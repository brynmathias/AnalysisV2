#!/usr/bin/env python
#
# RA3 photon ID implementation for RA1
#========================================================================================
#
# Here, "Loose" ID is identified with "isLoose"
# while "Tight" ID is identified with "isTight".
#
# Note there is no requirement on hasPixelSeed - yet...
#
# Further details here:
# * https://twiki.cern.ch/twiki/bin/view/CMS/PhotonID
#
# Notes:
# * There are different cut values for Barrel and Endcap photons.
# * The eta values corresponding to these regions are hard-coded into the IDFilter
#   and decisions are made on the fly.

from icf.core import PSet

ra3photonidps = PSet(
    Verbose = False,
    LooseCuts = PSet(
        #isolation
        TrkIsoC = PSet(
            B = 3.5,
            E = 3.5,
            ),
        TrkIsoB = PSet(
            B = 0.001,
            E = 0.001,
            ),
        EclIsoC = PSet(
            B = 4.2,
            E = 4.2,
            ),
        EclIsoB = PSet(
            B = 0.006,
            E = 0.006,
            ),
        HclIsoC = PSet(
            B = 2.2,
            E = 2.2,
            ),
        HclIsoB = PSet(
            B = 0.0025,
            E = 0.0025,
            ),
        #ID variables
        SigmaIEtaIEtaCut = PSet(
            B = 999999.,
            E = 999999.,
            ),
        HcalOverEcalCut = PSet(
            B = 0.05,
            E = 0.05,
            ),
        RequireNoPixelSeed = True
        ),#end of LooseCuts
    TightCuts = PSet(
        #isolation
        TrkIsoC = PSet(
            B = 2.0,
            E = 2.0,
            ),
        TrkIsoB = PSet(
            B = 0.001,
            E = 0.001,
            ),
        EclIsoC = PSet(
            B = 4.2,
            E = 4.2,
            ),
        EclIsoB = PSet(
            B = 0.006,
            E = 0.006,
            ),
        HclIsoC = PSet(
            B = 2.2,
            E = 2.2,
            ),
        HclIsoB = PSet(
            B = 0.0025,
            E = 0.0025,
            ),
        #ID variables
        SigmaIEtaIEtaCut = PSet(
            B = 0.013,
            E = 0.030,
            ),
        HcalOverEcalCut = PSet(
            B = 0.05,
            E = 0.05,
            ),
        RequireNoPixelSeed = True
        ),#end of TightCuts
    )#end of VBTF electron ID PSet
