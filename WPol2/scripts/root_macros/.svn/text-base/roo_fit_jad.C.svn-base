void roo_fit_jad()
{

  gSystem->Load("libRooFit"); using namespace RooFit;

  TString Hist1 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus_LH";
  TString Hist2 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus_RH";
  TString Hist3 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus_LO";
  TString Hist_data1 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus";
  // TString Hist_data1 = "MC_WPlots_100toinf/MC_ICVarPlusMuonAcc";


  //   TString Hist1 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_LH";
  //   TString Hist2 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_RH";
  //   TString Hist3 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_LO";
  //   TString Hist_data1 = "RECO_PolPlots_100toinf/RECO_ICVarPlus";

  //      TString Hist1 = "RECO_PolPlots_50to75/RECO_ICVarPlus_LH";
  //     TString Hist2 = "RECO_PolPlots_50to75/RECO_ICVarPlus_RH"; 
  //    TString Hist3 = "RECO_PolPlots_50to75/RECO_ICVarPlus_LO";
  //    TString Hist_data1 = "RECO_PolPlots_50to75/RECO_ICVarPlus";
  
  // TString Hist1 = "RECO_PolPlots_75to100/RECO_ICVarPlus_LH";
     // TString Hist2 = "RECO_PolPlots_75to100/RECO_ICVarPlus_RH";
     //  TString Hist3 = "RECO_PolPlots_75to100/RECO_ICVarPlus_LO";
     //    TString Hist_data1 = "RECO_PolPlots_75to100/RECO_ICVarPlus";
  
//    TString Hist1 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_LH";
//    TString Hist2 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_RH";
//    TString Hist3 = "RECO_PolPlots_100toinf/RECO_ICVarPlus_LO";
//    TString Hist_data1 = "RECO_PolPlots_100toinf/RECO_ICVarPlus";
  
    //  TString Hist_data1 = "RECO_PolPlots_100toinf/RECO_ICVarMinus";
  TFile *data = new TFile("results/GenW_CS_ZJets-lite_madgraph_50_75_100_plus.root");

  // TFile *data = new TFile("results/RecoW_WJets_madgraph_ICVAR_reweighting_test.root");
  
  Int_t rbin=10;

  TH1D *mc1 = (TH1D*)data->Get(Hist1);
  TH1D *mc2 = (TH1D*)data->Get(Hist2);
  TH1D *mc3 = (TH1D*)data->Get(Hist3);

  mc1->Rebin(rbin);
  mc2->Rebin(rbin);
  mc3->Rebin(rbin);

  float allmc = mc1->Integral()+mc2->Integral()+mc3->Integral();
  cout <<"all: "<< allmc << " " << mc1->Integral()/allmc <<" "  << mc2->Integral()/allmc<<" "  << mc3->Integral()/allmc<< endl;
  float scalef_1 =   allmc/mc1->Integral();
  float scalef_2 =    allmc/mc2->Integral();
  float scalef_3 =    allmc/mc3->Integral();
  TH1D *test1 = (TH1D*) mc1->Clone();
  test1->Add(mc2,+1);
  test1->Add(mc3,+1);

  TH1D *test2 = (TH1D*)data->Get(Hist_data1);
  test2->Rebin(rbin);
  //   test2->Scale(45);


  Double_t istat=test2->Integral();
  Int_t nBins=mc1->GetNbinsX();
 
  // Start RooFit session
  
  //RooRealVar x("x","ICvar",-2.5,2.5);
  RooRealVar x("x","CosThetaStar",-0.9,0.9) ;
  // Import binned Data
  RooDataHist data1("data1","dataset with ICvar",x,mc1);
  RooDataHist data2("data2","dataset with ICvar",x,mc2);
  RooDataHist data3("data3","dataset with ICvar",x,mc3);

  RooDataHist test("test_data","dataset with ICvar",x,test2);
  //  RooHistPdf htest("htest","htest",x,test);

  Float_t fr = (1./3.);

  // Helicity fractions
  RooRealVar f1("fL","fL fraction",fr,0.,1.);
  RooRealVar f2("fR","fR fraction",fr,0.,1.);
  RooRealVar f3("f0","f0 fraction",fr,0.,1.) ;

  RooRealVar n("n","n events",istat,0.,10000.);
  
  RooFormulaVar ff1("ff1","n*fL",RooArgList(n,f1)) ;
  RooFormulaVar ff2("ff2","n*fR",RooArgList(n,f2)) ;
  RooFormulaVar ff3("ff3","n*f0",RooArgList(n,f1,f2));

  // Templates 
  RooHistPdf h1("h1","h1",x,data1);
  RooHistPdf h2("h2","h2",x,data2);
  RooHistPdf h3("h3","h3",x,data3);
 
  RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2));

  // composite PDF
  //  RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2)) ;
 


 // RooAddPdf model("model","model",RooArgList(h1,h2,h3),RooArgList(f1,f2)) ;
  // Generate data 
  
  Int_t nevt=static_cast<int>(istat);
  
  RooDataSet *gtest = model.generate(x,nevt);

  // Fitting
  //  model.fitTo(*gtest,Minos(kTRUE),Extended(kTRUE));
  model.fitTo(test,Minos(kTRUE));
  
  // Plotting
  gROOT->SetStyle("Plain");  
  gStyle->SetOptFit(111);

  gStyle->SetCanvasDefH(600); //Height of canvas
  gStyle->SetCanvasDefW(600); //Width of canvas
  
  TCanvas *c0 = new TCanvas("c0","");
  TLegend* leg = new  TLegend(.5,.5,.8,.8,"");

  RooPlot* frame = x.frame() ;
  //gtest->plotOn(frame,Binning(nBins));
  //gtest->plotOn(frame,Binning(21));
  test.plotOn(frame);
  model.plotOn(frame) ;
  //model.paramOn(frame);
  model.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed)) ;
  model.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed)) ;
  model.plotOn(frame, Components(h3),LineColor(kBlack),LineStyle(kDashed)) ;
  frame->Draw() ;

  test2->SetLineColor(kBlue);
  test2->SetLineWidth(3);
  leg->AddEntry(test2,"fit result","l");
  mc1->SetLineColor(kRed);
  mc1->SetLineStyle(2);
  mc1->SetLineWidth(3);
  leg->AddEntry(mc1,"f_{L}","l");
  mc2->SetLineColor(kGreen);
  mc2->SetLineStyle(2);
  mc2->SetLineWidth(3);
  leg->AddEntry(mc2,"f_{R}","l");
  mc3->SetLineStyle(2);
  mc3->SetLineWidth(3);
  leg->AddEntry(mc3,"f_{0}","l");
  //leg->LineColor(0);
  leg->Draw("same") ;

  cout << "Val " << f1.getVal() << " Error: " <<  f1.getError() << endl;
  cout << "Val " << f2.getVal() << " Error: " <<  f2.getError() << endl;
  cout << " new error: " << endl;
  cout <<  scalef_1 <<" "<<  scalef_2 << " " << scalef_3  <<endl;
  cout <<  3*scalef_1/(scalef_1+scalef_2+scalef_3) <<" "<<  3*scalef_2/(scalef_1+scalef_2+scalef_3)<< " " << 3*scalef_3/(scalef_1+scalef_2+scalef_3)  <<endl;
  cout << "Val " << f1.getVal()*3*scalef_1/(scalef_1+scalef_2+scalef_3) << " Error: " <<  f1.getError()*3*scalef_1/(scalef_1+scalef_2+scalef_3) << endl;
  cout << "Val " << f2.getVal()*3*scalef_2/(scalef_1+scalef_2+scalef_3) << " Error: " <<  f2.getError()*3*scalef_2/(scalef_1+scalef_2+scalef_3)  << endl;


  c0->Update();
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
