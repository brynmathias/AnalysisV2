#!/usr/bin/env python


import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.utils import *
from data.MuHad_Run2011A_PromptReco_v2 import MuHad_Run2011A_PromptReco_v2 as muuu
from data.HT_Run2011A_PromptReco_v2 import HT_Run2011A_PromptReco_v2 as httt
from data.ElectronHad_Run2011A_PromptReco_v2 import ElectronHad_Run2011A_PromptReco_v2 as elll
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



# Create the analysis
a=Analysis("HTTurnOn")
tree  = Tree("Main")


##############
## TRIGGERS ##
##############

TriggerDenMu=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_Mu5_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )


TriggerMu=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT250_Mu5_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )

TriggerDenEl=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )


TriggerEl=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT250_Ele5_CaloIdVL_TrkIdVL_CaloIsoVL_TrkIsoVL_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )

TriggerDenTau=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT200_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v2",
#         bit1="HLT_Mu8_v1",
         bit2=""
         )
       )


TriggerTau=PSet(
       McAnal =False,
        MSugraScan = 0.,
       TriggerBits=PSet(
         bit1="HLT_HT250_DoubleLooseIsoPFTau10_Trk3_PFMHT35_v2",
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
tree.TAttach(ssdlTriggDenTau,ssdlTriggTau)


data=[muuu,elll,tauu]
a.Run(".", conf, data)

