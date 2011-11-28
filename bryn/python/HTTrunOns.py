#!/usr/bin/env python

"""
Created by Bryn Mathias on 2010-05-07.
"""
bin = 375.
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
from copy import deepcopy
from icf.JetCorrections import *
from icf.utils import json_to_pset

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
SecJets=PSet(
Prefix="green",
Suffix="Pat",
Uncorrected=False, #<TW date="07/11/2010" />
)
TerJets=PSet(
Prefix="blue",
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

# ak5_jpt = deepcopy(default_ntuple)
# ak5_jpt.Jets.Prefix="ak5JetJPT"

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
default_cc.Photons.PhotonJetDeltaR=0.5
default_cc.Photons.PhotonIsoTypePtCutoff=30.
# -----------------------------------------------------------------------------
# Definition of common objects
default_common = deepcopy(defaultConfig.Common)
default_common.ApplyXCleaning=True
default_common.Jets.PtCut=50.0*(bin/375.)
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
default_common.Muons.PtCut=40.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=-1.
default_common.Muons.CombIsoCut=0.15
default_common.Muons.ApplyID = True
default_common.Muons.TightID = True
default_common.Muons.RequireLooseForOdd = True
default_common.Photons.EtCut=25.0
default_common.Photons.EtaCut=2.5
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

# CMSSW_3_8_4_patch3 V14-00-02 samples

# -----------------------------------------------------------------------------


# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!

from icf.JetCorrections import *
corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
# corPset =  CorrectionPset("Spring10DataV2_L2L3Residual_AK5PF.txt")
JetCorrections = JESCorrections( corPset.ps() ,True)
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()



HT_Trigger_PS = PSet(
    Verbose = False,
    UsePreScaledTriggers = False,
    Triggers = [
        ]
    )


Cross_Trigger_PS = PSet(
    Verbose = False,
    UsePreScaledTriggers = False,
    Triggers =[]
    )


def PreScaledPair(cutTree = None, cut = None, NumeratorTrig = None, DenominatorTrig = None,Label = "", Debug = False):
  if str(type(NumeratorTrig)) != "<type 'list'>":
    NumeratorTrig = [NumeratorTrig]
  if str(type(DenominatorTrig)) != "<type 'list'>":
    DenominatorTrig = [DenominatorTrig]
  print "RefTrig = %s, testTrig = %s"%(DenominatorTrig,NumeratorTrig)
  # print type(NumeratorTrig) , type(DenominatorTrig)
  out = []
  if Debug == True:
    op = PreScaledTriggers( PSet(DirName = "DEBUG_"+Label+NumeratorTrig[0]+"_"+DenominatorTrig[0],NumeratorTrigger = NumeratorTrig[0], DenominatorTrigger= DenominatorTrig[0]).ps() )
  if Debug == False:
    op = SimplePreScaledTriggers( PSet(DirName = Label+NumeratorTrig[0]+"_"+DenominatorTrig[0],NumeratorTrigger = NumeratorTrig, DenominatorTrigger = DenominatorTrig).ps() )

  cutTree.TAttach(cut,op)
  out.append(op)
  return out
  """docstring for PreScaledPair"""
  pass


def AddHistPair(cutTree = None,cut = None, RefTrig = None, TestTrig = None):
  """docstring for AddBinedHist"""
  out = []
  refTrigs = None
  if "Mu40" in RefTrig:
   refTrigs = [TestTrig,RefTrig]
  else: refTrigs = [TestTrig]
  checkExists = CheckTrigExists( PSet(TrigExistsList = [RefTrig,TestTrig]).ps() )
  refPlots = PL_TriggerTurnOns( PSet(DirName = RefTrig+"_For_"+TestTrig, MinObjects = 0,
                                     MaxObjects = 15, Plots = True, ReWeight = False if "Mu40" not in RefTrig else False,
                                     TriggerReWeight = refTrigs,    Verbose = True,
                                     ReWeightL1 = False, L1TriggerReWeight = refTrigs).ps())

  testTrigPlots = PL_TriggerTurnOns( PSet(DirName = TestTrig+"_From_"+RefTrig, MinObjects = 0,
                                          MaxObjects = 15, Plots = True, ReWeight = False,
                                          TriggerReWeight = [TestTrig],  Verbose = True,
                                          ReWeightL1 = False, L1TriggerReWeight = refTrigs).ps())

  refTrigPS =  PSet(Verbose = True,UsePreScaledTriggers = True,Triggers = [] )
  refTrigPS.Triggers = [RefTrig]
  refTrigOP = OP_MultiTrigger( refTrigPS.ps() )
  testTrigPS = PSet(Verbose = True,UsePreScaledTriggers = True,Triggers = [] )
  testTrigPS.Triggers = [TestTrig]
  print "RefTrig = %s, testTrig = %s"%(refTrigPS.Triggers[0],testTrigPS.Triggers[0])
  testTrigOP = OP_MultiTrigger( testTrigPS.ps() )
  cutTree.TAttach(cut,checkExists)
  cutTree.TAttach(checkExists,refTrigOP)
  cutTree.TAttach(refTrigOP,refPlots)
  cutTree.TAttach(refTrigOP,testTrigOP)
  cutTree.TAttach(testTrigOP,testTrigPlots)
  out.append(refTrigOP)
  out.append(refPlots)
  out.append(testTrigPlots)
  out.append(testTrigOP)
  out.append(checkExists)
  return out



def AddHistPairWithL1(cutTree = None,cut = None, RefTrig = None, TestTrig = None, L1ListRef = None,L1ListTest = None):
  """docstring for AddBinedHist"""
  out = []
  refTrigs = None
  if "Mu" in RefTrig:
   refTrigs = [TestTrig,RefTrig]
  else: refTrigs = [TestTrig]
  refPlots = PL_TriggerTurnOns( PSet(DirName = RefTrig+"_For_"+TestTrig,MinObjects =0 ,
                                MaxObjects = 15,Plots = True, ReWeight = True if "Mu" not in RefTrig else False,
                                TriggerReWeight = refTrigs,   Verbose = False,
                                ReWeightL1 = False, L1TriggerReWeight = [L1ListRef]).ps())

  testTrigPlots = PL_TriggerTurnOns( PSet(DirName = TestTrig+"_From_"+RefTrig,MinObjects = 0,
                                     MaxObjects = 15,Plots = True, ReWeight = True,
                                     TriggerReWeight = [TestTrig], Verbose = False,
                                     ReWeightL1 = True, L1TriggerReWeight = [L1ListTest]).ps())


  refTrigPS =  PSet(Verbose = False,UsePreScaledTriggers = True,Triggers = [] )
  refTrigPS.Triggers = [RefTrig]
  refTrigOP = OP_MultiTrigger( refTrigPS.ps() )
  testTrigPS = PSet(Verbose = False,UsePreScaledTriggers = True,Triggers = [] )
  testTrigPS.Triggers = [TestTrig]
  print "RefTrig = %s, testTrig = %s"%(refTrigPS.Triggers[0],testTrigPS.Triggers[0])
  testTrigOP = OP_MultiTrigger( testTrigPS.ps() )
  cutTree.TAttach(cut,refTrigOP)
  cutTree.TAttach(refTrigOP,refPlots)
  cutTree.TAttach(refTrigOP,testTrigOP)
  cutTree.TAttach(testTrigOP,testTrigPlots)
  out.append(refTrigOP)
  out.append(refPlots)
  out.append(testTrigPlots)
  out.append(testTrigOP)
  return out
  pass






DeadEcalCutData = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt")
#Standard Event Selection
LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(0.)
LeadingJetCut = OP_FirstJetPtCut(10.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(100.*(bin/375.))
badMuonInJet = OP_BadMuonInJet()
numComElectrons = OP_NumComElectrons("<=",0)
numComMuons = OP_NumComMuons("==",1)
oneMuon = OP_NumComMuons("==",1)
diMuon = OP_NumComMuons("==",2)
zeroMuon = OP_NumComMuons("<=",0)
ZMassCut = RECO_2ndMuonMass(25.0, 91.2, True, "all")

numComPhotons = OP_NumComPhotons("<=",0)
muDr = RECO_MuonJetDRCut(0.5)
VertexPtOverHT = OP_SumVertexPtOverHT(0.1)
# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses
MHT_METCut = OP_MHToverMET(1.25,50.)
# AK5 Calo
json_ouput = JSONOutput("filtered")
json_lost = JSONOutput("lost")
alphaT = OP_CommonAlphaTCut(0.53)
json = JSONFilter("Json Mask", json_to_pset("/home/hep/db1110/public_html/Golden2011.json"))
evDump = EventDump()
# htTriggerEmu = OP_TriggerHT_Emu(250.,40.)
cutTreeData = Tree("Data")
out = []

skim_ps=PSet(
    SkimName = "myskim",
    DropBranches = False,
    Branches = [
        " keep * "
        ]
)

badEvents =runLumiCutter(PSet(Run= [162811, 163233, 163374, 163589, 163759, 163817, 165121, 165364, 165415, 165467, 165472, 165506, 165567, 165570, 165993, 166034, 166049, 166380, 166514, 166565, 166701, 166842, 166864, 166960, 167102, 167282, 167284, 167675, 167807, 167830, 167830, 167898, 167913, 167913, 170876, 170876, 171050, 171050, 171156, 171178, 171178, 171369, 171484, 171484, 171578, 171578, 171812, 171876, 171897, 172033, 172791, 172791, 172799, 172802, 172822, 172822, 172868, 172868, 172949, 172952, 173198, 173241, 173241, 173243, 173380, 173389, 173439, 173657, 173657, 173692, 173692, 173692, 175975, 175990, 176023, 176023, 176201, 176286, 176286, 176304, 176309, 176309, 176547, 176548, 176701, 176702, 176765, 176771, 176771, 176771, 176795, 176796, 176796, 176799, 176844, 176886, 176928, 176933, 176982, 177053, 177074, 177096, 177183, 177183, 177201, 177201, 177222, 177730, 177782, 177782, 177782, 177788, 177875, 178098, 178420, 178421, 178421, 178479, 178479, 178703, 178786, 178786, 178803, 178803, 178920, 178970, 179411, 179411, 179411, 179411, 179434, 179497, 179547, 179889, 180072, 180072, 180076, 180076, 180241, 180241, 180241],Lumi =[4, 274, 671, 46, 182, 118, 242, 1132, 812, 113, 493, 57, 540, 696, 778, 203, 57, 637, 12, 12, 79, 7, 318, 60, 6, 38, 891, 517, 1406, 171, 458, 1334, 12, 14, 180, 415, 53, 92, 211, 149, 731, 61, 358, 79, 347, 696, 323, 382, 295, 256, 664, 67, 203, 304, 1922, 616, 1755, 553, 933, 680, 665, 16, 759, 13, 199, 283, 307, 68, 90, 2250, 89, 927, 179, 56, 60, 65, 135, 166, 62, 186, 484, 696, 28, 624, 8, 399, 110, 148, 64, 78, 42, 10, 45, 153, 61, 378, 7, 82, 4, 530, 488, 129, 9, 98, 258, 63, 59, 213, 160, 73, 79, 22, 148, 183, 53, 111, 230, 189, 68, 177, 194, 67, 152, 55, 207, 157, 10, 23, 6, 96, 83, 192, 233, 169, 61, 80, 201, 229, 129, 65, 99]).ps())

skim = SkimOp(skim_ps.ps())
cutTreeData.Attach(json)
triggers = ["HLT_HT250_AlphaT0p55_v1","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p53_v2","HLT_HT250_AlphaT0p53_v3","HLT_HT250_AlphaT0p53_v4","HLT_HT250_AlphaT0p53_v5","HLT_HT250_AlphaT0p53_v6","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p58_v3","HLT_HT300_AlphaT0p52_v1","HLT_HT300_AlphaT0p52_v2","HLT_HT300_AlphaT0p52_v3","HLT_HT300_AlphaT0p52_v4","HLT_HT300_AlphaT0p52_v5","HLT_HT300_AlphaT0p53_v5","HLT_HT300_AlphaT0p53_v6","HLT_HT300_AlphaT0p53_v6","HLT_HT300_AlphaT0p54_v5","HLT_HT350_AlphaT0p51_v1","HLT_HT350_AlphaT0p51_v2","HLT_HT350_AlphaT0p51_v3","HLT_HT350_AlphaT0p51_v4","HLT_HT350_AlphaT0p51_v5","HLT_HT350_AlphaT0p52_v1","HLT_HT350_AlphaT0p52_v2","HLT_HT350_AlphaT0p52_v2","HLT_HT350_AlphaT0p53_v10","HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4","HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10"]
triggers = ["HLT_HT250_v5"]
CheckPreOverLapsOp = CheckPreOverLaps()
# for trig in triggers:
   # op = JSONOutput("%s"%(trig))
#   trigCut = CheckTrigExists( PSet(TrigExistsList = ["%s"%(trig)]).ps() )
   # trigCut = OP_MultiTrigger(  PSet(Verbose = True,UsePreScaledTriggers = True,Triggers = ["%s"%(trig)] ).ps() )
   # cutTreeData.TAttach(json,trigCut)
   # cutTreeData.TAttach(trigCut,skim)
#   cutTreeData.TAttach(trigCut,op)
#   out.append(trigCut)
#   out.append(op)
cutTreeData.TAttach(json,badEvents)
cutTreeData.FAttach(badEvents,json_lost)
cutTreeData.TAttach(badEvents,json_ouput)
cutTreeData.TAttach(badEvents,NoiseFilt)
# cutTreeData.Attach(NoiseFilt)
# cutTreeData.TAttach(NoiseFilt,CheckPreOverLapsOp)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,numComElectrons)
cutTreeData.TAttach(numComElectrons,numComPhotons)
cutTreeData.TAttach(numComPhotons,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,oddJet)
cutTreeData.TAttach(oddJet,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,secondJetET)
cutTreeData.TAttach(secondJetET,oneMuon)
cutTreeData.TAttach(secondJetET,zeroMuon)
cutTreeData.TAttach(secondJetET,diMuon)
cutTreeData.TAttach(diMuon,ZMassCut)
# If no preslection:
# cutTreeData.TAttach(json,AlphaT_Trigger_Filter)
# cutTreeData.TAttach(AlphaT_Trigger_Filter,Plots_TriggerOnly)
ht275 = RECO_CommonHTCut(275.)
ht325 = RECO_CommonHTCut(325.)
ht375 = RECO_CommonHTCut(375.)
# htLess325 = RECO_CommonHLTessThanCut(375.)
# htLess475 = RECO_CommonHLTessThanCut(475.)
# If muon required --- AlphaT and Meff Turn ons
cutTreeData.TAttach(oneMuon,DeadEcalCutData)
cutTreeData.TAttach(DeadEcalCutData,MHT_METCut)
cutTreeData.TAttach(MHT_METCut,muDr)
cutTreeData.TAttach(muDr,ht375)
cutTreeData.TAttach(muDr,ht275)
cutTreeData.TAttach(muDr,ht325)
# cutTreeData.TAttach(ht375,htLess475)

alphatTesting = {
  "HLT_HT250_AlphaT0p55_v1": ("HLT_Mu5_HT200_v4" ,[275.,]),
  "HLT_HT250_AlphaT0p55_v2": ("HLT_Mu8_HT200_v4" ,[275.,]),
  "HLT_HT250_AlphaT0p53_v2": ("HLT_Mu15_HT200_v2",[275.,]),
  "HLT_HT250_AlphaT0p53_v3": ("HLT_Mu15_HT200_v3",[275.,]),
  "HLT_HT250_AlphaT0p53_v4": ("HLT_Mu15_HT200_v4",[275.,]),
  "HLT_HT250_AlphaT0p53_v5": ("HLT_Mu30_HT200_v1",[275.,]),
  "HLT_HT250_AlphaT0p53_v6": ("HLT_Mu40_HT200_v4",[275.,]),
  "HLT_HT250_AlphaT0p55_v2": ("HLT_Mu40_HT200_v4",[275.,]),
  "HLT_HT300_AlphaT0p52_v1": ("HLT_Mu5_HT200_v4" ,[325.,]),
  "HLT_HT300_AlphaT0p52_v2": ("HLT_Mu8_HT200_v4" ,[325.,]),
  "HLT_HT300_AlphaT0p52_v3": ("HLT_Mu15_HT200_v2",[325.,]),
  "HLT_HT300_AlphaT0p52_v4": ("HLT_Mu15_HT200_v3",[325.,]),
  "HLT_HT300_AlphaT0p52_v5": ("HLT_Mu15_HT200_v4",[325.,]),
  "HLT_HT300_AlphaT0p53_v5": ("HLT_Mu30_HT200_v1",[325.,]),
  "HLT_HT300_AlphaT0p53_v6": ("HLT_Mu40_HT200_v3",[325.,]),
  "HLT_HT300_AlphaT0p53_v6": ("HLT_Mu40_HT200_v4",[325.,]),
  "HLT_HT350_AlphaT0p51_v1": ("HLT_Mu5_HT200_v4" ,[375.,]),
  "HLT_HT350_AlphaT0p51_v2": ("HLT_Mu8_HT200_v4" ,[375.,]),
  "HLT_HT350_AlphaT0p51_v3": ("HLT_Mu15_HT200_v2",[375.,]),
  "HLT_HT350_AlphaT0p51_v4": ("HLT_Mu15_HT200_v3",[375.,]),
  "HLT_HT350_AlphaT0p51_v5": ("HLT_Mu15_HT200_v4",[375.,]),
  "HLT_HT350_AlphaT0p52_v1": ("HLT_Mu30_HT200_v1",[375.,]),
  "HLT_HT350_AlphaT0p52_v2": ("HLT_Mu40_HT200_v3",[375.,]),
  "HLT_HT350_AlphaT0p52_v2": ("HLT_Mu40_HT200_v4",[375.,]),
  "HLT_HT350_AlphaT0p52_v2": ("HLT_Mu40_HT200_v4",[375.,]),
  "HLT_HT350_AlphaT0p53_v10": ("HLT_Mu40_HT300_v4",[375.,]),
  "HLT_HT350_AlphaT0p53_v10": ("HLT_Mu40_HT300_v5",[375.,]),
  "HLT_HT400_AlphaT0p51_v1": ("HLT_Mu5_HT200_v4" ,[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v2": ("HLT_Mu8_HT200_v4" ,[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v3": ("HLT_Mu15_HT200_v2",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v4": ("HLT_Mu15_HT200_v3",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v5": ("HLT_Mu15_HT200_v4",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v6": ("HLT_Mu30_HT200_v1",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v7": ("HLT_Mu40_HT200_v3",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v7": ("HLT_Mu40_HT200_v4",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v10":("HLT_Mu40_HT300_v4",[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v10":("HLT_Mu40_HT300_v5",[475.,575.,675.,775.,875.]),
}
# refTrigList =  ["HLT_Mu40_HT200_v*","HLT_Mu40_HT200_v*"]
# TestTrigList = ["HLT_HT250_AlphaT0p53_v6","HLT_HT250_AlphaT0p55_v*"]

for key,vals in alphatTesting.iteritems():
  for htbin in vals[1]:
    cut = eval("RECO_CommonHTCut(%f)"%(htbin))
    out.append(cut)
    cutTreeData.TAttach(muDr,cut)
    out.append(PreScaledPair(cutTreeData,cut,key,vals[0],"HT%d_"%(htbin)))

AlphaTwithDiMu = {
  "HLT_HT250_AlphaT0p55_v2": ("HLT_DoubleMu3_HT200_v4" ,[275.,]),
  "HLT_HT250_AlphaT0p58_v3": ("HLT_DoubleMu8_Mass8_HT200_v4" ,[275.,]),
  "HLT_HT250_AlphaT0p58_v3": ("HLT_DoubleMu8_Mass8_HT200_v5" ,[275.,]),

}
for key,vals in AlphaTwithDiMu.iteritems():
 for htbin in vals[1]:
   cut = eval("RECO_CommonHTCut(%f)"%(htbin))
   out.append(cut)
   cutTreeData.TAttach(ZMassCut,cut)
   out.append(PreScaledPair(cutTreeData,cut,key,vals[0],"DiMu_HT%d_"%(htbin)))



# If muon is not required
htTesting = {

"HLT_HT350_v11" : ("HLT_HT250_v11", "HLT_HT300_v12","HLT_Mu40_HT300_v4") ,
"HLT_HT350_v2"  : ("HLT_HT250_v2" , "HLT_HT300_v3" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT350_v3"  : ("HLT_HT250_v3" , "HLT_HT300_v4" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT350_v4"  : ("HLT_HT250_v4" , "HLT_HT300_v5" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT350_v5"  : ("HLT_HT250_v5" , "HLT_HT300_v6" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT350_v6"  : ("HLT_HT250_v6" , "HLT_HT300_v7" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT350_v7"  : ("HLT_HT250_v7" , "HLT_HT300_v8" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT350_v8"  : ("HLT_HT250_v8" , "HLT_HT300_v9" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT400_v11" : ("HLT_HT250_v11", "HLT_HT300_v12","HLT_Mu40_HT300_v4") ,
"HLT_HT400_v2"  : ("HLT_HT250_v2" , "HLT_HT300_v3" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT400_v3"  : ("HLT_HT250_v3" , "HLT_HT300_v4" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT400_v4"  : ("HLT_HT250_v4" , "HLT_HT300_v5" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT400_v5"  : ("HLT_HT250_v5" , "HLT_HT300_v6" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT400_v6"  : ("HLT_HT250_v6" , "HLT_HT300_v7" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT400_v7"  : ("HLT_HT250_v7" , "HLT_HT300_v8" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT400_v8"  : ("HLT_HT250_v8" , "HLT_HT300_v9" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT450_v11" : ("HLT_HT250_v11", "HLT_HT300_v12","HLT_Mu40_HT300_v4") ,
"HLT_HT450_v2"  : ("HLT_HT250_v2" , "HLT_HT300_v3" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT450_v3"  : ("HLT_HT250_v3" , "HLT_HT300_v4" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT450_v4"  : ("HLT_HT250_v4" , "HLT_HT300_v5" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT450_v5"  : ("HLT_HT250_v5" , "HLT_HT300_v6" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT450_v6"  : ("HLT_HT250_v6" , "HLT_HT300_v7" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT450_v7"  : ("HLT_HT250_v7" , "HLT_HT300_v8" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT450_v8"  : ("HLT_HT250_v8" , "HLT_HT300_v9" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT550_v11" : ("HLT_HT250_v11", "HLT_HT300_v12","HLT_Mu40_HT300_v4") ,
"HLT_HT550_v2"  : ("HLT_HT250_v2" , "HLT_HT300_v3" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT550_v3"  : ("HLT_HT250_v3" , "HLT_HT300_v4" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT550_v4"  : ("HLT_HT250_v4" , "HLT_HT300_v5" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT550_v5"  : ("HLT_HT250_v5" , "HLT_HT300_v6" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT550_v6"  : ("HLT_HT250_v6" , "HLT_HT300_v7" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT550_v7"  : ("HLT_HT250_v7" , "HLT_HT300_v8" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT550_v8"  : ("HLT_HT250_v8" , "HLT_HT300_v9" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT600_v1"  : ("HLT_HT250_v8",  ) ,
"HLT_HT600_v4"  : ("HLT_HT250_v11", ) ,
"HLT_HT750_v3"  : ("HLT_HT250_v11", ) ,
"HLT_HT450_v11" : "HLT_HT300_v12"  ,
"HLT_HT450_v2"  : "HLT_HT300_v3"   ,
"HLT_HT450_v3"  : "HLT_HT300_v4"   ,
"HLT_HT450_v4"  : "HLT_HT300_v5"   ,
"HLT_HT450_v5"  : "HLT_HT300_v6"   ,
"HLT_HT450_v6"  : "HLT_HT300_v7"   ,
"HLT_HT450_v7"  : "HLT_HT300_v8"   ,
"HLT_HT450_v8"  : "HLT_HT300_v9"   ,
"HLT_HT550_v11" : "HLT_HT350_v11"  ,
"HLT_HT550_v2"  : "HLT_HT350_v2"   ,
"HLT_HT550_v3"  : "HLT_HT350_v3"   ,
"HLT_HT550_v4"  : "HLT_HT350_v4"   ,
"HLT_HT550_v5"  : "HLT_HT350_v5"   ,
"HLT_HT550_v6"  : "HLT_HT350_v6"   ,
"HLT_HT550_v7"  : "HLT_HT350_v7"   ,
"HLT_HT550_v8"  : "HLT_HT350_v8"   ,
"HLT_HT600_v1"  : "HLT_HT350_v8"   ,

}






for key,test in htTesting.iteritems():
  for ref in test:
   out.append(PreScaledPair(cutTree = cutTreeData, cut = zeroMuon, NumeratorTrig = key, DenominatorTrig = ref, Label = "", Debug = False))
HTDebug = {
"HLT_HT450_v11" : ("HLT_HT250_v11", "HLT_HT300_v12")  ,
"HLT_HT450_v2"  : ("HLT_HT250_v2" , "HLT_HT300_v3" )  ,
"HLT_HT450_v3"  : ("HLT_HT250_v3" , "HLT_HT300_v4" )  ,
"HLT_HT450_v4"  : ("HLT_HT250_v4" , "HLT_HT300_v5" )  ,
"HLT_HT450_v5"  : ("HLT_HT250_v5" , "HLT_HT300_v6" )  ,
"HLT_HT450_v6"  : ("HLT_HT250_v6" , "HLT_HT300_v7" )  ,
"HLT_HT450_v7"  : ("HLT_HT250_v7" , "HLT_HT300_v8" )  ,
"HLT_HT450_v8"  : ("HLT_HT250_v8" , "HLT_HT300_v9" )  ,
"HLT_HT350_v2"  : ("HLT_HT250_v2" , "HLT_HT300_v3" )  ,
"HLT_HT350_v11" : ("HLT_Mu40_HT300_v4",) ,
"HLT_HT350_v2"  : ("HLT_Mu5_HT200_v4" ,) ,
"HLT_HT350_v3"  : ("HLT_Mu8_HT200_v4",) ,
"HLT_HT350_v4"  : ("HLT_Mu15_HT200_v2" ,) ,
"HLT_HT350_v5"  : ("HLT_Mu15_HT200_v3" ,) ,
"HLT_HT350_v6"  : ("HLT_Mu15_HT200_v4" ,) ,
"HLT_HT350_v7"  : ("HLT_Mu30_HT200_v1" ,) ,
"HLT_HT350_v8"  : ("HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT400_v11" : ("HLT_Mu40_HT300_v4",) ,
"HLT_HT400_v2"  : ("HLT_Mu5_HT200_v4" ,) ,
"HLT_HT400_v3"  : ("HLT_Mu8_HT200_v4",) ,
"HLT_HT400_v4"  : ("HLT_Mu15_HT200_v2" ,) ,
"HLT_HT400_v5"  : ("HLT_Mu15_HT200_v3" ,) ,
"HLT_HT400_v6"  : ("HLT_Mu15_HT200_v4" ,) ,
"HLT_HT400_v7"  : ("HLT_Mu30_HT200_v1" ,) ,
"HLT_HT400_v8"  : ("HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT450_v11" : ("HLT_Mu40_HT300_v4",) ,
"HLT_HT450_v2"  : ("HLT_Mu5_HT200_v4" ,) ,
"HLT_HT450_v3"  : ("HLT_Mu8_HT200_v4",) ,
"HLT_HT450_v4"  : ("HLT_Mu15_HT200_v2" ,) ,
"HLT_HT450_v5"  : ("HLT_Mu15_HT200_v3" ,) ,
"HLT_HT450_v6"  : ("HLT_Mu15_HT200_v4" ,) ,
"HLT_HT450_v7"  : ("HLT_Mu30_HT200_v1" ,) ,
"HLT_HT450_v8"  : ("HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT550_v11" : ("HLT_Mu40_HT300_v4",) ,
"HLT_HT550_v2"  : ("HLT_Mu5_HT200_v4" ,) ,
"HLT_HT550_v3"  : ("HLT_Mu8_HT200_v4",) ,
"HLT_HT550_v4"  : ("HLT_Mu15_HT200_v2", ) ,
"HLT_HT550_v5"  : ("HLT_Mu15_HT200_v3", ) ,
"HLT_HT550_v6"  : ("HLT_Mu15_HT200_v4", ) ,
"HLT_HT550_v7"  : ("HLT_Mu30_HT200_v1", ) ,
"HLT_HT550_v8"  : ("HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,


}

for key,test in HTDebug.iteritems():
  for ref in test:
   out.append(PreScaledPair(cutTree = cutTreeData, cut = zeroMuon, NumeratorTrig = key, DenominatorTrig = ref, Label = "", Debug = True))


from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
mu_id = PSet(
   MuID = "Tight",
   MinPt = 10.,
   MaxEta = 2.5,
   MaxIsolation = 0.1,
   DRMuJet = 0.5,
   MaxGlbTrkDxy = 0.02,
   MinGlbTrkNumOfValidHits = 11,
   SegMatch2GlbMu = 1,
   PixelHitsOnInrTrk = 1,
   MaxInrTrkDz = 1.,
   doJetLoop = False,
   )
vbtfMuonId_cff = CustomVBTFMuID(mu_id.ps())
def addCutFlowData(a) :
#  a.AddWeightFilter("Weight",PreScaleWeights)
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a.AddMuonFilter("PreCC",vbtfMuonId_cff)
  a+=cutTreeData

# AK5 Calo

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

# AK5 PF

conf_ak5_pfData = deepcopy(defaultConfig)
conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfData.XCleaning = deepcopy(default_cc)
conf_ak5_pfData.Common = deepcopy(default_common)
anal_ak5_pfData=Analysis("AK5PF")
addCutFlowData(anal_ak5_pfData)

from data.Run2011.HTRun2011AB import *
from data.Run2011.MuHad_Run2011A_Complete_V15_03_02 import *
from data.Run2011.MuHad2011AB import *
from SingleMu import *
#from data.Run2011.MuHad2011AB import *
from data.Run2011.MuHad_Run2011A_Complete_V15_03_14 import *
sample = MuHad2011AB
# sample.File = sample.File[0:5]#["/Users/bryn/WokringDir/DevVersionSUSYv2/Ntuples/AK5Calo_tedSync_newFormat.root"]
sample = HTRun2011AB
# sample.File = ["/Users/bryn/github/5e33Triggers/TotalEvents.root"]
outDir = "../%s_rmAllProblems/ht%dNoUpper/"%(sample.Name,bin)

ensure_dir(outDir)
# MuHad_Run2011A_Complete_V15_03_02.File = MuHad_Run2011A_Complete_V15_03_02.File[1:10]
anal_ak5_caloData.Run(outDir,conf_ak5_caloData,[sample])

