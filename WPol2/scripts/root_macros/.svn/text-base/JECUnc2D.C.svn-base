void JECUnc2D() {
  
  TFile *file0 = TFile::Open("results/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2_2DJECUNC.root");

  TH2D * pHist2D = (TH2D*)file0->Get("JecUncPlots2d/RECO_ICVarPFPlus_vs_JECUncSigma");
  TH2D * mHist2D = (TH2D*)file0->Get("JecUncPlots2d/RECO_ICVarPFMinus_vs_JECUncSigma");
  TH1D * pHist = (TH1D*)file0->Get("JecUncPlots2d/RECO_ICVarPFPlus");
  TH2D * pHist2DC = (TH2D*)pHist2D->Clone();
  TH2D * mHist2DC = (TH2D*)mHist2D->Clone();

  cout << "num x bins: " << pHist2D->GetNbinsX() << endl;
  cout << "num y bins: " << pHist2D->GetNbinsY() << endl;
  cout << pHist2D->GetBinContent(200,11) << endl;
  cout << pHist->GetBinContent(200) << endl;

  for(unsigned int sigma_step=0; sigma_step<21; sigma_step++) {

    for(unsigned int lp=0; lp<500;lp++){
      pHist2DC->SetBinContent(lp,sigma_step, pHist2DC->GetBinContent(lp, sigma_step) - pHist2D->GetBinContent(lp, 11));
      mHist2DC->SetBinContent(lp,sigma_step, mHist2DC->GetBinContent(lp, sigma_step) - mHist2D->GetBinContent(lp, 11));
    }
  }

  pHist2DC->Draw();

  return;
}
