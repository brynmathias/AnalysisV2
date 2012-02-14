#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from liballhadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from icf.utils import json_to_pset
from copy import deepcopy
import commands

pwd = commands.getoutput('echo $SUSY_WORKING_SW_DIR')
output_dir = pwd + "/results/v07"

default_ntuple = deepcopy(defaultConfig.Ntuple)
default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_common = deepcopy(defaultConfig.Common)
default_common.ApplyXCleaning=False

conf_ak5_calo = deepcopy(defaultConfig)
conf_ak5_calo.Ntuple = deepcopy(default_ntuple)
conf_ak5_calo.XCleaning = deepcopy(default_cc)
conf_ak5_calo.Common = deepcopy(default_common)

genpthat = GenPtHat( PSet(DirName = "QcdBkgdEst").ps() )
cut_flow = Tree("Test")
cut_flow.Attach(genpthat)

anal=Analysis("TEST")
anal+=cut_flow

from allhadronic.Summer11 import *
dataset = qcdpy1800
#dataset.LastEntry = 10000
#dataset.print_out()

anal.Run(output_dir,conf_ak5_calo,[dataset])
#anal.Run(".",conf_ak5_calo,[dataset])

