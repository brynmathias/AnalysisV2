#!/usr/bin/env python
"""
METPas_cfg.py

Created by Bryn Mathias on 2010-05-07.
"""

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from copy import deepcopy
from montecarlo.LMx import *
from bryn_samples import *
from montecarlo.WJets_Madgraph import *
from montecarlo.QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_2600to3000_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *

# -----------------------------------------------------------------------------
# Samples
#from local_samples import *
# from met_samples import *
# from JetMetTau139375_Uncleaned import *

# f=PSet(
# Name="Testing",
# File="~/WokringDir/CleaNJet15U.root",
# Format=("ICF",2),
# Weight = 1.0
# )
qcdPythia8=[QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_2600to3000_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1,
QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2,
QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1]

# -----------------------------------------------------------------------------
# Reading the collections from the ntuple

default_ntuple = deepcopy(defaultConfig.Ntuple)
default_ntuple.Electrons=PSet(
Prefix="electron",
Suffix="Pat",
LooseID="EIDLoose",
TightID="EIDTight",
)
default_ntuple.Muons=PSet(
Prefix="muon",
Suffix="Pat",
LooseID="IsGlobalMuon",
TightID="IDGlobalMuonPromptTight",
)
default_ntuple.Taus=PSet(
Prefix="tau",
Suffix="Pat",
LooseID="TauIdbyTaNCfrOnePercent",
TightID="TauIdbyTaNCfrTenthPercent"
)
default_ntuple.Jets=PSet(
Prefix="ic5Jet",
Suffix="Pat",
)
default_ntuple.Photons=PSet(
Prefix="photon",
Suffix="Pat",
)

ic5_calo = deepcopy(default_ntuple)
ic5_calo.Jets.Prefix="ic5Jet"

ak5_calo = deepcopy(default_ntuple)
ak5_calo.Jets.Prefix="ak5Jet"

ak5_jpt = deepcopy(default_ntuple)
ak5_jpt.Jets.Prefix="ak5JetJPT"

ak5_pf = deepcopy(default_ntuple)
ak5_pf.Jets.Prefix="ak5JetPF"

ak7_calo = deepcopy(default_ntuple)
ak7_calo.Jets.Prefix="ak7Jet"

# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=True
default_cc.ElectronJet=True
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=6.0
default_cc.Muons.CombIsoCut=0.2
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=6.0
default_cc.Electrons.CombIsoCut=0.2
default_cc.Photons.EtCut=10.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=9.0
default_cc.Photons.AllIsoCut=0.2
default_cc.Photons.IDReq=2

# -----------------------------------------------------------------------------
# Definition of common objects

default_common = deepcopy(defaultConfig.Common)

default_common.ApplyXCleaning=True
default_common.Jets.PtCut=30.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False
default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=6.
default_common.Electrons.CombIsoCut=0.2
default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=6.
default_common.Muons.CombIsoCut=0.2
default_common.Photons.EtCut=25.0
default_common.Photons.EtaCut=2.5
default_common.Photons.TrkIsoCut=9.
default_common.Photons.EcalIsoCut=99999.
default_common.Photons.HcalIsoCut=99999.
default_common.Photons.AllIsoCut=0.2
default_common.Photons.IDReq=3
# -----------------------------------------------------------------------------


#Plot the common plots!
pset1 = PSet(
DirName      = "150_250Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset1 = PSet(
DirName      = "n150_250Gev",
MinObjects   = 2,
MaxObjects   = 10,
StandardPlots     = True,
)
pset2 = PSet(
DirName      = "250_350Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset2 = PSet(
DirName      = "n250_350Gev",
MinObjects   = 2,
MaxObjects   = 10,
StandardPlots     = True,
)
pset3 = PSet(
DirName      = "350Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset3 = PSet(
DirName      = "n350Gev",
MinObjects   = 2,
MaxObjects   = 10,
StandardPlots     = True,
)

pset4 = PSet(
DirName      = "AllHtBins",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset4 = PSet(
DirName      = "nAllHtBins",
MinObjects   = 2,
MaxObjects   = 10,
StandardPlots     = True,
)


HadStandard150_250 = HadronicCommonPlots(pset1.ps())
HadStandard250_350 = HadronicCommonPlots(pset2.ps())
HadStandard350 = HadronicCommonPlots(pset3.ps())
HadStandardAll = HadronicCommonPlots(pset4.ps())

nHadStandard150_250 = HadronicCommonPlots(Npset1.ps())
nHadStandard250_350 = HadronicCommonPlots(Npset2.ps())
nHadStandard350 = HadronicCommonPlots(Npset3.ps())
nHadStandardAll = HadronicCommonPlots(Npset4.ps())

# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()
JetTrigger = OP_TriggerCut("HLT_Jet50U")

#Standard Event Selection
LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(100.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(30.)
badMuonINJet = OP_BadMuonInJet()
numComLeptons = OP_NumComLeptons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

DiJet0 = OP_NumComJets("==",2)
DiJet1 = OP_NumComJets("==",2)
DiJet2 = OP_NumComJets("==",2)
DiJet3 = OP_NumComJets("==",2)
NJet0 = OP_NumComJets(">=",3)
NJet1 = OP_NumComJets(">=",3)
NJet2 = OP_NumComJets(">=",3)
NJet3 = OP_NumComJets(">=",3)
LessThan250 = RECO_CommonHTLessThanCut(250.)
LessThan350 = RECO_CommonHTLessThanCut(350.)
htCut150 = RECO_CommonHTCut(150.)
htCut250 = RECO_CommonHTCut(250.)
htCut350 = RECO_CommonHTCut(350.)


#Create Cut Trees!
#First Data!

cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,JetTrigger)
cutTreeData.TAttach(JetTrigger,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,unCorLeadJetCut)
cutTreeData.TAttach(unCorLeadJetCut,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,oddJet)
cutTreeData.TAttach(oddJet,secondJetET)
cutTreeData.TAttach(secondJetET,badMuonINJet)
cutTreeData.TAttach(badMuonINJet,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)

##########DiJet Studies
cutTreeData.TAttach(numComPhotons,htCut150)
cutTreeData.TAttach(htCut150,LessThan250)
cutTreeData.TAttach(LessThan250,DiJet0)
cutTreeData.TAttach(LessThan250,NJet0)
cutTreeData.TAttach(DiJet0,HadStandard150_250)
cutTreeData.TAttach(NJet0,nHadStandard150_250)

cutTreeData.TAttach(numComPhotons,htCut250)
cutTreeData.TAttach(htCut250,LessThan350)
cutTreeData.TAttach(LessThan350,DiJet1)
cutTreeData.TAttach(LessThan350,NJet1)
cutTreeData.TAttach(DiJet1,HadStandard250_350)
cutTreeData.TAttach(NJet1,nHadStandard250_350)

cutTreeData.TAttach(numComPhotons,htCut350)
cutTreeData.TAttach(htCut350,DiJet2)
cutTreeData.TAttach(htCut350,NJet2)
cutTreeData.TAttach(DiJet2,HadStandard350)
cutTreeData.TAttach(NJet2,nHadStandard350)

cutTreeData.TAttach(numComPhotons,DiJet3)
cutTreeData.TAttach(DiJet3,HadStandardAll)

cutTreeData.TAttach(numComPhotons,NJet3)
cutTreeData.TAttach(DiJet3,nHadStandardAll)


#Second MC!

cutTreeMC = Tree("MC")
cutTreeMC.Attach(selection)
cutTreeMC.TAttach(selection,LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,unCorLeadJetCut)
cutTreeMC.TAttach(unCorLeadJetCut,oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,oddJet)
cutTreeMC.TAttach(oddJet,secondJetET)
cutTreeMC.TAttach(secondJetET,badMuonINJet)
cutTreeMC.TAttach(badMuonINJet,numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)

##########DiJet Studies
cutTreeMC.TAttach(numComPhotons,htCut150)
cutTreeMC.TAttach(htCut150,LessThan250)
cutTreeMC.TAttach(LessThan250,DiJet0)
cutTreeMC.TAttach(LessThan250,NJet0)
cutTreeMC.TAttach(DiJet0,HadStandard150_250)
cutTreeMC.TAttach(NJet0,nHadStandard150_250)
cutTreeMC.TAttach(numComPhotons,htCut250)
cutTreeMC.TAttach(htCut250,LessThan350)
cutTreeMC.TAttach(LessThan350,DiJet1)
cutTreeMC.TAttach(LessThan350,NJet1)
cutTreeMC.TAttach(DiJet1,HadStandard250_350)
cutTreeMC.TAttach(NJet1,nHadStandard250_350)
cutTreeMC.TAttach(numComPhotons,htCut350)
cutTreeMC.TAttach(htCut350,DiJet2)
cutTreeMC.TAttach(htCut350,NJet2)
cutTreeMC.TAttach(DiJet2,HadStandard350)
cutTreeMC.TAttach(NJet2,nHadStandard350)


cutTreeMC.TAttach(numComPhotons,DiJet3)
cutTreeMC.TAttach(DiJet3,HadStandardAll)

cutTreeMC.TAttach(numComPhotons,NJet3)
cutTreeMC.TAttach(DiJet3,nHadStandardAll)
#######End of NJet Studies

def addCutFlowData(a) :
  a+=cutTreeData

def addCutFlowMC(b) :
  b+=cutTreeMC


# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

# AK5 Calo

conf_ak5_caloMC = deepcopy(defaultConfig)
conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
conf_ak5_caloMC.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloMC=Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC)

# AK5 Calo

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

# -----------------------------------------------------------------------------
# Run analyses
#IMPERIAL COLLEGE
# anal_ak5_caloData.Run("../results/",conf_ak5_caloData,[JetMETTau_Run2010A_Compleate])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM0])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM1])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM2])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM3])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM4])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[LM5])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,qcdPythia8)
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[wjets_madgraph])
# anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[zjets_madgraph])
anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[ttbarTauola])
#anal_ak5_caloMC.Run("../results",conf_ak5_caloMC,[Zinvisible_jets])



