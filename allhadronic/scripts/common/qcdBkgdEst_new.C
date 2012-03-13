#include "utilities_new.C"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <TH1.h>

// -----------------------------------------------------------------------------
//  
int qcdBkgdEst_new() {

//   int nn = 100;
//   std::vector<float> xx;
//   std::vector<float> yy;
//   for ( uint i = 0; i < nn; ++i ) { xx.push_back( i*100. ); }
//   for ( uint ilumi = 0; ilumi < nn; ++ilumi ) { 
  
  bool plots = true;

  // 0 = false (force to gaussian), 1 = true, 2 = for prescales
  int use_sumw2 = 2; 
  
  std::string label = "";

  //int last_bin = 7;
  
  setTDRStyle();
  
  // Misc
  bool efficiency = false;

  enum choices { PLOT_NUMERATOR=1, PLOT_DENOMINATOR=2, PLOT_RATIO=5 };
  int choice = 5;
  bool min_max_with_errors = true;

  bool use_meff = false;
  
  double axis_offset = 2.;
  
  bool simulation = false; 
  
  // Some analysis defaults
  double offset = 0.;
  //double pt1_default = 100.;
  //double pt2_default = 100.;
  //double pt3_default = 50.;
  //double ht_default = 375. + offset;
  //double meff_default = ht_default + pt3_default;
  //double x1_default = pt1_default / meff_default;
  //double x2_default = pt2_default / meff_default;
  //double x3_default = pt3_default / meff_default ;
  //double x3_factor = ( 1. - x3_default ) / ( x3_default );

  std::string dir = "/vols/cms04/bainbrid/qcd/stable/SUSY2/results/";
  
  //std::string histo = "HtAfterAlphaT";
  //std::string histo = "HtAfterRecHit";
  std::string histo = "HtAfterBaby";
  
  std::vector<double> at;
  at.push_back(0.51);
  at.push_back(0.52);
  at.push_back(0.53);
  at.push_back(0.54);
  at.push_back(0.55);
  //at.push_back(0.60);
  const uint nat = at.size();

  std::vector<int> multi;
  multi.push_back(-2);
  const uint nmulti = multi.size();
  
  double ht_min = 0.;
  double ht_max = 0.;
  int nht = 20; //@@ number of bins
  std::vector<double> ht;
  std::vector<double> ht_step;
  
  // override histo binning
  if ( true ) { 
    ht.push_back(275.); 
    ht.push_back(325.); 
    for ( uint iht = 0; iht <= 6; ++iht ) { ht.push_back(375.+iht*100.); }
    //for ( uint iht = 0; iht <= 8; ++iht ) { ht.push_back(300.+iht*100.); }
    nht = ht.size() - 1; 
    ht_min = ht.front() + offset;
    ht_max = ht.back() + offset;
  }
  
  // -----------------------------------------------------------------------------
  // -----------------------------------------------------------------------------
  // -----------------------------------------------------------------------------

  StringVV files;
  
  bool test = true;
  if ( test ) {
    //std::string trunk = dir + "v02/Ratio__";
    //StringV q; q.push_back(trunk+"data.root"); files.push_back(q);
    //StringV q1; q1.push_back(dir + "v19/Ratio__data.root"); files.push_back(q1);
     StringV q3; q3.push_back(dir + "v21/Ratio__data.root"); files.push_back(q3);
     StringV q1; q1.push_back(dir + "v26/Ratio__data_1fb.root"); files.push_back(q1);
     StringV q2; q2.push_back(dir + "v22/Ratio__data.root"); files.push_back(q2);
    //StringV q; q.push_back("../python/Ratio_QCDPY.root"); 
    //StringV w(q); w.push_back(trunk+"wjets.root");
    //StringV z(q); z.push_back(trunk+"zinv.root");
    //StringV tt(q); tt.push_back(trunk+"ttbar.root");
  }
  
  bool results = false;
  if ( results ) {

    std::string trunk = dir + "v08/Ratio__";
    StringV q; q.push_back(trunk+"qcdmg.root"); 
    
    StringV sm(q); 
    sm.push_back(trunk+"wjets.root");
    sm.push_back(trunk+"zinv.root");
    sm.push_back(trunk+"ttbar.root");
    files.push_back(sm);

    StringV sm1(q); 
    sm1.push_back(trunk+"wjets_incl.root");
    sm1.push_back(trunk+"zinv.root");
    sm1.push_back(trunk+"ttbar.root");
    files.push_back(sm1);
    
    //StringV lm6(sm); lm6.push_back(trunk+"lm6.root"); files.push_back(lm6);
    StringV wi(q); wi.push_back(trunk+"wjets_incl.root"); files.push_back(wi);
    StringV w(q); w.push_back(trunk+"wjets.root"); files.push_back(w);
    StringV z(q); z.push_back(trunk+"zinv.root"); files.push_back(z);
    StringV tt(q); tt.push_back(trunk+"ttbar.root"); files.push_back(tt);
    //StringV t(q); t.push_back(trunk+"top.root"); files.push_back(t);
     
    files.push_back(StringV(1,dir+"v08/Ratio__data.root"));

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
  
  const uint nfile = files.size();
  
  std::vector<std::string> his;
  if ( his.size() < nfile ) { his.resize(nfile,histo); }
  
  std::vector<std::string> type;

  if ( test ) { 
//     type.push_back("1");
//     type.push_back("2");
    //type.push_back("Data");
    type.push_back("HT-aT cross triggers");
    type.push_back("HT-MHT cross triggers");
    type.push_back("HT prescaled triggers");
    //type.push_back("QcdMg");
    //type.push_back("Nominal");
    //type.push_back("Alternative");
  }

  if ( results ) {
    //type.push_back("SM + LM6 (Spring11)");
    //type.push_back("Spring11");
    //type.push_back("Summer11(Wincl)");
    //type.push_back("Summer11(W300)");
    type.push_back("SM (W+jets HT-binned)");
    type.push_back("SM (W+jets inclusive)");
//     type.push_back("SM   ");
    type.push_back("Wjets (incl)");
    type.push_back("Wjets (HT-binned)");
    type.push_back("Zinv ");
    type.push_back("TTbar");
    //type.push_back("Single top  ");
    type.push_back("Data ");
  }
  
  if ( type.size() < nfile ) { type.resize(nfile,"unknown"); }
  
  double lumi = 4650.;
  std::vector<double> lumis;

  if ( test ) {
    lumi = 4650;
    lumis.push_back(100.);
    //lumis.push_back(100.*lumi/1140.);
    lumis.push_back(100.);
    //lumis.push_back(lumi);
  }

  if ( results ) { 
    double tmp = 4650.;//xx[ilumi];
    lumi = tmp;
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
    lumis.push_back(tmp);
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
//   if ( data_file == -1 ) { 
//     data_file = 0;
//     std::cout << "Problem identifying data file!" << std::endl;
//   }
  
  std::vector<int> style;

  if ( test ) {
    style.push_back(20);
    style.push_back(24);
    style.push_back(25);
  }

  if ( results ) {
    style.push_back(24);
    style.push_back(25);
    style.push_back(26);
    style.push_back(28);
    style.push_back(27);
    style.push_back(30);
    style.push_back(20);
  }

  if ( style.size() < nfile ) { style.resize(nfile,25); }
  
  std::vector<double> size;
  if ( size.size() < nfile ) { size.resize(nfile,1.5); }
  
  std::vector<int> col;

  if ( test ) {
    col.push_back(1);
    col.push_back(2);
    col.push_back(4);
  }

  if ( results ) {
    col.push_back(2);
    col.push_back(4);
    col.push_back(6);
    col.push_back(6);
    col.push_back(6);
    col.push_back(6);
    col.push_back(1);
  }

  if ( col.size() < nfile ) { col.resize(nfile,1); }

  // -----------------------------------------------------------------------------
  // -----------------------------------------------------------------------------
  // -----------------------------------------------------------------------------

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
	for ( int iht = 0; iht < nht; ++iht ) {
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
  
  std::cout << " CALCULATING RATIOS..." << std::endl;
  calcRatio( nfile, nmulti, nat, nht, 
	     his, files, lumis, 
	     multi, at, ht, ht_min, ht_max, 
	     numer, numer_errh, numer_errl, 
	     denom, denom_errh, denom_errl, 
	     ratio, errh, errl, length,
	     label,
	     efficiency, use_sumw2,
	     data_file );
  
  ht_step.clear();
  for ( int iht = 0; iht < nht; ++iht ) { ht_step.push_back( ht[iht+1] - ht[iht] ); }
  
//   std::cout << " size " << ht.size()
// 	    << " nbins " << nht 
// 	    << " htmin " << ht_min 
// 	    << " htmax " << ht_max
// 	    << std::endl;
//   for ( int iht = 0; iht <= nht; ++iht ) {
//     std::cout << " ibin " << iht
// 	      << " ht " << ht[iht]
// 	      << " htstep " << (iht<nht?ht_step[iht]:0.)
// 	      << std::endl;
//   }

//   // -----------------------------------------------------------------------------
//   // -----------------------------------------------------------------------------
//   // -----------------------------------------------------------------------------
  
  // Print numbers
  bool print = true;
  if (print) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( int iht = 0; iht < nht; ++iht ) {
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
	      << " aT: " << at[iat]
	      << std::fixed << std::setprecision(0)
		      << " HT: " << ht[iht]
	      << std::scientific << std::setprecision(3)
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
	  for ( int iht = 0; iht < nht; ++iht ) {
	    double d = denom[ifile][imulti][iat][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << d << ", ";
	  }
	  ted << ")" << std::endl;

	  // Tail
	  ted << "\"nHad\":\t\t(";
	  for ( int iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht];
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << n << ", ";
	  }
	  ted << ")" << std::endl;

	  // Mean HT
	  ted << "self._htMeans = (";
	  for ( int iht = 0; iht < nht; ++iht ) {
	    ted << std::setw(9) << std::scientific << std::setprecision(3) << ht[iht] << ", ";
	  }
	  ted << ")" << std::endl;
	  std::cout << ted.str() << std::endl;

	}
      }
    }
  }
  
  // -----------------------------------------------------------------------------
  if (!plots) return 0;
  
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
	for ( int iht = 0; iht < nht; ++iht ) {
	  valx[ifile][imulti][iat][iht] = 0.;
	  errxh[ifile][imulti][iat][iht] = 0.;
	  errxl[ifile][imulti][iat][iht] = 0.;
	  valy[ifile][imulti][iat][iht] = 0.;
	  erryh[ifile][imulti][iat][iht] = 0.;
	  erryl[ifile][imulti][iat][iht] = 0.;
	  double width = (1.*ht_step[nht-1]) / (1.*ht_step[iht]);
	  //std::cout << " iht " << iht << " width " << width << std::endl;
	  if ( choice == PLOT_NUMERATOR ) {
	    valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset*ifile;
	    errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset*ifile;
	    errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset*ifile;
	    valy[ifile][imulti][iat][iht] = numer[ifile][imulti][iat][iht] * width;
	    erryh[ifile][imulti][iat][iht] = numer_errh[ifile][imulti][iat][iht] * width;
	    erryl[ifile][imulti][iat][iht] = numer_errl[ifile][imulti][iat][iht] * width;
	  } else if ( choice == PLOT_DENOMINATOR ) {
	    valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset*ifile;
	    errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset*ifile;
	    errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset*ifile;
	    valy[ifile][imulti][iat][iht] = denom[ifile][imulti][iat][iht] * width;
	    erryh[ifile][imulti][iat][iht] = denom_errh[ifile][imulti][iat][iht] * width;
	    erryl[ifile][imulti][iat][iht] = denom_errl[ifile][imulti][iat][iht] * width;
	  } else if ( choice == PLOT_RATIO ) {
	    //if ( iht < length[ifile][imulti][iat] ) {
	    valx[ifile][imulti][iat][iht] = ht[iht] + ht_step[iht]/2. + axis_offset*ifile;
	    errxh[ifile][imulti][iat][iht] = ht_step[iht]/2. + axis_offset*ifile;
	    errxl[ifile][imulti][iat][iht] = ht_step[iht]/2. - axis_offset*ifile;
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
	for ( int iht = 0; iht < nht; ++iht ) {
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

  // -----------------------------------------------------------------------------
  // Check number of pt and ht bins are the same
  std::cout << " CREATING PLOTS..." << std::endl;

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
      else if ( choice == PLOT_RATIO ) { 
	if ( efficiency ) { name = "Eff"; }
	else { name = "Ratio"; }
      } 
      else { name = "Unknown"; } 
  
      std::stringstream ss_canvas;
      ss_canvas << "Multi";
      if ( multi[imulti] >= 0 ) { ss_canvas << multi[imulti]; }
      else { ss_canvas << abs(multi[imulti]) << "Incl"; }
      ss_canvas << "_AlphaT" << at[iat];

      gStyle->SetOptFit(111);
      TCanvas* canvas = 0;
      TLegend* legend = 0;
      TLatex* prelim = 0;
      TLatex* lumitxt = 0;
      TMultiGraph* mg = 0;

	canvas = new TCanvas(TString(name+"_"+ss_canvas.str()),
			     TString(name+"_"+ss_canvas.str()),800,600);
	    
	canvas->SetFillColor(0);
	canvas->SetLineColor(0); 
	    
	canvas->SetLeftMargin(0.17);
	    
	legend = new TLegend( 0.65, 0.7-(nfile*0.04), 0.85, 0.7, NULL, "brNDC" );
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
	  
      std::stringstream ss_axis;
      if ( choice == PLOT_NUMERATOR ) { 
	ss_axis << "N(#alpha_{T}>" << at[iat] << ") / " << ht_step[nht-1] << " GeV"; 
      } else if ( choice == PLOT_DENOMINATOR ) { 
	if ( efficiency ) { ss_axis << "Total"; }
	else { ss_axis << "N(#alpha_{T}<" << at[iat] << ") / " << ht_step[nht-1] << " GeV"; }
      } else if ( choice == PLOT_RATIO ) { 
	if ( !efficiency ) { 
	  //ss_axis << "R_{#alpha_{T}}(" << at[iat] << ")"; 
	  if ( iat+1 < nat ) { 
	    ss_axis << "N(" << at[iat] << "<#alpha_{T}<" << at[iat+1] << ") / N(#alpha_{T}<" << at[iat] << ")"; 
	  } else { 
	    ss_axis << "N(#alpha_{T}>" << at[iat] << ") / N(#alpha_{T}<" << at[iat] << ")"; 
	  } 
	}
	else { ss_axis << "#varepsilon(#alpha_{T}=" << at[iat] << ")"; }
      } 
      else { ss_axis << "a.u."; }
	  
      std::stringstream ss_flat;
      std::stringstream ss_line;
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

	// Fitting
	if (true) {
	  TGraphAsymmErrors* tmp_gr = new TGraphAsymmErrors(*gr);

	  //tmp_gr->Fit("pol0","Q0","",valx[ifile][imulti][iat][0]-1.e-6,valx[ifile][imulti][iat][last_bin]+1.e-6);
	  tmp_gr->Fit("pol0","Q0","",ht_min-1.e-6,ht_max+1.e-6);
	  TF1* fit_c = (TF1*)tmp_gr->FindObject("pol0");
	  if ( fit_c ) {
	    if ( ifile == 0 ) { ss_flat << "Constant (y=A):" << std::endl; }
	    ss_flat << "" << type[ifile] << " "
		    << std::setprecision(3)
		    << fit_c->GetChisquare() << "/"
		    << std::setprecision(0)
		    << fit_c->GetNDF() << " ("
		    << std::setprecision(3)
		    << fit_c->GetProb() << ") "
		    << std::endl
		    << "" << type[ifile] << " "
		    << std::scientific << std::setprecision(3)
		    << "A: " << fit_c->GetParameter(0) << " +/- " << fit_c->GetParError(0)
		    << std::endl;
	    //yy.push_back( fit_c->GetProb() ); //@@ ADDED
	    if ( (int)ifile == data_file ) { fits.push_back( fit_c->GetProb() ); }
	    //rat.push_back( fit_c->GetParameter(0) );
	  } else {
	    //yy.push_back( 0. ); //@@ ADDED
	    std::cout << " NULL PTR! " << std::endl;
	  }

	  //tmp_gr->Fit("pol1","Q0","",valx[ifile][imulti][iat][0]-1.e-6,valx[ifile][imulti][iat][last_bin]+1.e-6);
	  tmp_gr->Fit("pol1","Q0","",ht_min-1.e-6,ht_max+1.e-6);
	  TF1* fit_l = (TF1*)tmp_gr->FindObject("pol1");
	  if ( fit_l ) {
	    if ( ifile == 0 ) { ss_line << "Linear (y=A+Bx):" << std::endl; }
	    ss_line << "" << type[ifile] << " "
		    << std::setprecision(3)
		    << fit_l->GetChisquare() << "/"
		    << std::setprecision(0)
		    << fit_l->GetNDF() << " ("
		    << std::setprecision(3)
		    << fit_l->GetProb() << ") "
		    << std::endl
		    << "" << type[ifile] << " "
		    << std::scientific << std::setprecision(3)
		    << "A: " << fit_l->GetParameter(0) << " +/- " << fit_l->GetParError(0)
		    << " B: " << fit_l->GetParameter(1) << " +/- " << fit_l->GetParError(1)
		    << std::endl;
	    if ( (int)ifile == data_file ) { fits.push_back( fit_l->GetProb() ); }
	    //rat.push_back( fit_l->GetParameter(0) );
	  } else {
	    std::cout << " NULL PTR! " << std::endl;
	  }

	  //tmp_gr->Fit("expo","Q0","",valx[ifile][imulti][iat][0]-1.e-6,valx[ifile][imulti][iat][last_bin]+1.e-6);
	  //TF1* fit_e = new TF1("expo+expo", tmp_gr->FindObject("expo");
	  //tmp_gr->Fit("expo","Q0","",ht_min-1.e-6,ht_max+1.e-6);
	  tmp_gr->Fit("expo","Q0","",325.-1.e-6,675.+1.e-6);
	  TF1* fit_e = (TF1*)tmp_gr->FindObject("expo");
	  if ( fit_e ) {
	    if ( ifile == 0 ) { ss_expo << "Exponential (y=e^{A+kx}):" << std::endl; }
	    ss_expo << "" << type[ifile] << " "
		    << std::fixed
		    << std::setprecision(3)
		    << fit_e->GetChisquare() << "/"
		    << std::setprecision(0)
		    << fit_e->GetNDF() << " ("
		    << std::setprecision(3)
		    << fit_e->GetProb() << ") "
		    << std::endl
		    << "" << type[ifile] << " "
		    << std::scientific << std::setprecision(3)
		    << "A: " << fit_e->GetParameter(0) << " +/- " << fit_e->GetParError(0)
		    << " k: " << fit_e->GetParameter(1) << " +/- " << fit_e->GetParError(1)
		    << std::endl;
	    if ( (int)ifile == data_file ) { fits.push_back( fit_e->GetProb() ); }
	    rat.push_back( fit_e->GetParameter(1) );
	  } else {
	    std::cout << " NULL PTR! " << std::endl;
	  }

	  //if (tmp_gr) delete tmp_gr;

	}

	for ( int ii = 0; ii < nht; ++ii ) {
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
  	  //std::cout << ss_flat.str() << std::endl;
 	  //std::cout << ss_line.str() << std::endl;
 	  std::cout << ss_expo.str() << std::endl;
 	}

	mg->Add(gr,"p");
	
	std::stringstream ss_legend;
	ss_legend << type[ifile];
	legend->AddEntry( gr, TString(ss_legend.str()), "p" );
	
	gr->SetTitle(TString(ss_legend.str()));
	gr->SetMarkerStyle(style[ifile]);
	gr->SetMarkerSize(size[ifile]);
	gr->SetMarkerColor(col[ifile]);
	gr->SetLineColor(col[ifile]);
	
      } // ifile
	  
      mg->Draw("a");
      mg->GetXaxis()->SetTitle(label.c_str());
      if (!use_meff) mg->GetXaxis()->SetTitle("H_{T} (GeV)");
      else mg->GetXaxis()->SetTitle("M_{eff} (GeV)");
      mg->GetYaxis()->SetTitle(TString(ss_axis.str()));
      mg->GetYaxis()->SetTitleOffset(1.3);
      mg->GetXaxis()->SetRangeUser(ht_min+offset,ht_max+offset);
      mg->GetYaxis()->SetRangeUser(min[imulti][iat]/2.0,max[imulti][iat]*1.2);
      //else mg->GetYaxis()->SetRangeUser(0.,0.12e-3);
      //mg->GetYaxis()->SetNoExponent(true);
      
      //mg->GetXaxis()->SetRangeUser(250,450.);
      //mg->GetYaxis()->SetRangeUser(0.,25.e-6);
      //mg->GetYaxis()->SetRangeUser(0.,0.05e-3);
      //mg->GetYaxis()->SetRangeUser(0.,0.04e-3);
      canvas->SetLogy();
      
      //if      (choice==1) mg->GetYaxis()->SetRangeUser(0.1,1.e4);
      //else if (choice==2) mg->GetYaxis()->SetRangeUser(0.1,1.e8);
      
      legend->Draw("same");
      //prelim->Draw("same");
      //lumitxt->Draw("same");
      canvas->Update();
      
      std::stringstream ss_text;
      ss_text << "#alpha_{T} = " << at[iat];
      
      TLatex* text = new TLatex(0.5,0.92,TString(ss_text.str()));
      text->SetNDC(kTRUE);
      text->SetTextSize(0.04);
      //text->Draw();
      
      //canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".C")); 
      //canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".png")); 
      //canvas->SaveAs(TString(name+"_"+ss_canvas.str()+".pdf")); 

      //if (canvas) delete canvas;
      
    } // iat
  } // imulti
      
  int index = 0;
  std::vector<float> cuts;
  std::vector<float>::const_iterator ifit = fits.begin();
  std::vector<float>::const_iterator jfit = fits.end();
  for ( ; ifit != jfit; ++ifit ) { cuts.push_back(at[index]); index++; }
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


//   }

//   yy.resize(xx.size(),0.);

//   TCanvas* c1 = new TCanvas();
//   TGraph* gr = new TGraph(nn, &(xx.front()), &(yy.front()) );
//   c1->cd();
//   gr->Draw("ap");
//   //gr->SetBorderSize(0);
//   gr->SetTitle("Fit range: 325 < HT < 985");
//   gr->GetXaxis()->SetTitle("Integrated Lumi (pb^{-1})");
//   gr->GetYaxis()->SetTitle("p-value");
//   c1->SaveAs("tmp.C");
//   delete c1;

//   std::cout << std::endl;
//   for ( uint i = 0; i < nn; ++i ) { std::cout << xx[i] << std::endl; }
//   std::cout << std::endl;
//   for ( uint i = 0; i < nn; ++i ) { std::cout << yy[i] << std::endl; }
//   std::cout << std::endl;
  
  return 0;
  
}
