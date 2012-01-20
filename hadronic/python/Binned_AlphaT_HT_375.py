#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
from time import strftime
from Binned_Sample_Config import *

mu_id = PSet(
    doJetLoop = False,
    MuID = "Tight",
    MinPt = 10.,
    MaxEta = 2.5,
    MaxIsolation = 0.1,
    DRMuJet = 0.3,
    MaxGlbTrkDxy = 0.02,
    MinGlbTrkNumOfValidHits = 11,
    SegMatch2GlbMu = 1,
    PixelHitsOnInrTrk = 1,
    MaxInrTrkDz = 1.
        )

#======== Filters ===========
from wpol.muon_config import muon_id # ,conf
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter = Photon_IDFilter( ra3photonidps.ps() )
muonfilt2 = OL_CustomVBTFMuID(mu_id.ps())
#muonfilt=CustomMuonId(muon_id.ps())
vbtMuonIdFilter = Muon_IDFilter( vbtfmuonidps.ps() )

default_common.Jets.PtCut=50.

# Change depending on Muon or Had selection
default_cc.Muons.CombIsoCut=0.15 # Had
default_common.Muons.CombIsoCut=0.15
#default_cc.Muons.CombIsoCut=0.1 # Muon
#default_common.Muons.CombIsoCut=0.1

tree,value1,l = MakeMuonDataTree(100.)
treeMC,value2,j = MakeMuonMCTree(100.)
cutTreeData,value3,k = MakeHadDataTree(100.)
cutTreeMC,value4,m = MakeHadMCTree(100.)

"""
#WJets
vertex_reweight = GoodVertexReweighting(
PSet(GoodVertexWeights= [2325.0676375962553, 0.08266214220897375, 0.4578290422874003, 0.840510462962519, 1.1424367086980733, 1.271434725935345, 1.275149405714869, 1.2503717242693777, 1.2426939988848076, 1.2951614031752379, 1.403475225925956, 1.575191239927366, 1.8135637028931426, 2.1242778130643605, 2.6336167421013648, 3.441131045211946, 4.8378805651479215, 6.737262598399448, 9.834033450897966, 14.808965861834524, 15.863537659704578, 17.813518094600724, 19.769438447404465, 39.094273395168706, 28.166628160506157] ).ps())

#TTbar

vertex_reweight = GoodVertexReweighting(
PSet(GoodVertexWeights=[2455.5508637795515, 0.08293127055192732, 0.4517855973561083, 0.8356756135308727, 1.1476120142768902, 1.277784207378596, 1.2870774041652397, 1.2549536790875715, 1.2522763976888578, 1.2965789197589437, 1.3997550854537164, 1.565100728651931, 1.776694847305835, 2.031631851352254, 2.526646420801418, 3.2142006355679964, 4.399459596831336, 5.880097043155728, 8.827430670877627, 11.794758476297526, 10.190126894948826, 19.532920105156215, 13.083149886433635, 6.818291311373197, 5.578601982032616]).ps())

"""
#Zinv

vertex_reweight = GoodVertexReweighting(
PSet(GoodVertexWeights=[2455.5508637795515, 0.08293127055192732, 0.4517855973561083, 0.8356756135308727, 1.1476120142768902, 1.277784207378596, 1.2870774041652397, 1.2549536790875715, 1.2522763976888578, 1.2965789197589437, 1.3997550854537164, 1.565100728651931, 1.776694847305835, 2.031631851352254, 2.526646420801418, 3.2142006355679964, 4.399459596831336, 5.880097043155728, 8.827430670877627, 11.794758476297526, 10.190126894948826, 19.532920105156215, 13.083149886433635, 6.818291311373197, 5.578601982032616]).ps())


def addCutFlowMuon(a) :
 
 a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
 a.AddMuonFilter("PreCC",muonfilt2)
 a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
 a+=tree

def addCutFlowMuonMC(b):
 b.AddElectronFilter("PreCC",vbtfElectronIdFilter) 
 b.AddMuonFilter("PreCC",muonfilt2)
 b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
 b.AddWeightFilter("Weight",vertex_reweight)
 b+=treeMC

def addCutFlowHadData(c):
 c.AddElectronFilter("PreCC",vbtfElectronIdFilter)
 c.AddMuonFilter("PreCC",vbtMuonIdFilter)
 c.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
 c+=cutTreeData


def addCutFlowHadMC(d):
 d.AddElectronFilter("PreCC",vbtfElectronIdFilter)
 d.AddMuonFilter("PreCC",vbtMuonIdFilter)
 d.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
 d.AddWeightFilter("Weight",vertex_reweight)
 d+=cutTreeMC

#===========================

conf= deepcopy(defaultConfig)
conf.Ntuple = deepcopy(ak5_calo)
conf.XCleaning = deepcopy(default_cc)
conf.Common = deepcopy(default_common)

confMC= deepcopy(defaultConfig)
confMC.Ntuple = deepcopy(ak5_calo)
confMC.XCleaning = deepcopy(default_cc)
confMC.Common = deepcopy(default_common)

confHad= deepcopy(defaultConfig)
confHad.Ntuple = deepcopy(ak5_calo)
confHad.XCleaning = deepcopy(default_cc)
confHad.Common = deepcopy(default_common)

confHadMC= deepcopy(defaultConfig)
confHadMC.Ntuple = deepcopy(ak5_calo)
confHadMC.XCleaning = deepcopy(default_cc)
confHadMC.Common = deepcopy(default_common)

Muon_Analysis=Analysis("Muon")
addCutFlowMuon(Muon_Analysis)

Muon_MC=Analysis("MuonMC")
addCutFlowMuonMC(Muon_MC)

Had_Analysis=Analysis("Had")
addCutFlowHadData(Had_Analysis)

Had_MC=Analysis("HadMC")
addCutFlowHadMC(Had_MC)

from data.Run2011.HT_Run2011AB import *

test = PSet(
Name = "test",
Format = ("ICF",3),
Weight = 1.0,
File = "../../Ntuples/375_newFormat.root")


#outdir = "../Binned_results_HT_375_"+strftime("%d_%b_%H")+"/Muon_Data/"
#outdir = "../Binned_results_HT_375_"+strftime("%d_%b_%H")+"/MC/"
#Hadoutdir = "../Binned_results_HT_375_"+strftime("%d_%b_%H")+"/Had_Data/"
HadoutdirMC = "../Binned_results_HT_375_"+strftime("%d_%b_%H")+"/Had_MC/"

ensure_dir(HadoutdirMC)
#ensure_dir(HadoutdirMC)

#HTRun2011AB.File = HTRun2011AB.File[:1]


#Muon_Analysis.Run(outdir,conf,[HT_Run2011AB])
#Muon_MC.Run(outdir,confMC, Summer11_Muon_MC)
#Had_Analysis.Run(Hadoutdir,confHad,[HT_Run2011AB])
Had_MC.Run(HadoutdirMC,confHadMC, Zinv_Sample)
