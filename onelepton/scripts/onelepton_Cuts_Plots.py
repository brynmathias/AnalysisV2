import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
import libWPol as wpol
import libHadronic as had
from icf.core import PSet, Analysis, susyDir
from icf.utils import json_to_pset
from onelepton_settings import *
from onelepton.filters import reweightVertices
import SUSYSignalScan.utils as susy_utils
from onelepton_TP_and_BE_data_filters import *
from onelepton_CutCounters import *

#Trigger
trg_set1 = PSet(
    Triggers = ["HLT_Mu5_HT200_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )
trg_set2 = PSet(
    Triggers = ["HLT_Mu8_HT200_v*","HLT_HT200_Mu5_PFMHT35_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )
trg_set4 = PSet(
    Triggers = ["HLT_Mu15_v*","HLT_Mu20_v*","HLT_IsoMu17_v*"],
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
    Triggers = ["HLT_Mu8_HT250_v*", #1e33
                "HLT_Mu15_HT200_v*",
                "HLT_Mu30_HT200_v*", #2e33
                "HLT_Mu40_HT200_v*", #3e33
                "HLT_HT250_Mu5_PFMHT35_v*", #1e33
                "HLT_HT250_Mu15_PFMHT20_v*", #2e33
                "HLT_HT250_Mu15_PFMHT40_v*", #3e33
#                "HLT_HT300_Mu5_PFMHT40_v*", #2e33
#                "HLT_HT350_Mu5_PFMHT45_v*" #2e33
                ],
    Verbose = False,
    UsePreScaledTriggers = False
    )
trg_set6 = PSet(
    Triggers = ["HLT_Mu30_v*","HLT_Mu20_v*","HLT_IsoMu17_v*","HLT_IsoMu24_v*"],
    Verbose = False,
    UsePreScaledTriggers = False
    )

trg_setSynch = PSet(
    Triggers = ["HLT_Mu15_HT200_v*", #1e33
                "HLT_HT250_Mu15_PFMHT20_v*",
                "HLT_HT250_Mu15_PFMHT40_v*", #2e33
                "HLT_HT300_Mu15_PFMHT40_v*", #1e33
          ##      "HLT_Mu8_HT200_v*", #2e33
               # "HLT_HT250_Mu15_PFMHT40_v*", #
#                "HLT_HT300_Mu5_PFMHT40_v*", #2e33
#                "HLT_HT350_Mu5_PFMHT45_v*" #2e33
                ],
    Verbose = False,
    UsePreScaledTriggers = False
    )

trg_setSynchMC = PSet(
    Triggers = ["HLT_Mu8_v1"               
                ],
    Verbose = False,
    UsePreScaledTriggers = False
    )

#Electron triggers
etrg_set2 = PSet(
    Triggers = ["HLT_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_HT250_v*",
                "HLT_Ele10_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_HT200_v*",
                "HLT_Ele25_CaloIdT_TrkIdT_HT350_v*",
                "HLT_Ele15_CaloIdT_CaloIsoVL_TrkIdT_TrkIsoVL_HT250_PFMHT25_v*", #3e33
                "HLT_HT350_Ele30_CaloIdT_TrkIdT_v*" #3e33
                ],
    Verbose = False,
    UsePreScaledTriggers = False
    )

json = JSONFilter("Cert_160404-165542",
                  json_to_pset("%s/onelepton/json/Json_Latest.txt" % susyDir()))

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

triggerSyncMuHad = OP_MultiTrigger(trg_setSynch.ps())

# lepton specific cuts
ZeroMu      = OP_NumComMuons("==",0)
OneMu       = OP_NumComMuons("==",1)
ZeroLooseMu = NumOfLooseMuonsRA4("==",0)
ZeroEl      = OP_NumComElectrons("==",0)
OneEl       = OP_NumComElectrons("==",1)
ZeroLooseEl = NumOfLooseElectronsRA4("==",0,Els_Veto.ps())

# additional potential cuts
DphiPTW_muCut = OP_DphiPTW_muCut(1.)


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

RECO_CommonHTCut300 = OP_HTPTCut(300.)
RECO_CommonHTCut500 = OP_HTPTCut(500.)

PFMuonCheck = OP_MuonCheck()

PFMET100 = OP_PFMETCutBin(100.,-1.)
PFMET150 = OP_PFMETCutBin(150.,-1.)

selection = OP_GoodEventSelection()
HBBEnoise = OP_HadronicHBHEnoiseFilter()
BeamHalo = OP_beamHaloCSCTightHaloId()
NoTracks = had.OP_SumVertexPtOverHT(0.1)


AtLeast4Jts = OP_NumComJets(">=",4)
AtLeast3Jts = OP_NumComJets(">=",3)
AtLeast3JtsSync = OP_NumComJets(">=",3)
AtLeast2Jts = OP_NumComJets(">=",2)
AtLeast1Jts = OP_NumComJets(">=",1)
LessThan4Jts = OP_NumComJets("<",4)
LessThan3Jts = OP_NumComJets("<",3)


NumOfGenLeptons = OP_GenNumberLepCut(1)

#SecondJetEtCut60 = OP_SecondJetEtCut(60.)
#SecondJetEtCut100 = OP_SecondJetEtCut(100.)
# cuts from Oneleptonic folder

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

msugra_pset = PSet(
    DirectoryName = "mSuGraScan",
    xBins = 200,
    xLow = 0.,
    xHigh = 2000.,
    yBins =80,
    yLow =0.,
    yHigh =800.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    verbose = True,
    NLO = None
    )

msugra_psets = {}

def getMSUGRAPSet(path):
    if not path in msugra_psets:
        processes, kfactors = susy_utils.readKFactors(path)
        ps = susy_utils.kfactorsToPSet(processes, kfactors)
        msugra_psets[path] = ps
    return msugra_psets[path]

def tripleScale(model = "tanB10", cutTree = None, cut = None, label = "", SM=False) :
    from libSUSYSignalScan import OP_mSuGraPlottingOps, OP_SMPlottingOps
    out = []
    for scale in q2_scales: # see onelepton_settings.py
        scale2 = scale.replace(".","")
        if scale2[-1]=="0" : scale2 = scale2[:-1]
        pset = deepcopy(msugra_pset)
        mSUGRAFile = "%s/SUSYSignalScan/textfiles/scale_xsection_nlo%s_m0_m12_%s_1v1.txt"%(susyDir(),
                                                                                        scale, model.replace("tanB","") )
        ps = getMSUGRAPSet(mSUGRAFile)
        pset._quiet_set("NLO", ps)
        pset.DirectoryName = "Counter_BSMGrid_%s_scale%s"%(label, scale2)
        if SM: op = OP_SMPlottingOps(pset.ps())
        else: op = OP_mSuGraPlottingOps(pset.ps())
        out.append(op)
        out.append(ps)
       # if cut is not None:
       #     cutTree.TAttach(cut, op)
       # else:
       #     cutTree.Attach(op)
    return (op, out)

def setupSUSYWeighting(a):
    xs = susy_utils.readLOXS("%s/SUSYSignalScan/textfiles/goodModelNames_10_0_1.txt" % susyDir())
    xsps = susy_utils.xsToPSet(xs)
    from libSUSYSignalScan import SignalScanLOCrossSectionWeighting
    weight = SignalScanLOCrossSectionWeighting(xsps.ps())
    a.AddWeightFilter("Weight", weight)
    return [weight]

################################################################################
def setupMuonPreselection(MET, name, mode, less_than_3jets=False):
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
    eleID = CustomEleIdRA4Sync(Els_Sig.ps())
    a.AddElectronFilter("PreCC", eleID)
    filters += [eleID]

    # Electron-jet DR cut
    el_jet_dr = EleJetDRFilter(0.3)
    #    el_jet_dr = EleJetDRFilterRA4Sync(0.3, Els_Sig.ps())
    a.AddJetFilter("PreCC", el_jet_dr)
    filters += [el_jet_dr]

    # this replaces typeI and uncorrected PFMET
    if MET == "typeI":
        met_typeI_filter = pfMETtopfMETtypeI()
        a.AddMETFilter("pfMET",met_typeI_filter)
        filters += [met_typeI_filter]

    # 311 MC needs to be reweighted accoring to vertex multiplicity
    # see onelepton/python/onelepton/filters.py
    if mode == "MC311" or mode == "MC42ttw_Z41" or mode == "MC42QCD" or mode == "MCskims":
        vert = reweightVertices(a)
        filters += [vert]

    if mode == "MCGrid": filters += setupSUSYWeighting(a)

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
            "sample_Fall11_data" : triggerSyncMuHad,#triggerData42X_PromptReco,
            "data42X_ReReco" : triggerData42X_ReReco
            }

    if mode in dataTriggers:
        tree.Attach(json)
        tree.TAttach(json,myCountsAndBSMGrids_Json)
        tree.TAttach(myCountsAndBSMGrids_Json,dataTriggers[mode])
        tree.TAttach(dataTriggers[mode],myCountsAndBSMGrids_Trigger)
        tree.TAttach(myCountsAndBSMGrids_Trigger,selection)
        
    elif mode == "MCGrid" or mode == "SMS":
        # Attach a BSM grid before any cuts have been applied so that we can
        # calculate signal efficiency for limit setting
        (bsmgrid, store) = tripleScale(cutTree = tree, label = "NoCuts", SM=False)
        tree.Attach(bsmgrid)
        tree.TAttach(bsmgrid, selection)
        filters += store
    else:
        tree.Attach(selection)

    # Add cut flow common to signal/control
    tree.TAttach(selection,myCountsAndBSMGrids_Sel)
    tree.TAttach(myCountsAndBSMGrids_Sel,HBBEnoise)
    tree.TAttach(HBBEnoise,myCountsAndBSMGrids_Noise)
    tree.TAttach(myCountsAndBSMGrids_Noise,BeamHalo)
    tree.TAttach(BeamHalo,myCountsAndBSMGrids_beam)
    tree.TAttach(myCountsAndBSMGrids_beam,NoTracks)
    tree.TAttach(NoTracks,myCountsAndBSMGrids_track)
    if  mode == "data42X_ReReco":
        tree.TAttach(myCountsAndBSMGrids_track,MuHad_May10ReReco_Cut_BE)
        tree.TAttach(MuHad_May10ReReco_Cut_BE,MuHad_May10ReReco_Cut_TP)
        tree.TAttach(MuHad_May10ReReco_Cut_TP,myCountsAndBSMGrids_TPBE)
    elif mode == "data42X_PromptReco":
        tree.TAttach(myCountsAndBSMGrids_track,MuHad_Prompt_Cut_BE)
        tree.TAttach(MuHad_Prompt_Cut_BE,MuHad_Prompt_Cut_TP)
        tree.TAttach(MuHad_Prompt_Cut_TP,myCountsAndBSMGrids_TPBE)
    elif mode == "sample_Fall11_data": 
        tree.TAttach(myCountsAndBSMGrids_track,MuHad_Prompt6_Cut_TP)
 #       tree.TAttach(MuHad_Prompt6_Cut_BE,MuHad_Prompt6_Cut_TP)
 #       tree.TAttach(MuHad_Prompt6_Cut_TP,MuHad_Aug5ReReco_v1_Cut_TP)
 #       tree.TAttach(MuHad_Aug5ReReco_v1_Cut_TP,MuHad_Aug5ReReco_v1_Cut_BE)
        tree.TAttach(MuHad_Prompt6_Cut_TP,myCountsAndBSMGrids_TPBE)
    else:
        tree.TAttach(myCountsAndBSMGrids_track,myCountsAndBSMGrids_TPBE)
 
    tree.TAttach(myCountsAndBSMGrids_TPBE,AtLeast2Jts)
    tree.TAttach(AtLeast2Jts,myCountsAndBSMGrids_2jets)
    tree.TAttach(myCountsAndBSMGrids_2jets,AtLeast3JtsSync)
    tree.TAttach(AtLeast3JtsSync,myCountsAndBSMGrids_3jets)
### FOR SYCHRONIZATION######################################
 #   tree.TAttach(myCountsAndBSMGrids_3jets,AtLeast4Jts)
 #   tree.TAttach(AtLeast4Jts,myCountsAndBSMGrids_4jets)
 #   tree.TAttach(myCountsAndBSMGrids_4jets,OneMu)
############################################################
    tree.TAttach(myCountsAndBSMGrids_3jets,OneMu)
    tree.TAttach(OneMu,myCountsAndBSMGrids_1mu)
    tree.TAttach(myCountsAndBSMGrids_1mu,PFMuonCheck)
    tree.TAttach(PFMuonCheck,myCountsAndBSMGrids_1muPF)
    tree.TAttach(myCountsAndBSMGrids_1muPF,ZeroEl)
    tree.TAttach(ZeroEl,myCountsAndBSMGrids_0El)
    tree.TAttach(myCountsAndBSMGrids_0El,ZeroLooseMu)
    tree.TAttach(ZeroLooseMu,myCountsAndBSMGrids_0loosemu)
    tree.TAttach(myCountsAndBSMGrids_0loosemu,DphiPTW_muCut)
    tree.TAttach(DphiPTW_muCut,ZeroLooseEl)
   ## tree.TAttach( myCountsAndBSMGrids_0loosemu,ZeroLooseEl)
    tree.TAttach(ZeroLooseEl,myCountsAndBSMGrids_0Eloose)
    #### FOR SYCHRONIZATION #################################################
    tree.TAttach(myCountsAndBSMGrids_0Eloose,RECO_CommonHTCut300)
    tree.TAttach(RECO_CommonHTCut300,myCountsAndBSMGrids_300HT)
    tree.TAttach(myCountsAndBSMGrids_300HT,PFMET100)
    tree.TAttach(PFMET100,myCountsAndBSMGrids_150PFMET)
    ########################################################################
    # Example to SKIM
    # tree.TAttach(ZeroEl,SumLepPT125)
    # tree.TAttach(SumLepPT125,skim)
    ###########################################################################
    if less_than_3jets: # CONTROL REGION
        tree.TAttach(ZeroLooseEl, AtLeast1Jts)
        if  mode == "data42X_ReReco":
            tree.TAttach(ZeroLooseEl,MuHad_May10ReReco_Cut_BE)
            tree.TAttach(MuHad_May10ReReco_Cut_BE,MuHad_May10ReReco_Cut_TP)
            tree.TAttach(MuHad_May10ReReco_Cut_TP,LessThan3Jts)
        elif  mode == "data42X_PromptReco":
            tree.TAttach(ZeroLooseEl,MuHad_Prompt_Cut_BE)
            tree.TAttach(MuHad_Prompt_Cut_BE,MuHad_Prompt_Cut_TP)
            tree.TAttach(MuHad_Prompt_Cut_TP,LessThan3Jts)
        else:
            tree.TAttach(AtLeast1Jts, LessThan3Jts)

    else: # SIGNAL REGION
        tree.TAttach(ZeroLooseEl,RECO_CommonHTCut500)
        tree.TAttach(RECO_CommonHTCut500,AtLeast3Jts)
  
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

    if mode == "MCGrid": filters += setupSUSYWeighting(a)

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
        tree.TAttach(json,HBBEnoise)
        tree.TAttach(HBBEnoise,BeamHalo)
        tree.TAttach(BeamHalo,NoTracks)
        tree.TAttach(NoTracks, dataTriggers[mode])
        tree.TAttach(dataTriggers[mode],selection)
    elif mode == "MCGrid" or mode == "SMS":
        # Attach a BSM grid before any cuts have been applied so that we can
        # calculate signal efficiency for limit setting
        (bsmgrid, store) = tripleScale(cutTree = tree, label = "NoCuts", SM=False)
        tree.TAttach(bsmgrid, selection)
        filters += store
    else:
        tree.Attach(selection)

    # Add cut flow common to signal/control
    tree.TAttach(selection, OneEl)

    if qcd_antiselection:
        tree.TAttach(OneEl,ZeroLooseMu)
    else:
        tree.TAttach(OneEl,ZeroLooseEl)
        tree.TAttach(ZeroLooseEl,ZeroLooseMu)

    tree.TAttach(ZeroLooseMu,ZeroMu)

    if less_than_3jets: # CONTROL REGION
        tree.TAttach(ZeroMu, AtLeast1Jts)
        tree.TAttach(AtLeast1Jts, LessThan3Jts)
    else: # SIGNAL REGION
        tree.TAttach(ZeroMu,RECO_CommonHTCut500)
 #       tree.TAttach(RECO_CommonHTCut500, AtLeast2Jts)
        if  mode == "data42X_ReReco":
            tree.TAttach(RECO_CommonHTCut500,ElHad_May10ReReco_Cut_BE)
            tree.TAttach(ElHad_May10ReReco_Cut_BE,ElHad_May10ReReco_Cut_TP)
            tree.TAttach(ElHad_May10ReReco_Cut_TP,AtLeast3Jts)
            tree.TAttach(ElHad_May10ReReco_Cut_TP,AtLeast4Jts)

        elif  mode == "data42X_PromptReco":
            tree.TAttach(RECO_CommonHTCut500,ElHad_Prompt_Cut_BE)
            tree.TAttach(ElHad_Prompt_Cut_BE,ElHad_Prompt_Cut_TP)
            tree.TAttach(ElHad_Prompt_Cut_TP,ElHad_Aug5ReReco_v1_Cut_BE)
            tree.TAttach(ElHad_Aug5ReReco_v1_Cut_BE,ElHad_Aug5ReReco_v1_Cut_TP)
            tree.TAttach(ElHad_Aug5ReReco_v1_Cut_TP,ElHad_Prompt_v6_Cut_BE)
            tree.TAttach(ElHad_Prompt_v6_Cut_BE,ElHad_Prompt_v6_Cut_TP)
            tree.TAttach(ElHad_Prompt_v6_Cut_TP,AtLeast3Jts)
            tree.TAttach(ElHad_Prompt_v6_Cut_TP,AtLeast4Jts)

        else:
            tree.TAttach(RECO_CommonHTCut500, AtLeast3Jts)
            tree.TAttach(RECO_CommonHTCut500, AtLeast4Jts)


    return (a, tree, filters)
################################################################################



def setupSignalBins(tree, hook, bins, mode="lp",
                    sig_cut_value=0.15, bg_cut_value=0.3, prefix=None, SM=False):
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

            # Store the bin op in case we want to attach stuff to it later
            bin_cuts[sbin] = bin_op
            # Attach the bin cut (i.e. pfmet or sumleppt)
            tree.TAttach(cut, bin_op)
            # Attach the counter op
            (bsmgrid, store) = tripleScale(cutTree=tree, cut=bin_op, label = bin_name, SM=SM)
            # Save the operations we created
            ops += [bin_op]
            ops.extend(store)

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
