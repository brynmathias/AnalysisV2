//
//  EventDump.cc
//
//  Created by Bryn Mathias on 2011-05-30.
//

#import "EventSelector.hh"
#include "Trigger.hh"
#include "CommonOps.hh"
#include "JetData.hh"
#include "Compute_Helpers.hh"
#include "LeptonData.hh"
#include "PhotonData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include "mt2_bisect.hh"
#include "AlphaT.hh"
#include "Photon.hh"
#include "Jet.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "JetData.hh"
#include "TMath.h"

using namespace Operation;

eventselector_t::eventselector_t( const Utils::ParameterSet& ps ) :
   _run( ps.Get<std::vector<int> >("Run") ),
  _lumi( ps.Get<std::vector<int> >("Lumi") ),
  _ev( ps.Get<std::vector<int> >("Event") )
  {}


 bool eventselector_t::Process( Event::Data &ev){
  if(_run.size() != _lumi.size() || _lumi.size() != _ev.size()){
    std::cout << " Please use same size vectors for each of RUN:LUMI:EVENT" << std::endl;
    return false;
    }
    std::vector<int>::iterator iRun  = _run.begin();
    std::vector<int>::iterator jRun  = _run.end();
    std::vector<int>::iterator iLumi = _lumi.begin();
    std::vector<int>::iterator iEv   = _ev.begin();


    while(iRun != jRun){
      if( ev.RunNumber() == *iRun && ev.LumiSection() == *iLumi && ev.EventNumber() == *iEv ){ return true; }
      ++iRun;
      ++iLumi;
      ++iEv;
    }
    return false;
}
std::ostream& eventselector_t::Description( std::ostream &ostrm ) {
  ostrm << "selected on events " << " ";
  return ostrm;
}

