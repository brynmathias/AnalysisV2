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

// Make sure same directory is declared in RooWPlus.cxx and RooWMinus.cxx as well.
TString dir = "RECO_PolPlots_50toinf/";  

// PLS do not change binning unless you take care to modify RooWPlus.cxx and RooWMinus as well...
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
  h->Scale(scale);//h->Sumw2();
}

void make_fit(int chrg=+1, double scale=10., bool addqcd=1, bool smear=0, bool draw_contour=1) {

 /* **** Arguments: */
 /*  - chrg = the W charge you want to fit for (+1 or -1) */
 /*  - scale = scale the weight of your sample by factor "scale" , i.e. new weight is : w*scale */
 /*  - addqcd = enable the additional bkg component in DATA and Fit function */
 /*  - smear; 0: perform fit using the total statistics available (in this case errors on the drawing data will not match the scatter of the data points...). 1: redice the data distributions for both signal (W) and bkg according to the desired statistics determined by "scale" */
 /*  - draw_contour; 1: draw the minuit fit contours. 0:do not draw the muinuit contours - instead a toy MC study will be executed !!! */

/*   **** Please NOTE: */
/* This macro requires that RooWPlus_cxx.so and RooWMinus_cxx.so shared libraries have been previously build. To do so, please use "run.C" to execute this macro */

  gSystem->Load("libRooFit"); using namespace RooFit;

  TFile *mcdata = new TFile("RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile *fibkg= new TFile("RecoRoutines_W-selection_Bkg.root");

  // RooFit session
  RooRealVar *x = new RooRealVar("x","LP variable",-0.4,1.6) ;
  //RooRealVar *x = new RooRealVar("x","LP variable",-0.5,1.6) ;

  RooRealVar *f1 = new RooRealVar("f_{1}","f_{1}",0.556,0.,1.) ;
  RooRealVar *f2 = new RooRealVar("f_{2}","f_{2}",0.555,0.,1.) ;
  // RooRealVar *f2 = new RooRealVar("f_{R}","f_{R}",0.234,0.,1.) ;

  TH1D *hsig, *hbkg;
  if (chrg>0) {
    mc1 = (TH1D*)mcdata->Get(pHist1); mc2 = (TH1D*)mcdata->Get(pHist2); mc3 = (TH1D*)mcdata->Get(pHist3);
    hsig = (TH1D*)mcdata->Get(pHist_data);
    hbkg = (TH1D*)fibkg->Get(pHist_data);
  } else {
    mc1 = (TH1D*)mcdata->Get(mHist1); mc2 = (TH1D*)mcdata->Get(mHist2); mc3 = (TH1D*)mcdata->Get(mHist3);
    hsig = (TH1D*)mcdata->Get(mHist_data); 
    hbkg = (TH1D*)fibkg->Get(mHist_data);
  }
  mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);
  hsig->Rebin(rbin);hbkg->Rebin(rbin);
  TH1D *test = hsig->Clone();
  
  // QCDetc background
  Double_t nbkg=0;
  
  ScaleErrors(hbkg,scale); ScaleErrors(test,scale); ScaleErrors(hsig,scale);
  ScaleErrors(mc1,scale); ScaleErrors(mc2,scale); ScaleErrors(mc3,scale);
  
  if(addqcd){
    test->Add(hbkg); nbkg=hbkg->Integral();
  }
  
  // Normalized statistics
  Double_t stat=test->Integral(); // total
  Double_t f_sig=(hsig->Integral())/stat; // signal fraction
  Double_t f_bkg=nbkg/stat; // bkg fraction

    // Import binned Data
  RooDataHist *data1 = new RooDataHist ("data1","dataset with ICvar",*x,mc1);
  RooDataHist *data2  = new RooDataHist ("data2","dataset with ICvar",*x,mc2);
  RooDataHist *data3  = new RooDataHist ("data3","dataset with ICvar",*x,mc3);

  // Signal template
  RooDataHist *data_sig = new RooDataHist("datas","dataset with ICVar",*x,hsig);
    // Background template
  RooDataHist *data_bkg = new RooDataHist("data4","dataset with ICVar",*x,hbkg);
  RooHistPdf *bkg = new RooHistPdf("bkg","bkg",*x,*data_bkg);

  // Bkg fraction
  RooRealVar *fbkg = new RooRealVar("f_{bkg}","f_bkg fraction",f_bkg);//,0.,1.) ;
  // Templates
  RooHistPdf *h1 = new RooHistPdf("h1","h1",*x,*data1);
  RooHistPdf *h2 = new RooHistPdf("h2","h2",*x,*data2);
  RooHistPdf *h3 = new RooHistPdf("h3","h3",*x,*data3);

  if (chrg>0) {
    RooWPlus *sig = new RooWPlus("sig","signal component",*x,*f1,*f2);
  } else {
    RooWMinus *sig = new RooWMinus("sig","signal component",*x,*f1,*f2);
  }
  // composite PDF
  RooAddPdf *model = new RooAddPdf("model","model",RooArgList(*bkg,*sig),*fbkg);

  // Data
  cout << "Generating data with N_sig = " << (stat*f_sig) << " and N_bkg = " << (stat*f_bkg) << endl;

  // Redice data: signal and background data are smeared separately
  RooDataSet *smear_sig=sig->generate(*x,int(f_sig*stat));
  if (addqcd) {
    RooDataSet *smear_bkg=bkg->generate(*x,int(f_bkg*stat));
    smear_sig->append(*smear_bkg);
  }
  RooDataSet *smear_data=smear_sig;  
  
  //  RooDataSet *smear_data=model->generate(*x,int(stat)); // smeared data
  RooDataHist *mc_data = new RooDataHist("montecarlo_data","dataset with LPvar",*x,test); // MC data (using total stats but normalized)

  //  return;

  // Fitting
  if (smear) {
    RooNLLVar nll("nll","nll",*model,*smear_data);
  } else {
    RooNLLVar nll("nll","nll",*model,*mc_data);
  }
  RooMinuit m(nll);
  // Activate constant-term optimization (always recommended)
  m.optimizeConst(kTRUE) ;
  // Activate profile timing
  m.setProfile(kTRUE) ;
  // Activate verbose logging
  m.setVerbose(kFALSE) ;
  // Run MIGRAD (parameters free)
  m.migrad() ;
  // Run HESSE (parameters free)
  m.hesse() ;
  // Deactivate verbose logging
  m.setVerbose(kFALSE) ;
// Run MIGRAD (parameters free)
//  m.migrad() ;
   // Run MINOS (parameters free)
  m.minos() ;

  RooFitResult *fitr=m.save();
 
  //RooFitResult *fitr=model->fitTo(*mc_data,Minos(kTRUE),Save(kTRUE));
  fitr->Print();

  // Change interpretation of parameters (if needed)
 
  RooFormulaVar *f2_p = new RooFormulaVar("f2_p","(1-f_{1})*f_{2}",RooArgList(*f1,*f2));
  RooAddPdf *temp =  new RooAddPdf("temp","component 1",RooArgList(*h1,*h2,*h3),RooArgList(*f1,*f2_p)) ;
  
  // Plotting
  setStyles();

  TCanvas *ce = new TCanvas("hello","");

  TLegend *leg=legend();
  if (chrg>0) {
    leg->SetHeader("#mu^{+}");
  } else {
    leg->SetHeader("#mu^{-}");
  }
  TH1D *fun=test->Clone();
  fun->SetLineColor(4); fun->SetLineWidth(3);
  test->SetLineColor(1); test->SetMarkerStyle(20);
  mc1->SetLineColor(2); mc1->SetLineStyle(2); mc1->SetLineWidth(3);
  mc2->SetLineColor(3); mc2->SetLineStyle(2); mc2->SetLineWidth(3); 
  mc3->SetLineColor(1); mc3->SetLineStyle(2); mc3->SetLineWidth(3);
  hbkg->SetFillColor(5);

  leg->AddEntry(test,"data","LP");
  leg->AddEntry(fun,"Fit result","L");
  leg->AddEntry(mc1,"f_{L}","L");leg->AddEntry(mc2,"f_{R}","L");leg->AddEntry(mc3,"f_{0}","L");
  leg->AddEntry(hbkg,"background template","F");

  RooPlot * xframe = x->frame();

  if (smear) {
    smear_data->plotOn(xframe,Binning(20),DataError(RooAbsData::SumW2));
  } else {
    mc_data->plotOn(xframe,Binning(20),DataError(RooAbsData::SumW2));
  }

  model->plotOn(xframe); //model->paramOn(xframe);
  
  temp->plotOn(xframe,Components(*h1),LineColor(kRed),LineStyle(kDashed));
  temp->plotOn(xframe,Components(*h2),LineColor(kGreen),LineStyle(kDashed));
  temp->plotOn(xframe,Components(*h3),LineColor(kBlack),LineStyle(kDashed));
  
  if (addqcd) {
    model->plotOn(xframe,Components(*bkg),FillColor(5),DrawOption("F"));
  } 
  // xframe->GetYaxis()->SetRangeUser(0.,120.);
  xframe->Draw();

  leg->Draw("SAME");
  ce->Update();
  
 // (f1,f2) --> (fL,fR)
  /* double fLreal = f1->getVal(); */
  /* double fRreal = (1.-f1->getVal())*f2->getVal(); */
  /* double f0real = (1.-f1->getVal())*(1.-f2->getVal()); */

  // Nominal values are taken from a fit to the MC W data (scaled to 100pb-1)
  if (chrg>0) { 
    RooRealVar fLnom("fLnom","fLnom",0.556);
    RooRealVar fRnom("fRnom","fRnom",0.234);
    RooRealVar f0nom("f0nom","f0nom",0.210);
  } else {
    RooRealVar fLnom("fLnom","fLnom",0.523);
    RooRealVar fRnom("fRnom","fRnom",0.265);
    RooRealVar f0nom("f0nom","f0nom",0.212);
  }

  double fLerror = f1->getError();
  double fRerror = error( (1.-f1->getVal()), f2->getVal(), -f1->getError(), f2->getError(),fitr->correlation(*f1,*f2) );
  double f0error = error( (1.-f1->getVal()), (1.-f2->getVal()), -f1->getError(), -f2->getError(), fitr->correlation(*f1,*f2) );
			  
  // Printing
  cout << "" << endl;
  cout << "************************************************************************" << endl;
  cout << "fL = " << f1->getVal() << "\t +- " << f1->getError() << endl;
  cout << "fR = " << (1.-f1->getVal())*f2->getVal() << "\t +- " << fRerror << endl;
  cout << "f0 = " << (1.-f1->getVal())*(1.-f2->getVal()) << "\t +- " << f0error << endl;
  cout << "************************************************************************" << endl;
  cout << "" << endl;

  // Likelihood contours in two-dimensions
   TString canvasName_1="nll";
  canvasName_1+=scale;
  //  if( plus) canvasName+="plus";
  // else canvasName+="Minus";
  if (addqcd) canvasName_1+="_qcd";
  else canvasName_1+="_Wonly";

  TString canvasName_2="pulls_";
  canvasName_2+=canvasName_1;

   if (draw_contour) {

  TCanvas *c0 = new TCanvas(canvasName_1,"");

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  double lumi=(1.*scale);
  
  TString head="L ="; head+=lumi; head+=" pb-1";
  if (addqcd) head+=" (W+QCD)";
  leg->SetHeader(head);

  RooPlot *contour=new RooPlot(*f1,*f2);
  fitr->plotOn(contour,*f1,*f2,"ME12VHB");

  RooPlot *mcontour = m.contour(*f1,*f2,1,2); 
  mcontour->Draw();
  contour->Draw("SAME");

  TString cname="bla";
  if (addqcd) cname+="bla";

  TCanvas *con0 = new TCanvas("con0","");
  TLegend *leg=legend();
  if (chrg>0) {
    leg->SetHeader("#mu^{+}");
  } else {
    leg->SetHeader("#mu^{-}");
  }
  //  RooPlot *ncontour = straight_transform(mcontour,1.,1.,0);
  RooPlot *ncontour0 = transform(mcontour,0);
  ncontour0->Draw();
  leg->Draw("SAME");

  TCanvas *con01 = new TCanvas("con01","");
  TLegend *leg=legend();
  if (chrg>0) {
    leg->SetHeader("#mu^{+}");
  } else {
    leg->SetHeader("#mu^{-}");
  }
  //  RooPlot *ncontour = straight_transform(mcontour,1.,1.,0);
  RooPlot *ncontour = transform(mcontour,1);
  ncontour->Draw();
  leg->Draw("SAME");

  TCanvas *con02 = new TCanvas("con02","");
  TLegend *leg=legend();
  if (chrg>0) {
    leg->SetHeader("#mu^{+}");
  } else {
    leg->SetHeader("#mu^{-}");
  }
  //  RooPlot *ncontour = straight_transform(mcontour,1.,1.,0);
  RooPlot *ncontour2 = transform(mcontour,2);
  ncontour2->Draw();
  leg->Draw("SAME");

   TCanvas *con03 = new TCanvas("con03","");
  TLegend *leg=legend();
  if (chrg>0) {
    leg->SetHeader("#mu^{+}");
  } else {
    leg->SetHeader("#mu^{-}");
  }
  //  RooPlot *ncontour = straight_transform(mcontour,1.,1.,0);
  RooPlot *ncontour3 = transform(mcontour,3);
  ncontour3->Draw();
  leg->Draw("SAME");

  return;


  }

// MC STudies
  Int_t nevt=stat;
  Int_t nEXP=100;

  RooMCStudy mgr(*model,*model,*x,"","mhrv");
  mgr.generateAndFit(nEXP,nevt,kTRUE);

  TCanvas *cp0 = new TCanvas(canvasName_2,"");

  // f1 pull
  RooPlot* m1pframe = mgr.plotPull(*f1,-3.,3.,30,kTRUE);
  m1pframe->Draw();

  canvasName_2+="_fr";
  TCanvas *cp02 = new TCanvas(canvasName_2,"");
  // f2 pull
  RooPlot* m2pframe = mgr.plotPull(*f2,-3.,3.,30,kTRUE);
  m2pframe->Draw();

  TCanvas *cnll = new TCanvas("cnll","");
  RooPlot* nllframe = mgr.plotNLL();
  nllframe->Draw();
  
  // Loop into the MC toys
  double a1_error, a2_error;
  double e_fL_i, e_fR_i, e_f0_i;

  // Toy histograms
  TH1D *fL_pull=new TH1D("pull1","",30,-3.,3.);
  TH1D *fR_pull=new TH1D("pull2","",30,-3.,3.);
  TH1D *f0_pull=new TH1D("pull3","",30,-3.,3.);
  // val dist
  TH1D *fL_val=new TH1D("val1","",50,0.,1.);
  TH1D *fR_val=new TH1D("val2","",50,0.,1.);
  TH1D *f0_val=new TH1D("val3","",50,0.,1.);
  // error dist
  TH1D *fL_error=new TH1D("error1","",200,0.,1.);
  TH1D *fR_error=new TH1D("error2","",200,0.,1.);
  TH1D *f0_error=new TH1D("error3","",200,0.,1.);

  // correlations
  TH2D *fL_fR=new TH2D("flfr","",50,0.,1.,50,0.,1.);
  TH2D *fL_f0=new TH2D("flf0","",50,0.,1.,50,0.,1.);
  TH2D *fR_f0=new TH2D("frf0","",50,0.,1.,50,0.,1.);

  for (Int_t i=0; i<nEXP; i++) {

    RooFitResult *fr=mgr.fitResult(i);
    const RooArgList list=fr->floatParsFinal();

    RooRealVar *a1=dynamic_cast<RooRealVar*>(list.at(0));
    RooRealVar *a2=dynamic_cast<RooRealVar*>(list.at(1));

    double fL_i = a1->getVal();
    double fR_i = (1.-a1->getVal())*a2->getVal();
    double f0_i = (1.-a1->getVal())*(1.-a2->getVal());

    // If asymmetric errors are calculated in the fit (by MINOS), those will be used in the pull calculation

    a1_error=a1->getError();
    a2_error=a2->getError(); 

    e_fL_i = a1_error;
    e_fR_i = error( (1.-a1->getVal()), a2->getVal(), -a1_error, a2_error,
		    fr->correlation(*a1,*a2) );
    e_f0_i = error( (1.-a1->getVal()), (1.-a2->getVal()), -a1_error, -a2_error, 
		    fr->correlation(*a1,*a2) );


    // Fill pull histogram
    double pull_L = (fLnom.getVal()-fL_i) / e_fL_i;
    double pull_R = (fRnom.getVal()-fR_i) / e_fR_i;
    double pull_0 = (f0nom.getVal()-f0_i) / e_f0_i;

    fL_val->Fill(fL_i); fR_val->Fill(fR_i); f0_val->Fill(f0_i);
    fL_error->Fill(e_fL_i); fR_error->Fill(e_fR_i); f0_error->Fill(e_f0_i);
    fL_pull->Fill(pull_L); fR_pull->Fill(pull_R); f0_pull->Fill(pull_0);

    fL_fR->Fill(fL_i,fR_i); fL_f0->Fill(fL_i,f0_i); fR_f0->Fill(fR_i,f0_i);

  }

  gStyle->SetOptFit(1);
  gStyle->SetOptStat(1100);

  TCanvas *cp1 = new TCanvas("cp1","");
  fL_pull->Fit("gaus","+","E1"); fL_pull->SetMarkerStyle(20);
  TCanvas *cp2 = new TCanvas("cp2","");
  fR_pull->Fit("gaus","+","E1"); fR_pull->SetMarkerStyle(20);
  TCanvas *cp3 = new TCanvas("cp3","");
  f0_pull->Fit("gaus","+","E1"); f0_pull->SetMarkerStyle(20);

  TCanvas *vp1 = new TCanvas("vp1","");
  fL_val->Draw("E1"); fL_val->SetMarkerStyle(20);
  TCanvas *vp2 = new TCanvas("vp2","");
  fR_val->Draw("E1"); fR_val->SetMarkerStyle(20);
  TCanvas *vp3 = new TCanvas("vp3","");
  f0_val->Draw("E1"); f0_val->SetMarkerStyle(20);

  TCanvas *ep1 = new TCanvas("ep1","");
  fL_error->Draw("E1"); fL_error->SetMarkerStyle(20);
  TCanvas *ep2 = new TCanvas("ep2","");
  fR_error->Draw("E1"); fR_error->SetMarkerStyle(20);
  TCanvas *ep3 = new TCanvas("ep3","");
  f0_error->Draw("E1"); f0_error->SetMarkerStyle(20);

  //correlations
  TCanvas *cop1 = new TCanvas("cop1","");
  fL_fR->Draw("COLZ"); fL_fR->SetTitle(";f_{L};f_{R}");
  TCanvas *cop2 = new TCanvas("cop2","");
  fR_f0->Draw("COLZ");  fR_f0->SetTitle(";f_{R};f_{0}");
  TCanvas *cop3 = new TCanvas("cop3","");
  fL_f0->Draw("COLZ"); fL_f0->SetTitle(";f_{L};f_{0}");

}

RooPlot *straight_transform(RooPlot *contour, double corx, double cory, bool mode) {

  RooPlot *h;

  if (mode) {
    h = new RooPlot(0.,1.,0.,1.);//contour->Clone(); h->Reset();
  } else {
    h = new RooPlot(0.,1.,0.,1.01);
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

    if (g1) ix1[i]=corx*g1->GetX()[i];
    if (g2) ix2[i]=corx*g2->GetX()[i];

    if (g1) iy1prime[i]=cory*(g1->GetY()[i]);
    if (g2) iy2prime[i]=cory*(g2->GetY()[i]);
    
    if (g1) {
      idiff1[i]=ix1[i]-iy1prime[i];
      isum1[i]=ix1[i]+iy1prime[i];
    }
    if (g2) {
      idiff2[i]=ix2[i]-iy2prime[i];
      isum2[i]=ix2[i]+iy2prime[i];
    }
  }

  Double_t mx=corx*point->GetX();
  Double_t my=cory*point->GetY();
  TMarker *dpoint; //= new TMarker(mx, my, 8);

  TGraph *c1, *c2;
  if (mode) {
    if (g1) c1 = new TGraph(50,ix1,iy1prime);
    if (g2) c2 = new TGraph(50,ix2,iy2prime);
    dpoint=new TMarker(mx,my,8);
    h->SetTitle(";f_{L};f_{R}");
  } else {
    if (g1) c1 = new TGraph(50,idiff1,isum1);
    if (g2) c2 = new TGraph(50,idiff2,isum2);
    dpoint=new TMarker((mx-my),(mx+my),8);
    h->SetTitle(";f_{L}-f_{R};f_{L}+f_{R}");
  }

  if (g1) {
    c1->SetLineStyle(1) ;
    c1->SetLineWidth(2) ;
    c1->SetLineColor(kBlue) ;
  }
  if (g2) {
    c2->SetLineStyle(2) ;
    c2->SetLineWidth(2) ;
    c2->SetLineColor(kBlue) ;
  }
  //  c1->Draw("A");
  h->addObject(dpoint);
  if (g1) h->addObject(c1,"L");
  if (g2) h->addObject(c2,"L");

  return h;

}

RooPlot *transform(RooPlot *contour,  int mode) {

  RooPlot *h;

  if (mode==0) {
    h = new RooPlot(0.,1.,0.,1.01);//contour->Clone(); h->Reset();
  } else {
    h = new RooPlot(0.,1.,0.,1.);
  }

  contour->Print();

  TGraph *g1 = (TGraph*)contour->findObject("contour_nll_n1.000000");
  TGraph *g2 = (TGraph*)contour->findObject("contour_nll_n2.000000");
  TMarker *point= (TMarker*)contour->findObject("TMarker");

  Double_t ix1[51], ix2[51];
  Double_t iy1prime[51], iy2prime[51];
  Double_t iz1prime[51], iz2prime[51];

  Double_t idiff1[51], isum1[51];
  Double_t idiff2[51], isum2[51];

  int g1_N, g2_N;
  if (g1) {

    g1_N=g1->GetN();
    cout << "g1 points = " << g1_N << endl;
    
    for (int i=0; i<g1_N; i++) {
    
      ix1[i]=g1->GetX()[i];
      iy1prime[i]=(1.-(g1->GetX()[i]))*(g1->GetY()[i]);
      iz1prime[i]=(1.-(g1->GetX()[i]))*(1.-(g1->GetY()[i]));

      idiff1[i]=ix1[i]-iy1prime[i];
      isum1[i]=ix1[i]+iy1prime[i];
      
    }
  } // if g1 exists

  if (g2) {
    g2_N=g2->GetN();

    cout << "g2 points = " << g2_N << endl;

    for (int i=0; i<g2_N; i++) {

      ix2[i]=g2->GetX()[i];
      iy2prime[i]=(1.-(g2->GetX()[i]))*(g2->GetY()[i]);
      iz2prime[i]=(1.-(g2->GetX()[i]))*(1.-(g2->GetY()[i]));

      idiff2[i]=ix2[i]-iy2prime[i];
      isum2[i]=ix2[i]+iy2prime[i];

    }
  }

  Double_t mx=point->GetX();
  Double_t my=(1-point->GetX())*point->GetY();
  Double_t mz=(1-point->GetX())*(1.-point->GetY());
  TMarker *dpoint; //= new TMarker(mx, my, 8);

  TGraph *c1, *c2;
  if (mode==1) {
    if(g1) c1 = new TGraph(g1_N,ix1,iy1prime);
    if (g2) c2 = new TGraph(g2_N,ix2,iy2prime);
    dpoint=new TMarker(mx,my,8);
    h->SetTitle(";f_{L};f_{R}");
  } else if (mode==0) {
    if (g1) c1 = new TGraph(g1_N,idiff1,isum1);
    if (g2) c2 = new TGraph(g2_N,idiff2,isum2);
    dpoint=new TMarker((mx-my),(mx+my),8);
    h->SetTitle(";f_{L}-f_{R};f_{L}+f_{R}");
  } else if (mode==2) {
    if (g1) c1 = new TGraph(g1_N,ix1,iz1prime);
    if (g2) c2 = new TGraph(g2_N,ix2,iz2prime);
    dpoint=new TMarker(mx,mz,8);
    h->SetTitle(";f_{L};f_{0}");
  } else if (mode==3) {
    if (g1) c1 = new TGraph(g1_N,iy1prime,iz1prime);
    if (g2) c2 = new TGraph(g2_N,iy2prime,iz2prime);
    dpoint=new TMarker(my,mz,8);
    h->SetTitle(";f_{R};f_{0}");
  }

  if (g1) {
    c1->SetLineStyle(1) ;
    c1->SetLineWidth(2) ;
    c1->SetLineColor(kBlue) ;
  }
  if (g2) {
    c2->SetLineStyle(2) ;
    c2->SetLineWidth(2) ;
    c2->SetLineColor(kBlue) ;
  }
  //  c1->Draw("A");
  h->addObject(dpoint);
  if (g1) h->addObject(c1,"L");
  if (g2) h->addObject(c2,"L");

  return h;

}

double error(double alpha, double beta, double dalpha, double dbeta, double cor) {
  // error on parameter C = A*B, when parameters A and B are correlated...
  return sqrt( beta*beta*dalpha*dalpha + alpha*alpha*dbeta*dbeta +
		    2.*alpha*beta*dalpha*dbeta*cor );

}

void setStyles() {

  gROOT->SetStyle("Plain");
  gStyle->SetCanvasDefW(600);
  gStyle->SetCanvasDefH(500);

  // For the axis titles:

  gStyle->SetTitleColor(1, "XYZ");
  //  gStyle->SetTitleFont(42, "XYZ");
  gStyle->SetTitleSize(0.05, "XYZ");
  // gStyle->SetTitleXSize(Float_t size = 0.02); // Another way to set the size?
  // gStyle->SetTitleYSize(Float_t size = 0.02);
  gStyle->SetTitleXOffset(0.95);
  gStyle->SetTitleYOffset(1.1);
  // gStyle->SetTitleOffset(1.1, "Y"); // Another way to set the Offset

  // For the axis labels:

  gStyle->SetLabelColor(1, "XYZ");
  gStyle->SetLabelFont(42, "XYZ");
  gStyle->SetLabelOffset(0.007, "XYZ");
  gStyle->SetLabelSize(0.05, "XYZ");

}

TLegend *legend() {

 TLegend *leg2 = new TLegend(0.4379195,0.5677966,0.8573826,0.8771186);
 leg2->SetFillStyle(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.05);
 leg2->SetTextFont(42);

 return leg2;

}

