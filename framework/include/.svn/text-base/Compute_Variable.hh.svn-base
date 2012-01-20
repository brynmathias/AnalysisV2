/*! \file Compute_Variable.hh
 * \brief Header file for the compute variable template
 */

#ifndef COMPUTE_VARIABLE_HH
#define COMPUTE_VARIABLE_HH

#include "NtupleData.hh"
#include <stdexcept>

namespace Event {
  class Data;
}

#define COMPUTE_VALIDATION // Validation of computation (throws exception if update not called)
#define AUTO_UPDATE // Automatically update variables on-demand (high overhead)

/*! \brief Namespace for all compute-related code.
 */
namespace Compute {


template<typename T, class X,class Y=Event::Data>
class Variable {
  public:
    Variable(const Y & ev) :
      mEv(ev),
      mCurrentEntry(-1) {}

#ifndef AUTO_UPDATE
    void Update() const {
      static_cast<const X &>(*this)._Update();
      mCurrentEntry = static_cast<const NtupleData &>(mEv).GetCurrentEntry();
    }
#endif

    // To avoid a circular Event::Data reference (the computables can be recursive)
    // we keep any functionality directly references in the variable class
    // as cast to the NtupleData structure, which keeps track of basic file
    // access and reference counting
    const T & operator() () const {
#ifdef AUTO_UPDATE
      if ( static_cast<const Event::NtupleData &>(mEv).GetCurrentEntry() != mCurrentEntry ) {
	// We need to update the code, so we use the Barton-Nackman trick
	// to pass update using a statically-polymorphic structure
	//std::cout << "Compute::Variable updated" << std::endl;
	static_cast<const X &>(*this)._Update();
	mCurrentEntry = static_cast<const Event::NtupleData &>(mEv).GetCurrentEntry();
      }
#endif

#ifdef COMPUTE_VALIDATION
      if ( static_cast<const Event::NtupleData &>(mEv).GetCurrentEntry() != mCurrentEntry ) {
	throw std::runtime_error("Compute validation failed");
      }
#endif

      // else {
      //std::cout << "Compute::Variable not update" << std::endl;
      //}
      // Return a const reference to the internal data member
      return mData;
    }

  protected:
    const Y & mEv;
  private:
    mutable unsigned int mCurrentEntry;
  protected:
    mutable T mData;
  };

} // ~namespace Compute

#endif //~COMPUTE_VARIABLE_HH
