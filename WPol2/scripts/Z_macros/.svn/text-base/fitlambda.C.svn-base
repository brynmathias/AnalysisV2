void fitlambda(bool realdata=1){

 gSystem->Load("libRooFit");
  using namespace RooFit;

TFile *data;
 if (realdata==1) data=new TFile("./RecoRoutines_Z-selection_data36pb.rew2.corr1.root","read");
 if (realdata==0) data=new TFile("./RecoRoutines_Z-selection_ZJets_TuneZ2_7TeV_alpgen_tauola.rew2.corr1.root","read");
TString dir="MuPtScale0toinf/";
TString title="dimuonstree";
TTree *tree = (TTree*)data->Get((dir+title).Data());

RooRealVar RMpPt("RMpPt","RMpPt",0,400);
RooRealVar RMpEta("RMpEta","RMpEta",-10,10);
RooRealVar RMpPhi("RMpPhi","RMpPhi",-10,10);
RooRealVar RMmPt("RMmPt","RMmPt",0,400);
RooRealVar RMmEta("RMmEta","RMmEta",-10,10);
RooRealVar RMmPhi("RMmPhi","RMmPhi",-10,10);
 RooRealVar RZmass("RZmass","RZmass",81.2,101.2);

RooDataSet dataset("dataset","dataset",RooArgSet(RMpPt,RMpEta,RMpPhi,RMmPt,RMmEta,RMmPhi,RZmass),StoreError(RooArgSet(RZmass)));

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
    
  for (Long64_t i=0;i<nentries;i++) {
    tree->GetEntry(i);
    RMpPt=MpPt;
    RMpEta=MpEta;
    RMpPhi=MpPhi;
    RMmPt=MmPt;
    RMmEta=MmEta;
    RMmPhi=MmPhi;
    RZmass=Zmass;
    RZmass.setError(3);
    dataset.add(RooArgSet(RMpPt,RMpEta,RMpPhi,RMmPt,RMmEta,RMmPhi,RZmass),EvWeight);
    }

  RooRealVar mean("mean","mean",91.2,85.0,95.0);
  RooRealVar cs01("cs01","cs01",0,-0.00,0.00);
  RooRealVar cs02("cs02","cs02",0,-0.00,0.00);
  RooRealVar ca01("ca01","ca01",0,-0.00,0.00);
  RooRealVar ca02("ca02","ca02",0,-0.05,0.05);
  RooRealVar cas1("cas1","cas1",0,-0.00,0.00);
  RooRealVar cas2("cas2","cas2",0,-0.05,0.05);
  RooRealVar phase("phase","phase",0,-3.14,3.14);
  RooRealVar cae1("cae1","cae1",0,-0.00,0.00);
  RooRealVar caeB2("caeB2","caeB2",0,-0.05,0.05);
  RooRealVar caeE2("caeE2","caeE2",0,-0.05,0.05);

  RooArgSet deps(RMpPt,RMmPt,RMpPhi,RMmPhi,RMpEta,RMmEta);
  deps.add(mean);
  deps.add(cs01);
  deps.add(cs02);
  deps.add(ca01);
  deps.add(ca02);
  deps.add(cas1);
  deps.add(cas2);
  deps.add(phase);
  deps.add(cae1);
  deps.add(caeB2);
  deps.add(caeE2);


// corrfunction:
 //  dp/p = CS01+CS02*p+charge*(CA01+CA02*p)+charge*(CAS1+CAS2*p)*sin(phi+PHASE)+charge*(CAE1+CAE2*p)*eta


// 0.5*(caeB2+caeE2+TMath::Sign(caeB2,1-abs(eta))+TMath::Sign(caeE2,abs(eta)-1))

  RooFormulaVar model("model","mean+mean/2*(cs01+cs02*RMpPt/100+(ca01+ca02*RMpPt/100)+(cas1+cas2*RMpPt/100)*sin(RMpPhi+phase)+\
(cae1+0.5*(caeB2+caeE2+TMath::Sign(caeB2,0.5-abs(RMpEta))+TMath::Sign(caeE2,abs(RMpEta)-0.5))*RMpPt/100)*RMpEta)\
+mean/2*(cs01+cs02*RMmPt/100-(ca01+ca02*RMmPt/100)-(cas1+cas2*RMmPt/100)*sin(RMmPhi+phase)-\
(cae1+0.5*(caeB2+caeE2+TMath::Sign(caeB2,0.5-abs(RMmEta))+TMath::Sign(caeE2,abs(RMmEta)-0.5))*RMmPt/100)*RMmEta)",deps);
  


  RooFitResult *r =  model.chi2FitTo(dataset,YVar(RZmass),Save());

  r->Print();

 RooPlot* frame = RMpPhi.frame() ;
 dataset.plotOnXY(frame,YVar(RZmass));
 model.plotOn(frame);
 frame->Draw();



};
