#ifndef __CINT__
#include "RooGlobalFunc.h"
 #endif

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooMinuit.h"
#include "RooSimultaneous.h"
#include "RooCategory.h"
#include "TCanvas.h"
#include "TString.h"
#include "RooPlot.h"




#include <vector.h>

// Run for + or - charge, +: chrg=0 , -: chrg=1
int chrg=1;
// Fit range limits
double xmin=0.;
double xmax=1.3;
double quanta=0.001;
// Fit mode [fit in terms of 0:(fL,fR) or 1:(fL-fR,f0)]
bool fitMode=1;
// Real or MC Data? If TRUE, pls beware of the integrated luminosity
bool realData=true; 
// add bkg term
bool addbkg=true;
bool addqcd=true;
bool usetemplate=true;
// account for systematics 
bool addParameter=false;

// Run Toy MC studies
bool toyMC=false;

//TString mcdir="WPolFiles/_Not_ResolutionCorrectedMC_v1/";

TString poscharge = "Plus";
TString negcharge = "Minus";

//RecoRoutines_W-selection_realdata.root");
bool makePlots = false;

// Binning [check that the USer defined functions involve the same binning!!!]
Int_t rbin=10;
// Integrated luminosity
Double_t sfactor=36.;

std::vector<TString> echarge(2);
std::vector<TString> charge(2);

// Muon files
// TFile *msigfile, *mbkgfile, *mdatafile;
// msigfile = new TFile("RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
// mbkgfile=new TFile("RecoRoutines_W-selection_ZTTbar.root");
// mdatafile = new TFile("RecoRoutines_W-selection_dataskimnov4rereco.root");
// // Electron files
// TFile *esigfile, *ebkgfile, *eqcdfile, *edatafile;
// esigfile = new TFile(mcdir+"eWPol_WJets-madgraph_v1.root");
// ebkgfile=new TFile(mcdir+"eWPol_BKG.root");
// eqcdfile=new TFile(mcdir+"eWPol_QCD.root");
// edatafile = new TFile("WPolFiles/ECALTransparencyCorrectedData_v3/eWPol_EG_transp_corr.root");

class Muons{
public:
  RooRealVar *fbkg;
  // PDFs
  RooAbsPdf *model, *sig;
  RooHistPdf *bkg;
  // data
  RooDataHist *test, *data_bkg;

  // TH1Ds
  // TH1D *mc1, *mc2, *mc3;
  TH1D *sighist, *bkghist, *hdata;
  TH1D *datahist;

  TFile *msigfile, *mbkgfile, *mdatafile;

  Muons(int chrg, RooRealVar *x, RooRealVar *f1, RooRealVar *f2, RooRealVar *fs)
  {

  // TString poscharge = "Plus";
  // TString negcharge = "Minus";

    // std::vector<TString> charge(2);
  charge.at(0) = poscharge;
  charge.at(1) = negcharge;


TString dir="/vols/cms02/georgia/WPol/";
  msigfile = new TFile(dir+"RecoRoutines_W-selection_WJetsMGZ238PU.root");
  mbkgfile=new TFile(dir+"RecoRoutines_W-selection_ZTTbar_newJetColl.root");
  mdatafile = new TFile(dir+"RecoRoutines_W-selection_dataskimnov4rereco_newJetColl.root");

  // Run both for + and - charges
  for(unsigned int j=0; j<charge.size(); j++) {
   
       if (j!=chrg) continue; // do only + charge fit
   
    if (realData) { sfactor=36; }

    // TString Hist1 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j) + "_LH";
    // TString Hist2 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j) + "_RH";
    // TString Hist3 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j) + "_LO";

    TString Hist_data1 = "RECO_PolPlots_50toinf/RECO_ICVarPF"+ charge.at(j);
    
    // mc1 = (TH1D*)msigfile->Get(Hist1);
    // mc2 = (TH1D*)msigfile->Get(Hist2);
    // mc3 = (TH1D*)msigfile->Get(Hist3);
    
    sighist = (TH1D*)msigfile->Get(Hist_data1)->Clone(); // W signal histogram
    bkghist=(TH1D*)mbkgfile->Get(Hist_data1)->Clone(); // Bkg histogram

    hdata=(TH1D*)mdatafile->Get(Hist_data1)->Clone(); // Real data histogram
    
    //mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);
    sighist->Rebin(rbin); bkghist->Rebin(rbin); hdata->Rebin(rbin);

      // Scale to sfactor/pb if MC

    // if (toyMC) sfactor=400;
    sighist->Scale(sfactor); bkghist->Scale(sfactor);
 
    Double_t nbkg=0;

    if (realData) { datahist=hdata;
    } else {
      datahist=(TH1D*)sighist->Clone();
      if (addbkg) {datahist->Add(bkghist); }
    }
    if (addbkg) { 
      nbkg=bkghist->Integral(bkghist->FindBin(xmin+quanta),bkghist->FindBin(xmax-quanta));
    }

    Double_t istat=datahist->Integral(datahist->FindBin(xmin+quanta),datahist->FindBin(xmax-quanta));
    Double_t f_sig=(sighist->Integral(sighist->FindBin(xmin+quanta),sighist->FindBin(xmax-quanta)))/istat; // signal fraction
    Double_t f_bkg=nbkg/istat; // bkg fraction


      // Start RooFit session
    //  RooRealVar x("x","LP",-1.9,1.9);
      // Import binned Data
    // RooDataHist data1("mdata1","dataset with WHICVarPlus",*x,mc1);
    // RooDataHist data2("mdata2","dataset with WHICVarPlus",*x,mc2);
    // RooDataHist data3("mdata3","dataset with WHICVarPlus",*x,mc3);
  
    test=new RooDataHist("mdata","dataset with WHICVarPlus",*x,datahist);
    data_bkg=new RooDataHist("mdata4","dataset with ICVar",*x,bkghist);
    
    // Background template
    bkg = new RooHistPdf("mbkg","bkg",*x,*data_bkg);
    // Bkg fraction
    fbkg=new RooRealVar("mf_{bkg}","f_bkg fraction",f_bkg);

      // Templates 
    // RooHistPdf h1("mh1","h1",*x,data1); // left-handed template histogram
    // RooHistPdf h2("mh2","h2",*x,data2); // right-handed template histo
    // RooHistPdf h3("mh3","h3",*x,data3); // longitudinal template histo

      // Construct model PDF
    // RooAbsPdf *sig;//, *model;


    //   if (charge.at(j) == "Plus") { // plus charge PDFs
      // if (addParameter) { sig = new RooWPlusExtended("msigmodel","model",*x,*f1,*f2,*fs);
      // } else { 
    if (j==0) {
      sig = new RooWPlus("msigmodel","model",*x,*f1,*f2); //} 
    } else if (j==1) {
    //    } else if (charge.at(j) == "Minus") { // minus charge PDFs
      //  if (addParameter) { sig = new RooWMinusExtended("msigmodel","model",*x,*f1,*f2,*fs);
      //} else { 
      sig = new RooWMinus("msigmodel","model",*x,*f1,*f2);// } 
    }
   

    if (addbkg) {
      model = new RooAddPdf("mumodel","mumodel",RooArgList(*bkg,*sig),*fbkg);
    } else { model = sig; }
  
  }
  
  }

};


class Electrons{

public:
  Double_t nsig, nbkg, nqcd;
  Double_t istat, f_sig, f_bkg, f_qcd;

  RooRealVar *fbkg, *fqcd;
  // PDFs
  RooAbsPdf *sig;
  RooAddPdf *model, *imodel;
  RooHistPdf *bkg, *qcd;
  // data
  RooDataHist *test;
  RooDataHist *data_bkg, *data_qcd;

  TFile *esigfile, *ebkgfile, *eqcdfile, *edatafile;

  // TH1Ds
  // TH1D *mc1, *mc2, *mc3;
  TH1D *datahist, *hdata;
  TH1D *sighist, *bkghist, *qcdhist, *qcdtemplate;
 
  Electrons(int chrg, TString mymodel, RooRealVar *x, RooRealVar *f1, RooRealVar *f2, RooRealVar *fs)
  {

  // std::vector<TString> echarge(2);
  echarge.at(0) = poscharge;
  echarge.at(1) = negcharge;

TString fdir="/vols/cms02/georgia/WPol/";
 // input data Files
  esigfile = new TFile(fdir+"eWPol_WJets-madgraph_fall10_pile_up.root");
  ebkgfile=new TFile(fdir+"eWPol_BKG.root");
  eqcdfile=new TFile(fdir+"eWPol_QCD.root");
  edatafile = new TFile(fdir+"eWPol_EG_38.root");

  // Run both for + and - charges
  for(unsigned int j=0; j<echarge.size(); j++) {
   
       if (j!=chrg) continue; // do only + charge fit

    double isfactor;

    if (realData) { isfactor=(36./100.); }
    else {isfactor=sfactor/100.; }

    TString dir = "RECO_ElPolPlots_PostMHT50MT50/";
    // TString Hist1 = dir+"RECO_ICVarPF"+ echarge.at(j) + "_LH";
    // TString Hist2 = dir+"RECO_ICVarPF"+ echarge.at(j) + "_RH";
    // TString Hist3 = dir+"RECO_ICVarPF"+ echarge.at(j) + "_LO";
    TString Hist_data1 = dir+"RECO_ICVarPF"+ echarge.at(j);
    
    TString dirtemp = "ControlPlots_PostMHT50MT50/";
    TString Hist_temp = dirtemp+"RECO_ICVarPFAll";

    // mc1 = (TH1D*)esigfile->Get(Hist1);
    // mc2 = (TH1D*)esigfile->Get(Hist2);
    // mc3 = (TH1D*)esigfile->Get(Hist3);
    
    sighist = (TH1D*)esigfile->Get(Hist_data1)->Clone(); // W signal histogram
    bkghist = (TH1D*)ebkgfile->Get(Hist_data1)->Clone(); // Bkg histogram
    qcdhist = (TH1D*)eqcdfile->Get(Hist_data1)->Clone(); // QCD histograms
    
    // TH1D *qcdtemplate;
    if (realData) {
      qcdtemplate=(TH1D*)edatafile->Get(Hist_temp)->Clone();
    } else {
      qcdtemplate=(TH1D*)eqcdfile->Get(Hist_temp)->Clone();
    }

    hdata=(TH1D*)edatafile->Get(Hist_data1); // Real data histogram

    // mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);
    sighist->Rebin(rbin); bkghist->Rebin(rbin); qcdhist->Rebin(rbin); 
    qcdtemplate->Rebin(rbin);
    
    hdata->Rebin(rbin);

    sighist->Scale(isfactor); bkghist->Scale(isfactor); qcdhist->Scale(isfactor);
   
    //   if (toyMC) sfactor=400;
    // Double_t nsig, nbkg, nqcd;
    nsig=nbkg=nqcd=0;

    nsig=sighist->Integral(sighist->FindBin(xmin+quanta),sighist->FindBin(xmax-quanta));

    // TH1D *datahist;
    if (realData) { datahist=hdata;
    } else {
      datahist=(TH1D*)sighist->Clone();
      if (addbkg) {datahist->Add(bkghist); }
    }
    if (addbkg) { 
      nbkg=bkghist->Integral(bkghist->FindBin(xmin+quanta),bkghist->FindBin(xmax-quanta));
      if (addqcd) {
	if (!realData) datahist->Add(qcdhist);
	nqcd=qcdhist->Integral(qcdhist->FindBin(xmin+quanta),qcdhist->FindBin(xmax-quanta));
      }
    }

    istat=datahist->Integral(datahist->FindBin(xmin+quanta),datahist->FindBin(xmax-quanta));
    f_sig=nsig/istat; // signal fraction
    f_bkg=nbkg/(nsig+nbkg); // bkg fraction
    f_qcd=nqcd/istat;
   
    test=new RooDataHist(mymodel+"edata","dataset with WHICVarPlus",*x,datahist);
    data_bkg=new RooDataHist(mymodel+"edata4","dataset with ICVar",*x,bkghist);
    //  RooDataHist *data_qcd;
    if (usetemplate) {
      data_qcd=new RooDataHist(mymodel+"edata5","dataset with ICVar",*x,qcdtemplate);
    } else {
      data_qcd=new RooDataHist(mymodel+"edata5","dataset with ICVar",*x,qcdhist);
    }
    
   
    // Background template
    bkg = new RooHistPdf(mymodel+"ebkg","bkg",*x,*data_bkg);
    qcd = new RooHistPdf(mymodel+"qcd","qcd",*x,*data_qcd);
    // Bkg fraction
    fbkg=new RooRealVar(mymodel+"f_{bkg}","f_bkg fraction",f_bkg); // EWK bkg relative normalization is fixed
    fqcd=new RooRealVar(mymodel+"f_{qcd}","f_qcd fraction",0.1,0.,1.); // QCD bkg rel norm is free

    fqcd->setPlotLabel("f_{qcd}");

      // Construct model PDF
    // RooAbsPdf *sig, *imodel;

    if (j==0) {
    //    if (echarge.at(j) == "Plus") { // plus charge PDFs
      // if (addParameter) { sig = new eRooWPlusExtended("esigmodel","model",*x,*f1,*f2,*fsub);
      // } else {
      sig = new eRooWPlus(mymodel+"esigmodel","model",*x,*f1,*f2); //} 
    } else if (j==1) {
      //    } else if (echarge.at(j) == "Minus") { // minus charge PDFs
      //    if (addParameter) { sig = new eRooWMinusExtended("esigmodel","model",*x,*f1,*f2,*fsub);
      //  } else { 
      sig = new eRooWMinus(mymodel+"esigmodel","model",*x,*f1,*f2); // } 
    }
    
    if (addbkg) {
      imodel = new RooAddPdf(mymodel+"iemodel","imodel",RooArgList(*bkg,*sig),*fbkg); 
      model = new RooAddPdf(mymodel+"emodel","emodel",RooArgList(*qcd,*imodel),*fqcd);
    } else { model = sig; }

    
  }
   
  }
 
};


void roo_sim() {

  RooRealVar *fLnom, *fRnom, *f0nom;
  if (chrg==0) { 
    fLnom=new RooRealVar("fL_nom","fLnom",0.556);
    fRnom=new RooRealVar("fR_nom","fRnom",0.234);
    f0nom=new RooRealVar("f0_nom","f0nom",0.210);
  } else {
    fLnom=new RooRealVar("fL_nom","fLnom",0.523);
    fRnom=new RooRealVar("fR_nom","fRnom",0.265);
    f0nom=new RooRealVar("f0_nom","f0nom",0.212);
  }

  RooRealVar *x=new RooRealVar("x","LP",xmin,xmax);

  RooRealVar *f1=new RooRealVar("fL","fL fraction",fLnom->getVal(),0.,1.);
  RooRealVar *f2=new RooRealVar("fR","f0 fraction", fRnom->getVal(),0.,1.);
  RooFormulaVar *f3=new RooFormulaVar("f0","1-fL-fR",RooArgList(*f1,*f2));
 
  // 2nd part
  RooRealVar *f1m=new RooRealVar("fLm","fL fraction",fLnom->getVal(),0.,1.);
  RooRealVar *f2m=new RooRealVar("fRm","f0 fraction", fRnom->getVal(),0.,1.);
  RooFormulaVar *f3m=new RooFormulaVar("f0m","1-fLm-fRm",RooArgList(*f1,*f2));

  if (fitMode) {
    f1->setVal((fLnom->getVal()-fRnom->getVal())); f1->setRange(-1.,1.); 
    f1->setPlotLabel("f_{L}-f_{R}"); 
    f2->setVal(f0nom->getVal()); 
    f2->setPlotLabel("f_{0}");

    f1m->setVal((fLnom->getVal()-fRnom->getVal())); f1m->setRange(-1.,1.); 
    f1m->setPlotLabel("f_{L}-f_{R}"); 
    f2m->setVal(f0nom->getVal()); 
    f2m->setPlotLabel("f_{0}");
  } 
   
  RooRealVar *fs=new RooRealVar("fs","fs par",(fLnom->getVal()-fRnom->getVal()),-1.,1.);
  // RooRealVar *fsum=new RooRealVar("fsum","fsum par",(fLnom->getVal()+fRnom->getVal()), -1.,1.);
   
  Electrons *PDF1=new Electrons(chrg,"eplus",x,f1,f2,fs); // e+
  //Electrons *PDF1=new Electrons(1,"eminus",x,f1,f2,fs); // e-
  Muons *PDF2=new Muons(chrg,x,f1,f2,fs); // mu+
  //Muons *PDF2=new Muons(1,x,f1,f2,fs); // mu-
  
  RooCategory tagCat("tagCat","tagging Category");
  tagCat.defineType("plus"); tagCat.defineType("minus");

  RooDataHist combData("combData","combined data",*x,Index(tagCat),
		       Import("plus",*(PDF1->test)), Import("minus",*(PDF2->test)) );

    // Simultaneous PDF
  RooSimultaneous simPdf("simPdf","sim pdf",tagCat);

  simPdf.addPdf(*(PDF1->model),"plus");
  simPdf.addPdf(*(PDF2->model),"minus");

  RooFitResult *fitr=0;
  fitr = simPdf.fitTo(combData,Minos(kFALSE),Save(kTRUE));

  fitr->Print();

  // SimFit plotting
  if (makePlots) {

  setStyles();

  TCanvas *c = new TCanvas("cnvs","");
  c->Divide(2,1);

  c->cd(1);
  RooPlot * xframe1 = x->frame();
  tagCat="plus";
  combData.plotOn(xframe1,Cut("tagCat==tagCat::plus"));//,DataError(RooAbsData::Poisson));
  //  tagCat="plus";
  simPdf.plotOn(xframe1,Slice(tagCat),ProjWData(tagCat,combData)); 
  simPdf.paramOn(xframe1,Label("Electrons"));

  xframe1->Draw();

  c->cd(2);
  RooPlot * xframe2 = x->frame();
  tagCat="minus";
  combData.plotOn(xframe2,Cut("tagCat==tagCat::minus"));//,DataError(RooAbsData::Poisson));
  // tagCat="minus";
  simPdf.plotOn(xframe2,Slice(tagCat),ProjWData(tagCat,combData));
  simPdf.paramOn(xframe2,Label("Muons"));

  xframe2->Draw();

  }

}

void setStyles() {

  gROOT->SetStyle("Plain");
  gStyle->SetCanvasDefW(900);
  gStyle->SetCanvasDefH(450);
}
