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
from icf.utils import json_to_pset

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
selection = OP_GoodEventSelection()
json = JSONFilter("Alex's JSON", json_to_pset("../Cert_160404-161216_7TeV_PromptReco_Collisions11_JSON.txt", True))
dijet=OP_NumComJets(">=",2)
trijet=OP_NumComJets(">=",3)
plot2=OP_KinSuiteComPlot("plot2",10,2)
plot3=OP_KinSuiteComPlot("plot3",10,2)

# Add the tree to our analysis
a+=tree
tree.Attach(selection)
tree.TAttach(selection, json)
tree.TAttach(json, dijet)
tree.TAttach(dijet,plot2)
tree.Attach(trijet)
tree.TAttach(trijet,plot3)

# Define the list of samples to run over
s=[LM0_SUSY_sftsht_7TeV_pythia6_Fall10_START38_V12_v1]

samp = PSet(
  Name = "HTblah",
  File = "/vols/cms02/bainbrid/qcd/data/HT_Run2011A_PromptReco_v1.root",
  Format = ("ICF", 3)
)


from data.Run2011.HT_Run2011A_PromptReco_v1 import HT_Run2011A_PromptReco_v1
HT_Run2011A_PromptReco_v1.File = [f.replace("store/user","store/user_old") for f in HT_Run2011A_PromptReco_v1.File]
HT_Run2011A_PromptReco_v1.File = HT_Run2011A_PromptReco_v1.File[1:10]
#s = [samp]
s= [ HT_Run2011A_PromptReco_v1 ]
a.Run("../results",conf,s)
