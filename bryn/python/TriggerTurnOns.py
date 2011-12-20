#!/usr/bin/env python

"""
Created by Bryn Mathias on 2010-05-07.
"""
bin = 275.
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
default_cc.Muons.PtCut=5.0
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
default_common.Muons.PtCut=5.0
default_common.Muons.EtaCut=2.1
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
diMuon = OP_NumComMuons(">=",1)
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
alphaT = OP_CommonAlphaTCut(0.53)
json = JSONFilter("Json Mask", json_to_pset("./Golden2011.json"))
evDump = EventDump()
json_lost = JSONOutput("lost")

# htTriggerEmu = OP_TriggerHT_Emu(250.,40.)
cutTreeData = Tree("Data")
out = []
badEvents =runLumiCutter(PSet(Run= [162811,162902,162929,163252,163286,163332,163589,163759,163795,163795,163817,165120,165121,165467,165506,165514,165537,165542,165633,165970,166033,166033,166034,166049,166049,166346,166374,166408,166429,166438,166493,166502,166514,166530,166565,166701,166756,166781,166787,166839,166842,166895,166960,167102,167282,167496,167673,167740,167830,167898,167913,167913,170053,170181,170249,170249,170286,170286,175857,175857,175872,175872,175873,175874,175874,175874,175906,175906,175906,175921,175921,175921,175921,175921,175971,175971,175975,175990,175990,175990,176023,176023,176023,176201,176201,176201,176207,176286,176286,176304,176304,176309,176461,176461,176464,176467,176547,176548,176701,176702,176765,176765,176771,176771,176771,176795,176795,176796,176796,176797,176799,176841,176844,176886,176928,176929,176933,176982,177053,177074,177074,177088,177096,177131,177138,177183,177183,177201,177222,177222,177313,177318,177449,177449,177449,177452,177507,177507,177507,177509,177509,177515,177617,177718,177718,177730,177730,177730,177730,177776,177776,177782,177782,177782,177783,177788,177788,177875,177875,178097,178097,178098,178110,178116,178160,178162,178365,178420,178420,178420,178421,178421,178421,178421,178479,178479,178479,178667,178675,178703,178703,178703,178712,178786,178786,178786,178803,178803,178803,178840,178840,178840,178854,178920,178920,178970,178985,179411,179411,179411,179411,179434,179434,179497,179497,179547,179547,179889,179889,179959,180072,180072,180076,180076,180093,180222,180241,180241,180241,180250,],Lumi =[4,25,131,4,108,7,46,182,24,33,118,27,242,113,57,40,13,161,2,9,13,27,203,15,57,7,3,29,4,1,3,2,12,37,12,79,21,2,12,5,7,135,60,6,38,18,2,4,171,4,12,14,9,2,41,45,83,87,25,30,65,67,24,13,33,51,49,51,70,176,182,33,47,56,48,61,179,26,3,56,2,60,65,135,2,40,94,166,62,186,66,223,107,109,9,112,28,121,8,124,110,67,148,64,78,3,42,10,45,197,153,122,61,74,7,171,82,4,42,200,26,2,129,38,71,9,98,63,41,59,62,70,1,235,44,156,42,64,67,110,8,5,3,120,44,213,35,50,55,51,8,160,73,79,242,22,30,148,8,10,7,183,2,180,209,33,209,4,47,53,111,230,34,42,189,3,68,44,11,177,3,31,8,194,20,67,152,2,55,199,2,47,63,207,35,157,6,10,23,6,96,27,83,192,4,233,4,169,18,62,61,80,201,229,98,3,129,65,99,237]).ps())
triggers = ["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5","HLT_Mu15_HT200_v2","HLT_Mu15_HT200_v3","HLT_Mu15_HT200_v4","HLT_Mu30_HT200_v1","HLT_Mu40_HT200_v3","HLT_Mu40_HT200_v4","HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5","HLT_Mu5_HT200_v4","HLT_Mu8_HT200_v3","HLT_Mu8_HT200_v4",]
cutTreeData.Attach(json)
for trig in triggers:
  op = JSONOutput("%s"%(trig))
  trigCut = CheckTrigExists( PSet(TrigExistsList = ["%s"%(trig)]).ps() )
  cutTreeData.TAttach(json,trigCut)
  cutTreeData.TAttach(trigCut,op)
  out.append(trigCut)
  out.append(op)
cutTreeData.TAttach(json,badEvents)
cutTreeData.FAttach(badEvents,json_lost)
cutTreeData.TAttach(badEvents,json_ouput)
#cutTreeData.TAttach(badEvents,NoiseFilt)
cutTreeData.TAttach(json,NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,# oddMuon)
# cutTreeData.TAttach(oddMuon,
oddElectron)
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
  "HLT_HT250_AlphaT0p55_v1": (["HLT_Mu5_HT200_v4" ,]                   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT250_AlphaT0p55_v2": (["HLT_Mu8_HT200_v4" ,"HLT_Mu8_HT200_v3"] ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT250_AlphaT0p53_v2": (["HLT_Mu15_HT200_v2",]                   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT250_AlphaT0p53_v3": (["HLT_Mu15_HT200_v3",]                   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT250_AlphaT0p53_v4": (["HLT_Mu15_HT200_v4",]                   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT250_AlphaT0p53_v5": (["HLT_Mu30_HT200_v1",]                   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT250_AlphaT0p55_v2": (["HLT_Mu40_HT200_v4",]                   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
  "HLT_HT300_AlphaT0p52_v1": (["HLT_Mu5_HT200_v4" ,],[325.,375.]),
  "HLT_HT300_AlphaT0p52_v2": (["HLT_Mu8_HT200_v4" ,],[325.,375.]),
  "HLT_HT300_AlphaT0p52_v3": (["HLT_Mu15_HT200_v2",],[325.,375.]),
  "HLT_HT300_AlphaT0p53_v3": (["HLT_Mu15_HT200_v3",],[325.,375.]),
	"HLT_HT300_AlphaT0p53_v4": (["HLT_Mu15_HT200_v4",],[325.,375.]),
  "HLT_HT300_AlphaT0p52_v4": (["HLT_Mu15_HT200_v3",],[325.,375.]),
  "HLT_HT300_AlphaT0p52_v5": (["HLT_Mu15_HT200_v4",],[325.,375.]),
  "HLT_HT300_AlphaT0p53_v5": (["HLT_Mu30_HT200_v1",],[325.,375.]),
  "HLT_HT300_AlphaT0p53_v6": (["HLT_Mu40_HT200_v3","HLT_Mu40_HT200_v4",],[325.,375.]),
  "HLT_HT300_AlphaT0p54_v5": (["HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5",],[325.,375.]),
  "HLT_HT300_AlphaT0p55_v3": (["HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5",],[325.,375.]),
  "HLT_HT350_AlphaT0p51_v1": (["HLT_Mu5_HT200_v4" ,],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p51_v2": (["HLT_Mu8_HT200_v4" ,],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p51_v3": (["HLT_Mu15_HT200_v2",],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p51_v4": (["HLT_Mu15_HT200_v3",],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p51_v5": (["HLT_Mu15_HT200_v4",],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p52_v1": (["HLT_Mu30_HT200_v1",],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p52_v2": (["HLT_Mu40_HT200_v3","HLT_Mu40_HT200_v4"],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT350_AlphaT0p53_v10":(["HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],[375.,475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v1": (["HLT_Mu5_HT200_v4" ,],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v2": (["HLT_Mu8_HT200_v4" ,],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v3": (["HLT_Mu15_HT200_v2",],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v4": (["HLT_Mu15_HT200_v3",],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v5": (["HLT_Mu15_HT200_v4",],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v6": (["HLT_Mu30_HT200_v1",],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v7": (["HLT_Mu40_HT200_v3","HLT_Mu40_HT200_v4"],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p51_v10":(["HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],[475.,575.,675.,775.,875.]),
  "HLT_HT400_AlphaT0p52_v5":(["HLT_Mu40_HT300_v4","HLT_Mu40_HT300_v5"],[475.,575.,675.,775.,875.]),
}
# refTrigList =  ["HLT_Mu40_HT200_v*","HLT_Mu40_HT200_v*"]
# TestTrigList = ["HLT_HT250_AlphaT0p53_v6","HLT_HT250_AlphaT0p55_v*"]
#
for key,vals in alphatTesting.iteritems():
  for ref in vals[0]:
    for htbin in vals[1]:
      cut = eval("RECO_CommonHTCut(%f)"%(htbin))
      out.append(cut)
      cutTreeData.TAttach(muDr,cut)
      out.append(PreScaledPair(cutTreeData,cut,key,ref,"HT%d_"%(htbin)))

AlphaTwithDiMu = {
"HLT_HT250_AlphaT0p58_v3": (["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5"]   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
"HLT_HT250_AlphaT0p60_v3": (["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5"]   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
"HLT_HT300_AlphaT0p54_v5": (["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5"]   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
"HLT_HT300_AlphaT0p55_v3": (["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5"]   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
"HLT_HT350_AlphaT0p53_v10":(["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5"]   ,[275.,325.,375.,475.,575.,675.,775.,875.]),
"HLT_HT250_v11":(["HLT_DoubleMu8_Mass8_HT200_v4" ,"HLT_DoubleMu8_Mass8_HT200_v5","HLT_IsoMu24_eta2p1_v6"]     ,[0.,]),
"HLT_HT250_v2" :(["HLT_Mu5_HT200_v4"  ,"HLT_IsoMu12_v1"]                                                      ,[0.,]),
"HLT_HT250_v3" :(["HLT_Mu8_HT200_v4"  ,"HLT_IsoMu17_v6"]                                                      ,[0.,]),
"HLT_HT250_v4" :(["HLT_Mu15_HT200_v2" ,"HLT_IsoMu17_v8"]                                                      ,[0.,]),
"HLT_HT250_v5" :(["HLT_Mu15_HT200_v3" ,"IsoMu17_v9"]                                                          ,[0.,]),
"HLT_HT250_v6" :(["HLT_Mu15_HT200_v4" ,"HLT_IsoMu17_v10"]                                                     ,[0.,]),
"HLT_HT250_v7" :(["HLT_Mu30_HT200_v1" ,"HLT_IsoMu17_v11"]                                                     ,[0.,]),
"HLT_HT250_v8" :(["IsoMu20_v8" ,"HLT_IsoMu24_eta2p1_v3"]                                                      ,[0.,]),
"HLT_HT300_v12":(["HLT_DoubleMu8_Mass8_HT200_v4","HLT_DoubleMu8_Mass8_HT200_v5","HLT_IsoMu24_eta2p1_v6"]      ,[0.,]),
"HLT_HT300_v3" :(["HLT_Mu5_HT200_v4"  ,"HLT_IsoMu12_v1"]                                                      ,[0.,]),
"HLT_HT300_v4" :(["HLT_Mu8_HT200_v4"  ,"HLT_IsoMu17_v6"]                                                      ,[0.,]),
"HLT_HT300_v5" :(["HLT_Mu15_HT200_v2" ,"HLT_IsoMu17_v8"]                                                      ,[0.,]),
"HLT_HT300_v6" :(["HLT_Mu15_HT200_v3" ,"IsoMu17_v9"]                                                          ,[0.,]),
"HLT_HT300_v7" :(["HLT_Mu15_HT200_v4" ,"HLT_IsoMu17_v10"]                                                     ,[0.,]),
"HLT_HT300_v8" :(["HLT_Mu30_HT200_v1" ,"HLT_IsoMu17_v11"]                                                     ,[0.,]),
"HLT_HT300_v9" :(["IsoMu20_v8" ,"HLT_IsoMu24_eta2p1_v3"]                                                      ,[0.,]),

}
for key,vals in AlphaTwithDiMu.iteritems():
  for htbin in vals[1]:
    for ref in vals[0]:
      for muDR in [0.5]:
          cut = eval("RECO_CommonHTCut(%f)"%(htbin))
          out.append(cut)
          muDRcut =  RECO_MuonJetDRCut(muDR)
          out.append(muDRcut)
          cutTreeData.TAttach(diMuon,muDRcut)
          cutTreeData.TAttach(muDRcut,cut)
          out.append(PreScaledPair(cutTreeData,cut,key,ref,"DiMu_HT%d_"%(htbin)))
          out.append(PreScaledPair(cutTreeData,cut,key,ref,"DiMu_HT%d_"%(htbin),Debug = True))

# If muon is not required
htTesting = {



"HLT_HT250_v11":("HLT_DoubleMu8_Mass8_HT200_v4" ,),
"HLT_HT250_v2" :("HLT_Mu5_HT200_v4"  ,) ,
"HLT_HT250_v3" :("HLT_Mu8_HT200_v4"  ,) ,
"HLT_HT250_v4" :("HLT_Mu15_HT200_v2" ,) ,
"HLT_HT250_v5" :("HLT_Mu15_HT200_v3" ,) ,
"HLT_HT250_v6" :("HLT_Mu15_HT200_v4" ,) ,
"HLT_HT250_v7" :("HLT_Mu30_HT200_v1" ,) ,
"HLT_HT300_v11":("HLT_DoubleMu8_Mass8_HT200_v4" ,"HLT_DoubleMu8_Mass8_HT200_v5") ,
"HLT_HT300_v2" :("HLT_Mu5_HT200_v4"  ,) ,
"HLT_HT300_v3" :("HLT_Mu8_HT200_v4"  ,) ,
"HLT_HT300_v4" :("HLT_Mu15_HT200_v2" ,) ,
"HLT_HT300_v5" :("HLT_Mu15_HT200_v3" ,) ,
"HLT_HT300_v6" :("HLT_Mu15_HT200_v4" ,) ,
"HLT_HT300_v7" :("HLT_Mu30_HT200_v1" ,) ,
"HLT_HT350_v11" : ("HLT_HT250_v11","HLT_Mu40_HT300_v4") ,
"HLT_HT350_v2"  : ("HLT_HT250_v2" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT350_v3"  : ("HLT_HT250_v3" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT350_v4"  : ("HLT_HT250_v4" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT350_v5"  : ("HLT_HT250_v5" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT350_v6"  : ("HLT_HT250_v6" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT350_v7"  : ("HLT_HT250_v7" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT350_v8"  : ("HLT_HT250_v8" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT400_v11" : ("HLT_HT250_v11","HLT_Mu40_HT300_v4") ,
"HLT_HT400_v2"  : ("HLT_HT250_v2" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT400_v3"  : ("HLT_HT250_v3" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT400_v4"  : ("HLT_HT250_v4" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT400_v5"  : ("HLT_HT250_v5" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT400_v6"  : ("HLT_HT250_v6" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT400_v7"  : ("HLT_HT250_v7" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT400_v8"  : ("HLT_HT250_v8" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT450_v11" : ("HLT_HT250_v11","HLT_Mu40_HT300_v4") ,
"HLT_HT450_v2"  : ("HLT_HT250_v2" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT450_v3"  : ("HLT_HT250_v3" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT450_v4"  : ("HLT_HT250_v4" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT450_v5"  : ("HLT_HT250_v5" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT450_v6"  : ("HLT_HT250_v6" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT450_v7"  : ("HLT_HT250_v7" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT450_v8"  : ("HLT_HT250_v8" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT500_v11" : ("HLT_HT250_v11","HLT_Mu40_HT300_v4") ,
"HLT_HT500_v2"  : ("HLT_HT250_v2" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT500_v3"  : ("HLT_HT250_v3" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT500_v4"  : ("HLT_HT250_v4" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT500_v5"  : ("HLT_HT250_v5" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT500_v6"  : ("HLT_HT250_v6" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT500_v7"  : ("HLT_HT250_v7" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT550_v11" : ("HLT_HT250_v11","HLT_Mu40_HT300_v4") ,
"HLT_HT550_v2"  : ("HLT_HT250_v2" ,"HLT_Mu5_HT200_v4" ) ,
"HLT_HT550_v3"  : ("HLT_HT250_v3" ,"HLT_Mu8_HT200_v4") ,
"HLT_HT550_v4"  : ("HLT_HT250_v4" ,"HLT_Mu15_HT200_v2" ) ,
"HLT_HT550_v5"  : ("HLT_HT250_v5" ,"HLT_Mu15_HT200_v3" ) ,
"HLT_HT550_v6"  : ("HLT_HT250_v6" ,"HLT_Mu15_HT200_v4" ) ,
"HLT_HT550_v7"  : ("HLT_HT250_v7" ,"HLT_Mu30_HT200_v1" ) ,
"HLT_HT550_v8"  : ("HLT_HT250_v8" ,"HLT_Mu30_HT200_v3","HLT_Mu40_HT200_v4" ) ,
"HLT_HT600_v1"  : ("HLT_HT250_v8",  ) ,
"HLT_HT600_v4"  : ("HLT_HT250_v11", ) ,
"HLT_HT700_v2"  : ("HLT_HT250_v11", ) ,
"HLT_HT750_v3"  : ("HLT_HT250_v11", ) ,
# "HLT_HT450_v11" : "HLT_HT300_v12"  ,
# "HLT_HT450_v2"  : "HLT_HT300_v3"   ,
# "HLT_HT450_v3"  : "HLT_HT300_v4"   ,
# "HLT_HT450_v4"  : "HLT_HT300_v5"   ,
# "HLT_HT450_v5"  : "HLT_HT300_v6"   ,
# "HLT_HT450_v6"  : "HLT_HT300_v7"   ,
# "HLT_HT450_v7"  : "HLT_HT300_v8"   ,
# "HLT_HT450_v8"  : "HLT_HT300_v9"   ,
# "HLT_HT550_v11" : "HLT_HT350_v11"  ,
# "HLT_HT550_v2"  : "HLT_HT350_v2"   ,
# "HLT_HT550_v3"  : "HLT_HT350_v3"   ,
# "HLT_HT550_v4"  : "HLT_HT350_v4"   ,
# "HLT_HT550_v5"  : "HLT_HT350_v5"   ,
# "HLT_HT550_v6"  : "HLT_HT350_v6"   ,
# "HLT_HT550_v7"  : "HLT_HT350_v7"   ,
# "HLT_HT550_v8"  : "HLT_HT350_v8"   ,
# "HLT_HT600_v1"  : "HLT_HT350_v8"   ,

}

# for key,test in htTesting.iteritems():
  # for ref in test:
   # out.append(PreScaledPair(cutTree = cutTreeData, cut = zeroMuon if "Mu" not in test else oneMuon, NumeratorTrig = key, DenominatorTrig = ref, Label = "", Debug = False))
   # out.append(PreScaledPair(cutTree = cutTreeData, cut = zeroMuon if "Mu" not in test else oneMuon, NumeratorTrig = key, DenominatorTrig = ref, Label = "DEBUG_", Debug = True))



from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
mu_id = PSet(
   MuID = "Tight",
   MinPt = 5.,
   MaxEta = 2.1,
   MaxIsolation = 0.1,
   DRMuJet = 0.5,
   MaxGlbTrkDxy = 0.02,
   MinGlbTrkNumOfValidHits = 11,
   SegMatch2GlbMu = 1,
   PixelHitsOnInrTrk = 1,
   MaxInrTrkDz = 1.,
   doJetLoop = False,
   )
# vbtfMuonId_cff = CustomVBTFMuID(mu_id.ps())
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
# MuHad_Run2011A_Complete_V15_03_02.File = MuHad_Run2011A_Complete_V15_03_02.File[1:10]
#sample = HTRun2011AB

outDir = "../5GeVMuonsOddVetoVBTFID/ht%dNoUpper/"%(bin)
ensure_dir(outDir)
anal_ak5_caloData.Run(outDir,conf_ak5_caloData,[sample])

