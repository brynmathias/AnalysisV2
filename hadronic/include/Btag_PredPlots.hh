#ifndef hadronic_include_Btag_PredPlots_hh
#define hadronic_include_Btag_PredPlots_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class Btag_PredPlots : public PlottingBase {

  public:

    Btag_PredPlots( const Utils::ParameterSet& );
    ~Btag_PredPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    std::vector<double> GenPt_;
    std::vector<double> GenEta_;
    std::vector<double> Pt_Eta_Eff_;
    std::vector<double> Mistag_GenPt_;
    std::vector<double> Mistag_GenEta_;
    std::vector<double> Mistag_Pt_Eta_Eff_;
    std::vector<double> JetPt_High_;
    std::vector<double> JetPt_Low_;
    std::vector<double> Variation_;

    bool StandardPlots_;

    // AlphaT Plots
    std::vector<TH1D*>  AlphaT_;

    //HT Plots
    std::vector<TH1D*>  HT_;
    std::vector<TH1D*>  AlphatCut_HT_55_;

    //Btag plots
    std::vector<TH1D*>  BtagPreAlphaT_5_;
    std::vector<TH1D*>  BtagAfterAlphaT_5_55_;

    std::vector<TH1D*>  GenJetPt_;
    std::vector<TH1D*>  GenJetPt_noB_;

    std::vector<TH1D*>  GenPt_ov_RecoPt_;
    std::vector<TH1D*>  GenPt_ov_RecoPt_noB_;

    std::vector<TH1D*>  GenJetEta_;
    std::vector<TH1D*>  GenJetEta_noB_;

    std::vector<TH2D*>  MatchedB_vs_Matched_noB_;
    std::vector<TH2D*>  MatchedB_vs_Matched_noB_alphaT_;

    std::vector<TH1D*>  Btagged_GenJetPt_;
    std::vector<TH1D*>  Btagged_GenJetPt_SFb_;
    std::vector<TH1D*>  Btagged_GenJetPt_SFb_plus_;
    std::vector<TH1D*>  Btagged_GenJetPt_SFb_minus_;

    std::vector<TH1D*>  Btagged_GenJetEta_;

    std::vector<TH1D*>  NotMatched_RecoJet_;
    std::vector<TH1D*>  Btagged_NotMatched_RecoJet_;

    std::vector<TH1D*>  Btagged_GenJetPt_noB_;
    std::vector<TH1D*>  Btagged_GenJetPt_noB_SFlight_;
    std::vector<TH1D*>  Btagged_GenJetPt_noB_SFlight_plus_;
    std::vector<TH1D*>  Btagged_GenJetPt_noB_SFlight_minus_;
    std::vector<TH1D*>  Btagged_GenJetEta_noB_;

    std::vector<TH1D*>  Duplicate_GenJetPt_;

    std::vector<TH1D*> GenPt_minus_RecoPt_noB_;
 
    std::vector<TH2D*>  Matched_GenJetPt_vs_GenJetEta_noB_;
    std::vector<TH2D*>  GenJetPt_vs_GenJetEta_noB_;

    void StandardPlots();
    bool StandardPlots( Event::Data& );

  };

}

#endif // hadronic_include_Btag_PredPlots_hh
