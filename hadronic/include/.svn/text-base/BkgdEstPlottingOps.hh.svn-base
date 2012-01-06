#ifndef hadronic_include_BkgdEstPlottingOps_hh
#define hadronic_include_BkgdEstPlottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include "Math/VectorUtil.h"
#include "ThrustStuff.hh"
#include "TH3.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include <strstream>
#include <iostream>
#include <fstream>

class TH1D;
class TH2D;



namespace Operation {

 

 


 class ABCDMethod : public PlottingBase  {

   public:

     /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param datasetname for histogram storage within ROOT file.
     * @param processName name for the ABCD variable combination called

     * @param var1Name name of the first variable generally the one on which one cut is applied
     * @param var2Name name of the second varialbe name of the second variable generally the one which is separated in bins

     * @param numberBins the number of bins you want for variable 1
     * @param MinVar2 starting value for the first bin in var1
     * @param MaxVar2 end value for the last bin in var1

     * @param numberBins the number of bins you want for variable 2
     * @param MinVar2 starting value for the first bin in var2
     * @param MaxVar2 end value for the last bin in var2

     * @param cutSignal the cut you apply on variable 1; per definition >cutSignal is signal <cutSignal is background
     */
     ABCDMethod(const std::string& fileName ,TString processName,TString var1Name,TString var2Name,UInt_t numberBinsVar1,float MinVar1,float MaxVar1, UInt_t numberBinsVar2, float MinVar2,float MaxVar2, const std::vector<Double_t>&lrange, const std::vector<Double_t>&hrange,Int_t minNumJets,Int_t maxNumJets);

     ~ABCDMethod();//!< Destructor.

  /*! \brief fills the required ABCD methods
     * @param event weight
     * @param variable 1
     * @param variable 2
     * @return Always true - this is a plotting operation.
     */
    bool Process(Double_t weight, Double_t var1, Double_t var2,Double_t var3,Int_t numJets);
   bool Process( Event::Data& ){return true;}

    void BookHistos();
    /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

  private:
  // Operation private data members
  //--------------------------------
    TFile *  File; //output file

    TString  var1Name;
    TString var2Name;
    Int_t numberBinsVar1;
    Float_t MinVar1;
    Float_t MaxVar1;
    Int_t numberBinsVar2;
    Float_t MinVar2;
    Float_t MaxVar2;



    TString process_name;

     const std::vector<Double_t > Lrange;

     const std::vector<Double_t > Hrange;


 Int_t MinNumJets;
    Int_t MaxNumJets;





  std::vector<TH2D *>ABCD_TH2D;




}; //~ABCDMethod class



   class BkgdEstPlottingOps : public PlottingBase {

  public:

     BkgdEstPlottingOps( const Utils::ParameterSet& );
     ~BkgdEstPlottingOps();

     void Start( Event::Data& );
     bool Process( Event::Data& );

     std::ostream& Description( std::ostream& );

   private:

     void BookHistos();

     std::string dirName_;

    
     ABCDMethod** *alphaT_vs_HT;



     Int_t nMin_;
     Int_t nMax_;

     const int m0_felder_;
     const int m12_felder_;

     int m0_feld_save;



  };



}

#endif // hadronic_include_BkgdEstPlottingOps_hh
