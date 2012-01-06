#include "EventPicker.hh"
#include "SSDLSelection.hh"
#include <fstream>


using namespace Event;
namespace SSDL{

   bool compareLepPt(const Lepton *l1, const Lepton* l2) {
    return l1->Pt() > l2->Pt();
  }

   bool findEv( std::vector<int> runs, std::vector<int> lumis, std::vector<int> events, int run,
	       int lumi, int event){
    std::vector<int>::const_iterator r = runs.begin(), l = lumis.begin(), e = events.begin();
    
    for(; r != runs.end() && l != lumis.end() && e != events.end(); ++r, ++l, ++e){
      if(run == *r && lumi == *l && event == *e){
	return true;
	break;
      }
      else{
	return false;
      }
    }
  }


  SSDLEventPicker::SSDLEventPicker(const Utils::ParameterSet& pset){
    _Events = pset.Get<std::vector<int> >("Events");
    _Lumis = pset.Get<std::vector<int> >("Lumis");
    _Runs = pset.Get<std::vector<int> >("Runs");
  }

  void SSDLEventPicker::Start(Event::Data& ev){}

  SSDLEventPicker::~SSDLEventPicker(){}

  std::ostream& SSDLEventPicker::Description(std::ostream& ostrm){
    ostrm << "Running SSDL EventPicker";
    return ostrm;
  }



  bool SSDLEventPicker::Process(Event::Data& ev){
    
    std::vector<const Lepton *> AllLeptons;

     for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
   	lep!=ev.LD_CommonTaus().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }
    
    sort((AllLeptons).begin(), (AllLeptons).end(), compareLepPt);


    if(ev.GetIsData() && findEv(_Runs,_Lumis,_Events, ev.GetRunNumber(), ev.GetLumiSec(), ev.GetEventNumber())){
	  std::string lep_type1, lep_type2;
	  switch (AllLeptons[0]->GetType()){
	  case 1:
	    lep_type1="el";
	    break;
	  case 2:
	    lep_type1="mu";
	    break;
	  case 3:
	    lep_type1="tau";
	    break;
	  default:
	    lep_type1="unknown";
	  }
	  switch (AllLeptons[1]->GetType()){
	  case 1:
	    lep_type2="el";
	    break;
	  case 2:
	    lep_type2="mu";
	    break;
	  case 3:
	    lep_type2="tau";
	    break;
	  default:
	    lep_type2="unknown";
	  }
	  
	  
	  std::ofstream Out;
	  Out.open("pickedEvents.txt",ios::out|ios::app);
	  Out<<"RUN: "<<ev.GetRunNumber()<<"    "<<"LUMISEC: "<<ev.GetLumiSec()<<"    "<<"EVENT: "<<ev.GetEventNumber()<<endl;
	  Out<<"HT: "<<ev.CommonHT()<<endl;
	  Out<<"MHT: "<<ev.CommonMHT().pt()<<"   pfMET: "<<ev.PFMET().pt()<<endl;
	  Out<<"Invariant mass/type of two leading leptons: lepton1: "+lep_type1+" lepton2: "+lep_type2+" inv. mass: "<<(*AllLeptons[0]+*AllLeptons[1]).M()<<endl;
	  Out<<"===========The Jets=================="<<endl;
	  for(std::vector<Event::Jet const*>::const_iterator jet=ev.JD_CommonJets().accepted.begin(); jet!=ev.JD_CommonJets().accepted.end(); ++jet){
	    Out<<"Jet "<<jet-ev.JD_CommonJets().accepted.begin()<<":   pt: "<<(*jet)->Pt()<<" eta: "<<(*jet)->eta()<<" phi: "<<(*jet)->phi()<<endl;
	}
	  Out<<"===========The Electrons============"<<endl;
	  for(std::vector<Event::Lepton const *>::const_iterator el=ev.LD_CommonElectrons().accepted.begin(); el!=ev.LD_CommonElectrons().accepted.end(); ++el){
	    Out<<"Electron "<<el-ev.LD_CommonElectrons().accepted.begin()<<":   pt: "<<(*el)->pt()<<" eta: "<<(*el)->eta()<<" phi: "<<(*el)->phi()<<" charge: "<<(*el)->GetCharge()<<endl;
	  }
	  Out<<"===========The Muons============"<<endl;
	  for(std::vector<Event::Lepton const*>::const_iterator mu=ev.LD_CommonMuons().accepted.begin(); mu!=ev.LD_CommonMuons().accepted.end(); ++mu){
	    Out<<"Muon "<<mu-ev.LD_CommonMuons().accepted.begin()<<":   pt: "<<(*mu)->pt()<<" eta: "<<(*mu)->eta()<<" phi: "<<(*mu)->phi()<<" charge: "<<(*mu)->GetCharge()<<endl;
	  }
	  Out<<"===========The Taus============"<<endl;
	  for(std::vector<Event::Lepton const*>::const_iterator tau=ev.LD_CommonTaus().accepted.begin(); tau!=ev.LD_CommonTaus().accepted.end(); ++tau){
	    Out<<"Tau "<<tau-ev.LD_CommonTaus().accepted.begin()<<":   pt: "<<(*tau)->pt()<<" eta: "<<(*tau)->eta()<<" phi: "<<(*tau)->phi()<<" charge: "<<(*tau)->GetCharge()<<endl;
	    Out<<""<<endl;
	    Out<<""<<endl;
	  }
	  
	  return true;
	}

    return false;

  }
}
