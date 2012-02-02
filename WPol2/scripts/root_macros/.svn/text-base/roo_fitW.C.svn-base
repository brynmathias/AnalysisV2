void roo_fitW()
{

  gSystem->Load("libRooFit"); 
  gSystem->Load("libRooFitCore");
  gSystem->Load("libMatrix");
  gSystem->Load("libGpad");
  using namespace RooFit;

  TString poscharge = "Plus";
  TString negcharge = "Minus";

  std::vector<TString> charge(2);
  charge.at(0) = poscharge;
  charge.at(1) = negcharge;

  TString bin1 = "50to75";
  TString bin2 = "75to100";
  TString bin3 = "100toinf";

  std::vector<TString> bins(3);
  bins.at(0) = bin1;
  bins.at(1) = bin2;
  bins.at(2) = bin3;

  //we only set up the machinery for the plus charge
  TFile *refTemplates = new TFile("results/GenW_CS_WJets-lite_madgraph_50_75_100.root");
  TFile *dataplus = new TFile("results/RecoW_WJets-lite_madgraph_50_75_100.root");
  //TFile *dataplus = new TFile("results/GenW_CS_WJets-lite_madgraph_50_75_100.root");

  bool makePlots = false;

  TString canvas_name_plus = "RECO_WCSFramePlots_PlusPhi";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",900,320);
  c0->Divide(3,1);
  TString canvas_name_minus = "RECO_WCSFramePlots_MinusPhi";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",900,320);
  c1->Divide(3,1);
 
  for(unsigned int i=0; i<bins.size(); i++) {
    for(unsigned int j=0; j<charge.size(); j++) {
      //unsigned int index = i*charge.size() + j;
      //cout << "INDEX= " << index << endl;
      //these histograms define the number of events in the complete templates so we can apply correction factors for acceptance etc.
      TString refHist1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_A";
      TString refHist2 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_B";
      TString refHist3 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_C";
      TH1D *refTempHist1 = (TH1D*)refTemplates->Get(refHist1);
      TH1D *refTempHist2 = (TH1D*)refTemplates->Get(refHist2);
      TH1D *refTempHist3 = (TH1D*)refTemplates->Get(refHist3);

      //TString Hist1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_A";//MuonAcc
      //TString Hist2 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_B";
      //TString Hist3 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_C";
      //TString Hist_data1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi";
      TString Hist1 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi_A";
      TString Hist2 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi_B";
      TString Hist3 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi_C";
      TString Hist_data1 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi";

      Int_t rbin=10;
      TH1D *mc1 = (TH1D*)dataplus->Get(Hist1);
      TH1D *mc2 = (TH1D*)dataplus->Get(Hist2);
      TH1D *mc3 = (TH1D*)dataplus->Get(Hist3);
      TH1D *datahist = (TH1D*)dataplus->Get(Hist_data1);

      double accFactor1 = refTempHist1->Integral() / mc1->Integral();
      double accFactor2 = refTempHist2->Integral() / mc2->Integral();
      double accFactor3 = refTempHist3->Integral() / mc3->Integral();

      double normFactor = (mc1->Integral() + mc2->Integral() + mc3->Integral()) / (refTempHist1->Integral() + refTempHist2->Integral() + refTempHist3->Integral());

      //accFactor1 = normFactor * accFactor1;
      //accFactor2 = normFactor * accFactor2;
      //accFactor3 = normFactor * accFactor3;

      //std::cout << "TEST: " << refTempHist1->Integral() / (refTempHist1->Integral() + refTempHist2->Integral() + refTempHist3->Integral()) << std::endl;
      //std::cout << "TEST: " << mc1->Integral() / (mc1->Integral() + mc2->Integral() + mc3->Integral()) << std::endl;
      //std::cout << "TEST: " << accFactor1 << ", " << accFactor2 << ", " << accFactor3 << std::endl;

      mc1->Rebin(rbin);
      mc2->Rebin(rbin);
      mc3->Rebin(rbin);
      datahist->Rebin(rbin);
      //datahist->Scale(10);
      //datahist->Scale(invWeightW);//to get MC errors - otherwise comment out

      Double_t istat=datahist->Integral();
      
      // Start RooFit session
  
      RooRealVar x("x","CS Phi",-3.,3.);
      // Import binned Data
      RooDataHist data1("data1","dataset with CSPhiPlus",x,mc1);
      RooDataHist data2("data2","dataset with CSPhiPlus",x,mc2);
      RooDataHist data3("data3","dataset with CSPhiPlus",x,mc3);
      RooDataHist test("test_data","dataset with ICvar",x,datahist);

      Float_t fr = (1./3.)*istat;

      // Relative fractions - allow them to float to negative values too
      RooRealVar f1("alpha","Alpha fraction",fr,0.,10000000.);//,fr,0.,100.) ;
      RooRealVar f2("beta","Beta fraction", fr,-1000000.,10000000. );//,fr,-100.,100.) ;
      RooRealVar f3("gamma","Gamma fraction",fr,-1000000.,10000000.);//,fr,0.,100.) ;

      // Templates 
      RooHistPdf h1("h1","h1",x,data1);
      RooHistPdf h2("h2","h2",x,data2);
      RooHistPdf h3("h3","h3",x,data3);
      
      // composite PDF  
      RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2,f3)) ;
      
      // Generate data 
      Int_t nevt=static_cast<int>(istat);

      // Fitting
      RooFitResult* res1 = model.fitTo(test,Minos(kTRUE),Extended(kTRUE), SumW2Error(kFALSE), Save());
      res1->Print();

      if(makePlots) {
	// Plotting
	gROOT->SetStyle("Plain");  
	gStyle->SetOptFit(111);
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	 //gStyle->SetCanvasDefH(600); //Height of canvas
	 //gStyle->SetCanvasDefW(600); //Width of canvas   
	//TString canvas_name = "MC_CSFramePlots_" + bins.at(i) + charge.at(j) + "Phi";
	//TCanvas *c0 = new TCanvas(canvas_name,"",300,320);
	if(charge.at(j) == "Plus") c0->cd(i+1);
	if(charge.at(j) == "Minus") c1->cd(i+1);
	RooPlot* frame = x.frame();
	test.plotOn(frame); 
	model.plotOn(frame);
	//model.paramOn(frame);
	model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
	model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
	model.plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
	frame->GetXaxis()->SetTitle("#phi_{CS}");
	frame->Draw();
	//c0->cd(i)->Update();
	//c0->Update();
	//c0->Print(canvas_name+".png");
      }

      const TMatrixDSym& cor = res1->correlationMatrix();
      const TMatrixDSym& cov = res1->covarianceMatrix();
      //Print correlation, covariance matrix
      //cout << "correlation matrix" << endl;
      //cor.Print();
      //cout << "covariance matrix" << endl;
      //cout << "(0,0) = " << cov[0][0] << endl;
      //cout << f1.getVal() << endl;
      //cov.Print();

      //calculate values of A2 and A3 with the appropriate errors
      double F1 = f1.getVal() * accFactor1;
      double F2 = f2.getVal() * accFactor2;
      double F3 = f3.getVal() * accFactor3;

      double A2_val = 4.0 * F3 / (F1 + F2 + F3); //the factor 4 is 1/k1...
      double A3_val = (16.0/(3.0*TMath::Pi())) * F2 / (F1 + F2 + F3);

      double A2dfdgamma = (F1 + F2)/((F1 + F2 + F3)*(F1 + F2 + F3)); 
      double A2dfdalpha = -1.0*F3/((F1 + F2 + F3)*(F1 + F2 + F3));
      double A2dfdbeta = A2dfdalpha;

      double A2comp1 = accFactor3 * accFactor3 * cov[2][2] * A2dfdgamma * A2dfdgamma;
      double A2comp2 = accFactor1 * accFactor1 * cov[0][0] * A2dfdalpha * A2dfdalpha;
      double A2comp3 = accFactor2 * accFactor2 * cov[1][1] * A2dfdbeta * A2dfdbeta;
      double A2comp4 = accFactor2 * accFactor3 * cov[1][2] * A2dfdgamma * A2dfdbeta * 2.0;
      double A2comp5 = accFactor1 * accFactor3 * cov[0][2] * A2dfdalpha * A2dfdgamma * 2.0;
      double A2comp6 = accFactor1 * accFactor2 * cov[0][1] * A2dfdalpha * A2dfdbeta * 2.0;

      double A2_err2 = A2comp1 + A2comp2 + A2comp3 + A2comp4 + A2comp5 + A2comp6;
      double A2_err = 4.0*sqrt(A2_err2);

      double A3dfdbeta = (F1 + F3)/((F1 + F2 + F3)*(F1 + F2 + F3));
      double A3dfdalpha = -1.0*F2/((F1 + F2 + F3)*(F1 + F2 + F3));
      double A3dfdgamma = A2dfdalpha;

      double A3comp1 = accFactor3 * accFactor3 * cov[2][2] * A3dfdgamma * A3dfdgamma;
      double A3comp2 = accFactor1 * accFactor1 * cov[0][0] * A3dfdalpha * A3dfdalpha;
      double A3comp3 = accFactor2 * accFactor2 * cov[1][1] * A3dfdbeta * A3dfdbeta;
      double A3comp4 = accFactor2 * accFactor3 * cov[1][2] * A3dfdgamma * A3dfdbeta * 2.0;
      double A3comp5 = accFactor1 * accFactor3 * cov[0][2] * A3dfdalpha * A3dfdgamma * 2.0;
      double A3comp6 = accFactor1 * accFactor2 * cov[0][1] * A3dfdalpha * A3dfdbeta * 2.0;

      double A3_err2 = A3comp1 + A3comp2 + A3comp3 + A3comp4 + A3comp5 + A3comp6;;
      double A3_err = (16.0/(3.0*TMath::Pi())) * sqrt(A3_err2);

      cout << "Fitting bin " << bins.at(i) << " for " << charge.at(j) << " charge: " << endl;
      cout << "A2 = " << A2_val << " +/- " << A2_err << endl;
      cout << "A3 = " << A3_val << " +/- " << A3_err << endl;

    }
  }
  if(makePlots) {
    c0->Print(canvas_name_plus+".png");
    c1->Print(canvas_name_minus+".png");
  }
  return;

}
