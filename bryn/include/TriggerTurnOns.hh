#ifndef hadronic_include_TriggerTurnOns_hh
#define hadronic_include_TriggerTurnOns_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include <iostream>
class TH1D;
class TH2D;

namespace Operation {

  class TriggerTurnOns : public PlottingBase {

  public:

    TriggerTurnOns( const Utils::ParameterSet& );
    ~TriggerTurnOns();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    std::vector<TH1D*> MHT_;
    std::vector<TH1D*> AlphaT_;
    std::vector<TH1D*> HT_;
    std::vector<TH1D*> MEff_;
    std::vector<TH1D*> preScale_;
    bool ReWeight_;
    std::vector<std::string> ReWeightVec_;
    bool verb_;
    bool Plots_;
    void Plots();
    bool Plots( Event::Data& );

    };

  }

#endif // hadronic_include_TriggerTurnOns_hh