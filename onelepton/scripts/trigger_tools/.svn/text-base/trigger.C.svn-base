//#include "setTDRStyle.C"

Double_t errorFun(Double_t *x, Double_t *par) {

  return 0.5*par[0]*(1. + TMath::Erf( (x[0] - par[1]) / (sqrt(2.)*par[2]) )) ;
  // return par[3] + par[0] * TMath::Freq( (x[0] - par[1]) / par[2] ) * TMath::Freq( (x[0] - par[4] ) / par[5] );

}


TLegend *legend() {
  
 TLegend *leg2 = new TLegend(0.57,0.6,0.92,0.92);
 leg2->SetFillStyle(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.04);
 leg2->SetTextFont(42); 
 
 return leg2;

}
TH2* readHist2D(TString nameHist,TString nameFile, int rebin)
{
 TFile* file = new TFile(nameFile);
 // file->ls();
 // TDirectory* dir = (TDirectory*)file->Get(Dirname);
 // dir->ls();
 TH2* hist = (TH2*)file->Get(nameHist);
 // hist->SetLineWidth(2);
 if(rebin>0) hist->RebinX(rebin);
 hist->GetXaxis()->SetTitleSize(.055);
 hist->GetYaxis()->SetTitleSize(.055);
 hist->GetXaxis()->SetLabelSize(.05);
 hist->GetYaxis()->SetLabelSize(.05);
 hist->SetStats(kFALSE);

 return hist;

}

TH1* readHistRef(TString nameHist,TString nameFile, int rebin)
{
 TFile* file = new TFile(nameFile);
 // file->ls();
 // TDirectory* dir = (TDirectory*)file->Get(Dirname);
 // dir->ls();
 TH1* hist = (TH1*)file->Get(nameHist);
 // hist->SetLineWidth(2);
 if(rebin>0) hist->Rebin(rebin);
 hist->GetXaxis()->SetTitleSize(.055);
 hist->GetYaxis()->SetTitleSize(.055);
 hist->GetXaxis()->SetLabelSize(.05);
 hist->GetYaxis()->SetLabelSize(.05);
 hist->SetStats(kFALSE);

 return hist;
}

TH1* readHistSel(TString nameHist,TString nameFile, int rebin)
{
 TFile* file =  new TFile(nameFile);
 // file->ls();
 // TDirectory* dir = (TDirectory*)file->Get(Dirname);
 // dir->ls();
 TH1* hist = (TH1*)file->Get(nameHist);
 // hist->SetLineWidth(2);

 hist->SetLineColor(9); hist->SetFillColor(9);
 hist->SetFillStyle(3035);

 if(rebin>0) hist->Rebin(rebin);
 hist->GetXaxis()->SetTitleSize(.055);
 hist->GetYaxis()->SetTitleSize(.055);
 hist->GetXaxis()->SetLabelSize(.05);
 hist->GetYaxis()->SetLabelSize(.05);
 hist->SetStats(kFALSE);

 return hist;
}


TCanvas* getaCanvas(TString name)
{

  TCanvas* aCanvas = new TCanvas(name);

  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);
  return aCanvas;
}

void drawPair(TString hname1, TString hname2, TString filename, TString entry1, TString entry2, TString xtitle, int rebin, float xhigh) {

  TH1D *ref = readHistRef(hname1, filename, rebin);
  TH1D *sel = readHistSel(hname2, filename, rebin);

  TCanvas *c=getaCanvas(hname1+hname2);

  TLegend *leg = legend();
  leg->AddEntry(ref,entry1,"LF");
  leg->AddEntry(sel,entry2,"LF");

  gPad->SetLogy(); //RefEt->SetStats(kFALSE);
  ref->Draw("E1HIST"); sel->Draw("HISTE1SAMES");

  ref->SetFillStyle(3035); ref->SetFillColor(1);
  sel->SetFillColor(9); sel->SetLineWidth(2);
  ref->GetXaxis()->SetTitle(xtitle);
  ref->GetXaxis()->SetRangeUser(0.,xhigh);

  leg->Draw("SAME");

}

TGraphAsymmErrors* drawEff(TString hname1, TString hname2, TString filename, TString header, TString xtitle,
			   int rebin, bool asymBin, float xhigh, int icol, int imark, TString draw) {

  // gStyle->SetOptStat(1);
  // gStyle->SetOptFit(1);

  TH1D *ref = readHistRef(hname1, filename, rebin);
  TH1D *sel = readHistSel(hname2, filename, rebin);

  ref->SetName(hname1+header); cout << "Ref = " << ref->Integral() << endl;
  sel->SetName(hname2+header); cout << "Sel = " << sel->Integral() << endl;

  // ref->Draw(); sel->Draw("SAME");
  //sel->SetLineColor(2); return;
 //  TCanvas *c=getaCanvas(hname1+hname2+"_eff");
//   gPad->SetGridy();  gPad->SetGridx();
//   gPad->SetLogx();

 //  TLegend *leg = legend();
//   leg->SetHeader(header);

  // TH1D *Eff=new TH1D("effi","",ref->GetNbinsX(),ref->GetXaxis()->GetXmin(),ref->GetXaxis()->GetXmax());
  TGraphAsymmErrors *Eff = new TGraphAsymmErrors();
  if (asymBin) {
    Double_t xbins[16]={0.,50.,100.,125.,150.,170.,190.,210.,225.,250.,
			300.,350.,400.,490.,800.,2000.};

    sel->Rebin(16,"nsel",xbins);
    ref->Rebin(16,"nref",xbins);
    Eff->BayesDivide(nsel, nref);
  } else {
    // Eff->Divide(sel,ref,1,1,"B");
    Eff->BayesDivide(sel, ref);
  }

  //Eff->Draw(); return;

  // gStyle->SetOptStat(1);
  gStyle->SetOptFit(1);

  TF1 *fermiFunction = new TF1("fermiFunction",errorFun,3.,xhigh,3);
  Double_t params[3] = {1.,200.,10.};            
  fermiFunction->SetParameters(params);
  fermiFunction->SetParNames("#epsilon","#mu","#sigma");
  fermiFunction->SetLineColor(4);
  fermiFunction->SetLineWidth(3.5);
  //Eff->Draw("AP");
  Eff->Fit("fermiFunction","R+");
  Eff->SetMarkerColor(icol);// EtEff0->SetMarkerColor(1);
  Eff->SetLineColor(icol); Eff->SetLineWidth(3);
  Eff->SetMarkerStyle(imark); Eff->SetMarkerSize(1.2);
  Eff->GetXaxis()->SetTitle(xtitle);
  Eff->GetYaxis()->SetTitle("Efficiency");
  Eff->GetYaxis()->SetRangeUser(0.,1.05);
  Eff->GetXaxis()->SetRangeUser(3.,xhigh);
  // Eff->PaintFit(fermiFunction);

  if (draw=="") {
    Eff->Draw("AP");
  } else {
    Eff->Draw("P");
  }
 //  fermiFunction->Draw("SAME"); 
//   fermiFunction->SetLineColor(1);
//   fermiFunction->SetLineWidth(2);

//  leg->Draw("SAME");

  return Eff;

}

void drawEff2(TString hname1, TString hname2, TString filename, TString header, TString xtitle, int rebin, float xlow, float xhigh) {

  // gStyle->SetOptStat(1);
  // gStyle->SetOptFit(1);

  TH1D *ref = readHistRef(hname1, filename, rebin);
  TH1D *sel = readHistSel(hname2, filename, rebin);

  ref->SetName(hname1+header);
  sel->SetName(hname2+header);

  TCanvas *c=getaCanvas(hname1+hname2+"_eff");
  gPad->SetGridy();  gPad->SetGridx();
 
  TLegend *leg = legend();
  leg->SetHeader(header);

  TGraphAsymmErrors *Eff = new TGraphAsymmErrors();
  Eff->BayesDivide(sel, ref);
  
  Eff->GetYaxis()->SetRangeUser(0.5,1.04);
  Eff->Draw("AP");

  leg->Draw("SAME");

}
void draw2D(TString hname, TString filename, TString header, TString xtitle,TString ytitle, int rebin, 
	    bool col, float xlow,float xhigh, float ylow, float yhigh) {

  TH2D *ref = readHist2D(hname, filename, rebin);

  TCanvas *c=getaCanvas(hname);

   TLegend *leg = legend();
  leg->SetHeader(header);

  gStyle->SetPalette(1);

  if (col) {
    ref->Draw("COLZ"); 
  } else {
    ref->Draw();
  }
  ref->GetXaxis()->SetTitle(xtitle);
  ref->GetYaxis()->SetTitle(ytitle);
  ref->GetXaxis()->SetRangeUser(xlow,xhigh);
  ref->GetYaxis()->SetRangeUser(ylow,yhigh);

  //  pt->SetLabel("#sqrt{s}=900 GeV");
  //  pt->Draw("SAME");
  leg->Draw("SAME");

}


void trigger() {

  TString ifile="singlemu15_withPFJets.root";

  int m_etNBins = 50; int m_etaNBins = 22; int m_phiNBins = 20;
  double m_etMin = 0.; double m_etaMin = -5.; double m_phiMin = -3.3161256;
   double m_etMax = 100.; double m_etaMax = 5.; double m_phiMax = 3.3161256;

   //  setTDRStyle();
  gStyle->SetOptStat(1);
  gStyle->SetOptFit(1);

  TCanvas *c=getaCanvas("_eff");
  gPad->SetGridy();  gPad->SetGridx();
  //  gPad->SetLogx();
  TLegend *leg = legend();
  //leg->SetHeader(header);
  
  TGraphAsymmErrors *eff1 = drawEff("MuonStandardPlots/H_{T}^{had}_all","MuonStandardPlots_PostHLT/H_{T}^{had}_all",
				    ifile,"HLT_Mu8_HT200","H_{T}, GeV",4,1,2000.,1,20,"");

  leg->Draw("SAME");  


}
