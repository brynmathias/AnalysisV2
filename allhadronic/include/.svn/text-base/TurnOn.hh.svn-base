#ifndef allhadronic_include_TurnOn_hh
#define allhadronic_include_TurnOn_hh

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
  class TurnOn : public PlottingBaseExtended {
    
  public:
    
    typedef std::map<std::string,bool> TurnOns;
    typedef TurnOns::const_iterator TurnOnsIter;
    typedef std::map<std::string,int> Prescales;
    typedef Prescales::const_iterator PrescalesIter;
    
    TurnOn( const Utils::ParameterSet& );
    ~TurnOn();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );
    void triggers( Event::Data& );
    void BookHistos();
    
    std::ostream& Description( std::ostream& );
    
  private:

    // Instance of class that defines analysis
    Algorithms algos_;

    // Misc
    bool verbose_;
    std::string dir_;
    int nMin_;
    int nMax_;
    
    // TurnOn
    std::vector<std::string> triggers_;
    std::vector<std::string> prefilters_;
    std::vector<std::string> variables_;
    std::vector<int> htbins_;
    
    // Histograms
    vvTH1D hTriggers_; 
    vvTH1D hPreFilters_; 
    vvTH1D hGiven_; 
    
  }; 

}

#endif // allhadronic_include_TurnOn_hh
