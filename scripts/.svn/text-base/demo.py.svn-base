#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
#from libOneLepton import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig

# This imports our demo sample
from montecarlo.LMsignal38 import LM0_SUSY_sftsht_7TeV_pythia6_Fall10_START38_V12_v1

# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Common.Jets.EtCut=5.

# Create the analysis
a=Analysis("Demo")

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")

# Initialise our operations
dijet=OP_NumComJets(">=",2)
trijet=OP_NumComJets(">=",3)
plot2=OP_KinSuiteComPlot("plot2",10,2)
plot3=OP_KinSuiteComPlot("plot3",10,2)

# Add the tree to our analysis
a+=tree
tree.Attach(dijet)
tree.TAttach(dijet,plot2)
tree.Attach(trijet)
tree.TAttach(trijet,plot3)

# Define the list of samples to run over
s=[LM0_SUSY_sftsht_7TeV_pythia6_Fall10_START38_V12_v1]
a.Run("../results",conf,s)
