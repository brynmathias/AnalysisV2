#!/usr/bin/env python

#!/usr/bin/env python
"""
Created by Bryn Mathias on 2010-05-07.
"""

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy
from icf.JetCorrections import *
from hadronic.BatchGoldenSamples import *


# -----------------------------------------------------------------------------
# Samples
#import yours in your running script



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
ak5_pf.Electrons.Prefix="PF"
ak5_pf.Muons.Prefix="PF"
ak5_pf.SecMuons.Prefix="Pat"

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
default_cc.Muons.TrkIsoCut=-1.0
default_cc.Muons.CombIsoCut=0.15
default_cc.Muons.MuonJetDeltaR=0.5      #TW added
default_cc.Muons.MuonIsoTypePtCutoff=0. #TW added - same effect as trkIso < -1.
default_cc.Muons.RequireLooseIdForInitialFilter=True #TW added - should be false, but default set to true for consistency.
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=-1.0
default_cc.Electrons.CombIsoCut=0.2
default_cc.Electrons.ElectronJetDeltaR=0.5         #TW added
default_cc.Electrons.ElectronIsoTypePtCutoff=0.    #TW added - same effect as trkIso < -1.
default_cc.Electrons.ElectronLooseIdRequired=False #TW added
default_cc.Electrons.ElectronTightIdRequired=False #TW added
default_cc.Electrons.RequireLooseIdForInitialFilter=True #TW added - default value for consistency
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=3
default_cc.Photons.PhotonJetDeltaR=0.5       # TW added
default_cc.Photons.PhotonIsoTypePtCutoff=30. # TW added - this hasn't changed (yet?)
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
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=-1.
default_common.Muons.CombIsoCut=0.15
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
default_common.Photons.IDReq=3
default_common.AlphaT.CalcWithEt=True
# default_common.AlphaT.CalcWithEt=True
# -----------------------------------------------------------------------------


#Plot the common plots!
pset1 = PSet(
DirName      = "250_300Gev",
MinObjects   = 1,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset1 = PSet(
DirName      = "n250_300Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset2 = PSet(
DirName      = "300_350Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset2 = PSet(
DirName      = "n300_350Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset3 = PSet(
DirName      = "350Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset3 = PSet(
DirName      = "n350Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)


pset5 = PSet(
DirName      = "350Gev_afterDeadEcal",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset5 = PSet(
DirName      = "n350Gev_afterDeadEcal",
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


dalitz_plots_Inclusive = HadronicPlottingOps( PSet(
DirName    = "Dalitz_Inclusive",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)

dalitz_plots_250_300 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_250_300",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)

dalitz_plots_300_350 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_300_350",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)

dalitz_plots_350 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_350",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)




HadStandard250_300 = HadronicCommonPlots(pset1.ps())
HadStandard300_350 = HadronicCommonPlots(pset2.ps())
HadStandard350 = HadronicCommonPlots(pset3.ps())
HadStandard350_after_DeadEcal = HadronicCommonPlots(pset5.ps())
HadStandardAll = HadronicCommonPlots(pset4.ps())
nHadStandard250_300 = HadronicCommonPlots(Npset1.ps())
nHadStandard300_350 = HadronicCommonPlots(Npset2.ps())
nHadStandard350 = HadronicCommonPlots(Npset3.ps())
nHadStandardAll = HadronicCommonPlots(Npset4.ps())
nHadStandard350_after_DeadEcal = HadronicCommonPlots(Npset5.ps())
# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!

from icf.JetCorrections import *
corPset =  CorrectionPset()
JetCorrections = JESCorrections( corPset.ps() )
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()


JetTrigger = OP_TwoTriggerCut("HLT_HT100U","HLT_HT140U")
#Standard Event Selection
LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(30.)
LeadingJetCut = OP_FirstJetPtCut(100.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(100.)
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

LessThan300 = RECO_CommonHTLessThanCut(300.)
LessThan350 = RECO_CommonHTLessThanCut(350.)
htCut250 = RECO_CommonHTCut(250.)
htCut300 = RECO_CommonHTCut(300.)
htCut350 = RECO_CommonHTCut(350.)
alphaT0 = OP_CommonAlphaTCut(0.55)
alphaT1 = OP_CommonAlphaTCut(0.55)
spikecleaner = OP_EcalSpikeCleaner()
event_display = OP_EventDisplay("EventDisplays", "common") #to draw all/common objects
alphat = OP_CommonAlphaTCut(0.55)
DeadEcalCutData = OP_DeadECALCut(0.3,"./deadRegionList_GR10_P_V10.txt")
DeadEcalCutMC = OP_DeadECALCut(0.3,"./deadRegionList_START38_V12.txt")
# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

# AK5 Calo

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,JetTrigger)
cutTreeData.TAttach(JetTrigger,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,oddJet)
cutTreeData.TAttach(oddJet,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,secondJetET)

##########DiJet Studies
cutTreeData.TAttach(secondJetET,htCut250)
cutTreeData.TAttach(htCut250,dalitz_plots_Inclusive)
cutTreeData.TAttach(htCut250,DiJet3)
cutTreeData.TAttach(htCut250,alphat)
cutTreeData.TAttach(alphat,event_display)
cutTreeData.TAttach(DiJet3,HadStandardAll)
cutTreeData.TAttach(htCut250,NJet3)
cutTreeData.TAttach(NJet3,nHadStandardAll)
cutTreeData.TAttach(htCut250,LessThan300)
cutTreeData.TAttach(LessThan300,dalitz_plots_250_300)
cutTreeData.TAttach(LessThan300,DiJet0)
cutTreeData.TAttach(LessThan300,NJet0)
cutTreeData.TAttach(DiJet0,HadStandard250_300)
cutTreeData.TAttach(NJet0,nHadStandard250_300)

cutTreeData.TAttach(secondJetET,htCut300)
cutTreeData.TAttach(htCut300,LessThan350)
cutTreeData.TAttach(LessThan350,dalitz_plots_300_350)
cutTreeData.TAttach(LessThan350,DiJet1)
cutTreeData.TAttach(LessThan350,NJet1)
cutTreeData.TAttach(DiJet1,HadStandard300_350)
cutTreeData.TAttach(NJet1,nHadStandard300_350)

cutTreeData.TAttach(secondJetET,htCut350)
cutTreeData.TAttach(htCut350,dalitz_plots_350)
cutTreeData.TAttach(htCut350,DiJet2)
cutTreeData.TAttach(htCut350,NJet2)
cutTreeData.TAttach(DiJet2,alphaT0)
cutTreeData.TAttach(NJet2,alphaT1)
cutTreeData.TAttach(DiJet2,HadStandard350)
cutTreeData.TAttach(NJet2,nHadStandard350)

cutTreeData.TAttach(htCut350,DeadEcalCutData)
cutTreeData.TAttach(DeadEcalCutData,DiJet4)
cutTreeData.TAttach(DiJet4,HadStandard350_after_DeadEcal)
cutTreeData.TAttach(DeadEcalCutData,NJet4)
cutTreeData.TAttach(NJet4,nHadStandard350_after_DeadEcal)


#Second MC!

cutTreeMC = Tree("MC")
cutTreeMC.Attach(LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)
cutTreeMC.TAttach(numComPhotons,oddJet)
cutTreeMC.TAttach(oddJet,oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,secondJetET)

##########DiJet Studies
cutTreeMC.TAttach(secondJetET,htCut250)
cutTreeMC.TAttach(htCut250,dalitz_plots_Inclusive)
cutTreeMC.TAttach(htCut250,DiJet3)
cutTreeMC.TAttach(DiJet3,HadStandardAll)
cutTreeMC.TAttach(htCut250,NJet3)
cutTreeMC.TAttach(NJet3,nHadStandardAll)
cutTreeMC.TAttach(htCut250,LessThan300)
cutTreeMC.TAttach(LessThan300,dalitz_plots_250_300)
cutTreeMC.TAttach(LessThan300,DiJet0)
cutTreeMC.TAttach(LessThan300,NJet0)
cutTreeMC.TAttach(DiJet0,HadStandard250_300)
cutTreeMC.TAttach(NJet0,nHadStandard250_300)
cutTreeMC.TAttach(secondJetET,htCut300)
cutTreeMC.TAttach(htCut300,LessThan350)
cutTreeMC.TAttach(LessThan350,dalitz_plots_300_350)
cutTreeMC.TAttach(LessThan350,DiJet1)
cutTreeMC.TAttach(LessThan350,NJet1)
cutTreeMC.TAttach(DiJet1,HadStandard300_350)
cutTreeMC.TAttach(NJet1,nHadStandard300_350)
cutTreeMC.TAttach(secondJetET,htCut350)
cutTreeMC.TAttach(htCut350,dalitz_plots_350)
cutTreeMC.TAttach(htCut350,DiJet2)
cutTreeMC.TAttach(htCut350,NJet2)
cutTreeMC.TAttach(DiJet2,alphaT0)
cutTreeMC.TAttach(NJet2,alphaT1)
cutTreeMC.TAttach(DiJet2,HadStandard350)
cutTreeMC.TAttach(NJet2,nHadStandard350)
cutTreeMC.TAttach(htCut350,DeadEcalCutMC)
cutTreeMC.TAttach(DeadEcalCutMC,DiJet4)
cutTreeMC.TAttach(DiJet4,HadStandard350_after_DeadEcal)
cutTreeMC.TAttach(DeadEcalCutMC,NJet4)
cutTreeMC.TAttach(NJet4,nHadStandard350_after_DeadEcal)


