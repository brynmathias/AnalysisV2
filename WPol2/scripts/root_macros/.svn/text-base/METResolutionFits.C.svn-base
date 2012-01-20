void METResolutionFits() {
  
  TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
  TH2F * hist = (TH2F*)file0->Get("RECO_PolPlots_50toinf/MC_RECO_PFMETres_vs_genMHT");
  
  numbinsy = hist->GetNbinsY();
  numbinsx = hist->GetNbinsX();

  TH1F * res = new TH1F("res",";;",50,-0.5,49.5);
  TH1F * myhist[30];

  for(unsigned int j=5;j<31;j++) {
    myhist[j] = new TH1F("myhist",";;",100,-5.05,4.95);
    for(unsigned int i=0;i<numbinsy; i++) {
      myhist[j]->SetBinContent(i, hist->GetBinContent(j,i));
      myhist[j]->SetBinError(i, hist->GetBinError(j,i));
    }

    TF1 *gfit = new TF1("gaus","gaus",-5.,5.); // Create the fit function
    myhist[j]->Fit(gfit);
    //cout << gfit->GetParameter(2) << endl;
    res->SetBinContent(j,j*10*gfit->GetParameter(2));
    res->SetBinError(j,j*10*gfit->GetParError(2));
  }
  res->Draw();
  //myhist[10]->Draw();
  return;
}
