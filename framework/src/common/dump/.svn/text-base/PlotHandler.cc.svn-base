/*! \file PlotHandler.cc
 * \brief Source code for the PlotHandler class. 
 */

#include "PlotHandler.hh"
#include "DrawOptions.hh"

#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>
#include <TMath.h>
#include <TGraphErrors.h>

#include <iostream>

using namespace std;

PlotHandler::PlotHandler(std::string dirname) : dirname_(dirname) {}

PlotHandler::~PlotHandler() {}

void PlotHandler::addDataSet(std::string dataSet)
{
  // Get the draw options for the dataset from the DrawOptions class
  DrawOptions* myOptions = new DrawOptions(dataSet);

  // Create vector of ROOT files, one entry for each dataset
  TString dsRootFileName = dirname_ + "/" + dataSet + ".root";
  cout << "Adding " << dsRootFileName << endl;
  TFile* rootFile = new TFile(dsRootFileName, "read");
  dataFileVec.push_back(rootFile);

  // Add dataset variables to other vectors
  drawOptVec.push_back(myOptions->drawOpt);
  colorVec.push_back(myOptions->color);
  linewidthVec.push_back(myOptions->linewidth);
  linestyleVec.push_back(myOptions->linestyle);
  dataNameVec.push_back(dataSet);

  legendVec.push_back(myOptions->LegendText);

} // end of addDataSet method


void PlotHandler::merge1DHist(char* fn, char* hn, bool legend, TString drawOpt) {

  TCanvas myCanvas(hn);
  TLegend myLegend(0.63, 0.73, 0.9, 0.93);
  myLegend.SetLineColor(0);
  myLegend.SetFillColor(0);
  myCanvas.SetLogy();
  Float_t theScale =1.;
  gPad->SetTicks();
  gPad->SetLeftMargin  ( 0.190*theScale );
  gPad->SetRightMargin ( 0.065*theScale );
  gPad->SetTopMargin( 0.05*theScale  );
  gPad->SetBottomMargin( 0.150*theScale  );

  int it = 0;
  Double_t maxsize=0;

  std::cout << " file name "<< fn << " hist name " << hn << std::endl;

  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();tfileIt++) {
    ((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->SetLineColor(colorVec[it]);
    ((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->SetLineWidth(linewidthVec[it]);
    ((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->SetLineStyle(linestyleVec[it]);
    if(legend==true)  myLegend.AddEntry(((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn)),legendVec[it], "L");
    if(it==0) {
      ((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn)->Draw(drawOptVec[it]+"h");
      maxsize = ((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->GetMaximum();
    }
    else {
      TString sameOpt = drawOptVec[it] + "h" + "same"; 
      ((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->Draw(sameOpt);
      if(((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->GetMaximum()>maxsize) {
	maxsize = ((TH1*)((TDirectoryFile*)(*tfileIt)->Get(fn))->Get(hn))->GetMaximum();
      }
    } // end of iteration check.

    
    it++;
  }

  //((TH1*)dataFileVec[0]->Get(hn))->SetMinimum(0.1);
  //((TH1*)dataFileVec[0]->Get(hn))->SetMaximum(maxsize*1.1);
  if(legend==true) myLegend.Draw();
  TString filename = TString(fn) + "_" + TString(hn);
  myCanvas.SaveAs(dirname_+"/"+filename+".png");
  myCanvas.SaveAs(dirname_+"/"+filename+".eps");

} // end of merge1DHist method




/*

void PlotHandler::make2DHist(char* histname)
{

  //outFile->cd();
  TCanvas myCanvas(histname);
  Double_t theScale = 1.;

  gPad->SetTicks();
  gPad->SetLeftMargin  ( 0.190*theScale );
  gPad->SetRightMargin ( 0.065*theScale );
  gPad->SetTopMargin( 0.05*theScale  );
  gPad->SetBottomMargin( 0.150*theScale  );

  myCanvas.SetLogz();
  int dataNo = linewidthVec.size();
  //cout << "dataNo = " << dataNo << endl;
  if (dataNo%2==1) dataNo++;
  myCanvas.Divide(2,dataNo/2);
  int it = 0;
  TString space = ": ";

  Double_t maxsize=((TH1*)dataFileVec[1]->Get(histname))->GetMaximum();

  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();++tfileIt)
    {
      myCanvas.cd(it+1);

      // ((TH1*)(*tfileIt)->Get(histname))->SetLineColor(colorVec[it]);
      ((TH1*)(*tfileIt)->Get(histname))->SetFillColor(colorVec[it]);
      //  ((TH1*)(*tfileIt)->Get(histname))->SetLineWidth(linewidthVec[it]);
      //  ((TH1*)(*tfileIt)->Get(histname))->SetLineStyle(linestyleVec[it]);
      ((TH1*)(*tfileIt)->Get(histname))->SetTitle(histname+space+legendVec[it]);
      // ((TH1*)(*tfileIt)->Get(histname))->SetMaximum(maxsize);
      ((TH2*)(*tfileIt)->Get(histname))->Rebin2D(2,2);
      (*tfileIt)->Get(histname)->Draw("box");    
      it++;
    }
  //outFile->cd();
  //myCanvas.Write();
  TString filename = histname;
  myCanvas.SaveAs(dirname_+"/"+filename+".png");
  myCanvas.SaveAs(dirname_+"/"+filename+".eps");

} // end of PlotHandler::make2DHist

*/



/*

//if smaller == true accepted is what is smaller than a certain cut
//if smaller == false accepted is what is larger than a certain cut
void PlotHandler::SoverB(char* histname,bool smaller){

  TH1D* Signal;
  TH1D* Background;
  

  //Add all necessary histograms first dataset assumed to be signal
  int it = 0;
  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();tfileIt++)
    { 
      ((TH1*)(*tfileIt)->Get(histname))->GetEntries();

      if(it==0) {
	Signal =(TH1D*)(*tfileIt)->Get(histname);
      }
      else if(it == 1) Background = (TH1D*)(*tfileIt)->Get(histname);
      else if(it > 1) {
       	Background->Add((TH1D*)((*tfileIt)->Get(histname)));
      }
      it++;
    }

  Int_t numberBins = Background->GetNbinsX();
  Double_t maxBin = numberBins * Background->GetBinWidth(1);

  Double_t background;
  Double_t signal;

  TString name = histname;
  name = name + "_SoverB"; 

  Double_t error_bkgd;
  Double_t error_signal;
  Double_t error_total;
  
  TH1D* SoverB = new TH1D(name,"signal over background",numberBins,0,maxBin);

 
  Double_t x[numberBins], y[numberBins];

  Double_t ex[numberBins];
  Double_t ey[numberBins];



 
 
  for(int bin = 1; bin <= numberBins; bin++)
    { 

      error_bkgd = 0;
      error_signal = 0;  
       
      if(smaller == false){// signal is what is above cut
	background = Background->Integral(bin,numberBins);
	signal = Signal->Integral(bin,numberBins);

	for(int count = bin; count <= numberBins; count++){
	  error_bkgd = error_bkgd + pow(Background->GetBinError(count),2);
	  error_signal = error_signal + pow(Signal->GetBinError(count),2);
	}
      }
      else {//signal is what is below cut
	background = Background->Integral(0,bin);
	signal = Signal->Integral(0,bin);

	for(int count = 1; count <= bin; count++){
	  error_bkgd = error_bkgd + pow(Background->GetBinError(count),2);
	  error_signal = error_signal + pow(Signal->GetBinError(count),2);
	}	
     }

      error_bkgd = sqrt(error_bkgd);
      error_signal = sqrt(error_signal);

      error_total = sqrt( pow(error_signal/background,2) + pow( error_bkgd * signal/pow(background,2),2 ) );
      
      y[bin-1] = signal/background;
      x[bin-1] = signal;

      ex[bin-1] = error_signal;
      
      if(background != 0) ey[bin-1] = error_total;
      else ey[bin-1] = 0.;


      
      if(background != 0){
	SoverB->SetBinContent(bin,signal/background);
	SoverB->SetBinError(bin,error_total);
      }
      else SoverB->SetBinContent(bin,0);
     
      cout << "center " << Background->GetBinCenter(bin) << " signal " << signal << " background " << background << " S/B " << signal/background << " +- " << error_total << endl;
      cout << " errorx " << ex[bin] << " errory " << ey[bin] << endl;
    }

  TGraphErrors* S_SoB = new TGraphErrors(numberBins,x,y,ex,ey);

  TCanvas myCanvas(name);

  myCanvas.Divide(2,2);
 

  TLegend myLegend(0.63, 0.73, 0.9, 0.93);

  Float_t theScale =1.;
  gPad->SetTicks();
  gPad->SetLeftMargin  ( 0.190*theScale );
  gPad->SetRightMargin ( 0.065*theScale );
  gPad->SetTopMargin( 0.05*theScale  );
  gPad->SetBottomMargin( 0.150*theScale  );

  TString outFileName = dirname_+"/"+name+ ".root";

  TFile* rootFile = new TFile(outFileName,"recreate");
  rootFile->cd();

  myCanvas.cd(1);

  gPad->SetLogy(1);
  Signal->SetTitle("signal");
  Signal->SetMinimum(0.1);
  Signal->Draw("h");
 
  myCanvas.cd(2);

  gPad->SetLogy(1);
  Background->SetTitle("background");
  Background->SetMinimum(0.1);
  Background->Draw("h");

  myCanvas.cd(3);

  TString title = histname;
  title = "cut on " + title;
  SoverB->GetXaxis()->SetTitle(title);
  SoverB->GetYaxis()->SetTitle("S/B");
  SoverB->Draw("h");

  myCanvas.cd(4);
  S_SoB->SetMarkerStyle(22);
  S_SoB->GetXaxis()->SetTitle("signal");
  S_SoB->GetYaxis()->SetTitle("S/B");
  S_SoB->Draw("AP");


  myCanvas.SaveAs(dirname_+"/"+name+".png");
  myCanvas.SaveAs(dirname_+"/"+name+".eps");
  myCanvas.Write(); 
}

*/


/*

void PlotHandler::makePrediction(TH1D& Predicted, TString histname,const TF1 &Fit,const TH1D& histo){

 
  Double_t predictedRatio =  Fit.GetParameter(0); 
  Double_t epredictedRatio = Fit.GetParError(0);
   

  Double_t BinCenter;
  Double_t BinContent;
  Double_t BinError;
  Double_t BinXError; 
   
  Double_t predictedEvents;
  Double_t epredictedEvents;

 
  Int_t numberBins = histo.GetNbinsX();

 
   for(int bin = 1; bin <= numberBins; bin++)
    { 
      BinCenter = histo.GetBinCenter(bin);
      BinContent = histo.GetBinContent(bin);

      BinError = histo.GetBinError(bin);
      BinXError = histo.GetBinWidth(bin)/2;

      predictedEvents = predictedRatio * BinContent;
      epredictedEvents = sqrt( pow(BinError*predictedRatio,2) + pow(BinContent*epredictedRatio,2) );

      Predicted.SetBinContent(bin,predictedEvents);
      Predicted.SetBinError(bin,epredictedEvents);
     

      //  CalculateABCD(bin);


    }

   // CalculateErrors();

  
}

*/






  
/*

void PlotHandler::makeABCD(char* histname,Double_t cut_varX,Double_t fitstart, Double_t fitend){

  TH2D* SignalPlusBackground;
  TH2D* Background;

   
  TH1D* SignalPlusBackground_AB;
  TH1D* Background_AB;
 
  TH1D* SignalPlusBackground_CD;
  TH1D* Background_CD;
  
  TH1D* Ratio_SignalPlusBackground;
  TH1D* Ratio_Background;

 

  int it = 0;
  
  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();tfileIt++)
    { 
      if(it == 0){
	SignalPlusBackground = ((TH2D*)(*tfileIt)->Get(histname));
      }
      if(it == 1){
	SignalPlusBackground->Add((TH2D*)((*tfileIt)->Get(histname)));
	Background = ((TH2D*)(*tfileIt)->Get(histname));
      }
      else if(it > 1) {
	SignalPlusBackground->Add((TH2D*)((*tfileIt)->Get(histname)));
       	Background->Add((TH2D*)((*tfileIt)->Get(histname)));
      }
      it++;
    }


  Int_t numberBinsX = Background->GetNbinsX();
  Int_t numberBinsY = Background->GetNbinsY();

 
 
  Int_t cutBin = cut_varX/(Background->GetBinWidth(1));
  Int_t startBin = cutBin+1;
  cout << "startBin " << startBin << " center " << Background->GetBinCenter(startBin) << endl;
  
  SignalPlusBackground_AB = SignalPlusBackground->ProjectionY("SignalPlusBackground_AB",1,cutBin);
  
  SignalPlusBackground_CD = SignalPlusBackground->ProjectionY("SignalPlusBackground_CD",startBin,numberBinsX);
  Ratio_SignalPlusBackground = SignalPlusBackground->ProjectionY("Ratio_SignalPlusBackground_CD",startBin,numberBinsX);
  
  Ratio_SignalPlusBackground->Divide(SignalPlusBackground_AB);

  Background_AB = Background->ProjectionY("Background_AB",1,cutBin);
  Background_CD = Background->ProjectionY("Background_CD",startBin,numberBinsX);
  Ratio_Background = Background->ProjectionY("Ratio_Background_CD",startBin,numberBinsX);

  Ratio_Background->Divide(Background_AB);


  //Do the Fit ---------------------------------------------------------------------------

  const TF1* Fit_Bkgd = new TF1("fit_bkgd","[0]",fitstart,fitend); 
  Ratio_Background->Fit("fit_bkgd","RN");

  const TF1* Fit_SignalPlusBackground = new TF1("fit_SaB","[0]",fitstart,fitend); 
  Ratio_SignalPlusBackground->Fit("fit_SaB","RN");

  //Make Prediction ---------------------------------------------------------------------------------------
  Double_t maxBinY = numberBinsY * Background->GetYaxis()->GetBinWidth(1);
 
  TH1D * Predicted_Background = new TH1D("predicted_events_Background","predicted events",numberBinsY,0,maxBinY);
  Predicted_Background->Sumw2(); 

  TH1D * Predicted_SignalPlusBackground = new TH1D("predicted_events_SignalPlusBackground","predicted events",numberBinsY,0,maxBinY);
  Predicted_SignalPlusBackground->Sumw2(); 


  makePrediction(*Predicted_Background, *histname,*Fit_Bkgd,*Background_AB);
  makePrediction(*Predicted_SignalPlusBackground, *histname,*Fit_SignalPlusBackground,*SignalPlusBackground_AB);



  TString name = histname;
  name = name + "_ABCD"; 


  TCanvas myCanvas(name);

  myCanvas.Divide(2,3);
 

  TLegend myLegend1(0.63, 0.73, 0.9, 0.93);

  myLegend1.AddEntry( Ratio_SignalPlusBackground,"Ratio SignalPlusBackground", "P");
  myLegend1.AddEntry( Ratio_Background,"Ratio Background only", "P");

 
  TLegend myLegend2(0.63, 0.73, 0.9, 0.93);

  myLegend2.AddEntry( Predicted_SignalPlusBackground,"Predicted_SignalPlusBackground", "P");
  myLegend2.AddEntry( Predicted_Background,"Predicted Background only", "P"); 

  TLegend myLegend3(0.63, 0.73, 0.9, 0.93);

  myLegend3.AddEntry( Background_CD,"Measured Background only", "P");
  myLegend3.AddEntry( Predicted_Background,"Predicted Background only", "P"); 

  TLegend myLegend4(0.63, 0.73, 0.9, 0.93);

  myLegend4.AddEntry( SignalPlusBackground_CD,"Measured SignalPlusBackground", "P");
  myLegend4.AddEntry( Predicted_SignalPlusBackground,"Predicted SignalPlusBackground", "P"); 

  TLegend myLegend5(0.63, 0.73, 0.9, 0.93);

  myLegend5.AddEntry(Background,"Background", "P");

  TLegend myLegend6(0.63, 0.73, 0.9, 0.93);

  myLegend6.AddEntry(SignalPlusBackground,"SignalPlusBackground", "P"); 


  Float_t theScale =1.;
  gPad->SetTicks();
  gPad->SetLeftMargin  ( 0.190*theScale );
  gPad->SetRightMargin ( 0.065*theScale );
  gPad->SetTopMargin( 0.05*theScale  );
  gPad->SetBottomMargin( 0.150*theScale  );

  TString outFileName = dirname_+"/"+name+ ".root";

  TFile* rootFile = new TFile(outFileName,"recreate");
  rootFile->cd();

  myCanvas.cd(1);

// Ratio_SignalPlusBackground->SetMaximum(0.0012);
 Ratio_SignalPlusBackground->SetMinimum(-0.00012);
 Ratio_Background->SetMaximum(0.0012);

 
  Ratio_SignalPlusBackground->SetMarkerStyle(21);
  Ratio_SignalPlusBackground->Draw();


  Ratio_Background->SetTitle("ratio_background");
 
  Ratio_Background->SetMarkerColor(2);
  Ratio_Background->SetMarkerStyle(22);
  Ratio_Background->Draw("same");

  myLegend1.Draw();
 
  myCanvas.cd(2);



  Predicted_SignalPlusBackground->SetMinimum(0.1);
  Predicted_SignalPlusBackground->SetMarkerStyle(22);
  Predicted_SignalPlusBackground->SetMarkerColor(2);
  Predicted_SignalPlusBackground->Draw();

  Predicted_Background->SetMinimum(0.1);
  Predicted_Background->SetMarkerStyle(21);
  Predicted_Background->SetMarkerColor(1);
  Predicted_Background->Draw("same");

  myLegend2.Draw();
 
  myCanvas.cd(3);
 
  Background_CD->SetTitle("Predicted_Measured_BackgroundOnly");
  Background_CD->SetMinimum(0.1);
  Background_CD->SetMarkerColor(2);
  Background_CD->SetMarkerStyle(22);
  Background_CD->Draw();

  Predicted_Background->SetMinimum(0.1);
  Predicted_Background->SetMarkerStyle(21);
  Predicted_Background->SetMarkerColor(1);
  Predicted_Background->Draw("same");

  myLegend3.Draw();


  myCanvas.cd(4); 
  SignalPlusBackground_CD->SetTitle("Predicted_Measured_SignalPlusBackground");
  SignalPlusBackground_CD->SetMinimum(0.1);
  SignalPlusBackground_CD->SetMarkerColor(1);
  SignalPlusBackground_CD->SetMarkerStyle(21);
  SignalPlusBackground_CD->Draw();

  Predicted_SignalPlusBackground->SetMinimum(0.1);
  Predicted_SignalPlusBackground->SetMarkerStyle(22);
  Predicted_SignalPlusBackground->SetMarkerColor(2);
  Predicted_SignalPlusBackground->Draw("same");

  myLegend4.Draw();
 

  myCanvas.cd(5);
  Background->SetTitle("Background");
  Background->SetMinimum(0.1);
  Background->Draw("ColZ");

  myLegend5.Draw();


  myCanvas.cd(6);
  SignalPlusBackground->SetTitle("signalPlusBackground");
  SignalPlusBackground->SetMinimum(0.1);
  SignalPlusBackground->Draw("ColZ");

  myLegend6.Draw();

 
  myCanvas.SaveAs(dirname_+"/"+name+".png");
  myCanvas.SaveAs(dirname_+"/"+name+".eps");
  myCanvas.Write();


}


*/







