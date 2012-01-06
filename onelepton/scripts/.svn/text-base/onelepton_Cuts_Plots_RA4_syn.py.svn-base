import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
import libWPol as wpol
import libHadronic as had


from icf.core import PSet, Analysis, susyDir
from icf.utils import json_to_pset
#from onelepton_settings import *

from onelepton_dataRA4_sync_settings import *
from onelepton.filters import reweightVertices
from onelepton.utils import getDeadECALList

MuHad_May10ReReco_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_May10ReReco_v1_filteredEventsBE_cfi.py")
MuHad_May10ReReco_deadecal_ps._quiet_set("Accept", False)
MuHad_May10ReReco_Cut_BE = EventSelector(MuHad_May10ReReco_deadecal_ps.ps())

MuHad_May10ReReco_TP_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_May10ReReco_v1_filteredEventsTP_cfi.py")
MuHad_May10ReReco_TP_deadecal_ps._quiet_set("Accept", False)
MuHad_May10ReReco_Cut_TP = EventSelector(MuHad_May10ReReco_TP_deadecal_ps.ps())

MuHad_Prompt_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_PromptReco_v4_filteredEventsBE_cfi.py")
MuHad_Prompt_deadecal_ps._quiet_set("Accept", False)
MuHad_Prompt_Cut_BE = EventSelector(MuHad_May10ReReco_deadecal_ps.ps())

MuHad_Prompt_TP_deadecal_ps = getDeadECALList("../python/deadecal/MuHad_Run2011A_PromptReco_v4_filteredEventsTP_cfi.py")
MuHad_Prompt_TP_deadecal_ps._quiet_set("Accept", False)
MuHad_Prompt_Cut_TP = EventSelector(MuHad_May10ReReco_TP_deadecal_ps.ps())


ElHad_May10ReReco_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_May10ReReco_v1_missed4Jobs_filteredEventsBE_cfi.py")
ElHad_May10ReReco_deadecal_ps._quiet_set("Accept", False)
ElHad_May10ReReco_Cut_BE = EventSelector(ElHad_May10ReReco_deadecal_ps.ps())

ElHad_May10ReReco_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_May10ReReco_v1_missed4Jobs_filteredEventsTP_cfi.py")
ElHad_May10ReReco_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_May10ReReco_Cut_TP = EventSelector(ElHad_May10ReReco_TP_deadecal_ps.ps())

ElHad_Prompt_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_PromptReco_v4_missed1Job_filteredEventsBE_cfi.py")
ElHad_Prompt_deadecal_ps._quiet_set("Accept", False)
ElHad_Prompt_Cut_BE = EventSelector(ElHad_May10ReReco_deadecal_ps.ps())

ElHad_Prompt_TP_deadecal_ps = getDeadECALList("../python/deadecal/ElectronHad_Run2011A_PromptReco_v4_missed1Job_filteredEventsTP_cfi.py")
ElHad_Prompt_TP_deadecal_ps._quiet_set("Accept", False)
ElHad_Prompt_Cut_TP = EventSelector(ElHad_May10ReReco_TP_deadecal_ps.ps())


#Trigger
trg_set1 = PSet(
    Triggers = ["HLT_Mu5_HT200_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )
trg_set2 = PSet(
 #   Triggers = ["HLT_Mu8_HT200_v*","HLT_Mu15_HT200_v*","HLT_Mu20_HT200_v*","HLT_Mu30_HT200_v*","HLT_HT200_Mu5_PFMHT35_v*""HLT_HT*_Mu*_PFMHT*_v*"],
    Triggers = ["HLT_Mu*_HT*_v*","HLT_HT*_Mu*_PFMHT*_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )
trg_set4 = PSet(
#    Triggers = ["HLT_Mu15_v*","HLT_Mu20_v*","HLT_IsoMu17_v*"],
    Triggers = ["HLT_Mu15_HT200_v*", "HLT_Mu8_HT200_v*" ],
    Verbose = False,
    UsePreScaledTriggers = False
    )

#Electron triggers
etrg_set1 = PSet(
    Triggers = ["HLT_Ele10_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_HT200_v*",
                "HLT_Ele10_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_HT200_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )

#Electrons: PromptReco
etrg_set3 = PSet(
    Triggers = ["HLT_Ele32_CaloIdVL_CaloIsoVL_TrkIdVL_TrkIsoVL_v*",
                "HLT_Ele32_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )

## Triggers after May's Technical Stop
trg_set5 = PSet(
    Triggers = ["HLT_Mu8_HT250_v*","HLT_HT250_Mu5_PFMHT35_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )
#trg_set6 = PSet(
#    Triggers = ["HLT_Mu30_v*","HLT_Mu20_v*""HLT_IsoMu17_v*","HLT_IsoMu24_v*"],
#    Verbose = False,
#    UsePreScaledTriggers = False
#    )

# for sync
trg_set6 = PSet(
    Triggers = ["HLT_Mu15_HT200_v*","HLT_Mu8_HT200_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )

#Electron triggers
etrg_set2 = PSet(
    Triggers = ["HLT_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_HT250_v*",
                "HLT_Ele10_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_HT200_v*",
                "HLT_HT200_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v*",
                "HLT_HT250_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v*",
                "HLT_HT300_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT40_v*",
                "HLT_HT350_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT45_v*",
                "HLT_HT300_Ele5_CaloIdVL_CaloIsoVL_TrkIdVL_TrkIsoVL_PFMHT40_v*",
                "HLT_HT350_Ele5_CaloIdVL_CaloIsoVL_TrkIdVL_TrkIsoVL_PFMHT45_v*"
                ],
    Verbose = False,
    UsePreScaledTriggers = False
    )


json = JSONFilter("Cert_160404-165542",
                  json_to_pset("%s/onelepton/json/RA4muonSync.txt" % susyDir()))

triggerData4X = OP_MultiTrigger(trg_set2.ps())
triggerData4XCtrl = OP_MultiTrigger(trg_set4.ps())

triggerData42X_PromptReco = OP_MultiTrigger(trg_set5.ps())
triggerData42XCtrl_PromptReco = OP_MultiTrigger(trg_set6.ps())

triggerData42X_ReReco = OP_MultiTrigger(trg_set2.ps())
triggerData42XCtrl_ReReco = OP_MultiTrigger(trg_set4.ps())

etriggerData42X_ReReco = OP_MultiTrigger(etrg_set1.ps())
etriggerData42X_PromptReco = OP_MultiTrigger(etrg_set2.ps())

etriggerData42XCtrl_ReReco =  OP_TriggerCut("HLT_Ele27_CaloIdVT_CaloIsoT_TrkIdT_TrkIsoT_v3")
etriggerData42XCtrl_PromptReco = OP_MultiTrigger(etrg_set3.ps())

# lepton specific cuts
ZeroMu      = OP_NumComMuons("==",0)
OneMu       = OP_NumComMuons("==",1)
ZeroLooseMu = NumOfLooseMuons("==",0)
#OneLooseMu = NumOfLooseMuons("==",1)
ZeroEl      = OP_NumComElectrons("==",0)
OneEl       = OP_NumComElectrons("==",1)
#OneLooseEl  = NumOfLooseElectronsRA4("==",1,Els_Veto.ps())
ZeroLooseEl = NumOfLooseElectronsRA4("==",0,Els_Veto.ps())
AtLeastOneEl = OP_NumComElectrons(">=",1)

# lepton specific plots
mu_plots_cfg = PSet(
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Muon",
    AlphaT = True,
    PtHat = False,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True,
    usePrescale = False,
    Triggers = ["HLT_Mu3_v1"]
    )

el_plots_cfg = PSet(
    MinObjects   = 2,
    MaxObjects   = 10,
    StandardPlots  = True,
    doGen = False,
    LeptonType = "Electron",
    AlphaT = True,
    PtHat = False,
    MET = True,
    Summary = False,
    CC = False,
    Kine = True,
    Lep = True,
    usePrescale = False,
    Triggers = ["HLT_Mu3_v1"]
    )

ANplots = OP_ANplots("ANplots")

#cuts from framework folder
RECO_PFMHTCut100 = OP_mPFMHTCut(100.)
RECO_PFMHTCut150 = OP_mPFMHTCut(150.)
RECO_PFMHTCut200 = OP_mPFMHTCut(200.)

RECO_CommonHTCut500 = RECO_CommonHTCut(500.)
RECO_CommonHTCut250 = RECO_CommonHTCut(250.)
RECO_CommonHTCut200 = RECO_CommonHTCut(200.)
RECO_CommonHTCut300 = RECO_CommonHTCut(300.)

PFMuonCheck = OP_MuonCheck()

selection = OP_GoodEventSelection()
HBBEnoise = OP_HadronicHBHEnoiseFilter()
BeamHalo = OP_beamHaloCSCTightHaloId()
NoTracks = had.OP_SumVertexPtOverHT(0.1)
MonsterFilter = OP_MonsterFilter()

AtLeast4Jts = OP_NumComJets(">=",4)
AtLeast3Jts = OP_NumComJets(">=",3)
AtLeast3JtsPr = OP_NumComJets(">=",3)
AtLeast2Jts = OP_NumComJets(">=",2)
AtLeast1Jts = OP_NumComJets(">=",1)
LessThan4Jts = OP_NumComJets("<",4)
LessThan3Jts = OP_NumComJets("<",3)

SecondJetEtCut60 = OP_SecondJetEtCut(60.)
SecondJetEtCut100 = OP_SecondJetEtCut(100.)
# cuts from Oneleptonic folder

# cuts from WPol folder
PFMETCut100 = wpol.RECO_PFMETCut(100.0)
PFMETCut150 = OP_PFMETCutBin(150,-1)

ttType = OP_GenNumberLepCut(1)



myCountsAndBSMGrids_Init= CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_Init",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )


myCountsAndBSMGrids_0Eli= CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_0Eli",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )

myCountsAndBSMGrids_Clean = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_Clean",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )


myCountsAndBSMGrids_2jets = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_2jets",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )

myCountsAndBSMGrids_3jets = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_3jets",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )

myCountsAndBSMGrids_4jets = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_4jets",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )
myCountsAndBSMGrids_1mu = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_1mu",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )

myCountsAndBSMGrids_300HT = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_300HT",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )

myCountsAndBSMGrids_150PFMET = CountsAndBSMGrids(
    PSet(
    DirectoryName = "Counter_150PFMET",
    xBins = 100,
    xLow =0.,
    xHigh =1000.,
    yBins =100,
    yLow =0.,
    yHigh =1000.,
    mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
    ).ps()

    )


## AnalysisTree code inputs
mu_fillLightTree_cfg = PSet(
    LeptonType = "Muons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = False ## False for DATA, True for MC
    )
AnalysisTree_Mu = AnalysisTree_HighPt("MuonTree", mu_fillLightTree_cfg.ps())


el_fillLightTree_cfg = PSet(
    LeptonType = "Electrons",
    MinNumOfObjs = 2,
    MaxNumOfObjs = 10,
    GenInfo = False ## False for DATA, True for MC
    )
AnalysisTree_El = AnalysisTree_HighPt("ElectronTree", el_fillLightTree_cfg.ps())

SumLepPT125= OP_SumPTlepCut(125,100000.)

skim_ps=PSet(
    SkimName = "myskim",
    DropBranches = False,
    Branches = [
        " keep * "
        ]
)
skim = SkimOp(skim_ps.ps())


################################################################################
def makeBSMGrid(name):
    return CountsAndBSMGrids(
        PSet(
            DirectoryName = name,
            xBins = 100,
            xLow =0.,
            xHigh =1000.,
            yBins =100,
            yLow =0.,
            yHigh =1000.,
            mSUGRAFile = "scale_xsection_nlo0.5_tandat50.txt",#"msugraTanbeta3_05down.txt",
            ).ps()
        )

bsmgrid_no_cuts = makeBSMGrid("Counter_BSMGrid_NoCuts")
################################################################################
def setupMuonPreselection(MET, name, mode, less_than_3jets=False):
    a = Analysis(name)
    filters = []


    ## Add jet iD
  #  pfJetId = PFJetIDLoose()
  #  a.AddJetFilter("PreCC",pfJetId)
  #  filters += [pfJetId]

    # Add muon ID
    customMuID = CustomVBTFMuID(Mus.ps())
    a.AddMuonFilter("PreCC", customMuID)
    filters += [customMuID]

    # Muon-jet DR cut
    #    mu_jet_dr = MuonJetDRFilter(0.1, Mus.ps())
##    mu_jet_dr = MuonJetDRFilterRA4Sync(0.1, Mus.ps())
##    a.AddJetFilter("PreCC", mu_jet_dr)
##    filters += [mu_jet_dr]

    # Add electron ID
    #    eleID = LooseEleId()
    eleID = CustomEleIdRA4Sync(Els_Sig.ps())
    a.AddElectronFilter("PreCC", eleID)
    filters += [eleID]

    # Electron-jet DR cut
##    el_jet_dr = EleJetDRFilter(0.3)
##    #    el_jet_dr = EleJetDRFilterRA4Sync(0.3, Els_Sig.ps())
##    a.AddJetFilter("PreCC", el_jet_dr)
##    filters += [el_jet_dr]

    # this replaces typeI and uncorrected PFMET
    if MET == "typeI":
        met_typeI_filter = pfMETtopfMETtypeI()
        a.AddMETFilter("pfMET",met_typeI_filter)
        filters += [met_typeI_filter]


    # the residual JetCorrections are different from PF and Calo, so be careful
    # when adding them.
    if mode == "data39":
        JetCorrections = JESCorrections( corPset.ps() ,0)
        a.AddJetFilter("PreCC",JetCorrections)
        filters += [JetCorrections]
    # 311 MC needs to be reweighted accoring to vertex multiplicity
    # see onelepton/python/onelepton/filters.py
    if mode == "MC311" or mode == "MC42ttw_Z41" or mode == "MC42QCD" or mode == "MCskims":
        vert = reweightVertices(a)
        filters += [vert]


    # Create analysis cut tree
    tree = Tree("Main")
    a += tree

    # Here we define the data triggers depending on the analysis mode to add a
    # different trigger mix simply add an entry here and they will automatically
    # be added to the tree below

    # Control region
    if less_than_3jets:
        dataTriggers = {
            "data4X" : triggerData4XCtrl,
            "data42X_PromptReco" : triggerData42XCtrl_PromptReco,
            "data42X_ReReco" : triggerData42XCtrl_ReReco
            }
    # Signal region
    else:
        dataTriggers = {
            "data4X" : triggerData4X,
            "data42X_PromptReco" : triggerData42X_PromptReco,
            "data42X_ReReco" : triggerData42X_ReReco
            }

    if mode == "data39":
        a.Attach(triggerData)
        a.TAttach(triggerData, selection)
    elif mode in dataTriggers:
        tree.Attach(json)
#        tree.TAttach(json, skim)
#        tree.TAttach(skim,dataTriggers[mode])
        tree.Attach(json,myCountsAndBSMGrids_Init)
        tree.Attach(myCountsAndBSMGrids_InitdataTriggers[mode])
        tree.TAttach(dataTriggers[mode],HBBEnoise)
        tree.TAttach(HBBEnoise,BeamHalo)
        tree.TAttach(BeamHalo,NoTracks)
        tree.TAttach(NoTracks,MonsterFilter)
        tree.TAttach(MonsterFilter,selection)
        
    elif mode == "MCGrid":
        # Attach a BSM grid before any cuts have been applied so that we can
        # calculate signal efficiency for limit setting
        tree.Attach(bsmgrid_no_cuts)
        tree.TAttach(bsmgrid_no_cuts, selection)
    else:
        tree.Attach(selection)

#    tree.TAttach(selection,OneMu)
#    tree.TAttach(OneMu, ZeroLooseMu)
#    tree.TAttach(ZeroLooseMu,PFMuonCheck)
#    tree.TAttach(PFMuonCheck,RECO_CommonHTCut200)
#    tree.TAttach(RECO_CommonHTCut200,ZeroLooseEl)
#    tree.TAttach(ZeroLooseEl,ZeroEl)

    tree.TAttach(selection,MuHad_Prompt_Cut_BE)
    tree.TAttach(MuHad_Prompt_Cut_BE,MuHad_Prompt_Cut_TP)
    tree.TAttach(MuHad_Prompt_Cut_TP,triggerData4XCtrl)
    tree.TAttach(triggerData4XCtrl,myCountsAndBSMGrids_Clean)
    tree.TAttach(myCountsAndBSMGrids_Clean,AtLeast2Jts)
    tree.TAttach(AtLeast2Jts,myCountsAndBSMGrids_2jets)
    tree.TAttach(myCountsAndBSMGrids_2jets,AtLeast3Jts)
    tree.TAttach(AtLeast3Jts,myCountsAndBSMGrids_3jets)
    tree.TAttach(myCountsAndBSMGrids_3jets,AtLeast4Jts)
    tree.TAttach(AtLeast4Jts,OneMu)
    tree.TAttach(OneMu,myCountsAndBSMGrids_1mu)
    tree.TAttach(myCountsAndBSMGrids_1mu,ZeroEl)
    tree.TAttach(ZeroEl,myCountsAndBSMGrids_0Eli)
    tree.TAttach(myCountsAndBSMGrids_0Eli,ZeroLooseMu)
    tree.TAttach(ZeroLooseMu,ZeroLooseEl)
    tree.TAttach(ZeroLooseEl,RECO_CommonHTCut300)
    tree.TAttach(RECO_CommonHTCut300,myCountsAndBSMGrids_300HT)
    tree.TAttach(myCountsAndBSMGrids_300HT,PFMETCut150)
    tree.TAttach(PFMETCut150,myCountsAndBSMGrids_150PFMET)

    
#                 PFMuonCheck)
#    tree.TAttach(PFMuonCheck,RECO_CommonHTCut200)
#    tree.TAttach(RECO_CommonHTCut200,ZeroLooseEl)
#    tree.TAttach(ZeroLooseEl,ZeroEl)

    return (a, tree, filters)
################################################################################


def setupElectronPreselection(MET, name, mode, less_than_3jets=False, qcd_antiselection=False):
    a = Analysis(name)
    filters = []

    ## Add jet iD
    pfJetId = PFJetIDLoose()
    a.AddJetFilter("PreCC",pfJetId)
    filters += [pfJetId]

    # Add muon ID
    customMuID = CustomVBTFMuID(Mus.ps())
    a.AddMuonFilter("PreCC", customMuID)
    filters += [customMuID]

    # Muon-jet DR cut
    #    mu_jet_dr = MuonJetDRFilter(0.1, Mus.ps())
    mu_jet_dr = MuonJetDRFilterRA4Sync(0.1, Mus.ps())
    a.AddJetFilter("PreCC", mu_jet_dr)
    filters += [mu_jet_dr]


    # Add electron ID
    #    eleID = LooseEleId()
    if qcd_antiselection: eleID = CustomEleIdRA4Sync(Els_QCD.ps())
    else: eleID = CustomEleIdRA4Sync(Els_Sig.ps())
    a.AddElectronFilter("PreCC", eleID)
    filters += [eleID]

    # Electron-jet DR cut
    el_jet_dr = EleJetDRFilter(0.3)
    #    el_jet_dr = EleJetDRFilterRA4Sync(0.3, Els_Sig.ps())
    a.AddJetFilter("PreCC", el_jet_dr)
    filters += [el_jet_dr]


    # the residual JetCorrections are different from PF and Calo, so be careful
    # when adding them.
    if mode == "data39":
        JetCorrections = JESCorrections( corPset.ps() ,0)
        a.AddJetFilter("PreCC",JetCorrections)
        filters += [JetCorrections]
    # 311 MC needs to be reweighted accoring to vertex multiplicity
    # see onelepton/python/onelepton/filters.py
    if mode == "MC311":
        vert = reweightVertices(a)
        filters += [vert]


    # Create analysis cut tree
    tree = Tree("Main")
    a += tree

    # Here we define the data triggers depending on the analysis mode to add a
    # different trigger mix simply add an entry here and they will automatically
    # be added to the tree below

    # Control region : not yet ready for electrons
    if less_than_3jets:
        dataTriggers = {
            "data4X" : etriggerData42XCtrl_ReReco,
            "data42X_PromptReco" : etriggerData42XCtrl_PromptReco,
            "data42X_ReReco" : etriggerData42XCtrl_ReReco
            }
    # Signal region
    else:
        dataTriggers = {
            "data4X" : etriggerData42XCtrl_ReReco,
            "data42X_PromptReco" : etriggerData42X_PromptReco,
            "data42X_ReReco" : etriggerData42X_ReReco
            }

    if mode == "data39":
        a.Attach(triggerData)
        a.TAttach(triggerData, selection)
    elif mode in dataTriggers:
        tree.Attach(json)
        tree.TAttach(json, dataTriggers[mode])
        tree.TAttach(dataTriggers[mode],selection)
    elif mode == "MCGrid":
        # Attach a BSM grid before any cuts have been applied so that we can
        # calculate signal efficiency for limit setting
        tree.Attach(bsmgrid_no_cuts)
        tree.TAttach(bsmgrid_no_cuts, selection)
    else:
        tree.Attach(selection)

    # Add cut flow common to signal/control
    tree.TAttach(selection,HBBEnoise)
    tree.TAttach(HBBEnoise,BeamHalo)
    tree.TAttach(BeamHalo,NoTracks)
    tree.TAttach(NoTracks, OneEl)
    tree.TAttach(OneEl,ZeroLooseEl)
    tree.TAttach(ZeroLooseEl,ZeroLooseMu)
    tree.TAttach(ZeroLooseMu,ZeroMu)

    if less_than_3jets: # CONTROL REGION
        tree.TAttach(ZeroMu, AtLeast1Jts)
        tree.TAttach(AtLeast1Jts, LessThan3Jts)
    else: # SIGNAL REGION
        tree.TAttach(ZeroMu,SecondJetEtCut60)
        tree.TAttach(SecondJetEtCut60,RECO_CommonHTCut500)
 #       tree.TAttach(RECO_CommonHTCut500, AtLeast2Jts)
        if  mode == "data42X_ReReco":
            tree.TAttach(RECO_CommonHTCut500,ElHad_May10ReReco_Cut_BE)
            tree.TAttach(ElHad_May10ReReco_Cut_BE,ElHad_May10ReReco_Cut_TP)
            tree.TAttach(ElHad_May10ReReco_Cut_TP,AtLeast3Jts)
        elif  mode == "data42X_PromptReco":
            tree.TAttach(RECO_CommonHTCut500,ElHad_Prompt_Cut_BE)
            tree.TAttach(ElHad_Prompt_Cut_BE,ElHad_Prompt_Cut_TP)
            tree.TAttach(ElHad_Prompt_Cut_TP,AtLeast3Jts)
        else:
            tree.TAttach(RECO_CommonHTCut500, AtLeast3Jts)


    return (a, tree, filters)
################################################################################



def setupSignalBins(tree, hook, bins, mode="lp",
                    sig_cut_value=0.15, bg_cut_value=0.3, prefix=None):
    """ Setup a series of bins in the chosen scale variable

    tree : Tree object to attach cuts to
    hook : Starting cut to attach cut flow on to
    sig_cut_value : (LP) this is sets the upper bound on signal region
    bg_cut_value : (LP) lower bound on control region
    bins : list of lower bin boundaries for the scale variable
    prefix : string to prepend onto directory names (if you call this multiple times to avoid name conflicts)
    """
    # This function is called further down. See comment below.
    def buildTree(cut, region):
        bin_cuts = {}
        ops = []
        # Loop over bin ranges
        for idx, sbin in enumerate(bins):
            if mode == "lp":
                bin_name = "SumLepPT%d" %  sbin
                BinOpClass = OP_SumPTlepCut
            elif mode == "pfmet":
                bin_name = "PFMETCut%d" % sbin
                if region == "sig": BinOpClass = OP_PFMETCutBin
                elif region == "bkg": BinOpClass = OP_PTlepCut

            if prefix: bin_name = "%s_%s" % (prefix, bin_name)

            # Create operation to bin in Sumleppt, pfmet or leppt
            # depending on mode
            # Set range of bin to either (a, b) or (a, inf)
            if idx == len(bins)-1: # Last bin, range -> infinity
                bin_op = BinOpClass(sbin, -1)
                print "Adding bin %d -> inf" % sbin
            else: # Otherwise range goes to next bin
                print "Adding bin %d -> %d" % (sbin, bins[idx+1])
                bin_op = BinOpClass(sbin, bins[idx+1])

            # Name control bins appropriately
            if region == "bkg": bin_name += "_BKG"
            elif region == "nolp": bin_name += "_NOLP"

            # Counter op setup for BSM or SM counting histograms
            count_op = makeBSMGrid("Counter_BSMGrid_%s" % bin_name)

            # Store the bin op in case we want to attach stuff to it later
            bin_cuts[sbin] = bin_op
            # Attach the bin cut (i.e. pfmet or sumleppt)
            tree.TAttach(cut, bin_op)
            # Attach the counter op
            tree.TAttach(bin_op, count_op)
            # Save the operations we created
            ops.extend([bin_op, count_op])

        return (bin_cuts, ops)

    # Function starts HERE

    # Define the signal and control regions appropriately
    if mode == "lp":
        # For the LP cutflow, we first need to setup the signal/control region
        # in LP
        signal_cut = OP_PFLPCut(sig_cut_value)
        bg_cut = OP_PFLPCut(-bg_cut_value)
        tree.TAttach(hook, signal_cut)
        tree.TAttach(hook, bg_cut)
        # Then attach the bins in sumleppt
        (signal_bins, ops1) = buildTree(signal_cut, "sig")
        (control_bins, ops2) = buildTree(bg_cut, "bkg")
        (nolp_bins, ops3) = buildTree(hook, "nolp")
        return (signal_bins, control_bins, nolp_bins,
                ops1 + ops2 + ops3 + [signal_cut, bg_cut])

    elif mode == "pfmet":
        # For pfmet cut flow, simply attach the bins in pfmet
        # and sumleppt
        (signal_bins, ops1) = buildTree(hook, "sig")
        (control_bins, ops2) = buildTree(hook, "bkg")
        return (signal_bins, control_bins, None, ops1 + ops2)
################################################################################
def makePlots(tree, ops, PlotClass,plot_name, *plot_args):
    " Attach plots to the bins "
    plot_ops = []
    for bin_range, bin_op in ops.iteritems():
        print "Attaching %d" % bin_range
        plot_ops.append(PlotClass(plot_name % bin_range,
                                  *plot_args))
        tree.TAttach(bin_op, plot_ops[-1])
    return plot_ops

