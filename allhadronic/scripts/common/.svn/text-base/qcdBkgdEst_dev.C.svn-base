#include "common/utilities_dev.C"
//#include "common/style.C"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>

// -----------------------------------------------------------------------------
//  
int qcdBkgdEst_dev() {

  bool use_sumw2 = true;

  std::string label = "";

  int last_bin = 7;

  setTDRStyle();

  // Misc
  bool efficiency = false;

  enum choices { PLOT_NUMERATOR=1, PLOT_DENOMINATOR=2, PLOT_ESTIMATE=3, PLOT_ANCHORED=4, PLOT_RATIO=5 };
  int choice = 5;
  bool plots = true;
  bool syst_plot = false;
  bool syst_ratio = true;
  bool killer = false;
  bool min_max_with_errors = true;

  //bool use_meff = true;
  
  double axis_offset1 = 2.;
  double axis_offset2 = 0.;
  
  int bin = 0;
  uint ht_bin = 2;
  bool anchor = false; 

  bool simulation = false; 
  
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
  double ht_default = 375. + offset;
  //if ( use_meff ) { ht_default *= 1.4; }
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
  //   at.push_back(540);
  at.push_back(550);
  //   at.push_back(560);
  //   at.push_back(570);
  //   at.push_back(580);
  //   at.push_back(590);
  //   at.push_back(600);
  //   at.push_back(650);
  //   at.push_back(700);
  //   at.push_back(510);
  //   at.push_back(520);
  //   for ( int iii = 0; iii < 60; ++iii ) { at.push_back(530+iii); }
  //   at.push_back(590);
  //   at.push_back(600);
  const uint nat = at.size();
  
  std::vector<int> multi;
  //multi.push_back(-2);
  //multi.push_back(2);
  multi.push_back(-2);
  const uint nmulti = multi.size();
  
  int nht = -1;
  std::vector<double> ht;
  std::vector<double> ht_step;
  
//   for ( uint iht = uint(ht_min); iht <= uint(ht_max); iht += uint(ht_step) ) { ht.push_back(iht); }
//   const uint nht = ht.size();
   
  //   if (true) {
  //     if (use_meff) {
  //       if (false) {
  // 	ht.push_back(275.*1.4);
  // 	ht_step.push_back(50.*1.4);
  // 	ht.push_back(325.*1.4);
  // 	ht_step.push_back(50.*1.4);
  // 	for ( uint iht = 0; iht < 7; ++iht ) { ht.push_back((375+iht*100.)*1.4); ht_step.push_back(100.*1.4); }
  //       } else { 
  // 	ht.push_back(400.);
  // 	ht_step.push_back(50.);
  // 	ht.push_back(450.);
  // 	ht_step.push_back(50.);
  // 	for ( uint iht = 0; iht < 7; ++iht ) { ht.push_back(500+iht*100.); ht_step.push_back(100.); }
  //       }
  //     } else {
        ht.push_back(275.);
        ht_step.push_back(50.);
        ht.push_back(325.);
        ht_step.push_back(50.);
        for ( uint iht = 0; iht < 7; ++iht ) { ht.push_back(375+iht*100.); ht_step.push_back(100.); }
  //     }
  //   } else {
  //     for ( uint iht = 0; iht < 11; ++iht ) { ht.push_back(250.+iht*20.); ht_step.push_back(20.); }
  //   }
  //   nht = ht.size() - 1;
  
//   for ( uint iht = 0; iht <= 8; ++iht ) { ht.push_back(475.+iht*100.); ht_step.push_back(100.); }

	nht = ht.size() - 1;

  StringVV files;
  
  bool test = false;
  if ( test ) {
    std::string trunk = dir + "v40/Ratio__";
    StringV q; q.push_back(trunk+"qcdpy.root"); 
    //StringV w(q); w.push_back(trunk+"wjets.root");
    //StringV z(q); z.push_back(trunk+"zinv.root");
    StringV tt(q); tt.push_back(trunk+"ttbar.root");
    files.push_back(tt);
    //std::string dir1 = "/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/";
    //files.push_back(StringV(1,dir1+"Ratio_Data.root"));
    //files.push_back(StringV(1,dir+"v90/Ratio__data.root"));
    //files.push_back(StringV(1,dir+"v100/Ratio__data.root"));
    //files.push_back(StringV(1,dir+"v09/Ratio__data.root"));
    //files.push_back(StringV(1,dir+"v60/Ratio__data.root"));
    //files.push_back(StringV(1,dir+"v70/Ratio__data.root"));
    //files.push_back(dir+"v42/Ratio__data.root"));
    //files.push_back(dir+"v25/parts/Ratio_HT_Run2011A.root"));
    //files.push_back(dir+"v24/Ratio_sm_pythia_with.root"));
    //files.push_back(dir+"v27/parts/Ratio_HT_Run2011A_L1OffSet.root"));
    //files.push_back("/vols/cms02/bainbrid/qcd/trigger/SUSY2/allhadronic/python/Ratio_Data.root"));
    //files.push_back(dir+"v12/Ratio_data.root"));
    //files.push_back(dir+"Ratio_data.root"));
    //files.push_back(dir+"Ratio_data_no_muon_veto.root"));
  }
  
  bool lykken = false;
  if ( lykken ) {
    StringV fixed; 
    fixed.push_back(dir+"v51/Ratio__wjets.root");
    fixed.push_back(dir+"v51/Ratio__zinv.root");
    fixed.push_back(dir+"v51/Ratio__ttbar.root");
    fixed.push_back(dir+"v51/Ratio__top.root");
    fixed.push_back(dir+"v51/Ratio__qcd_pythia.root");
    StringV scaled_low; 
    scaled_low.push_back(dir+"v50/Ratio__wjets.root");
    scaled_low.push_back(dir+"v50/Ratio__zinv.root");
    scaled_low.push_back(dir+"v50/Ratio__ttbar.root");
    scaled_low.push_back(dir+"v50/Ratio__top.root");
    scaled_low.push_back(dir+"v50/Ratio__qcd_pythia.root");
    StringV scaled_all; 
    scaled_all.push_back(dir+"v52/Ratio__wjets.root");
    scaled_all.push_back(dir+"v52/Ratio__zinv.root");
    scaled_all.push_back(dir+"v52/Ratio__ttbar.root");
    scaled_all.push_back(dir+"v52/Ratio__top.root");
    scaled_all.push_back(dir+"v52/Ratio__qcd_pythia.root");
    files.push_back(fixed);
    files.push_back(scaled_low);
    //files.push_back(scaled_all);
  }

  bool no_qcd_present = false;
  if ( no_qcd_present ) {
    // v2 = fixed, v3 = scaled
    files.push_back(StringV(1,dir+"v7/Ratio_sm_pythia.root"));
    files.push_back(StringV(1,dir+"v7/Ratio_sm_madgraph.root"));
  }

  bool ewk = false;
  bool sm_closure = false;
  if ( sm_closure ) {
    std::string version = "v13";
    std::string generator = "pythia";
    files.push_back(StringV(1,dir+""+version+"/Ratio_sm_"+generator+".root"));
    if (ewk){
      files.push_back(StringV(1,dir+""+version+"/Ratio_wjets_"+generator+".root"));
      files.push_back(StringV(1,dir+""+version+"/Ratio_zinv_"+generator+".root"));
      files.push_back(StringV(1,dir+""+version+"/Ratio_ttbar_"+generator+".root"));
      files.push_back(StringV(1,dir+""+version+"/Ratio_top_"+generator+".root"));
    }
  }
  
  bool lmx = false;
  if ( lmx ) {
    files.push_back(StringV(1,dir+"v08/Ratio_lm1.root"));
    files.push_back(StringV(1,dir+"v08/Ratio_lm6.root"));
    //files.push_back(StringV(1,dir+"v9/Ratio_sm_pythia.root"));
  }
  
  bool madgraph = false;
  if ( madgraph ) {
    StringV p; 
    p.push_back(dir+"v103/Ratio__wjets.root");
    p.push_back(dir+"v103/Ratio__zinv.root");
    p.push_back(dir+"v103/Ratio__ttbar.root");
    p.push_back(dir+"v103/Ratio__top.root");
    p.push_back(dir+"v103/Ratio__qcd_pythia.root");
    files.push_back(p);
    StringV m; 
    m.push_back(dir+"v103/Ratio__wjets.root");
    m.push_back(dir+"v103/Ratio__zinv.root");
    m.push_back(dir+"v103/Ratio__ttbar.root");
    m.push_back(dir+"v103/Ratio__top.root");
    m.push_back(dir+"v103/Ratio__qcd_madgraph.root");
    files.push_back(m);
    files.push_back(StringV(1,dir+"v103/Ratio__data.root"));
  }
 
  bool results = true;
  if ( results ) {

    std::string trunk = dir + "v37/Ratio__";
    StringV q; q.push_back(trunk+"qcdpy.root"); 
    StringV sm(q); 
    sm.push_back(trunk+"wjets.root");
    sm.push_back(trunk+"zinv.root");
    sm.push_back(trunk+"ttbar.root");
    //sm.push_back(trunk+"top.root");

    //StringV lm6(sm); lm6.push_back(trunk+"lm6.root"); 
    StringV w(q); w.push_back(trunk+"wjets.root");
    StringV z(q); z.push_back(trunk+"zinv.root");
    StringV tt(q); tt.push_back(trunk+"ttbar.root");
    //StringV t(q); t.push_back(trunk+"top.root");
    
    //files.push_back(lm6);
    files.push_back(sm);
    files.push_back(w);
    files.push_back(z);
    files.push_back(tt);
    //files.push_back(t);

    //files.push_back(StringV(1,dir+"v14/Ratio__data.root"));

//     std::string trunk = dir + "v36/Ratio__";
//     StringV sm1; 
//     sm1.push_back(trunk+"qcdpy.root");
//     //sm1.push_back(trunk+"wjets.root");
//     sm1.push_back(trunk+"zinv.root");
//     sm1.push_back(trunk+"ttbar.root");
//     sm1.push_back(trunk+"top.root");
//     trunk = dir + "v37/Ratio__";
//     StringV sm2; 
//     sm2.push_back(trunk+"qcdpy.root");
//     sm2.push_back(trunk+"wjets.root");
//     sm2.push_back(trunk+"zinv.root");
//     sm2.push_back(trunk+"ttbar.root");
//     trunk = dir + "v40/Ratio__";
//     StringV sm3; 
//     sm3.push_back(trunk+"qcdpy.root");
//     sm3.push_back(trunk+"wjets.root");
//     sm3.push_back(trunk+"zinv.root");
//     sm3.push_back(trunk+"ttbar.root");
//     files.push_back(sm1);
//     files.push_back(sm2);
//     files.push_back(sm3);

  }
  
  bool syst = false;
  if ( syst ) {
    simulation = true;
    axis_offset1 = 4;
    std::string trunk = dir + "v90/Ratio__";
    //std::string trunk = dir + "v50/Ratio__";
    if (false) {
      files.push_back(StringV(1,trunk+"sm_pythia.root"));
      files.push_back(StringV(1,trunk+"sm_wjets_115pc.root"));
      files.push_back(StringV(1,trunk+"sm_wjets_85pc.root"));
      files.push_back(StringV(1,trunk+"sm_zinv_115pc.root"));
      files.push_back(StringV(1,trunk+"sm_zinv_85pc.root"));
      files.push_back(StringV(1,trunk+"sm_ttbar_115pc.root"));
      files.push_back(StringV(1,trunk+"sm_ttbar_85pc.root"));
      files.push_back(StringV(1,trunk+"sm_top_115pc.root"));
      files.push_back(StringV(1,trunk+"sm_top_85pc.root"));
    } else if (true) {
      StringV base; 
      base.push_back(trunk+"wjets.root");
      base.push_back(trunk+"zinv.root");
      base.push_back(trunk+"ttbar.root");
      base.push_back(trunk+"top.root");
      base.push_back(trunk+"qcd_pythia.root");
      StringV tmp0(base); files.push_back(tmp0);
      StringV tmp2(base); tmp2[0] = trunk+"wjets_115pc.root"; files.push_back(tmp2);
      StringV tmp1(base); tmp1[0] = trunk+"wjets_85pc.root"; files.push_back(tmp1);
      StringV tmp4(base); tmp4[1] = trunk+"zinv_115pc.root"; files.push_back(tmp4);
      StringV tmp3(base); tmp3[1] = trunk+"zinv_85pc.root"; files.push_back(tmp3);
      StringV tmp6(base); tmp6[2] = trunk+"ttbar_115pc.root"; files.push_back(tmp6);
      StringV tmp5(base); tmp5[2] = trunk+"ttbar_85pc.root"; files.push_back(tmp5);
      StringV tmp8(base); tmp8[3] = trunk+"top_115pc.root"; files.push_back(tmp8);
      StringV tmp7(base); tmp7[3] = trunk+"top_85pc.root"; files.push_back(tmp7);
    } else {
      StringV base; 
      base.push_back(trunk+"ttbar.root");
      base.push_back(trunk+"qcd_pythia.root");
      StringV tmp0(base); files.push_back(tmp0);
      StringV tmp6(base); tmp6[0] = trunk+"ttbar_115pc.root"; files.push_back(tmp6);
      StringV tmp5(base); tmp5[0] = trunk+"ttbar_85pc.root"; files.push_back(tmp5);
    }
  }
  
  bool vetoes = false;
  if ( vetoes ) {
    files.push_back(StringV(1,dir+"v80/Ratio__data.root"));
    files.push_back(StringV(1,dir+"v81/Ratio__data.root"));
    files.push_back(StringV(1,dir+"v82/Ratio__data.root"));
    files.push_back(StringV(1,dir+"v83/Ratio__data.root"));
//     files.push_back(StringV(1,dir+"v16/Ratio_HT_Run2011_promptReco_DCS-all-vetoes.root"));
//     files.push_back(StringV(1,dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-muon-vetoes.root"));
//     files.push_back(StringV(1,dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-electron-vetoes.root"));
//     files.push_back(StringV(1,dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-photon-vetoes.root"));
//     files.push_back(StringV(1,dir+"v16/Ratio_HT_Run2011_promptReco_DCS-no-egamma-vetoes.root"));
  }

  bool odd_muons = false;
  if ( odd_muons ) {
    axis_offset1 = 5;
    files.push_back(StringV(1,dir+"v90/Ratio__data.root"));
    files.push_back(StringV(1,dir+"v91/Ratio__data.root"));
    StringV sm90; 
    sm90.push_back(dir+"v90/Ratio__wjets.root");
    sm90.push_back(dir+"v90/Ratio__zinv.root");
    sm90.push_back(dir+"v90/Ratio__ttbar.root");
    sm90.push_back(dir+"v90/Ratio__top.root");
    sm90.push_back(dir+"v90/Ratio__qcd_pythia.root");
    StringV sm91; 
    sm91.push_back(dir+"v91/Ratio__wjets.root");
    sm91.push_back(dir+"v91/Ratio__zinv.root");
    sm91.push_back(dir+"v91/Ratio__ttbar.root");
    sm91.push_back(dir+"v91/Ratio__top.root");
    sm91.push_back(dir+"v91/Ratio__qcd_pythia.root");
    files.push_back(sm90);
    files.push_back(sm91);
  }

  bool no_vetoes = false;
  int veto_index = 1;
  if ( no_vetoes ) {
    axis_offset1 = 5;
    StringV sm90; 
    sm90.push_back(dir+"v90/Ratio__wjets.root");
    sm90.push_back(dir+"v90/Ratio__zinv.root");
    sm90.push_back(dir+"v90/Ratio__ttbar.root");
    sm90.push_back(dir+"v90/Ratio__top.root");
    sm90.push_back(dir+"v90/Ratio__qcd_pythia.root");
    StringV sm92; 
    sm92.push_back(dir+"v92/Ratio__wjets.root");
    sm92.push_back(dir+"v92/Ratio__zinv.root");
    sm92.push_back(dir+"v92/Ratio__ttbar.root");
    sm92.push_back(dir+"v92/Ratio__top.root");
    sm92.push_back(dir+"v92/Ratio__qcd_pythia.root");
    StringV sm91; 
    sm91.push_back(dir+"v91/Ratio__wjets.root");
    sm91.push_back(dir+"v91/Ratio__zinv.root");
    sm91.push_back(dir+"v91/Ratio__ttbar.root");
    sm91.push_back(dir+"v91/Ratio__top.root");
    sm91.push_back(dir+"v91/Ratio__qcd_pythia.root");
    StringV sm93; 
    sm93.push_back(dir+"v93/Ratio__wjets.root");
    sm93.push_back(dir+"v93/Ratio__zinv.root");
    sm93.push_back(dir+"v93/Ratio__ttbar.root");
    sm93.push_back(dir+"v93/Ratio__top.root");
    sm93.push_back(dir+"v93/Ratio__qcd_pythia.root");
    StringV sm94; 
    sm94.push_back(dir+"v94/Ratio__wjets.root");
    sm94.push_back(dir+"v94/Ratio__zinv.root");
    sm94.push_back(dir+"v94/Ratio__ttbar.root");
    sm94.push_back(dir+"v94/Ratio__top.root");
    sm94.push_back(dir+"v94/Ratio__qcd_pythia.root");

    files.push_back(StringV(1,dir+"v90/Ratio__data.root"));
    if (veto_index==1) files.push_back(StringV(1,dir+"v92/Ratio__data.root"));
    if (veto_index==2) files.push_back(StringV(1,dir+"v91/Ratio__data.root"));
    if (veto_index==3) files.push_back(StringV(1,dir+"v93/Ratio__data.root"));
    if (veto_index==4) files.push_back(StringV(1,dir+"v94/Ratio__data.root"));

    files.push_back(sm90);
    if (veto_index==1) files.push_back(sm92);
    if (veto_index==2) files.push_back(sm91);
    if (veto_index==3) files.push_back(sm93);
    if (veto_index==4) files.push_back(sm94);

  }
  
  //files.push_back(StringV(1,dir+"v3/Ratio_data.root"));
  //files.push_back(StringV(1,dir+"v4/Ratio_sm_pythia_with.root"));
  //files.push_back(StringV(1,dir+"v5/Ratio_sm_pythia+lm1.root"));
  //files.push_back(StringV(1,dir+"v4/Ratio_qcd_pythia_with.root"));
  
  const uint nfile = files.size();
  
  std::vector<std::string> his;
  //if ( his.size() < nfile ) { his.resize(nfile,"HtAfterAlphaT"); }
  if ( his.size() < nfile ) { his.resize(nfile,"HtAfterRecHit"); }
  
  std::vector<std::string> type;

  if ( test ) { 
    type.push_back("nominal");
  }

  if ( lykken ) { 
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

  if ( madgraph ) {
    type.push_back("SM (QCD Pythia)  ");
    type.push_back("SM (QCD Madgraph)");
    type.push_back("Data       ");
  }

  if ( results ) {
    //type.push_back("SM + LM6 (Spring11)");
    //type.push_back("Spring11");
    //type.push_back("Summer11(Wincl)");
    //type.push_back("Summer11(W300)");
    type.push_back("SM          ");
    type.push_back("Wjets       ");
    type.push_back("Zinv        ");
    type.push_back("TTbar       ");
    type.push_back("Single top  ");
    type.push_back("Data, 2.7/fb");
  }

  if ( syst ) {
    type.push_back("SM (nominal)             ");
    type.push_back("W (+15%)                 ");
    type.push_back("W (-15%)                 ");
    type.push_back("Z#rightarrow#nu#nu (+15%)");
    type.push_back("Z#rightarrow#nu#nu (-15%)");
    type.push_back("t#bar{t} (+15%)          ");
    type.push_back("t#bar{t} (-15%)          ");
    type.push_back("t (+15%)                 ");
    type.push_back("t (-15%)                 ");
  }

  if ( vetoes ) {
    type.push_back("Nominal");
    type.push_back("No muon veto");
    type.push_back("No e/gamma vetoes");
    type.push_back("With odd muons");
//     type.push_back("All vetoes"); 
//     type.push_back("No muon");
//     type.push_back("No electron");
//     type.push_back("No photon");
//     type.push_back("No e/gamma");
  }

  if ( odd_muons ) { 
    type.push_back("Data, with odd muon veto");
    type.push_back("Data, no odd muon veto");
    type.push_back("SM (379/pb), with odd muon veto");
    type.push_back("SM (379/pb), no odd muon veto");
  }

  if ( no_vetoes ) { 
    type.push_back("Data, with all vetoes   ");
    if (veto_index==1) type.push_back("Data, all vetoes removed");
    if (veto_index==2) type.push_back("Data, no odd muon veto  ");
    if (veto_index==3) type.push_back("Data, no muon veto      ");
    if (veto_index==4) type.push_back("Data, no e/gamma veto   ");
    type.push_back("SM (379/pb), with all vetoes   ");
    if (veto_index==1) type.push_back("SM (379/pb), all vetoes removed");
    if (veto_index==2) type.push_back("SM (379/pb), no odd muon veto  ");
    if (veto_index==3) type.push_back("SM (379/pb), no muon veto      ");
    if (veto_index==4) type.push_back("SM (379/pb), no e/gamma veto   ");
  }
  
  if ( type.size() < nfile ) { type.resize(nfile,"unknown"); }
  
  double lumi = 30000.;
  std::vector<double> lumis;

  if ( test ) {
    //lumis.push_back(100.);
    lumis.push_back(30000.);
  }

  if ( lykken ) { 
    lumi = 379.;
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

  if ( madgraph ) { 
    double tmp = 1077.;
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(100.);
  }

  if ( results ) { 
    double tmp = 100.;
    lumi = tmp;
    //lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(100.);
  }

  if ( syst ) { 
    lumi = 379.;
    //lumi = 1080.;
    //lumi = 7138.;
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumis.push_back(lumi);
    lumi = 400.;
  }

  if ( vetoes ) { 
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(100.);
  }

  if ( odd_muons ) { 
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(379.);
    lumis.push_back(379.);
  }

  if ( no_vetoes ) { 
    lumis.push_back(100.);
    lumis.push_back(100.);
    lumis.push_back(379.);
    lumis.push_back(379.);
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
    style.push_back(25);
  }

  if ( lykken ) {
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

  if ( madgraph ) {
    style.push_back(24);
    style.push_back(24);
    style.push_back(20);
  }

  if ( results ) {
    //style.push_back(24);
    style.push_back(24);
    style.push_back(26);
    style.push_back(28);
    style.push_back(30);
    style.push_back(27);
    style.push_back(20);
  }

  if ( syst ) {
    style.push_back(20);
    style.push_back(32);
    style.push_back(26);
    style.push_back(32);
    style.push_back(26);
    style.push_back(32);
    style.push_back(26);
    style.push_back(32);
    style.push_back(26);
  }

  if ( vetoes ) {
    style.push_back(20);
    style.push_back(24);
    style.push_back(25);
    style.push_back(26);
    style.push_back(30);
  }

  if ( odd_muons ) {
    style.push_back(24);
    style.push_back(24);
    style.push_back(25);
    style.push_back(25);
  }

  if ( no_vetoes ) {
    style.push_back(24);
    style.push_back(25);
    style.push_back(24);
    style.push_back(25);
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
    col.push_back(4);
  }

  if ( lykken ) {
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

  if ( madgraph ) {
    col.push_back(4);
    col.push_back(2);
    col.push_back(1);
  }

  if ( results ) {
    //col.push_back(4);
    col.push_back(2);
    col.push_back(1);
    col.push_back(6);
    col.push_back(6);
    col.push_back(6);
    col.push_back(1);
  }

  if ( syst ) {
    col.push_back(1);
    col.push_back(2);
    col.push_back(2);
    col.push_back(6);
    col.push_back(6);
    col.push_back(4);
    col.push_back(4);
    col.push_back(3);
    col.push_back(3);
  }

  if ( vetoes ) {
    col.push_back(1);
    col.push_back(2);
    col.push_back(4);
    col.push_back(3);
    col.push_back(6);
  }

  if ( odd_muons ) {
    col.push_back(1);
    col.push_back(2);
    col.push_back(1);
    col.push_back(2);
  }

  if ( no_vetoes ) {
    col.push_back(1);
    col.push_back(1);
    col.push_back(2);
    col.push_back(2);
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

  DoubleVVVV numer; resize( numer, nfile, nmulti, nat, nht );
  DoubleVVVV numer_errh; resize( numer_errh, nfile, nmulti, nat, nht );
  DoubleVVVV numer_errl; resize( numer_errl, nfile, nmulti, nat, nht );
  DoubleVVVV denom; resize( denom, nfile, nmulti, nat, nht );
  DoubleVVVV denom_errh; resize( denom_errh, nfile, nmulti, nat, nht );
  DoubleVVVV denom_errl; resize( denom_errl, nfile, nmulti, nat, nht );
  DoubleVVVV ratio; resize( ratio, nfile, nmulti, nat, nht );
  DoubleVVVV errh; resize( errh, nfile, nmulti, nat, nht );
  DoubleVVVV errl; resize( errl, nfile, nmulti, nat, nht );
  IntVVV length; resize( length, nfile, nmulti, nat );
  
  // Min/max values for ratios
  DoubleVV min; min.resize( nmulti, DoubleV( nat, 0. ) );
  DoubleVV max; max.resize( nmulti, DoubleV( nat, 0. ) );
  
  std::cout << " nfile: " << nfile
	    << " nmulti: " << nmulti
	    << " nat: " << nat
	    << " nht: " << nht
	    << " total: " << nfile*nmulti*nat*nht
	    << std::endl;
  
  // Init arrays
  for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
    for ( uint iat = 0; iat < nat; ++iat ) {
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	for ( uint iht = 0; iht < nht; ++iht ) {
	  numer[ifile][imulti][iat][iht] = 0.;
	  numer_errh[ifile][imulti][iat][iht] = 0.;
	  numer_errl[ifile][imulti][iat][iht] = 0.;
	  denom[ifile][imulti][iat][iht] = 0.;
	  denom_errh[ifile][imulti][iat][iht] = 0.;
	  denom_errl[ifile][imulti][iat][iht] = 0.;
	  ratio[ifile][imulti][iat][iht] = 0.;
	  errh[ifile][imulti][iat][iht] = 0.;
	  errl[ifile][imulti][iat][iht] = 0.;
	}
	length[ifile][imulti][iat] = 0;
      }
      min[imulti][iat] = 0.;
      max[imulti][iat] = 0.;
    }
  }
  
  // -----------------------------------------------------------------------------
  // 
  std::cout << " CALCULATING RATIOS..." << std::endl;
  calcRatio( nfile, nmulti, nat, nht, 
	     his, files, lumis, weights, multi, at, ht, 
	     ht_min, ht_max, ht_step[nht],
	     numer, numer_errh, numer_errl, 
	     denom, denom_errh, denom_errl, 
	     ratio, errh, errl, length,
	     data_file, lumi, label,
	     efficiency, use_sumw2 );
  
  ht_step.clear();
  for ( uint iht = 0; iht < nht; ++iht ) { ht_step.push_back( ht[iht+1] - ht[iht] ); }

  //eff(denom,"EfficiencyDenom");
  //eff(numer,"EfficiencyNumer");
  
  std::cout << " size " << ht.size()
	    << " nbins " << nht 
	    << " htmin " << ht_min 
	    << " htmax " << ht_max
	    << std::endl;
  for ( uint iht = 0; iht <= nht; ++iht ) {
    std::cout << " ibin " << iht
	      << " ht " << ht[iht]
	      << " htstep " << ht_step[iht]
	      << std::endl;
  }

  // -----------------------------------------------------------------------------
  // R(aT) vs HT for "truth", "MC gen", "MC reco" and "data" with fixed (x1,x2,x3)
  
  // Print numbers
  bool print = true;
  if (print) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht];
	    double neh = numer_errh[ifile][imulti][iat][iht];
	    double nel = numer_errl[ifile][imulti][iat][iht];
	    double d = denom[ifile][imulti][iat][iht];
	    double deh = denom_errh[ifile][imulti][iat][iht];
	    double del = denom_errl[ifile][imulti][iat][iht];
	    double r = ratio[ifile][imulti][iat][iht];
	    double eh = errh[ifile][imulti][iat][iht];
	    double el = errl[ifile][imulti][iat][iht];
	    std::cout
	      //<< " PRINT: "
	      << "" << type[ifile] << ""
	      //<< " njets: " << multi[imulti]
	      //<< " aT: " << at[iat]
	      << std::fixed << std::setprecision(0)
		      << " HT: " << ht[iht]
	      << std::scientific << std::setprecision(2)
 		      << ", pass: " << n
  		      << " + " << neh
  		      << " - " << nel
// 	      << ",pass," << n
// 	      << "," << neh
// 	      << "," << nel
	      //<< " (" << ( n > 0. ? sqrt(n)/n : -1. ) << ")" 
	      << ", fail: " << d
	      << " + " << deh
	      << " - " << del
// 	      << ",fail," << d
// 	      << "," << deh
// 	      << "," << del
	      //<< " (" << ( d > 0. ? sqrt(d)/d : -1. ) << ")" 
	      //<< " R: " << ( d > 0. ? n/d : -1. )
	      //<< " E: " << ( d > 0. ? sqrt(n*(n/(n+d))*(1-(n/(n+d)))) : -1. )
  	      << ", ratio: " << r
  	      << " + " << eh
  	      << " - " << el
// 	      << ", ratio ," << r
// 	      << "," << eh
// 	      << "," << el
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
	  ted << " sample: \"" << type[ifile] << "\""
	      << " Multiplicity: " << multi[imulti]
	      << " AlphaT: " << at[iat] 
	      << std::endl;
	  ted << "\"had\":\t\t" << float(lumi) << ", #lumi" << std::endl;
	  ted << "\"hadBulk\":\t" << float(lumi) << ", #lumi" << std::endl;

	  // Bulk
	  ted << "\"nHadBulk\":\t(";
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double d = denom[ifile][imulti][iat][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << d << ", ";
	  }
	  ted << ")" << std::endl;

	  // Tail
	  ted << "\"nHad\":\t\t(";
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << n << ", ";
	  }
	  ted << ")" << std::endl;

	  // Mean HT
	  ted << "self._htMeans = (";
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht];
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
  double scale_val[nfile][nmulti][nat];
  double scale_errh[nfile][nmulti][nat];
  double scale_errl[nfile][nmulti][nat];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {

	scale_val[ifile][imulti][iat] = 0.;
	scale_errh[ifile][imulti][iat] = 0.;
	scale_errl[ifile][imulti][iat] = 0.;

	// If no data file, use first sample with non-zero ratio in "bin"
	int norm_file = 0;
	if ( data_file == -1 ) {
	  for ( uint iifile = 0; iifile < nfile; ++iifile ) {
	    if ( ratio[iifile][imulti][iat][bin] > 0. ) {
	      norm_file = iifile; 
	      break;
	    }
	  }
	}

	double d_val = ratio[norm_file][imulti][iat][bin];
	double d_errh = errh[norm_file][imulti][iat][bin];
	double d_errl = errl[norm_file][imulti][iat][bin];
	double mc_val = ratio[ifile][imulti][iat][bin];
	double mc_errh = errh[ifile][imulti][iat][bin];
	double mc_errl = errl[ifile][imulti][iat][bin];

	if ( mc_val > 0. ) { scale_val[ifile][imulti][iat] = d_val/mc_val; }

	bool print = false;
	std::stringstream ss;
	calcErr( scale_val[ifile][imulti][iat],
		 scale_errh[ifile][imulti][iat],
		 scale_errl[ifile][imulti][iat],
		 d_val, d_errh, d_errl,
		 mc_val, mc_errh, mc_errl, 
		 print, ss );
	  
	if ( print ) {
	  std::cout << " SCALE:"
		    << " sample:\"" << type[ifile] << "\""
		    << " multi: " << multi[imulti]
		    << " aT:" << at[iat]
		    << ss.str()
		    << std::endl;
	}

      } // iat 
    } // imulti
  } // ifile
  
  // Store scaled MC values using factors above
  std::cout << " STORE SCALED MC VALUES..." << std::endl;
  double anchored_val[nfile][nmulti][nat][nht];
  double anchored_errh[nfile][nmulti][nat][nht];
  double anchored_errl[nfile][nmulti][nat][nht];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	for ( uint iht = 0; iht < nht; ++iht ) {

	  double r_val = ratio[ifile][imulti][iat][iht];
	  double r_errh = errh[ifile][imulti][iat][iht];
	  double r_errl = errl[ifile][imulti][iat][iht];
	  double s_val = scale_val[ifile][imulti][iat];
	  double s_errh = scale_errh[ifile][imulti][iat];
	  double s_errl = scale_errl[ifile][imulti][iat];
	    
	  anchored_val[ifile][imulti][iat][iht] = r_val * s_val;
	  anchored_errh[ifile][imulti][iat][iht] = 0.;
	  anchored_errl[ifile][imulti][iat][iht] = 0.;

	  bool print = false;
	  std::stringstream ss;
	  calcErr( anchored_val[ifile][imulti][iat][iht],
		   anchored_errh[ifile][imulti][iat][iht],
		   anchored_errl[ifile][imulti][iat][iht],
		   r_val, r_errh, r_errl,
		   s_val, s_errh, s_errl,
		   print, ss );

	  if ( print ) {
	    std::cout << " SCALED:"
		      << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << " HT:" << ht[iht]
		      << ss.str()
		      << std::endl;
	  }

	} // iht
      } // iat 
    } // imulti
  } // ifile

  // Scale MC to data using factors above
  std::cout << " ANCHORING MC TO DATA..." << std::endl;
  if ( anchor ) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    ratio[ifile][imulti][iat][iht] = anchored_val[ifile][imulti][iat][iht];
	    errh[ifile][imulti][iat][iht] = anchored_errh[ifile][imulti][iat][iht];
	    errl[ifile][imulti][iat][iht] = anchored_errl[ifile][imulti][iat][iht];
	    numer[ifile][imulti][iat][iht] *= scale_val[ifile][imulti][iat];
	  } // iht
	} // iat 
      } // imulti
    } // ifile
  } // anchor?

  // Calculate estimation
  std::cout << " CALCULATING ESTIMATE..." << std::endl;
  uint loop = 0;
  uint nloop = nfile * nmulti * nat * nht;
  
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
  
  double estimate_val[nfile][nmulti][nat][nht];
  double estimate_errh[nfile][nmulti][nat][nht];
  double estimate_errl[nfile][nmulti][nat][nht];
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	std::cout << " Finished " << int(100*loop/nloop) << "%..." << std::endl;
	for ( uint iht = 0; iht < nht; ++iht ) {
	  loop++;
	    
	  // Only suitable for "flat" assumption
	  double r_val = ratio[ifile][imulti][iat][bin];
	  double r_errh = errh[ifile][imulti][iat][bin];
	  double r_errl = errl[ifile][imulti][iat][bin];

	  // Events observed
	  double d_val = denom[ifile][imulti][iat][iht];
	  double d_errh = denom_errh[ifile][imulti][iat][iht];
	  double d_errl = denom_errl[ifile][imulti][iat][iht];
	    
	  estimate_val[ifile][imulti][iat][iht] = r_val * d_val;
	  estimate_errh[ifile][imulti][iat][iht] = 0.;
	  estimate_errl[ifile][imulti][iat][iht] = 0.;
	    
	  bool print = false;
	  std::stringstream ss;
	  calcErr( estimate_val[ifile][imulti][iat][iht],
		   estimate_errh[ifile][imulti][iat][iht],
		   estimate_errl[ifile][imulti][iat][iht],
		   r_val, r_errh, r_errl,
		   d_val, d_errh, d_errl, 
		   print, ss );
	  
	  if ( print ) {
	    std::cout << " ESTIMATE:"
		      << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << " HT:" << ht[iht]
		      << ss.str()
		      << std::endl;
	  }
	    
	  if ( two_measurements ) {
	    if ( iht == 2 ) {
		
	      // Measurements from bins HT=250 and HT=300
	      double b0_val = ratio[ifile][imulti][iat][bin];
	      double b0_errh = errh[ifile][imulti][iat][bin];
	      double b0_errl = errl[ifile][imulti][iat][bin];
	      double b1_val = ratio[ifile][imulti][iat][1];
	      double b1_errh = errh[ifile][imulti][iat][1];
	      double b1_errl = errl[ifile][imulti][iat][1];

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
			  << " HT:" << ht[iht]
			  << ss1.str()
			  << std::endl;
	      }

	    } // iht == 2
	  } // two_measurements

	  if ( mc_measurement ) {
	    if ( iht == 2 ) {
		
	      // Measurements from bins HT=250 and HT=350
	      double b0_val = ratio[ifile][imulti][iat][bin];
	      double b0_errh = errh[ifile][imulti][iat][bin];
	      double b0_errl = errl[ifile][imulti][iat][bin];
	      double b2_val = ratio[ifile][imulti][iat][2];
	      double b2_errh = errh[ifile][imulti][iat][2];
	      double b2_errl = errl[ifile][imulti][iat][2];

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
			  << " HT:" << ht[iht] 
			  << ss2.str()
			  << std::endl;
	      }
		
		
	    } // iht == 2
	  } // mc_measurement
	    
	} // iht
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
	  double b1_val = ratio[ifile][imulti][iat][1];
	  double b1_errh = errh[ifile][imulti][iat][1];
	  double b1_errl = errl[ifile][imulti][iat][1];
	  
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
	  double d2_val = denom[ifile][imulti][iat][2];
	  double d2_errh = denom_errh[ifile][imulti][iat][2];
	  double d2_errl = denom_errl[ifile][imulti][iat][2];

	  // Calculate estimate in bin HT=350
	  estimate_val[ifile][imulti][iat][2] = d2_val * r2_val;
	  estimate_errh[ifile][imulti][iat][2] = 0.;
	  estimate_errl[ifile][imulti][iat][2] = 0.;
	  
	  std::stringstream sss;
	  calcErr( estimate_val[ifile][imulti][iat][2],
		   estimate_errh[ifile][imulti][iat][2],
		   estimate_errl[ifile][imulti][iat][2],
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
	    double d0_val = ratio[data_file][imulti][iat][bin];
	    double d0_errh = errh[data_file][imulti][iat][bin];
	    double d0_errl = errl[data_file][imulti][iat][bin];
	    
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
	    double d2_val = denom[data_file][imulti][iat][2];
	    double d2_errh = denom_errh[data_file][imulti][iat][2];
	    double d2_errl = denom_errl[data_file][imulti][iat][2];
	    
	    estimate_val[ifile][imulti][iat][2] = d2_val * r2_val;
	    estimate_errh[ifile][imulti][iat][2] = 0.;
	    estimate_errl[ifile][imulti][iat][2] = 0.;
	    
	    std::stringstream sss;
	    calcErr( estimate_val[ifile][imulti][iat][2],
		     estimate_errh[ifile][imulti][iat][2],
		     estimate_errl[ifile][imulti][iat][2],
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

	double meff = ht[ht_bin]*( 1. + 1./x3_factor );
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
	     << dr(ht[ht_bin]/x3_default,dec_places) << " & ";
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
	  //std::cout << ifile << " " << imulti << " " << iat << " " << std::endl;
	      
	  double e_val = estimate_val[ifile][imulti][iat][ht_bin];
	  double e_errh = estimate_errh[ifile][imulti][iat][ht_bin];
	  double e_errl = estimate_errl[ifile][imulti][iat][ht_bin];
	  double n_val = numer[ifile][imulti][iat][ht_bin];
	  double n_err = numer_errh[ifile][imulti][iat][ht_bin];
	  //double n_err = numer_errl[ifile][imulti][iat][ht_bin];
	  
	  if ( mc_measurement ) {
	    n_val = numer[data_file][imulti][iat][ht_bin];
	    n_err = numer_errh[data_file][imulti][iat][ht_bin];
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
      //<< anchored_val[0][iat][bin] << " \\pm ^{" 
      //<< anchored_errh[0][iat][bin] << "}_{"
      //<< anchored_errl[0][iat][bin] << "}$"
      //<< " and "
      //<< "$R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ")$"
      //<< "$ = " 
      //<< anchored_val[1][iat][bin] << " \\pm ^{" 
      //<< anchored_errh[1][iat][bin] << "}_{"
      //<< anchored_errl[1][iat][bin] << "}$"
      //ss << ".}" << std::endl;
      // 	ss// << std::setprecision(2)
      // 	  << "  \\caption{QCD estimation for MC and data in different HT bins, based the measurements"
      // 	  << " $R^{mc}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
      // 	  << anchored_val[0][iat][bin] << " \\pm ^{" 
      // 	  << anchored_errh[0][iat][bin] << "}_{"
      // 	  << anchored_errl[0][iat][bin] << "}$"
      // 	  << " and $R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
      // 	  << anchored_val[1][iat][bin] << " \\pm ^{" 
      // 	  << anchored_errh[1][iat][bin] << "}_{"
      // 	  << anchored_errl[1][iat][bin] << "}$"
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
			  numer[ifile][imulti][iat][2],
			  estimate_val[ifile][imulti][iat][2],
			  estimate_errh[ifile][imulti][iat][2],
			  estimate_errl[ifile][imulti][iat][2],
			  numer[ifile][imulti][iat][0],
			  denom[ifile][imulti][iat][0],
			  numer[ifile][imulti][iat][1],
			  denom[ifile][imulti][iat][1],
			  denom[ifile][imulti][iat][2],
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

  //     double pred_val[nfile][nat];
  //     double pred_errh[nfile][nat];
  //     double pred_errl[nfile][nat];
  //     double obs_val[nfile][nat];
  //     double obs_err[nfile][nat];
  //     for ( uint ifile = 0; ifile < nfile; ++ifile ) {
  //       for ( uint iat = 0; iat < nat; ++iat ) {
  // 	  pred_val[ifile][iat] = 0.;
  // 	  pred_errh[ifile][iat] = 0.;
  // 	  pred_errl[ifile][iat] = 0.;
  // 	  obs_val[ifile][iat] = 0.;
  // 	  obs_err[ifile][iat] = 0.;
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
  // 	  //std::cout << ifile << " " << imulti << " " << iat << " " << std::endl;
	      
  // 	  double e_val = estimate_val[ifile][imulti][iat][ht_bin];
  // 	  double e_errh = estimate_errh[ifile][imulti][iat][ht_bin];
  // 	  double e_errl = estimate_errl[ifile][imulti][iat][ht_bin];
  // 	  double n_val = numer[ifile][imulti][iat][ht_bin];
  // 	  double n_err = sqrt(numer[ifile][imulti][iat][ht_bin]);
		
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
  //       //<< anchored_val[0][iat][bin] << " \\pm ^{" 
  //       //<< anchored_errh[0][iat][bin] << "}_{"
  //       //<< anchored_errl[0][iat][bin] << "}$"
  //       //<< " and "
  //       //<< "$R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ")$"
  //       //<< "$ = " 
  //       //<< anchored_val[1][iat][bin] << " \\pm ^{" 
  //       //<< anchored_errh[1][iat][bin] << "}_{"
  //       //<< anchored_errl[1][iat][bin] << "}$"
  //       ss << ".}" << std::endl;
  //       // 	ss// << std::setprecision(2)
  //       // 	  << "  \\caption{QCD estimation for MC and data in different HT bins, based the measurements"
  //       // 	  << " $R^{mc}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
  //       // 	  << anchored_val[0][iat][bin] << " \\pm ^{" 
  //       // 	  << anchored_errh[0][iat][bin] << "}_{"
  //       // 	  << anchored_errl[0][iat][bin] << "}$"
  //       // 	  << " and $R^{data}_{\\alpha_{T}}(" << at[iat]/1000. << ") = " 
  //       // 	  << anchored_val[1][iat][bin] << " \\pm ^{" 
  //       // 	  << anchored_errh[1][iat][bin] << "}_{"
  //       // 	  << anchored_errl[1][iat][bin] << "}$"
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
	      valy[ifile][imulti][iat][iht] = numer[ifile][imulti][iat][iht];
	      erryh[ifile][imulti][iat][iht] = numer_errh[ifile][imulti][iat][iht];
	      erryl[ifile][imulti][iat][iht] = numer_errl[ifile][imulti][iat][iht];
	    } else if ( choice == PLOT_DENOMINATOR ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = denom[ifile][imulti][iat][iht];
	      erryh[ifile][imulti][iat][iht] = denom_errh[ifile][imulti][iat][iht];
	      erryl[ifile][imulti][iat][iht] = denom_errl[ifile][imulti][iat][iht];
	    } else if ( choice == PLOT_ESTIMATE ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = estimate_val[ifile][imulti][iat][iht];
	      erryh[ifile][imulti][iat][iht] = estimate_errh[ifile][imulti][iat][iht];
	      erryl[ifile][imulti][iat][iht] = estimate_errl[ifile][imulti][iat][iht];
	    } else if ( choice == PLOT_ANCHORED ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = anchored_val[ifile][imulti][iat][iht];
	      erryh[ifile][imulti][iat][iht] = anchored_errh[ifile][imulti][iat][iht];
	      erryl[ifile][imulti][iat][iht] = anchored_errl[ifile][imulti][iat][iht];
	    } else if ( choice == PLOT_RATIO ) {
	      //if ( iht < length[ifile][imulti][iat] ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = ratio[ifile][imulti][iat][iht];
	      erryh[ifile][imulti][iat][iht] = errh[ifile][imulti][iat][iht];
	      erryl[ifile][imulti][iat][iht] = errl[ifile][imulti][iat][iht];
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
	    std::cout << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << " min:" << min[imulti][iat]
		      << " max:" << max[imulti][iat]
		      << std::endl;
	  }
	}
      }
    }
    
    if (false) {
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	  for ( uint iat = 0; iat < nat; ++iat ) {
	    std::cout << " PLOTTING:"
		      << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]
		      << " valy: " << valy[ifile][imulti][iat]
		      << " erryh: " << erryh[ifile][imulti][iat]
		      << " erryl: " << erryl[ifile][imulti][iat]
		      << std::endl;
	  }
	}
      }
    }
    
    // Check number of pt and ht bins are the same
    std::cout << " CREATING PLOTS..." << std::endl;

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
	    
	  legend = new TLegend( 0.2, 0.8-(nfile*0.04), 0.4, 0.8, NULL, "brNDC" );
	  legend->SetTextSize(0.035);
	  legend->SetFillColor(0);
	  legend->SetLineColor(0); 
	  legend->SetShadowColor(0); 

	  if (!simulation) {
	    prelim = new TLatex( 0.20, 0.88, "#scale[0.8]{CMS preliminary 2011}" );
	  } else {
	    prelim = new TLatex( 0.20, 0.88, "#scale[0.8]{CMS simulation 2011}" );
	  }
	  prelim->SetTextSize(0.035);
	  prelim->SetNDC();
	  std::stringstream ssl; 
	  ssl << "#scale[0.8]{#int L dt = " << std::setprecision(3) << lumi/1000. << " fb^{-1}, #sqrt{s} = 7 TeV}";
	  lumitxt = new TLatex( 0.68, 0.88, ssl.str().c_str() );
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
	  if ( !efficiency ) { ss_axis << "R_{#alpha_{T}}"; }
	  else { ss_axis << "#varepsilon(#alpha_{T}=" << at[iat]/1000. << ")"; }
	} 
	else { ss_axis << "a.u."; }
	  
	std::stringstream ss_flat;
	std::stringstream ss_flat1;
	std::stringstream ss_expo;
	std::stringstream ss_expo1;
	  
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

	  // Fitting
	  if (true) {
	    TGraphAsymmErrors* tmp_gr = new TGraphAsymmErrors(*gr);

	    tmp_gr->Fit("pol0","Q0","",valx[ifile][imulti][iat][0]-1.e-6,valx[ifile][imulti][iat][last_bin]+1.e-6);
	    TF1* fit_c = (TF1*)tmp_gr->FindObject("pol0");
	    if ( fit_c ) {
	      if ( ifile == 0 ) { ss_flat << "Constant:" << std::endl; }
	      ss_flat << "" << type[ifile] << " "
		      << std::setprecision(3)
		      << fit_c->GetChisquare() << "/"
		      << std::setprecision(0)
		      << fit_c->GetNDF() << " ("
		      << std::setprecision(3)
		      << fit_c->GetProb() << ") "
		      << std::endl;
	      ss_flat1 << "" << type[ifile] << " "
		       << std::scientific << std::setprecision(3)
		       << " A: " << fit_c->GetParameter(0) << " +/- " << fit_c->GetParError(0)
		       << std::endl;
	      if ( ifile == data_file ) { fits.push_back( fit_c->GetProb() ); }
	      //rat.push_back( fit_c->GetParameter(0) );
	    } else {
	      std::cout << " NULL PTR! " << std::endl;
	    }

	    tmp_gr->Fit("expo","Q0","",valx[ifile][imulti][iat][0]-1.e-6,valx[ifile][imulti][iat][last_bin]+1.e-6);
	    TF1* fit_e = (TF1*)tmp_gr->FindObject("expo");
	    if ( fit_e ) {
	      if ( ifile == 0 ) { ss_expo << "Exponential:" << std::endl; }
	      ss_expo << "" << type[ifile] << " "
		      << std::fixed
		      << std::setprecision(3)
		      << fit_e->GetChisquare() << "/"
		      << std::setprecision(0)
		      << fit_e->GetNDF() << " ("
		      << std::setprecision(3)
		      << fit_e->GetProb() << ") "
		      << std::endl;
	      ss_expo1 << "" << type[ifile] << " "
		       << std::scientific << std::setprecision(3)
		       << " A: " << fit_e->GetParameter(0) << " +/- " << fit_e->GetParError(0)
		       << " k: " << fit_e->GetParameter(1) << " +/- " << fit_e->GetParError(1)
		       << std::endl;
	      if ( ifile == data_file ) { fits.push_back( fit_e->GetProb() ); }
	      rat.push_back( fit_e->GetParameter(1) );
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
	    std::cout << ss_flat1.str() << std::endl;
	    std::cout << ss_expo.str() << std::endl;
	    std::cout << ss_expo1.str() << std::endl;
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
	  mg->GetXaxis()->SetTitle(label.c_str());
	  //if (!use_meff) mg->GetXaxis()->SetTitle("H_{T} (GeV)");
	  //else mg->GetXaxis()->SetTitle("M_{eff} (GeV)");
	  mg->GetYaxis()->SetTitle(TString(ss_axis.str()));
	  mg->GetYaxis()->SetTitleOffset(1.3);
	  mg->GetXaxis()->SetRangeUser(ht_min+offset,ht_max+offset);
	  mg->GetYaxis()->SetRangeUser(min[imulti][iat]/2.,max[imulti][iat]*2.);
	  //if (ewk) mg->GetYaxis()->SetRangeUser(1.e-7,1.e-2);
	  //else mg->GetYaxis()->SetRangeUser(0.,0.12e-3);
	  //mg->GetYaxis()->SetNoExponent(true);
	  
	  //mg->GetXaxis()->SetRangeUser(250.,450.);
	  //mg->GetYaxis()->SetRangeUser(0.1,1000.);
	  //mg->GetYaxis()->SetRangeUser(0.,0.05e-3);
	  mg->GetYaxis()->SetRangeUser(0.,0.04e-3);
	  //canvas->SetLogy();
	    
	  if      (choice==1) mg->GetYaxis()->SetRangeUser(0.1,1.e4);
	  else if (choice==2) mg->GetYaxis()->SetRangeUser(0.1,1.e8);
	    
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
    if ( false && !rat.empty() ) {
      bool plot_ratio = false;
      setTDRStyle();
      gStyle->SetOptStat("emr");
      TCanvas* c2 = new TCanvas("RaTvsEwkComposition","RaTvsEwkComposition");
      c2->SetFillColor(0);
      c2->SetLineColor(0); 
      TH1D* diff = 0;
      if ( !plot_ratio ) { 
	diff = new TH1D("RaTvsEwkComposition","",1000,0.,1e-3); 
	//diff = new TH1D("RaTvsEwkComposition","",1000,-20.,0.); 
	for ( uint ifile = 0; ifile < nfile; ++ifile ) { 
	  std::cout << "sample: " << type[ifile] << " fit: " << rat[ifile] << std::endl;
	  diff->Fill( rat[ifile], 1. ); 
	}
      } else {
	diff = new TH1D("RaTvsEwkComposition","",200,0.6,1.4); 
	for ( uint ifile = 1; ifile < nfile; ++ifile ) { 
	  std::cout << "sample: " << type[ifile] << " nominal: " << rat[0] << " ratio: " << rat[ifile]/rat[0] << std::endl;
	  diff->Fill( rat[ifile]/rat[0], 1. ); 
	}
      }
      c2->cd();
      c2->SetRightMargin(0.12);
      c2->SetBottomMargin(0.15);
      diff->Draw("h");
      if (!plot_ratio) diff->GetXaxis()->SetTitle("Best fit value");
      else { 
	//diff->GetXaxis()->SetTitle("Best fit value relative to nominal");
	diff->GetXaxis()->SetTitle("R_{#alpha_{T}}^{(#pm15%)} / R_{#alpha_{T}}^{(nominal)}");
	diff->GetXaxis()->SetTitleOffset(1.1);
      }
      diff->GetYaxis()->SetTitle("Number of tests with #pm15%");
      if (!plot_ratio) c2->SaveAs("RaTvsEwkComposition.pdf"); 
      else c2->SaveAs("RaTvsEwkComposition_ratio.pdf"); 
    }
    
  } // plots = true?
  
  return 0;

}
