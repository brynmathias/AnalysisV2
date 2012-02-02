TString plot_dir = "eletree";
TString selec = "Signal_";
//TString plots = "./";
TString plots = "~/Plots/MCD34pb/JanUpdate/";
TString erlee = "early/";
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
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v1 + trig_HT150v3 + trig_HT160v1 + trig_HT160v3) > 0";

TCut e_odd = "ElectronOdd ==0";
TCut nmu = "NMuons == 0";
TCut mu_odd = "MuonOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";

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

//TCut ele1 = ne && e_iso1 && e_noiso2 && e_pt && e_dr &&  e_nodr2%OLD && e_nopt2;
//TCut ele2a = ne2 && e_iso1 && e_noiso2 &&  e_pt && e_dr &&  e_nodr2 && e_nopt2;
//TCut ele2b = ne2 && e_noiso1 && e_iso2 && e_nopt && e_nodr && e_dr2 && e_pt2;
TCut secondEle = "NLElectrons < 2.";
TCut looseMuon = "NLMuons == 0";


//TCut ele =(ele2a) || (ele1) || (ele2b);
TCut ele = ne && e_pt ;
//&& e_pt;
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


TCut numlepData = trig && h250 && hbhe && sel && ele && e_odd && nmu && mu_odd && secondEle && looseMuon ;
TCut numlep = h250 && sel && ele && e_odd && nmu && mu_odd && secondEle && looseMuon ;
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


//&& ElectronOdd == 0 && NElectrons == 0";
// && MuonClosestPreJetDR > 0.3";

 TFile *fLM0 = new TFile("eAlphaT_"+selec+"LM0.root");
TFile *fLM1 = new TFile("eAlphaT_"+selec+"LM1.root");
TFile *fTT = new TFile("eAlphaT_"+selec+"ttbarTauola.root");
TFile *fQCDem = new TFile("eAlphaT_"+selec+"QCDEM.root");
TFile *fQCDbce = new TFile("eAlphaT_"+selec+"QCDBCE.root");
TFile *fQCD170 = new TFile("eAlphaT_"+selec+"QCD_All170.root");
TFile *fW = new TFile("eAlphaT_"+selec+"Wjets_vols.root");
TFile *fZ = new TFile("eAlphaT_"+selec+"ZJets_madgraph.root");
TFile *fData = new TFile("eAlphaT_"+selec+"RA1Data.root");
TTree *tLM0 = (TTree*)fLM0->Get(plot_dir+"/T");
TTree *tLM1 = (TTree*)fLM1->Get(plot_dir+"/T");
TTree *tTT = (TTree*)fTT->Get(plot_dir+"/T");
TTree *tQCDem = (TTree*)fQCDem->Get(plot_dir+"/T");
TTree *tQCDbce = (TTree*)fQCDbce->Get(plot_dir+"/T");
TTree *tQCD170 = (TTree*)fQCD170->Get(plot_dir+"/T");
TTree *tW = (TTree*)fW->Get(plot_dir+"/T");
TTree *tZ = (TTree*)fZ->Get(plot_dir+"/T");
TTree *tData = (TTree*)fData->Get(plot_dir+"/T");

Double_t intlumi = 100.000;
TString luminum = "100.";


TCut earlyaT = HT200 && alphat;

TCut earlyaTData = HT200Data && alphat;
void ele_MCvsD(){
cout << "The Integrated Luminosity your plots are being scaled to is: " << intlumi  << "pb^{-1}" << endl;

// TH1D* a = GetHist("LM0",1,"AlphaT_Lep",trigMC+numpj,"(50,0.,1.)");

 tData->Scan("PFMET:AlphaT_Lep:ElectronPt[0]:HT_Lep",numpjData && "AlphaT_Lep > 0.55");
//makeAll("noHT");
// makeAll//("HT300");
//  Plot("PFMT",aT,"(30,0.,200.)",500,"aT");
//   Plot("ElectronPt[0]","HT200","(15,8.,38.)",1337.);
// makeAll("early");
/*
 Plot("HT","","(20,200.,1500.)",500,"nothing");
 Plot("NElectrons",h250 && sel,"(5,-0.5,4.5.)",500,"tright");
 Plot("ElectronPt[0]",h250 && sel && ne,"(30,8.,68.)",500,"Nele");
/// Plot("NMuons",h250 && sel && ne && e_pt ,"(5,-0.5,4.5)",500,"e pt");
 Plot("NLElectrons",h250 && sel && ne && e_pt && nmu,"(5,-0.5,4.5)",500,"n muons");
 Plot("NLMuons",h250 && sel && ne && e_pt && nmu && secondEle,"(5,-0.5,4.5)",500,"loose ele");
 Plot("NPhotons",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon,"(5,-0.5,4.5)",500,"loose muon");
 Plot("NJet",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho,"(7,-0.5,6.5)",500,"n pho");
 Plot("JetPt[0]",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho && nj,"(20.,0.,400.)",500,"n jet");
 Plot("JetOdd",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho && nj && j1pt,"(2,-0.5,1.5)",500,"j1 pt");
Plot("badMuonJet ==1",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho && nj && j1pt && jodd,"(2,-0.5,1.5)",500,"jodd");
Plot("JetEta[0]",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho && nj && j1pt && jodd && bmu,"(12,-4.8,4.8)",500,"BMU");
Plot("HT_Lep",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2,"(14,200.,1600.)",500,"alljet");
Plot("AlphaT",h250 && sel && ne && e_pt && nmu && secondEle && looseMuon && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && h350,"(20,0.,1.)",500,"HT");
*/
//GasPlot("W+Jets",tW);
////GasPlot("t #bar{t}",tTT);
//GasPlot("LM0",tLM0);
}
void GasPlot(TString set, TTree *t){

  setstyle();

  TH2D* wublu = Get2dMTaT(set , HT350,"(80,0.,200.,60.,0.,1.5)",t);
 wublu->Draw("COLZ");
 wublu->GetYaxis()->SetTitle("AlphaT_Lep");
 wublu->GetXaxis()->SetTitle("PFMT");
 wublu->SetTitle("Electron Channel - "+set);
 if(set == "W+Jets"){
   wublu->Scale(1.29557302);}
 if(set == "Z+Jets"){
   wublu->Scale(3048./2400.);}
 if(set == "t #bar{t}"){
   wublu->Scale(1.65789474);}

 TCanvas *cstar = new TCanvas("MTPFAT_Elecs"+set,"MTPFAT_Elecs"+set,500,400);
 wublu->Draw("COLZ");
 cstar->SaveAs(plots+"MTaT/Elecs_2dmtatplot_"+set+".png");
}
void cplots(TString cutstep){
   Plot("PFMHT",cutstep,"(25,0.,400.)",500);
     Plot("PFMT",cutstep,"(20,0.,200.)",500);
  Plot("PFMT2",cutstep,"(20,-100.,500.)",500.);
     Plot("PFLP",cutstep,"(20,-1.,2.)",500);
        Plot("PFMET",cutstep,"(25,0.,400.)",500.);
	

}

void makeAll(TString cutstep){
  //  Plot("ElectronEta[0]",HT200,"(10,-3.,3.)",500.,cutstep);
      Plot("AlphaT_Lep",HT200,"(30,0.,2.)",1.4,cutstep);
        Plot("ElectronPt[0]",HT200,"(10,8.,28.)",1337.,cutstep);
  Plot("ElectronEta[0]",HT200,"(10,-3.,3.)",500.,cutstep);
  Plot("ElectronPhi[0]",HT200,"(10,-3.14159,3.14159)",500.,cutstep);
  Plot("NJet",HT200,"(10,-0.5,9.5)",500.,cutstep);
  Plot("JetPt[0]",HT200,"(20,0,800)",500.,cutstep);
  Plot("JetEta[0]",HT200,"(10,-3.,3.)",1337.,cutstep);
  Plot("JetPhi[0]",HT200,"(20,-5.,5.)",500.,cutstep);
  Plot("JetPt[1]",HT200,"(20,0.,600.)",500.,cutstep);
  Plot("JetEta[1]",HT200,"(16,-5.,5.)",1337.,cutstep);
  Plot("JetPhi[1]",HT200,"(20,-5.,5.)",500.,cutstep);
  

  Plot("HT",HT200,"(20,200.,1500.)",500.,cutstep);
  Plot("HT_Lep",HT200,"(20,200.,1500.)",500.,cutstep);
  Plot("MHT",HT200,"(20,0.,700.)",500.,cutstep);
  //  Plot("PFMHT",HT200,"(20,0.,300.)",500.,cutstep);
  Plot("RecoilMET",HT200,"(30,0.,500.)",500.,cutstep);
  //  Plot("PFMET",HT200,"(20,0.,300.)",500.,cutstep);
  
  Plot("Meff",HT200,"(15,200.,1600.)",500.,cutstep);


    Plot("PFMHT",HT200,"(25,0.,700.)",500,cutstep);
     Plot("PFMT",HT200,"(20,0.,200.)",500,cutstep);
  Plot("PFMT2",HT200,"(25,-100.,700.)",500.,cutstep);
     Plot("PFLP",HT200,"(20,-1.,2.)",500,cutstep);
        Plot("PFMET",HT200,"(28,0.,450.)",500.,cutstep);
	Plot("JetPt[2]",HT200,"(20,0.,400.)",500,cutstep);  
Plot("JetEta[2]",HT200,"(16,-5.,5.)",1337,cutstep);  

 Plot("ElectronClosestComJetDR[0]",HT200,"(14,0.,4.2)",500,cutstep);
 Plot("ElectronClosestComJetDR[0]",HT200,"(10,0.,1.)",90003,cutstep);
}


void Plot(TString var,TCut cut,TString bins,Double_t xmax, TString cutpoint){
  setstyle(); 
 TH1::SetDefaultSumw2(true);
TCanvas *c2 = new TCanvas("canvas"+var+cutpoint,"canname"+var+cutpoint,800,800);
  TPad *mainPad = new TPad("","",0.01,0.25,0.99,0.99);
   mainPad->SetNumber(1);
   mainPad->Draw();
    TPad *ratioPad = new TPad("","",0.01,0.01,0.99,0.25);
   ratioPad->SetNumber(2);
   ratioPad->Draw();

   c2->cd(1);
   //   if (cutpoint == "noHT"){ TCut cut = numpj; TCut cutData = numpjData;}
   // else if (cutpoint == "HT200"){ TCut cut = HT200;TCut cutData = HT200Data; }
   //  else if (cutpoint == "HT300"){ TCut cut = HT300;TCut cutData = HT300Data;/ }
   // else if (cutpoint == "HT350"){ TCut cut = HT350;TCut cutData = HT350Data; }
   // else if (cutpoint == "aT"){ TCut cut = aT; TCut cutData = aTData;}
   //else if (cutpoint == "early"){TCut cut = earlyaT; TCut cutData = earlyaTData;//}
   // else{cout << "ERRORRRR: BRaaaaaaaaaaaaaaaaaains" << endl; }


  TCut cutData = trig && hbhe && cut;
  TH1D* lm0 = GetHist("LM0",kRed,var,cut,bins,tLM0,cutpoint);
  TH1D* lm1 = GetHist("LM1",kRed,var,cut,bins,tLM1,cutpoint);
  //TH1D* qcd = GetHist("QCD",kRed,var,cut,bins,tQCD,cutpoint);
    TH1D* qcdem = GetHist("QCDEM",kOrange+4,var,cut,bins,tQCDem,cutpoint);
  TH1D* qcdbce = GetHist("QCDBCE",kRed,var,cut,bins,tQCDbce,cutpoint);
TH1D* qcd170 = GetHist("QCD170",kRed,var,cut,bins,tQCD170,cutpoint);
  TH1D* data = GetHist("Data",1,var,cutData,bins,tData,cutpoint);
  TH1D* W = GetHist("Wjets_vols",kBlue,var,cut,bins,tW,cutpoint);
  TH1D* tt = GetHist("ttbarTauola",kGreen,var,cut,bins,tTT,cutpoint);
  TH1D* Z = GetHist("ZJets_madgraph",kYellow,var,cut,bins,tZ,cutpoint);
 // TH1D* SM = GetHist("SM",kGray+2,var,trigMC+cut,binstLM0,cutpoint);
 lm1->SetLineStyle(2);
 W->Scale(1.29557302);
 tt->Scale(1.65789474);
 Z->Scale(3048./2400.);
 //qcdem->Scale(1.5);
 // if(selec == "Signal_"){
 //   qcd170->Scale(3.86);}
 // else if(selec == "Control_"){
 //   qcd170->Scale(3.07);}


  TH1D *qcd = qcdem->Clone();
 qcd->Add(qcdbce);
 qcd->Add(qcd170);
 // qcd->Scale(2.48);
 TH1::SetDefaultSumw2(true);

 TH1D *SM   = (TH1D*)qcd->Clone();
 SM->Add(Z);
 SM->Add(tt);
 SM->Add(W);
 //SM->SetLineColor(kGray+2);
// SM->SetFillStyle(3002);
 // SM->SetFillColor(kGray+2);
 // SM->SetMarkerSize(0.);


 c2->cd(1)->SetLogy();
 //  data->Draw("PE0");
 SM->Draw("E");
   THStack bkg("bkg","test stacked histograms");
   bkg.Add(Z);
   bkg.Add(tt);
   bkg.Add(W);
   bkg.Add(qcd);
   TH1D *error = qcd->Clone();
   error->Add(Z);
   error->Add(tt);
   error->Add(W);
   error->Draw("ESAME");

   bkg.Draw("HIST0SAME");
   // data->Draw("PE0SAME");
   /*
   // SM->Draw("HIST0same");
   //qcd->Draw("HIST0same");
     
      W->Draw("HIST0same");
         Z->Draw("HIST0same");
       tt->Draw("HIST0same");
   */
    lm0->Draw("HIST0same"); lm0->SetLineColor(1); lm0->SetFillColor(0);
    lm1->Draw("HIST0same"); lm1->SetLineColor(1); lm1->SetFillColor(0); lm1->SetLineStyle(2);
	//  data->Draw("EPSAME");  
    if(xmax == 1337){
      double ymax=SM->GetMaximum()*14.6;}

    else{
      double ymax=SM->GetMaximum()*12.6;}
	SM->GetYaxis()->SetRangeUser(0.05,ymax);
	if (var=="AlphaT_Lep") { data->GetXaxis()->SetRangeUser(0.,xmax);}
	SM->GetXaxis()->SetTitle(var);
	SM->SetTitle();
  TLegend *leg = new TLegend(0.73803,0.591026,0.88137,0.880819);
  // leg->SetShadowColor(0);
  //leg->SetBorderSize(0);
  //leg->SetFillStyle(4100);
  leg->SetTextSize(0.04);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  
  // leg->AddEntry(data,"DATA","PL");
   leg->AddEntry(qcd,"QCD","FL");
  leg->AddEntry(W,"W","FL");
  leg->AddEntry(Z,"Z","FL");
  leg->AddEntry(tt,"TTbar","FL");
  leg->AddEntry(lm0,"LM0","FL");
  leg->AddEntry(lm1,"LM1","FL");
  
  //leg->AddEntry(SM,"SM BKGD","FL");
  leg->Draw("same");
  
   TLatex  *prelim = new TLatex(0.1152,0.81981,"CMS preliminary 2010");



  TLatex *lumi = new TLatex(0.1015,.9403,"#scale[0.8]{#int L dt = " +luminum+ "pb^{-1}, #sqrt{s} = 7 TeV}");
    prelim->SetNDC();
    lumi->SetNDC();
    //   prelim->Draw("same");
   lumi->Draw("same");

   TH1D *RatioBottom = (TH1D*)SM->Clone("Ratiob");
   TH1D *RatioTop = (TH1D*)data->Clone("Ratiot");
   RatioTop->GetYaxis()->SetTitle("data / sim");
 RatioTop->GetXaxis()->SetTitle();
      RatioTop->Divide(RatioBottom);

      c2->cd(2);
      gPad->SetGridx(); gPad->SetGridy();
   RatioTop->SetTitleSize(0.1, "XYZ");
    RatioTop->SetTitleOffset(0.55, "X");
    RatioTop->SetTitleOffset(0.3, "Y");
    RatioTop->SetLabelSize(0.11, "XY");
    RatioTop->GetYaxis()->SetRangeUser(-2.,4.0);
    RatioTop->Draw();
    //RatioTop->GetYaxis()->SetLabelSize(0.1);
    TBox *unity = new TBox(RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetFirst()), 0.89,RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetLast()), 1.11);
    unity->SetLineWidth(2);
unity->SetLineColor(2);
    unity->SetFillColor(2);
    unity->SetFillStyle(3002);
    unity->Draw();

    c2->Update();
    if(cutpoint == "early"){
      c2->SaveAs(plots+erlee+"Elec_ND"+selec+var+"_"+cutpoint+".png");
    }
    else if (xmax == 90003){
      c2->SaveAs(plots+"Elec_ND"+selec+"_zooomed_"+var+"_"+cutpoint+".png");}
    else{
      c2->SaveAs(plots+"Elec_ND"+selec+var+"_"+cutpoint+".png");}
     c2->Close();
  }
TH2D* Get2dMTaT(TString dataset, TCut flow, TString bin,TTree *t){
 TCanvas *c1 = new TCanvas("canneMT"+dataset,"canneMT"+dataset,400,400);
 //cout << var << "  " << dataset << endl;
 t->Draw("AlphaT_Lep:PFMT>>hist"+bin,"(wgt)"*flow);
  TH2D *HIST= (TH2D*)gDirectory->Get("hist");
  HIST->SetName(dataset+"MTaT");
  c1->Close();
  HIST->Scale(intlumi/10.);
 return HIST;

}
TH1D* GetHist(TString dataset, Color_t col, TString var, TCut flow,TString bin,TTree *t, TString poin){
 
   
     
 TCanvas *c1 = new TCanvas("canny"+var,"canne"+var,400,400);
  t->Draw(var+">>hist"+bin,"(wgt)"*flow);
  TH1D *HIST= (TH1D*)gDirectory->Get("hist");
  HIST->SetName(dataset+var+poin);
  c1->Close();

 
  if(dataset == "SM"){
 HIST->SetLineColor(col);
 HIST->SetFillStyle(3002);
 HIST->SetFillColor(col);
 HIST->SetMarkerSize(0.);
  }
  else if (dataset == "Data"){
    HIST->SetMarkerStyle(20);
 HIST->SetMarkerSize(1.1);
HIST->SetMarkerColor(col);
 
  }
  else{
  HIST->SetLineWidth(3);
  HIST->SetFillColor(col);
  HIST->SetLineColor(col);
  HIST->SetMarkerSize(0.);
  HIST->SetFillStyle(3002);
  }


  if (dataset != "Data"){
    HIST->Scale(intlumi/10.);
    /* if (dataset == "Wjets_vols") { */
    /*   HIST->Scale((31314./24170.)); */
    /* } else if (dataset == "ttbarTauola") { */
    /*   HIST->Scale(157.7/95.); */
    /* } */
    
  }
  return HIST;
}

void setstyle(){
   gROOT->SetBatch(kTRUE);
 gStyle->SetPalette(1);
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
