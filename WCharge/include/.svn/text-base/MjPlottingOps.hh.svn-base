#ifndef hadronic_include_MjPlottingOps_hh
#define hadronic_include_MjPlottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

const static int EtaCh_Bins=13;
const TString Suffix[EtaCh_Bins]={"",
  "_eta1_pos","_eta2_pos","_eta3_pos","_eta4_pos","_eta5_pos","_eta6_pos",
  "_eta1_neg","_eta2_neg","_eta3_neg","_eta4_neg","_eta5_neg","_eta6_neg",       
};



class TRandom;
class TH1D;
class TH2D;



  class MjPlottingOps : public PlottingBase {

  public:

    MjPlottingOps(const std::string & filename, const Utils::ParameterSet& );
    ~MjPlottingOps();
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    // Variables Here
    std::string dirName_;
//    UInt_t nMin_;
//    UInt_t nMax_;
    double p0metparRes;
    double p1metparRes;
    double p0metperRes;
    double p1metperRes;
    double p0metparBias;
    double p1metparBias;
    double p2metparBias;  
    double p0metperBias;
    double p1metperBias; 
    double p2metperBias;    

    double lepRes;
    double lepScale;
    

    // Methods Here

    // Histograms here
    TH1F *h_sel[EtaCh_Bins]; 
    TH1F *h_cor[EtaCh_Bins]; 	
    TRandom *random;
  };



#endif // hadronic_include_MjPlottingOps_hh
