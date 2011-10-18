void roo_fitWHSStudy()
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

  TString bin1 = "50toinf";
  TString bin2 = "70toinf";
  TString bin3 = "90toinf";

  TString folder = "hltmu9_goodevsel";
  TString noMTpath = "";

  bool makePlots = true;
  bool printPlots = false;
  bool noMT = false;
  if(noMT) noMTpath = "_noMT";

  std::vector<TString> bins(1);//(3)
  bins.at(0) = bin1;
  //bins.at(1) = bin2;
  //bins.at(2) = bin3;

  //define the data file
  //TFile *templates = new TFile("results/" + folder + "/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile *templates = new TFile("results/" + folder + "/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  //TFile *dataplus = new TFile("results/" + folder + "/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile *dataplus = new TFile("results/" + folder + "/RecoRoutines_W-selection_realdata.root");

  //define the reference template file
  TFile *refTemplates = new TFile("results/GenRoutines_WJets_JuneMadgraph_1muonextra.root");


  double err1=0.0;
  double comberr=0.0;

  double lowlim_fit = -0.5;
  double uplim_fit = 1.8;
  Int_t rbin=10;

  TString canvas_name_plus = "RECOPT50_pLP";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",450,470);//900,320
  //c0->Divide(3,1);

  TString canvas_name_minus = "RECOPT50_mLP";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",450,470);//900,320
  //c1->Divide(3,1);
 
  for(unsigned int i=0; i<bins.size(); i++) {
    for(unsigned int j=0; j<charge.size(); j++) {
      //unsigned int index = i*charge.size() + j;
      //cout << "INDEX= " << index << endl;

      //these histograms define the number of events in the complete templates so we can apply correction factors for acceptance etc.
      //do not change these histograms!
      TString refHist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
      TString refHist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
      TString refHist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
      TString refHistData = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j);
      TH1D *refTempHist1 = (TH1D*)refTemplates->Get(refHist1);
      TH1D *refTempHist2 = (TH1D*)refTemplates->Get(refHist2);
      TH1D *refTempHist3 = (TH1D*)refTemplates->Get(refHist3);
      TH1D *refTempHistData = (TH1D*)refTemplates->Get(refHistData);
      refTempHist1->Rebin(rbin);
      refTempHist2->Rebin(rbin);
      refTempHist3->Rebin(rbin);
      refTempHistData->Rebin(rbin);

      double mLHint=0.0, mRHint=0.0, mLOint=0.0, mDATAint=0.0;
      mLHint = refTempHist1->Integral(refTempHist1->GetXaxis()->FindBin(lowlim_fit), refTempHist1->GetXaxis()->FindBin(uplim_fit));
      mRHint = refTempHist2->Integral(refTempHist2->GetXaxis()->FindBin(lowlim_fit), refTempHist2->GetXaxis()->FindBin(uplim_fit));
      mLOint = refTempHist3->Integral(refTempHist3->GetXaxis()->FindBin(lowlim_fit), refTempHist3->GetXaxis()->FindBin(uplim_fit));
      mDATAint = refTempHistData->Integral(refTempHistData->GetXaxis()->FindBin(lowlim_fit), refTempHistData->GetXaxis()->FindBin(uplim_fit));

      //these histograms are the ones we want to fit
      //TString Hist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
      //TString Hist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
      //TString Hist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
      //TString Hist_data1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j);// + "MuonAcc";
      TString Hist1 = "RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPF"+ charge.at(j) + "_LH";
      TString Hist2 = "RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPF"+ charge.at(j) + "_RH";
      TString Hist3 = "RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPF"+ charge.at(j) + "_LO";
      TString Hist_data1 = "RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPF"+ charge.at(j);

      TH1D *mc1 = (TH1D*)templates->Get(Hist1);
      TH1D *mc2 = (TH1D*)templates->Get(Hist2);
      TH1D *mc3 = (TH1D*)templates->Get(Hist3);
      TH1D *datahist = (TH1D*)dataplus->Get(Hist_data1);

      mc1->Rebin(rbin);
      mc2->Rebin(rbin);
      mc3->Rebin(rbin);
      datahist->Rebin(rbin);
      //datahist->Scale(100);
      //datahist->Scale(invWeightW);//to get MC errors - otherwise comment out

      //Double_t istat=datahist->Integral();
      
      // Start RooFit session
  
      RooRealVar x("x","ICVar",lowlim_fit,uplim_fit);
      // Import binned Data
      RooDataHist data1("data1","dataset with WHICVarPlus",x,mc1);
      RooDataHist data2("data2","dataset with WHICVarPlus",x,mc2);
      RooDataHist data3("data3","dataset with WHICVarPlus",x,mc3);
      RooDataHist test("test_data","dataset with WHICVarPlus",x,datahist);

      //Float_t fr = (1./3.)*istat;
      Float_t fr = (1.0/3.0);

      // Relative fractions - allow them to float to negative values too if needs be
      RooRealVar f1("fL","fL fraction", fr,0.0,1.0);
      RooRealVar f2("fR","fR fraction", fr,0.0,1.0);
      RooRealVar f3("f0","f0 fraction", fr,0.0,1.0);
      //RooRealVar f3("f0","f0 fraction",0.21); //fix the value as opposed to let it float

      // Templates 
      RooHistPdf h1("h1","h1",x,data1);
      RooHistPdf h2("h2","h2",x,data2);
      RooHistPdf h3("h3","h3",x,data3);
      
      // composite PDF  
      RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2)) ;
 
      // Generate data 
      //Int_t nevt=static_cast<int>(istat);

      //RooDataSet *gtest = model.generate(x,nevt);

      // Fitting
      RooFitResult * res1 = model.fitTo(test,Minos(kTRUE), Save());
      //res1->Print();

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
	if(charge.at(j) == "Plus") c0->cd();//c0->cd(i+1);
	if(charge.at(j) == "Minus") c1->cd();//c1->cd(i+1);
	RooPlot* frame = x.frame();
	test.plotOn(frame); 
	model.plotOn(frame);
	//model.paramOn(frame);
	model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
	model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
	model.plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
	frame->GetXaxis()->SetRangeUser(-2.5,2.5);
	TString xaxislabel = "";
	if(charge.at(j) == "Plus") xaxislabel = "LP(#mu^{+})";
	else xaxislabel = "LP(#mu^{-})";
	frame->GetXaxis()->SetTitle(xaxislabel);
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
      cov.Print();

      double F1 = f1.getVal();
      double F2 = f2.getVal();
      double F3 = (1.0 - F1 - F2);

      double F1_err = sqrt(cov[0][0]);
      double F2_err = sqrt(cov[1][1]);
      double COV = cov[0][1];

      cout << "Fitting bin " << bins.at(i) << " for " << charge.at(j) << " charge: " << endl;
      cout << "NO ACCEPTANCE CORRECTIONS: " << endl;
      cout << "fL = " << F1 << " +/- " << F1_err << endl;
      cout << "fR = " << F2 << " +/- " << F2_err << endl;
      //cout << "f0 = " << F3 << " +/- " << "N/A" << endl;
      cout << "Covariance Term = " << COV << endl;
      //use the following if you want to talk about combined charges (we decided against this as the values are not strictly the same)
      //if(j==0) err1 = F1_err;
      //if(j==1) {
      //  comberr = 0.5*sqrt((err1*err1)+(F1_err*F1_err));
      //  cout << "Combined left error = " << comberr << endl;
      //}
      double LHint=0.0, RHint=0.0, LOint=0.0, DATAint=0.0;
      LHint = mc1->Integral(mc1->GetXaxis()->FindBin(lowlim_fit), mc1->GetXaxis()->FindBin(uplim_fit));
      RHint = mc2->Integral(mc2->GetXaxis()->FindBin(lowlim_fit), mc2->GetXaxis()->FindBin(uplim_fit));
      LOint = mc3->Integral(mc3->GetXaxis()->FindBin(lowlim_fit), mc3->GetXaxis()->FindBin(uplim_fit));
      DATAint = datahist->Integral(datahist->GetXaxis()->FindBin(lowlim_fit), datahist->GetXaxis()->FindBin(uplim_fit));
      //For debug:
      //cout << "Template Integrals: " << endl;
      //cout << "LH: " << LHint << endl;
      //cout << "RH: " << RHint << endl;
      //cout << "LO: " << LOint << endl;
      //cout << "Data Integral: " << DATAint << endl;

      double accLH=0.0, accRH=0.0;
      accLH = (mLHint / mDATAint) / (LHint / DATAint);
      accRH = (mRHint / mDATAint) / (RHint / DATAint);
      F1 *= accLH;
      F2 *= accRH;
      F1_err *= accLH;
      F2_err *= accRH;
      COV *= accLH;
      COV *= accRH;

      cout << "accLH = " << accLH << endl;
      cout << "accRH = " << accRH << endl;

      cout << "WITH ACCEPTANCE CORRECTIONS: " << endl;
      cout << "fL = " << F1 << " +/- " << F1_err << endl;
      cout << "fR = " << F2 << " +/- " << F2_err << endl;
      cout << "(fL - fR) = " << F1 - F2 << " +/- " << sqrt((F1_err*F1_err) + (F2_err*F2_err) - (2.0 * COV)) << endl;
      cout << "f0 = " << (1.0 - F1 - F2) << " +/- " << sqrt((F1_err*F1_err) + (F2_err*F2_err) + (2.0 * COV)) << endl;

    }
  }
  if(makePlots && printPlots) {
    c0->Print(canvas_name_plus+".png");
    c1->Print(canvas_name_minus+".png");
  }
  
  return;

}
