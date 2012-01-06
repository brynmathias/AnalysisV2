/*! \file JetData.hh
 * \brief Header file for the jet analysis data Compute::Jet
 */
#ifndef JetData_hh
#define JetData_hh

#include "Compute_Variable.hh"
#include <vector>
#include <algorithm>
#include "Types.hh"
#include "Jet.hh"
#include "Utils.hh"
// Forward declaration
namespace Event {
  class Jet;
}

namespace Compute {
  namespace Jet {
    /*! \brief struct for CommonJets
     */
    struct CommonJets_Data {
      std::vector<Event::Jet const *> accepted;     //!< Common jets (pass acceptance and quality).

    std::vector<Event::Jet const *> odd;          //!< Odd jets (pass acceptance, fail quality).

      std::vector<Event::Jet const *> killed;
      std::vector<Event::Jet const *> killed_10_30;
      std::vector<Event::Jet const *> killed_30_50;

      std::vector<Event::Jet const *> baby;
      std::vector<Event::Jet const *> baby_10_30;
      std::vector<Event::Jet const *> baby_30_50;

      LorentzV killedHT;
      LorentzV killedHT_10_30;
      LorentzV killedHT_30_50;

      LorentzV babyHT;
      LorentzV babyHT_10_30;
      LorentzV babyHT_30_50;
      bool hasOdd;
    };//end of struct CommonJets

    /*! \brief Container class for common jets.
     * @author ICF SUSY team
     */
    class CommonJets : public Compute::Variable<CommonJets_Data, CommonJets> {
     public:
      CommonJets(const Event::Data & ev);
      void _Update() const;
     private:
      /*! \brief Determines how a jet should be categorised.
       */
      void ProcessJet(const Event::Jet* jet) const {

        if ( jet->Pt() >= mPtCut) { //acceptance cut on the pt, determined from config.
        // "Quality" check on the jet
          if (   fabs(jet->Eta()) < mEtaCut && //@@ means jet is odd outside of eta acceptance, regardless of ID
               ( !mApplyID || ( jet->GetLooseId() &&
      ((mTightID && jet->GetTightId()) || !mTightID) ) ) ) {
            mData.accepted.push_back(jet);
          } else { // fails quality criteria
            mData.odd.push_back(jet); // TW - add the odd jet to the collection.
            mData.hasOdd = true;
          }
        } else { // fails the kinematic cuts on the jet
          // JJ - arbitrary hard-coded number?
          // TR & TW - baby jets.
          // Jets that fall below the "acceptance" pt cut (from config) are now
          // subject to the "quality" cuts (eta and ID) if they are above
          // 10GeV (note - arbitrary and hard-coded number ;-D).
          // Jets that pass the quality cuts are baby jets, jets that fail
          // are classified as "killed" (as usual).
          // TODO: Make these cuts configurable...
          if( fabs(jet->Eta()) < mEtaCut && (!mApplyID || ( jet->GetLooseId() &&
         ((mTightID && jet->GetTightId()) || !mTightID) ) )) {
            if( jet->Pt() > 10.) {
              mData.babyHT -= *jet;
              mData.baby.push_back(jet);
            }
            if( jet->Pt() > 10 && jet->Pt() < 30){
              mData.babyHT_10_30 -= *jet;
              mData.baby_10_30.push_back(jet);
            }
            if ( jet->Pt() > 30 && jet->Pt() < mPtCut){
              mData.babyHT_30_50 -= *jet;
              mData.baby_30_50.push_back(jet);
            }
          } else{ // "baby" jet fails the quality cuts - it's killed.
            if( jet->Pt() > 10.) {
              mData.killedHT -= *jet;
              mData.killed.push_back(jet);
        }
            if( jet->Pt() > 10 && jet->Pt() < 30){
              mData.killedHT_10_30 -= *jet;
              mData.killed_10_30.push_back(jet);
            }
            if ( jet->Pt() > 30 && jet->Pt() < mPtCut){
              mData.killedHT_30_50 -= *jet;
              mData.killed_30_50.push_back(jet);
      }
          }
        } // end of the common kinematic checks on the preconf jets
      }//end of CommonJets ProcessJet method.

      //config variables
     public:
      const bool   applyXClean;  //!< Is the analysis using x-cleaning?
      const bool   XClean;       //!< Is the analysis using x-cleaning AND modifying jets?
     private:
      const double mPtCut;       //!< Transverse momentum cut for acceptance.
      const double mEtaCut;      //!< $|\eta|$ cut for jet quality.
      const bool   mTightID;     //!< Is tight ID required for a common jet?
      const bool   mApplyID;     //!< Is loose ID required for a common jet?

    //object management variables
   private:
      mutable boost::object_pool<Event::Jet> mPool;
      mutable std::vector<Event::Jet*>       mAltered;
     public:
      mutable ObjectProcessor<Event::Jet>    jet_proc;
    };//end of CommonJets class.

    // Jets passing an em-fraction cut
    class EMJets : public Compute::Variable<std::vector<Event::Jet const *>, EMJets> {
    public:
      EMJets(const Event::Data & ev);
      void _Update() const;
     private:
      const bool mComEMFracCut;
    };

  } //~namespace Jet
} //~namespace Compute

#endif //~LeptonicData_hh
