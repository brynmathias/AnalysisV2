#ifndef TauFakeRate_hh
#define TauFakeRate_hh
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

namespace SSDL {

  class TauFakeRate : public PlottingBase {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    TauFakeRate(const std::string & folderName,
	      Utils::ParameterSet &);
    
    ~TauFakeRate(); //!< Destructor.

    /*! \brief Selection the required event data.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev);

    void  BookHistos();
    std::ostream& Description(std::ostream& ostrm);
    double        getDeltaR(double, double, double, double);
  private:
    // Operation private data members
    //--------------------------------
    const std::string mFolderName; //!< ROOT folder name to save histograms to.    
 

    TH2D* h_RecoTau_EtaPt;
    TH2D* h_IDTau_EtaPt;
    TH3D* h_LTau;
    TH3D* h_TTau;
    
    double upperHTCut;
    double upperMetCut;
    double mhtCut;
    double htCut;
    int looseIso_;
    bool lepReq_;
    bool mUseHps;
    string tauSrc;
  }; // ~TauFakeRate class
  
} //~namespace SSDL

#endif 
