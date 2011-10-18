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
#conf.Common.Muons.PtCut=10.0
conf.Common.ApplyXCleaning=False

# Create the analysis
genplots=Analysis("WeightingRoutines_MuonExtra")

tree = Tree("Main")

#SET THIS PARAMETER to either W or Z to ensure that the plotting code is setup appropriately
boson = "W"

# Now check that you've entered either W or Z
if boson == "W":
    print "W-boson chosen"
elif boson == "Z":
    print "Z-boson chosen"
else:
    raise NameError("bosontype")

# Initialise our operations
CheckForW = MC_GenWExists()
CheckForZ = MC_GenZExists()

# The decay type check only works if the gen-mother information is correct
#CheckForWMuon = MC_GenWMuonExists()
#CheckForWLepton = MC_GenWLeptonExists()
#alternative is just to check that the muon is there in the final state (without the explicit mother check)
CheckForWMuon = MC_GenNumLeptons("muon",1)
CheckFor1MuonExtra = MC_GenNumMuonsExtra(1)
MCRECOPT50toinf = MCRECO_PFMETCut(50.0) #remember this uses the RECO pfMET with/without the reco muon depending on deltaR(gen,reco)muon
MCRECOPT100toinf = MCRECO_PFMETCut(100.0) #remember this uses the RECO pfMET with/without the reco muon depending on deltaR(gen,reco)muon
MCRECOPT50to75 = MCRECO_PFMETCut2(50.0,75.0)
MCRECOPT75to100 = MCRECO_PFMETCut2(75.0,100.0)
#if you're going to use the MCRECO cut, make sure that the gen information exists, i.e. do a WMuon or WMuonExtra cut first

# The second index should be matched to the sample
WPTCut0to50 = MC_GenWPTCut2(0.0,50.0)
WPTCut50to100 = MC_GenWPTCut2(50.0,100.0)
WPTCut100toinf = MC_GenWPTCut(100.0)

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

#by PxYy we mean Pt bin x and Y bin y
PlotWStuffP0Y0 = MC_WPlots("MC_WPlots_P0Y0",boson)
PlotWStuffP0Y1 = MC_WPlots("MC_WPlots_P0Y1",boson)
PlotWStuffP0Y2 = MC_WPlots("MC_WPlots_P0Y2",boson)
PlotWStuffP0Y3 = MC_WPlots("MC_WPlots_P0Y3",boson)
PlotWStuffP0Y4 = MC_WPlots("MC_WPlots_P0Y4",boson)
PlotWStuffP0Y5 = MC_WPlots("MC_WPlots_P0Y5",boson)
PlotWStuffP0Y6 = MC_WPlots("MC_WPlots_P0Y6",boson)

PlotWStuffP1Y0 = MC_WPlots("MC_WPlots_P1Y0",boson)
PlotWStuffP1Y1 = MC_WPlots("MC_WPlots_P1Y1",boson)
PlotWStuffP1Y2 = MC_WPlots("MC_WPlots_P1Y2",boson)
PlotWStuffP1Y3 = MC_WPlots("MC_WPlots_P1Y3",boson)
PlotWStuffP1Y4 = MC_WPlots("MC_WPlots_P1Y4",boson)
PlotWStuffP1Y5 = MC_WPlots("MC_WPlots_P1Y5",boson)
PlotWStuffP1Y6 = MC_WPlots("MC_WPlots_P1Y6",boson)

PlotWStuffP2Y0 = MC_WPlots("MC_WPlots_P2Y0",boson)
PlotWStuffP2Y1 = MC_WPlots("MC_WPlots_P2Y1",boson)
PlotWStuffP2Y2 = MC_WPlots("MC_WPlots_P2Y2",boson)
PlotWStuffP2Y3 = MC_WPlots("MC_WPlots_P2Y3",boson)
PlotWStuffP2Y4 = MC_WPlots("MC_WPlots_P2Y4",boson)
PlotWStuffP2Y5 = MC_WPlots("MC_WPlots_P2Y5",boson)
PlotWStuffP2Y6 = MC_WPlots("MC_WPlots_P2Y6",boson)


# Add the tree to our analysis
genplots+=tree

if boson == "W":
    tree.Attach(CheckForW)
    #tree.TAttach(CheckForW, WPTCut0to50)
    #tree.TAttach(CheckForW, WPTCut50to100)
    #tree.TAttach(CheckForW, WPTCut100toinf)
    tree.TAttach(CheckForW, CheckFor1MuonExtra)
    tree.TAttach(CheckFor1MuonExtra, MCRECOPT75to100)
    #tree.TAttach(MCRECOPT75to100, WPTCut0to50)
    #tree.TAttach(MCRECOPT75to100, WPTCut50to100)
    tree.TAttach(MCRECOPT75to100, WPTCut100toinf)
else:
    tree.Attach(CheckForZ)
    tree.TAttach(CheckForZ, WPTCut0to50)
    tree.TAttach(CheckForZ, WPTCut50to100)
    tree.TAttach(CheckForZ, WPTCut100toinf)

##tree.TAttach(WPTCut0to50, WY0Cutbin0)
##tree.TAttach(WY0Cutbin0, PlotWStuffP0Y0)
##tree.TAttach(WPTCut0to50, WY0Cutbin1)
##tree.TAttach(WY0Cutbin1, PlotWStuffP0Y1)
##tree.TAttach(WPTCut0to50, WY0Cutbin2)
##tree.TAttach(WY0Cutbin2, PlotWStuffP0Y2)
##tree.TAttach(WPTCut0to50, WY0Cutbin3)
##tree.TAttach(WY0Cutbin3, PlotWStuffP0Y3)
##tree.TAttach(WPTCut0to50, WY0Cutbin4)
##tree.TAttach(WY0Cutbin4, PlotWStuffP0Y4)
##tree.TAttach(WPTCut0to50, WY0Cutbin5)
##tree.TAttach(WY0Cutbin5, PlotWStuffP0Y5)
##tree.TAttach(WPTCut0to50, WY0Cutbin6)
##tree.TAttach(WY0Cutbin6, PlotWStuffP0Y6)

##tree.TAttach(WPTCut50to100, WY1Cutbin0)
##tree.TAttach(WY1Cutbin0, PlotWStuffP1Y0)
##tree.TAttach(WPTCut50to100, WY1Cutbin1)
##tree.TAttach(WY1Cutbin1, PlotWStuffP1Y1)
##tree.TAttach(WPTCut50to100, WY1Cutbin2)
##tree.TAttach(WY1Cutbin2, PlotWStuffP1Y2)
##tree.TAttach(WPTCut50to100, WY1Cutbin3)
##tree.TAttach(WY1Cutbin3, PlotWStuffP1Y3)
##tree.TAttach(WPTCut50to100, WY1Cutbin4)
##tree.TAttach(WY1Cutbin4, PlotWStuffP1Y4)
##tree.TAttach(WPTCut50to100, WY1Cutbin5)
##tree.TAttach(WY1Cutbin5, PlotWStuffP1Y5)
##tree.TAttach(WPTCut50to100, WY1Cutbin6)
##tree.TAttach(WY1Cutbin6, PlotWStuffP1Y6)

tree.TAttach(WPTCut100toinf, WY2Cutbin0)
tree.TAttach(WY2Cutbin0, PlotWStuffP2Y0)
tree.TAttach(WPTCut100toinf, WY2Cutbin1)
tree.TAttach(WY2Cutbin1, PlotWStuffP2Y1)
tree.TAttach(WPTCut100toinf, WY2Cutbin2)
tree.TAttach(WY2Cutbin2, PlotWStuffP2Y2)
tree.TAttach(WPTCut100toinf, WY2Cutbin3)
tree.TAttach(WY2Cutbin3, PlotWStuffP2Y3)
tree.TAttach(WPTCut100toinf, WY2Cutbin4)
tree.TAttach(WY2Cutbin4, PlotWStuffP2Y4)
tree.TAttach(WPTCut100toinf, WY2Cutbin5)
tree.TAttach(WY2Cutbin5, PlotWStuffP2Y5)
tree.TAttach(WPTCut100toinf, WY2Cutbin6)
tree.TAttach(WY2Cutbin6, PlotWStuffP2Y6)

# Define the list of samples to run over
w=[wjets]
z=[zjets]
#wjets.LastEntry=1000000
wjets.Name+="_MCRECO75to100_part3"
if boson == "W":
    genplots.Run("results",conf,w)
else:
    genplots.Run("results",conf,z)
