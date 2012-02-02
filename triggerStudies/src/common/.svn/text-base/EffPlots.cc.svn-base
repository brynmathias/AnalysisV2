#include "EffPlots.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include "mt2_bisect.hh"
#include "AlphaT.hh"
#include "Jet.hh"
#include "Math/VectorUtil.h"
#include "JetData.hh"
#include "TMath.h"

using namespace Operation;

// -----------------------------------------------------------------------------
EffPlots::EffPlots( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
  EffPlots_( ps.Get<bool>("EffPlots") )

  {}

// -----------------------------------------------------------------------------
//
EffPlots::~EffPlots() {}

// -----------------------------------------------------------------------------
//
void EffPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void EffPlots::BookHistos() {
  if ( EffPlots_ )           { Plots(); }
}

// -----------------------------------------------------------------------------
//
bool EffPlots::Process( Event::Data& ev ) {
  if ( EffPlots_ ) { Plots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& EffPlots::Description( std::ostream& ostrm ) {
  ostrm << "Trigger Eff Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void EffPlots::Plots() {



  BookHistArray( HadronicAlphaTGeq3_,
    "HadronicAlphaTGeq3",
    ";#alpha_{T} ;Events;",
    1000, 0., 10.,
    nMax_+1, 0, 1, true );

  BookHistArray( HadronicAlphaT_,
    "HadronicAlphaT",
    ";#alpha_{T} ;Events;",
    1000, 0., 10.,
    nMax_+1, 0, 1, true );

  BookHistArray( LeptonicAlphaT_,
    "LeptonicAlphaT_",
    ";#alpha_{T} ;Events;",
    1000, 0., 10.,
    nMax_+1, 0, 1, true );

  BookHistArray( HT_,
    "HT",
    ";H_{T} ;Events;",
    100, 0., 1000.,
    nMax_+1, 0, 1, true );


  BookHistArray( Meff_,
    "Meff",
    ";M_{eff} ;Events;",
    500, 0., 5000.,
    nMax_+1, 0, 1, true );


  BookHistArray( MHT_,
    "MHT",
    ";#slash{H}_{T} ;Events;",
    500, 0., 5000.,
    nMax_+1, 0, 1, true );


  BookHistArray( MHTovHT_,
    "MHTovHT",
    ";#slash{H}_{T} ;Events;",
    1000, 0., 10.,
    nMax_+1, 0, 1, true );

}


bool EffPlots::Plots( Event::Data& ev ) {

  double weight = ev.GetEventWeight();
  UInt_t n = ev.CommonObjects().size();
  double MHTx = 0.;
  double MHTy = 0.;
  double HT = 0.;
    for(int i = 0 ; i < ev.JD_CommonJets().accepted.size(); i++){
        MHTx-= ev.JD_CommonJets().accepted[i]->Px();
        MHTy-= ev.JD_CommonJets().accepted[i]->Py();
        HT +=  (*ev.JD_CommonJets().accepted[i]).Et();
    }
    double MHT = sqrt(MHTx*MHTx+MHTy*MHTy);



     if ( n > 2 && n <= nMax_ && n < MHTovHT_.size()) {
      MHTovHT_[0]->Fill(MHT/HT,weight);
      MHTovHT_[n]->Fill(MHT/HT,weight);
    }


     if ( n >= nMin_ && n <= nMax_ && n < HadronicAlphaT_.size()) {
      HadronicAlphaT_[0]->Fill(ev.HadronicAlphaT(),weight);
      HadronicAlphaT_[n]->Fill(ev.HadronicAlphaT(),weight);
    }


     if ( n >= 3 && n <= nMax_ && n < HadronicAlphaTGeq3_.size()) {
      HadronicAlphaTGeq3_[0]->Fill(ev.HadronicAlphaT(),weight);
    }


     if ( n >= nMin_ && n <= nMax_ && n < LeptonicAlphaT_.size()) {
      LeptonicAlphaT_[0]->Fill(ev.LeptonicAlphaT(),weight);
      LeptonicAlphaT_[n]->Fill(ev.LeptonicAlphaT(),weight);
    }


     if ( n >= nMin_ && n <= nMax_ && n < HT_.size()) {
      HT_[0]->Fill(HT,weight);
      HT_[n]->Fill(HT,weight);
    }


     if ( n >= nMin_ && n <= nMax_ && n < Meff_.size()) {
      Meff_[0]->Fill( MHT+HT,weight);
      Meff_[n]->Fill( MHT+HT,weight);
    }

     if ( n >= nMin_ && n <= nMax_ && n < MHT_.size()) {
      MHT_[0]->Fill( MHT ,weight);
      MHT_[n]->Fill( MHT ,weight);
    }

  return true;
}


