void roo_fitWH()
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
  //TFile *dataplus = new TFile("results/GenW_CS_WJets-lite_madgraph_50_75_100.root");
  TFile *dataplus = new TFile("results/RecoW_WJets-lite_madgraph_50_75_100.root");
  TFile *refTemplates = new TFile("results/GenW_CS_WJets-lite_madgraph_50_75_100.root");

  bool makePlots = false;

  TString canvas_name_plus = "MC_WHelicityFramePlots_PlusICVar";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",900,320);
  c0->Divide(3,1);

  TString canvas_name_minus = "MC_WHelicityFramePlots_MinusICVar";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",900,320);
  c1->Divide(3,1);
 
  for(unsigned int i=0; i<bins.size(); i++) {
    for(unsigned int j=0; j<charge.size(); j++) {
      //unsigned int index = i*charge.size() + j;
      //cout << "INDEX= " << index << endl;

      //these histograms define the number of events in the complete templates so we can apply correction factors for acceptance etc.
      //do not change these histograms!
      TString refHist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
      TString refHist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
      TString refHist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
      TH1D *refTempHist1 = (TH1D*)refTemplates->Get(refHist1);
      TH1D *refTempHist2 = (TH1D*)refTemplates->Get(refHist2);
      TH1D *refTempHist3 = (TH1D*)refTemplates->Get(refHist3);

      //these histograms are the ones we want to fit
      //TString Hist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
      //TString Hist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
      //TString Hist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
      //TString Hist_data1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j);
      TString Hist1 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVar"+ charge.at(j) + "_LH";
      TString Hist2 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVar"+ charge.at(j) + "_RH";
      TString Hist3 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVar"+ charge.at(j) + "_LO";
      TString Hist_data1 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVar"+ charge.at(j);

      Int_t rbin=10;
      TH1D *mc1 = (TH1D*)dataplus->Get(Hist1);
      TH1D *mc2 = (TH1D*)dataplus->Get(Hist2);
      TH1D *mc3 = (TH1D*)dataplus->Get(Hist3);
      TH1D *datahist = (TH1D*)dataplus->Get(Hist_data1);

      //we are only fitting for fL and fR
      double accFactor1 = refTempHist1->Integral() / mc1->Integral();
      double accFactor2 = refTempHist2->Integral() / mc2->Integral();
      double accFactor3 = refTempHist3->Integral() / mc3->Integral();
      double normFactor = (mc1->Integral() + mc2->Integral() + mc3->Integral()) / (refTempHist1->Integral() + refTempHist2->Integral() + refTempHist3->Integral());

      mc1->Rebin(rbin);
      mc2->Rebin(rbin);
      mc3->Rebin(rbin);
      datahist->Rebin(rbin);
      //datahist->Scale(10);
      //datahist->Scale(invWeightW);//to get MC errors - otherwise comment out

      Double_t istat=datahist->Integral();
      
      // Start RooFit session
  
      RooRealVar x("x","ICVar",-1.9,1.9);
      // Import binned Data
      RooDataHist data1("data1","dataset with WHICVarPlus",x,mc1);
      RooDataHist data2("data2","dataset with WHICVarPlus",x,mc2);
      RooDataHist data3("data3","dataset with WHICVarPlus",x,mc3);
      RooDataHist test("test_data","dataset with WHICVarPlus",x,datahist);

      //Float_t fr = (1./3.)*istat;
      Float_t fr = (1.0/3.0);

      // Relative fractions - allow them to float to negative values too if needs be
      RooRealVar f1("fL","fL fraction",fr,0.0,1.0);
      RooRealVar f2("fR","fR fraction", fr,0.0,1.0);
      RooRealVar f3("f0","f0 fraction",fr,0.0,1.0);

      // Templates 
      RooHistPdf h1("h1","h1",x,data1);
      RooHistPdf h2("h2","h2",x,data2);
      RooHistPdf h3("h3","h3",x,data3);
      
      // composite PDF  
      RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2)) ;
 
      // Generate data 
      Int_t nevt=static_cast<int>(istat);

      RooDataSet *gtest = model.generate(x,nevt);

      // Fitting
      RooFitResult * res1 = model.fitTo(test,Minos(kTRUE), Save());
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
	frame->GetXaxis()->SetTitle("LP Variable");
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

      double F1 = f1.getVal() * accFactor1 * normFactor;
      double F2 = f2.getVal() * accFactor2 * normFactor;
      double F3 = (1.0 - F1 - F2);

      double F1_err = sqrt(cov[0][0]) * accFactor1 * normFactor;
      double F2_err = sqrt(cov[1][1]) * accFactor2 * normFactor;

      cout << "Fitting bin " << bins.at(i) << " for " << charge.at(j) << " charge: " << endl;
      cout << "fL = " << F1 << " +/- " << F1_err << endl;
      cout << "fR = " << F2 << " +/- " << F2_err << endl;
      cout << "f0 = " << F3 << " +/- " << "N/A" << endl;

    }
  }
  if(makePlots) {
    c0->Print(canvas_name_plus+".png");
    c1->Print(canvas_name_minus+".png");
  }
  return;

}
