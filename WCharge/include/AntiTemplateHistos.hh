#ifndef AntiTemplateHistos_h
#define AntiTemplateHistos_h

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;



const double AnTrk[6] = {6.0,3.0,3.0,2.5,2.5,2.5};
const double AnEcal[6] = {5.0,4.0,4.0,3.0,3.0,3.0};
const double AnHcal[6] = {5.0,5.0,5.0,5.0,5.0,5.0};
const double Ansihih[6] = {0.01,0.01,0.01,0.01,0.01,0.01};
const double AnDphi[6] = {0.04,0.02,0.02,0.02,0.02,0.02};
const double AnDeta[6] = {0.006,0.006,0.006,0.006,0.006,0.003};
const double AnHoE[6] = {0.05,0.05,0.02,0.02,0.02,0.02};

const double AnTrk_ee[6] = {6.0,1.5,0.8,0.8,0.8,0.8};
const double AnEcal_ee[6] = {2.5,2.5,2.5,2.5,2.0,2.0 };
const double AnHcal_ee[6] = {1.5,0.7,0.7,0.25,0.25,0.25};
const double Ansihih_ee[6] = {0.03,0.03,0.03,0.03,0.03,0.03};
const double AnDphi_ee[6] = {0.025,0.02,0.02,0.02,0.02,0.02};
const double AnDeta_ee[6] = {0.008,0.006,0.004,0.003,0.002,0.0015};
const double AnHoE_ee[6] = {0.025,0.025,0.025,0.0025,0.0025,0.0025};



class AntiTemplateHistos : public PlottingBase {
public:
	// Standard Operation methods.
	AntiTemplateHistos(const std::string & filename,
	Utils::ParameterSet &);
	~AntiTemplateHistos(); //!< Destructor.

	void Start(Event::Data & ev); //!< Start processing
	bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

	std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
	void BookHistos();
	bool passIsolation (double track, double ecal, double hcal, double eta, int ieff);
	bool passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff);
	bool fid(double eta);
	bool CheckCuts(double v_trk,double v_ecal,double v_hcal,double v_sihih,double v_dfi,double v_dhi,double v_hoe,double eta,int ieff);
	
private:
	std::string mFolderName;
	double elecET;
	
	TH1F * h_pfMET;
	TH1F * h_pfMET_presel;
	TH1F * h_pfMET_antiDhi90;


	TH1F * h_pfMET_eiso90_antiDhiDfi90;
	TH1F * h_pfMET_eiso80_antiDhiDfi90;
	TH1F * h_pfMET_eiso70_antiDhiDfi90;
	TH1F * h_pfMET_eiso60_antiDhiDfi90;

	TH1F * h_pfMET_antiDhi_90_eta1_pos;
	TH1F * h_pfMET_eiso90_antiDhiDfi90_eta1_pos;
	TH1F * h_pfMET_eiso80_antiDhiDfi90_eta1_pos;
	TH1F * h_pfMET_eiso70_antiDhiDfi90_eta1_pos;
	TH1F * h_pfMET_eiso60_antiDhiDfi90_eta1_pos;


	TH1F * h_pfMET_antiDhi_90_eta2_pos;
	TH1F * h_pfMET_eiso90_antiDhiDfi90_eta2_pos;
	TH1F * h_pfMET_eiso80_antiDhiDfi90_eta2_pos;
	TH1F * h_pfMET_eiso70_antiDhiDfi90_eta2_pos;
	TH1F * h_pfMET_eiso60_antiDhiDfi90_eta2_pos;


	TH1F * h_pfMET_antiDhi_90_eta3_pos;
	TH1F * h_pfMET_eiso90_antiDhiDfi90_eta3_pos;
	TH1F * h_pfMET_eiso80_antiDhiDfi90_eta3_pos;
	TH1F * h_pfMET_eiso70_antiDhiDfi90_eta3_pos;
	TH1F * h_pfMET_eiso60_antiDhiDfi90_eta3_pos;


	TH1F * h_pfMET_antiDhi_90_eta1_neg;
	TH1F * h_pfMET_eiso90_antiDhiDfi90_eta1_neg;
	TH1F * h_pfMET_eiso80_antiDhiDfi90_eta1_neg;
	TH1F * h_pfMET_eiso70_antiDhiDfi90_eta1_neg;
	TH1F * h_pfMET_eiso60_antiDhiDfi90_eta1_neg;


	TH1F * h_pfMET_antiDhi_90_eta2_neg;
	TH1F * h_pfMET_eiso90_antiDhiDfi90_eta2_neg;
	TH1F * h_pfMET_eiso80_antiDhiDfi90_eta2_neg;
	TH1F * h_pfMET_eiso70_antiDhiDfi90_eta2_neg;
	TH1F * h_pfMET_eiso60_antiDhiDfi90_eta2_neg;


	TH1F * h_pfMET_antiDhi_90_eta3_neg;
	TH1F * h_pfMET_eiso90_antiDhiDfi90_eta3_neg;
	TH1F * h_pfMET_eiso80_antiDhiDfi90_eta3_neg;
	TH1F * h_pfMET_eiso70_antiDhiDfi90_eta3_neg;
	TH1F * h_pfMET_eiso60_antiDhiDfi90_eta3_neg;


        TH1F * h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEP;
        TH1F * h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEM;
        TH1F * h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEP;
        TH1F * h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEM;

  bool chChk;
}; // ~WChSelect class

#endif







