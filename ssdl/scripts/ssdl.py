#!/usr/bin/env python
# Example analysis script, commented for clarity

import setupSUSY
from SweetBatchSub import *
# Import core framework library and the onelepton library
from libFrameworkSUSY import *
from libSSDL import *
# from libWPol import *
import lep_conf as lepconf
import icf.utils as utils
import icf.types as types

from data.JetMETTau_ALL_230810 import *
from montecarlo.QCD_Pythia6_allBins import *
from montecarlo.TTBarTauola import *
from montecarlo.WJets_Madgraph import *
from montecarlo.Zjets_madgraph import *
from montecarlo.LMx import *

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
JMT_data_test=PSet(
	Name="JMT_test",
        File="/vols/cms02/aeg04/JMT_sample.root",
        Format=("ICF",2),
        Weight=1.0,
#        FirstEntry=147,
#        LastEntry=156      
)

wjets_test=PSet(
    Name="wjets_TEST",
     CrossSection=24170., #normalised to 1/pb (7TeV) = 241.70
    Format=("ICF",2),
    File= [
"/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_10.root",
"/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_11.root"
        ],
    )


data_J50=Analysis("Data_Jet50trig_ssdlsel")
data_HT100=Analysis("Data_HT100trig_ssdlsel")
MC_J50=Analysis("MC_Jet50trig_ssdlsel")
MC_HT200=Analysis("MC_HT200trig_ssdlsel")

the_anals=[data_J50,data_HT100,MC_J50,MC_HT200]
# Create the analysis
a=Analysis("Jet50trig_ssdlselec")
b=Analysis("HT100trig_ssdlselec")

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

for a in the_anals:
    a.AddMuonFilter("PreCC",muonSelFilter)
    a.AddElectronFilter("PreCC",elecSelFilter)
    a.AddElectronFilter("PreCC",muelfilter)
    a.AddTauFilter("PreCC",tauSelFilter)
    a.AddTauFilter("PreCC",mutaufilter)
    a.AddTauFilter("preCC",eletaufilter)
    a.AddJetFilter("PreCC",taujetfilter)
# a.AddMuonFilter("PreCC",muond0filter)
# a.AddElectronFilter("PreCC",elecd0filter) D0 cut is added in custom ID now (taken from ssdlselecSM.py)


# Define some custom collections which we can plug into our analysis
#dc=DemoCompute()
#gm=GenMuons()

# Plug them into the analysis
#a.AddUserVar("MyJets",dc)
#a.AddUserVar("GenMuons",gm)

# With the V2 code you can add linear sets of operations as before
# Here we will use the Tree class to have branching operations
# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger



DataTrigger=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_Jet50U",
         bit2="",
         bit3="",
         bit4="",
         bit5="",
         bit6="",
         bit7="",
         bit8="",
         bit9="",
         bit10=""
         )
       )

DataTrigger_HT=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT100U",
         bit2="",
         bit3="",
         bit4="",
         bit5="",
         bit6="",
         bit7="",
         bit8="",
         bit9="",
         bit10=""
         )
       )

MCTrigger=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_Jet50",
         bit2="",
         bit3="",
         bit4="",
         bit5="",
         bit6="",
         bit7="",
         bit8="",
         bit9="",
         bit10=""
         )
       )

MCTrigger_HT=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200",
         bit2="",
         bit3="",
         bit4="",
         bit5="",
         bit6="",
         bit7="",
         bit8="",
         bit9="",
         bit10=""
         )
       )

ssdlTrigjet_data=SSDLTrigger("DatTrigJet50U",DataTrigger.ps())
ssdlTrigHT_data=SSDLTrigger("DatTrigHT100U",DataTrigger_HT.ps())
ssdlTrigjet_MC=SSDLTrigger("MCTrigJet50",MCTrigger.ps())
ssdlTrigHT_MC=SSDLTrigger("MCTrigHT200",MCTrigger_HT.ps())

Selection=PSet(
    SSMHTCut= 50.,
    SSHTCut=350.,
    MaxPtHat=1000000000.,
    LeptonCut =1.,
    BkgAnal =0.,
    MSugraScan = 0.,
    McAnal=0.,
    PrintLep=0.,
    bogusEvents=True,
    BogusEvFile="BogusEvents.txt",
    recoFile="ssdlReco.txt",
    mcFile="ssdlMC.txt"
    )

ssdlSelec=SSDLSelection("Selection",Selection.ps())

ssdlBkgdCat=SSDLBkgdCat(350.,50.,"BkgdCat")

TTEval=PSet(
    McAnal =1.,    
    )

# ttEval=TTBkgEval("TTEval",TTEval.ps())
# Add the tree to our analysis
data_J50+=ssdlTrigjet_data
data_J50+=ssdlSelec

data_HT100+=ssdlTrigHT_data
data_HT100+=ssdlSelec

MC_J50+=ssdlTrigjet_MC
MC_J50+=ssdlSelec

MC_HT200+=ssdlTrigHT_MC
MC_HT200+=ssdlSelec
MC_HT200+=ssdlBkgdCat
# a+=tree

# tree.Attach(ssdlTrigjet)
# tree.TAttach(ssdlTrigjet,ssdlSelec)
# tree.Attach(ssdlTrigHT)
# tree.TAttach(ssdlTrigHT,ssdlSelec)

#tree.Attach(ttEval)
#tree.TAttach(dijet,plot2)
#tree.Attach(trijet)
#tree.TAttach(trijet,plot3)
#tree.TAttach(plot3,demoop)
samples=[]
# Define the list of samples to run over
data=[JetMET_ALL_upto230810]
SM_MC=[QCD_AllPtBins_7TeV_Pythia, ttbarTauola, wjets_madgraph_vols, zjets_madgraph_vols]
QCD_pythia6=[QCD_Pt30_7TeV_Pythia,QCD_Pt80_7TeV_Pythia,QCD_Pt170_7TeV_Pythia,QCD_Pt300_7TeV_Pythia,QCD_Pt470_7TeV_Pythia,QCD_Pt800_7TeV_Pythia,QCD_Pt1400_7TeV_Pythia]
allqcd=[QCD_AllPtBins_7TeV_Pythia]
all=data+SM_MC
ttbar=[ttbarTauola]
w_z_jets=[wjets_madgraph, zjets_madgraph]
ttbar_bosonJets=[ttbarTauola,wjets_madgraph_vols, zjets_madgraph_vols]
bosonJets_vols=[wjets_madgraph_vols,zjets_madgraph_vols]
wjet=[wjets_madgraph]
zjet=[zjets_madgraph]
test=[JMT_data_test]
wjetstest=[wjets_test]
sig=[LM0]

# data_J50.Run(".",conf,JMT_data_test)
# MC_J50.Run(".",conf,bosonJets_vols)
# MC_HT200.Run("../Results_Oct10",conf,)
data_HT100.Run("./",conf,test)

# BatchRun(data,"data_J50","conf","/home/hep/aeg04/SUSYv2/ssdl/results2",50)
# BatchRun(data,"data_HT100","conf","/home/hep/aeg04/SUSY2/ssdl/results",50)
# BatchRun(bosonJets_vols,"MC_HT200","conf","/home/hep/aeg04/SUSY2/ssdl/results",1)
# BatchRun(allqcd,"MC_HT200","conf","/home/hep/aeg04/SUSY2/ssdl/results",1)
