DIR=.
#DIR=/vols/cms02/bainbrid/qcd/trigger/SUSY2/results

#mkdir parts
#mv Ratio_*_*.* parts/

#hadd Ratio_data.root ${DIR}/parts/Ratio_HT_Run2011_promptReco_DCS_*.root 
#hadd Ratio_data.root ${DIR}/parts/Ratio_HT42_incomplete_*.root 
hadd Ratio__data.root ${DIR}/parts/Ratio_HT_Run2011A_*.root 
hadd Ratio__qcd_pythia.root ${DIR}/parts/Ratio_QCD_Pt_*.root 
hadd Ratio__qcd_madgraph.root ${DIR}/parts/Ratio_QCD_TuneD6T_HT_*.root
hadd Ratio__wjets.root ${DIR}/parts/Ratio_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1_*.root 
hadd Ratio__zinv.root ${DIR}/parts/Ratio_ZinvisibleJets_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1_*.root 
hadd Ratio__ttbar.root ${DIR}/parts/Ratio_TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1_*.root 
hadd Ratio__top_t.root ${DIR}/parts/Ratio_TToBLNu_TuneZ2_t_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1_*.root
hadd Ratio__top_tW.root ${DIR}/parts/Ratio_TToBLNu_TuneZ2_tW_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1_*.root
hadd Ratio__top_s.root ${DIR}/parts/Ratio_TToBLNu_TuneZ2_s_channel_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1_*.root
hadd Ratio__lm1.root ${DIR}/parts/Ratio_LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1_*.root
hadd Ratio__lm4.root ${DIR}/parts/Ratio_LM4_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1_*.root
hadd Ratio__lm6.root ${DIR}/parts/Ratio_LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1_*.root

hadd Ratio__top.root Ratio__top_t.root Ratio__top_tW.root Ratio__top_s.root 
hadd Ratio__ewk.root Ratio__wjets.root Ratio__zinv.root Ratio__ttbar.root Ratio__top.root

hadd Ratio__sm_pythia.root Ratio__ewk.root Ratio__qcd_pythia.root
hadd Ratio__wjets_pythia.root Ratio__wjets.root Ratio__qcd_pythia.root
hadd Ratio__zinv_pythia.root Ratio__zinv.root Ratio__qcd_pythia.root
hadd Ratio__ttbar_pythia.root Ratio__ttbar.root Ratio__qcd_pythia.root
hadd Ratio__top_pythia.root Ratio__top.root Ratio__qcd_pythia.root

hadd Ratio__sm_pythia+lm1.root Ratio__lm1.root Ratio__sm_pythia.root
hadd Ratio__sm_pythia+lm4.root Ratio__lm4.root Ratio__sm_pythia.root
hadd Ratio__sm_pythia+lm6.root Ratio__lm6.root Ratio__sm_pythia.root

hadd Ratio__sm_madgraph.root Ratio__ewk.root Ratio__qcd_madgraph.root
hadd Ratio__wjets_madgraph.root Ratio__wjets.root Ratio__qcd_madgraph.root
hadd Ratio__zinv_madgraph.root Ratio__zinv.root Ratio__qcd_madgraph.root
hadd Ratio__ttbar_madgraph.root Ratio__ttbar.root Ratio__qcd_madgraph.root
hadd Ratio__top_madgraph.root Ratio__top.root Ratio__qcd_madgraph.root

hadd Ratio__sm_madgraph+lm1.root Ratio__lm1.root Ratio__sm_madgraph.root
hadd Ratio__sm_madgraph+lm4.root Ratio__lm4.root Ratio__sm_madgraph.root
hadd Ratio__sm_madgraph+lm6.root Ratio__lm6.root Ratio__sm_madgraph.root
