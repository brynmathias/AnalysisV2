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






  //file
  
  TString DIR ="DiLepSelec";

  //MET
  TFile* met[15];
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
  met[14]= new TFile("contagli/lm0.root");




   // TOGETHER
  

   float SL_M_L=0,DL_M_H=0,SL_M_L=0,SL_M_H=0,DL_M_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_M_L=0,err_SL_M_H=0,err_DL_M_L=0;
   
   float SL_M_T=0,DL_M_T=0,SL_M_T=0,DL_M_T=0;
   float err_SL_M_T=0,err_DL_M_T=0,err_SL_M_T=0,err_DL_M_T=0;
   
   
   for (int if=0; if<14; if++){
     met[if].cd(DIR);

       
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
     


 
    
    float priv_SL_M_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
    float priverr_SL_M_H= priv_SL_M_H*h_Charge->Integral()/h_Charge->GetEntries();
    
    float priv_DL_M_L=
      h_ht_dl->GetBinContent(3,3)+ h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(3,6)+
      h_ht_dl->GetBinContent(4,3)+ h_ht_dl->GetBinContent(4,5)+ h_ht_dl->GetBinContent(4,6);
    float priverr_DL_M_L= priv_DL_M_L*h_ht_dl->Integral()/h_Charge->GetEntries();
    
    SL_M_H+=priv_SL_M_H;
    DL_M_L+=priv_DL_M_L;
    
    err_SL_M_H+=priverr_SL_M_H;
    err_DL_M_L+=priverr_DL_M_L;
    
   }

   
 


   cout<<"ALL TOGETHER "<<endl;
   float pred= (DL_M_L*SL_M_H)/SL_M_L;
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (err_SL_M_H/(SL_M_H*SL_M_H))+
		     (err_DL_M_L/(DL_M_L*DL_M_L))
		     ); 

   met[14].cd(DIR);
   float sSL_M_H=SL_M_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_M_L=DL_M_L+
     h_ht_dl->GetBinContent(3,3)+ h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(3,6)+
     h_ht_dl->GetBinContent(4,3)+ h_ht_dl->GetBinContent(4,5)+ h_ht_dl->GetBinContent(4,6);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sDL_M_H=DL_M_H+     
     h_ht_dl->GetBinContent(5,3)+ h_ht_dl->GetBinContent(5,5)+ h_ht_dl->GetBinContent(5,6)+
     h_ht_dl->GetBinContent(6,3)+ h_ht_dl->GetBinContent(6,5)+ h_ht_dl->GetBinContent(6,6);

   float predsusy=(sDL_M_L*sSL_M_H)/sSL_M_L;
   cout<<"MC EXPECTED "<<DL_M_H<<" with susy "<<sDL_M_H<<endl;
   cout<<"PREDICTED  "<<pred<<"+/-"<<pred*errTot<<" "<<predsusy<<endl<<endl;



   //TAU-TAU

   cout<<endl<<"TAU TAU "<<endl;
   float SL_M_L=0,DL_M_H=0,SL_M_L=0,SL_M_H=0,DL_M_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_M_L=0,err_SL_M_H=0,err_DL_M_L=0;
   
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

     float priv_SL_M_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_M_H= priv_SL_M_H*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_DL_M_L=
       h_ht_dl->GetBinContent(3,3)+h_ht_dl->GetBinContent(4,3);
     float priverr_DL_M_L= priv_DL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
    SL_M_H+=priv_SL_M_H;
    DL_M_L+=priv_DL_M_L;
    
    err_SL_M_H+=priverr_SL_M_H;
    err_DL_M_L+=priverr_DL_M_L;



   }

   float pred= (DL_M_L*SL_M_H)/SL_M_L;
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (err_SL_M_H/(SL_M_H*SL_M_H))+
		     (err_DL_M_L/(DL_M_L*DL_M_L))
		     ); 

   met[14].cd(DIR);
   float sSL_M_H=SL_M_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_M_L=DL_M_L+h_ht_dl->GetBinContent(3,3)+ h_ht_dl->GetBinContent(4,3);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sDL_M_H=DL_M_H+h_ht_dl->GetBinContent(5,3)+h_ht_dl->GetBinContent(6,3);

   float predsusy=(sDL_M_L*sSL_M_H)/sSL_M_L;
   cout<<"MC EXPECTED "<<DL_M_H<<" with susy "<<sDL_M_H<<endl;
   cout<<"PREDICTED "<<pred<<"+/-"<<pred*errTot<<" "<<predsusy<<endl<<endl;
  

   // MU-TAU
   cout<<endl<<"TAU-MU "<<endl;
   float SL_M_L=0,DL_M_H=0,SL_M_L=0,SL_M_H=0,DL_M_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_M_L=0,err_SL_M_H=0,err_DL_M_L=0;
   
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


     float priv_SL_M_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_M_H= priv_SL_M_H*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_DL_M_L= h_ht_dl->GetBinContent(3,6)+ h_ht_dl->GetBinContent(4,6);
     float priverr_DL_M_L= priv_DL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_M_H+=priv_SL_M_H;
     DL_M_L+=priv_DL_M_L;

     err_SL_M_H+=priverr_SL_M_H;
     err_DL_M_L+=priverr_DL_M_L;

     //    cout<<"FF "<<priv_DL_M_H<<" "<<priverr_DL_M_H<<endl;
   }

   float pred= (DL_M_L*SL_M_H)/SL_M_L;
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (err_SL_M_H/(SL_M_H*SL_M_H))+
		     (err_DL_M_L/(DL_M_L*DL_M_L))
		     ); 


   met[14].cd(DIR);
   float sSL_M_H=SL_M_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_M_L=DL_M_L+h_ht_dl->GetBinContent(3,6)+ h_ht_dl->GetBinContent(4,6);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sDL_M_H=DL_M_H+h_ht_dl->GetBinContent(5,6)+h_ht_dl->GetBinContent(6,6);

   float predsusy=(sDL_M_L*sSL_M_H)/sSL_M_L;
   cout<<"MC EXPECTED "<<DL_M_H<<" with susy "<<sDL_M_H<<endl;
   cout<<"PREDICTED   "<<pred<<"+/-"<<pred*errTot<<" "<<predsusy<<endl<<endl;

   
   // EL-TAU
   cout<<endl<<"TAU-EL "<<endl;
   float SL_M_L=0,DL_M_H=0,SL_M_L=0,SL_M_H=0,DL_M_L=0;
   float err_SL_M_L=0,err_DL_M_H=0,err_SL_M_L=0,err_SL_M_H=0,err_DL_M_L=0;
   
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

     float priv_SL_M_H=h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
     float priverr_SL_M_H= priv_SL_M_H*h_Charge->Integral()/h_Charge->GetEntries();

     float priv_DL_M_L= h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(4,5);
     float priverr_DL_M_L= priv_DL_M_L*h_Charge->Integral()/h_Charge->GetEntries();
     
     SL_M_H+=priv_SL_M_H;
     DL_M_L+=priv_DL_M_L;
     
     err_SL_M_H+=priverr_SL_M_H;
     err_DL_M_L+=priverr_DL_M_L;

     //    cout<<"FF "<<priv_DL_M_H<<" "<<priverr_DL_M_H<<endl;
   }
   met[14].cd(DIR);
   float sSL_M_H=SL_M_H+h_ht_sl->GetBinContent(5,3)+ h_ht_sl->GetBinContent(6,3);
   float sDL_M_L=DL_M_L+h_ht_dl->GetBinContent(3,5)+ h_ht_dl->GetBinContent(4,5);
   float sSL_M_L=SL_M_L+h_ht_sl->GetBinContent(3,3)+ h_ht_sl->GetBinContent(4,3);
   float sDL_M_H=DL_M_H+h_ht_dl->GetBinContent(5,5)+h_ht_dl->GetBinContent(6,5);

   float predsusy=(sDL_M_L*sSL_M_H)/sSL_M_L;
    
   float pred= (DL_M_L*SL_M_H)/SL_M_L;
   float errTot=sqrt(
		     (err_SL_M_L/(SL_M_L*SL_M_L))+
		     (err_SL_M_H/(SL_M_H*SL_M_H))+
		     (err_DL_M_L/(DL_M_L*DL_M_L))
		     ); 

   cout<<"MC EXPECTED "<<DL_M_H<<" with susy "<<sDL_M_H<<endl;
   cout<<"PREDICTED  "<<pred<<"+/-"<<pred*errTot<<" "<<predsusy<<endl;
   
   for (int if=0; if<15; if++)
     delete met[if];
}
