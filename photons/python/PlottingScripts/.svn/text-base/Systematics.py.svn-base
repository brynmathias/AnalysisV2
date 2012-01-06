#!/usr/bin/env python
from ROOT import *
gStyle.SetOptStat(0)

analysis = "Calo_egm10006tight_geq3jets_"
var = "pfMET"
text = analysis+"\n"
text = text + "========================================\n\n"
text = text + "                   Selected      Control\n"
text = text + "----------------------------------------\n"
for sample in ["TuneZ2_pythia6", "TuneD6T_madgraph", "Data"]:
  for end in ["_1", "_2", "_3", "_all"]:
    file = TFile.Open("../../results/"+analysis+sample+".root")
    if sample == "TuneZ2_pythia6" or sample == "TuneD6T_madgraph":
      hist_sele = file.Get("StandardPlots_HT_sele/"+var+end)
      hist_anti = file.Get("StandardPlots_HT_anti/"+var+end)
      #hist_anti.Scale(hist_sele.Integral()/hist_anti.Integral())
      bias = hist_anti - hist_sele
      bias.Divide(bias, hist_sele, 1., 1., "B")
      bias.Scale(100.)

      bias.GetXaxis().SetRangeUser(0.,100.)
      bias.GetYaxis().SetRangeUser(-100.,100.)
      bias.SetLineColor(4)
      bias.SetLineWidth(3)
      bias.SetMarkerStyle(1)
      bias.SetMarkerColor(4)
      bias.Draw("histE9")
      c1.SaveAs("plots/Systematics/Bias_"+sample+"_"+var+end+".png")
      c1.SaveAs("plots/Systematics/Bias_"+sample+"_"+var+end+".eps")
      error = bias.Clone()
      for bin in range(bias.GetNbinsX()+2):
        error.SetBinContent(bin, bias.GetBinError(bin))
        error.SetBinError(bin, 0.)
      outfile = TFile.Open("plots/Systematics/Systematics_"+sample+"_"+var+end+".root", "recreate")
      error.Write()
      outfile.Close()

    else:
      hist_sele = file.Get("StandardPlots_HT_sele/"+var+end)
      hist_anti = file.Get("StandardPlots_HT_anti/"+var+end)
      errorfile = TFile.Open("plots/Systematics/Systematics_TuneD6T_madgraph_"+var+end+".root")
      #errorfile = TFile.Open("Systematics_TuneZ2_pythia6_"+var+end+".root")
      if end == "_1":
        text = text + "320 < HT < 400     "+str(int(hist_sele.Integral()))+"            "+str(int(hist_anti.Integral()))+"\n"
      if end == "_2":
        text = text + "400 < HT < 500     "+str(int(hist_sele.Integral()))+"            "+str(int(hist_anti.Integral()))+"\n"
      if end == "_3":
        text = text + "HT > 500           "+str(int(hist_sele.Integral()))+"            "+str(int(hist_anti.Integral()))+"\n"
      print "Selected Total ="+str(hist_sele.Integral()) 
      print "Control Total ="+str(hist_anti.Integral()) 
      hist_anti.Scale(hist_sele.Integral(1,16)/hist_anti.Integral(1,16))
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
      syst = errorfile.Get(var+end)
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
      hist_sele.SetMarkerStyle(20)
      hist_sele.SetMarkerColor(1)
      hist_sele.SetName("sele")
      hist_sele.SetBinContent(21,hist_sele.Integral(21,81))
      syst_top.SetMarkerStyle(1)
      syst_top.SetMarkerColor(kGreen-6)
      syst_top.SetFillColor(kGreen-6)
      syst_top.SetName("syst_top")
      stat_top.SetMarkerStyle(1)
      stat_top.SetMarkerColor(kCyan-9)
      stat_top.SetFillColor(kCyan-9)
      stat_top.SetName("stat_top")
      hist_anti.SetLineColor(kPink+2)
      hist_anti.SetMarkerColor(kPink+2)
      hist_anti.SetMarkerStyle(1)
      hist_anti.SetLineWidth(3)
      hist_anti.SetName("anti")
      hist_anti.SetBinContent(21,hist_anti.Integral(21,81))
      stat_bottom.SetMarkerStyle(1)
      stat_bottom.SetMarkerColor(kGreen-6)
      stat_bottom.SetFillColor(kGreen-6)
      stat_bottom.SetName("stat_bottom")
      syst_bottom.SetLineColor(1)
      syst_bottom.SetFillColor(10)
      syst_bottom.SetName("syst_bottom")
      syst_top.Draw("hist")
      stat_top.Draw("histsame")
      stat_bottom.Draw("histsame")
      syst_bottom.Draw("histsame")
      hist_anti.Draw("Lsame")
      hist_sele.Draw("EPsame")
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
      c1.SaveAs("plots/Systematics/SelevsAnti_"+sample+"_"+var+end+".png")
      c1.SaveAs("plots/Systematics/SelevsAnti_"+sample+"_"+var+end+".eps")
      #bias.GetYaxis().SetTitle("% bias")
      #bias.GetXaxis().SetRangeUser(MinX,MaxX)
      #bias.SetLineColor(kBlue+2)
      #bias.SetLineWidth(3)
      #bias.SetName("bias")
      #bias.Draw("histE9")
      #c1.SaveAs("plots/Bias_"+sample+"_"+var+end+".png")
      textfile = open("plots/Table.txt", "w")
      textfile.write(text)
