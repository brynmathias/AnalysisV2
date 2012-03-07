//ostringstream ostream;
//ofstream filestream;

Syst(bool Ht500 = true)
{
  cout.setf(ios::fixed,ios::floatfield);
  cout.precision(0);
  if(Ht500)
    {
      TString HT("500");
      float RCss[4];
      float RCerror[4];
      TString BKG("resultsPythia/zttw.root");
      float RCssref[4];
      TString BKGref("resultsPythia/BKGrefsyst.root");


      float dataStat[4];
      TString data("results/data.root");

      vector <TString> STbins;
      STbins.push_back(TString("150"));
      STbins.push_back(TString("250"));
      STbins.push_back(TString("350"));
      STbins.push_back(TString("450"));
      TString SystMetup("resultsSystREFSkim_metup/BKG.root");
      float Metup[4];
      TString SystMetdown("resultsSystREFSkim_metdown/BKG.root");
      float Metdown[4];
      float Metaverage[4];
      TString SystMetres("resultsSystREFSkim_metres_conservative/BKG.root");
      float Metres[4];
      TString SystPoldown("resultsSystREFSkim_polup/BKG.root");
      float Poldown[4];
      TString SystPolup("resultsSystREFSkim_poldown/BKG.root");
      float Polup[4];
      TString SystPoldownneg("resultsSystREFSkim_polup_plus/BKG.root");
      float Poldownneg[4];
      TString SystPoluppos("resultsSystREFSkim_poldown_plus/BKG.root");
      float Poluppos[4];
      float polMax[4];

      float w30[4];
      float tt10[4];
      TString w30S("resultsPythia/w.root");
      TString tt30S("resultsPythia/tt.root");

      for (int i=0;i<4;i++)
	{
	  dataStat[i] = RCSdatstat(data,STbins[i],HT);
	  RCss[i]  = RCS(BKG,STbins[i],HT);
	  RCerror[i]  = RCSerr(BKG,STbins[i],HT);
	  RCssref[i]  = RCS(BKGref,STbins[i],HT);
	  //cout << i << " Rcs  "<<RCss[i]<<endl;
	  Metup[i]  = RelativeError(RCS(SystMetup,STbins[i],HT), RCssref[i]);
	  Metdown[i]  = RelativeError(RCS(SystMetdown,STbins[i],HT), RCssref[i]);
	  Metres[i]  = RelativeError(RCS(SystMetres,STbins[i],HT), RCssref[i]);
	  Poldown[i]  = RelativeError(RCS(SystPoldown,STbins[i],HT), RCssref[i]);
	  Polup[i]  = RelativeError(RCS(SystPolup,STbins[i],HT), RCssref[i]);
	  Poldownneg[i]  = RelativeError(RCS(	SystPoldownneg	,STbins[i],HT), RCssref[i]);   
	  Poluppos[i]  = RelativeError(RCS(SystPoluppos	,STbins[i],HT), RCssref[i]);   
	  cout << "Pols: " << RelativeError(RCS(SystPoluppos	,STbins[i],HT), RCssref[i])<< " "<<RelativeError(RCS(	SystPoldownneg	,STbins[i],HT), RCssref[i]) << " "<< RelativeError(RCS(SystPolup,STbins[i],HT), RCssref[i]) << " "<< RelativeError(RCS(SystPoldown,STbins[i],HT), RCssref[i])  << endl;
	  //cout << "test"<<Metup[i]<< " "<< Metdown[i]<<endl;
	  Metaverage[i] = (fabs(Metup[i])+fabs(Metdown[i]))/2.;
	  if(fabs(RelativeError(RCSttw(w30S,tt30S,true,.1,STbins[i],HT), RCssref[i]))>fabs(RelativeError(RCSttw(w30S,tt30S,true,-.1,STbins[i],HT), RCssref[i]))) w30[i] = fabs(RelativeError(RCSttw(w30S,tt30S,true,.1,STbins[i],HT), RCssref[i]));
	  else {w30[i] = fabs(RelativeError(RCSttw(w30S,tt30S,true,-.1,STbins[i],HT), RCssref[i]));}
	  if(fabs( RelativeError(RCSttw(w30S,tt30S,false,.3,STbins[i],HT), RCssref[i]) ) > fabs(  RelativeError(RCSttw(w30S,tt30S,false,-.3,STbins[i],HT), RCssref[i]) )) tt10[i] = fabs( RelativeError(RCSttw(w30S,tt30S,false,.3,STbins[i],HT), RCssref[i]) );
	  else tt10[i] = fabs( RelativeError(RCSttw(w30S,tt30S,false,-.3,STbins[i],HT), RCssref[i]) );

      //cout <<"w 10 " << RelativeError(RCSttw(w30S,tt30S,true,.1,STbins[i],HT), RCssref[i]) << endl;
	  cout << RelativeError(RCSttw(w30S,tt30S,false,.3,STbins[i],HT), RCssref[i]) << endl;
	  cout <<"w -10 " << RelativeError(RCSttw(w30S,tt30S,true,-.1,STbins[i],HT), RCssref[i]) << endl;
	  cout << RelativeError(RCSttw(w30S,tt30S,false,-.3,STbins[i],HT), RCssref[i]) << endl;
	  if(fabs(Poldown[i])>= fabs(Polup[i])) polMax[i]=fabs(Poldown[i]);
	  else polMax[i]=fabs(Polup[i]);
	  if(polMax[i]<fabs(Poldownneg[i]))polMax[i]= fabs(Poldownneg[i]);
	  if(polMax[i]<fabs(Poluppos[i]))polMax[i]= fabs(Poluppos[i]);


	}

      cout <<"Bin & 150 - 250 &250 - 350 & 350 - 450 &  $>$ 450 /\/\ /\hline"<<endl;
      cout <<"$R_{CS}$ &"<<100*RCss[0]<< "&"<<100*RCss[1]<< "&" <<100*RCss[2]<< "&"<<100*RCss[3]<< "/\/\ /\hline"<<endl;
      // ostream.precision(0);
      cout <<"/\hspace{0.5cm}Control Region Stat. (/\%) &"<< dataStat[0]<< "&"<<dataStat[1]<< "&" <<dataStat[2]<< "&"<<dataStat[3]<< "/\/\ /\hline"<<endl;
      cout <<"/\hspace{0.5cm} MC stat. & "<< RCerror[0]<< "&" << RCerror[1]<< "&" << RCerror[2]<< "&" << RCerror[3]<<  "/\/\ /\hline"<<endl; 
  
      cout <<"/\hspace{0.5cm}  x-sec W & "<< w30[0]<< "&" << w30[1]<< "&" << w30[2]<< "&" << w30[3]<<  "\\ \\ "<<endl; 
      cout <<"/\hspace{0.5cm}  x-sec tt & "<< tt10[0]<< "&" << tt10[1]<< "&" << tt10[2]<< "&" << tt10[3]<<  "\\ \\"<<endl; 

      cout <<"/\hspace{0.5cm}JES Uncertainty up(\%) &"<<Metup[0]<< "&" << Metup[1]<< "&" << Metup[2]<< "&" << Metup[3]<<  "/\/\ /\hline"<<endl; 
      cout <<"/\hspace{0.5cm}JES Uncertainty down(\%) &"<<Metdown[0]<< "&" << Metdown[1]<< "&" << Metdown[2]<< "&" << Metdown[3]<<  "/\/\ /\hline"<<endl; 
      cout <<"/\hspace{0.5cm}JES Uncertainty (\%) &"<<Metaverage[0]<< "&" << Metaverage[1]<< "&" << Metaverage[2]<< "&" << Metaverage[3]<<  "/\/\ /\hline"<<endl; 
      cout <<"/\hspace{0.5cm}MET Resolution (10\%) (\%) &"<<Metres[0]<< "&" <<Metres[1]<< "&" << Metres[2]<< "&" << Metres[3]<<  "/\/\ /\hline"<<endl; 
      cout <<"/\hspace{0.5cm}W Polarization (\%) &"<<polMax[0]<< "&" << polMax[1]<< "&" << polMax[2]<< "&" << polMax[3]<<  "/\/\ /\hline"<<endl; 
  
      //float RCS(TString name,TString ST,TString HT)
    }
}
  float RelativeError(float syst, float ref)
  {
    return(100.*(ref-syst)/ref) ;

  }

  SystHist()
    {
      TH1D* syst150 = new TH1D("syst1","ST150;syst [%];",200,-10,10);
      TH1D* syst250 = new TH1D("syst2","ST250;syst [%];",200,-10,10);
      TH1D* syst350 = new TH1D("syst3","ST350;syst [%];",200,-10,10);
      TH1D* syst450 = new TH1D("syst4","ST450;syst [%];",200,-10,10);
      TCanvas* HT500can = new TCanvas("HT500can");
      HT500can->Divide(4);

      TString myST("150");
      FillHist(syst150,myST,TString("1000"));
      HT500can->cd(1);
      syst150->Draw();
      FillHist(syst250,TString("250"),TString("1000"));
      HT500can->cd(2);
      syst250->Draw();
      FillHist(syst350,TString("350"),TString("1000"));
      HT500can->cd(3);
      syst350->Draw();
      FillHist(syst450,TString("450"),TString("1000"));
      HT500can->cd(4);
      syst450->Draw();
    }

  void FillHist(TH1D* syst,TString ST,TString HT)
  {
    //  float RCS_ref = RCS(TString("resultsFall11Skim_test0/BKG.root"),ST,HT);
    // TString name("resultsFall11Skim_test_mupt");
    float RCS_ref = RCS(TString("resultsFall11Skim_HT0/BKG.root"),ST,HT);
    TString name("resultsFall11Skim_HT_mupt");
    for(int i=0;i<10;i++) 
      {
	char text[11];
	sprintf(text, "%d", i);
	TString aname(name);
	aname.Append(text);
	aname.Append("/BKG.root");
	float RCS_cur =  RCS(aname,ST,HT);
	syst->Fill(100.*(RCS_cur-RCS_ref)/RCS_ref);
      }
  }


  float RCS(TString name,TString ST,TString HT)
  {
    TFile* cur = new TFile(name);
    //cur->ls();

    TH1D* contr = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterCtrl_tot");
    TH1D* sig = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterSgnl_tot");

    //  cout << sig->GetBinContent(1) << " "<< contr->GetBinContent(1)<<endl;
    return sig->GetBinContent(1)/contr->GetBinContent(1);
  }


float RCSttw(TString namew,TString namett,bool w, float size,TString ST,TString HT)
  {
    TFile* cur = new TFile(namew);
    TH1D* contr = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterCtrl_tot");
    TH1D* sig = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterSgnl_tot");
    float RCSW = sig->GetBinContent(1)/contr->GetBinContent(1);
    float amplW = contr->GetBinContent(1);


    TFile* curtt = new TFile(namett);
    TH1D* contrtt = (TH1D*)curtt->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterCtrl_tot");
    TH1D* sigtt = (TH1D*)curtt->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterSgnl_tot");
    float RCStt = sigtt->GetBinContent(1)/contrtt->GetBinContent(1);
    float ampltt = contrtt->GetBinContent(1);

    //  cout << " RCStt :" <<  RCStt << " "<< RCSW<<endl;
    // cout << amplW/(amplW+ampltt) << " fW "<<amplW <<"/"<<(amplW+ampltt)<< " tt amp " << ampltt<<  " " <<ampltt/(amplW+ampltt)<<endl;
    // cout << "old " <<amplW/(amplW+ampltt)*RCSW+ampltt/(amplW+ampltt)*RCStt<<endl;

   if(w) {
      amplW = amplW*(1+size);
      //   cout << "new " <<(amplW/(amplW+ampltt)*RCSW+ampltt/(amplW+ampltt)*RCStt)<<endl;
      //  cout << amplW/(amplW+ampltt) << " fW"<<amplW<<"/"<<(amplW+ampltt)<< " tt amp " << ampltt<<  " " <<ampltt/(amplW+ampltt)<<endl;

      return (amplW/(amplW+ampltt)*RCSW+ampltt/(amplW+ampltt)*RCStt);
    }
    else{
      ampltt= ampltt*(1+size);
      //  cout << "new " <<(amplW/(amplW+ampltt)*RCSW+ampltt/(amplW+ampltt)*RCStt)<<endl;;
      //  cout << amplW/(amplW+ampltt) << " fW"<<amplW<<endl;
      return (amplW/(amplW+ampltt)*RCSW+ampltt/(amplW+ampltt)*RCStt);
    }

  }



  float RCSerr(TString name,TString ST,TString HT)
  {
    TFile* cur = new TFile(name);
    //cur->ls();
    TH1D* contr = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterCtrl_tot");
    TH1D* sig = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterSgnl_tot");
    cout << sig->GetBinError(1)/sig->GetBinContent(1)  << " "<< contr->GetBinError(1)/contr->GetBinContent(1)  <<" "<<sqrt(contr->GetBinContent(1))/contr->GetBinContent(1)<<endl;
    return 100* sqrt( sig->GetBinError(1)/sig->GetBinContent(1) * sig->GetBinError(1)/sig->GetBinContent(1) + contr->GetBinError(1)/contr->GetBinContent(1)  * contr->GetBinError(1)/contr->GetBinContent(1));
  }

  float RCSdatstat(TString name,TString ST,TString HT)
  {
    TFile* cur = new TFile(name);
    //cur->ls();

    TH1D* contr = (TH1D*)cur->Get("ANplots"+ST+"_NOLPsecondD"+HT+"/CounterCtrl_tot");
    return 100*(sqrt(contr->GetBinContent(1))/contr->GetBinContent(1));

  }
