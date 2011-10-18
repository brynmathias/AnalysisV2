#!/usr/bin/env python


import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.utils import *

from data.Run2011.HT_Run2011A import HT_Run2011A as AllHT
from data.Run2011.ElectronHad_Run2011A_PromptReco_v4_latest import ElectronHad_Run2011A_PromptReco_v4 as AllElPR

# from SSDLsamples.data.MuHad_Run2011A_PromptReco_v1v2_DCSJson import MuHad_Run2011A_PromptReco_v1 as muuu
from SSDLsamples.data.MuHad_Run2011A_PromptReco_v4_1 import MuHad_Run2011A_PromptReco_v4_1 as mu1
from SSDLsamples.data.MuHad_Run2011A_PromptReco_v4_2 import MuHad_Run2011A_PromptReco_v4_2 as mu2
from SSDLsamples.data.MuHad_Run2011A_PromptReco_v4_3 import MuHad_Run2011A_PromptReco_v4 as mu3
from SSDLsamples.data.MuHad_Run2011A_PromptReco_v4_4 import MuHad_Run2011A_PromptReco_v4 as mu4
from SSDLsamples.data.MuHad_Run2011A_PromptReco_v4_5 import MuHad_Run2011A_PromptReco_v4 as mu5
from SSDLsamples.data.MuHad_Run2011A_PromptReco_v4_6 import MuHad_Run2011A_PromptReco_v4 as mu6
from SSDLsamples.data.MuHad_Run2011A_May10ReReco_v1 import MuHad_Run2011A_May10ReReco_v1 as muReRe

from SSDLsamples.data.ElectronHad_Run2011A_PromptReco_v4_1 import ElectronHad_Run2011A_PromptReco_v4_1 as el1
from SSDLsamples.data.ElectronHad_Run2011A_PromptReco_v4_2 import ElectronHad_Run2011A_PromptReco_v4_2 as el2
from SSDLsamples.data.ElectronHad_Run2011A_May10ReReco_v1 import ElectronHad_Run2011A_May10ReReco_v1 as elReRe

# from data.Run2011.HT_Run2011_promptReco_DCS import HT_Run2011_promptReco_DCS as httt
from SSDLsamples.data.HT_Run2011A_PromptReco_v4_1 import HT_Run2011A_PromptReco_v4_1 as ht1
from SSDLsamples.data.HT_Run2011A_PromptReco_v4_2 import HT_Run2011A_PromptReco_v4_2 as ht2
from SSDLsamples.data.HT_Run2011A_May10ReReco_v1 import HT_Run2011A_May10ReReco_v1 as htReRe
# from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v1v2_DCSJson import TauPlusX_Run2011A_PromptReco_v1 as tauu
from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v4_1 import TauPlusX_Run2011A_PromptReco_v4_1 as tau1
from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v4_2 import TauPlusX_Run2011A_PromptReco_v4_2 as tau2
from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v4_3 import TauPlusX_Run2011A_PromptReco_v4 as tau3
from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v4_4 import TauPlusX_Run2011A_PromptReco_v4 as tau4
from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v4_5 import TauPlusX_Run2011A_PromptReco_v4 as tau5
from SSDLsamples.data.TauPlusX_Run2011A_PromptReco_v4_6 import TauPlusX_Run2011A_PromptReco_v4 as tau6
from SSDLsamples.data.TauPlusX_Run2011A_May10ReReco_v1 import TauPlusX_Run2011A_May10ReReco_v1 as tauReRe


# Samples with fast jet corrections


from SSDLsamples.data.FastJetCorr.MuHad_Run2011A_All import MuHad_Run2011A_May10ReReco_v1_1 as muFJC1, MuHad_Run2011A_May10ReReco_v1_2 as muFJC2, MuHad_Run2011A_May10ReReco_v1_3 as muFJC3, MuHad_Run2011A_PromptReco_v4_1 as muFJC4, MuHad_Run2011A_PromptReco_v4_2 as muFJC5, MuHad_Run2011A_PromptReco_v4_3 as muFJC6

from SSDLsamples.data.FastJetCorr.ElectronHad_Run2011A_All import ElectronHad_Run2011A_May10ReReco_v1_1 as elFJC1, ElectronHad_Run2011A_May10ReReco_v1_2 as elFJC2, ElectronHad_Run2011A_May10ReReco_v1_3 as elFJC3, ElectronHad_Run2011A_PromptReco_v4_1 as elFJC4, ElectronHad_Run2011A_PromptReco_v4_2 as elFJC5, ElectronHad_Run2011A_PromptReco_v4_3 as elFJC6

from SSDLsamples.data.FastJetCorr.TauPlusX_Run2011A_All import TauPlusX_Run2011A_May10ReReco_v1_1 as tauFJC1, TauPlusX_Run2011A_May10ReReco_v1_2 as tauFJC2, TauPlusX_Run2011A_PromptReco_v4_1 as tauFJC3, TauPlusX_Run2011A_PromptReco_v4_2 as tauFJC4, TauPlusX_Run2011A_PromptReco_v4_3 as tauFJC5

from SSDLsamples.data.FastJetCorr.HT_Run2011A_All import HT_Run2011A_May10ReReco_v1_1 as htFJC1, HT_Run2011A_May10ReReco_v1_2 as htFJC2, HT_Run2011A_May10ReReco_v1_3 as htFJC3, HT_Run2011A_PromptReco_v4_1 as htFJC4, HT_Run2011A_PromptReco_v4_2 as htFJC5, HT_Run2011A_PromptReco_v4_3 as htFJC6




import lep_conf as lepconf
import icf.utils as utils
import icf.types as types



# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig 

# import default configuration

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
conf.Common.Muons.ApplyID = True

conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4
conf.Common.Electrons.TrkIsoCut = 99.
conf.Common.Electrons.CombIsoCut = 99.
conf.Common.Electrons.TightID = False
conf.Common.Electrons.ApplyID = True

#############################
#conf.Ntuple.Taus.Prefix="tauHPS"
conf.Ntuple.Taus.Suffix="PF"
conf.Common.Taus.TightID = False
conf.Common.Taus.ApplyID = True
conf.Common.Taus.PtCut =  15.0
conf.Common.Taus.EtaCut = 2.4


ID = False

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
a=Analysis("Sel")

tree  = Tree("Main")

# Create a Tree called Main
#from icf.config import Trigger



##################
## LEP FILTYERS ##
##################
if ID:
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


##################
## TRIGGERS    ###
##################
##MU-TAU
TrigMu=PSet(Triggers = ["HLT_Mu5_HT200_v*","HLT_HT200_Mu5_PFMHT35_v*","HLT_HT250_Mu5_PFMHT35_v*",
                        "HLT_HT300_Mu5_PFMHT40_v*","HLT_HT350_Mu5_PFMHT45_v*"],
            Verbose = False,
            UsePreScaledTriggers = False)

#El-tau
TrigEl=PSet(Triggers = ["HLT_Ele10_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_HT200_v*",
                        "HLT_HT200_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v*",
                        "HLT_HT250_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v*",
                        "HLT_HT300_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT40_v*",
                        "HLT_HT350_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT45_v*",
                        "HLT_HT300_Ele5_CaloIdVL_CaloIsoVL_TrkIdVL_TrkIsoVL_PFMHT40_v*",
                        "HLT_HT350_Ele5_CaloIdVL_CaloIsoVL_TrkIdVL_TrkIsoVL_PFMHT45_v*"],
            Verbose = False,
            UsePreScaledTriggers = False)

#tau-tau
TrigTau=PSet(Triggers = ["HLT_HT200_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v*",
                         "HLT_HT250_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v*",
                         "HLT_HT300_DoubleLooseIsoPFTau10_Trk3_PFMHT40_v*",
                         "HLT_HT350_DoubleLooseIsoPFTau10_Trk3_PFMHT45_v*",
                         "HLT_HT250_DoubleIsoPFTau10_Trk3_PFMHT35_v*",
                         "HLT_HT300_DoubleIsoPFTau10_Trk3_PFMHT40_v*",
                         "HLT_HT350_DoubleIsoPFTau10_Trk3_PFMHT45_v*"],
             Verbose = False,
             UsePreScaledTriggers = False)


# tauFR
TrigTauFR = PSet(Triggers = ["HLT_HT250_v*"],
                 Verbose = False,
                 UsePreScaledTriggers = False)

# tauFR
TrigTauFR150 = PSet(Triggers = ["HLT_HLT150_v*"],
                    Verbose = False,
                    UsePreScaledTriggers = False)





TrMu = OP_MultiTrigger(TrigMu.ps())
TrEl = OP_MultiTrigger(TrigEl.ps())
TrTau = OP_MultiTrigger(TrigTau.ps())
TrTauFR = OP_MultiTrigger(TrigTauFR.ps())
TrTauFR150 = OP_MultiTrigger(TrigTauFR150.ps())

TwoJets   = OP_NumComJets(">",1)

####################
## TAU FAKE RATE  ##
####################

tauFR=PSet(
    SSMHTCut = 0.,
    SSHTCut = 300.,
    TauSource=conf.Ntuple.Taus.Prefix,
    UpperMetCut=2000.,
    UpperHTCut=2000.,
    LooseIsolation = IsoLooseTau,
    OppLepRequest = False,
    UseHps = UseHPS
    )
tauFR150=PSet(
    SSMHTCut = 0.,
    SSHTCut = 150.,
    TauSource=conf.Ntuple.Taus.Prefix,
    UpperMetCut=2000.,
    UpperHTCut=300.,
    LooseIsolation = IsoLooseTau,
    OppLepRequest = False,
    UseHps = UseHPS
    )


TAUFR=TauFakeRate("TAUFR",tauFR.ps())
TAUFR150=TauFakeRate("TAUFR150",tauFR.ps())
ZeroMu      = OP_NumComMuons("==",0)
ZeroEl      = OP_NumComElectrons("==",0)

#######################
## EventFinder ###
#####################
#Use this to pick any event

Event = PSet(
    Events = [227580680],
    Lumis = [394],
    Runs = [163334]
    )

EventPicker = SSDLEventPicker(Event.ps())
#######################
## SELECTION   ########
#######################


Selection=PSet(
    SSMHTCut= 80.,
    SSHTCut=350.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    UseHps = UseHPS,
    InterestingEvents = False,
    )


ssdlSelecMu=SSDLSelection("SelectionMu",Selection.ps())
ssdlSelecEl=SSDLSelection("SelectionEl",Selection.ps())
ssdlSelecTau=SSDLSelection("SelectionTau",Selection.ps())
#########################
## TAU NORMALIZATION ####
#########################

taunormMu=TauFRNormalization("TAUNORMMu",Selection.ps())
taunormEl=TauFRNormalization("TAUNORMEl",Selection.ps())
taunormTau=TauFRNormalization("TAUNORMTau",Selection.ps())

#######################
## SIGNAL SELECTION   ########
#######################
    
 
SigSelection=PSet(
    SSMHTCut= 120., 
    SSHTCut=400.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50000.,
    UseHps = UseHPS
    )


sigSsdlSelecMu=SSDLSelection("SigSelectionMu",SigSelection.ps())
sigSsdlSelecEl=SSDLSelection("SigSelectionEl",SigSelection.ps())
sigSsdlSelecTau=SSDLSelection("SigSelectionTau",SigSelection.ps())
#########################
## TAU NORMALIZATION ####
#########################
     
sigTaunormMu=TauFRNormalization("SigTAUNORMMu",SigSelection.ps())
sigTaunormEl=TauFRNormalization("SigTAUNORMEl",SigSelection.ps())
sigTaunormTau=TauFRNormalization("SigTAUNORMTau",SigSelection.ps())   


#######################
## CLOSURE TEST   #####
#######################

SelectionCT=PSet(
    SSMHTCut= 0.,
    SSHTCut=200.,
    LeptonCut =1.,
    TauSource=conf.Ntuple.Taus.Prefix,
    LooseIsolation = IsoLooseTau,
    UpperMetCut = 50.,
    UseHps = UseHPS
    )


ssdlSelecCTMu=SSDLSelection("SelectionCTMu",SelectionCT.ps())
ssdlSelecCTEl=SSDLSelection("SelectionCTEl",SelectionCT.ps())
ssdlSelecCTTau=SSDLSelection("SelectionCTTau",SelectionCT.ps())
#########################
## TAU NORMALIZATION ####
#########################
taunormCTMu=TauFRNormalization("TAUNORMCTMu",SelectionCT.ps())
taunormCTEl=TauFRNormalization("TAUNORMCTEl",SelectionCT.ps())
taunormCTTau=TauFRNormalization("TAUNORMCTTau",SelectionCT.ps())




####JSON FILE
json = JSONFilter("Cert_7TeV", json_to_pset("/vols/cms02/aeg04/SUSY2/ssdl/python/SSDLsamples/ssdlJson/Cert_160404-167784_May10RRPlusPR_963pb.json"))
jsonOut = JSONOutput("Filtered")
#json = JSONFilter("Cert_7TeV", json_to_pset("goodjson.txt"))
################################################
a += tree
##JSON
tree.Attach(json)
#EventPicker
tree.TAttach(json, EventPicker)
#TRIGGERS
tree.TAttach(json,TwoJets)
tree.TAttach(TwoJets,TrMu)
tree.TAttach(TwoJets,TrEl)
tree.TAttach(TwoJets,TrTau)

#TAU FAKE RATE
tree.TAttach(json,ZeroMu)
tree.TAttach(ZeroMu,ZeroEl)
tree.TAttach(ZeroEl,TrTauFR)
tree.TAttach(TrTauFR,TAUFR)
tree.TAttach(ZeroEl,TAUFR150)

#################
####SELECTION####
#################
#MU-TAU
tree.TAttach(TrMu,taunormMu)
tree.TAttach(TrMu,ssdlSelecMu)
#EL-TAU
tree.TAttach(TrEl,taunormEl)
tree.TAttach(TrEl,ssdlSelecEl)
#TAU-TAU
tree.TAttach(TrTau,taunormTau)
tree.TAttach(TrTau,ssdlSelecTau)

#################
####SIGNAL SELECTION####
#################
#MU-TAU
tree.TAttach(TrMu,sigTaunormMu)
tree.TAttach(TrMu,sigSsdlSelecMu)
#EL-TAU
tree.TAttach(TrEl,sigTaunormEl)
tree.TAttach(TrEl,sigSsdlSelecEl)
#TAU-TAU
tree.TAttach(TrTau,sigTaunormTau)
tree.TAttach(TrTau,sigSsdlSelecTau)


#################
##CLOSURE TEST###
#################
#MU-TAU
tree.TAttach(json,taunormCTMu)
tree.TAttach(json,ssdlSelecCTMu)
#EL-TAU
tree.TAttach(json,taunormCTEl)
tree.TAttach(json,ssdlSelecCTEl)
#TAU-TAU
tree.TAttach(json,taunormCTTau)
tree.TAttach(json,ssdlSelecCTTau)

#muuu.LastEntry=1000
#httt.LastEntry=1000
#elll.LastEntry=1000
#tauu.LastEntry=1000
Allmu=[mu1,mu2,mu3,mu4,mu5,mu6,muReRe]
Alltau=[tau1,tau2,tau3,tau4,tau5,tau6,tauReRe]
Allele=[AllElPR,elReRe]
AllHT = [AllHT]

AllFJCmu=[muFJC1,muFJC2,muFJC3,muFJC4,muFJC5,muFJC6]
AllFJCel=[elFJC1,elFJC2,elFJC3,elFJC4,elFJC5,elFJC6]
AllFJCtau=[tauFJC1,tauFJC2,tauFJC3,tauFJC4,tauFJC5]
AllFJCht=[htFJC1,htFJC2,htFJC3,htFJC4,htFJC5,htFJC6]
# latestdata=mudata + taudata + eledata + htdata
alldata = AllHT + Allmu + Alltau + Allele

allFJCdata = AllFJCmu + AllFJCel + AllFJCtau + AllFJCht
#latestdata=[httt]

from datetime import date
outpath = './AGB_Data_' + str(date.today()) + '_TEST_modID'
import os
if os.path.exists(outpath):
    print 'Warning, outpath: ' + outpath + ' already exists'
else:
    os.mkdir(outpath)




a.Run(outpath, conf, allFJCdata)

