#ifndef _RECOCSFramePlots_HH_
#define _RECOCSFramePlots_HH_

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

  class RECOCSFramePlots : public PlottingBase {

  public:
    // Standard Operation methods.

    RECOCSFramePlots(const std::string & foldername, const std::string & VBoson, bool Gen);
    ~RECOCSFramePlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    bool forW;
    bool forZ;
    bool doGen;
    std::string mFolderName;
    std::string mVBoson;


    //Histograms
    TH1D * RECO_CSWMuonPlusPhi;
    TH1D * RECO_CSWMuonPlusPhi2;
    TH1D * RECO_CSWMuonMinusPhi;
    TH1D * RECO_CSWMuonMinusPhi2;
    TH1D * RECO_CSWMuonPlusCosTheta;
    TH1D * RECO_CSWMuonMinusCosTheta;
    TH1D * RECO_CSWTransMass;

    TH1D * RECO_CSWMuon2MinusPhi;
    TH1D * RECO_CSWMuon2MinusPhi_A;
    TH1D * RECO_CSWMuon2MinusPhi_B;
    TH1D * RECO_CSWMuon2MinusPhi_C;
    TH1D * RECO_CSWMuon2PlusPhi;
    TH1D * RECO_CSWMuon2PlusPhi_A;
    TH1D * RECO_CSWMuon2PlusPhi_B;
    TH1D * RECO_CSWMuon2PlusPhi_C;
    TH1D * RECO_CSWMuon2PlusCosTheta;
    TH1D * RECO_CSWMuon2PlusCosTheta_A;
    TH1D * RECO_CSWMuon2PlusCosTheta_B;
    TH1D * RECO_CSWMuon2PlusCosTheta_C;
    TH1D * RECO_CSWMuon2MinusCosTheta;

    TH2D * MC_RECO_CSWMuonPhiCorrelation1;
    TH2D * MC_RECO_CSWMuonPhiCorrelation2;
    TH2D * MC_RECO_CSWMuonPhiCorrelation3;
    TH2D * MC_RECO_CSWMuonPhiCorrelation4;

  }; //~RECOCSFramePlots class
 
} // ~namespace Operation
#endif
