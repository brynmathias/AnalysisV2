#ifndef ElecBkgEval_hh
#define ElecBkgEval_hh
#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

namespace SSDL {

  class ElecBkgEval : public PlottingBase {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */
    ElecBkgEval(const std::string & folderName,
	      Utils::ParameterSet &);
    
    ~ElecBkgEval(); //!< Destructor.

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
    static const double PI                 = 3.14159265;

    TH2D* h_RecoElec_EtaPt;
    TH2D* h_IDElec_EtaPt;
    TH2D* h_nonIDElec_EtaPt;

    TH2D* h_RecoElec_EtaPt_HT0;
    TH2D* h_IDElec_EtaPt_HT0;
    TH2D* h_nonIDElec_EtaPt_HT0;

    TH2D* h_RecoElec_EtaPt_HT50;
    TH2D* h_IDElec_EtaPt_HT50;
    TH2D* h_nonIDElec_EtaPt_HT50;

    TH2D* h_RecoElec_EtaPt_HT150;
    TH2D* h_IDElec_EtaPt_HT150;
    TH2D* h_nonIDElec_EtaPt_HT150;

    TH2D* h_RecoElec_EtaPt_HT350;
    TH2D* h_IDElec_EtaPt_HT350;
    TH2D* h_nonIDElec_EtaPt_HT350;


    TH2D* h_IDElecEtaPt;
    TH2D* h_RecoElecEtaPt;

    TH2D* h_ElecEtaPt;
    TH2D* h_selElecEtaPt;
   
    TH2D* h_JetEtaPt;
    TH2D* h_selJetEtaPt;
    
    TH1D* h_HT_bc;
    TH1D* h_MHT_bc;
    TH1D* h_njet_bc;
    TH1D* h_nBjet_bc;
    TH1D* h_nIdMuon_bc;

    TH1D* h_isoSRCombRel_hlt;
    TH1D* h_isoSRCombRel_bjet;
    TH1D* h_isoSRCombRel_njet;
    TH1D* h_isoSRCombRel_mht;
    TH1D* h_isoSRCombRel_ht;
    //  TH1D* h_isoSRCombRel_ac;

    double mhtCut;
    double htCut;
    double metCut;
    double njetCut;
    bool MCAnal_;

  }; // ~ElecBkgEval class




  
} //~namespace SSDL

#endif 
