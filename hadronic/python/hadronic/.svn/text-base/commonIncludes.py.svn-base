# Lets keep this as a place for cuts and a basic cut flow deffinition,:
# Plots etc are not decalred here, declare them in your cut flow
# Object counting not needed as this is done in each of the Jet bins....
# The clutter made by a lot of counting operations (as well as the speed reduction) is unwanted!
# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy
from icf.JetCorrections import *

# Common cut definitions
#========================
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#
#jet multiplicity
numComJetsGeq2  = OP_NumComJets(">=",2)
numComJetsEq2   = OP_NumComJets("==",2)
numComJetsGeq   = OP_NumComJets(">=",3)

#JetTrigger = OP_TriggerCut("HLT_HT100U")
#new trigger operations (TW)
#This will be changing in the new run to the HLT_HTXXX_AlphaT0pYY triggers
datatriggerps = PSet(
    Verbose = False,
    Triggers = [
        "HLT_HT100U",
        "HLT_HT120U",
        "HLT_HT140U",
        "HLT_HT150U_v3",
        "HLT_HT160U_v1",
        "HLT_HT160U_v3",
        ]
    )
DataTrigger = OP_HadronicDataTrigger( datatriggerps.ps() )

#MC trigger - uses second jet collection (IC5, uncorrected) to act as trigger emulator.
mctriggerps = PSet(
    Verbose = False,
    JetPtCut = 20.,
    HTCut = 140.,
    )
mcTrigger   = OP_HadronicMCTrigger( mctriggerps.ps() )

#NoiseFilt = OP_HadronicHBHEnoiseFilter()
NoiseFilt   = OP_HadronicHBHEnoiseFilter()
VertexPtOverHT = OP_SumVertexPtOverHT(0.1)
#Standard Event Selection
selection   = OP_GoodEventSelection()

#odd objects
oddMuon     = OP_OddMuon()
#
oddElectron = OP_OddElectron()
#
oddPhoton   = OP_OddPhoton()
#object vetoes
numComLeptons = OP_NumComLeptons("<=",0)
#
numComElectrons = OP_NumComElectrons("<=",0)
#
numComMuons = OP_NumComMuons("<=",0)
#
numComPhotons = OP_NumComPhotons("<=",0)
# jet vetoes
badMuonInJet = OP_BadMuonInJet()
#
oddJet = OP_OddJet()
#
ht275     = RECO_CommonHTCut(275.)
ht325     = RECO_CommonHTCut(325.)
ht375     = RECO_CommonHTCut(375.)
ht475     = RECO_CommonHTCut(475.)
ht575     = RECO_CommonHTCut(575.)
ht675     = RECO_CommonHTCut(675.)
ht775     = RECO_CommonHTCut(775.)
ht875     = RECO_CommonHTCut(875.)
htLess325 = RECO_CommonHTLessThanCut(325.)
htLess375 = RECO_CommonHTLessThanCut(375.)
htLess475 = RECO_CommonHTLessThanCut(475.)
htLess575 = RECO_CommonHTLessThanCut(575.)
htLess675 = RECO_CommonHTLessThanCut(675.)
htLess775 = RECO_CommonHTLessThanCut(775.)
htLess875 = RECO_CommonHTLessThanCut(875.)

ht250 = RECO_CommonHTCut(250.)
ht300 = RECO_CommonHTCut(300.)
ht350 = RECO_CommonHTCut(350.)
ht450 = RECO_CommonHTCut(450.)
htLess300 = RECO_CommonHTLessThanCut(300.)
htLess350 = RECO_CommonHTLessThanCut(350.)
htLess450 = RECO_CommonHTLessThanCut(450.)





#leading and second jet requirements
LeadingJetEta = OP_FirstJetEta(2.5)
#
LeadingJetCut = OP_FirstJetPtCut(100.) #redundant
#
secondJetET = OP_SecondJetEtCut(100.)
#endgame
htCut350 = RECO_CommonHTCut(350.)
#
htCutLess350 = RECO_CommonHTLessThanCut(350.)
#
htCutM300 = RECO_CommonHTCut(300.)
#
htCutLess300 = RECO_CommonHTLessThanCut(300.)
#
htCut250 = RECO_CommonHTCut(250.)
#
htCutLess250 = RECO_CommonHTLessThanCut(250.)
#
#final cuts
alphaT = OP_CommonAlphaTCut(0.55)
#Add in as many as needed here::::AlphaT cuts
#Dead Ecal Cut to change
#dead ECAL set (dR cut, biasd DPhi cut, babyJet pt cut, nBadCell cut, take Map from File flag, dead region file)
#dead ECAL (data)
deadECALdata2om_250_300 = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
deadECALdata2eq_250_300 = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
deadECALdata3om_250_300 = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
#
deadECALdata2om_300_350 = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
deadECALdata2eq_300_350 = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
deadECALdata3om_300_350 = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
#
deadECALdata2om_350plus = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
deadECALdata2eq_350plus = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
deadECALdata3om_350plus = OP_DeadECALCut(0.3,0.3,0.5,30.,10,0,"./deadRegionList_GR10_P_V10.txt") #file for data
#
#dead ECAL (Monte Carlo)
deadECALmc2om_250_300   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
deadECALmc2eq_250_300   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
deadECALmc3om_250_300   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
#
deadECALmc2om_300_350   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
deadECALmc2eq_300_350   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
deadECALmc3om_300_350   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
#
deadECALmc2om_350plus   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
deadECALmc2eq_350plus   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC
deadECALmc3om_350plus   = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START36_V9.txt") #file for MC

# MHT/MET cut -- To be deprecieated
MHToverMET   = OP_MHToverMET(1.25,50.)

# MHT/PFMET cut -- use when doing PF analysis
MHToverPFMET   = OP_MHToverPFMET(1.25)
#
#eventDump = OP_EventNoDump("mydump","mydump")
#EventNoDump_DPhi_2om = OP_EventNoDump("LargeDPhi_2om","LargeDPhi_2om")

#Feel free to add anything useful in here
#-----------------------------------------------------------------------------



