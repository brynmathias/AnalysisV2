#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libLepCom import *
from icf.core import PSet,Analysis
from icf.config import defaultConfig
import samples.icf_demo as icfsamples

# import default configuration
conf=defaultConfig

# Lower our Jet Et Cut
conf.Common.Jets.EtCut=5.

SamplesDir="/home/arlogb/Ntup_V00-08-04-04/"
SamplesDirIC="/vols/cms01/arlogb/"
JPsiMuMu=PSet(
	Name="JPsiMuMu",
	File=SamplesDirIC+"JPsiMuMu_7TeV_V00-08-04-04_BadGen.root",
#         File='/castor/cern.ch/user/a/arlogb/7TeV/V00-08-04-04_Ntup_Prod/Onia/JPsiMuMu/SusyCAF_Tree_1.root',
        CrossSection=12570000*0.0739,
        Format=("ICF",2),
        Weight=4.
        )

lm0=PSet(
    Name="LM0",
    File=SamplesDir+'LM0_7TeV_V00-08-04-04.root',
    CrossSection=icfsamples.lm0.CrossSection,
    Format=("ICF", 2),
    FirstEntry=0
    )

lm0_IC=PSet(
    Name='LM0',
    File=[SamplesDirIC+'LM0/SusyCAF_Tree*'],
    Format=('ICF',2),
    CrossSection=icfsamples.lm0.CrossSection
)

lm1_IC=PSet(
    Name='LM1',
    File=[SamplesDirIC+'LM1/SusyCAF_Tree*'],
    Format=('ICF',2),
    CrossSection=4.888
)

lm1=PSet(
    Name='LM1',
    File=SamplesDir+'SusyCAF-LM1-7TeV-V000804-Summer09-MC_3XY_V18.root',
    CrossSection=4.888,
    Format=("ICF", 2)
    )

goodcol_v2=PSet(
    Name='GOODCOLL_v2',
    File=["/vols/cms01/susy/data/MinBias/Commissioning10-GOODCOLL-v2_V001008/MinBias_Com10-GOODCOLL*"],
    Format=("ICF", 2),
    Weight=1.
)

jsongoodruns_v8=PSet(
    Name='Json_GoodColl_v8',
    File=['/vols/cms01/susy/data/MinBias/Commissioning10-GOODCOLL-v8/Ntuple_GoodColl-v8_GoodRunsUpToXXXXXX*'],
    Format=("ICF",2),
    Weight=1.
)
GoodJPsiDataSamp=PSet(
    Name='GoodJPsiData',
    File=['/vols/cms01/arlogb/GoodJPsi/MinBias_Apr1ReReco-v2_testrun*'],
    Format=("ICF",2),
    Weight=1.
)

AllJPsi=PSet(
    Name='AllJPsi',
    File=['/vols/cms01/arlogb/AllJPsi_GOODCOL_v8/MinBias_Apr1ReReco-v2_testrun*'],
    Format=("ICF",2),
    Weight=1.
)


resultsdir = '../AGB_Results/'

JPsiSelec=True
JPsiStudy=False
Gen=True

# Create the manager
a=Analysis("LepVal")
htcut=HtCut(100)
postDiJetHt=HtCut(100)
postDoubMu0Ht=HtCut(100)
postDoubMu3Ht=HtCut(100)
if Gen:
    MyGenLeps=IsoGenLeptons()
    a.AddUserVar("Custom_IsoGenLeps",MyGenLeps)
#selection variables are d0, dz, normchi2Global, normchi2Trk, siTrkHits

JPsiMuons=SelectionJPsiMuons(JPsiSelec, 0.2, 10., 20., 5., 12.)#J/Psi cuts
a.AddUserVar("JPsiSelectionMuons",JPsiMuons)

DijetTrig=Trigger("HLT_DiJetAve30U")
DoubleMu0=Trigger("HLT_DoubleMu0")
DoubleMu3=Trigger("HLT_DoubleMu3")

plots=LP_plots('plots', JPsiStudy, Gen, JPsiStudy, resultsdir)
plots_postHT=LP_plots('plots_postHT100', JPsiStudy, Gen, JPsiStudy, resultsdir)
# plots_postDiJet_wHT=LP_plots('plots_postDiJet-HT', JPsiStudy, Gen)
# plots_postDoubMu0_wHT=LP_plots('plots_postDoubleMu0-HT',JPsiStudy, Gen)
# plots_postDoubMu3_wHT=LP_plots('plots_postDoubleMu3-HT',JPsiStudy, Gen)



# Create the tree
tree = Tree("Main")
a+=tree
tree.Attach(plots)
tree.Attach(htcut)
# tree.Attach(DijetTrig)
# tree.Attach(DoubleMu0)
# tree.Attach(DoubleMu3)
tree.TAttach(htcut, plots_postHT)
# tree.TAttach(DijetTrig, postDiJetHt)
# tree.TAttach(postDiJetHt,plots_postDiJet_wHT)
# tree.TAttach(DoubleMu0, postDoubMu0Ht)
# tree.TAttach(postDoubMu0Ht, plots_postDoubMu0_wHT)
# tree.TAttach(DoubleMu3, postDoubMu3Ht)
# tree.TAttach(postDoubMu3Ht, plots_postDoubMu3_wHT)



s=[lm0_IC, lm1_IC]
a.Run(resultsdir,conf,s)
