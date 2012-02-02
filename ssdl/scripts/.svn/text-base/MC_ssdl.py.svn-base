#!/usr/bin/env python


import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.utils import *
from montecarlo.Spring11.TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 as tt
from montecarlo.Spring11.QCD_TuneD6T_HT_100To250_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_100To250_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD1
from montecarlo.Spring11.QCD_TuneD6T_HT_250To500_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_250To500_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD2
from montecarlo.Spring11.QCD_TuneD6T_HT_500To1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_500To1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD3
from montecarlo.Spring11.QCD_TuneD6T_HT_1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD4
from montecarlo.Spring11.WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 as Wjets
from montecarlo.Spring11.LMx_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 import LM0_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 as lm0, LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 as lm1, LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 as lm6, import  LM9_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 as lm9
from montecarlo.Spring11.QCD_Pt_170to300_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_170to300_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd1
from montecarlo.Spring11.QCD_Pt_300to470_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_300to470_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd2
from montecarlo.Spring11.QCD_Pt_470to600_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_470to600_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd3
from montecarlo.Spring11.QCD_Pt_600to800_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_600to800_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd4
from montecarlo.Spring11.DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 as Zjets
from SSDLsamples.mc.PhotonVJets_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import PhotonVJets_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as phoVjets
from SSDLsamples.mc.WWtoAnything_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 import WWtoAnything_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 as WW
from SSDLsamples.mc.ZZtoAnything_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 import ZZtoAnything_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 as ZZ
from SSDLsamples.mc.WZtoAnything_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 import WZtoAnything_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1 as WZ
from montecarlo.Spring11.TToBLNu_TuneZ2_s_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import TToBLNu_TuneZ2_s_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as singleT_schan
from montecarlo.Spring11.TToBLNu_TuneZ2_t_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import TToBLNu_TuneZ2_t_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as singleT_tchan
from montecarlo.Spring11.TToBLNu_TuneZ2_tW_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import TToBLNu_TuneZ2_tW_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as singleT_tW

import lep_conf as lepconf
import icf.utils as utils
import icf.types as types



# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig 

# import default configuration

conf=defaultConfig


conf.Ntuple.Jets.Suffix="Pat"
conf.Ntuple.Jets.Uncorrected=False
conf.Ntuple.Jets.UseGenJets=False
conf.Ntuple.Jets.Prefix="ak5JetPF"
conf.Ntuple.SecJets.Prefix="ak5Jet"
conf.Common.Jets.PtCut = 40.0
conf.Common.Jets.EtaCut = 2.5
conf.Common.Jets.TightID=False
conf.Common.Jets.ApplyID=False

#############################
conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.EtaCut = 2.4
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4
conf.Common.Electrons.TrkIsoCut = 99.
conf.Common.Electrons.CombIsoCut = 99.
conf.Common.Electrons.TightID = False
conf.Common.Electrons.ApplyID = False

#############################
#conf.Ntuple.Taus.Prefix="tauHPS"
conf.Ntuple.Taus.Suffix="PF"
conf.Common.Taus.TightID = False
conf.Common.Taus.ApplyID = False
conf.Common.Taus.PtCut =  15.0
conf.Common.Taus.EtaCut = 2.4

IsoTightTau=2
IsoLooseTau=0
UseHPS=True
tau_id = PSet(
    TauSource=conf.Ntuple.Taus.Prefix,
    tauIDbyIso = IsoTightTau,
    AgainstElectron = True,
    AgainstMuon = True,
    UseHps = UseHPS
)

ele_id = PSet(
    OldNtu = False,
    Cuts = lepconf.ele_ptThres_vbtf80,
    IsolationSR = False,      # high pt
    IsoBarEC = True,
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
    D0sel = True,
    dxychoice = 'beamspot'
)
muon_id = PSet(#we're missing the ecalvetoDep and hcalvetoDep in the ntuples (for MIP requirement) - AGB 22/10/10
   Cuts = lepconf.muonCuts,
   IsolationPF = False,
   IsolationSR = True,
   LowPtIso = True,
   MuonID = True,
   MuonIso = True,
   dxychoice = "beamspot"

)

jet_id = PSet(
    MinConstituents=1,
    MaxEMFrac=0.99,
    MaxHadFrac=0.99,
    FWDMinCHConstituents=0,
    FWDMinCHHadFrac=0.,
    FWDMaxCHEMFrac=0.99
)
elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
tauSelFilter=CustomTauId(tau_id.ps())
jetSelFilter=CustomJetId(jet_id.ps())

muelfilter=MuonElectronDrFilter(0.1)
eletaufilter=ElectronTauDrFilter(0.1)
mutaufilter=MuonTauDrFilter(0.1)

elejetfilter=ElectronJetDrFilter(0.4)
muonjetfilter=MuonJetDrFilter(0.4)
taujetfilter=TauJetDrFilter(0.1)

# Create the analysis
a=Analysis("Sel")

tree  = Tree("Main")

# Create a Tree called Main
#from icf.config import Trigger



##################
## LEP FILTYERS ##
##################

a.AddMuonFilter("PreCC",muonSelFilter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddTauFilter("PreCC",tauSelFilter)
a.AddElectronFilter("PreCC",muelfilter)
a.AddTauFilter("PreCC",mutaufilter)
a.AddTauFilter("PreCC",eletaufilter)
a.AddJetFilter("PreCC",taujetfilter) 
a.AddJetFilter("PreCC",elejetfilter)
a.AddJetFilter("PreCC",muonjetfilter)

Selection=PSet(
    SSMHTCut= 120.,
    SSHTCut= 400.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    UseHps = UseHPS
    )


ssdlSelec=SSDLSelection("Selection",Selection.ps())
taunorm=TauFRNormalization("TAUNORM",Selection.ps())

tauFR=PSet(
    SSMHTCut = 0.,
    SSHTCut = 250.,
    TauSource=conf.Ntuple.Taus.Prefix,
    UpperMetCut=2000.,
    UpperHTCut = 2000.,
    LooseIsolation = IsoLooseTau,
    OppLepRequest = False,
    UseHps = UseHPS
    )


TAUFR=TauFakeRate("TAUFR",tauFR.ps())
TAUFR_MC=TauFakeRate("TAUFR_MC",tauFR.ps())
ZeroMu      = OP_NumComMuons("==",0)
ZeroEl      = OP_NumComElectrons("==",0)
mcnotau = NOMC(15)
ssdlBkgdCat=SSDLBkgdCat(0.,0.,"BkgdCat")
################################################
a += tree
##TRIGGERS
tree.Attach(ssdlSelec)
tree.TAttach(ssdlSelec,ssdlBkgdCat)
tree.Attach(taunorm)
tree.Attach(mcnotau)
tree.TAttach(mcnotau,TAUFR_MC)
tree.Attach(ZeroMu)
tree.TAttach(ZeroMu,ZeroEl)
tree.TAttach(ZeroEl,TAUFR)
#latestdata=[tt,QCD1,QCD2,QCD3,QCD4,Wjets,lm0,qcd1,qcd2,qcd3,qcd4,Zjets]
#latestdata=[lm0]

mc = [tt,QCD1,QCD2,QCD3,QCD4,Wjets,qcd1,qcd2,qcd3,qcd4,Zjets]
irreducible = [WW, WZ, ZZ, phoVjets]
ww = [WW]
wz = [WZ]
zz = [ZZ]
pho = [phoVjets]
lmx = [lm6, lm1, lm9]
singleT = [singleT_schan, singleT_tchan, singleT_tW]
test = [singleT_tW]
allMC = mc + irreducible + lmx + singleT

from datetime import date
outpath = './AGB_MC_' + str(date.today()) + '_HT400Mht120_test'
import os
if os.path.exists(outpath):
    print 'Warning, outpath: ' + outpath + ' already exists'
else:
    os.mkdir(outpath)

a.Run(outpath, conf, allMC)
