#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
from icf.utils import json_to_pset
from copy import deepcopy
import commands
import math
pwd = commands.getoutput('echo $SUSY_WORKING_SW_DIR')

# -----------------------------------------------------------------------------
# Options

# 0=2010, 1=2011, 2=QCDpythia, 3=QCDmagdraph, 4=Wjets, 5=Zinv, 6=TTbar, 7=SingleTop, 8=LM1, 9=SMS, 10=DATAtest, 11==MCtest
DatasetOption = 1

UseGenJetsOption = False

NoCutFlow = False

UseMeffOption = False

Summer11Option = True

output_dir = pwd + "/results/v13/"

FilterOption = -1
OffsetOption = 0.

AlternativeTriggersOption = True

DataOption = False
if ( DatasetOption == 0 or DatasetOption == 1 or DatasetOption == 10 ) :
    DataOption = True
    
JsonOption = False
if ( DatasetOption == 1 ) :
    JsonOption = True
        
#JsonFileOption = "/allhadronic/python/allhadronic/ReProcessing_PromptJson_Merged_1fb.txt"
#JsonFileOption = "/hadronic/python/hadronic/ReProcessing_PromptJson_Merged.txt"
JsonFileOption = "/hadronic/python/hadronic/2011GoldenJson.json"

NoQcdOption = False
if ( DatasetOption == 2 or DatasetOption == 3 ) :
    NoQcdOption = True

VetoesOption = "NoOddMuon"
AddMuonOption = False
if ( UseGenJetsOption == True ) :
    VetoesOption = "NoVetoes"
if ( VetoesOption == "NoMuon" or VetoesOption == "NoVetoes" ) :
    AddMuonOption = True

vertex_reweight = VertexReweighting(
    PSet(
    #VertexWeights =[0.20, 0.63, 1.19, 1.57, 1.62, 1.42, 1.09, 0.80 ,0.57, 0.42, 0.30, 0.20] # Robin on ~150/pb
    #VertexWeights =[0.22, 0.74, 1.47, 1.91, 1.92, 1.56, 1.09, 0.71 ,0.44, 0.27, 0.17, 0.11] # Zoe from ~1.1/fb
    VertexWeights =[0.27, 0.93, 1.50, 1.67, 1.42, 1.10, 0.79, 0.53, 0.43, 0.37, 0.23, 0.31]#,0.33,0.36,0.37,0.08,1.00,1.00,1.00,1.00]
    ).ps())

VertexReweightingOption = [0.]
if ( False and DataOption == False ) :
    if ( DatasetOption == 2 ) :

#        if ( Summer11Option == True ) :
#            VertexWeights = [
#                1.00,0.17,0.56,1.04,1.29,1.25,1.20,1.11,1.00,0.89,1.00,1.08,1.00,1.78,2.87,3.79,10.88,13.91,83.81,1610.78,1.00,-1.00,
#                1.00,0.17,0.56,1.05,1.32,1.25,1.22,1.10,1.00,0.86,1.00,1.09,1.00,2.00,2.60,3.04,10.10,27.91,214.49,1.00,1.00,-1.00,
#                1.00,0.17,0.53,1.00,1.23,1.19,1.20,1.19,0.91,1.00,1.00,1.00,1.60,1.00,3.56,5.34,11.64,6.24,130.23,1.00,1.00,-1.00,
#                1.00,0.18,0.59,1.00,1.29,1.31,1.13,1.08,1.00,0.83,1.00,1.00,1.56,2.14,3.03,5.80,12.41,22.35,29.50,356.94,1.00,-1.00,
#                ]
#            
    
        VertexReweightingOption = [ # QCD Pythia
            #1.00,0.27,0.93,1.50,1.67,1.42,1.10,0.79,0.53,0.43,0.37,0.23,0.31,0.33,0.36,0.37,0.08,1.00,1.00,1.00,1.00,-1.00,
            1.00,0.27,0.92,1.52,1.67,1.44,1.11,0.78,0.53,0.43,0.35,0.20,0.31,0.33,0.39,0.32,0.01,0.00,1.00,1.00,1.00,-1.00,
            1.00,0.28,0.95,1.56,1.61,1.34,1.08,0.84,0.51,0.41,0.42,0.26,0.34,0.33,0.30,0.50,0.05,1.00,1.00,1.00,1.00,-1.00,
            1.00,0.27,0.91,1.39,1.74,1.46,1.09,0.76,0.55,0.44,0.36,0.30,0.30,0.31,0.38,0.44,1.00,1.00,1.00,1.00,1.00,-1.00,
            ]



    else :
        VertexReweightingOption = [ # QCD Madgraph
            #1.00,0.24,0.85,1.46,1.65,1.45,1.12,0.81,0.59,0.45,0.36,0.30,0.30,0.33,0.37,0.54,0.29,1.00,1.00,1.00,1.00,-1.00,
            1.00,0.24,0.86,1.46,1.65,1.46,1.12,0.82,0.59,0.45,0.35,0.30,0.30,0.31,0.42,0.50,0.06,0.00,1.00,1.00,1.00,-1.00,
            1.00,0.24,0.84,1.45,1.64,1.45,1.13,0.81,0.59,0.45,0.38,0.31,0.29,0.40,0.23,1.00,1.00,1.00,1.00,1.00,1.00,-1.00,
            1.00,0.24,0.84,1.47,1.65,1.45,1.13,0.81,0.59,0.45,0.36,0.30,0.33,0.34,0.44,0.53,0.51,1.00,1.00,1.00,1.00,-1.00,
            ]
    
TriggerEpochsOption = [0.]
SignalTriggersOption = [""]
MonitorTriggersOption = [""]

if ( False and DataOption == False ) :
    
    TriggerEpochsOption = [6.38,38.53,159.80,133.27,501.56,252.41]

if ( DataOption == True ) :

    if ( AlternativeTriggersOption == False ) :

        SignalTriggersOption = [
            # 275
            "HLT_HT250_AlphaT0p55_v1","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p53_v2","HLT_HT250_AlphaT0p53_v3",
            "HLT_HT250_AlphaT0p53_v4","HLT_HT250_AlphaT0p53_v5","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p58_v3",
            "HLT_HT250_AlphaT0p60_v3",
            "",
            ]
        
        MonitorTriggersOption = [
            #275
            "HLT_HT250_v2","HLT_HT250_v3","HLT_HT250_v4","HLT_HT250_v5",
            "HLT_HT250_v6","HLT_HT250_v7","HLT_HT250_v8","HLT_HT250_v11","",
            #325
            "HLT_HT300_v3","HLT_HT300_v4","HLT_HT300_v5","HLT_HT300_v6",
            "HLT_HT300_v7","HLT_HT300_v8","HLT_HT300_v9","HLT_HT300_v12","",
            #375
            "HLT_HT350_v2","HLT_HT350_v3","HLT_HT350_v4","HLT_HT350_v5",
            "HLT_HT350_v6","HLT_HT350_v7","HLT_HT350_v8","HLT_HT350_v11","",
            #475
            "HLT_HT400_v2","HLT_HT400_v3","HLT_HT400_v4","HLT_HT400_v5",
            "HLT_HT400_v6","HLT_HT400_v7","HLT_HT400_v8","HLT_HT400_v11","",
            #575
            "HLT_HT550_v2","HLT_HT550_v3","HLT_HT550_v4","HLT_HT550_v5",
            "HLT_HT550_v6","HLT_HT550_v7","HLT_HT550_v8","HLT_HT550_v11","",
            #675
            "HLT_HT550_v2","HLT_HT550_v3","HLT_HT550_v4","HLT_HT550_v5",
            "HLT_HT550_v6","HLT_HT550_v7","HLT_HT600_v1","HLT_HT600_v4","",
            #775
            "HLT_HT550_v2","HLT_HT550_v3","HLT_HT550_v4","HLT_HT550_v5",
            "HLT_HT550_v6","HLT_HT550_v7","HLT_HT600_v1","HLT_HT700_v2","",
            #875
            "HLT_HT550_v2","HLT_HT550_v3","HLT_HT550_v4","HLT_HT550_v5",
            "HLT_HT550_v6","HLT_HT550_v7","HLT_HT600_v1","HLT_HT750_v3","",
            ]

    else :

        SignalTriggersOption = [
            # 275
            "HLT_HT250_AlphaT0p55_v1","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p53_v2","HLT_HT250_AlphaT0p53_v3",
            "HLT_HT250_AlphaT0p53_v4","HLT_HT250_AlphaT0p53_v5","HLT_HT250_AlphaT0p55_v2","HLT_HT250_AlphaT0p58_v3",
            "HLT_HT250_AlphaT0p60_v3",
            "",
            # 325
            "HLT_HT300_AlphaT0p52_v1","HLT_HT300_AlphaT0p52_v2","HLT_HT300_AlphaT0p52_v3","HLT_HT300_AlphaT0p53_v3",
            "HLT_HT300_AlphaT0p53_v4","HLT_HT300_AlphaT0p53_v5","HLT_HT300_AlphaT0p53_v6","HLT_HT300_AlphaT0p54_v5",
            "HLT_HT300_AlphaT0p55_v3",
            "",
            # 375
            "HLT_HT350_AlphaT0p51_v1","HLT_HT350_AlphaT0p51_v2","HLT_HT350_AlphaT0p51_v3","HLT_HT350_AlphaT0p51_v4",
            "HLT_HT350_AlphaT0p51_v5","HLT_HT350_AlphaT0p52_v1","HLT_HT350_AlphaT0p52_v2","HLT_HT350_AlphaT0p53_v10",
            "",
            # 475
            "HLT_HT400_AlphaT0p51_v1","HLT_HT400_AlphaT0p51_v2","HLT_HT400_AlphaT0p51_v3","HLT_HT400_AlphaT0p51_v4",
            "HLT_HT400_AlphaT0p51_v5","HLT_HT400_AlphaT0p51_v6","HLT_HT400_AlphaT0p51_v7","HLT_HT400_AlphaT0p51_v10",
            "HLT_HT400_AlphaT0p52_v5",
            "",
            ]

        MonitorTriggersOption = [
            #275
            "HLT_HT250_v2","HLT_HT250_v3","HLT_HT250_v4","HLT_HT250_v5",
            "HLT_HT250_v6","HLT_HT250_v7","HLT_HT250_v8","HLT_HT250_v11","",
            #325
            "HLT_HT300_v3","HLT_HT300_v4","HLT_HT300_v5","HLT_HT300_v6",
            "HLT_HT300_v7","HLT_HT300_v8","HLT_HT300_v9","HLT_HT300_v12","",
            #375
            "HLT_HT350_v2","HLT_HT350_v3","HLT_HT350_v4","HLT_HT350_v5",
            "HLT_HT350_v6","HLT_HT350_v7","HLT_HT350_v8","HLT_HT350_v11","",
            #475
            "HLT_HT400_v2","HLT_HT400_v3","HLT_HT400_v4","HLT_HT400_v5",
            "HLT_HT400_v6","HLT_HT400_v7","HLT_HT400_v8","HLT_HT400_v11","",
            #575
            "HLT_HT400_v2","HLT_HT400_v3","HLT_HT400_v4","HLT_HT400_v5",
            "HLT_HT400_v6","HLT_HT400_v7","HLT_HT400_v8","HLT_HT400_v11","",
            #675
            "HLT_HT400_v2","HLT_HT400_v3","HLT_HT400_v4","HLT_HT400_v5",
            "HLT_HT400_v6","HLT_HT400_v7","HLT_HT400_v8","HLT_HT400_v11","",
            #775
            "HLT_HT400_v2","HLT_HT400_v3","HLT_HT400_v4","HLT_HT400_v5",
            "HLT_HT400_v6","HLT_HT400_v7","HLT_HT400_v8","HLT_HT400_v11","",
            #875
            "HLT_HT400_v2","HLT_HT400_v3","HLT_HT400_v4","HLT_HT400_v5",
            "HLT_HT400_v6","HLT_HT400_v7","HLT_HT400_v8","HLT_HT400_v11","",
            ]

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

default_ntuple.Photons=PSet(
Prefix="photon",
Suffix="Pat",
)

default_ntuple.Jets=PSet(
Prefix="ic5Jet",
Suffix="Pat",
Uncorrected=False,
)

default_ntuple.SecJets=PSet(
    Prefix="",
    Suffix="",
    Uncorrected=False,
    )

default_ntuple.TerJets=PSet(
    Prefix="",
    Suffix="",
    Uncorrected=False,
    )

ak5_calo = deepcopy(default_ntuple)
if (UseGenJetsOption) :
    ak5_calo.Jets.Prefix="ak7"
    ak5_calo.Jets.Suffix=""
    ak5_calo.Jets.UseGenJets=True
else :
    ak5_calo.Jets.Prefix="ak5Jet"
    
# -----------------------------------------------------------------------------
# Cross-cleaning settings

default_cc = deepcopy(defaultConfig.XCleaning)
default_cc.Verbose=False

if ( UseGenJetsOption == True ) : 
    default_cc.MuonJet=False
    default_cc.ElectronJet=False
    default_cc.PhotonJet=False
    default_cc.ResolveConflicts=False
else :
    default_cc.MuonJet=True
    default_cc.ElectronJet=True
    default_cc.PhotonJet=True
    default_cc.ResolveConflicts=True

default_cc.Jets.PtCut=10.0
default_cc.Jets.EtaCut=10.0

default_cc.Muons.ModifyJetEnergy=True
default_cc.Muons.PtCut=10.0
default_cc.Muons.EtaCut=2.5
default_cc.Muons.TrkIsoCut=-1.
default_cc.Muons.CombIsoCut=0.15
default_cc.Muons.MuonJetDeltaR=0.5
default_cc.Muons.MuonIsoTypePtCutoff=0.
default_cc.Muons.RequireLooseIdForInitialFilter=False

default_cc.Electrons.PtCut=10.0
default_cc.Electrons.EtaCut=2.5
default_cc.Electrons.TrkIsoCut=-1.0
default_cc.Electrons.CombIsoCut=0.15
default_cc.Electrons.ElectronJetDeltaR=0.5
default_cc.Electrons.ElectronIsoTypePtCutoff=0.   
default_cc.Electrons.ElectronLooseIdRequired=True
default_cc.Electrons.ElectronTightIdRequired=False
default_cc.Electrons.RequireLooseIdForInitialFilter=False

default_cc.Photons.EtCut=25.0
default_cc.Photons.EtaCut=2.5
default_cc.Photons.TrkIsoCut=2.0
default_cc.Photons.CaloIsoCut=0.2
default_cc.Photons.IDReq=3
default_cc.Photons.PhotonJetDeltaR=0.5
default_cc.Photons.PhotonIsoTypePtCutoff=30.

# -----------------------------------------------------------------------------
# Definition of common objects

default_common = deepcopy(defaultConfig.Common)

if ( NoCutFlow == True or UseGenJetsOption == True ) : 
    default_common.ApplyXCleaning=False
else :
    default_common.ApplyXCleaning=True

default_common.Jets.PtCut=10.0
default_common.Jets.EtaCut=3.0
default_common.Jets.ApplyID=True
default_common.Jets.TightID=False

if ( UseGenJetsOption == True ) : 
    default_common.Jets.PtCut=5.0

default_common.Electrons.PtCut=10.0
default_common.Electrons.EtaCut=2.5
default_common.Electrons.TrkIsoCut=-1.
default_common.Electrons.CombIsoCut=0.15
default_common.Electrons.ApplyID = True
default_common.Electrons.TightID = False
default_common.Electrons.RequireLooseForOdd = True

default_common.Muons.PtCut=10.0
default_common.Muons.EtaCut=2.5
default_common.Muons.TrkIsoCut=-1.
default_common.Muons.CombIsoCut=0.15
default_common.Muons.ApplyID = True
default_common.Muons.TightID = True
default_common.Muons.RequireLooseForOdd = True

default_common.Photons.EtCut=25.0
default_common.Photons.EtaCut=2.5
default_common.Photons.IDReq = 3
default_common.Photons.RequireLooseForOdd = True

# -----------------------------------------------------------------------------

# Common configurations

conf_ak5_calo = deepcopy(defaultConfig)
conf_ak5_calo.Ntuple = deepcopy(ak5_calo)
conf_ak5_calo.XCleaning = deepcopy(default_cc)
#conf_ak5_calo.Common.print_out()
conf_ak5_calo.Common = deepcopy(default_common)

# -----------------------------------------------------------------------------
# Common cut definitions

from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.ra3PhotonId_cff import *

vbtf_muon = Muon_IDFilter( vbtfmuonidps.ps() )
vbtf_electron = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3_photon = Photon_IDFilter( ra3photonidps.ps() )

from icf.JetCorrections import *
corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt")
JetCorrections = JESCorrections( corPset.ps(), True )

NoiseFilt = OP_HadronicHBHEnoiseFilter()
selection = OP_GoodEventSelection()
selection_duplicate = OP_GoodEventSelection()

oddMuon = OP_OddMuon()
oddElectron = OP_OddElectron()
oddPhoton = OP_OddPhoton()

numComElectrons = OP_NumComElectrons("<=",0)
numComMuons = OP_NumComMuons("<=",0)
numComPhotons = OP_NumComPhotons("<=",0)

DeadEcalFileOption = pwd+"/hadronic/python/deadRegionList_START38_V12.txt"
CutFlowOption="MC"
if ( DataOption ) :
    pwd+"/hadronic/python/deadRegionList_GR10_P_V10.txt"
    CutFlowOption="Data"

HtBinOption = 0
HtBinningOptions = []
if ( True ) :
    alphat = 0.55
    factor = math.sqrt(1.-(1./(4.*alphat*alphat)))
    if ( UseMeffOption == False ) :
        HtBinOption = 2
        #HtBinningOptions = [275.,325.,375.,425.,475.,525.,575.,625.,675.,725.,775.,825.,875.,925.,975.,]
        HtBinningOptions = [275.,325.,375.,475.,575.,675.,775.,875.,975.,]
        #HtBinningOptions = [270.,360.,450.,540.,630.,720.,810.,900.,990.,]
        #HtBinningOptions = [300.,400.,500.,600.,700.,800.,900.,1000.,1100.,]
    else :
        HtBinOption = 2
        #HtBinningOptions = [400.,450.,500.,600.,700.,800.,900.,1000.,1100.,]
        #HtBinningOptions = [275.*1.4,325.*1.4,375.*1.4,475.*1.4,575.*1.4,675.*1.4,775.*1.4,875.*1.4,975.*1.4,]
        #HtBinningOptions = [350.*1.4,400.*1.4,500.*1.4,600.*1.4,700.*1.4,800.*1.4,900.*1.4,1000.*1.4,1100.*1.4,]
        #HtBinningOptions = [300.*1.4,400.*1.4,500.*1.4,600.*1.4,700.*1.4,800.*1.4,900.*1.4,1000.*1.4,1100.*1.4,]
        HtBinningOptions = [300.,400.,500.,600.,700.,800.,900.,1000.,1100.,]
        #HtBinningOptions = [400.,450.,500.,550.,600.,650.,700.,750.,800.,]
else :
    for n in range(0,31) :
        HtBinOption = 5
        HtBinningOptions.append(250+20.*n)

qcdBkgdEst = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                              # Triggers
                              TriggerEpochs = TriggerEpochsOption,
                              SignalTriggers = SignalTriggersOption,
                              MonitorTriggers = MonitorTriggersOption,
                              PrescaledSignalTriggers = False,
                              VertexReweighting = VertexReweightingOption,
                              # Miscellaneous
                              Verbose=False,
                              Filter=FilterOption,
                              NoQCD=NoQcdOption,
                              MaxLeadingJetEta=2.5,
                              AddMuon=AddMuonOption,
                              OnlyGenPtHat=False,
                              OnlyFull=True,
                              # Histogramming
                              MinObjects=2,
                              MaxObjects=4,
                              HtHistos=False,
                              MeffHistos=False,
                              MhtHistos=False,
                              MhtOverHtHistos=False,
                              MhtOverMeffHistos=False,
                              MultiplicityHistos=False,
                              JetPtHistos=False,
                              NumVertexHistos=False,
                              BabyJetsHistos=False,
                              BabyJetsMhtHistos=False,
                              MinBiasDPhiHistos=False,
                              CutFlowHistos=False,
                              AlphaTHistos=False,
                              DalitzHistos=False,
                              # Baby jets cleaning
                              NoCleaningInDenom=True,
                              BabyJetsCut=1.25,
                              # Dead ECAL cleaning
                              DeadEcalRegionDrCut=0.3,
                              DeadEcalRegionEtaCut=0.3,
                              MinBiasDeltaPhiCut=0.5,
                              MinJetPtCut=30.,
                              NBadCells=10,
                              UseDeadEcalFile=False,
                              DeadEcalFile=DeadEcalFileOption,
                              # RecHit cleaning
                              SumRecHitPtCut = 30.,
                              # Binning
                              AlphaTDefault=0,
                              AlphaT=[0.55,
                                      #0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.60,0.65,0.7,
                                      #0.51,0.52,
                                      #0.53,0.531,0.532,0.533,0.534,0.535,0.536,0.537,0.538,0.539,
                                      #0.54,0.541,0.542,0.543,0.544,0.545,0.546,0.547,0.548,0.549,
                                      #0.55,0.551,0.552,0.553,0.554,0.555,0.556,0.557,0.558,0.559,
                                      #0.56,0.561,0.562,0.563,0.564,0.565,0.566,0.567,0.568,0.569,
                                      #0.57,0.571,0.572,0.573,0.574,0.575,0.576,0.577,0.578,0.579,
                                      #0.58,0.581,0.582,0.583,0.584,0.585,0.586,0.587,0.588,0.589,
                                      #0.59,0.60
                                      ],
                              Inclusive=False,
                              HtBinning=HtBinningOptions,
                              HtNbins=len(HtBinningOptions)-1,
                              HtXlow=HtBinningOptions[0],
                              HtXhigh=HtBinningOptions[len(HtBinningOptions)-1],
                              HtOffset=0.,
                              # Thresholds and scaling
                              UseMeff=UseMeffOption,
                              MinJetPt1=100.,
                              MinJetPt2=100.,
                              MinJetPt3=50.,
                              HtBin=HtBinOption,
                              Scale=True,
                              ScaleInSignalRegion=False,
                              ScaleSingleJetThreshold=True,
                              ).ps() )

# -----------------------------------------------------------------------------
# Cut flow

cut_flow = Tree(CutFlowOption)

if ( NoCutFlow == True ) : 

    cut_flow.Attach(qcdBkgdEst)

else :

    if ( JsonOption ) : # Use JSON
        json = JSONFilter("JSON", json_to_pset(pwd+JsonFileOption))
        json_output = JSONOutput("_filtered")
        cut_flow.Attach(json)
        cut_flow.TAttach(json,json_output)
        cut_flow.TAttach(json,selection)
    else :
        cut_flow.Attach(selection)
   
    if ( DataOption ) : # Data only
        cut_flow.TAttach(selection,NoiseFilt)
        cut_flow.TAttach(NoiseFilt,selection_duplicate)
    else:
        cut_flow.TAttach(selection,selection_duplicate)

    mht_cut = OP_TriggerMHT_Emu(60.,30.)

    if ( VetoesOption == "AllVetoes" ) :
        cut_flow.TAttach(selection_duplicate,numComPhotons)
        cut_flow.TAttach(numComPhotons,oddPhoton)
        cut_flow.TAttach(oddPhoton,numComElectrons)
        cut_flow.TAttach(numComElectrons,oddElectron)
        cut_flow.TAttach(oddElectron,numComMuons)
        cut_flow.TAttach(numComMuons,oddMuon)
        cut_flow.TAttach(oddMuon,qcdBkgdEst)
        #    if (False) :
        #        cut_flow.TAttach(oddMuon,mht_cut)
        #        cut_flow.TAttach(mht_cut,qcdBkgdEst)
        #    else :
        #        cut_flow.TAttach(oddMuon,qcdBkgdEst)
    elif ( VetoesOption == "NoMuon" ) :
        cut_flow.TAttach(selection_duplicate,numComPhotons)
        cut_flow.TAttach(numComPhotons,oddPhoton)
        cut_flow.TAttach(oddPhoton,numComElectrons)
        cut_flow.TAttach(numComElectrons,oddElectron)
        cut_flow.TAttach(oddElectron,qcdBkgdEst)
    elif ( VetoesOption == "NoOddMuon" ) :
        cut_flow.TAttach(selection_duplicate,numComPhotons)
        cut_flow.TAttach(numComPhotons,oddPhoton)
        cut_flow.TAttach(oddPhoton,numComElectrons)
        cut_flow.TAttach(numComElectrons,oddElectron)
        cut_flow.TAttach(oddElectron,numComMuons)
        cut_flow.TAttach(numComMuons,qcdBkgdEst)
    elif ( VetoesOption == "NoElectron" ) :
        cut_flow.TAttach(selection_duplicate,numComPhotons)
        cut_flow.TAttach(numComPhotons,oddPhoton)
        cut_flow.TAttach(oddPhoton,numComMuons)
        cut_flow.TAttach(numComMuons,oddMuon)
        cut_flow.TAttach(oddMuon,qcdBkgdEst)
    elif ( VetoesOption == "NoPhoton" ) :
        cut_flow.TAttach(selection_duplicate,numComElectrons)
        cut_flow.TAttach(numComElectrons,oddElectron)
        cut_flow.TAttach(oddElectron,numComMuons)
        cut_flow.TAttach(numComMuons,oddMuon)
        cut_flow.TAttach(oddMuon,qcdBkgdEst)
    elif ( VetoesOption == "NoEGamma" ) :
        cut_flow.TAttach(selection_duplicate,numComMuons)
        cut_flow.TAttach(numComMuons,oddMuon)
        cut_flow.TAttach(oddMuon,qcdBkgdEst)
    elif ( VetoesOption == "NoVetoes" ) :
        cut_flow.TAttach(selection_duplicate,qcdBkgdEst)
    elif ( VetoesOption == "NoOddVetoes" ) :
        cut_flow.TAttach(selection_duplicate,numComPhotons)
        cut_flow.TAttach(numComPhotons,numComElectrons)
        cut_flow.TAttach(numComElectrons,numComMuons)
        cut_flow.TAttach(numComMuons,qcdBkgdEst)

    if ( True and FilterOption > -1 ) :
        skim_ps = PSet(
            SkimName = "Skim",
            Branches = ["keep *"],
            DropBranches = False,
            )
        skim = SkimOp( skim_ps.ps() )
        cut_flow.TAttach(qcdBkgdEst,skim)
    
# -----------------------------------------------------------------------------
# dataset 

Darren=PSet(
    Name="Darren",
    Format=("ICF",3),
    File=[
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1000_2_5ze.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1001_2_QRR.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1002_2_56x.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1003_2_Z7B.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1004_2_jeP.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1005_2_ObZ.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1006_2_JqJ.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1007_2_BoI.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1008_2_r2q.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1009_2_8as.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_100_1_9gW.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1010_2_25j.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1011_2_wl5.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1012_2_tdy.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1013_2_XyE.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1014_2_ktn.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning/ICF/automated/2011_11_11_14_03_49/HT.Run2011A-May10ReReco-v1.AOD/SusyCAF_Tree_1015_2_R95.root" ,
    ],
    Weight=1.0,
    #FirstEntry = 1,
    #LastEntry = 1000,
    )

data2011=PSet(
    Name="Data",
    Format=("ICF",3),
    File= [
    "file:/home/hep/db1110/public_html/275_Had_Data.root",
    #"file:/home/hep/elaird1/73_candidates/v8/375.root",
    #"/Users/bainbrid/Desktop/work/data/HT_Run2011_promptReco_DCS.root",
    #"root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning//ICF/automated/2011_04_13_17_17_19///SusyCAF_Tree_9_1_zCe.root" ,
    #"file:./skim.root" ,
    #"file:/vols/cms02/bainbrid/qcd/trigger/SUSY2/results/v23/Ratio_HT42_incomplete.root",
    ],
    Weight=1.,
    #FirstEntry = 1,
    #LastEntry = 10,
    )

path2010="/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/"
data2010 = PSet(
    Name = 'JetMET_Run2010A_PromptReco',
    Format = ('ICF',2),
    File = [
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_0_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_1_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_2_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_3_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_4_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_5_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_6_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_7_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_8_skim.root",
    path2010+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_9_skim.root",
    ],
    Weight=1.0,
    FirstEntry = 1,
    LastEntry = 10,
    )

candidates=PSet(
    Name="Candidates",
    Format=("ICF",3),
    File= [
    #"/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1.root",
    "/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-7bins.root",
    ],
    Weight=1.,
    )

test_lm=PSet(
    Name="LM1",
    Format=("ICF",3),
    File=[
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning//ICF/automated/2011_04_12_14_13_06//LM1_SUSY_sftsht_7TeV-pythia6.Spring11-PU_S1_START311_V1G1-v1.AODSIM//SusyCAF_Tree_10_1_ICZ.root" ,
    ],
    CrossSection=4.888,
    Events = 219190,
    FirstEntry = 1,
    #LastEntry = 10000,
    )

test_qcdpy=PSet(
    Name="QCDPY",
    Format=("ICF",3),
    File=[
#    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-120to170_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_0_DHE.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-170to300_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_0_osA.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-300to470_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_101_4_dG3.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-470to600_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_1_2IT.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-600to800_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_1_gJa.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-800to1000_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_1_Iou.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-1000to1400_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_0_Nz0.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-1400to1800_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_100_1_jXG.root" ,
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar/ICF/automated/2011_06_12_05_20_30/QCD_Pt-1800_TuneZ2_7TeV_pythia6.Summer11-PU_S3_START42_V11-v2.AODSIM/SusyCAF_Tree_10_1_n6q.root" ,
    ],
    Weight=1.,
    FirstEntry=1,
    LastEntry=1000,
    )

test_qcdmg=PSet(
    Name="QCDMG",
    Format=("ICF",3),
    File=[
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_20_30_16//QCD_TuneD6T_HT-100To250_7TeV-madgraph.Spring11-PU_S1_START311_V1G1-v1.AODSIM/SusyCAF_Tree_100_1_mfS.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_20_30_16//QCD_TuneD6T_HT-250To500_7TeV-madgraph.Spring11-PU_S1_START311_V1G1-v1.AODSIM/SusyCAF_Tree_100_1_how.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_20_30_16//QCD_TuneD6T_HT-500To1000_7TeV-madgraph.Spring11-PU_S1_START311_V1G1-v1.AODSIM//SusyCAF_Tree_100_1_wjO.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_20_30_16//QCD_TuneD6T_HT-1000_7TeV-madgraph.Spring11-PU_S1_START311_V1G1-v1.AODSIM//SusyCAF_Tree_9_1_OBL.root",
    ],
    Weight=1.,
    FirstEntry=1,
    #LastEntry=1000,
    )

test_sms=PSet(
    Name="SMS",
    Format=("ICF",3),
    File=[
    #"root://xrootd.grid.hep.ph.ic.ac.uk/store/user/dburton/ICF/T1datasettest/100.0_50.0To425.0_250.0.lhe_270000.root"
    "file:./sms.root",
    ],
    Weight=1.,
    #FirstEntry = 1,
    #LastEntry = 100,
    )

# MC samples
if ( Summer11Option == True ) :
    from allhadronic.Summer11 import *
else :
    from allhadronic.Spring11 import *

from data.Jet_35pb_WithTP_json051110 import Jet_35pb_WithTP_json051110
from data.Run2011.HT42_incomplete import HT42_incomplete
from data.Run2011.HT_Run2011_promptReco_DCS import HT_Run2011_promptReco_DCS
from data.Run2011.HT_Run2011A import HT_Run2011A
from data.Run2011.HT_Run2011A_PromptReco_v1 import HT_Run2011A_PromptReco_v1
from data.Run2011.HT_Run2011A_L1OffSet import HT_Run2011A_L1OffSet
from data.Run2011.HT_Run2011AB import HT_Run2011AB
from allhadronic.HT_Run2011A_1fb import HT_Run2011A_1fb

# -----------------------------------------------------------------------------
# Analysis

anal=Analysis("Ratio")
#if ( not DataOption ) :
#    anal.AddWeightFilter("Weight", vertex_reweight)
anal.AddMuonFilter("PreCC",vbtf_muon)
anal.AddElectronFilter("PreCC",vbtf_electron)
anal.AddPhotonFilter("PreCC",ra3_photon)
#anal.AddJetFilter("PreCC",JetCorrections)
 
anal+=cut_flow

dataset = []
if   ( DatasetOption == 0 ) : 
    dataset = [Jet_35pb_WithTP_json051110]
elif ( DatasetOption == 1 ) : 
    dataset = [HT_Run2011AB] # ~7930 files (and growing)
elif ( DatasetOption == 2 ) : 
    dataset = qcdpy600
elif ( DatasetOption == 3 ) : 
    dataset = qcdmg
elif ( DatasetOption == 4 ) :
    dataset = wjets
elif ( DatasetOption == 5 ) :
    dataset = zinv
elif ( DatasetOption == 6 ) :
    dataset = ttbar
elif ( DatasetOption == 7 ) :
    dataset = top
elif ( DatasetOption == 8 ) :
    dataset = [LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1,
               LM4_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1,
               LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1
               ]
elif ( DatasetOption == 10 ) : 
    dataset = [data2011]
    #dataset = [Darren]
elif ( DatasetOption == 11 ) :
    #dataset = [test_lm]
    dataset = [test_qcdpy]
    #dataset = [test_sms]

if ( DatasetOption != 10 and DatasetOption != 11 ) :
    anal.Run(output_dir,conf_ak5_calo,dataset) 
else :
    anal.Run(".",conf_ak5_calo,dataset)



