#!/usr/bin/env python

'''Created by Bryn Mathias
bryn.mathias@cern.ch
'''
import errno

import ROOT as Root
import math
from time import strftime
import os, commands, sys
from PlottingFunctions import *
Root.gROOT.SetBatch(True) # suppress the creation of canvases on the screen... much much faster if over a remote connection

Root.gROOT.ProcessLine(".L ./tdrstyle.C+")
Root.gStyle.SetLineStyleString(11,"50 25")
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise


# Global Close List
closeList = []
intlumi = 248.1

leg = Root.TLegend(0.65, 0.45, 0.97, 0.8)
leg.SetShadowColor(0)
leg.SetBorderSize(0)
leg.SetFillStyle(4100)
leg.SetFillColor(0)
leg.SetLineColor(0)

def GetAllhistos(inFile):
  temp = Root.TFile.Open(inFile)
  DirKeys = temp.GetListOfKeys()
  print DirKeys
  # histKeys =
  histList = [k.GetName() for k in (DirKeys[0].ReadObj()).GetListOfKeys()]
  return histList

def GetAllSubFiles(inFile):
  """docstring for GetAllSubFiles"""
  temp = Root.TFile.Open(inFile)
  DirKeys = temp.GetListOfKeys()
  DirList = []
  for d in DirKeys:
    DirList.append(d.GetName())
  return DirList

def GethistFromFolder(DataSetName,folder,hist,col,norm,Legend):
    a = Root.TFile.Open(DataSetName) #open the file
    closeList.append(a) # append the file to the close list
    b = a.Get(folder) #open the directory in the root file
    hist = b.Get(hist) # get your histogram b4y name
    if hist == None : hist = Root.TH1D()
    if Legend != 0:
      leg.AddEntry(hist,Legend,"LP") # add a legend entry
    hist.SetLineWidth(3)
    hist.SetLineColor(col) #set colour
    hist.SetBinContent(hist.GetNbinsX() ,hist.GetBinContent(hist.GetNbinsX())+hist.GetBinContent(hist.GetNbinsX()+1))
    hist.SetBinError(hist.GetNbinsX() ,math.sqrt((hist.GetBinError(hist.GetNbinsX()))**2 + (hist.GetBinError(hist.GetNbinsX()+1))**2))
    hist.SetBinContent(hist.GetNbinsX()+1,0)
    if norm != 0:
       hist.Scale(intlumi/100.) #if not data normilse to the data by lumi, MC is by default weighted to 100pb-1, if you have changed this change here!
    return hist



def PassingCutNumbers(Hist, name ,lowerBound, Upperbound):
  lowbin = Hist.FindBin(lowerBound)
  highbin = Hist.GetNbinsX()
  # print Hist.GetBinWidth(10) , "THIS IS THE BIN WIDTH"
  if Upperbound != None:
    highbin = Hist.FindBin(Upperbound) - 1
  # print "looking in bin", highbin, "This has a low edge of " , Hist.GetBinLowEdge(highbin), "Lower bin is" , lowbin, "THis has a low bin edge of" , Hist.GetBinLowEdge(lowbin)
  errorVal = Root.Double(0)
  passingCut = Hist.Integral(lowbin,highbin) #Hist.IntegralAndError(lowbin,highbin, errorVal)
  print passingCut
  textLine = "Sample = "  +  "   " + str(Hist.GetName()) + "     " + name +  " , Number bewteen cut of   " + str(lowerBound) + " and " + str(Upperbound) +" is " + "       " + str(passingCut)+ " +/- " + str(errorVal) + "\n"
  print textLine
  CutNumbers.write(textLine)



resultsDir = ["../results"]
outdirTmp = "../Plots/"
CutNumbers = open(outdirTmp+"CutTable.txt",'w')
histList = ["HT_aftar_AlphaT_all"]#"JetMultiplicityAfterAlphaT_all",
JetThreshList = ["","37","43"]
for num in JetThreshList:
  for dir in ["AllCutscombined"]:# GetAllSubFiles("../results/Data/AK5Calo_Jets.root"): 
   CutNumbers = open(out+"CutTable.txt",'w')
   if dir == "susyTree" : continue
    for hist in histList:
      outdir = outdirTmp
      # print dir,num,hist
      Data =  GethistFromFolder(resultsDir[0]+ "/Data"+num+"/AK5Calo_Jets.root",dir,hist,1,0,"Data")
      MCCentral = GethistFromFolder( resultsDir[0]+"/NoSmear"+num+"/AK5Calo_QCD_All.root",dir,hist,2,intlumi,"MC_Central" )
      MCCentral.Add( GethistFromFolder(resultsDir[0]+"/NoSmear"+num+"/AK5Calo_SingleTop.root",dir,hist,1,intlumi,0) )
      MCCentral.Add( GethistFromFolder(resultsDir[0]+"/NoSmear"+num+"/AK5Calo_TTbar.root",dir,hist,1,intlumi,0) )
      MCCentral.Add( GethistFromFolder(resultsDir[0]+"/NoSmear"+num+"/AK5Calo_WJets.root",dir,hist,1,intlumi,0) )
      MCCentral.Add( GethistFromFolder(resultsDir[0]+"/NoSmear"+num+"/AK5Calo_Zinv.root",dir,hist,1,intlumi,0) )
      c1 = Root.TCanvas("canvas"+hist,"canname"+hist,1200,1200)
      print "Data",dir,num,hist,Data.Integral(0,-1)#, errorValDa),"+/-",errorValDa
      print "MC",dir,num,hist, MCCentral.Integral(0,-1)#, errorValMC),"+/-",errorValMC
      c1.cd(1)
      Data.Draw("p")
      MCCentral.Draw("histsame")
      leg.Draw("same")
      outdir = outdir+"/"+num+"/"
      ensure_dir(outdir)
      c1.SaveAs(outdir+"/"+hist+"_"+num+"_"+dir+".png")
      leg.Clear()
      for a in closeList:
        a.Close()
