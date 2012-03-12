#!/usr/bin/env python
"""
Created by Bryn Mathias on 2010-05-07.
"""
# -----------------------------------------------------------------------------
# Necessary includes
import errno
import os
import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from libWPol import *
from libbryn import *
from icf.core import PSet,Analysis
from time import strftime
from icf.config import defaultConfig
from icf.utils import json_to_pset
from copy import deepcopy
# -----------------------------------------------------------------------------
# Samples
#import yours in your running script
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise



# -----------------------------------------------------------------------------
# Reading the collections from the ntuple

default_ntuple = deepcopy(defaultConfig.Ntuple)
default_ntuple.Electrons=PSet(
Prefix="electron",
Suffix="Pat",
LooseID="EIDLoose",
TightID="EIDTight",
)
default_ntuple.Muons=PSet(
Prefix="muon",
Suffix="Pat",
LooseID="IsGlobalMuon",
TightID="IDGlobalMuonPromptTight",
)
default_ntuple.SecMuons=PSet(
    Prefix="muon",
    Suffix="PF")
default_ntuple.Taus=PSet(
Prefix="tau",
Suffix="Pat",
LooseID="TauIdbyTaNCfrOnePercent",
TightID="TauIdbyTaNCfrTenthPercent"
)
default_ntuple.Jets=PSet(
Prefix="ic5Jet",
Suffix="Pat",
Uncorrected=False,
)
default_ntuple.Photons=PSet(
Prefix="photon",
Suffix="Pat",
)

ic5_calo = deepcopy(default_ntuple)
ic5_calo.Jets.Prefix="ic5Jet"

ak5_calo = deepcopy(default_ntuple)
ak5_calo.Jets.Prefix="ak5Jet"

ak5_jpt = deepcopy(default_ntuple)
ak5_jpt.Jets.Prefix="ak5JetJPT"

ak5_pf = deepcopy(default_ntuple)
ak5_pf.Jets.Prefix="ak5JetPF"
ak5_pf.TerJets.Prefix="ak5Jet"

ak7_calo = deepcopy(default_ntuple)
ak7_calo.Jets.Prefix="ak7Jet"


# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=True
default_cc.ElectronJet=True
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.ModifyJetEnergy=True
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=-1.
default_cc.Muons.CombIsoCut=0.15
default_cc.Muons.MuonJetDeltaR=0.5
default_cc.Muons.MuonIsoTypePtCutoff=0.
default_cc.Muons.RequireLooseIdForInitialFilter=False
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=-1.0
default_cc.Electrons.CombIsoCut=0.15
default_cc.Electrons.ElectronJetDeltaR=0.5
default_cc.Electrons.ElectronIsoTypePtCutoff=0.
default_cc.Electrons.ElectronLooseIdRequired=True
default_cc.Electrons.ElectronTightIdRequired=False
default_cc.Electrons.RequireLooseIdForInitialFilter=False
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=3
default_cc.Photons.UseID=True
default_cc.Photons.PhotonJetDeltaR=0.5
default_cc.Photons.PhotonIsoTypePtCutoff=30.
# -----------------------------------------------------------------------------
# Definition of common objects
default_common = deepcopy(defaultConfig.Common)
default_common.ApplyXCleaning=True
default_common.Jets.PtCut=50.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False
default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=-1.
default_common.Electrons.CombIsoCut=0.15
default_common.Electrons.ApplyID = True
default_common.Electrons.TightID = False
default_common.Electrons.RequireLooseForOdd = True
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=-1.
default_common.Muons.CombIsoCut=0.15
default_common.Muons.ApplyID = True
default_common.Muons.TightID = True
default_common.Muons.RequireLooseForOdd = True
default_common.Photons.EtCut=25.0
# default_common.Photons.EtaCut=2.5
default_common.Photons.UseID=True
# the photon cuts are NOT read anyway
# default_common.Photons.TrkIsoRel=0.
# default_common.Photons.TrkIsoCut=99999.
# default_common.Photons.EcalIsoRel=0.
# default_common.Photons.EcalIsoCut=99999.
# default_common.Photons.HcalIsoRel=0.
# default_common.Photons.HcalIsoCut=99999.
# default_common.Photons.HadOverEmCut=0.5
# default_common.Photons.SigmaIetaIetaCut=0.5
##default_common.Photons.CaloIsoCut=99999.
default_common.Photons.IDReq = 3
default_common.Photons.RequireLooseForOdd = True

skim_ps=PSet(
    SkimName = "myskim",
    DropBranches = False,
    Branches = [
        " keep * "
        ]
)
skim = SkimOp(skim_ps.ps())


#Plot the common plots!

genericPSet = PSet(
DirName      = "275_325Gev",
MinObjects   = 1,
MaxObjects   = 15,
StandardPlots     = True,
)


def makePlotOp(OP = (), cutTree = None, cut = None, label = ""):
  """docstring for makePlotOp"""
  out = []
  if OP[1] != None:
    plotpset = deepcopy(OP[1])
    plotpset.DirName = label
    print plotpset.DirName
    op = eval(OP[0]+"(plotpset.ps())")
  else:
    op = eval(OP[0])
  out.append(op)
  cutTree.TAttach(cut,op)
  alpha = OP_CommonAlphaTCut(0.55)
  dump = EventDump()
  skim_ps=PSet(
    SkimName = "myskim",
    DropBranches = False,
    Branches = [
        " keep * "
        ]
  )
  skim = SkimOp(skim_ps.ps())
  # out.append(skim)
  # out.append(skim_ps)
  cutTree.TAttach(cut,alpha)
  cutTree.TAttach(alpha,dump)
  # cutTree.TAttach(alpha,skim)
  out.append(alpha)
  out.append(dump)
  return out
  pass

def AddBinedHist(cutTree = None, OP = (), cut = None, htBins = [],TriggerDict = None,lab = ""):
  """docstring for AddBinedHist"""
  out = []
  if TriggerDict is not None:
      for lower,upper in zip(htBins,htBins[1:]+[None]):
        # print "Lower , Upper =", lower , upper
        if int(lower) == 325 and upper is None: continue
        if int(lower) == 375 and upper is None: continue
        # print "continue should have happened now"
        lowerCut = eval("RECO_CommonHTCut(%d)"%lower)
        triggerps = PSet(Verbose = False,
        UsePreScaledTriggers = False,
        Triggers = [])
        triggerps.Triggers = TriggerDict["%d%s"%(lower, "_%d"%upper if upper else "")]
        Trigger = OP_MultiTrigger( triggerps.ps() )
        out.append(triggerps)
        out.append(Trigger)
        out.append(lowerCut)
        cutTree.TAttach(cut,Trigger)
        cutTree.TAttach(Trigger,lowerCut)
        if upper:
          upperCut =  eval("RECO_CommonHTLessThanCut(%d)"%upper)
          out.append(upperCut)
          cutTree.TAttach(lowerCut,upperCut)
        pOps = makePlotOp(cutTree = cutTree, OP = OP, cut = upperCut if upper else lowerCut, label = "%s%d%s"%(lab,lower, "_%d"%upper if upper else ""))
        out.append(pOps) 
  else:
      for lower,upper in zip(htBins,htBins[1:]+[None]):
        # print "Lower , Upper =", lower , upper
        if int(lower) == 325 and upper is None: continue
        if int(lower) == 375 and upper is None: continue
        # print "continue should have happened now"
        lowerCut = eval("RECO_CommonHTCut(%d)"%lower)
        out.append(lowerCut)
        cutTree.TAttach(cut,lowerCut)
        if upper:
          upperCut =  eval("RECO_CommonHTLessThanCut(%d)"%upper)
          out.append(upperCut)
          cutTree.TAttach(lowerCut,upperCut)
        pOps = makePlotOp(cutTree = cutTree, OP = OP, cut = upperCut if upper else lowerCut, label = "%s%d%s"%(lab,lower, "_%d"%upper if upper else ""))
        out.append(pOps)
  return out
  pass



# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!

# from icf.JetCorrections import *
# corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
# corPset =  CorrectionPset("Spring10DataV2_L2L3Residual_AK5PF.txt")
# JetCorrections = JESCorrections( corPset.ps(),True )
NoiseFilt= OP_HadronicHBHEnoiseFilter()
GoodVertexMonster = OP_GoodEventSelection()

#Standard Event Selection
LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(30.)
LeadingJetPtCut = OP_FirstJetPtCut(100.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
badMuonInJet = OP_BadMuonInJet()
numComElectrons = OP_NumComElectrons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)





LessThan375 = RECO_CommonHTLessThanCut(375.)
ht250_Trigger = RECO_CommonHTCut(250.)
htCut275_2 = RECO_CommonHTCut(275.)
HT875Cut = RECO_CommonHTCut(875.)

ht275_Fail     = RECO_CommonHTCut(275.)
ht325_Fail     = RECO_CommonHTCut(325.)
ht375_Fail     = RECO_CommonHTCut(375.)
htLess325_Fail = RECO_CommonHTLessThanCut(325.)
htLess375_Fail = RECO_CommonHTLessThanCut(375.)

htCut275 = RECO_CommonHTCut(275.)
htCut375GeV = RECO_CommonHTCut(375.)
htCut375All = RECO_CommonHTCut(375.)
ht250_Trigger = RECO_CommonHTCut(250.)
htCut275_2 = RECO_CommonHTCut(275.)
htCut375GeV = RECO_CommonHTCut(375.)
htCut375 = RECO_CommonHTCut(375.)
alphaT0 = OP_CommonAlphaTCut(0.55)
alphaT1 = OP_CommonAlphaTCut(0.55)
alphaT2 = OP_CommonAlphaTCut(0.55)
spikecleaner = OP_EcalSpikeCleaner()
event_display = OP_EventDisplay("EventDisplays", "common") #to draw all/common objects
alphat = OP_CommonAlphaTCut(0.55)
DeadEcalCutData = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt")
DeadEcalCutMC =   OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_START38_V12.txt")
#MHTCut = OP_TriggerMHT_Emu(90.,30.)
MHTCut = OP_CommonMHTCut(0.)
MHT_METCut = OP_MHToverMET(1.25,50.)
DiJet5 = OP_NumComJets("==",2)






VertexPtOverHT = OP_SumVertexPtOverHT(0.1)
eventDump = EventDump()

triggers = {
    "275_325":["HLT_HT250_AlphaT0p55_v1","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p53_v2","HLT_HT250_AlphaT0p53_v3",
           "HLT_HT250_AlphaT0p53_v4","HLT_HT250_AlphaT0p53_v5","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p58_v3",
           "HLT_HT250_AlphaT0p60_v3",],
    "325_375":["HLT_HT300_AlphaT0p52_v1","HLT_HT300_AlphaT0p52_v2","HLT_HT300_AlphaT0p52_v3","HLT_HT300_AlphaT0p53_v3",
           "HLT_HT300_AlphaT0p53_v4","HLT_HT300_AlphaT0p53_v5","HLT_HT300_AlphaT0p53_v6","HLT_HT300_AlphaT0p54_v5",
           "HLT_HT300_AlphaT0p55_v3",],
    "375_475":["HLT_HT350_AlphaT0p51_v1","HLT_HT350_AlphaT0p51_v2","HLT_HT350_AlphaT0p51_v3","HLT_HT350_AlphaT0p51_v4",
           "HLT_HT350_AlphaT0p51_v5","HLT_HT350_AlphaT0p52_v1","HLT_HT350_AlphaT0p52_v2","HLT_HT350_AlphaT0p53_v10",],
    "475_575":["HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4",
           "HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10",
           "HLT_HT400_AlphaT0p52_v5"],
    "575_675":["HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4",
           "HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10",
           "HLT_HT400_AlphaT0p52_v5"],
    "675_775":["HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4",
           "HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10",
           "HLT_HT400_AlphaT0p52_v5"],
    "775_875":["HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4",
           "HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10",
           "HLT_HT400_AlphaT0p52_v5"],
    "875":["HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4",
           "HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10",
           "HLT_HT400_AlphaT0p52_v5"],
}


json = JSONFilter("Json Mask", json_to_pset("./Golden2011.json"))
# AlphatTriggerCut(0.52414,50)#
# vertex_reweight = VertexReweighting(
# PSet(
# VertexWeights =[0.20, 0.63, 1.19, 1.57, 1.62, 1.42, 1.09, 0.80 ,0.57, 0.42, 0.30, 0.20]
# # VertexWeights = [0.0, 0.027442995662725636, 0.12682983875287387, 0.28326829632076572, 0.40618954180036759, 0.41605144586432974, 0.33147399297403923, 0.21562021576661147, 0.1140047132529971]
# ).ps())


recHitCut = OP_SumRecHitPtCut(30.)
ZeroMuon = OP_NumComMuons("<=",0)
json_ouput = JSONOutput("filtered")
OneMuon = OP_NumComMuons("==",1)
ZMassCut = RECO_2ndMuonMass(25.0, 91.2, False, "all")
PFMTCut30 = RECO_PFMTCut(30.0)
DiMuon = OP_NumComMuons("==",2)
ZMass_2Muons = RECO_2ndMuonMass(25.0, 91.2, True, "OS")
minDRMuonJetCut = RECO_MuonJetDRCut(0.5)
minDRMuonJetCutDiMuon = RECO_MuonJetDRCut(0.5)
def MakeDataTree(Threshold,Muon = None):
  out = []
  print int(Threshold)

  secondJetET = OP_SecondJetEtCut(Threshold)
  HTBins = []
  if int(Threshold) is 100 : HTBins = [375+100*i for i in range(6)]
  if int(Threshold) is 73 : HTBins = [275.,325.]
  if int(Threshold) is 86 : HTBins = [325.,375.]
  # from batchGolden import *
  cutTreeData = Tree("Data")
  cutTreeData.Attach(json)
  # #cutTreeData.TAttach(json,evFilter)
  # #cutTreeData.TAttach(evFilter,skim)
  # #cutTreeData.TAttach(evFilter,eventDump)
  cutTreeData.TAttach(json,NoiseFilt)
  # cutTreeData.TAttach(json,json_ouput)
  # 
  # cutTreeData.Attach(eventDump)
  # 
  cutTreeData.TAttach(NoiseFilt,GoodVertexMonster)
  cutTreeData.TAttach(GoodVertexMonster,recHitCut)
  cutTreeData.TAttach(recHitCut,LeadingJetEta)
  cutTreeData.TAttach(LeadingJetEta,secondJetET)
  cutTreeData.TAttach(secondJetET,oddJet)
  cutTreeData.TAttach(oddJet,badMuonInJet)
  cutTreeData.TAttach(badMuonInJet,oddElectron)
  cutTreeData.TAttach(oddElectron,oddPhoton)
  cutTreeData.TAttach(oddPhoton,numComElectrons)
  cutTreeData.TAttach(numComElectrons,numComPhotons)
  cutTreeData.TAttach(numComPhotons,VertexPtOverHT)
  cutTreeData.TAttach(VertexPtOverHT,htCut275)
  # #FOR HT > 275Gev Plot
  # #END HT 275GEV Plot
  # #Begin MHT/MET plot inthe low region.
  cutTreeData.TAttach(htCut275,DeadEcalCutData)
  # #Here be plots after all the cuts!!
  cutTreeData.TAttach(DeadEcalCutData,MHT_METCut)
  if Muon == None:
      cutTreeData.TAttach(DeadEcalCutData,ZeroMuon)#MHT_METCut
  #     # cutTreeData.TAttach(ZeroMuon,ZeroMuonbtag)
  #     # out.append(AddBinedHist(cutTree = cutTreeData,
  #     # OP = ("WeeklyUpdatePlots",genericPSet), cut = ZeroMuonbtag,
  #     # htBins = HTBins,TriggerDict = triggers,lab ="btag_") )
  #   
      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("WeeklyUpdatePlots",genericPSet), cut = ZeroMuon,
      htBins = HTBins,TriggerDict = triggers,lab = "") )
  # # 
  # else:
  #     cutTreeData.TAttach(MHT_METCut,minDRMuonJetCut)
  #     cutTreeData.TAttach(minDRMuonJetCut,OneMuon)
  #     cutTreeData.TAttach(OneMuon,ZMassCut)
  #     cutTreeData.TAttach(ZMassCut,PFMTCut30)
  #     # cutTreeData.TAttach(PFMTCut30,btagOneMuon)
  #     # out.append(AddBinedHist(cutTree = cutTreeData,
  #     # OP = ("WeeklyUpdatePlots",genericPSet), cut = btagOneMuon,
  #     # htBins = HTBins,TriggerDict = triggers,lab ="btag_OneMuon_") )
  #   
  #     out.append(AddBinedHist(cutTree = cutTreeData,
  #     OP = ("WeeklyUpdatePlots",genericPSet), cut = PFMTCut30,
  #     htBins = HTBins,TriggerDict = triggers,lab = "OneMuon_") )
  #    
  #    
  #      
  #     cutTreeData.TAttach(minDRMuonJetCut,DiMuon)
  #     cutTreeData.TAttach(DiMuon,ZMass_2Muons)
  #     cutTreeData.TAttach(ZMass_2Muons,minDRMuonJetCutDiMuon)
  #     # cutTreeData.TAttach(minDRMuonJetCutDiMuon,btagDiMuon)
  #     # avobe here does one big inclusive bin!
  # #     # Now lets start binning in HT bins
  # #     # So we can HADD the files at the end and get a chorent set to save the book keeping nightmare:
  # #     # we arrange the HT bins so they are not repoduced though out threshold runs.
  # # 
  #     # out.append(AddBinedHist(cutTree = cutTreeData,
  #     # OP = ("WeeklyUpdatePlots",genericPSet), cut = btagDiMuon,
  #     # htBins = HTBins,TriggerDict = triggers,lab ="btag_DiMuon_") )
  # #   
  #     out.append(AddBinedHist(cutTree = cutTreeData,
  #     OP = ("WeeklyUpdatePlots",genericPSet), cut = minDRMuonJetCutDiMuon,
  #     htBins = HTBins,TriggerDict = triggers,lab = "DiMuon_") )
  #
  out.append(secondJetET)   
  return (cutTreeData, out)

#Second MC!

def MakeMCTree(Threshold, Muon = None):
  out = []

  HTBins = []
  
  if int(Threshold) is 100 : HTBins = [375+100*i for i in range(6)]
  if int(Threshold) is 73 : HTBins = [275.,325.]
  if int(Threshold) is 86 : HTBins = [325.,375.]
  secondJetET = OP_SecondJetEtCut(Threshold)
  cutTreeMC = Tree("MC")
  cutTreeMC.Attach(ht250_Trigger)
  cutTreeMC.TAttach(ht250_Trigger,NoiseFilt)
  cutTreeMC.TAttach(NoiseFilt,GoodVertexMonster)
  cutTreeMC.TAttach(GoodVertexMonster,recHitCut)
  cutTreeMC.TAttach(recHitCut,LeadingJetEta)
  cutTreeMC.TAttach(LeadingJetEta,secondJetET)
  cutTreeMC.TAttach(secondJetET,oddJet)
  cutTreeMC.TAttach(oddJet,badMuonInJet)
  cutTreeMC.TAttach(badMuonInJet,oddElectron)
  cutTreeMC.TAttach(oddElectron,oddPhoton)
  cutTreeMC.TAttach(oddPhoton,numComElectrons)
  cutTreeMC.TAttach(numComElectrons,numComPhotons)
  cutTreeMC.TAttach(numComPhotons,VertexPtOverHT)
  cutTreeMC.TAttach(VertexPtOverHT,htCut275)
  cutTreeMC.TAttach(htCut275,DeadEcalCutMC)
 
  #Here be plots after all the cuts!!
  cutTreeMC.TAttach(DeadEcalCutMC,MHT_METCut)
  if Muon == None:
      cutTreeMC.TAttach(DeadEcalCutMC,ZeroMuon)#MHT_METCut
      # cutTreeMC.TAttach(ZeroMuon,ZeroMuonbtag)
      # out.append(AddBinedHist(cutTree = cutTreeMC,
      # OP = ("WeeklyUpdatePlots",genericPSet), cut = ZeroMuonbtag,
      # htBins = HTBins,TriggerDict = triggers,lab ="btag_") )
    
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("WeeklyUpdatePlots",genericPSet), cut = ZeroMuon,
      htBins = HTBins,TriggerDict = triggers,lab = "") )
      
  # else:
  #     cutTreeMC.TAttach(MHT_METCut,minDRMuonJetCut)
  #     cutTreeMC.TAttach(minDRMuonJetCut,OneMuon)
  #     cutTreeMC.TAttach(OneMuon,ZMassCut)
  #     cutTreeMC.TAttach(ZMassCut,PFMTCut30)
  #     # cutTreeMC.TAttach(PFMTCut30,btagOneMuon)
  #     # out.append(AddBinedHist(cutTree = cutTreeMC,
  #     # OP = ("WeeklyUpdatePlots",genericPSet), cut = btagOneMuon,
  #     # htBins = HTBins,TriggerDict = triggers,lab ="btag_OneMuon_") )
  #   
  #     out.append(AddBinedHist(cutTree = cutTreeMC,
  #     OP = ("WeeklyUpdatePlots",genericPSet), cut = PFMTCut30,
  #     htBins = HTBins,TriggerDict = triggers,lab = "OneMuon_") )
  #   
  #   
  #     cutTreeMC.TAttach(minDRMuonJetCut,DiMuon)
  #     cutTreeMC.TAttach(DiMuon,ZMass_2Muons)
  #     cutTreeMC.TAttach(ZMass_2Muons,minDRMuonJetCutDiMuon)
  #     # cutTreeMC.TAttach(minDRMuonJetCutDiMuon,btagDiMuon)
  #     # avobe here does one big inclusive bin!
  #     # Now lets start binning in HT bins
  #     # So we can HADD the files at the end and get a chorent set to save the book keeping nightmare:
  #     # we arrange the HT bins so they are not repoduced though out threshold runs.
  #     # out.append(AddBinedHist(cutTree = cutTreeMC,
  #     # OP = ("WeeklyUpdatePlots",genericPSet), cut = btagDiMuon,
  #     # htBins = HTBins,TriggerDict = triggers,lab ="btag_DiMuon_") )
  #   
  #     out.append(AddBinedHist(cutTree = cutTreeMC,
  #     OP = ("WeeklyUpdatePlots",genericPSet), cut = minDRMuonJetCutDiMuon,
  #     htBins = HTBins,TriggerDict = triggers,lab = "DiMuon_") )


  return (cutTreeMC,secondJetET,out)


# Define the custom muon ID

mu_id = PSet(
    doJetLoop = False,
    MuID = "Tight",
    MinPt = 10.,
    MaxEta = 2.5,
    MaxIsolation = 0.1,
    DRMuJet = 0.3,
    MaxGlbTrkDxy = 0.02,
    MinGlbTrkNumOfValidHits = 11,
    SegMatch2GlbMu = 1,
    PixelHitsOnInrTrk = 1,
    MaxInrTrkDz = 1.
        )


# PU S6
# vertex_reweight = GoodVertexReweighting(
# PSet(GoodVertexWeights =[1.0, 0.6747792521746856, 1.0448420078821972, 1.3055015002285708, 1.3983895957384924, 1.4093911155782819, 1.3850308438481276, 1.3018072225453758, 1.1623455679439036, 1.0517773707737472, 0.89838694986924372, 0.76765214151467354, 0.63185640954246791, 0.49262105848611853, 0.42787145593782405, 0.3847054078776958, 0.35778382190253444, 0.34148368315539618, 0.28535617241618649, 0.24963682196802897, 0.15231738209843554, 0.10766396055685283, 0.066294358386045707, 0.039350814964675719, 0.071293966061105704] ).ps())

# PU S4
vertex_reweight = GoodVertexReweighting(
PSet(GoodVertexWeights = [1.0, 0.071182041228993354, 0.3788533298983548, 0.70212224756460717, 0.95912926863057879,
 1.1063323506805849, 1.1826257455177471, 1.2297382718782017, 1.2772830447358376, 1.4266446590805815, 1.5732065775636328, 
 1.8401056375971667, 2.1784909215394999, 2.506266882602076, 3.3335988825191176, 4.687787057503483, 6.8602191807881647, 
 11.198474011060968, 14.883466002768214, 20.878255333866864, 1.0, 1.0, 1.0, 1.0, 1.0]).ps())



QCD_Summer11_Pythia_All # S3
QCD_Summer11_madgraph_All #S4


# Here are the Summer 11 MC samples!!!

from montecarlo.Summer11.DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.Summer11.ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.QCD_Summer11_madgraph_All import *
from montecarlo.Summer11.TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.Summer11.T_TuneZ2_t_channel_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.T_TuneZ2_tW_channel_DR_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.Tbar_TuneZ2_t_channel_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.Tbar_TuneZ2_tW_channel_DR_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1 import *

# PU S6
from montecarlo.Summer11.WW_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1 import *
from montecarlo.Summer11.WZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1 import *
from montecarlo.Summer11.ZZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1 import *


PU_S6_Samples = [ WW_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1, 
                WZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1,
                 ZZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1]

 # QCD_Summer11_madgraph_All +
from montecarlo.Summer11.QCD_BLepEnriched_TuneZ2_7TeV_pythia6_evtgen_Summer11_PU_S3_START42_V11_v1 import *

PU_S3_Sample = [ QCD_BLepEnriched_TuneZ2_7TeV_pythia6_evtgen_Summer11_PU_S3_START42_V11_v1]

WJet_Sample =[ WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1, WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 ]

DiMuon_Sample = [ DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 ]

TTbar_Sample = [ TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1, T_TuneZ2_t_channel_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1,T_TuneZ2_tW_channel_DR_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1,Tbar_TuneZ2_t_channel_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1,
Tbar_TuneZ2_tW_channel_DR_7TeV_powheg_tauola_Summer11_PU_S4_START42_V11_v1, ]

Zinv_Sample = [ ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 ]
Summer11_MC_Higher_Bins = PU_S3_Sample# [WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1, WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 ] + TTbar_Sample 
Summer11_MC_Lower_Bins = PU_S3_Sample# [ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1, WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1,DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 ]+TTbar_Sample 
