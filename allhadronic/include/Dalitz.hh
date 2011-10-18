#ifndef allhadronic_include_Dalitz_hh
#define allhadronic_include_Dalitz_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include <Math/PtEtaPhiE4D.h>

class TH1D;
class TH2D;

typedef unsigned int uint;
typedef std::vector<LorentzV> LorentzVs;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<double> > PtEtaPhiE;

namespace Operation {

  class Dalitz : public PlottingBase {
    
  public:
    
    Dalitz( const Utils::ParameterSet& );
    ~Dalitz();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void binning();
    void BookHistos() {;} //@@ everything is done in Start()
    
    double calcDalitzVars( const std::vector<LorentzV>&, const LorentzV&, double&, double&, double& );
    
    double sigma3(double,double);
    double radius(double,double);
    double phi_AB(double,double);
    double phi_mB(double,double);
    
    // Typedefs for nested vectors (1D = multiplicity, 2D = HT or Meff, 3D = HT/Meff bins, 4D = AlphaT)
    typedef std::vector<TH1D*> vTH1D;
    typedef std::vector<vTH1D> vvTH1D;
    typedef std::vector<vvTH1D> vvvTH1D;
    typedef std::vector<vvvTH1D> vvvvTH1D;
    typedef std::vector<TH2D*> vTH2D;
    typedef std::vector<vTH2D> vvTH2D;
    typedef std::vector<vvTH2D> vvvTH2D;
    typedef std::vector<vvvTH2D> vvvvTH2D;
    
    void fill( uint multi, vTH1D&, double x, double weight );
    void fill( uint multi, vTH2D&, double x, double y, double weight );
    
    std::string ht( int );
    std::string meff( int );
    std::string at( int );
    
  private:

    // Misc
    bool doHtHistos_;
    bool doMeffHistos_;
    std::string dirName_;
    uint nMin_;
    uint nMax_;
    bool verbose_;
    double norm_;
    bool scale_;
    double maxJetEta_;
    double maxLeadingJetEta_;

    // Analysis defaults (that define signal region)
    std::vector<double> alphaT_; 
    double ht_;
    double meff_;
    double pt1_;
    double pt2_;
    double pt3_;

    // Binning

    uint htNbins_; 
    double htXlow_; 
    double htXhigh_; 
    std::vector<double> htBins_; 
    std::vector<double> htPt1Bins_; 
    std::vector<double> htPt2Bins_; 
    std::vector<double> htPt3Bins_; 
    uint meffNbins_; 
    double meffXlow_; 
    double meffXhigh_; 
    std::vector<double> meffBins_; 
    std::vector<double> meffPt1Bins_; 
    std::vector<double> meffPt2Bins_; 
    std::vector<double> meffPt3Bins_; 

    // Histos

    vTH1D gPtHatAllEvents_;
    
    vvTH2D hPreMeffRhoRho_;
    vvTH2D hPreMeffPhiPhi_;
    vvTH1D hPreMeffSigma3_;
    vvTH1D hPreMeffRadius_;
    vvTH1D hPreMeffAlphaT_;
    vvTH1D hPreMeffMht_;
    vvTH1D hPreMeffMt2_;
    vvTH1D hPreMeffCombo_;
    vvTH1D hPreMeffPhiAB_;
    vvTH1D hPreMeffPhimB_;
    
    vvTH2D hPostMeffRhoRho_;
    vvTH2D hPostMeffPhiPhi_;
    vvTH1D hPostMeffSigma3_;
    vvTH1D hPostMeffRadius_;
    vvTH1D hPostMeffAlphaT_;
    vvTH1D hPostMeffMht_;
    vvTH1D hPostMeffMt2_;
    vvTH1D hPostMeffCombo_;
    vvTH1D hPostMeffPhiAB_;
    vvTH1D hPostMeffPhimB_;

  }; 

}

#endif // allhadronic_include_Dalitz_hh
