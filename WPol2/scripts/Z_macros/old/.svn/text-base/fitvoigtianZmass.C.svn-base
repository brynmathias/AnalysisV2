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

// This macro fits the convolution of a gaussian and a BW to the reconstructed Z mass, in each bin of pt of the mu.

TH1::SetDefaultSumw2();


void fitvoigtianZmass(double zptcut=50, float muptcut=90, int scalevalue=0, double lumiscale=1, bool debug=false){

  TFile *f = new TFile("resfit.root","recreate");
  f->Close();

  TString scale("");
  scale+=scalevalue;


  TGraphErrors *istplus = workingmacro(debug,+1,zptcut,scalevalue,lumiscale,muptcut);
  istplus->SetMarkerStyle(20);
  istplus->GetHistogram()->SetAxisRange(82,98,"Y");

  TGraphErrors *istminus = workingmacro(debug,-1,zptcut,scalevalue,lumiscale,muptcut);
  istminus->SetMarkerStyle(20);
  istminus->SetLineColor(kRed); 
  istminus->SetMarkerColor(kRed);


  TGraphErrors *difference = new TGraphErrors();
  difference->SetName("ist_difference"); difference->SetTitle("difference plus-minus assuming no correlation");
  for (int i=0;i<istplus->GetN();i++){
    double x, plus, minus;
    istplus->GetPoint(i,x,plus);
    istminus->GetPoint(i,x,minus);
    difference->SetPoint(i,x,plus-minus);
    difference->SetPointError(i,istplus->GetErrorX(i),sqrt((istplus->GetErrorY(i))**2+(istminus->GetErrorY(i))**2));
    cout<<plus<<" "<<istplus->GetErrorY(i)<<endl;
    cout<<minus<<" "<<istminus->GetErrorY(i)<<endl;
cout<<plus-minus<<" "<<sqrt((istplus->GetErrorY(i))**2+(istminus->GetErrorY(i))**2)<<endl;
  };
  difference->GetHistogram()->SetAxisRange(-5,20,"Y");
  difference->SetMarkerStyle(7);

  TString legtitle("lumi: ");
  TLegend *leg = new TLegend(0.8,0.3,0.95,0.7,legtitle+=lumiscale);
  leg->AddEntry(istplus,(scale+",+").Data(),"lp");
  leg->AddEntry(istminus,(scale+",-").Data(),"lp");

  new TCanvas;
  istplus->Draw("AP");
  istminus->Draw("P");
  leg->Draw();

  new TCanvas;
  difference->Draw("AP");

}

TGraphErrors* workingmacro(bool debug=false, int charge=+1, double zptcut, int scalevalue, double lumiscale, Float_t ptmin){


  TFile *data = new TFile("./RecoRoutines_Z-selection_data36pb.rew8.corr1.root"); 
//  TFile *data = new TFile("./mc/zjets_win20_new.root"); 
  
  TString dir;
  if (zptcut==0) dir="MuPtScale0toinf/";
  if (zptcut==50) dir="MuPtScale50toinf/";

  TString scale("");
  scale+=scalevalue;


  TString plottitle;
  if (charge>0) plottitle="RECO_"+scale+"pcscale_recobosonMvsMpPT_hrdMp";
  else plottitle="RECO_"+scale+"pcscale_recobosonMvsMmPT_hrdMm";

  TH2F *corrplot;
  corrplot = (TH2F*)data->Get((dir+plottitle).Data());

cout<<(dir+plottitle).Data()<<endl;

  // see below for bin adjustment as a function of pt  
 double maxpt=ptmin;
 double binwidth=400-ptmin;
 double ptmax=ptmin+binwidth;

  TFile *f = new TFile("resfit.root","update");
  
  // ofstream *myfile = new ofstream("resfit.txt");
  // *myfile << "# bincenter mean errmean" << endl;

  gSystem->Load("libRooFit");
  using namespace RooFit;

  RooFitResult* r[50];
  int index=0;

  TGraphErrors *ist_dependence = new TGraphErrors();
  
  ist_dependence->SetName((plottitle+"_ist_dependence").Data());  ist_dependence->SetTitle((plottitle+"_ist_dependence").Data());

  do // in each bin of mu pt
    {

      // *myfile << ptmin+binwidth/2 << ' ';

      int bin0 = corrplot->GetYaxis()->FindBin(ptmin);
      int bin1 = corrplot->GetYaxis()->FindBin(ptmax);

      TH1D *hist = corrplot->ProjectionX("_px",bin0,bin1);
      hist->Scale(lumiscale);

      RooRealVar Zmass("Zmass","Zmass",81.2,101.2);
      RooDataHist datahist("datahist","datahist",Zmass,Import(*hist));
      RooBinning tbins(81.2,101.2);
      tbins.addUniform(20,81.2,101.2);

      if (charge>0) TString title("ZmassInMuPlusPtBin"); else TString title("ZmassInMuMinusPtBin");
      title+=(int)ptmin;
      RooPlot* frame = Zmass.frame(Title(title)) ;
      datahist.plotOn(frame,Binning(tbins),DataError(RooAbsData::SumW2)) ; 

      // Fit a Voigtian p.d.f to the data
      RooRealVar mean("mean","mean",91.2,81.2,101.2);
      RooRealVar sigma("sigma","sigma",3,0,30);
      RooRealVar width("width","width",2,0,30);
      RooVoigtian voigt("voigt","voigt",Zmass,mean,width,sigma);

      r[index] = voigt.fitTo(datahist,Save());

      voigt.plotOn(frame); 
      voigt.paramOn(frame);
      frame->Write(title.Data());
      if (charge>0) TString title2("ZmassMuPlusFitResult"); else  TString title2("ZmassMuMinusFitResult");
      title2+=(int)ptmin;
      r[index]->Write(title2.Data());

      delete frame;
      delete hist;

      const TMatrixDSym& cov = (r[index])->covarianceMatrix();

      // *myfile << mean.getVal() << ' ' << sqrt(cov[0][0]) << endl;

      ist_dependence->SetPoint(index,ptmin+binwidth/2,mean.getVal());
      ist_dependence->SetPointError(index,binwidth/2,sqrt(cov[0][0]));

 /*     if (ptmax==100) {binwidth=50; ptmin=50;}
      if (ptmax==200) {binwidth=200; ptmin=0;}
      ptmin+=binwidth; 
      ptmax+=binwidth;
*/
      index++;
    } while (ptmin<maxpt);


  if (debug) {
    for (int i=0;i<index;i++) {
      (r[i])->Print();
      cout << "covariance matrix" << endl;
      const TMatrixDSym& cov = (r[i])->covarianceMatrix();
      cov.Print();
      (r[i])->printMultiline(*myfile,0);
    }
  }

 // new TCanvas;
 //  ist_dependence->Draw("AP");
  ist_dependence->Write();

  // myfile->close();

  f->Close();
  return ist_dependence;

};

