#ifndef ONELEPTON_HH
#define ONELEPTON_HH

#include <string>
#include <stdexcept>
#include "Math/VectorUtil.h"

namespace OneLepton{

enum LeptonType{
  ONELEPTON_MUON=2,
  ONELEPTON_ELECTRON=1
};

enum MCLeptonType{
  ONELEPTON_MC_HF=10,
  ONELEPTON_MC_FAKE=-1,
  ONELEPTON_MC_PHOTON=22
};

inline LeptonType GetLeptonType(const std::string & str){
  if(str=="Muon")
    return ONELEPTON_MUON;
  else if(str=="Electron")
    return ONELEPTON_ELECTRON;
  else throw std::invalid_argument("Bad lepton type string");
}

}

#endif
