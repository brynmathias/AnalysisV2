/*! \file Compute_Helpers.cc
 * \brief Helper classes for caching computational variables
 */

#include "Compute_Helpers.hh"
#include <stdexcept>
#include "AlphaT.hh"
#include "EventData.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
#include "GenObject.hh"
#include "Photon.hh"
#include "Lepton.hh"
#include "Utils.hh"
#include "Razor.hh"

namespace Compute {


  RecoilMET::RecoilMET(const Event::Data & ev) :
    Compute::Variable<LorentzV, RecoilMET>(ev) {}

  void RecoilMET::_Update() const {
    mData.SetPxPyPzE(0.,0.,0.,0.);

    // Photons
    for ( std::vector<Event::Photon>::const_iterator i = mEv.PD_Photons().begin();
      i != mEv.PD_Photons().end();
      i++ ) {
      mData -= (*i);
    }

    // Electrons
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Electrons().begin();
      i != mEv.LD_Electrons().end();
      i++ ) {
      mData -= (*i);
    }

    // Muons
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Muons().begin();
      i != mEv.LD_Muons().end();
      i++ ) {
      mData -= (*i);
    }

    // Taus
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Taus().begin();
      i != mEv.LD_Taus().end();
      i++ ) {
      // JJ - bug here, was RecoilMET += tau
      mData -= (*i);
    }

    // Jets
    for ( std::vector<Event::Jet>::const_iterator i = mEv.JD_Jets().begin();
      i != mEv.JD_Jets().end();
      i++ ) {
      mData -= (*i);
    }
  }

  ObjSum::ObjSum(const Event::Data & ev) :
    Compute::Variable<LorentzV, ObjSum>(ev) {}

  void ObjSum::_Update() const {
    mData.SetPxPyPzE(0.,0.,0.,0.);

    // Photons
    for ( std::vector<Event::Photon>::const_iterator i = mEv.PD_Photons().begin();
      i != mEv.PD_Photons().end();
      i++ ) {
      mData += (*i);
    }

    // Electrons
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Electrons().begin();
      i != mEv.LD_Electrons().end();
      i++ ) {
      mData += (*i);
    }

    // Muons
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Muons().begin();
      i != mEv.LD_Muons().end();
      i++ ) {
      mData += (*i);
    }

    // Jets
    for ( std::vector<Event::Jet>::const_iterator i = mEv.JD_Jets().begin();
      i != mEv.JD_Jets().end();
      i++ ) {
      mData += (*i);
    }
  }

  SumEt::SumEt(const Event::Data & ev) :
    Compute::Variable<Double_t, SumEt>(ev) {}

  void SumEt::_Update() const {
    mData = 0.0;

    // Photons
    for ( std::vector<Event::Photon>::const_iterator i = mEv.PD_Photons().begin();
      i != mEv.PD_Photons().end();
      i++ ) {
      mData += i->Et();
    }

    // Electrons
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Electrons().begin();
      i != mEv.LD_Electrons().end();
      i++ ) {
      mData += i->Et();
    }

    // Muons
    for ( std::vector<Event::Lepton>::const_iterator i = mEv.LD_Muons().begin();
      i != mEv.LD_Muons().end();
      i++ ) {
      mData += i->Et();
    }

    // Jets
    for ( std::vector<Event::Jet>::const_iterator i = mEv.JD_Jets().begin();
      i != mEv.JD_Jets().end();
      i++ ) {
      mData += i->Et();
    }

    // NB - no taus?
  }
CommonMeff::CommonMeff(const Event::Data & ev) :
  Compute::Variable<Double_t, CommonMeff>(ev) {}



  void CommonMeff::_Update() const {


    mData = mEv.CommonSumEt() + mEv.CommonObjectSum().Pt();

  }


  CommonMHT::CommonMHT(const Event::Data & ev) :
    Compute::Variable<LorentzV, CommonMHT>(ev) {}

  void CommonMHT::_Update() const {
    mData.SetPxPyPzE(0.,0.,0.,0.);

    // Loop
    for ( std::vector<Event::Jet const *>::const_iterator j = mEv.JD_CommonJets().accepted.begin();
      j != mEv.JD_CommonJets().accepted.end();
      ++j ) {
      mData -= (**j);
    }

  }
 

  CommonMHTTakeMu::CommonMHTTakeMu(const Event::Data & ev) :
    Compute::Variable<LorentzV, CommonMHTTakeMu>(ev) {}

  void CommonMHTTakeMu::_Update() const {
    mData.SetPxPyPzE(0.,0.,0.,0.);

    // Loop
    for ( std::vector<Event::Jet const *>::const_iterator j = mEv.JD_CommonJets().accepted.begin();
      j != mEv.JD_CommonJets().accepted.end();
      ++j ) {
      mData -= (**j);
    }

    for ( std::vector<Event::Lepton const *>::const_iterator j = mEv.LD_CommonMuons().accepted.begin();
      j != mEv.LD_CommonMuons().accepted.end();
      ++j ) {
      mData -= (**j);
    }

  }
 



  CommonHT::CommonHT(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonHT>(ev) {}

  void CommonHT::_Update() const {
    mData = 0.0;

    // Loop
    for ( std::vector<Event::Jet const *>::const_iterator j = mEv.JD_CommonJets().accepted.begin();
      j != mEv.JD_CommonJets().accepted.end();
      ++j ) {
      mData += (*j)->Et();
    }
  }

  CommonHTTakeMu::CommonHTTakeMu(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonHTTakeMu>(ev) {}

  void CommonHTTakeMu::_Update() const {
    mData = 0.0;

    // Loop
    for ( std::vector<Event::Jet const *>::const_iterator j = mEv.JD_CommonJets().accepted.begin();
      j != mEv.JD_CommonJets().accepted.end();
      ++j ) {
      mData += (*j)->Et();
    }

    for ( std::vector<Event::Lepton const *>::const_iterator j = mEv.LD_CommonMuons().accepted.begin();
      j != mEv.LD_CommonMuons().accepted.end();
      ++j ) {
      mData += (*j)->Et();
    }
  }

  CommonMT::CommonMT(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonMT>(ev) {}

  void CommonMT::_Update() const {
    // Of course, MT is just sqrt(SumEt^2 - Recoil^2). But notice how the encapsulation
    // of the method would have allowed us to use the vector of ComObs if we had wanted.
    // Check if negative - can happen as a result of bad (e.g.) corrections!
    // If it is negative, return the corresponding negative mass value.
    mData = mEv.CommonSumEt() * mEv.CommonSumEt()
      - mEv.CommonObjectSum().Pt() * mEv.CommonObjectSum().Pt();
    if ( mData >= 0.0 ) {
      mData = sqrt(mData);
    } else {
      mData = sqrt(-mData);
    }
  }


 CommonMinDPhi::CommonMinDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonMinDPhi>(ev) {}

  void CommonMinDPhi::_Update() const {
    mData = Event::KS_MinDPhi( mEv.CommonRecoil(), mEv.CommonObjects() );
  }

  CommonMinBiasDPhi::CommonMinBiasDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonMinBiasDPhi>(ev) {}

  void CommonMinBiasDPhi::_Update() const {
    mData = Event::KS_MinBiasDPhi( mEv.CommonRecoil(), mEv.CommonObjects() );
  }

  JetMinDPhi::JetMinDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, JetMinDPhi>(ev) {}

  void JetMinDPhi::_Update() const {
    mData = Event::KS_MinDPhi( mEv.CommonMHT(), (const std::vector<LorentzV> &) mEv.JD_CommonJets().accepted );
  }

  JetMinBiasDPhi::JetMinBiasDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, JetMinBiasDPhi>(ev) {}

  void JetMinBiasDPhi::_Update() const {
    mData = 10.0;
    for (std::vector<Event::Jet const *>::const_iterator iJ = mEv.JD_CommonJets().accepted.begin();
     iJ != mEv.JD_CommonJets().accepted.end();
     ++iJ) {
      float mydPhi = mEv.biasedComRecoilMetdPhi(*iJ);
      if(mydPhi < mData) mData = mydPhi;
    }
  }

  JetMETMinDPhi::JetMETMinDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, JetMETMinDPhi>(ev) {}

  void JetMETMinDPhi::_Update() const {
    mData = Event::KS_MinDPhi( mEv.PFMET(), (const std::vector<LorentzV> &) mEv.JD_CommonJets().accepted );
  }

  CommonMinDEt::CommonMinDEt(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonMinDEt>(ev) {}

  void CommonMinDEt::_Update() const {
    if ( mEv.CommonObjects().size() < 1 ||
     mEv.CommonObjects().size() > Event::KS_MinDEt_MaxN() ) {
      throw std::runtime_error("Cannot compute CommonMinDEt - out of object range");
    }
    mData = Event::KS_MinDEt( mEv.CommonObjects() );
  }

  CommonAlphaT::CommonAlphaT(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonAlphaT>(ev),
      AlphaTwithEt(Utils::GetConfig<bool>("Common.AlphaT.CalcWithEt")) {}

  void CommonAlphaT::_Update() const {
      std::vector<bool> pseudo;
      double alpha_t = AlphaT()( mEv.CommonObjects(), pseudo, AlphaTwithEt );
      if ( pseudo.size() != mEv.CommonObjects().size() ) { throw std::runtime_error("Pseudo jet calculations did not use all common objects");}


      mData = alpha_t;
  }

  LeptonicAlphaT::LeptonicAlphaT(const Event::Data & ev) :
    Compute::Variable<Double_t, LeptonicAlphaT>(ev),
AlphaTwithEt(Utils::GetConfig<bool>("Common.AlphaT.CalcWithEt")) {}

  void LeptonicAlphaT::_Update() const {
      std::vector<bool> pseudo;
      double alpha_t = AlphaT()( mEv.LeptonicObjects(), pseudo, AlphaTwithEt );
      if ( pseudo.size() != mEv.LeptonicObjects().size() ) { throw std::runtime_error("Pseudo jet calculations did not use all common objects");}


      mData = alpha_t;
  }

  HadronicAlphaT::HadronicAlphaT(const Event::Data & ev) :
    Compute::Variable<Double_t, HadronicAlphaT>(ev),
AlphaTwithEt(Utils::GetConfig<bool>("Common.AlphaT.CalcWithEt")) {}

  void HadronicAlphaT::_Update() const {
      std::vector<bool> pseudo;
      double alpha_t = AlphaT()( mEv.HadronicObjects(), pseudo, AlphaTwithEt );
      if ( pseudo.size() != mEv.HadronicObjects().size() ) { throw std::runtime_error("Pseudo jet calculations did not use all common objects");}


      mData = alpha_t;
  }


  HadronicAlphaTTakeMu::HadronicAlphaTTakeMu(const Event::Data & ev) :
    Compute::Variable<Double_t, HadronicAlphaTTakeMu>(ev),
AlphaTwithEt(Utils::GetConfig<bool>("Common.AlphaT.CalcWithEt")) {}

  void HadronicAlphaTTakeMu::_Update() const {
      std::vector<bool> pseudo;
      double alpha_t = AlphaT()( mEv.CommonJetsAndMuons(), pseudo, AlphaTwithEt );
      if ( pseudo.size() != mEv.CommonJetsAndMuons().size() ) { throw std::runtime_error("Pseudo jet calculations did not use all common objects");}


      mData = alpha_t;
  }


  CommonMT2::CommonMT2(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonMT2>(ev) {}

  void CommonMT2::_Update() const {
    if ( mEv.CommonObjects().size() < 1 ||
     mEv.CommonObjects().size() > Event::KS_MinDEt_MaxN() ) {
      throw std::runtime_error("Cannot compute CommonMT2 - out of object range");
    }
    mData = Event::MT2(mEv.CommonObjects());
  }



  CommonRecoilMET::CommonRecoilMET(const Event::Data & ev) :
    Compute::Variable<LorentzV, CommonRecoilMET>(ev) {}

  void CommonRecoilMET::_Update() const {
    mData.SetPxPyPzE(0.,0.,0.,0.);

    // Photons
    for ( std::vector<Event::Photon const *>::const_iterator i = mEv.PD_CommonPhotons().accepted.begin();
      i != mEv.PD_CommonPhotons().accepted.end();
      i++ ) {
      mData -= (**i);
    }

    // Electrons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonElectrons().accepted.begin();
      i != mEv.LD_CommonElectrons().accepted.end();
      i++ ) {
      mData -= (**i);
    }

    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonMuons().accepted.begin();
      i != mEv.LD_CommonMuons().accepted.end();
      i++ ) {
      mData -= (**i);
    }

    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
      i != mEv.JD_CommonJets().accepted.end();
      i++ ) {
      mData -= (**i);
    }
  }

  CommonObjectSum::CommonObjectSum(const Event::Data & ev) :
    Compute::Variable<LorentzV, CommonObjectSum>(ev) {}

  void CommonObjectSum::_Update() const {
    mData.SetPxPyPzE(0.,0.,0.,0.);

    // Photons
    for ( std::vector<Event::Photon const *>::const_iterator i = mEv.PD_CommonPhotons().accepted.begin();
      i != mEv.PD_CommonPhotons().accepted.end();
      i++ ) {
      mData += (**i);
    }

    // Electrons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonElectrons().accepted.begin();
      i != mEv.LD_CommonElectrons().accepted.end();
      i++ ) {
      mData += (**i);
    }

    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonMuons().accepted.begin();
      i != mEv.LD_CommonMuons().accepted.end();
      i++ ) {
      mData += (**i);
    }

    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
      i != mEv.JD_CommonJets().accepted.end();
      i++ ) {
      mData += (**i);
    }
  }

  CommonSumEt::CommonSumEt(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonSumEt>(ev) {}

  void CommonSumEt::_Update() const {
    mData = 0.0;

    // Photons
    for ( std::vector<Event::Photon const *>::const_iterator i = mEv.PD_CommonPhotons().accepted.begin();
      i != mEv.PD_CommonPhotons().accepted.end();
      i++ ) {
      mData += (*i)->Et();
    }

    // Electrons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonElectrons().accepted.begin();
      i != mEv.LD_CommonElectrons().accepted.end();
      i++ ) {
      mData += (*i)->Et();
    }

    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonMuons().accepted.begin();
      i != mEv.LD_CommonMuons().accepted.end();
      i++ ) {
      mData += (*i)->Et();
    }

    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
      i != mEv.JD_CommonJets().accepted.end();
      i++ ) {
      mData += (*i)->Et();
    }
  }

  CommonRecoil::CommonRecoil(const Event::Data & ev) :
    Compute::Variable<LorentzV, CommonRecoil>(ev) {}

  void CommonRecoil::_Update() const {
    mData = mEv.CommonObjectSum();
    mData.SetPxPyPzE( -mData.Px(), -mData.Py(), -mData.Py(), mData.E() );
    //mData.SetPz(-mEv.CommonObjSum().Pz());
  }

  CommonRecoilMETJetDPhi::CommonRecoilMETJetDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, CommonRecoilMETJetDPhi>(ev) {}

  void CommonRecoilMETJetDPhi::_Update() const {
    mData = 10.0;
    for (std::vector<Event::Jet const *>::const_iterator iJ = mEv.JD_CommonJets().accepted.begin();
     iJ != mEv.JD_CommonJets().accepted.end();
     ++iJ) {
      float mydPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**iJ, mEv.CommonMHT()+(**iJ)));

      // float mydPhi = mEv.comRecoilMetdPhi(*iJ);
      if(mydPhi < mData) mData = mydPhi;
    }
  }

  BiasedCommonRecoilMETJetDPhi::BiasedCommonRecoilMETJetDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, BiasedCommonRecoilMETJetDPhi>(ev) {}

  void BiasedCommonRecoilMETJetDPhi::_Update() const {
    mData = 10.0;
    for (std::vector<Event::Jet const *>::const_iterator iJ = mEv.JD_CommonJets().accepted.begin();
     iJ != mEv.JD_CommonJets().accepted.end();
     ++iJ) {
      float mydPhi = mEv.biasedComRecoilMetdPhi(*iJ);
      if(mydPhi < mData) mData = mydPhi;
    }
  }

  LowPtBiasedCommonRecoilMETJetDPhi::LowPtBiasedCommonRecoilMETJetDPhi(const Event::Data & ev) :
    Compute::Variable<Double_t, LowPtBiasedCommonRecoilMETJetDPhi>(ev) {}

  void LowPtBiasedCommonRecoilMETJetDPhi::_Update() const {
    mData = 10.0;

    for (std::vector<Event::Jet const *>::const_iterator iJ = mEv.JD_CommonJets().accepted.begin();
     iJ != mEv.JD_CommonJets().accepted.end();
     ++iJ) {
      float mydPhi = mEv.lowPtbiasedComRecoilMetdPhi(*iJ);
      if(mydPhi < mData) mData = mydPhi;
    }
    for( std::vector<Event::Jet const*>::const_iterator iI = mEv.JD_CommonJets().baby_30_50.begin(); iI != mEv.JD_CommonJets().baby_30_50.end();
   ++iI) {
      float mydPhi_1 = mEv.lowPtbiasedComRecoilMetdPhi(*iI);
      if(mydPhi_1 < mData) mData = mydPhi_1;
    }
  }

  CommonObjects::CommonObjects(const Event::Data & ev) :
    Compute::Variable<std::vector<LorentzV>, CommonObjects>(ev) {}

  void CommonObjects::_Update() const {
    mData.clear();

    // Electrons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonElectrons().accepted.begin();
      i != mEv.LD_CommonElectrons().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }

    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonMuons().accepted.begin();
      i != mEv.LD_CommonMuons().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }

    // Photons
    for ( std::vector<Event::Photon const *>::const_iterator i = mEv.PD_CommonPhotons().accepted.begin();
    i != mEv.PD_CommonPhotons().accepted.end();
    i++ ) {
      mData.push_back(**i);
    }

    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
      i != mEv.JD_CommonJets().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }
  }

 LeptonicObjects::LeptonicObjects(const Event::Data & ev) :
    Compute::Variable<std::vector<LorentzV>, LeptonicObjects>(ev) {}

  void LeptonicObjects::_Update() const {
    mData.clear();

    // Electrons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonElectrons().accepted.begin();
      i != mEv.LD_CommonElectrons().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }

    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonMuons().accepted.begin();
      i != mEv.LD_CommonMuons().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }
    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
      i != mEv.JD_CommonJets().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }
  }

 HadronicObjects::HadronicObjects(const Event::Data & ev) :
    Compute::Variable<std::vector<LorentzV>, HadronicObjects>(ev) {}

  void HadronicObjects::_Update() const {
    mData.clear();
    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
      i != mEv.JD_CommonJets().accepted.end();
      i++ ) {
      mData.push_back(**i);
    }
  }

  

  CommonJetsAndElectrons::CommonJetsAndElectrons(const Event::Data & ev) :
    Compute::Variable<std::vector<LorentzV>, CommonJetsAndElectrons>(ev) {}

  void CommonJetsAndElectrons::_Update() const {
    mData.clear();

    // Electrons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonElectrons().accepted.begin();
	  i != mEv.LD_CommonElectrons().accepted.end();
	  i++ ) {
      mData.push_back(**i);
    }

    /*
    // Photons
    for ( std::vector<Event::Photon const *>::const_iterator i = mEv.PD_CommonPhotons().accepted.begin();
    i != mEv.PD_CommonPhotons().accepted.end();
    i++ ) {
      mData.push_back(**i);
    }
    */

    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
	  i != mEv.JD_CommonJets().accepted.end();
	  i++ ) {
      mData.push_back(**i);
    }
  }



  CommonJetsAndMuons::CommonJetsAndMuons(const Event::Data & ev) :
    Compute::Variable<std::vector<LorentzV>, CommonJetsAndMuons>(ev) {}

  void CommonJetsAndMuons::_Update() const {
    mData.clear();

    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = mEv.LD_CommonMuons().accepted.begin();
	  i != mEv.LD_CommonMuons().accepted.end();
	  i++ ) {
      mData.push_back(**i);
    }

    // Jets
    for ( std::vector<Event::Jet const *>::const_iterator i = mEv.JD_CommonJets().accepted.begin();
	  i != mEv.JD_CommonJets().accepted.end();
	  i++ ) {
      mData.push_back(**i);
    }
    //    sort(mData.begin(),     mData.end(),     KinSuite::Compare);
    sort(mData.begin(),     mData.end(),     KinSuite::Compare);
  }



  M3::M3(const Event::Data & ev) :
    Compute::Variable<Double_t, M3>(ev) {}

  void M3::_Update() const {

    if (mEv.JD_CommonJets().accepted.size()>=3) {

      TLorentzVector jet1;  TLorentzVector jet2; TLorentzVector jet3;
      jet1.SetPxPyPzE(mEv.JD_CommonJets().accepted[0]->Px(),mEv.JD_CommonJets().accepted[0]->Py(),mEv.JD_CommonJets().accepted[0]->Pz(),mEv.JD_CommonJets().accepted[0]->E());
      jet2.SetPxPyPzE(mEv.JD_CommonJets().accepted[1]->Px(),mEv.JD_CommonJets().accepted[1]->Py(),mEv.JD_CommonJets().accepted[1]->Pz(),mEv.JD_CommonJets().accepted[1]->E());
      jet3.SetPxPyPzE(mEv.JD_CommonJets().accepted[2]->Px(),mEv.JD_CommonJets().accepted[2]->Py(),mEv.JD_CommonJets().accepted[2]->Pz(),mEv.JD_CommonJets().accepted[2]->E());

      mData = (jet1 + jet2 + jet3).M();

    } else { mData = -999.; }

  }



  Razor_MR::Razor_MR(const Event::Data & ev) :
    Compute::Variable<Double_t, Razor_MR>(ev) {}
  
  void Razor_MR::_Update() const {
    std::vector<bool> pseudo;
    double razor = Razor()( mEv.CommonJetsAndElectrons(), pseudo, mEv.PFMET(), true );
      
    mData = razor;
  }


  Razor_MRt::Razor_MRt(const Event::Data & ev) :
    Compute::Variable<Double_t, Razor_MRt>(ev) {}
  
  void Razor_MRt::_Update() const {
    std::vector<bool> pseudo;
    double razor = Razor()( mEv.CommonJetsAndElectrons(), pseudo, mEv.PFMET(), false );
      
    mData = razor;
  }






WeightProducer::WeightProducer(const Event::Data & ev) :
    Compute::Variable<double, WeightProducer>(ev) {}

void WeightProducer::Init(double required_lumi,
                     const std::vector<double> & xcs,
                     const std::vector<int> & evts,
                     const std::vector<double> & ptbins)
{
  // if(!mEv.pthat.enabled())
  //   throw std::ind_argument("Ntuple does not contain pthat branch. Cannot use WeightProducer.");
  double target_lumi = (required_lumi > 0) ? required_lumi : 100;
  mPtBins=ptbins;
  mEventsPerBin=evts;
  mCrossSections=xcs;
  double lumi=0;
  int idx=0;
  for(std::vector<double>::iterator ii=mPtBins.begin();
      ii!=mPtBins.end();
      ++ii,++idx){
    lumi+=mEventsPerBin[idx]/mCrossSections[idx];
    mWeights.push_back(target_lumi/lumi);
  }
}

void WeightProducer::_Update() const{
  try {
    if(mEv.pthat() < mPtBins[0]) mData=0;
    else mData=mWeights[std::lower_bound(mPtBins.begin(),mPtBins.end(),mEv.pthat())-mPtBins.begin()-1];
  }
  catch(std::exception & e){
    std::cout << "[FIXME] Error reading genpthat branch from ntuple. This should be fixed. Continuing." << std::endl;
    mData=0;
  }

}

std::ostream & WeightProducer::Output(std::ostream & ostrm) const
{
    for (unsigned int i=0; i < mPtBins.size(); i++)
    {
    if (i != mPtBins.size() - 1)
    {
        ostrm << "ptmin: " << mPtBins[i] << ",  pthatmax: " << mPtBins[i+1] << ",  weight: " << mWeights[i] << std::endl;
    }else{
        ostrm << "ptmin: " << mPtBins[i] << ",  pthatmax: inf,  weight: " << mWeights[i] << std::endl;
    }
    }
    return ostrm;
}

EventWeight::EventWeight(const Event::Data & ev):
Compute::Variable<double, EventWeight>(ev) {}

void EventWeight::Init(const std::string mode,
                       double desired_lumi,
                       double cross_section,
                       double weight,
                       int nevents,
                       bool use_weight_producer,
                       EventWeight::FilterList & filters){
  if(desired_lumi >= 0) mDesiredLumi = desired_lumi;
  else mDesiredLumi = 100.;
  mCrossSection = cross_section;
  mNEvents = nevents;

  if(mode == "mSuGra") mMode = EventWeight::MSUGRA;
  else if(mode == "Ntuple") mMode = EventWeight::NTUPLE;
  else if(mode == "User"){
    if(weight >= 0){
      mMode = EventWeight::CONSTANT;
      mWeight = weight;
    }
    else if(use_weight_producer) mMode = EventWeight::PRODUCER;
    else if(mNEvents > 0){
      mMode = EventWeight::NEVENTS;
      mWeight = mCrossSection*mDesiredLumi/mNEvents;
    }
    else{
      mMode = EventWeight::USER;
      mWeight = mCrossSection*mDesiredLumi*mEv.GetUserEventWeight();
    }
  }
  else throw std::invalid_argument("Invalid weight mode");
  weight_proc.AddFilters(filters, "Weight");
}

void EventWeight::_Update() const{
  switch(mMode){
    case EventWeight::NTUPLE:
      mData = mEv.GetStoredEventWeight();
      break;
    case EventWeight::MSUGRA://10 000 events per point
      try{
        mData = mEv.GetSusyCrossSection()*mDesiredLumi/10000;
      }
      catch(std::exception & e){
        std::cout
            << "[FIXME] Error reading susyCrossSection branch from ntuple.\n"
            << "This should be fixed. Continuing." << std::endl;
        mData = 0;
      }
      break;
    case EventWeight::USER:
    case EventWeight::NEVENTS:
    case EventWeight::CONSTANT:
      mData = mWeight;
      break;
    case EventWeight::PRODUCER:
      mData = mEv.WeightProducer();
    default:
      throw std::invalid_argument("Invalid weight mode");
  }
  if(weight_proc.Enabled()) weight_proc.Apply(&mData);
}

std::ostream &  EventWeight::Print(std::ostream & ostrm){
  switch(mMode){
    case EventWeight::NTUPLE:
      ostrm << "Event weights will be taken from the ntuple.";
      break;
    case EventWeight::MSUGRA:
      ostrm << "mSuGra Event weights will be used";
      ostrm << "Need still to be normalized to event number per m0-m1/2 bin. Lumi ";
      ostrm << mDesiredLumi << "pb^-1." << std::endl;
      break;
    case EventWeight::USER:
      ostrm <<  "Event weights will be calculated for the number of events in the ntuple. ";
      ostrm << "Weighted to ";
      ostrm << mDesiredLumi << "pb^-1.";
      break;
    case EventWeight::NEVENTS:
      ostrm << "Event weights will be calculated for constant number of events: " << mNEvents;
      ostrm << ". Weighted to ";
      ostrm << mDesiredLumi << "pb^-1. ";
      ostrm << "Weight = " << mWeight << ".";
      break;
    case EventWeight::PRODUCER:
      ostrm << "Overlapping event weights will be calculated. ";
      ostrm << "Weighted to ";
      ostrm << mDesiredLumi << "pb^-1.";
      mEv.WeightProducer.Output(ostrm);
      break;
    case EventWeight::CONSTANT:
      ostrm << "Event weights will be set to constant value: " << mWeight << ".";
  }
  return ostrm;
}

} // ~namespace Compute
