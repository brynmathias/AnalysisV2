from ROOT import *

gROOT.SetBatch(True)
gROOT.SetStyle("Plain")

#jetalgo = "calo"
jetalgo = "pf"
file = TFile.Open("../../results/TriggerEfficiency_PhotonHad_uptoRun163817_"+jetalgo+".root")

ht200 = file.Get("trigger200/HT")
ht300 = file.Get("trigger300/HT")

ht200.Sumw2()
ht300.Sumw2()

efficiency = ht300.Clone()
efficiency.Divide(ht300, ht200, 1, 1, "B")
efficiency.SetMarkerStyle(20)
efficiency.SetMarkerColor(1)
efficiency.GetYaxis().SetTitle("Efficiency")
#efficiency.GetXaxis().SetRangeUser(200.,500.)
#efficiency.GetXaxis().SetRangeUser(300.,350.)
efficiency.GetXaxis().SetRangeUser(300.,400.)
efficiency.GetYaxis().SetRangeUser(0.5,1.)
efficiency.SetStats(0)

c = TCanvas("name", "name", 1000, 1000)
efficiency.Draw("E")
c.SaveAs("TriggerEfficiency-HT-"+jetalgo+"-zoomed.png")
c.SaveAs("TriggerEfficiency-HT-"+jetalgo+"-zoomed.eps")
