#!/usr/bin/env python
import ROOT as r
import math
import os.path

base = "/vols/cms03/as1604/ra4/onelepton/scripts/"
path = {
    "zero":base+"resultsMC",
    "metup":base+"resultsMC_metup",
    "metdown":base+"resultsMC_metdown",
    "metres":base+"resultsMC_metresnaive",
    "polup":base+"resultsMC_polup",
    "poldown":base+"resultsMC_poldown"

    }

files = {
#    "w" : "%s/default_Muons_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root",
    "w" : "%s/w.root",
    "tt" : "%s/Muons_TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root",
    "z" : "%s/Muons_DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root",
    "lm1" : "%s/Muons_LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
    "lm3" : "%s/Muons_LM3_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
    "lm6" : "%s/Muons_LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root"
    }

def getFile(fname, fset, default_fset="zero"):
    fpath = fname % path[fset]
    if not os.path.exists(fpath):
        print "%s : Falling back to %s" % (fname, default_fset)
        fpath = fname % path[default_fset]
    if not os.path.exists(fpath): raise IOError("File not found: %s" % fname)
    return r.TFile(fpath)


def get_ratio(h):
    return h.Integral(0, h.GetXaxis().FindBin(0.14999))/h.Integral(h.GetXaxis().FindBin(0.30001), h.GetNbinsX()+1)

def makeSystPlots(dirname, uncname, rdirname, histname, zero_files, up_files, down_files = None):
    def getHist(f):
        h = f.Get(rdirname).Get(histname).Clone()
        h.Scale(10.)
        h.Rebin(20)
        return h
    def drawLine(c):
        l = r.TLine(0.15, c.GetUymin(), 0.15, c.GetUymax())
        l.SetLineStyle(9)
        return l
    def drawLineC(c):
        l = r.TLine(0.3, c.GetUymin(), 0.3, c.GetUymax())
        l.SetLineStyle(9)
        return l
    def arrowHeight(c):
        return 0.9*c.GetUymax()
    def drawArrow(c):
        return r.TArrow(0.15, arrowHeight(c), -0.3, arrowHeight(c), 0.02, "|>" )
    def drawArrowC(c):
        return r.TArrow(0.3, arrowHeight(c), 0.75, arrowHeight(c), 0.02, "|>" )
    def makeLegend():
        return r.TLegend(0.1, 0.9, 0.3, 0.6)
    def makeLabel(lab):
        l = r.TLatex()
        l.SetNDC()
        if lab == "Signal": l.DrawLatex(0.35, 0.8, lab)
        else: l.DrawLatex(0.65, 0.8, lab)

    onesided = (down_files is None)
    if down_files is None:
        down_files = up_files

    hzero = getHist(zero_files["w"])
    for s in ["tt", "z"]:
        hzero.Add(getHist(zero_files[s]))

    h1 = getHist(up_files["w"])
    for s in ["tt", "z"]:
        h1.Add(getHist(up_files[s]))

    h2 = getHist(down_files["w"])
    for s in ["tt", "z"]:
        h2.Add(getHist(down_files[s]))

    thisdir = os.getcwd()
    try:
        os.mkdir(dirname)
    except OSError:
        pass
    os.chdir(dirname)
    # make Ratio plots
    c = r.TCanvas("brun")
    pad = r.TPad("", "", 0.01, 0.25, 0.99, 0.99)
    pad.Draw()
    pad.cd()
    pad.Divide(2,1,0.0003,0.0003)
    pad.cd(1)
    h1.SetLineColor(r.kRed)
    h1.SetLineWidth(2)
    h1.GetYaxis().SetRangeUser(0, 1.3*max([h1.GetMaximum(), h2.GetMaximum(), hzero.GetMaximum()]))
    h1.Draw("hist e")
    if not onesided:
        h2.SetLineColor(r.kBlue)
        h2.SetLineWidth(2)
        h2.Draw("hist e same")
    hzero.SetLineColor(r.kBlack)
    hzero.SetLineWidth(2)
    hzero.Draw("hist e same")
    leg = makeLegend()
    leg.AddEntry(hzero, "Unscaled", "L")
    leg.AddEntry(h1, "%s Up" % uncname, "L")
    if not onesided:
        leg.AddEntry(h2, "%s Down" % uncname, "L")
    leg.Draw()

    pad.cd(2)
    ratio = h1.Clone()
    ratio.SetLineColor(r.kRed)
    ratio.SetLineWidth(2)
    ratio.Divide(hzero)
    ratio.GetYaxis().SetRangeUser(0, 2)
    ratio.Draw("")
    if not onesided:
         ratio2 = h2.Clone()
         ratio2.SetLineColor(r.kBlue)
         ratio2.SetLineWidth(2)
         ratio2.Divide(hzero)
         ratio2.GetYaxis().SetRangeUser(0, 2)
         ratio2.Draw("same")
    c.SaveAs("%s_%s_ratio.pdf" % (rdirname, histname))

    c = r.TCanvas("brun")
    c.SetGrid()

    herr = hzero.Clone()
    for i in range(hzero.GetNbinsX()):
        up = abs(h1.GetBinContent(i) - hzero.GetBinContent(i))
        down = abs(h2.GetBinContent(i) - hzero.GetBinContent(i))
        herr.SetBinContent(i, 0.5*(hzero.GetBinContent(i) + up +
                                   hzero.GetBinContent(i) - down))
        herr.SetBinError(i, 0.5*(up + down))


    hs = r.THStack("hs","")
    hw = getHist(tfiles_zero["w"])
    hw.SetFillColor(r.kAzure+7)
    hw.SetFillStyle(1001)
    htt = getHist(tfiles_zero["tt"])
    htt.SetFillColor(r.kGreen+2)
    htt.SetFillStyle(1001)
    hz = getHist(tfiles_zero["z"])
    hz.SetFillColor(r.kYellow-7)
    hz.SetFillStyle(1001)

    hlm1 = getHist(tfiles_zero["lm1"])
    hlm1.SetFillColor(r.kMagenta- 9)

    hs.Add(hw)
    hs.Add(htt)
    hs.Add(hz)
    hs.Add(hlm1)
    hs.SetTitle(";L_{P};#Events/fb^{-1};")
    hs.Draw("hist")

    hs.SetMaximum(1.5*max([herr.GetMaximum(), hlm1.GetMaximum()]))
    c.Update()
    herr.SetFillColor(r.kBlack)
    herr.SetFillStyle(3002)
    herr.Draw("e2 same")
    c.Update()

    l = drawLine(c)
    l.SetLineWidth(2)
    l.Draw()

    lC = drawLineC(c)
    lC.SetLineWidth(2)
    lC.Draw()

    a = drawArrow(c)
    a.Draw()
    aC = drawArrowC(c)
    aC.Draw()

    leg = makeLegend()
    leg.AddEntry(hw, "W+Jets", "f")
    leg.AddEntry(htt, "tt+Jets", "f")
    leg.AddEntry(hz, "Z+Jets", "f")
    leg.AddEntry(herr, uncname, "f")
    leg.AddEntry(hlm1, "LM1", "f")
    leg.Draw()
    makeLabel("Signal")
    makeLabel("Control")
    c.SaveAs("%s_%s.pdf" % (rdirname, histname))
    os.chdir(thisdir)

    return ("imgs/%s/%s_%s.pdf" % (dirname, rdirname, histname),
            "imgs/%s/%s_%s_ratio.pdf" % (dirname, rdirname, histname))

def figure():
    return "\\begin{figure}[h!]\n\centering"

def subfigure(caption, path, width=0.5):
    return "\\subfloat[%s]{\n\\includegraphics[width=%.1f\\textwidth]{%s}}" % (
        caption, width, path)
def afigure(caption, path, width=0.5):
    return "\\begin{figure}[h!]\\centering\n\\includegraphics[width=%.1f\\textwidth]{%s}\\caption{%s}\\end{figure}" % (
        width,  path, caption)
def figure_end(caption):
    return "\\caption{%s}\n\\end{figure}" % caption
def newline():
    return r"\\"
def escape(s):
    return s.replace("_", "\_")
def subsection(s):
    return "\\FloatBarrier\\subsection{%s}" % s

if __name__ == "__main__":
    r.gROOT.SetStyle("Plain")


    tfiles_zero = dict([(n , getFile(fname, "zero", "zero")) for (n, fname) in files.iteritems()])
    tfiles_metup = dict([(n , getFile(fname, "metup", "zero")) for (n, fname) in files.iteritems()])
    tfiles_metdown = dict([(n , getFile(fname, "metdown", "zero")) for (n, fname) in files.iteritems()])
    tfiles_metres = dict([(n , getFile(fname, "metres", "zero")) for (n, fname) in files.iteritems()])
    tfiles_polup = dict([(n , getFile(fname, "polup", "zero")) for (n, fname) in files.iteritems()])
    tfiles_poldown = dict([(n , getFile(fname, "poldown", "zero")) for (n, fname) in files.iteritems()])

    latex = []
    for sumpt in [150, 250, 350, 450]:
        latex.append(subsection("$S_T^{\\textrm{lep}}$ bin : %d" % sumpt))
        for var in ["LPPlusvar_all", "LPMinusvar_all"]:
            print sumpt, var
            scale_plot, scale_ratio = makeSystPlots("metscale", "JEC Unc.",
                                                    "MuonStandardPlots_%d_NOLP" % sumpt,
                                                    var, tfiles_zero, tfiles_metup, tfiles_metdown)
            res_plot, res_ratio = makeSystPlots("metres", "MET Res.",
                                                "MuonStandardPlots_%d_NOLP" % sumpt,
                                                var, tfiles_zero, tfiles_metres, None)
            pol_plot, pol_ratio = makeSystPlots("pol", "W Pol.",
                                                "MuonStandardPlots_%d_NOLP" % sumpt,
                                                var ,tfiles_zero, tfiles_polup, tfiles_poldown)
            latex.extend([
            figure(),
            subfigure("JEC Unc.", scale_plot, 0.5),
            subfigure("MET Res.", res_plot, 0.5),
            newline(),
            subfigure("W Pol.", pol_plot, 0.5),
            figure_end("$S_T^{\\textrm{lep}}$ bin : %s (%s)" % (escape("%d" % sumpt), escape(var))),
            afigure("JEC Unc. (Ratio)", scale_ratio, 0.7),
            afigure("MET Res. (Ratio)", res_ratio, 0.7),
            afigure("W Pol. (Ratio)", pol_ratio, 0.7)
                ])

    print "\n".join(latex)
