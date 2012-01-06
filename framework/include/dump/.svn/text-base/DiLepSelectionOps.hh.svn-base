/*! \file DiLepSelectionOps.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef DiLepSelectionOps_hh
#define DiLepSelectionOps_hh

#include "PlottingBase.hh"
#include "Operation.hh"

#include "TH1D.h"
#include "TH2D.h"
#include <algorithm>
using namespace Event;

namespace Operation {

    /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class DiLepSelectionTest : public PlottingBase {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    DiLepSelectionTest(TFile* outFile,
		       const std::string & folderName,
		       const std::string & selFile);

    ~DiLepSelectionTest(); //!< Destructor.

    /*! \brief SelectionTest the required event data.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    bool Process(Event::Data & ev);

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

    TH1D *h_ss_HT;
    TH1D *h_ss_MHT;
    TH1D *h_bc_MHT;
    TH1D *h_ss_NTAU;
    TH1D *h_ss_NMUON;
    TH1D *h_ss_NELEC;
    TH1D *h_ss_NLEPTON;
    TH1D *h_ss_NJET;
    TH1D *h_deltaphi;
    TH1D *h_St;
    TH1D *h_enFirstJet;
    TH1D *h_enSecJet;
    TH1D *h_DrMHTLep;
    TH1D *h_Charge;
    TH1D *h_bc_Charge;
    TH1D *h_bc_HT;
    TH1D *h_bc_St;
    TH1D *h_bc_lept;
    TH1D *h_bc_Alpha;
    TH1D *h_ac_Alpha;
    TH1D *h_ss_Alpha;
    std::vector<TH1D*> h_ss_ht;
    std::vector<TH1D*> h_ss_mht;
    std::vector<double> SSSelections;
    double mhtCut;
    double htCut;
    UInt_t leptonCut;
  }; // ~DiLepTriggerTest class





} //~namespace Operation

#endif //~TriggerOps_hh
