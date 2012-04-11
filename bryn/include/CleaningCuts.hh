#ifndef hadronic_include_CleaningCuts_hh
#define hadronic_include_CleaningCuts_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class CleaningCuts : public PlottingBase {

  public:

    CleaningCuts( const Utils::ParameterSet& );
    ~CleaningCuts();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;

    bool CleaningPlots_;
    std::vector<TH1D*>  AlphaT_;
    std::vector<TH1D*>  MHTovMET_raw_;


    void CleaningPlots();
    bool CleaningPlots( Event::Data& );

  };

}

#endif // hadronic_include_CleaningCuts_hh
