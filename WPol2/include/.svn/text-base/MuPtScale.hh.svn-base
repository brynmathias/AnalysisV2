#ifndef MuPtScale_hh
#define MuPtScale_hh

#include "Operation.hh"
#include "PlottingBase.hh"
#include "EventData.hh"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "Structures.hh"
#include "Functions.hh"
#include "PolTransforms.hh"

namespace Operation {
  class MuPtScale : public PlottingBase {
  public:

    MuPtScale(const std::string & folderName);
    ~MuPtScale();

    void BookHistos();
    void Start(Event::Data & ev);

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:    
    std::string mFolderName;
    std::string mVBoson;


    TH1F * RECO_1pcscale_recobosonM;
    TH1F * RECO_5pcscale_recobosonM;

    TH2F * RECO_1pcscale_recobosonMvsLP;
    TH2F * RECO_5pcscale_recobosonMvsLP;
    TH2F * RECO_5pcscale_recobosonMvsMpPT;
    TH2F * RECO_5pcscale_recobosonMvsMmPT;
    TH2F * RECO_1pcscale_recobosonMvsMpPT;
    TH2F * RECO_1pcscale_recobosonMvsMmPT;
    TH2F * RECO_0pcscale_recobosonMvsMpPT;
    TH2F * RECO_0pcscale_recobosonMvsMmPT;

    TH2F * RECO_5pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_5pcscale_recobosonMvsMpPT_hrdMm;
    TH2F * RECO_1pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_1pcscale_recobosonMvsMpPT_hrdMm;
    TH2F * RECO_0pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_0pcscale_recobosonMvsMpPT_hrdMm;
    TH2F * RECO_5pcscale_recobosonMvsMmPT_hrdMp;
    TH2F * RECO_5pcscale_recobosonMvsMmPT_hrdMm;
    TH2F * RECO_1pcscale_recobosonMvsMmPT_hrdMp;
    TH2F * RECO_1pcscale_recobosonMvsMmPT_hrdMm;
    TH2F * RECO_0pcscale_recobosonMvsMmPT_hrdMp;
    TH2F * RECO_0pcscale_recobosonMvsMmPT_hrdMm;

    TH2F * RECO_4pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_4pcscale_recobosonMvsMmPT_hrdMm;
    TH2F * RECO_3pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_3pcscale_recobosonMvsMmPT_hrdMm;
    TH2F * RECO_2pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_2pcscale_recobosonMvsMmPT_hrdMm;
    TH2F * RECO_m1pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_m1pcscale_recobosonMvsMmPT_hrdMm;
    TH2F * RECO_m2pcscale_recobosonMvsMpPT_hrdMp;
    TH2F * RECO_m2pcscale_recobosonMvsMmPT_hrdMm;

    TH2F * RECO_0pcscale_MpEtavsMpPT_hrdMp;
    TH2F * RECO_0pcscale_MmEtavsMmPT_hrdMm;
    TH2F * RECO_0pcscale_MpPhivsMpPT_hrdMp;
    TH2F * RECO_0pcscale_MmPhivsMmPT_hrdMm;

    TH3F * RECO_0pcscale_MpEtavsMpPTvsrecobosonM_hrdMp;
    TH3F * RECO_0pcscale_MpPhivsMpPTvsrecobosonM_hrdMp;
    TH3F * RECO_0pcscale_MmEtavsMmPTvsrecobosonM_hrdMm;
    TH3F * RECO_0pcscale_MmPhivsMmPTvsrecobosonM_hrdMm;

    double PtPhiCorrA;
    double PtPhiCorrB;
    TH3F * RECO_PhiDep1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp;
    TH3F * RECO_PhiDep1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm;
    TH3F * RECO_PhiDep2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp;
    TH3F * RECO_PhiDep2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm;
    TH3F * RECO_PhiDepm1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp;
    TH3F * RECO_PhiDepm1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm;
    TH3F * RECO_PhiDepm2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp;
    TH3F * RECO_PhiDepm2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm;

    TTree * dimuonstree;
    Double_t MpPt;
    Double_t MpEta;
    Double_t MpPhi;
    Double_t MmPt;
    Double_t MmEta;
    Double_t MmPhi;
    Double_t Zmass;
    Double_t EvWeight;

  }; // ~MuPtScale class
}

#endif
