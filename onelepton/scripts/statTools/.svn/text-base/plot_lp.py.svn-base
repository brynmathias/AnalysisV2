#!/usr/bin/env python

import ROOT as r

fnames = {
    "w":"%s/default_Muons_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root",
    "z":"%s/default_Muons_DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root",
    "ttbar": "%s/default_Muons_TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root"
    }


if __name__ == "__main__":
    dirname = "MuonStandardPlots"
    histname = "Njet_all"
    files = [(n, r.TFile(f % "../resultsMC_ht350_lp08")) for (n, f) in fnames.iteritems()]
    hist = files[0][1].Get(dirname).Get(histname).Clone()
    for (n, f) in files[1:]:
        hist.Add(f.Get(dirname).Get(histname))
    files_up = [(n, r.TFile(f % "../resultsMC_ht350_lp08_metup")) for (n, f) in fnames.iteritems()]
    hist_up = files_up[0][1].Get(dirname).Get(histname).Clone()
    for (n, f) in files_up[1:]:
        hist_up.Add(f.Get(dirname).Get(histname))
    files_down = [(n, r.TFile(f % "../resultsMC_ht350_lp08_metdown")) for (n, f) in fnames.iteritems()]
    hist_down = files_down[0][1].Get(dirname).Get(histname).Clone()
    for (n, f) in files_down[1:]:
        hist_down.Add(f.Get(dirname).Get(histname))
    # hist.Rebin(20)
    # hist_up.Rebin(20)
    # hist_down.Rebin(20)
    c = r.TCanvas("test")
    hist.Draw("hist")
    hist_up.SetMarkerStyle(22)
    hist_up.Draw("p0 same")
    hist_down.SetMarkerStyle(23)
    hist_down.Draw("p0 same")
    c.SaveAs("./LP.pdf")

