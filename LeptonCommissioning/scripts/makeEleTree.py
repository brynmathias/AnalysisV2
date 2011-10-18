#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libLeptonCommissioning import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig

import leptoncommissioning.electron_id as eid
import samples.icf2 as icf
import samples.icf3 as icf_new
import samples.JetMetTau as data

from icf.utils import local_ntuple
#from samples.mc_qcd15_pythia8 import *
#====================================
# Configuration
#====================================

tag = "DeltaInv"
mht_cut = 100.
gen_match = False
lepton_type = "Electron"
my_ntuple_path = "/home/alex/Research/Samples/ICF"
id_working_point = eid.eff_70
id_working_point_noIso = eid.eff_80

sig_id = PSet(
    Cuts = id_working_point_noIso,
    useIso = False,
    Isolation = True,
    HoverE = True,
    DeltaAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True
)

bg_id = PSet(
    Cuts = id_working_point_noIso,
    useIso = False,
    Isolation = True,
    HoverE = True,
    DeltaAtVtx = False,
    SigmaIEtaIEta = True,
    Conversions = True
)

conf=defaultConfig.copy()
conf.Common.Jets.EtCut = 20.0
conf.Common.Jets.EtaCut = 5.0
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.PtCut = 15.0
conf.Common.Muons.TrkIsoCut = -1.
conf.Common.Muons.CombIsoCut = 0.1
conf.Common.Electrons.PtCut = 5.0
conf.Common.Electrons.EtaCut = 2.4
# These are turned off anyhow
conf.Common.Electrons.TrkIsoCut = -1.
conf.Common.Electrons.CombIsoCut = 0.1
conf.Common.Electrons.TightID = True

conf.Common.Photons.EtCut = 25.0
conf.Common.Photons.EtaCut = 2.5
conf.Common.Photons.TrkIsoCut = 9.
conf.Common.Photons.EcalIsoCut = 99999.
conf.Common.Photons.HcalIsoCut = 99999.
conf.Common.Photons.AllIsoCut = 0.2
conf.Common.Photons.IDReq = 3
conf.Common.ApplyXCleaning=False

#conf.Common.ApplyXCleaning=True
#conf.XCleaning.ElectronJet=True
#conf.XCleaning.MuonJet=True
#conf.XCleaning.PhotonJet=True
#conf.XCleaning.ResolveConflicts=True
#conf.XCleaning.Verbose=True

conf.Common.Electrons.TightID=False
conf.Common.Electrons.ApplyID=False

pol_plots_cfg = PSet(
    DoGen = True,
    LeptonType = lepton_type,
    METThreshold = 0.,
)

sd_jmt_skmd=PSet(
    Name="SD_JMT_SKMD",
    Format=("ICF",2),
    File=["/vols/cms02/elaird1/03_skims/cleaned/JetMETTau.Run2010A-May27thReReco_v1.RECO/JetMETTau.Run2010A-May27thReReco_v1.RECO_*.root","/vols/cms02/elaird1/03_skims/cleaned/MinimumBias.Commissioning10-SD_JetMETTau-v9.RECO/MinimumBias.Commissioning10-SD_JetMETTau-v9.RECO_*.root","/vols/cms02/elaird1/03_skims/cleaned/MinimumBias.Commissioning10-May6thPDSkim2_SD_JetMETTau-v1.RECO/MinimumBias.Commissioning10-May6thPDSkim2_SD_JetMETTau-v1.RECO_*.root"],
    Weight=1.
    )
mc_qcd15p8_skmd=PSet(
    Name="MC_QCD15P8_SKMD",
    Format=("ICF",2),
    File=["/vols/cms02/elaird1/03_skims/cleaned/QCD_Pt-15_7TeV-pythia8.Spring10-START3X_V26B-v1.GEN-SIM-RECO/QCD_Pt-15_7TeV-pythia8.Spring10-START3X_V26B-v1.GEN-SIM-RECO_*.root"],
    Weight=1.
    )

sd_eg_skmd=PSet(
    Name="SD_EG_SKMD",
    Format=("ICF",2),
    File="/vols/cms02/bm409/EG_AllDataSkim_skim.root",
    Weight=1.
    )

Wj = PSet(
    Name = "Wjets",
    File = ["/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_*.root"],
    Format = ("ICF", 2),
    CrossSection = 24170.
)


JetMetTau=PSet(
    Name="JetMETTau",
    Format=("ICF",2),
    Weight=1.0,
    File=[
    "/vols/cms02/bm409/JetMetTau7_7_10/SusyCAF_Tree_*",
    "/vols/cms02/bm409/JetMetTau7_7_10/1/SusyCAF_Tree_*",
    "/vols/cms02/bm409/JetMetTau7_7_10/2/SusyCAF_Tree_*",
    "/vols/cms02/bm409/JetMetTau7_7_10/3/SusyCAF_Tree_*"
    ]
)

qcd_pythia_merged=PSet(
    Name="QCD_Pythia_Merged",
    Format=("ICF",2),
    File=(
    "/home/georgia/dataICF/QCDJets_pt30_N.root",
    "/home/georgia/dataICF/QCDJets_pt80_N.root"
    ),
    Weights = PSet(
    CrossSection = [ 6.041e+04, 9.238e+02 ],
    Events       = [ 4869664,   2921800  ],
    PtBin        = [ 30.,       80.   ],
    )
)

#====================================
#trigger = OP_TriggerCut("HLT_Ele15_SW_L1R")
trigger = OP_TriggerCut("HLT_Jet15U")

selection = OP_GoodEventSelection()
HBHE = OP_HadronicHBHEnoiseFilter()

OneElectron = OP_NumComElectrons(">=",1)
odde = OP_OddElectron()
ZeroMuons = OP_NumComMuons("==", 0)
oddm = OP_OddMuon()
ZeroPhotons = OP_NumComPhotons("==", 0)
LT4Jets = OP_NumComJets(">=", 1)
oddj = OP_OddJet()

BasicPlotsPreMHT = ElectronTree("eTree_PreMHT", pol_plots_cfg.ps())


tree = Tree("Main")
# Main trunk of tree
tree.Attach(trigger)
tree.TAttach(trigger,selection)
tree.TAttach(selection,HBHE)
tree.TAttach(HBHE,OneElectron)
tree.TAttach(OneElectron,ZeroMuons)
tree.TAttach(ZeroMuons,oddj)
tree.TAttach(oddj,BasicPlotsPreMHT)

#tree.TAttach(OneElectron,odde)
#tree.TAttach(odde,ZeroMuons)
#tree.TAttach(ZeroMuons,oddm)
#tree.TAttach(oddm,oddj)
#tree.TAttach(oddj,BasicPlotsPreMHT)

eleS=CustomEleId(sig_id.ps())
eleB=CustomEleId(bg_id.ps())
jet=EleJetDRFilter(0.3)

sig=Analysis("eWPol_Signal_OddXClean")
sig.AddElectronFilter("PreCC",eleS)
sig.AddJetFilter("PreCC",jet)
sig+=tree

control=Analysis("eWPol_Control_OddXClean")
control.AddElectronFilter("PreCC",eleB)
control.AddJetFilter("PreCC",jet)
control+=tree

#samples=[sd_jmt_skmd,mc_qcd15p8_skmd]
samples=[JetMetTau]
#samples=[Wj]

sig.Run("scripts/eTrees", conf, samples)
control.Run("scripts/eTrees",conf,samples)

