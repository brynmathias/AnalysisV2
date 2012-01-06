#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *






#-----------------------------------------------
# Set Everything for bkgd Plots

#conf_ic5_calo.Ntuple.Weight="mSuGra"


TanjaBkgdEstPlots_g1jets = PSet(DirectoryName = "BkgdEstPlots_g1jets",
                         MinObjects=2,
                         MaxObjects=9,
                         m0_felder=0,
                         m12_felder=0
                         )
plots_bkgdEstPlots_g1jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g1jets.ps() )

TanjaBkgdEstPlots_2jets = PSet(DirectoryName = "BkgdEstPlots_2jets",
                         MinObjects=2,
                         MaxObjects=2,
                         m0_felder=0,
                         m12_felder=0
                         )
plots_bkgdEstPlots_2jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_2jets.ps() )

TanjaBkgdEstPlots_g2jets = PSet(DirectoryName = "BkgdEstPlots_g2jets",
                         MinObjects=3,
                         MaxObjects=7,
                         m0_felder=0,
                         m12_felder=0 
                         )
plots_bkgdEstPlots_g2jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g2jets.ps() )

mSuGraScanPlots_pset = PSet(DirectoryName = "mSuGraScan")
plots_mSuGraScan = OP_mSuGraPlottingOps(mSuGraScanPlots_pset.ps() )

mSuGraScanPlots2_pset = PSet(DirectoryName = "mSuGraScan2")
plots_mSuGraScan2 = OP_mSuGraPlottingOps(mSuGraScanPlots2_pset.ps() )

mSuGraScanPlots3_pset = PSet(DirectoryName = "mSuGraScan3")
plots_mSuGraScan3 = OP_mSuGraPlottingOps(mSuGraScanPlots3_pset.ps() )  


# -----------------------------------------------------------------------------
# Cut flow

def addCutFlow(a) :
   # a+=plots_mSuGraScan
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
    a+=plots_bkgdEstPlots_g1jets
    a+=plots_bkgdEstPlots_2jets
    a+=plots_bkgdEstPlots_g2jets
    a+=htCut
    a+=plots_mSuGraScan2
    a+=alphaT
    a+=plots_mSuGraScan3
    a+=plots_common
    
# -----------------------------------------------------------------------------
# Definition of analyses

anal_ic5_calo=Analysis("IC5Calo")
addCutFlow(anal_ic5_calo)


# -----------------------------------------------------------------------------
# Run analyses

#anal_ic5_calo.Run("results",conf_ic5_calo,[mSuGraScan1])
#anal_ic5_calo.Run("results",conf_ic5_calo,[mSuGraScan2])
#anal_ic5_calo.Run("results",conf_ic5_calo,[mSuGraScan25])
#anal_ic5_calo.Run("results",conf_ic5_calo,[mSuGraScan4])
#anal_ic5_calo.Run("results",conf_ic5_calo,[mSuGraScan5])
#anal_nocc_ic5_calo.Run("results",conf_nocc_ic5_calo,[lm0])
    
    
#anal_ic5_calo.Run("results",conf_ic5_calo,[mSuGraScanTANB10])    

#anal_ic5_calo.Run("results",conf_ic5_calo,[lm1])
#anal_ic5_calo.Run("results",conf_ic5_calo,[qcd_pythia_merged])
anal_ic5_calo.Run("results",conf_ic5_calo,[w_jets])
anal_ic5_calo.Run("results",conf_ic5_calo,[z_jets])
anal_ic5_calo.Run("results",conf_ic5_calo,[ttbar_jets])
anal_ic5_calo.Run("results",conf_ic5_calo,[z_inv])
