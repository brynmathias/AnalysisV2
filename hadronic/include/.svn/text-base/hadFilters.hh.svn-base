#include "Jet.hh"
#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "TRandom3.h"
namespace Event {

/*
A class to add a defined amount of energy to all common Jets
*/
class AddJetEnergy : public Compute::ObjectFilter<Event::Jet>
{
public:
  AddJetEnergy (double plusVal):
  plusVal_(plusVal)

  {
    mModifies = true;
  }
  ~AddJetEnergy(){}
  bool Apply( Event::Jet* ob){
    if(!ob) return true;
    //Get The object PT and find what 1GeV is as a percentage.

    // std::cout << "Object Pt = " << ob->Pt() << " 1 / obj Pt = " << 1./ob->Pt() << " So direct additon gives"  << ob->Pt() + plusVal_ << std::endl;
      *ob *= (1. + (plusVal_/ob->Pt()));
    // std::cout<< "Multiplicitave factor gives: " << ob->Pt() << std::endl;
    return true;
  }

  std::ostream & Description(std::ostream & ostrm) {
    ostrm << "Jets have had " << plusVal_ << " Added.";
    return ostrm;
  }


private:
  double plusVal_;
  /* data */
};


/*
Class to add a massless jet to the standard object, this should add no mass
*/

// class AddMassLessJet : public Compute::ObjectFilter<Event::Jet>
// {
// public:
//  AddMassLessJet (double masslessEnergy):
//  mlEn_(masslessEnergy)
//  {
//    mModifies = true;
//  }
//  ~AddMassLessJet (){}
//  bool Apply( Event::Jet* on){
//    if(!ob) return true;
//    TLorentzVector masslessJet(0.,0.,0.,0.);
//    masslessJet.SetPxPyPzE(px,py,pz,mlEn_)
//
//
//  }
//
//
//
// private:
//  /* data */
//  double mlEn_;
// };

}
