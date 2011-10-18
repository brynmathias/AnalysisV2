void Dcurvature(const char *chargechoice = "plus", double ptmin=20){

  TString sign=chargechoice;

  gStyle->SetPalette(1);
  gStyle->SetOptStat("e");

//  double ptmin=20;
  double ptmax=200;
  double etamax=2.1; 
  int ptbins=(ptmax-ptmin)/10;
  double ptbinwidth=(ptmax-ptmin)/ptbins;
  int etabins=21;
  int phibins=21;


  TProfile3D *khistptetaphi = new TProfile3D("DeltaCurv(pt,eta,phi)","DeltaCurv(pt,eta,phi) "+sign,ptbins,ptmin,ptmax,etabins,-etamax,etamax,phibins,-3.14,3.14);
  khistptetaphi->GetXaxis()->SetTitle("Pt");
  khistptetaphi->GetYaxis()->SetTitle("Eta");
  khistptetaphi->GetZaxis()->SetTitle("Phi");

  TProfile2D *khistpteta = new TProfile2D("DeltaCurv(pt,eta)","DeltaCurv(pt,eta) "+sign,ptbins,ptmin,ptmax,etabins,-etamax,etamax);
  khistpteta->GetXaxis()->SetTitle("Pt");
  khistpteta->GetYaxis()->SetTitle("Eta");
  TProfile2D *khistptphi = new TProfile2D("DeltaCurv(pt,phi)","DeltaCurv(pt,phi) "+sign,ptbins,ptmin,ptmax,phibins,-3.14,3.14);
  khistptphi->GetXaxis()->SetTitle("Pt");
  khistptphi->GetYaxis()->SetTitle("Phi");

  TProfile *khistpt = new TProfile("DeltaCurv(pt)","DeltaCurv(pt) "+sign,ptbins,ptmin,ptmax);
  khistpt->GetXaxis()->SetTitle("Pt");
  khistpt->SetAxisRange(-0.001,0.001,"Y");
  TProfile *khisteta = new TProfile("DeltaCurv(eta)","DeltaCurv(eta) "+sign,etabins,-etamax,etamax);
  khistpt->GetXaxis()->SetTitle("Eta");
  TProfile *khistphi = new TProfile("DeltaCurv(phi)","DeltaCurv(phi) "+sign,phibins,-3.14,3.14);
  khistpt->GetXaxis()->SetTitle("Phi");

  TObjArray *khistptbins= new TObjArray();
  for (int i=0; i<ptbins; i++) {
    TString name="DeltaCurv(eta,phi), pt bin ";
    name+=int(ptmin+i*(ptmax-ptmin)/ptbins);
    name+=TString(", charge ")+sign;
    TProfile2D *ist = new TProfile2D(name.Data(),name.Data(),phibins,-3.14,3.14,etabins,-etamax,etamax);
    ist->SetAxisRange(-0.002,0.002,"Z");
    khistptbins->Add(ist);
  }

  TFile *f = new TFile("RecoRoutines_Z-selection_ZJets_TuneZ2_7TeV_alpgen_tauola.rew8.corr1.root","read");

  TTree *tree;

  f->GetObject("SingleMuPtScale/"+sign+"muonstree",tree);

  Double_t MCPt;
  Double_t MCEta;
  Double_t MCPhi;
  Double_t RecoPt;
  Double_t RecoEta;
  Double_t RecoPhi;
  Double_t EvWeight;

  tree->SetBranchAddress("RecoPt",&RecoPt);
  tree->SetBranchAddress("RecoEta",&RecoEta);
  tree->SetBranchAddress("RecoPhi",&RecoPhi);
  tree->SetBranchAddress("MCPt",&MCPt);
  tree->SetBranchAddress("MCEta",&MCEta);
  tree->SetBranchAddress("MCPhi",&MCPhi);
  tree->SetBranchAddress("EvWeight",&EvWeight);

  long nentries = tree->GetEntriesFast();

  for (int i=0; i<nentries; i++){
    tree->GetEntry(i);
    if (RecoPt<ptmin || RecoPt>ptmax || RecoEta<-etamax || RecoEta>etamax) continue;
    double quantity=(MCPt-RecoPt)/MCPt/RecoPt;
    khistptetaphi->Fill(RecoPt,RecoEta,RecoPhi,quantity,EvWeight);
    khistpteta->Fill(RecoPt,RecoEta,quantity,EvWeight);
    khistptphi->Fill(RecoPt,RecoPhi,quantity,EvWeight);
    ((TProfile2D*)(khistptbins->At(int((RecoPt-ptmin)/ptbinwidth))))->Fill(RecoPhi,RecoEta,quantity,EvWeight);
    khistpt->Fill(RecoPt,quantity,EvWeight);
    khisteta->Fill(RecoEta,quantity,EvWeight);
    khistphi->Fill(RecoPhi,quantity,EvWeight);
  }



  TCanvas *c1 = new TCanvas();
  khistptetaphi->Draw("BOX");

  TCanvas *c2 = new TCanvas();
  c2->Divide(2,1);
  c2->cd(1);
  khistpteta->Draw("BOX");
  c2->cd(2);
  khistptphi->Draw("BOX");

  TCanvas *c2b = new TCanvas();
  c2b->Divide(3,1);
  c2b->cd(1);
  khistpt->Draw();
  c2b->cd(2);
  khisteta->Draw();
  c2b->cd(3);
  khistphi->Draw();

  TCanvas *c3 = new TCanvas();
  c3->Divide(int(sqrt(ptbins))+1,int(sqrt(ptbins)));
  for (int i=0;i<ptbins;i++) { c3->cd(i+1); ((TProfile2D*)(khistptbins->At(i)))->Draw("SURF1 PSR Z");}




  TProfile *khistcorrpt = new TProfile("DeltaCurv(pt)","DeltaCurv(pt) "+sign,ptbins,ptmin,ptmax);
  khistcorrpt->GetXaxis()->SetTitle("Pt");
  khistcorrpt->SetAxisRange(-0.001,0.001,"Y");
  TProfile *khistcorreta = new TProfile("DeltaCurv(eta)","DeltaCurv(eta) "+sign,etabins,-etamax,etamax);
  khistcorrpt->GetXaxis()->SetTitle("Eta");
  TProfile *khistcorrphi = new TProfile("DeltaCurv(phi)","DeltaCurv(phi) "+sign,phibins,-3.14,3.14);
  khistcorrpt->GetXaxis()->SetTitle("Phi");

  // correction
   for (int i=0; i<nentries; i++){
    tree->GetEntry(i);
    if (RecoPt<ptmin || RecoPt>ptmax || RecoEta<-etamax || RecoEta>etamax) continue;
    double newpt=RecoPt+RecoPt*RecoPt*khistptetaphi->GetBinContent(khistptetaphi->FindBin(RecoPt,RecoEta,RecoPhi));
    double quantity=(MCPt-newpt)/MCPt/newpt;
    khistcorrpt->Fill(RecoPt,quantity,EvWeight);
    khistcorreta->Fill(RecoEta,quantity,EvWeight);
    khistcorrphi->Fill(RecoPhi,quantity,EvWeight);
   }

   TCanvas *corrc2b = new TCanvas();
  corrc2b->Divide(3,1);
  corrc2b->cd(1);
  khistcorrpt->Draw();
  corrc2b->cd(2);
  khistcorreta->Draw();
  corrc2b->cd(3);
  khistcorrphi->Draw();


khistptetaphi->SetName("ist");
khistptetaphi->SaveAs("mcptbinscorrectionfactors.C");

}
