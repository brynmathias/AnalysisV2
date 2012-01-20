#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY

# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libSSDL import *
# from libWPol import *
import lep_conf as lepconf
import icf.utils as utils
import icf.types as types
import montecarlo.TTBarTauola as TT
import montecarlo.WJets_Madgraph as W
import montecarlo.Zjets_madgraph as Z
import montecarlo.QCD_Pythia6_allBins as QCD
import montecarlo.LMx as lm
# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig 

print lepconf.ele_ptThres_vbtf80.Isolation

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
    ConversionsExtra = True,    # not in ntuple V00-08
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

# We can override the configuration we imported
# Here, we lower our Jet Et Cut to 5 GeV
conf.Ntuple.Electrons.Suffix = "PF"
conf.Ntuple.Muons.Suffix = "PF"
conf.Ntuple.SecMuons.Suffix = "Pat"
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

# Here we define a sample to use
# The path and the filename are separate so you can easily move to using
# local samples.
test=PSet(
	Name="test",
        File="/data/pioppi/susy.root",
        Format=("ICF",2),
        Weight=1.0,
#    LastEntry=1000
)




# Create the analysis
a=Analysis("test")
tree = Tree("Main")

###FILTERS
taujetfilter=TauJetDrFilter(0.1)
muelfilter=MuonElectronDrFilter(0.1)
muond0filter=LeptonD0FilterVertex(0.2)
elecd0filter=LeptonD0FilterVertex(0.2)
elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
tauSelFilter=CustomTauId(tau_id.ps())
eletaufilter=ElectronTauDrFilter(0.1)
mutaufilter=MuonTauDrFilter(0.1)


a.AddMuonFilter("PreCC",muonSelFilter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddElectronFilter("PreCC",muelfilter)
a.AddTauFilter("PreCC",tauSelFilter)
a.AddTauFilter("PreCC",mutaufilter)
a.AddTauFilter("preCC",eletaufilter)
a.AddJetFilter("PreCC",taujetfilter)



# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger



Trigger=PSet(
       McAnal =0.,
        MSugraScan = 0.,
       TriggerBits=PSet(
#         bit1="HLT_HT200",
         bit1="HLT_Ele15_SW_L1R",
         bit2=""
         )
       )


ssdlTrigg=SSDLTrigger("Trigger",Trigger.ps())




elFlip=PSet(
#    SSMHTCut=50.,
    SSMHTCut=0.,
#    SSHTCut= 350.,
    SSHTCut= 0.,
    LeptonCut=1.,
    McAnal =0.,
    pt1eta1 = 0.00078,
    pt1eta2 = 0.001,
    pt1eta3 = 0.00369,
    pt2eta1 = 0.00031,
    pt2eta2 = 0.00071,
    pt2eta3 = 0.002292,
    pt3eta1 = 0.0000414,
    pt3eta2 = 0.00071,
    pt3eta3 = 0.002539,
    pt4eta1 = 0.0000422,
    pt4eta2 = 0.000804,
    pt4eta3 = 0.00234,
    pt5eta1 = 0.00010,
    pt5eta2 = 0.003225,
    pt5eta3 = 0.005870,
    )





ELFlip=BkgFromFlip("ElectronFlip",elFlip.ps())

a += tree
tree.Attach(ssdlTrigg)
tree.TAttach(ssdlTrigg,ELFlip)


TT.ttbarTauola.LastEntry = 500
#Z.zjets_madgraph_vols.LastEntry = 100
#W.wjets_madgraph_vols.LastEntry = 100
#QCD.QCD_AllPtBins_7TeV_Pythia.LastEntry=100
#lm.LM0.LastEntry=100
samples=[
  TT.ttbarTauola,
#         W.wjets_madgraph_vols,
#         Z.zjets_madgraph_vols,
#         QCD.QCD_AllPtBins_7TeV_Pythia
# lm.LM0
         ]

#All_MC=[QCD_AllPtBins_7TeV_Pythia, ttbarTauola, wjets_madgraph, zjets_madgraph,LM0]
utils.reweight(samples, 10.) 

#BatchRun(sig,"MC_HT200","conf","/home/hep/aeg04/SUSY2/ssdl/results",1000000)
a.Run(".", conf, samples)
#utils.reweight(samples, 10.) 
