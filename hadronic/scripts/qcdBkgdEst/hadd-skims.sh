DIR=tmp
WJETS=Skim_wjets_madgraph_edwardSkim 
ZINV=Skim_Zinvisible_jets_edwardSkim
TTBAR=Skim_ttbarTauola
QCD=Skim_QCD_AllPtBins_7TeV_Pythia
DATA=Skim_All38SkimsUpto151010_Jet_MultiJet

hadd Skim_data.root $DIR/${DATA}_part*.root 
hadd Skim_wjets.root $DIR/${WJETS}_part*.root
hadd Skim_zinv.root $DIR/${ZINV}_part*.root
hadd Skim_ttbar.root $DIR/${TTBAR}_part*.root
hadd Skim_qcd.root $DIR/${QCD}_part*.root
hadd Skim_ewk.root Skim_wjets.root Skim_zinv.root Skim_ttbar.root 
hadd Skim_sm.root Skim_qcd.root Skim_ewk.root

