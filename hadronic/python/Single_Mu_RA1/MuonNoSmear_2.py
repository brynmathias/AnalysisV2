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


vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
cutTreeMC,junkVar,junkVar2,l = MakeMCTree(100.,Muon = True,Split="Muon_Two")
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
CustomMuID = OL_CustomVBTFMuID(mu_id_eta_2_1.ps())
#CHOOSE SAMPLE NUMBER
# 0 = PUS4_Lower # 1 = PUS4_Higher # 2 = PUS6_2011 # 3 = MC_2012
number = 3
#==============
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
#conf_ak5_caloMC.Common.print_out()
anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)


outDir = "../../results_"+strftime("%d_%b")+"//MuonNoSmear_Btag_2/"
#outDir = "../results_"+strftime("%d_%b")+"//MuonNoSmear/"
ensure_dir(outDir)

#from CMSSM_Skim import *
#anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,CMSSM_Skim)

anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,switches()["reweight_samples"][number][1])

#anal_ak5_caloBtagData.Run(outDir,conf_ak5_caloBtagData,[TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1,WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1, WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1]+QCD_Summer11_madgraph_All)

#anal_ak5_caloBtagData.Run(outDir,conf_ak5_caloBtagData,[WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1, WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1])
