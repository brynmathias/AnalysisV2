#include "Ops.hh"
#include "AlphaT.hh"
#include <iostream>
#include <string>
#include <fstream>
#include "vector"
#include "Types.hh"

using namespace Operation;

// ----------------------------------------------------------------
AlphatTriggerCut::AlphatTriggerCut( float cut, float SecondJet, float JetThreshold, float MhtJetThreshold)
  : cut_(cut),
  SecondJet_(SecondJet),
  JetThreshold_(JetThreshold),
  MhtThreshold_(MhtJetThreshold)
  {;}
// ----------------------------------------------------------------
bool AlphatTriggerCut::Process( Event::Data& ev){
  int nJets = 0;
  double MHTx = 0.;
  double MHTy = 0.;
  double CoMHTx = 0.;
  double CoMHTy = 0.;
  vector<Event::Jet> newJets;
  newJets.clear();


  for(unsigned int i = 0; i <  ev.JD_Jets().size(); i++){
    // cout  << " For Jet " << i << " Pt is "<< ev.JD_Jets()[i].Pt() << "   Eta is:  " <<  fabs(ev.JD_Jets()[i].Eta()) << endl;
    if(ev.JD_Jets()[i].Pt() > JetThreshold_ && fabs(ev.JD_Jets()[i].Eta()) < 3.){
      newJets.push_back(ev.JD_Jets()[i]);
      nJets++;
    }
  }

  for(unsigned int i = 0; i < newJets.size(); i++){
    CoMHTx-=ev.JD_CommonJets().accepted[i]->Et()*cos(ev.JD_CommonJets().accepted[i]->Phi());
    CoMHTy-=ev.JD_CommonJets().accepted[i]->Et()*sin(ev.JD_CommonJets().accepted[i]->Phi());
  }


  if(newJets[1].Pt() < SecondJet_){ return false;}
  if( nJets == 2){
    double   HT = newJets[0].Et() + newJets[1].Et();
    for(int i = 0 ; i < 2; i++){
      if(ev.JD_Jets()[i].Et() > MhtThreshold_){
        MHTx-=newJets[i].Et()*cos(newJets[i].Phi());
        MHTy-=newJets[i].Et()*sin(newJets[i].Phi());
      }
    }
    double  MHT = sqrt(MHTx*MHTx + MHTy*MHTy);
    double  DHT = fabs(newJets[0].Et() - newJets[1].Et());
    if((HT-DHT)/(2.*sqrt((HT*HT) - (MHT*MHT))) > cut_ ){
      return true;}
      else{
        // cout <<"This event has on the fly alphaT of: " << (HT-DHT)/(2.*sqrt(HT*HT - (MHT*MHT)))  << " and alphaT of " << ev.CommonAlphaT() << " and MHT/HT of " <<sqrt(CoMHTy*CoMHTy + CoMHTx*CoMHTx)/ev.CommonHT() << "  MHT of (trig:Ana): "<<MHT << ": " << sqrt(CoMHTy*CoMHTy + CoMHTx*CoMHTx)  << " HT of(Trig:Ana): " <<HT << " : " << ev.CommonHT() <<endl;
        // cout << "The number of Jets in common jets is:" << ev.JD_CommonJets().accepted.size() << " Number of jets is " << nJets << endl;
        // for(int i =0; i < newJets.size(); i++){
          // cout  << " For Jet " << i << " Pt is "<< newJets[i].Et() << "   Eta is:  " <<  fabs(newJets[i].Eta()) << endl;
        // }

        return false;
      }
    }
    if( nJets > 2){
      double  HT =0.;
      for(unsigned int j = 0; j < newJets.size(); j++){
        if(newJets[j].Et() >= JetThreshold_){HT += newJets[j].Et();}
        if(newJets[j].Et() >= MhtThreshold_){
          MHTx-=newJets[j].Et()*cos(newJets[j].Phi());
          MHTy-=newJets[j].Et()*sin(newJets[j].Phi());
        }
      }
      double  MHT = sqrt(MHTx*MHTx + MHTy*MHTy);
      // cout <<"This event has on the fly MHT/HT of: " << fabs(MHT)/HT << " Event MHT/HT of: " << fabs(ev.CommonMHT().Et())/ev.CommonHT() <<" and alphaT of " << ev.CommonAlphaT() << endl;
      if(fabs(MHT)/HT > sqrt(1. - 1./(4.*cut_*cut_))){
        // cout <<"This event has MHT/HT of: " << MHT/HT << " and alphaT of " << ev.CommonAlphaT() << endl;
        return true;
      }
      else{
        // cout <<"This event has MHT/HT of: " << MHT/HT << " and MHT/HT of " <<sqrt(CoMHTy*CoMHTy + CoMHTx*CoMHTx)/ev.CommonHT() << "  MHT of (trig:Ana): "<<MHT << ": " << sqrt(CoMHTy*CoMHTy + CoMHTx*CoMHTx)  << " HT of(Trig:Ana): " <<HT << " : " << ev.CommonHT() <<endl;
        // cout << "The number of Jets in common jets is:" << ev.JD_CommonJets().accepted.size() << " Number of jets is " << nJets << endl;
        // for(int i =0; i < newJets.size(); i++){
          // cout  << " For Jet " << i << " Pt is "<< newJets[i].Et() << "   Eta is:  " <<  fabs(newJets[i].Eta()) << endl;
        // }

        return false;
      }
    }
    return false;
  }

  std::ostream& AlphatTriggerCut::Description( std::ostream &ostrm ) {
    ostrm << "AlphatTriggerCut " << cut_ << " " << " Jet Scale: " <<JetThreshold_ ;
    return ostrm;
  }
