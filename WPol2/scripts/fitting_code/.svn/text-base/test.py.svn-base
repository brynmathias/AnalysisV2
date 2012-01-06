#!/usr/bin/env python
import unittest

from wpolfitter.fit import *
from wpolfitter.utils import *

class WPolTestCase:
    def assertWithinErrors(self, name, a, b, err):
        self.assert_(abs(a - b) < err, "Value of %s = %.4f. +- %.4f incompatible with %.4f" %
                     (name, a, err, b))

class MuonTestCase(unittest.TestCase, WPolTestCase):
    def setUp(self):
        mu_path = "./ROOTFiles/"
        mu_file_names = ["RecoRoutines_W-selection_realdata.root",
                         "RecoRoutines_W-selection_WJets_madgraph_June2010.root",
                         "RecoRoutines_W-selection_ZJets_madgraph_June2010.root"]

        # Open files
        self.mu_files = [r.TFile(mu_path + mu_file_name) for mu_file_name in mu_file_names]

        # Read histograms
        self.mu_plus_hists = [f.Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFPlus") for f in self.mu_files]
        self.mu_minus_hists = [f.Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFMinus") for f in self.mu_files]
        total_ewk_plus = self.mu_plus_hists[1].Clone()
        total_ewk_plus.Add(self.mu_plus_hists[2])
        self.wfraction_plus = self.mu_plus_hists[1].Integral()/total_ewk_plus.Integral()

        total_ewk_minus = self.mu_minus_hists[1].Clone()
        total_ewk_minus.Add(self.mu_minus_hists[2])
        self.wfraction_minus = self.mu_minus_hists[1].Integral()/total_ewk_minus.Integral()
        self.mu_plus_wtemplates = [self.mu_files[1].Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFPlus_%s" % s)
                               for s in ["LH", "RH", "LO"]]
        self.mu_minus_wtemplates = [self.mu_files[1].Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFMinus_%s" % s)
                                for s in ["LH", "RH", "LO"]]
        # MC Data
        self.mc_plus_hists = [self.mu_plus_hists[1].Clone(), self.mu_plus_hists[2].Clone()]
        self.mc_minus_hists = [self.mu_minus_hists[1].Clone(), self.mu_minus_hists[2].Clone()]
        # Scale
        scale(100, self.mc_plus_hists, self.mc_minus_hists)

        # Rebin
        rebin(10, self.mc_plus_hists, self.mc_minus_hists)
        # Global parameters in fits
        self.fit_globals = {
            # Set up fit parameters
            "lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),

            # Set up fit variables
            "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
            "f2" : r.RooRealVar("f2", "f2", 0., 1.)
            }

    def test_plus_closure(self):
        """ Perform closure test fit for mu+ and check fL, fR, f0 within fit errors of nominal value"""
        plus_templates = {
            "w" : self.mu_plus_hists[1],
            "lh" : self.mu_plus_wtemplates[0],
            "rh" : self.mu_plus_wtemplates[1],
            "lo" : self.mu_plus_wtemplates[2]
        }
        rebin(10, plus_templates)
        fit = run("mu_plus_mc",
                  self.fit_globals,
                  self.mc_plus_hists[0:1],
                  plus_templates,
                  {"w" : 1},
                  action = "fit_minuit"
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5543
        fR_nom = 0.2270
        f0_nom = 0.208
        self.assertWithinErrors("fL", fL_fit, fL_nom, fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, f0_err)

    def test_plus_bg(self):
        """ Perform closure test fit (incl. bg) for mu+ and check fL, fR, f0
        within fit errors of nominal value"""
        plus_templates = {
            "w" : self.mu_plus_hists[1],
            "ewk" : self.mu_plus_hists[2],
            "lh" : self.mu_plus_wtemplates[0],
            "rh" : self.mu_plus_wtemplates[1],
            "lo" : self.mu_plus_wtemplates[2]
        }
        rebin(10, plus_templates)
        fit = run("mu_plus_mc",
                  self.fit_globals,
                  self.mc_plus_hists[0:2],
                  plus_templates,
                  {"w" : self.wfraction_plus},
                  action = "fit_minuit"
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5543
        fR_nom = 0.2270
        f0_nom = 0.208
        self.assertWithinErrors("fL", fL_fit, fL_nom, fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, f0_err)


    def test_minus_closure(self):
        """ Perform closure test fit for mu- and check fL, fR, f0 within fit
        errors of nominal value"""
        minus_templates = {
            "w" : self.mu_minus_hists[1],
            "lh" : self.mu_minus_wtemplates[0],
            "rh" : self.mu_minus_wtemplates[1],
            "lo" : self.mu_minus_wtemplates[2]
        }
        rebin(10, minus_templates)
        fit = run("mu_minus_mc",
                  self.fit_globals,
                  self.mc_minus_hists[0:1],
                  minus_templates,
                  {"w" : 1},
                  action = "fit_minuit"
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5214
        fR_nom = 0.2707
        f0_nom = 0.212
        assert(abs(fL_fit-fL_nom) < fL_err)
        assert(abs(fR_fit - fR_nom) < fR_err)
        assert(abs(f0_fit - f0_nom) < f0_err)

    def test_minus_bg(self):
        """ Perform closure test fit for mu- (incl. bg) and check fL, fR, f0
        within fit errors of nominal value"""
        minus_templates = {
            "w" : self.mu_minus_hists[1],
            "ewk" : self.mu_minus_hists[2],
            "lh" : self.mu_minus_wtemplates[0],
            "rh" : self.mu_minus_wtemplates[1],
            "lo" : self.mu_minus_wtemplates[2]
        }
        rebin(10, minus_templates)
        fit = run("mu_minus_mc",
                  self.fit_globals,
                  self.mc_minus_hists[0:2],
                  minus_templates,
                  {"w" : self.wfraction_minus},
                  action = "fit_minuit"
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5214
        fR_nom = 0.2707
        f0_nom = 0.212
        self.assertWithinErrors("fL", fL_fit, fL_nom, fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, f0_err)

class EleTestCase(unittest.TestCase, WPolTestCase):
    def setUp(self):
        el_path = "./ROOTFiles/"
        el_file_names = ["eWPol_EG.root",
                         "eWPol_WJets-madgraph_v1.root",
                         "eWPol_ZJets-madgraph_v1.root",
                         "eWPol_QCD_EMEnriched.root",
                         "eWPol_QCD_BCtoE.root",
                         "eWPol_PhotonJet.root"
                         ]
        # Open files
        self.el_files = [r.TFile(el_path + el_file_name) for el_file_name in el_file_names]
        # Read histograms
        self.el_plus_hists = [f.Get("lp_postmht_met15_mt50_sig").Get("lp_plus") for f in self.el_files]
        self.el_minus_hists = [f.Get("lp_postmht_met15_mt50_sig").Get("lp_minus") for f in self.el_files]

        # Merge the QCD/photon+jets templates into one histogram
        el_qcd_plus = self.el_plus_hists[3].Clone()
        for h in self.el_plus_hists[4:]:
            el_qcd_plus.Add(h)
        el_qcd_minus = self.el_minus_hists[3].Clone()
        for h in self.el_minus_hists[4:]:
            el_qcd_minus.Add(h)
        del self.el_plus_hists[3:]
        del self.el_minus_hists[3:]
        self.el_plus_hists.append(el_qcd_plus)
        self.el_minus_hists.append(el_qcd_minus)

        # Calculate w fraction of ewk contribution
        total_ewk_plus = self.el_plus_hists[1].Clone()
        total_ewk_plus.Add(self.el_plus_hists[2])
        self.wfraction_plus = self.el_plus_hists[1].Integral()/total_ewk_plus.Integral()

        # Calculate QCD fraction of total MC
        total = total_ewk_plus.Clone()
        total.Add(self.el_plus_hists[3])
        self.qcdfraction_plus = self.el_plus_hists[3].Integral()/total.Integral()

        # Same for minus charge
        total_ewk_minus = self.el_minus_hists[1].Clone()
        total_ewk_minus.Add(self.el_minus_hists[2])
        self.wfraction_minus = self.el_minus_hists[1].Integral()/total_ewk_minus.Integral()
        total = total_ewk_minus.Clone()
        total.Add(self.el_minus_hists[3])
        self.qcdfraction_minus = self.el_minus_hists[3].Integral()/total.Integral()

        # Read W templates
        self.el_plus_wtemplates = [self.el_files[1].Get("lp_postmht_met15_mt50_sig").Get("lp_plus_%s" % s)
                                   for s in ["lh", "rh", "lo"]]
        self.el_minus_wtemplates = [self.el_files[1].Get("lp_postmht_met15_mt50_sig").Get("lp_minus_%s" % s)
                               for s in ["lh", "rh", "lo"]]

        # MC Data
        self.mc_plus_hists = [self.el_plus_hists[1].Clone(), self.el_plus_hists[2].Clone()]
        self.mc_minus_hists = [self.el_minus_hists[1].Clone(), self.el_minus_hists[2].Clone()]

        # Scale
        #scale(10, self.mc_plus_hists, self.mc_minus_hists)
        # Rebin
        rebin(10, self.mc_plus_hists, self.mc_minus_hists)
        # Global parameters in fits
        self.fit_globals = {
            # Set up fit parameters
            "lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),

            # Set up fit variables
            "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
            "f2" : r.RooRealVar("f2", "f2", 0., 1.)
            }
        self.cfg = {
            "model_class": RooW_TH1D
            }

    def test_plus_closure(self):
        """ Perform closure test fit for el+ and check fL, fR, f0 within fit
        errors of nominal value"""
        plus_templates = {
            "w" : self.el_plus_hists[1],
            "lh" : self.el_plus_wtemplates[0],
            "rh" : self.el_plus_wtemplates[1],
            "lo" : self.el_plus_wtemplates[2]
        }
        rebin(10, plus_templates)
        fit = run("el_plus_mc",
                  self.fit_globals,
                  [self.mc_plus_hists[0]],
                  plus_templates,
                  {"w" : 1},
                  action = "fit_minuit",
                  **self.cfg
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5543
        fR_nom = 0.2270
        f0_nom = 0.208
        self.assertWithinErrors("fL", fL_fit, fL_nom, fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, 3*fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, f0_err)

    def test_plus_bg(self):
        """ Perform closure test fit for el+ (incl. bg) and check fL, fR, f0
        within fit errors of nominal value"""
        plus_templates = {
            "w" : self.el_plus_hists[1],
            "ewk" : self.el_plus_hists[2],
            "lh" : self.el_plus_wtemplates[0],
            "rh" : self.el_plus_wtemplates[1],
            "lo" : self.el_plus_wtemplates[2]
        }
        rebin(10, plus_templates)
        fit = run("el_plus_mc",
                  self.fit_globals,
                  self.mc_plus_hists[0:2],
                  plus_templates,
                  {"w" : self.wfraction_plus},
                  action = "fit_minuit",
                  **self.cfg
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5543
        fR_nom = 0.2270
        f0_nom = 0.208
        self.assertWithinErrors("fL", fL_fit, fL_nom, fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, 3*fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, f0_err)

    def test_minus_closure(self):
        """ Perform closure test fit for el- and check fL, fR, f0 within fit
        errors of nominal value"""
        minus_templates = {
            "w" : self.el_minus_hists[1],
            "lh" : self.el_minus_wtemplates[0],
            "rh" : self.el_minus_wtemplates[1],
            "lo" : self.el_minus_wtemplates[2]
        }
        rebin(10, minus_templates)
        fit = run("el_minus_mc",
                  self.fit_globals,
                  [self.mc_minus_hists[0]],
                  minus_templates,
                  {"w" : 1},
                  action = "fit_minuit",
                  **self.cfg
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5214
        fR_nom = 0.2707
        f0_nom = 0.212
        self.assertWithinErrors("fL", fL_fit, fL_nom, fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, f0_err)

    def test_minus_bg(self):
        """ Perform closure test fit for el- (incl. bg) and check fL, fR, f0
        within fit errors of nominal value"""
        minus_templates = {
            "w" : self.el_minus_hists[1],
            "ewk" : self.el_minus_hists[2],
            "lh" : self.el_minus_wtemplates[0],
            "rh" : self.el_minus_wtemplates[1],
            "lo" : self.el_minus_wtemplates[2]
        }
        rebin(10, minus_templates)
        fit = run("el_minus_mc",
                  self.fit_globals,
                  self.mc_minus_hists[0:2],
                  minus_templates,
                  {"w" : self.wfraction_minus},
                  action = "fit",
                  **self.cfg
                  )
        (fL_fit, fL_err) = fL(fit["result"])
        (fR_fit, fR_err) = fR(fit["result"])
        (f0_fit, f0_err) = f0(fit["result"])
        fL_nom = 0.5214
        fR_nom = 0.2707
        f0_nom = 0.212
        self.assertWithinErrors("fL", fL_fit, fL_nom, 5*fL_err)
        self.assertWithinErrors("fR", fR_fit, fR_nom, 3*fR_err)
        self.assertWithinErrors("f0", f0_fit, f0_nom, 3*f0_err)

if __name__ == "__main__":
    unittest.main()
