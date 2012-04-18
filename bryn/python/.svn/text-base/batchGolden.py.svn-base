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
# lets get some samples together!!
from montecarlo.Spring11.QCD_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL import *
from montecarlo.Spring11.TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.ZinvisibleJets_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.LMx_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.GJets_TuneD6T_HT_200_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.TToBLNu_TuneZ2_t_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.TToBLNu_TuneZ2_tW_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import *
from montecarlo.Spring11.TToBLNu_TuneZ2_s_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import *

MC = QCD_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL+[TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1,WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1,ZinvisibleJets_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1,LM0_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1,LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM2_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM3_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM4_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM5_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM7_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM8_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, LM9_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1,
GJets_TuneD6T_HT_200_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1,
TToBLNu_TuneZ2_s_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1,
TToBLNu_TuneZ2_tW_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1,
TToBLNu_TuneZ2_t_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1
]

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
MinObjects   = 2,
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
  cutTree.TAttach(cut,alpha)
  cutTree.TAttach(alpha,dump)
  out.append(alpha)
  out.append(dump)
  return out
  pass

def AddBinedHist(cutTree = None, OP = (), cut = None, htBins = []):
  """docstring for AddBinedHist"""
  out = []
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
    pOps = makePlotOp(cutTree = cutTree, OP = OP, cut = upperCut if upper else lowerCut, label = "%d%s"%(lower, "_%d"%upper if upper else ""))
    out.append(pOps)
  return out
  pass


pset1 = PSet(
DirName      = "275_325Gev",
MinObjects   = 1,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset1 = PSet(
DirName      = "n275_325Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset2 = PSet(
DirName      = "325Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset2 = PSet(
DirName      = "n325Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset3 = PSet(
DirName      = "375Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset3 = PSet(
DirName      = "n375Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)


pset5 = PSet(
DirName      = "375Gev_afterDeadEcal",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset5 = PSet(
DirName      = "n375Gev_afterDeadEcal",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset4 = PSet(
DirName      = "All",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset4 = PSet(
DirName      = "nAll",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

Npset6 = PSet(
DirName      = "nAllCuts",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset6 = PSet(
DirName      = "AllCuts",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

HadStandard275_375 = WeeklyUpdatePlots(pset1.ps())
HadStandard325 = WeeklyUpdatePlots(pset2.ps())
HadStandard375 = WeeklyUpdatePlots(pset3.ps())
HadStandard375_after_DeadEcal = WeeklyUpdatePlots(pset5.ps())
HadStandardAll = WeeklyUpdatePlots(pset4.ps())
nHadStandard275_375 = WeeklyUpdatePlots(Npset1.ps())
nHadStandard325 = WeeklyUpdatePlots(Npset2.ps())
nHadStandard375 = WeeklyUpdatePlots(Npset3.ps())
nHadStandardAll = WeeklyUpdatePlots(Npset4.ps())
nHadStandard375_after_DeadEcal = WeeklyUpdatePlots(Npset5.ps())
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
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

DiJet0 = OP_NumComJets("==",2)
DiJet1 = OP_NumComJets("==",2)
DiJet2 = OP_NumComJets("==",2)
DiJet3 = OP_NumComJets("==",2)
DiJet4 = OP_NumComJets("==",2)
NJet0 = OP_NumComJets(">=",3)
NJet1 = OP_NumComJets(">=",3)
NJet2 = OP_NumComJets(">=",3)
NJet3 = OP_NumComJets(">=",3)
NJet4 = OP_NumComJets(">=",3)
DiVertexJets = OP_NumComJets("==",2)
NVertexJets = OP_NumComJets(">=",3)



LessThan375 = RECO_CommonHTLessThanCut(375.)
ht250_Trigger = RECO_CommonHTCut(250.)
htCut275_2 = RECO_CommonHTCut(275.)

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
MHTCut = OP_CommonMHTCut(100.)
MHT_METCut = OP_MHToverMET(1.25,50.)
NJet5 = OP_NumComJets(">=",3)
DiJet5 = OP_NumComJets("==",2)
nHadStandardAllCuts=  WeeklyUpdatePlots(Npset6.ps())
HadStandardAllCuts=  WeeklyUpdatePlots(pset6.ps())


# Cross check with the allhadronic analysis
t1 = PSet(
    DirName      = "HadronicCommon_1",
    MinObjects   = 2,
    MaxObjects   = 15,
    StandardPlots     = False,
    DeadECALPlots = True,
    CleaningControlPlots = False,
    MECPlots = False,
    DeadECALFile = "./deadRegionList_START36_V9.txt",
    DeadECAL_MinJetPtCut = 30.,
    DeadECAL_MinBiasCut = 0.5,
    DeadECAL_NBadCellsCut = 10
)

t2 = deepcopy(t1)
t2.DirName = "HadronicCommon_2"

pset = PSet(
DirName      = "275_infGev",
MinObjects   = 1,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset = PSet(
DirName      = "n275_infGev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset2 = deepcopy(pset)
pset2.DirName = "275_375Gev"

Npset2 = deepcopy(Npset)
Npset2.DirName = "n275_375Gev"

pset3 = deepcopy(pset)
pset3.DirName = "375GeVafterDeadEcal"
Npset3 = deepcopy(Npset)
Npset3.DirName = "n375GeVafterDeadEcal"

pset4 = deepcopy(pset)
pset4.DirName = "allCuts"
Npset4 = deepcopy(Npset)
Npset4.DirName = "nAllCuts"
# Define a crap load more plotting ops, for HT exclusive bins
Plot_275_325_Fail_pset = deepcopy(genericPSet)
Plot_275_325_Fail_pset.DirName="275_325Fail"
Plot_325_375_Fail_pset = deepcopy(genericPSet)
Plot_325_375_Fail_pset.DirName="325_375Fail"
Plot_375_Fail_pset = deepcopy(genericPSet)
Plot_375_Fail_pset.DirName="375Fail"
Plot_275_325Fail = WeeklyUpdatePlots( Plot_275_325_Fail_pset.ps() )
Plot_325_375Fail = WeeklyUpdatePlots( Plot_325_375_Fail_pset.ps() )
Plot_375Fail     = WeeklyUpdatePlots( Plot_375_Fail_pset.ps() )

HTplot = WeeklyUpdatePlots(pset.ps())
nHTplot = WeeklyUpdatePlots(Npset.ps())
controlRegion = WeeklyUpdatePlots(pset2.ps())
ncontrolRegion = WeeklyUpdatePlots(Npset2.ps())
afterDeadEcal = WeeklyUpdatePlots(pset3.ps())
nafterDeadEcal = WeeklyUpdatePlots(Npset3.ps())
afterAllCuts = WeeklyUpdatePlots(pset4.ps())
nafterAllCuts = WeeklyUpdatePlots(Npset4.ps())


pset2 = deepcopy(pset1)
pset2.DirName = "HadronicCommon_2"

t3 = deepcopy(t1)
t3.DirName = "HadronicCommon_3"

t4 = deepcopy(t1)
t4.DirName = "HadronicCommon_4"

HadStandard_1 = HadronicCommonPlots(t1.ps())
HadStandard_2 = HadronicCommonPlots(t2.ps())
HadStandard_3 = HadronicCommonPlots(t3.ps())
HadStandard_4 = HadronicCommonPlots(t4.ps())
VertexPtOverHT = OP_SumVertexPtOverHT(0.1)
eventDump = EventDump()
datatriggerps = PSet(
    Verbose = False,
    UsePreScaledTriggers = False,
    Triggers = [
"HLT_HT250_AlphaT0p53_v2",
"HLT_HT250_AlphaT0p53_v3",
"HLT_HT250_AlphaT0p53_v4",
"HLT_HT250_AlphaT0p53_v5",
"HLT_HT250_AlphaT0p53_v6",
"HLT_HT250_AlphaT0p54_v2",
"HLT_HT250_AlphaT0p54_v3",
"HLT_HT250_AlphaT0p54_v4",
"HLT_HT250_AlphaT0p55_v1",
"HLT_HT250_AlphaT0p62_v1",
"HLT_HT250_AlphaT0p62_v2",
  ]
)
DataTrigger = OP_MultiTrigger( datatriggerps.ps() )

JetAdd = JetAddition(0.)
json = JSONFilter("Json Mask", json_to_pset("/home/hep/db1110/public_html/Golden2011.json"))

# AlphatTriggerCut(0.52414,50)#
# vertex_reweight = VertexReweighting(
# PSet(
# VertexWeights =[0.20, 0.63, 1.19, 1.57, 1.62, 1.42, 1.09, 0.80 ,0.57, 0.42, 0.30, 0.20]
# # VertexWeights = [0.0, 0.027442995662725636, 0.12682983875287387, 0.28326829632076572, 0.40618954180036759, 0.41605144586432974, 0.33147399297403923, 0.21562021576661147, 0.1140047132529971]
# ).ps())

# PreScaleWeights = PreScaleReweighting(datatriggerps.ps())
recHitCut = OP_SumRecHitPtCut(30.)
json_ouput = JSONOutput("filtered")
def MakeDataTree(Threshold):
  print int(Threshold)
  out = []
  secondJetET = OP_SecondJetEtCut(Threshold)
  HTBins = []
  if int(Threshold) is 100 : HTBins = [375+100*i for i in range(6)]
  if int(Threshold) is 73 : HTBins = [275.,325.]
  if int(Threshold) is 86 : HTBins = [325.,375.]
  # from batchGolden import *
  cutTreeData = Tree("Data")
  cutTreeData.Attach(json)
  # cutTreeData.TAttach(json,evFilter)
  # cutTreeData.TAttach(evFilter,skim)
  # cutTreeData.TAttach(evFilter,eventDump)
  cutTreeData.TAttach(json,DataTrigger)
  cutTreeData.TAttach(json,json_ouput)
  # cutTreeData.Attach(DataTrigger)
  cutTreeData.TAttach(DataTrigger,MHTCut)
  cutTreeData.TAttach(MHTCut,NoiseFilt)
  cutTreeData.TAttach(NoiseFilt,GoodVertexMonster)
  cutTreeData.TAttach(GoodVertexMonster,recHitCut)
  cutTreeData.TAttach(recHitCut,LeadingJetEta)
  cutTreeData.TAttach(LeadingJetEta,secondJetET)
  cutTreeData.TAttach(secondJetET,oddJet)
  cutTreeData.TAttach(oddJet,badMuonInJet)
  cutTreeData.TAttach(badMuonInJet,oddMuon)
  cutTreeData.TAttach(oddMuon,oddElectron)
  cutTreeData.TAttach(oddElectron,oddPhoton)
  cutTreeData.TAttach(oddPhoton,numComLeptons)
  cutTreeData.TAttach(numComLeptons,numComPhotons)
  cutTreeData.TAttach(numComPhotons,VertexPtOverHT)
  cutTreeData.TAttach(VertexPtOverHT,htCut275)
  #FOR HT > 275Gev Plot
  cutTreeData.TAttach(htCut275,DiJet3)
  cutTreeData.TAttach(htCut275,NJet3)
  cutTreeData.TAttach(DiJet3,HadStandardAll)
  cutTreeData.TAttach(NJet3,nHadStandardAll)
  #END HT 275GEV Plot
  #Begin MHT/MET plot inthe low region.
  cutTreeData.TAttach(htCut275,DeadEcalCutData)
  cutTreeData.TAttach(DeadEcalCutData,LessThan375)
  cutTreeData.TAttach(LessThan375,DiJet0)
  cutTreeData.TAttach(LessThan375,NJet0)
  cutTreeData.TAttach(DiJet0,HadStandard275_375)
  cutTreeData.TAttach(NJet0,nHadStandard275_375)
  #for Vertext multiplicity plot at 325geV
  cutTreeData.TAttach(htCut275,htCut375GeV)
  cutTreeData.TAttach(htCut375GeV,DiJet2)
  cutTreeData.TAttach(htCut375GeV,NJet2)
  cutTreeData.TAttach(DiJet2,HadStandard375)
  cutTreeData.TAttach(NJet2,nHadStandard375)
  cutTreeData.TAttach(DeadEcalCutData,htCut375)
  #Here be plots for baby jet MHT and MHT/MET in the signal region after dead ecal cuts
  cutTreeData.TAttach(htCut375,DiJet4)
  cutTreeData.TAttach(DiJet4,HadStandard375_after_DeadEcal)
  cutTreeData.TAttach(htCut375,NJet4)
  cutTreeData.TAttach(htCut375,alphaT1)
  cutTreeData.TAttach(NJet4,nHadStandard375_after_DeadEcal)
  #Here be plots after all the cuts!!
  # cutTreeData.TAttach(DeadEcalCutData,
  cutTreeData.TAttach(htCut275,MHT_METCut)
  cutTreeData.TAttach(MHT_METCut,htCut375All)
  cutTreeData.TAttach(htCut375All,NJet5)
  cutTreeData.TAttach(htCut375All,DiJet5)
  cutTreeData.TAttach(htCut375All,alphat)
  # cutTreeData.TAttach(alphat,eventDump)
#  cutTreeData.TAttach(alphat,skim)
  cutTreeData.TAttach(NJet5,nHadStandardAllCuts)
  cutTreeData.TAttach(DiJet5,HadStandardAllCuts)
  # cutTreeData.TAttach(MHT_METCut, alphat)
  # cutTreeData.TAttach(alphat,eventDump)#skim)
  # avobe here does one big inclusive bin!
  # Now lets start binning in HT bins
  # So we can HADD the files at the end and get a chorent set to save the book keeping nightmare:
  # we arrange the HT bins so they are not repoduced though out threshold runs.

  out.append(AddBinedHist(cutTree = cutTreeData,
            OP = ("WeeklyUpdatePlots",genericPSet), cut = MHT_METCut,
            htBins = HTBins) )

  return (cutTreeData,secondJetET,out)

#Second MC!

def MakeMCTree(Threshold):
  out = []
  HTBins = []
  if int(Threshold) is 100 : HTBins = [375+100*i for i in range(6)]
  if int(Threshold) is 73 : HTBins = [275.,325.]
  if int(Threshold) is 86 : HTBins = [325.,375.]
  secondJetET = OP_SecondJetEtCut(Threshold)
  cutTreeMC = Tree("MC")
  cutTreeMC.Attach(ht250_Trigger)
  cutTreeMC.TAttach(ht250_Trigger,MHTCut)
  cutTreeMC.TAttach(MHTCut,NoiseFilt)
  cutTreeMC.TAttach(NoiseFilt,GoodVertexMonster)
  cutTreeMC.TAttach(GoodVertexMonster,recHitCut)
  cutTreeMC.TAttach(recHitCut,LeadingJetEta)
  cutTreeMC.TAttach(LeadingJetEta,secondJetET)
  cutTreeMC.TAttach(secondJetET,oddJet)
  cutTreeMC.TAttach(oddJet,badMuonInJet)
  cutTreeMC.TAttach(badMuonInJet,oddMuon)
  cutTreeMC.TAttach(oddMuon,oddElectron)
  cutTreeMC.TAttach(oddElectron,oddPhoton)
  cutTreeMC.TAttach(oddPhoton,numComLeptons)
  cutTreeMC.TAttach(numComLeptons,numComPhotons)
  cutTreeMC.TAttach(numComPhotons,VertexPtOverHT)
  cutTreeMC.TAttach(VertexPtOverHT,htCut275)
  # cutTreeMC.TAttach(numComPhotons,ht275_Fail)
  # cutTreeMC.TAttach(numComPhotons,ht325_Fail)
  # cutTreeMC.TAttach(ht275_Fail,htLess325_Fail)
  # cutTreeMC.TAttach(ht325_Fail,htLess375_Fail)
  # cutTreeMC.TAttach(numComPhotons,ht375_Fail)
  # cutTreeMC.TAttach(htLess325_Fail,Plot_275_325Fail)
  # cutTreeMC.TAttach(htLess375_Fail,Plot_325_375Fail)
  # cutTreeMC.TAttach(ht375_Fail,Plot_375Fail)
  #FOR HT > 275Gev Plot
  cutTreeMC.TAttach(htCut275,DiJet3)
  cutTreeMC.TAttach(htCut275,NJet3)
  cutTreeMC.TAttach(DiJet3,HadStandardAll)
  cutTreeMC.TAttach(NJet3,nHadStandardAll)
  #END HT 275GEV Plot
  #Begin MHT/MET plot inthe low region.
  cutTreeMC.TAttach(htCut275,DeadEcalCutMC)
  cutTreeMC.TAttach(DeadEcalCutMC,LessThan375)
  cutTreeMC.TAttach(LessThan375,DiJet0)
  cutTreeMC.TAttach(LessThan375,NJet0)
  cutTreeMC.TAttach(DiJet0,HadStandard275_375)
  cutTreeMC.TAttach(NJet0,nHadStandard275_375)

  cutTreeMC.TAttach(DeadEcalCutMC,htCut375)
  cutTreeMC.TAttach(htCut275,htCut375GeV)
  cutTreeMC.TAttach(htCut375GeV,DiJet2)
  cutTreeMC.TAttach(htCut375GeV,NJet2)

  cutTreeMC.TAttach(DiJet2,HadStandard375)
  cutTreeMC.TAttach(NJet2,nHadStandard375)

  #Here be plots for baby jet MHT and MHT/MET in the signal region after dead ecal cuts
  cutTreeMC.TAttach(htCut375,DiJet4)
  cutTreeMC.TAttach(DiJet4,HadStandard375_after_DeadEcal)
  cutTreeMC.TAttach(htCut375,NJet4)
  cutTreeMC.TAttach(htCut375,alphaT1)
  cutTreeMC.TAttach(NJet4,nHadStandard375_after_DeadEcal)


  #Here be plots after all the cuts!!
  # cutTreeMC.TAttach(DeadEcalCutMC,
  cutTreeMC.TAttach(htCut275,MHT_METCut)
  cutTreeMC.TAttach(MHT_METCut,alphaT2)
  cutTreeMC.TAttach(MHT_METCut,htCut375All)
  cutTreeMC.TAttach(htCut375All,NJet5)
  cutTreeMC.TAttach(htCut375All,DiJet5)
  cutTreeMC.TAttach(NJet5,nHadStandardAllCuts)
  cutTreeMC.TAttach(DiJet5,HadStandardAllCuts)
  out.append(AddBinedHist(cutTree = cutTreeMC,
            OP = ("WeeklyUpdatePlots",genericPSet), cut = MHT_METCut,
            htBins = HTBins) )
  return (cutTreeMC,secondJetET,out)

