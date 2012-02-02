TFile *fW=new TFile("eWPol_Signal_W_enu.root");

/* TFile *fSig=new TFile("eWPol_Signal_MC_QCD15P8_SKMD.root");  */
/* TFile *fCtrl=new TFile("eWPol_Control_MC_QCD15P8_SKMD.root"); */
TFile *fSig=new TFile("eWPol_Signal_SD_JMT_SKMD.root");
TFile *fCtrl=new TFile("eWPol_Control_SD_JMT_SKMD.root");

TString w_dir = "eWPolBasicPlots_PreMHT/";
TString plot_dir = "eTree_PreMHT/";

TTree *trW=(TTree*)fW->Get(w_dir+"T");
TTree *tSig=(TTree*)fSig->Get(plot_dir+"T");
TTree *tCtrl=(TTree*)fCtrl->Get(plot_dir+"T");

struct fit_info{
  double val1;
  double val2;
  double err1;
  double err2;
  double corr1;
  double corr2;
  double corr3;
  double val1_corr;
  double val2_corr;
  double err1_corr;
  double err2_corr;
  double gcor1;
  double gcor2;
  double gcor12;
  double nom;
};

fit_info* draw_tree(double htcut) {

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  //  TString weight_w="wgt"
  /* TString weight="wgt"; // scale to 1pb-1 */
  /* TString no_we="1"; */
  /* // Start plotting */

  /* TString etCut="pt_e>10."; */

  /* TString theHT=" && pfMet<"; theHT+=htcut; */

  /* TH1D *hW=plotIsoW(trW,"combIso",weight,etCut+theHT+" && nEle>=1", */
  /* 		   "nJet>=0","w","(100,0.,2.)",1,5); */
  
  /* TH1D *hSelection=plotIso(tSig,"combIso",weight,etCut+theHT+" && nEle>=1", */
  /* 			   "nJet>=0","sel","(100,0.,2.)",1,1); */
  /* TH1D *hControl = plotIso(tCtrl,"combIso",weight,etCut+theHT+" && nEle>=1", */
  /* 			   "nJet>=0","ctrl","(100,0.,2.)",1,3); */
  /* TH1D *hConversions=plotIsoConv(tSig,"combIso",weight,etCut+theHT+" && nEle>=1", */
  /* 				 "nJet>=0","conv","(100,0.,2.)",1,2); */

  fit_info *fit = do_fit(trW,tSig,tCtrl,tSig,htcut);
  //fit_info *fit = do_fit(hW,hSelection,hControl,hConversions,htcut);
  return fit;

}

TH1D *plotIso(TTree *tSig,TString var,TString weight, TString etcut, TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol)
{
  TCut etcut20=weight+" * ("+etcut+" && "+njetcut+")";

  //  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv1=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=0)";
  TCut conv3=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=0 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  tSig->Draw(var+">>hsqrti"+bin,conv3);
  TH1D *hsqrt = (TH1D*)gDirectory->Get("hsqrti");
  hsqrt->SetName(ph+var+etcut+"hsqrti");

  hsqrt->SetLineColor(icol);
  hsqrt->SetLineWidth(3);

  return hsqrt;
}

TH1D *plotIsoW(TTree *tSig,TString var,TString weight, TString etcut, TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol)
{
  TCut etcut20=weight+" * ("+etcut+" && "+njetcut+")";

  //  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  //  TCut conv1=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=1)";
  TCut conv3=weight+" * ("+etcut+" && "+njetcut+"&& hitFP==1 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  tSig->Draw(var+">>whsqrti"+bin,conv3);
  TH1D *hsqrt = (TH1D*)gDirectory->Get("whsqrti");
  hsqrt->SetName(ph+var+etcut+"whsqrti");

  hsqrt->SetLineColor(icol);
  hsqrt->SetLineWidth(3);

  return hsqrt;
}

TH1D *plotIsoConv(TTree *tSig,TString var,TString weight, TString etcut, TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol)
{
  TCut etcut20=weight+" * ("+etcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+" && "+njetcut+"&& (hitFP==0))";
  TCut conv3=weight+" * ("+etcut+" && "+njetcut+"&& (hitFP==0 || !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";
  TCut conv4=weight+" * ("+etcut+" && "+njetcut+"&& ( !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";

  tSig->Draw(var+">>hsqrtico"+bin,conv4);
  TH1D *hsqrt = (TH1D*)gDirectory->Get("hsqrtico");
  hsqrt->SetName(ph+var+etcut+"hsqrtico");

  hsqrt->SetLineColor(icol);
  hsqrt->SetLineWidth(3);

  return hsqrt;
}

TH2D *plotCor2D(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  //  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv1=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1)";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  tSig->Draw(var+">>hsqrtij"+bin,conv3);
  TH2D *hsqrt = (TH2D*)gDirectory->Get("hsqrtij");
  hsqrt->SetName(ph+var+htcut+"hsqrtij");

  return hsqrt;
}

TH3D *plotCor(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  //  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv1=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1)";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  tSig->Draw(var+">>hsqrti"+bin,conv3);
  TH3D *hsqrt = (TH3D*)gDirectory->Get("hsqrti");
  hsqrt->SetName(ph+var+htcut+"hsqrti");

  return hsqrt;
}

TH3D *plotConv(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  //  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && hitFP==0)";
  TCut conv1=weight+" * ("+etcut+htcut+" && "+njetcut+"&& (hitFP==0))";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& (hitFP==0 || !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";
  TCut conv4=weight+" * ("+etcut+htcut+" && "+njetcut+"&& ( !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";

  
  tSig->Draw(var+">>hsqrtic"+bin,conv4);
  TH3D *hsqrt = (TH3D*)gDirectory->Get("hsqrtic");
  hsqrt->SetName(ph+var+htcut+"hsqrtic");

  return hsqrt;
}

TH1D *plotCanvas(TTree *tSig,TString var,TString weight, TString etcut, TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol) {

  TCanvas *c1=getaCanvas(ph+var+"c1");

  TCut etcut20=weight+" * ("+etcut+" && "+njetcut+")";

  //  TCut conv1=weight+" * ("+etcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv1=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=1)";
  TCut conv3=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=1 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";


  tSig->Draw(var+">>hsqrt"+bin,etcut20);
  TH1F *hsqrt = (TH1F*)gDirectory->Get("hsqrt");
  hsqrt->SetName(ph+var+"hsqrt");

  tSig->Draw(var+">>temp1",conv1,"samehist");
  TH1F *htemp1 = (TH1F*)gDirectory->Get("temp1");
  htemp1->SetLineStyle(2);htemp1->SetLineWidth(3); 
  htemp1->SetName(ph+var+"temp1");

  tSig->Draw(var+">>temp2",conv2,"samehist");
  TH1F *htemp2 = (TH1F*)gDirectory->Get("temp2");
  htemp2->SetLineStyle(3);htemp2->SetLineWidth(3); 
  htemp2->SetName(ph+var+"temp2");

  tSig->Draw(var+">>temp3",conv3,"samehist");
  TH1F *htemp3 = (TH1F*)gDirectory->Get("temp3");
  htemp3->SetLineStyle(4);htemp3->SetLineWidth(3); 
  htemp3->SetName(ph+var+"temp3");

  TLegend *leg=legend();
  leg->AddEntry(hsqrt,"All electrons","L");
  leg->AddEntry(htemp1,"+ hit in FirstPixelLayer","L");
  leg->AddEntry(htemp2,"+ missing expexted hits < 2","L");
  leg->AddEntry(htemp3,"+ Conversion Finder","L");

  leg->Draw("SAME");

  c1->Update();

  // Efficiency
  TCanvas *c2 = getaCanvas(ph+var+"c2");
  gPad->SetGridx(); gPad->SetGridy();

  TH1D *temp3 = htemp3->Clone(); 
  temp3->Reset();
  htemp3->Sumw2(); htemp1->Sumw2();
  temp3->Divide(htemp3,htemp1,1,1,"B");

  temp3->Draw("E");
  temp3->SetLineColor(icol);
  temp3->GetXaxis()->SetRangeUser(0.,xmax);
  temp3->GetYaxis()->SetRangeUser(0.,1.);
  temp3->SetLineStyle(1);

  c2->Update();

  return temp3;

}
void setStyles() {

  gROOT->SetStyle("Plain");
  gStyle->SetCanvasDefW(700);
  gStyle->SetCanvasDefH(600);
}

TLegend *legend() {

 TLegend *leg2 = new TLegend(0.5,0.55,0.82,0.82);
 leg2->SetFillStyle(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.06);
 leg2->SetTextFont(42);

 return leg2;

}
TCanvas* getaCanvas(TString name)
{

  TCanvas* aCanvas = new TCanvas(name);

  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  //  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);
  return aCanvas;
}

//fit_info* do_fit(TH1D *hW,TH1D *hSelection, TH1D *hControl, TH1D *hConversions, double theHT) {

fit_info* do_fit(TTree *trW,TTree *tSig, TTree *tCtrl, TTree *tSig, double htcut) {

  TString weight="wgt"; // scale to 1pb-1
  TString no_we="1";
  // Start plotting

  TString etCut="pt_e>10.";

  TString theHT=" && pfMet<"; theHT+=htcut;

  TH1D *hW=plotIsoW(trW,"combIso",weight,etCut+theHT+" && nEle>=1",
		    "nJet>=0","w","(100,0.,2.)",1,5);
  
  TH1D *hSelection=plotIso(tSig,"combIso",weight,etCut+theHT+" && nEle>=1",
			   "nJet>=0","sel","(100,0.,2.)",1,1);
  TH1D *hControl = plotIso(tCtrl,"combIso",weight,etCut+theHT+" && nEle>=1",
			   "nJet>=0","ctrl","(100,0.,2.)",1,3);
  TH1D *hConversions=plotIsoConv(tSig,"combIso",weight,etCut+theHT+" && nEle>=1",
				 "nJet>=0","conv","(100,0.,2.)",1,2);

  //  double sigE=tSig->GetEntries(etCut+theHT+"combIso<0.1 && nJet>=0 && nEle>=1 && mHits<=1 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)");
  // cout << "total events = " << sigE << endl;

  /* gSystem->Load("libRooFit"); using namespace RooFit; */

  RooRealVar x("x","Relative Isolation",0.,0.7);

  RooRealVar wN("N_W","W coefficient",10,0.,10000.);
  
  RooRealVar alpha("nconv","a coefficient",10.,0.,100000.) ;
  RooRealVar fakes("nfakes","b coefficient",100.,0.,100000.) ;
  RooFormulaVar nBkg("N_bkg","","nconv+nfakes",RooArgList(alpha,fakes));

  RooDataHist tempW("tempW","tempW",x,hW);
  RooDataHist temp1("temp1","temp1",x,hConversions);//p_conv);
  RooDataHist temp2("temp2","temp2",x,hControl);//p_ctrl);

  RooHistPdf tW("tW","Template for W",x,tempW);
  RooHistPdf tConv("tConv","Template for conversions",x,temp1);
  RooHistPdf tFakes("tFakes","Template for fakes",x,temp2);

  // Composite Model PDF
  RooAddPdf bkg("bkg","bkg PDF",RooArgList(tConv, tFakes),RooArgList(alpha,fakes));
  //  RooAddPdf model("model","bkg PDF",RooArgList(tConv, tFakes),RooArgList(alpha,fakes));
  RooAddPdf model("model","w bkg PDF",RooArgList(tW, bkg),RooArgList(wN,nBkg));
  // Data
  RooDataHist data("data","data",x,hSelection);
  
  // Fitting
  RooFitResult *fitr = model.fitTo(data,Minos(kTRUE),Extended(kTRUE), Save(kTRUE));

  // Signal region for prediction
  double cut=0.1;

  x.setRange("selection",0.,cut);
  Int_t low=hSelection->GetXaxis()->FindBin(0.);
  Int_t high=hSelection->GetXaxis()->FindBin(cut);
  RooAbsReal *intOfFunc = bkg.createIntegral(x,NormSet(x),Range("selection"));
  // Double_t nPredicted =(intOfFunc->getVal()*nBkg.getVal());
  Double_t nPredicted =(intOfFunc->getVal()*bkg.expectedEvents(x));

  Double_t factor1=tConv.createIntegral(x,NormSet(x),Range("selection"))->getVal();
  Double_t factor2=tFakes.createIntegral(x,NormSet(x),Range("selection"))->getVal();

  cout << "Fraction of conv = " << factor1 << endl;
  cout << "Fraction of fakes = " << factor2 << endl;

  double err1_corr=alpha.getError()*factor1;
  double err2_corr=fakes.getError()*factor2;
  double gcor12=fitr->correlation(alpha,fakes);
  double comb_error = sqrt(err1_corr*err1_corr + err2_corr*err2_corr 
				     + 2.*err1_corr*err2_corr*gcor12);
  cout << "" << endl;
  cout << "***********************************************************" << endl;
  cout << "Number of e in data = " << hSelection->Integral(low,high) << endl;
  cout << "Number of e predicted = " << nPredicted << " +/- " << comb_error << endl;
  cout << "***********************************************************" << endl;
  cout << "" << endl;


  fit_info* fit=new fit_info();
  
  fit->nom= hSelection->Integral(low,high);
    //nObserved;

  fit->val1=alpha.getVal();
  fit->val2=fakes.getVal();
  fit->err1=alpha.getError();
  fit->err2=fakes.getError();

  fit->corr1=fit->val1*factor1;
  fit->corr2=fit->val2*factor2;
  fit->err1_corr=fit->err1*factor1;
  fit->err2_corr=fit->err2*factor2;

  fit->gcor12 = fitr->correlation(alpha,fakes);

  // Plotting
  setStyles();

  TString labelName="Predicted bkg = ";
  labelName+=(int)nPredicted;
  labelName+=" +/- ";
  labelName+=(int)comb_error;

  TString canvasName="c";
  canvasName+=fit->corr1;

  TCanvas *cf = new TCanvas("cfit"+canvasName,"");

  TLegend *leg = new TLegend(.3,.6,.5,.8,"");
  leg->SetTextSize(0.03);
  leg->SetFillColor(0);
  leg->SetLineColor(0);

  TH1D *sdata=hSelection->Clone(); sdata->SetMarkerStyle(20);
  TH1D *hTotal=hSelection->Clone(); hTotal->SetFillColor(1); hTotal->SetFillStyle(3005);

  TString cHT=" "; cHT+=theHT;
  leg->SetHeader(cHT+" GeV");
  leg->AddEntry(sdata,"data","LP");

  leg->AddEntry(hSelection,"Fit result","L");

  leg->AddEntry(hW,"W template","F");
  leg->AddEntry(hTotal,"Background template","F");
  leg->AddEntry(hControl,"Fakes from eleID anti-selected events","L");
  leg->AddEntry(hConversions,"Conversions from anti-selected events","L");

  hSelection->SetLineColor(kBlue); hSelection->SetLineWidth(3);
  hControl->SetLineColor(kGreen); hControl->SetLineStyle(2);hControl->SetLineWidth(3);
  hConversions->SetLineColor(kRed); hConversions->SetLineStyle(2);hConversions->SetLineWidth(3);
  
  RooPlot * xframe = x.frame();
 
  data.plotOn(xframe);//,Binning(50));
  data.statOn(xframe,Label(labelName),What("N"),CutRange("selection"),
	      Format("NEU",AutoPrecision(2)));
    
  model.plotOn(xframe); model.paramOn(xframe,Label("Fit result"));

  model.plotOn(xframe,Components(tW),FillColor(5),DrawOption("F"));
  model.plotOn(xframe,Components(bkg),LineColor(1),DrawOption("F"),FillStyle(3035));//LineStyle(kDashed));
  model.plotOn(xframe,Components(tFakes),LineColor(kGreen),LineWidth(3),LineStyle(kDashed));
  model.plotOn(xframe,Components(tConv),LineColor(2),LineWidth(3),LineStyle(kDashed));
  data.plotOn(xframe);
  xframe->GetYaxis()->SetRangeUser(0.,100.);
  xframe->Draw();

  leg->Draw("SAME");
  cf->SaveAs(canvasName+".png");
  cf->Update();

  return fit;
}

void plot_iso() {
  gSystem->Load("libRooFit"); using namespace RooFit;

  TGraphErrors* g1=new TGraphErrors(100);
  g1->SetMarkerColor(kRed);g1->SetLineColor(kRed);
  g1->SetMarkerStyle(29); g1->SetMarkerSize(2.5);
  g1->SetLineWidth(3);
  TGraphErrors* g2=new TGraphErrors(100);
  g2->SetMarkerStyle(29); g2->SetMarkerSize(2.5);
  g2->SetMarkerColor(14);g2->SetLineColor(14);
  g2->SetLineWidth(3);
  TGraphErrors* g3=new TGraphErrors(100);
  g3->SetMarkerStyle(20); g3->SetMarkerSize(1.5);
  g3->SetLineWidth(2.5);

  TGraphErrors* fg1=new TGraphErrors(100);
  fg1->SetMarkerColor(kRed);fg1->SetLineColor(kRed);
  fg1->SetMarkerStyle(29); fg1->SetMarkerSize(2.5);
  fg1->SetLineWidth(3);
  TGraphErrors* fg2=new TGraphErrors(100);
  fg2->SetMarkerStyle(29); fg2->SetMarkerSize(2.5);
  fg2->SetMarkerColor(14);fg2->SetLineColor(14);
  fg2->SetLineWidth(3);


  int region=1;
  bool addW=false;

  int i=0;


  /* double nomi[5]={37.,28.,16.,12.,8.}; */
  /* double enomi[5]={0.,0.,0.,0.,0.}; */

  /* double obs[5]={34.5,22.,14.7,12.3,8.9}; */
  /* double eobs[5]={3.7,3.1,2.2,1.5,1.2}; */

  /* double nh[5]={20.,30.,40.,50.,60.}; */
  /*   for (i=0; i<5; i++) { */

  /*     g1->SetPoint(i,nh[i],obs[i]); g1->SetPointError(i,2.,eobs[i]); */
  /*   //    g2->SetPoint(i,nj,fw->corr1+fw->corr2); g2->SetPointError(i,5.,comb_error_sum_w); */
  /*     g3->SetPoint(i,nh[i],nomi[i]); g3->SetPointError(i,2.,0); */

  /*   } */
  int i=0; int inj;
  for (double nj=20.; nj<=20.; nj+=10.) {
    i++;
    inj=nj;
    if (i==8) nj=1000.;

    fit_info* fb = draw_tree(nj);

    //    return;

    double comb_error_sum_b = sqrt(fb->err1_corr*fb->err1_corr + fb->err2_corr*fb->err2_corr
  				     + 2.*fb->err1_corr*fb->err2_corr*fb->gcor12);
    //    double comb_error_sum_w = sqrt(fw->err1_corr*fw->err1_corr + fw->err2_corr*fw->err2_corr +
    //				   2.*fw->err1_corr*fw->err2_corr*fw->gcor12);

    g1->SetPoint(i,inj,fb->corr1+fb->corr2); g1->SetPointError(i,2.,comb_error_sum_b);
    //    g2->SetPoint(i,nj,fw->corr1+fw->corr2); g2->SetPointError(i,5.,comb_error_sum_w);
    g3->SetPoint(i,inj,fb->nom); g3->SetPointError(i,2.,0);

    double tot=fb->corr1+fb->corr2;

    fg1->SetPoint(i,nj,(fb->corr1/tot)); fg1->SetPointError(i,2.,0.);

    i++;
  }

  setStyles();

  TCanvas* can=new TCanvas("ifrac","");
  gPad->SetGridx(); gPad->SetGridy();

  fg1->Draw("AP");
  fg1->SetTitle(";pfMET anti-cut;fraction of conversions");

  TCanvas* can=new TCanvas("itest","");

  gPad->SetGridx(); gPad->SetGridy();

  TLegend *leg = new TLegend(.5,.5,.8,.8,"");
  leg->AddEntry(g3,"observed","P");
  leg->AddEntry(g1,"predicted background","P");
//  leg->AddEntry(g2,"predicted (W+QCD)","P");

  leg->SetFillColor(0);
  leg->SetLineColor(0);

  //  g2->GetHistogram()->GetXaxis()->SetRangeUser(-0.5,3.5);
  //g2->Draw("AP");
  g3->SetTitle(";pfMET anti-cut;N electrons");
  g3->Draw("AP");
  g1->Draw("P");

  leg->Draw("SAME");


}
