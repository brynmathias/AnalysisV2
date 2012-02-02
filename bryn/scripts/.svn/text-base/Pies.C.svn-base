Pies()

{
  // TFile* file = new TFile("RecoLM_TTbarJets.root");
  TFile* file = new TFile("RecoLM_WJets.root");
  TDirectory* dir = (TDirectory*)file->Get("tt");
  dir->ls();
 
  TCanvas *cpie = new TCanvas("cpie","TPie test",700,700);
  TH1D* test = (TH1D*) dir->Get("NLeptons_0");
  // test->Draw("pie");
  TPie* aPie= new TPie(test);
  aPie->SetLabelFormat("%perc %txt");
  aPie->GetSlice(1)->SetTitle("semi leptonic");
  aPie->GetSlice(1)->SetFillColor(3);
  aPie->GetSlice(0)->SetTitle("hadronic");
  aPie->GetSlice(0)->SetFillColor(2);
  aPie->GetSlice(2)->SetTitle("leptonic (#tau #tau)");
  aPie->GetSlice(2)->SetFillColor(4);
  aPie->SetRadius(.4);
  aPie->SetTextSize(0.04);
  aPie->SetLabelsOffset(-.3);
  aPie->Draw("nol <");
  
  TCanvas *cKind = new TCanvas("kind","lepton kind",700,700);
  TH1D* hKind = (TH1D*) dir->Get("NKind_0");
  TPie* aKind= new TPie(hKind);
  aKind->SetLabelFormat("%perc %txt");
  aKind->GetSlice(1)->SetTitle("e");
  aKind->GetSlice(1)->SetFillColor(3);
  aKind->GetSlice(0)->SetTitle("#tau");
  aKind->GetSlice(0)->SetFillColor(2);
  aKind->GetSlice(2)->SetTitle("#mu");
  aKind->GetSlice(2)->SetFillColor(4);
  aKind->SetRadius(.3);
  aKind->SetTextSize(0.05);
  aKind->SetLabelsOffset(-.1);
  aKind->Draw("nol <");


 TCanvas *cKind = new TCanvas("kind","lepton kind",700,700);
  TH1D* hKind = (TH1D*) dir->Get("NKind_0");
  TPie* aKind= new TPie(hKind);
  aKind->SetLabelFormat("%perc %txt");
  aKind->GetSlice(1)->SetTitle("e");
  aKind->GetSlice(1)->SetFillColor(3);
  aKind->GetSlice(0)->SetTitle("#tau");
  aKind->GetSlice(0)->SetFillColor(2);
  aKind->GetSlice(2)->SetTitle("#mu");
  aKind->GetSlice(2)->SetFillColor(4);
  aKind->SetRadius(.3);
  aKind->SetTextSize(0.05);
  aKind->SetLabelsOffset(-.1);
  aKind->Draw("nol <");

  TCanvas *cMac = new TCanvas("Muacc","Muacc",700,700);
  TH1D* hMac = (TH1D*) dir->Get("NMuon_0");
  TPie* aMac= new TPie(hMac);
  aMac->SetLabelFormat("%perc %txt");
  aMac->GetSlice(1)->SetTitle("#splitline{#mu out of}{acceptance}");
  aMac->GetSlice(1)->SetFillColor(3);
  aMac->GetSlice(0)->SetTitle("#splitline{#mu failed}{selection}");
  aMac->GetSlice(0)->SetFillColor(2);
  aMac->SetRadius(.3);
  aMac->SetTextSize(0.05);
  aMac->SetLabelsOffset(-.2);
  aMac->Draw("nol <");
  
  TCanvas *cEliac = new TCanvas("Elicc","Eliacc",700,700);
  TH1D* hEliac = (TH1D*) dir->Get("NEli_0");
  TPie* aEliac= new TPie(hEliac);
  aEliac->SetLabelFormat("%perc %txt");
  aEliac->GetSlice(1)->SetTitle("#splitline{e out of}{acceptance}");
  aEliac->GetSlice(1)->SetFillColor(3);
  aEliac->GetSlice(0)->SetTitle("#splitline{e failed}{selection}");
  aEliac->GetSlice(0)->SetFillColor(2);
  aEliac->SetRadius(.3);
  aEliac->SetTextSize(0.05);
  aEliac->SetLabelsOffset(-.2);


  // hEliac->Draw();
 aEliac->Draw("nol <");


 // TCanvas *cEliacg = new TCanvas("Eutrlicc","Eliacc",700,700);
 // hEliac->Draw();
}
