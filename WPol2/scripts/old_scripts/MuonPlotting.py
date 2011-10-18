#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libWPol import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

#import the samples (user dependent paths)
from wpol.samples_jad import *

#import the configuration
from wpol.muon_config import muon_id, conf

#can still override parameters
conf.Common.Muons.PtCut=10.0

# Create the analysis
muonplot=Analysis("MuonPlotting")

tree = Tree("Main")

# Initialise our operations
MuonPlots = RECO_MuonPlotting("testMuonPlotting")
ZtoTauTau = MC_ZtoLeptons("muon")
NumLeptons = OP_NumComLeptons("==", 1)

minDRMuonJetCut = RECO_MuonJetDRCut(0.5)
PFMETCut50 = RECO_PFMETCut(50.0)
PlotRECO50toinf = RECO_PolPlots("RECO_PolPlots_50toinf", "W", False)
PFMTCut30 = RECO_PFMTCut(30.0)
NumMuons = OP_NumComMuons("==", 1)
NumPh = OP_NumComPhotons("==", 0)
NumGoodJets = OP_NumComJets("<", 4)
OddJeti = OP_OddJet()
ZMassCut = RECO_2ndMuonMass(25.0, 91.2)

#add extra criteria to commonmuon definition
#can do this preCC or postCC i.e. before/after cross-cleaning
muonfilt=CustomMuonId(muon_id.ps())
muonplot.AddMuonFilter("PreCC",muonfilt)

# Add the tree to our analysis
muonplot+=tree
#tree.Attach(ZtoTauTau)
#tree.TAttach(ZtoTauTau, MuonPlots)
tree.Attach(NumLeptons)
tree.TAttach(NumLeptons, NumMuons)
tree.TAttach(NumMuons, NumPh)
tree.TAttach(NumPh, NumGoodJets)
tree.TAttach(NumGoodJets, OddJeti)
tree.TAttach(OddJeti, minDRMuonJetCut)
tree.TAttach(minDRMuonJetCut, ZMassCut)
tree.TAttach(ZMassCut, PFMETCut50)
#tree.TAttach(PFMETCut50, PFMTCut30)
tree.TAttach(PFMETCut50, MuonPlots)
tree.TAttach(PFMETCut50, PlotRECO50toinf)

# Define the list of samples to run over
w=[wjets]
z=[zjets]
data=[realdata]
qcd1=[qcdmu3050, qcdmu5080, qcdmu80120]
qcd2=[qcdmu120170, qcdmu170Inf]

muonplot.Run("results",conf,z)
