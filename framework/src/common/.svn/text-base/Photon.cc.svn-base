/*! \file Photon.cc
 * \brief Source code for the (simple) EventStuff::Photon physics object container class.
 */

#include "Photon.hh"

namespace Event {

  Photon::Photon(const LorentzV& v, double ecalRecHitSumEtConeDR04, double hcalTowerSumEtConeDR04, double trkSumPtHollowConeDR04,
       double hadronicOverEm, bool hasPixelSeed, double r9, double superClusterEnergy, double sigmaIetaIeta, int index) :
    LorentzV(v),
    mEcalRecHitSumEtConeDR04(ecalRecHitSumEtConeDR04),
    mHcalTowerSumEtConeDR04(hcalTowerSumEtConeDR04),
    mTrkSumPtHollowConeDR04(trkSumPtHollowConeDR04),
    mHadronicOverEm(hadronicOverEm),
    mHasPixelSeed(hasPixelSeed),
    mR9(r9),
    mSuperClusterEnergy(superClusterEnergy),
    mSigmaIetaIeta(sigmaIetaIeta),
    mIndex(index) {
      mTight = ( ecalRecHitSumEtConeDR04 < 4.2 + 0.006*v.Pt() &&
                 hcalTowerSumEtConeDR04 < 2.2 + 0.0025*v.Pt() &&
                 hadronicOverEm < 0.05 &&
                 trkSumPtHollowConeDR04 < 2 + 0.001*v.Pt() &&
                 ( (fabs(v.Eta()) < 1.479 && sigmaIetaIeta < 0.013) || (fabs(v.Eta()) > 1.525 && fabs(v.Eta()) < 2.5 && sigmaIetaIeta < 0.030) )
                );
      mLoose = ( ecalRecHitSumEtConeDR04 < 4.2 + 0.006*v.Pt() &&
                 hcalTowerSumEtConeDR04 < 2.2 + 0.0025*v.Pt() &&
                 hadronicOverEm < 0.05 &&
                 trkSumPtHollowConeDR04 < 3.5 + 0.001*v.Pt()
               );
      mLooseEM = ( ecalRecHitSumEtConeDR04 < 4.2 + 0.006*v.Pt() &&
                   hcalTowerSumEtConeDR04 < 2.2 + 0.0025*v.Pt() &&
                   hadronicOverEm < 0.05
                 );
  }
  Photon::~Photon() {}

  Double_t Photon::GetTrackIsolation() const { return mTrkSumPtHollowConeDR04; }
  Double_t Photon::GetEcalIsolation() const { return mEcalRecHitSumEtConeDR04; }
  Double_t Photon::GetHcalIsolation() const { return mHcalTowerSumEtConeDR04; }
  Double_t Photon::GetCaloIsolation() const { return mEcalRecHitSumEtConeDR04 + mHcalTowerSumEtConeDR04; }

  Double_t Photon::ecalRecHitSumEtConeDR04() const { return mEcalRecHitSumEtConeDR04; }
  Double_t Photon::hcalTowerSumEtConeDR04() const { return mHcalTowerSumEtConeDR04; }
  Double_t Photon::trkSumPtHollowConeDR04() const { return mTrkSumPtHollowConeDR04; }

  Double_t Photon::hadronicOverEm() const { return mHadronicOverEm; }
  Bool_t Photon::hasPixelSeed() const { return mHasPixelSeed; }
  Double_t Photon::r9() const { return mR9; }
  Double_t Photon::superClusterEnergy() const { return mSuperClusterEnergy; }
  Double_t Photon::sigmaIetaIeta() const { return mSigmaIetaIeta; }

  Int_t Photon::GetIndex() const { return mIndex;}

  void Photon::SetMatched(Bool_t matched) { mMatched = matched; }
  Bool_t Photon::WasItMatched() const { return mMatched;}
  void Photon::SetMatchedGenIndex(Int_t index) {gen_index_ = index; }
  Int_t Photon::GetGenIndex() const { return gen_index_; }

  Bool_t Photon::IsItTight() const { return mTight; }
  Bool_t Photon::IsItLoose() const { return mLoose; }
  Bool_t Photon::IsItLooseEM() const { return mLooseEM; }

  const char * Photon::GetID() const {
    if      (mTight)   { return "Tight"; }
    else if (mLoose)   { return "Loose"; }
    else if (mLooseEM) { return "LooseEM"; }
    else               { return "NoID"; }
  }

  UInt_t Photon::GetIntID() const {
    if      (mTight)   { return 3; }
    else if (mLoose)   { return 2; }
    else if (mLooseEM) { return 1; }
    else { return 0; }
  }

  void Photon::SetIntID(int id) {
    if (id == 3) { mTight = true; mLoose = true; mLooseEM = true; }
    if (id == 2) { mTight = false; mLoose = true; mLooseEM = true; }
    if (id == 1) { mTight = false; mLoose = false; mLooseEM = true; }
    if (id == 0) { mTight = false; mLoose = false; mLooseEM = false; }
  }

} // ~namespace Event

std::ostream& operator<< ( std::ostream& os, const Event::Photon& input ) {
    std::stringstream ss;
    ss  << "[EventStuff::Photon] "
        << " Index, Matched (gen), CC, ID: "
        << input.GetIndex() << ", "
        << input.WasItMatched() << ", "
        << input.GetID();
    ss  << std::endl
        << " Px/Py/Pz/E        : "
        << std::setprecision(8) << input.Px() << "/"
        << std::setprecision(8) << input.Py() << "/"
        << std::setprecision(8) << input.Pz() << "/"
        << std::setprecision(8) << input.E() << std::endl
        << " Pt/Et             : "
        << std::setprecision(8) << input.Pt() << "/"
        << std::setprecision(8) << input.Et() << std::endl
        << " eta/phi           : "
        << std::setprecision(8) << input.Eta() << "/"
        << std::setprecision(8) << input.Phi() << std::endl
        << " iso ecal/hcal/track : "
        << std::setprecision(8) << input.GetEcalIsolation() << "/"
        << std::setprecision(8) << input.GetHcalIsolation() << "/"
        << std::setprecision(8) << input.GetTrackIsolation() << "/"
        << " id hadronicOverEm/r9/sigmaIetaIeta : "
        << std::setprecision(8) << input.hadronicOverEm() << "/"
        << std::setprecision(8) << input.r9() << "/"
        << std::setprecision(8) << input.sigmaIetaIeta() << std::endl;
    os << ss.str();
    return os;
}
