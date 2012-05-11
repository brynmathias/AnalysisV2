#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
#from libbryn import *
from libHadronic import *
from libOneLepton import *
from icf.core import PSet,Analysis
from time import strftime
from time import strftime
from batchGolden_singlemu import *

from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
CustomMuID = OL_CustomVBTFMuID(mu_id_eta_2_1.ps())
cutTree,blah,blah2,l = MakeDataTree(100., Muon = True, Split = "Muon_One")

def addCutFlowData(b) :
  b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  b.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  b.AddMuonFilter("PreCC",CustomMuID)
  b+=cutTree

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
#from HT_L1OffSet import *
#from MuHad_L1OffSet import *

outdir = "../../results_"+strftime("%d_%b")+"/MuonData/"

ensure_dir(outdir)

#HT_Run2011AB.File = HT_Run2011AB.File[:10]
#anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[MuHad2011AB])#HT_Run2011A])
#anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[MuHad_L1OffSet])
anal_ak5_caloData.Run(outdir,conf_ak5_caloData,switches()["data_samples"][1])

