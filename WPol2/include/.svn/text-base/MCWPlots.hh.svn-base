#ifndef _MCWPlots_HH_
#define _MCWPlots_HH_

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
#include "MuPtScaleCorr.hh"

namespace Operation {
 
  class MCWPlots : public PlottingBase {

  public:
    // Standard Operation methods.

    MCWPlots(const std::string & foldername, const std::string & VBoson, const unsigned int & phase_space);
    ~MCWPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    bool forW;
    bool forZ;

    std::string mFolderName;
    std::string mVBoson;
    unsigned int mPhaseSpace;

    TVector3 jBoost, jBoost2;
    TVector3 jSol1Boost, jSol2Boost, jWrongBoost, jRightBoost;
    //TLorentzVector jRestMu, jRestQuark, jRestQuark2, jGenW, jGenLepton;
    TLorentzVector jSol1, jSol2, jSol1Mu, jSol2Mu, jWrongSol, jWrongMu, jRightSol, jRightMu;
    //Event::GenObject const * genLepton;
    //Event::GenObject const * genLeptonNu;
    double CosThetaStar1, CosThetaStar2, CosThetaStar3;
    double CosThetaStar1Sol1, CosThetaStar1Sol2, CosThetaStar1WrongPz, CosThetaStar1RightPz;
    double delta_w_mu, delta_w_mu_mu, wrong_sol, right_sol;
    jSolutionsW jMCSolW, jMCSol, jMCSolMHT2, jMCSolMuon,jMCSolMuonMHT2, jMCSolMuonMHT2Reco;
    jSolutionsW jMCSolWEtaBin1, jMCSolWEtaBin2, jMCSolWEtaBin3, jMCSolWEtaBin4, jMCSolWEtaBin5;
    jSolutionsW jMCSolWEtaBin6, jMCSolWEtaBin7, jMCSolWEtaBin8, jMCSolWEtaBin9, jMCSolWEtaBin10, jMCSolWEtaBin11;
    jSolutionsW jMCSolWPtBin1,jMCSolWPtBin2, jMCSolWPtBin3, jMCSolWPtBin4, jMCSolWPtBin5, jMCSolWPtBin6, jMCSolWPtBin7, jMCSolWPtBin8;
    jSolutionsW jMCSolWJetBin1,jMCSolWJetBin2, jMCSolWJetBin3, jMCSolWJetBin4, jMCSolWJetBin5, jMCSolWJetBin6;
    std::vector<double> all_lh_minus;
    std::vector<double> all_rh_minus;
    std::vector<double> all_long_minus;
    std::vector<double> all_lh_plus;
    std::vector<double> all_rh_plus;
    std::vector<double> all_long_plus;

    // Histograms
    TH1D * MC_WMultiplicity;
    TH1D * MC_MuonNuMultiplicity;
    TH1D * MC_MuonMultiplicity;
    TH1D * MC_JetMultiplicity;
    TH1D * MC_JetMultiplicityAll;
    TH1D * MC_JetPt;
    TH1D * MC_JetEta;
    TH1D * MC_JetPtAll;
    TH1D * MC_JetEtaAll;
    TH1D * MC_JetMHT;
    TH1D * MC_JetMHT2;
    TH1D * MC_VirtualWMass;
    TH1D * MC_VirtualWMassRe;
    TH1D * MC_VirtualWMassIm;
    TH1D * MC_WPT;
    TH1D * MC_WEta;
    TH1D * MC_WY;
    TH1D * MC_WYMuAcc;
    TH1D * MC_WPtPlus;
    TH1D * MC_WPtMinus;
    TH1D * MC_WPTLepAcc2Plus;
    TH1D * MC_WPTLepAcc2Minus;
    TH1D * MC_WEtaPlus;
    TH1D * MC_WEtaMinus;
    TH1D * MC_WYPlus;
    TH1D * MC_WYMinus;
    TH1D * MC_MHTGenJetsWPtDiff;
    TH1D * MC_MHT2GenJetsWPtDiff;
    TH1D * MC_MHTAllGenJetsWPtDiff;
    TH1D * MCRECO_PFMHTWPtDiff;
    TH1D * MC_MuonPt;
    TH1D * MC_MuonEta;
    TH1D * MC_MuonEtaAbs;
    TH1D * MC_MuonNuPt;
    TH1D * MC_MuonNuEta;
    TH1D * MC_MuonNuEtaAbs;

    TH1D * MC_MuonPtCut1;
    TH1D * MC_MuonPtCut2;
    TH1D * MC_MuonEtaCut1;
    TH1D * MC_MuonEtaCut2;
    TH1D * MC_MuonNuPtCut1;
    TH1D * MC_MuonNuPtCut2;
    TH1D * MC_MuonNuEtaCut1;
    TH1D * MC_MuonNuEtaCut2;
    TH1D * MC_MuonNuPtCut1Plus;
    TH1D * MC_MuonPtCut1Plus;
    TH1D * MC_MuonNuPtCut1Minus;
    TH1D * MC_MuonPtCut1Minus;
    TH1D * MC_MuonNuPtCut2Plus;
    TH1D * MC_MuonPtCut2Plus;
    TH1D * MC_MuonNuPtCut2Minus;
    TH1D * MC_MuonPtCut2Minus;

    TH1D * MC_HWA0Numerator;
    TH1D * MC_HWA1Numerator;
    TH1D * MC_HWA2Numerator;
    TH1D * MC_HWA3Numerator;
    TH1D * MC_HWA4Numerator;

    TH1D * MC_HWMinusA0Numerator;
    TH1D * MC_HWMinusA1Numerator;
    TH1D * MC_HWMinusA2Numerator;
    TH1D * MC_HWMinusA3Numerator;
    TH1D * MC_HWMinusA4Numerator;

    TH1D * MC_HWPlusA0Numerator;
    TH1D * MC_HWPlusA1Numerator;
    TH1D * MC_HWPlusA2Numerator;
    TH1D * MC_HWPlusA3Numerator;
    TH1D * MC_HWPlusA4Numerator;

    TH1D * MC_HWAiDenominator;
    TH1D * MC_HWPlusAiDenominator;
    TH1D * MC_HWMinusAiDenominator;

    TH1D * MC_MuonPtPlus;
    TH1D * MC_MuonNuPtPlus;
    TH1D * MC_MuonEtaPlus;
    TH1D * MC_MuonEtaPlus_LH;
    TH1D * MC_MuonEtaPlus_RH;
    TH1D * MC_MuonEtaPlus_LO;
    TH1D * MC_MuonEtaMuonAccPlus;
    TH1D * MC_MuonEtaMuonAccPlus_LH;
    TH1D * MC_MuonEtaMuonAccPlus_RH;
    TH1D * MC_MuonEtaMuonAccPlus_LO;
    TH1D * MC_MuonEtaAbsPlus;
    TH1D * MC_MuonNuEtaPlus;
    TH1D * MC_MuonNuEtaAbsPlus;
    TH1D * MC_ICVarPlus;
    TH1D * MC_ICVarPlus_A0p10pc;
    TH1D * MC_ICVarPlus_A1p10pc;
    TH1D * MC_ICVarPlus_A2p10pc;
    TH1D * MC_ICVarPlus_A3p10pc;
    TH1D * MC_ICVarPlus_A4p10pc;
    TH1D * MC_ICVarPlus_A0p0d01;
    TH1D * MC_ICVarPlus_A1p0d01;
    TH1D * MC_ICVarPlus_A2p0d01;
    TH1D * MC_ICVarPlus_A3p0d01;
    TH1D * MC_ICVarPlus_A4p0d01;
    TH1D * MC_ICVarPlusMuonAcc;
    TH1D * MC_ICVarPlus_LH;
    TH1D * MC_ICVarPlus_RH;
    TH1D * MC_ICVarPlus_LO;
    TH1D * MC_ICVarPlusMuonAcc_LH;
    TH1D * MC_ICVarPlusMuonAcc_RH;
    TH1D * MC_ICVarPlusMuonAcc_LO;
    TH1D * MC_ICVarMinus;
    TH1D * MC_ICVarMinus_A0p10pc;
    TH1D * MC_ICVarMinus_A1p10pc;
    TH1D * MC_ICVarMinus_A2p10pc;
    TH1D * MC_ICVarMinus_A3p10pc;
    TH1D * MC_ICVarMinus_A4p10pc;
    TH1D * MC_ICVarMinus_A0p0d01;
    TH1D * MC_ICVarMinus_A1p0d01;
    TH1D * MC_ICVarMinus_A2p0d01;
    TH1D * MC_ICVarMinus_A3p0d01;
    TH1D * MC_ICVarMinus_A4p0d01;
    TH1D * MC_ICVarMinusMuonAcc;
    TH1D * MC_ICVarMinus_LH;
    TH1D * MC_ICVarMinus_RH;
    TH1D * MC_ICVarMinus_LO;
    TH1D * MC_ICVarMinusMuonAcc_LH;
    TH1D * MC_ICVarMinusMuonAcc_RH;
    TH1D * MC_ICVarMinusMuonAcc_LO;
    TH1D * MC_MuonPtMinus;
    TH1D * MC_MuonNuPtMinus;
    TH1D * MC_MuonEtaMinus;
    TH1D * MC_MuonEtaMinus_LH;
    TH1D * MC_MuonEtaMinus_RH;
    TH1D * MC_MuonEtaMinus_LO;
    TH1D * MC_MuonEtaMuonAccMinus;
    TH1D * MC_MuonEtaMuonAccMinus_LH;
    TH1D * MC_MuonEtaMuonAccMinus_RH;
    TH1D * MC_MuonEtaMuonAccMinus_LO;
    TH1D * MC_MuonEtaAbsMinus;
    TH1D * MC_MuonNuEtaMinus;
    TH1D * MC_MuonNuEtaAbsMinus;
    TH1D * MC_WPlusPzMatching;
    TH1D * MC_WMinusPzMatching;
    TH1D * MC_PhiStar1Test1;
    TH1D * MC_PhiStar1Plus;
    TH1D * MC_PhiStar1PlusMuonAcc;
    TH1D * MC_PhiStar1Minus;
    TH1D * MC_CosPhiStar1Test1;
    TH1D * MC_PhiStar1Test2;
    TH1D * MC_PhiStar1Test3_acc10;
    TH1D * MC_CosPhiStar1_acc10;
    TH1D * MC_PhiStar1Test4_acc20;
    TH1D * MC_PhiStar1Test3_pt10;
    TH1D * MC_PhiStar1Test4_pt20;
    TH1D * MC_CosThetaStar1PlusTest1;
    TH1D * MC_CosThetaStar1MinusTest1;
    TH1D * MC_CosThetaStar1Plus;
    TH1D * MC_CosThetaStar1PlusMuonAcc;
    TH1D * MC_CosThetaStar1Plus_LH;
    TH1D * MC_CosThetaStar1Plus_RH;
    TH1D * MC_CosThetaStar1Plus_LO;
    TH1D * MC_CosThetaStar1PlusMuonAcc_LH;
    TH1D * MC_CosThetaStar1PlusMuonAcc_RH;
    TH1D * MC_CosThetaStar1PlusMuonAcc_LO;
    TH1D * MC_CosThetaStar1Minus;
    TH1D * MC_CosThetaStar1MinusMuonAcc;
    TH1D * MC_CosThetaStar1Minus_LH;
    TH1D * MC_CosThetaStar1Minus_RH;
    TH1D * MC_CosThetaStar1Minus_LO;
    TH1D * MC_CosThetaStar1MinusMuonAcc_LH;
    TH1D * MC_CosThetaStar1MinusMuonAcc_RH;
    TH1D * MC_CosThetaStar1MinusMuonAcc_LO;
    TH1D * MC_CosThetaStar2Plus;
    TH1D * MC_CosThetaStar2Minus;
    TH1D * MC_CosThetaStar3Plus;
    TH1D * MC_CosThetaStar3Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin1Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin1Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin2Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin2Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin3Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin3Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin4Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin4Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin5Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin5Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin6Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin6Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin7Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin7Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin8Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin8Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin9Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin9Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin10Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin10Minus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin11Plus;
    TH1D * MC_CosThetaStar1RightPzWEtaBin11Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin1Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin1Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin2Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin2Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin3Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin3Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin4Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin4Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin5Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin5Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin6Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin6Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin7Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin7Minus;
    TH1D * MC_CosThetaStar1RightPzWPtBin8Plus;
    TH1D * MC_CosThetaStar1RightPzWPtBin8Minus;
    TH1D * MC_CosThetaStar1RightPzWJetBin1Plus;
    TH1D * MC_CosThetaStar1RightPzWJetBin1Minus;
    TH1D * MC_CosThetaStar1RightPzWJetBin2Plus;
    TH1D * MC_CosThetaStar1RightPzWJetBin2Minus;
    TH1D * MC_CosThetaStar1RightPzWJetBin3Plus;
    TH1D * MC_CosThetaStar1RightPzWJetBin3Minus;
    TH1D * MC_CosThetaStar1RightPzWJetBin4Plus;
    TH1D * MC_CosThetaStar1RightPzWJetBin4Minus;
    TH1D * MC_CosThetaStar1RightPzWJetBin5Plus;
    TH1D * MC_CosThetaStar1RightPzWJetBin5Minus;
    TH1D * MC_CosThetaStar1RightPzWJetBin6Plus;
    TH1D * MC_CosThetaStar1RightPzWJetBin6Minus;
    TH1D * MC_CosThetaStar1WrongPzMuonMHT2RecoPlus;
    TH1D * MC_CosThetaStar1WrongPzMuonMHT2RecoMinus;
    TH1D * MC_CosThetaStar1RightPzMuonMHT2RecoPlus;
    TH1D * MC_CosThetaStar1RightPzMuonMHT2RecoMinus;
    TH1D * MC_CosThetaStar1WrongPzMuonMHT2Plus;
    TH1D * MC_CosThetaStar1WrongPzMuonMHT2Minus;
    TH1D * MC_CosThetaStar1RightPzMuonMHT2Plus;
    TH1D * MC_CosThetaStar1RightPzMuonMHT2Minus;
    TH1D * MC_CosThetaStar1WrongPzMuonMinus;
    TH1D * MC_CosThetaStar1WrongPzMuonPlus;
    TH1D * MC_CosThetaStar1RightPzMuonMinus;
    TH1D * MC_CosThetaStar1RightPzMuonPlus;
    TH1D * MC_CosThetaStar1RightPzMHT2Plus;
    TH1D * MC_CosThetaStar1RightPzMHT2Minus;
    TH1D * MC_CosThetaStar1WrongPzMHT2Plus;
    TH1D * MC_CosThetaStar1WrongPzMHT2Minus;
    TH1D * MC_CosThetaStar1WrongPzPlus;
    TH1D * MC_CosThetaStar1WrongPzMinus;
    TH1D * MC_CosThetaStar1RightPzPlus;
    TH1D * MC_CosThetaStar1RightPzMinus;
    TH1D * MC_DiffPzWMuPlus;
    TH1D * MC_DiffPzWMuMinus;

    TH2D * MC_PhiStar_vs_CosThetaStar;
    TH2D * MC_PhiStar_vs_CosThetaStar_Plus;
    TH2D * MC_PhiStar_vs_CosThetaStar_Minus;
    TH2D * MC_LP_vs_PhiStar;
    TH2D * MC_LP_vs_PhiStarPlus;
    TH2D * MC_LP_vs_PhiStarMinus;
    TH2D * MC_LPcol_vs_CosThetaStar;
    TH2D * MC_LPcol2_vs_CosThetaStar;
    TH2D * MC_LeptonTest1;
    TH2D * MC_LP3D_vs_LP;
    TH2D * MC_LPcol_vs_CosThetaStarPlus;
    TH2D * MC_LPcol_vs_CosThetaStarMinus;
    TH2D * MC_diffLPcolCosThetaStar_vs_PhiStar;
    TH2D * MC_diffLPcolCosThetaStar_vs_PhiStarPlus;
    TH2D * MC_diffLPcolCosThetaStar_vs_PhiStarMinus;
    TH2D * MC_leptonrapidity_vs_PhiStar;
    TH2D * MC_leptonrapidity_vs_PhiStarPlus;
    TH2D * MC_leptonrapidity_vs_PhiStarMinus;
    TH2D * MC_leptonPt_vs_PhiStar;
    TH2D * MC_leptonPt_vs_PhiStarPlus;
    TH2D * MC_leptonPt_vs_PhiStarMinus;
    TH2D * MC_leptonWrapiditydiff_vs_PhiStar;
    TH2D * MC_leptonWrapiditydiff_vs_PhiStarPlus;
    TH2D * MC_leptonWrapiditydiff_vs_PhiStarMinus;

    TH2D * MC_MuonEtaCosThetaStar1Plus;
    TH2D * MC_MuonEtaCosThetaStar1Minus;
    TH2D * MC_MuonPtCosThetaStar1Plus;
    TH2D * MC_MuonPtCosThetaStar1Minus;
    TH2D * MC_WEtaCosThetaStar1Plus;
    TH2D * MC_WEtaCosThetaStar1Minus;
    TH2D * MC_WPtCosThetaStar1Plus;
    TH2D * MC_WPtCosThetaStar1Minus;
    TH2D * MC_WPtPzPlus;
    TH2D * MC_WPtPzMinus;
    TH2D * MC_WMuPtPzPlus;
    TH2D * MC_WMuPtPzMinus;
    TH2D * MC_WPtY;
    TH2D * MC_WYvsMuEta;
    TH2D * MC_WPT_vs_LepPTPlus;
    TH2D * MC_WPT_vs_LepPTMinus;
    TH2D * MC_WPT_vs_LepEtaPlus;
    TH2D * MC_WPT_vs_LepEtaMinus;

    jSolutionsW jMCSolWCorr;
    TH1D * MC_CosThetaStar1CorrPlus;
    TH1D * MC_CosThetaStar1CorrPlus_LH;
    TH1D * MC_CosThetaStar1CorrPlus_RH;
    TH1D * MC_CosThetaStar1CorrPlus_LO;

  }; // ~MCWPlots class


} // ~namespace Operation
#endif
