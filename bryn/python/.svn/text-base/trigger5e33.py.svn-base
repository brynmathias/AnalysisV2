#!/usr/bin/env python
"""
Created by Bryn Mathias on 2010-05-07.
"""

# -----------------------------------------------------------------------------
# Necessary includes
import errno
import os
import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from libbryn import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy
from icf.JetCorrections import *
from batchGolden import *
# from libPhotons import *
# from samples_cff import *

# -----------------------------------------------------------------------------
# Samples
#import yours in your running script
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise

# -----------------------------------------------------------------------------
# Reading the collections from the ntuple


# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=True
default_cc.ElectronJet=True
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.ModifyJetEnergy=True
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=-1.
default_cc.Muons.CombIsoCut=0.15
default_cc.Muons.MuonJetDeltaR=0.5
default_cc.Muons.MuonIsoTypePtCutoff=0.
default_cc.Muons.RequireLooseIdForInitialFilter=False
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=-1.0
default_cc.Electrons.CombIsoCut=0.15
default_cc.Electrons.ElectronJetDeltaR=0.5
default_cc.Electrons.ElectronIsoTypePtCutoff=0.
default_cc.Electrons.ElectronLooseIdRequired=True
default_cc.Electrons.ElectronTightIdRequired=False
default_cc.Electrons.RequireLooseIdForInitialFilter=False
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=3
default_cc.Photons.PhotonJetDeltaR=0.5
default_cc.Photons.PhotonIsoTypePtCutoff=30.
# -----------------------------------------------------------------------------
# Definition of common objects
default_common = deepcopy(defaultConfig.Common)
default_common.ApplyXCleaning=True
default_common.Jets.PtCut=(375./275.)*50.
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False
default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=-1.
default_common.Electrons.CombIsoCut=0.15
default_common.Electrons.ApplyID = True
default_common.Electrons.TightID = False
default_common.Electrons.RequireLooseForOdd = True
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=-1.
default_common.Muons.CombIsoCut=0.15
default_common.Muons.ApplyID = True
default_common.Muons.TightID = True
default_common.Muons.RequireLooseForOdd = True
default_common.Photons.EtCut=25.0
default_common.Photons.EtaCut=2.5
# the photon cuts are NOT read anyway
# default_common.Photons.TrkIsoRel=0.
# default_common.Photons.TrkIsoCut=99999.
# default_common.Photons.EcalIsoRel=0.
# default_common.Photons.EcalIsoCut=99999.
# default_common.Photons.HcalIsoRel=0.
# default_common.Photons.HcalIsoCut=99999.
# default_common.Photons.HadOverEmCut=0.5
# default_common.Photons.SigmaIetaIetaCut=0.5
##default_common.Photons.CaloIsoCut=99999.
default_common.Photons.IDReq = 3
default_common.Photons.RequireLooseForOdd = True

datatriggerps = PSet(
    Verbose = False,
    UsePreScaledTriggers = True,
    Triggers = [
        "HLT_HT200_v*",
    ]
    )
alphatrigger = datatriggerps
alphatrigger.Triggers = ["HLT_HT250_AlphaT0p55_v*",]
HLTrigger = OP_MultiTrigger( datatriggerps.ps() )
HLTriggerAlphaT = OP_MultiTrigger(alphatrigger.ps())

# TriggerTwo = OP_MultiTrigger(PSet(Triggers = ["HLT_HT250_AlphaT0p55_v1","HLT_HT250_AlphaT0p55_v2"],Verbose = False).ps())
# dump = OP_Dump()
Plots_TriggerOnly = PL_TriggerTurnOns( PSet(DirName = "TriggerOnly", MinObjects =0 ,MaxObjects = 15,Plots = True, ReWeight = False,TriggerReWeight = datatriggerps.Triggers,Verbose = False).ps())
Plots_HT270 = PL_TriggerTurnOns( PSet(DirName = "Plots_HT270", MinObjects =0 ,MaxObjects = 15,Plots = True, ReWeight = False,TriggerReWeight = datatriggerps.Triggers,Verbose = False).ps())
Plots_HT275 = PL_TriggerTurnOns( PSet(DirName = "Plots_HT275", MinObjects =0 ,MaxObjects = 15,Plots = True, ReWeight = False,TriggerReWeight = datatriggerps.Triggers,Verbose = False).ps())
Plots_NoCleaningCuts_275 = PL_TriggerTurnOns( PSet(DirName = "Plots_HT275_NoCleaning", MinObjects =0 ,MaxObjects = 15,Plots = True, ReWeight = False,TriggerReWeight = datatriggerps.Triggers,Verbose = False).ps())
Plots_NoCleaningCuts_270 = PL_TriggerTurnOns( PSet(DirName = "Plots_HT270_NoCleaning", MinObjects =0 ,MaxObjects = 15,Plots = True, ReWeight = False,TriggerReWeight = datatriggerps.Triggers,Verbose = False).ps())
htCut270 = RECO_CommonHTCut(270.)
htCut275_NoCleaning = RECO_CommonHTCut(275.)
htCut270_NoCleaning = RECO_CommonHTCut(270.)

confHT = confHT(40.,250.)
emuAlphaT = AlphaTEmu(0.55,40.,250.,6)
def an(jetThreshold):
  out = []
  secondJetET = OP_SecondJetEtCut(jetThreshold)
  cutTreeData= Tree("Data")
  cutTreeData.Attach(json)
  cutTreeData.TAttach(json,HLTriggerAlphaT)
  cutTreeData.TAttach(HLTriggerAlphaT,Plots_TriggerOnly)
  cutTreeData.TAttach(HLTriggerAlphaT,NoiseFilt)
  cutTreeData.TAttach(NoiseFilt,GoodVertexMonster)
  cutTreeData.TAttach(GoodVertexMonster,oddJet)
  cutTreeData.TAttach(oddJet,badMuonInJet)
  cutTreeData.TAttach(badMuonInJet,oddMuon)
  cutTreeData.TAttach(oddMuon,oddElectron)
  cutTreeData.TAttach(oddElectron,oddPhoton)
  cutTreeData.TAttach(oddPhoton,numComLeptons)
  cutTreeData.TAttach(numComLeptons,numComPhotons)
  cutTreeData.TAttach(numComPhotons,htCut275_NoCleaning)
  cutTreeData.TAttach(numComPhotons,htCut270_NoCleaning)
  cutTreeData.TAttach(htCut270_NoCleaning,Plots_NoCleaningCuts_270)
  cutTreeData.TAttach(htCut275_NoCleaning,Plots_NoCleaningCuts_275)
  cutTreeData.TAttach(numComPhotons,recHitCut)
  cutTreeData.TAttach(recHitCut,LeadingJetEta)
  cutTreeData.TAttach(LeadingJetEta,secondJetET)
  cutTreeData.TAttach(secondJetET,VertexPtOverHT)
  cutTreeData.TAttach(VertexPtOverHT,htCut275)
  cutTreeData.TAttach(VertexPtOverHT,htCut270)
  cutTreeData.TAttach(htCut270,Plots_HT270)
  cutTreeData.TAttach(htCut275,Plots_HT275)
  return (cutTreeData,secondJetET,out)
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *

cutTree,blah,l = an(100.*(375./275.))

#JetSmear = JetSmear(0.1,30)
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
# def addCutFlowMC(b) :
#   b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
#   b.AddElectronFilter("PreCC",vbtfElectronIdFilter)
#   b+=cutTreeMC


def addCutFlowData(a):
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a+=cutTree


#AK5 Calo
# conf_ak5_caloMC = deepcopy(defaultConfig)
# conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
# conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
# conf_ak5_caloMC.Common = deepcopy(default_common)
# # conf_ak5_caloMC.Common.print_out()
# anal_ak5_caloMC=Analysis("AK5Calo")
# addCutFlowMC(anal_ak5_caloMC)

#AK5 Calo
conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_caloMC.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)



testFile = PSet(
Name = "TestFile",
Format = ("ICF",3),
Weight = 1.0,
File = ["../../Ntuples/AK5Calo_tedSync_newFormat.root"]
)

# Triggersamples =[LM0,LM1,LM2,LM3,LM4]
# from data.Run2011.HT_Run2011_promptReco import *
outdir = "../results/TriggerPurities/"
ensure_dir(outdir)
from data.Run2011.HTRun2011AB import *
#HT_Run2011A.File = HT_Run2011A.File[0:1]
# anal_ak5_caloData.Run(outDir,conf_ak5_caloData,[testFile])
anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[HTRun2011AB])

# anal_ak5_caloMC.Run("../results/Triggers/",conf_ak5_caloMC,Triggersamples)

