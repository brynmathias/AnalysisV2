#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *
from icf.core import PSet
from SweetBatchSub import *
from plottingStuff_cfg import *
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
from montecarlo.w_jets_mg_edwardSkim import *
from montecarlo.z_jets_mg_edwardSkim import *
from montecarlo.z_inv_mg_edwardSkim import *

from montecarlo.tanBeta3 import *
from montecarlo.tanBeta10 import *

from data.edward_data_skim import * #skim of 38 data
from data.edward_data_skim_36 import * #skim of 36 data

from data.Ted_JetMETTau_Run2010A_ReReco_v2_RECO_RAW_Henning import *
from data.Ted_JetMET_Run2010A_ReReco_v2_RECO_RAW_Burt import *
from data.Ted_Jet_Run2010B_PromptReco_v2_RECO_RAW_Burt import *

samples = []
data = [Skim_JetMET_Run2010A_ReReco_v2_Reco_Raw,Skim_JetMETTau_Run2010A_ReReco_v2_Reco_Raw,Skim_Jet_Run2010B_PromptReco_v2_Reco_Raw]



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


# -----------------------------------------------------------------------------
# Common cut definitions



numComJets = OP_NumComJets(">=",2)
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

missedHT = OP_MissedHTCut(1.25)
alphaT = OP_CommonAlphaTCut(0.55)
MHTPFMETDiff = OP_MHTPFMETDiffOvMeff(0.15)
deadECAL = OP_DeadECALCut(0.3,"./deadRegionList_GR10_P_V10.txt")

# -----------------------------------------------------------------------------
# Cut flow



cutTreeMC = Tree("MC")
cutTreeMC.Attach(LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,numComJets)
cutTreeMC.TAttach(numComJets,numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)
cutTreeMC.TAttach(numComPhotons,oddJet)
cutTreeMC.TAttach(oddJet,oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,secondJetET)
cutTreeMC.TAttach(secondJetET,htCut)
cutTreeMC.TAttach(htCut,alphaT)

cutTreeMC.TAttach(alphaT,HadStandard_1)

cutTreeMC.TAttach(alphaT,deadECAL)
cutTreeMC.TAttach(deadECAL,HadStandard_2)

cutTreeMC.TAttach(alphaT,MHTPFMETDiff)
cutTreeMC.TAttach(MHTPFMETDiff,HadStandard_3)

cutTreeMC.TAttach(deadECAL,MHTPFMETDiff_2)
cutTreeMC.TAttach(MHTPFMETDiff_2,HadStandard_4)


cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
#cutTreeData.TAttach(NoiseFilt,HadStandard)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,JetTrigger)
cutTreeData.TAttach(JetTrigger,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,numComJets)
cutTreeData.TAttach(numComJets,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,oddJet)
cutTreeData.TAttach(oddJet,oddMuon)

cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,secondJetET)
cutTreeData.TAttach(secondJetET,htCut)
cutTreeData.TAttach(htCut,alphaT)

cutTreeData.TAttach(alphaT,HadStandard_1)

cutTreeData.TAttach(alphaT,deadECAL)
cutTreeData.TAttach(deadECAL,HadStandard_2)

cutTreeData.TAttach(alphaT,MHTPFMETDiff)
cutTreeData.TAttach(MHTPFMETDiff,HadStandard_3)

cutTreeData.TAttach(deadECAL,MHTPFMETDiff_2)
cutTreeData.TAttach(MHTPFMETDiff_2,HadStandard_4)


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

anal_ak5_caloData.Run("../results",conf_ak5_calo,data)

#anal_ak5_caloData.Run("../results",conf_ak5_calo,[Edward_Data_Skim])
   
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM0])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM1])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM2])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM4])

#anal_ak5_caloMC.Run("../results",conf_ak5_calo,QCD)
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,QCD_PYTHIA6)

anal_ak5_caloMC.Run("../results",conf_ak5_calo,[ttbarTauola])
anal_ak5_caloMC.Run("../results",conf_ak5_calo,[wjets_madgraph_edwardSkim])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[Zinvisible_jets_edwardSkim])
            

