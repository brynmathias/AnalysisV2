#!/usr/bin/env python

#!/usr/bin/env python
"""
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
from icf.JetCorrections import *



# -----------------------------------------------------------------------------
# Samples
#import yours in your running script



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
default_ntuple.SecMuons=PSet(
    Prefix="muon",
    Suffix="PF")
default_ntuple.Taus=PSet(
Prefix="tau",
Suffix="Pat",
LooseID="TauIdbyTaNCfrOnePercent",
TightID="TauIdbyTaNCfrTenthPercent"
)
default_ntuple.Jets=PSet(
Prefix="ic5Jet",
Suffix="Pat",
Uncorrected=False,
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
ak5_pf.Electrons.Prefix="PF"
ak5_pf.Muons.Prefix="PF"
ak5_pf.SecMuons.Prefix="Pat"

ak7_calo = deepcopy(default_ntuple)
ak7_calo.Jets.Prefix="ak7Jet"


# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False
default_cc.MuonJet=False
default_cc.ElectronJet=True
default_cc.PhotonJet=True
default_cc.ResolveConflicts=True
default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0
default_cc.Muons.ModifyJetEnergy=True
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=6.0
default_cc.Muons.CombIsoCut=0.2
default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=6.0
default_cc.Electrons.CombIsoCut=0.2
default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=2

# -----------------------------------------------------------------------------
# Definition of common objects

default_common = deepcopy(defaultConfig.Common)

default_common.ApplyXCleaning=True
default_common.Jets.PtCut=50.0
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
default_common.Photons.TrkIsoRel=0.
default_common.Photons.TrkIsoCut=99999.
default_common.Photons.EcalIsoRel=0.
default_common.Photons.EcalIsoCut=99999.
default_common.Photons.HcalIsoRel=0.
default_common.Photons.HcalIsoCut=99999.
default_common.Photons.HadOverEmCut=0.5
default_common.Photons.SigmaIetaIetaCut=0.5
#default_common.Photons.CaloIsoCut=0.2
default_common.Photons.IDReq=2
default_common.AlphaT.CalcWithEt=True
# -----------------------------------------------------------------------------


#Plot the common plots!
pset1 = PSet(
DirName      = "250_300Gev",
MinObjects   = 1,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset1 = PSet(
DirName      = "n250_300Gev",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset2 = PSet(
DirName      = "300_350Gev",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset2 = PSet(
DirName      = "n300_350Gev",
MinObjects   = 3,
MaxObjects   = 15,
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
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)

pset4 = PSet(
DirName      = "All",
MinObjects   = 2,
MaxObjects   = 2,
StandardPlots     = True,
)

Npset4 = PSet(
DirName      = "nAll",
MinObjects   = 3,
MaxObjects   = 15,
StandardPlots     = True,
)


dalitz_plots_Inclusive = HadronicPlottingOps( PSet(
DirName    = "Dalitz_Inclusive",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)

dalitz_plots_250_300 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_250_300",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)

dalitz_plots_300_350 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_300_350",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)

dalitz_plots_350 = HadronicPlottingOps( PSet(
DirName    = "Dalitz_350",
MinObjects = 2,
MaxObjects = 10,
Verbose    = False,
Summary    = False,
CC         = False,
Dalitz     = True,
AlphaT     = False,
PtHat      = False,
MET        = False,
Kine       = False,
Response   = False,
).ps()
)




HadStandard250_300 = HadronicCommonPlots(pset1.ps())
HadStandard300_350 = HadronicCommonPlots(pset2.ps())
HadStandard350 = HadronicCommonPlots(pset3.ps())
HadStandardAll = HadronicCommonPlots(pset4.ps())
nHadStandard250_300 = HadronicCommonPlots(Npset1.ps())
nHadStandard300_350 = HadronicCommonPlots(Npset2.ps())
nHadStandard350 = HadronicCommonPlots(Npset3.ps())
nHadStandardAll = HadronicCommonPlots(Npset4.ps())
# Common cut definitions
#Avaiable criteria for MC and for Data are at current slightly different Hence the making of two trees
#DataOnly!

from icf.JetCorrections import *
corPset =  CorrectionPset()
JetCorrections = JESCorrections( corPset.ps() )
NoiseFilt= OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()


JetTrigger = OP_TriggerCut("HLT_Jet50U")
#Standard Event Selection
LeadingJetEta = OP_FirstJetEta(2.5)
unCorLeadJetCut = OP_UnCorLeadJetCut(50.)
LeadingJetCut = OP_FirstJetPtCut(100.)
oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()
oddJet = OP_OddJet()
secondJetET = OP_SecondJetEtCut(80.)
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
LessThan300 = RECO_CommonHTLessThanCut(300.)
LessThan350 = RECO_CommonHTLessThanCut(350.)
htCut250 = RECO_CommonHTCut(250.)
htCut300 = RECO_CommonHTCut(300.)
htCut350 = RECO_CommonHTCut(350.)
alphaT0 = OP_CommonAlphaTCut(0.55)
alphaT1 = OP_CommonAlphaTCut(0.55)
spikecleaner = OP_EcalSpikeCleaner()
event_display = OP_EventDisplay("EventDisplays", "all") #to draw all/common objects
alphat = OP_CommonAlphaTCut(0.55)
DeadEcalCut =  OP_DeadECALCut(0.3)

# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

# AK5 Calo



from montecarlo.LMx import *
from montecarlo.WJets_Madgraph_NNLO import *
from montecarlo.TTBarTauola_NNLO import *
from montecarlo.Zjets_madgraph_NNLO import *
from montecarlo.Zinvisible_jets_pset_NNLO import *
from montecarlo.QCD_Pythia6_allBins import *
from montecarlo.QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *




from data.JetMET_Run2010A_PromptReco_v4_03092010 import *
from data.JetMET_Run2010A_PromptReco_v4_130810 import *
from data.JetMET_Run2010A_PromptReco_v4_200810 import *
from data.JetMET_Run2010A_PromptReco_v4_250810 import *
from data.JetMET_Run2010A_PromptReco_v4 import *
from data.JetMETTau_Run2010A_Jul16thReReco_v1 import *
from data.JetMETTau_Run2010A_Jun14thReReco_v2 import *
from data.JetMETTau_Run2010A_PromptReco_v4_04_08 import *
from data.JetMETTau_Run2010A_PromptReco_v4 import *

from montecarlo.QCD_Madgraph_50_100 import *
from montecarlo.QCD_Madgraph_100_250 import *
from montecarlo.QCD_Madgraph_250_500 import *
from montecarlo.QCD_Madgraph_500_1000 import *
from montecarlo.QCD_Madgraph_1000_inf import *




data=[JetMET_Run2010A_PromptReco_v4_03092010,JetMET_Run2010A_PromptReco_v4_130810,JetMET_Run2010A_PromptReco_v4_200810,JetMET_Run2010A_PromptReco_v4_250810,JetMET_Run2010A_PromptReco_v4,JetMETTau_Run2010A_Jul16thReReco_v1,JetMETTau_Run2010A_Jun14thReReco_v2,JetMETTau_Run2010A_PromptReco_v4_04_08,JetMETTau_Run2010A_PromptReco_v4]
MC=[LM0,LM1,QCD_Madgraph_1000_inf,QCD_Madgraph_500_1000,QCD_Madgraph_250_500,QCD_Madgraph_100_250,QCD_Madgraph_50_100,
#QCD_AllPtBins_7TeV_Pythia,
wjets_madgraph,zjets_madgraph,Zinvisible_jets,ttbarTauola,QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2]


cutTreeData = Tree("Data")
cutTreeData.Attach(NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,JetTrigger)
cutTreeData.TAttach(JetTrigger,unCorLeadJetCut)
cutTreeData.TAttach(unCorLeadJetCut,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,oddJet)
cutTreeData.TAttach(oddJet,badMuonINJet)
cutTreeData.TAttach(badMuonINJet,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,DeadEcalCut)
cutTreeData.TAttach(DeadEcalCut,secondJetET)




##########DiJet Studies
cutTreeData.TAttach(secondJetET,htCut250)
cutTreeData.TAttach(htCut250,dalitz_plots_Inclusive)
cutTreeData.TAttach(htCut250,DiJet3)
cutTreeData.TAttach(htCut250,alphat)
cutTreeData.TAttach(alphat,event_display)
cutTreeData.TAttach(DiJet3,HadStandardAll)
cutTreeData.TAttach(htCut250,NJet3)
cutTreeData.TAttach(NJet3,nHadStandardAll)
cutTreeData.TAttach(htCut250,LessThan300)
cutTreeData.TAttach(LessThan300,dalitz_plots_250_300)
cutTreeData.TAttach(LessThan300,DiJet0)
cutTreeData.TAttach(LessThan300,NJet0)
cutTreeData.TAttach(DiJet0,HadStandard250_300)
cutTreeData.TAttach(NJet0,nHadStandard250_300)

cutTreeData.TAttach(secondJetET,htCut300)
cutTreeData.TAttach(htCut300,LessThan350)
cutTreeData.TAttach(LessThan350,dalitz_plots_300_350)
cutTreeData.TAttach(LessThan350,DiJet1)
cutTreeData.TAttach(LessThan350,NJet1)
cutTreeData.TAttach(DiJet1,HadStandard300_350)
cutTreeData.TAttach(NJet1,nHadStandard300_350)

cutTreeData.TAttach(secondJetET,htCut350)
cutTreeData.TAttach(htCut350,dalitz_plots_350)
cutTreeData.TAttach(htCut350,DiJet2)
cutTreeData.TAttach(htCut350,NJet2)
cutTreeData.TAttach(DiJet2,alphaT0)
cutTreeData.TAttach(NJet2,alphaT1)
cutTreeData.TAttach(DiJet2,HadStandard350)
cutTreeData.TAttach(NJet2,nHadStandard350)




#Second MC!

cutTreeMC = Tree("MC")
cutTreeMC.Attach(selection)
cutTreeMC.TAttach(selection,unCorLeadJetCut)
cutTreeMC.TAttach(unCorLeadJetCut,oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,oddJet)
cutTreeMC.TAttach(oddJet,badMuonINJet)
cutTreeMC.TAttach(badMuonINJet,numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)
cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,DeadEcalCut)
cutTreeMC.TAttach(DeadEcalCut,secondJetET)

##########DiJet Studies
cutTreeMC.TAttach(secondJetET,htCut250)
cutTreeMC.TAttach(htCut250,dalitz_plots_Inclusive)
cutTreeMC.TAttach(htCut250,DiJet3)
cutTreeMC.TAttach(DiJet3,HadStandardAll)
cutTreeMC.TAttach(htCut250,NJet3)
cutTreeMC.TAttach(NJet3,nHadStandardAll)
cutTreeMC.TAttach(htCut250,LessThan300)
cutTreeMC.TAttach(LessThan300,dalitz_plots_250_300)
cutTreeMC.TAttach(LessThan300,DiJet0)
cutTreeMC.TAttach(LessThan300,NJet0)
cutTreeMC.TAttach(DiJet0,HadStandard250_300)
cutTreeMC.TAttach(NJet0,nHadStandard250_300)
cutTreeMC.TAttach(secondJetET,htCut300)
cutTreeMC.TAttach(htCut300,LessThan350)
cutTreeMC.TAttach(LessThan350,dalitz_plots_300_350)
cutTreeMC.TAttach(LessThan350,DiJet1)
cutTreeMC.TAttach(LessThan350,NJet1)
cutTreeMC.TAttach(DiJet1,HadStandard300_350)
cutTreeMC.TAttach(NJet1,nHadStandard300_350)
cutTreeMC.TAttach(secondJetET,htCut350)
cutTreeMC.TAttach(htCut350,dalitz_plots_350)
cutTreeMC.TAttach(htCut350,DiJet2)
cutTreeMC.TAttach(htCut350,NJet2)
cutTreeMC.TAttach(DiJet2,alphaT0)
cutTreeMC.TAttach(NJet2,alphaT1)
cutTreeMC.TAttach(DiJet2,HadStandard350)
cutTreeMC.TAttach(NJet2,nHadStandard350)



#######End of NJet Studies

def addCutFlowData(a) :
  a.AddJetFilter("PreCC",JetCorrections)
  a+=cutTreeData



JetSmear = JetSmear(0.1,30)
def addCutFlowMC(b) :
  b.AddJetFilter("PreCC",JetSmear)
  b+=cutTreeMC


# -----------------------------------------------------------------------------
# Definition of analyses
# Analyses

#AK5 Calo
conf_ak5_caloMC = deepcopy(defaultConfig)
conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
conf_ak5_caloMC.Common = deepcopy(default_common)
conf_ak5_caloMC.Common.print_out()
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


# AK5 PF

conf_ak5_pfData = deepcopy(defaultConfig)
conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfData.XCleaning = deepcopy(default_cc)
conf_ak5_pfData.Common = deepcopy(default_common)
anal_ak5_pfData=Analysis("AK5PF")
addCutFlowData(anal_ak5_pfData)

# AK5 PF

conf_ak5_pfMC = deepcopy(defaultConfig)
conf_ak5_pfMC.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfMC.XCleaning = deepcopy(default_cc)
conf_ak5_pfMC.Common = deepcopy(default_common)
anal_ak5_pfMC=Analysis("AK5PF")
addCutFlowMC(anal_ak5_pfMC)

# AK5 JPT

conf_ak5_jptData = deepcopy(defaultConfig)
conf_ak5_jptData.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jptData.XCleaning = deepcopy(default_cc)
conf_ak5_jptData.Common = deepcopy(default_common)
# conf_ak5_jDatapt.Common.print_out()
anal_ak5_jptData=Analysis("AK5JPT")
addCutFlowData(anal_ak5_jptData)

# AK5 JPT

conf_ak5_jptMC = deepcopy(defaultConfig)
conf_ak5_jptMC.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jptMC.XCleaning = deepcopy(default_cc)
conf_ak5_jptMC.Common = deepcopy(default_common)
# conf_ak5_jMCpt.Common.print_out()
anal_ak5_jptMC=Analysis("AK5JPT")
addCutFlowMC(anal_ak5_jptMC)


# AK7 Calo

conf_ak7_caloData = deepcopy(defaultConfig)
conf_ak7_caloData.Ntuple = deepcopy(ak7_calo)
conf_ak7_caloData.XCleaning = deepcopy(default_cc)
conf_ak7_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak7_caloData=Analysis("AK7Calo")
addCutFlowData(anal_ak7_caloData)



# AK7 Calo

conf_ak7_caloMC = deepcopy(defaultConfig)
conf_ak7_caloMC.Ntuple = deepcopy(ak7_calo)
conf_ak7_caloMC.XCleaning = deepcopy(default_cc)
conf_ak7_caloMC.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak7_caloMC=Analysis("AK7Calo")
addCutFlowData(anal_ak7_caloData)



# -----------------------------------------------------------------------------
# Run analyses
#IMPERIAL COLLEGE
anal_ak5_caloData.Run("../results/",conf_ak5_caloData,data)
# anal_ak5_pfData.Run("../results/",conf_ak5_pfData,data)
# anal_ak5_jptData.Run("../results/",conf_ak5_jptData,data)
# anal_ak7_caloData.Run("../results/",conf_ak7_caloData,data)


#anal_ak5_caloMC.Run("../results/",conf_ak5_caloMC,MC)
# anal_ak5_caloMC.Run("../results/",conf_ak5_caloMC,[QCD_AllPtBins_7TeV_Pythia])
# anal_ak5_pfMC.Run("../results/",conf_ak5_pfMC,MC)
# anal_ak5_jptMC.Run("../results/",conf_ak5_jptMC,MC)
# anal_ak7_caloMC.Run("../results/",conf_ak7_caloMC,MC)

