#!/usr/bin/env python

# 1  = Data PROMPT RECO 36, 34.7/pb (sample size: 1=35/pb, 2=22/pb, 3=15/pb, 4=3/pb)
# 2 = QCD Pythia6, 36
# 3 = QCD Pythia6, 38
# 9 = QCD MadGraph (36?)
# 4 = LMx
# 5 = WJETS MC NO SKIM
# 6 = ZINV MC NO SKIM
# 7 = TTBAR MC NO SKIM
# 8 = Data RE-RECO 38, 36.1/pb

# 10 = MSUGRA, tanbeta3
# 11 = MSUGRA, tanbeta10
# 12 = MSUGRA, tanbeta50
# 13 = SMS, Topology T1
# 14 = SMS, Topology T2
# 15 = SMS, Topology T3
# 16 = SMS, Topology T4
# 17 = SMS, Topology T11
# 18 = SMS, Topology T21

# 101 = test with data
# 102 = test with QCD 36
# 103 = test with QCD 38
# 109 = test with QCD MG
# 105 = test with wjets
# 104 = test with LM1

# 110 = MSUGRA, tanbeta3
# 111 = MSUGRA, tanbeta10
# 112 = MSUGRA, tanbeta50
# 113 = SMS, T1
# 114 = SMS, T2
# 115 = SMS, T3
# 116 = SMS, T4

dataset=1

option=1
label = "110404"
NoQcdOption=False
NoCleaningInDenomOption=False
ScaleSignalOption=False

msugra_file = ""
if ( dataset == 10 or dataset == 110 ) :
      msugra_file = "scale_xsection_nlo1.0_tandat3.txt"
elif ( dataset == 11 or dataset == 111 ) :
      msugra_file = "scale_xsection_nlo1.0_tanssdat10.txt"
elif ( dataset == 12 or dataset == 112 ) :
      msugra_file = "scale_xsection_nlo1.0_tandat50.txt"
else :
      msugra_file = ""

samplesize=1

PfOption=False
FilterOption=3
VerboseOption=False
JetSmearOption=False
AddIdFilters=True
UseDeadEcalFileOption=False

# Make sure NoQCD is only set for QCD datasets
if ( dataset != 2 and dataset != 3 and dataset != 9 and dataset != 102 and dataset != 103 and dataset != 109 ) :
      NoQcdOption=False
      
print "NoQcdOption: ", NoQcdOption

ht_default = 350. 
meff_default = 500.
pt1_default = 100.
pt2_default = 100.
pt3_default = 50.

import commands
dir = commands.getoutput('echo $SUSY_WORKING_SW_DIR') + "/results/batch/"

optionStr=""
if ( option != 0 ) :
      optionStr="_"+str(option)

optionVeto = ""

OptionMuon = False
if ( optionVeto == "NoMuonVeto" ) :
      OptionMuon=True
elif ( optionVeto == "NoVetoes" ) :
      OptionMuon=True

extra = label+optionStr+"/"+str(int(pt1_default))+"_"+str(int(pt2_default))+"_"+str(int(pt3_default))+"/"
dir = dir+extra
print "dir = ",dir

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
      HtXhighOption=550.
elif ( option == 4 ) :
      ScaleOption=False
      NbinsOption=6
      HtXlowOption=250.
      HtXhighOption=550.
elif ( option == 5 ) :
      ScaleOption=True
      NbinsOption=15
      HtXlowOption=250.
      HtXhighOption=550.
elif ( option == 6 ) :
      ScaleOption=False
      NbinsOption=15
      HtXlowOption=250.
      HtXhighOption=550.
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
from hadronic.SweetBatchSub import *

from hadronic.samples_cff import *
from data.MultiJet_Run2010B_PromptReco_v2_408 import *

#from data.Jet_3pb_WithTP_run2010A import *
#from data.Jet_15pb_WithTP_json221010 import *
#from data.Jet_7pb_WithTP_json221010to291010 import *
#from data.Jet_22pb_WithTP_json291010 import *
#from data.Jet_13pb_WithTP_json291010to051110 import *
from data.Jet_35pb_WithTP_json051110 import *
from data.RA1_Complete_Run2010_Nov4ReReco_v1 import *

from montecarlo.LMx import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta3Fall10v1 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta10Fall10v1 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta50Fall10 import *
from montecarlo.PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi import *

from montecarlo.PhysicsProcesses_TopologyT1_38xFall10 import *
from montecarlo.PhysicsProcesses_TopologyT2_38xFall10_spadhi_new import *
from montecarlo.PhysicsProcesses_TopologyT3_38xFall10 import *
from montecarlo.PhysicsProcesses_TopologyT4_38xFall10 import *
from montecarlo.PhysicsProcesses_TopologyT11_38xFall10_spadhi import *
from montecarlo.PhysicsProcesses_TopologyT21_38xFall10_spadhi import *

from montecarlo.WJets_Madgraph_NNLO import *
from montecarlo.TTBarTauola_NNLO import *
from montecarlo.Zinvisible_jets_pset_NNLO import *
from montecarlo.Zjets_madgraph_NNLO import *

from montecarlo.QCD_Pythia6_ALL import * 
from montecarlo.QCD_Pythia6_384patch3_V14_00_02_ALL import *
from montecarlo.QCD_Madgraph_ALL import * 

qcdBkgdEstMC = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                                MinObjects=2,
                                MaxObjects=10,
                                Verbose=VerboseOption,
                                Filter=FilterOption,
                                UseGen=False,
                                pthat=False,
                                NoQCD=NoQcdOption,
                                NoCleaningInDenom=NoCleaningInDenomOption,
                                SusyScan=False,
                                SusyScanPSet=PSet(mSUGRAFile = msugra_file,
                                                  xBins = 30, # mSugra = 150, Topologies = 30
                                                  xLow =0.,
                                                  xHigh =1500.,
                                                  yBins =40, # mSugra = 100, Topologies = 40
                                                  yLow =0.,
                                                  yHigh =1000.,
                                                  zBins =40,
                                                  zLow =0.,
                                                  zHigh =1000.,
                                                  ),
                                MaxGenMet=1.,
                                MinGenJetPt=1.,
                                MaxJetEta=3.0,
                                MaxLeadingJetEta=2.5,
                                Scale=ScaleOption,
                                ScaleSignal=ScaleSignalOption,
                                BabyJetsCutType=BabyCutType,
                                BabyJetsCut=BabyCutVal,
                                UseDeadEcalFile=UseDeadEcalFileOption,
                                DeadEcalRegionsFile=commands.getoutput('echo $SUSY_WORKING_SW_DIR')+"/hadronic/python/deadRegionList_START38_V12.txt",
                                DeadEcalRegionDrCut=0.3,
                                MinJetPtCut=30.,
                                NBadCells=0,
                                DeadEcalFile=commands.getoutput('echo $SUSY_WORKING_SW_DIR')+"/hadronic/python/deadRegionList_START38_V12.txt",
                                MinBiasDeltaPhiCut=0.5,
                                AlphaT=[0.5,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,
                                        0.6,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,
                                        0.7],
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
                                MeffXhigh=550.,
                                AddMuonToMET=OptionMuon,).ps() )

qcdBkgdEstData = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                                  Inclusive=True,
                                  MinObjects=2,
                                  MaxObjects=10,
                                  Verbose=VerboseOption,
                                  Filter=FilterOption,
                                  UseGen=False,
                                  NoQCD=NoQcdOption,
                                  NoCleaningInDenom=NoCleaningInDenomOption,
                                  SusyScan=False,
                                  MaxGenMet=0.,
                                  MinGenJetPt=0.,
                                  MaxJetEta=3.0,
                                  MaxLeadingJetEta=2.5,
                                  Scale=ScaleOption,
                                  ScaleSignal=ScaleSignalOption,
                                  BabyJetsCutType=BabyCutType,
                                  BabyJetsCut=BabyCutVal,
                                  UseDeadEcalFile=UseDeadEcalFileOption,
                                  DeadEcalRegionsFile=commands.getoutput('echo $SUSY_WORKING_SW_DIR')+"/hadronic/python/deadRegionList_GR10_P_V10.txt",
                                  DeadEcalRegionDrCut=0.3,
                                  MinJetPtCut=30.,
                                  NBadCells=0,
                                  DeadEcalFile=commands.getoutput('echo $SUSY_WORKING_SW_DIR')+"/hadronic/python/deadRegionList_GR10_P_V10.txt",
                                  MinBiasDeltaPhiCut=0.5,
                                  AlphaT=[0.55,0.56,0.57,0.58,0.59,0.6],#,0.61,0.62,0.63,0.64,0.65,0.66,0.67,0.68,0.69,0.7],
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
                                  MeffXhigh=550.,
                                  AddMuonToMET=OptionMuon,).ps() )

cutTreeData = Tree("Data")
cutFlowData(cutTreeData,optionVeto)
cutTreeMC = Tree("MC")
cutFlowMC(cutTreeMC,optionVeto)

if ( optionVeto == "NoMuonVeto" ) :
      cutTreeData.TAttach(oddElectron,qcdBkgdEstData)
      cutTreeMC.TAttach(oddElectron,qcdBkgdEstMC)
elif ( optionVeto == "NoVetoes" ) :
      cutTreeData.TAttach(selection,qcdBkgdEstData)
      cutTreeMC.TAttach(selection,qcdBkgdEstMC)
else :
    cutTreeData.TAttach(oddMuon,qcdBkgdEstData)
    cutTreeMC.TAttach(oddMuon,qcdBkgdEstMC)
#    if ( dataset == 13 or dataset == 113 or dataset == 17 ) :
#          T1Filter = gensignalProcessID(PSet(IDs=[243,244]).ps())
#          if ( False ) :
#                t1_pre = ProcessIDPlottingOps(PSet(DirName="ProcessID_T1_pre").ps())
#                t1_post = ProcessIDPlottingOps(PSet(DirName="ProcessID_T1_post").ps())
#                cutTreeMC.TAttach(oddMuon,t1_pre)
#                cutTreeMC.TAttach(t1_pre,T1Filter)
#                cutTreeMC.TAttach(T1Filter,t1_post)
#                cutTreeMC.TAttach(t1_post,qcdBkgdEstMC)
#          else :
#                cutTreeMC.TAttach(oddMuon,T1Filter)
#                cutTreeMC.TAttach(T1Filter,qcdBkgdEstMC)
#    if ( dataset == 14 or dataset == 114 or dataset == 18 ) :
#          T2Filter = gensignalProcessID(PSet(IDs=[277,278,279,280]).ps())
#          if ( False ) :
#                t2_pre = ProcessIDPlottingOps(PSet(DirName="ProcessID_T2_pre").ps())
#                t2_post = ProcessIDPlottingOps(PSet(DirName="ProcessID_T2_post").ps())
#                cutTreeMC.TAttach(oddMuon,t2_pre)
#                cutTreeMC.TAttach(t2_pre,T2Filter)
#                cutTreeMC.TAttach(T2Filter,t2_post)
#                cutTreeMC.TAttach(t2_post,qcdBkgdEstMC)
#          else :
#                cutTreeMC.TAttach(oddMuon,T2Filter)
#                cutTreeMC.TAttach(T2Filter,qcdBkgdEstMC)
#    else :
#          cutTreeMC.TAttach(oddMuon,qcdBkgdEstMC)

if ( FilterOption > -1 ) : 
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

def addCutFlowData(a) :
      if ( AddIdFilters == True ) :
            a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
            a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
      #a.AddJetFilter("PreCC",JetCorrections)
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
if ( optionVeto == "NoElectronVeto" or
     optionVeto == "NoPhotonVeto" or
     optionVeto == "NoElectronPhotonVetoes" or
     optionVeto == "NoVetoes" ) :
      conf_ak5_calo.XCleaning.ElectronJet=False
      conf_ak5_calo.XCleaning.PhotonJet=False
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

samples = []

anal_str = "anal_ak5_caloMC"
conf_str = "conf_ak5_caloMC"
if ( PfOption == True ) :
      anal_str = "anal_ak5_pfMC"
      conf_str = "conf_ak5_pfMC"

if ( dataset == 1 ) : # PROMPT RECO 36
      if ( samplesize == 1 ) :
            data1 = [Jet_35pb_WithTP_json051110] # 160 files
            #data1 = [RA1_Complete_Run2010_Nov4ReReco_v1] # 2975 files
            if ( PfOption == False ) :
                  BatchRun(data1, "anal_ak5_caloData","conf_ak5_caloData",dir,1,dir) 
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
elif ( dataset == 2 ) : # QCD 36 
      MC2 = [QCD_AllPtBins_7TeV_Pythia]
      BatchRun(MC2,anal_str,conf_str,dir,1,dir) # 263 files
elif ( dataset == 3 ) : # QCD 38 
      BatchRun(QCD_Pythia6_384patch3_V14_00_02_ALL,anal_str,conf_str,dir,10,dir) # 1719 files
elif ( dataset == 9 ) : # QCD MG
      BatchRun(QCD_Madgraph_ALL,anal_str,conf_str,dir,1,dir) # 163 files
elif ( dataset == 4 ) :
      MC3 = [LM0,LM1]
      BatchRun(MC3,anal_str,conf_str,dir,10000,dir) 
elif ( dataset == 5 ) :
      MC4 = [wjets_madgraph_vols_expanded]
      BatchRun(MC4,anal_str,conf_str,dir,5,dir) # 207 files
elif ( dataset == 6 ) :
      MC5 = [Zinvisible_jets]
      BatchRun(MC5,anal_str,conf_str,dir,1,dir) # 22 files
elif ( dataset == 7 ) :
      MC6 = [ttbarTauola] 
      BatchRun(MC6,anal_str,conf_str,dir,1,dir) # 15 files
elif ( dataset == 8 ) : # RE-RECO 38
      data8 = [RA1_Complete_Run2010_Nov4ReReco_v1]
      if ( PfOption == False ) :
            BatchRun(data8, "anal_ak5_caloData","conf_ak5_caloData",dir,100,dir)
      else :
            BatchRun(data8, "anal_ak5_pfData","conf_ak5_pfData",dir,100,dir)

elif ( dataset == 10 ) :
      MC10 = [PhysicsProcesses_mSUGRA_tanbeta3Fall10v1]
      BatchRun(MC10,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,50,dir) # 651 files
elif ( dataset == 11 ) :
      MC11 = [PhysicsProcesses_mSUGRA_tanbeta10Fall10v1]
      BatchRun(MC11,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,150,dir) # 1666 files
elif ( dataset == 12 ) :
      MC12 = [PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi]
      BatchRun(MC12,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,50,dir) # 505 files
elif ( dataset == 13 ) :
      MC13 = [PhysicsProcesses_TopologyT1_38xFall10]
      BatchRun(MC13,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,5,dir) # 168 files
elif ( dataset == 14 ) :
      MC14 = [PhysicsProcesses_TopologyT2_38xFall10_spadhi_new]
      BatchRun(MC14,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,5,dir) # 168 files
elif ( dataset == 15 ) :
      MC15 = [PhysicsProcesses_TopologyT3_38xFall10]
      BatchRun(MC15,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,5,dir) # 186 files
elif ( dataset == 16 ) :
      MC16 = [PhysicsProcesses_TopologyT4_38xFall10]
      BatchRun(MC16,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,5,dir) # 186 files
elif ( dataset == 17 ) :
      MC17 = [PhysicsProcesses_TopologyT11_38xFall10_spadhi]
      BatchRun(MC17,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,1,dir) # 
elif ( dataset == 18 ) :
      MC18 = [PhysicsProcesses_TopologyT21_38xFall10_spadhi]
      BatchRun(MC18,"anal_ak5_caloMSUGRA","conf_ak5_caloMSUGRA",dir,1,dir) # 

# TESTS FOR DATA AND QCD MC:

elif ( dataset == 101 ) :
      path="/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/"
      tmp1 = PSet(
            Name = '_JetMET_Run2010A_PromptReco_v4_03092010',
            Format = ('ICF', 2),
            File = [
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_0_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_1_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_2_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_3_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_4_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_5_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_6_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_7_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_8_skim.root",
            path+"MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_9_skim.root",
            ],
            Weight=1.0,
            FirstEntry = 1,
            LastEntry = 100,
            )
      if ( PfOption == False ) :
            anal_ak5_caloData.Run(".",conf_ak5_caloData,[tmp1])
            #BatchRun([tmp1],anal_str,conf_str,dir,1,dir) 
      else :
            anal_ak5_pfData.Run(".",conf_ak5_pfData,[tmp1])

elif ( dataset == 1011 ) :
      tmp1011 = PSet(
            Name = '_JetMET_Run2010A_PromptReco_v4_03092010',
            Format = ('ICF', 2),
            File = [
            #"/vols/cms02/bainbrid/qcd/trigger/test/SUSY2/results/batch/110404_1/100_100_50/Skim_Jet_35pb_WithTP_json051110.root"
            #"/vols/cms02/bainbrid/qcd/trigger/2010/SUSY2/results/batch/110404_1/100_100_50/Skim_Jet_35pb_WithTP_json051110.root"
            "/vols/cms02/bainbrid/qcd/trigger/2010/SUSY2/hadronic/python/Skim_Jet_35pb_PromptReco.root"
            ],
            Weight=1.0,
            #FirstEntry = 1,
            #LastEntry = 100,
            )
      anal_ak5_caloData.Run(".",conf_ak5_caloData,[tmp1011])

elif ( dataset == 102 ) :
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
            #LastEntry = 10000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])

elif ( dataset == 103 ) :
      tmp = PSet(
            Name="QCD_Pythia6_38_AllPtBins",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2010_10_17_20_12_27//QCD_Pt_800to1000_TuneZ2_7TeV_pythia6.Fall10-START38_V12-v1.GEN-SIM-RECO//SusyCAF_Tree_100_1_u1V.root" ,
            ],
            CrossSection=48440000000.0,
            LastEntry = 10000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])

elif ( dataset == 109 ) :
      tmp2 = PSet(
            Name="QCD_Madgraph_ALL",
            Format=("ICF",2),
            File= [
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt-50To100_7TeV-madgraph.Spring10-START3X_V26-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt100to250-madgraph.Spring10-START3X_V26_S09-v2.GEN-SIM-RECO/SusyCAF_Tree_99_3.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt250to500-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_34_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt500to1000-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_3.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33/QCD_Pt1000toInf-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_2.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt500to1000-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_3.root",
            ],
            CrossSection=5200.,
            #LastEntry = 10000,
            )
      #anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp2])
      BatchRun([tmp2],anal_str,conf_str,dir,1,dir) 
      
elif ( dataset == 105 ) :
      tmp=PSet(
            Name="wjets_madgraph_vols",
            Events=10034822,
            Format=("ICF",2),
            File= [
            "/vols/cms02/jm1103/WJetsMadgraphJune10/WJets_madgraph_june2010_100.root",
            ],
            CrossSection=31314.0, # NLO
            LastEntry = 10000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])

elif ( dataset == 104 ) :

      tmp=PSet(
            Name="LM1",
            Events=100000,
            Format=("ICF",2),
            File= [
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/LM1.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            ],
            CrossSection=4.888,
            LastEntry = 1000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])


# SUSY TESTS

elif ( dataset == 110 ) :
      tmp=PSet(
            Name="PhysicsProcesses_mSUGRA_tanbeta3Fall10v1",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2010_11_10_19_34_17//SusyCAF_Tree_100_1_75v.root",
            ],
            CrossSection=0.,
            LastEntry = 1000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])

elif ( dataset == 111 ) :
      tmp=PSet(
            Name="PhysicsProcesses_mSUGRA_tanbeta10Fall10v1",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2010_11_07_00_18_19//SusyCAF_Tree_1000_1_UH4.root" ,
            ],
            CrossSection=0.,
            LastEntry = 1000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])
      
elif ( dataset == 112 ) :
      tmp=PSet(
            Name="PhysicsProcesses_mSUGRA_tanbeta50Fall10_spadhi",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/trommers//ICF/automated/2011_01_08_18_18_16/SusyCAF_Tree_100_1_h2E.root" ,
            ],
            CrossSection=0.,
            LastEntry = 1000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])
      
elif ( dataset == 113 ) :
      tmp=PSet(
            Name="PhysicsProcesses_TopologyT1_38xFall10",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_01_24_18_09_42///SusyCAF_Tree_100_1_myY.root" ,
            ],
            CrossSection=0.,
            LastEntry = 1000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])

elif ( dataset == 114 ) :
      tmp=PSet(
            Name="PhysicsProcesses_TopologyT2_38xFall10",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/elaird/ICF/automated/2011_03_08_23_04_26//SusyCAF_Tree_20_1_Ofi.root",
            ],
            CrossSection=0.,
            #LastEntry = 1000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])

elif ( dataset == 115 ) :
      tmp=PSet(
            Name="PhysicsProcesses_TopologyT3_38xFall10",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_01_25_21_33_22///SusyCAF_Tree_100_1_LOa.root" ,
            ],
            CrossSection=0.,
            LastEntry = 1000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])

elif ( dataset == 116 ) :
      tmp=PSet(
            Name="PhysicsProcesses_TopologyT4_38xFall10",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/henning//ICF/automated/2011_01_27_12_39_13///SusyCAF_Tree_100_1_hOd.root" ,
            ],
            CrossSection=0.,
            LastEntry = 10000,
            )
      anal_ak5_caloMSUGRA.Run(".",conf_ak5_caloMSUGRA,[tmp])

