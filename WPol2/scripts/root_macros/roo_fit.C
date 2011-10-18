void roo_fit()
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

  TFile *data = new TFile("results/GenW_CS_WJets_madgraph_50_75_100_CSonly.root");
  //TFile *data = new TFile("results/RecoW_WJets_madgraph_CSPhi_reweighting_test.root");

  double invWeightW = 544.0269; //basically the inverse of the madgraph weight = cross-section / num events ^{-1} = 9700000/17830
  double invWeightZ = 537.369;
  bool makePlots = false;
 
  for(unsigned int i=0; i<bins.size(); i++) {
    for(unsigned int j=0; j<charge.size(); j++) {
      unsigned int index = i*charge.size() + j;
      cout << "INDEX= " << index << endl;
      TString Hist1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_A";
      TString Hist2 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_B";
      TString Hist3 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi_C";
      TString Hist_data1 = "MC_CSFramePlots_" + bins.at(i) + "/MC_CSWMuon" + charge.at(j) + "Phi";
      //TString Hist1 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi_A";
      //TString Hist2 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi_B";
      //TString Hist3 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi_C";
      //TString Hist_data1 = "RECO_CSFramePlots_" + bins.at(i) + "/RECO_CSWMuon2"+ charge.at(j) + "Phi";

      Int_t rbin=10;
      TH1D *mc1 = (TH1D*)data->Get(Hist1);
      TH1D *mc2 = (TH1D*)data->Get(Hist2);
      TH1D *mc3 = (TH1D*)data->Get(Hist3);
      mc1->Rebin(rbin);
      mc2->Rebin(rbin);
      mc3->Rebin(rbin);
      TH1D *datahist = (TH1D*)data->Get(Hist_data1);
      datahist->Rebin(rbin);
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
	TString canvas_name = "RECO_CSFramePlots_" + bins.at(i) + charge.at(j) + "Phi";
	TCanvas *c0 = new TCanvas(canvas_name,"",300,320);
	RooPlot* frame = x.frame();
	test.plotOn(frame); 
	model.plotOn(frame);
	//model.paramOn(frame);
	model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
	model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
	model.plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
	frame->Draw();
	c0->Update();
	c0->Print(canvas_name+".png");
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
      double A2_val = 4.0 * f3.getVal() / (f1.getVal() + f2.getVal() + f3.getVal()); //the factor 4 is 1/k1...
      double A3_val = (16.0/(3.0*TMath::Pi())) * f2.getVal() / (f1.getVal() + f2.getVal() + f3.getVal());

      double A2dfdgamma = (f1.getVal() + f2.getVal())/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal())); 
      double A2dfdalpha = -1.0*f3.getVal()/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal()));
      double A2dfdbeta = A2dfdalpha;

      double A2comp1 = cov[2][2] * A2dfdgamma * A2dfdgamma;
      double A2comp2 = cov[0][0] * A2dfdalpha * A2dfdalpha;
      double A2comp3 = cov[1][1] * A2dfdbeta * A2dfdbeta;
      double A2comp4 = cov[1][2] * A2dfdgamma * A2dfdbeta * 2.0;
      double A2comp5 = cov[0][2] * A2dfdalpha * A2dfdgamma * 2.0;
      double A2comp6 = cov[0][1] * A2dfdalpha * A2dfdbeta * 2.0;

      double A2_err2 = A2comp1 + A2comp2 + A2comp3 + A2comp4 + A2comp5 + A2comp6;
      double A2_err = 4.0*sqrt(A2_err2);

      double A3dfdbeta = (f1.getVal() + f3.getVal())/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal()));
      double A3dfdalpha = -1.0*f2.getVal()/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal()));
      double A3dfdgamma = A2dfdalpha;

      double A3comp1 = cov[2][2] * A3dfdgamma * A3dfdgamma;
      double A3comp2 = cov[0][0] * A3dfdalpha * A3dfdalpha;
      double A3comp3 = cov[1][1] * A3dfdbeta * A3dfdbeta;
      double A3comp4 = cov[1][2] * A3dfdgamma * A3dfdbeta * 2.0;
      double A3comp5 = cov[0][2] * A3dfdalpha * A3dfdgamma * 2.0;
      double A3comp6 = cov[0][1] * A3dfdalpha * A3dfdbeta * 2.0;

      double A3_err2 = A3comp1 + A3comp2 + A3comp3 + A3comp4 + A3comp5 + A3comp6;;
      double A3_err = (16.0/(3.0*TMath::Pi())) * sqrt(A3_err2);

      cout << "Fitting bin " << bins.at(i) << " for " << charge.at(j) << " charge: " << endl;
      cout << "A2 = " << A2_val << " +/- " << A2_err << endl;
      cout << "A3 = " << A3_val << " +/- " << fabs(A3_err) << endl;

    }
  }

  return;

  TString Hist1 = "MC_CSFramePlots_100toinf/MC_CSWMuonAccPlusPhi_A";
  TString Hist2 = "MC_CSFramePlots_100toinf/MC_CSWMuonAccPlusPhi_B";
  TString Hist3 = "MC_CSFramePlots_100toinf/MC_CSWMuonAccPlusPhi_C";
//  TString Hist1 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusPhi_A";
//  TString Hist2 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusPhi_B";
//  TString Hist3 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusPhi_C";

//  TString Hist1 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2MinusPhi_A";
//  TString Hist2 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2MinusPhi_B";
//  TString Hist3 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2MinusPhi_C";
//  TString Hist1 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2PlusPhi_A";
//  TString Hist2 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2PlusPhi_B";
//  TString Hist3 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2PlusPhi_C";


//    TString Hist1 = "MC_WPlots_100toinf/MC_ICVarMinusMuonAcc_LH";
//    TString Hist2 = "MC_WPlots_100toinf/MC_ICVarMinusMuonAcc_RH";
//    TString Hist3 = "MC_WPlots_100toinf/MC_ICVarMinusMuonAcc_LO";
   // TString Hist1 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_LH";
   // TString Hist2 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_RH";
  // TString Hist3 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_LO";
//   TString Hist_data1 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus";
//   TString Hist_data1 = "MC_WPlots_100toinf/MC_ICVarPlusMuonAcc";

//  TString Hist_data1 = "MC_CSFramePlots_100toinf/MC_CSWMuonPlusPhi";
  TString Hist_data1 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusPhi";
//  TString Hist_data1 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2MinusPhi";
//  TString Hist_data1 = "RECO_CSFramePlots_100toinf/RECO_CSWMuon2PlusPhi";



  //  TFile *data = new TFile("GenW_WJets_madgraph_ICVAR_reweighting_test_muononly.root");
  //TFile *data = new TFile("results/RecoW_WJets_madgraph_ICVAR_reweighting_test.root");

  TFile *data = new TFile("results/GenW_CS_WJets_madgraph_CSPhi_reweighting_test.root");
//  TFile *data = new TFile("results/GenW_CS_ZJets_madgraph_CSPhi_reweighting_test.root");
//  TFile *data = new TFile("results/RecoW_WJets_madgraph_CSPhi_reweighting_test.root");
//  TFile *data = new TFile("results/RecoW_ZJets_madgraph_CSPhi_reweighting_test.root");

  Int_t rbin=10;

  TH1D *mc1 = (TH1D*)data->Get(Hist1);
  TH1D *mc2 = (TH1D*)data->Get(Hist2);
  TH1D *mc3 = (TH1D*)data->Get(Hist3);
  
//   TH1::SetDefaultSumw2(kTRUE);  
//   TH1D *mc1 = new TH1D("mc1_p",";;",700,-3.55,3.45);
//   TH1D *mc2 = new TH1D("mc2_p",";;",700,-3.55,3.45);
//   TH1D *mc3 = new TH1D("mc3_p",";;",700,-3.55,3.45);
//   TH1::SetDefaultSumw2(kFALSE);  

//   for(double i=-3.15; i<3.15; i=i+0.01) {
//     //don't use the weight trick to fill a 1D hist, but rather fill it properly since these are the pdfs which are normalised to one
//     if(i>-3.14 && i<3.14){ for(double j=0.005; j< 1.0 + cos(i); j=j+0.005)  {mc2->Fill(i);}}
//     if(i>-3.14 && i<3.14){ for(double j=0.005; j< 1.0 + cos(2.0*i); j=j+0.005) {mc3->Fill(i);}}
//     mc1->Fill(i);
//     //mc1->Fill(i);
//   }
  
  mc1->Rebin(rbin);
  mc2->Rebin(rbin);
  mc3->Rebin(rbin);


  double invWeightW = 544.0269; //basically the inverse of the madgraph weight = cross-section / num events ^{-1} = 9700000/17830
  double invWeightZ = 537.369;
//  mc1->Scale(invWeight);
//  mc2->Scale(invWeight);
//  mc3->Scale(invWeight);


//  TH1D *temp = mc1->Clone();
    //temp->Scale(TMath::Pi()/2.0);
//  temp->Scale(1.57);
//  mc3->Add(temp);

//  TH1D *temp2 = mc1->Clone();
    //temp2->Scale(TMath::Pi()/2.0);
//  temp2->Scale(1.57);
//  mc2->Add(temp2);

  //mc2->Add(mc1); mc3->Add(mc1);
  /*
  mc1->Draw(); mc2->Draw("SAME"); mc3->Draw("SAME");
  return;
  */
//   TH1D *test1 = (TH1D*) mc1->Clone();
//   test1->Add(mc2,+1);
//   test1->Add(mc3,+1);

  TH1D *datahist = (TH1D*)data->Get(Hist_data1);
  datahist->Rebin(rbin);
//  datahist->Scale(invWeightW);//to get MC errors - otherwise comment out
//  datahist->Scale(20.);//to get equivalent yield for Z relative to W

  Double_t istat=datahist->Integral();
    //mc1->Integral()+mc2->Integral()+mc3->Integral();
  Int_t nBins=datahist->GetNbinsX()/4.;
 
  // Start RooFit session
  
  //RooRealVar x("x","ICvar",-2.5,2.5);
  RooRealVar x("x","CS Phi",-3.,3.);
  // Import binned Data
  RooDataHist data1("data1","dataset with CSPhiPlus",x,mc1);
  RooDataHist data2("data2","dataset with CSPhiPlus",x,mc2);
  RooDataHist data3("data3","dataset with CSPhiPlus",x,mc3);

  RooDataHist test("test_data","dataset with ICvar",x,datahist);
  //  RooHistPdf htest("htest","htest",x,test);

  Float_t fr = (1./3.)*istat;

  // Relative fractions - allow them to float to negative values too
  RooRealVar f1("alpha","Alpha fraction",fr,0.,10000000.);//,fr,0.,100.) ;
  RooRealVar f2("beta","Beta fraction", fr,-1000000.,10000000. );//,fr,-100.,100.) ;
  RooRealVar f3("gamma","Gamma fraction",fr,-1000000.,10000000.);//,fr,0.,100.) ;

//  RooRealVar n("n","n",300,0.,1000.);

//  RooRealVar a2("a2","a2",1.,0.,2.);
//  RooRealVar a3("a3","a3",1.,0.,2.);

//   RooFormulaVar f1("f1","n*(1-a2-a3)",RooArgList(n,a2,a3));
//   RooFormulaVar f2("f2","n*a2",RooArgList(n,a2));
//   RooFormulaVar f3("f3","n*a3",RooArgList(n,a3));

  // Templates 
  RooHistPdf h1("h1","h1",x,data1);
  RooHistPdf h2("h2","h2",x,data2);
  RooHistPdf h3("h3","h3",x,data3);

  // composite PDF  
  RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2,f3)) ;
 

  // Generate data 
  
  Int_t nevt=static_cast<int>(istat);
  
  //  RooDataSet *gtest = model.generate(x,nevt);

  // Fitting
  RooFitResult* res1 = model.fitTo(test,Minos(kTRUE),Extended(kTRUE), SumW2Error(kFALSE), Save());
  res1->Print();

  // Plotting
  gROOT->SetStyle("Plain");  
  gStyle->SetOptFit(111);
  gStyle->SetOptTitle(0);

  gStyle->SetCanvasDefH(600); //Height of canvas
  gStyle->SetCanvasDefW(600); //Width of canvas
  
  TCanvas *c0 = new TCanvas("c0","");

  RooPlot* frame = x.frame() ;
  test.plotOn(frame); //,Binning(nBins));
  // h3.plotOn(frame);

  model.plotOn(frame) ;
  
  model.paramOn(frame);
  model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
  model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
  model.plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
  
  frame->Draw();

  c0->Update();
  c0->Print(".png");

  const TMatrixDSym& cor = res1->correlationMatrix();
  const TMatrixDSym& cov = res1->covarianceMatrix();
  // Print correlation, covariance matrix
  cout << "correlation matrix" << endl;
  cor.Print();
  cout << "covariance matrix" << endl;
  //cout << "(0,0) = " << cov[0][0] << endl;
  //cout << f1.getVal() << endl;
  cov.Print();

  //calculate values of A2 and A3 with the appropriate errors
  double A2_val = 4.0 * f3.getVal() / (f1.getVal() + f2.getVal() + f3.getVal()); //the factor 4 is 1/k1...
  double A3_val = (16.0/(3.0*TMath::Pi())) * f2.getVal() / (f1.getVal() + f2.getVal() + f3.getVal());

  double A2dfdgamma = (f1.getVal() + f2.getVal())/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal())); 
  double A2dfdalpha = -1.0*f3.getVal()/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal()));
  double A2dfdbeta = A2dfdalpha;

  double A2comp1 = cov[2][2] * A2dfdgamma * A2dfdgamma;
  double A2comp2 = cov[0][0] * A2dfdalpha * A2dfdalpha;
  double A2comp3 = cov[1][1] * A2dfdbeta * A2dfdbeta;
  double A2comp4 = cov[1][2] * A2dfdgamma * A2dfdbeta * 2.0;
  double A2comp5 = cov[0][2] * A2dfdalpha * A2dfdgamma * 2.0;
  double A2comp6 = cov[0][1] * A2dfdalpha * A2dfdbeta * 2.0;

  double A2_err2 = A2comp1 + A2comp2 + A2comp3 + A2comp4 + A2comp5 + A2comp6;
  double A2_err = 4.0*sqrt(A2_err2);

  double A3dfdbeta = (f1.getVal() + f3.getVal())/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal()));
  double A3dfdalpha = -1.0*f2.getVal()/((f1.getVal() + f2.getVal() + f3.getVal())*(f1.getVal() + f2.getVal() + f3.getVal()));
  double A3dfdgamma = A2dfdalpha;

  double A3comp1 = cov[2][2] * A3dfdgamma * A3dfdgamma;
  double A3comp2 = cov[0][0] * A3dfdalpha * A3dfdalpha;
  double A3comp3 = cov[1][1] * A3dfdbeta * A3dfdbeta;
  double A3comp4 = cov[1][2] * A3dfdgamma * A3dfdbeta * 2.0;
  double A3comp5 = cov[0][2] * A3dfdalpha * A3dfdgamma * 2.0;
  double A3comp6 = cov[0][1] * A3dfdalpha * A3dfdbeta * 2.0;

  double A3_err2 = A3comp1 + A3comp2 + A3comp3 + A3comp4 + A3comp5 + A3comp6;;
  double A3_err = (16.0/(3.0*TMath::Pi())) * sqrt(A3_err2);

  cout << "A2 = " << A2_val << " +/- " << A2_err << endl;
  cout << "A3 = " << A3_val << " +/- " << fabs(A3_err) << endl;

  return;
  
  // toy MC study
  RooMCStudy mgr(model,model,x,"","mhv");
  mgr.generateAndFit(100,nevt,kTRUE);

  TCanvas *c1 = new TCanvas("c1","");
  RooPlot* m1frame = f1.frame();
  mgr.plotParamOn(m1frame);
  m1frame->Draw();
  c1->SaveAs("f1.png");
  
  TCanvas *c11 = new TCanvas("c11","");
  RooPlot* m1eframe = mgr.plotError(f1);
  m1eframe->Draw();
  c11->SaveAs("f1err.png");
  
  TCanvas *c111 = new TCanvas("c111","");
  RooPlot* m1pframe = mgr.plotPull(f1,-3,3,40,kTRUE);
  m1pframe->Draw();
  c111->SaveAs("f1pull.png");

  TCanvas *c2 = new TCanvas("c2","");
  RooPlot* m2frame = f2.frame();
  mgr.plotParamOn(m2frame);
  m2frame->Draw();
  c2->SaveAs("f2.png");

  TCanvas *c22 = new TCanvas("c22","");
  RooPlot* m2eframe = mgr.plotError(f2);
  m2eframe->Draw();
  c22->SaveAs("f2err.png");
  
  TCanvas *c222 = new TCanvas("c222","");
  RooPlot* m2pframe = mgr.plotPull(f2,-3,3,40,kTRUE);
  m2pframe->Draw();
  c222->SaveAs("f2pull.png");

  TCanvas *c3 = new TCanvas("c3","");
  TH2* h = f1.createHistogram("f1 vs f2",f2) ;
  mgr.fitParDataSet().fillHistogram(h,RooArgList(f1,f2)) ;
  h->Draw("BOX") ;
  c3->SaveAs("corr.png");

}
TLegend *legend() {
  
 TLegend *leg2 = new TLegend(0.57,0.6,0.92,0.92);
 leg2->SetFillStyle(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.06);
 leg2->SetTextFont(42); 
 
 return leg2;

}
