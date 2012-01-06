#ifndef TauBkgEval_hh
#define TauBkgEval_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

namespace SSDL {

  class TauBkgEval : public PlottingBase {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    TauBkgEval(const std::string & folderName);
    
    ~TauBkgEval(); //!< Destructor.

    /*! \brief Selection the required event data.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev);

    void  BookHistos();
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    const std::string mFolderName; //!< ROOT folder name to save histograms to.    


    TH2D* h_Tau_EtaPt;
    TH2D* h_WCTau_EtaPt;
    TH2D* h_MCTau_EtaPt;
    TH2D* h_matchedTau_EtaPt;
    TH1D* h_MCTau;
    TH1D* h_recoTau;
  }; // ~TauBkgEval class




  
} //~namespace SSDL

#endif 
