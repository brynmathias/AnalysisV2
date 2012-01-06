void ChargeAsymmvsPTW() {
  
  //TFile * file0 = TFile::Open("results/ChargeAsymmCheck/RecoRoutines_W-selection_WJets_madgraph_Fall2010Z2.root");
  TFile * file0 = TFile::Open("results/ChargeAsymmCheck/RecoRoutines_W-selection_dataskimnov4rereco.root");

  TH1F * PTWplus = (TH1F*)file0->Get("RECO_PolPlots_MT50/RECO_pfMHTPlus");
  TH1F * PTWminus = (TH1F*)file0->Get("RECO_PolPlots_MT50/RECO_pfMHTMinus");
  double int_lumi = 1.0;
  PTWplus->Scale(int_lumi);
  PTWminus->Scale(int_lumi);

  cout << "total plus integral: " << PTWplus->Integral() << endl;
  cout << "total minus integral: " << PTWminus->Integral() << endl;
  //cout << "num + events between PTW 20-30 GeV: " << PTWplus->Integral(PTWplus->FindBin(10.0), PTWplus->FindBin(20.0)) << endl;
  //cout << "num - events between PTW 20-30 GeV: " << PTWminus->Integral(PTWminus->FindBin(10.0), PTWminus->FindBin(20.0)) << endl;
  //cout << "num + events between PTW 60-70 GeV: " << PTWplus->Integral(PTWplus->FindBin(60.0), PTWplus->FindBin(70.0)) << endl;
  //cout << "num - events between PTW 60-70 GeV: " << PTWminus->Integral(PTWminus->FindBin(60.0), PTWminus->FindBin(70.0)) << endl;

  TH1F * chargeratio = new TH1F("chargeratio", ";;",10,0.,100.);
  TH1F * chargeasymm = new TH1F("chargeasymm", ";;",10,0.,100.);

  for(unsigned int i=0; i<100; i+=10) {
    //cout << "bin:  " << i << " to " << i+10 << endl;
    double NBinplus = PTWplus->Integral(PTWplus->FindBin(i), PTWplus->FindBin(i+10));
    double NBinminus = PTWminus->Integral(PTWminus->FindBin(i), PTWminus->FindBin(i+10));
    double ratio_error = TMath::Sqrt((1.0/NBinplus) + (1.0/NBinminus)) * (NBinplus / NBinminus);
    
    double charge_asymm = (NBinplus - NBinminus) /  (NBinplus + NBinminus);
    double asymm_error = (2.0 / (NBinplus + NBinminus) ) * TMath::Sqrt( (NBinplus * NBinminus) / (NBinplus + NBinminus));

    chargeratio->SetBinContent((i/10)+1, NBinplus / NBinminus);
    chargeratio->SetBinError((i/10)+1, ratio_error);

    chargeasymm->SetBinContent((i/10)+1, charge_asymm);
    chargeasymm->SetBinError((i/10)+1, asymm_error);

  }
  chargeratio->Draw("HISTE");

  return;
}
