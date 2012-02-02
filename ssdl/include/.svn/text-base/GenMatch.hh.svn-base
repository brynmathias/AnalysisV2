#ifndef GenMatch_hh
#define GenMatch_hh

#include "GenObject.hh"
#include "Lepton.hh"
#include "EventData.hh"

#include "Math/VectorUtil.h"
namespace Alex{

  struct GenOrigin{
    enum LeptSource{
      Fake, HF, Prompt
    };
  };

    struct GenMatch{
      enum LeptonType{
	Fake, Photon, HeavyFlavour, Susy, W, Z, Tau,
	Other, VirtualBoson, Meson, Unknown
      };
      
    };
    
    struct GenMatchedLepton{
      const Event::GenObject* match;
      GenMatchedLepton(const Event::GenObject* gen):
	match(gen){}
      
      GenMatch::LeptonType Type(){

	if(match == 0) return GenMatch::Fake;
	else if(abs(match->GetID()) == 22) return GenMatch::Photon;

	int mother = abs(match->GetMotherID());

	if(mother > 99 && mother < 1000000) return GenMatch::HeavyFlavour;
	if(mother > 999999) return GenMatch::Susy;
	if(mother == 24 || mother == 6) return GenMatch::W;
	if(mother == 23) return GenMatch::Z;
	if(mother == 15) return GenMatch::Tau;
	if(mother > 24 && mother < 43) return GenMatch::Other;
	if( (mother > 0 && mother < 6) || mother == 21) return GenMatch::VirtualBoson;
	if(mother == 111 || mother == 130 || mother == 211 || mother == 311
	   || mother == 321 || mother == 310 || mother == 313 || mother == 323)
	  return GenMatch::Meson;
	return GenMatch::Unknown;
      }

      GenOrigin::LeptSource Source(){
	GenMatch::LeptonType t = Type();
	if (t == GenMatch::Fake || t == GenMatch::Photon || t == GenMatch::Unknown) return GenOrigin::Fake;
	if (t == GenMatch::HeavyFlavour || t == GenMatch::Meson) return GenOrigin::HF;
	else return GenOrigin::Prompt;
      }

    };
    
    struct LeptonMatch{
      
      LeptonMatch(double max_delta_r = 0.5):
	mEv(0),
	mMaxDeltaR(max_delta_r)
      {}
      
      LeptonMatch(Event::Data & ev, double max_delta_r = 0.5):
	mEv(&ev),
	mMaxDeltaR(max_delta_r)
      {}
      
      pair<GenMatchedLepton,bool> operator()(const Event::Lepton* lep){
	double best_delta_r = -1;
	const Event::GenObject* match = 0;
	const Event::GenObject* photon = 0;
	std::vector<Event::GenObject>::const_iterator gen
	  = mEv->GenParticles().begin();
	std::vector<Event::GenObject>::const_iterator end
	  = mEv->GenParticles().end();
        bool CHOK=true;
	for( ; gen != end; ++gen){
	  int gen_id = abs(gen->GetID());
	  if(gen->GetStatus() != 1 && (gen_id==11 || gen_id==13)) continue;//added the gen requirment
	  if(gen->GetStatus() != 2 && (gen_id==15)) continue; 
	  if(!(gen_id == 11 || gen_id == 13 || gen_id == 22 || gen_id == 15)) continue;
	  //add options for taus
	  double dr = ROOT::Math::VectorUtil::DeltaR(*lep, *gen);
	  if(dr > mMaxDeltaR) continue;

	  switch(lep->GetType()){
	  case 1:
	    if(gen_id == 11){
	      if(!match || dr < best_delta_r){
		best_delta_r = dr;
		match = &(*gen);
		
	      }
	    }
	    else if(gen_id == 22){
	  photon = &(*gen);
	    }
	    break;
	  case 2:
	    if(gen_id == 13 && (!match || dr < best_delta_r)){
	      best_delta_r = dr;
	      match = &(*gen);
	    }
	    break;
	  case 3:
	    if (gen_id == 15 && (!match || dr < best_delta_r)){
	      best_delta_r = dr;
	      match = &(*gen);
	    }
	    break;
	  }
	}
	if(match == 0 ){
	  if (photon)
	    return make_pair(GenMatchedLepton(photon),CHOK);
	  else return make_pair(GenMatchedLepton(0),CHOK);
	}
	else{
	  if (match->GetID()*lep->GetCharge()>0) CHOK=false;
	  int mother = abs(match->GetMotherID());
	  int genid=abs(match->GetID());
	  if (mother==genid && match->GetMother()>0){
	    match=&(mEv->GenParticles()[match->GetMother()]);
	    if (mother==match->GetID() && match->GetMother()>0){
	      match=&(mEv->GenParticles()[match->GetMother()]);
	    }
	  }
	  mother = abs(match->GetMotherID());
	  if (mother==15 &&(genid==11 || genid==13)){
	    match=&(mEv->GenParticles()[match->GetMother()]);
	  }
	  return make_pair(GenMatchedLepton(match),CHOK);
	}
      }
      
    private:
      const Event::Data  *mEv;
      double mMaxDeltaR;
      
    };
    
    
    
  }
#endif
    
