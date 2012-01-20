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
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "RooPlot.h"


double xmin=0.; // 0
double xmax=1.3; // 1.3
double quanta=0.001;
// Fit mode [fit in terms of 0:(fL,fR) or 1:(fL-fR,f0)]
bool fitMode=1;
// Real or MC Data? If TRUE, pls beware of the integrated luminosity
bool realData=true; 
bool redice=false;
// add bkg term
bool addbkg=true;
bool addqcd=true;
bool usetemplate=true;
// account for systematics 
bool addParameter=false;

// Run Toy MC studies
bool toyMC=false;

TString fdir="/vols/cms02/georgia/WPol/";
 // input data Files
//TFile *sigfile = new TFile(fdir+"eWPol_WJets-madgraph_winter10.root");
TFile *sigfile = new TFile(fdir+"eWPol_WJets-madgraph_fall10_pile_up.root");
TFile *bkgfile=new TFile(fdir+"eWPol_BKG.root");
TFile *qcdfile=new TFile(fdir+"eWPol_QCD.root");

//TFile *datafile=new TFile(fdir+"eWPol_EG_EG_Nov4th_v1.root");
//TFile *qcddatafile=new TFile(fdir+"eWPol_EG_EG_Nov4th_v1.root");

TFile *qcddatafile=new TFile(fdir+"eWPol_EG_38.root");
TFile *datafile=new TFile(fdir+"eWPol_EG_38.root");
// TFile *qcddatafile=new TFile(fdir+"eWPol_EG_39.root");
//TFile *datafile=new TFile(fdir+"eWPol_EG_39.root");

//TFile *datafile=new TFile(fdir+"NoConv.root");

TString dir = "RECO_ElPolPlots_PostMHT50MT50/";
TString dirtemp="ControlPlots_PostMHT50MT50/";

//TFile *datafile = new TFile("WPolFiles/ECALTransparencyCorrectedData_v3/eWPol_EG_transp_corr.root");
bool makePlots = true;

// Binning [check that the USer defined functions involve the same binning!!!]
Int_t rbin=10;
// Integrated luminosity
Double_t sfactor=(36./100.);

void roo_efitWH()
{
  TString poscharge = "Plus";
  TString negcharge = "Minus";

  std::vector<TString> charge(2);
  charge.at(0) = poscharge;
  charge.at(1) = negcharge;

   TString iposcharge = "pl";
  TString inegcharge = "mi";

  std::vector<TString> icharge(2);
  icharge.at(0) = iposcharge;
  icharge.at(1) = inegcharge;


  TString canvas_name_plus = "electron_MC_WHelicityFramePlots_PlusICVar";
  TCanvas *c0 = new TCanvas(canvas_name_plus,"",450,400);
  TString canvas_name_minus = "electron_MC_WHelicityFramePlots_MinusICVar";
  TCanvas *c1 = new TCanvas(canvas_name_minus,"",450,400);
 
  TCanvas *c00=new TCanvas("c00","",500,500);
  TCanvas *c11=new TCanvas("c11","",500,500);

  // Run both for + and - charges
  for(unsigned int j=0; j<charge.size(); j++) {
   
    // if (j==1) continue;

    if (toyMC && j==0) continue; // do only + charge fit
    if (realData) { sfactor=(36./100.); }

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

    //    TString dir = "RECO_ElPolPlots_PostMHT50MT50/";

    TString Hist1 = dir+"RECO_ICVarPF"+ charge.at(j) + "_LH";
    TString Hist2 = dir+"RECO_ICVarPF"+ charge.at(j) + "_RH";
    TString Hist3 = dir+"RECO_ICVarPF"+ charge.at(j) + "_LO";
    TString Hist_data1 = dir+"RECO_ICVarPF"+ charge.at(j);
    
    // TString Hist_data="heLPraw38all"+icharge.at(j);
    TString Hist_data="heLPraw39allnon"+icharge.at(j);//+"39";

    //    TString dirtemp="ControlPlots_PostMHT50MT50/";
 
    TString Hist_temp = dirtemp+"RECO_ICVarPFAll";

    TH1D *mc1 = (TH1D*)sigfile->Get(Hist1);
    TH1D *mc2 = (TH1D*)sigfile->Get(Hist2);
    TH1D *mc3 = (TH1D*)sigfile->Get(Hist3);
    
    TH1D *sighist = (TH1D*)sigfile->Get(Hist_data1); // W signal histogram
    TH1D *bkghist=(TH1D*)bkgfile->Get(Hist_data1); // Bkg histogram
    TH1D *qcdhist=(TH1D*)qcdfile->Get(Hist_data1); // QCD histogram

    TH1D *qcdtemplate;
    if (realData) {
      qcdtemplate=(TH1D*)qcddatafile->Get(Hist_temp)->Clone();
    } else {
      qcdtemplate=(TH1D*)qcddatafile->Get(Hist_temp)->Clone();
    }

    TH1D *hdata=(TH1D*)datafile->Get(Hist_data1); // Real data histogram

    mc1->Rebin(rbin); mc2->Rebin(rbin); mc3->Rebin(rbin);
    sighist->Rebin(rbin); bkghist->Rebin(rbin); qcdhist->Rebin(rbin); 
    qcdtemplate->Rebin(rbin);
    
    hdata->Rebin(rbin);

      // Scale to sfactor/pb if MC

    //if (toyMC) sfactor=(200./100.);
    sighist->Scale(sfactor); bkghist->Scale(sfactor); qcdhist->Scale(sfactor);
  
    Double_t nsig, nbkg, nqcd;
    nsig=nbkg=nqcd=0;

    nsig=sighist->Integral(sighist->FindBin(xmin+quanta),sighist->FindBin(xmax-quanta));

    TH1D *datahist;
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

    Double_t istat=datahist->Integral(datahist->FindBin(xmin+quanta),datahist->FindBin(xmax-quanta));
    Double_t f_sig=nsig/istat; // signal fraction
    Double_t f_bkg=nbkg/(nsig+nbkg); // bkg fraction
    Double_t f_qcd=nqcd/istat;


      // Start RooFit session
    RooRealVar x("x","LP",xmin,xmax);
      // Import binned Data
    RooDataHist data1("data1","dataset with WHICVarPlus",x,mc1);
    RooDataHist data2("data2","dataset with WHICVarPlus",x,mc2);
    RooDataHist data3("data3","dataset with WHICVarPlus",x,mc3);
  
    RooDataHist test("data","dataset with WHICVarPlus",x,datahist);
       // smear MC data....
    // RooDataSet *rtest;
    // if (!realData && redice) {
    //   RooHistPdf *datapdf = new RooHistPdf("datapdf","",x,test);
    //   rtest = datapdf->generate(x,istat);
    // }

    RooDataHist data_bkg("data4","dataset with ICVar",x,bkghist);
    RooDataHist *data_qcd;
    if (usetemplate) {
      data_qcd=new RooDataHist("data5","dataset with ICVar",x,qcdtemplate);
    } else {
      data_qcd=new RooDataHist("data5","dataset with ICVar",x,qcdhist);
    }
    // Relative fractions - allow them to float to negative values too if needs be
    //   if (fitMode==0) {
    RooRealVar f1("fL","fL fraction",fLnom->getVal(),-10.,10.);
    RooRealVar f2("fR","fR fraction", fRnom->getVal(),-10.,10.);
    RooFormulaVar f3("f0","1-fL-fR",RooArgList(f1,f2));
    if (fitMode) {
      f1.setVal((fLnom->getVal()-fRnom->getVal())); f1.setRange(-1.,1.); 
      f1.setPlotLabel("f_{L}-f_{R}"); 
      f2.setVal(f0nom->getVal()); f2.setRange(-1.,1.); 
      f2.setPlotLabel("f_{0}");
    } 
    // } else {
    //   RooRealVar f1("fL","fL fraction",(fLnom->getVal()-fRnom->getVal()),-1.,1.);
    //   RooRealVar f2("fR","fR fraction", (fLnom->getVal()+fRnom->getVal()),-1.,1.);
    //   RooFormulaVar f3("f0","1-fL-fR",RooArgList(f1,f2));
    // }
    RooRealVar fsub("fsub","fsub par",(fLnom->getVal()-fRnom->getVal()),-1.,1.);
    RooRealVar fsum("fsum","fsum par",(fLnom->getVal()+fRnom->getVal()), -1.,1.);
    
    // Background template
    RooHistPdf *bkg = new RooHistPdf("bkg","bkg",x,data_bkg);
    RooHistPdf *qcd = new RooHistPdf("qcd","qcd",x,*data_qcd);
    // Bkg fraction
    RooRealVar fbkg("f_{bkg}","f_bkg fraction",f_bkg); // EWK bkg relative normalization is fixed
  
    if (toyMC) { f_qcd=0.1; }
    RooRealVar fqcd("f_{qcd}","f_qcd fraction",0.1,0.,1.); // QCD bkg rel norm is free
     
    //RooRealVar fqcd("Nqcd","f_qcd fraction",260.,0.,1000.); // QCD bkg rel norm is free
    // RooRealVar fw("N_{w}","f_w events",nsig,0.,100000.);

      // Templates 
    RooHistPdf h1("h1","h1",x,data1); // left-handed template histogram
    RooHistPdf h2("h2","h2",x,data2); // right-handed template histo
    RooHistPdf h3("h3","h3",x,data3); // longitudinal template histo

      // Construct model PDF
    RooAbsPdf *sig, *model, *imodel;

    if (charge.at(j) == "Plus") { // plus charge PDFs
      //  if (addParameter) { sig = new eRooWPlusExtended("sigmodel","model",x,f1,f2,fsub);
      //} else { 
      sig = new eRooWPlus("sigmodel","model",x,f1,f2);
    } else if (charge.at(j) == "Minus") { // minus charge PDFs
      //  if (addParameter) { sig = new eRooWMinusExtended("sigmodel","model",x,f1,f2,fsub);
      // } else { 
      sig = new eRooWMinus("sigmodel","model",x,f1,f2); 
      //} 
    }
    
    if (addbkg) {
      imodel = new RooAddPdf("imodel","imodel",RooArgList(*bkg,*sig),fbkg); 
      // model = new RooAddPdf("model","model",RooArgList(*qcd,*imodel),RooArgList(fqcd,fw));
      model = new RooAddPdf("model","model",RooArgList(*qcd,*imodel),fqcd);
    } else { model = sig; }
    
      // Construct likelihood ( + penalty term)
  
    RooNLLVar nll("nll","nll",*model,test);//,Extended(kTRUE));

    RooRealVar pen("pen","penalty term",(0.5*1./(100.*100.)));
    RooFormulaVar nllPen("nllPen","nll+pen*(Nqcd-269.)^2",RooArgList(nll,pen,fqcd));
    
      // Fitting
    RooMinuit *m;
    if (!addParameter) { m = new RooMinuit(nll); }
    else {  m = new RooMinuit(nllPen);}

    if (!toyMC) {
      m->migrad(); m->hesse();
    }
    RooFitResult *res1 = m->save();
  
   
    if(makePlots) {
   
      // Temp PDF for plotting purposes
      //  RooAddPdf temp("temp","component 1",RooArgList(*h1,*h2,*h3),RooArgList(*f1,*f2_p)) ;
      RooFormulaVar fL("fL","(1.+f1-f2)/2.",RooArgList(f1,f2));
      RooFormulaVar fR("fR","(1.-f1-f2)/2.",RooArgList(f1,f2));

      // Temp PDF for plotting purposes
      RooAddPdf temp("temp","component 1",RooArgList(h1,h2,h3),RooArgList(fL,fR)) ;
      RooAddPdf itemp("itempo","imodel",RooArgList(*bkg,temp),fbkg);
      RooAddPdf ftemp("ftempo","fmodel",RooArgList(*qcd,itemp),fqcd);

      // Plotting
      gROOT->SetStyle("Plain");  
      gStyle->SetOptFit(111);
      gStyle->SetOptTitle(0);
      gStyle->SetOptStat(0);      //gStyle->SetCanvasDefH(600); //Height of canvas
      //gStyle->SetCanvasDefW(600); //Width of canvas   
    
      if(charge.at(j) == "Plus") { c0->cd();
	//	c0->Divide(2,1);c0->cd(1);
      }
      if(charge.at(j) == "Minus") { c1->cd();
	//c1->Divide(2,1);c1->cd(1);
      }
      
      datahist->Draw("E1"); //return ;
      datahist->GetXaxis()->SetRangeUser(xmin,(xmax-quanta));
      datahist->GetYaxis()->SetRangeUser(0.,550.);
      datahist->SetMarkerStyle(20);
      datahist->GetYaxis()->SetTitle("events / 36 pb^{-1}");
      if (charge.at(j) == "Plus") {
	datahist->GetXaxis()->SetTitle("LP (e^{+})");
      } else {
	datahist->GetXaxis()->SetTitle("LP (e^{-})");
      }

      RooPlot* frame = x.frame();
      //   if (realData || (!redice)) {
      test.plotOn(frame,Name("data")); 
      model->plotOn(frame,Name("model")); 
      //    model->paramOn(frame, Format("NELU", AutoPrecision(2)), Layout(0.1,0.5,0.9));
      // ftemp.plotOn(frame, Components(h1),LineColor(kRed),LineStyle(kDashed));
      // ftemp.plotOn(frame, Components(h2),LineColor(kGreen),LineStyle(kDashed));
      // ftemp.plotOn(frame, Components(h3),LineColor(kBlack),LineStyle(kDashed));
      if (addbkg) {
	//	model->plotOn(frame,Components(*bkg),FillColor(5),DrawOption("F"));
	if (toyMC) {
	  //  model->plotOn(frame,Components(*qcd),FillColor(2),DrawOption("F"),FillStyle(3035));
	} else {
	  // model->plotOn(frame,Components(*qcd),VisualizeError(*res1,RooArgSet(fL,fR,fqcd)),FillColor(2),FillStyle(3035));
	} 
      }
      frame->GetXaxis()->SetTitle("LP Variable");
      // frame->Draw("SAME");

  hdata->GetYaxis()->SetTitle("Events / 0.1");
  if(charge.at(j) == "Plus") {  hdata->GetXaxis()->SetTitle("#it{L_{P}}(#it{e}^{+})");}
  if(charge.at(j) == "Minus") {hdata->GetXaxis()->SetTitle("#it{L_{P}}(#it{e}^{-})");}
      hdata->GetXaxis()->SetTitleSize(0.06);
      hdata->GetXaxis()->SetTitleOffset(1.);
      hdata->GetYaxis()->SetTitleSize(0.06);
      hdata->GetYaxis()->SetTitleOffset(1.2);
      hdata->GetXaxis()->SetLabelSize(0.055);
      hdata->GetYaxis()->SetLabelSize(0.055);
      hdata->GetXaxis()->SetRangeUser(0.0,1.29);
      hdata->GetYaxis()->SetRangeUser(0.0,450);
      hdata->SetMarkerStyle(20);
      //  frame->Draw();


      //  mc1->Draw("same");
      // Goodness-of-fit
      Double_t chi2= frame->chiSquare("model","data",3);
      Double_t nllmin=res1->minNll();
      cout << "" << endl;
      cout << "Printing out the goodness-of-fit measure:" << endl;
      cout << "chi2 = " << chi2 << "\t" << "min NLL = " << nllmin << endl;
      res1->Print();

      //   TCanvas* testt  = new TCanvas ("testt","hj");
      cout <<"intetral: "<<   hdata->Integral()<<endl;
      hdata->GetXaxis()->SetRangeUser(0.0,1.29);
      cout <<   hdata->Integral()<<endl;
      qcdtemplate->GetXaxis()->SetRangeUser(0.0,1.29);
      qcdtemplate->SetLineColor(kRed);

      hdata->Draw("");
      //  frame->Draw("same");
      mc1->GetXaxis()->SetRangeUser(0.0,1.29);
      float f_l_a =  mc1->Integral();
      mc2->GetXaxis()->SetRangeUser(0.0,1.29);
      float f_r_a =  mc2->Integral();
      mc3->GetXaxis()->SetRangeUser(0.0,1.29);
      float f_0_a =  mc3->Integral();

      float allData =  hdata->Integral();
      float EWKBkg = (allData-fqcd.getVal())*(f_bkg);
      float QCDBkg = allData*(fqcd.getVal());
      float WData = allData*(1-f_bkg-fqcd.getVal());

      float f_l = 0.5*(1-f2.getVal()+f1.getVal());
      float f_r = 0.5*(1-f2.getVal()-f1.getVal());
      float f_0 = f2.getVal();
      cout << "f_l: "<< f_l<< ",f_r: "<< f_r<< ", f_0: "<< f_0<< " 1= "<< f_l+f_r+f_0<< endl;
      cout << f_bkg << endl;
      float allW = f_l*f_l_a+f_r*f_r_a+f_0*f_0_a;


      //hdata->Draw("");
      //    bkghist->GetXaxis()->SetRangeUser(0.0,1.3);
      bkghist->Scale(EWKBkg/bkghist->Integral());
    
      bkghist->SetLineColor(kYellow);
      bkghist->SetFillColor(kYellow);


      qcdtemplate->Scale(QCDBkg/qcdtemplate->Integral());
      qcdtemplate->Draw("samehist");
      //   qcdtemplate->SetLineColor();
      qcdtemplate->SetFillColor(2);

      bkghist->Draw("samehist");

      mc1->Scale(f_l*WData/allW);
      mc2->Scale(f_r*WData/allW);
      mc3->Scale(f_0*WData/allW);
      mc1->SetLineColor(kRed);
      mc2->SetLineColor(kGreen);
      mc3->SetLineColor(kBlue);
      mc1->SetLineWidth(3);
      mc2->SetLineWidth(3);
      mc3->SetLineWidth(3);
      mc1->SetLineStyle(2);
      mc2->SetLineStyle(3);
      mc3->SetLineStyle(4);
      mc1->Draw("samehist");
      mc2->Draw("samehist");
      mc3->Draw("samehist");

      TH1D* allHists = (TH1D*)mc1->Clone();
      allHists->Add(mc2,1);
      allHists->Add(mc3,1);
      allHists->Add(bkghist,1);
      allHists->Add(qcdtemplate,1);
      allHists->SetLineWidth(3);
      //   frame->SetOptFit(0);
      //allHists->Draw("same");
        frame->Draw("same");
  TLegend* aleg = new TLegend(0.2040359,0.5294118,0.4035874,0.9144385,"");
      //aleg->SetNColumns(2);
      aleg->SetFillColor(0);
      aleg->SetLineColor(0);
      aleg->AddEntry(mc1,"f_{L}","lf");
      aleg->AddEntry(mc2,"f_{R}","lf");
      aleg->AddEntry(mc3,"f_{0}","lf");
      aleg->AddEntry(qcdtemplate,"QCD","lf");
      aleg->AddEntry(bkghist,"EWK","lf");
      TH1* dummyhist = new TH1F("", "", 1, 0, 1);
      dummyhist->SetLineColor(kBlue);
      dummyhist->SetLineWidth(3);
      aleg->AddEntry(dummyhist, "fit result", "lf");
      aleg->AddEntry(hdata,"data","P");

      aleg->Draw("same");

      //TLatex* preliminary = new TLatex(0.35,415,"CMS preliminary: #it{L} = 36pb^{-1}@ 7 TeV");
      //TLatex* text;
  //if(charge.at(j) == "Minus") text = new TLatex(0.35,365,"#splitline{f_{L}-f_{R}=0.187#pm0.069(stat.)#pm0.066(syst.)}{f_{0}=0.130#pm0.200(stat.)#pm0.174(syst.)}");
  //if(charge.at(j) == "Plus")text = new TLatex(0.35,365,"#splitline{f_{L}-f_{R}=0.277#pm0.060(stat.)#pm0.050(syst.)}{f_{0}=0.240#pm0.190(stat.)#pm0.090(syst.)}");

      //preliminary->SetTextSize(0.043);
      //  preliminary->Draw("same");
      
      //text->SetTextSize(0.043);
      //  text->Draw("same");

      TLatex * text = new TLatex(0.7523023,380.0747,"#splitline{CMS,  #sqrt{s} = 7 TeV}{L_{ int} = 36 pb^{-1}}");
      text->SetTextSize(0.043);
      text->SetLineWidth(2);
      text->Draw("same");

      // Goodness-of-fit
      Double_t chi2= frame->chiSquare("model","data",3);
      Double_t nllmin=res1->minNll();
      cout << "" << endl;
      cout << "Printing out the goodness-of-fit measure:" << endl;
      cout << "chi2 = " << chi2 << "\t" << "min NLL = " << nllmin << endl;
      res1->Print();

      

	// Draw Minuit contours
      if (!toyMC) {

	if(charge.at(j) == "Plus") { c00->cd(); 
	} else { c11->cd();  }
	
	//	RooPlot *rcontour=m->contour(f1,f2,1,2);
	//	rcontour->Draw();
	RooPlot *rcontour=new RooPlot(f1,f2);
	//	res1->plotOn(rcontour,f1,f2,"ME123VHB");
	//	rcontour->Draw();

	if (fitMode) {
	  //	rcontour->GetXaxis()->SetTitle("f_{0}");
	  rcontour->GetXaxis()->SetTitle("f_{L}-f_{R}");
	  rcontour->GetYaxis()->SetTitle("f_{0}");
	} else {
	  rcontour->GetXaxis()->SetTitle("f_{L}");
	  rcontour->GetYaxis()->SetTitle("f_{R}");
	}

	if(charge.at(j) == "Plus") { c00->SaveAs("contourplus.C"); 
	} else { c11->SaveAs("contourminus.C");  }

      } // end if !toyMC
   
    } // end if makePlots
    

    const TMatrixDSym& cor = res1->correlationMatrix();
    const TMatrixDSym& cov = res1->covarianceMatrix();
    
    //Print correlation, covariance matrix
    cout << "correlation matrix" << endl; cor.Print();
    cout << "covariance matrix" << endl; cov.Print();
  
    cout << f1 << endl; cout << f2 << endl;
    if (!fitMode && !toyMC) {
      cout << "f0 = " << f3 << " +/- " << f3.getPropagatedError(*res1) << endl;
    }
  }

  if(makePlots) {
    c0->Print(canvas_name_plus+".pdf");
    c1->Print(canvas_name_minus+".pdf");
  }

  //return;

  if (toyMC) {

    // MC STudies
  Int_t nevt=istat;
  Int_t nEXP=300;

  RooMCStudy mgr(*model,x,FitModel(*model));//,Extended());//,Silence(),Binned());
  mgr.generateAndFit(nEXP,nevt,kTRUE);
  
  TCanvas *cp0 = new TCanvas("c0","",1200,800);
  cp0->Divide(2,1);
  cp0->cd(1);
  RooPlot *p1=mgr.plotParam(f1); p1->Draw(); 
  if (fitMode) p1->SetTitle(";f_{L}-f_{R};number of toys");
  cp0->cd(2);
  RooPlot *p2 = mgr.plotError(f1); p2->Draw();
  if (fitMode) p2->SetTitle(";#delta (f_{L}-f_{R});number of toys");
  //  cp0->cd(3);
  // f1 pull
  
  TCanvas *pcp0 = new TCanvas("pc0","",400,400);
  RooPlot* m1pframe = mgr.plotPull(f1,-3.,3.,30,kTRUE);
  m1pframe->Draw();
  if (fitMode) {
    m1pframe->SetTitle(";f_{L}-f_{R};number of toys");
  }
 
  TCanvas *dd1=new TCanvas("dd1","",400,400);
  TH2* hh1 = f1.createHistogram("f_{L}-f_{R} vs QCD",fqcd) ; 
  mgr.fitParDataSet().fillHistogram(hh1,RooArgList(f1,fqcd)) ; 
  hh1->Draw("BOX") ;

  TCanvas *cp02 = new TCanvas("c1","",1200,400);
  cp02->Divide(2,1);
  cp02->cd(1);
  RooPlot *p3=mgr.plotParam(f2); p3->Draw();
  if (fitMode) p3->SetTitle(";f_{0};number of toys");
  cp02->cd(2);
  RooPlot *p4=mgr.plotError(f2); p4->Draw();
  if (fitMode) p4->SetTitle(";#delta f_{0}; number of toys");
 
  TCanvas *pcp02 = new TCanvas("pc02","",400,400);
 //  cp02->cd(3);
  // f2 pull
  RooPlot* m2pframe = mgr.plotPull(f2,-3.,3.,30,kTRUE);
  m2pframe->Draw();
  if (fitMode) {
    m2pframe->SetTitle(";f_{0};number of toys");
  }

  TCanvas *dd2=new TCanvas("dd2","",400,400);
  TH2* hh2 = f2.createHistogram("f_{0} vs QCD",fqcd) ; 
  mgr.fitParDataSet().fillHistogram(hh2,RooArgList(f2,fqcd)) ; 
  hh2->Draw("BOX") ;

  // fqcd
  TCanvas *cp03 = new TCanvas("c3","",1200,400);
  cp03->Divide(3,1);
  cp03->cd(1);
  RooPlot *p5=mgr.plotParam(fqcd); p5->Draw();
  p5->SetTitle(";f_{qcd};number of toys");
  cp03->cd(2);
  RooPlot *p6=mgr.plotError(fqcd); p6->Draw();
  p6->SetTitle(";#delta f_{qcd}; number of toys");
  cp03->cd(3);
  // f2 pull
  RooPlot* m3pframe = mgr.plotPull(fqcd,-3.,3.,30,kTRUE);
  m3pframe->Draw();
  //if (fitMode) {
  m3pframe->SetTitle(";f_{qcd};number of toys");
 


  TCanvas *cnll = new TCanvas("cnll","");
  RooPlot* nllframe = mgr.plotNLL();
  nllframe->Draw();


  }

  return;
}
