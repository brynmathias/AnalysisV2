#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
namespace lepval {

  //Taken from SSDL code - could also just include that
  //Corrected D0 Filter

  class LeptonD0Filter : public Compute::ObjectFilter<Event::Lepton>{
  public:
    LeptonD0Filter(double d0Cut, double X, double Y):
      mD0Cut(d0Cut),
      mX(X),
      mY(Y){
      mModifies=false;}
    
    ~LeptonD0Filter(){}
    
    bool Apply(const Event::Lepton* ob){
 			  
      float d0=(ob->GetType()==2) ? mEv->GetMuonCombD0(ob->GetIndex()) : 
 	mEv->GetElectronD0(ob->GetIndex());

      double corrD0 = fabs(d0 - mX*sin(ob->Phi())+mY*cos(ob->Phi()));
      return (corrD0 < mD0Cut);

    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "D0 Cut  "<< mD0Cut;
      return ostrm;
    }
    
  private:
    double mD0Cut;
    double mX;
    double mY;
  };
}
