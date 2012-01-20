#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *
from icf.core import PSet
from SweetBatchSub import *
# -----------------------------------------------------------------------------
# Local samples

from copy import deepcopy

from montecarlo.LMx import *
from montecarlo.WJets_Madgraph import *
from montecarlo.TTBarTauola import *
from montecarlo.Zjets_madgraph import *
from montecarlo.Zinvisible_jets_pset import *
from montecarlo.QCD_Pythia6_allBins import *
from data.JetMETTau_ALL_230810 import *
from data.JetMET_Run2010A_PromptReco_v4_250810 import *
from montecarlo.QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_2600to3000_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.tanBeta3 import *
from data.edward_data_skim import *
from montecarlo.w_jets_mg_edwardSkim import *
from montecarlo.z_jets_mg_edwardSkim import *
from montecarlo.z_inv_mg_edwardSkim import *

samples = []
data = [JetMET_ALL_upto230810,JetMET_Run2010A_PromptReco_v4_250810]
QCD = [QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_2600to3000_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2
]

QCD_PYTHIA6 = [QCD_Pt80_7TeV_Pythia,QCD_Pt170_7TeV_Pythia,QCD_Pt300_7TeV_Pythia,QCD_Pt470_7TeV_Pythia,QCD_Pt800_7TeV_Pythia,QCD_Pt1400_7TeV_Pythia]





pset_standard_hadronic_smallPFMET_noLowerLimit = PSet(
    DirName = "HadronicCommon_smallPFMET_noLowerLimit",
    MinObjects = 1,
    MaxObjects = 10,
    StandardPlots = True,
    CountPlots = False,
    DeadECALPlots = True,
    BabyPlots = True
    )

pset_standard_hadronic_beforeAlphaT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_beforeAlphaT.DirName = "HadronicCommon_beforeAlphaT"

pset_standard_hadronic_PFMET = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_PFMET.DirName = "HadronicCommon_PFMET"

pset_standard_hadronic_PFMET_babyMHT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_PFMET_babyMHT.DirName = "HadronicCommon_PFMET_babyMHT"

pset_standard_hadronic_PFMET_antibabyMHT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_PFMET_antibabyMHT.DirName = "HadronicCommon_PFMET_antibabyMHT"

pset_standard_hadronic_largePFMET = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_largePFMET.DirName = "HadronicCommon_largePFMET"

pset_standard_hadronic_smallPFMET = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_smallPFMET.DirName = "HadronicCommon_smallPFMET"

pset_standard_hadronic_alphaT051 = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_alphaT051.DirName = "HadronicCommon_alphaT051"

pset_standard_hadronic_alphaT052 = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_alphaT052.DirName = "HadronicCommon_alphaT052"

pset_standard_hadronic_alphaT053 = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_alphaT053.DirName = "HadronicCommon_alphaT053"

pset_standard_hadronic_alphaT053_noDeadECAL = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_alphaT053_noDeadECAL.DirName = "HadronicCommon_8"

pset_standard_hadronic_largeAlphaT_noDeadECAL = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_largeAlphaT_noDeadECAL.DirName = "HadronicCommon_largeAlphaT_noDeadECAL"

pset_standard_hadronic_afterTheEdge_noDeadECAL = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_afterTheEdge_noDeadECAL.DirName = "HadronicCommon_afterTheEdge_noDeadECAL"

pset_standard_hadronic_smallMHT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_smallMHT.DirName = "HadronicCommon_smallMHT"

pset_standard_hadronic_afterTheEdge = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_afterTheEdge.DirName = "HadronicCommon_afterTheEdge"

pset_standard_hadronic_goodAlphaT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_goodAlphaT.DirName = "HadronicCommon_goodAlphaT"

pset_standard_hadronic_largeAlphaT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_largeAlphaT.DirName = "HadronicCommon_largeAlphaT"

pset_standard_hadronic_smallAlphaT = deepcopy(pset_standard_hadronic_smallPFMET_noLowerLimit)
pset_standard_hadronic_smallAlphaT.DirName = "HadronicCommon_smallAlphaT"



plots_standardHadronic_beforeAlphaT = HadronicCommonPlots(pset_standard_hadronic_beforeAlphaT.ps())
plots_standardHadronic_smallPFMET_noLowerLimit = HadronicCommonPlots(pset_standard_hadronic_smallPFMET_noLowerLimit.ps())
plots_standardHadronic_smallPFMET = HadronicCommonPlots(pset_standard_hadronic_smallPFMET.ps())
plots_standardHadronic_PFMET_babyMHT = HadronicCommonPlots(pset_standard_hadronic_PFMET_babyMHT.ps())

plots_standardHadronic_PFMET_antibabyMHT = HadronicCommonPlots(pset_standard_hadronic_PFMET_antibabyMHT.ps())
plots_standardHadronic_largePFMET = HadronicCommonPlots(pset_standard_hadronic_largePFMET.ps())
plots_standardHadronic_alphaT051 = HadronicCommonPlots(pset_standard_hadronic_alphaT051.ps())
plots_standardHadronic_alphaT052 = HadronicCommonPlots(pset_standard_hadronic_alphaT052.ps())
plots_standardHadronic_alphaT053 = HadronicCommonPlots(pset_standard_hadronic_alphaT053.ps())
plots_standardHadronic_alphaT053_noDeadECAL = HadronicCommonPlots(pset_standard_hadronic_alphaT053_noDeadECAL.ps())
plots_standardHadronic_afterTheEdge_noDeadECAL = HadronicCommonPlots(pset_standard_hadronic_afterTheEdge_noDeadECAL.ps())
plots_standardHadronic_largeAlphaT_noDeadECAL = HadronicCommonPlots(pset_standard_hadronic_largeAlphaT_noDeadECAL.ps())


plots_standardHadronic_SmallMHT = HadronicCommonPlots(pset_standard_hadronic_smallMHT.ps())
plots_standardHadronic_afterTheEdge = HadronicCommonPlots(pset_standard_hadronic_afterTheEdge.ps())
plots_standardHadronic_goodAlphaT = HadronicCommonPlots(pset_standard_hadronic_goodAlphaT.ps())
plots_standardHadronic_largeAlphaT = HadronicCommonPlots(pset_standard_hadronic_largeAlphaT.ps())
plots_standardHadronic_smallAlphaT = HadronicCommonPlots(pset_standard_hadronic_smallAlphaT.ps())


pset_count_1 = PSet(
    DirName = "CountPlots_1",
    MinObjects = 1,
    MaxObjects = 10,
    StandardPlots = True,
    CountPlots = True,
    DeadECALPlots = False,
    BabyPlots = False,
)

pset_count_2 = deepcopy(pset_count_1)
pset_count_2.DirName = "CountPlots_2"


pset_count_3 = deepcopy(pset_count_1)
pset_count_3.DirName = "CountPlots_3"

pset_count_4 = deepcopy(pset_count_1)
pset_count_4.DirName = "CountPlots_4"

pset_count_5 = deepcopy(pset_count_1)
pset_count_5.DirName = "CountPlots_5"

pset_count_6 = deepcopy(pset_count_1)
pset_count_6.DirName = "CountPlots_6"

pset_count_7 = deepcopy(pset_count_1)
pset_count_7.DirName = "CountPlots_7"

pset_count_8 = deepcopy(pset_count_1)
pset_count_8.DirName = "CountPlots_8"

pset_count_9 = deepcopy(pset_count_1)
pset_count_9.DirName = "CountPlots_9"

pset_count_10 = deepcopy(pset_count_1)
pset_count_10.DirName = "CountPlots_10"

pset_count_11 = deepcopy(pset_count_1)
pset_count_11.DirName = "CountPlots_11"

pset_count_12 = deepcopy(pset_count_1)
pset_count_12.DirName = "CountPlots_12"

pset_count_13 = deepcopy(pset_count_1)
pset_count_13.DirName = "CountPlots_13"

pset_count_14 = deepcopy(pset_count_1)
pset_count_14.DirName = "CountPlots_14"

pset_count_15 = deepcopy(pset_count_1)
pset_count_15.DirName = "CountPlots_15"

pset_count_16 = deepcopy(pset_count_1)
pset_count_16.DirName = "CountPlots_16"

pset_count_17 = deepcopy(pset_count_1)
pset_count_17.DirName = "CountPlots_17"



plots_count_1 = HadronicCommonPlots(pset_count_1.ps())
plots_count_2 = HadronicCommonPlots(pset_count_2.ps())
plots_count_3 = HadronicCommonPlots(pset_count_3.ps())
plots_count_4 = HadronicCommonPlots(pset_count_4.ps())
plots_count_5 = HadronicCommonPlots(pset_count_5.ps())
plots_count_6 = HadronicCommonPlots(pset_count_6.ps())
plots_count_7 = HadronicCommonPlots(pset_count_7.ps())
plots_count_8 = HadronicCommonPlots(pset_count_8.ps())
plots_count_9 = HadronicCommonPlots(pset_count_9.ps())
plots_count_10 = HadronicCommonPlots(pset_count_10.ps())
plots_count_11 = HadronicCommonPlots(pset_count_11.ps())
plots_count_12 = HadronicCommonPlots(pset_count_12.ps())
plots_count_13 = HadronicCommonPlots(pset_count_13.ps())
plots_count_14 = HadronicCommonPlots(pset_count_14.ps())
plots_count_15 = HadronicCommonPlots(pset_count_15.ps())
plots_count_16 = HadronicCommonPlots(pset_count_16.ps())
plots_count_17 = HadronicCommonPlots(pset_count_17.ps())



# -----------------------------------------------------------------------------
# Cross-cleaning settings

#default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=True
default_cc.ElectronJet=True
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=20.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.ModifyJetEnergy=True
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=6.0
default_cc.Muons.CombIsoCut=0.2
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=6.0
default_cc.Electrons.CombIsoCut=0.2
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=9.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=2

# -----------------------------------------------------------------------------
# Definition of common objects

#default_common = deepcopy(defaultConfig.Common)

default_common.ApplyXCleaning=True
default_common.Jets.PtCut=50.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False
default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=6.
default_common.Electrons.CombIsoCut=0.2
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=6.
default_common.Muons.CombIsoCut=0.2
default_common.Photons.EtCut=25.0
default_common.Photons.EtaCut=2.5
default_common.Photons.TrkIsoCut=9.
default_common.Photons.EcalIsoCut=99999.
default_common.Photons.HcalIsoCut=99999.
#default_common.Photons.CaloIsoCut=0.2
default_common.Photons.IDReq=2


# -----------------------------------------------------------------------------
# Common configurations ( IC5Calo, AK5Calo, AK5JPT, AK5PF)

conf_ic5_calo = deepcopy(defaultConfig)
conf_ic5_calo.Ntuple = deepcopy(ic5_calo)
conf_ic5_calo.XCleaning = deepcopy(default_cc)
conf_ic5_calo.Common = deepcopy(default_common)

conf_ak5_calo = deepcopy(defaultConfig)
conf_ak5_calo.Ntuple = deepcopy(ak5_calo)
conf_ak5_calo.XCleaning = deepcopy(default_cc)
conf_ak5_calo.Common = deepcopy(default_common)

conf_ak7_calo = deepcopy(defaultConfig)
conf_ak7_calo.Ntuple = deepcopy(ak7_calo)
conf_ak7_calo.XCleaning = deepcopy(default_cc)
conf_ak7_calo.Common = deepcopy(default_common)

conf_ak5_jpt = deepcopy(defaultConfig)
conf_ak5_jpt.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jpt.XCleaning = deepcopy(default_cc)
conf_ak5_jpt.Common = deepcopy(default_common)

conf_ak5_pf = deepcopy(defaultConfig)
conf_ak5_pf.Ntuple = deepcopy(ak5_pf)
conf_ak5_pf.XCleaning = deepcopy(default_cc)
conf_ak5_pf.Common = deepcopy(default_common)

# -----------------------------------------------------------------------------
# Common cut definitions

numComJets = OP_NumComJets(">=",2)
numComLeptons = OP_NumComLeptons("<=",0)

numComPhotons = OP_NumComPhotons("<=",0)
oddJet = OP_OddJet()
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
badMuonInJet = OP_BadMuonInJet()
secondJetET = OP_SecondJetEtCut(100.)
htCut = RECO_CommonHTCut(350.)
missedHT = OP_MissedHTCut(1.25)

alphaT = OP_CommonAlphaTCut(0.55)
alphaT_05 = OP_CommonAlphaTCut(0.5)
alphaT_0505 = OP_CommonAlphaTCut(0.505)
alphaT_051 = OP_CommonAlphaTCut(0.51)
alphaT_0515 = OP_CommonAlphaTCut(0.515)
alphaT_052 = OP_CommonAlphaTCut(0.52)
alphaT_053 = OP_CommonAlphaTCut(0.53)
alphaT_04 = OP_CommonAlphaTCut(0.4)
reverse_alphaT_03 = OP_CommonReverseAlphaTCut(0.3)
reverse_alphaT_05 = OP_CommonReverseAlphaTCut(0.5)


deadECAL = OP_DeadECALCut(0.5)
deadECAL_0 = OP_DeadECALCut(0.5)
deadECAL_1 = OP_DeadECALCut(0.5)
deadECAL_2 = OP_DeadECALCut(0.5)
deadECAL_3 = OP_DeadECALCut(0.5)
deadECAL_4 = OP_DeadECALCut(0.5)
deadECAL_5 = OP_DeadECALCut(0.5)
deadECAL_6 = OP_DeadECALCut(0.5)
deadECAL_03 = OP_DeadECALCut(0.3)

LeadingJetEta = OP_FirstJetEta(2.5)
reversedPFMET = OP_ReversedPFMET(100.)

PFMET_1 = OP_PFMET(10.)
PFMET = OP_PFMET(10.)

babyMHT = OP_BabyMHT(100)
antiBabyMHT = OP_ReversedBabyMHT(100)
babyMHTovHT = OP_BabyMHTovHT(0.3)

# -----------------------------------------------------------------------------
# Cut flow



cutTreeMC = Tree("MC")
cutTreeMC.Attach(unCorLeadJetCut)
cutTreeMC.TAttach(unCorLeadJetCut,plots_count_1)
cutTreeMC.TAttach(plots_count_1,LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,numComJets)
cutTreeMC.TAttach(numComJets,plots_count_2)

cutTreeMC.TAttach(numComJets,numComLeptons)
cutTreeMC.TAttach(numComLeptons,plots_count_3)

cutTreeMC.TAttach(numComLeptons,numComPhotons)
cutTreeMC.TAttach(numComPhotons,plots_count_4)

cutTreeMC.TAttach(numComPhotons,oddJet)
cutTreeMC.TAttach(oddJet,plots_count_5)

cutTreeMC.TAttach(oddJet,oddMuon)
cutTreeMC.TAttach(oddMuon,plots_count_6)

cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,plots_count_7)

cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,plots_count_8)

cutTreeMC.TAttach(oddPhoton,badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,plots_count_9)

cutTreeMC.TAttach(badMuonInJet,secondJetET)
cutTreeMC.TAttach(secondJetET,plots_count_10)

cutTreeMC.TAttach(secondJetET,htCut)
cutTreeMC.TAttach(htCut,plots_count_11)

cutTreeMC.TAttach(plots_count_11,plots_standardHadronic_beforeAlphaT)

cutTreeMC.TAttach(plots_count_11,reversedPFMET)
cutTreeMC.TAttach(reversedPFMET,plots_standardHadronic_smallPFMET_noLowerLimit)
cutTreeMC.TAttach(reversedPFMET,PFMET)
cutTreeMC.TAttach(PFMET,plots_standardHadronic_smallPFMET)
cutTreeMC.TAttach(PFMET,babyMHT)
cutTreeMC.TAttach(babyMHT,plots_standardHadronic_PFMET_babyMHT)

cutTreeMC.TAttach(PFMET,antiBabyMHT)
cutTreeMC.TAttach(antiBabyMHT,plots_standardHadronic_PFMET_antibabyMHT)
cutTreeMC.TAttach(plots_standardHadronic_PFMET_antibabyMHT,deadECAL)
cutTreeMC.TAttach(deadECAL,plots_standardHadronic_largePFMET)

cutTreeMC.TAttach(plots_count_11,alphaT_051)
cutTreeMC.TAttach(alphaT_051,deadECAL_4)
cutTreeMC.TAttach(deadECAL_4,plots_standardHadronic_alphaT051)

cutTreeMC.TAttach(plots_count_11,alphaT_052)
cutTreeMC.TAttach(alphaT_052,deadECAL_5)
cutTreeMC.TAttach(deadECAL_5,plots_standardHadronic_alphaT052)

cutTreeMC.TAttach(plots_count_11,alphaT_053)
cutTreeMC.TAttach(alphaT_053,plots_standardHadronic_alphaT053_noDeadECAL)
cutTreeMC.TAttach(plots_standardHadronic_alphaT053_noDeadECAL,deadECAL_6)
cutTreeMC.TAttach(deadECAL_6,plots_standardHadronic_alphaT053)

cutTreeMC.TAttach(plots_count_11,alphaT_05)
cutTreeMC.TAttach(alphaT_05,plots_standardHadronic_afterTheEdge_noDeadECAL)
cutTreeMC.TAttach(plots_standardHadronic_afterTheEdge_noDeadECAL,deadECAL_0)
cutTreeMC.TAttach(deadECAL_0,plots_standardHadronic_afterTheEdge)

cutTreeMC.TAttach(plots_count_11,reverse_alphaT_05)
cutTreeMC.TAttach(reverse_alphaT_05,alphaT_04)
cutTreeMC.TAttach(alphaT_04,deadECAL_1)
cutTreeMC.TAttach(deadECAL_1,plots_standardHadronic_goodAlphaT)

cutTreeMC.TAttach(plots_count_11,reverse_alphaT_03)
cutTreeMC.TAttach(reverse_alphaT_03,deadECAL_2)
cutTreeMC.TAttach(deadECAL_2,plots_standardHadronic_smallAlphaT)

cutTreeMC.TAttach(plots_count_11,alphaT)
cutTreeMC.TAttach(alphaT,plots_standardHadronic_largeAlphaT_noDeadECAL)
cutTreeMC.TAttach(alphaT,plots_count_12)
cutTreeMC.TAttach(alphaT,deadECAL_3)
cutTreeMC.TAttach(deadECAL_3,plots_standardHadronic_largeAlphaT)
cutTreeMC.TAttach(deadECAL_3,plots_count_13)
cutTreeMC.TAttach(alphaT,deadECAL_03)
cutTreeMC.TAttach(deadECAL_03,plots_count_14)


cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,plots_count_1)
cutTreeData.TAttach(plots_count_1,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,numComJets)
cutTreeData.TAttach(numComJets,plots_count_2)

cutTreeData.TAttach(numComJets,numComLeptons)
cutTreeData.TAttach(numComLeptons,plots_count_3)

cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,plots_count_4)

cutTreeData.TAttach(numComPhotons,oddJet)
cutTreeData.TAttach(oddJet,plots_count_5)

cutTreeData.TAttach(oddJet,oddMuon)
cutTreeData.TAttach(oddMuon,plots_count_6)

cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,plots_count_7)

cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,plots_count_8)

cutTreeData.TAttach(oddPhoton,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,plots_count_9)

cutTreeData.TAttach(badMuonInJet,secondJetET)
cutTreeData.TAttach(secondJetET,plots_count_10)

cutTreeData.TAttach(secondJetET,htCut)
cutTreeData.TAttach(htCut,plots_count_11)

cutTreeData.TAttach(plots_count_11,plots_standardHadronic_beforeAlphaT)

cutTreeData.TAttach(plots_count_11,reversedPFMET)
cutTreeData.TAttach(reversedPFMET,plots_standardHadronic_smallPFMET_noLowerLimit)
cutTreeData.TAttach(reversedPFMET,PFMET)
cutTreeData.TAttach(PFMET,plots_standardHadronic_smallPFMET)


cutTreeData.TAttach(PFMET,babyMHT)
cutTreeData.TAttach(babyMHT,plots_standardHadronic_PFMET_babyMHT)
cutTreeData.TAttach(PFMET,antiBabyMHT)
cutTreeData.TAttach(antiBabyMHT,plots_standardHadronic_PFMET_antibabyMHT)
cutTreeData.TAttach(plots_standardHadronic_PFMET_antibabyMHT,deadECAL)
cutTreeData.TAttach(deadECAL,plots_standardHadronic_largePFMET)

cutTreeData.TAttach(plots_count_11,alphaT_051)
cutTreeData.TAttach(alphaT_051,deadECAL_4)
cutTreeData.TAttach(deadECAL_4,plots_standardHadronic_alphaT051)

cutTreeData.TAttach(plots_count_11,alphaT_052)
cutTreeData.TAttach(alphaT_052,deadECAL_5)
cutTreeData.TAttach(deadECAL_5,plots_standardHadronic_alphaT052)

cutTreeData.TAttach(plots_count_11,alphaT_053)
cutTreeData.TAttach(alphaT_053,plots_standardHadronic_alphaT053_noDeadECAL)
cutTreeData.TAttach(plots_standardHadronic_alphaT053_noDeadECAL,deadECAL_6)
cutTreeData.TAttach(deadECAL_6,plots_standardHadronic_alphaT053)

cutTreeData.TAttach(plots_count_11,alphaT_05)
cutTreeData.TAttach(alphaT_05,plots_standardHadronic_afterTheEdge_noDeadECAL)
cutTreeData.TAttach(plots_standardHadronic_afterTheEdge_noDeadECAL,deadECAL_0)
cutTreeData.TAttach(deadECAL_0,plots_standardHadronic_afterTheEdge)

cutTreeData.TAttach(plots_count_11,reverse_alphaT_05)
cutTreeData.TAttach(reverse_alphaT_05,alphaT_04)
cutTreeData.TAttach(alphaT_04,deadECAL_1)
cutTreeData.TAttach(deadECAL_1,plots_standardHadronic_goodAlphaT)

cutTreeData.TAttach(plots_count_11,reverse_alphaT_03)
cutTreeData.TAttach(reverse_alphaT_03,deadECAL_2)
cutTreeData.TAttach(deadECAL_2,plots_standardHadronic_smallAlphaT)

cutTreeData.TAttach(plots_count_11,alphaT)
cutTreeData.TAttach(alphaT,plots_standardHadronic_largeAlphaT_noDeadECAL)
cutTreeData.TAttach(alphaT,plots_count_12)
cutTreeData.TAttach(alphaT,deadECAL_3)
cutTreeData.TAttach(deadECAL_3,plots_standardHadronic_largeAlphaT)
cutTreeData.TAttach(deadECAL_3,plots_count_13)
cutTreeData.TAttach(alphaT,deadECAL_03)
cutTreeData.TAttach(deadECAL_03,plots_count_14)





def addCutFlowMC(a) :
    a+=cutTreeMC

def addCutFlowData(b) :
    b+=cutTreeData


#    a+=debug_hadronic
    
# -----------------------------------------------------------------------------
# Definition of analyses



anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)

anal_ak7_caloMC=Analysis("AK7Calo")
addCutFlowMC(anal_ak7_caloMC)







anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

anal_ak7_caloData=Analysis("AK7Calo")
addCutFlowData(anal_ak7_caloData)



# -----------------------------------------------------------------------------
# Run analyses


MC = True
simpleTest = False
runLocal = False

if (MC == True ) :

   
    if(simpleTest != True) :
        if(runLocal == False) : 
            #anal_ak5_caloMC.Run("../results_Baby/Pythia8",conf_ak5_calo,QCD)
            #anal_ak7_caloMC.Run("../results_Baby/Pythia8",conf_ak7_calo,QCD)

            #anal_ak5_caloMC.Run("../results_Baby/LM0",conf_ak5_calo,[LM0])
            #anal_ak5_caloMC.Run("../results_Baby/tt",conf_ak5_calo,[ttbarTauola])
            
           # anal_ak7_caloMC.Run("../results_Baby/LM0",conf_ak7_calo,[LM0])
           # anal_ak7_caloMC.Run("../results_Baby/tt",conf_ak7_calo,[ttbarTauola])
            
            anal_ak5_caloMC.Run("../results_Baby/W",conf_ak5_calo,[wjets_madgraph_edwardSkim])
            anal_ak5_caloMC.Run("../results_Baby/Zinv",conf_ak5_calo,[Zinvisible_jets_edwardSkim])
            
            #anal_ak7_caloMC.Run("../results_Baby/W",conf_ak7_calo,[wjets_madgraph_edwardSkim])
            #anal_ak7_caloMC.Run("../results_Baby/Zinv",conf_ak7_calo,[Zinvisible_jets_edwardSkim])


    if(runLocal == True) :

        anal_ak5_caloMC.Run("../results_Baby/LM0_dR03",conf_ak5_calo,[LM0])
        anal_ak5_caloMC.Run("../results_Baby/LM1",conf_ak5_calo,[LM1])
        anal_ak5_caloMC.Run("../results_Baby/LM2",conf_ak5_calo,[LM2])
        anal_ak5_caloMC.Run("../results_Baby/LM4",conf_ak5_calo,[LM4])

    anal_ak5_caloMC.Run("../results_Baby/tt",conf_ak5_calo,[ttbarTauola])
        
        #anal_ak7_caloMC.Run("../results_Baby/LM0",conf_ak7_calo,[LM0])
        #anal_ak7_caloMC.Run("../results_Baby/tt",conf_ak7_calo,[ttbarTauola])
        
        #anal_ak5_caloMC.Run("../results_Baby/W",conf_ak5_calo,[wjets_madgraph_edwardSkim])
        #anal_ak5_caloMC.Run("../results_Baby/Zinv",conf_ak5_calo,[Zinvisible_jets_edwardSkim])
        
        #anal_ak7_caloMC.Run("../results_Baby/W",conf_ak7_calo,[wjets_madgraph_edwardSkim])
        #anal_ak7_caloMC.Run("../results_Baby/Zinv",conf_ak7_calo,[Zinvisible_jets_edwardSkim])
               
        
    if(simpleTest == True) :
    
        anal_ak5_caloMC.Run("../results_Baby/W",conf_ak5_calo,[wjets_madgraph_edwardSkim])
        anal_ak5_caloMC.Run("../results_Baby/Zinv",conf_ak5_calo,[Zinvisible_jets_edwardSkim])
        
    

       
  

if(MC == False) : 

    anal_ak5_caloMC.Run("../results_Baby/Pythia6",conf_ak5_calo,QCD_PYTHIA6)
  #  anal_ak7_caloMC.Run("../results_Baby/Pythia6",conf_ak7_calo,QCD_PYTHIA6)
   
    anal_ak5_caloData.Run("../results_Baby/newnewData",conf_ak5_calo,[Edward_Data_Skim])
    #anal_ak7_caloData.Run("../results_Baby/Data",conf_ak7_calo,[Edward_Data_Skim])
       
