#!/usr/bin/env python

# This script can be used to produce ROOT files giving the distribution of
# fitted values over an ensemble of toy experiments. It is intended that we use
# this to judge the systematic error on (fL - fR) and f0 from the QCD background
# estimation.


import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *
import eleQCDFunctionTemplates
import copy
import random
import math

cfg = {}
cfg["model_class"] = RooW_TH1D
#cfg["redice"] = True
ele_dir = "lp_postmht_mt50_%s"
quit = False

def SaveGraph(g, n):
    g.SetName(n)
    g.Write(n)

# Commented values were from old 36 W+Jets sample
fLfR_plus_nom = 0.311 # was 0.317
f0_plus_nom = 0.212 # was 0.210
fLfR_minus_nom = 0.258 # was 0.268
f0_minus_nom = 0.226 # was 0.218
    
if __name__ == "__main__":
    el_path = "./ROOTFiles/"
    el_path = "/home/hep/as1604/Work/WPol/WCWPolAnalysis/controlAnalysis/ZeroMC_v1/"
    el_file_names = [
        #"eWPol_EG.root",
        "eWPol_WJets-madgraph_v1.root",
#        "eWPol_ZJets-madgraph_v1.root",
	"eWPol_EWK.root",
        "eWPol_QCD_EMEnriched.root",
        "eWPol_QCD_BCtoE.root",
        "eWPol_PhotonJet.root"
        ]
    outf = open("Plots/systematicsOthers.txt", "w")
    rf = r.TFile("Plots/systematicsOthers.root", "recreate")	    
    h_plus_fLfR = r.TH2D("fLfR_plus", "fLfR_plus", 100, 0, 100, 1000, 0, 1)
    h_plus_fLfR_syst = r.TH2D("fLfR_plus_syst", "fLfR_plus_syst", 100, 0, 100, 1000, 0, 1)
    h_plus_fLfR_err = r.TH2D("fLfR_plus_err", "fLfR_plus_err", 100, 0, 100, 1000, 0, 1)
    h_plus_fLfR_total = r.TH2D("fLfR_plus_total", "fLfR_plus_total", 100, 0, 100, 1000, 0, 1)

    h_plus_f0 = r.TH2D("f0_plus", "f0_plus", 100, 0, 100, 1000, 0, 1)
    h_plus_f0_syst = r.TH2D("f0_plus_syst", "f0_plus_syst", 100, 0, 100, 1000, 0, 1)
    h_plus_f0_err = r.TH2D("f0_plus_err", "f0_plus_err", 100, 0, 100, 1000, 0, 1)
    h_plus_f0_total = r.TH2D("f0_plus_total", "f0_plus_total", 100, 0, 100, 1000, 0, 1)

    h_minus_fLfR = r.TH2D("fLfR_minus", "fLfR_minus", 100, 0, 100, 1000, 0, 1)
    h_minus_fLfR_syst = r.TH2D("fLfR_minus_syst", "fLfR_minus_syst", 100, 0, 100, 1000, 0, 1)
    h_minus_fLfR_err = r.TH2D("fLfR_minus_err", "fLfR_minus_err", 100, 0, 100, 1000, 0, 1)
    h_minus_fLfR_total = r.TH2D("fLfR_minus_total", "fLfR_minus_total", 100, 0, 100, 1000, 0, 1)

    h_minus_f0 = r.TH2D("f0_minus", "f0_minus", 100, 0, 100, 1000, 0, 1)
    h_minus_f0_syst = r.TH2D("f0_minus_syst", "f0_minus_syst", 100, 0, 100, 1000, 0, 1)
    h_minus_f0_err = r.TH2D("f0_minus_err", "f0_minus_err", 100, 0, 100, 1000, 0, 1)
    h_minus_f0_total = r.TH2D("f0_minus_total", "f0_minus_total", 100, 0, 100, 1000, 0, 1)

    my_fit_ranges = [
	       (-0.4, 1.6),
               (-0.4, 1.5),
               (-0.4, 1.4),
               (-0.4, 1.3),
               (-0.4, 1.2),
               (-0.4, 1.1),
               (-0.4, 1.0),
	       (-0.3, 1.6),
               (-0.3, 1.5),
               (-0.3, 1.4),
               (-0.3, 1.3),
               (-0.3, 1.2),
               (-0.3, 1.1),
               (-0.3, 1.0),
               (-0.2, 1.6),
               (-0.2, 1.5),
               (-0.2, 1.4),
               (-0.2, 1.3),
               (-0.2, 1.2),
               (-0.2, 1.1),
               (-0.2, 1.0),
               (-0.1, 1.6),
               (-0.1, 1.5),
               (-0.1, 1.4),
               (-0.1, 1.3),
               (-0.1, 1.2),
               (-0.1, 1.1),
               (-0.1, 1.0),
               (0.0, 1.6),
               (0.0, 1.5),
               (0.0, 1.4),
               (0.0, 1.3),
               (0.0, 1.2),
               (0.0, 1.1),             
               (0.0, 1.0)
               ]
    #    my_fit_ranges = [(-0.4, 1.6)]
    my_fit_ranges = [(0, 1.3)]
    g_plus_fLfR_total_max = r.TGraph(len(my_fit_ranges))
    g_plus_f0_total_max = r.TGraph(len(my_fit_ranges))
    g_minus_fLfR_total_max = r.TGraph(len(my_fit_ranges))
    g_minus_f0_total_max = r.TGraph(len(my_fit_ranges))

    g_err_plus_fLfR_total = r.TGraphAsymmErrors(len(my_fit_ranges))
    g_err_plus_f0_total = r.TGraphAsymmErrors(len(my_fit_ranges))
    g_err_plus_fLfR_stat = r.TGraphErrors(len(my_fit_ranges))
    g_err_plus_f0_stat = r.TGraphErrors(len(my_fit_ranges))
    g_err_plus_fLfR_syst = r.TGraphAsymmErrors(len(my_fit_ranges))
    g_err_plus_f0_syst = r.TGraphAsymmErrors(len(my_fit_ranges))

    g_err_minus_fLfR_total = r.TGraphAsymmErrors(len(my_fit_ranges))
    g_err_minus_f0_total = r.TGraphAsymmErrors(len(my_fit_ranges))
    g_err_minus_fLfR_stat = r.TGraphErrors(len(my_fit_ranges))
    g_err_minus_f0_stat = r.TGraphErrors(len(my_fit_ranges))
    g_err_minus_fLfR_syst = r.TGraphAsymmErrors(len(my_fit_ranges))
    g_err_minus_f0_syst = r.TGraphAsymmErrors(len(my_fit_ranges))
    
    for fr_idx, fr in enumerate(my_fit_ranges):
        print "%d & $%.2f \\longrightarrow %.2f$\\\\" % (fr_idx, fr[0], fr[1])
    for fr_idx, fr in enumerate(my_fit_ranges):
        outf.write("Range %.2f -> %.2f\n" % (fr[0], fr[1]))
        # Open files
        el_files = [r.TFile(el_path + el_file_name) for el_file_name in el_file_names]
        # Read histograms
        el_plus_hists = [f.Get(ele_dir % "sig").Get("lp_plus").Clone() for f in el_files]
        el_minus_hists = [f.Get(ele_dir % "sig").Get("lp_minus").Clone() for f in el_files]

        # Merge the QCD/photon+jets templates into one histogram
        el_qcd_plus = el_plus_hists[2].Clone()
        for h in el_plus_hists[3:]:
            el_qcd_plus.Add(h)
        el_qcd_minus = el_minus_hists[2].Clone()
        for h in el_minus_hists[3:]:
            el_qcd_minus.Add(h)
        del el_plus_hists[2:]
        del el_minus_hists[2:]
        el_plus_hists.append(el_qcd_plus)
        el_minus_hists.append(el_qcd_minus)

        # Calculate w fraction of ewk contribution
        total_ewk_plus = el_plus_hists[0].Clone()
        total_ewk_plus.Add(el_plus_hists[1])
        wfraction_plus = intr(el_plus_hists[0], *fr)/intr(total_ewk_plus, *fr)

        # Calculate QCD fraction of total MC
        total = total_ewk_plus.Clone()
        total.Add(el_plus_hists[2])
        qcdfraction_plus = intr(el_plus_hists[2], *fr)/intr(total, *fr)

        # Same for minus charge
        total_ewk_minus = el_minus_hists[0].Clone()
        total_ewk_minus.Add(el_minus_hists[1])
        wfraction_minus = intr(el_minus_hists[0],*fr)/intr(total_ewk_minus, *fr)
        total = total_ewk_minus.Clone()
        total.Add(el_minus_hists[2])
        qcdfraction_minus = intr(el_minus_hists[2], *fr)/intr(total, *fr)

        print "+"*50
        print "W Fraction = %.3f (plus), %.3f (minus)" % (wfraction_plus, wfraction_minus)
        print "QCD Fraction = %.3f (plus), %.3f (minus)" % (qcdfraction_plus, qcdfraction_minus)
        print "+"*50

        # Read W templates
        el_plus_wtemplates = [el_files[0].Get(ele_dir % "sig").Get("lp_plus_%s" % s)
                              for s in ["lh", "rh", "lo"]]
        el_minus_wtemplates = [el_files[0].Get(ele_dir % "sig").Get("lp_minus_%s" % s)
                               for s in ["lh", "rh", "lo"]]



        # Set up signal/bg/helicity templates
        plus_templates = {
            "w" : el_plus_hists[0],
            "qcd" : el_plus_hists[2],
            #"qcd" : qcd_control_hist,
            "ewk" : el_plus_hists[1],
            "lh" : el_plus_wtemplates[0],
            "rh" : el_plus_wtemplates[1],
            "lo" : el_plus_wtemplates[2]
            }
        minus_templates = {
            "w" : el_minus_hists[0],
            "qcd" : el_minus_hists[2],
            "ewk" : el_minus_hists[1],
            "lh" : el_minus_wtemplates[0],
            "rh" : el_minus_wtemplates[1],
            "lo" : el_minus_wtemplates[2]
            }

        # Rebin
        rebin(10, plus_templates, minus_templates)

        # Global parameters in fits
        fit_globals = {
            # Set up fit parameters
            "lp" : r.RooRealVar("lp", "LP Variable", *fr),#default_cfg["lp_range"]),

            # Set up fit variables
            "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
            "f2" : r.RooRealVar("f2", "f2", 0., 1.)
            }
        err_fLfR_plus_syst = {}
        err_fLfR_plus_stat = {}
        err_f0_plus_syst = {}
        err_f0_plus_stat = {}
        err_fLfR_minus_syst = {}
        err_fLfR_minus_stat = {}
        err_f0_minus_syst = {}
        err_f0_minus_stat = {}
        flfR_plus_central = 0
        f0_plus_central = 0
        fLfR_minus_central = 0
        f0_minus_central = 0
        fLfR_plus_total = -1
        f0_plus_total = -1
        fLfR_minus_total = -1
        f0_minus_total = -1
        
        for d in ["ZeroMC_v1",
                  "JECPlus5pcMC_v1",
                  "JECMinus5pcMC_v1",
#		  "ECALTransparencyUnCorrectedMC_v1",
		  "ECALTransparencyUnCorrectedPlus50pcMC_v2",
		  "ECALTransparencyUnCorrectedMinus50pcMC_v2"
                  ]:
            outf.write("%s\n" % d)
            el_smear_files = [r.TFile("/home/hep/as1604/Work/WPol/WCWPolAnalysis/controlAnalysis/%s/%s" % (d,el_file_name)) for el_file_name in el_file_names]
            # Read histograms
            el_smear_plus_hists = [f.Get(ele_dir % "sig").Get("lp_plus").Clone() for f in el_smear_files]
            el_smear_minus_hists = [f.Get(ele_dir % "sig").Get("lp_minus").Clone() for f in el_smear_files]

            # Merge the QCD/photon+jets templates into one histogram
            el_smear_qcd_plus = el_smear_plus_hists[2].Clone()
            for h in el_smear_plus_hists[3:]:
                el_smear_qcd_plus.Add(h)
            el_smear_qcd_minus = el_smear_minus_hists[2].Clone()
            for h in el_smear_minus_hists[3:]:
                el_smear_qcd_minus.Add(h)
            del el_smear_plus_hists[2:]
            del el_smear_minus_hists[2:]
            el_smear_plus_hists.append(el_smear_qcd_plus)
            el_smear_minus_hists.append(el_smear_qcd_minus)

            # Scale
            #            scale(0.35, el_smear_plus_hists, el_smear_minus_hists)
            rebin(10, el_smear_plus_hists, el_smear_minus_hists)

            # MC Data
            smear_plus_hists = [
                el_smear_plus_hists[0].Clone(),
                el_smear_plus_hists[1].Clone(),
                el_smear_plus_hists[2].Clone()
                ]
            c = r.TCanvas("brung")
            h = smear_plus_hists[0].Clone()
            for hi in smear_plus_hists[1:]:
                h.Add(hi)
            h.Draw("hist")
            c.SaveAs("brung.png")
            smear_minus_hists = [
                el_smear_minus_hists[0].Clone(),
                el_smear_minus_hists[1].Clone(),
                el_smear_minus_hists[2].Clone()
            ]
            scale(0.35, smear_plus_hists, smear_minus_hists)
            fit35_plus = run("fit35_plus_%s_%.2f_%.2f" % (d, fr[0], fr[1]),
                             fit_globals,
                             smear_plus_hists,
                             plus_templates,
                             {
                "w" : wfraction_plus,
                "qcd" : qcdfraction_plus
                },
                             action="fit",
                             lp_range = fr,
                             redice = False,
                             #                          fit_range = fr,
                             #                          constrain_qcd = True,
                             #                          qcd_mean = qcdfraction_plus,
                             #                          qcd_sigma = 0.5*qcdfraction_plus,
                             **cfg
                             )

            fit35_minus = run("fit35_minus_%s_%.2f_%.2f" % (d, fr[0], fr[1]),
                              fit_globals,
                              smear_minus_hists,
                              minus_templates,
                              {
                "w" : wfraction_minus,
                "qcd" : qcdfraction_minus
                },
                        action="fit",
                        lp_range = fr,
                        redice = False,
                        #                          fit_range = fr,
                        #                          constrain_qcd = True,
                        #                          qcd_mean = qcdfraction_plus,
                        #                          qcd_sigma = 0.5*qcdfraction_plus,
                        **cfg
                        )

            # MC Data
            smear_plus_hists = [
                el_smear_plus_hists[0].Clone(),
                el_smear_plus_hists[1].Clone(),
                el_smear_plus_hists[2].Clone()
                ]
            c = r.TCanvas("brung")
            h = smear_plus_hists[0].Clone()
            for hi in smear_plus_hists[1:]:
                h.Add(hi)
            h.Draw("hist")
            c.SaveAs("brung.png")
            smear_minus_hists = [
                el_smear_minus_hists[0].Clone(),
                el_smear_minus_hists[1].Clone(),
                el_smear_minus_hists[2].Clone()
            ]
            scale(10, smear_plus_hists, smear_minus_hists)
            #r.RooRandom.randomGenerator().SetSeed(i)
            
            # Fit el_plus (MC)
            fit100_plus = run("fit100_plus_%s_%.2f_%.2f" % (d, fr[0], fr[1]),
                         fit_globals,
                         smear_plus_hists,
                         plus_templates,
                         {
                "w" : wfraction_plus,
                "qcd" : qcdfraction_plus
                },
                         action="fit",
                         lp_range = fr,
                         redice = False,
                         **cfg
                         )
            fit100_minus = run("fit100_minus_%s_%.2f_%.2f" % (d, fr[0], fr[1]),
                               fit_globals,
                               smear_minus_hists,
                               minus_templates,
                               {
                "w" : wfraction_minus,
                "qcd" : qcdfraction_minus
                },
                               action="fit",
                               lp_range = fr,
                               redice = False,
                               **cfg
                               )

            h_plus_fLfR.Fill(fr_idx, fLminusfR(fit100_plus["result"])[0])
            h_plus_f0.Fill(fr_idx, f0(fit100_plus["result"])[0])

            fLfR_plus_syst_error = abs(fLminusfR(fit100_plus["result"])[0] - fLfR_plus_nom)
            f0_plus_syst_error = abs(f0(fit100_plus["result"])[0] - f0_plus_nom)
            err_fLfR_plus_syst[d] = fLfR_plus_syst_error
            err_f0_plus_syst[d] = f0_plus_syst_error
            
            h_plus_fLfR_err.Fill(fr_idx, fLminusfR(fit35_plus["result"])[1])
            h_plus_f0_err.Fill(fr_idx, f0(fit35_plus["result"])[1])
            err_fLfR_plus_stat[d] = fLminusfR(fit35_plus["result"])[1]
            err_f0_plus_stat[d] = f0(fit35_plus["result"])[1]
            
            fLfR_plus_total_error = math.sqrt(fLfR_plus_syst_error**2 + fLminusfR(fit35_plus["result"])[1]**2)
            if fLfR_plus_total_error > fLfR_plus_total:
                fLfR_plus_total = fLfR_plus_total_error

            f0_plus_total_error = math.sqrt(f0_plus_syst_error**2 + f0(fit35_plus["result"])[1]**2)
            if f0_plus_total_error > f0_plus_total:
                f0_plus_total = f0_plus_total_error

            h_plus_fLfR_syst.Fill(fr_idx, fLfR_plus_syst_error)
            h_plus_f0_syst.Fill(fr_idx, f0_plus_syst_error)
            h_plus_fLfR_total.Fill(fr_idx, fLfR_plus_total_error)
            h_plus_f0_total.Fill(fr_idx, f0_plus_total_error)
            
            outf.write("f0+ = %.3f +- %.3f\n" % (f0(fit100_plus["result"])[0],
                                                f0(fit35_plus["result"])[1]))
            
            outf.write("(fL-fR)+ = %.3f +- %.3f\n" % (fLminusfR(fit100_plus["result"])[0],
                                                     fLminusfR(fit35_plus["result"])[1]))
            

            h_minus_fLfR.Fill(fr_idx, fLminusfR(fit100_minus["result"])[0])
            h_minus_f0.Fill(fr_idx, f0(fit100_minus["result"])[0])
            fLfR_minus_syst_error = abs(fLminusfR(fit100_minus["result"])[0] - fLfR_minus_nom)
            f0_minus_syst_error = abs(f0(fit100_minus["result"])[0] - f0_minus_nom)

            err_fLfR_minus_syst[d] = fLfR_minus_syst_error
            err_f0_minus_syst[d] = f0_minus_syst_error
            
            h_minus_fLfR_err.Fill(fr_idx, fLminusfR(fit35_minus["result"])[1])
            h_minus_f0_err.Fill(fr_idx, f0(fit35_minus["result"])[1])
            err_fLfR_minus_stat[d] = fLminusfR(fit35_minus["result"])[1]
            err_f0_minus_stat[d] = f0(fit35_minus["result"])[1]
                  
            fLfR_minus_total_error = math.sqrt(fLfR_minus_syst_error**2 + fLminusfR(fit35_minus["result"])[1]**2)
            if fLfR_minus_total_error > fLfR_minus_total:
                fLfR_minus_total = fLfR_minus_total_error
            f0_minus_total_error = math.sqrt(f0_minus_syst_error**2 + f0(fit35_minus["result"])[1]**2)
            if f0_minus_total_error > f0_minus_total:
                f0_minus_total = f0_minus_total_error
            h_minus_fLfR_syst.Fill(fr_idx, fLfR_minus_syst_error)
            h_minus_f0_syst.Fill(fr_idx, f0_minus_syst_error)
            h_minus_fLfR_total.Fill(fr_idx, fLfR_minus_total_error)
            h_minus_f0_total.Fill(fr_idx, f0_minus_total_error)
            
            outf.write("f0- = %.3f +- %.3f\n" % (f0(fit100_minus["result"])[0],
                                                f0(fit35_minus["result"])[1]))
            
            outf.write("(fL-fR)- = %.3f +- %.3f\n" % (fLminusfR(fit100_minus["result"])[0],
                                                     fLminusfR(fit35_minus["result"])[1]))
            if d == "ZeroMC_v1":
                fLfR_plus_central = fLminusfR(fit100_plus["result"])[0]
                f0_plus_central = f0(fit100_plus["result"])[0]
                fLfR_minus_central = fLminusfR(fit100_minus["result"])[0]
                f0_minus_central = f0(fit100_minus["result"])[0]
                 

        g_plus_fLfR_total_max.SetPoint(fr_idx, fr_idx, fLfR_plus_total)
        g_plus_f0_total_max.SetPoint(fr_idx, fr_idx, f0_plus_total)

        g_minus_fLfR_total_max.SetPoint(fr_idx, fr_idx, fLfR_minus_total)
        g_minus_f0_total_max.SetPoint(fr_idx, fr_idx, f0_minus_total)

        # Fill extra graphs
        g_err_plus_fLfR_stat.SetPoint(fr_idx, fr_idx, 0)
        g_err_plus_fLfR_stat.SetPointError(fr_idx, 0, err_fLfR_plus_stat["ZeroMC_v1"]/fLfR_plus_central)
        g_err_plus_f0_stat.SetPoint(fr_idx, fr_idx, 0)
        g_err_plus_f0_stat.SetPointError(fr_idx, 0, err_f0_plus_stat["ZeroMC_v1"]/f0_plus_central)
        
        g_err_plus_fLfR_syst.SetPoint(fr_idx, fr_idx, 0)
        g_err_plus_fLfR_syst.SetPointError(fr_idx, 0, 0,  err_fLfR_plus_syst["jec_minus5pc"]/fLfR_plus_central,
                                           err_fLfR_plus_syst["jec_plus5pc"]/fLfR_plus_central)
        g_err_plus_f0_syst.SetPoint(fr_idx, fr_idx, 0)
        g_err_plus_f0_syst.SetPointError(fr_idx, 0, 0,
                                         err_f0_plus_syst["jec_minus5pc"]/f0_plus_central,
                                         err_f0_plus_syst["jec_plus5pc"]/f0_plus_central)

        g_err_plus_fLfR_total.SetPoint(fr_idx, fr_idx, 0)
        g_err_plus_fLfR_total.SetPointError(fr_idx, 0, 0,
                                            math.sqrt(err_fLfR_plus_stat["ZeroMC_v1"]**2 + err_fLfR_plus_syst["jec_minus5pc"]**2)/fLfR_plus_central,
                                            math.sqrt(err_fLfR_plus_stat["ZeroMC_v1"]**2 + err_fLfR_plus_syst["jec_plus5pc"]**2)/fLfR_plus_central)
        g_err_plus_f0_total.SetPoint(fr_idx, fr_idx, 0)
        g_err_plus_f0_total.SetPointError(fr_idx, 0, 0,  
                                         math.sqrt(err_f0_plus_stat["ZeroMC_v1"]**2 + err_f0_plus_syst["jec_minus5pc"]**2)/f0_plus_central,
                                         math.sqrt(err_f0_plus_stat["ZeroMC_v1"]**2 + err_f0_plus_syst["jec_plus5pc"]**2)/f0_plus_central)
        print err_f0_plus_stat["ZeroMC_v1"]
        print err_f0_plus_syst["jec_plus5pc"]
        print math.sqrt(err_f0_plus_stat["ZeroMC_v1"]**2 + err_f0_plus_syst["jec_plus5pc"]**2)
#        if quit:
#            sys.exit(1)
        quit = True
        g_err_minus_fLfR_stat.SetPoint(fr_idx, fr_idx, 0)
        g_err_minus_fLfR_stat.SetPointError(fr_idx, 0, err_fLfR_minus_stat["ZeroMC_v1"]/fLfR_minus_central)
        g_err_minus_f0_stat.SetPoint(fr_idx, fr_idx, 0)
        g_err_minus_f0_stat.SetPointError(fr_idx, 0, err_f0_minus_stat["ZeroMC_v1"]/f0_minus_central)
        
        g_err_minus_fLfR_syst.SetPoint(fr_idx, fr_idx, 0)
        g_err_minus_fLfR_syst.SetPointError(fr_idx, 0, 0,  err_fLfR_minus_syst["jec_minus5pc"]/fLfR_minus_central,
                                            err_fLfR_minus_syst["jec_plus5pc"]/fLfR_minus_central)
        g_err_minus_f0_syst.SetPoint(fr_idx, fr_idx, 0)
        g_err_minus_f0_syst.SetPointError(fr_idx, 0, 0,  err_f0_minus_syst["jec_minus5pc"]/f0_minus_central,
                                          err_f0_minus_syst["jec_plus5pc"]/f0_minus_central)
        
        g_err_minus_fLfR_total.SetPoint(fr_idx, fr_idx, 0)
        g_err_minus_fLfR_total.SetPointError(fr_idx, 0, 0,
                                            math.sqrt(err_fLfR_minus_stat["ZeroMC_v1"]**2 + err_fLfR_minus_syst["jec_minus5pc"]**2)/fLfR_minus_central,
                                            math.sqrt(err_fLfR_minus_stat["ZeroMC_v1"]**2 + err_fLfR_minus_syst["jec_plus5pc"]**2)/fLfR_minus_central)
        g_err_minus_f0_total.SetPoint(fr_idx, fr_idx, 0)
        g_err_minus_f0_total.SetPointError(fr_idx, 0, 0,
                                         math.sqrt(err_f0_minus_stat["ZeroMC_v1"]**2 + err_f0_minus_syst["jec_minus5pc"]**2)/f0_minus_central,
                                         math.sqrt(err_f0_minus_stat["ZeroMC_v1"]**2 + err_f0_minus_syst["jec_plus5pc"]**2)/f0_minus_central)
                                                                                        
        
    rf.cd()
    SaveGraph(g_err_plus_fLfR_total, "g_err_plus_fLfR_total")
    SaveGraph(g_err_plus_f0_total, "g_err_plus_f0_total")
    SaveGraph(g_err_plus_fLfR_stat, "g_err_plus_fLfR_stat")
    SaveGraph(g_err_plus_f0_stat, "g_err_plus_f0_stat")
    SaveGraph(g_err_plus_fLfR_syst, "g_err_plus_fLfR_syst")
    SaveGraph(g_err_plus_f0_syst, "g_err_plus_f0_syst")

    SaveGraph(g_err_minus_fLfR_total, "g_err_minus_fLfR_total")
    SaveGraph(g_err_minus_f0_total, "g_err_minus_f0_total")
    SaveGraph(g_err_minus_fLfR_stat, "g_err_minus_fLfR_stat")
    SaveGraph(g_err_minus_f0_stat, "g_err_minus_f0_stat")
    SaveGraph(g_err_minus_fLfR_syst, "g_err_minus_fLfR_syst")
    SaveGraph(g_err_minus_f0_syst, "g_err_minus_f0_syst")

    SaveGraph(g_plus_fLfR_total_max, "g_plus_fLfR_total_error")
    SaveGraph(g_plus_f0_total_max, "g_plus_f0_total_error")
    
    SaveGraph(g_minus_fLfR_total_max, "g_minus_fLfR_total_error")
    SaveGraph(g_minus_f0_total_max, "g_minus_f0_total_error")
    

    rf.Write()

