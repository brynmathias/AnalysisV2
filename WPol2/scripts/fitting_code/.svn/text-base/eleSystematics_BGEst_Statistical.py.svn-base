#!/usr/bin/env python

# This script can be used to produce ROOT files giving the distribution of
# fitted values over an ensemble of toy experiments. It is intended that we use
# this to judge the systematic error on (fL - fR) and f0 from the QCD background
# estimation.


import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *
#import qcdtemplates
import copy
import random

pulls = False
cfg = {}
cfg["model_class"] = RooW_TH1D
cfg["redice"] = True
cfg["lp_range"] = (0.0, 1.3)
ele_dir = "lp_postmht_mt50_%s"


if __name__ == "__main__":
    el_path = "./ROOTFiles/"
    el_path = "/home/hep/as1604/Work/WPol/WCWPolAnalysis/controlAnalysis/ZeroMC_v1/"
    el_file_names = ["eWPol_EG.root",
                     "eWPol_WJets-madgraph_v1.root",
#                     "eWPol_ZJets-madgraph_v1.root",
                     "eWPol_EWK.root",
                     "eWPol_QCD_EMEnriched.root",
                     "eWPol_QCD_BCtoE.root",
                     "eWPol_PhotonJet.root"
                     ]

    # Open files
    el_files = [r.TFile(el_path + el_file_name) for el_file_name in el_file_names]
    # Read histograms
    el_plus_hists = [f.Get(ele_dir % "sig").Get("lp_plus") for f in el_files]
    el_minus_hists = [f.Get(ele_dir % "sig").Get("lp_minus") for f in el_files]


    # Load QCD control histogram
    el_control_files = [r.TFile(el_path + el_file_name) for el_file_name in el_file_names]
    el_control_hists_plus = [f.Get(ele_dir % "control").Get("lp_plus") for f in el_control_files[1:]]
    el_control_hists_minus = [f.Get(ele_dir % "control").Get("lp_minus") for f in el_control_files[1:]]
    el_control_hists = el_control_hists_plus + el_control_hists_minus
    qcd_control_hist  = el_control_hists[0].Clone()
    for hist in el_control_hists[1:]:
        qcd_control_hist.Add(hist)
    qcd_control_hist.Scale(0.35)

    # Merge the QCD/photon+jets templates into one histogram
    el_qcd_plus = el_plus_hists[3].Clone()
    for h in el_plus_hists[4:]:
        el_qcd_plus.Add(h)
    el_qcd_minus = el_minus_hists[3].Clone()
    for h in el_minus_hists[4:]:
        el_qcd_minus.Add(h)
    del el_plus_hists[3:]
    del el_minus_hists[3:]
    el_plus_hists.append(el_qcd_plus)
    el_minus_hists.append(el_qcd_minus)

    # Calculate w fraction of ewk contribution
    total_ewk_plus = el_plus_hists[1].Clone()
    total_ewk_plus.Add(el_plus_hists[2])
    wfraction_plus = el_plus_hists[1].Integral()/total_ewk_plus.Integral()

    # Calculate QCD fraction of total MC
    total = total_ewk_plus.Clone()
    total.Add(el_plus_hists[3])
    qcdfraction_plus = el_plus_hists[3].Integral()/total.Integral()

    # Same for minus charge
    total_ewk_minus = el_minus_hists[1].Clone()
    total_ewk_minus.Add(el_minus_hists[2])
    wfraction_minus = el_minus_hists[1].Integral()/total_ewk_minus.Integral()
    total = total_ewk_minus.Clone()
    total.Add(el_minus_hists[3])
    qcdfraction_minus = el_minus_hists[3].Integral()/total.Integral()

    print "+"*50
    print "W Fraction = %.3f (plus), %.3f (minus)" % (wfraction_plus, wfraction_minus)
    print "QCD Fraction = %.3f (plus), %.3f (minus)" % (qcdfraction_plus, qcdfraction_minus)
    print "+"*50

    # Read W templates
    el_plus_wtemplates = [el_files[1].Get(ele_dir % "sig").Get("lp_plus_%s" % s)
                          for s in ["lh", "rh", "lo"]]
    el_minus_wtemplates = [el_files[1].Get(ele_dir % "sig").Get("lp_minus_%s" % s)
                          for s in ["lh", "rh", "lo"]]

    # Real data
    real_plus_hists = [el_plus_hists[0].Clone()]
    real_minus_hists = [el_minus_hists[0].Clone()]

    # MC Data
    mc_plus_hists = [el_plus_hists[1].Clone(),
                     el_plus_hists[2].Clone(),
                     el_plus_hists[3].Clone()
                     ]
    mc_minus_hists = [
        el_minus_hists[1].Clone(),
        el_minus_hists[2].Clone(),
        el_minus_hists[3].Clone()
        ]

    # Scale
    scale(1, mc_plus_hists, mc_minus_hists)

    # Set up signal/bg/helicity templates
    plus_templates = {
        "w" : el_plus_hists[1],
        "qcd" : el_plus_hists[3],
        #"qcd" : qcd_control_hist,
        "ewk" : el_plus_hists[2],
        "lh" : el_plus_wtemplates[0],
        "rh" : el_plus_wtemplates[1],
        "lo" : el_plus_wtemplates[2]
        }
    minus_templates = {
        "w" : el_minus_hists[1],
        "qcd" : el_minus_hists[3],
        "ewk" : el_minus_hists[2],
        "lh" : el_minus_wtemplates[0],
        "rh" : el_minus_wtemplates[1],
        "lo" : el_minus_wtemplates[2]
        }

    # Rebin
    rebin(10, real_plus_hists, real_minus_hists, mc_plus_hists, mc_minus_hists,
          plus_templates, minus_templates, [qcd_control_hist])

    c = r.TCanvas("brun")
    qcd_control_hist.Draw("hist")
    c.SaveAs("./brun.png")

    # Global parameters in fits
    fit_globals = {
        # Set up fit parameters
        "lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),

        # Set up fit variables
        "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
        "f2" : r.RooRealVar("f2", "f2", 0., 1.)
        }

    rf = r.TFile("Plots/systematicsViaToysStatistical35pb_mt50.root", "recreate")
    fLmfR_plus_h = r.TH1D("fLmfR_plus_h", "fLmfR_h_plus",
                     1000, -1, 1)
    f0_plus_h = r.TH1D("f0_plus_h", "f0_h_plus",
                  1000, -1, 1)
    h2d1_plus = r.TH2D("2dh_fLmfR_fLpfR_plus", "2dh1_plus", 1000,
                 0, 1,
                 1000,
                 0, 1)
    h2d2_plus = r.TH2D("2dh_fLmfR_f0_plus", "2dh2_plus", 1000,
                  0, 1,
                  1000,
                  0, 1)
    fLmfR_minus_h = r.TH1D("fLmfR_minus_h", "fLmfR_h_minus",
                     1000, -1, 1)
    f0_minus_h = r.TH1D("f0_minus_h", "f0_h_minus",
                  1000, -1, 1)
    h2d1_minus = r.TH2D("2dh_fLmfR_fLpfR_minus", "2dh1_minus", 1000,
                 0, 1,
                 1000,
                 0, 1)
    h2d2_minus = r.TH2D("2dh_fLmfR_f0_minus", "2dh2_minus", 1000,
                  0, 1,
                  1000,
                  0, 1)


    qcd_hists = []
    for i in range(500):
        r.RooRandom.randomGenerator().SetSeed(101) # was 105
        fluctuated_template = qcd_control_hist.Clone("hist_%d" % i)
        for j in range(h.GetNbinsX()+1):
            fluctuated_template.SetBinContent(j,
                                              random.gauss(fluctuated_template.GetBinContent(j),
                                                           fluctuated_template.GetBinError(j)))
        qcd_hists.append(fluctuated_template)
        tmp_templates = plus_templates.copy()
        tmp_templates["qcd"] = fluctuated_template
        # Fit el_plus (MC)
        fit = run("fit_plus_%d" % i,
                  fit_globals,
                  mc_plus_hists,
                  tmp_templates,
                  {"w" : wfraction_plus,
                   "qcd" : qcdfraction_plus
                   },
                  action="fit",
                  #                  constrain_qcd = True,
                  #                  qcd_mean = qcdfraction_plus,
                  #                  qcd_sigma = 0.5*qcdfraction_plus,
                  #                  qcd_function = qcd_func["model"],
                  **cfg
                  )
        fLmfR_plus_h.Fill(fLminusfR(fit["result"])[0])
        f0_plus_h.Fill(f0(fit["result"])[0])
        h2d1_plus.Fill(fLminusfR(fit["result"])[0], fLplusfR(fit["result"])[0])
        h2d2_plus.Fill(fLminusfR(fit["result"])[0], f0(fit["result"])[0])

        tmp_templates = minus_templates.copy()
        tmp_templates["qcd"] = fluctuated_template

        fit = run("fit_minus_%d" % i,
                  fit_globals,
                  mc_minus_hists,
                  tmp_templates,
                  {"w" : wfraction_minus,
                   "qcd" : qcdfraction_minus
                   },
                  action="fit",
                  #                  constrain_qcd = True,
                  #                  qcd_mean = qcdfraction_minus,
                  #                  qcd_sigma = 0.5*qcdfraction_minus,
                  #                  qcd_function = qcd_func["model"],
                  **cfg
                  )
        fLmfR_minus_h.Fill(fLminusfR(fit["result"])[0])
        f0_minus_h.Fill(f0(fit["result"])[0])
        h2d1_minus.Fill(fLminusfR(fit["result"])[0], fLplusfR(fit["result"])[0])
        h2d2_minus.Fill(fLminusfR(fit["result"])[0], f0(fit["result"])[0])

        # print "fL = %.3f +- %.3f" % (fL(fit["result"])[0],
        #                              fL(fit["result"])[1])
        # print "fR = %.3f +- %.3f" % (fR(fit["result"])[0],
        #                              fR(fit["result"])[1])
        # print "f0 = %.3f +- %.3f" % (f0(fit["result"])[0],
        #                              f0(fit["result"])[1])
        # print "(fL-fR) = %.3f +- %.3f" % (fLminusfR(fit["result"])[0],
        #                                   fLminusfR(fit["result"])[1])
        # print "qcd frac = %.4f" % qcdfraction_plus
    rf.Write()

