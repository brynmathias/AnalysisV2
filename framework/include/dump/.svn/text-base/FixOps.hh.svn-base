/*! \file FixOps.hh
 * \brief Header file for simulation fix-based operations.
 */
#ifndef FixOps_hh
#define FixOps_hh

#include "Operation.hh"
#include "EventData.hh"

namespace Operation {

  /*! \brief Simulation bug cut: MET/muon bug.
   *
   * Modes: 0 => No MET bug fix applied.
   *        1 => MET bug fix applied (TO BE IMPLEMENTED).
   * \todo Actually code the MET bug fix process method.
   */
  class CutMETBug : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * \param mode MET bug fix cut modus operandi.
     */
    CutMETBug(UInt_t mode);

    /*! \brief Destructor.
     */
    ~CutMETBug();

    /*! \brief Determines whether the event has been affected by the MET bug.
     *
     * \param ev Pointer to the event's data.
     * \return True if event unaffected, false is event affected (and so rejected).
     */
    bool Process(Event::Data * const ev);

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
    UInt_t mMode; //!< Simulation MET bug mode - see class description.

  }; // ~CutMETBug class

} // ~namespace Operation

#endif // ~FixOps_hh
