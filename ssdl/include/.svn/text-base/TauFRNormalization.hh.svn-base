#ifndef TauFRNormalization_hh
#define TauFRNormalization_hh
#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

namespace SSDL{
  class TauFRNormalization : public PlottingBase {
  public:
    // Standard Operation methods.
    TauFRNormalization(const std::string & filename,
		  Utils::ParameterSet &);
    ~TauFRNormalization(); //!< Destructor.

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();

  private:
    std::string mFolderName;
    const static int dilepFinalStates   = 6;


    double mhtCut;
    double htCut;
    float w;
    TH2D* hGoodMuFakeTau;
    TH2D* hGoodElFakeTau;
    TH2D* hGoodTauFakeTau;
    TH1D* hFakeTauFakeTau;
    TH1D* hAllGoodWrongCharge;
    TTree *tree;
    float eta1;
    float pt1;
    float eta2;
    float pt2;
    float weight;
    int looseIso_;
    float uppermetcut_;
    string tauSrc;
    bool mUseHps;
  }; // ~TauFRNormalization class
}
#endif

//






