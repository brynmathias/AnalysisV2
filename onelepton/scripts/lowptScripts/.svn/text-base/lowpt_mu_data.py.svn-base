#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from data.RA1_Complete_Run2010_Nov4ReReco_v1 import *
import wpol.electron_id as eid
#import samples.icf2 as icf
#import samples.icf3 as icf_new
from data.JetMETTau_ALL_230810 import *
#from samples.all_samples_august2010 import *
from SweetBatchSub import *
#from samples.QCD_EMBCE_DCACHE import *
#from samples.QCD_170 import *
#from samples.tt import *
from samples.LMx import *
from samples.tt import *
from samples.zjets_madgraph_filepset import *
#import samples.JetMetTau as data
from samples.wjets import *
from samples.JetMET_Run2010A_PromptReco_v4_250810 import *
from data.JetMET_Run2010A_PromptReco_v4_03092010 import *
from data.Multijet_json291010 import *
from data.MultiJet_Run2010B_PromptReco_v2_408 import *
from data.JetMET_Run2010A_PromptReco_v4_11092010 import *
from data.JetMET_Run2010A_PromptReco_v4_24092010 import *
from data.edward_data_skim_allJetTo_Json151010 import *
from data.Jet_MultiJet_JetMet_38_JSonUpTo151010 import *
from data.MultiJet_json221010 import *
#from icf.utils import local_ntuple

import icf.utils as utils

id_working_point = eid.eff_80

sig_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    CorrEEMisalig = True,
    Ctrl = False,
    Mu = True
    )

bg_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = False,
    DeltaPhiAtVtx = False,
    SigmaIEtaIEta = True,
    Conversions = True,
    CorrEEMisalig = True,
    Ctrl = True,
    Mu = True
)
mu_id = PSet(
   MuID = "Tight",
   MinPt = 5.,
   MaxEta = 2.1,
   MaxIsolation = 0.05,
   MaxGlbTrkDxy = 0.02,
   MinGlbTrkNumOfValidHits = 11,
   MaxGlbTrkChi2ndf = 10.,
   MinDRMuJet = 0.3
   )


mu_bid = PSet(
   MuID = "Tight",
   MinPt = 5.,
   MaxEta = 2.1,
   MaxIsolation = 2.0,
   MaxGlbTrkDxy = 0.02,
   MinGlbTrkNumOfValidHits = 11,
   MaxGlbTrkChi2ndf = 10.,
   MinDRMuJet = 0.3
   )


conf=defaultConfig.copy()

conf.Common.Jets.PtCut = 50.0
conf.Common.Jets.EtaCut = 3.
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.TrkIsoCut = -1.
conf.Common.Muons.CombIsoCut = 0.1
conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4
# These are turned off anyhow
conf.Common.Electrons.TrkIsoCut = -1.
conf.Common.Electrons.CombIsoCut = 0.1
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

conf.Common.ApplyXCleaning=True
#default_cc = deepcopy(defaultConfig.XCleaning)
conf.XCleaning.Verbose=False
conf.XCleaning.MuonJet=True
conf.XCleaning.ElectronJet=True
conf.XCleaning.PhotonJet=True
conf.XCleaning.ResolveConflicts=True
conf.XCleaning.Jets.PtCut=10.0
conf.XCleaning.Jets.EtaCut=10.0
conf.XCleaning.Electrons.CombIsoCut=0.06
conf.XCleaning.Electrons.TrkIsoCut=-1.
conf.XCleaning.Electrons.PtCut=10.
conf.XCleaning.Electrons.ElectronIsoTypePtCutoff = 0.
conf.XCleaning.Muons.PtCut = 5.0
conf.XCleaning.Muons.EtaCut=2.1
conf.XCleaning.Muons.CombIsoCut=0.05
conf.XCleaning.Muons.TrkIsoCut=-1.
conf.XCleaning.Photons.EtCut=25.0
conf.XCleaning.Photons.EtaCut=2.5
conf.XCleaning.Photons.TrkIsoCut=2.0
conf.XCleaning.Muons.MuonIsoTypePtCutoff = 0.
conf.XCleaning.Photons.CaloIsoCut=0.2
conf.XCleaning.Photons.IDReq=3
conf.XCleaning.Electrons.ElectronJetDeltaR=0.3
conf.XCleaning.Muons.MuonJetDeltaR=0.3
conf.XCleaning.Photons.PhotonIsoTypePtCutoff=30.
conf_350 = conf.copy()
conf_300 = conf.copy()
conf_250 = conf.copy()


conf_old_250 = conf.copy()
conf_old_300 = conf.copy()
conf_old_350 = conf.copy()

conf_300.Common.Jets.PtCut = 42.9
conf_250.Common.Jets.PtCut = 35.7
conf_old_350.Common.Jets.PtCut = 30.0
conf_old_300.Common.Jets.PtCut = 25.7
conf_old_250.Common.Jets.PtCut = 21.4
ctrl_conf = conf.copy()
ctrl_conf.Common.Muons.CombIsoCut = 2.
ctrl_conf.XCleaning.Muons.CombIsoCut=2.
from icf.JetCorrections import *
corPset =  CorrectionPset()
JetCorrections = JESCorrections( corPset.ps() )

tree_mu = PSet(
    LeptonType = "Muons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = False
    )
tree_ele = PSet(
    LeptonType = "Electrons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = False
    )

mu_plots_cfg = PSet(
    DirName      = "MuonControlPlots",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen =False,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )

mu_ht200_plots_cfg = PSet(
    DirName      = "MuonControlPlotsHT200",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )

mu_ht300_plots_cfg = PSet(
    DirName      = "MuonControlPlotsHT300",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )
mu_ht350_plots_cfg = PSet(
    DirName      = "MuonControlPlotsHT350",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )
mu_aT_plots_cfg = PSet(
    DirName      = "MuonControlPlotsaT",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )


#ele_plots_cfg = PSet(
 #   Eff_id=3, ## VBTF80
 ##   ElecET=10.,
 #   CorrEEMisalig=False,
 #   useGEN=False,
 #   useObservable="alphaT",
 #   eType="HF"
     #      )
Wj = PSet(
    Name = "Wjets_vols",
    File = ["/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_*.root"],
    Format = ("ICF", 2),
    CrossSection = 24170.
   # FirstEntry=1259727,
   # LastEntry=1359727
)


LM01=PSet(
        Name="LM01",
            Format=("ICF",2),
            File=["/vols/cms02/aeg04/MC_Generator_LMTestPoints/LM0-1_7TeV_SusyCAF_ntupleV00-13-05mod.root"],
            CrossSection=32.69
            )

LM01p=PSet(
    Name="LM01p",
    Format=("ICF",2),
    File=["/vols/cms02/aeg04/MC_Generator_LMTestPoints/LM0-1_2nd_7TeV_26.81_SusyCAF_ntupleV00-13-05mod.root"],
    CrossSection=28.81
    )

LMParis=PSet(
        Name="LMParis",
            Format=("ICF",2),
            File=["/vols/cms02/aeg04/MC_Generator_LMTestPoints/LM-Paris_7TeV_SusyCAF_ntupleV00-13-05mod.root"],
            CrossSection=46.89
            )

QCD_AllPtBins_7TeV_Pythia=PSet(
    Name="QCD_AllPtBins_7TeV_Pythia",
    Format=("ICF",2),
#    LastEntry=23620560,
    File=(
    "/vols/cms02/gouskos/QCD_Pythia_Pt15_Jun2010/SusyCAF_Tree_*.root",
    "/vols/cms02/gouskos/QCD_Pythia_Pt30_Jun2010/SusyCAF_Tree_*.root",
    "/vols/cms02/gouskos/QCD_Pythia_Pt80_Jun2010/SusyCAF_Tree_*.root",
    "/vols/cms02/gouskos/QCD_Pythia_Pt170_Jun2010/SusyCAF_Tree_*.root",
    "/vols/cms02/gouskos/QCD_Pythia_Pt300_Jun2010/SusyCAF_Tree_*.root",
    "/vols/cms02/gouskos/QCD_Pythia_Pt470_Jun2010/SusyCAF_Tree_*.root",
    "/vols/cms02/gouskos/QCD_Pythia_Pt800_Jun2010/SusyCAF_Tree_*.root"
    ),
    Weights = PSet(
    CrossSection = [8.762e+08,6.041e+07,9.238e+05,2.547e+04,1.256e+03  ,
                    8.798e+01,2.186,0.01122  ],
    Events       = [6095857,5069664,2065792,3171950,2976108,2159497,2181700,1185024],
    PtBin        = [15.,30.,80.,170.,300., 470.,800.,1400.],
    )
)

utils.reweight([LM0,LM1, LM01, LM01p, LMParis, QCD_AllPtBins_7TeV_Pythia,
                zjets_madgraph, Wj,ttbarTauola
                ],10.)

#Operations
#trigger = OP_TriggerCut("HLT_Jet70U")
#trigger = OP_TwoTriggerCut("HLT_HT100U","HLT_HT120U")
#trigger = OP_TriggerCut("HLT_Mu9")

selection = OP_GoodEventSelection()
HBHE = OP_HadronicHBHEnoiseFilter()
MuonTreeReq=OP_NumComMuons(">=",1)
LeadingJetEta = OP_FirstJetEta(2.4)
unCorLeadJetCut = OP_UnCorLeadJetCut(70.)
PrintOut = PrintAlphaTEvents()
OneMuon = OP_NumComMuons("==",1)
MaxPtCut = OP_UpperMuPtCut(25.)
ZeroElectrons = OP_NumComElectrons("<=",0)
OneElectron = OP_NumComElectrons("==",1)
OddEli = OP_OddElectron()
ZeroMuons = OP_NumComMuons("<=", 0)
OddMu = OP_OddMuon()
MuJetVeto = OP_MuJetVeto(0.3)
ZeroPhotons = OP_NumComPhotons("<=", 0)
OddPhot = OP_OddPhoton()
GE2Jets = OP_NumComJets(">=", 2)
OddJet = OP_OddJet()
badMuonINJet = OP_BadMuonInJet()
secondJetET = OP_SecondJetEtCut(30.)

HTlep200 = RECO_LeptonicHTCut(200.)
HTlep300 = RECO_LeptonicHTCut(300.)
HTlep350 = RECO_LeptonicHTCut(350.)
LepAlphaTCut = OP_LeptonicAlphaTCut(0.53)
ed_all = OP_EventDisplay("ED_All", "all") #to draw all objects
ed_com = OP_EventDisplay("ED_Com", "common") #to draw all objects


eletree = AnalysisTree("eletree",tree_ele.ps())
mutree = AnalysisTree("mutree",tree_mu.ps())
mutree_iso = AnalysisTree("mutree_iso",tree_mu.ps())

tree = Tree("Main")
# Main trunk of tree
tree.Attach(MuonTreeReq)
tree.TAttach(MuonTreeReq,mutree_iso)
tree.TAttach(mutree_iso,OneMuon)
tree.TAttach(OneMuon,MaxPtCut)
tree.TAttach(MaxPtCut,HTlep200)
tree.TAttach(HTlep200,LepAlphaTCut)
tree.TAttach(LepAlphaTCut,ed_all)
tree.TAttach(ed_all,ed_com)



#customMuID=CustomMuId(0.2, 11, 10)

b_customMuID = CustomVBTFMuID(mu_bid.ps())
customMuID = CustomVBTFMuID(mu_id.ps())
eleS=CustomEleId(sig_id.ps())
eleB=CustomEleId(bg_id.ps())
jet=EleJetDRFilter(0.3)

sig=Analysis("muAlphaT_Signal")
sig.AddMuonFilter("PreCC",customMuID)
sig.AddElectronFilter("PreCC",eleS)
sig.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig+=tree

sig_j50_350=Analysis("muAlphaT_Signal_jet50_350")
sig_j50_350.AddMuonFilter("PreCC",customMuID)
sig_j50_350.AddElectronFilter("PreCC",eleS)
sig_j50_350.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig_j50_350+=tree

sig_j50_300=Analysis("muAlphaT_Signal_jet50_300")
sig_j50_300.AddMuonFilter("PreCC",customMuID)
sig_j50_300.AddElectronFilter("PreCC",eleS)
#sig.AddJetFilter("PreCC",JetCorrections)
sig_j50_300.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig_j50_300+=tree

sig_j50_250=Analysis("muAlphaT_Signal_jet50_250")
sig_j50_250.AddMuonFilter("PreCC",customMuID)
sig_j50_250.AddElectronFilter("PreCC",eleS)
sig_j50_250.AddJetFilter("PreCC",JetCorrections)
sig_j50_250+=tree

sig_j30_350=Analysis("muAlphaT_Signal_jet30_350")
sig_j30_350.AddMuonFilter("PreCC",customMuID)
sig_j30_350.AddElectronFilter("PreCC",eleS)
sig_j30_350.AddJetFilter("PreCC",JetCorrections)

#sig.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig_j30_350+=tree

sig_j30_300=Analysis("muAlphaT_Signal_jet30_300")
sig_j30_300.AddMuonFilter("PreCC",customMuID)
sig_j30_300.AddElectronFilter("PreCC",eleS)
sig_j30_300.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig_j30_300+=tree

sig_j30_250=Analysis("muAlphaT_Signal_jet30_250")
sig_j30_250.AddMuonFilter("PreCC",customMuID)
sig_j30_250.AddElectronFilter("PreCC",eleS)
sig_j30_250.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig_j30_250+=tree

invIso = LepMinIsoFilter(0.3)

ctrl=Analysis("muAlphaT_Control")
ctrl.AddMuonFilter("PreCC",b_customMuID)
ctrl.AddMuonFilter("PreCC",invIso)
ctrl.AddElectronFilter("PreCC",eleS)
ctrl.AddJetFilter("PreCC",JetCorrections)
#ctrl.AddJetFilter("PreCC",jet)
ctrl+=tree


noiso=Analysis("muAlphaTXC_NoIso")
noiso.AddMuonFilter("PreCC",customMuID)
noiso.AddElectronFilter("PreCC",eleS)
noiso.AddJetFilter("PreCC",JetCorrections)
#noiso.AddJetFilter("PreCC",jet)
noiso+=tree

#samples=[JetMET_Run2010A_PromptReco_v4_03092010,JetMET_Run2010A_PromptReco_v4_250810,JetMET_ALL_upto230810,JetMET_Run2010A_PromptReco_v4_11092010,JetMET_Run2010A_PromptReco_v4_24092010]
#Jet_MultiJet_JetMet_38_JSonUpTo151010,MultiJet_json221010
#samples=[Jet_MultiJet_JetMet_38_JSonUpTo151010,MultiJet_json221010,MultiJet_json291010,MultiJet_json051110]
samples=[RA1_Complete_Run2010_Nov4ReReco_v1]
#sig_j50_350.Run("../../results/attempt2", conf_350, samples)
sig_j50_300.Run("../../results/attempt2", conf_300, samples)
#sig_j50_250.Run("../../results/attempt2", conf_250, samples)
#sig_j30_350.Run("../../results/attempt2", conf_old_350, samples)
#sig_j30_300.Run("../../results/attempt2", conf_old_300, samples)
#sig_j30_250.Run("../../results/attempt2", conf_old_250, samples)
#sig.Run("../../results", conf, samples)
#ctrl.Run("../results", ctrl_conf, samples)
#noiso.Run("../results", ctrl_conf, samples)

