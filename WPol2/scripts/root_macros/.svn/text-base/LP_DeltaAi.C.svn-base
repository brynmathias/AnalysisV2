void LP_DeltaAi() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  bool print = false;
  bool write = true;
  bool doGen = false;
  TString modifier = "p10pc";
  //TString modifier = "p0d01";
  unsigned int rebin=10;

  if(doGen) {
    TFile *file0 = TFile::Open("results/GenRoutines_WJets_madgraph_Fall2010Z2.root");
    TFile *Output = new TFile("results/LP_DeltaAiGen.root","RECREATE");
    TString folder = "MC_WPlots_50to100";
    TString histobase = "MC_ICVarPlus";
    double xmin = -0.5;
    double xmax = 1.5;
    TString xaxistitle = "LP(+)";
  } else {
    TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
    TFile *Output = new TFile("results/LP_DeltaAiRECO.root","RECREATE");
    TString folder = "RECO_PolPlots_50toinf";
    TString histobase = "RECO_ICVarPFPlus";
    double xmin = -0.5;
    double xmax = 1.5;
    TString xaxistitle = "LP(+)";
    //TString histobase = "RECO_MuonEtaPlus";
    //double xmin = 0.0;
    //double xmax = 2.5;
    //TString xaxistitle = "|#eta(+)|";
  }

  //TH1D::SetDefaultSumw2(kTRUE);

  TH1D * pLP_A0p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A0" + modifier);
  TH1D * pLP_A1p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A1" + modifier);
  TH1D * pLP_A2p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A2" + modifier);
  TH1D * pLP_A3p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A3" + modifier);
  TH1D * pLP_A4p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A4" + modifier);

  TH1D * pLP = (TH1D*)file0->Get(folder + "/" + histobase);
  TH1D * pLP_A0 = (TH1D*)pLP->Clone();
  TH1D * pLP_A1 = (TH1D*)pLP->Clone();
  TH1D * pLP_A2 = (TH1D*)pLP->Clone();
  TH1D * pLP_A3 = (TH1D*)pLP->Clone();
  TH1D * pLP_A4 = (TH1D*)pLP->Clone();
  TH1D * pLPclone = (TH1D*)pLP_A0->Clone();
  pLPclone->Rebin(rebin);


  TCanvas * A0 = new TCanvas("A0","A0",600,620); 
  A0->SetLeftMargin(0.1291946);
  A0->SetRightMargin(0.0704698);
  pLP_A0->Rebin(rebin);
  pLP_A0p10pc->Rebin(rebin);
  pLP_A0->Add(pLP_A0p10pc, -1);
  //pLP_A0->Divide(pLPclone);
  pLP_A0->GetYaxis()->SetTitleOffset(1.5);
  pLP_A0->GetYaxis()->SetTitle("#Delta N / #Delta A0");
  //pLP_A0->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A0->GetXaxis()->SetRangeUser(xmin,xmax);
  pLP_A0->GetXaxis()->SetTitle(xaxistitle);
  ZeroErrors(pLP_A0);
  pLP_A0->SetLineWidth(4);
  pLP_A0->SetLineStyle(1);
  pLP_A0->SetLineColor(kBlack);
  pLP_A0->Draw();

  TCanvas * A1 = new TCanvas("A1","A1",600,620);
  A1->SetLeftMargin(0.1291946);
  A1->SetRightMargin(0.0704698);
  pLP_A1->Rebin(rebin);
  pLP_A1p10pc->Rebin(rebin);
  pLP_A1->Add(pLP_A1p10pc, -1);
  //pLP_A1->Divide(pLPclone);
  pLP_A1->GetYaxis()->SetTitleOffset(1.5);
  pLP_A1->GetYaxis()->SetTitle("#Delta N / #Delta A1");
  //pLP_A1->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A1->GetXaxis()->SetRangeUser(xmin,xmax);
  pLP_A1->GetXaxis()->SetTitle(xaxistitle);
  ZeroErrors(pLP_A1);
  pLP_A1->SetLineWidth(4);
  pLP_A1->SetLineStyle(1);
  pLP_A1->SetLineColor(kBlack);
  pLP_A1->Draw();

  TCanvas * A2 = new TCanvas("A2","A2",600,620);
  A2->SetLeftMargin(0.1291946);
  A2->SetRightMargin(0.0704698);
  pLP_A2->Rebin(rebin);
  pLP_A2p10pc->Rebin(rebin);
  pLP_A2->Add(pLP_A2p10pc, -1);
  //pLP_A2->Divide(pLPclone);
  pLP_A2->GetYaxis()->SetTitleOffset(1.5);
  pLP_A2->GetYaxis()->SetTitle("#Delta N / #Delta A2");
  //pLP_A2->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A2->GetXaxis()->SetRangeUser(xmin,xmax);
  pLP_A2->GetXaxis()->SetTitle(xaxistitle);
  ZeroErrors(pLP_A2);
  pLP_A2->SetLineWidth(4);
  pLP_A2->SetLineStyle(1);
  pLP_A2->SetLineColor(kBlack);
  pLP_A2->Draw();

  TCanvas * A3 = new TCanvas("A3","A3",600,620);
  A3->SetLeftMargin(0.1291946);
  A3->SetRightMargin(0.0704698);
  pLP_A3->Rebin(rebin);
  pLP_A3p10pc->Rebin(rebin);
  pLP_A3->Add(pLP_A3p10pc, -1);
  //pLP_A3->Divide(pLPclone);
  pLP_A3->GetYaxis()->SetTitleOffset(1.5);
  pLP_A3->GetYaxis()->SetTitle("#Delta N / #Delta A3");
  //pLP_A3->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A3->GetXaxis()->SetRangeUser(xmin,xmax);
  pLP_A3->GetXaxis()->SetTitle(xaxistitle);
  ZeroErrors(pLP_A3);
  pLP_A3->SetLineWidth(4);
  pLP_A3->SetLineStyle(1);
  pLP_A3->SetLineColor(kBlack);
  pLP_A3->Draw();

  TCanvas * A4 = new TCanvas("A4","A4",600,620);
  A4->SetLeftMargin(0.1291946);
  A4->SetRightMargin(0.0704698);
  pLP_A4->Rebin(rebin);
  pLP_A4p10pc->Rebin(rebin);
  pLP_A4->Add(pLP_A4p10pc, -1);
  //pLP_A4->Divide(pLPclone);
  pLP_A4->GetYaxis()->SetTitleOffset(1.5);
  pLP_A4->GetYaxis()->SetTitle("#Delta N / #Delta A4");
  //pLP_A4->GetYaxis()->SetRangeUser(-0.07,0.07);
  pLP_A4->GetXaxis()->SetRangeUser(xmin,xmax);
  pLP_A4->GetXaxis()->SetTitle(xaxistitle);
  ZeroErrors(pLP_A4);
  pLP_A4->SetLineWidth(4);
  pLP_A4->SetLineStyle(1);
  pLP_A4->SetLineColor(kBlack);
  pLP_A4->Draw();

  if(doGen) {
    folder = "MC_WPlots_100toinf";
    TH1D * pLP2_A0p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A0" + modifier);
    TH1D * pLP2_A1p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A1" + modifier);
    TH1D * pLP2_A2p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A2" + modifier);
    TH1D * pLP2_A3p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A3" + modifier);
    TH1D * pLP2_A4p10pc = (TH1D*)file0->Get(folder + "/" + histobase + "_A4" + modifier);

    TH1D * pLP2 = (TH1D*)file0->Get(folder + "/" + histobase);  
    TH1D * pLP2_A0 = (TH1D*)pLP2->Clone();
    TH1D * pLP2_A1 = (TH1D*)pLP2->Clone();
    TH1D * pLP2_A2 = (TH1D*)pLP2->Clone();
    TH1D * pLP2_A3 = (TH1D*)pLP2->Clone();
    TH1D * pLP2_A4 = (TH1D*)pLP2->Clone();
    TH1D * pLP2clone = (TH1D*)pLP2_A0->Clone();
    pLP2clone->Rebin(rebin);

    A0->cd();
    pLP2_A0->Rebin(rebin);
    pLP2_A0p10pc->Rebin(rebin);
    pLP2_A0->Add(pLP2_A0p10pc, -1);
    //pLP_A0->Divide(pLPclone); 
    pLP2_A0->SetLineWidth(4);
    pLP2_A0->SetLineStyle(2);
    pLP2_A0->SetLineColor(kRed);

    TLegend *leg = new TLegend(0.3422819,0.75,0.6006711,0.8665541,NULL,"brNDC");
    leg->AddEntry(pLP_A0,"50<P_{T}(W)<100 [GeV]","l");
    leg->AddEntry(pLP2_A0,"P_{T}(W)>100 [GeV]","l");
    leg->SetFillColor(kWhite);
    leg->SetBorderSize(0);
    leg->SetTextFont(62);
    leg->SetTextSize(0.03378379);
    //leg->SetTextSizePixels(20);

    ZeroErrors(pLP2_A0);
    pLP2_A0->Draw("same");
    leg->DrawClone("same");

    A1->cd();
    pLP2_A1->Rebin(rebin);
    pLP2_A1p10pc->Rebin(rebin);
    pLP2_A1->Add(pLP2_A1p10pc, -1);
    //pLP_A1->Divide(pLPclone); 
    pLP2_A1->SetLineWidth(4);
    pLP2_A1->SetLineStyle(2);
    pLP2_A1->SetLineColor(kRed);
    ZeroErrors(pLP2_A1);
    pLP2_A1->Draw("same");
    leg->DrawClone("same");

    A2->cd();
    pLP2_A2->Rebin(rebin);
    pLP2_A2p10pc->Rebin(rebin);
    pLP2_A2->Add(pLP2_A2p10pc, -1);
    //pLP_A2->Divide(pLPclone); 
    pLP2_A2->SetLineWidth(4);
    pLP2_A2->SetLineStyle(2);
    pLP2_A2->SetLineColor(kRed);
    ZeroErrors(pLP2_A2);    
    pLP2_A2->Draw("same");
    leg->DrawClone("same");

    A3->cd();
    pLP2_A3->Rebin(rebin);
    pLP2_A3p10pc->Rebin(rebin);
    pLP2_A3->Add(pLP2_A3p10pc, -1);
    //pLP_A3->Divide(pLPclone); 
    pLP2_A3->SetLineWidth(4);
    pLP2_A3->SetLineStyle(2);
    pLP2_A3->SetLineColor(kRed);
    ZeroErrors(pLP2_A3);
    pLP2_A3->Draw("same");
    leg->DrawClone("same");

    A4->cd();
    pLP2_A4->Rebin(rebin);
    pLP2_A4p10pc->Rebin(rebin);
    pLP2_A4->Add(pLP2_A4p10pc, -1);
    //pLP_A4->Divide(pLPclone); 
    pLP2_A4->SetLineWidth(4);
    pLP2_A4->SetLineStyle(2);
    pLP2_A4->SetLineColor(kRed);
    ZeroErrors(pLP2_A4);
    pLP2_A4->Draw("same");
    leg->DrawClone("same");
  }

  if(print) {
    A0->Print(".png");
    A1->Print(".png");
    A2->Print(".png");
    A3->Print(".png");
    A4->Print(".png");
  }

  if(write) {
    Output->cd();
    A0->Write();
    A1->Write();
    A2->Write();
    A3->Write();
    A4->Write();
    Output->Close();
  }
 
  return;

}

void ZeroErrors(TH1D * myHist) {
 for(unsigned int i=0; i < myHist->GetNbinsX(); i++) myHist->SetBinError(i, 0.0);
 return;
}
