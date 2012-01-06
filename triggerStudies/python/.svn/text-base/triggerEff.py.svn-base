#!/usr/bin/env python

'''Created by Bryn Mathias
bryn.mathias@cern.ch
'''
import errno

import ROOT as Root
import math
from time import strftime
import os, commands
# from PlottingFunctions import *
# Root.gROOT.SetBatch(True) # suppress the creation of canvases on the screen.. much much faster if over a remote connection
Root.gROOT.SetStyle("Plain") #To set plain bkgds for slides
Root.gROOT.ProcessLine(".L ./Jets30/tdrstyle.C+")

intlumi =35.0 #4.433 #inv pico barns
resultsDir = "./Jets30/"

def GetHist(DataSetName,folder,hist,col,norm,Legend):
    a = Root.TFile.Open(DataSetName) #open the file
    # closeList.append(a) # append the file to the close list
    b = a.Get(folder) #open the directory in the root file
    Hist = b.Get(hist) # get your histogram by name
    if Hist == None : Hist = Root.TH1D()
    if Legend != 0:
      leg.AddEntry(Hist,Legend,"LP") # add a legend entry
    Hist.SetLineWidth(3)
    Hist.SetLineColor(col) #set colour
    Hist.SetBinContent(Hist.GetNbinsX() ,Hist.GetBinContent(Hist.GetNbinsX())+Hist.GetBinContent(Hist.GetNbinsX()+1))
    Hist.SetBinError(Hist.GetNbinsX() ,math.sqrt((Hist.GetBinError(Hist.GetNbinsX()))**2 + (Hist.GetBinError(Hist.GetNbinsX()+1))**2))
    Hist.SetBinContent(Hist.GetNbinsX()+1,0)
    if norm != 0:
       Hist.Scale(intlumi/100.) #if not data normilse to the data by lumi, MC is by default weighted to 100pb-1, if you have changed this change here!
    return Hist

leg = Root.TLegend(0.6, 0.55, 0.9, 0.8)
leg.SetShadowColor(0)
leg.SetBorderSize(0)
leg.SetFillStyle(4100)
leg.SetFillColor(0)
leg.SetLineColor(0)

prelim = Root.TLatex(0.15,0.92,"#scale[0.8]{CMS}")
prelim.SetNDC()
lumi = Root.TLatex(0.45,.82,"#scale[0.8]{#int L dt = 35 pb^{-1}, #sqrt{s} = 7 TeV}")
lumi.SetNDC()


NoCutsEfftxt = Root.TLatex(0.15,0.92,"HT > 250 GeV")
NoCutsEfftxt.SetNDC()
AllCutsEfftxt = Root.TLatex(0.15,0.92,"HT > 350 GeV")
AllCutsEfftxt.SetNDC()
FailNoCutstxt = Root.TLatex(0.15,0.92,"HT > 250 GeV Failures")
FailNoCutstxt.SetNDC()
FailCutstxt = Root.TLatex(0.15,0.92,"HT > 350 GeV Failures")
FailCutstxt.SetNDC()
c1 = Root.TCanvas("canvas","canname",1200,1200)


fold = ["alphaTnumbers150","alphaTnumbers200","alphaTnumbers250","alphaTnumbers300"]
listing = ["all","1","2","3","4","5","6","ge3"]
histlist = ["HadronicAlphaT_","MHTovHT_","HadronicAlphaTGeq3_"]

for fi in fold:
  for hist in histlist:
    for i in listing:
      if hist != "ge3":
        base = GetHist("./MHTovHT/40GeVOffline/AK5Calo_LM0_1.root", fi+"NoTrigger", hist+str(i),1,0,0)
        trig = GetHist("./MHTovHT/40GeVOffline/AK5Calo_LM0_1.root", fi , hist+str(i),1,0,0)
      if i == "ge3":
        base = GetHist("./MHTovHT/40GeVOffline/AK5Calo_LM0_1.root", fi+"NoTrigger", hist+"all",1,0,0)
        baseM = GetHist("./MHTovHT/40GeVOffline/AK5Calo_LM0_1.root", fi+"NoTrigger", hist+"2",1,0,0)
        trig = GetHist("./MHTovHT/40GeVOffline/AK5Calo_LM0_1.root", fi , hist+"all",1,0,0)
        trigM = GetHist("./MHTovHT/40GeVOffline/AK5Calo_LM0_1.root", fi , hist+"2",1,0,0)
        trig.Add(trigM,-1.)
        base.Add(baseM,-1.)
# trigF = GetHist("AK5Calo_JetsNoHTCutTest.root", fi +"F", hist+str(i),1,0,0)
      Eff = Root.TGraphAsymmErrors()
      Eff.BayesDivide(trig,base)
      if hist == "MHTovHT_":
        Eff.GetXaxis().SetTitle("MHT/HT")
        Eff.GetXaxis().SetRangeUser(0.,1.)
        base.GetXaxis().SetRangeUser(0.,1.)
        trig.GetXaxis().SetRangeUser(0.,1.)
      if hist == "HadronicAlphaT_" or hist == "HadronicAlphaTGeq3_":
        Eff.GetXaxis().SetTitle("#alpha_{T}")
        Eff.GetXaxis().SetRangeUser(0.2,1.2)
        base.GetXaxis().SetRangeUser(0.2,1.2)
        trig.GetXaxis().SetRangeUser(0.2,1.2)
      # Eff.GetXaxis().SetTitle("#alpha_{T}")
      Eff.GetYaxis().SetTitle("Eff")
      # Eff.GetXaxis().SetRangeUser(0.45,.8)
      Eff.Draw("apl")
      c1.SaveAs("./MHTovHT/40GeVOffline/"+fi+hist+str(i)+".pdf")
      c1.Clear()
      # c1.SetLogy()
      # base.Draw("hist")
      # c1.SaveAs("./RobThreshTest/40/NoTrigger/"+fi+hist+str(i)+".pdf")
      # c1.Clear()
      # c1.SetLogy()
      # trig.Draw("hist")
      # c1.SaveAs("./RobThreshTest/40/Trigger/"+fi+hist+str(i)+".pdf")
      # c1.Clear()
      # EffF = Root.TGraphAsymmErrors()
      # EffF.BayesDivide(trigF,base)
      # EffF.GetXaxis().SetTitle("#alpha_{T}")
      # EffF.GetYaxis().SetTitle("Eff")
      # EffF.GetXaxis().SetRangeUser(0.45,.6)
      # EffF.Draw("apl")
      # c1.SaveAs("./alphaEffs50P/"+fi+"Fail"+hist+str(i)+".pdf")



