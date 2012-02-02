#include "CrossClean.hh"
#include <Math/VectorUtil.h>
#include <cstdlib>
namespace Compute{
  
  // 
  void KillOp::print( std::stringstream& ss ) const {
    ss << "KillCode: \"";
    ss << killCode();
    ss << "\" Indices: " << kill_idx;
    ss << " kills " << idx;
    if ( killer ) { ss << " Et/Eta/Phi: " << killer->Et() << " / " << killer->Eta() << " / " << killer->Phi(); }
  }

  // 
  void KillOp::terse( std::stringstream& ss ) const {
    ss << killerStr() 
       << " " << kill_idx
       << " kills " << killedStr()
       << " " << idx;
  }

  // 
  std::string KillOp::killCode() const {
    if      ( op == jet_kills_muon ) { return "jet_kills_muon"; }
    else if ( op == jet_kills_electron ) { return "jet_kills_electron"; }
    else if ( op == jet_kills_photon ) { return "jet_kills_photon"; }
    else if ( op == electron_kills_jet ) { return "electron_kills_jet"; }
    else if ( op == photon_kills_jet ) { return "photon_kills_jet"; }
    else if ( op == kill_jet ) { return "anonymous_kill_jet"; }
    else if ( op == kill_electron ) { return "anonymous_kill_electron"; }
    else if ( op == kill_muon ) { return "anonymous_kill_muon"; }
    else if ( op == kill_photon ) { return "anonymous_kill_photon"; }
    else if ( op == kill_none ) { return "none"; }
    else { return "unknown"; }
  }

  // 
  std::string KillOp::killerStr() const {
    if      ( op == jet_kills_muon ) { return "Jet"; }
    else if ( op == jet_kills_electron ) { return "Jet"; }
    else if ( op == jet_kills_photon ) { return "Jet"; }
    else if ( op == electron_kills_jet ) { return "Electron"; }
    else if ( op == photon_kills_jet ) { return "Photon"; }
    else if ( op == kill_jet ) { return "Anonymous"; }
    else if ( op == kill_electron ) { return "Anonymous"; }
    else if ( op == kill_muon ) { return "Anonymous"; }
    else if ( op == kill_photon ) { return "Anonymous"; }
    else if ( op == kill_none ) { return "None"; }
    else { return "unknown"; }
  }

  // 
  std::string KillOp::killedStr() const {
    if      ( op == jet_kills_muon ) { return "Muon"; }
    else if ( op == jet_kills_electron ) { return "Electron"; }
    else if ( op == jet_kills_photon ) { return "Photon"; }
    else if ( op == electron_kills_jet ) { return "Jet"; }
    else if ( op == photon_kills_jet ) { return "Jet"; }
    else if ( op == kill_jet ) { return "Jet"; }
    else if ( op == kill_electron ) { return "Electron"; }
    else if ( op == kill_muon ) { return "Muon"; }
    else if ( op == kill_photon ) { return "Photon"; }
    else if ( op == kill_none ) { return "None"; }
    else { return "unknown"; }
  }

/* Reset the state of the cross-cleaner
 * Called before each event is to be processed.
 */
void CrossCleaner::Reset(){
  mKillMap.clear();
}

/* Performs the cross-cleaning logic.
 * NOTE: This function does not actually alter the relevant objects.
 * For each cross-cleaning operation required a KillOp object is inserted
 * into the KillMap. This maps the LorentzV* of the object to be killed to
 * the KillOp data structure. This includes the LorentzV* of the object
 * which has killed it, the type of the kill operation (e.g. jet_kills_muons)
 * and the index of the pointer to the object in its array.
 */
void CrossCleaner::Clean(){
  if ( verbose_ ) std::cout << "[CrossCleaner::Clean]" << std::endl;

  if ( verbose_ )
    std::cout << "SIZE"
	      << " Jets: " << int( mJets.end() - mJets.begin() )
	      << " Muons: " << int( mMuons.end() - mMuons.begin() )
	      << " Electrons: " << int( mElectrons.end() - mElectrons.begin() )
	      << " Photons: " << int( mPhotons.end() - mPhotons.begin() )
	      << std::endl;

  double dr=0;
  for(std::vector<const Event::Jet*>::const_iterator ij=mJets.begin();
      ij!=mJets.end();
      ++ij){
    if(!*ij) continue;

    if ( verbose_ ) std::cout << "JET: "
	      << " Id: " << (*ij)->GetIndex()
	      << " Ptr: " << *ij
	      << " Pt: " << (*ij)->Pt()
	      << " eta: " << (*ij)->eta()
	      << " phi: " << (*ij)->phi()
	      << " EMF: " << (*ij)->GetEmFrac()
	      <<std::endl;

    if(mMuonJet){
      for(std::vector<const Event::Lepton*>::const_iterator imu=mMuons.begin();
          imu!=mMuons.end();
          ++imu){
        if(!*imu) continue;  // If this has already been filtered, ignore
        dr=fabs(ROOT::Math::VectorUtil::DeltaR(**ij,**imu));
        //if(dr >= 0.5) continue;                // TW - commented out hard-coded version.
        if(dr >= mMuonJetDeltaR) continue;       // TW - now set from config.
        //bool isolation=((*imu)->Pt()<30) ?     // TW - commented out hard-coded version.
        bool isolation=((*imu)->Pt()<mMuonIsoTypePtCutoff) ?
            (*imu)->GetTrkIsolation() < mMuTrkIsoCut :
            (*imu)->GetCombIsolation() < mMuCombIsoCut;
        if ( verbose_ ) 
	  std::cout << " MUON: "
		    << " Id: " << (*imu)->GetIndex()
		    << " Ptr: " << *imu
		    << " Pt: " << (*imu)->Pt()
		    << " eta: " << (*imu)->eta()
		    << " phi: " << (*imu)->phi()
		    << " Delta R: " << dr
		    << " TrkIso: " << (*imu)->GetTrkIsolation()
		    << " CombIso: " << (*imu)->GetCombIsolation()
		    << " TrkIsoCut: " << mMuTrkIsoCut
		    << " AllIsoCut: " << mMuCombIsoCut
		    << " iso: " << isolation
		    << std::endl;
				//
				// If the muon is isolated, or it isn't "tight" (however this is defined)
				// we skip the muon and do nothing further. The only reason we should
				// kill a muon overlapping a jet is if it is ((NOT isolated) AND (is tight)),
				// in which case we want to add it to the jet by modifying the jet
				// energy. In general, muons should be left alone for "odd" vetoes to
				// pick up.
				//
        if( isolation || (!(*imu)->GetTightId()) ) continue;
        const LorentzV* v1=(const LorentzV*)(*imu);
        const LorentzV* v2=(const LorentzV*)(*ij);
	      if ( verbose_ ) std::cout << "  Jet id " << (*ij)->GetIndex() << " kills muon id " << (*imu)->GetIndex() << std::endl;
        mKillMap[v1]=KillOp(v2,jet_kills_muon,imu-mMuons.begin(),ij-mJets.begin());
      }
    }

    if(mElectronJet){
      for(std::vector<const Event::Lepton*>::const_iterator iel=mElectrons.begin();
          iel!=mElectrons.end();
          ++iel){
        if(!*iel) continue;
        dr=fabs(ROOT::Math::VectorUtil::DeltaR(**ij,**iel));
        //if(dr>=0.5) continue;                              // TW - commented out hard-coded value.
        if(dr>=mElJetDeltaR) continue;                       // TW - made configurable.
        //bool isolation=((*iel)->Pt()<30) ?                 // TW - commented out hard-coded value.
        bool isolation=((*iel)->Pt() < mElIsoTypePtCutoff) ? // TW - made configurable.
            (*iel)->GetTrkIsolation() < mElTrkIsoCut :
            (*iel)->GetCombIsolation() < mElCombIsoCut;
        if ( verbose_ ) 
	  std::cout << " ELEC: "
		    << " Id: " << (*iel)->GetIndex()
		    << " Ptr: " << *iel
		    << " Pt: " << (*iel)->Pt()
		    << " eta: " << (*iel)->eta()
		    << " phi: " << (*iel)->phi()
		    << " Delta R: " << dr
		    << " TrkIso: " << (*iel)->GetTrkIsolation()
		    << " CombIso: " << (*iel)->GetCombIsolation()
		    << " TrkIsoCut: " << mElTrkIsoCut
		    << " AllIsoCut: " << mElCombIsoCut
		    << " iso: " << isolation
		    << std::endl;
				//
				// Note: there is no ID requirement on the electron for object-killing purposes...
				//
				if ( (((*iel)->GetLooseId() && mElLooseIdRequired) || !mElLooseIdRequired ) && 
						 (((*iel)->GetTightId() && mElTightIdRequired) || !mElTightIdRequired )    ) {
          if(isolation){
            const LorentzV* v1=(const LorentzV*)(*ij);
            const LorentzV* v2=(const LorentzV*)(*iel);
            if ( verbose_ ) std::cout << "  Electron id " << (*iel)->GetIndex() << " kills jet id " << (*ij)->GetIndex() << std::endl;
            mKillMap[v1]=KillOp(v2,electron_kills_jet,ij-mJets.begin(),iel-mElectrons.begin());
          }
          if(!isolation ){
            const LorentzV* v1=(const LorentzV*)(*iel);
            const LorentzV* v2=(const LorentzV*)(*ij);
            if ( verbose_ ) std::cout << "  Jet id " << (*ij)->GetIndex() << " kills electron id " << (*iel)->GetIndex() << std::endl;
            mKillMap[v1]=KillOp(v2,jet_kills_electron,iel-mElectrons.begin(),ij-mJets.begin());
          }
        } else {//electron fails an ID check when one is required (using photon approach...)
          const LorentzV* v1=(const LorentzV*)(*iel);
          const LorentzV* v2=(const LorentzV*)(*ij);
          if ( verbose_ ) std::cout << "  Jet id " << (*ij)->GetIndex() << " kills electron id " << (*iel)->GetIndex() << std::endl;
          mKillMap[v1]=KillOp(v2,jet_kills_electron,iel-mElectrons.begin(),ij-mJets.begin());
				}//end of ID checks
			}
    }

    if(mPhotonJet){
      for(std::vector<const Event::Photon*>::const_iterator iph=mPhotons.begin();
          iph!=mPhotons.end();
          ++iph){
        if(!*iph) continue;
        dr=fabs(ROOT::Math::VectorUtil::DeltaR(**ij,**iph));
        //if(dr>=0.5) continue;            // TW commented out hard-coded value.
        if(dr>=mPhotonJetDeltaR) continue; // TW added
        //bool isolation=((*iph)->Et()<30) ? // TW commented out hard-coded value.
        bool isolation=((*iph)->Et()<mPhotonIsoTypePtCutoff) ?
          (*iph)->trkSumPtHollowConeDR04() < mPhotonTrkIsoCut :
	      ( ((*iph)->GetEcalIsolation() + (*iph)->GetHcalIsolation()) ) < mPhotonCaloIsoCut;
        if ( verbose_ ) 
	  std::cout << " PHOT: "
		    << " Id: " << (*iph)->GetIndex()
		    << " Ptr: " << *iph
		    << " Et: " << (*iph)->Et()
		    << " eta: " << (*iph)->eta()
		    << " phi: " << (*iph)->phi()
		    << " Delta R: " << dr
		    << " TrkIso: " << (*iph)->GetTrackIsolation()
		    << " CaloIso: " << (*iph)->GetEcalIsolation() + (*iph)->GetHcalIsolation()
		    << " TrkIsoCut: " << mPhotonTrkIsoCut
		    << " CaloIsoCut: " << mPhotonCaloIsoCut
        << " ID: " << (*iph)->GetIntID()
        << " IDCut: " << mPhotonIDReq
		    << " iso: " << isolation
		    << std::endl;
  if ( mPhotonUseID ) {
	  if ( int( (*iph)->GetIntID() ) >= mPhotonIDReq ) {
	    const LorentzV* v1=(const LorentzV*)(*ij);
	    const LorentzV* v2=(const LorentzV*)(*iph);
	    if ( verbose_ ) std::cout << "  Photon id " << (*iph)->GetIndex() <<" kills jet id " << (*ij)->GetIndex() << std::endl;
	    mKillMap[v1]=KillOp(v2,photon_kills_jet,ij-mJets.begin(),iph-mPhotons.begin());
    } else {
	    const LorentzV* v1=(const LorentzV*)(*iph);
	    const LorentzV* v2=(const LorentzV*)(*ij);
	    if ( verbose_ ) std::cout << "  Jet id " << (*ij)->GetIndex() << " kills photon id " << (*iph)->GetIndex() << std::endl;
	    mKillMap[v1]=KillOp(v2,jet_kills_photon,iph-mPhotons.begin(),ij-mJets.begin());
    }
  } else {
	  if(isolation){
	    const LorentzV* v1=(const LorentzV*)(*ij);
	    const LorentzV* v2=(const LorentzV*)(*iph);
	    if ( verbose_ ) std::cout << "  Photon id " << (*iph)->GetIndex() <<" kills jet id " << (*ij)->GetIndex() << std::endl;
	    mKillMap[v1]=KillOp(v2,photon_kills_jet,ij-mJets.begin(),iph-mPhotons.begin());
	  } else {
	    const LorentzV* v1=(const LorentzV*)(*iph);
	    const LorentzV* v2=(const LorentzV*)(*ij);
	    if ( verbose_ ) std::cout << "  Jet id " << (*ij)->GetIndex() << " kills photon id " << (*iph)->GetIndex() << std::endl;
	    mKillMap[v1]=KillOp(v2,jet_kills_photon,iph-mPhotons.begin(),ij-mJets.begin());
	  }
  }
      }
    }
  }
}

/* Resolve the kill map to remove kill chains.
 * The KillMap may contain cases like:
 *
 *    +------+       +------+       +------+
 *    | ele  +------>+ jet  +------>+ muon |
 *    |      |       |      |       |      |
 *    +------+       +------+       +------+
 *
 * Or even a circular case of the above. Currently these are resolved
 * by following kill paths through the kill map and building a kill_chain.
 * This kill_chain (relating n objects) is then iterated through from start to
 * (n-2). Each kill is changed from a killer specific type (e.g jet_kills_muon)
 * to an anonymous kill (e.g kill_muon). The killer in each case is changed to the
 * object at position n. The diagram above would be rewired to
 *
 *   +-------+         +------+     +------+
 *   |       |         | jet  |     | muon |
 *   |  ele  |         |      |     |      |
 *   |       |         +---+--+     +--+---+
 *   +--\----+             ^           ^
 *       \    \-           |           |
 *        \     -----------+           |
 *        -----------------------------+
 *
 * Currently circular kills are just removed completely.
 */
void CrossCleaner::Resolve(){
  if ( verbose_ ) std::cout << "[CrossCleaner::Resolve]" << std::endl;

  if ( verbose_ ) {
    std::stringstream pre;
    pre << "PRE: " << std::endl;
    std::map<const LorentzV*,KillOp>::iterator ii=mKillMap.begin();
    std::map<const LorentzV*,KillOp>::iterator jj=mKillMap.end();
    for ( ; ii != jj; ++ii ) { ii->second.print(pre); pre << std::endl; }
    std::cout << pre.str() << std::endl;
  }

  for(std::map<const LorentzV*,KillOp>::iterator kill=mKillMap.begin();
      kill!=mKillMap.end();
      ++kill){
    std::map<const LorentzV*,KillOp>::iterator suspect=kill;
    bool satisfied=(mKillMap.count(suspect->second.killer)==0);
    bool circular=false;
    std::vector<const LorentzV*> kill_chain;
    while(!satisfied){
      if ( verbose_ ) std::cout << "Conflicts found" << std::endl;
      kill_chain.push_back(suspect->first);
      circular= (suspect->second.killer==kill->first);
      satisfied=(mKillMap.count(suspect->second.killer) == 0) || circular;
      suspect=mKillMap.find(suspect->second.killer);
    }
    // 1 or 2 items in kill chain => ignore
    if(kill_chain.size()<=1) continue;
    // Circular kill chain => Delete everything
    if(circular){
      for(std::vector<const LorentzV*>::iterator it=kill_chain.begin();
          it!=kill_chain.end();++it){
        mKillMap.erase(*it);
      }
    }
    else{
      if ( verbose_ ) std::cout << "Rewiring kill-chain" << std::endl;
      std::map<const LorentzV*,KillOp>::iterator
          kill_it=mKillMap.find(*(kill_chain.end()-2));
      for(std::vector<const LorentzV*>::iterator it=kill_chain.begin();
          it!=kill_chain.end()-1;++it){
        std::map<const LorentzV*,KillOp>::iterator obj=mKillMap.find(*it);
        obj->second.op=anonymous_kill(obj->second.op);
        obj->second.killer=kill_it->second.killer;
        obj->second.kill_idx=kill_it->second.kill_idx;
      }
    }
  }

  if ( verbose_ ) {
    std::stringstream post;
    post << "POST: " << std::endl;
    std::map<const LorentzV*,KillOp>::iterator iii=mKillMap.begin();
    std::map<const LorentzV*,KillOp>::iterator jjj=mKillMap.end();
    for ( ; iii != jjj; ++iii ) { iii->second.print(post); post << std::endl; }
    std::cout << post.str() << std::endl;
  }

}

/* Executes the kill operations
 * The killmap has previously been filled in the Clean method
 * and then filtered in the Resolve method. This step "removes"
 * objects from the relevant arrays and performs kinematic corrections.
 * Note that in order to not screw up the array indexing, objects are not
 * removed from the array but the pointer is simply set null. This also
 * allows one-to-one matching with the original un xcleaned array.
 */
  void CrossCleaner::Execute(){
    if ( verbose_ ) std::cout << "[CrossCleaner::Execute]" << std::endl;
    std::vector<const Event::Jet*>::iterator jetc;
    Event::Jet* jet;
    std::vector<const Event::Lepton*>::iterator lepc;
    std::vector<const Event::Photon*>::iterator phoc;
    for(std::map<const LorentzV*,KillOp>::iterator kill=mKillMap.begin();
	kill!=mKillMap.end();
	++kill){
    
      switch ( kill->second.op ) {
      
      case jet_kills_muon:
      
	jetc=mJets.begin()+kill->second.kill_idx;
	lepc=mMuons.begin()+kill->second.idx;
	if ( *(jetc) && *(lepc) ) {
	  jet=mJets.Clone(jetc);
	  if (mModifyJetEnergy) *jet += **lepc;
	  *lepc = 0;
	} else {
	  std::cout <<" NULL pointer for \"jet_kills_muon\""
		    << " jet ptr: " << *jetc 
		    << " muon ptr: " << *lepc
		    << std::endl;	
	}
	break;
      
      case kill_muon:
      
	lepc = mMuons.begin()+kill->second.idx;
	*lepc = 0;
	break;
      
      case electron_kills_jet:

	jetc = mJets.begin()+kill->second.idx;
	*jetc = 0;
	break;

      case kill_jet:

	jetc = mJets.begin()+kill->second.idx;
	*jetc = 0;
	break;

      case jet_kills_electron:

	lepc = mElectrons.begin()+kill->second.idx;
	*lepc = 0;
	break;

      case kill_electron:

	lepc = mElectrons.begin()+kill->second.idx;
	*lepc = 0;
	break;

      case photon_kills_jet:

	jetc=mJets.begin()+kill->second.idx;
	*jetc=0;
	break;

      case jet_kills_photon:

	phoc=mPhotons.begin()+kill->second.idx;
	*phoc=0;
	break;
	
      case kill_photon:
      
	phoc=mPhotons.begin()+kill->second.idx;
	*phoc=0;
	break;
      
      default:
	break;

      }
    }
  }
  
  // -----------------------------------------------------------------------------
  // Copies KillMap into a vector.
  void CrossCleaner::KillMap( std::vector<KillOp>& kills ) {
    if ( verbose_ ) std::cout << "[CrossCleaner::KillMap]" << std::endl;
    kills.clear();
    std::map<const LorentzV*,KillOp>::const_iterator ii = mKillMap.begin();
    std::map<const LorentzV*,KillOp>::const_iterator jj = mKillMap.end();
    for ( ; ii != jj; ++ii ) { kills.push_back( ii->second ); }
  }

}

