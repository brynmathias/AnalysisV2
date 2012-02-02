#!/usr/bin/env python
"""
METPas_cfg.py

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
# from montecarlo.LMx import *
# from bryn_samples import *
# from montecarlo.WJets_Madgraph import *



# -----------------------------------------------------------------------------
# Samples
#from local_samples import *
# from met_samples import *
# from JetMetTau139375_Uncleaned import *

f=PSet(
Name="Testing",
File=["../SusyCAF_Tree_9_1.root"],
Format=("ICF",2),
Weight = 1.0
)


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
default_cc.MuonJet=False
default_cc.ElectronJet=False
default_cc.PhotonJet=False
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=6.0
default_cc.Muons.CombIsoCut=0.2
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=6.0
default_cc.Electrons.CombIsoCut=0.2
default_cc.Photons.EtCut=10.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=9.0
default_cc.Photons.AllIsoCut=0.2
default_cc.Photons.IDReq=2

# -----------------------------------------------------------------------------
# Definition of common objects

default_common = deepcopy(defaultConfig.Common)

default_common.ApplyXCleaning=False
default_common.Jets.PtCut=20.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=False
default_common.Jets.TightID=False
default_common.Jets.Uncorrected=False
default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=6.
default_common.Electrons.CombIsoCut=0.2
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=6.
default_common.Muons.CombIsoCut=0.2
default_common.Photons.EtCut=25.0
default_common.Photons.EtaCut=2.5
default_common.Photons.TrkIsoCut=9.
default_common.Photons.EcalIsoCut=99999.
default_common.Photons.HcalIsoCut=99999.
default_common.Photons.AllIsoCut=0.2
default_common.Photons.IDReq=3


# -----------------------------------------------------------------------------
# Common cut definitions

Dijet = OP_NumComJets("==",2)
Njet = OP_NumComJets(">=",3)
selection = OP_GoodEventSelection()

unCorLeadJetCut = OP_UnCorLeadJetCut(40.)
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)
oddJet = OP_OddJet()
JetTrigger = OP_TriggerCut("HLT_Jet15U")
NoiseFilt= OP_HadronicHBHEnoiseFilter()


oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
badMuonInJet = OP_BadMuonInJet()
secondJetET = OP_SecondJetEtCut(100.)
htCut = RECO_CommonHTCut(350.)
missedHT = OP_MissedHTCut(1.25)
# -----------------------------------------------------------------------------
# Common plots

plots_comjet = OP_ComJetPlots("CommonJetPlots",10)
plots_objkin = OP_ObjKinPlots("ObjectKinePlots",100,10)
plots_common = OP_CommonPlots("CommonPlots")
plots_kinsuite = OP_KinSuiteComPlot("KinSuitePlots",10,2)
nplots_comjet = OP_ComJetPlots("nCommonJetPlots",10)
nplots_kinsuite = OP_KinSuiteComPlot("nKinSuitePlots",10,2)
HTCut = RECO_CommonHTCut(200.)


#Plots with Basic Slection
# PlotsCommonBasic



pset1 = PSet(
DirName      = "MT2",
MinObjects   = 2,
MaxObjects   = 10,
Mt2DiJet     = False,
Mt2Multi_Jet = False,
Mt2Compare   = False,
MHT          = False,
DalitzMT2    = False,
Development  = False,
TriggerStudies = True,
)


TriggerPlots = BrynPlottingOps( pset1.ps() )

# -----------------------------------------------------------------------------
# Cut flow
#Cut flow for Data

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection, HTCut)
cutTreeData.TAttach(HTCut,TriggerPlots)



def addCutMCFlow(a) :
  a+=cutTreeMC


def addCutDataFlow(a) :
  a+=cutTreeData


  # -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

# IC5 Calo

conf_ic5_calo = deepcopy(defaultConfig)
conf_ic5_calo.Ntuple = deepcopy(ic5_calo)
conf_ic5_calo.XCleaning = deepcopy(default_cc)
conf_ic5_calo.Common = deepcopy(default_common)
# conf_ic5_calo.Common.print_out()
anal_ic5_calo=Analysis("IC5Calo")
addCutDataFlow(anal_ic5_calo)

# AK5 Calo

# conf_ak5_caloMC = deepcopy(defaultCon# fig)
# conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
# conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
# conf_ak5_caloMC.Common = deepcopy(default_common)
# # conf_ak5_calo.Common.print_out()
# anal_ak5_caloMC=Analysis("AK5Calo")
# addCutMCFlow(anal_ak5_caloMC)
#
# # AK5 Calo
#
# conf_ak5_caloData = deepcopy(defaultConfig)
# conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
# conf_ak5_caloData.XCleaning = deepcopy(default_cc)
# conf_ak5_caloData.Common = deepcopy(default_common)
# # conf_ak5_calo.Common.print_out()
# anal_ak5_caloData=Analysis("AK5Calo")
# addCutDataFlow(anal_ak5_caloData)
#


# # AK5 JPT
#
# conf_ak5_jpt = deepcopy(defaultConfig)
# conf_ak5_jpt.Ntuple = deepcopy(ak5_jpt)
# conf_ak5_jpt.XCleaning = deepcopy(default_cc)
# conf_ak5

# -----------------------------------------------------------------------------
# Run analyses
#IMPERIAL COLLEGE
anal_ic5_calo.Run("../results/",conf_ic5_calo,[f])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM0])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM1])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM2])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM3])
#anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM4])
#anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM5])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[wjets_madgraph])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[zjets_madgraph])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[ttbarTauola])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[Zinvisible_jets])

# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[f])