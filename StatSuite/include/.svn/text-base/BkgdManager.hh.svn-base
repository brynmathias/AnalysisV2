/*! \file BkgdManager.hh
 * \brief Header file for the analysis Operation::Manager class.
 *
 */
#ifndef BkgdManager_h
#define BkgdManager_h

#include "Utils.hh"
#include "bkgdDataSets.hh"


#include "Utils.hh"
#include "Types.hh"


namespace Operation {

  /*! \brief %Operation manager for the ntuple-based analysis.
   *
   * \author CMS SUSY Dijet Analysis Team
   * \date October 2008
   * \version 1.1
   *
   */
  class BkgdManager {

  private:

   
    
    TH2F* CutAndCount(const Utils::ParameterSet& significance,const Utils::ParameterSet& cuts,const bkgdDataSets &bkgd_Var3range3,const bkgdDataSets &SplusB_Var3range3,const bkgdDataSets &Data_Var3range3,bkgdDataSets &QCD_Var3range3,bkgdDataSets &EWK_Var3range3,TString method);

    TH2F* RatioMethod(const Utils::ParameterSet& significance,const Utils::ParameterSet &cuts,const bkgdDataSets &B_Var3range3,const bkgdDataSets&SplusB_Var3range3,const bkgdDataSets &Data_Var3range3,TString method);
    
  
     public:

    /*! \brief Constructor.
     * @param logFileName The name of the log file.
     */
    BkgdManager();

    ~BkgdManager(); //!< Destructor.


    void ReadIn(const Utils::ParameterSet &config,
		const Utils::ParameterSet &sample,
		const Utils::ParameterSet &mSuGraSettings);
   
    void Run(const Utils::ParameterSet & sample,
	     const Utils::ParameterSet & significance
	     );

     //define the bkgdDataSets classes for data in different var3 ranges
   bkgdDataSets *Data_Var3range1;
   bkgdDataSets *Data_Var3range2;
   bkgdDataSets *Data_Var3range3;

   //define the EWK bkgdDataSets classes for data in different var3 ranges
   bkgdDataSets *EWK_Var3range1;
   bkgdDataSets *EWK_Var3range2;
   bkgdDataSets *EWK_Var3range3;

  //define the QCD bkgdDataSets classes for data in different var3 ranges
   bkgdDataSets *QCD_Var3range1;
   bkgdDataSets *QCD_Var3range2;
   bkgdDataSets *QCD_Var3range3; 


  //define the bkgdDataSets classes for signal plus background in different var3 ranges
   bkgdDataSets *SplusB_Var3range1;
   bkgdDataSets *SplusB_Var3range2;
   bkgdDataSets *SplusB_Var3range3;
 

  //define the bkgdDataSets classes for background only in different var3 ranges
   bkgdDataSets *B_Var3range1;
   bkgdDataSets *B_Var3range2;
   bkgdDataSets *B_Var3range3;

   std::string outputDir;
   std::string input_plotName;
    Double_t lumi;

   std::string mSuGraFile;
    int tanBeta;

    int nbins_x ;
    int nbins_y ;
    int min_x ;
    int min_y ;
    int max_x ;
    int max_y ;
    int binsize_x ;
    int binsize_y ;

  
  }; // end of BkgdManager class definition.

} // ~namespace Operation

#endif //~BkgdManager_h

