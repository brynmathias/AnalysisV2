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
    Cuts = lepconf.ele_ptThres_vbtf80,
    IsolationSR = True,      # high pt
    HoverE = True,
    DeltaAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = False,    # not in ntuple V08
    IsolationPF = False,
    LowPtSel = True,
    LowPtID = True,
    LowPtIso = True    
)



muon_id = PSet(
   Cuts = lepconf.muonCuts,
   IsolationPF = False,
   IsolationSR = True,
   LowPtIso = True,
   MuonID = True,
   MuonIso = True,
#   dxychoice = "vertex"
   dxychoice = "beamspot"
)


tau_id = PSet(
 tauIDbyTaNC = True
)

import icf.utils as utils
import icf.types as types

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

conf.Common.Jets.PtCut = 5.0
conf.Common.Jets.EtaCut = 2.5


# These are turned off anyhow
#conf.Common.Electrons.TrkIsoCut = -1.
#conf.Common.Electrons.CombIsoCut = 0.1
#conf.Common.Electrons.TightID = True
#conf.Common.ApplyXCleaning=False
#conf.Common.Electrons.ApplyID=False

conf.XCleaning.Verbose=False
conf.Common.ApplyXCleaning=False


a=Analysis("ht300")

###FILTERS
taujetfilter=TauJetDrFilter(0.05)
muelfilter=MuonElectronDrFilter(0.05)
muond0filter=LeptonD0Filter(0.2,0.0,0.0322)
elecd0filter=LeptonD0Filter(0.2,0.0,0.0322)
elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
#tauSelFilter=CustomTauId(tau_id.ps())

a.AddJetFilter("PreCC",taujetfilter)
a.AddElectronFilter("PreCC",muelfilter)
a.AddMuonFilter("PreCC",muond0filter)
a.AddElectronFilter("PreCC",elecd0filter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddMuonFilter("PreCC",muonSelFilter)
#a.AddTauFilter("PreCC",tauSelFilter)

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger


ssdlMCtruth=SSDLMCTruth("mc")

Trigger=PSet(
       McAnal =1.,
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
    MCFinalState = 1,
 )


ssdlSelec=SSDLSelection("Selection",Selection.ps())

TTEval=PSet(
#    McAnal =1.,
    McAnal =0.,    
    )


ttEval=TTBkgEval("TTEval",TTEval.ps())


TauEval=PSet(
#    McAnal =1.,
    McAnal =0.,    
    )


tauEval=TauBkgEval("TauEval",TauEval.ps())

a+=tree
#tree.Attach(ttEval)

tree.Attach(tauEval)

#tree.Attach(ssdlMCtruth)
#tree.TAttach(ssdlMCtruth,ssdlTrigg)
##tree.Attach(ssdlTrigg)
#tree.TAttach(ssdlTrigg,ssdlSelec)


import robe_icfV08 as mysamplesV08
#samples=[mysamplesV08.ttbar]
#samples=[mysamplesV08.ttbar,mysamplesV08.qcd300]
#samples=[mysamplesV08.ttbar,mysamplesV08.qcd300]
samples=[mysamplesV08.qcd170,mysamplesV08.qcd80]
#samples=[mysamplesV08.qcd80]
ttnew1=PSet(
    Name="ttnew1",
    File=["/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_" + str(i) + "_1.root" for i in range (1 ,16)],
    CrossSection= 150.3,
    Format=("ICF",2)
)

ttnew2=PSet(
    Name="ttnew2",
    File=["/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_" + str(i) + "_2.root" for i in range (1 ,16)],
    CrossSection= 150.3,
    Format=("ICF",2)
)


ttnewtot=PSet(
    Name="ttnew1",
    File=["/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_" + str(i) + "_" + str(j) + ".root" for i in range (1 ,16)  for j in range (1 ,2)],
    CrossSection= 150.3,
    Format=("ICF",2)
)



#samples=[ttnew2]
#samples=[ttnewtot]
a.Run("../results/tau",conf,samples)
