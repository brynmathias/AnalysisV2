TString plot_dir = "mutree_iso";


TString plots = "~/Plots/MCD34pb/JanUpdate/";
//TCut trig = "trig_Jet50 ==1";
TCut h_j_pt = "(High_Jet_Pt > 70.)";
TCut mu_odd = "MuonOdd ==0";
TCut ne = "NElectrons == 0";
TCut e_odd = "ElectronOdd ==0";
TCut sel = "selection == 1";
TCut hbhe = "HBHENoise == 1";
TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140 + trig_HT150v3) > 0";
TCut trigData =trig && hbhe;


//TCut trig = "(trig_HT100 + trig_HT120 + trig_HT140) > 0";
TCut nmu = "NMuons ==1";
TCut mu_iso1 = "MuonRelCombIso[0]<0.1";
TCut mu_pt = "MuonPt[0] > 10. && MuonPt[0] < 25.";
TCut mu_dr = "MuonClosestComJetDR[0] > 0.3";
TCut amu_iso1 = "MuonRelCombIso[0]<0.3";
TCut amu_iso2 = "MuonRelCombIso[1]<0.3";
TCut amu_noiso2 = "MuonRelCombIso[1]>0.3";
TCut amu_noiso1 = "MuonRelCombIso[0]>0.3";
TCut nmu2 = "NMuons ==2";
TCut mu_noiso2 = "MuonRelCombIso[1]>0.1";
TCut mu_noiso1 = "MuonRelCombIso[0]>0.1"; 
TCut mu_iso2 = "MuonRelCombIso[1]<0.1"; 
TCut mu_pt2 = "MuonPt[0]<25.";
TCut mu_dr2 = "MuonClosestComJetDR[1] > 0.3";
TCut mu_nodr2 = "MuonClosestComJetDR[1] > 0";
TCut mu_nopt2 = "MuonPt[1]<100000.";
TCut mu_nodr = "MuonClosestComJetDR[0] > 0";
TCut mu_nopt = "MuonPt[0]<100000.";


TCut mu_pt_hi = "MuonPt[0]>10.";
TCut mu_pt_lo = "MuonPt[0]<=10.";


TCut muon1 = nmu && mu_iso1 && mu_noiso2 && mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;
TCut muon2a = nmu2 && mu_iso1 && mu_noiso2 &&  mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;
TCut muon2b = nmu2 && mu_noiso1 && mu_iso2 && mu_nopt && mu_nodr && mu_dr2 && mu_pt2;

TCut amuon1 = nmu && amu_iso1 && mu_noiso2 && mu_pt && mu_dr &&  mu_nodr2 && mu_nopt2;





//TCut muon =(muon2a) || (muon1) || (muon2b);
TCut muon = nmu && mu_pt;
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

TCut h200 = "HT_Lep > 200.";
TCut h300 = "HT_Lep > 300.";
TCut h350 = "HT_Lep > 350.";
TCut alphat = "AlphaT_Lep > 0.55";
TCut h250 = "HT > 300.";
TCut secondMuon = "NLMuons < 2";
TCut looseEle = "NLElectrons == 0";
TCut preData = trig && h250;
//TCut numlep = trig && sel && h_j_pt && muon1 && mu_odd;
TCut numlepData =  preData && sel && hbhe && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numlep =  h250 && sel && muon && mu_odd && ne && e_odd && secondMuon && looseEle;
TCut numlepA = sel && amuon1 && mu_odd && ne && e_odd;
TCut numpj = numlep && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjData = numlepData && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;
TCut numpjA = numlepA && npho && nj && j1pt && jodd && bmu && jeta1 && jeta2;

TCut HT200 = numpj && h200;
TCut HT300 = numpj && h300;
TCut HT350 = numpj && h350;
TCut aT = HT350 && alphat;

TCut HT200A = numpjA && h200;
TCut HT300A = numpjA && h300;
TCut HT350A = numpjA && h350;
TCut aTA= HT350A && alphat;

TCut HT200Data = numpjData && h200;
TCut HT300Data = numpjData && h300;
TCut HT350Data = numpjData && h350;
TCut aTData = HT350Data && alphat;

TFile *sfQCD = new TFile("muAlphaT_Signal_QCD_Mu.root");
TFile *asfQCD = new TFile("muAlphaT_Control_QCD_Mu.root");

TTree *stQCD = (TTree*)sfQCD->Get(plot_dir+"/T");
TTree *astQCD = (TTree*)asfQCD->Get(plot_dir+"/T");

TFile *sfData = new TFile("muAlphaT_Signal_Data_34.root");
TTree *stData = (TTree*)sfData->Get(plot_dir+"/T");

TFile *asfData = new TFile("muAlphaT_Control_Data_34.root");
TTree *astData = (TTree*)asfData->Get(plot_dir+"/T");
Double_t intlumi = 3.47;
TString luminum = "3.47";



void mu_SAS(){
   Plotting(numpj,numpjData, "noHT");
  //   Plotting(HT200,HT200Data,"HT200");
  //  Plotting(HT300,HT300A,"HT300");
    Plotting(HT350,HT350Data,"HT350");
  //  
 
}
void Plotting(TCut cuts, TCut cutsA, TString poins){

 control("AlphaT_Lep","(20,0.3,0.7)",cuts,cutsA,poins,true,9000);
 /* control("MuonPt[0]","(15,3.,33)",cuts,cutsA,poins,true,9000);
  control("MuonEta[0]","(18,-3.6,3.6)",cuts,cutsA,poins,true,9000);
  control("MuonPhi[0]","(20,-5.,5.)",cuts,cutsA,poins,true,9000);
  control("NJet","(10,-0.5,9.5)",cuts,cutsA,poins,true,9000);
  control("JetPt[0]","(30,50,1000)",cuts,cutsA,poins,true,9000);
 control("JetEta[0]","(22,-3.3,3.3)",cuts,cutsA,poins,true,9000);
 control("JetPhi[0]","(20,-4.,4.)",cuts,cutsA,poins,true,9000);
  control("JetPt[1]","(20,50,350)",cuts,cutsA,poins,true,9000);
 control("JetEta[1]","(22,-3.3,3.3)",cuts,cutsA,poins,true,9000);
 control("JetPhi[1]","(20,-4.,4.)",cuts,cutsA,poins,true,9000);
  control("HT","(20,100.,700.)",cuts,cutsA,poins,true,9000);
 control("HT_Lep","(30,100.,550.)",cuts,cutsA,poins,true,9000);
 control("MHT","(20,0.,250.)",cuts,cutsA,poins,true,9000);

  control("PFMHT","(20,0.,250.)",cuts,cutsA,poins,true,9000);
 control("RecoilMET","(20,0.,300.)",cuts,cutsA,poins,true,9000);
 control("PFMET","(20,0.,200.)",cuts,cutsA,poins,true,9000);

 control("Meff","(30,100.,850.)",cuts,cutsA,poins,true,9000);*/
 
}

void control(TString var,TString bin, TCut cuts, TCut cutsA, TString cutpoint,bool log,Double_t ymax){
setstyle();
 TH1::SetDefaultSumw2(true);
TCanvas *c2 = new TCanvas("canvas"+var+cutpoint,"canname"+var+cutpoint,700,800);

  TPad *mainPad = new TPad("","",0.01,0.25,0.99,0.99);
   mainPad->SetNumber(1);
   mainPad->Draw();
    TPad *ratioPad = new TPad("","",0.01,0.01,0.99,0.25);
   ratioPad->SetNumber(2);
   ratioPad->Draw();
 c2->cd(1);

 TCut lo = cuts && mu_pt_lo;
 TCut hi = cuts && mu_pt_hi;

 // TH1D *Ctrl_lo = GetHist("AS",kBlack,var,lo,bin,astQCD,cutpoint);
 // TH1D *Sig_lo = GetHist("S",kRed,var,lo,bin,stQCD,cutpoint);
  TH1D *Ctrl_hi = GetHist("AS",kBlack,var,cuts,bin,astQCD,cutpoint);
  TH1D *Sig_hi = GetHist("S",kRed,var,cuts,bin,stQCD,cutpoint);
  //  Ctrl_lo->Scale(1.94);
  //  Sig_lo->Scale(1.94);
  TH1D *Ctrl = Ctrl_hi->Clone();
  TH1D *Sig = Sig_hi->Clone();
  //  Ctrl->Add(Ctrl_hi);
  // Sig->Add(Sig_hi);

  Sig->Scale(intlumi);
  // TH1D *Ctrl = GetHist("AS",kBlack,var,cuts,bin,astQCD,cutpoint);
  if(Ctrl->Integral()!=0){
  Ctrl->Scale(Sig->Integral()/Ctrl->Integral());
  }
  
  if(log){ c2->cd(1)->SetLogy();}
  
 TLegend *leg = new TLegend(0.564,0.719,0.775,0.875);
 leg->SetTextSize(0.054);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  //  leg->AddEntry(Ctrl,"Anti-Selected","LF");
  leg->AddEntry(Sig,"Selected","LF");
    leg->AddEntry(Ctrl,"Anti-Selected","LF");

  Ctrl->Draw("EHIST9");
  Sig->Draw("E9same");

  Sig->SetMarkerStyle(20); Sig->SetMarkerColor(kRed);
  leg->Draw("same");
  Ctrl->SetTitle();
  Ctrl->GetXaxis()->SetTitle(var);
  if(log){
  Ctrl->GetYaxis()->SetRangeUser(0.001,ymax);
  }
  else{
    ymax=(Ctrl->GetMaximum()*1.6);
     Ctrl->GetYaxis()->SetRangeUser(0.,ymax);
  }
   TH1D *RatioBottom = (TH1D*)Ctrl->Clone("Ratiob");
   TH1D *RatioTop = (TH1D*)Sig->Clone("Ratiot");

  RatioTop->GetYaxis()->SetTitle("Selected / Anti-Selected");
 RatioTop->GetXaxis()->SetTitle();
 RatioTop->SetTitle();
      RatioTop->Divide(RatioBottom);

      c2->cd(2);
  gPad->SetGridx(); gPad->SetGridy();
   RatioTop->SetTitleSize(0.1, "XYZ");
    RatioTop->SetTitleOffset(0.55, "X");
    RatioTop->SetTitleOffset(0.3, "Y");
    RatioTop->SetLabelSize(0.06,"XY");
    RatioTop->GetYaxis()->SetRangeUser(-2.,5.0);
    RatioTop->SetLineColor(kBlack);
    RatioTop->Draw();
  TBox *unity = new TBox(RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetFirst()), 0.79,RatioTop->GetXaxis()->GetBinLowEdge(RatioTop->GetXaxis()->GetLast()), 1.21);
			   unity->SetLineWidth(2);
unity->SetLineColor(2);
    unity->SetFillColor(2);
			   unity->SetFillStyle(3002);
			   unity->Draw();
  c2->Update();
  c2->SaveAs(plots+"SAS_Muon_10to25"+var+"_"+cutpoint+".png");
  // c2->Close();
}



TH1D* GetHist(TString dataset, Color_t col, TString var, TCut flow,TString bin,TTree *t, TString poin){
 
  TCanvas *c1 = new TCanvas("canny"+var+dataset,"canne"+var+dataset,400,400);
  t->Draw(var+">>hist"+bin,"(wgt)"*flow);
  TH1D *HIST= (TH1D*)gDirectory->Get("hist");
  HIST->SetName(dataset+var+poin);
  c1->Close();
  if (dataset == "AS"){
 HIST->SetFillStyle(3002);
 HIST->SetFillColor(kGray+2);
  HIST->SetLineWidth(2);
  }
  else{
  HIST->SetLineWidth(3);

  }
 HIST->SetLineColor(col);

  return HIST;
}

void setstyle(){
    gROOT->SetBatch(kTRUE);
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
