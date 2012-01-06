#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libLeptonCommissioning import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig

import leptoncommissioning.electron_id as eid
import samples.icf2 as icf
import samples.icf3 as icf_new
from samples.QCD_Pt30_7TeV_Pythia import *
from samples.QCD_Pt80_7TeV_Pythia import *
from samples.sd_jmt_20100608 import *
from samples.Wjets_June2010_vols import *

from icf.utils import local_ntuple
import icf.utils as utils

#====================================
# Configuration
#====================================

tag = "DeltaInv"
mht_cut = 100.
#gen_match = False #original
#lepton_type = "Electron" #original
gen_match = False
lepton_type = "999"
my_ntuple_path = "/home/alex/Research/Samples/ICF"

conf=defaultConfig.copy()
conf.Common.Jets.EtCut = 20.0
conf.Common.Jets.EtaCut = 5.0
#conf.Ntuple.Jets.Prefix="ak5JetPF"

conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.PtCut = 10.0
conf.Common.Muons.TrkIsoCut = -1.
conf.Common.Muons.CombIsoCut = 99999999.
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
conf.Common.Electrons.TightID=True
conf.Common.Electrons.ApplyID=False

pol_plots_cfg = PSet(
    DoGen = True,#original True
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

QCD_Pt30_7TeV_Pythia_skim=PSet(
    Name="QCD_Pt30_7TeV_Pythia_skim",
    Format=("ICF",2),
    File="/localscratch/Data/StripedFiles_pre6/QCD_Pt30_7TeV_Pythia.root",
    CrossSection = 6.041e+07,
    )

QCD_Pt80_7TeV_Pythia_skim=PSet(
    Name="QCD_Pt80_7TeV_Pythia_skim",
    Format=("ICF",2),
    File="/localscratch/Data/StripedFiles_pre6/QCD_Pt80_7TeV_Pythia.root",
    CrossSection = 9.238e+05,
#    FirstEntry=1,
#    LastEntry=10000,
    )

QCD_Pt30and80_7TeV_Pythia_skim=PSet(
    Name="QCD_Pt30and80_7TeV_Pythia_skim",
    Format=("ICF",2),
    File=(
    "/localscratch/Data/StripedFiles_pre6/QCD_Pt30_7TeV_Pythia.root",
    "/localscratch/Data/StripedFiles_pre6/QCD_Pt80_7TeV_Pythia.root",
    ),
    Weights = PSet(
    CrossSection = [ 6.041e+07, 9.238e+05 ],
    Events       = [ 5369664,   3271800  ],
    PtBin        = [ 30.,       80.   ],
    )
)

#====================================
#trigger = OP_TriggerCut("HLT_Ele15_SW_L1R")
trigger = OP_TriggerCut("HLT_Jet15U")

HBHE = OP_HadronicHBHEnoiseFilter()

ZeroElectrons = OP_NumComElectrons("==",0)
OneMuon = OP_NumComMuons(">=", 1)
ZeroPhotons = OP_NumComPhotons("==", 0)
LT4Jets = OP_NumComJets(">=", 1)

#eleS=CustomEleId(sig_id.ps())
#jet=EleJetDRFilter(0.3)
customMuID=CustomMuId(0.05,10.,2.1)

BasicPlotsPreMHT = MuonTree("muTree", pol_plots_cfg.ps())

tree = Tree("Main")

# Run on Data
#tree.Attach(trigger)
#tree.TAttach(trigger,HBHE)
#tree.TAttach(HBHE,OneMuon)
#tree.TAttach(OneMuon, ZeroElectrons)
#tree.TAttach(ZeroElectrons,BasicPlotsPreMHT)


#Run on MC
tree.Attach(OneMuon)
tree.TAttach(OneMuon, ZeroElectrons)
tree.TAttach(ZeroElectrons,BasicPlotsPreMHT)


#sig=Analysis("muAlphaT_TMOneStLoose")
sig=Analysis("muAlphaT")
#sig.AddElectronFilter("PreCC",eleS)
#sig.AddJetFilter("PreCC",jet)
sig.AddMuonFilter("PreCC",customMuID)
sig+=tree

#samples=[sd_jmt_skmd,mc_qcd15p8_skmd,sd_eg_skmd]
#samples=[QCD_Pt30_7TeV_Pythia]
#samples=[sd_jmt_skmd]
#samples=[sd_jmt_20100608]
#samples=[QCD_Pt30_7TeV_Pythia_skim]
#samples=[QCD_Pt30and80_7TeV_Pythia_skim]
#samples=[mc_qcd15p8_skmd]
samples=[Wjets_June2010_vols]

#scale to the desired luminosity
utils.reweight(samples,1.)
sig.Run("muTrees", conf, samples)
