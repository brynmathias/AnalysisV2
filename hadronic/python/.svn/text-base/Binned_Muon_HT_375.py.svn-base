#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
from time import strftime
from Binned_Muon_Config import *

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

"""mu_id = PSet(
    doJetLoop = False,
    MuID = "Tight",
    MinPt = 10.,
    MaxEta = 2.5,
    MaxIsolation = 5.0,
    DRMuJet = 0.3,
    MaxGlbTrkDxy = 0.02,
    MinGlbTrkNumOfValidHits = 11,
    SegMatch2GlbMu = 1,
    PixelHitsOnInrTrk = 1,
    MaxInrTrkDz = 1.
        )
"""

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

#Cuts with Selction,HBHE,MHTovHT,CommonMHT,AlphaT 0.51

vertex_reweight = GoodVertexReweighting(
PSet(GoodVertexWeights = [1.0, 0.071182041228993354, 0.3788533298983548, 0.70212224756460717, 0.95912926863057879, 1.1063323506805849, 1.1826257455177471, 1.2297382718782017, 1.2772830447358376, 1.4266446590805815, 1.5732065775636328, 1.8401056375971667, 2.1784909215394999, 2.506266882602076, 3.3335988825191176, 4.687787057503483, 6.8602191807881647, 11.198474011060968, 14.883466002768214, 20.878255333866864, 1.0, 1.0, 1.0, 1.0, 1.0]).ps())

# Change depending on Muon or Had selection
default_cc.Muons.CombIsoCut=0.15 # Had
default_common.Muons.CombIsoCut=0.15
#default_cc.Muons.CombIsoCut= 0.10  # Muon
#default_common.Muons.CombIsoCut=0.10

tree,value1,l = MakeMuonDataTree(100.)
treeMC,value2,j = MakeMuonMCTree(100.)
cutTreeData,value3,k = MakeHadDataTree(100.)
cutTreeMC,value4,m = MakeHadMCTree(100.)


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

Muon_Analysis=Analysis("Muon_375")
addCutFlowMuon(Muon_Analysis)

Muon_MC=Analysis("MuonMC_375")
addCutFlowMuonMC(Muon_MC)

Had_Analysis=Analysis("Had_375")
addCutFlowHadData(Had_Analysis)

Had_MC=Analysis("HadMC_375")
addCutFlowHadMC(Had_MC)

from data.Run2011.HT_Run2011AB import *
from Muon375skim import *

test = PSet(
Name = "test",
Format = ("ICF",3),
Weight = 1.0,
File = "../../Ntuples/375_newFormat.root")


#outdir = "../Muon_Prediction_"+strftime("%d_%b")+"/Muon_Data/"
#outdir = "../Muon_Prediction_"+strftime("%d_%b")+"/MC/"
Hadoutdir = "../Muon_Prediction_"+strftime("%d_%b")+"/Had_Data/"
#Hadoutdir = "../Muon_Prediction_"+strftime("%d_%b")+"/Had_MC/"

#ensure_dir(outdir)
ensure_dir(Hadoutdir)

#HT_Run2011AB.File = HT_Run2011AB.File[:1]


#Muon_Analysis.Run(outdir,conf,[HT_Run2011AB])
#Muon_MC.Run(outdir,confMC, Summer11_MC_Higher_Bins)
Had_Analysis.Run(Hadoutdir,confHad,[HT_Run2011AB])
#Had_MC.Run(Hadoutdir,confHadMC, Summer11_MC_Higher_Bins)
