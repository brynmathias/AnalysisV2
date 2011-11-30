#ifndef AnalysisTree_HighPt_Data_hh
#define AnalysisTree_HighPt_Data_hh

//#include "BasicFilters.hh"
#include "Math/VectorUtil.h"
#include "PlottingBase.hh"
#include "Compare.hh"
#include "TTree.h"
#include "Operation.hh"
#include "Utils.hh"
#include "Types.hh"
#include "ICF_NtupleData.hh"
#include "EventData.hh"
#include "NtupleData.hh"
#include "MCData.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "GenMatrixBin.hh"

#include "Functions.hh"

using namespace Event;

namespace OneLepton{


  class AnalysisTree_HighPt_Data : public PlottingBase{
  public:
    AnalysisTree_HighPt_Data(const std::string & dir, const Utils::ParameterSet & ps):
      mFolderName(dir),
      leptonType_( ps.Get<std::string>("LeptonType") ),
      mMinNumOfObjs_( ps.Get<int>("MinNumOfObjs") ),
      mMaxNumOfObjs_( ps.Get<int>("MaxNumOfObjs") )
    {}

    ~AnalysisTree_HighPt_Data(){}
    
  
    void BookHistos();
    bool Process(Event::Data &ev);
    void Start(Event::Data &ev){
      initDir(ev.OutputFile(),mFolderName.c_str());
      BookHistos();
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Lepton tree : " << mFolderName;
      return ostrm;
    }
  private:
    std::vector <Event::Lepton const *> theLepton_;
    string leptonType_;
    UInt_t mMinNumOfObjs_;
    UInt_t mMaxNumOfObjs_;

    int  lepFlavour;
    
    TTree *tree;

    // Event Variables
    double wgt;
    Int_t RunNumber, EventNumber, LumiSection, NumPVs;

    // Trigger
    bool trig_Mu9, trig_Mu11, trig_Mu15, trig_Mu5_HT70U;
    bool trig_Ele15_LW, trig_Ele15_SW, trig_Ele17_SW_EleId;
    bool trig_Jet50, trig_Jet80;
    bool unpresc_trig_Mu9, unpresc_trig_Mu11, unpresc_trig_Mu15, unpresc_trig_Mu5_HT70U;
    bool unpresc_trig_Ele15_LW, unpresc_trig_Ele15_SW, unpresc_trig_Ele17_SW_EleId;
    bool unpresc_trig_Jet50, unpresc_trig_Jet80;

    // Jet Variables
    int NJet, NJet30, NJet40, NJet50, NJet60;
    double JetPt[50], JetEta[50], JetPhi[50], JetCor[50], JetEMF[50];

    // Jet-Raw Variables
    int NJetRaw;
    double JetRawPt[100], JetRawEta[100], JetRawPhi[100], JetRawCor[100];

    // Muon Variables
    int NMuons;
    double MuonPt[20], MuonEta[20], MuonPhi[20], MuonChrg[20];
    double MuonInrTrkD0BS[20], MuonInrTrkD0PV[20], MuonInrTrkD0err[20];
    double MuonGlbTrkD0BS[20], MuonGlbTrkD0PV[20], MuonGlbTrkD0err[20];
    double MuonRelCombIso[20];

    // Jet-Muon Variables
    double MuonClosestPreJetPt[20];
    double MuonClosestPreJetEta[20], MuonClosestPreJetPhi[20], MuonClosestPreJetDR[20];
    double MuonClosestComJetPt[20];
    double MuonClosestComJetEta[20], MuonClosestComJetPhi[20], MuonClosestComJetDR[20];


    // Electron Variables
    int NElectrons;
    double ElectronPt[20], ElectronEta[20], ElectronPhi[20], ElectronChrg[20];

    // Jet-Electron Variables
    double ElectronClosestPreJetDR[20], ElectronClosestPreJetPt[20], ElectronClosestComJetDR[20], ElectronClosestComJetPt[20];

    // General Kinematic Variables
    double AlphaT, AlphaT_Had, AlphaT_Lep, BiasedDPhi;

    // General Kinematic Variables -std-
    double HT, HT_Lep, MHT, MHTEta, MHTPhi, CaloMET, CaloMETtypeII, CaloMETtypeIIPhi, MT, LP, Meff;
    double PFMET, PFMETPhi, PFMHT_h, PFMT_h, PFLP_h;
    double PFMET_typeI;
    double HT12, HT123;
    double MHT12;
    double M2_sca, MinvMax;
    double M3_sca, M3_vec, M3lep_sca, M3lep_vec;
    double M_LepClosestJet, M_LepHighestJet, M_LepHighestJet2;
    double DPhi_LepMET, DPhi_LepMHT, DPhi_LepJetmin;
    double DPhi_Jet1Jet2, DR_Jet1Jet2;
    double DPhi_AllJetsMin, DR_AllJetsMin;

    // Razor variables
    double MR, MRt, R;
 
    const std::string mFolderName;

  }; // ~end of class AnalysisTree_HighPt_Data


} // ~ end of namespace onelepton

#endif
