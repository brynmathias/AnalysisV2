#!/usr/bin/env python
#-----------------------------------------------------------------
# Includes
from hadronic.golden_cff import *
from icf.core import PSet
from libHadronic import *
from libOneLepton import *
from libWPol import *

from wpol.muon_config import muon_id
#from SweetBatchSub import *
from plottingStuff_cfg import *
from hadronic.commonIncludes import *
from validation.cutCounters_cff import * #TW for convenience...
from copy import deepcopy
from hadronic.samples_cff import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta10Fall10v1 import *
#---------------------------------Helper functions------------------------
#here you can choose your model and your jes_scale
# whichMSUGRA = "tanB10"
default_common.Jets.PtCut=43.3
secondJetET = OP_SecondJetEtCut(86.7)

def switches() :
  d = {}

  d["model"] = "tanB10"
  #d["model"] = "T1"
  d["jes_scale"] = "default"
  #d["jes_scale"] = "plus"
  #d["jes_scale"] = "minus"

  assert d["model"] in ["T1","T2","tanB3","tanB10","tanB50"]
  assert d["jes_scale"] in ["default","plus","minus"]

  return d

#here you can set your sms process filters and .the ISR uncertainty plotting ops Beware two different kind of filters at the moment
def sms_plottingOps(whichSMS) :

  if whichSMS == "T1" :
    smsFilter = genProcess("gg")
    # plots_isr_unc_before = OP_ISRPlottingOps(isr_T1_pset_before.ps())
    # plots_isr_unc_350 = OP_ISRPlottingOps(isr_T1_pset_350.ps())
    # plots_isr_unc_450 = OP_ISRPlottingOps(isr_T1_pset_450.ps())
    return 1

  if whichSMS == "T2" :
    smsFilter = gensignalProcessID(277,278,279,280)
    # plots_isr_unc_before = OP_ISRPlottingOps(isr_T2_pset_before.ps())
    # plots_isr_unc_350 = OP_ISRPlottingOps(isr_T2_pset_350.ps())
    # plots_isr_unc_450 = OP_ISRPlottingOps(isr_T2_pset_450.ps())
    return 1

  if not whichSMS == "T1" :
    if not whichSMS == "T2" :

      return -1



# Over-write some of the standard cuts with muon speciffic ones.




#here you can set your mSUGRA plotting ops for the different NLO scale factors
def mSuGra_plottingOps(whichMSUGRA) :
  if whichMSUGRA == "tanB3" :
    plots_mSuGraScan_275_325_scale1  = OP_mSuGraPlottingOps(msugra_pset_275_325_scale1_tanB3.ps()  )
    plots_mSuGraScan_275_325_scale05 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale05_tanB3.ps() )
    plots_mSuGraScan_275_325_scale2  = OP_mSuGraPlottingOps(msugra_pset_275_325_scale2_tanB3.ps()  )
    plots_mSuGraScan_325_375_scale1  = OP_mSuGraPlottingOps(msugra_pset_325_375_scale1_tanB3.ps()  )
    plots_mSuGraScan_325_375_scale05 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale05_tanB3.ps() )
    plots_mSuGraScan_325_375_scale2  = OP_mSuGraPlottingOps(msugra_pset_325_375_scale2_tanB3.ps()  )
    plots_mSuGraScan_375_475_scale1  = OP_mSuGraPlottingOps(msugra_pset_375_475_scale1_tanB3.ps()  )
    plots_mSuGraScan_375_475_scale05 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale05_tanB3.ps() )
    plots_mSuGraScan_375_475_scale2  = OP_mSuGraPlottingOps(msugra_pset_375_475_scale2_tanB3.ps()  )
    plots_mSuGraScan_475_575_scale1  = OP_mSuGraPlottingOps(msugra_pset_475_575_scale1_tanB3.ps()  )
    plots_mSuGraScan_475_575_scale05 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale05_tanB3.ps() )
    plots_mSuGraScan_475_575_scale2  = OP_mSuGraPlottingOps(msugra_pset_475_575_scale2_tanB3.ps()  )
    plots_mSuGraScan_575_675_scale1  = OP_mSuGraPlottingOps(msugra_pset_575_675_scale1_tanB3.ps()  )
    plots_mSuGraScan_575_675_scale05 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale05_tanB3.ps() )
    plots_mSuGraScan_575_675_scale2  = OP_mSuGraPlottingOps(msugra_pset_575_675_scale2_tanB3.ps()  )
    plots_mSuGraScan_675_775_scale1  = OP_mSuGraPlottingOps(msugra_pset_675_775_scale1_tanB3.ps()  )
    plots_mSuGraScan_675_775_scale05 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale05_tanB3.ps() )
    plots_mSuGraScan_675_775_scale2  = OP_mSuGraPlottingOps(msugra_pset_675_775_scale2_tanB3.ps()  )
    plots_mSuGraScan_775_875_scale1  = OP_mSuGraPlottingOps(msugra_pset_775_875_scale1_tanB3.ps()  )
    plots_mSuGraScan_775_875_scale05 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale05_tanB3.ps() )
    plots_mSuGraScan_775_875_scale2  = OP_mSuGraPlottingOps(msugra_pset_775_875_scale2_tanB3.ps()  )
    plots_mSuGraScan_875_scale1      = OP_mSuGraPlottingOps( msugra_pset_875_scale1_tanB3.ps()  )
    plots_mSuGraScan_875_scale05     = OP_mSuGraPlottingOps( msugra_pset_875_scale05_tanB3.ps() )
    plots_mSuGraScan_875_scale2      = OP_mSuGraPlottingOps( msugra_pset_875_scale2_tanB3.ps()  )

    return 1

  if whichMSUGRA == "tanB10" :
    plots_mSuGraScan_275_325_scale1 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale1_tanB10.ps()  )
    plots_mSuGraScan_275_325_scale05= OP_mSuGraPlottingOps(msugra_pset_275_325_scale05_tanB10.ps() )
    plots_mSuGraScan_275_325_scale2 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale2_tanB10.ps()  )
    plots_mSuGraScan_325_375_scale1 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale1_tanB10.ps()  )
    plots_mSuGraScan_325_375_scale05= OP_mSuGraPlottingOps(msugra_pset_325_375_scale05_tanB10.ps() )
    plots_mSuGraScan_325_375_scale2 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale2_tanB10.ps()  )
    plots_mSuGraScan_375_475_scale1 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale1_tanB10.ps()  )
    plots_mSuGraScan_375_475_scale05= OP_mSuGraPlottingOps(msugra_pset_375_475_scale05_tanB10.ps() )
    plots_mSuGraScan_375_475_scale2 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale2_tanB10.ps()  )
    plots_mSuGraScan_475_575_scale1 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale1_tanB10.ps()  )
    plots_mSuGraScan_475_575_scale05= OP_mSuGraPlottingOps(msugra_pset_475_575_scale05_tanB10.ps() )
    plots_mSuGraScan_475_575_scale2 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale2_tanB10.ps()  )
    plots_mSuGraScan_575_675_scale1 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale1_tanB10.ps()  )
    plots_mSuGraScan_575_675_scale05= OP_mSuGraPlottingOps(msugra_pset_575_675_scale05_tanB10.ps() )
    plots_mSuGraScan_575_675_scale2 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale2_tanB10.ps()  )
    plots_mSuGraScan_675_775_scale1 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale1_tanB10.ps()  )
    plots_mSuGraScan_675_775_scale05= OP_mSuGraPlottingOps(msugra_pset_675_775_scale05_tanB10.ps() )
    plots_mSuGraScan_675_775_scale2 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale2_tanB10.ps()  )
    plots_mSuGraScan_775_875_scale1 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale1_tanB10.ps()  )
    plots_mSuGraScan_775_875_scale05= OP_mSuGraPlottingOps(msugra_pset_775_875_scale05_tanB10.ps() )
    plots_mSuGraScan_775_875_scale2 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale2_tanB10.ps()  )
    plots_mSuGraScan_875_scale1 = OP_mSuGraPlottingOps( msugra_pset_875_scale1_tanB10.ps()  )
    plots_mSuGraScan_875_scale05= OP_mSuGraPlottingOps(msugra_pset_875_scale05_tanB10.ps() )
    plots_mSuGraScan_875_scale2 = OP_mSuGraPlottingOps( msugra_pset_875_scale2_tanB10.ps()  )
    return 1

  if whichMSUGRA == "tanB50" :
    plots_mSuGraScan_275_325_scale1 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale1_tanB50.ps()  )
    plots_mSuGraScan_275_325_scale05= OP_mSuGraPlottingOps(msugra_pset_275_325_scale05_tanB50.ps() )
    plots_mSuGraScan_275_325_scale2 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale2_tanB50.ps()  )
    plots_mSuGraScan_325_375_scale1 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale1_tanB50.ps()  )
    plots_mSuGraScan_325_375_scale05= OP_mSuGraPlottingOps(msugra_pset_325_375_scale05_tanB50.ps() )
    plots_mSuGraScan_325_375_scale2 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale2_tanB50.ps()  )
    plots_mSuGraScan_375_475_scale1 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale1_tanB50.ps()  )
    plots_mSuGraScan_375_475_scale05= OP_mSuGraPlottingOps(msugra_pset_375_475_scale05_tanB50.ps() )
    plots_mSuGraScan_375_475_scale2 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale2_tanB50.ps()  )
    plots_mSuGraScan_475_575_scale1 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale1_tanB50.ps()  )
    plots_mSuGraScan_475_575_scale05= OP_mSuGraPlottingOps(msugra_pset_475_575_scale05_tanB50.ps() )
    plots_mSuGraScan_475_575_scale2 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale2_tanB50.ps()  )
    plots_mSuGraScan_575_675_scale1 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale1_tanB50.ps()  )
    plots_mSuGraScan_575_675_scale05= OP_mSuGraPlottingOps(msugra_pset_575_675_scale05_tanB50.ps() )
    plots_mSuGraScan_575_675_scale2 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale2_tanB50.ps()  )
    plots_mSuGraScan_675_775_scale1 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale1_tanB50.ps()  )
    plots_mSuGraScan_675_775_scale05= OP_mSuGraPlottingOps(msugra_pset_675_775_scale05_tanB50.ps() )
    plots_mSuGraScan_675_775_scale2 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale2_tanB50.ps()  )
    plots_mSuGraScan_775_875_scale1 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale1_tanB50.ps()  )
    plots_mSuGraScan_775_875_scale05= OP_mSuGraPlottingOps(msugra_pset_775_875_scale05_tanB50.ps() )
    plots_mSuGraScan_775_875_scale2 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale2_tanB50.ps()  )
    plots_mSuGraScan_875_scale1 = OP_mSuGraPlottingOps( msugra_pset_875_scale1_tanB50.ps()  )
    plots_mSuGraScan_875_scale05= OP_mSuGraPlottingOps(msugra_pset_875_scale05_tanB50.ps() )
    plots_mSuGraScan_875_scale2 = OP_mSuGraPlottingOps( msugra_pset_875_scale2_tanB50.ps()  )
    return 1

  if not whichMSUGRA == "tanB3" :
    if not whichMSUGRA == "tanB10" :
      if not whichMSUGRA == "tanB50" :

        return -1


plots_mSuGraScan_275_325_scale1 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale1_tanB10.ps()  )
plots_mSuGraScan_275_325_scale05= OP_mSuGraPlottingOps(msugra_pset_275_325_scale05_tanB10.ps() )
plots_mSuGraScan_275_325_scale2 = OP_mSuGraPlottingOps(msugra_pset_275_325_scale2_tanB10.ps()  )
plots_mSuGraScan_325_375_scale1 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale1_tanB10.ps()  )
plots_mSuGraScan_325_375_scale05= OP_mSuGraPlottingOps(msugra_pset_325_375_scale05_tanB10.ps() )
plots_mSuGraScan_325_375_scale2 = OP_mSuGraPlottingOps(msugra_pset_325_375_scale2_tanB10.ps()  )
plots_mSuGraScan_375_475_scale1 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale1_tanB10.ps()  )
plots_mSuGraScan_375_475_scale05= OP_mSuGraPlottingOps(msugra_pset_375_475_scale05_tanB10.ps() )
plots_mSuGraScan_375_475_scale2 = OP_mSuGraPlottingOps(msugra_pset_375_475_scale2_tanB10.ps()  )
plots_mSuGraScan_475_575_scale1 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale1_tanB10.ps()  )
plots_mSuGraScan_475_575_scale05= OP_mSuGraPlottingOps(msugra_pset_475_575_scale05_tanB10.ps() )
plots_mSuGraScan_475_575_scale2 = OP_mSuGraPlottingOps(msugra_pset_475_575_scale2_tanB10.ps()  )
plots_mSuGraScan_575_675_scale1 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale1_tanB10.ps()  )
plots_mSuGraScan_575_675_scale05= OP_mSuGraPlottingOps(msugra_pset_575_675_scale05_tanB10.ps() )
plots_mSuGraScan_575_675_scale2 = OP_mSuGraPlottingOps(msugra_pset_575_675_scale2_tanB10.ps()  )
plots_mSuGraScan_675_775_scale1 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale1_tanB10.ps()  )
plots_mSuGraScan_675_775_scale05= OP_mSuGraPlottingOps(msugra_pset_675_775_scale05_tanB10.ps() )
plots_mSuGraScan_675_775_scale2 = OP_mSuGraPlottingOps(msugra_pset_675_775_scale2_tanB10.ps()  )
plots_mSuGraScan_775_875_scale1 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale1_tanB10.ps()  )
plots_mSuGraScan_775_875_scale05= OP_mSuGraPlottingOps(msugra_pset_775_875_scale05_tanB10.ps() )
plots_mSuGraScan_775_875_scale2 = OP_mSuGraPlottingOps(msugra_pset_775_875_scale2_tanB10.ps()  )
plots_mSuGraScan_875_scale1 = OP_mSuGraPlottingOps( msugra_pset_875_scale1_tanB10.ps()  )
plots_mSuGraScan_875_scale05= OP_mSuGraPlottingOps(msugra_pset_875_scale05_tanB10.ps() )
plots_mSuGraScan_875_scale2 = OP_mSuGraPlottingOps( msugra_pset_875_scale2_tanB10.ps()  )



plots_mSuGraScan_450_scale2         = OP_mSuGraPlottingOps(msugra_pset_450_scale2_tanB3.ps())
plots_mSuGraScan_450_scale05        = OP_mSuGraPlottingOps(msugra_pset_450_scale05_tanB3.ps())
plots_mSuGraScan_450_scale1         = OP_mSuGraPlottingOps(msugra_pset_450_scale1_tanB3.ps())
plots_mSuGraScan_350_450_scale2     = OP_mSuGraPlottingOps(msugra_pset_350_450_scale2_tanB3.ps())
plots_mSuGraScan_350_450_scale05    = OP_mSuGraPlottingOps(msugra_pset_350_450_scale05_tanB3.ps())
plots_mSuGraScan_350_450_scale1     = OP_mSuGraPlottingOps(msugra_pset_350_450_scale1_tanB3.ps())
plots_mSuGraScan_300_350_scale2     = OP_mSuGraPlottingOps(msugra_pset_300_350_scale2_tanB3.ps())
plots_mSuGraScan_300_350_scale05    = OP_mSuGraPlottingOps(msugra_pset_300_350_scale05_tanB3.ps())
plots_mSuGraScan_300_350_scale1     = OP_mSuGraPlottingOps(msugra_pset_300_350_scale1_tanB3.ps())
plots_mSuGraScan_250_300_scale2     = OP_mSuGraPlottingOps(msugra_pset_250_300_scale2_tanB3.ps())
plots_mSuGraScan_250_300_scale05    = OP_mSuGraPlottingOps(msugra_pset_250_300_scale05_tanB3.ps())
plots_mSuGraScan_250_300_scale1     = OP_mSuGraPlottingOps(msugra_pset_250_300_scale1_tanB3.ps())
numComPhotons = OP_NumComPhotons("<=",0)

numComMuons = OP_NumComMuons('==',1)
default_common.Muons.PtCut=20.0
#default_common.Muons.EtaCut=2.1
default_common.Muons.CombIsoCut=0.05
minDRMuonJetCut = RECO_MuonJetDRCut(0.5)
ZMassCut = RECO_2ndMuonMass(25.0, 91.2, False, "all")
CommonMHTovHT = OP_MHTovHT(0.4)
PFMTCut30 = RECO_PFMTCut(30.0)
alphaT = OP_HadAlphaTCut(0.55)
def cutFlow_sms(cutTreeMC) :
  # -----------------------------------------------------------------------------
  # Cut flow
  #cut flow SMS

  cutTreeMC.Attach(count_total)
  cutTreeMC.TAttach(count_total,smsFilter)#include T1 filter to correct the SMS files
  cutTreeMC.TAttach(smsFilter,selection)
  #normalization part
  # cutTreeMC.TAttach(smsFilter,plots_isr_unc_before)
  # cutTreeMC.TAttach(smsFilter,plots_smsScan_before)
  #common part
  cutTreeMC.TAttach(selection,oddMuon)
  cutTreeMC.TAttach(oddMuon,oddElectron)
  cutTreeMC.TAttach(oddElectron,oddPhoton)
  cutTreeMC.TAttach(oddPhoton,numComElectrons)
  cutTreeMC.TAttach(numComElectrons,numComMuons)
  cutTreeMC.TAttach(numComMuons,numComPhotons)
  cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
  cutTreeMC.TAttach(LeadingJetEta,badMuonInJet)
  cutTreeMC.TAttach(badMuonInJet,oddJet)
  cutTreeMC.TAttach(oddJet,numComJetsGeq2)
  cutTreeMC.TAttach(numComJetsGeq2,secondJetET)
  cutTreeMC.TAttach(secondJetET,htCut350)
  cutTreeMC.TAttach(htCut350,alphaT)
  cutTreeMC.TAttach(alphaT,deadECAL_MC)
  cutTreeMC.TAttach(deadECAL_MC,MHToverMET)
  #SMS part
  # cutTreeMC.TAttach(MHToverMET,htCutLess450)# HT < 450 GeV
  # cutTreeMC.TAttach(htCutLess450,plots_isr_unc_350)
  # cutTreeMC.TAttach(htCutLess450,plots_smsScan_350)
  # cutTreeMC.TAttach(MHToverMET,htCut450)#HT > 450 GeV
  # cutTreeMC.TAttach(htCut450,plots_isr_unc_450)
  # cutTreeMC.TAttach(htCut450,plots_smsScan_450)
mSuGra_plottingOps("tanB10")
def cutFlow_msugra(cutTreeMC) :
  #cut flow mSUGRA
  cutTreeMC.Attach(count_total)
  cutTreeMC.TAttach(count_total,selection)
  #normalization counting
  cutTreeMC.TAttach(count_total,plots_mSuGraScan_before_scale1)
  cutTreeMC.TAttach(count_total,plots_mSuGraScan_before_scale05)
  cutTreeMC.TAttach(count_total,plots_mSuGraScan_before_scale2)
  #common part
  cutTreeMC.TAttach(selection,oddMuon)
  cutTreeMC.TAttach(oddMuon,oddElectron)
  cutTreeMC.TAttach(oddElectron,oddPhoton)
  cutTreeMC.TAttach(oddPhoton,numComElectrons)
  cutTreeMC.TAttach(numComElectrons,numComMuons)
  cutTreeMC.TAttach(numComMuons,minDRMuonJetCut)
  cutTreeMC.TAttach(minDRMuonJetCut,ZMassCut)
  cutTreeMC.TAttach(ZMassCut,CommonMHTovHT)
  cutTreeMC.TAttach(CommonMHTovHT,PFMTCut30)
  cutTreeMC.TAttach(PFMTCut30,numComPhotons)
  cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
  cutTreeMC.TAttach(LeadingJetEta,badMuonInJet)
  cutTreeMC.TAttach(badMuonInJet,oddJet)
  cutTreeMC.TAttach(oddJet,numComJetsGeq2)
  cutTreeMC.TAttach(numComJetsGeq2,secondJetET)
  cutTreeMC.TAttach(secondJetET,alphaT)
  cutTreeMC.TAttach(alphaT,deadECAL_MC)
  cutTreeMC.TAttach(deadECAL_MC,MHToverMET)
  cutTreeMC.TAttach(MHToverMET,ht275)
  #mSUGRA part

  cutTreeMC.TAttach(MHToverMET,ht250)
  cutTreeMC.TAttach(ht250,htLess300)
  cutTreeMC.TAttach(htLess300,plots_mSuGraScan_250_300_scale2 )
  cutTreeMC.TAttach(htLess300,plots_mSuGraScan_250_300_scale05)
  cutTreeMC.TAttach(htLess300,plots_mSuGraScan_250_300_scale1 )
  cutTreeMC.TAttach(MHToverMET,ht300)
  cutTreeMC.TAttach(ht300,htLess350)
  cutTreeMC.TAttach(htLess350,plots_mSuGraScan_300_350_scale2 )
  cutTreeMC.TAttach(htLess350,plots_mSuGraScan_300_350_scale05)
  cutTreeMC.TAttach(htLess350,plots_mSuGraScan_300_350_scale1 )
  cutTreeMC.TAttach(MHToverMET,ht350)
  cutTreeMC.TAttach(ht350,htLess450)
  cutTreeMC.TAttach(htLess450,plots_mSuGraScan_350_450_scale2 )
  cutTreeMC.TAttach(htLess450,plots_mSuGraScan_350_450_scale05)
  cutTreeMC.TAttach(htLess450,plots_mSuGraScan_350_450_scale1 )
  cutTreeMC.TAttach(MHToverMET,ht450)
  cutTreeMC.TAttach(ht450,plots_mSuGraScan_450_scale2 )
  cutTreeMC.TAttach(ht450,plots_mSuGraScan_450_scale05)
  cutTreeMC.TAttach(ht450,plots_mSuGraScan_450_scale1 )

  cutTreeMC.TAttach(ht275,htLess325)# HT < 450 GeV cut
  cutTreeMC.TAttach(htLess325,plots_mSuGraScan_275_325_scale1)
  cutTreeMC.TAttach(htLess325,plots_mSuGraScan_275_325_scale05)
  cutTreeMC.TAttach(htLess325,plots_mSuGraScan_275_325_scale2)
  cutTreeMC.TAttach(MHToverMET,ht325) #HT > 450 GeV cut
  cutTreeMC.TAttach(ht325,htLess375)
  cutTreeMC.TAttach(htLess375,plots_mSuGraScan_325_375_scale1)
  cutTreeMC.TAttach(htLess375,plots_mSuGraScan_325_375_scale05)
  cutTreeMC.TAttach(htLess375,plots_mSuGraScan_325_375_scale2)
  cutTreeMC.TAttach(MHToverMET,ht375)
  cutTreeMC.TAttach(ht375,htLess475)
  cutTreeMC.TAttach(htLess475,plots_mSuGraScan_375_475_scale1)
  cutTreeMC.TAttach(htLess475,plots_mSuGraScan_375_475_scale05)
  cutTreeMC.TAttach(htLess475,plots_mSuGraScan_375_475_scale2)
  cutTreeMC.TAttach(MHToverMET,ht475)
  cutTreeMC.TAttach(ht475,htLess575)
  cutTreeMC.TAttach(htLess575,plots_mSuGraScan_475_575_scale1)
  cutTreeMC.TAttach(htLess575,plots_mSuGraScan_475_575_scale05)
  cutTreeMC.TAttach(htLess575,plots_mSuGraScan_475_575_scale2)
  cutTreeMC.TAttach(MHToverMET,ht575)
  cutTreeMC.TAttach(ht575,htLess675)
  cutTreeMC.TAttach(htLess675,plots_mSuGraScan_575_675_scale1)
  cutTreeMC.TAttach(htLess675,plots_mSuGraScan_575_675_scale05)
  cutTreeMC.TAttach(htLess675,plots_mSuGraScan_575_675_scale2)
  cutTreeMC.TAttach(MHToverMET,ht675)
  cutTreeMC.TAttach(ht675,htLess775)
  cutTreeMC.TAttach(htLess775,plots_mSuGraScan_675_775_scale1)
  cutTreeMC.TAttach(htLess775,plots_mSuGraScan_675_775_scale05)
  cutTreeMC.TAttach(htLess775,plots_mSuGraScan_675_775_scale2)
  cutTreeMC.TAttach(MHToverMET,ht775)
  cutTreeMC.TAttach(ht775,htLess875)
  cutTreeMC.TAttach(htLess875,plots_mSuGraScan_775_875_scale1)
  cutTreeMC.TAttach(htLess875,plots_mSuGraScan_775_875_scale05)
  cutTreeMC.TAttach(htLess875,plots_mSuGraScan_775_875_scale2)
  cutTreeMC.TAttach(MHToverMET,ht875)
  cutTreeMC.TAttach(ht875,plots_mSuGraScan_875_scale1)
  cutTreeMC.TAttach(ht875,plots_mSuGraScan_875_scale05)
  cutTreeMC.TAttach(ht875,plots_mSuGraScan_875_scale2)



from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
#vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP90ps.ps() )
#vbtMuonIdFilter      = Muon_IDFilter( vbtfmuonidps.ps() )
ra3PhotonIdFilter  = Photon_IDFilter( ra3photonidps.ps() )


muonfilt=CustomMuonId(muon_id.ps())

def addCutFlowMC(a,cutTreeMC) :
#  a.AddJetFilter("PreCC",JESUncert)
  a.AddMuonFilter("PostCC",muonfilt)
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a+=cutTreeMC




#*********************************************************************
#---------------------------------Main Program------------------------
#*********************************************************************



# some default definitions might to be overwritten later
deadECAL_MC =   OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START38_V12.txt")
smsFilter = genProcess("gg")



cutTreeMC = Tree("MC")

if switches()["model"] == "T1" or switches()["model"] == "T2" :
  sms_plottingOps(switches()["model"])
  cutFlow_sms(cutTreeMC)

if switches()["model"] == "tanB3" or switches()["model"] == "tanB10" or switches()["model"] ==  "tanB50"  :
  mSuGra_plottingOps(switches()["model"])
  cutFlow_msugra(cutTreeMC)

# Object ID filters
#-----------------------------------------------------------------------



#set JES_scale
if(switches()["jes_scale"] == "default") :
  JESUncert = JESUncert("")
if(switches()["jes_scale"] == "plus"):
  JESUncert = JESUncert("+ve")
if(switches()["jes_scale"] == "minus") :
  JESUncert = JESUncert("-ve")


 #MC sms
anal_ak5_caloMC =Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC,cutTreeMC)

anal_ak7_caloMC=Analysis("AK7Calo")
addCutFlowMC(anal_ak7_caloMC,cutTreeMC)
# -----------------------------------------------------------------------------
# Definition of analyses
from montecarlo.LMx import *

# Run analyses
if(switches()["model"] == "T1") :
  anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[PhysicsProcesses_TopologyT1_38xFall10_spadhi])
if(switches()["model"] == "T2") :
  anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[PhysicsProcesses_TopologyT2_38xFall10_spadhi_new])
if(switches()["model"] == "tanB3") :
  anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[PhysicsProcesses_mSUGRA_tanbeta3Fall10v1])
if(switches()["model"] == "tanB10") :
  anal_ak5_caloMC.Run("../resultsMuon4386",conf_ak5_calo_msugra,[PhysicsProcesses_mSUGRA_tanbeta10Fall10v1])
if(switches()["model"] == "tanB50") :
  anal_ak5_caloMC.Run("../results",conf_ak5_calo_msugra,[PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi])



#*********************************************************************
#---------------------------------End of Main Program------------------------q
#*********************************************************************
