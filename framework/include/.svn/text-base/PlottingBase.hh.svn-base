/*! \file PlottingBase.hh
 * \brief Header file for the PlottingBase plotting operation base class.
 */

#ifndef PlottingBase_hh
#define PlottingBase_hh

#include "TFile.h"
#include "Operation.hh"
#include <vector>
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TString.h"
#include "TDirectory.h"

  /*! \brief Plotting Operation base class.
   *
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class PlottingBase : public Operation::_Base {

  public:

    PlottingBase(); //!< Constructor
    virtual  ~PlottingBase(){}; //!< Destructor

    // this method should be overwritten by inheriting classes

    /*! \brief Method for booking the histograms, to be overwritten by the user's Plotting Operation.
     */
    virtual void BookHistos() = 0;//{cout << "PlottingBase:: missing declaration of BookHistosin your inheriting class." <<endl;};

    /*! \brief Initialises the directory for the plotting operation's plots.
     * @param aFileOut [in] Pointer to the ROOT file to write to.
     * @param folderName [in] The name of the folder to add the histograms to.
     */
    void initDir(TDirectory* aFileOut, const char* folderName);

    TDirectory* returnDir(TDirectory* aFileOut, const char* folderName);

    TString GetInt(UInt_t myInt);

    /*! \brief Method for booking arrays of 2D histograms.
     */
    void  BookHistArray(std::vector<TH1D *> & histarray, TString histname,  TString title,
                        UInt_t xbins, Double_t xmin, Double_t xmax,
			UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, Bool_t zero_is_all);

    void  BookHistArray(std::vector<TH1D *> & histarray, TString histname,  TString title,
                        UInt_t xbins, Double_t* xarray,
			UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, Bool_t zero_is_all);

    /*! \brief Method for booking arrays of 2D histograms.
     */
    void  BookHistArray(std::vector<TH2D *> & histarray, TString histname,  TString title,
                        UInt_t xbins, Double_t xmin, Double_t xmax,
                        UInt_t ybins, Double_t ymin, Double_t ymax,
			UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, Bool_t zero_is_all);
    
    void  BookHistArray(std::vector<TH2D *> & histarray, TString histname,  TString title,
                        UInt_t xbins, Double_t* xarray,
                        UInt_t ybins, Double_t ymin, Double_t ymax,
			UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, Bool_t zero_is_all);

    void BookHistArray(std::vector<TH3D *> & histarray, TString histname, TString title,
    UInt_t xbins, Double_t xmin, Double_t xmax,
    UInt_t ybins, Double_t ymin, Double_t ymax,
    UInt_t zbins, Double_t zmin, Double_t zmax,
    UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, Bool_t zero_is_all);


  private:

    //    put you fancy Histos here


  };
#endif
