DATA_DIR=conf_ak5_caloData
MC_DIR=conf_ak5_caloMC

LM0=Ratio_LM0
LM1=Ratio_LM1
#WJETS=Ratio_wjets_madgraph_edwardSkim 
#ZINV=Ratio_Zinvisible_jets_edwardSkim
#TTBAR=Ratio_ttbarTauola
#WJETS=Ratio_wjets_skim
#ZINV=Ratio_zinv_skim
#TTBAR=Ratio_ttbar_noskim
WJETS=Ratio_wjets_madgraph_vols
ZINV=Ratio_Zinvisible_jets
TTBAR=Ratio_ttbarTauola
QCD=Ratio_QCD_AllPtBins_7TeV_Pythia
#DATA=Ratio_All38SkimsUpto221010_Jet_MultiJet
DATA=Ratio_Jet_15pb_WithTP_json221010

DO_SYST=1
DO_DATA=1

# Data

if [ $DO_DATA == 1 ]; then
    hadd QcdBkgdEst_data.root $DATA_DIR/${DATA}_part*.root 
fi

# MC

hadd QcdBkgdEst_lm0.root $MC_DIR/${LM0}_part*.root
hadd QcdBkgdEst_lm1.root $MC_DIR/${LM1}_part*.root
hadd QcdBkgdEst_wjets.root $MC_DIR/${WJETS}_part*.root
hadd QcdBkgdEst_zinv.root $MC_DIR/${ZINV}_part*.root
hadd QcdBkgdEst_ttbar.root $MC_DIR/${TTBAR}_part*.root
hadd QcdBkgdEst_qcd.root $MC_DIR/${QCD}_part*.root
hadd QcdBkgdEst_ewk.root QcdBkgdEst_wjets.root QcdBkgdEst_zinv.root QcdBkgdEst_ttbar.root 
hadd QcdBkgdEst_sm.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk.root
hadd QcdBkgdEst_sm+lm0.root QcdBkgdEst_sm.root QcdBkgdEst_lm0.root
hadd QcdBkgdEst_sm+lm1.root QcdBkgdEst_sm.root QcdBkgdEst_lm1.root

# Systematics

if [ $DO_SYST == 1 ]; then
    
    hadd QcdBkgdEst_ewk_wjets_x0.root QcdBkgdEst_zinv.root QcdBkgdEst_ttbar.root 
    hadd QcdBkgdEst_ewk_zinv_x0.root QcdBkgdEst_wjets.root QcdBkgdEst_ttbar.root 
    hadd QcdBkgdEst_ewk_ttbar_x0.root QcdBkgdEst_wjets.root QcdBkgdEst_zinv.root 
    
    hadd QcdBkgdEst_ewk_wjets_x2.root QcdBkgdEst_ewk.root QcdBkgdEst_wjets.root
    hadd QcdBkgdEst_ewk_zinv_x2.root QcdBkgdEst_ewk.root QcdBkgdEst_zinv.root
    hadd QcdBkgdEst_ewk_ttbar_x2.root QcdBkgdEst_ewk.root QcdBkgdEst_ttbar.root
    
    hadd QcdBkgdEst_ewk_wjets_x3.root QcdBkgdEst_ewk_wjets_x2.root QcdBkgdEst_wjets.root
    hadd QcdBkgdEst_ewk_zinv_x3.root QcdBkgdEst_ewk_zinv_x2.root QcdBkgdEst_zinv.root
    hadd QcdBkgdEst_ewk_ttbar_x3.root QcdBkgdEst_ewk_ttbar_x2.root QcdBkgdEst_ttbar.root
    
    hadd QcdBkgdEst_ewk_wjets_x4.root QcdBkgdEst_ewk_wjets_x3.root QcdBkgdEst_wjets.root
    hadd QcdBkgdEst_ewk_zinv_x4.root QcdBkgdEst_ewk_zinv_x3.root QcdBkgdEst_zinv.root
    hadd QcdBkgdEst_ewk_ttbar_x4.root QcdBkgdEst_ewk_ttbar_x3.root QcdBkgdEst_ttbar.root
    
    hadd QcdBkgdEst_ewk_wjets_x5.root QcdBkgdEst_ewk_wjets_x4.root QcdBkgdEst_wjets.root
    hadd QcdBkgdEst_ewk_zinv_x5.root QcdBkgdEst_ewk_zinv_x4.root QcdBkgdEst_zinv.root
    hadd QcdBkgdEst_ewk_ttbar_x5.root QcdBkgdEst_ewk_ttbar_x4.root QcdBkgdEst_ttbar.root

    hadd QcdBkgdEst_sm_wjets_x0.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_wjets_x0.root 
    hadd QcdBkgdEst_sm_zinv_x0.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_zinv_x0.root 
    hadd QcdBkgdEst_sm_ttbar_x0.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_ttbar_x0.root 
    
    hadd QcdBkgdEst_sm_wjets_x2.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_wjets_x2.root 
    hadd QcdBkgdEst_sm_zinv_x2.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_zinv_x2.root 
    hadd QcdBkgdEst_sm_ttbar_x2.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_ttbar_x2.root 
    
    hadd QcdBkgdEst_sm_wjets_x3.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_wjets_x3.root 
    hadd QcdBkgdEst_sm_zinv_x3.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_zinv_x3.root 
    hadd QcdBkgdEst_sm_ttbar_x3.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_ttbar_x3.root 
    
    hadd QcdBkgdEst_sm_wjets_x4.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_wjets_x4.root 
    hadd QcdBkgdEst_sm_zinv_x4.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_zinv_x4.root 
    hadd QcdBkgdEst_sm_ttbar_x4.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_ttbar_x4.root 
    
    hadd QcdBkgdEst_sm_wjets_x5.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_wjets_x5.root 
    hadd QcdBkgdEst_sm_zinv_x5.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_zinv_x5.root 
    hadd QcdBkgdEst_sm_ttbar_x5.root QcdBkgdEst_qcd.root QcdBkgdEst_ewk_ttbar_x5.root 

    hadd QcdBkgdEst_sm+lm0_wjets_x0.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_wjets_x0.root 
    hadd QcdBkgdEst_sm+lm0_zinv_x0.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_zinv_x0.root 
    hadd QcdBkgdEst_sm+lm0_ttbar_x0.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_ttbar_x0.root 
    
    hadd QcdBkgdEst_sm+lm0_wjets_x2.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_wjets_x2.root 
    hadd QcdBkgdEst_sm+lm0_zinv_x2.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_zinv_x2.root 
    hadd QcdBkgdEst_sm+lm0_ttbar_x2.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_ttbar_x2.root 
    
    hadd QcdBkgdEst_sm+lm0_wjets_x3.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_wjets_x3.root 
    hadd QcdBkgdEst_sm+lm0_zinv_x3.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_zinv_x3.root 
    hadd QcdBkgdEst_sm+lm0_ttbar_x3.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_ttbar_x3.root 
    
    hadd QcdBkgdEst_sm+lm0_wjets_x4.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_wjets_x4.root 
    hadd QcdBkgdEst_sm+lm0_zinv_x4.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_zinv_x4.root 
    hadd QcdBkgdEst_sm+lm0_ttbar_x4.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_ttbar_x4.root 
    
    hadd QcdBkgdEst_sm+lm0_wjets_x5.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_wjets_x5.root 
    hadd QcdBkgdEst_sm+lm0_zinv_x5.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_zinv_x5.root 
    hadd QcdBkgdEst_sm+lm0_ttbar_x5.root QcdBkgdEst_lm0.root QcdBkgdEst_sm_ttbar_x5.root 

    hadd QcdBkgdEst_sm+lm1_wjets_x0.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_wjets_x0.root 
    hadd QcdBkgdEst_sm+lm1_zinv_x0.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_zinv_x0.root 
    hadd QcdBkgdEst_sm+lm1_ttbar_x0.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_ttbar_x0.root 
    
    hadd QcdBkgdEst_sm+lm1_wjets_x2.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_wjets_x2.root 
    hadd QcdBkgdEst_sm+lm1_zinv_x2.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_zinv_x2.root 
    hadd QcdBkgdEst_sm+lm1_ttbar_x2.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_ttbar_x2.root 
    
    hadd QcdBkgdEst_sm+lm1_wjets_x3.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_wjets_x3.root 
    hadd QcdBkgdEst_sm+lm1_zinv_x3.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_zinv_x3.root 
    hadd QcdBkgdEst_sm+lm1_ttbar_x3.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_ttbar_x3.root 
    
    hadd QcdBkgdEst_sm+lm1_wjets_x4.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_wjets_x4.root 
    hadd QcdBkgdEst_sm+lm1_zinv_x4.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_zinv_x4.root 
    hadd QcdBkgdEst_sm+lm1_ttbar_x4.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_ttbar_x4.root 
    
    hadd QcdBkgdEst_sm+lm1_wjets_x5.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_wjets_x5.root 
    hadd QcdBkgdEst_sm+lm1_zinv_x5.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_zinv_x5.root 
    hadd QcdBkgdEst_sm+lm1_ttbar_x5.root QcdBkgdEst_lm1.root QcdBkgdEst_sm_ttbar_x5.root 
    
fi
