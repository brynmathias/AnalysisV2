#!/usr/bin/env python

'''Created by Bryn Mathias
bryn.mathias@cern.ch
'''
import errno

import ROOT as Root
import math
from time import strftime
import os, commands
from PlottingFunctions import *
Root.gROOT.SetBatch(True) # suppress the creation of canvases on the screen.. much much faster if over a remote connection
Root.gROOT.SetStyle("Plain") #To set plain bkgds for slides
Root.gStyle.SetTitleBorderSize(0)
Root.gStyle.SetCanvasBorderMode(0)
Root.gStyle.SetCanvasColor(0)#Sets canvas colour white
Root.gStyle.SetOptStat(1110)#set no title on Stat box
Root.gStyle.SetLabelOffset(0.001)
Root.gStyle.SetLabelSize(0.05)
Root.gStyle.SetLabelSize(0.05,"Y")#Y axis
Root.gStyle.SetTitleSize(0.06)
Root.gStyle.SetTitleW(0.7)
Root.gStyle.SetTitleH(0.07)
Root.gStyle.SetOptTitle(1)
Root.gStyle.SetOptStat(0)
Root.gStyle.SetAxisColor(1, "XYZ");
Root.gStyle.SetStripDecimals(Root.kTRUE);
Root.gStyle.SetTickLength(0.03, "XYZ");
Root.gStyle.SetNdivisions(510, "XYZ");
Root.gStyle.SetPadTickX(1);
Root.gStyle.SetPadTickY(1);
Root.gStyle.SetLabelColor(1, "XYZ");
Root.gStyle.SetLabelFont(42, "XYZ");
Root.gStyle.SetLabelOffset(0.007, "XYZ");
Root.gStyle.SetLabelSize(0.05, "XYZ");
Root.gStyle.SetHatchesLineWidth(3)


def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise

#Please enter the integrated lumi for the plots here:
algo = "Calo"
intlumi = 3.2 #inv pico barns
print "The Integrated Luminosity your plots are being scaled to is: ", intlumi , "pb^{-1}"
#Set your output file here
outputfile = "../pdfs/50GeVJets/SmearJES/"
ensure_dir(outputfile)


print "you are outputting to: " ,outputfile
#SetWhere your results from your analysis are
resultsDir ="../results/Smear/" #"/vols/cms02/bm409/SUSYv2/hadronic/results/"+algo

print "you are using the " , algo , " Jet collection"
#close list is a global variable that has the file name appended to it so at the end of each hist loop the open files are closed. It is cleared each time a new hist is called.

def GetHist(DataSetName,col,norm,Legend):
    a = Root.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
    b = a.Get(DirKeys[dir].GetTitle()) #open the directory in the root file
    Hist = b.Get(hist) # get your histogram by name
    if Hist == None : Hist = Root.TH1D()
    if Legend != 0:
      leg.AddEntry(Hist,Legend,"LP") # add a legend entry
    Hist.SetLineWidth(3)
    Hist.SetLineColor(col) #set colour
    if norm != 0:
       Hist.Scale(intlumi/100.) #if not data normilse to the data by lumi, MC is by default weighted to 100pb-1, if you have changed this change here!
    return Hist

#   /MinBias_TuneD6T_7TeV-pythia6/Spring10-START3X_V26B-v1/GEN-SIM-RECO
#   /MinBias_TuneD6T_7TeV-pythia6/Fall10-START38_V9_preproduction-v1/GEN-SIM-RECODEBUG


def RatioPlot(Data,BackGround):
  """docstring for RatioPlot"""
  bottom = BackGround.Clone()
  top = Data.Clone()
  top.GetYaxis().SetTitle("data / sim")
  top.Divide(bottom)

  top.SetTitleSize(0.1, "XYZ");
  top.SetTitleOffset(0.55, "X");
  top.SetTitleOffset(0.3, "Y");
  top.SetLabelSize(0.06,"XY")

  # top.SetTitleXOffset(0.9);
  # top.SetTitleYOffset(0.9);
  top.GetXaxis().SetRangeUser(MinX,MaxX)
  top.GetYaxis().SetRangeUser(0.,2.0)
  return top

def UnityLine (Data):
  """docstring for RatioPlot"""
  top = Data.Clone()  #Draw a line though the perfectly matching point
  # unity = Root.TBox(top.GetXaxis().GetBinUpEdge(top.GetXaxis().GetFirst()), 0.89,top.GetXaxis().GetBinUpEdge(top.GetNbinsX()), 1.11);
  # top.
  unity = Root.TBox(top.GetBinLowEdge(1+top.FindBin(MinX)), 0.89,top.GetBinLowEdge(1+top.FindBin(MaxX-top.GetBinWidth(2))), 1.11)
  unity.SetLineWidth(2);
  unity.SetLineColor(2);
  unity.SetFillColor(2);
  unity.SetFillStyle(3002)
  unity.Draw();
  return unity
  pass


def PassingCutNumbers(Hist, name ,lowerBound):
  lowbin = Hist.FindBin(lowerBound)
  errorVal = Root.Double(0)
  passingCut = Hist.IntegralAndError(lowbin, Hist.GetNbinsX(), errorVal)
  textLine = "Sample = " + DirKeys[dir].GetTitle() + " " + str(Hist.GetName()) + " " + name +  " , Number passing cut of " + str(lowerBound) +" is "+ " \t " + str(passingCut) + " +/- "  + str(errorVal) + "\n"
  CutNumbers.write(textLine)


time = strftime("%Y_%m_%d")
print time

#A file to open and scan for histograms inside directories
RootFileList = ["../results/AK5"+algo+"_JetMET_ALL.root"]

CutNumbers = open(outputfile+"CutTable.txt",'w')

Webpage = open(outputfile+"StandardPlots"+time+".html",'w')

AllPlots = ""
ControlRegonPlots1 = ""
ControlRegonPlots2 = ""
SignalRegonPlots = ""
ControlRegonPlotsAfterAT1 = ""
ControlRegonPlotsAfterAT2 = ""
SignalRegonPlotsAfterAT = ""

temp = Root.TFile.Open(RootFileList[0])
DirKeys = temp.GetListOfKeys()

HistKeys = [ (dir.ReadObj()).GetListOfKeys() for dir in DirKeys]
HistNames = [ [k.GetName() for k in D] for D in HistKeys]
#Loops though all the histograms that have been read from the first input file, this is done by histogram name

closeList = []
for dir in range(0,len(DirKeys)):
  print DirKeys[dir].GetTitle()
  for hist in HistNames[dir]:
    Draw = False
    if  "all" in hist: Draw = True
    # if DirKeys[dir].GetTitle()[0] != "n" and "_2" in hist: Draw = True
    if "__" in hist: Draw = True
    if not Draw : continue
    if "/" in hist : continue
    leg = Root.TLegend(0.5, 0.4, 0.95, 0.85)
    leg.SetShadowColor(0)
    leg.SetBorderSize(0)
    leg.SetFillStyle(4100)
    leg.SetFillColor(0)
    leg.SetLineColor(0)
    if "PFMetVsMHT" in hist: continue #This is the 2d Histogram in the file, dont want to plot this!
    col=2
    fileno = 1
    MaxY = 1.0#These three are the low terms for the axis and are reset for each histogram see below
    MaxX = 1.0# to see the numbers set by the functions that are defined in the beginning of the program
    MinX = 1000.#
    c1 = Root.TCanvas("canvas"+hist,"canname"+hist,1200,1200)
    #Make two pads, one small for the ratio plot and one large for the plot its self
    mainPad = Root.TPad("","",0.01,0.25,0.99,0.99);
    mainPad.SetNumber(1);
    mainPad.Draw();
    ratioPad = Root.TPad("","",0.01,0.05,0.99,0.26);
    ratioPad.SetNumber(2);
    ratioPad.Draw();

    c1.cd(1)
    #make your histograms form each file, read in the files you want below
    # GetHist("RootFile",Colour, scale to lumi 0=false anything else = true, Legend entry)
    #NB the order in which you book the histos is the order in which they appear in the legend
    Data = GetHist("../results/AK5"+algo+"_JetMET_ALL.root",1,0,"Data")
    QCD = GetHist(resultsDir+"/AK5"+algo+"_QCD_AllPtBins_7TeV_Pythia_1.root",Root.kRed-7,1,"QCD")
    Data.SetMarkerStyle(20)
    Data.SetLineWidth(3)
    Data.SetLineColor(1)
    Data.SetFillColor(1)
    ZJets  = GetHist(resultsDir+"/AK5"+algo+"_zjets_madgraph_9.root",Root.kTeal-7,1,"Z+Jets (Madgraph)")
    Zinv = GetHist(resultsDir+"/AK5"+algo+"_Zinvisible_jets_10.root",91,1,"Z->#nu#nu + Jets")
    WJets = GetHist(resultsDir+"/AK5"+algo+"_wjets_madgraph_8.root",Root.kPink+7,1,"W+Jets")
    ttbar = GetHist(resultsDir+"/AK5"+algo+"_ttbarTauola_11.root",Root.kBlue+1,1,"TTBar")
    LM0 = GetHist(resultsDir+"/AK5"+algo+"_LM0_1.root",2,1,"LM0")
    LM1 = GetHist(resultsDir+"/AK5"+algo+"_LM1_2.root",Root.kRed+3,1,"LM1")
    QCD.SetLineWidth(5)


    if "BiasedDeltaPhi_all" == hist or "BiasedDeltaPhi_after_alphaT_all" == hist:
      Data.Rebin(2)
      QCD.Rebin(2)
      QCD.SetFillColor(Root.kRed-7)
      ZJets.Rebin(2)
      Zinv.Rebin(2)
      ttbar.Rebin(2)
      LM0.Rebin(2)
      LM1.Rebin(2)



    #Make a histogram of the sum of all the SM backgrounds
    Total = QCD.Clone()
    Total.Add(Zinv)
    Total.Add(ZJets)
    Total.Add(WJets)
    Total.Add(ttbar)
    if "AlphaT_all" == hist :
      PassingCutNumbers(Data, "Data"               ,0.0)
      PassingCutNumbers(Total, "Sm Backgrounds"    ,0.0)
      PassingCutNumbers(QCD, "QCD"                 ,0.0)
    if "AlphaT_all" == hist :
     PassingCutNumbers(Data, "Data"               ,0.51)
     PassingCutNumbers(Total, "Sm Backgrounds"    ,0.51)
     PassingCutNumbers(QCD, "QCD"                 ,0.51)

    if "AlphaT_all" == hist :
     PassingCutNumbers(Data, "Data"               ,0.52)
     PassingCutNumbers(Total, "Sm Backgrounds"    ,0.52)
     PassingCutNumbers(QCD, "QCD"                 ,0.52)


    if "AlphaT_all" == hist :
     PassingCutNumbers(Data, "Data"               ,0.53)
     PassingCutNumbers(Total, "Sm Backgrounds"    ,0.53)
     PassingCutNumbers(QCD, "QCD"                 ,0.53)


    if "AlphaT_all" == hist :
     PassingCutNumbers(Data, "Data"               ,0.54)
     PassingCutNumbers(Total, "Sm Backgrounds"    ,0.54)
     PassingCutNumbers(QCD, "QCD"                 ,0.54)


    if "AlphaT_all" == hist :
     PassingCutNumbers(Data, "Data"               ,0.55)
     PassingCutNumbers(Total, "Sm Backgrounds"    ,0.55)
     PassingCutNumbers(QCD, "QCD"                 ,0.55)



      # PassingCutNumbers(LM0, "LM0"                 ,0.0)
      # PassingCutNumbers(LM1, "LM1"                 ,0.0)
      # PassingCutNumbers(Data, "JetMET"             ,0.0)
      # PassingCutNumbers(ttbar, "TTBbar"            ,0.0)
      # PassingCutNumbers(ZJets, "ZJets"             ,0.0)
      # PassingCutNumbers(WJets, "WJETS"             ,0.0)

      # PassingCutNumbers(Zinv, "Zinv"               ,0.0)
    # if "MHT_all" == hist :
    #   PassingCutNumbers(Data, "Data"    ,140.)
    #   PassingCutNumbers(Total, "Sm Backgrounds",140.)
    #   PassingCutNumbers(LM0, "LM0"      ,140.)
    #   PassingCutNumbers(LM1, "LM1"      ,140.)
    #   PassingCutNumbers(Data, "JetMET"  ,140.)
    #   PassingCutNumbers(ttbar, "TTBbar" ,140.)
    #   PassingCutNumbers(ZJets, "ZJets"  ,140.)
    #   PassingCutNumbers(WJets, "WJETS"  ,140.)
    #   PassingCutNumbers(QCD, "QCD"      ,140.)
    #   PassingCutNumbers(Zinv, "Zinv"    ,140.)

    # if "HT_all" == hist :
    #   PassingCutNumbers(Data, "Data"    ,350.)
    #   PassingCutNumbers(Total, "sm Backgrounds" ,350.)
    #   PassingCutNumbers(LM0, "LM0"      ,350.)
    #   PassingCutNumbers(LM1, "LM1"      ,350.)
    #   PassingCutNumbers(Data, "JetMET"  ,350.)
    #   PassingCutNumbers(ttbar, "TTBbar" ,350.)
    #   PassingCutNumbers(ZJets, "ZJets"  ,350.)
    #   PassingCutNumbers(WJets, "WJETS"  ,350.)
    #   PassingCutNumbers(QCD, "QCD"      ,350.)
    #   PassingCutNumbers(Zinv, "Zinv"    ,350.)

    #Some funkey stuff from Henning for drawing the total background with some interesting lines around it
    # Systematics
    ScaledUp = GetHist("../results/JESplus/AK5"+algo+"_QCD_AllPtBins_7TeV_Pythia_1.root",Root.kTeal-7,1,0)
    ScaledDown = GetHist("../results/JESminus/AK5"+algo+"_QCD_AllPtBins_7TeV_Pythia_1.root",Root.kTeal-7,1,0)
    # ScaledUpEta = GetHist("../results/JESetaPlus/AK5"+algo+"_QCD_AllPtBins_7TeV_Pythia_1.root",Root.kTeal-7,1,0)
    # ScaledDownEta = GetHist("../results/JESetaMinus/AK5"+algo+"_QCD_AllPtBins_7TeV_Pythia_1.root",Root.kTeal-7,1,0)
    Total = Systematics(Total,ScaledUp,ScaledDown)
    # Total = Systematics(Total,ScaledUpEta, ScaledDownEta)
    hcen=Total.Clone()
    herr=Total.Clone()
    herr.SetLineColor(Root.kTeal+3)
    herr.SetMarkerColor(Root.kAzure+6)
    herr.SetFillColor(Root.kAzure+6)

    herr.SetLineWidth(3)
    Total.SetLineWidth(3)

    Total.SetFillColor(Root.kAzure+2)
    Total.SetLineColor(Root.kAzure+2)
    Total.SetFillStyle(3245)
    hcen.SetFillColor(0)
    hcen.SetMarkerColor(Root.kTeal+3)
    hcen.SetLineColor(Root.kTeal+3)
    hcen.SetLineWidth(3)

    leg.AddEntry(Total,"Standard Model","Lf")

    #Defind the ranges of the histogram for the two highest histograms ie the data and the total
    if HistogramMinX(Total) < MinX :
       MinX = HistogramMinX(Total)
    if HistogramMaxX(Total) > MaxX :
       MaxX = HistogramMaxX(Total)
    if HistogramMaxY(Total) > MaxY :
       MaxY = HistogramMaxY(Total)

    if HistogramMinX(Data) < MinX :
       MinX = HistogramMinX(Data)
    if HistogramMaxX(Data) > MaxX :
       MaxX = HistogramMaxX(Data)
    if HistogramMaxY(Data) > MaxY :
       MaxY = HistogramMaxY(Data)



    herr.GetXaxis().SetRangeUser(MinX,MaxX)
    herr.GetYaxis().SetRangeUser(0.001,MaxY*5.)
    #Draw order is important!
    herr.Draw("hist")
    hcen.Draw("histsame")
    Total.Draw("9E2same")
    QCD.Draw("9SAMEhist")

    ZJets.Draw("9Sameh")
    Zinv.Draw("9SAMEh")
    #WJets.Draw("9SAMEh")
    ttbar.Draw("9SAMEh")
    LM0.Draw("9SAMEh")
    LM1.Draw("9SAMEh")
    #Draw Data last to get the points above everything else
    Data.Draw("9SAMEP")

    #Draw Text for histogram titile and for lumi
    prelim = Root.TLatex(0.4,0.75,"#scale[0.8]{CMS preliminary 2010}");
    lumi = Root.TLatex(0.4,.9,"#scale[0.8]{#int L dt = " + str(intlumi) + "pb^{-1}, #sqrt{s} = 7 TeV}");
    prelim.SetNDC()
    lumi.SetNDC()
    # prelim.Draw()
    lumi.Draw()
    title = Root.TLatex(0.05,0.95,(DirKeys[dir].GetTitle())+"_"+hist[0:-4])
    title.SetNDC()
    # title.Draw()
    lumi.Draw("Same")

    c1.cd(1).Update()

    leg.Draw()
    c1.cd(2)
    line = UnityLine(Data)
    ratio = RatioPlot(Data,Total)
    ratio.SetLabelSize(0.15, "XYZ")
    ratio.SetTitleSize(0.15, "XYZ")
    ratio.SetTitleOffset(1.05, "X")
    ratio.SetNdivisions(4, "Y");
    ratio.Draw()
    line.Draw()

    if Draw :
      c1.cd(1).SetLogy()
      c1.Update()
      c1.SaveAs(outputfile+(DirKeys[dir].GetTitle())+hist+".png")
      # c1.SaveAs(outputfile+(DirKeys[dir].GetTitle())+hist+".pdf")
      if "All" == (DirKeys[dir].GetTitle()):
        AllPlots += PlotRow("All"+hist,"nAll"+hist)

      if "250_300Gev" == (DirKeys[dir].GetTitle()):
        if "_after_alphaT" in hist : ControlRegonPlotsAfterAT1 += PlotRow("250_300Gev"+hist,"n250_300Gev"+hist)
        else: ControlRegonPlots1 += PlotRow("250_300Gev"+hist,"n250_300Gev"+hist)

      if "300_350Gev" == (DirKeys[dir].GetTitle()):
        if "_after_alphaT" in hist : ControlRegonPlotsAfterAT2 += PlotRow("300_350Gev"+hist,"n300_350Gev"+hist)
        else: ControlRegonPlots2 += PlotRow("300_350Gev"+hist,"n300_350Gev"+hist)

      if "350Gev" == (DirKeys[dir].GetTitle()):
        if "_after_alphaT" in hist : SignalRegonPlotsAfterAT += PlotRow("350Gev"+hist,"n350Gev"+hist)
        else: SignalRegonPlots += PlotRow("350Gev"+hist,"n350Gev"+hist)

    for a in closeList :
      a.Close()
    closeList = []
site = Header(intlumi) + BegSec("All Plots") + AllPlots + EndSec() + BegSec("Controll Region Plots 250-300GeV") + ControlRegonPlots1 + EndSec()  + BegSec("Controll Region 250-300GeV After AlphaT = 0.55 cut") +ControlRegonPlotsAfterAT1 + EndSec() + BegSec("Controll Region Plots 300-350GeV") + ControlRegonPlots2 + EndSec() + BegSec("Controll Region  300-350GeV After AlphaT = 0.55 cut") +ControlRegonPlotsAfterAT2 + EndSec() +  BegSec("Signal Region Plots") + SignalRegonPlots + EndSec() + BegSec("Signal Region After AlphaT = 0.55 cut") + SignalRegonPlotsAfterAT + EndSec() +  Footer()

Webpage.write(site)
