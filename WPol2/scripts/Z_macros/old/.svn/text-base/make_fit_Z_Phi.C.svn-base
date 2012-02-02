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


TString dir = "RECO_PolPlots_50toinf/";  
// Z templates
TString pHist1 = dir+"RECO_MuonPhiStarForZ_LH";
TString pHist2 = dir+"RECO_MuonPhiStarForZ_RH";
TString pHist3 = dir+"RECO_MuonPhiStarForZ_LO";
// Z data
TString pHist_data = dir+"RECO_MuonPhiStarForZ";



Int_t rbin=50;


void ScaleErrors(TH1D* h, double scale){
  h->Scale(scale);//h->Sumw2();
}

void make_fit_Z_Phi(int chrg=+1, double scale=1., bool addqcd=0, bool smear=0, bool draw_contour=0, bool toymc=0, bool addqcdtodata=0) {

 /* **** Arguments: */
 /*  - chrg = +1 by definition for the Z sample */
 /*  - scale = scale the weight of your sample by factor "scale" , i.e. new weight is : w*scale */
 /*  - addqcd = enable the additional bkg component in the Fit function */
 /*  - smear; 0: perform fit using the total statistics available (in this case errors on the drawing data will not match the scatter of the data points...). 1: redice the data distributions for both signal (W) and bkg according to the desired statistics determined by "scale". WARNING: in the case smear=1, the values obtained will be the initial values of fL,fR,f0, because the realdata sample will not be used at all. This is just for evaluating the fit performance. */
 /*  - draw_contour; 1: draw the minuit fit contours. 0:do not draw the muinuit contours */
 /* - toymc; 1: a toy MC study will be executed  */
  /* - addqcdtodata; if 1 adds the background MC sample to the realdata sample (NOT FOR REAL DATA!) */


  gSystem->Load("libRooFit"); using namespace RooFit;

 // TFile *mcdata = new TFile("./mc/RecoRoutines_Z-selection_zjets_madgraph.root");
TFile *mcdata = new TFile("./mc/test_newthetanewphi.root"); 
 TFile *fibkg; if (addqcd) fibkg = new TFile("./mc/RecoRoutines_Z-selection_ttbarTauola.root");
  //  TFile *realdata = new TFile("./totdata.root"); 
//  TFile *realdata = new TFile("./mc/RecoRoutines_Z-selection_zjets_madgraph.root"); // WARNING: not real data!!!
TFile *realdata = new TFile("./mc/test_newthetanewphi.root");

  // RooFit session
  RooRealVar *x = new RooRealVar("x","PhiStar variable",-5.005,4.995) ;


  TH1D *hMCsig, *hMCbkg, *hREALdata;

  // Get histograms from MC files 
    mc1 = (TH1D*)mcdata->Get(pHist1); mc2 = (TH1D*)mcdata->Get(pHist2); mc3 = (TH1D*)mcdata->Get(pHist3);
    hMCsig = (TH1D*)mcdata->Get(pHist_data);
    if (addqcd) hMCbkg = (TH1D*)fibkg->Get(pHist_data);

    // Scale to desired statistics
    if (addqcd) ScaleErrors(hMCbkg,scale); 
    ScaleErrors(hMCsig,scale);
    ScaleErrors(mc1,scale); ScaleErrors(mc2,scale); ScaleErrors(mc3,scale);

    // Rebinning
    mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);
    hMCsig->Rebin(rbin); 
    if(addqcd) hMCbkg->Rebin(rbin); 

  // Normalized statistics calculation
  if (addqcd){
    Double_t stat=hMCsig->Integral()+hMCbkg->Integral(); // total
    Double_t f_sig=(hMCsig->Integral())/stat; // signal fraction
    Double_t f_bkg=(hMCbkg->Integral())/stat; // bkg fraction
  } else {
    Double_t stat=hMCsig->Integral();
    Double_t f_sig=1.0;
    Double_t f_bkg=0.0;
  }

  // Change interpretation of parameters from (f1,f2) to (fL,fR,f0)
  RooDataHist *data1 = new RooDataHist ("data1","dataset1",*x,mc1);
  RooDataHist *data2  = new RooDataHist ("data2","dataset2",*x,mc2);
  RooDataHist *data3  = new RooDataHist ("data3","dataset3",*x,mc3);
  RooHistPdf *h1 = new RooHistPdf("h1","h1",*x,*data1);
  RooHistPdf *h2 = new RooHistPdf("h2","h2",*x,*data2);
  RooHistPdf *h3 = new RooHistPdf("h3","h3",*x,*data3);


  RooRealVar *f1 = new RooRealVar("f_{1}","f_{1}",0.380,0.,1.) ;
  RooRealVar *f2 = new RooRealVar("f_{2}","f_{2}",0.597,0.,1.) ;
  RooFormulaVar *fL = new RooFormulaVar("fL","f_{1}",RooArgList(*f1));
  RooFormulaVar *fR = new RooFormulaVar("fR","(1-f_{1})*f_{2}",RooArgList(*f1,*f2));



  /* IMPORT 100% TEMPLATES AND CONSTRUCT PDFS */

  // Signal 100% templates and PDF creation (see aux. class)
  RooAddPdf *sig = new RooAddPdf("sig","signal component",RooArgList(*h1,*h2,*h3),RooArgList(*fL,*fR));

  if(addqcd){
  // Background dataset
  RooDataHist *data_bkg = new RooDataHist("data4","dataset with CosThetaStar_Bck",*x,hMCbkg);
  RooHistPdf *bkg = new RooHistPdf("bkg","bkg",*x,*data_bkg);
  }

  // Bkg fraction
  RooRealVar *fbkg = new RooRealVar("f_{bkg}","f_bkg fraction",f_bkg);

  // composite PDF to be fit to data
  if (addqcd) RooAddPdf *model = new RooAddPdf("model","model",RooArgList(*bkg,*sig),*fbkg);
  else RooAddPdf *model = sig;



  /* IMPORT REAL DATA and prepare dataset to be fitted */

  hREALdata = (TH1D*)(realdata->Get(pHist_data));
  hREALdata->Rebin(rbin);
  if(addqcdtodata){
    hREALdata->Add(hMCbkg);
  }
  if (smear){
    cout << "Generating rediced data with N_sig = " << (stat*f_sig) << " and N_bkg = " << (stat*f_bkg) << endl;
    RooDataSet *smear_data=sig->generate(*x,int(f_sig*stat));
    if (addqcd) {
      RooDataSet *smear_bkg=bkg->generate(*x,int(f_bkg*stat));
      smear_data->append(*smear_bkg);
    }
     RooNLLVar nll("nll","nll",*model,*smear_data);
  } else {
    cout << "Using MC non-rediced data for fit: N_sig = "<< (stat*f_sig) << " and N_bkg = " << (stat*f_bkg) <<endl;
    RooDataHist *real_data = new RooDataHist("real_data","dataset with LPvar",*x,hREALdata);
    RooNLLVar nll("nll","nll",*model,*real_data);
  }



  /* MINUIT FIT */

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
  fitr->Print();


  //  RooAddPdf *polar_model =  new RooAddPdf("polar_model","",RooArgList(*h1,*h2,*h3),RooArgList(*f1,*fR)) ;
  RooAddPdf *polar_model =  sig;


  /* PLOTTING */

  /* MAIN PLOT: POLARIZATION TEMPLATES SUMMING UP TO DATA*/

  setStyles();

  TCanvas *ce = new TCanvas("hello","");

  hREALdata->SetLineColor(1); hREALdata->SetMarkerStyle(20);
  mc1->SetLineColor(2); mc1->SetLineStyle(2); mc1->SetLineWidth(3);
  mc2->SetLineColor(3); mc2->SetLineStyle(2); mc2->SetLineWidth(3); 
  mc3->SetLineColor(1); mc3->SetLineStyle(2); mc3->SetLineWidth(3);
  if (addqcd) hMCbkg->SetFillColor(5);


  TLegend *leg=legend();
  leg->SetHeader("#mu^{+} from Z");
  leg->AddEntry(hREALdata,"data","LP");
  leg->AddEntry(mc1,"f_{L}","L");leg->AddEntry(mc2,"f_{R}","L");leg->AddEntry(mc3,"f_{0}","L");
  if (addqcd) leg->AddEntry(hMCbkg,"background template","F");

  RooPlot * xframe = x->frame();

  if (smear) {
    smear_data->plotOn(xframe,Binning(20),DataError(RooAbsData::SumW2));
  } else {
    real_data->plotOn(xframe,Binning(20),DataError(RooAbsData::SumW2));
  }

  model->plotOn(xframe); //model->paramOn(xframe);
  
  polar_model->plotOn(xframe,Components(*h1),LineColor(kRed),LineStyle(kDashed));
  polar_model->plotOn(xframe,Components(*h2),LineColor(kGreen),LineStyle(kDashed));
  polar_model->plotOn(xframe,Components(*h3),LineColor(kBlack),LineStyle(kDashed));
  
  if (addqcd) {
    model->plotOn(xframe,Components(*bkg),FillColor(5),DrawOption("F"));
  } 

  xframe->Draw();
  leg->Draw("SAME");
  ce->Update();


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



  /* LIKELIHOOD CONTOURS IN TWO DIMENSIONS */

  // Likelihood contours in two-dimensions
   TString canvasName_1="nll";
  canvasName_1+=scale;

  if (addqcd) canvasName_1+="_qcd";
  else canvasName_1+="_Zonly";

  TString canvasName_2="pulls_";
  canvasName_2+=canvasName_1;

  
   if (draw_contour) {

  TCanvas *c0 = new TCanvas(canvasName_1,"");

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  double lumi=(1.*scale);

  
  TString head="L ="; head+=lumi; head+=" pb-1 IF SIGMA DOWNSCALED 100 FOR 1 PB^-1";
  if (addqcd) head+=" (Z+QCD)";
  leg->SetHeader(head);

  
  RooPlot *contour=new RooPlot(*f1,*f2);
  fitr->plotOn(contour,*f1,*f2,"ME12VHB");
  contour->Draw();
  RooPlot *mcontour = m.contour(*f1,*f2,1,2); 
  mcontour->Draw("SAME");
  leg->Draw("SAME");


  TCanvas *con[4];
  RooPlot *ncontour[4];
  TString contourname="c";
  for (int i=0;i<4;i++) {
    con[i] = new TCanvas(contourname.Append("0"),"");
    ncontour[i] = transform(mcontour,i);
    ncontour[i]->Draw();
  }

 
 } // end contour plots in 2D
  
   if(toymc){

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

    RooRealVar fLnom("fLnom","fLnom",0.388);
    RooRealVar fRnom("fRnom","fRnom",0.381);
    RooRealVar f0nom("f0nom","f0nom",0.230);


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

   } // end toy MC

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

