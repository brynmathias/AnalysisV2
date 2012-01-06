#include <TCanvas.h>
#include <TDirectory.h>
#include <TFile.h>
#include <TGraphAsymmErrors.h>
#include <TH1.h>
#include <TH1D.h>
#include <TMath.h>
#include <TMultiGraph.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TRandom3.h>
#include <TStyle.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include "style.C"

// -----------------------------------------------------------------------------
//  
typedef std::vector<double> VDouble;
typedef std::vector<VDouble> VVDouble;
typedef std::vector<VVDouble> VVVDouble;
typedef std::vector<VVVDouble> VVVVDouble;

// -----------------------------------------------------------------------------
// 
double dr( double x, int decimal_places ) {
  if ( decimal_places < 0 ) { return x; }
  if ( x == 0. ) { return 0.; }
  return floor(x*pow(10.,decimal_places)+0.5)/pow(10.,decimal_places); 
}

// -----------------------------------------------------------------------------
//  
TH1D* rebin( TFile* file, const char* name, int multi, int nbins = -1, double xlow = -1., double xhigh = -1. ) {

  // Check for null pointer
  if ( file ) { 
    std::cout << "Opened file with name \"" << file->GetName() << "\"" << std::endl;
  } else {
    std::cout << "Unable to retrieve file!" << std::endl;
    return 0; 
  }
  file->cd();

  // Retreive original histogram
  TH1D* input = 0;
  
  if ( multi == 0 ) {
    std::stringstream tmp; tmp << name << "_all";
    std::cout << "name: " << tmp.str() << std::endl;
    input = (TH1D*)file->Get( tmp.str().c_str() );
  } else if ( multi < 0 ) {
    for ( uint ii = abs(multi); ii < 9; ++ii ) {
      std::stringstream tmp; tmp << name << "_" << ii;
      std::cout << "name: " << tmp.str() << std::endl;
      if ( int(ii) == abs(multi) ) { input = (TH1D*)file->Get( tmp.str().c_str() ); }
      else { input->Add( (TH1D*)file->Get( tmp.str().c_str() ) ); }
    }
  } else {
    std::stringstream tmp; tmp << name << "_" << multi;
    std::cout << "name: " << tmp.str() << std::endl;
    input = (TH1D*)file->Get( tmp.str().c_str() );
  }
  
  if ( input ) { 
    std::cout << "Retrieved histogram with name \"" << input->GetName() << "\"" << std::endl;
  } else {
    std::cout << "Unable to retrieve histogram with name \"" << name << "\"" << std::endl;
    return 0; 
  }
  
  // Rebin original histogram
  std::cout << " INPUT: Nbins: " << input->GetXaxis()->GetNbins()
	    << " Xmin: " << input->GetXaxis()->GetXmin()
	    << " Xmax: " << input->GetXaxis()->GetXmax()
	    << std::endl;
  if ( nbins > 0. ) {
    input->Rebin( int(input->GetXaxis()->GetNbins()/nbins) );
  }
  std::cout << " INPUT: Nbins: " << input->GetXaxis()->GetNbins()
	    << " Xmin: " << input->GetXaxis()->GetXmin()
	    << " Xmax: " << input->GetXaxis()->GetXmax()
	    << std::endl;
  
  // Create new rebinned histogram
  TH1D* output = 0;
  if ( nbins > 0. ) { 
    output = new TH1D( TString(input->GetName())+"_Rebinned", "", 
		       nbins, 
		       xlow, 
		       xhigh );
    std::cout << " OUTPUT: Nbins: " << output->GetXaxis()->GetNbins()
	      << " Xmin: " << output->GetXaxis()->GetXmin()
	      << " Xmax: " << output->GetXaxis()->GetXmax()
	      << std::endl;
  } else {
    output = new TH1D( TString(input->GetName())+"_Rebinned", "", 
		       input->GetXaxis()->GetNbins(), 
		       input->GetXaxis()->GetXmin(), 
		       input->GetXaxis()->GetXmax() );
    std::cout << " OUTPUT: Nbins: " << output->GetXaxis()->GetNbins()
	      << " Xmin: " << output->GetXaxis()->GetXmin()
	      << " Xmax: " << output->GetXaxis()->GetXmax()
	      << std::endl;
  }
  output->Sumw2();

  // Populate new histogram
  for ( int bin = 1; bin <= output->GetNbinsX(); ++bin ) {
    Double_t centre = output->GetBinLowEdge(bin) + output->GetBinWidth(bin)/2.;
    output->SetBinContent( bin, input->GetBinContent( input->FindBin(centre) ) );
    output->SetBinError( bin, input->GetBinError( input->FindBin(centre) ) );
  }
  output->SetEntries( input->GetEntries() );
  
  // Modify last bin to be inclusive
  if ( true ) { 
    // Define value of centre of last bin of output histo
    Double_t centre = output->GetBinLowEdge(output->GetNbinsX()) + output->GetBinWidth(output->GetNbinsX())/2.;
    // Fill last bin of output histo with overflow from output histo
    output->Fill( centre, output->GetBinContent(output->GetNbinsX()+1) );
    // Fill last bin of output histo with overflow from input histo
    output->Fill( centre, input->GetBinContent(input->GetNbinsX()+1) );
  }

  if (true) {
    if ( input ) {
      TH1D* his = input;
      std::stringstream ss;
      ss << "INPUT HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
	 << std::endl
	 << " underflow: " << his->GetBinContent(0)
	 << std::endl
	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl
	 << " entries: " << his->GetEntries()
	 << std::endl
	 << " integral: " << his->Integral()
	 << std::endl
	 << " all: " << his->Integral() + his->GetBinContent(0) + his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl;
      for ( int bin = 1; bin <= his->GetNbinsX(); ++bin ) {
	ss << " bin: " << bin
	   << " val: " << his->GetBinContent(bin)
	   << " err: " << his->GetBinError(bin)
	   << std::endl;
      }
      std::cout << ss.str();
    }
  }
  
  if (true) {
    if ( output ) {
      TH1D* his = output;
      std::stringstream ss;
      ss << "OUTPUT HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
	 << std::endl
	 << " underflow: " << his->GetBinContent(0)
	 << std::endl
	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl
	 << " entries: " << his->GetEntries()
	 << std::endl
	 << " integral: " << his->Integral()
	 << std::endl
	 << " all: " << his->Integral() + his->GetBinContent(0) + his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl;
      for ( int bin = 1; bin <= his->GetNbinsX(); ++bin ) {
	ss << " bin: " << bin
	   << " val: " << his->GetBinContent(bin)
	   << " err: " << his->GetBinError(bin)
	   << std::endl;
      }
      std::cout << ss.str();
    }
  }

  return output;

}


// -----------------------------------------------------------------------------
// 
void calcRatio( const uint nfile, 
		const uint nmulti, 
		const uint nat, 
		const uint nht, 
 		std::vector<std::string> his, 
 		std::vector<std::string> files,
 		std::vector<double> lumis,
 		std::vector<int> multi, 
 		std::vector<int> at, 
 		std::vector<double> ht, 
 		VVVVDouble numer, 
 		VVVVDouble numer_err, 
 		VVVVDouble denom, 
 		VVVVDouble denom_err, 
 		VVVVDouble eff, 
 		VVVVDouble eff_errh, 
 		VVVVDouble eff_errl, 
 		double lumi
		) {
  
  // Loop through data/MC files 
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    
    // Open file
    std::cout << "filename: " << files[ifile] << std::endl;
    TString filename(files[ifile]);
    TFile* file = new TFile(filename);
    if ( file->IsZombie() || !(file->IsOpen()) ) { 
      if (file) { delete file; }
      continue; 
    }
    file->cd();
    
    // Loop through bins of multiplicity
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {

      // Loop through bins of AlphaT
      for ( uint iat = 0; iat < nat; ++iat ) {
      
	//std::cout << ifile << " " << imulti << " " << iat << std::endl;
	
	// Directory and histo names
	std::stringstream dir;
	std::stringstream name;
	std::stringstream pre;
	std::stringstream post;
	dir << "QcdBkgdEst/";
	name << his[ifile] << "_aT"; 
	pre << dir.str() << name.str() << "0";
	post << dir.str() << name.str() << at[iat]/1000.;
	std::cout << "dir: " << dir.str() << std::endl;
	std::cout << "name: " << name.str() << std::endl;
	std::cout << "pre: " << pre.str() << std::endl;
	std::cout << "post: " << post.str() << std::endl;
	
	// Create ratio histo
	TH1D* numerator = 0;
	TH1D* denominator = 0;
	TH1D* above = 0;
	TH1D* below = 0;
	TH1D* total = 0;
	TH1D* divide = 0;
	TGraphAsymmErrors* errors = 0;
	numerator = rebin( file, post.str().c_str(), multi[imulti], 16, 0., 4. );
	denominator = rebin( file, pre.str().c_str(), multi[imulti], 16, 0., 4. );
	if ( numerator && denominator ) {
	  numerator->Scale((lumi>0.?lumi:lumis[ifile])/100.);
	  denominator->Scale((lumi>0.?lumi:lumis[ifile])/100.);
	  above = (TH1D*)numerator->Clone(TString(numerator->GetName())+"_Clone");
	  below = (TH1D*)denominator->Clone(TString(denominator->GetName())+"_Clone");
	  total = (TH1D*)denominator->Clone(TString(denominator->GetName())+"_Clone");
	  
	  if ( above && below ) { 
	    if ( false ) { 
	      std::cout << " CONTENTS: file: " << ifile 
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< std::endl;
	      for ( uint iht = 0; iht < (uint)above->GetNbinsX(); ++iht ) {
		std::cout << "  HT:" << ht[iht]
			  << " numer: " 
			  << numerator->GetBinContent(iht+1) 
			  << " denom: " 
			  << denominator->GetBinContent(iht+1) 
			  << " above: " 
			  << above->GetBinContent(iht+1) 
			  << " below: " 
			  << below->GetBinContent(iht+1) 
			  << " total: " 
			  << total->GetBinContent(iht+1) 
			  << std::endl;
	      }
	    }
	    divide = (TH1D*)above->Clone(TString(above->GetName())+"_Clone");
	    if ( divide ) { 
	      divide->Divide(below);
	      errors = new TGraphAsymmErrors(above,below);
	    }
	  }
	}
	
	// Loop through bins of HT
	if ( above && below && divide ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    numer[ifile][imulti][iat][iht] = above->GetBinContent(iht+1);
	    numer_err[ifile][imulti][iat][iht] = above->GetBinError(iht+1);
	    denom[ifile][imulti][iat][iht] = below->GetBinContent(iht+1);
	    denom_err[ifile][imulti][iat][iht] = below->GetBinError(iht+1);
	    eff[ifile][imulti][iat][iht] = divide->GetBinContent(iht+1);
	    eff_errh[ifile][imulti][iat][iht] = errors->GetErrorYhigh(iht);
	    eff_errl[ifile][imulti][iat][iht] = errors->GetErrorYlow(iht);
	    if ( false &&
		 ( eff_errl[ifile][imulti][iat][iht] < 1.e-100 ||
		   eff_errh[ifile][imulti][iat][iht] < 1.e-100 ) ) { 
	      std::cout << " ERRORS: file: " << ifile 
			<< " multi: " << multi[imulti]
			<< " aT:" << at[iat]
			<< " HT:" << ht[iht]
			<< " vals: " 
			<< numer[ifile][imulti][iat][iht] << " " 
			<< numer_err[ifile][imulti][iat][iht] << " " 
			<< denom[ifile][imulti][iat][iht] << " " 
			<< denom_err[ifile][imulti][iat][iht] << " " 
			<< eff[ifile][imulti][iat][iht] << " " 
			<< eff_errl[ifile][imulti][iat][iht] << " "
			<< eff_errh[ifile][imulti][iat][iht] << " "
			<< errors->GetErrorYhigh(iht) << " "
			<< errors->GetErrorYlow(iht) << " "
			<< std::endl;
	    }
	    if ( eff_errl[ifile][imulti][iat][iht] <= 1.e-100 ) { 
	      eff_errl[ifile][imulti][iat][iht] = eff[ifile][imulti][iat][iht]; 
	    }
	    if ( eff_errh[ifile][imulti][iat][iht] <= 1.e-100 ) { 
	      eff_errh[ifile][imulti][iat][iht] = 1.-eff[ifile][imulti][iat][iht]; 
	    }
	  } 
	}
	
	if (numerator) { delete numerator; }
	if (denominator) { delete denominator; }
	if (above) { delete above; }
	if (below) { delete below; }
	if (total) { delete total; }
	if (divide) { delete divide; }
	if (errors) { delete errors; }
	
      } // Loop through aT bins
    } // Loop through multiplicity bins
    
    // Close file that was opened
    if (file) {
      file->cd();
      file->Close();
      delete file;
    } 
    
  } // Loop through files
  
  bool print = false;
  if (print) {
    std::stringstream ss;
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    ss << " CHECK:"
	       << " ifile: " << ifile
	       << " multi: " << multi[imulti]
	       << " AlphaT: " << at[iat]
	       << " HT :" << ht[iht]
	       << " n: " << numer[ifile][imulti][iat][iht]
	       << " n_err: " << numer_err[ifile][imulti][iat][iht]
	       << " sqrt(n): " << sqrt(numer[ifile][imulti][iat][iht])
	       << " d: " << denom[ifile][imulti][iat][iht]
	       << " d_err: " << denom_err[ifile][imulti][iat][iht]
	       << " sqrt(d): " << sqrt(denom[ifile][imulti][iat][iht])
	       << " r: " << eff[ifile][imulti][iat][iht]
	       << " eh: " << eff_errh[ifile][imulti][iat][iht]
	       << " el: " << eff_errl[ifile][imulti][iat][iht];
	    if ( eff[ifile][imulti][iat][iht] <= 0. ) { ss << " (0,0)"; }
	    else { 
	      ss << " (" 
		 << dr(eff_errh[ifile][imulti][iat][iht]/eff[ifile][imulti][iat][iht],2) 
		 << ","
		 << dr(eff_errl[ifile][imulti][iat][iht]/eff[ifile][imulti][iat][iht],2)
		 << ")"; 
	    }
	    ss << std::endl;
	  }
	}
      }
    }
    std::cout << ss.str();
  }
  
}

// -----------------------------------------------------------------------------
//  
int signalOverBkgd() {

  setTDRStyle();
  
  // Some analysis defaults
  double pt1_default = 100.;
  double pt2_default = 100.;
  double pt3_default = 50.;
//   double meff_default = ht_default + pt3_default;
//   double x1_default = pt1_default / meff_default;
//   double x2_default = pt2_default / meff_default;
//   double x3_default = pt3_default / meff_default ;
//   double x3_factor = ( 1. - x3_default ) / ( x3_default );

  std::stringstream dir1;
  dir1 << "101026";
  std::stringstream dir2;
  dir2 << pt1_default << "_" << pt2_default << "_" << pt3_default;
  
  std::vector<std::string> files;
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_lm0.root");
  files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_qcd.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_sm.root");
//   files.push_back("../../../results/batch/"+dir1.str()+"_1/"+dir2.str()+"/QcdBkgdEst_data.root");
  const uint nfile = files.size();
  
  std::vector<std::string> his;
//   his.push_back("BabyCaloOverMeffAfterDeadEcal_Meff500");
//   his.push_back("BabyCaloOverMeffAfterDeadEcal_Meff500");
//   his.push_back("BabyCaloOverMeffAfterDeadEcal_Meff500");
//   his.push_back("BabyCaloOverMeffAfterDeadEcal_Meff500");
  his.push_back("BabyMhtOverMetAfterDeadEcal_HT350");
  his.push_back("BabyMhtOverMetAfterDeadEcal_HT350");
  his.push_back("BabyMhtOverMetAfterDeadEcal_HT350");
  his.push_back("BabyMhtOverMetAfterDeadEcal_HT350");
  if ( his.size() < nfile ) { his.resize(nfile,"Ht"); }
  
  std::vector<std::string> type;
  type.push_back("lm0");
  type.push_back("qcd");
  type.push_back("sm");
  type.push_back("data");
  if ( type.size() < nfile ) { type.resize(nfile,"unknown"); }
  
  double lumi = -1.;
  std::vector<double> lumis;
  lumis.push_back(15.1);
  lumis.push_back(15.1);
  lumis.push_back(15.1);
  lumis.push_back(100.); // data
  if ( lumis.size() < nfile ) { lumis.resize(nfile,100.); }
 
  std::vector<int> style;
  style.push_back(25);
  style.push_back(25);
  style.push_back(25);
  style.push_back(21);
  if ( style.size() < nfile ) { style.resize(nfile,25); }
  
  std::vector<double> size;
  size.push_back(1.2);
  size.push_back(1.1);
  size.push_back(1.0);
  size.push_back(0.9);
  if ( size.size() < nfile ) { size.resize(nfile,1.); }
  
  std::vector<int> col;
  col.push_back(4);
  col.push_back(3);
  col.push_back(2);
  col.push_back(1);
  if ( col.size() < nfile ) { col.resize(nfile,1); }

  std::vector<int> multi;
  multi.push_back(2);
  //multi.push_back(3);
  //multi.push_back(4);
  //multi.push_back(5);
  //multi.push_back(6);
  //multi.push_back(-2);
  //multi.push_back(-3);
  //multi.push_back(-4);
  const uint nmulti = multi.size();

  std::vector<int> at;
   at.push_back(500);
//   at.push_back(501);
//   at.push_back(502);
//   at.push_back(503);
//   at.push_back(504);
//   at.push_back(505);
//   at.push_back(510);
//   at.push_back(515);
//   at.push_back(520);
//   at.push_back(525);
//   at.push_back(530);
//   at.push_back(535);
//   at.push_back(540);
//   at.push_back(545);
//   at.push_back(550);
//   at.push_back(555);
//   at.push_back(560);
  const uint nat = at.size();
  
  // HT bins
  int    ht_bins = 200;
  double ht_min = -1.;
  double ht_max = 1.;
  std::vector<double> ht;
  for ( uint iht = 0; iht < uint(ht_bins); iht++ ) { ht.push_back(ht_min+iht*((ht_max-ht_min)/(1.*ht_bins))); }
  const uint nht = ht.size();
    
  // Histogram contents
  VVVVDouble numer( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  VVVVDouble numer_err( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  VVVVDouble denom( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  VVVVDouble denom_err( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  VVVVDouble eff( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  VVVVDouble eff_errh( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  VVVVDouble eff_errl( nfile, VVVDouble( nmulti, VVDouble( nat, VDouble(nht) ) ) );
  
  // Min/max values for ratios
  VVDouble min( nmulti, VDouble(nat) );
  VVDouble max( nmulti, VDouble(nat) );
  
  std::cout << " nfile: " << nfile
	    << " nmulti: " << nmulti
	    << " nat: " << nat
	    << " nht: " << nht
	    << " total: " << nfile*nmulti*nat*nht
	    << std::endl;
  
  // Init arrays
  for ( uint iat = 0; iat < nat; ++iat ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint ifile = 0; ifile < nfile; ++ifile ) {
	for ( uint iht = 0; iht < nht; ++iht ) {
	  numer[ifile][imulti][iat][iht] = 0.;
	  numer_err[ifile][imulti][iat][iht] = 0.;
	  denom[ifile][imulti][iat][iht] = 0.;
	  denom_err[ifile][imulti][iat][iht] = 0.;
	  eff[ifile][imulti][iat][iht] = 0.;
	  eff_errh[ifile][imulti][iat][iht] = 0.;
	  eff_errl[ifile][imulti][iat][iht] = 0.;
	}
      }
      min[imulti][iat] = 0.;
      max[imulti][iat] = 0.;
    }
  }
  
  // -----------------------------------------------------------------------------

  std::cout << " CALCULATING RATIOS..." << std::endl;
  calcRatio( nfile, 
	     nmulti, 
	     nat, 
	     nht, 
	     his, 
	     files, 
	     lumis, 
	     multi, 
	     at, 
	     ht, 
	     numer, 
	     numer_err, 
	     denom, 
	     denom_err, 
	     eff, 
	     eff_errh, 
	     eff_errl,
	     lumi );
  
  // -----------------------------------------------------------------------------
  
  
  
  
  
  // -----------------------------------------------------------------------------

  // Print numbers
  bool print = false;
  if (print) {
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( uint iht = 0; iht < nht; ++iht ) {
	    double n = numer[ifile][imulti][iat][iht];
	    double ne = numer_err[ifile][imulti][iat][iht];
	    double d = denom[ifile][imulti][iat][iht];
	    double de = denom_err[ifile][imulti][iat][iht];
	    double r = eff[ifile][imulti][iat][iht];
	    double eh = eff_errh[ifile][imulti][iat][iht];
	    double el = eff_errl[ifile][imulti][iat][iht];
	    std::cout << " PRINT:"
		      << " sample: \"" << ifile << "\""
		      << " multi: " << multi[imulti]
		      << " AlphaT: " << at[iat]
		      << " HT :" << ht[iht]
	      //<< ", pT :" << pt[iht]
		      << ", pass: " << n
		      << "+/-" << ne
		      << " sqrt(p): " << sqrt(n)
	      //<< " (" << ( n > 0. ? sqrt(n)/n : -1. ) << ")" 
		      << ", fail: " << d
		      << "+/-" << de
		      << " sqrt(f): " << sqrt(d)
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
  
  return 0;

}
