#ifndef hadronic_include_Muon_ControlPlots_hh
#define hadronic_include_Muon_ControlPlots_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class Muon_ControlPlots : public PlottingBase {

  public:

     Muon_ControlPlots( const Utils::ParameterSet& );
    ~Muon_ControlPlots();

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
    std::vector<TH1D*>  AlphaT_Zoomed_;
    std::vector<TH1D*>  AlphaT_Zero_Six_Vertices_;
    std::vector<TH1D*>  AlphaT_Seven_Ten_Vertices_;
    std::vector<TH1D*>  AlphaT_Gr_Ten_Vertices_;

    std::vector<TH1D*>  AlphaT_Lep_;
    std::vector<TH1D*>  AlphaT_Zoomed_Lep_;

    //HT Plots
    std::vector<TH1D*>  HT_Zero_Six_Vertices_;
    std::vector<TH1D*>  HT_Seven_Ten_Vertices_;
    std::vector<TH1D*>  HT_Gr_Ten_Vertices_;
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

    //BiasedDphi
    std::vector<TH1D*>  BiasedDphi_;
    std::vector<TH1D*>  AlphatCut_BiasedDphi_afterAlphaT_55_;

    //Delta Phi leading subleading jets
    std::vector<TH1D*>  DetlaPhi_LeadingJets_;
    std::vector<TH1D*>  DetlaPhi_NextToLeadingJets_;
    std::vector<TH1D*>  DetlaPhi_LeadingJets_afterAlphaT_55_;
    std::vector<TH1D*>  DetlaPhi_NextToLeadingJets_afterAlphaT_55_;

    //Jet Pt
    std::vector<TH1D*>  JetPt_;
    std::vector<TH1D*>  JetEta_;
    std::vector<TH1D*>  JetPt_afterAlphaT_55_;
    std::vector<TH1D*>  JetEta_afterAlphaT_55_;

    //MHTovMET
    std::vector<TH1D*>  MHTovMET_;
    std::vector<TH1D*>  MHTovMET_afterAlphaT_55_;

    //Misc
    std::vector<TH1D*>  DPhi_MHT_MHTBaby_;
    std::vector<TH1D*>  DPhi_MET_MHTBaby_;
    std::vector<TH1D*>  DPhi_MET_MHT_;
    std::vector<TH1D*>  MissedHT_;

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

    //Muon Pt
    std::vector<TH1D*>  hLepEta_;
    std::vector<TH1D*>  hLepEta_afterAlphaT_55_; 
    
    // MT
    std::vector<TH1D*>  hMT_;
    std::vector<TH1D*>  hMT_afterAlphaT_55_;


    std::vector<TH1D*>  Mu_Inner_Track_Hits_;
    std::vector<TH1D*>  Mu_Global_Track_Hits_;
    std::vector<TH1D*>  Mu_Delta_R_;
    std::vector<TH1D*>  MHTOvCaloMET_;
    std::vector<TH1D*>  MHTOvCaloMET_Lepton_;



    void StandardPlots();
    bool StandardPlots( Event::Data& );

  };

}

#endif // hadronic_include_Muon_ControlPlots_hh
