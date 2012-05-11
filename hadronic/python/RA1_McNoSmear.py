#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
import icf.utils as Utils
from batchGolden_baseline import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *


#JetSmear = JetSmear(0.1,30)
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
#cutTreeMC,junkVar,l = MakeMCTree(100.,Muon = None,Split = "Had_One")
cutTreeMC,junkVar,l = MakeMCTree(100.,Muon = None)

vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
def addCutFlowMC(b) :
  b.AddWeightFilter("Weight", vertex_reweight)
  b.AddMuonFilter("PreCC",vbtfMuonId_cff)
  b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  b.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  b+=cutTreeMC

#AK5 Calo
conf_ak5_caloMC = deepcopy(defaultConfig)
conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
conf_ak5_caloMC.Common = deepcopy(default_common)
conf_ak5_caloMC.Common.print_out()
anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)

outDir = "../results_"+strftime("%d_%b")+"//NoSmear/"
ensure_dir(outDir)

#from CMSSM_Skim import *

#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,[CMSSM_Skim])
anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,Summer11_MC_Higher_Bins)
#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,Btag_Systematic_Samples_Higher)



#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,L1OffSet_MC_Higher_Bins)
