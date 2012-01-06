/*********************************************************************************
*********************************************************************************/

#include <algorithm>
#include <TROOT.h>
#include <iostream>

using namespace std;

void AsymTemplateFit(int ieff=80, float lumi=33.7, int ptCut=25, int METCut=0, int wShape = 0,bool corr=false ,bool DATA=true)
{
  gROOT->SetBatch();
  gROOT->Reset();   
  gROOT->SetStyle("Plain");// #To set plain bkgds for slides
  gStyle->SetTitleBorderSize(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetLineWidth(0.25);
  gStyle->SetCanvasColor(0);//#Sets canvas colour white
  gStyle->SetLabelOffset(0.001);
  gStyle->SetLabelSize(0.05);
  gStyle->SetLabelSize(0.05,"Y");//#Y axis
  gStyle->SetTitleSize(0.04);
  gStyle->SetTitleW(0.7);
  gStyle->SetTitleH(0.07);
  gStyle->SetOptTitle(1);
  gStyle->SetAxisColor(1, "XYZ");
  gStyle->SetStripDecimals(true);
  gStyle->SetTickLength(0.03, "XYZ");
  gStyle->SetNdivisions(510, "XYZ");
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetLabelColor(1, "XYZ");
  gStyle->SetLabelFont(42, "XYZ");
  gStyle->SetLabelOffset(0.007, "XYZ");
  gStyle->SetLabelSize(0.04, "XYZ");
  gStyle->SetHatchesLineWidth(3);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1111);
  gSystem->Load("libRooFit") ;
  using namespace RooFit;

  TString ptStr;
  if (ptCut==25) {
    ptStr="";
  } else if (ptCut==30) {
    ptStr="_30";
  } else if (ptCut==35) {
    ptStr="_35";
  }
  else {
    cout << "ptCut (4th argument) must be 25, 30 or 35" << endl;
  }
 
  
  TString str_eff;
  if (ieff==60) str_eff="_WP60";
  else if (ieff==70) str_eff="_WP70";
  else if (ieff==80) str_eff="_WP80";
  else if (ieff==85) str_eff="_WP85";
  else if (ieff==90) str_eff="_WP90";
  else if (ieff==95) str_eff="_WP95";
  else {
    cout << "input argument (signal efficiency point) must be 60, 70, 80 ,85, 90 or 95" << endl;
    return;
  }
  TString TemplateLocation="./Templates/";

  TString DIR="Templates" + str_eff + "_Ele" + "25";//This will be changed
  
  float EWKfrac = 1.0;
   
  //wShape = 1 Silvia's MET recoil templates
  //wShape = 2 MIT Z recoil templates
  //wShape = 3 MIT recoil templates with eta corrections
  //wShape = 4 Silvia's Ersatz with eta corrections
  //wShape = 5 DW Ersatz with eta corrections
  bool bUseMETRecoil = false;
  bool bUseMITMETRecoil = false;
  bool bUseMITMETRecoilCorr = false;
  bool bUseErsatz = false; 
  //h_wpt_pfMETcor_wpt1_pos;     
  //EventSelection
  TString data_Ev="h_wpt_MT";
  TString Ev="h_wpt_MT";//corEB";
  TString AntiEv="h_wpt_anti_MT";//corEB";
  TString data_AntiEv="h_wpt_anti_MT";
  if (corr) {
    data_Ev+="cor";
    data_AntiEv+="cor";
  }
  
  //data_Ev+="EB";
  //data_AntiEv+="EB";
 
  
  TString Suffix=ptStr;
  TString SAVDIR="./";//"~/public/html/";
  TString FORMAT=".pdf";

  if (wShape == 1 ) {
    bUseMETRecoil = true;
    //SAVDIR=SAVDIR+"Sil_";
  }
  else if (wShape == 2 ){
    bUseMITMETRecoil = true;
    //SAVDIR=SAVDIR+"MIT_";
  }
  else if (wShape == 3 ) {
    bUseMITMETRecoilCorr = true;
    //SAVDIR=SAVDIR+"MITcor_";
  }
  else if (wShape == 4 )  bUseErsatz = true;
  
  TLegend *leg = new TLegend(0.1,0.1,0.3,0.3);

  TLegend *l5_2 = new TLegend(0.7,0.5,0.9,0.9);
  TLegend *l5_0 = new TLegend(0.7,0.5,0.9,0.9);
  TLegend *l5_1 = new TLegend(0.1,0.6,0.4,0.9);

  TLegend *l5_4 = new TLegend(0.7,0.7,0.9,0.9);
  TLegend *l5_3 = new TLegend(0.7,0.7,0.9,0.9);
  TLegend *l5_7 = new TLegend(0.7,0.7,0.9,0.9);
  
  int binMETCut = METCut/2+1;//ALERT WRONG!
  int nbins=25;
  int rebinFactor=4;
  const int WptBins = 9;
  TString Titles[WptBins*2]={"Positrons  0<P_{T}^{W}< 4GeV","Electrons  0<P_{T}^{W}< 4GeV",
			     "Positrons  4<P_{T}^{W}< 8GeV"   ,"Electrons  4<P_{T}^{W}< 8GeV",
			     "Positrons  8<P_{T}^{W}<12GeV"   ,"Electrons  8<P_{T}^{W}<12GeV",
                 "Positrons 12<P_{T}^{W}<16GeV"   ,"Electrons 12<P_{T}^{W}<16GeV",
                 "Positrons 16<P_{T}^{W}<24GeV"   ,"Electrons 16<P_{T}^{W}<24GeV",
                 "Positrons 24<P_{T}^{W}<50GeV"   ,"Electrons 24<P_{T}^{W}<50GeV",
                 "Positrons 50<P_{T}^{W}<75GeV"   ,"Electrons 50<P_{T}^{W}<75GeV",
                 "Positrons 75<P_{T}^{W}<100GeV"  ,"Electrons 75<P_{T}^{W}<100GeV",
                 "Positrons 100<P_{T}^{W}<inf GeV","Electrons 100<P_{T}^{W}<inf GeV"};
  
			     
   double wptx[WptBins] =  {2., 6.,10.,14.,20.,37.,62.5,87.5,125.};
   double wptxl[WptBins] = {2., 2., 2., 2., 4.,13.,12.5,12.5,25.0};
   double wptxh[WptBins] = {2., 2., 2., 2., 4.,13.,12.5,12.5,25.0};   
			       
  TFile *file[19];
  file[0] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_dataWPT.root");
  //file[1] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wenu.root");

  file[2] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdEm_20-30.root");
  file[3] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdEm_30-80.root");
  file[4] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdEm_80-170.root");
  file[5] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdBce20-30.root");
  file[6] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdBce30-80.root");
  file[7] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_qcdBce80-170.root");
  file[8] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_gj15-30.root");
  file[9] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_gj30-50.root");

  file[11] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wenuPlus.root");
  file[12] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wenuMinus.root");

  //file[14] = TFile::Open(TemplateLocation+"Templates_DYee_M1to10.root");
  file[15] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_dytautau.root");
  file[16] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_dyee.root");
  file[17] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_wtaunu.root");
  file[18] = TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_ttbar.root");
	
  TString bins[WptBins*2]={"_wpt1_pos","_wpt1_neg",
			   "_wpt2_pos","_wpt2_neg",
 			   "_wpt3_pos","_wpt3_neg",
               "_wpt4_pos","_wpt4_neg",
               "_wpt5_pos","_wpt5_neg",
               "_wpt6_pos","_wpt6_neg",
               "_wpt7_pos","_wpt7_neg",
               "_wpt8_pos","_wpt8_neg",
               "_wpt9_pos","_wpt9_neg"};

  TH1F* hh_data_sel[WptBins*2];  TH1F* hh_wenu_sel[WptBins*2];  TH1F* hh_ewk_sel[WptBins*2]; TH1F* hh_qcd_sel[WptBins*2];
  TH1F* hh_data_sel_antisel[WptBins*2];TH1F*  hh_bkg_sel_template[WptBins*2]; TH1F *hh_ewk_sel_fit[WptBins*2];
  TH1F* hh_wenu_sel_fit[WptBins*2];
  TH1F* hh_tot_sel_fit[WptBins*2];  TH1F* hh_wenuewk_sel[WptBins*2];TH1F* hh_bkg_sel_template_fit[WptBins*2];
  for (int ib=0; ib<WptBins*2;ib++){
    hh_data_sel[ib]= new TH1F("h_data_sel"+bins[ib], "data_sel"+bins[ib], 100,0.,150.);;
    hh_wenu_sel[ib]=new TH1F("h_wenu_sel"+bins[ib],"wenu_sel"+bins[ib],100,0.,150.);
    hh_ewk_sel[ib] = new TH1F("h_ewk_sel"+bins[ib],"ewk_sel"+bins[ib],100,0.,150.);
    hh_qcd_sel[ib] = new TH1F("h_qcd_sel"+bins[ib],"qcd_sel"+bins[ib],100,0.,150.);
    hh_data_sel_antisel[ib] = new TH1F("h_data_sel_antisel"+bins[ib], "data_sel_antisel"+bins[ib], 100,0.,150.);
    hh_bkg_sel_template[ib]  = new TH1F("h_bkg_sel_template"+bins[ib], "data_bkg_sel_template"+bins[ib], nbins,0.,150.);
    hh_wenu_sel_fit[ib] = new TH1F("h_wenu_fit"+bins[ib],"wenu_fit"+bins[ib],nbins,0.,150.);
    hh_ewk_sel_fit[ib] = new TH1F("h_ewk_fit"+bins[ib],"ewk_fit"+bins[ib],nbins,0.,150.);
    hh_bkg_sel_template_fit[ib] = new TH1F("h_bkg_template_fit"+bins[ib], "bkg_template_fit"+bins[ib], nbins,0.,150.);  
    hh_wenuewk_sel[ib] = new TH1F("h_wenuewk_sel"+bins[ib],"wenuewk_sel"+bins[ib],nbins,0.,150.);
    hh_tot_sel_fit[ib] = new TH1F("h_tot_sel_fit"+bins[ib],"tot_sel_fit"+bins[ib],nbins,0.,150.);
  }



  TCanvas *c0 = new TCanvas("c0","Canvas0",1680,1050);
  c0->Divide(4,5);
  c0->SetFillColor(10);

  TCanvas *c1 = new TCanvas("c1","Canvas1",1680,1050);
  c1->Divide(4,5);
  c1->SetFillColor(10);
  TCanvas *c2 = new TCanvas("c2","Canvas2");
  c2->SetFillColor(10);
  if (!DATA){
    TCanvas *c3 = new TCanvas("c3","Canvas3",1680,1050);
    c3->Divide(4,5);
  }

  TCanvas *c4 = new TCanvas("c4","Canvas4",1680,1050);
  c4->SetFillColor(10);
  c4->Divide(4,5);
  TCanvas *c5 = new TCanvas("c5","Canvas5");

  TH1D *POS=new TH1D("POS","POS",9,0,2.4);
  TH1D *NEG=new TH1D("NEG","NEG",9,0,2.4);
  TH1D *BPOS=new TH1D("BPOS","BPOS",9,0,2.4);
  TH1D *BNEG=new TH1D("BNEG","BNEG",9,0,2.4);


  TH1 *ASY;
   
  double w[19];
  //for (unsigned i=1; i<19; i++) w[i]=lumi;  //w[i]=(w[i]/10.)*lumi;
  w[0] = 1;
  w[1] = (1.0/345.966)*lumi;

  w[2] = (1.0/14.900)*lumi;
  w[3] = (1.0/17.810)*lumi;
  w[4] = (1.0/57.875)*lumi;
  w[5] = (1.0/16.975)*lumi;
  w[6] = (1.0/14.587)*lumi;
  w[7] = (1.0/111.473)*lumi;
  w[8] = (1.0/5.392)*lumi;
  w[9] = (1.0/61.443)*lumi;

  w[11] = (1.0/345.966)*lumi;
  w[12] = (1.0/506.271)*lumi;

  w[15] = (1.0/1176.095)*lumi;
  w[16] = (1.0/1238.53)*lumi;
  w[17] = (1.0/537.272)*lumi;
  w[18] = (1.0/10633.511)*lumi;
 
  //EWK XSEC UNC.
  for (unsigned i=15; i<19; i++) {
    w[i]*=EWKfrac;
  }

  TH1F *h1;

  for (int ib=0; ib<WptBins*2;ib++){
    
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;  
  cout<<"WPt Charge Bin:"<<Titles[ib]<<endl;  
  
    if (DATA){
      file[0]->cd(DIR);
      gDirectory->GetObject(data_Ev+bins[ib]+Suffix,h1);
 //    gDirectory->GetObject(Ev+bins[ib],h1);//(data_Ev+bins[ib],h1);
	  //h1->Rebin(2);
      hh_data_sel[ib]->Add(h1,1.0000);
      	

     int ib_even = (ib/2)*2; 
	int ib_odd = ib_even+1;
      gDirectory->GetObject(data_AntiEv+bins[ib_odd]+Suffix,h1);//
      hh_data_sel_antisel[ib]->Add(h1,1.0000);

      gDirectory->GetObject(data_AntiEv+bins[ib_even]+Suffix,h1);//
      hh_data_sel_antisel[ib]->Add(h1,1.0000);
    }
    else{
      for (unsigned i=2; i<19; i++) {
        //   why 2? I removed wenu and added combined sample
        if (i>9&&i<11) continue;	
        if (i>2&&i<15) continue;	
        file[i]->cd(DIR);
        gDirectory->GetObject(data_Ev+bins[ib]+Suffix,h1);
        hh_data_sel[ib]->Add(h1,w[i]);
        gDirectory->GetObject(AntiEv+bins[ib]+Suffix,h1);
        hh_data_sel_antisel[ib]->Add(h1,w[i]);	
      }
    }

    //Wenuplus and minus
    file[11]->cd(DIR);
    gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
    h1->Sumw2();
    hh_wenu_sel[ib]->Add(h1,w[11]);
    
    file[12]->cd(DIR);
    gDirectory->GetObject(Ev+bins[ib],h1);
    h1->Sumw2();
    hh_wenu_sel[ib]->Add(h1,w[12]);
    if (bUseMETRecoil) {
      cout<<"Using Silvia's MET Recoil W->e nu template shapes."<<endl;  
      TFile *Wenufile = TFile::Open(TemplateLocation+"Templates_Wenu_Silvia.root");//*******
      double nWenu = hh_wenu_sel[ib]->Integral();
      TString WenuDIR="Templates_00";
      hh_wenu_sel[ib]->Reset();				
      Wenufile->cd(WenuDIR);				
      gDirectory->GetObject("h_MC_sel"+bins[ib],h1);	//"h_corr"+bins[ib],h1);//
      //h1->Sumw2();
      h1->Rebin(2);//200 -> 100
      hh_wenu_sel[ib]->Add(h1,1.0*nWenu/(h1->Integral()));
    }
    else if (bUseMITMETRecoil) {
      cout<<"Using MIT's MET Recoil W->e nu template shapes."<<endl;  
      TFile *MITfile =  TFile::Open(TemplateLocation+"Templates_Wenu_dec22_20MET.root");
// Templates_Wenu.root
// Templates_Wenu_ResHigh.root
// Templates_Wenu_ResLow.root
// Templates_Wenu_ScaHigh.root
// Templates_Wenu_ScaLow.root

      //hh_wenu_sel[ib]->Rebin(rebinFactor/2);
      double nWenu = hh_wenu_sel[ib]->Integral();
      TString WenuDIR;
      if (ptCut==25) {
	WenuDIR="midTree25";
      } else if (ptCut==30) {
	WenuDIR="midTree30";
      } else if (ptCut==35) {
	WenuDIR="midTree35";
      }
      hh_wenu_sel[ib]->Reset();				
      MITfile->cd(WenuDIR);				
      gDirectory->GetObject("h_wpt_MT"+bins[ib],h1);
      //gDirectory->GetObject("h_wpt"+bins[ib],h1);	
      //h1->Sumw2();
      hh_wenu_sel[ib]->Add(h1,1.*nWenu/(h1->Integral()));	
    }
    else if (bUseMITMETRecoilCorr) {
      cout<<"Using MIT template shapes (with eta binning fudge factor)"<<endl;   
      TFile *MITfile =  TFile::Open(TemplateLocation+"Templates_Wenu_MITCorrected.root");
      //hh_wenu_sel[ib]->Rebin(rebinFactor/2);
      double nWenu = hh_wenu_sel[ib]->Integral();
      TString WenuDIR="corr";
      hh_wenu_sel[ib]->Reset();				
      MITfile->cd(WenuDIR);				
      gDirectory->GetObject("h_corr"+bins[ib],h1);	
      //h1->Sumw2();
      hh_wenu_sel[ib]->Add(h1,1.001*nWenu/(h1->Integral()));	
    }
    else if (bUseErsatz) {
      cout<<"ERROR: NOT UPDATED YET."<<endl;    
      return;
    }
    for (unsigned i=15; i<19; i++) {
      file[i]->cd(DIR);
      gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
      h1->Sumw2();  
      hh_ewk_sel[ib]->Add(h1,w[i]);
    }
    for (unsigned i=2; i<10; i++) {
      file[i]->cd(DIR);
      gDirectory->GetObject(Ev+bins[ib],h1);
      h1->Sumw2();  
      hh_qcd_sel[ib]->Add(h1,w[i]);
    }

    hh_data_sel[ib]->Rebin(rebinFactor);
    hh_ewk_sel[ib]->Rebin(rebinFactor);
    hh_qcd_sel[ib]->Rebin(rebinFactor);
    hh_wenu_sel[ib]->Rebin(rebinFactor);
    hh_data_sel_antisel[ib]->Rebin(rebinFactor);
    
    // & $0.0<| \eta |<0.4$  & 13791 & 4127 & 18138\\ 
    // Integral(Int_t binx1, Int_t binx2, Option_t* option = "") const
//    cout<<"Using range: "<<hh_wenu_sel[ib]->GetXaxis()->GetBinLowEdge(binMETCut)<<" to " <<hh_wenu_sel[ib]->GetXaxis()->GetBinUpEdge(nbins)<<endl;
	cout<<"Selected Events = "<<hh_data_sel[ib]->Integral(binMETCut,nbins)<<endl;

	cout<<"Wenu Shape = "<<hh_wenu_sel[ib]->Integral(binMETCut,nbins)<<endl;
	cout<<"QCD Shape = "<<hh_qcd_sel[ib]->Integral(binMETCut,nbins)<<endl;
	cout<<"EWK Shape = "<<hh_ewk_sel[ib]->Integral(binMETCut,nbins)<<endl;
	cout<<"QCD AS shape = "<<hh_data_sel_antisel[ib]->Integral(binMETCut,nbins)<<endl;

  double QCDExpected = hh_qcd_sel[ib]->Integral(0,nbins);
  double EWKExpected = hh_ewk_sel[ib]->Integral(0,nbins)+hh_wenu_sel[ib]->Integral(0,nbins);

    hh_wenuewk_sel[ib]->Add(hh_wenu_sel[ib]);
    hh_wenuewk_sel[ib]->Add(hh_ewk_sel[ib]);
    hh_bkg_sel_template[ib]->Add(hh_data_sel_antisel[ib]);

RooRealVar pfMET("pfMET","pfMET",0.,150.);
    RooRealVar fsig("fsig","signal fraction",0.5,0.,1.);

    TH1*  hhhh_wenuewk_sel = (TH1*)hh_wenuewk_sel[ib]->Clone();
    TH1*  hhhh_bkg_sel_template =(TH1*)hh_bkg_sel_template[ib]->Clone();
    TH1*  hhhh_data_sel =(TH1*)hh_data_sel[ib]->Clone();
    
    RooDataHist roohist_wenuewk_sel("roohist_wenuewk_sel","wenuewk with pfMET",pfMET,hhhh_wenuewk_sel);
    RooDataHist roohist_bkg_sel_template("roohist_bkg_sel_template","bkg_template with pfMET",pfMET,hhhh_bkg_sel_template);
    RooHistPdf pdf_wenuewk_sel("pdf_wenuewk_sel","wenuewk with pfMET",RooArgList(pfMET),roohist_wenuewk_sel);
    RooHistPdf pdf_bkg_sel_template("pdf_bkg_sel_template","bkg_template with pfMET",RooArgList(pfMET),roohist_bkg_sel_template);
    RooDataHist roohist_data_sel("roohist_data_sel","data with pfMET",pfMET,hhhh_data_sel);
 
    RooRealVar nsig("nsig","signal fraction"    ,EWKExpected,0.,100000.);
    RooRealVar nbkg("nbkg","background fraction",QCDExpected,0.,100000.);  
    RooAddPdf model_sel("model_sel","model_sel",RooArgList(pdf_wenuewk_sel,pdf_bkg_sel_template),RooArgList(nsig,nbkg));
    model_sel.fitTo(roohist_data_sel,SumW2Error(kFALSE),InitialHesse(kFALSE),Extended(kTRUE),PrintLevel(-2),Verbose(0)); //InitialHesse(kTRUE)
    
    double nwenuewk_fit = nsig.getVal();
    double nwenuewk_fit_err = nsig.getError();
    double relSigErr=nwenuewk_fit_err/nwenuewk_fit;

    double nbkg_fit = nbkg.getVal();
    double nbkg_fit_err = nbkg.getError();
    double relBkgErr=nbkg_fit_err/nbkg_fit;

    //ROOFIT PLOT
    c0->cd(ib+1);
    RooPlot* xframe =  pfMET.frame();
    roohist_data_sel.plotOn(xframe,  MarkerColor(kBlack));
    model_sel.plotOn(xframe, Name("model_sel"), DrawOption("L"));
    xframe->Draw();

    double ScaleBkg= nbkg_fit/hh_bkg_sel_template[ib]->Integral();
    double ScaleSignal=nwenuewk_fit/hhhh_wenuewk_sel->Integral();
    double relfrac_wenu=hh_wenu_sel[ib]->Integral()/hhhh_wenuewk_sel->Integral();

    hh_wenu_sel_fit[ib]->Reset();
    hh_wenu_sel_fit[ib]->Add(hh_wenu_sel[ib]);
    hh_ewk_sel_fit[ib]->Reset();
    hh_ewk_sel_fit[ib]->Add(hh_ewk_sel[ib]);
    hh_bkg_sel_template_fit[ib]->Reset();
    hh_bkg_sel_template_fit[ib]->Add(hh_bkg_sel_template[ib]);

    hh_wenu_sel_fit[ib]->Scale(ScaleSignal);
    hh_ewk_sel_fit[ib]->Scale(ScaleSignal);
    hh_bkg_sel_template_fit[ib]->Scale(ScaleBkg);

    float NSignal =hh_wenu_sel_fit[ib]->Integral(binMETCut,nbins);//nwenuewk_fit*relfrac_wenu;
    float NBackground =hh_bkg_sel_template_fit[ib]->Integral(binMETCut,nbins) + hh_ewk_sel_fit[ib]->Integral(binMETCut,nbins);//nbkg_fit+(nwenuewk_fit*(1-relfrac_wenu));

	cout<<hh_bkg_sel_template_fit[ib]->Integral(binMETCut,nbins)<<endl; 
 
    if (ib==0)POS->SetBinContent(1,NSignal);
    if (ib==1)NEG->SetBinContent(1,NSignal);  
    if (ib==2)POS->SetBinContent(2,NSignal);
    if (ib==3)NEG->SetBinContent(2,NSignal); 
    if (ib==4)POS->SetBinContent(3,NSignal);
    if (ib==5)NEG->SetBinContent(3,NSignal);    
    if (ib==6)POS->SetBinContent(4,NSignal);
    if (ib==7)NEG->SetBinContent(4,NSignal);  
    if (ib==8)POS->SetBinContent(5,NSignal);
    if (ib==9)NEG->SetBinContent(5,NSignal); 
    if (ib==10)POS->SetBinContent(6,NSignal);
    if (ib==11)NEG->SetBinContent(6,NSignal);
    
    if (ib==12)POS->SetBinContent(7,NSignal);
    if (ib==13)NEG->SetBinContent(7,NSignal);  
    if (ib==14)POS->SetBinContent(8,NSignal);
    if (ib==15)NEG->SetBinContent(8,NSignal); 
    if (ib==16)POS->SetBinContent(9,NSignal);
    if (ib==17)NEG->SetBinContent(9,NSignal);   
    
    
    
    if (ib==0)POS->SetBinError(1,NSignal*relSigErr);
    if (ib==1)NEG->SetBinError(1,NSignal*relSigErr);  
    if (ib==2)POS->SetBinError(2,NSignal*relSigErr);
    if (ib==3)NEG->SetBinError(2,NSignal*relSigErr); 
    if (ib==4)POS->SetBinError(3,NSignal*relSigErr);
    if (ib==5)NEG->SetBinError(3,NSignal*relSigErr);    
    if (ib==6)POS->SetBinError(4,NSignal*relSigErr);
    if (ib==7)NEG->SetBinError(4,NSignal*relSigErr);  
    if (ib==8)POS->SetBinError(5,NSignal*relSigErr);
    if (ib==9)NEG->SetBinError(5,NSignal*relSigErr); 
    if (ib==10)POS->SetBinError(6,NSignal*relSigErr);
    if (ib==11)NEG->SetBinError(6,NSignal*relSigErr);    

    if (ib==12)POS->SetBinError(7,NSignal*relSigErr);
    if (ib==13)NEG->SetBinError(7,NSignal*relSigErr);  
    if (ib==14)POS->SetBinError(8,NSignal*relSigErr);
    if (ib==15)NEG->SetBinError(8,NSignal*relSigErr); 
    if (ib==16)POS->SetBinError(9,NSignal*relSigErr);
    if (ib==17)NEG->SetBinError(9,NSignal*relSigErr);    
    
    
    //cout << endl;
    cout << "NSignal = " << NSignal << endl;
    cout << "NBackground = " << NBackground << endl;

    c1->cd(ib+1);
    hh_data_sel[ib]->SetMarkerSize(.01);
    hh_data_sel[ib]->SetMarkerStyle(20);
    
    hh_wenu_sel_fit[ib]->SetFillColor(42);
    hh_ewk_sel_fit[ib]->SetFillColor(45);
    hh_bkg_sel_template_fit[ib]->SetFillColor(9);
    
    hh_wenu_sel_fit[ib]->SetLineWidth(0.25);
    hh_ewk_sel_fit[ib]->SetLineWidth(0.25);
    hh_bkg_sel_template_fit[ib]->SetLineWidth(0.25);
    
    
    THStack *h_back_sel_fit = new THStack("h_back_sel_fit","Fit: " + Titles[ib]); 
    
    h_back_sel_fit->Add(hh_bkg_sel_template_fit[ib]); 
    h_back_sel_fit->Add(hh_ewk_sel_fit[ib]);
    h_back_sel_fit->Add(hh_wenu_sel_fit[ib]);
    
    hh_tot_sel_fit[ib]->Reset();
    hh_tot_sel_fit[ib]->Add(hh_ewk_sel_fit[ib]);
    hh_tot_sel_fit[ib]->Add(hh_bkg_sel_template_fit[ib]);
    hh_tot_sel_fit[ib]->Add(hh_wenu_sel_fit[ib]);
    hh_tot_sel_fit[ib]->SetLineStyle(2);
    hh_tot_sel_fit[ib]->SetLineColor(3);
    hh_data_sel[ib]->SetMinimum(0);

    hh_data_sel[ib]->SetTitle(Titles[ib]);
    //hh_data_sel[ib]->GetYaxis()->SetTitleOffset(0.4);
    //hh_data_sel[ib]->GetYaxis()->SetTitleSize(0.1);
    //hh_data_sel[ib]->GetXaxis()->SetTitleOffset(0.5);
    //hh_data_sel[ib]->GetXaxis()->SetTitleSize(0.1);
    //hh_data_sel[ib]->GetXaxis()->SetLabelSize(.06);
    //hh_data_sel[ib]->GetYaxis()->SetLabelSize(.06);


    hh_data_sel[ib]->GetXaxis()->SetRange(0,150);
    hh_data_sel[ib]->GetXaxis()->SetTitle("PFMet (GeV)");
    hh_data_sel[ib]->GetYaxis()->SetTitle("Events/2 GeV");
    h_back_sel_fit->Draw("hist");
    hh_data_sel[ib]->Draw("e same");

    for (int j=1;j<nbins+1;j++) {
      float dcomp=(hh_wenuewk_sel[ib]->GetBinContent(j)>0)?	hh_wenuewk_sel[ib]->GetBinError(j)/hh_wenuewk_sel[ib]->GetBinContent(j):0;
      float drelSig=sqrt(relSigErr*relSigErr+dcomp*dcomp);
      float dSig=hh_wenuewk_sel[ib]->GetBinContent(j)*ScaleSignal*drelSig;
      
      float dcomp=(hh_bkg_sel_template[ib]->GetBinContent(j)>0.)?hh_bkg_sel_template[ib]->GetBinError(j)/hh_bkg_sel_template[ib]->GetBinContent(j):0.;
      float drelBkg=sqrt(relBkgErr*relBkgErr+dcomp*dcomp);
      float dBkg=drelBkg*ScaleBkg*hh_bkg_sel_template[ib]->GetBinError(j);
      float ErrTot=sqrt(dSig*dSig+dBkg*dBkg);
      hh_tot_sel_fit[ib]->SetBinError(j,ErrTot);
    }
    //Double_t chi2ndof = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"CHI2/NDF");
   // Double_t chi2ndofUW = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"UW CHI2/NDF");
  //  Double_t chi2 = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"CHI2"); 
//    Double_t chi2UW = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"UW CHI2"); 
   // cout<<"CHI2 "<<chi2<<"CHI2NDOF "<<chi2ndof<<endl;
   // cout<<"CHI2 "<<chi2UW<<"CHI2NDOF "<<chi2ndofUW<<endl;
  
    if (ib==0){
      l5_2->AddEntry(hh_data_sel[ib],"data","p");
      l5_2->AddEntry(hh_bkg_sel_template_fit[ib],"QCD","F");
      l5_2->AddEntry(hh_wenu_sel_fit[ib],"Signal","F");
      l5_2->AddEntry(hh_ewk_sel_fit[ib],"EWK","F");
      //l5_2->AddEntry(hh_tot_sel_fit[ib],"Fit","l");

      l5_2->Draw();
    }
    //MICHELE
    c4->cd(ib+1);
    //c5->cd();
    
    TH1 *jgg= new TH1F("h_data_selj"+bins[ib], bins[ib], nbins,0.,150.);
    TH1 *agg= (TH1*)hh_data_sel[ib]->Clone();
    TH1 *bgg= (TH1*)hh_tot_sel_fit[ib]->Clone();
    
    jgg->SetTitle(Titles[ib]);
    jgg->Divide(agg,bgg,1,1);
    jgg->SetMarkerStyle(20);
    jgg->SetMarkerSize(0.3); 
    jgg->SetMarkerColor(1);
    jgg->SetLineColor(1);
    jgg->SetMinimum(0.4);
    jgg->SetMaximum(2.4);
    jgg->Draw("pe");
    TLine* line=new TLine(0.0, 1.0 , 150, 1.0);
    line->SetLineColor(2);
    line->Draw("same");
    //
    if (!DATA){
      c3->cd(ib+1); 
      hh_data_sel[ib]->SetMaximum(50);
      hh_data_sel[ib]->SetMinimum(0);
      hh_data_sel[ib]->SetFillColor(3);
      hh_data_sel[ib]->Draw();
      TH1F* cici=(TH1F*)hh_data_sel[ib]->Clone();
      cici->Add(hh_wenu_sel[ib],-1);
      cici->SetFillColor(2); 
      cici->Draw("same"); 
      TH1F* cucu=(TH1F*)cici->Clone();
      cucu->Add(hh_ewk_sel[ib],-1);
      cucu->SetFillColor(5);
      cucu->Draw("same");

      if (ib==2){
        l5_0->AddEntry(hh_data_sel[ib],"W->e#nu","f");
        l5_0->AddEntry(cici,"EWK","f");
        l5_0->AddEntry(cucu,"QCD","f");
        l5_0->Draw();
      }
    }
   // if (ib==1)return;
  }
  ASY=POS->GetAsymmetry(NEG);
//   int SystCont=4;
//   float systPos[6][4];
//   float systNeg[6][4];
//   cout<<"SW "<<endl;
//   for (int ibin=0;ibin<5;ibin++){
//     for (int icon=0;icon<SystCont;icon++){
//       systPos[ibin][icon]=0.;
//       systNeg[ibin][icon]=0.;
//     }   	
//   }  

  double ay[WptBins]   = {0., 0., 0., 0., 0., 0.,0., 0., 0.};
//   double ry[WptBins]   = {0., 0., 0., 0., 0., 0.,0., 0., 0.};
  
  double aeyl[WptBins] = {0., 0., 0., 0., 0., 0.,0., 0., 0.};
  double aeyh[WptBins] = {0., 0., 0., 0., 0., 0.,0., 0., 0.};

   for (int ibi=0; ibi<WptBins;ibi++){
     ay[ibi] = ASY->GetBinContent(ibi+1);//change this for ratio?
     
//      ry[ibi] = (1.0+ASY->GetBinContent(ibi+1))/(1.0-ASY->GetBinContent(ibi+1));//change this for ratio?*/

     aeyl[ibi] = ASY->GetBinError(ibi+1);
     aeyh[ibi] = ASY->GetBinError(ibi+1);
   }

//  double ry[WptBins]   = {0.233157816815765,0.223996856283436,0.218439314887388,0.210635311334461,0.208599878845735,0.198268682664968,0.186176739529352,0.185410335168024,0.196651778327579};
//  double reyl[WptBins]   = {0.00430114287339364,0.00385497704660828,0.00329297047924779,0.00299294956212057,0.00382465262895459,0.00362071980481834,0.00560532710682413,0.00401188465481522,0.00613320370350767};
//  double reyh[WptBins]   = {0.00420165427679445,0.00418084018641401,0.00332858396734528,0.00436045647720129,0.00308712913273093,0.00312491922984706,0.0040285775112805,0.0042876639176414,0.00602556713344604};
//
//double ry[WptBins]   = {0.152787622730895,0.15366900223939,0.164049439419587,0.172431745714599,0.188591642741219,0.204287042123941,0.236060348608048,0.262562572083107,0.273842668933397};
//double reyl[WptBins]   = {0.00353987031582537,0.00387580062806192,0.00307576685951338,0.00382081579937984,0.00334948603363827,0.00330894029862544,0.00699239066142482,0.00472197982924294,0.00562142780155267};
//double reyh[WptBins]   = {0.00549734092678569,0.00463375057634646,0.00357186798320128,0.00356758788121936,0.00451416212552019,0.00403713006644027,0.00593895786802809,0.00643170263893889,0.0059835824601378};
//25GeV 0MET 0.8eta
//double ry[WptBins] ={0.219070381244666,0.209965915380997,0.205676162803496,0.198822826825128,0.1958868373142,0.188627202270829,0.179066432476957,0.181199694725622,0.188161168228022};
//double reyl[WptBins]={0.00437706296257656,0.00399309317173779,0.00382777106029311,0.00416866246660366,0.00333322862245317,0.00255174891591794,0.00401399491193966,0.00360096236915117,0.00491455791972928};
//double reyh[WptBins]={0.00383722067451722,0.00407093654214569,0.00332013014444346,0.00308703125872217,0.00336339944205219,0.00316750022817938,0.00476800279838155,0.00487151073484315,0.00468368267987196};
//

//25GeV 20MET
  const int nTheory =50;
  double ry[nTheory]   = {0.2239,0.2076,0.2067,0.2053,0.2046,0.2040,0.2023,0.2005,0.1990,0.1978,0.1963,0.1936,0.1923,0.1893,0.1870,0.1874,0.1811,0.1822,0.1785,0.1762,0.1711,0.1675,0.1688,0.1632,0.1623,0.1581,0.1602,0.1567,0.1559,0.1529,0.1504,0.1490,0.1518,0.1450,0.1461,0.1458,0.1449,0.1413,0.1457,0.1473,0.1495,0.1423,0.1438,0.1498,0.1445,0.1478,0.1451,0.1475,0.1461,0.1487};
  double reyl[nTheory]   = {0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
  double reyh[nTheory]   = {0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
  double rx[nTheory]   = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,63,65,67,69,71,73,75,77,79,81,83,85,87,89,91,93,95,97,99};
  double rex[nTheory]   = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//25GeV 20 MET eta > 0.8 
// double ry[WptBins]   = {};
//  double reyl[WptBins]   = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};
//  double reyh[WptBins]   = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};

   TGraphAsymmErrors* asyGraph = new TGraphAsymmErrors(WptBins, wptx, ay, wptxl, wptxh, aeyl, aeyh);
   asyGraph->SetMarkerStyle(20);
   asyGraph->SetMarkerColor(1);
   
   
   TGraphAsymmErrors* theoGraph = new TGraphAsymmErrors(nTheory, rx, ry, rex, rex, reyl, reyh);
   //theoGraph->SetMarkerStyle(21);
   theoGraph->SetMarkerColor(2);
   theoGraph->SetLineColor(2);
   

   
   c2->cd();
   asyGraph->GetXaxis()->SetTitle("Wpt bins");
   asyGraph->GetYaxis()->SetTitle("Asymmetry");
   asyGraph->SetTitle("Electron Charge Asymmetry");
   
   asyGraph->SetLineColor(1);
   asyGraph->SetMarkerStyle(20);
   asyGraph->SetMinimum(-0.0);
   asyGraph->SetMaximum(+0.5); 
  
      leg->AddEntry(asyGraph,"Asymmetry","lp");
      leg->AddEntry(theoGraph,"CTEQ10W (MCFM)","lp");
      //l5_2->AddEntry(hh_tot_sel_fit[ib],"Fit","l");


   
   TMultiGraph *mg = new TMultiGraph;
   mg->SetTitle("Asymmetry;W P_{T}; ");
   mg->Add(asyGraph,"p");
   mg->Add(theoGraph,"CX");
   mg->SetMinimum(-0.0);
   mg->SetMaximum(+0.5); 
   mg->Draw("ap");
         leg->Draw();

  //mg->GetXaxis()->SetLimits(0.0,0.5);
  ///gPad->Modified();


  //c2->Update();


   //asyGraph->Draw("ap");
   
//   c2->cd();
// 
//   ASY->GetXaxis()->SetTitle("Wpt bins");
//   ASY->GetYaxis()->SetTitle("Asymmetry");
//   ASY->SetTitle("Electron Charge Asymmetry");
//   ASY->SetMarkerColor(1); 
//   ASY->SetLineColor(1); 
//   ASY->SetMarkerStyle(20);
//   ASY->SetMarkerColor(1);
//   ASY->SetLineColor(1);
//   ASY->SetMarkerStyle(20);
//   ASY->SetMinimum(-0.0);
//   ASY->SetMaximum(+0.5); 
//   
//   ASY->Draw();
  
  
  for (int ibi=0; ibi<WptBins;ibi++){
	cout<<"BIN "<<ibi+1<<" "<<int(10000*ASY->GetBinContent(ibi+1))/10000.<<" +/- "
	<<int(10000.*ASY->GetBinError(ibi+1))/10000.<<" (stat) "<<endl;
//	<<int(10000.*totsystmax[ibi])/10000.<<" - " 
//	<<int(10000.*totsystmin[ibi])/10000.<<endl;
  }
		
  l5_4->AddEntry(ASY,"Only Statistical","l");
//  l5_4->AddEntry(ASYSYST,"Stat. + Syst. error","l");
  
  if (DATA) {
    //l5_4->Draw("same");
    c2->SaveAs(SAVDIR+"asy"+FORMAT);
    c1->SaveAs(SAVDIR+"data"+FORMAT);
  }
  if(!DATA){
    l5_4->Draw("same");
    c2->SaveAs(SAVDIR+"final"+FORMAT);
    c3->SaveAs(SAVDIR+"PfMETbins"+FORMAT); 
  }
  c4->SaveAs(SAVDIR+"fitratio"+FORMAT);
  c0->SaveAs(SAVDIR+"roofit"+FORMAT);
  //exit(0);
 // while(true){};//return;
}


int  main () {
  AsymTemplateFit(80, 36, 25, 0,  0,false ,true)
  return 0;
}
