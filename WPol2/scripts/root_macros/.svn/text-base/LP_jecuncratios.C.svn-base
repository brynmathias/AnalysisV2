void LP_jecuncratios() {
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  bool print = false;

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
  TFile *file1 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_jecunc_shiftup.root");
  TFile *file2 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_jecunc_shiftdown.root");

  TString folder = "RECO_PolPlots_50toinf";

  TH1D * pLP_nominal = (TH1D*)file0->Get(folder + "/RECO_ICVarPFPlus");
  TH1D * pLP_jecuncup = (TH1D*)file1->Get(folder + "/RECO_ICVarPFPlus");
  TH1D * pLP_jecuncdown = (TH1D*)file2->Get(folder + "/RECO_ICVarPFPlus");
  TH1D * pLP_nominal_clone = (TH1D*)pLP_nominal->Clone();

  TH1D * mLP_nominal = (TH1D*)file0->Get(folder + "/RECO_ICVarPFMinus");
  TH1D * mLP_jecuncup = (TH1D*)file1->Get(folder + "/RECO_ICVarPFMinus");
  TH1D * mLP_jecuncdown = (TH1D*)file2->Get(folder + "/RECO_ICVarPFMinus");
  TH1D * mLP_nominal_clone = (TH1D*)mLP_nominal->Clone();

  pLP_jecuncup->Rebin(10);
  pLP_jecuncdown->Rebin(10);
  pLP_nominal->Rebin(10);
  pLP_nominal_clone->Rebin(10);

  mLP_jecuncup->Rebin(10);
  mLP_jecuncdown->Rebin(10);
  mLP_nominal->Rebin(10);
  mLP_nominal_clone->Rebin(10);

  TCanvas * pLP_jecuncratios = new TCanvas("pLP_jecuncratios","pLP_jecuncratios",600,620);
  pLP_jecuncratios->cd();
  pLP_nominal->Divide(pLP_jecuncup);
  pLP_nominal_clone->Divide(pLP_jecuncdown);
  ZeroErrors(pLP_nominal);
  ZeroErrors(pLP_nominal_clone);
  pLP_nominal->SetLineWidth(4);
  pLP_nominal->SetLineStyle(1);
  pLP_nominal->SetLineColor(kBlack);
  pLP_nominal->GetXaxis()->SetTitle("LP(#mu^{+})");
  pLP_nominal->GetXaxis()->SetRangeUser(-0.5,1.5);
  pLP_nominal->GetYaxis()->SetTitle("LP Ratio");
  pLP_nominal->GetYaxis()->SetRangeUser(0.8,1.4);
  pLP_nominal_clone->SetLineWidth(4);
  pLP_nominal_clone->SetLineStyle(1);
  pLP_nominal_clone->SetLineColor(kRed);
  pLP_nominal->Draw();
  pLP_nominal_clone->Draw("same");


  TLegend *leg = new TLegend(0.3422819,0.75,0.6006711,0.8665541,NULL,"brNDC");
  leg->AddEntry(pLP_nominal,"Upward Shift","l");
  leg->AddEntry(pLP_nominal_clone,"Downward Shift","l");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.03378379);
  leg->DrawClone();
  
  TCanvas * mLP_jecuncratios = new TCanvas("mLP_jecuncratios","mLP_jecuncratios",600,620);
  mLP_jecuncratios->cd();
  mLP_nominal->Divide(mLP_jecuncup);
  mLP_nominal_clone->Divide(mLP_jecuncdown);
  ZeroErrors(mLP_nominal);
  ZeroErrors(mLP_nominal_clone);
  mLP_nominal->SetLineWidth(4);
  mLP_nominal->SetLineStyle(1);
  mLP_nominal->SetLineColor(kBlack);
  mLP_nominal->GetXaxis()->SetTitle("LP(#mu^{-})");
  mLP_nominal->GetXaxis()->SetRangeUser(-0.5,1.5);
  mLP_nominal->GetYaxis()->SetTitle("LP Ratio");
  mLP_nominal->GetYaxis()->SetRangeUser(0.8,1.4);
  mLP_nominal_clone->SetLineWidth(4);
  mLP_nominal_clone->SetLineStyle(1);
  mLP_nominal_clone->SetLineColor(kRed);
  mLP_nominal->Draw();
  mLP_nominal_clone->Draw("same");
  leg->DrawClone();

  if(print) {
    pLP_jecuncratios->Print(".png");
    mLP_jecuncratios->Print(".png");
  }
 
  return;

}

void ZeroErrors(TH1D * myHist) {
 for(unsigned int i=0; i < myHist->GetNbinsX(); i++) myHist->SetBinError(i, 0.0);
 return;
}
