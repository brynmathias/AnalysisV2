#!/usr/bin/env python

import setupSUSY

# Import core framework library and the topSusy library
from libFrameworkSUSY import *
from libTopSusy       import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet, Analysis

# This is the default configuration
from icf.config import defaultConfig

# import default configuration
conf = defaultConfig

jet50U = PSet(
  MinNJets    =  1,
  MinJetPt    = 15.0,
  InitTrigBit = "",
  EffTrig = PSet(
    bit1 = "HLT_Jet50U",
    bit2 = "",
    bit3 = "",
    bit4 = "",
    bit5 = "",
    bit6 = "",
    bit7 = "",
  )
)

diJetAve30U = PSet(
  MinNJets    =  2,
  MinJetPt    = 15.0,
  InitTrigBit = "",
  EffTrig = PSet(
    bit1 = "HLT_DiJetAve30U",
    bit2 = "",
    bit3 = "",
    bit4 = "",
    bit5 = "",
    bit6 = "",
    bit7 = "",
  )
)

quadJet15U = PSet(
  MinNJets    =  4,
  MinJetPt    = 15.0,
  InitTrigBit = "",
  EffTrig = PSet(
    bit1 = "HLT_QuadJet15U",
    bit2 = "",
    bit3 = "",
    bit4 = "",
    bit5 = "",
    bit6 = "",
    bit7 = "",
  )
)

# Define samples
collisions = PSet(
  Name         = "collisions",
  File         = "/tmp/weinberg/SusyCAF_nTuple_1_collisions.root",  # on pcwiscms08
  Weight       = 1.0,
  Format       = ("ICF", 2)
)

minBiasMc = PSet(
  Name         = "minBiasMc",
  File         = "/tmp/weinberg/SusyCAF_nTuple_1_minBiasMc.root",  # on pcwiscms08
  Weight       = 1.0,
  Format       = ("ICF", 2)
)

# Create the analysis
a = Analysis("JetTrigger")

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")

jt_jet50U      = JetTriggerSelector("jet50U",      jet50U.ps())
jt_diJetAve30U = JetTriggerSelector("diJetAve30U", diJetAve30U.ps())
jt_quadJet15U  = JetTriggerSelector("quadJet15U",  quadJet15U.ps())

# Add the tree to our analysis
a += tree

tree.Attach(jt_jet50U)
tree.Attach(jt_diJetAve30U)
tree.Attach(jt_quadJet15U)

# Define the list of samples to run over
s = [collisions, minBiasMc]
a.Run("../results", conf, s)
