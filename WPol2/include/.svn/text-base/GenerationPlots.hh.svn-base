#ifndef JadGenOrigin_hh
#define JadGenOrigin_hh

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TH1.h"
#include <sstream>
#include <iostream>
#include "Functions.hh"



namespace Operation {

  class JadGenOrigin : public PlottingBase {

  public:
    // Standard Operation methods.   
    JadGenOrigin(const std::string & foldername);
    ~JadGenOrigin();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:    
    std::string mFolderName;

    TH1D * genOrigin;
    
  }; //~JadGenOrigin class
}

#endif
