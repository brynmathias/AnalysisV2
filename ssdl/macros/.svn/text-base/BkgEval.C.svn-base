{
  //HADRONIC SELECTION
  TString HT="";
  TString PREF="";
  //HADRONIC CUT FOR FAKE RATE
  TString hhh="";  
  //CONFIGURATION FOR MUON FAKE RATE "", "_2JEts", "_3Jets"
  TString conf="";
  //DATA OR MC
  bool isData=false;
  //REBIN FACTOR
  //STANDARD BINNING
  //  int rebX=5;
  //  int rebY=5;

  //
  int rebX=5;
  int rebY=5;
  //MIN & MAX VALUE FOR THE PLOT
  float minP=0.0001;
  float maxP=14;
  //LOG OR LIN SCALE
  bool Log=true;
  //ADDLMO TO TEST CONTAMINATION LEVEL
  bool ADDLMO=false;
  bool singleTau=true;
  
  float TAUMisCharge=0.065;  
  float TAUMisCharge_stat=0.023;
  float TAUMisCharge_syst=0.023;
  //////////////////////////////////////
  gStyle->SetOptStat(0);
  TH1F *obs =new TH1F("obs","obs",6,0,6);
  TH1F *pre =new TH1F("pre","pre",6,0,6);
  TString channels[6];
  channels[0]="e-e"; channels[1]="#mu-#mu"; channels[2]="#tau-#tau";
  channels[3]="e-#mu"; channels[4]="e-#tau"; channels[5]="#mu-#tau";
  for (int ich=0;ich<6;ich++){
    obs->GetXaxis()->SetBinLabel(ich+1,channels[ich]);
    pre->GetXaxis()->SetBinLabel(ich+1,channels[ich]);
  }
  
  pre->SetMinimum(minP);
  pre->SetMaximum(maxP);

  TFile *files[12];
  int totbin=3;

  files[0] =new TFile("Mu.root");
  files[1] =new TFile("El.root");
  files[2] =new TFile("HT.root");
  files[3] =new TFile("Tau.root");


  TString SELE=PREF+"Selection"+HT;
  TString TAUNORM=PREF+"TAUNORM"+HT;
  TString TAUFR="TAUFR";
  


  

 
  files[1]->cd(TAUNORM+"El");
  hGoodElFakeTau->RebinX(rebX);
  hGoodElFakeTau->RebinY(rebY);
  float N_OS_TAUEL=hAllGoodWrongCharge->GetBinContent(5);
  files[0]->cd(TAUNORM+"Mu");
  hGoodMuFakeTau->RebinX(rebX);
  hGoodMuFakeTau->RebinY(rebY);
  float N_OS_TAUMU=hAllGoodWrongCharge->GetBinContent(6);
  files[3]->cd(TAUNORM+"Tau");
  float N_OS_TAUTAU=hAllGoodWrongCharge->GetBinContent(3);
  hGoodTauFakeTau->RebinX(rebX);
  hGoodTauFakeTau->RebinY(rebY);
  files[2]->cd(TAUFR);
  //  cout<<"SS "<<h_IDTau_EtaPt->Integral()<<" "<<h_RecoTau_EtaPt->Integral()<<endl;
  h_IDTau_EtaPt->RebinX(rebX);
  h_IDTau_EtaPt->RebinY(rebY);
  h_RecoTau_EtaPt->RebinX(rebX);
  h_RecoTau_EtaPt->RebinY(rebY);
  
  int mxX=h_IDTau_EtaPt->GetNbinsX();
  int mxY=h_IDTau_EtaPt->GetNbinsY();
  float xmin=h_IDTau_EtaPt->GetXaxis()->GetXmin();
  float xmax=h_IDTau_EtaPt->GetXaxis()->GetXmax();
  float ymin=h_IDTau_EtaPt->GetYaxis()->GetXmin();
  float ymax=h_IDTau_EtaPt->GetYaxis()->GetXmax();
  float etawidth=h_IDTau_EtaPt->GetXaxis()->GetBinWidth(1);
  float ptwidth=h_IDTau_EtaPt->GetYaxis()->GetBinWidth(1);
  
  //CLONE HISTOGRAMS
  TH2D* TAU_DEN= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* TAU_NUM= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D* TAU_FR= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);

  
  TH2D *GE_FE= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D *GE_FM= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D *GE_FT= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D *GM_FE= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax);
  TH2D *GM_FM= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax); 
  TH2D *GM_FT= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax); 
  TH2D *GT_FT= new TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax); 
  //EVALUATE FAKE RATE AND THE ERROR 
  for (int i=1; i<mxX+1; i++){
    for (int j=1; j<mxY+1; j++){
      float taunum=0; float taunumerr=0;
      float tauden=0; float taudenerr=0;
      float geft=0;  float gefterr=0;
      float gmft=0;  float gmfterr=0;
      float gtft=0;  float gtfterr=0;
	
      //TAU SUM
      files[2]->cd(TAUFR);
      tauden+=h_RecoTau_EtaPt->GetBinContent(i,j)-h_IDTau_EtaPt->GetBinContent(i,j);
      taunum+=h_IDTau_EtaPt->GetBinContent(i,j);
      taudenerr+=(h_RecoTau_EtaPt->GetBinContent(i,j)-h_IDTau_EtaPt->GetBinContent(i,j));
      taunumerr+=h_IDTau_EtaPt->GetBinContent(i,j);	

      //NORMALIZATION
      files[1]->cd(TAUNORM+"El");
      //Good Electron -Fake Tau
      geft+=hGoodElFakeTau->GetBinContent(i,j); 
      //	gefterr+=(hGoodElFakeTau->GetBinContent(i,j)*w[ih]);
      files[0]->cd(TAUNORM+"Mu");  
      //Good Muon -Fake Tau
      gmft+=hGoodMuFakeTau->GetBinContent(i,j); 
      gmfterr+=hGoodMuFakeTau->GetBinContent(i,j);
      files[3]->cd(TAUNORM+"Tau"); 
      gtft    += hGoodTauFakeTau->GetBinContent(i,j); 
      gtfterr += hGoodTauFakeTau->GetBinContent(i,j);
    
      //FILL HISTOTRAMS FOR RATE
      TAU_DEN->SetBinContent(i,j,tauden); 
      TAU_DEN->SetBinError(i,j,sqrt(taudenerr));
      TAU_NUM->SetBinContent(i,j,taunum); 
      TAU_NUM->SetBinError(i,j,sqrt(taunumerr));      
      //      cout<<"i,j  "<<taunum<<" "<<tauden<<endl;
      //FILL HISTOGRAMS FOR NORMALIZATION
      //      cout<<"EEE "<<geft<<" "<<gmft<<endl;
      GE_FT->SetBinContent(i,j,geft); 
      GE_FT->SetBinError(i,j,sqrt(gefterr));
      GM_FT->SetBinContent(i,j,gmft); 
      GM_FT->SetBinError(i,j,sqrt(gmfterr));
      GT_FT->SetBinContent(i,j,gtft); 
      GT_FT->SetBinError(i,j,sqrt(gtfterr));     
    }
  }

//   //SELECTION
  float tt=0; float tterr=0;
  float et=0; float eterr=0;
  float mt=0; float mterr=0;
  
  files[3]->cd(SELE+"Tau");
  tt+=h_RECSTATE->GetBinContent(3);
  tterr+=h_RECSTATE->GetBinContent(3);
  files[1]->cd(SELE+"El");
  et+=h_RECSTATE->GetBinContent(5);
  eterr+=h_RECSTATE->GetBinContent(5);
  files[0]->cd(SELE+"Mu");
  mt+=h_RECSTATE->GetBinContent(6);
  mterr+=h_RECSTATE->GetBinContent(6);

  obs->SetBinContent(3,tt);   
  obs->SetBinError(3,sqrt(tterr));
  obs->SetBinContent(5,et);   
  obs->SetBinError(5,sqrt(eterr));
  obs->SetBinContent(6,mt);   
  obs->SetBinError(6,sqrt(mterr));
  
  
//   //FAKE RATE PLOTS
  TAU_FR->Divide(TAU_NUM,TAU_DEN);
  

  float bkg=0.;
  float tot=0;
  float bkgErr=0;
  
 
  
 
 
  //TAU-ELECTRON

  float bkgEl=0.;
  float bkgMu=0.;
  float bkgTau=0.;
  float bkgErrEl=0.;
  float bkgErrMu=0.;
  float bkgErrTau=0.;


  for (int i=1; i<mxX+1; i++){
    for (int j=1; j<mxY+1; j++){
      float FR= TAU_FR->GetBinContent(i,j);
      float NormEl=GE_FT->GetBinContent(i,j);
      //      cout<<"FR "<<i<<" "<<j<<" "<<FR<<" "<<NormEl<<endl;
      float NormEl=GE_FT->GetBinContent(i,j);
      if (FR>0. && NormEl>0){
	float relErrFR=TAU_FR->GetBinError(i,j)/TAU_FR->GetBinContent(i,j);
	float relErrNorm=(NormEl>0) ? GE_FT->GetBinError(i,j)/GE_FT->GetBinContent(i,j):0.;
	float SqRelErr=(relErrFR*relErrFR)+(relErrNorm*relErrNorm);
	float num=FR*NormEl;
	bkgEl+=num; 
	if (NormEl>0) bkgErrEl+= (num*num*SqRelErr);
	else bkgErrEl+=TAU_FR->GetBinError(i,j)*TAU_FR->GetBinError(i,j) ;
      }

      float NormMu=GM_FT->GetBinContent(i,j);
      if (FR>0.){

	float relErrFR=TAU_FR->GetBinError(i,j)/TAU_FR->GetBinContent(i,j);
	float relErrNorm=(NormMu>0) ?GM_FT->GetBinError(i,j)/GM_FT->GetBinContent(i,j) : 0.;
	float SqRelErr=(relErrFR*relErrFR)+(relErrNorm*relErrNorm);
	//	cout<<"fr "<<relErrFR<<" norm "<<relErrNorm<<endl;
	float num=FR*NormMu;
	//	cout<<"("<<i<<","<<j<<") NORM "<<GM_FT->GetBinContent(i,j)<<"+-"<<GM_FT->GetBinError(i,j)<<" "<<TAU_FR->GetBinContent(i,j)<<" "<<TAU_FR->GetBinError(i,j)<<" "<<num<<endl;
	//	cout<<"ERR "<<SqRelErr<<" "<<num<<" "<<num*sqrt(SqRelErr)<<endl;
	bkgMu+=num; 
	if (NormMu>0) bkgErrMu+= (num*num*SqRelErr);
	else bkgErrMu+= TAU_FR->GetBinError(i,j)*TAU_FR->GetBinError(i,j);
	//	cout<<"BKG "<<bkgMu<<" "<<bkgErrMu<<endl;
      }
      
      float NormTau=GT_FT->GetBinContent(i,j);
      if (FR>0.){
	//	cout<<"NORM "<<NormTau<<" "<<FR<<endl;
	float relErrFR   = TAU_FR->GetBinError(i,j)/TAU_FR->GetBinContent(i,j);
	float relErrNorm = (NormTau>0) ?GT_FT->GetBinError(i,j)/GT_FT->GetBinContent(i,j):0.;
	float SqRelErr   = (relErrFR*relErrFR)+(relErrNorm*relErrNorm);
	//	cout<<"fr "<<FR<<" norm "<<NormTau<<endl;
	float num = FR*NormTau;
	//	cout<<"ERR "<<SqRelErr<<" "<<num<<" "<<num*sqrt(SqRelErr)<<endl;
	bkgTau += num; 
	if (NormTau>0) bkgErrTau += (num*num*SqRelErr);
	else bkgErrTau += (TAU_FR->GetBinError(i,j)*TAU_FR->GetBinError(i,j));
	//	cout<<"("<<i<<","<<j<<") NORM "<<GT_FT->GetBinContent(i,j)<<"+-"<<GT_FT->GetBinError(i,j)<<" FR "<<TAU_FR->GetBinContent(i,j)<<"+/-"<<TAU_FR->GetBinError(i,j)<<endl;
	// 	cout<<"BKG "<<bkgTau<<" "<<bkgErrTau<<endl;
      }     
    }
  }
  //  cout<<"dddddddd "<<bkgTau<<"+/-"<<sqrt(bkgErrTau)<<endl;
  



  cout<<"CHANNEL E-TAU"<<endl;
  cout<<" PREDICTED  "<<int(10000*bkgEl)/10000.<<"+/-"<<int(10000*sqrt(bkgErrEl))/10000.
      <<" OBSERVED "<<int(10000*obs->GetBinContent(5))/10000.<<"+/-"<<  int(10000*obs->GetBinError(5))/10000.<<endl;
  cout<<"CHANNEL MU-TAU"<<endl;
  cout<<" PREDICTED  "<<int(10000*bkgMu)/10000.<<"+/-"<<int(10000*sqrt(bkgErrMu))/10000.
      <<" OBSERVED "<<int(10000*obs->GetBinContent(6))/10000.<<"+/-"<<  int(10000*obs->GetBinError(6))/10000.<<endl;

  pre->SetBinContent(5,bkgEl);
  pre->SetBinError(5,sqrt(bkgErrEl));
  pre->SetBinContent(6,bkgMu);
  pre->SetBinError(6,sqrt(bkgErrMu));


  float bkgtautau=0.;
  float bkgtautauplus=0.;
  float bkgtautauminus=0.;
  float totEventsErr=0.;
  float totEvents=0.;
  Float_t         weight;
  Float_t         eta1;
  Float_t         pt1;
  Float_t         eta2;
  Float_t         pt2;
  TBranch        *b_weight;  
  TBranch        *b_eta1;
  TBranch        *b_pt1;
  TBranch        *b_eta2;
  TBranch        *b_pt2; 


  files[3]->cd(TAUNORM+"Tau");
  TTree *tree =(TTree*)gDirectory->Get("theTree");
  tree->SetBranchAddress("weight", &weight, &b_weight);
  tree->SetBranchAddress("eta1", &eta1, &b_eta1);
  tree->SetBranchAddress("pt1", &pt1, &b_pt1);
  tree->SetBranchAddress("eta2", &eta2, &b_eta2);
  tree->SetBranchAddress("pt2", &pt2, &b_pt2);
  Long64_t nentries = tree->GetEntriesFast();

  for (Long64_t jentry=0; jentry<tree->GetEntriesFast();jentry++) {
    tree->GetEntry(jentry);
    int ie1=int(fabs(eta1)/etawidth)+1;
    if (ie1>TAU_FR->GetNbinsX()) ie1=TAU_FR->GetNbinsX();
    int ie2=int(fabs(eta2)/etawidth)+1;
    if (ie2>TAU_FR->GetNbinsX()) ie2=TAU_FR->GetNbinsX();
    int ip1=int(pt1/ptwidth)+1;
    if (ip1>TAU_FR->GetNbinsY()) ip1=TAU_FR->GetNbinsY();
    int ip2=int(pt2/ptwidth)+1;
    if (ip2>TAU_FR->GetNbinsY()) ip2=TAU_FR->GetNbinsY();    
    //    cout<<"EVENTO "<<ie1<<" "<<ip1<<" "<<TAU_FR->GetBinContent(ie1,ip1)<<"  "<<ie2<<" "<<ip2<<TAU_FR->GetBinContent(ie2,ip2)<<" "<<TAU_FR->GetBinContent(ie1,ip1)*TAU_FR->GetBinContent(ie2,ip2)<<endl;
    totEventsErr+=weight*weight;
    totEvents+=weight;
    
    bkgtautau+=weight*TAU_FR->GetBinContent(ie1,ip1)*TAU_FR->GetBinContent(ie2,ip2);
       bkgtautauplus+=weight*
	 (TAU_FR->GetBinContent(ie1,ip1)+TAU_FR->GetBinError(ie1,ip1))*
	 (TAU_FR->GetBinContent(ie2,ip2)+TAU_FR->GetBinError(ie2,ip2));
       bkgtautauminus+=weight*
	 (TAU_FR->GetBinContent(ie1,ip1)-TAU_FR->GetBinError(ie1,ip1))*
	 (TAU_FR->GetBinContent(ie2,ip2)-TAU_FR->GetBinError(ie2,ip2)); 
  }


  float errDiff=fabs(bkgtautauplus-bkgtautau);
  if (errDiff<fabs(bkgtautauminus-bkgtautau)) errDiff=fabs(bkgtautauminus-bkgtautau);

 
 
  float errPP=(sqrt(totEventsErr)/totEvents)*bkgtautau;

  float TotErr=sqrt((errDiff*errDiff)+(errPP*errPP));
  //  cout<<"EEE "<<errDiff<<" "<<errPP<<" "<<TotErr<<endl;

  float ErrTotTau= (singleTau) ? sqrt(TotErr*TotErr+bkgErrTau) :TotErr;
  float TotBkgTau=(singleTau) ? bkgTau-bkgtautau : bkgtautau;
  //  cout<<"BBB "<<bkgTau<<endl;

  cout<<"CHANNEL TAU-TAU"<<endl;
  cout<<
    " PREDICTED "<<int(10000*(TotBkgTau))/10000.<<"+/-"<<int(10000*ErrTotTau)/10000. <<
    " OBSERVED "<<int(10000*obs->GetBinContent(3))/10000.<<"+/-"<<  int(10000*obs->GetBinError(3))/10000.<<endl;

  pre->SetBinContent(3,bkgtautau);
  pre->SetBinError(3,TotErr);



  cout<<"CONTRIBUTION FROM CHARGE MIS ID "<<endl;
  float rel_stat_err=TAUMisCharge_stat/TAUMisCharge;
  float rel_syst_err=TAUMisCharge_syst/TAUMisCharge;
  
  float tauelMC=N_OS_TAUEL*TAUMisCharge/(1-TAUMisCharge);
  float taumuMC=N_OS_TAUMU*TAUMisCharge/(1-TAUMisCharge);
 
  float tautauMC=N_OS_TAUTAU*2.*TAUMisCharge*(1-TAUMisCharge)/((1-TAUMisCharge)*(1-TAUMisCharge)+TAUMisCharge*TAUMisCharge);

  float tauelMCSystErr=rel_syst_err*tauelMC;
  float taumuMCSystErr=rel_syst_err*taumuMC;
  float tautauMCSystErr=rel_syst_err*tautauMC;
  
  float tauelMCErr= (N_OS_TAUEL>0) ? sqrt((rel_stat_err*rel_stat_err+1/N_OS_TAUEL))*tauelMC : rel_stat_err;
  float taumuMCErr= (N_OS_TAUMU>0) ? sqrt((rel_stat_err*rel_stat_err+1/N_OS_TAUMU))*taumuMC : rel_stat_err;
  float tautauMCErr= (N_OS_TAUTAU>0) ? sqrt((rel_stat_err*rel_stat_err+1/N_OS_TAUTAU))*tautauMC : rel_stat_err;

  //  float taumuMCErr= (N_OS_TAUMU>0) ? (rel_stat_err*rel_stat_err+1/N_OS_TAUMU)*taumuMC : rel_stat_err;
  //float tautauMCErr= (N_OS_TAUMU>0) ? (rel_stat_err*rel_stat_err+1/N_OS_TAUTAU)*tautauMC : rel_stat_err;

  cout<<"EL-TAU "<<tauelMC<<" +- "<<tauelMCErr<<" (stat) +/- "<<tauelMCSystErr<<" (syst)"<<endl;
  cout<<"MU-TAU "<<taumuMC<<" +- "<<taumuMCErr<<" (stat) +/- "<<taumuMCSystErr<<" (syst)"<<endl;
  cout<<"TAU-TAU "<<tautauMC<<" +- "<<tautauMCErr<<" (stat) +/- "<<tautauMCSystErr<<" (syst)"<<endl;
//   float tautauMC=N_OS_TAUTAU*2*TAUMisCharge;
//   float tautauMCErr=(0.4+1/N_OS_TAUTAU)*tautauMC;

  /////////////////////////////////////
    //pre->SetMinimum(0.00001);
    //  _file0->cd(SELE);
  TCanvas *c1=new TCanvas("c1","c1",100,100,900,900);
  TLegend *tl= new TLegend(0.8,0.8,0.9,0.9);
  pre->SetTitle(HT);
  pre->GetYaxis()->SetTitle("Events per channel");

  obs->SetMarkerStyle(21);
  pre->SetMarkerColor(2);
  pre->SetLineColor(2);
  pre->SetMarkerStyle(23);

  //if(Log) c1->GetPad(0).SetLogy();
  
  pre->Draw("pe");
  obs->Draw("pesame");
  tl->AddEntry(obs,"Observed","p");
  tl->AddEntry(pre,"Expected","p");
  tl->Draw();
  
  
}
