#include "style.C"
#include <TCanvas.h>
#include <TFile.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TGraphErrors.h>
#include <TH1D.h>
#include <TMultiGraph.h>
#include <TLegend.h>
#include <iostream>
#include <string>
#include <vector>

// -----------------------------------------------------------------------------
// 
void calcIntegral( TH1D* cum, bool greater_than ) {

  bool debug = false;
  
  if ( debug == true ) {
    for ( int ibin = 0; ibin <= cum->GetNbinsX()+1; ibin++ ) {
      if ( ibin > 10 && cum->GetNbinsX()-ibin >= 10 ) { continue; }
      std::cout << "Differential histogram:"
		<< " bin=" << ibin
		<< " content=" << cum->GetBinContent(ibin) 
		<< " +/- " << cum->GetBinError(ibin) 
		<< std::endl;
    }
    std::cout << "Differential histogram:"
	      << " entries=" << cum->GetEntries() 
	      << " integal=" << cum->Integral() 
	      << " total=" << cum->Integral(0,cum->GetNbinsX()+1) 
	      << " underflow=" << cum->GetBinContent(0) 
	      << "+/-" << cum->GetBinError(0) 
	      << " overflow=" << cum->GetBinContent(cum->GetNbinsX()+1) 
	      << "+/-" << cum->GetBinError(cum->GetNbinsX()+1) 
	      << std::endl;
  }

  double val = 0.;
  double err = 0.;

  // Loop through bins 
  int nbins = cum->GetNbinsX();
  for ( int ibin = 0; ibin <= nbins+1; ibin++ ) {
    
    // Check direction
    int bin = ibin;
    if ( greater_than ) { bin = nbins+1 - ibin; }
    
    // Running totals
    val += cum->GetBinContent(bin);
    err += cum->GetBinError(bin) * cum->GetBinError(bin);
    
    // Set bin content and error
    cum->SetBinContent(bin,val);
    cum->SetBinError(bin,sqrt(err));
    
  }
  
  // Number of entries
  cum->SetEntries(nbins+1);

  // Debug
  if ( debug == true ) {
    for ( int ibin = 0; ibin <= nbins+1; ibin++ ) {
      if ( ibin > 10 && nbins-ibin >= 10 ) { continue; }
      std::cout << "Cumulative histogram:"
		<< " bin=" << ibin
		<< " content=" << cum->GetBinContent(ibin) 
		<< " +/- " << cum->GetBinError(ibin) 
		<< std::endl;
    }
    std::cout << "Cumulative histogram:"
	      << " entries=" << cum->GetEntries() 
	      << " integal=" << cum->Integral() 
	      << " total=" << cum->Integral(0,nbins+1) 
	      << " underflow=" << cum->GetBinContent(0) 
	      << "+/-" << cum->GetBinError(0) 
	      << " overflow=" << cum->GetBinContent(nbins+1) 
	      << "+/-" << cum->GetBinError(nbins+1) 
	      << std::endl;
  }

}

// -----------------------------------------------------------------------------
// 
void createHisto( TH1* his, std::string title, std::string x, std::string y ) {
  TCanvas* c = new TCanvas(title.c_str(),title.c_str());
  his->GetXaxis()->SetTitle(x.c_str());
  his->GetYaxis()->SetTitle(y.c_str());
  his->GetYaxis()->SetTitleOffset(1.5);
  his->SetMarkerStyle(20);
  his->SetMarkerColor(1);
  his->SetMarkerSize(0.4);
  his->SetFillColor(11);
  his->SetLineColor(11);
  his->Draw("E3");
  his->Draw("sameP");
  c->SaveAs(TString(title+".pdf"));
}

// -----------------------------------------------------------------------------
// 
void createGraph( TGraphAsymmErrors* gr, std::string title, std::string x, std::string y ) {
  TCanvas* c = new TCanvas(title.c_str(),title.c_str());
  gr->SetTitle("");
  gr->GetXaxis()->SetTitle(x.c_str());
  gr->GetYaxis()->SetTitle(y.c_str());
  gr->SetMarkerStyle(20);
  gr->SetMarkerColor(1);
  gr->SetMarkerSize(0.4);
  gr->SetFillColor(11);
  gr->SetLineColor(11);
  gr->Draw("A3");
  gr->Draw("PZsame");
  c->SaveAs(TString(title+".pdf"));
}

// -----------------------------------------------------------------------------
// 
TGraphAsymmErrors* calcEff( TH1D* cum, bool greater_than ) {

  std::vector<double> num;
  std::vector<double> err;
  num.clear();
  err.clear();
  if ( greater_than ) {
    num.resize( cum->GetNbinsX()+1, cum->GetBinContent(0) );
    err.resize( cum->GetNbinsX()+1, cum->GetBinError(0) );
  } else {
    num.resize( cum->GetNbinsX()+1, cum->GetBinContent(cum->GetNbinsX()+1) );
    err.resize( cum->GetNbinsX()+1, cum->GetBinError(cum->GetNbinsX()+1) );
  }

  TH1D* tmp = new TH1D( *cum );
  TH1D* tot = new TH1D( *cum );
  tot->SetContent(&num.front());
  tot->SetError(&err.front());
  tot->SetBinContent(0,num.front());
  tot->SetBinError(0,err.front());
  tot->SetBinContent(tot->GetNbinsX()+1,num.front());
  tot->SetBinError(tot->GetNbinsX()+1,err.front());

  TGraphAsymmErrors* eff = new TGraphAsymmErrors(cum,tot,"cp");

  // Check values and errors
  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> xel;
  std::vector<double> xeh;
  std::vector<double> yel;
  std::vector<double> yeh;
  int nbins = tmp->GetNbinsX();
  for ( int ibin = 0; ibin < nbins; ibin++ ) {

    // Retrieve x/y values
    double x_tmp = 0.;
    double y_tmp = 0.;
    eff->GetPoint(ibin,x_tmp,y_tmp);

    // Retrieve errors
    double xel_tmp = eff->GetErrorXlow(ibin);
    double xeh_tmp = eff->GetErrorXhigh(ibin);
    double yel_tmp = eff->GetErrorYlow(ibin);
    double yeh_tmp = eff->GetErrorYhigh(ibin);
    
    // Calc efficiency
    int bin = ibin + 1;
    double n_tmp = tmp->GetBinContent(bin);
    double d_tmp = tot->GetBinContent(bin);
    double r_tmp = d_tmp > 0. ? n_tmp/d_tmp : 0.;
    
    // Set x/y values
    x.push_back(x_tmp);
    y.push_back(r_tmp);

    // Set errors on x
    xel.push_back( xel_tmp ); 
    xeh.push_back( xeh_tmp ); 

    // Check and set lower bound on y
    if ( r_tmp - yel_tmp < 0. ) { 
      // Use Normal interval instead of Clopper-Pearson
      yel.push_back( r_tmp );
    } else {
      yel.push_back( yel_tmp );
    }

    // Check and set upper bound on y
    if ( r_tmp + yeh_tmp > 1. ) { 
      // Use Normal interval instead of Clopper-Pearson
      yeh.push_back( 1. - r_tmp );
    } else {
      yeh.push_back( yeh_tmp );
    }

  }

  TGraphAsymmErrors* temp = new TGraphAsymmErrors(x.size(),
						  &x.front(),
						  &y.front(),
						  &xel.front(),
						  &xeh.front(),
						  &yel.front(),
						  &yeh.front());

  return temp;

}

// -----------------------------------------------------------------------------
// 
void calcSoverB( TH1D* his, TH1D* s, TH1D* b ) {

  // Loop through bins 
  int nbins = s->GetNbinsX();
  for ( int bin = 1; bin <= nbins; bin++ ) {
    
    double s_val = s->GetBinContent(bin);
    double s_err = s->GetBinError(bin);
    double b_val = b->GetBinContent(bin);
    double b_err = b->GetBinError(bin);
    
    double ratio = b_val > 0. ? s_val/b_val : 100.;
    double err = 0.;
    if ( b_val > 0. ) {
      err += s_val > 0. ? (s_err/s_val)*(s_err/s_val) : 0.; 
      err += b_val > 0. ? (b_err/b_val)*(s_err/b_val) : 0.; 
      err = sqrt(err) * ratio;
    }

    his->SetBinContent(bin,ratio);
    his->SetBinError(bin,err);
    
  }

}

// -----------------------------------------------------------------------------
// 
void calcSig( TH1D* his, TH1D* s, TH1D* b ) {
  
  // Loop through bins 
  int nbins = s->GetNbinsX();
  for ( int bin = 1; bin <= nbins; bin++ ) {
    
    double s_val = s->GetBinContent(bin);
    double s_err = s->GetBinError(bin);
    double b_val = b->GetBinContent(bin);
    double b_err = b->GetBinError(bin);
    
    double ratio = b_val > 0. ? s_val/sqrt(b_val) : 100.;
    double err = 0.;
    if ( b_val > 0. ) {
      err += s_val > 0. ? (s_err/s_val)*(s_err/s_val) : 0.; 
      err += b_val > 0. ? (b_err/b_val)*(s_err/b_val) : 0.; 
      err = sqrt(err) * ratio;
    }
    
    his->SetBinContent(bin,ratio);
    his->SetBinError(bin,err);
    
  }

}

// -----------------------------------------------------------------------------
// 
TGraphAsymmErrors* performance( TH1D* sb, TGraphAsymmErrors* eff, std::string var = "" ) { 
  
  double wp_val = 100.;
  int wp_index = -1;
  
  std::vector<double> xval;
  std::vector<double> xerrl;
  std::vector<double> xerrh;
  std::vector<double> yval;
  std::vector<double> yerrl;
  std::vector<double> yerrh;
  
  int nbins = sb->GetNbinsX();
  for ( int ibin = 0; ibin < nbins; ibin++ ) {

    int bin = ibin + 1;

    //if ( var == "Mht" && sb->GetBinCenter(bin) < 100. ) { continue; }
    
    double x = 0.; 
    double y = 0.; 
    eff->GetPoint(ibin,x,y);
    
    xval.push_back( y );
    yval.push_back( sb->GetBinContent(bin) );
    
    xerrl.push_back( eff->GetErrorYlow(ibin) );
    xerrh.push_back( eff->GetErrorYhigh(ibin) );
    
    yerrl.push_back( sb->GetBinError(bin) );
    yerrh.push_back( sb->GetBinError(bin) );
    
    if ( yval.back() < wp_val && yval.back() > 5. ) {
      wp_val = yval.back();
      wp_index = yval.size()-1;
    }
    
  }
  
  TGraphAsymmErrors* gr = new TGraphAsymmErrors( xval.size(),
						 &xval.front(),
						 &yval.front(),
						 &xerrl.front(),
						 &xerrh.front(),
						 &yerrl.front(),
						 &yerrh.front() );

  if ( wp_index > -1 ) {
    std::cout << "Working Point =" << int(yval[wp_index]*10.)/10. 
	      << "+/-" << int(yerrh[wp_index]*10.)/10.
	      << " Eff = (" << int(xval[wp_index]*1000.)/10.
	      << "+" << int(xerrh[wp_index]*1000.)/10.
	      << "-" << int(xerrl[wp_index]*1000.)/10.
	      << ")%"
	      << std::endl;
  } else {
    std::cout << "No working Point!" << std::endl;
  }

  return gr;

}

// -----------------------------------------------------------------------------
// Top-level method
void eff() {

  setTDRStyle();

  bool signal_diff = false;
  bool signal_cum = false;
  bool signal_eff = false;
  
  bool bkgd_diff = true;
  bool bkgd_cum = true;
  bool bkgd_eff = false;
  
  bool s_over_b = false;
  bool sig = false;
  bool perf_plot = false;
  
  std::vector<std::string> vars;
  std::vector<int> greater_than;
  std::vector<std::string> titles;

//   vars.push_back("Mt2");
//   greater_than.push_back(1);
//   titles.push_back(" M_{T2}");
  
  vars.push_back("AlphaT");
  greater_than.push_back(1);
  titles.push_back(" #alpha_{T}");
  
  vars.push_back("Sigma3");
  greater_than.push_back(0);
  titles.push_back(" #sigma_{3}");
  
  vars.push_back("PhiAB");
  greater_than.push_back(0);
  titles.push_back(" #phi_{12}");
  
//   vars.push_back("Radius");
//   greater_than.push_back(0);
//   titles.push_back(" #sqrt{x_{1}^{2}+x_{2}^{2}}");
  
//   vars.push_back("Mht");
//   greater_than.push_back(1);
//   titles.push_back(" H_{T}^{miss}");
  
  TMultiGraph* mg = 0;
  TLegend* leg = 0;
  if ( perf_plot ) {
    mg = new TMultiGraph();
    leg = new TLegend(0.2,0.7,0.3,0.9);
    leg->SetLineColor(0);
    leg->SetLineStyle(0);
    leg->SetLineWidth(0);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetTextSize(0.03);
  }

  for ( int ii = 0; ii < (int)vars.size(); ++ii ) {
  
    //std::string path = "/vols/cms02/bainbrid/qcd/SUSY2/results/batch/110113_1/100_100_50/";
    std::string path = "~/Desktop/work/temp/truth/";
    std::string dir = "Dalitz";
    std::string histo = "PostMeff" + vars[ii] + "_Meff500_4";
    std::string s_name = "lm1";
    std::string b_name = "qcd";
  
    // Retrieve signal histogram
    TFile* s_file =  new TFile( TString(path+"Ratio_"+s_name+".root"),"READ");
    TDirectory* s_dir = s_file > 0 ? (TDirectory*)s_file->Get(dir.c_str()) : 0;
    TH1D* s_his = s_dir > 0 ? (TH1D*)s_dir->Get(histo.c_str()) : 0;
    if ( !s_his ) {
      std::cout << "Cannot retrieve signal histogram:"
		<< " path=" << TString(path+"Ratio_"+s_name+".root")
		<< " dir=" << dir
		<< " histo=" << histo
		<< std::endl;
      return;
    }

    // Retrieve bkgd histogram
    TFile* b_file =  new TFile( TString(path+"Ratio_"+b_name+".root"),"READ");
    TDirectory* b_dir = b_file > 0 ? (TDirectory*)b_file->Get(dir.c_str()) : 0;
    TH1D* b_his = b_dir > 0 ? (TH1D*)b_dir->Get(histo.c_str()) : 0;
    if ( !b_his ) {
      std::cout << "Cannot retrieve bkgd histogram:"
		<< " path=" << TString(path+"Ratio_"+b_name+".root")
		<< " dir=" << dir
		<< " histo=" << histo
		<< std::endl;
      return;
    }
    
    // Differential histograms for signal and background
    int rebin = 1;
    TH1D* s_diff = new TH1D( *s_his );
    TH1D* b_diff = new TH1D( *b_his );
    s_diff->Rebin(rebin);
    b_diff->Rebin(rebin);

    // Cumulative histograms for signal and background
    TH1D* s_cum = new TH1D( *s_diff );
    TH1D* b_cum = new TH1D( *b_diff );
    calcIntegral(s_cum,greater_than[ii]);
    calcIntegral(b_cum,greater_than[ii]);
    
    if ( signal_diff ) { 
      createHisto( s_diff, 
		   std::string("Signal_Differential_Distribution_"+vars[ii]),
		   std::string(titles[ii]),
		   ""); 
    }

    if ( signal_cum ) { 
      createHisto( s_cum, 
		   std::string("Signal_Cumulative_Distribution_"+vars[ii]),
		   std::string(titles[ii]+(greater_than[ii]?" > ":" < ")+"cut value"),
		   "");
    }

    if ( bkgd_diff ) { 
      createHisto( b_diff, 
		   std::string("Bkgd_Differential_Distribution_"+vars[ii]),
		   std::string(titles[ii]),
		   ""); 
    }

    if ( bkgd_cum ) { 
      createHisto( b_cum, 
		   std::string("Bkgd_Cumulative_Distribution_"+vars[ii]),
		   std::string(titles[ii]+(greater_than[ii]?" > ":" < ")+"cut value"),
		   ""); 
    }
    
    // Create efficiency distributions
    TGraphAsymmErrors* s_eff = calcEff( s_cum, greater_than[ii] );
    TGraphAsymmErrors* b_eff = calcEff( b_cum, greater_than[ii] );

    if ( signal_eff ) { 
      createGraph( s_eff, 
		   std::string("Signal_Efficiency_Distribution_"+vars[ii]),
		   std::string(titles[ii]+(greater_than[ii]?" > ":" < ")+"cut value"),
		   "#varepsilon"); 
    }

    if ( bkgd_eff ) { 
      createGraph( b_eff, 
		   std::string("Bkgd_Efficiency_Distribution_"+vars[ii]),
		   std::string(titles[ii]+(greater_than[ii]?" > ":" < ")+"cut value"),
		   "#varepsilon"); 
    }
    
    // S/B
    TH1D* sb = new TH1D( *s_cum );
    calcSoverB(sb,s_cum,b_cum);
    if ( s_over_b ) { 
      createHisto( sb, 
		   std::string("Signal_Over_Bkgd_Distribution_"+vars[ii]),
		   std::string(titles[ii]+(greater_than[ii]?" > ":" < ")+"cut value"),
		   "S/B"); 
    }

    // S/sqrt(B)
    TH1D* sbb = new TH1D( *s_cum );
    calcSig(sbb,s_cum,b_cum);
    if ( sig ) { 
      createHisto( sbb, 
		   std::string("Significance_Distribution_"+vars[ii]),
		   std::string(titles[ii]+(greater_than[ii]?" > ":" < ")+"cut value"),
		   "S / #sqrt{B}"); 
    }
    
    // S/B vs signal efficiency
    if ( perf_plot ) {
      TGraphAsymmErrors* gr = performance(sbb,s_eff,vars[ii]);
      gr->SetMarkerSize(1.0);
      gr->SetMarkerStyle(24+ii);
      gr->SetMarkerColor(12+ii);
      gr->SetLineColor(12+ii);
      mg->Add(gr,"P");
      leg->AddEntry(gr,titles[ii].c_str(),"P");
    }

  } // ii

  if ( perf_plot ) {
    TCanvas* perf = new TCanvas("Performance","S/sqrt(B) versus signal efficiency");
    perf->cd();
    //perf->SetLogy();
    mg->Draw("A");
    mg->GetXaxis()->SetTitle("#varepsilon_{signal}");
    mg->GetYaxis()->SetTitle("S / #sqrt{B}");
    mg->GetXaxis()->SetLimits(0.,1.);
    mg->SetMinimum(0.);
    mg->SetMaximum(10.);
    leg->Draw();
  }

}
