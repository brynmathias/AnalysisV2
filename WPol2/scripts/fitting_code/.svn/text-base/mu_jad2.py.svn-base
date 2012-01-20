#!/usr/bin/env python
import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *

#closure test fit as a function of fitting range

if __name__ == "__main__":
    mu_path = "./ROOTFiles/"
    mu_file_names = ["RecoRoutines_W-selection_realdata.root",
                     "RecoRoutines_W-selection_WJets_madgraph_June2010.root",
                     "RecoRoutines_W-selection_ZJets_madgraph_June2010.root"]

    # Open files
    mu_files = [r.TFile(mu_path + mu_file_name) for mu_file_name in mu_file_names]

    ptwbin = "50toinf"

    # Read histograms
    #mu_plus_hists[0] is the PFPlus histo for the realdata etc
    mu_plus_hists = [f.Get("RECO_PolPlots_"+ptwbin).Get("RECO_ICVarPFPlus") for f in mu_files]
    mu_minus_hists = [f.Get("RECO_PolPlots_"+ptwbin).Get("RECO_ICVarPFMinus") for f in mu_files]

    #to get the total EWK "data" for plus charge i.e. indices 1,2 in mu_file_names, clone 1 and add 2 to it
    total_ewk_plus = mu_plus_hists[1].Clone()
    total_ewk_plus.Add(mu_plus_hists[2])
    
    #wfraction_plus = mu_plus_hists[1].Integral()/total_ewk_plus.Integral()
    #similarly, to get the total EWK "data", but this time for minus charge
    total_ewk_minus = mu_minus_hists[1].Clone()
    total_ewk_minus.Add(mu_minus_hists[2])

    # Read W templates
    mu_plus_wtemplates = [mu_files[1].Get("RECO_PolPlots_"+ptwbin).Get("RECO_ICVarPFPlus_%s" % s)
                          for s in ["LH", "RH", "LO"]]
    mu_minus_wtemplates = [mu_files[1].Get("RECO_PolPlots_"+ptwbin).Get("RECO_ICVarPFMinus_%s" % s)
                          for s in ["LH", "RH", "LO"]]

    # Real data
    real_plus_hists = [mu_plus_hists[0].Clone()]
    real_minus_hists = [mu_minus_hists[0].Clone()]

    # MC Data - is the sum of W and Z contributions. For BG free, only include W i.e. index 1
    mc_plus_hists = [mu_plus_hists[1].Clone(), mu_plus_hists[2].Clone()]
    mc_minus_hists = [mu_minus_hists[1].Clone(), mu_minus_hists[2].Clone()]

    # Scale - see utils.py - scales up by x i.e. to x/pb
    scale(35, mc_plus_hists, mc_minus_hists)

    # Set up signal/bg/helicity templates
    plus_templates = {
        "w" : mu_plus_hists[1],
        "ewk" : mu_plus_hists[2],
        "lh" : mu_plus_wtemplates[0],
        "rh" : mu_plus_wtemplates[1],
        "lo" : mu_plus_wtemplates[2]
        }
    minus_templates = {
        "w" : mu_minus_hists[1],
        "ewk" : mu_minus_hists[2],
        "lh" : mu_minus_wtemplates[0],
        "rh" : mu_minus_wtemplates[1],
        "lo" : mu_minus_wtemplates[2]
        }

    # Rebin - see utils.py
    rebin(10, real_plus_hists, real_minus_hists, mc_plus_hists, mc_minus_hists, plus_templates, minus_templates)

    xmin_plus = -0.4
    xmax_plus = 1.6
    xmin_minus = -0.4
    xmax_minus = 1.6

    flfr_nominalvalues_histminus = r.TH1D("flfr_nominalvalues_histminus","flfr_nominalvalues_histminus",30,-0.05,2.95)
    f0_nominalvalues_histminus = r.TH1D("f0_nominalvalues_histminus","f0_nominalvalues_histminus",30,-0.05,2.95)
    flfr_nominalvalues_histplus = r.TH1D("flfr_nominalvalues_histplus","flfr_nominalvalues_histplus",30,-0.05,2.95)
    f0_nominalvalues_histplus = r.TH1D("f0_nominalvalues_histplus","f0_nominalvalues_histplus",30,-0.05,2.95)


    for index in range(5):

      print "Fitting for LP plus range (%.2f - %.2f)" % (xmin_plus, xmax_plus)
      print "Fitting for LP minus range (%.2f - %.2f)" % (xmin_minus, xmax_minus)
      fit_range_size = xmax_plus - xmin_plus;
        
      # Global parameters in fits - plus
      fit_globals_plus = {
          # Set up fit parameters
          #"lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),
          "lp" : r.RooRealVar("lp", "LP Variable", xmin_plus, xmax_plus),
          
          # Set up fit variables
          "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
          "f2" : r.RooRealVar("f2", "f2", 0., 1.)
          }
      fit_globals_plus["lp"].setRange("lp_range", xmin_plus, xmax_plus)
      # Global parameters in fits - minus
      fit_globals_minus = {
          # Set up fit parameters
          #"lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),
          "lp" : r.RooRealVar("lp", "LP Variable", xmin_minus, xmax_minus),
          
          # Set up fit variables
          "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
          "f2" : r.RooRealVar("f2", "f2", 0., 1.)
          }
      fit_globals_minus["lp"].setRange("lp_range", xmin_minus, xmax_minus)

      #the intr function is defined in utils.py
      wfraction_plus = (intr(mu_plus_hists[1], xmin_plus, xmax_plus)/intr(total_ewk_plus, xmin_plus, xmax_plus))
      wfraction_minus = (intr(mu_minus_hists[1], xmin_minus, xmax_minus)/intr(total_ewk_minus, xmin_minus, xmax_minus))
      
      my_cfg_plus = default_cfg.copy()
      my_cfg_plus["lp_range"] = (xmin_plus, xmax_plus)
      my_cfg_plus["fit_range"] = (xmin_plus, xmax_plus)
      my_cfg_plus["redice"] = False
      my_cfg_plus["f1_init"] = 0.0
      my_cfg_plus["f2_init"] = 0.0
      my_cfg_plus["sumw2"] = r.kFALSE
      my_cfg_plus["output_path"] = "./Plots"

      my_cfg_minus = default_cfg.copy()
      my_cfg_minus["lp_range"] = (xmin_minus, xmax_minus)
      my_cfg_minus["fit_range"] = (xmin_minus, xmax_minus)
      my_cfg_minus["redice"] = False
      my_cfg_minus["f1_init"] = 0.0
      my_cfg_minus["f2_init"] = 0.0
      my_cfg_minus["sumw2"] = r.kFALSE
      my_cfg_minus["output_path"] = "./Plots"
        
      #Fit mu_minus (MC)
      fitminus = run("mu_minus_mc",
                     fit_globals_minus,
                     #real_plus_hists,
                     mc_minus_hists,
                     minus_templates,
                     {"w" : wfraction_minus},
                     #action = "fit_minuit",
                     action = "fit",
                     #redice = False,
                     **my_cfg_minus
                     )

      #Fit mu_plus (MC)
      fitplus = run("mu_plus_mc",
                    fit_globals_plus,
                    #real_plus_hists,
                    mc_plus_hists,
                    plus_templates,
                    {"w" : wfraction_plus},
                    #action = "fit_minuit",
                    action = "fit",
                    #redice = False,
                    **my_cfg_plus
                    )
      #plot_fit(fit_globals, fit, **my_cfg)
      #fL_result = fL(fit["result"])
      #fR_result = fR(fit["result"])
      fLfR_resultplus = fLminusfR(fitplus["result"])
      f0_resultplus = f0(fitplus["result"])
      fLfR_resultminus = fLminusfR(fitminus["result"])
      f0_resultminus = f0(fitminus["result"])
      
      flfr_nominalvalues_histplus.Fill(fit_range_size,fLfR_resultplus[0])
      flfr_nominalvalues_histplus.SetBinError(flfr_nominalvalues_histplus.FindBin(fit_range_size),fLfR_resultplus[1]);
      f0_nominalvalues_histplus.Fill(fit_range_size,f0_resultplus[0])
      f0_nominalvalues_histplus.SetBinError(f0_nominalvalues_histplus.FindBin(fit_range_size),f0_resultplus[1]);

      flfr_nominalvalues_histminus.Fill(fit_range_size,fLfR_resultminus[0])
      flfr_nominalvalues_histminus.SetBinError(flfr_nominalvalues_histminus.FindBin(fit_range_size),fLfR_resultminus[1]);
      f0_nominalvalues_histminus.Fill(fit_range_size,f0_resultminus[0])
      f0_nominalvalues_histminus.SetBinError(f0_nominalvalues_histminus.FindBin(fit_range_size),f0_resultminus[1]);
      
      xmin_plus = xmin_plus + 0.10
      xmax_plus = xmax_plus - 0.10
      xmin_minus = xmin_minus + 0.10
      xmax_minus = xmax_minus - 0.10
        
    outputfile = r.TFile("outputfile_nominalvalues50toinf.root", "RECREATE")
    flfr_nominalvalues_histplus.Write()
    f0_nominalvalues_histplus.Write()
    flfr_nominalvalues_histminus.Write()
    f0_nominalvalues_histminus.Write()
    outputfile.Close()
    #print "fL = " + str(fL_result[0]) + " +/- " + str(fL_result[1])
    #print "fR = " + str(fR_result[0]) + " +/- " + str(fR_result[1])
    #print "fL-fR = " + str(fLfR_result[0]) + " +/- " + str(fLfR_result[1])
    #print "f0 = " + str(f0_result[0]) + " +/- " + str(f0_result[1])
