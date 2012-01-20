#ifndef LepIsoPlots_hh
#define LepIsoPlots_hh

#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh"
#include "PlottingBase.hh"

#include "TH1D.h"
#include "TH2D.h"

#include "Math/VectorUtil.h"

using namespace Event;

namespace SSDL {

  //=====================================
  // LEPTON ISOLATION PLOTTING OPERATION
  //=====================================

  /*! \brief  [Brief description here]
   *
   *  \date     24 April 2009
   *  \author   M. Weinberg
   *  \version  1.2
   */
  class LepIsoPlots : public PlottingBase {
    public :

    LepIsoPlots ( const std::string & folderName);

    ~LepIsoPlots();  //! < Destructor
    
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev);  
    void BookHistos();

    void plotIsoCutEff  (TH1D*, TH1D*);
    void plotRecoEff    (TH1D*, int,   TH1D*);
    void plotRecoPurity (TH1D*, TH1D*, TH1D*);
    std::ostream& Description(std::ostream& ostrm);
    private :
      // Operation private data members
      //--------------------------------

      // Input
      std::string mFolderName;  //! < ROOT folder name for histograms



      // Generator lepton counters
      int nGenLep [8];

      // Histograms

      // Isolation histograms
      std::vector <TH1D*> h_trackIso;
      std::vector <TH1D*> h_ecalIso;
      std::vector <TH1D*> h_hcalIso;
      std::vector <TH1D*> h_combIso;

      // Isolation cut efficiency histograms
      std::vector <TH1D*> h_trackIsoCut_cutEff;
      std::vector <TH1D*> h_ecalIsoCut_cutEff;
      std::vector <TH1D*> h_hcalIsoCut_cutEff;
      std::vector <TH1D*> h_combIsoCut_cutEff;

      // Reconstruction efficiency histograms
      std::vector <TH1D*> h_trackIsoCut_recoEff;
      std::vector <TH1D*> h_ecalIsoCut_recoEff;
      std::vector <TH1D*> h_hcalIsoCut_recoEff;
      std::vector <TH1D*> h_combIsoCut_recoEff;

      // Reconstruction purity histograms
      std::vector <TH1D*> h_trackIsoCut_recoPurity;
      std::vector <TH1D*> h_ecalIsoCut_recoPurity;
      std::vector <TH1D*> h_hcalIsoCut_recoPurity;
      std::vector <TH1D*> h_combIsoCut_recoPurity;

      // Reconstruction acceptance histograms
      std::vector <TH1D*> h_trackIsoCut_recoAccept;
      std::vector <TH1D*> h_ecalIsoCut_recoAccept;
      std::vector <TH1D*> h_hcalIsoCut_recoAccept;
      std::vector <TH1D*> h_combIsoCut_recoAccept;

      // Array for generator lepton counters
      // [0]: genIsoGenElec_ptLessThan15
      // [1]: genIsoGenElec_ptGreaterThan15
      // [2]: genNonIsoGenElec_ptLessThan15
      // [3]: genNonIsoGenElec_ptGreaterThan15
      // [4]: genIsoGenMuon_ptLessThan9
      // [5]: genIsoGenMuon_ptGreaterThan9
      // [6]: genNonIsoGenMuon_ptLessThan9
      // [7]: genNonIsoGenMuon_ptGreaterThan9

      // Vector for isolation histograms:
      // [0]:  patElec_ptLessThan15
      // [1]:  patElec_ptGreaterThan15
      // [2]:  genIsoPatElec_ptLessThan15
      // [3]:  genIsoPatElec_ptGreaterThan15
      // [4]:  genNonIsoPatElec_ptLessThan15
      // [5]:  genNonIsoPatElec_ptGreaterThan15
      // [6]:  fakePatElec_ptLessThan15
      // [7]:  fakePatElec_ptGreaterThan15
      // [8]:  patMuon_ptLessThan9
      // [9]:  patMuon_ptGreaterThan9
      // [10]: genIsoPatMuon_ptLessThan9
      // [11]: genIsoPatMuon_ptGreaterThan9
      // [12]: genNonIsoPatMuon_ptLessThan9
      // [13]: genNonIsoPatMuon_ptGreaterThan9
      // [14]: fakePatMuon_ptLessThan9
      // [15]: fakePatMuon_ptGreaterThan9

      // Vector for efficiency / purity / acceptance histograms
      // [0]: genIsoPatElec_ptLessThan15
      // [1]: genIsoPatElec_ptGreaterThan15
      // [2]: genNonIsoPatElec_ptLessThan15
      // [3]: genNonIsoPatElec_ptGreaterThan15
      // [4]: genIsoPatMuon_ptLessThan9
      // [5]: genIsoPatMuon_ptGreaterThan9
      // [6]: genNonIsoPatMuon_ptLessThan9
      // [7]: genNonIsoPatMuon_ptGreaterThan9
  };  // ~LepIsoPlots class
}
#endif
