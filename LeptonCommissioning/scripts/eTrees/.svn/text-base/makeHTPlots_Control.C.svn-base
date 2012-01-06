#include "setTDRStyle.C"
TFile *fSig=new TFile("eWPol_Control_Odd_SD_JMT_SKMD.root");
TFile *fCtrl=new TFile("eWPol_Control_MC_QCD15P8_SKMD.root");



TString file = "MCvsJMT_Control";
TString variable = "HT";

/* TFile *fSig=new TFile("eWPol_Signal_MC_QCD15P8_SKMD.root"); */
/* TFile *fCtrl=new TFile("eWPol_Control_MC_QCD15P8_SKMD.root"); */

TString plot_dir = "eTree_PreMHT/";


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

  double icorr1;
  double icorr2;
  double ierr1_corr;
  double ierr2_corr;

  double gcor1;
  double gcor2;
  double gcor12;

  double nom;
  double inom;

  double ictrl;
  double ctrl;

};

fit_info* draw_tree(double cut, double step) {

  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TString weight="wgt"; // scale to 1pb-1
  TString no_we="1";
  // Start plotting

  TString etCut="pt_e>10.";

  TString fake="&& (lepType<0 || lepType==9) && (gPar!=22)";
  TString HF="&& (lepType==10 || lepType==4) ";
  TString Conversion="&& lepType<0 && gPar==22";
  TString fakeCH="&& ((lepType<0 && (gPar==211 || gPar==321)) || lepType==10)";

  TString theHT=" && ht>";theHT+=cut;
  TString theEta=" && caloIso<0.3";// theEta+=cut;e_
  // theEta+=" && eta_j1>"; theEta+=cut;
  // theEta+=" && eta_j1<"; theEta+=(cut+step); 

  TH1D *hSelection=plotIso(tSig,"alphaT",weight,etCut+theHT+" && nEle==1",theEta,
			   "nJet>=1 && et_j1>40.","sel","(100,0.,2.)",1.,1);
  TH1D *hControl=plotIso(tCtrl,"alphaT",weight,etCut+theHT+" && nEle==1",theEta,
			   "nJet>=1 && et_j1>40.","ctrl","(100,0.,2.)",1.,3);
  TH1D *hConversions=plotIsoConv(tSig,"alphaT",weight,etCut+theHT+" && nEle==1",theEta,
			   "nJet>=1 && et_j1>40.","conv","(100,0.,2.)",1.,2);


   hControl->Scale(0.0012);

  fit_info *fit = do_fit(hSelection,hControl,hConversions,cut,step);
  return fit;

}

TH1D *plotIso(TTree *tSig,TString var,TString weight, TString etcut, TString htcut, TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv2=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1)";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  TCanvas *c = getaCanvas(ph+var+etcut+htcut+"hsqrti");

  tSig->Draw(var+">>hsqrti"+bin,conv3);
  TH1D *hsqrt = (TH1D*)gDirectory->Get("hsqrti");
  hsqrt->SetName(ph+var+htcut+"hsqrti");

  hsqrt->SetLineColor(icol);
  hsqrt->SetLineWidth(3);
  c->Close();
  return hsqrt;
}

TH1D *plotIsoConv(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+htcut+" && "+njetcut+"&& (hitFP==0))";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& (hitFP==0 || !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";
  TCut conv4=weight+" * ("+etcut+htcut+" && "+njetcut+"&& ( !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";

  TCanvas *c = getaCanvas(ph+var+etcut+htcut+"hsqrtico");

  tSig->Draw(var+">>hsqrtico"+bin,conv4);
  TH1D *hsqrt = (TH1D*)gDirectory->Get("hsqrtico");
  hsqrt->SetName(ph+var+htcut+"hsqrtico");

  hsqrt->SetLineColor(icol);
  hsqrt->SetLineWidth(3);
  c->Close();
  return hsqrt;
}


TH2D *plotCor2D(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv2=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && mHits<2)";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && mHits<2 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  tSig->Draw(var+">>hsqrtij"+bin,conv1);
  TH2D *hsqrt = (TH2D*)gDirectory->Get("hsqrtij");
  hsqrt->SetName(ph+var+htcut+"hsqrtij");

  return hsqrt;
}

TH3D *plotCor(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv2=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && mHits<2)";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& mHits<=1 && mHits<2 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";
  
  tSig->Draw(var+">>hsqrti"+bin,conv1);
  TH3D *hsqrt = (TH3D*)gDirectory->Get("hsqrti");
  hsqrt->SetName(ph+var+htcut+"hsqrti");

  return hsqrt;
}

TH3D *plotConv(TTree *tSig,TString var,TString weight, TString etcut, TString htcut,TString njetcut, TString ph, TString bin)
{
  TCut etcut20=weight+" * ("+etcut+htcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+htcut+" &&"+njetcut+" && hitFP==0)";
  TCut conv2=weight+" * ("+etcut+htcut+" && "+njetcut+"&& (hitFP==0 && mHits>=2))";
  TCut conv3=weight+" * ("+etcut+htcut+" && "+njetcut+"&& (hitFP==0 && mHits>=2 && !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";
  TCut conv4=weight+" * ("+etcut+htcut+" && "+njetcut+"&& ( !(dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02)) )";

  
  tSig->Draw(var+">>hsqrtic"+bin,conv4);
  TH3D *hsqrt = (TH3D*)gDirectory->Get("hsqrtic");
  hsqrt->SetName(ph+var+htcut+"hsqrtic");

  return hsqrt;
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

TH1D *plotCanvas(TTree *tSig,TString var,TString weight, TString etcut, TString njetcut, TString ph, TString bin,Double_t xmax, Int_t icol) {

  TCanvas *c1=getaCanvas(ph+var+"c1");

  TCut etcut20=weight+" * ("+etcut+" && "+njetcut+")";

  TCut conv1=weight+" * ("+etcut+" &&"+njetcut+" && mHits<=1)";
  TCut conv2=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=1 && mHits<2)";
  TCut conv3=weight+" * ("+etcut+" && "+njetcut+"&& mHits<=1 && mHits<2 && (dcot>0.02 || dcot<-0.02 || dist>0.02 || dist<-0.02))";


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
  c1->Close();
  c2->Close();
  return temp3;

}
void setStyles() {

  gROOT->SetStyle("Plain");
  gStyle->SetCanvasDefW(600);
  gStyle->SetCanvasDefH(600);
}

TLegend *legend() {

 TLegend *leg2 = new TLegend(0.5,0.55,0.82,0.82);
 leg2->SetFillStyle(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.045);
 leg2->SetTextFont(42);

 return leg2;

}


fit_info* do_fit(TH1D *hSelection, TH1D *hControl, TH1D *hConversions, double theHT, double thestep) {

  //  gSystem->Load("libRooFit"); using namespace RooFit;

  double hi=3.;

  RooRealVar x("x","alphaT",0.,hi);
  
  RooRealVar alpha("nconv","a coefficient",0.);//100.,0.,100000.) ;
  RooRealVar fakes("nfakes","b coefficient",1000.,0.,100000.) ;
  RooFormulaVar nBkg("N_bkg","","nconv+nfakes",RooArgList(alpha,fakes));

  RooDataHist temp1("temp1","temp1",x,hConversions);//p_conv);
  RooDataHist temp2("temp2","temp2",x,hControl);//p_ctrl);

  RooHistPdf tConv("tConv","Template for conversions",x,temp1);
  RooHistPdf tFakes("tFakes","Template for fakes",x,temp2);

  // Composite Model PDF
  RooAddPdf bkg("bkg","bkg PDF",RooArgList(tConv, tFakes),RooArgList(alpha,fakes));
  RooAddPdf model("model","bkg PDF",RooArgList(tConv, tFakes),RooArgList(alpha,fakes));
  
  // Data
  RooDataHist data("data","data",x,hSelection);
  
  // Fitting
  //  double fitH=GetMinimum(hSelection,0.55,3.);
  RooFitResult *fitr=0;// = bkg.fitTo(data,Range(0.3,fitH),Minos(kTRUE),Extended(kTRUE), Save(kTRUE));

  // Signal region for prediction
  double cut=0.55;
  x.setRange("selection",cut,hi);
 
  Int_t low=hSelection->GetXaxis()->FindBin(cut);
  Int_t high=hSelection->GetXaxis()->FindBin(hi);


  fit_info* fit=new fit_info();
  fit->inom=hSelection->Integral(0,high);
    //data.createIntegral(x,NormSet(x),Range("lowsel"))->getVal();
    //hSelection->Integral(0,low);
  //fit->nom=data.createIntegral(x,NormSet(x),Range("selection"))->getVal(); 
  fit->nom=hSelection->Integral(low,high);
    //nObserved;

  fit->ictrl=hControl->Integral(0,high);
  fit->ctrl=hControl->Integral(low,high);

  fit->val1=alpha.getVal();
  fit->val2=fakes.getVal();
  fit->err1=alpha.getError();
  fit->err2=fakes.getError();

  /* fit->corr1=fit->val1*factor1; */
  /* fit->corr2=fit->val2*factor2; */
  /* fit->err1_corr=fit->err1*factor1; */
  /* fit->err2_corr=fit->err2*factor2; */

  /* fit->icorr1=fit->val1*ifactor1; */
  /* fit->icorr2=fit->val2*ifactor2; */
  /* fit->ierr1_corr=fit->err1*ifactor1; */
  /* fit->ierr2_corr=fit->err2*ifactor2; */

  //  fit->gcor12 = fitr->correlation(alpha,fakes);

  // Plotting
  setStyles();

  TString labelName="Predicted = ";
  //  labelName+=(int)nPredicted;
  labelName+=" +/- ";
  //  labelName+=(int)comb_error;

  TString canvasName="c";
  canvasName+=theHT;

  TCanvas *c = new TCanvas("cfit"+canvasName,"");

  TLegend *leg = new TLegend(.5,.7,.99,.99,"");
  leg->SetTextSize(0.03);
  leg->SetFillColor(0);
  leg->SetLineColor(0);
  //  TString varcut = variable;
  // varcut+=theHT;





  //  double etalow = theHT;
  //  double etahigh = theHT+thestep;

  TH1D *sdata=hSelection->Clone(); sdata->SetMarkerStyle(20);
   TString headerName="H_{T} >"; headerName+=theHT;
   TString varcut = variable; varcut+=theHT;
  //  TString headerNamea =""; headerNamea +=etalow;
  ///  TString headerNameb = " < |#eta_{j1}| < "; headerNameb+=etahigh;

   // leg->SetHeader(headerNamea+headerNameb);
   leg->SetHeader(headerName);
  leg->AddEntry(sdata,"data","LP");

  //  leg->AddEntry(hSelection,"Fit result","L");

  leg->AddEntry(hControl,"monte-Carlo (data-like)","L");
  //leg->AddEntry(hConversions,"Conversions from anti-selected events","L");

  hSelection->SetLineColor(kBlue); hSelection->SetLineWidth(3);
  hControl->SetLineColor(kBlue); hControl->SetLineStyle(1);hControl->SetLineWidth(3);
   hConversions->SetLineColor(kRed); hConversions->SetLineStyle(2);hConversions->SetLineWidth(3);
  
  //  gPad->SetLogy();

    RooPlot * xframe = x.frame();
 
    data.plotOn(xframe);//,Binning(100));
  //  data.statOn(xframe,Label(labelName),What("N"),CutRange("selection"),
  //	      Format("NEU",AutoPrecision(2)));
    
   model.plotOn(xframe);//,Binning(100));// model.paramOn(xframe,Label("Fit result"));

  // model.plotOn(xframe,Components(tConv),LineColor(kRed),LineStyle(kDashed));
  //model.plotOn(xframe,Components(tFakes),LineColor(kGreen),LineStyle(kDashed));

    data.plotOn(xframe);
   xframe->GetXaxis()->SetRangeUser(0.2,0.9);
   // xframe->GetYaxis()->SetRangeUser(0,2);
   xframe->Draw();
  // hControl->SetLineStyle();
  //
   //  xframe->SetTitle("selected events");
   xframe->SetTitle("anti-selected events");
//hSelection->Draw("E");
  //hSelection->SetTitle();
  //hControl->Draw("HISTSAME");
  leg->Draw("SAME");
    //    return;
  c->Update();
  c->SaveAs("Plots/"+file+"_RaT_"+varcut+".png");
	    //+file+"_RaT_"+variable+"_"+theHT+".png");
  return fit;
}

void makeHTPlots_Control() {

  //  fit_info* fb = draw_tree(0.1);
  //  return;
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
  double step=0.5;
  //  for (double nj=0.05; nj<0.9; nj+=0.1) { // Iso bins
   for (double nj=40.; nj<=150.; nj+=15.) { // HT bins
     //  for (double nj=0; nj<=3.5; nj+=step) { // j1 eta bins
    fit_info* fb = draw_tree(nj,step);

    //    double comb_error_sum_b = sqrt(fb->err1_corr*fb->err1_corr + fb->err2_corr*fb->err2_corr 
    //				     + 2.*fb->err1_corr*fb->err2_corr*fb->gcor12);

    cout << "ISo < " << nj << endl;

    //    cout << " a= " << (fb->corr1+fb->corr2) << endl;
    //    cout << " b= " << (fb->icorr1+fb->icorr2) << endl;

    //    double RaT= ((fb->corr1+fb->corr2) / (fb->icorr1+fb->icorr2));
    //    double eRaT=error((fb->corr1+fb->corr2),(fb->icorr1+fb->icorr2));

    double eNom=error((fb->nom),(fb->inom));
    double eCtrl=error((fb->ctrl),(fb->ictrl));

    //    cout << "RaT = " << RaT << " +/- " << eRaT << endl;

    //    g1->SetPoint(i,nj,RaT); g1->SetPointError(i,0.,eRaT);
    
    g1->SetPoint(i,nj,(fb->ctrl/fb->ictrl)); g1->SetPointError(i,0.1,eCtrl);
    g3->SetPoint(i,nj,(fb->nom/fb->inom)); g3->SetPointError(i,0.1,eNom);

    i++;
  }

  setTDRStyle();

  TCanvas* can=new TCanvas("itest","");

  gPad->SetGridx(); gPad->SetGridy();
  gPad->SetLogy();

  TLegend *leg = new TLegend(.4,.8.5,.99,.99,"");
  leg->SetTextSize(0.033);
    leg->SetHeader("ele ID inversion anti-selection region");
    //leg->SetHeader("selection region");
      //"Control region (ele ID anti-selection)
  leg->AddEntry(g3,"data","P");
  leg->AddEntry(g1,"monte carlo (data-like)","P");
//  leg->AddEntry(g2,"predicted (W+QCD)","P");

  leg->SetFillColor(0);
  leg->SetLineColor(0);

  //  g2->GetHistogram()->GetXaxis()->SetRangeUser(-0.5,3.5);
  //g2->Draw("AP");
  //g1->SetTitle(";|#eta_{j1}| bin;RaT = #frac{N(aT>0.55)}{N(aT>0)}");
 g1->SetTitle(";H_{T} cut [GeV];RaT = f(#alpha_{T}>0.55)");
  g1->Draw("AP");

  //  g1->Fit("pol1","R","",50.,100.);
  g3->Draw("P");
  g1->GetYaxis()->SetRangeUser(0.0007,2.);
  g1->GetYaxis()->SetTitleOffset(0.75);
  //  g1->GetXaxis()->SetRangeUser(20.,140.);
  leg->Draw("SAME");
  can->SaveAs("Plots/"+file+"RaT_vs_"+variable+".png");

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

double GetMinimum(TH1D *h, Double_t first, Double_t last) {

  Int_t bin, binx;
  Int_t locm;
  Int_t xfirst  = h->GetXaxis()->FindBin(first); //fXaxis.GetFirst();
  Int_t xlast   = h->GetXaxis()->FindBin(last);//fXaxis.GetLast();

   Double_t minimum = 999.;
   Double_t value;
   locm = 0;
   for (binx=xfirst;binx<=xlast;binx++) {
     bin = h->GetBin(binx);
     value = h->GetBinContent(bin);
     if (value < minimum) {
       minimum = value;
       locm    = bin;

     }
   }
   
   
   return h->GetBinCenter(locm);
}
