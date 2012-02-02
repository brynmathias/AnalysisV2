#ifndef AnalysisTree_hh
#define AnalysisTree_hh

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

using namespace Event;

namespace OneLepton{


  class AnalysisTree : public PlottingBase{
  public:
    AnalysisTree(const std::string & dir, const Utils::ParameterSet & ps):
      mFolderName(dir),
      leptonType_( ps.Get<std::string>("LeptonType") ),
      mMinNumOfObjs_( ps.Get<int>("MinNumOfObjs") ),
      mMaxNumOfObjs_( ps.Get<int>("MaxNumOfObjs") ),
      genInfo_( ps.Get<bool>("GenInfo") )
    {}

    ~AnalysisTree(){}
    
  
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
    bool genInfo_;

    int  lepFlavour;
    
    TTree *tree;

    // Event Variables
    double wgt;
    Int_t RunNumber, EventNumber, LumiSection, NumPVs;

    // Trigger
    bool trig_Mu9, trig_Mu15;
    bool trig_Ele15_LW, trig_Ele15_SW, trig_Ele17_SW_EleId;
    bool trig_Jet50, trig_Jet80;

    // Jet Variables
    int NJet, NGenJet;
    double JetPt[50], JetEta[50], JetPhi[50], JetCor[50], JetEMF[50];

    // Muon Variables
    int NMuons, MuonType[20], MuongPar[20], MuonGenMother[20];
    double MuonPt[20], MuonEta[20], MuonPhi[20], MuonChrg[20];

    // Jet-Muon Variables
    double MuonClosestPreJetPt[20];
    double MuonClosestPreJetEta[20], MuonClosestPreJetPhi[20], MuonClosestPreJetDR[20];
    double MuonClosestComJetPt[20];
    double MuonClosestComJetEta[20], MuonClosestComJetPhi[20], MuonClosestComJetDR[20];


    // Electron Variables
    int NElectrons, ElectronType[20], ElectrongPar[20], ElectronGenMother[20];
    double ElectronPt[20], ElectronEta[20], ElectronPhi[20], ElectronChrg[20];

    // Jet-Electron Variables
    double ElectronClosestPreJetDR[20], ElectronClosestPreJetPt[20], ElectronClosestComJetDR[20], ElectronClosestComJetPt[20];

    // General Kinematic Variables
    double AlphaT, AlphaT_Had, AlphaT_Lep;
    double HT, HT_Lep, MHT, MHTEta, MHTPhi, PFMHT, PFMHTEta, PFMHTPhi, CaloMET, CaloMETtypeII, RecoilMET, PFMET, PFMETPhi, MT, PFMT;
    double LP, PFLP;
    double BiasedDPhi, Meff;
 
    const std::string mFolderName;

  }; // ~end of class AnalysisTree


} // ~ end of namespace onelepton

#endif
