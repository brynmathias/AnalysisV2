#!/usr/bin/env python

import ROOT as r
from plottingUtils import Print
file = r.TFile.Open("SUSYSignalScan/NLOCrossSections.root")


c1 = Print("TestOut.pdf")
c1.open()
c1.canvas.SetLogz()
for key  in file.GetListOfKeys():
  hist = file.Get(key.GetName())
  hist.SetMinimum(1E-12)
  hist.SetMaximum(1E5)
  hist.Draw("COLZ")
  c1.Print()
  
c1.close()