/*! \file LepPlottingOps.hh
 * \brief Header file for leptonic analysis plotting operations.
 */
#ifndef LepPlottingOps_hh
#define LepPlottingOps_hh

#include "Operation.hh"
#include "PlottingBase.hh"

#include "TH1D.h"
#include "TH2D.h"

#include "Math/VectorUtil.h"

namespace Operation {

  /*! \brief Lepton counting operation. A test.
   *
   * \author Tom Whyntie
   * \date February 2009
   * \version 1.1
   *
   */
  class LeptonCountPlot : public  PlottingBase {

  public:

    /*! \brief Constructor.
     *
     * @param [in] fileName ROOT file name for histogram storage.
     * @param [in] folderName Name of the in-file storage file for the histograms.
     */
    LeptonCountPlot(TFile* outFile, std::string filename) {   
      initDir(outFile,filename.c_str());
      BookHistos();
    };

    ~LeptonCountPlot() {}; //!< Destructor.

    /*! \brief Plots the specified leptonic analysis event information.
     *
     * @param [in] ev Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    bool Process(Event::Data & ev);

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     *
     * @param [in] ostrm Reference to output stream (for output).
     * @return A reference to an output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

    void BookHistos();

  private:

    // Histograms
    //------------
    TH1D * hg_NumCommonElectrons; //!< Histogram for the number of common electrons.

  }; // ~LeptonCountPlot class


  class SingleLepPlots : public PlottingBase {

  public:

    /*! \brief Constructor.
     *
     * @param [in] fileName ROOT file name for histogram storage.
     * @param [in] folderName Name of the in-file storage file for the histograms.
     */
    SingleLepPlots(const std::string & filename);
    ~SingleLepPlots(); //!< Destructor.

    void Start(Event::Data & ev);

    /*! \brief Plots the specified leptonic analysis event information.
     *
     * @param [in] ev Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    bool Process(Event::Data & ev);

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     *
     * @param [in] ostrm Reference to output stream (for output).
     * @return A reference to an output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

    void BookHistos();

  private:
    std::string mFolderName;

    // Operation private data members
    //--------------------------------
    // Histograms
    //------------
    TH1D * hg_ComLepMult; TH1D * hg_ComLepRecoil; //!< The lepton recoil for n(GdLeps)==1 
    TH1D *hg_ComEleRecoil, *hg_ComMuRecoil;
    TH1D *hg_ComEleCalo, *hg_ComMuCalo;
    TH1D *hg_ComEleccCalo, *hg_ComMuccCalo;
    TH1D *hg_NComJet, *he_NComJet, *hmu_NComJet;
    TH1D *he_ComMHT, *he_ComHT;
    TH1D *hmu_ComMHT, *hmu_ComHT;

    TH1D *hg_ComEleMult, *hg_ComMuMult;

    TH1D *hg_GdElectronRecoilMET_MT;  //!< The transverse mass for 1e,RecoilMET
    TH1D *hg_GdMuonRecoilMET_MT;      //!< The transverse mass for 1mu,RecoilMET
    TH1D *hg_GdElectronRecoilMET_dPhi;  //!< The deltaPhi for 1e,RecoilMET
    TH1D *hg_GdMuonRecoilMET_dPhi;      //!< The deltaPhi mass for 1mu,RecoilMET
    TH1D *hg_GdElectronRecoilMET_dPhi2;  //!< The deltaPhi for 1e,MHT
    TH1D *hg_GdMuonRecoilMET_dPhi2;      //!< The deltaPhi mass for 1mu,MHT

    TH1D *hg_GdElectron_PT; TH1D *hg_GdMuon_PT;
    TH1D *hg_GdElectron_PT2; TH1D *hg_GdMuon_PT2;

    TH2D *hg_GdElectron_cor1; TH2D *hg_GdElectron_cor2; TH2D *hg_GdElectron_cor3; TH2D *hg_GdElectron_cor4;
    TH2D *hg_GdMuon_cor1; TH2D *hg_GdMuon_cor2; TH2D *hg_GdMuon_cor3; TH2D *hg_GdMuon_cor4; TH2D *hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht;
    TH1D *hg_GdMuon_deltaphi_muon_commht; TH1D *hg_GdMuon_ratio_muonpt_commht;

    TH2D *hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_2jet;
    TH1D *hg_GdMuon_deltaphi_muon_commht_2jet; 
    TH1D *hg_GdMuon_ratio_muonpt_commht_2jet;

    TH2D *hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_3jet;
    TH1D *hg_GdMuon_deltaphi_muon_commht_3jet; 
    TH1D *hg_GdMuon_ratio_muonpt_commht_3jet;

    TH2D *hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_4jet;
    TH1D *hg_GdMuon_deltaphi_muon_commht_4jet; 
    TH1D *hg_GdMuon_ratio_muonpt_commht_4jet;

    TH2D *hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_5jet;
    TH1D *hg_GdMuon_deltaphi_muon_commht_5jet; 
    TH1D *hg_GdMuon_ratio_muonpt_commht_5jet;

    TH1D *hg_GdMuonpt, *hg_GdMuonpt_2jet, *hg_GdMuonpt_3jet, *hg_GdMuonpt_4jet, *hg_GdMuonpt_5jet;

    TH2D *he_MTHT, *he_MTMHT, *he_MTHTMHT, *he_MTSumET;
    TH2D *hm_MTHT, *hm_MTMHT, *hm_MTHTMHT, *hm_MTSumET;
    TH2D *he_MTMeff, *hm_MTMeff;

    TH2D *he_calogen, *he_recoilgen;
    TH2D *hm_calogen, *hm_recoilgen;
 
  }; // ~GoodLepPlots class

}
#endif 
