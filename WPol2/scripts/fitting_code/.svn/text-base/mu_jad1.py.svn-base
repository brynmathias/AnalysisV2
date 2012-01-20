#!/usr/bin/env python
import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *

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

    xmin = -0.5
    xmax = 1.5

    flfrtoystudyhists = [] #declare an array to be filled with histrograms below
    f0toystudyhists = [] #declare an array to be filled with histrograms below

    #flfrvalueshist = r.TH1D("flfrvalueshist","flfrvalueshist",30,-0.05,2.95)
    #f0valueshist = r.TH1D("f0valueshist","f0valueshist",30,-0.05,2.95)
    
    for index in range(5):

        print "Fitting for LP range (%.2f - %.2f)" % (xmin, xmax)
        fit_range_size = xmax - xmin;
        
        #set up the histograms for this fit range
        flfrtoystudyhists.append(r.TH1D(("flfrtoystudyhist_fitrange%.2f" % fit_range_size),("flfrtoystudyhist_fitrange%.2f" % fit_range_size),1000,-0.0005,0.9995))
        f0toystudyhists.append(r.TH1D(("f0toystudyhist_fitrange%.2f" % fit_range_size),("f0toystudyhist_fitrange%.2f" % fit_range_size),1000,-0.0005,0.9995))
        #flfrvalueshist = r.TH1D("flfrvalueshist","flfrvalueshist",30,-0.05,2.95)
        #f0valueshist = r.TH1D("f0valueshist","f0valueshist",30,-0.05,2.95)
        
        # Global parameters in fits
        fit_globals = {
            # Set up fit parameters
            #"lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),
            "lp" : r.RooRealVar("lp", "LP Variable", xmin, xmax),
            
            # Set up fit variables
            "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
            "f2" : r.RooRealVar("f2", "f2", 0., 1.)
            }
        fit_globals["lp"].setRange("lp_range", xmin, xmax)
        
        #the intr function is defined in utils.py
        wfraction_plus = (intr(mu_plus_hists[1], xmin, xmax)/intr(total_ewk_plus, xmin, xmax))
        wfraction_minus = (intr(mu_minus_hists[1], xmin, xmax)/intr(total_ewk_minus, xmin, xmax))
        
        my_cfg = default_cfg.copy()
        my_cfg["lp_range"] = (xmin, xmax)
        my_cfg["fit_range"] = (xmin, xmax)
        my_cfg["redice"] = True
        my_cfg["f1_init"] = 0.0
        my_cfg["f2_init"] = 0.0
        my_cfg["sumw2"] = r.kFALSE
        my_cfg["output_path"] = "./Plots"
        
        for numexps in range(1000):
##          #Fit mu_minus (MC)
##          fit = run("mu_minus_mc",
##                    fit_globals,
##                    #real_plus_hists,
##                    mc_minus_hists,
##                    minus_templates,
##                    {"w" : wfraction_minus},
##                    #action = "fit_minuit",
##                    action = "fit",
##                    #redice = False,
##                    **my_cfg
##                    )
          #Fit mu_plus (MC)
          fit = run("mu_plus_mc",
                    fit_globals,
                    #real_plus_hists,
                    mc_plus_hists,
                    plus_templates,
                    {"w" : wfraction_plus},
                    #action = "fit_minuit",
                    action = "fit",
                    #redice = False,
                    **my_cfg
                    )
          #plot_fit(fit_globals, fit, **my_cfg)
          fL_result = fL(fit["result"])
          fR_result = fR(fit["result"])
          fLfR_result = fLminusfR(fit["result"])
          f0_result = f0(fit["result"])
          
          #flfrvalueshist.Fill(fit_range_size,fLfR_result[0])
          #flfrvalueshist.SetBinError(flfrvalueshist.FindBin(fit_range_size),fLfR_result[1]);
          #f0valueshist.Fill(fit_range_size,f0_result[0])
          #f0valueshist.SetBinError(f0valueshist.FindBin(fit_range_size),f0_result[1]);
          flfrtoystudyhists[index].Fill(fLfR_result[0])
          f0toystudyhists[index].Fill(f0_result[0])
        xmin = xmin + 0.10
        xmax = xmax - 0.10
        
    outputfile = r.TFile("outputfile_plus50toinf_md5_p1d5.root", "RECREATE")
    #flfrvalueshist.Write()
    #f0valueshist.Write()
    for i in flfrtoystudyhists:
      i.Write()
    for i in f0toystudyhists:
      i.Write()
    outputfile.Close()
    #print "fL = " + str(fL_result[0]) + " +/- " + str(fL_result[1])
    #print "fR = " + str(fR_result[0]) + " +/- " + str(fR_result[1])
    #print "fL-fR = " + str(fLfR_result[0]) + " +/- " + str(fLfR_result[1])
    #print "f0 = " + str(f0_result[0]) + " +/- " + str(f0_result[1])

    
    #fL_result = fL(fit["mcstudy"].fitResult(index))
##      fL_result = fL(fit["result"])
##      fR_result = fR(fit["result"])
##      myhist.Fill(fL_result[0])
##      myhist2.Fill(fR_result[0])
##      #print "fL result"+ str(index) + " = " + str(fL_result[0]) + " +/- " + str(fL_result[1])
##    c=r.TCanvas("c3","c3",500,500)
##    myhist.Draw()
##    c.SaveAs(".root");
##    c2=r.TCanvas("c4","c4",500,500)
##    myhist2.Draw()
##    c2.SaveAs(".root");    

