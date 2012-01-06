#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libSSDL import *


# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig 

# This imports the standard set of samples
# There are none atm :-(
from icf.samples import *

# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Common.Jets.EtCut=10.

#ELECTRON SELECTION
conf.Common.Electrons.PtCut=5.
conf.Common.Electrons.TrkIsoCut=3.

conf.Common.Muons.PtCut=5.
conf.Common.Muons.EtaCut=2.1
# Here we define a sample to use
# The path and the filename are separate so you can easily move to using
# local samples.
qcd_test=PSet(
	Name="lm0",
        File="/data/pioppi/work/susy/v6/SLpt5/LM0_229_PATV5_NT7_whyntie.root",
        CrossSection=110.,
     #   LastEntry=9715
)


# Create the analysis
a=Analysis("lm0")

# Define some custom collections which we can plug into our analysis
#dc=DemoCompute()
#gm=GenMuons()

# Plug them into the analysis
#a.AddUserVar("MyJets",dc)
#a.AddUserVar("GenMuons",gm)

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger



Trigger=PSet(
       McAnal =0.,
       TriggerBits=PSet(
         bit1=30,
         bit2=0,
         bit3=0,
         bit4=0,
         bit5=0,
         bit6=0,
         bit7=0,
         bit8=0,
         bit9=0,
         bit10=0
         )
       )

ssdlTrigg=SSDLTrigger("Trigger",Trigger.ps())

Selection=PSet(
    SSMHTCut= 50.,
    SSHTCut=350.,
    LeptonCut =1.,
    BkgAnal =0.

    )

ssdlSelec=SSDLSelection("Selection",Selection.ps())

TTEval=PSet(
    McAnal =1.,    
    )

ttEval=TTBkgEval("TTEval",TTEval.ps())
# Add the tree to our analysis
a+=ssdlTrigg
a+=ssdlSelec

s=[qcd_test]
a.Run(".",conf,s)
