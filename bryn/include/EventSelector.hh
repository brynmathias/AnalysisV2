#ifndef hadronic_include_EventSelector_hh
#define hadronic_include_EventSelector_hh

//
//  EventSelector.hh
//
//  Created by Bryn Mathias on 2011-05-30.
//
#include "EventData.hh"
#include "Math/VectorUtil.h"
#include "Operation.hh"
#include "TH1F.h"
#include <iostream>
#include <fstream>
#include "Photon.hh"
#include "Jet.hh"
#include "Lepton.hh"
#include "EventData.hh"
#include "JetData.hh"
#include "Compute_Helpers.hh"
#include "LeptonData.hh"
#include "PhotonData.hh"
namespace Operation {


  class eventselector_t : public Operation::_Base
  {
  public:
    eventselector_t ( const Utils::ParameterSet& ps );
    ~eventselector_t (){;}
    bool Process( Event::Data & ev );
    std::ostream& Description(std::ostream& ostrm);


  private:
    /* data */
    std::vector<int> _run;
    std::vector<int> _lumi;
    std::vector<int> _ev;
  };

}

#endif // hadronic_include_EventSelector_hh