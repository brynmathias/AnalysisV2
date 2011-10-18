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
 HTs.push_back(" HT_{cut}=100");
 HTs.push_back(" HT_{cut}=200");
 HTs.push_back(" HT_{cut}=350");
 HTs.push_back(" HT_{cut}=600"); 
 TCanvas *c1= new TCanvas("c1","MV vs estimation",1000,300);
 TH1F *mc= new TH1F("mc","only BKG",4,0,4);
 TH1F *mc_sig= new TH1F("mc_sig","BKG+LM0",4,0,4);
 mc->GetXaxis()->SetBinLabel(1,HTs[0]);
 mc->GetXaxis()->SetBinLabel(2,HTs[1]);
 mc->GetXaxis()->SetBinLabel(3,HTs[2]);
 mc->GetXaxis()->SetBinLabel(4,HTs[3]);
 mc->GetYaxis()->SetTitle("Nev/100 pb^{-1}");
 mc_sig->GetXaxis()->SetBinLabel(1,HTs[0]);
 mc_sig->GetXaxis()->SetBinLabel(2,HTs[1]);
 mc_sig->GetXaxis()->SetBinLabel(3,HTs[2]);
 mc_sig->GetXaxis()->SetBinLabel(4,HTs[3]);
 mc_sig->GetYaxis()->SetTitle("Nev/100 pb^{-1}");
 TH1F *est= new TH1F("est","mc vs estimation",4,0,4);
 TH1F *est_sig= new TH1F("est_sig","mc vs estimation",4,0,4);
 
  //file
  
  TString DIR ="DiLepSelec";

  //MET

  TFile* met[15];
  TFile* jet[15];

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
  met[14]= new TFile("contagli/lm0.root");

 //Single jet
  
  jet[0]= new TFile("singlejet/contagli/q80.root"); 
  jet[1]= new TFile("singlejet/contagli/q170.root");   
  jet[2]= new TFile("singlejet/contagli/q300.root");
  jet[3]= new TFile("singlejet/contagli/q470.root");   
  jet[4]= new TFile("singlejet/contagli/q800.root");
  jet[5]= new TFile("singlejet/contagli/q1400.root");   
  jet[6]= new TFile("singlejet/contagli/q2200.root");
  jet[7]= new TFile("singlejet/contagli/q3000.root");
  jet[13]= new TFile("singlejet/contagli/wjets.root");
  jet[9]= new TFile("singlejet/contagli/ww.root");
  jet[10]= new TFile("singlejet/contagli/tt.root");
  jet[11]= new TFile("singlejet/contagli/wz.root");
  jet[12]= new TFile("singlejet/contagli/zz.root");
  jet[8]= new TFile("singlejet/contagli/zjets.root");
  jet[14]= new TFile("singlejet/contagli/lm0.root");


 

  

  int istart=2;
  int iend=7;
  //  int ilim=5;
  

  
  
//   //TAUTAU
//   cout<<"TAUEL"<<endl;
//   for (int ig=istart; ig<6; ig++){		
//     // cout<<"IG"<<ig<<endl;
//     float m_sl_l=0,m_dl_l=0,m_sl_h=0,m_dl_h=0;
//     float j_sl_l=0,j_dl_l=0,j_sl_h=0,j_dl_h=0;
//     float em_sl_l=0,em_dl_l=0,em_sl_h=0,em_dl_h=0;
//     float ej_sl_l=0,ej_dl_l=0,ej_sl_h=0,ej_dl_h=0;
//     for (int if=0; if<14; if++){
//       for (int is=istart;is<=ig;is++){
// 	met[if]->cd(DIR);
// 	m_sl_l+=h_ht_sl->GetBinContent(is,3);
// 	m_dl_l+=h_ht_dl->GetBinContent(is,5);
// 	em_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	em_dl_l+=h_ht_dl->GetBinContent(is,5)*h_Charge->Integral()/h_Charge->GetEntries();
// 	jet[if]->cd(DIR);
// 	j_sl_l+=h_ht_sl->GetBinContent(is,3);
// 	j_dl_l+=h_ht_dl->GetBinContent(is,5);
// 	ej_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	ej_dl_l+=h_ht_dl->GetBinContent(is,5)*h_Charge->Integral()/h_Charge->GetEntries();
//       }
//       for (int is=ig+1;is<7;is++){
// 	met[if]->cd(DIR);
// 	m_sl_h+=h_ht_sl->GetBinContent(is,3);
// 	m_dl_h+=h_ht_dl->GetBinContent(is,5);
// 	em_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	em_dl_h+=h_ht_dl->GetBinContent(is,5)*h_Charge->Integral()/h_Charge->GetEntries();
// 	jet[if]->cd(DIR);
// 	j_sl_h+=h_ht_sl->GetBinContent(is,3);
// 	j_dl_h+=h_ht_dl->GetBinContent(is,3);
// 	ej_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	ej_dl_h+=h_ht_dl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
//       }
//     }
//     float met_pred=(m_dl_l/m_sl_l)*m_sl_h;
//     float jet_pred=(m_sl_l/j_sl_l)*(j_dl_l/j_sl_l)*j_sl_h;
//     float errTot=sqrt(
// 		      (em_sl_l/(m_sl_l*m_sl_l))+
// 		      (2*ej_sl_l/(j_sl_l*j_sl_l))+
// 		      (ej_sl_h/(j_sl_h*j_sl_h))+
// 		      (ej_dl_l/(j_dl_l*j_dl_l))); 
//     cout<<"MC "<< m_dl_h<<"+/-"<<sqrt(em_dl_h) <<" PREDICTED "<<jet_pred <<"+/-"<<errTot*jet_pred<<endl;
//   }

//   //TAUMU
//   cout<<"TAUMU"<<endl;
//   for (int ig=istart; ig<6; ig++){		
//     // cout<<"IG"<<ig<<endl;
//     float m_sl_l=0,m_dl_l=0,m_sl_h=0,m_dl_h=0;
//     float j_sl_l=0,j_dl_l=0,j_sl_h=0,j_dl_h=0;
//     float em_sl_l=0,em_dl_l=0,em_sl_h=0,em_dl_h=0;
//     float ej_sl_l=0,ej_dl_l=0,ej_sl_h=0,ej_dl_h=0;
//     for (int if=0; if<14; if++){
//       for (int is=istart;is<=ig;is++){
// 	met[if]->cd(DIR);
// 	m_sl_l+=h_ht_sl->GetBinContent(is,3);
// 	m_dl_l+=h_ht_dl->GetBinContent(is,6);
// 	em_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	em_dl_l+=h_ht_dl->GetBinContent(is,6)*h_Charge->Integral()/h_Charge->GetEntries();
// 	jet[if]->cd(DIR);
// 	j_sl_l+=h_ht_sl->GetBinContent(is,3);
// 	j_dl_l+=h_ht_dl->GetBinContent(is,6);
// 	ej_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	ej_dl_l+=h_ht_dl->GetBinContent(is,6)*h_Charge->Integral()/h_Charge->GetEntries();
//       }
//       for (int is=ig+1;is<7;is++){
// 	met[if]->cd(DIR);
// 	m_sl_h+=h_ht_sl->GetBinContent(is,3);
// 	m_dl_h+=h_ht_dl->GetBinContent(is,6);
// 	em_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	em_dl_h+=h_ht_dl->GetBinContent(is,6)*h_Charge->Integral()/h_Charge->GetEntries();
// 	jet[if]->cd(DIR);
// 	j_sl_h+=h_ht_sl->GetBinContent(is,3);
// 	j_dl_h+=h_ht_dl->GetBinContent(is,6);
// 	ej_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	ej_dl_h+=h_ht_dl->GetBinContent(is,6)*h_Charge->Integral()/h_Charge->GetEntries();
//       }
//     }
//     float met_pred=(m_dl_l/m_sl_l)*m_sl_h;
//     float jet_pred=(m_sl_l/j_sl_l)*(j_dl_l/j_sl_l)*j_sl_h;
//     float errTot=sqrt(
// 		      (em_sl_l/(m_sl_l*m_sl_l))+
// 		      (2*ej_sl_l/(j_sl_l*j_sl_l))+
// 		      (ej_sl_h/(j_sl_h*j_sl_h))+
// 		      (ej_dl_l/(j_dl_l*j_dl_l))); 
//     cout<<"MC "<< m_dl_h<<"+/-"<<sqrt(em_dl_h) <<" PREDICTED "<<jet_pred <<"+/-"<<errTot*jet_pred<<endl;
//   }



//    //TAUTAU
//   cout<<"TAUTAU"<<endl;
//   for (int ig=istart; ig<6; ig++){		
//     // cout<<"IG"<<ig<<endl;
//     float m_sl_l=0,m_dl_l=0,m_sl_h=0,m_dl_h=0;
//     float j_sl_l=0,j_dl_l=0,j_sl_h=0,j_dl_h=0;
//     float em_sl_l=0,em_dl_l=0,em_sl_h=0,em_dl_h=0;
//     float ej_sl_l=0,ej_dl_l=0,ej_sl_h=0,ej_dl_h=0;
//     for (int if=0; if<14; if++){
//       for (int is=istart;is<=ig;is++){
// 	met[if]->cd(DIR);
// 	m_sl_l+=h_ht_sl->GetBinContent(is,3);
// 	m_dl_l+=h_ht_dl->GetBinContent(is,3);
// 	em_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	em_dl_l+=h_ht_dl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	jet[if]->cd(DIR);
// 	j_sl_l+=h_ht_sl->GetBinContent(is,3);
// 	j_dl_l+=h_ht_dl->GetBinContent(is,3);
// 	ej_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	ej_dl_l+=h_ht_dl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
//       }
//       for (int is=ig+1;is<7;is++){
// 	met[if]->cd(DIR);
// 	m_sl_h+=h_ht_sl->GetBinContent(is,3);
// 	m_dl_h+=h_ht_dl->GetBinContent(is,3);
// 	em_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	em_dl_h+=h_ht_dl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	jet[if]->cd(DIR);
// 	j_sl_h+=h_ht_sl->GetBinContent(is,3);
// 	j_dl_h+=h_ht_dl->GetBinContent(is,3);
// 	ej_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
// 	ej_dl_h+=h_ht_dl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
//       }
//     }
//     float met_pred=(m_dl_l/m_sl_l)*m_sl_h;
//     float jet_pred=(m_sl_l/j_sl_l)*(j_dl_l/j_sl_l)*j_sl_h;
//     float errTot=sqrt(
// 		      (em_sl_l/(m_sl_l*m_sl_l))+
// 		      (2*ej_sl_l/(j_sl_l*j_sl_l))+
// 		      (ej_sl_h/(j_sl_h*j_sl_h))+
// 		      (ej_dl_l/(j_dl_l*j_dl_l))); 
//     cout<<"MC "<< m_dl_h<<"+/-"<<sqrt(em_dl_h) <<" PREDICTED "<<jet_pred <<"+/-"<<errTot*jet_pred<<endl;
//   } 
   //allTogether
  cout<<"all together"<<endl;
  for (int ig=istart; ig<6; ig++){		
    // cout<<"IG"<<ig<<endl;
    float m_sl_l=0,m_dl_l=0,m_sl_h=0,m_dl_h=0;
    float j_sl_l=0,j_dl_l=0,j_sl_h=0,j_dl_h=0;
    float em_sl_l=0,em_dl_l=0,em_sl_h=0,em_dl_h=0;
    float ej_sl_l=0,ej_dl_l=0,ej_sl_h=0,ej_dl_h=0;
    for (int if=0; if<14; if++){
      for (int is=istart;is<=ig;is++){
	met[if]->cd(DIR);
	m_sl_l+=h_ht_sl->GetBinContent(is,3);
	m_dl_l+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	em_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	em_dl_l+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
	jet[if]->cd(DIR);
	j_sl_l+=h_ht_sl->GetBinContent(is,3);
	j_dl_l+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	ej_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	ej_dl_l+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
      }
      for (int is=ig+1;is<7;is++){
	met[if]->cd(DIR);
	m_sl_h+=h_ht_sl->GetBinContent(is,3);
	m_dl_h+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	em_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	em_dl_h+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
	jet[if]->cd(DIR);
	j_sl_h+=h_ht_sl->GetBinContent(is,3);
	j_dl_h+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	ej_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	ej_dl_h+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
      }
    }
    float met_pred=(m_dl_l/m_sl_l)*m_sl_h;
    float jet_pred=(m_sl_l/j_sl_l)*(j_dl_l/j_sl_l)*j_sl_h;
    float errTot=sqrt(
		      (em_sl_l/(m_sl_l*m_sl_l))+
		      (2*ej_sl_l/(j_sl_l*j_sl_l))+
		      (ej_sl_h/(j_sl_h*j_sl_h))+
		      (ej_dl_l/(j_dl_l*j_dl_l))); 
    cout<<"MC "<< m_dl_h<<"+/-"<<sqrt(em_dl_h) <<" PREDICTED "<<jet_pred <<"+/-"<<errTot*jet_pred<<endl;
    mc->SetBinContent(ig-1,m_dl_h);    
    mc->SetBinError(ig-1,sqrt(em_dl_h));
    est->SetBinContent(ig-1,jet_pred);    
    est->SetBinError(ig-1,errTot*jet_pred);
  }

  for (int ig=istart; ig<6; ig++){		
    // cout<<"IG"<<ig<<endl;
    float m_sl_l=0,m_dl_l=0,m_sl_h=0,m_dl_h=0;
    float j_sl_l=0,j_dl_l=0,j_sl_h=0,j_dl_h=0;
    float em_sl_l=0,em_dl_l=0,em_sl_h=0,em_dl_h=0;
    float ej_sl_l=0,ej_dl_l=0,ej_sl_h=0,ej_dl_h=0;
    for (int if=0; if<15; if++){
      for (int is=istart;is<=ig;is++){
	met[if]->cd(DIR);
	m_sl_l+=h_ht_sl->GetBinContent(is,3);
	m_dl_l+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	em_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	em_dl_l+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
	jet[if]->cd(DIR);
	j_sl_l+=h_ht_sl->GetBinContent(is,3);
	j_dl_l+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	ej_sl_l+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	ej_dl_l+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
      }
      for (int is=ig+1;is<7;is++){
	met[if]->cd(DIR);
	m_sl_h+=h_ht_sl->GetBinContent(is,3);
	m_dl_h+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	em_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	em_dl_h+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
	jet[if]->cd(DIR);
	j_sl_h+=h_ht_sl->GetBinContent(is,3);
	j_dl_h+=h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6);
	ej_sl_h+=h_ht_sl->GetBinContent(is,3)*h_Charge->Integral()/h_Charge->GetEntries();
	ej_dl_h+=(h_ht_dl->GetBinContent(is,3)+h_ht_dl->GetBinContent(is,5)+h_ht_dl->GetBinContent(is,6))*h_Charge->Integral()/h_Charge->GetEntries();
      }
    }
    float met_pred=(m_dl_l/m_sl_l)*m_sl_h;
    float jet_pred=(m_sl_l/j_sl_l)*(j_dl_l/j_sl_l)*j_sl_h;
    float errTot=sqrt(
		      (em_sl_l/(m_sl_l*m_sl_l))+
		      (2*ej_sl_l/(j_sl_l*j_sl_l))+
		      (ej_sl_h/(j_sl_h*j_sl_h))+
		      (ej_dl_l/(j_dl_l*j_dl_l))); 
    cout<<"MC "<< m_dl_h<<"+/-"<<sqrt(em_dl_h) <<" PREDICTED "<<jet_pred <<"+/-"<<errTot*jet_pred<<endl;
    mc_sig->SetBinContent(ig-1,m_dl_h);    
    mc_sig->SetBinError(ig-1,sqrt(em_dl_h));
    est_sig->SetBinContent(ig-1,jet_pred);    
    est_sig->SetBinError(ig-1,errTot*jet_pred);
  }



  c1->Divide(2,1);

  c1->cd(1);
  TPad::c1_1->SetLogy();
  TPad::c1_2->SetLogy();
  mc->SetMinimum(2);
  mc->SetMaximum(180);   
  mc->SetMarkerStyle(20);
  mc->SetMarkerColor(2);
  mc->Draw("pe");
  est->SetMarkerStyle(23);
  est->SetMarkerColor(4);
  est->Draw("pesame");
  TLegend *ll = new TLegend(0.65,0.7,0.9,0.9);
  ll->AddEntry(mc,"MC true","p");
  ll->AddEntry(est,"Estimation","p");
  ll->Draw();

  c1->cd(2);
  mc_sig->SetMinimum(2);
  mc_sig->SetMaximum(180);   
  mc_sig->SetMarkerStyle(20);
  mc_sig->SetMarkerColor(2);
  mc_sig->Draw("pe");
  est_sig->SetMarkerStyle(23);
  est_sig->SetMarkerColor(4);
  est_sig->Draw("pesame");
  TLegend *ll_sig = new TLegend(0.65,0.7,0.9,0.9);
  ll_sig->AddEntry(mc_sig,"MC true","p");
  ll_sig->AddEntry(est_sig,"Estimation","p");
  ll_sig->Draw();


}
