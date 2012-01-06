{
  gStyle->SetOptStat(0);

  //HADRONIC CUT FOR FAKE RATE
  TString hhh="50HT";  
  TString conf="";

  //REBIN FACTOR
  int rebX=2;
  int rebY=4;
  //
  float minEl=0.0001;
  float maxEl=3;
  bool LogEl=false;
  float minMu=0.0001;
  float maxMu=1.4;
  bool LogMu=false;
  float minTau=0.1;
  float maxTau=2.7;
  bool LogTau=false;  
  //////////////////////////////////////

  


  TFile *files[11];
  int totbin=11;




  files[0] =new TFile("test_QCD_Pt15_7TeV_Pythia6.root");
  files[1] =new TFile("test_QCD_Pt30_7TeV_Pythia6.root");
  files[2] =new TFile("test_QCD_Pt80_7TeV_Pythia6.root");
  files[3] =new TFile("test_QCD_Pt170_7TeV_Pythia6.root");
  files[4] =new TFile("test_QCD_Pt300_7TeV_Pythia6.root");
  files[5] =new TFile("test_QCD_Pt470_7TeV_Pythia6.root");
  files[6] =new TFile("test_QCD_Pt800_7TeV_Pythia6.root");
  files[7] =new TFile("test_QCD_Pt1400_7TeV_Pythia6.root");
  files[8] =new TFile("test_ttbarTauola.root");
  files[9] =new TFile("test_wjets_madgraph_vols.root");
  // files[10] =new TFile("test_zjets_madgraph_vols.root");
  files[10] =new TFile("DATA.root");
  float w[12];
  w[0] =1437.;
  w[1] =119.2;
  w[2] =4.472;
  w[3] =0.0803;
  w[4] =0.00422;
  w[5] =0.0004074;
  w[6] =0.0000102;
  w[7] =0.00000009468;
  w[8] =0.0007409;
  w[9] =0.02409;
  w[10]=0.02212;

  
  


  TString MUFR="MuonFR_"+hhh+conf;
  TString ELFR="ElectronFR_"+hhh;
  TString TAUFR="TAUFR_"+hhh;




  for (int ih=0; ih<totbin; ih++){

    files[ih]->cd(ELFR);
    hGoodEl->RebinX(rebX);
    hGoodEl->RebinY(rebY);
    hAllEl->RebinX(rebX);
    hAllEl->RebinY(rebY);

    files[ih]->cd(MUFR);
    hGoodMu->RebinX(rebX);
    hGoodMu->RebinY(rebY);
    hAllMu->RebinX(rebX);
    hAllMu->RebinY(rebY);
 
   files[ih]->cd(TAUFR); 
    h_IDTau_EtaPt->RebinX(rebX);
    h_IDTau_EtaPt->RebinY(rebY);
    h_RecoTau_EtaPt->RebinX(rebX);
    h_RecoTau_EtaPt->RebinY(rebY);
 
  }
  int mxX=h_IDTau_EtaPt->GetNbinsX();
  int mxY=h_IDTau_EtaPt->GetNbinsY();
  float xmin=h_IDTau_EtaPt->GetXaxis()->GetXmin();
  float xmax=h_IDTau_EtaPt->GetXaxis()->GetXmax();
  float ymin=h_IDTau_EtaPt->GetYaxis()->GetXmin();
  float ymax=h_IDTau_EtaPt->GetYaxis()->GetXmax();

  
  //CLONE HISTOGRAMS
  TH2D* TAU_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* TAU_NUM= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* TAU_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);

  TH2D* MU_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* MU_NUM= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* MU_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);

  TH2D* EL_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* EL_NUM= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* EL_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  
 
  //EVALUATE FAKE RATE AND THE ERROR 
  for (int i=1; i<mxX+1; i++){
    for (int j=1; j<mxY+1; j++){
      float taunum=0; float taunumerr=0;
      float tauden=0; float taudenerr=0;
      float munum=0; float munumerr=0;
      float muden=0; float mudenerr=0; 
      float elnum=0; float elnumerr=0;
      float elden=0; float eldenerr=0; 

      for (int ih=0; ih<totbin; ih++){  
	//ELECTRON SUM
	files[ih]->cd(ELFR);
	elden+=hAllEl->GetBinContent(i,j)-hGoodEl->GetBinContent(i,j);
	elnum+=hGoodEl->GetBinContent(i,j);
	eldenerr+=(hAllEl->GetBinContent(i,j)-hGoodEl->GetBinContent(i,j))*w[ih];
	elnumerr+=(hGoodEl->GetBinContent(i,j))*w[ih];	
	//MUON SUM
	files[ih]->cd(MUFR);
	muden+=hAllMu->GetBinContent(i,j)-hGoodMu->GetBinContent(i,j);
	munum+=hGoodMu->GetBinContent(i,j);
	mudenerr+=(hAllMu->GetBinContent(i,j)-hGoodMu->GetBinContent(i,j))*w[ih];
	munumerr+=(hGoodMu->GetBinContent(i,j))*w[ih];	
	//TAU SUM
	files[ih]->cd(TAUFR);
	tauden+=h_RecoTau_EtaPt->GetBinContent(i,j)-h_IDTau_EtaPt->GetBinContent(i,j);
	taunum+=h_IDTau_EtaPt->GetBinContent(i,j);
	taudenerr+=(h_RecoTau_EtaPt->GetBinContent(i,j)-h_IDTau_EtaPt->GetBinContent(i,j))*w[ih];
	taunumerr+=(h_IDTau_EtaPt->GetBinContent(i,j))*w[ih];	
      }
      //FILL HISTOTRAMS FOR RATE
      EL_DEN->SetBinContent(i,j,elden); EL_DEN->SetBinError(i,j,sqrt(eldenerr));
      EL_NUM->SetBinContent(i,j,elnum); EL_NUM->SetBinError(i,j,sqrt(elnumerr));
      MU_DEN->SetBinContent(i,j,muden); MU_DEN->SetBinError(i,j,sqrt(mudenerr));
      MU_NUM->SetBinContent(i,j,munum); MU_NUM->SetBinError(i,j,sqrt(munumerr)); 
      TAU_DEN->SetBinContent(i,j,tauden); TAU_DEN->SetBinError(i,j,sqrt(taudenerr));
      TAU_NUM->SetBinContent(i,j,taunum); TAU_NUM->SetBinError(i,j,sqrt(taunumerr));      
    }
  }



  //FAKE RATE PLOTS
  EL_FR->Divide(EL_NUM,EL_DEN);
  MU_FR->Divide(MU_NUM,MU_DEN);
  TAU_FR->Divide(TAU_NUM,TAU_DEN);
  
  TFile* dataFile=new TFile("DATA.root");
  TH2D* DATA_EL_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax); 
  TH2D* DATA_EL_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* DATA_MU_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax); 
  TH2D* DATA_MU_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* DATA_TAU_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax); 
  TH2D* DATA_TAU_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);

  dataFile->cd(ELFR);
  hGoodEl->RebinX(rebX);
  hGoodEl->RebinY(rebY);
  hAllEl->RebinX(rebX);
  hAllEl->RebinY(rebY);
  DATA_EL_DEN->Add(hAllEl,hGoodEl,1.,-1.);
  DATA_EL_DEN->Sumw2();
  hGoodEl->Sumw2();
  DATA_EL_FR->Divide(hGoodEl,DATA_EL_DEN);

  dataFile->cd(MUFR);
  hGoodMu->RebinX(rebX); 
  hGoodMu->RebinY(rebY);
  hAllMu->RebinX(rebX);
  hAllMu->RebinY(rebY);
  DATA_MU_DEN->Add(hAllMu,hGoodMu,1.,-1.);
  DATA_MU_DEN->Sumw2();
  hGoodMu->Sumw2();
  DATA_MU_FR->Divide(hGoodMu,DATA_MU_DEN);
 
  dataFile->cd(TAUFR);
  h_IDTau_EtaPt->RebinX(rebX);
  h_IDTau_EtaPt->RebinY(rebY);
  h_RecoTau_EtaPt->RebinX(rebX);
  h_RecoTau_EtaPt->RebinY(rebY);
  DATA_TAU_DEN->Add(h_RecoTau_EtaPt,h_IDTau_EtaPt,1.,-1.);
  DATA_TAU_DEN->Sumw2();
  h_IDTau_EtaPt->Sumw2();
  DATA_TAU_FR->Divide(h_IDTau_EtaPt,DATA_TAU_DEN);

  //
  int xbin =DATA_TAU_FR->GetNbinsX();
  int x1_5=int(xbin*1.5/2.5);

  TLegend *tauLeg=new TLegend(0.1,0.9,0.25,0.7);
  TCanvas *taufr=new TCanvas("Tau Fake Rate"," Tau Fake Rate ", 100,100,900,900);  
  taufr->Divide(1,2);
  taufr->cd(1);
  TH1D *tau1=TAU_FR->ProjectionY("TAU |#eta|<1.5",1,x1_5,"s");
  tau1->SetTitle("TAU |#eta|<1.5");
  tau1->GetXaxis()->SetTitle("Pt (GeV)");
  tau1->GetYaxis()->SetTitle("Tight ID / (Loose Id && !TightID)");
  tau1->SetMinimum(minTau);
  tau1->SetMaximum(maxTau);
  if (LogTau) taufr->GetPad(1)->SetLogy();
  tau1->Draw();
  TH1D *datatau1=DATA_TAU_FR->ProjectionY("DATA TAU |#eta|<1.5",1,x1_5,"s");
  datatau1->SetLineColor(2);
  datatau1->Draw("same");
  tauLeg->AddEntry(tau1,"MC","l");
  tauLeg->AddEntry(datatau1,"DATA","l");
  tauLeg->Draw();
  taufr->cd(2);
  TH1D *tau2=TAU_FR->ProjectionY("TAU |#eta|>1.5",x1_5+1,xbin,"s");
  tau2->SetTitle("TAU |#eta|>1.5");
  tau2->GetXaxis()->SetTitle("Pt (GeV)");
  tau2->GetYaxis()->SetTitle("Tight ID / (Loose Id && !TightID)");
  tau2->SetMinimum(minTau);
  tau2->SetMaximum(maxTau);
  if (LogTau) taufr->GetPad(2)->SetLogy();
  tau2->Draw();

  TH1D *datatau2=DATA_TAU_FR->ProjectionY("DATA TAU |#eta|>1.5",x1_5+1,xbin,"s");
  datatau2->SetLineColor(2);
  datatau2->Draw("same");

  TLegend *muLeg=new TLegend(0.1,0.9,0.25,0.7);
  TCanvas *mufr=new TCanvas("Mu Fake Rate"," Mu Fake Rate ", 100,100,900,900);  
  mufr->Divide(1,2);
  mufr->cd(1);
  TH1D *mu1=MU_FR->ProjectionY("MU |#eta|<1.5",1,x1_5,"s");
  mu1->SetTitle("MU |#eta|<1.5");
  mu1->GetXaxis()->SetTitle("Pt (GeV)");
  mu1->GetYaxis()->SetTitle("Tight ID / (Loose Id && !TightID)");
  mu1->SetMinimum(minMu);
  mu1->SetMaximum(maxMu);
  if (LogMu) mufr->GetPad(1)->SetLogy();
  mu1->Draw();
  TH1D *datamu1=DATA_MU_FR->ProjectionY("DATA MU |#eta|<1.5",1,x1_5,"s");
  datamu1->SetLineColor(2);
  datamu1->Draw("same");
  muLeg->AddEntry(mu1,"MC","l");
  muLeg->AddEntry(datamu1,"DATA","l");
  muLeg->Draw();
  mufr->cd(2);
  TH1D *mu2=MU_FR->ProjectionY("MU |#eta|>1.5",x1_5+1,xbin,"s");
  mu2->SetTitle("MU |#eta|>1.5");
  mu2->GetXaxis()->SetTitle("Pt (GeV)");
  mu2->GetYaxis()->SetTitle("Tight ID / (Loose Id && !TightID)");
  mu2->SetMinimum(minMu);
  mu2->SetMaximum(maxMu);
  if (LogMu) mufr->GetPad(2)->SetLogy();
  mu2->Draw();

  TH1D *datamu2=DATA_MU_FR->ProjectionY("DATA MU |#eta|>1.5",x1_5+1,xbin,"s");
  datamu2->SetLineColor(2);
  datamu2->Draw("same");


  TLegend *elLeg=new TLegend(0.1,0.9,0.25,0.7);
  TCanvas *elfr=new TCanvas("El Fake Rate"," El Fake Rate ", 100,100,900,900);  
  elfr->Divide(1,2);
  elfr->cd(1);
  TH1D *el1=EL_FR->ProjectionY("EL |#eta|<1.5",1,x1_5,"s");
  el1->SetTitle("EL |#eta|<1.5");
  el1->GetXaxis()->SetTitle("Pt (GeV)");
  el1->GetYaxis()->SetTitle("Tight ID / (Loose Id && !TightID)");
  el1->SetMinimum(minEl);
  el1->SetMaximum(maxEl);
  if (LogEl) elfr->GetPad(1)->SetLogy();
  el1->Draw();
  TH1D *datael1=DATA_EL_FR->ProjectionY("DATA EL |#eta|<1.5",1,x1_5,"s");
  datael1->SetLineColor(2);
  datael1->Draw("same");
  elLeg->AddEntry(el1,"MC","l");
  elLeg->AddEntry(datael1,"DATA","l");
  elLeg->Draw();
  elfr->cd(2);
  TH1D *el2=EL_FR->ProjectionY("EL |#eta|>1.5",x1_5+1,xbin,"s");
  el2->SetTitle("EL |#eta|>1.5");
  el2->GetXaxis()->SetTitle("Pt (GeV)");
  el2->GetYaxis()->SetTitle("Tight ID / (Loose Id && !TightID)");
  el2->SetMinimum(minEl);
  el2->SetMaximum(maxEl);
  if (LogEl) elfr->GetPad(2)->SetLogy();
  el2->Draw();

  TH1D *datael2=DATA_EL_FR->ProjectionY("DATA EL |#eta|>1.5",x1_5+1,xbin,"s");
  datael2->SetLineColor(2);
  datael2->Draw("same");
}
