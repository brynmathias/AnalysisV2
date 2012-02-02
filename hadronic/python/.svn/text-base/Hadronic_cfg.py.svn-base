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

from hadronic.samples_cff import *

# -----------------------------------------------------------------------------
# Cut flow


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



# Object ID filters
#-----------------------------------------------------------------------
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *

vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
#vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP90ps.ps() )
#vbtMuonIdFilter      = Muon_IDFilter( vbtfmuonidps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )

def addCutFlowMC(a) :
    a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
    a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
#    a.AddMuonFilter("PreCC",vbtMuonIdFilter)
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

#anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[tanB3])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[tanB10])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM0])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM1])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM2])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[LM4])

#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[QCD_AllPtBins_7TeV_Pythia])

#ttbarTauola.FirstEntry = 0
#ttbarTauola.LastEntry = 199999
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[ttbarTauola])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[wjets_madgraph])
#anal_ak5_caloMC.Run("../results",conf_ak5_calo,[Zinvisible_jets])
