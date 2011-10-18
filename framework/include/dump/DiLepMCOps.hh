/*! \file DiLepMCOps.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef DiLepMCOps_hh
#define DiLepMCOps_hh

#include "Operation.hh"

#include "TH1D.h"
#include "TH2D.h"

using namespace Event;

namespace Operation {

    /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class DiLepMC : public Operation::_Base {

  public:

    /*! \brief Constructor.
     */
    DiLepMC();//const std::string & fileName,
    //const std::string & folderName);
    
    ~DiLepMC(); //!< Destructor.

    /*! \brief MC the required event data.
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
    //const std::string mFileName;   //!< ROOT file name to save histograms to.
    //const std::string mFolderName; //!< ROOT folder name to save histograms to.    
    //TFile *  FileOut; 
    //TDirectoryFile * mydir;

    // Histograms
    //------------
    //const static int dilepFinalStates   = 6;

  

  }; // ~DiLepMC class





} //~namespace Operation

#endif //~MCOps_hh
