/*! \file Operation.hh
 * \brief Header file for the Operation::_Base base class.
 */

#ifndef Operation_h
#define Operation_h

#include <iostream>

namespace Event {
  class Data;
}

/*! \brief Namespace for all Operation-related code.
 * 
 */
namespace Operation {

  /*! \brief Abstract definition of an operation.
   *
   * \author CMS SUSY Dijet Analysis Team
   * \author John Jones
   * \date Summer 2008, reformatted October 2008
   * \version 1.1
   */
  class _Base {

  public:
    /**
     * \brief Operation base class constructor.
     */
    _Base();

    /**
     * \brief Operation base class destructor.
     */
    virtual ~_Base();
    
  public:
    /**
     * \brief Start function
     * Called just before process is called the first time
     * so can be used for histogram initialisation, etc...
     */
    virtual void Start(Event::Data & ev);

    /**
     * \brief End function
     * Called only after last event is processed.
     */
    virtual void End(Event::Data & ev);
    
    /**
     * \brief Main processing function
     * Process the event with the operation...
     * Returns true on success (cut passed), false on failure
     */
    virtual bool Process(Event::Data & ev) = 0;

    /**
     * \brief Output a description of the operation.
     */ 
    virtual std::ostream& Description(std::ostream& ostrm) = 0;
  }; // ~_Base class

  /**
   * \brief Definition of abstract streamer.
   *
   * Must implement virtual for all derived types
   */
  std::ostream& operator << (std::ostream& ostrm, _Base& m);

} // ~ namespace Operation

#endif //~Operations_h
