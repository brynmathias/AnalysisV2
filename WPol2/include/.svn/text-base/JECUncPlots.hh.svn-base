#ifndef _JECUNCPLOTS_HH_
#define _JECUNCPLOTS_HH_

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TProfile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "Functions.hh"
#include "JECUnc_JetCorrectionUncertainty.hh"

namespace Operation {
 
  class JECUncPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    JECUncPlots(const std::string & foldername);
    ~JECUncPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    //Histograms
    TH1D * MHTeffect;
  }; //~JECUncPlots class


} // ~namespace Operation
#endif
