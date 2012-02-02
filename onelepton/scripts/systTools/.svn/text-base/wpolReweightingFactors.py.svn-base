#!/usr/bin/env python
import ROOT as r

def fit_costheta_bin(hist, normalised=False):
    f3 = r.TF1("f3","((1-x)*(1-x)/4*[0] + (1+x)*(1+x)/4*[1] +[2]*(1-x*x)/2)",-0.99, 1.00)
    if hist.Integral() < 50: return (0.0, 0.0, 0.0)
    hist.Fit(f3)
    if normalised: total_pol = sum([f3.GetParameter(i) for i in range(3)])
    else: total_pol = 1.0
    return (f3.GetParameter(0)/total_pol,
            f3.GetParameter(1)/total_pol,
            f3.GetParameter(2)/total_pol)

def run_bins(hist, ptw_bins, y_bins):
    factors = []
    plots = []
    for ptw_bin_idx, ptw_bin in enumerate(ptw_bins):
        for y_bin_idx, y_bin in enumerate(y_bins):
            ptw_bin_low = hist.GetXaxis().FindBin(ptw_bin+0.01)
            if ptw_bin_idx == len(ptw_bins) -1:
                ptw_bin_high = hist.GetXaxis().GetNbins()+1
                ptw_sh = "#infty"
            else:
                ptw_bin_high = hist.GetXaxis().FindBin(ptw_bins[ptw_bin_idx+1]-0.01)
                ptw_sh = "%d" % ptw_bins[ptw_bin_idx+1]
            y_bin_low = hist.GetYaxis().FindBin(y_bin+0.01)
            if y_bin_idx == len(y_bins) -1:
                y_bin_high = hist.GetYaxis().GetNbins()+1
                y_sh = "#infty"
            else:
                y_bin_high = hist.GetYaxis().FindBin(y_bins[y_bin_idx+1]-0.01)
                y_sh = "%.1f" % y_bins[y_bin_idx+1]
            hist.GetXaxis().SetRange(ptw_bin_low, ptw_bin_high)
            hist.GetYaxis().SetRange(y_bin_low, y_bin_high)

            cos_theta_star_hist = hist.Project3D("ptw%dy%.2f_z" % (ptw_bin, y_bin))
            ptw_sl = "%d" % ptw_bin
            y_sl = "%.1f" % y_bin
            cos_theta_star_hist.SetTitle("cos(#theta^{*})  %s < PT(W) < %s, %s < Y < %s" % (ptw_sl, ptw_sh, y_sl, y_sh))
            cos_theta_star_hist.Rebin(10)
            (alpha, beta, gamma) = fit_costheta_bin(cos_theta_star_hist, normalised)
            cos_theta_star_hist.GetXaxis().SetRangeUser(-1, 0.9)
            plots.append(cos_theta_star_hist)
            factors.append((ptw_bin, y_bin, alpha, beta, gamma))
    return (factors, plots)

def make_plots(fname, ptw_bins, y_bins, plots):
    c = r.TCanvas("canv", "", 1000, 1000)
    pad = r.TPad("", "", 0.01, 0.25, 0.99, 0.99)
    pad.Draw()
    pad.cd()
    pad.Divide(len(y_bins),len(ptw_bins),0.0003,0.0003)
    for idx, cos_theta_star_hist in enumerate(plots):
        pad.cd(idx+1)
        cos_theta_star_hist.Draw("e")
    c.SaveAs(fname)

def write_factors(fname, factors):
    fout = open(fname,"w")
    fout.write("# Reweighting factors\n")
    cols = ["ptw_bin", "y_bin", "alpha+", "beta+", "gamma+", "alpha-", "beta-", "gamma-"]
    fout.write("# "+" , ".join(["{%d:<12}" % i for i in range(8)]).format(*cols)+"\n")
    for ptw_bin, y_bin, alpha_plus, beta_plus, gamma_plus, alpha_minus, beta_minus, gamma_minus in factors:
        fmt_str = "  {0:<12d} , {1:<12.1f} , " + " , ".join(["{%d:<12.5f}" % i for i in range(2,8)]) + "\n"
        fout.write(fmt_str.format(ptw_bin, y_bin, alpha_plus, beta_plus, gamma_plus, alpha_minus, beta_minus, gamma_minus))

if __name__ == "__main__":
    r.gROOT.SetStyle("Plain")
    tfile = r.TFile("/vols/cms03/as1604/ra4/onelepton/scripts/systematics/w.root")

    ptw_bins = [0, 50, 100, 200, 300, 500]
    y_bins = [0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0]
    normalised = False

    hist = tfile.Get("Systematics").Get("MC_WPt_Y_CosThetaStarPlus")

    factors_plus, plots = run_bins(hist, ptw_bins, y_bins)
    c = make_plots("CostThetaStarBins_Plus.pdf", ptw_bins, y_bins, plots)

    hist = tfile.Get("Systematics").Get("MC_WPt_Y_CosThetaStarMinus")
    factors_minus, plots = run_bins(hist, ptw_bins, y_bins)
    c = make_plots("CostThetaStarBins_Minus.pdf", ptw_bins, y_bins, plots)

    factors = [(p[0], p[1], p[2], p[3], p[4], m[2], m[3], m[4]) for (p, m) in zip(factors_plus, factors_minus)]
    write_factors("reweightFactors.txt", factors)


