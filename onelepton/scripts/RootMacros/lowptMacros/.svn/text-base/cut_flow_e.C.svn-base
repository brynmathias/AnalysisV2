TString plot_dir = "eletree/";
TString selec = "Signal_";
TCut triga = "trig_HT100 == 1 ";

TCut trigb = "trig_HT120 == 1";

TCut trigc = "trig_HT140 == 1";
TCut trigd = "trig_HT150 ==1";
TCut trige = "trig_HT150v1 ==1";
TCut trigf = "trig_HT150v3 ==1";
TCut trigg = "trig_HT160 ==1";
TCut trigh = "trig_HT160v1 ==1";
TCut trigi = "trig_HT160v3 ==1";

//TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140) > 0";
//TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150 + trig_HT160) > 0";
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v3) > 0";

//TCut trig = triga || trigb || trigc || trige || trigf || trigh || trigi;
//TCut trig = triga || trigb || trigc || trigd || trigg;

TCut e_odd = "ElectronOdd ==0";
TCut nmu = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";

TCut secondEle = "NLElectrons < 2";
TCut looseMuon = "NLMuons == 0";

TCut trigData = trig && hbhe;

TCut ne = "NElectrons ==1";
TCut e_iso1 = "(ElectronRelCombIso[0]<0.06)";
TCut e_pt = "ElectronPt[0]<25.";
TCut e_dr = "ElectronClosestComJetDR[0] > 0.3";

TCut ne2 = "NElectrons ==2";
TCut e_noiso2 = "(ElectronRelCombIso[1]>0.06)";
TCut e_noiso1 = "(ElectronRelCombIso[0]>0.06)"; 
TCut e_iso2 = "(ElectronRelCombIso[1]<0.06)"; 
TCut e_pt2 = "ElectronPt[1]<25.";
TCut e_dr2 = "ElectronClosestComJetDR[1] > 0.3";
TCut e_nodr2 = "ElectronClosestComJetDR[1] > 0";
TCut e_nopt2 = "ElectronPt[1]<100000.";
TCut e_nodr = "ElectronClosestComJetDR[0] > 0";
TCut e_nopt = "ElectronPt[0]<100000.";




TCut ele1 = ne && e_iso1 && e_noiso2 && e_pt && e_dr &&  e_nodr2 && e_nopt2;
TCut ele2a = ne2 && e_iso1 && e_noiso2 &&  e_pt && e_dr &&  e_nodr2 && e_nopt2;
TCut ele2b = ne2 && e_noiso1 && e_iso2 && e_nopt && e_nodr && e_dr2 && e_pt2;


//TCut ele =(ele2a) || (ele1) || (ele2b);
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

TCut h250 = "HT > 250.";
TCut htt300 = "HT > 300.";
TCut ht200 = "HT>200.";

TCut preData = trig && h250 && hbhe;
TCut numlepData  = preData && sel && ele && secondEle && nmu && looseMuon;
TCut numlep = h250 && sel && ele && secondEle && nmu && looseMuon;
TCut numlepX = sel && ele && e_odd && nmu && mu_odd;
TCut numpj = numlep && npho; //&& nj && j1pt && jodd && bmu && jeta1 && jeta2;

TCut numphoj = numpj && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjData = numlepData && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjX = numlepX && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;






TCut HT200 = numpj && h200;
TCut HT300 = numpj && h300;
TCut HT350 = numpj && h350;
TCut aT = HT350 && alphat;

TCut HT200Data = numpjData && h200;
TCut HT300Data = numpjData && h300;
TCut HT350Data = numpjData && h350;
TCut aTData = HT350Data && alphat;
TCut earlyaTData = HT200Data && alphat;
TCut HT200X = numpjX && h200;
TCut HT300X = numpjX && h300;
TCut HT350X = numpjX && h350;
TCut aTX = HT350X && alphat;


Double_t lumi = 3.470;
//Double_t lumi = 1;
TString filebit = "_";
void cut_flow_e() {

  
  TString opt = "S";


  //  SingleFile(filebit+"Wjets_vols","W + jets",opt);
  //    SingleFile(filebit+"ZJets_madgraph","Z + Jets",opt);
     //  SingleFile(filebit+"LM0","LM0",opt);
  //  SingleFile(filebit+"Data","data",opt);

  //  SingleFile(filebit+"LM1","LM1",opt);
      //  SingleFile(filebit+"ttbarTauola","tt",opt);
     //  SingleFile(filebit+"QCD_AllPtBins_7TeV_Pythia","QCD",opt);

  // newCutFlow(numlep,"Control_","Lepton Req");
    CF();
  /* TFile *fqcd=new TFile("eAlphaT_Control_QCD.root");
  TTree *tqcd=(TTree*)fqcd->Get(plot_dir+"T");

 TFile *fqcdem=new TFile("eAlphaT_Control_QCDEM.root");
  TTree *tqcdem=(TTree*)fqcdem->Get(plot_dir+"T");
 TFile *fqcdbce=new TFile("eAlphaT_Control_QCDBCE.root");
  TTree *tqcdbce=(TTree*)fqcdbce->Get(plot_dir+"T");
 TFile *fqcd170=new TFile("eAlphaT_Control_QCD170.root");
  TTree *tqcd170=(TTree*)fqcd170->Get(plot_dir+"T");

 tqcd->Draw("NJet>>qcd","(wgt)"*numlep);
 tqcdem->Draw("NJet>>qcdem","(wgt)"*numlep);
 tqcdbce->Draw("NJet>>qcdbce","(wgt)"*numlep);
 tqcd170->Draw("NJet>>qcd170","(wgt)"*numlep);


  TCanvas *cm = new TCanvas("cm","cm");
  cm->Divide(2,2);
  cm->cd(1);
  qcd->Draw();
  cm->cd(2);
  qcdem->Draw();
  cm->cd(3);
    qcdbce->Draw();
  cm->cd(4);
  qcd170->Draw();
  cm->Update();


  cout << "QCD full  " << (qcd->Integral()) << ". Is it made up of  " << (qcdem->Integral()) << " plussed to " << qcdbce->Integral() << " and to " << qcd170->Integral() << " or not?" << endl;
  */
    //   TFile *fqcd=new TFile("eAlphaT_Control_Data_Trig_34.root");
    //    TTree *tqcd=(TTree*)fqcd->Get(plot_dir+"T");
  //  tqcd->Draw("NJet>>qcd","(wgt)"*aTData);
  //  cout << " Num is " << qcd->Integral() << endl;
  //   tqcd->Scan("RunNumber:LumiSection:EventNumber:ElectronPt[0]:JetPt[0]:HT:AlphaT_Lep:JetEta[0]:JetPt[1]:ElectronClosestComJetDR",aTData);
 
     /*
  float cfQCDem  = Npass("QCDEM","OLD_Control_QCDEM",numlep);
 float cfQCDbce  = Npass("QCDBCE","OLD_Control_QCDBCE",numlep);
 float cfQCD170  = Npass("QCD170","OLD_Control_QCD170",numlep);
 // cout << "a" << cfQCDem << "b" << cfQCDbce << "c"<< cfQCD170 << endl;
 // float cfQCD   = cfQCDem + cfQCDbce + cfQCD170;
 float cfQCD    = Npass("QCD","OLD_Control_QCD",numlep);

 cout << "QCD full " << cfQCD << ". Is it made up of   " << cfQCDem << " plussed to "<< cfQCDbce << " and to " << cfQCD170 <<  " or not?" << endl;
  */  
    // tqcd->Scan("RunNumber:LumiSection:EventNumber",earlyaTData);
}

void CF(){
cout << "\n";
  cout << " Electron  NUMLEP FLOW ~TABLE~ \n\n";
  cout.width(15);  cout << "CUT FLOW  ";
  cout.width(3);   cout << "| QCD      ";
  cout.width(13);  cout << "| Wjets    ";
  cout.width(13);  cout << "| Zjets    ";
  cout.width(13);  cout << "| TTbar    "; 
  cout.width(13);  cout << "| LM0      ";
  cout.width(13);  cout << "| LM1      ";
  cout.width(13);  cout << "|| SM      ";
  cout.width(14);  cout << "| DATA     "; 
  cout.width(7);  cout << "\n";
  cout.width(121); cout.fill('-'); cout << "\n";
cout.fill(' ');
// newCutFlow("","", "", selec,"Nothing",false);
  newCutFlow(h250,preData, HT300X, selec,"Trig & HT>250",false);
// && h_j_pt && ele && e_odd && nmu && looseMuon;
  //   newCutFlow(h250 && sel,preData && sel, HT300X, selec,"sel",false);
    //  newCutFlow(h250 && sel && h_j_pt, preData && sel && h_j_pt, HT300X, "Con//trol_","h_j_pt",false);
  //   newCutFlow(h250 && sel && h_j_pt && ele, preData && sel && h_j_pt && ele, HT300X, selec,"ele",false);
  //   newCutFlow(h250 && sel && h_j_pt && ele && nmu, preData && sel && h_j_pt && ele && nmu, HT300X, selec,"mu",false);
  //    newCutFlow(h250 && sel && h_j_pt && ele && nmu && secondEle, preData && sel && h_j_pt && ele && nmu && secondEle, HT300X, selec,"e odd",false);
  //    newCutFlow(h250 && sel && h_j_pt && ele && nmu && secondEle && looseMuon, preData && sel && h_j_pt && ele && nmu && secondEle && looseMuon, HT300X, selec,"mu odd",false);
  newCutFlow(numlep,numlepData,numlepX,selec,"Lepton Req",false);
  newCutFlow(numpj,numpjData,numpjX,selec,"Pho Req",false);
 newCutFlow(numphoj,numpjData,numpjX,selec,"Jet Req",false);
  //  newCutFlow(HT200,HT200Data,HT200X, selec,"HT > 200",false);
  //// newCutFlow(HT300,HT300Data, HT300X, selec,"HT > 300",false);
    newCutFlow(HT350,HT350Data, HT350X, selec,"HT > 350",false);//
    newCutFlow(aT,aTData,aTX,selec,"aT > 0.55",true);


}
void newCutFlow(TCut cut,TCut cutData,TCut cutX, TString sele, TString cutFlowNames,bool last){

     
  float cfQCDem  = Npass("QCDEM",""+sele+"QCDEM",cut);
 float cfQCDbce  = Npass("QCDBCE",""+sele+"QCDBCE",cut);
 float cfQCD170  = Npass("QCD170",""+sele+"QCD_All170",cut);
 // cout << "a" << cfQCDem << "b" << cfQCDbce << "c"<< cfQCD170 << endl;
 float cfQCD   = cfQCDem + cfQCDbce + cfQCD170;
 // cfQCD = cfQCD*2.48;
 // float cfQCD    = Npass("QCD",sele+"QCD",cut);
  float cfW    = Npass("W+jets",""+sele+"Wjets_vols",cut);
  float cfZ    = Npass("Z+jets",sele+"ZJets_madgraph",cut);
  float cfTT   = Npass("tt",sele+"ttbarTauola",cut);
  float cfSM   = cfQCD + cfW + cfZ + cfTT;
  float cfLM0  = Npass("LM0",sele+"LM0",cut);
  float cfLM1  = Npass("LM1",sele+"LM1",cut);
  float cfDATA = Npass("data",""+sele+"RA1Data",cutData);

cout.width(14); cout << cutFlowNames << " | ";

 if (cfQCD >0 && cfQCD < 10){cout.precision(4);}
 if (cfQCD >10 && cfQCD < 100){cout.precision(5);}
 if (cfQCD >100 && cfQCD < 1000){cout.precision(6);}
 cout.width(10); cout << cfQCD  << " | ";
 if (cfW >0 && cfW < 10){cout.precision(4);}
 if (cfW >10 && cfW < 100){cout.precision(5);}
 if (cfW >100 && cfW < 1000){cout.precision(6);}
  cout.width(10); cout << cfW    << " | ";
 if (cfZ >0 && cfZ < 10){cout.precision(4);}
 if (cfZ >10 && cfZ < 100){cout.precision(5);}
 if (cfZ >100 && cfZ < 1000){cout.precision(6);}
  cout.width(10); cout << cfZ    << " | ";
 if (cfTT >0 && cfTT < 10){cout.precision(4);}
 if (cfTT >10 && cfTT < 100){cout.precision(5);}
 if (cfTT >100 && cfTT < 1000){cout.precision(6);}
  cout.width(10); cout << cfTT   << " | ";
cout.precision(7);
  // if (cfLM0 >0 && cfLM0 < 10){cout.precision(4);}
  //if (cfLM0 >10 && cfLM0 < 100){cout.precision(5);}
  // if (cfLM0 >100 && cfLM0 < 1000){cout.precision(6);}
  cout.width(10); cout << cfLM0  << " | ";
  //if (cfLM1 >0 && cfLM1 < 10){cout.precision(4);}
  // if (cfLM1 >10 && cfLM1 < 100){cout.precision(5);}
  // if (cfLM1 >100 && cfLM1 < 1000){cout.precision(6);}
  cout.width(10); cout << cfLM1  << " || ";
 if (cfSM >0 && cfSM < 10){cout.precision(4);}
 if (cfSM >10 && cfSM < 100){cout.precision(5);}
 if (cfSM >100 && cfSM < 1000){cout.precision(6);}
  cout.width(10); cout << cfSM   << " | ";
  cout.width(4); cout << cfDATA << "\n";


if (last){
    cout.width(121); cout.fill('-'); cout << "\n";
cout.fill(' ');
 cout.width(54);cout.fill(' '); //cout.fill('-');
 cout.width(69); cout << "  S/B  | ";
  cout.precision(2);

    cout.width(7); cout << " " <<  cfLM0/cfSM << " |  ";
  if(cfLM1/cfSM < 1.){cout.precision(1);}
    cout.width(6); cout << "" <<  cfLM1/cfSM <<  " |  " <<  "\n";
 cout.width(54); cout.fill(' ');
    cout.width(69); cout << "  S/SQRT(B)  | ";
    cout.precision(2);

    cout.width(7); cout << " " <<  cfLM0/sqrt(cfSM) << " |  ";
    if(cfLM1/sqrt(cfSM) < 1.){cout.precision(1);}
    cout.width(6); cout << "" <<  cfLM1/sqrt(cfSM) << " |  " << "\n";

  }
}



void  SingleFile(TString file, TString name, TString Option){

    if (name == "data"){
      TString trig = trigdata;
    }
    else{
      TString trig = trigMC;
    }

    // cout << "File is : " << name << endl;
  cout << endl;
  if(Option == "B"  || Option == "S"){
    cout << "Selection Events" << endl;
  cout << "=======================================================" << endl;
  cout << "Events passing Trigger/UncorJet cuts: " << Npass(name,"Control"+file,trig) << endl;
  cout << "Events passing Lepton cuts: " << Npass(name,"Control"+file,trig+numlep) << endl;
  cout << "Events passing Photon and Jet cuts:  " << Npass(name,"Control"+file,trig+numpj) << endl;
  cout << "Events passing HT > 200 cut: " << Npass(name,"Control"+file,trig+HT200) << endl;
  cout << "Events passing HT > 300 cut: " << Npass(name,"Control"+file,trig+HT300) << endl;
  cout << "Events passing HT > 350 cut: " << Npass(name,"Control"+file,trig+HT350) << endl;
  cout << "Events passing aT > 0.55 cut: " << Npass(name,"Control"+file,trig+aT) << endl;

  }
     if(Option == "B"  || Option == "AS"){
  cout << "========================================================" << endl;
  
  cout << "Anti-Selection Events" << endl;
  cout << "====================================" << endl;
  cout << "Events passing Trigger/UncorJet cuts: " << Npass(name,"Control"+file,trig) << endl;
  cout << "Events passing Lepton cuts: " << Npass(name,"Control"+file,trig+numlep) << endl;
  cout << "Events passing Photon and Jet cuts:  " << Npass(name,"Control"+file,trig+numpj) << endl;
  cout << "Events passing HT > 200 cut: " << Npass(name,"Control"+file,trig+HT200) << endl;
  cout << "Events passing HT > 300 cut: " << Npass(name,"Control"+file,trig+HT300) << endl;
  cout << "Events passing HT > 350 cut: " << Npass(name,"Control"+file,trig+HT350) << endl;
 cout << "Events passing aT > 0.55 cut: " << Npass(name,"Control"+file,trig+aT) << endl;
  }
  }
double Npass(TString opt,TString fname, TCut flow ){
 TFile *f=new TFile("eAlphaT_"+fname+".root");
  TTree *t=(TTree*)f->Get(plot_dir+"T");
  //  cout << fname << "   " << plot_dir << endl;
   Double_t weight;
    t->SetBranchAddress("wgt",&weight);
    t->GetEntry(2);
 TString wt="wgt";

 if (opt == "QCDEM"){
  TCanvas *c = new TCanvas("c","c");
 t->Draw("NJet>>njet","(wgt)"*flow);
 double n = njet->Integral();
  n = lumi*n;
  // n = 1.5*n;
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
 if(selec == "Control_"){
   //   n = 3.07*n;
 }
 else if (selec == "Signal_"){
   // n = 4.35*n;
 }
  c->Close();
 }

 else if (opt == "QCD"){
  TCanvas *c = new TCanvas("c3","c3");

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
 return n;
}

