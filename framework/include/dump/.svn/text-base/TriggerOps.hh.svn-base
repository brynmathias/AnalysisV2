/*! \file TriggerOps.hh
 * \brief Header file for trigger-based operations.
 */
#ifndef TriggerOps_hh
#define TriggerOps_hh

#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh" 

#include "TH1D.h"

using namespace Event;

namespace Operation {

  /*! \brief Trigger test operation.
   *
   * \date February 2009
   * \author Tom Whyntie
   * \version 1.1
   *
   * Longer description of the operation.
   */
  class TriggerTest : public Operation::_Base {

  public:

    /*! \brief Constructor.
     */
    TriggerTest(const std::string & fileName,
		const std::string & folderName);

    /**
     * \brief Destructor.
     */
    ~TriggerTest();

    /*! \brief Description of the process the operation applies.
     *
     * \param ev Pointer to the event data container class.
     * \return True if the event passes the operation.
     */
    bool Process(Event::Data & ev);

    /**
     * \brief Describes the operation, for analysis output to terminal/log file.
     *
     * \param ostrm Reference to output stream (for output).
     * \return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    const std::string mFileName;   //!< ROOT file name for histogram storage.
    const std::string mFolderName; //!< Name of the in-file storage file for the histograms. 

    // Histograms
    //------------
    TH1D *hltEnabled; //!< Histogram with HLT trigger bits enabled 

  }; // ~TriggerTest class


} //~namespace Operation

#endif //~TriggerOps_hh
