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

default_common.Jets.PtCut=50.*(275/375.)

tree,value1,l = MakeMuonDataTree(100.*(275./375.))
treeMC,value2,j = MakeMuonMCTree(100.*(275./375.))
cutTreeData,value3,k = MakeHadDataTree(100.*(275./375.))
cutTreeMC,value4,m = MakeHadMCTree(100.*(275./375.))


def addCutFlowMuon(a) :
 
 a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
 a.AddMuonFilter("PreCC",muonfilt2)
 a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
 a+=tree

def addCutFlowMuonMC(b):
 b.AddElectronFilter("PreCC",vbtfElectronIdFilter) 
 b.AddMuonFilter("PreCC",muonfilt2)
 b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
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


conf= deepcopy(defaultConfig)
conf.Ntuple = deepcopy(ak5_calo)
conf.XCleaning = deepcopy(default_cc)
conf.Common = deepcopy(default_common)


Muon_Analysis=Analysis("Muon")
addCutFlowMuon(Muon_Analysis)

Muon_MC=Analysis("MuonMC")
addCutFlowMuonMC(Muon_MC)

Had_Analysis=Analysis("Had")
addCutFlowHadData(Had_Analysis)

Had_MC=Analysis("HadMC")
addCutFlowHadMC(Had_MC)

from data.Run2011.HTRun2011AB import *

test = PSet(
Name = "test",
Format = ("ICF",3),
Weight = 1.0,
File = "../../Ntuples/375_newFormat.root")


outdir = "../Binned_results_HT_275_"+strftime("%d_%b_%H")+"/Muon_Data/"
#outdir = "../Binned_results_HT_275_"+strftime("%d_%b_%H")+"/MC/"
#outdir = "../Binned_results_HT_275_"+strftime("%d_%b_%H")+"/Had_Data/"
#outdir = "../Binned_results_HT_275_"+strftime("%d_%b_%H")+"/Had_MC/"

ensure_dir(outdir)

HTRun2011AB.File = HTRun2011AB.File[:1]

#Muon_Analysis.Run(outdir,conf,[HT_Run2011AB])
#Muon_MC.Run(outdir,confMC, Summer11_MC_Lower_Bins)
#Had_Analysis.Run(Hadoutdir,confHad,[HT_Run2011AB])
Had_MC.Run(Hadoutdir,confHadMC, Summer11_MC_Lower_Bins)
