#include "style.C"
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

bool trigger_effs = false;

// -----------------------------------------------------------------------------

typedef unsigned int uint;

typedef std::vector<std::string> StringV;
typedef std::vector<StringV> StringVV;

typedef std::vector<double> DoubleV;
typedef std::vector<DoubleV> DoubleVV;
typedef std::vector<DoubleVV> DoubleVVV;
typedef std::vector<DoubleVVV> DoubleVVVV;

typedef std::vector<int> IntV;
typedef std::vector<IntV> IntVV;
typedef std::vector<IntVV> IntVVV;

void resize( DoubleVVVV& v, int nfile, int nmulti, int nat, int nht ) {
  v.clear();
  v.resize( nfile, DoubleVVV( nmulti, DoubleVV( nat, DoubleV( nht, 0. ) ) ) );
}

void resize( IntVVV& v, int nfile, int nmulti, int nat ) {
  v.clear();
  v.resize( nfile, IntVV( nmulti, IntV( nat, 0 ) ) );
}

// -----------------------------------------------------------------------------
// Poisson errors for n<20
void poissonErr( double x, double& errh, double& errl ) {

  // from http://www.slac.stanford.edu/BFROOT/www/Statistics/Report/report.pdf
  
  double poisson_eh[11] = { 1.15, 1.36, 1.53, 1.73, 1.98, 2.21, 2.42, 2.61, 2.80, 3.00, 3.16 };
  double poisson_el[11] = { 0.00, 1.00, 2.00, 2.14, 2.30, 2.49, 2.68, 2.86, 3.03, 3.19, 3.16 };
  if ( x < 10. ) {
    // Poisson errors
    int n = int(x);
    double f = x - double(int(x));
    errh = poisson_eh[n] + f*( poisson_eh[n+1] - poisson_eh[n] );
    errl = poisson_el[n] + f*( poisson_el[n+1] - poisson_el[n] );
//     std::cout << std::fixed
// 	      << std::setprecision(2)
// 	      << " x: " << x
// 	      << " n: " << n
// 	      << " f: " << f
// 	      << " poisson_eh[n]: " << poisson_eh[n]
// 	      << " poisson_eh[n+1]: " << poisson_eh[n+1]
// 	      << " errh: " << errh
// 	      << " poisson_el[n]: " << poisson_el[n]
// 	      << " poisson_el[n+1]: " << poisson_el[n+1]
// 	      << " errl: " << errl
// 	      << std::endl;
  } else {
    // Normal approximation
    errh = -1.;//sqrt(x);
    errl = -1.;//sqrt(x);
  }

}

double poissonErrH( double x, double e ) {
  double errh = 0., errl = 0.;
  poissonErr(x,errh,errl);
  return errh<-1.e-6?e:errh;
}

double poissonErrL( double x, double e ) {
  double errh = 0., errl = 0.;
  poissonErr(x,errh,errl);
  return errl<-1.e-6?e:errl;
}

// -----------------------------------------------------------------------------
//  
void qcd( const std::vector<float>& at, const std::vector<float>& pval ) {
  
  if ( at.empty() || pval.empty() || at.size() != pval.size() ) { return; }
  
  setTDRStyle();
  
  TCanvas* c1 = new TCanvas("pValueVersusAlphaT","");
  c1->SetFillColor(0);
  c1->SetLineColor(0); 
  
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
  }
    
  c1->cd();
  mg->Draw("al");
  mg->GetXaxis()->SetTitle("#alpha_{T} cut value");
  mg->GetYaxis()->SetTitle("p-value");
  mg->GetXaxis()->SetRangeUser(0.5,0.6);
  mg->GetYaxis()->SetRangeUser(0.,1.);

  TLatex* prelim = new TLatex( 0.18, 0.88, "#scale[0.8]{CMS preliminary 2011}" );
  prelim->SetTextSize(0.035);
  prelim->SetNDC();
  prelim->Draw("same");
  std::stringstream ssl; ssl << "#scale[0.8]{#int L dt = 769 pb^{-1}, #sqrt{s} = 7 TeV}";
  TLatex* lumitxt = new TLatex( 0.58, 0.88, ssl.str().c_str() );
  lumitxt->SetTextSize(0.035);
  lumitxt->SetNDC();
  lumitxt->Draw("same");

  c1->Update();
  c1->SaveAs(TString("pValueVersusAlphaT.pdf")); 
  c1->SaveAs(TString("pValueVersusAlphaT.C")); 
  
}

// -----------------------------------------------------------------------------
//  
void eff( const DoubleVVVV& num, const std::string& str ) {
  
  setTDRStyle();
  
  TCanvas* c = new TCanvas(TString(str),"");
  c->SetFillColor(0);
  c->SetLineColor(0); 
  c->SetLeftMargin(0.15);
  
  TLegend* legend = new TLegend( 0.20, 0.3, 0.40, 0.4, NULL, "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0); 
  legend->SetShadowColor(0);

  std::vector<std::string> name;
  name.push_back("Data");
  name.push_back("SM");

  std::vector<double> ht;
  ht.push_back(300.);
  ht.push_back(350.);
  for ( uint ii = 0; ii < 6; ++ii ) { ht.push_back(425.+ii*100.);  }
  std::vector<double> w(2,25.);
  w.resize(8,50.);
  
  TMultiGraph* mg = new TMultiGraph();

  std::vector< std::vector<double> > eff(2,std::vector<double>(num[0][0][0].size(),0.));
  std::vector< std::vector<double> > err(2,std::vector<double>(num[0][0][0].size(),0.));
  
  for ( uint ii = 0; ii < 2; ++ii ) {

    DoubleV pass(num[2*ii+0][0][0]);
    DoubleV total(num[2*ii+1][0][0]);
    
    for ( uint iii = 0; iii < num[0][0][0].size(); ++iii ) {
      eff[ii][iii] = total[iii] > 0. ? pass[iii]/total[iii] : 0.;
      err[ii][iii] = total[iii] > 0. ? sqrt( (eff[ii][iii]*(1.-eff[ii][iii])) / total[iii] ) : 0.;
    }
    
    TGraphAsymmErrors* gr = new TGraphAsymmErrors(num[0][0][0].size(),
						  &ht.front(),
						  &eff[ii].front(),
						  &w.front(),
						  &w.front(),
						  &err[ii].front(),
						  &err[ii].front());
    
    mg->Add(gr,"p");
    gr->SetLineColor(1+ii);
    gr->SetMarkerColor(1+ii);
    gr->SetMarkerStyle(20+ii);
    legend->AddEntry( gr, TString(name[ii]), "lep" );

  }
  
  c->cd();
  mg->Draw("ap");
  mg->GetXaxis()->SetTitle("HT (GeV)");
  mg->GetYaxis()->SetTitle("Efficiency");
  mg->GetYaxis()->SetTitleOffset(1.2);
  mg->GetXaxis()->SetRangeUser(275.,975.);
  mg->GetYaxis()->SetRangeUser(0.,1.);
  legend->Draw();

  c->SaveAs(TString(str+".pdf")); 
  c->SaveAs(TString(str+".C")); 

  // Correction factor 
  std::vector<double> corr(num[0][0][0].size(),0.);
  std::vector<double> cerr(num[0][0][0].size(),0.);
  for ( uint iii = 0; iii < num[0][0][0].size(); ++iii ) {
    corr[iii] = eff[1][iii] > 0. ? eff[0][iii] / eff[1][iii] : 1.;
    cerr[iii] = corr[iii] * sqrt( (eff[0][iii]>0.?(err[0][iii]/eff[0][iii])*(err[0][iii]/eff[0][iii]):0.) +
				  (eff[1][iii]>0.?(err[1][iii]/eff[1][iii])*(err[1][iii]/eff[1][iii]):0.) );
    std::cout << "HT: " 
	      << std::fixed << std::setprecision(0)
	      << 175.+iii*100.
	      << " corr: " 
	      << std::scientific << std::setprecision(2)
	      << corr[iii] << " +/- " << cerr[iii] << std::endl; 
  }
  
  TCanvas* c1 = new TCanvas(TString(str+"Corr"),"");
  c1->SetFillColor(0);
  c1->SetLineColor(0); 
  c1->SetLeftMargin(0.15);
  c->cd();
    
  TGraphAsymmErrors* gr1 = new TGraphAsymmErrors(num[0][0][0].size(),
						 &ht.front(),
						 &corr.front(),
						 &w.front(),
						 &w.front(),
						 &cerr.front(),
						 &cerr.front());
  
  c1->cd();
  gr1->SetTitle("");
  gr1->SetLineColor(1);
  gr1->SetMarkerColor(1);
  gr1->SetMarkerStyle(20);
  gr1->Draw("ap");
  gr1->GetXaxis()->SetTitle("HT (GeV)");
  gr1->GetYaxis()->SetTitle("#varepsilon(data)/#varepsilon(MC)");
  gr1->GetYaxis()->SetTitleOffset(1.2);
  gr1->GetXaxis()->SetRangeUser(275.,975.);
  gr1->GetYaxis()->SetRangeUser(0.,1.);

  c1->SaveAs(TString(str+"Corr.pdf")); 
  c1->SaveAs(TString(str+"Corr.C")); 
  
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
  ss << "_" << type[ifile] << "_multi" << multi[imulti] << "_aT" << at[iat];
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
	    << " aT:" << at[iat]
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
  }
  if ( val2 > 0. ) {
    errh += (errh2/val2)*(errh2/val2);
    errl += (errl2/val2)*(errl2/val2);
  }
  if ( val > 0 ) {
    errh = val * sqrt(errh);
    errl = val * sqrt(errl);
  }

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
  output->Sumw2();
  
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

// -----------------------------------------------------------------------------
//  
//TH1D* rebinNew( TFile* file, const char* name, int multi, int nbins = -1, double xlow = -1., double xhigh = -1. ) {
TH1D* rebinNew( TFile* file, TString name, int multi ) {
  //TH1D* rebinNew( TFile* file, TString name, int multi, int nbins = -1, double* xarray = 0 ) {

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
    std::cout << "Unable to retrieve histogram with name \"" << name << "\"" << std::endl;
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
  //output->Sumw2();
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
  TString name( TString( input->GetName() ) + "_Integral" );
  TH1D* output = new TH1D( name, "", 
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
		int& nht, 
 		StringV his, 
 		StringVV files,
 		DoubleV lumis,
 		IntV multi, 
 		DoubleV at, 
 		DoubleV& ht, 
 		double& ht_min, 
 		double& ht_max,
 		DoubleVVVV& numer, 
 		DoubleVVVV& numer_errh, 
 		DoubleVVVV& numer_errl, 
 		DoubleVVVV& denom, 
 		DoubleVVVV& denom_errh, 
 		DoubleVVVV& denom_errl, 
 		DoubleVVVV& ratio, 
 		DoubleVVVV& errh, 
 		DoubleVVVV& errl,
 		IntVVV& length,
		std::string& label,
		bool efficiency = false,
		int use_sumw2 = 1,
		int data_file = -1 ) {

  std::vector<double> seff;
  seff.push_back(0.8775);
  seff.push_back(0.9546);
  seff.push_back(0.9756);
  seff.push_back(0.9712);
  seff.resize(8,1.);
  
  std::vector<double> seffh;
  seffh.push_back(0.0171);
  seffh.push_back(0.0158);
  seffh.push_back(0.0166);
  seffh.push_back(0.0284);
  seffh.resize(8,0.);

  std::vector<double> seffl;
  seffl.push_back(0.0171);
  seffl.push_back(0.0158);
  seffl.push_back(0.0166);
  seffl.push_back(0.0284);
  seffl.resize(8,0.);

  std::vector<double> beff;
  beff.push_back(0.8784);
  beff.push_back(0.9061);
  beff.push_back(0.9823);
  beff.push_back(0.9876);
  beff.push_back(0.9735);
  beff.push_back(0.9996);
  beff.push_back(1.0000);
  beff.push_back(0.9999);
  beff.resize(8,1.);
  
  std::vector<double> beffh;
  beffh.push_back(0.0192);
  beffh.push_back(0.0293);
  beffh.push_back(0.0007);
  beffh.push_back(0.0012);
  beffh.push_back(0.0016);
  beffh.push_back(0.0002);
  beffh.push_back(0.0000);
  beffh.push_back(0.0001);
  beffh.resize(8,0.);

  std::vector<double> beffl;
  beffl.push_back(0.0192);
  beffl.push_back(0.0293);
  beffl.push_back(0.0007);
  beffl.push_back(0.0012);
  beffl.push_back(0.0016);
  beffl.push_back(0.0002);
  beffl.push_back(0.0000);
  beffl.push_back(0.0001);
  beffl.resize(8,0.);
  
  // Reset
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {	
	for ( int iht = 0; iht < nht; ++iht ) {
	  numer[ifile][imulti][iat][iht] = 0.;
	  numer_errh[ifile][imulti][iat][iht] = 0.;
	  numer_errl[ifile][imulti][iat][iht] = 0.;
	  denom[ifile][imulti][iat][iht] = 0.;
	  denom_errh[ifile][imulti][iat][iht] = 0.; 
	  denom_errl[ifile][imulti][iat][iht] = 0.; 
	  ratio[ifile][imulti][iat][iht] = 0.;
	  length[ifile][imulti][iat] = 0; 
	  errh[ifile][imulti][iat][iht] = 0.;
	  errl[ifile][imulti][iat][iht] = 0.;
	}
      }
    }
  }

  // Loop through collections of data/MC files 
  for ( uint ifile = 0; ifile < nfile; ++ifile ) {
    
    // Loop through data/MC files with each collection
    for ( uint jfile = 0; jfile < files[ifile].size(); ++jfile ) {
      
      TString filename(files[ifile][jfile]);
      TFile* file = new TFile(filename);
      if ( file->IsZombie() || !(file->IsOpen()) ) { 
	if (file) { delete file; }
	continue; 
      }
      file->cd();

      std::string short_name = file->GetName(); short_name = short_name.substr( short_name.find("Ratio_") );
      
      // Loop through bins of multiplicity
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {

	// Loop through bins of AlphaT
	for ( uint iat = 0; iat < nat; ++iat ) {
	  
	  length[ifile][imulti][iat] = 0;
	  
	  // Directory and histo names
	  std::stringstream dir;
	  std::stringstream name;
	  std::stringstream pre;
	  std::stringstream post;
	  dir << "QcdBkgdEst/";
	  name << his[ifile] << "_aT"; 
	  pre << dir.str() << name.str() << "0";
	  post << dir.str() << name.str() << at[iat];
	
	  // Create ratio histo
	  TH1D* above = rebinNew( file, TString(post.str()), multi[imulti] );
	  TH1D* below = rebinNew( file, TString(pre.str()), multi[imulti] );
	  
	  //@@ ALPHA_T SLICES PLUS LAST INCLUSIVE BIN
	  if ( iat+1 < nat ) {
	    std::stringstream post1;
	    post1 << dir.str() << name.str() << at[iat+1];
	    TH1D* above1 = rebinNew( file, TString(post1.str()), multi[imulti] );
	    above->Add(above1,-1.);
	  }

	  if ( above && (int)ht.size() < nht-1 ) {
	    int nbins = above->GetXaxis()->GetNbins();
	    nbins = nbins<nht?nbins:nht; //@@ check nbins does not exceed max
	    const TArrayD* bins = above->GetXaxis()->GetXbins();
	    ht.clear();
	    for ( int i = 0; i < nbins; ++i ) { ht.push_back((*bins)[i]); }
	    nht = ht.size();
	    ht.push_back( above->GetXaxis()->GetXmax() );
	    ht_min = above->GetXaxis()->GetXmin();
	    ht_max = above->GetXaxis()->GetXmax();
	    label = above->GetXaxis()->GetTitle();
	  }
	  
	  file->cd();
	    
	  if ( above && below ) {

	    above->Scale(lumis[ifile]/100.);
	    below->Scale(lumis[ifile]/100.);

	    if ( efficiency == false ) { below->Add(above,-1.); }
	      
// 	    	      if ( true ) { 
// 	    		std::cout << " CONTENTS: file: " << files[ifile][jfile] 
// 	    			  << " multi: " << multi[imulti]
// 	    			  << " aT:" << at[iat]
// 	    			  << "  HT:" << ht[iht]
// 	    			  << " n: " 
// 	    			  << above->GetBinContent(iht+1) 
// 	    			  << " ne: " 
// 	    			  << above->GetBinError(iht+1) 
// 	    			  << " d: " 
// 	    			  << below->GetBinContent(iht+1) 
// 	    			  << " de: " 
// 	    			  << below->GetBinError(iht+1) 
// 	    			  << std::endl;
// 	    	      }
	    
// 	    double bw  = 1.;
	    for ( int iht = 0; iht < nht; ++iht ) {
	      
	      //@@ If no entries in any bins, no weight can be determined. (Likely the sample is QCD, with no QCD in numerator)

	      bool other = false;

	      double a   = above->GetBinContent(iht+1);
	      double ae  = above->GetBinError(iht+1);
	      double aw  = -1.;
	      double an  = a;
	      double aeh = ae;
	      double ael = ae;

 	      for ( int jht = 0; jht < nht; ++jht ) {
		int bin = ((iht-jht)%nht); bin += bin<0?nht:0;
 		double aa = above->GetBinContent(bin+1);
 		double ee = above->GetBinError(bin+1);
 		if ( aa > 0. ) { aw = (ee*ee)/aa; break; } 
 	      }

 	      if ( use_sumw2 == 0 ) { 
 		an = a;
 		ae = sqrt(a);
 		aeh = a > 10. ? ae : poissonErrH(a,ae);
 		ael = a > 10. ? ae : poissonErrL(a,ae);
 	      } else if ( use_sumw2 == 1 && aw > 0. ) {
 		an  = a/aw;
 		aeh = an > 10. ? ae : ( other ? poissonErrH(a,ae) : aw * poissonErrH(an,ae) );
 		ael = an > 10. ? ae : ( other ? poissonErrL(a,ae) : aw * poissonErrL(an,ae) );
 	      } else if ( use_sumw2 == 2 && aw > 0. ) {
 		an  = a/aw;
		aeh = a > 0. ? ae : aw*poissonErrH(a,ae);
		ael = a > 0. ? ae : aw*poissonErrL(a,ae);
	      }

	      double b   = below->GetBinContent(iht+1);
	      double be  = below->GetBinError(iht+1);
	      double bw  = -1.;
	      double bn  = a;
	      double beh = be;
	      double bel = be;

 	      for ( int jht = 0; jht < nht; ++jht ) {
		double bb  = below->GetBinContent((iht+jht+1)%nht);
		double ee = below->GetBinError((iht+jht+1)%nht);
		if ( bb > 0. ) { bw = (ee*ee)/bb; break; } 
	      }
	      
	      if ( !use_sumw2 ) { 
		bn = b;
		be = sqrt(b);
		beh = b > 10. ? be : poissonErrH(b,be);
		bel = b > 10. ? be : poissonErrL(b,be);
	      } else if ( bw > 0. ) {
		bn  = b/bw;
		beh = bn > 10. ? be : ( other ? poissonErrH(b,be) : bw * poissonErrH(bn,be) );
		bel = bn > 10. ? be : ( other ? poissonErrL(b,be) : bw * poissonErrL(bn,be) );
	      }

	      numer[ifile][imulti][iat][iht]      += a;
	      numer_errh[ifile][imulti][iat][iht] += aeh*aeh;
	      numer_errl[ifile][imulti][iat][iht] += ael*ael;
	      denom[ifile][imulti][iat][iht]      += b;
	      denom_errh[ifile][imulti][iat][iht] += beh*beh;
	      denom_errl[ifile][imulti][iat][iht] += bel*bel;

	      std::cout << " ifile: " << ifile
			<< " jfile: " << jfile
			<< " file: " << short_name
			<< " imulti: " << imulti
			<< " iat: " << iat
			<< " iht: " << iht
			<< " a: " << a
 			<< " ae: " << ae
//  			<< " seh: " << sqrt(numer_errh[ifile][imulti][iat][iht])
//  			<< " sel: " << sqrt(numer_errl[ifile][imulti][iat][iht])
 			<< " aw: " << aw
 			<< " an: " << an
			<< " aeh: " << aeh
			<< " ael: " << ael
			<< " sumw2?: " << use_sumw2
// 			<< " r: " << (a>0.?aeh/a:0.)
// 			<< " b: " << b
// 			<< " e: " << be
// 			<< " w: " << bw
// 			<< " n: " << bn
// 			<< " eh: " << beh
// 			<< " el: " << bel
			<< std::endl;
	      
	    } 
	  }
	    
	  if (above) { delete above; }
	  if (below) { delete below; }
	    
	} // Loop through aT bins
      } // Loop through multiplicity bins
      
      // Close file that was opened
      if (file) {
	file->cd();
	file->Close();
	delete file;
      } 
      
    } // Loop through files (jfile)
    
    for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
      for ( uint iat = 0; iat < nat; ++iat ) {
	for ( int iht = 0; iht < nht; ++iht ) {

	  double a   = numer[ifile][imulti][iat][iht];
	  double aeh = sqrt(numer_errh[ifile][imulti][iat][iht]);
	  double ael = sqrt(numer_errl[ifile][imulti][iat][iht]);
	      
	  double b   = denom[ifile][imulti][iat][iht];
	  double beh = sqrt(denom_errh[ifile][imulti][iat][iht]);
	  double bel = sqrt(denom_errl[ifile][imulti][iat][iht]);
	    
	  // Trigger efficiencies
	  if ( trigger_effs && data_file > -1 ) {
	    //std::cout << " get here 0: " << a << std::endl;
	    double n  = 0.;
	    double eh = 0.;
	    double el = 0.;
	    // Efficiency of aT leg on aT trigger
	    if (true) {
	      n  = a / seff[iht]; eh = 0.; el = 0.;
	      calcErr( n, eh, el, a, aeh, ael, seff[iht], seffh[iht], seffl[iht] ); 
	      a = n; aeh = eh; ael = el;
	    }
	    // Efficiency of HT leg on aT trigger
	    if (true) {
	      n  = a / beff[iht]; eh = 0.; el = 0.;
	      calcErr( n, eh, el, a, aeh, ael, beff[iht], beffh[iht], beffl[iht] ); 
	      a = n; aeh = eh; ael = el;
	    }
	    // Efficiency of HT trigger
	    if (true) {
	      n  = b / beff[iht]; eh = 0.; el = 0.;
	      calcErr( n, eh, el, b, beh, bel, beff[iht], beffh[iht], beffl[iht] ); 
	      b = n; beh = eh; bel = el;
	    }
	    //std::cout << " get here 1: " << a << std::endl;
	  } else {
	    //std::cout << " get here 2: " << std::endl;
	  }

	  numer[ifile][imulti][iat][iht]      = a;
	  numer_errh[ifile][imulti][iat][iht] = aeh;
	  numer_errl[ifile][imulti][iat][iht] = ael;

	  denom[ifile][imulti][iat][iht]      = b;
	  denom_errh[ifile][imulti][iat][iht] = beh;
	  denom_errl[ifile][imulti][iat][iht] = bel;
	  
	  double r  = b > 0. ? a/b : 0.;
	  double rerrl = 0.;
	  double rerrh = 0.;
 	  calcErr( r, rerrh, rerrl, a, aeh, ael, b, beh, bel ); 
	  
	  ratio[ifile][imulti][iat][iht] = r;
	  if ( r > 0. ) { length[ifile][imulti][iat]++; }
	  errh[ifile][imulti][iat][iht] = rerrh;
	  errl[ifile][imulti][iat][iht] = rerrl;

// 	  //@@
// 	  if ( ifile != data_file &&
// 	       ht[iht] == 875. ) {
// 	    double norm = 320.;
// 	    double e1 = aeh;//errh[ifile][imulti][iat][ipt][iht] / ratio[ifile][imulti][iat][ipt][iht];
// 	    double e2 = 0.;
// 	    e2 += (norm/482.6)*1.148 * (norm/482.6)*1.148; // W
// 	    e2 += (norm/378.8)*1.148 * (norm/378.8)*1.148; // Z
// 	    e2 += e1*e1;
// 	    e2 = sqrt(e2);
// 	    errh[ifile][imulti][iat][iht] = (e2/a) * ratio[ifile][imulti][iat][iht];
// 	    errl[ifile][imulti][iat][iht] = (e2/a) * ratio[ifile][imulti][iat][iht];
// 	  }
	      
	} // iht
      } // iat
    } // imulti
      
  } // Loop through files (ifile)
  
  bool print = false;
  if (print) {
    std::stringstream ss;
    for ( uint ifile = 0; ifile < nfile; ++ifile ) {
      for ( uint imulti = 0; imulti < nmulti; ++imulti ) {
	for ( uint iat = 0; iat < nat; ++iat ) {
	  for ( int iht = 0; iht < nht; ++iht ) {
	    ss << " CHECK:"
	       << " ifile: " << ifile
	       << " multi: " << multi[imulti]
	       << " AlphaT: " << at[iat]
	       << " HT :" << ht[iht]
	       << " n: " << numer[ifile][imulti][iat][iht]
	       << " n_errh: " << numer_errh[ifile][imulti][iat][iht]
	       << " d: " << denom[ifile][imulti][iat][iht]
	       << " d_errh: " << denom_errh[ifile][imulti][iat][iht]
	       << " r: " << ratio[ifile][imulti][iat][iht]
	       << " eh: " << errh[ifile][imulti][iat][iht]
	       << " el: " << errl[ifile][imulti][iat][iht];
	    if ( ratio[ifile][imulti][iat][iht] <= 0. ) { ss << " (0,0)"; }
	    else { 
	      ss << " (" 
		 << dr((errh[ifile][imulti][iat][iht]/ratio[ifile][imulti][iat][iht]),2) 
		 << ","
		 << dr((errl[ifile][imulti][iat][iht]/ratio[ifile][imulti][iat][iht]),2)
		 << ")"; 
	    }
	    ss << std::endl;
	  }
	}
      }
    }
    std::cout << ss.str();
  }

//   numer[0][0][0][0] *= 1.01;
//   numer_errh[0][0][0][0] *= 1.01;
//   numer_errl[0][0][0][0] *= 1.01;
  
}
