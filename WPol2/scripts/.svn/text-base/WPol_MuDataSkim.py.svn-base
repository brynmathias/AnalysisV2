#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libWPol import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# Import the samples (user dependent paths)
from wpol.samples_jad import *

# Import the configuration
from wpol.muon_config import muon_id, conf

# We can still override parameters, for example:
conf.Common.Muons.PtCut=20.0

#SET THIS PARAMETER to either W or Z to ensure that the plotting code is setup appropriately
selection = "W"
#remember to choose the sample you will run over at the bottom - it could be data!

# Now check that you've entered either W or Z
if selection == "W":
    print "W-selection chosen"
elif selection == "Z":
    print "Z-selection chosen"
else:
    raise NameError("selectiontype")

# Create the analysis
a_name = "RecoRoutines_" + selection + "-selection_MuDataSkim"
recoplots=Analysis(a_name)

#add extra criteria to commonmuon definition
#can do this preCC or postCC i.e. before/after cross-cleaning
muonfilt=CustomMuonId(muon_id.ps())
recoplots.AddMuonFilter("PreCC",muonfilt)
#recoplots.AddMuonFilter("PostCC",muonfilt)

skim_cf=PSet(
    SkimName = "MuDataSkim",
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

skimop=SkimOp(skim_cf.ps())

tree = Tree("Main")

# Initialise our operations
GoodEventSelection = OP_GoodEventSelection()
NumLeptons1 = OP_NumComLeptons("==", 1)
NumLeptons2 = OP_NumComLeptons("==", 2)
NumMuons1 = OP_NumComMuons("==", 1)
NumMuons2 = OP_NumComMuons("==", 2)
Trigger = TRIGGER_Cut("HLT_Mu9","HLT_Mu15_v1")

# Add the tree to our analysis
recoplots+=tree
if selection == "W":
    tree.Attach(Trigger)
    tree.TAttach(Trigger, GoodEventSelection)
    tree.TAttach(GoodEventSelection, NumLeptons1)
    tree.TAttach(NumLeptons1, NumMuons1)
    tree.TAttach(NumMuons1, skimop)
else:
    tree.Attach(Trigger)
    tree.TAttach(Trigger, NumLeptons2)
    tree.TAttach(NumLeptons2, NumMuons2)
    tree.TAttach(NumMuons2, skimop)

# Define the list of samples to run over
#wjets.LastEntry=100000
#wjets.Name+="_shift_pfmht_m3pc"
w=[wjets]
wmu=[wmupythia]
wsherpa=[wjets_sherpa]
z=[zjets]
qcd1=[qcdmu3050, qcdmu5080, qcdmu80120]
qcd2=[qcdmu120170, qcdmu170Inf]
qcdall=[qcdmu3050, qcdmu5080, qcdmu80120, qcdmu120170, qcdmu170Inf]
#realdata1.Name+="_nogoodevsel"
data=[realdata1, realdata2, realdata3, realdata4, realdata5, realdata6, realdata7, realdata8, realdata9, realdata10, realdata11]
data38=[realdata2010A,realdata2010B_1,realdata2010B_2,realdata2010B_3,realdata2010B_4,realdata2010B_5]
qcdpythia=[qcdpythia_allptbins]
ttbar=[ttbarjets]

#realdata2010A.LastEntry=100000

recoplots.Run("results",conf,[realdata2010B_5])
