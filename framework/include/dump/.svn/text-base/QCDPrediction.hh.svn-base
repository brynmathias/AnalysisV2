#ifndef QCDPREDICTION_h
#define QCDPREDICTION_h

//#include "Operation.hh"

#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <TH1D.h>
/**
 * \brief Class that handles the processing of the ntuples and making the merged histograms.
 *
 * \author CMS SUSY Dijet Analysis Team
 * \date Summer 2008
 */
class QCDPrediction {

 public:

  QCDPrediction(TString name = "",std::string filename = "",TString Method = "",Double_t fit_start = 0,Double_t fit_end = 0,Int_t markerColor=1,Int_t linestyle=22);
  ~QCDPrediction();

  /**
   * \brief Adds a dataset to the histogram to be plotted
   */
  void addDataSet(std::string dataSet);

   void makePlots();

   void OutputResults();

  TH1D* GetMeasured_Plot(){
    TString buf = "Measured " + filename_;
    AddedSignal->SetName(buf);
    return AddedSignal;
  }
  TH1D* GetPredicted_Plot(){
    TString buf = "Predicted " + filename_;
    std::cout << "buf " << buf << std::endl;
    Predicted->SetName(buf);
    return  Predicted;
  }
  TH1D* GetRatio_Plot(){
    TString buf = "Ratio " + filename_;
    AddedSignal_Bkgd->SetName(buf);
    return AddedSignal_Bkgd;
  }

  Double_t Estimated_SB(){
     return (D-totPredictedEvents)/totPredictedEvents;
  }

  Double_t err_Estimated_SB(){
    return sqrt( pow(err_D/totPredictedEvents,2) + pow(D*e_totPredicted/pow(totPredictedEvents,2),2));
  }
  
private:
 
  TString dirname_; //!< Output directory (hardcoded...)
  std::string filename_; //!< Output file (hardcoded...)
  TString Method;
  Double_t fitstart;
  Double_t fitend;

  Bool_t use100pbErrors;


  std::vector<TFile*> dataFileVec; //!< Vector of ROOT files from the datasets

  int color;
  int linestyle;

  Double_t A;
  Double_t B;
  Double_t C; 
  Double_t D;

  Double_t err_A;
  Double_t err_B;
  Double_t err_C;
  Double_t err_D;
  
  Double_t err_A_100;
  Double_t err_B_100;
  Double_t err_C_100;
  Double_t err_D_100;


  TString  mLogFileName;

  Double_t predictedRatio; 
  Double_t epredictedRatio; 
  Double_t e_totPredicted_100;
  Double_t totPredictedEvents;
  Double_t e_totPredicted;

  TH1D* AddedSignal_Bkgd;
  TH1D* AddedSignal;
  TH1D* AddedBkgd; 
  TF1 *Fit;
  TH1D* Predicted;


  void buildRatio(TString histname);

  void CalculateABCD(Int_t bin);

  void CalculateErrors();

  void fitFunction();

  void makePrediction(TString histname);


  

};
#endif
