/** \file Jet.hh
 * \brief Header file for the Event::Jet physics object container class.
 */

#ifndef Jet_hh
#define Jet_hh

#include "TLorentzVector.h"
#include "Types.hh"

namespace Event {

  /*! \brief A slightly less simple jet container class.
   *
   * \author Rob Bainbridge
   * \author Georgia Karapostoli
   * \author Tom Whyntie
   * \date March 2009
   * \version 1.2
   */
  class Jet : public LorentzV {

  public:

    /*! \brief Represents correction type applied to 4-vector:
     */
    enum Correction {
        RAW,     //!< "raw" 4-vector from pat::Jet
        CC,      //!< 4-vector from cross-cleaned jets, possibly "modified" to account for overlaps
        MC,      //!< MC-based JECs, on top of any modifications from cross-cleaner
        JPT,     //!< JPT-based JECs, on top of any modifications from cross-cleaner (muon corrections done in JPT, not CC!)
        GEN      //!< test only: returns 4-vector of associated GenJet
    };

    /*! \brief Constructor.
     *
     * @param px Momentum x component.
     * @param py Momentum y component.
     * @param pz Momentum z component.
     * @param E Energy.
     * @param emFrac Electromagnetic fraction (calo).
     * @param index Index of the object in the original ntuple array.
     * @param match Whether or not matched to a generated particle.
     */
    Jet(Double_t px, Double_t py, Double_t pz, Double_t E,
  Double_t emFrac,
  Int_t index, Bool_t match, Bool_t cc,
  Correction,bool IsSmeared,
  int loose, int minimal, int tight );

    Jet(const LorentzV& lorentzjet,
  Double_t emFrac,
  Int_t index, Bool_t match, Bool_t cc,
  Correction,bool IsSmeared,
  int loose, int minimal, int tight );

    Jet(const LorentzV& lorentzjet,
  Double_t emFrac,
  Int_t index, Bool_t match, Bool_t cc,
  Correction,bool IsSmeared );

    // ICF constructor
    Jet(const LorentzV & v,double emFrac,int index,
  int loose, int minimal, int tight );

    // Convenience method for Python testing
    Jet(double px,double py, double pz,double E,double emfrac,
        int index):
        LorentzV(px,py,pz,E),
        mEmFrac(emfrac),
        mIndex(index){}


    ~Jet(); //!< Destructor

    // Public data access
    //--------------------

    Double_t GetEmFrac() const; //!< Returns the EM fraction.

    /*! \brief Returns the index of the object in the original ntuple.
     * \return The index of the object in the original ntuple.
     */
    Int_t GetIndex() const;

    /*! \brief Returns flag: true = was cross-cleaned.
     */
    //Bool_t WasItCc() const;

    /*! \brief Returns flag: true = was matched to a generated particle.
     */
    Bool_t WasItMatched() const;


    /*! \brief Returns type of correction applied to 4-vector
     */
    Correction correction() const;

    static Correction correction( const std::string& ); //!< Utility method to convert b/w enums and strings
    static std::string correction( const Correction ); //!< Utility method to convert b/w enums and strings

    Bool_t GetMinimalId() const;
    Bool_t GetLooseId() const;
    Bool_t GetTightId() const;

  private:
    // Private data members
    //----------------------
    Double_t mEmFrac; //!< EM fraction.
    Int_t mIndex;     //!< Index in the ntuple.
    Bool_t mMatched;  //!< Flag: True = matched to a generated particle.
    Bool_t mCC;       //!< Flag: True = lepton is cross-cleaned
    Correction corr_; //!< Type of correction applied to 4-vector
    bool isSmeared_;
    int loose_;
    int minimal_;
    int tight_;

  }; //~class Jet

  inline Double_t Jet::GetEmFrac() const { return mEmFrac; }

  inline Int_t Jet::GetIndex() const { return mIndex;}

  inline Bool_t Jet::WasItMatched() const { return mMatched;}

  inline Jet::Correction Jet::correction() const { return corr_; }

  inline Bool_t Jet::GetMinimalId() const { return minimal_; }
  inline Bool_t Jet::GetLooseId() const { return loose_; }
  inline Bool_t Jet::GetTightId() const { return tight_; }

} // ~Event

std::ostream& operator<< ( std::ostream&, const Event::Jet& );

#endif //~Jet_hh

