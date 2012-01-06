#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
# The leptonic specicif settings&files
#from onelepton_settings import *
from onelepton_dataRA4_sync_settings import *
from onelepton_Cuts_Plots_RA4_Z import *
from onelepton_Skimmed_samples import *

# Data/MC samples
from onelepton_MC_samples import *
from onelepton_Data_samples import *
from onelepton_BSM_Grids import samplesBSMgrids
# systematics code
from onelepton.filters import muonSystematics
from icf.utils import autoname
import libHadronic as had

# here a few flags to ensure you correct all instances
#mode = "MC311"
#mode = "MC38"
#mode = "data39"
#mode = "data311"
#mode = "data4X"
#mode = "data42X_PromptReco"
#mode = "data42X_ReReco"
#mode  = "MCGrid"
#mode = "MC42ttw_Z41"
#mode  = "MC42QCD"
mode  = "Z_ReReco"
#mode  = "Z"

# Systematics
systematics = None
#systematics = "metup"
#systematics = "metdown"
#systematics = "metres_conservative"
#systematics = "polup"
#systematics = "poldown"
# systematics = "mupt"

# MET type
MET = "typeI"   

# These functions are defined in onelepton_Cuts_Plots.py
# Setup the analysis with standard preselection
# The function below attaches plots and cuts from onelepton_Cuts_Plots.py
# You can attach more cuts by doing tree.TAttach(cut, my_cut)
sig, tree, extra = setupMuonPreselection(MET, "Muons", mode)

# Systematics
syst_filters = muonSystematics(sig, systematics)

### For the BSM set Weight = "mSuGra"
if mode == "MCGrid": conf.Ntuple.Weight = "mSuGra"

# List of samples available. Please add here.
samplesList = {
   
    "MC311"              : samplesMC311X,
    "MC38"               : samplesMC,
    "data39"             : samplesData,
    "data311"            : samplesData311,
    "data4X"             : samplesData311,
    "Z" : samplesData42X_SingleMu_PromptReco_NewMuRecipe,
    "Z_ReReco"     : samplesData42X_SingleMu_ReReco_NewMuRecipe,
    "MC42ttw_Z41"        : samplesMC42Wtt,
    "MC42QCD"            : samplesMC42QCD,
    "RA4sync"            : dataRA4_sync
    }

if systematics: syst_str = "_"+systematics
else: syst_str = ""

output_dir = autoname("./resultsZ%(syst_mode)s", syst_mode=syst_str)
#output_dir = "./resultsMC_metdown"

# Run the analysis!
sig.Run(output_dir, conf, samplesList[mode])

