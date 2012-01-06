void LP_bgdist() {

  //TFile *file0 = TFile::Open("results/MuPt10MT30/RecoRoutines_W-selection_BGhadd.root");
  //TH1D * pLPbg = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus");

  //TFile *file1 = TFile::Open("results/MuPt10/RecoRoutines_W-selection_BGhadd.root");
  //TH1D * pLPbgnoMT = (TH1D*)file1->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus");

  TFile *fileZ = TFile::Open("/home/jadm/dev/ICFv3SUSY/WPol/scripts/results/MuPt10/RecoRoutines_W-selection_ZJets_madgraph_June2010.root");
  TFile *fileQCD = TFile::Open("/home/jadm/dev/ICFv3SUSY/WPol/scripts/results/MuPt10/RecoRoutines_W-selection_QCDMu-lite_Pythia.root");
  TFile *filett = TFile::Open("/home/jadm/dev/ICFv3SUSY/WPol/scripts/results/MuPt10/RecoRoutines_W-selection_TTbarJets_tauola_madgraph_June2010.root");

  TH1D * pLPbgZ = (TH1D*)((TH1D*)fileZ->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus")->Clone());
  TH1D * pLPbgnoMTZ = (TH1D*)((TH1D*)fileZ->Get("RECO_PolPlots_50toinf_noMT/RECO_ICVarPFPlus")->Clone());

  TH1D * pLPbgQCD = (TH1D*)((TH1D*)fileQCD->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus")->Clone());
  TH1D * pLPbgnoMTQCD = (TH1D*)((TH1D*)fileQCD->Get("RECO_PolPlots_50toinf_noMT/RECO_ICVarPFPlus")->Clone());

  TH1D * pLPbgtt = (TH1D*)((TH1D*)filett->Get("RECO_PolPlots_50toinf/RECO_ICVarPFPlus")->Clone());
  TH1D * pLPbgnoMTtt = (TH1D*)((TH1D*)filett->Get("RECO_PolPlots_50toinf_noMT/RECO_ICVarPFPlus")->Clone());

  leg = new TLegend(0.1623563,0.6631356,0.3462644,0.9067797,NULL,"brNDC");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.06355932);
  leg->SetTextFont(62);

  legnoMT = new TLegend(0.1623563,0.6631356,0.3462644,0.9067797,NULL,"brNDC");
  legnoMT->SetFillColor(kWhite);
  legnoMT->SetBorderSize(0);
  legnoMT->SetTextSize(0.06355932);
  legnoMT->SetTextFont(62);

  TLatex *tplus = labelLatex(0.20,0.80,"7 TeV MC");

  pLPbgZ->GetXaxis()->SetTitle("LP(#mu^{+})");
  pLPbgZ->GetXaxis()->SetTitleSize(0.06);
  pLPbgZ->GetXaxis()->SetLabelOffset(0.015);
  pLPbgZ->GetXaxis()->SetTitleOffset(1.2);
  pLPbgZ->GetXaxis()->SetRange(31,91);

  pLPbgZ->GetYaxis()->SetTitle("Events / 1 pb^{-1}");
  pLPbgZ->GetYaxis()->SetTitleSize(0.06);
  pLPbgZ->GetYaxis()->SetTitleOffset(0.85);
 
  pLPbgnoMTZ->GetXaxis()->SetTitle("LP(#mu^{+})");
  pLPbgnoMTZ->GetXaxis()->SetTitleSize(0.06);
  pLPbgnoMTZ->GetXaxis()->SetLabelOffset(0.015);
  pLPbgnoMTZ->GetXaxis()->SetTitleOffset(1.2);
  pLPbgnoMTZ->GetXaxis()->SetRange(31,91);

  pLPbgnoMTZ->GetYaxis()->SetTitle("Events / 1 pb^{-1}");
  pLPbgnoMTZ->GetYaxis()->SetTitleSize(0.06);
  pLPbgnoMTZ->GetYaxis()->SetTitleOffset(0.85);

  pLPbgZ->Rebin(20);
  pLPbgZ->SetLineColor(kRed);
  pLPbgZ->SetLineWidth(4);
  pLPbgZ->SetLineStyle(2);
  leg->AddEntry(pLPbgZ,"Z","l");
  pLPbgQCD->Rebin(20);
  pLPbgQCD->SetLineColor(kGreen);
  pLPbgQCD->SetLineWidth(4);
  pLPbgQCD->SetLineStyle(7);
  leg->AddEntry(pLPbgQCD,"QCD","l");
  pLPbgtt->Rebin(20);
  pLPbgtt->SetLineColor(kBlue);
  pLPbgtt->SetLineWidth(4);
  pLPbgtt->SetLineStyle(5);
  leg->AddEntry(pLPbgtt,"t#bar{t}","l");

  pLPbgnoMTZ->Rebin(20);
  pLPbgnoMTZ->SetLineColor(kRed);
  pLPbgnoMTZ->SetLineWidth(4);
  pLPbgnoMTZ->SetLineStyle(2);
  legnoMT->AddEntry(pLPbgnoMTZ,"Z","l");
  pLPbgnoMTQCD->Rebin(20);
  pLPbgnoMTQCD->SetLineColor(kGreen);
  pLPbgnoMTQCD->SetLineWidth(4);
  pLPbgnoMTQCD->SetLineStyle(7);
  legnoMT->AddEntry(pLPbgnoMTQCD,"QCD","l");
  pLPbgnoMTtt->Rebin(20);
  pLPbgnoMTtt->SetLineColor(kBlue);
  pLPbgnoMTtt->SetLineWidth(4);
  pLPbgnoMTtt->SetLineStyle(5);
  legnoMT->AddEntry(pLPbgnoMTtt,"t#bar{t}","l");

  TCanvas * c1 = new TCanvas();  
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.06);
  c1->SetTopMargin(0.04);
  c1->SetBottomMargin(0.16);
  pLPbgZ->DrawCopy("h");
  pLPbgQCD->DrawCopy("sameh");
  pLPbgtt->DrawCopy("sameh");

  TH1D * pLPbg = (TH1D*)pLPbgZ->Clone();
  pLPbg->Add(pLPbgQCD);
  pLPbg->Add(pLPbgtt);
  pLPbg->SetLineColor(kBlack);
  pLPbg->SetLineStyle(1);
  pLPbg->SetLineWidth(4);
  leg->AddEntry(pLPbg,"All BG","l");
  pLPbg->DrawCopy("sameh");
  leg->DrawClone();
  //tplus->DrawClone("same");
  //c1->Print(".png");

  TCanvas * c2 = new TCanvas();
  c2->SetLeftMargin(0.12);
  c2->SetRightMargin(0.06);
  c2->SetTopMargin(0.04);
  c2->SetBottomMargin(0.16);
  pLPbgnoMTZ->DrawCopy("h"); 
  pLPbgnoMTQCD->DrawCopy("sameh");
  pLPbgnoMTtt->DrawCopy("sameh");

  TH1D * pLPbgnoMT = (TH1D*)pLPbgnoMTZ->Clone();
  pLPbgnoMT->Add(pLPbgnoMTQCD);
  pLPbgnoMT->Add(pLPbgnoMTtt);
  pLPbgnoMT->SetLineColor(kBlack);
  pLPbgnoMT->SetLineStyle(1);
  pLPbgnoMT->SetLineWidth(4);
  legnoMT->AddEntry(pLPbgnoMT,"All BG","l");
  pLPbgnoMT->DrawCopy("sameh");
  legnoMT->DrawClone();
  //tplus->DrawClone("same");

  //c2->Print(".png");
  filett->Close();
  fileQCD->Close();
  fileZ->Close();  
  return;
}

TLatex * labelLatex(double &x, double &y, TString &label)
{
  TLatex *t1 = new TLatex(x, y, label);
  t1->SetNDC(kTRUE);
  t1->SetTextSize(0.050);
  return t1;
}
