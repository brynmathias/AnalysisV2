#include "setTDRStyle.C"
//  muAlphaT_QCD_Pt30_7TeV_Pythia_skim.root
//  muAlphaT_QCD_Pt30and80_7TeV_Pythia_skim.root
//  muAlphaT_SD_JMT_SKMD.root
//  muAlphaT_MC_QCD15P8_SKMD.root
//  muAlphaT_Wjets_June2010.root
//  muAlphaT_QCD30and80andWjets.root
//  && mt_MuCaloMET < 40.
//  && pfMet < 20.
 
void mainFunction() {

  setTDRStyle();
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  
  //Define cuts
  TString cut_nMu = "nMu==1";
  TString cut_nEl = "nEl==0";
  TString cut_ptMu = "et_mu>=10.";
  TString cut_nJets = "nJet>=1";
  TString cut_etJet = "etJet[0]>=40";
  TString cut_relCombIso = "combIso<0.3";
  TString cut_ht = "ht > 80.";
  TString cut_pfMet = "pfMet < 20.";
  TString cutFlow = cut_nMu+" && "+cut_ptMu+" && "+cut_relCombIso+" && "+cut_nEl+" && "+cut_nJets+" && "+cut_etJet;
  TString cutVariable_Ctrl = "&& pfMet < 20.";
  TString cutVariable_Sig = "&& pfMet >= 0.";


  //create canvas
  TCanvas *cAlphaT_MC = createCanvas("cAlphaT_MC",true);
  cAlphaT_MC->Divide(3,2);
  TCanvas *cAlphaT_MCvsData = createCanvas("cAlphaT_MCvsData",true);
  cAlphaT_MCvsData->Divide(3,2);
  TCanvas *cAlphaT_Data = createCanvas("cAlphaT_Data",true);
  cAlphaT_Data->Divide(3,2);
  TCanvas *cRaTvsHT_MC = createCanvas("cRaTvsHT_MC",true);
  TCanvas *cRaTvsHT_Data = createCanvas("cRaTvsHT_Data",true);
  TCanvas *cRaTvsJetEta_HT0_MC = createCanvas("cRaTvsJetEta_HT0_MC",true);
  TCanvas *cRaTvsJetEta_HT80_MC = createCanvas("cRaTvsJetEta_HT80_MC",true);
  TCanvas *cRaTvsJetEta_Data = createCanvas("cRaTvsJetEta_Data",true);
  
  // create histos
  TH1F *hAlphaT_Ctrl_MC[6];
  TH1F *hAlphaT_Sig_MC[6];
  TH1F *hAlphaT_Ctrl_Data[6];
  TH1F *hAlphaT_Sig_Data[6];
  TH1F *hAlphaT_Ctrl_MC2Data[6];
  TH1F *hHT_Ctrl_MC[6];
  TH1F *hHT_Sig_MC[6];
  TH1F *hHT_Ctrl_Data[6];
  TH1F *hHT_Sig_Data[6];

  float tmpHT = 40.;
  UInt_t count = 0;
  while (tmpHT <= 190.) {

    cAlphaT_MC->cd(count+1);
    gPad->SetLogy();
    hAlphaT_Ctrl_MC[count] = 
      create1Dhisto_vsHT("muAlphaT_QCD30and80andWjets.root","alphaT","MC","Ctrl",cutFlow,cutVariable_Ctrl,tmpHT,80,-1.,3.,true);
    hAlphaT_Sig_MC[count] = 
      create1Dhisto_vsHT("muAlphaT_QCD30and80andWjets.root","alphaT","MC","Sig",cutFlow,cutVariable_Sig,tmpHT,80,-1.,3.,true);
    hAlphaT_Ctrl_MC[count]->GetXaxis()->SetRangeUser(0.,3.);
    hAlphaT_Ctrl_MC[count]->Draw("HIST E0");
    hAlphaT_Sig_MC[count]->Draw("HIST E0 sames");
    TLegend *legAlphaT_MC=legend1(hAlphaT_Ctrl_MC[count],hAlphaT_Sig_MC[count],"MC (Ctrl)","MC (Sig)");
    TLegend *legHT=legendHT(tmpHT);
    legAlphaT_MC->Draw("SAME");
    legHT->Draw("SAME");
    /*
    cAlphaT_MCvsData->cd(count+1);
    gPad->SetLogy();
    hAlphaT_Ctrl_MC2Data[count] = 
      create1Dhisto_vsHT("muAlphaT_QCD30and80andWjets.root","alphaT","MC","Ctrl",cutFlow,cutVariable_Ctrl,tmpHT,80,-1.,3.,true);
    hAlphaT_Sig_Data[count] = 
      create1Dhisto_vsHT("muAlphaT_SD_JMT_SKMD.root","alphaT","Data","Sig",cutFlow,cutVariable_Sig,tmpHT,80,-1.,3.,true);
    //    hAlphaT_Ctrl_MC2Data[count]->Sumw2();
    hAlphaT_Ctrl_MC2Data[count]->Scale((hAlphaT_Sig_Data[count]->Integral())/(hAlphaT_Ctrl_MC2Data[count]->Integral()));
    hAlphaT_Ctrl_MC2Data[count]->GetXaxis()->SetRangeUser(0.2,0.8);
    hAlphaT_Ctrl_MC2Data[count]->Draw("HIST E0");
    hAlphaT_Sig_Data[count]->Draw("HIST E0 sames");
    TLegend *legAlphaT_MCvsData=legend1(hAlphaT_Ctrl_MC2Data[count],hAlphaT_Sig_Data[count],"MC (Ctrl)","Data (Sig)");
    TLegend *legHT=legendHT(tmpHT);
    legAlphaT_MCvsData->Draw("SAME");
    legHT->Draw("SAME");

    cAlphaT_Data->cd(count+1);
    gPad->SetLogy();
    hAlphaT_Ctrl_Data[count] = 
      create1Dhisto_vsHT("muAlphaT_SD_JMT_SKMD.root","alphaT","Data","Ctrl",cutFlow,cutVariable_Ctrl,tmpHT,80,-1.,3.,true);
    //    hAlphaT_Sig_Data[count] = 
    //      create1Dhisto_vsHT("muAlphaT_SD_JMT_SKMD.root","alphaT","Data","Sig",cutFlow,cutVariable_Sig,tmpHT,80,-1.,3.,true);
    hAlphaT_Ctrl_Data[count]->GetXaxis()->SetRangeUser(0.2,0.8);
    hAlphaT_Ctrl_Data[count]->Draw("HIST E0");
    hAlphaT_Sig_Data[count]->Draw("HIST E0 sames");
    TLegend *legAlphaT_Data=legend1(hAlphaT_Ctrl_Data[count],hAlphaT_Sig_Data[count],"Data (Ctrl)","Data (Sig)");
    TLegend *legHT=legendHT(tmpHT);
    legAlphaT_Data->Draw("SAME");
    legHT->Draw("SAME");
    */

    tmpHT+=30;
    count++;
  }
  
  TH1F *hRaTvsHT_Ctrl_MC = createRaTvsHT_histo("muAlphaT_QCD30and80andWjets.root","MC","Ctrl",cutFlow,cutVariable_Ctrl,40.,190.,30.);
  hRaTvsHT_Ctrl_MC->SetName("hRaTvsHT_Ctrl_MC");
  hRaTvsHT_Ctrl_MC->GetYaxis()->SetRangeUser(0.001,1.);
  TH1F *hRaTvsHT_Sig_MC = createRaTvsHT_histo("muAlphaT_QCD30and80andWjets.root","MC","Sig",cutFlow,cutVariable_Sig,40.,190.,30.);
  hRaTvsHT_Sig_MC->SetName("hRaTvsHT_Sig_MC");
  cRaTvsHT_MC->cd();
  hRaTvsHT_Ctrl_MC->Draw("P E0");
  hRaTvsHT_Sig_MC->Draw("P E0 sames");
  TLegend *legRaTvsHT_MC=legend1(hRaTvsHT_Ctrl_MC,hRaTvsHT_Sig_MC,"MC (Ctrl)","MC (Sig)");
  legRaTvsHT_MC->Draw("SAME");
  
  /*
  TH1F *hRaTvsHT_Ctrl_Data = createRaTvsHT_histo("muAlphaT_SD_JMT_SKMD.root","Data","Ctrl",cutFlow,cutVariable_Ctrl,40.,190.,30.);
  hRaTvsHT_Ctrl_Data->SetName("hRaTvsHT_Ctrl_MC");
  hRaTvsHT_Ctrl_Data->GetYaxis()->SetRangeUser(0.001,1.);
  TH1F *hRaTvsHT_Sig_Data = createRaTvsHT_histo("muAlphaT_SD_JMT_SKMD.root","Data","Sig",cutFlow,cutVariable_Sig,40.,190.,30.);
  hRaTvsHT_Sig_Data->SetName("hRaTvsHT_Sig_MC");
  cRaTvsHT_Data->cd();
  hRaTvsHT_Ctrl_Data->Draw("P E0");
  hRaTvsHT_Sig_Data->Draw("P E0 sames");
  TLegend *legRaTvsHT_Data=legend1(hRaTvsHT_Ctrl_Data,hRaTvsHT_Sig_Data,"Data (Ctrl)","Data (Sig)");
  legRaTvsHT_Data->Draw("SAME");
  */
  
  TH1F *hRaTvsJetEta_Ctrl_HT0_MC = createRaTvsJetEta_histo("muAlphaT_QCD30and80andWjets.root","MC","Ctrl",cutFlow,cutVariable_Ctrl," && ht>=0.");
  hRaTvsJetEta_Ctrl_HT0_MC->SetName("hRaTvsJetEta_Ctrl_HT0_MC");
  hRaTvsJetEta_Ctrl_HT0_MC->GetYaxis()->SetRangeUser(0.001,1.);
  TH1F *hRaTvsJetEta_Sig_HT0_MC = createRaTvsJetEta_histo("muAlphaT_QCD30and80andWjets.root","MC","Sig",cutFlow,cutVariable_Sig," && ht>=0.");
  hRaTvsJetEta_Sig_HT0_MC->SetName("hRaTvsJetEta_Sig_HT0_MC");
  cRaTvsJetEta_HT0_MC->cd();
  hRaTvsJetEta_Ctrl_HT0_MC->Draw("P E0");
  hRaTvsJetEta_Sig_HT0_MC->Draw("P E0 sames");
  TLegend *legRaTvsHT_MC=legend1(hRaTvsHT_Ctrl_MC,hRaTvsHT_Sig_MC,"MC (Ctrl)","MC (Sig)");
  TLegend *legHT0=legendHT(0.);
  legRaTvsHT_MC->Draw("SAME");
  legHT0->Draw("SAME");

  TH1F *hRaTvsJetEta_Ctrl_HT80_MC = createRaTvsJetEta_histo("muAlphaT_QCD30and80andWjets.root","MC","Ctrl",cutFlow,cutVariable_Ctrl," && ht>=80.");
  hRaTvsJetEta_Ctrl_HT80_MC->SetName("hRaTvsJetEta_Ctrl_HT80_MC");
  hRaTvsJetEta_Ctrl_HT80_MC->GetYaxis()->SetRangeUser(0.001,1.);
  TH1F *hRaTvsJetEta_Sig_HT80_MC = createRaTvsJetEta_histo("muAlphaT_QCD30and80andWjets.root","MC","Sig",cutFlow,cutVariable_Sig," && ht>=80.");
  hRaTvsJetEta_Sig_HT80_MC->SetName("hRaTvsJetEta_Sig_HT80_MC");
  cRaTvsJetEta_HT80_MC->cd();
  hRaTvsJetEta_Ctrl_HT80_MC->Draw("P E0");
  hRaTvsJetEta_Sig_HT80_MC->Draw("P E0 sames");
  TLegend *legRaTvsHT_MC=legend1(hRaTvsHT_Ctrl_MC,hRaTvsHT_Sig_MC,"MC (Ctrl)","MC (Sig)");
  TLegend *legHT80=legendHT(80.);
  legRaTvsHT_MC->Draw("SAME");
  legHT80->Draw("SAME");
  
  /*
  TH1F *hRaTvsJetEta_Ctrl_Data = createRaTvsJetEta_histo("muAlphaT_SD_JMT_SKMD.root","Data","Ctrl",cutFlow,cutVariable_Ctrl);
  hRaTvsJetEta_Ctrl_Data->SetName("hRaTvsJetEta_Ctrl_Data");
  hRaTvsJetEta_Ctrl_Data->GetYaxis()->SetRangeUser(0.001,1.);
  TH1F *hRaTvsJetEta_Sig_Data = createRaTvsJetEta_histo("muAlphaT_SD_JMT_SKMD.root","Data","Sig",cutFlow,cutVariable_Sig);
  hRaTvsJetEta_Sig_Data->SetName("hRaTvsJetEta_Sig_Data");
  cRaTvsJetEta_Data->cd();
  hRaTvsJetEta_Ctrl_Data->Draw("P E0");
  hRaTvsJetEta_Sig_Data->Draw("P E0 sames");
  TLegend *legRaTvsHT_Data=legend1(hRaTvsHT_Ctrl_Data,hRaTvsHT_Sig_Data,"Data (Ctrl)","Data (Sig)");
  legRaTvsHT_Data->Draw("SAME");
  */

  //save plots
      
  TString plotsFolder = "muAlphaT_QCD3080andWjets/"; 
  cAlphaT_MC->Print("./Plots/"+plotsFolder+"aT_MC.png");
  cRaTvsHT_MC->Print("./Plots/"+plotsFolder+"RaTvsHT_MC.png");
  cRaTvsJetEta_HT0_MC->Print("./Plots/"+plotsFolder+"RaTvsJetEta_HT0_MC.png");
  cRaTvsJetEta_HT80_MC->Print("./Plots/"+plotsFolder+"RaTvsJetEta_HT80_MC.png");
  
} // ~end of mainFunction


TH1F *create1Dhisto_vsHT(TString filename,TString branch,TString DataOrMC,TString SigOrCtrl,TString cuts,TString pfMet,float tmpHT,int bins, float xmin, float xmax,bool scale2one) {
  
  TFile *f = TFile::Open("muTrees/"+filename,"READONLY");

  TString treeFolder = "muTree/";
  TTree *tree = (TTree*)f->Get(treeFolder+"T");

  cuts+=pfMet;
  TString cut_ht = " && ht >"; cut_ht+=tmpHT;
  cuts+=cut_ht;
  //  TCut cut =+cuts;
  TCut cut ="wgt*("+cuts+")";

  TH1F *hTemp = new TH1F("hTemp","hTemp",bins,xmin,xmax);
  tree->Project("hTemp",branch,cut);

  if (scale2one) { 
    hTemp->Sumw2();
    if ((hTemp->Integral())!=0) { hTemp->Scale(1./(hTemp->Integral())); }
    else { hTemp->Scale(0.); } 
  }

  hTemp->GetXaxis()->SetTitle(branch);
  if (!scale2one) { hTemp->GetYaxis()->SetRangeUser(0.1,2.2*(hTemp->GetBinContent(hTemp->GetMaximumBin()))); }

  if (DataOrMC == "Data") {
    hTemp->SetMarkerStyle(19);
    hTemp->SetMarkerSize(0.7);
    hTemp->SetLineWidth(3);
    //    hTemp->SetLineStyle(1);
  }

  if (DataOrMC == "MC") {
    hTemp->SetMarkerStyle(20);
    hTemp->SetMarkerSize(0.01);
    hTemp->SetLineWidth(3);
    //    hTemp->SetLineStyle(1);
  }

  if (SigOrCtrl == "Sig") {
    hTemp->SetLineColor(1);
    hTemp->SetMarkerColor(1);
  }

  if (SigOrCtrl == "Ctrl") {
    hTemp->SetLineColor(2);
    hTemp->SetMarkerColor(2);
  }


  return hTemp;
} //~ end of create1Dhisto_vsHT



TH1F *createRaTvsHT_histo(TString filename,TString DataOrMC,TString SigOrCtrl,TString cuts,TString pfMet,float minHT,float maxHT,float step) {

  TFile *f = TFile::Open("muTrees/"+filename,"READONLY");

  TString treeFolder = "muTree/";
  TTree *tree = (TTree*)f->Get(treeFolder+"T");

  int bins = (maxHT-minHT)/step;
  TH1F *hRaTvsHT = new TH1F("hRaTvsHT","hRaTvsHT",bins,minHT,maxHT);

  cuts+=pfMet;
  float tmpHT = minHT;
  UInt_t count = 0;

  while (tmpHT <= maxHT) {

    TString cutsb = cuts;
    TString cut_ht = " && ht >="; cut_ht+=tmpHT;
    cutsb+=cut_ht;
    TCut cut ="wgt*("+cutsb+")";

    TH1F *hAlphaT = new TH1F("hAlphaT","hAlphaT",160,-1.,3.);
    tree->Project("hAlphaT","alphaT",cut);

    float RaT = CalculateRaT(hAlphaT);
    float RaTerr = CalculateRaTerr(hAlphaT);

    hRaTvsHT->SetBinContent(count+1,RaT);
    hRaTvsHT->SetBinError(count+1,RaTerr);

    hRaTvsHT->GetXaxis()->SetTitle("HT > [GeV]");
    hRaTvsHT->GetYaxis()->SetTitle("R#alphaT");

    delete hAlphaT;
    tmpHT+=step;
    count++;
  } // ~end of while loop

  if (DataOrMC == "Data") {
    hRaTvsHT->SetMarkerStyle(19);
    hRaTvsHT->SetMarkerSize(0.7);
    hRaTvsHT->SetLineWidth(3);
    //    hRaTvsHT->SetLineStyle(1);
  }

  if (DataOrMC == "MC") {
    hRaTvsHT->SetMarkerStyle(20);
    hRaTvsHT->SetMarkerSize(0.7);
    hRaTvsHT->SetLineWidth(3);
    //    hRaTvsHT->SetLineStyle(1);
  }

  if (SigOrCtrl == "Sig") {
    hRaTvsHT->SetLineColor(1);
    hRaTvsHT->SetMarkerColor(1);
  }

  if (SigOrCtrl == "Ctrl") {
    hRaTvsHT->SetLineColor(2);
    hRaTvsHT->SetMarkerColor(2);
  }

  return hRaTvsHT;
} // ~ end of createRaTvsHT_histo





TH1F *createRaTvsJetEta_histo(TString filename,TString DataOrMC,TString SigOrCtrl,TString cuts,TString pfMet,TString ht) {

  TFile *f = TFile::Open("muTrees/"+filename,"READONLY");

  TString treeFolder = "muTree/";
  TTree *tree = (TTree*)f->Get(treeFolder+"T");

  TH1F *hRaTvsJetEta = new TH1F("hRaTvsJetEta","hRaTvsJetEta",5,0.,5.);

  cuts+=pfMet;
  cuts+=ht;

  float tmpJetEtaMin = 0.;
  float tmpJetEtaMax = 5.;
  float step = 1.;
  UInt_t count = 0;
  while (tmpJetEtaMin <= (tmpJetEtaMax-1.)) {

    TString cutsb = cuts;
    TString cut_jetEtaMin = " && etaJet[0] >="; cut_jetEtaMin+=tmpJetEtaMin;
    TString cut_jetEtaMax = " && etaJet[0] <"; cut_jetEtaMax+=(tmpJetEtaMin+1.);
    cutsb+=cut_jetEtaMin;
    cutsb+=cut_jetEtaMax;
    //    TCut cut =+cutsb;
    TCut cut ="wgt*("+cutsb+")";

    TH1F *hAlphaT = new TH1F("hAlphaT","hAlphaT",160,-1.,3.);
    tree->Project("hAlphaT","alphaT",cut);

    float RaT = CalculateRaT(hAlphaT);
    float RaTerr = CalculateRaTerr(hAlphaT);

    hRaTvsJetEta->SetBinContent(count+1,RaT);
    hRaTvsJetEta->SetBinError(count+1,RaTerr);

    hRaTvsJetEta->GetXaxis()->SetTitle("|#eta| leading Jet");
    hRaTvsJetEta->GetYaxis()->SetTitle("R#alphaT");

    delete hAlphaT;
    tmpJetEtaMin+=step;
    count++;
  } // ~end of while loop


  if (DataOrMC == "Data") {
    hRaTvsJetEta->SetMarkerStyle(19);
    hRaTvsJetEta->SetMarkerSize(0.7);
    hRaTvsJetEta->SetLineWidth(3);
    //    hRaTvsJetEta->SetLineStyle(1);
  }

  if (DataOrMC == "MC") {
    hRaTvsJetEta->SetMarkerStyle(20);
    hRaTvsJetEta->SetMarkerSize(0.7);
    hRaTvsJetEta->SetLineWidth(3);
    //    hRaTvsJetEta->SetLineStyle(1);
  }

  if (SigOrCtrl == "Sig") {
    hRaTvsJetEta->SetLineColor(1);
    hRaTvsJetEta->SetMarkerColor(1);
  }

  if (SigOrCtrl == "Ctrl") {
    hRaTvsJetEta->SetLineColor(2);
    hRaTvsJetEta->SetMarkerColor(2);
  }

  return hRaTvsJetEta;
} // ~ end of createRaTvsJetEta_histo



float CalculateRaT(TH1F *HistoInput) {

  HistoInput->SetName("HistoInput");

  float criticalValue = 0.55;
  int criticalBin = HistoInput->FindBin(criticalValue);
  int numOfBins = HistoInput->GetNbinsX();

  float RaT = 9999.;
  if ((HistoInput->Integral(0,criticalBin-1))!=0) {
    RaT = (HistoInput->Integral(criticalBin,numOfBins+1))/(HistoInput->Integral(0,criticalBin-1));}
  else { RaT = 0.; }

  return RaT;

} // ~end of CalculateRaT function                                                                                                                           


float CalculateRaTerr(TH1F *HistoInput) {

  HistoInput->SetName("HistoInput");

  float criticalValue = 0.55;
  int criticalBin = HistoInput->FindBin(criticalValue);
  int numOfBins = HistoInput->GetNbinsX();

  float num = HistoInput->Integral(criticalBin,numOfBins+1);
  float den = HistoInput->Integral(0,criticalBin-1);
  float RaTerr = 999999.;
  if (den!=0) {
    RaTerr = sqrt( pow((sqrt(num)/(den)),2) + pow(((num*(sqrt(den)))/(den*den)),2) ); }
  else { RaTerr = 0.; }

  return RaTerr;
} // ~end of CalculateRaT function





TCanvas* createCanvas(TString name, bool logOn) {

  TCanvas* aCanvas = new TCanvas(name,name,800,800);

  if (logOn==true) { gPad->SetLogy(); }
  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);

  return aCanvas;
}



TLegend *legend1(TH1F *histo1, TH1F *histo2, TString histoLeg1, TString histoLeg2) {

  TLegend *leg = new TLegend(0.65,0.8,0.92,0.92);
  leg->AddEntry(histo1,histoLeg1,"PL");
  leg->AddEntry(histo2,histoLeg2,"PL");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.045);
  leg->SetTextFont(42);

  return leg;

}


TLegend *legendHT(float tmpHT) {

  TLegend *leg = new TLegend(0.5,0.85,0.82,0.92);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.045);
  leg->SetTextFont(42);
  TString legHeader = "HT >";
  legHeader+=tmpHT;
  leg->SetHeader(legHeader);

  return leg;

}



void extractCutFlowTables() {

  //Define cuts
  TCut cut_nMu = "nMu>=1";
  TCut cut_nEl = "nEl==0";
  TCut cut_ptMu = "et_mu>=10.";
  TCut cut_nJets = "nJet>=1";
  TCut cut_etJet = "etJet[0]>=40";
  TCut cut_relCombIso = "combIso<0.3";
  TCut cut_ht80 = "ht > 80.";
  TCut cut_ht180 = "ht > 180.";
  TCut cut_pfMet = "pfMet >= 0.";

  TString filename = "muAlphaT_QCD30and80andWjets.root";
  TFile *f = TFile::Open("muTrees/"+filename,"READONLY");

  TString treeFolder = "muTree/";
  TTree *tree = (TTree*)f->Get(treeFolder+"T");

  TCut cutFlow = "(wgt)"*(cut_pfMet && cut_nMu && cut_ptMu && cut_relCombIso);
  tree->Draw("nMu >> hNumOfMus",cutFlow);
  float numOfEntries = hNumOfMus->Integral();
  cout << numOfEntries << "\n";
  TCut cutFlow = "(wgt)"*(cut_pfMet && cut_nMu && cut_ptMu && cut_relCombIso && cut_nEl);
  tree->Draw("nMu >> hNumOfMus",cutFlow);
  float numOfEntries = hNumOfMus->Integral();
  cout << numOfEntries << "\n";
  TCut cutFlow = "(wgt)"*(cut_pfMet && cut_nMu && cut_ptMu && cut_relCombIso && cut_nEl && cut_nJets && cut_etJet);
  tree->Draw("nMu >> hNumOfMus",cutFlow);
  float numOfEntries = hNumOfMus->Integral();
  cout << numOfEntries << "\n";
  TCut cutFlow = "(wgt)"*(cut_pfMet && cut_nMu && cut_ptMu && cut_relCombIso && cut_nEl && cut_nJets && cut_etJet && cut_ht80);
  tree->Draw("nMu >> hNumOfMus",cutFlow);
  float numOfEntries = hNumOfMus->Integral();
  cout << numOfEntries << "\n";
  TCut cutFlow = "(wgt)"*(cut_pfMet && cut_nMu && cut_ptMu && cut_relCombIso && cut_nEl && cut_nJets && cut_etJet && cut_ht180);
  tree->Draw("nMu >> hNumOfMus",cutFlow);
  float numOfEntries = hNumOfMus->Integral();
  cout << numOfEntries << "\n";

}



