#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
#from libOneLepton     import *
from libTopSusy       import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet, Analysis

# This is the default configuration
from icf.config import defaultConfig

# import default configuration
conf = defaultConfig


lm0 = PSet(
  Name         = "lm0",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM0_229_PATV5_NT7_whyntie.root",
  CrossSection = 22.0,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd100To250 = PSet(
  Name         = "qcd100To250",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/QCDMG/QCD_MG_HT100to250_229_PATV5_NT7_whyntie.root",
  CrossSection = 3000000.0,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd250To500 = PSet(
  Name         = "qcd250To500",
  File         = "/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD250to500_NT7.root",
  CrossSection = 80000.0,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd500To1000 = PSet(
  Name         = "qcd500To1000",
  File         = "/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD500to1000_NT7.root",
  CrossSection = 2800.0,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd1000ToInf = PSet(
  Name         = "qcd1000ToInf",
  File         = "/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD1000toInf_NT7.root",
  CrossSection = 74.0,
#  LastEntry    = 100000,
  Format       = ("NT", 7)
)

ttJets = PSet(
  Name         = "ttJets",
  File         = "/castor/cern.ch/user/n/nsaoulid/TTBAR_V7/TTJets_madgraph_NT7.root",
  CrossSection = 82.8,
#  LastEntry    = 10000,
  Format       = ("NT", 7)
)

wJets = PSet(
  Name         = "wJets",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/WJetsMG/WJetsMG_229_PATV5_NT7_whyntie.root",
  CrossSection = 9100.0,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

zJets = PSet(
  Name         = "zJets",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/ZJetsMG/ZJetsMG_229_PATV5_NT7whyntie.root",
  CrossSection = 840.0,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

# Create the analysis
a = Analysis("TopSusy")

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")

# Initialise our operations

###STANDARD SELECTION

singleElectron2 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   2.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   0.1,
  MaxElecTkIso    =    3.0,   
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   2.
)



###LOOSE ISOLATION
singleElectronIsoLoose2 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   2.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
  MaxElecTkIso     =   300., 
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   2.
)


singleElectronNjet2 = PSet(


  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   2.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   1,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =   3,
  
  ##EVENT
  MinHt            =  100.0,
  MaxHt            = 350.,
  MinMht           =   0.0,
  MaxMht           =  50000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   0.5,
  MinSecondLeptonPt=   2.
)




###STANDARD SELECTION

singleElectron5 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   5.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   0.1,
    MaxElecTkIso     =   3.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   5.
)



###LOOSE ISOLATION
singleElectronIsoLoose5 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   5.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   5.
)


singleElectronNjet5 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   5.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   1,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =   3,
  
  ##EVENT
  MinHt            =  100.0,
  MaxHt            = 350.,
  MinMht           =   0.0,
  MaxMht           =  50000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   0.5,
  MinSecondLeptonPt=   5.
)



singleElectron10 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   10.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   0.1,
    MaxElecTkIso     =   3.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)



###LOOSE ISOLATION
singleElectronIsoLoose10 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   10.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)


singleElectronNjet10 = PSet(


  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   10.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   1,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =   3,
  
  ##EVENT
  MinHt            =  100.0,
  MaxHt            = 350.,
  MinMht           =   0.0,
  MaxMht           =  50000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   0.5,
  MinSecondLeptonPt=   10.
)




singleElectron15 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   15.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   0.1,
    MaxElecTkIso     =   3.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)



###LOOSE ISOLATION
singleElectronIsoLoose15 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   15.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)


singleElectronNjet15 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   15.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   1,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =   3,
  
  ##EVENT
  MinHt            =  100.0,
  MaxHt            = 350.,
  MinMht           =   0.0,
  MaxMht           =  50000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   0.5,
  MinSecondLeptonPt=   10.
)




singleElectron20 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   20.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   0.1,
     MaxElecTkIso     =   3., 
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)



###LOOSE ISOLATION
singleElectronIsoLoose20 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   20.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)


singleElectronNjet20 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   20.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   1,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =   3,
  
  ##EVENT
  MinHt            =  100.0,
  MaxHt            = 350.,
  MinMht           =   0.0,
  MaxMht           =  50000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   0.5,
  MinSecondLeptonPt=   10.
)




singleElectron30 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   30.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   0.1,
    MaxElecTkIso     =   3.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)



###LOOSE ISOLATION
singleElectronIsoLoose30 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   30.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
   MaxElecTkIso     =   300.,   
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   4,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =  20,
  
  ##EVENT
  MinHt            = 350.0,
  MaxHt            = 20000.,
  MinMht           =  50.0,
  MaxMht           = 20000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   3.5,
  MinSecondLeptonPt=   10.
)


singleElectronNjet30 = PSet(

  ##ELECTRON  
  MinNElecs        =   1,
  MaxNElecs        =   1,
  MinElecEt        =   30.0,
  MaxElecAbsEta    =   2.5,
  MinCorrD0        =   0.,
  MaxCorrD0        =   0.2,
  MaxElecRelIso    =   10.,
    MaxElecTkIso     =   300.,  
  InvertedId       =  False ,
  ##MUON
  MinNMuons        =   0,
  MaxNMuons        =   0,
  MinMuonPt        =  20.0,
  MinNHits         =  11,
  MaxMuonAbsEta    =   2.1,
  MaxMuonRelIso    =   0.05,
  MaxNormChi2      =  10.0,
  
  ##JET
  MinNJets         =   1,
  MinJetPt         =  30.0,
  MaxJetAbsEta     =   2.4, 
  MinJetElecDeltaR =   0.3,
  MaxNJets         =   3,
  
  ##EVENT
  MinHt            =  100.0,
  MaxHt            = 350.,
  MinMht           =   0.0,
  MaxMht           =  50000.,
  ApplyVeto        = True,
  MinDeltaPhi      =  -0.1,
  MaxDeltaPhi      =   0.5,
  MinSecondLeptonPt=   10.
)



# Add the tree to our analysis
a += tree



##EL Pt >2 GeV
SingleElectron2 = QCDSelector("singleElectron2", singleElectron2.ps())
SingleElectronIsoLoose2 = QCDSelector("singleElectronIsoLoose2", singleElectronIsoLoose2.ps())
SingleElectronNjet2 = QCDSelector("singleElectronNjet2", singleElectronNjet2.ps())

tree.Attach(SingleElectron2)
tree.Attach(SingleElectronIsoLoose2)
tree.Attach(SingleElectronNjet2)

##EL Pt >5 GeV
SingleElectron5 = QCDSelector("singleElectron5", singleElectron5.ps())
SingleElectronIsoLoose5 = QCDSelector("singleElectronIsoLoose5", singleElectronIsoLoose5.ps())
SingleElectronNjet5 = QCDSelector("singleElectronNjet5", singleElectronNjet5.ps())

tree.Attach(SingleElectron5)
tree.Attach(SingleElectronIsoLoose5)
tree.Attach(SingleElectronNjet5)

##EL Pt >10 GeV
SingleElectron10 = QCDSelector("singleElectron10", singleElectron10.ps())
SingleElectronIsoLoose10 = QCDSelector("singleElectronIsoLoose10", singleElectronIsoLoose10.ps())
SingleElectronNjet10 = QCDSelector("singleElectronNjet10", singleElectronNjet10.ps())

tree.Attach(SingleElectron10)
tree.Attach(SingleElectronIsoLoose10)
tree.Attach(SingleElectronNjet10)

##EL Pt >15 GeV
SingleElectron15 = QCDSelector("singleElectron15", singleElectron15.ps())
SingleElectronIsoLoose15 = QCDSelector("singleElectronIsoLoose15", singleElectronIsoLoose15.ps())
SingleElectronNjet15 = QCDSelector("singleElectronNjet15", singleElectronNjet15.ps())

tree.Attach(SingleElectron15)
tree.Attach(SingleElectronIsoLoose15)
tree.Attach(SingleElectronNjet15)


##EL Pt >20 GeV
SingleElectron20 = QCDSelector("singleElectron20", singleElectron20.ps())
SingleElectronIsoLoose20 = QCDSelector("singleElectronIsoLoose20", singleElectronIsoLoose20.ps())
SingleElectronNjet20 = QCDSelector("singleElectronNjet20", singleElectronNjet20.ps())

tree.Attach(SingleElectron20)
tree.Attach(SingleElectronIsoLoose20)
tree.Attach(SingleElectronNjet20)

##EL Pt >30 GeV
SingleElectron30 = QCDSelector("singleElectron30", singleElectron30.ps())
SingleElectronIsoLoose30 = QCDSelector("singleElectronIsoLoose30", singleElectronIsoLoose30.ps())
SingleElectronNjet30 = QCDSelector("singleElectronNjet30", singleElectronNjet30.ps())

tree.Attach(SingleElectron30)
tree.Attach(SingleElectronIsoLoose30)
tree.Attach(SingleElectronNjet30)


s = [lm0,qcd100To250,qcd250To500,qcd500To1000,qcd1000ToInf,ttJets,wJets,zJets]
a.Run(".", conf, s)
