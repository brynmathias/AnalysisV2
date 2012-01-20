#include "Trigger.hh"
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
Trigger::Trigger( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
// MT2
  StandardPlots_( ps.Get<bool>("StandardPlots") ),
  AlphaT_(ps.Get<bool>("AlphaT") )
  {}

// -----------------------------------------------------------------------------
//
Trigger::~Trigger() {}

// -----------------------------------------------------------------------------
//
void Trigger::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void Trigger::BookHistos() {
  if ( StandardPlots_ )           { StandardPlots(); }
  if ( AlphaT_ )                      { Alphat(); }
}

// -----------------------------------------------------------------------------
//
bool Trigger::Process( Event::Data& ev ) {
  if ( StandardPlots_ )               { StandardPlots(ev); }
  if ( AlphaT_ )                      { Alphat(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& Trigger::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//

void Trigger::Alphat(){

}


void Trigger::StandardPlots() {

  BookHistArray( HT260_MHT60,
    "HT260_MHT60",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET70SecondJet70,
    "MET70SecondJet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );


  BookHistArray( Meffective250,
    "Meffective250",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective275,
    "Meffective275",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective300,
    "Meffective300",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective325,
    "Meffective325",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective350,
    "Meffective350",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective375,
    "Meffective375",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective400,
    "Meffective400",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective425,
    "Meffective425",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective450,
    "Meffective450",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meffective250SecondJet45,
    "Meffective250SecondJet45",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );
  BookHistArray( Meffective250SecondJet40,
    "Meffective250SecondJet40",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );
  BookHistArray( Meffective250SecondJet35,
    "Meffective250SecondJet35",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET45_HT250,
    "MET45_HT250",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET50_HT250,
    "MET50_HT250",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET65_HT200,
    "MET65_HT200",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET80_HT180,
    "MET80_HT180",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht,
    "Ht",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht200,
    "Ht200",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht250,
    "Ht250",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht300,
    "Ht300",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht150Jet50,
    "Ht150Jet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht150SecondJet50,
    "Ht150SecondJet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht150Jet70,
    "Ht150Jet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht200Jet50,
    "Ht200Jet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht150SecondJet70,
    "Ht150SecondJet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht200SecondJet50,
    "Ht200SecondJet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Ht200SecondJet70,
    "Ht200SecondJet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );



  BookHistArray( MHT50SecondJet50,
    "MHT50SecondJet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHT50SecondJet70,
    "MHT50SecondJet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHT70SecondJet50,
    "MHT70SecondJet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHT70SecondJet70,
    "MHT70SecondJet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET50SecondJet50,
    "MET50SecondJet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET50SecondJet70,
    "MET50SecondJet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );



  BookHistArray( MET60SecondJet35,
    "MET60SecondJet35",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );


  BookHistArray( Ht200Jet70,
    "Ht200Jet70",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET70SecondJet50,
    "MET70SecondJet50",
    ";H_{T};events/10GeV;",
    100, .0, 1000.,
    nMax_+1, 0, 1, true );
}
// -----------------------------------------------------------------------------
//
// struct Trigger::EComp_sort
// {
//   bool operator() (const LorentzV & o1, const LorentzV & o2)  {
//     return(o1.Et() > o2.Et());
//   }
// };

template<template <typename> class P = std::less >
struct sort_LVec_Et
{
   template<class T1, class T2>
   bool operator()(const T1 & o1, const T2 & o2)
   {
       return P<double>()( o2.Et(), o1.Et() );
   }
};
// -----------------------------------------------------------------------------
//

bool Trigger::StandardPlots( Event::Data& ev ) {

  double weight = ev.GetEventWeight();
  std::vector<LorentzV> ThresholdJets;

  std::vector<Event::Jet >::const_iterator ijet = ev.JD_Jets().begin();
  std::vector<Event::Jet >::const_iterator jjet = ev.JD_Jets().end();
  for ( ; ijet != jjet; ++ijet ) {

    LorentzV Jet = *ijet;

    // Jet /= ev.jetCorrFactor()->at((*ijet).GetIndex());
    if( Jet.Et() >= 20. ){ ThresholdJets.push_back(Jet); } // to enter collection jets must be above 20GeV uncorrected
  } // makes a collection of jets that are uncorrected, stores them in a vector
  std::sort(ThresholdJets.begin(),ThresholdJets.end(), sort_LVec_Et<>() ); // sort the uncorrected jet collection in Et order (as the trigger uses them)

  LorentzV mhtAllJets;
  double  htAllJets = 0.;
  for(unsigned int i =0; i < ThresholdJets.size(); i++){
   if(ThresholdJets[i].Et() > 30.){ htAllJets += ThresholdJets[i].Et();}
    mhtAllJets -= ThresholdJets[i];
  }

  // LorentzV mhtEtaThree;
  // double  htEtaThree = 0.;
  // for(unsigned int i =0; i < ThresholdJets.size(); i++){
  //   if(fabs(ThresholdJets[i].Eta) < 3. ){
  //     htEtaThree += ThresholdJets[i].Et();
  //     mhtEtaThree -= ThresholdJets[i];
  //   }
  // }

  unsigned int n = ThresholdJets.size();
//start Meffective trigger studies
//first reference collection:
  // cout << "MHT of Jets is: " << mhtAllJets.Pt() << endl;
  double Meff_allJets = htAllJets + mhtAllJets.Pt();


  if(htAllJets > 260. && mhtAllJets.Pt() > 60.0){
    if ( n >= nMin_ && n <= nMax_ && n < HT260_MHT60.size() ) {
      HT260_MHT60[0]->Fill(ev.CommonHT(), weight);
      HT260_MHT60[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if(Meff_allJets > 250.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective250.size() ) {
      Meffective250[0]->Fill(ev.CommonHT(), weight);
      Meffective250[n]->Fill(ev.CommonHT(), weight);
    }
  }




  if(Meff_allJets > 250. && ThresholdJets[1].Et() > 35.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective250SecondJet35.size() ) {
      Meffective250SecondJet35[0]->Fill(ev.CommonHT(), weight);
      Meffective250SecondJet35[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 250. && ThresholdJets[1].Et() > 40.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective250SecondJet40.size() ) {
      Meffective250SecondJet40[0]->Fill(ev.CommonHT(), weight);
      Meffective250SecondJet40[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 250. && ThresholdJets[1].Et() > 45.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective250SecondJet45.size() ) {
      Meffective250SecondJet45[0]->Fill(ev.CommonHT(), weight);
      Meffective250SecondJet45[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 275.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective275.size() ) {
      Meffective275[0]->Fill(ev.CommonHT(), weight);
      Meffective275[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 300.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective300.size() ) {
      Meffective300[0]->Fill(ev.CommonHT(), weight);
      Meffective300[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 325.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective325.size() ) {
      Meffective325[0]->Fill(ev.CommonHT(), weight);
      Meffective325[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if(Meff_allJets > 350.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective350.size() ) {
      Meffective350[0]->Fill(ev.CommonHT(), weight);
      Meffective350[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 375.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective375.size() ) {
      Meffective375[0]->Fill(ev.CommonHT(), weight);
      Meffective375[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if(Meff_allJets > 400.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective400.size() ) {
      Meffective400[0]->Fill(ev.CommonHT(), weight);
      Meffective400[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if(Meff_allJets > 425.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective425.size() ) {
      Meffective425[0]->Fill(ev.CommonHT(), weight);
      Meffective425[n]->Fill(ev.CommonHT(), weight);
    }
  }
  if(Meff_allJets > 450.){
    if ( n >= nMin_ && n <= nMax_ && n < Meffective450.size() ) {
      Meffective450[0]->Fill(ev.CommonHT(), weight);
      Meffective450[n]->Fill(ev.CommonHT(), weight);
    }
  }



  if ( n >= nMin_ && n <= nMax_ && n < Ht.size() ) {
    Ht[0]->Fill(ev.CommonHT(), weight);
    Ht[n]->Fill(ev.CommonHT(), weight);
  }


  if( htAllJets > 200. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht200.size() ) {
      Ht200[0]->Fill(ev.CommonHT(), weight);
      Ht200[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( htAllJets > 250. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht250.size() ) {
      Ht250[0]->Fill(ev.CommonHT(), weight);
      Ht250[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( htAllJets > 300. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht300.size() ) {
      Ht300[0]->Fill(ev.CommonHT(), weight);
      Ht300[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( htAllJets > 150. && ThresholdJets[0].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht150Jet50.size() ) {
      Ht150Jet50[0]->Fill(ev.CommonHT(), weight);
      Ht150Jet50[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( htAllJets > 150. && ThresholdJets[1].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht150SecondJet50.size() ) {
      Ht150SecondJet50[0]->Fill(ev.CommonHT(), weight);
      Ht150SecondJet50[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( htAllJets > 150. && ThresholdJets[0].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht150Jet70.size() ) {
      Ht150Jet70[0]->Fill(ev.CommonHT(), weight);
      Ht150Jet70[n]->Fill(ev.CommonHT(), weight);
    }
  }
  if( htAllJets > 150. && ThresholdJets[1].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht150SecondJet70.size() ) {
      Ht150SecondJet70[0]->Fill(ev.CommonHT(), weight);
      Ht150SecondJet70[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( htAllJets > 200. && ThresholdJets[0].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht200Jet50.size() ) {
      Ht200Jet50[0]->Fill(ev.CommonHT(), weight);
      Ht200Jet50[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( htAllJets > 200. && ThresholdJets[1].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht200SecondJet50.size() ) {
      Ht200SecondJet50[0]->Fill(ev.CommonHT(), weight);
      Ht200SecondJet50[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( htAllJets > 200. && ThresholdJets[0].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht200Jet70.size() ) {
      Ht200Jet70[0]->Fill(ev.CommonHT(), weight);
      Ht200Jet70[n]->Fill(ev.CommonHT(), weight);
    }
  }
  if( htAllJets > 200. && ThresholdJets[1].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < Ht200SecondJet70.size() ) {
      Ht200SecondJet70[0]->Fill(ev.CommonHT(), weight);
      Ht200SecondJet70[n]->Fill(ev.CommonHT(), weight);
    }
  }



  if( mhtAllJets.Pt() > 50. && ThresholdJets[1].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < MHT50SecondJet50.size() ) {
      MHT50SecondJet50[0]->Fill(ev.CommonHT(), weight);
      MHT50SecondJet50[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( mhtAllJets.Pt() > 50. && ThresholdJets[1].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < MHT50SecondJet70.size() ) {
      MHT50SecondJet70[0]->Fill(ev.CommonHT(), weight);
      MHT50SecondJet70[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( mhtAllJets.Pt() > 70. && ThresholdJets[1].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < MHT70SecondJet50.size() ) {
      MHT70SecondJet50[0]->Fill(ev.CommonHT(), weight);
      MHT70SecondJet50[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( mhtAllJets.Pt() > 70. && ThresholdJets[1].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < MHT70SecondJet70.size() ) {
      MHT70SecondJet70[0]->Fill(ev.CommonHT(), weight);
      MHT70SecondJet70[n]->Fill(ev.CommonHT(), weight);
    }
  }



  if( ev.CaloMET().Et() > 50. && ThresholdJets[1].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET50SecondJet50.size() ) {
      MET50SecondJet50[0]->Fill(ev.CommonHT(), weight);
      MET50SecondJet50[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( ev.CaloMET().Et() > 50. && ThresholdJets[1].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET50SecondJet70.size() ) {
      MET50SecondJet70[0]->Fill(ev.CommonHT(), weight);
      MET50SecondJet70[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( ev.CaloMET().Et() > 70. && ThresholdJets[1].Et() > 50. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET70SecondJet50.size() ) {
      MET70SecondJet50[0]->Fill(ev.CommonHT(), weight);
      MET70SecondJet50[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( ev.CaloMET().Et() > 70. && ThresholdJets[1].Et() > 70. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET70SecondJet70.size() ) {
      MET70SecondJet70[0]->Fill(ev.CommonHT(), weight);
      MET70SecondJet70[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( ev.CaloMET().Et() > 60. && ThresholdJets[1].Et() > 35. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET60SecondJet35.size() ) {
      MET60SecondJet35[0]->Fill(ev.CommonHT(), weight);
      MET60SecondJet35[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( ev.CaloMET().Et() > 45. && htAllJets > 250. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET45_HT250.size() ) {
      MET45_HT250[0]->Fill(ev.CommonHT(), weight);
      MET45_HT250[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( ev.CaloMET().Et() > 50. && htAllJets > 250. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET50_HT250.size() ) {
      MET50_HT250[0]->Fill(ev.CommonHT(), weight);
      MET50_HT250[n]->Fill(ev.CommonHT(), weight);
    }
  }


  if( ev.CaloMET().Et() > 65. && htAllJets > 200. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET65_HT200.size() ) {
      MET65_HT200[0]->Fill(ev.CommonHT(), weight);
      MET65_HT200[n]->Fill(ev.CommonHT(), weight);
    }
  }

  if( ev.CaloMET().Et() > 80. && htAllJets > 180. ){
    if ( n >= nMin_ && n <= nMax_ && n < MET80_HT180.size() ) {
      MET80_HT180[0]->Fill(ev.CommonHT(), weight);
      MET80_HT180[n]->Fill(ev.CommonHT(), weight);
    }
  }
  return true;
}

bool Trigger::Alphat( Event::Data& ev ) {

  // Alpha_t variable
  std::vector<Event::Jet const *>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
  std::vector<Event::Jet const *>::const_iterator jjet = ev.JD_CommonJets().accepted.end();
  std::vector<LorentzV> newJets;
  double Ht = 0.,mhtx = 0.,mhty = 0., dHt = 0., mHt = 0., aT = 0.,codeAlphaT= 0.;
    cout << "______________START EVENT__________________ " << endl;
    std::vector<LorentzV> firstCol;
    std::vector<LorentzV> secondCol;
  for( ; ijet != jjet; ijet++){
    newJets.push_back(**ijet);
    cout <<"Jet Et is " << (*ijet)->Et() << " Jet No is" << newJets.size() << endl;
    std::vector<bool> pseudo;
    codeAlphaT = AlphaT()( newJets, pseudo, true );
    if ( pseudo.size() != newJets.size() ) { abort(); }

    Ht += (*ijet)->Et();
    mhtx-=((*ijet)->Pt())*cos((*ijet)->phi());
    mhty-=((*ijet)->Pt())*sin((*ijet)->phi());
    mHt = sqrt(mhty*mhty + mhtx*mhtx); // Make MHT
    dHt = std::min( fabs(dHt + (*ijet)->Et() ) , fabs(dHt - (*ijet)->Et()) );


    // ( fabs(dHt + (*ijet)->Et() ) < fabs(dHt - (*ijet)->Et()) ? firstCol.push_back( *ijet ) : secondCol.push_back( *ijet ) );

    aT = ( Ht - fabs(dHt) ) / ( 2. * sqrt( ( Ht*Ht ) - ( mHt*mHt ) ) ); // calc alphaT


    cout << dHt << " Min Delta HT from Iterative method \n ______________________________" << std::endl;
    cout << " Assumption wrong " << codeAlphaT << " != " << aT <<  " No Jets considered " << newJets.size() << endl;


  }
  return true;
}


