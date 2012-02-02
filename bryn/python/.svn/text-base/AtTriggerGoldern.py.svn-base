#!/usr/bin/env python

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
from libTriggerStudies import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy
from icf.JetCorrections import *
from samples_cff import *

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
default_cc.Photons.PhotonJetDeltaR=0.5
default_cc.Photons.PhotonIsoTypePtCutoff=30.
# -----------------------------------------------------------------------------
# Definition of common objects
default_common = deepcopy(defaultConfig.Common)

default_common.ApplyXCleaning=True
default_common.Jets.PtCut=30.0
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
MC=[wjets_madgraph_vols,ttbarTauola,Zinvisible_jets,zjets_madgraph,LM0,LM1,LM2,LM3,LM4,LM5,LM6,LM9,LM12,LM13]
Pythia8=[QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2]
# CMSSW_3_8_4_patch3 V14-00-02 samples
from montecarlo.QCD_Pythia6_384patch3_V14_00_02_ALL import *
from montecarlo.QCD_Pythia8_384patch3_V14_00_02_ALL import *
from data.Jet_15pb_WithTP_json221010 import *
AllMC = QCD_Pythia6_384patch3_V14_00_02_ALL+QCD_Pythia8_384patch3_V14_00_02_ALL+MC+Pythia8



# -----------------------------------------------------------------------------


#Plot the common plots!
pset1 = PSet(
DirName      = "AllNoTrigger",
MinObjects   = 0,
MaxObjects   = 15,
StandardPlots     = True,
)
pset2 = PSet(
DirName      = "AllWithTrigger",
MinObjects   = 0,
MaxObjects   = 15,
StandardPlots     = True,
)
pset3 = PSet(
DirName      = "AllCutsNoTrigger",
MinObjects   = 0,
MaxObjects   = 15,
StandardPlots     = True,
)
pset4 = PSet(
DirName      = "AllCutsWithTrigger",
MinObjects   = 0,
MaxObjects   = 15,
StandardPlots     = True,
)
pset5 = PSet(
DirName      = "AllCutsTriggerFail",
MinObjects   = 0,
MaxObjects   = 15,
StandardPlots     = True,
)
pset6 = PSet(
DirName      = "AllTriggerFail",
MinObjects   = 0,
MaxObjects   = 15,
StandardPlots     = True,
)

AllNoTrigger = WeeklyUpdatePlots(pset1.ps())
AllWithTrigger =WeeklyUpdatePlots(pset2.ps())
AllCutsNoTrigger = WeeklyUpdatePlots(pset3.ps())
AllCutsAfterTrigger =WeeklyUpdatePlots( pset4.ps() )
AllCutsTriggerFail = WeeklyUpdatePlots(pset5.ps())
AllTriggerFail = WeeklyUpdatePlots(pset6.ps())


alphaTnumbers150 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers150",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers200 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers200",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers250 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers250",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers300 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers300",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers350 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers350",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers400 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers400",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers450 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers450",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers500 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers500",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers550 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers550",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers600 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers600",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers650 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers650",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers700 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers700",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers750 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers750",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers800 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers800",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!

from icf.JetCorrections import *
corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
# corPset =  CorrectionPset("Spring10DataV2_L2L3Residual_AK5PF.txt")
JetCorrections = JESCorrections( corPset.ps() ,True)
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()


# JetTrigger = AlphatTriggerCut(0.52414,35.) #OP_TwoTriggerCut("HLT_HT100U","HLT_HT140U")
#Standard Event Selection
LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(0.)
LeadingJetCut = OP_FirstJetPtCut(10.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(10.)
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

LessThan350 = RECO_CommonHTLessThanCut(350.)
# htCut250 = RECO_CommonHTCut(100.)

htCut150 = RECO_CommonHTCut(150.)
htCut200 = RECO_CommonHTCut(200.)
htCut250 = RECO_CommonHTCut(250.)
htCut300 = RECO_CommonHTCut(300.)
htCut350 = RECO_CommonHTCut(350.)
htCut400 = RECO_CommonHTCut(400.)
htCut450 = RECO_CommonHTCut(450.)
htCut500 = RECO_CommonHTCut(500.)
htCut550 = RECO_CommonHTCut(550.)
htCut600 = RECO_CommonHTCut(600.)
htCut650 = RECO_CommonHTCut(650.)
htCut700 = RECO_CommonHTCut(700.)
htCut750 = RECO_CommonHTCut(750.)
htCut800 = RECO_CommonHTCut(800.)


alphaT0 = HadronicAlphaT(0.55)
alphaT1 = OP_CommonAlphaTCut(0.55)
alphaT2 = OP_CommonAlphaTCut(0.55)
spikecleaner = OP_EcalSpikeCleaner()
event_display = OP_EventDisplay("EventDisplays", "common") #to draw all/common objects
alphat = OP_CommonAlphaTCut(0.55)
DeadEcalCutData = OP_DeadECALCut(0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt")
DeadEcalCutMC =   OP_DeadECALCut(0.3,0.5,30.,10,1,"./deadRegionList_START38_V12.txt")

NJet5 = OP_NumComJets(">=",3)
DiJet5 = OP_NumComJets("==",2)


# Cross check with the allhadronic analysis

VertexPtOverHT = OP_SumVertexPtOverHT(0.1)
MeffTrigger = OP_MeffTriggerCut(520., 40.,40.)
HtTrigger = OP_HtTriggerCut(150., 40.)
NoTriggerPlots150 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers150NoTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
NoTriggerPlots200 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers200NoTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
NoTriggerPlots250 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers250NoTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
NoTriggerPlots300 =   TriggerEffPlots( PSet(DirName = "alphaTnumbers300NoTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )

AlphatTriggerPlots =   TriggerEffPlots( PSet(DirName = "AlphatTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
MeffTriggerPlots =   TriggerEffPlots( PSet(DirName = "MeffTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
HtTriggerPlots =   TriggerEffPlots( PSet(DirName = "HtTrigger",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )
alphaTnumbers150F =   TriggerEffPlots( PSet(DirName = "alphaTnumbers150F",MinObjects =0 ,MaxObjects = 15,EffPlots = True).ps() )

# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses
MHT_METCut = OP_MHToverMET(1.25)
# AK5 Calo

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,oddJet)
cutTreeData.TAttach(oddJet,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,secondJetET)
##########DiJet Studies
cutTreeData.TAttach(secondJetET,VertexPtOverHT)
cutTreeData.TAttach(VertexPtOverHT,DeadEcalCutData)
cutTreeData.TAttach(DeadEcalCutData,MHT_METCut)
# cutTreeData.TAttach(MHT_METCut,NoTriggerPlots)
AtTrigger =  OP_AlphaTriggerCut(0.4,150.,70.,70.)
cutTreeData.TAttach(MHT_METCut,htCut150)
cutTreeData.TAttach(htCut150,NoTriggerPlots150)
cutTreeData.TAttach(htCut150,AtTrigger)
cutTreeData.TAttach(AtTrigger,alphaTnumbers150)
cutTreeData.FAttach(AtTrigger,alphaTnumbers150F)
AtTrigger1 =  OP_AlphaTriggerCut(0.35,200.,70.,70.)
cutTreeData.TAttach(MHT_METCut,htCut200)
cutTreeData.TAttach(htCut200,NoTriggerPlots200)
cutTreeData.TAttach(htCut200,AtTrigger1)
cutTreeData.TAttach(AtTrigger1,alphaTnumbers200)
AtTrigger2 =  OP_AlphaTriggerCut(0.3,250.,70.,70.)
cutTreeData.TAttach(MHT_METCut,htCut250)
cutTreeData.TAttach(htCut250,NoTriggerPlots250)
cutTreeData.TAttach(htCut250,AtTrigger2)
cutTreeData.TAttach(AtTrigger2,alphaTnumbers250)
AtTrigger3 =  OP_AlphaTriggerCut(0.25,300.,70.,70.)
cutTreeData.TAttach(MHT_METCut,htCut300)
cutTreeData.TAttach(htCut300,NoTriggerPlots300)
cutTreeData.TAttach(htCut300,AtTrigger3)
cutTreeData.TAttach(AtTrigger3,alphaTnumbers300)
