#!/usr/bin/env python

import setupSUSY
from SweetBatchSub import *
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.config import defaultConfig

import wpol.electron_id as eid
#import onelepton.electron_id as eid
from samples.Wjets_June2010 import *
from samples.Zjets_June2010 import *
from samples.QCD_Pythia_AllPtBins_June2010 import *
from samples.TTbarTauola_June2010 import *
from samples.LM0_June2010 import *
from samples.LM1_June2010 import *

from samples.QCD_38_Pythia6_Pt30to50     import *
from samples.QCD_38_Pythia6_Pt50to80     import *
from samples.QCD_38_Pythia6_Pt80to120    import *
from samples.QCD_38_Pythia6_Pt120to170   import *
from samples.QCD_38_Pythia6_Pt170to300   import *
from samples.QCD_38_Pythia6_Pt300to470   import *
from samples.QCD_38_Pythia6_Pt470to600   import *
from samples.QCD_38_Pythia6_Pt600to800   import *
from samples.QCD_38_Pythia6_Pt800to1000  import *
from samples.QCD_38_Pythia6_Pt1000to1400 import *
from samples.QCD_38_Pythia6_Pt1400to1800 import *
from samples.QCD_38_Pythia6_Pt1800toInf  import *

import samples.Mu_Run2010A_CMSSW38X_1 as mu38X_A_1
import samples.Mu_Run2010B_CMSSW38X_1 as mu38X_B_1
import samples.Mu_Run2010B_CMSSW38X_2 as mu38X_B_2
import samples.Mu_Run2010B_CMSSW38X_3 as mu38X_B_3
import samples.Mu_Run2010B_CMSSW38X_4 as mu38X_B_4
import samples.Mu_Run2010B_CMSSW38X_5 as mu38X_B_5

#import samples.Mu_Run2010A_Nov4ReReco_v1 as mu38X_Nov4ReReco_1
#import samples.Mu_Run2010B_Nov4ReReco_v1 as mu38X_Nov4ReReco_2

import icf.utils as utils

id_working_point = eid.eff_80


conf=defaultConfig.copy()

conf.Common.Jets.PtCut = 30.0
conf.Common.Jets.EtaCut = 2.4
conf.Common.Muons.EtaCut = 2.4
conf.Common.Muons.PtCut = 10.0
#conf.Common.Muons.TrkIsoCut = 999999999.
conf.Common.Muons.CombIsoCut = 0.05
conf.Common.Muons.ApplyID=True
conf.Common.Electrons.PtCut = 15.0 #it was 15 put it so again
conf.Common.Electrons.EtaCut = 2.5
# These are turned off anyhow
#conf.Common.Electrons.TrkIsoCut = -1.
conf.Common.Electrons.CombIsoCut = 0.2
conf.Common.Electrons.TightID=False
conf.Common.Electrons.ApplyID=False

conf.Common.Photons.EtCut = 25.0
conf.Common.Photons.EtaCut = 2.5

conf.Common.Photons.TrkIsoRel=0.
conf.Common.Photons.TrkIsoCut=99999.
conf.Common.Photons.EcalIsoRel=0.
conf.Common.Photons.EcalIsoCut=99999.
conf.Common.Photons.HcalIsoRel=0.
conf.Common.Photons.HcalIsoCut=99999.
conf.Common.Photons.HadOverEmCut=0.5
conf.Common.Photons.SigmaIetaIetaCut=0.5
#conf.Common.Photons.CaloIsoCut=0.2
conf.Common.Photons.IDReq=2

conf.Common.ApplyXCleaning=False
default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=False
default_cc.ElectronJet=False
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=30.0
default_cc.Jets.EtaCut=2.4
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=2

from icf.JetCorrections import *
corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
#corPset = CorrectionPset()
JetCorrections = JESCorrections( corPset.ps() ,0)


ctrl_conf = conf.copy()
ctrl_conf.Common.Muons.CombIsoCut = 2.



# AnalysisTree code inputs 
fillLightTree_cfg = PSet(
    LeptonType = "Muons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = False ## False for DATA, True for MC
    )


# Muon definition
Mus = PSet(
    MuID = "Tight",
    MinPt = 10.,
    MaxEta = 2.1,
    MaxIsolation = 0.05,
    MaxGlbTrkDxy = 0.02,
    MinGlbTrkNumOfValidHits = 11,
    MaxGlbTrkChi2ndf = 10.
    )
customMuID = CustomVBTFMuID(Mus.ps())


#Operations

#PrintInfo = PrintInfo()

triggerLM1  = OP_TriggerCut("HLT_Mu9")
triggerDATA = Mix2Triggers(147196,"HLT_Mu9","HLT_Mu15_v1")

selection = OP_GoodEventSelection()
HBHE = OP_HadronicHBHEnoiseFilter()
#WhichRunNumber = OP_WhichRunNumber(146644)

OneMu      = OP_NumComMuons("==",1)
OneLooseMu = NumOfLooseMuons("==",1)

ZeroLooseEl = NumOfLooseElectrons("==",0)


#MC
AtLeast4Jts = OP_NumComJets(">=",4)
CaloMET100 = OP_caloMETCut(100.)

#DATA
AtLeast2Jts = OP_NumComJets(">=",2)
CaloMET20 = OP_caloMETCut(20.)


AnalysisTree = AnalysisTree_HighPt("MuonTree", fillLightTree_cfg.ps())

tree = Tree("Main")

sig=Analysis("LP_Muons_CaloJets")
sig.AddMuonFilter("PreCC",customMuID)
sig.AddJetFilter("PreCC",JetCorrections) ## un-comment for DATA, comment for MC
sig+=tree


## Main trunk of tree

## un-comment for DATA
#tree.Attach(triggerDATA)
#tree.TAttach(triggerDATA,selection)

## un-comment for MC
tree.Attach(selection)


## un-comment For DATA
tree.TAttach(selection,HBHE)
tree.TAttach(HBHE,OneMu)

## un-comment For MC
#tree.TAttach(selection,OneMu)

tree.TAttach(OneMu,OneLooseMu)
tree.TAttach(OneLooseMu,ZeroLooseEl)
tree.TAttach(ZeroLooseEl,AnalysisTree)
tree.TAttach(AnalysisTree,AtLeast4Jts)
tree.TAttach(AtLeast4Jts,CaloMET100)


#simplesMC = [Wjets_June2010, TTbarTauola_June2010, LM0_June2010, LM1_June2010, Zjets_June2010, QCD_Pythia_AllPtBins_June2010]
simplesMC = [LM0_June2010]

simplesMCqcd = [
    QCD_Pythia_AllPtBins_June2010,
    QCD_38_Pythia6_Pt30to50,
    QCD_38_Pythia6_Pt50to80,
    QCD_38_Pythia6_Pt80to120,
    QCD_38_Pythia6_Pt120to170,
    QCD_38_Pythia6_Pt170to300,
    QCD_38_Pythia6_Pt300to470,
    QCD_38_Pythia6_Pt470to600,
    QCD_38_Pythia6_Pt600to800,
    QCD_38_Pythia6_Pt800to1000,
    QCD_38_Pythia6_Pt1000to1400,
    QCD_38_Pythia6_Pt1400to1800,
    QCD_38_Pythia6_Pt1800toInf
    ]

samples = [
    mu38X_A_1.Mu_Run2010A_CMSSW38X_1
#    mu38X_B_1.Mu_Run2010B_CMSSW38X_1,
#    mu38X_B_2.Mu_Run2010B_CMSSW38X_2,
#    mu38X_B_3.Mu_Run2010B_CMSSW38X_3,
#    mu38X_B_4.Mu_Run2010B_CMSSW38X_4,
#    mu38X_B_5.Mu_Run2010B_CMSSW38X_5
    ]


utils.reweight(simplesMC, 1.)

sig.Run("/vols/cms02/gouskos/onelepton/20110120", conf, simplesMC)

#BatchRun(samples,"sig","conf","/vols/cms02/gouskos/onelepton/Muons_MuDS_20101026",50000)
