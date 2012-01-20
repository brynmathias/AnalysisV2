#!/usr/bin/env python
import ROOT as r
import os
import math

class Channel(object):
    def __init__(self, name, lumi, triggerEfficiency, NObserved, NControl, NControlMC, R, signalEff,
                 controlEff, RStat, bkgPredict):
        self.name = name
        self.lumi = lumi
        self.triggerEfficiency = triggerEfficiency
        self.NObserved = NObserved
        self.NControl = NControl
        self.NControlMC = NControlMC
        self.R = R["nominal"]
        self.RSyst = dict([(k,v) for k, v in R.iteritems() if k != "nominal"])
        self.RStat = RStat
        self.signalEff = signalEff["nominal"]
        self.controlEff = controlEff
        self.signalEffSyst = dict([(k, v) for k, v in signalEff.iteritems() if k != "nominal"])
        self.NControlError = [math.sqrt(nc) for nc in self.NControl]
        self.bkgPredict = bkgPredict

    def signalSystematics(self):
        return set(self.signalEffSyst.keys())
    def backgroundSystematics(self):
        return set(self.RSyst.keys())
    def allSystematics(self):
        return self.signalSystematics() | self.backgroundSystematics()
    def enumBins(self):
        return enumerate(self.signalEff)

NuisancePDF =  r.RooGaussian
def OneLeptonSimple(globals, signalContamination, *channels): # Not so simple anymore!
    w = r. RooWorkspace("wspace")
    model = None
    obs = [ ]
    terms = [ ]
    nuis = [ ]
    def wimport(*items):
        for item in items:
            # suppress info messages
            r.RooMsgService.instance().setGlobalKillBelow(r.RooFit.WARNING)
            getattr(w, "import")(item)
            #re-enable all messages
            r.RooMsgService.instance().setGlobalKillBelow(r.RooFit.DEBUG)

    def signalTerms():
        wimport(r.RooRealVar("f", "f", 0.1, 0.0, 1.0)) # f was 0.1 . upper was 2.0
        print "xs = %.2f" % globals["xs"]
        wimport(r.RooRealVar("xs", "xs", globals["xs"]))
        wimport(r.RooRealVar("nuLumiMean", "nuLumiMean", 1.0))
        wimport(r.RooRealVar("nuLumi", "nuLumi", 1.0, 0.0, 2.0))
        wimport(r.RooRealVar("nuLumiDelta", "nuLumiDelta", 2*globals["lumiError"]))
        wimport(r.RooGaussian("nuLumiGauss", "nuLumiGauss", w.var("nuLumi"),
                              w.var("nuLumiMean"), w.var("nuLumiDelta")))
        obs.append("nuLumiMean")
        terms.append("nuLumiGauss")
        nuis.append("nuLumi")
        for ch in channels:
            print "Lumi %s = %.2f" % (ch.name, ch.lumi)
            wimport(r.RooRealVar("%sLumi" % ch.name, "%sLumi" % ch.name, ch.lumi))

    def nuisanceParams():
        systs = set.union(*[ch.allSystematics() for ch in channels])
        for syst in systs:
            name = "nu%s" % syst
            wimport(r.RooRealVar(name, name, 0, -3, 3))
            wimport(r.RooRealVar(name+"Mean", name+"Mean", 0))
            wimport(r.RooRealVar(name+"Sigma", name+"Sigma", 1.0))
            wimport(NuisancePDF(name+"Gauss", name+"Gauss",
                                w.var(name), w.var(name+"Mean"),
                                w.var(name+"Sigma")))
            nuis.append(name)
            terms.append(name+"Gauss")
            obs.append(name+"Mean")

    def backgroundPredictions():
        for ch in channels:
            for idx, eff in ch.enumBins():
                prefix = "%sBkg%d" % (ch.name, idx)
                wimport(r.RooRealVar("%s_RNom" % prefix, "%s_RNom" % prefix, ch.R[idx]))
                #                wimport(r.RooRealVar("%s_NControlNom" % prefix, "%s_NControlNom" % prefix, ch.NControl[idx]))
                prefix = "nu%sBkg%d_NControl" % (ch.name, idx)
                if ch.bkgPredict is not None:
                    wimport(r.RooRealVar(prefix, prefix, ch.NControl[idx]))
                else:
                    wimport(r.RooRealVar(prefix, prefix, ch.NControl[idx], 0, 10000))
                    wimport(r.RooRealVar("%sMean" % prefix, "%sMean" % prefix, ch.NControl[idx]))
                    wimport(r.RooRealVar("%sSigma" % prefix, "%sSigma" % prefix, ch.NControlError[idx]))
                    wimport(r.RooGaussian("%sGauss" % prefix, "%sGauss" % prefix,
                                          w.var(prefix), w.var("%sMean" % prefix), w.var("%sSigma" % prefix)))
                    terms.append("%sGauss" % prefix)
                    obs.append("%sMean" % prefix)
                    nuis.append(prefix)

                name = "nu%sBkg%d_R" % (ch.name, idx)
                wimport(r.RooRealVar(name, name, 1, 0, 2))
                wimport(r.RooRealVar("%sMean" % name, "%sMean" % name, 1.0))
                wimport(r.RooRealVar("%sSigma" % name, "%sSigma" % name, ch.RStat[idx]/ch.R[idx]))
                wimport(r.RooGaussian("%sGauss" % name, "%sGauss" % name, w.var(name), w.var("%sMean" % name), w.var("%sSigma" % name)))
                terms.append("%sGauss" % name)
                obs.append("%sMean" % name)
                nuis.append(name)
                R_systs = []
                for syst in ch.backgroundSystematics():
                    name = "%sBkg%d_R%s" % (ch.name, idx, syst)
                    wimport(r.RooRealVar("%sShift" %  name, "%sShift" % name, ch.RSyst[syst][idx]))
                    wimport(r.RooFormulaVar("%sScale" % name, "((@0) + (@1)*(@2))/(@3)",
                                            r.RooArgList(w.var("%sBkg%d_RNom" % (ch.name, idx)),
                                                               w.var("%sShift" % name),
                                                               w.var("nu%s" % syst),
                                                               w.var("%sBkg%d_RNom" % (ch.name, idx)))))
                    R_systs.append("%sScale" % name)

                if ch.bkgPredict is not None:
                    print "QCD Prediction enabled"
                    assert all([x!=0 for x in ch.bkgPredict[0]])
                    fEWK = [x/y for (x, y) in zip(ch.bkgPredict[0], ch.NControl)]
                    fEWKErr = []
                    for NEwk, NEwkErr, NControl in zip(ch.bkgPredict[0], ch.bkgPredict[1], ch.NControl):
                        a = NEwkErr/NControl
                        b = (NEwk*math.sqrt(NControl))/NControl**2
                        fEWKErr += [a**2 + b**2]
                    print "fEWK:", fEWK, fEWKErr

                    prefix = "nu%sBkg%d_NControlfEWK" % (ch.name, idx)
                    wimport(r.RooRealVar(prefix, prefix, fEWK[idx], 0, 1))
                    wimport(r.RooRealVar("%sMean" % prefix, "%sMean" % prefix, fEWK[idx]))
                    wimport(r.RooRealVar("%sSigma" % prefix, "%sSigma" % prefix, fEWKErr[idx]))
                    wimport(r.RooGaussian("%sGauss" % prefix, "%sGauss" % prefix, w.var(prefix),
                                          w.var("%sMean" % prefix), w.var("%sSigma" % prefix)))
                    terms.append("%sGauss" % prefix)
                    obs.append("%sMean" % prefix)
                    nuis.append(prefix)

                    control_terms = [w.var("nu%sBkg%d_NControl" % (ch.name, idx)),
                                     w.var("nu%sBkg%d_NControlfEWK" % (ch.name, idx))]
                    for syst in ch.bkgPredict[2].keys():
                        assert syst in ch.backgroundSystematics()
                        a = ch.bkgPredict[2][syst][idx]/NControl
                        b = (NEwk*math.sqrt(NControl))/NControl**2
                        syst_err = a**2 + b**2
                        print "fEWK_%s: %.2f" % (syst, syst_err)
                        name = "%sBkg%d_NControlfEWKErr%s" % (ch.name, idx, syst)
                        wimport(r.RooRealVar("%sShift" %  name, "%sShift" % name, syst_err))
                        wimport(r.RooFormulaVar("%sScale" % name, "((@0) + (@1)*(@2))/(@3)",
                                                   r.RooArgList(w.var("nu%sBkg%d_NControlfEWKMean" % (ch.name, idx)),
                                                               w.var("%sShift" % name),
                                                               w.var("nu%s" % syst),
                                                               w.var("nu%sBkg%d_NControlfEWKMean" % (ch.name, idx)))))
                        control_terms.append(w.function("%sScale"% name))


                    wimport(r.RooFormulaVar("%sBkg%d_NControl" % (ch.name, idx), "*".join(["(@%d)" % i for i in range(len(control_terms))]),
                                            r.RooArgList(*control_terms)))

                    NControl_term = w.function("%sBkg%d_NControl" % (ch.name, idx))
                else:
                    NControl_term = w.var("nu%sBkg%d_NControl" % (ch.name, idx))

                name = "%sBkg%d_NControl" % (ch.name, idx)
                wimport(r.RooRealVar(name+"_MC", name+"_MC", ch.NControlMC[idx]))
                wimport(r.RooRealVar(name+"_ControlEff", name+"_ControlEff", ch.controlEff[idx]))
                wimport(r.RooFormulaVar(name+"_NSUSY", "(@0)*(@1)*(@2)*(@3)", r.RooArgList(w.var("f"), w.var("xs"), w.var(name+"_ControlEff"), w.var("%sLumi" % ch.name))))
                fval = w.var("f").getVal()
                w.var("f").setVal(1.0)
                wimport(r.RooRealVar(name+"_NSUSYNom", name+"_NSUSYNom", w.function(name+"_NSUSY").getVal()))
                w.var("f").setVal(fval)
                R_terms = [w.var("nu%sBkg%d_R" % (ch.name, idx)), w.var("%sBkg%d_RNom" % (ch.name, idx)), NControl_term]
                if signalContamination and w.var(name+"_ControlEff").getVal() >= 0.0001:
		    print "====="
		    print w.function(name+"_NSUSYNom").getVal()
		    print w.function(name+"_MC").getVal()
                    wimport(r.RooFormulaVar(name+"_fSM_Mean", "(@0)/((@0) + (@1))", r.RooArgList(w.var(name+"_MC"), w.var(name+"_NSUSYNom"))))
                    wimport(r.RooFormulaVar(name+"_fSM_Sigma", "sqrt( (@0)*(1/((@0)+(@1)) - (@0)/(((@0)+(@1))^2))^2 + (@1)*((@0)/(((@0)+(@1))^2))^2)",
                                            r.RooArgList(w.var(name+"_MC"), w.var(name+"_NSUSYNom"))))
                    print w.function(name+"_fSM_Sigma").getVal()
                    wimport(r.RooRealVar(name+"_fSM", name+"_fSM", w.function(name+"_fSM_Mean").getVal(), 0, 1))
                    wimport(r.RooFormulaVar(name+"_fSMprime", "1 - (@0)*(1-(@1))", r.RooArgList(w.var("f"), w.var(name+"_fSM"))))
                    wimport(r.RooGaussian(name+"_fSM_Gauss", name+"_fSM_Gauss", w.var(name+"_fSM"), w.function(name+"_fSM_Mean"), w.function(name+"_fSM_Sigma")))
                    terms.append(name+"_fSM_Gauss")
                    nuis.append(name+"_fSMprime") # NO warning!!!! changed!!!
                    # obs.append(name+"_NSUSYNom")
                    #obs.append(name+"_MC")
#                    obs.append(name+"_fSM_Mean")
                    R_terms.append(w.function(name+"_fSMprime"))
                R_terms.extend([w.function(syst) for syst in R_systs])
                formula_str = "*".join(["(@%d)" % x for x in range(len(R_terms))])
                al = r.RooArgList()
                for t in R_terms: al.add(t)
                wimport(r.RooFormulaVar("%sBkg%d_N" % (ch.name, idx), formula_str, al))

    def signalBins():
        for ch in channels:
            for idx, eff in ch.enumBins():
                wimport(r.RooRealVar("%sSignal%d_EffNom" % (ch.name, idx), "%sSignal%d_Eff" % (ch.name, idx), ch.signalEff[idx]*ch.triggerEfficiency))
                signalEff_systs = []
                for syst in ch.signalSystematics():
                    name = "%sSignal%d_Eff%s" % (ch.name, idx, syst)
                    wimport(r.RooRealVar(name+"Shift", name+"Shift",
                                         ch.signalEffSyst[syst][idx]*ch.triggerEfficiency))
                    wimport(r.RooFormulaVar(name+"Scale", "((@0) + (@1)*(@2))/(@3)",
                                            r.RooArgList(w.var("%sSignal%d_EffNom" % (ch.name, idx)), w.var("nu%s" % syst),
                                                         w.var(name+"Shift"),
                                                         w.var("%sSignal%d_EffNom" % (ch.name, idx)))))
                    signalEff_systs += [name+"Scale"]

                signalEff_terms = [w.var("%sSignal%d_EffNom" % (ch.name, idx))]
                signalEff_terms.extend([w.function(syst) for syst in signalEff_systs])
                formula_str = "*".join(["(@%d)" % x for x in range(len(signalEff_terms))])
                wimport(r.RooFormulaVar("%sSignal%d_Eff" % (ch.name, idx), formula_str, r.RooArgList(*signalEff_terms)))

                wimport(r.RooProduct("%sSignal%d_N" % (ch.name, idx), "%sSignal%d_N" % (ch.name, idx),
                                     r.RooArgSet(w.var("f"), w.var("nuLumi"), w.var("xs"), w.var("%sLumi" % ch.name),
                                                 w.function("%sSignal%d_Eff" % (ch.name, idx)))))
                wimport(r.RooAddition("%sExpected%d_N" % (ch.name, idx), "%sExpected%d_N" % (ch.name, idx),
                                      r.RooArgSet(w.function("%sBkg%d_N" % (ch.name, idx)), w.function("%sSignal%d_N" % (ch.name, idx)))))
                print "%s - Observed" % ch.name, ch.NObserved[idx]
                wimport(r.RooRealVar("%sObserved%d_N" % (ch.name, idx), "%sObserved%d_N" % (ch.name, idx), ch.NObserved[idx]))
                wimport(r.RooPoisson("%sPoiss%d" % (ch.name, idx), "%sPoiss%d" % (ch.name, idx),
                                     w.var("%sObserved%d_N" % (ch.name, idx)), w.function("%sExpected%d_N" % (ch.name, idx))))
                terms.append("%sPoiss%d" % (ch.name, idx))
                obs.append("%sObserved%d_N" % (ch.name, idx))

    def model():
        w.factory("PROD:model(%s)" % ",".join(terms))

    nuisanceParams()
    signalTerms()
    backgroundPredictions()
    signalBins()
    model()
    print "obs", obs
    print "nuis", nuis
    print "terms", terms
    w.defineSet("obs", ",".join(obs))
    w.defineSet("nuis", ",".join(nuis))
    modelConfig = r.RooStats.ModelConfig("modelConfig", w)
    modelConfig.SetPdf("model")
    w.defineSet("poi", "f")
    modelConfig.SetParametersOfInterest(w.set("poi"))
    modelConfig.SetNuisanceParameters(w.set("nuis"))


    data = r.RooDataSet("dataName", "dataTitle", w.set("obs"))
    data.add(w.set("obs"))
    return (w, modelConfig, data)

