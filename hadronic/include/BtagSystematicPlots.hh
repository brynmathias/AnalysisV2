#ifndef hadronic_include_BtagSystematicPlots_hh
#define hadronic_include_BtagSystematicPlots_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class BtagSystematicPlots : public PlottingBase {

  public:

    BtagSystematicPlots( const Utils::ParameterSet& );
    ~BtagSystematicPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
    Double_t MT2( Event::Data& );
    Double_t MT2_Leading( Event::Data& );
    Double_t DeltaHT( Event::Data& );
    std::pair<LorentzV,LorentzV> PsudoJets(Event::Data&);
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


    //JetMultiplcity
    std::vector<TH1D*>  Multiplicity_;
    std::vector<TH1D*>  MultiplicityAfteraT_55_;

    //Number of vertices
    std::vector<TH1D*>  NumberVerticies_;
    std::vector<TH1D*>  NumberVerticiesAfterAlphaT_55_;

    //MHT
    std::vector<TH1D*>  MHT_;
    std::vector<TH1D*>  MHTAfteraT_55_;

    //Meff  
    std::vector<TH1D*>  Meff_;
    std::vector<TH1D*>  AlphatCut_Meff_55_;
    
    //Vertex Sum PtovHT
    std::vector<TH1D*>  vertexPtovHT_;
    std::vector<TH1D*>  vertexPtovHT_afterAlphaT_55_;

    //MHToverHT
    std::vector<TH1D*>  MHToverHT_;
    std::vector<TH1D*>  MHToverHT_afterAlphaT_55_;

//Jet Pt
    std::vector<TH1D*>  JetPt_;
    std::vector<TH1D*>  JetEta_; 
    std::vector<TH1D*>  Number_GenBJets_;
    std::vector<TH1D*>  Number_GenTauJets_;
    std::vector<TH1D*>  Number_Matched_GenBJets_;
    std::vector<TH1D*>  Number_Matched_Gen_NoBJets_;
    
    std::vector<TH1D*>  GenJetPt_;
    std::vector<TH1D*>  GenJetPt_noB_;

    std::vector<TH1D*>  GenPt_ov_RecoPt_;
    std::vector<TH1D*>  GenPt_ov_RecoPt_noB_;

    std::vector<TH1D*>  GenParticle_Ids_;
    std::vector<TH1D*>  GenParticle_Ids_Btagged_;
    std::vector<TH1D*>  GenParticle_B_Jet_Ids_;
    std::vector<TH1D*>  GenJetEta_;

    std::vector<TH1D*>  GenJetEta_noB_;
    std::vector<TH1D*>  GenJetEta_udsg_;
    std::vector<TH1D*>  GenJetEta_c_;

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
    std::vector<TH1D*>  Duplicate_GenJetEta_;
    std::vector<TH1D*>  Duplicate_GenJetPt_noB_;
    std::vector<TH1D*>  Duplicate_GenJetEta_noB_;
    std::vector<TH1D*>  JetPt_afterAlphaT_55_;
    std::vector<TH1D*>  JetEta_afterAlphaT_55_;

    //MHTovMET
    std::vector<TH1D*>  MHTovMET_;
    std::vector<TH1D*>  MHTovMET_afterAlphaT_55_;

    //Lepton Plots
    std::vector<TH1D*>  hLepTrIso_;
    std::vector<TH1D*>  hLepEIso_;
    std::vector<TH1D*>  hLepHIso_;
    std::vector<TH1D*>  hLepCIso_;

    std::vector<TH1D*>  hLepTrIso_afterAlphaT_55_;
    std::vector<TH1D*>  hLepEIso_afterAlphaT_55_;
    std::vector<TH1D*>  hLepHIso_afterAlphaT_55_;
    std::vector<TH1D*>  hLepCIso_afterAlphaT_55_;

    //Isolation Plots

    //Muon Pt
    std::vector<TH1D*>  hLepPt_;
    std::vector<TH1D*>  hLepPt_afterAlphaT_55_; 
    
    // MT
    std::vector<TH1D*>  hMT_;
    std::vector<TH1D*>  hMT_afterAlphaT_55_;

    std::vector<TH1D*> GenJet_DeltaR_noB_;
    std::vector<TH1D*> GenPt_minus_RecoPt_noB_;
 
    std::vector<TH2D*>  Matched_GenJetPt_vs_GenJetEta_;
    std::vector<TH2D*>  GenJetPt_vs_GenJetEta_;

    std::vector<TH2D*>  Matched_GenJetPt_vs_GenJetEta_noB_;
    std::vector<TH2D*>  GenJetPt_vs_GenJetEta_noB_;


    std::vector<TH1D*>  Number_Matched_Multiplicity_; 
    std::vector<TH1D*>  Number_Not_Matched_Multiplicity_;

    std::vector<TH1D*>  MHTOvCaloMET_;
    std::vector<TH1D*>  MHTOvCaloMET_Lepton_;
       

    void StandardPlots();
    bool StandardPlots( Event::Data& );

  };

}

#endif // hadronic_include_WeeklyUpdatePlots_hh
