/*! \file OpConfig.hh
 * \brief Header file for the operations configuration class.
 */

#ifndef BkgdEstConfig_hh
#define BkgdEstConfig_hh

#include "ControlCards.hh"

namespace Operation {

    /*! \brief Container class for the operations configuration parameters.
     */
    class BkgdEstConfig {
      public:
        BkgdEstConfig(const char * opconfigfilename); //!< Constructor.
        ~BkgdEstConfig(); //!< Destructor.

        ControlCards * Cards; //!< The operation configuration control cards.
    };

} // ~Operation

#endif
