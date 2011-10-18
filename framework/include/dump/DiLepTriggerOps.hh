/*! \file DiLepTriggerOps.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef DiLepTriggerOps_hh
#define DiLepTriggerOps_hh

#include "PlottingBase.hh"
#include "Operation.hh"

#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"

namespace Operation {

    /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class DiLepTriggerTest : public PlottingBase   {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    DiLepTriggerTest(TFile* outFile,
		     const std::string & folderName,
		     const std::string & triggerFile);
    
    ~DiLepTriggerTest(); //!< Destructor.

    /*! \brief TriggerTest the required event data.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
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
    const std::string mFileName;   //!< ROOT file name to save histograms to.
    const std::string mFolderName; //!< ROOT folder name to save histograms to.    
    TFile *  FileOut; 
    TDirectoryFile * mydir;

    // Histograms
    //------------
    const static int dilepFinalStates   = 6;
    TH1D *h_ss_trig_ejet;
    std::vector<TH1D*> h_trig_den_pt;
    std::vector<TH1D*> h_trig_num_pt;
    std::vector<TH1D*> h_trig_den_HT;
    std::vector<TH1D*> h_trig_num_HT;
    std::vector<double> SSTriggers;

    Double_t CalcComHT(const std::vector<TLorentzVector const *> & vtv);
    void CalcComMHT(const std::vector<TLorentzVector const *> & vtv,
		    TLorentzVector & res);

  }; // ~DiLepTriggerTest class


} //~namespace Operation

#endif //~TriggerOps_hh
