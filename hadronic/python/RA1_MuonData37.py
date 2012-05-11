#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from libOneLepton import *
from icf.core import PSet,Analysis
from time import strftime
from time import strftime
from batchGolden_baseline import *

from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
CustomMuID = OL_CustomVBTFMuID(mu_id_lower.ps())
default_common.Jets.PtCut=50.*(275./375.)
cutTree,blah,l = MakeDataTree(100.*(275./375.), Muon = True)



def addCutFlowData(a) :
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a.AddMuonFilter("PreCC",CustomMuID)
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
from data.Run2011.MuHad_Run2011AB import *
from HT_L1OffSet import *
#outdir = "../results_"+strftime("%d_%b")+"//MuonData37"

outdir = "../results_"+strftime("%d_%b")+"/MuonData37/"
ensure_dir(outdir)

anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[HT_L1OffSet])#HT_Run2011A])
#anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[HT_Run2011AB])
#anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[MuHad2011AB])
