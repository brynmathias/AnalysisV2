#ifndef ElectronFakeRate_hh
#define ElectronFakeRate_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;


namespace SSDL{
  class ElectronFakeRate : public PlottingBase {
  public:
    // Standard Operation methods.
    ElectronFakeRate(const std::string & filename,
		  Utils::ParameterSet &);
    ~ElectronFakeRate(); //!< Destructor.

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();

  private:
    std::string mFolderName;



    double mhtCut;
    double htCut;
    double upperMetCut;
    float w;
    TH2D* hAllEl;
    TH2D* hGoodEl;


  }; // ~ElectronFakeRate class
}
#endif

//






