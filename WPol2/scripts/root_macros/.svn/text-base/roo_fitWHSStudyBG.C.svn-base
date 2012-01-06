void roo_fitWHSStudyBG()
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
  bool doToyMC = false;
  bool AddQCD = false;
  bool AddQCDbgtemplate = false;
  bool AddZ = true;
  bool AddZbgtemplate = true;
  bool AddTT = true;
  bool AddTTbgtemplate = true;
  bool noMT = false;
  bool realdata = false;
  if(noMT) noMTpath = "_noMT";

  std::vector<TString> bins(1);
  bins.at(0) = bin1;
  //bins.at(1) = bin2;
  //bins.at(2) = bin3;

  //define the data files
  TFile * templates = new TFile("results/" + folder + "/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  //TFile * dataplus = new TFile("results/" + folder + "/RecoRoutines_W-selection_realdata.root");
  TFile * dataplus = new TFile("results/" + folder + "/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile * QCDbg = new TFile("results/" + folder + "/RecoRoutines_W-selection_QCD_AllPtBins_7TeV_Pythia.root");
  TFile * TTbg = new TFile("results/" + folder + "/RecoRoutines_W-selection_TTbarJets_tauola_madgraph_June2010.root");
  TFile * Zbg = new TFile("results/" + folder + "/RecoRoutines_W-selection_ZJets_madgraph_June2010.root");

  //define the reference template file
  TFile * refTemplates = new TFile("results/GenRoutines_WJets_JuneMadgraph_1muonextra.root");

  double err1=0.0;
  double comberr=0.0;
  double value1=0.0;

  double lowlim_fit = -0.5;
  double uplim_fit = 1.8;
  Int_t rbin=10;

  TString canvas_name_plus = "MC_WHelicityFramePlots_PlusLPVar";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",450,470);//900,320);
  //c0->Divide(3,1);

  TString canvas_name_minus = "MC_WHelicityFramePlots_MinusLPVar";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",450,470);//900,320);
  //c1->Divide(3,1);

  TString pulls_plus = "MC_WHelicityFramePlots_PlusICVarPull";
  TCanvas *cpp = new TCanvas(pulls_plus,"",450,470);//900,320);
  //cpp->Divide(3,1);

  TString pulls_minus = "MC_WHelicityFramePlots_MinusICVarPull";
  TCanvas *cpm = new TCanvas(pulls_minus,"",450,470);//900,320);
  //cpm->Divide(3,1);
 
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

      bool firstbg = true;

      if(AddQCD) {
	//add the two QCD charge templates together to get average shape
	TH1D * qcdbg = (TH1D*)((TH1D*)QCDbg->Get("RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPFPlus"))->Clone();
	TH1D * qcdbg2 = (TH1D*)((TH1D*)QCDbg->Get("RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPFMinus"))->Clone();
	qcdbg->Rebin(rbin);
	qcdbg2->Rebin(rbin);
	qcdbg->Add(qcdbg2);
	qcdbg->Scale(0.5);
	if(AddQCDbgtemplate) {
	  if(firstbg) {
	    TH1D * bgtemplate = (TH1D*)qcdbg->Clone();
	    firstbg = false;
	  } else bgtemplate->Add(qcdbg);	  
	}
      }

      if(AddTT) {
	//Since the shape expected is the same for both charges, do the same as in the QCD case
	TH1D * ttbg = (TH1D*)((TH1D*)TTbg->Get("RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPFPlus"))->Clone();
	TH1D * ttbg2 = (TH1D*)((TH1D*)TTbg->Get("RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPFMinus"))->Clone();
	ttbg->Rebin(rbin);
	ttbg2->Rebin(rbin);
	ttbg->Add(ttbg2);
	ttbg->Scale(0.5);
	if(AddTTbgtemplate) {
	  if(firstbg) {
	    TH1D * bgtemplate = (TH1D*)ttbg->Clone();
	    firstbg = false;
	  } else bgtemplate->Add(ttbg);
	}
      }
      
      if(AddZ) {
	//check to add the Z bg - but do this separately for both charges (templates expected to be slightly different)
	TH1D *zbg =(TH1D*)((TH1D*)Zbg->Get("RECO_PolPlots_" + bins.at(i) + noMTpath + "/RECO_ICVarPF" + charge.at(j)))->Clone(); 
	zbg->Rebin(rbin);
	if(AddZbgtemplate) {
	  if(firstbg) {
	    TH1D * bgtemplate = (TH1D*)zbg->Clone();
	    firstbg = false;
	  } else bgtemplate->Add(zbg);
	}
      }
      
      //these histograms are the ones we want to fit
      //TString Hist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
      //TString Hist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
      //TString Hist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
      //TString Hist_data1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j);
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

      //calculate the acceptance corrections at this stage - before adding anything to the W templates
      double LHint=0.0, RHint=0.0, LOint=0.0, DATAint=0.0;
      LHint = mc1->Integral(mc1->GetXaxis()->FindBin(lowlim_fit), mc1->GetXaxis()->FindBin(uplim_fit));
      RHint = mc2->Integral(mc2->GetXaxis()->FindBin(lowlim_fit), mc2->GetXaxis()->FindBin(uplim_fit));
      LOint = mc3->Integral(mc3->GetXaxis()->FindBin(lowlim_fit), mc3->GetXaxis()->FindBin(uplim_fit));
      DATAint = datahist->Integral(datahist->GetXaxis()->FindBin(lowlim_fit), datahist->GetXaxis()->FindBin(uplim_fit));

      if(!realdata) {
        if(AddQCD) datahist->Add(qcdbg);
        if(AddTT) datahist->Add(ttbg);
        if(AddZ) datahist->Add(zbg);
      }
      Double_t istat=datahist->Integral();
      
      // Start RooFit session
  
      RooRealVar x("x","ICVar",lowlim_fit,uplim_fit);
      // Import binned Data
      RooDataHist data1("data1","dataset with WHICVarPlus",x,mc1);
      RooDataHist data2("data2","dataset with WHICVarPlus",x,mc2);
      RooDataHist data3("data3","dataset with WHICVarPlus",x,mc3);
      RooDataHist data4("data4","dataset with WHICVar",x,bgtemplate);
      RooDataHist test("test_data","dataset with WHICVarPlus",x,datahist);

      //Float_t fr = (1./3.)*istat;
      Float_t fr = (1.0/3.0);

      // Relative fractions - allow them to float to negative values too if needs be
      RooRealVar f1("fL","fL fraction",fr,0.0,1.0);
      RooRealVar f2("fR","fR fraction", fr,0.0,1.0);
      RooRealVar f3("f0","f0 fraction",fr,0.0,1.0);
      RooRealVar f4("fs","fs fraction",1.0 - (bgtemplate->Integral()/istat));//to fix the backgrounds i.e. subtract them
      //RooRealVar f4("fs","fs fraction",0.988);//to fix the backgrounds i.e. subtract them
      //RooRealVar f4("fs","fs fraction",fr,0.0,1.0);//to fit for the QCD (+Z) bg

      // Templates 
      RooHistPdf h1("h1","h1",x,data1);
      RooHistPdf h2("h2","h2",x,data2);
      RooHistPdf h3("h3","h3",x,data3);
      
      // composite PDF  
      RooHistPdf bkg("bkg","bkg",x,data4);
      RooAddPdf sig("sig","sig",RooArgList(h1,h2,h3),RooArgList(f1,f2)) ;
      RooAddPdf model("model","model",RooArgList(sig,bkg),f4);
      //RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2)) ;
 
      // Generate data 
      Int_t nevt=static_cast<int>(istat);

      //do {
      //RooDataSet *gtest = model.generate(x,nevt);

      // Fitting
      RooFitResult * res1 = model.fitTo(test,Minos(kTRUE), Save());//replace test with *gtest etc
      //res1->Print();
      //} while((f1.getVal() * (1.0/3.0) / accFactor1) < 0.45 || (f1.getVal() * (1.0/3.0) / accFactor1) > 0.55 || (1.0 - f1.getVal() - f2.getVal()) < 0.0);
     

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
	if(charge.at(j) == "Plus") c0->cd();//(i+1);
	if(charge.at(j) == "Minus") c1->cd();//(i+1);
	RooPlot* frame = x.frame();
	test.plotOn(frame); //either test or *gtest
	model.plotOn(frame);
	//model.paramOn(frame);
	model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
	model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
	model.plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
	model.plotOn(frame, Components(bkg),LineColor(kBlack),LineStyle(kDashed)) ;
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
      // toy MC study
      if(doToyMC) {
	RooMCStudy mgr(model,model,x,"","mhv");
	mgr.generateAndFit(1000,nevt,kTRUE);    
	RooPlot* m1pframe = mgr.plotPull(f1,-3,3,20,kTRUE);
	if(charge.at(j) == "Plus") cpp->cd();//(i+1);
	if(charge.at(j) == "Minus") cpm->cd();//(i+1);
	m1pframe->Draw();
      }

    }
  }
  if(makePlots && printPlots) {
    c0->Print(canvas_name_plus+".png");
    c1->Print(canvas_name_minus+".png");
    if(doToyMC) {
      cpp->Print(pulls_plus+".png");
      cpm->Print(pulls_minus+".png");
    }
  }

  return;

}
