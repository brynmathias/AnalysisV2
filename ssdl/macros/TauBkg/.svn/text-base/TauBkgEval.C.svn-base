{
  gStyle->SetTextSize(18);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleFontSize(0.04);
  gStyle->SetTitleStyle(00);
  gStyle->SetStatBorderSize(1);
  gStyle->SetStatColor(0);
  gStyle->SetOptStat(110);
  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadColor(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetFrameLineWidth(2);
  gStyle->SetFillColor(0);
  gStyle->SetHistLineWidth(2);
  gStyle->SetLineWidth(2);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(2);
  gStyle->SetLabelSize(0.073);
  gStyle->SetOptStat(0);
  gROOT->ForceStyle();
  
  //ISTOGRAMMI
  vector<TString> HTs;
  HTs.push_back(" HT<50       ");   HTs.push_back(" 50<HT<100   ");  HTs.push_back(" 100<HT<200  ");
  HTs.push_back(" 200<HT<350  ");  HTs.push_back(" 350<HT<600  ");   HTs.push_back(" HT>600      ");
  TH1F *lep_j =new TH1F("lepton ratio","(Tau + Lepton) / SingleTau vs HT",4, 0,4);
  lep_j->GetXaxis()->SetBinLabel(1,HTs[2]);  lep_j->GetXaxis()->SetBinLabel(2,HTs[3]);
  lep_j->GetXaxis()->SetBinLabel(3,HTs[4]);  lep_j->GetXaxis()->SetBinLabel(4,HTs[5]);
  TH1F *cont_j =new TH1F("signal","signal contamination for single tau (single jet trigger)",4, 0,4);
  cont_j->GetXaxis()->SetBinLabel(1,HTs[2]);  cont_j->GetXaxis()->SetBinLabel(2,HTs[3]);
  cont_j->GetXaxis()->SetBinLabel(3,HTs[4]);  cont_j->GetXaxis()->SetBinLabel(4,HTs[5]);
  
  TH1F *cont_ssdl_j =new TH1F("signal2",
			      "signal contamination for tau + lepton (single jet trigger)",4, 0,4);
  cont_ssdl_j->GetXaxis()->SetBinLabel(1,HTs[2]);  cont_ssdl_j->GetXaxis()->SetBinLabel(2,HTs[3]);
  cont_ssdl_j->GetXaxis()->SetBinLabel(3,HTs[4]);  cont_ssdl_j->GetXaxis()->SetBinLabel(4,HTs[5]);
  
  TH1F *cont_m =new TH1F("signal3","signal contamination for single tau (met trigger)",4, 0,4);
  cont_m->GetXaxis()->SetBinLabel(1,HTs[2]);  cont_m->GetXaxis()->SetBinLabel(2,HTs[3]);
  cont_m->GetXaxis()->SetBinLabel(3,HTs[4]);  cont_m->GetXaxis()->SetBinLabel(4,HTs[5]);
  
  TH1F *cont_ssdl_m =new TH1F("signal4","signal contamination for tau + lepton (met trigger)",4, 0,4);
  cont_ssdl_m->GetXaxis()->SetBinLabel(1,HTs[2]);  cont_ssdl_m->GetXaxis()->SetBinLabel(2,HTs[3]);
  cont_ssdl_m->GetXaxis()->SetBinLabel(3,HTs[4]);  cont_ssdl_m->GetXaxis()->SetBinLabel(4,HTs[5]);  


  float rationum[4],ratioden[4],errrationum[4], errratioden[4];
  float cont_ssdl_mnum[4],cont_ssdl_mden[4],errcont_ssdl_mnum[4], errcont_ssdl_mden[4];
  float cont_ssdl_jnum[4],cont_ssdl_jden[4],errcont_ssdl_jnum[4], errcont_ssdl_jden[4];
  float cont_tau_mnum[4],cont_tau_mden[4],errcont_tau_mnum[4], errcont_tau_mden[4];
  float cont_tau_jnum[4],cont_tau_jden[4],errcont_tau_jnum[4], errcont_tau_jden[4];
  for (int ib=0;ib<4;ib++){
    rationum[ib]=0;ratioden[ib]=0;errrationum[ib]=0; errratioden[ib]=0;
    cont_ssdl_mnum[ib]=0;cont_ssdl_mden[ib]=0;errcont_ssdl_mnum[ib]=0; errcont_ssdl_mden[ib]=0;
    cont_ssdl_jnum[ib]=0;cont_ssdl_jden[ib]=0;errcont_ssdl_jnum[ib]=0; errcont_ssdl_jden[ib]=0;
    cont_tau_mnum[ib]=0;cont_tau_mden[ib]=0;errcont_tau_mnum[ib]=0; errcont_tau_mden[ib]=0;
    cont_tau_jnum[ib]=0;cont_tau_jden[ib]=0;errcont_tau_jnum[ib]=0; errcont_tau_jden[ib]=0;
  }



  //file
  
  TString DIR ="DiLepSelec";
  TFile* met[15];
  TFile* sj[15];
  TFile* sigmet=new TFile("contagli/lm0.root");   
  TFile* sigjet=new TFile("singlejet/contagli/lm0.root"); 

  //MET
  met[0]= new TFile("contagli/q80.root"); 
  met[1]= new TFile("contagli/q170.root");   
  met[2]= new TFile("contagli/q300.root");
  met[3]= new TFile("contagli/q470.root");   
  met[4]= new TFile("contagli/q800.root");
  met[5]= new TFile("contagli/q1400.root");   
  met[6]= new TFile("contagli/q2200.root");
  met[7]= new TFile("contagli/q3000.root");
  met[13]= new TFile("contagli/wjets.root");
  met[9]= new TFile("contagli/ww.root");
  met[10]= new TFile("contagli/tt.root");
  met[11]= new TFile("contagli/wz.root");
  met[12]= new TFile("contagli/zz.root");
  met[8]= new TFile("contagli/zjets.root");


 //Single jet
  
  sj[0]= new TFile("singlejet/contagli/q80.root"); 
  sj[1]= new TFile("singlejet/contagli/q170.root");   
  sj[2]= new TFile("singlejet/contagli/q300.root");
  sj[3]= new TFile("singlejet/contagli/q470.root");   
  sj[4]= new TFile("singlejet/contagli/q800.root");
  sj[5]= new TFile("singlejet/contagli/q1400.root");   
  sj[6]= new TFile("singlejet/contagli/q2200.root");
  sj[7]= new TFile("singlejet/contagli/q3000.root");
  sj[13]= new TFile("singlejet/contagli/wjets.root");
  sj[9]= new TFile("singlejet/contagli/ww.root");
  sj[10]= new TFile("singlejet/contagli/tt.root");
  sj[11]= new TFile("singlejet/contagli/wz.root");
  sj[12]= new TFile("singlejet/contagli/zz.root");
  sj[8]= new TFile("singlejet/contagli/zjets.root");



   // TOGETHER
  

   float SL_M_L=0,DL_M_H=0,SL_J_L=0,SL_J_H=0,DL_J_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_J_L=0,err_SL_J_H=0,err_DL_J_L=0;
   
   float SL_M_T=0,DL_M_T=0,SL_J_T=0,DL_J_T=0;
   float err_SL_M_T=0,err_DL_M_T=0,err_SL_J_T=0,err_DL_J_T=0;
   
   
   for (int if=0; if<14; if++){
     met[if].cd(DIR);

     ////histo
     for (int icont=3; icont<7;icont++){
      cont_tau_mden[icont-3]+=h_ht_sl->GetBinContent(icont,3);
      errcont_tau_mden[icont-3]+=h_ht_sl->GetBinContent(icont,3)*h_Charge->Integral()/h_Charge->GetEntries();

      cont_ssdl_mden[icont-3]+=h_ht_dl->GetBinContent(icont,3)+
	h_ht_dl->GetBinContent(icont,5)+
	h_ht_dl->GetBinContent(icont,6);
      errcont_ssdl_mden[icont-3]+=(h_ht_dl->GetBinContent(icont,3)+
				   h_ht_dl->GetBinContent(icont,5)+
				   h_ht_dl->GetBinContent(icont,6))*
	h_Charge->Integral()/h_Charge->GetEntries();
      
    }
    //////////////////////////////
     float priv_SL_M_T=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3)
       +h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_M_T= priv_SL_M_T*h_Charge->Integral()/h_Charge->GetEntries();    

     float priv_DL_M_T=
       h_ht_dl->GetBinContent(3,3)+h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(3,6)+
       h_ht_dl->GetBinContent(4,3)+ h_ht_dl->GetBinContent(4,5)+ h_ht_dl->GetBinContent(4,6)+
       h_ht_dl->GetBinContent(5,3)+h_ht_dl->GetBinContent(5,5)+ h_ht_dl->GetBinContent(5,6)+
       h_ht_dl->GetBinContent(6,3)+ h_ht_dl->GetBinContent(6,5)+ h_ht_dl->GetBinContent(6,6);
     float priverr_DL_M_T= priv_DL_M_T*h_ht_dl->Integral()/h_Charge->GetEntries();
     ///////////////////////////


    float priv_SL_M_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
    float priverr_SL_M_L= priv_SL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
 
    float priv_DL_M_H=
      h_ht_dl->GetBinContent(5,3)+ h_ht_dl->GetBinContent(5,5)+ h_ht_dl->GetBinContent(5,6)+
      h_ht_dl->GetBinContent(6,3)+ h_ht_dl->GetBinContent(6,5)+ h_ht_dl->GetBinContent(6,6);
    float priverr_DL_M_H= priv_DL_M_H*h_ht_dl->Integral()/h_Charge->GetEntries();
    
    SL_M_L+=priv_SL_M_L;
    err_SL_M_L+=priverr_SL_M_L; 
    DL_M_H+=priv_DL_M_H;
    err_DL_M_H+=priverr_DL_M_H; 
    
    SL_M_T+=priv_SL_M_T;
    err_SL_M_T+=priverr_SL_M_T; 
    DL_M_T+=priv_DL_M_T;
    err_DL_M_T+=priverr_DL_M_T; 


    sj[if].cd(DIR);

    //////////////////////////////
    float priv_SL_J_T=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3)
      +h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
    float priverr_SL_J_T= priv_SL_J_T*h_Charge->Integral()/h_Charge->GetEntries();    
    
    float priv_DL_J_T=
      h_ht_dl->GetBinContent(3,3)+h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(3,6)+
      h_ht_dl->GetBinContent(4,3)+ h_ht_dl->GetBinContent(4,5)+ h_ht_dl->GetBinContent(4,6)+
      h_ht_dl->GetBinContent(5,3)+h_ht_dl->GetBinContent(5,5)+ h_ht_dl->GetBinContent(5,6)+
      h_ht_dl->GetBinContent(6,3)+ h_ht_dl->GetBinContent(6,5)+ h_ht_dl->GetBinContent(6,6);
    float priverr_DL_J_T= priv_DL_J_T*h_ht_dl->Integral()/h_Charge->GetEntries();
    //per histo
    for (int icont=3; icont<7;icont++){
      cont_tau_jden[icont-3]+=h_ht_sl->GetBinContent(icont,3);
      errcont_tau_jden[icont-3]+=h_ht_sl->GetBinContent(icont,3)*h_Charge->Integral()/h_Charge->GetEntries();

      cont_ssdl_jden[icont-3]+=h_ht_dl->GetBinContent(icont,3)+
	h_ht_dl->GetBinContent(icont,5)+
	h_ht_dl->GetBinContent(icont,6);
      errcont_ssdl_jden[icont-3]+=(h_ht_dl->GetBinContent(icont,3)+
				   h_ht_dl->GetBinContent(icont,5)+
				   h_ht_dl->GetBinContent(icont,6))*
	h_Charge->Integral()/h_Charge->GetEntries();
      
     
    }
    ///////////////////////////


    float priv_SL_J_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
    float priverr_SL_J_L= priv_SL_J_L*h_Charge->Integral()/h_Charge->GetEntries();
    
    float priv_SL_J_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
    float priverr_SL_J_H= priv_SL_J_H*h_Charge->Integral()/h_Charge->GetEntries();
    
    float priv_DL_J_L=
      h_ht_dl->GetBinContent(3,3)+ h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(3,6)+
      h_ht_dl->GetBinContent(4,3)+ h_ht_dl->GetBinContent(4,5)+ h_ht_dl->GetBinContent(4,6);
    float priverr_DL_J_L= priv_DL_J_L*h_ht_dl->Integral()/h_Charge->GetEntries();
    
    SL_J_L+=priv_SL_J_L;
    SL_J_H+=priv_SL_J_H;
    DL_J_L+=priv_DL_J_L;
    
    err_SL_J_L+=priverr_SL_J_L;
    err_SL_J_H+=priverr_SL_J_H;
    err_DL_J_L+=priverr_DL_J_L;
    

    SL_J_T+=priv_SL_J_T;
    err_SL_J_T+=priverr_SL_J_T; 
    DL_J_T+=priv_DL_J_T;
    err_DL_J_T+=priverr_DL_J_T; 


    //    cout<<"FF "<<priv_DL_M_H<<" "<<priverr_DL_M_H<<endl;
   }
   //histo
   sigjet->cd(DIR);
   for (int icont=3; icont<7;icont++){
     cont_tau_jnum[icont-3]+=h_ht_sl->GetBinContent(icont,3);
     errcont_tau_jnum[icont-3]+=h_ht_sl->GetBinContent(icont,3)*h_Charge->Integral()/h_Charge->GetEntries();
     cont_ssdl_jnum[icont-3]+=h_ht_dl->GetBinContent(icont,3)+
       h_ht_dl->GetBinContent(icont,5)+
       h_ht_dl->GetBinContent(icont,6);
     errcont_ssdl_jnum[icont-3]+=(h_ht_dl->GetBinContent(icont,3)+
				  h_ht_dl->GetBinContent(icont,5)+
				  h_ht_dl->GetBinContent(icont,6))*
       h_Charge->Integral()/h_Charge->GetEntries();
     
   } 
   sigmet->cd(DIR);
   for (int icont=3; icont<7;icont++){
     cont_tau_mnum[icont-3]+=h_ht_sl->GetBinContent(icont,3);
     errcont_tau_mnum[icont-3]+=h_ht_sl->GetBinContent(icont,3)*h_Charge->Integral()/h_Charge->GetEntries();
     cont_ssdl_mnum[icont-3]+=h_ht_dl->GetBinContent(icont,3)+
       h_ht_dl->GetBinContent(icont,5)+
       h_ht_dl->GetBinContent(icont,6);
     errcont_ssdl_mnum[icont-3]+=(h_ht_dl->GetBinContent(icont,3)+
				  h_ht_dl->GetBinContent(icont,5)+
				  h_ht_dl->GetBinContent(icont,6))*
       h_Charge->Integral()/h_Charge->GetEntries();
     
   } 
   
   for (int ij=0;ij<4;ij++){
     
     float errB=cont_tau_jnum[ij]*sqrt(errcont_tau_jden[ij])/pow((cont_tau_jnum[ij]+cont_tau_jden[ij]),2);
     float errA=(2*cont_tau_jnum[ij]+cont_tau_jden[ij])*sqrt(errcont_tau_jnum[ij])/pow((cont_tau_jnum[ij]+cont_tau_jden[ij]),2);
     
     cont_j.SetBinContent(ij+1,cont_tau_jnum[ij]/(cont_tau_jnum[ij]+cont_tau_jden[ij]));
     cont_j.SetBinError(ij+1,sqrt(errA*errA+errB*errB));

     errB=cont_ssdl_jnum[ij]*sqrt(errcont_ssdl_jden[ij])/pow((cont_ssdl_jnum[ij]+cont_ssdl_jden[ij]),2);
     errA=(2*cont_ssdl_jnum[ij]+cont_ssdl_jden[ij])*sqrt(errcont_ssdl_jnum[ij])/pow((cont_ssdl_jnum[ij]+cont_ssdl_jden[ij]),2);

     cont_ssdl_j.SetBinContent(ij+1,cont_ssdl_jnum[ij]/(cont_ssdl_jnum[ij]+cont_ssdl_jden[ij]));
     cont_ssdl_j.SetBinError(ij+1,sqrt(errA*errA+errB*errB));

     errB=cont_tau_mnum[ij]*sqrt(errcont_tau_mden[ij])/pow((cont_tau_mnum[ij]+cont_tau_mden[ij]),2);
     errA=(2*cont_tau_mnum[ij]+cont_tau_mden[ij])*sqrt(errcont_tau_mnum[ij])/pow((cont_tau_mnum[ij]+cont_tau_mden[ij]),2);
     
     cont_m.SetBinContent(ij+1,cont_tau_mnum[ij]/(cont_tau_mnum[ij]+cont_tau_mden[ij]));
     cont_m.SetBinError(ij+1,sqrt(errA*errA+errB*errB));

     errB=cont_ssdl_mnum[ij]*sqrt(errcont_ssdl_mden[ij])/pow((cont_ssdl_mnum[ij]+cont_ssdl_mden[ij]),2);
     errA=(2*cont_ssdl_mnum[ij]+cont_ssdl_mden[ij])*sqrt(errcont_ssdl_mnum[ij])/pow((cont_ssdl_mnum[ij]+cont_ssdl_mden[ij]),2);

     cont_ssdl_m.SetBinContent(ij+1,cont_ssdl_mnum[ij]/(cont_ssdl_mnum[ij]+cont_ssdl_mden[ij]));
     cont_ssdl_m.SetBinError(ij+1,sqrt(errA*errA+errB*errB));
     
     float ratio=cont_ssdl_jden[ij]/cont_tau_jden[ij];
     float ERR=ratio*sqrt((errcont_tau_jden[ij]/(cont_tau_jden[ij]*cont_tau_jden[ij])) + 
			  (errcont_ssdl_jden[ij]/(cont_ssdl_jden[ij]*cont_ssdl_jden[ij])));
     lep_j.SetBinContent(ij+1,ratio);
     lep_j.SetBinError(ij+1,ERR);
     
   }
 


   cout<<"ALL TOGETHER "<<endl;

   sigmet->cd(DIR);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float serr_SL_M_L=err_SL_M_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_M_L-SL_M_L));
   float sDL_M_H=DL_M_H+
     h_ht_dl->GetBinContent(5,3)+ h_ht_dl->GetBinContent(5,5)+ h_ht_dl->GetBinContent(5,6)+
     h_ht_dl->GetBinContent(6,3)+ h_ht_dl->GetBinContent(6,5)+ h_ht_dl->GetBinContent(6,6);
   sigjet->cd(DIR);
   float sSL_J_L=SL_J_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sSL_J_H=SL_J_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_J_L=DL_J_L+
     h_ht_dl->GetBinContent(3,3)+ h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(3,6)+
     h_ht_dl->GetBinContent(4,3)+ h_ht_dl->GetBinContent(4,5)+ h_ht_dl->GetBinContent(4,6);
   
   float serr_SL_J_L=err_SL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_L-SL_J_L));
   float serr_SL_J_H=err_SL_J_H+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_H-SL_J_H));
   float serr_DL_J_L=err_DL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sDL_J_L-DL_J_L));



   float predsusy=(sDL_J_L*sSL_J_H*sSL_M_L)/(sSL_J_L*sSL_J_L);
   float serrTot=sqrt(
		     (serr_SL_M_L/(sSL_M_L*sSL_M_L))+
		     (2*serr_SL_J_L/(sSL_J_L*sSL_J_L))+
		     (serr_SL_J_H/(sSL_J_H*sSL_J_H))+
		     (serr_DL_J_L/(sDL_J_L*sDL_J_L))
		     ); 


   float pred= (DL_J_L*SL_J_H*SL_M_L)/(SL_J_L*SL_J_L);
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (2*err_SL_J_L/(SL_J_L*SL_J_L))+
		     (err_SL_J_H/(SL_J_H*SL_J_H))+
		     (err_DL_J_L/(DL_J_L*DL_J_L))
		     ); 

   cout<<"MC EXPECTED: no susy "<<DL_M_H
       <<"             with susy  "<<sDL_M_H<<endl;
   cout<<"PREDICTED:   no susy "<<pred<<"+/-"<<pred*errTot
       <<"   with susy  "<<predsusy<<"+/-"<<predsusy*serrTot<<endl;


   //TAU-TAU

   cout<<endl<<"TAU TAU "<<endl;
   float SL_M_L=0,DL_M_H=0,SL_J_L=0,SL_J_H=0,DL_J_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_J_L=0,err_SL_J_H=0,err_DL_J_L=0;

   for (int if=0; if<14; if++){
     met[if].cd(DIR);
     float priv_SL_M_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
     float priverr_SL_M_L= priv_SL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     float priv_DL_M_H=h_ht_dl->GetBinContent(5,3)+h_ht_dl->GetBinContent(6,3);
     float priverr_DL_M_H= priv_DL_M_H*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_M_L+=priv_SL_M_L;
     err_SL_M_L+=priverr_SL_M_L; 
     DL_M_H+=priv_DL_M_H;
     err_DL_M_H+=priverr_DL_M_H; 

     sj[if].cd(DIR);
     float priv_SL_J_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
     float priverr_SL_J_L= priv_SL_J_L*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_SL_J_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_J_H= priv_SL_J_H*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_DL_J_L=
       h_ht_dl->GetBinContent(3,3)+h_ht_dl->GetBinContent(4,3);
     float priverr_DL_J_L= priv_DL_J_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_J_L+=priv_SL_J_L;
     SL_J_H+=priv_SL_J_H;
     DL_J_L+=priv_DL_J_L;

     err_SL_J_L+=priverr_SL_J_L;
     err_SL_J_H+=priverr_SL_J_H;
     err_DL_J_L+=priverr_DL_J_L;


   }


     sigmet->cd(DIR);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float serr_SL_M_L=err_SL_M_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_M_L-SL_M_L));
   float sDL_M_H=DL_M_H+h_ht_dl->GetBinContent(5,3)+h_ht_dl->GetBinContent(6,3);
   sigjet->cd(DIR);
   float sSL_J_L=SL_J_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sSL_J_H=SL_J_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_J_L=DL_J_L+h_ht_dl->GetBinContent(3,3)+ h_ht_dl->GetBinContent(4,3);

   float serr_SL_J_L=err_SL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_L-SL_J_L));
   float serr_SL_J_H=err_SL_J_H+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_H-SL_J_H));
   float serr_DL_J_L=err_DL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sDL_J_L-DL_J_L));



   float predsusy=(sDL_J_L*sSL_J_H*sSL_M_L)/(sSL_J_L*sSL_J_L);
   float serrTot=sqrt(
		     (serr_SL_M_L/(sSL_M_L*sSL_M_L))+
		     (2*serr_SL_J_L/(sSL_J_L*sSL_J_L))+
		     (serr_SL_J_H/(sSL_J_H*sSL_J_H))+
		     (serr_DL_J_L/(sDL_J_L*sDL_J_L))
		     ); 


   float pred= (DL_J_L*SL_J_H*SL_M_L)/(SL_J_L*SL_J_L);
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (2*err_SL_J_L/(SL_J_L*SL_J_L))+
		     (err_SL_J_H/(SL_J_H*SL_J_H))+
		     (err_DL_J_L/(DL_J_L*DL_J_L))
		     ); 

   cout<<"MC EXPECTED: no susy "<<DL_M_H
       <<"             with susy  "<<sDL_M_H<<endl;
   cout<<"PREDICTED:   no susy "<<pred<<"+/-"<<pred*errTot
       <<"   with susy  "<<predsusy<<"+/-"<<predsusy*serrTot<<endl;

   // MU-TAU
   cout<<endl<<"TAU-MU "<<endl;
   float SL_M_L=0,DL_M_H=0,SL_J_L=0,SL_J_H=0,DL_J_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_J_L=0,err_SL_J_H=0,err_DL_J_L=0;
   
   for (int if=0; if<14; if++){
     met[if].cd(DIR);
     float priv_SL_M_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
     float priverr_SL_M_L= priv_SL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     float priv_DL_M_H=h_ht_dl->GetBinContent(5,6)+h_ht_dl->GetBinContent(6,6);
     float priverr_DL_M_H= priv_DL_M_H*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_M_L+=priv_SL_M_L;
     err_SL_M_L+=priverr_SL_M_L; 
     DL_M_H+=priv_DL_M_H;
     err_DL_M_H+=priverr_DL_M_H; 

     sj[if].cd(DIR);
     float priv_SL_J_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
     float priverr_SL_J_L= priv_SL_J_L*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_SL_J_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_J_H= priv_SL_J_H*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_DL_J_L= h_ht_dl->GetBinContent(3,6)+ h_ht_dl->GetBinContent(4,6);
     float priverr_DL_J_L= priv_DL_J_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_J_L+=priv_SL_J_L;
     SL_J_H+=priv_SL_J_H;
     DL_J_L+=priv_DL_J_L;

     err_SL_J_L+=priverr_SL_J_L;
     err_SL_J_H+=priverr_SL_J_H;
     err_DL_J_L+=priverr_DL_J_L;

     //    cout<<"FF "<<priv_DL_M_H<<" "<<priverr_DL_M_H<<endl;
   }

   sigmet->cd(DIR);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float serr_SL_M_L=err_SL_M_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_M_L-SL_M_L));
   float sDL_M_H=DL_M_H+h_ht_dl->GetBinContent(5,6)+h_ht_dl->GetBinContent(6,6);
   sigjet->cd(DIR);
   float sSL_J_L=SL_J_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sSL_J_H=SL_J_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_J_L=DL_J_L+h_ht_dl->GetBinContent(3,6)+ h_ht_dl->GetBinContent(4,6);

   float serr_SL_J_L=err_SL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_L-SL_J_L));
   float serr_SL_J_H=err_SL_J_H+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_H-SL_J_H));
   float serr_DL_J_L=err_DL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sDL_J_L-DL_J_L));



   float predsusy=(sDL_J_L*sSL_J_H*sSL_M_L)/(sSL_J_L*sSL_J_L);
   float serrTot=sqrt(
		     (serr_SL_M_L/(sSL_M_L*sSL_M_L))+
		     (2*serr_SL_J_L/(sSL_J_L*sSL_J_L))+
		     (serr_SL_J_H/(sSL_J_H*sSL_J_H))+
		     (serr_DL_J_L/(sDL_J_L*sDL_J_L))
		     ); 


   float pred= (DL_J_L*SL_J_H*SL_M_L)/(SL_J_L*SL_J_L);
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (2*err_SL_J_L/(SL_J_L*SL_J_L))+
		     (err_SL_J_H/(SL_J_H*SL_J_H))+
		     (err_DL_J_L/(DL_J_L*DL_J_L))
		     ); 

   cout<<"MC EXPECTED: no susy "<<DL_M_H
       <<"             with susy  "<<sDL_M_H<<endl;
   cout<<"PREDICTED:   no susy "<<pred<<"+/-"<<pred*errTot
       <<"   with susy  "<<predsusy<<"+/-"<<predsusy*serrTot<<endl;

   
   // MU-TAU
   cout<<endl<<"TAU-EL "<<endl;
   float SL_M_L=0,DL_M_H=0,SL_J_L=0,SL_J_H=0,DL_J_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_J_L=0,err_SL_J_H=0,err_DL_J_L=0;
   
   for (int if=0; if<14; if++){
     met[if].cd(DIR);
     float priv_SL_M_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
     float priverr_SL_M_L= priv_SL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     float priv_DL_M_H=h_ht_dl->GetBinContent(5,5)+h_ht_dl->GetBinContent(6,5);
     float priverr_DL_M_H= priv_DL_M_H*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_M_L+=priv_SL_M_L;
     err_SL_M_L+=priverr_SL_M_L; 
     DL_M_H+=priv_DL_M_H;
     err_DL_M_H+=priverr_DL_M_H; 

     sj[if].cd(DIR);
     float priv_SL_J_L=h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
     float priverr_SL_J_L= priv_SL_J_L*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_SL_J_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_J_H= priv_SL_J_H*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_DL_J_L= h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(4,5);
     float priverr_DL_J_L= priv_DL_J_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_J_L+=priv_SL_J_L;
     SL_J_H+=priv_SL_J_H;
     DL_J_L+=priv_DL_J_L;

     err_SL_J_L+=priverr_SL_J_L;
     err_SL_J_H+=priverr_SL_J_H;
     err_DL_J_L+=priverr_DL_J_L;

     //    cout<<"FF "<<priv_DL_M_H<<" "<<priverr_DL_M_H<<endl;
   }
   sigmet->cd(DIR);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float serr_SL_M_L=err_SL_M_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_M_L-SL_M_L));
   float sDL_M_H=DL_M_H+h_ht_dl->GetBinContent(5,5)+h_ht_dl->GetBinContent(6,5);
   sigjet->cd(DIR);
   float sSL_J_L=SL_J_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sSL_J_H=SL_J_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_J_L=DL_J_L+h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(4,5);

   float serr_SL_J_L=err_SL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_L-SL_J_L));
   float serr_SL_J_H=err_SL_J_H+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sSL_J_H-SL_J_H));
   float serr_DL_J_L=err_DL_J_L+((h_Charge->Integral()/h_Charge->GetEntries())*
				 (sDL_J_L-DL_J_L));



   float predsusy=(sDL_J_L*sSL_J_H*sSL_M_L)/(sSL_J_L*sSL_J_L);
   float serrTot=sqrt(
		     (serr_SL_M_L/(sSL_M_L*sSL_M_L))+
		     (2*serr_SL_J_L/(sSL_J_L*sSL_J_L))+
		     (serr_SL_J_H/(sSL_J_H*sSL_J_H))+
		     (serr_DL_J_L/(sDL_J_L*sDL_J_L))
		     ); 


   float pred= (DL_J_L*SL_J_H*SL_M_L)/(SL_J_L*SL_J_L);
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (2*err_SL_J_L/(SL_J_L*SL_J_L))+
		     (err_SL_J_H/(SL_J_H*SL_J_H))+
		     (err_DL_J_L/(DL_J_L*DL_J_L))
		     ); 

   cout<<"MC EXPECTED: no susy "<<DL_M_H
       <<"             with susy  "<<sDL_M_H<<endl;
   cout<<"PREDICTED:   no susy "<<pred<<"+/-"<<pred*errTot
       <<"   with susy  "<<predsusy<<"+/-"<<predsusy*serrTot<<endl;

   for (int if=0; if<14; if++){
     delete met[if];
     delete sj[if];
   }
   delete sigmet;
   delete sigjet;
}
