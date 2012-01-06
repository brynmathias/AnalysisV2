/*! \file MCPlottingOps.hh
 * \brief Header file for Monte Carlo-based plotting operations.
 */
#ifndef MCPlottingOps_hh
#define MCPlottingOps_hh

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TH1D.h"

namespace Operation {

  //=============================
  // Gen Particle Basic Plots
  //=============================
  /*!\brief Plots basic properties of the gen objects found in a sample.
   *
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class GenObjPlotByID : public PlottingBase {
    
  public:
    // Standard Operation methods.
    /*! \brief Constructor
     * @param filename [in] ROOT filename
     * @param foldername [in] Folder in which to store the plotting operation's plots.
     * @param pdgid [in] PDG ID of the particle in question.
     * @param numobj [in] The number of particles to look at in a given event.
     * @param anti [in] Boolean flag: True => look at antiparticles too (i.e. abs(pdg_id) ).
     */
    GenObjPlotByID(TFile* outFile, std::string filename,
		   Int_t pdgid,
		   UInt_t numobj,
		   Bool_t anti) : 
      foldername_(filename),
      pdgId_(pdgid), numObj_(numobj), anti_(anti) {  
      // Initialise the plots
      initDir(outFile,filename.c_str());
      BookHistos();
    };
    ~GenObjPlotByID(){}; //!< Destructor.
    bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void  BookHistos();
    
  private:
    // Operation private data members
    //--------------------------------
    // Input 
    std::string foldername_; //!< The name of the folder the plots are stored in.
    Int_t pdgId_; //!< PDS ID of the type of particle to look at.
    UInt_t numObj_; //!< The number of objects of the specified type to plot properties of.
    Bool_t anti_; //!< Whether or not to consider antiparticles too.
    //
    //
    // Histograms
    std::vector<TH1D *> hg_multiplicity_;  //!< Histograms for the multiplicity.
    std::vector<TH1D *> hg_E_; //!< Histogram for the object energy.
    std::vector<TH1D *> hg_Et_; //!< Histogram for the object transverse energy.
    std::vector<TH1D *> hg_Pt_; //!< Histogram for the object transverse momentum.
    std::vector<TH1D *> hg_eta_; //!< Histogram for the object pseudo-rapidity.
    std::vector<TH1D *> hg_m_; //!< Histogram for the object mass.
    
  }; // ~GenObjPlotByID class
  

} //~namespace Operation

#endif //~MCPlottingOps_hh
