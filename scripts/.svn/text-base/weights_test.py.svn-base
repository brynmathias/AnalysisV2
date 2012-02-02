#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *

from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig

# This imports our demo sample
import samples.icf_demo as icf

# import default configuration
conf=defaultConfig

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Common.Jets.EtCut=5.

qcd_test=PSet(
    Name="QCD Test",
    File="/home/alex/Research/Samples/ICF/LM0.root",
    Weights=PSet(
        CrossSection =  [ 11.5 , 10.2 , 3.1  ],
        Events       =  [ 100  , 200  , 300  ],
        PtBin        =  [ 100. , 200. , 300. ]
        ),
    Format=("ICF",2)
)

# Create the analysis
a=Analysis("WeightsTest")

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
s=[qcd_test]
a.Run("../results",conf,s)
