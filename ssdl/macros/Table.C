{
  TString DIR ="DiLepSelec";
  float qcd[6];
  float dib[6];
  float wz[6];
  float tt[6];
  float lm0[6];



  string hh[6]={"e-e","mu-mu","tau-tau","e-mu","e-tau","mu-tau"};
  //  TCanvas c1;
  //  c1.cd();
  //SIGNAL
  TFile *_file0 = TFile::Open("QCD.root");
  _file0->cd(DIR);
  qcd[0]=h_nl_A_0->Integral();   qcd[1]=h_nl_A_1->Integral();   qcd[2]=h_nl_A_2->Integral();
  qcd[3]=h_nl_A_3->Integral();   qcd[4]=h_nl_A_4->Integral();   qcd[5]=h_nl_A_5->Integral();

  //  //TT
  TFile *_file1 = TFile::Open("TT.root");
  _file1->cd(DIR);
  tt[0]=h_nl_A_0->Integral();   tt[1]=h_nl_A_1->Integral();   tt[2]=h_nl_A_2->Integral();
  tt[3]=h_nl_A_3->Integral();   tt[4]=h_nl_A_4->Integral();   tt[5]=h_nl_A_5->Integral();

  //DIB
  TFile *_file2 = TFile::Open("Dib.root");
  _file2->cd(DIR);
  dib[0]=h_nl_A_0->Integral();   dib[1]=h_nl_A_1->Integral();   dib[2]=h_nl_A_2->Integral();
  dib[3]=h_nl_A_3->Integral();   dib[4]=h_nl_A_4->Integral();   dib[5]=h_nl_A_5->Integral();

//   //LM0
//   TFile *_file3 = TFile::Open("LM0.root");
//   _file3->cd(DIR);
//   lm0[0]=h_nl_A_0->Integral();   lm0[1]=h_nl_A_1->Integral();   lm0[2]=h_nl_A_2->Integral();
//   lm0[3]=h_nl_A_3->Integral();   lm0[4]=h_nl_A_4->Integral();   lm0[5]=h_nl_A_5->Integral();

  //BkgLM0
  TFile *_file3 = TFile::Open("lm0.root");
  _file3->cd(DIR);
  lm0[0]=h_nl_A_0->Integral();   lm0[1]=h_nl_A_1->Integral();   lm0[2]=h_nl_A_2->Integral();
  lm0[3]=h_nl_A_3->Integral();   lm0[4]=h_nl_A_4->Integral();   lm0[5]=h_nl_A_5->Integral();


  //BkgLM1
  TFile *_file3 = TFile::Open("WZ.root");
  _file3->cd(DIR);
  wz[0]=h_nl_A_0->Integral();   wz[1]=h_nl_A_1->Integral();   wz[2]=h_nl_A_2->Integral();
  wz[3]=h_nl_A_3->Integral();   wz[4]=h_nl_A_4->Integral();   wz[5]=h_nl_A_5->Integral();
  

  for (int y=0; y<6;y++){
 

    cout<<"FINAL STATE "<<hh[y]<<endl
	<<" susy          = "<<lm0[y]<< endl
	<<" background  = "<<qcd[y]+tt[y]+dib[y]+wz[y]<<endl
	<<" qcd       = "<<qcd[y]<<endl
	<<" tt       = "<<tt[y]<<endl
	<<" dib       = "<<dib[y]<<endl
	<<" W/Z       = "<<wz[y]<<endl
	<<endl<<endl;    
  }
}
