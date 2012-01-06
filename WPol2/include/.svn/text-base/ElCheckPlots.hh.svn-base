#ifndef _ELCHECKPLOTS_HH_
#define _ELCHECKPLOTS_HH_

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

namespace Operation {
 
  class ElCheckPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    ElCheckPlots(const std::string & foldername);
    ~ElCheckPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    //Histograms
    TH1D * RECO_pfMET;
    TH1D * RECO_pfMETPlus;
    TH1D * RECO_pfMETMinus;
    
    TH1D * RECO_LeptonPt;
    TH1D * RECO_LeptonPtPlus;
    TH1D * RECO_LeptonPtMinus;
    TH1D * RECO_LeptonEtaPlus;
    TH1D * RECO_LeptonEtaMinus;
    TH1D * RECO_LeptonEtaPlusAbs;
    TH1D * RECO_LeptonEtaMinusAbs;
    
    TH1D * RECO_ICVarPFPlus;
    TH1D * RECO_ICVarPFMinus;
    
    TH1D * RECO_TransMass;
    TH1D * RECO_TransMassPlus;
    TH1D * RECO_TransMassMinus;
    TH2D * RECO_lepEtavspfLP;
    TH2D * RECO_lepEtavspfLPPlus;
    TH2D * RECO_lepEtavspfLPMinus;

  }; //~ElCheckPlots class


} // ~namespace Operation
#endif
