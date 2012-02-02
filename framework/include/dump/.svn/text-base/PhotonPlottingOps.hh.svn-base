/*! \file PhoPlottingOps.hh
 * \brief Header file for photonic analysis plotting operations.
 */
#ifndef PhoPlottingOps_hh
#define PhoPlottingOps_hh

#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh"
#include "PlottingBase.hh"
#include "TH1D.h"

namespace Operation {
    //===============================================
    // Plotting operation for common photon
    //===============================================
    /*!\brief Plotting operation for common photons and matched-to-gen common photons
    *
    * The matched-to-gen common photons are those who have been matched using a
    * $\Delta R$ cone method to a PDG ID==22 gen status 3 particle (see EventData
    * for more info). So not necessarily "signal" gen photons...
    * \date April 2009
    * \author Tom Whyntie
    * \version 1.1
    */
  class PlotComPhotons : public PlottingBase  {
    
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param outFile [in] Pointer to the ROOT file storing the histograms.
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     * @param num_photons [in] The number of common photons to plot for
     */
    PlotComPhotons(TFile* outFile, std::string foldername,
		   UInt_t num_photons) :
      foldername_(foldername),
      // User input variables...
      num_photons_(num_photons)
    {   
      initDir(outFile,foldername.c_str()); // Initialises the TDirectory in the ROOT file.
      BookHistos(); // Book histograms (see below)
    };
    
    ~PlotComPhotons(){}; //!< Destructor.
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - books your histograms (you need to implement this).
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string foldername_; //!< The foldername for plot storage.
    // User input members
    UInt_t num_photons_; //!< The number of common photons to plot.
    //
    // Histograms
    std::vector<TH1D *> hg_multi_; //!< Vector for multiplicity histogram.
    
    std::vector<TH1D *> hg_E_;  //!< Vector for histogram of E.
    std::vector<TH1D *> hg_Et_;  //!< Vector for histogram of Et.
    std::vector<TH1D *> hg_Pt_;  //!< Vector for histogram of Pt.
    std::vector<TH1D *> hg_eta_;  //!< Vector for histogram of eta.
    std::vector<TH1D *> hg_m_;  //!< Vector for histogram of m.
    
    std::vector<TH1D *> hg_trkiso_;  //!<
    std::vector<TH1D *> hg_ecaliso_;  //!<
    std::vector<TH1D *> hg_hcaliso_;  //!<
    std::vector<TH1D *> hg_alliso_;  //!<
    std::vector<TH1D *> hg_id_;  //!<
    std::vector<TH1D *> hg_cc_;  //!<
    
    // Plot the common photons that have been matched to gen photons.
    std::vector<TH1D *> hg_matched_; //!< 0=> common photon not matched 1=>common photon matched
    std::vector<TH1D *> hg_matched_multi_; //!< Vector for multiplicity histogram.
    
    std::vector<TH1D *> hg_matched_E_;  //!< Vector for histogram of E.
    std::vector<TH1D *> hg_matched_Et_;  //!< Vector for histogram of Et.
    std::vector<TH1D *> hg_matched_Pt_;  //!< Vector for histogram of Pt.
    std::vector<TH1D *> hg_matched_eta_;  //!< Vector for histogram of eta.
    std::vector<TH1D *> hg_matched_m_;  //!< Vector for histogram of m.
    
    std::vector<TH1D *> hg_matched_trkiso_;  //!<
    std::vector<TH1D *> hg_matched_ecaliso_;  //!<
    std::vector<TH1D *> hg_matched_hcaliso_;  //!<
    std::vector<TH1D *> hg_matched_alliso_;  //!<
    std::vector<TH1D *> hg_matched_id_;  //!<
    std::vector<TH1D *> hg_matched_cc_;  //!<
    
  }; // ~PlotComPhotons class
  
  
  //===============================================
  // Plotting operation for signal photon analysis
  //===============================================
  /*!\brief Plotting operation for signal gen and matched-to-gen preconfig, common and good photons
   *
   * \date April 2009
   * \author Tom Whyntie
   * \version 1.1
   */
  class PlotSigPhotons : public PlottingBase {
    
  public:
        // Standard Operation methods.
        /*! \brief Constructor
         * @param outFile [in] Pointer to ROOT file for histogram storage.
         * @param foldername [in] Folder in which to store the plotting operation's plots.
         */
    PlotSigPhotons(TFile* outFile, std::string foldername) : 
      foldername_(foldername)
    {
      initDir(outFile, foldername.c_str());
      BookHistos();
    };
    
    ~PlotSigPhotons(){}; //!< Destructor.
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos();
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string foldername_; //!< Name of the TDirectory for storing the histograms in the ROOT file.
    //
    // Histograms
    //------------
    // Gen signal photons
    std::vector<TH1D *> hg_gen_multi_; //!< Signal photon multiplicity.
    std::vector<TH1D *> hg_gen_E_;  //!< Vector for histogram of E.
    std::vector<TH1D *> hg_gen_Et_;  //!< Vector for histogram of Et.
    std::vector<TH1D *> hg_gen_Pt_;  //!< Vector for histogram of Pt.
    std::vector<TH1D *> hg_gen_eta_;  //!< Vector for histogram of eta.
    std::vector<TH1D *> hg_gen_m_;  //!< Vector for histogram of m.
    //
    // Preconfigured photons matched to signal photons
    std::vector<TH1D *> hg_mat_multi_; //!< Matched preconf photon multiplicity.
    std::vector<TH1D *> hg_mat_E_;  //!< Vector for histogram of E.
    std::vector<TH1D *> hg_mat_Et_;  //!< Vector for histogram of Et.
    std::vector<TH1D *> hg_mat_Pt_;  //!< Vector for histogram of Pt.
    std::vector<TH1D *> hg_mat_eta_;  //!< Vector for histogram of eta.
    std::vector<TH1D *> hg_mat_m_;  //!< Vector for histogram of m.
    //
    std::vector<TH1D *> hg_mat_trkiso_;  //!< 
    std::vector<TH1D *> hg_mat_ecaliso_;  //!<
    std::vector<TH1D *> hg_mat_hcaliso_;  //!<
    std::vector<TH1D *> hg_mat_alliso_;  //!<
    std::vector<TH1D *> hg_mat_id_;  //!<
    std::vector<TH1D *> hg_mat_cc_;  //!<
    //
    // Common photons matched to signal photons
    std::vector<TH1D *> hg_commat_multi_; //!< Matched common photon multiplicity.
    std::vector<TH1D *> hg_commat_E_;  //!< Vector for histogram of E.
    std::vector<TH1D *> hg_commat_Et_;  //!< Vector for histogram of Et.
    std::vector<TH1D *> hg_commat_Pt_;  //!< Vector for histogram of Pt.
    std::vector<TH1D *> hg_commat_eta_;  //!< Vector for histogram of eta.
    std::vector<TH1D *> hg_commat_m_;  //!< Vector for histogram of m.
    //
    std::vector<TH1D *> hg_commat_trkiso_;  //!< 
    std::vector<TH1D *> hg_commat_ecaliso_;  //!<
    std::vector<TH1D *> hg_commat_hcaliso_;  //!<
    std::vector<TH1D *> hg_commat_alliso_;  //!<
    std::vector<TH1D *> hg_commat_id_;  //!<
    std::vector<TH1D *> hg_commat_cc_;  //!<
    //
    // Good photons matched to signal photons
    std::vector<TH1D *> hg_gdmat_multi_; //!< Matched good photon multiplicity.
    std::vector<TH1D *> hg_gdmat_E_;  //!< Vector for histogram of E.
    std::vector<TH1D *> hg_gdmat_Et_;  //!< Vector for histogram of Et.
    std::vector<TH1D *> hg_gdmat_Pt_;  //!< Vector for histogram of Pt.
    std::vector<TH1D *> hg_gdmat_eta_;  //!< Vector for histogram of eta.
    std::vector<TH1D *> hg_gdmat_m_;  //!< Vector for histogram of m.
    //
    std::vector<TH1D *> hg_gdmat_trkiso_;  //!< 
    std::vector<TH1D *> hg_gdmat_ecaliso_;  //!<
    std::vector<TH1D *> hg_gdmat_hcaliso_;  //!<
    std::vector<TH1D *> hg_gdmat_alliso_;  //!<
    std::vector<TH1D *> hg_gdmat_id_;  //!<
    std::vector<TH1D *> hg_gdmat_cc_;  //!<
    
  }; // ~PlotSigPhotons class

  //=============================
  // Good photon plots
  //=============================
  /*!\brief Plots related to the "good" photons and jets identified in an event.
   *
   * \date April 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class GoodPhoPlots : public PlottingBase {
    
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param filename [in] ROOT filename
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     * @param [param1_name] [in] [Parameter 1 description]
     */
    GoodPhoPlots(TFile* outFile, std::string foldername //,
		 //[param1_type] [param1_name] //,
		 ) :
      foldername_(foldername) //,
      // User input variables...
      //param1_(param1_name)
    {
      initDir(outFile,foldername.c_str()); // Initialises the TDirectory in the ROOT file.
      BookHistos(); // Book histograms (see below)
    };
    
    ~GoodPhoPlots() {}; //!< Destructor.
    bool Process(Event::Data & ev); //!< Processes the event, making plots in this case. Always returns true for plotting.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - book your histograms (you need to implement this).
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string foldername_; //!< ROOT folder name to save histograms to.
    //[param1_type] [param1_name]_; //!< [param1 description]
    //
    TH1D * hg_gdpho_multi_; //!< Multiplicity of the good photons + good jets.
    TH1D * hg_gdphopho_multi_; //!< Multiplicity of the good photons.
    TH1D * hg_gdphojet_multi_; //!< Multiplicity of the good jets.
    
    // Histograms
    TH1D * hg_HT_;  //!<
    TH1D * hg_MHT_;  //!<
    TH1D * hg_MHToverHT_;  //!<
    //std::vector<TH1D *> hg_HT_;  //!<
    //std::vector<TH1D *> hg_MHT_;  //!<
    //std::vector<TH1D *> hg_MHToverHT_;  //!<
    
  }; // ~GoodPhoPlots class
  
  //=============================
  // Good photon kinematic plots
  //=============================
  /*!\brief Plots related to the kinematics of the "good" photons and jets identified in an event.
   *
   * \date April 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class GoodPhoKinPlots : public PlottingBase {
    
  public:
    GoodPhoKinPlots(TFile* outFile, std::string foldername) : foldername_(foldername) //,
    {
      initDir(outFile,foldername.c_str()); // Initialises the TDirectory in the ROOT file.
      BookHistos(); // Book histograms (see below)
    };
    
    ~GoodPhoKinPlots() {}; //!< Destructor.
    bool Process(Event::Data & ev); //!< Processes the event, making plots in this case. Always returns true for plotting.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - book your histograms (you need to implement this).
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string foldername_; //!< ROOT folder name to save histograms to.
    
    // Histograms
    TH1D * hg_MT_;  //!<
    TH1D * hg_MinDHT_;  //!<
    TH1D * hg_AlphaT_;  //!<
    
  }; // ~GoodPhoKinPlots class

} //~namespace Operation

#endif //~PhoPlottingOps_hh
