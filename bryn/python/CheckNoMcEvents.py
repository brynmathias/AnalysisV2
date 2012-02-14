#!/usr/bin/env python
"""
Created by Bryn Mathias on 2010-05-07.
"""
# -----------------------------------------------------------------------------
# Necessary includes
import errno
import os
import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from libWPol import *
from libbryn import *
from icf.core import PSet,Analysis
from time import strftime
from icf.config import defaultConfig
from icf.utils import json_to_pset
from copy import deepcopy
# -----------------------------------------------------------------------------
# Samples
#import yours in your running script
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise



# -----------------------------------------------------------------------------
# Reading the collections from the ntuple

default_ntuple = deepcopy(defaultConfig.Ntuple)
default_ntuple.Electrons=PSet(
Prefix="electron",
Suffix="Pat",
LooseID="EIDLoose",
TightID="EIDTight",
)
default_ntuple.Muons=PSet(
Prefix="muon",
Suffix="Pat",
LooseID="IsGlobalMuon",
TightID="IDGlobalMuonPromptTight",
)
default_ntuple.SecMuons=PSet(
    Prefix="muon",
    Suffix="PF")
default_ntuple.Taus=PSet(
Prefix="tau",
Suffix="Pat",
LooseID="TauIdbyTaNCfrOnePercent",
TightID="TauIdbyTaNCfrTenthPercent"
)
default_ntuple.Jets=PSet(
Prefix="ic5Jet",
Suffix="Pat",
Uncorrected=False,
)
default_ntuple.Photons=PSet(
Prefix="photon",
Suffix="Pat",
)

ic5_calo = deepcopy(default_ntuple)
ic5_calo.Jets.Prefix="ic5Jet"

ak5_calo = deepcopy(default_ntuple)
ak5_calo.Jets.Prefix="ak5Jet"

ak5_jpt = deepcopy(default_ntuple)
ak5_jpt.Jets.Prefix="ak5JetJPT"

ak5_pf = deepcopy(default_ntuple)
ak5_pf.Jets.Prefix="ak5JetPF"
ak5_pf.TerJets.Prefix="ak5Jet"

ak7_calo = deepcopy(default_ntuple)
ak7_calo.Jets.Prefix="ak7Jet"


# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=True
default_cc.ElectronJet=True
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.ModifyJetEnergy=True
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=-1.
default_cc.Muons.CombIsoCut=0.15
default_cc.Muons.MuonJetDeltaR=0.5
default_cc.Muons.MuonIsoTypePtCutoff=0.
default_cc.Muons.RequireLooseIdForInitialFilter=False
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=-1.0
default_cc.Electrons.CombIsoCut=0.15
default_cc.Electrons.ElectronJetDeltaR=0.5
default_cc.Electrons.ElectronIsoTypePtCutoff=0.
default_cc.Electrons.ElectronLooseIdRequired=True
default_cc.Electrons.ElectronTightIdRequired=False
default_cc.Electrons.RequireLooseIdForInitialFilter=False
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=3
default_cc.Photons.UseID=True
default_cc.Photons.PhotonJetDeltaR=0.5
default_cc.Photons.PhotonIsoTypePtCutoff=30.
# -----------------------------------------------------------------------------
# Definition of common objects
default_common = deepcopy(defaultConfig.Common)
default_common.ApplyXCleaning=True
default_common.Jets.PtCut=50.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False
default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=-1.
default_common.Electrons.CombIsoCut=0.15
default_common.Electrons.ApplyID = True
default_common.Electrons.TightID = False
default_common.Electrons.RequireLooseForOdd = True
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=-1.
default_common.Muons.CombIsoCut=0.15
default_common.Muons.ApplyID = True
default_common.Muons.TightID = True
default_common.Muons.RequireLooseForOdd = True
default_common.Photons.EtCut=25.0
# default_common.Photons.EtaCut=2.5
default_common.Photons.UseID=True
# the photon cuts are NOT read anyway
# default_common.Photons.TrkIsoRel=0.
# default_common.Photons.TrkIsoCut=99999.
# default_common.Photons.EcalIsoRel=0.
# default_common.Photons.EcalIsoCut=99999.
# default_common.Photons.HcalIsoRel=0.
# default_common.Photons.HcalIsoCut=99999.
# default_common.Photons.HadOverEmCut=0.5
# default_common.Photons.SigmaIetaIetaCut=0.5
##default_common.Photons.CaloIsoCut=99999.
default_common.Photons.IDReq = 3
default_common.Photons.RequireLooseForOdd = True
NoiseFilt= OP_HadronicHBHEnoiseFilter()
cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
def addCutFlowData(a) :
  a+=cutTreeData

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)


from montecarlo.L1OffSet_V14_04_00.DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.GJets_TuneZ2_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.GJets_TuneZ2_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.GJets_TuneZ2_40_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.QCD_BLepEnriched_TuneZ2_7TeV_pythia6_evtgen_Summer11_PU_S3_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.QCD_TuneZ2_HT_1000_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.QCD_TuneZ2_HT_100To250_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.QCD_TuneZ2_HT_250To500_7TeV_madgraph_Summer11_PU_S4_START42_V11_v3_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.QCD_TuneZ2_HT_500To1000_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.Summer11_PU_S4_START42_V11_v1_AODSIM_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.T_TuneZ2_s_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.T_TuneZ2_tW_channel_DS_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.T_TuneZ2_t_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.Tbar_TuneZ2_s_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.Tbar_TuneZ2_tW_channel_DS_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.Tbar_TuneZ2_t_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.WW_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.WZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
from montecarlo.L1OffSet_V14_04_00.ZZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *


samples = [DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,GJets_TuneZ2_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,GJets_TuneZ2_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,GJets_TuneZ2_40_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,QCD_BLepEnriched_TuneZ2_7TeV_pythia6_evtgen_Summer11_PU_S3_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,QCD_TuneZ2_HT_1000_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,QCD_TuneZ2_HT_100To250_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,QCD_TuneZ2_HT_250To500_7TeV_madgraph_Summer11_PU_S4_START42_V11_v3_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,QCD_TuneZ2_HT_500To1000_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,Summer11_PU_S4_START42_V11_v1_AODSIM_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,T_TuneZ2_s_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,T_TuneZ2_tW_channel_DS_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,T_TuneZ2_t_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,Tbar_TuneZ2_s_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,Tbar_TuneZ2_tW_channel_DS_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,Tbar_TuneZ2_t_channel_7TeV_powheg_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,WW_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,WZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,ZZ_TuneZ2_7TeV_pythia6_tauola_Fall11_PU_S6_START42_V14B_v1_V15_04_00_jetCorrections_L1Offset_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,]
out = "../testDir/"
ensure_dir(out)
anal_ak5_caloData.Run(out,conf_ak5_caloData,samples)




