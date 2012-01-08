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


#JetSmear = JetSmear(0.1,30)
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
cutTreeMC,junkVar,l = MakeMCTree(100.)
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
def addCutFlowMC(b) :
#  b.AddWeightFilter("Weight", vertex_reweight)
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

outDir = "../results_"+strftime("%d_%b_%H")+"//NoSmear/"
ensure_dir(outDir)

from montecarlo.Summer11.QCD_Summer11_madgraph_All import *

from montecarlo.Summer11.TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
anal_ak5_caloMC.Run(outDir,conf_ak5_caloMC,[TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1])
