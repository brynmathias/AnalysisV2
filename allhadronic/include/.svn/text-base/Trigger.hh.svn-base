#ifndef allhadronic_include_Trigger_hh
#define allhadronic_include_Trigger_hh

#include "Algorithms.hh"
#include "EventData.hh"
#include "Operation.hh"
#include "Utils.hh"
#include <string>
#include <vector>

class TFile;

namespace allhadronic {
  
  /**
     Class that creates histograms needed for analysis
  */
  class Trigger : public Operation::_Base { 
    
  public:
    
    Trigger( const Utils::ParameterSet& );
    ~Trigger() {;}
    
    void Start( Event::Data& );
    void End( Event::Data& );
    bool Process( Event::Data& );
    
    std::ostream& Description( std::ostream& );
    
  private:

    // Instance of class that defines analysis
    Algorithms algos_;
    
    Algorithms::Triggers triggers_;
    
    // Misc
    bool verbose_;
    std::vector<std::string> filters_;
    int vs_;
    TFile* file_;
    
  }; 

}

#endif // allhadronic_include_Trigger_hh
