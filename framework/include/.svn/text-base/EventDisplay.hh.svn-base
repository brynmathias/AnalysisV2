#ifndef EventDisplay_hh
#define EventDisplay_hh

#include "TFile.h"
#include "Operation.hh"
#include "TCanvas.h"
#include "TH2.h"
#include "TDirectory.h"

namespace Operation {

  class EventDisplay : public Operation::_Base {

    public:
      
      EventDisplay(const std::string &, const std::string &);
      ~EventDisplay(){};
      
      void initDir(TDirectory* aFileOut, const char* folderName);
      void Start(Event::Data &);
      bool Process(Event::Data &);
      std::ostream& Description(std::ostream& ostrm);
      
    private:

      TCanvas* c_;
      TH2D* eb_;
      std::string flag_; // "common" to plot only common objects; "all" to plot all objects
      std::string mFolderName;

  };

}
#endif 
