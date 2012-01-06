/*! \file DiLepMCOps.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef DiLepMCOps_hh
#define DiLepMCOps_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;

inline bool compareGenPt(const GenObject *o1, const GenObject *o2){
  return o1->Pt() > o2->Pt();
}


namespace SSDL {
  class FRMC : public PlottingBase {
    
  public:
 
    FRMC(const std::string & folderName,
	  Utils::ParameterSet &pset);
    
    ~FRMC(); //!< Destructor.

     
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.  
    std::ostream& Description(std::ostream& ostrm);
    void BookHistos();
  private:
    const  std::string mFolderName;
    double mhtCut;
    double htCut;   
    TH2D*  h_RecoTau_EtaPt;
    TH2D*  h_IDTau_EtaPt;
    TH2D*  hAllEl;
    TH2D*  hGoodEl;
    TH2D*  hAllMu;
    TH2D*  hGoodMu;
  }; // ~FRMC class
 
 class NOMC : public PlottingBase {
    
  public:
 
    NOMC(int);
    
    ~NOMC(); //!< Destructor.

     
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.  
    std::ostream& Description(std::ostream& ostrm);
    void BookHistos();
  private:
   int id_;

  }; // ~NOMC class


  class TTMC : public PlottingBase {
    
  public:
 
    TTMC(const std::string & folderName,
	 int);
    
    ~TTMC(); //!< Destructor.

     
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.  
    std::ostream& Description(std::ostream& ostrm);
    void BookHistos();
  private:
    int nmu_;
    const std::string mFolderName;
  }; // ~TTMC class


  //New class for plotting MC truths
  
  class SSDLMCTruth : public PlottingBase {
    
  public:

    SSDLMCTruth (const std::string & folderName, Utils::ParameterSet &);//TruthTest Constructor

    ~SSDLMCTruth();//TruthTest Destructor

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.  
   
    std::ostream& Description(std::ostream& ostrm);
    void BookHistos();

    private:

    const std::string mFolderName;
    
    float w;
    bool mSugraScan, MCAnal_;
    //Histograms

    TH2D *h_m0_m12_BeforeHLT;
    TH2D *h_m0_m12_BeforeHLT_nw;

    TH2D *h_m0_m12_BeforeHLT_gen2ss;
    TH2D *h_m0_m12_BeforeHLT_gen2ss_nw;


    
    TH2D *h_m0_m12_charg_toEle;
    TH2D *h_m0_m12_charg_toMu;
    TH2D *h_m0_m12_charg_toTau;
    TH2D *h_m0_m12_charg_toLep;

    TH2D *h_m0_m12_charg_toEle_nw;
    TH2D *h_m0_m12_charg_toMu_nw;
    TH2D *h_m0_m12_charg_toTau_nw;
    TH2D *h_m0_m12_charg_toLep_nw;




    TH2D *h_m0_m12_nchargino_nw;
    TH2D *h_m0_m12_nchargino;

    TH2D *h_m0_m12_chargino_nw;
    TH2D *h_m0_m12_chargino;




    TH1D *MCTruthNumFSLeps;
    TH1D *MCTruthSSDiLeps;
	  
    TH1D *MCTruthTauPt, *MCTruthTauPt15, *MCTruthTauEta, *MCTruthTauPt15Eta24;
    TH1D *MCTruthVisibleTauPt;
    
    TH1D *MCTruthSingleIsoLepPt;
    TH1D *MCTruthMultiIsoLepPt;
    
    TH1D *MCTruthSS_DEFAULT_EMPTY_Pt;
    TH1D *MCTruthSS_minus1_Pt;
    TH1D *MCTruthSS_0_Pt;
    TH1D *MCTruthSS_1_Pt;
    TH1D *MCTruthSS_2_Pt;
    TH1D *MCTruthSS_3_Pt;
    TH1D *MCTruthSS_4_Pt;
    TH1D *MCTruthSS_5_Pt;
    
    TH1D *MCTruthMuonPt;
    
    TH1D *MCTruthElecPt;
    
    
    TH1D *MCTruthElecPtCUT_Pt;
    TH1D *MCTruthElecPtCUT_Pt_eta;
    TH1D *MCTruthMuonPtCUT_Pt;
    TH1D *MCTruthMuonPtCUT_Pt_eta;
    TH1D *MCTruthTauPtCUT_Pt;
    TH1D *MCTruthTauPtCUT_Pt_eta;
    
    TH1D *MC_numTaus;

    TH1D *MC_MHT, *MC_HT;
  }; // ~ SSDLMCTruth class


  class SSDL_MC_PreSel : public Operation::_Base{
    
  public:
    
    SSDL_MC_PreSel(Utils::ParameterSet &pset);

    ~SSDL_MC_PreSel(){};

    bool Process(Event::Data & ev);
    
    std::ostream& Description(std::ostream& ostrm);

  private:
    
    bool _onlySS, _onlyOS;
    int _channel;


  };


} //~namespace SSDL

#endif //~MCOps_hh
