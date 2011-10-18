#!/usr/bin/env python
from ROOT import *

#gROOT.SetBatch(True)
#gROOT.SetStyle("Plain")
#gStyle.SetTitleSize(0.06)
#gStyle.SetTitleXOffset(0.8);
#gStyle.SetTitleYOffset(1.15);
#gStyle.SetLabelSize(0.05, "XYZ");

def HistogramMaxY(H):
   Nbins = H.GetNbinsX()
   Entries = [H.GetBinContent(i) for i in range(1,Nbins+1)]
   return max(Entries)

def HistogramMinX(H):
  Nbins = H.GetNbinsX()
  for x in range(0,Nbins):
    if H.GetBinContent(x) != 0:
      return H.GetBinLowEdge(x-2)
  return 0

def HistogramMaxX(H):
  Nbins = H.GetNbinsX()
  BackItr = range(0,Nbins)
  BackItr.reverse()
  for x in BackItr :
    if H.GetBinContent(x) != 0:
      return H.GetBinLowEdge(x+1)

sample = "Data"
#sample = "TuneZ2_pythia6"
#sample = "TuneD6T_madgraph"
var = "pfMET"
end = "_3"

file = TFile.Open("../../results/PhotonHad2jets_"+sample+".root")
errorfile_madgraph = TFile.Open("Systematics_TuneD6T_madgraph_"+var+end+".root")
ggm_1200_800_file = TFile.Open("../../results/PhotonHad3jets_Msq1040_Mg640.root")
ggm_1200_800 = ggm_1200_800_file.Get("StandardPlots_HT_sele/"+var+end)
ggm_1200_800.Scale(2.)
ggm_800_1200_file = TFile.Open("../../results/PhotonHad2jets_Msq720_Mg1040.root")
ggm_800_1200 = ggm_800_1200_file.Get("StandardPlots_HT_sele/"+var+end)
ggm_800_1200.Scale(2.)
#errorfile_pythia6 = TFile.Open("Systematics_TuneZ2_pythia6_"+var+end+".root")
hist_sele = file.Get("StandardPlots_HT_sele/"+var+end)
hist_anti = file.Get("StandardPlots_HT_anti/"+var+end)
print "Selected Total ="+str(hist_sele.Integral()) 
print "Control Total ="+str(hist_anti.Integral()) 
hist_anti.Scale(hist_sele.Integral()/hist_anti.Integral())
error = Double(0.)
print "Observed pfMET>80 = "+str(hist_sele.IntegralAndError(16,100,error)) 
print "Error = "+str(error)
print "Predicted pfMET>80 = "+str(hist_anti.IntegralAndError(16,100,error)) 
print "Error = "+str(error)
bias = hist_anti - hist_sele
bias.Divide(bias, hist_sele, 1., 1., "B")
stat = hist_anti.Clone()
for bin in range(hist_anti.GetNbinsX()+2):
  stat.SetBinContent(bin, hist_anti.GetBinError(bin))
  stat.SetBinError(bin, 0.)
syst = errorfile_madgraph.Get(var+end)
#new = syst_madgraph.Clone()
#syst_pythia6 = errorfile_pythia6.Get(var+end)
#syst = syst_madgraph + syst_pythia6
syst.Scale(0.01)
syst.Multiply(hist_anti)
print syst.IntegralAndError(16,100,error)
print error
print "Systematic Error = "+str(sqrt(syst.Integral(16,81)))
for bin in range(syst.GetNbinsX()+2):
  syst.SetBinContent(bin, abs(syst.GetBinContent(bin)))
syst_top = hist_anti + stat + syst
stat_top = hist_anti + stat
stat_bottom = hist_anti - stat
syst_bottom = hist_anti - stat - syst

c1 = TCanvas("canvas","name",1200,1200)
# Set axis range
MaxY = 1.0
MaxX = 0.1
MinX = 1000.

if HistogramMinX(hist_sele) < MinX :
  MinX = HistogramMinX(hist_sele)
if HistogramMaxX(hist_sele) > MaxX :
  MaxX = HistogramMaxX(hist_sele)
if HistogramMaxY(hist_sele) > MaxY :
  MaxY = HistogramMaxY(hist_sele)

#if HistogramMinX(hist_anti) < MinX :
#  MinX = HistogramMinX(hist_anti)
#if HistogramMaxX(hist_anti) > MaxX :
#  MaxX = HistogramMaxX(hist_anti)
#if HistogramMaxY(hist_anti) > MaxY :
#  MaxY = HistogramMaxY(hist_anti)

MinX = 0.
MaxX = 100.
hist_sele.GetXaxis().SetRangeUser(MinX,MaxX)
hist_sele.SetMarkerStyle(20)
hist_sele.SetMarkerColor(1)
hist_sele.SetName("sele")
hist_sele.SetBinContent(21,hist_sele.Integral(21,81))
syst_top.GetXaxis().SetRangeUser(MinX,MaxX)
syst_top.GetYaxis().SetRangeUser(1.,1000.)
syst_top.SetMarkerStyle(1)
syst_top.SetMarkerColor(kGreen-6)
syst_top.SetFillColor(kGreen-6)
syst_top.SetName("syst_top")
stat_top.GetXaxis().SetRangeUser(MinX,MaxX)
stat_top.SetMarkerStyle(1)
stat_top.SetMarkerColor(kCyan-9)
stat_top.SetFillColor(kCyan-9)
stat_top.SetName("stat_top")
hist_anti.GetXaxis().SetRangeUser(MinX,MaxX)
hist_anti.SetLineColor(kPink+2)
hist_anti.SetMarkerColor(kPink+2)
hist_anti.SetMarkerStyle(1)
hist_anti.SetLineWidth(3)
hist_anti.SetName("anti")
hist_anti.SetBinContent(21,hist_anti.Integral(21,81))
stat_bottom.GetXaxis().SetRangeUser(MinX,MaxX)
stat_bottom.SetMarkerStyle(1)
stat_bottom.SetMarkerColor(kGreen-6)
stat_bottom.SetFillColor(kGreen-6)
stat_bottom.SetName("stat_bottom")
syst_bottom.GetXaxis().SetRangeUser(MinX,MaxX)
syst_bottom.SetLineColor(1)
syst_bottom.SetFillColor(10)
syst_bottom.SetName("syst_bottom")
ggm_1200_800.GetXaxis().SetRangeUser(MinX,MaxX)
ggm_1200_800.SetLineColor(4)
ggm_1200_800.SetMarkerColor(4)
ggm_1200_800.SetMarkerStyle(1)
ggm_1200_800.SetLineWidth(3)
ggm_1200_800.SetBinContent(21,ggm_1200_800.Integral(41,81))
ggm_800_1200.GetXaxis().SetRangeUser(MinX,MaxX)
ggm_800_1200.SetLineColor(2)
ggm_800_1200.SetMarkerColor(2)
ggm_800_1200.SetMarkerStyle(1)
ggm_800_1200.SetLineWidth(3)
ggm_800_1200.SetBinContent(21,ggm_800_1200.Integral(41,81))

syst_top.Draw("hist")
stat_top.Draw("histsame")
stat_bottom.Draw("histsame")
syst_bottom.Draw("histsame")
hist_anti.Draw("Lsame")
hist_sele.Draw("EPsame")
ggm_1200_800.Draw("histsame")
ggm_800_1200.Draw("histsame")
lumi = TLatex(0.4,.83,"#scale[0.8]{#int L dt = 151 pb^{-1}, #sqrt{s} = 7 TeV}");
lumi.SetNDC()
lumi.Draw()
leg = TLegend(0.6, 0.6, 0.8, 0.8)
leg.SetShadowColor(0)
leg.SetFillColor(0)
leg.SetLineColor(0)
leg.AddEntry(hist_sele,"Data","LP")
leg.AddEntry(hist_anti,"Prediction","LfP")
leg.AddEntry(syst_top,"Syst. Error","LfP")
leg.AddEntry(stat_top,"Stat. Error","LfP")
leg.Draw()

c1.SetLogy()
c1.SaveAs("plots/SelevsAnti_"+sample+"_"+var+end+".png")
bias.GetYaxis().SetTitle("% bias")
bias.GetXaxis().SetRangeUser(MinX,MaxX)
bias.SetLineColor(kBlue+2)
bias.SetLineWidth(3)
bias.SetName("bias")
bias.Draw("histE9")
c1.SaveAs("plots/Bias_"+sample+"_"+var+end+".png")
