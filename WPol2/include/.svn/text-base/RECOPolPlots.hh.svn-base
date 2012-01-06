#ifndef _RECOPolPlots_HH_
#define _RECOPolPlots_HH_

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TProfile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "Structures.hh"
#include "Functions.hh"
#include "PolTransforms.hh"
#include "MuPtScaleCorr.hh"

namespace Operation {
 
  class RECOPolPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    RECOPolPlots(const std::string & foldername, const std::string & VBoson, bool Gen, const unsigned int & phase_space);
    ~RECOPolPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFolderName;
    std::string mVBoson;
    bool doGenMaster;
    unsigned int mPhaseSpace;
    bool forW;
    bool forZ;
    jSolutionsW jRECOSol;
    std::vector<double> all_lh_minus;
    std::vector<double> all_lh_plus;
    TLorentzVector jGenLep;
    double ICVariable;

    //Histograms
    TH1F * RECO_MuonPtPlus;
    TH1F * RECO_MuonPtPlus_vw;
    TH1F * RECO_MuonPtPlus_PTMp1pc;
    TH1F * RECO_MuonPtPlus_PTMm1pc;
    TH1F * RECO_MuonPtMinus;
    TH1F * RECO_MuonPtMinus_vw;
    TH1F * RECO_MuonPtMinus_PTMp1pc;
    TH1F * RECO_MuonPtMinus_PTMm1pc;
    TH1F * RECO_MuonEtaPlus;
    TH1F * RECO_MuonEtaPlus_A0p10pc;
    TH1F * RECO_MuonEtaPlus_A1p10pc;
    TH1F * RECO_MuonEtaPlus_A2p10pc;
    TH1F * RECO_MuonEtaPlus_A3p10pc;
    TH1F * RECO_MuonEtaPlus_A4p10pc;
    TH1F * RECO_MuonEtaMinus;
    TH1F * RECO_MuonEtaMinus_A0p10pc;
    TH1F * RECO_MuonEtaMinus_A1p10pc;
    TH1F * RECO_MuonEtaMinus_A2p10pc;
    TH1F * RECO_MuonEtaMinus_A3p10pc;
    TH1F * RECO_MuonEtaMinus_A4p10pc;
    TH1F * RECO_MuonEtaPlusAbs;
    TH1F * RECO_MuonEtaMinusAbs;
    TH1F * RECO_CommonMHTPlus;
    TH1F * RECO_CommonMHTMinus;
    TH1F * RECO_ICVarPlus;
    TH1F * RECO_ICVarMinus;
    TH1F * RECO_ICVarMinus_LH;
    TH1F * RECO_ICVarPlus_LH;
    TH1F * RECO_ICVarMinus_RH;
    TH1F * RECO_ICVarPlus_RH;
    TH1F * RECO_ICVarMinus_LO;
    TH1F * RECO_ICVarPlus_LO;
    TH1F * RECO_ICVarTCPlus;
    TH1F * RECO_ICVarTCMinus;
    TH1F * RECO_ICVarPFPlus;
    TH1F * RECO_ICVarPFPlus_vw;
    TH1F * RECO_ICVarPFPlus_LH;
    TH1F * RECO_ICVarPFPlus_LH_vw;
    TH1F * RECO_ICVarPFPlus_LH_GenMu;
    TH1F * RECO_ICVarPFPlus_LH_GenTau;
    TH1F * RECO_ICVarPFPlus_RH;
    TH1F * RECO_ICVarPFPlus_RH_vw;
    TH1F * RECO_ICVarPFPlus_RH_GenMu;
    TH1F * RECO_ICVarPFPlus_RH_GenTau;
    TH1F * RECO_ICVarPFPlus_LO;
    TH1F * RECO_ICVarPFPlus_LO_vw;
    TH1F * RECO_ICVarPFPlus_LO_GenMu;
    TH1F * RECO_ICVarPFPlus_LO_GenTau;
    TH1F * RECO_ICVarPFPlus_A0p10pc;
    TH1F * RECO_ICVarPFPlus_A1p10pc;
    TH1F * RECO_ICVarPFPlus_A2p10pc;
    TH1F * RECO_ICVarPFPlus_A3p10pc;
    TH1F * RECO_ICVarPFPlus_A4p10pc;
    TH1F * RECO_ICVarPFPlus_PTWp1pc;
    TH1F * RECO_ICVarPFPlus_PTWp3pc;
    TH1F * RECO_ICVarPFPlus_PTWp5pc;
    TH1F * RECO_ICVarPFPlus_PTWm1pc;
    TH1F * RECO_ICVarPFPlus_PTWm3pc;
    TH1F * RECO_ICVarPFPlus_PTWm5pc;
    TH1F * RECO_ICVarPFPlus_PTMp1pc;
    TH1F * RECO_ICVarPFPlus_PTMm1pc;
    TH1F * RECO_ICVarPFPlus_PTMp3pc;
    TH1F * RECO_ICVarPFPlus_PTMm3pc;
    TH1F * RECO_ICVarPFMinus;
    TH1F * RECO_ICVarPFMinus_vw;
    TH1F * RECO_ICVarPFMinus_LH;
    TH1F * RECO_ICVarPFMinus_LH_vw;
    TH1F * RECO_ICVarPFMinus_LH_GenMu;
    TH1F * RECO_ICVarPFMinus_LH_GenTau;
    TH1F * RECO_ICVarPFMinus_RH;
    TH1F * RECO_ICVarPFMinus_RH_vw;
    TH1F * RECO_ICVarPFMinus_RH_GenMu;
    TH1F * RECO_ICVarPFMinus_RH_GenTau;
    TH1F * RECO_ICVarPFMinus_LO;
    TH1F * RECO_ICVarPFMinus_LO_vw;
    TH1F * RECO_ICVarPFMinus_LO_GenMu;
    TH1F * RECO_ICVarPFMinus_LO_GenTau;
    TH1F * RECO_ICVarPFMinus_A0p10pc;
    TH1F * RECO_ICVarPFMinus_A1p10pc;
    TH1F * RECO_ICVarPFMinus_A2p10pc;
    TH1F * RECO_ICVarPFMinus_A3p10pc;
    TH1F * RECO_ICVarPFMinus_A4p10pc;
    TH1F * RECO_ICVarPFMinus_PTWp1pc;
    TH1F * RECO_ICVarPFMinus_PTWp3pc;
    TH1F * RECO_ICVarPFMinus_PTWp5pc;
    TH1F * RECO_ICVarPFMinus_PTWm1pc;
    TH1F * RECO_ICVarPFMinus_PTWm3pc;
    TH1F * RECO_ICVarPFMinus_PTWm5pc;
    TH1F * RECO_ICVarPFMinus_PTMp1pc;
    TH1F * RECO_ICVarPFMinus_PTMm1pc;
    TH1F * RECO_ICVarPFMinus_PTMp3pc;
    TH1F * RECO_ICVarPFMinus_PTMm3pc;
    TH1F * RECO_ICVarIC5Plus;
    TH1F * RECO_ICVarIC5Minus;
    TH1F * RECO_ICVarAK5Plus;
    TH1F * RECO_ICVarAK5Minus;
    TH1F * RECO_caloMT;
    TH1F * RECO_pfMT;
    TH1F * RECO_pfMT_vw;
    TH1F * RECO_pfMTPlus;
    TH1F * RECO_pfMTPlus_vw;
    TH1F * RECO_pfMTPlus_PTMp1pc;
    TH1F * RECO_pfMTPlus_PTMm1pc;
    TH1F * RECO_pfMTMinus;
    TH1F * RECO_pfMTMinus_vw;
    TH1F * RECO_pfMTMinus_PTMp1pc;
    TH1F * RECO_pfMTMinus_PTMm1pc;
    TH1F * RECO_pfMHT;
    TH1F * RECO_pfMHT_vw;
    TH1F * RECO_pfMHTPlus;
    TH1F * RECO_pfMHTPlus_vw;
    TH1F * RECO_pfMHTMinus;
    TH1F * RECO_pfMHTMinus_vw;
    TH1F * RECO_pfMET;
    TH1F * RECO_pfMET_vw;
    TH1F * RECO_pfMETPlus;
    TH1F * RECO_pfMETPlus_vw;
    TH1F * RECO_pfMETMinus;
    TH1F * RECO_pfMETMinus_vw;
    TH1F * RECO_CommonMHT;
    TH1F * RECO_MuonPt;
    TH1F * RECO_MuonPt_vw;
    TH1F * RECO_MuonPhi;
    TH1F * RECO_MuonPhiPlus;
    TH1F * RECO_MuonPhiMinus;
    TH1F * RECO_MuonEta;
    TH1F * RECO_recobosonMT;
    TH1F * RECO_recobosonPT;
    TH1F * RECO_recobosonPTvsMHTres;

    TH1F * RECO_NumVerticesPerEvent;
    TH1F * RECO_NumVerticesPerEvent_vw;
    TH1F * RECO_HLTMutriggerbits;
    TH1F * RECO_1v_MuonPt;
    TH1F * RECO_1v_MuonPtPlus;
    TH1F * RECO_1v_MuonPtMinus;
    TH1F * RECO_1v_MuonPhi;
    TH1F * RECO_1v_MuonEta;
    TH1F * RECO_1v_pfMT;
    TH1F * RECO_1v_pfMTPlus;
    TH1F * RECO_1v_pfMTMinus;
    TH1F * RECO_1v_pfMHT;
    TH1F * RECO_1v_pfMHTPlus;
    TH1F * RECO_1v_pfMHTMinus;
    TH1F * RECO_1v_pfMET;
    TH1F * RECO_1v_pfMETPlus;
    TH1F * RECO_1v_pfMETMinus;
    TH1F * RECO_1v_ICVarPFPlus;
    TH1F * RECO_1v_ICVarPFMinus;
    TH1F * RECO_gt1v_MuonPt;
    TH1F * RECO_gt1v_MuonPtPlus;
    TH1F * RECO_gt1v_MuonPtMinus;
    TH1F * RECO_gt1v_MuonPhi;
    TH1F * RECO_gt1v_MuonEta;
    TH1F * RECO_gt1v_pfMT;
    TH1F * RECO_gt1v_pfMTPlus;
    TH1F * RECO_gt1v_pfMTMinus;
    TH1F * RECO_gt1v_pfMHT;
    TH1F * RECO_gt1v_pfMHTPlus;
    TH1F * RECO_gt1v_pfMHTMinus;
    TH1F * RECO_gt1v_pfMET;
    TH1F * RECO_gt1v_pfMETPlus;
    TH1F * RECO_gt1v_pfMETMinus;
    TH1F * RECO_gt1v_ICVarPFPlus;
    TH1F * RECO_gt1v_ICVarPFMinus;

    TH1F * MC_WPt;
    TH1F * MC_WYAbs;
    TH1F * MC_CosThetaStar1Plus;
    TH1F * MC_CosThetaStar1Minus;
    TH1F * MC_MuonMultiplicity;
    TH1F * MC_MuonPlusTauMultiplicity;
    TH1F * MC_MuonExtraMultiplicity;
    TH1F * MC_pthatdist;
    TH1F * RECO_JetMultiplicity;
    TH1F * RECO_JetMultiplicity_vw;
    TH1F * RECO_MuonMultiplicity;
    TH1F * RECO_CosThetaStar1Sol1Plus;
    TH1F * RECO_CosThetaStar1Sol1Plus_LH;
    TH1F * RECO_CosThetaStar1Sol1Plus_RH;
    TH1F * RECO_CosThetaStar1Sol1Plus_LO;
    TH1F * RECO_CosThetaStar1Sol2Plus;
    TH1F * RECO_CosThetaStar1Sol1Minus;
    TH1F * RECO_CosThetaStar1Sol2Minus;
    TH1F * MC_RECO_MuonMultMatch;
    TH1F * MC_RECO_MHTDiff;
    TH1F * MC_RECO_CaloMETDiff;
    TH1F * MC_RECO_TCMETDiff;
    TH1F * MC_RECO_PFMETDiff;
    TH1F * MC_RECO_IC5METDiff;
    TH1F * MC_RECO_AK5METDiff;
    TH1F * MC_RECO_genMHTDiff;
    TH1F * MC_RECO_MuonPtDiff;
    TH1F * MC_RECO_MuonEtaDiff;
    TH1F * MC_RECO_MuonChargeId;

    TH1F * RECO_Tr ;
    TH1F * RECO_Ecal;
    TH1F * RECO_Hcal;
    TH1F * RECO_Com;
    TH1F * RECO_DR;
    TH1F * RECO_Type;
    TH1F * RECO_2ndMassZ;
    TH1F * RECO_2ndMassJPsi;
    TH1F * RECO_CommMuCommMuMass;

    TH2F * RECO_MHTvsTCMET;
    TH2F * RECO_MHTvsPFMET;
    TH2F * RECO_MHTvsCaloMET;
    TH2F * RECO_MHTvsAK5MET;
    TH2F * RECO_MHTvsIC5MET;
    TH2F * MC_RECO_PFMETres_vs_genMHT;
    TH2F * MC_WPtY;
    TH2F * RECO_pfMTvspfLP;
    TH2F * RECO_pfMHTvspfLP;
    TH2F * RECO_pfMHTvspfMT;
    TH2F * RECO_pfMHTvsMuPt;
    TH2F * RECO_recobosonMvsLP;
    TH2F * RECO_recobosonLPvspfLP;
    TH2F * RECO_recobosonPTvspfMHT;
    TH2F * RECO_PTmuplusvsMT;
    TH2F * RECO_PTmuminusvsMT;
    TH2F * RECO_MpPTvsLP;

    TProfile * RECO_recobosonMvsLP_Profile;
    TProfile * MC_RECO_MHTDiffProfile;
    TProfile * RECO_PTmuplusvsMT_Profile;
    TProfile * RECO_PTmuminusvsMT_Profile;

    TH1F * RECO_CosThetaStar1Sol1CorrPlus;
    TH1F * RECO_CosThetaStar1Sol1CorrPlus_LH;
    TH1F * RECO_CosThetaStar1Sol1CorrPlus_RH;
    TH1F * RECO_CosThetaStar1Sol1CorrPlus_LO;

    TH1F * RECO_CosThetaStar1Sol1Plus_A0p10pc;
    TH1F * RECO_CosThetaStar1Sol1Plus_A1p10pc;
    TH1F * RECO_CosThetaStar1Sol1Plus_A2p10pc;
    TH1F * RECO_CosThetaStar1Sol1Plus_A3p10pc;
    TH1F * RECO_CosThetaStar1Sol1Plus_A4p10pc;

  }; //~RECOPolPlots class


} // ~namespace Operation
#endif
