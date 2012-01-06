// -----------------------------------------------------------------------------
/*
  Arguments to createPlot():
  - path to input files
  - canvas title
  - historam title
  - histogram directory
  - rebin histograms?
  - normalize all histograms to unit area?
  - logarithmic y-scale
  - output file
*/   

int overlavMUHL_Markus() {
  
  // Path to input files
  //  TString path = "/vols/cms01/mstoye/Muon_Control_Sample_Outpt/";
 TString path = "";
  // Output file
  TFile* output = new TFile( "Plots.root", "RECREATE" );
  if ( !output || output->IsZombie() ) { return -1; }
  
  if (1) {


    if(false){
    // set one:
      createPlot( path, "Meff", "Meff", "ttWPlotting_500", 5, false, true, output );
      createPlot( path, "PFMET", "PFMET", "ttWPlotting_500", 25, false, true, output );
      createPlot( path, "Wpt", "WPTall", "ttWPlotting_500", 25, false, true, output );
      createPlot( path, "MeffLP", "Meff", "ttWPlotting_750", 5, false, true, output );
      createPlot( path, "PFMETLP", "PFMET", "ttWPlotting_750", 25, false, true, output );
      createPlot( path, "WptLP", "WPTall", "ttWPlotting_750", 25, false,  true,output );
      createPlot( path, "HTLep", "PFMETLepLP", "ttWPlotting_500", 25, false,  true,output );
      createPlot( path, "HTLepLP", "PFMETLepLP", "ttWPlotting_750", 25, false,  true,output );
      //
    }
    if(false){
      // set one:
      createPlot( path, "PFMETLP", "PFMETLP", "ttWPlotting_500", 25, false, true, output );
      createPlot( path, "WPTLPLP", "PFMETPro", "ttWPlotting_500", 25, false, true, output );
      createPlot( path, "PFMETLepLPII", "PFMETLepLPII", "ttWPlotting_500", 25, false, true, output );
      
      //
    }
    if(false){
      createPlot( path, "WptLP", "WPTall", "ttWPlotting_750", 25, false,  true,output );
      createPlot( path, "PFMETLP", "PFMETLepLP", "ttWPlotting_500", 25, false, true, output );
      createPlot( path, "PFMET", "PFMET", "ttWPlotting_500", 25, false, true, output );
      createPlot( path, "PFMETPro", "PFMETPro", "ttWPlotting_500", 25, false, true, output );
    }
    

    if(false)
      {
	//	createPlot( path, "WptLP", "WPTall", "post_LP_015", 25, false,  true,output );
       	createPlot( path, "PFMETLP", "PFMETLepLP", "post_LP_015", 5, false, true, output );
  	createPlot( path, "PFMETLP2", "PFMETLepLP", "ttWPlotting_750", 5, false, true, output );
	//	createPlot( path, "DynamicCutWptplusL_all", "DynamicCutWptplusL", "ttWPlotting_750", 25, false, true, output );	
	//		createPlot( path, "DynamicCutWptplusLI_all", "DynamicCutWptplusLI", "ttWPlotting_750", 25, false, true, output );	
	//		createPlot( path, "DynamicCutWptplusLII_all", "DynamicCutWptplusLII", "ttWPlotting_750", 25, false, true, output );	
		//	createPlot( path, "DynamicCutWptplusLII_2to4j", "DynamicCutWptplusLII", "post_LP_02_2to4j", 25, false, true, output );	
		//  	createPlot( path, "DynamicCutWptplusLII_4j", "DynamicCutWptplusLII", "post_LP_02_4j", 25, false, true, output );	
	//	createPlot( path, "PFMET", "PFMET", "ttWPlotting_500", 25, false, true, output );


		//	createPlot( path, "PFMET", "PFMET", "ttWPlotting_750", 25, false, true, output );

		//	createPlot( path, "PFMET", "PFMET", "post_LP_02_4j", 25, false, true, output );
	//	createPlot( path, "DynamicCutWptplusLII_4j", "DynamicCutWptplusLII", "post_LP_02_2to4j", 25, false, true, output );
	//	createPlot( path, "DynamicCutWptplusLII_4j", "DynamicCutWptplusLII", "post_LP_02_2j", 25, false, true, output );
	//	createPlot( path, "DynamicCutWptplusLII_4j", "DynamicCutWptplusLII", "post_LP_02_4j", 25, false, true, output );
	//	createPlot( path, "PFMET", "PFMET", "post_LP_02_4j", 25, false, true, output );

	//    createPlot( path, "DynamicCutWpt", "DynamicCutWpt", "ttWPlotting_500", 25, false, false, output );
	//		createPlot( path, "DynamicCutWptplusL", "DynamicCutWptplusL", "ttWPlotting_500", 25, false, true, output );
	// createPlot( path, "DynamicCutWptplusLNot", "DynamicCutWptplusLNot", "ttWPlotting_500", 50, false, false, output );
		//		createPlot( path, "DynamicCutWptplusLI", "DynamicCutWptplusLI", "ttWPlotting_500", 25, false, true, output ); 
	//createPlot( path, "DynamicCutWptplusLNotI", "DynamicCutWptplusLNotI", "ttWPlotting_500", 50, false, false, output );
	//	createPlot( path, "DynamicCutWptplusLII", "DynamicCutWptplusLII", "ttWPlotting_500", 25, false, true, output );	
	//	createPlot( path, "PFMET", "PFMET", "ttWPlotting_500", 25, false, true, output );
    // createPlot( path, "PFMETPro", "PFMETLepLPII", "ttWPlotting_500", 50, false, false, output );
    //    createPlot( path, "PFMETLepLP", "PFMETLepLP", "ttWPlotting_500", 5, false, false, output );
     //    createPlot( path, "Meff", "Meff", "ttWPlotting_500", 2, false, false, output );
      }

    if(true)
      {
	createPlot( path, "LP", "LP", "ttWPlots_150",10, false, false, output );
	//createPlot( path, "LP_350", "LP350", "ttWPlotting_500", 1, false, false, output );
	//	createPlot( path, "LP_300", "LP300", "ttWPlotting_500", 1, false, false, output );
	//	createPlot( path, "LP_250", "LP220", "ttWPlotting_500", 1, false, false, output );
      }


 //    createPlot( path, "PFMETpostLP", "PFMET", "ttWPlotting_500", 25, false, false, output );
 //createPlot( path, "PFMETpostLP", "PFMET", "ttWPlotting_500", 25, false, false, output );
 // createPlot( path, "PFMETpostLP", "PFMET", "ttWPlotting_500", 25, false, false, output );
       //   createPlot( path, "Meff", "Meff", "ttWPlotting_500", 5, false, false, output );
       //   createPlot( path, "MuPt", "MuPt", "ttWPlotting_500", 50, false, false, output );

       // createPlot( path, "PFMETPropostLP", "PFMETPro", "ttWPlotting_750", 5, false, false, output );
       // createPlot( path, "PFMETLepLPpostLP", "PFMETLepLP", "ttWPlotting_750", 5, false, false, output );
       // createPlot( path, "PFMETLepLPpostLPI", "PFMETLepLPI", "ttWPlotting_750", 5, false, false, output );
       // createPlot( path, "PFMETLepLPpostLPII", "PFMETLepLPII", "ttWPlotting_750", 5, false, false, output );
       


    //   createPlot( path, "MT", "MT", "ttWPlotting_500", 20, false, false, output );
    //   createPlot( path, "MTLP", "MT", "ttWPlotting_750", 20, false, false, output );



    //    createPlot( path, "MuEta", "MuEta", "ttWPlotting_750", 2, false, false, output );


    //   createPlot( path, "LP2", "LP2", "ttWPlotting_500", 10, false, false, output );
    //  createPlot( path, "LP3", "LP3", "post_LP_02_2j", 10, false, false, output );
    //   createPlot( path, "LP34j", "LP3", "post_LP_02_4j", 10, false, false, output );
    // createPlot( path, "LP4", "LP_500", "post_LP_02_4j", 5, false, false, output );
    //    createPlot( path, "LP44j", "LP_500", "post_LP_02_2to4j", 5, false, false, output );
    // createPlot( path, "LP4", "LP_500", "ttWPlotting_500", 5, false, false, output );
    //   createPlot( path, "LP44j", "LP_500", "ttWPlotting_500", 5, false, false, output );

   // createPlot( path, "LP4", "LP4", "ttWPlotting_500", 10, false, false, output );



    /*  createPlot( path, "Meff_1000", "Meff", "ttWPlotting_1000", 5, false, false, output );
    createPlot( path, "jetMult_1000", "CxjetsMult", "Counter_BSMGrid_final_selection", 1, false, false, output );
    createPlot( path, "MTall_750", "MT", "ttWPlotting_750", 10, false, false, output );
    createPlot( path, "WPTall_750", "LP", "ttWPlotting_750", 10, false, false, output );
    createPlot( path, "Meff_750", "Meff", "ttWPlotting_750", 5, false, false, output );
    createPlot( path, "jetMult_750", "CxjetsMult", "Counter_BSMGrid_750", 1, false, false, output );
    createPlot( path, "MTall_500", "MT", "ttWPlotting_500", 10, false, false, output );
    createPlot( path, "WPTall_500", "LP", "ttWPlotting_500", 10, false, false, output );
    createPlot( path, "Meff_500", "Meff", "ttWPlotting_500", 5, false, false, output );
    createPlot( path, "jetMult_500", "CxjetsMult", "Counter_BSMGrid_500", 1, false, false, output );
    */

    //createPlot( path, "AT_lep_250", "StandardPlots/HT_all", "After_AlphaT_had", 1, false, true, output );    
    // createPlot( path, "AT_had_300", "StandardPlots/AlphaT_Hadronic_all", "After_350Gev", 2, false, true, output );    
  }
  
  if (0) {
    createPlot( path, "LeadingJetEta", "Eta_1", "Hadronic", 5, false, true, output );
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

  float lumi = 250.0;// 15.04;//10.9;//6.8;
 
  // Create legend
  TLegend* legend = new TLegend(0.75, 0.6, 0.99, 0.99, "", "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0); 
  legend->SetShadowColor(0);
  TLatex* prelim = new TLatex(0.6,0.54,"#scale[0.8]{CMS preliminary 2010}");
  prelim->SetNDC();
  TLatex* alumi = new TLatex(0.6,.45,"#scale[0.8]{#int L dt = 35 pb^{-1}, #sqrt{s} = 7 TeV}");
  alumi->SetNDC();

  // Create canvas 
  TCanvas* aCanvas = createCanvas( canvas_name, file, log );

  // Create histogram
  TString aname("nAll");
  // TH1D* data1    = getHisto( path+"S14datacleaned/Edward_Data_Skim/",name,"data.root",aname,rebin);
  // TH1D* data    = getHisto( path+"S14datacleaned/Edward_Data_Skim/",name,"data.root",dirmame,rebin);
 
  TH1D* data    = getHisto( path+"", name, "tt.root", dirmame, rebin );
  TH1D* qcd     = getHisto( path+"", name, "lm1.root", dirmame, rebin );
  TH1D* w_jets  = getHisto( path+"", name, "w.root", dirmame, rebin );
  TH1D* tt_jets = getHisto( path+"", name, "tt.root", dirmame, rebin );
  TH1D* z_jets  = getHisto( path+"", name, "z.root", dirmame, rebin );
  TH1D* lm3     = getHisto( path+"", name, "lm3.root", dirmame, rebin );
  TH1D* lm1     = getHisto( path+"", name, "lm1.root", dirmame, rebin );
  TH1D* lm6     = getHisto( path+"", name, "data.root", dirmame, rebin );
  TH1D* wm     = getHisto( path+"", name, "w.root", dirmame, rebin );
  data->Scale(lumi/100.);
  qcd->Scale(lumi/100.);
  tt_jets->Scale(lumi/100);
  w_jets->Scale(lumi/100);
  //  w_jets->Scale(10);
  //  z_inv->Scale(lumi/100);
  //  lm6->Scale(lumi/100);
  lm1->Scale(lumi/100);
  lm3->Scale(lumi/100);
  z_jets->Scale(lumi/100);
  wm->Scale(lumi/100);
  // Combine Z+jets and Z->inv
  // TH1D* z_all = z_inv->Clone(); 
  //  z_all->Add(z_jets,1);
  //z_jets->Add(z_inv,1);
  TH1D* total = tt_jets->Clone();
  total->Add(w_jets);
  total->Add(z_jets);

  // total->
 
  Int_t binMax =   total->GetNbinsX();
  Double_t& err = new Double_t(0.);
  total->IntegralAndError(10,binMax ,err);
  Double_t& errW = new Double_t(0.);
  w_jets->IntegralAndError(10,binMax ,errW);
  Double_t& errtt = new Double_t(0.);
  tt_jets->IntegralAndError(10,binMax ,errtt);
  Double_t& errZ = new Double_t(0.);
  z_jets->IntegralAndError(10,binMax ,errZ);
  Double_t& errQCD = new Double_t(0.);
  qcd->IntegralAndError(10,binMax ,errQCD );


  cout  <<endl;
  //  cout << "MC:" <<  total->IntegralAndError(11,binMax ,err) <<" && " <<  w_jets->Integral(11,binMax)<<" && "<<tt_jets->Integral(11,binMax) << "&&  "<<z_jets->Integral(11,binMax)<<" && "<< "\/\ /\hline"<<endl;
  //  cout << total->IntegralAndError(0,binMax ,err) <<" & " << lm1->Integral(0,binMax) <<" & " << lm3->Integral(0,binMax)<<" & " << lm6->Integral(0,binMax)   <<"\\\\ \\hline"<<endl;
  //  cout <<"270: " <<  total->IntegralAndError(27,binMax ,err) <<" & " << lm1->Integral(27,binMax) <<" & " << lm3->Integral(27,binMax)<<" & " << lm6->Integral(27,binMax)   <<"\\\\ \\hline"<<endl;


  cout <<"250& " <<  total->IntegralAndError(6,binMax ,err) <<" & " << lm1->Integral(6,binMax) <<" & " << lm3->Integral(6,binMax)<<" & " << lm6->Integral(6,binMax)   <<"\\\\ \\hline"<<endl;
 
  // cout << "300: " <<  total->IntegralAndError(7,binMax ,err) <<" & " << lm1->Integral(7,binMax) <<" & " << lm3->Integral(7,binMax)<<" &" << lm6->Integral(7,binMax)   <<"\\\\ \\hline"<<endl;

  cout <<"350& " <<  total->IntegralAndError(8,binMax ,err) <<" & " << lm1->Integral(8,binMax) <<" & " << lm3->Integral(8,binMax)<<" & " << lm6->Integral(8,binMax)    <<"\\\\ \\hline"<<endl;

  //   cout << "400: " <<  total->IntegralAndError(9,binMax ,err) <<" & " << lm1->Integral(9,binMax) <<" & " << lm3->Integral(9,binMax)<<" & " << lm6->Integral(9,binMax)    <<"\\\\ \\hline"<<endl;

cout << "450& " <<  total->IntegralAndError(10,binMax ,err) <<" & " << lm1->Integral(10,binMax) <<" & " << lm3->Integral(10,binMax)<<" & " << lm6->Integral(10,binMax)    <<"\\\\ \\hline"<<endl;

//cout << "500: " <<   total->IntegralAndError(11,binMax ,err) <<" & " << lm1->Integral(11,binMax) <<" & " << lm3->Integral(11,binMax)<<" & " << lm6->Integral(11,binMax)    <<"\\\\ \\hline"<<endl;

  cout <<"550& " <<  total->IntegralAndError(12,binMax ,err) <<" & " << lm1->Integral(12,binMax) <<" & " << lm3->Integral(12,binMax)<<" & " << lm6->Integral(12,binMax)    <<"\\\\ \\hline"<<endl;
  /*
 cout << "MC:" <<  total->IntegralAndError(7,binMax ,err) <<" && " << lm1->Integral(7,binMax) <<" && " << lm3->Integral(7,binMax)<<" && " << lm6->Integral(6,binMax)   <<"/\/\ /\hline"<<endl;
  cout << "MC:" <<  total->IntegralAndError(8,binMax ,err) <<" && " << lm1->Integral(8,binMax) <<" && " << lm3->Integral(8,binMax)<<" && " << lm6->Integral(7,binMax)   <<"/\/\ /\hline"<<endl;
  cout << "MC:" <<  total->IntegralAndError(10,binMax ,err) <<" && " << lm1->Integral(10,binMax) <<" && " << lm3->Integral(10,binMax)<<" && " << lm6->Integral(10,binMax)   <<"/\/\ /\hline"<<endl;
 cout << "MC:" <<  total->IntegralAndError(11,binMax ,err) <<" && " << lm1->Integral(11,binMax) <<" && " << lm3->Integral(11,binMax)<<" && " << lm6->Integral(11,binMax)   <<"/\/\ /\hline"<<endl;
 cout << "MC:" <<  total->IntegralAndError(12,binMax ,err) <<" && " << lm1->Integral(12,binMax) <<" && " << lm3->Integral(12,binMax)<<" && " << lm6->Integral(12,binMax)   <<"/\/\ /\hline"<<endl;
  // cout << "MC:" << err  <<", W: " << errW<<", tt: "<<errtt << ", Z: "<<errZ<<", QCD: "<<  errQCD<< endl;
  */

  //  cout << "data:" << data->Integral() << endl;


  TH1D* hcen = total->Clone();
  TH1D* herr = total->Clone();
  
  herr->SetLineColor(kTeal+3);
  herr->SetMarkerColor(kAzure+6);
  herr->SetFillColor(kAzure+6);
  herr->SetLineWidth(3);
  
  total->SetLineWidth(3);
  total->SetFillColor(kAzure+2);
  total->SetLineColor(kAzure+2);
  total->SetFillStyle(3245);
 
  hcen->SetFillStyle(0);
  hcen->SetMarkerColor(kTeal+3);
  hcen->SetLineColor(kTeal+3);
  hcen->SetLineWidth(3);

  // Merge Z+jets and Z->inv
  bool combine = false;
  
  // Line colour and fill
  qcd->SetLineColor(kPink+4);
  qcd->SetLineWidth(3);
  tt_jets->SetLineColor(kBlue+1);
  tt_jets->SetLineWidth(3);
  
  w_jets->SetLineColor(kPink+7);
  w_jets->SetLineWidth(3);

  z_jets->SetLineWidth(3);
  z_jets->SetLineColor(kTeal-7);
  
  if ( combine ) {
    z_all->SetLineColor(kBlack);
    z_all->SetLineStyle(3);
    z_all->SetLineWidth(1);
  } else {
    data->SetLineColor(1);
    data->SetLineStyle(1);
    data->SetLineWidth(3);
    data->SetMarkerStyle(20);
    data->SetFillColor(0);
  }
  //  lm0->SetLineColor(kRed);
  //  lm0->SetLineWidth(3);
  // lm1->SetLineColor(kRed+3);
  // lm1->SetLineWidth(3);

  // Populate legend
  // legend->AddEntry( data, "tt fully leptonic/", "LP" );
   legend->AddEntry( herr, "full SM", "LP" );
    legend->AddEntry( z_jets, " Z+jets ", "LP" );
    legend->AddEntry( w_jets, " W+jets", "LP" );
    legend->AddEntry( tt_jets, " t#bar{t}", "LP" );
    //  legend->AddEntry( lm3, " SUSY LM3", "LP" );
    //   legend->AddEntry( lm1, " SUSY LM1", "LP" );
    legend->AddEntry( lm6, " data", "LP" );
    // legend->AddEntry(wm,"W Mad","lp");
    
  // Calc maximum number of entries
  double aMax = 0.;
  if( data->GetMaximum()     > aMax ) { aMax = data->GetMaximum()+data->GetBinError(data->GetMaximumBin()); }
  if ( qcd->GetMaximum()     > aMax ) { aMax = qcd->GetMaximum(); }
  //  if ( lm0->GetMaximum()     > aMax ) { aMax = lm0->GetMaximum(); }
  //  if ( lm1->GetMaximum()     > aMax ) { aMax = lm1->GetMaximum(); }
  if ( tt_jets->GetMaximum() > aMax ) { aMax = tt_jets->GetMaximum(); }  
  if ( w_jets->GetMaximum()  > aMax ) { aMax = w_jets->GetMaximum(); }  
  if ( combine ) {
    if ( z_all->GetMaximum()  > aMax ) { aMax = z_all->GetMaximum(); }  
  } else {
    //   if ( data->GetMaximum()   > aMax ) { aMax = z_inv->GetMaximum(); }  
    if ( z_jets->GetMaximum()  > aMax ) { aMax = z_jets->GetMaximum(); }  
  }

  // Calc minimum number of entries
  double aMin = 1.e12;
  if ( qcd->GetMinimum(1.e-12)     < aMin ) { aMin = qcd->GetMinimum(1.e-12); }
  //  if ( lm0->GetMinimum(1.e-12)     < aMin ) { aMin = lm0->GetMinimum(1.e-12); }
  //  if ( lm1->GetMinimum(1.e-12)     < aMin ) { aMin = lm1->GetMinimum(1.e-12); }
  if ( tt_jets->GetMinimum(1.e-12) < aMin ) { aMin = tt_jets->GetMinimum(1.e-12); }  
  if ( w_jets->GetMinimum(1.e-12)  < aMin ) { aMin = w_jets->GetMinimum(1.e-12); }  
  if ( combine ) {
    if ( z_all->GetMinimum(1.e-12)   < aMin ) { aMin = z_all->GetMinimum(1.e-12); }  
  } else {
    // if ( data->GetMinimum(1.e-12)   < aMin ) { aMin = z_inv->GetMinimum(1.e-12); }  
    if ( z_jets->GetMinimum(1.e-12)  < aMin ) { aMin = z_jets->GetMinimum(1.e-12); }  
  }

  if ( qcd ) qcd->GetYaxis()->SetTitleOffset(1.43);
  if ( qcd ) qcd->GetYaxis()->SetTitleSize(0.06);
  if ( qcd ) qcd->GetXaxis()->SetTitleSize(0.06);
  if ( qcd ) qcd->GetXaxis()->SetTitleOffset(0.9);

 
  if ( log ) {
    if ( qcd ) herr->SetMaximum( aMax * 10. );
    //   if ( qcd ) herr->SetMinimum( aMin * 0.1 );
    if ( qcd ) herr->SetMinimum( 0.005);
  } else {
    if ( qcd ) herr->SetMaximum( aMax * 1.1 );
    //   if ( qcd ) herr->SetMinimum( aMin * 0.9 );
  if ( qcd ) herr->SetMinimum( 0.005);

  }

  /*  TPad* mainPad = new TPad("","",0.01,0.25,0.99,0.99);
  mainPad->SetNumber(1);
  mainPad->SetFillColor(0);
  // mainPad->Range(-288.2483,-2.138147,1344.235,6.918939);
  mainPad->SetFillColor(0);
  mainPad->SetBorderMode(0);
  mainPad->SetBorderSize(2);
  if ( log == true)mainPad->SetLogy();
   mainPad->SetLeftMargin(0.1765705);
  mainPad->SetRightMargin(0.05772496);
  mainPad->SetTopMargin(0.04778761);
  mainPad->SetBottomMargin(0.1256637);
  mainPad->SetFrameFillStyle(0);
  mainPad->SetFrameLineWidth(2);
  mainPad->SetFrameBorderMode(0);
  mainPad->SetFrameFillStyle(0);
  mainPad->SetFrameLineWidth(2);
  mainPad->SetFrameBorderMode(0);
  if ( log == true)mainPad->SetLogy();
  mainPad->Draw();
  TPad*  ratioPad = new TPad("","",0.01,0.01,0.99,0.25);
  ratioPad->SetNumber(2);
  ratioPad->SetFillColor(0);
  ratioPad->SetFillColor(0);
  ratioPad->SetBorderMode(0);
  ratioPad->SetBorderSize(2);
  // if ( log == true)ratioPad->SetLogy();
   ratioPad->SetLeftMargin(0.1765705);
  ratioPad->SetRightMargin(0.05772496);
  ratioPad->SetTopMargin(0.04778761);
  ratioPad->SetBottomMargin(0.1256637);
  ratioPad->SetFrameFillStyle(0);
  ratioPad->SetFrameLineWidth(2);
  ratioPad->SetFrameBorderMode(0);
  ratioPad->SetFrameFillStyle(0);
  ratioPad->SetFrameLineWidth(2);
  ratioPad->SetFrameBorderMode(0);
  //  if ( log == true)ratioPad->SetLogy();
  ratioPad->Draw();
 

  aCanvas->cd(1);
  */

  herr->GetYaxis()->SetTitle("events");


  if ( norm ) {
    if ( qcd ) qcd->DrawNormalized("Ehist");
    // if ( lm0->GetEntries() > 0. )     { lm0->DrawNormalized("hsame"); }
    if ( lm1->GetEntries() > 0. )     { lm1->DrawNormalized("hsame"); }
    if ( tt_jets->GetEntries() > 0. ) { tt_jets->DrawNormalized("hsame"); }
    if ( w_jets->GetEntries() > 0. )  { w_jets->DrawNormalized("hsame"); }
    if ( combine ) {
      if ( z_all->GetEntries() > 0. )   { z_all->DrawNormalized("hsame"); }
    } else {
      if ( data->GetEntries() > 0. )   { z_inv->DrawNormalized("hsame"); }
      if ( z_jets->GetEntries() > 0. )  { z_jets->DrawNormalized("hsame"); }
    }
  } else {
     herr->Draw("hist");
   
   
     // qcd->SetFillStyle(3240);
     // qcd->SetFillColor(kPink+4);
    // qcd->Draw("hist");
    w_jets->Draw("hSameh");
    z_jets->Draw("9Sameh");
    w_jets->Draw("9Sameh");
    tt_jets->Draw("9SAMEh");
    //data1->Draw("9SAMEh");
     //lm0->Draw("9SAMEh");
     lm1->SetLineColor(12);
     lm1->SetLineStyle(2);
     lm1->SetLineWidth(2);
     //     lm1->Draw("9SAMEh");
     lm3->SetLineColor(14);
     lm3->SetLineStyle(2);
     lm3->SetLineWidth(2);
     //  lm3->Draw("9SAMEh");
     lm6->Draw("9SAMEh");
     wm->SetLineStyle(2);
     wm->SetLineColor(kPink+7);
     // wm->Draw("9Sameh");

     // total->DrawNormalized("9E2same");
     //      data->Draw("SAMEh");
    //  tt_jets->Divide(data);
    //  tt_jets->Draw("h");
  //  data->SetLineColor(kRed);
  //  data->Draw("sameh");
     //     data1->SetLineColor(kRed);
     //  data1->Draw("9SAMEP");
  }
  
    legend->Draw();
  // prelim->Draw();
  // alumi->Draw();



  /*  TH1D* ratioBottom = total->Clone();
  TH1D* ratioTop = data->Clone();
  ratioTop->GetYaxis()->SetTitle("data / sim");
  ratioTop->Divide(ratioBottom);
  
  aCanvas->cd(1)->Update();
 
  aCanvas->cd(2);

  ratioTop->SetTitleSize(0.1, "XYZ");
  ratioTop->SetTitleOffset(0.55, "X");
  ratioTop->SetTitleOffset(0.3, "Y");
  ratioTop->SetLabelSize(0.06,"XY");
    
  // ratioTop->GetXaxis().SetRangeUser(MinX,MaxX);
  ratioTop->GetYaxis()->SetRangeUser(0.,2.0);
  ratioTop->Draw();*/
  /* TBox* unity = TBox(ratioTop->GetXaxis()->GetBinLowEdge(ratioTop->GetXaxis()->GetFirst()), 0.89,ratioTop->GetXaxis()->GetBinLowEdge(ratioTop->GetXaxis()->GetLast()), 1.11);
  unity->SetLineWidth(2);
   
  unity->SetLineColor(2);
  unity->SetFillColor(2);
  unity->SetFillStyle(3002);
  unity->Draw();

  */
  file->cd();
 
  aCanvas->SaveAs( std::string(canvas_name+".pdf").c_str() );
  aCanvas->Write();



  //   aCanvas->Print(".png");
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
  // file->ls();
  TDirectory* dir = (TDirectory*)file->Get(Dirname);
  //  dir->ls();

  if( !dir) {
    std::cout << " dir " << Dirname << std::endl;
  }
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
  TCanvas* aCanvas = new TCanvas(name,name);
  gStyle->SetOptFit(1);
  gStyle->SetOptStat(111111);
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


