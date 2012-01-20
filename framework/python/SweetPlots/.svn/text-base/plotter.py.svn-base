from ROOT import *
from SweetPlots.utilities import PSet
gStyle.SetOptStat(0)

def Max(list):
    max_value = -99.
    for ele in list:
        if ele.Histogram.GetMaximum() > max_value:
            max_value = ele.Histogram.GetMaximum()
            max_element = ele
    return max_element

def Plot(args):
    hist_list = args[0]
    leg = args[1]
    outname = args[2]
    out_dir = args[3]
    format_list = args[4]
    opt = args[5]
    lumi = TLatex(0.5, 0.91, "#int Ldt = 1.1 fb^{-1};   #sqrt{s} = 7 TeV")
    lumi.SetNDC()
    c0 = TCanvas("c0")
    #c0 = TCanvas("c0", outname, 1000, 1000)
    #c1 = TCanvas("c1", outname, 1000, 1000)
    c1 = TCanvas("c1")
    if opt == "log":
        c0.SetLogy()
        c1.SetLogy()
    c0.cd()
    max_hist = Max(hist_list)
    #max_hist.Histogram.Sumw2()
    #max_hist.Histogram.Rebin()
    max_hist.Histogram.SetTitle(max_hist.Title)
    max_hist.Histogram.SetAxisRange(max_hist.XAxisMin, max_hist.XAxisMax, "X")
    max_hist.Histogram.SetAxisRange(max_hist.YAxisMin, max_hist.Histogram.GetMaximum()*1.2, "Y")
    max_hist.Histogram.SetXTitle(max_hist.XAxisLabel)
    max_hist.Histogram.SetYTitle(max_hist.YAxisLabel)
    max_hist.Histogram.SetLineWidth(max_hist.LineWidth)
    max_hist.Histogram.SetLineColor(max_hist.LineColor)
    max_hist.Histogram.SetLineStyle(max_hist.LineStyle)
    max_hist.Histogram.SetFillColor(max_hist.FillColor)
    max_hist.Histogram.SetFillStyle(max_hist.FillStyle)
    max_hist.Histogram.SetMarkerColor(max_hist.MarkerColor)
    max_hist.Histogram.SetMarkerStyle(max_hist.MarkerStyle)
    max_hist.Histogram.Draw(max_hist.DrawOption)
    i = 0
    for h in hist_list:
        if h != max_hist:
            #h.Histogram.Sumw2()
            #h.Histogram.Rebin()
            h.Histogram.SetLineWidth(h.LineWidth)
            h.Histogram.SetLineColor(h.LineColor)
            h.Histogram.SetLineStyle(h.LineStyle)
            h.Histogram.SetFillColor(h.FillColor)
            h.Histogram.SetFillStyle(h.FillStyle)
            h.Histogram.SetMarkerColor(h.MarkerColor)
            h.Histogram.SetMarkerStyle(h.MarkerStyle)
            h.Histogram.Draw(h.DrawOption+"same")
        if i == len(hist_list) - 2:
            bottom = h.Histogram.Clone()
        if i == len(hist_list) - 1:
            top = h.Histogram.Clone()
        i = i + 1
    leg.Draw()
    lumi.Draw()
    c1.cd()
    ratio = top.Clone()
    ratio.Divide(top, bottom)#, 1, 1, "B")
    ratio.SetAxisRange(max_hist.XAxisMin, max_hist.XAxisMax, "X")
    ratio.SetYTitle("ratio")
    ratio.Draw()
    # Fit horizontal line to ratio plot
    #nBins = ratio.GetXaxis().GetNbins()
    nBins = int( max_hist.XAxisMax/max_hist.Histogram.GetBinWidth(1) )
    min = ratio.GetXaxis().GetBinLowEdge(1)
    max = ratio.GetXaxis().GetBinUpEdge(nBins)
    n = 0
    sx = 0
    sy = 0
    sx2 = 0
    sy2 = 0
    sxy = 0
    chi2 = 0
    #sum_x_over_sig2 = 0
    #sum_1_over_sig2 = 0
    for i in range(nBins):
        i = i + 1
        if ratio.GetBinError(i) != 0 and ratio.GetBinError(i) != float('nan') and ratio.GetBinError(i) != float('inf'):
            n = n + 1./ratio.GetBinError(i)**2
            sx = sx + ratio.GetBinCenter(i)/ratio.GetBinError(i)**2
            sy = sy + ratio.GetBinContent(i)/ratio.GetBinError(i)**2
            sx2 = sx2 + ratio.GetBinCenter(i)**2/ratio.GetBinError(i)**2
            sy2 = sy2 + ratio.GetBinContent(i)**2/ratio.GetBinError(i)**2
            sxy = sxy + ratio.GetBinCenter(i)*ratio.GetBinContent(i)/ratio.GetBinError(i)**2
            #print "Bin Error = "+str(ratio.GetBinError(i))
            #sum_x_over_sig2 = sum_x_over_sig2 + ratio.GetBinContent(i)/ratio.GetBinError(i)**2
            #sum_1_over_sig2 = sum_1_over_sig2 + 1/ratio.GetBinError(i)**2
    a0 = 1
    a1 = 1
    #if sum_1_over_sig2 != 0:
        #a0 = sum_x_over_sig2/sum_1_over_sig2 
    if n*sx2 - sx**2 != 0:
        a0 = (sx2*sy - sx*sxy)/(n*sx2 - sx**2)
        a1 = (n*sxy - sx*sy)/(n*sx2 - sx**2)
    chi2 = 0
    for i in range(nBins):
        i = i + 1
        if ratio.GetBinError(i) != 0:
            chi2 = chi2 + ( (ratio.GetBinContent(i) - a0 - a1*ratio.GetBinCenter(i))/ratio.GetBinError(i) )**2
    s = 0
    err_a0 = 0
    err_a1 = 0
    chi2_over_ndof = 0
    if nBins > 2 and sx2 > 0:
        chi2_over_ndof = chi2/(nBins-2)
        s = sqrt( (sy2 - sxy**2/sx2) / (nBins - 2) )
        err_a0 = sqrt( 1/n )#+ (sx/nBins)**2/sx2 )
        err_a1 = s/sqrt(sx2)
    line = TLine(min, a0, max, a0+a1*(max-min))
    line.SetLineWidth(3)
    line.Draw()
    #if sum_1_over_sig2 != 0:
    #    err = nBins/sum_1_over_sig2 
    a0_box = TLatex(0.2, 0.85, "a0 = %.2f" % a0 + "#pm" + "%.2f" % err_a0)
    a0_box.SetNDC()
    a0_box.Draw()
    a1_box = TLatex(0.2, 0.75, "a1 = %.4f" % a1 + "#pm" + "%.4f" % err_a1)
    a1_box.SetNDC()
    a1_box.Draw()
    chi2_box = TLatex(0.2, 0.65, "#chi^{2}/ndof = %.2f" % chi2_over_ndof)
    chi2_box.SetNDC()
    chi2_box.Draw()
    lumi.Draw()
    for format in format_list:
        c0.SaveAs(out_dir+outname+format)
        c1.SaveAs(out_dir+outname+"_ratio"+format)


def DoPlotting(args):
    samples = args[0]
    histograms = args[1]
    files_folder = args[2]
    out_dir = args[3]
    formats = args[4]
    for h in histograms:
        hist_list = []
        files = []
        leg = TLegend(0.7,0.75,0.9,0.9)
        leg.SetFillColor(0)
        for s in samples:
            print "Getting file "+files_folder+s.FileName+" ; histogram "+s.Folder+h.Name+"."
            file = TFile(files_folder+s.FileName, "READ")
            files.append(file)
            histogram = file.Get(s.Folder+h.Name)
            if histogram.Integral() > 0: 
                histogram.Scale(1./histogram.Integral())
            #if s.Weight == -1:
            #  histogram.Scale(1./histogram.Integral())
            #else:
            #  histogram.Scale(s.Weight)
            hist = PSet(
                Histogram = histogram,
                Title = h.Title,
                XAxisLabel = h.XAxisLabel,
                XAxisMin = h.XAxisMin,
                XAxisMax = h.XAxisMax,
                YAxisLabel = h.YAxisLabel,
                YAxisMin = h.YAxisMin,
                YAxisMax = h.YAxisMax,
                #Rebin = h.Rebin,
                LineColor = s.LineColor,
                LineWidth = s.LineWidth,
                LineStyle = s.LineStyle,
                FillColor = s.FillColor,
                FillStyle = s.FillStyle,
                MarkerColor = s.MarkerColor,
                MarkerStyle = s.MarkerStyle,
                DrawOption = s.DrawOption, 
            )
            hist_list.append(hist)
            if hist.FillStyle == 0:
                key = "LP"
            else:
                key = "F" 
            leg.AddEntry(hist.Histogram, s.DisplayName, key)
        print "Plotting "+h.Name+" histogram."
        Plot([hist_list, leg, h.Name, out_dir, formats, h.LogOption])
        for file in files:
            file.Close()
