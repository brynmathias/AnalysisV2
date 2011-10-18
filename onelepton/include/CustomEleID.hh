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

  class CustomEleIdRA4Sync : public Compute::ObjectFilter<Event::Lepton> {
  public:
    CustomEleIdRA4Sync(const Utils::ParameterSet & ps, const std::string & prefix = "Cuts") :
      mIso(ps.Get<int>("Isolation")),
      mHoE(ps.Get<int>("HoverE")),
      mDeltaEta(ps.Get<int>("DeltaEtaAtVtx")),
      mDeltaPhi(ps.Get<int>("DeltaPhiAtVtx")),
      mShh(ps.Get<int>("SigmaIEtaIEta")),
      mConv(ps.Get<int>("Conversions")),

      mRelCombIsoBarrel(ps.Get<double>(prefix+".RelCombIso.Barrel")),
      mRelCombIsoEndcap(ps.Get<double>(prefix+".RelCombIso.Endcap")),

      mTrkIsoBarrel(ps.Get<double>(prefix+".TrkIso.Barrel")),
      mTrkIsoEndcap(ps.Get<double>(prefix+".TrkIso.Endcap")),
      mEcalIsoBarrel(ps.Get<double>(prefix+".EcalIso.Barrel")),
      mEcalIsoEndcap(ps.Get<double>(prefix+".EcalIso.Endcap")),
      mHcalIsoBarrel(ps.Get<double>(prefix+".HcalIso.Barrel")),
      mHcalIsoEndcap(ps.Get<double>(prefix+".HcalIso.Endcap")),
      mHoEBarrel(ps.Get<double>(prefix+".HoverE.Barrel")),
      mHoEEndcap(ps.Get<double>(prefix+".HoverE.Endcap")),
      mDeltaPhiBarrel(ps.Get<double>(prefix+".DeltaPhi.Barrel")),
      mDeltaPhiEndcap(ps.Get<double>(prefix+".DeltaPhi.Endcap")),
      mDeltaEtaBarrel(ps.Get<double>(prefix+".DeltaEta.Barrel")),
      mDeltaEtaEndcap(ps.Get<double>(prefix+".DeltaEta.Endcap")),
      mSigmaIEtaIEtaBarrel(ps.Get<double>(prefix+".SigmaIEtaIEta.Barrel")),
      mSigmaIEtaIEtaEndcap(ps.Get<double>(prefix+".SigmaIEtaIEta.Endcap")),
      mDCot(ps.Get<double>(prefix+".Conversions.DCot")),
      mDist(ps.Get<double>(prefix+".Conversions.Dist")),
      mMissingHits(ps.Get<int>(prefix+".Conversions.MissingHits")),
      mSupressErrors(ps.Contains("SupressErrors") ? ps.Get<bool>("SupressErrors") : false),
      mCorrEEMisalig(ps.Contains("CorrEEMisalig") ? ps.Get<bool>("CorrEEMisalig") : false)



      { mModifies = false; }

    ~CustomEleIdRA4Sync(){}

    //Based on Paolo Meridiani's corrections
    float dPhiCorr(double elePhi , double eleEta){
      double C, D, A;
      if (eleEta>1.479){
	C = 0.0;  D = 0.52; A = 2.17;
      }
      else if (eleEta<-1.479){
	C = 0.0; D = 0.45; A = -1.58;
      }
      else return 0;
      return C + (D/325.)*sinh(eleEta)*sin(A-elePhi);
    }
    float dEtaCorr(double elePhi , double eleEta){
      double C, DZ, D, A;
      if (eleEta>1.479){
	C = 0.0013; DZ = -0.06; D = 0.52; A = 2.17;
      }
      else if (eleEta<-1.479){
	C = -0.0013; DZ = -0.32; D = 0.45; A = -1.58;
      }
      else return 0;
      return C + (tanh(eleEta)/325.)*(DZ-D*sinh(eleEta)*cos(elePhi-A));
    }

    bool Apply(const Event::Lepton* ob){
      bool passIso = false;
      bool passHoE = false;
      bool passDeltaEta = false; bool passDeltaPhi = false;
      bool passShh = false;
      bool passConv = false;
      bool passExtra = false;

      //         bool passConvExtra = false;
      int iM = (ob)->GetIndex();

      //passConv = mEv->GetElectronHasValidHitInFirstPixelBarrel(iM);
      try{
	passConv = (fabs(mEv->GetElectronDCot(iM)) > mDCot || fabs(mEv->GetElectronDist(iM)) > mDist);
	passConv &= (mEv->GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
      }
      catch(std::invalid_argument & e){

	if(!mSupressErrors) throw e;
      }

      //      if (fabs(ob->Eta()) < 1.4442) {
      if (fabs(mEv->GetElectronESuperClusterEta(iM)) < 1.4442) {

	// Barrel
	passIso = ( (((ob->GetTrkIsolation()) + max(0., ob->GetEcalIsolation()-1.) + ob->GetHcalIsolation())/(ob->Pt())) < mRelCombIsoBarrel );
	//	passIso = ( ob->GetCombIsolation() < mRelCombIsoBarrel );
	//	      ( ob->GetTrkIsolation() < mTrkIsoBarrel &&
	//           ob->GetEcalIsolation()< mEcalIsoBarrel &&
	//           ob->GetHcalIsolation()< mHcalIsoBarrel );
	passHoE = ( mEv->GetElectronHoE(iM) < mHoEBarrel );
	passDeltaPhi = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel );
	passDeltaEta = ( fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
	passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );
      }
      //      else if (fabs(ob->Eta()) > 1.560 ) {
      else if ( (fabs(mEv->GetElectronESuperClusterEta(iM)) > 1.560) && (fabs(mEv->GetElectronESuperClusterEta(iM)) < 2.5) ) {
	// End-caps
	passIso = ( ob->GetCombIsolation() < mRelCombIsoEndcap );
	//( ob->GetTrkIsolation() < mTrkIsoEndcap &&
	//        ob->GetEcalIsolation() < mEcalIsoEndcap &&
	//        ob->GetHcalIsolation() < mHcalIsoEndcap );
	passHoE = ( mEv->GetElectronHoE(iM) < mHoEEndcap );
	if (mCorrEEMisalig){
	  passDeltaPhi = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)-dPhiCorr(ob->Phi(),ob->Eta())) < mDeltaPhiEndcap ) ;
	  passDeltaEta = ( fabs(mEv->GetElectronDeltaEtaAtVtx(iM)-dEtaCorr(ob->Phi(),ob->Eta())) < mDeltaEtaEndcap);
	}
	else{
	  passDeltaPhi = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiEndcap );
	  passDeltaEta = ( fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaEndcap);
	}
	passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaEndcap );

      } else { return false; }


      try {
	// 2011 definition
	if (
	    ( fabs(mEv->GetElectronD0BS(iM)) < 0.02) &&
	    ( fabs(mEv->electronGsfTrackVertexz()->at(iM) - (mEv->GetvertexPosition(0).Z())) < 1. )
	    ) { passExtra = true; }
      }
      catch (std::invalid_argument & e) {
	// 2010 definition
	if (
	    ( fabs(mEv->GetElectronD0BS(iM)) < 0.02)
	    ) { passExtra = true; }
      }


      return (
          (mIso < 0 ? true : int(passIso) == mIso) &&
          (mHoE < 0 ? true : int(passHoE) == mHoE) &&
          (mDeltaEta < 0 ? true : int(passDeltaEta) == mDeltaEta) &&
          (mDeltaPhi < 0 ? true : int(passDeltaPhi) == mDeltaPhi) &&
          (mShh < 0 ? true : int(passShh) == mShh) &&
          (mConv < 0 ? true : int(passConv) == mConv) &&
          passExtra
              );

    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom EleID: " << mName
	    << " ( supress errrors = " << mSupressErrors << ")";
      return ostrm;
    }

  private:
    const std::string mName;
    int mIso;
    int mHoE;
    int mDeltaEta, mDeltaPhi;
    int mShh;
    int mConv;

    //      bool mConvExtra;

    double mRelCombIsoBarrel, mRelCombIsoEndcap;
    double mTrkIsoBarrel, mTrkIsoEndcap;
    double mEcalIsoBarrel, mEcalIsoEndcap;
    double mHcalIsoBarrel, mHcalIsoEndcap;
    double mHoEBarrel, mHoEEndcap;
    double mDeltaPhiBarrel, mDeltaPhiEndcap;
    double mDeltaEtaBarrel, mDeltaEtaEndcap;
    double mSigmaIEtaIEtaBarrel, mSigmaIEtaIEtaEndcap;
    double mDCot, mDist;
    int mMissingHits;
    bool mSupressErrors;
    bool mCorrEEMisalig;

  };

}
