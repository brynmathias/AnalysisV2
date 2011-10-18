#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libOneLepton import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig

# This imports the standard set of samples
# There are none atm :-(
from samples.icf_demo import *

# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Common.Jets.EtCut=50.

#conf.Common.ApplyXCleaning=True
conf.XCleaning.MuonJet=True
conf.XCleaning.ElectronJet=True
conf.XCleaning.Muons.PtCut=3.
conf.XCleaning.Muons.TrkIsoCut=20.
conf.XCleaning.Muons.CombIsoCut=20.
conf.XCleaning.Muons.TrkIsoDef=0.5
conf.XCleaning.Muons.CombIsoDef=0.5
conf.XCleaning.Electrons.PtCut=3.
conf.XCleaning.Electrons.TrkIsoDef=1.
conf.XCleaning.Electrons.CombIsoDef=1.

conf.print_out()
# Here we define a sample to use
# The path and the filename are separate so you can easily move to using
# local samples.
qcd_test=PSet(
	Name="QCD_Dijet_380_470",
	File="/home/alex/Research/Samples/ICF/QCDJets_pt30_N.root",
        CrossSection=0.2,
	Format=("ICF",2)
)

# Create the analysis
a=Analysis("Demo")

mu=CustomIsoCut(1.,1.,1.)
elr=LeptonReflect()
eli=CustomIsoCut(1.,1.,1.)
met=DoubleMET()
a.AddMuonFilter("PreCC",mu)
a.AddElectronFilter("PreCC",elr)
a.AddElectronFilter("PreCC",eli)
a.AddMETFilter("pfMET", met)
# Define some custom collections which we can plug into our analysis
dc=DemoCompute()
gm=GenMuons()

# Plug them into the analysis
a.AddUserVar("MyJets",dc)
a.AddUserVar("GenMuons",gm)

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")

# Initialise our operations
dijet=OP_NumComJets(">=",2)
trijet=OP_NumComJets(">=",3)
plot2=OP_KinSuiteComPlot("plot2",10,2)
plot3=OP_KinSuiteComPlot("plot3",10,2)
demoop=DemoOp()

# Add the tree to our analysis
a+=tree
tree.Attach(dijet)
tree.TAttach(dijet,plot2)
tree.Attach(trijet)
tree.TAttach(trijet,plot3)
tree.TAttach(plot3,demoop)

# Define the list of samples to run over
s=[qcd_test]
a.Run("../results",conf,s)
