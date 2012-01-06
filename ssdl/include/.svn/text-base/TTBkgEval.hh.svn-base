#ifndef TTBkgEval_hh
#define TTBkgEval_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

namespace SSDL {

  class TTBkgEval : public PlottingBase {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    TTBkgEval(const std::string & folderName,
	      Utils::ParameterSet &);
    
    ~TTBkgEval(); //!< Destructor.

    /*! \brief Selection the required event data.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev);

    void  BookHistos();
    std::ostream& Description(std::ostream& ostrm);
    double        getDeltaR(double, double, double, double);
  private:
    // Operation private data members
    //--------------------------------
    const std::string mFolderName; //!< ROOT folder name to save histograms to.    
    static const double PI                 = 3.14159265;
 
    TH1D *h_isoPFCombRel_ac;
    TH1D *h_isoSRCombRel_ac;
    TH1D *h_isoPFCombRel_bc;
    TH1D *h_isoSRCombRel_bc;

    TH1D *h_isoSRCombRel_eta0;
    TH1D *h_isoSRCombRel_eta1;
    TH1D *h_isoSRCombRel_eta2;
    TH1D *h_isoSRTrk_eta0;
    TH1D *h_isoSRTrk_eta1;
    TH1D *h_isoSRTrk_eta2;
    
    TH1D *h_isoSRCombRel_pt0;
    TH1D *h_isoSRCombRel_pt1;
    TH1D *h_isoSRCombRel_pt2;
    TH1D *h_isoSRTrk_pt0;
    TH1D *h_isoSRTrk_pt1;
    TH1D *h_isoSRTrk_pt2;

    TH1D *h_met_ac;
    TH1D* h_minv2mu;
    TH2D *h_HT_njet;
    TH2D *h_MHT_njet;
    TH2D *h_HT_nBjet;
    TH2D *h_MHT_nBjet;

    TH1D *h_btagDiscri_alljets;
    TH1D *h_btagDiscriSV_alljets;
    TH1D *h_btagDiscriTC_alljets;
    TH2D *h_Bjet_EtaPt;
    TH2D *h_NONBjet_EtaPt;

    TH1D *h_dRmin_mujet;
    TH1D *h_dR_mujet;
    TH2D *h_muB_closetoMu_JetEtaPt;
    TH2D *h_2bp_probe_closetoMu_JetEtaPt;
    TH2D *h_muB_probe_JetEtaPt;
    TH2D* h_probe_closetoMu_JetEtaPt;
    TH2D* h_MuSelHF_closetoMu_JetEtaPt;
    TH2D* h_closetoMu_JetEtaPt;
    TH2D* h_MuSelHF_EtaPt;
    TH2D* h_ht300_muB_probe_JetEtaPt;
    TH2D* h_closetoMu_JetEtaPt_HT0;
    TH2D* h_closetoMu_JetEtaPt_HT150to350;
    TH2D* h_closetoMu_JetEtaPt_HT350;


    TH2D* h_MuSelHF_closetoMu_JetEtaPt_HT0;
    TH2D* h_MuSelHF_closetoMu_JetEtaPt_HT150to350;
    TH2D* h_MuSelHF_closetoMu_JetEtaPt_HT350;

    TH2D* h_bc_RecoMuon_EtaPt;
    TH2D* h_RecoMuon_EtaPt;
    TH2D* h_IDMuon_EtaPt;
    TH2D* h_nonIDMuon_EtaPt;

    TH2D* h_RecoMuon_EtaPt_HT0;
    TH2D* h_IDMuon_EtaPt_HT0;
    TH2D* h_nonIDMuon_EtaPt_HT0;

    TH2D* h_RecoMuon_EtaPt_HT50;
    TH2D* h_IDMuon_EtaPt_HT50;
    TH2D* h_nonIDMuon_EtaPt_HT50;

    TH2D* h_RecoMuon_EtaPt_HT150;
    TH2D* h_IDMuon_EtaPt_HT150;
    TH2D* h_nonIDMuon_EtaPt_HT150;

    TH2D* h_RecoMuon_EtaPt_HT350;
    TH2D* h_IDMuon_EtaPt_HT350;
    TH2D* h_nonIDMuon_EtaPt_HT350;

    TH2D* h_nonIDtau_jetClosetoMuonEtaPt;

    TH1D* h_btagSSV_jetClosetoMuon;


    TH1D* h_NC50_fakeMuon;
    TH1D* h_NC50_isoMuon;
    TH1D* h_NC50_HFMuon;
    TH1D* h_NC50_allMuon;
    TH1D* h_NC50_allrecoMuon;

    
    TH2D* h_IDMuonEtaPt;
    TH2D* h_RecoMuonEtaPt;

    TH2D* h_MuonEtaPt;
    TH2D* h_selMuonEtaPt;
   
    TH2D* h_JetEtaPt;
    TH2D* h_selJetEtaPt;
    
    TH2D* h_ProbeJetEtaPt;
    TH2D* h_selProbeJetEtaPt;

    TH2D* h_IDtauProbeJetEtaPt;
    TH2D* h_RtauProbeJetEtaPt;

    TH2D* h_ProbeMuonEtaPt;
    TH2D* h_selProbeMuonEtaPt;
    
    TH2D* h_selBmatchMuonEtaPt;
    TH2D* h_BmatchMuonEtaPt;

    TH2D* h_bpartonEtaPt;
    TH2D* h_closebMuonEtaPt;
    

    TH2D* h_jetClosetoMuonEtaPt;
    TH2D* h_jetEtaPt;

    TH2D* h_bjetEtaPt;
    TH2D* h_bjetMuonEtaPt;
    TH2D* h_taubjetEtaPt;
    TH2D* h_IDtau_bjetEtaPt;
    TH2D* h_bjetPt_tauPt;

    TH2D* h_NONbjetEtaPt;
    TH2D* h_NONbjetMuonEtaPt;
    TH2D* h_tauNONbjetEtaPt;
    TH2D* h_IDtau_NONbjetEtaPt;
    TH2D* h_NONbjetPt_tauPt;

    TH2D* h_IDtau_jetClosetoMuonEtaPt;

    TH1D* h_bpartonPt;
    TH1D* h_closebMuonPt;
    
    TH1D* h_jetPt;
    TH1D* h_commJetPt;
    TH1D* h_genMuonMatchedPDG;

    

    TH1D* h_tauIDbyTaNC_fake;
    TH1D* h_tauIDbyTaNC_taulep;


    TH1D* h_HT_bc;
    TH1D* h_MHT_bc;
    TH1D* h_njet_bc;
    TH1D* h_nBjet_bc;
    TH1D* h_nIdMuon_bc;

    TH1D* h_HT_aftermht;

    TH1D* h_isoSRCombRel_hlt;
    TH1D* h_isoSRCombRel_bjet;
    TH1D* h_isoSRCombRel_njet;
    TH1D* h_isoSRCombRel_mht;
    TH1D* h_isoSRCombRel_ht;
    TH1D* h_nbparton;
    TH1D* h_allJetPt;

    bool MCAnal_;
    double mhtCut;
    double metCut;
    double htCut;
    double jetPtCut;
    int njetCut;


  }; // ~TTBkgEval class




  
} //~namespace SSDL

#endif 
