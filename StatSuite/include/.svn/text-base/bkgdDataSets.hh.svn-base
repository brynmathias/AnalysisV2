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

  const int NbrDataSets()const{return dataFileVec.size();}

  const Double_t Pass(unsigned int bin)const{
    if(bin < pass.size() && bin > 0)return pass[bin];
    else return -1;
  } 


  const Double_t PassFrom(unsigned int bin)const{
    if(bin < AddedSignal->GetNbinsX())return AddedSignal->Integral(bin,AddedSignal->GetNbinsX());
    else return -1;
  } 

  const Double_t D_PassFrom(double_t bin)const{
    // std::cout << " found bin " << AddedSignal->FindBin(bin) << std::endl;
    if(AddedSignal->FindBin(bin) != -1)return AddedSignal->Integral(AddedSignal->FindBin(bin),AddedSignal->GetNbinsX());
    else return -1;
  }

  const Double_t D_PassFrom_To(double_t binFrom,double_t binTo)const{
    if(binFrom >= binTo){std::cout << " not valid D_PassFrom_To " << std::endl; return -1;}
    if(AddedSignal->FindBin(binFrom) != -1 && AddedSignal->FindBin(binTo) != -1)
      return AddedSignal->Integral(AddedSignal->FindBin(binFrom),AddedSignal->FindBin(binTo));
    else return -1;
  }

  

  const Double_t D_FailFrom(double_t bin)const{
    if(AddedBkgd->FindBin(bin) != -1){
      return AddedBkgd->Integral(AddedBkgd->FindBin(bin),AddedBkgd->GetNbinsX());
    }
    else return -1;
  }

  const Double_t D_FailFrom_To(double_t binFrom,double_t binTo)const{
    if(binFrom >= binTo){std::cout << " not valid D_FailFrom_To " << std::endl; return -1;}
    if(AddedBkgd->FindBin(binTo) != -1 && AddedBkgd->FindBin(binFrom) != -1)return AddedBkgd->Integral(AddedBkgd->FindBin(binFrom),AddedBkgd->FindBin(binTo));
    else return -1;
  }


  const Double_t FailFrom(unsigned int bin)const{
    if(bin < AddedBkgd->GetNbinsX())return AddedBkgd->Integral(bin,AddedBkgd->GetNbinsX());
    else return -1;
   } 

  const Double_t AllPass()const{
    return AddedSignal->Integral();
  }

  const Double_t AllFail()const{
    return AddedBkgd->Integral();
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

  //  TFile* testFile ;

};
#endif
