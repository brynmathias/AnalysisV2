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

//TH1::SetDefaultSumw2();


void massdifference(double zptcut=0, float muptcut=75, double lumiscale=0.36, bool debug=false){

setTDRStyle();

  TFile *f = new TFile("resfit.root","recreate");

 double x, plus, minus;
   TGraph *dataplus;
   TGraph *dataminus;
   double dp, dm, errd, errp, errm;
  dataplus=workingmacrosinglebin(debug,+1,zptcut,0,1,f,muptcut,1);
  dataminus=workingmacrosinglebin(debug,-1,zptcut,0,1,f,muptcut,1);
  dataplus->GetPoint(0,x,dp);
  dataminus->GetPoint(0,x,dm);
  errd=sqrt((dataplus->GetErrorY(0))**2+(dataminus->GetErrorY(0))**2);
  errp=dataplus->GetErrorY(0);
  errm=dataminus->GetErrorY(0);


  TGraphErrors *difference = new TGraphErrors();
  difference->SetName("ist_difference");
  // difference->SetTitle("Difference between fitted Z mass values");
  TGraphErrors *plusevolution = new TGraphErrors();
  plusevolution->SetName("evo_plus");
  plusevolution->SetTitle("Fitted Z mass in leading #mu^{+} events");
  TGraphErrors *minusevolution = new TGraphErrors();
  minusevolution->SetName("evo_minus");
  minusevolution->SetTitle("Fitted Z mass in leading #mu^{-} events");
  TGraphErrors *sign = new TGraphErrors();
  sign->SetName("significance");
  // sign->SetTitle("Mass difference / #sigma (significance)");


  int scalevalue=-3;  

  // for (int k=0;k<8;k++){
  for (int k=0;k<5;k++){

    scalevalue++;

 TString scale("");  
    if (scalevalue<0) {scale+="m"; scale+=(-scalevalue);}
    else scale+=scalevalue;


    TGraphErrors *istplus = workingmacrosinglebin(debug,+1,zptcut,scalevalue,lumiscale,f,muptcut,0);
    istplus->SetMarkerStyle(20);
    istplus->GetHistogram()->SetAxisRange(82,98,"Y");

    TGraphErrors *istminus = workingmacrosinglebin(debug,-1,zptcut,scalevalue,lumiscale,f,muptcut,0);
    istminus->SetMarkerStyle(20);
    istminus->SetLineColor(kRed); 
    istminus->SetMarkerColor(kRed);
  
   
    istplus->GetPoint(0,x,plus);
    istminus->GetPoint(0,x,minus);
    difference->SetPoint(k,scalevalue,plus-minus);
    // difference->SetPointError(k,0,sqrt((istplus->GetErrorY(0))**2+(istminus->GetErrorY(0))**2));
    difference->SetPointError(k,0,errd);
    plusevolution->SetPoint(k,scalevalue,plus);
    plusevolution->SetPointError(k,0,istplus->GetErrorY(0));
    minusevolution->SetPoint(k,scalevalue,minus);
    minusevolution->SetPointError(k,0,istminus->GetErrorY(0));
    sign->SetPoint(k,scalevalue,(plus-minus)/sqrt((istplus->GetErrorY(0))**2+(istminus->GetErrorY(0))**2));

    TString legtitle("lumi: ");
    TLegend *leg = new TLegend(0.8,0.3,0.95,0.7,legtitle+=lumiscale);
    leg->AddEntry(istplus,(scale+",+").Data(),"lp");
    leg->AddEntry(istminus,(scale+",-").Data(),"lp");
    
    // new TCanvas;
    // istplus->Draw("AP");
    // istminus->Draw("P");
    // leg->Draw();
    
    delete istplus; delete istminus; delete leg;

  }

  const int n=20;

   TGraph *grmin1 = new TGraph(n);
   TGraph *grmax1 = new TGraph(n);
   TGraph *gr1    = new TGraph(n);
   TGraph *grshade1 = new TGraph(2*n);
   grshade1->SetFillStyle(3013);
   grshade1->SetFillColor(16);
   gr1->SetLineWidth(4);
   gr1->SetMarkerColor(4);
   gr1->SetMarkerStyle(21);


  TCanvas *c1 = new TCanvas;
  // c1->Divide(2);
  // c1->cd(1);
  difference->SetLineWidth(3);
  difference->SetLineColor(kBlue);
  difference->SetMarkerStyle(20);
  difference->SetMarkerSize(0.7);
  difference->SetMarkerColor(kBlue);
  difference->GetHistogram()->SetAxisRange(-2,2,"Y");
  TAxis *xaxis = difference->GetXaxis();
  TAxis *yaxis = difference->GetYaxis();
  xaxis->SetTitle("#mu p_{T} correction / 100 GeV (%)");
  yaxis->SetTitle("Z_{lead+}-Z_{lead-} mass (GeV)");
  difference->Draw("AP");
  shadedbanddraw(dp-dm,errd,gr1,grmin1,grmax1,grshade1);



   TGraph *grmin2 = new TGraph(n);
   TGraph *grmax2 = new TGraph(n);
   TGraph *gr2    = new TGraph(n);
   TGraph *grshade2 = new TGraph(2*n);
   grshade2->SetFillStyle(3013);
   grshade2->SetFillColor(16);
   gr2->SetLineWidth(4);
   gr2->SetMarkerColor(4);
   gr2->SetMarkerStyle(21);

   TCanvas *c1b = new TCanvas();
  // c1->cd(2);
  sign->SetLineWidth(3);
  sign->SetLineColor(kBlue);
  sign->SetMarkerStyle(21);
  sign->SetMarkerSize(1.3);
  sign->SetMarkerColor(kBlue);
  sign->GetHistogram()->SetAxisRange(-4,4,"Y");
  xaxis = sign->GetXaxis();
  yaxis = sign->GetYaxis();
  xaxis->SetTitle("#mu p_{T} correction / 100 GeV (%)");
  yaxis->SetTitle("Z_{lead+}-Z_{lead-} mass / #sigma (significance)");
  sign->Draw("AP");
  shadedbanddraw((dp-dm)/errd,0.0,gr2,grmin2,grmax2,grshade2);


  c1->Update();
  c1b->Update();



  TCanvas *c2 = new TCanvas();
  
  plusevolution->SetLineWidth(3);
  plusevolution->SetLineColor(kRed);
  plusevolution->SetMarkerStyle(20);
  plusevolution->SetMarkerSize(0.7);
  plusevolution->SetMarkerColor(kRed);
  plusevolution->GetHistogram()->SetAxisRange(87,97,"Y");
  xaxis = plusevolution->GetXaxis();
  yaxis = plusevolution->GetYaxis();
  xaxis->SetTitle("#mu p_{T} correction (%)");
  yaxis->SetTitle("Z_{lead+} mass (GeV)");

  minusevolution->SetLineWidth(3);
  minusevolution->SetLineColor(kBlue);
  minusevolution->SetMarkerStyle(20);
  minusevolution->SetMarkerSize(0.7);
  minusevolution->SetMarkerColor(kBlue);
  minusevolution->GetHistogram()->SetAxisRange(87,97,"Y");
  xaxis = minusevolution->GetXaxis();
  yaxis = minusevolution->GetYaxis();
  xaxis->SetTitle("#mu p_{T} correction (%)");
  yaxis->SetTitle("Z_{lead-} mass (GeV)");

  
  TF1 *zmass = new TF1("zmass","91.18",-10,10);
  zmass->SetLineColor(kGreen);
  zmass->SetLineWidth(3);
 

   TGraph *grmin3 = new TGraph(n);
   TGraph *grmax3 = new TGraph(n);
   TGraph *gr3    = new TGraph(n);
   TGraph *grshade3 = new TGraph(2*n);
   grshade3->SetFillStyle(3013);
   grshade3->SetFillColor(16);
   gr3->SetLineWidth(4);
   gr3->SetMarkerColor(4);
   gr3->SetMarkerStyle(21);

  c2->Divide(2,1);
  c2->cd(1);
  plusevolution->Draw("AP");
 zmass->Draw("same");

  shadedbanddraw(dp,errp,gr3,grmin3,grmax3,grshade3);



   TGraph *grmin4 = new TGraph(n);
   TGraph *grmax4 = new TGraph(n);
   TGraph *gr4    = new TGraph(n);
   TGraph *grshade4 = new TGraph(2*n);
   grshade4->SetFillStyle(3013);
   grshade4->SetFillColor(16);
   gr4->SetLineWidth(4);
   gr4->SetMarkerColor(4);
   gr4->SetMarkerStyle(21);

 c2->cd(2);
  minusevolution->Draw("AP");
  zmass->Draw("same");
  shadedbanddraw(dm,errm,gr4,grmin4,grmax4,grshade4);


  c2->Update();


  difference->Write();
  plusevolution->Write();
  minusevolution->Write();
  f->Save();
  f->Close();

}

void shadedbanddraw(double center, double error, TGraph *gr,TGraph *grmin, TGraph *grmax, TGraph *grshade){
  const int n = 20;
 Double_t asc[n], y[n],ymin[n], ymax[n];
   Int_t i;
   for (i=0;i<n;i++) {
  asc[i] = -10.0+i;
     ymax[i] = center+error;
     ymin[i] = center-error;
     y[i] = center;
	}

 for (i=0;i<n;i++) {
      gr->SetPoint(i,asc[i],y[i]);
   grmin->SetPoint(i,asc[i],ymin[i]);
   grmax->SetPoint(i,asc[i],ymax[i]);
   grshade->SetPoint(i,asc[i],ymax[i]);
      grshade->SetPoint(n+i,asc[n-i-1],ymin[n-i-1]);

      }

grshade->Draw("f");
grmin->Draw("l");
grmax->Draw("l");
gr->Draw("C");

}

TGraphErrors* workingmacrosinglebin(bool debug=false, int charge=+1, double zptcut, int scalevalue, double lumiscale, TFile *f, Float_t ptmin, bool realdata){


TFile *data;
if (realdata) data = new TFile("./RecoRoutines_Z-selection_data36pb.root","read");
  else data = new TFile("./RecoRoutines_Z-selection_zjets_madgraph_skim100pb.root","read"); 
  
  f->cd();

  TString dir;
  if (zptcut==0) dir="MuPtScale0toinf/";
  if (zptcut==50) dir="MuPtScale50toinf/";

  TString scale("");  
    if (scalevalue<0) {scale+="m"; scale+=(-scalevalue);}
    else scale+=scalevalue;


  TString plottitle;
  if (charge>0) plottitle="RECO_"+scale+"pcscale_recobosonMvsMpPT_hrdMp";
  else plottitle="RECO_"+scale+"pcscale_recobosonMvsMmPT_hrdMm";

  TH2F *corrplot;
  corrplot = (TH2F*)data->Get((dir+plottitle).Data());

  cout<<(dir+plottitle).Data()<<endl;

  // see below for bin adjustment as a function of pt  
  double binwidth=400-ptmin;
  double ptmax=ptmin+binwidth;

  // ofstream *myfile = new ofstream("resfit.txt");
  // *myfile << "# bincenter mean errmean" << endl;

  gSystem->Load("libRooFit");
  using namespace RooFit;

  RooFitResult* r;


  TGraphErrors *ist_dependence = new TGraphErrors();
  
  ist_dependence->SetName((plottitle+"_ist_dependence").Data());  ist_dependence->SetTitle((plottitle+"_ist_dependence").Data());

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
if (realdata) title+="Data";
  title+=(int)ptmin;
  title+=scale;
  RooPlot* frame = Zmass.frame(Title(title)) ;
  // datahist.plotOn(frame,Binning(tbins),DataError(RooAbsData::SumW2)) ; 
  datahist.plotOn(frame,Binning(tbins)) ; 

  // Fit a Voigtian p.d.f to the data
  RooRealVar mean("mean","mean",91.2,81.2,101.2);
  RooRealVar sigma("sigma","sigma",3,0,30);
  RooRealVar width("width","width",2.49,2.49,2.49);
  RooVoigtian voigt("voigt","voigt",Zmass,mean,width,sigma);

  r = voigt.fitTo(datahist,Save());

  voigt.plotOn(frame); 
  voigt.paramOn(frame);
  frame->Write(title.Data());
  if (charge>0) TString title2("ZmassMuPlusFitResult"); else  TString title2("ZmassMuMinusFitResult");
 if (realdata) title2+="Data";
  title2+=(int)ptmin;
  title2+=scale;
  r->Write(title2.Data());

  delete frame;
  delete hist;

  const TMatrixDSym& cov = (r)->covarianceMatrix();

  // *myfile << mean.getVal() << ' ' << sqrt(cov[0][0]) << endl;

  ist_dependence->SetPoint(0,ptmin+binwidth/2,mean.getVal());
  ist_dependence->SetPointError(0,binwidth/2,sqrt(cov[0][0]));
  

  // if (debug) {
  //   for (int i=0;i<index;i++) {
  //     (r[i])->Print();
  //     cout << "covariance matrix" << endl;
  //     const TMatrixDSym& cov = (r[i])->covarianceMatrix();
  //     cov.Print();
  //     (r[i])->printMultiline(*myfile,0);
  //   }
  // }

  // new TCanvas;
  //  ist_dependence->Draw("AP");
  ist_dependence->Write();

  // myfile->close();

  return ist_dependence;

};
