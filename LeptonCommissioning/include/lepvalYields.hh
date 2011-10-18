/*! \file SSDLTrigger.hh
 * \brief Header file for common object plotting-based operations.
 */
#ifndef lepvalYields_hh
#define lepvalYields_hh
#include "PlottingBase.hh"
#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh"

#include "TH1D.h"
#include "TH2D.h"
#include "Utils.hh"


namespace lepval {

    /*! \brief Good hadronic analysis event data plotting operation.
   *
   * \date February 2009
   * \author The CMS SUSY all-hadronic analysis group.
   * \version 1.1
   *
   */
  class lepvalYields : public PlottingBase   {

  public:

    /*! \brief Constructor.
     * @param ROOT file name for histogram storage.
     * @param Folder name for histogram storage within ROOT file.
     */

    lepvalYields(const std::string & folderName, Utils::ParameterSet &);
    
    ~lepvalYields(); //!< Destructor.
    void Start(Event::Data & ev); //!< Start processing
    bool Process(Event::Data & ev);

    /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
    void  BookHistos();
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    const std::string mFolderName; //!< ROOT folder name to save histograms to.
    // Histograms
    //------------
    TH1D *TriggerYields, *TriggerYields_wHtCut80, *TriggerYields_wHtCut100, *TriggerYields_wHtCut120, *TriggerYields_wHtCut150;

    std::vector<std::string> triggerBits_;
  }; // ~lepvalYields class





} //~namespace lepval

#endif //~Trigger_hh
