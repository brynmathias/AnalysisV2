//
//  examplePlotOps.hh
//  
//
//  Created by Bryn Mathias on 17/03/2011.
//  
// An example of a plotting operation




#ifndef hadronic_include_examplePlotOps_hh
#define hadronic_include_examplePlotOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {
  
  class examplePlotOps : public PlottingBase {
    
  public:
    
    examplePlotOps( const Utils::ParameterSet& );
    ~examplePlotOps();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );
    
    std::ostream& Description( std::ostream& );
    
  private:
    
    void BookHistos();
    
    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    
      // MT2
    bool example_;
    void example();
    bool example( Event::Data& );
    std::vector<TH1D*> alphaT_;

  };
  
}

#endif // hadronic_include_examplePlotOps_hh