#include "TH1.h"
#include "TF1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TROOT.h"
#include "TApplication.h"
#include "TString.h"
#include "TMath.h"
#include <iostream>
#include <vector>
#include <TString.h>
#include <set>
#include "TLegend.h"
#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#include "TLatex.h"
#include "setTDRStyle.h"

struct GlobalParameterSet {
  bool PrintCanvases;
  TString PrintFileName;
  bool UseSystematics;
  bool ShowMCStatErrorbars;
  bool ShowErrorBand;
  bool ShowStatErrorbars;
  bool ShowSystematicsDetails;
  bool ShowMCComposition;
  bool StackMCComposition;
  int HistosPerCanvas;
  bool GlobalLog;	
  double intLumi;
};

void setTDRStyle();

using namespace std;

TH1D *plot1Dhisto(double intLumi,TFile *fileName,TString folderName,TString histoName,int color,int rebin,float xMin,float xMax,TString xName, TString yName,TString sampleName,bool mc);

void createDataVsMC(TString folderName,TString histoName,int rebin,double xMin,double xMax,TString xName, TString yName, vector<TString> MCFileNames, vector<TString> MCNames, vector<int> MCColors, vector<bool> AddToBkg,vector<TString> DataFileNames,vector<TString> dataNames,vector<int> dataColors,vector<TString> SystNames,vector<int> SystColors, TCanvas *cCanvas,int padNr,bool UseLog, GlobalParameterSet Parameters);
					
TCanvas* createCanvas(TString name,int xlen,int ylen,int xDiv);

TLegend *legendRAW();

void NoError (TH1D* histo,double xMin,double xMax);

void mainFunction(bool print = false) {

  setTDRStyle();
  gROOT->SetBatch(false);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  TH1::SetDefaultSumw2();

  GlobalParameterSet Parameters;

  vector<TString> folderNames;
  vector<int> rebinFactor;
// CHOOSE FOLDERS	==================================

//  folderNames.push_back("noSTbins");
//  rebinFactor.push_back(1);
  folderNames.push_back("ANplots150_LPsecondD1000");
   rebinFactor.push_back(1);
  folderNames.push_back("ANplots250_LPsecondD1000");
   rebinFactor.push_back(1);

  folderNames.push_back("ANplots350_LPsecondD1000");
   rebinFactor.push_back(1);

  folderNames.push_back("ANplots450_LPsecondD1000");
   rebinFactor.push_back(1);

//  folderNames.push_back("ANplots");
//  rebinFactor.push_back(1);
//  folderNames.push_back("ANplots250_NOLPsecondD400");/
//  rebinFactor.push_back(1);

//  folderNames.push_back("ANplots350_NOLPsecondD400");
//  rebinFactor.push_back(1);

//  folderNames.push_back("ANplots450_NOLPsecondD400");
//  rebinFactor.push_back(1); // 2 for search reg
   //  folderNames.push_back("ANplots450_NOLPsecondD500");
   //   rebinFactor.push_back(1);
  
  //  folderNames.push_back("OP_ANplots_ST150_inf");
  //  rebinFactor.push_back(1);
  // =================================================
  set<TString> plots;
  // CHOOSE PLOTS ====================================
  //  plots.insert("LP_pos");
  //  plots.insert("LP_neg");
    
   // plots.insert("HTthrust");
  //  plots.insert("thrust");
   plots.insert("LP_tot");
  //  plots.insert("LPMHT_tot");
      plots.insert("DeltaPhiMuWPT");
    
  //      plots.insert("HT_tot");
  //   plots.insert("MT_pos");
  //     plots.insert("MT_neg");
    //  plots.insert("MT_tot");
  //   plots.insert("SumLepPt_pos");
  //   plots.insert("SumLepPt_neg");
  //  plots.insert("SumLepPt_tot");
  // plots.insert("ST_tot");
  //       plots.insert("LepPt_pos");
  //       plots.insert("LepPt_neg");
  //     plots.insert("LepPt_tot");
    //    plots.insert("PFMET_pos");
    //   plots.insert("PFMET_neg");
    //      plots.insert("PFMET_tot");
    //plots.insert("PFMHT_pos");
    // plots.insert("PFMHT_neg");
    //  plots.insert("PFMHT_tot");
    //    plots.insert("LepEta_pos");
    //    plots.insert("LepEta_neg");
    //     plots.insert("LepEta_tot");
     //    plots.insert("LepPhi_pos");
     //    plots.insert("LepPhi_neg");
    //  plots.insert("LepPhi_tot");
    //      plots.insert("Iso_tot");
       plots.insert("NoVertex");
	  //    plots.insert("Zres");
    
	  //      plots.insert("Zmass");
       //  plots.insert("ZmassR");
       //plots.insert("ZPT");
       // plots.insert("ZMHT");
  // ==================================================
  
  // SET PLOT PARAMETERS ==============================
  // MC details (i.e. W, tt, ...)
  Parameters.ShowMCComposition = true;
  // Stack and fill MC histos?
  Parameters.StackMCComposition = true;
  // Print to file?
  Parameters.PrintCanvases = print;	
  
  // number of histograms per canvas
  Parameters.HistosPerCanvas = 4;
  // Stat. error bars of data
  Parameters.ShowStatErrorbars = true;
  // Show statistic error of MC
  Parameters.ShowMCStatErrorbars = true;
  
  // using systematics requires data in results*_metup etc
  // choose one of the following
  // Show errorband for stat. and syst. error of MC:
  Parameters.ShowErrorBand = false;
  // systematics details (ugly)
  Parameters.ShowSystematicsDetails = false;
  // Draw all histograms with log scale
  Parameters.GlobalLog = false; 

  // Parameters.PrintFileName = "DATAvsMC.pdf";
  
  // =================================================  
  
  // SET OTHER PARAMETERS ============================
   
  // int Lumi
  // Parameters.intLumi = 881.; //Electron PR
  // Parameters.intLumi = 201.; //Electron RR
  // Parameters.intLumi = 203.; //Muon PR
  Parameters.intLumi = 5000.; //Muon PR
  //  Parameters.intLumi = 1080.; //Electron total
  // path to files
  //  TString path = "/vols/cms02/gouskos/onelepton/20110817_El_Sel_COR/";
  //  TString path = "/vols/cms02/gouskos/onelepton/20110820_MuFromMarkus/";
  //  TString path = "/vols/cms01/mstoye/Markus8/SUSYv2/onelepton/scripts/resultsMC_lt3j/";
  //  TString path = "/vols/cms01/mstoye/Markus8/SUSYv2/onelepton/scripts/resultsMC_lt3j_St150infPlots/";
  TString path = "";
  // TString path = "/vols/cms02/gouskos/onelepton/20110827_Mu_lt3jts_HT350/";
  // MC filenames
  TString filename_MCqcd = path+"resultsSyncRelaxedIsoTest/qcd.root";
  TString filename_MCz   = path+"resultsSyncRelaxedIsoTest/z.root";
  TString filename_MCw   = path+"resultsSyncRelaxedIsoTest/w.root";
  TString filename_MCtt  = path+"resultsSyncRelaxedIsoTest/tt.root";
  // DATA filenames
  TString filename_DATAmu =  path+"resultsSyncRelaxedIsoTest/data.root";
  TString filename_DATAmuB =  path+"resultsSyncRelaxedIsoTest/data.root";

// ==================================================  
// END OF NORMAL CONFIGURATION PART =================

// MORE PARAMETERS ==================================
  int xSizeCanvas = 500;
  int ySizeCanvas = 750;
  int zColor = 5;
  int ttColor = 3;
  int wColor = 6;
  int qcdColor = 11;

  // prevent unfortunate parameter combinations
  if(Parameters.ShowSystematicsDetails||Parameters.ShowErrorBand)
    Parameters.UseSystematics = true;
  else
    Parameters.UseSystematics = false;
 
  if(Parameters.ShowErrorBand) {
    Parameters.StackMCComposition = false;
    Parameters.ShowMCStatErrorbars = true;
    Parameters.ShowMCComposition = false;
  }
  if(Parameters.ShowSystematicsDetails) {
    Parameters.ShowMCComposition = false;
    Parameters.ShowMCStatErrorbars = false;
    Parameters.ShowMCComposition = false;
  }
  if(!Parameters.ShowMCComposition) {
    Parameters.StackMCComposition = false;
  }
 
  // Systematics to use (names should be the same as in muon/electron_base)
  vector<TString> SystNames;
  vector<int> SystColors;
  if(Parameters.UseSystematics) {
    SystNames.push_back("metup");
    SystColors.push_back(3);
    SystNames.push_back("metdown");
    SystColors.push_back(4);
    //SystNames.push_back("metres_conservative");
    //SystColors.push_back(7);
    //SystNames.push_back("mupt");
    //SystColors.push_back(11);
  }

  // MC files
  vector<TString> MCFileNames;
  vector<TString> MCNames;
  vector<int> MCColors;
  vector<bool> AddToBkg;  

  MCFileNames.push_back(filename_MCw);
  MCNames.push_back(TString("W"));
  MCColors.push_back(wColor);
  AddToBkg.push_back(true);  
  
  MCFileNames.push_back(filename_MCtt);
  MCNames.push_back(TString("tt"));
  MCColors.push_back(ttColor);
  AddToBkg.push_back(true);
  
  MCFileNames.push_back(filename_MCz);
  MCNames.push_back(TString("Z"));
  MCColors.push_back(zColor);
  AddToBkg.push_back(true);
  
  MCFileNames.push_back(filename_MCqcd);
  MCNames.push_back(TString("QCD"));
  MCColors.push_back(qcdColor);
  AddToBkg.push_back(true);
   
  // Data Files
  vector<TString> dataFileNames;
  vector<TString> dataNames;
  vector<int> dataColors;
  
  dataFileNames.push_back(filename_DATAmu);
  dataNames.push_back("data");
  dataColors.push_back(1);

  //  dataFileNames.push_back(filename_DATAmuB);
  //  dataNames.push_back("DATAB");
  //  dataColors.push_back(2);  
  // There is the possibility of drawing more than one DATA sample
  //dataFileNames.push_back(path+"dataOldMET.root");
  //dataNames.push_back("DATA old MET");
  //dataColors.push_back(3);
  /*
  if(Parameters.UseSystematics&&(Parameters.ShowMCStatErrorbars||Parameters.ShowSystematicsDetails||Parameters.ShowErrorBand)) {
    TString filename_mupt = filename_DATAmu;
    filename_mupt = filename_mupt.Insert(filename_mupt.Last('/'),"_mupt");
    dataFileNames.push_back(filename_mupt);
    dataNames.push_back("mupt(Data)");
    dataColors.push_back(9);
  }
  */
// ==================================================  
// Create Canvases and Plots

// Create Canvases and Plots
  int CanvasesSize = (plots.size()*folderNames.size()-1)/Parameters.HistosPerCanvas+1;
  TCanvas* Canvases[CanvasesSize];
  for(int i=0; i<CanvasesSize;i++) {
    TString name = "canvas ";
    name +=i;
    Canvases[i]=createCanvas(name,xSizeCanvas,ySizeCanvas,Parameters.HistosPerCanvas);
  }
  int plotNr=0;
  for(unsigned int i=0; i<folderNames.size(); i++) {
    /*    if(plots.count("LP_pos")>0) { 
      createDataVsMC(folderNames[i],"LP_pos",5*rebinFactor[i],-0.5,1.5,"L_{P}[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("LP_neg")>0) {    	
      createDataVsMC(folderNames[i],"LP_neg",5*rebinFactor[i],-0.5,1.5,"L_{P}[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
      } */
    if(plots.count("LP_tot")>0) { 
      createDataVsMC(folderNames[i],"LP_tot",5*rebinFactor[i],-0.5,1.9,"L_{P}","Events / 0.15",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 
  }


  for(unsigned int i=0; i<folderNames.size(); i++) {

  if(plots.count("LPMHT_tot")>0) { 
      createDataVsMC(folderNames[i],"ZLPMHT",4*rebinFactor[i],-0.5,1.9,"L_{P}","Events / 0.15",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 
  }

  for(unsigned int i=0; i<folderNames.size(); i++) {
    if(plots.count("DeltaPhiMuWPT")>0) { 
      createDataVsMC(folderNames[i],"DeltaPhiMuJ_tot",10*rebinFactor[i],-0.,TMath::Pi(),"min #Delta#phi(P_{T}(jet),P_{T}(#mu))","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 
  }
  for(unsigned int i=0; i<folderNames.size(); i++) {

    if(plots.count("Iso_tot")>0) { 
      createDataVsMC(folderNames[i],"RelCombIso_tot",10*rebinFactor[i],-0.,0.1,"RelCombIso_tot","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,true,Parameters);
      plotNr++; 
    } }
  for(unsigned int i=0; i<folderNames.size(); i++) {
    if(plots.count("NoVertex")>0) { 
      createDataVsMC(folderNames[i],"NrOfJets_tot",1*rebinFactor[i],0.5,10.5,"NrOfJets","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 
  }
  for(unsigned int i=0; i<folderNames.size(); i++) {
if(plots.count("thrust")>0) { 
      createDataVsMC(folderNames[i],"Thrust",5*rebinFactor[i],-0.,1,"Thrust","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,true,Parameters);
      plotNr++; 
    } 
if(plots.count("HTthrust")>0) { 
      createDataVsMC(folderNames[i],"HT_tot_thru",5*rebinFactor[i],-0.,2000,"HT_tot_thru",";HT minor;Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,true,Parameters);
      plotNr++; 
    } 
if(plots.count("Zres")>0) { 
      createDataVsMC(folderNames[i],"ZPTres",5*rebinFactor[i],-1.5,1.5,"(ZPT-ZMHT)/ZPT","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 

if(plots.count("Zmass")>0) { 
      createDataVsMC(folderNames[i],"ZmassoppSign",1*rebinFactor[i],70,120,"Z mass [GeV]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 

if(plots.count("ZmassR")>0) { 
      createDataVsMC(folderNames[i],"ZmassoppSign",1*rebinFactor[i],70,120,"Z mass [GeV]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 


if(plots.count("ZPT")>0) { 
      createDataVsMC(folderNames[i],"ZPT",5*rebinFactor[i],0,500,"Z P_{T} [GeV]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 

if(plots.count("ZMHT")>0) { 
      createDataVsMC(folderNames[i],"ZMHTpl",5*rebinFactor[i],0,500,"Z MH_{T} [GeV]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++; 
    } 

  }
  for(unsigned int i=0; i<folderNames.size(); i++) {
    if(plots.count("LepEta_pos")>0) {
      createDataVsMC(folderNames[i],"LepEta_pos",10*rebinFactor[i],-2.1,2.1,"#eta[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
    	plotNr++;
    } 
    if(plots.count("LepEta_neg")>0) {
      createDataVsMC(folderNames[i],"LepEta_neg",10*rebinFactor[i],-2.1,2.1,"#eta[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("LepEta_tot")>0) {
      createDataVsMC(folderNames[i],"LepEta_tot",10*rebinFactor[i],-2.1,2.1,"#eta","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
  }
  for(unsigned int i=0; i<folderNames.size(); i++) {
    if(plots.count("MT_pos")>0) {
	    createDataVsMC(folderNames[i],"MT_pos",5*rebinFactor[i],0,500,"MT[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
	    plotNr++;
    } 
    if(plots.count("MT_neg")>0) {
      createDataVsMC(folderNames[i],"MT_neg",5*rebinFactor[i],0,500,"MT[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("MT_tot")>0) {
      createDataVsMC(folderNames[i],"MT_tot",5*rebinFactor[i],0,300,"M_{T} [GeV]","Events / 10 GeV",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    }
  }

  for(unsigned int i=0; i<folderNames.size(); i++) { 
    if(plots.count("SumLepPt_pos")>0) {
      createDataVsMC(folderNames[i],"SumLepPt_pos",5*rebinFactor[i],0,250,"S_{T}^{lep}[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("SumLepPt_neg")>0) {
      createDataVsMC(folderNames[i],"SumLepPt_neg",5*rebinFactor[i],0,250,"ST_{lep}[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("ST_tot")>0) {
      createDataVsMC(folderNames[i],"SumLepPt_tot",5*rebinFactor[i],125,250,"S_{T}^{lep} [GeV]","Events / 50 GeV",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    }
  }
  for(unsigned int i=0; i<folderNames.size(); i++) { 
    if(plots.count("LepPhi_pos")>0) {
      createDataVsMC(folderNames[i],"LepPhi_pos",10*rebinFactor[i],-TMath::Pi(),TMath::Pi(),"#phi[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("LepPhi_neg")>0) {
      createDataVsMC(folderNames[i],"LepPhi_neg",10*rebinFactor[i],-TMath::Pi(),TMath::Pi(),"#phi[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters); 
      plotNr++;
    } 
    if(plots.count("LepPhi_tot")>0) {
      createDataVsMC(folderNames[i],"LepPhi_tot",10*rebinFactor[i],-TMath::Pi(),TMath::Pi(),"#phi","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;   
    }
  }
  for(unsigned int i=0; i<folderNames.size(); i++) { 
    if(plots.count("LepPt_pos")>0) {
      createDataVsMC(folderNames[i],"LepPt_pos",10*rebinFactor[i],0,500,"LepPt[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("LepPt_neg")>0) {
      createDataVsMC(folderNames[i],"LepPt_neg",10*rebinFactor[i],0,500,"LepPt[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("LepPt_tot")>0) {
      createDataVsMC(folderNames[i],"LepPt_tot",5*rebinFactor[i],0,300,"p_{T}(lep) [GeV]","Events / 20 GeV",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    }
  }
  for(unsigned int i=0; i<folderNames.size(); i++) { 
    if(plots.count("PFMET_pos")>0) {
      createDataVsMC(folderNames[i],"PFMET_pos",10*rebinFactor[i],0,300,"PFMET[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("PFMET_neg")>0) {
      createDataVsMC(folderNames[i],"PFMET_neg",10*rebinFactor[i],0,300,"PFMET[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("PFMET_tot")>0) {
      createDataVsMC(folderNames[i],"PFMET_tot",10*rebinFactor[i],0,300,"PFMET","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    }
  }
  for(unsigned int i=0; i<folderNames.size(); i++) { 
    if(plots.count("PFMHT_pos")>0) {
      createDataVsMC(folderNames[i],"PFMHT_pos",25*rebinFactor[i],0,400,"PFMHT[+]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("PFMHT_neg")>0) {
      createDataVsMC(folderNames[i],"PFMHT_neg",25*rebinFactor[i],0,400,"PFMHT[-]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
    if(plots.count("PFMHT_tot")>0) {
      createDataVsMC(folderNames[i],"PFMHT_tot",25*rebinFactor[i],0,400,"PFMHT","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
  }

  for(unsigned int i=0; i<folderNames.size(); i++) {
    if(plots.count("HT_tot")>0) {
      createDataVsMC(folderNames[i],"HT_tot",5*rebinFactor[i],0.,1000.,"H_{T} [GeV]","Entries / bin",MCFileNames,MCNames,MCColors,AddToBkg,dataFileNames,dataNames,dataColors,SystNames,SystColors,Canvases[plotNr/Parameters.HistosPerCanvas],plotNr%Parameters.HistosPerCanvas,false,Parameters);
      plotNr++;
    } 
  }

 
// Print Plots 
  if(Parameters.PrintCanvases) {
    // if(Parameters.PrintFileName.Contains(".pdf")||Parameters.PrintFileName.Contains(".ps")) {
      // Canvases[0]->Print(Parameters.PrintFileName+"[");
      // Canvases[0]->Print(Parameters.PrintFileName);
      for(int i=0; i<CanvasesSize; i++) {
	Canvases[i]->Print(TString("plots/")+TString(Canvases[i]->GetName())+".pdf");
      }
      // Canvases[0]->Print(Parameters.PrintFileName+"]");
      // Canvases[0]->Print(TString(Canvases[0]->GetName())+".pdf");
      
  }
  /*else {
      for(int i=0; i<CanvasesSize; i++) {
	TString PrintName=Parameters.PrintFileName;
	TString s = "_";
	s+=i;
	PrintName.Insert(PrintName.Last('.'),s);
	Canvases[i]->Print(PrintName);
      }
    }
    }*/
}

// Help functions ===========================

// Draw 1D histos
TH1D *plot1Dhisto(double intLumi,TFile *fileName,TString folderName,TString histoName,int color,int rebin,float xMin,float xMax,TString xName, TString yName,TString sampleName,bool mc) {  
  
  TH1D *hTemp = (TH1D*)fileName->Get(folderName+"/"+histoName);
  hTemp->SetName(histoName+"_"+sampleName);
  if (mc){ 
    hTemp->Scale(intLumi/100.);
  }
  hTemp->Rebin(rebin);
  hTemp->SetLineColor(color);
  hTemp->SetLineWidth(5);
  hTemp->GetXaxis()->SetRangeUser(xMin,xMax);
  hTemp->GetXaxis()->SetTitle(xName);
  hTemp->GetXaxis()->SetTitleSize(0.06);
  hTemp->GetXaxis()->SetLabelSize(0.06);
  hTemp->GetYaxis()->SetTitle(yName);
  hTemp->GetYaxis()->SetTitleSize(0.06);
  hTemp->GetYaxis()->SetLabelSize(0.06);
  hTemp->SetTitleOffset(1.5, "Y");
  // last/first bin: put over/underflow
  hTemp->SetBinContent(hTemp->FindBin(xMax),hTemp->Integral(hTemp->FindBin(xMax),hTemp->GetNbinsX()+1));
  hTemp->SetBinContent(hTemp->FindBin(xMin),hTemp->Integral(-1,hTemp->FindBin(xMin)));  

  hTemp->SetBinError(hTemp->FindBin(xMax),sqrt(hTemp->Integral(hTemp->FindBin(xMax),hTemp->GetNbinsX()+1)));
  hTemp->SetBinError(hTemp->FindBin(xMin),sqrt(hTemp->Integral(-1,hTemp->FindBin(xMin))));
  //fileName->Close();

  /*
  if (histoName != "LP_tot") {
    if (histoName != "SumLepPt_tot") {
      if ((folderName == "ANplots150_NOLP")) { hTemp->GetXaxis()->SetRangeUser(0.,300.); } 
      if ((folderName == "ANplots250_NOLP")) { hTemp->GetXaxis()->SetRangeUser(0.,400.); }
      if ((folderName == "ANplots350_NOLP")) { hTemp->GetXaxis()->SetRangeUser(0.,500.); }
      if ((folderName == "ANplots450_NOLP")) { hTemp->GetXaxis()->SetRangeUser(0.,1000.); }
    }
    else {
      if ((folderName == "ANplots150_NOLP")) { hTemp->GetXaxis()->SetRangeUser(100.,300.); } 
      if ((folderName == "ANplots250_NOLP")) { hTemp->GetXaxis()->SetRangeUser(200.,400.); }
      if ((folderName == "ANplots350_NOLP")) { hTemp->GetXaxis()->SetRangeUser(300.,500.); }
      if ((folderName == "ANplots450_NOLP")) { hTemp->GetXaxis()->SetRangeUser(400.,1000.); }
    }
  } 
  */ 
  return hTemp;
} // ~ end of plot1Dhisto function


void createDataVsMC(TString folderName,TString histoName,int rebin,double xMin,double xMax,TString xName, TString yName, vector<TString> MCFileNames, vector<TString> MCNames, vector<int> MCColors, vector<bool> AddToBkg,vector<TString> DataFileNames,vector<TString> dataNames,vector<int> dataColors,vector<TString> SystNames,vector<int> SystColors, TCanvas *cCanvas, int padNr, bool UseLog,GlobalParameterSet Parameters) {
					 
  // CREATE ALL HISTOGRAMS ========================================================

  TString lumi = "";
  lumi+=Parameters.intLumi;
  if(Parameters.GlobalLog) {
    UseLog = true;  
  }
       
  // SM background histo
  TH1D *hSM0=0; 
  // Create MC histos and add them SM0
  vector<TH1D*> MChistos;
  bool noneAdded = true;
  for(unsigned int i =0;i<MCFileNames.size();i++) {
    MChistos.push_back(plot1Dhisto(Parameters.intLumi,TFile::Open(MCFileNames[i],"READONLY"),folderName,histoName,MCColors[i],rebin,xMin,xMax,xName,yName,"MC",true));
    if(noneAdded&&AddToBkg[i]) {
      hSM0 = (TH1D *) MChistos[i]->Clone();
      noneAdded = false;
    }
    else {
      if(AddToBkg[i]) {
	hSM0->Add(MChistos[i],1);
      }	  
    }
  }
  hSM0->SetLineColor(2);


  // Create Histograms with the different systematics
  vector<TH1D*> SystHistos;
  if(Parameters.UseSystematics) {
    for(unsigned int i=0; i<SystNames.size(); i++) {
      noneAdded = true;
      for(unsigned int j=0; j<MCFileNames.size(); j++) {
	if(AddToBkg[j]) {
	  TString SystFileName = MCFileNames[j];
	  SystFileName.Insert(SystFileName.Last('/'),"_"+SystNames[i]);
	  TFile *SystMCFile = TFile::Open(SystFileName,"READONLY");
	  TH1D *SystHistoTemp = plot1Dhisto(Parameters.intLumi,SystMCFile,folderName,histoName,SystColors[i],rebin,xMin,xMax,xName,yName,"MC",true);
	  SystHistoTemp->SetLineStyle(2);
	  if(noneAdded) {
	    SystHistos.push_back((TH1D *) SystHistoTemp->Clone());
	    noneAdded = false;
	  }
	  else {
	    SystHistos.back()->Add(SystHistoTemp,1);
	  }
	}
      }
    }
  }

  // Create Histograms for error band
  TH1D* hSM0allErrors = (TH1D *) hSM0->Clone();
  TH1D* hSM0systErrors = (TH1D *) hSM0->Clone();
  if(Parameters.UseSystematics) {
    for(int j = hSM0->FindBin(xMin); j<=hSM0->FindBin(xMax); j++) {
      double downerror=0;
      double uperror=0;
      for(unsigned int i=0; i<SystHistos.size(); i++) {
	double diff = SystHistos[i]->GetBinContent(j) - hSM0->GetBinContent(j);
	if(diff>0)
	  uperror += diff*diff;
	else
	  downerror += diff*diff;
      }
      downerror = TMath::Sqrt(downerror);
      uperror = TMath::Sqrt(uperror);
      double maxerror = TMath::Max(downerror,uperror);
      double staterror = hSM0->GetBinError(j);
      hSM0systErrors->SetBinError(j,maxerror);
      hSM0allErrors->SetBinError(j,TMath::Sqrt(maxerror*maxerror+staterror*staterror));
      hSM0systErrors->SetFillColor(5);
      hSM0systErrors->SetLineColor(5);
      hSM0allErrors->SetLineColor(3);
      hSM0allErrors->SetFillColor(3);
    }
  }
  
  // Create Data Histograms
  vector<TH1D *> dataHistos; 
  for(unsigned int i=0; i<DataFileNames.size();i++) {
    dataHistos.push_back(plot1Dhisto(Parameters.intLumi,TFile::Open(DataFileNames[i],"READONLY"),folderName,histoName,dataColors[i],rebin,xMin,xMax,xName,yName,"Data",false));
    dataHistos[i]->SetMarkerSize(1); 
    dataHistos[i]->SetMarkerColor(dataColors[i]); 
    dataHistos[i]->SetMarkerStyle(21);
    if(i==1) dataHistos[i]->Scale(1.);
    // remove error manually  
    if(!Parameters.ShowStatErrorbars){
      NoError(dataHistos[i],xMin,xMax);
    }
    // y-axis range
    if (UseLog){ 
      dataHistos[i]->GetYaxis()->SetRangeUser(.5,2.5*(dataHistos[i]->GetBinContent(dataHistos[i]->GetMaximumBin()))); 
    }
    else{ 
      dataHistos[i]->GetYaxis()->SetRangeUser(0.,1.8*(dataHistos[i]->GetBinContent(dataHistos[i]->GetMaximumBin())));
    }

  }
  
  cCanvas->SetName(folderName+histoName);
  cCanvas->cd(2*padNr+1);  
  if(UseLog) {
    gPad->SetLogy(); 
  }
  dataHistos[0]->Draw("P E0");


  if(histoName=="ZPT"||histoName=="LepPt_pos"||histoName=="LepPt_neg" )
    cout << "MC " << hSM0->Integral() <<" data: "<<dataHistos[0]->Integral() <<endl;

  //DRAW ALL HISTOGRAMS =====================================================    

  if(Parameters.ShowMCComposition){
    for(unsigned int i=1; Parameters.StackMCComposition&&i<MChistos.size();i++) {
      MChistos[i]->Add(MChistos[i],MChistos[i-1]);
      MChistos[i]->SetFillColor(MCColors[i]);
      MChistos[i]->SetFillStyle(3004);
      MChistos[i-1]->SetFillStyle(3004);
      MChistos[i-1]->SetFillColor(MCColors[i-1]); 	  	
    }  	
    for(int i=MChistos.size()-1;i>=0;i--) {
      if(Parameters.ShowMCStatErrorbars)
	MChistos[i]->Draw("HIST E0 same");
      else
	MChistos[i]->Draw("HIST same");
    }
  }
  
  hSM0->SetLineColor(kRed);

  if(Parameters.ShowErrorBand) {
    hSM0allErrors->Draw("E2 same");
    hSM0systErrors->Draw("E2 same");
  }

  if(!Parameters.ShowMCStatErrorbars&&!Parameters.StackMCComposition)
    hSM0->Draw("HIST same"); 
  	
  if(Parameters.ShowSystematicsDetails) {
    for(unsigned int i=0; i<SystHistos.size();i++) {
      SystHistos[i]->Draw("HIST same");
    }
  } 
  
  for(int i=dataHistos.size()-1;i>=0;i--) {
    dataHistos[i]->Draw("P E0 same");
  }
  if(Parameters.ShowMCStatErrorbars&&!Parameters.StackMCComposition) {
    hSM0->Draw("HIST same E0");
  }
  // Draw Legend
  TLegend *lSamples = legendRAW();
  if(!Parameters.StackMCComposition)
    lSamples->AddEntry(hSM0,"Total MC","FL");
  if(Parameters.ShowErrorBand) {
    lSamples->AddEntry(hSM0systErrors,"Systematic Error","FL");
    lSamples->AddEntry(hSM0allErrors,"MC Syst. #oplus Stat. Error","FL");
  }
  for(unsigned int i=0; i<dataHistos.size(); i++) { 
    lSamples->AddEntry(dataHistos[i],dataNames[i],"PL");
  }
  for(unsigned int i =0;i<MChistos.size()&&Parameters.ShowMCComposition;i++) {
    lSamples->AddEntry(MChistos[i],MCNames[i],"FL");
  }
  for(unsigned int i =0;i<SystHistos.size()&&Parameters.ShowSystematicsDetails;i++) {
    lSamples->AddEntry(SystHistos[i],SystNames[i],"FL");
  }
  
  lSamples->Draw("same");
  
  TLatex *lPreliminary = new TLatex(0.19,0.96,"CMS Preliminary 2011");

  //  TLatex *lIntLumi = new TLatex(0.15,0.89,"#scale[0.8]{#int L dt = "+lumi+" pb^{-1}, #sqrt{s} = 7 TeV}");
  TLatex *lIntLumi  = new TLatex(0.2,0.86,"#scale[1.]{~3.8fb fb^{-1}, #sqrt{s} = 7 TeV}");
  TLatex *lIntLumiB = new TLatex(0.2,0.77,"#scale[1.]{#sqrt{s} = 7 TeV}");
  lPreliminary->SetNDC();
  lIntLumi->SetNDC();
  lIntLumiB->SetNDC();
  lPreliminary->Draw("same");
  lIntLumi->Draw("same"); 
  //  lIntLumiB->Draw("same"); 
  //  gPad->SetGridx(); 
  //  gPad->SetGridy();
  
  // DRAW RATIO PLOTS ============================================================================

  vector<TH1D*> hRatio;
  for(unsigned int i=0; i<dataHistos.size()&&MChistos.size()>0; i++) {
    hRatio.push_back((TH1D*)dataHistos[i]->Clone(""));
    hRatio.back()->Divide(dataHistos[i],hSM0);
    hRatio.back()->GetYaxis()->SetTitle("Data / MC");
    hRatio.back()->GetYaxis()->SetTitleSize(0.16);
    hRatio.back()->GetXaxis()->SetTitle("");
    hRatio.back()->GetYaxis()->SetNdivisions(409);
    hRatio.back()->GetYaxis()->SetRangeUser(0.,2.);
    hRatio.back()->SetTitleSize(0.16, "XY");
    hRatio.back()->SetTitleOffset(0.5, "Y");
    hRatio.back()->SetLabelSize(0.165,"XY");

  }

  for(unsigned int i=0; Parameters.UseSystematics&&Parameters.ShowSystematicsDetails&&i<SystHistos.size(); i++) {
    hRatio.push_back((TH1D*)SystHistos[i]->Clone(""));
    hRatio.back()->Divide(SystHistos[i],hSM0);
    hRatio.back()->GetYaxis()->SetTitle("Data&Syst/MC");
    hRatio.back()->GetYaxis()->SetRangeUser(0.5,1.5);
    hRatio.back()->GetXaxis()->SetTitle("");
    hRatio.back()->SetTitleSize(0.06, "XY");
    hRatio.back()->SetTitleOffset(0.8, "Y");
    hRatio.back()->SetLabelSize(0.08,"XY");
    NoError(hRatio.back(),xMin,xMax);
  }
    
  cCanvas->cd(2*padNr+2);
  //  TBox *unity = new TBox(xMin-0.1,0.95,xMax+0.15, 1.05); // LP
  TBox *unity = new TBox(xMin-0.1,0.95,xMax+0.15, 1.05);

  unity->SetLineWidth(2);
  //unity.SetLineStyle(Root.kDashed);
  unity->SetLineColor(2);
  unity->SetFillColor(2);
  unity->SetFillStyle(3002);
  //  unity->Draw();
  //  gPad->SetGridx(); 
  //  gPad->SetGridy();
  for(unsigned int i=hRatio.size()-1; i<hRatio.size(); i--) {
    if(i==hRatio.size()-1) {
      hRatio[i]->Draw();
      unity->Draw("same");
      hRatio[i]->Draw("same");
    }
    else
      {
	hRatio[i]->GetYaxis()->SetTitleSize(0.055);
	hRatio[i]->Draw("same"); 
      }
 }

  /*
  double xMinBox = 0.;   double xMaxBox = 0.;
  if (histoName != "LP_tot") {
    if (histoName != "SumLepPt_tot") {
      if ((folderName == "ANplots150_NOLP")) { xMinBox = 0.; xMaxBox = 300.; } 
      if ((folderName == "ANplots250_NOLP")) { xMinBox = 0.; xMaxBox = 400.; }
      if ((folderName == "ANplots350_NOLP")) { xMinBox = 0.; xMaxBox = 500.; }
      if ((folderName == "ANplots450_NOLP")) { xMinBox = 0.; xMaxBox = 1000.; }
    }
    else {
      if ((folderName == "ANplots150_NOLP")) { xMinBox = 100.; xMaxBox = 300.; } 
      if ((folderName == "ANplots250_NOLP")) { xMinBox = 200.; xMaxBox = 400.; }
      if ((folderName == "ANplots350_NOLP")) { xMinBox = 300.; xMaxBox = 500.; }
      if ((folderName == "ANplots450_NOLP")) { xMinBox = 400.; xMaxBox = 1000.; }
    }
  } 
  else { xMinBox = xMin-0.1; xMaxBox = xMax+0.03; }
  */
  /*  
  //  TBox *unity = new TBox(xMin-0.1,0.95,xMax+0.15, 1.05); // LP
  TBox *unity = new TBox(xMin-0.1,0.95,xMax+0.15, 1.05);

  unity->SetLineWidth(2);
  //unity.SetLineStyle(Root.kDashed);
  unity->SetLineColor(2);
  unity->SetFillColor(2);
  unity->SetFillStyle(3002);
  unity->Draw("same");
  */
}

TCanvas* createCanvas(TString name,int xlen,int ylen, int xDiv) {
  TCanvas* aCanvas = new TCanvas(name,name,xlen*xDiv,ylen);

  float xstep = 1./xDiv;

  for (int i1=0; i1<xDiv; i1++) {

    TPad *mainPad = new TPad("","",0.01+((i1)*xstep),0.25,((i1+1)*xstep)-0.01,0.99);
    mainPad->SetNumber(1+i1*2);
    mainPad->Draw();

    TPad *ratioPad = new TPad("","",0.01+((i1)*xstep),0.01,((i1+1)*xstep)-0.01,0.25);
    ratioPad->SetNumber(i1*2+2);
    ratioPad->Draw();
  }

  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);

  return aCanvas;
}

TLegend *legendRAW() {

  TLegend *leg = new TLegend(0.73,0.67,0.95,0.93);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetTextFont(62);

  return leg;
}

void NoError (TH1D* histo,double xMin,double xMax) {
  for(int j = histo->FindBin(xMin); j<=histo->FindBin(xMax); j++) {
    histo->SetBinError(j,0);
  }
}
