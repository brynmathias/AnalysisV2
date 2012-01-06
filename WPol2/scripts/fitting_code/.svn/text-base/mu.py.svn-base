#!/usr/bin/env python
import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *

pulls = True

if __name__ == "__main__":
    mu_path = "./ROOTFiles/"
    mu_file_names = ["RecoRoutines_W-selection_realdata.root",
                     "RecoRoutines_W-selection_WJets_madgraph_June2010.root",
                     "RecoRoutines_W-selection_ZJets_madgraph_June2010.root"]

    # Open files
    mu_files = [r.TFile(mu_path + mu_file_name) for mu_file_name in mu_file_names]

    # Read histograms
    mu_plus_hists = [f.Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFPlus") for f in mu_files]
    mu_minus_hists = [f.Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFMinus") for f in mu_files]

    total_ewk_plus = mu_plus_hists[1].Clone()
    total_ewk_plus.Add(mu_plus_hists[2])
    wfraction_plus = (intr(mu_plus_hists[1], *default_cfg["lp_range"])/
                      intr(total_ewk_plus, *default_cfg["lp_range"]))
    wfraction_plus = mu_plus_hists[1].Integral()/total_ewk_plus.Integral()

    total_ewk_minus = mu_minus_hists[1].Clone()
    total_ewk_minus.Add(mu_minus_hists[2])
    wfraction_minus = (intr(mu_minus_hists[1], *default_cfg["lp_range"])/
                      intr(total_ewk_minus, *default_cfg["lp_range"]))
    print wfraction_plus

    # Read W templates
    mu_plus_wtemplates = [mu_files[1].Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFPlus_%s" % s)
                          for s in ["LH", "RH", "LO"]]
    mu_minus_wtemplates = [mu_files[1].Get("RECO_PolPlots_50toinf").Get("RECO_ICVarPFMinus_%s" % s)
                          for s in ["LH", "RH", "LO"]]

    # Real data
    real_plus_hists = [mu_plus_hists[0].Clone()]
    real_minus_hists = [mu_minus_hists[0].Clone()]

    # MC Data
    mc_plus_hists = [mu_plus_hists[1].Clone(), mu_plus_hists[2].Clone()]
    mc_minus_hists = [mu_minus_hists[1].Clone(), mu_minus_hists[2].Clone()]

    # Scale
    scale(100, mc_plus_hists, mc_minus_hists)

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

    # Rebin
    rebin(10, real_plus_hists, real_minus_hists, mc_plus_hists, mc_minus_hists,
          plus_templates, minus_templates)

    # Global parameters in fits
    fit_globals = {
        # Set up fit parameters
        "lp" : r.RooRealVar("lp", "LP Variable", *default_cfg["lp_range"]),

        # Set up fit variables
        "f1" :  r.RooRealVar("f1", "f1", 0., 1.),
        "f2" : r.RooRealVar("f2", "f2", 0., 1.)
        }
    fit_globals["lp"].setRange("lp_range", -0.4, 1.6)

    # # Fit mu_plus (Data)
    total_ewk_plus = mu_plus_hists[1].Clone()
    total_ewk_plus.Add(mu_plus_hists[2])

    # fit = run("mu_plus_data",
    #           fit_globals,
    #           real_plus_hists,
    #           r.RooW,
    #           plus_templates,
    #            {"w" : (intr(mu_plus_hists[1], *default_cfg["lp_range"])/
    #                          intr(total_ewk_plus, *default_cfg["lp_range"]))}
    #           )
    # plot_fit(fit_globals, fit)

    # if pulls:
    #     pulls = run("mu_plus_data_pulls",
    #                 fit_globals,
    #                 real_plus_hists,
    #                 plus_templates,
    #                 {"w" : (intr(mu_plus_hists[1], *default_cfg["lp_range"])/
    #                         intr(total_ewk_plus, *default_cfg["lp_range"]))},
    #                 action = "pulls",
    #                 N_experiments = 100
    #                 )
    #     plot_pulls(fit_globals, pulls)

    # # Fit mu_minus (Data)
    total_ewk_minus = mu_minus_hists[1].Clone()
    total_ewk_minus.Add(mu_minus_hists[2])

    # fit = run("mu_minus_data",
    #           fit_globals,
    #           real_minus_hists,
    #           r.RooW,
    #           minus_templates,
    #           {"w" : (intr(mu_minus_hists[1], *default_cfg["lp_range"])/
    #                         total_ewk_minus.Integral())}
    #           )
    # plot_fit(fit_globals, fit)

    # if pulls:
    #     pulls = run("mu_minus_data_pulls",
    #                 fit_globals,
    #                 real_minus_hists,
    #                 r.RooW,
    #                 minus_templates,
    #                 {"w" : (intr(mu_minus_hists[1], *default_cfg["lp_range"])/
    #                         total_ewk_minus.Integral())},
    #                 action = "pulls",
    #                 N_experiments = 500
    #                 )
    #     plot_pulls(fit_globals, pulls)

    # Fit mu_plus (MC)
    fit = run("mu_plus_mc",
              fit_globals,
              mc_plus_hists,
              plus_templates,
              {"w" : wfraction_plus},
              action = "fit_minuit",
              redice = True
              )
    plot_fit(fit_globals, fit)

    if pulls:
        pulls = run("mu_plus_mc_pulls",
                    fit_globals,
                    mc_plus_hists,
                    plus_templates,
                    {"w" : wfraction_plus},
                    action = "pulls",
                    N_experiments = 1000
                    )
        plot_pulls(fit_globals, pulls)

    # Fit mu_minus (MC)

    fit = run("mu_minus_mc",
              fit_globals,
              mc_minus_hists,
              minus_templates,
              {"w" : (intr(mu_minus_hists[1], *default_cfg["lp_range"])/
                            total_ewk_minus.Integral())}
              )
    plot_fit(fit_globals, fit)

    if pulls:
        pulls = run("mu_minus_mc_pulls",
                    fit_globals,
                    mc_minus_hists,
                    minus_templates,
                    {"w" : (intr(mu_minus_hists[1], *default_cfg["lp_range"])/
                            total_ewk_minus.Integral())},
                    action = "pulls",
                    N_experiments = 500,
                    )
        plot_pulls(fit_globals, pulls)
