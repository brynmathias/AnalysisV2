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
conf.Common.Muons.PtCut=0.0 #SET THIS 20.0
conf.Common.Muons.TrkIsoCut=-1.0 #i.e. we are ignoring it
conf.Common.Muons.CombIsoCut=0.1
conf.Common.Electrons.PtCut=15.0 #SET THIS 15.0
conf.Common.Electrons.EtaCut=3.0
conf.Common.Electrons.TrkIsoCut=1.0
conf.Common.Photons.EtCut=25.0
conf.Common.Photons.IDReq=3
conf.Common.ApplyXCleaning=True

# -----------------------------------------------------------------------------
# Cross-cleaning settings

conf.XCleaning.Verbose=False
conf.XCleaning.MuonJet=True
conf.XCleaning.ElectronJet=True
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
realdata=PSet(
        Name="realdatatest",
        File="~/jaddisk2/realdata_minbias_goodcollv9_16.root",
        Weight=1.0,
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0 #use 10 events for test of CS frame stuff
)

wjets=PSet(
	Name="WJets-lite_madgraph_50_70_90_inf_1pb-1_mu20_21",
        File="~/jaddisk3/ICFv2-lite/WJets_madgraph_lite.root",
        CrossSection=241.70, #normalised to 10 pb^-1 (7TeV) = 2417.0
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0 #use 10 events for test of CS frame stuff
)

zjets=PSet(
	Name="ZJets-lite_madgraph_50_70_90_inf_1pb-1_mu20_21_WSelection",
        File="~/jaddisk3/ICFv2-lite/ZJets_madgraph_lite.root",
        CrossSection=24.0, #normalised to 10 pb^-1 (7TeV) = 240.0
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0 #use 10 events for test of CS frame stuff
)

wmupythia=PSet(
        Name="WmuJets-lite_pythia_test",
        File="~/jaddisk2/Wmunu_pythia_lite.root",
        CrossSection=2417.0, #normalised to 10 pb^-1 (7TeV) = 2417.0
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0 #use 10 events for test of CS frame stuff
)

qcdjets=PSet(
        Name="QCDJets_Pythia80_50_75_100_WSelection",
        File="~/jaddisk3/SUSYICFv2Ntuples/QCDJets_Pythia_80.root",
        CrossSection=92380.0,
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0
)

qcdmu3050=PSet(
	Name="QCDMu-lite_Pythia30to50_50_70_90_inf_1pb-1_mu20_21_WSelection",
	File="~/jaddisk2/QCD_pythia_30to50mu_lite.root",
	CrossSection=6543.6, #normalised to 1pb-1 = 532000 * 0.0123
	Format=("ICF",2),
	FirstEntry=0,
	LastEntry=0 #total events = 6881160
)

qcdmu5080=PSet(
        Name="QCDMu-lite_Pythia50to80_50_70_90_inf_1pb-1_mu20_21_WSelection",
        File="~/jaddisk2/QCD_pythia_50to80mu_lite.root",
        CrossSection=1388.46, #normalised to 1pb-1 = 63400 * 0.0219
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0 #total events = 2307049
)

qcdmu80120=PSet(
        Name="QCDMu-lite_Pythia80to120_50_70_90_inf_1pb-1_mu20_21_WSelection",
        File="~/jaddisk2/QCD_pythia_80to120mu_lite.root",
        CrossSection=290.45, #normalised to 1pb-1 = 7850 * 0.037
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0 #total events = 516248
)

qcdmu120170=PSet(
        Name="QCDMu-lite_Pythia120to170_50_70_90_inf_1pb-1_mu20_21_WSelection",
        File="~/jaddisk2/QCD_pythia_120to170mu_lite.root",
        CrossSection=60.95, #normalised to 1pb-1 = 1150 * 0.053
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0
)

qcdmu170Inf=PSet(
        Name="QCDMu-lite_Pythia170toInf_50_70_90_inf_1pb-1_mu20_21_WSelection",
        File="~/jaddisk2/QCD_pythia_170toInfmu_lite.root",
        CrossSection=16.12, #normalised to 1pb-1 = 256 * 0.063
        Format=("ICF",2),
        FirstEntry=0,
        LastEntry=0
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
WY0Cutbin6 = MC_GenWYCut2(3.0)
WY1Cutbin0 = MC_GenWYCut(0.0,0.5)
WY1Cutbin1 = MC_GenWYCut(0.5,1.0)
WY1Cutbin2 = MC_GenWYCut(1.0,1.5)
WY1Cutbin3 = MC_GenWYCut(1.5,2.0)
WY1Cutbin4 = MC_GenWYCut(2.0,2.5)
WY1Cutbin5 = MC_GenWYCut(2.5,3.0)
WY1Cutbin6 = MC_GenWYCut2(3.0)
WY2Cutbin0 = MC_GenWYCut(0.0,0.5)
WY2Cutbin1 = MC_GenWYCut(0.5,1.0)
WY2Cutbin2 = MC_GenWYCut(1.0,1.5)
WY2Cutbin3 = MC_GenWYCut(1.5,2.0)
WY2Cutbin4 = MC_GenWYCut(2.0,2.5)
WY2Cutbin5 = MC_GenWYCut(2.5,3.0)
WY2Cutbin6 = MC_GenWYCut2(3.0)

PlotWStuff0to100 = MC_WPlots("MC_WPlots_0to100","W")
PlotWStuff0to50 = MC_WPlots("MC_WPlots_0to50","W")
PlotWStuff100to200 = MC_WPlots("MC_WPlots_100to200","W")
PlotWStuff200toinf = MC_WPlots("MC_WPlots_200toinf","W")
PlotWStuff0toinf = MC_WPlots("MC_WPlots_0toinf","W")
PlotWStuff50to75 = MC_WPlots("MC_WPlots_50to75","W")
PlotWStuff75to100 = MC_WPlots("MC_WPlots_75to100","W")
PlotWStuff100toinf = MC_WPlots("MC_WPlots_100toinf","W")
PlotWStuff90toinfY225 = MC_WPlots("MC_WPlots_90toinf_Y225","W")
#by PxYy we mean Pt bin x and Y bin y
PlotWStuffP0Y0 = MC_WPlots("MC_WPlots_P0Y0","Z")
PlotWStuffP0Y1 = MC_WPlots("MC_WPlots_P0Y1","Z")
PlotWStuffP0Y2 = MC_WPlots("MC_WPlots_P0Y2","Z")
PlotWStuffP0Y3 = MC_WPlots("MC_WPlots_P0Y3","Z")
PlotWStuffP0Y4 = MC_WPlots("MC_WPlots_P0Y4","Z")
PlotWStuffP0Y5 = MC_WPlots("MC_WPlots_P0Y5","Z")
PlotWStuffP0Y6 = MC_WPlots("MC_WPlots_P0Y6","Z")

PlotWStuffP1Y0 = MC_WPlots("MC_WPlots_P1Y0","Z")
PlotWStuffP1Y1 = MC_WPlots("MC_WPlots_P1Y1","Z")
PlotWStuffP1Y2 = MC_WPlots("MC_WPlots_P1Y2","Z")
PlotWStuffP1Y3 = MC_WPlots("MC_WPlots_P1Y3","Z")
PlotWStuffP1Y4 = MC_WPlots("MC_WPlots_P1Y4","Z")
PlotWStuffP1Y5 = MC_WPlots("MC_WPlots_P1Y5","Z")
PlotWStuffP1Y6 = MC_WPlots("MC_WPlots_P1Y6","Z")

PlotWStuffP2Y0 = MC_WPlots("MC_WPlots_P2Y0","Z")
PlotWStuffP2Y1 = MC_WPlots("MC_WPlots_P2Y1","Z")
PlotWStuffP2Y2 = MC_WPlots("MC_WPlots_P2Y2","Z")
PlotWStuffP2Y3 = MC_WPlots("MC_WPlots_P2Y3","Z")
PlotWStuffP2Y4 = MC_WPlots("MC_WPlots_P2Y4","Z")
PlotWStuffP2Y5 = MC_WPlots("MC_WPlots_P2Y5","Z")
PlotWStuffP2Y6 = MC_WPlots("MC_WPlots_P2Y6","Z")

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
PlotCSFrame0to50 = MC_CSFramePlots("MC_CSFramePlots_0to50","W")
PlotCSFrame50to75 = MC_CSFramePlots("MC_CSFramePlots_50to75","W")
PlotCSFrame75to100 = MC_CSFramePlots("MC_CSFramePlots_75to100","W")
PlotCSFrame100toinf = MC_CSFramePlots("MC_CSFramePlots_100toinf","W")
PlotCSFrame0toinf = MC_CSFramePlots("MC_CSFramePlots_0toinf","Z")
PlotCSFrameRECO50to75 = RECO_CSFramePlots("RECO_CSFramePlots_50to75","W",True)
PlotCSFrameRECO75to100 = RECO_CSFramePlots("RECO_CSFramePlots_75to100","W",True)
PlotCSFrameRECO100toinf = RECO_CSFramePlots("RECO_CSFramePlots_100toinf","W",True)
PlotCSFrameRECO50toinf = RECO_CSFramePlots("RECO_CSFramePlots_50toinf","W",True)
PlotCSFrameRECO70toinf = RECO_CSFramePlots("RECO_CSFramePlots_70toinf","W",True)
PlotCSFrameRECO90toinf = RECO_CSFramePlots("RECO_CSFramePlots_90toinf","W",True)

#this is for the reconstruction level plots
# Trigger Cut
#TrigCut = OP_TriggerCut(10)
# Lep comp.
NumLeptons = OP_NumComLeptons("==", 1)
NumLeptons2 = OP_NumComLeptons("==", 2)
# Mu comp.
NumMuons = OP_NumComMuons("==", 1)
NumMuons2 = OP_NumComMuons("==", 2)
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
CommMHTCut70 = RECO_CommonMHTCut(70.)
CommMHTCut90 = RECO_CommonMHTCut(90.)
PFMETCut50 = RECO_PFMETCut(50.)
PFMETCut70 = RECO_PFMETCut(70.)
PFMETCut90 = RECO_PFMETCut(90.)
# PlotRECOPol stuff NoHTCut
#PlotRecoPolStuffnoHtCut = RECO_PolPlots("RECO_PolPlotsNoHtCut", "W", True)
#PlotRecoPolStuffnoMHtCut = RECO_PolPlots("RECO_PolPlotsNoMHtCut", "W", True)
# CommonHT Cut
#CommHTCut = RECO_CommonHTCut(350.)
# PlotRECOPol stuff
PlotRECO = RECO_PolPlots("RECO_PolPlots", "W", False)

ZmassCut = RECO_2ndMuonMass(25.0, 91.2)
CommMHTCut50to75 = RECO_CommonMHTCut2(50.0,75.0)
CommMHTCut75to100 = RECO_CommonMHTCut2(75.0,100.0)
MuMuPtCut50to75 = RECO_MuMuPtCut2(50.0,75.0)
MuMuPtCut75to100 = RECO_MuMuPtCut2(75.0,100.0)
MuMuPtCut100 = RECO_MuMuPtCut(100.0)
PlotRECO50to75 = RECO_PolPlots("RECO_PolPlots_50to75", "W", True)
PlotRECO75to100 = RECO_PolPlots("RECO_PolPlots_75to100", "W", True)
PlotRECO100toinf = RECO_PolPlots("RECO_PolPlots_100toinf", "W", True)
PlotRECO50toinf = RECO_PolPlots("RECO_PolPlots_50toinf", "W", True)
PlotRECO70toinf = RECO_PolPlots("RECO_PolPlots_70toinf", "W", True)
PlotRECO75toinf = RECO_PolPlots("RECO_PolPlots_75toinf", "W", True)
PlotRECO90toinf = RECO_PolPlots("RECO_PolPlots_90toinf", "W", True)

#this is for print/debug info
PrintMCParticleInfo = MC_PrintGenParticleInfo("FULL")

#for the Z-boson analysis
CheckForZ = MC_GenZExists()

# Add the tree to our analysis
a+=tree
tree.Attach(CheckForW)
#tree.TAttach(CheckForW, CheckForWLepton)
tree.TAttach(CheckForW, CheckForWMuon)
#tree.TAttach(CheckForWLepton, WPTCut100toinf)
tree.TAttach(CheckForWMuon, WPTCut100toinf)
tree.TAttach(WPTCut100toinf, PlotWStuff100toinf)

#tree.TAttach(CheckForWLepton, WPTCut90toinf)
#tree.TAttach(WPTCut90toinf, WYCut0to225)
#tree.TAttach(WYCut0to225, PlotWStuff90toinfY225)

#tree.TAttach(CheckForW,CheckForWMuon)
#tree.TAttach(CheckForWMuon, PlotWStuff0toinf)

#tree.TAttach(CheckForWMuon,WPTCut0to100)
#tree.TAttach(WPTCut0to100,PlotWStuff0to100)
#tree.TAttach(CheckForWMuon,WPTCut100to200)
#tree.TAttach(WPTCut100to200,PlotWStuff100to200)
#tree.TAttach(CheckForWMuon,WPTCut200toinf)
#tree.TAttach(WPTCut200toinf,PlotWStuff200toinf)

#tree.TAttach(CheckForWMuon,WPTCut)
#tree.TAttach(WPTCut,PlotWStuff100toinf)

#tree.TAttach(CheckForWMuon, WYCut0top2)
#tree.TAttach(WYCut0top2, PlotWStuffY0top2)
#tree.TAttach(CheckForWMuon, WYCut2to2p2)
#tree.TAttach(WYCut2to2p2, PlotWStuffY2to2p2)

b+=treeb
treeb.Attach(NumLeptons)#use this as the starting point when running over file with no generator bosons...
#the recoW cut flow:
#treeb.Attach(CheckForW)
#treeb.TAttach(CheckForW, NumLeptons)
treeb.TAttach(NumLeptons, NumMuons)
treeb.TAttach(NumMuons, NumPh)
treeb.TAttach(NumPh, NumGoodJets)
treeb.TAttach(NumGoodJets, OddJeti)
treeb.TAttach(OddJeti, minDRMuonJetCut)
treeb.TAttach(minDRMuonJetCut, ZmassCut)
treeb.TAttach(ZmassCut, PlotRECO)
#treeb.TAttach(ZmassCut, PFMETCut50)
#treeb.TAttach(PFMETCut50, PlotCSFrameRECO50toinf)
#treeb.TAttach(PFMETCut50, PlotRECO50toinf)
#treeb.TAttach(ZmassCut, PFMETCut70)
#treeb.TAttach(PFMETCut70, PlotCSFrameRECO70toinf)
#treeb.TAttach(PFMETCut70, PlotRECO70toinf)
#treeb.TAttach(ZmassCut, PFMETCut90)
#treeb.TAttach(PFMETCut90, PlotCSFrameRECO90toinf)
#treeb.TAttach(PFMETCut90, PlotRECO90toinf)

#treeb.TAttach(ZmassCut, CommMHTCut50to75)
#treeb.TAttach(CommMHTCut50to75, PlotCSFrameRECO50to75)
#treeb.TAttach(CommMHTCut50to75, PlotRECO50to75)
#treeb.TAttach(ZmassCut, CommMHTCut75to100)
#treeb.TAttach(CommMHTCut75to100, PlotCSFrameRECO75to100)
#treeb.TAttach(CommMHTCut75to100, PlotRECO75to100)
#treeb.TAttach(ZmassCut, CommMHTCut100)
#treeb.TAttach(CommMHTCut100, PlotCSFrameRECO100toinf)
#treeb.TAttach(CommMHTCut100, PlotRECO100toinf)
#the recoZ cut flow:
#treeb.Attach(CheckForZ)
#treeb.TAttach(CheckForZ, NumLeptons2)
#treeb.TAttach(NumLeptons2, NumMuons2)
#treeb.TAttach(NumMuons2, NumPh)
#treeb.TAttach(NumPh, NumGoodJets)
#treeb.TAttach(NumGoodJets, OddJeti)
#treeb.TAttach(OddJeti, MuMuPtCut50to75)
#treeb.TAttach(MuMuPtCut50to75, PlotCSFrameRECO50to75)
#treeb.TAttach(MuMuPtCut50to75, PlotRECO50to75)
#treeb.TAttach(OddJeti, MuMuPtCut75to100)
#treeb.TAttach(MuMuPtCut75to100, PlotCSFrameRECO75to100)
#treeb.TAttach(MuMuPtCut75to100, PlotRECO75to100)
#treeb.TAttach(OddJeti,MuMuPtCut100)
#treeb.TAttach(MuMuPtCut100, PlotCSFrameRECO100toinf)
#treeb.TAttach(MuMuPtCut100, PlotRECO100toinf)

#treeb.TAttach(ZmassCut, CommMHTCut50to75)
#treeb.TAttach(CommMHTCut50to75, Plot50to75)
#treeb.TAttach(ZmassCut, CommMHTCut75to100)
#treeb.TAttach(CommMHTCut75to100, Plot75to100)
#treeb.TAttach(ZmassCut, CommMHTCut100)
#treeb.TAttach(CommMHTCut100, Plot100toinf)
#treeb.TAttach(NumPh, OddEli)
#treeb.TAttach(OddEli, OddMui)
#treeb.TAttach(OddMui, OddJeti)
#treeb.TAttach(OddJeti, OddPhoti)
#treeb.TAttach(OddPhoti, BadMui)
#treeb.TAttach(NumPh, BadMui)
#treeb.TAttach(BadMui, aPhotkilledJet)
#treeb.TAttach(aPhotkilledJet, minDRMuonJetCut)
#treeb.TAttach(minDRMuonJetCut, PlotRecoPolStuffnoMHtCut)
#treeb.TAttach(PlotRecoPolStuffnoMHtCut, CommMHTCut100)
#treeb.TAttach(CommMHTCut100, PlotRecoPolStuffnoHtCut)

c+=treec
treec.Attach(PrintMCParticleInfo)
#treec.Attach(PrintDebug)

d+=treed
treed.Attach(CheckForZ)
#treed.Attach(CheckForW)
 #treed.TAttach(CheckForW, CheckForWMuon)
#treed.TAttach(CheckForW, CheckForWLepton)

#treed.TAttach(CheckForWMuon, WPTCut15to25)
#treed.TAttach(WPTCut15to25, PlotCSFrame15to25)
#treed.TAttach(CheckForWMuon, WPTCut25to35)
#treed.TAttach(WPTCut25to35, PlotCSFrame25to35)
#treed.TAttach(CheckForWMuon, WPTCut35to65)
#treed.TAttach(WPTCut35to65, PlotCSFrame35to65)
#treed.TAttach(CheckForWMuon, WPTCut65to105)
#treed.TAttach(WPTCut65to105, PlotCSFrame65to105)

#treed.TAttach(CheckForWMuon, WPTCut100toinf)
#treed.TAttach(WPTCut100toinf, PlotCSFrame100toinf)

#treed.TAttach(CheckForW, PlotCSFrame0toinf)
treed.TAttach(CheckForZ, PlotCSFrame0toinf)

e+=treee
#treee.Attach(CheckForW)
treee.Attach(CheckForZ)
#treee.TAttach(CheckForW, CheckForWLepton)

#treee.TAttach(CheckForW, WPTCut0to50)
treee.TAttach(CheckForZ, WPTCut0to50)
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

#treee.TAttach(CheckForW, WPTCut50to100)
treee.TAttach(CheckForZ, WPTCut50to100)
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

#treee.TAttach(CheckForW, WPTCut100toinf)
treee.TAttach(CheckForZ, WPTCut100toinf)
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
#treeg.TAttach(CheckForW, CheckForWLepton)
#treeg.Attach(CheckForZ)

treeg.TAttach(CheckForW, WPTCut0to50)
#treeg.TAttach(CheckForZ, WPTCut0to50)
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

treeg.TAttach(CheckForW, WPTCut50to100)
#treeg.TAttach(CheckForZ, WPTCut50to100)
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

treeg.TAttach(CheckForW, WPTCut100toinf)
#treeg.TAttach(CheckForZ, WPTCut100toinf)
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

f+=treef
treef.Attach(CheckForW)
#treef.TAttach(CheckForW, CheckForWLepton)
#treef.Attach(CheckForZ)

treef.TAttach(CheckForW, WPTCut0to50)
#treef.TAttach(CheckForZ, WPTCut0to50)
treef.TAttach(WPTCut0to50, PlotWStuff0to50)
treef.TAttach(WPTCut0to50, PlotCSFrame0to50)

treef.TAttach(CheckForW, WPTCut50to75)
#treef.TAttach(CheckForZ, WPTCut50to75)
treef.TAttach(WPTCut50to75, PlotWStuff50to75)
treef.TAttach(WPTCut50to75, PlotCSFrame50to75)

treef.TAttach(CheckForW, WPTCut75to100)
#treef.TAttach(CheckForZ, WPTCut75to100)
treef.TAttach(WPTCut75to100, PlotWStuff75to100)
treef.TAttach(WPTCut75to100, PlotCSFrame75to100)

treef.TAttach(CheckForW, WPTCut100toinf)
#treef.TAttach(CheckForZ, WPTCut100toinf)
treef.TAttach(WPTCut100toinf, PlotWStuff100toinf)
treef.TAttach(WPTCut100toinf, PlotCSFrame100toinf)

# Define the list of samples to run over
w=[wjets]
z=[zjets]
q=[qcdjets]
w2=[wmupythia]
qmu=[qcdmu3050, qcdmu5080, qcdmu80120]#, qcdmu120170, qcdmu170Inf]
data=[realdata]
#a.Run("results",conf,z)
b.Run("results",conf,z)
#c.Run("results",conf,z)
#d.Run("results",conf,z)
#e.Run("results",conf,z)
#f.Run("results",conf,w2)
#g.Run("results",conf,w)
