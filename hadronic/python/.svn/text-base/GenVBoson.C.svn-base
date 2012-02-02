GenVBoson(){
  
  GenVBosonPlot(TString("VBETAT_0"),10,0,2);
  GenVBosonPlot(TString("VBETAT_2"),10,0,2);
  GenVBosonPlot(TString("VBETAT_3"),10,0,2);
  GenVBosonPlot(TString("VBETAT_4"),10,0,2);
  
  GenVBosonPlot(TString("Njet"),1,0,6);
  GenVBosonPlot(TString("VBY_0"),10,0,5);
  GenVBosonPlot(TString("VBPT_0"),2,100,1000,true);
  
  GenVBosonPlot(TString("VBPTHT_0"),2,0,2);
  GenVBosonPlot(TString("VBPTHT_2"),2,0,2);
  GenVBosonPlot(TString("VBPTHT_3"),2,0,2);
  GenVBosonPlot(TString("VBPTHT_4"),2,0,2);
  
  GenVBosonPlot(TString("jetPt1"),2,0,500,true);
  GenVBosonPlot(TString("jetPt2"),2,0,500,true);
  GenVBosonPlot(TString("jetPt3"),2,0,500,true);
  GenVBosonPlot(TString("jetPt4"),2,0,500,true);
  GenVBosonPlot(TString("VBHT_0"),4,100,1000,true);
  
     //  GenVBosonPlot(TString("VBDR_0"),10);

   //  GenVBosonPlot(TString("VBETHT_0"),2);

}

GenVBosonPlot(TString name, int rebin,float min = -1,float max =0, bool log=false){

  //  TCanvas* aCan = new TCanvas(name,name,0.6,0.6,0.8,0.8);

  TCanvas* aCan = new TCanvas(name);
  aCan->Divide(2,1);
  aCan->cd(1);
  if(log) aCan->SetLogy();
  // int rebin= 10;
  TFile* W = new TFile("results5/IC5Calo_WJets_madgraph.root");
  //W->ls();
  TDirectory* Wdir = ( TDirectory*) W->Get("GenVBoson200");
  Wdir->ls();
  TH1D* Wh = (TH1D*) Wdir->Get(name);
  Wh->Rebin(rebin);
  Wh->SetLineWidth(2);
  Wh->SetLineStyle(2);
  //  Wh->
  if(min>-.2)  Wh->GetXaxis()->SetRangeUser(min,max);
 
  Wh->DrawNormalized();
  //cout << Wh->GetMaximum() <<endl;
  Wh->GetXaxis()->SetRangeUser(0.00001,1);

  //  Wh->SetMaximum( Wh->GetMaximum()*1.75);


  TFile* Z = new TFile("results5/IC5Calo_Zinvisible_jets.root");
  //Z->ls();
  TDirectory* Zdir = ( TDirectory*) Z->Get("GenVBoson200");
  //  Zdir->ls();
  TH1D* Zh = (TH1D*) Zdir->Get(name);
  Zh->SetLineColor(kRed);
  Zh->SetLineWidth(2);
  Zh->SetLineStyle(2);

  Zh->Rebin(rebin);
  Zh->DrawNormalized("same");

  TFile* Ph = new TFile("results5/photon.root");
  Ph->ls();
  TDirectory* Phdir = ( TDirectory*) Ph->Get("GenVBoson200");
  // Phdir->ls();
  TH1D* Phh = (TH1D*) Phdir->Get(name);
  Phh->SetLineColor(kBlue);
  Phh->SetLineWidth(2);
  Phh->Rebin(rebin);
  Phh->DrawNormalized("same"); 

  TLegend* leg = new TLegend(0.5,0.5,0.7,0.7);
  leg->AddEntry(Zh,"Z","l" );
  leg->AddEntry(Wh,"W","l" );
  leg->AddEntry(Phh,"#gamma","l" );
  leg->Draw("same");

  aCan->cd(1);

  TH1D*  DivPhh = Phh->Clone();
  DivPhh->Divide(Zh);
  TH1D*  DivWh = Wh->Clone();
  DivWh->Divide(Zh);
  DivPhh->Draw();
DivWh->Draw("same");

}
