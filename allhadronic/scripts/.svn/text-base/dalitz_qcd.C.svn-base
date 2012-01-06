#include "./style.C"
#include <TCanvas.h>
#include <TColor.h>
#include <TDirectory.h>
#include <TFile.h>
#include <TGraph.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TMultiGraph.h>
#include <TPad.h>
#include <TPaletteAxis.h>
#include <TPaveStats.h>
#include <TStyle.h>
#include <iostream>
#include <sstream>
#include <string>

// -----------------------------------------------------------------------------
// 
void set_plot_style() {
  
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };

//   Double_t stops[NRGBs] = { 0., .25, .50, .75, 1.0 };
//   Double_t red[NRGBs]   = { 0., 0.0, 1.0, 1.0, 1.0 };
//   Double_t green[NRGBs] = { 0., 0.0, 0.0, 1.0, 1.0 };
//   Double_t blue[NRGBs]  = { 0., 1.0, 0.0, 0.0, 1.0 };

//   Double_t stops[NRGBs]  = { 0.00, 0.50, 1.00 };
//   Double_t red[NRGBs]    = { 1.00, 0.00, 0.00};
//   Double_t green[NRGBs]  = { 0.00, 1.00, 0.00};
//   Double_t blue[NRGBs]   = { 1.00, 0.00, 1.00};

  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
  
}

// -----------------------------------------------------------------------------
// 
// void set_plot_style2() {

//   const Int_t n = 100;
//   Int_t MyPalette[n];
  
//   Double_t r[]    = { 0.00, 0.00, 0.87, 1.00, 0.51 };
//   Double_t g[]    = { 0.00, 0.81, 1.00, 0.20, 0.00 };
//   Double_t b[]    = { 0.51, 1.00, 0.12, 0.00, 0.00 };
//   Double_t stop[] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  
//   Int_t FI = TColor::CreateGradientColorTable(5,stop,r,g,b,n);
//   for (int i=0; i<n; ++i ) { MyPalette[i] = FI+i; }

//   gStyle->SetPalette(n,MyPalette);
  
// }

// -----------------------------------------------------------------------------
// 
double cutAlgoInverse( const double val,
		       const double x2,
		       int algo ) {

  double norm = 2.;

  /*
    s = ( ( x1^2 + x2^2 ) / ( (1-x1) * (1-x2) ); 
    is solved in quadratic form:
    ax1^2 + bx1 + c = 0
    where:
    a = 1
    b = s(1-x2)
    c = x2^2 + x2*s - s
    and: 
    x1 = ( -b +/- sqrt( b^2 - 4ac ) ) / 2a
  */
  if ( algo == 1 ) {
    double a = 1.;
    double b = val * ( 1 - x2 );
    double c = x2*x2 + x2*val - val;
    double d = b*b - 4*a*c;
    return ( d >= 0. ? ( -1.*b + sqrt(d) ) / ( 2.*a ) : -1. );
  } else if ( algo == 2 ) {
    return val > x2 ? sqrt( val*val - x2*x2 ) : 0.;
  } else if ( algo == 3 ) {
    return pow((x2-2*pow(val,2))/(2*val),2) + 1 - pow(val,2); 
    //return 2*(pow((x2/norm)-val*val,2)/(2*val*val) + (1-val*val)/2);
  } else if ( algo == 4 ) {
    return norm*(1-2*(x2/norm))/(2*(1-(1-cos(val))*(x2/norm))); // val = "phi_AB"
  }
  
}

// -----------------------------------------------------------------------------
// Create plots
void plot( const std::string& path, 
	   const std::string& type, 
	   const std::string& sample, 
	   const std::string& dir, 
	   const std::string& histo,
	   double lumi,
	   bool log,
	   bool scale ) {
  
  // Retrieve histogram
  std::string file_name = path + type + "_" + sample + ".root";
  std::cout << "SAMPLE: " << sample << std::endl;
  TFile* f =  new TFile(file_name.c_str(),"READ");
  if (f) { std::cout << "Opened file: " << f->GetName() << std::endl; }
  else { 
    std::cout << "Could not find file: " << file_name.c_str() << std::endl; 
    return; 
  }
  
  TDirectory* d = (TDirectory*)f->Get(dir.c_str());
  if (d) { std::cout << "Opened dir: " << d->GetName() << std::endl; }
  else { 
    std::cout << "Could not find dir: " << dir.c_str() << std::endl; 
    return; 
  }

  TH2D* his = (TH2D*)d->Get(histo.c_str());
  if (his) { std::cout << "Opened histo: " << his->GetName() << std::endl; }
  else { 
    std::cout << "Could not find histo: " << histo.c_str() << std::endl; 
    return; 
  }

  std::string canvas_name = histo + "_" + dir + "_" + type + "_" + sample;

  // Create canvas  
  TCanvas* canvas = new TCanvas(canvas_name.c_str(),"");
  canvas->SetFillColor(0);
  canvas->SetFrameBorderMode(0);
  canvas->SetFrameFillColor(0);
  canvas->SetTopMargin(0.10);
  canvas->SetBottomMargin(0.12);
  canvas->SetLeftMargin(0.12);
  canvas->SetRightMargin(0.15);

  std::stringstream ss;
  ss << canvas_name;
  
  // Pad for cross-section plot
  TPad* pad = new TPad(TString("Pad"+ss.str()),"",0.,0.,1.,1.);
  if (pad) {
    pad->SetRightMargin(0.15);
    pad->SetGrid();
    pad->Draw();
    pad->cd();
  }
  TH1F* hr = pad->DrawFrame(0.,0.,1.,1.);
  
  // Histo title
  if (hr) {
    hr->GetXaxis()->SetTitle( "x_{2}" );
    hr->GetYaxis()->SetTitle( "x_{1}" );
  }
  
  //his->Rebin2D(2,2);

  if ( log ) { 
    gPad->SetLogz(); 
  }
  //if ( scale ) his->Scale( lumi / 100. );
//   his->SetMaximum(1.e5);
//   his->SetMinimum(1.e-1);

  double xmin = his->GetXaxis()->GetXmin();
  double xmax = his->GetXaxis()->GetXmax();
  double ymin = his->GetYaxis()->GetXmin();
  double ymax = his->GetYaxis()->GetXmax();
  
  // Reset title
  std::string title = ";" + std::string(his->GetXaxis()->GetTitle()) + ";" + std::string(his->GetYaxis()->GetTitle());
  his->SetTitle(title.c_str());
  his->GetXaxis()->SetTitleOffset(1.2);
  his->GetYaxis()->SetTitleOffset(1.4);

  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  his->Draw("COLZsame");

  double pass = 0.;
  double fail = 0.;
  for ( int ii = 1; ii <= his->GetNbinsX(); ++ii ) {
    for ( int jj = 1; jj <= his->GetNbinsY(); ++jj ) {
      double x1 = his->GetBinLowEdge(jj);
      double x2 = his->GetBinLowEdge(ii);
      //double x1 = his->GetBinCenter(jj);
      //double x2 = his->GetBinCenter(ii);
      double at = sqrt(((x2/2)*(x2/2))/(2*(x2/2)+2*(x1/2)-1));
      if ( at > 0.55 ) { pass += his->GetBinContent(ii,jj); }
      else { fail += his->GetBinContent(ii,jj); }
    }
  }
  std::cout << " PASS: " << pass
	    << " FAIL: " << fail
	    << " TOTAL: " << pass+fail
	    << std::endl;
 
//   // Lumi
//   if (0) { 
//     std::stringstream sss;
//     sss << "#int L dt = " << lumi << " pb^{-1}";
//     double xpos = 0.05 * (xmax-xmin)+xmin;
//     double ypos = 0.25 * (ymax-ymin)+ymin;
//     TLatex* text1 = new TLatex(xpos,ypos,sss.str().c_str());
//     text1->SetTextAlign(12); 
//     text1->SetTextSize(0.035);
//     text1->Draw("same");
//   }

//   // Sample
//   if (0) {
//     double xpos = 0.05 * (xmax-xmin)+xmin;
//     double ypos = 0.15 * (ymax-ymin)+ymin;
//     TText* text3 = new TText(xpos,ypos,sample.c_str());
//     text3->SetTextAlign(12); 
//     text3->SetTextSize(0.035);
//     text3->Draw("same");
//   }

//   // Jet type
//   if (0) { 
//     double xpos = 0.05 * (xmax-xmin)+xmin;
//     double ypos = 0.10 * (ymax-ymin)+ymin;
//     TText* text2 = new TText(xpos,ypos,type.c_str());
//     text2->SetTextAlign(12); 
//     text2->SetTextSize(0.035);
//     text2->Draw("same");
//   }

  // Scale
  TPaletteAxis* palette = (TPaletteAxis*)his->GetListOfFunctions()->FindObject("palette");
  if ( palette ) {
    palette->SetX2NDC( palette->GetX1NDC()+0.01 );
    palette->SetY1NDC(0.2);
    palette->SetY2NDC(0.8);
    palette->Draw();
  }

//   // Stats
//   gStyle->SetOptStat("i");
//   his->SetStats(1);
//   TPaveStats* stats = (TPaveStats*)his->GetListOfFunctions()->FindObject("stats"); 
//   std::string stats_pos = "br";
//   if ( stats ) { 
//     stats->SetFillColor(0);
//     stats->SetLineColor(0); 
//     stats->SetShadowColor(0); 
//     if ( stats_pos == "tr" ) {
//       stats->SetX1NDC(0.60); stats->SetY1NDC(0.68); stats->SetX2NDC(0.83); stats->SetY2NDC(0.88); 
//     } else if ( stats_pos == "br" ) {
//       stats->SetX1NDC(0.60); stats->SetY1NDC(0.18); stats->SetX2NDC(0.83); stats->SetY2NDC(0.28); 
//     } else {
//       stats->SetX1NDC(0.60); stats->SetY1NDC(0.68); stats->SetX2NDC(0.83); stats->SetY2NDC(0.88); 
//     }
//   }

  // -------------------- Pad for AlphaT contours --------------------
  
  if (1) {
    
    if (canvas) canvas->cd();
    TPad* overlay = new TPad(TString("Overlay"+ss.str()),"",0.,0.,1.,1.);
    if (overlay) {
      overlay->SetRightMargin(0.15);
      overlay->SetFillStyle(4000);
      overlay->SetFillColor(0);
      overlay->SetFrameFillStyle(4000);
      overlay->Draw();
      overlay->cd();
      overlay->DrawFrame(pad->GetUxmin(),
			 pad->GetUymin(),
			 pad->GetUxmax(),
			 pad->GetUymax());
    }

    // 
    const int nxs = 6;
    double xs[nxs];
    for ( int ii = 0; ii < nxs; ++ii ) { xs[ii] = 0.50 + 0.01*ii; } 

    // Graphs of 3-jet xs contours
    TMultiGraph* mg = new TMultiGraph();
    for ( Int_t ixs = 0; ixs < nxs; ixs++ ) {
      Double_t alpha_t = xs[ixs];
      std::cout << "Cut value = " << alpha_t << std::endl;
      const Int_t n_ = 100;
      Double_t x1_[n_];
      Double_t x2_[n_];
      for ( Int_t j = 0; j < 100; j++ ) {
	x2_[j] = j*0.01;
	x1_[j] = cutAlgoInverse( alpha_t, x2_[j], 3 );
      }
      TGraph* gr = new TGraph(n_,x2_,x1_);
      mg->Add(gr,"l");
    }
    mg->Draw();

   }

  // -------------------- Pad for Sigma3 contours --------------------

  if (1) {

    // Pad for Sigma3 contours
    if (canvas) canvas->cd();
    TPad* overlay = new TPad(TString("Overlay"+ss.str()),"",0.,0.,1.,1.);
    if (overlay) {
      overlay->SetRightMargin(0.15);
      overlay->SetFillStyle(4000);
      overlay->SetFillColor(0);
      overlay->SetFrameFillStyle(4000);
      overlay->Draw();
      overlay->cd();
      overlay->DrawFrame(pad->GetUxmin(),
			 pad->GetUymin(),
			 pad->GetUxmax(),
			 pad->GetUymax());
    }

    // 
    const int nxs = 5;
    double xs[nxs];
    for ( int ii = 0; ii < nxs; ++ii ) { xs[ii] = pow(10,ii-1); } 
    
    // Graphs of 3-jet xs contours
    TMultiGraph* mg = new TMultiGraph();
    for ( Int_t ixs = 0; ixs < nxs; ixs++ ) {
      Double_t alpha_t = xs[ixs];
      std::cout << "Cut value = " << alpha_t << std::endl;
      const Int_t n_ = 100;
      Double_t x1_[n_];
      Double_t x2_[n_];
      for ( Int_t j = 0; j < 100; j++ ) {
	x2_[j] = j*0.01;
	x1_[j] = cutAlgoInverse( alpha_t, x2_[j], 1 );
      }
      TGraph* gr = new TGraph(n_,x2_,x1_);
      mg->Add(gr,"l");
    }
    mg->Draw();
  
  }

  // -------------------- Pad for Radius contours --------------------

  if (0) {

    if (canvas) canvas->cd();
    TPad* overlay = new TPad(TString("Overlay"+ss.str()),"",0.,0.,1.,1.);
    if (overlay) {
      overlay->SetRightMargin(0.15);
      overlay->SetFillStyle(4000);
      overlay->SetFillColor(0);
      overlay->SetFrameFillStyle(4000);
      overlay->Draw();
      overlay->cd();
      overlay->DrawFrame(pad->GetUxmin(),
			 pad->GetUymin(),
			 pad->GetUxmax(),
			 pad->GetUymax());
    }

    // 
    const int nxs = 5;
    double xs[nxs];
    for ( int ii = 0; ii < nxs; ++ii ) { xs[ii] = 0.9 + ii*0.05; } 
    
    // Graphs of 3-jet xs contours
    TMultiGraph* mg = new TMultiGraph();
    for ( Int_t ixs = 0; ixs < nxs; ixs++ ) {
      Double_t alpha_t = xs[ixs];
      std::cout << "Cut value = " << alpha_t << std::endl;
      const Int_t n_ = 100;
      Double_t x1_[n_];
      Double_t x2_[n_];
      for ( Int_t j = 0; j < 100; j++ ) {
	x2_[j] = j*0.01;
	x1_[j] = cutAlgoInverse( alpha_t, x2_[j], 2 );
      }
      TGraph* gr = new TGraph(n_,x2_,x1_);
      mg->Add(gr,"l");
    }
    mg->Draw();
  
  }

  // -------------------- Pad for PhiAB contours --------------------

  if (0) {

    if (canvas) canvas->cd();
    TPad* overlay = new TPad(TString("Overlay"+ss.str()),"",0.,0.,1.,1.);
    if (overlay) {
      overlay->SetRightMargin(0.15);
      overlay->SetFillStyle(4000);
      overlay->SetFillColor(0);
      overlay->SetFrameFillStyle(4000);
      overlay->Draw();
      overlay->cd();
      overlay->DrawFrame(pad->GetUxmin(),
			 pad->GetUymin(),
			 pad->GetUxmax(),
			 pad->GetUymax());
    }

    // 
    const int nxs = 24;
    double xs[nxs];
    for ( int ii = 0; ii < nxs; ++ii ) { xs[ii] = 3.14159265*(ii+1)/24; } 
    
    // Graphs of 3-jet xs contours
    TMultiGraph* mg = new TMultiGraph();
    for ( Int_t ixs = 0; ixs < nxs; ixs++ ) {
      Double_t alpha_t = xs[ixs];
      std::cout << "Cut value = " << alpha_t << std::endl;
      const Int_t n_ = 100;
      Double_t x1_[n_];
      Double_t x2_[n_];
      for ( Int_t j = 0; j < 100; j++ ) {
	x2_[j] = j*0.01;
	x1_[j] = cutAlgoInverse( alpha_t, x2_[j], 4 );
      }
      TGraph* gr = new TGraph(n_,x2_,x1_);
      mg->Add(gr,"l");
    }
    mg->Draw();
  
  }

  canvas->cd();
  canvas->SaveAs(std::string(canvas_name+".pdf").c_str());

}

// -----------------------------------------------------------------------------
// Loop over files and histograms 
void loop( const std::string& path, 
	   const std::vector<std::string>& type, 
	   const std::vector<std::string>& samples, 
	   const std::vector<std::string>& dirs, 
	   const std::vector<std::string>& histos,
	   double lumi,
	   bool log = false, 
	   bool scale = false ) {
  
//   // Create output file
//   TFile* file = new TFile( "Plots2D.root", "RECREATE" );
//   if ( !file || file->IsZombie() ) { return; }
  
  // Check
  if ( dirs.size() != histos.size() ) {
    std::cout << "dirs.size() != histos.size()" << std::endl;
    abort();
  }
  
  // Create plots
  for ( int i = 0; i < histos.size(); ++i ) { 
    for ( int j = 0; j < samples.size(); ++j ) { 
      for ( int k = 0; k < type.size(); ++k ) { 
	std::cout << "SAMPLE: " << samples[j] << std::endl;
	
	plot( path.c_str(),
	      type[k].c_str(),
	      samples[j].c_str(),
	      dirs[i].c_str(),
	      histos[i].c_str(),
	      lumi,
	      log,
	      scale );
      }
    }
  }
  
//   file->cd();
//   file->Write();
//   file->Close();
//   delete file; 
  
}

// -----------------------------------------------------------------------------
// Top-level method
void dalitz_qcd() {

  setTDRStyle();
  set_plot_style();

  std::string path = "../../results/batch/110121_1/100_100_50/";
  //std::string path = "~/Desktop/work/temp/truth/";
  
  std::vector<std::string> type;
  type.push_back("Ratio");
  
  std::vector<std::string> dirs;
  std::vector<std::string> histos;
  std::vector<std::string> samples;

  double lumi = 100.;

  samples.push_back("lm1");
  
  if (1) {
    dirs.push_back("Dalitz");
    //histos.push_back("PostMeffDalitz_Meff500_4");
    histos.push_back("PostMeffRhoRho_Meff500_2");
  }

  loop( path, type, samples, dirs, histos, lumi, true, false );
  
}

