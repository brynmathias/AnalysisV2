#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *

from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig

# This imports our demo sample
import samples.icf_demo as icf

# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Common.Jets.EtCut=5.

qcd_test=PSet(
    Name="QCDJets_pt80_lite",
    File="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/QCDJets_Pythia_80.root",
#    Weights=PSet(
#        CrossSection =  [ 11.5 , 10.2 , 3.1  ],
#        Events       =  [ 100  , 200  , 300  ],
#        PtBin        =  [ 100. , 200. , 300. ]
#        ),
    Format=("ICF",2)
#    FirstEntry=0,
#    LastEntry=20000
   
)

filter_skinny=PSet(
    OutputDir="/home/georgia/dataICF/",
    Branches = [
        " drop * ",
        " keep event ",
	" keep run ",
	" keep electronP4Pat ",
	" keep electronChargePat ",
        " keep electronTrackIsoPat ",
	" keep electronEcalIsoPat ",
	" keep electronHcalIsoPat ",
	" keep electronEIDLoosePat ",
	" keep electronEIDTightPat ",
        " keep electronGsfTrackD0Pat ",
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
        " keep muonGlobalTrackdxyPat",
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

# Create the analysis
a=Analysis("FilterTest",filter_skinny)
s=[qcd_test]
a.Run("../results",conf,s)
