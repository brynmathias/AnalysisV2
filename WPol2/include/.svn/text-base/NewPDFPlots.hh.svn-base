#ifndef _NEWPDFPLOTS_HH_
#define _NEWPDFPLOTS_HH_

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
#include "Structures.hh"
#include "PolTransforms.hh"

#include "LHAPDF/LHAPDF.h"

namespace Operation {
 
  class NewPDFPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    NewPDFPlots(const std::string & foldername, const std::string & PDFSetName, int setID);
    ~NewPDFPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    std::string mPDFSetName;
    int mSetID;
    //Histograms
    TH1D * MC_CosThetaStar1PlusTest1;
    TH1D * MC_CosThetaStar1MinusTest1;
    TH1D * RECO_ICVarPFPlus;
    TH1D * RECO_ICVarPFPlus_LH;
    TH1D * RECO_ICVarPFPlus_RH;
    TH1D * RECO_ICVarPFPlus_LO;
    TH1D * RECO_ICVarPFMinus;
    TH1D * RECO_ICVarPFMinus_LH;
    TH1D * RECO_ICVarPFMinus_RH;
    TH1D * RECO_ICVarPFMinus_LO;
  }; //~NewPDFPlots class


} // ~namespace Operation
#endif
