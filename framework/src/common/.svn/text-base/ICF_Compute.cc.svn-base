#include "Compute_Helpers.hh"
#include <stdexcept>
#include "Utils.hh"
//#include "EventData.hh"
#include "ICF_Compute.hh"
#include "GenObject.hh"
#include "Photon.hh"
#include "Lepton.hh"
#include "ICF_NtupleData.hh"

namespace ICF{


  Electrons::Electrons(const ICF::NtupleData & ev) :
  Compute::Variable<std::vector<Event::Lepton> ,
    Electrons,ICF::NtupleData>(ev) {}

  void Electrons::_Update() const {
    mData.clear();
    int idx=0;
    if(mEv.electronP4()->size() != mEv.electronCharge()->size()){
      std::cout << mEv.EventNumber() << std::endl;
      std::cout << mEv.electronP4()->size() << " " << mEv.electronCharge()->size()<<std::endl;
    }
    for(std::vector<ICF_LorentzV>::const_iterator ii= mEv.electronP4()->begin();
    ii!=mEv.electronP4()->end(); ++ii,++idx){
      Event::Lepton el(*ii,
        (double)mEv.electronCharge()->at(idx),
        mEv.electronTrkIso03()->at(idx),
        mEv.electronEcalIso03()->at(idx),
        mEv.electronHcalIso03()->at(idx),
        mEv.electronIDLoose()->at(idx),
        mEv.electronIDTight()->at(idx),
        1,
        idx);
      mData.push_back(el);
    }
  }

  Muons::Muons(const ICF::NtupleData &ev) :
  Compute::Variable<std::vector<Event::Lepton> , Muons,ICF::NtupleData>(ev){}


  void Muons::_Update() const{
    mData.clear();
    int idx=0;
    for(std::vector<ICF_LorentzV >::const_iterator ii= mEv.muonP4()->begin();
    ii!=mEv.muonP4()->end(); ++ii,++idx){
      Event::Lepton mu(*ii,
        (double)mEv.muonCharge()->at(idx),
        mEv.muonTrkIso()->at(idx),
        mEv.muonEcalIso()->at(idx),
        mEv.muonHcalIso()->at(idx),
        mEv.muonIDLoose()->at(idx),
        mEv.muonIDTight()->at(idx),
        2,
        idx);
      mData.push_back(mu);
    }

  }
  //MICHELE ->Secondary Muon Collection
  SecMuons::SecMuons(const ICF::NtupleData &ev) :
  Compute::Variable<std::vector<Event::Lepton> , SecMuons,ICF::NtupleData>(ev){}


  void SecMuons::_Update() const{
    mData.clear();
    int idx=0;
    for(std::vector<ICF_LorentzV >::const_iterator ii= mEv.secMuonP4()->begin();
    ii!=mEv.secMuonP4()->end(); ++ii,++idx){
      Event::Lepton mu(*ii,
        (double)mEv.secMuonCharge()->at(idx),
        mEv.secMuonTrkIso()->at(idx),
        mEv.secMuonEcalIso()->at(idx),
        mEv.secMuonHcalIso()->at(idx),
           0.,0.,

           //       mEv.secMuonIDLoose()->at(idx),
           //        mEv.secMuonIDTight()->at(idx),
        2,
        idx);
      mData.push_back(mu);
    }

  }
  //MICHELE ->Secondary Muon Collection
  Taus::Taus(const ICF::NtupleData &ev) :
  Compute::Variable<std::vector<Event::Lepton> , Taus,ICF::NtupleData>(ev){}

  void Taus::_Update() const{
    mData.clear();
    int idx=0;
    for(std::vector<ICF_LorentzV>::const_iterator ii= mEv.tauP4()->begin();
    ii!=mEv.tauP4()->end(); ++ii,++idx){
      Event::Lepton tau(*ii,mEv.tauCharge()->at(idx),
			0.,
			0.,
			0.,
			//        mEv.tauTrkIso()->at(idx),
			//        mEv.tauEcalIso()->at(idx),
			//        mEv.tauHcalIso()->at(idx),
      //  true,
      //  true,
      //  mEv.tauIDLoose()->at(idx),
      0,
      //  mEv.tauIDTight()->at(idx),
      0,
  3,
        idx);
      mData.push_back(tau);
    }
  }

  SecTaus::SecTaus(const ICF::NtupleData &ev) :
    Compute::Variable<std::vector<Event::Lepton> , SecTaus,ICF::NtupleData>(ev){}

  void SecTaus::_Update() const{
    mData.clear();
    int idx=0;
    for(std::vector<ICF_LorentzV>::const_iterator ii= mEv.secTauP4()->begin();
    ii!=mEv.secTauP4()->end(); ++ii,++idx){
      Event::Lepton tau(*ii,mEv.secTauCharge()->at(idx),
			0.,
			0.,
			0.,
			//        mEv.tauTrkIso()->at(idx),
			//        mEv.tauEcalIso()->at(idx),
			//        mEv.tauHcalIso()->at(idx),
      //  true,
      //  true,
      //  mEv.tauIDLoose()->at(idx),
      0,
      //  mEv.tauIDTight()->at(idx),
      0,
  3,
        idx);
      mData.push_back(tau);
    }
  }

// Photons and jets are wrong atm (? This should be explained)
  Photons::Photons(const ICF::NtupleData &ev) :
  Compute::Variable<std::vector<Event::Photon> , Photons,ICF::NtupleData>(ev){}

  void Photons::_Update() const{
    mData.clear();
    int idx=0;
    for(std::vector<ICF_LorentzV>::const_iterator ii= mEv.photonP4()->begin();
    ii!=mEv.photonP4()->end(); ++ii,++idx){
      Event::Photon phot(*ii,
        mEv.photonEcalRecHitSumEtConeDR04()->at(idx),
        mEv.photonHcalDepth1TowSumEtConeDR04()->at(idx) + mEv.photonHcalDepth2TowSumEtConeDR04()->at(idx),
        mEv.photonTrkSumPtHollowConeDR04()->at(idx),
        mEv.photonHadronicOverEm()->at(idx),
        mEv.photonHasPixelSeed()->at(idx),
        mEv.photonR9()->at(idx),
        mEv.photonSuperClusterEnergy()->at(idx),
        mEv.photonSigmaIetaIeta()->at(idx),
        //mEv.photonSuperClusterPhiWidth()->at(idx),
        //mEv.photonSuperClusterEtaPhiWidth()->at(idx),
        //mEv.photonSuperClusterNXtals()->at(idx),
        //mEv.photonSwissCross()->at(idx),
        //mEv.photonE2overE9()->at(idx),
        //mEv.photonSeedTime()->at(idx),
        //mEv.photonTime2()->at(idx),
        //mEv.photonSeedEnergy()->at(idx),
        //mEv.photonEnergy2()->at(idx),
        //mEv.photonE2x2()->at(idx),
        //mEv.photonE3x3()->at(idx),
        //mEv.photonE4x4()->at(idx),
        //mEv.photonE5x5()->at(idx),
        idx);
      mData.push_back(phot);
    }
  }

  Jets::Jets(const ICF::NtupleData &ev) :
  Compute::Variable<std::vector<Event::Jet> , Jets,ICF::NtupleData>(ev),
  Uncorrectedjets(Utils::GetConfig<bool>("Ntuple.Jets.Uncorrected")) {}

  void Jets::_Update() const{
    mData.clear();
    int idx=0;
    if ( mEv.useGenJets ) {//GEN JET
      std::vector<ICF_LorentzV>::const_iterator ii = mEv.genJetP4()->begin();
      std::vector<ICF_LorentzV>::const_iterator jj = mEv.genJetP4()->end();
      for ( ; ii != jj; ++ii, ++idx ) { mData.push_back( Event::Jet( *ii, 0., idx, true, true, true ) ); }
    } else {
      bool is_pf = mEv.isPFJet;
      std::vector<ICF_LorentzV>::const_iterator ii = mEv.jetP4()->begin();
      std::vector<ICF_LorentzV>::const_iterator jj = mEv.jetP4()->end();
      for ( ; ii != jj; ++ii, ++idx ) {
        if ( !is_pf ) {//NOT PF JET
          float emf   = mEv.jetFEm()->at(idx);
          int loose   = mEv.jetLooseID()->at(idx);
          int minimal = mEv.jetMinimalID()->at(idx);
          int tight   = mEv.jetTightID()->at(idx);

          Event::Jet j( *ii, emf, idx, loose, minimal, tight );
          if(Uncorrectedjets){  j /= mEv.jetCorrFactor()->at(idx); }
          mData.push_back(j);
        } 
        else { //PF JET (updated to match NEWXC branch selection)
          float emf = -999.;
          int loose   = false;
          int minimal = true;
          int tight   = false;
          if ( mEv.jetFneutralHad()->at(idx) < 0.99 &&
               mEv.jetEMFneutral()->at(idx) < 0.99 &&
               (mEv.jetNcharged()->at(idx) + mEv.jetNneutral()->at(idx)) > 1 &&
               (fabs( ii->Eta() ) > 2.4 || //@@ if >2.4, can ignore below
                 ( mEv.jetFchargedHad()->at(idx) > 0. &&
                   mEv.jetNcharged()->at(idx) > 0. &&
                   mEv.jetEMFcharged()->at(idx) < 0.99 ) ) ) {
            loose = true;
            if ( mEv.jetFneutralHad()->at(idx) < 0.9  &&
                 mEv.jetEMFneutral()->at(idx) < 0.9 ) { 
              tight = true;
            }            
          }
          Event::Jet j( *ii, emf, idx, loose, minimal, tight );
          if(Uncorrectedjets){  j /= mEv.jetCorrFactor()->at(idx); }
          mData.push_back(j);
        }
      }
    }
  }

  //AGB - sec jets 28/10/10
  SecJets::SecJets(const ICF::NtupleData &ev) :
    Compute::Variable<std::vector<Event::Jet>, SecJets, ICF::NtupleData>(ev),
    mUncorrectedSecJets(Utils::GetConfig<bool>("Ntuple.SecJets.Uncorrected")) //<TW date="07/11/2010" />
  {}

  void SecJets::_Update() const{
    mData.clear();
    int idx=0;
    bool is_pf=mEv.secjetisPFJet;
    for(std::vector<ICF_LorentzV>::const_iterator ii=mEv.secjetP4()->begin(); ii!=mEv.secjetP4()->end(); ++ii, idx++){
      if (!is_pf){
      float emf = mEv.secjetFEm()->at(idx);
      int loose = mEv.secjetLooseID()->at(idx);
      int minimal = mEv.secjetMinimalID()->at(idx);
      int tight = mEv.secjetTightID()->at(idx);
      //mData.push_back(Event::Jet(*ii, emf, idx, loose, minimal, tight));
      Event::Jet j( *ii, emf, idx, loose, minimal, tight );
      if(mUncorrectedSecJets){  j /= mEv.secjetCorrFactor()->at(idx); }
      mData.push_back(j);
	}
      else{//PF SecJets
	float emf = -999.;
	int loose = false;
	int minimal = true;
	int tight = false;
	if ( mEv.secjetFneutralHad()->at(idx) < 0.99 &&
               mEv.secjetEMFneutral()->at(idx) < 0.99 &&
               (mEv.secjetNcharged()->at(idx) + mEv.secjetNneutral()->at(idx)) > 1 &&
               (fabs( ii->Eta() ) > 2.4 || //@@ if >2.4, can ignore below
                 ( mEv.secjetFchargedHad()->at(idx) > 0. &&
                   mEv.secjetNcharged()->at(idx) > 0. &&
                   mEv.secjetEMFcharged()->at(idx) < 0.99 ) ) ) {
            loose = true;
            if ( mEv.secjetFneutralHad()->at(idx) < 0.9  &&
                 mEv.secjetEMFneutral()->at(idx) < 0.9 ) { 
              tight = true;
            }            
          }
	    //mData.push_back(Event::Jet(*ii, emf, idx, loose, minimal, tight));
        Event::Jet j( *ii, emf, idx, loose, minimal, tight );
        if(mUncorrectedSecJets){  j /= mEv.secjetCorrFactor()->at(idx); }
        mData.push_back(j);
      }//end of PF jet check
    }//end of loop over jets
  }//end of SecJets _Update() method


  TerJets::TerJets(const ICF::NtupleData &ev) :
    Compute::Variable<std::vector<Event::Jet>, TerJets, ICF::NtupleData>(ev),
    mUncorrectedTerJets(Utils::GetConfig<bool>("Ntuple.TerJets.Uncorrected"))
  {}

  void TerJets::_Update() const{
    mData.clear();
    int idx=0;
    bool is_pf=mEv.terjetisPFJet;
    for(std::vector<ICF_LorentzV>::const_iterator ii=mEv.terjetP4()->begin(); ii!=mEv.terjetP4()->end(); ++ii, idx++){
      if (!is_pf){
      float emf = mEv.terjetFEm()->at(idx);
      int loose = mEv.terjetLooseID()->at(idx);
      int minimal = mEv.terjetMinimalID()->at(idx);
      int tight = mEv.terjetTightID()->at(idx);
      //mData.push_back(Event::Jet(*ii, emf, idx, loose, minimal, tight));
      Event::Jet j( *ii, emf, idx, loose, minimal, tight );
      if(mUncorrectedTerJets){  j /= mEv.terjetCorrFactor()->at(idx); }
      mData.push_back(j);
	}
      else{//PF TerJets
	float emf = -999.;
	int loose = false;
	int minimal = true;
	int tight = false;
	if ( mEv.terjetFneutralHad()->at(idx) < 0.99 &&
               mEv.terjetEMFneutral()->at(idx) < 0.99 &&
               (mEv.terjetNcharged()->at(idx) + mEv.terjetNneutral()->at(idx)) > 1 &&
               (fabs( ii->Eta() ) > 2.4 || //@@ if >2.4, can ignore below
                 ( mEv.terjetFchargedHad()->at(idx) > 0. &&
                   mEv.terjetNcharged()->at(idx) > 0. &&
                   mEv.terjetEMFcharged()->at(idx) < 0.99 ) ) ) {
            loose = true;
            if ( mEv.terjetFneutralHad()->at(idx) < 0.9  &&
                 mEv.terjetEMFneutral()->at(idx) < 0.9 ) { 
              tight = true;
            }            
          }
	    //mData.push_back(Event::Jet(*ii, emf, idx, loose, minimal, tight));
        Event::Jet j( *ii, emf, idx, loose, minimal, tight );
        if(mUncorrectedTerJets){  j /= mEv.terjetCorrFactor()->at(idx); }
        mData.push_back(j);
      }//end of PF jet check
    }//end of loop over jets
  }//end of TerJets _Update() method



// TODO
  MPT::MPT(const ICF::NtupleData &ev) :
  Compute::Variable<LorentzV , MPT,ICF::NtupleData>(ev){}

  void MPT::_Update() const{
    mData=LorentzV();
  }



  GenParticles::GenParticles(const ICF::NtupleData &ev) :
  Compute::Variable<std::vector<Event::GenObject> , GenParticles,ICF::NtupleData>(ev){}

  void GenParticles::_Update() const{
    if(!mEv.genHandleValid()){
      std::string e_str="Gen information not available.";
      throw std::invalid_argument(e_str);
    }
    mData.clear();
    int idx=0;
    for(std::vector<ICF_LorentzV>::const_iterator ii= mEv.genP4()->begin();
    ii!=mEv.genP4()->end(); ++ii,++idx){

      //int mother_index=-1;
      //if(mEv.genHasMother()->at(idx)) mother_index=mEv.genMother()->at(idx);
      //int mother_id=-1;
      //if(mEv.genMotherStored()->at(idx))  mother_id=mEv.genPdgId()->at(mother_index);
      //else mother_id = mother_index;

      bool hasMother, hasMotherStored;
      //look in SusyCAF_Gen.h: if the mother PDG ID is 0, then hasMother = fals
      if(mEv.genMotherPdgId()->at(idx)) hasMother = true;
      else hasMother = false;
      if(mEv.genMotherIndex()->at(idx) == -1) hasMotherStored = false;
      else hasMother = true;

      Event::GenObject gen(*ii,
         idx,
         mEv.genPdgId()->at(idx),
         mEv.genStatus()->at(idx),
         //mEv.genHasMother()->at(idx),
         hasMother,
         //mEv.genMotherStored()->at(idx),
         hasMotherStored,
         //mother_index,
         mEv.genMotherIndex()->at(idx),
         //mother_id
         mEv.genMotherPdgId()->at(idx)
         );

      mData.push_back(gen);
    }
  }

// MET variables
  AK5MET::AK5MET(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, AK5MET,ICF::NtupleData>(ev) {}

  void AK5MET::_Update() const {
    mData=LorentzV((*mEv.metP4ak5()));
  }


  CaloMET::CaloMET(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, CaloMET,ICF::NtupleData>(ev) {}

  void CaloMET::_Update() const {
    mData=LorentzV((*mEv.metP4calo()));
  }

  IC5MET::IC5MET(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, IC5MET,ICF::NtupleData>(ev) {}

  void IC5MET::_Update() const {
    mData=LorentzV((*mEv.metP4ic5()));
  }

  PFMET::PFMET(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, PFMET,ICF::NtupleData>(ev) {}

void PFMET::_Update() const {
  mData=LorentzV((*mEv.metP4pf()));
  met_proc.Apply(&mData);
}

  TCMET::TCMET(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, TCMET,ICF::NtupleData>(ev) {}

  void TCMET::_Update() const {
    mData=LorentzV((*mEv.metP4tc()));
  }

  CaloMETnohf::CaloMETnohf(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, CaloMETnohf,ICF::NtupleData>(ev) {}

  void CaloMETnohf::_Update() const {
    mData=LorentzV((*mEv.metP4nohfcalo()));
  }

  CaloMETtypeII::CaloMETtypeII(const ICF::NtupleData & ev) :
  Compute::Variable<LorentzV, CaloMETtypeII,ICF::NtupleData>(ev) {}

  void CaloMETtypeII::_Update() const {
    mData=LorentzV((*mEv.metP4caloTypeII()));
  }


}


