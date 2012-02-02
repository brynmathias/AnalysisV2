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



TH1D *plot1Dhisto(double intLumi,TFile *fileName,TString folderName,TString histoName,int color,int rebin,float xMin,float xMax,TString xName, TString yName,TString sampleName,bool mc);
void createDataVsMCcompRatio(double intLumi,TFile *fQCD,TFile *fZ,TFile *fW,TFile *fTT,TFile *flm1,TFile *fDATA,TCanvas *cCanvas,int cPad,int maxPads,
			     TString folderName,TString histoName,int rebin,float xMin,float xMax,TString xName, TString yName,bool useLog);
TCanvas* createCanvas(TString name,int xlen,int ylen,int xDiv,bool logOn);
TLegend *legendRAW();


void mainFunction() {

  setTDRStyle();
  gROOT->SetBatch(false);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(1);


  // INt Lumi
  double intLumi = 131.;



  // -- MC filenames
  TString filename_MCqcd = "/vols/cms02/gouskos/onelepton/20110506_MC_GoldenPVReWeight/QCD_Pythia6.root";
  TString filename_MCz   = "/vols/cms02/gouskos/onelepton/20110506_MC_GoldenPVReWeight/Z_Madgraph.root";
  TString filename_MCw   = "/vols/cms02/gouskos/onelepton/20110506_MC_GoldenPVReWeight/W_Madgraph.root";
  TString filename_MCtt  = "/vols/cms02/gouskos/onelepton/20110506_MC_GoldenPVReWeight/TT_Madgraph.root";
  TString filename_MClm1 = "/vols/cms02/gouskos/onelepton/20110506_MC_GoldenPVReWeight/LM1.root";


  // -- DATA filenames
  TString filename_DATAmu = "/vols/cms02/gouskos/onelepton/20110506_DATA_GoldenJson/MuHad_2011.root";


  // -- Open MC files
  TFile *f_MCqcd = TFile::Open(filename_MCqcd,"READONLY");
  TFile *f_MCz   = TFile::Open(filename_MCz,"READONLY");
  TFile *f_MCw   = TFile::Open(filename_MCw,"READONLY");
  TFile *f_MCtt  = TFile::Open(filename_MCtt,"READONLY");
  TFile *f_MClm1 = TFile::Open(filename_MClm1,"READONLY");


  // -- Open DATA files
  TFile *f_DATAmu = TFile::Open(filename_DATAmu,"READONLY");


  TString folderName = "MuonStandardPlots_Loukas";
  //  TString folderName = "MuonStandardPlots_PostMHT200";


  // save canvas?
  bool savePlots = false;



  // do the DATA-MC comparison

  
  // Muon variables
  
  TCanvas *cPtMu = createCanvas("cPtMu",500,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cPtMu,1,1,folderName,"Pt_all",25,0.,500.,"p_{T}[#mu]","Entries / bin",true);
  
  TCanvas *cEtaMu = createCanvas("cEtaMu",400,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cEtaMu,1,1,folderName,"lepEta_all",5,-2.5,2.5,"#eta[#mu]","Entries / bin",true);


  
  // Jet variables
  
  TCanvas *cNJet = createCanvas("cNJet",400,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cNJet,1,1,folderName,"Njet_all",1,0.,10.,"N_{jets}","Entries / bin",true);
  
  TCanvas *cPtJet1 = createCanvas("cPtJet1",400,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cPtJet1,1,1,folderName,"jet1Et_all",25,0.,1000.,"p_{T}[jet1]","Entries / bin",true);

  TCanvas *cEtaJet1 = createCanvas("cEtaJet1",400,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cEtaJet1,1,1,folderName,"jet1Eta_all",5,-3.5,3.5,"#eta[jet1]","Entries / bin",true);

  TCanvas *cPtJet2 = createCanvas("cPtJet2",400,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cPtJet2,1,1,folderName,"jet2Et_all",25,0.,700.,"p_{T}[jet2]","Entries / bin",true);

  TCanvas *cEtaJet2 = createCanvas("cEtaJet2",400,800,1,true);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cEtaJet2,1,1,folderName,"jet2Eta_all",5,-3.5,3.5,"#eta[jet2]","Entries / bin",true);
  

  
  // General Variables
  
  TCanvas *cLP_Pos = createCanvas("cLP_Pos",400,800,1,false); 
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cLP_Pos,1,1,folderName,"LPPlusvar_all",10,-0.6,1.4,"L_{P}[+]","Entries / bin",false);
  
  TCanvas *cLP_Neg = createCanvas("cLP_Neg",400,800,1,false); 
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cLP_Neg,1,1,folderName,"LPMinusvar_all",10,-0.6,1.4,"L_{P}[-]","Entries / bin",false);
  
  TCanvas *cPFMHT = createCanvas("cPFMHT",400,800,1,false); 
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cPFMHT,1,1,folderName,"pfMHT_all",25,-0.,700,"MHT [GeV]","Entries / bin",true);
  
  TCanvas *cPFMT = createCanvas("cPFMT",400,800,1,false);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cPFMT,1,1,folderName,"M_{T}_all",10,-0.,400.,"pfM_{T} [GeV]","Entries / bin",true);

  TCanvas *cHTlep = createCanvas("cHTlep",400,800,1,false); 
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cHTlep,1,1,folderName,"H_{T}^{lep}_all",10,200.,2000.,"H_{T}^{lep} [GeV]","Entries / bin",true);

  TCanvas *cMeffa = createCanvas("cMeffa",400,800,1,false);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cMeffa,1,1,folderName,"Meff_all",10,300.,2000.,"M_{eff} [GeV]","Entries / bin",true);

  TCanvas *cMeffb = createCanvas("cMeffb",400,800,1,false);
  createDataVsMCcompRatio(intLumi,f_MCqcd,f_MCz,f_MCw,f_MCtt,f_MClm1,f_DATAmu,cMeffb,1,1,folderName,"Meff'_all",10,300.,2000.,"M_{eff}^{'} [GeV]","Entries / bin",true);
  


  if (savePlots) {
    TString plotsFolder = "DATAvsMC_Muons_20110509/";
    cPtMu->Print("./Plots/"+plotsFolder+"PtMu.png");
    cEtaMu->Print("./Plots/"+plotsFolder+"EtaMu.png");
    cNJet->Print("./Plots/"+plotsFolder+"NJet.png");
    cPtJet1->Print("./Plots/"+plotsFolder+"PtJet1.png");
    cEtaJet1->Print("./Plots/"+plotsFolder+"EtaJet1.png");
    cPtJet2->Print("./Plots/"+plotsFolder+"PtJet2.png");
    cEtaJet2->Print("./Plots/"+plotsFolder+"EtaJet2.png");
    cLP_Pos->Print("./Plots/"+plotsFolder+"LP_Pos.png");
    cLP_Neg->Print("./Plots/"+plotsFolder+"LP_Neg.png");
    cPFMHT->Print("./Plots/"+plotsFolder+"PFMHT.png");
    cPFMT->Print("./Plots/"+plotsFolder+"PFMT.png");
    cHTlep->Print("./Plots/"+plotsFolder+"HTlep.png");
    cMeffa->Print("./Plots/"+plotsFolder+"Meffa.png");
    cMeffb->Print("./Plots/"+plotsFolder+"Meffb.png");
  } // ~end of save plots  


} // ~ end of mainFunction




  // -- Help functions


  // -- Draw 1D histos
TH1D *plot1Dhisto(double intLumi,TFile *fileName,TString folderName,TString histoName,int color,int rebin,float xMin,float xMax,TString xName, TString yName,TString sampleName,bool mc) {

  
  
  TH1D *hTemp = (TH1D*)fileName->Get(folderName+"/"+histoName); hTemp->SetName(histoName+"_"+sampleName);
  //  hTemp->Sumw2();
  if (mc) { hTemp->Scale(intLumi/100.); }
  hTemp->Rebin(rebin);
  hTemp->SetLineColor(color);
  hTemp->SetLineWidth(3);
  hTemp->GetXaxis()->SetRangeUser(xMin,xMax);
  hTemp->GetXaxis()->SetTitle(xName);
  hTemp->GetYaxis()->SetTitle(yName);

  // last bin: put put overflow
  hTemp->SetBinContent(hTemp->FindBin(xMax),hTemp->Integral(hTemp->FindBin(xMax),hTemp->GetNbinsX()+1));
  //  cout << "Nbins=" << hTemp->GetNbinsX() << "\n";
  

  
  return hTemp;
} // ~ end of plot1Dhisto function





  // DATA vs MC comparison
void createDataVsMCcompRatio(double intLumi,TFile *fQCD,TFile *fZ,TFile *fW,TFile *fTT,TFile *flm1,TFile *fDATA,TCanvas *cCanvas,int cPad,int maxPads,
			     TString folderName,TString histoName,int rebin,float xMin,float xMax,TString xName, TString yName,bool useLog) {
  

  ostringstream tmpLumi;
  tmpLumi << intLumi;
  TString lumi = tmpLumi.str();
  


  cCanvas->cd(cPad);
  
  if (useLog) { gPad->SetLogy(); }
  
  
  // SM backgrounds
  TH1D *hQCD = plot1Dhisto(intLumi,fQCD,folderName,histoName,kYellow+3,rebin,xMin,xMax,xName,yName,"QCD",true); // hQCD->SetName("hQCD");
  TH1D *hZ   = plot1Dhisto(intLumi,fZ,folderName,histoName,kMagenta,rebin,xMin,xMax,xName,yName,"Z",true); // hQCD->SetName("hQCD");
  TH1D *hW   = plot1Dhisto(intLumi,fW,folderName,histoName,4,rebin,xMin,xMax,xName,yName,"W",true); // hQCD->SetName("hQCD");
  TH1D *hTT  = plot1Dhisto(intLumi,fTT,folderName,histoName,kGreen+2,rebin,xMin,xMax,xName,yName,"TT",true); // hQCD->SetName("hQCD");
  TH1D *hSM  = (TH1D*)hTT->Clone("hSM"); hSM->SetName("hSM");  hSM->Add(hW); hSM->Add(hQCD); hSM->Add(hZ);
  hSM->SetLineWidth(4); hSM->SetLineColor(kGray+3); hSM->SetMarkerSize(0.);
  
  // Data
  TH1D *hData = plot1Dhisto(intLumi,fDATA,folderName,histoName,1,rebin,xMin,xMax,xName,yName,"Data",false); // hQCD->SetName("hQCD");
  hData->SetMarkerSize(1); hData->SetMarkerColor(1); hData->SetMarkerStyle(21);
  
  // Signal
  TH1D *hLM1 = plot1Dhisto(intLumi,flm1,folderName,histoName,2,rebin,xMin,xMax,xName,yName,"LM1",true); // hQCD->SetName("hQCD");


  
  // y-axis range
  if (useLog) { hData->GetYaxis()->SetRangeUser(0.1,30.*(hData->GetBinContent(hData->GetMaximumBin()))); }
  else { hData->GetYaxis()->SetRangeUser(0.1,1.4*(hData->GetBinContent(hData->GetMaximumBin()))); }


  
  // Draw the histograms
  hData->Draw("P E0");
  hSM->Draw("HIST E0 sames");
  hQCD->Draw("HIST E0 sames");
  hZ->Draw("HIST E0 sames");
  hW->Draw("HIST E0 sames");                                                                                                                                                                               
  hTT->Draw("HIST E0 sames");
  hLM1->Draw("HIST E0 sames");                                                                                                                                                                             
  hData->Draw("P E0 sames"); // re-draw to be on top
  
  
  
  // Draw Legend
  TLegend *lSamples = legendRAW();
  lSamples->AddEntry(hData,"DATA","PL");
  lSamples->AddEntry(hQCD,"QCD","FL");
  lSamples->AddEntry(hZ,"Z","FL");
  lSamples->AddEntry(hW,"W","FL");
  lSamples->AddEntry(hTT,"TTbar","FL");
  lSamples->AddEntry(hLM1,"LM1","FL");
  lSamples->AddEntry(hSM,"SM","FL");
  lSamples->Draw("same");
  
  
  
  TLatex *lPreliminary = new TLatex(0.2,0.82,"Preliminary 2011");
  //    TLatex *lIntLumi = new TLatex(0.2,0.89,"#scale[0.8]{#int L dt = " +intLumi+"pb^{-1}, #sqrt{s} = 7 TeV}");
  TLatex *lIntLumi = new TLatex(0.2,0.89,"#scale[0.8]{#int L dt = "+lumi+" pb^{-1}, #sqrt{s} = 7 TeV}");
  lPreliminary->SetNDC();
  lIntLumi->SetNDC();
  lPreliminary->Draw("same");
  lIntLumi->Draw("same");
  
  cCanvas->cd(cPad+maxPads);
  //  cCanvas->cd(cPad+1);
  
  gPad->SetGridx(); gPad->SetGridy();
  TH1D *hRatio = (TH1D*)hData->Clone("hRatio");
  //  hRatio->Sumw2();
  hRatio->Divide(hData,hSM);
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
  
  
} // ~ end of createDataVsMCcompRatio function






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





