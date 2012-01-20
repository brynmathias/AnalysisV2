#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libPhotons import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from icf.utils import json_to_pset
from copy import deepcopy
from PhotonId_cff import *

# -----------------------------------------------------------------------------
# Samples

from skimmedsamples_cff import *
#from data.Run2011.PhotonHad_uptoRun163817 import PhotonHad_uptoRun163817
#from data.Run2011.PhotonHad_Run2011A_uptoRun171106 import PhotonHad_Run2011A_uptoRun171106
from montecarlo.Spring11.QCD_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL import QCD_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL
from montecarlo.Spring11.QCD_TuneD6T_7TeV_madgraph_Spring11_PU_START311_ALL import QCD_TuneD6T_7TeV_madgraph_Spring11_PU_START311_ALL
from montecarlo.Spring11.G_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL import G_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL
from montecarlo.Spring11.GJets_TuneD6T_7TeV_madgraph_Spring11_PU_START311_ALL import GJets_TuneD6T_7TeV_madgraph_Spring11_PU_START311_ALL
from montecarlo.GGMSignalScan import GGMSignalScan
OneFile = PSet(
  Name="OneFile",
  Format=("ICF",3),
  File=[
	"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/rnandi/ICF/automated/2011_08_02_17_39_36/SusyCAF_Tree_272_1_lFZ.root" ,
  ],
  Weight=1.
)

# -----------------------------------------------------------------------------
# Configuration

config = deepcopy(defaultConfig)
config.Ntuple.Jets.Prefix="ak5Jet"
#config.Ntuple.Jets.Prefix="ak5JetPF"
#config.XCleaning.Verbose=False
#config.XCleaning.PhotonJet=True
#config.XCleaning.ResolveConflicts=True
#config.XCleaning.Jets.PtCut=40.
#config.XCleaning.Jets.EtaCut=3.
#config.XCleaning.Photons.EtCut=40.
#config.XCleaning.Photons.IDReq=2
config.Common.ApplyXCleaning=False
config.Common.Jets.PtCut=40.
config.Common.Jets.EtaCut=2.5
config.Common.Photons.EtCut=80.
config.Common.Photons.IDReq=2

# -----------------------------------------------------------------------------
# User Variables

SelectedJetCuts = PSet(
  Et = 80.,
  DeltaR = 0.4 
)
SelectedPhotonCuts = PSet(
  Et = 80.,
  EtaEBMax = 1.4442,
  EtaEEMin = 1.56,
  EtaEEMax = 2.5,
  IDReq = 3
)
selected_jets = SelectedJets(SelectedJetCuts.ps())
selected_photons = SelectedPhotons(SelectedPhotonCuts.ps())

# -----------------------------------------------------------------------------
# Cut/Filter Operations

Trigger_PSet = PSet(
  Triggers = [ 
    "HLT_Photon70_CaloIdL_HT300_v1",
    "HLT_Photon70_CaloIdL_HT300_v2",
    "HLT_Photon70_CaloIdL_HT300_v3",
    "HLT_Photon70_CaloIdL_HT350_v3",
    "HLT_Photon70_CaloIdL_HT350_v4",
    "HLT_Photon70_CaloIdL_HT350_v5",
    "HLT_Photon70_CaloIdL_HT350_v6",
    "HLT_Photon70_CaloIdL_HT350_v7"
  ],
  Verbose = True,
  UsePreScaledTriggers = False
)
trigger = OP_MultiTrigger( Trigger_PSet.ps() )
nComPhotons = OP_NumComPhotons(">=",1)
nSelectedJets = OP_NumSelectedJets(">=",2)
nSelectedPhotons = OP_NumSelectedPhotons(">=",1)
htCut = RECO_CommonHTCut(400.)
met = OP_PFMETCut(100.)
categorize = OP_Categorize(0)
selected = OP_Category(4)
control = OP_Category(3)
sideband_selected = OP_Category(2)
sideband_control = OP_Category(1)

# -----------------------------------------------------------------------------
# Plot Operations

StandardPlots_HT_sele = PSet(
    DirName="StandardPlots_HT_sele",
    VariableName="HT",
    MinValue=400.,
    nBins=2, 
    BinWidth=100.,
)
StandardPlots_HT_cont = PSet(
    DirName="StandardPlots_HT_cont",
    VariableName="HT",
    MinValue=400.,
    nBins=2, 
    BinWidth=100.,
)
StandardPlots_HT_sb_sele = PSet(
    DirName="StandardPlots_HT_sb_sele",
    VariableName="HT",
    MinValue=400.,
    nBins=2, 
    BinWidth=100.,
)
StandardPlots_HT_sb_cont = PSet(
    DirName="StandardPlots_HT_sb_cont",
    VariableName="HT",
    MinValue=400.,
    nBins=2, 
    BinWidth=100.,
)

plots_standard_HT_sele = OP_StandardPlots(StandardPlots_HT_sele.ps())
plots_standard_HT_cont = OP_StandardPlots(StandardPlots_HT_cont.ps())
plots_standard_HT_sb_sele = OP_StandardPlots(StandardPlots_HT_sb_sele.ps())
plots_standard_HT_sb_cont = OP_StandardPlots(StandardPlots_HT_sb_cont.ps())

# -----------------------------------------------------------------------------
# Useful General Operations

skim_pset=PSet(
    SkimName = "skim",
    DropBranches = False,
    Branches = [
        " keep * "
    ]
)
skim = SkimOp(skim_pset.ps())
dump = OP_Dump()
event_display = OP_EventDisplay("Event Displays", "all")
plots_genpthat = OP_GenPtHatPlots("GenPtHatPlots")
NoiseFilter = OP_HadronicHBHEnoiseFilter()
Selection = OP_GoodEventSelection()
SpikeFilter = OP_EcalSpikeCleaner()
#json = JSONFilter("6MayJSON", json_to_pset("Golden_6May_uptoRun163757.json"))
json_output = JSONOutput("filtered")
pthat = OP_GenPtHatPlots("pthat")
signal_filter = OP_SignalFilter(720,1040)
vertex_reweight = VertexReweighting(
  PSet(VertexWeights = [0.5, 1.0, 2.0, 4.0, 8.0]).ps()
)
PhotonIdFilter = Photon_IDFilter( ra3tight.ps() )
#PhotonIdFilter = Photon_IDFilter( egm10006loose.ps() )
#PhotonIdFilter = Photon_IDFilter( egm10006tight.ps() )


# -----------------------------------------------------------------------------
# Cut flow

# SKIM
s=Tree("Main")
s.Attach(NoiseFilter)
s.TAttach(NoiseFilter,Selection)
s.TAttach(Selection,SpikeFilter)
s.TAttach(SpikeFilter,trigger)
s.TAttach(trigger,htCut)
#s.TAttach(SpikeFilter,htCut) # MC - do not apply trigger
s.TAttach(htCut,nComPhotons)
s.TAttach(nComPhotons,skim)

# ANALYSIS
t=Tree("Main")
t.Attach(nSelectedJets)
t.TAttach(nSelectedJets,categorize)
t.TAttach(categorize,selected)
t.TAttach(selected,plots_standard_HT_sele)
t.TAttach(categorize,control)
t.TAttach(control,plots_standard_HT_cont)
t.TAttach(categorize,sideband_selected)
t.TAttach(sideband_selected,plots_standard_HT_sb_sele)
t.TAttach(categorize,sideband_control)
t.TAttach(sideband_control,plots_standard_HT_sb_cont)
#t.TAttach(nSelectedPhotons,plots_standard_HT_sele)
#t.FAttach(nSelectedPhotons,plots_standard_HT_anti)

# -----------------------------------------------------------------------------
# Definition of analyses

# SKIM
a=Analysis("Skim")
a.AddPhotonFilter("PreCC",PhotonIdFilter)
a+=s

# PLOTS
b=Analysis("Calo_ra3tight")
#b.AddWeightFilter("Weight", vertex_reweight)
b.AddPhotonFilter("PreCC",PhotonIdFilter)
b.AddUserVar("SelectedPhotons",selected_photons)
b.AddUserVar("SelectedJets",selected_jets)
b+=t

# -----------------------------------------------------------------------------
# Run analyses

#a.Run("/vols/cms03/rnandi",config,[PhotonHad_Run2011A_uptoRun171106])

#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,[PhotonHad_uptoRun163817])
b.Run("/home/hep/rjn04/SUSY2/photons/results",config,[PhotonHad_Run2011A_uptoRun171106])
#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,[OneFile])
#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,QCD_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL)
#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,QCD_TuneD6T_7TeV_madgraph_Spring11_PU_START311_ALL)
#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,G_TuneZ2_7TeV_pythia6_Spring11_PU_START311_ALL)
#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,GJets_TuneD6T_7TeV_madgraph_Spring11_PU_START311_ALL)
#b.Run("/home/hep/rjn04/SUSY2/photons/results",config,[GGMSignalScan])
