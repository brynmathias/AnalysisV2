#ifndef MuFakeRate_hh
#define MuFakeRate_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;


namespace SSDL{
  class MuFakeRate : public PlottingBase {
  public:
    // Standard Operation methods.
    MuFakeRate(const std::string & filename,
		  Utils::ParameterSet &);
    ~MuFakeRate(); //!< Destructor.

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
    TH2D* hGoodMu;
    TH2D* hAllMu;


  }; // ~MuFakeRate class
}
#endif

//






