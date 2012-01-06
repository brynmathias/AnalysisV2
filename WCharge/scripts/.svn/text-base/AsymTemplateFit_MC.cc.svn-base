/*********************************************************************************

This macro is intended for studying the template fit method for background 
subtraction for the W->enu analysis.

Inputs required:
----------------
The MC distributions for pfMET before/after signal selection and after anti-selection.  
These are provided in the root files in
/afs/cern.ch/user/f/futyand/public/WenuAnalysis/
These root files were in turn created by running the following macro:
UserCode/Futyan/macros/runWenuTemplateHistos_MC.C (instructions can be found in the file)

Configuration:
--------------
The macro takes 5 arguments (all optional with defaults):

1) ieff - efficiency working point: template histograms are generated separately to
correspond to different sets of electron isolation and ID cuts.  Possible values of 
ieff are 60, 70, 80, 90, correspoinding to 60%, 70%, 80% and 90% efficiency points. 
The cut values used are those used in the 2009 October exercise can be seen in 
UserCode/Futyan/macros/WenuTemplateHistos.h

2) The number of toy experiments

3) lumi - integrated luminosity, used to determine the number of pseudo data events in 
the toy data, in the calculation of the cross-section, and to determine binning for the 
template histos (100 bins for lumi<1., otherwise 200 bins).

4) ptCut on electron used in pre-selection in GeV (Must be 20 or 30.  Default is 20).

5) MET cut in GeV:  Signal yield and efficiency are calculated for MET greater than 
this threshold.  Default value of 30 is recommended.

The macro can be executed in root as follows (example arguments shown):

.L WenuTemplateFit_MC.cc
WenuTemplateFit_MC(80,5000,.1)

*********************************************************************************/


#include <algorithm>

void AsymTemplateFit_MC(int ieff=80, int maxExpt=500, float lumi=.4, int ptCut=25, int METCut=0 )
{
  gROOT->SetBatch();
  gROOT->Reset();   
  gROOT->SetStyle("Plain");// #To set plain bkgds for slides
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetLineWidth(0.25);
  gStyle->SetCanvasColor(0);//#Sets canvas colour white
  gStyle->SetLabelOffset(0.001);
//   gStyle->SetLabelSize(0.05);
//   gStyle->SetLabelSize(0.05,"Y");//#Y axis
  gStyle->SetLabelSize(0.05, "XYZ");
  gStyle->SetLabelColor(1, "XYZ");
  gStyle->SetLabelFont(42, "XYZ");
  gStyle->SetLabelOffset(0.007, "XYZ");
  gStyle->SetTitleSize(0.05);
  gStyle->SetTitleW(0.4);
  gStyle->SetTitleH(0.07);
  gStyle->SetOptTitle(1);
  gStyle->SetAxisColor(1, "XYZ");
  gStyle->SetStripDecimals(true);
  gStyle->SetTickLength(0.03, "XYZ");
  gStyle->SetNdivisions(510, "XYZ");
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);

  gStyle->SetHatchesLineWidth(3);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1111);
  gSystem->Load("libRooFit");
  using namespace RooFit;
  
  TString ptStr;
  if (ptCut==20) {
    ptStr="20";
  } else if (ptCut==30) {
    ptStr="30";
  } else if (ptCut==15) {
    ptStr="15";
  } else if (ptCut==25) {
    ptStr="25";
  }
  
  else {
    cout << "ptCut (4th argument) must be 20 or 30" << endl;
  }
  
  TString str_eff;
  if (ieff==60) str_eff="_WP60";
  else if (ieff==70) str_eff="_WP70";
  else if (ieff==80) str_eff="_WP80";
  else if (ieff==85) str_eff="_WP85";
  else if (ieff==90) str_eff="_WP90";
  else if (ieff==95) str_eff="_WP95";
  else {
    cout << "input argument (signal efficiency point) must be 60, 70, 80 ,85, 90 or 95" << endl;
    return;
  }
  
  TString AntiEv="h_anti_pfMET";
  TString TemplateLocation="./Templates/";
  TString DIR="Templates" + str_eff + "_Ele" + ptStr;
  //USE of Extended Maximum Likelihood fit
  bool EML= true;
  //AntiEventSelection
  int binMETCut = METCut+1;
  int nbins=50;
  int rebinFactor=2;
  if (lumi < 1.) {
    if (METCut%2!=0.) {
      cout << "METCut (5th Argument) must be a multiple of 2" << endl;
      continue;
    }
    nbins=50;
    binMETCut = METCut/2+1;
    rebinFactor=2;
  } 

  int ibmax =12;
  int iasmax=ibmax/2;

  TString Titles[12]={"Positrons |#eta|<0.4","Electrons |#eta|<0.4","Positrons 0.4<|#eta|<0.8",
		      "Electrons 0.4<|#eta|<0.8","Positrons 0.8<|#eta|>1.2","Electrons 0.8<|#eta|<1.2",
		      "Positrons 1.2<|#eta|<1.6","Electrons 1.2<|#eta|<1.6","Positrons 1.6<|#eta|<2.0",
		      "Electrons 1.6<|#eta|<2.0","Positrons 2.0<|#eta|<2.4","2.0<Electrons |#eta|<2.4"};
TFile *file[18];


  file[0] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_data.root");
  file[1] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wenu.root");

  file[2] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdEm_20-30.root");
  file[3] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdEm_30-80.root");
  file[4] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdEm_80-170.root");
  file[5] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdBce20-30.root");
  file[6] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdBce30-80.root");
  file[7] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdBce80-170.root");
  file[8] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_gj15-30.root");
  file[9] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_gj30-50.root");

  file[11] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wenuPlus.root");
  file[12] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wenuMinus.root");

  //file[14] = TFile::Open(TemplateLocation+"Templates_DYee_M1to10.root");
  file[15] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_dytautau.root");
  file[16] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_dyee.root");
  file[17] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wtaunu.root");
  file[18] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_ttbar.root");
  
  float NSignal[5000];
  float NBackground[5000];
  //  float fit_error_sel[5000];

  TString AsyTitles[6]={"|#eta|<0.4","0.4<|#eta|<0.8","0.8<|#eta|<1.2","1.2<|#eta|<1.6","1.6<|#eta|<2.0","|#eta|>2.0"};
  TString bins[12]={"_eta1_pos","_eta1_neg","_eta2_pos","_eta2_neg","_eta3_pos","_eta3_neg","_eta4_pos","_eta4_neg","_eta5_pos","_eta5_neg","_eta6_pos","_eta6_neg"}; 
  TH1F* hh_wenu_sel[12]; TH1F* hh_qcd_sel[12]; TH1F* hh_ewk_sel[12]; TH1F* hh_tot_sel[12];  
  TH1F* hh_wenu_sel_antisel[12]; TH1F* hh_qcd_sel_antisel[12]; 
  TH1F* hh_ewk_sel_antisel[12]; TH1F* hh_tot_sel_antisel[12];  
  TH1F* hhh_wenuewk[12];  TH1F* hhh_wenuewk_sel[12];
  //MICHELE IN BIN
  for (int ib=0; ib<ibmax;ib++){
    hh_wenu_sel[ib]=new TH1F("h_wenu_sel"+bins[ib],"wenu_sel"+bins[ib],nbins*rebinFactor,0.,100.);
    hh_qcd_sel[ib] = new TH1F("h_qcd_sel"+bins[ib],"qcd_sel"+bins[ib],nbins*rebinFactor,0.,100.);
    hh_ewk_sel[ib] = new TH1F("h_ewk_sel"+bins[ib],"ewk_sel"+bins[ib],nbins*rebinFactor,0.,100.);
    hh_tot_sel[ib] = new TH1F("h_tot_sel"+bins[ib], "tot_sel"+bins[ib], nbins*rebinFactor,0.,100.);    
    hh_wenu_sel_antisel[ib]=new TH1F("h_wenu_sel_antisel"+bins[ib],"wenu_sel_antisel"+bins[ib],nbins*rebinFactor,0.,100.);
    hh_qcd_sel_antisel[ib] = new TH1F("h_qcd_sel_antisel"+bins[ib],"qcd_sel_antisel"+bins[ib],nbins*rebinFactor,0.,100.);
    hh_ewk_sel_antisel[ib] = new TH1F("h_ewk_sel_antisel"+bins[ib],"ewk_sel_antisel"+bins[ib],nbins*rebinFactor,0.,100.);
    hh_tot_sel_antisel[ib] = new TH1F("h_tot_sel_antisel"+bins[ib], "tot_sel_antisel"+bins[ib],nbins*rebinFactor,0.,100.);    
    hhh_wenuewk_sel[ib] = new TH1F("h_wenuewk_sel"+bins[ib],"wenuewk_sel"+bins[ib],nbins,0.,100.);
  }
  
  //Define MC weights for 10pb-1
  double w[19];
  //for (unsigned i=1; i<19; i++) w[i]=lumi;  //w[i]=(w[i]/10.)*lumi;
  w[0] = 1;
  w[1] = (1.0/345.966)*lumi;

  w[2] = (1.0/14.900)*lumi;
  w[3] = (1.0/17.810)*lumi;
  w[4] = (1.0/57.875)*lumi;
  w[5] = (1.0/16.975)*lumi;
  w[6] = (1.0/14.587)*lumi;
  w[7] = (1.0/111.473)*lumi;
  w[8] = (1.0/5.392)*lumi;
  w[9] = (1.0/61.443)*lumi;

  w[11] = (1.0/345.966)*lumi;
  w[12] = (1.0/506.271)*lumi;

  w[15] = (1.0/1176.095)*lumi;
  w[16] = (1.0/1238.53)*lumi;
  w[17] = (1.0/537.272)*lumi;
  w[18] = (1.0/10633.511)*lumi;
  //MICHELE BIN
  TH1F *h1;
  for (int ib=0; ib<ibmax;ib++){
    
    //Read in template histograms
    //SIGNAL
//     file[1]->cd(DIR);
//     gDirectory->GetObject("h_pfMET"+bins[ib],h1);
//     //    h1->Sumw2();
//     hh_wenu_sel[ib]->Add(h1,w[1]);
//     gDirectory->GetObject(AntiEv+bins[ib],h1);
//     //    h1->Sumw2();
//     hh_wenu_sel_antisel[ib]->Add(h1,w[1]);

    file[11]->cd(DIR);
    gDirectory->GetObject("h_pfMET"+bins[ib],h1);
    //h1->Sumw2();
    hh_wenu_sel[ib]->Add(h1,w[11]);
    gDirectory->GetObject(AntiEv+bins[ib],h1);
    //h1->Sumw2();
    hh_wenu_sel_antisel[ib]->Add(h1,w[11]);
    
    file[12]->cd(DIR);
    gDirectory->GetObject("h_pfMET"+bins[ib],h1);
    //h1->Sumw2();
    hh_wenu_sel[ib]->Add(h1,w[12]);
    gDirectory->GetObject(AntiEv+bins[ib],h1);
    //h1->Sumw2();
    hh_wenu_sel_antisel[ib]->Add(h1,w[12]);
    
    //QCD
    for (unsigned i=2; i<10; i++) {
      file[i]->cd(DIR);
      gDirectory->GetObject("h_pfMET"+bins[ib],h1);
      //      h1->Sumw2();      
      hh_qcd_sel[ib]->Add(h1,w[i]);    
      gDirectory->GetObject(AntiEv+bins[ib],h1);
      //      h1->Sumw2();
      hh_qcd_sel_antisel[ib]->Add(h1,w[i]);
    }

    for (unsigned i=15; i<19; i++) {
      file[i]->cd(DIR);
      gDirectory->GetObject("h_pfMET"+bins[ib],h1);
      //      h1->Sumw2();
      hh_ewk_sel[ib]->Add(h1,w[i]);
      gDirectory->GetObject(AntiEv+bins[ib],h1);
      //      h1->Sumw2();
      hh_ewk_sel_antisel[ib]->Add(h1,w[i]);
    }
  }
  
  for (int ib=0; ib<ibmax;ib+=2){
    hh_qcd_sel[ib]->Add(hh_qcd_sel[ib+1]);
    hh_qcd_sel[ib]->Scale(0.5);
  }
  for (int ib=1; ib<ibmax;ib+=2){
    hh_qcd_sel[ib]->Add(hh_qcd_sel[ib-1]);
    hh_qcd_sel[ib]->Scale(0.5);
  } 
  
  for (int ib=0; ib<ibmax;ib++){
    hh_tot_sel[ib]->Add(hh_wenu_sel[ib]);
    hh_tot_sel[ib]->Add(hh_qcd_sel[ib]);   
    hh_tot_sel[ib]->Add(hh_ewk_sel[ib]);
    hh_tot_sel_antisel[ib]->Add(hh_wenu_sel_antisel[ib]);
    hh_tot_sel_antisel[ib]->Add(hh_qcd_sel_antisel[ib]);
    hh_tot_sel_antisel[ib]->Add(hh_ewk_sel_antisel[ib]);
    hh_tot_sel[ib]->Rebin(rebinFactor);
    hh_qcd_sel[ib]->Rebin(rebinFactor);
    hh_ewk_sel[ib]->Rebin(rebinFactor);
    hh_wenu_sel[ib]->Rebin(rebinFactor);
    hh_tot_sel_antisel[ib]->Rebin(rebinFactor);
    hh_qcd_sel_antisel[ib]->Rebin(rebinFactor);
    hh_ewk_sel_antisel[ib]->Rebin(rebinFactor);
    hh_wenu_sel_antisel[ib]->Rebin(rebinFactor);
    hhh_wenuewk_sel[ib]->Add(hh_wenu_sel[ib]);
    hhh_wenuewk_sel[ib]->Add(hh_ewk_sel[ib]);
    
  }
  float NNSignal_true[12],NNBackground_true[12],SSoverB_true[12];
  
  for (int ib=0; ib<ibmax;ib+=2){
    hh_tot_sel_antisel[ib]->Add(hh_tot_sel_antisel[ib+1]);
    hh_tot_sel_antisel[ib]->Scale(0.5);
  }
  for (int ib=1; ib<ibmax;ib+=2){
    hh_tot_sel_antisel[ib]->Add(hh_tot_sel_antisel[ib-1]);
    hh_tot_sel_antisel[ib]->Scale(0.5);
  } 
  
  for (int ib=0; ib<ibmax;ib++){
    NNSignal_true[ib] = hh_wenu_sel[ib]->Integral(binMETCut,nbins+1);
    NNBackground_true[ib] = hh_qcd_sel[ib]->Integral(binMETCut,nbins+1) + hh_ewk_sel[ib]->Integral(binMETCut,nbins+1);
    SSoverB_true[ib] = NNSignal_true[ib]/NNBackground_true[ib];   
  }
  float AsymTrue[6];
  for (int ias=0; ias<iasmax;ias++){
    AsymTrue[ias]=(NNSignal_true[ias*2]-NNSignal_true[ias*2+1])/(NNSignal_true[ias*2]+NNSignal_true[ias*2+1]);
    //cout<<AsymTrue[ias]<<endl;
  }
  float asym_sing_err[6];

  TCanvas *c1 = new TCanvas("c1","Background",1600,1050);
  c1->SetFillColor(10);
  c1->Divide(4,3);
  TCanvas *c2 = new TCanvas("c2","Signal",1600,1050);
  c2->SetFillColor(10);
  c2->Divide(4,3);
  TCanvas *c3 = new TCanvas("c3","Asymmetry",1600,1050);
  c3->SetFillColor(10);
  c3->Divide(2,3);
  TCanvas *c4 = new TCanvas("c4","Canvas4",1600,1050);
  c4->Divide(4,3);
  c4->SetFillColor(10);
  TLegend *l5_2 = new TLegend(0.7,0.5,0.9,0.9);
  TCanvas *c5 = new TCanvas("c5","Pull Asy Pois",1600,1050);
  c5->Divide(2,3);
  TCanvas *c6 = new TCanvas("c6","Pull Asy Tot",1600,1050);
  c6->Divide(2,3);
  TCanvas *c7 = new TCanvas("c7","Pull Signal Pois",1600,1050);
  c7->Divide(4,3);

  TCanvas *c8 = new TCanvas("c8","Pull Signal Tot",1600,1050);
  c8->Divide(4,3);



  TRandom *random = new TRandom();
  TH1F *hh_NSignal[12];TH1F *hh_NBackground[12];
  double nnTotal_sel[12],nnTotal_sel_antisel[12];
  TH1F *hh_data_sel[12];   TH1F *hh_data_antisel[12];   TH1F *hh_data_sel_antisel[12];
  TH1F *hh_bkg_sel_template[12];TH1F *hh_ewk_sel_fit[12];   TH1F * hh_wenu_sel_fit[12];
  TH1F *hh_bkg_sel_template_fit[12]; TH1F *hh_data_sel_bkgsubtracted[12];TH1F *hh_tot_sel_fit[12];
  TH1F *h_sig_pull[12];   TH1F *h_sig_pull_tot[12];

  for (int ib=0; ib<ibmax;ib++){
    
    hh_NSignal[ib] = new TH1F("h_NSignal"+bins[ib],"NSignal"+bins[ib],20,NNSignal_true[ib]*.95,NNSignal_true[ib]*1.05);
    hh_NBackground[ib] = new TH1F("h_NBackground"+bins[ib],"NBackground"+bins[ib],20,NNBackground_true[ib]*0.9,NNBackground_true[ib]*1.1);
    hh_data_sel[ib] = new TH1F("h_data_sel"+bins[ib], "data_sel"+bins[ib], nbins,0.,100.);
    hh_data_sel_antisel[ib] = new TH1F("h_data_sel_antisel"+bins[ib], "data_sel_antisel"+bins[ib], nbins,0.,100.);
    hh_bkg_sel_template[ib]  = new TH1F("h_bkg_sel_template"+bins[ib], "data_bkg_sel_template"+bins[ib], nbins,0.,100.);
    hh_wenu_sel_fit[ib] = new TH1F("h_wenu_fit"+bins[ib],"wenu_fit"+bins[ib],nbins,0.,100.);
    hh_ewk_sel_fit[ib] = new TH1F("h_ewk_fit"+bins[ib],"ewk_fit"+bins[ib],nbins,0.,100.);
    hh_bkg_sel_template_fit[ib] = new TH1F("h_bkg_template_fit"+bins[ib], "bkg_template_fit"+bins[ib], nbins,0.,100.);
    hh_data_sel_bkgsubtracted[ib] = new TH1F("h_data_sel_bkgsubtracted"+bins[ib],"data_sel_bkgsubtracted"+bins[ib],nbins,0.,100.);
    hh_tot_sel_fit[ib] = new TH1F("h_tot_fit"+bins[ib],"tot_fit"+bins[ib],nbins,0.,100.);
    nnTotal_sel[ib]          = hh_tot_sel[ib]->Integral();
    nnTotal_sel_antisel[ib]  = hh_tot_sel_antisel[ib]->Integral();
    h_sig_pull[ib] = new TH1F("h_sig_pull"+bins[ib],"sig_pull"+bins[ib],200,-5.,5.);
    h_sig_pull_tot[ib] = new TH1F("h_sig_pull_tot"+bins[ib],"sig_pull_tot"+bins[ib],200,-5.,5.);

  }

  TH1F *hh_asym[6];
  hh_asym[0]=new TH1F("hh_asym_eta0","hh_asym_eta0",nbins,0.8*AsymTrue[0],1.2*AsymTrue[0]);
  hh_asym[1]=new TH1F("hh_asym_eta1","hh_asym_eta1",nbins,0.8*AsymTrue[1],1.2*AsymTrue[1]);
  hh_asym[2]=new TH1F("hh_asym_eta2","hh_asym_eta2",nbins,0.8*AsymTrue[2],1.2*AsymTrue[2]);
  hh_asym[3]=new TH1F("hh_asym_eta3","hh_asym_eta3",nbins,0.8*AsymTrue[3],1.2*AsymTrue[3]);
  hh_asym[4]=new TH1F("hh_asym_eta4","hh_asym_eta4",nbins,0.8*AsymTrue[4],1.2*AsymTrue[4]);
  hh_asym[5]=new TH1F("hh_asym_eta5","hh_asym_eta5",nbins,0.8*AsymTrue[5],1.2*AsymTrue[5]);


  TH1F *hh_asym_pull[6];
  hh_asym_pull[0]=new TH1F("hh_asymPull_eta0","hh_asymPull_eta0",200,-5.,5.);
  hh_asym_pull[1]=new TH1F("hh_asymPull_eta1","hh_asymPull_eta1",200,-5.,5.);
  hh_asym_pull[2]=new TH1F("hh_asymPull_eta2","hh_asymPull_eta2",200,-5.,5.);
  hh_asym_pull[3]=new TH1F("hh_asymPull_eta3","hh_asymPull_eta3",200,-5.,5.);
  hh_asym_pull[4]=new TH1F("hh_asymPull_eta4","hh_asymPull_eta4",200,-5.,5.);
  hh_asym_pull[5]=new TH1F("hh_asymPull_eta5","hh_asymPull_eta5",200,-5.,5.);



  TH1F *hh_asym_pull_tot[6];
  hh_asym_pull_tot[0]=new TH1F("hh_asymPulltot_eta0","hh_asymPulltot_eta0",200,-5.,5.);
  hh_asym_pull_tot[1]=new TH1F("hh_asymPulltot_eta1","hh_asymPulltot_eta1",200,-5.,5.);
  hh_asym_pull_tot[2]=new TH1F("hh_asymPulltot_eta2","hh_asymPulltot_eta2",200,-5.,5.);
  hh_asym_pull_tot[3]=new TH1F("hh_asymPulltot_eta3","hh_asymPulltot_eta3",200,-5.,5.);
  hh_asym_pull_tot[4]=new TH1F("hh_asymPulltot_eta4","hh_asymPulltot_eta4",200,-5.,5.);
  hh_asym_pull_tot[5]=new TH1F("hh_asymPulltot_eta5","hh_asymPulltot_eta5",200,-5.,5.);


  for (int iexpt=0;iexpt<maxExpt;iexpt++) {
    if (iexpt%20==0. && iexpt>0) cout << iexpt << endl;
    float signalevents[12];
    float signalerror[12];    
    for (int ib=0; ib<ibmax;ib++){
    
      int nData_sel = random->Poisson(nnTotal_sel[ib]);
      int nData_sel_antisel = random->Poisson(nnTotal_sel_antisel[ib]);
      hh_data_sel[ib]->Reset();
      hh_data_sel_antisel[ib]->Reset();
      hh_data_sel[ib]->FillRandom(hh_tot_sel[ib],nData_sel);
      hh_data_sel_antisel[ib]->FillRandom(hh_tot_sel_antisel[ib],nData_sel_antisel);
      //hh_data_sel_antisel[ib]->FillRandom(hh_qcd_sel[ib],nData_sel_antisel);

      double frac_wenuewk,frac_bkg,frac_wenuewk_err,frac_bkg_err;

      RooRealVar pfMET("pfMET","pfMET",0.,100.);
      RooRealVar fsig("fsig","signal fraction",0.5,0.,1.);   


      hh_bkg_sel_template[ib]->Reset();
      hh_bkg_sel_template[ib]->Add(hh_data_sel_antisel[ib]);
  
      for (int j=0;j<nbins+1;j++)
	if (hh_bkg_sel_template[ib]->GetBinContent(j)<0.) hh_bkg_sel_template[ib]->SetBinContent(j,0.);
      TH1* hhhh_wenuewk_sel = (TH1*)  hhh_wenuewk_sel[ib]->Clone();
      TH1* hhhh_bkg_sel_template = (TH1*) gDirectory->Get("h_bkg_sel_template"+bins[ib]);
      TH1* hhhh_data_sel = (TH1*) gDirectory->Get("h_data_sel"+bins[ib]);

      RooDataHist roohist_wenuewk_sel("roohist_wenuewk_sel","wenuewk with pfMET",pfMET,hhhh_wenuewk_sel);
      RooDataHist roohist_bkg_sel_template("roohist_bkg_sel_template","bkg_template with pfMET",pfMET,hhhh_bkg_sel_template);
      RooHistPdf pdf_wenuewk_sel("pdf_wenuewk_sel","wenuewk with pfMET",RooArgList(pfMET),roohist_wenuewk_sel);
      RooHistPdf pdf_bkg_sel_template("pdf_bkg_sel_template","bkg_template with pfMET",RooArgList(pfMET),roohist_bkg_sel_template);
      RooDataHist roohist_data_sel("roohist_data_sel","data with pfMET",pfMET,hhhh_data_sel);
      double err_frac_wenuewk=0.;    
      
      RooRealVar nsig("nsig","signal fraction",0.,1000000.);
      RooRealVar nbkg("nbkg","background fraction",0.,1000000.);  
      RooAddPdf model_sel("model_sel","model_sel",RooArgList(pdf_wenuewk_sel,pdf_bkg_sel_template),RooArgList(nsig,nbkg));
      model_sel.fitTo(roohist_data_sel,Extended(kTRUE),SumW2Error(kFALSE),PrintLevel(-2),InitialHesse(kTRUE)); //,InitialHesse(kTRUE)
      double	nwenuewk_fit = nsig.getVal();
      double nbkg_fit = nbkg.getVal();
      double nwenuewk_fit_err = nsig.getError();
      double nbkg_fit_err = nbkg.getError(); 
      frac_wenuewk = nwenuewk_fit/(nwenuewk_fit+nbkg.getVal());
      frac_bkg = 1.-frac_wenuewk;
      
      err_frac_wenuewk=sqrt(pow(nwenuewk_fit*nbkg_fit_err,2)+
                            pow(nbkg_fit*nwenuewk_fit_err,2))/
        pow(nwenuewk_fit+nbkg_fit,2);
      
      

      double frac_wenu = frac_wenuewk*(hh_wenu_sel[ib]->Integral()/hhhh_wenuewk_sel->Integral());
      double frac_ewk = frac_wenuewk*(hh_ewk_sel[ib]->Integral()/hhhh_wenuewk_sel->Integral());

      hh_wenu_sel_fit[ib]->Reset();
      hh_wenu_sel_fit[ib]->Add(hh_wenu_sel[ib]);
      hh_ewk_sel_fit[ib]->Reset();
      hh_ewk_sel_fit[ib]->Add(hh_ewk_sel[ib]);
      hh_bkg_sel_template_fit[ib]->Reset();
      hh_bkg_sel_template_fit[ib]->Add(hh_bkg_sel_template[ib]);

      hh_tot_sel_fit[ib]->Reset();     
      hh_tot_sel_fit[ib]->Add(hh_wenu_sel[ib],frac_wenu*(hh_data_sel[ib]->Integral())/hh_wenu_sel[ib]->Integral());
      hh_tot_sel_fit[ib]->Add(hh_ewk_sel[ib],frac_ewk*(hh_data_sel[ib]->Integral())/hh_ewk_sel[ib]->Integral());
      hh_tot_sel_fit[ib]->Add(hh_bkg_sel_template_fit[ib],frac_bkg*(hh_data_sel[ib]->Integral())/hh_bkg_sel_template[ib]->Integral());
//       //     //Scale template histograms according to fit result (after selection)
      hh_wenu_sel_fit[ib]->Scale(frac_wenu*(hh_data_sel[ib]->Integral())/hh_wenu_sel[ib]->Integral());
      hh_ewk_sel_fit[ib]->Scale(frac_ewk*(hh_data_sel[ib]->Integral())/hh_ewk_sel[ib]->Integral());

      hh_bkg_sel_template_fit[ib]->Scale(frac_bkg*(hh_data_sel[ib]->Integral())/hh_bkg_sel_template[ib]->Integral());
      hh_data_sel_bkgsubtracted[ib]->Reset();
      hh_data_sel_bkgsubtracted[ib]->Add(hh_data_sel[ib]);
      hh_data_sel_bkgsubtracted[ib]->Add(hh_bkg_sel_template_fit[ib],-1.);
      hh_data_sel_bkgsubtracted[ib]->Add(hh_ewk_sel_fit[ib],-1.);
      for (int j=0;j<nbins+1;j++) {

	hh_data_sel_bkgsubtracted[ib]->SetBinError(j,hh_data_sel[ib]->GetBinError(j));
      }
      NSignal[iexpt] = hh_data_sel_bkgsubtracted[ib]->Integral(binMETCut,nbins+1);
  
      signalevents[ib]= NSignal[iexpt];
     hh_NSignal[ib]->Fill(NSignal[iexpt]);

    
    signalerror[ib]=NSignal[iexpt]*nwenuewk_fit_err/nwenuewk_fit; 
    h_sig_pull[ib]->Fill((NSignal[iexpt]-NNSignal_true[ib])/sqrt(NSignal[iexpt]));
    h_sig_pull_tot[ib]->Fill((NSignal[iexpt]-NNSignal_true[ib])/signalerror[ib]);
    
    NBackground[iexpt] = hh_bkg_sel_template_fit[ib]->Integral(binMETCut,nbins+1) + hh_ewk_sel_fit[ib]->Integral(binMETCut,nbins+1);
      hh_NBackground[ib]->Fill(NBackground[iexpt]);

     if(iexpt==4){
       c4->cd(ib+1);
       //hhhh_data_sel->SetMaximum(15);
       hhhh_data_sel->SetMarkerSize(.75);
       hhhh_data_sel->SetMarkerStyle(20);
       hhhh_data_sel->SetMinimum(0);
       //hhhh_data_sel->SetMaximum(600);
       hhhh_data_sel->SetTitle(Titles[ib]);
//        hhhh_data_sel->GetXaxis()->SetTitleSize(0.06);
//        hhhh_data_sel->GetYaxis()->SetTitleSize(0.06);
//        hhhh_data_sel->GetYaxis()->SetTitleOffset(0.4);
//        hhhh_data_sel->GetXaxis()->SetTitleOffset(0.6);
       hhhh_data_sel->GetXaxis()->SetTitle("PFMet (GeV)");
       hhhh_data_sel->GetYaxis()->SetTitle("Events/2 GeV");
       hhhh_data_sel->Draw("e");
       
       hh_tot_sel_fit[ib]->SetLineStyle(2);
       hh_tot_sel_fit[ib]->SetLineColor(3);
       
       
       hh_wenu_sel_fit[ib]->SetLineColor(4);
       hh_wenu_sel_fit[ib]->SetLineWidth(2.);
       hh_wenu_sel_fit[ib]->Draw("same");
       hh_tot_sel_fit[ib]->Draw("same");
       
       
       THStack *h_back_sel_fit = new THStack("h_back_sel_fit","background from fit after selection");
       
       
       
       h_back_sel_fit->Add(hh_ewk_sel_fit[ib]);
       h_back_sel_fit->Add(hh_bkg_sel_template_fit[ib]); 
       
       
       
       hh_ewk_sel_fit[ib]->SetFillColor(3); 
       
       h_back_sel_fit->Draw("same");
       
       
       
       if (ib==0){
	 l5_2->AddEntry(hhhh_data_sel,"ALL","p");
	 l5_2->AddEntry(h_back_sel_fit,"QCD","l");
	 l5_2->AddEntry(hh_wenu_sel_fit[ib],"Signal","l");
	 l5_2->AddEntry(hh_ewk_sel_fit[ib],"EWK","f");
	 l5_2->AddEntry(hh_tot_sel_fit[ib],"Fit","l");
	 
         l5_2->Draw();
       }

     }
     
     
    }

    for (int ias=0; ias<iasmax;ias++){
      float pos=signalevents[ias*2];
      float neg=signalevents[ias*2+1];
      float errpos=signalerror[ias*2];
      float errneg=signalerror[ias*2+1];
      float Asym=(pos-neg)/(pos+neg);
      //       float Asym=(hh_NSignal[ias*2]->Integral()-hh_NSignal[ias*2+1]->Integral())/
      // 	(hh_NSignal[ias*2]->Integral()+hh_NSignal[ias*2+1]->Integral());
      //      cout<<"ETA "<<ias+1<<" "<<pos<<" "<<neg<<" "<<Asym<<endl;
      //       cout<<"ASYM toy "<< Asym<<endl;
      hh_asym[ias]->Fill(Asym);
      float asymErr=2 * sqrt(pos*neg)/pow(pos+neg,1.5);
      float asymErrTot=2 * sqrt((pos*pos*errneg*errneg)+(neg*neg*errpos*errpos))/pow(pos+neg,2.);  
      hh_asym_pull[ias]->Fill((Asym-AsymTrue[ias])/asymErr);
      hh_asym_pull_tot[ias]->Fill((Asym-AsymTrue[ias])/asymErrTot);
      if(iexpt==4){

	asym_sing_err[ias]=asymErr;
	//	cout<<"asymErr "<<asymErr<<endl;
      }

    }


  }//FINE LOOP ESPERIMENTO

//start output to file

  ofstream outputfile("./"+AntiEv+"_data.py");

  TString bg_diff = "bg_diff = (";
  TString sg_diff = "sg_diff = (";
  TString asym_diff = "asym_diff = (";
// 
  TString sg_pull = "sg_pull = (";
  TString asym_pull = "asym_pull = (";
  
  //end output to file

  for (int ib=0; ib<ibmax;ib++){
    hh_NBackground[ib]->SetTitle(Titles[ib]);
//     hh_NBackground[ib]->GetYaxis()->SetTitleOffset(0.4);
//     hh_NBackground[ib]->GetYaxis()->SetTitleSize(0.1);
//     hh_NBackground[ib]->GetXaxis()->SetTitleOffset(0.5);
//     hh_NBackground[ib]->GetXaxis()->SetTitleSize(0.1);
//     hh_NBackground[ib]->GetXaxis()->SetLabelSize(.06);
//     hh_NBackground[ib]->GetYaxis()->SetLabelSize(.06);
    hh_NBackground[ib]->GetXaxis()->SetTitle("Background Yield");
    hh_NBackground[ib]->GetYaxis()->SetTitle("N Experiments"); 
    hh_NBackground[ib]->SetFillColor(42);
    c1->cd(ib+1);
    hh_NBackground[ib]->Draw();
    TF1 *f0= new TF1("gaus","gaus",0,5);
    hh_NBackground[ib]->Fit(f0,"Q");
    TLine *line4 = new TLine(NNBackground_true[ib],0.,NNBackground_true[ib],hh_NBackground[ib]->GetMaximum()*1.05);
    line4->SetLineColor(4);
    line4->SetLineWidth(2);
    line4->Draw();

    c2->cd(ib+1);
    hh_NSignal[ib]->SetTitleSize(100.);
    hh_NSignal[ib]->SetTitle(Titles[ib]);

//     hh_NSignal[ib]->GetYaxis()->SetTitleOffset(0.4);
//     hh_NSignal[ib]->GetYaxis()->SetTitleSize(0.1);
//     hh_NSignal[ib]->GetXaxis()->SetTitleOffset(0.5);
//     hh_NSignal[ib]->GetXaxis()->SetTitleSize(0.1);
//     hh_NSignal[ib]->GetXaxis()->SetLabelSize(.06);
//     hh_NSignal[ib]->GetYaxis()->SetLabelSize(.06);
    hh_NSignal[ib]->GetXaxis()->SetTitle("Signal Yield");
    hh_NSignal[ib]->GetYaxis()->SetTitle("N Experiments");    
    hh_NSignal[ib]->SetFillColor(42);

//     //  hh_NSignal[ib]->GetXaxis()->SetTitleSize(.08);
//     //    hh_NSignal[ib]->GetXaxis()->SetTitle("NSignal after Wenu selection");
    hh_NSignal[ib]->Draw();
    TF1 *f1= new TF1("gaus","gaus",NNSignal_true[ib]*0.2,NNSignal_true[ib]*3);
    hh_NSignal[ib]->Fit(f1,"Q");

    TLine *line5 = new TLine(NNSignal_true[ib],0.,NNSignal_true[ib],hh_NSignal[ib]->GetMaximum()*1.05);
    line5->SetLineColor(4);
    line5->SetLineWidth(2);
    line5->Draw();
    cout<<"BIN "<<bins[ib]<<endl
	<<" BKG TRUE = "<<NNBackground_true[ib]<<" BKG FROM TOY= "<<f0->GetParameter(1)<<" +/- "<<f0->GetParError(1)<<endl
	<<" SIG TRUE = "<<NNSignal_true[ib]<<" SIG FROM TOY= "<<f1->GetParameter(1)<<" +/- "<<f1->GetParError(1)<<endl;
	
	//start output to file
	
    bg_diff+="(";
    bg_diff+=(f0->GetParameter(1) - NNBackground_true[ib]);
    bg_diff+=",";
    bg_diff+=f0->GetParError(1);
    bg_diff+=",";
    bg_diff+=f0->GetParameter(2);
    bg_diff+="), ";
    
    sg_diff+="(";
    sg_diff+=(f1->GetParameter(1) - NNSignal_true[ib]);
    sg_diff+=",";
    sg_diff+=f1->GetParError(1);
    sg_diff+=",";
    sg_diff+=f1->GetParameter(2);
    sg_diff+="), ";
	
	//end output to file
	
   TF1 *f4= new TF1("gaus","gaus",-5.,5.); 
     TF1 *f5= new TF1("gaus","gaus",-5.,5.);
    c7->cd(ib+1); 
    h_sig_pull[ib]->Fit(f4,"Q"); 
    cout<<"PULL "<<f4->GetParameter(1)<<" +/- "<<f4->GetParError(1)<<" "<<f4->GetParameter(2)<<endl; 
    c8->cd(ib+1); 
    //h_sig_pull_tot[ib]->Draw(); 
    h_sig_pull_tot[ib]->Fit(f5,"Q"); 
    cout<<"PULL TOT "<<f5->GetParameter(1)<<" +/- "<<f5->GetParError(1)<<" "<<f5->GetParameter(2)<<endl;

    	//start output to fil
    sg_pull+="(";
    sg_pull+=f5->GetParameter(1);
    sg_pull+=",";
    sg_pull+=f5->GetParError(1);
    sg_pull+=",";
    sg_pull+=f5->GetParameter(2);
    sg_pull+="), ";
    	//end output to file
  }
 
 //start output to file
 bg_diff+=")";
 sg_diff+=")";
 sg_pull+=")";
  
 outputfile<<bg_diff<<endl;
 outputfile<<sg_diff<<endl;
 outputfile<<sg_pull<<endl;
 //end output to file

  for (int ias=0; ias<iasmax;ias++){
    hh_asym[ias]->SetTitle(AsyTitles[ias]);
    hh_asym[ias]->SetFillColor(42);
//     hh_asym[ias]->GetYaxis()->SetTitleOffset(0.4);
//     hh_asym[ias]->GetYaxis()->SetTitleSize(0.1);
//     hh_asym[ias]->GetXaxis()->SetTitleOffset(0.65);
//     hh_asym[ias]->GetXaxis()->SetTitleSize(0.1);
//     hh_asym[ias]->GetXaxis()->SetLabelSize(.08);
//     hh_asym[ias]->GetYaxis()->SetLabelSize(.08);
    hh_asym[ias]->GetXaxis()->SetTitle("Asymmety");
    hh_asym[ias]->GetYaxis()->SetTitle("N Experiments");
    c3->cd(ias+1);
    hh_asym[ias]->Draw();
    TF1 *f2= new TF1("gaus","gaus",AsymTrue[ias]*-0.2,AsymTrue[ias]*3);
    hh_asym[ias]->Fit(f2,"Q");
    TLine *line6 = new TLine(AsymTrue[ias],0.,AsymTrue[ias],hh_asym[ias]->GetMaximum()*1.05);
    line6->SetLineColor(4);
    line6->SetLineWidth(2);
    line6->Draw();
    cout<<"ETA BIN "<<ias+1<<endl
	<<"ASYM TRUE = "<<AsymTrue[ias]<<" ASYM FROM TOY = "<<f2->GetParameter(1)<<" +/- "<<f2->GetParError(1)<<endl
	<<" ASYM SIGMA = "<<f2->GetParameter(2)<<" only poisson "<<" "<<asym_sing_err[ias]<<endl;
	
 //start output to file
    asym_diff+="(";
    asym_diff+=(f2->GetParameter(1) - AsymTrue[ias]);
    asym_diff+=",";
    asym_diff+=f2->GetParError(1);
    asym_diff+=",";
    asym_diff+=f2->GetParameter(2);
    asym_diff+="), ";
 //end output to file
	
	
    TF1 *f3= new TF1("gaus","gaus",-5.,5.);
    TF1 *f6= new TF1("gaus","gaus",-5.,5.);
    c5->cd(ias+1);
    hh_asym_pull[ias]->Fit(f3,"Q");
    cout<<"PULL "<<f3->GetParameter(1)<<" +/- "<<f3->GetParError(1)<<" "<<f3->GetParameter(2)<<endl;
    c6->cd(ias+1);
    hh_asym_pull_tot[ias]->Fit(f6,"Q");
    cout<<"PULL TOT "<<f6->GetParameter(1)<<" +/- "<<f6->GetParError(1)<<" "<<f6->GetParameter(2)<<endl;
    
 //start output to file
    asym_pull+="(";
    asym_pull+=f6->GetParameter(1);
    asym_pull+=",";
    asym_pull+=f6->GetParError(1);
    asym_pull+=",";
    asym_pull+=f6->GetParameter(2);
    asym_pull+="), ";
     //end output to file

  } 

  asym_diff+=")";
  asym_pull+=")";
 
  outputfile<<asym_diff<<endl;
  outputfile<<asym_pull<<endl;
  
  c1->SaveAs(TemplateLocation+"bkyield.pdf");
  c2->SaveAs(TemplateLocation+"sigyield.pdf");
  c3->SaveAs(TemplateLocation+"toyasym.pdf");
  c4->SaveAs(TemplateLocation+"singlefit.pdf");
  c5->SaveAs(TemplateLocation+"pullasyPois.pdf");
  c6->SaveAs(TemplateLocation+"pullasyTot.pdf");
  c7->SaveAs(TemplateLocation+"pullsigPois.pdf");
  c8->SaveAs(TemplateLocation+"pullsigTot.pdf");
  
  file[0]->Close();
  file[1]->Close();
  file[2]->Close();
  file[3]->Close();
  file[4]->Close();
  file[5]->Close();
  file[6]->Close();
  file[7]->Close();
  file[8]->Close();
  file[9]->Close();

  //file[14]->Close();
  file[15]->Close();
  file[16]->Close();
  file[17]->Close(); 
  file[18]->Close(); 

  outputfile.close();
  cout<<"done"<<endl;
  
}
