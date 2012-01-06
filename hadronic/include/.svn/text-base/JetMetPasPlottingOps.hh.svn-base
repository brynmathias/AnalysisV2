#ifndef hadronic_include_JetMetPasPlottingOps_hh
#define hadronic_include_JetMetPasPlottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class JetMetPasPlottingOps : public PlottingBase {

  public:

    JetMetPasPlottingOps( const Utils::ParameterSet& );
    ~JetMetPasPlottingOps();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();


    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    //Development Plots
    bool Plots_;
    std::vector<TH1D*> mht_xyOverSqrtHT;
    std::vector<TH1D*> met_xyOverSqrtET;
    std::vector<TH2D*> HTvsMHT_;
    std::vector<TH2D*> HTvsMHT_X_;
    std::vector<TH2D*> HTvsMHT_Y_;
    std::vector<TH2D*> CaloMetvsSUMET_;
    std::vector<TH1D*> CALO_MET_;
    std::vector<TH1D*> MET_Pt_;
    std::vector<TH1D*> MHT_X_;
    std::vector<TH1D*> MHT_Y_;
    std::vector<TH2D*> SumETvsHT_;
    std::vector<TH2D*> SumETvsMHT_;
    std::vector<TH2D*> CaloMetXvsSUMET_;
    std::vector<TH2D*> CaloMetYvsSUMET_;
    std::vector<TH2D*> MHTxVsMHTy_;
    std::vector<TH2D*> CaloMetXvsCaloMetY_;
    std::vector<TH2D*> MHTvsMET_;
    std::vector<TH2D*> HT_VS_ALPHAt_Common_;
    std::vector<TH2D*> HT_VS_ALPHAt_Jets_;
    std::vector<TH2D*> HT_VS_BiasedDeltaPhi_Common_;
    std::vector<TH2D*> HT_VS_BiasedDeltaPhi_Jets_;
    std::vector<TH2D*> HT_VS_BiasedDeltaPhi_killedJets_;
    void Plots();
    bool Plots( Event::Data& );

  };

}

#endif // hadronic_include_JetMetPasPlottingOps_hh
