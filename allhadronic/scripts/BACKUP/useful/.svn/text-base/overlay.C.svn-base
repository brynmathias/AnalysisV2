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
  //TString path = "../results/";
  //TString path = "../../../RESULTS/10-AllFixedForTalk/";
  //TString path = "../../../RESULTS/12-Talk/";
  //TString path = "../../../RESULTS/16-Dalitz0.606AlphaT0.576/";
  //TString path = "../../../RESULTS/18-PhotonJets/";
  TString path = "../../../RESULTS/19-MarkusTalk/";

  // Output file
  TFile* output = new TFile( "Plots.root", "RECREATE" );
  if ( !output || output->IsZombie() ) { return -1; }

  // Old PAS scales
  if (0) {
    createPlot( path, "JetMultiplicity", "JetMultiplicity", "CommonPlots", 1, false, true, output, 0.17, 200. );
    createPlot( path, "HT", "SumEtall", "CommonPlots", 10, false, true, output, 0.06, 200. );
    createPlot( path, "MHT", "MHTall", "CommonPlots", 10, false, true, output, 0.06, 200. );
    createPlot( path, "AlphaT", "AlphaT_0", "KinSuitePlots", 5, false, true, output, 0.06, 3.e6 );
    createPlot( path, "BiasedDPhi", "biasedJetMHTdPhiall", "CommonPlots", 2, false, true, output, 0.006, 90. );
  }

  // New scales
  if (1) {
    createPlot( path, "JetMultiplicity", "JetMultiplicity", "CommonPlotsPre", 1, false, true, output, 0.1, 100. );
    createPlot( path, "HT", "SumEtall", "CommonPlotsPre", 10, false, true, output, 0.1, 100. );
    createPlot( path, "MHT", "MHTall", "CommonPlotsPre", 10, false, true, output, 0.1, 100. );
    createPlot( path, "AlphaT", "AlphaT_0", "KinSuitePlots", 5, false, true, output, 0.1, 2.e6 );
    createPlot( path, "AlphaT_yscale", "AlphaT_0", "KinSuitePlots", 10, false, true, output );
    createPlot( path, "BiasedDPhi", "biasedJetMHTdPhiall", "CommonPlots", 2, false, true, output, 0.001, 100. );
    createPlot( path, "BiasedDPhi_yscale", "biasedJetMHTdPhiall", "CommonPlots", 2, false, true, output );
  }

  // No scales
  if (0) {
    createPlot( path, "HT", "SumEtall", "CommonPlots", 10, false, true, output );
    createPlot( path, "MHT", "MHTall", "CommonPlots", 10, false, true, output );
    createPlot( path, "AlphaT", "AlphaT_0", "KinSuitePlots", 5, false, true, output );
    createPlot( path, "BiasedDPhi", "biasedJetMHTdPhiall", "CommonPlots", 2, false, true, output );
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
		     TDirectory* file,
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
  
  // Create histograms
  TH1D* qcd   = 0;
  TH1D* phot  = 0;
  TH1D* ttbar = 0;
  TH1D* wjets = 0;
  TH1D* zinv  = 0;
  TH1D* zjets = 0;
  TH1D* lm0   = 0;
  TH1D* lm1   = 0;
  
  qcd   = (TH1D*)getHisto( path, name, "IC5Calo_QCDPythia.root", dirmame, rebin );
  //phot  = (TH1D*)getHisto( path, name, "IC5Calo_PhotonJetPythia.root", dirmame, rebin );
  ttbar = (TH1D*)getHisto( path, name, "IC5Calo_TTbar.root", dirmame, rebin );
  wjets = (TH1D*)getHisto( path, name, "IC5Calo_WJets.root", dirmame, rebin );
  zinv  = (TH1D*)getHisto( path, name, "IC5Calo_Zinv.root", dirmame, rebin );
  zjets = (TH1D*)getHisto( path, name, "IC5Calo_ZJets.root", dirmame, rebin );
  lm0   = (TH1D*)getHisto( path, name, "IC5Calo_LM0.root", dirmame, rebin );
  lm1   = (TH1D*)getHisto( path, name, "IC5Calo_LM1.root", dirmame, rebin );
  //qcd   = (TH1D*)getHisto( path, name, "IC5Calo_QCD_Pythia_Merged.root", dirmame, rebin );
  //ttbar = (TH1D*)getHisto( path, name, "IC5Calo_TTbarJets.root", dirmame, rebin );

  // Combine Z+jets and Z->inv
  TH1D* zall = zinv ? zinv->Clone() : 0; 
  if ( zall && zjets ) zall->Add(zjets,1);

  // Merge Z+jets and Z->inv
  bool combine = true;
  
  // Line colour and fill
  if ( qcd ) qcd->SetLineColor(kGreen+2);
  if ( qcd ) qcd->SetFillColor(kGreen+2);
  if ( qcd ) qcd->SetFillStyle(3003);
  if ( phot ) phot->SetLineColor(kOrange);
  if ( phot ) phot->SetLineStyle(1);
  if ( phot ) phot->SetLineWidth(3);
  if ( ttbar ) ttbar->SetLineColor(kBlue);
  if ( ttbar ) ttbar->SetLineStyle(1);
  if ( ttbar ) ttbar->SetLineWidth(3);
  if ( wjets ) wjets->SetLineColor(kBlue);
  if ( wjets ) wjets->SetLineStyle(3);
  if ( wjets ) wjets->SetLineWidth(3);
  if ( combine ) {
    if ( zall ) zall->SetLineColor(kBlack);
    if ( zall ) zall->SetLineStyle(3);
    if ( zall ) zall->SetLineWidth(3);
  } else {
    if ( zinv ) zinv->SetLineColor(kBlack);
    if ( zinv ) zinv->SetLineStyle(1);
    if ( zinv ) zinv->SetLineWidth(3);
    if ( zjets ) zjets->SetLineColor(kBlack);
    if ( zjets ) zjets->SetLineStyle(3);
    if ( zjets ) zjets->SetLineWidth(3);
  }
  if ( lm0 ) lm0->SetLineColor(kRed);
  if ( lm0 ) lm0->SetLineStyle(1);
  if ( lm0 ) lm0->SetLineWidth(3);
  if ( lm1 ) lm1->SetLineColor(kRed);
  if ( lm1 ) lm1->SetLineStyle(3);
  if ( lm1 ) lm1->SetLineWidth(3);

  // Populate legend
  if ( lm0 ) legend->AddEntry( lm0, " SUSY LM0", "L" );
  if ( lm1 ) legend->AddEntry( lm1, " SUSY LM1", "L" );
  if ( qcd ) legend->AddEntry( qcd, " QCD", "f" );
  if ( phot ) legend->AddEntry( phot, " #gamma+jet", "L" );
  if ( ttbar ) legend->AddEntry( ttbar, " t#bar{t}", "L" );
  if ( wjets ) legend->AddEntry( wjets, " W", "L" );
  if ( combine ) {
    if ( zall ) legend->AddEntry( zall, " Z", "L" );
  } else {
    if ( zjets ) legend->AddEntry( zjets, " Z+jets", "L" );
    if ( zinv ) legend->AddEntry( zinv, " Z#rightarrow#nu#nu", "L" );
  }

  // Calc maximum number of entries
  double aMax = 0.;
  if ( qcd && qcd->GetMaximum() > aMax ) { aMax = qcd->GetMaximum(); }
  if ( phot && phot->GetMaximum() > aMax ) { aMax = phot->GetMaximum(); }
  if ( lm0 && lm0->GetMaximum() > aMax ) { aMax = lm0->GetMaximum(); }
  if ( lm1 && lm1->GetMaximum() > aMax ) { aMax = lm1->GetMaximum(); }
  if ( ttbar && ttbar->GetMaximum() > aMax ) { aMax = ttbar->GetMaximum(); }  
  if ( wjets && wjets->GetMaximum() > aMax ) { aMax = wjets->GetMaximum(); }  
  if ( combine ) {
    if ( zall && zall->GetMaximum() > aMax ) { aMax = zall->GetMaximum(); }  
  } else {
    if ( zinv && zinv->GetMaximum() > aMax ) { aMax = zinv->GetMaximum(); }  
    if ( zjets && zjets->GetMaximum() > aMax ) { aMax = zjets->GetMaximum(); }  
  }

  // Calc minimum number of entries
  double aMin = 1.e12;
  if ( qcd && qcd->GetMinimum(1.e-12) < aMin ) { aMin = qcd->GetMinimum(1.e-12); }
  if ( phot && phot->GetMinimum(1.e-12) < aMin ) { aMin = phot->GetMinimum(1.e-12); }
  if ( lm0 && lm0->GetMinimum(1.e-12) < aMin ) { aMin = lm0->GetMinimum(1.e-12); }
  if ( lm1 && lm1->GetMinimum(1.e-12) < aMin ) { aMin = lm1->GetMinimum(1.e-12); }
  if ( ttbar && ttbar->GetMinimum(1.e-12) < aMin ) { aMin = ttbar->GetMinimum(1.e-12); }  
  if ( wjets && wjets->GetMinimum(1.e-12) < aMin ) { aMin = wjets->GetMinimum(1.e-12); }  
  if ( combine ) {
    if ( zall && zall->GetMinimum(1.e-12) < aMin ) { aMin = zall->GetMinimum(1.e-12); }  
  } else {
    if ( zinv && zinv->GetMinimum(1.e-12) < aMin ) { aMin = zinv->GetMinimum(1.e-12); }  
    if ( zjets && zjets->GetMinimum(1.e-12) < aMin ) { aMin = zjets->GetMinimum(1.e-12); }  
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

  if ( qcd && min > 0. ) qcd->SetMinimum( min );
  if ( qcd && max > 0. ) qcd->SetMaximum( max );
  
  if ( norm ) {
    if ( qcd ) qcd->DrawNormalized("Ehist");
    if ( phot && phot->GetEntries() > 0. ) { phot->DrawNormalized("hsame"); }
    if ( lm0 && lm0->GetEntries() > 0. ) { lm0->DrawNormalized("hsame"); }
    if ( lm1 && lm1->GetEntries() > 0. ) { lm1->DrawNormalized("hsame"); }
    if ( ttbar && ttbar->GetEntries() > 0. ) { ttbar->DrawNormalized("hsame"); }
    if ( wjets && wjets->GetEntries() > 0. ) { wjets->DrawNormalized("hsame"); }
    if ( combine ) {
      if ( zall && zall->GetEntries() > 0. ) { zall->DrawNormalized("hsame"); }
    } else {
      if ( zinv && zinv->GetEntries() > 0. ) { zinv->DrawNormalized("hsame"); }
      if ( zjets && zjets->GetEntries() > 0. ) { zjets->DrawNormalized("hsame"); }
    }
  } else {
    if ( qcd ) qcd->Draw("h");
    if ( phot ) phot->Draw("sameH");
    if ( lm0 ) lm0->Draw("sameH");
    if ( lm1 ) lm1->Draw("sameH");
    if ( ttbar ) ttbar->Draw("sameh");
    if ( wjets) wjets->Draw("sameH");
    if ( combine ) {
      if ( zall ) zall->Draw("sameH");
    } else {
      if ( zinv ) zinv->Draw("sameH");
      if ( zjets ) zjets->Draw("sameH");
    }
  }
  
  file->cd();
  legend->Draw("same");
  aCanvas->SaveAs( std::string(canvas_name+".png").c_str() );
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


