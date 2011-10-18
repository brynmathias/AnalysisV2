#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
from icf.core import PSet,Analysis

from icf.utils import autoname

# The leptonic specicif settings&files
from onelepton_settings import *
from onelepton_BSM_Grids import *
from onelepton_MC_samples import *
from onelepton_Cuts_Plots import *
from onelepton_Data_samples import *

# here a few flags to ensure you correct all instances
mode = "data42X_PromptReco"

MET = "typeI"

ElectronPlots = LeptonicPlots("ElectronStandardPlots",el_plots_cfg.ps())
ElectronPlotsHLT = LeptonicPlots("ElectronStandardPlots_PostHLT",el_plots_cfg.ps())

triggerCUT = OP_MultiTrigger(etrg_set2.ps())

# muon specific plots/trees END
sig, tree, extra = setupElectronPreselection(MET,"Electrons", mode, True)

tree.TAttach(OneEl,RECO_CommonHTCut350)
tree.TAttach(RECO_CommonHTCut350,ElectronPlots)
tree.TAttach(ElectronPlots,triggerCUT)
tree.TAttach(triggerCUT,ElectronPlotsHLT)

### For the BSM set Weight = "mSuGra"
if mode == "MCGrid": conf.Ntuple.Weight = "mSuGra"

# List of samples available. Please add here.
samplesList = {
    "MCGrid"             : samplesBSMgrids,
    "MC311"              : samplesMC42Wtt, #samplesMC42QCD, #samplesMC42Wtt, #samplesMC311X,
    "MC38"               : samplesMC,
    "data39"             : samplesData,
    "data311"            : samplesData311,
    "data4X"             : samplesData311,
    "data42X_PromptReco" : samplesData42X_SingleEl_PromptReco,
    "data42X_ReReco"     : samplesData42X_SingleEl_ReReco,
    }

#if systematics: syst_str = "_"+systematics
#else:
syst_str = ""

output_dir = autoname("./resultsTrigger_e%(syst_mode)s", syst_mode=syst_str)
#output_dir = "./resultsMC_metdown"

# Run the analysis!
sig.Run(output_dir, conf, samplesList[mode])
