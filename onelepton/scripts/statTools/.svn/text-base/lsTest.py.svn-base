#!/usr/bin/env python
import ROOT as r
import math
from limit_utils import cls

# Loose
loose = {
    "name" : "LS Loose",
    "predicted" : 49.8,
    "stat" : 8.8,
    "syst" : 10.8,
    "observed" : 52,
    "lm6" : 15
    }

# Tight
tight = {
    "name" : "LS Tight",
    "predicted" : 12.1,
    "stat" : 4.3,
    "syst" : 3.6,
    "observed" : 8,
    "lm6" : 10
    }

############ CONFIG ##########
# Choose which selection to run
run = tight
#run = loose
# Relative signal error
signal_error = 0.2
# Signal point
signal_point = "lm6"
nToys = 500
##############################

# Which signal point
run["Nsig"] = run[signal_point]
# Relative signal error
run["Nsig_delta"] = signal_error
# Relative background error
run["Nbkg_delta"] = math.sqrt(run["stat"]**2 + run["syst"]**2)/run["predicted"]

def likelihood():
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
    # Parameter of interest - signal strength
    wimport(r.RooRealVar("f", "f", 0.1, 0.0, 1.0))
    # Signal statistical nuisance parameter (Gaussian)
    wimport(r.RooRealVar("Nsig", "Nsig", run["Nsig"]))
    wimport(r.RooRealVar("Nsig_rho", "Nsig_rho", 1.0, 0.0, 5.0))
    wimport(r.RooRealVar("Nsig_mean", "Nsig_mean", 1.0))
    wimport(r.RooRealVar("Nsig_delta", "Nsig_delta", run["Nsig_delta"]))
    wimport(r.RooGaussian("Nsig_gauss", "Nsig_gauss", w.var("Nsig_rho"), w.var("Nsig_mean"), w.var("Nsig_delta")))
    terms += ["Nsig_gauss"]
    obs += ["Nsig_mean"]
    nuis += ["Nsig_rho"]

    # Backgroun prediction nuisance parameter
    wimport(r.RooRealVar("Nbkg", "Nbkg", run["predicted"]))
    wimport(r.RooRealVar("Nbkg_rho", "Nbkg_rho", 1.0, 0.0, 5.0))
    wimport(r.RooRealVar("Nbkg_mean", "Nbkg_mean", 1.0))
    wimport(r.RooRealVar("Nbkg_delta", "Nbkg_delta", run["Nbkg_delta"]))
    wimport(r.RooGaussian("Nbkg_gauss", "Nbkg_gauss", w.var("Nbkg_rho"), w.var("Nbkg_mean"), w.var("Nbkg_delta")))
    terms += ["Nbkg_gauss"]
    obs += ["Nbkg_mean"]
    nuis += ["Nbkg_rho"]

    # Total number of events = f * rho_sig * Nsig + rho_bkg * Nbkg
    wimport(r.RooFormulaVar("N", "(@0)*(@1)*(@2) + (@2)*(@3)", r.RooArgList(w.var("f"), w.var("Nsig"), w.var("Nsig_rho"),
                                                                            w.var("Nbkg_rho"), w.var("Nbkg"))))
    # Observed number of events
    wimport(r.RooRealVar("Nobs", "Nobs", run["observed"]))
    obs += ["Nobs"]
    # Poisson term P(Nobs | Nsig+Nbkg)
    wimport(r.RooPoisson("Npoiss", "Npoiss", w.var("Nobs"), w.function("N")))
    terms += ["Npoiss"]

    # Model likelihood = Nsig_gauss * Nbkg_gauss * Npoiss
    w.factory("PROD:model(%s)" % ",".join(terms))

    w.defineSet("obs", ",".join(obs))
    w.defineSet("nuis", ",".join(nuis))
    modelConfig = r.RooStats.ModelConfig("modelConfig", w)
    modelConfig.SetPdf("model")
    w.defineSet("poi", "f")
    modelConfig.SetParametersOfInterest(w.set("poi"))
    modelConfig.SetNuisanceParameters(w.set("nuis"))
    data = r.RooDataSet("dataName", "dataTitle", w.set("obs"))
    data.add(w.set("obs"))


    return (modelConfig, w, data)


if __name__ == "__main__":
    modelConfig, wspace, dset = likelihood()
    lim = cls(wspace, modelConfig, dset,  0.95, nToys)
#    lim =     {'Median': 0.0060271646859082076, 'CLsError': 0.0050864472425011424, 'MedianMinusOneSigma': 0.0019124826874588787, 'CLb': 0.58899999999999997, 'MedianPlusOneSigma': 0.93135476970866515, 'CLs+b': 0.0089999999999999993, 'CLs': 0.015280135823429542, 'PoiValue': 1.0}
    print "="*40
    print "RESULTS: %s (%s)" % (run["name"], signal_point)
    print "="*40
    for k, v in lim.iteritems():
        print "{0:<30} {1:<20.4f}".format(k, v)
    print "="*40



