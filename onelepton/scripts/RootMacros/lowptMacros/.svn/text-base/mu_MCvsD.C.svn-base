TString plot_dir = "mutree_iso";


TString plots = "~/Plots/MCD34pb/JanUpdate/";
TString erlee = "early/";
//TCut trig = "trig_Jet50 ==1";
TCut triga = "trig_HT100 == 1 ";
TCut trigb = "trig_HT120 == 1";

TCut trigc = "trig_HT140 == 1";
//TCut trig = triga || trigb || trig
TCut mu_odd = "MuonOdd ==0";
TCut ne = "NElectrons == 0";
TCut e_odd = "ElectronOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";

Double_t d_aT = 0.55;
TString s_aT = "0.55";
UInt_t lobinat = 55;
UInt_t hibinat = 56;

TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v1 + trig_HT150v3 + trig_HT160v1 + trig_HT160v3) > 0";

TCut trigData =trig && hbhe;
TCut nmu = "NMuons ==1";
TCut mu_iso1 = "MuonRelCombIso[0]<0.1";
TCut amu_iso1 = "MuonRelCombIso[0]<0.3";
TCut amu_iso2 = "MuonRelCombIso[1]<0.3";


TCut mu_barrel1 = "MuonEta[0] < 1.4442";
TCut mu_barrel2 = "MuonEta[0] > -1.4442";
TCut mu_barrel = mu_barrel1 && mu_barrel2;

TCut mu_ec1 = "MuonEta[0] > 1.560";
TCut mu_ec2 = "MuonEta[0] < -1.560";
TCut mu_ec = mu_ec1 || mu_ec2;
TCut mu_pt = "MuonPt[0] > 10. && MuonPt[0] <25.";


TCut mu_pt_hi = "MuonPt[0]>10.";
TCut mu_pt_lo = "MuonPt[0]<=10.";


TCut mu_dr = "MuonClosestComJetDR[0] > 0.3";

TCut mu_pt_r1 = "MuonPt[0]<10.";
TCut mu_pt_r2 = "MuonPt[0]>10. && MuonPt[0]<20.";
TCut mu_pt_r3 = "MuonPt[0]>20. && MuonPt[0]<30.";


TCut nmu2 = "NMuons ==2";
TCut mu_noiso2 = "MuonRelCombIso[1]>0.1";
TCut amu_noiso2 = "MuonRelCombIso[1]>0.3";
TCut amu_noiso1 = "MuonRelCombIso[0]>0.3";
TCut mu_noiso1 = "MuonRelCombIso[0]>0.1"; 
TCut mu_iso2 = "MuonRelCombIso[1]<0.1"; 
TCut mu_pt2 = "MuonPt[1]<25.";
TCut mu_dr2 = "MuonClosestComJetDR[1] > 0.3";
TCut mu_nodr2 = "MuonClosestComJetDR[1] > 0";
TCut mu_nopt2 = "MuonPt[1]<100000.";
TCut mu_nodr = "MuonClosestComJetDR[0] > 0";
TCut mu_nopt = "MuonPt[0]<100000.";

TCut muon1 = nmu && mu_iso1 && mu_noiso2 && mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;
TCut muon2a = nmu2 && mu_iso1 && mu_noiso2 &&  mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;
TCut muon2b = nmu2 && mu_noiso1 && mu_iso2 && mu_nopt && mu_nodr && mu_dr2 && mu_pt2;

TCut amuon1 = nmu && amu_iso1 && mu_noiso1 && mu_noiso2 && amu_noiso2 && mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;
TCut amuon2a = nmu2 && amu_iso1 && mu_noiso2 &&  mu_noiso2 && amu_noiso2 &&  mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;
TCut amuon2b = nmu2 && mu_noiso1 && amu_noiso1 && amu_iso2 && amu_noiso2 && mu_nopt && mu_nodr && mu_dr2 && mu_pt2;
TCut amuon =(amuon2a) || (amuon1) || (amuon2b);
//TCut muon =(muon2a) || (muon1) || (muon2b);




TCut muon = nmu && mu_pt;
TString selec = "Signal_";
TString ptsec = "";


TCut secondMuon = "NLMuons < 2.";
TCut looseEle = "NLElectrons == 0";

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

//TCut numlep = trig && sel && h_j_pt && muon1 && mu_odd;
TCut h250 = "HT > 250.";

TCut numlepData = trig && h250 && hbhe && sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
 TCut numlep = h250 && sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;

TCut anumlepData = trigData && sel && amuon && mu_odd && ne && e_odd;
TCut anumlep = trig && sel && amuon && mu_odd && ne && e_odd;



TCut numpj = numlep && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjData = numlepData && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;

TCut anumpj = anumlep && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut anumpjData = anumlepData && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;

TCut HT200 = numpj && h200;
TCut HT300 = numpj && h300;
TCut HT350 = numpj && h350;
TCut aT = HT350 && alphat;

TCut earlyaT = HT200 && alphat;


TCut HT200Data = numpjData && h200;
TCut HT300Data = numpjData && h300;
TCut HT350Data = numpjData && h350;
TCut aTData = HT350Data && alphat;

TCut earlyaTData = HT200Data && alphat;

TCut aHT200 = anumpj && h200;
TCut aHT300 = anumpj && h300;
TCut aHT350 = anumpj && h350;
TCut aaT = aHT350 && alphat;


TCut aHT200Data = anumpjData && h200;
TCut aHT300Data = anumpjData && h300;
TCut aHT350Data = anumpjData && h350;
TCut aaTData = aHT350Data && alphat;


//&& ElectronOdd == 0 && NElectrons == 0";
// && MuonClosestPreJetDR > 0.3";

 TFile *fLM0 = new TFile("muAlphaT_"+selec+"LM0.root");
TFile *fLM1 = new TFile("muAlphaT_"+selec+"LM1.root");
TFile *fTT = new TFile("muAlphaT_"+selec+"ttbarTauola.root");
TFile *fQCD = new TFile("muAlphaT_"+selec+"QCD_Mu.root");
TFile *fW = new TFile("muAlphaT_"+selec+"Wjets_vols.root");
TFile *fZ = new TFile("muAlphaT_"+selec+"ZJets_madgraph.root");
TFile *fData = new TFile("muAlphaT_"+selec+"RA1Data.root");
TTree *tLM0 = (TTree*)fLM0->Get(plot_dir+"/T");
TTree *tLM1 = (TTree*)fLM1->Get(plot_dir+"/T");
TTree *tTT = (TTree*)fTT->Get(plot_dir+"/T");
TTree *tQCD = (TTree*)fQCD->Get(plot_dir+"/T");
TTree *tW = (TTree*)fW->Get(plot_dir+"/T");
TTree *tZ = (TTree*)fZ->Get(plot_dir+"/T");
TTree *tData = (TTree*)fData->Get(plot_dir+"/T");

Double_t intlumi = 100.;
TString luminum = "100.";



void mu_MCvsD(){
cout << "The Integrated Luminosity your plots are being scaled to is: " << intlumi  << "pb^{-1}" << endl;
tData->Scan("PFMET:AlphaT_Lep:MuonPt[0]:HT_Lep",numpjData && "AlphaT_Lep > 0.55");
// TH1D* a = GetHist("LM0",1,"AlphaT_Lep",trigMC+numpj,"(50,0.,1.)");
//makeAll("HT200");
/*
 Plot("HT","","(20,200.,1500.)",500,"nothing");
 Plot("NMuons",h250 && sel,"(5,-0.5,4.5.)",500,"tright");
 Plot("MuonPt[0]",h250 && sel && nmu,"(30,4.,64.)",500,"Nmu");
 Plot("NElectrons",h250 && sel && nmu && mu_pt ,"(5,-0.5,4.5)",500,"mu pt");
 Plot("NLMuons",h250 && sel && nmu && mu_pt && ne,"(5,-0.5,4.5)",500,"n ele");
 Plot("NLElectrons",h250 && sel && nmu && mu_pt && nmu && secondMuon,"(5,-0.5,4.5)",500,"loose mu");
 Plot("NPhotons",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle,"(5,-0.5,4.5)",500,"loose ele");
 Plot("NJet",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho,"(7,-0.5,6.5)",500,"n pho");
 Plot("JetPt[0]",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho && nj,"(20.,0.,400.)",500,"n jet");
 Plot("JetOdd",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho && nj && j1pt,"(2,-0.5,1.5)",500,"j1 pt");
Plot("badMuonJet ==1",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho && nj && j1pt && jodd,"(2,-0.5,1.5)",500,"jodd");
Plot("JetEta[0]",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho && nj && j1pt && jodd && bmu,"(12,-4.8,4.8)",500,"BMU");
Plot("HT_Lep",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2,"(14,200.,1600.)",500,"alljet");
Plot("AlphaT",h250 && sel && nmu && mu_pt && ne && secondMuon && looseEle && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2 && h350,"(20,0.,1.)",500,"HT");*/
// makeAll("early");
//Plot("MuonPt[0]","HT200","(24,0.,30.)",1337.);
// makeAll("noHT");
// makeAll("HT350");
// makeAll("anoHT");
//makeAll("aHT200");


// Plot("PFMT",aT,"(30,0.,200.)",500,"aT")// cplots("early");
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
 wublu->SetTitle("Muon Channel - "+set);
 if(set == "W+Jets"){
   wublu->Scale(1.29557302);}
 if(set == "Z+Jets"){
   wublu->Scale(3048./2400.);}
 if(set == "t #bar{t}"){
   wublu->Scale(1.65789474);}

 TCanvas *cstar = new TCanvas("MTPFAT_Muons"+set,"MTPFAT_Muons"+set,500,400);
 wublu->Draw("COLZ");
 cstar->SaveAs(plots+"MTaT/Muons_2dmtatplot_"+set+".png");
}



void cplots(TString cutstep){
  Plot("PFMHT",cutstep,"(25,0.,400.)",500,cutstep);
  Plot("PFMT",cutstep,"(20,0.,200.)",500,cutstep);
  Plot("PFMT2",cutstep,"(20,0.,300.)",500.,cutstep);
  Plot("PFLP",cutstep,"(20,-1.,2.)",500,cutstep);
   Plot("PFMET",cutstep,"(25,0.,400.)",500.,cutstep);

}



void makeAll(TString cutstep){
  
    Plot("AlphaT_Lep",HT200,"(30,0.,2.)",1.4,cutstep);
          Plot("MuonPt[0]",HT200,"(10,0.,30.)",1337.,cutstep);
  Plot("MuonEta[0]",HT200,"(10,-3.,3.)",500.,cutstep);
  Plot("MuonPhi[0]",HT200,"(10,-3.14159,3.14159)",500.,cutstep);
  Plot("NJet",HT200,"(10,-0.5,9.5)",500.,cutstep);
  Plot("JetPt[0]",HT200,"(20,0,800)",500.,cutstep);
  Plot("JetEta[0]",HT200,"(10,-3.,3.)",1337.,cutstep);
  Plot("JetPhi[0]",HT200,"(10,-3.14159,3.14159)",500.,cutstep);
  Plot("JetPt[1]",HT200,"(20,0.,600.)",500.,cutstep);
  Plot("JetEta[1]",HT200,"(16,-5.,5.)",1337.,cutstep);
  Plot("JetPhi[1]",HT200,"(10,-3.14159,3.14159)",500.,cutstep);
  
  
  Plot("HT",HT200,"(10,0.,1000.)",500.,cutstep);
  Plot("HT_Lep",HT200,"(10,200.,1200.)",500.,cutstep);
  Plot("MHT",HT200,"(20,0.,500.)",500.,cutstep);
//  Plot("PFMHT",HT200,"(20,0.,300.)",500.,cutstep);
  Plot("RecoilMET",HT200,"(20,0.,300.)",500.,cutstep);
  //  Plot("PFMET",HT200,"(20,0.,300.)",500.,cutstep); 
  
  Plot("Meff",HT200,"(10,200.,1200.)",500.,cutstep);
  
  Plot("PFMHT",HT200,"(25,0.,400.)",500,cutstep);
     Plot("PFMT",HT200,"(20,0.,200.)",500,cutstep);
  Plot("PFMT2",HT200,"(20,-100.,500.)",500.,cutstep);
     Plot("PFLP",HT200,"(20,-1.,2.)",500,cutstep);
        Plot("PFMET",HT200,"(25,0.,400.)",500.,cutstep);
	Plot("JetPt[2]",HT200,"(20,0.,400.)",500,cutstep);  
Plot("JetEta[2]",HT200,"(16,-5.,5.)",1337,cutstep);  

Plot("MuonClosestComJetDR[0]",HT200,"(14,0.,4.2)",500,cutstep);
Plot("MuonClosestComJetDR[0]",HT200,"(10,0.,1.)",90003,cutstep);
}


void Plot(TString var,TCut cut,TString bins,Double_t xmax,TString cutpoint){
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
//  else if (cutpoint == "HT200"){ TCut cut = HT200; TCut cutData = HT200Data; }//
//  else if (cutpoint == "anoHT"){ TCut cut = anumpj; TCut cutData = anumpjData;}
//  else if (cutpoint == "aHT200"){ TCut cut = aHT200; TCut cutData = aHT200Data; }
// else if (cutpoint == "HT300"){ TCut cut = HT300;  TCut cutData = HT300Data;}
// else if (cutpoint == "HT350"){ TCut cut = HT350; TCut cutData = HT350Data; }
//  else if (cutpoint == "aT"){ TCut cut = aT;  TCut cutData = aTData;}
//  else if (cutpoint == "early"){TCut cut = earlyaT; TCut cutData = earlyaTData;}

//else{cout << "ERRORRRR: BRaaaaaaaaaaaaaaaaaains" << endl; }
  TCut cutData = trig && hbhe && cut;
  TH1D* lm0 = GetHist("LM0",kRed,var,cut,bins,tLM0,cutpoint);
  ///  cout << "lm0" << endl;
  TH1D* lm1 = GetHist("LM1",kRed,var,cut,bins,tLM1,cutpoint);
  //  cout << "lm1" << endl;
  TH1D* qcd = GetHist("QCD_AllPtBins_7TeV_Pythia",kOrange+4,var,cut && mu_pt_hi,bins,tQCD,cutpoint);
  // cout << "qcd" << endl;
  TH1D* data = GetHist("Data",1,var,cutData,bins,tData,cutpoint);
  // cout << "data" << endl;
  TH1D* W = GetHist("Wjets_vols",kBlue,var,cut,bins,tW,cutpoint);
  //cout << "W" << endl;
  TH1D* tt = GetHist("ttbarTauola",kGreen,var,cut,bins,tTT,cutpoint);
  // cout << "tt" << endl;
  TH1D* Z = GetHist("ZJets_madgraph",kYellow,var,cut,bins,tZ,cutpoint);
  // cout << "Z" << endl;


  //TH1D* qcd_lo = GetHist("QCD_AllPtBins_7TeV_Pythia",kOrange+4,var,cut && mu_pt_lo,bins,tQCD,cutpoint);
 

  //   qcd_lo->Scale(1.94);
  // qcd->Add(qcd_lo);
 // TH1D* SM = GetHist("SM",kGray+2,var,cut,binstLM0,cutpoint);
 lm1->SetLineStyle(2);
 W->Scale(1.29557302);
 tt->Scale(1.65789474);
 Z->Scale(3048./2400.);

 TH1::SetDefaultSumw2(true);

 TH1D *SM   = (TH1D*)qcd->Clone();
 SM->Add(Z);
 SM->Add(tt);
 SM->Add(W);
 //SM->SetLineColor(kGray+2);
 // SM->SetFillStyle(3001);
 // SM->SetFillColor(kGray+2);
 // SM->SetMarkerSize(0.);
 //for(int bnum = 1; bnum <9; bnum++){
 //  if(data->GetBinContent(bnum)>0){
 // cout << "Bin Number " << bnum << " has qcd " << qcd->GetBinContent(bnum) << " and data " << data->GetBinContent(bnum) <<  " and SM " << SM->GetBinContent(bnum) <<  " and scale factor to QCD " << data->GetBinContent(bnum)/qcd->GetBinContent(bnum) << " and scale factor to SM " << data->GetBinContent(bnum)/SM->GetBinContent(bnum) << endl; 
 // }
 //  }
 c2->cd(1)->SetLogy();
 //  data->Draw("PE0");
 SM->Draw("E");
   THStack bkg("bkg","test stacked histograms");
   bkg.Add(Z);
   bkg.Add(tt);
   bkg.Add(W);
   bkg.Add(qcd);

   bkg.Draw("HIST0SAME");
   //  data->Draw("PE0SAME");
   
   
   //qcd->Draw("HIST0same");
   /*  
      W->Draw("HIST0same");
         Z->Draw("HIST0same");
       tt->Draw("HIST0same");
   */
    lm0->Draw("HIST0same"); lm0->SetLineColor(1); lm0->SetFillColor(0);
    lm1->Draw("HIST0same"); lm1->SetLineColor(1); lm1->SetFillColor(0); lm1->SetLineStyle(2);
	//  data->Draw("EPSAME");  
  if(xmax == 1337){
      double ymax=SM->GetMaximum()*12.6;}
  else{
    double ymax=SM->GetMaximum()*10.6;}
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
    RatioTop->SetLabelSize(0.06,"XY");
    RatioTop->GetYaxis()->SetRangeUser(-2.,4.0);
    RatioTop->Draw();
    RatioTop->GetYaxis()->SetLabelSize(0.05);
    TBox *unity = new TBox(RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetFirst()), 0.89,RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetLast()), 1.11);
    unity->SetLineWidth(2);
unity->SetLineColor(2);
    unity->SetFillColor(2);
    unity->SetFillStyle(3002);
    unity->Draw();

    c2->Update();
    if(cutpoint == "early"){
      c2->SaveAs(plots+erlee+"Muon_ND"+selec+var+"_"+cutpoint+".png");
    }
    else if (xmax == 90003){
      c2->SaveAs(plots+"Muon_ND"+selec+"_zooomed_"+var+"_"+cutpoint+".png");}
    else{
      c2->SaveAs(plots+"Muon_ND"+ptsec++selec+var+"_"+cutpoint+".png");}



 
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
 
   
     
 TCanvas *c1 = new TCanvas("canny"+var+dataset,"canne"+var+dataset,400,400);
 //cout << var << "  " << dataset << endl;
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
  //gROOT->SetBatch(kTRUE);
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
