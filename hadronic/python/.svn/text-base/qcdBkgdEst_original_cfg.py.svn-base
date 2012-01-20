#!/usr/bin/env python

# 1  = Data PROMPT RECO 36, 34.7/pb (sample size: 1=35/pb, 2=22/pb, 3=15/pb, 4=3/pb)
# 10 = Data RE-RECO 38, 36.1/pb
# 2 = QCD Pythia6, 36
# 3 = QCD Pythia6, 38
# 4 = LMx
# 5 = WJETS MC NO SKIM
# 6 = ZINV MC NO SKIM
# 7 = TTBAR MC NO SKIM
# 8 = MSUGRA

# 9 = test with data
# 11 = test with QCD 36
# 12 = test with QCD 38
# 12 = test with QCD MG

dataset=9
option=1

samplesize=1

PfOption=False

FilterOption=False
VerboseOption=False
JetSmearOption=False
AddIdFilters=True
UseDeadEcalFileOption=False

mSugraOption=False
if ( dataset == 8 ) :
      mSugraOption=True

ht_default = 350.
meff_default = 500.
pt1_default = 100.
pt2_default = 100.
pt3_default = 50.

dir ="/vols/cms02/bainbrid/qcd/SUSY2/results/batch/"

optionStr=""
if ( option != 0 ) :
      optionStr="_"+str(option)

extra = "101209"+optionStr+"/"+str(int(pt1_default))+"_"+str(int(pt2_default))+"_"+str(int(pt3_default))+"/"
dir = dir+extra
print dir

babycut=5 # 1 = MHT-pfMET/Meff, 2 = MHT-caloMET/Meff, 3 = MHT/caloMET, 4 = MHT(50)/MHT(10), 5 = MHT(350)/MET

BabyCutType=0
BabyCutVal=0.
if ( babycut == 1 ) :
      BabyCutType=1
      BabyCutVal=0.125
elif ( babycut == 2 ) :
      BabyCutType=2
      BabyCutVal=0.125
elif ( babycut == 3 ) :
      BabyCutType=3
      BabyCutVal=1.25
elif ( babycut == 4 ) :
      BabyCutType=4
      BabyCutVal=1.25
elif ( babycut == 5 ) :
      if ( PfOption == False ) :
            BabyCutType=5
            BabyCutVal=1.25
      else :
            BabyCutType=6
            BabyCutVal=1.25
      
ScaleOption=True
NbinsOption=3
HtXlowOption=250.
HtXhighOption=400.
if ( option == 1 ) :
      ScaleOption=True
      NbinsOption=3
      HtXlowOption=250.
      HtXhighOption=400.
elif ( option == 2 ) :
      ScaleOption=False
      NbinsOption=3
      HtXlowOption=250.
      HtXhighOption=400.
elif ( option == 3 ) :
      ScaleOption=True
      NbinsOption=6
      HtXlowOption=250.
      HtXhighOption=400.
elif ( option == 4 ) :
      ScaleOption=False
      NbinsOption=6
      HtXlowOption=250.
      HtXhighOption=400.
elif ( option == 5 ) :
      ScaleOption=True
      NbinsOption=21
      HtXlowOption=250.
      HtXhighOption=460.
elif ( option == 6 ) :
      ScaleOption=False
      NbinsOption=21
      HtXlowOption=250.
      HtXhighOption=460.
elif ( option == 7 ) :
      ScaleOption=True
      NbinsOption=41
      HtXlowOption=250.
      HtXhighOption=455.
elif ( option == 8 ) :
      ScaleOption=False
      NbinsOption=41
      HtXlowOption=250.
      HtXhighOption=455.
elif ( option == 9 ) :
      ScaleOption=True
      NbinsOption=61
      HtXlowOption=250.
      HtXhighOption=555.
elif ( option == 10 ) :
      ScaleOption=False
      NbinsOption=61
      HtXlowOption=250.
      HtXhighOption=555.
elif ( option == 11 ) :
      ScaleOption=True
      NbinsOption=91
      HtXlowOption=250.
      HtXhighOption=705.
elif ( option == 12 ) :
      ScaleOption=False
      NbinsOption=91
      HtXlowOption=250.
      HtXhighOption=705.
      
import setupSUSY
from hadronic.rob_golden_cff import * ## @@ USE HADRONIC VERSION!!! (ADAPTED!!!)
from SweetBatchSub import *

from hadronic.samples_cff import *
from data.MultiJet_Run2010B_PromptReco_v2_408 import *

from data.Jet_3pb_WithTP_run2010A import *
from data.Jet_15pb_WithTP_json221010 import *
from data.Jet_7pb_WithTP_json221010to291010 import *
from data.Jet_22pb_WithTP_json291010 import *
from data.Jet_13pb_WithTP_json291010to051110 import *
from data.Jet_35pb_WithTP_json051110 import *
from data.RA1_Complete_Run2010_Nov4ReReco_v1 import *

from montecarlo.LMx import *
from montecarlo.tanBeta10 import *

from montecarlo.WJets_Madgraph_NNLO import *
from montecarlo.TTBarTauola_NNLO import *
from montecarlo.Zinvisible_jets_pset_NNLO import *
from montecarlo.Zjets_madgraph_NNLO import *

from montecarlo.QCD_Pythia6_ALL import * 
from montecarlo.QCD_Pythia6_384patch3_V14_00_02_ALL import *

qcdBkgdEstMC = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                                MinObjects=2,
                                MaxObjects=10,
                                Verbose=VerboseOption,
                                Filter=FilterOption,
                                UseGen=True,
                                mSugra=mSugraOption,
                                mSugraOnly=mSugraOption,
                                MaxGenMet=1.,
                                MinGenJetPt=1.,
                                MaxJetEta=3.0,
                                MaxLeadingJetEta=2.5,
                                Scale=ScaleOption,
                                BabyJetsCutType=BabyCutType,
                                BabyJetsCut=BabyCutVal,
                                UseDeadEcalFile=UseDeadEcalFileOption,
                                DeadEcalRegionsFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_START38_V12.txt",
                                DeadEcalRegionDrCut=0.3,
                                MinJetPtCut=30.,
                                NBadCells=0,
                                DeadEcalFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_START38_V12.txt",
                                MinBiasDeltaPhiCut=0.5,
                                AlphaT=[0.5,0.501,0.502,0.503,0.504,0.505,
                                        0.51,0.515,0.52,0.525,0.53,0.535,0.54,0.545,0.55,
                                        0.555,0.56,0.565,0.57,0.575,0.58,0.585,0.59,0.595,
                                        0.6,0.7,0.8,0.9,
                                        1.,2.,3.,4.,5.],
                                HT=ht_default,
                                Meff=meff_default,
                                MinJetPt1=pt1_default,
                                MinJetPt2=pt2_default,
                                MinJetPt3=pt3_default,
                                HtNbins=NbinsOption,
                                HtXlow=HtXlowOption,
                                HtXhigh=HtXhighOption,
                                MeffNbins=NbinsOption,
                                MeffXlow=400.,
                                MeffXhigh=550.,).ps() )

qcdBkgdEstData = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                                  MinObjects=2,
                                  MaxObjects=10,
                                  Verbose=VerboseOption,
                                  Filter=FilterOption,
                                  UseGen=False,
                                  mSugra=mSugraOption,
                                  mSugraOnly=mSugraOption,
                                  MaxGenMet=0.,
                                  MinGenJetPt=0.,
                                  MaxJetEta=3.0,
                                  MaxLeadingJetEta=2.5,
                                  Scale=ScaleOption,
                                  BabyJetsCutType=BabyCutType,
                                  BabyJetsCut=BabyCutVal,
                                  UseDeadEcalFile=UseDeadEcalFileOption,
                                  DeadEcalRegionsFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_GR10_P_V10.txt",
                                  DeadEcalRegionDrCut=0.3,
                                  MinJetPtCut=30.,
                                  NBadCells=0,
                                  DeadEcalFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_GR10_P_V10.txt",
                                  MinBiasDeltaPhiCut=0.5,
                                  AlphaT=[0.5,0.501,0.502,0.503,0.504,0.505,
                                          0.51,0.515,0.52,0.525,0.53,0.535,0.54,0.545,0.55,
                                          0.555,0.56,0.565,0.57,0.575,0.58,0.585,0.59,0.595,
                                          0.6,0.7,0.8,0.9,
                                          1.,2.,3.,4.,5.],
                                  HT=ht_default,
                                  Meff=meff_default,
                                  MinJetPt1=pt1_default,
                                  MinJetPt2=pt2_default,
                                  MinJetPt3=pt3_default,
                                  HtNbins=NbinsOption,
                                  HtXlow=HtXlowOption,
                                  HtXhigh=HtXhighOption,
                                  MeffNbins=NbinsOption,
                                  MeffXlow=400.,
                                  MeffXhigh=550.,).ps() )

cutTreeData.TAttach(oddMuon,qcdBkgdEstData)
cutTreeMC.TAttach(oddMuon,qcdBkgdEstMC)

if ( FilterOption == True ) : 
      skim_ps = PSet(
            SkimName = "Skim",
            Branches = [""],
            DropBranches = False,
            )
      skimMC = SkimOp( skim_ps.ps() )
      skimData = SkimOp( skim_ps.ps() )
      cutTreeData.TAttach(qcdBkgdEstData,skimData)
      cutTreeMC.TAttach(qcdBkgdEstMC,skimMC)

from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )

from icf.JetCorrections import *
ps = PSet
if ( PfOption == False ) :
      ps = CorrectionPset("ResidualJetEnergyCorrections.txt")
else :
      ps = CorrectionPset("Spring10DataV2_L2L3Residual_AK5PF.txt")
JetCorrections = JESCorrections( ps.ps(), False )

def addCutFlowData(a) :
      if ( AddIdFilters == True ) :
            a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
            a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
      a.AddJetFilter("PreCC",JetCorrections)
      a+=cutTreeData
      
def addCutFlowMC(b) :
      if ( AddIdFilters == True ) :
            b.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
            b.AddElectronFilter("PreCC",vbtfElectronIdFilter)
      if ( JetSmearOption == True ) :
            JetSmear = JetSmear(0.1,50)
            b.AddJetFilter("PreCC",JetSmear)
      b+=cutTreeMC

# -----------------------------------------------------------------------------
# Analyses

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
conf_ak5_caloData.Common.print_out()
anal_ak5_caloData=Analysis("Ratio")
addCutFlowData(anal_ak5_caloData)

conf_ak5_caloMC = deepcopy(defaultConfig)
conf_ak5_caloMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMC.XCleaning = deepcopy(default_cc)
conf_ak5_caloMC.Common = deepcopy(default_common)
conf_ak5_caloMC.Common.print_out()
anal_ak5_caloMC=Analysis("Ratio")
addCutFlowMC(anal_ak5_caloMC)

conf_ak5_caloMSUGRA = deepcopy(defaultConfig)
conf_ak5_caloMSUGRA.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloMSUGRA.Ntuple.Weight = "mSuGra"
conf_ak5_caloMSUGRA.XCleaning = deepcopy(default_cc)
conf_ak5_caloMSUGRA.Common = deepcopy(default_common)
conf_ak5_caloMSUGRA.Common.print_out()
anal_ak5_caloMSUGRA=Analysis("Ratio")
addCutFlowMC(anal_ak5_caloMSUGRA)

conf_ak5_pfData = deepcopy(defaultConfig)
conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfData.XCleaning = deepcopy(default_cc)
conf_ak5_pfData.XCleaning.Muons.ModifyJetEnergy=False
conf_ak5_pfData.Common = deepcopy(default_common)
conf_ak5_pfData.Common.Jets.TightID=True
conf_ak5_pfData.Common.print_out()
anal_ak5_pfData=Analysis("Ratio")
addCutFlowData(anal_ak5_pfData)

conf_ak5_pfMC = deepcopy(defaultConfig)
conf_ak5_pfMC.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfMC.XCleaning = deepcopy(default_cc)
conf_ak5_pfMC.XCleaning.Muons.ModifyJetEnergy=False
conf_ak5_pfMC.Common = deepcopy(default_common)
conf_ak5_pfMC.Common.Jets.TightID=True
conf_ak5_pfMC.Common.print_out()
anal_ak5_pfMC=Analysis("Ratio")
addCutFlowMC(anal_ak5_pfMC)

conf_ak5_pfMSUGRA = deepcopy(defaultConfig)
conf_ak5_pfMSUGRA.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfMSUGRA.Ntuple.Weight = "mSuGra"
conf_ak5_pfMSUGRA.XCleaning = deepcopy(default_cc)
conf_ak5_pfMSUGRA.XCleaning.Muons.ModifyJetEnergy=False
conf_ak5_pfMSUGRA.Common = deepcopy(default_common)
conf_ak5_pfMSUGRA.Common.Jets.TightID=True
conf_ak5_pfMSUGRA.Common.print_out()
anal_ak5_pfMSUGRA=Analysis("Ratio")
addCutFlowMC(anal_ak5_pfMSUGRA)

conf_ak5_genMC = deepcopy(defaultConfig)
conf_ak5_genMC.Ntuple = deepcopy(ak5_calo)
conf_ak5_genMC.XCleaning = deepcopy(default_cc)
conf_ak5_genMC.Common = deepcopy(default_common)
conf_ak5_genMC.Common.print_out()
anal_ak5_caloMC=Analysis("Ratio")
addCutFlowMC(anal_ak5_caloMC)

samples = []

anal_str = "anal_ak5_caloMC"
conf_str = "conf_ak5_caloMC"
if ( PfOption == True ) :
      anal_str = "anal_ak5_pfMC"
      conf_str = "conf_ak5_pfMC"

if ( dataset == 1 ) : # PROMPT RECO 36
      if ( samplesize == 1 ) :
            data1 = [Jet_35pb_WithTP_json051110]
            if ( PfOption == False ) :
                  BatchRun(data1, "anal_ak5_caloData","conf_ak5_caloData",dir,5,dir)
            else :
                  BatchRun(data1, "anal_ak5_pfData","conf_ak5_pfData",dir,5,dir)
      elif ( samplesize == 2 ) :
            data2 = [Jet_22pb_WithTP_json291010]
            if ( PfOption == False ) :
                  BatchRun(data2, "anal_ak5_caloData","conf_ak5_caloData",dir,5,dir)
            else :
                  BatchRun(data2, "anal_ak5_pfData","conf_ak5_pfData",dir,5,dir)
      elif ( samplesize == 3 ) :
            data3 = [Jet_15pb_WithTP_json221010]
            if ( PfOption == False ) :
                  BatchRun(data3, "anal_ak5_caloData","conf_ak5_caloData",dir,5,dir)
            else :
                  BatchRun(data3, "anal_ak5_pfData","conf_ak5_pfData",dir,5,dir)
      elif ( samplesize == 4 ) :
            data4 = [Jet_3pb_WithTP_run2010A]
            if ( PfOption == False ) :
                  BatchRun(data4, "anal_ak5_caloData","conf_ak5_caloData",dir,5,dir)
            else :
                  BatchRun(data4, "anal_ak5_pfData","conf_ak5_pfData",dir,5,dir)
if ( dataset == 10 ) : # RE-RECO 38
      data10 = [RA1_Complete_Run2010_Nov4ReReco_v1]
      if ( PfOption == False ) :
            BatchRun(data10, "anal_ak5_caloData","conf_ak5_caloData",dir,100,dir)
      else :
            BatchRun(data10, "anal_ak5_pfData","conf_ak5_pfData",dir,100,dir)
elif ( dataset == 2 ) : # QCD 36 
      MC2 = [QCD_AllPtBins_7TeV_Pythia]
      BatchRun(MC2,anal_str,conf_str,dir,5,dir)
elif ( dataset == 3 ) : # QCD 38 
      BatchRun(QCD_Pythia6_384patch3_V14_00_02_ALL,anal_str,conf_str,dir,10,dir)
elif ( dataset == 4 ) :
      MC3 = [LM0,LM1]
      BatchRun(MC3,anal_str,conf_str,dir,10000,dir) 
elif ( dataset == 5 ) :
      MC4 = [wjets_madgraph_vols_expanded]
      BatchRun(MC4,anal_str,conf_str,dir,5,dir)
elif ( dataset == 6 ) :
      MC5 = [Zinvisible_jets]
      BatchRun(MC5,anal_str,conf_str,dir,3,dir)
elif ( dataset == 7 ) :
      MC6 = [ttbarTauola]
      BatchRun(MC6,anal_str,conf_str,dir,1,dir)
elif ( dataset == 8 ) :
      MC7 = [tanB10]
      if ( PfOption == False ) :
            BatchRun(MC7,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,5,dir)
      else :
            BatchRun(MC7,"anal_ak5_pfMSUGRA","conf_ak5_pfMSUGRA",dir,5,dir)

# TESTS FOR DATA AND QCD MC:

elif ( dataset == 9 ) :
      tmp = PSet(
            Name = '_JetMET_Run2010A_PromptReco_v4_03092010',
            Format = ('ICF', 2),
            File = [
            #"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_0_skim.root",
            "/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_0_skim.root",
            ],
            Weight=1.0,
            LastEntry = 1000,
            )
      if ( PfOption == False ) :
            anal_ak5_pfData.Run(".",conf_ak5_pfData,[tmp])
      else :
            anal_ak5_pfData.Run(".",conf_ak5_pfData,[tmp])
elif ( dataset == 11 ) :
      tmp = PSet(
            Name="QCD_Pythia6_AllPtBins",
            Format=("ICF",2),
            File=[
            "/vols/cms02/gouskos/QCD_Pythia_Pt470_Jun2010/SusyCAF_Tree_10_1_wU8.root",
            ],
            Weights = PSet(
            CrossSection = [8.762e+08,6.041e+07,9.238e+05,2.547e+04,1.256e+03,8.798e+01,2.186,0.01122],
            Events=[6095857,5069664,2065792,3171950,2976108,2159497,2181700,1185024],
            PtBin = [15.,30.,80.,170.,300., 470.,800.,1400.],
            ),
            LastEntry = 1000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])
elif ( dataset == 12 ) :
      tmp = PSet(
            Name="QCD_Pythia6_38_AllPtBins",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2010_10_17_20_12_27//QCD_Pt_800to1000_TuneZ2_7TeV_pythia6.Fall10-START38_V12-v1.GEN-SIM-RECO//SusyCAF_Tree_100_1_u1V.root" ,
            #"root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2010_10_18_17_55_22//QCD_Pt_470to600_TuneZ2_7TeV_pythia6.Fall10-START38_V12-v1.GEN-SIM-RECO//SusyCAF_Tree_100_2_GlB.root" ,
            ],
            CrossSection=48440000000.0,
            #LastEntry = 1000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])
elif ( dataset == 13 ) :
      tmp = PSet(
            Name="QCD_MadGraph",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt500to1000-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_26_2.root",
            ],
            CrossSection=5200.,
            LastEntry = 1000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])


