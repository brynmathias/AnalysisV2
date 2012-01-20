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

z_test=PSet(
    Name="ZJets_madgraph_lite2",
    File=["~/jaddisk3/SUSYICFv2Ntuples/ZJets-madgraph_ICFv2.root"],
#    Weights=PSet(
#        CrossSection =  [ 11.5 , 10.2 , 3.1  ],
#        Events       =  [ 100  , 200  , 300  ],
#        PtBin        =  [ 100. , 200. , 300. ]
#        ),
    Format=("ICF",2)
#    FirstEntry=0,
#    LastEntry=10   
)

w_test=PSet(
    Name="WJets_madgraph_lite2",
    File=["~/jaddisk3/SUSYICFv2Ntuples/WJets-madgraph_ICFv2.root"],
    Format=("ICF",2)   
)


qcdpythia_mu_30to50=PSet(
    Name="QCD_pythia_30to50mu_lite",
    File=["~/jaddisk2/QCD_Mu_Pt30to50.root"],
    Format=("ICF",2)   
)

qcdpythia_mu_50to80=PSet(
    Name="QCD_pythia_50to80mu_lite",
    File=["~/jaddisk2/QCD_Mu_Pt50to80.root"],
    Format=("ICF",2)   
)

qcdpythia_mu_80to120=PSet(
    Name="QCD_pythia_80to120mu_lite",
    File=["~/jaddisk2/QCD_Mu_Pt80to120.root"],
    Format=("ICF",2)   
)

qcdpythia_mu_120to170=PSet(
    Name="QCD_pythia_120to170mu_lite",
    File=["~/jaddisk2/QCD_Mu_Pt120to170.root"],
    Format=("ICF",2)   
)

qcdpythia_mu_170toInf=PSet(
    Name="QCD_pythia_170toInfmu_lite",
    File=["~/jaddisk2/QCD_Mu_Pt170toInf.root"],
    Format=("ICF",2)   
)

wpythiamunu=PSet(
    Name="Wmunu_pythia_lite",
    File="~/jaddisk2/WmunuPythia.root",
    Format=("ICF",2)
)

filter_skinny=PSet(
    OutputDir="~/jaddisk2/",
    Branches = [
        " drop * ",
        " keep event ",
	" keep run ",
	" keep beamSpotPosition ",
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
        " keep muonIsTrackerMuonPat ",
        " keep muonGlobalTrackdxyPat ",
        " keep muonGlobalTrackdxyErrorPat ",
        " keep muonGlobalTracknormalizedChi2Pat ",
        " keep muonGlobalTracknumberOfValidHitsPat ",
        " keep muonInnerTrackDxyBSPat ",
        " keep muonInnerTrackDxyPat ",
        " keep muonInnerTrackDxyErrorPat ",
        " keep muonInnerTrackNormalizedChi2Pat ",
        " keep muonInnerTrackNumberOfValidHitsPat ",
	" keep tauP4Pat ",
	" keep tauChargePat ",
	" keep tauTrkIsoPat ",
	" keep tauEcalIsoPat ",
	" keep tauHcalIsoPat ",
	" keep ic5JetCorrectedP4Pat ",
	" keep ic5JetEmEnergyFractionPat ",
        " keep ic5JetJetIDloosePat ",
        " keep ic5JetJetIDminimalPat ",
        " keep ic5JetJetIDtightPat ",
        " keep ic5JetCorrFactorPat ",
        " keep ic5JetGenJetP4Pat ",
        " keep ic5JetGenJetMatchIndexPat ",
        " keep muonOuterTrackNumberOfValidHitsPat ",
        " keep muonInnerTrackDzPat ",
        " keep muonVertexChi2Pat ",
        " keep muonVertexNdofPat ",
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
s=[w_test]
a.Run("results",conf,s)
