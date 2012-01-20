void LP_datadist() {

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_realdata_all.root");
  TH1D * pLP = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus");
  TH1D * mLP = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFMinus");

  TLatex *tplus = labelLatex(0.20,0.80,"7 TeV Data");

  bool print = true;

  //first for plus charge
  pLP->GetXaxis()->SetTitle("LP(#mu^{+})");
  pLP->GetXaxis()->SetTitleSize(0.06);
  pLP->GetXaxis()->SetLabelOffset(0.015);
  pLP->GetXaxis()->SetTitleOffset(1.2);
  pLP->GetXaxis()->SetRange(31,91);

  pLP->GetYaxis()->SetTitle("Events / 280 nb^{-1}");
  pLP->GetYaxis()->SetTitleSize(0.06);
  pLP->GetYaxis()->SetTitleOffset(0.85);

  pLP->Rebin(20);
  pLP->SetLineColor(kBlack);
  pLP->SetLineWidth(2);

  TCanvas * c1 = new TCanvas("pLP_data", "pLP_data");
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.06);
  c1->SetTopMargin(0.04);
  c1->SetBottomMargin(0.16);
  pLP->SetMarkerStyle(20);
  pLP->DrawCopy("p");
  tplus->DrawClone("same");
  if(print) c1->Print(".png");

  //now for minus charge
  mLP->GetXaxis()->SetTitle("LP(#mu^{-})");
  mLP->GetXaxis()->SetTitleSize(0.06);
  mLP->GetXaxis()->SetLabelOffset(0.015);
  mLP->GetXaxis()->SetTitleOffset(1.2);
  mLP->GetXaxis()->SetRange(31,91);

  mLP->GetYaxis()->SetTitle("Events / 280 nb^{-1}");
  mLP->GetYaxis()->SetTitleSize(0.06);
  mLP->GetYaxis()->SetTitleOffset(0.85);

  mLP->Rebin(20);
  mLP->SetLineColor(kBlack);
  mLP->SetLineWidth(2);

  TCanvas * c2 = new TCanvas("mLP_data", "mLP_data");
  c2->SetLeftMargin(0.12);
  c2->SetRightMargin(0.06);
  c2->SetTopMargin(0.04);
  c2->SetBottomMargin(0.16);
  mLP->SetMarkerStyle(20);
  mLP->DrawCopy("p");
  tplus->DrawClone("same");
  if(print) c2->Print(".png");

  file0->Close();
  return;
}

TLatex * labelLatex(double &x, double &y, TString &label)
{
  TLatex *t1 = new TLatex(x, y, label);
  t1->SetNDC(kTRUE);
  t1->SetTextSize(0.050);
  return t1;
}
