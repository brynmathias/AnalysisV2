TH1D* combi(int binMin,int binMax,TH1D* bP, TH1D* hM)
{
  int nBins = binMax-binMin;
  TH1D* comb = new TH1D("test","HIHP",2*(nBins),0,2.*(nBins));

  for(int i=1;i<nBins;i++)
  {
    comb->SetBinContent(i,bP->GetBinContent(i+binMin));
    comb->SetBinContent(i+nBins,hM->GetBinContent(i+binMin));
  }
  return comb;
}

void roo_fitWHSStudyBGCombined()
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

  std::vector<TString> bins(1);
  bins.at(0) = bin1;
  //bins.at(1) = bin2;
  //bins.at(2) = bin3;

  TString MuonPtCut = "MuPt10MT30/";

  //these values specify where you which range of the LP you want to look at (in units of bins: 500, -2.5, 2.5)
  int binMin = 200;//200
  int binMax = 400;//400

  //we only set up the machinery for the plus charge
  //TFile *dataplus = new TFile("../results/MuonPlotting_WJets_madgraph.root");
  TFile *dataplus = new TFile("results/"+ MuonPtCut +"RecoRoutines_W-selection_WJets-lite_madgraph.root");
  
  TFile * QCDbg = new TFile("results/"+ MuonPtCut +"RecoRoutines_W-selection_QCDMu-lite_Pythia.root");
  //TFile * Zbg = new TFile("../results/MuonPlotting_ZJets_madgraph.root");
  TFile * Zbg = new TFile("results/"+ MuonPtCut +"RecoRoutines_W-selection_ZJets-lite_madgraph.root");

  bool makePlots = true;
  bool printPlots = false;
  bool doToyMC = false;
  bool AddZ = true;

  double err1=0.0;
  double comberr=0.0;
  double value1=0.0;

  TString canvas_name_plus = "MC_WHelicityFramePlots_PlusICVar";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",900,320);
  c0->Divide(3,1);

  TString canvas_name_minus = "MC_WHelicityFramePlots_MinusICVar";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",900,320);
  c1->Divide(3,1);

  TString pulls_plus = "MC_WHelicityFramePlots_PlusICVarPull";
  TCanvas *cpp = new TCanvas(pulls_plus,"",900,320);
  cpp->Divide(3,1);

  TString pulls_minus = "MC_WHelicityFramePlots_MinusICVarPull";
  TCanvas *cpm = new TCanvas(pulls_minus,"",900,320);
  cpm->Divide(3,1);
 
  for(unsigned int i=0; i<bins.size(); i++) {
    //for(unsigned int j=0; j<charge.size(); j++) {
      //unsigned int index = i*charge.size() + j;
      //cout << "INDEX= " << index << endl;
      Int_t rbin=10;
      //these histograms define the number of events in the complete templates so we can apply correction factors for acceptance etc.
      //do not change these histograms!
//      TString refHist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
//      TString refHist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
//      TString refHist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
//      TH1D *refTempHist1 = (TH1D*)refTemplates->Get(refHist1);
//      TH1D *refTempHist2 = (TH1D*)refTemplates->Get(refHist2);
//      TH1D *refTempHist3 = (TH1D*)refTemplates->Get(refHist3);

      //add the two QCD charge templates together - do this once per charge otherwise root will rebin the hist twice etc
      //if(j == 0) {
	TH1D *qcdbg = (TH1D*)QCDbg->Get("RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFPlus"); 
	//qcdbg->Rebin(rbin);
	TH1D *qcdbg2 = (TH1D*)QCDbg->Get("RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFMinus");
	//qcdbg2->Rebin(rbin);
	qcdbg->Add(qcdbg2);
	qcdbg->Scale(0.5);
	TH1D * qcdbgtemplate = combi(binMin,binMax,qcdbg,qcdbg);
	qcdbgtemplate->Rebin(rbin);
      //}

      //check to add the Z bg - but do this separately for both charges (templates expected to be slightly different)
      if(AddZ) {
	TH1D *zbg1 = (TH1D*)Zbg->Get("RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFPlus"); 
	//zbg1->Rebin(rbin);
	TH1D *zbg2 = (TH1D*)Zbg->Get("RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFMinus");
	//zbg2->Rebin(rbin);

	TH1D * zbgtemplate = combi(binMin,binMax,zbg1,zbg2);
	zbgtemplate->Rebin(rbin);
	zbgtemplate->Add(qcdbgtemplate);
      }

      
      //these histograms are the ones we want to fit
      //TString Hist1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LH";
      //TString Hist2 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_RH";
      //TString Hist3 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j) + "_LO";
      //TString Hist_data1 = "MC_WPlots_" + bins.at(i) + "/MC_ICVar" + charge.at(j);
      TString Hist1 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFPlus_LH";
      TString Hist2 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFPlus_RH";
      TString Hist3 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFPlus_LO";
      TString Hist_data1 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFPlus";

      TString Hist4 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFMinus_LH";
      TString Hist5 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFMinus_RH";
      TString Hist6 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFMinus_LO";
      TString Hist_data2 = "RECO_PolPlots_" + bins.at(i) + "/RECO_ICVarPFMinus";

      TH1D *mc1 = (TH1D*)dataplus->Get(Hist1);
      TH1D *mc2 = (TH1D*)dataplus->Get(Hist2);
      TH1D *mc3 = (TH1D*)dataplus->Get(Hist3);
      TH1D *datahist1 = (TH1D*)dataplus->Get(Hist_data1);     

      TH1D *mc4 = (TH1D*)dataplus->Get(Hist4);
      TH1D *mc5 = (TH1D*)dataplus->Get(Hist5);
      TH1D *mc6 = (TH1D*)dataplus->Get(Hist6);
      TH1D *datahist2 = (TH1D*)dataplus->Get(Hist_data2);   

      TH1D * template1 = combi(binMin,binMax,mc1,mc4);//mc4
      TH1D * template2 = combi(binMin,binMax,mc2,mc5);//mc5
      TH1D * template3 = combi(binMin,binMax,mc3,mc6);//mc6
      TH1D * datahist = combi(binMin,binMax,datahist1,datahist2);//datahist1
      
      double accFactor1 = template1->Integral() / (template1->Integral() + template2->Integral() + template3->Integral());
      double accFactor2 = template2->Integral() / (template1->Integral() + template2->Integral() + template3->Integral());

      //we are only fitting for fL and fR
//       double accFactor1 = refTempHist1->Integral() / mc1->Integral();
//       double accFactor2 = refTempHist2->Integral() / mc2->Integral();
//       double accFactor3 = refTempHist3->Integral() / mc3->Integral();
//       double normFactor = (mc1->Integral() + mc2->Integral() + mc3->Integral()) / (refTempHist1->Integral() + refTempHist2->Integral() + refTempHist3->Integral());

      template1->Rebin(rbin);
      template2->Rebin(rbin);
      template3->Rebin(rbin);
      datahist->Rebin(rbin);

      //datahist->Scale(invWeightW);//to get MC errors - otherwise comment out
      datahist->Add(zbgtemplate);
      //add some scaling in here if required e.g. to "change" integrated luminosity
      //datahist->Scale(.3);
      //zbgtemplate->Scale(.3);
      Double_t istat=datahist->Integral();
      
      // Start RooFit session
      double range = double(binMax-binMin)*2.0;
      RooRealVar x("x","ICVar",0.0,range);
      // Import binned Data
      RooDataHist data1("data1","dataset with WHICVarPlus",x,template1);
      RooDataHist data2("data2","dataset with WHICVarPlus",x,template2);
      RooDataHist data3("data3","dataset with WHICVarPlus",x,template3);
      RooDataHist data4("data4","dataset with WHICVar",x,zbgtemplate);
      RooDataHist test("test_data","dataset with WHICVarPlus",x,datahist);

      //Float_t fr = (1./3.)*istat;
      Float_t fr = (1.0/3.0);

      // Relative fractions - allow them to float to negative values too if needs be
      RooRealVar f1("fL","fL fraction",fr,0.0,1.0);
      RooRealVar f2("fR","fR fraction", fr,0.0,1.0);
      RooRealVar f3("f0","f0 fraction",fr,0.0,1.0);
      RooRealVar f4("fs","fs fraction",1.0 - (zbgtemplate->Integral()/istat));//to fix the QCD (+Z) bg i.e. subtract it
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

      //do { //some quality criteria for when you want to redice the plots
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
	//if(charge.at(j) == "Plus") c0->cd(i+1);
	//if(charge.at(j) == "Minus") c1->cd(i+1);
	c0->cd(i+1);
	RooPlot* frame = x.frame();
	test.plotOn(frame,Binning(10)); //either test or *gtest
	model.plotOn(frame);
	//model.paramOn(frame);
	model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
	model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
	model.plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
	model.plotOn(frame, Components(bkg),LineColor(kBlack),LineStyle(kDashed)) ;
	frame->GetXaxis()->SetRangeUser(0.,range);
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
      cor.Print();
      //cout << "covariance matrix" << endl;
      //cout << "(0,0) = " << cov[0][0] << endl;
      //cout << f1.getVal() << endl;
      cov.Print();

      double F1 = f1.getVal() * (1.0/3.0) / accFactor1;
      double F2 = f2.getVal() * (1.0/3.0) / accFactor2;
      double F3 = (1.0 - F1 - F2);

      double F1_err = sqrt(cov[0][0]) * (1.0/3.0) / accFactor1;
      double F2_err = sqrt(cov[1][1]) * (1.0/3.0) / accFactor2;

      double F1F2_COV = 2.0*cov[0][1] * ((1.0/3.0) / accFactor1) * ((1.0/3.0) / accFactor2);

      cout << "Fitting bin " << bins.at(i) << endl;//<< " for " << charge.at(j) << " charge: " << endl;
      cout << "fL = " << F1 << " +/- " << F1_err << endl;
      cout << "fR = " << F2 << " +/- " << F2_err << endl;
      cout << "f0 = " << F3 << " +/- " << "N/A" << endl;
      cout << "fL-fR = " << F1-F2 << " +/- " << sqrt((F1_err*F1_err) + (F2_err*F2_err) - F1F2_COV) << endl; 
      /*
      if(j==0) {
	err1 = F1_err;
	value1 = F1;
      }
      if(j==1) {
        comberr = 0.5*sqrt((err1*err1)+(F1_err*F1_err));
        cout << "fL combined  = " << (F1+value1)/2.0 << " +/- " << comberr << endl;
      }
*/
      // toy MC study
      if(doToyMC) {
	RooMCStudy mgr(model,model,x,"","mhv");
	mgr.generateAndFit(1000,nevt,kTRUE);    
	RooPlot* m1pframe = mgr.plotPull(f1,-3,3,20,kTRUE);
	if(charge.at(j) == "Plus") cpp->cd(i+1);
	if(charge.at(j) == "Minus") cpm->cd(i+1);
	m1pframe->Draw();
      }

      //}
  }
  if(makePlots && printPlots) {
    c0->Print(canvas_name_plus+".png");
    c1->Print(canvas_name_minus+".png");
    if(doToyMC) {
      cpp->Print(pulls_plus+".png");
      cpm->Print(pulls_minus+".png");
    }
  }

//   TCanvas * c3 = new TCanvas();
//   TH1D * sensitivity = new TH1D("sensitivity","sensitivity P_{T}(#mu)>20GeV, |#eta(#mu)|<2.1, pfMHT>70GeV  ;integrated luminosity [pb^{-1}];#sigma(f_{L})",10,-0.5,9.5);
// //for MHT without backgrounds:
// //   sensitivity->Fill(1.0, 0.225);
// //   sensitivity->Fill(3.0, 0.137);
// //   sensitivity->Fill(6.0, 0.098);
// //   sensitivity->Fill(9.0, 0.080);
// //for pfMHT with backgrounds (fixed QCD):
//   sensitivity->Fill(1.0, 0.232);
//   sensitivity->Fill(3.0, 0.137);
//   sensitivity->Fill(6.0, 0.097);
//   sensitivity->Fill(9.0, 0.079);
//   sensitivity->SetMarkerStyle(5);
//   sensitivity->SetMarkerSize(5);
//   sensitivity->Draw("p");
//   TF1 * lumifit = new TF1("lumifit","[0]/sqrt(x)",0.,10.);
//   sensitivity->Fit(lumifit,"0");
//   lumifit->DrawCopy("same");

  return;

}
