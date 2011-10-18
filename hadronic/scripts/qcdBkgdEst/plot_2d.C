#include <TCanvas.h>
#include <TDirectory.h>
#include <TFile.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TPaletteAxis.h>
#include <TPaveStats.h>
#include <TStyle.h>
#include <iostream>
#include <sstream>
#include <string>

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

  // Retrieve histogram
  std::string file_name = path + type + "_" + sample + ".root";
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
  
  //his->Rebin2D(2,2);

  if ( log ) { gPad->SetLogz(); }
  if ( scale ) his->Scale( lumi / 100. );
  //his->SetMaximum(1.e4);
  //his->SetMinimum(1.e0);
  //his->SetMinimum( his->GetMinimum(1.e-12) );

//   his->SetMaximum( 20000. );
//   his->SetMinimum( 2.e-4 );

//   his->SetMaximum( 20000. );
//   his->SetMinimum( 20. );

  double xmin = his->GetXaxis()->GetXmin();
  double xmax = his->GetXaxis()->GetXmax();
  double ymin = his->GetYaxis()->GetXmin();
  double ymax = his->GetYaxis()->GetXmax();
  
  // Reset title
  std::string title = ";" + std::string(his->GetXaxis()->GetTitle()) + ";" + std::string(his->GetYaxis()->GetTitle());
  his->SetTitle(title.c_str());
  //his->GetXaxis()->SetTitle("x_{2}");
  his->GetXaxis()->SetTitleOffset(1.2);
  //his->GetYaxis()->SetTitle("x_{1}");
  his->GetYaxis()->SetTitleOffset(1.4);
  his->Draw("COLZ");
  gPad->Update();

  // Lumi
  if (1) { 
    std::stringstream ss;

    ss << "#int L dt = " << lumi << " pb^{-1}";
    double xpos = 0.05 * (xmax-xmin)+xmin;
    double ypos = 0.25 * (ymax-ymin)+ymin;
    TLatex* text1 = new TLatex(xpos,ypos,ss.str().c_str());
    text1->SetTextAlign(12); 
    text1->SetTextSize(0.035);
    text1->Draw();
  }

  // Sample
  if (1) {
    double xpos = 0.05 * (xmax-xmin)+xmin;
    double ypos = 0.15 * (ymax-ymin)+ymin;
    TText* text3 = new TText(xpos,ypos,sample.c_str());
    text3->SetTextAlign(12); 
    text3->SetTextSize(0.035);
    text3->Draw();
  }

  // Jet type
  if (0) { 
    double xpos = 0.05 * (xmax-xmin)+xmin;
    double ypos = 0.10 * (ymax-ymin)+ymin;
    TText* text2 = new TText(xpos,ypos,type.c_str());
    text2->SetTextAlign(12); 
    text2->SetTextSize(0.035);
    text2->Draw();
  }

  // Stats
  gStyle->SetOptStat("i");
  his->SetStats(1);
  TPaveStats* stats = (TPaveStats*)his->GetListOfFunctions()->FindObject("stats"); 
  std::string stats_pos = "br";
  if ( stats ) { 
    stats->SetFillColor(0);
    stats->SetLineColor(0); 
    stats->SetShadowColor(0); 
    if ( stats_pos == "tr" ) {
      stats->SetX1NDC(0.60); stats->SetY1NDC(0.68); stats->SetX2NDC(0.83); stats->SetY2NDC(0.88); 
    } else if ( stats_pos == "br" ) {
      stats->SetX1NDC(0.60); stats->SetY1NDC(0.18); stats->SetX2NDC(0.83); stats->SetY2NDC(0.28); 
    } else {
      stats->SetX1NDC(0.60); stats->SetY1NDC(0.68); stats->SetX2NDC(0.83); stats->SetY2NDC(0.88); 
    }
  }

   // Scale
  gStyle->SetPalette(1);
  TPaletteAxis* palette = (TPaletteAxis*)his->GetListOfFunctions()->FindObject("palette");
  if ( palette ) {
    palette->SetY1NDC(0.2);
    palette->SetY2NDC(0.8);
  }

  canvas->Modified();
  canvas->cd();
  canvas->SetSelected(canvas);
  canvas->SaveAs(std::string(canvas_name+".png").c_str());
  //canvas->Write();

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
  
  // Create output file
  TFile* file = new TFile( "Plots2D.root", "RECREATE" );
  if ( !file || file->IsZombie() ) { return; }

  // Check
  if ( dirs.size() != histos.size() ) {
    std::cout << "dirs.size() != histos.size()" << std::endl;
    abort();
  }

  // Create plots
  for ( uint i = 0; i < histos.size(); ++i ) { 
    for ( uint j = 0; j < samples.size(); ++j ) { 
      for ( uint k = 0; k < type.size(); ++k ) { 
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
  
  file->cd();
  file->Write();
  file->Close();
  delete file; 
  
}

// -----------------------------------------------------------------------------
// Top-level method
void plot_2d() {
  
  std::string path = "../../../results/batch/101028b_1/100_100_50/";
  
  std::vector<std::string> type;
  type.push_back("QcdBkgdEst");

  std::vector<std::string> dirs;
  std::vector<std::string> histos;
  std::vector<std::string> samples;

  double lumi = 15.1;

  // ---------- mSUGRA ----------

  bool msugra = true;
  if (msugra) {

    // Samples to be used
    samples.push_back("tanB10");
  
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("MSUGRA_HT0_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("MSUGRA_HT250_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("MSUGRA_HT300_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("MSUGRA_HT350_all");
    }

    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenMSUGRA_HT0_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenMSUGRA_HT250_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenMSUGRA_HT300_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenMSUGRA_HT350_all");
    }
    
    // Create MC plots
    loop( path, type, samples, dirs, histos, lumi, false, true );
    
  }

  // ---------- MC ----------

  bool mc = false;
  if (mc) {

    // Samples to be used
    samples.push_back("qcd");
  
    // Dalitz from truth, no baby jet cut, so "spilling over"
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenHtDalitzNoMet_HT250_2");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenHtDalitzNoMet_HT300_2");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenHtDalitzNoMet_HT350_2");
    }

    // Dalitz from truth, with baby jet cut, so NO "spilling over"
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenHtDalitzNoMetAfterBaby_HT250_2");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenHtDalitzNoMetAfterBaby_HT300_2");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("GenHtDalitzNoMetAfterBaby_HT350_2");
    }

    // Create MC plots
    loop( path, type, samples, dirs, histos, lumi, true, true );

  }

  // ---------- Data ----------

  bool data = false;
  if (data) {

    dirs.clear();
    histos.clear();
    samples.clear();

    samples.push_back("data");

    // Dalitz from reco
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitz_HT350_2");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterBaby_HT350_2");
    }
    
    // Dalitz from reco
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitz_HT250_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitz_HT300_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitz_HT350_all");
    }
    
    // Dalitz from reco, after dead ECAL
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterDeadEcal_HT250_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterDeadEcal_HT300_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterDeadEcal_HT350_all");
    }

    // Dalitz from reco, after baby jet cut
    if (1) {
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterBaby_HT250_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterBaby_HT300_all");
      dirs.push_back("QcdBkgdEst");
      histos.push_back("HtDalitzAfterBaby_HT350_all");
    }

    // Create MC plots
    loop( path, type, samples, dirs, histos, lumi, true, false );

  }
  
}

