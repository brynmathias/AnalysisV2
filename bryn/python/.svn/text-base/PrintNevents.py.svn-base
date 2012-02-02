#!/usr/bin/env python
import ROOT as Root
import math
from time import strftime
import os, commands, sys
import glob
def GetHist(DataSetName,folder,hist):
    a = Root.TFile.Open(DataSetName) #open the file
    # closeList.append(a) # append the file to the close list
    b = a.Get(folder) #open the directory in the root file
    Hist = b.Get(hist) # get your histogram by name
    # if Hist == None : Hist = Root.TH1D()
    # Hist.SetBinContent(Hist.GetNbinsX() ,Hist.GetBinContent(Hist.GetNbinsX())+Hist.GetBinContent(Hist.GetNbinsX()+1))
    # Hist.SetBinError(Hist.GetNbinsX() ,math.sqrt((Hist.GetBinError(Hist.GetNbinsX()))**2 + (Hist.GetBinError(Hist.GetNbinsX()+1))**2))
    # Hist.SetBinContent(Hist.GetNbinsX()+1,0)
    return Hist

histList = glob.glob(sys.argv[1])

for hist in histList:
  if "Z2" in hist: continue
  if "PU" in hist: continue
  a = GetHist(hist,"AllCuts","HT_after_alphaT_all")
  b = GetHist(hist,"nAllCuts","HT_after_alphaT_all")
  #c = GetHist(hist,"AllCutscombined","HT_after_alphaT_all")

  # tot = a.Integral(1,a.GetNbinsX()) + b.Integral(1,b.GetNbinsX())
  print "Number of events passing cuts for" , hist , "is", a.Integral(1,a.GetNbinsX()) + b.Integral(1,b.GetNbinsX()), "DiJets" ,a.Integral(0,a.GetNbinsX()) ,"NJets", b.Integral(0,b.GetNbinsX())#,"from combiner",c.Integral(0,c.GetNbinsX())
