#ifndef BKGDDATASETS_h
#define BKGDDATASETS_h

//#include "Operation.hh"

#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <TMath.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TF1.h>


#include "Utils.hh"

/**
 * \brief Class that handles the processing of the ntuples and making the merged histograms.
 *
 * \author CMS SUSY Dijet Analysis Team
 * \date Summer 2008
 */
class bkgdDataSets {


 public:

  bkgdDataSets(TString dirname,std::string filename,const Utils::ParameterSet&,TString TH2DPlotName,TString range) ;

  ~bkgdDataSets();
  
  void addDataSet(std::string dataSet);
  
  void mergePlots();

  int NbrDataSets(){return dataFileVec.size();}

  const Double_t Pass(unsigned int bin)const{
    if(bin < pass.size() && bin > 0)return pass[bin];
    else return -1;
  } 

  const Double_t Fail(unsigned int bin)const{
    if(bin < fail.size() && bin > 0)return fail[bin];
    else return -1;
  } 

  const unsigned int PassSize()const{
    unsigned int size = pass.size();
    return size;
  }
  const Int_t FailSize()const{
    Int_t size = fail.size();
    return size;
  }

  TH1D* GetRatio_Plot(){
    TString buf = "Ratio " + filename_;
    AddedSignal_Bkgd->SetName(buf);
    return AddedSignal_Bkgd;
  }
  

private:
 
  TString dirname_; //!< Output directory (hardcoded...)
  std::string filename_; //!< Output file (hardcoded...)

 
  Double_t signalLow;
  Double_t signalUp;
  Double_t bkgdLow;


  TString TH2DPlotName;
  
  Int_t RebinX;

  std::vector<TFile*> dataFileVec; //!< Vector of ROOT files from the datasets

  TH1D* AddedSignal_Bkgd;
  TH1D* AddedSignal;
  TH1D* AddedBkgd; 

  std::vector<Double_t> pass;
  std::vector<Double_t> fail;

};
#endif
