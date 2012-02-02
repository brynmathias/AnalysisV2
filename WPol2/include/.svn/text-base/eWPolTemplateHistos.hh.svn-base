#ifndef eWPolTemplateHistos_h
#define eWPolTemplateHistos_h

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"

#include "ElPlottingOps.hh"
#include "Utils.hh"
#include "Types.hh"
#include "TLorentzVector.h"

using namespace Event;

namespace WPol{

  const double Trk[6] = {0.15,0.12,0.09,0.09,0.05,0.04};
  const double Ecal[6] = {2.00,0.09,0.08,0.07,0.06,0.04};
  const double Hcal[6] = {0.12,0.10,0.10,0.10,0.03,0.03};


  const double RelIso[6] = {0.15,0.1,0.09,0.07,0.04,0.03};
  const double RelIso_ee[6]={0.1,0.07,0.06,0.06,0.03,0.02};

  const double sihih[6] = {0.01,0.01,0.01,0.01,0.01,0.01};
  const double Dphi[6] = {0.8,0.8,0.06,0.06,0.03,0.025};
  const double Deta[6] = {0.007,0.007,0.006,0.004,0.004,0.004};
  const double HoE[6] = {0.5,0.12,0.04,0.04,0.025,0.025};

  const double Trk_ee[6] = {0.08,0.05,0.05,0.04,0.025,0.025};
  const double Ecal_ee[6] = {0.06,0.06,0.05,0.05,0.025,0.02};
  const double Hcal_ee[6] = {0.05,0.03,0.025,0.025,0.02,0.02};
  const double sihih_ee[6] = {0.03,0.03,0.03,0.03,0.03,0.03};
  const double Dphi_ee[6] = {0.7,0.7,0.04,0.03,0.02,0.02};
  const double Deta_ee[6] = {0.01,0.009,0.007,0.007,0.005,0.005};
  const double HoE_ee[6] = {0.07,0.05,0.025,0.025,0.025,0.025};

  const int ConvMissHits[6] = {1,1,1,0,0,0};
  const double ConvDist[6] = {0.02,0.02,0.02,0.02,0.02,0.02};
  const double ConvDcot[6] = {0.02,0.02,0.02,0.02,0.02,0.02};

  TLorentzVector TLVConvert(const LorentzV * particle);

class eWPolTemplateHistos : public PlottingBase {

public:
	// Standard Operation methods.
  eWPolTemplateHistos(const std::string & filename,
		      Utils::ParameterSet &);
  ~eWPolTemplateHistos(); //!< Destructor.

  void Start(Event::Data & ev); //!< Start processing
  bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

  std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
  void BookHistos();
  bool passIsolation (double comb, double eta, int ieff);
  bool passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff);
  bool passConvRejection(bool expectedHits, double dist, double dcot, int ieff);
  bool fid(double eta);
  bool CheckCuts(double v_iso,double v_sihih,double v_dfi,double v_dhi,double v_hoe,double eta,int ieff);
  float dPhiCorr(double elePhi , double eleEta);
  float dEtaCorr(double elePhi , double eleEta);

private:
  std::string mFolderName;
  double elecET;
  /*	
  int nEle=4;
  
  double probe_ele_pt[nEle];
  double probe_ele_et[nEle];
  double probe_ele_eta[nEle];
  double probe_ele_charge[nEle];

  double probe_ele_dfi[nEle];
  double probe_ele_dhi[nEle];
  double probe_ele_hoe[nEle];
  double probe_ele_sihih[nEle];
  
  double probe_ele_ecal_iso_user[nEle];
  double probe_ele_hcal_iso_user[nEle];
  double probe_ele_combIso[nEle];

  double probe_ele_dcot[nEle];
  double probe_ele_dist[nEle];
  double probe_ele_expextedHitsInner[nEle];
  */
  TH1F * h_pfMET;
  TH1F * h_pfMET_presel;
  TH1F * h_pfMET_antiDhi_90;
  TH1F * h_pfMET_antiDhi_90_barl;
  TH1F * h_pfMET_antiDhi_90_endc;

  TH1F * h_pfMET_sel_90;
  TH1F * h_pfMET_sel_80;
  TH1F * h_pfMET_sel_70;
  TH1F * h_pfMET_sel_60;
  
  TH1F * h_pfMET_sel_90_barl;
  TH1F * h_pfMET_sel_80_barl;
  TH1F * h_pfMET_sel_70_barl;
  TH1F * h_pfMET_sel_60_barl;

  TH1F * h_pfMET_sel_90_endc;
  TH1F * h_pfMET_sel_80_endc;
  TH1F * h_pfMET_sel_70_endc;
  TH1F * h_pfMET_sel_60_endc;
  
  TH1F * h_pfMET_sel_90_pos;
  TH1F * h_pfMET_sel_80_pos;
  TH1F * h_pfMET_sel_70_pos;
  TH1F * h_pfMET_sel_60_pos;
  
  TH1F * h_pfMET_sel_90_neg;
  TH1F * h_pfMET_sel_80_neg;
  TH1F * h_pfMET_sel_70_neg;
  TH1F * h_pfMET_sel_60_neg;

  TH1F * h_pfMET_eiso90_antiDhiDfi90;
  TH1F * h_pfMET_eiso80_antiDhiDfi90;
  TH1F * h_pfMET_eiso70_antiDhiDfi90;
  TH1F * h_pfMET_eiso60_antiDhiDfi90;
  
  TH1F * h_pfMET_eiso90_antiDhiDfi90_barl;
  TH1F * h_pfMET_eiso80_antiDhiDfi90_barl;
  TH1F * h_pfMET_eiso70_antiDhiDfi90_barl;
  TH1F * h_pfMET_eiso60_antiDhiDfi90_barl;

  TH1F * h_pfMET_eiso90_antiDhiDfi90_endc;
  TH1F * h_pfMET_eiso80_antiDhiDfi90_endc;
  TH1F * h_pfMET_eiso70_antiDhiDfi90_endc;
  TH1F * h_pfMET_eiso60_antiDhiDfi90_endc;
  
  bool chChk;
  bool corrEE;
  bool useGEN;
  string useObservable;
  string eType;

};
}
#endif







