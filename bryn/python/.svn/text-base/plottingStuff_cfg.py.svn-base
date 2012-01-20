
#!/usr/bin/env python
"""
plottingStuff_cfg.py

Created by Tanja Rommerskirchen 13.10.10
"""

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy
from icf.JetCorrections import *





mSuGraScanPlots_beforeAll_pset = PSet(DirectoryName = "mSuGraScan_beforeAll")

#mSuGra scan plots
mSuGraScanPlots_before_150_pset = PSet(DirectoryName = "mSuGraScan_before_150")
mSuGraScanPlots_before_250_pset = PSet(DirectoryName = "mSuGraScan_before_250")
mSuGraScanPlots_before_350_pset = PSet(DirectoryName = "mSuGraScan_before_350")

mSuGraScanPlots_150_pset = PSet(DirectoryName = "mSuGraScan_150")
mSuGraScanPlots_250_pset = PSet(DirectoryName = "mSuGraScan_250")
mSuGraScanPlots_350_pset = PSet(DirectoryName = "mSuGraScan_350")

#Bkgd Estimation Plots

TanjaBkgdEstPlots_g1jets = PSet(DirectoryName = "BkgdEstPlots_g1jets",
                         MinObjects=2,
                         MaxObjects=9,
                         m0_felder=0,
                         m12_felder=0
                         )
plots_bkgdEstPlots_g1jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g1jets.ps() )

TanjaBkgdEstPlots_2jets = PSet(DirectoryName = "BkgdEstPlots_2jets",
                         MinObjects=2,
                         MaxObjects=2,
                         m0_felder=0,
                         m12_felder=0
                         )
plots_bkgdEstPlots_2jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_2jets.ps() )

TanjaBkgdEstPlots_g2jets = PSet(DirectoryName = "BkgdEstPlots_g2jets",
                         MinObjects=3,
                         MaxObjects=7,
                         m0_felder=0,
                         m12_felder=0 
                         )
plots_bkgdEstPlots_g2jets = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g2jets.ps() )

TanjaBkgdEstPlots_g1jets_MSUGRA = PSet(DirectoryName = "BkgdEstPlots_g1jets",
                         MinObjects=2,
                         MaxObjects=9,
                         m0_felder=80,
                         m12_felder=25
                         )
plots_bkgdEstPlots_g1jets_MSUGRA = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g1jets_MSUGRA.ps() )

TanjaBkgdEstPlots_2jets_MSUGRA = PSet(DirectoryName = "BkgdEstPlots_2jets",
                         MinObjects=2,
                         MaxObjects=2,
                         m0_felder=80,
                         m12_felder=25
                         )
plots_bkgdEstPlots_2jets_MSUGRA = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_2jets_MSUGRA.ps() )

TanjaBkgdEstPlots_g2jets_MSUGRA = PSet(DirectoryName = "BkgdEstPlots_g2jets",
                         MinObjects=3,
                         MaxObjects=7,
                         m0_felder=80,
                         m12_felder=25 
                         )
plots_bkgdEstPlots_g2jets_MSUGRA = OP_BkgdEstPlottingOps( TanjaBkgdEstPlots_g2jets_MSUGRA.ps() )



plots_mSuGraScan_beforeAll = OP_mSuGraPlottingOps(mSuGraScanPlots_beforeAll_pset.ps())

plots_mSuGraScan_before_150 = OP_mSuGraPlottingOps(mSuGraScanPlots_before_150_pset.ps() )
plots_mSuGraScan_before_250 = OP_mSuGraPlottingOps(mSuGraScanPlots_before_250_pset.ps() )
plots_mSuGraScan_before_350 = OP_mSuGraPlottingOps(mSuGraScanPlots_before_350_pset.ps() )



plots_mSuGraScan_150 = OP_mSuGraPlottingOps(mSuGraScanPlots_150_pset.ps() )
plots_mSuGraScan_250 = OP_mSuGraPlottingOps(mSuGraScanPlots_250_pset.ps() )
plots_mSuGraScan_350 = OP_mSuGraPlottingOps(mSuGraScanPlots_350_pset.ps() )


#Plot the common plots!
pset1 = PSet(
DirName      = "HadronicCommon_1",
MinObjects   = 2,
MaxObjects   = 6,
StandardPlots     = True,
DeadECALPlots = True,
CleaningControlPlots = True,
MECPlots = True,
DeadECALFile = ""
)

pset2 = deepcopy(pset1)
pset2.DirName = "HadronicCommon_2"

pset3 = deepcopy(pset1)
pset3.DirName = "HadronicCommon_3"

pset4 = deepcopy(pset1)
pset4.DirName = "HadronicCommon_4"

HadStandard_1 = HadronicCommonPlots(pset1.ps())
HadStandard_2 = HadronicCommonPlots(pset2.ps())
HadStandard_3 = HadronicCommonPlots(pset3.ps())
HadStandard_4 = HadronicCommonPlots(pset4.ps())


dalitz_plots_Inclusive = HadronicPlottingOps( PSet(
DirName    = "Dalitz_Inclusive",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps() 
)

dalitz_plots_150_250 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_150_250",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps() 
)

dalitz_plots_250_350 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_250_350",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps() 
)

dalitz_plots_350 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_350",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps() 
)





