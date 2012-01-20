#ifndef ANplots_hh
#define ANplots_hh

#include "Operation.hh"
#include "PlottingBase.hh"

namespace Operation {
  class ANplots : public PlottingBase {
    
  public:
    // Standard Operation methods.
    
    ANplots(const std::string & foldername);
    ~ANplots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName;

    TH1D* Zmassmu; 
    TH1D* Zmassmu_pos; 
    TH1D* Zmassmu_neg; 
    
    TH1D* ZLP ;
    TH1D* ZLP_pos ;
    TH1D* ZLP_neg ;

    TH1D* ZPT ;
    TH1D* ZPT_pos ;
    TH1D* ZPT_neg ;

    TH1D* ZPTres;
    TH1D* ZPTres_pos;
    TH1D* ZPTres_neg;

    TH2D* ZPTvsMHT; 
    TH2D* ZLPvsLP ;
    TH1D* ZmassmuRaw;

    TH1D* ZLPMHT ;
    TH1D* ZLPMHT_pos ;
    TH1D* ZLPMHT_neg ;

    TH1D* ZMHTpl;
    TH1D* ZMHTpl_pos;
    TH1D* ZMHTpl_neg;
    TH1D* ZST;


    TH1D* CounterCtrl_pos;
    TH1D* CounterSgnl_pos;
    TH1D* NrOfJets_pos;
    TH1D* LP_pos;
    TH1D* LPmht_pos;
    TH1D* LPctrl_pos;
    TH1D* LPsig_pos;
    TH1D* MT_pos;
    TH1D* SumLepPt_pos;
    TH1D* LepPt_pos;
    TH1D* LepEta_pos;
    TH1D* LepPhi_pos;
    TH1D* PFMET_pos;
    TH1D* PFMHT_pos;
    TH1D* HT_pos;
    TH1D* MHT_pos;
    TH1D* DeltaPhiMuJ_pos;
    TH1D* DeltaPhiMETJ_pos;
    TH2D* LepEtaPhi_pos;
    TH2D* LPTvsPFMET_pos;
    TH2D* WPTvsST_pos;
    TH2D* PFMETvsLP_pos;
    TH2D* LepPtvsLP_pos;
    TH2D* STHT_tot;
    TH1D* DeltaPhiMuWPT_pos;
    TH1D* DeltaPhiMuWPT_neg;
    TH1D* DeltaPhiMuWPT_tot;
    TH2D* HTthrust;
    TH1D* CounterCtrl_neg;
    TH1D* CounterSgnl_neg;
    TH1D* LP_neg;
    TH1D* LPmht_neg;
    TH1D* LPctrl_neg;
    TH1D* LPsig_neg;
    TH1D* MT_neg;
    TH1D* SumLepPt_neg;
    TH1D* LepPt_neg;
    TH1D* LepEta_neg;
    TH1D* LepPhi_neg;
    TH1D* PFMET_neg;
    TH1D* PFMHT_neg;
    TH1D* HT_neg;
    TH1D* MHT_neg;
    TH1D* DeltaPhiMuJ_neg;
    TH1D* DeltaPhiMETJ_neg;
    TH2D* LepEtaPhi_neg;
    TH1D* NrOfJets_neg;
    TH2D* LPTvsPFMET_neg;
    TH2D* WPTvsST_neg;
    TH2D* PFMETvsLP_neg;
    TH2D* LepPtvsLP_neg;

    TH1D* CounterCtrl_tot;
    TH1D* CounterSgnl_tot;
    TH1D* LP_tot;
    TH1D* LPmht_tot;
    TH1D* LPfit_tot;
    TH1D* LPctrl_tot;
    TH1D* LPsig_tot;
    TH1D* MT_tot;
    TH1D* SumLepPt_tot;
    TH1D* LepPt_tot;
    TH1D* LepEta_tot;
    TH1D* LepPhi_tot;
    TH1D* PFMET_tot;
    TH1D* PFMHT_tot;
    TH1D* HT_tot;
    TH1D* HT_tot_thru;

    TH1D* MHT_tot;
    TH1D* NrOfJets_tot;
    TH1D* DeltaPhiMuJ_tot;
    TH1D* DeltaPhiMETJ_tot;
    TH2D* LepEtaPhi_tot; 
    TH2D* LPTvsPFMET_tot;
    TH2D* WPTvsST_tot;
    TH2D* PFMETvsLP_tot;
    TH2D* LepPtvsLP_tot;

    TH2D* PFMETtypeIvsLepPt_pos;
    TH2D* PFMETtypeIvsLepPt_neg;
    TH2D* PFMETtypeIvsLepPt_tot;

    TH1D* MT_lt03_tot;
    TH1D* MT_gt03_tot;
    TH1D* PFMETtypeOVPFMET;
    TH2D* PFMETtypeVSPFMET;

    TH1D* JetCorFactor;
    TH1D* JetCorFactorB;
    TH1D* Thrust;
    TH1D* ThrustPhi;

    TH1D* RelCombIso_pos;
    TH1D* RelCombIso_neg;
    TH1D* RelCombIso_tot;


    // Slava's binning
    TH1D* LPf_tot;
    TH1D* MTf_tot;
    TH1D* STf_tot;
    TH1D* LepPtf_tot;

  }; //~ANplots class

}

#endif
