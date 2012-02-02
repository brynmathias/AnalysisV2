/*! \file BkgdManager.hh
 * \brief Header file for the analysis Operation::Manager class.
 *
 */
#ifndef BkgdManager_h
#define BkgdManager_h

#include "Utils.hh"
#include "bkgdDataSets.hh"

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

    double CalculateSignificance(const Utils::ParameterSet & cuts,const bkgdDataSets &SplusB_Var3range1,const bkgdDataSets &SplusB_Var3range3,Double_t x);

    
  
     public:

    /*! \brief Constructor.
     * @param logFileName The name of the log file.
     */
    BkgdManager();

    ~BkgdManager(); //!< Destructor.

   
    void Run(const Utils::ParameterSet & config, // configuration file
             const Utils::ParameterSet & sample
	     );
  
  }; // end of BkgdManager class definition.

} // ~namespace Operation

#endif //~BkgdManager_h

