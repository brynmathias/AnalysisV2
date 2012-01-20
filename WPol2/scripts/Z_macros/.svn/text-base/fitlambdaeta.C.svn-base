void fitlambdaeta(bool realdata=1){

 gSystem->Load("libRooFit");
  using namespace RooFit;

TFile *data;
 if (realdata==1) data=new TFile("../results/reco_data/RecoRoutines_Z-selection_SingleMu_Run2011A_May10ReReco_v1.root","read");
 //if (realdata==1) data=new TFile("./reco_data/RecoRoutines_Z-selection_SingleMu_uptoRun163817.root","read");
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

  RooRealVar mean("mean","mean",90.8,88.0,92.0);
  RooRealVar ca02("ca02","ca02",-0.002,-0.02,0.02);
  RooRealVar barrcas2("barrcas2","barrcas2",0.008,0.0,0.02);
  RooRealVar barrphase("barrphase","barrphase",0,-3.14,3.14);
  RooRealVar endpcas2("endpcas2","endpcas2",0.008,-0.02,0.02);
  RooRealVar endpphase("endpphase","endpphase",0,-3.14,3.14);
  RooRealVar endmcas2("endmcas2","endmcas2",0.008,-0.02,0.02);
  RooRealVar endmphase("endmphase","endmphase",0,-3.14,3.14);


  RooArgSet deps(RMpPt,RMmPt,RMpPhi,RMmPhi,RMpEta,RMmEta);
  deps.add(mean);
  deps.add(ca02);
  deps.add(barrcas2);
  deps.add(barrphase);
  deps.add(endpcas2);
  deps.add(endpphase);
  deps.add(endmcas2);
  deps.add(endmphase);


// corrfunction:
 //  dp/p = charge*(CA02*p)+charge*(CAS2*p)*sin(phi+PHASE)


// 0.5*(caeB2+caeE2+TMath::Sign(caeB2,1-abs(eta))+TMath::Sign(caeE2,abs(eta)-1))

//   RooFormulaVar model("model","mean+mean/2*(ca02*RMpPt/100)+(cas1+cas2*RMpPt/100)*sin(RMpPhi+phase)+\
// (cae1+0.5*(caeB2+caeE2+TMath::Sign(caeB2,0.5-abs(RMpEta))+TMath::Sign(caeE2,abs(RMpEta)-0.5))*RMpPt/100)*RMpEta)\
// +mean/2*(cs01+cs02*RMmPt/100-(ca01+ca02*RMmPt/100)-(cas1+cas2*RMmPt/100)*sin(RMmPhi+phase)-\
// (cae1+0.5*(caeB2+caeE2+TMath::Sign(caeB2,0.5-abs(RMmEta))+TMath::Sign(caeE2,abs(RMmEta)-0.5))*RMmPt/100)*RMmEta)",deps);


  //  RooFormulaVar amplp("amplp","0.5*(endmcas2+barrcas2+endpcas2+TMath::Sign(endmcas2,RMpEta+1)+TMath::Sign(endpcas2,RMpEta-1)+TMath::Sign(barrcas2,1-abs(RMpEta)))",RooArgSet(RMpEta,barrcas2,endpcas2,endmcas2));
 
  //  0.5*(endmphase+barrphase+endpphase+TMath::Sign(endmphase,RMpEta+1)+TMath::Sign(endpphase,RMpEta-1)+TMath::Sign(barrphase,1-abs(RMpEta)))

  RooFormulaVar model("model","mean\
+mean/2*(ca02*RMpPt/100+0.5*(endmcas2+barrcas2+endpcas2+TMath::Sign(endmcas2,RMpEta+1)+TMath::Sign(endpcas2,RMpEta-1)+TMath::Sign(barrcas2,1-abs(RMpEta)))*RMpPt/100*sin(RMpPhi+ 0.5*(endmphase+barrphase+endpphase+TMath::Sign(endmphase,RMpEta+1)+TMath::Sign(endpphase,RMpEta-1)+TMath::Sign(barrphase,1-abs(RMpEta)))))\
-mean/2*(ca02*RMmPt/100+0.5*(endmcas2+barrcas2+endpcas2+TMath::Sign(endmcas2,RMmEta+1)+TMath::Sign(endpcas2,RMmEta-1)+TMath::Sign(barrcas2,1-abs(RMmEta)))*RMmPt/100*sin(RMmPhi+ 0.5*(endmphase+barrphase+endpphase+TMath::Sign(endmphase,RMmEta+1)+TMath::Sign(endpphase,RMmEta-1)+TMath::Sign(barrphase,1-abs(RMmEta)))))", deps);


  RooFitResult *r =  model.chi2FitTo(dataset,YVar(RZmass),Save());

  r->Print();
/*
 RooPlot* frame = RMpPhi.frame() ;
 dataset.plotOnXY(frame,YVar(RZmass));
 model.plotOn(frame);
 frame->Draw();

*/

};
