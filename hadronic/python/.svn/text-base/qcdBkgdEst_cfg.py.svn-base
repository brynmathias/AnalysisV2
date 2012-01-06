#!/usr/bin/env python

# 1 = TEST data
# 2 = TEST QCD MC,
# 3 = Data
# 4 = QCD MC
# 5 = QCD EWK + LMx # @@ DO NOT SPLIT THESE JOBS!!!!!

sample=1
option=0

VerboseOption=False
FilterOption=True
JetSmearOption=False

ScaleOption=False
NbinsOption=3
if ( option == 1 ) :
      ScaleOption=True
      NbinsOption=3
elif ( option == 2 ) :
      ScaleOption=False
      NbinsOption=3
elif ( option == 3 ) :
      ScaleOption=True
      NbinsOption=6
elif ( option == 4 ) :
      ScaleOption=False
      NbinsOption=6

optionStr=""
if ( option != 0 ) :
      optionStr="_"+str(option)
      
ht_default = 350.
meff_default = 500.
pt1_default = 100.
pt2_default = 100.
pt3_default = 50.

dir ="/vols/cms02/bainbrid/qcd/SUSY2/results/batch/"

extra = "010101"+optionStr+"/"+str(int(pt1_default))+"_"+str(int(pt2_default))+"_"+str(int(pt3_default))+"/"
dir = dir+extra
print dir

import os
import errno
def ensure_dir(path) :
      try:
            os.makedirs(path)
      except OSError as exc: # Python >2.5
            if exc.errno == errno.EEXIST:
                  pass
            else: raise
ensure_dir(dir)

import setupSUSY
from hadronic.rob_golden_cff import * ## @@ USE HADRONIC VERSION!!! (ADAPTED!!!)
from SweetBatchSub import *

from montecarlo.LMx import *
from montecarlo.w_jets_mg_edwardSkim import *
from montecarlo.z_inv_mg_edwardSkim import *
from montecarlo.TTBarTauola_NNLO import *
from montecarlo.QCD_Pythia6_ALL import *
from data.edward_data_skim_allJetTo_Json151010 import *

qcdBkgdEstMC = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                                MinObjects=2,
                                MaxObjects=10,
                                Verbose=VerboseOption,
                                Filter=FilterOption,
                                UseGen=True,
                                MaxGenMet=1.,
                                MinGenJetPt=1.,
                                MaxJetEta=3.0,
                                MaxLeadingJetEta=2.5,
                                Scale=ScaleOption,
                                BabyJetsCut=0.15,
                                DeadEcalRegionsFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_START38_V12.txt",
                                DeadEcalRegionDrCut=0.3,
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
                                HtXlow=250.,
                                HtXhigh=400.,
                                MeffNbins=NbinsOption,
                                MeffXlow=400.,
                                MeffXhigh=550.,).ps() )

qcdBkgdEstData = QcdBkgdEst( PSet(DirName = "QcdBkgdEst",
                                  MinObjects=2,
                                  MaxObjects=10,
                                  Verbose=VerboseOption,
                                  Filter=FilterOption,
                                  UseGen=False,
                                  MaxGenMet=0.,
                                  MinGenJetPt=0.,
                                  MaxJetEta=3.0,
                                  MaxLeadingJetEta=2.5,
                                  Scale=ScaleOption,
                                  BabyJetsCut=0.15,
                                  DeadEcalRegionsFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_GR10_P_V10.txt",
                                  DeadEcalRegionDrCut=0.3,
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
                                  HtXlow=250.,
                                  HtXhigh=400.,
                                  MeffNbins=NbinsOption,
                                  MeffXlow=400.,
                                  MeffXhigh=550.,).ps() )


#cutTreeData.TAttach(htCut,qcdBkgdEstData)
#cutTreeMC.TAttach(htCut,qcdBkgdEstMC)
cutTreeData.TAttach(numComPhotons,qcdBkgdEstData)
cutTreeMC.TAttach(numComPhotons,qcdBkgdEstMC)

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

def addCutFlowData(a) :
      a.AddJetFilter("PreCC",JetCorrections)
      a+=cutTreeData
      
def addCutFlowMC(b) :
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

samples = []

if ( sample == 1 ) : # Test Data

      tmp = PSet(
            Name = '_JetMET_Run2010A_PromptReco_v4_03092010',
            Format = ('ICF', 2),
            File = [
            #"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_10_skim.root"
            "/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_11_skim.root"
            #"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_0_skim.root"
            ],
            Weight=1.0,
            #LastEntry = 1000,
            )
      anal_ak5_caloData.Run(".",conf_ak5_caloData,[tmp])

elif ( sample == 2 ) : # Test MC
      
      tmp = PSet(
            Name="QCD_Pythia6_AllPtBins",
            Format=("ICF",2),
            File=[
            #"/vols/cms02/gouskos/QCD_Pythia_Pt15_Jun2010/SusyCAF_Tree_10_1_1hm.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt30_Jun2010/SusyCAF_Tree_11_2_EHT.root",
            "/vols/cms02/gouskos/QCD_Pythia_Pt80_Jun2010/SusyCAF_Tree_10_1_52b.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt170_Jun2010/SusyCAF_Tree_10_2_41z.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt300_Jun2010/SusyCAF_Tree_10_1_8qT.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt470_Jun2010/SusyCAF_Tree_10_1_wU8.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt800_Jun2010/SusyCAF_Tree_10_1_aDW.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt1400_Jun2010/SusyCAF_Tree_10_1_IFQ.root",
            ],
            Weights = PSet(
            CrossSection = [8.762e+08,6.041e+07,9.238e+05,2.547e+04,1.256e+03,8.798e+01,2.186,0.01122],
            Events=[6095857,5069664,2065792,3171950,2976108,2159497,2181700,1185024],
            PtBin = [15.,30.,80.,170.,300., 470.,800.,1400.],
            ),
            #LastEntry = 1000,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])

elif ( sample == 3 ) : # Data
      
      data = [All38SkimsUpto151010_Jet_MultiJet]
      anal_ak5_caloData.Run(dir,conf_ak5_caloData,data)

elif ( sample == 4 ) : # QCD background on /vols

      MC = [QCD_AllPtBins_7TeV_Pythia]
      anal_ak5_caloMC.Run(dir,conf_ak5_caloMC,MC)
      
elif ( sample == 5 ) : # EWK backgrounds on /vols and LM0 points on dcache
      
      # CAN ONLY RUN ONE JOB FOR THESE FILES!!!!!!!!!!!!!!!
      MC = [wjets_madgraph_edwardSkim,Zinvisible_jets_edwardSkim,ttbarTauola,LM0,LM1]
      anal_ak5_caloMC.Run(dir,conf_ak5_caloMC,MC)
      # CAN ONLY RUN ONE JOB FOR THESE FILES!!!!!!!!!!!!!!!
