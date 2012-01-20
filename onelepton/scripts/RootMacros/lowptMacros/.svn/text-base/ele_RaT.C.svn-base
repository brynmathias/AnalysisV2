TString plot_dir = "eletree/";

TString selec = "Signal_";
TString aselec = "Control_";
TString plotting = "~/Plots/RaT/";
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v3) > 0";

TCut hbhe = "HBHENoise == 1";
TCut e_odd = "ElectronOdd ==0";
TCut nmu = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut trigData = trig && hbhe;
TCut secondEle = "NLElectrons < 2";
TCut looseMuon = "NLMuons == 0";

TCut ne = "NElectrons ==1";
TCut e_iso1 = "(ElectronRelCombIso[0]<0.06)";
TCut e_pt = "ElectronPt[0]<25.";
TCut e_dr = "ElectronClosestComJetDR[0] > 0.3";

TCut ele = ne && e_pt;

TCut npho = "NPhotons ==0";
TCut nj = "NJet >= 2";
TCut j1pt = "JetPt[1]>50.";
TCut jodd = "JetOdd ==0";
TCut bmu = "badMuonJet ==1";
TCut jeta1 = "JetEta[0] < 2.4";
TCut jeta2 = "JetEta[0] > -2.4";
TCut h250 = "HT > 250.";
TCut ht_250 = "HT_Lep > 250. && HT_Lep <= 300.";
TCut ht_300= "HT_Lep > 300. && HT_Lep <= 350.";
TCut ht_350 = "HT_Lep > 350.";
TCut alphat = "AlphaT_Lep > 0.55";
TCut preData = trig && h250 && hbhe;
TCut numlepData  = preData && sel && ele && secondEle && nmu && looseMuon;
TCut numlep = h250 && sel && ele && secondEle && nmu && looseMuon;
//TCut numlepX = sel && ele && e_odd && nmu && mu_odd;
TCut numpj = numlep && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;

//TCut numphoj = numpj && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjData = numlepData && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;


TCut reg1 = numpj && ht_250;
TCut reg2 = numpj && ht_300;
TCut reg3 = numpj && ht_350;

TCut reg1Data = numpjData && ht_250;
TCut reg2Data = numpjData && ht_300;
TCut reg3Data = numpjData && ht_350;

//TString aT = HT350 + " && AlphaT_Lep > 0.55";

TFile *sfLM0 = new TFile("eAlphaT_"+selec+"LM0.root");
TFile *sfLM1 = new TFile("eAlphaT_"+selec+"LM1.root");
TFile *sfTT = new TFile("eAlphaT_"+selec+"ttbarTauola.root");
TFile *sfQCDEM = new TFile("eAlphaT_"+selec+"QCDEM.root");
TFile *sfQCDBCE = new TFile("eAlphaT_"+selec+"QCDBCE.root");
TFile *sfQCD170 = new TFile("eAlphaT_"+selec+"QCD_All170.root");

TFile *sfW = new TFile("eAlphaT_"+selec+"Wjets_vols.root");
TFile *sfZ = new TFile("eAlphaT_"+selec+"ZJets_madgraph.root");
TFile *sfData = new TFile("eAlphaT_"+selec+"RA1Data.root");
//TFile *sfSM = new TFile("eAlphaT_"+selec+"SM.root");
//TFile *sfSUS = new TFile("eAlphaT_"+selec+"SUSLM0.root");

//TTree *stSUS = (TTree*)sfSUS->Get(plot_dir+"/T");
TTree *stLM0 = (TTree*)sfLM0->Get(plot_dir+"/T");
TTree *stLM1 = (TTree*)sfLM1->Get(plot_dir+"/T");
TTree *stTT = (TTree*)sfTT->Get(plot_dir+"/T");
TTree *stQCDEM = (TTree*)sfQCDEM->Get(plot_dir+"/T");
TTree *stQCDBCE = (TTree*)sfQCDBCE->Get(plot_dir+"/T");
TTree *stQCD170 = (TTree*)sfQCD170->Get(plot_dir+"/T");

TTree *stW = (TTree*)sfW->Get(plot_dir+"/T");
TTree *stZ = (TTree*)sfZ->Get(plot_dir+"/T");
TTree *stData = (TTree*)sfData->Get(plot_dir+"/T");
//TTree *stSM = (TTree*)sfSM->Get(plot_dir+"/T");

/*TFile *asfLM0 = new TFile("eAlphaT_"+aselec+"LM0.root");
TFile *asfLM1 = new TFile("eAlphaT_"+aselec+"LM1.root");
TFile *asfTT = new TFile("eAlphaT_"+aselec+"ttbarTauola.root");
TFile *asfQCD = new TFile("eAlphaT_"+aselec+"QCD_AllPtBins_7TeV_Pythia.root");
TFile *asfW = new TFile("eAlphaT_"+aselec+"Wjets_vols.root");
TFile *asfZ = new TFile("eAlphaT_"+aselec+"ZJets_madgraph.root");
TFile *asfData = new TFile("eAlphaT_"+aselec+"Data.root");
TFile *asfSM = new TFile("eAlphaT_"+aselec+"SM.root");
TTree *astLM0 = (TTree*)asfLM0->Get(plot_dir+"/T");
TTree *astLM1 = (TTree*)asfLM1->Get(plot_dir+"/T");
TTree *astTT = (TTree*)asfTT->Get(plot_dir+"/T");
TTree *astQCD = (TTree*)asfQCD->Get(plot_dir+"/T");
TTree *astW = (TTree*)asfW->Get(plot_dir+"/T");
TTree *astZ = (TTree*)asfZ->Get(plot_dir+"/T");
TTree *astData = (TTree*)asfData->Get(plot_dir+"/T");
TTree *astSM = (TTree*)asfSM->Get(plot_dir+"/T");
*/




Double_t intlumi = 35.;
TString luminum = "35.";

void ele_RaT(){

  // TH1D* all = GetHist("Data", "JetEta[0]",trigMC+numpj,"(12,0.,3.)",tData,"noHT");

  // SAS_RaTPlot(stData,astData,trigMC+numpj,"noHT");
  /*  SAS_RaTPlot(stSM,astSM,trigMC+numpj,"noHT","SM");
 SAS_RaTPlot(stSM,astSM,trigMC+numpj,"HT200","SM");
 SAS_RaTPlot(stSM,astSM,trigMC+numpj,"HT300","SM");
 SAS_RaTPlot(stSM,astSM,trigMC+numpj,"HT350","SM");
  */

 
  // SAS_RaTPlot(stSM,astSM,trigMC+numpj,"noHT","SM");



  /* NaT(stSM,astSM,trigMC+numpj,"noHT");


   NaT(stSM,astSM,trigMC+HT200,"HT>200");
   NaT(stSM,astSM,trigMC+HT300,"HT>300");
   NaT(stSM,astSM,trigMC+HT350,"HT>350");
  */
  HTRegionsRaT();
}

void HTRegionsRaT(){
gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  SetStyle();

  TGraphErrors *data = new TGraphErrors(3);
  TGraphErrors *SM = new TGraphErrors(3);

TGraphErrors *data51 = new TGraphErrors(3);
  TGraphErrors *SM51 = new TGraphErrors(3);


  Double_t data_250  = NumRaTData(reg1Data,55);
  Double_t data_300 = NumRaTData(reg2Data,55);
  Double_t data_350 = NumRaTData(reg3Data,55);
 Double_t SM_250 = NumRaTSM(reg1,55);
  Double_t SM_300 = NumRaTSM(reg2,55);
  Double_t SM_350 = NumRaTSM(reg3,55);

 Double_t data_e_250  = NumRaTDataErr(reg1Data,55);
  Double_t data_e_300 = NumRaTDataErr(reg2Data,55);
  Double_t data_e_350 = NumRaTDataErr(reg3Data,55);
 Double_t SM_e_250 = NumRaTSMErr(reg1,55);
 Double_t SM_e_300 = NumRaTSMErr(reg2,55);
 Double_t SM_e_350 = NumRaTSMErr(reg3,55);

  Double_t a51_data_250  = NumRaTData(reg1Data,51);
  Double_t a51_data_300 = NumRaTData(reg2Data,51);
  Double_t a51_data_350 = NumRaTData(reg3Data,51);
 Double_t a51_SM_250 = NumRaTSM(reg1,51);
  Double_t a51_SM_300 = NumRaTSM(reg2,51);
  Double_t a51_SM_350 = NumRaTSM(reg3,51);

 Double_t a51_data_e_250  = NumRaTDataErr(reg1Data,51);
  Double_t a51_data_e_300 = NumRaTDataErr(reg2Data,51);
  Double_t a51_data_e_350 = NumRaTDataErr(reg3Data,51);
 Double_t a51_SM_e_250 = NumRaTSMErr(reg1,51);
 Double_t a51_SM_e_300 = NumRaTSMErr(reg2,51);
 Double_t a51_SM_e_350 = NumRaTSMErr(reg3,51);


  data ->SetPoint(0,275.,data_250);
  data ->SetPointError(0,25.,data_e_250);
  data ->SetPoint(1,325.,data_300);
  data ->SetPointError(1,25.,data_e_300);
  data ->SetPoint(2,375.,data_350);
  data ->SetPointError(2,25.,data_e_350);

  SM->SetPoint(0,275.,SM_250);
  SM->SetPointError(0,25.,SM_e_250);
  SM->SetPoint(1,325.,SM_300);
  SM->SetPointError(1,25.,SM_e_300);
  SM->SetPoint(2,375.,SM_350);
  SM->SetPointError(2,25.,SM_e_350);

data51->SetPoint(0,275.,a51_data_250);
  data51->SetPointError(0,25.,a51_data_e_250);
  data51->SetPoint(1,325.,a51_data_300);
  data51->SetPointError(1,25.,a51_data_e_300);
  data51->SetPoint(2,375.,a51_data_350);
  data51->SetPointError(2,25.,a51_data_e_350);

  SM51->SetPoint(0,275.,a51_SM_250);
  SM51->SetPointError(0,25.,a51_SM_e_250);
  SM51->SetPoint(1,325.,a51_SM_300);
  SM51->SetPointError(1,25.,a51_SM_e_300);
  SM51->SetPoint(2,375.,a51_SM_350);
  SM51->SetPointError(2,25.,a51_SM_e_350);


  TCanvas *see = new TCanvas("see","see",800,800);
 SM->Draw("AP");
 data->Draw("P");
 // data51->Draw("P");
 // // SM51->Draw("P");
 SM->GetYaxis()->SetRangeUser(0.0001,1.0);

SM->GetXaxis()->SetRangeUser(250,400);

 SM->GetXaxis()->SetTitle("H_{T} Leptonic [GeV]");
 SM->GetYaxis()->SetTitle("R_{#alpha_{T}}");
 SM->GetXaxis()->SetTitleSize(0.04);
 SM->GetXaxis()->SetTitleOffset(1.1);
 see->SetLogy();
 SM->SetTitle("");
 SM->SetMarkerStyle(25);
 SM->SetMarkerColor(kRed);
 SM51->SetMarkerStyle(24);
 SM51->SetMarkerColor(kRed);
 data51->SetMarkerStyle(20);
 data51->SetMarkerColor(kBlack);
 data->SetMarkerStyle(21);
 data->SetMarkerColor(kBlack);
 TLegend *leg = new TLegend(0.65,0.65,0.8,0.8);
 leg->AddEntry(data,"Data, #alpha _{T} > 0.55","P");
 leg->AddEntry(SM,"SM, #alpha _{T} > 0.55","P");
 

 //leg->AddEntry(data51,"Data, #alpha _{T} > 0.51","P");
 //leg->AddEntry(SM51,"SM, #alpha _{T} > 0.51","P");
 leg->Draw("same");
}

Double_t NumRaTData(TCut region, UInt_t aT){
  UInt_t aTplus1 = aT + 1;
  UInt_t aTbin = aT;

  TH1D* data = GetaTHist(stData, region, "Data");
  Double_t above = data->Integral(aTplus1,data->GetNbinsX());
  Double_t below = data->Integral(0,aTbin);
  Double_t RaTArray;
  if(above > 0.){
  RaTArray = above/below;
  // RaTArray[1] = error(above,below);
  }
  else(){
  RaTArray = 0.;
  // RaTArray[1] = 0.;
       }


  return RaTArray;
}

Double_t NumRaTDataErr(TCut region,UInt_t aT){
  UInt_t aTplus1 = aT + 1;
  UInt_t aTbin = aT;

  TH1D* data = GetaTHist(stData, region, "Data");
  Double_t above = data->Integral(aTplus1,data->GetNbinsX());
  Double_t below = data->Integral(0,aTbin);
  Double_t RaTArray;
  if(above > 0.){
    RaTArray = error(above,below);
  // RaTArray[1] = error(above,below);
  }
  else(){
  RaTArray = 0.;
  // RaTArray[1] = 0.;
       }


  return RaTArray;
}

Double_t error(double a, double b) {

 TRandom rndm;
 rndm.SetSeed(12345);
 
 if (a<=0.000000001) return 0.;

 double eff = a/b;
 int n0 = rndm.Poisson((a+b));
 // int n1 = rndm.Binomial(n0,eff);

 double err=sqrt(eff*(1-eff)/n0);

 return err;
}
Double_t NumRaTSM(TCut region, UInt_t aT){
  UInt_t aTplus1 = aT + 1;
  UInt_t aTbin = aT;

  TH1D* QCDEM = GetaTHist(stQCDEM, region, "QCDEM");
TH1D* QCDBCE = GetaTHist(stQCDBCE, region, "QCDBCE");
TH1D* QCD170 = GetaTHist(stQCD170, region, "QCD170");

 TH1D* W = GetaTHist(stW, region, "W");
TH1D* tt= GetaTHist(stTT, region, "tt");
TH1D* Z = GetaTHist(stZ, region, "z");

W->Scale(1.29557302);
tt->Scale(1.65789474);
 Z->Scale(3048./2400.);
 TH1D* SM = QCDEM->Clone();
 SM->Add(QCDBCE);
 SM->Add(QCD170);
 SM->Add(W);
 SM->Add(Z);
 SM->Add(tt);

 // cout << "pass" << endl;
 Double_t above = SM->Integral(aTplus1,SM->GetNbinsX());
  Double_t below = SM->Integral(0,aTbin);
  Double_t RaTArray;
  RaTArray = above/below;
  //  RaTArray[1] = error(above,below);


  return RaTArray;


}

Double_t NumRaTSMErr(TCut region, UInt_t aT){
 
  UInt_t aTplus1 = aT+1;
  UInt_t aTbin = aT;

  TH1D* QCDEM = GetaTHist(stQCDEM, region, "QCDEM");
TH1D* QCDBCE = GetaTHist(stQCDBCE, region, "QCDBCE");
TH1D* QCD170 = GetaTHist(stQCD170, region, "QCD170");

 TH1D* W = GetaTHist(stW, region, "W");
TH1D* tt= GetaTHist(stTT, region, "tt");
TH1D* Z = GetaTHist(stZ, region, "z");

W->Scale(1.29557302);
tt->Scale(1.65789474);
 Z->Scale(3048./2400.);
 TH1D* SM = QCDEM->Clone();
 SM->Add(QCDBCE);
 SM->Add(QCD170);
 SM->Add(W);
 SM->Add(Z);
 SM->Add(tt);


 Double_t above = SM->Integral(aTplus1,SM->GetNbinsX());
  Double_t below = SM->Integral(0,aTbin);
  Double_t RaTArray;
  //  RaTArray[0] = above/below;
  RaTArray = error(above,below);


  return RaTArray;


}

  TH1D* GetaTHist(TTree* set, TCut flow, TString dataset){
  TH1::SetDefaultSumw2(true);
   
     
 TCanvas *c1 = new TCanvas("cannyaT"+dataset,"canneaT"+dataset,400,400);
  set->Draw("AlphaT_Lep>>hist(100,0.,1.)","(wgt)"*flow);
  TH1D *HIST= (TH1D*)gDirectory->Get("hist");
  HIST->SetName(dataset+"aT");
  c1->Close();
  // TH1::SetDefaultSumw2(true);
 


  if (dataset != "Data"){
    HIST->Scale(intlumi/10.);
  }
  return HIST;
}

void NaT(TTree *sel, TTree *asel,TString flow,TString point){

 TCanvas *c1 = new TCanvas("sel1","sell1",400,400);
 sel->Draw("AlphaT_Lep>>sely(100,0.,1.)","wgt*("+flow+")");
 TH1D *s_at= (TH1D*)gDirectory->Get("sely");
 s_at->SetName("one_aTSel");
 c1->Close();

 TCanvas *c2 = new TCanvas("asel1","asell1",400,400);
 asel->Draw("AlphaT_Lep>>asely(100,0.,1.)","wgt*("+flow+")");
 TH1D *as_at= (TH1D*)gDirectory->Get("asely");
 as_at->SetName("one_aTaSel");
 c2->Close();


  Double_t Ctrl_ratio = (as_at->Integral(55,as_at->GetNbinsX()))/(as_at->Integral(0,55));
  Double_t Sig_below = s_at->Integral(0,55);
  Double_t Sig_above = Ctrl_ratio * Sig_below;
  Double_t Actual_Sig_above = s_at->Integral(55,s_at->GetNbinsX());

  cout << endl;
  cout.width(122); cout.fill('-'); cout << "\n";

  cout << " The point at which this calculation is done is: " << point << endl;
  cout << endl;
 
  cout << " The ratio in the CTRL region is " << Ctrl_ratio << " and the number of events below aT 0.55 in SIG region is " << Sig_below << endl;
  cout << endl;
  cout << "Hence the number of predicted events in the SIG region with aT > 0.55 is " << Sig_above << " while the actual is " << Actual_Sig_above << endl;
cout << endl;
 cout.width(122); cout.fill('-'); cout << "\n";
 cout << endl;


}




void SAS_RaTPlot(TTree *t1, TTree *t2, TString flow, TString point, TString set){
gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  SetStyle();



  TH1D *s = RaT(t1,kRed,flow,point,"S",set);
  TH1D *as = RaT(t2,kBlack,flow,point,"AS",set);

TCanvas *c7 = new TCanvas ("SAS"+point+set,"SAS"+point+set);
 TLegend *leg = new TLegend(0.7,0.7,0.99,0.99);
 leg->AddEntry(s,"Selected","LP");
 leg->AddEntry(as,"Anti-Selected","LP");
 s->Draw("E");
 gPad->SetGridx(); gPad->SetGridy();
 as->Draw("ESAME");
 s->SetTitle();
 s->GetXaxis()->SetTitle("|#eta | leading jet");
 s->GetYaxis()->SetTitle("N(above aT 0.55) / N(all)");
 s->GetYaxis()->SetTitleOffset(1.2);
 leg->Draw("SAME");
 c7->Update();
 c7->SaveAs(plotting+"ELEC_RaT_"+set+"_"+point+".png");

}



void HT_RaTPlot(TTree *t1, TString sel, TString set){
gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  SetStyle();



  TH1D *noHT = RaT(t1,kRed,trigMC+numpj,"noHT",sel,set);
   TH1D *HT200 = RaT(t1,kBlack,trigMC+HT200,"HT200",sel,set);
   TH1D *HT300= RaT(t1,kGreen,trigMC+HT300,"HT300",sel,set);
   TH1D *HT350 = RaT(t1,kBlue,trigMC+HT350,"HT350",sel,set);

TCanvas *c7 = new TCanvas ("SAS"+sel+set,"SAS"+sel+set);
 TLegend *leg = new TLegend(0.7,0.7,0.99,0.99);
 leg->AddEntry(noHT,"noHT","LP");
 leg->AddEntry(HT200,"HT > 200","LP");
 leg->AddEntry(HT300,"HT > 300","LP");
 leg->AddEntry(HT350,"HT > 350","LP");
 noHT->Draw("E");
 gPad->SetGridx(); gPad->SetGridy();
 HT200->Draw("ESAME");
 HT300->Draw("ESAME");
 HT350->Draw("ESAME");

 HT200->SetTitle();
 HT200->GetXaxis()->SetTitle("|#eta | leading jet");
 HT200->GetYaxis()->SetTitle("N(above aT 0.55) / N(all)");
 HT200->GetYaxis()->SetTitleOffset(1.2);
 leg->Draw("SAME");
 c7->Update();
 c7->SaveAs(plotting+"RaT_HTbins_"+set+"_"+sel+".png");

}

TH1D* RaT(TTree* t,Color_t icol,TString cuts,TString point,TString iden, TString iden2){

 TH1::SetDefaultSumw2(true);
    TH1D* above = GetHist("SData",cuts,t,point, "Above");
  TH1D* all = GetHist("SData",cuts,t,point, "All");



  double err[6];
  // double rbin = 2;
  //  all->Rebin(rbin); above->Rebin(rbin);
  TH1D *Ratio = new TH1D("Ratio","Ratio",6,0.,2.5);
  Ratio->SetName(iden+iden2+point);
  Ratio->Divide(above,all,1.,1.,"B");

 


 for (UInt_t i=0; i<6; i++){
   err[i] = error(above->GetBinContent(i+1),all->GetBinContent(i+1));
     Ratio->SetBinError(i+1,err[i]);

		}

 Ratio->SetLineColor(icol);
      Ratio->SetLineWidth(3);

 TH1::SetDefaultSumw2(true);
      return Ratio;

}



TH1D* GetHist(TString dataset, TString flow,TTree *t, TString poin, TString type){
 
  if(type == "All"){
     
 TCanvas *c1 = new TCanvas("canny1","canne1",400,400);
 t->Draw("JetEta[0]>>hist1(6,0.,2.5)","10*wgt*("+flow+")");
 TH1D *HIST1= (TH1D*)gDirectory->Get("hist1");
  HIST1->SetName("one_"+dataset+"JetEtaFabs"+poin+type);
 c1->Close();

 TCanvas *c2= new TCanvas("canny2","canne2",400,400);
  t->Draw("-1*JetEta[0]>>hist2(6,0.,2.5)","10*wgt*("+flow+")");
  TH1D *HIST2= (TH1D*)gDirectory->Get("hist2");
   HIST2->SetName("two_"+dataset+"JetEtaFabs"+poin+type);
   c2->Close();
  }



  else if(type == "Above"){


 TCanvas *c1 = new TCanvas("canny1","canne1",400,400);
 t->Draw("JetEta[0]>>hist1(6,0.,2.5)","10*wgt*("+flow+" && AlphaT_Lep > 0.55)");
 TH1D *HIST1= (TH1D*)gDirectory->Get("hist1");
  HIST1->SetName("one_"+dataset+"JetEtaFabs"+poin+type);
 c1->Close();

  TCanvas *c2= new TCanvas("canny2","canne2",400,400);
  t->Draw("-1*JetEta[0]>>hist2(6,0.,2.5)","10*wgt*("+flow+" && AlphaT_Lep > 0.55)");
  TH1D *HIST2= (TH1D*)gDirectory->Get("hist2");
   HIST2->SetName("two_"+dataset+"JetEtaFabs"+poin+type);
  c2->Close();

  }
 else if(type == "Below"){


 TCanvas *c1 = new TCanvas("canny1","canne1",400,400);
 t1->Draw("JetEta[0]>>hist1(6,0.,2.5)","10*wgt*("+flow+" && AlphaT_Lep < 0.55)");
 TH1D *HIST1= (TH1D*)gDirectory->Get("hist1");
  HIST1->SetName("one_"+dataset+"JetEtaFabs"+poin+type);
 c1->Close();

  TCanvas *c2= new TCanvas("canny2","canne2",400,400);
  t2->Draw("-1*JetEta[0]>>hist2(6,0.,2.5)","10*wgt*("+flow+" && AlphaT_Lep < 0.55)");
  TH1D *HIST2= (TH1D*)gDirectory->Get("hist2");
  HIST2->SetName("two_"+dataset+"JetEtaFabs"+poin+type);
  c2->Close();
 }


   TH1D *HIST = (TH1D*)HIST1->Clone();
   HIST->SetName("Full_"+dataset+type);
   HIST->Add(HIST2);

  return HIST;





}

void SetStyle(){

  gROOT->SetStyle("Plain"); 
			      gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(0);
			      gStyle->SetOptStat(1110);
							 gStyle->SetLabelOffset(0.001);
  gStyle->SetLabelSize(0.05);
  gStyle->SetLabelSize(0.05,"Y");#Y axis
				   gStyle->SetTitleSize(0.06);
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
 gStyle->SetHatchesLineWidth(3);

}
double error(double a, double b) {

 TRandom rndm;
 rndm.SetSeed(12345);
 
 if (a<=0.000000001) return 0.;

 double eff = a/b;
 int n0 = rndm.Poisson((a+b));
 // int n1 = rndm.Binomial(n0,eff);

 double err=sqrt(eff*(1-eff)/n0);

 return err;
}
