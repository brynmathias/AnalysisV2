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

typedef unsigned int uint;

// -----------------------------------------------------------------------------
// Poisson errors for n<20
std::vector<double> poisson_eh;
poisson_eh.push_back(1.84);
poisson_eh.push_back(2.30);
poisson_eh.push_back(2.63);
poisson_eh.push_back(2.92);
poisson_eh.push_back(3.16);
poisson_eh.push_back(3.38);
std::vector<double> poisson_el;
poisson_el.push_back(0.00);
poisson_el.push_back(0.83);
poisson_el.push_back(1.92);
poisson_el.push_back(1.63);
poisson_el.push_back(1.91);
poisson_el.push_back(2.16);
void poissonErr( double x, double& errh, double& errl ) {
  if ( x < 5. ) {
    int n = int(x);
    double f = x - double(int(x));
    errh = poisson_eh[n] + f*( poisson_eh[n+1] - poisson_eh[n] );
    errl = poisson_el[n] + f*( poisson_el[n+1] - poisson_el[n] );
  } else if ( x < 20. ) {
    // Gehrels (1986 ApJ, 303, 336) is an approx, with accuracy better than 2% 
    errh = 1.0 + sqrt(n+0.75); // equ 7, S=1
    errl = 0.0 + sqrt(n-0.25); // equ 11, S=1
  } else {
    // Normal approximation
    errh = sqrt(x);
    errl = sqrt(x);
  }
}

// -----------------------------------------------------------------------------
//  
int qcd( const std::vector<float>& at, const std::vector<float>& pval ) {
  
  if ( at.empty() || pval.empty() || at.size() != pval.size() ) { return -1; }
  
  setTDRStyle();
  
  TCanvas* c1 = new TCanvas("pValueVersusAlphaT","");
  c1->SetFillColor(0);
  c1->SetLineColor(0); 
  //c1->SetRightMargin(0.2);
  
//   TLegend* legend = new TLegend( 0.82, 0.5, 0.98, 0.9, NULL, "brNDC" );
//   legend->SetFillColor(0);
//   legend->SetLineColor(0); 
//   legend->SetShadowColor(0); 
  
  TMultiGraph* mg = new TMultiGraph();
  for ( uint ii = 0; ii < 1; ++ii ) {
    
    TGraphAsymmErrors* gr = 0;
    
    std::vector<float> at_e(at.size(),0.);
    std::vector<float> pval_e(pval.size(),0.);
    
    gr = new TGraphAsymmErrors(at.size(),
			       &at.front(),
			       &pval.front(),
			       &at_e.front(),
			       &at_e.front(),
			       &pval_e.front(),
			       &pval_e.front()
			       );

    mg->Add(gr,"p");
    gr->SetTitle("pValue");
    gr->SetLineColor(1+ii);
    gr->SetMarkerColor(1+ii);
    gr->SetMarkerStyle(20+ii);
    //legend->AddEntry( gr, TString("pValue"), "lep" );
  }
    
  c1->cd();
  mg->Draw("al");
  mg->GetXaxis()->SetTitle("#alpha_{T} cut value");
  mg->GetYaxis()->SetTitle("p-value");
  mg->GetXaxis()->SetRangeUser(0.5,0.6);
  mg->GetYaxis()->SetRangeUser(0.,1.);
  //legend->Draw("same");
  c1->Update();
  c1->SaveAs(TString("pValueVersusAlphaT.pdf")); 
  c1->SaveAs(TString("pValueVersusAlphaT.C")); 
  
}

// -----------------------------------------------------------------------------
//  
double poissonf( double* x, double* par ) {                                                                              
  return par[0] * TMath::Poisson(x[0],par[1]);
}                                                                              

// -----------------------------------------------------------------------------
// 
void checkStats( std::vector<std::string>& type,
		 std::vector<int>& multi,
		 std::vector<int>& at, 
		 uint ifile, uint imulti, uint iat, 
		 double observed, double estimate, double errh, double errl, 
		 double b0_pass, double b0_fail, 
		 double b1_pass, double b1_fail,
		 double b2_fail,
		 double& b2_mean, 
		 double& b2_rms, 
		 double& b2_err ) {

  TDirectory* dir = gDirectory;
  TStyle* style = gStyle;
  gStyle->SetOptStat(1111111);
  
  std::stringstream ss;
  ss << "_" << type[ifile] << "_multi" << multi[imulti] << "_aT" << at[iat]/1000.;
  TCanvas* c2 = new TCanvas(TString("CheckStats"+ss.str()),
			    TString("CheckStats"+ss.str()));
  
  uint number_of_trials = 10000;
  
  // Poisson error
  double b0_pass_err = sqrt(b0_pass);
  double b1_pass_err = sqrt(b1_pass);
  
  // Gaussian error
  double b0_fail_err = sqrt(b0_fail);
  double b1_fail_err = sqrt(b1_fail);

  double xmin = 0.;
  double xmax = 0.;
  
  xmin = 1. * int( b0_fail - 5. * b0_fail_err );
  xmax = 1. * int( b0_fail + 5. * b0_fail_err );
  TH1D* b0_fail_his = new TH1D(TString("b0_fail"+ss.str()),"",int(xmax-xmin),xmin,xmax);

  xmin = 1. * int( b1_fail - 5. * b1_fail_err );
  xmax = 1. * int( b1_fail + 5. * b1_fail_err );
  TH1D* b1_fail_his = new TH1D(TString("b1_fail"+ss.str()),"",int(xmax-xmin),xmin,xmax);
  
  xmin = -1.;
  xmax = 1. * int( b0_pass + 10. * b0_pass_err );
  TH1D* b0_pass_his = new TH1D(TString("b0_pass"+ss.str()),"",int(xmax-xmin),xmin,xmax);
  
  xmin = -1.;
  xmax = 1. * int( b1_pass + 10. * b1_pass_err );
  TH1D* b1_pass_his = new TH1D(TString("b1_pass"+ss.str()),"",int(xmax-xmin),xmin,xmax);
  
  xmin = -1.;
  xmax = 1. * int( b1_pass + 10. * b1_pass_err );
  TH1D* b2_pred_his = new TH1D(TString("b2_pred"+ss.str()),"",int(xmax-xmin),xmin,xmax);
  
  TRandom3 rand;
  for ( uint ii = 0; ii < number_of_trials; ++ii ) {

    double b0_pass_rand = rand.PoissonD(b0_pass);
    double b1_pass_rand = rand.PoissonD(b1_pass);
    double b0_fail_rand = rand.Gaus(b0_fail,b0_fail_err);
    double b1_fail_rand = rand.Gaus(b1_fail,b1_fail_err);
    
    b0_pass_his->Fill(b0_pass_rand);
    b1_pass_his->Fill(b1_pass_rand);
    b0_fail_his->Fill(b0_fail_rand);
    b1_fail_his->Fill(b1_fail_rand);

    double b0_ratio = ( b0_fail_rand > 0. ? b0_pass_rand/b0_fail_rand : 0. );
    double b1_ratio = ( b1_fail_rand > 0. ? b1_pass_rand/b1_fail_rand : 0. );
    
    double ratio = ( b0_ratio > 0. && b1_ratio > 0. ? b1_ratio/b0_ratio : 0. );
    double b2_ratio = b1_ratio * ratio;
    
    double b2_pred_rand = b2_ratio * b2_fail;
    if ( ratio > 0. ) { b2_pred_his->Fill(b2_pred_rand); }
    
  }

  // Pass/fail distributions
  c2->Divide(2,3);
  c2->cd(1);
  b0_pass_his->Draw();
  c2->cd(2);
  b0_fail_his->Draw();
  c2->cd(3);
  b1_pass_his->Draw();
  c2->cd(4);
  b1_fail_his->Draw();
  
  // Predicted value (with fit)
  c2->cd(5);
  TF1 pois("pois",poissonf,xmin,xmax,2);
  pois.SetParName(0,"Const");
  pois.SetParName(1,"Mean");
  pois.SetParameter(0,b2_pred_his->GetMaximum());
  pois.SetParameter(1,b2_pred_his->GetMean());
  gStyle->SetOptFit(1111111);
  b2_pred_his->Fit("pois","Q");
  b2_pred_his->Draw();

  // 68% integral
  double denominator = b2_pred_his->Integral();
  b2_pred_his->SetAxisRange(estimate-errl,estimate+errh);
  double numerator = b2_pred_his->Integral();
  b2_pred_his->SetAxisRange(xmin,xmax);
  
  c2->SaveAs(TString("CheckStats"+ss.str()+".png"));
  
  b2_mean = pois.GetParameter(1);
  b2_rms = sqrt(pois.GetParameter(1));
  b2_err = pois.GetParError(1);
  
  dir->cd();
  gStyle = style;
  
  std::cout << " STAT CHECK:"
	    << " sample:\"" << type[ifile] << "\""
	    << " multi: " << multi[imulti]
	    << " aT:" << at[iat]/1000.
	    << " obs: " << observed
	    << "+/-" << sqrt(observed)
	    << " pred: " << estimate
	    << "+" << errh
	    << "-" << errl
	    << " stat: " << b2_mean
	    << "+/-" << b2_rms
	    << " (" << (int(( denominator > 0. ? numerator/denominator : 0. )*1000.))/10. << "%)"
	    << std::endl;
  
}

// -----------------------------------------------------------------------------
// 
double dr( double x, int decimal_places ) {
  if ( decimal_places < 0 ) { return x; }
  if ( x == 0. ) { return 0.; }
  return floor(x*pow(10.,decimal_places)+0.5)/pow(10.,decimal_places); 
}

// -----------------------------------------------------------------------------
// 
double sr( double x, int significant_figures ) {
  if ( significant_figures < 0 ) { return x; }
  if ( x == 0. ) { return 0.; }
  double s = floor(log10(x))-significant_figures+1;
  double f = pow(10.,fabs(s));
//   if ( f == 0. || 1/f == 0. ) {
//     std::cout << " x: " << x
// 	      << " n: " << significant_figures
// 	      << " s: " << s
// 	      << " abs(s): " << abs(s)
// 	      << " pow(10.,abs(s)): " << pow(10.,abs(s)) 
// 	      << std::endl;
//   }
  if (s<0) f = 1/f;
  return int(x/f)*f;
}

// -----------------------------------------------------------------------------
// 
void calcErr( double val, double& errh, double& errl, 
	      double val1, double errh1, double errl1,
	      double val2, double errh2, double errl2,
	      bool print, std::stringstream& ss ) {
  errh = 0.;
  errl = 0.;
  if ( val1 > 0. ) {
    errh = (errh1/val1)*(errh1/val1);
    errl = (errl1/val1)*(errl1/val1);
//    } else {
//      errh = errh1*errh1; 
//      errl = errl1*errl1;
  }
  if ( val2 > 0. ) {
    errh += (errh2/val2)*(errh2/val2);
    errl += (errl2/val2)*(errl2/val2);
//    } else {
//      errh += errh2*errh2;
//      errl += errl2*errl2;
  }
  if ( val > 0 ) {
    errh = val * sqrt(errh);
    errl = val * sqrt(errl);
//    } else {
//      errh = sqrt(errh);
//      errl = sqrt(errl);
  }

//   if ( !( val1 > 0. && val2 > 0. ) ) {
//     errh = 0.;
//     errl = 0.;
//   }

  if ( print ) {
    ss << " out: " << val
       << "+" << errh
       << "-" << errl
       << " (" 
       << dr( (val>0.?errh/val:0.), 2 ) 
       << "," 
       << dr( (val>0.?errl/val:-1.), 2 )
       << ") " 
       << " in1: " << val1
       << "+" << errh1
       << "-" << errl1
       << " (" 
       << dr( (val1>0.?errh1/val1:0.), 2 ) 
       << "," 
       << dr( (val1>0.?errl1/val1:0.), 2 ) 
       << ") " 
       << " in2: " << val2
       << "+" << errh2
       << "-" << errl2
       << " (" 
       << dr( (val2>0.?errh2/val2:0.), 2 )
       << "," 
       << dr( (val2>0.?errl2/val2:0.), 2 )
       << ") ";
  }

}

// -----------------------------------------------------------------------------
// 
void calcErr( double val, double& errh, double& errl, 
	      double val1, double errh1, double errl1,
	      double val2, double errh2, double errl2 ) {
  std::stringstream null;
  calcErr( val, errh, errl, 
	   val1, errh1, errl1,
	   val2, errh2, errl2, 
	   false, null );
}

// -----------------------------------------------------------------------------
//  
TH1D* rebin( TFile* file, const char* name, int multi, double width, double xlow, double xhigh ) {

  // Check for null pointer
  if ( !file ) { 
    std::cout << "Unable to retrieve file!" << std::endl;
    return 0; 
  }
  file->cd();

  // Retreive original histogram
  TH1D* input = 0;
  
  if ( multi == 0 ) {
    std::stringstream tmp; tmp << name << "_all";
    //std::cout << "name: " << tmp.str() << std::endl;
    input = (TH1D*)file->Get( tmp.str().c_str() )->Clone();
  } else if ( multi < 0 ) {
    for ( uint ii = abs(multi); ii < 10; ++ii ) {
      std::stringstream tmp; tmp << name << "_" << ii;
      //std::cout << "name: " << tmp.str() << std::endl;
      if ( int(ii) == abs(multi) ) { input = (TH1D*)file->Get( tmp.str().c_str() )->Clone(); }
      else { input->Add( (TH1D*)file->Get( tmp.str().c_str() ) ); }
    }
  } else {
    std::stringstream tmp; tmp << name << "_" << multi;
    input = (TH1D*)file->Get( tmp.str().c_str() )->Clone();
  }
  
  if ( !input ) { 
    std::cout << "Unable to retrieve histogram with name \"" << name << "\"" << std::endl;
    return 0; 
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
  
  // Rebin original histogram
  input->Rebin( int(width/(input->GetBinWidth(1))) );
  
  // Create new rebinned histogram
  TH1D* output = new TH1D( TString(input->GetName())+"_Rebinned", "", int((xhigh+width-xlow)/width), xlow, xhigh+width );
  
  // Populate new histogram
  for ( int bin = 1; bin <= input->GetNbinsX(); ++bin ) {
    Double_t centre = input->GetBinLowEdge(bin) + input->GetBinWidth(bin)/2.;
    output->Fill( centre, input->GetBinContent(bin) );
  }
  // Modify last HT bin to be inclusive
  if ( true ) { 
    Double_t centre = output->GetBinLowEdge(output->GetNbinsX()) + output->GetBinWidth(output->GetNbinsX())/2.;
    output->Fill( centre, input->GetBinContent(output->GetNbinsX()+1) );
  }
  
  output->Sumw2();
  
  if (true) {
    if ( input ) {
      TH1D* his = input;
      std::stringstream ss;
      ss << "REBINNED HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
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

// // -----------------------------------------------------------------------------
// //  
// TH1D* rebinNew( TFile* file, const char* name, int multi, int nbins = -1, double xlow = -1., double xhigh = -1. ) {

//   bool debug = true;

//   // Check for null pointer
//   if ( file ) { 
//     //std::cout << "Opened file with name \"" << file->GetName() << "\"" << std::endl;
//   } else {
//     std::cout << "Unable to retrieve file!" << std::endl;
//     return 0; 
//   }
//   file->cd();

//   // Retreive original histogram
//   TH1D* input = 0;
  
//   if ( multi == 0 ) {
//     std::stringstream tmp; tmp << name << "_all";
//     input = (TH1D*)file->Get( tmp.str().c_str() )->Clone();
//   } else if ( multi < 0 ) {
//     for ( uint ii = abs(multi); ii < 9; ++ii ) {
//       std::stringstream tmp; tmp << name << "_" << ii;
//       if ( int(ii) == abs(multi) ) { input = (TH1D*)file->Get( tmp.str().c_str() )->Clone(); }
//       else { input->Add( (TH1D*)file->Get( tmp.str().c_str() ) ); }
//     }
//   } else {
//     std::stringstream tmp; tmp << name << "_" << multi;
//     input = (TH1D*)file->Get( tmp.str().c_str() )->Clone();
//   }
  
//   if ( input ) { 
//     //std::cout << "Retrieved histogram with name \"" << input->GetName() << "\"" << std::endl;
//   } else {
//     std::cout << "Unable to retrieve histogram with name \"" << name << "\"" << std::endl;
//     return 0; 
//   }

//   if (debug) {
//     if ( input ) {
//       TH1D* his = input;
//       std::stringstream ss;
//       ss << "INPUT HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
// 	 << std::endl
// 	 << " underflow: " << his->GetBinContent(0)
// 	 << std::endl
// 	 << " underflow_err: " << his->GetBinError(0)
// 	 << std::endl
// 	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
// 	 << std::endl
// 	 << " overflow_err: " << his->GetBinError(his->GetNbinsX()+1)
// 	 << std::endl
// 	 << " entries: " << his->GetEntries()
// 	 << std::endl
// 	 << " integral: " << his->Integral()
// 	 << std::endl
// 	 << " all: " << his->Integral() + his->GetBinContent(0) + his->GetBinContent(his->GetNbinsX()+1)
// 	 << std::endl;
//       for ( int bin = 1; bin <= his->GetNbinsX(); ++bin ) {
// 	ss << " bin: " << bin
// 	   << " val: " << his->GetBinContent(bin)
// 	   << " err: " << his->GetBinError(bin)
// 	   << std::endl;
//       }
//       std::cout << ss.str();
//     }
//   }
  
//   // Rebin original histogram
//   if (debug) std::cout << " INPUT: " << input->GetName()
// 		       << " Nbins: " << input->GetXaxis()->GetNbins()
// 		       << " Xmin: " << input->GetXaxis()->GetXmin()
// 		       << " Xmax: " << input->GetXaxis()->GetXmax()
// 		       << std::endl;
//   if ( nbins > 0. ) { input->Rebin( int(input->GetXaxis()->GetNbins()/nbins) ); }
//   if (debug) std::cout << " REBINNED: " << input->GetName()
// 		       << " Nbins: " << input->GetXaxis()->GetNbins()
// 		       << " Xmin: " << input->GetXaxis()->GetXmin()
// 		       << " Xmax: " << input->GetXaxis()->GetXmax()
// 		       << std::endl;
  
//   // Create temp histogram
//   TH1D* temp = 0;
//   if ( nbins > 1 ) { 
//     int bins = nbins - 1;
//     double xmin = xlow;
//     double xmax = xhigh;
//     double width = ( xmax - xmin ) / ( bins * 1. );
//     xmax -= width;
//     temp = new TH1D( TString(input->GetName())+"_Temp", "", 
// 		     bins, 
// 		     xmin, 
// 		     xmax );
//     if (debug) std::cout << " TEMP: " << temp->GetName()
// 			 << " Nbins: " << temp->GetXaxis()->GetNbins()
// 			 << " Xmin: " << temp->GetXaxis()->GetXmin()
// 			 << " Xmax: " << temp->GetXaxis()->GetXmax()
// 			 << std::endl;
//   } else {
//     int bins = temp->GetXaxis()->GetNbins() - 1;
//     double xmin = temp->GetXaxis()->GetXmin();
//     double xmax = temp->GetXaxis()->GetXmax();
//     double width = ( xmax - xmin ) / ( bins * 1. );
//     xmax -= width;
//     temp = new TH1D( TString(input->GetName())+"_Temp", "", 
// 		     bins, 
// 		     xmin, 
// 		     xmax );
//     if (debug) std::cout << " TEMP: " << temp->GetName()
// 			 << " Nbins: " << temp->GetXaxis()->GetNbins()
// 			 << " Xmin: " << temp->GetXaxis()->GetXmin()
// 			 << " Xmax: " << temp->GetXaxis()->GetXmax()
// 			 << std::endl;
//   }
//   temp->Sumw2();
  
//   // Populate temp histogram
//   for ( int bin = 1; bin <= temp->GetNbinsX(); ++bin ) {
//     Double_t centre = temp->GetBinLowEdge(bin) + temp->GetBinWidth(bin)/2.;
//     int find_bin = input->FindBin(centre);
//     temp->SetBinContent( bin, input->GetBinContent( find_bin ) );
//     temp->SetBinError( bin, input->GetBinError( find_bin ) );
//   }
//   temp->SetBinContent( bin, input->GetBinContent( input->GetXaxis()->GetNbins()+1 ) );
//   temp->SetBinError( bin, input->GetBinError( input->GetXaxis()->GetNbins()+1 ) );
//   temp->SetEntries( input->GetEntries() );

//   // Create new rebinned histogram
//   TH1D* output = 0;
//   if ( nbins > 0 ) { 
//     output = new TH1D( TString(input->GetName())+"_Output", "", 
// 		       nbins, 
// 		       xlow, 
// 		       xhigh );
//     if (debug) std::cout << " OUTPUT: " << output->GetName()
// 			 << " Nbins: " << output->GetXaxis()->GetNbins()
// 			 << " Xmin: " << output->GetXaxis()->GetXmin()
// 			 << " Xmax: " << output->GetXaxis()->GetXmax()
// 			 << std::endl;
//   } else {
//     output = new TH1D( TString(input->GetName())+"_Output", "", 
// 		       input->GetXaxis()->GetNbins(), 
// 		       input->GetXaxis()->GetXmin(), 
// 		       input->GetXaxis()->GetXmax() );
//     if (debug) std::cout << " OUTPUT: " << output->GetName()
// 			 << " Nbins: " << output->GetXaxis()->GetNbins()
// 			 << " Xmin: " << output->GetXaxis()->GetXmin()
// 			 << " Xmax: " << output->GetXaxis()->GetXmax()
// 			 << std::endl;
//   }
//   output->Sumw2();

//   // Populate new histogram
//   for ( int bin = 1; bin <= output->GetNbinsX(); ++bin ) {
//     Double_t centre = output->GetBinLowEdge(bin) + output->GetBinWidth(bin)/2.;
//     int find_bin = temp->FindBin(centre);
//     output->SetBinContent( bin, temp->GetBinContent( find_bin ) );
//     output->SetBinError( bin, temp->GetBinError( find_bin ) );
//   }
//   output->SetEntries( temp->GetEntries() );

//   if (debug) {
//     if ( temp ) {
//       TH1D* his = temp;
//       std::stringstream ss;
//       ss << "TEMP HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
// 	 << std::endl
// 	 << " underflow: " << his->GetBinContent(0)
// 	 << std::endl
// 	 << " underflow_err: " << his->GetBinError(0)
// 	 << std::endl
// 	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
// 	 << std::endl
// 	 << " overflow_err: " << his->GetBinError(his->GetNbinsX()+1)
// 	 << std::endl
// 	 << " entries: " << his->GetEntries()
// 	 << std::endl
// 	 << " integral: " << his->Integral()
// 	 << std::endl
// 	 << " all: " << his->Integral() + his->GetBinContent(0) + his->GetBinContent(his->GetNbinsX()+1)
// 	 << std::endl;
//       for ( int bin = 1; bin <= his->GetNbinsX(); ++bin ) {
// 	ss << " bin: " << bin
// 	   << " val: " << his->GetBinContent(bin)
// 	   << " err: " << his->GetBinError(bin)
// 	   << std::endl;
//       }
//       std::cout << ss.str();
//     }
//   }
  
// //   // Modify last bin to be inclusive
// //   if ( true ) { 
// //     // Define value of centre of last bin of output histo
// //     Double_t centre = output->GetBinLowEdge(output->GetNbinsX()) + output->GetBinWidth(output->GetNbinsX())/2.;
// //     // Add to the last bin of output histo with overflow from output histo
// //     output->SetBinContent( output->GetNbinsX(), 
// // 			   output->GetBinContent(output->GetNbinsX()) +
// // 			   output->GetBinContent(output->GetNbinsX()+1) );
// //     output->SetBinError( output->GetNbinsX(), 
// // 			 sqrt(output->GetBinError(output->GetNbinsX()) *
// // 			      output->GetBinError(output->GetNbinsX()) +
// // 			      output->GetBinError(output->GetNbinsX()+1) *
// // 			      output->GetBinError(output->GetNbinsX()+1)) );
// //     // Add to the last bin of output histo with overflow from input histo
// //     output->SetBinContent( output->GetNbinsX(), 
// // 			   output->GetBinContent(output->GetNbinsX()) +
// // 			   input->GetBinContent(output->GetNbinsX()+1) );
// //     output->SetBinError( output->GetNbinsX(), 
// // 			 sqrt(output->GetBinError(output->GetNbinsX()) *
// // 			      output->GetBinError(output->GetNbinsX()) +
// // 			      output->GetBinError(input->GetNbinsX()+1) *
// // 			      output->GetBinError(input->GetNbinsX()+1)) );
// //   }
  
//   if (debug) {
//     if ( output ) {
//       TH1D* his = output;
//       std::stringstream ss;
//       ss << "OUTPUT HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
// 	 << std::endl
// 	 << " underflow: " << his->GetBinContent(0)
// 	 << std::endl
// 	 << " underflow_err: " << his->GetBinError(0)
// 	 << std::endl
// 	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
// 	 << std::endl
// 	 << " overflow_err: " << his->GetBinError(his->GetNbinsX()+1)
// 	 << std::endl
// 	 << " entries: " << his->GetEntries()
// 	 << std::endl
// 	 << " integral: " << his->Integral()
// 	 << std::endl
// 	 << " all: " << his->Integral() + his->GetBinContent(0) + his->GetBinContent(his->GetNbinsX()+1)
// 	 << std::endl;
//       for ( int bin = 1; bin <= his->GetNbinsX(); ++bin ) {
// 	ss << " bin: " << bin
// 	   << " val: " << his->GetBinContent(bin)
// 	   << " err: " << his->GetBinError(bin)
// 	   << std::endl;
//       }
//       std::cout << ss.str();
//     }
//   }

//   if (temp) { delete temp; }
//   return output;

// }

// -----------------------------------------------------------------------------
//  
//TH1D* rebinNew( TFile* file, const char* name, int multi, int nbins = -1, double xlow = -1., double xhigh = -1. ) {
TH1D* rebinNew( TFile* file, TString name, int multi, int nbins = -1, double* xarray = 0 ) {

  bool debug = false;

  // Check for null pointer
  if ( file ) { 
    //std::cout << "Opened file with name \"" << file->GetName() << "\"" << std::endl;
  } else {
    std::cout << "Unable to retrieve file!" << std::endl;
    return 0; 
  }
  file->cd();

  // Retreive original histogram
  TH1D* input = 0;
  
  if ( multi == 0 ) {
    std::stringstream tmp; tmp << name << "_all";
    TH1D* temp = (TH1D*)file->Get( tmp.str().c_str() );
    if (temp) { input = (TH1D*)temp->Clone(); } 
    //else { std::cout << "Unable to retrieve histo with name " << tmp.str() << std::endl; }
  } else if ( multi < 0 ) {
    for ( uint ii = abs(multi); ii <= 20; ++ii ) {
      std::stringstream tmp; tmp << name << "_" << ii;
      if ( int(ii) == abs(multi) ) { 
	TH1D* temp = (TH1D*)file->Get( tmp.str().c_str() );
	if (temp) { input = (TH1D*)temp->Clone(); } 
	//else { std::cout << "Unable to retrieve histo with name " << tmp.str() << std::endl; }
      }
      else { 
	TH1D* temp = (TH1D*)file->Get( tmp.str().c_str() );
	if (temp) { input->Add( (TH1D*)temp ); } 
	//else { std::cout << "Unable to retrieve histo with name " << tmp.str() << std::endl; }
      }
    }
  } else {
    std::stringstream tmp; tmp << name << "_" << multi;
    TH1D* temp = (TH1D*)file->Get( tmp.str().c_str() );
    if (temp) { input = (TH1D*)temp->Clone(); } 
    //else { std::cout << "Unable to retrieve histo with name " << tmp.str() << std::endl; }
  }
  
  if ( input ) { 
    //std::cout << "Retrieved histogram with name \"" << input->GetName() << "\"" << std::endl;
  } else {
    //std::cout << "Unable to retrieve histogram with name \"" << name << "\"" << std::endl;
    return 0; 
  }

  if (debug) {
    if ( input ) {
      TH1D* his = input;
      std::stringstream ss;
      ss << "INPUT HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
	 << std::endl
	 << " underflow: " << his->GetBinContent(0)
	 << std::endl
	 << " underflow_err: " << his->GetBinError(0)
	 << std::endl
	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl
	 << " overflow_err: " << his->GetBinError(his->GetNbinsX()+1)
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
  
  // Rebin original histogram
//   std::cout << " INPUT: Nbins: " << input->GetXaxis()->GetNbins()
// 	    << " Xmin: " << input->GetXaxis()->GetXmin()
// 	    << " Xmax: " << input->GetXaxis()->GetXmax()
// 	    << std::endl;
//   if ( nbins > 0. ) {
//     input->Rebin( int(input->GetXaxis()->GetNbins()/nbins) );
//   }
//   std::cout << " INPUT: Nbins: " << input->GetXaxis()->GetNbins()
// 	    << " Xmin: " << input->GetXaxis()->GetXmin()
// 	    << " Xmax: " << input->GetXaxis()->GetXmax()
// 	    << std::endl;

  if (debug) {
    if ( input ) {
      TH1D* his = input;
      std::stringstream ss;
      ss << "REBINNED HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
	 << std::endl
	 << " underflow: " << his->GetBinContent(0)
	 << std::endl
	 << " underflow_err: " << his->GetBinError(0)
	 << std::endl
	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl
	 << " overflow_err: " << his->GetBinError(his->GetNbinsX()+1)
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
  
  // Create new rebinned histogram
  TH1D* output = 0;
//   if ( nbins > 0. ) { 
//     output = new TH1D( TString(input->GetName())+"_Rebinned", "", 
// 		       nbins, 
// 		       xlow, 
// 		       xhigh );
// //     std::cout << " OUTPUT: Nbins: " << output->GetXaxis()->GetNbins()
// // 	      << " Xmin: " << output->GetXaxis()->GetXmin()
// // 	      << " Xmax: " << output->GetXaxis()->GetXmax()
// // 	      << std::endl;
//   } else {
//     output = new TH1D( TString(input->GetName())+"_Rebinned", "", 
// 		       input->GetXaxis()->GetNbins(), 
// 		       input->GetXaxis()->GetXmin(), 
// 		       input->GetXaxis()->GetXmax() );
// //     std::cout << " OUTPUT: Nbins: " << output->GetXaxis()->GetNbins()
// // 	      << " Xmin: " << output->GetXaxis()->GetXmin()
// // 	      << " Xmax: " << output->GetXaxis()->GetXmax()
// // 	      << std::endl;
//   }
//   if (output) output->Sumw2();

  // Populate new histogram
  if (!output) output = input;
  for ( int bin = 1; bin <= output->GetNbinsX(); ++bin ) {
    Double_t centre = output->GetBinLowEdge(bin) + output->GetBinWidth(bin)/2.;
    int find_bin = input->FindBin(centre);
    output->SetBinContent( bin, input->GetBinContent( find_bin ) );
    output->SetBinError( bin, input->GetBinError( find_bin ) );
  }
  output->SetEntries( input->GetEntries() );
  
  // Modify last bin to be inclusive
  if ( true ) { 
    // Add to the last bin of output histo with overflow from output histo
//      std::cout << " content: " << output->GetBinContent( output->GetNbinsX() )
//  	      << " error: " << output->GetBinError( output->GetNbinsX() )  
//  	      << std::endl;
    output->SetBinContent( output->GetNbinsX(), 
			   output->GetBinContent(output->GetNbinsX()) +
			   output->GetBinContent(output->GetNbinsX()+1) );
    output->SetBinError( output->GetNbinsX(), 
			 sqrt(output->GetBinError(output->GetNbinsX()) *
			      output->GetBinError(output->GetNbinsX()) +
			      output->GetBinError(output->GetNbinsX()+1) *
			      output->GetBinError(output->GetNbinsX()+1)) );
    output->SetBinContent( output->GetNbinsX()+1, 0. );
    output->SetBinError( output->GetNbinsX()+1, 0. );
//      std::cout << " content: " << output->GetBinContent( output->GetNbinsX() )
//  	      << " error: " << output->GetBinError( output->GetNbinsX() )  
//  	      << std::endl;
//     // Add to the last bin of output histo with overflow from input histo
//     output->SetBinContent( output->GetNbinsX(), 
// 			   output->GetBinContent(output->GetNbinsX()) +
// 			   input->GetBinContent(input->GetNbinsX()+1) );
//     output->SetBinError( output->GetNbinsX(), 
// 			 sqrt(output->GetBinError(output->GetNbinsX()) *
// 			      output->GetBinError(output->GetNbinsX()) +
// 			      input->GetBinError(input->GetNbinsX()+1) *
// 			      input->GetBinError(input->GetNbinsX()+1)) );
//      std::cout << " content: " << output->GetBinContent( output->GetNbinsX() )
// 	       << " error: " << output->GetBinError( output->GetNbinsX() )  
//  	      << std::endl;
  }
  
  if (debug) {
    if ( output ) {
      TH1D* his = output;
      std::stringstream ss;
      ss << "OUTPUT HISTO: " << file->GetName() << "/" << name << " multi: " << (multi<0?">=":"==") << abs(multi) 
	 << std::endl
	 << " underflow: " << his->GetBinContent(0)
	 << std::endl
	 << " underflow_err: " << his->GetBinError(0)
	 << std::endl
	 << " overflow: " << his->GetBinContent(his->GetNbinsX()+1)
	 << std::endl
	 << " overflow_err: " << his->GetBinError(his->GetNbinsX()+1)
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
/*
 */  
TH1D* integral( TH1D* input ) {
  
  // Check input
  if ( !input ) { return 0; }

  // Create clone
  TString cname( TString( input->GetName() ) + "_Integral" );
  TH1D* output = new TH1D( cname, "", 
			   input->GetNbinsX(), 
			   input->GetXaxis()->GetXmin(), 
			   input->GetXaxis()->GetXmin() );
  
  // Integral
  double total = 0.;
  
  // Overflow
  total += input->GetBinContent( input->GetNbinsX() );
  
  // Loop through histo bins
  for ( int bin = 1; bin < input->GetNbinsX()+1; ++bin ) {
    Double_t centre = input->GetBinLowEdge(bin) + input->GetBinWidth(bin)/2.;
    total += input->GetBinContent( bin );
    output->Fill( centre, total );
  }
  output->Sumw2();

  std::cout << "total: " << total 
	    << " integral: " << input->Integral()
	    << " integral: " << output->Integral()
	    << std::endl;

  return output;
}

// -----------------------------------------------------------------------------
// 
void calcRatio( const uint nfile, 
		const uint nmulti, 
		const uint nat, 
		const uint npt, 
		const uint nht, 
 		std::vector<std::string> his, 
 		std::vector<std::string> files,
 		std::vector<double> lumis,
 		std::vector<double> weights,
 		std::vector<int> multi, 
 		std::vector<int> at, 
 		std::vector<double> pt, 
 		std::vector<double> ht, 
 		double ht_min, 
 		double ht_max,
 		double ht_step,
 		double numer[][nmulti][nat][npt][nht], 
 		double numer_err[][nmulti][nat][npt][nht], 
 		double denom[][nmulti][nat][npt][nht], 
 		double denom_err[][nmulti][nat][npt][nht], 
 		double ratio[][nmulti][nat][npt][nht], 
 		double errh[][nmulti][nat][npt][nht], 
 		double errl[][nmulti][nat][npt][nht], 
 		int length[][nmulti][nat][npt],
 		int data_file,
 		double lumi,
		bool efficiency = false
		) {
  calcRatio( nfile, nmulti, nat, npt, nht, 
	     his, files, lumis, weights, multi, at, pt, ht, 
	     (int)nht, ht_min, ht_max, 
	     //int((ht_max-ht_min)/ht_step), ht_min, ht_max, 
	     numer, numer_err, denom, denom_err, ratio, errh, errl, length, 
	     data_file, lumi,
	     efficiency );
}

// -----------------------------------------------------------------------------
// 
void calcRatio( const uint nfile, 
		const uint nmulti, 
		const uint nat, 
		const uint npt, 
		const uint nht, 
 		std::vector<std::string> his, 
 		std::vector<std::string> files,
 		std::vector<double> lumis,
 		std::vector<double> weights,
 		std::vector<int> multi, 
 		std::vector<int> at, 
 		std::vector<double> pt, 
 		std::vector<double> ht, 
 		int    ht_nbin,
 		double ht_min, 
 		double ht_max,
 		double numer[][nmulti][nat][npt][nht], 
 		double numer_err[][nmulti][nat][npt][nht], 
 		double denom[][nmulti][nat][npt][nht], 
 		double denom_err[][nmulti][nat][npt][nht], 
 		double ratio[][nmulti][nat][npt][nht], 
 		double errh[][nmulti][nat][npt][nht], 
 		double errl[][nmulti][nat][npt][nht], 
 		int length[][nmulti][nat][npt],
 		int data_file,
 		double lumi,
		bool efficiency = false
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
      
	// Loop through bins of pT
	for ( uint ipt = 0; ipt < npt; ++ipt ) {
	
	  //std::cout << ifile << " " << imulti << " " << iat << " " << ipt << std::endl;
	  length[ifile][imulti][iat][ipt] = 0;

	  // Directory and histo names
	  std::stringstream dir;
	  std::stringstream name;
	  std::stringstream pre;
	  std::stringstream post;
	  dir << "QcdBkgdEst/";
	  name << his[ifile] << "_aT"; 
	  pre << dir.str() << name.str() << "0";
	  post << dir.str() << name.str() << at[iat]/1000.;
	  //std::cout << "dir: " << dir.str() << std::endl;
	  //std::cout << "name: " << name.str() << std::endl;
	  //std::cout << "pre: " << pre.str() << std::endl;
	  //std::cout << "post: " << post.str() << std::endl;
	
	  // Create ratio histo
	  //TH1D* above = rebinNew( file, post.str().c_str(), multi[imulti], ht_nbin, ht_min, ht_max );
	  //TH1D* below = rebinNew( file, pre.str().c_str(), multi[imulti], ht_nbin, ht_min, ht_max );
	  TH1D* above = rebinNew( file, TString(post.str()), multi[imulti] );
	  TH1D* below = rebinNew( file, TString(pre.str()), multi[imulti] );
	  TH1D* divide = 0;
	  //TGraphAsymmErrors* errors = 0;
	  
	  file->cd();
	  //numerator = rebinNew( file, post.str().c_str(), multi[imulti], ht_nbin, ht_min, ht_max );
 	  //denominator = rebinNew( file, pre.str().c_str(), multi[imulti], ht_nbin, ht_min, ht_max );
	  
	  if ( above && below ) {
	    //if ( numerator && denominator ) {
	    
	    above->Scale(lumis[ifile]/100.);
	    below->Scale(lumis[ifile]/100.);
	    //numerator->Scale(lumis[ifile]/100.);
	    //denominator->Scale(lumis[ifile]/100.);
	    //numerator->Scale(weights[ifile]);

	    //above = (TH1D*)numerator->Clone(TString(numerator->GetName())+"_Clone");
	    //below = (TH1D*)denominator->Clone(TString(denominator->GetName())+"_Clone");
	    //divide = (TH1D*)below->Clone(TString(above->GetName())+"_AnotherClone");
	    divide = new TH1D(*above);
// 	    divide = new TH1D( TString(above->GetName())+"_Clone", 
// 			       TString(above->GetName())+"_Clone",
// 			       above->GetXaxis()->GetXbins(), 
// 			       above->GetXaxis()->GetXmin(), 
// 			       above->GetXaxis()->GetXmax() );
	  
	    if ( above && below ) { 
	      if ( efficiency == false ) { below->Add(above,-1.); }

	      if ( false ) { 
		std::cout << " CONTENTS: file: " << files[ifile] 
			  << " multi: " << multi[imulti]
			  << " aT:" << at[iat]
			  << "  HT:" << ht[ipt]
			  << " n: " 
			  << above->GetBinContent(ipt+1) 
			  << " ne: " 
			  << above->GetBinError(ipt+1) 
			  << " d: " 
			  << below->GetBinContent(ipt+1) 
			  << " de: " 
			  << below->GetBinError(ipt+1) 
			  << std::endl;
	      }

	      divide->Divide(above,below);
	      //errors = new TGraphAsymmErrors(above,below);
	    }
	  }
	  
	  // Loop through bins of HT
	  if ( above && below && divide /*&& errors*/ ) {
	    for ( uint iht = 0; iht < nht; ++iht ) {

	      double a  = above->GetBinContent(iht+1);
	      double ae = above->GetBinError(iht+1);
	      double b  = below->GetBinContent(iht+1);
	      double be = below->GetBinError(iht+1);
	      double r  = divide->GetBinContent(iht+1);
	      double rerrl = 0.;
	      double rerrh = 0.;
	      calcErr( r, rerrh, rerrl, a, ae, ae, b, be, be );
	      
	      numer[ifile][imulti][iat][ipt][iht] = a;
	      numer_err[ifile][imulti][iat][ipt][iht] = ae;
	      denom[ifile][imulti][iat][ipt][iht] = b;
	      denom_err[ifile][imulti][iat][ipt][iht] = be; 
	      ratio[ifile][imulti][iat][ipt][iht] = r;
	      if ( r > 0. ) { length[ifile][imulti][iat][ipt]++; }
	      errh[ifile][imulti][iat][ipt][iht] = rerrh;
	      errl[ifile][imulti][iat][ipt][iht] = rerrl;

//  	      std::cout << " ERRORS: file: " << ifile 
//  			<< " multi: " << multi[imulti]
//  			<< " aT:" << at[iat]
//  			<< " pT:" << pt[ipt]
//  			<< " HT:" << ht[iht]
//  			<< " a: " << a
//  			<< " ae: " << ae
//  			<< " b: " << b
//  			<< " be: " << be
//  			<< " r: " << r
//  			<< " rerrh: " << rerrh
//  			<< " rerrl: " << rerrl
//  			<< std::endl;
	      
 	      if ( ratio[ifile][imulti][iat][ipt][iht] == 0. ) { 
		if ( iht > 0 ) { a = above->GetBinContent(1); ae = above->GetBinError(1); }
		else           { a = above->GetBinContent(nht); ae = above->GetBinError(nht); }
 		errl[ifile][imulti][iat][ipt][iht] = 0.;
		errh[ifile][imulti][iat][ipt][iht] = 0.;//1.148 * (a>0.?(ae*ae)/(a*b):0.); //@@
 	      }
	      
	      //@@
//  	      if ( true &&
// 		   ifile == 2 && 
// 		   multi[imulti] == -3 &&
// 		   at[iat] == 550 &&
//  		   ht[iht] == 390. ) {
//   	      if ( true &&
//   		   ht[iht] == 875. ) {
// 		double e1 = ae;//errh[ifile][imulti][iat][ipt][iht] / ratio[ifile][imulti][iat][ipt][iht];
// 		double e2 = 0.;
// 		e2 += (320./320.)*1.148 * (320./320.)*1.148; // W
// 		e2 += (320./352.)*1.148 * (320./352.)*1.148; // Z
// 		e2 += e1*e1;
// 		e2 = sqrt(e2);
//  		std::cout << " GET HERE1 ERR " << errh[ifile][imulti][iat][ipt][iht] << std::endl;
// 		errh[ifile][imulti][iat][ipt][iht] = (e2/a) * ratio[ifile][imulti][iat][ipt][iht];
// 		errl[ifile][imulti][iat][ipt][iht] = (e2/a) * ratio[ifile][imulti][iat][ipt][iht];
//  		std::cout << " GET HERE2 " << e1 << " " << e2 << std::endl;
//  		std::cout << " GET HERE3 ERR " << errh[ifile][imulti][iat][ipt][iht] << std::endl;
// 	      }
	      
//  	      if ( errl[ifile][imulti][iat][ipt][iht] <= 1.e-100 ) { 
//  		errl[ifile][imulti][iat][ipt][iht] = ratio[ifile][imulti][iat][ipt][iht]; 
//  	      }
//  	      if ( errh[ifile][imulti][iat][ipt][iht] <= 1.e-100 ) { 
//  		errh[ifile][imulti][iat][ipt][iht] = 1.-ratio[ifile][imulti][iat][ipt][iht]; 
//  	      }
	      
//   	      // Account for MC weights when null QCD entries found
//   	      if ( (int)ifile != data_file ) { 
//   		if ( numer[ifile][imulti][iat][ipt][iht] == 0. ) {
//   		  errl[ifile][imulti][iat][ipt][iht] = 0.;
//   		  double upper = 1.148 * lumis[ifile] / ( 100. / weights[iht] );
//   		  double lower = denom[ifile][imulti][iat][ipt][iht];
//   		  errh[ifile][imulti][iat][ipt][iht] = lower > 0. ? upper / lower : 0.;
//   		}
//   	      }
	      
	    } 
	  }

	  //if (numerator) { delete numerator; }
	  //if (denominator) { delete denominator; }
	  if (above) { delete above; }
	  if (below) { delete below; }
	  if (divide) { delete divide; }
	  //if (errors) { delete errors; }
	  
	} // Loop through pT bins
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
	       << " n: " << numer[ifile][imulti][iat][iht][iht]
	       << " n_err: " << numer_err[ifile][imulti][iat][iht][iht]
	       << " d: " << denom[ifile][imulti][iat][iht][iht]
	       << " d_err: " << denom_err[ifile][imulti][iat][iht][iht]
	       << " r: " << ratio[ifile][imulti][iat][iht][iht]
	       << " eh: " << errh[ifile][imulti][iat][iht][iht]
	       << " el: " << errl[ifile][imulti][iat][iht][iht];
	    if ( ratio[ifile][imulti][iat][iht][iht] <= 0. ) { ss << " (0,0)"; }
	    else { 
	      ss << " (" 
		 << dr((errh[ifile][imulti][iat][iht][iht]/ratio[ifile][imulti][iat][iht][iht]),2) 
		 << ","
		 << dr((errl[ifile][imulti][iat][iht][iht]/ratio[ifile][imulti][iat][iht][iht]),2)
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
