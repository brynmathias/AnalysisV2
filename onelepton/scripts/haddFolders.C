void mainFunction(TString type = "/") {


  TString path = "/vols/cms01/gouskos/20120127_El_HTbins_STbins_Sel"+type;
  TString fname_qcd  = path+"qcd.root";
  TString fname_z    = path+"z.root";
  TString fname_w    = path+"w.root";
  TString fname_tt   = path+"tt.root";
  TString fname_ewk  = path+"ewk.root";
  TString fname_sm   = path+"sm.root";
  TString fname_data = path+"data.root";
  

  
  // -- initial root file to merge
  if (type == "/") {
    TFile *f_initQCD  = TFile::Open(fname_qcd,"READONLY");
    TFile *f_initZ    = TFile::Open(fname_z,"READONLY");
    TFile *f_initW    = TFile::Open(fname_w,"READONLY");
    TFile *f_initTT   = TFile::Open(fname_tt,"READONLY");
    TFile *f_initEWK  = TFile::Open(fname_ewk,"READONLY");
    TFile *f_initSM   = TFile::Open(fname_sm,"READONLY");
    TFile *f_initDATA = TFile::Open(fname_data,"READONLY");
  }
  else {
    TFile *f_initZ    = TFile::Open(fname_z,"READONLY");
    TFile *f_initW    = TFile::Open(fname_w,"READONLY");
    TFile *f_initTT   = TFile::Open(fname_tt,"READONLY");
    TFile *f_initEWK  = TFile::Open(fname_ewk,"READONLY");
  }

  // -- output .root name
  TString f_outPath = "./20120127_El_HT750t_STbins_Sel"+type;
  
  if (type == "/") {
    makeFiles(f_initQCD,f_outPath+"qcd.root");
    makeFiles(f_initZ,f_outPath+"z.root");
    makeFiles(f_initW,f_outPath+"w.root");
    makeFiles(f_initTT,f_outPath+"tt.root");
    makeFiles(f_initEWK,f_outPath+"ewk.root");
    makeFiles(f_initSM,f_outPath+"sm.root");
    makeFiles(f_initDATA,f_outPath+"data.root");
  }
  else {
    makeFiles(f_initZ,f_outPath+"z.root");
    makeFiles(f_initW,f_outPath+"w.root");
    makeFiles(f_initTT,f_outPath+"tt.root");
    makeFiles(f_initEWK,f_outPath+"ewk.root");
  }
    
}




void makeFiles(TFile *f_init, TString f_out) {

  TH1::SetDefaultSumw2();

  // --- hadd histograms
  TString ST150 = "150";
  TString ST250 = "250";
  TString ST350 = "350";
  TString ST450 = "450";


  // -- vector to hold the HT bins to merge 
  vector<TString> HT; HT.push_back("750"); HT.push_back("1000");


  // -- name of the histogram to merge
  TString histo2merge = "LPf_tot";


  // --- output [merged] histograms
  TH1D *hST150 = haddHistos(f_init,histo2merge,ST150,HT); hST150->SetName("hST150");
  TH1D *hST250 = haddHistos(f_init,histo2merge,ST250,HT); hST250->SetName("hST250");
  TH1D *hST350 = haddHistos(f_init,histo2merge,ST350,HT); hST350->SetName("hST350");
  TH1D *hST450 = haddHistos(f_init,histo2merge,ST450,HT); hST450->SetName("hST450");


  // --- save histograms in a root file. 
  TFile *hData = createRootFile(f_out,"150","750",hST150,histo2merge);
  TFile *hData = createRootFile(f_out,"250","750",hST250,histo2merge);  
  TFile *hData = createRootFile(f_out,"350","750",hST350,histo2merge);
  TFile *hData = createRootFile(f_out,"450","750",hST450,histo2merge);



}




TFile *createRootFile(TString fileName,TString STlepCut,TString HTCut,TH1D *hIn,TString histoName)  {

  TH1::SetDefaultSumw2();

  TFile *fout = new TFile(fileName,"UPDATE");
  fout->mkdir("ANplots"+STlepCut+"_NOLPsecondD"+HTCut);
  fout->ls(); 
  fout->cd("ANplots"+STlepCut+"_NOLPsecondD"+HTCut);
  fout->pwd();

  TH1D *hOut = (TH1D*)hIn->Clone(histoName); hOut->SetName(histoName);
  hOut->Write(histoName);
  fout->Close();

  return fout;
}


TH1D *haddHistos(TFile *fileName,TString histoName,vector<TString> ST,vector<TString> HT) {

  TH1::SetDefaultSumw2();

  TH1D *hInit = (TH1D*)fileName->Get("ANplots"+ST[0]+"_NOLPsecondD"+HT[0]+"/"+histoName); hInit->SetName(histoName);

  // ---- loop over all the STbins
  for (int iST=0; iST<ST.size(); iST++) {

    if (ST.size()>1) {
      TH1D *hTempST = (TH1D*)fileName->Get("ANplots"+ST[iST]+"_NOLPsecondD"+HT[iHT]+"/"+histoName);
      hInit->Add(hInit,hTempST,1.,1.);
    }

    // ---- loop over all the STbins
    for (int iHT=0; iHT<HT.size(); iHT++) {

      if (HT.size()>1) {
	TH1D *hTempHT = (TH1D*)fileName->Get("ANplots"+ST[iST]+"_NOLPsecondD"+HT[iHT]+"/"+histoName);
	hInit->Add(hInit,hTempHT,1.,1.);
      }
      
    } // --- end of looping over HTbins

  } // --- end of looping over STbins


  return hInit;
}



TH1D *haddHistos(TFile *fileName,TString histoName,TString ST,vector<TString> HT) {
  
  TH1::SetDefaultSumw2();

  fileName->ls();

  TH1D *hInit = (TH1D*)fileName->Get("ANplots"+ST+"_NOLPsecondD"+HT[0]+"/"+histoName); hInit->SetName(histoName);
  cout << "IN-1" << "\n";
  // ---- loop over all the STbins
  for (int iHT=0; iHT<HT.size(); iHT++) {
    cout << "iHT " << iHT << "\n";
    if ((HT.size()>1) && (iHT>0)) {
      TH1D *hTempHT = (TH1D*)fileName->Get("ANplots"+ST+"_NOLPsecondD"+HT[iHT]+"/"+histoName);
      hInit->Add(hInit,hTempHT,1.,1.);
    }
    
  } // --- end of looping over HTbins

  
  return hInit;
}
