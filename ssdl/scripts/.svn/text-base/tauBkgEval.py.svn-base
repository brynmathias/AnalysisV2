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


from data.JetMETTau_ALL_230810 import *
from montecarlo.QCD_Pythia6_allBins import *
from montecarlo.TTBarTauola import *
from montecarlo.WJets_Madgraph import *
from montecarlo.Zjets_madgraph import *
from montecarlo.LMx import *


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
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.TrkIsoCut = 99.
conf.Common.Muons.CombIsoCut = 99.
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 5.0
conf.Common.Electrons.EtaCut = 2.4
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

a=Analysis("tauFR_MC")

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
#a.AddTauFilter("PreCC",tauSelFilter)
a.AddTauFilter("PreCC",mutaufilter)
a.AddTauFilter("PreCC",eletaufilter)
#a.AddJetFilter("PreCC",taujetfilter)


# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger



#a+=tree
#tree.Attach(ssdlTrigg)
#tree.TAttach(ssdlTrigg,ssdlSelec)

TauEval=PSet(
    McAnal =1.,
#    McAnal =0.,    
    )

tauEval=TauBkgEval("TauEval",TauEval.ps())
a+=tree

#tree.Attach(ttEval)

tree.Attach(tauEval)

import qcd_pythia as qcd
import ZjetsPythia as zpythia
import WJets_madg as wjets

import newNtuple as sm


ttbar=[ttbarTauola]
a.Run("../results",conf,ttbar)
