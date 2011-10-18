#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *

from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig

# import default configuration
conf=defaultConfig

# Create the analysis
a=Analysis("Demo")

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

chain=PSet(
    Name="Chain",
    File=["/home/alex/Research/Samples/ICF/SusyCAF_Tree_4_1.root",
          "/home/alex/Research/Samples/ICF/SusyCAF_Tree_4_1.root"],
    Format=("ICF",2)
)

s=[chain]
a.Run("../results",conf,s)
