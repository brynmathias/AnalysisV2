void LP_Aip10pc() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  bool print = true;

  TFile *file0 = TFile::Open("results/GenRoutines_WJets_madgraph_June2010_AiTest.root");

  TString folder = "MC_WPlots_50to100";

  TH1D * pLP_A0p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A0p10pc");
  TH1D * pLP_A1p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A1p10pc");
  TH1D * pLP_A2p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A2p10pc");
  TH1D * pLP_A3p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A3p10pc");
  TH1D * pLP_A4p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A4p10pc");

  TH1D * pLP = (TH1D*)file0->Get(folder + "/MC_ICVarPlus");  
  TH1D * pLP_A0 = (TH1D*)pLP->Clone();
  TH1D * pLP_A1 = (TH1D*)pLP->Clone();
  TH1D * pLP_A2 = (TH1D*)pLP->Clone();
  TH1D * pLP_A3 = (TH1D*)pLP->Clone();
  TH1D * pLP_A4 = (TH1D*)pLP->Clone();
  TH1D * pLPclone = (TH1D*)pLP_A0->Clone();
  pLPclone->Rebin(10);


  TCanvas * A0 = new TCanvas("A0","A0",600,620); 
  A0->SetLeftMargin(0.1291946);
  A0->SetRightMargin(0.0704698);
  pLP_A0->Rebin(10);
  pLP_A0p10pc->Rebin(10);
  pLP_A0->Add(pLP_A0p10pc, -1);
  //pLP_A0->Divide(pLPclone);
  pLP_A0->GetYaxis()->SetTitleOffset(1.5);
  pLP_A0->GetYaxis()->SetTitle("#Delta N / #Delta A0");
  //pLP_A0->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A0->GetXaxis()->SetRangeUser(-0.5,1.5);
  pLP_A0->GetXaxis()->SetTitle("LP(+)");
  pLP_A0->Draw();

  TCanvas * A1 = new TCanvas("A1","A1",600,620);
  A1->SetLeftMargin(0.1291946);
  A1->SetRightMargin(0.0704698);
  pLP_A1->Rebin(10);
  pLP_A1p10pc->Rebin(10);
  pLP_A1->Add(pLP_A1p10pc, -1);
  //pLP_A1->Divide(pLPclone);
  pLP_A1->GetYaxis()->SetTitleOffset(1.5);
  pLP_A1->GetYaxis()->SetTitle("#Delta N / #Delta A1");
  //pLP_A1->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A1->GetXaxis()->SetRangeUser(-0.5,1.5);
  pLP_A1->GetXaxis()->SetTitle("LP(+)");
  pLP_A1->Draw();

  TCanvas * A2 = new TCanvas("A2","A2",600,620);
  A2->SetLeftMargin(0.1291946);
  A2->SetRightMargin(0.0704698);
  pLP_A2->Rebin(10);
  pLP_A2p10pc->Rebin(10);
  pLP_A2->Add(pLP_A2p10pc, -1);
  //pLP_A2->Divide(pLPclone);
  pLP_A2->GetYaxis()->SetTitleOffset(1.5);
  pLP_A2->GetYaxis()->SetTitle("#Delta N / #Delta A2");
  //pLP_A2->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A2->GetXaxis()->SetRangeUser(-0.5,1.5);
  pLP_A2->GetXaxis()->SetTitle("LP(+)");
  pLP_A2->Draw();

  TCanvas * A3 = new TCanvas("A3","A3",600,620);
  A3->SetLeftMargin(0.1291946);
  A3->SetRightMargin(0.0704698);
  pLP_A3->Rebin(10);
  pLP_A3p10pc->Rebin(10);
  pLP_A3->Add(pLP_A3p10pc, -1);
  //pLP_A3->Divide(pLPclone);
  pLP_A3->GetYaxis()->SetTitleOffset(1.5);
  pLP_A3->GetYaxis()->SetTitle("#Delta N / #Delta A3");
  //pLP_A3->GetYaxis()->SetRangeUser(-0.02,0.02);
  pLP_A3->GetXaxis()->SetRangeUser(-0.5,1.5);
  pLP_A3->GetXaxis()->SetTitle("LP(+)");
  pLP_A3->Draw();

  TCanvas * A4 = new TCanvas("A4","A4",600,620);
  A4->SetLeftMargin(0.1291946);
  A4->SetRightMargin(0.0704698);
  pLP_A4->Rebin(10);
  pLP_A4p10pc->Rebin(10);
  pLP_A4->Add(pLP_A4p10pc, -1);
  //pLP_A4->Divide(pLPclone);
  pLP_A4->GetYaxis()->SetTitleOffset(1.5);
  pLP_A4->GetYaxis()->SetTitle("#Delta N / #Delta A4");
  //pLP_A4->GetYaxis()->SetRangeUser(-0.07,0.07);
  pLP_A4->GetXaxis()->SetRangeUser(-0.5,1.5);
  pLP_A4->GetXaxis()->SetTitle("LP(+)");
  pLP_A4->Draw();


  folder = "MC_WPlots_100toinf";

  TH1D * pLP_A0p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A0p10pc");
  TH1D * pLP_A1p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A1p10pc");
  TH1D * pLP_A2p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A2p10pc");
  TH1D * pLP_A3p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A3p10pc");
  TH1D * pLP_A4p10pc = (TH1D*)file0->Get(folder + "/MC_ICVarPlus_A4p10pc");

  TH1D * pLP = (TH1D*)file0->Get(folder + "/MC_ICVarPlus");  
  TH1D * pLP_A0 = (TH1D*)pLP->Clone();
  TH1D * pLP_A1 = (TH1D*)pLP->Clone();
  TH1D * pLP_A2 = (TH1D*)pLP->Clone();
  TH1D * pLP_A3 = (TH1D*)pLP->Clone();
  TH1D * pLP_A4 = (TH1D*)pLP->Clone();
  TH1D * pLPclone = (TH1D*)pLP_A0->Clone();
  pLPclone->Rebin(10);

  A0->cd();
  pLP_A0->Rebin(10);
  pLP_A0p10pc->Rebin(10);
  pLP_A0->Add(pLP_A0p10pc, -1);
  //pLP_A0->Divide(pLPclone); 
  pLP_A0->SetLineColor(kRed);
  pLP_A0->Draw("same");

  A1->cd();
  pLP_A1->Rebin(10);
  pLP_A1p10pc->Rebin(10);
  pLP_A1->Add(pLP_A1p10pc, -1);
  //pLP_A1->Divide(pLPclone); 
  pLP_A1->SetLineColor(kRed);
  pLP_A1->Draw("same");

  A2->cd();
  pLP_A2->Rebin(10);
  pLP_A2p10pc->Rebin(10);
  pLP_A2->Add(pLP_A2p10pc, -1);
  //pLP_A2->Divide(pLPclone); 
  pLP_A2->SetLineColor(kRed);
  pLP_A2->Draw("same");

  A3->cd();
  pLP_A3->Rebin(10);
  pLP_A3p10pc->Rebin(10);
  pLP_A3->Add(pLP_A3p10pc, -1);
  //pLP_A3->Divide(pLPclone); 
  pLP_A3->SetLineColor(kRed);
  pLP_A3->Draw("same");

  A4->cd();
  pLP_A4->Rebin(10);
  pLP_A4p10pc->Rebin(10);
  pLP_A4->Add(pLP_A4p10pc, -1);
  //pLP_A4->Divide(pLPclone); 
  pLP_A4->SetLineColor(kRed);
  pLP_A4->Draw("same");

  if(print) {
    A0->Print(".png");
    A1->Print(".png");
    A2->Print(".png");
    A3->Print(".png");
    A4->Print(".png");
  }
 
  return;

}
