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



void createDataVsMCcompRatio(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,TTree *tree_DATAmu,
			     TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog);
TH1F *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool DATA,bool useLog);
void coutCutFlow(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,TTree *tree_DATAmu,
		 TString intLumi,TString cuts,TString cutFlowNames);
float cout1Dhisto(TTree *tree,TString intLumi,TString cuts,bool DATA);
TH1F *Divide2Histos(const TH1F* HistoInput1,const TH1F* HistoInput2);
TCanvas* createCanvas(TString name,int xlen,int ylen,int xDiv,bool logOn);
TLegend *legendRAW();
TLegend *legendHeader(TString header);



void mainFunction() {

  setTDRStyle();
  gROOT->SetBatch(false);
  gStyle->SetOptStat(1);
  gStyle->SetPalette(1);

  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(1);


  // ---------
  // Define Integrated Lumi [(pb)-1]
  float intLumi = 2.88;
  //  float intLumi = 3.;

  ostringstream tmpLumi;
  tmpLumi << intLumi;
  TString lumi = tmpLumi.str();

  // -------
  // Open files

  // MC
  TString filename_MCqcd  = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100927/muAlphaT_Signal_QCD_Pythia_AllPtBins_June2010.root";
  TString filename_MCw    = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100927/muAlphaT_Signal_Wjets_June2010.root";
  TString filename_MCz    = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100927/muAlphaT_Signal_Zjets_June2010.root";
  TString filename_MCtt   = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100927/muAlphaT_Signal_TTbarTauola_June2010.root";
  TString filename_MClm0  = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100927/muAlphaT_Signal_LM0_June2010.root";
  TString filename_MClm1  = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100927/muAlphaT_Signal_LM1_June2010.root";

  // DATA
  //  TString filename_DATAmu = "/vols/cms02/gouskos/onelepton/results_highpt_muons_RA4_20100928/Mu.root";
  //  TString filename_DATAmu = "/vols/cms02/gouskos/onelepton/results_highpt_muons_test/Mu_20100906/muAlphaT_Signal_Mu_20100906_B.root";
  TString filename_DATAmu = "/vols/cms02/gouskos/onelepton/results_highpt_muons_test/muAlphaT_Signal_Mu_20100906_B.root";

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



  // -----------
  // Define Cuts

  // Event Cuts
  TString RunNumber = "RunNumber==143962";

  // Trigger
  TString TrigMu9 = "trig_Mu9==1";

  // Muons
  TString MuN           = "NMuons==1";
  TString MuTightN      = "NTightMuons==1";
  TString Mu1ID         = "MuonTrackerMuon==1 && MuonGMPTMuon==1";
  TString Mu1Pt         = "MuonPt[0]>20."; 
  TString Mu1Eta        = "MuonEta[0]>-2.1 && MuonEta[0]<2.1";
  TString Mu1TightPt    = "MuonTightPt[0]>20."; 
  TString Mu1TightEta   = "MuonTightEta[0]>-2.1 && MuonTightEta[0]<2.1";
  TString Mu1Plus       = "MuonChrg[0] > 0.4";
  TString Mu1Minus      = "MuonChrg[0] < -0.4";
  TString Mu1DRJetVeto  = "MuonClosestComJetDR[0] > 0.3";
  TString Mu1RelCombIso = "MuonRelCombIso[0]<0.05";

  // Electrons
  TString ElN          = "NElectrons==0";
  TString El1Pt        = "ElectronsPt[0]>25."; 
  TString El1Eta       = "fabs(ElectronEta[0]<2.1)";
  TString ElRelCombIso = "ElectronRelCombIso[0]<0.05";

  // Jets
  TString JetN    = "NJet>=2";
  TString Jet1Pt  = "JetPt[0]>60."; 
  TString Jet1Eta = "fabs(JetEta[0]<2.4)";
  TString JetOdd  = "JetOdd==0";

  // General kinematic variables
  TString HT_Lep = "HT_Lep>100.";
  TString MHT_PF = "PFMHT>50.";
  TString MET    = "CaloMET>20.";


  // Cut Flow
  TString Cut_Trig = TrigMu9;

  //  TString Cut_Muons_Bas = MuN +" && "+ Mu1ID +" && "+ Mu1Pt +" && "+ Mu1Eta;
  TString Cut_Muons_1   = MuTightN;// +" && "+ Mu1TightPt +" && "+ Mu1TightEta;
  TString Cut_Muons_2   = MuN;
  TString Cut_Muons_Rel = Mu1RelCombIso;
  TString Cut_Muons_DRJ = Mu1DRJetVeto;
  TString Cut_Muons_Pos = Mu1Plus;
  TString Cut_Muons_Neg = Mu1Minus;
  TString Cut_Muons_Tot = Cut_Muons_1 +" && " + Cut_Muons_2;

  TString Cut_Electrons_Tot = ElN;

  TString Cut_Jets_Bas = JetN;
  TString Cut_Jets_Odd = JetOdd;
  TString Cut_Jets_Tot = Cut_Jets_Bas;

  TString Cut_MHT = MHT_PF;

  TString CutFlow_Final =  Cut_Trig +" && " + Cut_Muons_1 +" && " + Cut_Muons_2 +" && "+ Cut_Electrons_Tot +" && "+ Cut_Jets_Tot +" && "+ MET;
  //  TString CutFlowPlus_Final = Cut_Trig +" && " + Cut_Muons_Tot +" && " + Cut_Muons_2 +" && "+ Cut_Muons_Pos +" && "+ Cut_Electrons_Tot +" && "+ Cut_Jets_Tot +" && "+ MHT_PF;
  //  TString CutFlowMinus_Final = Cut_Trig +" && " + Cut_Muons_Tot +" && " + Cut_Muons_2 +" && "+ Cut_Muons_Neg +" && "+ Cut_Electrons_Tot +" && "+ Cut_Jets_Tot +" && "+ MHT_PF;

  
  const int numOfSteps = 5;
  TString CutFlowSteps[numOfSteps];
  CutFlowSteps[0] = RunNumber +" && "+ Cut_Trig +" && " + Cut_Muons_1;
  CutFlowSteps[1] = RunNumber +" && "+ Cut_Trig +" && " + Cut_Muons_1 +" && " + Cut_Muons_2;
  CutFlowSteps[2] = RunNumber +" && "+ Cut_Trig +" && " + Cut_Muons_Tot +" && "+ Cut_Electrons_Tot;
  CutFlowSteps[3] = RunNumber +" && "+ Cut_Trig +" && " + Cut_Muons_Tot +" && "+ Cut_Electrons_Tot +" && "+ Cut_Jets_Tot;
  CutFlowSteps[4] = RunNumber +" && "+ Cut_Trig +" && " + Cut_Muons_Tot +" && "+ Cut_Electrons_Tot +" && "+ Cut_Jets_Tot +" && "+ MET;

  TString CutFlowStepsNames[numOfSteps];
  CutFlowStepsNames[0] = "1 Tight Mu";
  CutFlowStepsNames[1] = "Veto 2nd Loose Muon";
  CutFlowStepsNames[2] = "Veto Els";
  CutFlowStepsNames[3] = "NJt>=2";
  CutFlowStepsNames[4] = "MET > 50.";


  cout << "\n";
  cout << "   CUT FLOW ~TABLE~ \n\n";
  cout.width(21);  cout << "CUT FLOW  ";
  cout.width(3);   cout << "| QCD      ";
  cout.width(13);  cout << "| Wjets    ";
  cout.width(13);  cout << "| Zjets    ";
  cout.width(13);  cout << "| TTbar    "; 
  cout.width(13);  cout << "| LM0      ";
  cout.width(13);  cout << "| LM1      ";
  cout.width(13);  cout << "| SM       ";
  cout.width(13);  cout << "| DATA     "; 
  cout.width(13);  cout << "\n";
  cout.width(128); cout.fill('-'); cout << "\n";
  cout.fill(' ');
  
  for (int i=0; i<numOfSteps; i++) {
    coutCutFlow(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,lumi,CutFlowSteps[i],CutFlowStepsNames[i]);
  }
  

  // -----------------------------
  // Data vs. MC comparison Plots
 
  /*  
  // Mu Multiplicity
  TCanvas *cMuMultiplicity = createCanvas("cMuMultiplicity",400,800,1,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMuMultiplicity,1,1,lumi,CutFlow_Final,"NMuons",11,-0.5,10.5,true);
    
  // Mu1 Charge
  TCanvas *cMu1Charge = createCanvas("cMu1Charge",400,800,1,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMu1Charge,1,1,lumi,CutFlow_Final,"MuonChrg[0]",5,-2.5,2.5,true);
  
  TString CutFlow_Test = Cut_Trig +" && "+ Cut_Muons_Tot;
  // Mu1 RelCombIsolation
  TCanvas *cMu1RelCombIso = createCanvas("cMu1RelCombIso",700,800,1,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMu1RelCombIso,1,1,lumi,CutFlow_Test,"MuonRelCombIso[0]",20,0.,1.,true); //250,0.,5. | 40,0.,0.8
  
  // Mu1 DR(mu1,jet)
  TCanvas *cMu1DRJet = createCanvas("cMu1DRJet",400,800,1,true);
  TString CutForThis2 = Cut_Muons_Bas +" && "+ Cut_Muons_Rel +" && "+ Cut_Muons_Odd;
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMu1DRJet,1,1,lumi,CutForThis2,"MuonClosestComJetDR[0]",50,0.,5.,true);
  
  // Mu1 Kinematics
  //  TCanvas *cMu1Kinematics = createCanvas("cMu1Kinematics",1200,800,3,true);
  TCanvas *cMu1Kinematics = createCanvas("cMu1Kinematics",400,800,1,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMu1Kinematics,1,1,lumi,CutFlow_Final,"MuonPt[0]",25,0.,250.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMu1Kinematics,2,3,lumi,CutFlow_Final,"MuonEta[0]",15,-3.,3.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMu1Kinematics,3,3,lumi,CutFlow_Final,"MuonPhi[0]",14,-3.5,3.5,true);
											  
  
  // Jet Multiplicity
  TCanvas *cJetMultiplicity = createCanvas("cJetMultiplicity",400,800,1,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJetMultiplicity,1,1,lumi,CutFlow_Final,"NJet",11,-0.5,10.5,true);
  
  // Jet1 Kinematics
  TCanvas *cJet1Kinematics = createCanvas("cJet1Kinematics",1200,800,3,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJet1Kinematics,1,3,lumi,CutFlow_Final,"JetPt[0]",12,50.,350.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJet1Kinematics,2,3,lumi,CutFlow_Final,"JetEta[0]",15,-3.,3.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJet1Kinematics,3,3,lumi,CutFlow_Final,"JetPhi[0]",14,-3.5,3.5,true);

  // Jet2 Kinematics
  TCanvas *cJet2Kinematics = createCanvas("cJet2Kinematics",1200,800,3,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJet2Kinematics,1,3,lumi,CutFlow_Final,"JetPt[1]",10,0.,250.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJet2Kinematics,2,3,lumi,CutFlow_Final,"JetEta[1]",15,-3.,3.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cJet2Kinematics,3,3,lumi,CutFlow_Final,"JetPhi[1]",14,-3.5,3.5,true);
    
  // HT, HT_Lep
  TCanvas *cHT = createCanvas("cHT",400,800,1,true);
  
  //  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
  //  cHT,1,2,lumi,CutFlow_Final,"HT",21,80.,940.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cHT,1,1,lumi,CutFlow_Final,"HT_Lep",21,80.,940.,true);
  
  // MHT, PFMHT
  TCanvas *cMHT = createCanvas("cMHT",800,800,2,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMHT,1,2,lumi,CutFlow_Final,"MHT",35,0.,350.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMHT,2,2,lumi,CutFlow_Final,"PFMHT",35,0.,350.,true);

  // MET, PFMET
  TCanvas *cMET = createCanvas("cMET",800,800,2,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMET,1,2,lumi,CutFlow_Final,"RecoilMET",20,0.,400.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMET,2,2,lumi,CutFlow_Final,"PFMET",20,0.,400.,true);

  // MT, PFMT
  TCanvas *cMT = createCanvas("cMT",800,800,2,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMT,1,2,lumi,CutFlow_Final,"MT",40,0.,200.,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cMT,2,2,lumi,CutFlow_Final,"PFMT",40,0.,200.,true);
  
  // LP+, LP-, LP total (PF)
  TCanvas *cLP = createCanvas("cLP",1200,800,3,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cLP,1,3,lumi,CutFlowPlus_Final,"PFLP",11,-0.6,1.6,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cLP,2,3,lumi,CutFlowMinus_Final,"PFLP",11,-0.6,1.6,true);
  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cLP,3,3,lumi,CutFlow_Final,"PFLP",11,-0.6,1.6,true);
  
  TCanvas *cLPB = createCanvas("cLPB",400,800,1,true);

  createDataVsMCcompRatio(tree_MCqcd,tree_MCw,tree_MCz,tree_MCtt,tree_MClm0,tree_MClm1,tree_DATAmu,
			  cLPB,1,1,lumi,CutFlow_Final,"MuonChrg[0]*(PFLP-1.5)",25,-2.5,2.5,true);

  
  // Save plots
  TString plotsFolder = "DATAvsMC/";

  cMuMultiplicity->Print("./Plots/"+plotsFolder+"MuMultiplicity.png");
  cMu1Charge->Print("./Plots/"+plotsFolder+"Mu1Charge.png");
  cMu1Kinematics->Print("./Plots/"+plotsFolder+"Mu1Kinematics.png");
  cMu1RelCombIso->Print("./Plots/"+plotsFolder+"Mu1RelCombIso.png");
  cMu1DRJet->Print("./Plots/"+plotsFolder+"Mu1DRJet.png");
  cJetMultiplicity->Print("./Plots/"+plotsFolder+"JetMultiplicity.png");
  cJet1Kinematics->Print("./Plots/"+plotsFolder+"Jet1Kinematics.png");
  cJet2Kinematics->Print("./Plots/"+plotsFolder+"Jet2Kinematics.png");
  cHT->Print("./Plots/"+plotsFolder+"HT.png");
  cMHT->Print("./Plots/"+plotsFolder+"MHT.png");
  cMET->Print("./Plots/"+plotsFolder+"MET.png");
  cMT->Print("./Plots/"+plotsFolder+"MT.png");
  cLP->Print("./Plots/"+plotsFolder+"LP.png");
  */    

} // ~ end of main function


  // ----------------
  // Help Functions
  

void createDataVsMCcompRatio(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,TTree *tree_DATAmu,
			     TCanvas *cCanvas,int cPad,int maxPads,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool useLog) {

  cCanvas->cd(cPad);

  if (useLog) { gPad->SetLogy(); }
  
  TH1F *hQCD  = create1Dhisto(tree_MCqcd,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hQCD->Sumw2();
  hQCD->SetName("hQCD");
  TH1F *hW    = create1Dhisto(tree_MCw,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hW->Sumw2();
  hW->SetName("hW");
  TH1F *hZ    = create1Dhisto(tree_MCz,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hZ->Sumw2();
  hZ->SetName("hZ");
  TH1F *hTT   = create1Dhisto(tree_MCtt,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hTT->Sumw2();
  hTT->SetName("hTT");
  TH1F *hSM   = (TH1F*)hW->Clone("hSM"); hSM->Add(hQCD); hSM->Add(hZ); hSM->Add(hTT);
  TH1F *hLM0  = create1Dhisto(tree_MClm0,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hLM0->Sumw2();
  hLM0->SetName("hLM0");
  TH1F *hLM1  = create1Dhisto(tree_MClm1,intLumi,cuts,branch,bins,xmin,xmax,false,useLog);
  //  hLM1->Sumw2();
  hLM1->SetName("hLM1");
  TH1F *hDATA = create1Dhisto(tree_DATAmu,intLumi,cuts,branch,bins,xmin,xmax,true,useLog);
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
  lPreliminary->Draw("same"); 
  lIntLumi->Draw("same"); 

  cCanvas->cd(cPad+maxPads);
  //  cCanvas->cd(cPad+1);
  gPad->SetGridx(); gPad->SetGridy();
  TH1F *hRatio = (TH1F*)hDATA->Clone("hRatio");
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
  
  cCanvas->Update();

} // ~ end of createDataVsMCcomp



TH1F *create1Dhisto(TTree *tree,TString intLumi,TString cuts,TString branch,int bins,float xmin,float xmax,bool DATA,bool useLog) {
  
  TString cut;
  
  if (!DATA) {cut ="(wgt*"+intLumi+")*("+cuts+")"; }
  else if (DATA) { cut ="(wgt)*("+cuts+")"; }
 

  TH1F *hTemp = new TH1F("hTemp","hTemp",bins,xmin,xmax);
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





float cout1Dhisto(TTree *tree,TString intLumi,TString cuts,bool DATA) {

  TString cut;
  if (!DATA) {cut ="(wgt*"+intLumi+")*("+cuts+")"; }
  else if (DATA) { cut ="(wgt)*("+cuts+")"; }
  //  if (!DATA) {cut =+cuts; }
  //  else if (DATA) { cut ="(wgt)*("+cuts+")"; }

  TH1F *hPass = new TH1F("hPass","hPass",1000,0.,1000.);
  hPass->SetName("hPass");
  tree->Project("hPass","PFMET",cut);
  float passed = hPass->Integral(0,500+1);

  hPass->Delete();
  return passed;
}




void coutCutFlow(TTree *tree_MCqcd,TTree *tree_MCw,TTree *tree_MCz,TTree *tree_MCtt,TTree *tree_MClm0,TTree *tree_MClm1,TTree *tree_DATAmu,
		 TString intLumi,TString cuts,TString cutFlowNames) {
    
  float cfQCD  = cout1Dhisto(tree_MCqcd,intLumi,cuts,false);
  float cfW    = cout1Dhisto(tree_MCw,intLumi,cuts,false);
  float cfZ    = cout1Dhisto(tree_MCz,intLumi,cuts,false);
  float cfTT   = cout1Dhisto(tree_MCtt,intLumi,cuts,false);
  float cfSM   = cfQCD + cfW + cfZ + cfTT;
  float cfLM0  = cout1Dhisto(tree_MClm0,intLumi,cuts,false);
  float cfLM1  = cout1Dhisto(tree_MClm1,intLumi,cuts,false);
  float cfDATA = cout1Dhisto(tree_DATAmu,intLumi,cuts,true);

  
  cout.width(20); cout << cutFlowNames << " | ";
  cout.width(10); cout << cfQCD  << " | ";
  cout.width(10); cout << cfW    << " | ";
  cout.width(10); cout << cfZ    << " | ";
  cout.width(10); cout << cfTT   << " | ";
  cout.width(10); cout << cfLM0  << " | ";
  cout.width(10); cout << cfLM1  << " | ";
  cout.width(10); cout << cfSM   << " | ";
  cout.width(10); cout << cfDATA << "\n";


} // ~ end of createDataVsMCcomp


TH1F *Divide2Histos(const TH1F* HistoInput1,const TH1F* HistoInput2) {

  TH1F *HistoOutput = (TH1F*)HistoInput1->Clone();
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



TLegend *legend1(TH1F *histo1, TH1F *histo2, TString histoLeg1, TString histoLeg2) {

  TLegend *leg = new TLegend(0.6,0.8,0.92,0.92);
  leg->AddEntry(histo1,histoLeg1,"PL");
  leg->AddEntry(histo2,histoLeg2,"PL");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.045);
  leg->SetTextFont(42);

  return leg;
}


TLegend *legendRAW() {
 
  TLegend *leg = new TLegend(0.75,0.7,0.92,0.93);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);

  return leg;
}



TLegend *legendHeader(TString header) {

  TLegend *leg = new TLegend(0.55,0.85,0.92,0.92);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.045);
  leg->SetTextFont(42);
  leg->SetHeader(header);

  return leg;
}
