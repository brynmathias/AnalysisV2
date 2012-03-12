#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
from batchGolden import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
#  Change the settings from golden to use the lowest scaled bin.
default_common.Jets.PtCut=50.*(275./375.)
cutTree,blah = MakeDataTree(100.*(275./375.), Muon = None)
print cutTree

def addCutFlowData(a) :
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a.AddMuonFilter("PreCC",vbtfMuonId_cff)
  a+=cutTree

# AK5 Calo

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)


from data.Run2011.HT_Run2011AB import *

outDir = "../results_FullCutFlow_"+strftime("%d_%b")+"//Data37"
ensure_dir(outDir)
from htRemake import *
# HT42_incomplete.LastEntry = 100
# HT42_incomplete.File = HT42_incomplete.File[0:1]
#HT_Run2011AB.File = ["/home/hep/db1110/public_html//Darren_And_Bryn_Sync/Had_Skim.root"]
anal_ak5_caloData.Run(outDir,conf_ak5_caloData,[HT_Run2011A_05Aug2011_v1_V15_04_00_jetCorrections_L1FastJet_L2Relative_L3Absolute_L2L3Residual_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1])

