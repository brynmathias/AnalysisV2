#ifndef WPOL_HH
#define WPOL_HH
#include <string>
#include <stdexcept>
#include "Math/VectorUtil.h"

namespace WPol{
enum LeptonType{
  WPOL_MUON=2,
  WPOL_ELECTRON=1
};

enum MCLeptonType{
  WPOL_MC_HF=10,
  WPOL_MC_FAKE=-1,
  WPOL_MC_PHOTON=22
};

inline LeptonType GetLeptonType(const std::string & str){
  if(str=="Muon")
    return WPOL_MUON;
  else if(str=="Electron")
    return WPOL_ELECTRON;
  else throw std::invalid_argument("Bad lepton type string");
}

inline const std::string GetLeptonString(LeptonType lt){
  switch(lt){
    case WPOL_MUON:
      return "Muon";
    case WPOL_ELECTRON:
      return "Electron";
    default:
      throw std::invalid_argument("Invalid Lepton Type");
  }
}

inline MCLeptonType GetMCLeptonType(const std::string & str){
  if(str=="HF") return WPOL_MC_HF;
  else if(str=="Fake") return WPOL_MC_FAKE;
  else if(str=="Photon") return WPOL_MC_PHOTON;
  else throw std::invalid_argument("Invalid MC type specified");
}

inline const std::string GetMCLeptonString(MCLeptonType t){
  switch(t){
    case WPOL_MC_HF:
      return "HF";
    case WPOL_MC_FAKE:
      return "Fake";
    case WPOL_MC_PHOTON:
      return "Photon";
    default:
      throw std::invalid_argument("Invalid MC type");
  }
}

inline const Event::Lepton* GetLeadingLepton(Event::Data & ev,
                                      LeptonType lep_type){
  switch(lep_type){
    case WPOL_MUON:
      if (ev.LD_CommonMuons().accepted.size()==0) return 0;
      else return ev.LD_CommonMuons().accepted[0];
    case WPOL_ELECTRON:
      if (ev.LD_CommonElectrons().accepted.size()==0) return 0;
      else return ev.LD_CommonElectrons().accepted[0];
    default:
      throw std::invalid_argument("Lepton type value not supported");
  }
}

inline const std::vector<Event::Lepton> & GetRawLeptons(Event::Data &ev,
  LeptonType lep_type){
  switch(lep_type){
    case WPOL_MUON:
      return ev.LD_Muons();
    case WPOL_ELECTRON:
      return ev.LD_Electrons();
    default:
      throw std::invalid_argument("Lepton type value not supported");
  }
}

inline const std::vector<const Event::Lepton*> &
GetCommonLeptons(Event::Data &ev,
                 LeptonType lep_type){
  switch(lep_type){
    case WPOL_MUON:
      return ev.LD_CommonMuons().accepted;
    case WPOL_ELECTRON:
      return ev.LD_CommonElectrons().accepted;
    default:
      throw std::invalid_argument("Lepton type value not supported");
  }
}

inline int ExtendedType(Event::Data &ev,const LorentzV*  vec,int ltype){
  int iMatch=ev.leptonMatch(vec,ltype);
  if(iMatch>=0) return ev.leptonType(iMatch);
  else{
    double dRmin=-1;
    bool pt_match=false;
    for(std::vector<Event::GenObject>::const_iterator ii=ev.GenParticles().begin();
        ii!=ev.GenParticles().end();++ii){
      if(fabs(ii->GetID()) == 22){
        double dPtoverPt = fabs(ii->Pt() - vec->Pt())/ii->Pt();
        double dR=ROOT::Math::VectorUtil::DeltaR(*ii,*vec);
        if ( dR < dRmin || dRmin<0){
          pt_match=(fabs(dPtoverPt) < 0.3);
          dRmin=dR;
        }
      }
    }
    if(dRmin<0.5 && dRmin>=0) return pt_match ? 22 : -22;
  }
  return -1;
}

}
#endif
