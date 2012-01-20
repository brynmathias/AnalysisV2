##from http://root.cern.ch/root/html/tutorials/roostats/StandardHypoTestInvDemo.C.html
##
##    type = 0 Freq calculator
##    type = 1 Hybrid
##
##    testStatType = 0 LEP
##                 = 1 Tevatron
##                 = 2 Profile Likelihood
##                 = 3 Profile Likelihood one sided (i.e. = 0 if mu < mu_hat)
##
##    useCLs          scan for CLs (otherwise for CLs+b)
##
##    npoints:        number of points to scan , for autoscan set npoints = -1
##
##    poimin,poimax:  min/max value to scan in case of fixed scans
##                    (if min >= max, try to find automatically)
##
##    ntoys:         number of toys to use
##
##    extra options are available as global paramters of the macro. They are:
##

import ROOT as r

def RunInverter(w = None, modelSBName = "", modelBName = "",
                dataName = "", type = None, testStatType = None,
                npoints = None, poimin = None, poimax = None,
                ntoys = 1000, useCls = True, CL = 0.95,
                nworkers = 1, optimize = False, debug = False) :

    if debug : w.Print()

    data = w.data(dataName)
    assert data, "Dataset %s does not exist."%dataName
    if debug : print "Using data set %s"%dataName

    bModel = w.obj(modelBName)
    sbModel = w.obj(modelSBName)

    assert sbModel, "ModelConfig %s does not exist."%modelSBName
    assert sbModel.GetPdf(), "Model %s has no pdf."%modelSBName
    assert sbModel.GetParametersOfInterest(), "Model %s has no poi."%modelSBName
    if not sbModel.GetSnapshot() :
        if debug : r.Info("StandardHypoTestInvDemo","Model %s has no snapshot - make one using model poi"%modelSBName)
        sbModel.SetSnapshot(sbModel.GetParametersOfInterest())

    if (not bModel) or (bModel==sbModel) :
        if debug : r.Info("StandardHypoTestInvDemo","The background model %s does not exist"%modelBName)
        if debug : r.Info("StandardHypoTestInvDemo","Copy it from ModelConfig %s and set POI to zero"%modelSBName)
        bModel = sbModel.Clone()
        bModel.SetName(modelSBName+"_with_poi_0")
        var = bModel.GetParametersOfInterest().first()
        assert var
        oldval = var.getVal()
        var.setVal(0)
        bModel.SetSnapshot(r.RooArgSet(var))
        var.setVal(oldval)
    elif not bModel.GetSnapshot() :
        if debug : r.Info("StandardHypoTestInvDemo","Model %s has no snapshot - make one using model poi and 0 values "%modelBName)
        var = bModel.GetParametersOfInterest().first()
        assert var, "Model %s has no valid poi."%modelBName
        oldval = var.getVal()
        var.setVal(0)
        bModel.SetSnapshot(r.RooArgSet(var))
        var.setVal(oldval)

    slrts = r.RooStats.SimpleLikelihoodRatioTestStat(sbModel.GetPdf(),bModel.GetPdf())
    if sbModel.GetSnapshot() : slrts.SetNullParameters(sbModel.GetSnapshot())
    if  bModel.GetSnapshot() : slrts.SetAltParameters(bModel.GetSnapshot())

    # ratio of profile likelihood - need to pass snapshot for the alt
    ropl = r.RooStats.RatioOfProfiledLikelihoodsTestStat(sbModel.GetPdf(), bModel.GetPdf(), bModel.GetSnapshot())
    ropl.SetSubtractMLE(False)

    profll = r.RooStats.ProfileLikelihoodTestStat(sbModel.GetPdf())
    if (testStatType == 3) : profll.SetOneSided(1)
    if optimize : profll.SetReuseNLL(True)

    testStat = slrts
    if (testStatType == 1) : testStat = ropl
    if (testStatType == 2 or testStatType == 3) : testStat = profll

    if not type : hc = r.RooStats.FrequentistCalculator(data, bModel, sbModel)
    else        : hc = r.RooStats.HybridCalculator(data, bModel, sbModel)

    toymcs = hc.GetTestStatSampler()
    toymcs.SetNEventsPerToy(1)
    toymcs.SetTestStatistic(testStat)
    if optimize : toymcs.SetUseMultiGen(true)

    if (type == 1) :
        hc.SetToys(ntoys,ntoys)

        # check for nuisance prior pdf
        if (bModel.GetPriorPdf() and sbModel.GetPriorPdf()) :
            hc.ForcePriorNuisanceAlt(bModel.GetPriorPdf())
            hc.ForcePriorNuisanceNull(sbModel.GetPriorPdf())
        else :
            assert not (bModel.GetNuisanceParameters() or sbModel.GetNuisanceParameters()),\
                   "Cannnot run Hybrid calculator because no prior on the nuisance parameter is specified."

    else :
        hc.SetToys(ntoys,ntoys)

    # Get the result
    r.RooMsgService.instance().getStream(1).removeTopic(r.RooFit.NumIntegration)

    poi = sbModel.GetParametersOfInterest().first()
    # fit the data first
    sbModel.GetPdf().fitTo(data)
    poihat = poi.getVal()

    calc = r.RooStats.HypoTestInverter(hc)
    calc.SetConfidenceLevel(CL)

    calc.UseCLs(useCls)
    calc.SetVerbose(True)

    # can speed up using proof-lite
    if nworkers>1 : toymcs.SetProofConfig(r.RooStats.ProofConfig(w, nworkers, "", r.kFALSE))

    if npoints>=1 :
        print "Doing a fixed scan  in interval : %g , %g"%(poimin, poimax)
        calc.SetFixedScan(npoints, poimin, poimax)
    else :
        #poi.setMax(10*int( (poihat+ 10 *poi.getError() )/10 ) )
        print "Doing an  automatic scan  in interval : %g , %g"%(poi.getMin(), poi.getMax())

    return calc.GetInterval()
