#ifndef JetTriggerSelection_hh
#define JetTriggerSelection_hh

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

namespace TopSusy {
  class JetTriggerSelector : public PlottingBase {

    public :

      // Standard operation methods
      JetTriggerSelector(const std::string&, Utils::ParameterSet&);
      ~JetTriggerSelector();  //! Destructor

      void          BookHistos();                //! Virtual method---book histograms
      void          Start      (Event::Data&);   //! Start processing
      bool          Process    (Event::Data&);   //! Process event, return true if it passes operation
      std::ostream& Description(std::ostream&);  //! Describe operation, output analysis to terminal / log file
      void          createHistNames();
      void          createHltNames();
      double        getDeltaPhi(double, double);

    private :

      // Constants
      static const int    N_CUTS          =  4;
      static const int    N_TRIG_BITS     =  7;
      static const double PI              =  3.14159265;
      static const double MAX_JET_ABS_ETA =  2.4;
      static const double MIN_JET_PT      = 30.0;

      // Input variables
      std::string folderName_;

      // Class variables
      bool   passesInitTrig, passesJetMetTrigs, passesEffTrigs, passesCuts;
      int    nJets;
      double eventWeight;
      double jet1Pt,         jet2Pt,            jet3Pt,         jet4Pt;
      double jet12DeltaEta,  jet12DeltaPhi;

      // Parameters from selection file
      int                      minNJets;
      double                   minJetPt;
      std::string              initTrigBit;
      std::vector<std::string> effTrigBit;

      // Histograms
      std::vector<TH1D*> h_nJets;
      std::vector<TH1D*> h_jet1Pt,        h_jet2Pt, h_jet3Pt, h_jet4Pt;
      std::vector<TH1D*> h_jet12DeltaEta, h_jet12DeltaPhi;

      // Strings for name components
      std::vector<std::string> cutName, hltName;

      // Maps
      std::map<std::string, TH1D*> nJetsMap;
      std::map<std::string, TH1D*> jet1PtMap,        jet2PtMap, jet3PtMap, jet4PtMap;
      std::map<std::string, TH1D*> jet12DeltaEtaMap, jet12DeltaPhiMap;
  };  // ~JetTriggerSelector
}

#endif
