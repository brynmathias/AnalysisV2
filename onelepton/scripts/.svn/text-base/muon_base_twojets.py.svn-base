#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
# The leptonic specicif settings&files
from onelepton_settings import *
from onelepton_Cuts_Plots import *
# MC/Data samples
from onelepton_BSM_Grids import *
from onelepton_MC_samples import *
from onelepton_Data_samples import *
from onelepton_Skimmed_samples import *

# Systematics code
from onelepton.filters import muonSystematics
from icf.utils import autoname
# here a few flags to ensure you correct all instances
#mode = "MC311"
#mode = "MC38"
mode = "MC42ttw_Z41"
#mode = "MC42QCD"
#mode = "data42X"
#mode = "data42X_PromptReco"
#mode = "data42X_ReReco"
#mode = "MCskims"
#mode = "dataskims"
#mode  = "MCGrid"
#mode  = "MC42QCD"

# Systematics
systematics = None
# systematics = "metup"
# systematics = "metdown"
# systematics = "metres_conservative"
# sysemtatics = "polup"
# systematics = "poldown"
#systematics = "mupt"


# MET type
#MET = "typeI"
MET = "uncor"

bins = [150, 250, 350, 450]
# Setup the preselection
# These functions are defined in onelepton_Cuts_Plots.py
sig, tree, extra = setupMuonPreselection(MET, "Muons", mode, less_than_3jets=True)

# Setup bins in LP
lp_sig_bins, lp_bkg_bins, nolp_bins, lp_ops = setupSignalBins(tree, LessThan3Jts, bins,
                                                   mode = "lp", sig_cut_value = 0.15,
                                                   bg_cut_value = 0.3)
# Setup bins in pfmet/leppt
pfmet_sig_bins, pfmet_bkg_bins,_, pfmet_ops = setupSignalBins(tree, LessThan3Jts, bins,
                                                              mode = "pfmet")

# Define some standard plots in each bin

#sig_plots = makePlots(tree, lp_sig_bins, LeptonicPlots, "MuonStandardPlots_%d", mu_plots_cfg.ps())
#bkg_plots = makePlots(tree, lp_bkg_bins, LeptonicPlots, "MuonStandardPlots_%d_BKG", mu_plots_cfg.ps())
#met_sig_plots = makePlots(tree, pfmet_sig_bins, LeptonicPlots, "MuonStandardPlots_PFMET_%d", mu_plots_cfg.ps())
#met_bkg_plots = makePlots(tree, pfmet_bkg_bins, LeptonicPlots, "MuonStandardPlots_PFMET_%d_BKG", mu_plots_cfg.ps())

#sig_plots = makePlots(tree, lp_sig_bins, OP_ANplots,"MuonANPlots_%d")
#bkg_plots = makePlots(tree, lp_bkg_bins, OP_ANplots,"MuonANPlots_%d_BKG")
#nolp_plots = makePlots(tree, nolp_bins, OP_ANplots, "MuonANPlots_%d_NOLP")


# sig_plots = makePlots(tree, lp_sig_bins, wpol.RECO_ttWPlotting,
# "ttWPlots_%d")

# bkg_plots = makePlots(tree, lp_bkg_bins, wpol.RECO_ttWPlotting,
# "ttWPlots_%d_BKG")x

sig_plots =  makePlots(tree, lp_sig_bins, OP_ANplots, "ANplots%d_LP")
nolp_plots = makePlots(tree, nolp_bins, OP_ANplots, "ANplots%d_NOLP")
nolp_plotsttW = makePlots(tree, nolp_bins, wpol.RECO_ttWPlotting, "RECO_ttWPlotting%d_NOLP")
sig_plotsttW = makePlots(tree, lp_sig_bins, wpol.RECO_ttWPlotting, "RECO_ttWPlotting%d_LP")


# Systematics
syst_filters = muonSystematics(sig, systematics)

### For the BSM set Weight = "mSuGra"
if mode == "MCGrid": conf.Ntuple.Weight = "mSuGra"
 
# List of samples available. Please add here.
samplesList = {
    "MCGrid"             : samplesBSMgrids,
    "MC311"              : samplesMC311X,
    "MC38"               : samplesMC,
    "data4X"             : samplesData311,
 #   "data42X_PromptReco" : samplesData42X_SingleMu_ReReco,
 #   "data42X_ReReco"     : samplesData42X_SingleMu_PromptReco,
    "data42X_PromptReco" : samplesDataSiMuNewPromt,
    "data42X_ReReco"     : samplesDataSiMuNew,
    "MCskims"            : MC42_madgraph_skims,
    "MC42ttw_Z41"        : samplesSynMC,#samplesMC42Wtt,
    "MC42QCD"            : samplesMC42QCD,
    "dataskims"          : data42_skims
    }

if systematics: syst_str = "_"+systematics
else: syst_str = ""

output_dir = autoname("./resultsMC_lt3j%(syst_mode)s", syst_mode=syst_str)
#output_dir = "./results"

# Run the analysis!
sig.Run(output_dir, conf, samplesList[mode])

