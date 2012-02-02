#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *
from icf.core import PSet
#from SweetBatchSub import *
from plottingStuff_cfg import *
from validation.cutCounters_cff import * #TW for convenience...
# -----------------------------------------------------------------------------
# Local samples

from copy import deepcopy

from samples_cff import *

# -----------------------------------------------------------------------------
# Cut flow


NJetM = OP_NumComJets("==",2)
from SweetBatchSub import *


plots_mSuGraScan_beforeAll_10 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_beforeAll_10",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo1.0_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)

plots_mSuGraScan_beforeAll_20 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_beforeAll_20",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo2.0_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)

plots_mSuGraScan_beforeAll_05 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_beforeAll_05",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)



plots_mSuGraScan_350_10 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_350_10",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo1.0_tanssdat10.txt",
    ).ps()
)




plots_mSuGraScan_350_20 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_350_20",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo2.0_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)

plots_mSuGraScan_350_05 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_350_05",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)



plots_mSuGraScan_450_10 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_450_10",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo1.0_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)

plots_mSuGraScan_450_20 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_450_20",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo2.0_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)

plots_mSuGraScan_450_05 = OP_mSuGraPlottingOps(
    PSet(
    DirectoryName = "mSuGraScan_450_05",
    xBins = 150,
    xLow =0.,
    xHigh =1500.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tanssdat10.txt",#"msugraTanbeta3_05down.txt",
    ).ps()
)






LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(30.)
LeadingJetCut = OP_FirstJetPtCut(100.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(100.)
badMuonInJet = OP_BadMuonInJet()
LessThan300 = RECO_CommonHTLessThanCut(300.)
LessThan450 = RECO_CommonHTLessThanCut(450.)
htCut350 = RECO_CommonHTCut(350.)
htCut450 = RECO_CommonHTCut(450.)
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)
numComJets = OP_NumComJets(">=",2)
alphaT = HadronicAlphaT(0.55)
deadECAL_MC =   OP_DeadECALCut(0.3,0.5,30.,10,1,"./deadRegionList_START38_V12.txt")
MHToverMET = OP_MHToverMET(1.25)
#Monte-Carlo samples
cutTreeMC = Tree("MC")
cutTreeMC.Attach(count_total)
cutTreeMC.TAttach(count_total,selection)
cutTreeMC.TAttach(count_total,plots_mSuGraScan_beforeAll_05)
cutTreeMC.TAttach(count_total,plots_mSuGraScan_beforeAll_10)
cutTreeMC.TAttach(count_total,plots_mSuGraScan_beforeAll_20)
# cutTreeMC.TAttach(selection,count_selection)
cutTreeMC.TAttach(selection,oddMuon)
# cutTreeMC.TAttach(oddMuon,count_oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
# cutTreeMC.TAttach(oddElectron,count_oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
# cutTreeMC.TAttach(oddPhoton,count_oddPhoton)
cutTreeMC.TAttach(oddPhoton,numComLeptons)
# cutTreeMC.TAttach(numComLeptons,count_numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)
# cutTreeMC.TAttach(numComPhotons,count_numComPhotons)
cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
# cutTreeMC.TAttach(LeadingJetEta,count_LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,badMuonInJet)
# cutTreeMC.TAttach(badMuonInJet,count_badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,oddJet)
# cutTreeMC.TAttach(oddJet,count_oddJet)
cutTreeMC.TAttach(oddJet,LeadingJetCut)
# cutTreeMC.TAttach(LeadingJetCut,count_LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,numComJets)
# cutTreeMC.TAttach(numComJets,count_numComJets)
cutTreeMC.TAttach(numComJets,secondJetET)
# cutTreeMC.TAttach(secondJetET,count_secondJetET)
cutTreeMC.TAttach(secondJetET,htCut350)
# cutTreeMC.TAttach(htCut,count_htCut)
cutTreeMC.TAttach(htCut350,alphaT)
# cutTreeMC.TAttach(alphaT,count_alphaT)
#
# cutTreeMC.TAttach(alphaT,HadStandard_1)
cutTreeMC.TAttach(alphaT,deadECAL_MC)
# cutTreeMC.TAttach(deadECAL_MC,count_deadECAL)
# cutTreeMC.TAttach(deadECAL_MC,HadStandard_2)
cutTreeMC.TAttach(deadECAL_MC,MHToverMET)
# cutTreeMC.TAttach(MHToverMET,count_MHToverMET)
# cutTreeMC.TAttach(MHToverMET,HadStandard_3)
# cutTreeMC.TAttach(deadECAL_MC,MHToverMET_2)
# cutTreeMC.TAttach(MHToverMET_2,count_MHToverMET_2)
# cutTreeMC.TAttach(MHToverMET_2,HadStandard_4)

cutTreeMC.TAttach(MHToverMET,LessThan450)
cutTreeMC.TAttach(LessThan450,plots_mSuGraScan_350_05)
cutTreeMC.TAttach(LessThan450,plots_mSuGraScan_350_10)
cutTreeMC.TAttach(LessThan450,plots_mSuGraScan_350_20)
cutTreeMC.TAttach(MHToverMET,htCut450)
cutTreeMC.TAttach(htCut450,plots_mSuGraScan_450_05)
cutTreeMC.TAttach(htCut450,plots_mSuGraScan_450_10)
cutTreeMC.TAttach(htCut450,plots_mSuGraScan_450_20)



#
# #data samples
cutTreeData = Tree("Data")
# cutTreeData.Attach(count_total)
# cutTreeData.TAttach(count_total,NoiseFilt)
# cutTreeData.TAttach(NoiseFilt,count_NoiseFilt)
# cutTreeData.TAttach(NoiseFilt,selection)
# cutTreeData.TAttach(selection,count_selection)
# cutTreeData.TAttach(selection,oddMuon)
# cutTreeData.TAttach(oddMuon,count_oddMuon)
# cutTreeData.TAttach(oddMuon,oddElectron)
# cutTreeData.TAttach(oddElectron,count_oddElectron)
# cutTreeData.TAttach(oddElectron,oddPhoton)
# cutTreeData.TAttach(oddPhoton,count_oddPhoton)
# cutTreeData.TAttach(oddPhoton,numComLeptons)
# cutTreeData.TAttach(numComLeptons,count_numComLeptons)
# cutTreeData.TAttach(numComLeptons,numComPhotons)
# cutTreeData.TAttach(numComPhotons,count_numComPhotons)
# cutTreeData.TAttach(numComPhotons,LeadingJetEta)
# cutTreeData.TAttach(LeadingJetEta,count_LeadingJetEta)
# cutTreeData.TAttach(LeadingJetEta,badMuonInJet)
# cutTreeData.TAttach(badMuonInJet,count_badMuonInJet)
# cutTreeData.TAttach(badMuonInJet,oddJet)
# cutTreeData.TAttach(oddJet,count_oddJet)
# cutTreeData.TAttach(oddJet,LeadingJetCut)
# cutTreeData.TAttach(LeadingJetCut,count_LeadingJetCut)
# cutTreeData.TAttach(LeadingJetCut,numComJets)
# cutTreeData.TAttach(numComJets,count_numComJets)
# cutTreeData.TAttach(numComJets,secondJetET)
# cutTreeData.TAttach(secondJetET,count_secondJetET)
# cutTreeData.TAttach(secondJetET,htCut)
# cutTreeData.TAttach(htCut,count_htCut)
# cutTreeData.TAttach(htCut,HadStandard_1)
# cutTreeData.TAttach(HadStandard_1,alphaT)
# cutTreeData.TAttach(alphaT,count_alphaT)
#
#
# cutTreeData.TAttach(alphaT,deadECAL_data)
# cutTreeData.TAttach(deadECAL_data,HadStandard_2)
# cutTreeData.TAttach(deadECAL_data,count_deadECAL)
#
# cutTreeData.TAttach(alphaT,MHToverMET)
# cutTreeData.TAttach(MHToverMET,count_MHToverMET)
# cutTreeData.TAttach(MHToverMET,HadStandard_3)
#
# cutTreeData.TAttach(deadECAL_data,MHToverMET_2)
# cutTreeData.TAttach(MHToverMET_2,count_MHToverMET_2)
# cutTreeData.TAttach(MHToverMET_2,HadStandard_4)
# cutTreeData.TAttach(MHToverMET_2,EventNoDump_DPhi)
# cutTreeData.TAttach(HadStandard_4,plots_mSuGraScan_350)




# Object ID filters
#-----------------------------------------------------------------------
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *

vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
#vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP90ps.ps() )
#vbtMuonIdFilter      = Muon_IDFilter( vbtfmuonidps.ps() )
ra3PhotonIdFilter  = Photon_IDFilter( ra3photonidps.ps() )

JESUncert = JESUncert(0.1,False,True)


def addCutFlowMC(a) :
  a.AddJetFilter("PreCC",JESUncert)
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a+=cutTreeMC

def addCutFlowData(b) :
    b.AddJetFilter("PreCC",JetCorrections)
    b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
    b.AddElectronFilter("PreCC",vbtfElectronIdFilter)
#    b.AddMuonFilter("PreCC",vbtMuonIdFilter)
    b+=cutTreeData


#    a+=debug_hadronic

# -----------------------------------------------------------------------------
# Definition of analyses


#MC
anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)

anal_ak7_caloMC=Analysis("AK7Calo")
addCutFlowMC(anal_ak7_caloMC)


#data

anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)
anal_ak7_caloData=Analysis("AK7Calo")
addCutFlowData(anal_ak7_caloData)



# -----------------------------------------------------------------------------
# Run analyses

#anal_ak5_caloData.Run("../results",conf_ak5_calo,[Jet_15pb_WithTP_json221010]) #10.9357/pb
# from MultiJet_Run2010B_PromptReco_v2_408 import *
#anal_ak5_caloData.Run("../results",conf_ak5_calo,[MultiJet_Run2010B_PromptReco_v2])
# from Newdata import *
#anal_ak5_caloData.Run("../results",conf_ak5_calo,[Newdata])
# from data.edward_data_skim import *
#anal_ak5_caloData.Run("/vols/cms01/mstoye/AN_had/newdata350_15_7/",conf_ak5_calo,[Jet_15pb_WithTP_json221010])
#BatchRun([MultiJet_Run2010B_PromptReco_v2],"anal_ak5_caloData", "conf_ak5_calo","/vols/cms01/mstoye/AN_had/newdata350_35_3/",2)
atestFile = PSet(
Name="TestT4",
Format=("ICF",2),
File=
[
# "~/WokringDir/rootFiles/SusyCAF_Tree_100_1_UK9.root",
# "~/WokringDir/rootFiles/SusyCAF_Tree_14_1_jrs.root",
"~/WokringDir/rootFiles/SusyCAF_Tree_490_1_G4r.root"
],
CrossSection = 1.,
# FirstEntry = 0,
# LastEntry = 1000,
)

from montecarlo.PhysicsProcesses_TopologyT1_38xFall10_spadhi_PhysicsProcesses_TopologyT1_38xFall10_f959c379445f9d7540d41cf9ffa87a96 import *
from montecarlo.PhysicsProcesses_TopologyT2_38xFall10_spadhi_PhysicsProcesses_TopologyT2_38xFall10_f959c379445f9d7540d41cf9ffa87a96 import *
from montecarlo.PhysicsProcesses_TopologyT3_38xFall10_spadhi_PhysicsProcesses_TopologyT3_38xFall10_d29e4f3917076227642d4f571bcff7fa import *
from montecarlo.PhysicsProcesses_TopologyT4_38xFall10_spadhi_PhysicsProcesses_TopologyT4_38xFall10_7e3d0954d994b653c9c6cafe6f6b4102 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta10Fall10_spadhi_PhysicsProcesses_mSUGRA_tanbeta10Fall10_89b6a3994a6055d40027085b0a39a60b import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta3Fall10v1 import *
# from montecarlo.PhysicsProcesses_mSUGRA_tanbeta10Fall10v1 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta50Fall10 import *
samples = [
# PhysicsProcesses_mSUGRA_tanbeta3Fall10v1,
# PhysicsProcesses_mSUGRA_tanbeta10Fall10v1,
# PhysicsProcesses_mSUGRA_tanbeta50Fall10,
# PhysicsProcesses_TopologyT1_38xFall10_spadhi_PhysicsProcesses_TopologyT1_38xFall10_f959c379445f9d7540d41cf9ffa87a96,
# PhysicsProcesses_TopologyT2_38xFall10_spadhi_PhysicsProcesses_TopologyT2_38xFall10_f959c379445f9d7540d41cf9ffa87a96,
# PhysicsProcesses_TopologyT3_38xFall10_spadhi_PhysicsProcesses_TopologyT3_38xFall10_d29e4f3917076227642d4f571bcff7fa,
# PhysicsProcesses_TopologyT4_38xFall10_spadhi_PhysicsProcesses_TopologyT4_38xFall10_7e3d0954d994b653c9c6cafe6f6b4102,
# PhysicsProcesses_mSUGRA_tanbeta10Fall10_spadhi_PhysicsProcesses_mSUGRA_tanbeta10Fall10_89b6a3994a6055d40027085b0a39a60b
]


anal_ak5_caloMC.Run("../results/PhysicsProcesses_mSUGRA_tanbeta10Retry",conf_ak5_calo_msugra,[PhysicsProcesses_mSUGRA_tanbeta10Fall10v1])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[tanB10])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM0])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM1_SUSY_sftsht_7TeV_pythia6_Fall10_START38_V12_v1])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM2])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM4])

#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[QCD_AllPtBins_7TeV_Pythia])

#ttbarTauola.FirstEntry = 0
#ttbarTauola.LastEntry = 250000
#anal_ak5_caloMC.Run("../BjatTest",conf_ak5_calo,[ttbarTauola])
# from montecarlo.w_jets_mg_edwardSkim2 import *
#anal_ak5_caloMC.Run("../muon_test",conf_ak5_calo,[wjets_madgraph_edwardSkim2])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[Zinvisible_jets])
