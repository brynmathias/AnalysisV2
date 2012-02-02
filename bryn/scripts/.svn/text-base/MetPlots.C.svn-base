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
- Projection
- output file
*/
int MetPlots() {

  // Path to input files
  TString path = "./";

  // Output file
  TFile* output = new TFile( "Plots.root", "RECREATE" );
  if ( !output || output->IsZombie() ) { return -1; }

  if (1) {

//MT2 Plots
    createPlot( path, "MHT", "MHT_all" , "MT2", 10, true, true,false ,output);
    createPlot( path, "MHT X", "MHT X_all" , "MT2", 4, true, true,false ,output);
    createPlot( path, "MHT Y", "MHT Y_all" , "MT2", 4, true, true,false ,output);
    createPlot( path, "HT vs MHT2", "HT vs MHT_all" , "MT2", false, false, false,false, output);

    createPlot( path, "Alpha T Dijet", "AlphaT_2", "KinSuitePlots", false , true, true,false, output);

    // createPlot( path, "MT2", "Mt2_all", "MT2", 10, true, true, output );
    // createPlot( path, "MT2 vs aplha T", "Mt2 vs AlphaT_all", "MT2", 10, false, false, output );

//Common Jet Plots
    createPlot( path, "Multiplicity", "Multiplicity", "CommonJetPlots", false, true, true,false ,output );
    createPlot( path, "Pt alljet spectrium", "Pt_all", "CommonJetPlots", 10, true, true, false,output );
    createPlot( path, "Pt leading Jet", "Pt_1", "CommonJetPlots", 10, true, true, false,output );
    createPlot( path, "Pt second Jet", "Pt_2", "CommonJetPlots", 10, true, true, false,output );
    createPlot( path, "ET", "Et_all", "CommonJetPlots", 10, true, true,false ,output );

  // Object Kine Plots
    createPlot( path, "eta leading Jet", "eta_1", "ObjectKinePlots", 5,true, true, false,output);
    createPlot( path, "eta second Jet", "eta_2", "ObjectKinePlots",5 ,true, true,false, output);
    createPlot( path, "#Delta #eta(j#_{1},j#_{2})", "DeltaEta_1", "ObjectKinePlots",5 ,true, true,false, output);
    createPlot( path, "HT vs MHT", "HT vs MHT_all" , "MT2", false, false, true,true, output);
    createPlot( path, "HT vs MHT_X", "HT vs MHT_X_all" , "MT2", false, false, true,true, output);
    createPlot( path, "HT vs MHT_Y", "HT vs MHT_Y_all" , "MT2", false, false, true,true, output);

  }

  if (0) {

    createPlot( path, "MT2 vs mt(j1+j2)", "hDalitzMT2Mjj_all", "MT2", false, true, true, output );
    createPlot( path, "MT2 vs mt(j2+mht)", "hDalitzMT2mt_j2_mht_all", "MT2", false, true, true, output );
    createPlot( path, "MT2 vs mt(j1+mht)", "hDalitzMT2mt_j1_mht_all", "MT2", false, true, true, output );

    // createPlot( path, "SecondJetEta", "Eta_2", "Hadronic", 10, false, true, output );
    // createPlot( path, "DeltaEta", "DeltaEta_1", "Hadronic", 10, false, true, output );
    // createPlot( path, "DeltaR", "DeltaR_1", "Hadronic", 10, false, true, output );
    // createPlot( path, "LeadingJetEtaNorm", "Eta_1", "Hadronic", 10, true, true, output );
    // createPlot( path, "SecondJetEtaNorm", "Eta_2", "Hadronic", 10, true, true, output );
    // createPlot( path, "DeltaEtaNorm", "DeltaEta_1", "Hadronic", 10, true, true, output );
    // createPlot( path, "DeltaRNorm", "DeltaR_1", "Hadronic", 10, true, true, output );
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
  bool project,
  TDirectory* file
  )
{

  // SetSomeStyles();

  // Create legend
  TLegend* legend = new TLegend( 0.75, 0.65, 0.92, 0.92, NULL, "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0);

  // Create canvas
  TCanvas* aCanvas = createCanvas( canvas_name, file, log );

  // Create histograms

  TH1D* MC  = getHisto( path, name, "AK5PF_MinBias MC.root", dirmame, rebin );
  TH1D* Data  = getHisto( path, name, "AK5PF_NewData.root", dirmame, rebin );

  // Line colour and fill
  if ( MC ) MC->SetLineColor(kRed);
  // if ( MC ) MC->SetFillColor(kRed);
  if ( MC ) MC->SetFillStyle(3003);
  if ( Data ) Data->SetLineColor(kBlack);
  if ( Data ) Data->SetLineStyle(1);
  if ( Data ) Data->SetLineWidth(1);
  if ( Data ) Data->SetMarkerStyle(20);
  // Populate legend
  legend->AddEntry( Data, " All Data ", "L" );
  legend->AddEntry( MC, " MC ", "f" );
  // Calc maximum number of entries
  double aMax = 0.;
  if ( Data->GetMaximum()     > aMax ) { aMax = Data->GetMaximum(); }
  if ( MC->GetMaximum() > aMax ) { aMax = MC->GetMaximum(); }


  // Calc minimum number of entries
  double aMin = 1.e12;
  if ( Data->GetMinimum(1.e-12)     < aMin ) { aMin = Data->GetMinimum(1.e-12); }
  if ( MC->GetMinimum(1.e-12) < aMin ) { aMin = MC->GetMinimum(1.e-12); }
  // if ( Data ) Data->GetXaxis()->SetRangeUser(0.,400.);
  // if ( MC ) MC->GetXaxis()->SetRangeUser(0.,400.);
  if ( Data ) Data->GetYaxis()->SetTitleOffset(1.43);
  if ( Data ) Data->GetYaxis()->SetTitleSize(0.06);
  if ( Data ) Data->GetXaxis()->SetTitleSize(0.06);
  if ( Data ) Data->GetXaxis()->SetTitleOffset(0.9);

  if ( log ) {
    if ( Data ) Data->SetMaximum( aMax * 10. );
    if ( Data ) Data->SetMinimum( aMin * 0.1 );
  } else {
    if ( Data ) Data->SetMaximum( aMax * 1.1 );
    if ( Data ) Data->SetMinimum( aMin * 0.9 );
  }
  if ( project ){
    TCanvas *c1 = new TCanvas("c1","projecton",10,10,800,600);
    c1->cd();
    Int_t n = Data->GetYaxis()->GetNbins();
    // Int_t w = Data->GetYaxis()->GetBinWidth();
    for(int i = 0; i < n; i+=4){

      Int_t up = Data->GetYaxis()->GetBinUpEdge(i+4);
      Int_t low = Data->GetYaxis()->GetBinLowEdge(i+1);
      std::cout << "Lower bin value " << low << " upper bin value " << up << std::endl;

      TString bins("MHT in Bins of HT (");
      bins+=low;
      TString mid("<HT<");
      bins+=mid;
      bins+=up;
      TString end(")");
      bins+=end;
      std::cout << bins << endl;

      TH1D *px1 = Data->TH2D::ProjectionY("px1",i+1,i+4,"o");
      px1->GetXaxis()->SetRangeUser(0.,200.);
      px1->GetYaxis()->SetTitle(bins);
      px1->GetXaxis()->SetTitle("MHT (GeV)");
      TH1D *px2 = MC->TH2D::ProjectionY("px2",i+1,i+4,"o");
      px2->Scale(px1->Integral()/px2->Integral());



      if( canvas_name == TString("HT vs MHT_X") || canvas_name == TString("HT vs MHT_X")){ bool fit_ = true;}
      else { bool fit_ = false;}
      // fit_ = true;

      if ( fit_ ) {
        if(px1->GetBinContent(i+1) == 0) continue;// bool can put in else where.
        Double_t max = px1->GetMean(1) + 2*(px1->GetRMS(1));
        Double_t min = px1->GetMean(1) - 2*(px1->GetRMS(1));
        TF1 *gfit = new TF1("g1","gaus",min,max); // Create the fit function
        px1->Fit("g1","QR");
        px1->GetFunction("g1")->SetLineColor(1);
        Double_t maxMC = px2->GetMean(1) + 2*(px2->GetRMS(1));
        Double_t minMC = px2->GetMean(1) - 2*(px2->GetRMS(1));
        TF1 *gfit2 = new TF1("g2","gaus",minMC,maxMC);
        px2->Fit("g2","QR+");
        px2->GetFunction("g2")->SetLineColor(3); // Create the fit function
      }

      px1->Draw("LPEBh");
      px2->Draw("sameh");
      //Save as a png with name of orig plot + sting. to append Integer to string
      // TString a("string");
      // a+=integer;
      // a = stringinteger <---- so far the only way I know to do this.
      TString type(".png");
      bins+=canvas_name;
      bins+=type;

      c1->SetFillColor(0);
      c1->SetBorderMode(0);
      c1->SetBorderSize(2);
      if ( log == true)c1->SetLogy();
      c1->SetLeftMargin(0.1765705);
      c1->SetRightMargin(0.05772496);
      c1->SetTopMargin(0.04778761);
      c1->SetBottomMargin(0.1256637);
      c1->SetFrameFillStyle(0);
      c1->SetFrameLineWidth(2);
      c1->SetFrameBorderMode(0);
      c1->SetFrameFillStyle(0);
      c1->SetFrameLineWidth(2);
      c1->SetFrameBorderMode(0);


      c1->SaveAs(bins);
    }

    if (Data) { TH1D *px19 = Data->TH2D::ProjectionY("px19",1,40,"o");
    px19->GetXaxis()->SetRangeUser(0.,200.);
    px19->GetYaxis()->SetTitle("");
    px19->GetXaxis()->SetTitle("MHT (GeV)");
    px19->Draw("LPEBh");}


    if (MC)   { TH1D *px20 = MC->TH2D::ProjectionY("px20",1,40,"o");
    px20->GetXaxis()->SetRangeUser(0.,200.);
    px20->Scale(px19->Integral()/px20->Integral());
    px20->Draw("sameh");}
    c1->SaveAs("MHT_all.png");


  }

  if ( norm ) {
    if ( Data ) Data->DrawNormalized("LPEBhist");


    if ( MC->GetEntries() > 0. ) { MC->DrawNormalized("hsame"); }
  } else {
    if ( Data ) Data->Draw("LPEBh");
    if ( MC ) MC->Draw("sameh");
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


