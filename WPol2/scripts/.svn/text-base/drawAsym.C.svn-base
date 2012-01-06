drawAsym(){
  
  TString mi1 = TString("ttTemplate/ScaleMinus_0");
  TString pl1 = TString("ttTemplate/ScalePlus_0");
  TH1D* jet1 = drawAsymPlot(pl1,mi1);
  jet1->Draw();

  TString mi2 = TString("ttTemplate/MeffMinus");
  TString pl2 = TString("ttTemplate/MeffPlus");
  TH1D* jet2 = drawAsymPlot(pl2,mi2);
  jet2->SetLineColor(kRed);
  jet2->Draw("same");
 


  TString mi3 = TString("ttTemplate/ScaleMinus_3");
  TString pl3 = TString("ttTemplate/ScalePlus_3");
  TH1D* jet3 = drawAsymPlot(pl3,mi3);
  jet3->SetLineColor(kBlue);
  //  jet3->Draw("same");
  
  TString mi4 = TString("ttTemplate/ScaleMinus_4");
  TString pl4 = TString("ttTemplate/ScalePlus_4");
  TH1D* jet4 = drawAsymPlot(pl4,mi4);
  jet4->SetLineColor(kGreen);
  //  jet4->Draw("same");

  TLegend* aTLegend = new TLegend(0.5,0.5,0.75,0.75);
  aTLegend->AddEntry(jet1,"jet1","lp");
 aTLegend->AddEntry(jet2,"jet1","lp");
 aTLegend->AddEntry(jet3,"jet1","lp");
 aTLegend->AddEntry(jet4,"jet1","lp");

  aTLegend->Draw("same");
}


TH1D* drawAsymPlot(TString pl, TString mi)
{
  
  TFile *tempW = new TFile("results/RecoRoutines_W-selection_WJets.root");
  TFile *tempTT = new TFile("results/RecoRoutines_W-selection_ttbarTauola.root");
  TFile *tempZ = new TFile("results/RecoRoutines_W-selection_ZJets.root");
  TFile *data = new TFile("results/all.root");

  TString Minus = "pl";
  TH1D *mc1M = (TH1D*)tempW->Get(mi);
  // TH1D *mc2M = (TH1D*)tempTT->Get(Minus);
  // TH1D *mc3M = (TH1D*)tempZ->Get(Minus);
  // TH1D *DATA1M = (TH1D*) data->Get(Minus);
  
  TString Plus = "mi";
  TH1D *mc1P = (TH1D*)tempW->Get(pl);
  int rebin = 5;
  mc1P->Rebin(rebin);
  mc1M->Rebin(rebin);
  //  TDirectory* =
 ((TDirectory*)tempW->Get("ttTemplate"))->ls();
  //  TH1D *mc2P = (TH1D*)tempTT->Get(Plus);
  // TH1D *mc3P = (TH1D*)tempZ->Get(Plus);
  // TH1D *DATA1P = (TH1D*) data->Get(Plus);


  TH1D *mc1S = mc1P->Clone();
  //  mc1S->Add(mc1M,-1);
  TH1D *mc1A = mc1M->Clone();
  // mc1A->Add(mc1M,1);

  mc1S->Divide(mc1A);
  // mc1S->DrawCopy();
  return mc1S;
}
