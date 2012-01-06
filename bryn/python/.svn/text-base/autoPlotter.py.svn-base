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
# Root.gROOT.SetStyle("Plain") #To set plain bkgds for slides
# Root.gStyle.SetTitleBorderSize(0)
# Root.gStyle.SetCanvasBorderMode(0)
# Root.gStyle.SetCanvasColor(0)#Sets canvas colour white
# Root.gStyle.SetOptStat(1110)#set no title on Stat box
# Root.gStyle.SetLabelOffset(0.001)
# Root.gStyle.SetLabelSize(0.05)
# Root.gStyle.SetLabelSize(0.05,"Y")#Y axis
# Root.gStyle.SetTitleSize(0.06)
# Root.gStyle.SetTitleW(0.7)
# Root.gStyle.SetTitleH(0.07)
# Root.gStyle.SetOptTitle(1)
# Root.gStyle.SetOptStat(0)
# Root.gStyle.SetAxisColor(1, "XYZ");
# Root.gStyle.SetStripDecimals(Root.kTRUE);
# Root.gStyle.SetTickLength(0.03, "XYZ");
# Root.gStyle.SetNdivisions(510, "XYZ");
# Root.gStyle.SetPadTickX(1);
# Root.gStyle.SetPadTickY(1);
# Root.gStyle.SetLabelColor(1, "XYZ");
# Root.gStyle.SetLabelFont(42, "XYZ");
# Root.gStyle.SetLabelOffset(0.01, "XYZ");
# Root.gStyle.SetLabelSize(0.05, "XYZ");
# Root.gStyle.SetHatchesLineWidth(2)

Root.gROOT.ProcessLine(".L ./tdrstyle.C+")

# Root.gStyle.SetPaperSize(20,20)
# Root.gROOT.ProcessLine(".x /Users/bryn/.root/tdrstyle.C+")
# setTDRStyle()
Root.gStyle.SetLineStyleString(11,"50 25")
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise

#Please enter the integrated lumi for the plots here:
algo = "Calo"
intlumi =17.#4.433 #inv pico barns
# intlumi = 2.947
#intlumi = 7.0
print "The Integrated Luminosity your plots are being scaled to is: ", intlumi , "pb^{-1}"
#Set your output file here
# outputfile = "../pdfs/PlotsForPO38WithTPs/"

# outputfile = "../pdfs/JESFixedTest/"

outputfile = "../2011_17pb/"

ensure_dir(outputfile)


print "you are outputting to: " ,outputfile
#SetWhere your results from your analysis are
resultsDir = "~/Finalresults/" #"/vols/cms02/bm409/SUSYv2/hadronic/results/"+algo

print "you are using the " , algo , " Jet collection"
#close list is a global variable that has the file name appended to it so at the end of each hist loop the open files are closed. It is cleared each time a new hist is called.

def GetHist(DataSetName,col,norm,Legend):
    a = Root.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
    if type(dir) != int:
      b= a.Get(dir)
    else:
      b = a.Get(DirKeys[dir].GetTitle()) #open the directory in the root file
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


def GetHistFromFolder(DataSetName,folder,col,norm,Legend):
    a = Root.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
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





def RatioPlot(Data,BackGround):
  """docstring for RatioPlot"""
  bottom = BackGround.Clone()
  top = Data.Clone()
  top.GetYaxis().SetTitle("data / sim")
  top.Divide(bottom)
  # top.SetTitleSize(0.1, "XYZ");
  # top.SetTitleOffset(0.55, "X");
  # top.SetTitleOffset(0.4, "Y");
  # top.SetLabelSize(0.06,"XY")
  # top.SetTitleXOffset(0.9);
  # top.SetTitleYOffset(0.9);
  top.GetXaxis().SetRangeUser(MinX,MaxX+0.1)
  top.GetYaxis().SetRangeUser(0.,4.0)
  return top

def UnityLine (Data):
  """docstring for RatioPlot"""
  # top = Data.Clone()  #Draw a line though the perfectly matching point
  # unity = Root.TBox(top.GetXaxis().GetBinUpEdge(top.GetXaxis().GetFirst()), 0.89,top.GetXaxis().GetBinUpEdge(top.GetNbinsX()), 1.11);
  unity = Root.TBox(Data.GetBinLowEdge(Data.GetXaxis().GetFirst()), 0.89,Data.GetBinLowEdge(Data.GetXaxis().GetLast())+Data.GetBinWidth(Data.GetXaxis().GetLast()), 1.11)
  unity.SetLineWidth(3);
  unity.SetLineColor(2);
  unity.SetFillColor(2);
  unity.SetFillStyle(3002)
  # unity.Draw();
  return unity
  pass


def PassingCutNumbers(Hist, name ,lowerBound):
  lowbin = Hist.FindBin(lowerBound)
  errorVal = Root.Double(0)
  passingCut = Hist.IntegralAndError(lowbin, Hist.GetNbinsX(), errorVal)
  textLine = "Sample = " + DirKeys[dir].GetTitle()  + "   " + str(Hist.GetName()) + "     " + name +  " , Number passing cut of   " + str(lowerBound) + " is " + "       " + str(passingCut)+ " +/- " + str(errorVal) + "\n"
  CutNumbers.write(textLine)


time = strftime("%Y_%m_%d")
print time
DrawRatio = True
#A file to open and scan for histograms inside directories
RootFileList = ["/Users/bryn/Desktop/AK5"+algo+"_Jets.root"]
# RootFileList = [resultsDir+"/AK5Calo_ExtraJets.root"]

CutNumbers = open(outputfile+"CutTable.txt",'w')



AllPlots = ""
ControlRegonPlots1 = ""
ControlRegonPlots2 = ""
SignalRegonPlots = ""
ControlRegonPlotsAfterAT1 = ""
ControlRegonPlotsAfterAT2 = ""
SignalRegonPlotsAfterAT = ""
SignalRegonPlotsAfterATandDeadEcal = ""
SignalRegonPlotsAfterDeadEcal = ""
SignalRegonPlotsAfterAllCuts = ""
SignalRegonPlotsAfterAtAllCuts = ""
temp = Root.TFile.Open(RootFileList[0])
DirKeys = temp.GetListOfKeys()

HistKeys = [ (dir.ReadObj()).GetListOfKeys() for dir in DirKeys]
HistNames = [ [k.GetName() for k in D] for D in HistKeys]
#Loops though all the histograms that have been read from the first input file, this is done by histogram name
# print HistNames
closeList = []
for dir in range(0,len(DirKeys)):
  # print DirKeys[dir].GetTitle(), dir
  for hist in HistNames[dir]:
    Draw = False
    Root.setTDRStyle()
    DrawNorm = False
    # print DirKeys[dir].GetTitle()
    # if "AllCuts" not in DirKeys[dir].GetTitle() : continue
    # Root.tdrStyle.SetPadRightMargin(0.06)#tweak
    # if "CaloMET_after_alphaT_all" in hist: Draw = True
    if "EffectiveMass_after_alphaT_55_all" in hist: Draw = True
    # if "HT_after_alphaT_all" == hist: Draw = True
    if "BiasedDeltaPhi_after_alphaT_55_all" in hist: Draw = True
    # if "CosDetlaPhi_MHT_MHTBaby__all" in hist: Draw = True
    # if "DPhi_MHT_MHTbaby_AfterAlphaT__all" in hist: Draw = True
    if "BabyJetMHT_all" in hist: Draw = True
    if "BabyJetMHTafterMetCut_all" in hist: Draw = True
    # if "CaloMET_all" in hist: Draw = True
    if "MHTovMET_all" in hist: Draw = True
    if "MHTovMET_afterAlphaT_all" in hist: Draw = True
    # if "Mt2_LeadingJets_all" in hist: Draw = True
    # if "Mt2_all" in hist: Draw = True
    if "HT_after_alphaT_all" == hist : Draw = True
    if "AlphaT_all" == hist: Draw = True
    if "AlphaT_Zoomed_all" == hist: Draw = True
    if "HT_all" == hist: Draw = True
    # if "EffectiveMass_all" in hist: Draw = True
    # if "BiasedDeltaPhi_all" in hist: Draw = True
    # if "MHToverHT_all" in hist: Draw = True
    # if "MHT_all" == hist: Draw = True
    if "JetMultiplicityAfterAlphaT_all" in hist: Draw = True
    if "JetMultiplicity_all" in hist: Draw = True
    # if "JetEta_" in hist: Draw = True
    # if "JetPt_" in hist: Draw = True
    # if "fem__all" in hist: Draw = True
    # if "BabyJetMHTafterMetCut_all" in hist: Draw = True

    # if "__1" in hist: Draw = True
    # if "__2" in hist: Draw = True
    # if "__3" in hist: Draw = True
    # if "__15" in hist: Draw = True
    if not Draw : continue
    if "/" in hist : continue

    leg = Root.TLegend(0.65, 0.45, 0.97, 0.8)
    if "JetMultiplicity_all" == hist: leg2 = Root.TLegend(0.62, 0.55, 0.97, 0.85)

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
    if DrawRatio:
      #Make two pads, one small for the ratio plot and one large for the plot its self
      mainPad = Root.TPad("","",0.01,0.25,0.99,0.99);
      mainPad.SetNumber(1);
      mainPad.Draw();
      ratioPad = Root.TPad("","",0.01,0.05,0.99,0.26);
      ratioPad.SetBottomMargin(0.32);
      ratioPad.SetNumber(2);
      ratioPad.Draw();
    c1.cd(1)
    #make your histograms form each file, read in the files you want below
    # GetHist("RootFile",Colour, scale to lumi 0=false anything else = true, Legend entry)
    #NB the order in which you book the histos is the order in which they appear in the legend
    # temp = dir
    # dir = "350Gevcombined"
    Data = GetHist("/Users/bryn/Desktop/AK5"+algo+"_Jets.root",1,0,"Data")
    # dir = temp
    # Data.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_Jets.root","300_350Gevcombined",1,0,0))
    # Data.Add(GetHist(resultsDir+"/AK5Calo_ExtraJets.root",1,0,"Data"))
    if str(type(Data)) != "<class '__main__.TH1D'>" : continue
    QCD = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_QCD_Pythia6_38.root",Root.kGreen+3,1,"QCD")

    # QCD.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_QCD_Pythia6_38.root","300_350Gevcombined",1,1,0))
    Data.SetMarkerStyle(20)
    Data.SetMarkerSize(1.5)
    Data.SetLineWidth(3)
    Data.SetLineColor(1)
    Data.SetFillColor(1)
    ZJets  = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_zjets_madgraph_4.root",Root.kTeal-7,1,0)
    # ZJets.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_zjets_madgraph_4_4.root","300_350Gevcombined",Root.kTeal-7,1,0))
    Zinv = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_Zinvisible_jets_3.root",91,1,0)
    # Zinv.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_Zinvisible_jets_3_31_3.root","300_350Gevcombined",Root.kTeal-7,1,0))
    Ztotal = ZJets.Clone()
    Ztotal.Add(Zinv)
    Ztotal.SetLineColor(91)
    leg.AddEntry(Ztotal,"Z + Jets","L")

    WJets = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_wjets_madgraph_vols_1.root",Root.kPink+7,1,"W + Jets")
    # WJets.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_wjets_madgraph_vols_1_29.root","300_350Gevcombined",Root.kTeal-7,1,0))
    ttbar = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_ttbarTauola_2.root",Root.kBlue+1,1,"tt + Jets")
    # ttbar.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_ttbarTauola_2_30.root","300_350Gevcombined",Root.kTeal-7,1,0))
    LM0 = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_LM0_5.root",2,1,"LM0")
    LM0.SetLineStyle(9)
    # LM0.SetMarkerStyle(21)

    LM0.SetMarkerColor(2)
    # LM0.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_LM0_5_5.root","300_350Gevcombined",Root.kTeal-7,1,0))
    LM1 = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_LM1_6.root",Root.kPink+7,1,"LM1")
    # LM1.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_LM1_6_6.root","300_350Gevcombined",Root.kTeal-7,1,0))
    LM1.SetLineStyle(2)
    QCD.SetLineWidth(4)
    DrawSM = True
    EWK = ttbar.Clone()
    EWK.Add(WJets)
    EWK.Add(Ztotal)
    EWK.SetLineWidth(3)
    EWK.SetLineColor(Root.kBlue+1)
    if False: #"EffectiveMass_all" == hist or "EffectiveMass_after_alphaT_55_all" == hist :
          leg.RecursiveRemove(Ztotal)
          leg.RecursiveRemove(WJets)
          leg.RecursiveRemove(ttbar)
          LM2 = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_LM2_7.root",3,1,"LM2")
          LM3 = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_LM3_8.root",4,1,"LM3")
          LM4 = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_LM4_9.root",5,1,"LM4")
          LM5 = GetHist(resultsDir+"/NoSmear/AK5"+algo+"_LM5_10.root",6,1,"LM5")
          DrawSM = True



    #Make a histogram of the sum of all the SM backgrounds
    Total = QCD.Clone()
    Total.Add(Zinv)
    Total.Add(ZJets)
    Total.Add(WJets)
    Total.Add(ttbar)
    leg2 = Root.TLegend(0.55, 0.5, 0.97, 0.8)
    if "JetMultiplicity_all" == hist: leg2 = Root.TLegend(0.62, 0.55, 0.97, 0.85)
    if "BiasedDeltaPhi_after_alphaT_all" == hist:# or "AlphaT" in hist :
      Data.Rebin(4)
      QCD.Rebin(4)
      # QCD.SetFillColor(Root.kRed-7)
      # ZJets.Rebin(4)
      # Zinv.Rebin(4)
      # ttbar.Rebin(4)
      LM0.Rebin(4)
      LM1.Rebin(4)
      Total.Rebin(4)

      EWK.Rebin(4)



    Pythia8 = False

    if hist == "MHTovMET_afterAlphaT_all" or hist == "BabyJetMHT_all" or hist == "BabyJetMHTafterMetCut_all" or hist == "BiasedDeltaPhi_after_alphaT_55_all" or hist == "BiasedDeltaPhi_all" :
      Pythia8=GetHist(resultsDir+"/NoSmear/AK5"+algo+"_QCD_Pythia8_38.root",3,1,"QCD Pythia tune 1")
      # Pythia8.Add(GetHistFromFolder(resultsDir+"/AK5"+algo+"_QCD_Pythia8_38.root","300_350Gevcombined",Root.kTeal-7,1,0))
      Pythia8.SetLineWidth(3)
    DrawErrors = True
    drawBackgrounds = True

    if hist == "BiasedDeltaPhi_all" or  "EffectiveMass_after_alphaT_55_all" == hist:
      DrawSM = True
      DrawErrors = True
      drawEWK = True
      drawBackgrounds = False
      Pythia8 = False
      leg2 = Root.TLegend(0.7, 0.5, 0.97, 0.8)
      if "EffectiveMass_after_alphaT_55_all" == hist:
        leg2 = Root.TLegend(0.9, 0.6, 1., 0.8)

      leg2.SetShadowColor(0)
      leg2.SetBorderSize(0)
      leg2.SetFillStyle(4100)
      leg2.SetFillColor(0)
      leg2.SetLineColor(0)
      leg2.AddEntry(Data, "Data", "lp")
      # leg2.AddEntry(QCD, "QCD Pythia tune Z2", "lp")
      # leg2.AddEntry(Pythia8 , "QCD Pythia Z1 tune","lp")
      # leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets" , "l")
      leg2.AddEntry(LM0, "LM0", "p")
      leg2.AddEntry(LM1, "LM1", "lp")
      if "BiasedDeltaPhi_all" == hist:
        Data.Rebin(4)
        Total.Rebin(4)
        QCD.Rebin(4)
        EWK.Rebin(4)
        LM0.Rebin(4)
        LM1.Rebin(4)




    # Systematics
    ScaledUpQCD = GetHist(resultsDir+"/JESplus/AK5"+algo+"_QCD_Pythia6_38.root",Root.kTeal-7,1,0)
    ScaledUpW = GetHist(resultsDir+"/JESplus/AK5"+algo+"_wjets_madgraph_vols_1.root",Root.kTeal-7,1,0)
    ScaledUpZj = GetHist(resultsDir+"/JESplus/AK5"+algo+"_Zinvisible_jets_3.root",Root.kTeal-7,1,0)
    ScaledUpJi = GetHist(resultsDir+"/JESplus/AK5"+algo+"_zjets_madgraph_4.root",Root.kTeal-7,1,0)
    ScaledUptt = GetHist(resultsDir+"/JESplus/AK5"+algo+"_ttbarTauola_2.root",Root.kTeal-7,1,0)

    ScaledUp = ScaledUpQCD.Clone()
    # if "EffectiveMass_after_alphaT_55_all" == hist:
      # ScaledUp = None
      # ScaledUp = QCD.Clone()

    ScaledUp.Add(ScaledUpW)
    ScaledUp.Add(ScaledUpZj)
    ScaledUp.Add(ScaledUpJi)
    ScaledUp.Add(ScaledUptt)
    ScaledDownQCD =GetHist(resultsDir+"/JESminus/AK5"+algo+"_QCD_Pythia6_38.root",Root.kTeal-7,1,0)
    ScaledDownW =  GetHist(resultsDir+"/JESminus/AK5"+algo+"_wjets_madgraph_vols_1.root",Root.kTeal-7,1,0)
    ScaledDownZj = GetHist(resultsDir+"/JESminus/AK5"+algo+"_Zinvisible_jets_3.root",Root.kTeal-7,1,0)
    ScaledDownJi = GetHist(resultsDir+"/JESminus/AK5"+algo+"_zjets_madgraph_4.root",Root.kTeal-7,1,0)
    ScaledDowntt = GetHist(resultsDir+"/JESminus/AK5"+algo+"_ttbarTauola_2.root",Root.kTeal-7,1,0)
    ScaledDown =   ScaledDownQCD.Clone()
    # if "EffectiveMass_after_alphaT_55_all" == hist:
      # ScaledDown = None
      # ScaledDown =   QCD.Clone()

    ScaledDown.Add(ScaledDownW)
    ScaledDown.Add(ScaledDownZj)
    ScaledDown.Add(ScaledDownJi)
    ScaledDown.Add(ScaledDowntt)

    SmearedQCD =GetHist(resultsDir+"/Smear/AK5"+algo+"_QCD_Pythia6_38.root",Root.kTeal-7,1,0)
    SmearedW =  GetHist(resultsDir+"/Smear/AK5"+algo+"_wjets_madgraph_vols_1.root",Root.kTeal-7,1,0)
    SmearedZj = GetHist(resultsDir+"/Smear/AK5"+algo+"_Zinvisible_jets_3.root",Root.kTeal-7,1,0)
    SmearedJi = GetHist(resultsDir+"/Smear/AK5"+algo+"_zjets_madgraph_4.root",Root.kTeal-7,1,0)
    Smearedtt = GetHist(resultsDir+"/Smear/AK5"+algo+"_ttbarTauola_2.root",Root.kTeal-7,1,0)
    Smeared =   SmearedQCD.Clone()
    # if "EffectiveMass_after_alphaT_55_all" == hist:
      # Smeared = None
      # Smeared =   QCD.Clone()
    Smeared.Add(SmearedW)
    Smeared.Add(SmearedZj)
    Smeared.Add(SmearedJi)
    Smeared.Add(Smearedtt)

    blank1 = Root.TH1D()
    blank2 = Root.TH2D()

    if "MHTovMET_afterAlphaT_all" in hist:
      Total.Rebin(4)
      ScaledUp.Rebin(4)
      ScaledDown.Rebin(4)
      Smeared.Rebin(4)



    if "BiasedDeltaPhi_after_alphaT_55_all" == hist or "EffectiveMass_after_alphaT_55_all" == hist:
      if "EffectiveMass_after_alphaT_55_all" == hist:
        Total.Rebin(3)
        ScaledUp.Rebin(3)
        ScaledDown.Rebin(3)
        Smeared.Rebin(3)
      if "BiasedDeltaPhi_after_alphaT_55_all" == hist:
        Total.Rebin(4)
        ScaledUp.Rebin(4)
        ScaledDown.Rebin(4)
        Smeared.Rebin(4)
    # AsymErrors = Systematics(Total,Total,Total,Smeared ,"TGraph")
    AsymErrors = Systematics(Total,ScaledUp,ScaledDown,Smeared ,"TGraph")
    AsymErrors.SetLineColor(Root.kAzure+2)#kTeal+3)
    AsymErrors.SetFillColor(Root.kAzure+2)#kTeal+3)
    AsymErrors.SetLineWidth(3)

    AsymErrors.SetFillStyle(3245)#(3245)

    SMBackGrounds = Systematics(Total,ScaledUp,ScaledDown,Smeared,"TH1")
    if SMBackGrounds.Integral(0,SMBackGrounds.GetNbinsX()) == 0 : Draw = False

    drawEWK = False
    if "AlphaT_all" == hist :
      PassingCutNumbers(Data, "Data"            ,0.55)
      # PassingCutNumbers(SmearedJets, "Data_SMEARED!!!"  ,0.55)
      PassingCutNumbers(Total, "Total Background Stat" ,0.55)
      PassingCutNumbers(ScaledUp, "Total Background scaled up" ,0.55)
      PassingCutNumbers(ScaledDown, "Total Background scaled down" ,0.55)
      PassingCutNumbers(SMBackGrounds, "Total Background Systematic" ,0.55)
      PassingCutNumbers(ttbar, "TTBbar"         ,0.55)
      PassingCutNumbers(ZJets, "ZJets"          ,0.55)
      PassingCutNumbers(WJets, "WJETS"          ,0.55)
      PassingCutNumbers(QCD, "QCD"              ,0.55)
      PassingCutNumbers(Zinv, "Zinv"            ,0.55)
      PassingCutNumbers(LM0, "LM0"              ,0.55)
      PassingCutNumbers(LM1, "LM1"              ,0.55)
    #
    #
    if "HT_all" == hist :
      PassingCutNumbers(Data, "Data"    ,350.)
      # PassingCutNumbers(Data, "Data 250GeV"    ,250.)
    #   PassingCutNumbers(Total, "Total Background Stat" ,250.)
    #   PassingCutNumbers(SMBackGrounds, "Total Background Systematic" ,250.)
    #   PassingCutNumbers(LM0, "LM0"      ,250.)
    #   PassingCutNumbers(LM1, "LM1"      ,250.)
    #   PassingCutNumbers(Data, "JetMET"  ,250.)
    #   PassingCutNumbers(ttbar, "TTBbar" ,250.)
    #   PassingCutNumbers(ZJets, "ZJets"  ,250.)
    #   PassingCutNumbers(WJets, "WJETS"  ,250.)
    #   PassingCutNumbers(QCD, "QCD"      ,250.)
    #   PassingCutNumbers(Zinv, "Zinv"    ,250.)
    #
    # if "MHT_all" == hist :
    #   PassingCutNumbers(Data, "Data"                                 ,140.)
    #   PassingCutNumbers(Total, "Total Background Stat"               ,140.)
    #   PassingCutNumbers(SMBackGrounds, "Total Background Systematic" ,140.)
    #   PassingCutNumbers(LM0, "LM0"                                   ,140.)
    #   PassingCutNumbers(LM1, "LM1"                                   ,140.)
    #   PassingCutNumbers(Data, "JetMET"                               ,140.)
    #   PassingCutNumbers(ttbar, "TTBbar"                              ,140.)
    #   PassingCutNumbers(ZJets, "ZJets"                               ,140.)
    #   PassingCutNumbers(WJets, "WJETS"                               ,140.)
    #   PassingCutNumbers(QCD, "QCD"                                   ,140.)
    #   PassingCutNumbers(Zinv, "Zinv"                                 ,140.)



    hcen=Total.Clone()
    herr=Total.Clone()
    herr.SetLineColor(Root.kTeal+3)
    herr.SetMarkerColor(Root.kAzure+6)
    herr.SetFillColor(Root.kAzure+6)
    # Total.SetFillStyle(3001)
    # Total.SetFillColor(Root.kAzure+6)
    herr.SetLineWidth(3)
    Total.SetLineWidth(5)

    # Total.SetFillColor(Root.kAzure+2)
    Total.SetLineColor(Root.kAzure+6)
    # Total.SetLineColor(Root.kBlue+2)
    # Total.SetFillStyle(3245)
    hcen.SetFillColor(0)
    hcen.SetMarkerColor(Root.kTeal+3)
    hcen.SetLineColor(Root.kTeal+3)
    hcen.SetLineWidth(3)




    #Defind the ranges of the histogram for the two highest histograms ie the data and the total

    MinY = 0.05
    if "AlphaT" in hist: MaxXOrig = Data.GetNbinsX()*Data.GetBinWidth(1)
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
    if "Mt2" in hist: MaxX = 500.
    if "AlphaT" in hist: MaxX = MaxXOrig
    if "Multiplicity" in hist:
      MaxX = 12.
      MinX = 1.
    leg2 = Root.TLegend(0.54, 0.55, 0.97, 0.78)
    if "JetMultiplicity_all" == hist or "JetMultiplicityAfterAlphaT_all" ==hist: leg2 = Root.TLegend(0.55, 0.57, 0.97, 0.78)

    leg2.SetShadowColor(0)
    leg2.SetBorderSize(0)
    leg2.SetFillStyle(4100)
    leg2.SetFillColor(0)
    leg2.SetLineColor(0)
    leg2.AddEntry(Data, "Data", "p")
    AsymErrorsLeg = AsymErrors
    AsymErrorsLeg.SetLineColor(Root.kAzure+6)
    AsymErrorsLeg.SetLineWidth(6)
    leg2.AddEntry(AsymErrors , "Standard Model", "fl")
    if "EffectiveMass" not in hist:
      leg2.AddEntry(QCD, "QCD MultiJet","lp")# " Pythia tune Z2", "lp")
      leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets" , "l")
    leg2.AddEntry(LM0, "LM0", "pl")
    leg2.AddEntry(LM1, "LM1", "l")
    # AsymErrors.SetLineWidth(3)
    if hist == "BiasedDeltaPhi_after_alphaT_55_all" :
      leg2.Clear()
      QCD.SetLineColor(Root.kRed-7)
      MinX = 0.
      MaxX = 3.2
      DrawSM = False
      MaxY = 75.
      MinY = 0.05
      leg2 = Root.TLegend(0.47, 0.58, 0.89, 0.78)
      leg2.SetShadowColor(0)
      leg2.SetBorderSize(0)
      leg2.SetFillStyle(4100)
      leg2.SetFillColor(0)
      leg2.SetLineColor(0)
      leg2.AddEntry(Data, "Data", "p")
      # leg2.AddEntry(QCD, "QCD Pythia tune Z2", "lp")
      QCD.SetFillStyle(3345)
      QCD.SetFillColor(Root.kRed-7)
      Pythia8.SetFillStyle(3354)
      Pythia8.SetFillColor(3)
      # QCD.SetFillStyle(1001)
      QCD.SetFillColor(Root.kRed-7)
      # Pythia8.SetFillStyle(1001)
      Pythia8.SetFillColor(3)
      Data.Rebin(4)
      Pythia8.Rebin(4)
      EWK.Rebin(4)
      QCD.Rebin(4)
      LM0.Rebin(4)
      LM1.Rebin(4)
      # leg2.AddEntry(Pythia8 , "QCD Pythia tune 1","lp")
      drawEWK = True
      drawBackgrounds = False
      DrawErrors = False
      print "biased Dphi bin width",str(QCD.GetXaxis().GetBinWidth(2))
      Pythia8.GetYaxis().SetTitle("Events / 0.2 rad")
      QCD.GetYaxis().SetTitle(    "Events / 0.2 rad")
      EWK.GetYaxis().SetTitle(    "Events / 0.2 rad")
      Total.GetYaxis().SetTitle(  "Events / 0.2 rad")
      Pythia8.GetXaxis().SetTitle("#Delta #phi* (rad)")
      QCD.GetXaxis().SetTitle(    "#Delta #phi* (rad)")
      EWK.GetXaxis().SetTitle(    "#Delta #phi* (rad)")
      Total.GetXaxis().SetTitle(  "#Delta #phi* (rad)")
      # if "AllCut" not in DirKeys[dir].GetTitle():
      leg2.AddEntry(QCD,"QCD MultiJet Pythia 6 tune Z2",'lf')
      leg2.AddEntry(Pythia8,"QCD MultiJet Pythia 8 tune 1",'lf')
      leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets", "lp")
      # leg2.AddEntry(WJets, "W + Jets", "lp")
      # leg2.AddEntry(ttbar, "TTBar", "lp")
      # leg2.AddEntry(AsymErrors, "Standard Model" , "lf")
      leg2.AddEntry(LM0, "LM0", "lp")
      leg2.AddEntry(LM1, "LM1", "lp")
    if  "EffectiveMass" in hist:
      MinX = 400.
      MaxX = 1800.
      MinY = 0.01
      DrawSM = False



    if "JetMultiplicityAfterAlphaT_all" == hist or "JetMultiplicity_all" == hist:
      Total.GetYaxis().SetTitle("Events")
      Total.GetXaxis().SetTitle("N_{Jets}")
      for bin in range(3, Total.GetNbinsX()+1):
        Total.GetXaxis().SetBinLabel(bin, str(int(Total.GetBinLowEdge(bin))))
      Total.GetXaxis().SetRangeUser(2.0,10.0)
      DrawSM = True
      DrawErrors = True
      drawBackgrounds = False
      leg2 = Root.TLegend(0.55, 0.6, 0.9, 0.8)
      leg2.SetShadowColor(0)
      leg2.SetBorderSize(0)
      leg2.SetFillStyle(4100)
      leg2.SetFillColor(0)
      leg2.SetLineColor(0)
      leg2.AddEntry(Data, "Data", "p")
      leg2.AddEntry(AsymErrors , "Standard Model","lf")
      leg2.AddEntry(LM0 , "LM0","lp")
      leg2.AddEntry(LM1 , "LM1","lp")


    if "BabyJetMHT_all" in hist or "BabyJetMHTafterMetCut_all" == hist:
      DrawNorm = True
      DrawSM = False
      MaxX= 240.
      MinX = 0.
      QCD.SetLineColor(Root.kRed-7)
      leg2 = Root.TLegend(0.5, 0.65, 0.99, 0.8)
      leg2.SetShadowColor(0)
      leg2.SetBorderSize(0)
      leg2.SetFillStyle(4100)
      leg2.SetFillColor(0)
      leg2.SetLineColor(0)
      leg2.AddEntry(Data, "Data", "p")
      leg2.AddEntry(QCD, "QCD MultiJet Pythia tune Z2", "lp")
      leg2.AddEntry(Pythia8 , "QCD MultiJet Pythia tune 1","lp")
      Pythia8.GetXaxis().SetTitle("MHT (GeV) [10 < p_{T}< 50 GeV]")
      QCD.GetXaxis().SetTitle("MHT (GeV) [10 < p_{T}< 50 GeV]")
      Total.GetXaxis().SetTitle("MHT (GeV) [10 < p_{T}< 50 GeV]")
      Data.GetXaxis().SetTitle("MHT (GeV) [10 < p_{T}< 50 GeV]")
      Data.GetXaxis().SetTitleOffset(1.25)
      QCD.GetXaxis().SetTitleOffset(1.25)
      Pythia8.GetXaxis().SetTitleOffset(1.25)
      Total.GetXaxis().SetTitleOffset(1.25)
    if "MHTovMET_afterAlphaT_all" in hist:
      QCD.SetLineColor(Root.kRed-7)
      MaxX = 5.
      MinX = 0.0
      DrawSM = False
      MaxY = 500.
      MinY = .06
      leg2 = Root.TLegend(0.35, 0.56, 0.9, 0.77)
      if (DirKeys[dir].GetTitle()) == "250_300Gevcombined": leg2 = Root.TLegend(0.15, 0.56, 0.9, 0.77)
      Data.Rebin(4)
      QCD.Rebin(4)
      Pythia8.Rebin(4)
      ZJets.Rebin(4)
      Zinv.Rebin(4)
      QCD.SetFillStyle(3345)
      QCD.SetFillColor(Root.kRed-7)
      Pythia8.SetFillStyle(3354)
      Pythia8.SetFillColor(3)
      ttbar.Rebin(4)
      EWK.Rebin(4)
      LM0.Rebin(4)
      LM1.Rebin(4)
      QCD.SetFillStyle(3345)
      QCD.SetFillColor(Root.kRed-7)
      Pythia8.GetYaxis().SetTitle("Events/0.2")
      QCD.GetYaxis().SetTitle("Events/0.2")
      Pythia8.GetXaxis().SetTitle("R_{Miss}")
      QCD.GetXaxis().SetTitle("R_{Miss}")
      Pythia8.SetFillStyle(3354)
      Pythia8.SetFillColor(3)
      # QCD.SetFillStyle(1001)
      QCD.SetFillColor(Root.kRed-7)
      # Pythia8.SetFillStyle(1001)
      # Pythia8.SetFillColor(3)
      leg2.SetShadowColor(0)
      leg2.SetBorderSize(0)
      leg2.SetFillStyle(4100)
      leg2.SetFillColor(0)
      leg2.SetLineColor(0)
      leg2.AddEntry(Data, "Data", "p")
      leg2.AddEntry(QCD, "QCD Pythia tune Z2", "lf")
      leg2.AddEntry(Pythia8 , "QCD Pythia tune 1","lf")
      leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets", "lp")
      # leg2.AddEntry(WJets, "W + Jets", "lp")
      # leg2.AddEntry(ttbar, "TTBar", "lp")
      leg2.AddEntry(LM0, "LM0", "lp")
      leg2.AddEntry(LM1, "LM1", "lp")
      drawEWK = True
      drawBackgrounds = False
      DrawSM = False



    if "HT_after_alphaT_all" == hist:
      MinX = 350.
    if "HT_all" == hist:
      MinX = 250.
      Total.GetYaxis().SetTitle("Events / 25 GeV")
    if "AlphaT_all" == hist:
      Total.GetYaxis().SetTitle("Events / 0.025")
      Root.gStyle.SetPadTickY(0)
      Total.GetXaxis().SetNdivisions(6,5,0, Root.kFALSE)
      MinX = 0.0
      MaxX = 1.5
      MaxY = 1e6
      print Total.GetXaxis().GetNdivisions()
    if "EffectiveMass_after_alphaT_55_all" == hist:
      Data.Rebin(3)
      # Pythia8.Rebin(4)
      EWK.Rebin(3)
      # Total.Rebin(3)
      print "EWK binwidth", EWK.GetXaxis().GetBinWidth(2)
      print "Total binwidth", Total.GetXaxis().GetBinWidth(2)
      QCD.Rebin(3)
      LM0.Rebin(3)
      LM1.Rebin(3)
      print "Effective mass bin width",
      # Pythia8.GetYaxis().SetTitle("Events / 0.2 rad")
      QCD.GetYaxis().SetTitle(    "Events / 120 GeV")
      EWK.GetYaxis().SetTitle(    "Events / 120 GeV")
      Total.GetYaxis().SetTitle(  "Events / 120 GeV")
      MaxY = 75.
      MinY = 0.05
      MinX = 500.



    # if (DirKeys[dir].GetTitle()) == "AllCutscombined":
      # print Data.GetXaxis().GetBinWidth(2)
      # for low in range(13,41):
      #   if low%2 != 0:  print "Data  integral from" ,     Data.GetXaxis().GetBinLowEdge(low), "to ",Data.GetXaxis().GetBinUpEdge(Data.GetNbinsX()) , " is" , Data.Integral(low,Data.GetNbinsX())
      #   if low%2 != 0:  print "TTbar integral from" ,   ttbar.GetXaxis().GetBinLowEdge(low), "to ",ttbar.GetXaxis().GetBinUpEdge(Data.GetNbinsX()) , " is" ,  ttbar.Integral(low,Data.GetNbinsX())
      #   if low%2 != 0:  print "WJets integral from" ,   WJets.GetXaxis().GetBinLowEdge(low), "to ",WJets.GetXaxis().GetBinUpEdge(Data.GetNbinsX()) , " is" ,  WJets.Integral(low,Data.GetNbinsX())
      #   if low%2 != 0:  print "ZJets integral from" , Ztotal.GetXaxis().GetBinLowEdge(low), "to ",Ztotal.GetXaxis().GetBinUpEdge(Data.GetNbinsX()) , " is" , Ztotal.Integral(low,Data.GetNbinsX())

    Total.GetXaxis().SetRangeUser(MinX,MaxX)
    # print "Range of Total" , MinX , MaxX
    AsymErrors.GetYaxis().SetRangeUser(MinY,MaxY*5.)
    Total.GetYaxis().SetRangeUser(MinY,MaxY*5.)
    if Pythia8: Pythia8.GetXaxis().SetRangeUser(MinX,MaxX)
    if Pythia8: Pythia8.GetYaxis().SetRangeUser(MinY,MaxY*5.)
    QCD.GetYaxis().SetRangeUser(MinY,MaxY*5.)
    QCD.GetXaxis().SetRangeUser(MinX,MaxX)

    if DrawNorm == True:
      Pythia8.SetTitleOffset(1.3, "Y")
      Pythia8.DrawNormalized("9hist")
      QCD.DrawNormalized("9histsame")
      Data.DrawNormalized("9SAMEP")
      Data.DrawNormalized("AXISSAME")



    #Draw order is important!
    if DrawNorm == False:
      if DrawSM:
        leg.AddEntry(Total,"Standard Model","Lf")
        # leg2.AddEntry(Total,"Standard Model","Lf")
        Total.Draw("9hist")
        Total.SetTitleOffset(1.3, "Y")
        if DrawErrors== True : AsymErrors.Draw("2same")
        QCD.Draw("9SAMEhist")
      # Total.Draw("9histsame")

      if DrawSM == False:
        if Pythia8:
          Pythia8.Draw("9hist")
          Pythia8.SetTitleOffset(1.3, "Y")
          QCD.Draw("9histsame")
        else:
          Total.Draw("9hist")
          Total.SetTitleOffset(1.3, "Y")


      if hist == "MHTovMET_afterAlphaT_all"  or hist == "BabyJetMHT_all" or hist =="BabyJetMHTafterMetCut_all" or hist =="BiasedDeltaPhi_after_alphaT_55_all":
        Pythia8.Draw("9hist")
        # if "MHTovMET_afterAlphaT_all" not in hist: Total.Draw("9samehist")
        # if "MHTovMET_afterAlphaT_all" not in hist and "BabyJetMHTafterMetCut_all" not in hist: AsymErrors.Draw("2same")
        Pythia8.SetTitleOffset(1.3, "Y")
        QCD.Draw("9histsame")
      if "EffectiveMass" in hist:
        AsymErrors.Draw("2same")
        drawEWK = True
        # LM2.Draw("9SAMEh")
        # LM3.Draw("9SAMEh")
        # LM4.Draw("9SAMEh")
        # LM5.Draw("9SAMEh")
        # drawBackgrounds = False
      if drawEWK:
        EWK.Draw("9samehist")
        drawBackgrounds = False
      if drawBackgrounds:
        EWK.Draw("9samehist")
        # Ztotal.Draw("9Sameh")
        # Zinv.Draw("9SAMEh")
        # WJets.Draw("9SAMEh")
        # ttbar.Draw("9SAMEh")
        if "EffectiveMass" in hist:
            leg.RecursiveRemove(Ztotal)
            leg.RecursiveRemove(WJets)
            leg.RecursiveRemove(ttbar)
      LM0.Draw("9SAMEhist")
      LM1.Draw("9SAMEhist")
      #Draw Data last to get the points above everything else
      Data.Draw("9SAMEP")
    njetsText = "#scale[0.8]{2 Jets}"
    if (DirKeys[dir].GetTitle())[0] == "n":
      njetsText = "#scale[0.8]{#geq 3 Jets}"
    njetsMarker = Root.TLatex(0.62 ,0.89,njetsText)
    njetsMarker.SetNDC()

    #Draw Text for histogram titile and for lumi
    prelim = Root.TLatex(0.47,0.89,"#scale[0.8]{CMS 2011}")

    prelim.SetNDC()
    lumi = Root.TLatex(0.47,.82,"#scale[0.8]{#int L dt = "+str(intlumi)+" pb^{-1}, #sqrt{s} = 7 TeV}")
    lumi.SetNDC()

    prelim.Draw()
    lumi.Draw()
    title = Root.TLatex(0.05,0.95,(DirKeys[dir].GetTitle())+"_"+hist[0:-4])
    title.SetNDC()
    # title.Draw()
    lumi.Draw("Same")
    if "combined" not in (DirKeys[dir].GetTitle()):
      njetsMarker.Draw("Same")
    c1.cd(1).Update()

    if  "MHTovMET_afterAlphaT_all" not in hist and "BiasedDeltaPhi_after_alphaT_55_all" not in hist and "BabyJetMHT_all" not in hist and "BabyJetMHTafterMetCut_all" not in hist and"BiasedDeltaPhi_all" not in hist: leg2.Draw()
    # if "EffectiveMass" in  hist :
    #   leg2 = Root.TLegend(0.55, 0.5, 0.97, 0.8)
    #   leg2.SetShadowColor(0)
    #   leg2.SetBorderSize(0)
    #   leg2.SetFillStyle(4100)
    #   leg2.SetFillColor(0)
    #   leg2.SetLineColor(0)
    #   leg2.AddEntry(Data, "Data", "lp")
    #   # leg2.AddEntry(QCD, "QCD", "lp")
    #   # leg2.AddEntry(Total , "Standard Model")
    #   # leg2.AddEntry(LM0, "LM0", "lp")
    #   # leg2.AddEntry(LM1, "LM1", "lp")
    #   # leg2.AddEntry(LM2, "LM2", "lp")
    #   # leg2.AddEntry(LM3, "LM3", "lp")
    #   # leg2.AddEntry(LM4, "LM4", "lp")
    #   # leg2.AddEntry(LM5, "LM5", "lp")
    #   leg2.Draw()

    if "MHTovMET_afterAlphaT_all" in hist or "BiasedDeltaPhi_after_alphaT_55_all" in hist or "BabyJetMHT_all" in hist or "BabyJetMHTafterMetCut_all" in hist or "BiasedDeltaPhi_all" in hist:
      leg2.Draw()

    if DrawRatio:
      c1.cd(2)
      line = UnityLine(Total)
      ratio = RatioPlot(Data,SMBackGrounds)
      ratio.SetLabelSize(0.15, "XYZ")
      ratio.SetTitleSize(0.15, "XYZ")
      ratio.SetTitleOffset(1.05, "X")
      ratio.SetNdivisions(4, "Y")
      ratio.Draw()
      line.Draw("same")


    Data.Draw("9SAMEP")
    c1.cd(1).SetLogy()
    c1.Update()
    # print "Data Starting Bin", Data.GetBinLowEdge(1), MinX
    # print "Bin Width", EWK.GetBinWidth(2)
    # print "Number of Data events", Data.Integral(-1,Data.GetNbinsX())
    # print "Number of ewk events", EWK.Integral(-1,EWK.GetNbinsX())
    # print "Number of QCD events", QCD.Integral(-1,QCD.GetNbinsX())
    # print "LM0 bin width", LM0.GetBinWidth(2)
    # print "ewk bin width", EWK.GetBinWidth(2)
    # print "data bin width", Data.GetBinWidth(2)
    # print "saving hist:", hist, "from dir:",DirKeys[dir].GetTitle()
    # c1.SaveAs(outputfile+(DirKeys[dir].GetTitle())+hist+".png")
    # c1.SaveAs(outputfile+(DirKeys[dir].GetTitle())+hist+".png")
    if Total.GetEntries() == 0: Draw = False
    if Draw :
      c1.cd(1).SetLogy()
      c1.Update()
      c1.Print(outputfile+(DirKeys[dir].GetTitle())+hist+".png")
      c1.Print(outputfile+(DirKeys[dir].GetTitle())+hist+".pdf")
      if "All" == (DirKeys[dir].GetTitle()):
        AllPlots += PlotRow("All"+hist,"nAll"+hist,"Allcombined"+hist)

      if "250_300Gev" == (DirKeys[dir].GetTitle()):
        # if "_after_alphaT" in hist : ControlRegonPlotsAfterAT1 += PlotRow("250_300Gev"+hist,"n250_300Gev"+hist,"250_300Gevcombined"+hist)
        ControlRegonPlots1 += PlotRow("250_300Gev"+hist,"n250_300Gev"+hist,"250_300Gevcombined"+hist)

      if "300_350Gev" == (DirKeys[dir].GetTitle()):
        # if "_after_alphaT" in hist : ControlRegonPlotsAfterAT2 += PlotRow("300_350Gev"+hist,"n300_350Gev"+hist, "300_350Gevcombined"+hist)
        ControlRegonPlots2 += PlotRow("300_350Gev"+hist,"n300_350Gev"+hist,"300_350Gevcombined"+hist)

      if "350Gev" == (DirKeys[dir].GetTitle()):
        # if "_after_alphaT" in hist : SignalRegonPlotsAfterAT += PlotRow("350Gev"+hist,"n350Gev"+hist,"350Gevcombined"+hist)
        SignalRegonPlots += PlotRow("350Gev"+hist,"n350Gev"+hist,"350Gevcombined"+hist)

      if "350Gev_afterDeadEcal" == (DirKeys[dir].GetTitle()):
        # if "_after_alphaT" in hist : SignalRegonPlotsAfterATandDeadEcal += PlotRow("350Gev_afterDeadEcal"+hist,"n350Gev_afterDeadEcal"+hist,"350Gev_afterDeadEcalcombined"+hist)
        SignalRegonPlotsAfterDeadEcal += PlotRow("350Gev_afterDeadEcal"+hist,"n350Gev_afterDeadEcal"+hist,"350Gev_afterDeadEcalcombined"+hist)

      if "AllCuts" == (DirKeys[dir].GetTitle()):
        # if "_after_alphaT" in hist : SignalRegonPlotsAfterAllCuts += PlotRow("AllCuts"+hist,"nAllCuts"+hist,"AllCutscombined"+hist)
        SignalRegonPlotsAfterAllCuts += PlotRow("AllCuts"+hist,"nAllCuts"+hist,"AllCutscombined"+hist)


    for a in closeList :
      a.Close()
    closeList = []
site = Header(intlumi)+BegSec("Signal Region after all cuts")+ SignalRegonPlotsAfterAllCuts+ EndSec()  + BegSec("All Plots") + AllPlots + EndSec() + BegSec("Signal Region Plots") + SignalRegonPlots + EndSec()  + BegSec("Signal Region Plots After Dead Ecal Cut") + SignalRegonPlotsAfterDeadEcal + EndSec() + Footer()
print " Making Web Page now!"
Webpage = open(outputfile+"/StandardPlots.html",'w')
Webpage.write(site)
