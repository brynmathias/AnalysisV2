#!/usr/bin/env python

# 1 = MadGraph, 
# 2 = QCD Pythia6, 36
# 3 = QCD Pythia6, 38

# 4 = LMx

# 5 = WJETS MC NO SKIM
# 6 = ZINV MC NO SKIM
# 7 = TTBAR MC NO SKIM

# 11 = test with QCD MG
# 12 = test with QCD 36
# 13 = test with QCD 38
# 14 = test with LM1

dataset=4
option=1

VerboseOption=False

ht_default = 350.
meff_default = 500.
pt1_default = 100.
pt2_default = 100.
pt3_default = 50.

dir ="/vols/cms02/bainbrid/qcd/SUSY2/results/batch/"

optionStr=""
if ( option != 0 ) :
      optionStr="_"+str(option)

extra = "110124"+optionStr+"/"+str(int(pt1_default))+"_"+str(int(pt2_default))+"_"+str(int(pt3_default))+"/"
dir = dir+extra
print dir

babycut=5 # MHT(350)/MET

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
      
import setupSUSY
from allhadronic.dalitz_cff import * 
from SweetBatchSub import *

from samples_cff import *

from montecarlo.QCD_Madgraph_ALL import * 
from montecarlo.QCD_Pythia6_ALL import * 
from montecarlo.QCD_Pythia6_384patch3_V14_00_02_ALL import *

from montecarlo.LMx import *

from montecarlo.WJets_Madgraph_NNLO import *
from montecarlo.Zinvisible_jets_pset_NNLO import *
from montecarlo.Zjets_madgraph_NNLO import *
from montecarlo.TTBarTauola_NNLO import *

dalitzMC = Dalitz( PSet(DirName = "Dalitz",
                        MinObjects=2,
                        MaxObjects=10,
                        Verbose=VerboseOption,
                        MaxJetEta=3.0,
                        MaxLeadingJetEta=2.5,
                        Scale=ScaleOption,
                        AlphaT=[0.5,0.51,0.52,0.53,0.54,0.55,0.56,0.57,0.58,0.59,0.6],
                        HT=ht_default,
                        Meff=meff_default,
                        MinJetPt1=pt1_default,
                        MinJetPt2=pt2_default,
                        MinJetPt3=pt3_default,
                        HtNbins=NbinsOption,
                        HtXlow=HtXlowOption,
                        HtXhigh=HtXhighOption,
                        MeffNbins=NbinsOption,
                        MeffXlow=HtXlowOption+150.,
                        MeffXhigh=HtXhighOption+150.).ps() )

cutTreeMC.TAttach(selection,dalitzMC)

# -----------------------------------------------------------------------------
# Analyses

conf_ak5_genMC = deepcopy(defaultConfig)
conf_ak5_genMC.Ntuple = deepcopy(default_ntuple)
conf_ak5_genMC.XCleaning = deepcopy(default_cc)
conf_ak5_genMC.Common = deepcopy(default_common)
conf_ak5_genMC.Common.print_out()
anal_ak5_genMC=Analysis("Ratio")
anal_ak5_genMC+=cutTreeMC

samples = []

anal_str = "anal_ak5_genMC"
conf_str = "conf_ak5_genMC"

if ( dataset == 1 ) : # MadGraph
      BatchRun(QCD_MadGraph_ALL,anal_str,conf_str,dir,5,dir)

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

# TESTS 

elif ( dataset == 11 ) :
      tmp = PSet(
            Name="QCD_MadGraph",
            Format=("ICF",2),
            File=[
            #"dcap://gfe02.grid.hep.ph.ic.ac.uk:22128/pnfs/hep.ph.ic.ac.uk/data/cms/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt100to250-madgraph.Spring10-START3X_V26_S09-v2.GEN-SIM-RECO/SusyCAF_Tree_99_3.root",
            #"dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/as1604/ICF/automated/2010_08_15_23_34_33/QCD_Pt1000toInf-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_2.root",
            #"dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/as1604/ICF/automated/2010_08_15_23_34_33/QCD_Pt1000toInf-madgraph.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_2.root",
            'dcap://gfe02.grid.hep.ph.ic.ac.uk:22128/pnfs/hep.ph.ic.ac.uk/data/cms/store/user/as1604/ICF/automated/2010_08_15_23_34_33//QCD_Pt100to250-madgraph.Spring10-START3X_V26_S09-v2.GEN-SIM-RECO/SusyCAF_Tree_28_1.root',
            ],
            CrossSection=5200.,
            LastEntry = 100,
            )
      anal_ak5_genMC.Run(".",conf_ak5_genMC,[tmp])

elif ( dataset == 12 ) :
      tmp = PSet(
            Name="QCD_Pythia6_AllPtBins",
            Format=("ICF",2),
            File=[
            #"/vols/cms02/gouskos/QCD_Pythia_Pt80_Jun2010/SusyCAF_Tree_10_1_52b.root",
            #"/vols/cms02/gouskos/QCD_Pythia_Pt470_Jun2010/SusyCAF_Tree_10_1_wU8.root",
            "/vols/cms02/gouskos/QCD_Pythia_Pt1400_Jun2010/SusyCAF_Tree_9_1_Qjk.root",
            ],
            Weights = PSet(
            CrossSection = [8.762e+08,6.041e+07,9.238e+05,2.547e+04,1.256e+03,8.798e+01,2.186,0.01122],
            Events=[6095857,5069664,2065792,3171950,2976108,2159497,2181700,1185024],
            PtBin = [15.,30.,80.,170.,300., 470.,800.,1400.],
            ),
            LastEntry = 1000,
            )
      anal_ak5_genMC.Run(".",conf_ak5_genMC,[tmp])

elif ( dataset == 13 ) :
      tmp = PSet(
            Name="QCD_Pythia6_38_AllPtBins",
            Format=("ICF",2),
            File=[
            "dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/bm409//ICF/automated/2010_10_11_23_08_00//QCD_Pt_120to170_TuneZ2_7TeV_pythia6.Fall10-START38_V12-v1.GEN-SIM-RECO//SusyCAF_Tree_100_2_stC.root" ,
            ],
            CrossSection=48440000000.0,
            LastEntry = 1000,
            )
      anal_ak5_genMC.Run(".",conf_ak5_genMC,[tmp])

elif ( dataset == 14 ) :
      tmp = PSet(
            Name="LM1",
            Format=("ICF",2),
            File=[
            "dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/LM1.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            "dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/LM1.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root",
            "dcap://gfe02.grid.hep.ph.ic.ac.uk:22128//pnfs/hep.ph.ic.ac.uk/data/cms/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/LM1.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            ],
            CrossSection=4.888,
            LastEntry = 10000,
            )
      anal_ak5_genMC.Run(".",conf_ak5_genMC,[tmp])



