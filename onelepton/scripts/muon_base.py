#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
# The leptonic specicif settings&files
from onelepton_settings import *
from onelepton_Cuts_Plots import *
# Data/MC samples
from onelepton_MC_samples import *
from onelepton_Data_samples import *
from onelepton_BSM_Grids import samplesBSMgrids42, samplesSMS

from onelepton_Skimmed_samples import *
# systematics code
from onelepton.filters import muonSystematics
from icf.utils import autoname

# here a few flags to ensure you correct all instances
#mode = "data4X"
#mode = "data42X_PromptReco"
#mode = "data42X_ReReco"
#mode  = "MCGrid"
mode = "MC42ttw_Z41"
#mode  = "MC42QCD"
#mode = "MCskims"
#mode = "data42_muHadSkims"
##AUTOMATE_MODE##
#mode = "MC42QCDMu"
#mode = "sample_Fall11_data"

#mode = "SMS"

isSM = not (mode in ["MCGrid", "SMS"])

# Systematics
systematics = None
#systematics = "metup_flat"
#systematics = "metdown_flat"
#systematics = "metres_conservative"
#systematics = "polup"
#systematics = "poldown"
#systematics = "polup_plus"
#systematics = "poldown_plus"
#systematics = "mupt"
##AUTOMATE_SYSTEMATICS##



# MET type
#MET = "typeI"
MET = "Uncor"

# These functions are defined in onelepton_Cuts_Plots.py
# Setup the analysis with standard preselection
# The function below attaches plots and cuts from onelepton_Cuts_Plots.py
# You can attach more cuts by doing tree.TAttach(cut, my_cut)
sig, tree, extra = setupMuonPreselection(MET, "Muons", mode)

# Define bins to use
bins = [150, 250, 350, 450]
# This function sets up the signal and control bins requested and attaches them
# to the tree (after the 3 jet cut).
# Setup bins in LP
lp_sig_bins, lp_bkg_bins, nolp_bins, lp_ops = setupSignalBins(tree, AtLeast3Jts, bins,
                                                   mode = "lp", sig_cut_value = 0.15,
                                                   bg_cut_value = 0.3, SM = isSM)
# Setup bins in pfmet/leppt
pfmet_sig_bins, pfmet_bkg_bins, _, pfmet_ops = setupSignalBins(tree, AtLeast3Jts, bins,
                                                               mode = "pfmet", SM = isSM)

# Define some plots
#met_sig_plots = makePlots(tree, pfmet_sig_bins, wpol.RECO_ttWPlotting, "LepMet%d_PFisotest")
#met_bkg_plots = makePlots(tree, pfmet_bkg_bins, wpol.RECO_ttWPlotting, "LepMet%d_MuonID")
sig_plots =  makePlots(tree, lp_sig_bins, OP_ANplots, "ANplots%d_LP")
nolp_plots = makePlots(tree, nolp_bins, OP_ANplots, "ANplots%d_NOLP")
bkg_plots =  makePlots(tree, lp_bkg_bins, OP_ANplots, "ANplots%d_ConLP")

#nolp_plots = makePlots(tree, nolp_bins, OP_ANplots, "ANplots%d_NOLP")
#nolp_plotsttW = makePlots(tree, nolp_bins, wpol.RECO_ttWPlotting, "RECO_ttWPlotting%d_NOLP")
#sig_plotsttW = makePlots(tree, lp_sig_bins, wpol.RECO_ttWPlotting, "RECO_ttWPlotting%d_LP")
#bgk_plotsttW = makePlots(tree, lp_bkg_bins, wpol.RECO_ttWPlotting, "RECO_ttWPlotting%d_LPControl")

# Systematics
syst_filters = muonSystematics(sig, systematics)

### For the BSM set Weight = "mSuGra"
#if mode == "MCGrid": conf.Ntuple.Weight = "mSuGra"

# List of samples available. Please add here.
samplesList = {
    "MCGrid"             : samplesBSMgrids42,
    "data311"            : samplesData311,
    "data4X"             : samplesData311,
 #   "data42X_PromptReco" : samplesData42X_MuHad_PromptReco,
 #   "data42X_ReReco"     : samplesData42X_MuHad_ReReco,
    "data42X_PromptReco" : samplesDataMuHadresidualPrompt,
    "data42X_ReReco"     : samplesDataMuHadresidualMay,
  #  "MC42ttw_Z41"        : samplesMC42Wtt,
    "MC42ttw_Z41"        : samplesSynMC,
    "MC42QCD"            : samplesMC42QCD,
    "MCskims"            : MC42_madgraph_skims,
    "data42_muHadSkims"  : data42_skims,
    "MC42QCDMu"          : samplesMCQCDmu,
    "FASTW"              : [WJets_HT300toInf_Madgraph_Summer11_GEN_V2_leo_TuneZ2_Fastsim_4_2_4_p1_NoPU_V2_651176baf0801b18003b251b106ec60b],
    "SMS"                : samplesSMS
    "sample_Fall11_data" : sample_Fall11
    }

if systematics: syst_str = "_"+systematics
else: syst_str = ""


if mode.startswith("data"): output_dir = autoname("./resultsData")
else: output_dir = autoname("./resultsMC%(syst_mode)s", syst_mode=syst_str)

#output_dir = "./notrigger"

# Run the analysis!
sig.Run(output_dir, conf, samplesList[mode])
