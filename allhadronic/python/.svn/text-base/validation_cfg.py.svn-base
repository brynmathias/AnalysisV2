#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from liballhadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy

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

default_ntuple.Photons=PSet(
Prefix="photon",
Suffix="Pat",
)

default_ntuple.Jets=PSet(
Prefix="ic5Jet",
Suffix="Pat",
Uncorrected=False,
)

default_ntuple.SecJets=PSet(
    Prefix="",
    Suffix="",
    Uncorrected=False,
    )

default_ntuple.TerJets=PSet(
    Prefix="",
    Suffix="",
    Uncorrected=False,
    )

ak5_calo = deepcopy(default_ntuple)
ak5_calo.Jets.Prefix="ak5Jet"

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

# Common configurations

conf_ak5_calo = deepcopy(defaultConfig)
conf_ak5_calo.Ntuple = deepcopy(ak5_calo)
conf_ak5_calo.XCleaning = deepcopy(default_cc)
conf_ak5_calo.Common.print_out()
conf_ak5_calo.Common = deepcopy(default_common)

# -----------------------------------------------------------------------------
# Common cut definitions

from ra1objectid.vbtfElectronId_cff import *
ele_filter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )

from ra1objectid.ra3PhotonId_cff import *
phot_filter = Photon_IDFilter( ra3photonidps.ps() )

from icf.JetCorrections import *
corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
JetCorrections = JESCorrections( corPset.ps(), True )

NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()

oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()

numComElectrons = OP_NumComElectrons("<=",0)
numComMuons = OP_NumComMuons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

# -----------------------------------------------------------------------------
# Test module

from allhadronic.algorithms_cfi import *

ps = PSet(
    Verbose = False,
    AlphaT = [0.55],
    DirName = "QcdBkgdEst",
    nMin = 2,
    nMax = 10,
    Algorithms = AlgorithmsPSet,
    )
test = Validation(ps.ps())

# -----------------------------------------------------------------------------
# Cut flow

cut_flow = Tree("CutFlow")
cut_flow.Attach(selection)
if ( True ) : # Data only
    cut_flow.TAttach(selection,NoiseFilt)
    cut_flow.TAttach(NoiseFilt,numComPhotons)
else :
    cut_flow.TAttach(selection,numComPhotons)
cut_flow.TAttach(numComPhotons,oddPhoton)
cut_flow.TAttach(oddPhoton,numComElectrons)
cut_flow.TAttach(numComElectrons,oddElectron)
cut_flow.TAttach(oddElectron,numComMuons)
cut_flow.TAttach(numComMuons,oddMuon)
cut_flow.TAttach(oddMuon,test)

# -----------------------------------------------------------------------------
# Dataset

lm1=PSet(
    Name="LM1",
    Events=100000,
    Format=("ICF",2),
    File= [
    "dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/LM1.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
    ],
    CrossSection=4.888,
    FirstEntry = 50,
    LastEntry = 100,
    )

data=PSet(
    Name="Data",
    Format=("ICF",3),
    File= [
    "dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/georgia//ICF/automated/2011_04_09_18_07_10///SusyCAF_Tree_100_1_OjA.root" ,
    #"/vols/cms02/bainbrid/qcd/data/HT_Run2011A_PromptReco_v1.root",
    ],
    Weight=1.,
    #FirstEntry = 1,
    #LastEntry = 10,
    )

from montecarlo.LMx import LM0
from montecarlo.QCD_Pythia6_384patch3_V14_00_02_ALL import *
from data.Jet_35pb_WithTP_json051110 import Jet_35pb_WithTP_json051110

# -----------------------------------------------------------------------------
# Analysis

anal=Analysis("Validation")
anal.AddPhotonFilter("PreCC",phot_filter)
anal.AddElectronFilter("PreCC",ele_filter)
#anal.AddJetFilter("PreCC",JetCorrections)
anal+=cut_flow

anal.Run(".",conf_ak5_calo,[data])
#anal.Run(".",conf_ak5_calo,[lm1])
#anal.Run(".",conf_ak5_calo,[LM0])
#anal.Run(".",conf_ak5_calo,[Jet_35pb_WithTP_json051110])
#anal.Run(".",conf_ak5_calo,QCD_Pythia6_384patch3_V14_00_02_ALL)
