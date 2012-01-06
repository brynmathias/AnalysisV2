#ifndef ChAsymTemplateHistos_h
#define ChAsymTemplateHistos_h

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

const static int EtaChBins=61;
const static int AntiEvBins=7;

//(95%,90%,85%,80%,70%,60%, DavidF)
										//DavidF AS
const int MissHits[AntiEvBins] = {1,1,1,0,0,0,					0};
const double DCot[AntiEvBins] = {0.0, 0.02, 0.02, 0.02, 0.02, 0.02,		0.0};
const double Dist[AntiEvBins] = {0.0, 0.02, 0.02, 0.02, 0.02, 0.02,		0.0};

const double Trk[AntiEvBins] = {0.15,0.12,0.09,0.09,0.05,0.04,			0.0};
const double Ecal[AntiEvBins] = {2.00,0.09,0.08,0.07,0.06,0.04,			0.0};
const double Hcal[AntiEvBins] = {0.12,0.10,0.10,0.10,0.03,0.03,			0.0};
const double sihih[AntiEvBins] = {0.01,0.01,0.01,0.01,0.01,0.01,		0.0};  
const double Dphi[AntiEvBins] = {0.8,0.8,0.06,0.06,0.03,0.025,          0.06};
const double Deta[AntiEvBins] = {0.007,0.007,0.006,0.004,0.004,0.004,   0.007};
const double HoE[AntiEvBins] = {0.5,0.12,0.04,0.04,0.025,0.025,			0.0};

const double Trk_ee[AntiEvBins] = {0.08,0.05,0.05,0.04,0.025,0.025,		0.0};
const double Ecal_ee[AntiEvBins] = {0.06,0.06,0.05,0.05,0.025,0.02,		0.0};
const double Hcal_ee[AntiEvBins] = {0.05,0.03,0.025,0.025,0.02,0.02,	0.0};
const double sihih_ee[AntiEvBins] = {0.03,0.03,0.03,0.03,0.03,0.03,		0.0};
const double Dphi_ee[AntiEvBins] = {0.7,0.7,0.04,0.03,0.02,0.02,		0.04};
const double Deta_ee[AntiEvBins] = {0.01,0.009,0.007,0.007,0.005,0.005,		0.009};
const double HoE_ee[AntiEvBins] = {0.07,0.05,0.025,0.025,0.025,0.025,		0.0};


//const TString suff[EtaChBins]={"","_eta1_pos","_eta2_pos","_eta3_pos","_eta1_neg","_eta2_neg","_eta3_neg","_eta3_neg_EEP","_eta3_neg_EEM","_eta3_pos_EEM","_eta3_pos_EEP"};
const TString suff[EtaChBins]={"",
  "_eta1_pos","_eta2_pos","_eta3_pos","_eta4_pos","_eta5_pos","_eta6_pos",
  "_eta1_neg","_eta2_neg","_eta3_neg","_eta4_neg","_eta5_neg","_eta6_neg",
  "_eta1_pos_P","_eta2_pos_P","_eta3_pos_P","_eta4_pos_P","_eta5_pos_P","_eta6_pos_P",
  "_eta1_neg_P","_eta2_neg_P","_eta3_neg_P","_eta4_neg_P","_eta5_neg_P","_eta6_neg_P",
  "_eta1_pos_M","_eta2_pos_M","_eta3_pos_M","_eta4_pos_M","_eta5_pos_M","_eta6_pos_M",
  "_eta1_neg_M","_eta2_neg_M","_eta3_neg_M","_eta4_neg_M","_eta5_neg_M","_eta6_neg_M",
  "_eta1_pos_pt1","_eta2_pos_pt1","_eta3_pos_pt1","_eta4_pos_pt1","_eta5_pos_pt1","_eta6_pos_pt1",
  "_eta1_neg_pt1","_eta2_neg_pt1","_eta3_neg_pt1","_eta4_neg_pt1","_eta5_neg_pt1","_eta6_neg_pt1",
  "_eta1_pos_pt2","_eta2_pos_pt2","_eta3_pos_pt2","_eta4_pos_pt2","_eta5_pos_pt2","_eta6_pos_pt2",
  "_eta1_neg_pt2","_eta2_neg_pt2","_eta3_neg_pt2","_eta4_neg_pt2","_eta5_neg_pt2","_eta6_neg_pt2",		       
};

const TString AV[AntiEvBins]={"_95","_90","_85","_80","_70","_60","_DF"};

class ChAsymTemplateHistos : public PlottingBase {
public:
  // Standard Operation methods.
  ChAsymTemplateHistos(const std::string & filename,
  Utils::ParameterSet &);
  ~ChAsymTemplateHistos(); //!< Destructor.
  
  void Start(Event::Data & ev); //!< Start processing
  bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
  
  std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
  void BookHistos();
  bool passIsolation (double track, double ecal, double hcal, double eta, int ieff);
  bool passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff);
  bool passConv (int v_missHits, double v_DCot, double v_Dist, int ieff);
  bool passID_AS(double v_dfi, double v_dhi, double eta, int ieff);  
  bool fid(double eta);
  bool CheckCuts(double v_trk,double v_ecal,double v_hcal,double v_sihih,double v_dfi,double v_dhi,double v_hoe,double eta,int ieff);
  TString Suffix(double eta,double charge, double pt, int Option=0);
  void FillHistos(TString Prefix,TDirectory *Dir,double met,std::vector<Lepton const *>::const_iterator lep);
private:
  std::string mFolderName;
  double elecET;
  
  TH1F * h_dfi[EtaChBins][AntiEvBins];
  TH1F * h_dhi[EtaChBins][AntiEvBins];
  TH1F * h_dfi_dhi[EtaChBins][AntiEvBins];
  TH1F * h_sel[EtaChBins]; 

  bool chChk;
  bool convChk;
  bool lepVeto;
  double lepPtVeto;
  int wp;
  bool scEta;
  bool scEnergy;
  int ieff;
  double w;
}; //
#endif







