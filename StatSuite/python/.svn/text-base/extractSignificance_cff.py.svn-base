#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Necessary includes

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from bkgdCore import BkgdAnalysis
from copy import deepcopy
from icf.core import PSet

from bkgdEst_cfi import defaultBkgdConfig

default_samples = deepcopy(defaultBkgdConfig.Samples)



Jamboree_samples=PSet(
    plotName="BkgdEstPlots_g1jets/alphaT_vs_HT_",
    outputDir="../results_Jamboree/",
    Signal="../results_Jamboree/AK5Calo_LM0.root",
    mSuGra_tanB10="../results_Jamboree/AK5Calo_tanB10.root",
    mSuGra_tanB3="../results_Jamboree/AK5Calo_tanB3.root",
    Data="../results_Jamboree/AK5Calo_Edward_Data_Skim.root",
    Background=PSet(
    ttbar="../results_Jamboree/AK5Calo_ttbarTauola.root",
    Zinv="../results_Jamboree/AK5Calo_Zinvisible_jets_edwardSkim.root",
    Zjets="../results_Jamboree/AK5Calo_zjets_madgraph_edwardSkim.root",
    Wjets="../results_Jamboree/AK5Calo_wjets_madgraph_edwardSkim.root",
    QCD="../results_Jamboree/AK5Calo_QCD_PYTHIA8.root",
   
    )
    )

PAS_samples=PSet(
    plotName="BkgdEstPlots_g1jets/alphaT_vs_HT_",
    outputDir="../results_PAS/",
    Signal="../results_PAS/AK5Calo_LM0.root",
    mSuGra_tanB10="../results_PAS/AK5Calo_tanB10.root",
    mSuGra_tanB3="../results_PAS/AK5Calo_tanB3.root",
    Data="../results_PAS/AK5Calo_Edward_Data_Skim.root",
    Background=PSet(
    ttbar="../results_PAS/AK5Calo_ttbarTauola.root",
    Zinv="../results_PAS/AK5Calo_Zinvisible_jets_edwardSkim.root",
    Zjets="../results_PAS/AK5Calo_zjets_madgraph_edwardSkim.root",
    Wjets="../results_PAS/AK5Calo_wjets_madgraph_edwardSkim.root",
    QCD="../results_PAS/AK5Calo_QCD_PYTHIA8.root",
    tanBeta ="3"
    )
    )
  

default_cuts = deepcopy(defaultBkgdConfig.Cuts)
default_cuts=PSet(
    signalLow=0.55,
    signalUp=-1.,
    bkgdLow=0.,
    bkgdUp=0.55,
    nBinVar1=3,
    rebinX=10,
    HTcut_First=250.,
    HTcut_FirstUp=350.,
    HTcut_Second=350.,
    )

mSuGraSettings = PSet(
    mSuGraDir = "mSuGraScan_350", #HT > 350
    mSuGraHist = "m0_m12_0", #_0 all jet Mult. _1 2 jet events _2 >2 jet events
    tanBeta =3,
    nbins_x = 80,
    min_x = 0,
    max_x = 4000,
    binsize_x = 50,
    nbins_y = 25,
    min_y = 100,
    max_y = 600,
    binsize_y = 20,  
)

default_significanceSettings = deepcopy(defaultBkgdConfig.Significance)

Bayes_3pb_alljet_significanceSettings=PSet(
    mSuGraDir = "mSuGraScan_350", #HT > 350
    mSuGraHist = "m0_m12_0", #_0 all jet Mult. _1 2 jet events _2 >2 jet events
    outputPlotName = "BayesPlot_3pb_alljet_tanB3.root",
    CutAndCountOrRatio = "CutAndCount", #Ratio or CutAndCount
    method = "Bayes",
    testFactor = 1.,#dangerous only for funny tests only change if you know what you are doing!
    lumi=3.,
    useRealData=1,
    exclusion_significance=0.95,
    precision=0.02,
    integration_upperLimit=10000000,
    uncertainty_qcd=1.,
    uncertainty_ewk=0.5,
    rhonomSigma=1.,
 )

Bayes_50pb_alljet_significanceSettings = deepcopy(Bayes_3pb_alljet_significanceSettings)
Bayes_50pb_alljet_significanceSettings.lumi = 50.
Bayes_50pb_alljet_significanceSettings.outputPlotName="Bayes_50pb_alljet_tanB3.root"

Bayes_50pb_alljet_significanceSettings_fudge = deepcopy(Bayes_50pb_alljet_significanceSettings)
Bayes_50pb_alljet_significanceSettings_fudge.testFactor = 0.5
Bayes_50pb_alljet_significanceSettings_fudge.outputPlotName="Bayes_50pb_alljet_tanB3_fudge.root"

Profile_3pb_alljet_significanceSettings=PSet(
    mSuGraDir = "mSuGraScan_350", #HT > 350
    mSuGraHist = "m0_m12_0", #_0 all jet Mult. _1 2 jet events _2 >2 jet events
    outputPlotName = "ProfilePlot_3pb_alljet_tanB3.root",
    CutAndCountOrRatio = "CutAndCount", #Ratio or CutAndCount
    method = "Profile",
    testFactor = 1.,#dangerous only for funny tests only change if you know what you are doing!
    lumi=3.,
    useRealData=1,
    exclusion_significance=0.95,
    precision=0.02,
    integration_upperLimit=10000000,
    uncertainty_qcd=1.,
    uncertainty_ewk=0.5,
    rhonomSigma=1.,
 )

Profile_50pb_alljet_significanceSettings = deepcopy(Profile_3pb_alljet_significanceSettings)
Profile_50pb_alljet_significanceSettings.lumi = 50.
Profile_50pb_alljet_significanceSettings.outputPlotName="Profile_50pb_alljet_tanB3.root"

Profile_50pb_alljet_significanceSettings_fudge = deepcopy(Profile_50pb_alljet_significanceSettings)
Profile_50pb_alljet_significanceSettings_fudge.testFactor = 0.5
Profile_50pb_alljet_significanceSettings_fudge.outputPlotName="Profile_50pb_alljet_tanB10_fudge.root"

FC_3pb_alljet_significanceSettings=PSet(
    mSuGraDir = "mSuGraScan_350", #HT > 350
    mSuGraHist = "m0_m12_0", #_0 all jet Mult. _1 2 jet events _2 >2 jet events
    outputPlotName = "FCPlot_3pb_alljet_tanB3.root",
    CutAndCountOrRatio = "CutAndCount", #Ratio or CutAndCount
    method = "FC",
    testFactor = 1.,#dangerous only for funny tests only change if you know what you are doing!
    lumi=3.,
    useRealData=1,
    exclusion_significance=0.95,
    precision=0.02,
    integration_upperLimit=10000000,
    uncertainty_qcd=1.,
    uncertainty_ewk=0.5,
    rhonomSigma=1.,
 )

FC_50pb_alljet_significanceSettings = deepcopy(FC_3pb_alljet_significanceSettings)
FC_50pb_alljet_significanceSettings.lumi = 50.
FC_50pb_alljet_significanceSettings.outputPlotName="FC_50pb_alljet_tanB3.root"

FC_50pb_alljet_significanceSettings_fudge = deepcopy(FC_50pb_alljet_significanceSettings)
FC_50pb_alljet_significanceSettings_fudge.testFactor = 0.8
FC_50pb_alljet_significanceSettings_fudge.outputPlotName="FC_50pb_alljet_tanB3_fudge.root"

MCMC_3pb_alljet_significanceSettings=PSet(
    mSuGraDir = "mSuGraScan_350", #HT > 350
    mSuGraHist = "m0_m12_0", #_0 all jet Mult. _1 2 jet events _2 >2 jet events
    outputPlotName = "MCMCPlot_3pb_alljet_tanB3.root",
    CutAndCountOrRatio = "CutAndCount", #Ratio or CutAndCount
    method = "MCMC",
    testFactor = 1.,#dangerous only for funny tests only change if you know what you are doing!
    lumi=3.,
    useRealData=1,
    exclusion_significance=0.95,
    precision=0.02,
    integration_upperLimit=10000000,
    uncertainty_qcd=1.,
    uncertainty_ewk=0.5,
    rhonomSigma=1.,
 )

MCMC_3pb_alljet_ratio_significanceSettings = deepcopy(MCMC_3pb_alljet_significanceSettings)
MCMC_3pb_alljet_ratio_significanceSettings.CutAndCountOrRatio = "Ratio"

MCMC_50pb_alljet_significanceSettings = deepcopy(MCMC_3pb_alljet_significanceSettings)
MCMC_50pb_alljet_significanceSettings.lumi = 50.
MCMC_50pb_alljet_significanceSettings.outputPlotName="MCMC_50pb_alljet_tanB3.root"

MCMC_50pb_alljet_significanceSettings_fudge = deepcopy(MCMC_50pb_alljet_significanceSettings)
MCMC_50pb_alljet_significanceSettings_fudge.testFactor = 0.5
MCMC_50pb_alljet_significanceSettings_fudge.outputPlotName="MCMC_50pb_alljet_tanB3_fudge.root"

                         
BkgdAnalysis = BkgdAnalysis("bkgdAnalysis")

BkgdAnalysis.ReadIn(default_cuts,Jamboree_samples,mSuGraSettings)

#BkgdAnalysis.Run(default_cuts,Profile_3pb_alljet_significanceSettings)
#BkgdAnalysis.Run(default_cuts,Bayes_3pb_alljet_significanceSettings)
#BkgdAnalysis.Run(default_cuts,MCMC_3pb_alljet_significanceSettings)
#BkgdAnalysis.Run(default_cuts,FC_3pb_alljet_significanceSettings)

