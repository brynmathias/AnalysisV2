#ifndef allhadronic_include_Validation_hh
#define allhadronic_include_Validation_hh

#include "Algorithms.hh"
#include "EventData.hh"
#include "PlottingBaseExtended.hh"
#include "Utils.hh"
#include <ostream>
#include <string>
#include <vector>

namespace allhadronic {
  
  /**
     Class that creates histograms needed for analysis
  */
  class Validation : public PlottingBaseExtended {
    
  public:
    
    
    Validation( const Utils::ParameterSet& );
    ~Validation();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );
    void BookHistos();
    
    std::ostream& Description( std::ostream& );
    
  private:

    // Instance of class that defines analysis
    Algorithms algos_;
    
    // Misc
    bool verbose_;
    std::string dir_;
    uint nMax_;

    // Variables
    std::vector<double> aT_;

    // Histograms
    vvTH1D hPreCleaning_; 
    vvTH1D hPostDeadEcal_; 
    vvTH1D hPostBaby_; 
    vvTH1D hPostTrackless_; 

    // Cntrs
    double cntr_baseline;
    double cntr_leading_jet_eta;
    double cntr_odd_jet_veto;
    double cntr_bad_muon_in_jet;
    double cntr_leading_jet_pt;
    double cntr_second_jet_pt;
    double cntr_correct_reco_bin;
    double cntr_jet_multiplicity;
    double cntr_at;
    double cntr_pass_dead_ecal;  
    double cntr_pass_baby_cut;
    
  }; 

}

#endif // allhadronic_include_Validation_hh
