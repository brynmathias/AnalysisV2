/*! \file FillABCDMethod.hh
 * \brief Header file for filling ABCD Plots operations.
 */
#ifndef FillABCDMethod_hh
#define FillABCDMethod_hh

#include "Operation.hh"
#include "EventData.hh"

#include "TH1D.h"
#include "TH2D.h"
#include <TProfile.h>

namespace Operation {


    /*! \brief ABCD method plotting operation.
   *
   * \date 4. March 2009
   * \author  Tanja Rommerskirchen
   * \version 1.1
   *
   */


class ABCDMethod   {

   public:

     /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param datasetname for histogram storage within ROOT file.
     * @param processName name for the ABCD variable combination called

     * @param var1Name name of the first variable generally the one on which one cut is applied
     * @param var2Name name of the second varialbe name of the second variable generally the one which is separated in bins

     * @param numberBins the number of bins you want for variable 1
     * @param MinVar2 starting value for the first bin in var1
     * @param MaxVar2 end value for the last bin in var1

     * @param numberBins the number of bins you want for variable 2
     * @param MinVar2 starting value for the first bin in var2
     * @param MaxVar2 end value for the last bin in var2

     * @param cutSignal the cut you apply on variable 1; per definition >cutSignal is signal <cutSignal is background
     */
  ABCDMethod(const std::string & fileName,
	     const std::string & processName,
	     TString var1Name,
	     TString var2Name,
	     UInt_t numberBinsVar1,
	     float MinVar1,
	     float MaxVar1,
	     UInt_t numberBinsVar2,
	     float MinVar2,
	     float MaxVar2,
	     Double_t cutSignal);

  ~ABCDMethod();//!< Destructor.

  /*! \brief fills the required ABCD methods
     * @param event weight
     * @param variable 1
     * @param variable 2
     * @return Always true - this is a plotting operation.
     */
    bool Process(Double_t weight, Double_t var1, Double_t var2);

  
  /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
  std::ostream& Description(std::ostream& ostrm);  

   private:
  // Operation private data members
  //--------------------------------
  TFile *  File; //output file
  float cut_signal; //cut on variable 1; > cut_signal (signal); < cut_signal (background)
  const std::string& process_name;
  
  // Profile plots
  //------------
  TProfile * ABCD_Profile;
  TH2D * ABCD_TH2D;

  // Histograms
  //------------
  TH1D *ABCD_PlotSignal;
  TH1D *ABCD_PlotBkgd;


}; //~ABCDMethod class







  /*! \brief class for calling ABCDMethods 
   */

  class CallABCDMethod : public Operation::_Base {

  public:

     /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param datasetname for histogram storage within ROOT file.
     */
    CallABCDMethod(const std::string & fileName);
    
    ~CallABCDMethod(); //!< Destructor.

  /*! \brief call the required ABCD variable combinations.
     * @param Reference to the event data.
     * @return Always true - this is a plotting operation.
     */
    bool Process(Event::Data & ev);


     /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    const std::string mFileName;   //!< ROOT file name to save histograms to.
      
    // ABCDMethods
    //------------
   
    ABCDMethod * recoilMET_vs_etaLeading;
   
    ABCDMethod * METsign_vs_etaLeading;

    ABCDMethod * alphaT_vs_etaLeading_HT_250_350;

    ABCDMethod * alphaT_vs_etaLeading_HT_350;

  };





}//~namespace Operation


#endif //~FillABCDMethod_hh
