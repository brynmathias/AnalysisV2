void Zselection() {
  TLatex *tplus = labelLatex(0.20,0.80,"7 TeV Data");
  gROOT->SetStyle("Plain"); 
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  //the correct W x-sec to use is 31314, c.f. 24170, 30380
  double w_scale = 35.0;//(31314.0 / 24170.0) * 3.2;
  double z_scale = w_scale;
  double qcd_scale = 14./1000.0;
  double data_scale = 1.;
  unsigned int rbin = 5;
  unsigned int numPlots = 11;
  bool doPrint = false;

  TString folder = "hltmu15_goodevsel/Zselection";

  TFile *file0 = TFile::Open("results/" + folder + "/RecoRoutines_Z-selection_realdata.root");
  TFile *file1 = TFile::Open("results/" + folder + "/RecoRoutines_Z-selection_WJets_madgraph_June2010.root");
  //TFile *file1 = TFile::Open("results/" + folder + "/RecoRoutines_W-selection_WJets_sherpa.root");
  //TFile *file2 = TFile::Open("results/" + folder + "/RecoRoutines_W-selection_QCD_AllPtBins_7TeV_Pythia.root");
  TFile *file3 = TFile::Open("results/" + folder + "/RecoRoutines_Z-selection_ZJets_madgraph_June2010.root");
  //TFile *file4 = TFile::Open("results/MuPt10/RecoRoutines_W-selection_TTbarJets_tauola_madgraph_June2010.root");

  //dynamic array size not allowed in CINT hehe
  TCanvas *canvas [11] = {makeCanvas("reco_wpt_plus"), makeCanvas("reco_wpt_minus"), makeCanvas("reco_wpt"), makeCanvas("muon_pt_plus"), makeCanvas("muon_pt_minus"), makeCanvas("muon_pt"), makeCanvas("pf_mt_plus"), makeCanvas("pf_mt_minus"), makeCanvas("pf_mt"), makeCanvas("lpvar_plus"), makeCanvas("lpvar_minus")};
  TLegend *legend [11] = {makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend(), makeLegend()};

  TString plotnames [11] = {"RECO_PolPlots_50toinf/RECO_pfMHTPlus",
                            "RECO_PolPlots_50toinf/RECO_pfMHTMinus",
                            "RECO_PolPlots_50toinf/RECO_pfMHT", 
                            "RECO_PolPlots_50toinf/RECO_MuonPtPlus", 
                            "RECO_PolPlots_50toinf/RECO_MuonPtMinus", 
                            "RECO_PolPlots_50toinf/RECO_MuonPt", 
                            "RECO_PolPlots_50toinf/RECO_pfMTPlus",
                            "RECO_PolPlots_50toinf/RECO_pfMTMinus",
                            "RECO_PolPlots_50toinf/RECO_pfMT", 
                            "RECO_PolPlots_50toinf/RECO_ICVarPlus", 
                            "RECO_PolPlots_50toinf/RECO_ICVarMinus"};
  TString plotlabels [11] = {"RECO P_{T}(W+) [GeV]", "RECO P_{T}(W-) [GeV]", "RECO P_{T}(W) [GeV]", "P_{T}(Muon+) [GeV]", "P_{T}(Muon-) [GeV]", "P_{T}(Muon) [GeV]", "M_{T}+ [GeV]", "M_{T}- [GeV]", "M_{T} [GeV]", "LP(+)", "LP(-)"};
  int rbinextra [11] = {2,2,2,4,4,4,2,2,2,4,4};
  double xmin [11] = {50., 50., 50., 0., 0., 0., 30., 30., 30., -0.5, -0.5};
  double xmax [11] = {120., 120., 120., 140., 140., 140., 90., 90., 90., 1.5, 1.5};
  double ymax [11] = {170., 150., 300., 150., 100., 250., 160., 130., 260., 150., 80.};
  int skip [11] = {0,0,0,0,0,0,0,0,0,0,0};


  for(unsigned int i=0; i<numPlots; i++) {
    if(skip[i] == 0) {
    TH1D * data = (TH1D*)file0->Get(plotnames[i]);
    TH1D * w = (TH1D*)file1->Get(plotnames[i]);
    //TH1D * qcd = (TH1D*)file2->Get(plotnames[i]);
    TH1D * z = (TH1D*)file3->Get(plotnames[i]);
    //TH1D * tt = (TH1D*)file4->Get(plotnames[i]);

    w->Rebin(rbin*rbinextra[i]);
    //qcd->Rebin(rbin*rbinextra[i]);
    z->Rebin(rbin*rbinextra[i]);
    //tt->Rebin(rbin);
    data->Scale(data_scale);
    data->Rebin(rbin*rbinextra[i]);

    w->Scale(w_scale);
    z->Scale(z_scale);
    //tt->Scale(lumi_scale);
    //qcd->Scale(qcd_scale);

    TH1D * mc = (TH1D*)w->Clone();
    //mc->Add(w);
    mc->Add(z);
    //mc->Add(tt);
    mc->SetLineWidth(3);
    //mc->SetLineStyle(9);
    mc->SetLineColor(kGray);
    //qcd->SetLineColor(kGreen);
    //qcd->SetLineWidth(2);
    //qcd->GetXaxis()->SetRangeUser(xmin[i],xmax[i]);
    //qcd->GetXaxis()->SetTitle(plotlabels[i]);
    //qcd->GetXaxis()->SetTitleSize(0.05);
    //qcd->GetYaxis()->SetRangeUser(0.1,ymax[i]);
    //qcd->GetYaxis()->SetTitle("Events / 2.8 pb^{-1}");
    //qcd->GetYaxis()->SetTitleSize(0.05);
    //qcd->GetYaxis()->SetTitleOffset(1.36);
    canvas[i]->cd(1);//->SetLogy();
    //qcd->DrawCopy("h");
    w->SetLineColor(kBlue);
    w->SetLineWidth(2);
    w->DrawCopy("h");
    z->SetLineColor(kRed);
    z->SetLineWidth(2);
    z->DrawCopy("sameh");
    //tt->SetLineColor(kGold);
    //tt->SetLineWidth(2);
    //tt->DrawCopy("sameh");

    mc->DrawCopy("sameh");
    data->SetMarkerStyle(20);
    data->DrawCopy("samep");
    //tplus->DrawClone("same");
    legend[i]->AddEntry(data, "7TeV Data", "p");
    legend[i]->AddEntry(mc, "All MC", "l");
    legend[i]->AddEntry(w, "W+Jets", "l");
    legend[i]->AddEntry(z, "Z+Jets", "l");
    //legend[i]->AddEntry(qcd, "QCD", "l");
    legend[i]->DrawClone();

    data->Divide(mc);
    canvas[i]->cd(2);
    data->GetXaxis()->SetRangeUser(xmin[i], xmax[i]);
    data->GetXaxis()->SetTitleSize(0.05);
    data->GetXaxis()->SetTitle(plotlabels[i]);
    data->GetYaxis()->SetTitle("Data / MC");
    data->GetYaxis()->SetTitleSize(0.05);
    data->GetYaxis()->SetTitleOffset(1.36);
    data->DrawCopy();

    if(doPrint) canvas[i]->Print(".png");
    }
  }
  //file2->Close();
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
