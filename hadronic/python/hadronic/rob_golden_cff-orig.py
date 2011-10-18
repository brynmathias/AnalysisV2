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
#ak5_pf.Electrons.Prefix="PF"
#ak5_pf.Muons.Prefix="PF"

ak7_calo = deepcopy(default_ntuple)
ak7_calo.Jets.Prefix="ak7Jet"

ak5_gen = deepcopy(default_ntuple)
ak5_gen.Jets.Prefix="ak5Jet"
ak5_gen.Jets.UseGenJets=True

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
default_common.Jets.PtCut=10.0
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
default_common.Photons.IDReq = 3
default_common.Photons.RequireLooseForOdd = True

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

conf_ak5_calo_msugra = deepcopy(conf_ak5_calo)
conf_ak5_calo_msugra.Ntuple.Weight = "mSuGra"

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
conf_ak5_pf.XCleaning.Muons.ModifyJetEnergy=False
conf_ak5_pf.Common = deepcopy(default_common)

conf_ak5_pf_msugra = deepcopy(conf_ak5_pf)
conf_ak5_pf_msugra.Ntuple.Weight = "mSuGra"

conf_ak5_gen = deepcopy(defaultConfig)
conf_ak5_gen.Ntuple = deepcopy(ak5_gen)
conf_ak5_gen.XCleaning = deepcopy(default_cc)
conf_ak5_gen.Common.print_out()
conf_ak5_gen.Common = deepcopy(default_common)

# -----------------------------------------------------------------------------
# Common cut definitions

from icf.JetCorrections import *
corPset =  CorrectionPset()
JetCorrections = JESCorrections( corPset.ps() )

JetTrigger = OP_TwoTriggerCut("HLT_HT100U","HLT_HT120U")
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()

secondJetET = OP_SecondJetEtCut(70.)
LeadingJetCut = OP_FirstJetPtCut(70.)
LeadingJetEta = OP_FirstJetEta(2.5)

oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()

numComLeptons = OP_NumComLeptons("<=",0)
numComElectrons = OP_NumComElectrons("<=",0)
numComMuons = OP_NumComMuons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)
numComJets = OP_NumComJets(">=",2)

htCut = RECO_CommonHTCut(250.)

# -----------------------------------------------------------------------------
# Common cut flows

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,numComPhotons)
cutTreeData.TAttach(numComPhotons,oddPhoton)
cutTreeData.TAttach(oddPhoton,numComElectrons)
cutTreeData.TAttach(numComElectrons,oddElectron)
cutTreeData.TAttach(oddElectron,numComMuons)
cutTreeData.TAttach(numComMuons,oddMuon)

#cutTreeData.TAttach(oddMuon,numComJets)
#cutTreeData.TAttach(numComJets,LeadingJetCut)
#cutTreeData.TAttach(LeadingJetCut,secondJetET)
#cutTreeData.TAttach(secondJetET,htCut)
            
cutTreeMC = Tree("MC")
cutTreeMC.Attach(selection)
cutTreeMC.TAttach(selection,numComPhotons)
cutTreeMC.TAttach(numComPhotons,oddPhoton)
cutTreeMC.TAttach(oddPhoton,numComElectrons)
cutTreeMC.TAttach(numComElectrons,oddElectron)
cutTreeMC.TAttach(oddElectron,numComMuons)
cutTreeMC.TAttach(numComMuons,oddMuon)

#cutTreeMC.TAttach(oddMuon,numComJets)
#cutTreeMC.TAttach(numComJets,LeadingJetCut)
#cutTreeMC.TAttach(LeadingJetCut,secondJetET)
#cutTreeMC.TAttach(secondJetET,htCut)

