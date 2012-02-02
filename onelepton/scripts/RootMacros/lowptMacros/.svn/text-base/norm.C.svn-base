TString plot_dir = "eletree";
TString selec = "Signal_";

TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v3)>0";
//" + trig_HT150v1 + trig_HT150v3 + trig_HT160v1 + trig_HT160v3) > 0";



TCut h_j_pt = "(High_Jet_Pt > 70.)";
TCut e_odd = "ElectronOdd ==0";
TCut nmu = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";

TCut trigData = trig && hbhe;

TCut ne = "NElectrons ==1";
TCut e_pt = "ElectronPt[0]<25.";


TCut secondEle = "NLElectrons < 2";
TCut looseMuon = "NLMuons == 0";


TCut ele = ne && e_pt;
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
TCut h250 = "HT > 300.";


TCut numlepData = trig && h250 && hbhe && sel && h_j_pt && ele && e_odd && nmu && mu_odd && secondEle && looseMuon;
TCut numlep = h250 && sel && h_j_pt && ele && e_odd && nmu && mu_odd && secondEle && looseMuon;
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


 TFile *fLM0 = new TFile("eAlphaT_"+selec+"LM0.root");
TFile *fLM1 = new TFile("eAlphaT_"+selec+"LM1.root");
TFile *fTT = new TFile("eAlphaT_"+selec+"ttbarTauola.root");
TFile *fQCDem = new TFile("eAlphaT_"+selec+"QCDEM.root");
TFile *fQCDbce = new TFile("eAlphaT_"+selec+"QCDBCE.root");
TFile *fQCD170 = new TFile("eAlphaT_"+selec+"QCD170.root");
TFile *fW = new TFile("eAlphaT_"+selec+"Wjets_vols.root");
TFile *fZ = new TFile("eAlphaT_"+selec+"ZJets_madgraph.root");
TFile *fData = new TFile("eAlphaT_"+selec+"Data_34.root");
TTree *tLM0 = (TTree*)fLM0->Get(plot_dir+"/T");
TTree *tLM1 = (TTree*)fLM1->Get(plot_dir+"/T");
TTree *tTT = (TTree*)fTT->Get(plot_dir+"/T");
TTree *tQCDem = (TTree*)fQCDem->Get(plot_dir+"/T");
TTree *tQCDbce = (TTree*)fQCDbce->Get(plot_dir+"/T");
TTree *tQCD170 = (TTree*)fQCD170->Get(plot_dir+"/T");
TTree *tW = (TTree*)fW->Get(plot_dir+"/T");
TTree *tZ = (TTree*)fZ->Get(plot_dir+"/T");
TTree *tData = (TTree*)fData->Get(plot_dir+"/T");

Double_t intlumi = 34.7;
TString luminum = "15.740";
void norm(){
   
  
    TH1D* qcdem = GetHist("QCDEM",kOrange+4,"PFMET",numpj,"(20.,0.,200.)",tQCDem,"HT200");
  TH1D* qcdbce = GetHist("QCDBCE",kRed,"PFMET",numpj,"(20.,0.,200.)",tQCDbce,"HT200");
TH1D* qcd170 = GetHist("QCD_All170",kRed,"PFMET",numpj,"(20.,0.,200.)",tQCD170,"HT200");
  TH1D* data = GetHist("Data",1,"PFMET",numpjData,"(20.,0.,200.)",tData,"HT200");
  TH1D* W = GetHist("Wjets_vols",kBlue,"PFMET",numpj,"(20.,0.,200.)",tW,"HT200");
  TH1D* tt = GetHist("ttbarTauola",kGreen,"PFMET",numpj,"(20.,0.,200.)",tTT,"HT200");
  TH1D* Z = GetHist("ZJets_madgraph",kYellow,"PFMET",numpj,"(20.,0.,200.)",tZ,"H T200");


 W->Scale(1.29557302);
 tt->Scale(1.65789474);
 Z->Scale(3048./2400.);
  qcdem->Scale(1.5);
 qcdbce->Scale(1.2);
  //MCwoEM->Add(W);
  //MCwoEM->Add(tt);
  //MCwoEM->Add(Z);
 TH1D* QCD = qcdbce->Clone();
 QCD->Add(qcd170);
 QCD->Add(qcdem);


  TH1D* EWK = W->Clone();
  EWK->Add(Z);
  EWK->Add(tt);

 TH1D* MCwoEM = qcdem->Clone();
  MCwoEM->Add(qcdbce);
  MCwoEM->Add(EWK);

 double factor = 1;
 UInt_t step =0;
 double chi2min = chitwo(data, MCwoEM, qcd170,1.);
 // double eye = 1+9/10.;
 // cout << eye << endl;
 // double chi2min2 = chitwo(data, MCwoEM, qcdem,eye);
   for(int i=1; i<1000; i++){
   double fac_i = 1+i/100.;
   double chi2_i = chitwo(data, MCwoEM, qcd170,fac_i);
 
   if(chi2_i < chi2min){
     chi2min = chi2_i;
     factor = fac_i;
     step = i;
   }
   //   cout << " Step is " << i << " and so factor is " << fac_i << " and the Chisq is : " << chi2_i << " and the chimin is " << chi2min << endl;
 }

 cout << " The minimum reached at step " << step << " and the chi2 here is " << chi2min << " when using a factor of " << factor << endl;
  
}

TH1D* GetHist(TString dataset, Color_t col, TString var, TCut flow,TString bin,TTree *t, TString poin){
 
   
     
  TCanvas *c1 = new TCanvas("canny"+dataset+var,"canne"+dataset+var,400,400);
  t->Draw(var+">>hist"+bin,"(wgt)"*flow);
  TH1D *HIST= (TH1D*)gDirectory->Get("hist");
  HIST->SetName(dataset+var+poin);
  c1->Close();

 



  if (dataset != "Data"){
    HIST->Scale(intlumi/10.);
     if (dataset == "Wjets_vols") { 
       //   HIST->Scale((31314./24170.)); 
     } else if (dataset == "ttbarTauola") { 
       // HIST->Scale(157.7/95.); 
   } 
else if (dataset == "ZJets_madgraph") { 
  // HIST->Scale(3048./2400.); 
 }
    
  }
  return HIST;
}
double chitwo(TH1D* h_data, TH1D* h_MClessEM, TH1D* h_em, double factor){

  TH1D* EM = h_em->Clone();
  TH1D* MC = h_MClessEM->Clone();
  TH1D*  Data = h_data->Clone();
  EM->Scale(factor);

  MC->Add(EM);
   
  double CHIble = 0;
  for(UInt_t i=1; i <= MC->GetNbinsX(); i++){
    if(Data->GetBinContent(i)>10){

     
    double ChiStep = ((Data->GetBinContent(i) - MC->GetBinContent(i))*(Data->GetBinContent(i) - MC->GetBinContent(i)))/Data->GetBinContent(i);

    CHIble+=ChiStep;

    //  cout <<" The Bin is "  << i <<  " where Data " << Data->GetBinContent(i) << " and MC " << MC->GetBinContent(i) << " Gives CHi2 " << ChiStep << " so Chi2ble is " << CHIble << endl;
}

  }

  return CHIble;

}
