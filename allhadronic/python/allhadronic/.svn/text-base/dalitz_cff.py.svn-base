#!/usr/bin/env python
"""
Golden_cfg.py

Created by Bryn Mathias on 2010-05-07.
"""

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
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

default_ntuple.Jets=PSet( # GEN JETS
Prefix="ak5Jet", 
Suffix="Pat",
UseGenJets=True,
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
default_cc.MuonJet=False
default_cc.ElectronJet=False
default_cc.PhotonJet=False
default_cc.ResolveConflicts=False
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0

# -----------------------------------------------------------------------------
# Definition of common objects

default_common = deepcopy(defaultConfig.Common)

default_common.ApplyXCleaning=False
default_common.Jets.PtCut=10.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=False
default_common.Jets.TightID=False

# -----------------------------------------------------------------------------
# Common cut definitions

selection = OP_GoodEventSelection()

# -----------------------------------------------------------------------------
# Common cut flows

cutTreeMC = Tree("MC")
cutTreeMC.Attach(selection)

