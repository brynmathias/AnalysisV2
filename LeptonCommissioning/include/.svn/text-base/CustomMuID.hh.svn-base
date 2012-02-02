#include "Operation.hh"
#include "EventData.hh"
#include "NtupleData.hh"
#include "Utils.hh"
#include "Math/VectorUtil.h"
#include <sstream>
#include <vector>
#include "ICF_NtupleData.hh"


using namespace Event;
using namespace ICF;

namespace LeptonCommissioning {


  class MuJetDRFilter : public Compute::ObjectFilter<Event::Jet>{
  public:
    MuJetDRFilter(float drCut, float relCombIso):
      mDRCut(drCut),
      mRelCombIso(relCombIso)
    { mModifies=false;}
    ~MuJetDRFilter(){}

    bool Apply(const Event::Jet* ob){
      if(mEv->LD_CommonMuons().accepted.size()==0) return true;
      else {
	double dR=fabs(ROOT::Math::VectorUtil::DeltaR ((*ob),*(mEv->LD_CommonMuons().accepted[0])));
	if ( (dR < mDRCut) && (mEv->LD_CommonMuons().accepted[0]->GetCombIsolation()<mRelCombIso) ) { return false; }
	//	double ratio = mEv->LD_CommonMuons().accepted[0]->Pt()/ob->Pt();
	//	if (ratio>0.7) return (dR > mDRCut );
	else return true;
      }

    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(mu-jet) Cut > "<< mDRCut;
      return ostrm;
    }

  private:
    double mDRCut;
    double mRelCombIso;
  };



  
class CustomMuId : public Compute::ObjectFilter<Event::Lepton>{
public:
    CustomMuId(float dR, float pt, float eta):
      mDR(dR),
      mPt(pt),
      mEta(eta)
    { mModifies=false; }
    
    ~CustomMuId(){}
    
    // 1st loop over the "raw"(Predifined) muons
    bool Apply(const Event::Lepton* ob) {

      int iM = ob->GetIndex();
      float tmpInrTrkDxyPrimVtx = 999.;
      int   tmpInrTrkNValidHits = 999.;
      float tmpGlbTrkChi2ndf = 999.;

      tmpInrTrkNValidHits = mEv->GetMuonInnerTracknumberOfValidHits(iM);
      tmpInrTrkDxyPrimVtx = mEv->GetMuonInnerTrackDxy(iM);
      tmpGlbTrkChi2ndf = mEv->GetMuonGlobalTrackNormChi2(iM);

      if (
	  ( !(mEv->IsMuonTracker(iM)) ) || 
	  ( !(mEv->IsGlobalMuonPromptTight(iM)) ) ||
	  //	  ( (!(ob->GetLooseId())) && (!(ob->GetTightId())) ) ||
	  ( (ob->Pt()) < mPt )                                || 
	  ( fabs(ob->Eta()) > mEta )                          ||
	  ( tmpInrTrkNValidHits < 11 )                         ||
	  ( fabs(tmpInrTrkDxyPrimVtx) > 0.2)                   ||
	  ( tmpGlbTrkChi2ndf > 10. )                          
	  )  { return false; }

      return true;
           
    } //~ end of: 1st loop over the "raw" muons
  
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "CustomMuId:" ;
      return ostrm;
    }


  private:
    float mDR;
    float mPt;
    float mEta;
    
  }; // end of class


  
} //~namespace Isolation

