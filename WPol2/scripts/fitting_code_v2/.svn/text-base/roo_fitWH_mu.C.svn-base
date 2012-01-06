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

// Fit mode [fit in terms of 0:(fL,fR) or 1:(fL-fR,fL+fR)]
bool fitMode=1;
// Real or MC Data? If TRUE, pls beware of the integrated luminosity
bool realData=true; 
// add bkg term
bool addbkg=true;
// account for systematics 
bool addParameter=false;

// Run Toy MC studies
bool toyMC=false;

 // input data Files
TFile *sigfile = new TFile("RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
TFile *bkgfile=new TFile("RecoRoutines_W-selection_ZJets_madgraph_June2010.root");
//RecoRoutines_W-selection_WJets_madgraph_June2010_templateclosuretest.root");
TFile *refTemplates = new TFile("GenRoutines_WJets_madgraph_June2010_mcrecotesting.root");
TFile *datafile = new TFile("RecoRoutines_W-selection_dataskimnov4rereco.root");
//RecoRoutines_W-selection_realdata.root");
bool makePlots = true;

// Binning [check that the USer defined functions involve the same binning!!!]
Int_t rbin=10;
// Integrated luminosity
Int_t sfactor=36;

void roo_fitWH_mu()
{
  TString poscharge = "Plus";
  TString negcharge = "Minus";

  std::vector<TString> charge(2);
  charge.at(0) = poscharge;
  charge.at(1) = negcharge;

  TString canvas_name_plus = "MC_WHelicityFramePlots_PlusICVar";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",800,400);
  TString canvas_name_minus = "MC_WHelicityFramePlots_MinusICVar";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",800,400);
 
  // Run both for + and - charges
  for(unsigned int j=0; j<charge.size(); j++) {
   
    //  if (j==1) break; // do only + charge fit
    if (realData) { sfactor=35; }

      // Nominal values are taken from a fit to the MC W data (scaled to 100pb-1)
    RooRealVar *fLnom, *fRnom, *f0nom;
    if (j==0) { 
      fLnom=new RooRealVar("fL_nom","fLnom",0.556);
      fRnom=new RooRealVar("fR_nom","fRnom",0.234);
      f0nom=new RooRealVar("f0_nom","f0nom",0.210);
    } else {
      fLnom=new RooRealVar("fL_nom","fLnom",0.523);
      fRnom=new RooRealVar("fR_nom","fRnom",0.265);
      f0nom=new RooRealVar("f0_nom","f0nom",0.212);
    }

    TString Hist1 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j) + "_LH";
    TString Hist2 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j) + "_RH";
    TString Hist3 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j) + "_LO";
    TString Hist_data1 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j);
    
    TH1D *mc1 = (TH1D*)sigfile->Get(Hist1);
    TH1D *mc2 = (TH1D*)sigfile->Get(Hist2);
    TH1D *mc3 = (TH1D*)sigfile->Get(Hist3);
    
    TH1D *sighist = (TH1D*)sigfile->Get(Hist_data1); // W signal histogram
    TH1D *bkghist=(TH1D*)bkgfile->Get(Hist_data1); // Bkg histogram
    TH1D *hdata=(TH1D*)datafile->Get(Hist_data1); // Real data histogram

    // //we are only fitting for fL and fR
    // double accFactor1 = refTempHist1->Integral() / mc1->Integral();
    // double accFactor2 = refTempHist2->Integral() / mc2->Integral();
    // double accFactor3 = refTempHist3->Integral() / mc3->Integral();
    // double normFactor = (mc1->Integral() + mc2->Integral() + mc3->Integral()) / (refTempHist1->Integral() + refTempHist2->Integral() + refTempHist3->Integral());
    
    mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);
    sighist->Rebin(rbin); bkghist->Rebin(rbin); hdata->Rebin(rbin);

      // Scale to sfactor/pb if MC
    //if (!realData) {
    if (toyMC) sfactor=400;
    sighist->Scale(sfactor); bkghist->Scale(sfactor);
      // }
      //datahist->Scale(invWeightW);//to get MC errors - otherwise comment out

    Double_t nbkg=0;

    TH1D *datahist;
    if (realData) { datahist=hdata;
    } else {
      datahist=(TH1D*)sighist->Clone();
      if (addbkg) {datahist->Add(bkghist); }
    }
    if (addbkg) { 
      nbkg=bkghist->Integral();
    }

    Double_t istat=datahist->Integral();
    Double_t f_sig=(sighist->Integral())/istat; // signal fraction
    Double_t f_bkg=nbkg/istat; // bkg fraction


      // Start RooFit session
    RooRealVar x("x","LP",0.,1.3);
      // Import binned Data
    RooDataHist data1("data1","dataset with WHICVarPlus",x,mc1);
    RooDataHist data2("data2","dataset with WHICVarPlus",x,mc2);
    RooDataHist data3("data3","dataset with WHICVarPlus",x,mc3);
  
    RooDataHist test("data","dataset with WHICVarPlus",x,datahist);
    RooDataHist data_bkg("data4","dataset with ICVar",x,bkghist);

    // Relative fractions - allow them to float to negative values too if needs be
    //   if (fitMode==0) {
    RooRealVar f1("fL","fL fraction",fLnom->getVal(),0.,1.);
    RooRealVar f2("fR","fR fraction", fRnom->getVal(),0.,1.);
    RooFormulaVar f3("f0","1-fL-fR",RooArgList(f1,f2));
    if (fitMode) {
      f1.setVal((fLnom->getVal()-fRnom->getVal())); f1.setRange(-1.,1.); 
      f1.setPlotLabel("f_{L}-f_{R}"); 
      f2.setVal(f0nom->getVal()); 
      f2.setPlotLabel("f_{0}");
    } 
    // } else {
    //   RooRealVar f1("fL","fL fraction",(fLnom->getVal()-fRnom->getVal()),-1.,1.);
    //   RooRealVar f2("fR","fR fraction", (fLnom->getVal()+fRnom->getVal()),-1.,1.);
    //   RooFormulaVar f3("f0","1-fL-fR",RooArgList(f1,f2));
    // }
    RooRealVar fsub("fsub","fsub par",0.0,-10.,10.);
    RooRealVar fsum("fsum","fsum par",0.0, -10.,10.);
    // fsub.setVal(0.0);


    // Background template
    RooHistPdf *bkg = new RooHistPdf("bkg","bkg",x,data_bkg);
    // Bkg fraction
    RooRealVar fbkg("f_{bkg}","f_bkg fraction",f_bkg);

      // Templates 
    RooHistPdf h1("h1","h1",x,data1); // left-handed template histogram
    RooHistPdf h2("h2","h2",x,data2); // right-handed template histo
    RooHistPdf h3("h3","h3",x,data3); // longitudinal template histo

      // Construct model PDF
    RooAbsPdf *sig, *model;

    if (charge.at(j) == "Plus") { // plus charge PDFs
      if (addParameter) { sig = new RooWPlusExt("sigmodel","model",x,f1,f2,fsub,fsum);
      } else { sig = new RooWPlus("sigmodel","model",x,f1,f2); } 
    } else if (charge.at(j) == "Minus") { // minus charge PDFs
      if (addParameter) { sig = new RooWMinusExt("sigmodel","model",x,f1,f2,fsub,fsum);
      } else { sig = new RooWMinus("sigmodel","model",x,f1,f2); } 
    }
    
    if (addbkg) {
      model = new RooAddPdf("model","model",RooArgList(*bkg,*sig),fbkg);
    } else { model = sig; }
    
    // Set the Fit Range
    // x.setRange("fitrange",-0.0,1.3);
    // Construct likelihood ( + penalty term)
    RooNLLVar nll("nll","nll",*model,test,Range("fitrange"));
    RooRealVar pen("pen","penalty term",0.5/1.);
    RooRealVar pen2("pen2","penalty term 2",0.5/1.);
    RooFormulaVar nllPen("nllPen","nll+pen*fsub^2+pen2*fsum^2",RooArgList(nll,pen,fsub,pen2,fsum));
    
      // Fitting
    RooMinuit *m;
    if (!addParameter) { m = new RooMinuit(nll); }
    else {  m = new RooMinuit(nllPen);}

    if (!toyMC) {
      m->migrad(); m->hesse();
    }
    RooFitResult *res1 = m->save();
    
    // Re-diced data 
    // Int_t nevt=static_cast<int>(istat);
    // RooDataSet *gtest = model->generate(x,nevt);
    
    // Fitting
    //   RooFitResult * res1 = model.fitTo(test,Minos(kFALSE), Save());
    //       res1->Print();
   
    if(makePlots) {
   
      // Temp PDF for plotting purposes
      //  RooAddPdf temp("temp","component 1",RooArgList(*h1,*h2,*h3),RooArgList(*f1,*f2_p));
      // Plotting
      gROOT->SetStyle("Plain");  
      gStyle->SetOptFit(111);
      gStyle->SetOptTitle(0);
      gStyle->SetOptStat(0);      //gStyle->SetCanvasDefH(600); //Height of canvas
      //gStyle->SetCanvasDefW(600); //Width of canvas   
      if(charge.at(j) == "Plus") { c0->cd();
	c0->Divide(2,1);c0->cd(1);
      }
      if(charge.at(j) == "Minus") { c1->cd();
	c1->Divide(2,1);c1->cd(1);
      }

      datahist->Draw("E1");
      datahist->GetXaxis()->SetRangeUser(-1.9,1.9);
      datahist->SetMarkerStyle(20);

      RooPlot* frame = x.frame();
      test.plotOn(frame,Name("data")); 
      model->plotOn(frame,Name("model")); 
      model->paramOn(frame, Format("NELU", AutoPrecision(2)), Layout(0.1,0.5,0.9));
      // temp->plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
      // temp->plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
      // temp->plotOn(frame, Components(h3),LineColor(kYellow),LineStyle(kDashed));
      if (addbkg) {
	model->plotOn(frame,Components(*bkg),FillColor(5),DrawOption("F"));
      } 
      frame->GetXaxis()->SetTitle("LP Variable");
      frame->Draw("SAME");

      // Goodness-of-fit
      Double_t chi2= frame->chiSquare("model","data",3);
      Double_t nllmin=res1->minNll();
      cout << "" << endl;
      cout << "Printing out the goodness-of-fit measure:" << endl;
      cout << "chi2 = " << chi2 << "\t" << "min NLL = " << nllmin << endl;
      res1->Print();

	// Draw Minuit contours
      if(charge.at(j) == "Plus") { c0->cd(2);
      } else { c1->cd(2); }

	// RooPlot *rcont=m->contour(f1,f2,1,2);
	// rcont->Draw();
      RooPlot *rcontour=new RooPlot(f1,f2);
      res1->plotOn(rcontour,f1,f2,"ME123VHB");
      rcontour->Draw();
      if (fitMode) {
	rcontour->GetXaxis()->SetTitle("f_{L}-f_{R}");
	rcontour->GetYaxis()->SetTitle("f_{0}");
      } else {
	rcontour->GetXaxis()->SetTitle("f_{L}");
	rcontour->GetYaxis()->SetTitle("f_{R}");
      }
    }

    const TMatrixDSym& cor = res1->correlationMatrix();
    const TMatrixDSym& cov = res1->covarianceMatrix();
    
    //Print correlation, covariance matrix
    cout << "correlation matrix" << endl; cor.Print();
    cout << "covariance matrix" << endl; cov.Print();
  
    cout << f1 << endl; cout << f2 << endl;
    if (!fitMode) {
      cout << "f0 = " << f3 << " +/- " << f3.getPropagatedError(*res1) << endl;
    }
  }

  if(makePlots) {
    c0->Print(canvas_name_plus+".png");
    c1->Print(canvas_name_minus+".png");
  }

  if (toyMC) {

    // MC STudies
  Int_t nevt=istat;
  Int_t nEXP=100;

  RooMCStudy mgr(*model,*model,x,"","mhrv");
  mgr.generateAndFit(nEXP,nevt,kTRUE);
  
  TCanvas *cp0 = new TCanvas("c0","",1200,400);
  cp0->Divide(3,1);
  cp0->cd(1);
  RooPlot *p1=mgr.plotParam(f1); p1->Draw(); 
  if (fitMode) p1->SetTitle(";f_{L}-f_{R};number of toys");
  cp0->cd(2);
  RooPlot *p2 = mgr.plotError(f1); p2->Draw();
  if (fitMode) p2->SetTitle(";#delta (f_{L}-f_{R});number of toys");
  cp0->cd(3);
  // f1 pull
  RooPlot* m1pframe = mgr.plotPull(f1,-3.,3.,30,kTRUE);
  m1pframe->Draw();
  if (fitMode) {
    m1pframe->SetTitle(";f_{L}-f_{R};number of toys");
  }

  TCanvas *cp02 = new TCanvas("c1","",1200,400);
  cp02->Divide(3,1);
  cp02->cd(1);
  RooPlot *p3=mgr.plotParam(f2); p3->Draw();
  if (fitMode) p3->SetTitle(";f_{0};number of toys");
  cp02->cd(2);
  RooPlot *p4=mgr.plotError(f2); p4->Draw();
  if (fitMode) p4->SetTitle(";#delta f_{0}; number of toys");
  cp02->cd(3);
  // f2 pull
  RooPlot* m2pframe = mgr.plotPull(f2,-3.,3.,30,kTRUE);
  m2pframe->Draw();
  if (fitMode) {
    m2pframe->SetTitle(";f_{0};number of toys");
  }

  TCanvas *cnll = new TCanvas("cnll","");
  RooPlot* nllframe = mgr.plotNLL();
  nllframe->Draw();


  }

  return;
}
