#include <algorithm>
void AsymTemplateFit()
{
  // Previous options. mostly redundant
  float lumi=869.; 
  int METCut=0; 
  bool DATA=true;

  //Current options to affect the fitting
  //float EWKfrac = 0.01; //Can use this to scale EWK or turn it off completely
  float EWKfrac = 1.0; //Can use this to scale EWK or turn it off completely
  bool corSigCon =false; //true;// true;   
  bool madgraph =true; // Use madgraph samples instead of pythia
  bool debug =false; // Extra information on the fit results
  TString pdf = "00";


  SetPlottingStyle();
  gSystem->Load("libRooFit") ;
  using namespace RooFit;


  //Template Names and Location
  TString TemplateLocation="./Templates/";
  TString tfile_dir="Default_Asym";
  TString data_Ev="h_eta_pfMET";
  TString data_AntiEv="h_eta_anti_pfMET";
  TString Ev="h_eta_pfMET";
  TString AntiEv="h_eta_anti_pfMET";
  TString Suffix="";

  // Output 
  TString output_dir="./";//"~/public/html/";
  TString FORMAT=".pdf";


  // Histograms and Legends setup 
  TLegend *l5_2 = new TLegend(0.7,0.5,0.9,0.9);
  TLegend *l5_0 = new TLegend(0.7,0.5,0.9,0.9);
  TLegend *l5_1 = new TLegend(0.1,0.6,0.4,0.9);
  TLegend *l5_4 = new TLegend(0.7,0.1,0.9,0.3);
  TLegend *l5_3 = new TLegend(0.7,0.7,0.9,0.9);
  TLegend *l5_7 = new TLegend(0.7,0.7,0.9,0.9);

  // Asymmetry Binning
  int binMETCut = METCut/2+1;
  int nbins=50;
  int rebinFactor=2;
  double x[] =  {0.1,0.3,0.5,0.7,0.9,1.1,1.3,1.7,1.9,2.1,2.3};
  double ex[] = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};

  // Eta Bin Titles and names
  TString Titles[22]={
    "Positrons |#eta|<0.2"    ,"Electrons |#eta|<0.2"    ,
    "Positrons 0.2<|#eta|<0.4","Electrons 0.2<|#eta|<0.4",
    "Positrons 0.4<|#eta|<0.6","Electrons 0.4<|#eta|<0.6",
    "Positrons 0.6<|#eta|<0.8","Electrons 0.6<|#eta|<0.8",
    "Positrons 0.8<|#eta|<1.0","Electrons 0.8<|#eta|<1.0",
    "Positrons 1.0<|#eta|<1.2","Electrons 1.0<|#eta|<1.2",
    "Positrons 1.2<|#eta|<1.4","Electrons 1.2<|#eta|<1.4",
    "Positrons 1.6<|#eta|<1.8","Electrons 1.6<|#eta|<1.8",
    "Positrons 1.8<|#eta|<2.0","Electrons 1.8<|#eta|<2.0",
    "Positrons 2.0<|#eta|<2.2","Electrons 2.0<|#eta|<2.2",
    "Positrons 2.2<|#eta|<2.4","Electrons 2.2<|#eta|<2.4"};
  TString bins[22]={"_eta1_pos","_eta1_neg",
    "_eta2_pos","_eta2_neg",
    "_eta3_pos","_eta3_neg",
    "_eta4_pos","_eta4_neg",
    "_eta5_pos","_eta5_neg",
    "_eta6_pos","_eta6_neg",
    "_eta7_pos","_eta7_neg",
    "_eta8_pos","_eta8_neg",
    "_eta9_pos","_eta9_neg",
    "_eta10_pos","_eta10_neg",
    "_eta11_pos","_eta11_neg"};

  // Open Template Files
  TFile *file[19];
  //Data
  file[0] = TFile::Open(TemplateLocation+"Templates_SingleElectron_Run2011A.root");
  //QCD MC
  file[2]=TFile::Open(TemplateLocation+"Templates_QCD_EM20to30.root");
  file[3]=TFile::Open(TemplateLocation+"Templates_QCD_EM30to80.root");
  file[4]=TFile::Open(TemplateLocation+"Templates_QCD_EM80to170.root");
  file[5]=TFile::Open(TemplateLocation+"Templates_QCD_BC20to30.root");
  file[6]=TFile::Open(TemplateLocation+"Templates_QCD_BC30to80.root");
  file[7]=TFile::Open(TemplateLocation+"Templates_QCD_BC80to170.root");
  file[8]=TFile::Open(TemplateLocation+"Templates_Gjet_50to80.root");
  //file[9]=TFile::Open(TemplateLocation+"ResultsWENU_VBTFpreselection_gj30-50.root");

  // These tempaltes were generated with CTEQ
  //file[11] = TFile::Open(TemplateLocation+"Template_wm_lhc7_ct66_"+pdf+".root");
  //file[12] = TFile::Open(TemplateLocation+"Template_wp_lhc7_ct66_"+pdf+".root");

  //EWK and Signal
  if (madgraph){
    file[1]=TFile::Open(TemplateLocation+"Templates_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1.root");
    file[16]=TFile::Open(TemplateLocation+"Templates_DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root");
    file[18]=TFile::Open(TemplateLocation+"Templates_TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1.root");
  }
  else{
    file[1]=TFile::Open(TemplateLocation+"Templates_WToENu_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2.root");
    file[15]=TFile::Open(TemplateLocation+"Templates_DYToTauTau_M_20_TuneZ2_7TeV_pythia6_tauola_Spring11_PU_S1_START311_V1G1_v1.root");
    file[16]=TFile::Open(TemplateLocation+"Templates_DYToEE_M_20_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root");
    file[17]=TFile::Open(TemplateLocation+"Templates_WToTauNu_TuneZ2_7TeV_pythia6_tauola_Summer11_PU_S3_START42_V11_v2.root");
    file[18]=TFile::Open(TemplateLocation+"Templates_TT_TuneZ2_7TeV_pythia6_tauola_Summer11_PU_S3_START42_V11_v2.root");
  }

  // MANY HISTOGRAMS! TODO simplify the naming
  TH1F* hh_data_sel[22];  
  TH1F* hh_wenu_sel[22];  
  TH1F* hh_ewk_sel[22]; 
  TH1F* hh_qcd_sel[22];

  TH1F* hh_dytautau_sel[22];
  TH1F* hh_dyee_sel[22];
  TH1F* hh_wtaunu_sel[22];
  TH1F* hh_ttbar_sel[22];  

  TH1F* hh_data_sel_antisel[22];
  TH1F* hh_bkg_sel_template[22]; 
  TH1F* hh_ewk_sel_fit[22];
  TH1F* hh_wenu_sel_fit[22];
  TH1F* hh_tot_sel_fit[22];  
  TH1F* hh_wenuewk_sel[22];
  TH1F* hh_bkg_sel_template_fit[22];

  //Signal contamination histograms
  float NTP_con[4];
  float NTP_sig[4];
  TString ecalbin[4]={"_EB_pos","_EB_neg","_EE_pos","_EE_neg"};

  // create histograms
  for (int ib=0; ib<22;ib++){
    hh_data_sel[ib]= new TH1F("h_data_sel"+bins[ib], "data_sel"+bins[ib], 100,0.,100.);;
    hh_wenu_sel[ib]=new TH1F("h_wenu_sel"+bins[ib],"wenu_sel"+bins[ib],100,0.,100.);
    hh_ewk_sel[ib] = new TH1F("h_ewk_sel"+bins[ib],"ewk_sel"+bins[ib],100,0.,100.);
    hh_qcd_sel[ib] = new TH1F("h_qcd_sel"+bins[ib],"qcd_sel"+bins[ib],100,0.,100.);
    hh_data_sel_antisel[ib] = new TH1F("h_data_sel_antisel"+bins[ib], "data_sel_antisel"+bins[ib], 100,0.,100.);
    hh_bkg_sel_template[ib]  = new TH1F("h_bkg_sel_template"+bins[ib], "data_bkg_sel_template"+bins[ib], nbins,0.,100.);
    hh_wenu_sel_fit[ib] = new TH1F("h_wenu_fit"+bins[ib],"wenu_fit"+bins[ib],nbins,0.,100.);
    hh_ewk_sel_fit[ib] = new TH1F("h_ewk_fit"+bins[ib],"ewk_fit"+bins[ib],nbins,0.,100.);
    hh_bkg_sel_template_fit[ib] = new TH1F("h_bkg_template_fit"+bins[ib], "bkg_template_fit"+bins[ib], nbins,0.,100.);  
    hh_wenuewk_sel[ib] = new TH1F("h_wenuewk_sel"+bins[ib],"wenuewk_sel"+bins[ib],nbins,0.,100.);
    hh_tot_sel_fit[ib] = new TH1F("h_tot_sel_fit"+bins[ib],"tot_sel_fit"+bins[ib],nbins,0.,100.);

    hh_dytautau_sel[ib] = new TH1F("h_dytautau_sel"+bins[ib],"h_dytautau_sel"+bins[ib],100,0.,100.);
    hh_dyee_sel[ib] = new TH1F("h_dyee_sel"+bins[ib],"h_dyee_sel"+bins[ib],100,0.,100.);
    hh_wtaunu_sel[ib] = new TH1F("h_wtaunu_sel"+bins[ib],"h_wtaunu_sel"+bins[ib],100,0.,100.);
    hh_ttbar_sel[ib] = new TH1F("h_ttbar_sel"+bins[ib],"h_ttbar_sel"+bins[ib],100,0.,100.);
  }

  // Various TCanvases for plots TODO more useful naming
  TCanvas *c6 = new TCanvas("c6","Canvas6",1680,1050);
  c6->Divide(2,1);
  c6->SetFillColor(10);
  TCanvas *c_roofit = new TCanvas("c_roofit","roofit",1680,1050);
  c_roofit->Divide(6,4);
  c_roofit->SetFillColor(10);

  TCanvas *c1 = new TCanvas("c1","Canvas1",1680,1050);
  c1->Divide(6,4);
  c1->SetFillColor(10);
  TCanvas *c2 = new TCanvas("c2","Canvas2");
  c2->SetFillColor(10);

  TCanvas *c_fit[11];
  for (int ib=0 ; ib<11 ; ib++){
      c_fit[ib] = new TCanvas("c_fit"+bins[ib*2],"fit",800,400);
      c_fit[ib]->Divide(2,1);
      c_fit[ib]->SetFillColor(10);
  }

  TCanvas *c_syst[11];
  for (int ib=0 ; ib<11 ; ib++){
      c_syst[ib] = new TCanvas("c_syst"+bins[ib*2],"syst",800,400);
      c_syst[ib]->Divide(2,1);
      c_syst[ib]->SetFillColor(10);
  }

  if (!DATA){
    TCanvas *c3 = new TCanvas("c3","Canvas3",1680,1050);
    c3->Divide(6,4);
  }

  TCanvas *c4 = new TCanvas("c4","Canvas4",1680,1050);
  c4->SetFillColor(10);
  c4->Divide(6,4);

  TCanvas *c5 = new TCanvas("c5","Canvas5");
  c5->SetFillColor(10);

  // Histograms that hold the information on N+ and N- for each eta bin
  TH1D *POS=new TH1D("POS","POS",11,0,2.4);
  TH1D *NEG=new TH1D("NEG","NEG",11,0,2.4);
  TH1D *BPOS=new TH1D("BPOS","BPOS",11,0,2.4);
  TH1D *BNEG=new TH1D("BNEG","BNEG",11,0,2.4);
  TH1 *ASY;

  // Weights for each background, templates are weighted when they are created
  // so all this does is scale them to the luminosity. As the normalisation will
  // float this is not needed, but is carried over from a previous version where
  // the templates needed to be weighted to their xsec
  double w[19];
  for (unsigned i=1; i<19; i++) w[i]=(1/100.)*lumi;//All templates weighted to 100pb
  // This allows us to scale the EWK fraction. 
  for (unsigned i=15; i<19; i++) {
    w[i]*=EWKfrac;
  }

  // dummy histogram pointer used to read in files
  TH1F *h1;

  // Signal contamination histograms
  for (int ib=0; ib<4;ib++){
      file[0]->cd(tfile_dir);
      gDirectory->GetObject("h_TPC"+ecalbin[ib],h1);
      NTP_con[ib] = h1->Integral();
      gDirectory->GetObject("h_TPS"+ecalbin[ib],h1);
      NTP_sig[ib] = h1->Integral();
  }

  // Begin main loop over all eta/charge bins
  for (int ib=0; ib<22;ib++){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;  
    cout<<"Eta Charge Bin:"<<Titles[ib]<<endl;  

    // Data 
    if (DATA){ // Read in data
      file[0]->cd(tfile_dir);
      gDirectory->GetObject(data_Ev+bins[ib]+Suffix,h1);
      hh_data_sel[ib]->Add(h1);

      gDirectory->GetObject(data_AntiEv+bins[(ib%2)*2  ]+Suffix,h1);//
      hh_data_sel_antisel[ib]->Add(h1);

      gDirectory->GetObject(data_AntiEv+bins[(ib%2)*2+1]+Suffix,h1);//
      hh_data_sel_antisel[ib]->Add(h1);
      //TODO add anti sel +  and anti sel - together
    }
    else{ // MC only running, read in all MC background and signal
      for (unsigned i=1; i<19; i++) {
        if (i>9&&i<11) continue;//TODO Update these ranges if running bData= false;	
        if (i>2&&i<15) continue;	
        file[i]->cd(tfile_dir);
        gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
        hh_data_sel[ib]->Add(h1,w[i]);
        gDirectory->GetObject(AntiEv+bins[ib]+Suffix,h1);
        hh_data_sel_antisel[ib]->Add(h1,w[i]);	
      }
    }

   
    // Signal
    // W->enu
    file[1]->cd(tfile_dir);
    gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
    h1->Sumw2();
    hh_wenu_sel[ib]->Add(h1,w[1]);

    // EWK background
    if (!madgraph){
      // DY->tautau 
      file[15]->cd(tfile_dir);
      gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
      h1->Sumw2();  
      hh_ewk_sel[ib]->Add(h1,w[15]);
      hh_dytautau_sel[ib]->Add(h1,w[15]);
      // W->taunu
      file[17]->cd(tfile_dir);
      gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
      h1->Sumw2();  
      hh_ewk_sel[ib]->Add(h1,w[17]);
      hh_wtaunu_sel[ib]->Add(h1,w[17]);
    }
    // DY->ee 
    file[16]->cd(tfile_dir);
    gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
    h1->Sumw2();  
    hh_ewk_sel[ib]->Add(h1,w[16]);
    hh_dyee_sel[ib]->Add(h1,w[16]);

    // ttbar
    file[18]->cd(tfile_dir);
    gDirectory->GetObject(Ev+bins[ib]+Suffix,h1);
    h1->Sumw2();  
    hh_ewk_sel[ib]->Add(h1,w[18]);
    hh_ttbar_sel[ib]->Add(h1,w[18]);

    // QCD background
    for (unsigned i=2; i<9; i++) {
      file[i]->cd(tfile_dir);
      gDirectory->GetObject(Ev+bins[ib],h1);
      h1->Sumw2();  
      hh_qcd_sel[ib]->Add(h1,w[i]);
    }

    // rebin histograms to our prefered binning
    hh_data_sel[ib]->Rebin(rebinFactor);
    hh_ewk_sel[ib]->Rebin(rebinFactor);
    hh_qcd_sel[ib]->Rebin(rebinFactor);
    hh_wenu_sel[ib]->Rebin(rebinFactor);
    hh_data_sel_antisel[ib]->Rebin(rebinFactor);
    hh_dytautau_sel[ib]->Rebin(rebinFactor);
    hh_dyee_sel[ib]->Rebin(rebinFactor);
    hh_wtaunu_sel[ib]->Rebin(rebinFactor);
    hh_ttbar_sel[ib]->Rebin(rebinFactor);

    if (debug){
      cout<<"Using range: "<<hh_wenu_sel[ib]->GetXaxis()->GetBinLowEdge(binMETCut)
          <<" to " <<hh_wenu_sel[ib]->GetXaxis()->GetBinUpEdge(nbins)<<endl;
      cout<<"MC Wenu = "      <<hh_wenu_sel[ib]->Integral(binMETCut,nbins)    <<endl;
      cout<<"MC EWK = "       <<hh_ewk_sel[ib]->Integral(binMETCut,nbins)     <<endl;
      cout<<"MC EWK DYtautau = "<<hh_dytautau_sel[ib]->Integral(binMETCut,nbins)<<endl;
      cout<<"MC EWK DYee = "  <<hh_dyee_sel[ib]->Integral(binMETCut,nbins)    <<endl;
      cout<<"MC EWK WTau= "   <<hh_wtaunu_sel[ib]->Integral(binMETCut,nbins)  <<endl;
      cout<<"MC EWK ttbar= "  <<hh_ttbar_sel[ib]->Integral(binMETCut,nbins)   <<endl;
      cout<<"MC QCD = "       <<hh_qcd_sel[ib]->Integral(binMETCut,nbins)     <<endl;
    }

    // add ewk background to signal, this fixed template is used in the fitting 
    hh_wenuewk_sel[ib]->Add(hh_wenu_sel[ib]);
    hh_wenuewk_sel[ib]->Add(hh_ewk_sel[ib]);
    hh_bkg_sel_template[ib]->Add(hh_data_sel_antisel[ib]);


    // clone histograms, RooFit needs a pointer to a TH1 TODO rename these
    TH1*  hhhh_wenuewk_sel = (TH1*)hh_wenuewk_sel[ib]->Clone();
    TH1*  hhhh_bkg_sel_template =(TH1*)hh_bkg_sel_template[ib]->Clone();
    TH1*  hhhh_data_sel =(TH1*)hh_data_sel[ib]->Clone();

    // Roo fit fun
    RooRealVar pfMET("pfMET","pfMET",0.,100.);
    RooRealVar fsig("fsig","signal fraction",0.5,0.,1.);

    RooDataHist roohist_wenuewk_sel("roohist_wenuewk_sel","wenuewk with pfMET",pfMET,hhhh_wenuewk_sel);
    RooDataHist roohist_bkg_sel_template("roohist_bkg_sel_template","bkg_template with pfMET",pfMET,hhhh_bkg_sel_template);
    RooHistPdf pdf_wenuewk_sel("pdf_wenuewk_sel","wenuewk with pfMET",RooArgList(pfMET),roohist_wenuewk_sel);
    RooHistPdf pdf_bkg_sel_template("pdf_bkg_sel_template","bkg_template with pfMET",RooArgList(pfMET),roohist_bkg_sel_template);
    RooDataHist roohist_data_sel("roohist_data_sel","data with pfMET",pfMET,hhhh_data_sel);

    RooRealVar nsig("nsig","signal fraction",0.,1000000.);
    RooRealVar nbkg("nbkg","background fraction",0.,1000000.);  
    RooAddPdf model_sel("model_sel","model_sel",RooArgList(pdf_wenuewk_sel,pdf_bkg_sel_template),RooArgList(nsig,nbkg));
    model_sel.fitTo(roohist_data_sel,Extended(kTRUE),SumW2Error(kFALSE),InitialHesse(kTRUE),PrintLevel(-2)); 

    // get fit results
    double nwenuewk_fit = nsig.getVal();
    double nwenuewk_fit_err = nsig.getError();
    double relSigErr=nwenuewk_fit_err/nwenuewk_fit;

    double nbkg_fit = nbkg.getVal();
    double nbkg_fit_err = nbkg.getError();
    double relBkgErr=nbkg_fit_err/nbkg_fit;

    // plot roofit 
    if (ib < 22) {
      c_roofit->cd(ib+1);
      RooPlot* xframe =  pfMET.frame();
      roohist_data_sel.plotOn(xframe,  MarkerColor(kBlack));
      model_sel.plotOn(xframe, Name("model_sel"), DrawOption("L"));
      xframe->Draw();
    }


    // scale templates to match fit results
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

    // get number of signal and background events 
    float NSignal =hh_wenu_sel_fit[ib]->Integral(binMETCut,nbins);//nwenuewk_fit*relfrac_wenu;
    float NQCD =hh_bkg_sel_template_fit[ib]->Integral(binMETCut,nbins);//nwenuewk_fit*relfrac_wenu;
    float NBackground =hh_bkg_sel_template_fit[ib]->Integral(binMETCut,nbins) + hh_ewk_sel_fit[ib]->Integral(binMETCut,nbins);//nbkg_fit+(nwenuewk_fit*(1-relfrac_wenu));

    //Signal Contamination Correction
    int i_ECAL; //what ecal bin we are in // TString ecalbin[4]={"_EB_pos","_EB_neg","_EE_pos","_EE_neg"};
    if (ib<14){
      i_ECAL = 0;
    }
    else{
      i_ECAL = 2;
    }
    if (ib%2 != 0) {//negative
      i_ECAL +=1;
    }
    // David's method,
    //float NControl = hh_bkg_sel_template[ib]->Integral();//N events in QCD template
    //float NSignal_cor = 1.0/(1.0-(NQCD/NControl)*(NTP_con[i_ECAL]/NTP_sig[i_ECAL]));
    //float NSignal_true = NSignal*NSignal_cor;
    //float contamFrac = (NSignal_true/NControl)*(NTP_con[i_ECAL]/NTP_sig[i_ECAL]);

    double sig_fit = NSignal;//N signal from fit
    double frac_AS = (NTP_con[i_ECAL]/NTP_sig[i_ECAL]);//N signal in AS / signal in selection
    double bkg_scale = ScaleBkg;//ammount background template is scaled to fit
    double sig_AS = sig_fit*frac_AS*bkg_scale;
    double sig_true = sig_fit + sig_AS;

    cout << "ECAL bin = " << ecalbin[i_ECAL] << endl;
    //cout << "signal contamination fraction in QCD template = " << contamFrac << endl;
    //cout << "signal contamination correction factor = " << NSignal_cor << endl;
    //cout << "NSignal (contamination corrected) = " << NSignal_true << " ±" << sqrt(NSignal) << " ±" << NSignal*nwenuewk_fit_err << endl;
    cout << "signal contamination fraction in QCD template = " << sig_AS/NQCD << endl;
    cout << "signal contamination correction factor = " << sig_true/sig_fit << endl;
    cout << "NSignal (contamination corrected) = " << sig_true << " ±" << sqrt(NSignal) << " ±" << NSignal*nwenuewk_fit_err << endl;

    if (corSigCon){
      //NQCD = NQCD - (NSignal_true - NSignal);
      //NSignal = NSignal_true;
      NQCD = NQCD - sig_AS; 
      NSignal = sig_true;
    }


    // Fill yield vs eta histograms 
    if (ib%2 == 0) {
      POS->SetBinContent(ib/2+1,NSignal) ;
      POS->SetBinError(ib/2+1,NSignal*relSigErr);
      BPOS->SetBinContent(ib/2+1,NQCD) ;
      BPOS->SetBinError(ib/2+1,NQCD*relBkgErr);
    }
    else {
      NEG->SetBinContent(ib/2+1,NSignal) ;
      NEG->SetBinError(ib/2+1,NSignal*relSigErr);
      BNEG->SetBinContent(ib/2+1,NQCD) ;
      BNEG->SetBinError(ib/2+1,NQCD*relBkgErr);
    }

    //     cout << endl;
    cout << "NSignal = " << NSignal << endl;
    cout << "NQCD = " << NQCD << endl;
    cout << "NBackground = " << NBackground << endl;



    // data plot of fit
    //TODO fix this to make bigger plots
    //if (ib < 22) {
    //  c1->cd(ib+1);
    //}
    c_fit[ib/2]->cd(ib%2 +1);

    // set histogram style
    hh_data_sel[ib]->SetMarkerSize(.01);
    hh_data_sel[ib]->SetMarkerStyle(20);
    hh_wenu_sel_fit[ib]->SetFillColor(42);
    hh_ewk_sel_fit[ib]->SetFillColor(45);
    hh_bkg_sel_template_fit[ib]->SetFillColor(9);
    hh_wenu_sel_fit[ib]->SetLineWidth(0.25);
    hh_ewk_sel_fit[ib]->SetLineWidth(0.25);
    hh_bkg_sel_template_fit[ib]->SetLineWidth(0.25);
    // plot fit histograms
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
    hh_data_sel[ib]->GetXaxis()->SetRange(0,100);
    hh_data_sel[ib]->GetXaxis()->SetTitle("PFMet (GeV)");
    hh_data_sel[ib]->GetYaxis()->SetTitle("Events/2 GeV");
    h_back_sel_fit->Draw("hist");
    hh_data_sel[ib]->Draw("e same");

    // TODO work out what the hell this does
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

    // chi2 of the fit TODO KS test and add to plot
    //Double_t chi2ndof = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"CHI2/NDF");
    //    Double_t chi2ndofUW = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"UW CHI2/NDF");
    //Double_t chi2 = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"CHI2"); 
    //     Double_t chi2UW = hh_data_sel[ib]->Chi2Test(hh_tot_sel_fit[ib],"UW CHI2"); 
    //cout<<"CHI2= "<<chi2<<", CHI2NDOF= "<<chi2ndof<<endl;

    // legend TODO add this to each plot
    if (ib==0){
      l5_2->AddEntry(hh_data_sel[ib],"data","p");
      l5_2->AddEntry(hh_bkg_sel_template_fit[ib],"QCD","F");
      l5_2->AddEntry(hh_wenu_sel_fit[ib],"Signal","F");
      l5_2->AddEntry(hh_ewk_sel_fit[ib],"EWK","F");
      //l5_2->AddEntry(hh_tot_sel_fit[ib],"Fit","l");

      l5_2->Draw();
    }

    // syst fit
    c_syst[ib/2]->cd(ib%2 +1);
    TH1 *h_syst = (TH1*)hh_tot_sel_fit[ib]->Clone(); //TODO delete this object
    h_syst->SetFillColor(kRed);
    //TODO calc errors

    hh_data_sel[ib]->SetMarkerSize(.01);
    hh_data_sel[ib]->SetMarkerStyle(20);
    hh_data_sel[ib]->SetMinimum(0);
    hh_data_sel[ib]->SetTitle(Titles[ib]);
    hh_data_sel[ib]->GetXaxis()->SetRange(0,100);
    hh_data_sel[ib]->GetXaxis()->SetTitle("PFMet (GeV)");
    hh_data_sel[ib]->GetYaxis()->SetTitle("Events/2 GeV");
    h_syst->Draw("E2");
    hh_data_sel[ib]->Draw("e same");

    // Ratio plot
    if (ib < 22) {
      //TODO could add this to fit plot
      c4->cd(ib+1);

      TH1 *jgg= new TH1F("h_data_selj"+bins[ib], bins[ib], nbins,0.,100.);
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
      TLine* line=new TLine(0.0, 1.0 , 100, 1.0);
      line->SetLineColor(2);
      line->Draw("same");
    }

    // MC truth plot
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

      if (ib==0){
        l5_0->AddEntry(hh_data_sel[ib],"W->e#nu","f");
        l5_0->AddEntry(cici,"EWK","f");
        l5_0->AddEntry(cucu,"QCD","f");
        l5_0->Draw();
      }
    }

  }
  // End eta/charge bin loop


  // Asymmetry (sig and bkg) plots
  ASY=POS->GetAsymmetry(NEG);
  BASY=BPOS->GetAsymmetry(BNEG);

  // systematic uncertaities
  // TODO add all systematics in
  // initilise array containing systs
  int SystCont=4;
  float systPos[11][4];
  float systNeg[11][4];
  cout<<"SW "<<endl;
  for (int ibin=0;ibin<11;ibin++){
    for (int icon=0;icon<SystCont;icon++){
      systPos[ibin][icon]=0.;
      systNeg[ibin][icon]=0.;
    }   	
  }  
  c2->cd();

  // mischarge rate effect
  float mischarge_rate[11]={0.0,0.0,0.0,0.0,0.0,0.0,0.0018,0.0025,0.0025,0.0039,0.0039};
  float mischarge_max[11] ={0.0008,0.0008,0.0007,0.0007,0.0007,0.0007,0.0025,0.0030,0.0030,0.0043,0.0043};
  float mischarge_min[11] ={0.0,0.0,0.0,0.0,0.0,0.0,0.0014,0.0017,0.0017,0.0026,0.0026};
  for (int ibin=0; ibin<11; ibin++){
    systPos[ibin][0]=ASY->GetBinContent(ibin+1)*((1/(1-2*mischarge_max[ibin]))-(1/(1-2*mischarge_rate[ibin])));
    systNeg[ibin][0]=ASY->GetBinContent(ibin+1)*((1/(1-2*mischarge_rate[ibin]))-(1/(1-2*mischarge_min[ibin])));
    ASY->SetBinContent(ibin+1,ASY->GetBinContent(ibin+1)/(1-2*mischarge_rate[ibin]));
  }

  // relative efficiency
  TH1F *NEGP=(TH1F*)NEG->Clone();
  TH1F *NEGM=(TH1F*)NEG->Clone();
  float Deltaerr[11]={0.018,0.018,0.018,0.018,0.018,0.018,0.018,0.018,0.018,0.018,0.018}; 
  for (int  ibin=0; ibin<11; ibin++){
    NEGP->SetBinContent(ibin+1,NEG->GetBinContent(ibin+1)*(1.+Deltaerr[ibin]));
    NEGM->SetBinContent(ibin+1,NEG->GetBinContent(ibin+1)*(1.-Deltaerr[ibin]));
  }
  TH1F *ASYP=POS->GetAsymmetry(NEGP);
  TH1F *ASYM=POS->GetAsymmetry(NEGM);
  for (int  ibin=0; ibin<11; ibin++){
    ASYP->SetBinContent(ibin+1,ASYP->GetBinContent(ibin+1)/(1-2*mischarge_rate[ibin]));
    ASYM->SetBinContent(ibin+1,ASYM->GetBinContent(ibin+1)/(1-2*mischarge_rate[ibin]));    
    systNeg[ibin][1]=ASY->GetBinContent(ibin+1)-ASYP->GetBinContent(ibin+1);
    systPos[ibin][1]=ASYM->GetBinContent(ibin+1)-ASY->GetBinContent(ibin+1);
  }

  float systRes[11]={0.0007,0.0007,0.0008,0.0008,0.0018,0.0018,0.0045,0.0035,0.0035,0.0051,0.0051};
  for (int ibin=0; ibin<11; ibin++){
    systNeg[ibin][2]=systRes[ibin];
    systPos[ibin][2]=systRes[ibin];
  }

  // add all systematics in quadrature
  float totsystmax[11] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  float totsystmin[11] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  for (int it=0; it<11;it++){
    float errsystmin=0;
    float errsystmax=0; 
    for (int icon=0; icon<SystCont;icon++){
      errsystmax+=(systPos[it][icon]*systPos[it][icon]);
      errsystmin+=(systNeg[it][icon]*systNeg[it][icon]);         
    }
    totsystmax[it]=sqrt(errsystmax); 
    totsystmin[it]=sqrt(errsystmin);  
  } 

  // print out raw results
  for (int ibi=0; ibi<11;ibi++){
    cout<<"BIN "<<ibi+1<<" "<<int(10000*ASY->GetBinContent(ibi+1))/10000.<<" +/- "
      <<int(10000.*ASY->GetBinError(ibi+1))/10000.<<" (stat) +"
      <<int(10000.*totsystmax[ibi])/10000.<<" - " 
      <<int(10000.*totsystmin[ibi])/10000.<<endl;
  }
  
  // TODO correct results for biases
  // TODO reprint results after corrections

  // create a graph of the background asymmetry
  // TODO add systematics
  c5->cd();
  double y[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  double ey_stat[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  double ey_all[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  for (int ibi=0; ibi<11;ibi++){
    y[ibi] = BASY->GetBinContent(ibi+1);
    float stat=BASY->GetBinError(ibi+1);
    // float syst=max(totsystmax[ibi],totsystmin[ibi]);
    // float toterr=sqrt(stat*stat+syst*syst);
    ey_stat[ibi] = stat;
  }
  TLine zeroline(0, 0.0, 2.5, 0.0); 
  TGraphErrors* g_bkgasym = new TGraphErrors(11, x, y, ex, ey_stat);
  g_bkgasym->GetYaxis()->SetRangeUser(-0.3,0.3);
  g_bkgasym->GetXaxis()->SetTitle("|#eta|");
  g_bkgasym->GetYaxis()->SetTitle("Asymmetry");
  g_bkgasym->SetTitle("Background Charge Asymmetry");
  g_bkgasym->Draw("ap");
  zeroline.SetLineColor(2);
  zeroline.Draw();

  // create asymmetry graph
  c2->cd(); 
  for (int ibi=0; ibi<11;ibi++){
    y[ibi] = ASY->GetBinContent(ibi+1);
    float stat=ASY->GetBinError(ibi+1);
    float syst=max(totsystmax[ibi],totsystmin[ibi]);
    float toterr=sqrt(stat*stat+syst*syst);
    ey_stat[ibi] = stat;
    ey_all[ibi] = toterr;
  }
  TGraphErrors* g_asym_stat = new TGraphErrors(11, x, y, ex, ey_stat);
  TGraphErrors* g_asym_all  = new TGraphErrors(11, x, y, ex, ey_all);

  // muon results as a comparison
  float mu_x[]={0.0992806, 0.297842, 0.496403, 0.703597, 0.902158, 1.10072,
    1.3036, 1.50216, 1.72662, 1.97266, 2.24892};
  float mu_x_err[]={0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.125, 0.125, 0.15};
  float mu_asym[] = {0.110027, 0.11625, 0.123165, 0.121782, 0.137686, 0.142181,
    0.157394, 0.168112, 0.184707, 0.203032, 0.219628};
  float mu_asym_err[] = {0.003803, 0.004149, 0.003803, 0.004495, 0.004495,
    0.004149, 0.004149, 0.004149, 0.003804, 0.003803, 0.004494};
  TGraphErrors* g_asym_mu  = new TGraphErrors(11, mu_x, mu_asym, mu_x_err, mu_asym_err);

  // asym graph plotting options
  g_asym_all->SetMarkerColor(2);
  g_asym_all->SetLineColor(2);
  g_asym_mu->SetMarkerColor(4);
  g_asym_mu->SetLineColor(4);
  //g_asym_all->Draw("ap");
  //g_asym_stat->Draw("ap");

  // urgh root Tmultigraph to handle plotting many graphs to a single graph
  TMultiGraph *mg_asym = new TMultiGraph();
  mg_asym->Add(g_asym_all,"p");
  mg_asym->Add(g_asym_stat,"p");
  mg_asym->Add(g_asym_mu,"p");
  mg_asym->Draw("a");
  mg_asym->GetXaxis()->SetTitle("|#eta|");
  mg_asym->GetYaxis()->SetTitle("Asymmetry");
  mg_asym->SetTitle("Electron Charge Asymmetry");
  gPad->Modified();
  mg_asym->SetMinimum(0.0);
  mg_asym->SetMaximum(0.32);
  //mg_asym->Draw("a");

  l5_4->AddEntry(g_asym_stat,"Only Statistical","l");
  l5_4->AddEntry(g_asym_all, "Stat. + Syst. error","l");
  l5_4->AddEntry(g_asym_mu, "Muon Channel","l");

  if (DATA) {
    l5_4->Draw("same");
    c2->SaveAs(output_dir+"asy"+FORMAT);
    c5->SaveAs(output_dir+"bkgasy"+FORMAT);
    //c1->SaveAs(output_dir+"data"+FORMAT);
    c6->SaveAs(output_dir+"inc"+FORMAT);
  }
  if(!DATA){
    l5_4->Draw("same");
    c2->SaveAs(output_dir+"final"+FORMAT);
    c3->SaveAs(output_dir+"PfMETbins"+FORMAT); 
  }
  c4->SaveAs(output_dir+"fitratio"+FORMAT);
  c_roofit->SaveAs(output_dir+"roofit"+FORMAT);
  for (int ib=0 ; ib<11 ; ib++){
      TString bin = "";
      bin+=ib;
      c_fit[ib]->SaveAs(output_dir+"data_"+bin+FORMAT);
      c_syst[ib]->SaveAs(output_dir+"syst_"+bin+FORMAT);
  }
}



void SetPlottingStyle(){

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


}
