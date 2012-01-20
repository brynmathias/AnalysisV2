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

# -----------------------------------------------------------------------------
# Common cut definitions

from icf.JetCorrections import *
corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
JetCorrections = JESCorrections( corPset.ps() ,True )

NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()

oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()

numComElectrons = OP_NumComElectrons("<=",0)
numComMuons = OP_NumComMuons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

# -----------------------------------------------------------------------------
# Common cut flows

def cutFlowData( cutTreeData, optionVeto ) :
    cutTreeData.Attach(NoiseFilt)
    cutTreeData.TAttach(NoiseFilt,selection)
    if ( optionVeto == "NoMuonVeto" ) :
        print "No muon veto applied!"
        cutTreeData.TAttach(selection,numComPhotons)
        cutTreeData.TAttach(numComPhotons,oddPhoton)
        cutTreeData.TAttach(oddPhoton,numComElectrons)
        cutTreeData.TAttach(numComElectrons,oddElectron)
    elif ( optionVeto == "NoElectronVeto" ) :
        print "No electron veto applied!"
        cutTreeData.TAttach(selection,numComPhotons)
        cutTreeData.TAttach(numComPhotons,oddPhoton)
        cutTreeData.TAttach(oddPhoton,numComMuons)
        cutTreeData.TAttach(numComMuons,oddMuon)
    elif ( optionVeto == "NoPhotonVeto" ) :
        print "No photon veto applied!"
        cutTreeData.TAttach(selection,numComElectrons)
        cutTreeData.TAttach(numComElectrons,oddElectron)
        cutTreeData.TAttach(oddElectron,numComMuons)
        cutTreeData.TAttach(numComMuons,oddMuon)
    elif ( optionVeto == "NoElectronPhotonVetoes" ) :
        print "No electron/photon vetoes applied!"
        cutTreeData.TAttach(selection,numComMuons)
        cutTreeData.TAttach(numComMuons,oddMuon)
    elif ( optionVeto == "NoVetoes" ) :
        print "No vetoes at all applied!"
    else :
        print "ALL vetoes applied, as normal!"
        cutTreeData.TAttach(selection,numComPhotons)
        cutTreeData.TAttach(numComPhotons,oddPhoton)
        cutTreeData.TAttach(oddPhoton,numComElectrons)
        cutTreeData.TAttach(numComElectrons,oddElectron)
        cutTreeData.TAttach(oddElectron,numComMuons)
        cutTreeData.TAttach(numComMuons,oddMuon)
            
def cutFlowMC( cutTreeMC, optionVeto ) :
    cutTreeMC.Attach(selection)
    if ( optionVeto == "NoMuonVeto" ) :
        print "No muon veto applied!"
        cutTreeMC.TAttach(selection,numComPhotons)
        cutTreeMC.TAttach(numComPhotons,oddPhoton)
        cutTreeMC.TAttach(oddPhoton,numComElectrons)
        cutTreeMC.TAttach(numComElectrons,oddElectron)
    elif ( optionVeto == "NoElectronVeto" ) :
        print "No electron veto applied!"
        cutTreeMC.TAttach(selection,numComPhotons)
        cutTreeMC.TAttach(numComPhotons,oddPhoton)
        cutTreeMC.TAttach(oddPhoton,numComMuons)
        cutTreeMC.TAttach(numComMuons,oddMuon)
    elif ( optionVeto == "NoPhotonVeto" ) :
        print "No photon veto applied!"
        cutTreeMC.TAttach(selection,numComElectrons)
        cutTreeMC.TAttach(numComElectrons,oddElectron)
        cutTreeMC.TAttach(oddElectron,numComMuons)
        cutTreeMC.TAttach(numComMuons,oddMuon)
    elif ( optionVeto == "NoElectronPhotonVetoes" ) :
        print "No electron/photon vetoes applied!"
        cutTreeMC.TAttach(selection,numComMuons)
        cutTreeMC.TAttach(numComMuons,oddMuon)
    elif ( optionVeto == "NoVetoes" ) :
        print "No vetoes at all applied!"
    else :
        print "ALL vetoes applied, as normal!"
        cutTreeMC.TAttach(selection,numComPhotons)
        cutTreeMC.TAttach(numComPhotons,oddPhoton)
        cutTreeMC.TAttach(oddPhoton,numComElectrons)
        cutTreeMC.TAttach(numComElectrons,oddElectron)
        cutTreeMC.TAttach(oddElectron,numComMuons)
        cutTreeMC.TAttach(numComMuons,oddMuon)

