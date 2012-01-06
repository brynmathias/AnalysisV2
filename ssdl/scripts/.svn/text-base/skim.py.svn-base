#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY
# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libSSDL import *
# from libWPol import *
import lep_conf as lepconf
import icf.utils as utils
import icf.types as types
import glob
from data.JetMETTau_ALL_230810 import *
from montecarlo.QCD_Pythia6_allBins import *
from montecarlo.TTBarTauola import *
from montecarlo.WJets_Madgraph import *
from montecarlo.Zjets_madgraph import *
from montecarlo.LMx import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig 


# import default configuration
conf=defaultConfig.copy()

ele_id = PSet(
    ParticleFlow=True,
    OldNtu = False,
    Cuts = lepconf.ele_ptThres_vbtf80,
    IsolationSR = False,      # high pt
    HoverE = False,
    DeltaAtVtx = False,
    SigmaIEtaIEta = False,
    Conversions = True,
    ConversionsExtra = False,    # not in ntuple V00-08
    IsolationPF = False,
    LowPtSel = False,
    LowPtID = False,
    LowPtIso = False,
    ChargeComp = True,
    D0sel = True
)

muon_id = PSet(
   ParticleFlow=True,
   Cuts = lepconf.muonCuts,
   IsolationPF = False,
   IsolationSR = True,
   LowPtIso = True,
   MuonID = True,
   MuonIso = True,
   dxychoice = "vertex"
#   dxychoice = "beamspot"
)

muon_id2 = PSet(
   ParticleFlow=False,
   Cuts = lepconf.muonCuts,
   IsolationPF = False,
   IsolationSR = True,
   LowPtIso = True,
   MuonID = True,
   MuonIso = True,
   dxychoice = "vertex"
#   dxychoice = "beamspot"
)

tau_id = PSet(
 tauIDbyTaNC = True
)

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Ntuple.Electrons.Suffix = "PF"
conf.Ntuple.Muons.Suffix = "PF"
conf.Ntuple.SecMuons.Suffix='Pat'
conf.Ntuple.Taus.Suffix = "Pat"
conf.Ntuple.Jets.Suffix = "Pat"
conf.Ntuple.Jets.Prefix = "ak5JetPF"

conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.EtaCut = 2.4     
conf.Common.Muons.TrkIsoCut = 99.
conf.Common.Muons.CombIsoCut = 99.
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 5.0
conf.Common.Electrons.EtaCut = 2.5
conf.Common.Electrons.TrkIsoCut = 99.
conf.Common.Electrons.CombIsoCut = 99.
conf.Common.Electrons.TightID = False
conf.Common.Electrons.ApplyID = False

conf.Common.Taus.PtCut = 5.0
conf.Common.Taus.EtaCut = 2.5
conf.Common.Taus.TightID = False
conf.Common.Taus.ApplyID = False


conf.Common.Jets.PtCut = 50.0

# Here we define a sample to use
# The path and the filename are separate so you can easily move to using
# local samples.
JMT_data_test=PSet(
	Name="JMT_test",
        File=["/vols/cms02/aeg04/JMT_sample.root"],
        Format=("ICF",2),
        Weight=1.0,
#        FirstEntry=147,
#        LastEntry=156      
)

wjets_test=PSet(
    Name="wjets_TEST",
     CrossSection=24170., #normalised to 1/pb (7TeV) = 241.70
    Format=("ICF",2),
    File= [
"/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_10.root",
"/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_11.root"
        ],
    )


# Create the analysis
a=Analysis("ssdl_skimer")


# Add the tree to our analysis
tree = Tree('Main')

skim_cf=PSet(
    SkimName = "myskim",
    DropBranches = False,
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

skim = SkimOp(skim_cf.ps())
comLeps = OP_NumAllLeptons('>',0)
lepsel = SkimSel(ele_id.ps(),muon_id.ps(),muon_id2.ps(),tau_id.ps())

# def flatten_samples(s):
#     arr = []
#     for idx, samp in enumerate(s.File):
#         print idx
#         print samp
#         stemp = s.copy()
#         for i,s1 in enumerate(glob.glob(samp)):
#             print i
#             print s1
#             idx=idx+i
#             stemp.File = s1
#             stemp.Name = "%s_%d" % (s.Name, idx)
#             arr.append(stemp)
#     print arr
#     return arr

a+=tree
tree.Attach(lepsel)
tree.TAttach(lepsel, skim)
# Define the list of samples to run over
samples=[]
data=[JetMET_ALL_upto230810]
SM_MC=[QCD_AllPtBins_7TeV_Pythia, ttbarTauola, wjets_madgraph, zjets_madgraph]
QCD_pythia6=[QCD_Pt30_7TeV_Pythia,QCD_Pt80_7TeV_Pythia,QCD_Pt170_7TeV_Pythia,QCD_Pt300_7TeV_Pythia,QCD_Pt470_7TeV_Pythia,QCD_Pt800_7TeV_Pythia,QCD_Pt1400_7TeV_Pythia]
allqcd=[QCD_AllPtBins_7TeV_Pythia]
all=data+SM_MC
ttbar=[ttbarTauola]
w_z_jets=[wjets_madgraph, zjets_madgraph]
ttbar_bosonJets=[ttbarTauola,wjets_madgraph, zjets_madgraph]
bosonJets_vols=[wjets_madgraph_vols,zjets_madgraph_vols]
wjet=[wjets_madgraph]
zjet=[zjets_madgraph]
test=[JMT_data_test]
wjetstest=[wjets_test]
sig=[LM0]

# samples.extend(flatten_samples(QCD_Pt30_7TeV_Pythia))

a.Run('/vols/cms02/aeg04/JMT_skims/',conf,data)

