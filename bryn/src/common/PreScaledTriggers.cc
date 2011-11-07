#include "PreScaledTriggers.hh"
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
PreScaledTriggers::PreScaledTriggers( const Utils::ParameterSet& ps ) :
dirName_( ps.Get<std::string>("DirName") ),
  Plots_( ps.Contains("Plots") ? ps.Get<bool>("Plots") : true ),
  NomTrigger_( ps.Get<std::string>("NumeratorTrigger")),
  DeNomTrigger_( ps.Get<std::string>("DenominatorTrigger")),
  verb_(ps.Contains("Verbose") ? ps.Get<bool>("Verbose") : false )
{
  hIdxTrack_ = 1;
}

// -----------------------------------------------------------------------------
//
PreScaledTriggers::~PreScaledTriggers() {}

// -----------------------------------------------------------------------------
//
void PreScaledTriggers::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void PreScaledTriggers::BookHistos() {
  if ( Plots_ )           { Plots(); }
}

// -----------------------------------------------------------------------------
//
bool PreScaledTriggers::Process( Event::Data& ev ) {
  if ( Plots_ )               { Plots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& PreScaledTriggers::Description( std::ostream& ostrm ) {
  ostrm << "PreScaled Trigger Plots ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void PreScaledTriggers::Plots() {


  BookHistArray( HT_Nom,
    "HT_Nom",
    ";H_{T} GeV",
    2000,0.,2000.,
    50, 0, 1, true );


  BookHistArray( HT_Denom,
    "HT_Denom",
    ";H_{T} GeV",
    2000,0.,2000.,
    50, 0, 1, true );


  BookHistArray( OverLapCheck_,
    "OverLapCheck",
    ";Did Denom Fire given Nom did?",
    2,-0.5,1.5,
    50, 0, 1, true );





}


bool PreScaledTriggers::Plots( Event::Data& ev ) {

  // Get prescales of both triggers
  int NomPre = 0;
  int DenomPre = 0;
  bool NomPass = false;
  bool DenomPass = false;
  if ( NomTrigger_.at(NomTrigger_.size()-1) != '*'){
    std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(NomTrigger_);
    std::map<std::string, bool>::const_iterator pass = ev.hlt()->find(NomTrigger_);
    if( prescale != ev.hlt_prescaled()->end()  ) NomPre = prescale->second;
    if( pass != ev.hlt()->end() ) NomPass = pass->second;
  }
  else{
    size_t found;
    // now loop though the map and test the string part -- slow!
    std::map<std::string, int>::const_iterator ipre = ev.hlt_prescaled()->begin();
    std::map<std::string, bool>::const_iterator pass = ev.hlt()->begin();
    std::map<std::string, int>::const_iterator jpre = ev.hlt_prescaled()->end();
    for( ; ipre != jpre; ++ipre, ++pass ){
      std::string str = NomTrigger_;
      str = str.substr(0, str.size() - 1 );
      // cout <<NomTrigger_<< " compare with " << ipre->first << endl;
      found = ipre->first.find(str);
      if(found != string::npos){
        NomPre = ipre->second;
      }
      if(found != string::npos){
        NomPass = pass->second;
      }

    }
  }

  if ( DeNomTrigger_.at(DeNomTrigger_.size()-1) != '*'){
    std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(DeNomTrigger_);
    std::map<std::string, bool>::const_iterator pass = ev.hlt()->find(DeNomTrigger_);
    if( prescale != ev.hlt_prescaled()->end()  ) DenomPre = prescale->second;
    if( pass != ev.hlt()->end()  ) DenomPass = pass->second;

  }
  else{
    size_t found;
    // now loop though the map and test the string part -- slow!
    std::map<std::string, int>::const_iterator ipre = ev.hlt_prescaled()->begin();
    std::map<std::string, bool>::const_iterator pass = ev.hlt()->begin();
    std::map<std::string, int>::const_iterator jpre = ev.hlt_prescaled()->end();
    for( ; ipre != jpre; ++ipre, ++pass ){
      std::string str = DeNomTrigger_;
      str = str.substr(0, str.size() - 1 );
      // cout <<DeNomTrigger_ << " compare with " << ipre->first << endl;
      found = ipre->first.find(str);
      if(found != string::npos){ DenomPre = ipre->second; }
      found = pass->first.find(str);
      if(found != string::npos){ DenomPass = pass->second; }
    }
  }

  std::pair<int,int> key(NomPre,DenomPre);
  std::map<std::pair<int,int> , int >::const_iterator histN = histMap_.find(key);
  if( histN == histMap_.end() ) {
    histMap_.insert(make_pair( key, hIdxTrack_) );
    HT_Nom[hIdxTrack_]->SetTitle(Form("Nom_%sPre_%d_%sPre_%d",      NomTrigger_.c_str(),NomPre,DeNomTrigger_.c_str(),DenomPre));
    HT_Denom[hIdxTrack_]->SetTitle(Form("Denom_%sPre_%d_%sPre_%d",  NomTrigger_.c_str(),NomPre,DeNomTrigger_.c_str(),DenomPre));
    HT_Nom[hIdxTrack_]->SetName(Form("Nom_%sPre_%d_%sPre_%d",      NomTrigger_.c_str(),NomPre,DeNomTrigger_.c_str(),DenomPre));
    HT_Denom[hIdxTrack_]->SetName(Form("Denom_%sPre_%d_%sPre_%d",  NomTrigger_.c_str(),NomPre,DeNomTrigger_.c_str(),DenomPre));
    OverLapCheck_[hIdxTrack_]->SetName(Form("OverLapCheck_%sPre_%d_%sPre_%d",  NomTrigger_.c_str(),NomPre,DeNomTrigger_.c_str(),DenomPre));
    hIdxTrack_++;
  }
 histN = histMap_.find(key);
  if( histN != histMap_.end() ) {
    if(NomPass && DenomPass) OverLapCheck_[histN->second]->Fill(1.0,1.0);
    if(NomPass && !DenomPass) OverLapCheck_[histN->second]->Fill(0.0,1.0);
    if(DenomPass){
      HT_Denom[histN->second]->Fill(ev.CommonHT(),1.);
      if(NomPass){
      HT_Nom[histN->second]->Fill(ev.CommonHT(),1.);
      }
    }
  }



  return true;
}
