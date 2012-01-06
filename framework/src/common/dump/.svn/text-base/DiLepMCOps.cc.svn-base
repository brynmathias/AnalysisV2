/*! \file ComMCOps.cc
 * \brief Source code for common object plotting operations.
 */
#include "DiLepMCOps.hh"
#include "EventData.hh"

namespace Operation {

  //================================
  // Good Jet MC Operation
  //================================
  DiLepMC::DiLepMC() //: //const std::string & fileName,
    //const std::string & folderName) : 
  //mFileName(fileName),
  //mFolderName(folderName) {    
  {  } // end of DiLepMC constructor.

  DiLepMC::~DiLepMC() {} // end of DiLepMC destructor.

  bool DiLepMC::Process(Event::Data & ev) {
    return (ev.MC_Final().state > 0);
  }

  std::ostream& DiLepMC::Description(std::ostream &ostrm) {
    ostrm << "DiLepMC plots made here: (histograms in ";
    return ostrm;
  }
} //~namespace Operation
  

