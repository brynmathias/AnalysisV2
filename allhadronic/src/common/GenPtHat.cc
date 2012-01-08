#include "GenPtHat.hh"
#include "EventData.hh"
#include "TH1D.h"

using namespace Operation;

// -----------------------------------------------------------------------------
//
GenPtHat::GenPtHat( const Utils::ParameterSet& ps ) :
  // Misc
  dirName_( ps.Get<std::string>("DirName") ),
  his_( 0 )
{}

// -----------------------------------------------------------------------------
//
GenPtHat::~GenPtHat() {}

// -----------------------------------------------------------------------------
//
void GenPtHat::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  try {
    ev.pthat(); 
    BookHistArray( his_,
		   "GenPtHat",
		   ";#hat{p_{T}} [GeV];", 
		   500,0.,5000.,
		   1, 0, 1, true );
  } catch (...){}
}

// -----------------------------------------------------------------------------
//
bool GenPtHat::Process( Event::Data& ev ) {
  try {
    double pt_hat = ev.pthat(); 
    if ( his_[0] ) his_[0]->Fill( pt_hat, ev.GetEventWeight() ); 
  } catch (...){ return false; }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& GenPtHat::Description( std::ostream& ostrm ) {
  ostrm << "GenPtHat histogram";
  return ostrm;
}
