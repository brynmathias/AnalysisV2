#ifndef MAKE_EXCLUSIONPLOT_HH
#define MAKE_EXCLUSIONPLOT_HH

#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TFile.h"


#include "vector.h"





void ExclusionPlot();
  

void CommandMSUGRA(TString plotName,Int_t tanBeta);

 

void setPlottingStyle(TH2F& hsig,Int_t lineStyle);

void setPlottingStyle(TH2F& hsig);

 



  TGraph* set_lep_ch(Int_t tanBeta);
  TGraph* set_lep_sl(Int_t tanBeta);//slepton curve
  TGraph* set_tev_sg_cdf(Int_t tanBeta);//squark gluino cdf
  TGraph* set_tev_sg_d0(Int_t tanBeta);//squark gluino d0
  TGraph* set_tev_tlp_cdf(Int_t tanBeta);//trilepton cdf
  TGraph* set_tev_tlp_d0(Int_t tanBeta);//trilepton d0
TGraph* set_tev_stau(Int_t tanBeta);//stau 

TGraph* set_sneutrino_d0_1(Int_t tanBeta);
TGraph* set_sneutrino_d0_2(Int_t tanBeta);


  TF1* constant_squark(int tanBeta,int i);
  TF1* constant_gluino(int tanBeta,int i);

  TLatex* constant_squark_text(Int_t it,TF1& lnsq);
  TLatex* constant_gluino_text(Int_t it,TF1& lngl);

  TLegend* makeStauLegend(Double_t txtsz);
  TLegend* makeExpLegend(TGraph& sg_gr, TGraph& sgd_gr,TGraph& ch_gr,TGraph& sl_gr,Double_t txtsz);



  
  
  TString plotName_;

  vector<TH2F*> exclusionPlots;

TH2F* yieldPlot(TString mSuGraFile,TString mSuGraDir, TString mSuGraHist){
  //read In mSuGra Histo
  TFile* f = new TFile(mSuGraFile);
  TDirectory* dir = (TDirectory*)f->Get(mSuGraDir);
  
  TH2F* hnev = (TH2F*)dir->Get(mSuGraHist);

 

  return hnev;
}

TH2F* getHisto( TString path,
	       TString nameHist,
	       TString nameFile ) {
  TString name = path + nameFile;
  TFile* file =  new TFile(name);
  //  TDirectory* dir = (TDirectory*)file->Get(Dirname);
  TH2F* hist = (TH2F*)file->Get(nameHist);
  if (!hist) {
    std::cout << " name: " << nameHist
	      << " file: " << nameFile
	      << std::endl;
    abort();

  }
  hist->SetLineWidth(1);

  hist->GetXaxis()->SetTitleSize(0.055);
  hist->GetYaxis()->SetTitleSize(0.055);
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetLabelSize(0.05);
  hist->SetStats(kFALSE);
  return hist;
}



#endif
