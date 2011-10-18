/*! \file LeptonData.hh
 * \brief Header file for the lepton analysis data Compute::Lepton
 */
#ifndef LeptonData_hh
#define LeptonData_hh

#include "Compute_Variable.hh"
#include <vector>
#include "Lepton.hh"
#include "Utils.hh"
// Forward declaration
namespace Event {
  class Lepton;
}

namespace Compute {
namespace Lepton {
    // Common electrons
struct CommonElectrons_Data {
  std::vector<Event::Lepton const *> accepted;
  std::vector<Event::Lepton const *> odd;
  std::vector<Event::Lepton const *> killed;
  bool hasOdd;
};

class CommonElectrons : public Compute::Variable<CommonElectrons_Data, CommonElectrons> {
 public:
  CommonElectrons(const Event::Data & ev);
  void _Update() const;
 private:
  inline void ProcessElectron(const Event::Lepton* const el) const;
 public:
  const bool XClean;
  const bool applyXClean;
 private:
  const double mEtCut;
  const double mEtaCut;
  const double mTrkIsoCut;
  const double mCombIsoCut;
  const bool mTightID;
  const bool mApplyID;
  const bool mRequireLooseForOdd; //TW added 23/20/2010
  mutable boost::object_pool<Event::Lepton> mPool;
  mutable std::vector<Event::Lepton*> mAltered;
 public:
  mutable ObjectProcessor<Event::Lepton> electron_proc;
};

inline void CommonElectrons::ProcessElectron(const Event::Lepton* const el) const{
  // Acceptance cuts
  if ( (el->Et() > mEtCut &&
        (fabs(el->Eta()) < mEtaCut) )) {
    // Electron passes loose ID criteria
    if ( !mApplyID || (el->GetLooseId() &&
                       ((mTightID && el->GetTightId()) || !mTightID) &&
                       ((el->GetTrkIsolation() < mTrkIsoCut) ||
                        (el->GetCombIsolation() < mCombIsoCut))))  {
      mData.accepted.push_back(el);
    } // end of ID and track isolation check
    else {
      if ((el->GetLooseId() && mRequireLooseForOdd) || !mRequireLooseForOdd) {    //TW - make consistent with muon...
        mData.odd.push_back(el); //TW
        mData.hasOdd = true;
      }
    } // end of bad electron (Loose ID and track isolation) check
  } // end of electron kinematic checks
  else mData.killed.push_back(el);
}

// Common muons
struct CommonMuons_Data {
  std::vector<Event::Lepton const *> accepted;
  std::vector<Event::Lepton const *> odd;
  std::vector<Event::Lepton const *> killed;
  bool hasOdd;
};

class CommonMuons : public Compute::Variable<CommonMuons_Data, CommonMuons> {
 public:
  CommonMuons(const Event::Data & ev);
  void _Update() const;
 private:
  inline void ProcessMuon(const Event::Lepton* const mu) const;
  const double mEtCut;
  const double mEtaCut;
  const double mTrkIsoCut;
  const double mCombIsoCut;
  const bool mTightID;
  const bool mApplyID;
  const bool mRequireLooseForOdd;
 public:
  const bool applyXClean;
  const bool XClean;
  mutable ObjectProcessor<Event::Lepton> muon_proc;
 private:
  mutable boost::object_pool<Event::Lepton> mPool;
  mutable std::vector<Event::Lepton*> mAltered;
};

 inline void CommonMuons::ProcessMuon(const Event::Lepton* const mu) const{
  // Acceptance cuts
  if ( (mu->Et() > mEtCut) &&
       (fabs(mu->Eta()) < mEtaCut) ) {

    // Check if muon passes loose ID criteria
    if ( !mApplyID || ((mu->GetLooseId()) &&
                       ((mTightID && mu->GetTightId()) || !mTightID) &&
                       ((mu->GetTrkIsolation() < mTrkIsoCut) ||
                        (mu->GetCombIsolation() < mCombIsoCut)))) {

      mData.accepted.push_back(mu);

    } else {
      if(( mu->GetLooseId() && mRequireLooseForOdd) || !mRequireLooseForOdd) {
    mData.odd.push_back(mu);
        mData.hasOdd = true; // passes loose ID criteria
      }
    } // end of bad muon (ID and track isolation) checks
  } // end of kinematic acceptance check
  else mData.killed.push_back(mu);
 }

  // Common taus
  struct CommonTaus_Data {
    std::vector<Event::Lepton const *> accepted;
    std::vector<Event::Lepton const *> killed;
    bool hasOdd;
  };
  class CommonTaus : public Compute::Variable<CommonTaus_Data, CommonTaus> {
  public:
    CommonTaus(const Event::Data & ev);
    void _Update() const;
    mutable ObjectProcessor<Event::Lepton> tau_proc;
    const bool XClean;
    const bool applyXClean;
  private:
    inline void ProcessTau(const Event::Lepton* const tau) const;
    const double mEtCut;
    const double mEtaCut;
    const bool mTauElecClean, mTauMuonClean, mTauJetClean;
    const bool mTightID;
    const bool mApplyID;
    mutable boost::object_pool<Event::Lepton> mPool;
    mutable std::vector<Event::Lepton*> mAltered;
  };



  inline void CommonTaus::ProcessTau(const Event::Lepton* const tau) const{
    // Acceptance cuts
    if ( (tau->Et() > mEtCut) &&
   (fabs(tau->Eta()) < mEtaCut) ) {

      // Check if tau passes loose ID criteria
  if ( !mApplyID || tau->GetLooseId()) {
  mData.accepted.push_back(tau);
  }
  else {
    if(tau->GetLooseId()) {
      mData.hasOdd = true; // failed loose ID criteria
    }
  } // end of bad tau

    } // end of kinematic acceptance check
    else mData.killed.push_back(tau);
  }


  //@@ UNCOMMENT ON AS-NEED BASIS

//     // Good electron data
//     class GoodElectrons : public Compute::Variable<std::vector<Event::Lepton const *>, GoodElectrons> {
//     public:
//       GoodElectrons(const Event::Data & ev);
//       void _Update() const;
//     };

//     // Good muons data
//     class GoodMuons : public Compute::Variable<std::vector<Event::Lepton const *>, GoodMuons> {
//     public:
//       GoodMuons(const Event::Data & ev);
//       void _Update() const;
//     };

//     // Good lepton recoil
//     class GoodLepRecoil : public Compute::Variable<Double_t, GoodLepRecoil> {
//     public:
//       GoodLepRecoil(const Event::Data & ev);
//       void _Update() const;
//     };

 } //~namespace Lepton
} //~namespace Compute

#endif //~LeptonicData_hh
