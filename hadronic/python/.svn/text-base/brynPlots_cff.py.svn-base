#!/usr/bin/env python

"""
Plot settings for Bryn's plotting operations.
"""

from libbryn import *

from icf.core import PSet

from copy import deepcopy

#plot configuration
pset_2om = PSet(
    DirName       = "250_infGev_2om",
    MinObjects    = 2,
    MaxObjects    = 15,
    StandardPlots = True,
    )

pset_2eq = PSet(
    DirName       = "250_infGev_2eq",
    MinObjects    = 2,
    MaxObjects    = 2,
    StandardPlots = True,
    )

pset_3om = PSet(
    DirName       = "250_infGev_3om",
    MinObjects    = 3,
    MaxObjects    = 15,
    StandardPlots = True,
    )

#control region 1
pset250_300_2om = deepcopy(pset_2om)
pset250_300_2om.DirName = "250_300Gev_2om"
#
pset250_300_2eq = deepcopy(pset_2eq)
pset250_300_2eq.DirName = "250_300Gev_2eq"
#
pset250_300_3om = deepcopy(pset_3om)
pset250_300_3om.DirName = "250_300Gev_3om"

#control region 2
pset300_350_2om = deepcopy(pset_2om)
pset300_350_2om.DirName = "300_350Gev_2om"
#
pset300_350_2eq = deepcopy(pset_2eq)
pset300_350_2eq.DirName = "300_350Gev_2eq"
#
pset300_350_3om = deepcopy(pset_3om)
pset300_350_3om.DirName = "300_350Gev_3om"


#signal region (HT>350GeV) after cuts
#post-deadECAL cut
pset350plus_afterDeadEcal_2om = deepcopy(pset_2om)
pset350plus_afterDeadEcal_2om.DirName = "350GeV_afterDeadEcal_2om"
#
pset350plus_afterDeadEcal_2eq = deepcopy(pset_2eq)
pset350plus_afterDeadEcal_2eq.DirName = "350GeV_afterDeadEcal_2eq"
#
pset350plus_afterDeadEcal_3om = deepcopy(pset_3om)
pset350plus_afterDeadEcal_3om.DirName = "350GeV_afterDeadEcal_3om"

#after all cuts
pset350plus_afterAllCuts_2om = deepcopy(pset_2om)
pset350plus_afterAllCuts_2om.DirName = "350GeV_afterAllCuts_2om"
#
pset350plus_afterAllCuts_2eq = deepcopy(pset_2eq)
pset350plus_afterAllCuts_2eq.DirName = "350GeV_afterAllCuts_2eq"
#
pset350plus_afterAllCuts_3om = deepcopy(pset_3om)
pset350plus_afterAllCuts_3om.DirName = "350GeV_afterAllCuts_3om"


#plot operations
#attach after >250GeV cut
plotGtHT250_2om = WeeklyUpdatePlots(pset_2om.ps())
plotGtHT250_2eq = WeeklyUpdatePlots(pset_2eq.ps())
plotGtHT250_3om = WeeklyUpdatePlots(pset_3om.ps())

#attach after 250GeV < HT < 300GeV && dead ecal:
plotHT250_300_deadECAL_2om = WeeklyUpdatePlots(pset250_300_2om.ps())
plotHT250_300_deadECAL_2eq = WeeklyUpdatePlots(pset250_300_2eq.ps())
plotHT250_300_deadECAL_3om = WeeklyUpdatePlots(pset250_300_3om.ps())

#attach after 300GeV < HT < 350GeV && dead ecal:
plotHT300_350_deadECAL_2om = WeeklyUpdatePlots(pset300_350_2om.ps())
plotHT300_350_deadECAL_2eq = WeeklyUpdatePlots(pset300_350_2eq.ps())
plotHT300_350_deadECAL_3om = WeeklyUpdatePlots(pset300_350_3om.ps())

#attach after HT > 350GeV && dead ecal
plotGtHT350_deadECAL_2om = WeeklyUpdatePlots(pset350plus_afterDeadEcal_2om.ps())
plotGtHT350_deadECAL_2eq = WeeklyUpdatePlots(pset350plus_afterDeadEcal_2eq.ps())
plotGtHT350_deadECAL_3om = WeeklyUpdatePlots(pset350plus_afterDeadEcal_3om.ps())

#attach after MHT/MET && dead Ecal && 350GeV (all cuts)
plotGtHT350_AfterAllCuts_2om = WeeklyUpdatePlots(pset350plus_afterAllCuts_2om.ps())
plotGtHT350_AfterAllCuts_2eq = WeeklyUpdatePlots(pset350plus_afterAllCuts_2eq.ps())
plotGtHT350_AfterAllCuts_3om = WeeklyUpdatePlots(pset350plus_afterAllCuts_3om.ps())
