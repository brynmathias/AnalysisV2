TString plot_dir = "mutree_iso";

TString selec = "Signal_";
TString aselec = "Control_";
TString plotting = "~/Plots/SAS/";


//TCut trig = triga || trigb || trigc;

TString lumi = "35pb";
Double_t lumm = 34.7;

Double_t d_aT = 0.51;
TString s_aT = "0.51";
UInt_t lobinat = 51;
UInt_t hibinat = 52;

TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v1 + trig_HT150v3 + trig_HT160v1 + trig_HT160v3) > 0";
TCut triga = "trig_HT100 == 1";

TCut trigb = "trig_HT120 == 1";

TCut trigc = "trig_HT140 == 1";
TCut trigd = "trig_HT150 ==1";
TCut trige = "trig_HT150v1 ==1";
TCut trigf = "trig_HT150v3 ==1";
TCut trigg = "trig_HT160 ==1";
TCut trigh = "trig_HT160v1 ==1";
TCut trigi = "trig_HT160v3 ==1";


//TCut trig = triga || trigb || trigc || trige || trigf || trigh || trigi;
//TCut trig = triga || trigb || trigc || trigd || trigg;
TCut h_j_pt = "(High_Jet_Pt > 70.)";
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

TCut trigData = trig && hbhe;






TCut nmu = "NMuons ==1";


TCut mu_pt = "MuonPt[0] >10. && MuonPt[0] < 25.";
TCut mu_pt_hi = "MuonPt[0]>10.";
TCut mu_pt_lo = "MuonPt[0]<10.";

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
TCut alphat = "AlphaT_Lep > "+s_aT;

TCut htt300 = "HT > 300.";
TCut preData = trig && h250;
TCut numlepData =  preData && sel && hbhe && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numlep =  h250 && sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numlepX = sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numpj = numlep && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
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


TFile *sfLM0 = new TFile("muAlphaT_"+selec+"LM0.root");
TFile *sfLM1 = new TFile("muAlphaT_"+selec+"LM1.root");
TFile *sfTT = new TFile("muAlphaT_"+selec+"ttbarTauola.root");
TFile *sfQCD = new TFile("muAlphaT_"+selec+"QCD_Mu.root");
TFile *sfW = new TFile("muAlphaT_"+selec+"Wjets_vols.root");
TFile *sfZ = new TFile("muAlphaT_"+selec+"ZJets_madgraph.root");
TFile *sfData = new TFile("muAlphaT_"+selec+"RA1Data.root");
TFile *sfSM = new TFile("muAlphaT_"+selec+"SM.root");
TFile *sfEWK = new TFile("muAlphaT_"+selec+"EWK.root");
//TFile *sfSUS = new TFile("eAlphaT_"+selec+"SUSLM0.root");

//TTree *stSUS = (TTree*)sfSUS->Get(plot_dir+"/T");
TTree *stLM0 = (TTree*)sfLM0->Get(plot_dir+"/T");
TTree *stLM1 = (TTree*)sfLM1->Get(plot_dir+"/T");
TTree *stTT = (TTree*)sfTT->Get(plot_dir+"/T");
TTree *stQCD = (TTree*)sfQCD->Get(plot_dir+"/T");
TTree *stW = (TTree*)sfW->Get(plot_dir+"/T");
TTree *stZ = (TTree*)sfZ->Get(plot_dir+"/T");
TTree *stData = (TTree*)sfData->Get(plot_dir+"/T");
TTree *stSM = (TTree*)sfSM->Get(plot_dir+"/T");
TTree *stEWK = (TTree*)sfEWK->Get(plot_dir+"/T"); 

TFile *asfEWK = new TFile("muAlphaT_"+aselec+"EWK.root");
TFile *asfLM0 = new TFile("muAlphaT_"+aselec+"LM0.root");
TFile *asfLM1 = new TFile("muAlphaT_"+aselec+"LM1.root");
TFile *asfTT = new TFile("muAlphaT_"+aselec+"ttbarTauola.root");
TFile *asfQCD = new TFile("muAlphaT_"+aselec+"QCD_Mu.root");
TFile *asfW = new TFile("muAlphaT_"+aselec+"Wjets_vols.root");
TFile *asfZ = new TFile("muAlphaT_"+aselec+"ZJets_madgraph.root");
TFile *asfData = new TFile("muAlphaT_"+aselec+"Data_34.root");
TFile *asfSM = new TFile("muAlphaT_"+aselec+"SM.root");
TTree *astLM0 = (TTree*)asfLM0->Get(plot_dir+"/T");
TTree *astLM1 = (TTree*)asfLM1->Get(plot_dir+"/T");
TTree *astTT = (TTree*)asfTT->Get(plot_dir+"/T");
TTree *astQCD = (TTree*)asfQCD->Get(plot_dir+"/T");
TTree *astW = (TTree*)asfW->Get(plot_dir+"/T");
TTree *astZ = (TTree*)asfZ->Get(plot_dir+"/T");
TTree *astData = (TTree*)asfData->Get(plot_dir+"/T");
TTree *astSM = (TTree*)asfSM->Get(plot_dir+"/T");
TTree *astEWK = (TTree*)asfEWK->Get(plot_dir+"/T"); 




Double_t intlumi = 100.; //2.880;
TString luminum = "100";//"2.880";

void RaTable_mu(){

  // TH1D* all = GetHist("Data", "JetEta[0]",trigMC+numpj,"(12,0.,3.)",tData,"noHT");
  //SAS_RaTPlot(stData,astData,HT200Data,"noHT","Data");
//  SAS_RaTPlot(stData,astData,HT200,"noHT","Data");
  // SAS_RaTPlot(stSM,astSM,HT200,"noHT","SM");
  /*
 SAS_RaTPlot(stSM,astSM,trigMC+numpj,"HT200","SM");
 SAS_RaTPlot(stSM,astSM,trigMC+numpj,"HT300","SM");
 SAS_RaTPlot(stSM,astSM,trigMC+numpj,"HT350","SM");
  */

  //   HT_RaTPlot(stSUS,"Signal","SUSY");
  // SAS_RaTPlot(stSM,astSM,trigMC+numpj,"noHT","SM");


    table();

  // NaT(stSM,astSM,stQCD,stEWK,numpj,"no HT");
  //  NaT(stSM,astSM,stQCD,stEWK,HT200,"HT>200");
  //  NaT(stSM,astSM,stQCD,stEWK,HT300,"HT>300");
  //  NaT(stSM,astSM,stQCD,stEWK,HT350,"HT>350");
 }


void table(){

 cout << "\n";
 cout << " Muon RaT Table - MonteCarlo at 35pb \n\n";
 cout.width(7); cout << " HT Cut "; 
 cout.width(28); cout << "|   Upper Bound on QCD  ";
 cout.width(31); cout << "|   Observed Evts (aT>"+s_aT+")";
cout.width(24); cout << "| True MC QCD (aT>"+s_aT+")";
cout.width(27); cout << "|   True MC EWK (aT>"+s_aT+")";
 cout.width(1); cout << "\n";
 cout.width(121); cout.fill('-'); cout << "\n";

 cout.fill(' ');

 NaT(stEWK,astEWK,stQCD,astQCD,stEWK,numpj,"Object Cuts","MC");
   //     NaT(stSM,astSM,stQCD,stEWK,HT200,"HT>200");
   //    NaT(stSM,astSM,stQCD,stEWK,HT300,"HT>300");
 NaT(stEWK,astEWK,stQCD,astQCD,stEWK,HT300,"HT_Lep>300","MC");
 NaT(stEWK,astEWK,stQCD,astQCD,stEWK,HT350,"HT_Lep>350","MC");
    cout.width(121); cout.fill('-'); cout << "\n";
    cout << "\n";
    //    cout << "In Data using this method we obtain the following " << endl; 

    NaT(stData,astData,stQCD,astQCD,stEWK,numpjData,"After Object Cuts","Data");
    NaT(stData,astData,stQCD,astQCD,stEWK,HT300Data,"After HT_Lep > 300","Data");
  NaT(stData,astData,stQCD,astQCD,stEWK,HT350Data,"After HT_Lep > 350","Data");
}

void NaT(TTree *sel, TTree *asel,TTree *qcd,TTree *aqcd, TTree *ewk, TCut flow,TString point, TString type){
  TCut hi = flow && mu_pt_hi;
  TCut lo = flow && mu_pt_lo;

  if (type == "Data"){


 TH1D* s_at = GetHist("Data","AlphaT_Lep",flow,"(100,0.,1.)",sel);
 TH1D* as_at = GetHist("Data","AlphaT_Lep",flow,"(100,0.,1.)",asel);
  }
  else if (type != "Data"){



  
    TH1D* s_qcd = GetHist("S_QCD","AlphaT_Lep",flow,"(100,0.,1.)",qcd);
    //    TH1D* s_qcd_lo = GetHist("S_QCDlo","AlphaT_Lep",lo,"(100,0.,1.)",qcd);


    // s_qcd_lo->Scale(1.94);
    //s_qcd->Add(s_qcd_lo);


 


 TH1D* s_W= GetHist("S_W","AlphaT_Lep",flow,"(100,0.,1.)",stW);
 TH1D* s_tt = GetHist("S_tt","AlphaT_Lep",flow,"(100,0.,1.)",stTT);
TH1D* s_Z = GetHist("S_tt","AlphaT_Lep",flow,"(100,0.,1.)",stZ);

s_W->Scale(1.29557302);
s_tt->Scale(1.65789474);
 s_Z->Scale(3048./2400.);
 TH1D *s_ewk = (TH1D*)s_W->Clone();
 s_ewk->Add(s_Z);
 s_ewk->Add(s_tt);

 TH1D *s_at = (TH1D*)s_ewk->Clone();
 s_at->Add(s_qcd);

 TH1D* as_qcd = GetHist("AS_QCD","AlphaT_Lep",hi,"(100,0.,1.)",aqcd);
    TH1D* as_qcd_lo = GetHist("AS_QCDlo","AlphaT_Lep",lo,"(100,0.,1.)",aqcd);
    //cout << "qcdhi  " <<  as_qcd->Integral(56,as_qcd->GetNbinsX()) << " and below " << (as_qcd->Integral(0,55)) << endl;
    //cout << "qcdlo  " <<  as_qcd_lo->Integral(56,as_qcd->GetNbinsX()) << " and below " << (as_qcd_lo->Integral(0,55)) << endl;
 as_qcd_lo->Scale(1.94);
 //cout << "qcdlo after scaling " <<  as_qcd_lo->Integral(56,as_qcd->GetNbinsX()) << " and below " << (as_qcd_lo->Integral(0,55)) << endl;
 as_qcd->Add(as_qcd_lo);
 // cout << "qcd after adding  " <<  as_qcd->Integral(56,as_qcd->GetNbinsX()) << " and below " << (as_qcd->Integral(0,55)) << endl;
 TH1D* as_W= GetHist("AS_W","AlphaT_Lep",flow,"(100,0.,1.)",astW);
 TH1D* as_tt = GetHist("AS_tt","AlphaT_Lep",flow,"(100,0.,1.)",astTT);
TH1D* as_Z = GetHist("AS_tt","AlphaT_Lep",flow,"(100,0.,1.)",astZ);
as_W->Scale(1.29557302);
 as_tt->Scale(1.65789474);
 as_Z->Scale(3048./2400.);

 TH1D *as_ewk   = (TH1D*)as_W->Clone();
 as_ewk->Add(as_Z);
 as_ewk->Add(as_tt);

 TH1D *as_at= (TH1D*)as_ewk->Clone();
 as_at->Add(as_qcd);


  }


 /* cout << "Bin 0.47 = " << s_at->GetXaxis()->FindBin(0.47) << endl; */
 /* cout << "Bin center is = " << s_at->GetBinCenter(s_at->GetXaxis()->FindBin(0.47) ) << endl; */
 /* cout << "Next bin is = " << s_at->GetBinCenter(s_at->GetXaxis()->FindBin(0.56) ) << endl; */

  Double_t Ctrl_ratio = (as_at->Integral(hibinat,as_at->GetNbinsX()))/(as_at->Integral(0,lobinat));
  Double_t Ctrl_ratio_error=error(as_at->Integral(hibinat,as_at->GetNbinsX()),as_at->Integral(0,lobinat));
  Double_t Sig_below = s_at->Integral(0,lobinat);
  Double_t Sig_below_error = sqrt(s_at->Integral(0,lobinat));

 Double_t combinationA = ((Ctrl_ratio_error/Ctrl_ratio)*(Ctrl_ratio_error/Ctrl_ratio));
 Double_t combinationB = ((Sig_below_error/Sig_below)*(Sig_below_error/Sig_below));

 //cout << "after the scaling " << as_at->Integral(56,as_at->GetNbinsX()) << " and below " << (as_at->Integral(0,55)) << endl;
 


  Double_t Sig_above = Ctrl_ratio * Sig_below;

 Double_t  Sig_above_error = sqrt((Sig_above*Sig_above)*(combinationA + combinationB));
  Double_t Actual_Sig_above = s_at->Integral(hibinat,s_at->GetNbinsX());
  if (type != "Data"){
  Double_t Actual_sQCD_above = s_qcd->Integral(hibinat,s_qcd->GetNbinsX());
  Double_t Actual_sEWK_above =  s_ewk->Integral(hibinat,s_ewk->GetNbinsX());}

  //cout << endl;
  //cout.width(122); cout.fill('-'); cout << "\n";

  //cout << " The point at which this calculation is done is: " << point << endl;/
  //cout << endl;
 
  //   cout << " The ratio in the CTRL region is " << Ctrl_ratio << " +/- " << Ctrl_ratio_error << " and the number of events below aT 0.49 in SIG region is " << Sig_below << endl;
  //  cout << endl;
  //  cout << "Hence the number of predicted events in the SIG region with aT > 0.49 is " << Sig_above << " +/- "<< Sig_above_error << "  while the actual SM is " << Actual_Sig_above << " +/- " << sqrt(Actual_Sig_above) << endl;
  // cout << "BUT the actual QCD above in signal region is : " << Actual_sQCD_above << " +/= " << sqrt(Actual_sQCD_above) << " whereas EWK is : " << Actual_sEWK_above << "+/-" << sqrt(Actual_sEWK_above) << endl;

  // cout.width(122); cout.fill('-'); cout << "\n";
  // cout << endl;
  if (type =="Data"){
    cout.precision(4);
    cout << point + " the Upper bound on QCD predicted from "+lumi+" data is: " << Sig_above << " +/- " << Sig_above_error << endl;
 cout.precision(4);
    cout << point + " the  Actual events in "+lumi+" data is " << Actual_Sig_above << " +/- " << sqrt(Actual_Sig_above) << endl;
  cout << endl;
  }
  else{
    cout.precision(4);
    cout.width(11); cout << point; cout.width(2); cout << "|";
  cout.width(11); cout << Sig_above; cout.width(5); cout << "  +/-"; cout.width(10); cout << Sig_above_error; cout.width(2); cout << " |";
 cout.precision(4);
  cout.width(11); cout << Actual_Sig_above; cout.width(5); cout << "  +/-"; cout.width(10); cout << sqrt(Actual_Sig_above); cout.width(2); cout << " |";
 cout.precision(4);
  cout.width(10); cout << Actual_sQCD_above; cout.width(5); cout << "   +/-"; cout.width(7); cout << sqrt(Actual_sQCD_above); cout.width(2); cout << " |";
 cout.precision(4);
  cout.width(10); cout << Actual_sEWK_above; cout.width(5); cout << "  +/-"; cout.width(9); cout << sqrt(Actual_sEWK_above); cout.width(2); cout << "\n";
 cout.precision(4);


}
  //  cout.width (10); cout << Actual_Sig_above << " +/- " << sqrt(Actual_Sig_above) << "   | ";
  //cout.width (12); cout << Actual_sQCD_above << " +/- " << sqrt(Actual_sQCD_aove) << "     | ";
  // cout.width (9); cout << Actual_sEWK_above << " +/- " << sqrt(Actual_sEWK_above) << "\n";
  }



void SAS_RaTPlot(TTree *t1, TTree *t2, TCut flow, TString point, TString set){
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
 s->GetYaxis()->SetTitle("N(above aT"+s_aT+") / N(all)");
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
 HT200->GetYaxis()->SetTitle("N(above aT "+s_aT+") / N(all)");
 HT200->GetYaxis()->SetTitleOffset(1.2);
 leg->Draw("SAME");
 c7->Update();
 c7->SaveAs(plotting+"RaT_HTbins_"+set+"_"+sel+".png");

}

TH1D* RaT(TTree* t,Color_t icol,TCut cuts,TString point,TString iden, TString iden2){

 TH1::SetDefaultSumw2(true);
 if (iden2 == "Data"){
    TH1D* above = GetHist2("SData",cuts,t,point, "Above");
  TH1D* all = GetHist2("SData",cuts,t,point, "All");

 }
 else if(iden2 == "SM"){
TCut mu_pt_hi = "MuonPt[0]>10.";
TCut mu_pt_lo = "MuonPt[0]<=10.";

 TCut hi = cuts && mu_pt_hi;
 TCut lo = cuts && mu_pt_lo;

   if (iden == "S"){

    TH1D* W_ab = GetHist2("SW",cuts,stW,point, "Above");
  TH1D* W_all = GetHist2("SW",cuts,stW,point, "All");
 TH1D* TT_ab = GetHist2("STT",cuts,stTT,point, "Above");
  TH1D* TT_all = GetHist2("STT",cuts,stTT,point, "All");
 TH1D* Z_ab = GetHist2("SZ",cuts,stZ,point, "Above");
  TH1D* Z_all = GetHist2("SZ",cuts,stZ,point, "All");
 TH1D* QCDlo_ab = GetHist2("SQCDlo",lo,stQCD,point, "Above");
  TH1D* QCDlo_all = GetHist2("SQCDlo",lo,stQCD,point, "All");
   TH1D* QCDhi_ab = GetHist2("SQCDhi",hi,stQCD,point, "Above");
  TH1D* QCDhi_all = GetHist2("SQCDhi",hi,stQCD,point, "All"); 


  QCDlo_ab->Scale(1.94);
  QCDlo_all->Scale(1.94);
W_ab->Scale(1.29557302);
TT_ab->Scale(1.65789474);
 Z_ab->Scale(3048./2400.);
W_all->Scale(1.29557302);
TT_all->Scale(1.65789474);
 Z_all->Scale(3048./2400.);


 TH1D* above = W_ab->Clone();
 above->Add(Z_ab);
 above->Add(TT_ab);
 above->Add(QCDlo_ab);
 above->Add(QCDhi_ab);

 TH1D* all = W_all->Clone();
 all->Add(Z_all);
 all->Add(TT_all);
 all->Add(QCDlo_all);
 all->Add(QCDhi_all);


   }
 else if (iden == "AS"){

    TH1D* W_ab = GetHist2("ASW",cuts,astW,point, "Above");
  TH1D* W_all = GetHist2("ASW",cuts,astW,point, "All");
 TH1D* TT_ab = GetHist2("ASTT",cuts,astTT,point, "Above");
  TH1D*TT_all = GetHist2("ASTT",cuts,astTT,point, "All");
 TH1D* Z_ab = GetHist2("ASZ",cuts,astZ,point, "Above");
  TH1D* Z_all = GetHist2("ASZ",cuts,astZ,point, "All");
 TH1D* QCDlo_ab = GetHist2("ASQCDlo",lo,astQCD,point, "Above");
  TH1D* QCDlo_all = GetHist2("ASQCDlo",lo,astQCD,point, "All");
   TH1D* QCDhi_ab = GetHist2("ASQCDhi",hi,astQCD,point, "Above");
  TH1D* QCDhi_all = GetHist2("ASQCDhi",hi,astQCD,point, "All"); 


  QCDlo_ab->Scale(1.94);
  QCDlo_all->Scale(1.94);
W_ab->Scale(1.29557302);
TT_ab->Scale(1.65789474);
 Z_ab->Scale(3048./2400.);
W_all->Scale(1.29557302);
TT_all->Scale(1.65789474);
 Z_all->Scale(3048./2400.);


 TH1D* above = W_ab->Clone();
 above->Add(Z_ab);
 above->Add(TT_ab);
 above->Add(QCDlo_ab);
 above->Add(QCDhi_ab);

 TH1D* all = W_all->Clone();
 all->Add(Z_all);
 all->Add(TT_all);
 all->Add(QCDlo_all);
 all->Add(QCDhi_all);

 }

 above->Scale(3.47);
 all->Scale(3.47);
 }



  double err[6];
  // double rbin = 2;
  //  all->Rebin(rbin); above->Rebin(rbin);
  TH1D *Ratio = new TH1D("Ratio","Ratio",6,0.,3);
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

TH1D* GetHist(TString dataset, TString var, TCut flow,TString bin,TTree *t){
 
   
     
 TCanvas *c1 = new TCanvas("canny"+var+dataset,"canne"+var+dataset,400,400);
  t->Draw(var+">>hist"+bin,"(wgt)"*flow);
  TH1D *HIST= (TH1D*)gDirectory->Get("hist");
  HIST->SetName(dataset+var);
  c1->Close();

 


  if (dataset != "Data"){
    HIST->Scale(lumm/10.);
  }
  return HIST;
}
TH1D* GetHist2(TString dataset, TCut flow,TTree *t, TString poin, TString type){
  TCut aThi =  "AlphaT_Lep > "+s_aT;
  TCut aTlo =  "AlphaT_Lep < "+s_aT;
  TCut above = flow && aThi;
  TCut below = flow && aTlo;
  if(type == "All"){
     
 TCanvas *c1 = new TCanvas("canny1","canne1",400,400);
 t->Draw("JetEta[0]>>hist1(6,0.,3.)","(wgt)"*flow);
 TH1D *HIST1= (TH1D*)gDirectory->Get("hist1");
  HIST1->SetName("one_"+dataset+"JetEtaFabs"+poin+type);
 c1->Close();

 TCanvas *c2= new TCanvas("canny2","canne2",400,400);
  t->Draw("-1*JetEta[0]>>hist2(6,0.,3.)","(wgt)"*flow);
  TH1D *HIST2= (TH1D*)gDirectory->Get("hist2");
   HIST2->SetName("two_"+dataset+"JetEtaFabs"+poin+type);
   c2->Close();
  }



  else if(type == "Above"){


 TCanvas *c1 = new TCanvas("canny1","canne1",400,400);
 t->Draw("JetEta[0]>>hist1(6,0.,3.)","(wgt)"*above);
 TH1D *HIST1= (TH1D*)gDirectory->Get("hist1");
  HIST1->SetName("one_"+dataset+"JetEtaFabs"+poin+type);
 c1->Close();

  TCanvas *c2= new TCanvas("canny2","canne2",400,400);
  t->Draw("-1*JetEta[0]>>hist2(6,0.,3.)","(wgt)"*above);
  TH1D *HIST2= (TH1D*)gDirectory->Get("hist2");
   HIST2->SetName("two_"+dataset+"JetEtaFabs"+poin+type);
  c2->Close();

  }
 else if(type == "Below"){


 TCanvas *c1 = new TCanvas("canny1","canne1",400,400);
 t->Draw("JetEta[0]>>hist1(6,0.,3.)","(wgt)"*below);                         );
 TH1D *HIST1= (TH1D*)gDirectory->Get("hist1");
  HIST1->SetName("one_"+dataset+"JetEtaFabs"+poin+type);
 c1->Close();

  TCanvas *c2= new TCanvas("canny2","canne2",400,400);
  t->Draw("-1*JetEta[0]>>hist2(6,0.,3.)","(wgt)"*below);
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
