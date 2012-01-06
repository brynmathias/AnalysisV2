#ifndef BkgFromFlip_hh
#define BkgFromFlip_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

namespace SSDL{
  class BkgFromFlip : public PlottingBase {
  public:
    // Standard Operation methods.
    BkgFromFlip(const std::string & filename,
		  Utils::ParameterSet &);
    ~BkgFromFlip(); //!< Destructor.

    double Weight(double pt, double eta);

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();

    TH1D* histOSDLDE;
    TH1D* histOSDLSE;
    TH1D* histSSDLDE_weight;
    TH1D* histSSDLSE_weight;

  private:
    std::string mFolderName;
    double mhtCut;
    double htCut;
    double leptonCut;
    double bin11,bin12,bin13;
    double bin21,bin22,bin23;
    double bin31,bin32,bin33;
    double bin41,bin42,bin43;
    double bin51,bin52,bin53;

    double printLep;
    bool mSugraScan;

    bool mcAnal;
 
    int nhdl[6][6];
    int nhsl[6][3];
    float w;

  }; // ~BkgFromFlip class
}
#endif

//






