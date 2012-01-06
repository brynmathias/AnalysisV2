#include <string>

// -----------------------------------------------------------------------------
// Top-level method
void plot_2d() {
  
  std::string path = "/vols/cms02/bainbrid/SUSYv2/results/data-mc-comparison/";
  
  // Jet algorithm and type (IC5Calo,AK5Calo,AK5JPT,AK5PF)
  std::vector<std::string> type;
  type.push_back("AK5Calo");
  
  // Directories and names of histograms
  std::vector<std::string> dirs;
  std::vector<std::string> histos;
  
  dirs.push_back("Dalitz_150_250");
  histos.push_back("DalitzRho2");
  dirs.push_back("Dalitz_150_250");
  histos.push_back("DalitzRho3");
  dirs.push_back("Dalitz_150_250");
  histos.push_back("DalitzRhoN");

  dirs.push_back("Dalitz_250_350");
  histos.push_back("DalitzRho2");
  dirs.push_back("Dalitz_250_350");
  histos.push_back("DalitzRho3");
  dirs.push_back("Dalitz_250_350");
  histos.push_back("DalitzRhoN");
  
  dirs.push_back("Dalitz_350");
  histos.push_back("DalitzRho2");
  dirs.push_back("Dalitz_350");
  histos.push_back("DalitzRho3");
  dirs.push_back("Dalitz_350");
  histos.push_back("DalitzRhoN");

  dirs.push_back("Dalitz_Inclusive");
  histos.push_back("DalitzRho2");
  dirs.push_back("Dalitz_Inclusive");
  histos.push_back("DalitzRho3");
  dirs.push_back("Dalitz_Inclusive");
  histos.push_back("DalitzRhoN");

  // Samples to be used
  std::vector<std::string> samples;
  samples.push_back("JetMET_ALL_upto230810");

  // Create data plots
  loop( path, type, samples, dirs, histos, 1.096, false );

  samples.clear();
  samples.push_back("LM0");
  samples.push_back("LM1");
  samples.push_back("QCD_AllPtBins_7TeV_Pythia6");
  samples.push_back("WJets-madgraph");
  samples.push_back("ZJets-madgraph");
  samples.push_back("ttbarTauola");
  samples.push_back("BkgdOnly");
  //samples.push_back("Zinvisible_jets");
  
  // Create MC plots
  loop( path, type, samples, dirs, histos, 1.096, true );
  
}

// -----------------------------------------------------------------------------
// Loop over files and histograms 
void loop( const std::string& path, 
	   const std::vector<std::string>& type, 
	   const std::vector<std::string>& samples, 
	   const std::vector<std::string>& dirs, 
	   const std::vector<std::string>& histos,
	   double lumi,
	   bool scale = false ) {
  
  // Create output file
  TFile* file = new TFile( "Plots2D.root", "RECREATE" );
  if ( !file || file->IsZombie() ) { return -1; }

  // Check
  if ( dirs.size() != histos.size() ) {
    std::cout << "dirs.size() != histos.size()" << std::endl;
    abort();
  }

  // Create plots
  for ( int i = 0; i < histos.size(); ++i ) { 
    for ( int j = 0; j < samples.size(); ++j ) { 
      for ( int k = 0; k < type.size(); ++k ) { 
	plot( path.c_str(),
	      type[k].c_str(),
	      samples[j].c_str(),
	      dirs[i].c_str(),
	      histos[i].c_str(),
	      lumi,
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
// Create plots
void plot( std::string& path, 
	   std::string& type, 
	   std::string& sample, 
	   std::string& dir, 
	   std::string& histo,
	   double lumi,
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
  TDirectory* d = (TDirectory*)f->Get(dir.c_str());
  TH2D* his = (TH1*)d->Get(histo.c_str());
  if ( !his ) return;

  //his->Rebin2D(2,2);

  if ( true ) { gPad->SetLogz(); }
  if ( scale ) his->Scale( lumi / 100. );
  his->SetMaximum(1.e4);
  his->SetMinimum(1.e-5);
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
  his->GetXaxis()->SetTitle("x_{2}");
  his->GetXaxis()->SetTitleOffset(1.2);
  his->GetYaxis()->SetTitle("x_{1}");
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

  // Jet type
  if (1) { 
    double xpos = 0.05 * (xmax-xmin)+xmin;
    double ypos = 0.15 * (ymax-ymin)+ymin;
    TText* text2 = new TText(xpos,ypos,type.c_str());
    text2->SetTextAlign(12); 
    text2->SetTextSize(0.035);
    text2->Draw();
  }

  // Sample
  if (1) {
    double xpos = 0.05 * (xmax-xmin)+xmin;
    double ypos = 0.10 * (ymax-ymin)+ymin;
    TText* text3 = new TText(xpos,ypos,sample.c_str());
    text3->SetTextAlign(12); 
    text3->SetTextSize(0.035);
    text3->Draw();
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

