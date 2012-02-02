#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
import libOneLepton as one
import libWPol as wpol
from copy import deepcopy
from icf.core import PSet,Analysis

# The leptonic specicif settings&files
from onelepton_settings import *
from onelepton_MC_samples import *
from onelepton.filters import metScaleSystematic, vertexReweighting, metResolutionSystematic

syst_ps = PSet(
    Polarisation = True,
    Lepton = "Muon",
    METResolution = True
    )
syst_plots = one.SystematicsPlots("Systematics", syst_ps.ps())

syst = Analysis("Systematics")
tree = Tree("Main")
syst += tree

tree.Attach(syst_plots)

syst.Run("./systematics", conf, samplesMC)


