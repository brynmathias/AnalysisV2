#ifndef QCDSelection_hh
#define QCDSelection_hh

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;



namespace TopSusy {
  class QCDSelector : public PlottingBase {
    
  public :
    
    // Standard operation methods
    QCDSelector(const std::string&, Utils::ParameterSet&);
    ~QCDSelector();  //! Destructor
    
    void          BookHistos();                //! Virtual method---book histograms
    void          Start      (Event::Data&);   //! Start processing
    bool          Process    (Event::Data&);   //! Process event, return true if it passes operation
    std::ostream& Description(std::ostream&);  //! Describe operation, output analysis to terminal / log file
    double        getCorrD0  (double, double);
    double        getDeltaPhi(double, double);
    
  private :
    
    // Constants
    
    static const double PI                 = 3.14159265;
    static const double MAX_BARREL_ABS_ETA = 1.442;
    static const double MIN_ENDCAP_ABS_ETA = 1.560;
    static const double BEAM_SPOT_X        = 0.0;
    static const double BEAM_SPOT_Y        = 0.0322;
    
    // Input variables
    std::string folderName_;
    
    // Class variables
    bool   passesCuts;
    int    nElecs,      nMuons, nJets;
    double eventWeight, ht,     mht;
    double chargeProd;
    double met,         wMt,    m3;
    double elec1Et,     jet1Pt;
    double elec1Eta;
    
    // Parameters from selection file
    int     minNElecs,     minNMuons,     minNJets;
    int     minNHits;
    double  minHt,         minMht;
    double  minElecEt,     minMuonPt,     minJetPt;
    double  maxElecAbsEta, maxMuonAbsEta, maxJetAbsEta;
    double  maxCorrD0;
    double  maxElecRelIso, maxMuonRelIso;
    double  maxNormChi2;
    double  minJetElecDeltaR;
    bool    applyLeptonVeto,invertedId;
    double  minSecondLeptonPt,maxNElecs,maxNMuons,maxNJets,maxHt,maxMht,minCorrD0;
    double  minDeltaphi, maxDeltaphi;
    double  maxElecTkIso;
      // Histograms
    TH1D*  h_el_pt;
    TH1D*  h_mu_pt;
    TH1D*  h_el_Wt;
    TH1D*  h_mu_Wt;
    TH1D*  h_el_Dphi;
    TH1D*  h_mu_Dphi;
    std::vector<TH1D*>  h_el_tkisol,h_el_ecalisol,h_el_hcalisol,h_el_combisol,h_el_relcombisol;
    std::vector<TH1D*>  h_mu_tkisol,h_mu_ecalisol,h_mu_hcalisol,h_mu_combisol,h_mu_relcombisol;
    
  };  // ~QCDSelector
}

#endif
