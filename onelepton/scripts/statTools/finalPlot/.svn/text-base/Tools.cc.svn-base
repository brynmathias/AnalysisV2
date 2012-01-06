#include "ExclusionPlot.hh"



TH2F* getHisto( TString path,
	       TString nameHist,
	       TString nameFile ) {
  TString name = path + nameFile;
  TFile* file =  new TFile(name);
  //  TDirectory* dir = (TDirectory*)file->Get(Dirname);
  TH2F* hist = (TH2F*)file->Get(nameHist);
  if (!hist) {
    file->ls();
    std::cout << " name: " << nameHist
	      << " file: " << nameFile
	      << std::endl;
    abort();

  }
  hist->SetLineWidth(1);

  hist->GetXaxis()->SetTitleSize(0.055);
  hist->GetYaxis()->SetTitleSize(0.055);
  hist->GetXaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetLabelSize(0.05);
  hist->SetStats(kFALSE);
  return hist;
}


TH2F* yieldPlot(TString mSuGraFile,TString mSuGraDir, TString mSuGraHist){
  //read In mSuGra Histo
  TFile* f = new TFile(mSuGraFile);
  TDirectory* dir = (TDirectory*)f->Get(mSuGraDir);
  
  TH2F* hnev = (TH2F*)dir->Get(mSuGraHist);

 

  return hnev;
}

TH2F* yieldPlot_nosubdir(TString mSuGraFile,TString mSuGraHist){
  //read In mSuGra Histo
  TFile* f = new TFile(mSuGraFile);
  //  TDirectory* dir = (TDirectory*)f->Get(mSuGraDir);
  
  TH2F* hnev = (TH2F*)f->Get(mSuGraHist);

 

  return hnev;
}

TH1F* yieldPlot(TString mSuGraFile, TString mSuGraHist){
  //read In mSuGra Histo
  TFile* f = new TFile(mSuGraFile);
  // TDirectory* dir = (TDirectory*)f->Get(mSuGraDir);
  
  TH1F* hnev = (TH1F*)f->Get(mSuGraHist);

 

  return hnev;
}










void setPlottingStyle(TH1F& hsig){
  
  hsig.SetStats(kFALSE);
  
  hsig.SetAxisRange(80,500,"Y");
  hsig.SetAxisRange(0,520,"X");
  hsig.SetAxisRange(200,520,"X");

  hsig.GetXaxis()->SetTitle("m_{0} (GeV)");
  hsig.GetYaxis()->SetTitle("m_{1/2} (GeV)");
  hsig.GetYaxis()->SetTitleOffset(0.8);
  hsig.GetYaxis()->SetTitleSize(0.06);
  hsig.GetYaxis()->SetLabelSize(0.06);
  hsig.GetXaxis()->SetTitleOffset(0.9);
  hsig.GetXaxis()->SetTitleSize(0.06);
  hsig.GetXaxis()->SetLabelSize(0.06);

  hsig.SetLineWidth(1);  
  hsig.SetLineColor(kBlue);  
  
}








TH1F* getHisto_1d( TString path,
	       TString nameHist,
	       TString nameFile ) {
  TString name = path + nameFile;
  TFile* file =  new TFile(name);
  //  TDirectory* dir = (TDirectory*)file->Get(Dirname);
  TH2F* hist = (TH2F*)file->Get(nameHist);
  if (!hist) {
    std::cout << " name: " << nameHist
	      << " file: " << nameFile
	      << std::endl;
    abort();

  }

  

  TH1F* Onedhist = new TH1F(nameHist,nameHist,int(hist->GetXaxis()->GetNbins()+0.5),hist->GetXaxis()->GetXmin(),hist->GetXaxis()->GetXmax());

  for(int x = 0;x < hist->GetXaxis()->GetNbins();x++){

    bool firsthit = false;
    for(int y = hist->GetYaxis()->GetNbins(); y>0; y--){

      double y_height = hist->GetYaxis()->GetXmin()+hist->GetYaxis()->GetBinWidth(0)*y;

      if(firsthit == false && hist->GetBinContent(x+1,y) > 0){
	Onedhist->SetBinContent(x+1,y_height);
	firsthit = true;
	}


    }

  }


  Onedhist->SetLineWidth(1);

  Onedhist->GetXaxis()->SetTitleSize(0.055);
  Onedhist->GetYaxis()->SetTitleSize(0.055);
  Onedhist->GetXaxis()->SetLabelSize(0.05);
  Onedhist->GetYaxis()->SetLabelSize(0.05);
  Onedhist->SetStats(kFALSE);

  
  

  return Onedhist;
}


TCanvas* makeCanvas(TString tanb){
  TCanvas* cvsSys = new TCanvas("cvsnm","cvsnm",0,0,800,600);
  gStyle->SetOptTitle(0);
  cvsSys->SetFillColor(0);
  cvsSys->GetPad(0)->SetRightMargin(0.07);
  cvsSys->Range(-120.5298,26.16437,736.0927,500);
  cvsSys->SetFillColor(0);
  cvsSys->SetBorderMode(0);
  cvsSys->GetPad(0)->SetBorderSize(2);
  cvsSys->GetPad(0)->SetLeftMargin(0.1407035);
  cvsSys->GetPad(0)->SetTopMargin(0.08);
  cvsSys->GetPad(0)->SetBottomMargin(0.13);

  cvsSys->SetTitle("tan#beta="+tanb);

  return cvsSys;
}
