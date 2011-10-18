/*! \file GenObject.cc
 * \brief Source code for the (simple!) Event::GenObject physics object class.
 */

#include "GenObject.hh"

namespace Event {
  
  GenObject::GenObject(Double_t px,
		       Double_t py,
		       Double_t pz,
		       Double_t E,
		       Int_t index,
		       Int_t pid,
		       Int_t mother,
		       Int_t stat) :
    LorentzV(px, py, pz, E),
    mIndex(index),
    mID(pid),
    mMother(mother),
    mStatus(stat)
  {}
  
  GenObject::~GenObject() {}

  Int_t GenObject::GetIndex() const { return mIndex; }
  Int_t GenObject::GetID() const { return mID; }
  Int_t GenObject::GetMother() const { return mMother;}
  Int_t GenObject::GetStatus() const { return mStatus;}
  Int_t GenObject::GetMotherID() const {return mMotherID;}
  bool GenObject::GetHasMother() const {return mMotherStored;}
    //  if(genMotherStored(mIndex)) {return  (mEv.GenParticles() )[mMother]->GetID();}
    //    else {return mMother;}
  

} // ~Event

std::ostream& operator<< ( std::ostream& os, const Event::GenObject& input ) {
  std::stringstream ss;
  ss  << "[Event::GenObject] "
      << " Index, ID, Mother, Status: "
      << input.GetIndex() << ", "
      << input.GetID() << ", "
      << input.GetMother() << ", "
      << input.GetStatus();
  ss  << std::endl
      << " Px/Py/Pz/E     : "
      << std::setprecision(8) << input.Px() << "/"
      << std::setprecision(8) << input.Py() << "/"
      << std::setprecision(8) << input.Pz() << "/"
      << std::setprecision(8) << input.E() << std::endl
      << " Pt/Et          : "
      << std::setprecision(8) << input.Pt() << "/"
      << std::setprecision(8) << input.Et() << std::endl
      << " eta/phi        : "
      << std::setprecision(8) << input.Eta() << "/"
      << std::setprecision(8) << input.Phi() << std::endl;
  os << ss.str();
  return os;
}
