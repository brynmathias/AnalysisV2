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

  
  TFile* tt=new TFile("contagli/tt.root");   
  TFile* bb=new TFile("contagli/bb.root");   
  TFile* qq=new TFile("contagli/qq.root");   
  TFile* zz=new TFile("contagli/zjets.root");   
  //file
  
  TString DIR ="TTBkg";

  tt->cd(DIR);
  //  tt->ls();


  //TT GENERAL

  float tbmc_eff=h_mudaB->GetBinContent(2)/h_mudaB->GetBinContent(1);
  float etbmc_eff=sqrt(tbmc_eff*(1-tbmc_eff)/(h_mudaB->GetBinContent(1)*(h_mudaB->GetEntries()/h_mudaB->Integral())));
  cout<<"mudaB (ttMC) "<<tbmc_eff<<"+\-"<<etbmc_eff<<endl;
  
  float jetspec[3][3];
  for (int i1=0;i1<3;i1++){
    for (int i2=0;i2<3;i2++){
      jetspec[i1][i2]=h_bjet_tt->GetBinContent(i1+1,i2+1)/h_bjet_tt->Integral();
    }
  }
  
  //TT MC AVERAGE

  char hh[20];
  float eff_aver_tt=0;
  float DEN=0;
  for (int i1=0; i1<3; i1++){
    for (int i2=0; i2<3; i2++){
      sprintf(hh,"%s%d%s%d","h_muBmc_eta",i1,"_pt",i2);
      TH1 *h;
      gDirectory.GetObject(hh,h);
      eff_aver_tt+=(h->GetBinContent(2)/h->GetBinContent(1))*jetspec[i2][i1];
      DEN+=h->GetBinContent(1)*(h_mudaB->GetEntries()/h_mudaB->Integral());
    }
  }

  float  eeff_aver_tt=sqrt((eff_aver_tt*(1-eff_aver_tt))/DEN);
  cout<<"mudaB (ttMC average) "<<eff_aver_tt<<"+/-"<<eeff_aver_tt<<endl;

  bb->cd(DIR);
    
  //BB MC AVERAGE
  float eff_aver_bb=0;
  float DEN=0;
  for (int i1=0; i1<3; i1++){
    for (int i2=0; i2<3; i2++){
      sprintf(hh,"%s%d%s%d","h_muBmc_eta",i1,"_pt",i2);
      TH1 *h;
      gDirectory.GetObject(hh,h);
      eff_aver_bb+=(h->GetBinContent(2)/h->GetBinContent(1))*jetspec[i2][i1];
      DEN+=h->GetBinContent(1)*(h_mudaB->GetEntries()/h_mudaB->Integral());

    }
  }
  float eeff_aver_bb=sqrt((eff_aver_bb*(1-eff_aver_bb))/DEN);
  cout<<"mudaB (bbMC average) "<<eff_aver_bb<<"+/-"<<eeff_aver_bb<<endl;


  //BB SEL AVERAGE
  float eff_sel_bb=0;
  float DEN=0;
  for (int i1=0; i1<3; i1++){
    for (int i2=0; i2<3; i2++){
      sprintf(hh,"%s%d%s%d","h_muB_eta",i1,"_pt",i2);
      TH1 *h;
      gDirectory.GetObject(hh,h);
      eff_sel_bb+=(h->GetBinContent(2)/h->GetBinContent(1))*jetspec[i2][i1];
      DEN+=h->GetBinContent(1)*(h_mudaB->GetEntries()/h_mudaB->Integral());   
    }
  }
  float eeff_sel_bb=sqrt((eff_sel_bb*(1-eff_sel_bb))/DEN);
  cout<<"mudaB (bb sel) "<<eff_sel_bb<<"+/-"<<eeff_sel_bb<<endl;


  //QQ SEL AVERAGE
  qq->cd(DIR);
  float eff_sel_qq=0;
  float DEN=0;
  for (int i1=0; i1<3; i1++){
    for (int i2=0; i2<3; i2++){
      sprintf(hh,"%s%d%s%d","h_muB_eta",i1,"_pt",i2);
      TH1 *h;
      gDirectory.GetObject(hh,h);
      eff_sel_qq+=(h->GetBinContent(2)/h->GetBinContent(1))*jetspec[i2][i1];
      DEN+=h->GetBinContent(1)*(h_mudaB->GetEntries()/h_mudaB->Integral());   
    }
  }
  float eeff_sel_qq=sqrt((eff_sel_qq*(1-eff_sel_qq))/DEN);
  cout<<"mudaQ (qq sel) "<<eff_sel_qq<<"+/-"<<eeff_sel_qq<<endl;
  
  //MU DA V
  tt->cd(DIR);
  float tW_eff=h_mudaW->GetBinContent(2)/h_mudaW->GetBinContent(1);
  float etW_eff=sqrt(tW_eff*(1-tW_eff)/(h_mudaW->GetBinContent(1)*(h_mudaW->GetEntries()/h_mudaW->Integral())));
  cout<<"mudaW (ttMC) "<<tW_eff<<"+\-"<<etW_eff<<endl;
  float etW_eff=h_eledaW->GetBinContent(2)/h_eledaW->GetBinContent(1);
  float eetW_eff=sqrt(etW_eff*(1-etW_eff)/(h_eledaW->GetBinContent(1)*(h_eledaW->GetEntries()/h_eledaW->Integral())));
  cout<<"eldaW (ttMC) "<<etW_eff<<"+\-"<<eetW_eff<<endl;
  
  zz->cd(DIR);
  float tW_eff=h_mudaZ->GetBinContent(2)/h_mudaZ->GetBinContent(1);
  float etW_eff=sqrt(tW_eff*(1-tW_eff)/(h_mudaZ->GetBinContent(1)*(h_mudaZ->GetEntries()/h_mudaZ->Integral())));
  cout<<"mudaZ (zzMC) "<<tW_eff<<"+\-"<<etW_eff<<endl;
  float etW_eff=h_eledaZ->GetBinContent(2)/h_eledaZ->GetBinContent(1);
  float eetW_eff=sqrt(etW_eff*(1-etW_eff)/(h_eledaZ->GetBinContent(1)*(h_eledaZ->GetEntries()/h_eledaZ->Integral())));
  cout<<"eldaZ (zzMC) "<<etW_eff<<"+\-"<<eetW_eff<<endl;

  delete bb;
  delete tt;
  delete zz;
}
