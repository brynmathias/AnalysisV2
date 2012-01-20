#!/usr/bin/env python
import setupSUSY
from ewpol.eWPolHelpers import eWPol
from ewpol.eWPolConfig import ewpol_conf, loose_id, tight_id
from icf.core import Analysis, PSet
import icf.utils as utils
import icf.types as types
import glob

import libFrameworkSUSY as fwk

# Global configuration
data = False
mc_int_lumi = 10.

conf = ewpol_conf.copy()
e = eWPol(data, loose_id, tight_id)
a = Analysis("eWPol", )
e.installFilters(a)
e.buildTree()

skim = fwk.SkimOp( PSet(
         SkimName = "eWPol_MHT50Skim",
         DropBranches = False,
         Branches = types.StringVector([])
         ).ps() )

e.tree.TAttach(e.ops[len(e.ops)-1][1], skim)

a += e.tree

lm0 = PSet(
    Name = "LM0",
    Format = ("ICF", 2),
    File = glob.glob("/home/alex/Research/Samples/ICF/LM0/SusyCAF*.root")
)

samples = [lm0]
utils.reweight(samples, mc_int_lumi)
a.Run("../results", conf, samples)
