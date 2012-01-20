from icf.core import PSet
import os, commands

AlgorithmsPSet = PSet(
    
    # Binning
    UseMeff = False,
    Nbins = 3,
    Low = 250.,
    High = 400.,
    Scale = True,

    # Analysis cuts
    MinJetPt1 = 100.,
    MinJetPt2 = 100.,
    MinJetPt3 = 50.,
    MaxLeadingJetEta = 2.5,
    MinVertexSumPtOverHt = 0.1,
    MaxBaby = 1.25,

    # Dead ECAL regions
    UseFile = False,
    DeadEcalFile = commands.getoutput('echo $SUSY_WORKING_SW_DIR')+"/hadronic/python/deadRegionList_START38_V12.txt",
    MinBabyJetPt = 30.,
    nBadCells = 0,
    MaxBiasDeltaPhi = 0.5,
    MaxDrToDeadEcalRegion = 0.3,
    
    )
