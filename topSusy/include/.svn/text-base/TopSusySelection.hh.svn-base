#ifndef TopSusySelection_hh
#define TopSusySelection_hh

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

// Structure for leptons
struct lepton {
  double         charge;
  TLorentzVector vector;
  lepton(double c, TLorentzVector v) : charge(c), vector(v) {}
};

namespace TopSusy {
  class TopSusySelector : public PlottingBase {

    public :

      // Standard operation methods
      TopSusySelector(const std::string&, Utils::ParameterSet&);
      ~TopSusySelector();  //! Destructor

      void          BookHistos();                //! Virtual method---book histograms
      void          Start      (Event::Data&);   //! Start processing
      bool          Process    (Event::Data&);   //! Process event, return true if it passes operation
      std::ostream& Description(std::ostream&);  //! Describe operation, output analysis to terminal / log file
      void          createHistNames();
      double        getCorrD0  (double, double);
      double        getDeltaPhi(double, double);

    private :

      // Constants
      static const int    N_CUTS             = 7;
      static const double PI                 = 3.14159265;
      static const double MAX_BARREL_ABS_ETA = 1.442;
      static const double MIN_ENDCAP_ABS_ETA = 1.560;
      static const double BEAM_SPOT_X        = 0.0;
      static const double BEAM_SPOT_Y        = 0.0322;

      static const int    MIN_N_HITS           = 11;
      static const double MAX_ELEC_ABS_ETA     =  2.5;
      static const double MAX_MUON_ABS_ETA     =  2.1;
      static const double MAX_JET_ABS_ETA      =  2.4;
      static const double MAX_CORR_D0          =  0.2;
      static const double MAX_ELEC_REL_ISO     =  0.1;
      static const double MAX_MUON_REL_ISO     =  0.05;
      static const double MAX_NORM_CHI_2       = 10.0;
      static const double MIN_JET_ELEC_DELTA_R =  0.3;

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
      int    minNElecs, minNMuons, minNJets;
      double minHt,     minMht;
      double minElecEt, minMuonPt, minJetPt;

      // Histograms
      std::vector<TH1D*> h_nJets;
      std::vector<TH1D*> h_met,     h_wMt, h_m3;
      std::vector<TH1D*> h_elec1Et, h_jet1Pt;
      std::vector<TH1D*> h_elec1Eta;

      // Strings for name components
      std::vector<std::string> cutName;

      // Maps
      std::map<std::string, TH1D*> nJetsMap;
      std::map<std::string, TH1D*> metMap,     wMtMap, m3Map;
      std::map<std::string, TH1D*> elec1EtMap, jet1PtMap;
      std::map<std::string, TH1D*> elec1EtaMap;
  };  // ~TopSusySelector
}

#endif
