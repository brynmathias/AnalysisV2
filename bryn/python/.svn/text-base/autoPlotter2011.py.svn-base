#!/usr/bin/env python

'''Created by Bryn Mathias
bryn.mathias@cern.ch
'''
import errno

import ROOT as r
import math
from time import strftime
import os, commands, sys
from PlottingFunctions import *
r.gROOT.SetBatch(True) # suppress the creation of canvases on the screen... much much faster if over a remote connection
import array
r.gROOT.ProcessLine(".L ./tdrstyle.C+")
r.gStyle.SetLineStyleString(11,"50 25")
r.gStyle.SetTitleOffset(0.2,"Y")
r.gStyle.SetTitleSize(0.05, "Y")
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise

#Please enter the integrated lumi for the plots here:
algo = "Calo"
intlumi = 1080.0
#print "The Integrated Luminosity your plots are being scaled to is: ", intlumi , "pb^{-1}"



resultsDir = sys.argv[1]
outputfile = sys.argv[2]
ensure_dir(outputfile)
#print "you are outputting to: " ,outputfile
#SetWhere your results from your analysis are


#print "you are using the " , algo , " Jet collection"
#close list is a global variable that has the file name appended to it so at the end of each hist loop the open files are closed. It is cleared each time a new hist is called.

def GetHist(DataSetName,col,norm,Legend):
    a = r.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
    b = a.Get(DirKeys[dir].GetTitle()) #open the directory in the root file
    Hist = b.Get(hist) # get your histogram by name
    if Hist == None :
      Hist = r.TH1D()
    if Legend != 0:
      leg.AddEntry(Hist,Legend,"LP") # add a legend entry
    if norm != 0:
       Hist.Scale(intlumi/100.) #if not data normilse to the data by lumi, MC is by default weighted to 100pb^{-1}, if you have changed this change here!
    # Now we check that the errors for the bin are correct - effects us in low stats cases!
    newWeight = 1.0
    # //@@ 68% CL intervals from http://www.slac.stanford.edu/BFROOT/www/Statistics/Report/report.pdf
    eh =  [1.15, 1.36, 1.53, 1.73, 1.98, 2.21, 2.42, 2.61, 2.80, 3.00 ]
    el =  [0.00, 1.00, 2.00, 2.14, 2.30, 2.49, 2.68, 2.86, 3.03, 3.19 ]
    if "Zinv" in DataSetName: newWeight =  intlumi / 378.8
    if "TTbar" in DataSetName: newWeight = intlumi / 13500.
    if "WJets" in DataSetName: newWeight = intlumi / 473.3
    if "QCD" not in DataSetName:
      for bin in range(0,Hist.GetNbinsX()):
        if Hist.GetBinContent(bin)/newWeight < 10.:
          n = int(Hist.GetBinContent(bin)/newWeight)
          # print "BinContent is %f, New Error is %f, DataSet is %s, Bin LowEdge is: %f"%(n,eh[n]*newWeight,DataSetName,Hist.GetBinLowEdge(bin))
          Hist.SetBinError(bin,eh[n]*newWeight)
    Hist.SetLineWidth(3)
    Hist.SetLineColor(col) #set colour
    Hist.SetBinContent(Hist.GetNbinsX() ,Hist.GetBinContent(Hist.GetNbinsX())+Hist.GetBinContent(Hist.GetNbinsX()+1))
    Hist.SetBinError(Hist.GetNbinsX() ,math.sqrt((Hist.GetBinError(Hist.GetNbinsX()))**2 + (Hist.GetBinError(Hist.GetNbinsX()+1))**2))
    Hist.SetBinContent(Hist.GetNbinsX()+1,0)
    return Hist

def HistToGraph(Hist):
  """docstring for HistToGraph"""
  # //@@ 68% CL intervals from http://www.slac.stanford.edu/BFROOT/www/Statistics/Report/report.pdf
  eh =  [1.15, 1.36, 1.53, 1.73, 1.98, 2.21, 2.42, 2.61, 2.80, 3.00 ]
  el =  [0.00, 1.00, 2.00, 2.14, 2.30, 2.49, 2.68, 2.86, 3.03, 3.19 ]
  Graph = r.TGraphAsymmErrors(Hist)
  for bin in range(1,Hist.GetNbinsX()):
     n = int(Hist.GetBinContent(bin))
     print n
     if n < 10:
      errorLow,errorHigh = el[n],eh[n]
     if n > 10:
      errorLow , errorHigh = Hist.GetBinError(bin),Hist.GetBinError(bin)
     if n is 0: errorLow, errorHigh = 0.,0.
     print "BinContent is: %d, errorLow,errorHigh: (%f,%f)"%(Hist.GetBinContent(bin),errorLow,errorHigh)
     Graph.SetPointError(bin-1,0.,0.,errorLow,errorHigh)
  return Graph

def PrintBinErrors(Hist):
  """docstring for PrintBinErrors"""
  for bin in range(1,Hist.GetNbinsX()):
    print "BinContent is: %d, errorLow: (%f)"%(Hist.GetBinContent(bin),Hist.GetBinError(bin))
  pass


def GetHistFromFolder(DataSetName,folder,col,norm,Legend):
    a = r.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
    b = a.Get(folder) #open the directory in the root file
    Hist = b.Get(hist) # get your histogram by name
    if Hist == None : Hist = r.TH1D()
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





def RatioPlot(inPu,BackGround):
  """docstring for RatioPlot"""
  # bottom = BackGround.Clone()
  top = inPu.Clone()
  # top.GetYaxis().SetTitle("data / sim")
  top.Divide(BackGround)
  # top.GetXaxis().SetRangeUser(MinX,MaxX+0.1)
  # top.GetYaxis().SetRangeUser(0.,4.0)
  return top

def UnityLine (Data):
  """docstring for RatioPlot"""
  # top = Data.Clone()  #Draw a line though the perfectly matching point
  # unity = r.TBox(top.GetXaxis().GetBinUpEdge(top.GetXaxis().GetFirst()), 0.89,top.GetXaxis().GetBinUpEdge(top.GetNbinsX()), 1.11);
  unity = r.TBox(Data.GetBinLowEdge(Data.GetXaxis().GetFirst()), 0.96,Data.GetBinLowEdge(Data.GetXaxis().GetLast())+Data.GetBinWidth(Data.GetXaxis().GetLast()), 1.04)
  unity.SetLineWidth(3);
  unity.SetLineColor(2);
  unity.SetFillColor(2);
  unity.SetFillStyle(3002)
  # unity.Draw();
  return unity
  pass


def PassingCutNumbers(Hist, name ,lowerBound, Upperbound):
  lowbin = Hist.FindBin(lowerBound)
  highbin = Hist.GetNbinsX()
  # #print Hist.GetBinWidth(10) , "THIS IS THE BIN WIDTH"
  if Upperbound != None:
    highbin = Hist.FindBin(Upperbound) - 1
  # #print "looking in bin", highbin, "This has a low edge of " , Hist.GetBinLowEdge(highbin), "Lower bin is" , lowbin, "THis has a low bin edge of" , Hist.GetBinLowEdge(lowbin)
  errorVal = r.Double(0)
  passingCut = Hist.IntegralAndError(lowbin,highbin, errorVal)
  textLine = "Sample = " + DirKeys[dir].GetTitle()  + "   " + str(Hist.GetName()) + "     " + name +  " , Number bewteen cut of   " + str(lowerBound) + " and " + str(Upperbound) +" is " + "       " + str(passingCut)+ " +/- " + str(errorVal) + "\n"
  CutNumbers.write(textLine)


time = strftime("%Y_%m_%d")
#print time
DrawRatio = False
#A file to open and scan for histograms inside directories
rFileList = [resultsDir+"Data/AK5"+algo+"_Jets.root"]
# rFileList = [resultsDir+""+num+"/AK5Calo_ExtraJets.root"]

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
temp = r.TFile.Open(rFileList[0])
DirKeys = temp.GetListOfKeys()
HistKeys =  (DirKeys[0].ReadObj()).GetListOfKeys()# for dir in DirKeys[0]]
#for a in HistKeys:
#  #print a
HistNames =  [k.GetName() for k in HistKeys]
#Loops though all the histograms that have been read from the first input file, this is done by histogram name
# #print HistNames
closeList = []
# print HistNames
for num in [""]:#,"37","43"]:
  ensure_dir(outputfile+"/"+num)
  for dir in range(0,len(DirKeys)):
    # #print DirKeys[dir].GetTitle(), dir
    for hist in HistNames:
      if DirKeys[dir].GetTitle() == "susyTree": continue
      if "AllCuts" not in DirKeys[dir].GetTitle(): continue
      Draw = False
      DrawLog = True
      r.setTDRStyle()
      DrawNorm = False
      # #print DirKeys[dir].GetTitle()
      # if "AllCuts" not in DirKeys[dir].GetTitle() : continue
      # r.tdrStyle.SetPadRightMargin(0.06)#tweak
      # if "CaloMET_after_alphaT_all" in hist: Draw = True
      if "EffectiveMass_after_alphaT_55_all" in hist:
        Draw = False
        DrawLog = False
      if "HT_after_alphaT_all" == hist:
        Draw = False
        DrawLog = False
      if "BiasedDeltaPhi_after_alphaT_55_all" in hist:
        Draw = False
        DrawLog = False
      # if "CosDetlaPhi_MHT_MHTBaby__all" in hist: Draw = True
      # if "HT_before_alphaT_all" == hist: Draw = True
      # if "DPhi_MHT_MHTbaby_AfterAlphaT__all" in hist: Draw = True
      # if "BabyJetMHT_all" in hist: Draw = True
      # if "BabyJetMHTafterMetCut_all" in hist: Draw = True
      if "Number_Primary_verticies__all" in hist:
        Draw = False#True
        DrawNorm = True
      # if "CaloMET_all" in hist: Draw = True
      # if "MHTovMET_all" in hist: Draw = True
      # if "MHTovMET_afterAlphaT_all" in hist: Draw = True
      if "Mt2_LeadingJets_all" in hist: Draw = False
      if "Mt2_all" in hist: Draw = False
      if "AlphaT_all" ==  hist: Draw = True
      if "AlphaT_Zoomed_all" in hist: Draw = False
      if "HT_all" == hist: Draw = False
      if "EffectiveMass_all" in hist: Draw = False
      # if "BiasedDeltaPhi_all" in hist: Draw = True
      # if "MHToverHT_all" in hist: Draw = True
      if "MHT_all" == hist: Draw = False
      if "JetMultiplicityAfterAlphaT_all" in hist:
        Draw = False
        DrawLog = False
      if "JetMultiplicity_all" in hist: Draw = False
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
      # #print hist , hist , hist , hist , hist , DirKeys[dir].GetTitle() ,DirKeys[dir].GetTitle() ,DirKeys[dir].GetTitle() ,DirKeys[dir].GetTitle() ,DirKeys[dir].GetTitle()
      if Draw:       print hist, num, DirKeys[dir].GetTitle()

      leg = r.TLegend(0.65, 0.55, 0.97, 0.85)
      if "JetMultiplicity_all" == hist: leg2 = r.TLegend(0.57, 0.55, 0.95, 0.85)

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
      c1 = r.TCanvas("canvas"+hist,"canname"+hist,1200,1200)
      if DrawRatio:
        #Make two pads, one small for the ratio plot and one large for the plot its self
        mainPad = r.TPad("m"+hist,"M"+hist,0.01,0.25,0.99,0.99)
        mainPad.SetNumber(1)
        mainPad.Draw()
        ratioPad = r.TPad("r"+hist,"R"+hist,0.01,0.05,0.99,0.26)
        ratioPad.SetBottomMargin(0.32)
        ratioPad.SetNumber(2)
        ratioPad.Draw()
      c1.cd()
      #make your histograms form each file, read in the files you want below
      # GetHist("rFile",Colour, scale to lumi 0=false anything else = true, Legend entry)
      #NB the order in which you book the histos is the order in which they appear in the legend
      Data = GetHist(resultsDir+"/Data"+num+"/AK5"+algo+"_Jets.root",1,0,"Data")
      if str(type(Data)) != "<class '__main__.TH1D'>" : continue
      QCD = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_QCD_All.root",r.kGreen+3,1,"QCD")

      Data.SetMarkerStyle(20)
      Data.SetMarkerSize(1.5)
      Data.SetLineWidth(3)
      Data.SetLineColor(1)
      Data.SetFillColor(1)
      Ztotal  = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_Zinv.root",r.kTeal-7,1,0)
      Ztotal.SetLineColor(91)
      leg.AddEntry(Ztotal,"Z + Jets","L")
      WJets = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_WJets.root",r.kPink+7,1,"W + Jets")
      ttbar = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_TTbar.root",r.kBlue+1,1,"tt + Jets")
      singleTop = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_SingleTop.root",r.kBlue+1,1,"tt + Jets")
      ttbar.Add(singleTop)
      ##LM4 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM4.root",2,1,"LM4")
      #LM4.SetLineStyle(9)
      #LM4.SetMarkerColor(2)
      LM6 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM6.root",r.kPink+7,1,"LM6")
      LM2 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM2.root",r.kPink+7,1,"")
      LM3 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM3.root",r.kPink+7,1,"")
      LM5 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM5.root",r.kPink+7,1,"")
      LM6 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM6.root",r.kPink+7,1,"")
      LM7 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM7.root",r.kPink+7,1,"")

      LM6.SetLineStyle(2)
      QCD.SetLineWidth(4)
      DrawSM = True
      EWK = ttbar.Clone()
      EWK.Add(WJets)
      EWK.Add(Ztotal)
      EWK.SetLineWidth(3)
      EWK.SetLineColor(r.kBlue+1)
      if False: #"EffectiveMass_all" == hist or "EffectiveMass_after_alphaT_55_all" == hist :
            leg.RecursiveRemove(Ztotal)
            leg.RecursiveRemove(WJets)
            leg.RecursiveRemove(ttbar)
            LM2 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM2.root",3,1,"LM2")
            LM3 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM3.root",4,1,"LM3")
            #LM4 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM4.root",5,1,"LM4")
            LM5 = GetHist(resultsDir+"/NoSmear"+num+"/AK5"+algo+"_LM5.root",6,1,"LM5")
            DrawSM = True



      #Make a histogram of the sum of all the SM backgrounds
      Total = QCD.Clone()
      # Total.Add(Zinv)
      Total.Add(Ztotal)
      Total.Add(WJets)
      Total.Add(ttbar)
      leg2 = r.TLegend(0.4, 0.55, 0.95, 0.78)
      #if "JetMultiplicity_all" == hist: leg2 = r.TLegend(0.7, 0.55, 0.99, 0.85)
      if "BiasedDeltaPhi_after_alphaT_all" == hist:# or "AlphaT" in hist :
        Data.Rebin(4)
        QCD.Rebin(4)
        SMBackGrounds.Rebin(4)
        # QCD.SetFillColor(r.kRed-7)
        # ZJets.Rebin(4)
        # Zinv.Rebin(4)
        # ttbar.Rebin(4)
        #LM4.Rebin(4)
        LM6.Rebin(4)
        Total.Rebin(4)

        EWK.Rebin(4)



      Pythia8 = False

      if hist == "MHTovMET_afterAlphaT_all" or hist == "BabyJetMHT_all" or hist == "BabyJetMHTafterMetCut_all" or hist == "BiasedDeltaPhi_after_alphaT_55_all" or hist == "BiasedDeltaPhi_all" :
        Pythia8=r.TH1D("","",Data.GetNbinsX(),Data.GetBinLowEdge(1),Data.GetBinLowEdge(Data.GetNbinsX()))
        # Pythia8=GetHist("~/Finalresults/NoSmear"+num+"/AK5"+algo+"_QCD_Pythia8_38.root",3,1,"QCD Pythia tune 1")
        # Pythia8.Add(GetHistFromFolder(resultsDir+""+num+"/AK5"+algo+"_QCD_Pythia8_38.root","300_350Gevcombined",r.kTeal-7,1,0))
        Pythia8.SetLineWidth(3)
      DrawErrors = True
      drawBackgrounds = False#True

      if hist == "BiasedDeltaPhi_all" or  "EffectiveMass_after_alphaT_55_all" == hist:
        DrawSM = True
        DrawErrors = True
        drawEWK = True
        drawBackgrounds = False
        Pythia8 = False
        leg2 = r.TLegend(0.4, 0.5, 0.95, 0.78)
        if "EffectiveMass_after_alphaT_55_all" == hist:
          leg2 = r.TLegend(0.4, 0.5, 0.95, 0.78)

        leg2.SetShadowColor(0)
        leg2.SetBorderSize(0)
        leg2.SetFillStyle(4100)
        leg2.SetFillColor(0)
        leg2.SetLineColor(0)
        leg2.Clear()
        #leg2.AddEntry(Data, "Data", "lp")
        # leg2.AddEntry(QCD, "QCD Pythia tune Z2", "lp")
        # leg2.AddEntry(Pythia8 , "QCD Pythia Z1 tune","lp")
        # leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets" , "l")
        #leg2.AddEntry(LM4, "LM4", "p")
        #leg2.AddEntry(LM6, "LM6", "lp")
        if "BiasedDeltaPhi_all" == hist:
          Data.Rebin(4)
          Total.Rebin(4)
          QCD.Rebin(4)
          EWK.Rebin(4)
          #LM4.Rebin(4)
          LM6.Rebin(4)




      # Systematics
      ScaledUpQCD = GetHist(resultsDir+"/JESplus"+num+"/AK5"+algo+"_QCD_All.root",r.kTeal-7,1,0)
      ScaledUpW = GetHist(resultsDir+"/JESplus"+num+"/AK5"+algo+"_WJets.root",r.kTeal-7,1,0)
      ScaledUpZj = GetHist(resultsDir+"/JESplus"+num+"/AK5"+algo+"_Zinv.root",r.kTeal-7,1,0)
      # ScaledUpJi = GetHist(resultsDir+"/JESplus"+num+"/AK5"+algo+"_zjets_madgraph_4.root",r.kTeal-7,1,0)
      ScaledUptt = GetHist(resultsDir+"/JESplus"+num+"/AK5"+algo+"_TTbar.root",r.kTeal-7,1,0)
      ScaledUpSingleTop = GetHist(resultsDir+"/JESplus"+num+"/AK5"+algo+"_SingleTop.root",r.kTeal-7,1,0)
      ScaledUptt.Add(ScaledUpSingleTop)
      ScaledUp = ScaledUpQCD.Clone()
      # if "EffectiveMass_after_alphaT_55_all" == hist:
        # ScaledUp = None
        # ScaledUp = QCD.Clone()

      ScaledUp.Add(ScaledUpW)
      ScaledUp.Add(ScaledUpZj)
      # ScaledUp.Add(ScaledUpJi)
      ScaledUp.Add(ScaledUptt)
      ScaledDownQCD =GetHist(resultsDir+"/JESminus"+num+"/AK5"+algo+"_QCD_All.root",r.kTeal-7,1,0)
      ScaledDownW =  GetHist(resultsDir+"/JESminus"+num+"/AK5"+algo+"_WJets.root",r.kTeal-7,1,0)
      ScaledDownZj = GetHist(resultsDir+"/JESminus"+num+"/AK5"+algo+"_Zinv.root",r.kTeal-7,1,0)
      # ScaledDownJi = GetHist(resultsDir+"/JESminus"+num+"/AK5"+algo+"_zjets_madgraph_4.root",r.kTeal-7,1,0)
      ScaledDowntt = GetHist(resultsDir+"/JESminus"+num+"/AK5"+algo+"_TTbar.root",r.kTeal-7,1,0)
      ScaledDownSingleTop = GetHist(resultsDir+"/JESminus"+num+"/AK5"+algo+"_SingleTop.root",r.kTeal-7,1,0)
      ScaledDowntt.Add(ScaledDownSingleTop)
      ScaledDown =   ScaledDownQCD.Clone()
      # if "EffectiveMass_after_alphaT_55_all" == hist:
        # ScaledDown = None
        # ScaledDown =   QCD.Clone()

      ScaledDown.Add(ScaledDownW)
      ScaledDown.Add(ScaledDownZj)
      # ScaledDown.Add(ScaledDownJi)
      ScaledDown.Add(ScaledDowntt)

      SmearedQCD =GetHist(resultsDir+"/Smear"+num+"/AK5"+algo+"_QCD_All.root",r.kTeal-7,1,0)
      SmearedW =  GetHist(resultsDir+"/Smear"+num+"/AK5"+algo+"_WJets.root",r.kTeal-7,1,0)
      SmearedZj = GetHist(resultsDir+"/Smear"+num+"/AK5"+algo+"_Zinv.root",r.kTeal-7,1,0)
      # SmearedJi = GetHist(resultsDir+"/Smear"+num+"/AK5"+algo+"_zjets_madgraph_4.root",r.kTeal-7,1,0)
      Smearedtt = GetHist(resultsDir+"/Smear"+num+"/AK5"+algo+"_TTbar.root",r.kTeal-7,1,0)
      SmearedSingleTop = GetHist(resultsDir+"/Smear"+num+"/AK5"+algo+"_SingleTop.root",r.kTeal-7,1,0)
      Smearedtt.Add(SmearedSingleTop)
      Smeared =   SmearedQCD.Clone()
      # if "EffectiveMass_after_alphaT_55_all" == hist:
        # Smeared = None
        # Smeared =   QCD.Clone()
      Smeared.Add(SmearedW)
      Smeared.Add(SmearedZj)
      # Smeared.Add(SmearedJi)
      Smeared.Add(Smearedtt)

      blank1 = r.TH1D()
      blank2 = r.TH2D()

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
      #AsymErrors = Systematics(EWK,EWK,EWK,EWK ,"TGraph")
      # AsymErrors = Systematics(Total,Total,Total,Total ,"TGraph")
      #AsymErrors = Systematics(Total,Total,Total,Smeared ,"TGraph")
      AsymErrors = Systematics(Total,ScaledUp,ScaledDown,Smeared ,"TGraph")
      AsymErrors.SetLineColor(r.kAzure+2)#kTeal+3)
      AsymErrors.SetFillColor(r.kAzure+2)#kTeal+3)
      AsymErrors.SetLineWidth(3)

      AsymErrors.SetFillStyle(3245)#(3245)

      SMBackGrounds = Systematics(Total,ScaledUp,ScaledDown,Smeared,"TH1")
      # SMBackGrounds = Systematics(Total,Total,Total,Total,"TH1")
      if SMBackGrounds.Integral(0,SMBackGrounds.GetNbinsX()) == 0 : Draw = False

      drawEWK = True

      uplist = [325,375,425,475,575,675,775,875,3000]
      lowlist = [275,325,375,425,475,575,675,775,875]
      if "HT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Data, num+"Data"    ,low,up)
      if "HT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Total, num+"Total Background Stat"  ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Data, num+"Data"    ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Total, num+"Total Background Stat"  ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(singleTop, num+"SingleTop"  ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(ttbar, num+"Top"  ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(WJets, num+"WJETS"   ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(QCD, num+"QCD"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Ztotal, num+"Ztotal" ,low,up)
  #    if "HT_after_alphaT_all" == hist :
  #      for up, low in zip(uplist , lowlist):
  #        PassingCutNumbers(LM4, num+"LM4"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM6, num+"LM6"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM2, num+"LM2"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM3, num+"LM3"       ,low,up)
   #   if "HT_after_alphaT_all" == hist :
   #     for up, low in zip(uplist , lowlist):
   #       PassingCutNumbers(LM4, num+"LM4"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM5, num+"LM5"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM6, num+"LM6"       ,low,up)
      if "HT_after_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM7, num+"LM7"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Data, num+"Data"    ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Total, num+"Total Background Stat"  ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(singleTop, num+"SingleTop"  ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(ttbar, num+"Top"  ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(WJets, num+"WJETS"   ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(QCD, num+"QCD"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(Ztotal, num+"Ztotal" ,low,up)
    #  if "HT_before_alphaT_all" == hist :
    #    for up, low in zip(uplist , lowlist):
    #      PassingCutNumbers(LM4, num+"LM4"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM6, num+"LM6"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM2, num+"LM2"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM3, num+"LM3"       ,low,up)
     # if "HT_before_alphaT_all" == hist :
     #   for up, low in zip(uplist , lowlist):
     #     PassingCutNumbers(LM4, num+"LM4"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM5, num+"LM5"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM6, num+"LM6"       ,low,up)
      if "HT_before_alphaT_all" == hist :
        for up, low in zip(uplist , lowlist):
          PassingCutNumbers(LM7, num+"LM7"       ,low,up)

      hcen=Total.Clone()
      herr=Total.Clone()
      herr.SetLineColor(r.kTeal+3)
      herr.SetMarkerColor(r.kAzure+6)
      herr.SetFillColor(r.kAzure+6)
      # Total.SetFillStyle(3001)
      # Total.SetFillColor(r.kAzure+6)
      herr.SetLineWidth(3)
      Total.SetLineWidth(5)

      # Total.SetFillColor(r.kAzure+2)
      Total.SetLineColor(r.kAzure+6)
      # Total.SetLineColor(r.kBlue+2)
      # Total.SetFillStyle(3245)
      hcen.SetFillColor(0)
      hcen.SetMarkerColor(r.kTeal+3)
      hcen.SetLineColor(r.kTeal+3)
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
      if "Mt2" in hist: MaxX = 1000.
      if "AlphaT" in hist: MaxX = MaxXOrig
      if "Multiplicity" in hist:
        MaxX = 12.
        MinX = 1.
      #leg2 = r.TLegend(0.54, 0.55, 0.97, 0.78)
      #if "JetMultiplicity_all" == hist or "JetMultiplicityAfterAlphaT_all" ==hist: leg2 = r.TLegend(0.55, 0.57, 0.97, 0.78)

      leg2.SetShadowColor(0)
      leg2.SetBorderSize(0)
      leg2.SetFillStyle(4100)
      leg2.SetFillColor(0)
      leg2.SetLineColor(0)
      leg2.AddEntry(Data, "Data", "p")
      AsymErrorsLeg = AsymErrors
      AsymErrorsLeg.SetLineColor(r.kAzure+6)
      AsymErrorsLeg.SetLineWidth(6)
      leg2.AddEntry(AsymErrors , "Standard Model", "fl")
      if "EffectiveMass" not in hist:
        if "JetMultiplicityAfterAlphaT_all" != hist: leg2.AddEntry(QCD, "QCD MultiJet","lp")# " Pythia tune Z2", "lp")
        leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets" , "l")
      #leg2.AddEntry(LM4, "LM4", "pl")
      leg2.AddEntry(LM6, "LM6", "l")
      # AsymErrors.SetLineWidth(3)
      if hist == "BiasedDeltaPhi_after_alphaT_55_all" :
        leg2.Clear()
        QCD.SetLineColor(r.kRed-7)
        MinX = 0.
        MaxX = 3.4
        DrawSM = True #False
        MaxY = 40.0
        MinY = 0.05
        leg2 = r.TLegend(0.4, 0.5, 0.95, 0.78)
        leg2.SetShadowColor(0)
        leg2.SetBorderSize(0)
        leg2.SetFillStyle(4100)
        leg2.SetFillColor(0)
        leg2.SetLineColor(0)
        leg2.AddEntry(Data, "Data", "p")
        # leg2.AddEntry(QCD, "QCD Pythia tune Z2", "lp")
        QCD.SetFillStyle(3345)
        QCD.SetFillColor(r.kRed-7)
        Pythia8.SetFillStyle(3354)
        Pythia8.SetFillColor(3)
        # QCD.SetFillStyle(1001)
        QCD.SetFillColor(r.kRed-7)
        # Pythia8.SetFillStyle(1001)
        Pythia8.SetFillColor(3)
        Data.Rebin(4)
        Pythia8.Rebin(4)
        EWK.Rebin(4)
        QCD.Rebin(4)
        #LM4.Rebin(4)
        LM6.Rebin(4)
        # leg2.AddEntry(Pythia8 , "QCD Pythia tune 1","lp")
        drawEWK = True
        drawBackgrounds = False
        DrawErrors = True
        #print "biased Dphi bin width",str(QCD.GetXaxis().GetBinWidth(2))
        Pythia8.GetYaxis().SetTitle("Events / 0.2 rad")
        QCD.GetYaxis().SetTitle(    "Events / 0.2 rad")
        EWK.GetYaxis().SetTitle(    "Events / 0.2 rad")
        Total.GetYaxis().SetTitle(  "Events / 0.2 rad")
        Pythia8.SetTitleSize(0.05, "Y")
        Pythia8.GetXaxis().SetTitle("#Delta #phi* (rad)")
        QCD.GetXaxis().SetTitle(    "#Delta #phi* (rad)")
        EWK.GetXaxis().SetTitle(    "#Delta #phi* (rad)")
        Total.GetXaxis().SetTitle(  "#Delta #phi* (rad)")
        # if "AllCut" not in DirKeys[dir].GetTitle():
        #leg2.AddEntry(QCD,"QCD MultiJet Pythia 6 tune Z2",'lf')
        #leg2.AddEntry(Pythia8,"QCD MultiJet Pythia 8 tune 1",'lf')
        #leg2.AddEntry(EWK, "t#bar{t}, W, Z + Jets", "lp")
        # leg2.AddEntry(WJets, "W + Jets", "lp")
        # leg2.AddEntry(ttbar, "TTBar", "lp")
        leg2.AddEntry(AsymErrors, "Standard Model" , "lf")
        #leg2.AddEntry(LM4, "LM4", "lp")
        leg2.AddEntry(LM6, "LM6", "lp")
      if  "EffectiveMass" in hist:
        MinX = 400.
        MaxX = 1800.
        MinY = 0.01
        DrawSM = False



      if "JetMultiplicityAfterAlphaT_all" == hist or "JetMultiplicity_all" == hist and Draw:
        Total.GetYaxis().SetTitle("Events")
        Total.GetXaxis().SetTitle("N_{Jets}")
        for bin in range(3, Total.GetNbinsX()+1):
          Total.GetXaxis().SetBinLabel(bin, str(int(Total.GetBinLowEdge(bin))))
        Total.GetXaxis().SetRangeUser(2.0,10.0)
        DrawSM = True
        DrawErrors = True
        drawBackgrounds = True
        #leg2 = r.TLegend(0.55, 0.6, 0.9, 0.8)
        leg2.Clear()
        leg2.SetShadowColor(0)
        leg2.SetBorderSize(0)
        leg2.SetFillStyle(4100)
        leg2.SetFillColor(0)
        leg2.SetLineColor(0)
        leg2.AddEntry(Data, "Data", "p")
        leg2.AddEntry(AsymErrors , "Standard Model","lf")
        #leg2.AddEntry(LM4 , "LM4","lp")
        leg2.AddEntry(LM6 , "LM6","lp")


      if "BabyJetMHT_all" in hist or "BabyJetMHTafterMetCut_all" == hist:
        DrawNorm = True
        DrawSM = False
        MaxX= 240.
        MinX = 0.
        QCD.SetLineColor(r.kRed-7)
        leg2 = r.TLegend(0.5, 0.65, 0.99, 0.8)
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
        QCD.SetLineColor(r.kRed-7)
        MaxX = 5.
        MinX = 0.0
        DrawSM = False
        # MaxY = 500.
        MinY = .06
        leg2 = r.TLegend(0.35, 0.56, 0.9, 0.77)
        if (DirKeys[dir].GetTitle()) == "250_300Gevcombined": leg2 = r.TLegend(0.15, 0.56, 0.9, 0.77)
        # Data.Rebin(4)
        # QCD.Rebin(4)
        # Pythia8.Rebin(4)
        # Ztotal.Rebin(4)
        # Zinv.Rebin(4)
        QCD.SetFillStyle(3345)
        QCD.SetFillColor(r.kRed-7)
        Pythia8.SetFillStyle(3354)
        Pythia8.SetFillColor(3)
        # ttbar.Rebin(4)
        # EWK.Rebin(4)
        # LM4.Rebin(4)
        # LM6.Rebin(4)
        QCD.SetFillStyle(3345)
        QCD.SetFillColor(r.kRed-7)
        Pythia8.GetYaxis().SetTitle("Events/0.2")
        QCD.GetYaxis().SetTitle("Events/0.2")
        Pythia8.GetXaxis().SetTitle("R_{Miss}")
        QCD.GetXaxis().SetTitle("R_{Miss}")
        Pythia8.SetFillStyle(3354)
        Pythia8.SetFillColor(3)
        # QCD.SetFillStyle(1001)
        QCD.SetFillColor(r.kRed-7)
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
        leg2.AddEntry(LM4, "LM4", "lp")
        leg2.AddEntry(LM6, "LM6", "lp")
        drawEWK = True
        drawBackgrounds = False
        DrawSM = False



      if "HT_after_alphaT_all" == hist:
        MinX = 250.
        MaxX = 1500.
      if "HT_all" == hist:
        MinX = 250.
        Total.GetYaxis().SetTitle("Events / 25 GeV")
      if "AlphaT_all" == hist:
        Total.GetYaxis().SetTitle("Events / 0.025")
        r.gStyle.SetPadTickY(0)
        # Total.GetXaxis().SetNdivisions(6,5,0, r.kFALSE)
        MinX = 0.0
        MaxX = 25.0
# Data.SetBinContent(Data.GetNbinsX(), Data.GetBinContent(Data.GetNbinsX()) + Data.GetBinContent(Data.GetNbinsX() +1) )
        # MaxY = 1e6
        #print Total.GetXaxis().GetNdivisions()
      if "EffectiveMass_after_alphaT_55_all" == hist:
        Data.Rebin(3)
        # Pythia8.Rebin(4)
        EWK.Rebin(3)
        # Total.Rebin(3)
        #print "EWK binwidth", EWK.GetXaxis().GetBinWidth(2)
        #print "Total binwidth", Total.GetXaxis().GetBinWidth(2)
        QCD.Rebin(3)
        #LM4.Rebin(3)
        LM6.Rebin(3)
        #print "Effective mass bin width",
        # Pythia8.GetYaxis().SetTitle("Events / 0.2 rad")
        QCD.GetYaxis().SetTitle(    "Events / 120 GeV")
        EWK.GetYaxis().SetTitle(    "Events / 120 GeV")
        Total.GetYaxis().SetTitle(  "Events / 120 GeV")
        # MaxY = 75.
        MinY = 0.05
        MinX = 500.



      Total.GetXaxis().SetRangeUser(MinX,MaxX)
      # #print "Range of Total" , MinX , MaxX
      AsymErrors.GetYaxis().SetRangeUser(MinY,MaxY*2.)
      Total.GetYaxis().SetRangeUser(MinY,MaxY*2.0)
      if Pythia8: Pythia8.GetXaxis().SetRangeUser(MinX,MaxX)
      if Pythia8: Pythia8.GetYaxis().SetRangeUser(MinY,MaxY*2.0)
      QCD.GetYaxis().SetRangeUser(MinY,MaxY*2.0)
      QCD.GetXaxis().SetRangeUser(MinX,MaxX)

      if "MHTovMET_afterAlphaT_all" == hist:
        Pythia8.GetXaxis().SetRangeUser(MinX,MaxX)
        QCD.GetXaxis().SetRangeUser(MinX,MaxX)
        Data.GetXaxis().SetRangeUser(MinX,MaxX)
        Pythia8.GetXaxis().SetRangeUser(MinX,MaxX)

      if hist == "BiasedDeltaPhi_after_alphaT_55_all" :
        Data.GetXaxis().SetRangeUser(0.,3.2)
        QCD.GetXaxis().SetRangeUser(0.,3.2)
        Pythia8.GetXaxis().SetRangeUser(0.,3.2)
        Data.GetXaxis().SetRangeUser(0.,3.2)
        Data.GetXaxis().SetRangeUser(0.,3.2)
        Data.GetXaxis().SetRangeUser(0.,3.2)

      # if "after" in hist:
        # c1.SetLogy(r.kFlase)
      drawEWK = False
      Data = HistToGraph(Data)
      # asdf = PrintBinErrors(Data)
      if DrawNorm == True:
        # Pythia8.SetTitleOffset(1.3, "Y")
        # Pythia8.DrawNormalized("9hist")
        QCD.DrawNormalized("9hist")
        Data.DrawNormalized("9SAMEP")
        Data.DrawNormalized("AXISSAME")



      #Draw order is important!
      if DrawNorm == False:
        if DrawSM:
          leg.AddEntry(Total,"Standard Model","Lf")
          # leg2.AddEntry(Total,"Standard Model","Lf")
          Total.Draw("9hist")
          Total.SetTitleOffset(1.3, "Y")
          if DrawErrors == True : AsymErrors.Draw("2same")
          QCD.Draw("9SAMEhist")
          #Total.Draw("9histsame")

        if DrawSM == False:
          if Pythia8:
            QCD.Draw("9hist")
            QCD.SetTitleOffset(1.3, "Y")
            Pythia8.Draw("9histsame")
            if DrawErrors == True : AsymErrors.Draw("2same")
            # QCD.SetTitleOffset(1.3, "Y")
          else:
            Total.Draw("9hist")
            Total.SetTitleOffset(1.3, "Y")
            if DrawErrors == True : AsymErrors.Draw("2same")

        if hist == "MHTovMET_afterAlphaT_all"  or hist == "BabyJetMHT_all" or hist =="BabyJetMHTafterMetCut_all" or hist =="BiasedDeltaPhi_after_alphaT_55_all" and Draw:
          Pythia8.Draw("9hist")
          if "MHTovMET_afterAlphaT_all" not in hist: Total.Draw("9samehist")
          Pythia8.SetTitleOffset(1.3, "Y")
      #    QCD.Draw("9histsame")
          if DrawErrors == True :
            AsymErrors.Draw("2same")
            Total.Draw("2samehist")
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
        #LM4.Draw("9SAMEhist")
        LM6.Draw("9SAMEhist")
        #Draw Data last to get the points above everything else
        #Total.Draw("9samehist")
      EWK.Draw("9SAMEhist")
      Data.Draw("9SAMEP")
      njetsText = "#scale[0.8]{2 Jets}"
      if (DirKeys[dir].GetTitle())[0] == "n":
        njetsText = "#scale[0.8]{#geq 3 Jets}"
      njetsMarker = r.TLatex(0.62 ,0.89,njetsText)
      njetsMarker.SetNDC()

      #Draw Text for histogram titile and for lumi
      prelim = r.TLatex(0.47,0.87,"#scale[0.8]{CMS}\n1.1fb^{-1}\n7 TeV")
      cms = r.TLatex(0.77,0.88, "CMS")
      lumi = r.TLatex(0.77,0.83,"1.1fb^{-1}")
      energy = r.TLatex(0.77,0.79,"7 TeV")
      cms.SetNDC()
      lumi.SetNDC()
      energy.SetNDC()
      cms.Draw("same")
      lumi.Draw("same")
      energy.Draw("same")
      #prelim.SetNDC()
      #lumi = r.TLatex(0.47,.87,"#scale[0.8]{#int L dt = 1.1 fb^{-1}, #sqrt{s} = 7 TeV}")
      #lumi.SetNDC()

      #prelim.Draw("same")
      #lumi.Draw("same")
      title = r.TLatex(0.05,0.95,(DirKeys[dir].GetTitle())+"_"+hist[0:-4])
      title.SetNDC()
      # title.Draw()
      #lumi.Draw("Same")
      if "combined" not in (DirKeys[dir].GetTitle()):
        njetsMarker.Draw("Same")
      c1.Update()

      if  "MHTovMET_afterAlphaT_all" not in hist and "BiasedDeltaPhi_after_alphaT_55_all" not in hist and "BabyJetMHT_all" not in hist and "BabyJetMHTafterMetCut_all" not in hist and"BiasedDeltaPhi_all" not in hist: leg2.Draw()


      if "MHTovMET_afterAlphaT_all" in hist or "BiasedDeltaPhi_after_alphaT_55_all" in hist or "BabyJetMHT_all" in hist or "BabyJetMHTafterMetCut_all" in hist or "BiasedDeltaPhi_all" in hist:
        leg2.Draw()

      if DrawRatio:
        ratioPad.cd()
        ratioPad.Clear()
        print "padname", ratioPad.GetName()
        # c1.cd(2).Clear()
        # ratioPad.Update()
        line = UnityLine(Total)
        ratio = RatioPlot(GetHist(resultsDir+"/Data"+num+"/AK5"+algo+"_Jets.root",1,0,0),SMBackGrounds)
        # a = r.TH1D("a","b",1000,0.,10.)
        # a.GetXaxis().SetRangeUser(0.,1.5)
        # a.GetYaxis().SetRangeUser(-1.,1e4)
        # a.Draw()
        # ratio.SetLabelSize(0.15, "XYZ")
        # ratio.SetTitleSize(0.15, "XYZ")
        # ratio.SetTitleOffset(1.05, "X")
        # ratio.SetNdivisions(4, "Y")
        ratio.Draw("hist9")
        line.Draw("same")
      if hist == "Number_Primary_verticies__all" and (DirKeys[dir].GetTitle()) == "Allcombined":
        vertTot = Data.Integral(0,-1)
        vertDist =[]
        vertDistNorm =[]
        #print "Total number of events",Data.Integral(0,-1)
        for bin in range(1,Data.GetNbinsX()):
          vertDist.append(Data.Integral(bin-1,bin))
        #print vertDist
        for i in vertDist:
          vertDistNorm.append(i/vertTot)
        #print vertDistNorm
      Data.Draw("SAMEP")
      if DrawLog : c1.SetLogy()
      c1.Update()
      if Total.GetEntries() == 0: Draw = False
      if Draw :
        if DrawLog : c1.SetLogy()
        c1.Update()
        c1.Print(outputfile+"/"+num+"/"+(DirKeys[dir].GetTitle())+hist+".png")
        c1.Print(outputfile+"/"+num+"/"+(DirKeys[dir].GetTitle())+hist+".pdf")
        c1.SaveAs(outputfile+"/"+num+"/"+(DirKeys[dir].GetTitle())+hist+".C")
        c1.Clear()
        # #print "Saving histogram now!!!"
        if "All" == (DirKeys[dir].GetTitle()):
          AllPlots += PlotRow("All"+hist,"nAll"+hist,"Allcombined"+hist)

        if "275_325Gev" == (DirKeys[dir].GetTitle()):
          # if "_after_alphaT" in hist : ControlRegonPlotsAfterAT1 += PlotRow("250_300Gev"+hist,"n250_300Gev"+hist,"250_300Gevcombined"+hist)
          ControlRegonPlots1 += PlotRow("275_325Gev"+hist,"n275_325Gev"+hist,"275_325Gevcombined"+hist)

        if "325_375Gev" == (DirKeys[dir].GetTitle()):
          # if "_after_alphaT" in hist : ControlRegonPlotsAfterAT2 += PlotRow("300_350Gev"+hist,"n300_350Gev"+hist, "300_350Gevcombined"+hist)
          ControlRegonPlots2 += PlotRow("325_375Gev"+hist,"n325_375Gev"+hist,"325_375Gevcombined"+hist)

        if "375Gev" == (DirKeys[dir].GetTitle()):
          # if "_after_alphaT" in hist : SignalRegonPlotsAfterAT += PlotRow("350Gev"+hist,"n350Gev"+hist,"350Gevcombined"+hist)
          SignalRegonPlots += PlotRow("375Gev"+hist,"n375Gev"+hist,"375Gevcombined"+hist)

        if "375Gev_afterDeadEcal" == (DirKeys[dir].GetTitle()):
          # if "_after_alphaT" in hist : SignalRegonPlotsAfterATandDeadEcal += PlotRow("350Gev_afterDeadEcal"+hist,"n350Gev_afterDeadEcal"+hist,"350Gev_afterDeadEcalcombined"+hist)
          SignalRegonPlotsAfterDeadEcal += PlotRow("375Gev_afterDeadEcal"+hist,"n375Gev_afterDeadEcal"+hist,"375Gev_afterDeadEcalcombined"+hist)

        if "AllCuts" == (DirKeys[dir].GetTitle()):
          # if "_after_alphaT" in hist : SignalRegonPlotsAfterAllCuts += PlotRow("AllCuts"+hist,"nAllCuts"+hist,"AllCutscombined"+hist)
          SignalRegonPlotsAfterAllCuts += PlotRow("AllCuts"+hist,"nAllCuts"+hist,"AllCutscombined"+hist)


      for a in closeList :
        a.Close()
      closeList = []
  # #print SignalRegonPlotsAfterAllCuts
  # site0 =
  site1 = Header(intlumi,resultsDir)+ BegSec("All Plots") + AllPlots + EndSec() + Footer()
  site2 = Header(intlumi,resultsDir)+ BegSec("Signal Region Plots") + SignalRegonPlots + EndSec()  + Footer()
  site3 = Header(intlumi,resultsDir)+ BegSec("Signal Region Plots After Dead Ecal Cut") + SignalRegonPlotsAfterDeadEcal + EndSec()  + Footer()
  print " Making Web Page now!"
  Webpage0 = open(outputfile+"/"+num+"/AllCuts.html",'w')
  Webpage1 = open(outputfile+"/"+num+"/Inclusive.html",'w')
  Webpage2 = open(outputfile+"/"+num+"/HTG375GeV.html",'w')
  Webpage3 = open(outputfile+"/"+num+"/DeadEcalCut375GeV.html",'w')
  Webpage0.write(Header(intlumi,resultsDir)+BegSec("Signal Region after all cuts")+ SignalRegonPlotsAfterAllCuts+ EndSec()  + Footer())
  Webpage1.write(site1)
  Webpage2.write(site2)
  Webpage3.write(site3)
