#ifndef _MC7to10_HH_
#define _MC7to10_HH_

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

namespace Operation {
 
  class MC7to10 : public PlottingBase {

  public:
    // Standard Operation methods.

    MC7to10(const std::string & foldername);
    ~MC7to10();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    //Histograms
    TH1D * MC_WPtMuonAcc;
    TH1D * MC_WPtPlusMuonAcc;
    TH1D * MC_WPtMinusMuonAcc;
  }; //~MC7to10 class


} // ~namespace Operation
#endif
