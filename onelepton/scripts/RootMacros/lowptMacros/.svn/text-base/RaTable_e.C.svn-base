TString plot_dir = "eletree/";

TString selec = "Signal_";
TString aselec = "Control_";
TString plotting = "~/Plots/SAS/";

//TCut trig = triga || trigb || trigc;
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v1 + trig_HT150v3 + trig_HT160v1 + trig_HT160v3) > 0";
TCut h_j_pt = "(High_Jet_Pt > 70.)";
TCut e_odd = "ElectronOdd ==0";
TCut nmu = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";

TCut trigData = trig && hbhe;

TCut ne = "NElectrons ==1";

TCut e_pt = "ElectronPt[0]<25.";

TString lumi = "35pb";
Double_t lumm = 34.7;

Double_t d_aT = 0.51;
TString s_aT = "0.51";
UInt_t lobinat = 51;
UInt_t hibinat = 52;
TCut ele =ne && e_pt;
 TCut npho = "NPhotons == 0";
 TCut nj = "NJet >= 2";
TCut j1pt = "JetPt[1]>50.";
TCut jodd = "JetOdd ==0";
TCut bmu = "badMuonJet ==1";
TCut jeta1 = "JetEta[0] < 2.4";
TCut jeta2 = "JetEta[0] > -2.4";
TCut h250 = "HT > 250.";
TCut h200 = "HT_Lep > 200.";
TCut h300 = "HT_Lep > 300.";
TCut h350 = "HT_Lep > 350.";
TCut alphat = "AlphaT_Lep > "+s_aT;

TCut secondEle = "NLElectrons < 2";
TCut looseMuon = "NLMuons == 0";



TCut numlepData = trig && h250 && sel && hbhe && ele && e_odd && nmu && mu_odd && secondEle && looseMuon;
TCut numlep =  h250 && sel && ele && e_odd && nmu && mu_odd && secondEle && looseMuon;
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




TFile *sfLM0 = new TFile("eAlphaT_"+selec+"LM0.root");
TFile *sfLM1 = new TFile("eAlphaT_"+selec+"LM1.root");
TFile *sfTT = new TFile("eAlphaT_"+selec+"ttbarTauola.root");
TFile *sfQCDEM = new TFile("eAlphaT_"+selec+"QCDEM.root");
TFile *sfQCDBCE = new TFile("eAlphaT_"+selec+"QCDBCE.root");
TFile *sfQCD170 = new TFile("eAlphaT_"+selec+"QCD170.root");

TFile *sfW = new TFile("eAlphaT_"+selec+"Wjets_vols.root");
TFile *sfZ = new TFile("eAlphaT_"+selec+"ZJets_madgraph.root");
TFile *sfData = new TFile("eAlphaT_"+selec+"RA1Data.root");
TFile *sfSM = new TFile("eAlphaT_"+selec+"SM.root");
TFile *sfEWK = new TFile("eAlphaT_"+selec+"EWK.root");
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
TTree *stSM = (TTree*)sfSM->Get(plot_dir+"/T");
TTree *stEWK = (TTree*)sfEWK->Get(plot_dir+"/T"); 
TFile *asfLM0 = new TFile("eAlphaT_"+aselec+"LM0.root");
TFile *asfLM1 = new TFile("eAlphaT_"+aselec+"LM1.root");
TFile *asfTT = new TFile("eAlphaT_"+aselec+"ttbarTauola.root");

TFile *asfQCDEM = new TFile("eAlphaT_"+aselec+"QCDEM.root");
TFile *asfQCDBCE = new TFile("eAlphaT_"+aselec+"QCDBCE.root");
TFile *asfQCD170 = new TFile("eAlphaT_"+aselec+"QCD170.root");
TFile *asfW = new TFile("eAlphaT_"+aselec+"Wjets_vols.root");
TFile *asfZ = new TFile("eAlphaT_"+aselec+"ZJets_madgraph.root");
TFile *asfData = new TFile("eAlphaT_"+aselec+"Data_34.root");
TFile *asfSM = new TFile("eAlphaT_"+aselec+"SM.root");
TTree *astLM0 = (TTree*)asfLM0->Get(plot_dir+"/T");
TTree *astLM1 = (TTree*)asfLM1->Get(plot_dir+"/T");
TTree *astTT = (TTree*)asfTT->Get(plot_dir+"/T");

TTree *astQCDEM = (TTree*)asfQCDEM->Get(plot_dir+"/T");
TTree *astQCDBCE = (TTree*)asfQCDBCE->Get(plot_dir+"/T");
TTree *astQCD170 = (TTree*)asfQCD170->Get(plot_dir+"/T");
TTree *astW = (TTree*)asfW->Get(plot_dir+"/T");
TTree *astZ = (TTree*)asfZ->Get(plot_dir+"/T");
TTree *astData = (TTree*)asfData->Get(plot_dir+"/T");
TTree *astSM = (TTree*)asfSM->Get(plot_dir+"/T");





Double_t intlumi = 100.; //2.880;
TString luminum = "100";//"2.880";

void RaTable_e(){

  // TH1D* all = GetHist("Data", "JetEta[0]",trigMC+numpj,"(12,0.,3.)",tData,"noHT");

  // SAS_RaTPlot(stData,astData,trigMC+numpj,"noHT");
  /*  SAS_RaTPlot(stSM,astSM,trigMC+numpj,"noHT","SM");
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
  //   
}


void table(){

 cout << "\n";
 cout << " Electron RaT Table - MonteCarlo at 35pb \n\n";
 cout.width(7); cout << " HT Cut "; 
 cout.width(28); cout << "|   Upper Bound on QCD  ";
 cout.width(31); cout << "|   Observed Evts (aT>"+s_aT+")";
cout.width(24); cout << "| True MC QCD (aT>"+s_aT+")";
cout.width(27); cout << "|   True MC EWK (aT>"+s_aT+")";
 cout.width(1); cout << "\n";
 cout.width(121); cout.fill('-'); cout << "\n";

 cout.fill(' ');

 NaT(stSM,astSM,stQCDEM,stQCDBCE,stQCD170,stEWK,numpj,"Object Cuts","MC");
   //     NaT(stSM,astSM,stQCD,stEWK,HT200,"HT>200");
   //    NaT(stSM,astSM,stQCD,stEWK,HT300,"HT>300");
 NaT(stSM,astSM,stQCDEM,stQCDBCE,stQCD170,stEWK,HT300,"HT_Lep>300","MC");
 NaT(stSM,astSM,stQCDEM,stQCDBCE,stQCD170,stEWK,HT350,"HT_Lep>350","MC");
    cout.width(121); cout.fill('-'); cout << "\n";
    cout << "\n";
    //    cout << "In Data using this method we obtain the following " << endl; 

    NaT(stData,astData,stQCDEM,stQCDBCE,stQCD170,stEWK,numpjData,"After Object Cuts","Data");
 NaT(stData,astData,stQCDEM,stQCDBCE,stQCD170,stEWK,HT300Data,"After HT_Lep > 300","Data");
    NaT(stData,astData,stQCDEM,stQCDBCE,stQCD170,stEWK,HT350Data,"After HT_Lep > 350","Data");
}

void NaT(TTree *sel, TTree *asel,TTree *qcdem, TTree *qcdbce, TTree *qcd170, TTree *ewk, TCut flow,TString point, TString type){

 if (type == "Data"){
 TH1D* s_at = GetHist("Data","AlphaT_Lep",flow,"(100,0.,1.)",sel);
 TH1D* as_at = GetHist("Data","AlphaT_Lep",flow,"(100,0.,1.)",asel);
 }

 if (type != "Data"){

 TH1D* s_W= GetHist("S_W","AlphaT_Lep",flow,"(100,0.,1.)",stW);
 TH1D* s_tt = GetHist("S_tt","AlphaT_Lep",flow,"(100,0.,1.)",stTT);
TH1D* s_Z = GetHist("S_tt","AlphaT_Lep",flow,"(100,0.,1.)",stZ);
 TH1D* as_W= GetHist("AS_W","AlphaT_Lep",flow,"(100,0.,1.)",astW);
 TH1D* as_tt = GetHist("AS_tt","AlphaT_Lep",flow,"(100,0.,1.)",astTT);
TH1D* as_Z = GetHist("AS_tt","AlphaT_Lep",flow,"(100,0.,1.)",astZ);


s_W->Scale(1.29557302);
s_tt->Scale(1.65789474);
 s_Z->Scale(3048./2400.);
as_W->Scale(1.29557302);
 as_tt->Scale(1.65789474);
 as_Z->Scale(3048./2400.);

 TH1D *s_ewk = (TH1D*)s_W->Clone();
 s_ewk->Add(s_Z);
 s_ewk->Add(s_tt);
TH1D *as_ewk   = (TH1D*)as_W->Clone();
 as_ewk->Add(as_Z);
 as_ewk->Add(as_tt);
 //cout << " when the as_a

 TH1D* s_qcd_em = GetHist("S_QCD_EM","AlphaT_Lep",flow,"(100,0.,1.)",stQCDEM);
 TH1D* s_qcd_bce = GetHist("S_QCD_BCE","AlphaT_Lep",flow,"(100,0.,1.)",stQCDBCE);
 TH1D* s_qcd_170 = GetHist("S_QCD_170","AlphaT_Lep",flow,"(100,0.,1.)",stQCD170);
 TH1D* as_qcd_em = GetHist("S_QCD_EM","AlphaT_Lep",flow,"(100,0.,1.)",astQCDEM);
 TH1D* as_qcd_bce = GetHist("S_QCD_BCE","AlphaT_Lep",flow,"(100,0.,1.)",astQCDBCE);
 TH1D* as_qcd_170 = GetHist("S_QCD_170","AlphaT_Lep",flow,"(100,0.,1.)",astQCD170);

 //s_qcd_em->Scale(1.5);
 // s_qcd_170->Scale(4.35);

 //  as_qcd_em->Scale(1.5);
 //  as_qcd_170->Scale(3.07);



   TH1D* s_qcd = s_qcd_bce->Clone();
   s_qcd->Add(s_qcd_em);
   s_qcd->Add(s_qcd_170);


   TH1D* as_qcd = as_qcd_bce->Clone();
   as_qcd->Add(as_qcd_em);
   as_qcd->Add(as_qcd_170);
 TH1D *s_at = (TH1D*)s_ewk->Clone();
 s_at->Add(s_qcd);

 TH1D *as_at= (TH1D*)as_ewk->Clone();
 as_at->Add(as_qcd);

 }

 
 /* cout << "Bin 0.lobinat = " << s_at->GetXaxis()->FindBin(0.lobinat) << endl; */
 /* cout << "Bin center is = " << s_at->GetBinCenter(s_at->GetXaxis()->FindBin(0.lobinat) ) << endl; */
 /* cout << "Next bin is = " << s_at->GetBinCenter(s_at->GetXaxis()->FindBin(0.hibinat) ) << endl; */
 if (as_at->Integral(hibinat,as_at->GetNbinsX()) > 0){
  Double_t Ctrl_ratio = (as_at->Integral(hibinat,as_at->GetNbinsX()))/(as_at->Integral(0,lobinat));
  Double_t Ctrl_ratio_error=error(as_at->Integral(hibinat,as_at->GetNbinsX()),as_at->Integral(0,lobinat));
  Double_t Sig_below = s_at->Integral(0,lobinat);
  Double_t Sig_below_error = sqrt(s_at->Integral(0,lobinat));



 Double_t combinationA = ((Ctrl_ratio_error/Ctrl_ratio)*(Ctrl_ratio_error/Ctrl_ratio));
 Double_t combinationB = ((Sig_below_error/Sig_below)*(Sig_below_error/Sig_below));




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
 
  //   cout << " The ratio in the CTRL region is " << Ctrl_ratio << " +/- " << Ctrl_ratio_error << " and the number of events below aT 0.55 in SIG region is " << Sig_below << endl;
  //  cout << endl;
  //  cout << "Hence the number of predicted events in the SIG region with aT > 0.55 is " << Sig_above << " +/- "<< Sig_above_error << "  while the actual SM is " << Actual_Sig_above << " +/- " << sqrt(Actual_Sig_above) << endl;
  // cout << "BUT the actual QCD above in signal region is : " << Actual_sQCD_above << " +/= " << sqrt(Actual_sQCD_above) << " whereas EWK is : " << Actual_sEWK_above << "+/-" << sqrt(Actual_sEWK_above) << endl;

  // cout.width(122); cout.fill('-'); cout << "\n";
  // cout << endl;
  if (type =="Data"){
cout.precision(4);
    cout << point + " the Upper bound on QCD predicted from "+lumi+" data is: " << Sig_above << " +/- " << Sig_above_error << endl;
    cout << point + " the  Actual events in "+lumi+" data is " << Actual_Sig_above << " +/- " << sqrt(Actual_Sig_above) << endl;
  cout << endl;
  }
  else{
    cout.precision(4);
    cout.width(11); cout << point; cout.width(2); cout << "|";
  cout.width(11); cout << Sig_above; cout.width(5); cout << "  +/-"; cout.width(10); cout << Sig_above_error; cout.width(2); cout << " |";
  cout.width(11); cout << Actual_Sig_above; cout.width(5); cout << "  +/-"; cout.width(10); cout << sqrt(Actual_Sig_above); cout.width(2); cout << " |";
  cout.width(10); cout << Actual_sQCD_above; cout.width(5); cout << "   +/-"; cout.width(7); cout << sqrt(Actual_sQCD_above); cout.width(2); cout << " |";
  cout.width(10); cout << Actual_sEWK_above; cout.width(5); cout << "  +/-"; cout.width(9); cout << sqrt(Actual_sEWK_above); cout.width(2); cout << " | ";cout << "\n";


  }
 }

 else(){
   cout << "the RaT method cannot be used at this stage (" << point << ") because there lack statistics to populate the aT>"+s_aT+" in Control Region" << endl;
 }


  //  cout.width (10); cout << Actual_Sig_above << " +/- " << sqrt(Actual_Sig_above) << "   | ";
  //cout.width (12); cout << Actual_sQCD_above << " +/- " << sqrt(Actual_sQCD_above) << "     | ";
  // cout.width (9); cout << Actual_sEWK_above << " +/- " << sqrt(Actual_sEWK_above) << "\n";
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
 s->GetYaxis()->SetTitle("N(above aT "+s_aT+") / N(all)");
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
