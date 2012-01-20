void ptwsyst_LPderivatives() {

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TCanvas * c1 = new TCanvas("c1","c1",500,500);
  TCanvas * c2 = new TCanvas("c2","c2",500,500);

  TFile *file0 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_WJets_madgraph_June2010.root");  
  TFile *file1 = TFile::Open("results/hltmu15_goodevsel_newtemplates/syst_shift_pfmht/RecoRoutines_W-selection_WJets_madgraph_June2010_shift_pfmht_p3pc.root");
  TFile *file2 = TFile::Open("results/hltmu15_goodevsel_newtemplates/syst_shift_pfmht/RecoRoutines_W-selection_WJets_madgraph_June2010_shift_pfmht_m3pc.root");

  TString charge = "Minus";
  TString bin = "75to100";
  unsigned int rebin_factor = 10;
  double int_lumi = 35.0;
  double x_range_min = -0.2;
  double x_range_max = 1.3;

  TH1F * original_LP = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge))->Clone();
  TH1F * p3pcmht_LP = (TH1F*)((TH1F*)file1->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge))->Clone();
  TH1F * p3pcmht_LP_noevsel = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge+"_PTWp3pc"))->Clone();
  TH1F * m3pcmht_LP = (TH1F*)((TH1F*)file2->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge))->Clone();
  TH1F * m3pcmht_LP_noevsel = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge+"_PTWm3pc"))->Clone();

  original_LP->Rebin(rebin_factor);
  p3pcmht_LP->Rebin(rebin_factor);
  p3pcmht_LP_noevsel->Rebin(rebin_factor);
  m3pcmht_LP->Rebin(rebin_factor);
  m3pcmht_LP_noevsel->Rebin(rebin_factor);

  TH1F * diff1 = (TH1F*)p3pcmht_LP->Clone();
  TH1F * diff2 = (TH1F*)p3pcmht_LP_noevsel->Clone();
  TH1F * diff3 = (TH1F*)m3pcmht_LP->Clone();
  TH1F * diff4 = (TH1F*)m3pcmht_LP_noevsel->Clone();

  c1->cd();
  diff1->Add(original_LP, -1);
  diff1->Divide(original_LP);
  diff1->SetLineWidth(2);
  if(charge == "Plus") diff1->GetXaxis()->SetTitle("LP Variable Plus");
  else diff1->GetXaxis()->SetTitle("LP Variable Minus");
  diff1->GetYaxis()->SetTitle("Percentage change");
  diff1->GetXaxis()->SetRangeUser(x_range_min,x_range_max);
  diff1->GetYaxis()->SetRangeUser(-0.5,0.5);
  diff1->Draw("hist");

  diff2->Add(original_LP, -1);
  diff2->Divide(original_LP);
  diff2->SetLineWidth(2);
  diff2->SetLineColor(kRed);
  diff2->Draw("hist same");

  leg = new TLegend(0.168,0.744,0.427,0.862,NULL,"brNDC");
  leg->AddEntry(diff1,"Before Selection","l");
  leg->AddEntry(diff2,"After Selection","l");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.06);
  leg->DrawClone();

  TLatex *comment1 = new TLatex(0.3, 0.3, "MHT + 3%");
  comment1->SetNDC(kTRUE);
  comment1->SetTextSize(0.06);
  comment1->DrawClone("same");

  c2->cd();
  diff3->Add(original_LP, -1);
  diff3->Divide(original_LP);
  diff3->SetLineWidth(2);
  if(charge == "Plus") diff3->GetXaxis()->SetTitle("LP Variable Plus");
  else diff3->GetXaxis()->SetTitle("LP Variable Minus");
  diff3->GetYaxis()->SetTitle("Percentage change");
  diff3->GetXaxis()->SetRangeUser(x_range_min,x_range_max);
  diff3->GetYaxis()->SetRangeUser(-0.5,0.5);
  diff3->Draw("hist");

  diff4->Add(original_LP, -1);
  diff4->Divide(original_LP);
  diff4->SetLineWidth(2);
  diff4->SetLineColor(kRed);
  diff4->Draw("hist same");
  leg->DrawClone();
  TLatex *comment2 = new TLatex(0.3, 0.3, "MHT - 3%");
  comment2->SetNDC(kTRUE);
  comment2->SetTextSize(0.06);
  comment2->DrawClone("same");

  //original_LP->SetLineWidth(2);
  //if(charge == "Plus") original_LP->GetXaxis()->SetTitle("LP Variable Plus");
  //else original_LP->GetXaxis()->SetTitle("LP Variable Minus");
  //original_LP->GetYaxis()->SetTitle("Events / 35 pb^{-1}");
  //original_LP->Scale(int_lumi);
  //original_LP->Draw("hist");
  //p3pcmht_LP->SetLineWidth(2);
  //p3pcmht_LP->SetLineColor(kRed);
  //p3pcmht_LP->Scale(int_lumi);
  //p3pcmht_LP->Draw("hist same");

//   diff3->Add(p3pcmht_LP_noevsel, -1);
//   //diff3->Divide(original_LP);
//   diff3->SetLineWidth(2);
//   diff3->SetLineColor(kRed);
//   diff3->Draw("hist same");

//   c2->cd();
//   diff2->Add(m3pcmht_LP, -1);
//   diff2->SetLineWidth(2);
//   if(charge == "Plus") diff2->GetXaxis()->SetTitle("LP Variable Plus");
//   else diff2->GetXaxis()->SetTitle("LP Variable Minus");
//   diff2->GetYaxis()->SetTitle("#Delta LP");
//   diff2->Draw("hist");

//   diff4->Add(m3pcmht_LP_noevsel, -1);
//   diff4->SetLineWidth(2);
//   diff4->SetLineColor(kRed);
//   diff4->Draw("hist same");

//   cout << "Integral of original hist: " << original_LP->Integral() << endl;
//   cout << "Integral of p3pc hist: " << p3pcmht_LP->Integral() << endl;
//   cout << "Integral of p3pc hist noevsel: " << p3pcmht_LP_noevsel->Integral() << endl;
//   cout << "Integral of m3pc hist: " << m3pcmht_LP->Integral() << endl;
//   cout << "Integral of m3pc hist noevsel: " << m3pcmht_LP_noevsel->Integral() << endl;
//   cout << "Integral of diff1: " << diff1->Integral() << endl;
//   cout << "Integral of diff2: " << diff2->Integral() << endl;

  return;
}
