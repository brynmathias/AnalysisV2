#include "PhotonCompute.hh"
#include "EventData.hh"
#include "Compute_Variable.hh"
#include "GenObject.hh"
#include "Math/VectorUtil.h"
#include "Utils.hh"

//namespace Photon{

SelectedPhotons::SelectedPhotons(const Utils::ParameterSet & ps):
    Compute::User<std::vector<Event::Photon const *>,SelectedPhotons>() {
  mEt = ps.Get<double>("Et");
  mEtaEBMax = ps.Get<double>("EtaEBMax");
  mEtaEEMin = ps.Get<double>("EtaEEMin");
  mEtaEEMax = ps.Get<double>("EtaEEMax");
  mIDReq = ps.Get<int>("IDReq");
}

void SelectedPhotons::_Update() const {
  mData.clear();
  for (std::vector<Event::Photon>::const_iterator iP = mEv->PD_Photons().begin();
       iP != mEv->PD_Photons().end();++iP) {
    if (iP->Et() > mEt
        && ( fabs(iP->Eta()) < mEtaEBMax || (fabs(iP->Eta()) > mEtaEEMin && fabs(iP->Eta()) < mEtaEEMax) ) 
        && iP->GetIntID() >= mIDReq ) {
      mData.push_back(&*iP);
    }
  }
}

std::ostream & SelectedPhotons::Description(std::ostream & ostrm){
  ostrm << " Selected Photons ";
  return ostrm;
}

SelectedJets::SelectedJets(const Utils::ParameterSet & ps):
    Compute::User<std::vector<Event::Jet const *>,SelectedJets>() {
  mEt = ps.Get<double>("Et");
  mDeltaR = ps.Get<double>("DeltaR");
}

void SelectedJets::_Update() const {
  mData.clear();
  for (std::vector<Event::Jet>::const_iterator jet = mEv->JD_Jets().begin(); 
       jet != mEv->JD_Jets().end(); ++jet) {
    bool jet_accepted = true;
    for (std::vector<Event::Photon const *>::const_iterator pho = mEv->PD_CommonPhotons().accepted.begin(); 
         pho != mEv->PD_CommonPhotons().accepted.end(); ++pho) {
      jet_accepted = jet_accepted && (ROOT::Math::VectorUtil::DeltaR(*jet, **pho) > mDeltaR);
    }
    if (jet_accepted) mData.push_back(&*jet);
  }
}

std::ostream & SelectedJets::Description(std::ostream & ostrm){
  ostrm << " SelectedJets ";
  return ostrm;
}

Status1GenPhotons::Status1GenPhotons():
    Compute::User<std::vector<Event::GenObject>,Status1GenPhotons>()
{}

void Status1GenPhotons::_Update() const {
  mData.clear();
  for (std::vector<Event::GenObject>::const_iterator it = mEv->GenParticles().begin();  it != mEv->GenParticles().end(); ++it) {
    if (it->GetStatus() == 1 && it->GetID() == 22) mData.push_back(*it);
  }
}

std::ostream & Status1GenPhotons::Description(std::ostream & ostrm){
  ostrm << " Status1 Gen Photons ";
  return ostrm;
}

Status3GenPhotons::Status3GenPhotons():
    Compute::User<std::vector<Event::GenObject>,Status3GenPhotons>()
{}

void Status3GenPhotons::_Update() const {
  mData.clear();
  for (std::vector<Event::GenObject>::const_iterator it = mEv->GenParticles().begin();  it != mEv->GenParticles().end(); ++it) {
    if (it->GetStatus() == 3 && it->GetID() == 22) mData.push_back(*it);
  }
}

std::ostream & Status3GenPhotons::Description(std::ostream & ostrm){
  ostrm << " Status3 Gen Photons ";
  return ostrm;
}

MatchedStatus1Photons::MatchedStatus1Photons(double EtCut, double EtaCut):
    Compute::User<std::vector<Event::Photon const *>,MatchedStatus1Photons>(),
    mEtCut(EtCut),
    mEtaCut(EtaCut)
{}

void MatchedStatus1Photons::_Update() const {
  mData.clear();
  for (std::vector<Event::Photon>::const_iterator iP = mEv->PD_Photons().begin(); iP != mEv->PD_Photons().end();++iP) {
    if (iP->Et() > mEtCut && fabs(iP->Eta()) < mEtaCut)
    {
      for (std::vector<Event::GenObject>::const_iterator gp = mEv->GenParticles().begin(); gp != mEv->GenParticles().end();++gp) {
        //if (gp->GetID() == 22) {
          //std::cout << "[Gen Particles]" << std::endl;
          //std::cout << "ID = " << gp->GetID() << std::endl;
          //std::cout << "Status = " << gp->GetStatus() << std::endl;
          //std::cout << "Pt = " << gp->Pt() << std::endl;
        //}
        //if ((gp->GetStatus() == 1 || gp->GetStatus() == 3) && gp->GetID() == 22) {
        if (gp->GetStatus() == 1 && gp->GetID() == 22) {
        //if (gp->GetStatus() == 1 && gp->GetID() == 22) {
          if (ROOT::Math::VectorUtil::DeltaR(*gp,*iP) < 0.5) mData.push_back(&*iP);
        }
      }
    }
  }
}

std::ostream & MatchedStatus1Photons::Description(std::ostream & ostrm){
  ostrm << " Matched Status1 Photons ";
  return ostrm;
}

MatchedStatus3Photons::MatchedStatus3Photons(double EtCut, double EtaCut):
    Compute::User<std::vector<Event::Photon const *>,MatchedStatus3Photons>(),
    mEtCut(EtCut),
    mEtaCut(EtaCut)
{}

void MatchedStatus3Photons::_Update() const {
  mData.clear();
  for (std::vector<Event::Photon>::const_iterator iP = mEv->PD_Photons().begin(); iP != mEv->PD_Photons().end();++iP) {
    if (iP->Et() > mEtCut && fabs(iP->Eta()) < mEtaCut)
    {
      for (std::vector<Event::GenObject>::const_iterator gp = mEv->GenParticles().begin(); gp != mEv->GenParticles().end();++gp) {
        //if (gp->GetID() == 22) {
          //std::cout << "[Gen Particles]" << std::endl;
          //std::cout << "ID = " << gp->GetID() << std::endl;
          //std::cout << "Status = " << gp->GetStatus() << std::endl;
          //std::cout << "Pt = " << gp->Pt() << std::endl;
        //}
        //if ((gp->GetStatus() == 1 || gp->GetStatus() == 3) && gp->GetID() == 22) {
        if (gp->GetStatus() == 3 && gp->GetID() == 22) {
        //if (gp->GetStatus() == 1 && gp->GetID() == 22) {
          if (ROOT::Math::VectorUtil::DeltaR(*gp,*iP) < 0.5) mData.push_back(&*iP);
        }
      }
    }
  }
}

std::ostream & MatchedStatus3Photons::Description(std::ostream & ostrm){
  ostrm << " Matched Status3 Photons ";
  return ostrm;
}

UnmatchedPhotons::UnmatchedPhotons(double EtCut, double EtaCut):
    Compute::User<std::vector<Event::Photon const *>,UnmatchedPhotons>(),
    mEtCut(EtCut),
    mEtaCut(EtaCut)
{}

void UnmatchedPhotons::_Update() const {
  mData.clear();
  for (std::vector<Event::Photon>::const_iterator iP = mEv->PD_Photons().begin(); iP != mEv->PD_Photons().end();++iP) {
    bool isMatched = false;
    if (iP->Et() > mEtCut && fabs(iP->Eta()) < mEtaCut)
    {
      for (std::vector<Event::GenObject>::const_iterator gp = mEv->GenParticles().begin(); gp != mEv->GenParticles().end();++gp) {
        //if (gp->GetID() == 22) {
          //std::cout << "[Gen Particles]" << std::endl;
          //std::cout << "ID = " << gp->GetID() << std::endl;
          //std::cout << "Status = " << gp->GetStatus() << std::endl;
          //std::cout << "Pt = " << gp->Pt() << std::endl;
        //}
        //if ((gp->GetStatus() == 1 || gp->GetStatus() == 3) && gp->GetID() == 22) {
        if ((gp->GetStatus() == 3 || gp->GetStatus() == 1) && gp->GetID() == 22) {
        //if (gp->GetStatus() == 1 && gp->GetID() == 22) {
          if (ROOT::Math::VectorUtil::DeltaR(*gp,*iP) < 0.5) {
            isMatched = true;
            break;
          }
        }
      }
      if (!isMatched) mData.push_back(&*iP);
    }
  }
}

std::ostream & UnmatchedPhotons::Description(std::ostream & ostrm){
  ostrm << " Unmatched Photons ";
  return ostrm;
}
//}
