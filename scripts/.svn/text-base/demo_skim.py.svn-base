#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
#from libOneLepton import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig


# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Common.Jets.EtCut=200.

# Create the analysis
a=Analysis("Demo")


from alexSamples.local import lm0


# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")

skim_cf=PSet(
    SkimName = "myskim",
    DropBranches = False,
    Branches = [
        " drop * ",
        " keep event ",
	" keep run ",
        " keep ak5JetCorrectedP4Pat ",
        " keep ak5JetEmEnergyFractionPat ",
        " keep ak5JetJetIDloosePat ",
        " keep ak5JetJetIDminimalPat ",
        " keep ak5JetJetIDtightPat ",
	" keep electronP4Pat ",
	" keep electronChargePat ",
        " keep electronTrackIsoPat ",
	" keep electronEcalIsoPat ",
	" keep electronHcalIsoPat ",
	" keep electronEIDLoosePat ",
	" keep electronEIDTightPat ",
        " keep electronGsfTrackDxyPat ",
        " keep electronHcalOverEcalPat ",
        " keep electronDeltaPhiSuperClusterTrackAtVtxPat ",
        " keep electronDeltaEtaSuperClusterTrackAtVtxPat ",
        " keep electronSigmaIetaIetaPat ",
        " keep electronHasValidHitInFirstPixelBarrelPat ",
	" keep muonP4Pat ",
	" keep muonChargePat ",
	" keep muonTrackIsoPat ",
	" keep muonEcalIsoPat ",
	" keep muonHcalIsoPat ",
	" keep muonIsGlobalMuonPat ",
	" keep muonIDGlobalMuonPromptTightPat ",
        " keep muonIsTrackerMuonPat",
        " keep muonGlobalTrackDxyPat",
        " keep muonGlobalTracknormalizedChi2Pat",
        " keep muonGlobalTracknumberOfValidHitsPat",
	" keep tauP4Pat ",
	" keep tauChargePat ",
	" keep tauTrkIsoPat ",
	" keep tauEcalIsoPat ",
	" keep tauHcalIsoPat ",
	" keep ic5JetCorrectedP4Pat ",
	" keep ic5JetEmEnergyFractionPat ",
	" keep photonP4Pat ",
	" keep photonTrkIsoPat ",
	" keep photonEcalIsoPat ",
	" keep photonHcalIsoPat ",
	" keep photonCaloIsoPat ",
	" keep photonIDLoosePat ",
	" keep photonIDTightPat ",
	" keep genHandleValid ",
	" keep genP4 ",
	" keep genStatus ",
	" keep genHasMother ",
	" keep genMotherStored ",
	" keep genMother ",
	" keep genPdgId ",
        " keep genpthat",
        " keep metP4AK5 ",
        " keep metP4Calo ",
        " keep metP4IC5 ",
        " keep metP4PF ",
        " keep metP4TC ",
        " keep metnohfP4Calo ",
	" keep triggered ",
	" keep hltHandleValid "
        ]
)

# Initialise our operations
dijet=OP_NumComJets(">=",2)
trijet=OP_NumComJets(">=",7)
#plot2=OP_KinSuiteComPlot("plot2",10,2)
#plot3=OP_KinSuiteComPlot("plot3",10,2)
#demoop=DemoOp()
skim = SkimOp(skim_cf.ps())

# Add the tree to our analysis
a+=tree
tree.Attach(dijet)
#tree.TAttach(dijet,plot2)
tree.TAttach(dijet, trijet)
tree.TAttach(trijet, skim)
#tree.TAttach(plot3, skim)

#tree.TAttach(plot3,demoop)
#tree.TAttach(demoop,skim)
# Define the list of samples to run over

#lm0.File = "/home/alex/Research/Samples/ICF/LM0_hadd.root"
s=[lm0]
a.Run("../results",conf,s)
