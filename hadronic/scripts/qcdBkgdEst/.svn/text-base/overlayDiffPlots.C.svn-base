#include "style.C"
#include <TCanvas.h>
#include <TFile.h>
#include <TH1D.h>
#include <TLegend.h>
#include <TString.h>
#include <vector>
#include <iostream>

typedef unsigned int uint;

// -----------------------------------------------------------------------------
//
TCanvas* createCanvas(TString name,TDirectory* afile, bool log)
{
  afile->cd();
  TCanvas* aCanvas = new TCanvas(name);
  //gStyle->SetOptFit(1);
  //gStyle->SetOptStat(0);
  aCanvas->Range(-288.2483,-2.138147,1344.235,6.918939);
  aCanvas->SetFillColor(0);
  aCanvas->SetBorderMode(0);
  aCanvas->SetBorderSize(2);
  if ( log == true)aCanvas->SetLogy();
  aCanvas->SetLeftMargin(0.1765705);
  aCanvas->SetRightMargin(0.05772496);
  aCanvas->SetTopMargin(0.04778761);
  aCanvas->SetBottomMargin(0.1256637);
  aCanvas->SetFrameFillStyle(0);
  aCanvas->SetFrameLineWidth(2);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameFillStyle(0);
  aCanvas->SetFrameLineWidth(2);
  aCanvas->SetFrameBorderMode(0);
 
  
  return aCanvas;
}

// -----------------------------------------------------------------------------
//
TH1* getHisto( TString path,
	       TString nameHist,
	       TString nameFile,
	       TString Dirname, 
	       int rebin ) {
  TString name = path + nameFile;
  TFile* file =  new TFile(name);
  if (file) { std::cout << "Opened file: " << file->GetName() << std::endl; }
  else { 
    std::cout << "Could not find file: " << name << std::endl; 
    return 0; 
  }
  
  TDirectory* dir = (TDirectory*)file->Get(Dirname);
  if (dir) { std::cout << "Opened dir: " << dir->GetName() << std::endl; }
  else { 
    std::cout << "Could not find dir: " << Dirname << std::endl; 
    return 0; 
  }
  
  TH1* hist = (TH1*)dir->Get(nameHist);
  if (hist) { std::cout << "Opened histo: " << hist->GetName() << std::endl; }
  else { 
    std::cout << "Could not find histo: " << nameHist << std::endl; 
    return 0; 
  }

  hist->SetLineWidth(3);
  if ( rebin > 0 ) { hist->Rebin(rebin); }
  hist->GetXaxis()->SetTitleSize(0.055);
  hist->GetYaxis()->SetTitleSize(0.055);
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetLabelSize(0.05);
  hist->SetStats(kFALSE);
  return hist;
}

// -----------------------------------------------------------------------------
//
TCanvas* createPlot( TString path, 
		     TString canvas_name, 
		     std::vector<TString> names, 
		     TString dirmame, 
		     int rebin, 
		     bool norm, 
		     bool log,
		     TDirectory* file,
		     double min = -1.,
		     double max = -1. )
{

  // SetSomeStyles();

  // Create legend
  TLegend* legend = new TLegend( 0.65, 0.75, 0.92, 0.95, NULL, "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0); 
  
  // Create canvas
  TCanvas* aCanvas = createCanvas( canvas_name, file, log );

  // First histo be drawn
  bool first = true;
  
  // Loop through histogram names
  std::vector<TH1D*> his;
  for ( uint iname = 0; iname < names.size(); ++iname ) {
    his.push_back( (TH1D*)getHisto( path, names[iname], "QcdBkgdEst_qcd.root", dirmame, rebin ) );
  }
  
  // Loop through histograms
  double aMax = 0.;
  double aMin = 1.e12;
  for ( uint ihis = 0; ihis < his.size(); ++ihis ) {

    if ( !his[ihis] ) { continue; }
    
    // Line colour and fill
    his[ihis]->SetLineColor(1+ihis);
    his[ihis]->SetLineStyle(1);
    his[ihis]->SetLineWidth(1);

    // Populate legend
    legend->AddEntry( his[ihis], names[ihis], "L" );
    
    // Calc min/max number of entries
    if ( his[ihis]->GetMaximum() > aMax ) { aMax = his[ihis]->GetMaximum(); }
    if ( his[ihis]->GetMinimum(1.e-12) < aMin ) { aMin = his[ihis]->GetMinimum(1.e-12); }

  }

  if ( !his.empty() ) {
    if ( his[0] ) his[0]->GetYaxis()->SetTitleOffset(1.43);
    if ( his[0] ) his[0]->GetYaxis()->SetTitleSize(0.06);
    if ( his[0] ) his[0]->GetXaxis()->SetTitleSize(0.06);
    if ( his[0] ) his[0]->GetXaxis()->SetTitleOffset(0.9);
  }

  for ( uint ihis = 0; ihis < his.size(); ++ihis ) {

    if ( !his[ihis] ) { continue; }
    
    if ( log ) {
      his[ihis]->SetMaximum( aMax * 10. );
      his[ihis]->SetMinimum( aMin * 0.1 );
    } else {
      his[ihis]->SetMaximum( aMax * 1.1 );
      his[ihis]->SetMinimum( aMin * 0.9 );
    }

    if ( min > 0. ) his[ihis]->SetMinimum( min );
    if ( max > 0. ) his[ihis]->SetMaximum( max );
    
    if ( norm ) {
      TString options = "";
      if ( first ) { options = "Ehist"; first = false; }
      else { options = "hsame"; }
      if ( his[ihis]->GetEntries() > 0. ) { his[ihis]->DrawNormalized(options); }
    } else {
      TString options = "";
      if ( first ) { options = "h"; first = false; }
      else { options = "hsame"; }
      his[ihis]->Draw(options);
    }
    
  } // Loop through histos

  file->cd();
  legend->Draw("same");
  aCanvas->Modified();
  aCanvas->SaveAs( std::string(canvas_name+".png").c_str() );
  aCanvas->SaveAs( std::string(canvas_name+".C").c_str() );
  aCanvas->Write();
  return aCanvas;

}

// -----------------------------------------------------------------------------
//
TCanvas* createPlot( TString path, 
		     TString canvas_name, 
		     TString name, 
		     TString dirmame, 
		     int rebin, 
		     bool norm, 
		     bool log,
		     TDirectory* file,
		     double min = -1.,
		     double max = -1. )
{
  std::vector<TString> names;
  names.push_back(name);
  return createPlot( path, 
		     canvas_name, 
		     names, 
		     dirmame, 
		     rebin, 
		     norm, 
		     log,
		     file,
		     min,
		     max );
}

// -----------------------------------------------------------------------------
/*
  Arguments to createPlot():
  - path to input files
  - canvas title
  - histogram title
  - histogram directory
  - rebin histograms?
  - normalize all histograms to unit area?
  - logarithmic y-scale
  - output file
  - min for y-axis (optiional)
  - max for y-axis (optiional)
*/  
int overlayDiffPlots() {

  setTDRStyle();

  // Path to input files
  TString path("../../../results/batch/101026_1/100_100_50/");

  // Output file
  TFile* output = new TFile( "Plots.root", "RECREATE" );
  if ( !output || output->IsZombie() ) { return -1; }

    
  //std::string histo = "BabyCaloOverMeffAfterDeadEcal";
//   std::string histo = "BabyPfOverMeffAfterDeadEcal";
   std::string histo = "BabyMhtOverMetAfterDeadEcal";
//    std::string histo = "GenBabyOverMeffNoMet";
//   std::string histo = "GenBabyMhtOverMetNoMet";

   std::string bin0 = "HT250";
   std::string bin1 = "HT300";
   std::string bin2 = "HT350";

//    std::string bin0 = "Meff400";
//    std::string bin1 = "Meff450";
//    std::string bin2 = "Meff500";

  // ---------- diff ht bins ----------

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin0+"_aT0.5_all");
    names.push_back(histo+"_"+bin0+"_aT0.51_all");
    names.push_back(histo+"_"+bin0+"_aT0.52_all");
    names.push_back(histo+"_"+bin0+"_aT0.53_all");
    names.push_back(histo+"_"+bin0+"_aT0.54_all");
    names.push_back(histo+"_"+bin0+"_aT0.55_all");
    createPlot( path, histo+"_HT250", names, "QcdBkgdEst", 2, false, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin1+"_aT0.5_all");
    names.push_back(histo+"_"+bin1+"_aT0.51_all");
    names.push_back(histo+"_"+bin1+"_aT0.52_all");
    names.push_back(histo+"_"+bin1+"_aT0.53_all");
    names.push_back(histo+"_"+bin1+"_aT0.54_all");
    names.push_back(histo+"_"+bin1+"_aT0.55_all");
    createPlot( path, histo+"_HT300", names, "QcdBkgdEst", 2, false, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin2+"_aT0.5_all");
    names.push_back(histo+"_"+bin2+"_aT0.51_all");
    names.push_back(histo+"_"+bin2+"_aT0.52_all");
    names.push_back(histo+"_"+bin2+"_aT0.53_all");
    names.push_back(histo+"_"+bin2+"_aT0.54_all");
    names.push_back(histo+"_"+bin2+"_aT0.55_all");
    createPlot( path, histo+"_HT350", names, "QcdBkgdEst", 2, false, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin0+"_aT0.51_all");
    names.push_back(histo+"_"+bin1+"_aT0.51_all");
    names.push_back(histo+"_"+bin2+"_aT0.51_all");
    createPlot( path, histo+"_Check0.51", names, "QcdBkgdEst", 2, true, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin0+"_aT0.52_all");
    names.push_back(histo+"_"+bin1+"_aT0.52_all");
    names.push_back(histo+"_"+bin2+"_aT0.52_all");
    createPlot( path, histo+"_Check0.52", names, "QcdBkgdEst", 2, true, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin0+"_aT0.53_all");
    names.push_back(histo+"_"+bin1+"_aT0.53_all");
    names.push_back(histo+"_"+bin2+"_aT0.53_all");
    createPlot( path, histo+"_Check0.53", names, "QcdBkgdEst", 2, true, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin0+"_aT0.54_all");
    names.push_back(histo+"_"+bin1+"_aT0.54_all");
    names.push_back(histo+"_"+bin2+"_aT0.54_all");
    createPlot( path, histo+"_Check0.54", names, "QcdBkgdEst", 2, true, true, output );
  }

  if (1) {
    std::vector<TString> names;
    names.push_back(histo+"_"+bin0+"_aT0.55_all");
    names.push_back(histo+"_"+bin1+"_aT0.55_all");
    names.push_back(histo+"_"+bin2+"_aT0.55_all");
    createPlot( path, histo+"_Check0.55", names, "QcdBkgdEst", 2, true, true, output );
  }


  // --------------------------------------------------------------------------------

  if (0) {
    std::vector<TString> names;
    names.push_back("GenBabyOverHtNoMet_HT250_aT0.5_all");
    names.push_back("GenBabyOverHtNoMet_HT250_aT0.51_all");
    names.push_back("GenBabyOverHtNoMet_HT250_aT0.52_all");
    names.push_back("GenBabyOverHtNoMet_HT250_aT0.53_all");
    names.push_back("GenBabyOverHtNoMet_HT250_aT0.54_all");
    names.push_back("GenBabyOverHtNoMet_HT250_aT0.55_all");
    createPlot( path, "GenBabyOverHtNoMet", names, "QcdBkgdEst", 1, true, true, output );
  }

  if (0) {
    std::vector<TString> names;
    //names.push_back("HtMultiplicity_HT0");
    names.push_back("HtMultiplicity_HT250");
    names.push_back("HtMultiplicity_HT300");
    names.push_back("HtMultiplicity_HT350");
    createPlot( path, "HtMultiplicity", names, "QcdBkgdEst", 1, true, true, output );
  }

  if (0) {
    std::vector<TString> names;
    //names.push_back("GenHtMultiplicity_HT0");
    names.push_back("GenHtMultiplicity_HT250");
    names.push_back("GenHtMultiplicity_HT300");
    names.push_back("GenHtMultiplicity_HT350");
    createPlot( path, "GenHtMultiplicity", names, "QcdBkgdEst", 1, false, true, output );
  }
  
  if (0) {
    std::vector<TString> names;
    names.push_back("GenBabyOverHt_Ht0_aT0_all");
    names.push_back("GenBabyOverHt_Ht0_aT0.5_all");
    names.push_back("GenBabyOverHt_Ht0_aT0.51_all");
    names.push_back("GenBabyOverHt_Ht0_aT0.52_all");
    names.push_back("GenBabyOverHt_Ht0_aT0.53_all");
    names.push_back("GenBabyOverHt_Ht0_aT0.54_all");
    names.push_back("GenBabyOverHt_Ht0_aT0.55_all");
    createPlot( path, "GenBabyOverHt_VsAlphaT", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("GenBabyOverHt_HT250_aT0_all");
    names.push_back("GenBabyOverHt_HT350_aT0_all");
    names.push_back("GenBabyOverHt_HT250_aT0.5_all");
    names.push_back("GenBabyOverHt_HT350_aT0.5_all");
    names.push_back("GenBabyOverHt_HT250_aT0.51_all");
    names.push_back("GenBabyOverHt_HT350_aT0.51_all");
    names.push_back("GenBabyOverHt_HT250_aT0.52_all");
    names.push_back("GenBabyOverHt_HT350_aT0.52_all");
    createPlot( path, "GenBabyOverHt_Vs_Ht_VsAlphaT", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverHt_Ht0_aT0_all");
    names.push_back("BabyOverHt_Ht0_aT0.5_all");
    names.push_back("BabyOverHt_Ht0_aT0.51_all");
    names.push_back("BabyOverHt_Ht0_aT0.52_all");
    names.push_back("BabyOverHt_Ht0_aT0.53_all");
    names.push_back("BabyOverHt_Ht0_aT0.54_all");
    names.push_back("BabyOverHt_Ht0_aT0.55_all");
    createPlot( path, "BabyOverHt_VsAlphaT", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverHt_HT250_aT0_all");
    names.push_back("BabyOverHt_HT350_aT0_all");
    names.push_back("BabyOverHt_HT250_aT0.5_all");
    names.push_back("BabyOverHt_HT350_aT0.5_all");
    names.push_back("BabyOverHt_HT250_aT0.51_all");
    names.push_back("BabyOverHt_HT350_aT0.51_all");
    names.push_back("BabyOverHt_HT250_aT0.52_all");
    names.push_back("BabyOverHt_HT350_aT0.52_all");
    createPlot( path, "BabyOverHt_Vs_Ht_VsAlphaT", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverHt_Ht0_aT0_all");
    names.push_back("BabyOverHt_HT250_aT0_all");
    names.push_back("BabyOverHt_HT300_aT0_all");
    names.push_back("BabyOverHt_HT350_aT0_all");
    createPlot( path, "BabyJets_Ht", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverHt_Ht0_aT0.51_all");
    names.push_back("BabyOverHt_HT250_aT0.51_all");
    names.push_back("BabyOverHt_HT300_aT0.51_all");
    names.push_back("BabyOverHt_HT350_aT0.51_all");
    createPlot( path, "BabyJets_Ht", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverHt_Ht0_aT0.52_all");
    names.push_back("BabyOverHt_HT250_aT0.52_all");
    names.push_back("BabyOverHt_HT300_aT0.52_all");
    names.push_back("BabyOverHt_HT350_aT0.52_all");
    createPlot( path, "BabyJets_Ht", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverMeff_Meff0_aT0_all");
    names.push_back("BabyOverMeff_Meff400_aT0_all");
    names.push_back("BabyOverMeff_Meff450_aT0_all");
    names.push_back("BabyOverMeff_Meff500_aT0_all");
    createPlot( path, "BabyJets_Meff", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverMeff_Meff0_aT0.51_all");
    names.push_back("BabyOverMeff_Meff400_aT0.51_all");
    names.push_back("BabyOverMeff_Meff450_aT0.51_all");
    names.push_back("BabyOverMeff_Meff500_aT0.51_all");
    createPlot( path, "BabyJets_Meff", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("BabyOverMeff_Meff0_aT0.52_all");
    names.push_back("BabyOverMeff_Meff400_aT0.52_all");
    names.push_back("BabyOverMeff_Meff450_aT0.52_all");
    names.push_back("BabyOverMeff_Meff500_aT0.52_all");
    createPlot( path, "BabyJets_Meff", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("GenBabyOverHt_Ht0_aT0_all");
    names.push_back("GenBabyOverHt_HT250_aT0_all");
    names.push_back("GenBabyOverHt_HT300_aT0_all");
    names.push_back("GenBabyOverHt_HT350_aT0_all");
    createPlot( path, "GenBabyJets_Ht", names, "QcdBkgdEst", 5, false, true, output );
  }

  if (0) {
    std::vector<TString> names;
    names.push_back("GenBabyOverMeff_Meff0_aT0_all");
    names.push_back("GenBabyOverMeff_Meff400_aT0_all");
    names.push_back("GenBabyOverMeff_Meff450_aT0_all");
    names.push_back("GenBabyOverMeff_Meff500_aT0_all");
    createPlot( path, "GenBabyJets_Meff", names, "QcdBkgdEst", 5, false, true, output );
  }

  output->Write();
  output->Close();
  delete output; 

  return 0;

}


