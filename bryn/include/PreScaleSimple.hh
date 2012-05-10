#ifndef hadronic_include_PreScaleSimple_hh
#define hadronic_include_PreScaleSimple_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include <iostream>
class TH1D;
class TH2D;

namespace Operation {

  class PreScaleSimple : public PlottingBase {

  public:

    PreScaleSimple( const Utils::ParameterSet& );
    ~PreScaleSimple();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    std::vector<std::string> NomTrigger_;
    std::vector<std::string> DeNomTrigger_;
    bool Plots_;
    bool verb_;
    std::vector<TH1D*> HT_Nom;
    std::vector<TH1D*> HT_Denom;
    std::vector<TH1D*> AlphaT_Nom;
    std::vector<TH1D*> AlphaT_Denom;
    std::vector<TH1D*> MuPt_Denom;
    std::vector<TH1D*> MuPt_Nom;
    void Plots();
    bool Plots( Event::Data& );
    };

  }

#endif // hadronic_include_PreScaleSimple_hh
