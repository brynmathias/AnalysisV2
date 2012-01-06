#include "Ops.hh"
#include "AlphaT.hh"
#include <iostream>
#include <string>
#include <fstream>
#include "vector"
#include "Types.hh"

using namespace Operation;

// ----------------------------------------------------------------
AlphatTriggerCut::AlphatTriggerCut( float cut, float HTthresh, float LowerBound)
  : cut_(cut),
  HTthresh_(HTthresh),
  LowerBound_(LowerBound)
  {;}
// ----------------------------------------------------------------
bool AlphatTriggerCut::Process( Event::Data& ev){

  double MHTx = 0.;
  double MHTy = 0.;
  double HT = 0.;
  for(unsigned int i = 0; i <  ev.JD_Jets().size(); i++){
    if(ev.JD_Jets()[i].Et() > LowerBound_ && fabs(ev.JD_Jets()[i].Eta()) < 3.){
      double  MHT = 0.;
      HT+=ev.JD_Jets()[i].Et();
      MHTx-=ev.JD_Jets()[i].Et()*cos(ev.JD_Jets()[i].Phi());
      MHTy-=ev.JD_Jets()[i].Et()*sin(ev.JD_Jets()[i].Phi());
      MHT = sqrt(MHTy*MHTy + MHTx*MHTx);
      if(i == 1){ //dijet case check alpha T
        double alpha = (HT - (ev.JD_Jets()[0].Et() - ev.JD_Jets()[1].Et() )) / (2.0*sqrt(HT*HT - MHT*MHT));
        if(HT > HTthresh_ && alpha > cut_){ return true;}
      } // end Dijets
      if(i >1 ){ // nJet case check MHT/HT (BetaT)
        double alpha = (HT) / (2.0*sqrt(HT*HT - MHT*MHT));
        if(HT > HTthresh_ && alpha > cut_){return true;}
      } // end NJets
    }//end jet selection
  }//end jet loop

  return false;
}

std::ostream& AlphatTriggerCut::Description( std::ostream &ostrm ) {
  ostrm << "AlphatTriggerCut " << cut_ << " " << " Jet Scale: " <<LowerBound_ ;
  return ostrm;
}



MeffTriggerCut::MeffTriggerCut( float cut, float JetThreshold, float MhtJetThreshold)
  : cut_(cut),
  JetThreshold_(JetThreshold),
  MhtThreshold_(MhtJetThreshold)
  {;}
bool MeffTriggerCut::Process( Event::Data& ev){
  double MHTx = 0.;
  double MHTy = 0.;
  double  HT =0.;

  vector<Event::Jet> newJets;
  newJets.clear();
  for(unsigned int i = 0; i <  ev.JD_Jets().size(); i++){
    if(ev.JD_Jets()[i].Et() > JetThreshold_ && fabs(ev.JD_Jets()[i].Eta()) < 3.){
      newJets.push_back(ev.JD_Jets()[i]);
    }
  }
  for(unsigned int j = 0; j < newJets.size(); j++){
    if(newJets[j].Et() >= JetThreshold_){HT += newJets[j].Et();}
    if(newJets[j].Et() >= MhtThreshold_){
      MHTx-=newJets[j].Et()*cos(newJets[j].Phi());
      MHTy-=newJets[j].Et()*sin(newJets[j].Phi());
    }
  }
  double  MHT = sqrt(MHTx*MHTx + MHTy*MHTy);

  if(MHT + HT  > cut_){return true;}

  return false;

}


std::ostream& MeffTriggerCut::Description( std::ostream &ostrm ) {
  ostrm << "MeffTriggerCut " << cut_ << " " << " Jet Scale: " <<JetThreshold_ ;
  return ostrm;
}



HtTriggerCut::HtTriggerCut( float cut, float JetThreshold)
  : cut_(cut),
  JetThreshold_(JetThreshold)
  {;}
bool HtTriggerCut::Process( Event::Data& ev){
  double  HT =0.;

  vector<Event::Jet> newJets;
  newJets.clear();
  for(unsigned int i = 0; i <  ev.JD_Jets().size(); i++){
    if(ev.JD_Jets()[i].Et() > JetThreshold_ && fabs(ev.JD_Jets()[i].Eta()) < 3.){
      newJets.push_back(ev.JD_Jets()[i]);
    }
  }
  for(unsigned int j = 0; j < newJets.size(); j++){
    if(newJets[j].Et() >= JetThreshold_){HT += newJets[j].Et();}
  }

  if(HT  > cut_){return true;}

  return false;

}


std::ostream& HtTriggerCut::Description( std::ostream &ostrm ) {
  ostrm << "HtTriggerCut " << cut_ << " " << " Jet Scale: " <<JetThreshold_ ;
  return ostrm;
}


