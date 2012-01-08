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

pwd = commands.getoutput('echo $SUSY_WORKING_SW_DIR')
output_dir = pwd + "/results/v12/"

# -----------------------------------------------------------------------------
# Reading the collections from the ntuple

default_ntuple = deepcopy(defaultConfig.Ntuple)

# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=False
default_cc.ElectronJet=False
default_cc.PhotonJet=False
default_cc.ResolveConflicts=False

# -----------------------------------------------------------------------------
# Definition of common objects

default_common = deepcopy(defaultConfig.Common)
default_common.ApplyXCleaning=False

# -----------------------------------------------------------------------------
# Common configurations

conf = deepcopy(defaultConfig)
conf.Ntuple = deepcopy(ak5_calo)
conf.XCleaning = deepcopy(default_cc)
conf.Common = deepcopy(default_common)

# -----------------------------------------------------------------------------
# Test module

from allhadronic.algorithms_cfi import *

ps = PSet(
    Verbose = False,
    DirName = "Triggers",
    nMin = 2,
    nMax = 4,
    Algorithms = AlgorithmsPSet,
    Filters = ["HLT_HT??_v*",
               "HLT_HT???_v*",
               "HLT_HT????_v*",
               "HLT_HT*_MHT*_v*",
               "HLT_HT*_AlphaT*_v*",
               "HLT_Mu*_HT*_v*"],
    Versus = 2,
    )
test = Trigger(ps.ps())

# -----------------------------------------------------------------------------
# Cut flow

JsonFileOption = "/hadronic/python/hadronic/2011GoldenJson.json"

json = JSONFilter("JSON",json_to_pset(pwd+JsonFileOption))
json_output = JSONOutput("_filtered")

cut_flow = Tree("CutFlow")
cut_flow.Attach(json)
cut_flow.TAttach(json,json_output)
cut_flow.TAttach(json_output,test)

# -----------------------------------------------------------------------------
# Dataset

data=PSet(
    Name="HT_Run2011A_PromptReco_v1",
    Format=("ICF",3),
    File= [
    "dcap://xrootd.grid.hep.ph.ic.ac.uk//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/henning//ICF/automated/2011_04_13_17_17_19///SusyCAF_Tree_9_1_zCe.root" ,
    #"/Users/bainbrid/Desktop/work/data/HT_Run2011A_PromptReco_v1.root",
    ],
    Weight=1.,
    LastEntry = 10,
    )

from data.Jet_35pb_WithTP_json051110 import Jet_35pb_WithTP_json051110
from data.Run2011.HT42_incomplete import HT42_incomplete
from data.Run2011.HT_Run2011_promptReco_DCS import HT_Run2011_promptReco_DCS
from data.Run2011.HT_Run2011A import HT_Run2011A
from data.Run2011.HT_Run2011A_PromptReco_v1 import HT_Run2011A_PromptReco_v1
from data.Run2011.HT_Run2011A_L1OffSet import HT_Run2011A_L1OffSet
from data.Run2011.HT_Run2011AB import HT_Run2011AB
from allhadronic.HT_Run2011A_1fb import HT_Run2011A_1fb

# -----------------------------------------------------------------------------
# Analysis

anal=Analysis("Trigger")
#anal.AddPhotonFilter("PreCC",phot_filter)
#anal.AddElectronFilter("PreCC",ele_filter)
#anal.AddJetFilter("PreCC",JetCorrections)
anal+=cut_flow

anal.Run(".",conf,[data])
#anal.Run(".",conf,[Jet_35pb_WithTP_json051110])
#anal.Run(".",conf_ak5_calo,[HT_Run2011A_PromptReco_v1])
#anal.Run(".",conf_ak5_calo,[HT_Run2011_promptReco_DCS])
#anal.Run(output_dir,conf_ak5_calo,[HT42_incomplete])
#anal.Run(output_dir,conf_ak5_calo,[HT_Run2011A_L1OffSet])
#anal.Run(output_dir,conf_ak5_calo,[HT_Run2011A])
#anal.Run(output_dir,conf_ak5_calo,[HT_Run2011A_AllReco_17June])
#anal.Run(output_dir,conf_ak5_calo,[HT_Run2011AB])

