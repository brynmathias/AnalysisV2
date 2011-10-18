#include "PlottingBaseExtended.hh"

using namespace allhadronic;
using namespace Operation;

// -----------------------------------------------------------------------------
//
PlottingBaseExtended::PlottingBaseExtended( const Utils::ParameterSet& ps ) 
{;}

// -----------------------------------------------------------------------------
//
PlottingBaseExtended::~PlottingBaseExtended() {}

// -----------------------------------------------------------------------------
//
void PlottingBaseExtended::Start( Event::Data& ev ) {}

// -----------------------------------------------------------------------------
//
std::ostream& PlottingBaseExtended::Description( std::ostream& ss ) { return ss; }

// -----------------------------------------------------------------------------
//
bool PlottingBaseExtended::Process( Event::Data& ev ) { return true; }

// -----------------------------------------------------------------------------
//
void PlottingBaseExtended::BookHistos() {
  std::cout << "[PlottingBaseExtended::BookHistos]"
	    << " Requires implementation in derived class!" 
	    << std::endl;
}

// -----------------------------------------------------------------------------
//
void PlottingBaseExtended::book( vvTH1D& his, 
				 const std::string& histogram_name, 
				 const std::string& xaxis_title,
				 uint xbins, 
				 double xlow, 
				 double xhigh, 
				 uint jet_multiplicity,
				 const std::string& variable_name,
				 const std::vector<double>& variable ) {
  
  //his.clear();
  his.resize( variable.size(), vTH1D() );
  
  for ( uint ii = 0; ii < variable.size(); ++ii ) { 
    std::stringstream ss;
    ss << histogram_name << "_" << variable_name << variable[ii];
    std::stringstream sss;
    sss << ";" << xaxis_title << ";";
    BookHistArray( his[ii], ss.str(), sss.str(), xbins, xlow, xhigh, jet_multiplicity+1, 0, 1, true ); 
  }
  
}

// -----------------------------------------------------------------------------
//
void PlottingBaseExtended::fill( vTH1D& his,
				 double value,
				 double weight,
				 uint jet_multiplicity,
				 double at_value,
				 double at_cut ) {
  if ( at_value >= at_cut ) {
    if ( !his.empty() ) { 
      if ( his[0] ) his[0]->Fill( value, weight ); 
    }
    if ( jet_multiplicity < his.size() ) {
      if ( his[jet_multiplicity] ) his[jet_multiplicity]->Fill( value, weight ); 
    }
  }

}


