TString plot_dir = "eletree";

TString plots = "~/Plots/MCD34pb/JanUpdate/";

//TCut trig = "trig_Jet50 ==1";
TCut h_j_pt = "(High_Jet_Pt > 70.)";
TCut e_odd = "ElectronOdd ==0";
TCut nmu = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v3) > 0";

TCut secondEle = "NLElectrons < 2";
TCut looseMuon = "NLMuons == 0";
TCut trigData = trig && hbhe;

TCut ne = "NElectrons ==1";
TCut e_iso1 = "ElectronRelCombIso[0]<0.06";
TCut e_pt = "ElectronPt[0]<25.";
TCut e_dr = "ElectronClosestComJetDR[0] > 0.3";

TCut ne2 = "NElectrons ==2";
TCut e_noiso2 = "ElectronRelCombIso[1]>0.06";
TCut e_noiso1 = "ElectronRelCombIso[0]>0.06"; 
TCut e_iso2 = "ElectronRelCombIso[1]<0.06"; 
TCut e_pt2 = "ElectronPt[1]<25.";
TCut e_dr2 = "ElectronClosestComJetDR[1] > 0.3";
TCut e_nodr2 = "ElectronClosestComJetDR[1] > 0";
TCut e_nopt2 = "ElectronPt[1]<100000.";
TCut e_nodr = "ElectronClosestComJetDR[0] > 0";
TCut e_nopt = "ElectronPt[0]<100000.";

TCut ele1 = ne && e_iso1 && e_noiso2 && e_pt && e_dr &&  e_nodr2 && e_nopt2;
TCut ele2a = ne2 && e_iso1 && e_noiso2 &&  e_pt && e_dr &&  e_nodr2 && e_nopt2;
TCut ele2b = ne2 && e_noiso1 && e_iso2 && e_nopt && e_nodr && e_dr2 && e_pt2;


TCut ele =ne && e_pt;
TCut npho = "NPhotons ==0";
TCut nj = "NJet >= 2";
TCut j1pt = "JetPt[1]>50.";
TCut jodd = "JetOdd ==0";
TCut bmu = "badMuonJet ==1";
TCut jeta1 = "JetEta[0] < 2.4";
TCut jeta2 = "JetEta[0] > -2.4";

TCut h200 = "HT_Lep > 200.";
TCut h300 = "HT_Lep > 300.";
TCut h350 = "HT_Lep > 350.";
TCut alphat = "AlphaT_Lep > 0.55";

TCut h250 = "HT > 250.";
TCut htt300 = "HT > 300.";
TCut ht200 = "HT>200.";

TCut preData = trig && h250 && hbhe;
TCut numlepData  = preData && sel && ele && secondEle && nmu && looseMuon;
TCut numlep = h250 && sel && ele && secondEle && nmu && looseMuon;

TCut numpj = numlep && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjData = numlepData && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;



TCut HT200 = numpj && h200;
TCut HT300 = numpj && h300;
TCut HT350 = numpj && h350;
TCut aT = HT350 && alphat;


TCut HT200Data = numpjData && h200;
TCut HT300Data = numpjData && h300;
TCut HT350Data = numpjData && h350;
TCut aTData = HT350Data && alphat;

//TFile *sfQCD = new TFile("eAlphaT_Signal_QCD.root");
//TFile *asfQCD = new TFile("eAlphaT_Control_QCD.root");

//TTree *stQCD = (TTree*)sfQCD->Get(plot_dir+"/T");
//TTree *astQCD = (TTree*)asfQCD->Get(plot_dir+"/T");

TFile *sfQCDem = new TFile("eAlphaT_Signal_QCDEM.root");
TFile *asfQCDem = new TFile("eAlphaT_Control_QCDEM.root");

TTree *stQCDem = (TTree*)sfQCDem->Get(plot_dir+"/T");
TTree *astQCDem = (TTree*)asfQCDem->Get(plot_dir+"/T");

TFile *sfQCDbce = new TFile("eAlphaT_Signal_QCDBCE.root");
TFile *asfQCDbce = new TFile("eAlphaT_Control_QCDBCE.root");

TTree *stQCDbce = (TTree*)sfQCDbce->Get(plot_dir+"/T");
TTree *astQCDbce = (TTree*)asfQCDbce->Get(plot_dir+"/T");

TFile *sfQCD170 = new TFile("eAlphaT_Signal_QCD_All170.root");
TFile *asfQCD170 = new TFile("eAlphaT_Control_QCD_All170.root");

TTree *stQCD170 = (TTree*)sfQCD170->Get(plot_dir+"/T");
TTree *astQCD170 = (TTree*)asfQCD170->Get(plot_dir+"/T");



TFile *sfData = new TFile("eAlphaT_Signal_Data_34.root");
TFile *asfData = new TFile("eAlphaT_Control_Data_34.root");

TTree *stData = (TTree*)sfData->Get(plot_dir+"/T");
TTree *astData = (TTree*)asfData->Get(plot_dir+"/T");

Double_t intlumi = 3.47;
TString luminum = "34.7";

void ele_SAS(){
     Plotting(numpj,"noHT");
     //Plotting(HT200,"HT200");
     //     Plotting(HT300,"HT300");
         Plotting(HT350,"HT350");
  
 
}
void Plotting(TCut cuts, TString poins){

 control("AlphaT_Lep","(20,0.3,0.7)",cuts,poins,true,1000);
 /* control("ElectronPt[0]","(8,0,30)",cuts,poins,true,1000);
  control("ElectronEta[0]","(10,-3.,3.)",cuts,poins,true,1000);
  control("ElectronPhi[0]","(20,-5.,5.)",cuts,poins,true,1000);
  control("NJet","(10,-0.5,9.5)",cuts,poins,false,1000);
  control("JetPt[0]","(30,50,1000)",cuts,poins,true,1000);
 control("JetEta[0]","(10,-3.,3.)",cuts,poins,true,1000);
 control("JetPhi[0]","(10,-4.,4.)",cuts,poins,true,1000);
  control("JetPt[1]","(20,50,1000)",cuts,poins,true,1000);
 control("JetEta[1]","(10,-3.,3.)",cuts,poins,true,1000);
 control("JetPhi[1]","(10,-4.,4.)",cuts,poins,true,1000);
  control("JetPt[2]","(20,50,1000)",cuts,poins,true,1000);
 control("JetEta[2]","(10,-3.,3.)",cuts,poins,true,1000);
 control("JetPhi[2]","(10,-4.,4.)",cuts,poins,true,1000);
  control("HT","(10,100.,1000.)",cuts,poins,true,1000);
 control("HT_Lep","(10,100.,1000.)",cuts,poins,true,1000);
 control("MHT","(20,0.,250.)",cuts,poins,true,1000);

  control("PFMHT","(20,0.,250.)",cuts,poins,true,1000);
 control("RecoilMET","(20,0.,300.)",cuts,poins,true,1000);
 control("PFMET","(20,0.,200.)",cuts,poins,true,1000);
 control("PFLP","(20,-1.,2.)",cuts,poins,true,1000);
 control("Meff","(10,100.,1500.)",cuts,poins,true,1000);

 control("ElectronClosestComJetDR[0]","(14,0.,4.2)",cuts,poins,true,1000);
 */
}

void control(TString var,TString bin, TCut cuts, TString cutpoint,bool log,Double_t ymax){
  setstyle();
  TH1::SetDefaultSumw2(true);
  TCanvas *c2 = new TCanvas("canvas"+var+cutpoint,"canname"+var+cutpoint,700,800);

  TPad *mainPad = new TPad("","",0.01,0.25,0.99,0.99);
  mainPad->SetNumber(1);
  mainPad->Draw();
  TPad *ratioPad = new TPad("","",0.01,0.01,0.99,0.25);
  ratioPad->SetNumber(2);
  ratioPad->Draw();

  TH1D *Ctrl_em = GetHist("AS",kBlack,var,cuts,bin,astQCDem,cutpoint);
  TH1D *Sig_em = GetHist("S",kRed,var,cuts,bin,stQCDem,cutpoint);


  TH1D *Ctrl_170 = GetHist("AS",kBlack,var,cuts,bin,astQCD170,cutpoint);
  TH1D *Sig_170 = GetHist("S",kRed,var,cuts,bin,stQCD170,cutpoint);


  TH1D *Ctrl_bce = GetHist("AS",kBlack,var,cuts,bin,astQCDbce,cutpoint);
  TH1D *Sig_bce = GetHist("S",kRed,var,cuts,bin,stQCDbce,cutpoint);


  //Ctrl_em->Scale(1.5);
  //  Sig_em->Scale(1.5);
  //  Ctrl_170->Scale(3.07);
  // Sig_170->Scale(4.35);

  Ctrl_bce->Add(Ctrl_em);
  Ctrl_bce->Add(Ctrl_170);

  Sig_bce->Add(Sig_em);
  Sig_bce->Add(Sig_170);

  TH1D *Ctrl = Ctrl_bce->Clone();
  TH1D *Sig = Sig_bce->Clone();

  //TH1D *Ctrl2 = GetHist("AS",kBlack,var,cuts,bin,astQCDbce,cutpoint);
  // TH1D *Sig2 = GetHist("S",kRed,var,cuts,bin,stQCDbce,cutpoint);


  //TH1D *Ctrl3 = GetHist("AS",kBlack,var,cuts,bin,astQCD170,cutpoint);
  //TH1D *Sig3 = GetHist("S",kRed,var,cuts,bin,stQCD170,cutpoint);

  // Ctrl->Scale(intlumi);
    Sig->Scale(intlumi);



  // TH1D *Ctrl = GetHist("AS",kBlack,var,cuts,bin,astQCD,cutpoint);
  if(Ctrl->Integral()!=0){
    Ctrl->Scale(Sig->Integral()/Ctrl->Integral());
  }
  c2->cd(1);
  if(log){ c2->cd(1)->SetLogy();}
  
  TLegend *leg = new TLegend(0.564,0.719,0.775,0.875);
  leg->SetTextSize(0.054);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  leg->AddEntry(Sig,"Selected","LP");
  leg->AddEntry(Ctrl,"Anti-Selected","LF");
  //  leg->AddEntry(Ctrl,"Anti-Selected","LF");

  Ctrl->Draw("EHIST9"); Sig->Draw("E9SAME"); 
  Sig->SetMarkerStyle(20); Sig->SetMarkerColor(kRed);

  leg->Draw("same");
  Ctrl->SetTitle();
  Ctrl->GetXaxis()->SetTitle(var);
  
  ymax=(Ctrl->GetMaximum()*10.6);
  if (log) {
    Ctrl->GetYaxis()->SetRangeUser(0.01,ymax);
  } else {
     ymax=(Ctrl->GetMaximum()*1.6);
     Ctrl->GetYaxis()->SetRangeUser(0.,ymax);
  }
  TH1D *RatioBottom = (TH1D*)Ctrl->Clone("Ratiob");
  TH1D *RatioTop = (TH1D*)Sig->Clone("Ratiot");

  RatioTop->GetYaxis()->SetTitle("Selected / Anti-Selected");
  RatioTop->GetXaxis()->SetTitle();
  RatioTop->SetTitle();
  RatioTop->Divide(RatioBottom);
  
  c2->cd(2);
  gPad->SetGridx(); gPad->SetGridy();
  RatioTop->SetTitleSize(0.1, "XYZ");
  RatioTop->SetTitleOffset(0.55, "X");
  RatioTop->SetTitleOffset(0.3, "Y");
  RatioTop->SetLabelSize(0.06,"XY");
  RatioTop->GetYaxis()->SetRangeUser(-2.,5.0);
  RatioTop->SetLineColor(kBlack);
  RatioTop->Draw();
  TBox *unity = new TBox(RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetFirst()), 0.79,RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetLast()), 1.21);
  unity->SetLineWidth(2);
  unity->SetLineColor(2);
  unity->SetFillColor(2);
  unity->SetFillStyle(3002);
  unity->Draw();
  c2->Update();
  c2->SaveAs(plots+"SAS_Elec_10to25"+var+"_"+cutpoint+".png");
  // c2->Close();
}


TH1D* GetHist(TString dataset, Color_t col, TString var, TCut flow,TString bin,TTree *t, TString poin){
 
  TCanvas *c1 = new TCanvas("canny"+var+dataset,"canne"+var+dataset,400,400);
  t->Draw(var+">>hist"+bin,"(wgt)"*flow);
  TH1D *HIST= (TH1D*)gDirectory->Get("hist");
  HIST->SetName(dataset+var+poin);
  c1->Close();
  if (dataset == "AS"){
 HIST->SetFillStyle(3002);
 HIST->SetFillColor(kGray+2);
  HIST->SetLineWidth(2);
  }
  else{
  HIST->SetLineWidth(3);

  }
 HIST->SetLineColor(col);

  return HIST;
}

void setstyle(){
  gROOT->SetBatch(kTRUE);
  gROOT->SetStyle("Plain");
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(0);
  gStyle->SetOptStat(1110);
  gStyle->SetLabelOffset(0.001);
  gStyle->SetLabelSize(0.05);
  gStyle->SetLabelSize(0.05,"Y");
  gStyle->SetTitleSize(0.05);
  //  gStyle->SetTitleOffset(0.04);
  gStyle->SetTitleW(0.7);
  gStyle->SetTitleH(0.07);
  gStyle->SetOptTitle(1);
  gStyle->SetOptStat(0);
gStyle->SetAxisColor(1, "XYZ");
gStyle->SetStripDecimals(kTRUE);
gStyle->SetTickLength(0.03, "XYZ");
gStyle->SetNdivisions(510, "XYZ");
gStyle->SetPadTickX(1);
gStyle->SetPadTickY(1);
gStyle->SetLabelColor(1, "XYZ");
gStyle->SetLabelFont(42, "XYZ");
gStyle->SetLabelOffset(0.007, "XYZ");
gStyle->SetLabelSize(0.05, "XYZ");
 gStyle->SetHatchesLineWidth(3);}
