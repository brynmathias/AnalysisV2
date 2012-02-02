/*! \file PhotonicData.hh
 * \brief Header file for the photonic analysis-specific data container EventStuff::PhotonicData.
 */
#ifndef PhotonicData_hh
#define PhotonicData_hh

#include "Compute_Variable.hh"
#include <vector>
#include "Jet.hh"
#include "Photon.hh"
#include "Utils.hh"

namespace Event {
  class GenObject;
}

namespace Compute {
  namespace Photon {

    // Moved from Event::Data
    struct CommonPhotons_Data {
      std::vector<Event::Photon const *> accepted;
      std::vector<Event::Photon const *> odd;
      std::vector<Event::Photon const *> killed;
      bool hasOdd;
    };

    class CommonPhotons : public Compute::Variable<CommonPhotons_Data, CommonPhotons> {
    public:
      CommonPhotons(const Event::Data & ev);
      void _Update() const;
    private:
      inline void ProcessPhoton(const Event::Photon* const ph) const;
    public:
      const bool XClean;
      const bool applyXClean;
    private:
      const double mEtCut;
      const double mEtaEBMaxCut;
      const double mEtaEEMinCut;
      const double mEtaEEMaxCut;
      const double mEcalIsoCut;
      const double mEcalIsoRel;
      const double mHcalIsoCut;
      const double mHcalIsoRel;
      const double mTrackIsoCut;
      const double mTrackIsoRel;
      const double mHadOverEmCut;
      const double mR9Cut;
      const double mSigIhIhEBCut;
      const double mSigIhIhEECut;
      const int mIDReq;
      const bool mUseID;
      const bool mRequireLooseForOdd; //TW added 23/10/2010
      mutable boost::object_pool<Event::Photon> mPool;
      mutable std::vector<Event::Photon*> mAltered;
    public:
      mutable ObjectProcessor<Event::Photon> photon_proc;
    };

    inline void CommonPhotons::ProcessPhoton(const Event::Photon* const ph) const{

      if ( mUseID ) {
        if ( ph->Et() > mEtCut
             &&  ( fabs(ph->Eta()) < mEtaEBMaxCut || ( fabs(ph->Eta()) < mEtaEEMaxCut && fabs(ph->Eta()) > mEtaEEMinCut ) )
             && int(ph->GetIntID()) >= mIDReq ) {
          mData.accepted.push_back(ph);
        } else if ((ph->IsItLoose() && mRequireLooseForOdd) || !mRequireLooseForOdd ) { //TW added 23/20/2010
          mData.odd.push_back(ph);
          mData.hasOdd = true;
        } else {
          mData.killed.push_back(ph);
        }
      } else {
        if ( ph->Et() > mEtCut
             && ( fabs(ph->Eta()) < mEtaEBMaxCut || ( fabs(ph->Eta()) < mEtaEEMaxCut && fabs(ph->Eta()) > mEtaEEMinCut ) )
             && ph->ecalRecHitSumEtConeDR04() <  mEcalIsoCut + mEcalIsoRel*ph->Et()
             && ph->hcalTowerSumEtConeDR04() < mHcalIsoCut + mHcalIsoRel*ph->Et()
             && ph->trkSumPtHollowConeDR04() < mTrackIsoCut + mTrackIsoRel*ph->Et()
             && ph->hadronicOverEm() < mHadOverEmCut
             && ph->r9() > mR9Cut
             && ( (fabs(ph->Eta()) < mEtaEBMaxCut && ph->sigmaIetaIeta() < mSigIhIhEBCut) || (fabs(ph->Eta()) < mEtaEEMaxCut && fabs(ph->Eta()) > mEtaEEMinCut &&  ph->sigmaIetaIeta() < mSigIhIhEECut) ) ) {
          mData.accepted.push_back(ph);
        } else if ((ph->IsItLoose() && mRequireLooseForOdd) || !mRequireLooseForOdd ) { //TW added 23/20/2010
          mData.odd.push_back(ph);
          mData.hasOdd = true;
        } else {
          mData.killed.push_back(ph);
        }
      }
    }

  } // ~Photon
} // ~Compute

#endif //~PhotonicData_hh
