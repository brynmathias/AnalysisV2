#!/usr/bin/env python
""" Module for doing LP fits using RooFit for the W Polarisation measurement """

import ROOT as r
from utils import *

setup_root()

# Expose these
RooW_TH1F = r.RooW_TH1F
RooW_TH1D = r.RooW_TH1D

# These are default configuration options They can be overridden by passing
# keywords to the run function:
#
# run(..., lp_range = (-0.5, 1.6))
#
# You can also make a dictionary of configuration options:
#
# my_cfg = default_cfg.copy()
# my_cfg["lp_range"] = (-0.5, 1.6)
# run(..., **my_cfg)
#
# The ** tells Python that you want to pass all the values in your dictionary as
# named parameters to your function. These will override the defaults

default_cfg = {
    "lp_range" : (-0.4, 1.6),
    "redice" : False,
    "f1_init" : 0.556,
    "f2_init" : 0.555,
    "output_path" : "./Plots",
    "use_minos" : r.kFALSE,
    "sumw2" : r.kFALSE,
    "model_class" : r.RooW_TH1F,
    "nominal_values" : {}
    }

class ConfigError:
    "Error class for fit configuration errors"
    def __init__(self, s):
        self.msg = s
    def __str__(self):
        return self.msg

###############################################################
# Functions for extracting fit parameters and correct errors
###############################################################
def fL(fr):
    """Returns tuple (fL fitted, fL fit error)"""
    f1 = fr.floatParsFinal().find("f1")
    return (f1.getVal(), f1.getError())

def fR(fr):
    """Returns tuple (fR fitted, fR propagated fit error)"""
    f1 = fr.floatParsFinal().find("f1")
    f2 = fr.floatParsFinal().find("f2")
    formula = r.RooFormulaVar("f_{R}",
                              "f_{R}",
                              "(1-f1)*f2",
                              r.RooArgList(f1, f2))
    return (formula.getVal(), formula.getPropagatedError(fr))

def f0(fr):
    """Returns tuple (f0, propagated fit error on f0)"""
    f1 = fr.floatParsFinal().find("f1")
    f2 = fr.floatParsFinal().find("f2")
    formula = r.RooFormulaVar("f_{0}",
                              "f_{0}",
                              "(1-f1)*(1-f2)",
                              r.RooArgList(f1, f2))
    return (formula.getVal(), formula.getPropagatedError(fr))

def fLminusfR(fr):
    """Returns tuple ( (fL-fR), propagated fit error on (fL-fR) )"""
    f1 = fr.floatParsFinal().find("f1")
    f2 = fr.floatParsFinal().find("f2")
    formula = r.RooFormulaVar("f_{L}-f_{R}",
                              "f_{L}-f_{R}",
                              "f1 - (1-f1)*f2",
                              r.RooArgList(f1, f2))
    return (formula.getVal(), formula.getPropagatedError(fr))

def fLplusfR(fr):
    """Returns tuple ( (fL-fR), propagated fit error on (fL-fR) )"""
    f1 = fr.floatParsFinal().find("f1")
    f2 = fr.floatParsFinal().find("f2")
    formula = r.RooFormulaVar("f_{L}+f_{R}",
                              "f_{L}+f_{R}",
                              "f1 + (1-f1)*f2",
                              r.RooArgList(f1, f2))
    return (formula.getVal(), formula.getPropagatedError(fr))


nom_values_plus = {
    "f_{L}" : 0.55423,
    "f_{R}" : 0.2270,
    "f_{0}" : 0.208,
    }

nom_values_minus = {
    "f_{L}" : 0.5214,
    "f_{R}" : 0.2707,
    "f_{0}" : 0.212
    }
############################################################
# run
############################################################
def run(
    name,                   # Unique name for this fit
    fit_globals,            # Fit global variables (for simultaneous fits)
    data_hists,             # List of TH1Ds containing LP distributions for data
    templates,              # List of templates to fit
    template_norms,         # Initial normalisations for templates
    action = 'fit',         # Action: fit/pulls/fit_minuit
    **cfg                   # Extra configuration options (see comment above)
    ):
    # Read in configuration options and override defaults if requested
    cfg_base = default_cfg.copy()
    cfg_base.update(cfg)
    cfg = cfg_base

    # Get the global variables passed in. These need to be set up externally to
    # allow for simultaneously fits.
    lp = fit_globals["lp"]
    lp_as = r.RooArgSet(lp)
    lp_al = r.RooArgList(lp)
    f1 = fit_globals["f1"]
    f2 = fit_globals["f2"]

    # Reset the variables
    f1.setVal(cfg["f1_init"])
    f2.setVal(cfg["f2_init"])
    f1.setError(0)
    f2.setError(0)

    # Set up variable for W template
    if "ewk" in templates:
        if not "w" in template_norms:
            raise ConfigError("No template/normalisation specified for W")
    wfrac = 1
    if "w" in template_norms:
        wfrac = template_norms["w"]
    print "wfrac = %.2f" % wfrac
    f_w = r.RooRealVar("f_w_%s" % name,
                       "f_w_%s" % name,
                       wfrac)
    # Set up W helicity PDF
    sig_model = cfg["model_class"](
        "sig_%s" % name,
        "sig_%s" % name,
        lp,
        f1,
        f2,
        templates["lh"],
        templates["rh"],
        templates["lo"])

    # If we are fitting for QCD, set up variable
    if "qcd" in templates:
        if  not "qcd" in template_norms:
            raise ConfigError("Have requested QCD fit but no QCD template/normalisation supplied")
        f_qcd = r.RooRealVar("f_qcd_%s" % name,
                             "f_qcd_%s" % name,
                             template_norms["qcd"],
                             0., 1.
                             )

    # Make templates and corresponding PDFs
    template_data_hists = {}
    template_pdfs = {}
    for tmp_name, tmp_hist in templates.iteritems():
        template_data_hists[tmp_name] = r.RooDataHist("%s_%s" % (tmp_name, name),
                                                      "%s_%s" % (tmp_name, name),
                                                      lp_al,
                                                      tmp_hist)
        template_pdfs[tmp_name] = r.RooHistPdf("%s_pdf_%s" % (tmp_name, name),
                                               "%s_pdf_%s" % (tmp_name, name),
                                               lp_as,
                                               template_data_hists[tmp_name])

    data_stats = [int(intr(data_hists[0], *cfg["lp_range"]))]
    for d in data_hists[1:]:
        data_stats.append(int(intr(d, *cfg["lp_range"])))

    # Get our data together
    if cfg["redice"]:
        # Convert the data histograms into a list of RooDataHists
        roo_data_list = []
        roo_pdf_list = []
        roo_redice_stats = []
        for idx, data_hist in enumerate(data_hists):
            roo_data_list.append(r.RooDataHist("data_%d_%s" % (idx, name),
                                               "data_%d_%s" % (idx, name),
                                                lp_al,
                                                data_hists[idx]))
            roo_pdf_list.append(r.RooHistPdf("pdf_%d_%s" % (idx, name),
                                             "pdf_%d_%s" % (idx, name),
                                             lp_as,
                                             roo_data_list[idx]))

        # Generate rediced data
        smeared_data = roo_pdf_list[0].generate(lp_as,
                                                r.RooFit.NumEvents(data_stats[0]),
                                                r.RooFit.Extended())
        roo_redice_stats.append(smeared_data.numEntries())
        idx = 1
        for roo_data in roo_pdf_list[1:]:
            gen = roo_data.generate(lp_as,
                                    r.RooFit.NumEvents(data_stats[idx])#,
                                    #r.RooFit.Extended()
                                    )
            roo_redice_stats.append(gen.numEntries())
            smeared_data.append(gen)
            idx+=1
        print "Rediced!!!"
        roo_data = smeared_data
    else:
        # No redicing, just sum the supplied histograms together
        # For data plots this will just be a single histogram
        data = data_hists[0].Clone()
        print "data = %.5f" % data.Integral()
        for d in data_hists[1:]:
            data.Add(d)

        # Convert to RooDataHist
        roo_data = r.RooDataHist("data_%s" % name,
                                 "data_%s" % name,
                                 lp_al,
                                 data)

    # If we are using an EWK template, set it up as:
    # EWK(x) = f_w * {f_L h_L(x) + f_R h_R(x) + (1 - f_L - f_R) h_0(x)} + (1 - f_W)EWKBG(x)
    # Otherwise do a signal only fit
    if not "ewk" in template_pdfs:
        ewk_pdf = sig_model
    else:
        pdf_al = r.RooArgList(sig_model, template_pdfs["ewk"])
        fw_al = r.RooArgList(f_w)
        ewk_pdf = r.RooAddPdf("ewk_w_pdf_%s" % name,
                              "ewk_w_pdf_%s" % name,
                              pdf_al,
                              fw_al)

    # If we are fitting for QCD too, the model should be:
    # Model = f_QCD QCD(x) + (1-f_QCD) EWK(x)
    # Otherwise:
    # Model = EWK(x)
    if "qcd" in template_pdfs:
        print "f_qcd = %.3f" % f_qcd.getVal()
        if cfg["redice"] and len(roo_redice_stats) > 2 and not action == "pulls":
            f_qcd.setVal(roo_redice_stats[2]/float(sum(roo_redice_stats)))
        print "f_qcd = %.3f" % f_qcd.getVal()
        f_qcd_nom = f_qcd.getVal()
        if "qcd_function" in cfg:
            print "Using function for QCD"
            pdf_al = r.RooArgList(cfg["qcd_function"], ewk_pdf)
        else:
            pdf_al = r.RooArgList(template_pdfs["qcd"], ewk_pdf)
        qcd_al = r.RooArgList(f_qcd)

        qcd_pdf = r.RooAddPdf("qcd_ewk_pdf_%s" % name,
                              "qcd_ewk_pdf_%s" % name,
                              pdf_al,
                              qcd_al)
        model = qcd_pdf
    else:
        model = ewk_pdf

    ret_dict = {}
    opts = [r.RooFit.Save()]
    # If requested, apply Gaussian constraint to f_QCD
    if "constrain_qcd" in cfg and cfg["constrain_qcd"]:
        if not "qcd_mean" in cfg or not "qcd_sigma" in cfg:
            raise ConfigError("Specified constrain_qcd but no qcd_mean or qcd_sigma provided")
        qcd_const = r.RooGaussian("qcd_const_%s" % name,
                                  "qcd_const_%s" % name,
                                  f_qcd,
                                  r.RooFit.RooConst(cfg["qcd_mean"]),
                                  r.RooFit.RooConst(cfg["qcd_sigma"]))
        model = r.RooProdPdf("model_%s" % name,
                             "model_%s" % name,
                             r.RooArgList(qcd_pdf, qcd_const))
        ret_dict["qcd_const"] = qcd_const
        qcd_as = r.RooArgSet(f_qcd)
        opts.append(r.RooFit.Constrain(qcd_as))
    # Build fit options

    if "silence" in cfg:
        opts.append(r.RooFit.Verbose(r.kFALSE))
    if "constrain_qcd" in cfg and cfg["constrain_qcd"] and not action == "pulls":
        opts.append(r.RooFit.Constrain(r.RooArgSet(f_qcd)))
    if "use_minos" in cfg:
        opts.append(r.RooFit.Minos(cfg["use_minos"]))
    if "sumw2" in cfg:
        opts.append(r.RooFit.SumW2Error(cfg["sumw2"]))
    if "fit_range" in cfg:
        opts.append(r.RooFit.Range(*cfg["fit_range"]))
    # Return dictionary with various parameters

    ret_dict.update(fit_globals)
    ret_dict["sig_model"] = sig_model
    ret_dict["ewk_pdf"] = ewk_pdf
    ret_dict["model"] = model
    ret_dict["data"] = roo_data
    ret_dict["data_stats"] = data_stats
    ret_dict["name"] = name
    ret_dict["template_pdfs"] = template_pdfs
    ret_dict["f_w"] = f_w
    ret_dict["data_hists"] = data_hists
    if "ewk" in template_pdfs:
        ret_dict["ewk_w_pdf"] = template_pdfs["ewk"]
    # If we have qcd in the fit, store these too:
    if "qcd" in templates:
        ret_dict["f_qcd"] = f_qcd
        ret_dict["f_qcd_nom"] = f_qcd_nom
        ret_dict["qcd_ewk_pdf"] = qcd_pdf
        ret_dict["qcd_pdf"] = template_pdfs["qcd"]
    if "qcd_function" in cfg:
        ret_dict["qcd_function"] = cfg["qcd_function"]
    ret_dict["template_data_hists"] = template_data_hists
    ret_dict.update(templates)

    # Perform requested action
    if action == "fit":
        result = model.fitTo(roo_data, *opts)
        if "fit_qcd" in cfg:
            ret_dict["f_ewk_bg"] = (1-f_qcd.getVal())*(1-f_w.getVal())
        else:
            ret_dict["f_ewk_bg"] = (1-f_w.getVal())
        ret_dict["result"] = result
    elif action == "pulls":
        if not "N_experiments" in cfg:
            raise ConfigError("pulls requested but did not supply N_experiments")
        opts.append(r.RooFit.Save())
        if "constrain_qcd" in cfg and cfg["constrain_qcd"]:
            fitmodel = qcd_pdf
        else:
            fitmodel = model
        mcstudy = r.RooMCStudy(model, lp_as, r.RooFit.FitModel(fitmodel),
                               r.RooFit.Silence(), r.RooFit.Binned(),
                               r.RooFit.FitOptions(*opts))
        print sum(data_stats)
        mcstudy.generateAndFit(cfg["N_experiments"], sum(data_stats), r.kTRUE)
        ret_dict["mcstudy"] = mcstudy
    elif action == "simultaneous":
        ret_dict["opts"] = opts
        return ret_dict
#        for i in range(20):
#            fr = mcstudy.fitParams(i)
#            f1 = fr.find("f1")
#            print "fL = %.3f +- %.3f" % (f1.getVal(), f1.getError())
#        print "--"
    elif action == "fit_minuit":
        # Minuit option. Should give the same results as 'fit' option but we should
        # check.
        nll = r.RooNLLVar("%s_nll" % name,
                          "%s_nll" % name,
                          model,
                          roo_data, *opts)
        m = r.RooMinuit(nll)
        m.optimizeConst(r.kTRUE)
        m.setProfile(r.kTRUE)
        m.setVerbose(r.kFALSE)
        m.migrad()
        m.hesse()
        m.setVerbose(r.kFALSE)
        m.minos()
        ret_dict["minuit"] = m
        ret_dict["nll"] = nll
        if "fit_qcd" in cfg:
            ret_dict["f_ewk_bg"] = (1-f_qcd.getVal())*(1-f_w.getVal())
        else:
            ret_dict["f_ewk_bg"] = (1-f_w.getVal())
        ret_dict["result"] = m.save()

    return ret_dict


def qcd_double_gaussian(lp, alpha, mu1, sigma1, mu2, sigma2):
    f = r.RooRealVar("f", "f", alpha)
    gauss1 = r.RooGaussian("gauss1", "gauss1", lp, r.RooFit.RooConst(mu1), r.RooFit.RooConst(sigma1))
    gauss2 = r.RooGaussian("gauss2", "gauss2", lp, r.RooFit.RooConst(mu2), r.RooFit.RooConst(sigma2))
    model = r.RooAddPdf("model", "model", r.RooArgList(gauss1, gauss2), r.RooArgList(f))
    return {"gauss1" : gauss1,
            "gauss2" : gauss2,
            "alpha" : f,
            "model" : model}

def qcd_single_gaussian(lp, mu, sigma):
    return {"model":r.RooGaussian("gauss", "gauss", lp, r.RooFit.RooConst(mu), r.RooFit.RooConst(sigma))}

def sim_fit(name, fit_globals, opts_from, **args):
    sample = r.RooCategory("%s_sample" % name,
                           "%s_sample" % name)
    items = {}
    for k, v in args.iteritems():
        sample.defineType(k)
        items[k] = v
    dh_args = [r.RooFit.Index(sample)]
    data_hists = []
    for k, v in args.iteritems():
        data_hist = v["data_hists"][0].Clone()
        for h in v["data_hists"][1:]:
            data_hist.Add(h)
        dh_args.append(r.RooFit.Import(k, data_hist))
        data_hists.append(data_hist)
    lp_al = r.RooArgList(fit_globals["lp"])
    data = r.RooDataHist("%s_data" % name,
                         "%s_data" % name,
                         lp_al,
                         *dh_args)
    sim_pdf = r.RooSimultaneous("sim_pdf",
                                "simultaneous pdf",
                                sample)
    for k, v in items.iteritems():
        sim_pdf.addPdf(v["model"], k)
    ll = r.RooLinkedList()
    for o in items[opts_from]["opts"]:
        ll.Add(o)
    opts = [r.RooFit.Save()]

    nll = None
    if False:
        result = sim_pdf.fitTo(data, *items[opts_from]["opts"])
    else:
        nll = r.RooNLLVar("%s_nll" % name,
                          "%s_nll" % name,
                          sim_pdf,
                          data,
                          *items[opts_from]["opts"])
        m = r.RooMinuit(nll)
        m.optimizeConst(r.kTRUE)
        m.setProfile(r.kTRUE)
        m.setVerbose(r.kFALSE)
        m.migrad()
        m.hesse()
        m.setVerbose(r.kFALSE)
        m.minos()
        result = m.save()
    ret_dict = {
        "minuit" : m,
        "nll" : nll,
        "sample" : sample,
        "items" : items,
        "dh_args" : dh_args,
        "lp_al" : lp_al,
        "data" : data,
        "sim_pdf" : sim_pdf,
        "result" : result
        }
    return ret_dict
