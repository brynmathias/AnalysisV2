#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
#from libbryn import *
from libHadronic import *
from libOneLepton import *
from icf.core import PSet,Analysis
from time import strftime
import icf.utils as Utils
from batchGolden_singlemu import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *

default_common.Jets.PtCut=50.*(325./375.)
cutTreeMC, junkVar,junkVar2,l = MakeMCTree(100.*(325./375.), Muon = None)
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
CustomMuID = OL_CustomVBTFMuID(had_mu_id_eta_2_5.ps())
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )

#CHOOSE SAMPLE NUMBER
# 0 = PUS4_Lower # 1 = PUS4_Higher # 2 = PUS6_2011 # 3 = MC_2012
number = 3
#================
vertex_reweight = GoodVertexReweighting(PSet(GoodVertexWeights = switches()["reweight_samples"][number][0]).ps())

def addCutFlowMC(b) :
  b.AddWeightFilter("Weight", vertex_reweight)
  b.AddMuonFilter("PreCC",CustomMuID)
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


outDir = "../../results_"+strftime("%d_%b")+"//NoSmear43/"
ensure_dir(outDir)

#from CMSSM_Skim import *
#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,[CMSSM_Skim])
#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,Btag_Systematic_Samples_Lower)
#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,Summer11_MC_Lower_Bins)
anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,switches()["reweight_samples"][number][1])


