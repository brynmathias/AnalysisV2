#ifndef PLOT_PREDICTION_h
#define PLOT_PREDICTION_h

//#include "Operation.hh"

#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <TH1D.h>
#include <map>
//#include <pair.h>

/**
 * \brief Class that handles the plotting of vectors of histograms
 * \author Tanja Rommerskirchen
 * \date March 2004
 */
class Plot_Prediction {

 public:
  Plot_Prediction(TString dirname,TString filename,std::vector<TH1D* >& histos) ;
 

 
  ~Plot_Prediction();

 
   void Plot();

 
private:
  TFile* rootFile;
  TString dirname_; //!< Output directory (hardcoded...)
  TString filename_; //!< Output file (hardcoded...)

 
 std::vector<TH1D* > histos;


  template<class T>void setPlotStyle(T& plot);
  void setPad(Double_t leftMargin);
  

};
#endif
