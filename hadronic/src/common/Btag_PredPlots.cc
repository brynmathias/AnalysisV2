#include "Btag_PredPlots.hh"
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
#include "GenMatrixBin.hh"

using namespace Operation;

// -----------------------------------------------------------------------------
Btag_PredPlots::Btag_PredPlots( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
  GenPt_(ps.Get<std::vector<double> >("GenPt")),
  GenEta_(ps.Get<std::vector<double> >("GenEta")),
  Pt_Eta_Eff_(ps.Get<std::vector<double> >("Pt_Eta_Eff")),

  Mistag_GenPt_(ps.Get<std::vector<double> >("Mistag_GenPt")),
  Mistag_GenEta_(ps.Get<std::vector<double> >("Mistag_GenEta")),
  Mistag_Pt_Eta_Eff_(ps.Get<std::vector<double> >("Mistag_Pt_Eta_Eff")),

  JetPt_High_(ps.Get<std::vector<double> >("JetPt_High")),
  JetPt_Low_(ps.Get<std::vector<double> >("JetPt_Low")),
  Variation_(ps.Get<std::vector<double> >("Variation")),

  StandardPlots_( ps.Get<bool>("StandardPlots") )

  { 
  }

// -----------------------------------------------------------------------------
//
Btag_PredPlots::~Btag_PredPlots() {}

// -----------------------------------------------------------------------------
//
void Btag_PredPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void Btag_PredPlots::BookHistos() {
  if ( StandardPlots_ )           { StandardPlots(); }
}

// -----------------------------------------------------------------------------
//
bool Btag_PredPlots::Process( Event::Data& ev ) {
  if ( StandardPlots_ )               { StandardPlots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& Btag_PredPlots::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void Btag_PredPlots::StandardPlots() {

  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    4, 0, 1, true );
  
  BookHistArray( HT_,
    "HT",
    ";H_{T} (GeV); Events/25 GeV;",
    2500,0.,2500.,
    4, 0, 1, true );

  BookHistArray( MatchedB_vs_Matched_noB_,
    "Matched_vs_Matched_noB",
    ";Number B-jets; Number Not B-jets;",
    6,0.,6.,
    10,0.,10.,
    4, 0, 1, true );

  BookHistArray( MatchedB_vs_Matched_noB_alphaT_,
    "Matched_vs_Matched_noB_alphaT",
    ";Number B-jets; Number Not B-jets;",
    6,0.,6.,
    10,0.,10.,
    4, 0, 1, true );

  BookHistArray( GenJetPt_,
    "GenJetPt",
    ";GeV ; Event ",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_,
    "Btagged_GenJetPt",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( Btagged_NotMatched_RecoJet_,
    "Btagged_NotMatched_RecoJet_",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( NotMatched_RecoJet_,
    "NotMatched_RecoJet_",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_SFb_,
    "Btagged_GenJetPt_SFb",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( Btagged_GenJetPt_SFb_plus_,
    "Btagged_GenJetPt_SFb_plus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_SFb_minus_,
    "Btagged_GenJetPt_SFb_minus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( GenJetPt_noB_,
    "GenJetPt_noB",
    ";GeV ; Event ",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_,
    "Btagged_GenJetPt_noB",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_SFlight_,
    "Btagged_GenJetPt_noB_SFlight",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_SFlight_plus_,
    "Btagged_GenJetPt_noB_SFlight_plus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_SFlight_minus_,
    "Btagged_GenJetPt_noB_SFlight_minus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

 BookHistArray( Duplicate_GenJetPt_,
    "Duplicate_GenJetPt",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

   BookHistArray( BtagPreAlphaT_5_,
    "Btag_Pre_AlphaT_5_",
    ";Number of Btags;",
    6,0.,6.,
    4, 0, 1, true );

  BookHistArray( BtagAfterAlphaT_5_55_,
    "Btag_Post_AlphaT_5_55",
    ";Number of Btags;",
    6,0.,6.,
    4, 0, 1, true );

}
// -----------------------------------------------------------------------------
//
bool Btag_PredPlots::StandardPlots( Event::Data& ev ) {

  UInt_t nBtags_five = 0;
  for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
  if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 5) > 0.679) {
  nBtags_five++;
   } 
  }

  UInt_t n = ev.JD_CommonJets().accepted.size();
  if(n>=3){n=3;}
  Double_t weight = ev.GetEventWeight();
  
  if ( n >= nMin_ && n <= nMax_ && n < BtagPreAlphaT_5_.size()) {
    BtagPreAlphaT_5_[0]->Fill( nBtags_five, weight );
    BtagPreAlphaT_5_[n]->Fill( nBtags_five, weight );
    }

  if ( StandardPlots_ ){

    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_.size()  ) {
      AlphaT_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_[n]->Fill( ev.HadronicAlphaT(), weight );
    }

   int counter_noB = 0;
   int counter = 0;
   std::set<unsigned> recojet;
   std::set<unsigned> matched;

   if (ev.pthat.enabled()){
      GenMatrixBin gen(&ev);
      std::map<std::pair<int, double>, double> error_variation_;

      for(std::vector<double>::const_iterator it = JetPt_Low_.begin();it != JetPt_Low_.end(); it++){
              error_variation_.insert(std::make_pair(std::make_pair((*it),JetPt_High_[it - JetPt_Low_.begin()]),Variation_[it - JetPt_Low_.begin()]));}

      double match_jetpt_low;
      double match_jetpt_high;
      
      for(unsigned int i = 0; i < gen.the_GenB.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenB.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }
        if(index_keeper != -1 && minDeltaR < 0.5 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5 ){

          float x = ev.JD_CommonJets().accepted.at(index_keeper)->Pt();
          for(std::vector<double>::const_iterator JetPt_it = JetPt_Low_.begin(); JetPt_it != JetPt_Low_.end(); JetPt_it++){
                if (x  > (*JetPt_it) && x < (*(JetPt_it+1))){
                match_jetpt_low = (*JetPt_it);
                match_jetpt_high = JetPt_High_[JetPt_it - JetPt_Low_.begin()];
                break;}
                else{ 
                  match_jetpt_low = 30.0;
                  match_jetpt_high = 40.0;
                 }}
          std::pair<int, double> cd = make_pair(match_jetpt_low, match_jetpt_high);
          if(error_variation_.find(cd) == error_variation_.end()){
            std::stringstream ss;
            ss << "Point: GenPt=" << match_jetpt_low << ",Higher " << match_jetpt_high << ") not found for mistag. Aborting.";
            throw std::invalid_argument(ss.str());
            }
          double sigma_correction = error_variation_.find(cd)->second;
          float SFb = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))));
          float SFb_plus = SFb + sigma_correction;
          float SFb_minus = SFb - sigma_correction;
          
          counter += 1;

          if ( i != 0 && matched.count(index_keeper)){ Duplicate_GenJetPt_[0]->Fill(gen.the_GenB.at(i)->Pt(),weight); }
          matched.insert(index_keeper);
          recojet.insert(index_keeper);
          //cout << "Reco Jet  " << index_keeper << "Matched to Gen BJet " << i << endl; 
          GenJetPt_[0]->Fill(gen.the_GenB.at(i)->Pt(),weight);

          if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(index_keeper)->GetIndex(), 5) > 0.679){
            //cout << "Reco Jet " << index_keeper << "Has been Btagged" << endl; 
            Btagged_GenJetPt_[0]->Fill(gen.the_GenB.at(i)->Pt(),weight);
            Btagged_GenJetPt_SFb_[0]->Fill(gen.the_GenB.at(i)->Pt(),(weight*SFb));
            Btagged_GenJetPt_SFb_plus_[0]->Fill(gen.the_GenB.at(i)->Pt(),(weight*SFb_plus));
            Btagged_GenJetPt_SFb_minus_[0]->Fill(gen.the_GenB.at(i)->Pt(),(weight*SFb_minus));
               }
             }
            }
/////////////////////////////////////////////////////////////////////////////////////

if (ev.pthat.enabled()){

      for(unsigned int i = 0; i < gen.the_GenJets_noB.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenJets_noB.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }

        if(index_keeper != -1 && minDeltaR < 0.5 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5  ){
          counter_noB += 1;
          GenJetPt_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),weight);

          if ( i != 0 && matched.count(index_keeper)){Duplicate_GenJetPt_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),weight);}
          matched.insert(index_keeper);
          recojet.insert(index_keeper);

          if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(index_keeper)->GetIndex(), 5) > 0.679){
            
            float SFlight;
            float SFlight_minus;
            float SFlight_plus;
            float x = ev.JD_CommonJets().accepted.at(index_keeper)->Pt();
            for(std::vector<double>::const_iterator JetPt_it = JetPt_Low_.begin(); JetPt_it != JetPt_Low_.end(); JetPt_it++){
                if (x  > (*JetPt_it) && x < (*(JetPt_it+1))){
                match_jetpt_low = (*JetPt_it);
                match_jetpt_high = JetPt_High_[JetPt_it - JetPt_Low_.begin()];
                break;}
                else{
                  match_jetpt_low = 30.0;
                  match_jetpt_high = 40.0;}
              }
            std::pair<int, double> cd = make_pair(match_jetpt_low, match_jetpt_high);
            if(error_variation_.find(cd) == error_variation_.end()){
            std::stringstream ss;
            ss << "Point: GenPt=" << match_jetpt_low << ",Higher " << match_jetpt_high << ") not found for mistag. Aborting.";
            throw std::invalid_argument(ss.str());
            }
            double sigma_correction = error_variation_.find(cd)->second; 

            if(gen.the_GenJets_noB.at(i)->GetID() == 4){
              SFlight = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))));
              SFlight_minus = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))))-(2*sigma_correction);
              SFlight_plus = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))))+(2*sigma_correction); }
            else{
               SFlight = ((1.04318+(0.000848162*x))+(-2.5795e-06*(x*x)))+(1.64156e-09*(x*(x*x)));
               SFlight_minus =((0.962627+(0.000448344*x))+(-1.25579e-06*(x*x)))+(4.82283e-10*(x*(x*x))); //min
               SFlight_plus = ((1.12368+(0.00124806*x))+(-3.9032e-06*(x*x)))+(2.80083e-09*(x*(x*x))); //max
               }

            Btagged_GenJetPt_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),weight);
            Btagged_GenJetPt_noB_SFlight_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),(weight*SFlight));
            Btagged_GenJetPt_noB_SFlight_plus_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),(weight*SFlight_plus));
            Btagged_GenJetPt_noB_SFlight_minus_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),(weight*SFlight_minus));

              }
             }
            }
        }

for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
     bool reco_match = false;
     for(std::set<unsigned>::iterator it = recojet.begin(); it != recojet.end(); it++){
      if(j == (*it)){reco_match = true;}
      }

     if (!reco_match){
       counter_noB += 1;
       GenJetPt_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);
       NotMatched_RecoJet_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);

       if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(j)->GetIndex(), 5) > 0.679){
       Btagged_NotMatched_RecoJet_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);
       float SFlight;
       float SFlight_minus;
       float SFlight_plus;
       float x = ev.JD_CommonJets().accepted.at(j)->Pt();
       SFlight = ((1.04318+(0.000848162*x))+(-2.5795e-06*(x*x)))+(1.64156e-09*(x*(x*x)));
       SFlight_minus =((0.962627+(0.000448344*x))+(-1.25579e-06*(x*x)))+(4.82283e-10*(x*(x*x))); //min
       SFlight_plus = ((1.12368+(0.00124806*x))+(-3.9032e-06*(x*x)))+(2.80083e-09*(x*(x*x))); //max

       Btagged_GenJetPt_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);
       Btagged_GenJetPt_noB_SFlight_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),(weight*SFlight));
       Btagged_GenJetPt_noB_SFlight_plus_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),(weight*SFlight_plus));
       Btagged_GenJetPt_noB_SFlight_minus_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),(weight*SFlight_minus));

       }
     }
}

if( n>=nMin_ && nMax_ && n < MatchedB_vs_Matched_noB_.size()){
MatchedB_vs_Matched_noB_[0]->Fill(counter,counter_noB,weight);
MatchedB_vs_Matched_noB_[n]->Fill(counter,counter_noB,weight);}

if(ev.HadronicAlphaT() > 0.55){
if( n>=nMin_ && nMax_ && n < MatchedB_vs_Matched_noB_alphaT_.size()){
MatchedB_vs_Matched_noB_alphaT_[0]->Fill(counter,counter_noB,weight);
MatchedB_vs_Matched_noB_alphaT_[n]->Fill(counter,counter_noB,weight);}
}

}
     
if(ev.HadronicAlphaT() > 0.55){

 UInt_t nBtags_AT_five_55 = 0;
 for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
    if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 5) > 0.679) {nBtags_AT_five_55++;} 
 }

 if ( n >= nMin_ && n <= nMax_ && n < BtagAfterAlphaT_5_55_.size()) {
    BtagAfterAlphaT_5_55_[0]->Fill( nBtags_AT_five_55, weight );
    BtagAfterAlphaT_5_55_[n]->Fill( nBtags_AT_five_55, weight );
 }
      }
    }

  return true;

}
