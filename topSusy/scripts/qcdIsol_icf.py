#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *

from libTopSusy       import *
from libSSDL import *
from icf.core import PSet, Analysis
from icf.config import defaultConfig
conf = defaultConfig

import samples.icf2 as icf
from icf.utils import local_ntuple


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

TriggerCon=PSet(
       McAnal =0.,
       TriggerBits=PSet(
         bit1="HLT_Jet30",
         bit2=""
        )
    )

Trigger=PSet(
       McAnal =0.,
       TriggerBits=PSet(
         bit1="HLT_DiJetAve70U",
         bit2=""
        )
    )

ssdlTrigCon=SSDLTrigger("TriggerCon",TriggerCon.ps())
ssdlTrig=SSDLTrigger("Trigger",Trigger.ps())
tree.Attach(ssdlTrig)
tree.Attach(ssdlTrigCon)


##EL Pt >2 GeV
SingleElectron2 = QCDSelector("singleElectron2", singleElectron2.ps())
SingleElectronIsoLoose2 = QCDSelector("singleElectronIsoLoose2", singleElectronIsoLoose2.ps())
SingleElectronNjet2 = QCDSelector("singleElectronNjet2", singleElectronNjet2.ps())

tree.TAttach(ssdlTrig,SingleElectron2)
tree.TAttach(ssdlTrig,SingleElectronIsoLoose2)
tree.TAttach(ssdlTrigCon,SingleElectronNjet2)

##EL Pt >5 GeV
SingleElectron5 = QCDSelector("singleElectron5", singleElectron5.ps())
SingleElectronIsoLoose5 = QCDSelector("singleElectronIsoLoose5", singleElectronIsoLoose5.ps())
SingleElectronNjet5 = QCDSelector("singleElectronNjet5", singleElectronNjet5.ps())

tree.TAttach(ssdlTrig,SingleElectron5)
tree.TAttach(ssdlTrig,SingleElectronIsoLoose5)
tree.TAttach(ssdlTrigCon,SingleElectronNjet5)

##EL Pt >10 GeV
SingleElectron10 = QCDSelector("singleElectron10", singleElectron10.ps())
SingleElectronIsoLoose10 = QCDSelector("singleElectronIsoLoose10", singleElectronIsoLoose10.ps())
SingleElectronNjet10 = QCDSelector("singleElectronNjet10", singleElectronNjet10.ps())

tree.TAttach(ssdlTrig,SingleElectron10)
tree.TAttach(ssdlTrig,SingleElectronIsoLoose10)
tree.TAttach(ssdlTrigCon,SingleElectronNjet10)

##EL Pt >15 GeV
SingleElectron15 = QCDSelector("singleElectron15", singleElectron15.ps())
SingleElectronIsoLoose15 = QCDSelector("singleElectronIsoLoose15", singleElectronIsoLoose15.ps())
SingleElectronNjet15 = QCDSelector("singleElectronNjet15", singleElectronNjet15.ps())

tree.TAttach(ssdlTrig,SingleElectron15)
tree.TAttach(ssdlTrig,SingleElectronIsoLoose15)
tree.TAttach(ssdlTrigCon,SingleElectronNjet15)


##EL Pt >20 GeV
SingleElectron20 = QCDSelector("singleElectron20", singleElectron20.ps())
SingleElectronIsoLoose20 = QCDSelector("singleElectronIsoLoose20", singleElectronIsoLoose20.ps())
SingleElectronNjet20 = QCDSelector("singleElectronNjet20", singleElectronNjet20.ps())

tree.TAttach(ssdlTrig,SingleElectron20)
tree.TAttach(ssdlTrig,SingleElectronIsoLoose20)
tree.TAttach(ssdlTrigCon,SingleElectronNjet20)

##EL Pt >30 GeV
SingleElectron30 = QCDSelector("singleElectron30", singleElectron30.ps())
SingleElectronIsoLoose30 = QCDSelector("singleElectronIsoLoose30", singleElectronIsoLoose30.ps())
SingleElectronNjet30 = QCDSelector("singleElectronNjet30", singleElectronNjet30.ps())

tree.TAttach(ssdlTrig,SingleElectron30)
tree.TAttach(ssdlTrig,SingleElectronIsoLoose30)
tree.TAttach(ssdlTrigCon,SingleElectronNjet30)



samples=[
    icf.QCD_EMenriched_20to30,
    icf.QCD_EMenriched_30to80,
    icf.QCD_EMenriched_80to170,
    icf.QCD_BCtoE_20to30,
    icf.QCD_BCtoE_30to80,
    icf.QCD_BCtoE_80to170,
    icf.TTjets,
    icf.Wjets,
    icf.Zjets,
    icf.qcd_pt170,
    icf.qcd_pt300,
    icf.qcd_pt470,
    icf.qcd_pt800,
    icf.qcd_pt1400,
]





a.Run(".", conf, samples)
