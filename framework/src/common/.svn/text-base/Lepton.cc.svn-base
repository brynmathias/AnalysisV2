/*! \file Lepton.cc
 * \brief Source code for the (simple) EventStuff::Lepton physics object container class.
 */

#include "Lepton.hh"


namespace Event {

  Lepton::Lepton(Double_t px, Double_t py, Double_t pz, Double_t E,
     Double_t charge, Double_t trkIso, Double_t ecalIso, Double_t hcalIso,
     Bool_t looseId, Bool_t tightId,
     Int_t type, Int_t index, Bool_t match, Bool_t cc) :
    LorentzV(px, py, pz, E),
    mCharge(charge),
    mTrkIso(trkIso),
    mEcalIso(ecalIso),
    mHcalIso(hcalIso),
    mLooseId(looseId),
    mTightId(tightId),
    mType(type),
    mIndex(index),
    mMatched(match),
    mCC(cc)
  {}

  Lepton::~Lepton() {}

  Double_t Lepton::GetCharge() const { return mCharge;}
  Double_t Lepton::GetTrkIsolation() const { return mTrkIso; }
  Double_t Lepton::GetEcalIsolation() const { return mEcalIso; }
  Double_t Lepton::GetHcalIsolation() const { return mHcalIso; }
  Double_t Lepton::GetCombIsolation() const {


    if(fabs(Eta()) < 1.4442 && mType ==1){
      return (mTrkIso/this->Pt() + TMath::Max(0.,(mEcalIso-1.))/this->Et() + mHcalIso/this->Et());}
    else{
      return (mTrkIso/this->Pt() + mEcalIso/this->Et() + mHcalIso/this->Et());}

 }
  Bool_t Lepton::GetLooseId() const { return mLooseId; }
  Bool_t Lepton::GetTightId() const { return mTightId; }
  Int_t Lepton::GetIndex() const { return mIndex;}
  Int_t Lepton::GetType() const { return mType;}
  Bool_t Lepton::WasItMatched() const { return mMatched;}

} // ~namespace Event
