void getAiZ() 
{
  TFile *data1 = new TFile("results/CSFrame_ZJets_madgraph_0_inf_plus.root");
  TFile *data2 = new TFile("results/CSFrame_ZJets_madgraph_0_inf_minus.root");

  TString HistPA0 = "MC_CSFramePlots_0toinf/MC_CSWPlusA0Numerator";
  TString HistPA1 = "MC_CSFramePlots_0toinf/MC_CSWPlusA1Numerator";
  TString HistPA2 = "MC_CSFramePlots_0toinf/MC_CSWPlusA2Numerator";
  TString HistPA3 = "MC_CSFramePlots_0toinf/MC_CSWPlusA3Numerator";
  TString HistPA4 = "MC_CSFramePlots_0toinf/MC_CSWPlusA4Numerator";
  TString HistPD = "MC_CSFramePlots_0toinf/MC_CSWPlusAiDenominator";

  TString HistMA0 = "MC_CSFramePlots_0toinf/MC_CSWMinusA0Numerator";
  TString HistMA1 = "MC_CSFramePlots_0toinf/MC_CSWMinusA1Numerator";
  TString HistMA2 = "MC_CSFramePlots_0toinf/MC_CSWMinusA2Numerator";
  TString HistMA3 = "MC_CSFramePlots_0toinf/MC_CSWMinusA3Numerator";
  TString HistMA4 = "MC_CSFramePlots_0toinf/MC_CSWMinusA4Numerator";
  TString HistMD = "MC_CSFramePlots_0toinf/MC_CSWMinusAiDenominator";

  TH1D *hPA0 = (TH1D*)data1->Get(HistPA0);
  TH1D *hPA1 = (TH1D*)data1->Get(HistPA1);
  TH1D *hPA2 = (TH1D*)data1->Get(HistPA2);
  TH1D *hPA3 = (TH1D*)data1->Get(HistPA3);
  TH1D *hPA4 = (TH1D*)data1->Get(HistPA4);
  TH1D *hPD = (TH1D*)data1->Get(HistPD);

  TH1D *hMA0 = (TH1D*)data2->Get(HistMA0);
  TH1D *hMA1 = (TH1D*)data2->Get(HistMA1);
  TH1D *hMA2 = (TH1D*)data2->Get(HistMA2);
  TH1D *hMA3 = (TH1D*)data2->Get(HistMA3);
  TH1D *hMA4 = (TH1D*)data2->Get(HistMA4);
  TH1D *hMD = (TH1D*)data2->Get(HistMD);

  hPA0->Rebin(20);
  hPA1->Rebin(20);
  hPA2->Rebin(20);
  hPA3->Rebin(20);
  hPA4->Rebin(20);
  hPD->Rebin(20);

  hMA0->Rebin(20);
  hMA1->Rebin(20);
  hMA2->Rebin(20);
  hMA3->Rebin(20);
  hMA4->Rebin(20);
  hMD->Rebin(20);

  TCanvas * aCanvas = new TCanvas("CSAiZ", "CSAiZ", 1100, 500);
  aCanvas->SetFillColor(0);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->Divide(2,1);

  setPadMargins(aCanvas->cd(1));

  TLegend * aLegend = new TLegend(0.23,0.92,0.4,0.62);
  aLegend->SetFillColor(0);
  aLegend->SetLineColor(0);
  aLegend->SetTextSize(0.0625);

  aLegend->AddEntry(hPA0,"A0", "L");
  //aLegend->AddEntry(hPA1,"A1", "L");
  aLegend->AddEntry(hPA2,"A2", "L");
  aLegend->AddEntry(hPA3,"A3", "L");
  //aLegend->AddEntry(hPA4,"A4", "L");

  hPA0->Scale(20.0/3.0);
  hPA0->Divide(hPD);
  for(unsigned int i=0; i<hPA0->GetNbinsX(); i++) {
    hPA0->SetBinContent(i, (2.0/3.0) + hPA0->GetBinContent(i));
  }
  hPA0->SetLineWidth(3);
  hPA0->GetYaxis()->SetRangeUser(-1.,2.);
  hPA0->GetXaxis()->SetTitle("P_{T}(Z) [GeV]");
  hPA0->GetXaxis()->SetRangeUser(0,220);
  hPA0->GetYaxis()->SetTitle("A_{i}");
  hPA0->GetXaxis()->SetTitleSize(0.0625);
  hPA0->GetYaxis()->SetTitleSize(0.0625);
  hPA0->GetXaxis()->SetTitleOffset(1.00);
  hPA0->GetYaxis()->SetTitleOffset(1.20);
  hPA0->GetXaxis()->SetLabelSize(0.052);
  hPA0->GetYaxis()->SetLabelSize(0.052);
  hPA0->GetXaxis()->SetLabelOffset(0.01);
  hPA0->GetYaxis()->SetLabelOffset(0.01);
  hPA0->DrawCopy("hist");

  hPA1->Scale(5.0);
  hPA1->Divide(hPD);
  hPA1->SetLineColor(kRed);
  hPA1->SetLineWidth(3);
  //hPA1->DrawCopy("histsame");//we don't have sensitivity to A1 - sign of cos(theta_CS)

  hPA2->Scale(10.0);
  hPA2->Divide(hPD);
  hPA2->SetLineColor(kBlue);
  hPA2->SetLineWidth(3);
  hPA2->DrawCopy("histsame");

  hPA3->Scale(4.0);
  hPA3->Divide(hPD);
  hPA3->SetLineColor(kGreen);
  hPA3->SetLineWidth(3);
  hPA3->DrawCopy("histsame");

  hPA4->Scale(4.0);
  hPA4->Divide(hPD);
  hPA4->SetLineColor(kCyan);
  hPA4->SetLineWidth(3);
  //hPA4->DrawCopy("histsame");//we don't have sensitivity to A4 - sign of cos(theta_CS)

  TLatex *tplus = labelLatex(0.25,0.25,"Lepton Plus Charge");
  tplus->DrawClone("same");

  aLegend->DrawClone("same");  

  setPadMargins(aCanvas->cd(2));

  hMA0->Scale(20.0/3.0);
  hMA0->Divide(hMD);
  for(unsigned int i=0; i<hMA0->GetNbinsX(); i++) {
    hMA0->SetBinContent(i, (2.0/3.0) + hMA0->GetBinContent(i));
  }
  hMA0->SetLineWidth(3);
  hMA0->GetYaxis()->SetRangeUser(-1.,2.);
  hMA0->GetXaxis()->SetTitle("P_{T}(Z) [GeV]");
  hMA0->GetXaxis()->SetRangeUser(0,220);
  hMA0->GetYaxis()->SetTitle("A_{i}");
  hMA0->GetXaxis()->SetTitleSize(0.0625);
  hMA0->GetYaxis()->SetTitleSize(0.0625);
  hMA0->GetXaxis()->SetTitleOffset(1.00);
  hMA0->GetYaxis()->SetTitleOffset(1.20);
  hMA0->GetXaxis()->SetLabelSize(0.052);
  hMA0->GetYaxis()->SetLabelSize(0.052);
  hMA0->GetXaxis()->SetLabelOffset(0.01);
  hMA0->GetYaxis()->SetLabelOffset(0.01);
  hMA0->DrawCopy("hist");

  hMA1->Scale(5.0);
  hMA1->Divide(hMD);
  hMA1->SetLineColor(kRed);
  hMA1->SetLineWidth(3);
  //hMA1->DrawCopy("histsame");

  hMA2->Scale(10.0);
  hMA2->Divide(hMD);
  hMA2->SetLineColor(kBlue);
  hMA2->SetLineWidth(3);
  hMA2->DrawCopy("histsame");

  hMA3->Scale(4.0);
  hMA3->Divide(hMD);
  hMA3->SetLineColor(kGreen);
  hMA3->SetLineWidth(3);
  hMA3->DrawCopy("histsame");

  hMA4->Scale(4.0);
  hMA4->Divide(hMD);
  hMA4->SetLineColor(kCyan);
  hMA4->SetLineWidth(3);
  //hMA4->DrawCopy("histsame");

  TLatex *tminus = labelLatex(0.25,0.25,"Lepton Minus Charge");
  tminus->DrawClone("same");

  aLegend->DrawClone("same");  

  aCanvas->Print(".png");

  return;
}

void setPadMargins(TVirtualPad* pad)
{
  pad->SetTopMargin(0.050);
  pad->SetBottomMargin(0.200);
  pad->SetLeftMargin(0.200);
  return;
}

TLatex * labelLatex(double &x, double &y, TString &label)
{
  TLatex *t1 = new TLatex(x, y, label);
  t1->SetNDC(kTRUE);
  t1->SetTextSize(0.070);
  return t1;
}
