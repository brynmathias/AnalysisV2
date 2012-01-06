#ifndef hadronic_include_TanjaCCControlPlots_hh
#define hadronic_include_TanjaCCControlPlots_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

   class TanjaCCControlPlots : public PlottingBase {

  public:

    TanjaCCControlPlots( const Utils::ParameterSet& );
    ~TanjaCCControlPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
 
    std::string dirName_;

     LorentzV RecoilMET( Event::Data& );

     std::vector<TH1D*>  hCC_MHT_;
     std::vector<TH1D*>  hCC_MHTovHT_;     
     std::vector<TH1D*>  hCC_alphaT_;

     std::vector<TH1D*> hCCEleJet_CombRelIso_;
     std::vector<TH1D*>  hCCEleJet_Mult_;
     std::vector<TH2D*> hCCEleJet_MinDeltaR_vs_Pt_;
     std::vector<TH1D*>  hCCEleJet_MHT_;
     std::vector<TH1D*>  hCCEleJet_MHTovHT_;     
     std::vector<TH1D*>  hCCEleJet_alphaT_;

     std::vector<TH1D*> hCCPhotJet_CombRelIso_;
     std::vector<TH1D*>  hCCPhotJet_Mult_;
     std::vector<TH2D*> hCCPhotJet_MinDeltaR_vs_Pt_;
     std::vector<TH1D*>  hCCPhotJet_MHT_;
     std::vector<TH1D*>  hCCPhotJet_MHTovHT_;     
     std::vector<TH1D*>  hCCPhotJet_alphaT_;

     std::vector<TH1D*> hCCMuJet_CombRelIso_;
     std::vector<TH1D*>  hCCMuJet_Mult_;
     std::vector<TH1D*>  hCCMuJet_DeltaPtovPt_;
     std::vector<TH2D*> hCCMuJet_MinDeltaR_vs_Pt_; 
     std::vector<TH1D*>  hCCMuJet_MHT_;
     std::vector<TH1D*>  hCCMuJet_MHTovHT_;     
     std::vector<TH1D*>  hCCMuJet_alphaT_;
    
  }; 

}

#endif // hadronic_include_TanjaCCControlPlots_hh
