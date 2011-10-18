from ROOT import *

gROOT.SetBatch(True)
gROOT.SetStyle("Plain")
gStyle.SetPaintTextFormat("5.2f")

file = TFile.Open("../../results/AK5Calo/Photon_GGMSignalScan.root")

SignalScan_50 = file.Get("signalScan_met/SignalScan_mChi50")
SignalScan_150 = file.Get("signalScan_met/SignalScan_mChi150")
SignalScan_500 = file.Get("signalScan_met/SignalScan_mChi500")
SignalScan_1000 = file.Get("signalScan_met/SignalScan_mChi1000")

#drawOption="COLZ"
drawOption="TEXT"
c = TCanvas("name", "name", 1000, 1000)
SignalScan_50.Draw(drawOption)
c.SaveAs("SignalScan_50_"+drawOption+".eps")
c.SaveAs("SignalScan_50_"+drawOption+".png")
c.SaveAs("SignalScan_50_"+drawOption+".C")
SignalScan_150.Draw(drawOption)
c.SaveAs("SignalScan_150_"+drawOption+".eps")
c.SaveAs("SignalScan_150_"+drawOption+".png")
c.SaveAs("SignalScan_150_"+drawOption+".C")
SignalScan_500.Draw(drawOption)
c.SaveAs("SignalScan_500_"+drawOption+".eps")
c.SaveAs("SignalScan_500_"+drawOption+".png")
c.SaveAs("SignalScan_500_"+drawOption+".C")
SignalScan_1000.Draw(drawOption)
c.SaveAs("SignalScan_1000_"+drawOption+".eps")
c.SaveAs("SignalScan_1000_"+drawOption+".png")
c.SaveAs("SignalScan_1000_"+drawOption+".C")
