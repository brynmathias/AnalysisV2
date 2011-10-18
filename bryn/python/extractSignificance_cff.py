#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from bkgdCore import BkgdAnalysis
from copy import deepcopy
from icf.core import PSet

from bkgdEst_cfi import defaultBkgdConfig

default_samples = deepcopy(defaultBkgdConfig.Samples)



default_samples=PSet(
    plotName="BkgdEstPlots_g2jets/alphaT_vs_etaLeading_HT_",
    outputDir="somewhere",
    Signal="results/IC5Calo_LM1.root",
    Background=PSet(
    Zinv="results/IC5Calo_Zinv.root",
    Zjets="results/IC5Calo_ZJets.root",
    Wjets="results/IC5Calo_WJets.root",
    QCD="results/IC5Calo_QCD_Pythia_Merged.root",
    )
    )
  

default_cuts = deepcopy(defaultBkgdConfig.Cuts)
default_cuts=PSet(
    signalLow=0.55,
    signalUp=-1.,
    bkgdLow=0.,
    bkgdUp=0.55,
    nBinVar1=3,
    rebinX=1,
    )



                         
BkgdAnalysis = BkgdAnalysis("bkgdAnalysis")

BkgdAnalysis.Run(default_cuts,default_samples)

