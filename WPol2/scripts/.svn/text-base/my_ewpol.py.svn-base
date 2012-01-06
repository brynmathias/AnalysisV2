#!/usr/bin/env python
import setupSUSY

### CONFIGURATION ###
# Which corrections?
ecal_transparency_corrections_version = "38" # "39"
# Output to
output_path = "./results"
# Use tight electron ID (WP70)?
use_tight_ele_id = False
use_loose_ele_id = False
#####################

import libFrameworkSUSY as fwk
import libWPol as wpol

from ewpol.eWPolConfig import ewpol_conf, loose_id, tight_id
from icf.core import PSet, Analysis

conf = ewpol_conf.copy()

conf.Ntuple.Jets.Prefix = "ak5JetPF2PAT"
conf.Ntuple.SecJets.Prefix = "ak5JetPF"
conf.Ntuple.TerJets.Prefix = "nothanks"
conf.Common.Electrons.PtCut = 0

a = Analysis("eWPol")

jet_dr = wpol.EleJetDRFilter(0.3)
loose_ele_id = wpol.CustomEleId(loose_id.ps())
tight_ele_id = wpol.CustomEleId(tight_id.ps())

ecal_filter = wpol.ECALTransparencyCorrections(
	PSet(
		CorrectionsVersion = ecal_transparency_corrections_version,
		ApplyAsCorrection = True,
		ApplySystematics = False,
                SystematicsShift = 0.0
			).ps())

if use_tight_ele_id:
     a.AddElectronFilter("PostCC", tight_ele_id)
if use_loose_ele_id:
     a.AddElectronFilter("PostCC", loose_ele_id)

a.AddJetFilter("PostCC", jet_dr)
a.AddElectronFilter("PostCC", ecal_filter)

print "Creating standard analysis"

t = fwk.Tree("eWPol")

### ADD YOUR OPS HERE ###

# t.Attach(my_op)


#########################


### DEFINE YOUR SAMPLES HERE ###
samples = [

]
################################

a += t



a.Run(output_path, conf, samples)

