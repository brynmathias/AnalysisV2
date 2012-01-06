#!/usr/bin/env python

""" This script steers the systematics calculations and outputs a LaTeX
table. The actual calculations are performed in the C++ files predict.C
"""
import ROOT as r
import math
import config as cfg
import utils
import likelihood
from multiprocessing import Pool, TimeoutError
import json
import time, os, copy
from limit_utils import toys, capture, quantiles
import pprint
import copy

def chunks(l, n):
    """ Yield successive n-sized chunks from l.
    """
    for i in xrange(0, len(l), n):
        yield l[i:i+n]

def setupLimit(channel):
    def makeLegend():
        return r.TLegend(0.7, 0.9, 0.9, 0.6)
    def plot(NObserved, results, NControl, R, bkgPredict):
        r.gROOT.SetStyle("Plain")
        c = r.TCanvas("test")
        c.SetGrid()
        nbins = len(NObserved)
        obs = r.TH1D("obs", "obs", nbins, 0.5, nbins+0.5)
        pred = r.TH1D("pred", "pred", nbins, 0.5, nbins+0.5)
        pred2 = r.TH1D("pred2", "pred2", nbins, 0.5, nbins+0.5)
        for idx, b in enumerate(NObserved):
            obs.SetBinContent(idx+1, b)
            if bkgPredict: pred2.SetBinContent(idx+1, R["nominal"][idx]*bkgPredict[0][idx])
            pred.SetBinContent(idx+1, results[idx].predicted())
            perr = math.sqrt(results[idx].predicted())
            serr = R["MCStats"][idx]*NControl[idx]
            pred.SetBinError(idx+1,
                             math.sqrt(perr**2 + serr**2))
            obs.GetXaxis().SetBinLabel(idx+1, utils.formatBin(idx, False))
        pred.SetLineColor(r.kRed)
        pred2.SetLineColor(r.kGreen);
        obs.GetYaxis().SetRangeUser(0, 1.2*max(obs.GetMaximum(), pred.GetMaximum()))
        obs.SetStats(r.kFALSE)
        obs.Draw("hist")
        if bkgPredict: pred2.Draw("hist e same")
        pred.Draw("hist e same")
        leg = makeLegend()
        leg.AddEntry(pred, "Predicted", "L")
        if bkgPredict: leg.AddEntry(pred2, "Predicted (QCD Fit)", "L")
        leg.AddEntry(obs, "Observed", "L")
        leg.Draw()
        c.SaveAs("limit/%s_pred_obs.pdf" % channel.name)
    def plotA(path, *args, **kwargs):
        c = r.TCanvas("test")
        c.SetGrid()
        r.gROOT.SetStyle("Plain")
        nbins = len(args[0])
        hists = [r.TH1D("h%d" % idx, "h%d" %idx, nbins, 0.5, nbins+0.5) for idx in range(len(args))]
        for idx in range(nbins):
            for hidx, h in enumerate(hists):
                h.SetBinContent(idx+1, args[hidx][idx])
                h.SetBinError(idx+1, math.sqrt(args[hidx][idx]))
        cols = kwargs.get("cols", [r.kBlack, r.kRed])
        legs = kwargs.get("legend", [])
        legend = makeLegend() if len(legs) > 0 else None
        for hidx, h in enumerate(hists):
            h.SetLineColor(cols[hidx])
            h.GetYaxis().SetRangeUser(0, 1.2*max([h.GetMaximum() for h in hists]))
            if hidx == 0: h.Draw("hist e")
            else: h.Draw("hist e same")
            if hidx < len(legs): legend.AddEntry(h, legs[hidx], "L")
        if legend: legend.Draw()
        c.SaveAs(path)

    ctrl_channel = bkgPredict = None
    # Get the background prediction per bin
    if channel.bkgPrediction == "OtherChannel":
        ctrl_channel = channel.ctrlChannel

    data = utils.getZeroData(channel, ctrl_channel)
    mc = utils.getZeroMC(channel, ctrl_channel)

    results = utils.makePredictions(data)

    systs = utils.getSystematicsBkg(channel, ctrl_channel)

    R = {"nominal": [b.R() for b in data]}

    for name, scaled in systs:
        R[name] = utils.getSystematicShiftsR(mc, scaled[0], scaled[1])
    R["MCStats"] = utils.mcStatsSystematicBkg(channel.bkgSamples, channel, ctrl_channel)
    R["ttpol"] = [x*tt for x, tt in zip(R["nominal"], ch.ttPolarisationUncertainty)]
    NObserved = [b.observed() for b in data]
    NControl = [b.control() for b in data]
    NControlMC = [b.mcControl() for b in mc]
    # This is to fix a problem with this not being scaled when running in real data mode.
    # Its not pretty but it works (I hope!)
    if cfg.useRealData:
        scaleMC = ch.lumi/cfg.icfDefaultLumi
        NControlMC = [x*scaleMC for x in NControlMC]
    print "Extracting signal data..."
    susyEff = utils.getZeroMCSignal(channel)
    controlRegionEff = utils.getZeroMCSignalControlRegion(channel)
    effSysts = utils.getSystematicsSignalEff(channel)

    if channel.bkgPrediction == "QCDFit":
        if cfg.useRealData: bkgPredict = (channel.ewkN, channel.ewkErr, {})
        else: bkgPredict = (NControl, [rel*control for rel, control in zip(channel.ewkRelErr, NControl)], {})

    for (m0, m12), p in susyEff.iteritems():
        p["effShift"] = {}
        p["control_efficiencies"] = controlRegionEff[(m0, m12)]["efficiencies"]
        for name,scaled in effSysts:
            shift = utils.getSystematicShiftsEff(p, scaled[0], scaled[1])
            p["effShift"][name] = shift
        if "pdfunc" in channel.includeSignalSysts:
            p["effShift"]["pdfunc"] = [0.1*eff for eff in p["efficiencies"]]

    plot(NObserved, results, NControl, R, bkgPredict)
    plotA("limit/R_%s.pdf" % channel.name, R["nominal"], legend = ["R"])

    # This is an ad-hoc correction to the electron limit to account for poor
    # statistics

    if ch == cfg.Electron and False:
        print "Correcting Electron channel top bin!"
        R["nominal"] = [x*2 for x in R["nominal"]]
#        for k, v in R.iteritems():
 #           R[k] = [x*2.25 for x in R[k]]
            #R[k][-1] = R[k][-1]*2.25
        if not cfg.useRealData:
            NObserved[-1] = NObserved[-1]*2.25

    if cfg.expectedLimit:
        if bkgPredict is None: NObserved = [Ri*cont for Ri, cont in zip(R["nominal"], NControl)]
        else: NObserved = [Ri*cont for Ri, cont in zip(R["nominal"], bkgPredict[0])]
    return {
        "name" : ch.name,
        "NObserved" : NObserved,
        "NControl" : NControl,
        "NControlMC" : NControlMC,
        "bkgPredict" : bkgPredict,
        "R" : R,
        "lumi": ch.lumi,
        "triggerEfficiency":ch.triggerEfficiency,
        "lumiError": cfg.lumiError,
        "signal" : susyEff,
        }

def mergeTasks(tasks, maxPoints):
    out = {"signal":[], "other":{}}
    for (m0, m12), p in tasks[0]["signal"].iteritems():
        addPoint = True
        if cfg.selectAPoint is not None: addPoint = (m0==cfg.selectAPoint[0] and m12 == cfg.selectAPoint[1])
        elif not cfg.run_sms and m0 < 600 and m12 < 200: continue
        for t in tasks[1:]:
            if not (m0, m12) in t["signal"]:
                addPoint=False
                break
        if addPoint:
            d = dict([(t["name"], t["signal"][(m0, m12)]) for t in tasks])
            (d["m0"], d["m1/2"]) = (m0, m12)
            out["signal"].append(d)
    out["signal"].sort(key = lambda x : (x["m0"], x["m1/2"]))
    out["signal"] = out["signal"][:maxPoints]
    for t in tasks:
        del t["signal"]
        out["other"][t["name"]] = t
    return out


def workOnPoint(actions, globs, channels, rootfname):
    pprint.pprint(channels)
    r.gROOT.SetBatch(True)
    r.RooRandom.randomGenerator().SetSeed(1)
    # r.RooMsgService.instance().addStream(r.RooFit.DEBUG, r.RooFit.Topic(r.RooFit.Tracing), r.RooFit.ClassName("RooGaussian"))
    #r.RooMsgService.instance().addStream(r.RooFit.DEBUG, r.RooFit.Topic(r.RooFit.Tracing))
    #r.RooMsgService.instance().addStream(r.RooFit.DEBUG, r.RooFit.Topic(r.RooFit.Minimization))
    # rfile = r.TFile(rootfname % os.getpid(), "UPDATE")
    # rfile.mkdir("susy_%d_%d" % (globs["m0"], globs["m1/2"])).cd()
    fitChannels = []
    print "============= Working on point ============"
    print "m0 = %d, m1/2 = %d" % (globs["m0"], globs["m1/2"])
    for chan in channels:
        c = copy.deepcopy(chan)
        name = c["name"]
        R = c["R"]
        MCStats = None
        if "MCStats" in R:
            MCStats = R["MCStats"]
            del R["MCStats"]

        signalEff = {"nominal":c["efficiencies"]}
        for k, v in c["effShift"].iteritems():
            signalEff[k] = v
        controlEff = c["control_efficiencies"]
        fitChannels += [likelihood.Channel(c["name"], c["lumi"], c["triggerEfficiency"], c["NObserved"], c["NControl"], c["NControlMC"],
                                           c["R"], signalEff, controlEff, MCStats,
                                           c["bkgPredict"])]
        assert all([x.signalEffSyst is not None for x in fitChannels])
    (w, modelConfig, dataset) = likelihood.OneLeptonSimple(globs, cfg.includeSignalContamination,
                                                           *fitChannels)
    w.Print()
    #print signalPoint

    out = globs.copy()
    out["channels"] = channels
    out["results"] = {}
    for act in actions:
        if act["name"] == "limit":
            out["results"][act["method"]] = capture(w, modelConfig, dataset, act["cl"], act["method"],
                                                    globs)
        elif act["name"] == "toys":
            out["results"]["toys"] = []
            for expt_w, expt_dset in toys(w, modelConfig, dataset, act["n"], act["cl"]):
                out["results"]["toys"].append(capture(expt_w, modelConfig, expt_dset, act["cl"], "pl", globs))
            limits = [x["limit"]["high"] for x in out["results"]["toys"]]
            out["results"]["quantiles"] = quantiles(limits, cfg.plusMinus)[0]

        else: raise ValueError("Invalid action: %s" % act["name"])
    # rfile.Write()
    # rfile.Close()
    return out

def runLimit(job, fork, timeout, rootfname):
    pointsOut = []
    if fork > 1:
        pool = Pool(fork)
        res = []
    for p in job["signal"]:
        channels = []
        for k, v in job["other"].iteritems():
            channels.append(v.copy())
            channels[-1].update(p[k])

        glob = {}
        if cfg.use_nloxs: glob["xs"] = channels[0]["nloxs"]
        else: glob["xs"] = channels[0]["loxs"]
        (glob["m0"], glob["m1/2"]) = (channels[0]["m0"], channels[0]["m1/2"])
        glob["lumiError"] = channels[0]["lumiError"]
        args = [job["actions"], glob, channels, rootfname]
        if fork > 1: res.append(pool.apply_async(workOnPoint, args))
        else: pointsOut.append(workOnPoint(*args))
    if fork > 1:
        for result in res:
            try:
                print "Waiting..."
                pointsOut.append(result.get(timeout))
            except TimeoutError:
                continue

    return pointsOut


def options():
    import optparse
    parser = optparse.OptionParser()
    parser.add_option("-s", "--schedule", action = "store_true", default = False)
    parser.add_option("-p", "--points-per-job", action = "store", type="int", default = 20)
    parser.add_option("-r", "--run", action = "store_true", default = False)
    parser.add_option("-f", "--fork", action = "store",  type = "int", default = 1)
    parser.add_option("-b", "--batch-run", action="store", type="string", default = None)
    parser.add_option("-m", "--merge", action="store", type = "string", default = None)
    parser.add_option("-a", "--action", action="store", type = "string", default = "limit")
    parser.add_option("-c", "--confidence-level", action="store", type="float", default = 0.95)
    parser.add_option("-l", "--limit", action="append", dest="limit",
                      choices = ["pl", "clsviatoys"], default=[])
    parser.add_option("-t", "--toys", action="store", type="int", default = None)
    parser.add_option("-T", "--timeout", action = "store", type="int", default=60*60)
    parser.add_option("-o", "--output-file", action = "store", type="string", default = "limit.pkl")
    parser.add_option("-N", "--N-points", action="store", type="int", default=None)
    parser.add_option("-n", "--do-nothing", action="store_true")
    (opts, args) = parser.parse_args()
    if (opts.schedule or opts.run) and not opts.limit and not opts.toys and not opts.do_nothing:
        raise ValueError("Must specify action")
    return (opts, args)

def subJobs(job_dir, njobs, queue = "hepshort.q"):
    import subprocess
    p = subprocess.Popen(["qsub",
                          "-q", queue,
                          "-t", "%d-%d:1" % (1, njobs),
                          "-o", job_dir,
                          "-e", job_dir,
                          "-N", "limits",
                          job_dir+"/run.sh"])
    if p.wait() == 0:
        print "%d jobs submitted successfuly" % njobs

if __name__ == "__main__":
    opts, args = options()
    r.gROOT.LoadMacro("predict.C+")
    actions = []
    for meth in opts.limit:
        actions.append({"name":"limit",
                        "cl":opts.confidence_level,
                        "method": meth})
    if opts.toys:
        actions.append({"name":"toys",
                        "cl":opts.confidence_level,
                        "n" : opts.toys})
    tasks = []
    if opts.schedule or opts.run:
        for ch in cfg.channels:
            tasks += [setupLimit(ch)]
    if opts.schedule or opts.run:
        # batch jobs are already pre-merged
        task = mergeTasks(tasks, opts.N_points)
        task["actions"] = actions

    if opts.schedule:
        job_dir = "%s/__limits__%s" % (os.getcwd(), time.strftime("%Y%m%d_%H_%M_%S"))
        os.mkdir(job_dir)
        for idx, pts in enumerate(chunks(task["signal"], opts.points_per_job)):
            os.mkdir("%s/%d" % (job_dir, idx+1))
            jobdict = copy.deepcopy(task)
            jobdict["signal"] = pts
            json.dump(jobdict, open("%s/%d/job.json" % (job_dir, idx+1), "w"), indent=0)
            open("%s/run.sh" % job_dir,"w").write("""#!/bin/sh
            source %(source)s
            cd %(cwd)s
            ./runLimit.py --batch-run %(job_dir)s/${SGE_TASK_ID} --fork %(fork)d --timeout %(timeout)d
            """ % {"cwd": os.getcwd(), "job_dir" : job_dir, "fork" : opts.fork, "timeout" : opts.timeout,
                   "source": "%s/root_svn.sh" % os.getcwd()})
        subJobs(job_dir, idx)
        print "Scheduled %s jobs: %s" % (idx, job_dir)
    elif opts.run or opts.batch_run:
        if opts.batch_run:
            task = json.load(open("%s/job.json" % opts.batch_run))
            print "Starting batch job!"
            ofile = "%s/results.json" % opts.batch_run
            orootfile = opts.batch_run + "/results_%d.root"
        else:
            ofile = opts.output_file
            orootfile = opts.output_file.replace(".json", "_%d.root").replace(".pkl", "_%d.root")
        results = runLimit(task, opts.fork, opts.timeout, orootfile)
        utils.saveFile({"results" : results}, ofile)
    elif opts.merge:
        if os.path.exists(opts.output_file): raise IOError("Output file exists: %s" % opts.output_file)
        else: print "Dumping to file: %s" % opts.output_file
        files = []
        idx = 1
        nonexist =0
        while True:
            path = "%s/%d/results.json" % (opts.merge, idx)
            print path
            if not os.path.exists(path):
                nonexist += 1
                if nonexist == 10: break
            else:
                files += [path]
                nonexist=0
            idx += 1
        points = []
        for idx, fname in enumerate(files):
            if idx % 10 == 0: print "Scanning file %d/%d" % (idx, len(files))
            pointsToAdd = utils.loadFile(fname)["results"]
            for p in pointsToAdd:
                if "toys" in p["results"]: del p["results"]["toys"]
            points.extend(pointsToAdd)
            if len(pointsToAdd) == 0:
                print "[WARNING] Empty output file: %d" % idx
        utils.saveFile({"results": points}, opts.output_file)
        print "Dumped %d files with %d points" % (idx -1, len(points))
