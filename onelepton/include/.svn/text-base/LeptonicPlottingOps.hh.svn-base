#ifndef LeptonicPlottingOps_hh
#define LeptonicPlottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

#include "OneLepton.hh"

class TH1D;
class TH2D;

namespace Operation {

  class LeptonicPlottingOps : public PlottingBase {

  public:

    LeptonicPlottingOps( const std::string & foldername, const Utils::ParameterSet& );
    ~LeptonicPlottingOps();

    void Start( Event::Data& );
    double TriggerPrescale( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
    LorentzV RecoilMET( Event::Data& );

    std::string dirName_;
    
    UInt_t nMin_;
    UInt_t nMax_;
    //    bool verbose_;
    bool doGen_;

    bool usePrescale_;
    std::vector<std::string> mTriggers_;
    
    OneLepton::LeptonType leptonType_;
    //    std::string leptonType_;
    std::vector <Event::Lepton const *> theLepton_;

    // AlphaT plots
    bool alphaT_;
    std::vector<TH1D*> hAlphaT_;
    std::vector<TH1D*> hLepAlphaT_;
    std::vector<TH1D*> hHadAlphaT_;
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
    std::vector<TH1D*> hMetPF_; std::vector<TH1D*> hMetPFp_; std::vector<TH1D*> hMetPFm_;

    void met();
    bool met( Event::Data& );

    // Event summary
    bool summary_;
    bool summary(  Event::Data& );

    // Cross-cleaning output
    bool cc_;
    bool cc( Event::Data& );

    // Kinematic plots
    bool kine_;
    std::vector<TH1D*> hPrescale_;
    std::vector<TH1D*> hEta_;
    std::vector<TH1D*> hDEta_;

    std::vector<TH1D*> hDR_;
    std::vector<TH1D*> hDR_lepJet_;
    std::vector<TH1D*> hDR_lepComJet_;

    std::vector<TH1D*> hNjet_;
    std::vector<TH1D*> hJ1Et_, hJ2Et_, hJ3Et_;
    std::vector<TH1D*> hJ1Eta_, hJ2Eta_, hJ3Eta_;

    std::vector<TH1D*> hMT_; std::vector<TH1D*> hMTp_; std::vector<TH1D*> hMTm_;
    std::vector<TH1D*> hMT2_;
    std::vector<TH1D*> hM3_;
    std::vector<TH1D*> hLP_; std::vector<TH1D*> hLPp_; std::vector<TH1D*> hLPm_;
    std::vector<TH1D*> hPFMHT_;
    std::vector<TH1D*> hMHTsum_;

    std::vector<TH1D*> hHT_;
    std::vector<TH1D*> hHTlep_;
    std::vector<TH1D*> hHThad_;
    std::vector<TH1D*> hMeff_;
    std::vector<TH1D*> hnlMeff_;

    void kine();
    bool kine( Event::Data& );

    // Lepton object plots
    bool lep_;
    std::vector<TH1D*> lPt_; std::vector<TH1D*> lPtp_;  std::vector<TH1D*> lPtm_;
    std::vector<TH1D*> lEta_; std::vector<TH1D*> lEtap_; std::vector<TH1D*> lEtam_;
    std::vector<TH1D*> lPhi_; std::vector<TH1D*> lPhip_; std::vector<TH1D*> lPhim_;
    std::vector<TH1D*> lRelCombIso_;
    std::vector<TH1D*> lType_;

    void lepton();
    bool lepton(Event::Data& );

  };

}

#endif

