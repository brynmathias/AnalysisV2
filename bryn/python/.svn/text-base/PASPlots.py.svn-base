#!/usr/bin/env python

from golden_cff import *
from icf.core import PSet
from SweetBatchSub import *

#Import your samples!

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

from montecarlo.tanBeta10 import *

#
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
MC = [
LM0,LM1,QCD_AllPtBins_7TeV_Pythia,wjets_madgraph,zjets_madgraph,Zinvisible_jets,
ttbarTauola,
QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,
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
QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2,
]



#Create Cut Trees!
#First Data!

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,JetTrigger)
cutTreeData.TAttach(JetTrigger,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,unCorLeadJetCut)
cutTreeData.TAttach(unCorLeadJetCut,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,oddJet)
cutTreeData.TAttach(oddJet,secondJetET)
cutTreeData.TAttach(secondJetET,badMuonINJet)
cutTreeData.TAttach(badMuonINJet,missedMHT)
cutTreeData.TAttach(missedMHT,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)

##########Bkgd Studies
cutTreeData.TAttach(numComPhotons,plots_bkgdEstPlots_g1jets)
cutTreeData.TAttach(plots_bkgdEstPlots_g1jets,plots_bkgdEstPlots_2jets)
cutTreeData.TAttach(plots_bkgdEstPlots_2jets,plots_bkgdEstPlots_g2jets)



##########DiJet Studies
cutTreeData.TAttach(numComPhotons,htCut150)
cutTreeData.TAttach(htCut150,dalitz_plots_Inclusive)
cutTreeData.TAttach(htCut150,DiJet3)
cutTreeData.TAttach(DiJet3,HadStandardAll)
cutTreeData.TAttach(htCut150,NJet3)
cutTreeData.TAttach(NJet3,nHadStandardAll)
cutTreeData.TAttach(htCut150,LessThan250)
cutTreeData.TAttach(LessThan250,dalitz_plots_150_250)
cutTreeData.TAttach(LessThan250,DiJet0)
cutTreeData.TAttach(LessThan250,NJet0)
cutTreeData.TAttach(DiJet0,HadStandard150_250)
cutTreeData.TAttach(NJet0,nHadStandard150_250)

cutTreeData.TAttach(numComPhotons,htCut250)
cutTreeData.TAttach(htCut250,LessThan350)
cutTreeData.TAttach(LessThan350,dalitz_plots_250_350)
cutTreeData.TAttach(LessThan350,DiJet1)
cutTreeData.TAttach(LessThan350,NJet1)
cutTreeData.TAttach(DiJet1,HadStandard250_350)
cutTreeData.TAttach(NJet1,nHadStandard250_350)

cutTreeData.TAttach(numComPhotons,htCut350)
cutTreeData.TAttach(htCut350,dalitz_plots_350)
cutTreeData.TAttach(htCut350,DiJet2)
cutTreeData.TAttach(htCut350,NJet2)
cutTreeData.TAttach(DiJet2,alphaT0)
cutTreeData.TAttach(NJet2,alphaT1)
cutTreeData.TAttach(DiJet2,HadStandard350)
cutTreeData.TAttach(NJet2,nHadStandard350)

#change of default settings
default_common.Jets.PtCut=50.0
secondJetET = OP_SecondJetEtCut(100.)

#Second MC!

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
cutTreeMC.TAttach(badMuonINJet,numComLeptons)
cutTreeMC.TAttach(numComLeptons,missedMHT)
cutTreeMC.TAttach(missedMHT,numComPhotons)

##########Bkgd Studies
cutTreeMC.TAttach(numComPhotons,plots_bkgdEstPlots_g1jets)
cutTreeMC.TAttach(plots_bkgdEstPlots_g1jets,plots_bkgdEstPlots_2jets)
cutTreeMC.TAttach(plots_bkgdEstPlots_2jets,plots_bkgdEstPlots_g2jets)


##########DiJet Studies
cutTreeMC.TAttach(numComPhotons,htCut150)
cutTreeMC.TAttach(htCut150,dalitz_plots_Inclusive)
cutTreeMC.TAttach(htCut150,DiJet3)
cutTreeMC.TAttach(DiJet3,HadStandardAll)
cutTreeMC.TAttach(htCut150,NJet3)
cutTreeMC.TAttach(NJet3,nHadStandardAll)

cutTreeMC.TAttach(htCut150,LessThan250)
cutTreeMC.TAttach(LessThan250,dalitz_plots_150_250)
cutTreeMC.TAttach(LessThan250,DiJet0)
cutTreeMC.TAttach(LessThan250,NJet0)
cutTreeMC.TAttach(DiJet0,HadStandard150_250)
cutTreeMC.TAttach(NJet0,nHadStandard150_250)

cutTreeMC.TAttach(numComPhotons,htCut250)
cutTreeMC.TAttach(htCut250,LessThan350)
cutTreeMC.TAttach(LessThan350,dalitz_plots_250_350)
cutTreeMC.TAttach(LessThan350,DiJet1)
cutTreeMC.TAttach(LessThan350,NJet1)
cutTreeMC.TAttach(DiJet1,HadStandard250_350)
cutTreeMC.TAttach(NJet1,nHadStandard250_350)

cutTreeMC.TAttach(numComPhotons,htCut350)
cutTreeMC.TAttach(htCut350,dalitz_plots_350)
cutTreeMC.TAttach(htCut350,DiJet2)
cutTreeMC.TAttach(htCut350,NJet2)
cutTreeMC.TAttach(DiJet2,alphaT0)
cutTreeMC.TAttach(NJet2,alphaT1)
cutTreeMC.TAttach(alphaT0,HadStandard350)
cutTreeMC.TAttach(alphaT1,nHadStandard350)


#Third! MSUGRA!

cutTreeMSUGRA = Tree("MSUGRA")
cutTreeMSUGRA.Attach(selection)
cutTreeMSUGRA.TAttach(selection,plots_mSuGraScan_beforeAll)
cutTreeMSUGRA.TAttach(plots_mSuGraScan_beforeAll,LeadingJetEta)
cutTreeMSUGRA.TAttach(LeadingJetEta,unCorLeadJetCut)
cutTreeMSUGRA.TAttach(unCorLeadJetCut,oddMuon)
cutTreeMSUGRA.TAttach(oddMuon,oddElectron)
cutTreeMSUGRA.TAttach(oddElectron,oddPhoton)
cutTreeMSUGRA.TAttach(oddPhoton,oddJet)
cutTreeMSUGRA.TAttach(oddJet,secondJetET)
cutTreeMSUGRA.TAttach(secondJetET,badMuonINJet)
cutTreeMSUGRA.TAttach(badMuonINJet,numComLeptons)
cutTreeMSUGRA.TAttach(numComLeptons,missedMHT)
cutTreeMSUGRA.TAttach(missedMHT,numComPhotons)

##########Bkgd Studies
#cutTreeMSUGRA.TAttach(numComPhotons,plots_bkgdEstPlots_g1jets_MSUGRA)
#cutTreeMSUGRA.TAttach(plots_bkgdEstPlots_g1jets_MSUGRA,plots_bkgdEstPlots_2jets_MSUGRA)
#cutTreeMSUGRA.TAttach(plots_bkgdEstPlots_2jets_MSUGRA,plots_bkgdEstPlots_g2jets_MSUGRA)


##########DiJet Studies
#cutTreeMSUGRA.TAttach(plots_mSuGraScan_beforeAll,numComPhotons)

#from 150 < HT < 350 GeV
cutTreeMSUGRA.TAttach(numComPhotons,htCut150)
cutTreeMSUGRA.TAttach(htCut150,LessThan250)
cutTreeMSUGRA.TAttach(LessThan250,plots_mSuGraScan_before_150)
cutTreeMSUGRA.TAttach(plots_mSuGraScan_before_150,alphaT0_150)
cutTreeMSUGRA.TAttach(alphaT0_150,plots_mSuGraScan_150)

#from 250 < HT < 350 GeV
cutTreeMSUGRA.TAttach(numComPhotons,htCut250)
cutTreeMSUGRA.TAttach(htCut250,LessThan350)
cutTreeMSUGRA.TAttach(LessThan350,plots_mSuGraScan_before_250)
cutTreeMSUGRA.TAttach(plots_mSuGraScan_before_250,alphaT0_250)
cutTreeMSUGRA.TAttach(alphaT0_250,plots_mSuGraScan_250)

#HT > 350
cutTreeMSUGRA.TAttach(numComPhotons,htCut350)
cutTreeMSUGRA.TAttach(htCut350,plots_mSuGraScan_before_350)
cutTreeMSUGRA.TAttach(plots_mSuGraScan_before_350,alphaT0)
cutTreeMSUGRA.TAttach(alphaT0,plots_mSuGraScan_350)







#######End of NJet Studies

def addCutFlowData(a) :
  a.AddJetFilter("PreCC",JetCorrections)
  a+=cutTreeData

def addCutFlowMC(b) :
  b+=cutTreeMC

def addCutFlowMSUGRA(c):
  c+=cutTreeMSUGRA


# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

# AK5 Calo MC

conf_ak5_caloMC = deepcopy(defaultConfig)
conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
conf_ak5_caloMC.Common = deepcopy(default_common)
conf_ak5_caloMC.Common.print_out()
anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)

# AK5 Calo MSUGRA

conf_ak5_caloMSUGRA = deepcopy(defaultConfig)
conf_ak5_caloMSUGRA.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMSUGRA.Ntuple.Weight="mSuGra"
conf_ak5_caloMSUGRA.XCleaning = deepcopy(default_cc)
conf_ak5_caloMSUGRA.Common = deepcopy(default_common)
conf_ak5_caloMSUGRA.Common.print_out()
anal_ak5_caloMSUGRA=Analysis("AK5Calo")
addCutFlowMSUGRA(anal_ak5_caloMSUGRA)

# AK5 Calo DATA

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

#
# # AK5 PF
#
# conf_ak5_pfData = deepcopy(defaultConfig)
# conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
# conf_ak5_pfData.XCleaning = deepcopy(default_cc)
# conf_ak5_pfData.Common = deepcopy(default_common)
# anal_ak5_pfData=Analysis("AK5PF")
# addCutFlowData(anal_ak5_pfData)
#
# # AK5 PF
#
# conf_ak5_pfMC = deepcopy(defaultConfig)
# conf_ak5_pfMC.Ntuple = deepcopy(ak5_pf)
# conf_ak5_pfMC.XCleaning = deepcopy(default_cc)
# conf_ak5_pfMC.Common = deepcopy(default_common)
# anal_ak5_pfMC=Analysis("AK5PF")
# addCutFlowMC(anal_ak5_pfMC)
#
# # AK5 JPT
#
# conf_ak5_jptData = deepcopy(defaultConfig)
# conf_ak5_jptData.Ntuple = deepcopy(ak5_jpt)
# conf_ak5_jptData.XCleaning = deepcopy(default_cc)
# conf_ak5_jptData.Common = deepcopy(default_common)
# # conf_ak5_jDatapt.Common.print_out()
# anal_ak5_jptData=Analysis("AK5JPT")
# addCutFlowData(anal_ak5_jptData)
#
# # AK5 JPT
#
# conf_ak5_jptMC = deepcopy(defaultConfig)
# conf_ak5_jptMC.Ntuple = deepcopy(ak5_jpt)
# conf_ak5_jptMC.XCleaning = deepcopy(default_cc)
# conf_ak5_jptMC.Common = deepcopy(default_common)
# # conf_ak5_jMCpt.Common.print_out()
# anal_ak5_jptMC=Analysis("AK5JPT")
# addCutFlowMC(anal_ak5_jptMC)




# -----------------------------------------------------------------------------
# Run analyses
#IMPERIAL COLLEGE
#anal_ak5_caloData.Run("../results_PAS",conf_ak5_caloData,[Edward_Data_Skim])
BatchRun([Edward_Data_Skim],"anal_ak5_caloData","conf_ak5_caloData","/vols/cms01/trommers/Haddata_PAS/",20)
BatchRun(QCD,"anal_ak5_caloMC", "conf_ak5_caloMC","/vols/cms01/trommers/Haddata_PAS/",1000)
#BatchRun([tanB3],"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA","/vols/cms01/trommers/Haddata_PAS/",20)
#BatchRun([tanB10],"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA","/vols/cms01/trommers/Haddata_PAS/",20)

anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[wjets_madgraph_edwardSkim])
anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[zjets_madgraph_edwardSkim])
anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[Zinvisible_jets_edwardSkim])
anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM0])
anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM1])
anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[ttbarTauola])



#BatchRun(data, "anal_ak5_caloData", "conf_ak5_caloData","/vols/cms01/trommers/Haddata_PAS/",20)
#BatchRun([tanB3],"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA","/vols/cms01/trommers/Haddata_PAS/",20)
#BatchRun([tanB10],"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA","/vols/cms01/trommers/Haddata_PAS/",20)
#BatchRun([QCD_AllPtBins_7TeV_Pythia],"anal_ak5_caloMC","/vols/cms01/trommers/Haddata_PAS/",1000)
#anal_ak5_caloMSUGRA.Run("../results_PAS",conf_ak5_caloMSUGRA,[tanB3])
#anal_ak5_caloMSUGRA.Run("../results_PAS",conf_ak5_caloMSUGRA,[tanB10])

#anal_ak5_caloData.Run("../results_PAS",conf_ak5_caloData,data)
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM0])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM1])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM2])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM3])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM4])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[LM5])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[wjets_madgraph])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[zjets_madgraph])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[ttbarTauola])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[Zinvisible_jets])
#anal_ak5_caloMC.Run("../results_PAS",conf_ak5_caloMC,[QCD_AllPtBins_7TeV_Pythia])

# anal_ak5_pfData.Run("../results_PAS/",conf_ak5_pfData,[allData])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[LM0])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[LM1])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[LM2])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[LM3])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[LM4])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[LM5])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[wjets_madgraph])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[zjets_madgraph])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[ttbarTauola])
# anal_ak5_pfMC.Run("../results_PAS",conf_ak5_pfMC,[Zinvisible_jets])

# anal_ak5_jptData.Run("../results_PAS/",conf_ak5_jptData,[allData])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[LM0])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[LM1])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[LM2])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[LM3])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[LM4])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[LM5])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[wjets_madgraph])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[zjets_madgraph])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[ttbarTauola])
# anal_ak5_jptMC.Run("../results_PAS",conf_ak5_jptMC,[Zinvisible_jets])

