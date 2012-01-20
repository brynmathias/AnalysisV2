#ifndef allhadronic_include_GenPtHat_hh
#define allhadronic_include_GenPtHat_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class GenPtHat : public PlottingBase {

  public:
    
    GenPtHat( const Utils::ParameterSet& );
    ~GenPtHat();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );
    void BookHistos() {;} //@@ everything is done in Start()
    
    std::ostream& Description( std::ostream& );
    
  private:
    
    typedef std::vector<TH1D*> vTH1D;

    std::string dirName_;
    vTH1D his_;
    
  }; 

}

#endif // allhadronic_include_GenPtHat_hh
