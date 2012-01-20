/*! \file Compute_Variable.hh
 * \brief Header file for the compute variable template
 */

#ifndef COMPUTE_USER_HH
#define COMPUTE_USER_HH

#include "NtupleData.hh"
#include <stdexcept>
#include "Lepton.hh"
#include "Jet.hh"
#include "Photon.hh"
#include "GenObject.hh"

namespace Event {
  class Data;
}

#define COMPUTE_VALIDATION // Validation of computation (throws exception if update not called)
#define AUTO_UPDATE // Automatically update variables on-demand (high overhead)

/*! \brief Namespace for all compute-related code.
 */
namespace Compute {

class UserBase{
 protected:
  Event::Data * mEv;
 public:
  virtual ~UserBase();

  void Init(Event::Data &ev);
  virtual std::ostream & Description(std::ostream & ostrm)=0;

  UserBase();
};

std::ostream& operator << (std::ostream& ostrm, UserBase& m);

template<typename T, class X>
class User : public UserBase{
  public:
    User() :
        UserBase(),
      mCurrentEntry(-1) {}


#ifndef AUTO_UPDATE
    void Update() const {
      static_cast<const X &>(*this)._Update();
      mCurrentEntry = static_cast<const NtupleData&>(*mEv).GetCurrentEntry();
    }
#endif

    // To avoid a circular Event::Data reference (the computables can be recursive)
    // we keep any functionality directly references in the variable class
    // as cast to the NtupleData structure, which keeps track of basic file
    // access and reference counting
    const T & operator() () const {
#ifdef AUTO_UPDATE
      if ( static_cast<const Event::NtupleData&>(*mEv).GetCurrentEntry() != mCurrentEntry ) {
	// We need to update the code, so we use the Barton-Nackman trick
	// to pass update using a statically-polymorphic structure
	//std::cout << "Compute::Variable updated" << std::endl;
	static_cast<const X &>(*this)._Update();
	mCurrentEntry = static_cast<const Event::NtupleData&>(*mEv).GetCurrentEntry();
      }
#endif

#ifdef COMPUTE_VALIDATION
      if ( static_cast<const Event::NtupleData&>(*mEv).GetCurrentEntry() != mCurrentEntry ) {
	throw std::runtime_error("Compute validation failed");
      }
#endif

      // else {
      //std::cout << "Compute::Variable not update" << std::endl;
      //}
      // Return a const reference to the internal data member
      return mData;
    }

 private:
    mutable unsigned int mCurrentEntry;
  protected:
    mutable T mData;
  };

/* Compute::Generic class
 *
 * This class inherits from Compute::User. It provides a Generic
 * collection/variable for a given variable type. The variable is
 * updated by overriding the __Update and __Description virtual methods
 * in descendent classes. The benefit of this is that code may use the
 * collection as Compute::Generic<T> (where T=std::vector<Event::Lepton const *>
 * for example). The user code will be independent of the actual collection class used.
 */
template<typename ObjType>
class Generic : public Compute::User<ObjType, Generic<ObjType> >{
 public:
  Generic() :
      Compute::User<ObjType, Generic<ObjType> >()
  {}

  virtual ~Generic(){}

  void _Update() const {
    __Update();
  }

  virtual void __Update() const{
    throw std::invalid_argument("You have not overridden the __Update method for a Generic collection.");
  }

  virtual std::ostream & __Description(std::ostream & ostrm){
    throw std::invalid_argument("You have not overridden the __Description method for a Generic collection.");
  }

  std::ostream & Description(std::ostream & ostrm){
    return  __Description(ostrm);
  }
};


} // ~namespace Compute

typedef Compute::Generic<std::vector<Event::Lepton const *> > GenericLeptons;
typedef Compute::Generic<std::vector<Event::Jet const * > > GenericJets;
typedef Compute::Generic<std::vector<Event::Photon const *> > GenericPhotons;
typedef Compute::Generic<std::vector<ICF_LorentzV const *> > GenericLorentzVs;
typedef Compute::Generic<std::vector<Event::GenObject const *> > GenericGenObjects;
typedef Compute::Generic<ICF_LorentzV> GenericLorentzV;


#endif //~COMPUTE_VARIABLE_HH
