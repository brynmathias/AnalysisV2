#include "TurnOn.hh"
#include "Types.hh"
#include "Vars.hh"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace allhadronic;

// -----------------------------------------------------------------------------
//
TurnOn::TurnOn( const Utils::ParameterSet& ps ) :
  PlottingBaseExtended(ps),
  algos_(ps),
  verbose_(false),
  dir_(""),
  nMin_(0),
  nMax_(0),
  triggers_(),
  prefilters_(),
  variables_(),
  htbins_(),
  hTriggers_(),
  hPreFilters_(),
  hGiven_()
{
  
  // Optional parameters
  if ( ps.Contains("Verbose") ) verbose_ = ps.Get<bool>("Verbose");
  
  // Required parameters
  dir_ = ps.Get<std::string>("DirName"); 
  nMin_ = ps.Get<int>("nMin"); 
  nMax_ = ps.Get<int>("nMax"); 
  
  // TurnOn parameters
  triggers_ = ps.Get< std::vector<std::string> >("Triggers"); 
  prefilters_ = ps.Get< std::vector<std::string> >("PreFilters"); 
  variables_ = ps.Get< std::vector<std::string> >("Variables"); 
  htbins_ = ps.Get< std::vector<int> >("Bins"); 
  
}

// -----------------------------------------------------------------------------
//
TurnOn::~TurnOn() {
}

// -----------------------------------------------------------------------------
//
void TurnOn::Start( Event::Data& ev ) {

  if ( triggers_.empty() ||
       triggers_.size() != prefilters_.size() ||
       triggers_.size() != variables_.size() ||
       triggers_.size() != htbins_.size() ) {
    std::cout << "[TurnOn::Start]"
	      << " Unexpected number of triggers, prefilters and/or HT bins! "
	      << triggers_.size() << " " 
	      << prefilters_.size() << " " 
	      << variables_.size() << " " 
	      << htbins_.size() << " " 
	      << std::endl;
    abort();
  }

  initDir( ev.OutputFile(), dir_.c_str() );
  BookHistos();
  
}

// -----------------------------------------------------------------------------
//
void TurnOn::BookHistos() {

  hTriggers_.resize( triggers_.size(), vTH1D( ) );
  hPreFilters_.resize( triggers_.size(), vTH1D( ) );
  hGiven_.resize( triggers_.size(), vTH1D( ) );
  
  for ( uint ii = 0; ii < triggers_.size(); ++ii ) { 

    std::string str("");
    int nbins = 0;
    double xlow = 0.;
    double xhigh = 0.;
    if      ( variables_[ii] == "HT" )        { str = "HT";         nbins = 1000; xlow = 0.; xhigh = 1000.; }
    else if ( variables_[ii] == "MHT" )       { str = "MHT";        nbins = 1000; xlow = 0.; xhigh = 1000.; }
    else if ( variables_[ii] == "AlphaT" )    { str = "#alpha_{T}"; nbins = 1000; xlow = 0.; xhigh = 1.; }
    else if ( variables_[ii] == "MHToverHT" ) { str = "MHT/HT";     nbins = 1000; xlow = 0.; xhigh = 1.; }
    //     if      ( variables_[ii] == "HT" )        { str = "HT";         nbins = 600; xlow = 150.; xhigh = 750.; }
    //     else if ( variables_[ii] == "MHT" )       { str = "MHT";        nbins = 400; xlow = 0.;   xhigh = 400.; }
    //     else if ( variables_[ii] == "AlphaT" )    { str = "#alpha_{T}"; nbins = 400; xlow = 0.4;  xhigh = 0.8; }
    //     else if ( variables_[ii] == "MHToverHT" ) { str = "MHT/HT";     nbins = 600; xlow = 0.2;  xhigh = 0.8; }
    
    std::stringstream num; num << ii;
    std::stringstream bin; bin << htbins_[ii];
    std::stringstream pt; 
    if ( htbins_[ii] < algos_.nbins() ) { pt << ", p_{T}^{jet}>" << algos_.pt3Bins()[htbins_[ii]] << " GeV"; }
    else { pt << ", " << algos_.pt3Bins()[0] << "<p_{T}^{jet}<" << algos_.pt3Bins()[algos_.nbins()-1] << " GeV"; }
    
    BookHistArray( hTriggers_[ii], 
		   std::string("TurnOn_"+triggers_[ii]+"_given_"+prefilters_[ii]+"_"+variables_[ii]+"_Bin"+bin.str()).c_str(), 
		   std::string(triggers_[ii]+pt.str()+";"+str+";a.u.").c_str(), 
		   nbins, xlow, xhigh,
		   nMax_+1, 0, 1, true ); 
    
    BookHistArray( hPreFilters_[ii], 
		   std::string("PreFilters_"+triggers_[ii]+"_given_"+prefilters_[ii]+"_"+variables_[ii]+"_Bin"+bin.str()).c_str(), 
		   std::string(prefilters_[ii]+pt.str()+";"+str+";a.u.").c_str(), 
		   nbins, xlow, xhigh,
		   nMax_+1, 0, 1, true ); 
    
    BookHistArray( hGiven_[ii], 
		   std::string("Given_"+triggers_[ii]+"_given_"+prefilters_[ii]+"_"+variables_[ii]+"_Bin"+bin.str()).c_str(), 
		   std::string(triggers_[ii]+" | "+prefilters_[ii]+pt.str()+";"+str+";a.u.").c_str(), 
		   nbins, xlow, xhigh,
		   nMax_+1, 0, 1, true ); 
    
  }

}

// -----------------------------------------------------------------------------
//
std::ostream& TurnOn::Description( std::ostream& ss ) { return ss; }

// -----------------------------------------------------------------------------
//
bool TurnOn::Process( Event::Data& ev ) {

  //std::cout << " event number: " << ev.GetEventNumber() << std::endl;

  // Event weight
  Double_t weight = ev.GetEventWeight();
  
  // Retrieve MET from ntuple
  LorentzV met = algos_.met( ev );

  // Determine RECO and BABY objects (and identify bin to be used)
  Vars reco;
  Vars baby;
  algos_.reco( ev, reco );
  algos_.baby( ev, baby );
  int bin = algos_.bin();
  
  // Event variables for signal region (350<HT<400 bin)
  Vars signal_region;
  algos_.reco( ev, signal_region, nMax_, 3 );

  // Event variables for temporary HT bin
  Vars temp;
  
  // Pre-selection
  if (  algos_.bin() < 0 ) { return false; }
  if ( !algos_.jetMultiplicity( reco ) ) { return false; }
  if ( !algos_.leadingJetPt( reco ) ) { return false; }
  if ( !algos_.leadingJetEta( reco ) ) { return false; }
  if ( !algos_.secondJetPt( reco ) ) { return false; }
  if ( !algos_.noOddJets( ev ) ) { return false; }
  if ( !algos_.noBadMuonInJet( ev, reco ) ) { return false; }
  
  // Cleaning cuts
  if ( !algos_.mhtOverMet( ev, reco, signal_region.mht().Pt() ) ) { return false; }
  if ( !algos_.noOverlapWithDeadEcal( ev, reco, baby ) ) { return false; }
  if ( !algos_.vertexSumPtOverHt( ev, reco ) ) { return false; }
  
  // Loop through triggers, prefilters and variables
  for ( unsigned int ii = 0; ii < triggers_.size(); ++ii ) {
    
    // Calc event variables for temp HT bin, if necessary
    if ( bin != htbins_[ii] ) { bin = htbins_[ii]; algos_.reco( ev, temp, nMax_, bin ); }
    else                      { temp = reco; }
    
    // Extract prescale for given trigger
    int weight_t = algos_.triggers( ev, std::vector<std::string>(1,triggers_[ii]) );
    
    // Extract prescale for given prefilter 
    int weight_p = algos_.triggers( ev, std::vector<std::string>(1,prefilters_[ii]) );
    
    // Extract variable to plot
    double variable = -1.;
    if      ( variables_[ii] == "HT" )        { variable = temp.ht(); }
    else if ( variables_[ii] == "MHT" )       { variable = temp.mht().Pt(); }
    else if ( variables_[ii] == "MHToverHT" ) { variable = temp.mht().Pt()/temp.ht(); }
    else if ( variables_[ii] == "AlphaT" )    { variable = temp.at(); }
    else {
      std::cout << "[TurnOn::Process]" 
		<< " Unexpected variable: \"" 
		<< variables_[ii] << "\""
		<< std::endl;
      abort();
    }
    
    int njets = temp.njets();
    
    // Trigger histograms
    if ( weight_t > 0 ) {
      // Weighting by prescale
      double w = weight;
      if ( weight_t == 1 && weight_p == 1 ) { w = w; }
      if ( weight_t  > 1 && weight_p == 1 ) { w = weight_t; }
      if ( weight_t == 1 && weight_p  > 1 ) { w = w; }
      if ( weight_t  > 1 && weight_p  > 1 ) { w = weight_t; } //@@ - weight_t*weight_p ?
      // Fill histograms
      if ( !hTriggers_.empty() ) {
	if ( !hTriggers_[ii].empty() ) { 
	  if ( hTriggers_[ii][0] ) { hTriggers_[ii][0]->Fill( variable, w ); }
	}
	if ( njets < nMax_ ) {
	  if ( hTriggers_[ii][njets] ) { 
	    hTriggers_[ii][njets]->Fill( variable, w ); 
	  }
	} else {
	  if ( hTriggers_[ii][nMax_] ) { 
	    hTriggers_[ii][nMax_]->Fill( variable, w ); 
	  }
	}
      }
    }
    
    // Prefilter histograms
    if ( weight_p > 0 ) {
      // Weighting by prescale
      double w = weight;
      if ( weight_t == 1 && weight_p == 1 ) { w = w; }
      if ( weight_t  > 1 && weight_p == 1 ) { w = w; }
      if ( weight_t == 1 && weight_p  > 1 ) { w = w; }
      if ( weight_t  > 1 && weight_p  > 1 ) { w = weight_p; } //@@ - weight_t*weight_p ?
      // Fill histograms
      if ( !hPreFilters_.empty() ) {
	if ( !hPreFilters_[ii].empty() ) { 
	  if ( hPreFilters_[ii][0] ) { hPreFilters_[ii][0]->Fill( variable, w ); }
	}
	if ( njets < nMax_ ) {
	  if ( hPreFilters_[ii][njets] ) { 
	    hPreFilters_[ii][njets]->Fill( variable, w ); 
	  }
	} else {
	  if ( hPreFilters_[ii][nMax_] ) { 
	    hPreFilters_[ii][nMax_]->Fill( variable, w ); 
	  }
	}
      }
    }
    
    // "Trigger given prefilter" histograms
    if ( weight_t > 0 && weight_p > 0 ) {
      // Weighting by prescale
      double w = weight;
      if ( weight_t == 1 && weight_p == 1 ) { w = w; }
      if ( weight_t  > 1 && weight_p == 1 ) { w = weight_t; }
      if ( weight_t == 1 && weight_p  > 1 ) { w = w; }
      if ( weight_t  > 1 && weight_p  > 1 ) { w = weight_t; } //@@ - weight_t*weight_p ?
      // Fill histograms
      if ( !hGiven_.empty() ) {
	if ( !hGiven_[ii].empty() ) { 
	  if ( hGiven_[ii][0] ) { hGiven_[ii][0]->Fill( variable, w ); }
	}
	if ( njets < nMax_ ) {
	  if ( hGiven_[ii][njets] ) { 
	    hGiven_[ii][njets]->Fill( variable, w ); 
	  }
	} else {
	  if ( hGiven_[ii][nMax_] ) { 
	    hGiven_[ii][nMax_]->Fill( variable, w ); 
	  }
	}
      }
    }

//     // Fill "trigger given prefilter" histograms
//     if ( weight_t > 0 ) {
//       if ( !hGiven_.empty() ) {
// 	if ( !hGiven_[ii].empty() ) { 
// 	  if ( hGiven_[ii][0] ) { hGiven_[ii][0]->Fill( variable, weight*weight_t ); }
// 	}
// 	if ( njets < nMax_ ) {
// 	  if ( hGiven_[ii][njets] ) { 
// 	    hGiven_[ii][njets]->Fill( variable, weight*weight_t ); 
// 	  }
// 	} else {
// 	  if ( hGiven_[ii][nMax_] ) { 
// 	    hGiven_[ii][nMax_]->Fill( variable, weight*weight_t ); 
// 	  }
// 	}
//       }
//     }
    
  }
  
  return true;

}
