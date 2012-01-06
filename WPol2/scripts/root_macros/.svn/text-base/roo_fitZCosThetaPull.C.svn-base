void roo_fitZCosThetaPull()
{

  gSystem->Load("libRooFit"); 
  gSystem->Load("libRooFitCore");
  gSystem->Load("libMatrix");
  gSystem->Load("libGpad");
  using namespace RooFit;

  TString poscharge = "Plus";
  TString negcharge = "Minus";

  std::vector<TString> charge(1);
  charge.at(0) = poscharge;
  //charge.at(1) = negcharge;

  TString bin1 = "50to75";
  TString bin2 = "75to100";
  TString bin3 = "100toinf";

  std::vector<TString> bins(3);
  bins.at(0) = bin1;
  bins.at(1) = bin2;
  bins.at(2) = bin3;

  //REMEMBER: we are not sensitive to A4 because we don't know the sign of cos(#theta_{CS})

  //we only set up the machinery for the plus charge
  TFile *dataplus = new TFile("results/GenW_CS_ZJets-lite_madgraph_50_75_100_plus.root");
  //TFile *dataplus = new TFile("results/RecoW_ZJets-lite_madgraph_50_75_100_plus.root");
  TFile *refTemplates = new TFile("results/GenW_CS_ZJets-lite_madgraph_50_75_100_plus.root");

  bool makePlots = false;
  double invZweight = 1 / 0.024; //approx 1M events in the ZJets-madgraph sample
 
  TString canvas_name = "RECO_ZCSFramePlots_PlusCosTheta";
  TCanvas *c0 = new TCanvas(canvas_name,"",900,320);
  c0->Divide(3,1);

  for(unsigned int i=0; i<bins.size(); i++) {
    for(unsigned int j=0; j<charge.size(); j++) {
      //unsigned int index = i*charge.size() + j;
      //cout << "INDEX= " << index << endl;
      //these histograms define the number of events in the complete templates so we can apply correction factors for acceptance etc.
      TString refHist1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "CosTheta_A";
      TString refHist2 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "CosTheta_C";
      TH1D *refTempHist1 = (TH1D*)refTemplates->Get(refHist1);
      TH1D *refTempHist2 = (TH1D*)refTemplates->Get(refHist2);
      
      
      TString Hist1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "CosTheta_A";
      TString Hist2 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "CosTheta_C";
      TString Hist_data1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "CosTheta";
      //TString Hist1 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "CosTheta_A";
      //TString Hist2 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "CosTheta_C";
      //TString Hist_data1 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "CosTheta";

      Int_t rbin=10;
      TH1D *mc1 = (TH1D*)dataplus->Get(Hist1);
      TH1D *mc2 = (TH1D*)dataplus->Get(Hist2);
      TH1D *datahist = (TH1D*)dataplus->Get(Hist_data1);

      double accFactor1 = refTempHist1->Integral() / mc1->Integral();
      double accFactor2 = refTempHist2->Integral() / mc2->Integral();
      
      mc1->Rebin(rbin);
      mc2->Rebin(rbin);
      datahist->Rebin(rbin);
      //datahist->Scale(10);
      //datahist->Scale(invZweight);//to get MC errors - otherwise comment out

      Double_t istat=datahist->Integral();
      
      // Start RooFit session
  
      RooRealVar x("x","CS Phi",-0.9,0.9);
      // Import binned Data
      RooDataHist data1("data1","dataset with CSCosThetaPlus",x,mc1);
      RooDataHist data2("data3","dataset with CSCosThetaPlus",x,mc2);
      RooDataHist test("test_data","dataset with ICvar",x,datahist);

      Float_t fr = (1./3.)*istat;

      // Relative fractions - allow them to float to negative values too
      RooRealVar f1("alpha","Alpha fraction",fr,0.,10000000.);//,fr,0.,100.) ;
      RooRealVar f2("beta","Beta fraction",fr,-1000000.,10000000.);//,fr,0.,100.) ;

      // Templates 
      RooHistPdf h1("h1","h1",x,data1);
      RooHistPdf h2("h2","h2",x,data2);
      
      // composite PDF  
      //RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2,f3)) ;
      RooAddPdf model("model","model",RooArgList(h1,h2),RooArgList(f1,f2)) ;
      
      // Generate data 
      Int_t nevt=static_cast<int>(istat);

      // Fitting
      RooFitResult* res1 = model.fitTo(test,Minos(kTRUE),Extended(kTRUE), SumW2Error(kFALSE), Save());
      double F1 = f1.getVal() * accFactor1;
      double F2 = f2.getVal() * (accFactor2 * 3.0); // times 3 due to integral over the template x^2 between [1,-1] difference to 1 (and 1+x), over the same range
      double A0_refVal = 2.0 * (F1 - F2) / (3.0*F1 + F2);
      double F1_refVal = f1.getVal();
      double F2_refVal = f2.getVal();

      TH1D * histo = new TH1D("histo","histo", 2000, -100.5, 99.5);

      for(unsigned int k=0; k<100; k++) {
	RooDataSet *gtest = model.generate(x,nevt);
	RooFitResult* res1 = model.fitTo(*gtest,Minos(kTRUE),Extended(kTRUE), SumW2Error(kFALSE), Save());
	double F1 = f1.getVal() * accFactor1;
	double F2 = f2.getVal() * (accFactor2 * 3.0); // times 3 due to integral over the template x^2 between [1,-1] difference to 1 (and 1+x), over the same range
	double A0_val = 2.0 * (F1 - F2) / (3.0*F1 + F2);
	double A0dfdalpha = (8.0 * F2) / ((3.0*F1 + F2)*(3.0*F1 + F2));
	double A0dfdbeta = (8.0 * F1) / ((3.0*F1 + F2)*(3.0*F1 + F2));
	const TMatrixDSym& cov = res1->covarianceMatrix();
	double A0comp1 = accFactor1 * accFactor1 * cov[0][0] * A0dfdalpha * A0dfdalpha;
	double A0comp2 = (accFactor2 * 3.0) * (accFactor2 * 3.0) * cov[1][1] * A0dfdbeta * A0dfdbeta;
	double A0comp3 = accFactor1 * (accFactor2 * 3.0) * cov[0][1] * A0dfdalpha * A0dfdbeta * 2.0; 
	
	double A0_err2 = A0comp1 + A0comp2 + A0comp3;
	double A0_err = sqrt(A0_err2);
	//histo->Fill((A0_val - A0_refVal)/A0_err);
	histo->Fill((f2.getVal() - F2_refVal)/f2.getError());
      }
      c0->cd(i+1);
      histo->Draw();
      // Fitting
      //RooFitResult* res1 = model.fitTo(test,Minos(kTRUE),Extended(kTRUE), SumW2Error(kFALSE), Save());
      //res1->Print();
/*
      if(makePlots) {
	// Plotting
	gROOT->SetStyle("Plain");  
	gStyle->SetOptFit(111);
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	c0->cd(i+1);
	RooPlot* frame = x.frame();
	test.plotOn(frame); 
	model.plotOn(frame);
	//model.paramOn(frame);
	model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
	model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
	frame->GetXaxis()->SetTitle("cos#theta_{CS}");
	frame->Draw();
      }

      const TMatrixDSym& cor = res1->correlationMatrix();
      const TMatrixDSym& cov = res1->covarianceMatrix();
      //Print correlation, covariance matrix
      //cout << "correlation matrix" << endl;
      //cor.Print();
      //cout << "covariance matrix" << endl;
      //cov.Print();

      //cout << "(0,0) = " << cov[0][0] << endl;
      //cout << f1.getVal() << endl;


      //accFactor1 = 1.0;
      //accFactor2 = 1.0;
      //accFactor3 = 1.0;

      //calculate values of A0 and A4 with the appropriate errors
      double F1 = f1.getVal() * accFactor1;
      double F2 = f2.getVal() * (accFactor2 * 3.0); // times 3 due to integral over the template x^2 between [1,-1] difference to 1 (and 1+x), over the same range

      double A0_val = 2.0 * (F1 - F2) / (3.0*F1 + F2);
      
      double A0dfdalpha = (8.0 * F2) / ((3.0*F1 + F2)*(3.0*F1 + F2));
      double A0dfdbeta = (8.0 * F1) / ((3.0*F1 + F2)*(3.0*F1 + F2));

      double A0comp1 = accFactor1 * accFactor1 * cov[0][0] * A0dfdalpha * A0dfdalpha;
      double A0comp2 = (accFactor2 * 3.0) * (accFactor2 * 3.0) * cov[1][1] * A0dfdbeta * A0dfdbeta;
      double A0comp3 = accFactor1 * (accFactor2 * 3.0) * cov[0][1] * A0dfdalpha * A0dfdbeta * 2.0; 

      double A0_err2 = A0comp1 + A0comp2 + A0comp3;
      double A0_err = sqrt(A0_err2);

      cout << "Fitting bin " << bins.at(i) << " for " << charge.at(j) << " charge: " << endl;
      cout << "A0 = " << A0_val << " +/- " << A0_err << endl;
      //cout << "A4 = " << A4_val << " +/- " << A4_err << endl;
      //cout << "accFactor1 = " << accFactor1 << ", accFactor2 = " << accFactor2 << ", accFactor3 = " << accFactor3 << endl;
*/
    }
  }

  if(makePlots) c0->Print(canvas_name+".png");
  return;

}
