#include "utilities.C"
#include "style.C"

// -----------------------------------------------------------------------------
//  
int qcdBkgdEst() {

  setTDRStyle();

  // Misc
  
  enum choices { PLOT_NUMERATOR=1, PLOT_DENOMINATOR=2, PLOT_ESTIMATE=3, PLOT_ANCHORED=4, PLOT_RATIO=5 };
  int choice = 5;
  bool plots = false;
  bool syst = false;
  bool killer = false;
  bool min_max_with_errors = true;

  double axis_offset1 = 1.;
  double axis_offset2 = 0.;
  
  int bin = 0; //@@ used to measure R(aT)
  uint ht_bin = 2;
  bool anchor = false; 
  
  bool two_measurements = true;
  bool mc_measurement = false;
  if ( two_measurements || mc_measurement ) { ht_bin = 2; }
  
  int dec_places = 1;
  int sig_figs = 2;
  bool pt_thresholds = false;
  bool print_ratio = false;
  
  // Some analysis defaults
  double pt1_default = 100.;
  double pt2_default = 100.;
  double pt3_default = 50.;
  double ht_default = 350.;
  double meff_default = ht_default + pt3_default;
  double x1_default = pt1_default / meff_default;
  double x2_default = pt2_default / meff_default;
  double x3_default = pt3_default / meff_default ;
  double x3_factor = ( 1. - x3_default ) / ( x3_default );

  std::stringstream dir1;
  dir1 << "101028b";
  std::stringstream dir2;
  dir2 << pt1_default << "_" << pt2_default << "_" << pt3_default;
  
  std::vector<std::string> files;
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_wjets_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_zinv_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_ttbar_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_wjets_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_zinv_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_ttbar_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_wjets_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_zinv_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_ttbar_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_wjets_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_zinv_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_ttbar_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_wjets_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_zinv_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk_ttbar_x5.root");

//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_wjets_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_zinv_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_ttbar_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_wjets_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_zinv_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_ttbar_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_wjets_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_zinv_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_ttbar_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_wjets_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_zinv_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_ttbar_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_wjets_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_zinv_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm_ttbar_x5.root");

//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_wjets_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_zinv_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_ttbar_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_wjets_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_zinv_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_ttbar_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_wjets_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_zinv_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_ttbar_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_wjets_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_zinv_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_ttbar_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_wjets_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_zinv_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm0_ttbar_x5.root");

//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_wjets_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_zinv_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_ttbar_x0.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_wjets_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_zinv_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_ttbar_x2.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_wjets_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_zinv_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_ttbar_x3.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_wjets_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_zinv_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_ttbar_x4.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_wjets_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_zinv_x5.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm+lm1_ttbar_x5.root");

  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_wjets.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_zinv.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ttbar.root");

  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_qcd.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_ewk.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_lm0.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_lm1.root");
  //files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_data.root");

  const uint nfile = files.size();
 
  std::vector<std::string> his;
//   his.push_back("HtAfterBaby");
//   his.push_back("HtAfterBaby");
//   his.push_back("HtAfterBaby");
//   his.push_back("HtAfterBaby");
  if ( his.size() < nfile ) { his.resize(nfile,"Ht"); }
  
  std::vector<std::string> type;
  type.push_back("wjets");
  type.push_back("zinv");
  type.push_back("ttbar");
  type.push_back("qcd");
  type.push_back("ewk");
  type.push_back("sm");
  type.push_back("lm0");
  type.push_back("lm1");
//    type.push_back("data");
//    type.push_back("pf 11/pb");
//    type.push_back("pf 15/pb");
//    type.push_back("calo 15/pb");
  if ( type.size() < nfile ) { type.resize(nfile,"unknown"); }
  
  double lumi = 100.;
  std::vector<double> lumis;
//     lumis.push_back(4.152e+02); // W NLO
//     lumis.push_back(4.468e+02); // Zinv NLO
//   lumis.push_back(3.205e+02); // W NNLO
//   lumis.push_back(3.518e+02); // Zinv NNLO
//   lumis.push_back(1.350e+04); // ttbar NLO
//   lumis.push_back(3.590e+02); // EWK NNLO
//     lumis.push_back(4.633e+02); // EWK NLO
//   lumis.push_back(4.282); // QCD
  if ( lumis.size() < nfile ) { lumis.resize(nfile,100.); }
  
  // Which file is the data file
  int data_file = -1;
  for ( uint itype = 0; itype < nfile; ++itype ) {
    if ( type[itype] == "data" ) { data_file = itype; }
  }
  if ( data_file == -1 ) { 
    std::cout << "Problem identifying data file!" << std::endl;
  }
  
  std::vector<int> style;
  style.push_back(25);
  style.push_back(25);
  style.push_back(25);
  style.push_back(25);
  style.push_back(25);
  style.push_back(25);
  style.push_back(21);
  if ( style.size() < nfile ) { style.resize(nfile,25); }
  
  std::vector<double> size;
  size.push_back(1.5);
  size.push_back(1.4);
  size.push_back(1.3);
  size.push_back(1.2);
  size.push_back(1.1);
  size.push_back(1.0);
  size.push_back(0.9);
  if ( size.size() < nfile ) { size.resize(nfile,1.); }
  
  std::vector<int> col;
//   col.push_back(7);
//   col.push_back(6);
//   col.push_back(5);
  col.push_back(4);
  col.push_back(3);
  col.push_back(2);
  col.push_back(1);
  if ( col.size() < nfile ) { col.resize(nfile,1); }
  
  std::vector<int> at;
//   at.push_back(500);
//   at.push_back(501);
//   at.push_back(502);
//   at.push_back(503);
//   at.push_back(504);
//   at.push_back(505);
//   at.push_back(510);
// //   at.push_back(515);
//    at.push_back(520);
// //    at.push_back(525);
//   at.push_back(530);
// //   at.push_back(535);
//   at.push_back(540);
//   at.push_back(545);
  at.push_back(550);
//     at.push_back(555);
//     at.push_back(560);
//    at.push_back(565);
//    at.push_back(570);
//    at.push_back(575);
//    at.push_back(580);
//    at.push_back(585);
//    at.push_back(590);
//    at.push_back(595);
//    at.push_back(600);
//    at.push_back(700);
//    at.push_back(800);
//    at.push_back(900);
//    at.push_back(1000);
//    at.push_back(2000);
//    at.push_back(3000);
//    at.push_back(4000);
//    at.push_back(5000);
  const uint nat = at.size();

  std::vector<int> multi;
  //multi.push_back(2);
  //multi.push_back(3);
  //multi.push_back(4);
  //multi.push_back(5);
  //multi.push_back(6);
  multi.push_back(-2);
  //multi.push_back(-3);
  //multi.push_back(-4);
  const uint nmulti = multi.size();
  
  // HT bins
  double ht_min = 250.;
  double ht_max = 350.;
  double ht_step = 50.;
//   double ht_min = 250.;
//   double ht_max = 375.;
//   double ht_step = 25.;
//   double ht_min = 400.;
//   double ht_max = 525.;
//   double ht_step = 25.;
  std::vector<double> ht;
  for ( uint iht = uint(ht_min); iht <= uint(ht_max); iht += uint(ht_step) ) { ht.push_back(iht); }
  const uint nht = ht.size();
  
  // pT bins
  std::vector<double> pt;
  for ( uint iht = 0; iht < ht.size(); ++iht ) { pt.push_back(ht[iht]/x3_factor); }
  const uint npt = pt.size();
  
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
	     his, files, lumis, multi, at, pt, ht, 
	     ht_min, ht_max, ht_step,
	     numer, numer_err, denom, denom_err, ratio, errh, errl, length,
	     data_file, lumi );
  
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
	    double d = denom[ifile][imulti][iat][iht][iht];
	    double r = ratio[ifile][imulti][iat][iht][iht];
	    double eh = errh[ifile][imulti][iat][iht][iht];
	    double el = errl[ifile][imulti][iat][iht][iht];
	    std::cout << " PRINT:"
		      << " sample: \"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " AlphaT: " << at[iat]
		      << " HT :" << ht[iht]
	      //<< ", pT :" << pt[iht]
		      << ", pass: " << n
		      << "+/-" << sqrt(n)
	      //<< " (" << ( n > 0. ? sqrt(n)/n : -1. ) << ")" 
		      << ", fail: " << d
		      << "+/-" << sqrt(d)
	      //<< " (" << ( d > 0. ? sqrt(d)/d : -1. ) << ")" 
	      //<< " R: " << ( d > 0. ? n/d : -1. )
	      //<< " E: " << ( d > 0. ? sqrt(n*(n/(n+d))*(1-(n/(n+d)))) : -1. )
		      << ", ratio: " << r
		      << "+" << eh
		      << "-" << el
	      //<< " (" << ( r > 0. ? eh/r : -1. ) << "," 
	      //<< ( r > 0. ? el/r : -1. ) << ")" 
		      << std::endl;
	  }
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
	  if ( data_file == -1 ) {
	    for ( uint iifile = 0; iifile < nfile; ++iifile ) {
	      if ( ratio[iifile][imulti][iat][bin][bin] > 0. ) {
		data_file = iifile; 
		break;
	      }
	    }
	  }
	  if ( data_file == -1 ) { data_file = 0; }

	  double d_val = ratio[data_file][imulti][iat][bin][bin];
	  double d_errh = errh[data_file][imulti][iat][bin][bin];
	  double d_errl = errl[data_file][imulti][iat][bin][bin];
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
	    double d_errh = sqrt( denom[ifile][imulti][iat][ipt][iht] );
	    double d_errl = sqrt( denom[ifile][imulti][iat][ipt][iht] );
	    
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
		double b0_val = ratio[ifile][imulti][iat][0][0];
		double b0_errh = errh[ifile][imulti][iat][0][0];
		double b0_errl = errl[ifile][imulti][iat][0][0];
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
		double b0_val = ratio[ifile][imulti][iat][0][0];
		double b0_errh = errh[ifile][imulti][iat][0][0];
		double b0_errl = errl[ifile][imulti][iat][0][0];
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
	  double d2_errh = sqrt( denom[ifile][imulti][iat][2][2] );
	  double d2_errl = sqrt( denom[ifile][imulti][iat][2][2] );
	  
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
	    std::cout << " TWO MEASUREMENTS: sample:\"" << type[ifile] << "\""
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
	    
	    // Ratio of events (from data) observed to fail AlphaT cut in bin HT=250
	    double d0_val = ratio[data_file][imulti][iat][0][0];
	    double d0_errh = errh[data_file][imulti][iat][0][0];
	    double d0_errl = errl[data_file][imulti][iat][0][0];
	    
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
	    double d2_errh = sqrt(denom[data_file][imulti][iat][2][2]);
	    double d2_errl = sqrt(denom[data_file][imulti][iat][2][2]);
	    
	    estimate_val[data_file][imulti][iat][2][2] = d2_val * r2_val;
	    estimate_errh[data_file][imulti][iat][2][2] = 0.;
	    estimate_errl[data_file][imulti][iat][2][2] = 0.;
	    
	    std::stringstream sss;
	    calcErr( estimate_val[data_file][imulti][iat][2][2],
		     estimate_errh[data_file][imulti][iat][2][2],
		     estimate_errl[data_file][imulti][iat][2][2],
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
    double observed[nfile][nmulti][nat];
    double error[nfile][nmulti][nat];
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  predicted_val[ifile][imulti][iat] = 0.;
	  predicted_errh[ifile][imulti][iat] = 0.;
	  predicted_errl[ifile][imulti][iat] = 0.;
	  observed[ifile][imulti][iat] = 0.;
	  error[ifile][imulti][iat] = 0.;
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
	  double n_err = sqrt(numer[ifile][imulti][iat][ht_bin][ht_bin]);
	  
	  if ( mc_measurement ) {
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
	      observed[ifile][imulti][iat] = n_val;
	      error[ifile][imulti][iat] = 0.;
	      if ( e_val > n_val ) { error[ifile][imulti][iat] = sqrt( e_errl*e_errl + n_err*n_err ); }
	      else { error[ifile][imulti][iat] = sqrt( e_errh*e_errh + n_err*n_err ); }
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
	    observed[ifile][imulti][iat] = n_val;
	    error[ifile][imulti][iat] = 0.;
	    if ( e_val > n_val ) { error[ifile][imulti][iat] = sqrt( e_errl*e_errl + n_err*n_err ); }
	    else { error[ifile][imulti][iat] = sqrt( e_errh*e_errh + n_err*n_err ); }
	  }
	  
	} // ifile
	ss << " \\\\" << std::endl;
	
      } // imulti

      ss << "   \\noalign{\\smallskip}\\hline" << std::endl;
      ss << "  \\end{tabular}" << std::endl;
      ss << "  \\caption{"
	 << " Predicted and measured QCD yields for "
	 << " the cut value $\\alpha_{T} = " << at[iat] /1000. << "$ and ";
      if ( ht_bin == nht-1 ) { ss << "$H_{T} \\geq " << ht[ht_bin] << "$"; }
      else { ss << "$" << ht[ht_bin] << " \\leq H_{T} < " << ht[ht_bin]+ht_step << "$"; }
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
      ss << ".}" << std::endl;
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
    if (syst) {
      gStyle->SetOptStat("emr");
      uint imulti = 0;
      for ( uint iat = 0; iat < nat; ++iat ) {
	std::stringstream ss;
	ss << "Difference_AlphaT" << at[iat]/1000.;
	TCanvas* c1 = new TCanvas(ss.str().c_str(),ss.str().c_str());
	c1->SetFillColor(0);
	c1->SetLineColor(0); 
	TH1D* difference = new TH1D(ss.str().c_str(),ss.str().c_str(),8000,-40.,40.);
	for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	  //if ( int(ifile) == data_file ) { continue; }
	  difference->Fill( predicted_val[ifile][imulti][iat]-observed[ifile][imulti][iat], 1. );
	  if (true) {
	    std::cout << " PREDICTED/OBSERVED:"
		      << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]/1000.
		      << " pred: " << predicted_val[ifile][imulti][iat]
		      << " obs: " << observed[ifile][imulti][iat]
		      << " diff: " << predicted_val[ifile][imulti][iat] - observed[ifile][imulti][iat]
		      << " error: " << error[ifile][imulti][iat]
		      << std::endl;
	  }
	}
	c1->cd();
	difference->Draw("h");
	c1->SaveAs(TString(ss.str()+".C")); 
      }
    }
      
    // Plot ( N_{predicted} - N_{observed} ) vs AlphaT
    if (killer) {

      TCanvas* c1 = new TCanvas("DifferenceVsAlphaT","");
      c1->SetFillColor(0);
      c1->SetLineColor(0); 
      c1->SetRightMargin(0.2);
      TLegend* legend = new TLegend( 0.82, 0.5, 0.98, 0.9, NULL, "brNDC" );
      legend->SetFillColor(0);
      legend->SetLineColor(0); 
      legend->SetShadowColor(0); 
      
      TMultiGraph* mg = new TMultiGraph();
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {

	uint imulti = 0;
	double scale_offset = 0.;
	
	if ( mc_measurement && int(ifile) == data_file ) { continue; }
	std::vector<double> xval;
	std::vector<double> xerrl;
	std::vector<double> xerrh;
	std::vector<double> yval;
	std::vector<double> yerrl;
	std::vector<double> yerrh;
	for ( uint iat = 0; iat < nat; ++iat ) {

	  double val = scale_offset + predicted_val[ifile][imulti][iat] - observed[ifile][imulti][iat];

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
	  yerrl.push_back( error[ifile][imulti][iat] );
	  yerrh.push_back( error[ifile][imulti][iat] );

	  if (true) {
	    std::cout << " PREDICTED/OBSERVED:"
		      << " sample:\"" << type[ifile] << "\""
		      << " multi: " << multi[imulti]
		      << " aT:" << at[iat]/1000.
		      << " pred: " << predicted_val[ifile][imulti][iat]
		      << " obs: " << observed[ifile][imulti][iat]
		      << " diff: " << yval.back()
		      << " error: " << error[ifile][imulti][iat]
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
      mg->GetXaxis()->SetTitle("#alpha_{T}");
      mg->GetYaxis()->SetTitle("N_{predicted} - N_{observed}");
      //mg->GetYaxis()->SetRangeUser(min[iat]/2.,max[iat]*2.);
      legend->Draw("same");
      c1->Update();
      c1->SaveAs("DifferenceVsAlphaT.png"); 
      c1->SaveAs("DifferenceVsAlphaT.C"); 
      
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
  if ( plots ) {

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
	    if ( choice == PLOT_NUMERATOR ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = numer[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = sqrt(numer[ifile][imulti][iat][iht][iht]);
	      erryl[ifile][imulti][iat][iht] = sqrt(numer[ifile][imulti][iat][iht][iht]);
	    } else if ( choice == PLOT_DENOMINATOR ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = denom[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = sqrt(denom[ifile][imulti][iat][iht][iht]);
	      erryl[ifile][imulti][iat][iht] = sqrt(denom[ifile][imulti][iat][iht][iht]);
	    } else if ( choice == PLOT_ESTIMATE ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = estimate_val[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = estimate_errh[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = estimate_errl[ifile][imulti][iat][iht][iht];
	    } else if ( choice == PLOT_ANCHORED ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = anchored_val[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = anchored_errh[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = anchored_errl[ifile][imulti][iat][iht][iht];
	    } else if ( choice == PLOT_RATIO ) {
	      valx[ifile][imulti][iat][iht] = ht[iht] + ht_step/2. + axis_offset1*ifile;
	      errxh[ifile][imulti][iat][iht] = ht_step/2. + axis_offset1*ifile;
	      errxl[ifile][imulti][iat][iht] = ht_step/2. - axis_offset1*ifile;
	      valy[ifile][imulti][iat][iht] = ratio[ifile][imulti][iat][iht][iht];
	      erryh[ifile][imulti][iat][iht] = errh[ifile][imulti][iat][iht][iht];
	      erryl[ifile][imulti][iat][iht] = errl[ifile][imulti][iat][iht][iht];
	    } else {
	      valx[ifile][imulti][iat][iht] = 0.;
	      errxh[ifile][imulti][iat][iht] = 0.;
	      errxl[ifile][imulti][iat][iht] = 0.;
	      valy[ifile][imulti][iat][iht] = 0.;
	      erryh[ifile][imulti][iat][iht] = 0.;
	      erryl[ifile][imulti][iat][iht] = 0.;
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
	    if ( ht[iht] < ht_min && ht[iht] > ht_max+ht_step ) { continue; }
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
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  
	  std::string name;
	  if ( choice == PLOT_NUMERATOR ) { name = "Pass"; } 
	  else if ( choice == PLOT_DENOMINATOR ) { name = "Fail"; } 
	  else if ( choice == PLOT_ESTIMATE ) { name = "Estimate"; } 
	  else if ( choice == PLOT_ANCHORED ) { name = "Anchored"; } 
	  else if ( choice == PLOT_RATIO ) { name = "Ratio"; } 
	  else { name = "Unknown"; } 
  
	  std::stringstream ss_canvas;
	  ss_canvas << "Multi";
	  if ( multi[imulti] >= 0 ) { ss_canvas << multi[imulti]; }
	  else { ss_canvas << abs(multi[imulti]) << "Incl"; }
	  ss_canvas << "_AlphaT" << at[iat]/1000.;
	  
	  TCanvas* canvas = new TCanvas(TString(name+"_"+ss_canvas.str()),
					TString(name+"_"+ss_canvas.str()));

	  canvas->SetFillColor(0);
	  canvas->SetLineColor(0); 
	  canvas->SetLogy();

	  canvas->SetRightMargin(0.2);
	
	  TLegend* legend = new TLegend( 0.82, 0.7, 0.98, 0.9, NULL, "brNDC" );
	  legend->SetFillColor(0);
	  legend->SetLineColor(0); 
	  legend->SetShadowColor(0); 

	  TMultiGraph* mg = new TMultiGraph();
	
	  std::stringstream ss_axis;
	  if ( choice == PLOT_NUMERATOR ) { 
	    ss_axis << "N(#alpha_{T}>" << at[iat]/1000. << ")"; 
	  } else if ( choice == PLOT_DENOMINATOR ) { 
	    ss_axis << "N(#alpha_{T}<" << at[iat]/1000. << ")"; 
	  } else if ( choice == PLOT_ESTIMATE ) { 
	    ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")"
		    << " #upoint"
		    << " N(#alpha_{T}<" << at[iat]/1000. << ")"; 
	  } else if ( choice == PLOT_ANCHORED ) { 
	    ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")";
	  } else if ( choice == PLOT_RATIO ) { 
	    ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")";
	  } else { ss_axis << "a.u."; }
      
	  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	  
	    std::stringstream ss_histo;
	    ss_histo << name << "_" << type[ifile] << "_" << ss_canvas.str();
	    
	    TH1D* histo = new TH1D("","",nht,ht_min,ht_max+ht_step);
	    for ( uint ii = 0; ii < nht; ++ii ) {
	      double v = valy[ifile][imulti][iat][ii];
	      double e = erryh[ifile][imulti][iat][ii];
	      histo->SetBinContent(ii+1,v); 
	      histo->SetBinError(ii+1,e);
	      if ( false && ifile == 1 && iat == 2 ) {
		std::cout << " sample:\"" << type[ifile] << "\""
			  << " multi: " << multi[imulti]
			  << " aT:" << at[iat]
			  << " pT:" << pt[ii]
			  << " HT:" << ht[ii]
			  << " ratio:" << v
			  << " +/- " << e
			  << " (" << ( v > 0. ? e/v : -1. ) << ") " 
			  << std::endl;
	      }
	    
	    }

	    histo->GetYaxis()->SetRangeUser(min[imulti][iat]/2.,max[imulti][iat]*2.);
	    histo->GetXaxis()->SetTitle("HT_{reco} [GeV]");
	    histo->GetYaxis()->SetTitle(TString(ss_axis.str()));
	    histo->SetMarkerStyle(style[ifile]);
	    histo->SetMarkerSize(size[ifile]);
	    histo->SetMarkerColor(col[ifile]);
	    
	    std::stringstream ss_legend;
	    ss_legend << type[ifile];
	    legend->AddEntry( histo, TString(ss_legend.str()), "lep" );
	  
	    //if ( ifile == 0 ) { histo->Draw("E1"); }
	    //else { histo->Draw("sameE1"); }
	  
	    //TGraphAsymmErrors* gr = new TGraphAsymmErrors(histo);
	    TGraphAsymmErrors* gr = new TGraphAsymmErrors(nht,
							  valx[ifile][imulti][iat],
							  valy[ifile][imulti][iat],
							  errxh[ifile][imulti][iat],
							  errxl[ifile][imulti][iat],
							  erryl[ifile][imulti][iat],
							  erryh[ifile][imulti][iat]);
	    for ( uint ii = 0; ii < nht; ++ii ) {
	      double x = 0.;
	      double y = 0.;
	      gr->GetPoint(ii,x,y);
	      if ( y == 0. ) { gr->SetPointEYhigh(ii,0.); gr->SetPointEYlow(ii,0.); }
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

	    mg->Add(gr,"p");
	    gr->SetTitle(TString(ss_legend.str()));
	    gr->SetMarkerStyle(style[ifile]);
	    gr->SetMarkerSize(size[ifile]);
	    gr->SetMarkerColor(col[ifile]);
	  
	  }
	
	  mg->Draw("a");
	  mg->GetXaxis()->SetTitle("HT_{reco} [GeV]");
	  mg->GetYaxis()->SetTitle(TString(ss_axis.str()));
	  mg->GetXaxis()->SetRangeUser(ht_min,ht_max+ht_step);
	  mg->GetYaxis()->SetRangeUser(min[imulti][iat]/2.,max[imulti][iat]*2.);
	
	  legend->Draw("same");
	  canvas->Update();
	
	  std::stringstream ss_text;
	  ss_text << "#alpha_{T} = " << at[iat]/1000.;
      
	  TLatex* text = new TLatex(0.5,0.92,TString(ss_text.str()));
	  text->SetNDC(kTRUE);
	  text->SetTextSize(0.04);
	  //text->Draw();

	  canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".png")); 
	  
	} // iat
      } // imulti
      
    } // npt == nht

  }    

  return 0;

}
