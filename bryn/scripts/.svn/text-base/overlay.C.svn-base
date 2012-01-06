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
*/  
int overlay() {
  
  // Path to input files
  TString path = "../results/";

  // Output file
  TFile* output = new TFile( "Plots.root", "RECREATE" );
  if ( !output || output->IsZombie() ) { return -1; }
  
  if (1) {
    createPlot( path, "AlphaT", "AlphaT_0", "KinSuitePlots", 5, false, true, output );
    //createPlot( path, "AlphaTzoom", "AlphaT_0", "KinSuitePlots", 1, false, true, output );
    createPlot( path, "JetMultiplicity", "JetMultiplicity", "CommonPlots", 1, false, true, output );
    createPlot( path, "HT", "SumEtall", "CommonPlots", 10, false, true, output );
    createPlot( path, "MHT", "MHTall", "CommonPlots", 10, false, true, output );
    createPlot( path, "BiasedDPhi", "biasedJetMHTdPhiall", "CommonPlots", 2, false, true, output );
    createPlot( path, "DeltaPhi_MPT_MHT", "MPTMHTdPhi", "CommonPlots", 2, false, true, output );
  }
  
  if (0) {
    createPlot( path, "LeadingJetEta", "Eta_1", "Hadronic", 10, false, true, output );
    createPlot( path, "SecondJetEta", "Eta_2", "Hadronic", 10, false, true, output );
    createPlot( path, "DeltaEta", "DeltaEta_1", "Hadronic", 10, false, true, output );
    createPlot( path, "DeltaR", "DeltaR_1", "Hadronic", 10, false, true, output );
    createPlot( path, "LeadingJetEtaNorm", "Eta_1", "Hadronic", 10, true, true, output );
    createPlot( path, "SecondJetEtaNorm", "Eta_2", "Hadronic", 10, true, true, output );
    createPlot( path, "DeltaEtaNorm", "DeltaEta_1", "Hadronic", 10, true, true, output );
    createPlot( path, "DeltaRNorm", "DeltaR_1", "Hadronic", 10, true, true, output );
  }

  output->Write();
  output->Close();
  delete output; 
  
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
		     TDirectory* file )
{

  // SetSomeStyles();

  // Create legend
  TLegend* legend = new TLegend( 0.75, 0.65, 0.92, 0.92, NULL, "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0); 
  
  // Create canvas
  TCanvas* aCanvas = createCanvas( canvas_name, file, log );
  
  // Create histograms
  TH1D* qcd     = getHisto( path, name, "IC5Calo_QCD_Pythia_Merged.root", dirmame, rebin );
  TH1D* tt_jets = getHisto( path, name, "IC5Calo_TTbarJets.root", dirmame, rebin );
  TH1D* w_jets  = getHisto( path, name, "IC5Calo_WJets.root", dirmame, rebin );
  TH1D* z_inv   = getHisto( path, name, "IC5Calo_Zinv.root", dirmame, rebin );
  TH1D* z_jets  = getHisto( path, name, "IC5Calo_ZJets.root", dirmame, rebin );
  TH1D* lm0     = getHisto( path, name, "IC5Calo_LM0.root", dirmame, rebin );
  TH1D* lm1     = getHisto( path, name, "IC5Calo_LM1.root", dirmame, rebin );

  // Combine Z+jets and Z->inv
  TH1D* z_all = z_inv->Clone(); 
  z_all->Add(z_jets,1);

  // Merge Z+jets and Z->inv
  bool combine = true;
  
  // Line colour and fill
  if ( qcd ) qcd->SetLineColor(kGreen+2);
  if ( qcd ) qcd->SetFillColor(kGreen+2);
  if ( qcd ) qcd->SetFillStyle(3003);
  if ( tt_jets ) tt_jets->SetLineColor(kBlue);
  if ( tt_jets ) tt_jets->SetLineStyle(1);
  if ( tt_jets ) tt_jets->SetLineWidth(1);
  w_jets->SetLineColor(kBlue);
  w_jets->SetLineStyle(3);
  w_jets->SetLineWidth(1);
  if ( combine ) {
    z_all->SetLineColor(kBlack);
    z_all->SetLineStyle(3);
    z_all->SetLineWidth(1);
  } else {
    z_inv->SetLineColor(kBlack);
    z_inv->SetLineStyle(1);
    z_inv->SetLineWidth(1);
    z_jets->SetLineColor(kBlack);
    z_jets->SetLineStyle(3);
    z_jets->SetLineWidth(1);
  }
  lm0->SetLineColor(kRed);
  lm0->SetLineStyle(1);
  lm0->SetLineWidth(2);
  lm1->SetLineColor(kRed);
  lm1->SetLineStyle(3);
  lm1->SetLineWidth(2);

  // Populate legend
  legend->AddEntry( qcd, " QCD", "f" );
  legend->AddEntry( lm0, " SUSY LM0", "L" );
  legend->AddEntry( lm1, " SUSY LM1", "L" );
  legend->AddEntry( tt_jets, " t#bar{t}+jets", "L" );
  legend->AddEntry( w_jets, " W+jets", "L" );
  if ( combine ) {
    legend->AddEntry( z_all, " Z", "L" );
  } else {
    legend->AddEntry( z_jets, " Z+jets", "L" );
    legend->AddEntry( z_inv, " Z#rightarrow#nu#nu", "L" );
  }

  // Calc maximum number of entries
  double aMax = 0.;
  if ( qcd->GetMaximum()     > aMax ) { aMax = qcd->GetMaximum(); }
  if ( lm0->GetMaximum()     > aMax ) { aMax = lm0->GetMaximum(); }
  if ( lm1->GetMaximum()     > aMax ) { aMax = lm1->GetMaximum(); }
  if ( tt_jets->GetMaximum() > aMax ) { aMax = tt_jets->GetMaximum(); }  
  if ( w_jets->GetMaximum()  > aMax ) { aMax = w_jets->GetMaximum(); }  
  if ( combine ) {
    if ( z_all->GetMaximum()  > aMax ) { aMax = z_all->GetMaximum(); }  
  } else {
    if ( z_inv->GetMaximum()   > aMax ) { aMax = z_inv->GetMaximum(); }  
    if ( z_jets->GetMaximum()  > aMax ) { aMax = z_jets->GetMaximum(); }  
  }

  // Calc minimum number of entries
  double aMin = 1.e12;
  if ( qcd->GetMinimum(1.e-12)     < aMin ) { aMin = qcd->GetMinimum(1.e-12); }
  if ( lm0->GetMinimum(1.e-12)     < aMin ) { aMin = lm0->GetMinimum(1.e-12); }
  if ( lm1->GetMinimum(1.e-12)     < aMin ) { aMin = lm1->GetMinimum(1.e-12); }
  if ( tt_jets->GetMinimum(1.e-12) < aMin ) { aMin = tt_jets->GetMinimum(1.e-12); }  
  if ( w_jets->GetMinimum(1.e-12)  < aMin ) { aMin = w_jets->GetMinimum(1.e-12); }  
  if ( combine ) {
    if ( z_all->GetMinimum(1.e-12)   < aMin ) { aMin = z_all->GetMinimum(1.e-12); }  
  } else {
    if ( z_inv->GetMinimum(1.e-12)   < aMin ) { aMin = z_inv->GetMinimum(1.e-12); }  
    if ( z_jets->GetMinimum(1.e-12)  < aMin ) { aMin = z_jets->GetMinimum(1.e-12); }  
  }

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

  if ( norm ) {
    if ( qcd ) qcd->DrawNormalized("Ehist");
    if ( lm0->GetEntries() > 0. )     { lm0->DrawNormalized("hsame"); }
    if ( lm1->GetEntries() > 0. )     { lm1->DrawNormalized("hsame"); }
    if ( tt_jets->GetEntries() > 0. ) { tt_jets->DrawNormalized("hsame"); }
    if ( w_jets->GetEntries() > 0. )  { w_jets->DrawNormalized("hsame"); }
    if ( combine ) {
      if ( z_all->GetEntries() > 0. )   { z_all->DrawNormalized("hsame"); }
    } else {
      if ( z_inv->GetEntries() > 0. )   { z_inv->DrawNormalized("hsame"); }
      if ( z_jets->GetEntries() > 0. )  { z_jets->DrawNormalized("hsame"); }
    }
  } else {
    if ( qcd ) qcd->Draw("h");
    lm0->Draw("sameH");
    lm1->Draw("sameH");
    if ( tt_jets ) tt_jets->Draw("sameh");
    w_jets->Draw("sameH");
    if ( combine ) {
      z_all->Draw("sameH");
    } else {
      z_inv->Draw("sameH");
      z_jets->Draw("sameH");
    }
  }
  
  file->cd();
  legend->Draw("same");
  //aCanvas->SaveAs( std::string(canvas_name+".png").c_str() );
  aCanvas->Write();
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
  TDirectory* dir = (TDirectory*)file->Get(Dirname);
  TH1* hist = (TH1*)dir->Get(nameHist);
  if (!hist) {
    std::cout << " name: " << nameHist
	      << " file: " << nameFile
	      << " dir: " <<  Dirname
	      << std::endl;
    abort();

  }
  hist->SetLineWidth(1);
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
TCanvas* createCanvas(TString name,TDirectory* afile, bool log)
{
  afile->cd();
  TCanvas* aCanvas = new TCanvas(name);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(0);
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


