/*! \file MCOps.hh
 * \brief Header file for Monte Carlo (truth) information-based operations.
 */
#ifndef JetResponsePlottingOps_hh
#define JetResponsePlottingOps_hh

#include "Operation.hh"
#include "PlottingBase.hh"
#include "TH1D.h"
#include "TH2D.h"

namespace Operation {

  class JetCorPlot : public PlottingBase {

  public:
    /*! \brief Constructor.
     *
     * @param [in] fileName ROOT file name for histogram storage.
     * @param [in] folderName Name of the in-file storage file for the histograms.
     */
    JetCorPlot(TFile* outFile, std::string filename){   
      initDir(outFile,filename.c_str());
      BookHistos();
      the_TFile = outFile;
      the_filename = filename;
     } ;

    ~JetCorPlot(); //!< Destructor.
    /*! \brief Plots the specified leptonic analysis event information.
     *
     * @param [in] ev Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    bool Process(Event::Data & ev);

    void BookHistos();

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     *
     * @param [in] ostrm Reference to output stream (for output).
     * @return A reference to an output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

  private:

    TFile* the_TFile;// not to nice, just because calculations are done in the destructor
    std::string the_filename;// not to nice, just because calculations are done in the destructor
    TH2D *hg_ComJet_DeltaEvsE;
    TH2D *hg_ComJet_DeltaEtvsEt;
    TH2D *hg_ComJet_DeltaPtvsPt;
    TH2D *hg_ComJet_DeltaPtvsEta;    
    TH1D *hg_leadingJetRes;
    TH2D *hg_Jet_DeltaPhivsPt;
    TH2D *hg_Jet_DeltaPhivsEta;    
    TH2D *hg_leadJet_DeltaPhivsDeltaPhi;   
    
    TH2D *hg_ComJetParton_DeltaEvsE;
    TH2D *hg_ComJetParton_DeltaEtvsEt;
    TH2D *hg_ComJetParton_DeltaPtvsPt;
    TH2D *hg_ComJetParton_DeltaPtvsEta;    
    TH1D *hg_leadingJetRes_Parton;
    TH2D *hg_Jet_DeltaPhivsPt_Parton;
    TH2D *hg_Jet_DeltaPhivsEta_Parton;    
    TH2D *hg_leadJet_DeltaPhivsDeltaPhi_Parton;   
    

    TH1D *mean, *mean_vs_eta, *res;

  };

} //~namespace Operation

#endif //~JetCorPerformance_hh

