//#include "common/utilities_hack.C"
#include "common/utilities.C"
#include "common/style.C"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>

// -----------------------------------------------------------------------------
//  
int qcdBkgdEst_2011() {

  int last_bin = 9;

  setTDRStyle();

  // Misc
  bool efficiency = false;

  enum choices { PLOT_NUMERATOR=1, PLOT_DENOMINATOR=2, PLOT_ESTIMATE=3, PLOT_ANCHORED=4, PLOT_RATIO=5 };
  int choice = 1;
  bool plots = true;
  bool syst_plot = false;
  bool syst_ratio = true;
  bool killer = false;
  bool min_max_with_errors = true;
  
  double axis_offset1 = 1.;
  double axis_offset2 = 0.;
  
  int bin = 0;
  uint ht_bin = 2;
  bool anchor = false; 
  
  bool two_measurements = true;
  bool mc_measurement = false;
  if ( two_measurements || mc_measurement ) { ht_bin = 2; }
  
  int dec_places = 1;
  int sig_figs = 3;
  bool pt_thresholds = false;
  bool print_ratio = true;
  
  // Some analysis defaults
  double offset = 0.;
  double pt1_default = 100.;
  double pt2_default = 100.;
  double pt3_default = 50.;
  double ht_default = 350. + offset;
  double meff_default = ht_default + pt3_default;
  double x1_default = pt1_default / meff_default;
  double x2_default = pt2_default / meff_default;
  double x3_default = pt3_default / meff_default ;
  double x3_factor = ( 1. - x3_default ) / ( x3_default );

  //std::string dir = "~/Desktop/trigger/SUSY2/results/";
  std::string dir = "/vols/cms02/bainbrid/qcd/trigger/SUSY2/results/";
  
  std::vector<int> at;
//   at.push_back(510);
//   at.push_back(520);
//   at.push_back(530);
  at.push_back(550);
//   at.push_back(510);
//   at.push_back(520);
//   for ( int iii = 0; iii < 60; ++iii ) { at.push_back(530+iii); }
//   at.push_back(590);
//   at.push_back(600);
  const uint nat = at.size();
  
  std::vector<int> multi;
  //multi.push_back(-2);
  //multi.push_back(2);
  multi.push_back(-3);
  const uint nmulti = multi.size();
  
  std::vector<double> ht;
  std::vector<double> ht_step;

//   for ( uint iht = uint(ht_min); iht <= uint(ht_max); iht += uint(ht_step) ) { ht.push_back(iht); }
//   const uint nht = ht.size();

//   ht.push_back(275.);
//   ht_step.push_back(50.);
//   ht.push_back(325.);
//   ht_step.push_back(50.);
//   for ( uint iht = 0; iht < 7; ++iht ) { ht.push_back(375+iht*100.); ht_step.push_back(100.); }
//   const uint nht = ht.size() - 1;
  
  for ( uint iht = 0; iht < 11; ++iht ) { ht.push_back(250.+iht*20.); ht_step.push_back(20.); }
  const uint nht = ht.size() - 1;
  
  std::vector<std::string> files;

  //files.push_back("/vols/cms02/bainbrid/qcd/reinterpretation/SUSY2/results/batch/110405_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");
  
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-offset0.root");
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-offset25.root");
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-offset10.root");
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1.root");

  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-143pb-offset0.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-143pb-offset10.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-143pb-offset25.root");

//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-xxpb-offset0.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-xxpb-offset10.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-xxpb-offset25.root");
  
//   files.push_back(dir+"v2/Ratio_data.root");
//   files.push_back(dir+"v2/Ratio_sm_pythia.root");
//   files.push_back(dir+"v2/Ratio_sm_pythia+lm1.root");
//   files.push_back(dir+"v2/Ratio_qcd_pythia.root");
  
  bool test = false;
  if ( test ) {
    files.push_back(dir+"v70/Ratio__data.root");
    //files.push_back(dir+"v80/Ratio__data.root");
    //files.push_back(dir+"v42/Ratio__data.root");
    //files.push_back(dir+"v25/parts/Ratio_HT_Run2011A.root");
    //files.push_back(dir+"v24/Ratio_sm_pythia_with.root");
    //files.push_back(dir+"v27/parts/Ratio_HT_Run2011A_L1OffSet.root");
    //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_Data.root");
    //files.push_back(dir+"v12/Ratio_data.root");
    //files.push_back(dir+"Ratio_data.root");
    //files.push_back(dir+"Ratio_data_no_muon_veto.root");
  }
  
  bool qcd_present = true;
  if ( qcd_present ) {
    files.push_back(dir+"v51/Ratio__sm_pythia.root");
    files.push_back(dir+"v50/Ratio__sm_pythia.root");
    //files.push_back(dir+"v52/Ratio__sm_pythia.root");
    //files.push_back(dir+"v51/Ratio__qcd_pythia.root");
    //files.push_back(dir+"v52/Ratio__qcd_pythia.root");
  }
  
  bool no_qcd_present = false;
  if ( no_qcd_present ) {
    // v2 = fixed, v3 = scaled
    files.push_back(dir+"v7/Ratio_sm_pythia.root");
    files.push_back(dir+"v7/Ratio_sm_madgraph.root");
  }

  bool ewk = false;
  bool sm_closure = false;
  if ( sm_closure ) {
    std::string version = "v24";
    std::string generator = "pythia";
    files.push_back(dir+""+version+"/Ratio_sm_"+generator+".root");
    if (ewk){
      files.push_back(dir+""+version+"/Ratio_wjets_"+generator+".root");
      files.push_back(dir+""+version+"/Ratio_zinv_"+generator+".root");
      files.push_back(dir+""+version+"/Ratio_ttbar_"+generator+".root");
      files.push_back(dir+""+version+"/Ratio_top_"+generator+".root");
    }
  }
  
  bool lmx = false;
  if ( lmx ) {
    files.push_back(dir+"v08/Ratio_lm1.root");
    files.push_back(dir+"v08/Ratio_lm6.root");
    //files.push_back(dir+"v9/Ratio_sm_pythia.root");
  }
  
  bool data = false;
  if ( data ) {
    files.push_back(dir+"v24/Ratio_sm_pythia+lm1.root");
    files.push_back(dir+"v24/Ratio_sm_pythia+lm6.root");
    files.push_back(dir+"v24/Ratio_sm_pythia.root");
    files.push_back(dir+"v70/Ratio__data.root");
    //files.push_back(dir+"v30/Ratio_HT_Run2011A.root");
    //files.push_back(dir+"v25/Ratio_HT_Run2011A_AllReco_17June.root");
    //files.push_back(dir+"v30/Ratio_HT_Run2011A_AllReco_17June.root");
    //files.push_back(dir+"v30/Ratio_HT_Run2011A_L1OffSet.root");
//     files.push_back(dir+"v24/Ratio_wjets_pythia.root");
//     files.push_back(dir+"v24/Ratio_zinv_pythia.root");
//     files.push_back(dir+"v24/Ratio_ttbar_pythia.root");
//     files.push_back(dir+"v24/Ratio_top_pythia.root");
  }
  
  bool syst = false;
  if ( syst ) {
//     files.push_back(dir+"v50/Ratio__sm_pythia.root");
//     files.push_back(dir+"v50/Ratio__sm_wjets_50pc.root");
//     files.push_back(dir+"v50/Ratio__sm_wjets_150pc.root");
//     files.push_back(dir+"v50/Ratio__sm_zinv_50pc.root");
//     files.push_back(dir+"v50/Ratio__sm_zinv_150pc.root");
//     files.push_back(dir+"v50/Ratio__sm_ttbar_50pc.root");
//     files.push_back(dir+"v50/Ratio__sm_ttbar_150pc.root");
//     files.push_back(dir+"v50/Ratio__sm_top_50pc.root");
//     files.push_back(dir+"v50/Ratio__sm_top_150pc.root");

    files.push_back(dir+"v23/Ratio_sm_pythia.root");
    files.push_back(dir+"v23/Ratio_sm_wjets_50pc.root");
    files.push_back(dir+"v23/Ratio_sm_wjets_150pc.root");
    files.push_back(dir+"v23/Ratio_sm_zinv_50pc.root");
    files.push_back(dir+"v23/Ratio_sm_zinv_150pc.root");
    files.push_back(dir+"v23/Ratio_sm_ttbar_50pc.root");
    files.push_back(dir+"v23/Ratio_sm_ttbar_150pc.root");
    files.push_back(dir+"v23/Ratio_sm_top_50pc.root");
    files.push_back(dir+"v23/Ratio_sm_top_150pc.root");
  }

  bool vetoes = false;
  if ( vetoes ) {
    files.push_back(dir+"v16/Ratio_HT_Run2011_promptReco_DCS-all-vetoes.root");
    files.push_back(dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-muon-vetoes.root");
    files.push_back(dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-electron-vetoes.root");
    files.push_back(dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-photon-vetoes.root");
    files.push_back(dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-egamma-vetoes.root");
  }
  
  //files.push_back(dir+"v3/Ratio_data.root");
  //files.push_back(dir+"v4/Ratio_sm_pythia_with.root");
  //files.push_back(dir+"v5/Ratio_sm_pythia+lm1.root");
  //files.push_back(dir+"v4/Ratio_qcd_pythia_with.root");
  
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-7bins.root");
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011_promptReco_DCS-3bins.root");
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-17pb.root");
  
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1.root");
  //files.push_back("/vols/cms02/bainbrid/qcd/trigger/2010/SUSY2/allhadronic/python/Ratio_Jet_35pb_WithTP_json051110.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/test/SUSY2/results/batch/110402_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/test/SUSY2/results/batch/110401_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");
  
//   files.push_back("/vols/cms02/bainbrid/qcd/reinterpretation/SUSY2/results/batch/110404_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/reinterpretation/SUSY2/results/batch/110405_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");
  
  //   files.push_back("/vols/cms02/bainbrid/qcd/trigger/2010/SUSY2/results/batch/110404_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/2010/SUSY2/results/batch/110405_1/100_100_50/Ratio_Jet_35pb_WithTP_json051110.root");

//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Incl_HT_Run2011A_PromptReco_v1.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Excl_HT_ht_sRun2011A_PromptReco_v1.root");
  
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-filter0.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-filter3.root");
  

//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/with-cleaning/Ratio_HT_Run2011A_PromptReco_v1-exclusive.root");
//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/without-cleaning/Ratio_HT_Run2011A_PromptReco_v1-exclusive.root");


//   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1.root");
  
  // files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-17pb-additional-triggers.root");
//    files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-17pb-additional-triggers-aT0p6.root");
//     files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-17pb-with-cleaning-in-denom.root");
    //   files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_HT_Run2011A_PromptReco_v1-17pb-with-no-cleaning-in-denom.root");
  
  const uint nfile = files.size();
  
  std::vector<std::string> his;
  if ( his.size() < nfile ) { his.resize(nfile,"HtAfterTrackless"); }
  
  std::vector<std::string> type;
  if ( test ) { 
    type.push_back("Nominal");
    type.push_back("SumRecHitPt");
//     type.push_back("100,100,50");
//     type.push_back("120,120,60");
//     type.push_back("Nominal");
//     type.push_back("Pile-up subtracted");
  }
  if ( qcd_present ) { 
    type.push_back("Fixed in all HT");
    type.push_back("Scaled in low HT");
    type.push_back("Scaled in all HT");
  }
  if ( no_qcd_present ) { 
    type.push_back("EWK (QCD Pythia)");
    type.push_back("EWK (QCD Madgraph)");
  }
  if ( sm_closure ) {
//     type.push_back("SM+LM1");
//     type.push_back("SM+LM6");
    type.push_back("SM");
    type.push_back("Wjets");
    type.push_back("Zinv");
    type.push_back("TTbar");
    type.push_back("SingleTop");
  }

  if ( lmx ) {
    type.push_back("SM+LM1");
    type.push_back("SM+LM6");
    type.push_back("SM");
  }

  if ( data ) {
    //type.push_back("SM(Madgraph)+LM1");
    type.push_back("SM+LM1");
    //type.push_back("SM(Madgraph)");
    type.push_back("SM+LM6");
    type.push_back("SM");
    type.push_back("Data");
    type.push_back("Wjets");
    type.push_back("Zinv");
    type.push_back("TTbar");
    type.push_back("SingleTop");
  }

  if ( syst ) {
    type.push_back("SM (nominal)");
    type.push_back("Wjets (-50%)");
    type.push_back("Wjets (+50%)");
    type.push_back("Zinv (-50%)");
    type.push_back("Zinv (+50%)");
    type.push_back("TTbar (-50%)");
    type.push_back("TTbar (+50%)");
    type.push_back("SingleTop (-50%)");
    type.push_back("SingleTop (+50%)");
  }

  if ( vetoes ) {
    type.push_back("All vetoes"); 
    type.push_back("No muon");
    type.push_back("No electron");
    type.push_back("No photon");
    type.push_back("No e/gamma");
  }

  if ( type.size() < nfile ) { type.resize(nfile,"unknown"); }
  
  double lumi = 320.;
  std::vector<double> lumis;
  if ( test ) {
    lumis.push_back(100.);
    //lumis.push_back(lumi);
    lumis.push_back(100.);
  }
  if ( qcd_present ) { 
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
//     lumis.push_back(4.1);
//     lumis.push_back(4.1);
//     lumis.push_back(1.5);
//     lumis.push_back(1.5);
  }
  if ( no_qcd_present ) { 
    lumis.push_back(300.);
    lumis.push_back(300.);
  }
  if ( sm_closure ) { 
    lumis.push_back(300.);
    lumis.push_back(300.);
    lumis.push_back(300.);
    lumis.push_back(300.);
    lumis.push_back(300.);
    lumis.push_back(300.);
  }
  if ( lmx ) { 
    lumis.push_back(300.);
    lumis.push_back(300.); 
    lumis.push_back(300.);
  }
  if ( data ) { 
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(100.);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
  }
  if ( syst ) { 
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
  }
  if ( vetoes ) { 
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(100.);
  }
  if ( lumis.size() < nfile ) { lumis.resize(nfile,100.); }
  
  // Which file is the data file
  int data_file = -1;
  for ( uint itype = 0; itype < nfile; ++itype ) {
    if ( type[itype] == "data" || 
	 type[itype] == "Data" ) { 
      data_file = itype; 
      break;
    }
  }
  if ( data_file == -1 ) { 
    data_file = 0;
    std::cout << "Problem identifying data file!" << std::endl;
  }
  
  std::vector<int> style;
  if ( test ) {
    style.push_back(20);
    style.push_back(24);
  }
  if ( qcd_present ) {
    style.push_back(24);
    style.push_back(25);
    style.push_back(26);
  }
  if ( no_qcd_present ) {
    style.push_back(20);
    style.push_back(20);
  }
  if ( sm_closure ) {
//     style.push_back(24);
//     style.push_back(24);
    style.push_back(20);
    style.push_back(25);
    style.push_back(26);
    style.push_back(28);
    style.push_back(30);
  }
  if ( lmx ) {
    style.push_back(24);
    style.push_back(24);
    style.push_back(20);
  }
  if ( data ) {
    style.push_back(24);
    style.push_back(24);
    style.push_back(24);
    style.push_back(20);
    style.push_back(25);
    style.push_back(26);
    style.push_back(28);
    style.push_back(30);
  }
  if ( syst ) {
    style.push_back(20);
    style.push_back(24);
    style.push_back(25);
    style.push_back(24);
    style.push_back(25);
    style.push_back(24);
    style.push_back(25);
    style.push_back(24);
    style.push_back(25);
  }
  if ( vetoes ) {
    style.push_back(20);
    style.push_back(24);
    style.push_back(25);
    style.push_back(26);
    style.push_back(30);
  }
  if ( style.size() < nfile ) { style.resize(nfile,25); }
  
  std::vector<double> size;
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  size.push_back(2.0);
  if ( size.size() < nfile ) { size.resize(nfile,1.); }
  
  std::vector<int> col;
  if ( test ) {
    col.push_back(1);
    col.push_back(2);
  }
  if ( qcd_present ) {
    col.push_back(1);
    col.push_back(2);
    col.push_back(4);
    col.push_back(4);
  }
  if ( no_qcd_present ) {
    col.push_back(2);
    col.push_back(4);
  }
  if ( sm_closure ) {
//     col.push_back(4);
//     col.push_back(2);
    col.push_back(1);
    col.push_back(2);
    col.push_back(3);
    col.push_back(4);
    col.push_back(6);
  }
  if ( lmx ) {
    col.push_back(4);
    col.push_back(3);
    col.push_back(2);
  }
  if ( data ) {
    col.push_back(4);
    col.push_back(3);
    col.push_back(2);
    col.push_back(1);
    col.push_back(6);
    col.push_back(6);
    col.push_back(6);
    col.push_back(6);
  }
  if ( syst ) {
    col.push_back(1);
    col.push_back(4);
    col.push_back(4);
    col.push_back(3);
    col.push_back(3);
    col.push_back(2);
    col.push_back(2);
    col.push_back(6);
    col.push_back(6);
  }
  if ( vetoes ) {
    col.push_back(1);
    col.push_back(1);
    col.push_back(1);
    col.push_back(1);
    col.push_back(1);
  }
  if ( col.size() < nfile ) { col.resize(nfile,1); }
  
  // HT bins
  double ht_min = ht.front() + offset;
  double ht_max = ht.back() + offset;
  //double ht_step = 0.;
  
//   for ( uint iht = 0; iht < 4; ++iht ) { ht.push_back(250+iht*50.); ht_step.push_back(50.); }
//   const uint nht = ht.size() - 1;

  std::vector<double> weights;
  weights.push_back(44.72);
  weights.push_back(44.72);
  weights.push_back(0.803);
  if ( weights.size() < nfile ) { weights.resize(nfile,1.); }
  
  // pT bins
  std::vector<double> pt;
  for ( uint iht = 0; iht < ht.size(); ++iht ) { pt.push_back(ht[iht]/x3_factor); }
  const uint npt = pt.size() - 1;
  
  // Ratio and x3
  double numer[nfile][nmulti][nat][npt][nht];
  double numer_err[nfile][nmulti][nat][npt][nht];
  double denom[nfile][nmulti][nat][npt][nht];
  double denom_err[nfile][nmulti][nat][npt][nht];
  double ratio[nfile][nmulti][nat][npt][nht];
  double errh[nfile][nmulti][nat][npt][nht];
  double errl[nfile][nmulti][nat][npt][nht];
  int length[nfile][nmulti][nat][npt];
  
  // Min/max values for ratios
  double min[nmulti][nat];
  double max[nmulti][nat];

  std::cout << " nfile: " << nfile
	    << " nmulti: " << nmulti
	    << " nat: " << nat
	    << " npt: " << npt
	    << " nht: " << nht
	    << " total: " << nfile*nmulti*nat*npt*nht
	    << std::endl;
  
  // Init arrays
  for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
    for ( uint iat = 0; iat < nat; ++iat ) {
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	for ( uint ipt = 0; ipt < npt; ++ipt ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    numer[ifile][imulti][iat][ipt][iht] = 0.;
	    numer_err[ifile][imulti][iat][ipt][iht] = 0.;
	    denom[ifile][imulti][iat][ipt][iht] = 0.;
	    denom_err[ifile][imulti][iat][ipt][iht] = 0.;
	    ratio[ifile][imulti][iat][ipt][iht] = 0.;
	    errh[ifile][imulti][iat][ipt][iht] = 0.;
	    errl[ifile][imulti][iat][ipt][iht] = 0.;
	  }
	  length[ifile][imulti][iat][ipt] = 0;
	}
      }
      min[imulti][iat] = 0.;
      max[imulti][iat] = 0.;
    }
  }
  
  // -----------------------------------------------------------------------------
  // 
  std::cout << " CALCULATING RATIOS..." << std::endl;
  calcRatio( nfile, nmulti, nat, npt, nht, 
	     his, files, lumis, weights, multi, at, pt, ht, 
	     ht_min, ht_max, ht_step[nht],
	     numer, numer_err, denom, denom_err, ratio, errh, errl, length,
	     data_file, lumi,
	     efficiency );
  
  // -----------------------------------------------------------------------------
  // R(aT) vs HT for "truth", "MC gen", "MC reco" and "data" with fixed (x1,x2,x3)
  
  // Print numbers
  bool print = true;
  if (print) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht][iht];
	    double ne = numer_err[ifile][imulti][iat][iht][iht];
	    double d = denom[ifile][imulti][iat][iht][iht];
	    double de = denom_err[ifile][imulti][iat][iht][iht];
	    double r = ratio[ifile][imulti][iat][iht][iht];
	    double eh = errh[ifile][imulti][iat][iht][iht];
	    double el = errl[ifile][imulti][iat][iht][iht];
	    std::cout << " PRINT: \"" << type[ifile] << "\""
		      << " njets: " << multi[imulti]
		      << " aT: " << at[iat]
		      << " HT :" << ht[iht]
	      //<< ", pT :" << pt[iht]
		      << ", pass: " << n
 		      << " +/- " << ne
	      //<< " (" << ( n > 0. ? sqrt(n)/n : -1. ) << ")" 
		      << ", fail: " << d
 		      << " +/- " << de
	      //<< " (" << ( d > 0. ? sqrt(d)/d : -1. ) << ")" 
	      //<< " R: " << ( d > 0. ? n/d : -1. )
	      //<< " E: " << ( d > 0. ? sqrt(n*(n/(n+d))*(1-(n/(n+d)))) : -1. )
//   		      << ", ratio: " << r
//   		      << " + " << eh
//   		      << " - " << el
//  		      << " (" << int(( r > 0. ? eh/r : -1. )*100.) << "," 
//  		      << int(( r > 0. ? el/r : -1. )*100.) << ")" 
		      << std::endl;
	  }
	}
      }
    }
  }

  // -----------------------------------------------------------------------------
  // For Ted
  
  bool print_ted = true;
  if (print_ted) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  std::stringstream ted;
	  ted << "File: " << files[ifile]
	      << " Multiplicity: " << multi[imulti]
	      << " AlphaT: " << at[iat] 
	      << std::endl;
	  ted << "\"had\":\t\t" << float(lumi) << ", #lumi" << std::endl;
	  ted << "\"hadBulk\":\t" << float(lumi) << ", #lumi" << std::endl;

	  // Bulk
	  ted << "\"nHadBulk\":\t(";
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double d = denom[ifile][imulti][iat][iht][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << d << ", ";
	  }
	  ted << ")" << std::endl;

	  // Tail
	  ted << "\"nHad\":\t\t(";
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << n << ", ";
	  }
	  ted << ")" << std::endl;

	  // Mean HT
	  ted << "self._htMeans = (";
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << ht[iht] << ", ";
	  }
	  ted << ")" << std::endl;
	  std::cout << ted.str() << std::endl;

	}
      }
    }
  }

  // Calculate factor required to scale MC to data, using Nth bin
  std::cout << " CALCULATING SCALING FACTORS..." << std::endl;
  double scale_val[nfile][nmulti][nat][npt];
  double scale_errh[nfile][nmulti][nat][npt];
  double scale_errl[nfile][nmulti][nat][npt];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	for ( uint ipt = 0; ipt < npt; ++ipt ) {

	  scale_val[ifile][imulti][iat][ipt] = 0.;
	  scale_errh[ifile][imulti][iat][ipt] = 0.;
	  scale_errl[ifile][imulti][iat][ipt] = 0.;

	  // If no data file, use first sample with non-zero ratio in "bin"
	  int norm_file = 0;
	  if ( data_file == -1 ) {
	    for ( uint iifile = 0; iifile < nfile; ++iifile ) {
	      if ( ratio[iifile][imulti][iat][bin][bin] > 0. ) {
		norm_file = iifile; 
		break;
	      }
	    }
	  }

	  double d_val = ratio[norm_file][imulti][iat][bin][bin];
	  double d_errh = errh[norm_file][imulti][iat][bin][bin];
	  double d_errl = errl[norm_file][imulti][iat][bin][bin];
	  double mc_val = ratio[ifile][imulti][iat][bin][bin];
	  double mc_errh = errh[ifile][imulti][iat][bin][bin];
	  double mc_errl = errl[ifile][imulti][iat][bin][bin];

	  if ( mc_val > 0. ) { scale_val[ifile][imulti][iat][ipt] = d_val/mc_val; }

	  bool print = false;
	  std::stringstream ss;
	  calcErr( scale_val[ifile][imulti][iat][ipt],
		   scale_errh[ifile][imulti][iat][ipt],
		   scale_errl[ifile][imulti][iat][ipt],
		   d_val, d_errh, d_errl,
		   mc_val, mc_errh, mc_errl, 
		   print, ss );
	  
	  if ( print ) {
	    std::cout << " SCALE:"
		      << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << " pT:" << pt[ipt]
		      << ss.str()
		      << std::endl;
	  }

	} // ipt
      } // iat 
    } // imulti
  } // ifile
  
  // Store scaled MC values using factors above
  std::cout << " STORE SCALED MC VALUES..." << std::endl;
  double anchored_val[nfile][nmulti][nat][npt][nht];
  double anchored_errh[nfile][nmulti][nat][npt][nht];
  double anchored_errl[nfile][nmulti][nat][npt][nht];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	for ( uint ipt = 0; ipt < npt; ++ipt ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {

	    double r_val = ratio[ifile][imulti][iat][ipt][iht];
	    double r_errh = errh[ifile][imulti][iat][ipt][iht];
	    double r_errl = errl[ifile][imulti][iat][ipt][iht];
	    double s_val = scale_val[ifile][imulti][iat][ipt];
	    double s_errh = scale_errh[ifile][imulti][iat][ipt];
	    double s_errl = scale_errl[ifile][imulti][iat][ipt];
	    
	    anchored_val[ifile][imulti][iat][ipt][iht] = r_val * s_val;
	    anchored_errh[ifile][imulti][iat][ipt][iht] = 0.;
	    anchored_errl[ifile][imulti][iat][ipt][iht] = 0.;

	    bool print = false;
	    std::stringstream ss;
	    calcErr( anchored_val[ifile][imulti][iat][ipt][iht],
		     anchored_errh[ifile][imulti][iat][ipt][iht],
		     anchored_errl[ifile][imulti][iat][ipt][iht],
		     r_val, r_errh, r_errl,
		     s_val, s_errh, s_errl,
		     print, ss );

	    if ( print ) {
	      std::cout << " SCALED:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< " pT:" << pt[ipt]
			<< " HT:" << ht[iht]
			<< ss.str()
			<< std::endl;
	    }

	  } // iht
	} // ipt
      } // iat 
    } // imulti
  } // ifile

  // Scale MC to data using factors above
  std::cout << " ANCHORING MC TO DATA..." << std::endl;
  if ( anchor ) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint ipt = 0; ipt < npt; ++ipt ) {
	    for ( uint iht = 0; iht < nht; ++iht ) {
	      ratio[ifile][imulti][iat][ipt][iht] = anchored_val[ifile][imulti][iat][ipt][iht];
	      errh[ifile][imulti][iat][ipt][iht] = anchored_errh[ifile][imulti][iat][ipt][iht];
	      errl[ifile][imulti][iat][ipt][iht] = anchored_errl[ifile][imulti][iat][ipt][iht];
	      numer[ifile][imulti][iat][ipt][iht] *= scale_val[ifile][imulti][iat][ipt];
	    } // iht
	  } // ipt
	} // iat 
      } // imulti
    } // ifile
  } // anchor?

  // Calculate estimation
  std::cout << " CALCULATING ESTIMATE..." << std::endl;
  uint loop = 0;
  uint nloop = nfile * nmulti * nat * npt * nht;
  
  double r01_val[nfile][nmulti][nat];
  double r01_errh[nfile][nmulti][nat];
  double r01_errl[nfile][nmulti][nat];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	r01_val[ifile][imulti][iat] = 0.;
	r01_errh[ifile][imulti][iat] = 0.;
	r01_errl[ifile][imulti][iat] = 0.;
      }
    }
  }

  double r02_val[nfile][nmulti][nat];
  double r02_errh[nfile][nmulti][nat];
  double r02_errl[nfile][nmulti][nat];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	r02_val[ifile][imulti][iat] = 0.;
	r02_errh[ifile][imulti][iat] = 0.;
	r02_errl[ifile][imulti][iat] = 0.;
      }
    }
  }
  
  double estimate_val[nfile][nmulti][nat][npt][nht];
  double estimate_errh[nfile][nmulti][nat][npt][nht];
  double estimate_errl[nfile][nmulti][nat][npt][nht];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	std::cout << " Finished " << int(100*loop/nloop) << "%..." << std::endl;
	for ( uint ipt = 0; ipt < npt; ++ipt ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    loop++;
	    
	    // Only suitable for "flat" assumption
	    double r_val = ratio[ifile][imulti][iat][bin][bin];
	    double r_errh = errh[ifile][imulti][iat][bin][bin];
	    double r_errl = errl[ifile][imulti][iat][bin][bin];

	    // Events observed
	    double d_val = denom[ifile][imulti][iat][ipt][iht];
	    double d_errh = denom_err[ifile][imulti][iat][ipt][iht];
	    double d_errl = denom_err[ifile][imulti][iat][ipt][iht];
	    
	    estimate_val[ifile][imulti][iat][ipt][iht] = r_val * d_val;
	    estimate_errh[ifile][imulti][iat][ipt][iht] = 0.;
	    estimate_errl[ifile][imulti][iat][ipt][iht] = 0.;
	    
	    bool print = false;
	    std::stringstream ss;
	    calcErr( estimate_val[ifile][imulti][iat][ipt][iht],
		     estimate_errh[ifile][imulti][iat][ipt][iht],
		     estimate_errl[ifile][imulti][iat][ipt][iht],
		     r_val, r_errh, r_errl,
		     d_val, d_errh, d_errl, 
		     print, ss );
	  
	    if ( print ) {
	      std::cout << " ESTIMATE:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< " pT:" << pt[ipt]
			<< " HT:" << ht[iht]
			<< ss.str()
			<< std::endl;
	    }
	    
	    if ( two_measurements ) {
	      if ( ipt == 2 && iht == 2 ) {
		
		// Measurements from bins HT=250 and HT=300
		double b0_val = ratio[ifile][imulti][iat][bin][bin];
		double b0_errh = errh[ifile][imulti][iat][bin][bin];
		double b0_errl = errl[ifile][imulti][iat][bin][bin];
		double b1_val = ratio[ifile][imulti][iat][1][1];
		double b1_errh = errh[ifile][imulti][iat][1][1];
		double b1_errl = errl[ifile][imulti][iat][1][1];

		// Calc ratio of ratios
 		r01_val[ifile][imulti][iat] = ( b0_val > 0. ? b1_val/b0_val : 0. );

		bool print1 = false;
		std::stringstream ss1;
		calcErr( r01_val[ifile][imulti][iat],
			 r01_errh[ifile][imulti][iat],
			 r01_errl[ifile][imulti][iat],
			 b0_val, b0_errh, b0_errl,
			 b1_val, b1_errh, b1_errl,
			 print1, ss1 );
		
		if ( print1 ) {
		  std::cout << " TWO MEASUREMENTS:"
			    << " sample:\"" << type[ifile] << "\""
			    << " multi: " << multi[imulti]
			    << " aT:" << at[iat]
			    << " pT:" << pt[ipt]
			    << " HT:" << ht[iht]
			    << ss1.str()
			    << std::endl;
		}

	      } // ipt == iht == 2
	    } // two_measurements

	    if ( mc_measurement ) {
	      if ( ipt == 2 && iht == 2 ) {
		
		// Measurements from bins HT=250 and HT=350
		double b0_val = ratio[ifile][imulti][iat][bin][bin];
		double b0_errh = errh[ifile][imulti][iat][bin][bin];
		double b0_errl = errl[ifile][imulti][iat][bin][bin];
		double b2_val = ratio[ifile][imulti][iat][2][2];
		double b2_errh = errh[ifile][imulti][iat][2][2];
		double b2_errl = errl[ifile][imulti][iat][2][2];

		// Ratio of ratios from MC
		r02_val[ifile][imulti][iat] = ( b0_val > 0. ? b2_val/b0_val : 0. );

		bool print2 = false;
		std::stringstream ss2;
		calcErr( r02_val[ifile][imulti][iat],
			 r02_errh[ifile][imulti][iat],
			 r02_errl[ifile][imulti][iat],
			 b0_val, b0_errh, b0_errl,
			 b2_val, b2_errh, b2_errl,
			 print2, ss2 );
		
		if ( print2 ) {
		  std::cout << " MC MEASUREMENT:"
			    << " sample:\"" << type[ifile] << "\""
			    << " multi: " << multi[imulti]
			    << " aT:" << at[iat]
			    << " pT:" << pt[ipt]
			    << " HT:" << ht[iht] 
			    << ss2.str()
			    << std::endl;
		}
		
		
	      } // ipt == iht == 2
	    } // mc_measurement
	    
	  } // iht
	} // ipt
      } // iat
    } // imulti
  } // ifile

  // Extrapolation using two measurements in bins HT=250 and HT=300
  std::cout << " CALC TWO MEASUREMENTS... " << std::endl;
  if ( two_measurements ) {
    
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  
	  // Ratio in bin HT=300
	  double b1_val = ratio[ifile][imulti][iat][1][1];
	  double b1_errh = errh[ifile][imulti][iat][1][1];
	  double b1_errl = errl[ifile][imulti][iat][1][1];
	  
	  // Set ratio for HT=350 using "ratio of ratios"
	  double rr_val = r01_val[ifile][imulti][iat];
	  double rr_errh = r01_errh[ifile][imulti][iat];
	  double rr_errl = r01_errl[ifile][imulti][iat];
	  
	  // Set ratio for HT=350 using "ratio of ratios"
	  double r2_val = b1_val * rr_val;
	  double r2_errh = 0.;
	  double r2_errl = 0.;
	  
	  bool print = false;
	  std::stringstream ss;
	  calcErr( r2_val, r2_errh, r2_errl,
		   b1_val, b1_errh, b1_errl,
		   rr_val, rr_errh, rr_errl,
		   print, ss );
	  
	  if ( print ) {
	    std::cout << " TWO MEASUREMENTS: sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << ss.str() 
		      << std::endl;
	  }
	  
	  // Events observed to fail AlphaT cut in bin HT=350
	  double d2_val = denom[ifile][imulti][iat][2][2];
	  double d2_errh = denom_err[ifile][imulti][iat][2][2];
	  double d2_errl = denom_err[ifile][imulti][iat][2][2];

	  // Calculate estimate in bin HT=350
	  estimate_val[ifile][imulti][iat][2][2] = d2_val * r2_val;
	  estimate_errh[ifile][imulti][iat][2][2] = 0.;
	  estimate_errl[ifile][imulti][iat][2][2] = 0.;
	  
	  std::stringstream sss;
	  calcErr( estimate_val[ifile][imulti][iat][2][2],
		   estimate_errh[ifile][imulti][iat][2][2],
		   estimate_errl[ifile][imulti][iat][2][2],
		   r2_val, r2_errh, r2_errl,
		   d2_val, d2_errh, d2_errl,
		   print, sss );

	  if ( print ) {
	    std::cout << " TWO MEASUREMENTS : sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << sss.str() 
		      << std::endl;
	  }

	} // iat
      } // imulti
    } // ifile
  } // two_measurements

  // Estimate using two MC measurements in bins HT=250 and HT=350
  std::cout << " CALC MC MEASUREMENTS... " << std::endl;
  if ( mc_measurement ) {

    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  
	  if ( int(ifile) != data_file ) {
	    
	    // Ratio of events (from data) observed to pass AlphaT cut in bin HT=250
	    double d0_val = ratio[data_file][imulti][iat][bin][bin];
	    double d0_errh = errh[data_file][imulti][iat][bin][bin];
	    double d0_errl = errl[data_file][imulti][iat][bin][bin];
	    
	    // Set ratio for HT=350 using "ratio of ratios"
	    double rr_val = r02_val[ifile][imulti][iat];
	    double rr_errh = r02_errh[ifile][imulti][iat];
	    double rr_errl = r02_errl[ifile][imulti][iat];
	    
	    double r2_val = d0_val * rr_val;
	    double r2_errh = 0.;
	    double r2_errl = 0.;
	    
	    bool print = false;
	    std::stringstream ss;
	    calcErr( r2_val, r2_errh, r2_errl,
		     rr_val, rr_errh, rr_errl,
		     d0_val, d0_errh, d0_errl,
		     print, ss );
	    
	    if ( print ) {
	      std::cout << " MC MEASUREMENT:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< ss.str()
			<< std::endl;
	    }
	    
	    // Events (from data) observed to fail AlphaT cut in bin HT=350
	    double d2_val = denom[data_file][imulti][iat][2][2];
	    double d2_errh = denom_err[data_file][imulti][iat][2][2];
	    double d2_errl = denom_err[data_file][imulti][iat][2][2];
	    
	    estimate_val[ifile][imulti][iat][2][2] = d2_val * r2_val;
	    estimate_errh[ifile][imulti][iat][2][2] = 0.;
	    estimate_errl[ifile][imulti][iat][2][2] = 0.;
	    
	    std::stringstream sss;
	    calcErr( estimate_val[ifile][imulti][iat][2][2],
		     estimate_errh[ifile][imulti][iat][2][2],
		     estimate_errl[ifile][imulti][iat][2][2],
		     r2_val, r2_errh, r2_errl,
		     d2_val, d2_errh, d2_errl,
		     print, sss );

	    if ( print ) {
	      std::cout << " MC MEASUREMENT:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< sss.str()
			<< std::endl;
	    }

	    
	  } // ifile
	} // iat
      } // imulti
    } // ifile
  } // mc_measurement

  // Table of results
  std::cout << " CONSTRUCTING TABLES..." << std::endl;
  if (true) {
    
    double predicted_val[nfile][nmulti][nat];
    double predicted_errh[nfile][nmulti][nat];
    double predicted_errl[nfile][nmulti][nat];
    double observed_val[nfile][nmulti][nat];
    double observed_errh[nfile][nmulti][nat];
    double observed_errl[nfile][nmulti][nat];
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  predicted_val[ifile][imulti][iat] = 0.;
	  predicted_errh[ifile][imulti][iat] = 0.;
	  predicted_errl[ifile][imulti][iat] = 0.;
	  observed_val[ifile][imulti][iat] = 0.;
	  observed_errh[ifile][imulti][iat] = 0.;
	  observed_errl[ifile][imulti][iat] = 0.;
	}
      }
    }

    std::stringstream ss;
    ss << std::endl;
    for ( uint iat = 0; iat < nat; ++iat ) { //@@ Go from aT = 0.52 -> 0.55
	
      ss << "\\begin{table}[!h]" << std::endl
	 << " \\begin{center}" << std::endl;

      // Alignment
      ss << "  \\begin{tabular}{c";
      if (pt_thresholds) { ss << "cccc"; }
      if ( mc_measurement ) { 
	ss << "r@{$\\ \\pm\\ $}l"; 
	for ( uint ifile = 0; ifile < nfile; ++ifile ) { 
	  if ( print_ratio ) { ss << "r@{$\\ \\pm\\ $}lr@{$\\ \\pm\\ $}l"; }
	  else { ss << "r@{$\\ \\pm\\ $}lr@{$\\ \\pm\\ $}lr@{$\\ \\pm\\ $}l"; }
	}
      } else {
	for ( uint ifile = 0; ifile < nfile; ++ifile ) { ss << "r@{$\\ \\pm\\ $}lr@{$\\ \\pm\\ $}l"; }
      }
      ss << "}";
      ss << std::endl;
      ss << "   \\hline\\noalign{\\smallskip}" << std::endl;

      // Labels
      ss << "   $N_{jet}$ & ";
      if ( pt_thresholds ) { ss << "HT & $p_{T}^{jet1}$ & $p_{T}^{jet2}$ & $p_{T}^{jet3}$ &"; }
      if ( mc_measurement ) {
	ss << " \\multicolumn{2}{c}{$R^{" << type[data_file] << "}_{350/250}$} & "; 
	if ( print_ratio ) {
	  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	    if ( int(ifile) != data_file ) {
	      ss << " \\multicolumn{2}{c}{$R^{" << type[ifile] << "}_{350/250}$} & ";
	    }
	  }
	}
      } 
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	if ( !(mc_measurement && int(ifile) == data_file) ) {
	  ss << " \\multicolumn{2}{c}{$N^{" << type[ifile] << "}_{predicted}$} & "
	     << " \\multicolumn{2}{c}{$N^{" << type[ifile] << "}_{observed}$}";
	  if ( nfile-ifile > 1 ) { ss << " & "; }
	}
      }
      ss << " \\\\" << std::endl; 
      
      // Units
      if ( pt_thresholds ) { 
	ss << "  & $[$GeV$]$ & $[$GeV$]$ & $[$GeV$]$ & $[$GeV$]$ & ";
	if ( mc_measurement ) { ss << "\\multicolumn{" << 2+4*nfile << "}{c}{} \\\\" << std::endl; }
	else { ss << "\\multicolumn{" << 4*nfile << "}{c}{} \\\\" << std::endl; }
      }
      ss << "   \\noalign{\\smallskip}\\hline\\noalign{\\smallskip}" << std::endl;

      // Data
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {

	double meff = ht[ht_bin] + pt[ht_bin];
	double pt1 = x1_default * meff;
	double pt2 = x2_default * meff;
	      
	// 	if ( multi[imulti] < 0 && once ) {
	// 	  ss << "   \\hline\\noalign{\\smallskip}" << std::endl;
	// 	  once = false;
	// 	}

	ss << "   "; 
	if ( multi[imulti] > 0 ) { ss << multi[imulti] << " & "; }
	else if ( multi[imulti] == 0 ) { ss << "$\\geq2$ & "; }
	else { ss << "$\\geq$" << abs(multi[imulti]) << " & "; }
	
	if ( pt_thresholds ) { 
	  ss << ht[ht_bin] << " & " 
	     << dr(pt1,dec_places) << " & " 
	     << dr(pt2,dec_places) << " & " 
	     << dr(pt[ht_bin],dec_places) << " & ";
	}
	
	if ( mc_measurement ) {
	  ss << "$" << sr(r02_val[data_file][imulti][iat],sig_figs) << "$&$" 
	     << "^{" << sr(r02_errh[data_file][imulti][iat],sig_figs) << "}_{" 
	     << sr(r02_errl[data_file][imulti][iat],sig_figs) << "}$ & ";
	  if ( print_ratio ) {
	    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	      if ( int(ifile) != data_file ) {
		ss << "$" << sr(r02_val[ifile][imulti][iat],sig_figs) << "$&$" 
		   << "^{" << sr(r02_errh[ifile][imulti][iat],sig_figs) << "}_{" 
		   << sr(r02_errl[ifile][imulti][iat],sig_figs) << "}$ & ";
	      }
	    }
	  }
	}
 
	for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	  //std::cout << ifile << " " << imulti << " " << iat << " " << ipt << std::endl;
	      
	  double e_val = estimate_val[ifile][imulti][iat][ht_bin][ht_bin];
	  double e_errh = estimate_errh[ifile][imulti][iat][ht_bin][ht_bin];
	  double e_errl = estimate_errl[ifile][imulti][iat][ht_bin][ht_bin];
	  double n_val = numer[ifile][imulti][iat][ht_bin][ht_bin];
	  double n_err = numer_err[ifile][imulti][iat][ht_bin][ht_bin];
	  
	  if ( mc_measurement ) {
	    n_val = numer[data_file][imulti][iat][ht_bin][ht_bin];
	    n_err = numer_err[data_file][imulti][iat][ht_bin][ht_bin];
	    if ( int(ifile) != data_file ) {
	      ss << "$" << sr(e_val,sig_figs) << "$&$" 
		 << "^{" << sr(e_errh,sig_figs) << "}_{" 
		 << sr(e_errl,sig_figs) << "}$ & " 
		 << "$" << dr(n_val,dec_places) << "$&$" 
		 << dr(n_err,dec_places) << "$";
	      if ( nfile-ifile > 1 ) { ss << " & "; }
	      // Difference
	      predicted_val[ifile][imulti][iat] = e_val;
	      predicted_errh[ifile][imulti][iat] = e_errh;
	      predicted_errl[ifile][imulti][iat] = e_errl;
	      observed_val[ifile][imulti][iat] = n_val;
	      observed_errh[ifile][imulti][iat] = sqrt( e_errh*e_errh + n_err*n_err ); 
	      observed_errl[ifile][imulti][iat] = sqrt( e_errl*e_errl + n_err*n_err ); 
	    }
	  } else {
	    ss << "$" << sr(e_val,sig_figs) << "$&$" 
	       << "^{" << sr(e_errh,sig_figs) << "}_{" 
	       << sr(e_errl,sig_figs) << "}$ & " 
	       << "$" << dr(n_val,dec_places) << "$&$" 
	       << dr(n_err,dec_places) << "$";
	    if ( nfile-ifile > 1 ) { ss << " & "; }
	    // Difference
	    predicted_val[ifile][imulti][iat] = e_val;
	    predicted_errh[ifile][imulti][iat] = e_errh;
	    predicted_errl[ifile][imulti][iat] = e_errl;
	    observed_val[ifile][imulti][iat] = n_val;
	    observed_errh[ifile][imulti][iat] = sqrt( e_errh*e_errh + n_err*n_err ); 
	    observed_errl[ifile][imulti][iat] = sqrt( e_errl*e_errl + n_err*n_err ); 
	  }
	  
	} // ifile
	ss << " \\\\" << std::endl;
	
      } // imulti

      ss << "   \\noalign{\\smallskip}\\hline" << std::endl;
      ss << "  \\end{tabular}" << std::endl;
      ss << "  \\caption{";
      if ( ht_bin == nht-1 ) { ss << "$H_{T} \\geq " << ht[ht_bin] << "$"; }
      else { ss << "$" << ht[ht_bin] << " \\leq H_{T} < " << ht[ht_bin]+ht_step[ht_bin] << "$"; }
      ss << " and $\\alpha_{T} \\geq " << at[iat] /1000. << "$"
	 << ".}" << std::endl;
      //ss << " $R^{mc}_{\\alpha_{T}}(" << at[iat]/1000. << ")$" 
      //<< "$ = "
      //<< anchored_val[0][iat][bin][bin] << " \\pm ^{" 
      //<< anchored_errh[0][iat][bin][bin] << "}_{"
      //<< anchored_errl[0][iat][bin][bin] << "}$"
      //<< " and "
      //<< "$R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ")$"
      //<< "$ = " 
      //<< anchored_val[1][iat][bin][bin] << " \\pm ^{" 
      //<< anchored_errh[1][iat][bin][bin] << "}_{"
      //<< anchored_errl[1][iat][bin][bin] << "}$"
      //ss << ".}" << std::endl;
      // 	ss// << std::setprecision(2)
      // 	  << "  \\caption{QCD estimation for MC and data in different HT bins, based the measurements"
      // 	  << " $R^{mc}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
      // 	  << anchored_val[0][iat][bin][bin] << " \\pm ^{" 
      // 	  << anchored_errh[0][iat][bin][bin] << "}_{"
      // 	  << anchored_errl[0][iat][bin][bin] << "}$"
      // 	  << " and $R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
      // 	  << anchored_val[1][iat][bin][bin] << " \\pm ^{" 
      // 	  << anchored_errh[1][iat][bin][bin] << "}_{"
      // 	  << anchored_errl[1][iat][bin][bin] << "}$"
      // 	  << " using the bin $HT=" << ht[bin] << "$. The $p_{T}$ thresholds on the $N^{th}$ jet are scaled with HT"
      // 	  << " such that the allowed kinematic phase space is fixed as"
      // 	  << " $(x_{1},x_{2},x_{3}) = (" << x1_default << ", " << x2_default << ", " << x2_default << ")$"
      // 	  << ", using the normalisation $x_{1} + x_{2} + x_{3} = 2$.}"
      // 	  << std::endl;
      ss << " \\end{center}" << std::endl;
      ss << "\\end{table}" << std::endl;
      ss << std::endl;

    } // iat

    std::cout << ss.str();

    // Plot N_{predicted} - N_{observed}
    if (syst_plot) {
      gStyle->SetOptStat("emr");

      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {

	  std::stringstream ss3;
	  ss3 << "Difference_AlphaT_" << at[iat] << "_Multi" << multi[imulti];
	  TCanvas* c1 = new TCanvas(ss3.str().c_str(),ss3.str().c_str());
	  c1->SetFillColor(0);
	  c1->SetLineColor(0); 
	  TH1D* difference = 0;
	  if ( syst_ratio ) { difference = new TH1D(ss3.str().c_str(),"",400,-2.,2.); }
	  else              { difference = new TH1D(ss3.str().c_str(),"",400,-2.,2.); }
	  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	    //if ( int(ifile) == data_file ) { continue; }
	    if ( syst_ratio ) {
	      if ( predicted_val[ifile][imulti][iat] != 0. ) {
		difference->Fill( observed_val[ifile][imulti][iat]/predicted_val[ifile][imulti][iat], 1. );
	      }
	    } else {
	      difference->Fill( predicted_val[ifile][imulti][iat]-observed_val[ifile][imulti][iat], 1. );
	    }
	    if (true) {
	      std::cout << " PREDICTED/OBSERVED:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]/1000.
			<< " pred: " << predicted_val[ifile][imulti][iat]
			<< " obs: " << observed_val[ifile][imulti][iat]
			<< " diff: " << predicted_val[ifile][imulti][iat] - observed_val[ifile][imulti][iat]
			<< " errorh: " << observed_errh[ifile][imulti][iat]
			<< " errorl: " << observed_errl[ifile][imulti][iat]
			<< std::endl;
	    }
	  }
	  c1->cd();
	  difference->Draw("h");
	  //c1->SaveAs(TString(ss3.str()+".png")); 
	  c1->SaveAs(TString(ss3.str()+".pdf")); 
	}
      }
    }
      
    // Plot ( N_{predicted} - N_{observed} ) vs AlphaT
    if (killer) {

      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {

	std::stringstream ss2;
	ss2 << "DifferenceVsAlphaT_Multi" << multi[imulti];

	TCanvas* c1 = new TCanvas(ss2.str().c_str(),"");
	c1->SetFillColor(0);
	c1->SetLineColor(0); 
	c1->SetRightMargin(0.2);
	TLegend* legend = new TLegend( 0.82, 0.5, 0.98, 0.9, NULL, "brNDC" );
	legend->SetFillColor(0);
	legend->SetLineColor(0); 
	legend->SetShadowColor(0); 
      
	TMultiGraph* mg = new TMultiGraph();
	for ( uint ifile = 0; ifile < nfile; ++ifile ) {

	  double scale_offset = 0.;
	
	  if ( mc_measurement && int(ifile) == data_file ) { continue; }
	  std::vector<double> xval;
	  std::vector<double> xerrl;
	  std::vector<double> xerrh;
	  std::vector<double> yval;
	  std::vector<double> yerrl;
	  std::vector<double> yerrh;
	  for ( uint iat = 0; iat < nat; ++iat ) {

	    double val = scale_offset + predicted_val[ifile][imulti][iat] - observed_val[ifile][imulti][iat];

	    if ( predicted_val[ifile][imulti][iat] <= 0. ) { continue; }

	    double width = 0.;
	    if ( nat > 1 ) { 
	      if ( iat < nat-1 ) { width = at[iat+1]/1000. - at[iat]/1000.; }
	      else { width = at[iat]/1000. - at[iat-1]/1000.; }
	    } 
	    xval.push_back( at[iat]/1000. + width/2. + axis_offset2*ifile );
	    xerrl.push_back( width/2. - axis_offset2*ifile );
	    xerrh.push_back( width/2. + axis_offset2*ifile );
	    yval.push_back( val );
	    yerrl.push_back( observed_errh[ifile][imulti][iat] );
	    yerrh.push_back( observed_errl[ifile][imulti][iat] );

	    if (true) {
	      std::cout << " PREDICTED/OBSERVED:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]/1000.
			<< " pred: " << predicted_val[ifile][imulti][iat]
			<< " obs: " << observed_val[ifile][imulti][iat]
			<< " diff: " << yval.back()
			<< " errorh: " << observed_errh[ifile][imulti][iat]
			<< " errorl: " << observed_errl[ifile][imulti][iat]
			<< std::endl;
	    }
	  
	    // Check on stat errors
	    if (false) {
	      double b2_mean = 0.;
	      double b2_rms = 0.;
	      double b2_err = 0.;
	      checkStats( type, multi, at,
			  ifile, imulti, iat,
			  numer[ifile][imulti][iat][2][2],
			  estimate_val[ifile][imulti][iat][2][2],
			  estimate_errh[ifile][imulti][iat][2][2],
			  estimate_errl[ifile][imulti][iat][2][2],
			  numer[ifile][imulti][iat][0][0],
			  denom[ifile][imulti][iat][0][0],
			  numer[ifile][imulti][iat][1][1],
			  denom[ifile][imulti][iat][1][1],
			  denom[ifile][imulti][iat][2][2],
			  b2_mean, 
			  b2_rms, 
			  b2_err );
	    }

	  }
	
	  // 	for ( uint iat = 0; iat < yval.size(); ++iat ) {
	  // 	  if (false) {
	  // 	    std::cout << " PREDICTED/OBSERVED:"
	  // 		      << " sample:\"" << type[ifile] << "\""
	  // 		      << " multi: " << multi[imulti]
	  // 		      << " aT:" << xval[iat]
	  // 		      << " diff: " << yval[iat]
	  // 		      << " yerrl: " << yval[iat] - yerrl[iat]
	  // 		      << " yerrh: " << yval[iat] + yerrh[iat]
	  // 		      << std::endl;
	  // 	  }
	  // 	}

	  std::stringstream ss;
	  ss << type[ifile];
	  TGraphAsymmErrors* gr = 0;
	
	  if ( !xval.empty() ) {
	    gr = new TGraphAsymmErrors(xval.size(),
				       &xval.front(),&yval.front(),
				       &xerrl.front(),&xerrh.front(),
				       &yerrl.front(),&yerrh.front());
	    mg->Add(gr,"p");
	    gr->SetTitle(TString(ss.str()));
	    gr->SetLineColor(col[ifile]);
	    gr->SetMarkerStyle(style[ifile]);
	    gr->SetMarkerColor(col[ifile]);
	    legend->AddEntry( gr, TString(ss.str()), "lep" );
	  }
	
	}

	c1->cd();
	mg->Draw("a");
	mg->GetXaxis()->SetTitle("#alpha_{T} cut value");
	mg->GetYaxis()->SetTitle("N_{predicted} - N_{observed}");
	//mg->GetYaxis()->SetRangeUser(-20.,15.);
	legend->Draw("same");
	c1->Update();
	c1->SaveAs(TString(ss2.str()+".C")); 
	//c1->SaveAs(TString(ss2.str()+".png")); 
	c1->SaveAs(TString(ss2.str()+".pdf")); 
      
      }
    }
  }
  
//   // Table of results
//   std::cout << " CONSTRUCTING TABLES..." << std::endl;
//   if (true) {

//     double pred_val[nfile][nat][npt];
//     double pred_errh[nfile][nat][npt];
//     double pred_errl[nfile][nat][npt];
//     double obs_val[nfile][nat][npt];
//     double obs_err[nfile][nat][npt];
//     for ( uint ifile = 0; ifile < nfile; ++ifile ) {
//       for ( uint iat = 0; iat < nat; ++iat ) {
// 	for ( uint ipt = 0; ipt < npt; ++ipt ) {
// 	  pred_val[ifile][iat][ipt] = 0.;
// 	  pred_errh[ifile][iat][ipt] = 0.;
// 	  pred_errl[ifile][iat][ipt] = 0.;
// 	  obs_val[ifile][iat][ipt] = 0.;
// 	  obs_err[ifile][iat][ipt] = 0.;
// 	}
//       }
//     }

//     std::stringstream ss;
//     ss << std::endl;
//     for ( uint iat = 0; iat < nat; ++iat ) { //@@ Go from aT = 0.52 -> 0.55
	
//       ss << "\\begin{table}[!h]" << std::endl
// 	 << " \\begin{center}" << std::endl;

//       // Alignment
//       ss << "  \\begin{tabular}{c";
//       if (ht_scale) { ss << "cccc"; }
//       for ( uint ifile = 0; ifile < nfile; ++ifile ) { ss << "r@{$\\ \\pm\\ $}lr@{$\\ \\pm\\ $}l"; }
//       ss << "}";
//       ss << "   \\hline\\noalign{\\smallskip}" << std::endl;

//       // Labels
//       ss << "   $N_{jet}$ & ";
//       if ( ht_scale ) { ss << "HT & $p_{T}^{jet1}$ & $p_{T}^{jet2}$ & $p_{T}^{jet3}$ &"; }
//       if ( mc_measurement ) {
// 	for ( uint ifile = 0; ifile < nfile; ++ifile ) {
// 	  ss << " \\multicolumn{2}{c}{$R^{" << type[ifile] << "}_{350/250}$} & "; //ss << " \\multicolumn{4}{c}{}";
// 	}
// 	ss << " \\multicolumn{2}{c}{$N^{" << type[data_file] << "}_{predicted}$} & "
// 	   << " \\multicolumn{2}{c}{$N^{" << type[data_file] << "}_{observed}$}";
//       } else {
// 	for ( uint ifile = 0; ifile < nfile; ++ifile ) {
// 	  ss << " \\multicolumn{2}{c}{$N^{" << type[ifile] << "}_{predicted}$} & "
// 	     << " \\multicolumn{2}{c}{$N^{" << type[ifile] << "}_{observed}$}";
// 	  if ( ifile < nfile-1 ) { ss << " & "; }
// 	}
//       }
//       ss << " \\\\" << std::endl; 

//       // Units
//       if ( ht_scale ) { 
// 	ss << "  & $[$GeV$]$ & $[$GeV$]$ & $[$GeV$]$ & $[$GeV$]$ & ";
// 	ss << "\\multicolumn{" << 4*nfile << "}{c}{} \\\\" << std::endl;
//       }
//       ss << "   \\noalign{\\smallskip}\\hline\\noalign{\\smallskip}" << std::endl;

//       // Data
//       bool once = true;
//       for ( uint imulti = 0; imulti < nmulti; ++imulti ) {

// 	double meff = ht[ht_bin] + pt[ht_bin];
// 	double pt1 = x1_default * meff;
// 	double pt2 = x2_default * meff;
	      
// 	if ( multi[imulti] < 0 && once ) {
// 	  ss << "   \\hline\\noalign{\\smallskip}" << std::endl;
// 	  once = false;
// 	}

// 	ss << "   "; 
// 	if ( multi[imulti] >= 0 ) { ss << multi[imulti] << " & "; }
// 	else { ss << "$\\geq$" << abs(multi[imulti]) << " & "; }
	
// 	if ( ht_scale ) { 
// 	  ss << ht[ht_bin] << " & " 
// 	     << dr(pt1,dec_places) << " & " 
// 	     << dr(pt2,dec_places) << " & " 
// 	     << dr(pt[ht_bin],dec_places) << " & ";
// 	}
	
// 	if ( mc_measurement ) {
// 	  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
// 	    ss << "$" << sr(r02_val[ifile][imulti][iat],sig_figs) << "$&$" 
// 	       << "^{" << sr(r02_errh[ifile][imulti][iat],sig_figs) << "}_{" 
// 	       << sr(r02_errl[ifile][imulti][iat],sig_figs) << "}$ & ";
// 	  }
// 	}
	    
// 	for ( uint ifile = 0; ifile < nfile; ++ifile ) {
// 	  //std::cout << ifile << " " << imulti << " " << iat << " " << ipt << std::endl;
	      
// 	  double e_val = estimate_val[ifile][imulti][iat][ht_bin][ht_bin];
// 	  double e_errh = estimate_errh[ifile][imulti][iat][ht_bin][ht_bin];
// 	  double e_errl = estimate_errl[ifile][imulti][iat][ht_bin][ht_bin];
// 	  double n_val = numer[ifile][imulti][iat][ht_bin][ht_bin];
// 	  double n_err = sqrt(numer[ifile][imulti][iat][ht_bin][ht_bin]);
		
// 	  if ( mc_measurement ) {
// 	    if ( int(ifile) == data_file ) {
// 	      ss << "$" << sr(e_val,sig_figs) << "$&$" 
// 		 << "^{" << sr(e_errh,sig_figs) << "}_{" 
// 		 << sr(e_errl,sig_figs) << "}$ & " 
// 		 << "$" << dr(n_val,dec_places) << "$&$" 
// 		 << dr(n_err,dec_places) << "$";
// 	    }
// 	  } else {
// 	    ss << "$" << sr(e_val,sig_figs) << "$&$" 
// 	       << "^{" << sr(e_errh,sig_figs) << "}_{" 
// 	       << sr(e_errl,sig_figs) << "}$ & " 
// 	       << "$" << dr(n_val,dec_places) << "$&$" 
// 	       << dr(n_err,dec_places) << "$";
// 	    if ( ifile < nfile-1 ) { ss << " & "; }
// 	  }

// 	} // ifile
// 	ss << " \\\\" << std::endl;
	
//       } // imulti

//       ss << "   \\noalign{\\smallskip}\\hline" << std::endl;
//       ss << "  \\end{tabular}" << std::endl;
//       ss << "  \\caption{"
// 	 << " Predicted and measured QCD yields for "
// 	 << " the cut value $\\alpha_{T} = " << at[iat] /1000. << "$ and ";
//       if ( ht_bin == nht-1 ) { ss << "$H_{T} \\geq " << ht[ht_bin] << "$"; }
//       else { ss << "$" << ht[ht_bin] << " \\leq H_{T} < " << ht[ht_bin]+ht_step << "$"; }
//       //ss << " $R^{mc}_{\\alpha_{T}}(" << at[iat]/1000. << ")$" 
//       //<< "$ = "
//       //<< anchored_val[0][iat][bin][bin] << " \\pm ^{" 
//       //<< anchored_errh[0][iat][bin][bin] << "}_{"
//       //<< anchored_errl[0][iat][bin][bin] << "}$"
//       //<< " and "
//       //<< "$R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ")$"
//       //<< "$ = " 
//       //<< anchored_val[1][iat][bin][bin] << " \\pm ^{" 
//       //<< anchored_errh[1][iat][bin][bin] << "}_{"
//       //<< anchored_errl[1][iat][bin][bin] << "}$"
//       ss << ".}" << std::endl;
//       // 	ss// << std::setprecision(2)
//       // 	  << "  \\caption{QCD estimation for MC and data in different HT bins, based the measurements"
//       // 	  << " $R^{mc}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
//       // 	  << anchored_val[0][iat][bin][bin] << " \\pm ^{" 
//       // 	  << anchored_errh[0][iat][bin][bin] << "}_{"
//       // 	  << anchored_errl[0][iat][bin][bin] << "}$"
//       // 	  << " and $R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
//       // 	  << anchored_val[1][iat][bin][bin] << " \\pm ^{" 
//       // 	  << anchored_errh[1][iat][bin][bin] << "}_{"
//       // 	  << anchored_errl[1][iat][bin][bin] << "}$"
//       // 	  << " using the bin $HT=" << ht[bin] << "$. The $p_{T}$ thresholds on the $N^{th}$ jet are scaled with HT"
//       // 	  << " such that the allowed kinematic phase space is fixed as"
//       // 	  << " $(x_{1},x_{2},x_{3}) = (" << x1_default << ", " << x2_default << ", " << x2_default << ")$"
//       // 	  << ", using the normalisation $x_{1} + x_{2} + x_{3} = 2$.}"
//       // 	  << std::endl;
//       ss << " \\end{center}" << std::endl;
//       ss << "\\end{table}" << std::endl;
//       ss << std::endl;

//     } // iat

//     std::cout << ss.str();

//   }

  // -----------------------------------------------------------------------------
  if ( true ) {

    // Variable to plot
    std::cout << " EXTRACTING VALUES TO PLOT..." << std::endl;
    double valx[nfile][nmulti][nat][nht];
    double errxh[nfile][nmulti][nat][nht];
    double errxl[nfile][nmulti][nat][nht];
    double valy[nfile][nmulti][nat][nht];
    double erryh[nfile][nmulti][nat][nht];
    double erryl[nfile][nmulti][nat][nht];
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    valx[ifile][imulti][iat][iht] = 0.;
	    errxh[ifile][imulti][iat][iht] = 0.;
	    errxl[ifile][imulti][iat][iht] = 0.;
	    valy[ifile][imulti][iat][iht] = 0.;
	    erryh[ifile][imulti][iat][iht] = 0.;
	    erryl[ifile][imulti][iat][iht] = 0.;
	    if ( choice == PLOT_NUMERATOR ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = numer[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = numer_err[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = numer_err[ifile][imulti][iat][iht][iht];
	    } else if ( choice == PLOT_DENOMINATOR ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = denom[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = denom_err[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = denom_err[ifile][imulti][iat][iht][iht];
	    } else if ( choice == PLOT_ESTIMATE ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = estimate_val[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = estimate_errh[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = estimate_errl[ifile][imulti][iat][iht][iht];
	    } else if ( choice == PLOT_ANCHORED ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = anchored_val[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = anchored_errh[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = anchored_errl[ifile][imulti][iat][iht][iht];
	    } else if ( choice == PLOT_RATIO ) {
	      //if ( iht < length[ifile][imulti][iat] ) {
		valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
		errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
		errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
		valy[ifile][imulti][iat][iht] = ratio[ifile][imulti][iat][iht][iht];
		erryh[ifile][imulti][iat][iht] = errh[ifile][imulti][iat][iht][iht];
		erryl[ifile][imulti][iat][iht] = errl[ifile][imulti][iat][iht][iht];
		//}
	    }
	  }
	}
      }
    }

    if ( choice == PLOT_NUMERATOR ) { 
      std::cout << "Plotting numerator..." << std::endl;
    } else if ( choice == PLOT_DENOMINATOR ) { 
      std::cout << "Plotting denominator..." << std::endl;
    } else if ( choice == PLOT_ESTIMATE ) { 
      std::cout << "Plotting estimate..." << std::endl;
    } else if ( choice == PLOT_ANCHORED ) { 
      std::cout << "Plotting anchored..." << std::endl;
    } else if ( choice == PLOT_RATIO ) { 
      std::cout << "Plotting ratio..." << std::endl;
    } else { 
      std::cout << "Plotting unknown!!..." << std::endl;
    }
    
    // -----------------------------------------------------------------------------
    // Calculate min and max values for y-axis (ratio)
    
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	min[imulti][iat] = 1.e12;
	max[imulti][iat] = 1.e-12;
	for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    if ( ht[iht] < ht_min && ht[iht] > ht_max ) { continue; }
	    double ymin = valy[ifile][imulti][iat][iht] - erryl[ifile][imulti][iat][iht];
	    double ymax = valy[ifile][imulti][iat][iht] + erryh[ifile][imulti][iat][iht];
	    if ( valy[ifile][imulti][iat][iht] > 0. &&
		 valy[ifile][imulti][iat][iht] < min[imulti][iat] ) {
	      if ( min_max_with_errors && ymin > 0. && ymin < min[imulti][iat] ) { min[imulti][iat] = ymin; }
	      else { min[imulti][iat] = valy[ifile][imulti][iat][iht]; }
	    }
	    if ( valy[ifile][imulti][iat][iht] > 0. &&
		 valy[ifile][imulti][iat][iht] > max[imulti][iat] ) {
	      if ( min_max_with_errors && ymax > 0. && ymax > max[imulti][iat] ) { max[imulti][iat] = ymax; }
	      else { max[imulti][iat] = valy[ifile][imulti][iat][iht]; }
	    }
	  }
	}
      }
    }
    
    if (false) {
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	  for ( uint iat = 0; iat < nat; ++iat ) {
	    for ( uint ipt = 0; ipt < npt; ++ipt ) {
	      std::cout << " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< " pT:" << pt[ipt]
			<< " min:" << min[imulti][iat]
			<< " max:" << max[imulti][iat]
			<< std::endl;
	    }
	  }
	}
      }
    }
    
    if (false) {
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	  for ( uint iat = 0; iat < nat; ++iat ) {
	    for ( uint ipt = 0; ipt < npt; ++ipt ) {
	      std::cout << " PLOTTING:"
			<< " sample:\"" << type[ifile] << "\""
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< " pT:" << pt[ipt]
			<< " valy: " << valy[ifile][imulti][iat][ipt]
			<< " erryh: " << erryh[ifile][imulti][iat][ipt]
			<< " erryl: " << erryl[ifile][imulti][iat][ipt]
			<< std::endl;
	    }
	  }
	}
      }
    }
    
    // Check number of pt and ht bins are the same
    std::cout << " CREATING PLOTS..." << std::endl;
    if ( npt == nht ) {

      // -----------------------------------------------------------------------------
      // Create plots


      std::vector<double> rat;
      std::vector<float> fits;
      
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	
	for ( uint iat = 0; iat < nat; ++iat ) {
	  
	  std::string name;
	  if ( choice == PLOT_NUMERATOR ) { name = "Pass"; } 
	  else if ( choice == PLOT_DENOMINATOR ) {
	    if ( efficiency ) { name = "Total"; }
	    else { name = "Fail"; }
	  }
	  else if ( choice == PLOT_ESTIMATE ) { name = "Estimate"; } 
	  else if ( choice == PLOT_ANCHORED ) { name = "Anchored"; } 
	  else if ( choice == PLOT_RATIO ) { 
	    if ( efficiency ) { name = "Eff"; }
	    else { name = "Ratio"; }
	  } 
	  else { name = "Unknown"; } 
  
	  std::stringstream ss_canvas;
	  ss_canvas << "Multi";
	  if ( multi[imulti] >= 0 ) { ss_canvas << multi[imulti]; }
	  else { ss_canvas << abs(multi[imulti]) << "Incl"; }
	  ss_canvas << "_AlphaT" << at[iat]/10.;

	  gStyle->SetOptFit(0);
 	  TCanvas* canvas = 0;
 	  TLegend* legend = 0;
 	  TLatex* prelim = 0;
 	  TLatex* lumitxt = 0;
 	  TMultiGraph* mg = 0;

	  if (plots) {
	    canvas = new TCanvas(TString(name+"_"+ss_canvas.str()),
				 TString(name+"_"+ss_canvas.str()),800,600);
	    
	    canvas->SetFillColor(0);
	    canvas->SetLineColor(0); 
	    if(ewk) canvas->SetLogy();
	    
	    canvas->SetLeftMargin(0.17);
	    
	    legend = new TLegend( 0.6, 0.65, 0.8, 0.85, NULL, "brNDC" );
	    legend->SetTextSize(0.035);
	    legend->SetFillColor(0);
	    legend->SetLineColor(0); 
	    legend->SetShadowColor(0); 
	    
	    prelim = new TLatex( 0.20, 0.9, "#scale[0.8]{CMS preliminary 2011}" );
	    prelim->SetTextSize(0.035);
	    prelim->SetNDC();
	    std::stringstream ssl; ssl << "#scale[0.8]{#int L dt = " << lumi << " pb^{-1}, #sqrt{s} = 7 TeV}";
	    lumitxt = new TLatex( 0.6, 0.9, ssl.str().c_str() );
	    lumitxt->SetTextSize(0.035);
	    lumitxt->SetNDC();
	    
	    mg = new TMultiGraph();
	  
	  } // plots

	  std::stringstream ss_axis;
	  if ( choice == PLOT_NUMERATOR ) { 
	    ss_axis << "N(#alpha_{T}>" << at[iat]/1000. << ")"; 
	  } else if ( choice == PLOT_DENOMINATOR ) { 
	    if ( efficiency ) { ss_axis << "Total"; }
	    else { ss_axis << "N(#alpha_{T}<" << at[iat]/1000. << ")"; }
	  } else if ( choice == PLOT_ESTIMATE ) { 
	    ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")"
		    << " #upoint"
		    << " N(#alpha_{T}<" << at[iat]/1000. << ")"; 
	  } else if ( choice == PLOT_ANCHORED ) { 
	    ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")";
	  } else if ( choice == PLOT_RATIO ) { 
	    if ( !efficiency ) { ss_axis << "R_{#alpha_{T}}(H_{T})"; }
	    else { ss_axis << "#varepsilon(#alpha_{T}=" << at[iat]/1000. << ")"; }
	  } 
	  else { ss_axis << "a.u."; }
	  
 	  std::stringstream ss_flat;
 	  std::stringstream ss_expo;
	  
 	  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	  
	    std::stringstream ss_histo;
	    ss_histo << name << "_" << type[ifile] << "_" << ss_canvas.str();

	    gStyle->SetOptFit(0);
	    TGraphAsymmErrors* gr = new TGraphAsymmErrors(nht,
							  valx[ifile][imulti][iat],
							  valy[ifile][imulti][iat],
							  errxh[ifile][imulti][iat],
							  errxl[ifile][imulti][iat],
							  erryl[ifile][imulti][iat],
							  erryh[ifile][imulti][iat]);
	    
	    if (true) {
	      TGraphAsymmErrors* tmp_gr = new TGraphAsymmErrors(*gr);
	      tmp_gr->Fit("pol0","Q0","",valx[ifile][imulti][iat][0]-1.e-6,valx[ifile][imulti][iat][last_bin]+1.e-6);
	      TF1* fit_c = (TF1*)tmp_gr->FindObject("pol0");
	      if ( fit_c ) {
		if ( ifile == 0 ) { ss_flat << "Constant:" << std::endl; }
		ss_flat << "\"" << type[ifile] << "\" "
			<< fit_c->GetChisquare() << "/"
			<< fit_c->GetNDF() << " ("
			<< fit_c->GetProb() << ") "
		  //<< fit_c->GetParameter(0) << " +/- " << fit_c->GetParError(0)
			<< std::endl;
		if ( ifile == data_file ) { fits.push_back( fit_c->GetProb() ); }
		//rat.push_back( fit_c->GetParameter(0) );
	      } else {
		std::cout << " NULL PTR! " << std::endl;
	      }
	      if (tmp_gr) delete tmp_gr;
	    }

	    for ( uint ii = 0; ii < nht; ++ii ) {
	      double x = 0.;
	      double y = 0.;
	      gr->GetPoint(ii,x,y);
	      //if ( y == 0. ) { gr->SetPointEYhigh(ii,0.); gr->SetPointEYlow(ii,0.); }
	      if (false) {
		std::cout << " sample:\"" << type[ifile] << "\""
			  << " multi: " << multi[imulti]
			  << " aT:" << at[iat]
			  << " pT:" << pt[ii]
			  << " HT:" << ht[ii]
			  << " ARRAY x: " << valx[ifile][imulti][iat][ii]
			  << " y: " << valy[ifile][imulti][iat][ii]
			  << " + " << erryh[ifile][imulti][iat][ii]
			  << " - " << erryl[ifile][imulti][iat][ii]
			  << " HISTO x: " << x
			  << " y: " << y
			  << " + " << gr->GetErrorYhigh(ii)
			  << " - " << gr->GetErrorYlow(ii)
			  << std::endl;
	      }
		
	    }
	    
	    if ( nfile - ifile == 1 ) {
	      std::cout << ss_flat.str() << std::endl;
	      //std::cout << ss_expo.str() << std::endl;
	    }

	    if (plots) {
	      mg->Add(gr,"p");

	      std::stringstream ss_legend;
	      ss_legend << type[ifile];
 	      legend->AddEntry( gr, TString(ss_legend.str()), "p" );

	      gr->SetTitle(TString(ss_legend.str()));
	      gr->SetMarkerStyle(style[ifile]);
	      gr->SetMarkerSize(size[ifile]);
	      gr->SetMarkerColor(col[ifile]);
	      gr->SetLineColor(col[ifile]);

	    } // plots
 
	  } // ifile
	  
	  if (plots) {
	    mg->Draw("a");
	    mg->GetXaxis()->SetTitle("H_{T} (GeV)");
	    mg->GetYaxis()->SetTitle(TString(ss_axis.str()));
	    mg->GetYaxis()->SetTitleOffset(1.3);
	    mg->GetXaxis()->SetRangeUser(ht_min+offset,ht_max+offset);
	    mg->GetYaxis()->SetRangeUser(min[imulti][iat]/10.,max[imulti][iat]*100.);
	    //if (ewk) mg->GetYaxis()->SetRangeUser(1.e-7,1.e-2);
	    //else mg->GetYaxis()->SetRangeUser(0.,0.12e-3);
	    //mg->GetYaxis()->SetNoExponent(true);
	    
	    //mg->GetXaxis()->SetRangeUser(250.,450.);
	    //mg->GetYaxis()->SetRangeUser(5e5,5e7);
	    //mg->GetYaxis()->SetRangeUser(0.,0.05e-3);
	    mg->GetYaxis()->SetRangeUser(0.,0.12e-3);
	    
	    if (choice==1) mg->GetYaxis()->SetRangeUser(0.,400.);
	    
	    legend->Draw("same");
	    prelim->Draw("same");
	    lumitxt->Draw("same");
	    canvas->Update();
	
	    std::stringstream ss_text;
	    ss_text << "#alpha_{T} = " << at[iat]/1000.;
	    
	    TLatex* text = new TLatex(0.5,0.92,TString(ss_text.str()));
	    text->SetNDC(kTRUE);
	    text->SetTextSize(0.04);
	    //text->Draw();
	    
	    canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".C")); 
	    //canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".png")); 
	    canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".pdf")); 
	  
	  } // plots

	} // iat
      } // imulti
      
      int index = 0;
      std::vector<float> cuts;
      std::vector<float>::const_iterator ifit = fits.begin();
      std::vector<float>::const_iterator jfit = fits.end();
      for ( ; ifit != jfit; ++ifit ) { cuts.push_back(float(at[index])/1000.); index++; }
      //if ( !fits.empty() ) qcd(cuts,fits);
      
      // Draw RaT 
      if ( !rat.empty() ) {
	bool plot_ratio = true;
	setTDRStyle();
	gStyle->SetOptStat("emr");
	TCanvas* c2 = new TCanvas("RaTvsEwkComposition","RaTvsEwkComposition");
	c2->SetFillColor(0);
	c2->SetLineColor(0); 
	TH1D* diff = 0;
	if ( !plot_ratio ) { 
	  diff = new TH1D("RaTvsEwkComposition","",200,0.,2.e-5); 
	  for ( uint ifile = 0; ifile < nfile; ++ifile ) { 
	    std::cout << "sample: " << type[ifile] << " fit: " << rat[ifile] << std::endl;
	    diff->Fill( rat[ifile], 1. ); 
	  }
	} else {
	  diff = new TH1D("RaTvsEwkComposition","",200,0.5,1.5); 
	  for ( uint ifile = 1; ifile < nfile; ++ifile ) { 
	    std::cout << "sample: " << type[ifile] << " nominal: " << rat[0] << " ratio: " << rat[ifile]/rat[0] << std::endl;
	    diff->Fill( rat[ifile]/rat[0], 1. ); 
	  }
	}
	c2->cd();
	c2->SetRightMargin(0.12);
	diff->Draw("h");
	if (!plot_ratio) diff->GetXaxis()->SetTitle("Best fit value for constant");
	else diff->GetXaxis()->SetTitle("Best fit value relative to nominal");
	diff->GetYaxis()->SetTitle("Number of tests");
	if (!plot_ratio) c2->SaveAs("RaTvsEwkComposition.pdf"); 
	else c2->SaveAs("RaTvsEwkComposition_ratio.pdf"); 
      }
      
    } // npt == nht
    
  } // plots = true?
  
  return 0;

}
