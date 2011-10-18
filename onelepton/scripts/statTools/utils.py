import ROOT as r
import config as cfg
import os.path
import math

def formatBin(idx, latex=True):
    """ Return a human readable bin name """
    if idx < len(cfg.bins) -1:
        return "%d - %d" % (cfg.bins[idx], cfg.bins[idx+1])
    else:
        if latex: return " $>$ %d" % cfg.bins[idx]
        else: return " > %d" % cfg.bins[idx]

def buildHist(samples, files, histpath, scale_factors, mcLumi=None):
    """ Loop through sample list 'samples' and fetch histogram at 'histpath'
    from TFile dictionary 'files'. Optionally look up scale factor from
    'scale_factors' and scale histogram appropriately.
    """
    h = files[samples[0]].Get(histpath).Clone()
    for s in samples[1:]:
        tmp = files[s].Get(histpath)
        if s in scale_factors:
            tmp = tmp.Clone()
            tmp.Scale(scale_factors[s])
        h.Add(tmp)
    if not cfg.useRealData:
        if mcLumi is None: raise Exception("Please specify lumi for normalisation")
        h.Scale(mcLumi/cfg.icfDefaultLumi)
    return h

def getFile(fname, fset, default_fset="zero"):
    """ Lookup a given filename 'fname', replacing %s in the string with the
    path to file set 'fset'. If the file can't be found, fall back to the one
    available in 'default_fset'.
    """
    fpath = fname % cfg.path[fset]
    if not os.path.exists(fpath):
        print "[WARNING] File: %s" % fname
        print "File not found for systematic '%s'. Using '%s' version instead!" % (fset, default_fset)
        fpath = fname % cfg.path[default_fset]
    if not os.path.exists(fpath): raise IOError("File not found: %s" % fname)
    return r.TFile(fpath)

def extract(channel, fset, data, mc, scale_factors={}):
    """For the specified data samples 'data' and mc samples 'mc', extract signal
    and control histograms for the set of files 'fset'. Construct BinData
    objects (see predict.C) from these. Optionally scale histograms according to
    'scale_factors' dictionary.
    """
    tfiles = dict([(n, getFile(fname, fset, "zero"))
                   for (n, fname) in channel.files.iteritems()])

    data_signal = [buildHist(data, tfiles, cfg.bin_fmt % (cfg.binName, b, "", cfg.hname),
                             scale_factors, channel.mcLumi)
                   for b in cfg.bins]
    data_control = [buildHist(data, tfiles, cfg.bin_fmt % (cfg.binName, b, "_BKG", cfg.hname),
                              scale_factors, channel.mcLumi)
                    for b in cfg.bins]
    mc_signal = [buildHist(mc, tfiles, cfg.bin_fmt % (cfg.binName, b, "", cfg.hname),
                           scale_factors, channel.mcLumi)
                 for b in cfg.bins]
    mc_control = [buildHist(mc, tfiles, cfg.bin_fmt % (cfg.binName, b, "_BKG", cfg.hname),
                            scale_factors, channel.mcLumi)
                  for b in cfg.bins]

    return  [
        r.BinData(dsig, dcontrol, mcsig, mccontrol)
        for (dsig, dcontrol, mcsig, mccontrol)
        in zip(data_signal, data_control, mc_signal, mc_control)
        ]

def extract2(pred_channel, ctrl_channel, fset, data, mc, scale_factors={}):
    """ELECTRONS: For the specified data samples 'data' and mc samples 'mc', extract signal
    and control histograms for the set of files 'fset'. Construct BinData
    objects (see predict.C) from these. Optionally scale histograms according to
    'scale_factors' dictionary.
    """
    tfiles1 = dict([(n, getFile(fname, fset, "zero"))
                   for (n, fname) in pred_channel.files.iteritems()])
    tfiles2 = dict([(n, getFile(fname, fset, "zero"))
                   for (n, fname) in ctrl_channel.files.iteritems()])

    data_signal = [buildHist(data, tfiles1, cfg.bin_fmt % (cfg.binName, b, "", cfg.hname),
                             scale_factors, pred_channel.mcLumi)
                   for b in cfg.bins]
    data_control = [buildHist(data, tfiles2, cfg.bin_fmt % (cfg.binName, b, "_BKG", cfg.hname),
                              scale_factors, ctrl_channel.mcLumi)
                    for b in cfg.bins]
    # If we have more lumi in the prediction channel than the control channel,
    # scale the control down to match the predicted lumi
    for dc in data_control:
        dc.Scale(pred_channel.lumi/ctrl_channel.lumi)

    mc_signal = [buildHist(mc, tfiles1, cfg.bin_fmt % (cfg.binName, b, "", cfg.hname),
                           scale_factors, pred_channel.mcLumi)
                 for b in cfg.bins]
    mc_control = [buildHist(mc, tfiles2, cfg.bin_fmt % (cfg.binName, b, "_BKG", cfg.hname),
                            scale_factors, ctrl_channel.mcLumi)
                  for b in cfg.bins]

    return  [
        r.BinData(dsig, dcontrol, mcsig, mccontrol)
        for (dsig, dcontrol, mcsig, mccontrol)
        in zip(data_signal, data_control, mc_signal, mc_control)
        ]

def extractProxy(pred_channel, ctrl_channel, fset, data, mc, scale_factors={}):
    if ctrl_channel is None:
        return extract(pred_channel, fset, data, mc, scale_factors)
    else:
        return extract2(pred_channel, ctrl_channel, fset, data, mc , scale_factors)

def extractSignalEffs(channel, fset, sample, asdict = False, label=""):
    """ Extract SUSY signal efficiencies per bin and output each mSUGRA point as a list
    'fset' : set of files to use
    'sample' : which sample e.g. tanbeta10
    'asdict' : Output a dictionary indexed by (m0, m1/2) instead
    """
    def hist(f, path):
        h =  f.Get(path).Clone()
        return h

    tfiles = dict([(n, getFile(fname, fset, "zero"))
                   for (n, fname) in channel.files.iteritems()])
    print tfiles[sample].GetEndpointUrl().GetUrl(),sample
    nocuts = hist(tfiles[sample], "Counter_BSMGrid_NoCuts_scale1/m0_m12_mChi")
    nocuts_noweight = hist(tfiles[sample], "Counter_BSMGrid_NoCuts_scale1/m0_m12_mChi_noweight")

    xs = nocuts.Clone()
    xs.Divide(nocuts_noweight)
    xs.Scale(cfg.icfNEventsIn/cfg.icfDefaultLumi)

    nloxs = None
    for p in cfg.processes:
        nlo = hist(tfiles[sample], "Counter_BSMGrid_NoCuts_scale1/m0_m12_%s" % p)
        nlo.Divide(hist(tfiles[sample], "Counter_BSMGrid_NoCuts_scale1/m0_m12_%s_noweight" % p))
        if nloxs is None: nloxs = nlo
        else: nloxs.Add(nlo)

    sigbins = []
    nloeffs = []
    for b in cfg.bins:
        bin_fmt = "Counter_BSMGrid_%s%d%s_scale1/%s"
        bin_name = bin_fmt  % (cfg.binName, b, label, "m0_m12_mChi_noweight")
        sigbin = hist(tfiles[sample], bin_name)
        sigbin.Divide(nocuts_noweight)
        sigbins.append(sigbin)
        nloeff = None
        for p in cfg.processes:
            top = hist(tfiles[sample], bin_fmt % (cfg.binName, b, label, "m0_m12_%s" % p))
            top.Divide(hist(tfiles[sample], "Counter_BSMGrid_NoCuts_scale1/m0_m12_%s_noweight" % p))
            if nloeff is None: nloeff = top
            else: nloeff.Add(top)
        nloeff.Divide(nloxs)
        nloeffs.append(nloeff)
    effs = []
    for xx in range(sigbins[0].GetNbinsX()+1):
        for yy in range(sigbins[0].GetNbinsY()+1):
            for zz in range(0, 10):
                (x, y, z) = (int(sigbins[0].GetXaxis().GetBinLowEdge(xx)),
                             int(sigbins[0].GetYaxis().GetBinLowEdge(yy)),
                             int(sigbins[0].GetZaxis().GetBinLowEdge(zz)))
                if xs.GetBinContent(xx, yy, zz) < cfg.minXSToConsider: continue
                if nocuts_noweight.GetBinContent(xx, yy, zz) != 10000:
#                    print "WARNING: Found hole in scan (%d, %d)" % (x,y)
                    continue
                point = {"loefficiencies": [],
                         "nloefficiencies": [],
                         "loxs" : xs.GetBinContent(xx, yy, zz),
                         "nloxs" : nloxs.GetBinContent(xx, yy),
                         "m0" : x,
                         "m1/2" : y,
                         "mChi": z}
                for idx, sigbin in enumerate(sigbins):
                    eff = sigbin.GetBinContent(xx,yy, zz)
                    point["loefficiencies"].append(eff)
                    point["nloefficiencies"].append(nloeffs[idx].GetBinContent(xx, yy))

                if cfg.use_nloxs: point["efficiencies"] = point["nloefficiencies"]
                else: point["efficiencies"] = point["loefficiencies"]
                if label == "" and all([eff < cfg.minEffToConsider for eff in point["efficiencies"]]):
                    continue
                effs.append(point)
    if asdict: effs = dict([((p["m0"], p["m1/2"]), p) for p in effs])
    return effs

def rootkill(thing) :
    """ Delete a ROOT object. Needed to avoid memory leaks """
    #free up memory (http://wlav.web.cern.ch/wlav/pyroot/memory.html)
    thing.IsA().Destructor( thing )

# Background Systematics
# These functions return the background signal and control yields as BinData
# objects for each systematic variation (i.e. jec, met resolution etc.)
def jecSystematicBkg(pred_channel, ctrl_channel):
    return (extractProxy(pred_channel, ctrl_channel, "metup",   pred_channel.bkgSamples, pred_channel.bkgSamples),
            extractProxy(pred_channel, ctrl_channel, "metdown", pred_channel.bkgSamples, pred_channel.bkgSamples))

def jecFlatSystematicBkg(pred_channel, ctrl_channel):
    return (extractProxy(pred_channel, ctrl_channel, "metup_flat",   pred_channel.bkgSamples, pred_channel.bkgSamples),
            extractProxy(pred_channel, ctrl_channel, "metdown_flat", pred_channel.bkgSamples, pred_channel.bkgSamples))

def metresSystematicBkg(pred_channel, ctrl_channel):
    one = extractProxy(pred_channel, ctrl_channel, "metres",    pred_channel.bkgSamples, pred_channel.bkgSamples)
    return (one, one)

def metres11SystematicBkg(pred_channel, ctrl_channel):
    one = extractProxy(pred_channel, ctrl_channel, "metres11",    pred_channel.bkgSamples, pred_channel.bkgSamples)
    return (one, one)

def metres12SystematicBkg(pred_channel, ctrl_channel):
    one = extractProxy(pred_channel, ctrl_channel, "metres12",    pred_channel.bkgSamples, pred_channel.bkgSamples)
    return (one, one)

def polSystematicBkg(pred_channel, ctrl_channel):
    return (extractProxy(pred_channel, ctrl_channel, "polup",   pred_channel.bkgSamples, pred_channel.bkgSamples),
            extractProxy(pred_channel, ctrl_channel, "poldown", pred_channel.bkgSamples, pred_channel.bkgSamples))
def lepSystematicBkg(pred_channel, ctrl_channel):
    one = extractProxy(pred_channel, ctrl_channel, "muscale",      pred_channel.bkgSamples, pred_channel.bkgSamples)
    return (one, one)
def WttSystematicBkg(pred_channel, ctrl_channel):
    return (extractProxy(pred_channel, ctrl_channel, "zero",    pred_channel.bkgSamples, pred_channel.bkgSamples,
                    {"tt":1.5, "w":0.7}),
            extractProxy(pred_channel, ctrl_channel, "zero",    pred_channel.bkgSamples, pred_channel.bkgSamples,
                    {"tt":0.5, "w":1.3}))
def mcStatsSystematicBkg(mc, pred_channel, ctrl_channel):
    if ctrl_channel is None:
        ctrl_channel = pred_channel
    tfiles1 = dict([(n, getFile(fname, "zero", "zero"))
                    for (n, fname) in pred_channel.files.iteritems()])
    tfiles2 = dict([(n, getFile(fname, "zero", "zero"))
                    for (n, fname) in ctrl_channel.files.iteritems()])
    mc_signal = [buildHist(mc, tfiles1, cfg.bin_fmt % (cfg.binName, b, "", cfg.hname),
                           {}, pred_channel.mcLumi)
                 for b in cfg.bins]
    print [h.Integral() for h in mc_signal]
    mc_control = [buildHist(mc, tfiles2, cfg.bin_fmt % (cfg.binName, b, "_BKG", cfg.hname),
                            {}, ctrl_channel.mcLumi)
                  for b in cfg.bins]
    deltaR = []
    for sig, ctrl in zip(mc_signal, mc_control):
        nsig = sig.GetBinContent(1)
        nctrl = ctrl.GetBinContent(1)
        sigma_sig = sig.GetBinError(1)
        print "Sig", sigma_sig/nsig, nsig
        sigma_ctrl = ctrl.GetBinError(1)
        print "Ctrl", sigma_ctrl/nctrl, nctrl
        a = sigma_sig* (1.0/nctrl) if nctrl > 0 else 0
        b = sigma_ctrl * (-1.0*nsig)/(nctrl**2) if nctrl > 0 else 0
        deltaR.append(math.sqrt(a**2 + b**2))
    return deltaR

def getSystematicsBkg(pred_channel, ctrl_channel=None):
    """ Return all background systematics filtered by the includeBackgroundSysts
    list"""
    syst_funcs = {
        "jec"    : jecFlatSystematicBkg,
        "metres" : metres11SystematicBkg,
        "pol"    : polSystematicBkg,
        "lep"    : lepSystematicBkg,
        "Wtt"    : WttSystematicBkg
        }
    out = []
    for syst in cfg.systInfo.keys():
        if syst in pred_channel.includeBackgroundSysts: out += [(syst, syst_funcs[syst](pred_channel, ctrl_channel))]
    return out

def getLiterallyAllSystematicsBkg(pred_channel, ctrl_channel=None):
    """ Return all background systematics filtered by the includeBackgroundSysts
    list"""
    syst_funcs = {
        "jec"    : jecSystematicBkg,
        "jec_flat" : jecFlatSystematicBkg,
        "metres" : metresSystematicBkg,
        "metres11" : metres11SystematicBkg,
        "metres12" : metres12SystematicBkg,
        "pol"    : polSystematicBkg,
        "lep"    : lepSystematicBkg,
        "Wtt"    : WttSystematicBkg
        }
    out = []
    for syst,syst_func in syst_funcs.iteritems():
        out += [(syst, syst_funcs[syst](pred_channel, ctrl_channel))]
    return out

# Signal Systematics

def jecSystematicSignalEff(channel):
    return (extractSignalEffs(channel, "metup", cfg.susyScan, asdict=True),
            extractSignalEffs(channel, "metdown", cfg.susyScan, asdict=True))
def jecFlatSystematicSignalEff(channel):
    return (extractSignalEffs(channel, "metup_flat", cfg.susyScan, asdict=True),
            extractSignalEffs(channel, "metdown_flat", cfg.susyScan, asdict=True))

def metresSystematicSignalEff(channel):
    one = extractSignalEffs(channel, "metres", cfg.susyScan, asdict=True)
    return (one, one)
def metres11SystematicSignalEff(channel):
    one = extractSignalEffs(channel, "metres11", cfg.susyScan, asdict=True)
    return (one, one)

def lepSystematicSignalEff(channel):
    one = extract(channel, "muscale", cfg.susyScan, asdict=True)
    return (one, one)

def getSystematicsSignalEff(channel):
    syst_funcs = {
        "jec" : jecFlatSystematicSignalEff,
        "metres" : metres11SystematicSignalEff,
        "lep" : lepSystematicSignalEff
        }
    out = []
    for syst in syst_funcs.keys():
        if not cfg.systInfo[syst]["signal"]:
            raise ValueError("Not a signal systematic: %s" % syst)
        if syst in channel.includeSignalSysts:
            out += [(syst, syst_funcs[syst](channel))]
    return out

# General functions for dealing with systematics
def calcSyst(nom, up, down):
    """ Return the largest shift (and appropriate sign) per bin from the nominal
    data to the up and down scaled data."""
    def sign(a, b):
        if a >= b: return 1.0
        else: return -1.0
    def symmetriseSyst(a, b):
        return max(a, b)

    shift_up = [abs(u - n) for u, n in zip(up, nom)]
    shift_down = [abs(d - n) for d, n in zip(down, nom)]
    shift_sign = [sign(u, n) for u, n in zip(up, nom)]
    shifts = [ssign*symmetriseSyst(u, d) for u, d, ssign in
              zip(shift_up, shift_down, shift_sign)]
    return shifts

def getSystematicShiftsEff(p, up, down):
    """ Calculate signal efficiency systematics.  p is a single mSUGRA
    point. up, down are dictionaries (keyed with m0,m1/2) for the up and down
    scaled SUSY points.
    """
    out = []
    (m0, m12) = (p["m0"], p["m1/2"])
    if not (m0, m12) in up or not (m0, m12) in down:
        return None
    up_eff = up[(m0, m12)]["efficiencies"]
    down_eff = down[(m0, m12)]["efficiencies"]
    return calcSyst(p["efficiencies"], up_eff, down_eff)


def getSystematicShiftsR(nom, up, down):
    """ Get systematic shift on R (Nsignal/Ncontrol) per bin"""
    nom = map(lambda x : x.R(), nom)
    up = map(lambda x: x.R(), up)
    down = map(lambda x : x.R(), down)
    return calcSyst(nom, up, down)


def getZeroMC(pred_channel, ctrl_channel=None):
    """ Return background only MC without systematic variation """
    return extractProxy(pred_channel, ctrl_channel, "zero", pred_channel.bkgSamples, pred_channel.bkgSamples, cfg.binName)

def getZeroData(pred_channel, ctrl_channel=None):
    """ Return MC pseudodata (possibly containing signal) without syst variation"""
    return extractProxy(pred_channel, ctrl_channel,  "zero", pred_channel.dataSamples, pred_channel.bkgSamples, cfg.binName)

def getZeroMCSignal(channel):
    """ Return mSUGRA efficiencies without systematic variation"""
    return extractSignalEffs(channel, "zero", cfg.susyScan, asdict=True)

def getZeroMCSignalControlRegion(channel):
    return extractSignalEffs(channel, "zero", cfg.susyScan, asdict=True, label="_BKG")

def makePredictions(data):
    """ Turn BinData objects into BinResult representing prediction """
    return [r.createBin(databin) for databin in data]

def addSystematic(name, data, results, syst):
    """ Add systematic contribution to bins """
    for idx, res in enumerate(results):
        r.addSystematic(name, res, data[idx], syst[0][idx], syst[1][idx])

def getSignalSystematics():
    """ Return systematics affecting signal expectation """
    return [name for name, fields in cfg.systInfo.iteritems()
            if fields["signal"]]

def getBackgroundSystematics():
    """ Return systematics affecting background prediction """
    return [name for name, fields in cfg.systInfo.iteritems()
            if fields["background"]]

def getAllSystematics():
    """ Return all systematics """
    return set(getSignalSystematics()) | set(getBackgroundSystematics())


def loadFile(fname):
    """ Generic load file. json/picle depending on extension."""
    if fname.endswith(".json"):
        import json
        return json.load(open(fname))
    elif fname.endswith(".pkl"):
        import cPickle as pickle
        p = pickle.Unpickler(open(fname))
        res = p.load()
        del p
        return res

def saveFile(ob, fname):
    """ Generic save file. json/picle depending on extension."""
    if fname.endswith(".json"):
        import json
        json.dump(ob, open(fname, "w"), indent = 1)
    elif fname.endswith(".pkl"):
        import cPickle as pickle
        p = pickle.Pickler(open(fname, "wb"))
        # Needed to avoid bad_alloc
        p.fast = True
        p.dump(ob)
