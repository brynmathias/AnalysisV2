#ifndef EffPlotsAGB_hh
#define EffPlotsAGB_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include "EventData.hh"

namespace AGBTrig{

  class AGBTrigEffPlots : public PlottingBase {

  public:
    
    AGBTrigEffPlots( const Utils::ParameterSet&);
    ~AGBTrigEffPlots();

    void Start(Event::Data&);
    bool Process(Event::Data&);
    
    std::ostream& Description (std::ostream& );

  private:

    void BookHistos();
    

    std::string _dirName;
    double _TrigMHTcut, _JetPtThres;
    TH1D* pfCommonMHT, *pfCalcMHT, *pfCommonMHT_postCut, *pfGenMHT, *pfGenMHT_postCut, *matchedGenMHT, *matchedGenMHT_postCut, *JetsPt, *pfMET, *pfGenMET, *pfGenMET_postCut, *pfMET_postCut, *tauPt, *muPt, *elePt, *tauPt_postCut, *muPt_postCut, *elePt_postCut,*CommonHT, *CommonHT_postCut;

  };
}

#endif
