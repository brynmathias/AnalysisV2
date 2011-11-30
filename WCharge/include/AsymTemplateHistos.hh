#ifndef AsymTemplateHistos_h
#define AsymTemplateHistos_h

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"
#include "RecoilCorrector.hh"

using namespace Event;

const static int EtaBins = 11;
const static int EtaChBins_=EtaBins*2;
//const double etabinup[EtaBins] = {0.4,0.8,1.2,1.6,2.0,2.4};//Note: this is the upper bin edge 
const double etabinup[EtaBins] = {0.2,0.4,0.6,0.8,1.0,1.2,1.6,//bin 1.2-1.6 includes the gap 1.4-1.6
				  1.8,2.0,2.2,2.4};//Note: this is the upper bin edge 
const TString etabin[EtaChBins_]={"_eta1_pos","_eta2_pos","_eta3_pos","_eta4_pos","_eta5_pos","_eta6_pos",
				  "_eta7_pos","_eta8_pos","_eta9_pos","_eta10_pos","_eta11_pos",
			          "_eta1_neg","_eta2_neg","_eta3_neg","_eta4_neg","_eta5_neg","_eta6_neg",
			          "_eta7_neg","_eta8_neg","_eta9_neg","_eta10_neg","_eta11_neg"};

const static int WptBins = 5;
const static int WptChBins_ = WptBins*2;
const double wptbinlow[WptBins] = {0,5,10,20,50};//Note: this is the lower bin edge 
const TString wptbin[WptChBins_]={"_wpt1_pos","_wpt2_pos","_wpt3_pos","_wpt4_pos","_wpt5_pos",
	"_wpt1_neg","_wpt2_neg","_wpt3_neg","_wpt4_neg","_wpt5_neg"};

const static int JetBins = 5; //0,1,2,3,4
const static int JetChBins_ = JetBins*2;
const int jetnbin[JetBins] = {0,1,2,3,4};
const TString jetbin[JetChBins_]={"_jet0_pos","_jet1_pos","_jet2_pos","_jet3_pos","_jet4_pos",
        "_jet0_neg","_jet1_neg","_jet2_neg","_jet3_neg","_jet4_neg"};


const std::string wp[6]={"_WP95","_WP90","_WP85","_WP80","_WP70","_WP60"};

class AsymTemplateHistos : public PlottingBase {
public:
	// Standard Operation methods.
	AsymTemplateHistos(const std::string & filename,
	Utils::ParameterSet &);
	~AsymTemplateHistos(); //!< Destructor.

	void Start(Event::Data & ev); //!< Start processing
	void End(Event::Data & ev) ;  //!< End processing
	bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

	std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
	void BookHistos();
	bool passIsolation (double track, double ecal, double hcal, double eta, int ieff);
	bool passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff);
	bool passConv (int v_missHits, double v_DCot, double v_Dist, int ieff);
	bool passID_AS(double v_dfi, double v_dhi, double eta);  
	bool fid(double eta);
	int getEta(Lepton const * lep);
	int getWpt(Lepton const * lep, double met, double met_phi);
	int getJet(Lepton const * lep, int nJet);
	double cor(double et,double eta,int runNumber);
	bool CheckCuts(double v_trk,double v_ecal,double v_hcal,double v_sihih,double v_dfi,double v_dhi,double v_hoe,double eta,int ieff);
	void SetTree(TTree * tree);
	void SetTreeVariables(float pt, float phi, int njet, float u1, float u2, float met );
	void SetTreeVariables(TLorentzVector *genBoson, TLorentzVector *recoBoson, TVector2 *sumLepton, TVector2 *pfMET, TVector2 *trkMET, float wt, int nJet, TTree *tree);

private:
  	RecoilCorrector *corrector;
	std::string ZDat;
	std::string ZMC;
	std::string WNew;
	std::string mFolderName;
	TH1F * h_met;
	TH1F * h_mt;
	TH1F * h_eta_sel[EtaChBins_]; 
	TH1F * h_eta_antisel[EtaChBins_];
	TH1F * h_TP[EtaChBins_];
	TH1F * h_TPC[EtaChBins_];
	TH1F * h_TPS[EtaChBins_];
	TH1F * h_wpt_sel[WptChBins_];
	TH1F * h_wpt_antisel[WptChBins_];
	TH1F * h_jet_sel[JetChBins_]; 
	TH1F * h_jet_antisel[JetChBins_];
	TH1F * h_TP_all;
	TH1F * h_TPC_all;
	TH1F * h_TPS_all;

	bool doRecoil;
	bool doTP;
	bool doRecoilNtuple;
	int recType;
	double jet_ET;
	double lep_ET;
	double lep_MT;
	double lep_VetoET;

	int lep_WP;
	int lep_VetoWP;   
	int lep_AntiWP;   

    	double lep_AntiDPhi_eb;
   	double lep_AntiDEta_eb;
    	double lep_AntiDPhi_ee;
   	double lep_AntiDEta_ee;

	bool lep_QCheck;

        int lep_MissHits[6];
        double lep_DCot[6];
        double lep_Dist[6];

	double lep_Trk_eb[6];
	double lep_Ecal_eb[6];
	double lep_Hcal_eb[6];
	double lep_sihih_eb[6];
	double lep_Dphi_eb[6];
	double lep_Deta_eb[6];
	double lep_HoE_eb[6];

	double lep_Trk_ee[6];
	double lep_Ecal_ee[6];
	double lep_Hcal_ee[6];
	double lep_sihih_ee[6];
	double lep_Dphi_ee[6];
	double lep_Deta_ee[6];
	double lep_HoE_ee[6];

	// lepton properties
	float _leppt;
	float _lepphi;

	// boson properties
	float _genpt;
	float _genphi;
	float _mass;
	float _pt;
	float _y;
	float _phi;

	//pfmet
	float _pfmet;
	float _pfmetphi;
	float _pfmt;
	float _pfu1;
	float _pfu2;

	//track met
	float _trkmet;
	float _trkmetphi;
	float _trkmt;
	float _trku1;
	float _trku2;

	float _weight;
	int _njet;

        TTree * iTree;

	double w;
}; //
#endif







