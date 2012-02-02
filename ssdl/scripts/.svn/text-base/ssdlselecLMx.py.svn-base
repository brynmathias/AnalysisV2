#!/usr/bin/env python
# Example analysis script, commented for clarity
import setupSUSY
# Import core framework library and the ssdl library
from libFrameworkSUSY import *
from libSSDL import *
import lep_conf as lepconf

# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

#from icf.core import PSet

# This is the default configuration
from icf.config import defaultConfig


# import default configuration
conf=defaultConfig


ele_id = PSet(
    ParticleFlow=True,
    OldNtu = False,
    Cuts = lepconf.ele_ptThres_vbtf80,
    IsolationSR = True,      # high pt
    HoverE = True,
    DeltaAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,    # not in ntuple V08
    IsolationPF = False,
    LowPtSel = True,
    LowPtID = True,
    LowPtIso = True,
    ChargeComp = True,
    D0sel = True
)



muon_id = PSet(
   ParticleFlow=True, 
   Cuts = lepconf.muonCuts,
   IsolationPF = False,
   IsolationSR = True,
   LowPtIso = True,
   MuonID = True,
   MuonIso = True,
   dxychoice = "vertex"
#   dxychoice = "beamspot"
)


tau_id = PSet(
 tauIDbyTaNC = True
)

import icf.utils as utils
import icf.types as types

#conf.Ntuple.Weight = "mSuGra"

conf.Ntuple.Electrons.Suffix = "PF"
conf.Ntuple.Muons.Suffix = "PF"
conf.Ntuple.Taus.Suffix = "Pat"
conf.Ntuple.Jets.Suffix = "Pat"
conf.Ntuple.Jets.Prefix = "ak5JetPF"

conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.EtaCut = 2.4
conf.Common.Muons.TrkIsoCut = 99.
conf.Common.Muons.CombIsoCut = 99.
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 5.0
conf.Common.Electrons.EtaCut = 2.5
conf.Common.Electrons.TrkIsoCut = 99.
conf.Common.Electrons.CombIsoCut = 99.
conf.Common.Electrons.TightID = False
conf.Common.Electrons.ApplyID = False

conf.Common.Taus.PtCut = 5.0
conf.Common.Taus.EtaCut = 2.5
conf.Common.Taus.TightID = False
conf.Common.Taus.ApplyID = False


conf.Common.Jets.PtCut = 50.0


# These are turned off anyhow
#conf.Common.Electrons.TrkIsoCut = -1.
#conf.Common.Electrons.CombIsoCut = 0.1
#conf.Common.Electrons.TightID = True
#conf.Common.ApplyXCleaning=False
#conf.Common.Electrons.ApplyID=False

conf.XCleaning.Verbose=False
conf.Common.ApplyXCleaning=False


a=Analysis("ssdl_mc")

###FILTERS



taujetfilter=TauJetDrFilter(0.1)
muelfilter=MuonElectronDrFilter(0.1)
muond0filter=LeptonD0Filter(0.2,0.0,0.0322)
elecd0filter=LeptonD0Filter(0.2,0.0,0.0322)
elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
tauSelFilter=CustomTauId(tau_id.ps())
eletaufilter=ElectronTauDrFilter(0.1)
mutaufilter=MuonTauDrFilter(0.1)

#a.AddMuonFilter("PreCC",muond0filter)
a.AddMuonFilter("PreCC",muonSelFilter)
#a.AddElectronFilter("PreCC",elecd0filter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddElectronFilter("PreCC",muelfilter)
a.AddTauFilter("PreCC",tauSelFilter)
a.AddTauFilter("PreCC",mutaufilter)
a.AddTauFilter("PreCC",eletaufilter)
a.AddJetFilter("PreCC",taujetfilter)



# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger


MCtruth=PSet(
    McAnal =1.,
    MSugraScan = 0.,
    )

ssdlMC=SSDLMCTruth("MCtruth",MCtruth.ps())

Trigger=PSet(
       McAnal =1.,
       MSugraScan = 0.,
       TriggerBits=PSet(
#         bit1="HLT_DiJetAve70U",
#         bit1="HLT_HT100U",
         bit1="HLT_HT200",
#         bit1="HLT_MET60",
         bit2="",
         bit3="",
         )
       )

ssdlTrigg=SSDLTrigger("Trigger",Trigger.ps())





Selection=PSet(
    MuonLowPtTrackIsoCut = 5.,
    ElectronLowPtTrackIsoCut = 3.,
    LeptonCombIsoCut = 0.15,
    SSMHTCut= 50.,
    SSHTCut=350.,
    LeptonCut =1.,
    BkgAnal =0.,
    McAnal =1.,
    MaxPtHat = 1000000000.,
    MSugraScan = 0.,
    PrintLep = 0.,
 )


ssdlSelec=SSDLSelection("Selection",Selection.ps())

a+=tree
tree.Attach(ssdlMC)
#tree.Attach(ssdlTrigg)
tree.TAttach(ssdlMC,ssdlTrigg)
tree.TAttach(ssdlTrigg,ssdlSelec)


import susyLMx as lmx
#samples=[lmx.LM0,lmx.LM9]
samples=[lmx.LM0]
a.Run("../results/ptordered",conf,samples)
