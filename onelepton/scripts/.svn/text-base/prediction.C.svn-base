#include "setTDRStyle.h"
void setTDRStyle();


void mainFunction() {


  setTDRStyle();
  gStyle->SetOptStat(0);

  // --- HT > 500 
  TH1D* hObs_HT500t  = new TH1D("hObs_HT500t","hObs_HT500t",4,150.,550.);   
  hObs_HT500t->SetLineColor(1); hObs_HT500t->SetLineWidth(3);
  TH1D* hFit_FitUnc_HT500t = new TH1D("hFit_FitUnc_HT500t","hFit_FitUnc_HT500t",4,150.,550.);
  hFit_FitUnc_HT500t->SetLineColor(4); hFit_FitUnc_HT500t->SetLineWidth(3);
  TH1D* hFit_SysUnc_HT500t = new TH1D("hFit_SysUnc_HT500t","hFit_SysUnc_HT500t",4,150.,550.);
  hFit_SysUnc_HT500t->SetLineColor(kGreen+2); hFit_SysUnc_HT500t->SetLineWidth(3);
  TH1D* hFit_TotUnc_HT500t = new TH1D("hFit_TotUnc_HT500t","hFit_TotUnc_HT500t",4,150.,550.); 
  hFit_TotUnc_HT500t->SetFillColor(2); hFit_TotUnc_HT500t->SetFillStyle(3018);


  // --- HT[500,750]
  TH1D* hObs_HT500b = new TH1D("hObs_HT500b","hObs_HT500b",4,150.,550.);   
  hObs_HT500b->SetLineColor(1); hObs_HT500b->SetLineWidth(3);
  TH1D* hFit_FitUnc_HT500b = new TH1D("hFit_FitUnc_HT500b","hFit_FitUnc_HT500b",4,150.,550.);
  hFit_FitUnc_HT500b->SetLineColor(4); hFit_FitUnc_HT500b->SetLineWidth(3);
  TH1D* hFit_SysUnc_HT500b = new TH1D("hFit_SysUnc_HT500b","hFit_SysUnc_HT500b",4,150.,550.);
  hFit_SysUnc_HT500b->SetLineColor(kGreen+2); hFit_SysUnc_HT500b->SetLineWidth(3);
  TH1D* hFit_TotUnc_HT500b = new TH1D("hFit_TotUnc_HT500b","hFit_TotUnc_HT500b",4,150.,550.); 
  hFit_TotUnc_HT500b->SetFillColor(2); hFit_TotUnc_HT500b->SetFillStyle(3018);


  // --- HT[750,1000]
  TH1D* hObs_HT750b = new TH1D("hObs_HT750b","hObs_HT750b",4,150.,550.);   
  hObs_HT750b->SetLineColor(1); hObs_HT750b->SetLineWidth(3);
  TH1D* hFit_FitUnc_HT750b = new TH1D("hFit_FitUnc_HT750b","hFit_FitUnc_HT750b",4,150.,550.);
  hFit_FitUnc_HT750b->SetLineColor(4); hFit_FitUnc_HT750b->SetLineWidth(3);
  TH1D* hFit_SysUnc_HT750b = new TH1D("hFit_SysUnc_HT750b","hFit_SysUnc_HT750b",4,150.,550.);
  hFit_SysUnc_HT750b->SetLineColor(kGreen+2); hFit_SysUnc_HT750b->SetLineWidth(3);
  TH1D* hFit_TotUnc_HT750b = new TH1D("hFit_TotUnc_HT750b","hFit_TotUnc_HT750b",4,150.,550.); 
  hFit_TotUnc_HT750b->SetFillColor(2); hFit_TotUnc_HT750b->SetFillStyle(3018);


  // --- HT[1000,inf]
  TH1D* hObs_HT1000b = new TH1D("hObs_HT1000b","hObs_HT1000b",4,150.,550.);   
  hObs_HT1000b->SetLineColor(1); hObs_HT1000b->SetLineWidth(3);
  TH1D* hFit_FitUnc_HT1000b = new TH1D("hFit_FitUnc_HT1000b","hFit_FitUnc_HT1000b",4,150.,550.);
  hFit_FitUnc_HT1000b->SetLineColor(4); hFit_FitUnc_HT1000b->SetLineWidth(3);
  TH1D* hFit_SysUnc_HT1000b = new TH1D("hFit_SysUnc_HT1000b","hFit_SysUnc_HT1000b",4,150.,550.);
  hFit_SysUnc_HT1000b->SetLineColor(kGreen+2); hFit_SysUnc_HT1000b->SetLineWidth(3);
  TH1D* hFit_TotUnc_HT1000b = new TH1D("hFit_TotUnc_HT1000b","hFit_TotUnc_HT1000b",4,150.,550.); 
  hFit_TotUnc_HT1000b->SetFillColor(2); hFit_TotUnc_HT1000b->SetFillStyle(3018);



  // --- electron numbers

  // HT>500 
  double obs_HT500t[4]    = {250.,92.,35.,17.};
  double fit_HT500t[4]    = {229.,81.6,28.6,18.7};
  double fitUnc_HT500t[4] = {8.,4.8,2.9,2.7};
  double sysUnc_HT500t[4] = {25.,7.3,3.4,3.2};

  // HT[500,750] 
  double obs_HT500b[4]    = {204.,71.,29.,11.};
  double fit_HT500b[4]    = {179.,65.3,19.4,9.18};
  double fitUnc_HT500b[4] = {7.,4.3,2.4,1.91};
  double sysUnc_HT500b[4] = {21.,7.2,2.7,2.01};

  // HT[500,750] 
  double obs_HT750b[4]    = {37.,13.,5.,5.};
  double fit_HT750b[4]    = {37.,11.2,6.26,6.8};
  double fitUnc_HT750b[4] = {3.5,2.,1.23,1.62};
  double sysUnc_HT750b[4] = {5.2,1.7,1.63,1.5};

  // HT[1000,inf] 
  double obs_HT1000b[4]    = {9.,8.,1.,1.};
  double fit_HT1000b[4]    = {12.5,4.84,2.60,2.55};
  double fitUnc_HT1000b[4] = {2.2,1.45,1.19,1.33};
  double sysUnc_HT1000b[4] = {2.5,1.21,0.94,0.97};




  for (int i=0; i<4; i++) {


    // --- HT>500
    hObs_HT500t->SetBinContent(i+1,obs_HT500t[i]);
    hObs_HT500t->SetBinError(i+1,sqrt(obs_HT500t[i]));
    hFit_FitUnc_HT500t->SetBinContent(i+1,fit_HT500t[i]);
    hFit_FitUnc_HT500t->SetBinError(i+1,fitUnc_HT500t[i]);
    hFit_SysUnc_HT500t->SetBinContent(i+1,fit_HT500t[i]);
    hFit_SysUnc_HT500t->SetBinError(i+1,sysUnc_HT500t[i]);
    hFit_TotUnc_HT500t->SetBinContent(i+1,fit_HT500t[i]);
    hFit_TotUnc_HT500t->SetBinError(i+1,sqrt((pow(sqrt(fit_HT500t[i])),2)+pow(sysUnc_HT500t[i],2)));


    // --- HT[500,750]
    hObs_HT500b->SetBinContent(i+1,obs_HT500b[i]);
    hObs_HT500b->SetBinError(i+1,sqrt(obs_HT500b[i]));
    hFit_FitUnc_HT500b->SetBinContent(i+1,fit_HT500b[i]);
    hFit_FitUnc_HT500b->SetBinError(i+1,fitUnc_HT500b[i]);
    hFit_SysUnc_HT500b->SetBinContent(i+1,fit_HT500b[i]);
    hFit_SysUnc_HT500b->SetBinError(i+1,sysUnc_HT500b[i]);
    hFit_TotUnc_HT500b->SetBinContent(i+1,fit_HT500b[i]);
    hFit_TotUnc_HT500b->SetBinError(i+1,sqrt((pow(sqrt(fit_HT500b[i])),2)+pow(sysUnc_HT500b[i],2)));


    // --- HT[750,1000]
    hObs_HT750b->SetBinContent(i+1,obs_HT750b[i]);
    hObs_HT750b->SetBinError(i+1,sqrt(obs_HT750b[i]));
    hFit_FitUnc_HT750b->SetBinContent(i+1,fit_HT750b[i]);
    hFit_FitUnc_HT750b->SetBinError(i+1,fitUnc_HT750b[i]);
    hFit_SysUnc_HT750b->SetBinContent(i+1,fit_HT750b[i]);
    hFit_SysUnc_HT750b->SetBinError(i+1,sysUnc_HT750b[i]);
    hFit_TotUnc_HT750b->SetBinContent(i+1,fit_HT750b[i]);
    hFit_TotUnc_HT750b->SetBinError(i+1,sqrt((pow(sqrt(fit_HT750b[i])),2)+pow(sysUnc_HT750b[i],2)));


    // --- HT[1000,inf]
    hObs_HT1000b->SetBinContent(i+1,obs_HT1000b[i]);
    hObs_HT1000b->SetBinError(i+1,sqrt(obs_HT1000b[i]));
    hFit_FitUnc_HT1000b->SetBinContent(i+1,fit_HT1000b[i]);
    hFit_FitUnc_HT1000b->SetBinError(i+1,fitUnc_HT1000b[i]);
    hFit_SysUnc_HT1000b->SetBinContent(i+1,fit_HT1000b[i]);
    hFit_SysUnc_HT1000b->SetBinError(i+1,sysUnc_HT1000b[i]);
    hFit_TotUnc_HT1000b->SetBinContent(i+1,fit_HT1000b[i]);
    hFit_TotUnc_HT1000b->SetBinError(i+1,sqrt((pow(sqrt(fit_HT1000b[i])),2)+pow(sysUnc_HT1000b[i],2)));

      
  }
  
  // Make legends
  TLatex *lPreliminary = new TLatex(0.19,0.96,"CMS Preliminary 2011");
  lPreliminary->SetNDC();

  TLatex *lIntLumi  = new TLatex(0.2,0.86,"#scale[1.]{4.7 fb^{-1} , #sqrt{s} = 7 TeV}");
  TLatex *lIntLumiB = new TLatex(0.2,0.77,"#scale[1.]{#sqrt{s} = 7 TeV}");
  lIntLumi->SetNDC();
  lIntLumiB->SetNDC();

  TLegend *leg = new TLegend(0.5,0.55,0.95,0.7);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetTextFont(62);
  leg->AddEntry(hFit_FitUnc_HT500t,"prediction","PL");
  leg->AddEntry(hObs_HT500t,"data","L");
  

  // --- Draw plots
  TCanvas *cPrediction_HT500t = new TCanvas("cPrediction_HT500t","cPrediction_HT500t",400,400);

  hObs_HT500t->GetXaxis()->SetTitleSize(0.06);
  hObs_HT500t->GetXaxis()->SetTitle("S_{T}^{lep} [GeV]");
  hObs_HT500t->GetYaxis()->SetTitleSize(0.06);
  hObs_HT500t->GetYaxis()->SetTitle("Events");
  hObs_HT500t->GetYaxis()->SetRangeUser(0.,1.3*(hObs_HT500t->GetBinContent(hObs_HT500t->GetMaximumBin())));
  hObs_HT500t->SetLabelSize(0.06,"XY");
  hObs_HT500t->SetLabelFont(62,"XY");
  hObs_HT500t->SetTitleFont(62,"XY");
  hObs_HT500t->GetXaxis()->SetNdivisions(407);
  hObs_HT500t->SetTitleOffset(1.5,"Y");
  //  hObs_HT500->SetTitleOffset(1.2,"X");
  hFit_FitUnc_HT500t->SetMarkerStyle(20);
  hFit_FitUnc_HT500t->SetMarkerSize(1.);
  hFit_FitUnc_HT500t->SetMarkerColor(4);
  hObs_HT500t->Draw("HIST");
  hFit_TotUnc_HT500t->Draw("E2 sames");
  hFit_FitUnc_HT500t->Draw("P E0 sames");
  lIntLumi->Draw("same");
  lPreliminary->Draw("same");
  leg->Draw("same");


  TCanvas *cPrediction_HTbins = new TCanvas("cPrediction_HTbins","cPrediction_HTbins",1200,400);
  cPrediction_HTbins->Divide(3,1);

  cPrediction_HTbins->cd(1);
  hObs_HT500b->GetXaxis()->SetTitleSize(0.06);
  hObs_HT500b->GetXaxis()->SetTitle("S_{T}^{lep} [GeV]");
  hObs_HT500b->GetYaxis()->SetTitleSize(0.06);
  hObs_HT500b->GetYaxis()->SetTitle("Events");
  hObs_HT500b->GetYaxis()->SetRangeUser(0.,1.3*(hObs_HT500b->GetBinContent(hObs_HT500b->GetMaximumBin())));
  hObs_HT500b->SetLabelSize(0.06,"XY");
  hObs_HT500b->SetLabelFont(62,"XY");
  hObs_HT500b->SetTitleFont(62,"XY");
  hObs_HT500b->GetXaxis()->SetNdivisions(407);
  hObs_HT500b->SetTitleOffset(1.5,"Y");
  //  hObs_HT500->SetTitleOffset(1.2,"X");
  hFit_FitUnc_HT500b->SetMarkerStyle(20);
  hFit_FitUnc_HT500b->SetMarkerSize(1.);
  hFit_FitUnc_HT500b->SetMarkerColor(4);
  hObs_HT500b->Draw("HIST");
  hFit_TotUnc_HT500b->Draw("E2 sames");
  hFit_FitUnc_HT500b->Draw("P E0 sames");
  lIntLumi->Draw("same");
  lPreliminary->Draw("same");
  leg->Draw("same");

  cPrediction_HTbins->cd(2);
  hObs_HT750b->GetXaxis()->SetTitleSize(0.06);
  hObs_HT750b->GetXaxis()->SetTitle("S_{T}^{lep} [GeV]");
  hObs_HT750b->GetYaxis()->SetTitleSize(0.06);
  hObs_HT750b->GetYaxis()->SetTitle("Events");
  hObs_HT750b->GetYaxis()->SetRangeUser(0.,1.5*(hObs_HT750b->GetBinContent(hObs_HT750b->GetMaximumBin())));
  hObs_HT750b->SetLabelSize(0.06,"XY");
  hObs_HT750b->SetLabelFont(62,"XY");
  hObs_HT750b->SetTitleFont(62,"XY");
  hObs_HT750b->GetXaxis()->SetNdivisions(407);
  hObs_HT750b->SetTitleOffset(1.5,"Y");
  //  hObs_HT750->SetTitleOffset(1.2,"X");
  hFit_FitUnc_HT750b->SetMarkerStyle(20);
  hFit_FitUnc_HT750b->SetMarkerSize(1.);
  hFit_FitUnc_HT750b->SetMarkerColor(4);
  hObs_HT750b->Draw("HIST");
  hFit_TotUnc_HT750b->Draw("E2 sames");
  hFit_FitUnc_HT750b->Draw("P E0 sames");
  lIntLumi->Draw("same");
  lPreliminary->Draw("same");
  leg->Draw("same");
  
  cPrediction_HTbins->cd(3);
  hObs_HT1000b->GetXaxis()->SetTitleSize(0.06);
  hObs_HT1000b->GetXaxis()->SetTitle("S_{T}^{lep} [GeV]");
  hObs_HT1000b->GetYaxis()->SetTitleSize(0.06);
  hObs_HT1000b->GetYaxis()->SetTitle("Events");
  hObs_HT1000b->GetYaxis()->SetRangeUser(0.,2.2*(hObs_HT1000b->GetBinContent(hObs_HT1000b->GetMaximumBin())));
  hObs_HT1000b->SetLabelSize(0.06,"XY");
  hObs_HT1000b->SetLabelFont(62,"XY");
  hObs_HT1000b->SetTitleFont(62,"XY");
  hObs_HT1000b->GetXaxis()->SetNdivisions(407);
  hObs_HT1000b->SetTitleOffset(1.5,"Y");
  //  hObs_HT1000->SetTitleOffset(1.2,"X");
  hFit_FitUnc_HT1000b->SetMarkerStyle(20);
  hFit_FitUnc_HT1000b->SetMarkerSize(1.);
  hFit_FitUnc_HT1000b->SetMarkerColor(4);
  hObs_HT1000b->Draw("HIST");
  hFit_TotUnc_HT1000b->Draw("E2 sames");
  hFit_FitUnc_HT1000b->Draw("P E0 sames");
  lIntLumi->Draw("same");
  lPreliminary->Draw("same");
  leg->Draw("same");

}
