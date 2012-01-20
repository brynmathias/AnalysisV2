#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooVoigtian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TH1F.h"
#include "TH2F.h"
#include <iostream>
#include <fstream>
#include "tdrstyle.C"

// This macro fits the convolution of a gaussian and a BW to the reconstructed Z mass, in each bin of pt of the mu.


void mueta(double zptcut=0, double ptmin=45, double lumiscale=0.36){


TH1D *histp = plotmacro(zptcut,ptmin,1,lumiscale);
TH1D *histm = plotmacro(zptcut,ptmin,-1,lumiscale);

/*
TF1 *sinp = new TF1("sinp","[0]+[1]*TMath::Sin([2]*x+[3])",-3.14,3.14);
sinp->SetParLimits(0,80,90);
sinp->SetParameters(0,85.0);
sinp->SetParLimits(1,1,20);
sinp->SetParameters(1,5);
sinp->SetParLimits(2,-3,3);
sinp->SetParameters(2,1);
sinp->SetParLimits(3,-3.14,3.14);
sinp->SetParameters(3,0.0);
sinp->SetLineColor(kRed);

TF1 *sinm = new TF1("sinm","[0]+[1]*TMath::Sin([2]*x+[3])",-3.14,3.14);
sinm->SetParLimits(0,80,90);
sinm->SetParameters(0,85.0);
sinm->SetParLimits(1,1,20);
sinm->SetParameters(1,5);
sinm->SetParLimits(2,-3,3);
sinm->SetParameters(2,1);
sinm->SetParLimits(3,-3.14,3.14);
sinm->SetParameters(3,0.0);
sinm->SetLineColor(kBlue);

histp->Fit(sinp,"","",-3.14,3.14);
histm->Fit(sinm,"","",-3.14,3.14);
*/

TCanvas *canv1 = new TCanvas();
canv1->Divide(3,1);
canv1->cd(1);
histp->Draw();
canv1->cd(2);
histm->Draw();
canv1->cd(3);
histp->Draw();
histm->Draw("same");
canv1->Update();

};

TH1D* plotmacro(double zptcut, double ptmin, int charge, double lumiscale){

//setTDRStyle();

 TFile *data = new TFile("./RecoRoutines_Z-selection_zjets_madgraph_skim100pb.root","read"); 
  
  
  TString dir;
  if (zptcut==0) dir="RECO_PolPlots_0toinf/";
  if (zptcut==50) dir="RECO_PolPlots_50toinf/";

  TString plottitle;
  if (charge>0) plottitle="RECO_0pcscale_MpEtavsMpPT_hrdMp";
  else plottitle="RECO_0pcscale_MmEtavsMmPT_hrdMm";

  TH2F *corrplot;
  corrplot = (TH2F*)data->Get((dir+plottitle).Data());


  double binwidth=400-ptmin;
  double ptmax=ptmin+binwidth;

  

  int bin0 = corrplot->GetYaxis()->FindBin(ptmin);
  int bin1 = corrplot->GetYaxis()->FindBin(ptmax);

  TH1D *hist = corrplot->ProjectionX("_px",bin0,bin1);
  hist->Scale(lumiscale);

 hist->SetTitle(plottitle.Data());

 if(charge>0) hist->SetLineColor(kRed); else hist->SetLineColor(kBlue);
 return hist;

};

