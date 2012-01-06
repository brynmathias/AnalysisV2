#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *

# -----------------------------------------------------------------------------
# Cut flow

def addCutFlow(a) :
    a+=numComJets
    a+=numComLeptons
    a+=numComPhotons
    a+=oddJet
    a+=oddMuon
    a+=oddElectron
    a+=oddPhoton
    a+=badMuonInJet
    a+=secondJetET
    a+=htCut
    a+=missedHT
    a+=plots_kinsuite
    a+=alphaT
    a+=plots_common
    
# -----------------------------------------------------------------------------
# Definition of analyses

anal_ic5_calo=Analysis("IC5Calo")
addCutFlow(anal_ic5_calo)

# -----------------------------------------------------------------------------
# Run analyses

anal_ic5_calo.Run("results",conf_ic5_calo,[lm0])
anal_ic5_calo.Run("results",conf_ic5_calo,[lm1])
anal_ic5_calo.Run("results",conf_ic5_calo,[qcd_pythia_merged])
anal_ic5_calo.Run("results",conf_ic5_calo,[w_jets])
anal_ic5_calo.Run("results",conf_ic5_calo,[z_jets])
anal_ic5_calo.Run("results",conf_ic5_calo,[ttbar_jets])
anal_ic5_calo.Run("results",conf_ic5_calo,[z_inv])
