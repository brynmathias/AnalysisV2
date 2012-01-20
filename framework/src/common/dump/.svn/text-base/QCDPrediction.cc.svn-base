#include "QCDPrediction.hh"
#include "DrawOptions.hh"

#include <TCanvas.h>
#include <TLegend.h>

#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>

#include <iostream>

using namespace std;

QCDPrediction::QCDPrediction(TString dirname,std::string filename,TString method,Double_t fit_start,Double_t fit_end,int marker_Color,int line_Style) : dirname_(dirname),filename_(filename),Method(method),fitstart(fit_start),fitend(fit_end),color(marker_Color),linestyle(line_Style) {

 
  mLogFileName = dirname + "/";
  mLogFileName += filename;
  mLogFileName += ".log";

  // Get the draw options for the dataset from the DrawOptions class
  // TW - this appears to be unused? Generates a compilation warning. :-)
  //DrawOptions* myOptions = new DrawOptions(filename);


 
  // Predicted = new TGraphErrors;

  totPredictedEvents = 0;
 
  //for error Caluclation
  A = 0;
  B = 0;
  C = 0;
  D = 0;

  err_A = 0;
  err_B = 0;
  err_C = 0;
  err_D = 0;

  err_A_100 = 0;
  err_B_100 = 0;
  err_C_100 = 0;
  err_D_100 = 0;



}
QCDPrediction::~QCDPrediction() {
 
  //delete Predicted;
  dataFileVec.clear();
}

void QCDPrediction::addDataSet(std::string dataSet)
{


  // Create vector of ROOT files, one entry for each dataset
  TString dsRootFileName = dataSet;
  cout << "Adding " << dsRootFileName << endl;
 
  TFile* testFile = new TFile(dsRootFileName, "read");
 

  ((TH1*)(*testFile).Get("Signal"))->GetEntries();
  ((TH1*)(*testFile).Get("Bkgd"))->GetEntries();



  dataFileVec.push_back(testFile);

} // end of addDataSet method


void QCDPrediction::makePlots(){

  buildRatio("ratio");
  fitFunction();
  makePrediction("prediction");
  OutputResults();

}


void QCDPrediction::buildRatio(TString histname){
  

  int it = 0;

 
  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();tfileIt++)
    {
      if(it==0) {
	AddedSignal_Bkgd =(TH1D*)(*tfileIt)->Get("Signal")->Clone();
	AddedSignal =(TH1D*)(*tfileIt)->Get("Signal")->Clone();
	AddedBkgd = (TH1D*)(*tfileIt)->Get("Bkgd")->Clone();
      }
				
      else { 
      	AddedSignal_Bkgd->Add((TH1D*)((*tfileIt)->Get("Signal")));
	AddedSignal->Add((TH1D*)((*tfileIt)->Get("Signal")));
      	AddedBkgd->Add((TH1D*)((*tfileIt)->Get("Bkgd")));


      }

      it++;

    }

  /* // always calculate both Mc and 100 pb // changed by M. Stoye
     if(use100pbErrors) {
    
     for(int i = 0; i < AddedBkgd->GetNbinsX(); i++){
     AddedSignal_Bkgd->SetBinError(i,sqrt(AddedSignal_Bkgd->GetBinContent(i)));
     AddedBkgd->SetBinError(i,sqrt(AddedBkgd->GetBinContent(i)));
     AddedSignal->SetBinError(i,sqrt(AddedSignal->GetBinContent(i)));
     }
 

}
  */


AddedSignal_Bkgd->Divide(AddedBkgd);




AddedSignal_Bkgd->GetYaxis()->SetTitle("#frac{#events var1 > cut_signal}{#events var1 < cut_signal}");
   
AddedSignal_Bkgd->SetMarkerColor(color+1);
AddedSignal_Bkgd->SetMarkerStyle(linestyle+1);

AddedSignal->SetMarkerColor(color);
AddedSignal->SetMarkerStyle(linestyle); 


}


void QCDPrediction::fitFunction(){
Fit = new TF1("fit","[0]",fitstart,fitend); 
AddedSignal_Bkgd->Fit("fit","RN");
}

void QCDPrediction::makePrediction(TString histname){

 
predictedRatio =  Fit->GetParameter(0); 
epredictedRatio = Fit->GetParError(0);
   

Double_t BinCenter;
Double_t BinContent;
Double_t BinError;
Double_t BinXError; 
   
Double_t predictedEvents;
Double_t epredictedEvents;

 
Int_t numberBins = AddedBkgd->GetNbinsX();

Double_t maxBin = numberBins * AddedBkgd->GetBinWidth(1);
  
TString buf = "predictedEvents"+filename_;

Predicted = new TH1D(buf,"predicted events",numberBins,0,maxBin);

Predicted->Sumw2(); 

for(int bin = 1; bin <= numberBins; bin++)
{ 
BinCenter = AddedBkgd->GetBinCenter(bin);
BinContent = AddedBkgd->GetBinContent(bin);

BinError = AddedBkgd->GetBinError(bin);
BinXError = AddedBkgd->GetBinWidth(bin)/2;

predictedEvents = predictedRatio * BinContent;
epredictedEvents = sqrt( pow(BinError*predictedRatio,2) + pow(BinContent*epredictedRatio,2) );

Predicted->SetBinContent(bin,predictedEvents);
Predicted->SetBinError(bin,epredictedEvents);
     

CalculateABCD(bin);


}

CalculateErrors();

Predicted->SetMarkerColor(color+1);
Predicted->SetMarkerStyle(linestyle+1);
}


void QCDPrediction::CalculateABCD(Int_t bin){
  
Double_t BinCenter = AddedBkgd->GetBinCenter(bin);


// err_A_MC = 0;
// err_B_MC = 0;
// err_C_MC = 0;
// err_D_MC = 0;


//error Calculation
if(BinCenter < fitstart){ //signal region in variable 2 (eta)
D += AddedSignal->GetBinContent(bin);  //lets call it C signal region var1 > cutsignal && var2 < fitstart
err_D = err_D + pow(AddedSignal->GetBinError(bin),2);

B += AddedBkgd->GetBinContent(bin) ;//lets call it B var1 < cutsignal && var2 < fitstart
err_B = err_B + pow(AddedBkgd->GetBinError(bin),2); 
}
if(BinCenter > fitstart && BinCenter < fitend){ //control region in variable 2 (eta)
C += AddedSignal->GetBinContent(bin); // lets call it D var1 > cutsignal && var2 > fitstart
err_C = err_C + pow(AddedSignal->GetBinError(bin),2);

A += AddedBkgd->GetBinContent(bin) ;
err_A = err_A + pow(AddedBkgd->GetBinError(bin),2); 
}

}

void QCDPrediction::CalculateErrors()
{
  //error Calculation
  err_A = sqrt(err_A);
  err_B = sqrt(err_B);
  err_C = sqrt(err_C);
  err_D = sqrt(err_D);

  err_A_100 = sqrt(A);
  err_B_100 = sqrt(B);
  err_C_100 = sqrt(C);
  err_D_100 = sqrt(D);

  totPredictedEvents = C/A*B;

  //predicted events(D) = C/A*B
  e_totPredicted = sqrt(pow(err_C/A*B,2) + pow(C/A*err_B,2) + pow(C*B*err_A/pow(A,2),2));
  e_totPredicted_100 = sqrt(pow(err_C_100/A*B,2) + pow(C/A*err_B_100,2) + pow(C*B*err_A_100/pow(A,2),2));


}
  






void QCDPrediction::OutputResults() {

 

  ofstream outfile(mLogFileName);

  outfile.clear();

  cout << " ABCDMethod " << filename_ << endl;
  cout << " A " << A << " +- " << err_A << " B " << B << " +- " << err_B << " C " << C << " +_ " << err_C << " predicted events = C/A*B = " << totPredictedEvents << " +_ " << e_totPredicted << endl;
  cout << " measured Ratio " << predictedRatio  << " +- " << epredictedRatio <<  " predicted Events " << totPredictedEvents << " +- (MC)" << e_totPredicted <<" +- (100/pb)" << e_totPredicted_100  << " measured events " << D <<  " +- " << err_D <<  endl;
  cout << " " << endl;

  

    
  outfile << " ABCDMethod " << filename_ << endl;
  outfile << " A " << A << "+-" << err_A << " B " << B << "+-" << err_B << " C " << C << "+_" << err_C << " predicted events = C/A*B = " << totPredictedEvents << "+_" << e_totPredicted << endl;
  outfile << " measured Ratio " << predictedRatio << "+-" << epredictedRatio  << " predicted Events " << totPredictedEvents << " +- (MC)" << e_totPredicted << " +- (100/pb)" << e_totPredicted_100  <<" measured events " << D <<  "+-" << err_D << endl;


  outfile.close();
	    

}









