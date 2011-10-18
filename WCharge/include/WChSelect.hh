#ifndef WChSelect_hh
#define WChSelect_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;


class WChSelect : public PlottingBase {
public:
  // Standard Operation methods.
  WChSelect(const std::string & filename,
	    Utils::ParameterSet &);
  ~WChSelect(); //!< Destructor.
  
  void Start(Event::Data & ev); //!< Start processing
  bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
  
  std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
  void BookHistos();
  
private:
  std::string mFolderName;

  TH1D *PosEta;
  TH1D *EleEta;
  TH1D *McPosEta;
  TH1D *McEleEta;
  TH1D *McPosEtaWC;
  TH1D *McEleEtaWC;
  TH1D *fbremElg;
  TH1D *fbremElw;
  TH1D *sigmaetaElg;
  TH1D *sigmaetaElw;
  
  
  float elecPt;
  float metLowerCut;
  float metUpperCut;
  float fbremCut;
  bool  mcAnal;
  bool useEcal;
  bool chChk;
}; // ~WChSelect class

#endif







