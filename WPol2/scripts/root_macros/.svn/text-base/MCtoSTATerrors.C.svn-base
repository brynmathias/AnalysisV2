void MCtoSTATerrors() {
  TLatex *tplus = labelLatex(0.1364943,0.8114407,"MC sample");

  TFile *file0 = TFile::Open("results/StandardCutflow/allmc.root");

  TCanvas *c1 = new TCanvas();
  //TCanvas *c2 = new TCanvas();
  TH1D * LPplus = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus");
  TH1D * LPminus = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFMinus");

  LPplus->Rebin(20);
  LPminus->Rebin(20);

  LPplus->Scale(0.3);
  LPminus->Scale(0.3);

  TH1D * newLPplus = (TH1D*)LPplus->Clone();
  TH1D * newLPminus = (TH1D*)LPminus->Clone();

  for(unsigned int i=1; i < LPplus->GetXaxis()->GetNbins(); i++) {
    newLPplus->SetBinError(i, TMath::Sqrt(LPplus->GetBinContent(i)));
    newLPminus->SetBinError(i, TMath::Sqrt(LPminus->GetBinContent(i)));
  }

  c1->cd();
  newLPplus->GetYaxis()->SetTitle("Events / 300 nb^{-1}");
  //newLPplus->GetXaxis()->SetTitle("LP(#mu^{+})");
  newLPplus->GetXaxis()->SetTitle("LP(#mu)");
  newLPplus->GetXaxis()->SetRangeUser(-1.0,2.0);
  newLPplus->SetLineWidth(3);
  newLPplus->SetLineStyle(2);
  newLPplus->SetLineColor(kRed);
  newLPplus->DrawCopy();
  tplus->DrawClone("same");

//   c2->cd();
//   newLPminus->GetYaxis()->SetTitle("Events / 100 nb^{-1}");
//   newLPminus->GetXaxis()->SetTitle("LP(#mu^{-})");
  newLPminus->SetLineWidth(3);
  newLPminus->SetLineStyle(2);
  newLPminus->SetLineColor(kBlack);
  newLPminus->DrawCopy("same");
//   tplus->DrawClone("same");

  leg = new TLegend(0.762931,0.720339,0.8649425,0.8622881,NULL,"brNDC");
  leg->AddEntry(newLPplus,"#mu^{+}","l");
  leg->AddEntry(newLPminus,"#mu^{-}","l");

  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->DrawClone();

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
