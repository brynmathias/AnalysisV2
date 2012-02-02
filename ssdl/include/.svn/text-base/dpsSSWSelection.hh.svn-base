#ifndef dpsSSWSelection_hh
#define dpsSSWSelection_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"
#include "SSDLSelection.hh"
using namespace Event;

//Structure for leptons

/*
struct lepton {
  double         charge;
  TLorentzVector vector;
  lepton(double c, TLorentzVector v) : charge(c), vector(v) {}
};
*/
namespace SSDL{
  class dpsSSWSelection : public PlottingBase {
  public:
    // Standard Operation methods.
    dpsSSWSelection(const std::string & filename,
		  Utils::ParameterSet &);
    ~dpsSSWSelection(); //!< Destructor.

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();

  private:
    std::string mFolderName;
    const static int dilepFinalStates   = 6;

    TH1D *h_nlep_hlt;
    TH1D *h_nlep_skim;
    TH1D *h_nlep_2idlep;
    TH1D *h_nlep_charge;

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

    int mChargeProdCut;
    double mhtCut;
    double htCut;
    double leptonCut;
    double maxPtHat;
    double printLep;
    bool mSugraScan;
    bool bkgAnal;
    int nhdl[6][6];
    int nhsl[6][3];
    float w;

    TH2D *h_m0_m12_AC_nw;
    TH2D *h_m0_m12_BC_nw;

    TH2D *h_m0_m12_AC;
    TH2D *h_m0_m12_BC;
    TH2D *h_m0_m12_SS;
    
    string recoFile;
    string mcFile;

  }; // ~dpsSSWSelection class




}
#endif

//






