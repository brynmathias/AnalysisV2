void vertex_distribution_dataMC() {

  bool print = false;

  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_WJetsMGZ238PU.root");
  TFile *file1 = TFile::Open("results/RecoRoutines_W-selection_dataskimnov4rereco_newJetColl.root");

  TCanvas * canvas = makeCanvas("vertexDistribution_dataMC");
  TH1D * mc = (TH1D*)file0->Get("RECO_PolPlots_50toinf/RECO_NumVerticesPerEvent");
  TH1D * data = (TH1D*)file1->Get("RECO_PolPlots_50toinf/RECO_NumVerticesPerEvent");

  mc->GetXaxis()->SetTitle("Vertex Multiplicity");
  mc->GetXaxis()->SetTitleSize(0.06);
  mc->GetXaxis()->SetLabelOffset(0.015);
  mc->GetXaxis()->SetTitleOffset(1.2);
  mc->GetXaxis()->SetRangeUser(0,10);
  mc->GetYaxis()->SetRangeUser(0,0.35);

  mc->GetYaxis()->SetTitle("Normalised");
  mc->GetYaxis()->SetTitleSize(0.06);
  mc->GetYaxis()->SetTitleOffset(0.85);

  mc->SetLineColor(kRed);
  data->SetLineColor(kBlack);

  mc->SetLineWidth(4);
  mc->SetLineStyle(2);
  data->SetLineWidth(4);
  data->SetLineStyle(1);

  leg = new TLegend(0.6426174,0.8074324,0.9010067,0.9273649,NULL,"brNDC");
  leg->AddEntry(mc,"MC","l");
  leg->AddEntry(data,"Data","l");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);

  canvas->cd();
  mc->DrawNormalized("h");
  data->DrawNormalized("sameh");
  leg->DrawClone();

  if(print) {
    canvas->Write();
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
