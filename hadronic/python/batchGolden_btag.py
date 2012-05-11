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
from libOneLepton import *
from libbryn import *
from icf.core import PSet,Analysis
from time import strftime
from icf.config import defaultConfig
from icf.utils import json_to_pset
from copy import deepcopy
from utils import *
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
GenPt = EffToPSet(readBtagWeight("./Btag_Efficiency_Test.txt")).GenPt,
GenEta = EffToPSet(readBtagWeight("./Btag_Efficiency_Test.txt")).GenEta,
Pt_Eta_Eff = EffToPSet(readBtagWeight("./Btag_Efficiency_Test.txt")).Pt_Eta_Eff,

Mistag_GenPt = EffToPSet(readBtagWeight("./Btag_Mistag_Test.txt")).GenPt,
Mistag_GenEta = EffToPSet(readBtagWeight("./Btag_Mistag_Test.txt")).GenEta,
Mistag_Pt_Eta_Eff = EffToPSet(readBtagWeight("./Btag_Mistag_Test.txt")).Pt_Eta_Eff,

JetPt_Low = EffToPSet(readBtagWeight("./Btag_Systematic_Variation.txt")).GenPt,
JetPt_High = EffToPSet(readBtagWeight("./Btag_Systematic_Variation.txt")).GenEta,
Variation  = EffToPSet(readBtagWeight("./Btag_Systematic_Variation.txt")).Pt_Eta_Eff,

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
  #cutTree.TAttach(cut,dump)
  #cutTree.TAttach(cut,skim)
  #cutTree.TAttach(alpha,dump)
  #cutTree.TAttach(alpha,skim)
  out.append(skim)
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
        if int(lower) == 475 and upper is None: continue
        if int(lower) == 675 and upper is None: continue
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
        if int(lower) == 475 and upper is None: continue
        if int(lower) == 675 and upper is None: continue
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
GE2Jets = OP_NumComJets(">=",2)

# Define a crap load more plotting ops, for HT exclusive bins

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

mu_triggers = {
 "275_325":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"], 
 "325_375":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 "375_475":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 "475_575":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 "575_675":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 "675_775":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 "775_875":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 "875":["HLT_Mu5_HT200_v3","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v4","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],
 
}

single_mu_triggers = {
  "275_325":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "325_375":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "375_475":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "475_575":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "575_675":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "675_775":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "775_875":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
  "875":["HLT_Mu30_v*","HLT_Mu40_eta2p1_v*"],
}

#json = JSONFilter("Json Mask", json_to_pset("./Run2011A.json"))

#json = JSONFilter("Json Mask", json_to_pset("./Run2011B.json"))
#json = JSONFilter("Json Mask", json_to_pset("./Jad_Test.json"))
json = JSONFilter("Json Mask", json_to_pset("./Golden2011.json"))

zerobtagDiMuon= OP_NumCommonBtagJets("==",0,0.679,5)
more_than_zero_btagDiMuon= OP_NumCommonBtagJets(">",0,0.679,5)
onebtagDiMuon= OP_NumCommonBtagJets("==",1,0.679,5)
more_than_one_btagDiMuon= OP_NumCommonBtagJets(">",1,0.679,5)
twobtagDiMuon= OP_NumCommonBtagJets("==",2,0.679,5)
more_than_two_btagDiMuon= OP_NumCommonBtagJets(">",2,0.679,5)

zerobtagOneMuon= OP_NumCommonBtagJets("==",0,0.679,5)
more_than_zero_btagOneMuon= OP_NumCommonBtagJets(">",0,0.679,5)
onebtagOneMuon= OP_NumCommonBtagJets("==",1,0.679,5)
more_than_one_btagOneMuon= OP_NumCommonBtagJets(">",1,0.679,5)
twobtagOneMuon= OP_NumCommonBtagJets("==",2,0.679,5)
more_than_two_btagOneMuon= OP_NumCommonBtagJets(">",2,0.679,5)

zerobtag= OP_NumCommonBtagJets("==",0,0.679,5)
more_than_zero_btag= OP_NumCommonBtagJets(">",0,0.679,5)
onebtag= OP_NumCommonBtagJets("==",1,0.679,5)
more_than_one_btag= OP_NumCommonBtagJets(">",1,0.679,5)
twobtag= OP_NumCommonBtagJets("==",2,0.679,5)
more_than_two_btag= OP_NumCommonBtagJets(">",2,0.679,5)

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
Mu45PtCut = OP_UpperMuPtCut(45.0)


def MakeBtagDataTree(Threshold,Muon = None,Split = None):
  out = []
  print int(Threshold)

  secondJetET = OP_SecondJetEtCut(Threshold)
  HTBins = []
  if int(Threshold) is 100 and Split == None : HTBins = [375+100*i for i in range(6)]
  if int(Threshold) is 100 and Split == "Had_One" : HTBins = [375+100*i for i in range(4)]
  if int(Threshold) is 100 and Split == "Had_Two" : HTBins = [675+100*i for i in range(3)]
  if int(Threshold) is 100 and Split == "Muon_One" : HTBins = [375,475]
  if int(Threshold) is 100 and Split == "Muon_Two" : HTBins = [475,575,675]
  if int(Threshold) is 100 and Split == "Muon_Three" : HTBins = [675,775,875]
  if int(Threshold) is 73 : HTBins = [275.,325.]
  if int(Threshold) is 86 : HTBins = [325.,375.]
  # from batchGolden import *
  cutTreeData = Tree("Data")
  cutTreeData.Attach(json)
  # cutTreeData.TAttach(json,evFilter)
  # cutTreeData.TAttach(evFilter,skim)
  # cutTreeData.TAttach(evFilter,eventDump)
  # cutTreeData.TAttach(json,NoiseFilt)
  # cutTreeData.TAttach(json,json_ouput)
  # cutTreeData.Attach(DataTrigger)
  #cutTreeData.Attach(NoiseFilt)
  cutTreeData.TAttach(json,NoiseFilt)
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
  #FOR HT > 275Gev Plot
  #END HT 275GEV Plot
  #Begin MHT/MET plot inthe low region.
  cutTreeData.TAttach(htCut275,DeadEcalCutData)
  #Here be plots after all the cuts!!
  cutTreeData.TAttach(DeadEcalCutData,MHT_METCut)
  if Muon == None:
    pass
  else:
      cutTreeData.TAttach(MHT_METCut,Mu45PtCut)
      cutTreeData.TAttach(Mu45PtCut,minDRMuonJetCut)
      cutTreeData.TAttach(minDRMuonJetCut,OneMuon)
      cutTreeData.TAttach(OneMuon,ZMassCut)
      cutTreeData.TAttach(ZMassCut,PFMTCut30)
      cutTreeData.TAttach(PFMTCut30,zerobtagOneMuon)
      cutTreeData.TAttach(PFMTCut30,more_than_zero_btagOneMuon)
      cutTreeData.TAttach(PFMTCut30,onebtagOneMuon)
      cutTreeData.TAttach(PFMTCut30,more_than_one_btagOneMuon)
      cutTreeData.TAttach(PFMTCut30,twobtagOneMuon)
      cutTreeData.TAttach(PFMTCut30,more_than_two_btagOneMuon)


      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = zerobtagOneMuon,
      htBins = HTBins,TriggerDict = mu_triggers ,lab ="btag_zero_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_zero_btagOneMuon,
      htBins = HTBins,TriggerDict = mu_triggers ,lab ="btag_morethanzero_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = onebtagOneMuon,
      htBins = HTBins,TriggerDict = mu_triggers ,lab ="btag_one_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_one_btagOneMuon,
      htBins = HTBins,TriggerDict = mu_triggers ,lab ="btag_morethanone_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = twobtagOneMuon,
      htBins = HTBins,TriggerDict = mu_triggers ,lab ="btag_two_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_two_btagOneMuon,
      htBins = HTBins,TriggerDict = mu_triggers ,lab ="btag_morethantwo_OneMuon_") )
         
      cutTreeData.TAttach(minDRMuonJetCut,DiMuon)
      cutTreeData.TAttach(DiMuon,ZMass_2Muons)
      cutTreeData.TAttach(ZMass_2Muons,zerobtagDiMuon) 
      cutTreeData.TAttach(ZMass_2Muons,more_than_zero_btagDiMuon)
      cutTreeData.TAttach(ZMass_2Muons,onebtagDiMuon) 
      cutTreeData.TAttach(ZMass_2Muons,more_than_one_btagDiMuon)
      cutTreeData.TAttach(ZMass_2Muons,twobtagDiMuon) 
      cutTreeData.TAttach(ZMass_2Muons,more_than_two_btagDiMuon)

      # avobe here does one big inclusive bin!
      # Now lets start binning in HT bins
      # So we can HADD the files at the end and get a chorent set to save the book keeping nightmare:
      # we arrange the HT bins so they are not repoduced though out threshold runs.
      
      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = zerobtagDiMuon,
      htBins = HTBins,TriggerDict = mu_triggers,lab ="btag_zero_DiMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_zero_btagDiMuon,
      htBins = HTBins,TriggerDict = mu_triggers,lab ="btag_morethanzero_DiMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = onebtagDiMuon,
      htBins = HTBins,TriggerDict = mu_triggers,lab ="btag_one_DiMuon_") )
   
      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_one_btagDiMuon,
      htBins = HTBins,TriggerDict = mu_triggers,lab ="btag_morethanone_DiMuon_") )
   
      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = twobtagDiMuon,
      htBins = HTBins,TriggerDict = mu_triggers,lab ="btag_two_DiMuon_") )
   
      out.append(AddBinedHist(cutTree = cutTreeData,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_two_btagDiMuon,
      htBins = HTBins,TriggerDict = mu_triggers,lab ="btag_morethantwo_DiMuon_") )
     
  return (cutTreeData,secondJetET,out)

#Second MC!

def MakeBtagMCTree(Threshold, Muon = None,Split = None):
  out = []

  HTBins = []
  
  if int(Threshold) is 100 and Split == None : HTBins = [375+100*i for i in range(6)]
  if int(Threshold) is 100 and Split == "Had_One" : HTBins = [375+100*i for i in range(4)]
  if int(Threshold) is 100 and Split == "Had_Two" : HTBins = [675+100*i for i in range(3)]
  if int(Threshold) is 100 and Split == "Muon_One" : HTBins = [375,475]
  if int(Threshold) is 100 and Split == "Muon_Two" : HTBins = [475,575,675]
  if int(Threshold) is 100 and Split == "Muon_Three" : HTBins = [675,775,875]
  if int(Threshold) is 73 : HTBins = [275.,325.]
  if int(Threshold) is 86 : HTBins = [325.,375.]
  secondJetET = OP_SecondJetEtCut(Threshold)
  cutTreeMC = Tree("MC")
  #cutTreeMC.Attach(GE2Jets)
  cutTreeMC.Attach(ht250_Trigger)
  #cutTreeMC.TAttach(GE2Jets,ht250_Trigger)
  cutTreeMC.TAttach(ht250_Trigger,NoiseFilt)
  cutTreeMC.TAttach(NoiseFilt,GoodVertexMonster)
  cutTreeMC.TAttach(GoodVertexMonster,recHitCut)
  cutTreeMC.TAttach(recHitCut,LeadingJetEta)
  cutTreeMC.TAttach(LeadingJetEta,secondJetET)
  cutTreeMC.TAttach(secondJetET,oddJet)
  cutTreeMC.TAttach(oddJet,badMuonInJet)
  cutTreeMC.TAttach(badMuonInJet, oddElectron)
  cutTreeMC.TAttach(oddElectron,oddPhoton)
  cutTreeMC.TAttach(oddPhoton,numComElectrons)
  cutTreeMC.TAttach(numComElectrons,numComPhotons)
  cutTreeMC.TAttach(numComPhotons,VertexPtOverHT)
  cutTreeMC.TAttach(VertexPtOverHT,htCut275)
  cutTreeMC.TAttach(htCut275,DeadEcalCutMC)
 
  #Here be plots after all the cuts!!
  cutTreeMC.TAttach(DeadEcalCutMC,MHT_METCut)
  if Muon == None:
      pass
     
  else:
      cutTreeMC.TAttach(MHT_METCut,Mu45PtCut)
      cutTreeMC.TAttach(Mu45PtCut,minDRMuonJetCut)
      cutTreeMC.TAttach(minDRMuonJetCut,OneMuon)
      cutTreeMC.TAttach(OneMuon,ZMassCut)
      cutTreeMC.TAttach(ZMassCut,PFMTCut30)
      cutTreeMC.TAttach(PFMTCut30,zerobtagOneMuon)
      cutTreeMC.TAttach(PFMTCut30,more_than_zero_btagOneMuon)
      cutTreeMC.TAttach(PFMTCut30,onebtagOneMuon)
      cutTreeMC.TAttach(PFMTCut30,more_than_one_btagOneMuon)
      cutTreeMC.TAttach(PFMTCut30,twobtagOneMuon)
      cutTreeMC.TAttach(PFMTCut30,more_than_two_btagOneMuon)

      
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = PFMTCut30,
      htBins = HTBins,TriggerDict = None ,lab ="OneMuon_") )
      """
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = zerobtagOneMuon,
      htBins = HTBins,TriggerDict = None ,lab ="btag_zero_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_zero_btagOneMuon,
      htBins = HTBins,TriggerDict = None ,lab ="btag_morethanzero_OneMuon_") )
 
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = onebtagOneMuon,
      htBins = HTBins,TriggerDict = None ,lab ="btag_one_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_one_btagOneMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_morethanone_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = twobtagOneMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_two_OneMuon_") )

      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_two_btagOneMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_morethantwo_OneMuon_") )
      """

      cutTreeMC.TAttach(minDRMuonJetCut,DiMuon)
      cutTreeMC.TAttach(DiMuon,ZMass_2Muons)
      cutTreeMC.TAttach(ZMass_2Muons,zerobtagDiMuon) 
      cutTreeMC.TAttach(ZMass_2Muons,more_than_zero_btagDiMuon)
      cutTreeMC.TAttach(ZMass_2Muons,onebtagDiMuon) 
      cutTreeMC.TAttach(ZMass_2Muons,more_than_one_btagDiMuon)
      cutTreeMC.TAttach(ZMass_2Muons,twobtagDiMuon) 
      cutTreeMC.TAttach(ZMass_2Muons,more_than_two_btagDiMuon)

      # avobe here does one big inclusive bin!
      # Now lets start binning in HT bins
      # So we can HADD the files at the end and get a chorent set to save the book keeping nightmare:
      # we arrange the HT bins so they are not repoduced though out threshold runs.
      
      """ 
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = zerobtagDiMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_zero_DiMuon_") )
      
      
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_zero_btagDiMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_morethanzero_DiMuon_") )
     
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = onebtagDiMuon,
      htBins = HTBins,TriggerDict =None,lab ="btag_one_DiMuon_") )
   
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_one_btagDiMuon,
      htBins = HTBins,TriggerDict =None ,lab ="btag_morethanone_DiMuon_") )
   
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = twobtagDiMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_two_DiMuon_") )
   
      out.append(AddBinedHist(cutTree = cutTreeMC,
      OP = ("BtagSystematicPlots",genericPSet), cut = more_than_two_btagDiMuon,
      htBins = HTBins,TriggerDict = None,lab ="btag_morethantwo_DiMuon_") )
      """

  return (cutTreeMC,secondJetET,out)



