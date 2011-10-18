#include "TObject.h"

  gSystem->Load("libRooFit");
  using namespace RooFit;
gROOT->ProcessLine(".L ptcorrection.C+O");
gSystem->Load("ptcorrection_C.so");

void misalign2(bool realdata=1, double ptmin=20, double ptmax=400, int nbins=10){

  double lumiscale;
  if (realdata==0) lumiscale=1;
  if (realdata==1) lumiscale=1;

  TFile *data;
  if (realdata==0) data=new TFile("./reco_mc/RecoRoutines_Z-selection_ZJets_TuneZ2_7TeV_alpgen_tauola.root","read");
  //if (realdata==0) data=new TFile("./reco_mc/RecoRoutines_Z-selection_DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola.Spring11-PU_S1_START311_V1G1-v1.AODSIM.root","read");
  if (realdata==1) data=new TFile("./reco_data/RecoRoutines_Z-selection_SingleMu_Run2011A_May10ReReco_v1.root","read");
  //if (realdata==1) data=new TFile("./reco_data/RecoRoutines_Z-selection_SingleMu_uptoRun163817.root","read");
  TString dir="MuPtScale0toinf/";
  TString title="dimuonstree";

  TFile *tmpfile = new TFile("./tmpfile.root","recreate");

  std::cout << (dir+title).Data() << std::endl;

  TTree *origtree = (TTree*)data->Get((dir+title).Data());
  TTree *tree0 = CorrectTree(origtree,0,realdata,lumiscale,tmpfile);
  TTree *treeC = CorrectTree(origtree,1,realdata,lumiscale,tmpfile);


  TGraphErrors *G0phiP = new TGraphErrors();
  TGraphErrors *G0phiM = new TGraphErrors();
  TGraphErrors *GCphiP = new TGraphErrors();
  TGraphErrors *GCphiM = new TGraphErrors();
  TList *LG0phiP = new TList();
  TList *LG0phiM = new TList();
  TList *LGCphiP = new TList();
  TList *LGCphiM = new TList();

  TGraphErrors *G0etaP = new TGraphErrors();
  TGraphErrors *G0etaM = new TGraphErrors();
  TGraphErrors *GCetaP = new TGraphErrors();
  TGraphErrors *GCetaM = new TGraphErrors();
  TList *LG0etaP = new TList();
  TList *LG0etaM = new TList();
  TList *LGCetaP = new TList();
  TList *LGCetaM = new TList();


  for(int i=0;i<nbins;i++){
    LG0phiP->Add(fitmacro(tree0,+1,ptmin,ptmax,1,i,nbins));
    LG0phiM->Add(fitmacro(tree0,-1,ptmin,ptmax,1,i,nbins));
    LGCphiP->Add(fitmacro(treeC,+1,ptmin,ptmax,1,i,nbins));
    LGCphiM->Add(fitmacro(treeC,-1,ptmin,ptmax,1,i,nbins));
    LG0etaP->Add(fitmacro(tree0,+1,ptmin,ptmax,2,i,nbins));
    LG0etaM->Add(fitmacro(tree0,-1,ptmin,ptmax,2,i,nbins));
    LGCetaP->Add(fitmacro(treeC,+1,ptmin,ptmax,2,i,nbins));
    LGCetaM->Add(fitmacro(treeC,-1,ptmin,ptmax,2,i,nbins));
  }

  tgemerger(G0phiP,LG0phiP);
  tgemerger(G0phiM,LG0phiM);
  tgemerger(GCphiP,LGCphiP);
  tgemerger(GCphiM,LGCphiM);
  tgemerger(G0etaP,LG0etaP);
  tgemerger(G0etaM,LG0etaM);
  tgemerger(GCetaP,LGCetaP);
  tgemerger(GCetaM,LGCetaM);

  GFormat(G0phiP,1,0);
  GFormat(G0phiM,-1,0);
  GFormat(GCphiP,1,1);
  GFormat(GCphiM,-1,1);
  GFormat(G0etaP,1,0);
  GFormat(G0etaM,-1,0);
  GFormat(GCetaP,1,1);
  GFormat(GCetaM,-1,1);
  

  TF1 *sinp = new TF1("sinp","[0]+[1]*TMath::Sin([2]*x+[3])",-3.14,3.14);
  sinp->SetParLimits(0,90,92);
  sinp->SetParameters(0,91.2);
  sinp->SetParLimits(1,0.1,2);
  sinp->SetParameters(1,1);
  sinp->SetParLimits(2,0.9,1.1);
  sinp->SetParameters(2,1);
  sinp->SetParLimits(4,-3.14,5);
  sinp->SetParameters(3,0);
  sinp->SetLineColor(kRed);

  TF1 *sinm = new TF1("sinm","[0]+[1]*TMath::Sin([2]*x+[3])",-3.14,3.14);
  sinm->SetParLimits(0,90,92);
  sinm->SetParameters(0,91.2);
  sinm->SetParLimits(1,0.1,2);
  sinm->SetParameters(1,1);
  sinm->SetParLimits(2,0.9,1.1);
  sinm->SetParameters(2,1);
  sinm->SetParLimits(3,-3.14,5);
  sinm->SetParameters(3,0);
  sinm->SetLineColor(kBlue);

  G0phiP->Fit(sinp,"","",-3.14,3.14);
  G0phiM->Fit(sinm,"","",-3.14,3.14);


  gStyle->SetOptFit(1);

  TCanvas *canv1 = new TCanvas();
  canv1->Divide(3,1);
  canv1->cd(1);
  G0phiP->Draw("AP");
  GCphiP->Draw("P");
  canv1->cd(2);
  G0phiM->Draw("AP");
  GCphiM->Draw("P");
  canv1->cd(3);
  G0phiP->Draw("AP");
  G0phiM->Draw("P");

  TCanvas *canv2 = new TCanvas();
  canv2->Divide(3,1);
  canv2->cd(1);
  G0etaP->Draw("AP");
  GCetaP->Draw("P");
  canv2->cd(2);
  G0etaM->Draw("AP");
  GCetaM->Draw("P");
  canv2->cd(3);
  G0etaP->Draw("AP");
  G0etaM->Draw("P");


  tmpfile->Close();
  data->Close();

};


TGraphErrors* fitmacro(TTree *tree, int charge, double ptmin, double ptmax, int quant, int bin, int nbins){

  using namespace RooFit;

  RooRealVar RMpPt("RMpPt","RMpPt",0,400);
  RooRealVar RMpEta("RMpEta","RMpEta",-10,10);
  RooRealVar RMpPhi("RMpPhi","RMpPhi",-10,10);
  RooRealVar RMmPt("RMmPt","RMmPt",0,400);
  RooRealVar RMmEta("RMmEta","RMmEta",-10,10);
  RooRealVar RMmPhi("RMmPhi","RMmPhi",-10,10);
  RooRealVar RZmass("RZmass","RZmass",81.2,101.2);
  RooDataHist dset("dset","dset",RooArgSet(RZmass));

  Double_t  MpPt ;
  Double_t  MpEta; 
  Double_t  MpPhi; 
  Double_t  MmPt; 
  Double_t  MmEta;
  Double_t  MmPhi;
  Double_t  Zmass;
  Double_t  EvWeight;
  tree->SetBranchAddress("MpPt",&MpPt);
  tree->SetBranchAddress("MpEta",&MpEta);
  tree->SetBranchAddress("MpPhi",&MpPhi);
  tree->SetBranchAddress("MmPt",&MmPt);
  tree->SetBranchAddress("MmEta",&MmEta);
  tree->SetBranchAddress("MmPhi",&MmPhi);
  tree->SetBranchAddress("Zmass",&Zmass);
  tree->SetBranchAddress("EvWeight",&EvWeight);
    
  Long64_t nentries = tree->GetEntries();

   
  double phimin = -3.14;
  double phimax = 3.14;
  double etamin = -2 ;
  double etamax = 2;
 
  if (quant==1) {phimin = -3.14+6.28*((double)bin/nbins);  phimax = phimin+6.28/nbins;}
  if (quant==2) {etamin= -2.0+4.0*((double)bin/nbins); etamax= etamin+4.0/nbins;}

  double pt,pt2,eta,phi;
  for (Long64_t i=0;i<nentries;i++) {
    tree->GetEntry(i);
    if (charge==1) {pt=MpPt; pt2=MmPt; eta=MpEta; phi=MpPhi;}
    else if (charge==-1) {pt=MmPt; pt2=MpPt; eta=MmEta; phi=MmPhi;}
    if (pt<pt2 || pt<ptmin || pt>ptmax || phi<phimin || phi>phimax || eta<etamin || eta>etamax) continue;
    RZmass=Zmass;
    dset.add(RooArgSet(RZmass),EvWeight);
  }


  RooRealVar mean("mean","mean",91.2,81.2,101.2);
  RooRealVar sigma("sigma","sigma",3,0,30);
  RooRealVar width("width","width",2.49,2.49,2.49);
  RooVoigtian voigt("voigt","voigt",RZmass,mean,width,sigma);

  RooFitResult *r = voigt.fitTo(dset,Save(),Verbose(kFALSE),PrintLevel(0));
  TMatrixDSym& cov = r->covarianceMatrix();

  TGraphErrors *out = new TGraphErrors();
 
  if (quant==1)  {
    out->SetPoint(0,(phimin+phimax)/2,mean.getVal());
    out->SetPointError(0,(phimax-phimin)/2,sqrt(cov[0][0]));
  }
  else if (quant==2){
    out->SetPoint(0,(etamin+etamax)/2,mean.getVal());
    out->SetPointError(0,(etamax-etamin)/2,sqrt(cov[0][0]));
  }

  delete r;
  return out;
};

TTree *CorrectTree(TTree *tree, int correct, bool realdata, double lumiscale, TFile *tmpfile){
 
  tmpfile->cd();

  Double_t  MpPt ;
  Double_t  MpEta; 
  Double_t  MpPhi; 
  Double_t  MmPt; 
  Double_t  MmEta;
  Double_t  MmPhi;
  Double_t  Zmass;
  Double_t  EvWeight;
  tree->SetBranchAddress("MpPt",&MpPt);
  tree->SetBranchAddress("MpEta",&MpEta);
  tree->SetBranchAddress("MpPhi",&MpPhi);
  tree->SetBranchAddress("MmPt",&MmPt);
  tree->SetBranchAddress("MmEta",&MmEta);
  tree->SetBranchAddress("MmPhi",&MmPhi);
  tree->SetBranchAddress("Zmass",&Zmass);
  tree->SetBranchAddress("EvWeight",&EvWeight);

  Double_t  MpPt2 ;
  Double_t  MpEta2; 
  Double_t  MpPhi2; 
  Double_t  MmPt2; 
  Double_t  MmEta2;
  Double_t  MmPhi2;
  Double_t  Zmass2;
  Double_t  EvWeight2;

  TString title("");
  title+=correct;
  newtree = new TTree(title.Data(),"");

  newtree->Branch("MpPt",&MpPt2,"MpPt/D") ;
  newtree->Branch("MpEta",&MpEta2,"MpEta/D") ;
  newtree->Branch("MpPhi",&MpPhi2,"MpPhi/D") ;
  newtree->Branch("MmPt",&MmPt2,"MmPt/D") ;
  newtree->Branch("MmEta",&MmEta2,"MmEta/D") ;
  newtree->Branch("MmPhi",&MmPhi2,"MmPhi/D") ;
  newtree->Branch("Zmass",&Zmass2,"Zmass/D") ;
  newtree->Branch("EvWeight",&EvWeight2,"EvWeight/D") ;

  Long64_t nentries = tree->GetEntriesFast();
  TLorentzVector mp,mm;

  for (int i=0; i<nentries; i++){
    tree->GetEntry(i);
    MpEta2=MpEta;
    MpPhi2=MpPhi;
    MmEta2=MmEta;
    MmPhi2=MmPhi;
    EvWeight2=EvWeight*lumiscale;
    if (correct==1) {
      MpPt2=correction(+1,MpPt,MpEta,MpPhi,realdata);
      MmPt2=correction(-1,MmPt,MmEta,MmPhi,realdata);
      mp.SetPtEtaPhiM(MpPt2,MpEta2,MpPhi2,0);
      mm.SetPtEtaPhiM(MmPt2,MmEta2,MmPhi2,0);
      Zmass2=(mp+mm).M();
    }
    else {
      MpPt2=MpPt;
      MmPt2=MmPt;
      Zmass2=Zmass;
    }
    newtree->Fill();
  }

  newtree->Write();
  return newtree;

};


bool tgemerger(TGraphErrors *graph, TCollection* li){

  TIter next(li);
  TObject *o;

  while (o = next()) {
    TGraphErrors *g = dynamic_cast<TGraphErrors*> (o);
    if (!g) return -1;
    Double_t x, y, dx, dy;
    for (Int_t i = 0 ; i < g->GetN(); i++) {
      g->GetPoint(i, x, y);
      dx=g->GetErrorX(i);
      dy=g->GetErrorY(i);
      graph->SetPoint(graph->GetN(), x, y);
      graph->SetPointError(graph->GetN()-1,dx,dy);
    }
  }

  //  return graph->GetN();
  return;
};

void GFormat(TGraphErrors *g, int sign, int corr){
  if (sign>0){
    g->SetLineColor(kRed);
    g->SetMarkerColor(kRed);
  }
  else {
    g->SetLineColor(kBlue);
    g->SetMarkerColor(kBlue);
  }
  if (corr==0){
    g->SetLineWidth(3);
    g->SetMarkerStyle(20);
    g->SetMarkerSize(0.7);
  }
  else if (corr==1){
    g->SetLineStyle(7);
    g->SetLineWidth(6);
    g->SetLineColor(kBlack);
  }
};
