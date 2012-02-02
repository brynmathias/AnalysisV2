#ifndef trigger_include_EffPlots_hh
#define trigger_include_EffPlots_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class EffPlots : public PlottingBase {

  public:

    EffPlots( const Utils::ParameterSet& );
    ~EffPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    bool EffPlots_;
    void Plots();
    bool Plots( Event::Data& );
    std::vector<TH1D*>  LeptonicAlphaT_;
    std::vector<TH1D*>  HadronicAlphaT_;
    std::vector<TH1D*>  HT_;
    std::vector<TH1D*>  Meff_;
    std::vector<TH1D*>  MHT_;
    std::vector<TH1D*>  MHTovHT_;
    std::vector<TH1D*>  HadronicAlphaTGeq3_;
    };

  }

#endif // trigger_include_EffPlots_hh
