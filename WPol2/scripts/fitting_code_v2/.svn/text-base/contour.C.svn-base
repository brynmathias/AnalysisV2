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
#include "RooPlot.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TGraph.h"
void contour(Double_t x1,Double_t x2,Double_t s1, Double_t s2,Double_t rho,TString name, bool charge) {
  
  // MC values
  Double_t th1=0.322;
  Double_t th2=0.225;

  // by hand
  /*
 // lookup the 2x2 covariance matrix elements for these variables
  Double_t x1= 0.310;//par1->getVal();
  Double_t x2= 0.171;//par2->getVal();
  Double_t s1= 0.038;//par1->getError();
  Double_t s2= 0.125;//par2->getError();
  Double_t rho= -0.3;//correlation(parName1, parName2);
  */
  RooPlot *contour1=ellipse(x1,x2,s1,s2,rho,"E");
  //RooPlot *contour2=ellipse(x1,x2,0.04,0.13,rho,"EC",th1,th2);

  gROOT->SetStyle("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0); 

  TCanvas *c= new TCanvas(name,name,600,600);
  contour1->Draw();
  if(charge==true){
  contour1->GetXaxis()->SetTitle("(f_{L} - f_{R})^{ +}");
  contour1->GetYaxis()->SetTitle("f_{0}^{ +}");}
else{
  contour1->GetXaxis()->SetTitle("(f_{L}} - f_{R})^{ -}");
  contour1->GetYaxis()->SetTitle("f_{0}^{ -}");}
  contour1->GetXaxis()->SetTitleSize(0.05);
  contour1->GetYaxis()->SetTitleSize(0.05);
  contour1->GetXaxis()->SetTitleOffset(.9);
  contour1->GetYaxis()->SetTitleOffset(.85);

  const  int n = 2000;
  Double_t x[n], y[n];
  for (Int_t i=0;i<n;i++) {
    x[i] = -1+i*0.001; 
     y[i] = i*0.001; 
     if(i*0.001>1) y[i] = 2-i*0.001;
     //cout << " x :"<<x[i]  << " y :"<< y[i]  <<endl;
}

 TGraph * excl = new TGraph(n,x,y);
 excl->SetLineWidth(9903);
 excl->SetFillStyle(3005);
excl->Draw("SAMEC");
  // contour2->Draw("SAME");
}


RooPlot *ellipse(double x1, double x2, double s1, double s2, double rho, const char* options="ME12VH") {
  
  RooPlot* frame=new RooPlot(-1.,1.,0.,1.);

  TString opt(options);

  // add a 1-sigma error ellipse, if requested
  if(opt.Contains("E")) {
    RooEllipse *contour= new RooEllipse("contour",x1,x2,s1,s2,rho);
    contour->SetLineWidth(2) ;
    if (opt.Contains("C")) contour->SetLineColor(3);
    frame->addPlotable(contour);

 }

 frame->SetFillColor(kGreen);
  frame->SetFillStyle(1001);


    // TCanvas *c= new TCanvas("c","");
    // frame->Draw();

  // add the error bar for parameter 1, if requested
  if(opt.Contains("1")) {
    TLine *hline= new TLine(x1-s1,x2,x1+s1,x2);
    hline->SetLineColor(kRed);
    frame->addObject(hline);
  }

  if(opt.Contains("2")) {
    TLine *vline= new TLine(x1,x2-s2,x1,x2+s2);
    vline->SetLineColor(kRed);
    frame->addObject(vline);
  }

  if(opt.Contains("B")) {
    TBox *box= new TBox(x1-s1,x2-s2,x1+s1,x2+s2);
    box->SetLineStyle(kDashed);
    box->SetLineColor(kRed);
    box->SetFillStyle(0);
    frame->addObject(box);
  }

  if(opt.Contains("H")) {
    TLine *line= new TLine(x1-rho*s1,x2-s2,x1+rho*s1,x2+s2);
    line->SetLineStyle(kDashed);
    line->SetLineColor(kBlue);
    line->SetLineWidth(2) ;
    frame->addObject(line);
    if(opt.Contains("A")) {
      TGaxis *axis= new TGaxis(x1-s1,x2-s2,x1+s1,x2-s2,-1.,+1.,502,"-=");
      axis->SetLineColor(kBlue);
      frame->addObject(axis);
    }
  }

  if(opt.Contains("V")) {
    TLine *line= new TLine(x1-s1,x2-rho*s2,x1+s1,x2+rho*s2);
    line->SetLineStyle(kDashed);
    line->SetLineColor(kBlue);
    line->SetLineWidth(2) ;
    frame->addObject(line);
    if(opt.Contains("A")) {
      TGaxis *axis= new TGaxis(x1-s1,x2-s2,x1-s1,x2+s2,-1.,+1.,502,"-=");
      axis->SetLineColor(kBlue);
      frame->addObject(axis);
    }
  }

  //   add a marker at the fitted value, if requested
    if(opt.Contains("M")) {
    TMarker *marker= new TMarker(x1,x2,20);
    marker->SetMarkerColor(kBlack);
    frame->addObject(marker);
    /*
    TMarker *marker2= new TMarker(th1,th2,20);
    marker2->SetMarkerColor(kRed);
    frame->addObject(marker2);
    */
  }
  

  return frame;
}
