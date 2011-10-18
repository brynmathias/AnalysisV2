#ifndef _MCPolPlots_HH_
#define _MCPolPlots_HH_

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
 
  class MCPolPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    MCPolPlots(const std::string & foldername);
    ~MCPolPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    TLorentzVector jGenMu, jRestMu1, jRestMu2, jMHT, jSol1, jSol2;
    TVector3 jSol1Boost, jSol2Boost;
    double CosThetaStar1Sol1, CosThetaStar1Sol2;
    jSolutionsW jMCSol;

    //Histograms
    TH1D * MC_MHT;
    TH1D * MC_MuonPt;
    TH1D * MC_MuonEta;
    TH1D * MC_MuonMultiplicity;
    TH1D * MC_ICVarPlus;
    TH1D * MC_ICVarMinus;
    TH1D * MC_CosThetaStar1Sol1Plus;
    TH1D * MC_CosThetaStar1Sol2Plus;
    TH1D * MC_CosThetaStar1Sol1Minus;
    TH1D * MC_CosThetaStar1Sol2Minus;

  }; //~MCPolPlots class


} // ~namespace Operation
#endif
