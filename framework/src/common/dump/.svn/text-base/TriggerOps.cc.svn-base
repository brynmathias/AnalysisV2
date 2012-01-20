/*! \file TriggerOps.cc
 * \brief Source code for the trigger-related operations.
 */
#include "TriggerOps.hh"

#include <iostream>

using namespace std;

namespace Operation {

  //======================================
  // TriggerTest operation implementation
  //======================================
  TriggerTest::TriggerTest(const std::string & fileName,
			   const std::string & folderName) :
    mFileName(fileName),
    mFolderName(folderName)
  {
    hltEnabled = new TH1D("hltEff","HLT bits enabled",160,-0.5,159.5);
    hltEnabled->Sumw2();
  }

  TriggerTest::~TriggerTest() {
    TFile * FileOut = new TFile(mFileName.c_str(), "update");
    TDirectoryFile * mydir = new TDirectoryFile(mFolderName.c_str(), "recreate");
    hltEnabled->SetDirectory(mydir);
    FileOut->Write(); // Write out the ROOT file.
    delete FileOut; // Tidy up.

  }

  bool TriggerTest::Process(Event::Data & ev) {
    // Do whatever you gotta do...
    // JJ - is nHLT really uint or int?
    for (Int_t i = 0 ; i < ev.nHLT() ; i++) {      
      // Filla histogram with the HLT bits that were enabled (hltBits[i]==1)
      if (ev.HLTArray()[i]) {
	hltEnabled->Fill(static_cast<float>(i), ev.GetEventWeight());
      }
    }
    return true; // Check for fails above, return false to fail operation.
  }

  std::ostream& TriggerTest::Description(std::ostream &ostrm) {
    ostrm << "TriggerTest Operation";
    return ostrm;
  }

} //~namespace Operation
