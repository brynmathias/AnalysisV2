#include "lepvalJPsiSelection.hh"
#include "lepvalFilters.hh"

namespace lepval{

  LepValJPsiMu::LepValJPsiMu(bool applyselec, double d0, double dz, double normchi2Global, double normchi2Trk, double siTrkHits) :
    _applyselec(applyselec), _d0(d0), _dz(dz), _normchi2Global(normchi2Global), _normchi2Trk(normchi2Trk), _siTrkHits(siTrkHits){}

  LepValJPsiMu::~LepValJPsiMu(){}

  void LepValJPsiMu::_Update() const{

    mData.clear();
    
    
    for(std::vector<Event::Lepton>::const_iterator mu = mEv->LD_Muons().begin(); mu!=mEv->LD_Muons().end(); ++mu){
      if(_applyselec){
      int index=mu->GetIndex();
      LeptonD0Filter D0cut(_d0, mEv->GetBeamSpotPosition().X(), mEv->GetBeamSpotPosition().Y());
      D0cut.Init(*mEv);
      if(!D0cut.Apply(&*mu)){continue;}
      if(abs(mEv->GetMuonInnerTrackDz(index))>_dz){continue;}
      if(mEv->IsMuonGlobal(index)){
	if( (mEv->GetMuonGlobalTrackNormChi2(index) > _normchi2Global) || (mEv->GetMuonInnerTracknumberOfValidHits(index) < _siTrkHits) ){continue;}
	//the global muon selection
	// chi2/ndf < 20 (global fit)
	// num hits in silicon tracker > 12 (pixel and strip)
	mData.push_back(&*mu);
	
      }
      
      else if(mEv->IsMuonTracker(index))
	{
	  //the tracker muons selection
	  //chi2/ndf < 5 (trk fit)
	  //num hits in silicon tracker > 12 (pixel and strip)
	  //TMLastStationAngTight=true
	  if( (mEv->GetMuonInnerTrackNormChi2(index) > _normchi2Trk) || (mEv->GetMuonInnerTracknumberOfValidHits(index) < _siTrkHits) || (mEv->GetMuonTMLastStationAngTight(index)) ){continue;}
// 	  std::cout<<"InnerTrkNormChi2 and InnerTrkValHits OK"<<std::endl;
	  
	  mData.push_back(&*mu);
	  
	}

      else{continue;}
      }


      else{
	mData.push_back(&*mu);//just fill with LD_Muons if we turn off the selection
      }
      
    }
  }
  
  std::ostream & LepValJPsiMu::Description(std::ostream & ostrm){
    ostrm << "Muons satisfying J/Psi to MuMu selection" << std::endl;
    return ostrm;
  }
}
