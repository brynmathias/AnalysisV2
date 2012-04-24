#!/usr/bin/env python

import setupSUSY

from montecarlo.PhysicsProcesses_mSUGRA_tanbeta3Fall10v1 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta10Fall10v1 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi import *
from onelepton_local_samples import *
samplesBSMgrids = [PhysicsProcesses_mSUGRA_tanbeta3Fall10v1,PhysicsProcesses_mSUGRA_tanbeta10Fall10v1,PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi]

from SUSYSignalScan.mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1 import *
from SUSYSignalScan.mSUGRA_m0_20to2000_m12_20to760_tanb_40andA0_m500_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FSIM_v1 import *

from SUSYSignalScan.SMS_T2tt_Mstop_225to1200_mLSP_50to1025_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v1_V15_03_18_scan_T2tt import *
from SUSYSignalScan.SMS_T3w_x_0p25to0p75_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v2_V15_03_18_scan_T3w import *
from SUSYSignalScan.SMS_T3wb_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v1 import *
from  montecarlo.Summer11.SMS_T3w_x_0p25to0p75_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v2_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1_scan_T3w  import *
from  oneleptonis_SMSskim import *



samplesBSMgrids42 = [

   # SUSYeltanb10
   mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1,
  #  SkimmedSUSYtanB
#   mSUGRA_m0_20to2000_m12_20to760_tanb_40andA0_m500_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FSIM_v1
    ]

samplesSMS = [
    SMSeliskim
#SMSmuskim
    #  SMS_T3w_x_0p25to0p75_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v2_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1_scan_T3w
 
    ]
