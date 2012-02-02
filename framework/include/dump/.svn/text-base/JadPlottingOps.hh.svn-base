/*! \file JadPlottingOps.hh
 * \brief Header file for Monte Carlo-based plotting operations.
 */
#ifndef JadPlottingOps_hh
#define JadPlottingOps_hh

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TH1D.h"
#include "TH2D.h"

namespace Operation {

  struct jSolutionsW {
    bool realSolutions; //true implies real solutions, false implies complex ones
    double rightSol;
    double wrongSol;
    double sol1;
    double sol2;
  };


  jSolutionsW FindBoost(const TLorentzVector &jMuon, const double &jVWPx, const double &jVWPy, const double &jVWPz, const bool &cheat, const bool &approximate, const double &jVWM);

  class MCWPlots : public PlottingBase {
    
  public:
    // Standard Operation methods.

    MCWPlots(const std::string & foldername);
    ~MCWPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:

    std::string mFolderName;
    TVector3 jBoost, jBoost2;
    TVector3 jSol1Boost, jSol2Boost, jWrongBoost, jRightBoost;
    TLorentzVector jRestMu, jRestQuark, jRestQuark2, jGenW, jGenMu;
    TLorentzVector jSol1, jSol2, jSol1Mu, jSol2Mu, jWrongSol, jWrongMu, jRightSol, jRightMu;
    double CosThetaStar1, CosThetaStar2, CosThetaStar3;
    double CosThetaStar1Sol1, CosThetaStar1Sol2, CosThetaStar1WrongPz, CosThetaStar1RightPz;
    double delta_w_mu, delta_w_mu_mu, wrong_sol, right_sol;
    jSolutionsW jMCSolW, jMCSol, jMCSolMHT2, jMCSolMuon,jMCSolMuonMHT2, jMCSolMuonMHT2Reco;
    jSolutionsW jMCSolWEtaBin1, jMCSolWEtaBin2, jMCSolWEtaBin3, jMCSolWEtaBin4, jMCSolWEtaBin5;
    jSolutionsW jMCSolWEtaBin6, jMCSolWEtaBin7, jMCSolWEtaBin8, jMCSolWEtaBin9, jMCSolWEtaBin10, jMCSolWEtaBin11;
    jSolutionsW jMCSolWPtBin1,jMCSolWPtBin2, jMCSolWPtBin3, jMCSolWPtBin4, jMCSolWPtBin5, jMCSolWPtBin6, jMCSolWPtBin7, jMCSolWPtBin8;
    jSolutionsW jMCSolWJetBin1,jMCSolWJetBin2, jMCSolWJetBin3, jMCSolWJetBin4, jMCSolWJetBin5, jMCSolWJetBin6;

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
    TH1D * MC_WPtPlus;
    TH1D * MC_WPtMinus;
    TH1D * MC_WEtaPlus;
    TH1D * MC_WEtaMinus;
    TH1D * MC_MHTGenJetsWPtDiff;
    TH1D * MC_MHT2GenJetsWPtDiff;
    TH1D * MC_MHTAllGenJetsWPtDiff;
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

    TH1D * MC_MuonPtPlus;
    TH1D * MC_MuonNuPtPlus;
    TH1D * MC_MuonEtaPlus;
    TH1D * MC_MuonEtaAbsPlus;
    TH1D * MC_MuonNuEtaPlus;
    TH1D * MC_MuonNuEtaAbsPlus;
    TH1D * MC_ICVarPlus;
    TH1D * MC_MuonPtMinus;
    TH1D * MC_MuonNuPtMinus;
    TH1D * MC_MuonEtaMinus;
    TH1D * MC_MuonEtaAbsMinus;
    TH1D * MC_MuonNuEtaMinus;
    TH1D * MC_MuonNuEtaAbsMinus;
    TH1D * MC_ICVarMinus;
    TH1D * MC_WPlusPzMatching;
    TH1D * MC_WMinusPzMatching;
    TH1D * MC_CosThetaStar1Plus;
    TH1D * MC_CosThetaStar1Minus;
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
    TH2D * MC_MuonEtaCosThetaStar1Plus;
    TH2D * MC_MuonEtaCosThetaStar1Minus;
    TH2D * MC_MuonPtCosThetaStar1Plus;
    TH2D * MC_MuonPtCosThetaStar1Minus;
    TH2D * MC_WEtaCosThetaStar1Plus;
    TH2D * MC_WEtaCosThetaStar1Minus;
    TH2D * MC_WPtCosThetaStar1Plus;
    TH2D * MC_WPtCosThetaStar1Minus;
 
    // markus additions

    TH2D *  MC_ICVarCosThetaPlus2D;
    TH2D * MC_ICVarCosThetaMinus2D;
    TH1D * MC_ICVarCosThetaPlusZ;
    TH1D * MC_ICVarCosThetaMinusZ;
    TH1D * MC_ICVarCosThetaPlus;
    TH1D * MC_ICVarCosThetaMinus;
    TH2D * ICVarCosThetaPlusDiv;
    TH2D * ICVarCosThetaMinusDiv;



  }; // ~MCWPlots class
  

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
    TH1D * MC_CosThetaStar1Sol1Plus;
    TH1D * MC_CosThetaStar1Sol2Plus;
    TH1D * MC_CosThetaStar1Sol1Minus;
    TH1D * MC_CosThetaStar1Sol2Minus;

  }; //~MCPolPlots class

  class RECOPolPlots : public PlottingBase {
    
  public:
    // Standard Operation methods.

    RECOPolPlots(const std::string & foldername);
    ~RECOPolPlots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:

    std::string mFolderName;
    jSolutionsW jRECOSol;

    //Histograms
    TH1D * RECO_MuonPtPlus;
    TH1D * RECO_MuonPtMinus;
    TH1D * RECO_MuonEtaPlus;
    TH1D * RECO_MuonEtaMinus;
    TH1D * RECO_MuonEtaPlusAbs;
    TH1D * RECO_MuonEtaMinusAbs;
    TH1D * RECO_CommonMHTPlus;
    TH1D * RECO_CommonMHTMinus;
    TH1D * RECO_ICVarPlus;
    TH1D * RECO_ICVarMinus;
    TH1D * RECO_TransMass;

    TH1D * MC_MuonMultiplicity;
    TH1D * RECO_JetMultiplicity;
    TH1D * RECO_MuonMultiplicity;
    TH1D * RECO_CosThetaStar1Sol1Plus;
    TH1D * RECO_CosThetaStar1Sol2Plus;
    TH1D * RECO_CosThetaStar1Sol1Minus;
    TH1D * RECO_CosThetaStar1Sol2Minus;
    TH1D * MC_RECO_MuonMultMatch;
    TH1D * MC_RECO_MHTDiff;
    TH1D * MC_RECO_MuonPtDiff;
    TH1D * MC_RECO_MuonEtaDiff;
    TH1D * MC_RECO_MuonChargeId;
  }; //~RECOPolPlots class


} //~namespace Operation

#endif //~JadPlottingOps_hh
