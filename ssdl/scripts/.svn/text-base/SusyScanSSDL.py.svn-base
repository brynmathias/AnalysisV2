#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from icf.core import PSet, Analysis
from icf.utils import reweight
from SUSYSignalScan.utils import *
from SUSYSignalScan.plottingStuff_cfg import tripleScale, smsOps
from libSUSYSignalScan import *

import lep_conf as lepconf

from icf.config import defaultConfig



conf=defaultConfig

conf.Ntuple.Jets.Suffix="Pat"
conf.Ntuple.Jets.Uncorrected=False
conf.Ntuple.Jets.UseGenJets=False
conf.Ntuple.Jets.Prefix="ak5JetPF"
conf.Ntuple.SecJets.Prefix="ak5Jet"
conf.Common.Jets.PtCut = 40.0
conf.Common.Jets.EtaCut = 2.5
conf.Common.Jets.TightID=False
conf.Common.Jets.ApplyID=False

#############################
conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.EtaCut = 2.4
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4
conf.Common.Electrons.TrkIsoCut = 99.
conf.Common.Electrons.CombIsoCut = 99.
conf.Common.Electrons.TightID = False
conf.Common.Electrons.ApplyID = False

#############################
#conf.Ntuple.Taus.Prefix="tauHPS"
conf.Ntuple.Taus.Suffix="PF"
conf.Common.Taus.TightID = False
conf.Common.Taus.ApplyID = False
conf.Common.Taus.PtCut =  15.0
conf.Common.Taus.EtaCut = 2.4



IsoTightTau=2
IsoLooseTau=0
UseHPS=True
tau_id = PSet(
    TauSource=conf.Ntuple.Taus.Prefix,
    tauIDbyIso = IsoTightTau,
    AgainstElectron = True,
    AgainstMuon = True,
    UseHps = UseHPS
)


ele_id = PSet(
    OldNtu = False,
    Cuts = lepconf.ele_ptThres_vbtf80,
    IsolationSR = False,      # high pt
    IsoBarEC = True,
    HoverE = True,
    DeltaAtVtx = True,
    SigmaIEtaIEta = True,
    Conversions = True,
    ConversionsExtra = True,    # not in ntuple V00-08
    IsolationPF = False,
    LowPtSel = True,
    LowPtID = True,
    LowPtIso = True,
    ChargeComp = True,
    D0sel = True,
    dxychoice = 'beamspot'
)

muon_id = PSet(#we're missing the ecalvetoDep and hcalvetoDep in the ntuples (for MIP requirement) - AGB 22/10/10
   Cuts = lepconf.muonCuts,
   IsolationPF = False,
   IsolationSR = True,
   LowPtIso = True,
   MuonID = True,
   MuonIso = True,
   dxychoice = "beamspot"

)

jet_id = PSet(
    MinConstituents=1,
    MaxEMFrac=0.99,
    MaxHadFrac=0.99,
    FWDMinCHConstituents=0,
    FWDMinCHHadFrac=0.,
    FWDMaxCHEMFrac=0.99
)

elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
tauSelFilter=CustomTauId(tau_id.ps())
jetSelFilter=CustomJetId(jet_id.ps())

muelfilter=MuonElectronDrFilter(0.1)
eletaufilter=ElectronTauDrFilter(0.1)
mutaufilter=MuonTauDrFilter(0.1)

elejetfilter=ElectronJetDrFilter(0.4)
muonjetfilter=MuonJetDrFilter(0.4)
taujetfilter=TauJetDrFilter(0.1)


# Create the analysis
a=Analysis("SusyScan")

tree  = Tree("Main")

# Create a Tree called Main
#from icf.config import Trigger



##################
## LEP FILTERS ##
##################

a.AddMuonFilter("PreCC",muonSelFilter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddTauFilter("PreCC",tauSelFilter)
a.AddJetFilter("PreCC",jetSelFilter)
a.AddElectronFilter("PreCC",muelfilter)
a.AddTauFilter("PreCC",mutaufilter)
a.AddTauFilter("PreCC",eletaufilter)
a.AddJetFilter("PreCC",taujetfilter) 
a.AddJetFilter("PreCC",elejetfilter)
a.AddJetFilter("PreCC",muonjetfilter)

path_to_xs = '/vols/cms02/aeg04/SUSY2/SUSYSignalScan/textfiles'

LOweights = SignalScanLOCrossSectionWeighting(xsToPSet(readLOXS(path_to_xs + '/goodModelNames_10_0_1.txt') ).ps())


a.AddWeightFilter("Weight",LOweights)

# conf.Ntuple.Weight = 'mSuGra'


#######################
## SIGNAL SELECTION   ########
#######################
    
 
SigSelection=PSet(
    SSMHTCut= 0., 
    SSHTCut=0.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    IgnoreNonTauStates = True
    )


sigSsdlSelec=SSDLSelection("SelectionFull",SigSelection.ps())


SigSelection_ET=PSet(
    SSMHTCut= 0., 
    SSHTCut=0.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    OnlyETau = True
    )


sigSsdlSelec_ET=SSDLSelection("Selection_ET",SigSelection_ET.ps())


SigSelection_MT=PSet(
    SSMHTCut= 0., 
    SSHTCut=0.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    OnlyMuTau = True
    )


sigSsdlSelec_MT=SSDLSelection("Selection_MT",SigSelection_MT.ps())

SigSelection_TT=PSet(
    SSMHTCut= 0., 
    SSHTCut=0.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    OnlyTauTau = True
    )


sigSsdlSelec_TT=SSDLSelection("Selection_TT",SigSelection_TT.ps())


####Lep Efficiencies wrt Gen


lepsel_os_ee=SSDLSelection("LepSel_os_ee",SigSelection.ps())
lepsel_os_mm=SSDLSelection("LepSel_os_mm",SigSelection.ps())
lepsel_os_tt=SSDLSelection("LepSel_os_tt",SigSelection.ps())
lepsel_os_em=SSDLSelection("LepSel_os_em",SigSelection.ps())
lepsel_os_et=SSDLSelection("LepSel_os_et",SigSelection.ps())
lepsel_os_mt=SSDLSelection("LepSel_os_mt",SigSelection.ps())

lepsel_ss_ee=SSDLSelection("LepSel_ss_ee",SigSelection.ps())
lepsel_ss_mm=SSDLSelection("LepSel_ss_mm",SigSelection.ps())
lepsel_ss_tt=SSDLSelection("LepSel_ss_tt",SigSelection.ps())
lepsel_ss_em=SSDLSelection("LepSel_ss_em",SigSelection.ps())
lepsel_ss_et=SSDLSelection("LepSel_ss_et",SigSelection.ps())
lepsel_ss_mt=SSDLSelection("LepSel_ss_mt",SigSelection.ps())

Gen_os_ee = PSet(channel = 0, oppositesign = True)
Gen_os_mm = PSet(channel = 1, oppositesign = True)
Gen_os_tt = PSet(channel = 2, oppositesign = True)
Gen_os_em = PSet(channel = 3, oppositesign = True)
Gen_os_et = PSet(channel = 4, oppositesign = True)
Gen_os_mt = PSet(channel = 5, oppositesign = True)
Gen_ss_ee = PSet(channel = 0, samesign = True)
Gen_ss_mm = PSet(channel = 1, samesign = True)
Gen_ss_tt = PSet(channel = 2, samesign = True)
Gen_ss_em = PSet(channel = 3, samesign = True)
Gen_ss_et = PSet(channel = 4, samesign = True)
Gen_ss_mt = PSet(channel = 5, samesign = True)

os_ee_presel = SSDL_MC_PreSel(Gen_os_ee.ps())
os_mm_presel = SSDL_MC_PreSel(Gen_os_mm.ps())
os_tt_presel = SSDL_MC_PreSel(Gen_os_tt.ps())
os_em_presel = SSDL_MC_PreSel(Gen_os_em.ps())
os_et_presel = SSDL_MC_PreSel(Gen_os_et.ps())
os_mt_presel = SSDL_MC_PreSel(Gen_os_mt.ps())
ss_ee_presel = SSDL_MC_PreSel(Gen_ss_ee.ps())
ss_mm_presel = SSDL_MC_PreSel(Gen_ss_mm.ps())
ss_tt_presel = SSDL_MC_PreSel(Gen_ss_tt.ps())
ss_em_presel = SSDL_MC_PreSel(Gen_ss_em.ps())
ss_et_presel = SSDL_MC_PreSel(Gen_ss_et.ps())
ss_mt_presel = SSDL_MC_PreSel(Gen_ss_mt.ps())

#####

TwoJets = OP_NumComJets(">",1)
TwoJets_wHT = OP_NumComJets(">",1)
TwoJets_ET  = OP_NumComJets(">",1)
TwoJets_MT = OP_NumComJets(">",1)
TwoJets_TT = OP_NumComJets(">",1)

pfMETcut_eff = OP_PFMETCut(120.)
pfMETcut = OP_PFMETCut(120.)
pfMETcut_ET = OP_PFMETCut(120.)
pfMETcut_MT = OP_PFMETCut(120.)
pfMETcut_TT = OP_PFMETCut(120.)

HTcut = RECO_CommonHTCut(400.)
HTcut_wJets = RECO_CommonHTCut(400.)
HTcut_ET = RECO_CommonHTCut(400.)
HTcut_MT = RECO_CommonHTCut(400.)
HTcut_TT = RECO_CommonHTCut(400.)

    

################################################
mode = 'SMS' 

dummy = OP_ObjCountPlots('dummy',1)

mc = PSet(MSugraScan=False,McAnal=True)
MC_truth = SSDLMCTruth('mcPlots',mc.ps())

out=[]

a += tree
##JSON
# tripleScale(model = 'tanB10',cutTree = tree, label = 'test_pre')
#TRIGGERS
tree.Attach(MC_truth)
tree.Attach(dummy)
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = dummy, label = 'test_pre'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = dummy, label = 'test_pre'))

tree.Attach(os_ee_presel)
tree.Attach(os_mm_presel)
tree.Attach(os_tt_presel)
tree.Attach(os_em_presel)
tree.Attach(os_et_presel)
tree.Attach(os_mt_presel)
tree.Attach(ss_ee_presel)
tree.Attach(ss_mm_presel)
tree.Attach(ss_tt_presel)
tree.Attach(ss_em_presel)
tree.Attach(ss_et_presel)
tree.Attach(ss_mt_presel)

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = Gen_os_ee, label = 'gen_os_ee'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = os_ee_presel, label = 'gen_os_ee'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = os_mm_presel, label = 'gen_os_mm'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = os_tt_presel, label = 'gen_os_tt'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = os_em_presel, label = 'gen_os_em'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = os_et_presel, label = 'gen_os_et'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = os_mt_presel, label = 'gen_os_mt'))

    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = ss_ee_presel, label = 'gen_ss_ee'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = ss_mm_presel, label = 'gen_ss_mm'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = ss_tt_presel, label = 'gen_ss_tt'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = ss_em_presel, label = 'gen_ss_em'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = ss_et_presel, label = 'gen_ss_et'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = ss_mt_presel, label = 'gen_ss_mt'))


tree.TAttach(os_ee_presel, lepsel_os_ee)
tree.TAttach(os_mm_presel, lepsel_os_mm)
tree.TAttach(os_tt_presel, lepsel_os_tt)
tree.TAttach(os_em_presel, lepsel_os_em)
tree.TAttach(os_et_presel, lepsel_os_et)
tree.TAttach(os_mt_presel, lepsel_os_mt)
tree.TAttach(ss_ee_presel, lepsel_ss_ee)
tree.TAttach(ss_mm_presel, lepsel_ss_mm)
tree.TAttach(ss_tt_presel, lepsel_ss_tt)
tree.TAttach(ss_em_presel, lepsel_ss_em)
tree.TAttach(ss_et_presel, lepsel_ss_et)
tree.TAttach(ss_mt_presel, lepsel_ss_mt)


if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = lepsel_os_ee, label = 'LepSel_gen_os_ee'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_os_ee, label = 'LepSel_gen_os_ee'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_os_mm, label = 'LepSel_gen_os_mm'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_os_tt, label = 'LepSel_gen_os_tt'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_os_em, label = 'LepSel_gen_os_em'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_os_et, label = 'LepSel_gen_os_et'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_os_mt, label = 'LepSel_gen_os_mt'))

    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_ss_ee, label = 'LepSel_gen_ss_ee'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_ss_mm, label = 'LepSel_gen_ss_mm'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_ss_tt, label = 'LepSel_gen_ss_tt'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_ss_em, label = 'LepSel_gen_ss_em'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_ss_et, label = 'LepSel_gen_ss_et'))
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = lepsel_ss_mt, label = 'LepSel_gen_ss_mt'))


tree.Attach(sigSsdlSelec)
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = sigSsdlSelec, label = 'test_postLep'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = sigSsdlSelec, label = 'test_postLep'))

tree.Attach(TwoJets_wHT)
tree.TAttach(TwoJets_wHT, HTcut_wJets)
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = HTcut_wJets, label = 'test_postJetpostHT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = HTcut_wJets, label = 'test_postJetpostHT'))

tree.Attach(pfMETcut_eff)
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = pfMETcut_eff, label = 'test_postMET'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = pfMETcut_eff, label = 'test_postMET'))

    
tree.Attach(sigSsdlSelec_ET)

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = sigSsdlSelec_ET, label = 'test_postET'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = sigSsdlSelec_ET, label = 'test_postET'))

tree.Attach(sigSsdlSelec_MT)

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = sigSsdlSelec_MT, label = 'test_postMT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = sigSsdlSelec_MT, label = 'test_postMT'))

tree.Attach(sigSsdlSelec_TT)

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = sigSsdlSelec_TT, label = 'test_postTT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = sigSsdlSelec_TT, label = 'test_postTT'))

# for s in lept_sel:
#     tree.TAttach(s,TwoJets)
tree.TAttach(sigSsdlSelec, TwoJets)
tree.TAttach(sigSsdlSelec_ET,TwoJets_ET)
tree.TAttach(sigSsdlSelec_MT,TwoJets_MT)
tree.TAttach(sigSsdlSelec_TT,TwoJets_TT)
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = TwoJets, label = 'test_postLep_postJet'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = TwoJets, label = 'test_postLep_postJet'))
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = TwoJets_ET, label = 'test_postET_postJet'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = TwoJets_ET, label = 'test_postET_postJet'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = TwoJets_MT, label = 'test_postMT_postJet'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = TwoJets_MT, label = 'test_postMT_postJet'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = TwoJets_TT, label = 'test_postTT_postJet'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = TwoJets_TT, label = 'test_postTT_postJet'))

tree.TAttach(TwoJets, HTcut)
tree.TAttach(TwoJets_ET, HTcut_ET)
tree.TAttach(TwoJets_MT, HTcut_MT)
tree.TAttach(TwoJets_TT, HTcut_TT)

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = HTcut, label = 'test_postLep_postJet_postHT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = HTcut, label = 'test_postLep_postJet_postHT'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = HTcut_ET, label = 'test_postET_postJet_postHT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = HTcut_ET, label = 'test_postET_postJet_postHT'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = HTcut_MT, label = 'test_postMT_postJet_postHT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = HTcut_MT, label = 'test_postMT_postJet_postHT'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = HTcut_TT, label = 'test_postTT_postJet_postHT'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = HTcut_TT, label = 'test_postTT_postJet_postHT'))

tree.TAttach(HTcut, pfMETcut)
tree.TAttach(HTcut_ET, pfMETcut_ET)
tree.TAttach(HTcut_MT, pfMETcut_MT)
tree.TAttach(HTcut_TT, pfMETcut_TT)

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = pfMETcut, label = 'test_postLep_postJet_postHT_postMET'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = pfMETcut, label = 'test_postLep_postJet_postHT_postMET'))
    
if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = pfMETcut_ET, label = 'test_postET_postJet_postHT_postMET'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = pfMETcut_ET, label = 'test_postET_postJet_postHT_postMET'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = pfMETcut_MT, label = 'test_postMT_postJet_postHT_postMET'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = pfMETcut_MT, label = 'test_postMT_postJet_postHT_postMET'))

if mode == 'mSugra':
    out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = pfMETcut_TT, label = 'test_postTT_postJet_postHT_postMET'))
elif mode == 'SMS':
    out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = pfMETcut_TT, label = 'test_postTT_postJet_postHT_postMET'))
    



# tree.Attach(TwoJets)
# tree.TAttach(TwoJets,sigSsdlSelec)

# if mode == 'mSugra':
#     out.append(tripleScale(model = 'tanB10', cutTree = tree, cut = sigSsdlSelec, label = 'test_post'))
# elif mode == 'SMS':
#     out.append(smsOps(model = 'T1TauNu', cutTree = tree, cut = sigSsdlSelec, label = 'test_post'))


from datetime import date
outpath = './AGB_SusyScan_' + str(date.today()) + '_HT400Met120_SMS_New'
import os
if os.path.exists(outpath):
    print 'Warning, outpath: ' + outpath + ' already exists'
else:
    os.mkdir(outpath)


from SUSYSignalScan.mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1 import mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1 as  mSUGRA_TanB10


from montecarlo.PhysicsProcesses_mSUGRA_tanbeta50Fall10 import *

from SSDLsamples.mc.SMS_T1taunu_x_05_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v1_V15_03_14_T1taunu_noGenCut import SMS_T1taunu_x_05_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v1_V15_03_14_T1taunu as SimpModel_t1TauNu

tb50_old = [PhysicsProcesses_mSUGRA_tanbeta50Fall10]

TanB10 = [mSUGRA_TanB10]

T1TauNu = [SimpModel_t1TauNu]

SMS_test = PSet(
    Name = 'test',
    Format = ('ICF',3),
    File = [
        "root://gfe02.grid.hep.ph.ic.ac.uk/store/user/arlogb/SimplifiedModel_T1TauNu_Second/0.5_100.0_50.0to325.0_50.0.lhe_1.root"
        ],
    Weight = 1.0,
    # LastEntry = 10
    )

SMS_test2 = PSet(
    Name = 'test2',
    Format = ('ICF',3),
    File = [
        'root://gfe02.grid.hep.ph.ic.ac.uk/store/user/arlogb/ICF/automated/2011_08_23_16_46_43/SusyCAF_Tree_79_3_rar.root'
        ],
    Weight = 1.0
    )

test = [SMS_test]
test2 = [SMS_test2]

reweight(TanB10,976.)
if mode == 'mSugra':
    a.Run(outpath, conf, TanB10)
elif mode == 'SMS':
    a.Run(outpath, conf, T1TauNu)
    
