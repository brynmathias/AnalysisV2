void LP_templates() {

  bool write = true;
  unsigned int rebin = 10;
  TFile *Output = new TFile("LP_templates_RECO.root","RECREATE");

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_WJetsMGZ238PU.root");

  TString charge[2] = {"Plus", "Minus"};
  TCanvas * canvas[2] = {makeCanvas("pLPtemplates_RECO"), makeCanvas("mLPtemplates_RECO")};

  for(unsigned int i=0; i<2; i++) {

  TH1D * pLP_LH = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPF" + charge[i] + "_LH_vw");
  TH1D * pLP_LO = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPF" + charge[i] + "_LO_vw");
  TH1D * pLP_RH = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPF" + charge[i] + "_RH_vw");

  TH1D * pLP_LH_tau = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPF" + charge[i] + "_LH_GenTau");
  TH1D * pLP_LO_tau = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPF" + charge[i] + "_LO_GenTau");
  TH1D * pLP_RH_tau = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPF" + charge[i] + "_RH_GenTau");


  if(i==0) pLP_LH->GetXaxis()->SetTitle("LP(#mu^{+})");
  else pLP_LH->GetXaxis()->SetTitle("LP(#mu^{-})"); 
  pLP_LH->GetXaxis()->SetTitleSize(0.06);
  pLP_LH->GetXaxis()->SetLabelOffset(0.015);
  pLP_LH->GetXaxis()->SetTitleOffset(1.2);
  pLP_LH->GetXaxis()->SetRange(21,46);

  pLP_LH->GetYaxis()->SetTitle("Events (a.u.)");
  pLP_LH->GetYaxis()->SetTitleSize(0.06);
  pLP_LH->GetYaxis()->SetTitleOffset(0.85);

  pLP_LH->Rebin(rebin);
  pLP_LO->Rebin(rebin);
  pLP_RH->Rebin(rebin);

  pLP_LH_tau->Rebin(rebin);
  pLP_RH_tau->Rebin(rebin);
  pLP_LO_tau->Rebin(rebin);

  pLP_LH->SetLineColor(kRed);
  pLP_LO->SetLineColor(kBlue);
  pLP_RH->SetLineColor(kGreen);

  pLP_LH_tau->SetLineColor(kRed);
  pLP_RH_tau->SetLineColor(kBlue);
  pLP_LO_tau->SetLineColor(kGreen);

  pLP_LH->SetLineWidth(4);
  pLP_LH->SetLineStyle(1);
  pLP_LO->SetLineWidth(4);
  pLP_LO->SetLineStyle(2);
  pLP_RH->SetLineWidth(4);
  pLP_RH->SetLineStyle(7);

  pLP_LH_tau->SetLineWidth(4);
  pLP_LH_tau->SetLineStyle(1);
  pLP_LO_tau->SetLineWidth(4);
  pLP_LO_tau->SetLineStyle(2);
  pLP_RH_tau->SetLineWidth(4);
  pLP_RH_tau->SetLineStyle(7);


  leg = new TLegend(0.6426174,0.8074324,0.9010067,0.9273649,NULL,"brNDC");
  leg->AddEntry(pLP_LH,"Left Handed","l");
  leg->AddEntry(pLP_LO,"Longitudinal","l");
  leg->AddEntry(pLP_RH,"Right Handed","l");
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
  canvas[i]->cd();
  pLP_LH->DrawCopy("h");
  pLP_LO->DrawCopy("sameh");
  pLP_RH->DrawCopy("sameh");
  pLP_LH_tau->DrawCopy("sameh");
  pLP_RH_tau->DrawCopy("sameh");
  pLP_LO_tau->DrawCopy("sameh");
  leg->DrawClone();

  }

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
