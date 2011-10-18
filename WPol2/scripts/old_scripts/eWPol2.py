#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libWPol import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig

import wpol.electron_id as eid
import samples.icf2 as icf
import samples.QCD_EMBCE_PSet as qcd
import samples.wjets_madgraph_pset as w

import icf.utils as utils
import icf.types as types

#====================================
# Configuration
#====================================
gen_match = False
lepton_type = "Electron"
my_ntuple_path = "/home/alex/Research/Samples/ICF"
id_working_point = eid.eff_90
lumi = 10.
ele_jet_dr_cut = 0.3
use_pf_objects = False

sig_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,
    SupressErrors = True
)

bg_id = PSet(
    Cuts = id_working_point,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = False,
    DeltaPhiAtVtx = False,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,
    SupressError = True
)

good_id = PSet(
    Cuts = eid.eff_80,
    Isolation = True,
    HoverE = True,
    DeltaEtaAtVtx = True,
    DeltaPhiAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,
    SupressErrors = True
)


conf=defaultConfig.copy()
conf.Common.Jets.EtCut = 20.0
conf.Common.Jets.EtaCut = 5.0
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.PtCut = 15.0
conf.Common.Muons.TrkIsoCut = -1.
conf.Common.Muons.CombIsoCut = 0.1
conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4

# These are turned off anyhow
conf.Common.Electrons.TrkIsoCut = -1.
conf.Common.Electrons.CombIsoCut = 0.1
conf.Common.Electrons.TightID = True
conf.Common.ApplyXCleaning=False
conf.Common.Electrons.ApplyID=False

conf.Common.Photons.EtCut = 25.0
conf.Common.Photons.EtaCut = 2.5
conf.Common.Photons.TrkIsoCut = 9.
conf.Common.Photons.EcalIsoCut = 99999.
conf.Common.Photons.HcalIsoCut = 99999.
conf.Common.Photons.AllIsoCut = 0.2
conf.Common.Photons.IDReq = 3

conf.Ntuple.Jets.Prefix = "ak5Jet"

if use_pf_objects:
    conf.Ntuple.Jets.Prefix="ak5JetPF"
    conf.Ntuple.Electrons.Suffix="PF"
    ele_jet_dr_cut = 0.3 # Tighten this for PF

pol_plots_cfg = PSet(
    DoGen = True,
    LeptonType = lepton_type,
    METThreshold = 40.,
    NLeptons = 1
)
#====================================

trigger = OP_TriggerCut("HLT_Ele15_SW_L1R")

OneElectron = OP_NumComElectrons(">=",1)
ZeroMuons = OP_NumComMuons("==", 0)
#ZeroPhotons = OP_NumComPhotons("==", 0)
LT4Jets = OP_NumComJets("<", 4)
ele_good=CustomEleId(good_id.ps())
FirstEle = ApplyLeptonCut("Electron", 20.0, ele_good, 1, True)
ZMassCut = MassWindowCut("Electron", PSet( MassLower = 76., MassUpper=106.,
                                           MatchCharge = True, NetCharge = 0 ).ps() )
MHTCut50 = RECO_CommonMHTCut(50.)
MHTCut100 = RECO_CommonMHTCut(100.)
PFMHTCut50 = OP_PFMHTCut(50.)
PFMHTCut100 = OP_PFMHTCut(100.)
PFMETCut20 = OP_PFMETCut(20.)
PFMETCut20_2 = OP_PFMETCut(20.)
PFMETCut30 = OP_PFMETCut(30.)
PFMETCut30_2 = OP_PFMETCut(30.)

trigger_eff = TriggerEffPlot("trigger_eff")

BasicPlotsOneEle = eWPolBasicPlots("eWPolBasicPlotsOneEle", pol_plots_cfg.ps())
BasicPlotsPostMHT50 = eWPolBasicPlots("ewPolBasicPlotsPostMHT50", pol_plots_cfg.ps())
BasicPlotsPostMHT100 = eWPolBasicPlots("eWPolBasicPlotsPostMHT100", pol_plots_cfg.ps())

PolPlotsPreMHT = RECO_ElPolPlots("RECO_ElPolPlots_PreMHT", pol_plots_cfg.ps())
PolPlotsPostMHT50 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT50", pol_plots_cfg.ps())
PolPlotsPostMHT100 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT100", pol_plots_cfg.ps())

PolPlotsPostMHT50MET20 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT50MET20", pol_plots_cfg.ps())
PolPlotsPostMHT50MET30 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT50MET30",pol_plots_cfg.ps())
PolPlotsPostMHT100MET20 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT100MET20", pol_plots_cfg.ps())
PolPlotsPostMHT100MET30 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT100MET30",pol_plots_cfg.ps())
if gen_match:
    PolPlotsPreMHT_HF = RECO_ElPolPlots("RECO_ElPolPlots_PreMHT_HF", pol_plots_cfg.ps())
    PolPlotsPostMHT_HF = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT_HF", pol_plots_cfg.ps())
    PolPlotsPreMHT_Fake = RECO_ElPolPlots("RECO_ElPolPlots_PreMHT_Fake", pol_plots_cfg.ps())
    PolPlotsPostMHT_Fake = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT_Fake", pol_plots_cfg.ps())
    PolPlotsPreMHT_Photon = RECO_ElPolPlots("RECO_ElPolPlots_PreMHT_Photon", pol_plots_cfg.ps())
    PolPlotsPostMHT_Photon = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT_Photon", pol_plots_cfg.ps())

    HFCut = GenLeptonType(lepton_type,"HF")
    FakeCut = GenLeptonType(lepton_type,"Fake")
    PhotonCut = GenLeptonType(lepton_type, "Photon")
    MHTCut50_HF = RECO_CommonMHTCut(50.)
    MHTCut50_Fake = RECO_CommonMHTCut(50.)
    MHTCut50_Photon = RECO_CommonMHTCut(50.)


# if skim_output:
#     skim = SkimOp( PSet(
#         SkimName = "eWPol_gt1ele",
#         DropBranches = False,
#         Branches = types.StringVector([])
#         ).ps() )

def make_tree(tree,control=False):
    # Main trunk of tree
    tree.Attach(trigger)
    tree.TAttach(trigger,OneElectron)
    #tree.Attach(OneElectron)
    tree.TAttach(OneElectron, ZeroMuons)
    if control:
        tree.TAttach(ZeroMuons, trigger_eff)
    else:
        tree.TAttach(ZeroMuons, FirstEle)
        tree.TAttach(FirstEle, trigger_eff)
    tree.TAttach(trigger_eff, BasicPlotsOneEle)
    tree.TAttach(BasicPlotsOneEle, ZMassCut)
    tree.TAttach(ZMassCut, LT4Jets)
    tree.TAttach(LT4Jets, PolPlotsPreMHT)
    if use_pf_objects:
        tree.TAttach(PolPlotsPreMHT, MHTCut50)
        tree.TAttach(MHTCut50, PolPlotsPostMHT50)
    else:
        tree.TAttach(PolPlotsPreMHT, PFMHTCut50)
        tree.TAttach(PFMHTCut50, PolPlotsPostMHT50)
    tree.TAttach(PolPlotsPreMHT, PFMHTCut100)
    tree.TAttach(PFMHTCut100, PolPlotsPostMHT100)
    tree.TAttach(PolPlotsPostMHT100, BasicPlotsPostMHT100)
    tree.TAttach(BasicPlotsPostMHT100, PFMETCut20_2)
    tree.TAttach(PFMETCut20_2, PolPlotsPostMHT100MET20)
    tree.TAttach(PolPlotsPostMHT100MET20, PFMETCut30_2)
    tree.TAttach(PFMETCut30_2, PolPlotsPostMHT100MET30)
    #tree.TAttach(PolPlotsPostMHT50, trigger1)
    #tree.TAttach(trigger1, PFMETCut20)

    tree.TAttach(PolPlotsPostMHT50,PFMETCut20)
    tree.TAttach(PolPlotsPostMHT50, BasicPlotsPostMHT50)
    tree.TAttach(PFMETCut20,PolPlotsPostMHT50MET20)
    tree.TAttach(PolPlotsPostMHT50MET20,PFMETCut30)
    tree.TAttach(PFMETCut30,PolPlotsPostMHT50MET30)
    if gen_match:
        # HF Plots
        tree.TAttach(LT4Jets, HFCut)
        tree.TAttach(HFCut, PolPlotsPreMHT_HF)
        tree.TAttach(PolPlotsPreMHT_HF, MHTCut50_HF)
        tree.TAttach(MHTCut50_HF, PolPlotsPostMHT_HF)
        # Fake Plots
        tree.TAttach(LT4Jets, FakeCut)
        tree.TAttach(FakeCut, PolPlotsPreMHT_Fake)
        tree.TAttach(PolPlotsPreMHT_Fake, MHTCut50_Fake)
        tree.TAttach(MHTCut50_Fake, PolPlotsPostMHT_Fake)
        # Photon Plots
        tree.TAttach(LT4Jets, PhotonCut)
        tree.TAttach(PhotonCut, PolPlotsPreMHT_Photon)
        tree.TAttach(PolPlotsPreMHT_Photon, MHTCut50_Photon)
        tree.TAttach(MHTCut50_Photon, PolPlotsPostMHT_Photon)
    return tree

eleS=CustomEleId(sig_id.ps())
eleB=CustomEleId(bg_id.ps())
jet=EleJetDRFilter(ele_jet_dr_cut)

sig=Analysis("eWPol_Signal")
sig.AddElectronFilter("PreCC",eleS)
sig.AddJetFilter("PreCC",jet)
sig_tree = Tree("Signal")
sig+=make_tree(sig_tree, control = False)

control=Analysis("eWPol_Control")
control.AddElectronFilter("PreCC",eleB)
control.AddJetFilter("PreCC",jet)
control_tree = Tree("Control")
control+=make_tree(control_tree, control=True)

import glob
lm0 = PSet(
    Name = "LM0",
    Format = ("ICF", 2),
    File = glob.glob("/home/alex/Research/Samples/ICF/LM0/*.root")
)
samples=[
    lm0
#    qcd.em_20_30,
#    qcd.em_30_80,
#    qcd.em_80_170,
#    qcd.bce_20_30,
#    qcd.bce_30_80,
#    qcd.bce_80_170
]

#local_ntuple(samples, my_ntuple_path, True)
#utils.switch_ntuple(samples, "/home/alex/Research/Samples/NtupleMap.txt", False)
utils.reweight(samples, lumi)

sig.Run("../results", conf, samples)
#control.Run("../results",conf,samples)

