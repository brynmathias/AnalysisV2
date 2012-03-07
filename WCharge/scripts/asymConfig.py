#!/usr/bin/env python
# -*- coding: utf-8 -*-
import setupSUSY
from libFrameworkSUSY import *
from libWCharge       import *
from icf.core import PSet, Analysis
from icf.config import defaultConfig
from icf.utils import json_to_pset

#Import DATA PSETS
from SingleElectron_Run2011A_May10ReReco_v1 import *
from SingleElectron_Run2011A_PromptReco_v4_213 import *
from SingleElectron_Run2011A_PromptReco_v4_228 import *
from SingleElectron_Run2011A_PromptReco_v4_245 import *
from SingleElectron_Run2011A_PromptReco_v4_268 import *
from SingleElectron_Run2011A_PromptReco_v4_285 import *
from SingleElectron_Run2011A_PromptReco_v4_299 import *

#Import MC PSETS
from DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import *
from DYToEE_M_10To20_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 import * 
from DYToEE_M_20_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 import * 
from DYToTauTau_M_10To20_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 import * 
from DYToTauTau_M_20_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 import * 

from TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import * 
from TT_TuneZ2_7TeV_pythia6_tauola_Summer11_PU_S3_START42_V11_v2 import * 

from WToENu_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import * 
from WToTauNu_TuneZ2_7TeV_pythia6_tauola_Summer11_PU_S3_START42_V11_v2 import * 
from WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *

from powheg import *

from QCD_BC20to30 import *
from QCD_BC30to80 import *
from QCD_BC80to170 import *
from QCD_EM20to30 import *
from QCD_EM30to80 import *
from QCD_EM80to170 import *
from Gjet_50to80 import *



#Standard Cuts
conf = defaultConfig.copy()
conf.Common.Jets.PtCut=40.0
conf.Common.Jets.EtaCut=2.5
conf.Common.Jets.ApplyID=True
conf.Common.Jets.TightID=False
conf.Common.Muons.EtaCut = 2.4
conf.Common.Muons.PtCut = 15.0
conf.Common.Muons.TrkIsoCut = -1.
conf.Common.Muons.CombIsoCut = 0.1
conf.Common.Electrons.PtCut = 15.0
conf.Common.Electrons.EtaCut = 2.4
conf.Common.Electrons.ApplyID=False

conf.Ntuple.Electrons.Suffix = "Pat"
conf.Ntuple.Muons.Suffix = "Pat"
conf.Ntuple.SecMuons.Suffix = "PF"
conf.Ntuple.Taus.Suffix = "Pat"
conf.Ntuple.Jets.Suffix = "Pat"
conf.Ntuple.Jets.Prefix = "ak5JetPF"
conf.Ntuple.SecJets.Suffix = "Pat"
conf.Ntuple.SecJets.Prefix = "ak5JetPF2PAT"
conf.Ntuple.TerJets.Suffix = "Pat"
conf.Ntuple.TerJets.Prefix = "ak7JetPF"

default_Asym = PSet(
    jet_ET = 40.,
    lep_ET = 35.,
    lep_MT = 0.,
    lep_VetoET = 15.,
    lep_WP = 3,
    lep_VetoWP = 0,
    lep_AntiWP = 3,
    #lep_AntiDPhi_eb = 0.06,
    #lep_AntiDEta_eb = 0.007,
    #lep_AntiDPhi_ee = 0.04,
    #lep_AntiDEta_ee = 0.009,
    lep_AntiDPhi_eb = 0.06,
    lep_AntiDEta_eb = 0.004,
    lep_AntiDPhi_ee = 0.03,
    lep_AntiDEta_ee = 0.007,
    lep_QCheck = True,

    lep_MissHits_WP95 = 1,
    lep_DCot_WP95 = 0.0,
    lep_Dist_WP95 = 0.0,
    lep_Trk_eb_WP95 = 0.15,
    lep_Ecal_eb_WP95 = 2.0,#not typo, cut is removed
    lep_Hcal_eb_WP95 = 0.12,
    lep_sihih_eb_WP95 = 0.01,
    lep_Dphi_eb_WP95 = 0.08,
    lep_Deta_eb_WP95 = 0.007,
    lep_HoE_eb_WP95 = 0.5,
    lep_Trk_ee_WP95 = 0.08,
    lep_Ecal_ee_WP95 = 0.06,
    lep_Hcal_ee_WP95 = 0.05,
    lep_sihih_ee_WP95 = 0.03,
    lep_Dphi_ee_WP95 = 0.7,
    lep_Deta_ee_WP95 = 0.01,
    lep_HoE_ee_WP95 = 0.15,

    lep_MissHits_WP90 = 1,
    lep_DCot_WP90 = 0.02,
    lep_Dist_WP90 = 0.02,
    lep_Trk_eb_WP90 = 0.12,
    lep_Ecal_eb_WP90 = 0.09,
    lep_Hcal_eb_WP90 = 0.10,
    lep_sihih_eb_WP90 = 0.01,
    lep_Dphi_eb_WP90 = 0.08,
    lep_Deta_eb_WP90 = 0.007,
    lep_HoE_eb_WP90 = 0.12,
    lep_Trk_ee_WP90 = 0.05,
    lep_Ecal_ee_WP90 = 0.06,
    lep_Hcal_ee_WP90 = 0.03,
    lep_sihih_ee_WP90 = 0.03,
    lep_Dphi_ee_WP90 = 0.7,
    lep_Deta_ee_WP90 = 0.009,
    lep_HoE_ee_WP90 = 0.15,

    lep_MissHits_WP85 = 1,
    lep_DCot_WP85 = 0.02,
    lep_Dist_WP85 = 0.02,
    lep_Trk_eb_WP85 = 0.09,
    lep_Ecal_eb_WP85 = 0.08,
    lep_Hcal_eb_WP85 = 0.10,
    lep_sihih_eb_WP85 = 0.01,
    lep_Dphi_eb_WP85 = 0.06,
    lep_Deta_eb_WP85 = 0.006,
    lep_HoE_eb_WP85 = 0.04,
    lep_Trk_ee_WP85 = 0.05,
    lep_Ecal_ee_WP85 = 0.05,
    lep_Hcal_ee_WP85 = 0.025,
    lep_sihih_ee_WP85 = 0.03,
    lep_Dphi_ee_WP85 = 0.04,
    lep_Deta_ee_WP85 = 0.007,
    lep_HoE_ee_WP85 = 0.15,

    lep_MissHits_WP80 = 0,
    lep_DCot_WP80 = 0.02,
    lep_Dist_WP80 = 0.02,
    lep_Trk_eb_WP80 = 0.09,
    lep_Ecal_eb_WP80 = 0.07,
    lep_Hcal_eb_WP80 = 0.10,
    lep_sihih_eb_WP80 = 0.01,
    lep_Dphi_eb_WP80 = 0.06,
    lep_Deta_eb_WP80 = 0.004,
    lep_HoE_eb_WP80 = 0.04,
    lep_Trk_ee_WP80 = 0.04,
    lep_Ecal_ee_WP80 = 0.05,
    lep_Hcal_ee_WP80 = 0.025,
    lep_sihih_ee_WP80 = 0.03,
    lep_Dphi_ee_WP80 = 0.03,
    lep_Deta_ee_WP80 = 0.007,
    lep_HoE_ee_WP80 = 0.15,

    lep_MissHits_WP70 = 0,
    lep_DCot_WP70 = 0.02,
    lep_Dist_WP70 = 0.02,
    lep_Trk_eb_WP70 = 0.05,
    lep_Ecal_eb_WP70 = 0.06,
    lep_Hcal_eb_WP70 = 0.03,
    lep_sihih_eb_WP70 = 0.01,
    lep_Dphi_eb_WP70 = 0.03,
    lep_Deta_eb_WP70 = 0.004,
    lep_HoE_eb_WP70 = 0.025,
    lep_Trk_ee_WP70 = 0.025,
    lep_Ecal_ee_WP70 = 0.025,
    lep_Hcal_ee_WP70 = 0.02,
    lep_sihih_ee_WP70 = 0.03,
    lep_Dphi_ee_WP70 = 0.02,
    lep_Deta_ee_WP70 = 0.005,
    lep_HoE_ee_WP70 = 0.15,

    lep_MissHits_WP60 = 0,
    lep_DCot_WP60 = 0.02,
    lep_Dist_WP60 = 0.02,
    lep_Trk_eb_WP60 = 0.04,
    lep_Ecal_eb_WP60 = 0.04,
    lep_Hcal_eb_WP60 = 0.03,
    lep_sihih_eb_WP60 = 0.01,
    lep_Dphi_eb_WP60 = 0.025,
    lep_Deta_eb_WP60 = 0.004,
    lep_HoE_eb_WP60 = 0.025,
    lep_Trk_ee_WP60 = 0.025,
    lep_Ecal_ee_WP60 = 0.02,
    lep_Hcal_ee_WP60 = 0.02,
    lep_sihih_ee_WP60 = 0.03,
    lep_Dphi_ee_WP60 = 0.02,
    lep_Deta_ee_WP60 = 0.005,
    lep_HoE_ee_WP60 = 0.15,

    do_Recoil = False,
    rec_fluc = 0,
    do_TP = False,
    do_RecoilNtuple = False,
    rec_Type = 0,
    ZDat_File = "./RecoilFit/recoilfits/recoil_data.root",
    ZMC_File = "./RecoilFit/recoilfits/recoil_data.root",
    W_File = "./RecoilFit/recoilfits/recoil_data.root",
)

trigger_bits_sel = [
          "HLT_Ele27_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_v*",
          "HLT_Ele32_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_v*",
      ]
triggers_sel = PSet(
          Triggers=trigger_bits_sel,
          Verbose=False,
          UsePreScaledTriggers=False
          )

data_samples =[
    SingleElectron_Run2011A_May10ReReco_v1,
    SingleElectron_Run2011A_PromptReco_v4_213,
    SingleElectron_Run2011A_PromptReco_v4_228,
    SingleElectron_Run2011A_PromptReco_v4_245,
    SingleElectron_Run2011A_PromptReco_v4_268,
    SingleElectron_Run2011A_PromptReco_v4_285,
    SingleElectron_Run2011A_PromptReco_v4_299
  ]
recoil_samples =[ 
    WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1, 
    WToENu_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2, 
  ]
background_samples =[
    #TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1, 
    #TT_TuneZ2_7TeV_pythia6_tauola_Summer11_PU_S3_START42_V11_v2, 
    #WToTauNu_TuneZ2_7TeV_pythia6_tauola_Summer11_PU_S3_START42_V11_v2, 
    TauMinus_Powheg,
    TauPlus_Powheg,
    #DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1,
    #DYToEE_M_10To20_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, 
    #DYToEE_M_20_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1, 
    #DYToTauTau_M_10To20_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1, 
    #DYToTauTau_M_20_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1, 
    #QCD_BC20to30,
    #QCD_BC30to80,
    #QCD_BC80to170,
    #QCD_EM20to30,
    #QCD_EM30to80,
    #QCD_EM80to170,
    #Gjet_50to80,
  ]
