ostringstream ostream;
ofstream filestream;

float lumi;
//lumi = 876; //Muon PR
//lumi = 201; //Muon RR
//lumi = 881; //Electron PR
//lumi = 203; //Electron RR
//lumi = 960; //Muon
//lumi = 1084; //Electron
lumi =100; //Muon
TString dirname("");
TString HTbin("");
 
bool data = true;
bool susy = true;
bool qcd = true;
 
bool counterFromANplots=true; //if true it will require ANplots in ST bins, otherwise Counter_BSMGrid_SumLepPT is used

//TString ttPath = "resultsSync/tt.root" ;
TString ttPath = "resultsSyncSyst/BKG.root" ;
TString wPath = "resultsSyncSyst/BKG.root" ;
TString zPath = "resultsSyncSyst/BKG.root";
TString qcdPath = "resultsSync/qcdmu.root";
TString dataPath = "resultsSync/data.root"; 
//TString bkgPath = "resultsSyncResTest_metres_HT/BKG.root" ;
TString bkgPath = "resultsSync/data.root"; 
TString lm1Path = "/lm5.root";
TString lm3Path = "resultsSync/lm9p.root";
TString lm6Path = "resultsSync/lm6.root";

cutFlow(TString HTbin_){
  HTbin =  HTbin_;
  TString lumiString;
  lumiString+=lumi;
  ostream.setf(ios::fixed,ios::floatfield);;
  ostream.precision(1);
  tabStart(TString(" XXX for "+lumiString+" pb$^{-1}$ XXX"));
  ostream <<"$L_{P}$ $>$ 0.3& \\stlep$\\in[150-250]$ & \\stlep$\\in[250-350]$& \\stlep$\\in[350-450]$ &\\stlep$\\in$[450-inf] \\\\ \\hline  \\hline"<<endl;
  TString SumLepPT;
  if(counterFromANplots){
    SumLepPT = "ANplots";
  }
  else {
    SumLepPT = "Counter_BSMGrid_SumLepPT";
  }
  cutFlowostream(dirname+TString(ttPath),TString("tt"),SumLepPT,true);
  cutFlowostream(dirname+TString(wPath),TString("W"),SumLepPT,true);
  cutFlowostream(dirname+TString(zPath),TString("Z"),SumLepPT,true);
  if(qcd) {
    cutFlowostream(dirname+TString(qcdPath),TString("QCD"),SumLepPT,true);
  }
  cutFlowostream(dirname+TString(bkgPath),TString("Total MC"),SumLepPT,true);
  if(data){
    ostream.precision(0);
    cutFlowostream(dirname+TString(dataPath),TString("data"),SumLepPT,1,true);
    ostream.precision(1);

 }
  if(susy){
    //    cutFlowostream(dirname+TString(lm1Path),TString("LM1"),SumLepPT,true);
    cutFlowostream(dirname+TString(lm3Path),TString("LM9"),SumLepPT,true);
    cutFlowostream(dirname+TString(lm6Path),TString("LM6"),SumLepPT,true);
  }
  tabEnd();
  
  tabStart(TString("XXX for "+lumiString+" pb$^{-1}$ XXX"));
  ostream <<"$L_P < 0.15$&  \\stlep$\\in[150-250]$ & \\stlep$\\in[250-350]$& \\stlep$\\in[350-450]$ &\\stlep$\\in$[450-inf]  \\\\ \\hline  \\hline"<<endl;
  cutFlowostream(dirname+TString(ttPath),TString("tt"),SumLepPT,false);
  cutFlowostream(dirname+TString(wPath),TString("W"),SumLepPT,false);
  cutFlowostream(dirname+TString(zPath),TString("Z"),SumLepPT,false);
  if(qcd) {
    cutFlowostream(dirname+TString(qcdPath),TString("QCD"),SumLepPT,false);
  }
  cutFlowostream(dirname+TString(bkgPath),TString("Total MC"),SumLepPT,false);
  if(data) {

ostream.precision(0);
    cutFlowostream(dirname+TString(dataPath),TString("data"),SumLepPT,false,true);
ostream.precision(1);

    pred(dirname+TString(bkgPath),TString("prediction"),SumLepPT,false);
  }
  if(susy) {
    //   cutFlowostream(dirname+TString(lm1Path),TString("lm1"),SumLepPT,false);
    cutFlowostream(dirname+TString(lm3Path),TString("LM9"),SumLepPT,false);
    cutFlowostream(dirname+TString(lm6Path),TString("LM6"),SumLepPT,false);
  }
 
  tabEnd(); 
  cout << ostream.str();
  writeLatex("cutFlow.tex");
  
}
void writeLatex(TString filename) {
	filestream.open(filename);
	filestream << "\\documentclass[landscape]{article}\n\\usepackage[landscape]{geometry}\n\\begin{document}\n";
	filestream << ostream.str();
	filestream << "\n\\end{document}";
	filestream.close();
}

void  tabStart(TString cap)
{
  ostream <<"\\begin{table}[t]"<<endl;

  ostream <<"\\caption{"<<cap<<"}"<<endl<<"\\label{}"<<endl<<"\\begin{center}"<<endl<<"\\begin{tabular}{|c|c|c|c|c|} \\hline "<< endl;

}
void  tabEnd()
{
 ostream <<"\\end{tabular}"<<endl<<"\\end{center}"<<endl<<"\\end{table}"<< endl;
}

pred(TString filename, TString name, TString option,int i)
{

  // get MC events and error in signal region
  TFile* MCfile = new TFile(filename);
  TString SGNL;
  if(counterFromANplots) {
    SGNL = TString("_NOLPsecondD"+HTbin+"/CounterSgnl_tot");
  }
  else {
    SGNL = TString("_scale1/SM_Events");
  }
  float HT150Bin = ((TH1D*)MCfile->Get(option+"150"+SGNL))->GetBinContent(1);
  float HT150errBin = ((TH1D*)MCfile->Get(option+"150"+SGNL))->GetBinError(1);
  float HT250Bin = ((TH1D*)MCfile->Get(option+"250"+SGNL))->GetBinContent(1);
  float HT250errBin = ((TH1D*)MCfile->Get(option+"250"+SGNL))->GetBinError(1);
  float HT350Bin = ((TH1D*)MCfile->Get(option+"350"+SGNL))->GetBinContent(1);
  float HT350errBin = ((TH1D*)MCfile->Get(option+"350"+SGNL))->GetBinError(1);
  float HT450Bin = ((TH1D*)MCfile->Get(option+"450"+SGNL))->GetBinContent(1);
  float HT450errBin =((TH1D*)MCfile->Get(option+"450"+SGNL))->GetBinError(1);
  
  // get MC events and error in control region
  if(counterFromANplots) {
    BKG = TString("_NOLPsecondD"+HTbin+"/CounterCtrl_tot");
  }
  else {
    BKG = TString("_BKG_scale1/SM_Events");
  }
  float HT150BinB = ((TH1D*)MCfile->Get(option+"150"+BKG))->GetBinContent(1);
  float HT150errBinB = ((TH1D*)MCfile->Get(option+"150"+BKG))->GetBinError(1);
  float HT250BinB = ((TH1D*)MCfile->Get(option+"250"+BKG))->GetBinContent(1);
  float HT250errBinB = ((TH1D*)MCfile->Get(option+"250"+BKG))->GetBinError(1);
  float HT350BinB = ((TH1D*)MCfile->Get(option+"350"+BKG))->GetBinContent(1);
  float HT350errBinB = ((TH1D*)MCfile->Get(option+"350"+BKG))->GetBinError(1);
  float HT450BinB = ((TH1D*)MCfile->Get(option+"450"+BKG))->GetBinContent(1);
  float HT450errBinB = ((TH1D*)MCfile->Get(option+"450"+BKG))->GetBinError(1);

  // get data events and error in control region
  datafilename = dirname+TString(dataPath);
  datafile = new TFile(datafilename);
  float HT150BinD = ((TH1D*)datafile->Get(option+"150"+BKG))->GetBinContent(1);
  float HT150errBinD = ((TH1D*)datafile->Get(option+"150"+BKG))->GetBinError(1);
  float HT250BinD = ((TH1D*)datafile->Get(option+"250"+BKG))->GetBinContent(1);
  float HT250errBinD = ((TH1D*)datafile->Get(option+"250"+BKG))->GetBinError(1);
  float HT350BinD = ((TH1D*)datafile->Get(option+"350"+BKG))->GetBinContent(1);
  float HT350errBinD = ((TH1D*)datafile->Get(option+"350"+BKG))->GetBinError(1);
  float HT450BinD = ((TH1D*)datafile->Get(option+"450"+BKG))->GetBinContent(1);
  float HT450errBinD = ((TH1D*)datafile->Get(option+"450"+BKG))->GetBinError(1);
  
  // get data events and error in signal region
  float HT150BinDS = ((TH1D*)datafile->Get(option+"150"+SGNL))->GetBinContent(1);
  float HT150errBinDS = ((TH1D*)datafile->Get(option+"150"+SGNL))->GetBinError(1);
  float HT250BinDS = ((TH1D*)datafile->Get(option+"250"+SGNL))->GetBinContent(1);
  float HT250errBinDS = ((TH1D*)datafile->Get(option+"250"+SGNL))->GetBinError(1);
  float HT350BinDS = ((TH1D*)datafile->Get(option+"350"+SGNL))->GetBinContent(1);
  float HT350errBinDS = ((TH1D*)datafile->Get(option+"350"+SGNL))->GetBinError(1);
  float HT450BinDS = ((TH1D*)datafile->Get(option+"450"+SGNL))->GetBinContent(1);
  float HT450errBinDS = ((TH1D*)datafile->Get(option+"450"+SGNL))->GetBinError(1);
  
  // calculate predicted events 
  float pre150 = HT150Bin/HT150BinB*HT150BinD;
  float pre250 = HT250Bin/HT250BinB*HT250BinD;
  float pre350 = HT350Bin/HT350BinB*HT350BinD;
  float pre450 = HT450Bin/HT450BinB*HT450BinD;
  float preall = pre150+pre250+pre350+pre450;
  float MCerr150 = sqrt((HT150errBinB/HT150BinB)*(HT150errBinB/HT150BinB)+(HT150errBin/HT150Bin)*(HT150errBin/HT150Bin))*pre150;
  float MCerr250 =sqrt((HT250errBinB/HT250BinB)*(HT250errBinB/HT250BinB)+(HT250errBin/HT250Bin)*(HT250errBin/HT250Bin))*pre250;
  float MCerr350 =sqrt((HT350errBinB/HT350BinB)*(HT350errBinB/HT350BinB)+(HT350errBin/HT350Bin)*(HT350errBin/HT350Bin))*pre350;
  float MCerr450 =sqrt((HT450errBinB/HT450BinB)*(HT450errBinB/HT450BinB)+(HT450errBin/HT450Bin)*(HT450errBin/HT450Bin))*pre450;

  // error of prediction due to data statistic error in control region
  float presterrctrl150 = HT150Bin/HT150BinB*HT150errBinD;
  float presterrctrl250 = HT250Bin/HT250BinB*HT250errBinD;
  float presterrctrl350 = HT350Bin/HT350BinB*HT350errBinD;
  float presterrctrl450 = HT450Bin/HT450BinB*HT450errBinD;

  // calculate prediction error by adding statistical error of prediction (due to ctrl region stat. error) with sqrt(n) of prediction
  float preerr150 = sqrt(presterrctrl150*presterrctrl150 + pre150);
  float preerr250 = sqrt(presterrctrl250*presterrctrl250 + pre250);
  float preerr350 = sqrt(presterrctrl350*presterrctrl350 + pre350);
  float preerr450 = sqrt(presterrctrl450*presterrctrl450 + pre450);
  
  // output prediction
  ostream << "pred. & " << pre150 << "$\\pm$"<<  preerr150 <<"$\\pm$"<< MCerr150  <<" & " << pre250 << "$\\pm$"<< preerr250 <<"$\\pm$"<< MCerr250  <<" & " << pre350 << "$\\pm$"<< preerr350 <<"$\\pm$"<< MCerr350  <<" & " << pre450 << "$\\pm$"<< preerr450 << "$\\pm$"<< MCerr450  <<  "\\\\ \\hline"<<endl;
  
  // create prediction histogram
  TH1D* plotpre = new TH1D("plot",";ST_{lep};",4,150,550);
  plotpre->SetBinContent(1,pre150);
  plotpre->SetBinContent(2,pre250);
  plotpre->SetBinContent(3,pre350);
  plotpre->SetBinContent(4,pre450);
 
  // calculate difference between prediction and observed
  float preD150= pre150 - HT150BinDS;
  float preD250= pre250 - HT250BinDS;
  float preD350= pre350 - HT350BinDS;
  float preD450= pre450 - HT450BinDS;
  float preDall=HT150Bin/HT150BinB*HT150BinD+HT450Bin/HT450BinB*HT450BinD+ HT250Bin/HT250BinB*HT250BinD + HT350Bin/HT350BinB*HT350BinD-HT450BinDS-HT250BinDS- HT350BinDS-HT150BinDS;

  // output difference between prediction and observed
  ostream << "$\\Delta$pred. & " << preD150/pre150 << "$\\pm$"<< preerr150 << " & " << preD250/pre250<< "$\\pm$" << preerr250  << " & " << preD350/pre350 << "$\\pm$"<< preerr350  << " & " <<preD450/pre450<< "$\\pm$"<< preerr450 << " \\\\ \\hline"<<endl;

  //plot histos

  TH1D* ploterr = new TH1D("ploterr",";ST_{lep};",4,150,550);
  ploterr->SetBinContent(1,pre150);
  ploterr->SetBinContent(2,pre250);
  ploterr->SetBinContent(3,pre350);
  ploterr->SetBinContent(4,pre450);
  ploterr->SetLineWidth(3);
  ploterr->GetXaxis()->SetRangeUser(0,100);
  //ploterr->Draw();

  ploterr->SetBinError(1,sqrt(preerr150*preerr150+MCerr150*MCerr150));
  ploterr->SetBinError(2,sqrt(preerr250*preerr250+MCerr250*MCerr250));
  ploterr->SetBinError(3,sqrt(preerr350*preerr350+MCerr350*MCerr350));
  ploterr->SetBinError(4,sqrt(preerr450*preerr450+MCerr450*MCerr450));
  ploterr->SetLineColor(kBlue);

  TH1D* plotda = new TH1D("plotda",";S_{T}^{lep};number of events",4,150,550);
  plotda->SetBinContent(1,HT150BinDS);
  plotda->SetBinContent(2,HT250BinDS);
  plotda->SetBinContent(3,HT350BinDS);
  plotda->SetBinContent(4,HT450BinDS);
  plotda->SetLineWidth(3);
  plotda->GetXaxis()->SetRangeUser(0,100);
  plotda->Draw();
  ploterr->Draw("samee1");
  plotpre->SetBinError(1,preerr150);
  plotpre->SetBinError(2,preerr250);
  plotpre->SetBinError(3,preerr350 );
  plotpre->SetBinError(4,preerr450 );
  plotpre->SetLineColor(kRed);  plotpre->SetLineWidth(3);
  plotpre->Draw("samee1");

  TLegend * aleg = new TLegend(0.6,0.6,0.9,0.9);
  //  aleg->AddEntry(ploterr,"prediction (MC+data err)","lp");
  aleg->AddEntry(plotpre,"prediction","lp");
  aleg->AddEntry(plotda,"unsmeared MC","lp");
  aleg->SetFillColor(0);
  aleg->Draw("same");

}


cutFlowostream(TString filename, TString name, TString option,bool isBKG, bool isData=false)
{
  float lu = lumi;
  // if(isData) {
  //   lu = 100.;
  //  }
   cout << "trying to open " << filename << endl;
   TFile* thefile = new TFile(filename);
   cout << "opened " << filename << endl;
  cout << "opened " << TString("_NOLPsecondD"+HTbin+"/CounterSgnl_tot") << endl;
   thefile->ls();
   if(counterFromANplots) {
     SGNL = TString("_NOLPsecondD"+HTbin+"/CounterSgnl_tot");
     BKG = TString("_NOLPsecondD"+HTbin+"/CounterCtrl_tot");
   }
   else {
     BKG = TString("_BKG_scale1/SM_Events");
     SGNL = TString("_scale1/SM_Events");
   }
  TString REGION;
  if (isBKG) {
    REGION = BKG;
  }
  else {
    REGION = SGNL;
  }

  cout <<option+"150"+REGION<<endl;
  float HT150Bin = lu/100.*((TH1D*)thefile->Get(option+"150"+REGION))->GetBinContent(1);
  float HT150errBin = lu/100.*((TH1D*)thefile->Get(option+"150"+REGION))->GetBinError(1);
  float HT250Bin = lu/100.*((TH1D*)thefile->Get(option+"250"+REGION))->GetBinContent(1);
  float HT250errBin = lu/100.*((TH1D*)thefile->Get(option+"250"+REGION))->GetBinError(1);
  float HT350Bin = lu/100.*((TH1D*)thefile->Get(option+"350"+REGION))->GetBinContent(1);
  float HT350errBin = lu/100.*((TH1D*)thefile->Get(option+"350"+REGION))->GetBinError(1);
  float HT450Bin = lu/100.*((TH1D*)thefile->Get(option+"450"+REGION))->GetBinContent(1);
  float HT450errBin =lu/100.*((TH1D*)thefile->Get(option+"450"+REGION))->GetBinError(1);

  if(isData) {
    ostream << name<< " & "<< HT150Bin<< " & " << HT250Bin << " & "<< HT350Bin << " & " << HT450Bin  << "\\\\ \\hline"<<endl;
    
  }
  else {
    ostream << name<< " & "<< HT150Bin<< "$\\pm$"<< HT150errBin  << " & " << HT250Bin<< "$\\pm$"<< HT250errBin  << " & "<< HT350Bin << "$\\pm$"<< HT350errBin  <<" & " << HT450Bin << "$\\pm$"<< HT450errBin  <<"\\\\ \\hline"<<endl;
  }
  cout << "done with " << filename << endl;
}
