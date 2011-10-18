#!/usr/bin/env python
#
# Vector Boson Taskforce muon ID implementation for RA1
#========================================================================================
#
# "Tight" ID is identified with the "tight" of CMS AN AN-10-116.
#
# Further details here:
# * CMS AN-2010/116 "Measurements of Inclusive W and Z Cross Sections in pp Collisions..."
#
# Notes:
# * A few variables need the 38 ntuples (pixel hits, number of chambers).

from icf.core import PSet

vbtfmuonidps = PSet(
    Verbose = False,
    LooseCuts = PSet(
        #ID variables
        RequireTrackerMuon = False,
        RequireGlobalMuon  = True,
        ChiSquaredCut = 999999.,
        NumChambersCut = 0,
        NumGlobalHits = 0,
        NumTrackerHits = 0,
        NumPixelHits = 0,
        DxyCut = 9999999.,
        ),#end of LooseCuts
    TightCuts = PSet(
        #ID variables
        RequireTrackerMuon = True,
        RequireGlobalMuon  = True,
        ChiSquaredCut = 10.0,
        NumChambersCut = 2,
        NumGlobalHits = 1,
        NumTrackerHits = 10,
        NumPixelHits = 1,
        DxyCut = 0.2, #it's in cm, right? This should be 2mm.
        ),#end of TightCuts
    )#end of VBTF electron ID PSet
