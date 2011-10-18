#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <vector>
#include <string>

#include "ExclusionPlot.hh"

#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TMarker.h"
#include "vector.h"
#include "TMath.h"
#include "TList.h"
#include "TGraph.h"
#include "TObjArray.h"

void ExclusionPlot(){
  gStyle->SetPalette(1);

  Int_t tanBeta = 3;
  CommandMSUGRA("35pb_expected_11.root",tanBeta,1);


}



void CommandMSUGRA(TString plotName_,
       Int_t tanBeta_){

  //convert tanb value to string
  std::stringstream tmp;
  tmp << tanBeta_;
  TString tanb( tmp.str() );


  // Output file
  cout << " create " << plotName_ << endl;
  TFile* output = new TFile( plotName_, "RECREATE" );
  if ( !output || output->IsZombie() ) { std::cout << " zombie alarm output is a zombie " << std::endl; }


  //set old exclusion Limits
  // TGraph* LEP_ch = set_lep_ch(tanBeta_);
  // TGraph* myLEP_ch = set_lep_ch(tanBeta_);
  // myLEP_ch->SetFillColor(10);
  // myLEP_ch->SetFillStyle(1001);
  // TGraph* LEP_sl = set_lep_sl(tanBeta_);//slepton curve
  // TGraph* TEV_sg_cdf = set_tev_sg_cdf(tanBeta_);//squark gluino cdf
  // TGraph* TEV_sg_d0 = set_tev_sg_d0(tanBeta_);//squark gluino d0
  TGraph* stau = set_tev_stau(tanBeta_);//stau
  TGraph* NoEWSB = set_NoEWSB(tanBeta_);


  //  TGraph* TEV_sn_d0_1 = set_sneutrino_d0_1();
  //  TGraph* TEV_sn_d0_2 = set_sneutrino_d0_2();

  //constant ssqquark and gluino lines
  TF1* lnsq[6];
  TF1* lngl[6];

  TLatex* sq_text[6];
  TLatex* gl_text[6];

  for(int i = 0; i < 5; i++){
    lnsq[i] = constant_squark(tanBeta_,i);
    sq_text[i] = constant_squark_text(i,*lnsq[i],tanBeta_);
    lngl[i] = constant_gluino(tanBeta_,i);
    gl_text[i] = constant_gluino_text(i,*lngl[i],tanBeta_);
  }

  //Legends
  TLegend* legst = makeStauLegend(0.05,tanBeta_);
  //  TLegend* legexp = makeExpLegend( *TEV_sg_cdf,*TEV_sg_d0,*LEP_ch,*LEP_sl,*TEV_sn_d0_1,0.03,tanBeta_);
  TLegend* legNoEWSB  = makeNoEWSBLegend(0.05,tanBeta_);

  //make Canvas
  TCanvas* cvsSys = makeCanvas(tanb);
  output->cd();

  //and now
  //the exclusion limits
  TGraphErrors* First ;
  TGraphErrors* Second;
  TGraphErrors* Third;
  TGraphErrors* Second_up;
  TGraphErrors* Second_low;
  TGraphErrors* Fourth;
  QCDZero = get1080QCDExpExp();
  QCDSideBand = get1080SidBandExp();
  if(tanBeta_ == 3){
    First = getObserved_NLO_tanBeta3();
    Second = getExpected_NLO_tanBeta3();
    Second_up = getExpected_NLO_tanBeta3_up();
    Second_low = getExpected_NLO_tanBeta3_low();
    //Third = getLO_tanBeta3();
  }
  if(tanBeta_ == 10){

    //PL
    //    First = get1080ObsNLO();
    //    Second = get1080Exp();
    //    Second_up = get1080Up();
    //    Second_low = get1080Low();
    //Third = get1080ObsLO();
    Fourth = getObserved_NLO_tanBeta10();

    //CLs
    //  First = getCLs1080ObsNLO();
    //   Second = getCLs1080Exp();
    //    Second_up = getCLs1080Up();
    //    Second_low = getCLs1080Low();
        Third = get1080Exp();
    //Third = getCLs1080ObsNLO();

  }
  if(tanBeta_ == 40){
    // First = getObserved_NLO_tanBeta50();
    // Second = getExpected_NLO_tanBeta50();
    // Second_up = getExpected_NLO_tanBeta50_up();
    // Second_low = getExpected_NLO_tanBeta50_low();

    Third = get1080Exp();
    Fourth = get1080Exp();

  }



  TGraphErrors* ATLcomb;
  ATLcomb = getATLAScomb();

  TGraphErrors* ATLPLHC;
  ATLPLHC = getATLASPLHC();




  //   TH2F* hist = getHisto("/home/hep/elaird1/public_html/57_stat_plots/05_cmssm_fc/","ExclusionLimit","feldmanCousins_tanBeta"+tanb+"_nlo_1HtBin_expR.root");

  TH2F* hist = new TH2F("h1","h1",100,0,2000,100,0,750);

  hist->GetXaxis()->SetRangeUser(0,500);
  if (tanBeta_ == 10)  hist->GetXaxis()->SetRangeUser(0,2000);
  if (tanBeta_ == 40)  hist->GetXaxis()->SetRangeUser(380,2000);
  hist->GetYaxis()->SetRangeUser(120,750);


  hist->SetLineWidth(3);
  hist->SetLineColor(9);
  hist->SetLineStyle(2);

  output->cd();
  hist->Reset();
  hist->Draw();

  cvsSys->Update();

  hist->GetXaxis()->SetTitle("m_{0} (GeV)");
  hist->GetYaxis()->SetTitle("m_{1/2} (GeV)");
  hist->GetYaxis()->SetTitleOffset(1.);
  hist->GetXaxis()->SetNdivisions(506);
  //  if (tanBeta_ == 50)  hist->GetXaxis()->SetNdivisions(504);
  hist->GetYaxis()->SetNdivisions(506);



  TSpline3 *sATLcomb = new TSpline3("sATLcomb",ATLcomb);
  sATLcomb->SetLineColor(kGreen);
  sATLcomb->SetLineWidth(3);


  //  TSpline3 *sFirst = new TSpline3("sFirst",First);
  TSpline3 *sFirst =  getCLs1080ObsNLO();
  if (tanBeta_ ==40)  TSpline3 *sFirst =  getCLs1080ObsNLOtb40();
  sFirst->SetLineColor(kRed);
  sFirst->SetLineWidth(3);

  //  TSpline3 *sSecond = new TSpline3("sSecond",Second);
  TSpline3 *sSecond = getCLs1080Exp();
  if (tanBeta_ ==40)  TSpline3 *sSecond = getCLs1080Exptb40();
  sSecond->SetLineColor(kBlue+3);
  sSecond->SetLineStyle(4);
  sSecond->SetLineWidth(3);
  //  sSecond->SetFillStyle(3001);
  //  sSecond->SetFillColor(kAzure-9);

  //  TSpline3 *sSecond_up = new TSpline3("sSecond_up",Second_up);
  TSpline3 *sSecond_up = getCLs1080Up();
  //TSpline3 *sSecond_up = getCLs1080ObsNLOtb40();
  if (tanBeta_ == 40) TSpline3 *sSecond_up = getCLs1080Uptb40();
  sSecond_up->SetLineColor(kAzure+1);
  sSecond_up->SetLineStyle(1);
  sSecond_up->SetLineWidth(3);

  //  TSpline3 *sSecond_low = new TSpline3("sSecond_low",Second_low);
  TSpline3 *sSecond_low = getCLs1080Low();
  //TSpline3 *sSecond_low = getCLs1080Exptb40();
  if (tanBeta_ ==40) TSpline3 *sSecond_low = getCLs1080Lowtb40();
  sSecond_low->SetLineColor(kAzure+1);
  sSecond_low->SetLineStyle(1);
  sSecond_low->SetLineWidth(3);


  TSpline3 *sQCDZero = new TSpline3("sQCDZero",QCDZero);
  sQCDZero->SetLineColor(kPink-7);
  sQCDZero->SetLineWidth(3);
  TSpline3 *sQCDSideBand = new TSpline3("sQCDSideBand",QCDSideBand);
  sQCDSideBand->SetLineColor(kBlue-7);
  sQCDSideBand->SetLineWidth(3);

  TSpline3 *sThird = new TSpline3("sThird",Third);
  sThird->SetLineColor(kGreen+2);
  sThird->SetLineStyle(9);
  sThird->SetLineWidth(3);

  TSpline3 *sFourth = new TSpline3("sFourth",Fourth);
  sFourth->SetLineColor(6);
  sFourth->SetLineStyle(9);
  sFourth->SetLineWidth(3);

  TSpline3 *sFifth = new TSpline3("sFifth",ATLPLHC);
  sFifth->SetLineColor(kOrange+8);
  sFifth->SetLineStyle(7);
  sFifth->SetLineWidth(3);

  //  sSecond_up->SetFillStyle(4010);
  //  sSecond_up->SetFillColor(kCyan-10);

  //default
  sSecond_up->SetFillStyle(3001);
  sSecond_up->SetFillColor(kAzure-9);

  sSecond_low->SetFillStyle(1001);
  sSecond_low->SetFillColor(10);



  //expected and observed (LO & NLO) contours

  TLegend* myleg = new TLegend(0.42,0.70,0.79,0.86,NULL,"brNDC");
  myleg->SetFillColor(0);
  // myleg->SetFillStyle(0);
  myleg->SetShadowColor(0);
  myleg->SetTextSize(0.03);
  myleg->SetBorderSize(0);

  //  sThird->SetLineColor(2);
  // sThird->SetLineStyle(1);


  myleg->SetHeader("95% CL limits:");
  myleg->AddEntry(sFirst,"Observed Limit (NLO), CL_{s}","L");
  //myleg->AddEntry(sFirst,"Observed Limit (NLO), CL_{s}, tan#beta=10, A_{0}=0GeV","L");

  //myleg->AddEntry(sThird,"Observed Limit (NLO), CL_{s}","L");
  //myleg->AddEntry(sFirst,"Observed Limit (NLO), PL","L");
  // myleg->AddEntry(sQCDZero,"#alpha_{T} shape analysis PL QCD(0), EWK flat (LO), 769pb^{-1} (Expected)","L");
  // myleg->AddEntry(sQCDSideBand,"#alpha_{T} shape analysis PL QCD(EXP) sideband, EWK flat (LO), 769pb^{-1} (expected)","L");
  // myleg->AddEntry(sATLcomb,"ATLAS: 0lep combined CLs (NLO), 165pb^{-1}","L");
  // myleg->AddEntry(,"#alpha_{T} cut&count, 35pb^{-1}","L");

  //  myleg->AddEntry(sSecond,"Median Expected Limit","L");

  //hack to compare tanb10 with tanb40
  // sFirst->SetLineColor(kRed);
  // sFirst->SetLineStyle(1);
  // sSecond->SetLineColor(kRed);
  // sSecond->SetLineStyle(7);
  // sSecond_up->SetLineColor(kBlue);
  // sSecond_up->SetLineStyle(1);
  // sSecond_low->SetLineColor(kBlue);
  // sSecond_low->SetLineStyle(4);

  //default
  sSecond->SetLineStyle(4);
  sSecond->SetLineColor(kBlue+3);
  sSecond->SetFillStyle(3001);
  sSecond->SetFillColor(kAzure-9);



  myleg->AddEntry(sSecond,"Median Expected Limit #pm 1 #sigma","FL");  
  //myleg->AddEntry(sSecond,"Median Expected Limit","L");  

  //  myleg->AddEntry(sThird,"Observed Limit (LO), PL","L");
  //  myleg->AddEntry(sThird,"Expected Limit (NLO), PL","L");
  //  myleg->AddEntry(sFourth,"Observed Limit (NLO), FC, 35pb^{-1}","L");
  //  myleg->AddEntry(sFifth,"ATLAS 0lep comb. (NLO), CL_{s}, 165pb^{-1}","L");
 
  //hack for tanb10-40 comparison
  //  myleg->AddEntry(sSecond_up,"Observed Limit (NLO), CL_{s}, tan#beta=40, A_{0}=-500GeV","L");
  //  myleg->AddEntry(sSecond_low,"Median Expected limit","L");


  sSecond_up->Draw("same");
  sSecond->Draw("same");
  sSecond_low->Draw("same");
  sFirst->Draw("same");
  
  //constant squark and gluino mass contours
  int start =0;
  if (tanBeta_ == 40) start =1;
  for (int it=start;it<5;it++) {
    lnsq[it]->Draw("same");
    sq_text[it]->Draw();
  }
  for (int it=0;it<5;it++) {
    lngl[it]->Draw("same");
    gl_text[it]->Draw();
  }

  //exclusion limits previous experiments
  // if(tanBeta_ == 3){
  //   TEV_sn_d0_1->Draw("fsame");
  //   TEV_sn_d0_2->Draw("fsame");
  // }
  //LEP_ch->Draw("fsame");
  //  if (tanBeta_ != 50) LEP_sl->Draw("fsame");

  //  TEV_sg_cdf->Draw("fsame");
  //  TEV_sg_d0->Draw("same");
  //  TEV_sg_d0->Draw("fsame");


  //other labels

  //  TLatex* lumilabel = new TLatex(700,700,"CMS:  #scale[0.6]{#int}Ldt = 1.1 fb^{-1},  #sqrt{s} = 7 TeV");

  double xposl = 705;
  if (tanBeta_ == 40) xposl = 955;
  TLatex* lumilabel = new TLatex(xposl,695,"CMS,  1.14 fb^{-1},  #sqrt{s} = 7 TeV");
  lumilabel->SetTextSize(0.05);
  lumilabel->Draw("same");

  TString text_tanBeta;
  if (tanBeta_ == 10 )  text_tanBeta =  "tan#beta = "+tanb+", A_{0} = 0 GeV, #mu > 0";
  if (tanBeta_ == 40 )  text_tanBeta =  "tan#beta = "+tanb+", A_{0} = -500 GeV, #mu > 0";

  TLatex* cmssmpars = new TLatex(1040,450,text_tanBeta);
  cmssmpars->SetTextSize(0.04);
  //default
  cmssmpars->Draw("same");

  //LM points
  TMarker* LM4 = new TMarker(210.,285.,20);
  TMarker* LM6 = new TMarker(85.,400.,20);

  LM4->SetMarkerSize(1.2);
  LM6->SetMarkerSize(1.2);

  TLatex* tLM4 = new TLatex(230.,270.,"LM4");
  tLM4->SetTextSize(0.035);

  TLatex* tLM6 = new TLatex(110.,400.,"LM6");
  tLM6->SetTextSize(0.035);

  if (tanBeta_ != 40){
    //    LM4->Draw("same");
    //    tLM4->Draw("same");
    LM6->Draw("same");
    tLM6->Draw("same");
  }


  // sQCDZero->Draw("same");
  // sQCDSideBand->Draw("same");

  // sobs250->Draw("same");
  // sATLcomb->Draw("same");

  //  sThird->Draw("same");

  //  sFourth->Draw("same");
  //  sFifth->Draw("same");

  TLine* scan = new TLine(0,455,800,455);
  scan->SetLineColor(1);
  scan->SetLineWidth(15);
  //  scan->Draw("same");
  TLatex* scanlabel = new TLatex(100,470,"End of CMS scan");
  scanlabel->SetTextSize(0.04);
  //  scanlabel->Draw("same");

  //stau=LSP contour
  stau->Draw("fsame");
  // NoEWSB->Draw("fsame");

  //legends
  //  legexp->Draw();
  legst->Draw();
  //  legNoEWSB->Draw();
  myleg->Draw();

  // if(tanBeta_ == 50){
  //   myLEP_ch->Draw("fsame");
  //   LEP_ch->Draw("fsame");

  //   TEV_sg_cdf->Draw("fsame");
  //   TEV_sg_d0->Draw("same");
  //   TEV_sg_d0->Draw("fsame");
  // }

  hist->Draw("sameaxis");
  cvsSys->RedrawAxis("g");

  cvsSys->Update();

  cvsSys->Write();


  cvsSys->SaveAs("RA1_ExclusionLimit_tanb"+tanb+".pdf");
  cvsSys->SaveAs("RA1_ExclusionLimit_tanb"+tanb+".png");


  output->Write();
  output->Close();
  delete output;

}


