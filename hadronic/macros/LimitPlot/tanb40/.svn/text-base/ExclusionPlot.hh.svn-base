#ifndef MAKE_EXCLUSIONPLOT_HH
#define MAKE_EXCLUSIONPLOT_HH

#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TF1.h"
#include "TLegend.h"
#include "TList.h"
#include "TLatex.h"
#include "TFile.h"
#include "TSpline.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TMath.h"
#include "TPad.h"
#include "TROOT.h"
#include "TCanvas.h"


#include <vector>

#include "GridDump.C"



void ExclusionPlot();


void CommandMSUGRA(TString plotName,Int_t tanBeta,Int_t sigma);



TCanvas* makeCanvas(TString tanb);


//PlottingTools
void setPlottingStyle(TH1F& hsig);
TH2F* getHisto( TString path,
    TString nameHist,
    TString nameFile );
TH1F* getHisto_1d( TString path,
       TString nameHist,
       TString nameFile );
TH2F* yieldPlot(TString mSuGraFile,TString mSuGraDir, TString mSuGraHist);
TH1F* yieldPlot(TString mSuGraFile, TString mSuGraHist);
TH2F* yieldPlot_nosubdir(TString mSuGraFile,TString mSuGraHist);


//older Exclusion curves
TGraph* set_lep_ch(Int_t tanBeta);
TGraph* set_lep_ch_tanBeta3();
TGraph* set_lep_ch_tanBeta10();
TGraph* set_lep_ch_tanBeta50();
TGraph* set_lep_sl(Int_t tanBeta);//slepton curve
TGraph* set_tev_sg_cdf(Int_t tanBeta);//squark gluino cdf
TGraph* set_tev_sg_d0(Int_t tanBeta);//squark gluino d0
TGraph* set_tev_stau(Int_t tanBeta);//stau
TGraph* set_NoEWSB(Int_t tanBeta);

TGraph* set_sneutrino_d0_1();
TGraph* set_sneutrino_d0_2();

TGraph* drawsqlines();
TGraph* drawgllines();

TF1* constant_squark(int tanBeta,int i);
TF1* constant_gluino(int tanBeta,int i);

TLatex* constant_squark_text(Int_t it,TF1& lnsq,Int_t tanBeta_);
TLatex* constant_gluino_text(Int_t it,TF1& lngl,Int_t tanBeta_);

TGraph* constant_mass(double mass, TH2F& massGrid);
//TGraph* constant_mass(double mass,TGraph2D* massGrid);

TLegend* makeStauLegend(Double_t txtsz,Int_t tanBeta_);
TLegend* makeExpLegend(TGraph& sg_gr, TGraph& sgd_gr,TGraph& ch_gr,TGraph& sl_gr,TGraph&,Double_t txtsz,Int_t tanbeta);
TLegend* makeNoEWSBLegend(Double_t txtsz,Int_t tanBeta);

//RA1 exclusion curves
TGraphErrors* getLO_tanBeta3();
TGraphErrors* getLO_tanBeta10();
TGraphErrors* getLO_tanBeta50();

//TGraphErrors* getCLs1080ObsNLO();
TSpline3* getCLs1080ObsNLO();
TSpline3* getCLs1080ObsNLOtb40();
//TGraphErrors* getCLs1080ObsLO();
TSpline3* getCLs1080Up();
TSpline3* getCLs1080Low();
TSpline3* getCLs1080Exp();
TSpline3* getCLs1080Uptb40();
TSpline3* getCLs1080Lowtb40();
TSpline3* getCLs1080Exptb40();

TGraphErrors* get1080ObsNLO();
TGraphErrors* get1080ObsLO();
TGraphErrors* get1080Up();
TGraphErrors* get1080Low();
TGraphErrors* get1080Exp();

TGraphErrors* get1080SidBandExp();
TGraphErrors* get1080QCDExpExp();

TGraphErrors* getATLASPLHC();
TGraphErrors* getATLAScomb();

TGraphErrors* getExpected_NLO_tanBeta3();
TGraphErrors* getExpected_NLO_tanBeta10();
TGraphErrors* getExpected_NLO_tanBeta50();

TGraphErrors* getExpected_NLO_tanBeta3_2();
TGraphErrors* getExpected_NLO_tanBeta10_2();
TGraphErrors* getExpected_NLO_tanBeta50_2();

TGraphErrors* getExpected_NLO_tanBeta3_low();
TGraphErrors* getExpected_NLO_tanBeta10_low();
TGraphErrors* getExpected_NLO_tanBeta50_low();

TGraphErrors* getExpected_NLO_tanBeta3_up();
TGraphErrors* getExpected_NLO_tanBeta10_up();
TGraphErrors* getExpected_NLO_tanBeta50_up();

TGraphErrors* getObserved_NLO_tanBeta3();
TGraphErrors* getObserved_NLO_tanBeta10();
TGraphErrors* getObserved_NLO_tanBeta50();

TGraphErrors* getObserved_NLO_tanBeta3_2();
TGraphErrors* getObserved_NLO_tanBeta10_2();
TGraphErrors* getObserved_NLO_tanBeta50_2();


TString plotName_;

vector<TH1F*> exclusionPlots;




#endif
