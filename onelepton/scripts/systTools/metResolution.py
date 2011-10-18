#!/usr/bin/env python
import ROOT as r

if __name__ == "__main__":
    r.gROOT.SetStyle("Plain")
    tfile = r.TFile("/vols/cms03/as1604/ra4/onelepton/scripts/systematics/w.root")
    hist = tfile.Get("Systematics").Get("MC_RECO_pfMETRes_genMHT")

    genmht_bins = [0, 50, 60, 70, 80, 90, 100, 120, 140, 160,
                   180, 200, 220, 240, 260, 280, 300, 350, 400, 450, 500]

    fout = open("METResolution.txt", "w")
    c = r.TCanvas("canv", "", 800, 1000)
    pad = r.TPad("", "", 0.01, 0.25, 0.99, 0.99)
    pad.Draw()
    pad.cd()
    nrows = len(genmht_bins)/4
    if len(genmht_bins) % 4 != 0: nrows += 1
    pad.Divide(4, nrows, 0.0003, 0.0003)
    pad_idx = 1
    fout.write("# "+" , ".join(["{%d:<10}" % i for i in range(2)]).format("genmht bin", "met sigma")+"\n")
    for idx, gbin in enumerate(genmht_bins):
        xbin_low = hist.GetXaxis().FindBin(gbin+0.001)
        if idx == len(genmht_bins)-1:
            xbin_high = hist.GetXaxis().GetNbins()
        else:
            xbin_high = hist.GetXaxis().FindBin(genmht_bins[idx+1]-0.001)
        pad.cd(pad_idx)
        hmetres = hist.ProjectionY("hist_%d" % idx, xbin_low, xbin_high)
        f = r.TF1("gaus", "gaus", -5, 5)
        hmetres.Fit(f)
        sigma = f.GetParameter(2)
        hmetres.GetXaxis().SetRangeUser(-1.5, 1.5)
        hmetres.Draw("e")
        pad_idx += 1
        fout.write("  {0:<10d} , {1:<10.6f}\n".format(gbin, sigma))
    c.SaveAs("METResolution.pdf")

