#ifndef hadronic_include_EventDump_hh
#define hadronic_include_EventDump_hh

//
//  EventDump.h
//
//  Created by Bryn Mathias on 2011-05-30.
//  Copyright (c) 2011 Imperial College. All rights reserved.
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

class eventDump : public Operation::_Base
{
public:
  eventDump();
  ~eventDump();

  bool Process( Event::Data & ev );
  void End( Event::Data & ev );

  std::ostream& Description(std::ostream& ostrm);


private:
  std::string evInfo_;
  /* data */
};



}

#endif // hadronic_include_EventDump_hh
