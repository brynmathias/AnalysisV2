#include "CleaningCuts.hh"
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
CleaningCuts::CleaningCuts( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
// MT2
  CleaningPlots_( ps.Get<bool>("CleaningPlots") )

  {}

// -----------------------------------------------------------------------------
//
CleaningCuts::~CleaningCuts() {}

// -----------------------------------------------------------------------------
//
void CleaningCuts::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void CleaningCuts::BookHistos() {
  if ( CleaningPlots_ )           { CleaningPlots(); }
}

// -----------------------------------------------------------------------------
//
bool CleaningCuts::Process( Event::Data& ev ) {
  if ( CleaningPlots_ )               { CleaningPlots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& CleaningCuts::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void CleaningCuts::CleaningPlots() {


  BookHistArray( MHTovMET_raw_,
    "MHTovMET",
    ";MHT/MET;Events/0.1;",
    100, 0., 10,
    nMax_+1, 0, 1, true );


  BookHistArray( AlphaT_,
    "AlphaT",
    ";AlphaT;Events/0.01;",
    200, 0., 2,
    nMax_+1, 0, 1, true );


}
// -----------------------------------------------------------------------------
//



bool CleaningCuts::CleaningPlots( Event::Data& ev ) {

  UInt_t n = ev.JD_CommonJets().accepted.size();

  Double_t weight = ev.GetEventWeight();

  // Make new MET -- add common muons to the MET
  LorentzV MET = LorentzV(*ev.metP4caloTypeII());
  for(int i = 0; i < int(ev.LD_CommonMuons().accepted.size());i++){
    MET+=(*ev.LD_CommonMuons().accepted[i]);
  }
  


  if ( CleaningPlots_ ){

    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_.size()  ) {
      AlphaT_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_[n]->Fill( ev.HadronicAlphaT(), weight );
    }
    
    if ( n >= nMin_ && n <= nMax_ && n < MHTovMET_raw_.size() ) {
      MHTovMET_raw_[0]->Fill(  ev.CommonMHT().Pt()/MET.Pt(), weight );
      MHTovMET_raw_[n]->Fill(  ev.CommonMHT().Pt()/MET.Pt(), weight );
    }

  }

  return true;
}
