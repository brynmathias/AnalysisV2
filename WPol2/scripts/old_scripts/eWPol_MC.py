#!/usr/bin/env python
import setupSUSY
from libFrameworkSUSY import *
from libWPol import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig

import wpol.electron_id as eid
import samples.icf2 as icf

import icf.utils as utils
import icf.types as types

#====================================
# Configuration
#====================================
gen_match = False
lepton_type = "Electron"
my_ntuple_path = "/home/alex/Research/Samples/ICF"
id_working_point = eid.eff_944
lumi = 1

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
conf.Common.ApplyXCleaning=False
conf.Common.Electrons.ApplyID=False

conf.Common.Photons.EtCut = 25.0
conf.Common.Photons.EtaCut = 2.5
conf.Common.Photons.TrkIsoCut = 9.
conf.Common.Photons.EcalIsoCut = 99999.
conf.Common.Photons.HcalIsoCut = 99999.
conf.Common.Photons.AllIsoCut = 0.2
conf.Common.Photons.IDReq = 3

conf.Ntuple.Jets.Prefix="ak5Jet"

pol_plots_cfg = PSet(
    DoGen = True,
    LeptonType = lepton_type,
    METThreshold = 0.,
    NLeptons = 1
)

met_plots_cfg = PSet(
    ElecET=20.,
    CorrEEMisalig=False,
    useObservable="MET",
    useGEN=False,
    eType="All"
)
lp_plots_cfg = PSet(
    ElecET=20.,
    CorrEEMisalig=False,
    useObservable="LP",
    useGEN=False,
    eType="All"
)
iso_plots_cfg = PSet(
    ElecET=20.,
    CorrEEMisalig=False,
    useObservable="Iso",
    useGEN=False,
    eType="All"
)


#====================================

trigger = OP_TriggerCut("HLT_Ele15_SW_L1R")

OneElectron = OP_NumComElectrons(">=",1)
ZeroMuons = OP_NumComMuons("==", 0)
#ZeroPhotons = OP_NumComPhotons("==", 0)
LT4Jets = OP_NumComJets("<", 4)

ZMassCut20 = MassWindowCut("Electron", PSet( MassLower = 76., MassUpper=106.,
                                           MatchCharge = True, NetCharge = 0 ).ps() )
ZMassCut30 = MassWindowCut("Electron", PSet( MassLower = 76., MassUpper=106.,
                                           MatchCharge = True, NetCharge = 0 ).ps() )
MHTCut50 = RECO_CommonMHTCut(50.)
PFMHTCut50 = OP_PFMHTCut(50.)
PFMETCut20 = OP_PFMETCut(20.)
PFMETCut30 = OP_PFMETCut(30.)

trigger_eff = TriggerEffPlot("trigger_eff")

BasicPlotsOneEle = eWPolBasicPlots("eWPolBasicPlotsOneEle", pol_plots_cfg.ps())
BasicPlotsPostMHT50 = eWPolBasicPlots("ewPolBasicPlotsPostMHT50", pol_plots_cfg.ps())

PolPlotsPreMHT = RECO_ElPolPlots("RECO_ElPolPlots_PreMHT", pol_plots_cfg.ps())
PolPlotsPostMHT50 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT50", pol_plots_cfg.ps())

PolPlotsPostMHT50MET20 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT50MET20", pol_plots_cfg.ps())
PolPlotsPostMHT50MET30 = RECO_ElPolPlots("RECO_ElPolPlots_PostMHT50MET30",pol_plots_cfg.ps())

eMetTemplatePreMHT = eTemplateHistos("eMetTemplatePreMHT",met_plots_cfg.ps())
eLPTemplatePreMHT = eTemplateHistos("eLPTemplatePreMHT",lp_plots_cfg.ps())

eMetTemplatePostMHT50 = eTemplateHistos("eMetTemplatePostMHT50",met_plots_cfg.ps())
eLPTemplatePostMHT50 = eTemplateHistos("eLPTemplatePostMHT50",lp_plots_cfg.ps())

eMetTemplatePostMHT50MET20 = eTemplateHistos("eMetTemplatePostMHT50MET20",met_plots_cfg.ps())
eLPTemplatePostMHT50MET20 = eTemplateHistos("eLPTemplatePostMHT50MET20",lp_plots_cfg.ps())

eMetTemplatePostMHT50MET30 = eTemplateHistos("eMetTemplatePostMHT50MET30",met_plots_cfg.ps())
eLPTemplatePostMHT50MET30 = eTemplateHistos("eLPTemplatePostMHT50MET30",lp_plots_cfg.ps())

tree = Tree("Main")

# Main trunk of tree
tree.Attach(trigger)
tree.TAttach(trigger,OneElectron)
tree.TAttach(OneElectron, ZeroMuons)
tree.TAttach(ZeroMuons,trigger_eff)
tree.TAttach(trigger_eff, BasicPlotsOneEle)
tree.TAttach(BasicPlotsOneEle, LT4Jets)
tree.TAttach(LT4Jets, ZMassCut20)
tree.TAttach(ZMassCut20,PolPlotsPreMHT)
tree.TAttach(PolPlotsPreMHT,eMetTemplatePreMHT)
tree.TAttach(eMetTemplatePreMHT,eLPTemplatePreMHT)
tree.TAttach(eLPTemplatePreMHT,PFMHTCut50)

tree.TAttach(PFMHTCut50, PolPlotsPostMHT50)
tree.TAttach(PolPlotsPostMHT50,eMetTemplatePostMHT50)
tree.TAttach(eMetTemplatePostMHT50,eLPTemplatePostMHT50)
tree.TAttach(eLPTemplatePostMHT50,PFMETCut20)

tree.TAttach(PFMETCut20,PolPlotsPostMHT50MET20)
tree.TAttach(PolPlotsPostMHT50MET20,eMetTemplatePostMHT50MET20)
tree.TAttach(eMetTemplatePostMHT50MET20,eLPTemplatePostMHT50MET20)
tree.TAttach(eLPTemplatePostMHT50MET20,PFMETCut30)

tree.TAttach(PFMETCut30,PolPlotsPostMHT50MET30)
tree.TAttach(PolPlotsPostMHT50MET30,eMetTemplatePostMHT50MET30)
tree.TAttach(eMetTemplatePostMHT50MET30,eLPTemplatePostMHT50MET30)

#eleS=CustomEleId(sig_id.ps())
jet=EleJetDRFilter(0.3)

sig=Analysis("eWPol_Signal")
#sig.AddElectronFilter("PreCC",eleS)
sig.AddJetFilter("PreCC",jet)
sig+=tree

Wenu=PSet(
    Name="W_enu",
    File="/home/georgia/dataICF/Wenu.root",
    CrossSection = 61.53 , # will be scaled to 100pb-1
    Format = ("ICF", 2)
)

qcd_pythia_merged=PSet(
    Name="QCD_Pythia_Merged",
    Format=("ICF",2),
    File=(
    "/home/georgia/dataICF/QCDJets_pt30_N.root",
    "/home/georgia/dataICF/QCDJets_pt80_N.root"
    ),
    Weights = PSet( #scaled to 100pb-1
    CrossSection = [ 6.041e+05, 9.238e+03 ],
    Events       = [ 4869664,   2921800  ],
    PtBin        = [ 30.,       80.   ],
    )
)



samples=[
    Wenu,
    qcd_pythia_merged

#    icf.qcd_pt80,
#    icf.QCD_EMenriched_20to30,
#    icf.qcd_pt80,
#    icf.QCD_EMenriched_20to30,
#    icf.QCD_EMenriched_30to80,
#    icf.QCD_EMenriched_80to170,
#    icf.qcd_bctoe_20to30,
#    icf.QCD_BCtoE_30to80,
#    icf.QCD_BCtoE_80to170,

#    icf.qcd_em_30to80,
#    icf.qcd_em_80to170,
#     icf.Wjets,
#     icf.Zjets,
#     icf.gammajets_pt30
]

# NLO CrossSection!!!
icf.Wjets.CrossSection = 24170.

#local_ntuple(samples, my_ntuple_path, True)
#utils.switch_ntuple(samples, "/home/alex/Research/Samples/NtupleMap.txt", True)
#utils.reweight(samples, lumi)

sig.Run("../results", conf, samples)

