void compare3839_genlevel() {

  gROOT->SetStyle("Plain");

  bool write = true;
  unsigned int rebin = 10;
  TFile *Output = new TFile("MC_39Z2_vs_39D6T_WJets_Madgraph_GEN.root","RECREATE");

  TFile *file0 = TFile::Open("results/GenRoutines_WJetsMGD6T39.root");
  TFile *file1 = TFile::Open("results/GenRoutines_WJetsMGZ239.root");

  TString basepath = "MC_WPlots_50toinf/";
  TString histname[6] = {"MC_ICVarPlus", "MC_ICVarMinus", "MC_MuonPtPlus", "MC_MuonPtMinus", "MC_WPtPlus", "MC_WPtMinus"};
  TString xaxisname[6] = {"LP(+)", "LP(-)", "P_{T}(lep +)", "P_{T}(lep -)", "P_{T}(W+)", "P_{T}(W-)"};
  TCanvas * canvas[6] = {makeCanvas("pLP_GEN"), makeCanvas("mLP_GEN"), makeCanvas("pPTlep_GEN"), makeCanvas("mPTlep_GEN"), makeCanvas("pWPT_GEN"), makeCanvas("mWPT_GEN")};

  for(unsigned int i=0; i<6; i++) {

  TH1F * phistd6t = (TH1F*)file0->Get(basepath+histname[i]);
  TH1F * phistz2 = (TH1F*)file1->Get(basepath+histname[i]);

  cout << "D6T Integral: " << phistd6t->Integral() << endl;
  cout << "Z2 Integral: " << phistz2->Integral() << endl;

  phistz2->Scale(100.);

  phistd6t->GetXaxis()->SetTitle(xaxisname[i]);
  phistd6t->GetYaxis()->SetTitle("Normalised");
  phistd6t->Rebin(rebin);
  phistz2->Rebin(rebin);
  phistd6t->SetLineColor(kRed);
  phistz2->SetLineColor(kBlack);
  phistd6t->SetLineWidth(4);
  phistd6t->SetLineStyle(1);
  phistz2->SetLineWidth(4);
  phistz2->SetLineStyle(2);

  //pLP_LH->GetXaxis()->SetTitleSize(0.06);
  //pLP_LH->GetXaxis()->SetLabelOffset(0.015);
  //pLP_LH->GetXaxis()->SetTitleOffset(1.2);
  //pLP_LH->GetXaxis()->SetRange(21,46);

  //pLP_LH->GetYaxis()->SetTitle("Events (a.u.)");
  //pLP_LH->GetYaxis()->SetTitleSize(0.06);
  //pLP_LH->GetYaxis()->SetTitleOffset(0.85);

  leg = new TLegend(0.6426174,0.8074324,0.9010067,0.9273649,NULL,"brNDC");
  leg->AddEntry(phistd6t,"WJetsD6T_39","l");
  leg->AddEntry(phistz2,"WJetsZ2_39","l");
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
  phistd6t->DrawNormalized("h");
  phistz2->DrawNormalized("sameh");
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
