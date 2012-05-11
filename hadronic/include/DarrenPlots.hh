#ifndef hadronic_include_DarrenPlots_hh
#define hadronic_include_DarrenPlots_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include "DeadECALDR.hh"

class TH1D;
class TH2D;

namespace Operation {

  class DarrenPlots : public PlottingBase {

  public:

    DarrenPlots( const Utils::ParameterSet& );
    ~DarrenPlots();

    void Start( Event::Data& );
   bool Process( Event::Data& );
    void BookHistos();

    std::ostream& Description( std::ostream& );

  private:

    //  void BookHistos();
    Double_t MT2( Event::Data& );
    Double_t MT2_Leading( Event::Data& );
    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;

    bool MHTMETPlots_;
    bool MHTPlots_;
    bool CleaningPlots_;
    std::string deadECALFile_;

    double deadECAL_minJetPTCut_;
    double deadECAL_minBiasCut_;
    int deadECAL_nBadCellsCut_;
    
   
    //Cleaning Plots

    std::vector<TH1D*>  BiasedDphi_;
    std::vector<TH1D*> BadJetECALDR_;
    std::vector<TH1D*> allMinECALDR_;
    std::vector<TH1D*> TPMHT_;
    std::vector<TH1D*> TPHT_;
    std::vector<TH1D*> TPMHTRatio_;
    std::vector<TH2D*> TPHT_vs_BadJetECALDR_;
    std::vector<TH2D*> EtaPhi_DeadECAL_;
    std::vector<TH2D*> EtaPhi_realDeadECAL_;
    std::vector<TH2D*> MisMeasured_Eta_Phi_;
    void CleaningPlots();
    bool CleaningPlots( Event::Data& );
    

    //MHTMET Plots
    std::vector<TH1D*> MHTOvCaloMET_;
    std::vector<TH1D*> BiasedDphi_pT50GeV_;
    void MHTMETPlots();
    bool MHTMETPlots( Event::Data& );


    //MHTPlots
    std::vector<TH1D*> CaloMHT_;
    std::vector<TH1D*> MHT_;
    std::vector<TH1D*> HT_;
    std::vector<TH1D*> AlphaT_;
    void MHTPlots();
    bool MHTPlots( Event::Data& );
    };


 
  }


#endif // hadronic_include_DarrenPlots_hh
