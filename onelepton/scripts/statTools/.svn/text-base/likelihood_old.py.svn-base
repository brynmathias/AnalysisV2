class OneLeptonLikelihood(object):
    def __init__(self, constants, data, backgroundInfo, signalInfo=None):
        self.w = r.RooWorkspace("wspace")
        self.terms = []
        self.obs = []
        self.nuis = []
        self.systs = {}
        self.systs["jec"] = "jecDeltas" in signalInfo or "RjecShift" in backgroundInfo
        self.nuisances()
        if signalInfo:
            self.signal(constants, signalInfo)
        self.background(constants, backgroundInfo)
        self.observables(data, signalInfo is not None)
        self.model()
        print self.terms
        print self.obs
        print self.nuis
        self.w.defineSet("obs", ",".join(self.obs))
        self.w.defineSet("nuis", ",".join(self.nuis))
        self.modelConfig = r.RooStats.ModelConfig("modelConfig", self.w)
        self.modelConfig.SetPdf("model")
        if signalInfo:
            self.w.defineSet("poi", "f")
            self.modelConfig.SetParametersOfInterest(self.w.set("poi"))
            self.modelConfig.SetNuisanceParameters(self.w.set("nuis"))

        # self.data = self.w.pdf("model").generate(self.w.set("obs"), r.RooFit.NumEvents(100))
        self.data = r.RooDataSet("dataName", "dataTitle", self.w.set("obs"))
        self.data.add(self.w.set("obs"))

    def __del__(self):
        del self.w
        del self.data
        del self.modelConfig

    def debug(self) :
        self.w.Print("v")
        dotFile = "debug.dot"
        self.w.pdf("model").graphVizTree(dotFile, ":", True, False)
        cmd = "dot -Tps %s -o %s"%(dotFile, dotFile.replace(".dot", ".ps"))
        os.system(cmd)

    def wimport(self, item):
        # suppress info messages
        r.RooMsgService.instance().setGlobalKillBelow(r.RooFit.WARNING)
        getattr(self.w, "import")(item)
        #re-enable all messages
        r.RooMsgService.instance().setGlobalKillBelow(r.RooFit.DEBUG)


    def signal(self, constants, signalInfo):
        self.wimport(r.RooRealVar("f", "f", 1.0, 0.0, 5.0))
        self.wimport(r.RooRealVar("xs", "xs", signalInfo["xs"]))
        self.wimport(r.RooRealVar("lumi", "lumi", constants["lumi"]))
        self.wimport(r.RooRealVar("nuLumi", "nuLumi", 1.0, 0.0, 2.0))
        self.wimport(r.RooRealVar("nuLumiMean", "nuLumiMean", 1.0))
        self.wimport(r.RooRealVar("nuLumiSigma", "nuLumiSigma", 2.0*constants["lumiError"]))
        self.wimport(r.RooGaussian("nuLumiGauss", "nuLumiGauss",
                                  self.w.var("nuLumi"),
                                  self.w.var("nuLumiMean"),
                                  self.w.var("nuLumiSigma")))
        self.terms.append("nuLumiGauss")
        self.nuis.append("nuLumi")
        self.obs.append("nuLumiMean")
        for idx, efficiency in enumerate(signalInfo["efficiencies"]):
            name = "signalEffNom%d" % idx
            self.wimport(r.RooRealVar(name, name, efficiency))

            eff_systs = []
            if "jecDeltas" in signalInfo:
                name="nuSignalJEC%d" % idx
                self.wimport(r.RooRealVar(name+"Delta", name+"Delta",
                                          signalInfo["jecDeltas"][idx]))
                self.wimport(r.RooProduct(name+"EffShift", name+"EffShift",
                                          r.RooArgSet(self.w.var(name+"Delta"),
                                                      self.w.var("nuJEC"))))
                eff_systs.append(name+"EffShift")
            eff_terms = [self.w.var("signalEffNom%d" % idx)]
            eff_terms.extend([self.w.function(eff_syst) for eff_syst in eff_systs])
            assert all(eff_terms), "Variable not found in eff_terms"
            self.wimport(r.RooAddition("signalEff%d" % idx,
                                       "signalEff%d" % idx,
                                       r.RooArgSet(*eff_terms)))
            signal_terms = ([self.w.var(x) for x in ["f", "xs"]] +
                            [self.w.function(x) for x in ["signalEff%d" % idx,
                                                          "lumi", "nuLumi"]])

            assert all(signal_terms), "Variable not found in signal_terms"
            self.wimport(r.RooProduct("signalTerm%d" % idx, "signalTerm%d" % idx,
                                      r.RooArgSet(*signal_terms)))


    def observables(self, data, signal):
        for idx, obs in enumerate(data["NObserved"]):
            name = "observedN%d" % idx
            self.wimport(r.RooRealVar(name, name, obs))
            self.obs.append(name)
            if signal: ras = r.RooArgSet(self.w.function("signalTerm%d" % idx),
                                         self.w.function("bkgTerm%d" % idx))
            else: ras = r.RooArgSet(self.w.var("bkgTerm%d" % idx))
            self.wimport(r.RooAddition("expectedN%d" % idx,
                                       "expectedN%d" % idx,
                                       ras))
            self.wimport(r.RooPoisson("poissonTerm%d" % idx,
                                      "poissonTerm%d" % idx,
                                      self.w.var("observedN%d" % idx),
                                      self.w.function("expectedN%d" % idx)))
            self.terms.append("poissonTerm%d" % idx)
            print self.w.var(name).getVal()

    def nuisances(self):
        if self.systs["jec"]:
            name = "nuJEC"
            self.wimport(r.RooRealVar(name, name,
                                      0, -5, 5))
            self.wimport(r.RooRealVar(name + "Mean", name + "Mean", 0))
            self.wimport(r.RooRealVar(name + "Sigma", name + "Sigma", 1))
            self.wimport(r.RooGaussian(name + "Gauss", name + "Gauss",
                                       self.w.var(name), self.w.var(name+"Mean"),
                                       self.w.var(name+"Sigma")))
            self.nuis.append(name)
            self.terms.append("nuJECGauss")

    def model(self):
        self.w.factory().process("PROD::model(%s)" % ",".join(self.terms))

    def background(self, constants, backgroundInfo):
        for idx, ncontrol in enumerate(backgroundInfo["NControl"]):
            self.wimport(r.RooRealVar("bkgNControl%dMean" % idx,
                                      "bkgNControl%dMean" % idx,
                                      ncontrol))
            self.obs.append("bkgNControl%dMean" % idx)
            self.wimport(r.RooRealVar("bkgNControl%d" % idx,
                                      "bkgNControl%d" % idx,
                                      ncontrol))#, 0.5*ncontrol, 2*ncontrol))
            # These lines are commented for now cause it doesnt seem to work
            # self.wimport(r.RooPoisson("bkgNControl%dPoisson" % idx,
            #                           "bkgNControl%dPoisson" % idx,
            #                           self.w.var("bkgNControl%d" % idx),
            #                           self.w.var("bkgNControl%dMean" % idx)))
            # self.terms.append("bkgNControl%dPoisson" % idx)
            # self.nuis.append("bkgNControl%d" % idx)
            self.wimport(r.RooRealVar("bkgR%d" % idx,
                                      "bkgR%d" % idx,
                                      backgroundInfo["R"][idx]))

            if "RjecShift" in backgroundInfo:
                self.wimport(r.RooRealVar("nuBkgJEC%dDelta" % idx,
                                          "nuBkgJEC%dDelta" % idx, backgroundInfo["jecDeltas"][idx]))
                self.wimport(r.RooProduct("nuBkgJEC%dRShift" % idx,
                                          "nuBkgJEC%dRShift" % idx,
                                          r.RooArgSet(self.w.var("nuJEC"),
                                                      self.w.function("nuBkgJEC%dDelta" % idx))))
                R_systs.append("nuBkgJEC%dRShift" % idx)
            self.wimport(r.RooProduct("bkgTerm%d" % idx,
                                      "bkgTerm%d" % idx,
                                      r.RooArgSet(self.w.var("bkgNControl%d" % idx),
                                                  self.w.var("bkgR%d" % idx))))


    def plInterval(self, cl):
        calc = r.RooStats.ProfileLikelihoodCalculator(self.data, self.modelConfig)
        calc.SetConfidenceLevel(cl)
        interval = calc.GetInterval()
        low = interval.LowerLimit(self.w.var("f"))
        print "WAAAY"
        up = interval.UpperLimit(self.w.var("f"))
        return (low, up)
