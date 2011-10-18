void LP_ptbins() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  TFile *file0 = TFile::Open("/home/jadm/dev/ICFv3SUSY/WPol/scripts/results/WeightingRoutines_WJets_madgraph_June2010.root");
  //TH1D * pLP_LH = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus_LH");
  //TH1D * pLP_LO = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus_LO");
  //TH1D * pLP_RH = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus_RH");

  TH1D * pLP_LHP2Y0 = (TH1D*)file0->Get("MC_WPlots_P2Y0/MC_ICVarPlus_LH");
  TH1D * pLP_LHP2Y1 = (TH1D*)file0->Get("MC_WPlots_P2Y1/MC_ICVarPlus_LH");
  TH1D * pLP_LHP2Y2 = (TH1D*)file0->Get("MC_WPlots_P2Y2/MC_ICVarPlus_LH");
  TH1D * pLP_LHP2Y3 = (TH1D*)file0->Get("MC_WPlots_P2Y3/MC_ICVarPlus_LH");
  TH1D * pLP_LHP2Y4 = (TH1D*)file0->Get("MC_WPlots_P2Y4/MC_ICVarPlus_LH");
  TH1D * pLP_LHP2Y5 = (TH1D*)file0->Get("MC_WPlots_P2Y5/MC_ICVarPlus_LH");
  TH1D * pLP_LHP2Y6 = (TH1D*)file0->Get("MC_WPlots_P2Y6/MC_ICVarPlus_LH");

  pLP_LHP2Y0->Add(pLP_LHP2Y1);
  pLP_LHP2Y0->Add(pLP_LHP2Y2);
  pLP_LHP2Y0->Add(pLP_LHP2Y3);
  pLP_LHP2Y0->Add(pLP_LHP2Y4);
  pLP_LHP2Y0->Add(pLP_LHP2Y5);
  pLP_LHP2Y0->Add(pLP_LHP2Y6);

  pLP_LHP2Y0->GetXaxis()->SetTitle("Left-Handed Template: LP(+)"); 
  pLP_LHP2Y0->GetXaxis()->SetTitleSize(0.06);
  pLP_LHP2Y0->GetXaxis()->SetLabelOffset(0.015);
  pLP_LHP2Y0->GetXaxis()->SetTitleOffset(1.2);
  pLP_LHP2Y0->GetXaxis()->SetRangeUser(-1.0,2.0);

  pLP_LHP2Y0->GetYaxis()->SetTitle("Events (normalised)");
  pLP_LHP2Y0->GetYaxis()->SetTitleSize(0.06);
  pLP_LHP2Y0->GetYaxis()->SetTitleOffset(0.85);

  pLP_LHP2Y0->Rebin(10);
  pLP_LHP2Y0->SetLineWidth(4);
  pLP_LHP2Y0->SetLineStyle(1);
  pLP_LHP2Y0->SetLineColor(kRed);

  TH1D * pLP_LHP1Y0 = (TH1D*)file0->Get("MC_WPlots_P1Y0/MC_ICVarPlus_LH");
  TH1D * pLP_LHP1Y1 = (TH1D*)file0->Get("MC_WPlots_P1Y1/MC_ICVarPlus_LH");
  TH1D * pLP_LHP1Y2 = (TH1D*)file0->Get("MC_WPlots_P1Y2/MC_ICVarPlus_LH");
  TH1D * pLP_LHP1Y3 = (TH1D*)file0->Get("MC_WPlots_P1Y3/MC_ICVarPlus_LH");
  TH1D * pLP_LHP1Y4 = (TH1D*)file0->Get("MC_WPlots_P1Y4/MC_ICVarPlus_LH");
  TH1D * pLP_LHP1Y5 = (TH1D*)file0->Get("MC_WPlots_P1Y5/MC_ICVarPlus_LH");
  TH1D * pLP_LHP1Y6 = (TH1D*)file0->Get("MC_WPlots_P1Y6/MC_ICVarPlus_LH");

  pLP_LHP1Y0->Add(pLP_LHP1Y1);
  pLP_LHP1Y0->Add(pLP_LHP1Y2);
  pLP_LHP1Y0->Add(pLP_LHP1Y3);
  pLP_LHP1Y0->Add(pLP_LHP1Y4);
  pLP_LHP1Y0->Add(pLP_LHP1Y5);
  pLP_LHP1Y0->Add(pLP_LHP1Y6);

  pLP_LHP1Y0->Rebin(10);
  pLP_LHP1Y0->SetLineWidth(4);
  pLP_LHP1Y0->SetLineStyle(2);
  pLP_LHP1Y0->SetLineColor(kBlue);

  leg = new TLegend(0.5545977,0.6991525,0.8132184,0.8983051,NULL,"brNDC");
  leg->AddEntry(pLP_LHP1Y0,"50<P_{T}(W)<100 [GeV]","l");
  leg->AddEntry(pLP_LHP2Y0,"P_{T}(W)>100 [GeV]","l");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.04237288);
 
  TCanvas * c1 = new TCanvas();
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.06);
  c1->SetTopMargin(0.04);
  c1->SetBottomMargin(0.16);

  pLP_LHP2Y0->DrawNormalized("h");
  pLP_LHP1Y0->DrawNormalized("sameh");
  leg->DrawClone();

  file0->Close();
  return;
}
