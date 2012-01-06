#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
from icf.core import PSet,Analysis
# The leptonic specicif settings&files
from onelepton_settings import *
from onelepton_BSM_Grids import *
from onelepton_MC_samples import *
from onelepton_Cuts_Plots import *
from onelepton_Data_samples import *

# here a few flags to ensure you correct all instances
#data_typeBool = "data39Bool"
#data_typeBool = "data4XBool"
data_typeBool  = "MCBool"
#data_typeBool  = "MCGrid"

# muon specific cuts
triggerDATA = Mix2Triggers(147196,"HLT_Mu9","HLT_Mu15_v1")
OneMu      = OP_NumComMuons("==",1)
OneLooseMu = NumOfLooseMuons("==",1)
ZeroLooseEl = NumOfLooseElectrons("==",0)

# muon specific plots/trees START
# AnalysisTree code inputs 
fillLightTree_cfg = PSet(
    LeptonType = "Muons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = False ## False for DATA, True for MC
    )
AnalysisTree = AnalysisTree_HighPt("MuonTree", fillLightTree_cfg.ps())



# muon specific plots/trees END

# the analysis
sig=Analysis("default_Muons")

# Muon definition
Mus = PSet(
    MuID = "Tight",
    MinPt = 10.,
    MaxEta = 2.1,
    MaxIsolation = 0.05,
    MaxGlbTrkDxy = 0.02,
    MinGlbTrkNumOfValidHits = 11,
    MaxGlbTrkChi2ndf = 10.
    )
customMuID = CustomVBTFMuID(Mus.ps())
sig.AddMuonFilter("PreCC",customMuID)

# the residual JetCorrections are different from PF and Calo, so be careful when adding them.
if data_typeBool == "data39Bool":
 sig.AddJetFilter("PreCC",JetCorrections) 

tree = Tree("Main")    
sig+=tree
## Main trunk of tree
## The first two is are true for data
if data_typeBool == "data39Bool":
    tree.Attach(triggerDATA)
    tree.TAttach(triggerDATA,selection)
elif data_typeBool == "data4XBool":
   tree.Attach(triggerDATA)
   tree.TAttach(triggerDATA,selection)
else: # else true for MC only !! 
    tree.Attach(selection)

tree.TAttach(selection,OneMu)
tree.TAttach(OneMu,OneLooseMu)
tree.TAttach(OneLooseMu,ZeroLooseEl)
tree.TAttach(ZeroLooseEl,AtLeast1Jts)
tree.TAttach(AtLeast1Jts,AnalysisTree)
tree.TAttach(AnalysisTree,PFMETCut100)
tree.TAttach(PFMETCut100,AtLeast2Jts)
tree.TAttach(AtLeast2Jts,myRECO_CommonHTCut)

#first Meff Bin
tree.TAttach(myRECO_CommonHTCut,PFMeffWCut500)
tree.TAttach(PFMeffWCut500,PFMeffWCut750S)
tree.TAttach(PFMeffWCut750S,RECO_ttWPlotting_500)
tree.TAttach(RECO_ttWPlotting_500,myCountsAndBSMGrids_500_pre_LP)
tree.TAttach(myCountsAndBSMGrids_500_pre_LP,PFLPCut500)
tree.TAttach(PFLPCut500,myCountsAndBSMGrids_500)
tree.TAttach(myCountsAndBSMGrids_500,RECO_ttWPlotting_500_post_LP)

#secvond Meff Bin
tree.TAttach(myRECO_CommonHTCut,PFMeffWCut750)
tree.TAttach(PFMeffWCut750,PFMeffWCut1000S)
tree.TAttach(PFMeffWCut1000S,RECO_ttWPlotting_750)
tree.TAttach(RECO_ttWPlotting_750,myCountsAndBSMGrids_750_pre_LP)
tree.TAttach(myCountsAndBSMGrids_750_pre_LP,PFLPCut750)
tree.TAttach(PFLPCut750,myCountsAndBSMGrids_750)
tree.TAttach(myCountsAndBSMGrids_750,RECO_ttWPlotting_750_post_LP)

#third Meff Bin
tree.TAttach(myRECO_CommonHTCut,PFMeffWCut1000)
tree.TAttach(PFMeffWCut1000,RECO_ttWPlotting_1000)
tree.TAttach(RECO_ttWPlotting_1000,myCountsAndBSMGrids_fin_pre_LP)
tree.TAttach(myCountsAndBSMGrids_fin_pre_LP,PFLPCut1000)
tree.TAttach(PFLPCut1000,myCountsAndBSMGrids_fin)
tree.TAttach(myCountsAndBSMGrids_fin,RECO_ttWPlotting_1000_post_LP)
             
#tree.TAttach(RECO_ttWPlotting_preLP,PFLPCut)
#tree.TAttach(PFLPCut,RECO_ttWPlotting_postLP)
#tree.TAttach(myCountsAndBSMGrids_2Jts,AtLeast3Jts)
#tree.TAttach(AtLeast3Jts,myCountsAndBSMGrids_3Jts)
#tree.TAttach(myCountsAndBSMGrids_3Jts,AtLeast4Jts)
#tree.TAttach(AtLeast4Jts,AnalysisTree)
#tree.TAttach(AnalysisTree,myCountsAndBSMGrids_fin)

#
if data_typeBool == "MCGrid":
 conf.Ntuple.Weight = "mSuGra" ### For the BSM set Weight = "mSuGra"
 sig.Run("./results_new_HT", conf, [PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi])
### end BSM running

if data_typeBool == "MCBool":
### Non BSM running
 sig.Run("./results_new_HT", conf, samplesMC)
if data_typeBool == "data39Bool":
 sig.Run("./results_new_HT", conf,samplesData)
