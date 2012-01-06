/** \file GenObject.hh
 * \brief Header file for the EventStuff::GenObject physics object container class.
 */

#ifndef GenObject_hh
#define GenObject_hh

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Types.hh"
namespace Event {

  /*! \brief Container class for MC generator objects.
   *
   * \author Georgia Karapostoli
   * \author Tom Whyntie
   * \date Feb 2009
   * \version 1.1
   */
  class GenObject : public LorentzV {

  public:

    /*! \brief Constructor.
     *
     * @param px [in] Momentum x component.
     * @param py [in] Momentum y component.
     * @param pz [in] Momentum z component.
     * @param E [in] Energy.
     * @param index [in] The index of the gen particle in the ntuple.
     * @param pid [in] PDG ID of the particle.
     * @param mother [in] Position in the ntuple array of the mother particle.
     * @param stat [in] The Pythia status of the particle.
     */

     GenObject(Double_t px, Double_t py, Double_t pz, Double_t E,
       Int_t index, Int_t pid, Int_t mother, Int_t stat);

    // AS: Temporarily added
    GenObject(LorentzV vec,
              int idx,
              int pid,
              int status,
              bool hasMother,
              bool motherStored,
              int mother,
	      int motherid
):
        LorentzV(vec),
        mIndex(idx),
        mID(pid),
	mMother(mother),
        mStatus(status),
        mHasMother(hasMother),
        mMotherStored(motherStored),
	mMotherID(motherid)
    {}
    /*! \brief Destructor.
     */
    ~GenObject();

    // Public data access
    //--------------------

    Int_t GetIndex() const; //!< Returns the index of the gen particle in the ntuple.

    /*! \brief Returns Particle PDG ID.
     */
    Int_t GetID() const;

    /*! \brief Returns the position of first Mother in the ntuple array.
     */
    Int_t GetMother() const ;

    /*! \brief Returns Particle status in PYTHIA listing
     */
    Int_t GetStatus() const;

    /*! \brief Returns PDG Id of mother
     */
    Int_t GetMotherID() const;

    bool GetHasMother() const;
  private:
    // Private data members
    //----------------------
    Int_t mIndex;  //!< Index in the ntuple.
    Int_t mID;     //!< Particle PDGid.
    Int_t mMother;  //!< Position of first Mother.
    Int_t mStatus;  //!< Particle status in PYTHIA listing
    bool mHasMother;
    bool mMotherStored;
    Int_t mMotherID;
  }; //~class Lepton

} // ~Event

std::ostream& operator<< ( std::ostream&, const Event::GenObject& );

#endif //~GenObject_hh
