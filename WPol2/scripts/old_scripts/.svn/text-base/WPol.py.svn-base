#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libWPol import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig

# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 20 GeV

conf.Common.Jets.EtCut=20.0
conf.Common.Jets.EtaCut=5.0
conf.Common.Jets.EMFracCut=0.95
conf.Common.Muons.EtaCut=2.1
conf.Common.Muons.PtCut=20.0
conf.Common.Muons.TrkIsoCut=-1.0 #i.e. we are ignoring it
conf.Common.Muons.CombIsoCut=0.1
conf.Common.Electrons.PtCut=15.0
conf.Common.Electrons.EtaCut=3.0
conf.Common.Electrons.TrkIsoCut=1.0
conf.Common.Photons.EtCut=25.0
conf.Common.Photons.IDReq=3
conf.Common.ApplyXCleaning=True

# -----------------------------------------------------------------------------
# Cross-cleaning settings

conf.XCleaning.Verbose=False
conf.XCleaning.MuonJet=True
conf.XCleaning.ElectronJet=False
conf.XCleaning.PhotonJet=False
conf.XCleaning.ResolveConflicts=False
#conf.XCleaning.Jets.EtCut=0.
#conf.XCleaning.Jets.EtaCut=1000.0
#conf.XCleaning.Muons.PtCut=0.
#conf.XCleaning.Muons.EtaCut=1000.
#conf.XCleaning.Muons.TrkIsoCut=-1.
#conf.XCleaning.Muons.CombIsoCut=6.
#conf.XCleaning.Electrons.PtCut=0.0
#conf.XCleaning.Electrons.EtaCut=1000.0
#conf.XCleaning.Electrons.TrkIsoCut=6.0
#conf.XCleaning.Electrons.CombIsoCut=0.2
#conf.XCleaning.Photons.EtCut=0.0
#conf.XCleaning.Photons.EtaCut=1000.0
#conf.XCleaning.Photons.TrkIsoCut=9.
#conf.XCleaning.Photons.AllIsoCut=0.2
#conf.XCleaning.Photons.IDReq=2

# Here we define a sample to use
# The path and the filename are separate so you can easily move to using
# local samples.
wjets=PSet(
	Name="WJets_madgraph",
        File="/home/mstoye/ntupleData/ICF/W/WJets-madgraph_ICFv2.root",
        CrossSection=2417.0, #normalised to 10 pb^-1 (7TeV)
        Format=("ICF",2),
        FirstEntry=1,
        LastEntry=0 #use 10 events for test of CS frame stuff
)

zjets=PSet(
	Name="ZJets_madgraph",
        File="/home/mstoye/ntupleData/ICF/Z/ZJets-madgraph_ICFv2.root",
        CrossSection=240., #normalised to 10 pb^-1 (7TeV)
        Format=("ICF",2),
        FirstEntry=1,
        LastEntry=0 #use 10 events for test of CS frame stuff
)






# Create the analysis
a=Analysis("GenW")
b=Analysis("RecoW")
c=Analysis("Print")
d=Analysis("CSFrame")
e=Analysis("Reweight")
f=Analysis("GenW_CS")
g=Analysis("Reweight_CS")

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")
treeb = Tree("Mainb")
treec = Tree("Mainc")
treed = Tree("Maind")
treee = Tree("Maine")
treef = Tree("Mainf")
treeg = Tree("Maing")
# Initialise our operations

# for debug info
PrintDebug = Print_DebugInfo("")

#this is for the generator level plots
CheckForW = MC_GenWExists()
CheckForWMuon = MC_GenWMuonExists()
CheckForWLepton = MC_GenWLeptonExists()
WPTCut = MC_GenWPTCut(100.0)
WPTCut50to75 = MC_GenWPTCut2(50.0, 75.0)
WPTCut75to100 = MC_GenWPTCut2(75.0, 100.0)
WPTCut0to50 = MC_GenWPTCut2(0.0,50.0)
WPTCut50to100 = MC_GenWPTCut2(50.0,100.0)
WPTCut0to100 = MC_GenWPTCut2(0.0,100.0)
WPTCut100to200 = MC_GenWPTCut2(100.0,200.0)
WPTCut90toinf = MC_GenWPTCut(90.0)
WPTCut100toinf = MC_GenWPTCut(100.0)
WPTCut200toinf = MC_GenWPTCut(200.0)
WYCut0to225 = MC_GenWYCut(0.0,2.25)
WY0Cutbin0 = MC_GenWYCut(0.0,0.5)
WY0Cutbin1 = MC_GenWYCut(0.5,1.0)
WY0Cutbin2 = MC_GenWYCut(1.0,1.5)
WY0Cutbin3 = MC_GenWYCut(1.5,2.0)
WY0Cutbin4 = MC_GenWYCut(2.0,2.5)
WY0Cutbin5 = MC_GenWYCut(2.5,3.0)
WY0Cutbin6 = MC_GenWYCut(3.0,15.0)
WY1Cutbin0 = MC_GenWYCut(0.0,0.5)
WY1Cutbin1 = MC_GenWYCut(0.5,1.0)
WY1Cutbin2 = MC_GenWYCut(1.0,1.5)
WY1Cutbin3 = MC_GenWYCut(1.5,2.0)
WY1Cutbin4 = MC_GenWYCut(2.0,2.5)
WY1Cutbin5 = MC_GenWYCut(2.5,3.0)
WY1Cutbin6 = MC_GenWYCut(3.0,15.0)
WY2Cutbin0 = MC_GenWYCut(0.0,0.5)
WY2Cutbin1 = MC_GenWYCut(0.5,1.0)
WY2Cutbin2 = MC_GenWYCut(1.0,1.5)
WY2Cutbin3 = MC_GenWYCut(1.5,2.0)
WY2Cutbin4 = MC_GenWYCut(2.0,2.5)
WY2Cutbin5 = MC_GenWYCut(2.5,3.0)
WY2Cutbin6 = MC_GenWYCut(3.0,15.0)

PlotWStuff0to100 = MC_WPlots("MC_WPlots_0to100","W")
PlotWStuff100to200 = MC_WPlots("MC_WPlots_100to200","W")
PlotWStuff200toinf = MC_WPlots("MC_WPlots_200toinf","W")
PlotWStuff0toinf = MC_WPlots("MC_WPlots_0toinf","W")
PlotWStuff50to75 = MC_WPlots("MC_WPlots_50to75","W")
PlotWStuff75to100 = MC_WPlots("MC_WPlots_75to100","W")
PlotWStuff100toinf = MC_WPlots("MC_WPlots_100toinf","W")
PlotWStuff90toinfY225 = MC_WPlots("MC_WPlots_90toinf_Y225","W")

#by PxYy we mean Pt bin x and Y bin y
PlotWStuffP0Y0 = MC_WPlots("MC_WPlots_P0Y0","W")
PlotWStuffP0Y1 = MC_WPlots("MC_WPlots_P0Y1","W")
PlotWStuffP0Y2 = MC_WPlots("MC_WPlots_P0Y2","W")
PlotWStuffP0Y3 = MC_WPlots("MC_WPlots_P0Y3","W")
PlotWStuffP0Y4 = MC_WPlots("MC_WPlots_P0Y4","W")
PlotWStuffP0Y5 = MC_WPlots("MC_WPlots_P0Y5","W")
PlotWStuffP0Y6 = MC_WPlots("MC_WPlots_P0Y6","W")

PlotWStuffP1Y0 = MC_WPlots("MC_WPlots_P1Y0","W")
PlotWStuffP1Y1 = MC_WPlots("MC_WPlots_P1Y1","W")
PlotWStuffP1Y2 = MC_WPlots("MC_WPlots_P1Y2","W")
PlotWStuffP1Y3 = MC_WPlots("MC_WPlots_P1Y3","W")
PlotWStuffP1Y4 = MC_WPlots("MC_WPlots_P1Y4","W")
PlotWStuffP1Y5 = MC_WPlots("MC_WPlots_P1Y5","W")
PlotWStuffP1Y6 = MC_WPlots("MC_WPlots_P1Y6","W")

PlotWStuffP2Y0 = MC_WPlots("MC_WPlots_P2Y0","W")
PlotWStuffP2Y1 = MC_WPlots("MC_WPlots_P2Y1","W")
PlotWStuffP2Y2 = MC_WPlots("MC_WPlots_P2Y2","W")
PlotWStuffP2Y3 = MC_WPlots("MC_WPlots_P2Y3","W")
PlotWStuffP2Y4 = MC_WPlots("MC_WPlots_P2Y4","W")
PlotWStuffP2Y5 = MC_WPlots("MC_WPlots_P2Y5","W")
PlotWStuffP2Y6 = MC_WPlots("MC_WPlots_P2Y6","W")

#by PxYy we mean Pt bin x and Y bin y
#setup for the CS frame stuff
PlotCSWStuffP0Y0 = MC_CSFramePlots("MC_CSFramePlots_P0Y0","W")
PlotCSWStuffP0Y1 = MC_CSFramePlots("MC_CSFramePlots_P0Y1","W")
PlotCSWStuffP0Y2 = MC_CSFramePlots("MC_CSFramePlots_P0Y2","W")
PlotCSWStuffP0Y3 = MC_CSFramePlots("MC_CSFramePlots_P0Y3","W")
PlotCSWStuffP0Y4 = MC_CSFramePlots("MC_CSFramePlots_P0Y4","W")
PlotCSWStuffP0Y5 = MC_CSFramePlots("MC_CSFramePlots_P0Y5","W")
PlotCSWStuffP0Y6 = MC_CSFramePlots("MC_CSFramePlots_P0Y6","W")

PlotCSWStuffP1Y0 = MC_CSFramePlots("MC_CSFramePlots_P1Y0","W")
PlotCSWStuffP1Y1 = MC_CSFramePlots("MC_CSFramePlots_P1Y1","W")
PlotCSWStuffP1Y2 = MC_CSFramePlots("MC_CSFramePlots_P1Y2","W")
PlotCSWStuffP1Y3 = MC_CSFramePlots("MC_CSFramePlots_P1Y3","W")
PlotCSWStuffP1Y4 = MC_CSFramePlots("MC_CSFramePlots_P1Y4","W")
PlotCSWStuffP1Y5 = MC_CSFramePlots("MC_CSFramePlots_P1Y5","W")
PlotCSWStuffP1Y6 = MC_CSFramePlots("MC_CSFramePlots_P1Y6","W")

PlotCSWStuffP2Y0 = MC_CSFramePlots("MC_CSFramePlots_P2Y0","W")
PlotCSWStuffP2Y1 = MC_CSFramePlots("MC_CSFramePlots_P2Y1","W")
PlotCSWStuffP2Y2 = MC_CSFramePlots("MC_CSFramePlots_P2Y2","W")
PlotCSWStuffP2Y3 = MC_CSFramePlots("MC_CSFramePlots_P2Y3","W")
PlotCSWStuffP2Y4 = MC_CSFramePlots("MC_CSFramePlots_P2Y4","W")
PlotCSWStuffP2Y5 = MC_CSFramePlots("MC_CSFramePlots_P2Y5","W")
PlotCSWStuffP2Y6 = MC_CSFramePlots("MC_CSFramePlots_P2Y6","W")

PlotCSFrame = MC_CSFramePlots("MC_CSFramePlots","W")
WPTCut15to25 = MC_GenWPTCut2(15.0,25.0)
PlotCSFrame15to25 = MC_CSFramePlots("MC_CSFramePlots_15to25","W")
WPTCut25to35 = MC_GenWPTCut2(25.0,35.0)
PlotCSFrame25to35 = MC_CSFramePlots("MC_CSFramePlots_25to35","W")
WPTCut35to65 = MC_GenWPTCut2(35.0,65.0)
PlotCSFrame35to65 = MC_CSFramePlots("MC_CSFramePlots_35to65","W")
WPTCut65to105 = MC_GenWPTCut2(65.0,105.0)
PlotCSFrame65to105 = MC_CSFramePlots("MC_CSFramePlots_65to105","W")
PlotCSFrame50to75 = MC_CSFramePlots("MC_CSFramePlots_50to75","W")
PlotCSFrame75to100 = MC_CSFramePlots("MC_CSFramePlots_75to100","W")
PlotCSFrame100toinf = MC_CSFramePlots("MC_CSFramePlots_100toinf","W")
PlotCSFrame0toinf = MC_CSFramePlots("MC_CSFramePlots_0toinf","W")
PlotCSFrameRECO50to75 = RECO_CSFramePlots("RECO_CSFramePlots_50to75","W",True)
PlotCSFrameRECO75to100 = RECO_CSFramePlots("RECO_CSFramePlots_75to100","W",True)
PlotCSFrameRECO100toinf = RECO_CSFramePlots("RECO_CSFramePlots_100toinf","W",True)

#this is for the reconstruction level plots
#Trigger Cut
#TrigCut = OP_TriggerCut(10)
# Lep comp.
NumLeptons = OP_NumComLeptons("==", 1)
# Mu comp.
NumMuons = OP_NumComMuons("==", 1)
# Photon comp.
NumPh = OP_NumComPhotons("==", 0)
# Good Jets Cut
NumGoodJets = OP_NumComJets("<", 4)
# Odd cuts
OddEli = OP_OddElectron()
OddMui = OP_OddMuon()
OddJeti = OP_OddJet()
OddPhoti = OP_OddPhoton()
# Bad muon in jet
BadMui = OP_BadMuonInJet()
# Photon killed jet
aPhotkilledJet = OP_PhotonKilledJet()
# Minimum DeltaR(Muon,Jet) cut
minDRMuonJetCut = RECO_MuonJetDRCut(0.5)

# CommonMHT Cut

CommMHTCut = RECO_CommonMHTCut(200.)
CommMHTCut100 = RECO_CommonMHTCut(100.)
CommMHTCut80 = RECO_CommonMHTCut(80.)
CommMHTCut75 = RECO_CommonMHTCut(75.)
CommMHTCut50 = RECO_CommonMHTCut(50.)

# PlotRECOPol stuff NoHTCut
# PlotRecoPolStuffnoHtCut = RECO_PolPlots("RECO_PolPlotsNoHtCut")
# PlotRecoPolStuffnoMHtCut = RECO_PolPlots("RECO_PolPlotsNoMHtCut")
# CommonHT Cut
# CommHTCut = RECO_CommonHTCut(350.)
# PlotRECOPol stuff
# PlotRecoPolStuff = RECO_PolPlots("RECO_PolPlots")

ZmassCut = RECO_2ndMuonMass(25.0)
CommMHTCut50to75 = RECO_CommonMHTCut2(50.0,75.0)
CommMHTCut75to100 = RECO_CommonMHTCut2(75.0,100.0)
Plot50to75 = RECO_PolPlots("RECO_PolPlots_50to75")
Plot75to100 = RECO_PolPlots("RECO_PolPlots_75to100")
Plot100toinf = RECO_PolPlots("RECO_PolPlots_100toinf")
Plot50toinf = RECO_PolPlots("RECO_PolPlots_50toinf")
Plot75toinf = RECO_PolPlots("RECO_PolPlots_75toinf")

#this is for print/debug info
PrintMCParticleInfo = MC_PrintGenParticleInfo("FULL")

#for the Z-boson analysis
CheckForZ = MC_GenZExists()

# Add the tree to our analysis
# *Markus*
#not sure what this is for, I guess the polarization plots a la AN Note 09/174
# ********
a+=tree
tree.Attach(CheckForW)
#tree.TAttach(CheckForW, CheckForWLepton)
tree.TAttach(CheckForW, CheckForWMuon)
#tree.TAttach(CheckForWLepton, WPTCut100toinf)
tree.TAttach(CheckForWMuon, WPTCut100toinf)
tree.TAttach(WPTCut100toinf, PlotWStuff100toinf)



# mixture of MC and reco cuts? Not sure what it is used for 
b+=treeb
treeb.Attach(CheckForW)
treeb.TAttach(CheckForW, NumLeptons)
# commentedout MC cut CheckForW
#treeb.Attach(NumLeptons)
treeb.TAttach(NumLeptons, NumMuons)
treeb.TAttach(NumMuons, NumPh)
treeb.TAttach(NumPh, NumGoodJets)
treeb.TAttach(NumGoodJets, OddJeti)
treeb.TAttach(OddJeti, CommMHTCut50to75)
treeb.TAttach(CommMHTCut50to75, PlotCSFrameRECO50to75)
treeb.TAttach(OddJeti, CommMHTCut75to100)
treeb.TAttach(CommMHTCut75to100, PlotCSFrameRECO75to100)
treeb.TAttach(OddJeti, CommMHTCut100)
treeb.TAttach(CommMHTCut100, PlotCSFrameRECO100toinf)


# some Debug analysis 
c+=treec
treec.Attach(PrintMCParticleInfo)
#treec.Attach(PrintDebug)


# ??? some test plots of CS ???
d+=treed
#treed.Attach(CheckForZ)
treed.Attach(CheckForW)
treed.TAttach(CheckForW, PlotCSFrame0toinf)



#Presumable needed for template production (guessed Markus)

e+=treee
treee.Attach(CheckForW)
treee.TAttach(CheckForW, CheckForWLepton)
treee.TAttach(CheckForWLepton, WPTCut0to50)
treee.TAttach(WPTCut0to50, WY0Cutbin0)
treee.TAttach(WY0Cutbin0, PlotWStuffP0Y0)
treee.TAttach(WPTCut0to50, WY0Cutbin1)
treee.TAttach(WY0Cutbin1, PlotWStuffP0Y1)
treee.TAttach(WPTCut0to50, WY0Cutbin2)
treee.TAttach(WY0Cutbin2, PlotWStuffP0Y2)
treee.TAttach(WPTCut0to50, WY0Cutbin3)
treee.TAttach(WY0Cutbin3, PlotWStuffP0Y3)
treee.TAttach(WPTCut0to50, WY0Cutbin4)
treee.TAttach(WY0Cutbin4, PlotWStuffP0Y4)
treee.TAttach(WPTCut0to50, WY0Cutbin5)
treee.TAttach(WY0Cutbin5, PlotWStuffP0Y5)
treee.TAttach(WPTCut0to50, WY0Cutbin6)
treee.TAttach(WY0Cutbin6, PlotWStuffP0Y6)
treee.TAttach(CheckForWLepton, WPTCut50to100)
treee.TAttach(WPTCut50to100, WY1Cutbin0)
treee.TAttach(WY1Cutbin0, PlotWStuffP1Y0)
treee.TAttach(WPTCut50to100, WY1Cutbin1)
treee.TAttach(WY1Cutbin1, PlotWStuffP1Y1)
treee.TAttach(WPTCut50to100, WY1Cutbin2)
treee.TAttach(WY1Cutbin2, PlotWStuffP1Y2)
treee.TAttach(WPTCut50to100, WY1Cutbin3)
treee.TAttach(WY1Cutbin3, PlotWStuffP1Y3)
treee.TAttach(WPTCut50to100, WY1Cutbin4)
treee.TAttach(WY1Cutbin4, PlotWStuffP1Y4)
treee.TAttach(WPTCut50to100, WY1Cutbin5)
treee.TAttach(WY1Cutbin5, PlotWStuffP1Y5)
treee.TAttach(WPTCut50to100, WY1Cutbin6)
treee.TAttach(WY1Cutbin6, PlotWStuffP1Y6)

treee.TAttach(CheckForWLepton, WPTCut100toinf)
treee.TAttach(WPTCut100toinf, WY2Cutbin0)
treee.TAttach(WY2Cutbin0, PlotWStuffP2Y0)
treee.TAttach(WPTCut100toinf, WY2Cutbin1)
treee.TAttach(WY2Cutbin1, PlotWStuffP2Y1)
treee.TAttach(WPTCut100toinf, WY2Cutbin2)
treee.TAttach(WY2Cutbin2, PlotWStuffP2Y2)
treee.TAttach(WPTCut100toinf, WY2Cutbin3)
treee.TAttach(WY2Cutbin3, PlotWStuffP2Y3)
treee.TAttach(WPTCut100toinf, WY2Cutbin4)
treee.TAttach(WY2Cutbin4, PlotWStuffP2Y4)
treee.TAttach(WPTCut100toinf, WY2Cutbin5)
treee.TAttach(WY2Cutbin5, PlotWStuffP2Y5)
treee.TAttach(WPTCut100toinf, WY2Cutbin6)
treee.TAttach(WY2Cutbin6, PlotWStuffP2Y6)

g+=treeg
treeg.Attach(CheckForW)
treeg.TAttach(CheckForW, CheckForWLepton)
#treeg.Attach(CheckForW)

#treeg.TAttach(CheckForWLepton, WPTCut0to50)
treeg.TAttach(CheckForWLepton, WPTCut0to50)
treeg.TAttach(WPTCut0to50, WY0Cutbin0)
treeg.TAttach(WY0Cutbin0, PlotCSWStuffP0Y0)
treeg.TAttach(WPTCut0to50, WY0Cutbin1)
treeg.TAttach(WY0Cutbin1, PlotCSWStuffP0Y1)
treeg.TAttach(WPTCut0to50, WY0Cutbin2)
treeg.TAttach(WY0Cutbin2, PlotCSWStuffP0Y2)
treeg.TAttach(WPTCut0to50, WY0Cutbin3)
treeg.TAttach(WY0Cutbin3, PlotCSWStuffP0Y3)
treeg.TAttach(WPTCut0to50, WY0Cutbin4)
treeg.TAttach(WY0Cutbin4, PlotCSWStuffP0Y4)
treeg.TAttach(WPTCut0to50, WY0Cutbin5)
treeg.TAttach(WY0Cutbin5, PlotCSWStuffP0Y5)
treeg.TAttach(WPTCut0to50, WY0Cutbin6)
treeg.TAttach(WY0Cutbin6, PlotCSWStuffP0Y6)

#treeg.TAttach(CheckForWLepton, WPTCut50to100)
treeg.TAttach(CheckForWLepton, WPTCut50to100)
treeg.TAttach(WPTCut50to100, WY1Cutbin0)
treeg.TAttach(WY1Cutbin0, PlotCSWStuffP1Y0)
treeg.TAttach(WPTCut50to100, WY1Cutbin1)
treeg.TAttach(WY1Cutbin1, PlotCSWStuffP1Y1)
treeg.TAttach(WPTCut50to100, WY1Cutbin2)
treeg.TAttach(WY1Cutbin2, PlotCSWStuffP1Y2)
treeg.TAttach(WPTCut50to100, WY1Cutbin3)
treeg.TAttach(WY1Cutbin3, PlotCSWStuffP1Y3)
treeg.TAttach(WPTCut50to100, WY1Cutbin4)
treeg.TAttach(WY1Cutbin4, PlotCSWStuffP1Y4)
treeg.TAttach(WPTCut50to100, WY1Cutbin5)
treeg.TAttach(WY1Cutbin5, PlotCSWStuffP1Y5)
treeg.TAttach(WPTCut50to100, WY1Cutbin6)
treeg.TAttach(WY1Cutbin6, PlotCSWStuffP1Y6)

#treeg.TAttach(CheckForWLepton, WPTCut100toinf)
treeg.TAttach(CheckForWLepton, WPTCut100toinf)
treeg.TAttach(WPTCut100toinf, WY2Cutbin0)
treeg.TAttach(WY2Cutbin0, PlotCSWStuffP2Y0)
treeg.TAttach(WPTCut100toinf, WY2Cutbin1)
treeg.TAttach(WY2Cutbin1, PlotCSWStuffP2Y1)
treeg.TAttach(WPTCut100toinf, WY2Cutbin2)
treeg.TAttach(WY2Cutbin2, PlotCSWStuffP2Y2)
treeg.TAttach(WPTCut100toinf, WY2Cutbin3)
treeg.TAttach(WY2Cutbin3, PlotCSWStuffP2Y3)
treeg.TAttach(WPTCut100toinf, WY2Cutbin4)
treeg.TAttach(WY2Cutbin4, PlotCSWStuffP2Y4)
treeg.TAttach(WPTCut100toinf, WY2Cutbin5)
treeg.TAttach(WY2Cutbin5, PlotCSWStuffP2Y5)
treeg.TAttach(WPTCut100toinf, WY2Cutbin6)
treeg.TAttach(WY2Cutbin6, PlotCSWStuffP2Y6)

# Presumably to make genLevel plots of CS stuff in WPT bins
f+=treef
treef.Attach(CheckForW)
#treef.TAttach(CheckForW, CheckForWLepton)
#treef.Attach(CheckForZ)
#treef.TAttach(CheckForWLepton, WPTCut50to75)
treef.TAttach(CheckForW,WPTCut50to75)
#treef.TAttach(WPTCut50to75, PlotWStuff50to75)
treef.TAttach(WPTCut50to75, PlotCSFrame50to75)
treef.TAttach(CheckForW,WPTCut75to100)
treef.TAttach(WPTCut75to100, PlotCSFrame75to100)
treef.TAttach(CheckForW,WPTCut100toinf)
treef.TAttach(WPTCut100toinf, PlotWStuff100toinf)
#treef.TAttach(WPTCut100toinf, PlotCSFrame100toinf)

# Define the list of samples to run over
w=[wjets]
z=[zjets]
#a.Run("results",conf,r)
b.Run("results",conf,w)
#c.Run("results",conf,r)
#d.Run("results",conf,r)
#e.Run("results",conf,w)
#f.Run("results",conf,r)
#g.Run("results",conf,r)
