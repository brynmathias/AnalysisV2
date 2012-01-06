#ifndef ElPlottingOps_hh
#define ElPlottingOps_hh

#include "Functions.hh"
#include "MC7to10.hh"
#include "MCCSFramePlots.hh"
#include "MCPolPlots.hh"
#include "MCWPlots.hh"
#include "RECOCSFramePlots.hh"
#include "RECOPolPlots.hh"
#include "WPol.hh"

namespace eWPol{
class RECOPolPlots : public PlottingBase {

 public:
  // Standard Operation methods.

  RECOPolPlots(const std::string & foldername,const Utils::ParameterSet &);
  ~RECOPolPlots();
  void BookHistos();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream& Description(std::ostream& ostrm);

 private:

  std::string mFolderName;
  bool mDoGen;
  WPol::LeptonType mLeptonType;
  double mMETThresh;

  Operation::jSolutionsW jRECOSol;
  std::vector<double> all_lh_minus;
  std::vector<double> all_lh_plus;
  TLorentzVector jGenLep, jGenW;

  //Histograms
  TH1D *RECO_tcMET, *RECO_pfMET;
  TH1D *RECO_ic5MET, *RECO_ak5MET;

  TH1D * RECO_LeptonPtPlus;
  TH1D * RECO_LeptonPtMinus;
  TH1D * RECO_LeptonEtaPlus;
  TH1D * RECO_LeptonEtaMinus;
  TH1D * RECO_LeptonEtaPlusAbs;
  TH1D * RECO_LeptonEtaMinusAbs;
  TH1D * RECO_CommonMHTPlus;
  TH1D * RECO_CommonMHTMinus;
  TH1D * RECO_ICVarPlus;
  TH1D * RECO_Fake_ICVarPlus;
  TH1D * RECO_HF_ICVarPlus;
  TH1D * RECO_Phot_ICVarPlus;

  TH1D * RECO_ICVarMinus;

  TH1D * RECO_ICVarMinus_LH;
  TH1D * RECO_ICVarPlus_LH;
  TH1D * RECO_ICVarMinus_RH;
  TH1D * RECO_ICVarPlus_RH;
  TH1D * RECO_ICVarMinus_LO;
  TH1D * RECO_ICVarPlus_LO;

  TH1D * RECO_ICVarPFMinus_LH;
  TH1D * RECO_ICVarPFPlus_LH;
  TH1D * RECO_ICVarPFMinus_RH;
  TH1D * RECO_ICVarPFPlus_RH;
  TH1D * RECO_ICVarPFMinus_LO;
  TH1D * RECO_ICVarPFPlus_LO;

  TH1D * RECO_ICVarPFMinus_VertexReweighting_LH;
  TH1D * RECO_ICVarPFPlus_VertexReweighting_LH;
  TH1D * RECO_ICVarPFMinus_VertexReweighting_RH;
  TH1D * RECO_ICVarPFPlus_VertexReweighting_RH;
  TH1D * RECO_ICVarPFMinus_VertexReweighting_LO;
  TH1D * RECO_ICVarPFPlus_VertexReweighting_LO;


  TH1D * RECO_ICVarTCPlus;
  TH1D * RECO_ICVarTCMinus;
  TH1D * RECO_ICVarPFPlus;
  TH1D * RECO_ICVarPFMinus;
  TH1D * RECO_ICVarIC5Plus;
  TH1D * RECO_ICVarIC5Minus;
  TH1D * RECO_ICVarAK5Plus;
  TH1D * RECO_ICVarAK5Minus;
  TH1D * RECO_TransMass;
  TH1D * RECO_CommonMHT;
  TH1D * RECO_LeptonPt;

  TH1D * MC_WPt;
  TH1D * MC_WYAbs;
  TH1D * MC_CosThetaStar1Plus;
  TH1D * MC_CosThetaStar1Minus;
  TH1D * MC_LeptonMultiplicity;
  TH1D * RECO_JetMultiplicity;
  TH1D * RECO_LeptonMultiplicity;
  TH1D * RECO_CosThetaStar1Sol1Plus;
  TH1D * RECO_CosThetaStar1Sol2Plus;
  TH1D * RECO_CosThetaStar1Sol1Minus;
  TH1D * RECO_CosThetaStar1Sol2Minus;
  TH1D * MC_RECO_LeptonMultMatch;
  TH1D * MC_RECO_MHTDiff;
  TH1D * MC_RECO_CaloMETDiff;
  TH1D * MC_RECO_TCMETDiff;
  TH1D * MC_RECO_PFMETDiff;
  TH1D * MC_RECO_IC5METDiff;
  TH1D * MC_RECO_AK5METDiff;
  TH1D * MC_RECO_LeptonPtDiff;
  TH1D * MC_RECO_LeptonEtaDiff;
  TH1D * MC_RECO_LeptonChargeId;

  TH1D *  RECO_Tr ;
  TH1D *  RECO_Ecal;
  TH1D *  RECO_Hcal;
  TH1D *  RECO_Com;
  TH1D *  RECO_DR;
  TH1D *  RECO_Type;
  TH1D *  RECO_2ndMass;

  TH2D * RECO_MHTvsTCMET;
  TH2D * RECO_MHTvsPFMET;
  TH2D * RECO_MHTvsCaloMET;
  TH2D * RECO_MHTvsAK5MET;
  TH2D * RECO_MHTvsIC5MET;
  TH2D * MC_WPtY;

  TProfile * MC_RECO_MHTDiffProfile;
  TProfile * MC_RECO_PFMHTDiffProfile;
}; //~RECOPolPlots class

class BasicPlots : public PlottingBase{
public:
BasicPlots(const std::string & dir,
             const Utils::ParameterSet & ps):
      mFolderName(dir),
      mLeptonType(WPol::GetLeptonType(ps.Get<std::string>("LeptonType"))),
      mNLeptons(ps.Get<int>("NLeptons")),
      mDoGen(ps.Get<bool>("DoGen"))
  {}

  ~BasicPlots(){}

  void BookHistos();
  bool Process(Event::Data &ev);
  double getCorrD0(double d0, double phi, double X, double Y );
  void Start(Event::Data &ev){
    initDir(ev.OutputFile(),mFolderName.c_str());
    BookHistos();
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Electron W Polarisation Plots : " << mFolderName;
    return ostrm;
  }
 private:
  TH1D* h_lep_combiso;
  TH1D* h_lep_hfcombiso;
  TH1D* h_lep_fakecombiso;
  TH1D* h_lep_EoverPin;
  TH1D* h_lep_EoverPout,*h_comlep_EoverPout;

  TH1D *h_ele_d0;

  TH1D *h_dilepton_mass;
  TH1D *h_dilepton_charge;
  TH1D * h_electron_mva;

  TH1D *h_dcot;
  TH1D *h_dist;
  TH1D *h_partner_track_expected;
  TH1D *h_MT;
  TH1D *h_pfMET;
  //barrel
  TH1D *h_barrel_EoverPin, *h_barrel_fbrem;
  TH1D *h_barrel_HoE, *h_barrel_SigmaIetaIeta;
  TH1D *h_barrel_DeltaEtaAtVtx, *h_barrel_DeltaPhiAtVtx;
  TH1D *h_barrel_TrkIso, *h_barrel_EcalIso, *h_barrel_HcalIso;

  TH2D *h_barrel_TrkIso_vsHT, *h_barrel_EcalIso_vsHT, *h_barrel_HcalIso_vsHT, *h_barrel_CombRelIso_vsHT;
  TH2D *h_barrel_TrkIso_vsMHT, *h_barrel_EcalIso_vsMHT, *h_barrel_HcalIso_vsMHT, *h_barrel_CombRelIso_vsMHT;

  //endcap
  TH1D *h_endcap_EoverPin, *h_endcap_fbrem;
  TH1D *h_endcap_HoE, *h_endcap_SigmaIetaIeta;
  TH1D *h_endcap_DeltaEtaAtVtx, *h_endcap_DeltaPhiAtVtx;
  TH1D *h_endcap_TrkIso, *h_endcap_EcalIso, *h_endcap_HcalIso;

  TH1D* h_mht;
  TH1D* h_comlep_combiso,*h_comlep_fake_combiso,*h_comlep_hf_combiso,*h_comlep_phot_combiso;
  TH1D* h_lep_photcombiso, *h_comlep_phot2_combiso, *h_lep_phot2combiso;
  TH1D* h_comlep_pt;
  TH2D *h_endcap_TrkIso_vsHT, *h_endcap_EcalIso_vsHT, *h_endcap_HcalIso_vsHT, *h_endcap_CombRelIso_vsHT;
  TH2D *h_endcap_TrkIso_vsMHT, *h_endcap_EcalIso_vsMHT, *h_endcap_HcalIso_vsMHT, *h_endcap_CombRelIso_vsMHT;

  const std::string mFolderName;
  WPol::LeptonType mLeptonType;
  int mNLeptons;
  bool mDoGen;
};

class TriggerEffPlot : public PlottingBase{
 public:
  TriggerEffPlot(const std::string & folder);
  ~TriggerEffPlot();
  void BookHistos();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  TH1D* h_trigger_eff;
  const std::string mFolderName;
  bool printed;
};

class ControlPlots : public PlottingBase{
 public:
  ControlPlots(const std::string folder, const Utils::ParameterSet & ps);
  ~ControlPlots();
  void BookHistos();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  const std::string mFolderName;
  double mPtCut;
  double mEtaCut;
  double mWPtCut;
  double mMTCut;
  Compute::ObjectFilter<Event::Lepton> *mFilter;
  TH1D* h_lp_plus;
  TH1D* h_wpt_plus;
  TH1D* h_elept_plus;
  TH1D* h_eleeta_plus;
  TH1D* h_elephi_plus;
  TH1D* h_pfmt_plus;
  TH1D* h_pfmet_plus;
  TH2D* h2d_nvertices_lp_plus;

  TH1D* h_lp_minus;
  TH1D* h_wpt_minus;
  TH1D* h_elept_minus;
  TH1D* h_eleeta_minus;
  TH1D* h_elephi_minus;
  TH1D* h_pfmt_minus;
  TH1D* h_pfmet_minus;
  TH2D* h2d_nvertices_lp_minus;

  TH1D* h_lp_all;
  TH1D* h_wpt_all;
  TH1D* h_elept_all;
  TH1D* h_eleeta_all;
  TH1D* h_elephi_all;
  TH1D* h_pfmt_all;
  TH1D* h_pfmet_all;
  TH2D* h2d_nvertices_lp_all;
};

class DataMCPlots : public PlottingBase{
 public:
  DataMCPlots(const std::string folder);
  ~DataMCPlots();
  void BookHistos();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  const std::string mFolderName;
  TH1D* h_lp_plus;
  TH1D* h_wpt_plus;
  TH1D* h_elept_plus;
  TH1D* h_eleeta_plus;
  TH1D* h_elephi_plus;
  TH1D* h_pfmt_plus;
  TH1D* h_pfmet_plus;
  TH1D* h_combiso_plus;
  TH2D* h2d_nvertices_lp_plus;
  TH1D* h_nvertices_plus;

  TH1D* h_lp_minus;
  TH1D* h_wpt_minus;
  TH1D* h_elept_minus;
  TH1D* h_eleeta_minus;
  TH1D* h_elephi_minus;
  TH1D* h_pfmt_minus;
  TH1D* h_pfmet_minus;
  TH1D* h_combiso_minus;
  TH2D* h2d_nvertices_lp_minus;
  TH1D* h_nvertices_minus;

  TH1D* h_lp_all;
  TH1D* h_wpt_all;
  TH1D* h_elept_all;
  TH1D* h_eleeta_all;
  TH1D* h_elephi_all;
  TH1D* h_pfmt_all;
  TH1D* h_pfmet_all;
  TH1D* h_combiso_all;
  TH2D* h2d_nvertices_lp_all;
  TH1D* h_nvertices_all;
};

class DebuggingPlots : public PlottingBase{
 public:
  DebuggingPlots(const std::string folder);
  ~DebuggingPlots();
  void BookHistos();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  const std::string mFolderName;
  TH1D* kfCharge;
  TH1D* scCharge;
  TH1D* gsfCharge;
};
}

#endif
