#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *

#-----------------------------------------------
# Set Everything for bkgd Plots
TanjaBkgdEstPlots_2jets = PSet(DirectoryName = "BkgdEstPlots_2jet",
                         MinObjects=2,
                         MaxObjects=2
                         )
plots_bkgdEstPlots_2jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_2jets.ps() )

TanjaBkgdEstPlots_g2jets = PSet(DirectoryName = "BkgdEstPlots_g2jets",
                         MinObjects=3,
                         MaxObjects=7
                         )
plots_bkgdEstPlots_g2jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g2jets.ps() )


# -----------------------------------------------------------------------------
# Cut flow

def addCutFlow(a) :
    a+=oddJet
    a+=oddMuon
    a+=oddElectron
    a+=oddPhoton
    a+=badMuonInJet
    a+=numComJets
    a+=numComLeptons
    a+=numComPhotons
    a+=secondJetET
    a+=missedHT
    a+=plots_bkgdEstPlots_2jets
    a+=plots_bkgdEstPlots_g2jets
    a+=htCut  
    a+=alphaT
    a+=plots_common
    
# -----------------------------------------------------------------------------
# Definition of analyses

anal_ic5_calo=Analysis("IC5Calo")
addCutFlow(anal_ic5_calo)

anal_nocc_ic5_calo=Analysis("IC5Calo_nocc")
addCutFlow(anal_nocc_ic5_calo)


# -----------------------------------------------------------------------------
# Run analyses

anal_ic5_calo.Run("results",conf_ic5_calo,[lm0])
#anal_nocc_ic5_calo.Run("results",conf_nocc_ic5_calo,[lm0])
    
    
    

#anal_ic5_calo.Run("results",conf_ic5_calo,[lm1])
#anal_ic5_calo.Run("results",conf_ic5_calo,[qcd_pythia_merged])
#anal_ic5_calo.Run("results",conf_ic5_calo,[w_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[z_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[ttbar_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[z_inv])
