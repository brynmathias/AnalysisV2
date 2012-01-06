#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.config import defaultConfig

import wpol.electron_id as eid
#import samples.icf2 as icf
#import samples.icf3 as icf_new
from data.JetMETTau_ALL_230810 import *
#from samples.all_samples_august2010 import *

#from samples.QCD_EMBCE_DCACHE import *
#from samples.QCD_170 import *
#from samples.tt import *
from samples.LMx import *
from samples.tt import *
from samples.zjets_madgraph_filepset import *
#import samples.JetMetTau as data
from samples.wjets import *
#from icf.utils import local_ntuple
from montecarlo.QCD_Mu_Pt80to120_Summer10_START36_V9_S09_v1 import *
from montecarlo.QCD_Mu_Pt50to80_Summer10_START36_V9_S09_v1 import *
from montecarlo.QCD_Mu_Pt30to50_Summer10_START36_V9_S09_v1 import *
from montecarlo.QCD_Mu_Pt20to30_Summer10_START36_V9_S09_v1 import *
from montecarlo.QCD_Mu_Pt170toInf_Summer10_START36_V9_S09_v1 import *
from montecarlo.QCD_Mu_Pt120to170_Summer10_START36_V9_S09_v1 import *

import icf.utils as utils

id_working_point = eid.eff_80
pf_ele_id = PSet(
    IsoPF = 0.2,
    EleMva = 0.4,
    LostHits = 1.,
    ElecDxy = 0.04,
    ElecDz = 1.
    )

pf_mu_id = PSet(
    IsoPF = 0.2,
    ValidHits = 11.,
    MuonID = True,
    MuonDxy = 0.02,
    MuonDz = 1.
    )
sig_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    Ctrl = False
    )

bg_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = False,
    DeltaPhiAtVtx = False,
    SigmaIEtaIEta = True,
    Conversions = True,
    Ctrl = True
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
conf.Ntuple.Electrons.Suffix = "PF"
conf.Ntuple.Muons.Suffix = "PF"
conf.Ntuple.Taus.Suffix = "Pat"
conf.Ntuple.Jets.Suffix = "Pat"
conf.Ntuple.Jets.Prefix = "ak5JetPF2PAT"

conf.Ntuple.SecMuons.Suffix = "Pat"
conf.Ntuple.Jets.Prefix="ak5JetJPT"
conf.Common.Jets.PtCut = 30.0
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

conf.Common.ApplyXCleaning=False
#default_cc = deepcopy(defaultConfig.XCleaning)

#conf.Common.ApplyXCleaning=True




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
    GenInfo = True
    )
tree_ele = PSet(
    LeptonType = "Electrons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = True
    )

mu_plots_cfg = PSet(
    DirName      = "MuonControlPlots",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen =True,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = True,
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
    doGen = True,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = True,
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
    doGen = True,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = True,
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
    doGen = True,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = True,
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
    doGen = True,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = True,
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
    PtBin        = [15.,30.,80.,170.,300., 470.,800.,1400.]
    )
)

utils.reweight([LM0,LM1, LM01, LM01p, LMParis, QCD_AllPtBins_7TeV_Pythia,
                zjets_madgraph, Wj,ttbarTauola,QCD_Mu_Pt80to120_Summer10_START36_V9_S09_v1,QCD_Mu_Pt50to80_Summer10_START36_V9_S09_v1,QCD_Mu_Pt30to50_Summer10_START36_V9_S09_v1,QCD_Mu_Pt20to30_Summer10_START36_V9_S09_v1,QCD_Mu_Pt170toInf_Summer10_START36_V9_S09_v1,QCD_Mu_Pt120to170_Summer10_START36_V9_S09_v1
                ],10.)

#Operations
trigger = OP_TriggerCut("HLT_Jet50")
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
LepAlphaTCut = OP_LeptonicAlphaTCut(0.55)

#MuonPlots = LeptonicCommonPlots(mu_plots_cfg.ps())
#MuonPlotsHT200 =  LeptonicCommonPlots(mu_ht200_plots_cfg.ps())
#MuonPlotsHT300 =  LeptonicCommonPlots(mu_ht300_plots_cfg.ps())
#MuonPlotsHT350 =  LeptonicCommonPlots(mu_ht350_plots_cfg.ps())
#MuonPlotsaT =  LeptonicCommonPlots(mu_aT_plots_cfg.ps())

eletree = AnalysisTree("eletree",tree_ele.ps())
mutree = AnalysisTree("mutree",tree_mu.ps())
mutree_iso = AnalysisTree("mutree_iso",tree_mu.ps())
tree = Tree("Main")
# Main trunk of tree
tree.Attach(MuonTreeReq)
tree.TAttach(MuonTreeReq,mutree_iso)
customMuID = CustomVBTFMuID(mu_id.ps())
PF_MU_ID = PFMuId(pf_mu_id.ps())
PF_ELE_ID = PFEleId(pf_ele_id.ps())
b_customMuID = CustomVBTFMuID(mu_bid.ps())
#customMuID=CustomMuId(0.2, 11, 10)



eleS=CustomEleId(sig_id.ps())
eleB=CustomEleId(bg_id.ps())
jet=EleJetDRFilter(0.3)

sig=Analysis("PF_muAlphaT_Signal")
sig.AddMuonFilter("PreCC",PF_MU_ID)
sig.AddElectronFilter("PreCC",PF_ELE_ID)
#sig.AddJetFilter("PreCC",jet)
sig+=tree

invIso = LepMinIsoFilter(0.3)


ctrl=Analysis("PF_muAlphaT_Control")
ctrl.AddMuonFilter("PreCC",b_customMuID)
ctrl.AddMuonFilter("PreCC",invIso)
ctrl.AddElectronFilter("PreCC",eleS)
#ctrl.AddJetFilter("PreCC",jet)

ctrl+=tree

noiso=Analysis("muAlphaTXC_NoIso")
noiso.AddMuonFilter("PreCC",customMuID)
noiso.AddElectronFilter("PreCC",eleS)
#noiso.AddJetFilter("PreCC",jet)
noiso+=tree

#samples=[ QCD_AllPtBins_7TeV_Pythia]
#samples=[z_jets, w_jets]
#samples=[ttbar_jets, z_jets, w_jets, QCD_AllPtBins_7TeV_Pythia]
#data=[JetMET_ALL_upto230810]
#qcd_sample=[QCD_AllPtBins_7TeV_Pythia]
samples=[LM0,LM1,zjets_madgraph,ttbarTauola,Wj,QCD_Mu_Pt80to120_Summer10_START36_V9_S09_v1,QCD_Mu_Pt50to80_Summer10_START36_V9_S09_v1,QCD_Mu_Pt30to50_Summer10_START36_V9_S09_v1,QCD_Mu_Pt20to30_Summer10_START36_V9_S09_v1,QCD_Mu_Pt170toInf_Summer10_START36_V9_S09_v1,QCD_Mu_Pt120to170_Summer10_START36_V9_S09_v1]
#samples=[LM01,LMParis]
#ctrl.Run("../results", ctrl_conf, samples)
#LM0,LM1,Wj

sig.Run("../results", conf, samples)
#ctrl.Run("../results", ctrl_conf, samples)
#noiso.Run("../results", ctrl_conf, samples)
