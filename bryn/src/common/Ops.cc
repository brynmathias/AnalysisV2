#include "Ops.hh"
#include "AlphaT.hh"
#include <iostream>
#include <string>
#include "TString.h"
#include <fstream>
//#include "NLOTools.hh"
#include "Types.hh"
#include "Jet.hh"

using namespace Operation;

confHT::confHT(float JetEtThreshold,float cutVal) :
JetEt_(JetEtThreshold),
  cut_(cutVal)
  {;}

bool confHT::Process( Event::Data& ev){
  //Get the CommonJets - baby jets etc
  std::vector<Event::Jet const *>::const_iterator ijet  = ev.JD_CommonJets().accepted.begin();
  std::vector<Event::Jet const *>::const_iterator jjet  = ev.JD_CommonJets().accepted.end();
  std::vector<Event::Jet const *>::const_iterator ibaby = ev.JD_CommonJets().baby.begin();
  std::vector<Event::Jet const *>::const_iterator jbaby = ev.JD_CommonJets().baby.end();
  double HT  = 0.;
  for(; ijet!=jjet; ++ijet){
    if( (*ijet)->Et() > JetEt_){
      HT += ((*ijet)->E()/cosh((*ijet)->Eta()));
    }
  }
  for( ; ibaby!=jbaby; ++ibaby){
    if( (*ibaby)->pt() > JetEt_ ){
      HT += ((*ibaby)->E()/cosh((*ibaby)->Eta()));
    }
  }

  if ( HT > cut_) return true;
  return false;
}

std::ostream& confHT::Description( std::ostream &ostrm){
  ostrm << "Cut on custom HT of " << cut_ << " using jets above " << JetEt_ << " GeV";
  return ostrm;
}



alphaTriggerEmu::alphaTriggerEmu(float aT_Thresh,float JetEtThreshold, float HTThreshold,int maxNjets):
  aTCut_(aT_Thresh),
  JetEt_(JetEtThreshold),
  HtCut_(HTThreshold),
  maxNjets_(maxNjets){;}


bool alphaTriggerEmu::Process( Event::Data &ev){
  std::vector<Event::Jet> triggerJets;
    //  Cross cleaning fucks us around here need to use JD_Jets
    // std::vector<Event::Jet const *>::const_iterator ijet  = ev.JD_CommonJets().accepted.begin();
    // std::vector<Event::Jet const *>::const_iterator jjet  = ev.JD_CommonJets().accepted.end();
    // std::vector<Event::Jet const *>::const_iterator ibaby = ev.JD_CommonJets().baby.begin();
    // std::vector<Event::Jet const *>::const_iterator jbaby = ev.JD_CommonJets().baby.end();
    // for(; ijet!=jjet; ++ijet){
    //   if( ((*ijet)->E()/cosh((*ijet)->Eta())) > JetEt_){
    //     if(triggerJets.size() < maxNjets_){ triggerJets.push_back((**ijet)); }
    //   }
    // }
    // for( ; ibaby!=jbaby; ++ibaby){
    //   if( ((*ibaby)->E()/cosh((*ibaby)->Eta())) > JetEt_ ){
    //     if(triggerJets.size() < maxNjets_){triggerJets.push_back((**ibaby));}
    //   }
    // }
  std::vector<Event::Jet>::const_iterator ijet = ev.JD_Jets().begin();
  std::vector<Event::Jet>::const_iterator jjet = ev.JD_Jets().end();
    for(; ijet!=jjet; ++ijet){
      if( ((ijet)->E()/cosh((ijet)->Eta())) > JetEt_ && fabs((ijet)->Eta()) < 3.0){
        if(triggerJets.size() < maxNjets_){ triggerJets.push_back((*ijet)); }
      }
    }
  double ht = 0.;
  double mhtx = 0., mhty = 0.;
  int nJets = 0;
  double dht = 0.;
  std::vector<Event::Jet>::iterator i  = triggerJets.begin();
  std::vector<Event::Jet>::iterator j  = triggerJets.end();
  // printf("Size of jet collection %d \n",triggerJets.size());
  for(; i!=j; ++i){
    double mHT = 0.;
    double aT = 0.;
    ht += ((i)->E()/cosh((i)->Eta())); // HT
      mhtx-=((i)->E()/cosh((i)->Eta()))*cos((i)->Phi());
      mhty-=((i)->E()/cosh((i)->Eta()))*sin((i)->Phi());
      mHT = sqrt(mhty*mhty + mhtx*mhtx); // Make MHT
      nJets++;
      dht += ( nJets < 2 ?((i)->E()/cosh((i)->Eta())) : -1.* ((i)->E()/cosh((i)->Eta())) ); // Ripped from rob for DHT
      if ( nJets == 2 || nJets == 3 ) {
        aT = ( ht - fabs(dht) ) / ( 2. * sqrt( ( ht*ht ) - ( mHT*mHT ) ) ); // calc alphaT
      } else if ( nJets > 3 ) {
        aT =  ( ht ) / ( 2. * sqrt( ( ht*ht ) - ( mHT*mHT ) ) ); // Calc Beta T if more jets
      }
      // printf("Itertion no %d, alphat %f ht %f \n",nJets,aT,ht);
      if(aT > aTCut_ && ht > HtCut_){
        return true;
      }
    }

  return false; // if no pass this returns zero
}




std::ostream& alphaTriggerEmu::Description( std::ostream &ostrm){
  ostrm << "Cut on emulated alphaT trigger of " << aTCut_ << " using jets above " << JetEt_ << " GeV" << " HT above " << HtCut_ << " and limited to " << maxNjets_ << "Jets ";
  return ostrm;
}


//---------------------------------------------------------------------
checkTrigExists::checkTrigExists( const Utils::ParameterSet& ps ) :
  trigList(ps.Get< std::vector<std::string> >("TrigExistsList") )
    {;}

  bool checkTrigExists::Process( Event::Data &ev ){
    std::vector<std::string>::const_iterator it = trigList.begin();
    std::vector<std::string>::const_iterator ite = trigList.end();
    for( ; it != ite; ++it){
      if( it->at(it->size()-1) != '*'){
        // std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
        std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(*it);
        if( prescale == ev.hlt_prescaled()->end() ) return false;
        if( prescale != ev.hlt_prescaled()->end() && prescale->second == 0 ) return false;
      }else{
        size_t found;
    // now loop though the map and test the string part -- slow!
        std::map<std::string, int>::const_iterator ipre = ev.hlt_prescaled()->begin();
        std::map<std::string, int>::const_iterator jpre = ev.hlt_prescaled()->end();
        for( ; ipre != jpre; ++ipre, ++ipre ){
            std::string str = *it;
            str = str.substr(0, str.size() - 1 );
          // cout <<*it<< " compare with " << itrig->first << endl;
            found = ipre->first.find(str);
            if(found == string::npos){ return false; }
            if( found != string::npos && ipre->second == 0 ) return false;
        }
      }
    }
    return true;
  }

std::ostream& checkTrigExists::Description( std::ostream &ostrm){
  ostrm << "Check that the following triggers: \n ";
    std::vector<std::string>::const_iterator it = trigList.begin();
    std::vector<std::string>::const_iterator ite = trigList.end();
    for( ; it != ite; ++it){
      ostrm << "\t" << *it << "\n";
    }
    ostrm << "Exist in the event.";
    return ostrm;
}
