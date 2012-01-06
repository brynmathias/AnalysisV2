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
  # put yout samples in here or import a file containing your data samples



ICSkim=PSet(
Name="ICSkim",
File="/vols/cms02/bm409/Bryn_skim.root",
Format=("ICF",2),
Weight=1.
)

MC=PSet(
Name="15JetUSkimMC",
File="/castor/cern.ch/user/h/henning//SusyCAF/automated/2010_05_18_18_10_10/Skims/CleanJet15U.root",
Format=("ICF",2),
Weight=1.
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
default_common.Jets.ApplyID=True #Id for jets is by default loose
default_common.Jets.TightID=False # Can turn on tight ID here.
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

numComJets = OP_NumComJets(">=",2)
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)
oddJet = OP_OddJet()
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
secondJetET = OP_SecondJetEtCut(50.)

unCorLeadJetCut = OP_UnCorLeadJetCut(40.)

# -----------------------------------------------------------------------------
# Common plots

plots_comjet = OP_ComJetPlots("CommonJetPlots",6)
plots_objkin = OP_ObjKinPlots("ObjectKinePlots",100,6)
plots_common = OP_CommonPlots("CommonPlots")
plots_kinsuite = OP_KinSuiteComPlot("KinSuitePlots",6,2)

pset1 = PSet(
DirName      = "MT2",
MinObjects   = 2,
MaxObjects   = 10,
Mt2DiJet     = False,#MT2 plots of Dijet system NOT USED HERE
Mt2Multi_Jet = False,#As above for multiJet
Mt2Compare   = False,#Compares the above methods
MHT          = True, #Plots MHT Variables
DalitzMT2    = False, # A testing/idea for putting MT2 in with Dalitz plots, also False
Development  = True, #Development area, here is where the JetMET PAS plots have been developed, Needs tidying, will be put in to a File of its own, for the moment everything you want will be in here
)

pset2 = PSet(
DirName      = "MT2after",
MinObjects   = 2,
MaxObjects   = 10,
Mt2DiJet     = False,#MT2 plots of Dijet system NOT USED HERE
Mt2Multi_Jet = False,#As above for multiJet
Mt2Compare   = False,#Compares the above methods
MHT          = True, #Plots MHT Variables
DalitzMT2    = False, # A testing/idea for putting MT2 in with Dalitz plots, also False
Development  = True, #Development area, here is where the JetMET PAS plots have been developed, Needs tidying, will be put in to a File of its own, for the moment everything you want will be in here
)

plots_mt2 = BrynPlottingOps( pset1.ps() )
plots_ANmt2 = BrynPlottingOps( pset2.ps() )


hadset = PSet(
DirName    = "Hadronic",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = False,
AlphaT     = True, #Robs alphaT plots.
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
)
plots_hadronic = HadronicPlottingOps( hadset.ps() )
# -----------------------------------------------------------------------------
# Cut flow

def addCutFlow(a) :

  a+=unCorLeadJetCut
  a+=numComJets
  a+=oddJet
  a+=plots_ANmt2
  # a+=secondJetET
  a+=plots_mt2
  a+=plots_hadronic
  a+=plots_comjet
  a+=plots_objkin
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
#Please set up a directory to write the files out in to
anal_ak5_calo.Run("../results/",conf_ak5_calo,[MC])
anal_ak5_pf.Run("../results/",conf_ak5_pf,[MC])
# anal_ak5_pf.Run("../results/PAS/NoVeto/et50/2jet",conf_ak5_pf,[MatchingMC])
anal_ak5_calo.Run("../results/",conf_ak5_calo,[MC])
# anal_ak5_calo.Run("../results/PAS/NoVeto/et50/2jet",conf_ak5_calo,[MatchingMC])
