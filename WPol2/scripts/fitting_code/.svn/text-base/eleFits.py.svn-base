#!/usr/bin/env python
import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *
#import qcdtemplates

lp_range = (-0.5, 1.5)
ele_dir = "lp_premht_%s"
data = True

if __name__ == "__main__":
    el_path = "./ROOTFiles/"
    el_path = "/home/hep/as1604/Work/WPol/WCWPolAnaylsis/controlAnalysis/jec_zero/"
    el_path = "/home/hep/as1604/Work/WPol/WCWPolAnalysis/controlAnalysis/ZeroMC_v1/"
    el_file_names = ["eWPol_EG.root",
                     "eWPol_WJets-madgraph_v1.root",
		     "eWPol_EWK.root",
#                     "eWPol_ZJets-madgraph_v1.root",
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
    if data:
        temp_dir = el_control_files[0].Get(ele_dir % "control")
#        qcd_control_hist= temp_dir.Get("lp_plus").Clone()
#        qcd_control_hist.Add(temp_dir.Get("lp_minus").Clone())
	qcd_control_hist = temp_dir.Get("lp").Clone()
    else:
        qcd_control_hist  = el_control_hists[0].Clone()
        for hist in el_control_hists[1:]:
            qcd_control_hist.Add(hist)
    c = r.TCanvas("brun")
    qcd_control_hist.Draw("hist")
    c.SaveAs("./brun.png")

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
    wfraction_plus = intr(el_plus_hists[1], *lp_range)/intr(total_ewk_plus, *lp_range)

    # Calculate QCD fraction of total MC
    total = total_ewk_plus.Clone()
    total.Add(el_plus_hists[3])
    qcdfraction_plus = el_plus_hists[3].Integral()/total.Integral()
    qcdfraction_plus = intr(el_plus_hists[3], *lp_range)/intr(total, *lp_range)

    # Same for minus charge
    total_ewk_minus = el_minus_hists[1].Clone()
    total_ewk_minus.Add(el_minus_hists[2])
    wfraction_minus = el_minus_hists[1].Integral()/total_ewk_minus.Integral()
    wfraction_minus = intr(el_minus_hists[1], *lp_range)/intr(total_ewk_minus, *lp_range)
	
    total = total_ewk_minus.Clone()
    total.Add(el_minus_hists[3])
    qcdfraction_minus = el_minus_hists[3].Integral()/total.Integral()
    qcdfraction_minus = intr(el_minus_hists[3], *lp_range)/intr(total, *lp_range)

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
    scale(0.35, mc_plus_hists, mc_minus_hists)

    # Set up signal/bg/helicity templates
    plus_templates = {
        "w" : el_plus_hists[1],
        #"qcd" : el_plus_hists[3],
        "qcd" : qcd_control_hist,
        "ewk" : el_plus_hists[2],
        "lh" : el_plus_wtemplates[0],
        "rh" : el_plus_wtemplates[1],
        "lo" : el_plus_wtemplates[2]
        }
    minus_templates = {
        "w" : el_minus_hists[1],
        "qcd" : qcd_control_hist.Clone(),
        "ewk" : el_minus_hists[2],
        "lh" : el_minus_wtemplates[0],
        "rh" : el_minus_wtemplates[1],
        "lo" : el_minus_wtemplates[2]
        }

    fit_opts = {
        "constrain_qcd" : False,
        "model_class" : RooW_TH1D,
        "redice" : not data,
	"lp_range" : lp_range
        }
    # Rebin
    rebin(10, real_plus_hists, real_minus_hists, mc_plus_hists, mc_minus_hists,
          plus_templates, minus_templates)
    # Global parameters in fits
    fit_globals = {
        # Set up fit parameters
        "lp" : r.RooRealVar("lp", "LP Variable", *fit_opts["lp_range"]),

        # Set up fit variables
        "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
        "f2" : r.RooRealVar("f2", "f2", 0., 1.)
        }

    print "qcd frac = %.4f" % qcdfraction_plus
    #r.RooRandom.randomGenerator().SetSeed(115) # was 105
    r.RooRandom.randomGenerator().SetSeed(105) # was 105
    if data:
        data_str = "data35"
        pseudodata_plus = real_plus_hists
        pseudodata_minus = real_minus_hists
    else:
        data_str = "mc35"
        pseudodata_plus = mc_plus_hists
        pseudodata_minus = mc_minus_hists
    # Fit el_plus (Data)
    fit = run("el_plus_premht_%s" % data_str,
              fit_globals,
              pseudodata_plus,
              plus_templates,
              {"w" : wfraction_plus,
               "qcd" : qcdfraction_plus},
              action = "fit",
#              qcd_mean = qcdfraction_plus,
#              qcd_sigma = 0.5*qcdfraction_plus,
              **fit_opts
              )
    plot_fit(fit_globals, fit,
             nominal_values = nom_values_plus,
             show_extra_values = True)
    print "fL = %.3f +- %.3f" % (fL(fit["result"])[0],
                                 fL(fit["result"])[1])
    print "fR = %.3f +- %.3f" % (fR(fit["result"])[0],
                                 fR(fit["result"])[1])
    print "f0 = %.3f +- %.3f" % (f0(fit["result"])[0],
                                 f0(fit["result"])[1])
    print "(fL-fR) = %.3f +- %.3f" % (fLminusfR(fit["result"])[0],
                                      fLminusfR(fit["result"])[1])
    print "fQCD = %.3f +- %.3f" % (fit["f_qcd"].getVal(), fit["f_qcd"].getError())
    print "qcd frac = %.4f" % qcdfraction_plus
    # # # # Fit el_minus (Data)

    fit = run("el_minus_premht_%s" % data_str,
              fit_globals,
              pseudodata_minus,
              minus_templates,
              {"w" : wfraction_minus,
               "qcd" : qcdfraction_minus},
#              qcd_mean = qcdfraction_minus,
#              qcd_sigma = 0.5*qcdfraction_minus,
              **fit_opts
              )
    plot_fit(fit_globals, fit,
             nominal_values = nom_values_minus,
             show_extra_values = True)

    print "fL = %.3f +- %.3f" % (fL(fit["result"])[0],
                                 fL(fit["result"])[1])
    print "fR = %.3f +- %.3f" % (fR(fit["result"])[0],
                                 fR(fit["result"])[1])
    print "f0 = %.3f +- %.3f" % (f0(fit["result"])[0],
                                 f0(fit["result"])[1])

    print "(fL-fR) = %.3f +- %.3f" % (fLminusfR(fit["result"])[0],
                                      fLminusfR(fit["result"])[1])
    print "fQCD = %.3f +- %.3f" % (fit["f_qcd"].getVal(), fit["f_qcd"].getError())
    print "qcd frac = %.4f" % qcdfraction_plus
