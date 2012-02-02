#!/usr/bin/env python
import ROOT as r
from wpolfitter.utils import *
from wpolfitter.fit import *
from wpolfitter.plot import *

pulls = False
cfg = default_cfg.copy()
cfg["model_class"] = RooW_TH1D
#cfg["redice"] = True
#cfg["fit_range"] = (0.3 , 1.2)

if __name__ == "__main__":
    el_path = "./ROOTFiles/"
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
    el_plus_wtemplates = [el_files[1].Get("lp_postmht_met15_mt50_sig").Get("lp_plus_%s" % s)
                          for s in ["lh", "rh", "lo"]]
    el_minus_wtemplates = [el_files[1].Get("lp_postmht_met15_mt50_sig").Get("lp_minus_%s" % s)
                          for s in ["lh", "rh", "lo"]]

    # Real data
    real_plus_hists = [el_plus_hists[0].Clone()]
    real_minus_hists = [el_minus_hists[0].Clone()]

    # MC Data
    mc_plus_hists = [el_plus_hists[1].Clone(),
#                     el_plus_hists[2].Clone(),
#                     el_plus_hists[3].Clone()
                     ]
    mc_minus_hists = [
        el_minus_hists[1].Clone(),
 #       el_minus_hists[2].Clone(),
 #       el_minus_hists[3].Clone()
        ]

    # Scale
#    scale(1, mc_plus_hists, mc_minus_hists)

    # Set up signal/bg/helicity templates
    plus_templates = {
        "w" : el_plus_hists[1],
#        "qcd" : el_plus_hists[3],
#        "ewk" : el_plus_hists[2],
        "lh" : el_plus_wtemplates[0],
        "rh" : el_plus_wtemplates[1],
        "lo" : el_plus_wtemplates[2]
        }
    minus_templates = {
        "w" : el_minus_hists[1],
#        "qcd" : el_minus_hists[3],
#        "ewk" : el_minus_hists[2],
        "lh" : el_minus_wtemplates[0],
        "rh" : el_minus_wtemplates[1],
        "lo" : el_minus_wtemplates[2]
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
    #    fit_globals["lp"].setRange("frange", 1, 1.6)

    # # Fit el_plus (Data)
    # fit = run("el_plus_data",
    #           fit_globals,
    #           real_plus_hists,
    #           plus_templates,
    #            {"w" : wfraction_plus,
    #             "qcd" : qcdfraction_plus},
    #           **cfg
    #           )
    # plot_fit(fit_globals, fit)

    # if pulls:
    #     pulls = run("el_plus_data_pulls",
    #                 fit_globals,
    #                 real_plus_hists,
    #                 plus_templates,
    #                 {"w" : wfraction_plus, "qcd" : qcdfraction_plus},
    #                 action = "pulls",
    #                 N_experiments = 500,
    #                 **cfg
    #                 )
    #     plot_pulls(fit_globals, pulls)

    # # # Fit el_minus (Data)
    # total_ewk_minus = el_minus_hists[1].Clone()
    # total_ewk_minus.Add(el_minus_hists[2])

    # fit = run("el_minus_data",
    #           fit_globals,
    #           real_minus_hists,
    #           minus_templates,
    #           {"w" : (intr(el_minus_hists[1], *default_cfg["lp_range"])/
    #                         total_ewk_minus.Integral())},
    #           **cfg
    #           )
    # plot_fit(fit_globals, fit)

    # selected templates
    qcd_func = qcd_double_gaussian(fit_globals["lp"],
                                   0.797,
                                   1.222,
                                   0.100,
                                   1.108,
                                   0.228)
    # qcd_func = qcd_double_gaussian(fit_globals["lp"],
    #                                0.449,
    #                                1.248,
    #                                0.100,
    #                                1.161,
    #                                0.180)
    # Fit el_plus (MC)
    fit = run("el_plus_mc",
              fit_globals,
              mc_plus_hists,
              plus_templates,
              {"w" : wfraction_plus,
               "qcd" : qcdfraction_plus
               },
              action="fit",
#              qcd_function = qcd_func["model"],
              **cfg
              )
    plot_fit(fit_globals, fit)
    print "fL = %.3f +- %.3f" % (fL(fit["result"])[0],
                                 fL(fit["result"])[1])
    print "fR = %.3f +- %.3f" % (fR(fit["result"])[0],
                                 fR(fit["result"])[1])
    print "f0 = %.3f +- %.3f" % (f0(fit["result"])[0],
                                 f0(fit["result"])[1])

    if pulls:
        pulls = run("el_plus_mc_pulls",
                    fit_globals,
                    mc_plus_hists,
                    plus_templates,
                    {"w" : wfraction_plus,
                     "qcd" : qcdfraction_plus},
                    action = "pulls",
#                    qcd_function = qcd_func["model"],
                    N_experiments = 1000,
                    **cfg
                    )
    #     lp_as = r.RooArgSet(fit_globals["lp"])
#         mcstudy = r.RooMCStudy(pulls["model"],
#                                lp_as,
#                                r.RooFit.FitModel(pulls["model"]),
#                                r.RooFit.Silence(),
#                                r.RooFit.Binned(),
#                                r.RooFit.FitOptions(r.RooFit.Save()))
#         mcstudy.generateAndFit(20,
#                                sum(pulls["data_stats"]),
#                                r.kTRUE)
# #        ret_dict["mcstudy"] = mcstudy
#         for i in range(20):
#             fr = mcstudy.fitParams(i)
#             f1 = fr.find("f1")
#             print "fL = %.3f +- %.3f" % (f1.getVal(), f1.getError())

        plot_pulls(fit_globals, pulls)

    # # Fit el_minus (MC)

    fit = run("el_minus_mc",
              fit_globals,
              mc_minus_hists,
              minus_templates,
              {"w" : wfraction_minus,
               "qcd" : qcdfraction_minus},
              qcd_function = qcd_func["model"],
              **cfg
              )
    plot_fit(fit_globals, fit)
    print "fL = %.3f +- %.3f" % (fL(fit["result"])[0],
                                 fL(fit["result"])[1])
    print "fR = %.3f +- %.3f" % (fR(fit["result"])[0],
                                 fR(fit["result"])[1])
    print "f0 = %.3f +- %.3f" % (f0(fit["result"])[0],
                                 f0(fit["result"])[1])

    # if pulls:
    #     pulls = run("el_minus_mc_pulls",
    #                 fit_globals,
    #                 mc_minus_hists,
    #                 minus_templates,
    #                 {"w" : wfraction_plus,
    #                  "qcd" : qcdfraction_plus},
    #                 model_class = r.RooW_TH1D,
    #                 action = "pulls",
    #                 N_experiments = 500,
    #                 **cfg
    #                 )
    #     plot_pulls(fit_globals, pulls)
