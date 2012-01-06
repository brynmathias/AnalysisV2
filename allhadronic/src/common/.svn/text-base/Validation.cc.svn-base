#include "Validation.hh"
#include "Types.hh"
#include "Vars.hh"
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace allhadronic;

// -----------------------------------------------------------------------------
//
Validation::Validation( const Utils::ParameterSet& ps ) :
  PlottingBaseExtended(ps),
  algos_(ps),
  verbose_(false),
  dir_(""),
  nMax_(0),
  aT_(),
  hPreCleaning_(),
  hPostDeadEcal_(),
  hPostBaby_(),
  hPostTrackless_(),
  cntr_baseline(0.),
  cntr_leading_jet_eta(0.),
  cntr_odd_jet_veto(0.),
  cntr_bad_muon_in_jet(0.),
  cntr_leading_jet_pt(0.),
  cntr_second_jet_pt(0.),
  cntr_correct_reco_bin(0.),
  cntr_jet_multiplicity(0.),
  cntr_at(0.),
  cntr_pass_dead_ecal(0.),
  cntr_pass_baby_cut(0.)
{
  
  // Optional parameters
  if ( ps.Contains("Verbose") ) verbose_ = ps.Get<bool>("Verbose");
  
  // Required parameters
  aT_ = ps.Get< std::vector<double> >("AlphaT"); 
  dir_ = ps.Get<std::string>("DirName"); 
  nMax_ = ps.Get<int>("nMax"); 
  
  // Add zero-value cut (ie, not cut)
  aT_.insert( aT_.begin(), 0. );
  
}

// -----------------------------------------------------------------------------
//
Validation::~Validation() {
  std::cout << std::fixed 
	    << "RECO cut flow:" << std::endl
    //<< "cntr_signal_region: " << cntr_baseline << std::endl
	    << "cntr_correct_reco_bin: " << cntr_correct_reco_bin << std::endl
	    << "cntr_leading_jet_eta: " << cntr_leading_jet_eta << std::endl
	    << "cntr_bad_muon_in_jet: " << cntr_bad_muon_in_jet << std::endl
	    << "cntr_odd_jet_veto: " << cntr_odd_jet_veto << std::endl
	    << "cntr_leading_jet_pt: " << cntr_leading_jet_pt << std::endl
	    << "cntr_second_jet_pt: " << cntr_second_jet_pt << std::endl
	    << "cntr_jet_multiplicity: " << cntr_jet_multiplicity << std::endl
	    << "cntr_at: " << cntr_at << std::endl
	    << "cntr_pass_dead_ecal: " << cntr_pass_dead_ecal << std::endl 
	    << "cntr_pass_baby_cut: " << cntr_pass_baby_cut << std::endl;
}

// -----------------------------------------------------------------------------
//
void Validation::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dir_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void Validation::BookHistos() {
  book( hPreCleaning_, "Ht", "H_{T} (GeV)", algos_.nbins(), algos_.low(), algos_.high(), nMax_, "aT", aT_ );
  book( hPostDeadEcal_, "HtAfterDeadEcal", "H_{T} (GeV)", algos_.nbins(), algos_.low(), algos_.high(), nMax_, "aT", aT_ );
  book( hPostBaby_, "HtAfterBaby", "H_{T} (GeV)", algos_.nbins(), algos_.low(), algos_.high(), nMax_, "aT", aT_ );
  book( hPostTrackless_, "HtAfterTrackless", "H_{T} (GeV)", algos_.nbins(), algos_.low(), algos_.high(), nMax_, "aT", aT_ );
}

// -----------------------------------------------------------------------------
//
std::ostream& Validation::Description( std::ostream& ss ) { return ss; }

// -----------------------------------------------------------------------------
//
bool Validation::Process( Event::Data& ev ) {
  
  // Event weight
  Double_t weight = ev.GetEventWeight();
  
  // Retrieve MET from ntuple
  LorentzV met = algos_.met( ev );
  
  // Determine RECO and BABY objects (and identify bin to be used)
  Vars reco;
  Vars baby;
  algos_.reco( ev, reco, nMax_ );
  algos_.baby( ev, baby, nMax_ );

//   std::stringstream ss;
//   ss << "RECO: " << std::endl;
//   reco.print(ss);
//   ss << "BABY: " << std::endl;
//   baby.print(ss);
//   std::cout << ss.str() << std::endl;
  
  // Event variables for signal region (ie, highest HT bin)
  Vars signal_region;
  algos_.reco( ev, signal_region, nMax_, algos_.nbins()-1 );
  
  // Pre-selection
  bool correct_reco_bin = ( algos_.bin() > -1 );
  bool jet_multiplicity = algos_.jetMultiplicity( reco );
  bool leading_jet_pt   = algos_.leadingJetPt( reco );
  bool leading_jet_eta  = algos_.leadingJetEta( reco );
  bool second_jet_pt    = algos_.secondJetPt( reco );
  bool no_odd_jets      = algos_.noOddJets( ev );
  bool no_bad_mu_in_jet = algos_.noBadMuonInJet( ev, reco );
  
  // Cleaning cuts
  bool mht_over_met = false; 
  bool no_dead_ecal = false;
  bool pt_over_ht   = false;
  if ( correct_reco_bin &&
       jet_multiplicity &&
       leading_jet_pt &&
       second_jet_pt &&
       leading_jet_eta &&
       no_odd_jets && 
       no_bad_mu_in_jet ) {
    mht_over_met = algos_.mhtOverMet( ev, reco, signal_region.mht().Pt() );
    no_dead_ecal = algos_.noOverlapWithDeadEcal( ev, reco, baby );
    pt_over_ht   = algos_.vertexSumPtOverHt( ev, reco );
  }

  // Fill histograms  
  if ( correct_reco_bin &&
       jet_multiplicity &&
       leading_jet_pt &&
       second_jet_pt &&
       leading_jet_eta &&
       no_odd_jets && 
       no_bad_mu_in_jet ) {
    for ( uint iat = 0; iat < aT_.size(); ++iat ) {
      fill( hPreCleaning_[iat], reco.ht(), weight, reco.njets(), reco.at(), aT_[iat] );  
      if ( no_dead_ecal ) { 
	fill( hPostDeadEcal_[iat], reco.ht(), weight, reco.njets(), reco.at(), aT_[iat] ); 
	if ( mht_over_met ) {
	  fill( hPostBaby_[iat], reco.ht(), weight, reco.njets(), reco.at(), aT_[iat] ); 
	  if ( pt_over_ht ) { 
	    fill( hPostTrackless_[iat], reco.ht(), weight, reco.njets(), reco.at(), aT_[iat] ); 
	  }
	}
      }
    }
  }
  
  // Cut flow counters
  if ( algos_.bin() < 0 || ( algos_.nbins() - algos_.bin() ) == 1 ) {
    //cntr_baseline += weight;
    if ( correct_reco_bin ) {
      cntr_correct_reco_bin += weight;
      if ( leading_jet_eta ) {
	cntr_leading_jet_eta += weight;
	if ( no_bad_mu_in_jet ) {
	  cntr_bad_muon_in_jet += weight;
	  if ( no_odd_jets ) { 
	    cntr_odd_jet_veto += weight;
	    if ( leading_jet_pt ) {
	      cntr_leading_jet_pt += weight;
	      if ( second_jet_pt ) {
		cntr_second_jet_pt += weight;
		if ( jet_multiplicity ) {
		  cntr_jet_multiplicity += weight;
		  if ( reco.at() > 0.55 ) {
		    cntr_at += weight;
		    if ( no_dead_ecal ) {
		      cntr_pass_dead_ecal += weight;
		      if ( mht_over_met ) {
			cntr_pass_baby_cut += weight;
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }  
  }

  return true;

}
