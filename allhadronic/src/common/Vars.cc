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
  at_ = AlphaT()( jets_, pseudo_ );
  
  // Construct pseudo di-jets
  std::vector<LorentzV> dijets(2);
  for ( unsigned int i = 0; i < jets_.size(); ++i ) {
    if ( pseudo_[i] ) { dijets[0] += jets_[i]; }
    else              { dijets[1] += jets_[i]; }
  }
  //std::sort( dijets.begin(), dijets.end(), SortByEt );
  std::sort( dijets.begin(), dijets.end(), SortByPt );
  j1_ = dijets[0];
  j2_ = dijets[1];
  
  // Calculate dht, x1, x2
  dht_ = j1_.Et() - j2_.Et();
  x1_ = ( j1_.Pt() ) / ( j1_.Pt() + j2_.Pt() + mht_.Pt() );
  x2_ = ( j2_.Pt() ) / ( j1_.Pt() + j2_.Pt() + mht_.Pt() );
  
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


