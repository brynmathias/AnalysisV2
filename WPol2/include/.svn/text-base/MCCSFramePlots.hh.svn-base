#ifndef _MCCSFramePlots_HH_
#define _MCCSFramePlots_HH_

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TProfile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "Structures.hh"
#include "Functions.hh"
#include "PolTransforms.hh"

namespace Operation {
 
  class MCCSFramePlots : public PlottingBase {

  public:
    // Standard Operation methods.

    MCCSFramePlots(const std::string & foldername, const std::string & VBoson);
    ~MCCSFramePlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    bool forW;
    bool forZ;
    std::string mFolderName;
    std::string mVBoson;

    //Histograms
    TH1D * MC_CSWMuonPlusPhi;
    TH1D * MC_CSWMuonPlusPhi_A;
    TH1D * MC_CSWMuonPlusPhi_B;
    TH1D * MC_CSWMuonPlusPhi_C;
    TH1D * MC_CSWMuonAccPlusPhi;
    TH1D * MC_CSWMuonAccPlusPhi_A;
    TH1D * MC_CSWMuonAccPlusPhi_B;
    TH1D * MC_CSWMuonAccPlusPhi_C;
    TH1D * MC_CSWMuonPlusPhi2;
    TH1D * MC_CSWMuonMinusPhi;
    TH1D * MC_CSWMuonMinusPhi_A;
    TH1D * MC_CSWMuonMinusPhi_B;
    TH1D * MC_CSWMuonMinusPhi_C;
    TH1D * MC_CSWMuonAccMinusPhi;
    TH1D * MC_CSWMuonAccMinusPhi_A;
    TH1D * MC_CSWMuonAccMinusPhi_B;
    TH1D * MC_CSWMuonAccMinusPhi_C;
    TH1D * MC_CSWMuonMinusPhi2;
    TH1D * MC_CSWMuonPlusCosTheta;
    TH1D * MC_CSWMuonPlusCosTheta_A;
    TH1D * MC_CSWMuonPlusCosTheta_B;
    TH1D * MC_CSWMuonPlusCosTheta_C;
    TH1D * MC_CSWMuonAccPlusCosTheta;
    TH1D * MC_CSWMuonAccPlusCosTheta_A;
    TH1D * MC_CSWMuonAccPlusCosTheta_B;
    TH1D * MC_CSWMuonAccPlusCosTheta_C;
    TH1D * MC_CSWMuonMinusCosTheta;

    TH1D * MC_CSWA0Numerator;
    TH1D * MC_CSWA1Numerator;
    TH1D * MC_CSWA2Numerator;
    TH1D * MC_CSWA3Numerator;
    TH1D * MC_CSWA4Numerator;

    TH1D * MC_CSWMinusA0Numerator;
    TH1D * MC_CSWMinusA1Numerator;
    TH1D * MC_CSWMinusA2Numerator;
    TH1D * MC_CSWMinusA3Numerator;
    TH1D * MC_CSWMinusA4Numerator;

    TH1D * MC_CSWPlusA0Numerator;
    TH1D * MC_CSWPlusA1Numerator;
    TH1D * MC_CSWPlusA2Numerator;
    TH1D * MC_CSWPlusA3Numerator;
    TH1D * MC_CSWPlusA4Numerator;

    TH1D * MC_CSWAiDenominator;
    TH1D * MC_CSWPlusAiDenominator;
    TH1D * MC_CSWMinusAiDenominator;

    TH1D * MC_CSWPzSol1PhiDiff;
    TH1D * MC_CSWPzSol2PhiDiff;
    TH1D * MC_CSWPzDiff;

    TH2D * MC_CSWM_WMT;
  }; //~MCCSFramePlots class

} // ~namespace Operation
#endif
