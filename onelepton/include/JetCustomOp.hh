#include "Operation.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "Lepton.hh"
//#include "GenMuons.hh"

#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"

namespace OneLepton {

class EleJetSeparation : public Compute::ObjectFilter<Event::Jet>{
 public:
  EleJetSeparation(double drCut):
    mDRCut(drCut) { mModifies=false;}

  ~EleJetSeparation(){}

  bool Apply(const Event::Jet* ob){
    
    double dRmin=9999.;

    if (mEv->LD_CommonElectrons().accepted.size()>0) {
      dRmin=fabs(ROOT::Math::VectorUtil::DeltaR ((*ob),*(mEv->LD_CommonElectrons().accepted.at(0))));
    }
    return (dRmin > mDRCut );
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Custom DR(e-jet) Cut > "<< mDRCut;
    return ostrm;
  }

 private:
  double mDRCut;
};


class JetCustomOp : public Operation::_Base {
  public:
  JetCustomOp(){}
  ~JetCustomOp(){}
  bool Process(Event::Data & ev){
    return true;
  }
  std::ostream& Description(std::ostream& ostrm){
    ostrm << "JetCustom Op" << std::endl;
    return ostrm;
  }
};
}
