#!/usr/bin/env python
#
# Vector Boson Taskforce electron ID implementation for RA1
#========================================================================================
#
# Here, "Loose" ID is identified with WP95 of the EWK Vector Boson Task Force (VBTF)
# while "Tight" ID is identified with WP80 of the same specification.
#
# Further details here:
# * CMS AN-2010/116 "Measurements of Inclusive W and Z Cross Sections in pp Collisions..."
# * https://twiki.cern.ch/twiki/bin/view/CMS/SimpleCutBasedEleID
#
# Notes:
# * There are different cut values for Barrel and Endcap electrons.
# * Electrons falling into the Barrel-Endcap "transition region" are IDed as non-Loose.
# * The eta values corresponding to these regions are hard-coded into the IDFilter
#   and decisions are made on the fly.

from icf.core import PSet

vbtfelectronidWP95ps = PSet(
    Verbose = False,
    UseCombinedIsolation = True,
    LooseCuts = PSet(
        #isolation
        TrkIso = PSet(
            B = 0.15, #WP95
            E = 0.08, #WP95
            ),
        EclIso = PSet(
            B = 2.0,  #WP95
            E = 0.06, #WP95
            ),
        HclIso = PSet(
            B = 0.12, #WP95
            E = 0.05, #WP95
            ),
        CmbIso = PSet(
            B = 0.15, #WP95
            E = 0.10, #WP95
            ),
        #conversion rejection
        ConversionNumHits = PSet(
            B = 1, #WP95
            E = 1, #WP95
            ),
        ConversionDcot = PSet(
            B = 0.0, #n/a - WP95
            E = 0.0, #n/a - WP95
            ),
        ConversionDist = PSet(
            B = 0.0, #n/a - WP95
            E = 0.0, #n/a - WP95
            ),
        #ID variables
        SigmaIEtaIEtaCut = PSet(
            B = 0.01, #WP95
            E = 0.03, #WP95
            ),
        DeltaPhiAtVertexCut = PSet(
            B = 0.8, #WP95
            E = 0.7, #WP95
            ),
        DeltaEtaAtVertexCut = PSet(
            B = 0.007, #WP95
            E = 0.01,  #WP95
            ),
        HcalOverEcalCut = PSet(
            B = 0.15, #WP95
            E = 0.07, #WP95
            ),
        ),#end of LooseCuts
    TightCuts = PSet( #taken from WP80, CMS AN AN-2010-116 (W/Z note)
        #isolation
        TrkIso = PSet(
            B = 0.09,
            E = 0.04,
            ),
        EclIso = PSet(
            B = 0.07,
            E = 0.05,
            ),
        HclIso = PSet(
            B = 0.10,
            E = 0.025,
            ),
        CmbIso = PSet(
            B = 0.07,# not used in WP80
            E = 0.06,# not used in WP80
            ),
        #conversion rejection
        ConversionNumHits = PSet(
            B = 0,
            E = 0,
            ),
        ConversionDcot = PSet(
            B = 0.02, #EWK WP80
            E = 0.02, #EWK WP80
            ),
        ConversionDist = PSet(
            B = 0.02, #EWK WP80
            E = 0.02, #EWK WP80
            ),
        #ID variables
        SigmaIEtaIEtaCut = PSet(
            B = 0.01, #EWK WP80
            E = 0.03, #EWK WP80
            ),
        DeltaPhiAtVertexCut = PSet(
            B = 0.06, #EWK WP80
            E = 0.03, #EWK WP80
            ),
        DeltaEtaAtVertexCut = PSet(
            B = 0.004, #EWK WP80
            E = 0.007, #EWK WP80
            ),
        HcalOverEcalCut = PSet(
            B = 0.04,  #EWK WP80
            E = 0.025, #EWK WP80
            ),
        ),#end of TightCuts
    )#end of VBTF electron ID PSet

vbtfelectronidWP90ps = PSet(
    Verbose = False,
    UseCombinedIsolation = True,
    LooseCuts = PSet(
        #isolation
        TrkIso = PSet(
            B = 0.12, #WP90; #0.15, #WP95
            E = 0.05, #WP90; #0.08, #WP95
            ),
        EclIso = PSet(
            B = 0.09, #WP90; #2.0,  #WP95
            E = 0.06, #WP90; #0.06, #WP95
            ),
        HclIso = PSet(
            B = 0.10, #WP90; #0.12, #WP95
            E = 0.03, #WP90; #0.05, #WP95
            ),
        CmbIso = PSet(
            B = 0.10, #WP90; #999999.,#not used in WP95
            E = 0.07, #WP90; #0.1, #WP95
            ),
        #conversion rejection
        ConversionNumHits = PSet(
            B = 1, #WP90; #1, #WP95
            E = 1, #WP90; #1, #WP95
            ),
        ConversionDcot = PSet(
            B = 0.02, #WP90; #0.0, #n/a - WP95
            E = 0.02, #WP90; #0.0, #n/a - WP95
            ),
        ConversionDist = PSet(
            B = 0.02, #WP90; #0.0, #n/a - WP95
            E = 0.02, #WP90; #0.0, #n/a - WP95
            ),
        #ID variables
        SigmaIEtaIEtaCut = PSet(
            B = 0.01, #WP90; #0.01, #WP95
            E = 0.01, #WP90; #0.03, #WP95
            ),
        DeltaPhiAtVertexCut = PSet(
            B = 0.8, #WP90; #0.8, #WP95
            E = 0.8, #WP90; #0.7, #WP95
            ),
        DeltaEtaAtVertexCut = PSet(
            B = 0.007, #WP90; #0.007, #WP95
            E = 0.009, #WP90; #0.01,  #WP95
            ),
        HcalOverEcalCut = PSet(
            B = 0.12, #WP90; #0.15, #WP95
            E = 0.05, #WP90; #0.07, #WP95
            ),
        ),#end of LooseCuts
    TightCuts = PSet( #taken from WP80, CMS AN AN-2010-116 (W/Z note)
        #isolation
        TrkIso = PSet(
            B = 0.09,
            E = 0.04,
            ),
        EclIso = PSet(
            B = 0.07,
            E = 0.05,
            ),
        HclIso = PSet(
            B = 0.10,
            E = 0.025,
            ),
        CmbIso = PSet(
            B = 999999.,# not used in WP80
            E = 999999.,# not used in WP80
            ),
        #conversion rejection
        ConversionNumHits = PSet(
            B = 0,
            E = 0,
            ),
        ConversionDcot = PSet(
            B = 0.02, #EWK WP80
            E = 0.02, #EWK WP80
            ),
        ConversionDist = PSet(
            B = 0.02, #EWK WP80
            E = 0.02, #EWK WP80
            ),
        #ID variables
        SigmaIEtaIEtaCut = PSet(
            B = 0.01, #EWK WP80
            E = 0.03, #EWK WP80
            ),
        DeltaPhiAtVertexCut = PSet(
            B = 0.06, #EWK WP80
            E = 0.03, #EWK WP80
            ),
        DeltaEtaAtVertexCut = PSet(
            B = 0.004, #EWK WP80
            E = 0.007, #EWK WP80
            ),
        HcalOverEcalCut = PSet(
            B = 0.04,  #EWK WP80
            E = 0.025, #EWK WP80
            ),
        ),#end of TightCuts
    )#end of VBTF electron ID PSet
