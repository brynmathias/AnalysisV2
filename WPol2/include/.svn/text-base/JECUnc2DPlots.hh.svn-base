#ifndef _JECUNC2DPLOTS_HH_
#define _JECUNC2DPLOTS_HH_

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
 
  class JECUnc2DPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    JECUnc2DPlots(const std::string & foldername);
    ~JECUnc2DPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    //Histograms
    TH1D * RECO_ICVarPFPlus;
    TH1D * RECO_ICVarPFMinus;
    TH2D * RECO_ICVarPFPlus_vs_JECUncSigma;
    TH2D * RECO_ICVarPFMinus_vs_JECUncSigma;
  }; //~JECUnc2DPlots class


} // ~namespace Operation
#endif
