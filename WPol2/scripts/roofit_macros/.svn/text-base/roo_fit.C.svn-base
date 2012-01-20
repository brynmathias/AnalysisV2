#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooMinuit.h"
#include "RooSimultaneous.h"
#include "RooCategory.h"
#include "TCanvas.h"
#include "RooPlot.h"

using namespace RooFit ;


struct fit_info{
  double val1;
  double val2;
  double err1;
  double err2;
  double corr1;
  double corr2;
  double corr3;
  double val1_corr;
  double val2_corr;
  double err1_corr;
  double err2_corr;
  double gcor1;
  double gcor2;
  double gcor12;
};

TString dir ="RECO_ElPolPlots_PostMHT50/";
// TString dir ="RECO_ElPolPlots_PostMHT50MET30/";
/* TFile *data = new TFile("eWPol_Signal_Wjets.root"); */
/* TFile *fbkg= new TFile("eWPol_Signal_QCD_enriched.root"); */

Int_t rbin=10;

// W+ templates
TString pHist1 = dir+"RECO_ICVarPFPlus_LH";
TString pHist2 = dir+"RECO_ICVarPFPlus_RH";
TString pHist3 = dir+"RECO_ICVarPFPlus_LO";
// W+ data
TString pHist_data = dir+"RECO_ICVarPFPlus";

// W- templates
TString mHist1 = dir+"RECO_ICVarPFMinus_LH";
TString mHist2 = dir+"RECO_ICVarPFMinus_RH";
TString mHist3 = dir+"RECO_ICVarPFMinus_LO";
// W- data
TString mHist_data = dir+"RECO_ICVarPFMinus";


void ScaleErrors(TH1D* h, double scale){
  h->Sumw2();
  h->Scale(scale);//h->Sumw2();
}

class PDF{

public:
  RooAddPdf *sig, *model;
  RooDataHist *data1, *data2, *data3,*data4;
  RooDataHist *rtest1;
  RooDataSet *test1;
  RooRealVar* f3, *fs;
  RooHistPdf *h1, *h2, *h3, *bkg;

  Double_t stat;
  TH1D *mc1, *mc2, *mc3;

  PDF(TString chrg, double scale, bool addqcd, RooRealVar* x, RooRealVar* f1, RooRealVar *f2, bool redice){

    TFile *data = new TFile("eWPol_Signal_Wjets.root");
    TFile *fbkg= new TFile("eWPol_Signal_QCD.root");
    
    TH1D *hsig, *hbkg;
    if (chrg=="plus") {
      mc1 = (TH1D*)data->Get(pHist1); mc2 = (TH1D*)data->Get(pHist2); mc3 = (TH1D*)data->Get(pHist3);
      hsig = (TH1D*)data->Get(pHist_data); hsig->Rebin(rbin);
      hbkg = (TH1D*)fbkg->Get(pHist_data); hbkg->Rebin(rbin);
    } else {
      mc1 = (TH1D*)data->Get(mHist1); mc2 = (TH1D*)data->Get(mHist2); mc3 = (TH1D*)data->Get(mHist3);
      hsig = (TH1D*)data->Get(mHist_data); hsig->Rebin(rbin);
      hbkg = (TH1D*)fbkg->Get(mHist_data); hbkg->Rebin(rbin);
   }
    mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);

    TH1D *test = hsig->Clone();

    // QCD background
    Double_t nbkg=0;

    ScaleErrors(hbkg,scale);
    ScaleErrors(test,scale);
    ScaleErrors(hsig,scale);
    ScaleErrors(mc1,scale); ScaleErrors(mc2,scale); ScaleErrors(mc3,scale);

    if(addqcd){
      test->Add(hbkg); nbkg=hbkg->Integral();
    }

    stat=test->Integral();
    Double_t f_sig=(hsig->Integral())/stat;
    Double_t f_bkg=nbkg/stat;
 
  // Import binned Data
    data1 = new RooDataHist ("data1","dataset with ICvar",*x,mc1);
    data2  = new RooDataHist ("data2","dataset with ICvar",*x,mc2);
    data3  = new RooDataHist ("data3","dataset with ICvar",*x,mc3);

    // Background template
    data4 = new RooDataHist("data4","dataset with ICVar",*x,hbkg);
    bkg = new RooHistPdf("bkg","bkg",*x,*data4);

    // Helicity fractions
    //3 = new RooRealVar("f_{0}","f3 fraction",100.,0.,100000.) ;
    f3 = new RooRealVar("f_{0}","f3 fraction",0.3,0.,1.) ;

    fs = new RooRealVar("f_{s}","f4 fraction",f_sig);//,0.,1.) ;

    // Templates
    h1 = new RooHistPdf("h1","h1",*x,*data1);
    h2 = new RooHistPdf("h2","h2",*x,*data2);
    h3 = new RooHistPdf("h3","h3",*x,*data3);

    // Model which changes the interpretation of parameters    
    RooAddPdf *com = new RooAddPdf("cplus1","component 1",RooArgList(*h2,*h3),RooArgList(*f2)) ;
    sig = new RooAddPdf("sig","component 1",RooArgList(*h1,*com),RooArgList(*f1)) ;
    
    // Original Model (allows negative values of f0...)
    //sig =  new RooAddPdf("sig","component 1",RooArgList(*h1,*h2,*h3),RooArgList(*f1,*f2)) ;

  // composite PDF
    model = new RooAddPdf("model","model",RooArgList(*sig,*bkg),*fs);
 
    // if (redice) {
    test1=model->generate(*x,int(stat));
    //} else {
    rtest1 = new RooDataHist("data","dataset with LPvar",*x,test);
    //}
  }

};


void roo_fit(TString chrg="plus", bool redice=0){

  gSystem->Load("libRooFit"); using namespace RooFit;
  //  TCanvas* c=new TCanvas("test");
  TGraphErrors* efl1=new TGraphErrors(100);
  efl1->SetMarkerColor(kRed);efl1->SetLineColor(kRed);
  efl1->SetMarkerStyle(29); efl1->SetMarkerSize(2.);
  TGraphErrors* efl2=new TGraphErrors(100);
  efl2->SetMarkerStyle(29); efl2->SetMarkerSize(2.);
  TGraphErrors* efr1=new TGraphErrors(100);
  efr1->SetMarkerColor(kRed); efr1->SetLineColor(kRed);
  efr1->SetMarkerStyle(29); efr1->SetMarkerSize(2.);
  TGraphErrors* efr2=new TGraphErrors(100);
  efr2->SetMarkerStyle(29); efr2->SetMarkerSize(2.);

  TGraph* g1=new TGraph(100);
  g1->SetMarkerColor(kRed);
  g1->SetMarkerStyle(29); g1->SetMarkerSize(2.);
  TGraph* g2=new TGraph(100);
  g2->SetMarkerStyle(29); g2->SetMarkerSize(2.);
  TGraph* gp1=new TGraph(100);
  gp1->SetMarkerColor(kRed);
  gp1->SetMarkerStyle(29);gp1->SetMarkerSize(2.);
  TGraph* gp2=new TGraph(100);
  gp2->SetMarkerStyle(29);gp2->SetMarkerSize(2.);
  // global correlation info plots
  TGraph* cg1=new TGraph(100);
  cg1->SetMarkerColor(kRed);
  cg1->SetMarkerStyle(29); cg1->SetMarkerSize(2.);
  TGraph* cg2=new TGraph(100);
  cg2->SetMarkerStyle(29); cg2->SetMarkerSize(2.);
  TGraph* cgp1=new TGraph(100);
  cgp1->SetMarkerColor(kRed);
  cgp1->SetMarkerStyle(29);cgp1->SetMarkerSize(2.);
  TGraph* cgp2=new TGraph(100);
  cgp2->SetMarkerStyle(29);cgp2->SetMarkerSize(2.);

  
  TGraph* dg1=new TGraph(100);
  dg1->SetMarkerColor(kRed);
  dg1->SetMarkerStyle(29); dg1->SetMarkerSize(2.);
  TGraph* dg2=new TGraph(100);
  dg2->SetMarkerStyle(29); dg2->SetMarkerSize(2.);
  TGraph* sg1=new TGraph(100);
  sg1->SetMarkerColor(kRed);
  sg1->SetMarkerStyle(29); sg1->SetMarkerSize(2.);
  TGraph* sg2=new TGraph(100);
  sg2->SetMarkerStyle(29); sg2->SetMarkerSize(2.);

  TGraphErrors* edg1=new TGraphErrors(100);
  edg1->SetMarkerColor(kRed);edg1->SetLineColor(kRed);
  edg1->SetMarkerStyle(29); edg1->SetMarkerSize(2.);
  TGraphErrors* edg2=new TGraphErrors(100);
  edg2->SetMarkerStyle(29); edg2->SetMarkerSize(2.);
  TGraphErrors* esg1=new TGraphErrors(100);
  esg1->SetMarkerColor(kRed); esg1->SetLineColor(kRed);
  esg1->SetMarkerStyle(29); esg1->SetMarkerSize(2.);
  TGraphErrors* esg2=new TGraphErrors(100);
  esg2->SetMarkerStyle(29); esg2->SetMarkerSize(2.);

  int i=0;
  bool qcd=false;

  for(double sc = 1. ; sc <= 1. ; sc+=0.3,++i){
    cout << qcd << endl;
 
    fit_info* fsb, *fs;
    
    if (chrg=="plus") {
      fsb= do_oneflavor_fit(sc,"qcd","plus",0,redice);
      fs = do_oneflavor_fit(sc,"","plus",0,redice);
    } else {
      fsb= do_oneflavor_fit(sc,"qcd","minus",0,redice);
      fs = do_oneflavor_fit(sc,"","minus",0,redice);
    } 

    cout << "===================================================="<<endl;
    cout << "Val " << fsb->val1 << " Error: " <<  fsb->err1 << endl;
    cout << "Val " << fsb->val2 << " Error: " <<  fsb->err2 << endl;
    cout << " new error: " << endl;
    //  cout <<  scalef_1 << " " <<  scalef_2 << " " << scalef_3  << endl;
    cout <<  fsb->corr1  << " " <<  fsb->corr2 << " " << fsb->corr3  << endl;
    cout << "Val " << fsb->val1_corr << " Error: " << fsb->err1_corr << endl;
    cout << "Val " << fsb->val2_corr << " Error: " << fsb->err2_corr << endl;
    cout << "===================================================="<<endl;

    cout << "===================================================="<<endl;
    cout << "Val " << fs->val1 << " Error: " <<  fs->err1 << endl;
    cout << "Val " << fs->val2 << " Error: " <<  fs->err2 << endl;
    cout << " new error: " << endl;
    //  cout <<  scalef_1 << " " <<  scalef_2 << " " << scalef_3  << endl;
    cout <<  fs->corr1  << " " <<  fs->corr2 << " " << fs->corr3  << endl;
    cout << "Val " << fs->val1_corr << " Error: " << fs->err1_corr << endl;
    cout << "Val " << fs->val2_corr << " Error: " << fs->err2_corr << endl;
    cout << "===================================================="<<endl;

    return;
    // uncertainty on fL-fR

    // cout << "correlation = " << fs->gcor12 << endl;

    double comb_error_diff_bs = sqrt( (fsb->err1_corr*fsb->err1_corr) + (fsb->err2_corr*fsb->err2_corr) -
				      (2.*fsb->err1_corr*fsb->err2_corr*fsb->gcor12));
    double comb_error_diff_s = sqrt(fs->err1_corr*fs->err1_corr + fs->err2_corr*fs->err2_corr -
				    2.*fs->err1_corr*fs->err2_corr*fs->gcor12);

 
    double comb_error_sum_bs = sqrt(fsb->err1_corr*fsb->err1_corr + fsb->err2_corr*fsb->err2_corr +
				     2.*fsb->err1_corr*fsb->err2_corr*fsb->gcor12);
    double comb_error_sum_s = sqrt(fs->err1_corr*fs->err1_corr + fs->err2_corr*fs->err2_corr +
				     2.*fs->err1_corr*fs->err2_corr*fs->gcor12);

    //    cout << "diff error = " <<  comb_error_diff_bs <<endl;
    //    cout << "sum error = " <<  comb_error_sum_bs <<endl;
    //   return;
    // 
    efl1->SetPoint(i,sc*10, (fsb->val1_corr));efl2->SetPoint(i,sc*10, (fs->val1_corr));
    efl1->SetPointError(i,0, fsb->err1_corr);efl2->SetPointError(i,0, fs->err1_corr);

    efr1->SetPoint(i,sc*10, (fsb->val2_corr));efr2->SetPoint(i,sc*10, (fs->val2_corr));
    efr1->SetPointError(i,0, fsb->err2_corr);efr2->SetPointError(i,0, fs->err2_corr);



    dg1->SetPoint(i,sc*10, comb_error_diff_bs);dg2->SetPoint(i,sc*10, comb_error_diff_s);
    sg1->SetPoint(i,sc*10, comb_error_sum_bs);sg2->SetPoint(i,sc*10, comb_error_sum_s);
    
    edg1->SetPoint(i,sc*10, (fsb->val1_corr-fsb->val2_corr));edg2->SetPoint(i,sc*10, (fs->val1_corr-fs->val2_corr));
    edg1->SetPointError(i,0, comb_error_diff_bs);edg2->SetPointError(i,0, comb_error_diff_s);
    
    esg1->SetPoint(i,sc*10, (fsb->val1_corr+fsb->val2_corr));esg2->SetPoint(i,sc*10, (fs->val1_corr+fs->val2_corr));
    esg1->SetPointError(i,0, comb_error_sum_bs);esg2->SetPointError(i,0, comb_error_sum_s);

    // absolute combined errors
    g1->SetPoint(i,sc*10,fsb->err1_corr);g2->SetPoint(i,sc*10,fs->err1_corr);
    gp1->SetPoint(i,sc*10,fsb->err2_corr);gp2->SetPoint(i,sc*10,fs->err2_corr);

    // global correlation
    cg1->SetPoint(i,sc*10,fsb->gcor1);cg2->SetPoint(i,sc*10,fs->gcor1);
    cgp1->SetPoint(i,sc*10,fsb->gcor2);cgp2->SetPoint(i,sc*10,fs->gcor2);

    delete fsb;
    delete fs;
 
  } 

  setStyles();

  TCanvas* c=new TCanvas("test");
  c->Divide(2,1);

  c->cd(1);
 gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(efl2,"W only","P");
  leg->AddEntry(efl1,"W, QCD","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

 //  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
//   TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
//   efl1->Fit(fa1,"R+");//,"",4.,11.);
//   efl2->Fit(fa2,"R+");//,"",3.,11.);
  efl1->Draw("AP");
  efl1->GetYaxis()->SetRangeUser(0.,1.);
  efl1->SetTitle(";luminosity (pb^{-1});combined f_{L}");
  efl2->Draw("P");
  //  efl1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  c->cd(2);

  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(g2,"W only","P");
  leg->AddEntry(g1,"W, QCD","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
  TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
  g1->Fit(fa1,"R+");//,"",4.,11.);
  g2->Fit(fa2,"R+");//,"",3.,11.);
  g1->Draw("AP");
  g1->GetYaxis()->SetRangeUser(0.,1.);
  g1->SetTitle(";luminosity (pb^{-1});combined #delta f_{L}");
  g2->Draw("P");
  g1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  c->SaveAs("combined_fL_error.png");

  TCanvas *cp=new TCanvas("cp","");
  cp->Divide(2,1);

  cp->cd(1);
 gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(efr2,"W only","P");
  leg->AddEntry(efr1,"W, QCD","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

 //  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
//   TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
//   efr1->Fit(fa1,"R+");//,"",4.,11.);
//   efr2->Fit(fa2,"R+");//,"",3.,11.);
  efr1->Draw("AP");
  efr1->GetYaxis()->SetRangeUser(0.,1.);
  efr1->SetTitle(";luminosity (pb^{-1});combined f_{R}");
  efr2->Draw("P");
  //  efr1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  cp->cd(2);


  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(gp2,"W only","P");
  leg->AddEntry(gp1,"W, QCD","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  gp1->Fit(fa1,"R+");
  gp2->Fit(fa2,"R+");
  gp1->Draw("AP");
  gp1->GetYaxis()->SetRangeUser(0.,1.);
  gp1->SetTitle(";luminosity (pb^{-1});combined #delta f_{R}");
  gp2->Draw("P");
  gp1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  cp->SaveAs("combined_fR_error.png");
  // correlations
  TCanvas* c=new TCanvas("ctest");
  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(cg2,"W only","P");
  leg->AddEntry(cg1,"W, QCD","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

 //  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
//   TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
  // cg1->Fit(fa1,"R+","",4.,11.);
  //  cg2->Fit(fa2,"R+","",3.,11.);
  cg1->Draw("AP");
  cg1->GetYaxis()->SetRangeUser(0.,1.);
  cg1->SetTitle(";luminosity (pb^{-1});correlation #delta f_{L}");
  cg2->Draw("P");
  //  cg1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  TCanvas *cp=new TCanvas("ccp","");
  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(cgp2,"W only","P");
  leg->AddEntry(cgp1,"W + QCD + Z","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  //  cgp1->Fit(fa1,"R+");
  //  cgp2->Fit(fa2,"R+");
  cgp1->Draw("AP");
  cgp1->GetYaxis()->SetRangeUser(0.,1.);
  cgp1->SetTitle(";luminosity (pb^{-1});correlation #delta f_{R}");
  cgp2->Draw("P");
  //  cgp1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  TCanvas* ecc=new TCanvas("ectest");
  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(edg2,"W only","P");
  leg->AddEntry(edg1,"W + QCD + Z","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

 //  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
//   TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
//   edg1->Fit(fa1,"R+","",4.,11.);
//   edg2->Fit(fa2,"R+","",3.,11.);
  edg1->Draw("AP");
  edg1->GetYaxis()->SetRangeUser(0.,1.);
  edg1->SetTitle(";luminosity (pb^{-1});(f_{L}-f_{R})");
  edg2->Draw("P");
  //  edg1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  ecc->SaveAs("fL_fR_diff.png");

  TCanvas* eccc=new TCanvas("ecctest");
  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(esg2,"W only","P");
  leg->AddEntry(esg1,"W + QCD + Z","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  // TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
//   TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
//   esg1->Fit(fa1,"R+","",4.,11.);
//   esg2->Fit(fa2,"R+","",3.,11.);
  esg1->Draw("AP");
  // esg1->GetYaxis()->SetRangeUser(0.,1.);
  esg1->SetTitle(";luminosity (pb^{-1});(f_{L}+f_{R})");
  esg2->Draw("P");
  // esg1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  eccc->SaveAs("fL_fR_sum.png");

  TCanvas* cc=new TCanvas("ctest");
  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(dg2,"W only","P");
  leg->AddEntry(dg1,"W + QCD + Z","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
  TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
  dg1->Fit(fa1,"R+");//,"",4.,11.);
  dg2->Fit(fa2,"R+");//,"",3.,11.);
  dg1->Draw("AP");
  dg1->GetYaxis()->SetRangeUser(0.,0.7);
  dg1->SetTitle(";luminosity (pb^{-1});#delta (f_{L}-f_{R})");
  dg2->Draw("P");
  dg1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

  TCanvas* ccc=new TCanvas("cctest");
  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(sg2,"W only","P");
  leg->AddEntry(sg1,"W + QCD + Z","P");
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  TF1 *fa1 = new TF1("fa1","[0]/sqrt(x)",0.3,11);
  TF1 *fa2 = new TF1("fa2","[0]/sqrt(x)",0.3,11);
  sg1->Fit(fa1,"R+");//,"",4.,11.);
  sg2->Fit(fa2,"R+");//,"",3.,11.);
  sg1->Draw("AP");
  sg1->GetYaxis()->SetRangeUser(0.,1.);
  sg1->SetTitle(";luminosity (pb^{-1});#delta (f_{L}+f_{R})");
  sg2->Draw("P");
  sg1->GetFunction("fa1")->SetLineColor(2);

  leg->Draw("SAME");

}

void setStyles() {

  gROOT->SetStyle("Plain");
  gStyle->SetCanvasDefW(600);
  gStyle->SetCanvasDefH(500);
}

fit_info* do_oneflavor_fit(double scale, TString bg, TString chrg, bool temp, bool redice) {

  RooRealVar *x = new RooRealVar("x","LP variable",-0.4,1.6) ;

  /* RooRealVar *f1 = new RooRealVar("f_{L}","f_{L}",500.,0.,10000.) ; */
  /* RooRealVar *f2 = new RooRealVar("f_{R}","f_{R}",100.,0.,10000.) ; */

  RooRealVar *f1 = new RooRealVar("f_{L}","f_{L}",0.51,0.,1.) ;
  RooRealVar *f2 = new RooRealVar("f_{R}","f_{R}",0.29,0.,1.) ;
  //  RooRealVar *f3 = new RooRealVAr("f_{0}","f_{0}",(1-0.51-0.29),0.,1.);

  bool addqcd=false;
  if(bg.Contains("qcd")) addqcd=true;

  PDF ePDF = PDF(chrg, scale,addqcd,x,f1,f2,redice);

  // Toy MC Study
  TString canvasName_2="pulls";
  canvasName_2+=scale;
  
  if (addqcd) canvasName_2+="_qcd";
  else canvasName_2+="_Wonly";

   TCanvas *cp0 = new TCanvas(canvasName_2,"");

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);


  // Correction factors
  TH1D *temp1=ePDF.mc1->Clone(); TH1D *temp2=ePDF.mc2->Clone(); TH1D *temp3=ePDF.mc3->Clone();
 
  float allmc = temp1->Integral()+temp2->Integral()+temp3->Integral();
  float scalef_1 = allmc/temp1->Integral();
  float scalef_2 = allmc/temp2->Integral();
  float scalef_3 = allmc/temp3->Integral();
  /*
  RooCategory tagCat("tagCat","tagging Category");
  tagCat.defineType("eplus");  tagCat.defineType("eminus");

  // Construct combined dataset in (x,tagCat)
  if (redice) {
    RooDataSet combData("ecombData","combined data",*x,Index(tagCat),Import("eplus",*(ePDF.test1_plus)),
		       Import("eminus",*(ePDF.test1_minus)) );
  } else {
    RooDataHist combData("ecombData","combined data",*x,Index(tagCat),Import("eplus",*(ePDF.rtest1_plus)),
		       Import("eminus",*(ePDF.rtest1_minus)) );
  }
  */

  //  (*ePDF.model).fitTo(*ePDF.rtest1,Minos(kTRUE));

  RooNLLVar nll("nll","nll",*ePDF.model,*ePDF.rtest1);
  
  RooMinuit m(nll);

  // Activate constant-term optimization (always recommended)
  m.optimizeConst(kTRUE) ;

  // Activate profile timing
  m.setProfile(kTRUE) ;

  // Activate verbose logging
  m.setVerbose(kTRUE) ;

  // Run HESSE (mx,my,sx,sy free)
  m.hesse() ;

  // Deactivate verbose logging
  m.setVerbose(kFALSE) ;

// Run MIGRAD (mx,my free)
  m.migrad() ;
   // Run MINOS (mx,my,sx free)
  m.minos() ;

  RooFitResult *fitr=m.save();
  fitr->Print();
  //  return;
 //  if (redice) {
//     RooDataSet mdata("d","d",ePDF.test1,*x);
//   } else {
//     RooDataHist mdata("d","d",*x,*ePDF.rtest1);
//   }

  // RooFormulaVar con("constrain","(1-f_{L}-f_{R})<0.",RooArgList(*f1,*f2));
  
  //  RooFitResult *fitr = (*ePDF.model).fitTo(*ePDF.rtest1,Minos(kTRUE),Save(kTRUE));

  fit_info* fit=new fit_info();
 
  /*
  fit->val1 = f1->getVal();
  fit->val2 = f2->getVal();
  fit->err1 =  f1->getError();
  fit->err2  =  f2->getError();
  */
  // Change interpretation of parameters
  fit->val1 = f1->getVal();
  fit->val2 = (1-fit->val1)*f2->getVal();
  fit->err1 =  f1->getError();

  double alpha=(1-fit->val1); double beta=fit->val2;
  double dalpha=-fit->err1; double dbeta=f2->getError();


  fit->err2 = sqrt( beta*beta*dalpha*dalpha + alpha*alpha*dbeta*dbeta +
		    2.*alpha*beta*dalpha*dbeta*fitr->correlation(*f1,*f2) );
		    
  //  fit->err2 = sqrt( (dalpha/alpha)*(dalpha/alpha) +  (dbeta/beta)*(dbeta/beta) +
  //		       2. *((dalpha*dbeta)/(alpha*beta))*fitr->correlation(*f1,*f2)  );

  fit->corr1 = 3*scalef_1/(scalef_1+scalef_2+scalef_3);
  fit->corr2 = 3*scalef_2/(scalef_1+scalef_2+scalef_3);
  fit->corr3 =  3*scalef_3/(scalef_1+scalef_2+scalef_3);
  fit->val1_corr = fit->val1 * fit->corr1;
  fit->val2_corr = fit->val2 * fit->corr2;
  fit->err1_corr = fit->err1 * fit->corr1;
  fit->err2_corr = fit->err2 * fit->corr2;
  fit->gcor1 = fitr->globalCorr(*f1);
  fit->gcor2 = fitr->globalCorr(*f2);
  fit->gcor12 = fitr->correlation(*f1,*f2);

  TString ecanvasName="e";
  TString canvasName="c";
  canvasName+=scale;
  ecanvasName+=scale;
  //  if( plus) canvasName+="plus";
  // else canvasName+="Minus";
  if (addqcd) {
    canvasName+="_qcd";
  }
  else canvasName+="_Wonly";
  ecanvasName+=canvasName;

  setStyles();


  TCanvas *ce = new TCanvas(ecanvasName,"");
 
  RooPlot * xframe = x->frame();
 
  (*ePDF.rtest1).plotOn(xframe,Binning(20));
  (*ePDF.model).plotOn(xframe); (*ePDF.model).paramOn(xframe);
  
  (*ePDF.model).plotOn(xframe,Components(*ePDF.h1),LineColor(kRed),LineStyle(kDashed));
  (*ePDF.model).plotOn(xframe,Components(*ePDF.h2),LineColor(kGreen),LineStyle(kDashed));
  (*ePDF.model).plotOn(xframe,Components(*ePDF.h3),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    (*ePDF.model).plotOn(xframe,Components(*ePDF.bkg),LineColor(kBlack),LineStyle(kDashed));
  } 
  
  xframe->Draw();

  ce->Update();

  //  return;

   // Likelihood contours in two-dimensions

  TString canvasName_1="nll";
  canvasName_1+=scale;
  //  if( plus) canvasName+="plus";
  // else canvasName+="Minus";
  if (addqcd) canvasName_1+="_qcd";
  else canvasName_1+="_Wonly";

  TString canvasName_2="pulls_";
  canvasName_2+=canvasName_1;

  TCanvas *c0 = new TCanvas(canvasName_1,"");

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  double lumi=(10.*scale);
  
  TString head="L ="; head+=lumi; head+=" pb-1";
  if (addqcd) head+=" (W+QCD)";
  leg->SetHeader(head);

  c0->Divide(2,1);
  c0->cd(1);
  RooPlot *contour = m.contour(*f1,*f2); 
  contour->Draw();

  // m.contour(*f1,*f2)->Draw();
  contour->SetTitle(";f_{1};f_{2}");

  leg->Draw("SAME");

  c0->cd(2);

  RooPlot *ncontour = transform(contour,1.,1.,0);
  //  RooPlot *ncontour = transform(contour,fit->corr1,fit->corr2,0);
  ncontour->Draw();
  //  ncontour->SetTitle(";f_{L};f_{R}");
  //  if (addqcd) 
    return fit;

  // MC STudies
  Int_t nevt=(int)ePDF.stat;

  RooMCStudy mgr(*ePDF.model,*ePDF.model,*x,"","mhv");
  mgr.generateAndFit(500,nevt,kTRUE);

  TCanvas *cp0 = new TCanvas(canvasName_2,"");

  RooPlot* m1pframe = mgr.plotPull(*f1,-4,4,40,kTRUE);
  m1pframe->Draw();

  canvasName_2+="_fr";
  TCanvas *cp02 = new TCanvas(canvasName_2,"");

  RooPlot* m2pframe = mgr.plotPull(*f2,-4,4,40,kTRUE);
  m2pframe->Draw();
  
  canvasName_2+="_f0";
  TCanvas *cp03 = new TCanvas(canvasName_2,"");

  RooPlot* m3pframe = mgr.plotPull(*ePDF.f3,-4,4,40,kTRUE);
  m3pframe->Draw();

  return fit;
}

RooPlot *transform(RooPlot *contour, double corx, double cory, bool mode) {

  RooPlot *h;

  if (mode) {
    h = new RooPlot(0.,1.,0.,1.);//contour->Clone(); h->Reset();
  } else {
    h = new RooPlot(0.,1.,0.,1.2);
  }

  contour->Print();
  TGraph *g1 = (TGraph*)contour->findObject("contour_nll_n1.000000");
  TGraph *g2 = (TGraph*)contour->findObject("contour_nll_n2.000000");
  TMarker *point= (TMarker*)contour->findObject("TMarker");

  Double_t ix1[50], ix2[50];
  Double_t iy1prime[50], iy2prime[50];

  Double_t idiff1[50], isum1[50];
  Double_t idiff2[50], isum2[50];

  for (int i=0; i<50; i++) {
     

    ix1[i]=corx*g1->GetX()[i];
    ix2[i]=corx*g2->GetX()[i];

    iy1prime[i]=cory*(1.-(g1->GetX()[i]))*(g1->GetY()[i]);
    iy2prime[i]=cory*(1.-(g2->GetX()[i]))*(g2->GetY()[i]);

    idiff1[i]=ix1[i]-iy1prime[i];
    isum1[i]=ix1[i]+iy1prime[i];

    idiff2[i]=ix2[i]-iy2prime[i];
    isum2[i]=ix2[i]+iy2prime[i];

  }

  Double_t mx=corx*point->GetX();
  Double_t my=cory*(1-point->GetX())*point->GetY();
  TMarker *dpoint; //= new TMarker(mx, my, 8);

  TGraph *c1, *c2;
  if (mode) {
    c1 = new TGraph(50,ix1,iy1prime);
    c2 = new TGraph(50,ix2,iy2prime);
    dpoint=new TMarker(mx,my,8);
    h->SetTitle(";f_{L};f_{R}");
  } else {
    c1 = new TGraph(50,idiff1,isum1);
    c2 = new TGraph(50,idiff2,isum2);
    dpoint=new TMarker((mx-my),(mx+my),8);
    h->SetTitle(";f_{L}-f_{R};f_{L}+f_{R}");
  }
    	c1->SetLineStyle(1) ;
	c1->SetLineWidth(2) ;
	c1->SetLineColor(kBlue) ;

	c2->SetLineStyle(2) ;
	c2->SetLineWidth(2) ;
	c2->SetLineColor(kBlue) ;

  //  c1->Draw("A");
	h->addObject(dpoint);
  h->addObject(c1,"L");
  h->addObject(c2,"L");
  
 /*
  for (int ix=0; ix<=contour->GetNbinsX(); ix++) {
    for (int iy=0; iy<=contour->GetNbinsY(); iy++) {

      double content=contour->GetBinContent(ix,iy);
      
      double y1=contour->GetXaxis()->GetBinCenter(ix);
      double y2=contour->GetYaxis()->GetBinCenter(iy);

      double yprime=(1-y1)*y2;
      int iyprime=contour->GetYaxis()->FindBin(yprime);

      h->SetBinContent(ix,iyprime);
   
    }
  }
 */
  //  h->Draw();
  return h;

}

RooPlot* mycontour(RooRealVar& var1, RooRealVar& var2, Double_t n1, Double_t n2, Double_t n3, Double_t n4, Double_t n5, Double_t n6) 
{
  // Create and draw a TH2 with the error contours in parameters var1 and v2 at up to 6 'sigma' settings
  // where 'sigma' is calculated as n*n*errorLevel
  
  _theFitter->SetObjectFit(this) ;

  // Verify that both variables are floating parameters of PDF
  Int_t index1= _floatParamList->index(&var1);
  if(index1 < 0) {
    coutE(Minimization) << "RooMinuit::contour(" << GetName() 
			<< ") ERROR: " << var1.GetName() << " is not a floating parameter of " << _func->GetName() << endl ;
    return 0;
  }

  Int_t index2= _floatParamList->index(&var2);
  if(index2 < 0) {
    coutE(Minimization) << "RooMinuit::contour(" << GetName() 
			<< ") ERROR: " << var2.GetName() << " is not a floating parameter of PDF " << _func->GetName() << endl ;
    return 0;
  }
  
  // create and draw a frame
  RooPlot* frame = new RooPlot(var1,var2) ;

  // draw a point at the current parameter values
  double val2=(1-var1.getVal())*var2.getVal();
  TMarker *point= new TMarker(var1.getVal(), val2 , 8);
  frame->addObject(point) ;

  // remember our original value of ERRDEF
  Double_t errdef= gMinuit->fUp;

  Double_t n[6] ;
  n[0] = n1 ; n[1] = n2 ; n[2] = n3 ; n[3] = n4 ; n[4] = n5 ; n[5] = n6 ;
  

  for (Int_t ic = 0 ; ic<6 ; ic++) {
    if(n[ic] > 0) {
      // set the value corresponding to an n1-sigma contour
      gMinuit->SetErrorDef(n[ic]*n[ic]*errdef);
      // calculate and draw the contour
      TGraph* graph= (TGraph*)gMinuit->Contour(50, index1, index2);
      if (!graph) {
	coutE(Minimization) << "RooMinuit::contour(" << GetName() << ") ERROR: MINUIT did not return a contour graph for n=" << n[ic] << endl ;
      } else {
	graph->SetName(Form("contour_%s_n%f",_func->GetName(),n[ic])) ;
	graph->SetLineStyle(ic+1) ;
	graph->SetLineWidth(2) ;
	graph->SetLineColor(kBlue) ;
	frame->addObject(graph,"L") ;
      }
    }
  }

  // restore the original ERRDEF
  gMinuit->SetErrorDef(errdef);
  
  return frame ;
}

