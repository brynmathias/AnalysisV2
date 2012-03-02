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
from onelepton.filters import electronSystematics
from icf.utils import autoname

# here a few flags to ensure you correct all instances
#mode = "MC311"
#mode = "MC38"
#mode = "data39"
#mode = "data311"
#mode = "data4X"
#mode = "data42X_PromptReco"
#mode = "data42X_ReReco"
#mode = "MC42ttw_Z41"
#mode  = "MC42QCD"
#mode  = "MCGrid"
#mode = "SMS"
#mode = "data42X_Sync"
#mode = "data42X_Run2011Full"
mode = "MC_Summer11"
#mode = "MC_Fall11"
##AUTOMATE_MODE##

isSM = not (mode in ["MCGrid", "SMS"])

# Systematics
systematics = None
#systematics = "metup"
#systematics = "metdown"
#systematics = "metres_conservative"
#systematics = "polup"
#systematics = "poldown"
#systematics = "polup_plus"
#systematics = "poldown_plus"


# MET type
#MET = "typeI"
MET = "Uncor"

run_qcd_antiselection = False

# These functions are defined in onelepton_Cuts_Plots.py
# Setup the analysis with standard preselection
# The function below attaches plots and cuts from onelepton_Cuts_Plots.py
# You can attach more cuts by doing tree.TAttach(cut, my_cut)
sig, tree, extra = setupElectronPreselection(MET, "Electrons", mode, qcd_antiselection = run_qcd_antiselection)

# Define ST bins to use
#bins = [0,150]
bins = [0,150, 250, 350, 450]

# Define HT bins to use
HTbins = [500,999999999999999999]
#HTbins = [500, 750, 1000, 999999999999999999]

BinnedHTPTCut = []
backtuple_list = []
sig_plots = []
nolp_plots = []
bkg_plots = []


for idxHT, sbinHT in enumerate(HTbins):
    if len(HTbins)-1==idxHT:
        BinnedHTPTCut += [OP_HTPTCut(HTbins[idxHT],-1.)]
    else:
        BinnedHTPTCut += [OP_HTPTCut(HTbins[idxHT],HTbins[idxHT+1])]
        
        tree.TAttach(AtLeast3Jts,BinnedHTPTCut[idxHT])
        backtuple_list  += [setupSignalBins(tree, BinnedHTPTCut[idxHT], bins, HTbins[idxHT],
                                            mode = "lp", sig_cut_value = 0.15,
                                            bg_cut_value = 0.3, SM = isSM)]
        nameAdd = "secondD%d" % HTbins[idxHT]
        sig_plots +=  [makePlots(tree, backtuple_list[idxHT][0], OP_ANplots, "ANplots%d_LP"+nameAdd)]
        nolp_plots += [makePlots(tree,backtuple_list[idxHT][2] , OP_ANplots, "ANplots%d_NOLP"+nameAdd)]
        bkg_plots +=  [makePlots(tree,backtuple_list[idxHT][1] , OP_ANplots, "ANplots%d_ConLP"+nameAdd)]
        
# This function sets up the signal and control bins requested and attaches them
# to the tree (after the 3 jet cut).
# Setup bins in LP
#lp_sig_bins, lp_bkg_bins, nolp_bins, lp_ops = setupSignalBins(tree, AtLeast3Jts, bins,
#                                                   mode = "lp", sig_cut_value = 0.15,
#                                                   bg_cut_value = 0.3, SM=isSM)
# Setup bins in pfmet/leppt
#pfmet_sig_bins, pfmet_bkg_bins, _, pfmet_ops = setupSignalBins(tree, AtLeast3Jts, bins,
#                                                               mode = "pfmet", SM = isSM)

# Define some plots
#sig_plots = makePlots(tree, lp_sig_bins, LeptonicPlots, "MuonStandardPlots_%d", mu_plots_cfg.ps())
#bkg_plots = makePlots(tree, lp_bkg_bins, LeptonicPlots, "MuonStandardPlots_%d_BKG", mu_plots_cfg.ps())
#nolp_plots = makePlots(tree, nolp_bins, LeptonicPlots, "ElectronStandardPlots_%d_NOLP", el_plots_cfg.ps())

#met_sig_plots = makePlots(tree, pfmet_sig_bins, LeptonicPlots, "MuonStandardPlots_PFMET_%d", mu_plots_cfg.ps())
#met_bkg_plots = makePlots(tree, pfmet_bkg_bins, LeptonicPlots, "MuonStandardPlots_PFMET_%d_BKG", mu_plots_cfg.ps())


#sig_plots = makePlots(tree, lp_sig_bins, OP_ANplots,"MuonANPlots_%d")
#bkg_plots = makePlots(tree, lp_bkg_bins, OP_ANplots,"MuonANPlots_%d_BKG")
#nolp_plots = makePlots(tree, nolp_bins, OP_ANplots, "MuonANPlots_%d_NOLP")

#bkg_plots =  makePlots(tree, lp_bkg_bins, OP_ANplots, "ANplots%d_BKG")
#sig_plots =  makePlots(tree, lp_sig_bins, OP_ANplots, "ANplots%d_LP")
#nolp_plots = makePlots(tree, nolp_bins, OP_ANplots, "ANplots%d_NOLP")

# Systematics
syst_filters = electronSystematics(sig, systematics)

# List of samples available. Please add here.
samplesList = {
    "MCGrid"             : samplesBSMgrids42,
    "MC311"              : samplesMC_WandTT, #samplesMC_QCD, #samplesMC_Approval, #samplesMC42X, #samplesMC_WandTT,
    "data39"             : samplesData,
    "data311"            : samplesData311,
    "data4X"             : samplesData311,
    "data42X_PromptReco" : samplesData42X_ElHad_PR_V15_03_14_residual,#samplesData42X_ElHad_PromptReco,
    "data42X_ReReco"     : samplesData42X_ElHad_RR_V15_03_14_residual,#samplesData42X_ElHad_ReReco,
    "data42X_Run2011Full": samplesData42X_ElHad_V15_03_19_residual,
    "MC_Summer11"        : samplesMC_Summer11,
    "MC_Fall11"          : samplesMC_Fall11,
    #    "data42X_Sync"       : samplesData42X_ElHad_May10Sync,
    "MC42ttw_Z41"        : samplesMC42Wtt,
    "MC42QCD"            : samplesMC42QCD,
    "SMS"                : samplesSMS
    
    }

if systematics: syst_str = "_"+systematics
else: syst_str = ""

#if mode.startswith("data"): output_dir = autoname("./resultsData")
#else: output_dir = autoname("./resultsMC%(syst_mode)s", syst_mode=syst_str)
output_dir = "/vols/cms01/gouskos/20120113_El_HTbins_STbins_Sel"
#output_dir = "./data"

# Run the analysis!
sig.Run(output_dir, conf, samplesList[mode])
