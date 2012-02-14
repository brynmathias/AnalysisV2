#include "Vars.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "JetData.hh"
#include "KinSuite.hh"
#include "Math/VectorUtil.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace allhadronic;

// -----------------------------------------------------------------------------
//
Vars::Vars()
  : jets_(),
    pseudo_(),
    j1_(),
    j2_(),
    et1_(0.),
    et2_(0.),
    ht_(0.),
    dht_(0.),
    mht_(),
    at_(0.),
    meff_(0.),
    x1_(0.),
    x2_(0.),
    updated_(true)
{
  clear();
};

// -----------------------------------------------------------------------------
//
void Vars::clear() {
  jets_.clear();
  jets_.reserve(16);
  pseudo_.clear();
  pseudo_.reserve(16);
  j1_ = LorentzV(0.,0.,0.,0.);
  j2_ = LorentzV(0.,0.,0.,0.);
  et1_ = 0.;
  et2_ = 0.;
  ht_ = 0.;
  dht_ = 0.;
  mht_ = LorentzV(0.,0.,0.,0.);
  at_ = 0.;
  meff_ = 0.;
  x1_ = 0.;
  x2_ = 0.;
  updated_ = true;
};

// -----------------------------------------------------------------------------
//
void Vars::push_back( const LorentzV& jet ) {
  jets_.push_back( jet ); //@@ assume use massless jets?
  //jets_.push_back( massless(jet) ); //@@ assume use massless jets?
  ht_ += jets_.back().Et();
  mht_ -= jets_.back(); 
  updated_ = false;
}

// -----------------------------------------------------------------------------
//
void Vars::update() {
  
  if ( jets_.empty() ) { return; }
  
  updated_ = true;
  
  // Sort jets
  //std::sort( jets_.begin(), jets_.end(), SortByEt );
  //std::sort( jets_.begin(), jets_.end(), SortByPt );
  
  // Calc meff, at and do jet recombination
  meff_ = ht_ + mht_.Pt();
  at_ = jets_.size() < 2 ? 0. : AlphaT()( jets_, pseudo_ );
  
  // Construct pseudo di-jets
  j1_ = LorentzV(0.,0.,0.,0.);
  j2_ = LorentzV(0.,0.,0.,0.);
  et1_ = 0.;
  et2_ = 0.;
  for ( unsigned int i = 0; i < jets_.size(); ++i ) {
    if ( pseudo_[i] ) { j1_ += jets_[i]; et1_ += jets_[i].Et(); }
    else              { j2_ += jets_[i]; et2_ += jets_[i].Et(); }
  }
  
  // Calculate DHT
  dht_ = fabs( et1_ - et2_ );
  
  // Calculate x1, x2
  x1_ = ( j1_.Pt() ) / ( j1_.Pt() + j2_.Pt() + mht_.Pt() );
  x2_ = ( j2_.Pt() ) / ( j1_.Pt() + j2_.Pt() + mht_.Pt() );

  if ( x2_ > x1_ ) { double tmp = x2_; x2_ = x1_; x1_ = tmp; }
  
}

// -----------------------------------------------------------------------------
//
void Vars::print( std::stringstream& ss ) {
  ss << "[Vars::print] " << std::endl
     << " Njets: " << njets() << std::endl
     << " HT: " << ht_ << std::endl
     << " MHT: " << mht_.Pt() << std::endl
     << " AlphaT: " << at_ << std::endl
     << " Meff: " << meff_ << std::endl
     << " x1: " << x1_ << std::endl
     << " x2: " << x2_ << std::endl;
}

// -----------------------------------------------------------------------------
//
void Vars::print() {
  std::cout << "[Vars::print] " 
	    << std::fixed 
	    << std::setprecision(0)
	    << " ht: " << ht_ 
	    << std::setprecision(0)
	    << " mht: " << mht_.Pt() 
	    << std::setprecision(0)
	    << " dht: " << dht_
	    << std::setprecision(2)
	    << " at: " << at_ 
	    << std::setprecision(0)
	    << " meff: " << meff_ 
	    << std::setprecision(3)
	    << " et: " << ( jets_.empty() ? 0. : jets_.back().Et() )
	    << std::setprecision(0)
// 	    << " et1: " << j1_.Pt() 
// 	    << std::setprecision(0)
// 	    << " et2: " << j2_.Pt() 
// 	    << std::setprecision(0)
// 	    << " et1: " << j1_.Et() 
// 	    << std::setprecision(0)
// 	    << " et2: " << j2_.Et() 
	    << std::setprecision(0)
	    << " et1: " << et1_
	    << std::setprecision(0)
	    << " et2: " << et2_
	    << std::setprecision(2)
	    << " x1: " << x1_ 
	    << std::setprecision(2)
	    << " x2: " << x2_ 
	    << std::setprecision(0)
	    << " nj: " << njets() 
	    << std::setprecision(3)
	    << " mht/meff: " << ( meff() > 0. ? mht_.Pt() / meff() : 0. )
	    << std::endl;
}


