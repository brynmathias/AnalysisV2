#!/usr/bin/env python

from golden_cff import *
from icf.core import PSet
from SweetBatchSub import *
#Import your samples!
from libWPol import *
# Import the configuration
from wpol.muon_config import muon_id, conf

from montecarlo.PhotonJet import *
from montecarlo.QCD_Madgraph_1000_inf import *
from montecarlo.QCD_Madgraph_100_250 import *
from montecarlo.QCD_Madgraph_250_500 import *
from montecarlo.QCD_Madgraph_500_1000 import *
from montecarlo.QCD_Madgraph_50_100 import *

from JetMET_Run2010A_PromptReco_v4_03092010  import *
from montecarlo.LMx import *
from montecarlo.WJets_Madgraph import *
from montecarlo.TTBarTauola import *
from montecarlo.Zjets_madgraph import *
from montecarlo.Zinvisible_jets_pset import *
from montecarlo.QCD_Pythia6_allBins import *
from data.JetMETTau_ALL_230810 import *
from data.JetMET_Run2010A_PromptReco_v4_250810 import *
from data.edward_data_skim import *
from montecarlo.QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
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
from montecarlo.w_jets_mg_edwardSkim import *
from montecarlo.z_inv_mg_edwardSkim import *
from test import *

#
samples = []
#data = [JetMET_ALL_upto230810,JetMET_Run2010A_PromptReco_v4_250810]
#dataII = [JetMET_Run2010A_PromptReco_v4_03092010]
data = [Edward_Data_Skim]
MCphot = [
  pjets_madgraph_100_200,
  pjets_madgraph_200,
  pjets_madgraph_40,
  QCD_Madgraph_100_250,
  QCD_Madgraph_1000_inf,
#  QCD_Madgraph_50_100,
  QCD_Madgraph_250_500,
#  QCD_Madgraph_500_1000
  ]

MC = [
wjets_madgraph_edwardSkim,Zinvisible_jets_edwardSkim,
LM0,LM1,zjets_madgraph,
#wjets_madgraph,zjets_madgraph,Zinvisible_jets,
ttbarTauola,
#QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1,
#QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1,
#QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1,
#QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,
#QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1,
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
QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2
]

MCS = [QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2]


#Create Cut Trees!
#First Data!
RecoilMET_ov_SumETCut = OP_RecoilMET_ov_SumETCut(0.4);
MissedHTCut = OP_MissedHTCut(1.25);
#MHT_PFMET_Cut = OP_MHT_PFMET(1.5);
MHT_PFMET_Cut = OP_MHTPFMETDiffOvMeff(0.15);
AntibiasedDPhiCut = OP_biasedDPhiCut(0.5)
EventNoDump_LargePFMET = OP_EventNoDump("LargeMHTHT","LargeMHTHT")
EventNoDump_DPhi = OP_EventNoDump("LargeDPhi","LargeDPhi")
#EcalSpikeJetCleaner = OP_EcalSpikeJetCleaner()
FuckingPhotonCut = OP_PhotonKilledJet()
PhotonPT100 = OP_PhotonPtCut(120)
PhotonDR05 = OP_PhotonJetDRCut(0.5)
PlotPhotons250 = OP_PlotPhotons("Photons250")
PlotPhotons350 = OP_PlotPhotons("Photons235")
numComPhotons = OP_NumComPhotons("==",1)
ttWPlottingOpsMHT120 = RECO_ttWPlotting("ttW_AfterMHT120")
ttWPlottingOps100 = RECO_ttWPlotting("ttW_After250")
ttWPlottingOps350 = RECO_ttWPlotting("ttW_After350")
ttWPlottingOpsAT = RECO_ttWPlotting("ttW_AfterAT")
spikeFilter = OP_EcalSpikeCleaner()


psetS = PSet(
DirName      = "Afetr_350Gev",
MinObjects   = 2,
MaxObjects   = 9,
StandardPlots     = True,
)
HadStandard350 = HadronicCommonPlots(psetS.ps())
psetMHT = PSet(
DirName      = "Afetr_MHTGev",
MinObjects   = 2,
MaxObjects   = 9,
StandardPlots     = True,
)
HadStandardMHT = HadronicCommonPlots(psetMHT.ps())

psetHT = PSet(
DirName      = "Afetr_250Gev",
MinObjects   = 2,
MaxObjects   = 9,
StandardPlots = True,
)
HadStandard250= HadronicCommonPlots(psetHT.ps())


psetAT = PSet(
DirName      = "After_AlphaT_had",
MinObjects   = 2,
MaxObjects   = 9,
StandardPlots = True,
)
HadStandardAlpha = HadronicCommonPlots(psetAT.ps())


LepNumComLeptons = OP_NumComLeptons("==",0)
NumMuons1 = OP_NumComMuons("==", 0)
PFMETCut100toinfD = RECO_PFMETCut(100.0)
HadAlphaTCut = OP_HadAlphaTCut(0.55)
minDRMuonJetCut = RECO_MuonJetDRCut(0.5)
PFMTCut110 = RECO_PFMTCut(110.0)
CommonMHTCut = OP_CommonMHTCut(150)

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,spikeFilter)
cutTreeData.TAttach(spikeFilter,selection)
cutTreeData.TAttach(selection,JetTrigger)
cutTreeData.TAttach(JetTrigger,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,unCorLeadJetCut)
cutTreeData.TAttach(unCorLeadJetCut,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,oddJet)
cutTreeData.TAttach(oddJet,secondJetET)
cutTreeData.TAttach(secondJetET,badMuonINJet)
cutTreeData.TAttach(badMuonINJet,LepNumComLeptons)
cutTreeData.TAttach(LepNumComLeptons,NumMuons1)
cutTreeData.TAttach(NumMuons1,minDRMuonJetCut)
cutTreeData.TAttach(minDRMuonJetCut,numComPhotons)
cutTreeData.TAttach(numComPhotons,PhotonPT100)
cutTreeData.TAttach(PhotonPT100,PhotonDR05)
cutTreeData.TAttach(PhotonDR05,CommonMHTCut)
cutTreeData.TAttach(CommonMHTCut,HadStandardMHT)
cutTreeData.TAttach(HadStandardMHT,htCut250)
cutTreeData.TAttach(htCut250,LessThan350)
cutTreeData.TAttach(LessThan350,ttWPlottingOps100)
cutTreeData.TAttach(ttWPlottingOps100,PlotPhotons250)
cutTreeData.TAttach(HadStandardMHT,htCut350)
cutTreeData.TAttach(htCut350,HadStandard350)
cutTreeData.TAttach(HadStandard350,HadAlphaTCut)
cutTreeData.TAttach(HadAlphaTCut,HadStandardAlpha)
cutTreeData.TAttach(HadStandardAlpha,PlotPhotons350)


                    
cutTreeMC = Tree("MC")
cutTreeMC.Attach(selection)
cutTreeMC.TAttach(selection,LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,unCorLeadJetCut)
cutTreeMC.TAttach(unCorLeadJetCut,oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,oddJet)
cutTreeMC.TAttach(oddJet,secondJetET)
cutTreeMC.TAttach(secondJetET,badMuonINJet)
cutTreeMC.TAttach(badMuonINJet,LepNumComLeptons)
cutTreeMC.TAttach(LepNumComLeptons,NumMuons1)
cutTreeMC.TAttach(NumMuons1,minDRMuonJetCut)
cutTreeMC.TAttach(minDRMuonJetCut,numComPhotons)
cutTreeMC.TAttach(numComPhotons,PhotonPT100)
cutTreeMC.TAttach(PhotonPT100,PhotonDR05)
cutTreeMC.TAttach(PhotonDR05,CommonMHTCut)
cutTreeMC.TAttach(CommonMHTCut,HadStandardMHT)
cutTreeMC.TAttach(HadStandardMHT,htCut250)
cutTreeMC.TAttach(htCut250,LessThan350)
cutTreeMC.TAttach(LessThan350,ttWPlottingOps100)
cutTreeMC.TAttach(ttWPlottingOps100,PlotPhotons250)
cutTreeMC.TAttach(HadStandardMHT,htCut350)
cutTreeMC.TAttach(htCut350,HadStandard350)
cutTreeMC.TAttach(HadStandard350,HadAlphaTCut)
cutTreeMC.TAttach(HadAlphaTCut,HadStandardAlpha)
cutTreeMC.TAttach(HadStandardAlpha,PlotPhotons350)

def addCutFlowData(a) :
  a.AddJetFilter("PreCC",JetCorrections)
  a+=cutTreeData

def addCutFlowMC(b) :
  b+=cutTreeMC


# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

muonfilt=CustomMuonId(muon_id.ps())

# AK7 Calo

conf_ak7_caloMC = deepcopy(defaultConfig)
conf_ak7_caloMC.Ntuple = deepcopy(ak7_calo)
conf_ak7_caloMC.XCleaning = deepcopy(default_cc)
conf_ak7_caloMC.Common = deepcopy(default_common)
conf_ak7_caloMC.Common.print_out()
anal_ak7_caloMC=Analysis("AK7Calo")
anal_ak7_caloMC.AddMuonFilter("PostCC",muonfilt)
addCutFlowMC(anal_ak7_caloMC)

# AK7 Calo

conf_ak7_caloData = deepcopy(defaultConfig)
conf_ak7_caloData.Ntuple = deepcopy(ak7_calo)
conf_ak7_caloData.XCleaning = deepcopy(default_cc)
conf_ak7_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak7_caloData=Analysis("AK7Calo")
anal_ak7_caloData.AddMuonFilter("PostCC",muonfilt)
addCutFlowData(anal_ak7_caloData)

# AK5 Calo

conf_ak5_caloMC = deepcopy(defaultConfig)
conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
conf_ak5_caloMC.Common = deepcopy(default_common)
conf_ak5_caloMC.Common.print_out()
anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)

# AK5 Calo

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

# AK5 PF

conf_ak5_pfData = deepcopy(defaultConfig)
conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfData.XCleaning = deepcopy(default_cc)
conf_ak5_pfData.Common = deepcopy(default_common)
anal_ak5_pfData=Analysis("AK5PF")
addCutFlowData(anal_ak5_pfData)

# AK5 PF

conf_ak5_pfMC = deepcopy(defaultConfig)
conf_ak5_pfMC.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfMC.XCleaning = deepcopy(default_cc)
conf_ak5_pfMC.Common = deepcopy(default_common)
anal_ak5_pfMC=Analysis("AK5PF")
addCutFlowMC(anal_ak5_pfMC)
 
# AK5 JPT

conf_ak5_jptData = deepcopy(defaultConfig)
conf_ak5_jptData.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jptData.XCleaning = deepcopy(default_cc)
conf_ak5_jptData.Common = deepcopy(default_common)
# conf_ak5_jDatapt.Common.print_out()
anal_ak5_jptData=Analysis("AK5JPT")
addCutFlowData(anal_ak5_jptData)

# AK5 JPT

conf_ak5_jptMC = deepcopy(defaultConfig)
conf_ak5_jptMC.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jptMC.XCleaning = deepcopy(default_cc)
conf_ak5_jptMC.Common = deepcopy(default_common)
# conf_ak5_jMCpt.Common.print_out()
anal_ak5_jptMC=Analysis("AK5JPT")
addCutFlowMC(anal_ak5_jptMC)


# --------- --------------------------------------------------------------------
# Run analyses
#IMPERIAL COLLEGE
# -----------------------------------------------------------------------------
# Run analyses
#IMPERIAL COLLEGE

# CHANGE THE PATHS also please use absolute path.

BatchRun(MCphot,"anal_ak5_caloMC", "conf_ak5_caloMC","/vols/cms01/mstoye/Photon_Control_Sep24/MC_tight_PT120/",10000)
#BatchRun(data, "anal_ak5_caloData", "conf_ak5_caloData","/vols/cms01/mstoye/Photon_Control_Sep24/data_tight_PT120/",1)
#anal_ak7_caloMC.Run("../results_S24",conf_ak5_caloMC,[pjets_madgraph_200])
 
