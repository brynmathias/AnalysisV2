#include "Utils.hh"
#include "Math/VectorUtil.h"


using namespace Operation; // For wpol stuff

namespace OneLepton{


   class PFJetIDLoose : public Compute::ObjectFilter<Event::Jet>{
   public:
     PFJetIDLoose()
     { mModifies=false;}

      ~PFJetIDLoose(){}

      bool Apply(const Event::Jet* ob){

	if (
	    (mEv->jetPFJetIDLoose()->at(ob->GetIndex()) > 0) &&
	    ((ob)->Pt()>=30.) &&
	    (fabs((ob)->Eta())<=2.4)
	    ) { return true; }

	else return false;
      }

      std::ostream & Description(std::ostream & ostrm){
         ostrm << "Jet Filter ";
         return ostrm;
      }

   private:
   };


}
