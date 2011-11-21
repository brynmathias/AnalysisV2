#ifndef hadronic_include_PreScaledTriggers_hh
#define hadronic_include_PreScaledTriggers_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include <iostream>
class TH1D;
class TH2D;

namespace Operation {

  class PreScaledTriggers : public PlottingBase {

  public:

    PreScaledTriggers( const Utils::ParameterSet& );
    ~PreScaledTriggers();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    std::string NomTrigger_;
    std::string DeNomTrigger_;
    bool Plots_;
    bool verb_;
    std::vector<TH1D*> HT_Nom;
    std::vector<TH1D*> HT_Denom;
    std::vector<TH2D*> preDenom;
    std::vector<TH1D*> OverLapCheck_;
    void Plots();
    bool Plots( Event::Data& );
    std::map< std::pair<int, int>, int > histMap_;
		std::map< int, std::pair<int,int> > runLumiMap_;
    int hIdxTrack_;
    };

  }

#endif // hadronic_include_PreScaledTriggers_hh
