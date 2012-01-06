import ROOT as r
import utils
import math, array
import sys
import config as cfg
from runInverter import RunInverter

def wimport(w, item) :
    r.RooMsgService.instance().setGlobalKillBelow(r.RooFit.WARNING) #suppress info messages
    getattr(w, "import")(item)
    r.RooMsgService.instance().setGlobalKillBelow(r.RooFit.DEBUG) #re-enable all messages

def rooFitResults(pdf, data, options = (r.RooFit.Verbose(False), r.RooFit.PrintLevel(-1), r.RooFit.Save(True))) :
    return pdf.fitTo(data, *options)

def plInterval(w, modelConfig, dataset, cl=0.95, poi="f", plot=False):
    out = {}
    calc = r.RooStats.ProfileLikelihoodCalculator(dataset, modelConfig)
    w.var("f").setVal(0.1) # was 0.1
    w.var("f").setConstant(False)

    calc.SetConfidenceLevel(0.95)
    interval = calc.GetInterval()
    out["low"] = interval.LowerLimit(w.var(poi))
    out["high"] = interval.UpperLimit(w.var(poi))

    if plot:
        canvas = r.TCanvas("pl")
        canvas.SetTickx()
        canvas.SetTicky()
        plPlot = r.RooStats.LikelihoodIntervalPlot(interval)
        plPlot.Draw()
        canvas.Write()
    utils.rootkill(interval)
    return out

def cls(w, modelConfig, dataset, cl, nToys, nWorkers=1, plSeed=False):
    nPoints = 1
    poiMin = 1.0
    poiMax = 1.0
    testStatType = 3
    plusMinus = cfg.plusMinus

    if plSeed:
        plUpperLimit = plInterval(w, modelConfig, dataset, cl = cl)["high"]
        nPoints= 3
        poiMin = plUpperLimit*0.5
        poiMax = plUpperLimit*1.5
    #r.RooMsgService.instance().addStream(r.RooFit.DEBUG, r.RooFit.Topic(r.RooFit.Tracing))
    wimport(w, dataset)
    wimport(w, modelConfig)
    result = RunInverter(w = w, modelSBName = "modelConfig", dataName = "dataName", CL = cl,
                         nworkers = nWorkers, ntoys = nToys, type = 0, testStatType = testStatType,
                         npoints = nPoints, poimin = poiMin, poimax = poiMax, debug=False)


    out = {}
    for iPoint in range(nPoints) :
        s = "" if not iPoint else "_%d"%iPoint
        out["CLb%s"     %s] = result.CLb(iPoint)
        out["CLs+b%s"   %s] = result.CLsplusb(iPoint)
        out["CLs%s"     %s] = result.CLs(iPoint)
        out["CLsError%s"%s] = result.CLsError(iPoint)
        out["PoiValue%s"%s] = result.GetXValue(iPoint)

    if nPoints==1 and poiMin==poiMax :
        args = {}
        for item in ["testStatType", "plusMinus"] :
            args[item] = eval(item)
        args["result"] = result
        args["poiPoint"] = poiMin
        args["out"] = out
        clsOnePoint(args)
    else :
        out["UpperLimit"] = result.UpperLimit()
        out["UpperLimitError"] = result.UpperLimitEstimatedError()
        out["LowerLimit"] = result.LowerLimit()
        out["LowerLimitError"] = result.LowerLimitEstimatedError()
    return out

def clsOnePoint(args) :
    result = args["result"]
    iPoint = result.FindIndex(args["poiPoint"])
    if iPoint<0 :
        print "WARNING: No index for POI value 1.0.  Will use 0."
        iPoint = 0

    values = result.GetExpectedPValueDist(iPoint).GetSamplingDistribution()
    q,hist = quantiles(values, args["plusMinus"], histoName = "expected_CLs_distribution",
                       histoTitle = "expected CLs distribution;CL_{s};toys / bin",
                       histoBins = (205, -1.0, 1.05), cutZero = False)

    for key,value in q.iteritems() :
        assert not (key in args["out"]),"%s %s"%(key, str(args["out"]))
        args["out"][key] = value
    return values

def clsOld(w, modelConfig, dataset, method, nToys, plot=False):
    def indexFraction(item, l):
        totalList = sorted(l+[item])
        return totalList.index(item)/(0.0+len(totalList))

    def histToList(name, title, nbins, l):
        hist = r.TH1D(name, title, nbins, min(l), max(l))
        for item in l: hist.Fill(item)
        return hist

    def pValue(w, nToys, plot_name=None):
        results = rooFitResults(w.pdf("model"), dataset)
        w.saveSnapshot("snap", w.allVars())
        maxData = -results.minNll()
        maxs = []
        graph = r.TGraph()
        for i,dset in enumerate(pseudoData(w, nToys)):
            w.loadSnapshot("snap")
            results = rooFitResults(w.pdf("model"), dset)
            maxs.append(-results.minNll())
            graph.SetPoint(i, i, indexFraction(maxData, maxs))
            utils.rootkill(results)
        if plot:
            c = r.TCanvas(plot_name)
            graph.Draw("a*")
            c.Write()
            hist = histToList("%s_hist" % plot_name, "", 50, maxs)
            hist_actual = histToList("%s_hist_actual" % plot_name, "", 50, [0, maxData])
            hist.Write()
            hist_actual.Write()
        utils.rootkill(graph)
        return indexFraction(maxData, maxs)

    out = {}

    if method == "Toys":
        w.var("f").setVal(0.0)
        w.var("f").setConstant()
        out["CLb"] = 1.0 - pValue(w, nToys, "CLb")
        w.var("f").setVal(1.0)
        w.var("f").setConstant()
        out["CLs+b"] = pValue(w, nToys, "CLs+b")

    out["CLs"] = out["CLs+b"]/out["CLb"] if out["CLb"] else 9.9
    return out

def pseudoData(w, n):
    dataset = w.pdf("model").generate(w.set("obs"), n)
    out = []
    for i in range(int(dataset.sumEntries())):
        argset = dataset.get(i)
        data = r.RooDataSet("pseudoData%d" % i, "title", argset)
        data.add(argset)
        out.append(data)
    return out

def toys(w, modelConfig, dataset, nToys, cl=0.95):
    w.var("f").setVal(0.0)
    w.var("f").setConstant(True)
    results = rooFitResults(w.pdf("model"), dataset)

    pseudo = pseudoData(w, nToys)

    w.var("f").setVal(1.0)
    w.var("f").setConstant(False)

    w.saveSnapshot("snap", w.allVars())

    for i, dataset in enumerate(pseudo):
        sys.stderr.write("@@ TOY @@ %d\n" % i)
        w.loadSnapshot("snap")
        yield w, dataset

def capture(w, modelConfig, dataset, cl, method, globals):
    out = {}
    if method == "pl":
        pl_plot_name = "pl_%(m0)d_%(m1/2)d" % globals
        out["limit"] = plInterval(w, modelConfig, dataset, cl)
        print out["limit"]
        for syst in utils.getAllSystematics():
            try: out["%s" % syst] = w.var("nu%s" % syst).getVal()
            except ReferenceError: out["%s" % syst] = -1
    elif method == "clsviatoys":
        out["limit"] = cls(w, modelConfig, dataset,  cl, cfg.clsToys)

    return out


def quantiles(values = [], plusMinus = {}, histoName = "", histoTitle = "", histoBins = [], cutZero = None) :
    def histoFromList(l, name, title, bins, cutZero = False) :
        h = r.TH1D(name, title, *bins)
        for item in l :
            if cutZero and (not item) : continue
            h.Fill(item)
        return h

    def probList(plusMinus) :
        def lo(nSigma) : return ( 1.0-r.TMath.Erf(nSigma/math.sqrt(2.0)) )/2.0
        def hi(nSigma) : return 1.0-lo(nSigma)
        out = []
        out.append( (0.5, "Median") )
        for key,n in plusMinus.iteritems() :
            out.append( (lo(n), "MedianMinus%s"%key) )
            out.append( (hi(n), "MedianPlus%s"%key)  )
        return sorted(out)

    def oneElement(i, l) :
        return map(lambda x:x[i], l)

    pl = probList(plusMinus)
    probs = oneElement(0, pl)
    names = oneElement(1, pl)

    probSum = array.array('d', probs)
    q = array.array('d', [0.0]*len(probSum))

    h = histoFromList(values, name = histoName, title = histoTitle, bins = histoBins, cutZero = cutZero)
    h.GetQuantiles(len(probSum), q, probSum)
    return dict(zip(names, q)),h

# def quantiles(limits, plusMinus):
#     def histoFromList(l, name, title, bins) :
#         h = r.TH1D(name, title, *bins)
#         for item in l : h.Fill(item)
#         return h
#     def probList(plusMinus) :
#         def lo(nSigma) : return ( 1.0-r.TMath.Erf(nSigma/math.sqrt(2.0)) )/2.0
#         def hi(nSigma) : return 1.0-lo(nSigma)
#         out = []
#         out.append( (0.5, "Median") )
#         for key,n in plusMinus.iteritems() :
#             out.append( (lo(n), "MedianMinus%s"%key) )
#             out.append( (hi(n), "MedianPlus%s"%key)  )
#         return sorted(out)
#     fst = lambda x : x[0]
#     snd = lambda x : x[1]
#     pl = probList(plusMinus)
#     probs = map(fst, pl)
#     names = map(snd, pl)
#     probSum = array.array('d', probs)
#     q = array.array('d', [0.0]*len(probSum))
#     probSum = array.array('d', probs)
#     q = array.array('d', [0.0]*len(probSum))

#     h = histoFromList(limits, name = "upperLimit", title = ";upper limit on XS factor;toys / bin",
#                       bins = (50, 1, -1)) #enable auto-range
#     h.GetQuantiles(len(probSum), q, probSum)
#     return (dict(zip(names, q)), h)
