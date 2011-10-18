/*! \file HadPlottingOps.hh
 * \brief Header file for the hadronic analysis plotting operations.
 */

#ifndef HadPlottingOps_hh
#define HadPlottingOps_hh

#include "Operation.hh"
#include "PlottingBase.hh"
#include "TH1D.h"

namespace Operation {

  /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class GoodHadPlots : public PlottingBase {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    GoodHadPlots(TFile* outFile, std::string filename) {   
      initDir(outFile,filename.c_str());
      BookHistos();
    };
    
    ~GoodHadPlots(); //!< Destructor.

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

    // Histograms
    //------------
    // no Histos yet


    const static int jetArrayLength = 6;
    void  BookArray(TH1D* histos[jetArrayLength],  TString name,TString title ,int bins, double min, double max);


  }; // ~GoodHadPlots class


    
    //===============================
    // PAT (preconf) JET PLOTTING OPERATION
    //===============================
    /*!\brief Plotting operation for preconfigured (PAT) jet properties
     *
     * \date April 2009
     * \author Tom Whyntie
     * \version 1.0
     */
  class PatJetPlots : public PlottingBase {
    
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param filename [in] ROOT filename
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     * @param numjets [in] The number of jets to plot for.
     */
    PatJetPlots(TFile* outFile, std::string foldername,
		UInt_t numjets //,
		) :
      foldername_(foldername),
      // User input variables...
      numjets_(numjets)
    {
      initDir(outFile,foldername.c_str()); // Initialises the TDirectory in the ROOT file.
      BookHistos(); // Book histograms (see below)
    };
    
    ~PatJetPlots() {}; //!< Destructor.
    bool Process(Event::Data & ev); //!< Processes the event, making plots in this case. Always returns true for plotting.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void BookHistos(); //!< Virtual method - book your histograms (you need to implement this).
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string foldername_; //!< ROOT folder name to save histograms to.
    UInt_t numjets_; //!< Number of individual jets to plot properties of.
    //
    // Histograms
    std::vector<TH1D *> hg_multi_;  //!<
    std::vector<TH1D *> hg_E_;  //!<
    std::vector<TH1D *> hg_Et_;  //!<
    std::vector<TH1D *> hg_Pt_;  //!<
    std::vector<TH1D *> hg_eta_;  //!<
    std::vector<TH1D *> hg_m_;  //!<
    std::vector<TH1D *> hg_emfrac_;  //!<
    
    std::vector<TH2D *> hg_Et_emfrac_; //!< 2D histogram for Et vs. EM fraction.
    std::vector<TH2D *> hg_eta_emfrac_; //!< 2D histogram for eta vs. EM fraction.
    
    std::vector<TH1D *> hg_emfail_E_;  //!<
    std::vector<TH1D *> hg_emfail_Et_;  //!<
    
  }; // ~PatJetPlots class
  
} // ~namespace Operation

#endif
