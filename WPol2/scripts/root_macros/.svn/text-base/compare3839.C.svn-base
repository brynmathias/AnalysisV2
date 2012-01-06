void compare3839() {

  bool write = true;
  unsigned int rebin = 10;
  TFile *Output = new TFile("MC_38_vs_39_WJetsZ2_Madgraph_RECO.root","RECREATE");

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_newJetColl_vw.root");
  TFile *file1 = TFile::Open("results/RecoRoutines_W-selection_WJetsMGZ239.root");

  TString basepath = "RECO_PolPlots_50toinf/";
  TString histname[8] = {"RECO_ICVarPFPlus", "RECO_ICVarPFMinus", "RECO_MuonPtPlus", "RECO_MuonPtMinus", "RECO_pfMTPlus", "RECO_pfMTMinus", "RECO_pfMETPlus", "RECO_pfMETMinus"};
  TString xaxisname[8] = {"LP(#mu^{+})", "LP(#mu^{-})", "P_{T}(#mu^{+})", "P_{T}(#mu^{-})", "M_{T}(+)", "M_{T}(-)", "MET(+)", "MET(-)"};
  TCanvas * canvas[8] = {makeCanvas("pLP_RECO"), makeCanvas("mLP_RECO"), makeCanvas("pPTmu_RECO"), makeCanvas("mPTmu_RECO"), makeCanvas("pMT_RECO"), makeCanvas("mMT_RECO"), makeCanvas("pMET_RECO"), makeCanvas("mMET_RECO")};

  for(unsigned int i=0; i<8; i++) {

  TH1F * phist38 = (TH1F*)file0->Get(basepath+histname[i]);
  TH1F * phist39 = (TH1F*)file1->Get(basepath+histname[i]);

  cout << "38 Integral: " << phist38->Integral() << endl;
  cout << "39 Integral: " << phist39->Integral() << endl;

  phist38->GetXaxis()->SetTitle(xaxisname[i]);
  phist38->Rebin(rebin);
  phist39->Rebin(rebin);
  phist38->SetLineColor(kRed);
  phist39->SetLineColor(kBlack);
  phist38->SetLineWidth(4);
  phist38->SetLineStyle(1);
  phist39->SetLineWidth(4);
  phist39->SetLineStyle(2);

  //pLP_LH->GetXaxis()->SetTitleSize(0.06);
  //pLP_LH->GetXaxis()->SetLabelOffset(0.015);
  //pLP_LH->GetXaxis()->SetTitleOffset(1.2);
  //pLP_LH->GetXaxis()->SetRange(21,46);

  //pLP_LH->GetYaxis()->SetTitle("Events (a.u.)");
  //pLP_LH->GetYaxis()->SetTitleSize(0.06);
  //pLP_LH->GetYaxis()->SetTitleOffset(0.85);

  leg = new TLegend(0.6426174,0.8074324,0.9010067,0.9273649,NULL,"brNDC");
  leg->AddEntry(phist38,"WJetsZ2_38","l");
  leg->AddEntry(phist39,"WJetsZ2_39","l");
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
  phist38->DrawCopy("h");
  phist39->DrawCopy("sameh");
  //pLP_LH->DrawCopy("h");
  //pLP_LO->DrawCopy("sameh");
  //pLP_RH->DrawCopy("sameh");
  //pLP_LH_tau->DrawCopy("sameh");
  //pLP_RH_tau->DrawCopy("sameh");
  //pLP_LO_tau->DrawCopy("sameh");
  leg->DrawClone();

  }

  if(write) {
    Output->cd();
    canvas[0]->Write();
    canvas[1]->Write();
    canvas[2]->Write();
    canvas[3]->Write();
    canvas[4]->Write();
    canvas[5]->Write();
    canvas[6]->Write();
    canvas[7]->Write();
    Output->Close();
  }

  file1->Close();
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
