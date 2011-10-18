void vertex_reweighting() {
  
  //TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_newJetColl.root");
  TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJetsMGZ238PU.root");
  TFile * file1 = TFile::Open("results/RecoRoutines_W-selection_dataskimnov4rereco_newJetColl.root");
  TH1F * hist1 = (TH1F*)file0->Get("RECO_PolPlots_50toinf/RECO_NumVerticesPerEvent");
  TH1F * hist2 = (TH1F*)file1->Get("RECO_PolPlots_50toinf/RECO_NumVerticesPerEvent");

  //given the different number of vertices seen between data and MC
  //we would like to reweight the two distributions onto each other (MC-->Data)
  //since MC only has max 4, we will map 1 to 1, 2 to 2, 3 to 3 and >=4 to >=4

  hist1->Scale(36.0);
  double mc_int = hist1->Integral();
  double data_int = hist2->Integral();

  TH1F * newhist = new TH1F("newhist",";NumVerticesPerEvent;Events",25, -0.5, 24.5);
  for(unsigned int i=2; i<14; i++) {
    double weight = (hist2->GetBinContent(i) / data_int) / ( hist1->GetBinContent(i)/ mc_int);
    cout << weight << endl;
    newhist->Fill(i-1, hist1->GetBinContent(i)*weight);
  }

  //now for >=4 bin:
  //weight = (hist2->Integral(5,11) / data_int) / ( hist1->GetBinContent(5)/ mc_int);
  //cout << weight << endl;
  //newhist->Fill(4, hist1->GetBinContent(5)*weight);

  //newhist->Draw();
  //hist2->Draw("same");
  //hist1->Draw();
  //hist2->Draw("same");
  newhist->Divide(hist2);
  newhist->Draw();
  return;
}
