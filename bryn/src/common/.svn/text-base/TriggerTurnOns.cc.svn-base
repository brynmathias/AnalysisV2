#include "TriggerTurnOns.hh"
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
TriggerTurnOns::TriggerTurnOns( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
// MT2
  Plots_( ps.Get<bool>("Plots") ),
  ReWeight_(ps.Contains("ReWeight") ? ps.Get<bool>("ReWeight") : false ),
  ReWeightL1_(ps.Contains("ReWeightL1") ? ps.Get<bool>("ReWeightL1") : false ),
  ReWeightVec_(ps.Get< std::vector<std::string> >("TriggerReWeight") ),
  L1ReWeightVec_(ps.Get< std::vector<std::string> >("L1TriggerReWeight") ),
  verb_(ps.Contains("Verbose") ? ps.Get<bool>("Verbose") : false )
  {}

// -----------------------------------------------------------------------------
//
TriggerTurnOns::~TriggerTurnOns() {}

// -----------------------------------------------------------------------------
//
void TriggerTurnOns::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void TriggerTurnOns::BookHistos() {
  if ( Plots_ )           { Plots(); }
}

// -----------------------------------------------------------------------------
//
bool TriggerTurnOns::Process( Event::Data& ev ) {
  if ( Plots_ )               { Plots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& TriggerTurnOns::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void TriggerTurnOns::Plots() {
  BookHistArray( HT_,
    "HT",
    ";H_{T} GeV",
    300,0.,3000.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T}",
    500,0.,5.,
    nMax_+1, 0, 1, true );


  BookHistArray( MHT_,
    "MHT",
    ";#slash{H}_{T}",
    100,0.,1000.,
    nMax_+1, 0, 1, true );


  BookHistArray( MEff_,
    "Meff",
    ";M_{eff} GeV",
    100,0.,1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( preScaleHLT_,
    "preScaleHLT",
    ";Prescale",
    1000,0.,1000.,
    1, 0, 1, true );


  BookHistArray( preScaleL1andHLT_,
    "PreScale_L1AndHT",
    ";Prescale",
    1000,0.,1000.,
    1, 0, 1, true );



  BookHistArray( MHT_HT_,
    "MHTovHT",
    ";#slash{H}_{T}/H_{T}",
    100,0.,1.,
    1, 0, 1, true );


  BookHistArray( MHT_MEff_,
    "MHTovMeff",
    ";#slash{H}_{T}/M_{Eff}",
    100,0.,1.,
    1, 0, 1, true );


}


bool TriggerTurnOns::Plots( Event::Data& ev ) {
  UInt_t n = ev.CommonObjects().size();
  Double_t weight = ev.GetEventWeight();
  int preScaleVal = 99999;
  if(ReWeight_ ){
    if(verb_){
      std::cout << "New Event" << std::endl;
    }
    std::vector<std::string>::const_iterator it = ReWeightVec_.begin();
    std::vector<std::string>::const_iterator ite = ReWeightVec_.end();
    for( ; it != ite; ++it){
      if( it->at(it->size()-1) != '*'){
        std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
        std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(*it);
        if( (trig != ev.hlt()->end() && trig->second) && (prescale != ev.hlt_prescaled()->end() && prescale->second < preScaleVal) ) {
          preScaleVal = prescale->second ;
          if(verb_){
            std::cout << "Trigger " << (*it) << " Has a prescale of " << prescale->second << " " << std::endl;
          }
        }
      }else{
        size_t found;
    // now loop though the map and test the string part -- slow!
        std::map<std::string, bool>::const_iterator itrig = ev.hlt()->begin();
        std::map<std::string, bool>::const_iterator jtrig = ev.hlt()->end();
        std::map<std::string, int>::const_iterator ipre = ev.hlt_prescaled()->begin();
        for( ; itrig != jtrig; ++itrig, ++ipre ){
          if(itrig->second){
            std::string str = *it;
            str = str.substr(0, str.size() - 1 );
          // cout <<*it<< " compare with " << itrig->first << endl;
            found = itrig->first.find(str);
            if(found != string::npos){ preScaleVal = ipre->second; }
          }
        }
      }
    }
    if(verb_){
      cout << " The lowest prescale in the event is " << preScaleVal << std::endl;
      if(preScaleVal == 99999) {
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
        cout << "Triggers that exist in the event:" <<endl;
        for(std::map<std::string,bool>::const_iterator it2 = ev.hlt()->begin();
        it2!= ev.hlt()->end(); ++it2){
          if( it2->second ) std::cout << it2->first << std::endl;
        }
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
      }
    }
    if(preScaleVal == 99999) preScaleVal = 1;
    double factor = double(preScaleVal);
    weight *= factor;
  }

  preScaleHLT_[0]->Fill(weight,1.);

if(ReWeightL1_){
    std::map<std::string, bool>::const_iterator itrig = ev.l1t()->begin();
    std::map<std::string, bool>::const_iterator jtrig = ev.l1t()->end();
    std::map<std::string, int>::const_iterator ipre = ev.l1t_prescaled()->begin();
    // std::cout << "Starting to look at the L1 trigger info"<< std::endl;
      if(verb_){
         for( ; itrig != jtrig; ++itrig, ++ipre ){
              std::cout << itrig->first << " its prescale is: " << ipre->second << std::endl;
            }
      }
      int L1PreScale = -1;
      // Search the L1 prescale collection to find the L1 prescale do this for a vector of inputs
      // Most of the time it will be a single trigger, but we want to handle the case when it is not.
      std::vector<std::string>::const_iterator it =  L1ReWeightVec_.begin();
      std::vector<std::string>::const_iterator ite = L1ReWeightVec_.end();
          for( ; it != ite; ++it){
            std::map<std::string, int>::const_iterator prescale = ev.l1t_prescaled()->find(*it);
            if(L1PreScale == -1) L1PreScale = prescale->second;
            else if( L1PreScale > prescale->second) L1PreScale = prescale->second;
          }
          if(L1PreScale != -1){
          weight *= L1PreScale;
        }
  }
  preScaleL1andHLT_[0]->Fill(weight,1.);

  if ( n >= nMin_ && n <= nMax_ && n < HT_.size()) {
    HT_[0]->Fill(ev.CommonHT(),weight);
    HT_[n]->Fill(ev.CommonHT(),weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < AlphaT_.size()) {
    AlphaT_[0]->Fill(ev.CommonAlphaT(),weight);
    AlphaT_[n]->Fill(ev.CommonAlphaT(),weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < MHT_HT_.size()) {
    MHT_HT_[0]->Fill(ev.CommonMHT().Pt()/ev.CommonHT(),weight);
    MHT_HT_[n]->Fill(ev.CommonMHT().Pt()/ev.CommonHT(),weight);
  }

  if ( n >= nMin_ && n <= nMax_ && n < MHT_.size()) {
    MHT_[0]->Fill(ev.CommonMHT().Pt(),weight);
    MHT_[n]->Fill(ev.CommonMHT().Pt(),weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < MEff_.size()) {
    MEff_[0]->Fill(ev.CommonMHT().Pt()+ev.CommonHT(),weight);
    MEff_[n]->Fill(ev.CommonMHT().Pt()+ev.CommonHT(),weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < MHT_MEff_.size()) {
    MHT_MEff_[0]->Fill(ev.CommonMHT().Pt()/(ev.CommonMHT().Pt()+ev.CommonHT()),weight);
    MHT_MEff_[n]->Fill(ev.CommonMHT().Pt()/(ev.CommonMHT().Pt()+ev.CommonHT()),weight);
  }

  return true;
}
