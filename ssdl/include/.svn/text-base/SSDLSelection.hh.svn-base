#ifndef SSDLSelection_hh
#define SSDLSelection_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

// Structure for leptons
struct lepton {
  double         charge;
  TLorentzVector vector;
  lepton(double c, TLorentzVector v) : charge(c), vector(v) {}
};

inline bool compareLepPt(const Lepton *l1, const Lepton* l2) {
    return l1->Pt() > l2->Pt();
  }

namespace SSDL{
  

  class SSDLSelection : public PlottingBase {
  public:
    // Standard Operation methods.
    SSDLSelection(const std::string & filename,
		  Utils::ParameterSet &);
    ~SSDLSelection(); //!< Destructor.

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();

  private:
    std::string mFolderName;
    const static int dilepFinalStates   = 6;
    
    TH1D* h_ssdl_trigEff;

    TH2D* h_ssdl_cFlow;
    TH1D* h_gen_lepPtSpec;

    TH1D* h_ssdl_postMHT, *h_ssdl_postHT, *h_ssdl_postHT_postMHT;
    TH1D *h_HT_postSSDL, *h_MHT_postSSDL;
    TH1D *h_MHT_postHT, *h_MHT_postHT_postSSDL;
    TH1D *h_nlep_postHT, *h_nlep_postMHT, *h_nlep_postHT_postMHT;
    TH1D *h_nmuon_postHT, *h_nelec_postHT, *h_ntau_postHT;
    TH1D *h_nmuon_postMHT, *h_nelec_postMHT, *h_ntau_postMHT;
    TH1D *h_nmuon_postHT_postMHT, *h_nelec_postHT_postMHT, *h_ntau_postHT_postMHT;
    TH1D *h_mu_eta_postHT, *h_elec_eta_postHT, *h_tau_eta_postHT;
    TH1D *h_mu_eta_postMHT, *h_elec_eta_postMHT, *h_tau_eta_postMHT;
    TH1D *h_mu_eta_postHT_postMHT, *h_elec_eta_postHT_postMHT, *h_tau_eta_postHT_postMHT;
    TH1D *h_mu_pt_postHT, *h_elec_pt_postHT, *h_tau_pt_postHT;
    TH1D *h_mu_pt_postMHT, *h_elec_pt_postMHT, *h_tau_pt_postMHT;
    TH1D *h_mu_pt_postHT_postMHT, *h_elec_pt_postHT_postMHT, *h_tau_pt_postHT_postMHT;

   
    TH1D *h_ss_HT;
    TH1D *h_ss_MHT;
    TH1D *h_ss_NTAU;
    TH1D *h_ss_NMUON;
    TH1D *h_ss_NELEC;
    TH1D *h_ss_NLEPTON;
    TH1D *h_bc_NTAU;
    TH1D *h_bc_NMUON;
    TH1D *h_bc_NELEC;
    TH1D *h_bc_ElecPt;
    TH1D *h_bc_MuonPt;
    TH1D *h_bc_TauPt;
    TH1D *h_Charge;
    TH1D *h_bc_Charge;
    TH1D *h_bc_HT;
    TH1D *h_bc_lept;
    TH1D *h_bc_MHT;
    TH1D *h_ss_RECSTATE;
    std::vector<TH1D*> h_ss_ht;
    std::vector<TH1D*> h_abcd_ht;
    std::vector<TH1D*> h_ss_mht;
    std::vector<TH2D*> h_ch_ht;
    std::vector<TH1D*> h_nl_A;

    std::vector<TH2D*> h_m0_m12_fs;
    std::vector<TH2D*> h_m0_m12_fs_nw;

    TH2D *h_ht_sl;
    TH2D *h_ht_dl;

    TH2D *h_tauEtaPt;
    TH2D *h_tausel1_EtaPt;
    TH2D *h_tausel2_EtaPt;

    TH2D *h_tau1AnyJetEtaPt;
    TH2D *h_tau1BJetEtaPt;

    TH2D *h_tau2AnyJetEtaPt;
    TH2D *h_tau2BJetEtaPt;
    TH2D *h_tauIDbyTaNCvsPt;

    double mhtCut;
    double htCut;
    double leptonCut;
    double maxPtHat;
    double printLep;
    bool mSugraScan;
    bool bkgAnal;
    bool mcAnal;
    // bool bogusEvents;
    bool mInterestingEvents;
    bool ignoreNonTau, onlyETau, onlyMuTau, onlyTauTau;
    std::string _InterestingFile;
    
    
    int nhdl[6][6];
    int nhsl[6][3];
    float w;
    float uppermetcut_;
    TH2D *h_m0_m12_AC_nw;
    TH2D *h_m0_m12_BC_nw;

    TH2D *h_m0_m12_AC;
    TH2D *h_m0_m12_BC;
    TH2D *h_m0_m12_SS;
    /*
    TH2D *h_m0_m12_charg_toEle;
    TH2D *h_m0_m12_charg_toMu;
    TH2D *h_m0_m12_charg_toTau;
    TH2D *h_m0_m12_charg_toLep;
    */
    string recoFile;
    string mcFile;
    string bogusEvFile;
    
  }; // ~SSDLSelection class
}
#endif

//






