#include <TCanvas.h>
#include <TFile.h>
#include <TH1D.h>
#include <TLegend.h>
#include <TString.h>
#include <vector>
#include <iostream>

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
  TDirectory* dir = file ? (TDirectory*)file->Get(Dirname) : 0;
  TH1* hist = dir ? (TH1*)dir->Get(nameHist) : 0;
  if (!hist) {
    std::cout << " path: " << path
	      << " name: " << nameHist
	      << " file: " << nameFile
	      << " dir: " <<  Dirname
	      << std::endl;
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
		     TString name, 
		     TString dirmame, 
		     int rebin, 
		     bool norm, 
		     bool log,
		     TDirectory* file,
		     double lumi = -1.,
		     double min = -1.,
		     double max = -1. )
{

  // SetSomeStyles();

  // Create legend
  TLegend* legend = new TLegend( 0.75, 0.65, 0.92, 0.92, NULL, "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0); 
  
  // Create canvas
  TCanvas* aCanvas = createCanvas( canvas_name, file, log );

  // First histo be drawn
  bool first = true;
  
  // Create histograms
  TH1D* data  = 0;
  TH1D* qcd   = 0;
  TH1D* phot  = 0;
  TH1D* ttbar = 0;
  TH1D* wjets = 0;
  TH1D* zinv  = 0;
  TH1D* lm0   = 0;
  TH1D* lm1   = 0;

  data  = (TH1D*)getHisto( path, name, "QcdBkgdEst_data.root", dirmame, rebin );
  qcd   = (TH1D*)getHisto( path, name, "QcdBkgdEst_qcd.root", dirmame, rebin );
  ttbar = (TH1D*)getHisto( path, name, "QcdBkgdEst_ttbar.root", dirmame, rebin );
  wjets = (TH1D*)getHisto( path, name, "QcdBkgdEst_wjets.root", dirmame, rebin );
  zinv  = (TH1D*)getHisto( path, name, "QcdBkgdEst_zinv.root", dirmame, rebin );
  lm0   = (TH1D*)getHisto( path, name, "QcdBkgdEst_lm0.root", dirmame, rebin );
  lm1   = (TH1D*)getHisto( path, name, "QcdBkgdEst_lm1.root", dirmame, rebin );

  // Line colour and fill
  if ( data ) data->SetMarkerColor(kBlack);
  if ( data ) data->SetMarkerStyle(21);
  if ( data ) data->SetMarkerSize(0.8);
  if ( data ) data->SetLineWidth(1);
  //if ( qcd ) qcd->SetLineColor(kGreen+2);
  //if ( qcd ) qcd->SetFillColor(kGreen+2);
  //if ( qcd ) qcd->SetFillStyle(3003);
  if ( qcd ) qcd->SetLineColor(kGreen+2);
  if ( qcd ) qcd->SetLineStyle(1);
  if ( qcd ) qcd->SetLineWidth(1);
  if ( phot ) phot->SetLineColor(kOrange);
  if ( phot ) phot->SetLineStyle(1);
  if ( phot ) phot->SetLineWidth(1);
  if ( ttbar ) ttbar->SetLineColor(kBlue);
  if ( ttbar ) ttbar->SetLineStyle(1);
  if ( ttbar ) ttbar->SetLineWidth(1);
  if ( wjets ) wjets->SetLineColor(kBlue);
  if ( wjets ) wjets->SetLineStyle(3);
  if ( wjets ) wjets->SetLineWidth(1);
  if ( zinv ) zinv->SetLineColor(kMagenta);
  if ( zinv ) zinv->SetLineStyle(1);
  if ( zinv ) zinv->SetLineWidth(1);
  if ( lm0 ) lm0->SetLineColor(kRed);
  if ( lm0 ) lm0->SetLineStyle(1);
  if ( lm0 ) lm0->SetLineWidth(3);
  if ( lm1 ) lm1->SetLineColor(kRed);
  if ( lm1 ) lm1->SetLineStyle(3);
  if ( lm1 ) lm1->SetLineWidth(3);
  
  // Populate legend
  if ( data ) legend->AddEntry( data, " Data", "P" );
  if ( lm0 ) legend->AddEntry( lm0, " SUSY LM0", "L" );
  if ( lm1 ) legend->AddEntry( lm1, " SUSY LM1", "L" );
  if ( qcd ) legend->AddEntry( qcd, " QCD", "f" );
  if ( phot ) legend->AddEntry( phot, " #gamma+jet", "L" );
  if ( ttbar ) legend->AddEntry( ttbar, " t#bar{t}", "L" );
  if ( wjets ) legend->AddEntry( wjets, " W", "L" );
  if ( zinv ) legend->AddEntry( zinv, " Z#rightarrow#nu#nu", "L" );

  // Scale to lumi
  if ( lumi > 0. ) {
    if ( qcd ) qcd->Scale(lumi/100.);
    if ( lm0 ) lm0->Scale(lumi/100.);
    if ( lm1 ) lm1->Scale(lumi/100.);
    if ( ttbar ) ttbar->Scale(lumi/100.);
    if ( wjets) wjets->Scale(lumi/100.);
    if ( zinv ) zinv->Scale(lumi/100.);
  } 
  
  // Calc maximum number of entries
  double aMax = -1.e12;
  if ( data && data->GetMaximum() > aMax ) { aMax = data->GetMaximum(); }
  if ( qcd && qcd->GetMaximum() > aMax ) { aMax = qcd->GetMaximum(); }
  if ( phot && phot->GetMaximum() > aMax ) { aMax = phot->GetMaximum(); }
  if ( lm0 && lm0->GetMaximum() > aMax ) { aMax = lm0->GetMaximum(); }
  if ( lm1 && lm1->GetMaximum() > aMax ) { aMax = lm1->GetMaximum(); }
  if ( ttbar && ttbar->GetMaximum() > aMax ) { aMax = ttbar->GetMaximum(); }  
  if ( wjets && wjets->GetMaximum() > aMax ) { aMax = wjets->GetMaximum(); }  
  if ( zinv && zinv->GetMaximum() > aMax ) { aMax = zinv->GetMaximum(); }  

  // Calc minimum number of entries
  double aMin = 1.e12;
  if ( data && data->GetMinimum(1.e-12) < aMin ) { aMin = data->GetMinimum(1.e-12); }
  if ( qcd && qcd->GetMinimum(1.e-12) < aMin ) { aMin = qcd->GetMinimum(1.e-12); }
  if ( phot && phot->GetMinimum(1.e-12) < aMin ) { aMin = phot->GetMinimum(1.e-12); }
  if ( lm0 && lm0->GetMinimum(1.e-12) < aMin ) { aMin = lm0->GetMinimum(1.e-12); }
  if ( lm1 && lm1->GetMinimum(1.e-12) < aMin ) { aMin = lm1->GetMinimum(1.e-12); }
  if ( ttbar && ttbar->GetMinimum(1.e-12) < aMin ) { aMin = ttbar->GetMinimum(1.e-12); }  
  if ( wjets && wjets->GetMinimum(1.e-12) < aMin ) { aMin = wjets->GetMinimum(1.e-12); }  
  if ( zinv && zinv->GetMinimum(1.e-12) < aMin ) { aMin = zinv->GetMinimum(1.e-12); }  

  if ( qcd ) qcd->GetYaxis()->SetTitleOffset(1.43);
  if ( qcd ) qcd->GetYaxis()->SetTitleSize(0.06);
  if ( qcd ) qcd->GetXaxis()->SetTitleSize(0.06);
  if ( qcd ) qcd->GetXaxis()->SetTitleOffset(0.9);

  if ( log ) {
    if ( qcd ) qcd->SetMaximum( aMax * 10. );
    if ( qcd ) qcd->SetMinimum( aMin * 0.1 );
  } else {
    if ( qcd ) qcd->SetMaximum( aMax * 1.1 );
    if ( qcd ) qcd->SetMinimum( aMin * 0.9 );
  }

  if ( qcd && min > 0. ) qcd->SetMinimum( min );
  if ( qcd && max > 0. ) qcd->SetMaximum( max );
  
  if ( norm ) {
    if ( qcd && qcd->GetEntries() > 0. ) { qcd->DrawNormalized("Ehist"); }
    if ( data && data->GetEntries() > 0. ) { data->DrawNormalized("psame"); }
    if ( lm0 && lm0->GetEntries() > 0. ) { lm0->DrawNormalized("hsame"); }
    if ( lm1 && lm1->GetEntries() > 0. ) { lm1->DrawNormalized("hsame"); }
    if ( ttbar && ttbar->GetEntries() > 0. ) { ttbar->DrawNormalized("hsame"); }
    if ( wjets && wjets->GetEntries() > 0. ) { wjets->DrawNormalized("hsame"); }
    if ( zinv && zinv->GetEntries() > 0. ) { zinv->DrawNormalized("hsame"); }
  } else {
    if ( qcd ) qcd->Draw("h");
    if ( data ) data->Draw("psame");
    if ( lm0 ) lm0->Draw("hsame");
    if ( lm1 ) lm1->Draw("hsame");
    if ( ttbar ) ttbar->Draw("hsame");
    if ( wjets) wjets->Draw("hsame");
    if ( zinv ) zinv->Draw("hsame");
  }
  
  file->cd();
  legend->Draw("same");
  aCanvas->SaveAs( std::string(canvas_name+".png").c_str() );
  aCanvas->Write();
  return aCanvas;

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
int overlaySamePlot() {

  // Path to input files
  TString path("../results/batch/101011/100_80_50/");

  // Output file
  TFile* output = new TFile( "Plots.root", "RECREATE" );
  if ( !output || output->IsZombie() ) { return -1; }

  // Ratio from truth
  if (0) {
    createPlot( path, "BabyJets_HT250_All", "BabyOverHt_HT250_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );

  // Baby jets
  if (0) {
    createPlot( path, "BabyJets_HT250_All", "BabyOverHt_HT250_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT300_All", "BabyOverHt_HT300_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT350_All", "BabyOverHt_HT350_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff400_All", "BabyOverMeff_Meff400_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff450_All", "BabyOverMeff_Meff450_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff500_All", "BabyOverMeff_Meff500_aT0_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT250_AT0.52_All", "BabyOverHt_HT250_aT0.52_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT300_AT0.52_All", "BabyOverHt_HT300_aT0.52_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT350_AT0.52_All", "BabyOverHt_HT350_aT0.52_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff400_AT0.52_All", "BabyOverMeff_Meff400_aT0.52_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff450_AT0.52_All", "BabyOverMeff_Meff450_aT0.52_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff500_AT0.52_All", "BabyOverMeff_Meff500_aT0.52_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT250_AT0.55_All", "BabyOverHt_HT250_aT0.55_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT300_AT0.55_All", "BabyOverHt_HT300_aT0.55_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_HT350_AT0.55_All", "BabyOverHt_HT350_aT0.55_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff400_AT0.55_All", "BabyOverMeff_Meff400_aT0.55_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff450_AT0.55_All", "BabyOverMeff_Meff450_aT0.55_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
    createPlot( path, "BabyJets_Meff500_AT0.55_All", "BabyOverMeff_Meff500_aT0.55_all", "QcdBkgdEst", 5, false, true, output, 2.85 );
  }

  output->Write();
  output->Close();
  delete output; 

  return 0;

}


