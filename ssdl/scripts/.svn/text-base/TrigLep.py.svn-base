#!/usr/bin/env python


import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.utils import *
from data.MuHad_Run2011A_PromptReco_v2 import MuHad_Run2011A_PromptReco_v2 as muuu
from data.HT_Run2011A_PromptReco_v2 import HT_Run2011A_PromptReco_v2 as httt
from data.oldHT_Run2011A_PromptReco_v2 import HT_Run2011A_PromptReco_v2 as oldhttt
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
conf.Ntuple.Jets.Prefix="ak5JetPF2PAT"
conf.Ntuple.SecJets.Prefix="ak5Jet"
conf.Common.Jets.PtCut = 40.0
conf.Common.Jets.EtaCut = 5.0
conf.Common.Jets.TightID=False
conf.Common.Jets.ApplyID=True

#############################
conf.Common.Muons.PtCut = 2.0
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 2.0
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
conf.Common.Taus.PtCut =  8.0
conf.Common.Taus.EtaCut = 2.3

IsoTightTau=1
IsoLooseTau=0

tau_id = PSet(
    TauSource=conf.Ntuple.Taus.Prefix,
    tauIDbyIso = IsoTightTau,

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
elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
tauSelFilter=CustomTauId(tau_id.ps())

# Create the analysis
a=Analysis("LepTurnOn")
tree = Tree("Main")


# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger

##############
## TRIGGERS ##
##############

TriggerDen=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT300_MHT75_v4",

         bit2=""
         )
       )

TriggerNumMu=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_Mu5_PFMHT35_v2",
         bit2="HLT_HT250_Mu5_PFMHT35_v2",
         bit3=""
         )
       )


TriggerNumEl=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v2",
         bit2="HLT_HT250_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v2",
         bit3=""
         )
       )


TriggerNumTau=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v2",
         bit2="HLT_HT250_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v2",
         bit3="",    
         )
       )


ssdlTriggDen=SSDLTrigger("TriggerDen",TriggerDen.ps())
ssdlTriggNumTau=SSDLTrigger("TriggerNumTau",TriggerNumTau.ps())
ssdlTriggNumMu=SSDLTrigger("TriggerNumMu",TriggerNumMu.ps())
ssdlTriggNumEl=SSDLTrigger("TriggerNumEl",TriggerNumEl.ps())

a.AddMuonFilter("PreCC",muonSelFilter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddTauFilter("PreCC",tauSelFilter)

OneMu      = OP_NumComMuons("==",1)
OneEl      = OP_NumComElectrons("==",1)
TwoTaus     = OP_NumComTaus("==",2)

json_to_pset("goodjson.txt", debug=True)
json = JSONFilter("Cert_7TeV", json_to_pset("goodjson.txt"))


HTHT=RECO_CommonHTCut(300.)


################################################
a += tree
##TRIGGERS
tree.Attach(json)
#tree.TAttach(json,ssdlTriggDen)
#tree.TAttach(ssdlTriggDen,OneMu)
#tree.TAttach(ssdlTriggDen,OneEl)
#tree.TAttach(ssdlTriggDen,TwoTaus)
tree.TAttach(json,HTHT)
tree.TAttach(HTHT,OneMu)
tree.TAttach(HTHT,OneEl)
tree.TAttach(HTHT,TwoTaus)
tree.TAttach(OneMu,ssdlTriggNumMu)
tree.TAttach(OneEl,ssdlTriggNumEl)
tree.TAttach(TwoTaus,ssdlTriggNumTau)


latestdata=[oldhttt]

a.Run(".", conf, latestdata)
