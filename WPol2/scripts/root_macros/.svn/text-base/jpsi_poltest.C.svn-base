#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit ;


void jpsi_poltest() {

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_realdatatest.root");

  TH1D * datahist = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_2ndMassJPsi");
  datahist->Rebin(10);
  //datahist->GetXaxis()->SetRangeUser(2.2,4.2);
  // Declare observable x
  RooRealVar x("x","J/Psi Mass [GeV]", 2.2, 3.8);

  RooRealVar mean("mean","mean of gaussians",3.1, 3.0, 3.2);
  RooRealVar sigma1("sigma1","width of gaussians",0.05, 0.01, 0.10);
  RooRealVar exponent("exponent", "exponent of exp",-0.6);

  RooGaussian sig1("sig1","Signal component 1",x,mean,sigma1);
  RooExponential bkg("bkg","Background component", x,exponent);

  RooRealVar sig1frac("sig1frac","fraction of component 1 in signal",0.8,0.,1.);
  RooAddPdf sig("sig","Signal",sig1,sig1frac);

  RooRealVar bkgfrac("bkgfrac","fraction of background",0.5,0.,1.) ;
  RooAddPdf  model("model","bkgsig",RooArgList(bkg,sig1), bkgfrac) ;

  RooDataHist data("data","datahist",x,datahist);
  model.fitTo(data);

  // Plot data and PDF overlaid
  RooPlot* xframe = x.frame();//x.frame(Title("Example of composite pdf=(sig1+sig2)+bkg")) ;
  data.plotOn(xframe);
  model.plotOn(xframe);

  // Overlay the background component of model with a dashed line
  model.plotOn(xframe,Components(bkg),LineStyle(kDashed));

  // Overlay the background+sig2 components of model with a dotted line
  //model.plotOn(xframe,Components(RooArgSet(bkg,sig2)),LineStyle(kDotted)) ;

  // Print structure of composite p.d.f.
  model.Print("t");
  model.paramOn(xframe);
  xframe->Draw();
  
  return;

  TH1D * SBhighplus = (TH1D*)file0->Get("RECO_PolPlots_SBhigh/RECO_ICVarPFPlus");
  TH1D * SBhighminus = (TH1D*)file0->Get("RECO_PolPlots_SBhigh/RECO_ICVarPFMinus");
  TH1D * SBlowplus = (TH1D*)file0->Get("RECO_PolPlots_SBlow/RECO_ICVarPFPlus");
  TH1D * SBlowminus = (TH1D*)file0->Get("RECO_PolPlots_SBlow/RECO_ICVarPFMinus");

  TH1D * dataplus = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus");
  TH1D * dataminus = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFMinus");

  TCanvas * c1 = new TCanvas();
  TCanvas * c2 = new TCanvas();
  TCanvas * c3 = new TCanvas();

  SBlowplus->Add(SBhighplus,+1);
  //SBlowplus->Rebin(10);
  //SBlowplus->DrawCopy();

  SBlowminus->Add(SBhighminus,+1);
  //SBlowminus->Rebin(10);
  //SBlowminus->DrawCopy();

  SBlowplus->Add(SBlowminus,+1);
  SBlowplus->Scale(1/17.0);

  dataplus->Add(SBlowplus,-1);
  dataminus->Add(SBlowplus,-1);

  c1->cd();
  dataplus->DrawCopy();
  c2->cd();
  dataminus->DrawCopy();

  dataplus->Add(dataminus,-1);
  c3->cd();
  dataplus->DrawCopy();

  file0->Close();
  return;
}
