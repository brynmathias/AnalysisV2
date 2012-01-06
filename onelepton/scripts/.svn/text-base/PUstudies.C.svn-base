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

//#include "<direct.h>"
void setTDRStyle();
using namespace std;

#endif



TH1D *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog);
TLegend *legendRAW();



void mainFunction() {

  setTDRStyle();
  gROOT->SetBatch(false);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);
  gStyle->SetPalette(1);

  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(3);



  // --- Integrated Lumi [pb^{-1}]

  float intLumi = 300.;

  ostringstream tmpLumi;
  tmpLumi << intLumi;
  TString lumi = tmpLumi.str();


 
  //  -- Open files
  TString filename_MCsm   = "/vols/cms02/gouskos/onelepton/20111115_El_Sel_HT300_Tree/sm.root";
  TString filename_MCw    = "/vols/cms02/gouskos/onelepton/20111115_El_Sel_HT300_Tree/w.root";
  TString filename_MCtt   = "/vols/cms02/gouskos/onelepton/20111115_El_Sel_HT300_Tree/tt.root";
  TString filename_MClm1  = "/vols/cms02/gouskos/onelepton/20111115_El_Sel_HT300_Tree/tt.root";
  TString filename_DATAht = "/vols/cms02/gouskos/onelepton/20111115_El_Sel_HT300_Tree/data.root";
  //  TString filename_DATAht = "../DATA/20110513_GoldenJson/MuHad_2011.root";

  TFile *f_MCsm   = TFile::Open(filename_MCsm,"READONLY");
  TFile *f_MCw    = TFile::Open(filename_MCw,"READONLY");
  TFile *f_MCtt   = TFile::Open(filename_MCtt,"READONLY");
  TFile *f_MClm1  = TFile::Open(filename_MClm1,"READONLY");
  TFile *f_DATAht = TFile::Open(filename_DATAht,"READONLY");


  TString treeFolder = "ElectronTree/";
  TTree *tree_MCsm   = (TTree*)f_MCsm->Get(treeFolder+"T");
  TTree *tree_MCw    = (TTree*)f_MCw->Get(treeFolder+"T");
  TTree *tree_MCtt   = (TTree*)f_MCtt->Get(treeFolder+"T");
  TTree *tree_MClm1  = (TTree*)f_MClm1->Get(treeFolder+"T");
  TTree *tree_DATAht = (TTree*)f_DATAht->Get(treeFolder+"T");



  // -- Define Cuts

  TString Cut = "NElectrons>0 && ElectronPt[0]>20.";
  //  TString Cut = "MuonPt[0]>0.";






  // ------------------------------------------------------------------------------------------------ //


  TString var = "NumPVs"; int bins = 35; double xmin = -0.5; double xmax = 34.5; bool log = false; TString varName = "L_{P}"; 
  //  TString var = "PFMHT_h"; int bins = 100; double xmin = -0.; double xmax = 1000.; bool log = true; TString varName = "MH_{T}"; 


  // Draw the NumOfPVs for MC and DATA
  TCanvas *cPU = new TCanvas("cPU","cPU",400,400);

  
  TH1D *hW = create1Dhisto(tree_MCw,lumi,Cut,var,bins,xmin,xmax,log); hW->SetName("hW");
  hW->SetLineColor(4);   hW->SetLineStyle(1);    hW->SetLineWidth(3);
  hW->SetMarkerColor(4); hW->SetMarkerStyle(20); hW->SetMarkerSize(0.);  
  
  TH1D *hTT = create1Dhisto(tree_MCtt,lumi,Cut,var,bins,xmin,xmax,log); hTT->SetName("hTT");
  hTT->Scale(1./(hTT->Integral()));
  hTT->SetLineColor(kGreen+2);   hTT->SetLineStyle(1);    hTT->SetLineWidth(3);
  hTT->SetMarkerColor(kGreen+2); hTT->SetMarkerStyle(20); hTT->SetMarkerSize(0.);  

  TH1D *hLM1 = create1Dhisto(tree_MClm1,lumi,Cut,var,bins,xmin,xmax,log); hLM1->SetName("hLM1");
  hLM1->Scale(1./(hLM1->Integral()));
  hLM1->SetLineColor(2);   hLM1->SetLineStyle(1);    hLM1->SetLineWidth(3);
  hLM1->SetMarkerColor(2); hLM1->SetMarkerStyle(20); hLM1->SetMarkerSize(0.);  

  TH1D *hSM = create1Dhisto(tree_MCsm,lumi,Cut,var,bins,xmin,xmax,log); hSM->SetName("hSM");
  hSM->SetLineColor(4);   hSM->SetLineStyle(1);    hSM->SetLineWidth(3);
  hSM->SetMarkerColor(4); hSM->SetMarkerStyle(20); hSM->SetMarkerSize(0.);  
  
  TH1D *hDATA = create1Dhisto(tree_DATAht,lumi,Cut,var,bins,xmin,xmax,log); hDATA->SetName("hDATA");
  hDATA->SetLineColor(1);   hDATA->SetLineStyle(1);    hDATA->SetLineWidth(3);
  hDATA->SetMarkerColor(1); hDATA->SetMarkerStyle(20); hDATA->SetMarkerSize(0.);  

  TH1D *hSM_Norm = (TH1D*)hSM->Clone("hSM_Norm"); hSM_Norm->SetName("hSM_Norm");
  hSM_Norm->Scale(1./(hSM_Norm->Integral()));

  TH1D *hDATA_Norm = (TH1D*)hDATA->Clone("hDATA_Norm"); hDATA_Norm->SetName("hDATA_Norm");
  hDATA_Norm->Scale(1./(hDATA_Norm->Integral()));


  hTT->GetXaxis()->SetTitle("NumOfPVs");
  hTT->Draw("HIST");
  hLM1->Draw("HIST sames");
  hDATA->Draw("HIST sames");


  // calculate the weight factors
  TCanvas *cFactors = new TCanvas("cFactors","cFactors",400,400);

  TH1D *hFactors = (TH1D*)hDATA_Norm->Clone("hFactors"); hFactors->SetName("hFactors");
  hFactors->Divide(hDATA_Norm,hSM_Norm,1.,1.);
  hFactors->GetXaxis()->SetTitle("NumOfPVs");
  hFactors->Draw("HIST");

  // cout the factors
  for (int i=1; i<hFactors->GetNbinsX()+1; i++) {
    //    cout << "NumOfPVs = " << i << " , ";
    cout << hFactors->GetBinContent(i) << ", "; 
  }


  TFile f("PVReWeightingFactors_HT300.root","recreate");
  hSM->Write();
  hDATA->Write();
  hFactors->Write();
  f.Close();




} // ~ end of main function


  // ----------------
  // Help Functions





TH1D *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog) {
  TH1::SetDefaultSumw2(kTRUE);
  
  //  TString cut ="(wgt*"+intLumi+")*("+cuts+")";
   TString cut ="("+intLumi+")*("+cuts+")";


  TH1D *hTemp = new TH1D("hTemp","hTemp",bins,xmin,xmax);
  tree->Project("hTemp",branch,cut);
  
  if (useLog) {
    hTemp->GetYaxis()->SetRangeUser(0.1,50.*(hTemp->GetBinContent(hTemp->GetMaximumBin())));
  } 
  else if (!useLog) {
    hTemp->GetYaxis()->SetRangeUser(0.,2.*(hTemp->GetBinContent(hTemp->GetMaximumBin())));
  }
  hTemp->SetLineWidth(3);
  hTemp->GetXaxis()->SetTitle(branch);
  
  return hTemp;
} //~ end of create1Dhisto



TLegend *legendRAW() {
 
  TLegend *leg = new TLegend(0.75,0.7,0.92,0.93);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);

  return leg;
}
