/*!\file Lepton.hh
 * \brief Header file for the EventStuff::Lepton physics object class.
 *
 */

#ifndef Lepton_hh
#define Lepton_hh

#include "Types.hh"
#include "Utils.hh"
#include <TMath.h>
namespace Event {

  /*! \brief A very simple lepton container.
   *
   * \author Georgia Karapostoli
   * \author Tom Whyntie
   * \date February 2009
   * \version 1.1
   *
   * \todo Add taus (type = 3?) to the lepton class. Inheritence?
   */
  class Lepton : public LorentzV {

  public:

    /**
     * \brief Constructor.
     *
     * \param px Momentum x component.
     * \param py Momentum y component.
     * \param pz Momentum z component.
     * \param E Energy.
     * \param charge Charge of the lepton.
     * \param trkIso The "track isolation" of the lepton.
     * \param type Type of lepton: 1=> electron, 2=> muon.
     * \param index Index of the lepton in the original ntuple array.
     * \param match Whether or not matched to a generated lepton.
     * \param [in] cc Whether or not matched to a cross-cleaned lepton.
     */
    Lepton(Double_t px, Double_t py, Double_t pz, Double_t E,
     Double_t charge, Double_t trkIso, Double_t ecalIso, Double_t hcalIso,
     Bool_t looseID, Bool_t tightID,
     Int_t type, Int_t index, Bool_t match, Bool_t cc);

    // ICF constructor
    Lepton(const LorentzV& vec,
           Double_t charge,
           Double_t trkIso,
           Double_t ecalIso,
           Double_t hcalIso,
           Bool_t looseId,
           Bool_t tightId,
           int type,
           int index) :
        LorentzV(vec),
        mCharge(charge),
        mTrkIso(trkIso),
        mEcalIso(ecalIso),
        mHcalIso(hcalIso),
        mLooseId(looseId),
        mTightId(tightId),
        mType(type),
        mIndex(index),
        mCC(true)
    {}

    /* Convenience method for python testing */
    Lepton(double px,
           double py,
           double pz,
           double E,
           double charge,
           double trkIso,
           double ecalIso,
           double hcalIso,
           bool looseId,
           bool tightId,
           int type,
           int index) :
        LorentzV(px,py,pz,E),
        mCharge(charge),
        mTrkIso(trkIso),
        mEcalIso(ecalIso),
        mHcalIso(hcalIso),
        mLooseId(looseId),
        mTightId(tightId),
        mType(type),
        mIndex(index),
        mCC(true)
    {}
    /**
     * \brief Destructor.
     */
    ~Lepton();

    // Public data access
    //--------------------

    /**
     * \brief Returns the charge of the object.
     */
    Double_t GetCharge() const;

    /**
     * \brief Returns the track isolation of the object.
     */
    Double_t GetTrkIsolation() const;
    Double_t GetEcalIsolation() const;
    Double_t GetHcalIsolation() const;
    Double_t GetCombIsolation() const;

     /**
     * \brief Returns true if the lepton passes loose ID cuts.
     */
    Bool_t GetLooseId() const;
    Bool_t GetTightId() const;
    /**
     * \brief Returns the index of the object in the original ntuple.
     *
     * \return The index of the lepton in the original ntuple.
     */
    Int_t GetIndex() const;

    /**
     * \brief Returns the type of lepton.
     *
     * In Georgia's code, it's 1 for electrons, 2 for muons...
     */
    Int_t GetType() const;

    /**
     * \brief Returns flag: true = was matched to a generated particle.
     */
    Bool_t WasItMatched() const;
    /**
     * \brief Returns flag: true = was cross-cleaned.
     */

    inline void SetLooseId(Bool_t newval) { mLooseId = newval; }
    inline void SetTightId(Bool_t newval) { mTightId = newval; }

  private:
    // Private data members
    //----------------------
    Double_t mCharge; //!< Charge.
    Double_t mTrkIso; //!< Track isolation(???).
    Double_t mEcalIso;
    Double_t mHcalIso;
    Bool_t mLooseId;  //!< Flag: True = lepton passes loose ID criteria
    Bool_t mTightId;  //!< Flag: True = lepton passes tight ID criteria
    Int_t mType;      //!< Type of lepton: 1=>electron, 2=>muon.
    Int_t mIndex;     //!< Index of the lepton in the ntuple.
    Bool_t mMatched;  //!< Flag: True = lepton matched to a generated lepton.
    Bool_t mCC;       //!< Flag: True = lepton is cross-cleaned

  }; //~class Lepton

} //~namespace EventStuff

#endif //~Lepton_hh
