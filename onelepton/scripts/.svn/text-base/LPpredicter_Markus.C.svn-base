LPpredicter_Markus()
{

  TString datafile("MC_LM3x3.root");
 
  cout << "weiter oben"<<endl;
  DoPredicter(TString("500-750 GeV"),1,TString("Counter_BSMGrid_500_pre_LP"),TString("Counter_BSMGrid_500"),TString("MC_SM3.root"),datafile);
  DoPredicter(TString("500-750 GeV"),2,TString("Counter_BSMGrid_500_pre_LP"),TString("Counter_BSMGrid_500"),TString("MC_SM3.root"),datafile);
  DoPredicter(TString("500-750 GeV"),3,TString("Counter_BSMGrid_500_pre_LP"),TString("Counter_BSMGrid_500"),TString("MC_SM3.root"),datafile);

   cout <<endl;

  DoPredicter(TString("750-1000 GeV"),1,TString("Counter_BSMGrid_750_pre_LP"),TString("Counter_BSMGrid_750"),TString("MC_SM3.root"),datafile);
  DoPredicter(TString("750-1000 GeV"),2,TString("Counter_BSMGrid_750_pre_LP"),TString("Counter_BSMGrid_750"),TString("MC_SM3.root"),datafile);
  DoPredicter(TString("750-100 GeV"),3,TString("Counter_BSMGrid_750_pre_LP"),TString("Counter_BSMGrid_750"),TString("MC_SM3.root"),datafile);
 
  cout <<endl;
  DoPredicter(TString("1000 GeV"),1,TString("Counter_BSMGrid_final_selection_pre_LP"),TString("Counter_BSMGrid_final_selection"),TString("MC_SM3.root"),datafile);
  DoPredicter(TString("1000 GeV"),2,TString("Counter_BSMGrid_final_selection_pre_LP"),TString("Counter_BSMGrid_final_selection"),TString("MC_SM3.root"),datafile);
  DoPredicter(TString("1000 GeV"),3,TString("Counter_BSMGrid_final_selection_pre_LP"),TString("Counter_BSMGrid_final_selection"),TString("MC_SM3.root"),datafile);
   
}

DoPredicter(TString WhatBin, int jetno, TString placeName_precut,TString placeName_postcut,TString fileMC,TString fileData )
{

  TFile* data_file = new TFile(fileData);
  TH1D* data_njet_precut =  (TH1D*)data_file->Get(placeName_precut+"/CxjetsMult");
  TH1D* data_njet_postcut =  (TH1D*)data_file->Get(placeName_postcut+"/CxjetsMult");

  TFile* MC_file = new TFile(fileMC);
  TH1D* MC_njet_precut =  (TH1D*)MC_file->Get(placeName_precut+"/CxjetsMult");
  TH1D* MC_njet_postcut =  (TH1D*)MC_file->Get(placeName_postcut+"/CxjetsMult");
  MC_njet_postcut->DrawCopy();
  //  MC_njet_precut->DrawCopy("same");

  int binCenter=10;
  int binmax=20;

  Double_t& MCerr_all_pre = new Double_t(0.);
  MC_njet_precut->IntegralAndError(0,binmax ,MCerr_all_pre);
  float  MC_all_pre =MC_njet_precut->Integral(0,binCenter-jetno)+MC_njet_precut->Integral(binCenter+jetno+2,binmax);
  
  Double_t& MCerr_plus_pre = new Double_t(0.);
  MC_njet_precut->IntegralAndError(0,binCenter-jetno,MCerr_plus_pre );
  float  MC_plus_pre=MC_njet_precut->Integral(0,binCenter-jetno);
  
  Double_t& MCerr_plus_pre = new Double_t(0.);
  MC_njet_precut->IntegralAndError(binCenter+jetno+2,binmax,MCerr_plus_pre); 
  float   MC_minus_pre=MC_njet_precut->Integral(binCenter+jetno+2,binmax);
  

  Double_t& MCerr_all_post = new Double_t(0.);
  MC_njet_postcut->IntegralAndError(0,binmax ,MCerr_all_post);
  float   MC_all_post=MC_njet_postcut->Integral(0,binCenter-jetno)+MC_njet_postcut->Integral(binCenter+jetno+2,binmax);
  
  Double_t& MCerr_plus_post = new Double_t(0.);
  MC_njet_postcut->IntegralAndError(0,binCenter-jetno,MCerr_plus_post );
  float   MC_plus_post=MC_njet_postcut->Integral(0,binCenter-jetno);
  
  Double_t& MCerr_plus_post = new Double_t(0.);
  MC_njet_postcut->IntegralAndError(binCenter+jetno+2,binmax,MCerr_plus_post); 
  float   MC_minus_post=MC_njet_postcut->Integral(binCenter+jetno+2,binmax);



  Double_t& dataerr_all_pre = new Double_t(0.);
  data_njet_precut->IntegralAndError(0,binmax ,dataerr_all_pre);
  float  data_all_pre =data_njet_precut->Integral(0,binCenter-jetno)+data_njet_precut->Integral(binCenter+jetno+2,binmax);
  
  Double_t& dataerr_plus_pre = new Double_t(0.);
  data_njet_precut->IntegralAndError(0,binCenter-jetno,dataerr_plus_pre );
  float  data_plus_pre=data_njet_precut->Integral(0,binCenter-jetno);
  
  Double_t& dataerr_plus_pre = new Double_t(0.);
  data_njet_precut->IntegralAndError(binCenter+jetno+2,binmax,dataerr_plus_pre); 
  float   data_minus_pre=data_njet_precut->Integral(binCenter+jetno+2,binmax);



  Double_t& dataerr_all_post = new Double_t(0.);
  data_njet_postcut->IntegralAndError(0,binmax ,dataerr_all_post);
  float   data_all_post=data_njet_postcut->Integral(0,binCenter-jetno)+data_njet_postcut->Integral(binCenter+jetno+2,binmax);
  
  Double_t& dataerr_plus_post = new Double_t(0.);
  data_njet_postcut->IntegralAndError(0,binCenter-jetno,dataerr_plus_post );
  float   data_plus_post=data_njet_postcut->Integral(0,binCenter-jetno);
  
  Double_t& dataerr_plus_post = new Double_t(0.);
  data_njet_postcut->IntegralAndError(binCenter+jetno+2,binmax,dataerr_plus_post); 
  float   data_minus_post=data_njet_postcut->Integral(binCenter+jetno+2,binmax);
  


  float all_predicted = MC_all_post/(MC_all_pre-MC_all_post)*(data_all_pre-data_all_post);
  float all_predicted_err = sqrt(data_all_pre-data_all_post)*MC_all_post/(MC_all_pre-MC_all_post);
  cout << "\\hline "<<WhatBin <<  "&jetno$>$"<<jetno<<"  &&&& \\\\ \\hline \\hline"<<endl;
  cout << "charges & prediction & stat error & found & SM (MC)& sigificance\\\\ \\hline"<<endl;
  cout << "both &"<< all_predicted << " & " << all_predicted_err << " & " << data_all_post << " & "<< MC_all_post << " & "<< fabs(all_predicted-data_all_post)/sqrt(all_predicted+all_predicted_err*all_predicted_err)<< "\\\\ \\hline"<<endl;
  //  cout <<MC_all_post<< " "<< MC_all_pre<<endl;
  // cout << "predicted minus charge  & stat error & found & sigificance \\\ \\hline"<<endl;
  float pluspredicted = MC_plus_post/(MC_plus_pre-MC_plus_post)*(data_plus_pre-data_plus_post);
  float pluspredicted_err = sqrt(data_plus_pre-data_plus_post)*MC_plus_post/(MC_plus_pre-MC_plus_post);
  cout << "minus &"<<pluspredicted << " & " << pluspredicted_err << " & " << data_plus_post << " & "<< MC_plus_post<< " & " << fabs(pluspredicted-data_plus_post)/sqrt(pluspredicted+pluspredicted_err*pluspredicted_err)<< "\\\\ \\hline"<<endl;
  //  cout << "predicted plus charge  & stat error & found & sigificance \\\ \\hline"<<endl;
  float minuspredicted = MC_minus_post/(MC_minus_pre-MC_minus_post)*(data_minus_pre-data_minus_post);
  float minuspredicted_err = sqrt(data_minus_pre-data_minus_post)*MC_minus_post/(MC_minus_pre-MC_minus_post);
  cout << "plus &"<< minuspredicted << " & " << minuspredicted_err << " & " << data_minus_post  << " & "<< MC_minus_post<<" & " << fabs(minuspredicted-data_minus_post)/sqrt(minuspredicted+minuspredicted_err*minuspredicted_err)<< "\\\\ \\hline"<<endl;

}
