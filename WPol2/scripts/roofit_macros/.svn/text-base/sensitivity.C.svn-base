#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
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

void ScaleErrors(TH1D* h, double scale){
  h->Scale(scale);// h->Sumw2();
}


class PDF{
public:
  RooAddPdf *sig_plus, *sig_minus, *model_plus, *model_minus;
  RooDataHist *data1_plus, *data2_plus, *data3_plus, *data1_minus, *data2_minus, *data3_minus, *data4;
  RooDataHist *rtest1_plus, *rtest1_minus;
  RooDataSet *test1_plus, *test1_minus;
  RooRealVar* f3, *fsm, *fsp;
  RooHistPdf *h1_plus, *h2_plus, *h3_plus, *h1_minus, *h2_minus, *h3_minus, *bkg;

  Double_t stat_plus, stat_minus;
  TH1D *mc1_plus, *mc1_minus, *mc2_plus, *mc2_minus, *mc3_plus, *mc3_minus;

  PDF(int flavour, double scale, bool addqcd, RooRealVar* x, RooRealVar* f1, RooRealVar *f2, bool redice){
    if(flavour == 0) //muons
      {
	TString dir ="RECO_PolPlots_50toinf/";
	TFile *data = new TFile("RecoW_WJets-lite_madgraph_50_70_90_inf_1pb-1_mu20_21.root");
	TFile *fbkg= new TFile("RecoW_QCDMu-lite_Pythia30to120_50_70_90_inf_1pb-1_mu20_21_WSelection.root");
	//TFile *fbkg= new TFile("RecoW_Bkg.root");
      }
    else{ // electrons
      TString dir ="RECO_ElPolPlots_PostMHT50MET20/";
      TFile *data = new TFile("eWPol_Signal_Wjets.root");
      TFile *fbkg= new TFile("eWPol_Signal_QCD_enriched.root");
    }
 
    Int_t rbin=2;

    TString pHist1 = dir+"RECO_ICVarPFPlus_LH";
    TString pHist2 = dir+"RECO_ICVarPFPlus_RH";
    TString pHist3 = dir+"RECO_ICVarPFPlus_LO";
    TString pHist_data = dir+"RECO_ICVarPFPlus";

    TString mHist1 = dir+"RECO_ICVarPFMinus_LH";
    TString mHist2 = dir+"RECO_ICVarPFMinus_RH";
    TString mHist3 = dir+"RECO_ICVarPFMinus_LO";
    TString mHist_data = dir+"RECO_ICVarPFMinus";
    
    mc1_plus = (TH1D*)data->Get(pHist1); mc2_plus = (TH1D*)data->Get(pHist2); mc3_plus = (TH1D*)data->Get(pHist3);
    mc1_plus->Rebin(rbin); mc2_plus->Rebin(rbin); mc3_plus->Rebin(rbin);

    mc1_minus = (TH1D*)data->Get(mHist1); mc2_minus = (TH1D*)data->Get(mHist2); mc3_minus = (TH1D*)data->Get(mHist3);
    mc1_minus->Rebin(rbin); mc2_minus->Rebin(rbin); mc3_minus->Rebin(rbin);

    TH1D *hsig_plus = (TH1D*)data->Get(pHist_data); hsig_plus->Rebin(rbin);
    TH1D *test_plus = hsig_plus->Clone();

  // QCD background
  TH1D *hbkg_plus = (TH1D*)fbkg->Get(pHist_data); hbkg_plus->Rebin(rbin);
  Double_t nbkg_plus=0;

  ScaleErrors(hbkg_plus,scale);
  ScaleErrors(test_plus,scale);
  ScaleErrors(hsig_plus,scale);
  ScaleErrors(mc1_plus,scale); ScaleErrors(mc2_plus,scale); ScaleErrors(mc3_plus,scale);


  if(addqcd){
    test_plus->Add(hbkg_plus);
    nbkg_plus=hbkg_plus->Integral();
  }


  Double_t stat_plus=test_plus->Integral();
  Double_t f_sig_plus=(hsig_plus->Integral())/stat_plus;
  Double_t f_bkg_plus=nbkg_plus/stat_plus;

  // minus charge
  TH1D *hsig_minus = (TH1D*)data->Get(mHist_data); hsig_minus->Rebin(rbin);
  TH1D *test_minus = hsig_minus->Clone();

  // QCD background
  TH1D *hbkg_minus = (TH1D*)fbkg->Get(mHist_data); hbkg_minus->Rebin(rbin);
  Double_t nbkg_minus=0;

  ScaleErrors(hbkg_minus,scale);
  ScaleErrors(test_minus,scale);
  ScaleErrors(hsig_minus,scale);
  ScaleErrors(mc1_minus,scale); ScaleErrors(mc2_minus,scale); ScaleErrors(mc3_minus,scale);

  if(addqcd){
    test_minus->Add(hbkg_minus);
    nbkg_minus=hbkg_minus->Integral();
  }

  Double_t stat_minus=test_minus->Integral();
  Double_t f_sig_minus=(hsig_minus->Integral())/stat_minus;
  Double_t f_bkg_minus=nbkg_minus/stat_minus;


  Double_t f_sig=(hsig_plus->Integral()+hsig_minus->Integral())/
    ( (hsig_plus->Integral()+hsig_minus->Integral()) + (nbkg_plus+nbkg_minus)/2.);
  cout << "f_sig (plus) = " << f_sig_plus << endl;
  cout << "f_sig (minus) = " << f_sig_minus << endl;
  
  // RooFit session    
  //  RooRealVar x("x","ICvar",-0.2,0.6);
 
  // Import binned Data
  data1_plus = new RooDataHist ("data1_plus","dataset with ICvar",*x,mc1_plus);
  data2_plus  = new RooDataHist ("data2_plus","dataset with ICvar",*x,mc2_plus);
  data3_plus  = new RooDataHist ("data3_plus","dataset with ICvar",*x,mc3_plus);

  data1_minus  = new RooDataHist ("data1_minus","dataset with ICvar",*x,mc1_minus);
  data2_minus = new RooDataHist  ("data2_minus","dataset with ICvar",*x,mc2_minus);
  data3_minus = new RooDataHist("data3_minus","dataset with ICvar",*x,mc3_minus);

  // Background template

  hbkg_plus->Add(hbkg_minus); hbkg_plus->Scale(0.5);
  data4 = new RooDataHist("data4","dataset with ICVar",*x,hbkg_plus);
  //data4_minus = new RooDataHist("data4m","dataset with ICVar",*x,hbkg_minus);
  bkg = new RooHistPdf("bkg","bkg",*x,*data4);
  //bkg_minus = new RooHistPdf("bkgm","bkg minus",*x,*data4_minus);

  //  rtest1_plus = new RooDataHist("data_plus","dataset with LPvar",*x,test_plus);
  //  rtest1_minus = new RooDataHist("data_minus","dataset with LPvar",*x,test_minus);
  // redice data

 // Helicity fractions
  f3 = new RooRealVar("f_0","f3 fraction",0.3,0.,1.) ;

  fsp = new RooRealVar("f_splus","f4 fraction",f_sig_plus);//,0.,1.) ;
  fsm = new RooRealVar("f_sminus","f5 fraction",f_sig_minus);//,0.,1.) ;
  // Templates
  h1_plus = new RooHistPdf("h1_plus","h1",*x,*data1_plus);
  h2_plus = new RooHistPdf("h2_plus","h2",*x,*data2_plus);
  h3_plus = new RooHistPdf("h3_plus","h3",*x,*data3_plus);
  
  h1_minus = new RooHistPdf("h1_minus","h1",*x,*data1_minus);
  h2_minus = new RooHistPdf("h2_minus","h2",*x,*data2_minus);
  h3_minus = new RooHistPdf("h3_minus","h3",*x,*data3_minus);

  RooAddPdf *com_plus = new RooAddPdf("cplus1","component 1",RooArgList(*h2_plus,*h3_plus),RooArgList(*f2)) ;
  sig_plus = new RooAddPdf("sig_plus","component 1",RooArgList(*h1_plus,*com_plus),RooArgList(*f1)) ;

  RooAddPdf *com_minus = new RooAddPdf("cminus1","component 1",RooArgList(*h2_minus,*h3_minus),RooArgList(*f2)) ;
  sig_minus = new RooAddPdf("sig_minus","component 1",RooArgList(*h1_minus,*com_minus),RooArgList(*f1)) ;


  // composite PDF
//   sig_plus = new RooAddPdf("sig_plus","sig",RooArgList(*h1_plus,*h2_plus,*h3_plus),RooArgList(*f1,*f2)) ;
//   sig_minus = new RooAddPdf("sig_minus","sig",RooArgList(*h1_minus,*h2_minus,*h3_minus),RooArgList(*f1,*f2)) ;
  // composite PDF with bkg component
  model_plus = new RooAddPdf("model_plus","model",RooArgList(*sig_plus,*bkg),*fsp);
  model_minus = new RooAddPdf("model_minus","model",RooArgList(*sig_minus,*bkg),*fsm);  

  if (redice) {
    test1_plus=model_plus->generate(*x,int(stat_plus));
    test1_minus=model_minus->generate(*x,int(stat_minus));
  } else {
    rtest1_plus = new RooDataHist("data_plus","dataset with LPvar",*x,test_plus);
    rtest1_minus = new RooDataHist("data_minus","dataset with LPvar",*x,test_minus);
  }
}

};


fit_info* do_fit(double scale, TString bg, bool temp, bool redice) {

  //  gSystem->Load("libRooFit"); using namespace RooFit;

  RooRealVar *x = new RooRealVar("x","LP variable",-0.4,1.6) ;

  RooRealVar *f1 = new RooRealVar("f_L","f1 fraction",0.51,0.,1.) ;
  RooRealVar *f2 = new RooRealVar("f_R","f2 fraction",0.29,0.,1.) ;

  bool addqcd=false;
  if(bg.Contains("qcd")) addqcd=true;

  PDF ePDF = PDF(1, scale,addqcd,x,f1,f2,redice);
  PDF muPDF = PDF(0, scale*10, addqcd,x,f1,f2,redice);

  // Correction factors
  TH1D *temp1=ePDF.mc1_plus->Clone(); TH1D *temp2=ePDF.mc2_plus->Clone(); TH1D *temp3=ePDF.mc3_plus->Clone();
  temp1->Add(ePDF.mc1_minus);temp2->Add(ePDF.mc2_minus);temp3->Add(ePDF.mc3_minus);
  temp1->Add(muPDF.mc1_plus);temp2->Add(muPDF.mc2_plus);temp3->Add(muPDF.mc3_plus);
  temp1->Add(muPDF.mc1_minus);temp2->Add(muPDF.mc2_minus);temp3->Add(muPDF.mc3_minus);

  float allmc = temp1->Integral()+temp2->Integral()+temp3->Integral();
  float scalef_1 =   allmc/temp1->Integral();
  float scalef_2 =    allmc/temp2->Integral();
  float scalef_3 =    allmc/temp3->Integral();
  
  RooCategory tagCat("tagCat","tagging Category");
  tagCat.defineType("eplus");  tagCat.defineType("eminus");
  tagCat.defineType("muplus");  tagCat.defineType("muminus");

  // Construct combined dataset in (x,tagCat)
  if (redice) {
    RooDataSet combData("ecombData","combined data",*x,Index(tagCat),Import("eplus",*(ePDF.test1_plus)),
		       Import("eminus",*(ePDF.test1_minus)),Import("muplus", *(muPDF.test1_plus)),
		       Import("muminus",*(muPDF.test1_minus)) );
  } else {
    RooDataHist combData("ecombData","combined data",*x,Index(tagCat),Import("eplus",*(ePDF.rtest1_plus)),
		       Import("eminus",*(ePDF.rtest1_minus)),Import("muplus", *(muPDF.rtest1_plus)),
		       Import("muminus",*(muPDF.rtest1_minus)) );
  }
  // Simultaneous PDF
  RooSimultaneous simPdf("simPdf","sim pdf",tagCat);

  if(addqcd){
    simPdf.addPdf(*ePDF.model_plus,"eplus");
    simPdf.addPdf(*ePDF.model_minus,"eminus");
    simPdf.addPdf(*muPDF.model_plus,"muplus");
    simPdf.addPdf(*muPDF.model_minus,"muminus");
  }
  else{
    simPdf.addPdf(*ePDF.sig_plus,"eplus");
    simPdf.addPdf(*ePDF.sig_minus,"eminus");
    simPdf.addPdf(*muPDF.sig_plus,"muplus");
    simPdf.addPdf(*muPDF.sig_minus,"muminus");   
  }

  RooFitResult *fitr=0;
  fitr = simPdf.fitTo(combData,Minos(kTRUE),Save(kTRUE));

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

  TCanvas *c = new TCanvas(canvasName,"");
  c->Divide(2,1);

  c->cd(1);
  RooPlot * xframe = x->frame();
  
  //(*muPDF.rtest1_plus).plotOn(xframe,Binning(20));
  combData.plotOn(xframe,Binning(20),Cut("tagCat==tagCat::muplus"));
  tagCat="muplus";
  simPdf.plotOn(xframe,Slice(tagCat),ProjWData(tagCat,combData)); simPdf.paramOn(xframe,Label("muons"));
  
  simPdf.plotOn(xframe,Slice(tagCat),Components(*muPDF.h1_plus),ProjWData(tagCat,combData),LineColor(kRed),LineStyle(kDashed));
  simPdf.plotOn(xframe,Slice(tagCat),Components(*muPDF.h2_plus),ProjWData(tagCat,combData),LineColor(kGreen),LineStyle(kDashed));
  simPdf.plotOn(xframe,Slice(tagCat),Components(*muPDF.h3_plus),ProjWData(tagCat,combData),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    simPdf.plotOn(xframe,Slice(tagCat),Components(*muPDF.bkg),ProjWData(tagCat,combData),LineColor(kBlack),LineStyle(kDashed));
  } 
  
  xframe->Draw();

  c->cd(2);
  RooPlot * xframe2 = x->frame();
  
  //(*muPDF.rtest1_minus).plotOn(xframe2,Binning(20));
  combData.plotOn(xframe2,Binning(20),Cut("tagCat==tagCat::muminus"));
  tagCat="muminus";
  simPdf.plotOn(xframe2,Slice(tagCat),ProjWData(tagCat,combData));simPdf.paramOn(xframe2,Label("muons"));
  
  simPdf.plotOn(xframe2,Slice(tagCat),Components(*muPDF.h1_minus),ProjWData(tagCat,combData),LineColor(kRed),LineStyle(kDashed));
  simPdf.plotOn(xframe2,Slice(tagCat),Components(*muPDF.h2_minus),ProjWData(tagCat,combData),LineColor(kGreen),LineStyle(kDashed));
  simPdf.plotOn(xframe2,Slice(tagCat),Components(*muPDF.h3_minus),ProjWData(tagCat,combData),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    simPdf.plotOn(xframe2,Slice(tagCat),Components(*muPDF.bkg),ProjWData(tagCat,combData),LineColor(kBlack),LineStyle(kDashed));
  } 
  xframe2->Draw();

  c->Update();


  TCanvas *ce = new TCanvas(ecanvasName,"");
  ce->Divide(2,1);

  ce->cd(1);
  RooPlot * xframe3 = x->frame();
  
  //(*muPDF.rtest1_plus).plotOn(xframe,Binning(20));
  combData.plotOn(xframe3,Binning(20),Cut("tagCat==tagCat::eplus"));
  tagCat="eplus";
  simPdf.plotOn(xframe3,Slice(tagCat),ProjWData(tagCat,combData)); simPdf.paramOn(xframe3,Label("electrons"));
  
  simPdf.plotOn(xframe3,Slice(tagCat),Components(*ePDF.h1_plus),ProjWData(tagCat,combData),LineColor(kRed),LineStyle(kDashed));
  simPdf.plotOn(xframe3,Slice(tagCat),Components(*ePDF.h2_plus),ProjWData(tagCat,combData),LineColor(kGreen),LineStyle(kDashed));
  simPdf.plotOn(xframe3,Slice(tagCat),Components(*ePDF.h3_plus),ProjWData(tagCat,combData),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    simPdf.plotOn(xframe3,Slice(tagCat),Components(*ePDF.bkg),ProjWData(tagCat,combData),LineColor(kBlack),LineStyle(kDashed));
  } 
  
  xframe3->Draw();

  ce->cd(2);
  RooPlot * xframe4 = x->frame();
  
  //(*muPDF.rtest1_minus).plotOn(xframe2,Binning(20));
  combData.plotOn(xframe4,Binning(20),Cut("tagCat==tagCat::eminus"));
  tagCat="eminus";
  simPdf.plotOn(xframe4,Slice(tagCat),ProjWData(tagCat,combData));simPdf.paramOn(xframe4,Label("electrons"));
  
  simPdf.plotOn(xframe4,Slice(tagCat),Components(*ePDF.h1_minus),ProjWData(tagCat,combData),LineColor(kRed),LineStyle(kDashed));
  simPdf.plotOn(xframe4,Slice(tagCat),Components(*ePDF.h2_minus),ProjWData(tagCat,combData),LineColor(kGreen),LineStyle(kDashed));
  simPdf.plotOn(xframe4,Slice(tagCat),Components(*ePDF.h3_minus),ProjWData(tagCat,combData),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    simPdf.plotOn(xframe4,Slice(tagCat),Components(*ePDF.bkg),ProjWData(tagCat,combData),LineColor(kBlack),LineStyle(kDashed));
  } 
  xframe4->Draw();

  ce->Update();



   // Likelihood contours in two-dimensions

  TString canvasName_1="nll";
  canvasName_1+=scale;
  //  if( plus) canvasName+="plus";
  // else canvasName+="Minus";
  if (addqcd) canvasName_1+="_qcd";
  else canvasName_1+="_Wonly";

  TCanvas *c0 = new TCanvas(canvasName_1,"");

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  double lumi=(10.*scale);
  
  TString head="L ="; head+=lumi; head+=" pb-1";
  if (addqcd) head+=" (W+QCD)";
  leg->SetHeader(head);

  RooPlot *frame = new RooPlot(0,1,0,1); //f1.frame(0.,1.,20);
  fitr->plotOn(frame,*f1,*f2,"ME12VHB");
  frame->Draw();
  frame->SetTitle(";f_1;f_2");

  leg->Draw("SAME");

  //  TString pngName = canvasName_1+".png";

  return fit;
}


void sensitivity(TString flavor="doall", bool redice=0){

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

  for(double sc = 0.1 ; sc < 1.1 ; sc+=0.3,++i){
    cout << qcd << endl;
 
    fit_info* fsb, *fs;
    
    if (flavor=="ele") {
      fsb= do_oneflavor_fit(sc,"qcd",0,1,redice);
      fs = do_oneflavor_fit(sc,"",0,1,redice);
    } else if (flavor=="mu") {
      fsb= do_oneflavor_fit(sc,"qcd",0,0,redice);
      fs = do_oneflavor_fit(sc,"",0,0,redice);
    } else {
      fsb= do_fit(sc,"qcd",0,redice);
      fs = do_fit(sc,"",0,redice);
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
  dg1->GetYaxis()->SetRangeUser(0.,1.);
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

fit_info* do_oneflavor_fit(double scale, TString bg, bool temp, bool flavor, bool redice) {


  RooRealVar *x = new RooRealVar("x","LP variable",-0.4,1.6) ;

  RooRealVar *f1 = new RooRealVar("f_L","f1 fraction",0.51,0.,1.) ;
  RooRealVar *f2 = new RooRealVar("f_R","f2 fraction",0.29,0.,1.) ;

  bool addqcd=false;
  if(bg.Contains("qcd")) addqcd=true;


  if (flavor==1) {
    PDF ePDF = PDF(flavor, scale,addqcd,x,f1,f2,redice);
  } else {
    PDF ePDF = PDF(0, scale*10, addqcd,x,f1,f2,redice);
  }
  // Correction factors
  TH1D *temp1=ePDF.mc1_plus->Clone(); TH1D *temp2=ePDF.mc2_plus->Clone(); TH1D *temp3=ePDF.mc3_plus->Clone();
  temp1->Add(ePDF.mc1_minus);temp2->Add(ePDF.mc2_minus);temp3->Add(ePDF.mc3_minus);

  float allmc = temp1->Integral()+temp2->Integral()+temp3->Integral();
  float scalef_1 =   allmc/temp1->Integral();
  float scalef_2 =    allmc/temp2->Integral();
  float scalef_3 =    allmc/temp3->Integral();
  
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


  // Simultaneous PDF
  RooSimultaneous simPdf("simPdf","sim pdf",tagCat);

  if(addqcd){
    simPdf.addPdf(*ePDF.model_plus,"eplus");
    simPdf.addPdf(*ePDF.model_minus,"eminus");
  }
  else{
    simPdf.addPdf(*ePDF.sig_plus,"eplus");
    simPdf.addPdf(*ePDF.sig_minus,"eminus");
  }

  RooFitResult *fitr=0;
  fitr = simPdf.fitTo(combData,Minos(kTRUE),Save(kTRUE));

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
  ce->Divide(2,1);

  ce->cd(1);
  RooPlot * xframe = x->frame();
  
  //(*muPDF.rtest1_plus).plotOn(xframe,Binning(20));
  combData.plotOn(xframe,Binning(20),Cut("tagCat==tagCat::eplus"));
  tagCat="eplus";
  simPdf.plotOn(xframe,Slice(tagCat),ProjWData(tagCat,combData)); //simPdf.paramOn(xframe);
  
  simPdf.plotOn(xframe,Slice(tagCat),Components(*ePDF.h1_plus),ProjWData(tagCat,combData),LineColor(kRed),LineStyle(kDashed));
  simPdf.plotOn(xframe,Slice(tagCat),Components(*ePDF.h2_plus),ProjWData(tagCat,combData),LineColor(kGreen),LineStyle(kDashed));
  simPdf.plotOn(xframe,Slice(tagCat),Components(*ePDF.h3_plus),ProjWData(tagCat,combData),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    simPdf.plotOn(xframe,Slice(tagCat),Components(*ePDF.bkg),ProjWData(tagCat,combData),LineColor(kBlack),LineStyle(kDashed));
  } 
  
  xframe->Draw();

  ce->cd(2);
  RooPlot * xframe2 = x->frame();
  
  //(*muPDF.rtest1_minus).plotOn(xframe2,Binning(20));
  combData.plotOn(xframe2,Binning(20),Cut("tagCat==tagCat::eminus"));
  tagCat="eminus";
  simPdf.plotOn(xframe2,Slice(tagCat),ProjWData(tagCat,combData));// simPdf.paramOn(xframe);
  
  simPdf.plotOn(xframe2,Slice(tagCat),Components(*ePDF.h1_minus),ProjWData(tagCat,combData),LineColor(kRed),LineStyle(kDashed));
  simPdf.plotOn(xframe2,Slice(tagCat),Components(*ePDF.h2_minus),ProjWData(tagCat,combData),LineColor(kGreen),LineStyle(kDashed));
  simPdf.plotOn(xframe2,Slice(tagCat),Components(*ePDF.h3_minus),ProjWData(tagCat,combData),LineColor(kYellow),LineStyle(kDashed));
  
  if (addqcd) {
    simPdf.plotOn(xframe2,Slice(tagCat),Components(*ePDF.bkg),ProjWData(tagCat,combData),LineColor(kBlack),LineStyle(kDashed));
  } 
  xframe2->Draw();

  ce->Update();



   // Likelihood contours in two-dimensions

  TString canvasName_1="nll";
  canvasName_1+=scale;
  //  if( plus) canvasName+="plus";
  // else canvasName+="Minus";
  if (addqcd) canvasName_1+="_qcd";
  else canvasName_1+="_Wonly";

  TCanvas *c0 = new TCanvas(canvasName_1,"");

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  double lumi=(10.*scale);
  
  TString head="L ="; head+=lumi; head+=" pb-1";
  if (addqcd) head+=" (W+QCD)";
  leg->SetHeader(head);

  RooPlot *frame = new RooPlot(0,1,0,1); //f1.frame(0.,1.,20);
  fitr->plotOn(frame,*f1,*f2,"ME12VHB");
  frame->Draw();
  frame->SetTitle(";f_1;f_2");

  leg->Draw("SAME");

  TString pngName = canvasName_1+".png";
  //  c0->SaveAs(pngName);

  return fit;
}
