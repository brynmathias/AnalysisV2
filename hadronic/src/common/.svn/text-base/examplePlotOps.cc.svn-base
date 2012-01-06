//
//  examplePlotOps.cc
//  
//
//  Created by Bryn Mathias on 17/03/2011.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "examplePlotOps.hh"
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
#include "TRandom.h"
#include "JetData.hh"

using namespace Operation;

  // -----------------------------------------------------------------------------
examplePlotOps::examplePlotOps( const Utils::ParameterSet& ps ) :
  // Misc
dirName_( ps.Get<std::string>("DirName") ),
nMin_( ps.Get<int>("MinObjects") ),
nMax_( ps.Get<int>("MaxObjects") ),
  // MT2
example_( ps.Get<bool>("ExamplePlots") )
{}

  // -----------------------------------------------------------------------------
  //
examplePlotOps::~examplePlotOps() {}

  // -----------------------------------------------------------------------------
  //
void examplePlotOps::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

  // -----------------------------------------------------------------------------
  //
void examplePlotOps::BookHistos() {
  if ( example_ )           { example(); }

}

  // -----------------------------------------------------------------------------
  //
bool examplePlotOps::Process( Event::Data& ev ) {
  if ( example_ )               { example(ev); }

  return true;
}

  // -----------------------------------------------------------------------------
  //
std::ostream& examplePlotOps::Description( std::ostream& ostrm ) {
  ostrm << "examplePlotOps's PlottingOps ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

  // -----------------------------------------------------------------------------
  //
void examplePlotOps::example() {
  
  BookHistArray( alphaT_,
                "AlphaT",
                "",
                200, 0., 20.,
                nMax_+1, 0, 1, true );
}



bool examplePlotOps::example( Event::Data& ev ) {
  Double_t weight = ev.GetEventWeight();
  std::vector<Event::Jet const *> jets = ev.JD_CommonJets().accepted;
  UInt_t n = jets.size();
  
  if ( n >= nMin_ && n <= nMax_ && n < alphaT_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    alphaT_[0]->Fill( ev.CommonAlphaT(), weight );
    alphaT_[n]->Fill( ev.CommonAlphaT(), weight );
  }
  
  return true;
}

