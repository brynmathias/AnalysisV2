/*! \file ComPlottingOps.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef ComPlottingOps_hh
#define ComPlottingOps_hh

#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "TTree.h"


using namespace Event;

namespace Operation {

  //===========================
  // ObjCountPlots
  //===========================
  /*!\brief Operation for plotting the number of physics objects in events in a given sample.
   *
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   *
   */
  class ObjCountPlots : public PlottingBase {

  public:
    // andard Operation methods.
    ObjCountPlots(const std::string & filename,
		  UInt_t Type);
    ~ObjCountPlots(); //!< Destructor.

    void  BookHistos();

    void Start(Event::Data & ev);
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.

  private:
 
    UInt_t mType; //!< Type of object to count: 0=> Preconfigured, 1=> Common.
    std::string mFolderName;

    // Histograms
    std::vector<TH1D *> hg_JetMultiplicity;  //!< Histogram of the number of jet objects counted in each event.
    std::vector<TH1D *> hg_EleMultiplicity;  //!< Histogram of the number of electron objects counted in each event.
    std::vector<TH1D *> hg_MuoMultiplicity;  //!< Histogram of the number of muon objects counted in each event.
    std::vector<TH1D *> hg_TauMultiplicity;  //!< Histogram of the number of tau objects counted in each event.
    std::vector<TH1D *> hg_PhoMultiplicity;  //!< Histogram of the number of photon objects counted in each event.
    std::vector<TH1D *> hg_ObjMultiplicity;  //!< Histogram of the total number of objects counted in each event.

    TH1D * hg_Gen_hard_JetMultiplicity;  //!< Histogram of the number of jet objects counted in each event.
    TH1D * hg_Gen_hard_EleMultiplicity;  //!< Histogram of the number of electron objects counted in each event.
    TH1D * hg_Gen_hard_MuoMultiplicity;  //!< Histogram of the number of muon objects counted in each event.
    TH1D * hg_Gen_hard_TauMultiplicity;  //!< Histogram of the number of tau objects counted in each event.
    TH1D * hg_Gen_hard_PhoMultiplicity;  //!< Histogram of the number of photon objects counted in each event.
    TH1D * hg_Gen_hard_ObjMultiplicity;  //!< Histogram of the total number of objects counted in each event.
    TH1D * hg_Gen_hard_TauMu;
    TH1D * hg_Gen_hard_TauEli;
    TH1D * hg_Gen_hard_TauHad;
    TH1D * hg_Gen_hard_Leptons;
    TH1D * hg_Gen_hard_TopPt;
    TH1D * hg_Gen_hard_TauPt;
    TH1D * hg_Gen_hard_MuonvsNU;
    TH1D * hg_Gen_hard_WPt;
    TH1D * hg_Gen_hard_MuonvsW;
    TH1D * hg_Gen_hard_WPtRes;
    TH1D * hg_Gen_hard_WMuPhi;
    TH1D * hg_Gen_hard_WNuPhi;
    TH1D * hg_WMuRatio;


  }; // ~ObjCountPlots class

  //======================================
  // Object Kinematics Plotting Operation
  //======================================
  /*!\brief Operation for plotting the kinematic properties of objects.
   *
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   *
   */
  class ObjKinPlots : public PlottingBase {
  public:
    // Standard Operation methods.
    ObjKinPlots(const std::string & folderName,
		UInt_t Type,
		UInt_t Nth);
    ~ObjKinPlots(); //!< Destructor.
 
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void  BookHistos();

  private:
    UInt_t mType; //!< The type of object to plot for (PDG ID. Jets use 100).
    UInt_t mNth; //!< The nth object to plot information for.
    std::string mFolderName;

    // Histograms
    std::vector<TH1D *> hg_E; //!< Histogram for the object energy.
    std::vector<TH1D *> hg_Et; //!< Histogram for the object transverse energy.
    std::vector<TH1D *> hg_Pt; //!< Histogram for the object transverse momentum.
    std::vector<TH1D *> hg_eta; //!< Histogram for the object pseudo-rapidity.
    std::vector<TH1D *> hg_deta; //!< Histogram for the object pseudo-rapidity.
    std::vector<TH1D *> hg_dr; //!< Histogram for the object pseudo-rapidity.
    std::vector<TH1D *> hg_m; //!< Histogram for the object mass.
  }; // ~ObjKinPlots class
  
  //========================================
  // Common object Kinematic Suite Plotting 
  //========================================
  /*!\brief Operation for plotting the kinematic suite variables for an event's common objects.
   *
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   *
   */
  class kinSuiteComPlot : public PlottingBase {
  public:
    // Standard Operation methods.
    kinSuiteComPlot(const std::string & filename,
		    int NumObjMax,
		    int NumObjMin);
    ~kinSuiteComPlot(); //!< Destructor.

    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();
    
  private:
    int mNumObjMax;
    int mNumObjMin;
    std::string mFolderName;

    // Histograms
    std::vector<TH1D *> hg_RecoilPt; //!<
    std::vector<TH1D *> hg_SumEt; //!< 
    std::vector<TH1D *> hg_RecoilPt_SumEt; //!< 
    std::vector<TH1D *> hg_M; //!< 
    std::vector<TH1D *> hg_MT; //!< 
    std::vector<TH1D *> hg_MinDPhi; //!< 
    std::vector<TH1D *> hg_MinBiasDPhi; //!<
    std::vector<TH1D *> hg_MinDEt; //!< 
    std::vector<TH1D *> hg_AlphaT; //!< 
		std::vector<TH1D *> hg_Meff; //!<
		std::vector<TH1D *> hg_Ht; //!<
		std::vector<TH1D *> hg_HtOver2sinPhiStar;

  }; // ~kinSuiteComPlot class


  /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class CommonPlots : public PlottingBase {
  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    CommonPlots(const std::string & folderName);
    ~CommonPlots(); //!< Destructor.

    void Start(Event::Data & ev);

    /*! \brief Plots the required event data.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    bool Process(Event::Data & ev);

    /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

    void BookHistos();

  private:    
    std::string mFolderName;

    // Histograms
    const static int jetArrayLength = 6;
    
    TH1D * hg_HT[jetArrayLength];    //!< Histogram of the HT for all events with good jets.
    TH1D * hg_MHT[jetArrayLength];    //!< Histogram of the HT for all events with good jets.
    TH1D * hg_dPhi[jetArrayLength];    //!< Histogram of the HT for all events with good jets.
    TH1D * hg_biasedPhi[jetArrayLength];    //!< Histogram of the HT for all events with good jets.
    TH1D * hg_Pt[jetArrayLength];    //!< Histogram of the HT for all events with good jets.
    TH1D * hg_Eta[jetArrayLength];    //!< Histogram of the HT for all events with good jets.
    TH1D * hg_JetMultiplicity;
    TH1D * hg_MScosT[jetArrayLength]; 
    TH1D * hg_cosT[jetArrayLength];
    TH1D * hg_caloMetdPhi[jetArrayLength];
    TH1D * hg_TeCoilMetdPhi[jetArrayLength];
    TH2D * caloMetR1R2;
    TH2D * recoilMetR1R2;
    TH1D * MPTMHTdPhi;
    TH1D * MPTMETdPhi;

    TH1D * hg_missed_MHT[jetArrayLength];
    TH1D * hg_missed_MHT_ov_MHT[jetArrayLength];
    TH1D * hg_missed_MHT_ov_HT[jetArrayLength];
    TH2D * hg_missed_MHT_vs_HT[jetArrayLength];
    TH2D * hg_missed_MHT_vs_MHT[jetArrayLength];
    TH1D * hg_missed_MHTvec_ov_MHT[jetArrayLength];

    TH1D * hg_CosThetaGen;
    TH1D * hg_WLepton;
    //    TH1D * hg_CosThetaGen;
  
    TH1D * hg_MHTovHT[jetArrayLength];  
    TH2D * hg_MHTovHT_biasdPhi[jetArrayLength];  
    TH2D * hg_MHTovHT_dPhi[jetArrayLength];  

    void  BookArray(TH1D* histos[jetArrayLength],  TString name,TString title ,int bins, double min, double max);
    void  BookArray(TH2D* histos[jetArrayLength],
		    TString name,
		    TString title,
		    int bins,
		    double min,
		    double max,
		    int binsY,
		    double minY,
		    double maxY);
    
  }; // ~CommonPlots class

  //=============================
  // SEARCH MATRIX PLOTTING
  //=============================
  /*! \brief Operation for "plotting" the search matrix for a given sample based on common object content.
   * \date April 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class ComSearchMatrix : public PlottingBase {
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     */
    ComSearchMatrix(const std::string & folderName,
		    UInt_t jetmax,
		    UInt_t lepmax,
		    UInt_t phomax);
    ~ComSearchMatrix(); //!< Destructor.
    
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev); //!< Processes the event, making plots in this case. Always returns true for plotting.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - book your histograms (you need to implement this).
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string mFolderName; //!< ROOT folder name to save histograms to.
    UInt_t jetmax_; //!< The maximum number of jets to count explicitly.
    UInt_t lepmax_; //!< The maximum number of leptons to count explicitly.
    UInt_t phomax_; //!< The maximum number of photons to count explicitly.
    
        //
        // Histograms
        std::vector<TH2D *> hg_jet_lep_;  //!< jets vs leptons (e, mu).
        std::vector<TH2D *> hg_jet_pho_;  //!< jets vs photons.

    }; // ~ComSearchMatrix class
  
  //===============================
  // COMMON JET PLOTTING OPERATION
  //===============================
  /*!\brief Plotting operation for common jet properties
   *
   * \date April 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class ComJetPlots : public PlottingBase {
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param filename [in] ROOT filename
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     * @param numcomjets [in] The number of common jets to plot for.
     */
    ComJetPlots(const std::string & foldername,
		UInt_t numcomjets);
    ~ComJetPlots(); //!< Destructor.
    
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev); //!< Processes the event, making plots in this case. Always returns true for plotting.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - book your histograms (you need to implement this).
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string mFolderName; //!< ROOT folder name to save histograms to.
    UInt_t numcomjets_; //!< Number of individual common jets to plot properties of.

    // Histograms
    std::vector<TH1D *> hg_multi_;  //!<
    std::vector<TH1D *> hg_E_;  //!<
    std::vector<TH1D *> hg_Et_;  //!<
    std::vector<TH1D *> hg_Pt_;  //!<
    std::vector<TH1D *> hg_eta_;  //!<
    std::vector<TH1D *> hg_m_;  //!<
    std::vector<TH1D *> hg_emfrac_;  //!<

    }; // ~ComJetPlots class

class ComPhoPlots : public PlottingBase {
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param filename [in] ROOT filename
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     * @param numcomphotons [in] The number of common photons to plot for.
     */
    ComPhoPlots(const std::string & foldername,
        UInt_t numcomphotons);
    ~ComPhoPlots(); //!< Destructor.

    void Start(Event::Data & ev);
    bool Process(Event::Data & ev); //!< Processes the event, making plots in this case. Always returns true for plotting.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - book your histograms (you need to implement this).

  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string mFolderName; //!< ROOT folder name to save histograms to.
    UInt_t numcomphotons_; //!< Number of individual common photons to plot properties of.

    // Histograms
    std::vector<TH1D *> hg_multi_;  //!<
    std::vector<TH1D *> hg_Et_;  //!<
    std::vector<TH1D *> hg_eta_;  //!<
    std::vector<TH1D *> hg_ecalIso_;  //!<
    std::vector<TH1D *> hg_hcalIso_;  //!<
    std::vector<TH1D *> hg_trackIso_;  //!<
    std::vector<TH1D *> hg_hadronicOverEm_;  //!<
    std::vector<TH1D *> hg_r9_;  //!<
    std::vector<TH1D *> hg_sigmaIetaIeta_;  //!<
    std::vector<TH1D *> hg_hasPixelSeed_;  //!<

    }; // ~ComPhoPlots class

/*
class StandardPlots : public PlottingBase {

  public:

    StandardPlots( const Utils::ParameterSet& );
    ~StandardPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
    Double_t MT2( Event::Data& );
    Double_t MT2_Leading( Event::Data& );

    std::string dirName_;
    std::string variable_;
    Double_t valueMin_;
    UInt_t nBins_;
    Double_t binWidth_;

    std::vector<TH1D*>  nVertices_;
    std::vector<TH1D*>  nJets_;
    std::vector<TH1D*>  Mt2_;
    std::vector<TH1D*>  AlphaT_;
    std::vector<TH1D*>  AlphaT_Hadronic_;
    std::vector<TH1D*>  HT_;
    std::vector<TH1D*>  Meff_;
    std::vector<TH1D*>  BiasedDphi_;
    std::vector<TH1D*>  MHToverHT_;
    std::vector<TH1D*>  HTover2SinDeltaPhi_;
    std::vector<TH1D*>  MHT_;
    std::vector<TH1D*>  ak5CaloMET_;
    std::vector<TH1D*>  pfMET_;
    std::vector<TH1D*>  tcMET_;
    std::vector<TH1D*>  PhotonPt_;
    std::vector<TH1D*>  PhotonEta_;
    std::vector<TH1D*>  PhotonEcalIso_;
    std::vector<TH1D*>  PhotonHcalIso_;
    std::vector<TH1D*>  PhotonTrackIso_;
    std::vector<TH1D*>  PhotonHoverE_;
    std::vector<TH1D*>  PhotonSigmaIetaIeta_;
    std::vector<TH1D*>  PhotonR9_;
    std::vector<TH1D*>  PhotonHasPixelSeed_;
    std::vector<TH1D*>  Jet1Pt_;
    std::vector<TH1D*>  Jet1Eta_;
    std::vector<TH1D*>  Jet1EmFrac_;
    std::vector<TH1D*>  Jet2Pt_;
    std::vector<TH1D*>  Jet2Eta_;
    std::vector<TH1D*>  Jet2EmFrac_;

    };

*/
class MetPlots : public PlottingBase {

  public:

    MetPlots( const Utils::ParameterSet& );
    ~MetPlots();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    std::string variable_;
    Double_t valueMin_;
    UInt_t nBins_;
    Double_t binWidth_;

    std::vector<TH1D*>  caloMet_;
    std::vector<TH1D*>  caloMetNoHf_;
    std::vector<TH1D*>  pfMet_;
    std::vector<TH1D*>  tcMet_;
    std::vector<TH1D*>  ak5CaloMet_;
    std::vector<TH1D*>  ic5CaloMet_;
    };


 class EventNoDump : public PlottingBase {
  public:
    // Standard Operation methods.
   EventNoDump(const std::string & folderName, std::string TreeName);
    ~EventNoDump(); //!< Destructor.
   // std::ofstream ostrm("event.txt");
   void Start(Event::Data & ev);
   bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void  BookHistos();
   //  std::iostream ostrm;

  private:
 
   std::string mFolderName;
   std::string mTreeName;
   // Histograms
   
   TTree * mTree; 
   int LS;
   int Run;
   int Event;


  }; // ~











} //~namespace Operation

#endif //~PlottingOps_hh
