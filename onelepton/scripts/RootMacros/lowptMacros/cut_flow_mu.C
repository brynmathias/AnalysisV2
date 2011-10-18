kiniTString plot_dir = "mutree/";


TString trigMC = "trig_Jet50 == 1 && selection == 1 && (High_Jet_Pt > 70.)";
TString trigdata = "trig_Jet50==1 && selection == 1 && HBHENoise == 1 && (High_Jet_Pt > 70.)";
TString numlep = " && NMuons ==1 &&  MuonPt[0] < 25. && MuonOdd == 0 && MuonClosestComJetDR[0] > 0.3 && NElectrons == 0 &&  ElectronOdd == 0";

//&& ElectronOdd == 0 && NElectrons == 0";
// && MuonClosestPreJetDR > 0.3";

TString numpj = numlep + odd + el+ " && NPhotons == 0 && NJet >= 2 && JetOdd ==0 && badMuonJet ==1 && JetEta[0] < 2.4 && JetEta[0] > -2.4";
TString HT200 = numpj + " && HT_Lep > 200.";
TString HT300 = numpj + " && HT_Lep > 300.";
TString HT350 = numpj + " && HT_Lep > 350.";
TString aT = HT350 + " && AlphaT_Lep > 0.55";
Double_t lumi = 0.2880;

TString filebit = "_";
void cut_flow_mu() {

  
  TString opt = "S";


  //  SingleFile(filebit+"Wjets_vols.root","W + jets",opt);
  //    SingleFile(filebit+"ZJets_madgraph.root","Z + Jets",opt);
  // SingleFile(filebit+"LM0.root","LM0",opt);
  //  SingleFile(filebit+"Data.root","data",opt);

  //     SingleFile(filebit+"LM1.root","LM1",opt);
  //    SingleFile(filebit+"ttbarTauola.root","tt",opt);
     //   SingleFile(filebit+"QCD_AllPtBins_7TeV_Pythia.root","QCD",opt);

  CF();
}

void CF(){
cout << "\n";
  cout << " Muon  CUT FLOW ~TABLE~ \n\n";
  cout.width(15);  cout << "CUT FLOW  ";
  cout.width(3);   cout << "| QCD      ";
  cout.width(13);  cout << "| Wjets    ";
  cout.width(13);  cout << "| Zjets    ";
  cout.width(13);  cout << "| TTbar    "; 
  cout.width(13);  cout << "| LM0      ";
  cout.width(13);  cout << "| LM1      ";
  cout.width(13);  cout << "| SM       ";
  cout.width(13);  cout << "| DATA     "; 
  cout.width(7);  cout << "\n";
  cout.width(124); cout.fill('-'); cout << "\n";
  cout.fill(' ');

newCutFlow(numlep,"Signal_","Lepton Req",false);
newCutFlow(numpj,"Signal_","Pho/Jet Req",false);
newCutFlow(HT200,"Signal_","HT > 200",false);
newCutFlow(HT300,"Signal_","HT > 300",false);
newCutFlow(HT350,"Signal_","HT > 350",false);//
newCutFlow(aT,"Signal_","aT > 0.55",true);


}

void newCutFlow(TString cut,TString sele, TString cutFlowNames,bool last){

     
  float cfQCD  = Npass("QCD",sele+"QCD_AllPtBins_7TeV_Pythia",trigMC+cut);
  float cfW    = Npass("W+jets",sele+"Wjets_vols",trigMC+cut);
  float cfZ    = Npass("Z+jets",sele+"ZJets_madgraph",trigMC+cut);
  float cfTT   = Npass("tt",sele+"ttbarTauola",trigMC+cut);
  float cfSM   = cfQCD + cfW + cfZ + cfTT;
  float cfLM0  = Npass("LM0",sele+"LM0",trigMC+cut);
  float cfLM1  = Npass("LM1",sele+"LM1",trigMC+cut);
  float cfDATA = Npass("data",sele+"Data",trigdata+cut);

cout.width(14); cout << cutFlowNames << " | ";
  cout.width(10); cout << cfQCD  << " | ";
  cout.width(10); cout << cfW    << " | ";
  cout.width(10); cout << cfZ    << " | ";
  cout.width(10); cout << cfTT   << " | ";
  cout.width(10); cout << cfLM0  << " | ";
  cout.width(10); cout << cfLM1  << " | ";
  cout.width(10); cout << cfSM   << " | ";
  cout.width(4); cout << cfDATA  << "\n";

  if (last){
    cout.width(124); cout.fill('-'); cout << "\n";
    cout.width(54); cout.fill('-');
    cout.width(10); cout << "  S/B  ";
    cout.width(10); cout << "(LM0)    " <<  cfLM0/cfSM << " | ";
    cout.width(10); cout << "(LM1)    " <<  cfL M1/cfSM << "\n";

  }
}



double Npass(TString opt,TString fname, TString flow ){
 TFile *f=new TFile("muAlphaT_"+fname+".root");
  TTree *t=(TTree*)f->Get(plot_dir+"T");

   Double_t weight;
    t->SetBranchAddress("wgt",&weight);
    t->GetEntry(2);
 TString wt="wgt";

 if (opt == "QCD"){
  TCanvas *c = new TCanvas("c","c");
  TString cuts ="wgt * ("+ flow +")";
 t->Draw("NJet>>njet",cuts);
 double n = njet->Integral();
 n = lumi*n;

  c->Close();
 }
 else if (opt == "data"){
   TString cuts =wt+ " * ("+ flow +")";
  double n = t->GetEntries(cuts);
  n*=weight;
 }
 else if (opt == "W+jets"){
   TString cuts =wt+ " * ("+ flow +")";
  double n = t->GetEntries(cuts);
  n*=weight;
  n=lumi*n;
  n=1.29557302*n;
 }
 else if (opt == "tt"){
   TString cuts =wt+ " * ("+ flow +")";
  double n = t->GetEntries(cuts);
  n*=weight;
  n=lumi*n;
  n=1.65789474*n;
 }
 else{
   TString cuts =wt+ " * ("+ flow +")";
  double n = t->GetEntries(cuts);
  n*=weight;
  n=lumi*n;
 }
 return n;
}
