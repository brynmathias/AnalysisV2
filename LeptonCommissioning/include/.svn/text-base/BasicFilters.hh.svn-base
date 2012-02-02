#include "Utils.hh"
#include "Math/VectorUtil.h"

#include "Operation.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "Lepton.hh"
#include "TLorentzVector.h"

namespace LeptonCommissioning {

inline int ExtendedType(Event::Data &ev,const LorentzV*  vec,int ltype){
  int iMatch=ev.leptonMatch(vec,ltype);
  if(iMatch>=0) return -999;//return ev.leptonType(iMatch);
  else{
    double dRmin=-1;
    bool pt_match=false;
    int pId=-1;
    for(std::vector<Event::GenObject>::const_iterator ii=ev.GenParticles().begin();
        ii!=ev.GenParticles().end();++ii){
      //      if(fabs(ii->GetID()) == 22){
      if (ii->GetStatus() != 1) continue;

      double dPtoverPt = fabs(ii->Pt() - vec->Pt())/ii->Pt();
      double dR=ROOT::Math::VectorUtil::DeltaR(*ii,*vec);
      if ( dR < dRmin || dRmin<0){
	pt_match=(fabs(dPtoverPt) < 0.3);
	dRmin=dR; pId=fabs(ii->GetID());
      }
    }
    
    if(dRmin<0.5 && dRmin>=0) return pId; 
				//pt_match ? 22 : -22;
  }
  return -1;
};

}
