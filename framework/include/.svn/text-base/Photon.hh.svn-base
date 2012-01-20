/*!\file Photon.hh
 * \brief Header file for the EventStuff::Photon physics object class.
 */

#ifndef Photon_hh
#define Photon_hh

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Types.hh"
namespace Event {

  /*! \brief A very simple photon container.
   *
   * \author Rob Bainbridge
   * \author Tom Whyntie
   * \date February 2009
   * \version 1.1
   *
   * \todo Work out what's needed for photonic studies and implement in the code.
   * \todo Does the gen. photon information need to be stored in the ntuple? It isn't at the moment (19/02/2009).
   */
  class Photon : public LorentzV {

  public:

    Photon(const LorentzV& v, double ecalRecHitSumEtConeDR04, double hcalTowerSumEtConeDR04, double trkSumPtHollowConeDR04,
      double hadronicOverEm, bool hasPixelSeed, double r9, double superClusterEnergy, double sigmaIetaIeta, int index);

    ~Photon(); //!< Destructor.

    // Public data access
    //--------------------
    Double_t GetTrackIsolation() const; //!< Returns the track isolation of the object.
    Double_t GetEcalIsolation() const; //!< Returns the ECAL isolation of the object.
    Double_t GetHcalIsolation() const; //!< Returns the HCAL isolation of the object.
    Double_t GetCaloIsolation() const; //!< Returns the HCAL isolation of the object.

    Double_t ecalRecHitSumEtConeDR04() const;
    Double_t hcalTowerSumEtConeDR04() const;
    Double_t trkSumPtHollowConeDR04() const;
    Double_t hadronicOverEm() const;
    Bool_t hasPixelSeed() const;
    Double_t r9() const;
    Double_t superClusterEnergy() const;
    Double_t sigmaIetaIeta() const;

    Int_t GetIndex() const; //!< Returns the index of the object in the original ntuple.
    void SetMatched(Bool_t matched); //!< Set whether the photon was matched to a gen photon or not.
    Bool_t WasItMatched() const; //!< Returns flag: true = was matched to a generated particle.
    void SetMatchedGenIndex(Int_t index); //!< Set the index of the matched gen photon (-1 is no match).
    Int_t GetGenIndex() const; //!< Returns the index of the matched gen photon in the ntuple collection (-1 no match).

    const char * GetID() const;
    UInt_t GetIntID() const;
    Bool_t IsItLoose() const;   //!< Check if the photon has been IDed as "Loose".
    Bool_t IsItTight() const;   //!< Check if the photon has been IDed as "Tight".
    Bool_t IsItLooseEM() const; //!< Check if the photon has been IDed as "LooseEM" ???

    void SetIntID(int);

    inline void SetLooseId(Bool_t newval) { mLoose = newval; }
    inline void SetTightId(Bool_t newval) { mTight = newval; }

  private:
    // Private data members
    //----------------------
    // Isolation.
    Double_t mEcalRecHitSumEtConeDR04;
    Double_t mHcalTowerSumEtConeDR04;
    Double_t mTrkSumPtHollowConeDR04;
    Double_t mHadronicOverEm;
    Double_t mHasPixelSeed;
    Double_t mR9;
    Double_t mSuperClusterEnergy;
    Double_t mSigmaIetaIeta;
    Int_t  mIndex;    //!< Index of the photon in the ntuple.
    Bool_t mMatched;  //!< Flag: True = photon matched to a generated photon.
    Int_t gen_index_; //!< The index of the gen photon in the genparticles ntuple collection (-1 no match).
    Bool_t mCc;       //!< Flag: True = photon associated with a cross-cleaned photon.
    Bool_t mTight;   //!< Flag: True = IDed as a "tight photon".
    Bool_t mLoose;   //!< Flag: True = IDed as a "loose photon".
    Bool_t mLooseEM; //!< Flag: True = IDed as a "Loose EM" object.

  }; //~class Photon

} //~namespace Event

std::ostream& operator<< ( std::ostream&, const Event::Photon& );

#endif //~Photon_hh
