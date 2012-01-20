TString plot_dir = "mutree_iso/";
TString selec = "Signal_";


//TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140) > 0";
//TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150 + trig_HT160) > 0";
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v1 + trig_HT150v3 + trig_HT160v1 + trig_HT160v3) > 0";




TCut mu_pt_hi = "MuonPt[0]>10.";
TCut mu_pt_lo = "MuonPt[0]<=10.";

//TCut trig = triga || trigb || trigc || trige || trigf || trigh || trigi;
//TCut trig = triga || trigb || trigc || trigd || trigg

TCut mu_odd = "MuonOdd ==0";
TCut ne = "NElectrons == 0";
TCut e_odd = "ElectronOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";

//TCut mu_barrel1 = "MuonEta[0] < 1.4442";
//TCut mu_barrel2 = "MuonEta[0] > -1.44S42";
//T/Cut mu_barrel = mu_barrel1 && mu_barrel2;

//TCut mu_ec1 = "MuonEta[0] > 1.44420";
//TCut mu_ec2 = "MuonEta[0] < -1.4442";
//TCut mu_ec = mu_ec1 || mu_ec2;



TCut nmu = "NMuons ==1";


TCut mu_pt = "MuonPt[0] >10. && MuonPt[0]<25.";

TCut mu_pt_r1 = "MuonPt[0]<10.";
TCut mu_pt_r2 = "MuonPt[0]>10. && MuonPt[0]<20.";
TCut mu_pt_r3 = "MuonPt[0]>20. && MuonPt[0]<30.";




TCut secondMuon = "NLMuons < 2";
TCut looseEle = "NLElectrons == 0";


TCut muon = nmu && mu_pt;


TCut npho = "NPhotons ==0";
TCut nj = "NJet >= 2";
TCut j1pt = "JetPt[1]>50.";
TCut jodd = "JetOdd ==0";
TCut bmu = "badMuonJet ==1";
TCut jeta1 = "JetEta[0] < 2.4";
TCut jeta2 = "JetEta[0] > -2.4";

TCut h200 = "HT_Lep > 200.";
TCut h250 = "HT > 250.";
TCut ht200 = "HT>200.";
TCut h300 = "HT_Lep > 300.";
TCut h350 = "HT_Lep > 350.";
TCut alphat = "AlphaT_Lep > 0.55";

TCut htt300 = "HT > 300.";
TCut preData = trig && h250;
TCut numlepData =  preData && sel && hbhe && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numlep =  h250 && sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numlepX = sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numpj = numlep && npho; // && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
//TCut numpho = numpj && npho;
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
//TCut numlep = numlepb || numlepa;

//TCut numpj = numlep + " && NPhotons == 0 && NJet >= 2 && JetPt[1]>50. && JetOdd ==0 && badMuonJet ==1 && JetEta[0] < 2.4 && JetEta[0] > -2.4";
//TCut HT200 = numpj + " && HT_Lep > 200.";
//TCut HT300 = numpj + " && HT_Lep > 300.";
//TCut HT350 = numpj + " && HT_Lep > 350.";
//TCut aT = HT300 + " && AlphaT_Lep > 0.55";
Double_t lumi = 3.470;

TString filebit = "_";
void tcutting() {
  /*
    TFile *f=new TFile("muAlphaT_Control_ZJets_madgraph.root");
    TTree *t=(TTree*)f->Get(plot_dir+"T");
    t->Draw("NJet>>njet","(wgt)"*numlep);
    Double_t n = njet->Integral();
    n = n*lum
    cout << n << endl;
  */



  //  SingleFile(filebit+"Wjets_vols.root","W + jets",opt);
  //    SingleFile(filebit+"ZJets_madgraph.root","Z + Jets",opt);
  // SingleFile(filebit+"LM0.root","LM0",opt);
  //  SingleFile(filebit+"Data.root","data",opt);

  //     SingleFile(filebit+"LM1.root","LM1",opt);
  //    SingleFile(filebit+"ttbarTauyola.root","tt",opt);
     //   SingleFile(filebit+"QCD_AllPtBins_7TeV_Pythia.root","QCD",opt);

   CF();

     
   
  //  TCut star = nmu && mu_iso1 && mu_dr;
  //&& amu_iso1 && mu_noiso2 && amu_noiso2;
  //   TFile *fqcd=new TFile("muAlphaT_Controly_Data_15.root");
  //      TTree *tqcd=(TTree*)fqcd->Get(plot_dir+"T");
     //tqcd->Draw("NJet>>qcd","(wgt)"*aTData);
    // cout << " Num is " << qcd->Integral() << endl;
     //  tqcd->Scan("",aTData);
       //  tqcd->Scan("trig_HT100:trig_HT120:trig_HT140:selection:HBHENoise:NJet:JetPt[0]:JetEta[0]:NPhotons:NMuons","RunNumber ==147390 && LumiSection ==102 && EventNumber ==91415462");
  //      tqcd->Scan("MuonPt[0]:MuonOdd:NElectrons:ElectronOdd:JetOdd:JetPt[1]:AlphaT_Lep:HT_Lep:","RunNumber ==147390 && LumiSection ==102 && EventNumber ==91415462");

   //    tqcd->Scan("RunNumber:LumiSection:EventNumber",earlyaTData);

  //cout << "help" << endl;

}

void CF(){
cout << "\n";
  cout << " Muon  CUT FLOW ~TABLE~ \n\n";
  cout.width(15);  cout << "CUT FLOW  ";
  cout.width(3);   cout << "| QCD      ";
  cout.width(13);  cout << "| Wjets    ";
  cout.width(13);  cout << "| Zjets    ";
  cout.width(13);  cout << "| TTbar    "; 
  cout.width(13);  cout << "| LM0     ";
  cout.width(13);  cout << "| LM1    ";
  cout.width(13);  cout << "| SM       ";
  cout.width(13);  cout << "| DATA     "; 
  cout.width(7);  cout << "\n";
  cout.width(121); cout.fill('-'); cout << "\n";
  cout.fill(' ');
  //newCutFlow("",selec,"Total",false);

  //newCutFlow("","", HT300X, selec,"Nothing",false);
   newCutFlow(h250,preData, HT300X, selec,"Trig & HT>250",false);
   // newCutFlow(h250 && sel && h_j_pt, trig && hbhe && h250 &&sel && h_j_pt,HT300X, selec,"sel and hjpt",false);
   //newCutFlow(h250 && sel && h_j_pt && nmu, trig && hbhe && h250 &&sel && h_j_pt && nmu ,HT300X, selec,"nmu",false);
   //newCutFlow(h250 && sel && h_j_pt && nmu && mu_pt, trig && hbhe && h250 &&sel && h_j_pt && nmu && mu_pt ,HT300X, selec,"mupt",false);
   //newCutFlow(h250 && sel && h_j_pt && nmu && mu_pt && ne, trig && hbhe && h250 &&sel && h_j_pt && nmu && mu_pt && ne ,HT300X, selec,"ne",false);
   //newCutFlow(h250 && sel && h_j_pt && nmu && mu_pt && ne && secondMuon, trig && hbhe && h250 &&sel && h_j_pt && nmu && mu_pt && ne && secondMuon,HT300X, selec,"loosemu",false);
   //newCutFlow(h250 && sel && h_j_pt && nmu && mu_pt && ne && secondMuon && looseEle, trig && hbhe && h250 &&sel && h_j_pt && nmu && mu_pt && ne  && secondMuon && looseEle ,HT300X, selec,"loosee",false);

  newCutFlow(numlep,numlepData,numlepX,selec,"Lepton Req",false);
  newCutFlow(numpj,numpjData,numpjX,selec,"Pho Req",false);
  newCutFlow(numphoj,numpjData,numpjX,selec,"Jet Req",false);
  //  newCutFlow(HT200,HT200Data,HT200X,selec,"HT > 200",false);
  // newCutFlow(HT300,HT300Data, HT300X,selec,"HT > 300",false);
  newCutFlow(HT350,HT350Data, HT350X,selec,"HT > 350",false);//
  newCutFlow(aT,aTData,aTX,selec,"aT > 0.55",true);


}

void newCutFlow(TCut cut,TCut cutData,TCut cutX, TString sele, TString cutFlowNames,bool last){

     
  //  float cfQCD  = Npass("QCD",sele+"QCD_AllPtBins_7TeV_Pythia",cut);
  float cfQCD  = Npass("QCD",sele+"QCD_Mu",cut);;
  float cfW    = Npass("W+jets",sele+"Wjets_vols",cut);
  float cfZ    = Npass("Z+jets",sele+"ZJets_madgraph",cut);
  float cfTT   = Npass("tt",sele+"ttbarTauola",cut);
  float cfSM   = cfQCD + cfW + cfZ + cfTT;
  float cfLM0  = Npass("LM0",sele+"LM0",cut);
  float cfLM1  = Npass("LM1",sele+"LM1",cut);
  float cfDATA = Npass("data",sele+"Data_34",cutData);

cout.width(14); cout << cutFlowNames << " | ";
 if (cfQCD >0 && cfQCD < 10){cout.precision(4);}
 if (cfQCD >10 && cfQCD < 100){cout.precision(5);}
 if (cfQCD >100 && cfQCD < 1000){cout.precision(6);}
 if (cfQCD >1000 && cfQCD < 10000){cout.precision(7);}
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
cout.precision(17)
  // if (cfLM0 >0 && cfLM0 < 10){cout.precision(4);}
  //if (cfLM0 >10 && cfLM0 < 100){cout.precision(5);}
  //if (cfLM0 >100 && cfLM0 < 1000){cout.precision(6);}
  cout.width(10); cout << cfLM0  << " | ";
  // if (cfLM1 >0 && cfLM1 < 10){cout.precision(4);}
  // if (cfLM1 >10 && cfLM1 < 100){cout.precision(5);}
  // if (cfLM1 >100 && cfLM1 < 1000){cout.precision(6);}
  cout.width(10); cout << cfLM1  << " | ";
 if (cfSM >0 && cfSM < 10){cout.precision(4);}
 if (cfSM >10 && cfSM < 100){cout.precision(5);}
 if (cfSM >100 && cfSM < 1000){cout.precision(6);}
 if (cfSM >1000 && cfSM < 10000){cout.precision(7);}
  cout.width(10); cout << cfSM   << " | ";
  cout.width(4); cout << cfDATA  << "\n";

  if (last){
    cout.width(121); cout.fill('-'); cout << "\n";
    cout.width(54); cout.fill(' ');
    cout.width(69); cout << "  S/B  | ";
  cout.precision(2);
    cout.width(7); cout << " " <<  cfLM0/cfSM << " |  ";
if(cfLM1/cfSM < 1.){cout.precision(1);}
    cout.width(6); cout << "" <<  cfLM1/cfSM << "\n";
  
    cout.width(54); cout.fill(' ');
    cout.width(69); cout << "  S/SQRT(B)  | ";
  cout.precision(2);
    cout.width(7); cout << " " <<  cfLM0/sqrt(cfSM) << " |  ";
    if(cfLM1/sqrt(cfSM) < 0.95){cout.precision(1);}
    cout.width(6); cout << "" <<  cfLM1/sqrt(cfSM) << "\n";

  }
}



double Npass(TString opt,TString fname, TCut flow ){
 TFile *f=new TFile("muAlphaT_"+fname+".root");
  TTree *t=(TTree*)f->Get(plot_dir+"T");

   Double_t weight;
    t->SetBranchAddress("wgt",&weight);
    t->GetEntry(2);
 TString wt="wgt";

 if (opt == "QCD"){
   TCut hi = flow && mu_pt_hi;
  TCanvas *c_hi = new TCanvas("c_hi","c_hi");
  t->Draw("NJet>>njet_hi","(wgt)"*hi );
 double n_hi = njet_hi->Integral();


 TCut lo = flow && mu_pt_lo;
   TCanvas *c_lo = new TCanvas("c_lo","c_lo");
  t->Draw("NJet>>njet_lo","(wgt)"*lo );
 double n_lo = njet_lo->Integral();
 // n_lo = n_lo*1.94;
 double n = n_hi;
 n = lumi*n;

  c_hi->Close();
  c_lo->Close();
 }
 else if (opt == "data"){
 
   double n = t->GetEntries("(wgt)"*flow);
   //   cout << n << endl;
  n*=weight;
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
