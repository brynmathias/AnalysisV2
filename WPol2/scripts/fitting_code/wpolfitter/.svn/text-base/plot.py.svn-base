import ROOT as r
from fit import *

###########################################################
# Plotting
###########################################################
def plot_fit(
    fit_globals,
    fit_dict,
    **cfg
    ):
    cfg_base = default_cfg.copy()
    cfg_base.update(cfg)
    cfg = cfg_base

    # Set up drawing
    c = r.TCanvas("test")
    frm = fit_globals["lp"].frame()

    fit_dict["result"].Print("v")
    # Plot data
    fit_dict["data"].plotOn(frm)#, r.RooFit.Binning(20))

    frm.SetMaximum(2*frm.GetMaximum())

    #print fit_dict["model"]
    fit_dict["model"].plotOn(frm)

    # f2_p = r.RooFormulaVar("f2_p", "(1-f1)*f2",
    #                        r.RooArgList(fit_globals["f1"], fit_globals["f2"]))
    # made_up_pdf = r.RooAddPdf("templates", "component 1",
    #                           r.RooArgList(fit_dict["template_pdfs"]["lh"],
    #                                        fit_dict["template_pdfs"]["rh"],
    #                                        fit_dict["template_pdfs"]["lo"]),
    #                           r.RooArgList(fit_globals["f1"], f2_p))
    #made_up_pdf.plotOn(frm)
    #fas = r.RooArgSet(fit_dict["template_pdfs"]["lh"])
    # made_up_pdf.plotOn(frm,
    #                    r.RooFit.LineColor(r.kYellow),
    #                    r.RooFit.Components(fas)
    #                    )
    #fas = r.RooArgSet(fit_dict["template_pdfs"]["rh"])
    # made_up_pdf.plotOn(frm,
    #                    r.RooFit.LineColor(r.kYellow),
    #                    r.RooFit.Components(fas))

    data_stats = sum(fit_dict["data_stats"])

    allmc = fit_dict["lh"].Integral() + fit_dict["rh"].Integral() + fit_dict["lo"].Integral()
    # if "ewk" in fit_dict:
    #     allmc += fit_dict["ewk"].Integral()

    # if "qcd" in fit_dict:
    #     allmc += fit_dict["qcd"].Integral()
    print "allmc = %.2f" % allmc
    print "lh = %.2f" % fit_dict["lh"].Integral()
    print "rh = %.2f" % fit_dict["rh"].Integral()
    print "lo =%.2f" % fit_dict["lo"].Integral()
    scale_fL = fit_dict["lh"].Integral()/allmc
    scale_fR = fit_dict["rh"].Integral()/allmc
    scale_f0 = fit_dict["lo"].Integral()/allmc

 #   allmc = intr(fit_dict["lh"], *cfg["lp_range"]) + intr(fit_dict["rh"], *cfg["lp_range"]) + intr(fit_dict["lo"], *cfg["lp_range"])
    print "scale_fL = %.2f" % scale_fL
    print "scale_fR = %.2f" % scale_fR
    print "scale_f0 = %.2f" % scale_f0
    if "ewk" in fit_dict:
        print "f_ewk_bg = %.2f" % fit_dict["f_ewk_bg"]
        ewk_bg = fit_dict["ewk"].Clone()
        ewk_bg.SetLineColor(0)
        ewk_bg.SetFillColor(5)
        #        scale_ewk = fit_dict["ewk"].Integral()/allmc
        ewk_bg.Scale(fit_dict["f_ewk_bg"]*data_stats/ewk_bg.Integral())
        frm.addTH1(ewk_bg, "hist")
    if "qcd" in fit_dict:
        print "f_ewk_bg = %.2f" % fit_dict["f_qcd"].getVal()
        qcd_bg = fit_dict["qcd"].Clone()
        qcd_bg.SetLineColor(r.kRed - 7)
        qcd_bg.SetLineWidth(2)
        qcd_bg.SetFillColor(0)
        # Think we need to scale these too
        #        scale_qcd = fit_dict["qcd"].Integral()/allmc
        qcd_bg.Scale(fit_dict["f_qcd"].getVal()*data_stats/qcd_bg.Integral())
        frm.addTH1(qcd_bg, "hist")
        if "qcd_function" in fit_dict:
            print fit_dict["f_qcd"].getVal()*data_stats
            qcdfas = r.RooArgSet(fit_dict["qcd_function"])
            # fit_dict["model"].plotOn(frm, r.RooFit.LineColor(r.kBlack),
            #                          r.RooFit.Components(qcdfas))
    print "Data stats = %.2f" % data_stats
    if "lh" in fit_dict:
        lh = fit_dict["lh"].Clone()
        lh.SetLineColor(r.kRed)
        lh.SetLineWidth(2)
        lh.SetLineStyle(2)
        print lh.Integral()
        lh.Scale(fit_dict["f_w"].getVal()*fL(fit_dict["result"])[0]*scale_fL*data_stats/lh.Integral())
#        lh.Scale(fit_dict["f_w"].getVal()*fL(fit_dict["result"])[0]*allmc/intr(lh, *cfg["lp_range"]))
        print lh.Integral()
  #      lh.Scale(data_stats/lh.Integral())
        print "lh integral %.2f" % lh.Integral()
        print "lh scale %.2f" % (data_stats/lh.Integral())
        print "lh = %.2f" % lh.Integral()


    if "rh" in fit_dict:
        rh = fit_dict["rh"].Clone()
        rh.SetLineColor(r.kGreen)
        rh.SetLineWidth(2)
        rh.SetLineStyle(2)
        rh.Scale(fit_dict["f_w"].getVal()*fR(fit_dict["result"])[0]*scale_fR*data_stats/rh.Integral())#/intr(rh, *cfg["lp_range"]))
#        rh.Scale(fit_dict["f_w"].getVal()*fR(fit_dict["result"])[0]*allmc/intr(rh, *cfg["lp_range"]))
  #      rh.Scale(data_stats/rh.Integral())
        print "rh = %.2f" % rh.Integral()

    if "lo" in fit_dict:
        lo = fit_dict["lo"].Clone()
        lo.SetLineColor(r.kBlack)
        lo.SetLineWidth(2)
        lo.SetLineStyle(2)
        lo.Scale(fit_dict["f_w"].getVal()*f0(fit_dict["result"])[0]*scale_f0*data_stats/lo.Integral())#/intr(lo, *cfg["lp_range"]))
#        lo.Scale(fit_dict["f_w"].getVal()*f0(fit_dict["result"])[0]*allmc/intr(lo, *cfg["lp_range"]))
  #      lo.Scale(data_stats/lo.Integral())
        print "lo = %.2f" % lo.Integral()

    print "Sum (LH + RH + LO) = %.2f" % sum([lh.Integral(), rh.Integral(), lo.Integral()])
    print "Data stats = %.2f" % data_stats

#    Plot fit result
    model = lh.Clone()
    model.Add(rh)
    model.Add(lo)
    if "ewk" in fit_dict:
        model.Add(ewk_bg)
    if "qcd" in fit_dict:
        model.Add(qcd_bg)
    model.SetLineColor(r.kBlue)
    model.SetLineStyle(1)
    model.SetLineWidth(2)
    lh.Scale(data_stats/model.Integral())
    rh.Scale(data_stats/model.Integral())
    lo.Scale(data_stats/model.Integral())
    model.Scale(data_stats/model.Integral())
    print intr(lh, -0.4, 1.6)/(fit_dict["f_w"].getVal()*intr(model, -0.4, 1.6))
    print rh.Integral()/model.Integral()
    frm.addTH1(lh, "hist")
    frm.addTH1(rh, "hist")
    frm.addTH1(lo, "hist")
    #    frm.addTH1(model, "hist")

    frm.Draw()


    # Plot legend
    hist_temp = []
    leg=r.TLegend(0.2, 0.65, 0.9, 0.9)
    leg.SetFillStyle(0)
    leg.SetBorderSize(0)
    leg.SetTextSize(0.04)
    leg.SetTextFont(42)
    temp = [("lh", "f_{L}", 2, fL),
            ("rh", "f_{R}", 3, fR),
            ("lo", "f_{0}", r.kBlue, f0)]
    for name, title, col, parm in temp:
        h = fit_dict[name].Clone()
        h.SetLineColor(col); h.SetLineStyle(2); h.SetLineWidth(3)

        legtitle = "%s" % title
        if "show_values" in cfg and cfg["show_values"]:
            legtitle += " = %.3f #pm %.3f" % (
                parm(fit_dict["result"])[0],
                parm(fit_dict["result"])[1])
            if title in cfg["nominal_values"]:
                legtitle += " (MC: %.3f)" % cfg["nominal_values"][title]
        leg.AddEntry(h, legtitle, "L")
        hist_temp.append(h)
    if "ewk" in fit_dict:
        legtitle = "f_{ewk}"
        if "show_values" in cfg and cfg["show_values"]:
            legtitle += " = %.3f" % fit_dict["f_ewk_bg"]
        leg.AddEntry(ewk_bg, legtitle , "F")
    if "qcd" in fit_dict:
        legtitle = "f_{qcd}"
        if "show_values" in cfg and cfg["show_values"]:
            legtitle += " = %.3f #pm %.3f (MC: %.3f)" % (fit_dict["f_qcd"].getVal(),
                                                         fit_dict["f_qcd"].getError(),
                                                         fit_dict["f_qcd_nom"])
        leg.AddEntry(qcd_bg, legtitle, "L")
    if "show_extra_values" in cfg and cfg["show_extra_values"]:
        l = r.TLatex()
        l.SetNDC()
        l.DrawLatex(0.45, 0.85, "(f_{L} - f_{R}) = %.3f #pm %.3f" % (
            fLminusfR(fit_dict["result"])[0],
            fLminusfR(fit_dict["result"])[1]))
        l.DrawLatex(0.45, 0.78, "f_{0} = %.3f #pm %.3f" % (
            f0(fit_dict["result"])[0],
            f0(fit_dict["result"])[1]))
    leg.Draw()

    out_path = "%s/%s/" %  (default_cfg["output_path"],
                           fit_dict["name"])
    ensure_dir(out_path)
    c.SaveAs("%s/fit.png" % out_path)
    c.SaveAs("%s/fit.pdf" % out_path)

def plot_pulls(
    fit_globals,
    fit_dict,
    save_root=True
    ):

    plots = []
    f1 = fit_globals["f1"]
    f2 = fit_globals["f2"]
    mcstudy = fit_dict["mcstudy"]

    out_path = "%s/%s/" %  (default_cfg["output_path"],
                            fit_dict["name"])
    ensure_dir(out_path)
    if save_root:
        outfile = r.TFile("%s/pulls.root" % out_path, "recreate")
    # f1 Pull
    c = r.TCanvas("f1_pull_%s" % fit_dict["name"])
    frm = mcstudy.plotPull(f1, -3, 3, 30, r.kTRUE)
    plots.append(frm.getObject(0))
    frm.Draw()
    frm.Print("v")
    c.SaveAs("%s/f1_pull.pdf" % out_path)
    c.SaveAs("%s/f1_pull.png" % out_path)

    # f1 val
    c = r.TCanvas("f1_val_%s" % fit_dict["name"])
    frm = mcstudy.plotParam(f1)
    plots.append(frm.getObject(0))
    frm.Draw()
    c.SaveAs("%s/f1_val.pdf" % out_path)
    c.SaveAs("%s/f1_val.png" % out_path)

    # f1 Error
    c = r.TCanvas("f1_error_%s" % fit_dict["name"])
    frm = mcstudy.plotError(f1, 0, 0.1, 10)
    plots.append(frm.getObject(0))
    frm.Draw()
    c.SaveAs("%s/f1_error.pdf" % out_path)
    c.SaveAs("%s/f1_error.png" % out_path)

    # f2 Pull
    c = r.TCanvas("f2_pull_%s" % fit_dict["name"])
    frm = mcstudy.plotPull(f2, -3, 3, 30, r.kTRUE)
    plots.append(frm.getObject(0))
    frm.Draw()
    c.SaveAs("%s/f2_pull.pdf" % out_path)
    c.SaveAs("%s/f2_pull.png" % out_path)

    # f2 val
    c = r.TCanvas("f2_val_%s" % fit_dict["name"])
    frm = mcstudy.plotParam(f2)
    plots.append(frm.getObject(0))
    frm.Draw()
    c.SaveAs("%s/f2_val.pdf" % out_path)
    c.SaveAs("%s/f2_val.png" % out_path)

    # f2 error
    c = r.TCanvas("f2_error_%s" % fit_dict["name"])
    frm = mcstudy.plotError(f2, 0, 0.1, 10)
    plots.append(frm.getObject(0))
    frm.Draw()
    c.SaveAs("%s/f2_error.pdf" % out_path)
    c.SaveAs("%s/f2_error.png" % out_path)

    if "f_qcd" in fit_dict:
        c = r.TCanvas("fqcd_pull_%s" % fit_dict["name"])
        frm = mcstudy.plotPull(fit_dict["f_qcd"], -3, 3, 30, r.kTRUE)
        plots.append(frm.getObject(0))
        frm.Draw()
        c.SaveAs("%s/fqcd_pull.pdf" % out_path)
        c.SaveAs("%s/fqcd_pull.png" % out_path)

        c = r.TCanvas("fqcd_val_%s" % fit_dict["name"])
        frm = mcstudy.plotParam(fit_dict["f_qcd"])
        plots.append(frm.getObject(0))
        frm.Draw()
        c.SaveAs("%s/fqcd_val.pdf" % out_path)
        c.SaveAs("%s/fqcd_val.png" % out_path)

        c = r.TCanvas("fqcd_error_%s" % fit_dict["name"])
        frm = mcstudy.plotError(fit_dict["f_qcd"], 0, 0.1, 10)
        plots.append(frm.getObject(0))
        frm.Draw()
        c.SaveAs("%s/fqcd_error.pdf" % out_path)
        c.SaveAs("%s/fqcd_error.png" % out_path)

    if save_root:
        for p in plots:
            h = p.Clone()
        outfile.Write()
