TString e_plot_dir = "eletree/";
TString mu_plot_dir = "mutree_iso/";
TString filesused  = "Standard_Objects";
TString ptrange = "infininty";
TString sele = "Signal_";

TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v3) > 0";


TCut h_j_pt = "(High_Jet_Pt > 70.)";
TCut e_odd = "ElectronOdd ==0";
TCut nmu_0 = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";
TCut secondEle = "NLElectrons < 2";
TCut looseMuon = "NLMuons == 0";
TCut secondMuon = "NLMuons < 2";
TCut looseEle = "NLElectrons == 0";

TCut ne_0 = "NElectrons == 0";
TCut nmu = "NMuons ==1";
TCut mu_pt = "MuonPt[0] >10.";
// && MuonPt[0] < 25.";



TCut trigData = trig && hbhe;

  //  else if (echan == "muAlph
TCut ne = "NElectrons ==1";
TCut e_pt = "ElectronPt[0] >10.";
// && ElectronPt[0] < 25.";
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
TCut h250 = "HT > 300.";
TCut alphat = "AlphaT_Lep > 0.55";


TCut e_noht = h250 && sel && h_j_pt && ne && e_pt && secondEle && nmu_0 && looseMuon && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && alphat;

TCut e_all = h250 && sel && h_j_pt && ne && e_pt && secondEle && nmu_0 && looseMuon && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && alphat && h350;


TCut e_nonjet = h250 && sel && h_j_pt && ne && e_pt && secondEle && nmu_0 && looseMuon && npho && j1pt && jodd && bmu && jeta1 && jeta2 && h350 && alphat;
//TCut e_nonjet_50 = h250 && sel && h_j_pt && ne && e_pt && secondEle && nmu_0 && looseMuon && npho && j1pt && jodd && bmu && jeta1 && jeta2 && h350 && alphat && JetPt[1]>50.;
TCut e_nomeff = h250 && sel && h_j_pt && ne && e_pt && secondEle && nmu_0 && looseMuon && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && alphat;


TCut mu_noht = h250 && sel && h_j_pt && nmu && mu_pt && secondMuon && ne_0 && looseEle && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && alphat;

TCut mu_nonjet = h250 && sel && h_j_pt && nmu && mu_pt && secondMuon && ne_0 && looseEle && npho && j1pt && jodd && bmu && jeta1 && jeta2 && h350 && alphat;
//TCut mu_nonjet_50 = h250 && sel && h_j_pt && nmu && mu_pt && secondMuon && ne_0 && looseEle && npho && j1pt && jodd && bmu && jeta1 && jeta2 && h350 && alphat && JetPt[1];

TCut mu_nomeff = h250 && sel && h_j_pt && nmu && mu_pt && secondMuon && ne_0 && looseEle && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && alphat;
TCut mu_all = h250 && sel && h_j_pt && nmu && mu_pt && secondMuon && ne_0 && looseEle && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && alphat && h350;

TString ht = "HT > ";
TString meff = "Meff > ";
TString njety = "NJet >= ";
TString MT = "PFMT > ";

//Double_t lumi = 10.000;

TString echan = "eAlphaT_";

TString muchan = "muAlphaT_";
void CutOpt(){
  //   OptCurves(e_nonjet, mu_nonjet, njety,"NJET_30",4,1,2,10);
  // OptCurves(e_nonjet, mu_nonjet, njety,"NJET_50",4,1,2,10);
  ///
  //   OptCurves(e_noht, mu_noht, ht,"HT_",5,50,300,10);
  //  OptCurves(e_noht, mu_noht, meff,"MEFF_",5,100,500,10);
  //TFile *f=new TFile("eAlphaT_Signal_QCDEM.root");
 OptCurves(e_all, mu_all, MT,"MT_",20,10,0,10);
  //  if (echan == "eAlphaT_"){
  //     TTree *t=(TTree*)f->Get(e_plot_dir+"T");}
  //  else if (echan == "muAlphaT_"){
  //  TTree *t=(TTree*)f->Get(mu_plot_dir+"T");}


  //  t->Scan("*","");
  // hil->Draw("A*");mu
  //  SigLumi(3.5,1.0,17.,e_all, mu_all);
}
void SigLumi(Double_t luminit,Double_t steplumi,Double_t steps,TCut e, TCut mu){setStyle();
  TGraph* ele = Evo(luminit,steplumi, steps,e,"eAlphaT_");
    TGraph* muon = Evo(luminit,steplumi, steps,mu,"muAlphaT_");

  TLegend *leg = new TLegend(0.68,0.8,0.99,0.99);

 leg->SetHeader(filesused);
 leg->AddEntry(ele, "e channel","P");
 leg->AddEntry(muon, "mu channel","P");

 TCanvas *c2 = new TCanvas("Varying2","Varying2");

  muon->Draw("A*C");
 ele->Draw("*C");
 ele->SetMarkerColor(kRed);
 ele->SetMarkerStyle(20);
 muon->SetMarkerStyle(21);
 ele->SetMarkerSize(1.4);
 muon->SetMarkerSize(1.4);
  muon->GetXaxis()->SetTitle("Integrated Lumiosity /pb^{-1}");
 muon->GetYaxis()->SetTitle("S/#sqrt{B}");
 // if(vary == "NJet >= "){
 //   muon->GetYaxis()->SetRangeUser(1.5,3.5);
 // }
 // if(vary == "Meff > "){
 //  muon->GetYaxis()->SetRangeUser(1.0,4.0);
   // }
 // if(vary == "HT > "){
   muon->GetYaxis()->SetRangeUser(1.0,8.0);
   // }
 leg->SetTextSize(0.05);
 leg->Draw("SAME");
  c2->Update();
 c2->SaveAs("~/Plots/Optim/Evoloution_"+ptrange+filesused+".png");

}

TGraph* Evo(Double_t initlumi, Double_t steplumi,Double_t steps, TCut cut, TString channel){
TGraph *evo = new TGraph[steps];

 for (UInt_t i = 0; i < steps; i++){
   Double_t templumi = initlumi + (i*steplumi);
   TString arghlumi = ToString2(templumi);
 evo->SetName(channel+arghlumi);

  double signific= Significance(channel,cut, templumi);
  evo->SetPoint(i,(10*templumi),signific);
 }
 return evo;
}




void OptCurves(TCut e, TCut mu, TString vary, TString save, UInt_t steps,UInt_t stepsi,UInt_t initvar,Double_t lum){
  setStyle();
  TLegend *leg = new TLegend(0.68,0.8,0.99,0.99);
  TGraph* ele = Optimise(echan,steps,stepsi,e,vary,initvar,lum);
  TGraph* muon = Optimise(muchan, steps,stepsi,mu,vary,initvar,lum);
 leg->SetHeader(filesused);
 leg->AddEntry(ele, "e channel","P");
 leg->AddEntry(muon, "mu channel","P");

 TCanvas *c1 = new TCanvas("Varying"+vary,"Varying"+vary);

  muon->Draw("A*C");
 ele->Draw("*C");
 ele->SetMarkerColor(kRed);
 ele->SetMarkerStyle(20);
 muon->SetMarkerStyle(21);
 ele->SetMarkerSize(1.4);
 muon->SetMarkerSize(1.4);
 muon->GetXaxis()->SetTitle(vary);
 muon->GetYaxis()->SetTitle("S/#sqrt{B}");
  if(vary == "NJet >= "){
   muon->GetYaxis()->SetRangeUser(1.,5.0);
  }
  else if(vary == "Meff > "){
   muon->GetYaxis()->SetRangeUser(0.,5.0);
   }
 // if(vary == "HT > "){
  else(){
    muon->GetYaxis()->SetRangeUser(1.0,20.0);
  muon->GetXaxis()->SetRangeUser(0.0,140.0);}
   // }
 leg->SetTextSize(0.05);
 leg->Draw("SAME");
  c1->Update();
 c1->SaveAs("~/Plots/Optim/"+save+ptrange+filesused+".png");

}
void OptCurves2(TCut e, TCut mu, TString vary, TString save, UInt_t steps, Double_t stepsi, Double_t initvar){
  setStyle();
  TLegend *leg = new TLegend(0.68,0.8,0.99,0.99);
  TGraph* ele = Optimise(echan,steps,stepsi,e,vary,initvar);
  TGraph* muon = Optimise(muchan, steps,stepsi,mu,vary,initvar);
 leg->SetHeader(filesused);
 leg->AddEntry(ele, "e channel","P");
 leg->AddEntry(muon, "mu channel","P");

 TCanvas *c1 = new TCanvas("Varying"+vary,"Varying"+vary);

 muon->Draw("A*C");
 ele->Draw("*C");
 ele->SetMarkerColor(kRed);
 ele->SetMarkerStyle(20);
 muon->SetMarkerStyle(21);
 muon->GetXaxis()->SetTitle(vary);
 muon->GetYaxis()->SetTitle("S/#SQRT{B}");
 leg->SetTextSize(0.05);
 leg->Draw("SAME");
 c1->Update();
 c1->SaveAs("~/Plots/Optim/"+save+ptrange+filesused+".png");

}
TGraph* Optimise(TString channel,UInt_t steps,UInt_t stepsize, TCut stat, TString dynam, UInt_t initval, Double_t lum){

  TGraph *opt = new TGraph[steps];

 

  // TString initstring = ToString(initval);
  // TCut initcut = dynam + initstring + ".";

  for (UInt_t i==0; i<steps; i++){
    TString stepstring = ToString(initval+(i*stepsize));
    //  cout << stepstring << endl;
    TCut stepcut = dynam + stepstring + ".";
    /*
    if(dynam == "NJet >= " && initval+(i*stepsize) == 3){
      cout << "works3" << endl;
      TCut jet50 = "JetPt[2] >50.";
      TCut imcut = stepcut && jet50;
      stepcut = imcut;}
    
 if(dynam == "NJet >= " && initval+(i*stepsize) == 4){
  cout << "works4" << endl;
      TCut jet50 = "JetPt[3] >50.";
      TCut imcut = stepcut && jet50;
      stepcut=imcut;
    }
   
 if(dynam == "NJet >= " && initval+(i*stepsize) == 5){
      cout << "works5" << endl;
      TCut jet50 = "JetPt[4] >50.";
      TCut imcut = stepcut && jet50;
      stepcut= imcut;
    }
    */
        // cout << stepcut << endl;
    TCut nowcut = stat && stepcut;
    // cout << nowcut << endl;
    double signific= Significance(channel,nowcut, lum);
    if (signific != -9999.){
      opt->SetPoint(i,initval+(i*stepsize),signific);}

    //cout << " i is " << i << " and ht is " << initval+(i*stepsize) << "  and sig is " << signific << endl;

  }

  return opt;


}

TString ToString(UInt_t value){
 stringstream sstr;
 sstr << value;
  TString argh = sstr.str();

  // cout << sstr.str() << endl;

  return argh;
}

TString ToString2(Double_t value){
 stringstream sstr;
 sstr << value;
  TString argh = sstr.str();

  // cout << sstr.str() << endl;

  return argh;
}

Double_t Significance(TString chan,TCut cut, Double_t lumi){
  TCut cutData = cut && trigData;
  if (chan == "eAlphaT_"){
 float cfQCDem  = Npass(chan,"QCDEM",sele+"QCDEM",cut,lumi);
 float cfQCDbce  = Npass(chan,"QCDBCE",""+sele+"QCDBCE",cut,lumi);
 float cfQCD170  = Npass(chan,"QCD170",""+sele+"QCD_All170",cut,lumi);
 float cfQCD   = cfQCDem + cfQCDbce + cfQCD170;}
  else if (chan == "muAlphaT_"){
    float cfQCD = Npass(chan,"QCD",sele+"QCD_Mu",cut,lumi);
  }

  float cfW    = Npass(chan,"W+jets",""+sele+"Wjets_vols",cut,lumi);
  float cfZ    = Npass(chan,"Z+jets",sele+"ZJets_madgraph",cut,lumi);
  float cfTT   = Npass(chan,"tt",sele+"ttbarTauola",cut,lumi);
  float cfSM   = cfQCD + cfW + cfZ + cfTT;
  float cfLM0  = Npass(chan,"LM0",sele+"LM0",cut,lumi);
  // float cfLM1  = Npass(chan,"LM1",sele+"LM1",cut);
  // float cfDATA = Npass(chan,"data",""+sele+"Data_34",cutData);
  // cout << cfLM0 << " and " << cfSM << " so the s / sqrt b " << cfLM0/sqrt(cfSM) << endl;
  if (cfSM > 0){
    Double_t sig = cfLM0/sqrt(cfSM);}
  else (){
    Double_t sig = -9999.;
  }

  return sig;

}




double Npass(TString channel, TString opt,TString fname, TCut flow, Double_t lumi){
 TFile *f=new TFile(channel+fname+".root");
 if (channel == "eAlphaT_"){
   TTree *t=(TTree*)f->Get(e_plot_dir+"T");}
 else if (channel == "muAlphaT_"){
   TTree *t=(TTree*)f->Get(mu_plot_dir+"T");}


 // t->Scan("*",flow);
   Double_t weight;
    t->SetBranchAddress("wgt",&weight);
    t->GetEntry(2);
 TString wt="wgt";

 if (opt == "QCDEM"){
  TCanvas *c = new TCanvas("c","c");
 t->Draw("NJet>>njet","(wgt)"*flow);
 //cout << channel << endl;
 // t->Scan("*",e_noht);
 double n = njet->Integral();
  n = lumi*n;
  //  n = 1.5*n;
  c->Close();
 }
 else if (opt == "QCDBCE"){
  TCanvas *c = new TCanvas("c2","c2");
 t->Draw("NJet>>njet","(wgt)"*flow);
 double n = njet->Integral();
  n = lumi*n;

  c->Close();
 }
 else if (opt == "QCD170"){
  TCanvas *c = new TCanvas("c3","c3");
 
 t->Draw("NJet>>njet","(wgt)"*flow);
 double n = njet->Integral();
 n = lumi*n;
 if(sele == "Control_"){
   //   n = 3.07*n;
 }
 else if (sele == "Signal_"){
   // n = 4.35*n;
 }
  c->Close();
 }

 else if (opt == "QCD"){
  TCanvas *c = new TCanvas("c3","c3");
  //  t->Scan("*",flow);
 t->Draw("NJet>>njet","(wgt)"*flow);
 double n = njet->Integral();
  n = lumi*n;
 //n=n*1.5;
  c->Close();
 }


 else if (opt == "data"){
 
  double n = t->GetEntries("(wgt)"*flow);
  //n*=weight;
 }
 else if (opt == "W+jets"){
   
  double n = t->GetEntries("(wgt)"*flow);
  n*=weight;
  n=lumi*n;
  n=1.29557302*n;
 }
 else if (opt == "Z+jets"){
   
  double n = t->GetEntries("(wgt)"*flow);
  n*=weight;
  n=lumi*n;
  n=(3048./2400.)*n;
 }
 else if (opt == "tt"){

  double n = t->GetEntries("(wgt)"*flow);
  n*=weight;
  n=lumi*n;
  n=1.65789474*n;
 }
 else{
  
  double n = t->GetEntries("(wgt)"*flow);
  n*=weight;
  n=lumi*n;
 }
 t->Delete();
 return n;
}
void setStyle(){
  //gROOT->SetBatch(kTRUE);
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
