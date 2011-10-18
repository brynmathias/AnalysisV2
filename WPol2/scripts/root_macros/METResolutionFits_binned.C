void METResolutionFits_binned() {
  
  //TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
  TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJetsMGZ238PU.root");

  TH2F * hist = (TH2F*)file0->Get("RECO_PolPlots_50toinf/MC_RECO_PFMETres_vs_genMHT");
  
  int numbinsy = hist->GetNbinsY();
  int numbinsx = hist->GetNbinsX();

  TH1F * res = new TH1F("res",";;",100,-0.5,99.5);
  TH1F * res2 = new TH1F("res2",";;",100,-0.5,99.5);
  TH1F * myhist[100];

  //now construct the 1D histograms from the 2D histogram:
  for(unsigned int j=0;j<numbinsx;j++) {
    myhist[j] = new TH1F("myhist",";;",100,-5.05,4.95);
    for(unsigned int i=0;i<numbinsy; i++) {
      myhist[j]->SetBinContent(i, hist->GetBinContent(j,i));
      myhist[j]->SetBinError(i, hist->GetBinError(j,i));
    }
  }

  TF1 *gfit = new TF1("gaus","gaus",-5.,5.); // Create the fit function
  std::vector<double> results;

  myhist[1]->Add(myhist[2]);
  myhist[1]->Add(myhist[3]);
  myhist[1]->Add(myhist[4]);
  myhist[1]->Add(myhist[5]);
  myhist[11]->Add(myhist[12]);
  myhist[13]->Add(myhist[14]);
  myhist[15]->Add(myhist[16]);
  myhist[17]->Add(myhist[18]);
  myhist[19]->Add(myhist[20]);
  myhist[21]->Add(myhist[22]);
  myhist[21]->Add(myhist[23]);
  myhist[21]->Add(myhist[24]);
  myhist[21]->Add(myhist[25]);

  myhist[1]->Fit(gfit);
  res->SetBinContent(1,25*gfit->GetParameter(2));
  res->SetBinError(1,25*gfit->GetParError(2));
  res2->SetBinContent(1,gfit->GetParameter(2));
  res2->SetBinError(1,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[6]->Fit(gfit);
  res->SetBinContent(2,55*gfit->GetParameter(2));
  res->SetBinError(2,55*gfit->GetParError(2));
  res2->SetBinContent(2,gfit->GetParameter(2));
  res2->SetBinError(2,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[7]->Fit(gfit);
  res->SetBinContent(3,65*gfit->GetParameter(2));
  res->SetBinError(3,65*gfit->GetParError(2));
  res2->SetBinContent(3,gfit->GetParameter(2));
  res2->SetBinError(3,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[8]->Fit(gfit);
  res->SetBinContent(4,75*gfit->GetParameter(2));
  res->SetBinError(4,75*gfit->GetParError(2));
  res2->SetBinContent(4,gfit->GetParameter(2));
  res2->SetBinError(4,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[9]->Fit(gfit);
  res->SetBinContent(5,85*gfit->GetParameter(2));
  res->SetBinError(5,85*gfit->GetParError(2));
  res2->SetBinContent(5,gfit->GetParameter(2));
  res2->SetBinError(5,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[10]->Fit(gfit);
  res->SetBinContent(6,95*gfit->GetParameter(2));
  res->SetBinError(6,95*gfit->GetParError(2));
  res2->SetBinContent(6,gfit->GetParameter(2));
  res2->SetBinError(6,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[11]->Fit(gfit);
  res->SetBinContent(7,110*gfit->GetParameter(2));
  res->SetBinError(7,110*gfit->GetParError(2));
  res2->SetBinContent(7,gfit->GetParameter(2));
  res2->SetBinError(7,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[13]->Fit(gfit);
  res->SetBinContent(8,130*gfit->GetParameter(2));
  res->SetBinError(8,130*gfit->GetParError(2));
  res2->SetBinContent(8,gfit->GetParameter(2));
  res2->SetBinError(8,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[15]->Fit(gfit);
  res->SetBinContent(9,150*gfit->GetParameter(2));
  res->SetBinError(9,150*gfit->GetParError(2));
  res2->SetBinContent(9,gfit->GetParameter(2));
  res2->SetBinError(9,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[17]->Fit(gfit);
  res->SetBinContent(10,170*gfit->GetParameter(2));
  res->SetBinError(10,170*gfit->GetParError(2));
  res2->SetBinContent(10,gfit->GetParameter(2));
  res2->SetBinError(10,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[19]->Fit(gfit);
  res->SetBinContent(11,190*gfit->GetParameter(2));
  res->SetBinError(11,190*gfit->GetParError(2));
  res2->SetBinContent(11,gfit->GetParameter(2));
  res2->SetBinError(11,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));

  myhist[21]->Fit(gfit);
  res->SetBinContent(12,225*gfit->GetParameter(2));
  res->SetBinError(12,225*gfit->GetParError(2));
  res2->SetBinContent(12,gfit->GetParameter(2));
  res2->SetBinError(12,gfit->GetParError(2));
  results.push_back(gfit->GetParameter(2));
  
  res->Draw();
  //myhist[9]->Draw();
  for(unsigned int i=0;i<results.size();i++) cout << results.at(i) << endl;
  return;
}
