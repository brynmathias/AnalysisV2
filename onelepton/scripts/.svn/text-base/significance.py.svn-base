#!/usr/bin/env python

# standard imports
import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
import libWPol as wpol
from copy import deepcopy
from icf.core import PSet,Analysis
# The leptonic specicif settings&files
from onelepton_settings import *
from onelepton_BSM_Grids import *
from onelepton_MC_samples import *
from onelepton_Cuts_Plots import *
#from onelepton_Data_samples import *

# here a few flags to ensure you correct all instances
mode = "MC"
#mode = "data39"
#mode = "data4X"
#mode  = "MCGrid"

vertexReweight = "Yes"
met_syst = True

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
looseEleID = LooseEleId()
sig.AddElectronFilter("PreCC", looseEleID)

# the residual JetCorrections are different from PF and Calo, so be careful when adding them.
if mode == "data39":
 sig.AddJetFilter("PreCC",JetCorrections)
if met_syst:
    pfmet_jecunc = PSet(
        #the location of the JECUncertainty txt file
        jecuncfile = "/vols/cms01/as1604/SUSY-svn/WPol2/scripts/GR_R_38X_V15_AK5PF_Uncertainty.txt",
        #either Muon or Electron
        lepton = "Muon",
        #the jet threshold to consider for the JEC Uncertainties
        pfjetthresh = 10.0,
        #the percentage/100 to shift the unclustered energy by
        unclusteredshift = 0.05,
        #whether or not to apply the shift upwards (True) or downwards (False)
        shiftup = False
        )
    pfmetjecunc = wpol.pfMETJECUnc(pfmet_jecunc.ps())
    sig.AddMETFilter("pfMET", pfmetjecunc)


mu_jet_dr = MuonJetDRFilter(0.1, Mus.ps())
sig.AddJetFilter("PreCC", mu_jet_dr)

if vertexReweight == "Yes":
    vertex_reweight = VertexReweighting(
        PSet(
        VertexWeights = [0.0, 0.169, 0.511, 1.276, 1.688, 1.564, 1.715, 1.135, 1.042, 0.476, 0.469, 0.385, 0.359, 0.37, 0.502, 0.489, 0.0, 0.0, 0.0, 0.0]
        ).ps()
        )
    sig.AddWeightFilter("Weight", vertex_reweight)

tree = Tree("Main")
sig+=tree
## Main trunk of tree
## The first two is are true for data
if mode == "data39":
    tree.Attach(triggerDATA)
    tree.TAttach(triggerDATA,selection)
elif mode == "data4X":
    tree.Attach(selection)
#   tree.Attach(triggerDATA)
#   tree.TAttach(triggerDATA,selection)
else: # else true for MC only !!
    tree.Attach(selection)

tree.TAttach(selection,OneMu)
tree.TAttach(OneMu,OneLooseMu)
tree.TAttach(OneLooseMu,ZeroLooseEl)
tree.TAttach(ZeroLooseEl,AtLeast2Jts)
tree.TAttach(AtLeast2Jts,SecondJetEtCut60)
tree.TAttach(SecondJetEtCut60,MuonPlots)
tree.TAttach(SecondJetEtCut60, skim)
tree.TAttach(MuonPlots,RECO_PFMHTCut100)
tree.TAttach(RECO_PFMHTCut100,MuonPlots_PostMHT)
tree.TAttach(MuonPlots_PostMHT,RECO_CommonHTCut350)
tree.TAttach(MuonPlots, RECO_PFMHTCut150)
tree.TAttach(RECO_PFMHTCut150, MuonPlots_PostMHT150)
tree.TAttach(MuonPlots_PostMHT150, RECO_CommonHTCut350_2)
tree.TAttach(MuonPlots, RECO_PFMHTCut200)
tree.TAttach(RECO_PFMHTCut200, MuonPlots_PostMHT200)
tree.TAttach(MuonPlots_PostMHT200, RECO_CommonHTCut350_3)

tree.TAttach(RECO_CommonHTCut350, myCountsAndBSMGrids_PFMHT100_pre_LP)
tree.TAttach(myCountsAndBSMGrids_PFMHT100_pre_LP, PFLPCutPFMHT100)
tree.TAttach(PFLPCutPFMHT100, myCountsAndBSMGrids_PFMHT100)

tree.TAttach(RECO_CommonHTCut350_2, myCountsAndBSMGrids_PFMHT150_pre_LP)
tree.TAttach(myCountsAndBSMGrids_PFMHT150_pre_LP, PFLPCutPFMHT150)
tree.TAttach(PFLPCutPFMHT150, myCountsAndBSMGrids_PFMHT150)

tree.TAttach(RECO_CommonHTCut350_3, myCountsAndBSMGrids_PFMHT200_pre_LP)
tree.TAttach(myCountsAndBSMGrids_PFMHT200_pre_LP, PFLPCutPFMHT200)
tree.TAttach(PFLPCutPFMHT200, myCountsAndBSMGrids_PFMHT200)


if mode == "MCGrid":
 conf.Ntuple.Weight = "mSuGra" ### For the BSM set Weight = "mSuGra"
 sig.Run("./results", conf, [PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi])
### end BSM running

if mode  == "MC":
 sig.Run("./results", conf, samplesMC311X)
elif mode == "data39":
 sig.Run("./results", conf,samplesData)
elif mode == "data4X":
    sig.Run("./resultsData", conf, samplesData4X)
