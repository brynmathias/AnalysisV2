#!/usr/bin/env python

#-----------------------------------------------------------------
# Includes
from golden_cff import *
from icf.core import PSet
from libHadronic import *
#from SweetBatchSub import *
from hadronic.commonIncludes import *
from libSUSYSignalScan import *
from validation.cutCounters_cff import * #TW for convenience...
from copy import deepcopy
from SUSYSignalScan.plottingStuff_cfg import tripleScale,smsOps,addBinnedStuff,isCmssm,isSms
from hadronic.samples_cff import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta10Fall10v1 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta3Fall10v1 import *
from SUSYSignalScan.utils import *
import os

mu_id = PSet(
   MuID = "Tight",
   MinPt = 10.,
   MaxEta = 2.5,
   MaxIsolation = 0.1,
   DRMuJet = 0.3,
   MaxGlbTrkDxy = 0.02,
   MinGlbTrkNumOfValidHits = 11,
   SegMatch2GlbMu = 1,
   PixelHitsOnInrTrk = 1,
   MaxInrTrkDz = 1.,
   doJetLoop = False,
   )


def mkdir(path) :
  try: os.makedirs(path)
  except OSError as e :
    if e.errno!=17 : raise e

def checkSwitches(d) :
  assert d["model"] in ["T1","T2","tanB3","tanB10","tanB40","tanB50"]
  assert d["jes"] in ["","+ve","-ve"]
  assert isCmssm(d["model"]) or isSms(d["model"])

def switches() :
  d = {}
  d["model"] = ["tanB3", "tanB10", "tanB40", "tanB50", "T1", "T2"][1]
  d["selection"] = ["had", "muon"][0]
  d["thresholds"] = [(36.7, 73.7), (43.3, 86.7), (50.0, 100.0)][2]
  d["jes"] = ["", "+ve", "-ve"][0]
  checkSwitches(d)
  return d

default_common.Jets.PtCut = switches()["thresholds"][0]
secondJetET = OP_SecondJetEtCut(switches()["thresholds"][1])
numComPhotons = OP_NumComPhotons("<=",0)
deadECAL_MC = OP_DeadECALCut(0.3,0.3,0.5,30.,10,1,"./deadRegionList_START38_V12.txt")
JESUncert = JESUncert(switches()["jes"])
alphaT70 = OP_HadAlphaTCut(0.70)
alphaT55 = OP_HadAlphaTCut(0.55)
alphaT53 = OP_HadAlphaTCut(0.53)

if switches()["selection"]=="muon" :
  from libOneLepton import *
  from libWPol import *
  from wpol.muon_config import muon_id

  numComMuons = OP_NumComMuons('==',1)
  default_common.Muons.PtCut=10.0
  default_common.Muons.EtaCut=2.1
  default_common.Muons.CombIsoCut=0.1
  minDRMuonJetCut = RECO_MuonJetDRCut(0.5)
  ZMassCut = RECO_2ndMuonMass(25.0, 91.2, False, "all")
  CommonMHTovHT = OP_MHTovHT(0.4)
  PFMTCut30 = RECO_PFMTCut(30.0)
  alphaT = OP_HadAlphaTCut(0.55)


def cutFlow(cutTreeMC, model) :
  out = []

  cutTreeMC.Attach(count_total)
  if isCmssm(model) :
    cutTreeMC.TAttach(count_total,selection)
    out.append( tripleScale(model = switches()["model"], cutTree = cutTreeMC, cut = count_total, label = "before") )
  elif isSms(model) :
  #  cutTreeMC.TAttach(count_total,smsFilter)
    out.append( smsOps(model = switches()["model"], cutTree = cutTreeMC, cut =
    count_total, label = "before") )
    cutTreeMC.TAttach(count_total,selection)

  if switches()["selection"]!="muon" :
    cutTreeMC.TAttach(selection,oddMuon)
    cutTreeMC.TAttach(oddMuon,oddElectron)
    cutTreeMC.TAttach(oddElectron,oddPhoton)
    cutTreeMC.TAttach(oddPhoton,numComLeptons)
    cutTreeMC.TAttach(numComLeptons,numComPhotons)
    cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
    cutTreeMC.TAttach(LeadingJetEta,badMuonInJet)
    cutTreeMC.TAttach(badMuonInJet,oddJet)
    cutTreeMC.TAttach(oddJet,numComJetsGeq2)
    cutTreeMC.TAttach(numComJetsGeq2,secondJetET)
    cutTreeMC.TAttach(secondJetET,deadECAL_MC)
    cutTreeMC.TAttach(deadECAL_MC,MHToverMET)
    cutTreeMC.TAttach(MHToverMET,alphaT)
    cutTreeMC.TAttach(MHToverMET,alphaT70)
    cutTreeMC.FAttach(alphaT70,alphaT55)
    cutTreeMC.FAttach(alphaT55,alphaT53)
  else :
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
    cutTreeMC.TAttach(secondJetET,deadECAL_MC)
    cutTreeMC.TAttach(deadECAL_MC,MHToverMET)
    cutTreeMC.TAttach(MHToverMET,alphaT)
    cutTreeMC.TAttach(MHToverMET,alphaT70)
    cutTreeMC.FAttach(alphaT70,alphaT55)
    cutTreeMC.FAttach(alphaT55,alphaT53)
  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT,
                            htBins = [250, 300, 350, 450],
                            label2 = "") )
  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT,
                            htBins = [275, 325] + [375+100*i for i in range(6)],
                            label2 = ""))

  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT53,
                            htBins = [250, 300, 350, 450],
                            label2 = "AlphaT53_55_") )

  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT53,
                            htBins = [275, 325] + [375+100*i for i in range(6)],
                            label2 = "AlphaT53_55_"))

  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT55,
                            htBins = [250, 300, 350, 450],
                            label2 = "AlphaT55_70_") )

  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT55,
                            htBins = [275, 325] + [375+100*i for i in range(6)],
                            label2 = "AlphaT55_70_"))

  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT70,
                            htBins = [250, 300, 350, 450],
                            label2 = "AlphaT70_inf") )

  out.append( addBinnedStuff(model = switches()["model"],
                            cutTree = cutTreeMC,
                            cut = alphaT70,
                            htBins = [275, 325] + [375+100*i for i in range(6)],
                            label2 = "AlphaT70_inf_"))
  return out

from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
#vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP90ps.ps() )
ra3PhotonIdFilter  = Photon_IDFilter( ra3photonidps.ps() )

muonfilt = CustomVBTFMuID(mu_id.ps()) if switches()["selection"]=="muon" else Muon_IDFilter( vbtfmuonidps.ps() )
# muonfilt = Muon_IDFilter(vbtfmuonidps.ps())
import os
susydir = os.environ['SUSY_WORKING_SW_DIR'] + '/'
if isCmssm(switches()["model"]) :
    if switches()["model"] == "tanB10": LOweights = SignalScanLOCrossSectionWeighting(xsToPSet( readLOXS(susydir+"SUSYSignalScan/textfiles/goodModelNames_10_0_1.txt") ).ps())
    if switches()["model"] == "tanB40": LOweights = SignalScanLOCrossSectionWeighting(xsToPSet( readLOXS(susydir+"SUSYSignalScan/textfiles/goodModelNames_40_m500_1.txt") ).ps())

def addCutFlowMC(a,cutTreeMC) :
  if "tan" in switches()["model"]:a.AddWeightFilter("Weight",LOweights)
  if switches()["jes"] != "":
    a.AddJetFilter("PreCC",JESUncert)
  a.AddMuonFilter("PreCC",muonfilt); print "WARNING: should this be PreCC?"
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a+=cutTreeMC

#*********************************************************************
#---------------------------------Main Program------------------------
#*********************************************************************
cutTreeMC = Tree("MC")
stuff = cutFlow(cutTreeMC, model = switches()["model"])

#MC sms
anal_ak5_caloMC =Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC,cutTreeMC)
from SUSYSignalScan.mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1 import *
from SUSYSignalScan.mSUGRA_m0_20to2000_m12_20to760_tanb_40andA0_m500_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FSIM_v1 import *
from SUSYSignalScan.SMS_T1 import *
def outputDir() :
  o = "../results_WithPdfUnCert_%s_%s_%g_%s"%(switches()["selection"], switches()["model"], switches()["thresholds"][1],switches()["jes"])
  mkdir(o)
  return o

def sample() :
  if isCmssm(switches()["model"]) :
    if switches()["model"] == "tanB10":return mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1
    if switches()["model"] == "tanB40":return mSUGRA_m0_20to2000_m12_20to760_tanb_40andA0_m500_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FSIM_v1
  elif isSms(switches()["model"]) : return SMS_T1
  else :         return None

sample().File = sample().File[0:5]
print sample().File
anal_ak5_caloMC.Run(outputDir(), conf_ak5_calo_msugra,[sample()])
