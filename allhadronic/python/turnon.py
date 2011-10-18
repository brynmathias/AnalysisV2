#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from liballhadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from icf.utils import json_to_pset
from allhadronic.golden_cff import *
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
Prefix="ak5Jet",
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

conf = deepcopy(defaultConfig)
conf.Ntuple = deepcopy(ak5_calo)
conf.XCleaning = deepcopy(default_cc)
conf.Common.print_out()
conf.Common = deepcopy(default_common)

# -----------------------------------------------------------------------------
# Common cut definitions

from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.ra3PhotonId_cff import *

vbtf_muon = Muon_IDFilter( vbtfmuonidps.ps() )
vbtf_electron = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3_photon = Photon_IDFilter( ra3photonidps.ps() )

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
AlgorithmsPSet.Nbins = 8
AlgorithmsPSet.Low = 200.
AlgorithmsPSet.High = 600.
AlgorithmsPSet.MinJetPt1 = 100.*550./350.
AlgorithmsPSet.MinJetPt2 = 100.*550./350.
AlgorithmsPSet.MinJetPt3 = 50.*550./350.
#AlgorithmsPSet.MinJetPt1 = 40.
#AlgorithmsPSet.MinJetPt2 = 40.
#AlgorithmsPSet.MinJetPt3 = 40.
#AlgorithmsPSet.Scale = False

AlgorithmsPSet.Pt1Bins = [100.*200./350.,100.*250./350.,100.*300./350.,100.,100.,100.,100.,100.,]
AlgorithmsPSet.Pt2Bins = [100.*200./350.,100.*250./350.,100.*300./350.,100.,100.,100.,100.,100.,]
AlgorithmsPSet.Pt3Bins = [ 50.*200./350., 50.*250./350., 50.*300./350., 50., 50., 50., 50., 50.,]

ps = PSet(
    Verbose = False,
    DirName = "TurnOn",
    nMin = 2,
    nMax = 4,
    Algorithms = AlgorithmsPSet,
    Triggers = [
    "HLT_HT260_MHT60_v2","HLT_HT260_MHT60_v2","HLT_HT260_MHT60_v2","HLT_HT240_v2","HLT_HT260_v2",
    "HLT_HT250_MHT60_v2","HLT_HT250_MHT60_v2","HLT_HT250_MHT60_v2","HLT_HT250_v2",
    "HLT_HT250_MHT60_v3","HLT_HT250_MHT60_v3","HLT_HT250_MHT60_v3","HLT_HT250_v3",
    ],
    
    PreFilters = [
    "HLT_HT260_v2","HLT_HT260_v2","HLT_HT260_v2","HLT_HT160_v2","HLT_HT240_v2",
    "HLT_HT250_v2","HLT_HT250_v2","HLT_HT250_v2","HLT_HT200_v2",
    "HLT_HT250_v3","HLT_HT250_v3","HLT_HT250_v3","HLT_HT200_v3",
    ],

    Variables = [
    "MHT","MHToverHT","AlphaT","HT","HT",
    "MHT","MHToverHT","AlphaT","HT",
    "MHT","MHToverHT","AlphaT","HT",
    ],
    
    Bins = [
    1,1,1,1,1,
    1,1,1,1,
    1,1,1,1,
    ],
    )

test = TurnOn(ps.ps())

# -----------------------------------------------------------------------------
# Cut flow

pwd = commands.getoutput('echo $SUSY_WORKING_SW_DIR')
json = JSONFilter("JSON", json_to_pset(pwd+"/allhadronic/python/Cert_160404-163869_7TeV_PromptReco_Collisions11_JSON.txt"))

cut_flow = Tree("CutFlow")
cut_flow.Attach(json)
cut_flow.TAttach(json,selection)
cut_flow.TAttach(selection,NoiseFilt)
cut_flow.TAttach(NoiseFilt,numComPhotons)
cut_flow.TAttach(numComPhotons,oddPhoton)
cut_flow.TAttach(oddPhoton,numComElectrons)
cut_flow.TAttach(numComElectrons,oddElectron)
cut_flow.TAttach(oddElectron,numComMuons)
cut_flow.TAttach(numComMuons,oddMuon)
cut_flow.TAttach(oddMuon,test)

# -----------------------------------------------------------------------------
# Dataset


data=PSet(
    Name="data",
    Format=("ICF",3),
    File= [
    "dcap://gfe02.grid.hep.ph.ic.ac.uk//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/henning//ICF/automated/2011_04_13_17_17_19///SusyCAF_Tree_9_1_zCe.root" ,
    ],
    Weight=1.,
    #FirstEntry = 934,
    LastEntry = 10,
    )

tmp=PSet(
    Name="HT_Run2011A_PromptReco_v1",
    Format=("ICF",3),
    File= [
        #"dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/georgia//ICF/automated/2011_04_09_18_07_10///SusyCAF_Tree_100_1_OjA.root",
        "/Users/bainbrid/Desktop/work/data/HT_Run2011A_PromptReco_v1.root",
        ],
    Weight=1.,
    #LastEntry = 10,
    )

lm1=PSet(
    Name="lm1",
    Events=100000,
    Format=("ICF",2),
    File= [
    #"dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/LM1.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
    "/Users/bainbrid/Desktop/work/data/LM1.root",
    ],
    CrossSection=4.888,
    #FirstEntry = 1,
    #LastEntry = 10,
    )

from data.Run2011.HT_Run2011A_PromptReco_v1 import HT_Run2011A_PromptReco_v1
from data.Run2011.HT_Run2011_promptReco_DCS import HT_Run2011_promptReco_DCS

# -----------------------------------------------------------------------------
# Analysis

anal=Analysis("TurnOn")
anal.AddMuonFilter("PreCC",vbtf_muon)
anal.AddElectronFilter("PreCC",vbtf_electron)
anal.AddPhotonFilter("PreCC",ra3_photon)
anal+=cut_flow

#anal.Run(".",conf,[data])
#anal.Run(".",conf,[tmp])
#anal.Run(".",conf,[lm1])
#anal.Run(".",conf_ak5_calo,[HT_Run2011A_PromptReco_v1])
anal.Run(".",conf_ak5_calo,[HT_Run2011_promptReco_DCS])

