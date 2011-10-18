void PDFUnc_ChargeAsymmetry() {

  char h_name_plus[50], h_name_minus[50];
  TH1D * charge_ratio = new TH1D("charge ratio",";Charge Ratio;",200, -0.005, 1.995);
  TFile * file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_PDFUncertainties.root");
  
  for(unsigned int n=0; n<41; n++) {
    sprintf(h_name_plus, "RECO_PDFUncPlots_50toinf/RECO_ICVarPFPlus_hist_%d",n);
    //RECO_ICVarPFPlus[n] = new TH1D(h_name_plus,";LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
    sprintf(h_name_minus, "RECO_PDFUncPlots_50toinf/RECO_ICVarPFMinus_hist_%d",n);
    //RECO_ICVarPFMinus[n] = new TH1D(h_name_minus,";LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);
    
    TH1D * hist_plus = (TH1D*)file0->Get(h_name_plus);
    TH1D * hist_minus = (TH1D*)file0->Get(h_name_minus);
    
    //cout << hist_plus->Integral() << endl;
    //cout << hist_minus->Integral() << endl;
    charge_ratio->Fill( hist_plus->Integral() / hist_minus->Integral());
    
  }
  
  charge_ratio->Draw();
  return;
  
}
