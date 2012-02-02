void mu_nu_spectra_data() {

  bool write = false;
  unsigned int rebin = 10;
  TFile *Output = new TFile("muon_neutrino_spectra_36pbDATA.root","RECREATE");

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_dataskimnov4rereco.root");

  //TString charge[2] = {"Plus", "Minus"};
  //TCanvas * canvas[2] = {makeCanvas("pLPtemplates_RECO"), makeCanvas("mLPtemplates_RECO")};
  TCanvas * canvas = makeCanvas("mu_nu_spectra_data");

  //for(unsigned int i=0; i<2; i++) {

  TH1D * pMu = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_MuonPtPlus");
  TH1D * pNu = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_pfMETPlus");
  TH1D * mMu = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_MuonPtMinus");
  TH1D * mNu = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_pfMETMinus");

  pMu->GetXaxis()->SetTitle("LP(lepton)");
  pMu->GetXaxis()->SetTitleSize(0.06);
  pMu->GetXaxis()->SetLabelOffset(0.015);
  pMu->GetXaxis()->SetTitleOffset(1.2);
  pMu->GetXaxis()->SetRange(21,46);

  pMu->GetYaxis()->SetTitle("Events / 36 pb^{-1}");
  pMu->GetYaxis()->SetTitleSize(0.06);
  pMu->GetYaxis()->SetTitleOffset(0.85);

  pMu->Rebin(rebin);
  pNu->Rebin(rebin);
  mMu->Rebin(rebin);
  mNu->Rebin(rebin);

  pMu->SetLineColor(kRed);
  pNu->SetLineColor(kBlue);
  mMu->SetLineColor(kGreen);
  mNu->SetLineColor(kTeal);

  pMu->SetLineWidth(4);
  pMu->SetLineStyle(1);
  pNu->SetLineWidth(4);
  pNu->SetLineStyle(2);
  mMu->SetLineWidth(4);
  mMu->SetLineStyle(7);
  mNu->SetLineWidth(4);
  mNu->SetLineStyle(8);

  leg = new TLegend(0.6426174,0.8074324,0.9010067,0.9273649,NULL,"brNDC");
  leg->AddEntry(pMu,"#mu^{+}","l");
  leg->AddEntry(pNu,"#nu^{+}","l");
  leg->AddEntry(mMu,"#mu^{-}","l");
  leg->AddEntry(mNu,"#nu^{-}","l");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);

  //Unfortunately, if you want to show the relative sizes of the templates from tau->mu, 
  //then DrawNormalized will only show the shape - use DrawCopy instead
  //TCanvas * c1 = new TCanvas("pLP_RECO","pLP_RECO",600,620);
  //c1->SetLeftMargin(0.12);
  //c1->SetRightMargin(0.06);
  //c1->SetTopMargin(0.04);
  //c1->SetBottomMargin(0.16);
  canvas->cd();
  pMu->DrawCopy("h");
  pNu->DrawCopy("sameh");
  mMu->DrawCopy("sameh");
  mNu->DrawCopy("sameh");
  leg->DrawClone();

  //}

  if(write) {
    Output->cd();
    canvas[0]->Write();
    canvas[1]->Write();
    Output->Close();
  }

  file0->Close();
  return;
}

TCanvas * makeCanvas(TString & name) {
  TCanvas * c1 = new TCanvas(name, name, 600, 620);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.06);
  c1->SetTopMargin(0.04);
  c1->SetBottomMargin(0.16);
  return c1;
}
