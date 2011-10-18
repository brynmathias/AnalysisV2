#!/usr/bin/env python
import setupSUSY
from icf.core import PSet
ecal_transparency_corrections_version = "38"
use_tight_ele_id = False #set this to False if you want to use the individual ID cuts
use_loose_ele_id = True

from wpol.samples_jad import *
from data.EG_dec22 import EGRUN2010A_Dec22

import libFrameworkSUSY as fwk
import libWPol as wpol
from ewpol.eWPolConfig import ewpol_conf, loose_id, tight_id
from icf.core import PSet,Analysis

conf = ewpol_conf.copy()

conf.Ntuple.Jets.Prefix = "ak5JetPF2PAT"
conf.Ntuple.SecJets.Prefix = "ak5JetPF"
conf.Ntuple.TerJets.Prefix = "nothanks"
#conf.Common.Electrons.PtCut = 5.

a = Analysis("eWPol")

jet_dr = wpol.EleJetDRFilter(0.3)
loose_ele_id = wpol.CustomEleId(loose_id.ps())
tight_ele_id = wpol.CustomEleId(tight_id.ps())

ecal_filter = wpol.ECALTransparencyCorrections(
   PSet(
          CorrectionsVersion = ecal_transparency_corrections_version,
          ApplyAsCorrection = True,
          ApplySystematics = False,
          SystematicsShift = 0.0
                     ).ps())

if use_tight_ele_id:
    a.AddElectronFilter("PostCC", tight_ele_id)
if use_loose_ele_id:
    a.AddElectronFilter("PostCC", loose_ele_id)

a.AddJetFilter("PostCC", jet_dr)
a.AddElectronFilter("PostCC", ecal_filter)

print "Creating Standard Analysis"

myEventNoDump01 = wpol.EventNoDump("start", "start")
myEventNoDump02 = wpol.EventNoDump("after_trig", "after_trig")
myEventNoDump03 = wpol.EventNoDump("after_goodevents", "after_goodevents")
myEventNoDump04 = wpol.EventNoDump("after_oneeli", "after_oneeli")
myEventNoDump05 = wpol.EventNoDump("after_onetighteli", "after_onetighteli")
myEventNoDump06 = wpol.EventNoDump("after_threecharge", "after_threecharge")
myEventNoDump07 = wpol.EventNoDump("after_nomuons", "after_nomuons")
myEventNoDump08 = wpol.EventNoDump("after_numjets", "after_numjets")
myEventNoDump09 = wpol.EventNoDump("after_mtcut", "after_mtcut")
myEventNoDump10 = wpol.EventNoDump("after_ptwcut", "after_ptwcut")

myEventIDNoDump01 = wpol.EventNoDump("passID_isolation", "passID_isolation")
myEventIDNoDump02 = wpol.EventNoDump("passID_HoE", "passID_HoE")
myEventIDNoDump03 = wpol.EventNoDump("passID_DeltaEta", "passID_DeltaEta")
myEventIDNoDump04 = wpol.EventNoDump("passID_DeltaPhi", "passID_DeltaPhi")
myEventIDNoDump05 = wpol.EventNoDump("passID_Sigmaietaieta", "passID_Sigmaietaieta")
myEventIDNoDump06 = wpol.EventNoDump("passID_Conversions", "passID_Conversions")

checkplots01 = wpol.RECO_ElCheckPlots("start")
checkplots02 = wpol.RECO_ElCheckPlots("passCut_Trigger")
checkplots03 = wpol.RECO_ElCheckPlots("passCut_GoodEvents")
checkplots04 = wpol.RECO_ElCheckPlots("passCut_OneLooseElectron")
checkplots05 = wpol.RECO_ElCheckPlots("passCut_OneTightElectron")
checkplots06 = wpol.RECO_ElCheckPlots("passCut_ThreeCharge")
checkplots07 = wpol.RECO_ElCheckPlots("passCut_NoMuons")
checkplots08 = wpol.RECO_ElCheckPlots("passCut_NumJets")
checkplots09 = wpol.RECO_ElCheckPlots("passCut_MTCut")
checkplots10 = wpol.RECO_ElCheckPlots("passCut_PTWCut")

checkplotsid01 = wpol.RECO_ElCheckPlots("jpassID_isolation")
checkplotsid02 = wpol.RECO_ElCheckPlots("jpassID_HoE")
checkplotsid03 = wpol.RECO_ElCheckPlots("jpassID_DeltaEta")
checkplotsid04 = wpol.RECO_ElCheckPlots("jpassID_DeltaPhi")
checkplotsid05 = wpol.RECO_ElCheckPlots("jpassID_Sigmaietaieta")
checkplotsid06 = wpol.RECO_ElCheckPlots("jpassID_Conversions")


t = fwk.Tree("eWPol")

trigger_bits = (
                "HLT_Ele10_LW_L1R",
                "HLT_Ele15_SW_L1R",
                "HLT_Ele15_SW_CaloEleId_L1R",
                "HLT_Ele17_SW_CaloEleId_L1R",
                "HLT_Ele17_SW_TightEleId_L1R",
                "HLT_Ele22_SW_TighterEleId_L1R_v2",
                "HLT_Ele22_SW_TighterEleId_L1R_v3"
                )
triggers = PSet(Triggers=trigger_bits)

trig = fwk.OP_MultiTrigger(triggers.ps())
goodevents = fwk.OP_GoodEventSelection()
oneeli = fwk.OP_NumComElectrons("==", 1)
onetighteli = wpol.ApplyLeptonCut("Electron", 25., tight_ele_id, 1, True)
threecharge = wpol.ChargeAgreement()
nomuons = fwk.OP_NumComMuons("==",0)
numjets = fwk.OP_NumComJets("<", 4)
mtcut = wpol.ePFMTCut("Electron", 50)
ptwcut = wpol.OP_PFMHTCut(50)

isolationID = wpol.DebugElectronID(0, tight_id.ps())
hoeID = wpol.DebugElectronID(1, tight_id.ps())
deltaetaID = wpol.DebugElectronID(2, tight_id.ps())
deltaphiID = wpol.DebugElectronID(3, tight_id.ps())
sigmaietaietaID = wpol.DebugElectronID(4, tight_id.ps())
conversionID = wpol.DebugElectronID(5, tight_id.ps())

t.Attach(myEventNoDump01)
t.TAttach(myEventNoDump01, trig)
t.TAttach(trig, myEventNoDump02)
t.TAttach(myEventNoDump02, goodevents)
t.TAttach(goodevents, myEventNoDump03)
t.TAttach(myEventNoDump03, oneeli)
t.TAttach(oneeli, myEventNoDump04)
t.TAttach(myEventNoDump04, onetighteli)
t.TAttach(onetighteli, myEventNoDump05)
#t.TAttach(myEventNoDump04, isolationID)
#t.TAttach(isolationID, myEventIDNoDump01)
#t.TAttach(myEventIDNoDump01, hoeID)
#t.TAttach(hoeID, myEventIDNoDump02)
#t.TAttach(myEventIDNoDump02, deltaetaID)
#t.TAttach(deltaetaID, myEventIDNoDump03)
#t.TAttach(myEventIDNoDump03, deltaphiID)
#t.TAttach(deltaphiID, myEventIDNoDump04)
#t.TAttach(myEventIDNoDump04, sigmaietaietaID)
#t.TAttach(sigmaietaietaID, myEventIDNoDump05)
#t.TAttach(myEventIDNoDump05, conversionID)
#t.FAttach(conversionID, myEventIDNoDump06)
#t.FAttach(conversionID, checkplotsid06)
#t.TAttach(myEventIDNoDump06, myEventNoDump05)
t.TAttach(myEventNoDump05, threecharge)
t.TAttach(threecharge, myEventNoDump06)
t.TAttach(myEventNoDump06, nomuons)
t.TAttach(nomuons, myEventNoDump07)
t.TAttach(myEventNoDump07, numjets)
t.TAttach(numjets, myEventNoDump08)
#t.TAttach(myEventNoDump08, mtcut)
#t.TAttach(mtcut, myEventNoDump09)
#t.TAttach(myEventNoDump09, ptwcut)
#t.TAttach(ptwcut, myEventNoDump10)
t.TAttach(myEventNoDump08, ptwcut)
t.TAttach(ptwcut, myEventNoDump09)
t.TAttach(myEventNoDump09, mtcut)
t.TAttach(mtcut, myEventNoDump10)

a+=t

# Define the list of samples to run over
#e38 = [erun38]
#e39 = [erun39]
#e38n39 = [erun38mis39]
#e39n38 = [erun39mis38]

a.Run("results/electrontest",conf,[EGRUN2010A_Dec22])
