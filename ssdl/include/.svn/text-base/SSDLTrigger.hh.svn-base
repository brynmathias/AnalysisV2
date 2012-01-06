/*! \file SSDLTrigger.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef SSDLTrigger_hh
#define SSDLTrigger_hh
#include "PlottingBase.hh"
#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh"

#include "TH1D.h"
#include "TH2D.h"
#include "Utils.hh"


namespace SSDL {

    /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class SSDLTrigger : public PlottingBase   {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */

    SSDLTrigger(const std::string & folderName, Utils::ParameterSet &);
    
    ~SSDLTrigger(); //!< Destructor.
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev);

    /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
    void  BookHistos();
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    const std::string mFolderName; //!< ROOT folder name to save histograms to.
    // Histograms
    //------------
    const static int dilepFinalStates   = 6;
    std::vector<TH1D*> h_trig_den_pt;
    std::vector<TH1D*> h_trig_num_pt;
    float w;
    bool mSugraScan;

    TH1D *h_trig_HT_den;
    TH1D *h_trig_HT_num;
    TH1D *h_trig_MET_den;
    TH1D *h_trig_MET_num;   
    TH1D *h_trig_mu_den;
    TH1D *h_trig_mu_num;
    TH1D *h_trig_el_den;
    TH1D *h_trig_el_num;
    TH1D *h_trig_tau_den;
    TH1D *h_trig_tau_num;

    double MCAnal_;
    vector<string> triggerBits_;
  }; // ~SSDLTrigger class





} //~namespace SSDL

#endif //~Trigger_hh
