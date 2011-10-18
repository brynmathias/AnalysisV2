#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libOneLepton     import *
from libTopSusy       import *

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet, Analysis

# This is the default configuration
from icf.config import defaultConfig

# import default configuration
conf = defaultConfig

# Import sets of cuts
import cutsTopSusy

# Define sample
lm0 = PSet(
  Name         = "lm0",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM0_229_PATV5_NT7_whyntie.root",
  CrossSection = 22.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd100To250 = PSet(
  Name         = "qcd100To250",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/QCDMG/QCD_MG_HT100to250_229_PATV5_NT7_whyntie.root",
  CrossSection = 3000000.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd250To500 = PSet(
  Name         = "qcd250To500",
  File         = "/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD250to500_NT7.root",
  CrossSection = 80000.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd500To1000 = PSet(
  Name         = "qcd500To1000",
  File         = "/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD500to1000_NT7.root",
  CrossSection = 2800.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

qcd1000ToInf = PSet(
  Name         = "qcd1000ToInf",
  File         = "/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD1000toInf_NT7.root",
  CrossSection = 74.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

ttJets = PSet(
  Name         = "ttJets",
  File         = "/castor/cern.ch/user/n/nsaoulid/TTBAR_V7/TTJets_madgraph_NT7.root",
  CrossSection = 82.8,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

wJets = PSet(
  Name         = "wJets",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/WJetsMG/WJetsMG_229_PATV5_NT7_whyntie.root",
  CrossSection = 9100.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

zJets = PSet(
  Name         = "zJets",
  File         = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/ZJetsMG/ZJetsMG_229_PATV5_NT7whyntie.root",
  CrossSection = 840.0,
  FirstEntry   = 1,
  # LastEntry    = 10,
  Format       = ("NT", 7)
)

firstCollision = PSet(
  Name         = "firstCollision",
  # File         = "/tmp/weinberg/SusyCAF_Tree.root",  # on pcwiscms08
  File         = "/castor/cern.ch/user/a/arlogb/QCDDiJet_Pt380to470_MC_31X_V9_Pat.root",
  FirstEntry   = 1,
  # LastEntry  = 10,
  Format       = ("ICF", 2)
)

# Create the analysis
a = Analysis("TopSusy")

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")

# Initialise our operations
ts_e_4J_tightE_tightMu_looseJ  = TopSusySelector("e_4J_tightE_tightMu_looseJ",  cutsTopSusy.e_4J_tightE_tightMu_looseJ.ps())
ts_mu_4J_tightE_tightMu_looseJ = TopSusySelector("mu_4J_tightE_tightMu_looseJ", cutsTopSusy.mu_4J_tightE_tightMu_looseJ.ps())
ts_e_4J_tightE_tightMu_tightJ  = TopSusySelector("e_4J_tightE_tightMu_tightJ",  cutsTopSusy.e_4J_tightE_tightMu_tightJ.ps())
ts_mu_4J_tightE_tightMu_tightJ = TopSusySelector("mu_4J_tightE_tightMu_tightJ", cutsTopSusy.mu_4J_tightE_tightMu_tightJ.ps())
ts_e_all_tightE_tightMu        = TopSusySelector("e_all_tightE_tightMu",        cutsTopSusy.e_all_tightE_tightMu.ps())
ts_mu_all_tightE_tightMu       = TopSusySelector("mu_all_tightE_tightMu",       cutsTopSusy.mu_all_tightE_tightMu.ps())
ts_ee_tightE_tightMu           = TopSusySelector("ee_tightE_tightMu",           cutsTopSusy.ee_tightE_tightMu.ps())
ts_ee_looseE_tightMu           = TopSusySelector("ee_looseE_tightMu",           cutsTopSusy.ee_looseE_tightMu.ps())
ts_ee_looseE_looseMu           = TopSusySelector("ee_looseE_looseMu",           cutsTopSusy.ee_looseE_looseMu.ps())
ts_emu_tightE_tightMu          = TopSusySelector("emu_tightE_tightMu",          cutsTopSusy.emu_tightE_tightMu.ps())
ts_emu_tightE_looseMu          = TopSusySelector("emu_tightE_looseMu",          cutsTopSusy.emu_tightE_looseMu.ps())
ts_emu_looseE_tightMu          = TopSusySelector("emu_looseE_tightMu",          cutsTopSusy.emu_looseE_tightMu.ps())
ts_emu_looseE_looseMu          = TopSusySelector("emu_looseE_looseMu",          cutsTopSusy.emu_looseE_looseMu.ps())
ts_mumu_tightE_tightMu         = TopSusySelector("mumu_tightE_tightMu",         cutsTopSusy.mumu_tightE_tightMu.ps())
ts_mumu_tightE_looseMu         = TopSusySelector("mumu_tightE_looseMu",         cutsTopSusy.mumu_tightE_looseMu.ps())
ts_mumu_looseE_looseMu         = TopSusySelector("mumu_looseE_looseMu",         cutsTopSusy.mumu_looseE_looseMu.ps())

# Add the tree to our analysis
a += tree

tree.Attach(ts_e_4J_tightE_tightMu_looseJ)
tree.Attach(ts_mu_4J_tightE_tightMu_looseJ)
tree.Attach(ts_e_4J_tightE_tightMu_tightJ)
tree.Attach(ts_mu_4J_tightE_tightMu_tightJ)
tree.Attach(ts_e_all_tightE_tightMu)
tree.Attach(ts_mu_all_tightE_tightMu)
tree.Attach(ts_ee_tightE_tightMu)
tree.Attach(ts_ee_looseE_tightMu)
tree.Attach(ts_ee_looseE_looseMu)
tree.Attach(ts_emu_tightE_tightMu)
tree.Attach(ts_emu_tightE_looseMu)
tree.Attach(ts_emu_looseE_tightMu)
tree.Attach(ts_emu_looseE_looseMu)
tree.Attach(ts_mumu_tightE_tightMu)
tree.Attach(ts_mumu_tightE_looseMu)
tree.Attach(ts_mumu_looseE_looseMu)

# Define the list of samples to run over
s = [lm0, qcd100To250, qcd250To500, qcd500To1000, qcd1000ToInf, ttJets, wJets, zJets]
a.Run("../results", conf, s)
