#!/usr/bin/env python
"""
Golden_cfg.py

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

# -----------------------------------------------------------------------------


# Common configurations ( IC5Calo, AK5Calo, AK5JPT, AK5PF)

conf_ic5_calo = deepcopy(defaultConfig)
conf_ic5_calo.Ntuple = deepcopy(ic5_calo)
conf_ic5_calo.XCleaning = deepcopy(default_cc)
conf_ic5_calo.Common = deepcopy(default_common)

conf_ak5_calo = deepcopy(defaultConfig)
conf_ak5_calo.Ntuple = deepcopy(ak5_calo)
conf_ak5_calo.XCleaning = deepcopy(default_cc)
conf_ak5_calo.Common.print_out()
conf_ak5_calo.Common = deepcopy(default_common)

conf_ak7_calo = deepcopy(defaultConfig)
conf_ak7_calo.Ntuple = deepcopy(ak7_calo)
conf_ak7_calo.XCleaning = deepcopy(default_cc)
conf_ak7_calo.Common = deepcopy(default_common)

conf_ak5_jpt = deepcopy(defaultConfig)
conf_ak5_jpt.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jpt.XCleaning = deepcopy(default_cc)
conf_ak5_jpt.Common = deepcopy(default_common)

conf_ak5_pf = deepcopy(defaultConfig)
conf_ak5_pf.Ntuple = deepcopy(ak5_pf)
conf_ak5_pf.XCleaning = deepcopy(default_cc)
conf_ak5_pf.Common = deepcopy(default_common)


corPset =  CorrectionPset()
JetCorrections = JESCorrections( corPset.ps() )


# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!
JetTrigger = OP_TriggerCut("HLT_HT100U")
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()




#Standard Event Selection
secondJetET = OP_SecondJetEtCut(100.)
LeadingJetCut = OP_FirstJetPtCut(100.)
LeadingJetEta = OP_FirstJetEta(2.5)

htCut = RECO_CommonHTCut(350.)

oddJet = OP_OddJet()
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()

badMuonInJet = OP_BadMuonInJet()

numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

MHTPFMETDiff = OP_MHTPFMETDiffOvMeff(0.15)
MHTPFMETDiff_2 = OP_MHTPFMETDiffOvMeff(0.15)

deadECAL = OP_DeadECALCut(0.3,"./MC36_deadECALList.txt")#choose input file according to need CMSSW version MC or data

DiJet0 = OP_NumComJets("==",2)
DiJet1 = OP_NumComJets("==",2)
DiJet2 = OP_NumComJets("==",2)
DiJet3 = OP_NumComJets("==",2)
NJet0 = OP_NumComJets(">=",3)
NJet1 = OP_NumComJets(">=",3)
NJet2 = OP_NumComJets(">=",3)
NJet3 = OP_NumComJets(">=",3)

LessThan250 = RECO_CommonHTLessThanCut(250.)
LessThan350 = RECO_CommonHTLessThanCut(350.)
LessThan400 = RECO_CommonHTLessThanCut(400.)

htCut150 = RECO_CommonHTCut(150.)
htCut250 = RECO_CommonHTCut(250.)
htCut350 = RECO_CommonHTCut(350.)
htCut400 = RECO_CommonHTCut(400.)

alphaT0 = OP_CommonAlphaTCut(0.55)
alphaT1 = OP_CommonAlphaTCut(0.55)

alphaT0_150 = OP_CommonAlphaTCut(0.55)
alphaT1_150 = OP_CommonAlphaTCut(0.55)
alphaT0_250 = OP_CommonAlphaTCut(0.55)
alphaT1_250 = OP_CommonAlphaTCut(0.55)

