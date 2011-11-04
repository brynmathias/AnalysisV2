#include "PreScaleSimple.hh"
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
PreScaleSimple::PreScaleSimple( const Utils::ParameterSet& ps ) :
dirName_( ps.Get<std::string>("DirName") ),
  Plots_( ps.Contains("Plots") ? ps.Get<bool>("Plots") : true ),
  NomTrigger_( ps.Get<std::vector< std::string> >("NumeratorTrigger")),
  DeNomTrigger_( ps.Get<std::vector< std::string> >("DenominatorTrigger")),
  verb_(ps.Contains("Verbose") ? ps.Get<bool>("Verbose") : false )
{}

// -----------------------------------------------------------------------------
//
PreScaleSimple::~PreScaleSimple() {}

// -----------------------------------------------------------------------------
//
void PreScaleSimple::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void PreScaleSimple::BookHistos() {
  if ( Plots_ )           { Plots(); }
}

// -----------------------------------------------------------------------------
//
bool PreScaleSimple::Process( Event::Data& ev ) {
  if ( Plots_ )               { Plots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& PreScaleSimple::Description( std::ostream& ostrm ) {
  ostrm << "PreScaled Trigger Plots ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void PreScaleSimple::Plots() {


  BookHistArray( HT_Nom,
    "HT_Nom",
    ";H_{T} GeV",
    2000,0.,2000.,
    1, 0, 1, true );


  BookHistArray( HT_Denom,
    "HT_Denom",
    ";H_{T} GeV",
    2000,0.,2000.,
    1, 0, 1, true );





}


bool PreScaleSimple::Plots( Event::Data& ev ) {

//  OK lets catch the strange examples before we start
// Look for triggers that done have the same L1 seed.
// Now it would be nice if we had the L1 seed for a HLT trigger stored in the Ntuple
// as of Nov 4 2011 we don't. Hence this requires outside knowledge.
// HLT_HT150_v* is seeded by L1_HTT50 and HLT_HT200_v* is seeded by L1_HTT75.

// Lets make this flexable, nom and denom do not have to be the same length.

  std::vector<std::string>::const_iterator nom = NomTrigger_.begin();
  std::vector<std::string>::const_iterator nomEnd = NomTrigger_.end();
  std::vector<std::string>::const_iterator denom = DeNomTrigger_.begin();
  std::vector<std::string>::const_iterator denomEnd = DeNomTrigger_.end();
  int nomPreScale = -1;
  int denomPreScale = -1;
  bool NOMFIRE = false;
  bool DENOMFIRE = false;
  bool carryonsearchingNom = true;
  bool carryonsearchingDenom = true;
  // Take care of all the numerator prescales
  for( ; nom != nomEnd; ++nom){
    if(!carryonsearchingNom) continue;
        size_t found;
        std::string str = *nom;
        // cout << "Checking " << (*nom) << endl;
        str = str.substr(0, str.size() - 1 );
        found = str.find("HLT_HT150_v");
        // handle the L1 prescales
        if(found != string::npos){
          std::map<std::string, int>::const_iterator L1prescale = ev.l1t_prescaled()->find("L1_HTT50");
          if( L1prescale != ev.l1t_prescaled()->end() ){ nomPreScale *= L1prescale->second; }
        }
        found = str.find("HLT_HT200_v");
        if(found != string::npos){
          std::map<std::string, int>::const_iterator L1prescale = ev.l1t_prescaled()->find("L1_HTT75");
          if( L1prescale != ev.l1t_prescaled()->end() ){ nomPreScale *= L1prescale->second; }
        }
    if( nom->at(nom->size()-1) != '*'){
      std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(*nom);
      std::map<std::string, bool>::const_iterator fire = ev.hlt()->find(*nom);

      if( prescale != ev.hlt_prescaled()->end() ){
        nomPreScale *= -prescale->second;
      }
      if( fire != ev.hlt()->end() ){
        carryonsearchingNom = false;
        // cout << "Have found " << (*nom) << endl;
        NOMFIRE = fire->second; continue;}
    }
    else{
      size_t found;
      // cout <<"Trigger has a star in the name searching" << endl;
    // now loop though the map and test the string part -- slow!
      std::map<std::string, int>::const_iterator ipre = ev.hlt_prescaled()->begin();
      std::map<std::string, int>::const_iterator jpre = ev.hlt_prescaled()->end();
      std::map<std::string, bool>::const_iterator fire = ev.hlt()->begin();
      for( ; ipre != jpre; ++ipre, ++fire ){
       // cout << "comparing " << (*nom) << " To " << ipre->first << endl;

        std::string str = *nom;
        str = str.substr(0, str.size() - 1 );
        found = ipre->first.find(str);
        if(found != string::npos){
          nomPreScale *= -ipre->second;
          NOMFIRE = fire->second;
          carryonsearchingNom = false;

          // cout << "Did " << (*nom) << " fire? " << fire->second << endl;
          continue;
        }
      }
    }
  }


  for( ; denom != denomEnd; ++denom){
      if(!carryonsearchingDenom) continue;
        size_t found;
        std::string str = *denom;
        str = str.substr(0, str.size() - 1 );
        found = str.find("HLT_HT150_v");
        // handle the L1 prescales
        if(found != string::npos){
          std::map<std::string, int>::const_iterator L1prescale = ev.l1t_prescaled()->find("L1_HTT50");
          if( L1prescale != ev.l1t_prescaled()->end() ){ denomPreScale *= L1prescale->second; }
        }
        found = str.find("HLT_HT200_v");
        if(found != string::npos){
          std::map<std::string, int>::const_iterator L1prescale = ev.l1t_prescaled()->find("L1_HTT75");
          if( L1prescale != ev.l1t_prescaled()->end() ){ denomPreScale *= L1prescale->second; }
        }
    if( denom->at(denom->size()-1) != '*'){
      std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(*denom);
      std::map<std::string, bool>::const_iterator fire = ev.hlt()->find(*denom);
      if( prescale != ev.hlt_prescaled()->end() ){
        denomPreScale *= -prescale->second;
      }
      if( fire != ev.hlt()->end() ){
        carryonsearchingDenom = false;
        DENOMFIRE = fire->second;}

    }
    else{
      size_t found;
    // now loop though the map and test the string part -- slow!
      std::map<std::string, int>::const_iterator ipre = ev.hlt_prescaled()->begin();
      std::map<std::string, int>::const_iterator jpre = ev.hlt_prescaled()->end();
      std::map<std::string, bool>::const_iterator fire = ev.hlt()->begin();
      for( ; ipre != jpre; ++ipre, ++fire ){
        std::string str = *denom;
        str = str.substr(0, str.size() - 1 );
        found = ipre->first.find(str);
        if(found != string::npos){
          carryonsearchingDenom = false;
          denomPreScale *= -ipre->second;
          DENOMFIRE = fire->second;
        }
      }
    }
  }

  if ( denomPreScale % nomPreScale == 0){
    if(DENOMFIRE){
        HT_Denom[0]->Fill(ev.CommonHT(),1);
      if(NOMFIRE){
        HT_Nom[0]->Fill(ev.CommonHT(),1);
      }
    }

  }

  return true;
}
