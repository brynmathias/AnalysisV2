#!/usr/bin/env python
import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *
import wpolfitter.contour as contour
import qcdtemplates


fit_globals = {
    # Set up fit parameters
    "lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),

    # Set up fit variables
    "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
    "f2" : r.RooRealVar("f2", "f2", 0., 1.)
    }

cfg = {}

mu_path = "./ROOTFiles/"
mu_file_names = ["RecoRoutines_W-selection_realdata.root",
                 "RecoRoutines_W-selection_WJets_madgraph_June2010.root",
                 "RecoRoutines_W-selection_ZJets_madgraph_June2010.root"]

# Open files
mu_files = [r.TFile(mu_path + mu_file_name) for mu_file_name in mu_file_names]

# Read histograms
mu_plus_hists = [f.Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFPlus") for f in mu_files]
mu_minus_hists = [f.Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFMinus") for f in mu_files]

# Read W templates
mu_plus_wtemplates = [mu_files[1].Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFPlus_%s" % s)
                       for s in ["LH", "RH", "LO"]]
mu_minus_wtemplates = [mu_files[1].Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFMinus_%s" % s)
                        for s in ["LH", "RH", "LO"]]
el_path = "/home/alex/Research/WPol/WPolAnalysis/controlAnalysis/"
el_file_names = ["eWPol_EG.root",
                     "eWPol_WJets-madgraph_v1.root",
                     "eWPol_ZJets-madgraph_v1.root",
                     "eWPol_QCD_EMEnriched.root",
                     "eWPol_QCD_BCtoE.root",
                     "eWPol_PhotonJet.root"
                     ]
# Open files
el_files = [r.TFile(el_path + el_file_name) for el_file_name in el_file_names]
# Read histograms
el_plus_hists = [f.Get("lp_postmht_met15_mt50_sig").Get("lp_plus") for f in el_files]
el_minus_hists = [f.Get("lp_postmht_met15_mt50_sig").Get("lp_minus") for f in el_files]


 # Load QCD control histogram
el_control_files = [r.TFile(el_path + el_file_name) for el_file_name in el_file_names]
el_control_hists_plus = [f.Get("lp_postmht_met15_mt50_control").Get("lp_plus") for f in el_control_files[1:]]
el_control_hists_minus = [f.Get("lp_postmht_met15_mt50_control").Get("lp_minus") for f in el_control_files[1:]]

temp_dir = el_control_files[0].Get("lp_postmht_met15_mt50_control")
qcd_control_hist= temp_dir.Get("lp_plus").Clone()
qcd_control_hist.Add(temp_dir.Get("lp_minus").Clone())

# Read W templates
el_plus_wtemplates = [el_files[1].Get("lp_postmht_met15_mt50_sig").Get("lp_plus_%s" % s)
                      for s in ["lh", "rh", "lo"]]
el_minus_wtemplates = [el_files[1].Get("lp_postmht_met15_mt50_sig").Get("lp_minus_%s" % s)
                       for s in ["lh", "rh", "lo"]]
total_ewk_plus = mu_plus_hists[1].Clone()
total_ewk_plus.Add(mu_plus_hists[2])
wfraction_plus = (intr(mu_plus_hists[1], *default_cfg["lp_range"])/
                  intr(total_ewk_plus, *default_cfg["lp_range"]))
mu_wfraction_plus = mu_plus_hists[1].Integral()/total_ewk_plus.Integral()

total_ewk_minus = mu_minus_hists[1].Clone()
total_ewk_minus.Add(mu_minus_hists[2])
mu_wfraction_minus = (intr(mu_minus_hists[1], *default_cfg["lp_range"])/
                   intr(total_ewk_minus, *default_cfg["lp_range"]))
print wfraction_plus



# Real data
mu_real_plus_hists = [mu_plus_hists[0].Clone()]
mu_real_minus_hists = [mu_minus_hists[0].Clone()]

# MC Data
mu_mc_plus_hists = [mu_plus_hists[1].Clone(), mu_plus_hists[2].Clone()]
mu_mc_minus_hists = [mu_minus_hists[1].Clone(), mu_minus_hists[2].Clone()]

# Scale
scale(35, mu_mc_plus_hists, mu_mc_minus_hists)

# Set up signal/bg/helicity templates
mu_plus_templates = {
    "w" : mu_plus_hists[1],
    "ewk" : mu_plus_hists[2],
    "lh" : mu_plus_wtemplates[0],
    "rh" : mu_plus_wtemplates[1],
    "lo" : mu_plus_wtemplates[2]
}
mu_minus_templates = {
    "w" : mu_minus_hists[1],
    "ewk" : mu_minus_hists[2],
    "lh" : mu_minus_wtemplates[0],
    "rh" : mu_minus_wtemplates[1],
    "lo" : mu_minus_wtemplates[2]
    }

# Rebin
rebin(10, mu_real_plus_hists, mu_real_minus_hists, mu_mc_plus_hists, mu_mc_minus_hists,
          mu_plus_templates, mu_minus_templates)

# # Fit mu_plus (Data)
total_ewk_plus = mu_plus_hists[1].Clone()
total_ewk_plus.Add(mu_plus_hists[2])

mu = run("mu_plus_data",
         fit_globals,
         mu_real_plus_hists,
         mu_plus_templates,
         {"w" : mu_wfraction_plus},
         action = "fit_minuit",
          **cfg
         )
contour.plot_contour(fit_globals, mu, 1, "./Plots/mu_plus_contours/1.pdf")

print "fL = %.3f +- %.3f" % (fL(mu["result"])[0],
                             fL(mu["result"])[1])
print "fR = %.3f +- %.3f" % (fR(mu["result"])[0],
                             fR(mu["result"])[1])
print "f0 = %.3f +- %.3f" % (f0(mu["result"])[0],
                             f0(mu["result"])[1])
print "(fL-fR) = %.3f +- %.3f" % (fLminusfR(mu["result"])[0],
                                  fLminusfR(mu["result"])[1])

cfg = {}
cfg["model_class"] = RooW_TH1D

# el_control_hists = el_control_hists_plus + el_control_hists_minus
# qcd_control_hist  = el_control_hists[0].Clone()
# for hist in el_control_hists[1:]:
#     qcd_control_hist.Add(hist)
# c = r.TCanvas("brun")
# qcd_control_hist.Draw("hist")
# c.SaveAs("./brun.png")

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
el_wfraction_plus = el_plus_hists[1].Integral()/total_ewk_plus.Integral()

# Calculate QCD fraction of total MC
total = total_ewk_plus.Clone()
total.Add(el_plus_hists[3])
el_qcdfraction_plus = el_plus_hists[3].Integral()/total.Integral()

# Same for minus charge
total_ewk_minus = el_minus_hists[1].Clone()
total_ewk_minus.Add(el_minus_hists[2])
el_wfraction_minus = el_minus_hists[1].Integral()/total_ewk_minus.Integral()
total = total_ewk_minus.Clone()
total.Add(el_minus_hists[3])
el_qcdfraction_minus = el_minus_hists[3].Integral()/total.Integral()


cfg["model_class"] = RooW_TH1D

# Real data
el_real_plus_hists = [el_plus_hists[0].Clone()]
el_real_minus_hists = [el_minus_hists[0].Clone()]

# MC Data
el_mc_plus_hists = [el_plus_hists[1].Clone(),
                     el_plus_hists[2].Clone(),
                     el_plus_hists[3].Clone()
                     ]
el_mc_minus_hists = [
    el_minus_hists[1].Clone(),
    el_minus_hists[2].Clone(),
    el_minus_hists[3].Clone()
    ]

# Scale
scale(0.35, el_mc_plus_hists, el_mc_minus_hists)

# Set up signal/bg/helicity templates
el_plus_templates = {
    "w" : el_plus_hists[1],
 #   "qcd" : el_plus_hists[3],
    "qcd" : qcd_control_hist,
    "ewk" : el_plus_hists[2],
    "lh" : el_plus_wtemplates[0],
    "rh" : el_plus_wtemplates[1],
    "lo" : el_plus_wtemplates[2]
    }
el_minus_templates = {
    "w" : el_minus_hists[1],
    "qcd" : qcd_control_hist.Clone(),
    "ewk" : el_minus_hists[2],
    "lh" : el_minus_wtemplates[0],
    "rh" : el_minus_wtemplates[1],
    "lo" : el_minus_wtemplates[2]
    }

# Rebin
rebin(10, el_real_plus_hists, el_real_minus_hists, el_mc_plus_hists, el_mc_minus_hists,
      el_plus_templates, el_minus_templates)

qcd_func = qcdtemplates.qcd_data_mt50(fit_globals["lp"])

# Fit el_plus (Data)
el = run("el_plus_data",
          fit_globals,
          el_real_plus_hists,
          el_plus_templates,
          {"w" : el_wfraction_plus,
           "qcd" : el_qcdfraction_plus},
          # constrain_qcd = True,
          # qcd_mean = el_qcdfraction_plus,
          # qcd_sigma = 0.5*el_qcdfraction_plus,
          action = "simultaneous",
          **cfg
          )

fit_globals["f1"].setVal(0.556)
fit_globals["f2"].setVal(0.555)
fit = sim_fit("plus_fit",
              fit_globals,
              "ele_plus_data",
              ele_plus_data = el,
              muon_plus_data = mu
              )
contour.plot_contour(fit_globals, fit, 1, "./Plots/sim_plus_contours/1.pdf")
fit["result"].Print("v")
fit["sim_pdf"].Print("v")
print "fL = %.3f +- %.3f" % (fL(fit["result"])[0],
                             fL(fit["result"])[1])
print "fR = %.3f +- %.3f" % (fR(fit["result"])[0],
                             fR(fit["result"])[1])
print "f0 = %.3f +- %.3f" % (f0(fit["result"])[0],
                             f0(fit["result"])[1])
print "(fL-fR) = %.3f +- %.3f" % (fLminusfR(fit["result"])[0],
                                  fLminusfR(fit["result"])[1])
