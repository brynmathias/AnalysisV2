#ifndef ElMuFRNormalization_hh
#define ElMuFRNormalization_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;


namespace SSDL{
  class ElMuFRNormalization : public PlottingBase {
  public:
    // Standard Operation methods.
    ElMuFRNormalization(const std::string & filename,
		  Utils::ParameterSet &);
    ~ElMuFRNormalization(); //!< Destructor.

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
    TH2D* hGoodMuFakeEl;
    TH2D* hGoodElFakeEl;
    TH2D* hGoodMuFakeMu;
    TH2D* hGoodElFakeMu;


  }; // ~ElMuFRNormalization class
}
#endif

//






