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
from wpol.muon_config import muon_id, conf, muon_scale_shift

# Import pfmet smearing parameters
from wpol.pfmet_smearing import pfmet_smearing, pfmet_jecunc

# Modify the pfmet_smearing parameters
pfmet_smearing.scale = False #if scale = false, then smear.
pfmet_smearing.value = 0.05
pfmet_smearing.doMHT = True #if True, act on MHT (as long as 1 muon exists), if False, act on MET

# Modify the muon scale parameters
muon_scale_shift.scalechoice = 100.0 #this is the GeV scale to apply the percentage shift
muon_scale_shift.scaleshift = 0.01 #the percentage shift to apply relative to the original PT(mu)
muon_scale_shift.plusplus = False #if True, then the positively charged muon has its PT increased, negatively charged decreased. False = converse

# Modify the JEC Uncertainty pfMET scale parameters
pfmet_jecunc.jecuncfile = "GR_R_38X_V15_AK5PF_Uncertainty.txt"
pfmet_jecunc.lepton = "Muon"
pfmet_jecunc.pfjetthresh = 10.0
pfmet_jecunc.unclusteredshift = 0.05
pfmet_jecunc.shiftup = True

# We can still override parameters, for example:
conf.Common.Muons.PtCut=20.0

#SET THIS PARAMETER to either W or Z to ensure that the plotting code is setup appropriately
selection = "W"
#SET THIS PARAMETER to either True or False depending on if you want to use the gen information for templates
doGen = True
#remember to choose the sample you will run over at the bottom - it could be data!

# Now check that you've entered either W or Z
if selection == "W":
    print "W-selection chosen"
elif selection == "Z":
    print "Z-selection chosen"
else:
    raise NameError("selectiontype")

# Create the analysis
a_name = "RecoRoutines_" + selection + "-selection"
recoplots=Analysis(a_name)

#add extra criteria to commonmuon definition
#can do this preCC or postCC i.e. before/after cross-cleaning
muonfilt=CustomMuonId(muon_id.ps())
recoplots.AddMuonFilter("PreCC",muonfilt)
#recoplots.AddMuonFilter("PostCC",muonfilt)

#add muon scale shift before event selection
#muonscaleshift=MuonScaleShift(muon_scale_shift.ps())
#recoplots.AddMuonFilter("PreCC",muonscaleshift)

#add pfMET smearing (for systematic studies)
#pfmetsmear=pfMETsmearing(pfmet_smearing.ps())
#recoplots.AddMETFilter("pfMET",pfmetsmear)

#add pfMET JEC Uncertainty (for systematic studies)
#pfmetjecunc=pfMETJECUnc(pfmet_jecunc.ps())
#recoplots.AddMETFilter("pfMET",pfmetjecunc)

tree = Tree("Main")

# Initialise our operations
GoodEventSelection = OP_GoodEventSelection()
NumLeptons1 = OP_NumComLeptons("==", 1)
NumLeptons2 = OP_NumComLeptons("==", 2)
NumMuons1 = OP_NumComMuons("==", 1)
NumMuons2 = OP_NumComMuons("==", 2)
NumPhotons0 = OP_NumComPhotons("==", 0)
NumGoodJetsLT4 = OP_NumComJets("<", 4)
NumGoodJetsEQ1 = OP_NumComJets("==", 1)
OddJetCut = OP_OddJet()
minDRMuonJetCut = RECO_MuonJetDRCut(0.5)
#Trigger = TRIGGER_Cut("HLT_Mu9")
Trigger = TRIGGER_Cut("HLT_Mu9","HLT_Mu15")
# If the veto is set to true, cut away events in the Z-mass window
if selection == "Z":
    keepZ = True
    window = 10.0
else:
    keepZ = False
    window = 25.0
ZMassCut = RECO_2ndMuonMass(window, 91.2, keepZ, "all")
#ZMassCut = RECO_2ndMuonMass(1.0, 3.1, True, "OS")#"SS" for same sign, "OS" for opposite sign and "all" for all
#SBlowCut = RECO_2ndMuonMass(0.4, 2.6, True)
#SBhighCut = RECO_2ndMuonMass(0.4, 3.6, True)
PFMTCut30 = RECO_PFMTCut(30.0)
PFMTCut30_1 = RECO_PFMTCut(30.0)
PFMTCut30_2 = RECO_PFMTCut(30.0)
PFMTCut30_3 = RECO_PFMTCut(30.0)

PFMETCut50toinf = RECO_PFMETCut(50.0)
PFMETCut100toinf = RECO_PFMETCut(100.0)
PFMETCut50to75 = RECO_PFMETCut2(50.0, 75.0)
PFMETCut75to100 = RECO_PFMETCut2(75.0, 100.0)

MuMuPtCut50toinf = RECO_MuMuPtCut(50.0)
MuMuPtCut50to75 = RECO_MuMuPtCut2(50.0,75.0)
MuMuPtCut75to100 = RECO_MuMuPtCut2(75.0,100.0)
MuMuPtCut100toinf = RECO_MuMuPtCut(100.0)

#convention for RECO_PolPlots: 0=ignore, 1=50-inf, 2=100-inf, 3=50-75, 4=75-100
PlotRECO50to75 = RECO_PolPlots("RECO_PolPlots_50to75", selection, doGen, 3)
PlotRECO75to100 = RECO_PolPlots("RECO_PolPlots_75to100", selection, doGen, 4)
PlotRECO100toinf = RECO_PolPlots("RECO_PolPlots_100toinf", selection, doGen, 2)
PlotRECO50toinf = RECO_PolPlots("RECO_PolPlots_50toinf", selection, doGen, 1)
PlotRECO50toinfnoMT = RECO_PolPlots("RECO_PolPlots_50toinf_noMT", selection, doGen, 1)
PlotRECO50toinfnoMTnoMHT = RECO_PolPlots("RECO_PolPlots_50toinf_noMT_noMHT", selection, doGen, 1)
PlotRECO50toinfstart = RECO_PolPlots("RECO_PolPlots_50toinf_start", selection, doGen, 1)
#PlotRECOSBlow = RECO_PolPlots("RECO_PolPlots_SBlow", selection, doGen)
#PlotRECOSBhigh = RECO_PolPlots("RECO_PolPlots_SBhigh", selection, doGen)

PlotCSFrameRECO50toinf = RECO_CSFramePlots("RECO_CSFramePlots_50toinf", selection, doGen)
PlotCSFrameRECO50to75 = RECO_CSFramePlots("RECO_CSFramePlots_50to75", selection, doGen)
PlotCSFrameRECO75to100 = RECO_CSFramePlots("RECO_CSFramePlots_75to100", selection, doGen)
PlotCSFrameRECO100toinf = RECO_CSFramePlots("RECO_CSFramePlots_100toinf", selection, doGen)

MuonPlots = RECO_MuonPlotting("testMuonPlotting")
#PlotGenOrigin = CheckGenOrigin("checkGenOrigin") #only plot this if gen info is available...

#CheckForWMuon = MC_GenNumLeptons("muon",1)#temp
#CheckFor1MuonExtra = MC_GenNumMuonsExtra(1)#temp

# Add the tree to our analysis
recoplots+=tree
if selection == "W":
    tree.Attach(Trigger)
    tree.TAttach(Trigger, GoodEventSelection)
    #tree.TAttach(Trigger, NumLeptons1)
    #tree.Attach(GoodEventSelection)
    #tree.TAttach(GoodEventSelection, PlotRECO50toinfstart)
    tree.TAttach(GoodEventSelection, NumLeptons1)
    #tree.Attach(NumLeptons1)
    #tree.Attach(CheckFor1MuonExtra)
    #tree.TAttach(CheckFor1MuonExtra, NumLeptons1)
    tree.TAttach(NumLeptons1, NumMuons1)
    tree.TAttach(NumMuons1, NumPhotons0)
else:
    tree.Attach(Trigger)
    tree.TAttach(Trigger, NumLeptons2)
    tree.TAttach(NumLeptons2, NumMuons2)
    tree.TAttach(NumMuons2, NumPhotons0)
tree.TAttach(NumPhotons0, NumGoodJetsLT4)
tree.TAttach(NumGoodJetsLT4, OddJetCut)
#tree.TAttach(NumPhotons0, NumGoodJetsEQ1)
#tree.TAttach(NumGoodJetsEQ1, OddJetCut)
tree.TAttach(OddJetCut, minDRMuonJetCut)
tree.TAttach(minDRMuonJetCut, ZMassCut)
#for the JPsi SideBands
#tree.TAttach(minDRMuonJetCut, SBlowCut)
#tree.TAttach(SBlowCut, PlotRECOSBlow)
#tree.TAttach(minDRMuonJetCut, SBhighCut)
#tree.TAttach(SBhighCut, PlotRECOSBhigh)
if selection == "W":
    tree.TAttach(ZMassCut, PlotRECO50toinfnoMTnoMHT)
    tree.TAttach(ZMassCut, PFMETCut50toinf)
    tree.TAttach(PFMETCut50toinf, PlotRECO50toinfnoMT)
    tree.TAttach(PFMETCut50toinf, PFMTCut30)
    tree.TAttach(PFMTCut30, PlotRECO50toinf)
    #tree.TAttach(PFMTCut30, PlotCSFrameRECO50toinf)  
    tree.TAttach(PFMTCut30, MuonPlots)
    #tree.TAttach(ZMassCut, PlotRECO50toinf)
    #tree.TAttach(PFMTCut30, PlotGenOrigin)
    tree.TAttach(ZMassCut, PFMETCut50to75)
    tree.TAttach(PFMETCut50to75, PFMTCut30_1)
    tree.TAttach(PFMTCut30_1, PlotRECO50to75)
    tree.TAttach(ZMassCut, PFMETCut75to100)
    tree.TAttach(PFMETCut75to100, PFMTCut30_2)
    tree.TAttach(PFMTCut30_2, PlotRECO75to100)
    tree.TAttach(ZMassCut, PFMETCut100toinf)
    tree.TAttach(PFMETCut100toinf, PFMTCut30_3)
    tree.TAttach(PFMTCut30_3, PlotRECO100toinf)
else:
    tree.TAttach(ZMassCut, MuMuPtCut50to75)
    tree.TAttach(MuMuPtCut50to75, PlotRECO50to75)
    tree.TAttach(ZMassCut, MuMuPtCut75to100)
    tree.TAttach(MuMuPtCut75to100, PlotRECO75to100)
    tree.TAttach(ZMassCut, MuMuPtCut100toinf)
    tree.TAttach(MuMuPtCut100toinf, PlotRECO100toinf)
    #tree.TAttach(MuMuPtCut50toinf, PlotCSFrameRECO50toinf)
    tree.TAttach(ZMassCut, MuMuPtCut50toinf)
    tree.TAttach(MuMuPtCut50toinf, MuonPlots)
    tree.TAttach(MuMuPtCut50toinf, PlotRECO50toinf)

# Define the list of samples to run over
#wjets.LastEntry=200000
#wjets.Name+="_shift_ptmu100gev_pm1pc"
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
#dataskim38
#realdata2010A.LastEntry=1000

recoplots.Run("results",conf,w)
