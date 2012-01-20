#!/usr/bin/env python


import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.utils import *
from data.MuHad_Run2011A_PromptReco_v2 import MuHad_Run2011A_PromptReco_v2 as muuu
from data.ElectronHad_Run2011A_PromptReco_v2 import ElectronHad_Run2011A_PromptReco_v2 as elll
from data.HT_Run2011A_PromptReco_v2 import HT_Run2011A_PromptReco_v2 as httt
from data.TauPlusX_Run2011A_PromptReco_v2 import TauPlusX_Run2011A_PromptReco_v2 as tauu
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
#############################
conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.EtaCut = 2.1
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
conf.Common.Taus.PtCut =  13.0
conf.Common.Taus.EtaCut = 2.3

# Create the analysis
a=Analysis("METTurnOn")
tree = Tree("Main")

##############
## TRIGGERS ##
##############
IsoTightTau=1
IsoLooseTau=0

tau_id = PSet(
    TauSource=conf.Ntuple.Taus.Prefix,
    tauIDbyIso = IsoTightTau,

    )
tauSelFilter=CustomTauId(tau_id.ps())
a.AddTauFilter("PreCC",tauSelFilter)

TriggerDenMu=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_Mu5_HT200_v5",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )


TriggerMu=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_Mu5_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )

TriggerDenEl=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_Ele10_CaloIdL_CaloIsoVL_TrkIdVL_TrkIsoVL_HT200_v4",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )


TriggerEl=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )

HTHT=RECO_CommonHTCut(300.)
TwoTaus      = OP_NumComTaus(">",1)

TriggerDenTau=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_DoubleIsoPFTau20_Trk5_v4",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )

TriggerTau=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )


ssdlTriggDenMu=SSDLTrigger("TriggerDenMu",TriggerDenMu.ps())
ssdlTriggMu=SSDLTrigger("TriggerMu",TriggerMu.ps())

ssdlTriggDenEl=SSDLTrigger("TriggerDenEl",TriggerDenEl.ps())
ssdlTriggEl=SSDLTrigger("TriggerEl",TriggerEl.ps())

ssdlTriggDenTau=SSDLTrigger("TriggerDenTau",TriggerDenTau.ps())
ssdlTriggTau=SSDLTrigger("TriggerTau",TriggerTau.ps())


json_to_pset("goodjson.txt", debug=True)
json = JSONFilter("Cert_7TeV", json_to_pset("goodjson.txt"))


################################################
a += tree
##TRIGGERS
tree.Attach(json)
tree.TAttach(json,ssdlTriggDenMu)
tree.TAttach(ssdlTriggDenMu,ssdlTriggMu)
tree.TAttach(json,ssdlTriggDenEl)
tree.TAttach(ssdlTriggDenEl,ssdlTriggEl)
tree.TAttach(json,ssdlTriggDenTau)
tree.TAttach(ssdlTriggDenTau,HTHT)
tree.TAttach(HTHT,TwoTaus)
tree.TAttach(TwoTaus,ssdlTriggTau)

data=[muuu,elll,tauu,httt]
#data=[tauu]
#muuu.LastEntry=1000
#elll.LastEntry=1000
#tauu.LastEntry=1000
#httt.LastEntry=1000

a.Run(".", conf,data )
################################################


