#!/usr/bin/env python
"""
METPas_cfg.py

Created by Bryn Mathias on 2010-05-07.
Copyright (c) 2010 Imperial College. All rights reserved.
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
#from local_samples import *
from met_samples import *
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
default_cc.Jets.EtCut=10.0
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
default_common.Jets.EtCut=20.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False
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

twoJet = OP_NumComJets("==",2)
greaterThreeJet = OP_NumComJets(">=",3)
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(50.)
Jet15Utrigger = OP_TriggerCut("HLT_Jet15U")

# -----------------------------------------------------------------------------
# Common plots

plots_comjet = OP_ComJetPlots("CommonJetPlots",10)
plots_objkin = OP_ObjKinPlots("ObjectKinePlots",100,10)
plots_common = OP_CommonPlots("CommonPlots")
plots_kinsuite = OP_KinSuiteComPlot("KinSuitePlots",10,2)

pset1 = PSet(
DirName      = "MET Plots N=2",
MinObjects   = 2,
MaxObjects   = 10,
Mt2DiJet     = False,
Mt2Multi_Jet = False,
Mt2Compare   = False,
MHT          = False,
DalitzMT2    = False,
Development  = True,
)

pset2 = PSet(
DirName      = "MET Plots N>2",
MinObjects   = 2,
MaxObjects   = 10,
Mt2DiJet     = False,
Mt2Multi_Jet = False,
Mt2Compare   = False,
MHT          = False,
DalitzMT2    = False,
Development  = True,
)
PlotsMetG3 = BrynPlottingOps( pset2.ps() )
PlotsMetEq2 = BrynPlottingOps( pset1.ps() )

hadset = PSet(
DirName    = "Hadronic",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = False,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
)
plots_hadronic = HadronicPlottingOps( hadset.ps() )
# -----------------------------------------------------------------------------
# Cut flow

def addCutFlow(a) :
  a+=Jet15Utrigger
  a+=secondJetET
  a+=oddJet
  a+=twoJet
  a+=PlotsMetEq2
  a+=greaterThreeJet
  a+=PlotsMetG3
  a+=plots_comjet
  a+=plots_kinsuite
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
addCutFlow(anal_ic5_calo)

# AK5 Calo

conf_ak5_calo = deepcopy(defaultConfig)
conf_ak5_calo.Ntuple = deepcopy(ak5_calo)
conf_ak5_calo.XCleaning = deepcopy(default_cc)
conf_ak5_calo.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_calo=Analysis("AK5Calo")
addCutFlow(anal_ak5_calo)

# AK5 JPT

conf_ak5_jpt = deepcopy(defaultConfig)
conf_ak5_jpt.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jpt.XCleaning = deepcopy(default_cc)
conf_ak5_jpt.Common = deepcopy(default_common)
# conf_ak5_jpt.Common.print_out()
anal_ak5_jpt=Analysis("AK5JPT")
addCutFlow(anal_ak5_jpt)

# AK5 PF

conf_ak5_pf = deepcopy(defaultConfig)
conf_ak5_pf.Ntuple = deepcopy(ak5_pf)
conf_ak5_pf.XCleaning = deepcopy(default_cc)
conf_ak5_pf.Common = deepcopy(default_common)
# conf_ak5_pf.Common.print_out()
anal_ak5_pf=Analysis("AK5PF")
addCutFlow(anal_ak5_pf)

# -----------------------------------------------------------------------------
# Run analyses
# Comment out one block depending on where you are running!
#LX PLUS
anal_ak5_pf.Run("../results/",conf_ak5_pf,[SusyCafDataSkim])
anal_ak5_calo.Run("../results/",conf_ak5_calo,[SusyCafDataSkim])
anal_ak5_jpt.Run("../results",conf_ak5_jpt,[SusyCafDataSkim])
anal_ak5_pf.Run("../results/",conf_ak5_pf,[SusyCafMC])
anal_ak5_calo.Run("../results/",conf_ak5_calo,[SusyCafMC])
anal_ak5_jpt.Run("../results",conf_ak5_jpt,[SusyCafMC])
#IMPERIAL COLLEGE
anal_ak5_pf.Run("../results/",conf_ak5_pf,[ICMCSkim])
anal_ak5_calo.Run("../results/",conf_ak5_calo,[ICMCSkim])
anal_ak5_jpt.Run("../results",conf_ak5_jpt,[ICMCSkim])
anal_ak5_pf.Run("../results/",conf_ak5_pf,[ICDataSkim])
anal_ak5_calo.Run("../results/",conf_ak5_calo,[ICDataSkim])
anal_ak5_jpt.Run("../results",conf_ak5_jpt,[ICDataSkim])
