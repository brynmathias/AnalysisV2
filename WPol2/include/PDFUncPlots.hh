#ifndef _PDFUNCPLOTS_HH_
#define _PDFUNCPLOTS_HH_

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

#include "LHAPDF/LHAPDF.h"

namespace Operation {
 
  class PDFUncPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    PDFUncPlots(const std::string & foldername);
    ~PDFUncPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    //Histograms
    TH1D * RECO_ICVarPFPlus[41];
    TH1D * RECO_ICVarPFPlus_LH[41];
    TH1D * RECO_ICVarPFPlus_RH[41];
    TH1D * RECO_ICVarPFPlus_LO[41];
    TH1D * RECO_ICVarPFMinus[41];
    TH1D * RECO_ICVarPFMinus_LH[41];
    TH1D * RECO_ICVarPFMinus_RH[41];
    TH1D * RECO_ICVarPFMinus_LO[41];
    //TH1D * MHTeffect;
  }; //~PDFUncPlots class


} // ~namespace Operation
#endif
