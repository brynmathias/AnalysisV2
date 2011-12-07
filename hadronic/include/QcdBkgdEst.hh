#ifndef hadronic_include_QcdBkgdEst_hh
#define hadronic_include_QcdBkgdEst_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include <Math/PtEtaPhiE4D.h>

class TH1D;
class TH2D;
namespace Operation { class DeadECALCut; }
namespace Operation { class sumRecHitPtCut; }

typedef unsigned int uint;
typedef std::vector<LorentzV> LorentzVs;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<float> > PtEtaPhiE;

namespace temp { class mSuGraPlottingOps; } //@@ below!

namespace Operation {
  
  class QcdBkgdEst : public PlottingBase {
    
  public:
    
    QcdBkgdEst( const Utils::ParameterSet& );
    ~QcdBkgdEst();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );
    
    std::ostream& Description( std::ostream& );
    
  private:

    typedef std::vector<double> vdouble;
    typedef std::vector<vdouble> vvdouble;
    typedef std::vector<std::string> vstring;
    typedef std::vector<vstring> vvstring;
    int trigger( const Event::Data& ev, const vstring& triggers, bool use_prescaled = true );
    
    void binning();
    void BookHistos() {;} //@@ everything is done in Start()
    
    void calcDalitzVars( const std::vector<LorentzV>&, const std::vector<bool>&, const LorentzV&, double&, double& );

    Double_t DeadECALDR(TString, float, float, int );
    Double_t DeadECALDR( Event::Data&, float, float, int );
    Double_t DeadECALDR_File( TString, float, float, int );
    bool deadECALCut( Event::Data&, std::vector<LorentzV>&, LorentzV, std::vector<LorentzV>& );

    bool passVertexSumPtOverHt( Event::Data& ev, double ht = -1. );
    double minBiasDeltaPhi( const std::vector<LorentzV>& );
    
    void thresholds( std::string trigger, double& ht, double& mht, double& at );
    bool hltHt( const Event::Data& ev, double ht_cut );
    bool hltMht( const Event::Data& ev, double mht_cut );
    bool hltHtAlphaT( const Event::Data& ev, double ht_cut, double at_cut );
    
    // Typedefs for nested vectors (1D = multiplicity, 2D = HT or Meff, 3D = HT/Meff bins, 4D = AlphaT)
    typedef std::vector<TH1D*> vTH1D;
    typedef std::vector<vTH1D> vvTH1D;
    typedef std::vector<vvTH1D> vvvTH1D;
    typedef std::vector<vvvTH1D> vvvvTH1D;
    typedef std::vector<TH2D*> vTH2D;
    typedef std::vector<vTH2D> vvTH2D;
    typedef std::vector<vvTH2D> vvvTH2D;
    typedef std::vector<vvvTH2D> vvvvTH2D;
    
    //void fill( uint multi, double alpha_t, double at_cut, vTH1D&, double valx, double weight );
    void fill( uint multi, vTH1D&, double valx, double weight );
    void fill( uint multi, vTH2D&, double valx, double valy, double weight );
    void fill2d( uint multi, vTH2D&, double x, double y, double weight );
    
    std::string ht( int );
    std::string at( int );
    
  private:

    // Misc
    std::string dirName_;
    uint nMin_;
    uint nMax_;
    bool verbose_;
    int filter_;
    bool noQcd_;
    bool noCleaningInDenom_;
    double norm_;
    bool scale_;
    bool scaleSignal_;
    bool scaleSingle_;
    double maxLeadingJetEta_;
    double babyCut_;
    bool addMuon_;
    bool onlyGenPtHat_;
    bool onlyFull_;
    bool useMeff_;

    double deadEcalRegionDrCut_;
    double deadEcalRegionEtaCut_;
    double minJetPtCut_;
    int nBadCells_;
    bool useFile_;
    std::string deadECALfile_;
    double minBiasDeltaPhiCut_;
    DeadECALCut* dead_;

    sumRecHitPtCut* rechit_;
    
    // Analysis defaults (that define signal region)
    std::vector<double> alphaT_; 
    uint aT_; 
    unsigned int ht_;
    double pt1_;
    double pt2_;
    double pt3_;

    // Binning
    bool inclusive_;
    unsigned int htNbins_; 
    double htXlow_; 
    double htXhigh_; 
    std::vector<double> htBins_; 
    std::vector<double> htPt1Bins_; 
    std::vector<double> htPt2Bins_; 
    std::vector<double> htPt3Bins_; 
    double offset_;
    
    // HT RECO histograms
    vTH1D hGenPtHat_;
    vTH2D hSMS_;
    bool cutFlowHistos_;
    vvTH1D hCutFlow_;
    bool htHistos_;
    vvvTH1D hHtDistr_; 
    bool meffHistos_;
    vvvTH1D hMeffDistr_; 
    bool mhtHistos_;
    vvvTH1D hMhtDistr_; 
    bool mhtOverHtHistos_;
    vvvTH1D hMhtOverHtDistr_; 
    bool mhtOverMeffHistos_;
    vvvTH1D hMhtOverMeffDistr_; 
    bool multiHistos_; 
    vvvTH1D hMultiplicity_;
    bool jetPtHistos_;
    vvvTH1D hAllJetsPt_;
    vvvTH1D hRecoJetsPt_;
    vvvTH1D hBabyJetsPt_;
    bool vertexHistos_;
    vvvTH1D hNumVertex_;
    bool atHistos_;
    vvTH1D hAlphaT_;
    bool dalitzHistos_;
    vvTH2D hDalitz_;
    bool minBiasDeltaPhiHistos_; 
    vvvTH1D hMinBiasDeltaPhi_; 
    bool babyJetsHistos_;
    vvvTH1D hBabyJets_; 
    bool babyJetsMhtHistos_;
    vvvTH1D hBabyJetsMht_; 

    vvTH1D hPassAlphaT_; 
    vvTH1D hPassDeadEcal_; 
    vvTH1D hPassBaby_; 
    vvTH1D hPassTrackless_; 
    vvTH1D hPassRecHit_; 
    vvTH1D hPassMinBiasDPhi_; 
    vvTH1D hFailAlphaT_; 
    vvTH1D hFailDeadEcal_; 
    vvTH1D hFailBaby_; 
    vvTH1D hFailTrackless_; 
    vvTH1D hFailMinBiasDPhi_; 

    // Cntrs
    double cntr_baseline;
    double cntr_correct_reco_bin;
    double cntr_trigger_fired;
    double cntr_jet_multiplicity;
    double cntr_leading_jet_pt;
    double cntr_second_jet_pt;
    double cntr_leading_jet_eta;
    double cntr_odd_jet_veto;
    double cntr_bad_muon_in_jet;
    double cntr_at;
    double cntr_pass_dead_ecal;  
    double cntr_pass_baby_cut;
    double cntr_pass_pt_over_ht;
    double cntr_pass_rechit;

    std::vector<double> epochs_;
    vvstring signal_;
    vvstring monitor_;
    vvdouble reweight_;
    vstring names_;
    bool usePrescaled_;

  }; 

}

#endif // hadronic_include_QcdBkgdEst_hh
