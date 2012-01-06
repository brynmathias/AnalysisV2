#ifndef hadronic_include_HadronicPlottingOps_hh
#define hadronic_include_HadronicPlottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class HadronicPlottingOps : public PlottingBase {

  public:

    HadronicPlottingOps( const Utils::ParameterSet& );
    ~HadronicPlottingOps();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );
    
    static bool EventSummary( Event::Data&, bool gen = true );
    static bool EventDetail( Event::Data&, bool gen = true );
    static LorentzV RecoilMET( Event::Data& );

  private:

    void BookHistos();
    
    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    bool verbose_;
    
    // Dalitz plots
    bool dalitz_;
    std::vector<TH2D*> hDalitzRhoARhoB_;
    std::vector<TH2D*> hDalitzRhoARhoB2_;
    std::vector<TH2D*> hDalitzRhoARhoB3_;
    std::vector<TH2D*> hDalitzRhoARhoBn_;
    std::vector<TH2D*> hDalitzMTj1Mjj_;
    std::vector<TH2D*> hDalitzMTj2Mjj_;
    std::vector<TH2D*> hDalitzMTj1MTjj_;
    std::vector<TH2D*> hDalitzMTj2MTjj_;
    std::vector<TH2D*> hDalitzMT2j1M2jj_;
    std::vector<TH2D*> hDalitzMT2j2M2jj_;
    std::vector<TH2D*> hDalitzMT2j1MT2jj_;
    std::vector<TH2D*> hDalitzMT2j2MT2jj_;

    void dalitz();
    bool dalitz( Event::Data& );
    
    // AlphaT plots
    bool alphaT_;
    std::vector<TH1D*> hAlphaT_;
    std::vector<TH2D*> hAlphaTVal_;
    std::vector<TH2D*> hAlphaTnJets_;
    void alphaT();
    bool alphaT( Event::Data& );

    // Gen PtHat plots
    bool ptHat_;
    std::vector<TH1D*> hPtHat_;
    void ptHat();
    bool ptHat( Event::Data& );

    // MET plots
    bool met_;
    std::vector<TH1D*> hMetDiff1_;
    std::vector<TH1D*> hMetDiff2_;
    std::vector<TH1D*> hMetCC_;
    std::vector<TH1D*> hMetRaw_;
    std::vector<TH1D*> hMetCalo_;
    void met();
    bool met( Event::Data& );

    // Event summary
    bool summary_;
    bool summary( Event::Data& );

    // Cross-cleaning output
    bool cc_;
    bool cc( Event::Data& );
    
    // Kinematic plots
    bool kine_;
    std::vector<TH1D*> hEta_;
    std::vector<TH1D*> hDEta_;
    std::vector<TH1D*> hDR_;
    void kine();
    bool kine( Event::Data& );

    // Jet response plots
    bool response_;
    void response();
    bool response( Event::Data& );
    std::vector<TH2D*> hRespCorr_;
    std::vector<TH2D*> hRespEtaCorr_;
    std::vector<TH2D*> hRespRaw_;
    std::vector<TH2D*> hRespEtaRaw_;
    std::vector<TH2D*> hCorr_;
    std::vector<TH2D*> hJetID_;
    
  }; 

}

#endif // hadronic_include_HadronicPlottingOps_hh
