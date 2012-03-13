#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
import icf.utils as Utils
from batchGolden import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *

default_common.Jets.PtCut=50.*(275./375.)
cutTreeMC, junkVar,l = MakeMCTree(100.*(275./375.),Muon = None)
#JetSmear = JetSmear(0.1,30)
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )

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

outDir = "../results_FullCutFlow_"+strftime("%d_%b")+"//NoSmear37/"
ensure_dir(outDir)


anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,QCD_Summer11_Pythia_All)
# anal_ak5_pfMC.Run(outDir,conf_ak5_pfMC,MC)
# anal_ak5_pfMC.Run("../results_"+strftime("%d_%b_%H")+"//NoSmear",conf_ak5_pfMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak5_jptMC.Run("../results_"+strftime("%d_%b_%H")+"//NoSmear",conf_ak5_jptMC,MC)
# anal_ak5_jptMC.Run("../results_"+strftime("%d_%b_%H")+"//NoSmear",conf_ak5_jptMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak7_caloMC.Run("../results_"+strftime("%d_%b_%H")+"//NoSmear",conf_ak7_caloMC,MC)
# anal_ak7_caloMC.Run("../results_"+strftime("%d_%b_%H")+"//NoSmear",conf_ak7_caloMC,[QCD_AllPtBins_7TeV_Pythia])

