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
genplots=Analysis("GenRoutines")

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

#for printing decay chain
PrintMCParticleInfo = MC_PrintGenParticleInfo("FULL")

# Initialise our operations
CheckForW = MC_GenWExists()
CheckForZ = MC_GenZExists()

# The decay type check only works if the gen-mother information is correct
#CheckForWMuon = MC_GenWMuonExists()
#CheckForWLepton = MC_GenWLeptonExists()
#alternative is just to check that the muon is there in the final state (without the explicit mother check)
CheckForWMuon = MC_GenNumLeptons("muon",1) #first index is flavour of object, second index is number of objects
CheckForWTau = MC_GenNumLeptons("tau",1)
CheckS1Muon = MC_GenS1Leptons("muon")
CheckFor1MuonExtra = MC_GenNumMuonsExtra(1)

WPTCut50to75 = MC_GenWPTCut2(50.0, 75.0)
WPTCut75to100 = MC_GenWPTCut2(75.0, 100.0)
WPTCut50to100 = MC_GenWPTCut2(50.0, 100.0)
WPTCut100toinf = MC_GenWPTCut(100.0)
WPTCut50toinf = MC_GenWPTCut(50.0)
WPTCut75toinf = MC_GenWPTCut(75.0)
MCRECOPT50toinf = MCRECO_PFMETCut(50.0) #remember this uses the RECO pfMET with/without the reco muon depending on deltaR(gen,reco)muon
MCRECOPT100toinf = MCRECO_PFMETCut(100.0) #remember this uses the RECO pfMET with/without the reco muon depending on deltaR(gen,reco)muon
MCRECOPT50to75 = MCRECO_PFMETCut2(50.0,75.0)
MCRECOPT75to100 = MCRECO_PFMETCut2(75.0,100.0)

# The second index should be matched to the sample
PlotWStuff0toinf = MC_WPlots("MC_WPlots_0toinf",boson)
PlotWStuff50to75 = MC_WPlots("MC_WPlots_50to75",boson)
PlotWStuff75to100 = MC_WPlots("MC_WPlots_75to100",boson)
PlotWStuff50to100 = MC_WPlots("MC_WPlots_50to100",boson)
PlotWStuff100toinf = MC_WPlots("MC_WPlots_100toinf",boson)
PlotWStuff50toinf = MC_WPlots("MC_WPlots_50toinf",boson)
PlotWStuff75toinf = MC_WPlots("MC_WPlots_75toinf",boson)

PlotWStuffMCRECO50toinf = MC_WPlots("MC_WPlots_MCRECO50toinf",boson)
PlotWStuffMCRECO100toinf = MC_WPlots("MC_WPlots_MCRECO100toinf",boson)
PlotWStuffMCRECO50to75 = MC_WPlots("MC_WPlots_MCRECO50to75",boson)
PlotWStuffMCRECO75to100 = MC_WPlots("MC_WPlots_MCRECO75to100",boson)

PlotCSFrame0toinf = MC_CSFramePlots("MC_CSFramePlots_0toinf",boson)
PlotCSFrame50to75 = MC_CSFramePlots("MC_CSFramePlots_50to75",boson)
PlotCSFrame75to100 = MC_CSFramePlots("MC_CSFramePlots_75to100",boson)
PlotCSFrame100toinf = MC_CSFramePlots("MC_CSFramePlots_100toinf",boson)

# Add the tree to our analysis
genplots+=tree

if boson == "W":
    ##tree.Attach(PrintMCParticleInfo)
    tree.Attach(CheckForW)
    ##tree.TAttach(PrintMCParticleInfo, CheckForW)
    ##tree.TAttach(CheckForW, PlotWStuff0toinf)
    ##tree.TAttach(CheckForW, PlotCSFrame0toinf)
    #tree.TAttach(CheckForW, WPTCut50to75)
    #tree.TAttach(CheckForW, WPTCut75to100)
    #tree.TAttach(CheckForW, WPTCut50to100)
    #tree.TAttach(CheckForW, WPTCut100toinf)
    ##tree.TAttach(CheckForW, CheckForWTau)
    ##tree.TAttach(CheckForWTau, CheckS1Muon)
    ##tree.TAttach(CheckS1Muon, PrintMCParticleInfo)
    ##tree.Attach(CheckForWMuon)
    ##tree.TAttach(CheckForWMuon, WPTCut50toinf)
    tree.TAttach(CheckForW, CheckFor1MuonExtra)
    tree.TAttach(CheckFor1MuonExtra, MCRECOPT100toinf)
    tree.TAttach(CheckFor1MuonExtra, MCRECOPT50toinf)
    tree.TAttach(CheckFor1MuonExtra, MCRECOPT50to75)
    tree.TAttach(CheckFor1MuonExtra, MCRECOPT75to100)
    #tree.TAttach(CheckForW, WPTCut50toinf)
    #tree.TAttach(CheckForW, WPTCut75toinf)
    #tree.TAttach(CheckForW, WPTCut100toinf)
else:
    tree.Attach(CheckForZ)
    tree.TAttach(CheckForZ, PlotWStuff0toinf)
    #tree.TAttach(CheckForZ, PlotCSFrame0toinf)
    #tree.TAttach(CheckForZ, WPTCut50to75)
    #tree.TAttach(CheckForZ, WPTCut75to100)
    tree.TAttach(CheckForZ, WPTCut100toinf)

#tree.TAttach(WPTCut50to75, PlotWStuff50to75)
##tree.TAttach(WPTCut50to75, PlotCSFrame50to75)
#tree.TAttach(WPTCut75to100, PlotWStuff75to100)
##tree.TAttach(WPTCut75to100, PlotCSFrame75to100)
#tree.TAttach(WPTCut50to100, PlotWStuff50to100)
#tree.TAttach(WPTCut100toinf, PlotWStuff100toinf)
##tree.TAttach(WPTCut100toinf, PlotCSFrame100toinf)

#tree.TAttach(WPTCut50toinf, PlotWStuff50toinf)
##tree.TAttach(CheckForWMuon, PlotWStuff50toinf)
tree.TAttach(MCRECOPT100toinf, PlotWStuffMCRECO100toinf)
tree.TAttach(MCRECOPT50toinf, PlotWStuffMCRECO50toinf)
tree.TAttach(MCRECOPT50to75, PlotWStuffMCRECO50to75)
tree.TAttach(MCRECOPT75to100, PlotWStuffMCRECO75to100)
##tree.TAttach(WPTCut75toinf, PlotWStuff75toinf)

# Define the list of samples to run over
w=[wjets]
z=[zjets]
#wjets.LastEntry=1000000
wjets.Name+="_mcrecotesting"
if boson == "W":
    genplots.Run("results",conf,w)
else:
    genplots.Run("results",conf,z)
