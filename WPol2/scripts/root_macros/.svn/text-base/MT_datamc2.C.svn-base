void MT_datamc2() {
  TLatex *tplus = labelLatex(0.20,0.80,"7 TeV Data");
  gROOT->SetStyle("Plain"); 
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  //the correct W x-sec to use is 31314, c.f. 24170, 30380
  double w_scale = 43.0;//(31314.0 / 24170.0) * 35.0;
  double z_scale = w_scale;
  double qcd_scale = 14./1000.0;
  double data_scale = 1.;
  unsigned int rbin = 5;
  unsigned int numPlots = 4;
  bool doPrint = false;

  TString folder = "hltmu15_goodevsel";

  TFile *file0 = TFile::Open("results/" + folder + "/RecoRoutines_W-selection_realdata.root");
  TFile *file1 = TFile::Open("results/" + folder + "/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  //TFile *file1 = TFile::Open("results/" + folder + "/RecoRoutines_W-selection_WJets_sherpa.root");
  TFile *file2 = TFile::Open("results/hltmu9_goodevsel/RecoRoutines_W-selection_QCD_AllPtBins_7TeV_Pythia.root");
  TFile *file3 = TFile::Open("results/" + folder + "/RecoRoutines_W-selection_ZJets_madgraph_June2010.root");
  //TFile *file4 = TFile::Open("results/MuPt10/RecoRoutines_W-selection_TTbarJets_tauola_madgraph_June2010.root");

  //dynamic array size not allowed in CINT hehe
  TCanvas *canvas [4] = {makeCanvas("reco_wpt"), makeCanvas("muon_pt"), makeCanvas("pf_mt"), makeCanvas("lpvar")};
  TLegend *legend [4] = {makeLegend(), makeLegend(), makeLegend(), makeLegend()};
  TString plotnames[4] = {"RECO_PolPlots_50toinf/RECO_pfMHT", 
			  "RECO_PolPlots_50toinf/RECO_MuonPt", 
			  "RECO_PolPlots_50toinf/RECO_pfMT", 
			  "RECO_PolPlots_50toinf/RECO_ICVarPF"};
  
  TString plotlabels_m [4] = {"RECO P_{T}(W-) [GeV]", "P_{T}(#mu^{-}) [GeV]", "M_{T}- [GeV]", "LP(#mu^{-})"};
  TString plotlabels_p [4] = {"RECO P_{T}(W+) [GeV]", "P_{T}(#mu^{+}) [GeV]", "M_{T}+ [GeV]", "LP(#mu^{+})"};
  int rbinextra [4] = {2,4,2,4};
  double xmin_m [4] = {50., 20., 30., -0.5};
  double xmin_p [4] = {50., 20., 30., -0.5};
  double xmax_m [4] = {200., 170., 150., 1.5};
  double xmax_p [4] = {200., 170., 150., 1.5};
  double ymax_m [4] = {1500., 1200., 1500., 800.};
  double ymax_p [4] = {2000., 2000., 2000., 1200.};
  int skip [4] = {0,0,0,0};

  for(unsigned int i=0; i<numPlots; i++) {
    if(skip[i] == 0) {
      TH1D * data_p = (TH1D*)file0->Get(TString(plotnames[i]+"Plus"));
      TH1D * data_m = (TH1D*)file0->Get(TString(plotnames[i]+"Minus"));
      TH1D * w_p = (TH1D*)file1->Get(TString(plotnames[i]+"Plus"));
      TH1D * w_m = (TH1D*)file1->Get(TString(plotnames[i]+"Minus"));
      TH1D * qcd_p = (TH1D*)file2->Get(TString(plotnames[i]+"Plus"));
      TH1D * qcd_m = (TH1D*)file2->Get(TString(plotnames[i]+"Minus"));
      TH1D * z_p = (TH1D*)file3->Get(TString(plotnames[i]+"Plus"));
      TH1D * z_m = (TH1D*)file3->Get(TString(plotnames[i]+"Minus"));
      //TH1D * tt = (TH1D*)file4->Get(plotnames[i]);

    w_p->Rebin(rbin*rbinextra[i]);
    w_m->Rebin(rbin*rbinextra[i]);
    qcd_p->Rebin(rbin*rbinextra[i]);
    qcd_m->Rebin(rbin*rbinextra[i]);
    z_p->Rebin(rbin*rbinextra[i]);
    z_m->Rebin(rbin*rbinextra[i]);
    //tt->Rebin(rbin);
    data_p->Scale(data_scale);
    data_m->Scale(data_scale);
    data_p->Rebin(rbin*rbinextra[i]);
    data_m->Rebin(rbin*rbinextra[i]);

    w_p->Scale(w_scale);
    w_m->Scale(w_scale);
    z_p->Scale(z_scale);
    z_m->Scale(z_scale);
    //tt->Scale(lumi_scale);
    qcd_p->Scale(qcd_scale);
    qcd_m->Scale(qcd_scale);

    TH1D * mc_p = (TH1D*)qcd_p->Clone();
    mc_p->Add(w_p);
    mc_p->Add(z_p);
    mc_p->SetLineWidth(3);
    mc_p->SetLineColor(kGray);
    qcd_p->SetLineColor(kGreen);
    qcd_p->SetLineWidth(2);
    qcd_p->GetXaxis()->SetRangeUser(xmin_p[i],xmax_p[i]);
    qcd_p->GetXaxis()->SetTitle(plotlabels_p[i]);
    qcd_p->GetXaxis()->SetTitleSize(0.06);
    qcd_p->GetXaxis()->SetLabelSize(0.05);
    qcd_p->GetYaxis()->SetRangeUser(0.1,ymax_p[i]);
    qcd_p->GetYaxis()->SetTitle("Events / 35 pb^{-1}");
    qcd_p->GetYaxis()->SetTitleSize(0.06);
    qcd_p->GetYaxis()->SetTitleOffset(1.19);
    qcd_p->GetYaxis()->SetLabelSize(0.05);
    canvas[i]->cd(1);//->SetLogy();
    qcd_p->DrawCopy("h");
    w_p->SetLineColor(kBlue);
    w_p->SetLineWidth(2);
    w_p->DrawCopy("sameh");
    z_p->SetLineColor(kRed);
    z_p->SetLineWidth(2);
    z_p->DrawCopy("sameh");

    mc_p->DrawCopy("sameh");
    data_p->SetMarkerStyle(20);
    data_p->DrawCopy("samep");

    legend[i]->AddEntry(data_p, "7TeV Data", "p");
    legend[i]->AddEntry(mc_p, "All MC", "l");
    legend[i]->AddEntry(w_p, "W+Jets", "l");
    legend[i]->AddEntry(z_p, "Z+Jets", "l");
    legend[i]->AddEntry(qcd_p, "QCD", "l");
    legend[i]->DrawClone();

    TH1D * mc_m = (TH1D*)qcd_m->Clone();
    mc_m->Add(w_m);
    mc_m->Add(z_m);
    //mc->Add(tt);
    mc_m->SetLineWidth(3);
    //mc->SetLineStyle(9);
    mc_m->SetLineColor(kGray);
    qcd_m->SetLineColor(kGreen);
    qcd_m->SetLineWidth(2);
    qcd_m->GetXaxis()->SetRangeUser(xmin_m[i],xmax_m[i]);
    qcd_m->GetXaxis()->SetTitle(plotlabels_m[i]);
    qcd_m->GetXaxis()->SetTitleSize(0.06);
    qcd_m->GetXaxis()->SetLabelSize(0.05);
    qcd_m->GetYaxis()->SetRangeUser(0.1,ymax_m[i]);
    qcd_m->GetYaxis()->SetTitle("Events / 35 pb^{-1}");
    qcd_m->GetYaxis()->SetTitleSize(0.06);
    qcd_m->GetYaxis()->SetTitleOffset(1.19);
    qcd_m->GetYaxis()->SetLabelSize(0.05);
    canvas[i]->cd(2);//->SetLogy();
    qcd_m->DrawCopy("h");
    w_m->SetLineColor(kBlue);
    w_m->SetLineWidth(2);
    w_m->DrawCopy("sameh");
    z_m->SetLineColor(kRed);
    z_m->SetLineWidth(2);
    z_m->DrawCopy("sameh");

    mc_m->DrawCopy("sameh");
    data_m->SetMarkerStyle(20);
    data_m->DrawCopy("samep");
    //tplus->DrawClone("same");

    if(doPrint) canvas[i]->Print(".png");
    }
  }
  file2->Close();
  file1->Close();
  file0->Close();
  return;

}

TLatex * labelLatex(double &x, double &y, TString &label)
{
  TLatex *t1 = new TLatex(x, y, label);
  t1->SetNDC(kTRUE);
  t1->SetTextSize(0.050);
  return t1;
}

TCanvas * makeCanvas(TString & name)
{
  TCanvas *c1 = new TCanvas(name, name, 800, 400);
  c1->Divide(2,1);
  c1->cd(1)->SetLeftMargin(0.1392496);
  c1->cd(1)->SetRightMargin(0.0593692);
  c1->cd(1)->SetTopMargin(0.04123489);
  c1->cd(1)->SetBottomMargin(0.1572755);

  c1->cd(2)->SetLeftMargin(0.1392496);
  c1->cd(2)->SetRightMargin(0.0593692);
  c1->cd(2)->SetTopMargin(0.04123489);
  c1->cd(2)->SetBottomMargin(0.1572755);
  return c1;
}

TLegend * makeLegend()
{
  leg = new TLegend(0.6391466,0.6673143,0.8968254,0.9398748,NULL,"brNDC");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.04857513);
  return leg;
}
