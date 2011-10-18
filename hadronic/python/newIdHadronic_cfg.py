#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from hadronic.golden_cff import *
from icf.core import PSet
#from SweetBatchSub import *
from plottingStuff_cfg import *
from validation.cutCounters_cff import * #TW for convenience...
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
from data.Ted_Jet_Run2010B_PromptReco_v2_RECO_RAW_Burt2 import *
from data.Ted_MultiJet_Run2010B_PromptReco_v2_RECO_RAW_Burt import *
from data.Ted_MultiJet_Run2010B_PromptReco_v2_RECO_RAW_Burt2 import *

from data.MultiJet_json221010 import *
from data.edward_data_skim_allJetTo_Json151010 import *

samples = []
data = [All38SkimsUpto151010_Jet_MultiJet,MultiJet_json221010]



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
# Cut flow
#------------------------------------------------------------------------------
# See hadronic.golden_cff.py for cut flow definitions.

#Monte-Carlo samples
cutTreeMC = Tree("MC")
cutTreeMC.Attach(count_total)
cutTreeMC.TAttach(count_total,selection)
cutTreeMC.TAttach(selection,count_selection)
cutTreeMC.TAttach(selection,oddMuon)
cutTreeMC.TAttach(oddMuon,count_oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,count_oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,count_oddPhoton)
cutTreeMC.TAttach(oddPhoton,numComLeptons)
cutTreeMC.TAttach(numComLeptons,count_numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)
cutTreeMC.TAttach(numComPhotons,count_numComPhotons)
cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,count_LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,count_badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,oddJet)
cutTreeMC.TAttach(oddJet,count_oddJet)
cutTreeMC.TAttach(oddJet,LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,count_LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,numComJets)
cutTreeMC.TAttach(numComJets,count_numComJets)
cutTreeMC.TAttach(numComJets,secondJetET)
cutTreeMC.TAttach(secondJetET,count_secondJetET)
cutTreeMC.TAttach(secondJetET,htCut)
cutTreeMC.TAttach(htCut,count_htCut)
cutTreeMC.TAttach(htCut,alphaT)
cutTreeMC.TAttach(alphaT,count_alphaT)

cutTreeMC.TAttach(alphaT,HadStandard_1)

cutTreeMC.TAttach(alphaT,deadECAL_MC)
cutTreeMC.TAttach(deadECAL_MC,count_deadECAL)
cutTreeMC.TAttach(deadECAL_MC,HadStandard_2)

cutTreeMC.TAttach(alphaT,MHToverMET)
cutTreeMC.TAttach(MHToverMET,count_MHToverMET)
cutTreeMC.TAttach(MHToverMET,HadStandard_3)

cutTreeMC.TAttach(deadECAL_MC,MHToverMET_2)
cutTreeMC.TAttach(MHToverMET_2,count_MHToverMET_2)
cutTreeMC.TAttach(MHToverMET_2,HadStandard_4)
cutTreeMC.TAttach(HadStandard_4,plots_mSuGraScan_350)

#data samples
cutTreeData = Tree("Data")
cutTreeData.Attach(count_total)
cutTreeData.TAttach(count_total,NoiseFilt)
cutTreeData.TAttach(NoiseFilt,count_NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,count_selection)
cutTreeData.TAttach(selection,oddMuon)
cutTreeData.TAttach(oddMuon,count_oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,count_oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,count_oddPhoton)
cutTreeData.TAttach(oddPhoton,numComLeptons)
cutTreeData.TAttach(numComLeptons,count_numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,count_numComPhotons)
cutTreeData.TAttach(numComPhotons,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,count_LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,count_badMuonInJet)
cutTreeData.TAttach(badMuonInJet,oddJet)
cutTreeData.TAttach(oddJet,count_oddJet)
cutTreeData.TAttach(oddJet,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,count_LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,numComJets)
cutTreeData.TAttach(numComJets,count_numComJets)
cutTreeData.TAttach(numComJets,secondJetET)
cutTreeData.TAttach(secondJetET,count_secondJetET)
cutTreeData.TAttach(secondJetET,htCut)
cutTreeData.TAttach(htCut,count_htCut)
cutTreeData.TAttach(htCut,alphaT)
cutTreeData.TAttach(alphaT,count_alphaT)

cutTreeData.TAttach(alphaT,HadStandard_1)

cutTreeData.TAttach(alphaT,deadECAL_data)
cutTreeData.TAttach(deadECAL_data,HadStandard_2)
cutTreeData.TAttach(deadECAL_data,count_deadECAL)

cutTreeData.TAttach(alphaT,MHToverMET)
cutTreeData.TAttach(MHToverMET,count_MHToverMET)
cutTreeData.TAttach(MHToverMET,HadStandard_3)

cutTreeData.TAttach(deadECAL_data,MHToverMET_2)
cutTreeData.TAttach(MHToverMET_2,count_MHToverMET_2)
cutTreeData.TAttach(MHToverMET_2,HadStandard_4)
cutTreeData.TAttach(HadStandard_4,plots_mSuGraScan_350)

dump = OP_EventId("eventIds.txt")
cutTreeData.TAttach(MHToverMET_2,dump)

# Object ID filters
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *

vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidps.ps() )
vbtMuonIdFilter      = Muon_IDFilter( vbtfmuonidps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )

def addCutFlowMC(a) :
    a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
    a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
    a.AddMuonFilter("PreCC",vbtMuonIdFilter)
    a+=cutTreeMC

def addCutFlowData(b) :
    b.AddJetFilter("PreCC",JetCorrections)
    b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
    b.AddElectronFilter("PreCC",vbtfElectronIdFilter)
    b.AddMuonFilter("PreCC",vbtMuonIdFilter)
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

#conf_ak5_calo.XCleaning.Electrons.ElectronLooseIdRequired = True
#conf_ak5_calo.XCleaning.Electrons.ElectronTightIdRequired = False
#conf_ak5_calo.Common.Electrons.TightID = False

#anal_ak5_caloData.Run("../resultsnewid",conf_ak5_calo,[All38SkimsUpto151010_Jet_MultiJet]) #10.9357/pb
#anal_ak5_caloData.Run("../resultsnewid",conf_ak5_calo,[Skim_MultiJet_Run2010B_PromptReco_v2_Reco_Raw_2]) #4.1508/pb

#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[tanB3])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[tanB10])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[LM0])
#anal_ak5_caloMC.Run("../resultsnewidelWP95",conf_ak5_calo,[LM0])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[LM1])
#anal_ak5_caloMC.Run("../resultsnewidelWP95",conf_ak5_calo,[LM1])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[LM2])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[LM4])

#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,QCD)
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,QCD_PYTHIA6)

ttbarTauola.FirstEntry = 0
ttbarTauola.LastEntry = 199999
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[ttbarTauola])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[wjets_madgraph_edwardSkim])
#anal_ak5_caloMC.Run("../resultsnewid",conf_ak5_calo,[Zinvisible_jets_edwardSkim])
