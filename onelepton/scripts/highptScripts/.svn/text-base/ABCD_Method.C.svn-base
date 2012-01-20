#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TLine.h"
#include "TPolyLine.h"
#include "TGraphErrors.h"
#include "TROOT.h"
#include "TApplication.h"
#include "TString.h"
#include "TProfile.h"
#include "TMath.h"
#include "Riostream.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <TString.h>
#include "time.h"
#include <ctime>
#include <cstdlib>
#include "TLegend.h"
#include "TTree.h"
#include "TFile.h"
#include "TCut.h"
#include "TString.h"
#include "TLatex.h"
#include "setTDRStyle.h"
#include "TPaveStats.h"
#include "TProfile2D.h"

//#include "<direct.h>"
void setTDRStyle();
using namespace std;

#endif


void decomposeMEff(TH1D *hTempMean,TH1D *hTempRMS,TTree *tree,double MHTcut,double METcut,double HTcut,double LPmin,double LPmax);
void create1DhistoXinYbins(TCanvas *cCanvas,TTree *tree,bool fullSM,TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TString intLumi,
			   TString branch,int bins, double xmin, double xmax,TString cuts,double varLimit,
			   TString slice1,TString slice2,TString slice3,bool useLog,bool Data);
void DebugPlots(TTree *tree,TCanvas *cCanvas,TH1D *hNJts1Ref,TString intLumi,TString cuts,TString branch,int bins,double xmin,double xmax,
                double xminRange, double xmaxRange,double yminRatio,double ymaxRatio,double fitXmin,double fitXmax,bool useLog);
void createDataVsMCcompRatio(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,TTree *tree_DATAmu,
                             TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog);
void create1DMCcomp(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,
		    TCanvas *cCanvas,int cPad,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog,bool norm);
void create1DMCcompRatio(TTree *tree_MCw,TTree *tree_MCtt,TTree *tree_MClm0,TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,
			 TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog);
//void create2DMCComp(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,
//	  TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,TString cuts,TString branchX,int binsX,float xmin,float xmax,
//	  TString branchY,int binsY,float ymin,float ymax);
TH1D *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog);
TH1D *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool DATA,bool useLog);
TH2D *create2Dhisto(TTree *tree,TString intLumi,TString cuts,TString branchX,int binsX,float xmin,float xmax,
		    TString branchY,int binsY,float ymin,float ymax,bool DATA);
//TH2D *create2Dhisto(TTree *tree,TString intLumi,TString cuts,TString branchX,int binsX,float xmin,float xmax,
//	    TString branchY,int binsY,float ymin,float ymax,bool DATA);
TH1D *Divide2Histos(const TH1D* HistoInput1,const TH1D* HistoInput2);
TCanvas* createCanvas(TString name,int xlen,int ylen,bool logOn);
TCanvas* createCanvas(TString name,int xlen,int ylen,int xDiv,bool logOn);
TLegend *legendRAW();
TH1D *calculateSignificance(TTree *tMCqcd,TTree *tMCz,TTree *tMCw,TTree *tMCtt,TTree *tMClm0,TTree *tMClm1,TString lumi,TString Cut,TString var,int bins,double min,double max);


void mainFunction() {

  setTDRStyle();
  gROOT->SetBatch(false);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);
  //  gStyle->SetOptStat("emriou");
  //  gStyle->SetPalette(1);

  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(1);


  // ---------
  // Define Integrated Lumi [pb^{-1}]



  // -----------
  // Open files

  TString filename_MCqcd  = "../DATA/20110112/LP_Muons_QCD_Pythia_AllPtBins_June2010_6.root";
  TString filename_MCw    = "../DATA/20110112/LP_Muons_Wjets_June2010_1.root";
  TString filename_MCz    = "../DATA/20110112/LP_Muons_Zjets_June2010_5.root";
  TString filename_MCtt   = "../DATA/20110112/LP_Muons_TTbarTauola_June2010_2.root";
  TString filename_MClm0  = "../DATA/20110112/LP_Muons_LM0_June2010_3.root";
  TString filename_MClm1  = "../DATA/20110112/LP_Muons_LM1_June2010_4.root";
  TString filename_DATAmu = "../DATA/20110112/Mu.root";


  TFile *f_MCqcd  = TFile::Open(filename_MCqcd,"READONLY");
  TFile *f_MCw    = TFile::Open(filename_MCw,"READONLY");
  TFile *f_MCz    = TFile::Open(filename_MCz,"READONLY");
  TFile *f_MCtt   = TFile::Open(filename_MCtt,"READONLY");
  TFile *f_MClm0  = TFile::Open(filename_MClm0,"READONLY");
  TFile *f_MClm1  = TFile::Open(filename_MClm1,"READONLY");
  TFile *f_DATAmu = TFile::Open(filename_DATAmu,"READONLY");


  TString treeFolder = "MuonTree/";
  TTree *tree_MCqcd  = (TTree*)f_MCqcd->Get(treeFolder+"T");
  TTree *tree_MCw    = (TTree*)f_MCw->Get(treeFolder+"T");
  TTree *tree_MCz    = (TTree*)f_MCz->Get(treeFolder+"T");
  TTree *tree_MCtt   = (TTree*)f_MCtt->Get(treeFolder+"T");
  TTree *tree_MClm0  = (TTree*)f_MClm0->Get(treeFolder+"T");
  TTree *tree_MClm1  = (TTree*)f_MClm1->Get(treeFolder+"T");
  TTree *tree_DATAmu = (TTree*)f_DATAmu->Get(treeFolder+"T");



  // arguments
  //  TString varX = "(MuonPt[0]-PFMET)/(MuonPt[0]+PFMET)"; int binsX = 20; double minX = -1.; double maxX = 1.; 
  TString varX = "PFLP_h"; int binsX = 200; double minX = -0.6; double maxX = 1.4; 
  TString varY = "M3"; int binsY = 500; double minY = 0.;   double maxY = 1000.;
  TString sliceVarX1 = varX+"<0.3";  TString sliceVarX2 = "0.3 <="+varX+" && "+varX+"<0.8";  TString sliceVarX3 = varX+">=0.8";
  TString sliceVarY1 = varY+"<300."; TString sliceVarY2 = varY+">=300. && "+varY+"<500."; TString sliceVarY3 = varY+">=500.";
  float intLumi = 35.;
  TString Cut = "NMuons==1 && MuonClosestComJetDR[0]>0.3 && MuonPt[0]>15. && NJet30>=3 && PFMT_h>30. && M3>0. && PFMHT_h>150. && HT>250.";
  double varXlimitLow = 0.1; double varXlimitHigh = 0.3; double varYlimitLow = 250.; double varYlimitHigh = 350.;
  bool addLM0 = false; bool addLM1 = true;
  // ~ end of arguments

  

  // save plots
  TString plotsFolder = "../Plots/20101214_ABCD_a/";
  TString prefixA = varX+"in"+varY+"bins";
  TString prefixB = varY+"in"+varX+"bins";
  TString cutInfo = "geq2Jts_PFMHT150_HT200_PFMT30_Meff0_Neg";
  TString suffixA = "MC_TotW";  
  TString suffixB = "MC_TotTT";
  TString suffixC = "MC_TotSM";


  ostringstream tmpLumi; 
  tmpLumi << intLumi;
  TString lumi = tmpLumi.str();

  /*  
  TCanvas *cCharge = new TCanvas("cCharge","cCharge",800,300);
  cCharge->Divide(2,1);

  cCharge->cd(1);
  TString cut1 = Cut+" && MuonChrg[0]<0.";
  TH1D *h1  = create1Dhisto(tree_MCtt,lumi,cut1,varY,binsY,minY,maxY,false,false);  h1->SetName("h1");
  h1->SetLineColor(1); h1->SetLineWidth(2); h1->SetMarkerSize(0);

  TString cut2 = Cut+" && MuonChrg[0]<0.";
  TH1D *h2  = create1Dhisto(tree_MCw,lumi,cut2,varY,binsY,minY,maxY,false,false);  h2->SetName("h2");
  h2->SetLineColor(2); h2->SetLineWidth(2); h2->SetMarkerSize(0);

  h1->Draw("HIST E0");
  h2->Draw("HIST E0 sames");

  cCharge->cd(2);
  TH1D *hRatio = (TH1D*)h1->Clone("hRatio");
  hRatio->Divide(h1,h2,1.,1.);
  hRatio->SetLineColor(1); hRatio->SetLineWidth(2); hRatio->SetMarkerSize(1); hRatio->SetMarkerStyle(20); hRatio->SetMarkerColor(1);
  hRatio->Draw("P E0");
  */


  /*
  // calculate the S/sqrt(B) for different cases
  TCanvas *cSignif = new TCanvas("cSignif","cSignif",400,300);
  gPad->SetGrid(1);

  TString Cut0 = Cut;
  TH1D *h_LP0 = calculateSignificance(tree_MCqcd,tree_MCz,tree_MCw,tree_MCtt,tree_MClm0,tree_MClm1,lumi,Cut0,"M3",1000,0.,1000.);
  h_LP0->SetName("h_LP0"); h_LP0->SetMarkerStyle(20); h_LP0->SetMarkerColor(1); h_LP0->SetLineWidth(2); h_LP0->SetLineColor(1);

  TString Cut1 = Cut+" && PFLP<0.3";
  TH1D *h_LP1 = calculateSignificance(tree_MCqcd,tree_MCz,tree_MCw,tree_MCtt,tree_MClm0,tree_MClm1,lumi,Cut1,"M3",1000,0.,1000.);
  h_LP1->SetName("h_LP1"); h_LP1->SetMarkerStyle(20); h_LP1->SetMarkerColor(2); h_LP1->SetLineWidth(2); h_LP1->SetLineColor(2);

  TString Cut2 = Cut+" && PFLP<0.2";
  TH1D *h_LP2 = calculateSignificance(tree_MCqcd,tree_MCz,tree_MCw,tree_MCtt,tree_MClm0,tree_MClm1,lumi,Cut2,"M3",1000,0.,1000.);
  h_LP2->SetName("h_LP2"); h_LP2->SetMarkerStyle(20); h_LP2->SetMarkerColor(kGreen+2); h_LP2->SetLineWidth(2); h_LP2->SetLineColor(kGreen+2);

  TString Cut3 = Cut+" && PFLP<0.1";
  TH1D *h_LP3 = calculateSignificance(tree_MCqcd,tree_MCz,tree_MCw,tree_MCtt,tree_MClm0,tree_MClm1,lumi,Cut3,"M3",1000,0.,1000.);
  h_LP3->SetName("h_LP3"); h_LP3->SetMarkerStyle(20); h_LP3->SetMarkerColor(4); h_LP3->SetLineWidth(2); h_LP3->SetLineColor(4);

  h_LP0->Draw("P");
  h_LP1->Draw("P sames");
  h_LP2->Draw("P sames");
  h_LP3->Draw("P sames");

  TLegend *leg1 = new TLegend(0.75,0.7,0.92,0.93);
  leg1->SetFillStyle(0);
  leg1->SetBorderSize(0);
  leg1->SetTextSize(0.04);
  leg1->SetTextFont(42);
  leg1->AddEntry(h_LP0,"No LP Cut","PL");
  leg1->AddEntry(h_LP1,"LP<0.3","PL");
  leg1->AddEntry(h_LP2,"LP<0.2","PL");
  leg1->AddEntry(h_LP3,"LP<0.1","PL");
  leg1->Draw("same");
  */    



  
  // VarX & Var Y plots decomposed to each proccess to check spearation power etc..
  /*    
  TString Cut0 = "NMuons==1 && MuonClosestComJetDR[0]>0.3 && NJet>=3 && PFMT_h>30. && M3>0.";

  TCanvas *cVarX = createCanvas("cVarX",800,300,true);
  cVarX->Divide(2,1);
  create1DMCcomp(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,cVarX,1,lumi,Cut0,varX,20,minX,maxX,false,false);
  create1DMCcomp(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,cVarX,2,lumi,Cut0,varX,20,minX,maxX,false,true);


  TCanvas *cVarY = createCanvas("cVarY",800,300,true);
  cVarY->Divide(2,1);
  create1DMCcomp(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,cVarY,1,lumi,Cut0,varY,20,minY,maxY,false,false);
  create1DMCcomp(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,cVarY,2,lumi,Cut0,varY,20,minY,maxY,false,true);
  */



  
  //
  // check the correlation between the 2 variables
  /*
  cout.precision(3);
  cout << "\n\n";
  
    
  cout << "XinYbins" << "\n";
  cout << "--------" << "\n\n";

  cout << "-- W --" << "\n";
  TCanvas *cXinYbins_W = createCanvas("cXinYbins_W",900,600,false);
  create1DhistoXinYbins(cXinYbins_W,tree_MCw,false,tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,lumi,varX,binsX,minX,maxX,Cut,varXlimitLow,
			sliceVarY1,sliceVarY2,sliceVarY3,false,false);

  cout << "-- T-Tbar --" << "\n";
  TCanvas *cXinYbins_TT = createCanvas("cXinYbins_TT",900,600,false);
  create1DhistoXinYbins(cXinYbins_TT,tree_MCtt,false,tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,lumi,varX,binsX,minX,maxX,Cut,varXlimitLow,
			sliceVarY1,sliceVarY2,sliceVarY3,false,false);

  cout << "-- SM --" << "\n";
  TCanvas *cXinYbins_SM = createCanvas("cXinYbins_SM",900,600,false);
  create1DhistoXinYbins(cXinYbins_SM,tree_MCtt,true,tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,lumi,varX,binsX,minX,maxX,Cut,varXlimitLow,
			sliceVarY1,sliceVarY2,sliceVarY3,false,false);

  
  cout << "YinXbins" << "\n";
  cout << "--------" << "\n\n";

  cout << "-- W --" << "\n";
  TCanvas *cYinXbins_W = createCanvas("cYinXbins_W",900,600,false);
  create1DhistoXinYbins(cYinXbins_W,tree_MCw,false,tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,lumi,varY,binsY,minY,maxY,Cut,varYlimit,
			sliceVarX1,sliceVarX2,sliceVarX3,false,false);

  cout << "-- T-Tbar --" << "\n";
  TCanvas *cYinXbins_TT = createCanvas("cYinXbins_TT",900,600,false);
  create1DhistoXinYbins(cYinXbins_TT,tree_MCtt,false,tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,lumi,varY,binsY,minY,maxY,Cut,varYlimit,
			sliceVarX1,sliceVarX2,sliceVarX3,false,false);

  cout << "-- SM --" << "\n";
  TCanvas *cYinXbins_SM = createCanvas("cYinXbins_SM",900,600,false);
  create1DhistoXinYbins(cYinXbins_SM,tree_MCtt,true,tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,lumi,varY,binsY,minY,maxY,Cut,varYlimit,
			sliceVarX1,sliceVarX2,sliceVarX3,false,false);
  */
  

 
  // Create histograms 
  //  binsX = binsX*20.; binsY = binsY*20.;
  TH2D *hQCD = create2Dhisto(tree_MCqcd,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,false);
  hQCD->SetName("hQCD");
  hQCD->SetMarkerStyle(20);
  hQCD->SetMarkerColor(1);
  hQCD->SetMarkerSize(0.3);
  TH2D *hZ = create2Dhisto(tree_MCz,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,false);
  hZ->SetName("hZ");
  hZ->SetMarkerStyle(20);
  hZ->SetMarkerColor(1);
  hZ->SetMarkerSize(0.3);
  TH2D *hW = create2Dhisto(tree_MCw,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,false);
  hW->SetName("hW");
  hW->SetMarkerStyle(20);
  hW->SetMarkerColor(1);
  hW->SetMarkerSize(0.3);
  TH2D *hTT = create2Dhisto(tree_MCtt,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,false);
  hTT->SetName("hTT");
  hTT->SetMarkerStyle(20);
  hTT->SetMarkerColor(1);
  hTT->SetMarkerSize(0.3);
  TH2D *hSM = (TH2D*)hTT->Clone("hSM");
  hSM->Add(hQCD); hSM->Add(hZ); hSM->Add(hW);
  hSM->SetName("hSM");
  hSM->SetMarkerStyle(20);
  hSM->SetMarkerColor(1);
  hSM->SetMarkerSize(0.3);

  TH2D *hLM0 = create2Dhisto(tree_MClm0,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,false);
  hLM0->SetName("hLM0");
  hLM0->SetMarkerStyle(21);
  hLM0->SetMarkerColor(2);
  hLM0->SetMarkerSize(0.3);
  if (addLM0) { hSM->Add(hLM0); }
  TH2D *hLM1 = create2Dhisto(tree_MClm1,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,false);
  hLM1->SetName("hLM1");
  hLM1->SetMarkerStyle(21);
  hLM1->SetMarkerColor(2);
  hLM1->SetMarkerSize(0.3);
  if (addLM1) { hSM->Add(hLM1); }
  TH2D *hDATA = create2Dhisto(tree_DATAmu,lumi,Cut,varX,binsX,minX,maxX,varY,binsY,minY,maxY,true);
  hDATA->SetName("hDATA");
  hDATA->SetMarkerStyle(22);
  hDATA->SetMarkerColor(4);
  hDATA->SetMarkerSize(0.3);


  // Create Normalized histograms

  TCanvas *cM3vsLP = new TCanvas("cM3vsLP","cM3vsLP",1200,300);
  cM3vsLP->Divide(3,1);

  cM3vsLP->cd(1);
  TH1D *hSMb = (TH1D*)hSM->Clone("hSMb"); 
  hSMb->Draw("COLZ");

  cM3vsLP->cd(2);
  TH1D *hLM0b = (TH1D*)hLM0->Clone("hLM0b");
  hLM0b->Draw("COLZ");

  cM3vsLP->cd(3);
  TH1D *hLM1b = (TH1D*)hLM1->Clone("hLM1b");
  hLM1b->Draw("COLZ"); 


  
  // Draw ABCD plot [MC]
  TCanvas *cABCD_MC = createCanvas("cABCD_MC",500,500,false);
  hLM0->Draw();
  hQCD->Draw("sames");
  hZ->Draw("sames");
  hW->Draw("sames");
  hTT->Draw("sames");
  
  // Draw ABCD plot [DATA]
  TCanvas *cABCD_DATA = createCanvas("cABCD_DATA",500,500,false);
  hDATA->Draw();
 
  /*
  TH1D *hW_1D  = create1Dhisto(tree_MCw,lumi,Cut,varY,binsY,minY,maxY,false,false);  hW_1D->SetName("hW_1D");
  TH1D *hTT_1D = create1Dhisto(tree_MCtt,lumi,Cut,varY,binsY,minY,maxY,false,false); hTT_1D->SetName("hTT_1D");

  double ratio1_min = 0.;     double ratio1_max = 160.;
  double ratio2_min = 160.;   double ratio2_max = 210.;
  double ratio3_min = 210.;   double ratio3_max = 400.;

  cout << "ratio1 = " << hW_1D->Integral(hW_1D->FindBin(ratio1_min),hW_1D->FindBin(ratio1_max)) << "/" << hTT_1D->Integral(hTT_1D->FindBin(ratio1_min),hTT_1D->FindBin(ratio1_max)) 
       << " = " << (hW_1D->Integral(hW_1D->FindBin(ratio1_min),hW_1D->FindBin(ratio1_max)))/(hTT_1D->Integral(hTT_1D->FindBin(ratio1_min),hTT_1D->FindBin(ratio1_max))) << "\n";
  */

 
    
  // compute number of events and the error
  cout.precision(1);
  double NerrQCD  = 0.; double Nqcd  = hQCD->IntegralAndError(0,binsX+1,0,binsY+1,NerrQCD);
  double NerrZ    = 0.; double Nz    = hZ->IntegralAndError(0,binsX+1,0,binsY+1,NerrZ);
  double NerrW    = 0.; double Nw    = hW->IntegralAndError(0,binsX+1,0,binsY+1,NerrW);
  double NerrTT   = 0.; double Ntt   = hTT->IntegralAndError(0,binsX+1,0,binsY+1,NerrTT);
  double NerrSM   = 0.; double Nsm   = hSM->IntegralAndError(0,binsX+1,0,binsY+1,NerrSM);
  double NerrDATA = 0.; double Ndata = hDATA->IntegralAndError(0,binsX+1,0,binsY+1,NerrDATA);
  double NerrLM0  = 0.; double Nlm0  = hLM0->IntegralAndError(0,binsX+1,0,binsY+1,NerrLM0);
  double NerrLM1  = 0.; double Nlm1  = hLM1->IntegralAndError(0,binsX+1,0,binsY+1,NerrLM1);



  // Application of the ABCD Method
  // N_D = [N_A/N_B]*N_C // N_D signal region

  int varXlimitLowBin = hTT->GetXaxis()->FindBin(varXlimitLow); int varXlimitHighBin = hTT->GetXaxis()->FindBin(varXlimitHigh);
  int varYlimitLowBin = hTT->GetYaxis()->FindBin(varYlimitLow); int varYlimitHighBin = hTT->GetYaxis()->FindBin(varYlimitHigh);


  // MC
  double N_A_Err = 0.;      double N_A = hSM->IntegralAndError(varXlimitHighBin,binsX+1,varYlimitHighBin,binsY+1,N_A_Err);
  double N_B_Err = 0.;      double N_B = hSM->IntegralAndError(varXlimitHighBin,binsX+1,0,varYlimitLowBin,N_B_Err);
  double N_C_Err = 0.;      double N_C = hSM->IntegralAndError(0,varXlimitLowBin,0,varYlimitLowBin,N_C_Err);
  double N_D_Obs_Err = 0.;  double N_D_Obs = hSM->IntegralAndError(0,varXlimitLowBin,varYlimitHighBin,binsY+1,N_D_Obs_Err);
  double N_D_LM0_Err = 0.; double N_D_LM0 = hLM0->IntegralAndError(0,varXlimitLowBin,varYlimitHighBin,binsY+1,N_D_LM0_Err);
  double N_D_LM1_Err = 0.; double N_D_LM1 = hLM1->IntegralAndError(0,varXlimitLowBin,varYlimitHighBin,binsY+1,N_D_LM1_Err);

  double N_D_Pre = (N_A/N_B)*N_C; 
  double N_D_Pre_Err = sqrt(pow((N_C*N_A_Err/N_B),2)+pow(((N_A*N_C*N_B_Err)/(N_B*N_B)),2)+pow((N_A*N_C_Err/N_B),2));
  
  
  // DATA
  double Ndata_A_Err = 0.;     double Ndata_A = hDATA->IntegralAndError(varXlimitHighBin,binsX+1,varYlimitHighBin,binsY+1,Ndata_A_Err);
  double Ndata_B_Err = 0.;     double Ndata_B = hDATA->IntegralAndError(varXlimitHighBin,binsX+1,0,varYlimitLowBin,Ndata_B_Err);
  double Ndata_C_Err = 0.;     double Ndata_C = hDATA->IntegralAndError(0,varXlimitLowBin,0,varYlimitLowBin,Ndata_C_Err);
  double Ndata_D_Obs_Err = 0.; double Ndata_D_Obs = hDATA->IntegralAndError(0,varXlimitLowBin,varYlimitHighBin,binsY+1,Ndata_D_Obs_Err);

  double Ndata_D_Pre = (Ndata_A/Ndata_B)*Ndata_C; 
  double Ndata_D_Pre_Err = sqrt(pow((Ndata_C*Ndata_A_Err/Ndata_B),2)+pow(((Ndata_A*Ndata_C*Ndata_B_Err)/(Ndata_B*Ndata_B)),2)+pow((Ndata_A*Ndata_C_Err/Ndata_B),2));
  

  // Print out results
  
  cout << "\n\n";
  cout << "Print Results" << "\n";
  cout << "-------------" << "\n";
  cout << "\n";
  
  cout << "De-composition of samples @ " << intLumi << " pb-1" << "\n";
  cout << "----------------------------------------" << "\n";
  cout << "QCD:  " << Nqcd  << " +/- " << NerrQCD  << "\n"; 
  cout << "Z:    " << Nz    << " +/- " << NerrZ    << "\n"; 
  cout << "W:    " << Nw    << " +/- " << NerrW    << "\n"; 
  cout << "TT:   " << Ntt   << " +/- " << NerrTT   << "\n"; 
  cout << "SM:   " << Nsm   << " +/- " << NerrSM   << "\n";
  //  cout << "DATA: " << Ndata << " +/- " << NerrDATA << "\n";
  cout << "LM0:  " << Nlm0  << " +/- " << NerrLM0  << "\n"; 
  cout << "LM1:  " << Nlm1  << " +/- " << NerrLM1  << "\n"; 

   
  cout << "\n\n";
  cout << "--- MC ---" << "\n"; 
  cout << "----------" << "\n";
  cout << "N_A:             " << N_A     << " +/- " << N_A_Err     << "\n";
  cout << "N_B:             " << N_B     << " +/- " << N_B_Err     << "\n";
  cout << "N_C:             " << N_C     << " +/- " << N_C_Err     << "\n";
  cout << "N_D [Observed]:  " << N_D_Obs << " +/- " << N_D_Obs_Err << "\n";
  cout << "N_D [Predicted]: " << N_D_Pre << " +/- " << N_D_Pre_Err << "\n";
  cout << "N_D [LM0]:       " << N_D_LM0 << " +/- " << N_D_LM0_Err << "\n";
  cout << "N_D [LM1]:       " << N_D_LM1 << " +/- " << N_D_LM1_Err << "\n";
 
  
  cout << "\n\n";
  cout << "-- DATA --" << "\n"; 
  cout << "----------" << "\n";
  cout << "N_A:             " << Ndata_A     << " +/- " << Ndata_A_Err     << "\n";
  cout << "N_B:             " << Ndata_B     << " +/- " << Ndata_B_Err     << "\n";
  cout << "N_C:             " << Ndata_C     << " +/- " << Ndata_C_Err     << "\n";
  cout << "N_D [Observed]:  " << Ndata_D_Obs << " +/- " << Ndata_D_Obs_Err << "\n";
  cout << "N_D [Predicted]: " << Ndata_D_Pre << " +/- " << Ndata_D_Pre_Err << "\n";
  cout << "\n\n";
  
    
  // save plots
  
  //  cXinYbins_W->Print("./Plots/"+plotsFolder+prefixA+"_"+cutInfo+"_"+suffixA+".png");
  //  cXinYbins_TT->Print("./Plots/"+plotsFolder+prefixA+"_"+cutInfo+"_"+suffixB+".png");
  //  cXinYbins_SM->Print("./Plots/"+plotsFolder+prefixA+"_"+cutInfo+"_"+suffixC+".png");
  //  cYinXbins_W->Print("./Plots/"+plotsFolder+prefixB+"_"+cutInfo+"_"+suffixA+".png");
  //  cYinXbins_TT->Print("./Plots/"+plotsFolder+prefixB+"_"+cutInfo+"_"+suffixB+".png");
  //  cYinXbins_SM->Print("./Plots/"+plotsFolder+prefixB+"_"+cutInfo+"_"+suffixC+".png");
  //  cABCD_MC->Print("./Plots/"+plotsFolder+"ABCD_MC_"+cutInfo+".png");
  //  cABCD_DATA->Print("./Plots/"+plotsFolder+"ABCD_DATA_"+cutInfo+".png");
  

  //  ABCDoutput.close();


  /*
  // Debug - Why Meff distribution is correlated with LP for LP<0.3
  TCanvas *cDebug = new TCanvas("cCanvas","cCanvas",800,300);
  cDebug->Divide(2,1);

  TH1D *hTempMean_Low = new TH1D("hTempMean_Low","hTempMean_Low",3,0.,3.);
  TH1D *hTempRMS_Low  = new TH1D("hTempRMS_Low","hTempRMS_Low",3,0.,3.);
  hTempMean_Low->SetLineColor(1);
  hTempMean_Low->SetLineWidth(2);
  hTempRMS_Low->SetLineColor(1);
  hTempRMS_Low->SetLineWidth(2);
  decomposeMEff(hTempMean_Low,hTempRMS_Low,tree_MCtt,100.,0.,100.,-10.,0.3);

  TH1D *hTempMean_Mid = new TH1D("hTempMean_Mid","hTempMean_Mid",3,0.,3.);
  TH1D *hTempRMS_Mid  = new TH1D("hTempRMS_Mid","hTempRMS_Mid",3,0.,3.);
  hTempMean_Mid->SetLineColor(2);
  hTempMean_Mid->SetLineWidth(2);
  hTempRMS_Mid->SetLineColor(2);
  hTempRMS_Mid->SetLineWidth(2);
  decomposeMEff(hTempMean_Mid,hTempRMS_Mid,tree_MCtt,100.,0.,100.,0.3,0.8);

  TH1D *hTempMean_High = new TH1D("hTempMean_High","hTempMean_High",3,0.,3.);
  TH1D *hTempRMS_High  = new TH1D("hTempRMS_High","hTempRMS_High",3,0.,3.);
  hTempMean_High->SetLineColor(4);
  hTempMean_High->SetLineWidth(2);
  hTempRMS_High->SetLineColor(4);
  hTempRMS_High->SetLineWidth(2);
  decomposeMEff(hTempMean_High,hTempRMS_High,tree_MCtt,100.,0.,100.,0.8,10.);

  cDebug->cd(1);
  hTempMean_Low->GetYaxis()->SetRangeUser(0.,0.8);
  hTempMean_Low->Draw("HIST");
  hTempMean_Mid->Draw("HIST sames");
  hTempMean_High->Draw("HIST sames");

  cDebug->cd(2);
  hTempRMS_Low->GetYaxis()->SetRangeUser(0.02,0.1);
  hTempRMS_Low->Draw("HIST");
  hTempRMS_Mid->Draw("HIST sames");
  hTempRMS_High->Draw("HIST sames");
  */


} // ~ end of main function


// ----------------
// Help Functions


// create function: create1DhistoXinYbins()

void create1DhistoXinYbins(TCanvas *cCanvas,TTree *tree,bool fullSM,TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TString intLumi,
			   TString branch,int bins, double xmin, double xmax,TString cuts,double varLimit,
			   TString slice1,TString slice2,TString slice3,bool useLog,bool Data) {

  gStyle->SetOptStat(0);

  cCanvas->Divide(2,2);

  // slices
  //  TString cuts1 = "(wgt*"+intLumi+")*("+cuts+" && "+slice1+")";
  //  TString cuts2 = "(wgt*"+intLumi+")*("+cuts+" && "+slice2+")";
  //  TString cuts3 = "(wgt*"+intLumi+")*("+cuts+" && "+slice3+")";

  TString cuts1 = cuts+" && "+slice1;
  TString cuts2 = cuts+" && "+slice2;
  TString cuts3 = cuts+" && "+slice3;


  TLegend *lDistributions = legendRAW();
  TLegend *lRatio = legendRAW();


  // Abs distributions
  cCanvas->cd(1);
  if (useLog) { gPad->SetLogy(); }

  TH1D *h1_Abs;
  if (fullSM) {
    TH1D *h1_Abs_qcd = create1Dhisto(tree_MCqcd,intLumi,cuts1,branch,bins,xmin,xmax,useLog,Data); h1_Abs_qcd->SetName("h1_Abs_qcd");
    TH1D *h1_Abs_z   = create1Dhisto(tree_MCz,intLumi,cuts1,branch,bins,xmin,xmax,useLog,Data);   h1_Abs_z->SetName("h1_Abs_z");
    TH1D *h1_Abs_w   = create1Dhisto(tree_MCw,intLumi,cuts1,branch,bins,xmin,xmax,useLog,Data);   h1_Abs_w->SetName("h1_Abs_w");
    TH1D *h1_Abs_tt  = create1Dhisto(tree_MCtt,intLumi,cuts1,branch,bins,xmin,xmax,useLog,Data);  h1_Abs_tt->SetName("h1_Abs_tt");
    h1_Abs = (TH1D*)h1_Abs_qcd->Clone("h1_Abs"); h1_Abs->Add(h1_Abs_z); h1_Abs->Add(h1_Abs_w); h1_Abs->Add(h1_Abs_tt);
  } else { h1_Abs = create1Dhisto(tree,intLumi,cuts1,branch,bins,xmin,xmax,useLog,Data); }
  h1_Abs->SetName("h1_Abs");
  //  h1_Abs->Sumw2();
  h1_Abs->SetMarkerStyle(20);
  h1_Abs->SetMarkerColor(1);
  h1_Abs->SetMarkerSize(0);
  h1_Abs->SetLineWidth(2);
  h1_Abs->SetLineColor(1);
  if (useLog) { h1_Abs->GetYaxis()->SetRangeUser(0.01,5.*(h1_Abs->GetBinContent(h1_Abs->GetMaximumBin()))); }
  else { h1_Abs->GetYaxis()->SetRangeUser(0.,2.*(h1_Abs->GetBinContent(h1_Abs->GetMaximumBin()))); }

  TH1D *h2_Abs;
  if (fullSM) {
    TH1D *h2_Abs_qcd = create1Dhisto(tree_MCqcd,intLumi,cuts2,branch,bins,xmin,xmax,useLog,Data); h2_Abs_qcd->SetName("h2_Abs_qcd");
    TH1D *h2_Abs_z   = create1Dhisto(tree_MCz,intLumi,cuts2,branch,bins,xmin,xmax,useLog,Data);   h2_Abs_z->SetName("h2_Abs_z");
    TH1D *h2_Abs_w   = create1Dhisto(tree_MCw,intLumi,cuts2,branch,bins,xmin,xmax,useLog,Data);   h2_Abs_w->SetName("h2_Abs_w");
    TH1D *h2_Abs_tt  = create1Dhisto(tree_MCtt,intLumi,cuts2,branch,bins,xmin,xmax,useLog,Data);  h2_Abs_tt->SetName("h2_Abs_tt");
    h2_Abs = (TH1D*)h2_Abs_qcd->Clone("h2_Abs"); h2_Abs->Add(h2_Abs_z); h2_Abs->Add(h2_Abs_w); h2_Abs->Add(h2_Abs_tt);
  } else { h2_Abs = create1Dhisto(tree,intLumi,cuts2,branch,bins,xmin,xmax,useLog,Data); }
  h2_Abs->SetName("h2_Abs");
  //  h2_Abs->Sumw2();
  h2_Abs->SetMarkerStyle(21);
  h2_Abs->SetMarkerColor(2);
  h2_Abs->SetMarkerSize(1);
  h2_Abs->SetLineWidth(2);
  h2_Abs->SetLineColor(2);

  TH1D *h3_Abs;
  if (fullSM) {
    TH1D *h3_Abs_qcd = create1Dhisto(tree_MCqcd,intLumi,cuts3,branch,bins,xmin,xmax,useLog,Data); h3_Abs_qcd->SetName("h3_Abs_qcd");
    TH1D *h3_Abs_z   = create1Dhisto(tree_MCz,intLumi,cuts3,branch,bins,xmin,xmax,useLog,Data);   h3_Abs_z->SetName("h3_Abs_z");
    TH1D *h3_Abs_w   = create1Dhisto(tree_MCw,intLumi,cuts3,branch,bins,xmin,xmax,useLog,Data);   h3_Abs_w->SetName("h3_Abs_w");
    TH1D *h3_Abs_tt  = create1Dhisto(tree_MCtt,intLumi,cuts3,branch,bins,xmin,xmax,useLog,Data);  h3_Abs_tt->SetName("h3_Abs_tt");
    h3_Abs = (TH1D*)h3_Abs_qcd->Clone("h3_Abs"); h3_Abs->Add(h3_Abs_z); h3_Abs->Add(h3_Abs_w); h3_Abs->Add(h3_Abs_tt);
  } else { h3_Abs = create1Dhisto(tree,intLumi,cuts3,branch,bins,xmin,xmax,useLog,Data); }
  h3_Abs->SetName("h3_Abs");
  //  h3_Abs->Sumw2();
  h3_Abs->SetMarkerStyle(22);
  h3_Abs->SetMarkerColor(4);
  h3_Abs->SetMarkerSize(1);
  h3_Abs->SetLineWidth(2);
  h3_Abs->SetLineColor(4);

  h1_Abs->Draw("HIST E0");
  h2_Abs->Draw("HIST E0 sames");
  h3_Abs->Draw("HIST E0 sames");

  lDistributions->AddEntry(h1_Abs,"Reg1","PL");
  lDistributions->AddEntry(h2_Abs,"Reg2","PL");
  lDistributions->AddEntry(h3_Abs,"Reg3","PL");
  lDistributions->Draw("same");


  // Ratio of abs distributions
  cCanvas->cd(2);
  TH1D *h2ovh1_Abs = (TH1D*)h2_Abs->Clone("h2ovh1_Abs");
  h2ovh1_Abs->SetName("h2ovh1_Abs"); 
  h2ovh1_Abs->Divide(h2_Abs,h1_Abs);

  TH1D *h3ovh1_Abs = (TH1D*)h3_Abs->Clone("h3ovh1_Abs");
  h3ovh1_Abs->SetName("h3ovh1_Abs");
  h3ovh1_Abs->Divide(h3_Abs,h1_Abs); 

  h2ovh1_Abs->GetYaxis()->SetRangeUser(0.,5.);
  h2ovh1_Abs->Draw("P E0");
  h3ovh1_Abs->Draw("P E0 sames");

  lRatio->AddEntry(h2ovh1_Abs,"Reg2/Reg1","PL");
  lRatio->AddEntry(h3ovh1_Abs,"Reg3/Reg1","PL");
  lRatio->Draw("same");


  // Norm distributions
  cCanvas->cd(3);
  if (useLog) { gPad->SetLogy(); }

  TH1D *h1_Norm = (TH1D*)h1_Abs->Clone("h1_Norm");
  h1_Norm->SetName("h1_Norm");
  //  h1_Norm->Sumw2();
  h1_Norm->Scale(1./(h1_Norm->Integral()));
  h1_Norm->SetMarkerStyle(20);
  h1_Norm->SetMarkerColor(1);
  h1_Norm->SetMarkerSize(0);
  h1_Norm->SetLineWidth(2);
  h1_Norm->SetLineColor(1);
  if (useLog) { h1_Norm->GetYaxis()->SetRangeUser(0.0001,5*(h1_Norm->GetBinContent(h1_Norm->GetMaximumBin()))); }
  else { h1_Norm->GetYaxis()->SetRangeUser(0.,1.7*(h1_Norm->GetBinContent(h1_Norm->GetMaximumBin()))); }

  TH1D *h2_Norm = (TH1D*)h2_Abs->Clone("h2_Norm");
  h2_Norm->SetName("h2_Norm");
  //  h2_Norm->Sumw2();
  h2_Norm->Scale(1./(h2_Norm->Integral()));
  h2_Norm->SetMarkerStyle(21);
  h2_Norm->SetMarkerColor(2);
  h2_Norm->SetMarkerSize(1);
  h2_Norm->SetLineWidth(2);
  h2_Norm->SetLineColor(2);

  TH1D *h3_Norm = (TH1D*)h3_Abs->Clone("h3_Norm");
  h3_Norm->SetName("h3_Norm");
  //  h1_Norm->Sumw2();
  h3_Norm->Scale(1./(h3_Norm->Integral()));
  h3_Norm->SetMarkerStyle(22);
  h3_Norm->SetMarkerColor(4);
  h3_Norm->SetMarkerSize(1);
  h3_Norm->SetLineWidth(2);
  h3_Norm->SetLineColor(4);

  h1_Norm->Draw("HIST E0");
  h2_Norm->Draw("HIST E0 sames");
  h3_Norm->Draw("HIST E0 sames");

  lDistributions->Draw("same");


  // Ratio of norm distributions
  cCanvas->cd(4);
  TH1D *h2ovh1_Norm = (TH1D*)h2_Norm->Clone("h2ovh1_Norm");
  h2ovh1_Norm->SetName("h2ovh1_Norm"); 
  h2ovh1_Norm->Divide(h2_Norm,h1_Norm);

  TH1D *h3ovh1_Norm = (TH1D*)h3_Norm->Clone("h3ovh1_Norm");
  h3ovh1_Norm->SetName("h3ovh1_Norm"); 
  h3ovh1_Norm->Divide(h3_Norm,h1_Norm);

  h2ovh1_Norm->GetYaxis()->SetRangeUser(0.,5.);
  h2ovh1_Norm->Draw("P E0");
  h3ovh1_Norm->Draw("P E0 sames");

  lRatio->Draw("same");


  // Print results

  ostringstream tmpLimit;
  tmpLimit << varLimit;
  TString varlimit = tmpLimit.str();

  cout << "Reg1: ";
  TString N1_Abs = "N_Reg1["+branch+"<"+varlimit+"]/N_Reg1["+branch+">"+varlimit+"] = ";
  double N1_Low_Err = 0;  double N1_Low = h1_Abs->IntegralAndError(0,h1_Abs->FindBin(varLimit),N1_Low_Err);     
  double N1_High_Err = 0; double N1_High = h1_Abs->IntegralAndError(h1_Abs->FindBin(varLimit)+1,bins+1,N1_High_Err);
  cout << N1_Abs << N1_Low << "/" << N1_High << " = " << N1_Low/N1_High;
  cout << " +/- " <<   sqrt(pow((N1_Low_Err/N1_High),2)+pow(((N1_Low*N1_High_Err)/(N1_High*N1_High)),2)) << "\n";
  cout << "\n";

  cout << "Reg2: ";
  TString N2_Abs = "N_Reg2["+branch+"<"+varlimit+"]/N_Reg2["+branch+">"+varlimit+"] = ";
  double N2_Low_Err = 0;  double N2_Low = h2_Abs->IntegralAndError(0,h2_Abs->FindBin(varLimit),N2_Low_Err);     
  double N2_High_Err = 0; double N2_High = h2_Abs->IntegralAndError(h2_Abs->FindBin(varLimit)+1,bins+1,N2_High_Err);
  cout << N2_Abs << N2_Low << "/" << N2_High << " = " << N2_Low/N2_High;
  cout << " +/- " <<   sqrt(pow((N2_Low_Err/N2_High),2)+pow(((N2_Low*N2_High_Err)/(N2_High*N2_High)),2)) << "\n";
  cout << "\n";

  cout << "Reg3: ";
  TString N3_Abs = "N_Reg3["+branch+"<"+varlimit+"]/N_Reg3["+branch+">"+varlimit+"] = ";
  double N3_Low_Err = 0;  double N3_Low = h3_Abs->IntegralAndError(0,h3_Abs->FindBin(varLimit),N3_Low_Err);     
  double N3_High_Err = 0; double N3_High = h3_Abs->IntegralAndError(h3_Abs->FindBin(varLimit)+1,bins+1,N3_High_Err);
  cout << N3_Abs << N3_Low << "/" << N3_High << " = " << N3_Low/N3_High;
  cout << " +/- " <<   sqrt(pow((N3_Low_Err/N3_High),2)+pow(((N3_Low*N3_High_Err)/(N3_High*N3_High)),2)) << "\n";
  cout << "\n";


} // ~ end of create1DhistoXinYbins




void DebugPlots(TTree *tree,TCanvas *cCanvas,TH1D *hNJts1Ref,TString intLumi,TString cuts,TString branch,int bins,double xmin,double xmax,
                double xminRange,double xmaxRange,double yminRatio,double ymaxRatio,double fitXmin,double fitXmax,bool useLog) {

  cCanvas->Divide(3,1);

  gStyle->SetOptStat(0);
  // Abs distributions
  cCanvas->cd(1);
  if (useLog) { gPad->SetLogy(); }
  hNJts1Ref->SetName("hNJts1Ref");
  hNJts1Ref->SetLineColor(1);
  hNJts1Ref->SetLineWidth(2);
  hNJts1Ref->SetMarkerColor(1);
  hNJts1Ref->SetMarkerStyle(20);
  hNJts1Ref->SetMarkerSize(0.9);

  TH1D *hNJts2True = create1Dhisto(tree,intLumi,cuts,branch,bins,xmin,xmax,false,false);
  hNJts2True->SetName("hNJts2True");
  hNJts2True->SetLineColor(2);
  hNJts2True->SetLineWidth(2);
  hNJts2True->SetMarkerColor(2);
  hNJts2True->SetMarkerStyle(21);
  hNJts2True->SetMarkerSize(0.9);

  // Draw Legend
  TLegend *lSamples = legendRAW();
  lSamples->AddEntry(hNJts1Ref,"NJts=1[Cor]","PL");
  lSamples->AddEntry(hNJts2True,"NJts=2","FL");

  hNJts1Ref->GetXaxis()->SetTitle(branch);
  if ((branch=="PFLP") || (branch=="LP")) {
    hNJts1Ref->GetYaxis()->SetRangeUser(0.,1.7*(hNJts1Ref->GetBinContent(hNJts1Ref->GetMaximumBin()))); }
  hNJts1Ref->GetXaxis()->SetRangeUser(xminRange,xmaxRange);
  hNJts1Ref->Draw("HIST E0");
  hNJts2True->Draw("HIST E0 sames");
  lSamples->Draw("same");


  // Normalized distributions
  cCanvas->cd(2);
  if (useLog) { gPad->SetLogy(); }
  TH1D *hNJts1Ref_Norm = (TH1D*)hNJts1Ref->Clone("hNJts1Ref_Norm");
  hNJts1Ref_Norm->SetName("hNJts1Ref_Norm");
  hNJts1Ref_Norm->Scale(1./(hNJts1Ref_Norm->Integral()));
  hNJts1Ref_Norm->SetLineColor(1);
  hNJts1Ref_Norm->SetLineWidth(2);
  hNJts1Ref_Norm->SetMarkerColor(1);
  hNJts1Ref_Norm->SetMarkerStyle(20);
  hNJts1Ref_Norm->SetMarkerSize(0.9);

  TH1D *hNJts2True_Norm = create1Dhisto(tree,intLumi,cuts,branch,bins,xmin,xmax,false,false);
  hNJts2True_Norm->SetName("hNJts2True_Norm");
  hNJts2True_Norm->Scale(1./(hNJts2True_Norm->Integral()));
  hNJts2True_Norm->SetLineColor(2);
  hNJts2True_Norm->SetLineWidth(2);
  hNJts2True_Norm->SetMarkerColor(2);
  hNJts2True_Norm->SetMarkerStyle(21);
  hNJts2True_Norm->SetMarkerSize(0.9);

  hNJts1Ref_Norm->GetXaxis()->SetTitle(branch);
  if (branch=="PFLP" || branch=="LP") {
    hNJts1Ref_Norm->GetYaxis()->SetRangeUser(0.,1.7*(hNJts1Ref_Norm->GetBinContent(hNJts1Ref_Norm->GetMaximumBin()))); }
  hNJts1Ref_Norm->GetXaxis()->SetRangeUser(xminRange,xmaxRange);
  hNJts1Ref_Norm->Draw("HIST E0");
  hNJts2True_Norm->Draw("HIST E0 sames");
  lSamples->Draw("same");


  //ratios of the Norm distributions
  cCanvas->cd(3);
  gPad->SetGrid();
  gStyle->SetOptFit(1);

  TH1D *hRatio = (TH1D*)hNJts1Ref->Clone("hRatio");
  hRatio->SetName("hRatio");
  hRatio->Divide(hNJts1Ref,hNJts2True,1.,1.);
  hRatio->GetXaxis()->SetTitle(branch);
  hRatio->GetXaxis()->SetRangeUser(xminRange,xmaxRange);
  hRatio->GetYaxis()->SetRangeUser(yminRatio,ymaxRatio);
  hRatio->Draw("P E0");
  TF1 *fitFunc = new TF1("fitFunc","pol1",fitXmin,fitXmax);
  hRatio->Fit("fitFunc","R");

  TLegend *lSamplesRatio = legendRAW();
  lSamplesRatio->AddEntry(hRatio,"NJts=1[Cor]/NJts=2","PL");

  lSamplesRatio->Draw("same");

} //~end of Debug plots



void createDataVsMCcompRatio(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,TTree *tree_DATAmu,
                             TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog) {

  cCanvas->cd(cPad);

  if (useLog) { gPad->SetLogy(); }

  TH1D *hQCD  = create1Dhisto(tree_MCqcd,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hQCD->Sumw2();
  hQCD->SetName("hQCD");
  TH1D *hW    = create1Dhisto(tree_MCw,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hW->Sumw2();
  hW->SetName("hW");
  TH1D *hZ    = create1Dhisto(tree_MCz,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hZ->Sumw2();
  hZ->SetName("hZ");
  TH1D *hTT   = create1Dhisto(tree_MCtt,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hTT->Sumw2();
  hTT->SetName("hTT");
  TH1D *hSM   = (TH1D*)hW->Clone("hSM"); hSM->Add(hQCD); hSM->Add(hZ); hSM->Add(hTT);
  TH1D *hLM0  = create1Dhisto(tree_MClm0,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hLM0->Sumw2();
  hLM0->SetName("hLM0");
  TH1D *hLM1  = create1Dhisto(tree_MClm1,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hLM1->Sumw2();
  hLM1->SetName("hLM1");
  TH1D *hDATA = create1Dhisto(tree_DATAmu,intLumi,cuts,branch,bins,xmin,xmax,true,useLog);
  //  hDATA->Sumw2();
  hDATA->SetName("hDATA");


  // Colors
  hDATA->SetMarkerColor(1);
  hDATA->SetMarkerSize(1.1);
  hDATA->SetMarkerStyle(21);
  hSM->SetFillStyle(3002);
  hSM->SetFillColor(kGray+2);
  hSM->SetLineColor(kGray+2);
  hSM->SetMarkerSize(0.);
  hQCD->SetLineColor(kYellow+2);
  hQCD->SetMarkerSize(0.);
  hW->SetLineColor(kBlue);
  hW->SetMarkerSize(0.);
  hZ->SetLineColor(kMagenta);
  hZ->SetMarkerSize(0.);
  hTT->SetLineColor(kGreen+3);
  hTT->SetMarkerSize(0.);
  hLM0->SetLineColor(kRed);
  hLM0->SetMarkerSize(0.);
  hLM1->SetLineColor(kRed);
  hLM1->SetLineStyle(2);
  hLM1->SetMarkerSize(0.);


  // Draw
  hDATA->Draw("P E0");
  hSM->Draw("HIST E0 sames");
  hQCD->Draw("HIST E0 sames");
  hW->Draw("HIST E0 sames");
  hZ->Draw("HIST E0 sames");
  hTT->Draw("HIST E0 sames");
  hLM0->Draw("HIST E0 sames");
  hLM1->Draw("HIST E0 sames");
  hDATA->Draw("P E0 sames"); // re-draw to be on top

  // Draw Legend
  TLegend *lSamples = legendRAW();
  lSamples->AddEntry(hDATA,"DATA","PL");
  lSamples->AddEntry(hQCD,"QCD","FL");
  lSamples->AddEntry(hW,"W","FL");
  lSamples->AddEntry(hZ,"Z","FL");
  lSamples->AddEntry(hTT,"TTbar","FL");
  lSamples->AddEntry(hLM0,"LM0","FL");
  lSamples->AddEntry(hLM1,"LM1","FL");
  lSamples->AddEntry(hSM,"SM","FL");
  lSamples->Draw("same");

  TLatex *lPreliminary = new TLatex(0.2,0.82,"CMS Preliminary 2010");
  TLatex *lIntLumi = new TLatex(0.2,0.89,"#scale[0.8]{#int L dt = " +intLumi+"pb^{-1}, #sqrt{s} = 7 TeV}");
  lPreliminary->SetNDC();
  lIntLumi->SetNDC();
  //  lPreliminary->Draw("same");
  lIntLumi->Draw("same");

  cCanvas->cd(cPad+maxPads);
  //  cCanvas->cd(cPad+1);
  gPad->SetGridx(); gPad->SetGridy();
  TH1D *hRatio = (TH1D*)hDATA->Clone("hRatio");
  //  hRatio->Sumw2();
  hRatio->Divide(hDATA,hSM);
  hRatio->GetYaxis()->SetTitle("DATA / MC [SM]");
  hRatio->GetXaxis()->SetTitle("");
  hRatio->GetYaxis()->SetRangeUser(0.,2.);
  hRatio->SetTitleSize(0.1, "XYZ");
  hRatio->SetTitleOffset(0.65, "X");
  hRatio->SetTitleOffset(0.6, "Y");
  hRatio->SetLabelSize(0.08,"XY");

  //Draw a line though the perfectly matching point
  TBox *unity = new TBox(hRatio->GetXaxis()->GetBinLowEdge(hRatio->GetXaxis()->GetFirst()),
                         0.89,hRatio->GetXaxis()->GetXmax(), 1.11);
  unity->SetLineWidth(2);
  //unity.SetLineStyle(Root.kDashed);
  unity->SetLineColor(2);
  unity->SetFillColor(2);
  unity->SetFillStyle(3002);
  unity->Draw();

  hRatio->Draw("P E0");
  unity->Draw();

  cCanvas->Update();

} // ~ end of createDataVsMCcomp


  

void create1DMCcomp(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,
                    TCanvas *cCanvas,int cPad,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog,bool norm) {

  cCanvas->cd(cPad);

  if (useLog) { gPad->SetLogy(); }

  TH1D *hQCD  = create1Dhisto(tree_MCqcd,intLumi,cuts,branch,bins,xmin,xmax,useLog);
  //  hQCD->Sumw2();
  hQCD->SetName("hQCD");
  if (norm) { hQCD->Scale(1./hQCD->Integral()); }
  TH1D *hW    = create1Dhisto(tree_MCw,intLumi,cuts,branch,bins,xmin,xmax,useLog);
  //  hW->Sumw2();
  hW->SetName("hW");
  if (norm) { hW->Scale(1./hW->Integral()); }
  TH1D *hZ    = create1Dhisto(tree_MCz,intLumi,cuts,branch,bins,xmin,xmax,useLog);  
  //  hZ->Sumw2();
  hZ->SetName("hZ");
  if (norm) { hZ->Scale(1./hZ->Integral()); }
  TH1D *hTT   = create1Dhisto(tree_MCtt,intLumi,cuts,branch,bins,xmin,xmax,useLog);
  //  hTT->Sumw2();
  hTT->SetName("hTT");
  if (norm) { hTT->Scale(1./hTT->Integral()); }
  TH1D *hSM   = (TH1D*)hW->Clone("hSM"); hSM->Add(hQCD); hSM->Add(hZ); hSM->Add(hTT);
  TH1D *hLM0  = create1Dhisto(tree_MClm0,intLumi,cuts,branch,bins,xmin,xmax,useLog);
  //  hLM0->Sumw2();
  hLM0->SetName("hLM0");
  if (norm) { hLM0->Scale(1./hLM0->Integral()); }
  TH1D *hLM1  = create1Dhisto(tree_MClm1,intLumi,cuts,branch,bins,xmin,xmax,useLog);
  //  hLM1->Sumw2();
  hLM1->SetName("hLM1");
  if (norm) { hLM1->Scale(1./hLM1->Integral()); }


  // Colors                                                                                                                                                  
  hSM->SetFillStyle(3002);
  hSM->SetFillColor(kGray+2);
  hSM->SetLineColor(kGray+2);
  hSM->SetMarkerSize(0.);
  hQCD->SetLineColor(kYellow+2);
  hQCD->SetMarkerSize(0.);
  hW->SetLineColor(kBlue);
  hW->SetMarkerSize(0.);
  hZ->SetLineColor(kMagenta);
  hZ->SetMarkerSize(0.);
  hTT->SetLineColor(kGreen+3);
  hTT->SetMarkerSize(0.);
  hLM0->SetLineColor(kRed);
  hLM0->SetMarkerSize(0.);
  hLM1->SetLineColor(kRed);
  hLM1->SetLineStyle(2);
  hLM1->SetMarkerSize(0.);


  // Draw
  //  hSM->Draw("HIST");
  if (norm) { hW->GetYaxis()->SetRangeUser(0.,0.5); }
  hW->Draw("HIST E0");
  //  hQCD->Draw("HIST E0 sames");
  //  hZ->Draw("HIST E0 sames");
  hTT->Draw("HIST E0 sames");
  hLM0->Draw("HIST E0 sames");
  hLM1->Draw("HIST E0 sames");


  // Draw Legend
  TLegend *lSamples = legendRAW();
  //  lSamples->AddEntry(hQCD,"QCD","FL");
  lSamples->AddEntry(hW,"W","FL");
  //  lSamples->AddEntry(hZ,"Z","FL");
  lSamples->AddEntry(hTT,"TTbar","FL");
  lSamples->AddEntry(hLM0,"LM0","FL");
  lSamples->AddEntry(hLM1,"LM1","FL");
  //  lSamples->AddEntry(hSM,"SM","FL");
  lSamples->Draw("same");

  TLatex *lPreliminary = new TLatex(0.2,0.82,"CMS Preliminary 2010");
  TLatex *lIntLumi = new TLatex(0.2,0.89,"#scale[0.8]{#int L dt = " +intLumi+"pb^{-1}, #sqrt{s} = 7 TeV}");
  lPreliminary->SetNDC();
  lIntLumi->SetNDC();
  //  lPreliminary->Draw("same");
  lIntLumi->Draw("same");

  cCanvas->Update();

} // ~ end of create1DMCcomp





void create1DMCcompRatio(TTree *tree_MCw,TTree *tree_MCtt,TTree *tree_MClm0,TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,
			 TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog) {

  cCanvas->cd(cPad);

  if (useLog) { gPad->SetLogy(); }

  TString CutsPos = cuts+" && MuonChrg[0] > 0.4";
  TString CutsNeg = cuts+" && MuonChrg[0] < -0.4";

  // Histos
  TH1D *hWpos    = create1Dhisto(tree_MCw,intLumi,CutsPos,branch,bins,xmin,xmax,useLog);
  hWpos->Sumw2();
  hWpos->SetName("hWpos");
  //  hWpos->Scale(1./(hWpos->Integral()));
  //  hWpos->GetYaxis()->SetRangeUser(0.,0.27);
  TH1D *hTTpos   = create1Dhisto(tree_MCtt,intLumi,CutsPos,branch,bins,xmin,xmax,useLog);
  hTTpos->Sumw2();
  //  hTTpos->Scale(1./(hTTpos->Integral()));
  hTTpos->SetName("hTTpos");
  TH1D *hLM0pos  = create1Dhisto(tree_MClm0,intLumi,CutsPos,branch,bins,xmin,xmax,useLog);
  hLM0pos->Sumw2();
  //  hLM0pos->Scale(1./(hLM0pos->Integral()));
  hLM0pos->SetName("hLM0pos");
  TH1D *hWneg    = create1Dhisto(tree_MCw,intLumi,CutsNeg,branch,bins,xmin,xmax,useLog);
  hWneg->Sumw2();
  //  hWneg->Scale(1./(hWneg->Integral()));
  hWneg->SetName("hWneg");
  TH1D *hTTneg   = create1Dhisto(tree_MCtt,intLumi,CutsNeg,branch,bins,xmin,xmax,useLog);
  hTTneg->Sumw2();
  //  hTTneg->Scale(1./(hTTneg->Integral()));
  hTTneg->SetName("hTTneg");
  TH1D *hLM0neg  = create1Dhisto(tree_MClm0,intLumi,CutsNeg,branch,bins,xmin,xmax,useLog);
  hLM0neg->Sumw2();
  //  hLM0neg->Scale(1./(hLM0neg->Integral()));
  hLM0neg->SetName("hLM0neg");


  // Colors
  hWpos->SetLineColor(kBlue);
  hWpos->SetMarkerSize(0.);
  hTTpos->SetLineColor(kGreen+3);
  hTTpos->SetMarkerSize(0.);
  hLM0pos->SetLineColor(kRed);
  hLM0pos->SetMarkerSize(0.);
  hWneg->SetLineColor(kBlue);
  hWneg->SetLineStyle(2);
  hWneg->SetMarkerSize(0.);
  hTTneg->SetLineColor(kGreen+3);
  hTTneg->SetLineStyle(2);
  hTTneg->SetMarkerSize(0.);
  hLM0neg->SetLineColor(kRed);
  hLM0neg->SetLineStyle(2);
  hLM0neg->SetMarkerSize(0.);
    

  // Draw
  hWpos->Draw("HIST E0");
  hTTpos->Draw("HIST E0 sames");
  hLM0pos->Draw("HIST E0 sames");
  hWneg->Draw("HIST E0 sames");
  hTTneg->Draw("HIST E0 sames");
  hLM0neg->Draw("HIST E0 sames");

  
  // Draw Legend
  TLegend *lSamples = legendRAW();
  lSamples->AddEntry(hWpos,"W(+)","FL");
  lSamples->AddEntry(hWneg,"W(-)","FL");
  lSamples->AddEntry(hTTpos,"TTbar(+)","FL");
  lSamples->AddEntry(hTTneg,"TTbar(-)","FL");
  lSamples->AddEntry(hLM0pos,"LM0(+)","FL");
  lSamples->AddEntry(hLM0neg,"LM0(-)","FL");
  lSamples->Draw("same");

  cout << "W+: " << hWpos->Integral(0,bins+1) << "\n";
  cout << "W-: " << hWneg->Integral(0,bins+1) << "\n";
  cout << "TT+: " << hTTpos->Integral(0,bins+1) << "\n";
  cout << "TT-: " << hTTneg->Integral(0,bins+1) << "\n";
  cout << "LM0+: " << hLM0pos->Integral(0,bins+1) << "\n";
  cout << "LM0-: " << hLM0neg->Integral(0,bins+1) << "\n";
  cout << "\n";

  TLatex *lPreliminary = new TLatex(0.2,0.82,"CMS Preliminary 2010");
  TLatex *lIntLumi = new TLatex(0.2,0.89,"#scale[0.8]{#int L dt = " +intLumi+"pb^{-1}, #sqrt{s} = 7 TeV}");
  lPreliminary->SetNDC();
  lIntLumi->SetNDC();
  //  lPreliminary->Draw("same"); 
  lIntLumi->Draw("same"); 


  cCanvas->cd(cPad+maxPads);

  gPad->SetGridx(); gPad->SetGridy();
  TH1D *hRatio = (TH1D*)hWpos->Clone("hRatio");
  hRatio->Divide(hWpos,hWneg);
  hRatio->GetYaxis()->SetTitle("W[+] / W[-]");
  hRatio->GetXaxis()->SetTitle("");
  hRatio->GetYaxis()->SetRangeUser(0.,4.);
  hRatio->SetTitleSize(0.1, "XYZ");
  hRatio->SetTitleOffset(0.65, "X");
  hRatio->SetTitleOffset(0.6, "Y");
  hRatio->SetLabelSize(0.08,"XY");

  //Draw a line though the perfectly matching point
  TBox *unity = new TBox(hRatio->GetXaxis()->GetBinLowEdge(hRatio->GetXaxis()->GetFirst()),
                         0.99,hRatio->GetXaxis()->GetXmax(), 1.01);
  unity->SetLineWidth(2);
  //unity.SetLineStyle(Root.kDashed);
  unity->SetLineColor(1);
  unity->SetLineStyle(2);
  unity->SetFillColor(0);
  unity->SetFillStyle(3002);
  unity->Draw();

  hRatio->Draw("P E0");

  
  cCanvas->Update();

} // ~ end of createMCcompRatio




TH1D *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog) {

  TString cut ="(wgt*"+intLumi+")*("+cuts+")";
 
  TH1D *hTemp = new TH1D("hTemp","hTemp",bins,xmin,xmax);
  hTemp->Sumw2();
  tree->Project("hTemp",branch,cut);
  
  if (useLog) {
    hTemp->GetYaxis()->SetRangeUser(0.1,50.*(hTemp->GetBinContent(hTemp->GetMaximumBin())));
  } 
  else if (!useLog) {
    hTemp->GetYaxis()->SetRangeUser(0.,1.4*(hTemp->GetBinContent(hTemp->GetMaximumBin())));
  }
  hTemp->SetLineWidth(3);
  hTemp->GetXaxis()->SetTitle(branch);
  
  return hTemp;
} //~ end of create1Dhisto





TH1D *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool DATA,bool useLog) {

  TString cut;

  if (!DATA) {cut ="(wgt*"+intLumi+")*("+cuts+")"; }
  else if (DATA) { cut ="(wgt)*("+cuts+")"; }


  TH1D *hTemp = new TH1D("hTemp","hTemp",bins,xmin,xmax);
  hTemp->Sumw2();
  tree->Project("hTemp",branch,cut);

  if ( (useLog) && (DATA) ) {
    hTemp->GetYaxis()->SetRangeUser(0.1,50.*(hTemp->GetBinContent(hTemp->GetMaximumBin())));
  }
  else if ( (!useLog) && (DATA) ) {
    hTemp->GetYaxis()->SetRangeUser(0.,2.*(hTemp->GetBinContent(hTemp->GetMaximumBin())));
  }
  hTemp->SetLineWidth(3);
  hTemp->GetXaxis()->SetTitle(branch);

  return hTemp;
} //~ end of create1Dhisto





TH2D *create2Dhisto(TTree *tree,TString intLumi,TString cuts,TString branchX,int binsX,float xmin,float xmax,
		    TString branchY,int binsY,float ymin,float ymax, bool DATA) {
  
  TString cut;

  if (!DATA) {cut ="(wgt*"+intLumi+")*("+cuts+")"; }
  else if (DATA) {cut = "(wgt)*("+cuts+")"; }

 
  TH2D *hTemp = new TH2D("hTemp","hTemp",binsX,xmin,xmax,binsY,ymin,ymax);
  hTemp->Sumw2();
  tree->Project("hTemp",branchY+":"+branchX,cut);
 
  hTemp->GetXaxis()->SetTitle(branchX);
  hTemp->GetYaxis()->SetTitle(branchY);
  
  return hTemp;
} //~ end of create1Dhisto


/*
TH2D *create2Dhisto(TTree *tree,TString intLumi,TString cuts,TString branchX,int binsX,float xmin,float xmax,
		    TString branchY,int binsY,float ymin,float ymax, bool DATA) {
  
  TString cut;
  
  if (!DATA) {cut ="(wgt*"+intLumi+")*("+cuts+")"; }
  else if (DATA) { cut ="(wgt)*("+cuts+")"; }

  
  TH2D *hTemp = new TH2D("hTemp","hTemp",binsX,xmin,xmax,binsY,ymin,ymax);
  tree->Project("hTemp",branchY+":"+branchX,cut);
 
  hTemp->GetXaxis()->SetTitle(branchX);
  hTemp->GetYaxis()->SetTitle(branchY);
  
  return hTemp;
} //~ end of createProfile2Dhisto
*/



TH1D *Divide2Histos(const TH1D* HistoInput1,const TH1D* HistoInput2) {
  TH1::SetDefaultSumw2(true);

  TH1D *HistoOutput = (TH1D*)HistoInput1->Clone();
  HistoOutput->Sumw2();
  HistoOutput->SetName("HistoOutput");

  HistoOutput->Divide(HistoOutput, HistoInput2,1.,1.); //,"B"                                                                                                                          

  //error propagation calculation -> f=a/b .. a,da & b,db
  const int numOfBins = HistoInput1->GetNbinsX();
  float error = 0.;
  float a, da, b, db = 0;
  for (int i=0; i<=numOfBins; i++) {
    error = 0.;
    a = da = b = db =0;
    a  = HistoInput1->GetBinContent(i);
    da = HistoInput1->GetBinError(i);
    b  = HistoInput2->GetBinContent(i);
    db = HistoInput2->GetBinError(i);
    if (b != 0) {
      error = sqrt( pow((da/b),2) + pow(((-1.*a*db)/(b*b)),2));
      HistoOutput->SetBinError(i,error);
    } // end of if                                                                                                                                  
  } // end of for loop                                                                                                                                

  return HistoOutput;
}




TCanvas* createCanvas(TString name,int xlen,int ylen,bool logOn) {

  TCanvas* aCanvas = new TCanvas(name,name,xlen,ylen);

  if (logOn==true) { gPad->SetLogy(); }

  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);

  return aCanvas;
}




TCanvas* createCanvas(TString name,int xlen,int ylen,int xDiv,bool logOn) {

  TCanvas* aCanvas = new TCanvas(name,name,xlen,ylen);

  float xstep = 1./xDiv;

  for (int i1=1; i1<=xDiv; i1++) {

    TPad *mainPad = new TPad("","",0.01+((i1-1)*xstep),0.25,(i1*xstep)-0.01,0.99);
    mainPad->SetNumber(i1);
    mainPad->Draw();

    TPad *ratioPad = new TPad("","",0.01+((i1-1)*xstep),0.01,(i1*xstep)-0.01,0.25);
    ratioPad->SetNumber(i1+xDiv);
    ratioPad->Draw();
  }

  if (logOn==true) { gPad->SetLogy(); }

  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);

  return aCanvas;
}



TLegend *legendRAW() {
 
  TLegend *leg = new TLegend(0.75,0.7,0.92,0.93);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);

  return leg;
}



void decomposeMEff(TH1D *hTempMean,TH1D *hTempRMS,TTree *tree,double MHTcut,double METcut,double HTcut,double LPmin,double LPmax) {


  Int_t nentries = (Int_t)tree->GetEntries();

  // variables from tree to cut or plot
  double wgt;
  int NJet;
  double JetPt[50];
  double JetEta[50];
  int NMuons;
  double MuonPt[20];
  double MuonEta[20];
  double MuonChrg[20];
  double HT;
  double HT_Lep;
  double PFMHT;
  double PFMET;
  double PFMT;
  double PFLP;
  double Meff;

  tree->SetBranchAddress("wgt",&wgt);
  tree->SetBranchAddress("NJet",&NJet);
  tree->SetBranchAddress("JetPt",JetPt);
  tree->SetBranchAddress("JetEta",JetEta);
  tree->SetBranchAddress("NMuons",&NMuons);
  tree->SetBranchAddress("MuonPt",MuonPt);
  tree->SetBranchAddress("MuonEta",MuonEta);
  tree->SetBranchAddress("MuonChrg",MuonChrg);
  tree->SetBranchAddress("HT",&HT);
  tree->SetBranchAddress("HT_Lep",&HT_Lep);
  tree->SetBranchAddress("PFMHT",&PFMHT);
  tree->SetBranchAddress("PFMET",&PFMET);
  tree->SetBranchAddress("PFMT",&PFMT);
  tree->SetBranchAddress("PFLP",&PFLP);
  tree->SetBranchAddress("Meff",&Meff);


  TH1D *hRelMuPt = new TH1D("hRelMuPt","hRelMuPt",100,0.,1.); 
  TH1D *hRelMET  = new TH1D("hRelMET","hRelMET",100,0.,1.); 
  TH1D *hRelHT   = new TH1D("hRelHT","hRelHT",100,0.,1.); 

  for (Int_t i=1; i<=nentries; i++) {
  //  for (Int_t i=0; i<1000; i++) {
    tree->GetEntry(i);

    // apply cuts
    if (NMuons!=1)                                   continue;
    if ((MuonPt[0]<=20.) || (fabs(MuonEta[0])>=2.1)) continue;
    //    if (MuonChrg[0]>-0.2)                            continue;
    if (NJet!=1)                                     continue;
    if ((JetPt[0]<=30.) || (fabs(JetEta[0])>=2.4))   continue;
    if (HT<HTcut)                                    continue;
    if (PFMHT<=MHTcut)                               continue;
    if (PFMET<=METcut)                               continue;                                                                                           
    if (PFMT<=30.)                                   continue;
    if ((PFLP<LPmin) || (PFLP>=LPmax))               continue;


    //    cout << "Meff= " << Meff << " | " << "pT[mu]= " << MuonPt[0] << ", PFMET= " << PFMET << ", HT= " << HT << "\n";
    //    cout << "; Meff'= " << MuonPt[0]+PFMET+HT << "\n";
    //    cout << "Relative Fraction of Meff: " << "pT[mu]/Meff= " << MuonPt[0]/Meff << ", PFMET/Meff= " << PFMET/Meff << ", HT/Meff= " << HT/Meff << "\n";

    hRelMuPt->Fill(MuonPt[0]/Meff);
    hRelMET->Fill(PFMET/Meff);
    hRelHT->Fill(HT/Meff);

  } // ~ end of looping over all tree entries


  hTempMean->SetBinContent(1,hRelMuPt->GetMean());
  hTempMean->SetBinContent(2,hRelMET->GetMean());
  hTempMean->SetBinContent(3,hRelHT->GetMean());

  hTempRMS->SetBinContent(1,hRelMuPt->GetRMS());
  hTempRMS->SetBinContent(2,hRelMET->GetRMS());
  hTempRMS->SetBinContent(3,hRelHT->GetRMS());

  delete hRelMuPt;
  delete hRelMET;
  delete hRelHT;

} // ~end of decomposeMEff function



// calculate the S/sqrt(B) for different cases
TH1D *calculateSignificance(TTree *tMCqcd,TTree *tMCz,TTree *tMCw,TTree *tMCtt,TTree *tMClm0,TTree *tMClm1,
			    TString lumi,TString Cut,TString var,int bins,double min,double max) {
  
  TH1D *hQCD = create1Dhisto(tMCqcd,lumi,Cut,var,bins,min,max,false,false); hQCD->SetName("hQCD");
  TH1D *hZ   = create1Dhisto(tMCz,lumi,Cut,var,bins,min,max,false,false);   hZ->SetName("hZ");
  TH1D *hW   = create1Dhisto(tMCw,lumi,Cut,var,bins,min,max,false,false);   hW->SetName("hW");
  TH1D *hTT  = create1Dhisto(tMCtt,lumi,Cut,var,bins,min,max,false,false);  hTT->SetName("hTT");
  TH1D *hSM = (TH1D*)hW->Clone("hSM"); hSM->Add(hQCD); hSM->Add(hZ); hSM->Add(hTT);
  
  TH1D *hLM0  = create1Dhisto(tMClm0,lumi,Cut,var,bins,min,max,false,false); hLM0->SetName("hLM0");
  TH1D *hLM1  = create1Dhisto(tMClm1,lumi,Cut,var,bins,min,max,false,false); hLM1->SetName("hLM0");
  
  double start = 200.; double end = 700.; double step = 50.; int numOfSteps = ((end-start)/step)+1; 
  TH1D *hTemp = new TH1D("hTemp","hTemp",numOfSteps,175,725);
  hTemp->SetName("hTemp");
  
  double counter = start;
  for (int i=0; i<numOfSteps+1; i++) {
    
    double significance = (hLM1->Integral(hLM1->FindBin(counter),bins+1))/(sqrt(hSM->Integral(hSM->FindBin(counter),bins+1)));
    //double sigError = sqrt(pow((),2)+pow((),2));
    hTemp->SetBinContent(i+1,significance);
    //      hTemp->SetBinError(i+1,sigError);

    counter+=step;
  }

  hTemp->GetXaxis()->SetTitle(var);
  hTemp->GetYaxis()->SetTitle("S/#sqrt{B}");
  
  return hTemp;
} // ~ end of calculate significance function
