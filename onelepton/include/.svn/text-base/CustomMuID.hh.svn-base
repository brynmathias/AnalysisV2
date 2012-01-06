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

namespace OneLepton{

  class CustomMuId : public Compute::ObjectFilter<Event::Lepton>{
  public:
    CustomMuId(float InrTrkDxyPrimVtx, int InrTrkNValidHits, int GlbTrkChi2ndf):
    mInrTrkDxyPrimVtx(InrTrkDxyPrimVtx),
      mInrTrkNValidHits(InrTrkNValidHits),
      mGlbTrkChi2ndf(GlbTrkChi2ndf)
      { mModifies=false; }

    ~CustomMuId(){}

    // 1st loop over the "raw"(Predifined) muons
    bool Apply(const Event::Lepton* ob) {

      int iM = ob->GetIndex();
      float tmpInrTrkDxyPrimVtx = 999.;
      int   tmpInrTrkNValidHits = 999;
      int tmpGlbTrkChi2ndf = 999;

      tmpInrTrkNValidHits = mEv->GetMuonInnerTracknumberOfValidHits(iM);
      tmpInrTrkDxyPrimVtx = mEv->GetMuonInnerTrackDxy(iM);
      tmpGlbTrkChi2ndf = mEv->GetMuonGlobalTrackNormChi2(iM);

      if (

        ( !(mEv->IsMuonTracker(iM)) ) ||
        ( !(mEv->IsGlobalMuonPromptTight(iM)) ) ||

        ( tmpInrTrkNValidHits < mInrTrkNValidHits )                         ||
        ( fabs(tmpInrTrkDxyPrimVtx) > mInrTrkDxyPrimVtx)                   ||
        ( tmpGlbTrkChi2ndf > mGlbTrkChi2ndf )

        )  { return false; }

      return true;

    } //~ end of: 1st loop over the "raw" muons

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "CustomMuId:" ;
      return ostrm;
    }


  private:
    float mInrTrkDxyPrimVtx;
    int mInrTrkNValidHits;
    int mGlbTrkChi2ndf;
  }; // end of class





  class CustomVBTFMuID : public Compute::ObjectFilter<Event::Lepton>{
  public:
    CustomVBTFMuID(const Utils::ParameterSet & ps) :
    mID(ps.Get<std::string>("MuID")),
      mMinPt(ps.Get<double>("MinPt")),
      mMaxEta(ps.Get<double>("MaxEta")),
      mIsolation(ps.Get<double>("MaxIsolation")),
      mDRMuJet(ps.Get<double>("DRMuJet")),
      mMaxGlbTrkDxy(ps.Get<double>("MaxGlbTrkDxy")),
      mMinGlbTrkNumOfValidHits(ps.Get<int>("MinGlbTrkNumOfValidHits")),
      mSegMatch2GlbMu(ps.Get<int>("SegMatch2GlbMu")),
      mPixelHitsOnInrTrk(ps.Get<int>("PixelHitsOnInrTrk")),
      mMaxInrTrkDz(ps.Get<double>("MaxInrTrkDz")),
      doJetLoop_(ps.Contains("doJetLoop") ? ps.Get<bool>("doJetLoop") : true )

      { mModifies=false; }

    ~CustomVBTFMuID(){}

    // 1st loop over the "raw"(Predifined) muons
    bool Apply(const Event::Lepton* ob) {

      bool id = false;
      if (mID=="Tight") { id = (mEv->IsMuonTracker(ob->GetIndex())) && (mEv->IsGlobalMuonPromptTight(ob->GetIndex())); }
      else { id = (mEv->IsMuonGlobal(ob->GetIndex())); }
      //Add a check to do jet loop or not, this solves problem with the cross cleaner.
      //      */
    
      bool muonIsTight = false;

      try {
  // new definition - 2011
        if (
          ( id )  &&
          ( ((ob->Pt()) >= mMinPt) && (fabs(ob->Eta()) <= mMaxEta) )  &&
          ( (ob->GetCombIsolation()) < mIsolation )  &&
          ( fabs(mEv->GetMuonInnerTrackDxyBS(ob->GetIndex())) <= mMaxGlbTrkDxy )  &&
          ( mEv->muonNumberOfMatches()->at(ob->GetIndex()) > mSegMatch2GlbMu )  &&
          ( mEv->muonGlobalTracknumberOfValidTrackerHits()->at(ob->GetIndex()) >= mMinGlbTrkNumOfValidHits )  &&
          ( mEv->muonNumberOfPixelLayersWithMeasurement()->at(ob->GetIndex()) >= mPixelHitsOnInrTrk )  &&
          ( ( fabs(mEv->muonInnerTrackVertexz()->at(ob->GetIndex()) - (mEv->GetvertexPosition(0).Z())) ) < mMaxInrTrkDz ) &&
	  ( mEv->muonGlobalTrackPTsigma()->at(ob->GetIndex())/(ob->Pt()*ob->Pt())< 0.001) 
          ) { muonIsTight = true; }
  // ~end of new definition - 2011
      }
      catch (std::invalid_argument & e) {
  // old definition - 2010
        if (
          ( id )  &&
          ( ((ob->Pt()) >= mMinPt) && (fabs(ob->Eta()) <= mMaxEta) )  &&
          ( (ob->GetCombIsolation()) < mIsolation )  &&
          ( fabs(mEv->GetMuonInnerTrackDxyBS(ob->GetIndex())) <= mMaxGlbTrkDxy )  &&
          ( mEv->muonNumberOfMatches()->at(ob->GetIndex()) > mSegMatch2GlbMu )  &&
          ( mEv->GetMuonInnerTracknumberOfValidHits(ob->GetIndex()) >= mMinGlbTrkNumOfValidHits )  &&
          ( mEv->muonNumberOfValidPixelHits()->at(ob->GetIndex()) >= mPixelHitsOnInrTrk ) &&
          ( ( fabs(mEv->GetMuonInnerTrackDz(ob->GetIndex()))) < mMaxInrTrkDz ) 
          ) { muonIsTight = true; }
  // ~end of old definition - 2010
      }

	int muonPFIndex =-1;
	float Drmin = 1000;
      
	for(int i = 0 ; i<mEv->secMuonP4()->size(); i++)
	  {
	  
	  
	    if( fabs(ROOT::Math::VectorUtil::DeltaR (mEv->secMuonP4()->at(i),*ob ))<Drmin){
	      Drmin=fabs(ROOT::Math::VectorUtil::DeltaR ((mEv->secMuonP4()->at(i)),*ob));
	      muonPFIndex = i;
	 	    
	    }  
	  }
      
      
	if(muonIsTight == true)
	  {

	    if(muonPFIndex!=-1)
	      {
		if(fabs(mEv->secMuonP4()->at(muonPFIndex).Pt()-ob->Pt())/ob->Pt()>0.2) muonIsTight=false;	 
	      }
	    //   else {muonIsTight=false;}
	  }


      if (muonIsTight) { return true; } else { return false; }

      return false;

    } //~ end of: 1st loop over the "raw" muons

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "CustomVBTFMuID:" ;
      return ostrm;
    }

  private:
    std::string mID;
    double mMinPt;
    double mMaxEta;
    double mIsolation;
    double mDRMuJet;
    double mMaxGlbTrkDxy;
    int mMinGlbTrkNumOfValidHits;
    int mSegMatch2GlbMu;
    int mPixelHitsOnInrTrk;
    double mMaxInrTrkDz;
    bool doJetLoop_;
    //    double mMaxGlbTrkChi2ndf;
  }; // end of class




  /*
  class MuJetDRCleaning : public Compute::ObjectFilter<Event::Lepton>{
  public:
  MuJetDRCleaning(const Utils::ParameterSet & ps, double drMin) :
  mDrMin(drMin),
  mID(ps.Get<std::string>("MuID")),
  mMinPt(ps.Get<double>("MinPt")),
  mMaxEta(ps.Get<double>("MaxEta")),
  mIsolation(ps.Get<double>("MaxIsolation")),
  mMaxGlbTrkDxy(ps.Get<double>("MaxGlbTrkDxy")),
  mMinGlbTrkNumOfValidHits(ps.Get<int>("MinGlbTrkNumOfValidHits")),
  mSegMatch2GlbMu(ps.Get<int>("SegMatch2GlbMu")),
  mPixelHitsOnInrTrk(ps.Get<int>("PixelHitsOnInrTrk")),
  mMaxInrTrkDz(ps.Get<double>("MaxInrTrkDz"))
  { mModifies=false; }

~MuJetDRCleaning(){}

// 1st loop over the "raw"(Predifined) muons
bool Apply(const Event::Lepton* ob) {

bool id = false;
if (mID=="Tight") { id = (mEv->IsMuonTracker(ob->GetIndex())) && (mEv->IsGlobalMuonPromptTight(ob->GetIndex())); }
else { id = (mEv->IsMuonGlobal(ob->GetIndex())); }

bool tightMuon = false;

if (
( id )                                                                                                        &&
( ((ob->Pt()) >= mMinPt) && (fabs(ob->Eta()) <= mMaxEta) )                                                    &&
( (ob->GetCombIsolation()) < mIsolation )                                                                     &&
( fabs(mEv->GetMuonInnerTrackDxyBS(ob->GetIndex())) <= mMaxGlbTrkDxy )                                         &&
( mEv->muonNumberOfMatches()->at(ob->GetIndex()) > mSegMatch2GlbMu )                                          &&
// old definition - 2010
//          ( mEv->GetMuonInnerTracknumberOfValidHits(ob->GetIndex()) >= mMinGlbTrkNumOfValidHits )                      &&
//          ( mEv->muonNumberOfValidPixelHits()->at(ob->GetIndex()) >= mPixelHitsOnInrTrk )                         &&
//          ( ( fabs(mEv->GetMuonInnerTrackDz(ob->GetIndex()))) < mMaxInrTrkDz )
// ~end of old definition - 2010

// new definition - 2011
( mEv->muonGlobalTracknumberOfValidTrackerHits()->at(ob->GetIndex()) >= mMinGlbTrkNumOfValidHits )  &&
( mEv->muonNumberOfPixelLayersWithMeasurement()->at(ob->GetIndex()) >= mPixelHitsOnInrTrk )         &&
( ( fabs(mEv->muonInnerTrackVertexz()->at(ob->GetIndex()) - (mEv->GetvertexPosition(0).Z())) ) < mMaxInrTrkDz )
// ~end of new definition - 2011
) { tightMuon = true; }

if (tightMuon) {

double muonComJetDRmin_ = 9999999.;
// check if there are jets in the event
if (mEv->JD_CommonJets().accepted.size()>0) {
for (std::vector<Event::Jet const *>::const_iterator iMuj = mEv->JD_CommonJets().accepted.begin();
iMuj != mEv->JD_CommonJets().accepted.end(); iMuj++) {
double tmpMuonComJetDR_ = fabs(ROOT::Math::VectorUtil::DeltaR(*ob,**iMuj));
if ( (tmpMuonComJetDR_ < muonComJetDRmin_) && (tmpMuonComJetDR_>0.1) ) { muonComJetDRmin_ = tmpMuonComJetDR_; }
} // ~ end of loop over the common Jts.
//  cout << " " << muonComJetDRmin_ << "\n";

} // end of looping over the jets

if (muonComJetDRmin_< mDrMin) { return false; }
else { return true; }

} // end of if TightMuon
else { return false; }



} //~ end of: 1st loop over the "raw" muons

std::ostream & Description(std::ostream & ostrm){
ostrm << "MuJetDRCleaning:" ;
return ostrm;
}

private:
double mDrMin;
std::string mID;
double mMinPt;
double mMaxEta;
double mIsolation;
double mMaxGlbTrkDxy;
int mMinGlbTrkNumOfValidHits;
int mSegMatch2GlbMu;
int mPixelHitsOnInrTrk;
double mMaxInrTrkDz;
//    double mMaxGlbTrkChi2ndf;
}; // end of class
*/





} //~namespace Isolation

