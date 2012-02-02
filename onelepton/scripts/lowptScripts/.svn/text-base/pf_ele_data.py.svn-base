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
from SweetBatchSub import *
#from samples.QCD_EMBCE_DCACHE import *
#from samples.QCD_170 import *
#from samples.tt import *
from samples.LMx import *
from samples.zjets_madgraph_filepset import *
from samples.JetMET_Run2010A_PromptReco_v4_250810 import *
from data.JetMET_Run2010A_PromptReco_v4_03092010 import *
from data.JetMET_Run2010A_PromptReco_v4_11092010 import *
from data.JetMET_Run2010A_PromptReco_v4_24092010 import *

from data.edward_data_skim_allJetTo_Json151010 import *
from data.Jet_MultiJet_JetMet_38_JSonUpTo151010 import *
from data.Multijet_json291010 import *
from data.MultiJet_Run2010B_PromptReco_v2_408 import *
from samples.QCD_EMBCE_DCACHE import *


from data.MultiJet_json221010 import *

#import samples.JetMetTau as data
from samples.wjets import *
#from icf.utils import local_ntuple

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
    CorrEEMisalig = False,
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
    CorrEEMisalig = False,
    Ctrl = True
)
sig_noiso_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    Ctrl = False
    )

bg_noiso_id = PSet(
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
conf=defaultConfig.copy()
conf.Ntuple.Electrons.Suffix = "PF"
conf.Ntuple.Muons.Suffix = "PF"
conf.Ntuple.Taus.Suffix = "Pat"
conf.Ntuple.Jets.Suffix = "Pat"
conf.Ntuple.Jets.Prefix = "ak5JetPF2PAT"

conf.Ntuple.SecMuons.Suffix = "Pat"
#conf.Ntuple.SecJets.Prefix = "ak5Jet"
#conf.Ntuple.SecElectrons.Suffix = "Pat"


conf.Common.Jets.PtCut = 30.0
conf.Common.Jets.EtaCut = 3.
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.PtCut = 10.0
conf.Common.Muons.TrkIsoCut = -1.
conf.Common.Muons.CombIsoCut = 0.1
conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4
# These are turned off anyhow
conf.Common.Electrons.TrkIsoCut = -1.
conf.Common.Electrons.CombIsoCut = 1.0
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




#ctrl_conf = conf.copy()
#ctrl_conf.Common.Muons.CombIsoCut = 2.
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


ele_plots_cfg = PSet(
    DirName      = "ElecControlPlots",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen =False,
    LeptonType = "Electron",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )

ele_ht200_plots_cfg = PSet(
    DirName      = "ElecControlPlotsHT200",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Electron",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )

ele_ht300_plots_cfg = PSet(
    DirName      = "ElecControlPlotsHT300",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Electron",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )

ele_ht350_plots_cfg = PSet(
    DirName      = "ElecControlPlotsHT350",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Electron",
    AlphaT = True,
    PtHat = False,
    FABS_EtaJ1 = True,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True
    )
ele_aT_plots_cfg = PSet(
    DirName      = "ElecControlPlotsaT",
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Electron",
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
                zjets_madgraph,bce_80to170
                ],10.)

#Operations
trigger = OP_TwoTriggerCut("HLT_HT100U","HLT_HT120U")
#trigger = OP_TriggerCut("HLT_Mu9")

selection = OP_GoodEventSelection()
HBHE = OP_HadronicHBHEnoiseFilter()
EleTreeReq=OP_NumComElectrons(">=",1)
LeadingJetEta = OP_FirstJetEta(2.4)
unCorLeadJetCut = OP_UnCorLeadJetCut(70.)
PrintOut = PrintAlphaTEvents()
OneMuon = OP_NumComMuons("==",1)
MaxPtCut = OP_UpperElePtCut(25.)
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

ed_all = OP_EventDisplay("ED_All", "all") #to draw all objects
ed_com = OP_EventDisplay("ED_Com", "common") #to draw all objects


eletree = AnalysisTree("eletree",tree_ele.ps())
mutree = AnalysisTree("mutree",tree_mu.ps())


tree = Tree("Main")
# Main trunk of tree
tree.Attach(EleTreeReq)
tree.TAttach(EleTreeReq,eletree)
tree.TAttach(eletree,OneElectron)
tree.TAttach(OneElectron,MaxPtCut)
tree.TAttach(MaxPtCut,HTlep200)
tree.TAttach(HTlep200,LepAlphaTCut)
tree.TAttach(LepAlphaTCut,ed_all)
tree.TAttach(ed_all,ed_com)
PF_MU_ID = PFMuId(pf_mu_id.ps())
PF_ELE_ID = PFEleId(pf_ele_id.ps())

customMuID = CustomVBTFMuID(mu_id.ps())
#customMuID=CustomMuId(0.2, 11, 10) 
eleS=CustomEleId(sig_id.ps())
eleB=CustomEleId(bg_id.ps())
eleSnoiso=CustomEleId(sig_noiso_id.ps())
eleBnoiso=CustomEleId(bg_noiso_id.ps())
#jet=EleJetDRFilter(0.3)

sig=Analysis("PF_eAlphaT_Signal")
sig.AddMuonFilter("PreCC",PF_MU_ID)
sig.AddElectronFilter("PreCC",PF_ELE_ID)
sig.AddJetFilter("PreCC",JetCorrections)
#sig.AddJetFilter("PreCC",jet)
sig+=tree

invIso = LepMinIsoFilter(0.3)

ctrl=Analysis("PF_eAlphaT_Control")
ctrl.AddMuonFilter("PreCC",customMuID)
ctrl.AddElectronFilter("PreCC",eleB)
ctrl.AddJetFilter("PreCC",JetCorrections)
#ctrl.AddJetFilter("PreCC",jet)

ctrl+=tree

sig_noiso=Analysis("eAlphaT_SignalNoIso")
sig_noiso.AddMuonFilter("PreCC",customMuID)
sig_noiso.AddElectronFilter("PreCC",eleSnoiso)
sig_noiso.AddJetFilter("PreCC",JetCorrections)
#sig_noiso.AddJetFilter("PreCC",jet)
sig_noiso+=tree

invIso = LepMinIsoFilter(0.3)

ctrl_noiso=Analysis("eAlphaT_ControlNoIso")
ctrl_noiso.AddMuonFilter("PreCC",customMuID)
ctrl_noiso.AddElectronFilter("PreCC",eleBnoiso)
#ctrl_noiso.AddJetFilter("PreCC",jet)
ctrl_noiso.AddJetFilter("PreCC",JetCorrections)
ctrl_noiso+=tree


#samples=[JetMET_Run2010A_PromptReco_v4_03092010,JetMET_Run2010A_PromptReco_v4_250810,JetMET_ALL_upto230810,JetMET_Run2010A_PromptReco_v4_11092010,JetMET_Run2010A_PromptReco_v4_24092010]

#samples=[All38SkimsUpto151010_Jet_MultiJet]

#samples=[bce_80to170]
#Jet_MultiJet_JetMet_38_JSonUpTo151010,MultiJet_json221010,MultiJet_json291010,MultiJet_json051110]
samples=[Jet_MultiJet_JetMet_38_JSonUpTo151010,MultiJet_json221010,MultiJet_json291010,MultiJet_json051110]
sig.Run("../results", conf, samples)
#ctrl.Run("../results", conf, samples)
#sig_noiso.Run("../results", conf, samples)
##ctrl_noiso.Run("../results", conf, samples)
