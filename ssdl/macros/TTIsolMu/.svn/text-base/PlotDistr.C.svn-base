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
  //file
  
  TString DIR ="TTBkg";


  TCanvas *c1= new TCanvas("c1","Combined Isolation",1000,700);
  c1->Divide(3,3);



 
  vector<string> title;
  title.push_back("Pt < 40 GeV  |#eta|<0.7");
  title.push_back("Pt < 40 GeV  0.7<|#eta|<1.4");
  title.push_back("Pt < 40 GeV  1.4<|#eta|<2.1");
  title.push_back("40< Pt < 80 GeV  |#eta|<0.7");
  title.push_back("40< Pt < 80 GeV  0.7<|#eta|<1.4");
  title.push_back("40< Pt < 80 GeV  1.4<|#eta|<2.1");
  title.push_back("Pt >80 GeV  |#eta|<0.7");
  title.push_back("Pt >80 GeV  0.7<|#eta|<1.4");
  title.push_back("Pt >80 GeV  1.4<|#eta|<2.1");


  TH1 *h; 
  char hh[20];
  for (int i1=0; i1<3; i1++){
    for (int i2=0; i2<3; i2++){
      c1->cd(i1*3+i2+1);
      tt->cd(DIR);
      sprintf(hh,"%s%d%s%d","h_CombIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      h->Scale(1/h->Integral());
      h->SetTitle(title[i1*3+i2].c_str());
      h->Draw();
      bb->cd(DIR);
      sprintf(hh,"%s%d%s%d","h_CombIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      h->Scale(1/h->Integral());
      h->SetLineColor(2);
      h->Draw("same"); 
      sprintf(hh,"%s%d%s%d","h_selCombIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      h->Scale(1/h->Integral());
      h->SetLineColor(4);
      h->Draw("same");  
      qq->cd(DIR);
      sprintf(hh,"%s%d%s%d","h_selCombIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      if (h->Integral()>0)
       h->Scale(1/h->Integral());
      h->SetLineColor(6);
      h->Draw("same");        

    }
  }


  TCanvas *c2= new TCanvas("c1","Tracker Isolation",1000,700);
  c2->Divide(3,3);
  TH1 *h; 
  char hh[20];
  for (int i1=0; i1<3; i1++){
    for (int i2=0; i2<3; i2++){
      c2->cd(i1*3+i2+1);
      tt->cd(DIR);
      sprintf(hh,"%s%d%s%d","h_TrkIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      h->Scale(1/h->Integral());
      h->SetTitle(title[i1*3+i2].c_str());
      h->Draw();
      bb->cd(DIR);
      sprintf(hh,"%s%d%s%d","h_TrkIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      h->Scale(1/h->Integral());
      h->SetLineColor(2);
      h->Draw("same"); 
      sprintf(hh,"%s%d%s%d","h_selTrkIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      h->Scale(1/h->Integral());
      h->SetLineColor(4);
      h->Draw("same");  
      qq->cd(DIR);
      sprintf(hh,"%s%d%s%d","h_selTrkIso_eta",i1,"_pt",i2);
      gDirectory.GetObject(hh,h);
      if (h->Integral()>0)
	h->Scale(1/h->Integral());
      h->SetLineColor(6);
      h->Draw("same");  
 
    }
  }



}
