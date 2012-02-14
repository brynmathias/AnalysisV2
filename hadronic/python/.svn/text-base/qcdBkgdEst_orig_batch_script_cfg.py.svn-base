#!/usr/bin/env python


# 1 = Data
# 2 = QCD MC
# 3 = LMx
# 4 = WJETS MC NO SKIM
# 5 = ZINV MC NO SKIM
# 6 = TTBAR MC NO SKIM
# 7 = MSUGRA
# 8 = test Data
# 9 = test QCD 36
# 10 = test QCD 38

dataset = 10

FilterOption=False
VerboseOption=False
JetSmearOption=False
AddIdFilters=True
UseDeadEcalFileOption=False

mSugraOption=False
if ( dataset == 7 ) :
      mSugraOption=True

option=0
ScaleOption=True
NbinsOption=12
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

import setupSUSY
from hadronic.rob_golden_cff import * ## @@ USE HADRONIC VERSION!!! (ADAPTED!!!)
from SweetBatchSub import *

from hadronic.samples_cff import *
from montecarlo.w_jets_mg_edwardSkim import *

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
                                BabyJetsCutType=3,
                                BabyJetsCut=1.25,
                                UseDeadEcalFile=UseDeadEcalFileOption,
                                DeadEcalRegionsFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_START38_V12.txt",
                                DeadEcalRegionDrCut=0.3,
                                MinJetPtCut=30.,
                                NBadCells=10,
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
                                  mSugra=mSugraOption,
                                  mSugraOnly=mSugraOption,
                                  MaxGenMet=0.,
                                  MinGenJetPt=0.,
                                  MaxJetEta=3.0,
                                  MaxLeadingJetEta=2.5,
                                  Scale=ScaleOption,
                                  BabyJetsCutType=3,
                                  BabyJetsCut=1.25,
                                  UseDeadEcalFile=UseDeadEcalFileOption,
                                  DeadEcalRegionsFile="/vols/cms02/bainbrid/qcd/SUSY2/hadronic/python/deadRegionList_GR10_P_V10.txt",
                                  DeadEcalRegionDrCut=0.3,
                                  MinJetPtCut=30.,
                                  NBadCells=10,
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

from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
      
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

samples = []

if ( dataset == 1 ) :
      data = [Jet_15pb_WithTP_json221010]
      for kk in range(0,len(data)) :
            data[kk].LastEntry = 1000
      anal_ak5_caloData.Run(".",conf_ak5_caloData,data)
elif ( dataset == 2 ) :
      MC2 = [QCD_AllPtBins_7TeV_Pythia]
      for kk in range(0,len(MC2)) :
            MC2[kk].LastEntry = 1000
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,MC2)
elif ( dataset == 3 ) :
      MC3 = [LM0,LM0]
      for kk in range(0,len(MC3)) :
            MC3[kk].LastEntry = 1000
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,MC3)
elif ( dataset == 4 ) :
      MC4 = [wjets_madgraph_vols_expanded]
      for kk in range(0,len(MC4)) :
            MC4[kk].LastEntry = 10000
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,MC4)
elif ( dataset == 5 ) :
      MC6 = [Zinvisible_jets]
      for kk in range(0,len(MC5)) :
            MC5[kk].LastEntry = 1000
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,MC5)
elif ( dataset == 6 ) :
      MC6 = [ttbarTauola]
      for kk in range(0,len(MC6)) :
            MC6[kk].LastEntry = 1000
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,MC6)
elif ( dataset == 7 ) :
      MC7 = [tanB10]
      for kk in range(0,len(MC7)) :
            MC7[kk].LastEntry = 1000
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,MC7)
elif ( dataset == 8 ) :
      tmp = PSet(
            Name = '_JetMET_Run2010A_PromptReco_v4_03092010',
            Format = ('ICF', 2),
            File = [
            #"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_0_skim.root",
            "/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_0_skim.root",
            #"/vols/cms02/bainbrid/qcd/SUSY2/results/batch/101022_1/100_80_50/Skim_data.root",
            ],
            Weight=1.0,
            LastEntry = 1000,
            )
      anal_ak5_caloData.Run(".",conf_ak5_caloData,[tmp])
elif ( dataset == 9 ) :
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
elif ( dataset == 10 ) :
      tmp = PSet(
            Name="QCD_Pythia6_38_AllPtBins",
            Format=("ICF",2),
            File=[
            "root://xrootd.grid.hep.ph.ic.ac.uk/store/user/bm409//ICF/automated/2010_10_11_23_08_00//QCD_Pt_0to5_TuneZ2_7TeV_pythia6.Fall10-START38_V12-v1.GEN-SIM-RECO//SusyCAF_Tree_10_4_tTr.root" ,
            ],
            CrossSection=48440000000.0,
            LastEntry = 10,
            )
      anal_ak5_caloMC.Run(".",conf_ak5_caloMC,[tmp])
      
