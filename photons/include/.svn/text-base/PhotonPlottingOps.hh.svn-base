#ifndef photons_include_PhotonPlottingOps_hh
#define photons_include_PhotonslottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include "PhotonCompute.hh"

class TH1D;
class TH2D;

namespace Operation {

class StandardPlots : public PlottingBase {

  public:

    StandardPlots( const Utils::ParameterSet& );
    ~StandardPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    std::string variable_;
    Double_t valueMin_;
    UInt_t nBins_;
    Double_t binWidth_;
    std::vector<double> weights_1_;
    std::vector<double> weights_2_;
    std::vector<double> weights_3_;

    std::vector<TH1D*>  nVertices_;
    std::vector<TH1D*>  nJets_;
    std::vector<TH1D*>  HT_;
    std::vector<TH1D*>  Meff_;
    std::vector<TH1D*>  BiasedDphi_;
    std::vector<TH1D*>  MHToverHT_;
    std::vector<TH1D*>  HTover2SinDeltaPhi_;
    std::vector<TH1D*>  MHT_;
    std::vector<TH1D*>  ak5CaloMET_;
    std::vector<TH1D*>  pfMET_;
    std::vector<TH1D*>  tcMET_;
    std::vector<TH1D*>  PhotonPt_;
    std::vector<TH1D*>  PhotonEta_;
    std::vector<TH1D*>  PhotonEcalIso_;
    std::vector<TH1D*>  PhotonHcalIso_;
    std::vector<TH1D*>  PhotonTrackIso_;
    std::vector<TH1D*>  PhotonHoverE_;
    std::vector<TH1D*>  PhotonSigmaIetaIeta_;
    std::vector<TH1D*>  PhotonR9_;
    std::vector<TH1D*>  PhotonHasPixelSeed_;
    std::vector<TH1D*>  PhotonMETdPhi_;
    std::vector<TH1D*>  Jet1Pt_;
    std::vector<TH1D*>  Jet1Eta_;
    std::vector<TH1D*>  Jet1EmFrac_;
    std::vector<TH1D*>  Jet2Pt_;
    std::vector<TH1D*>  Jet2Eta_;
    std::vector<TH1D*>  Jet2EmFrac_;

    };

class EfficiencyPlots : public PlottingBase {

  public:

    EfficiencyPlots( const std::string& , const std::string&);
    ~EfficiencyPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    std::string genStatus_;
    TH1D *h_eta_all_, *h_pt_all_;
    TH1D *h_eta_pass_, *h_pt_pass_;
    TH1D *h_eta_matched_, *h_pt_matched_;
    TH1D *h_eta_matched_pass_, *h_pt_matched_pass_;
    TH1D *h_efficiency_;
    double mEtCut;
    double mEtaCut;

}; 

class HtPlot : public PlottingBase {

  public:

    HtPlot( const std::string& );
    ~HtPlot();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    TH1D *h_ht_;

};

class TriggerPlots : public PlottingBase {

  public:

    TriggerPlots( const std::string& );
    ~TriggerPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    TH1D *h_pfMET_;
    TH1D *h_HT_;
    TH1D *h_MHT_;

};

class GenPtHatPlots : public PlottingBase {

  public:

    GenPtHatPlots( const std::string& );
    ~GenPtHatPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    TH1D *h_pthat_;

};

class SpikePlots : public PlottingBase {

  public:

    SpikePlots( const std::string& );
    ~SpikePlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    TH1D *h_superClusterPhiWidth_;
    TH1D *h_superClusterEtaPhiWidth_;
    TH1D *h_superClusterEnergy_;
    TH1I *h_superClusterNXtals_;
    TH1D *h_swissCross_;
    TH1D *h_e2overE9_;
    TH1D *h_sigmaIetaIeta_;
    TH1D *h_seedTime_;
    TH1D *h_time2_;
    TH1D *h_seedEnergy_;
    TH1D *h_energy2_;
    TH1D *h_e2x2_;
    TH1D *h_e3x3_;
    TH1D *h_e4x4_;
    TH1D *h_e5x5_;
    TH1D *h_e2x2overE3x3_;
    TH1D *h_e2x2overE4x4_;
    TH1D *h_e2x2overE5x5_;
    TH1D *h_e2x2overEsc_;
    TH2D *h_sigmaIetaIeta_seedTime_;
    TH2D *h_sigmaIetaIphi_seedTime_;
    TH2D *h_sigmaIphiIphi_seedTime_;
    TH2D *h_e2overE9_seedTime_;
    TH2D *h_e2x2overE3x3_seedTime_;
    TH2D *h_e2x2overE4x4_seedTime_;
    TH2D *h_e2x2overE5x5_seedTime_;
    TH2D *h_e2x2overEsc_seedTime_;
    TH2D *h_swissCross_seedTime_;
    TH2D *h_sigmaIetaIeta_time2_;
    TH2D *h_sigmaIetaIphi_time2_;
    TH2D *h_sigmaIphiIphi_time2_;
    TH2D *h_e2overE9_time2_;
    TH2D *h_e2x2overE3x3_time2_;
    TH2D *h_e2x2overE4x4_time2_;
    TH2D *h_e2x2overE5x5_time2_;
    TH2D *h_e2x2overEsc_time2_;
    TH2D *h_swissCross_time2_;
    TH2D *h_seedTime_t2_;

};

class PhotonPlots : public PlottingBase {

  public:

    PhotonPlots(const std::string &, UInt_t);
    ~PhotonPlots();
    
    void Start(Event::Data &);
    bool Process(Event::Data &);
    std::ostream& Description(std::ostream&);
    void BookHistos();
    
  private:

    std::string mFolderName;
    UInt_t numphotons_;

    std::vector<TH1D *> hg_multi_;
    std::vector<TH1D *> hg_Et_;
    std::vector<TH1D *> hg_eta_;
    std::vector<TH1D *> hg_ecalIso_;
    std::vector<TH2D *> hg_ecalIso_Et_;
    std::vector<TH1D *> hg_hcalIso_;
    std::vector<TH2D *> hg_hcalIso_Et_;
    std::vector<TH1D *> hg_trackIso_;
    std::vector<TH2D *> hg_trackIso_Et_;
    std::vector<TH1D *> hg_hadronicOverEm_;
    std::vector<TH1D *> hg_r9_;
    std::vector<TH1D *> hg_sigmaIetaIeta_;
    std::vector<TH1D *> hg_hasPixelSeed_;

};

class SignalScan : public PlottingBase {

  public:

    SignalScan(const std::string &);
    ~SignalScan();
    
    void Start(Event::Data &);
    bool Process(Event::Data &);
    std::ostream& Description(std::ostream&);
    void BookHistos();
    
  private:

    std::string dirName_;

    TH2D *h_mChi50_;
    TH2D *h_mChi150_;
    TH2D *h_mChi500_;
    TH2D *h_mChi1000_;

};

class EBDeadTT : public PlottingBase {

  public:

    EBDeadTT(const std::string &);
    ~EBDeadTT();
    
    void Start(Event::Data &);
    bool Process(Event::Data &);
    std::ostream& Description(std::ostream&);
    void BookHistos();
    
  private:

    std::string dirName_;

    TH2D *h_eb_;

};

/*
class StandardPlots : public PlottingBase {

  public:

    StandardPlots( const Utils::ParameterSet& );
    ~StandardPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    std::string variable_;
    Double_t valueMin_;
    UInt_t nBins_;
    Double_t binWidth_;

    std::vector<TH1D*>  HT_;
    std::vector<TH1D*>  Meff_;
    std::vector<TH1D*>  BiasedDphi_;
    std::vector<TH1D*>  MHToverHT_;
    std::vector<TH1D*>  MHT_;
    std::vector<TH1D*>  ak5CaloMET_;
    std::vector<TH1D*>  pfMET_;
    std::vector<TH1D*>  tcMET_;
    std::vector<TH1D*>  PhotonPt_;
    std::vector<TH1D*>  PhotonEta_;
    std::vector<TH1D*>  PhotonEcalIso_;
    std::vector<TH1D*>  PhotonHcalIso_;
    std::vector<TH1D*>  PhotonTrackIso_;
    std::vector<TH1D*>  PhotonHoverE_;
    std::vector<TH1D*>  PhotonSigmaIetaIeta_;
    std::vector<TH1D*>  PhotonR9_;
    std::vector<TH1D*>  PhotonHasPixelSeed_;
    std::vector<TH1D*>  Jet1Pt_;
    std::vector<TH1D*>  Jet1Eta_;
    std::vector<TH1D*>  Jet1EmFrac_;
    std::vector<TH1D*>  Jet2Pt_;
    std::vector<TH1D*>  Jet2Eta_;
    std::vector<TH1D*>  Jet2EmFrac_;

};
*/

}

#endif
