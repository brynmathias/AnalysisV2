
#include "ElOpsDebug.hh"
#include "Math/VectorUtil.h"
#include "Lepton.hh"
#include "EventData.hh"

namespace WPol{

DebugElectronID::DebugElectronID(int cut_to_apply,
                                 const Utils::ParameterSet & ps,
                                 const std::string & prefix
                                 ) :
      mIso(ps.Get<bool>("Isolation")),
      mHoE(ps.Get<bool>("HoverE")),
      mDeltaEta(ps.Get<bool>("DeltaEtaAtVtx")),
      mDeltaPhi(ps.Get<bool>("DeltaPhiAtVtx")),
      mShh(ps.Get<bool>("SigmaIEtaIEta")),
      mConv(ps.Get<bool>("Conversions")),
      mConvExtra(ps.Get<bool>("ConversionsExtra")),

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
      mCorrEEMisalig(ps.Contains("CorrEEMisalig") ? ps.Get<bool>("CorrEEMisalig") : false),
      //mIDToApply(ps.Get<int>("IDToApply"))
      mIDToApply(cut_to_apply)

{}

DebugElectronID::~DebugElectronID(){}

void DebugElectronID::Start(Event::Data & ev){}

  //Based on Paolo Meridiani's corrections
float DebugElectronID::dPhiCorr(double elePhi , double eleEta){
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
float DebugElectronID::dEtaCorr(double elePhi , double eleEta){
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

bool DebugElectronID::Process(Event::Data & ev){
    const Event::Lepton* ob = ev.LD_CommonElectrons().accepted[0];
    bool passIso = false;
    bool passHoE = false;
    bool passDeltaEta = false; bool passDeltaPhi = false;
    bool passShh = false;
    bool passConv = false;
    bool passConvExtra = false;
    int iM = (ob)->GetIndex();

    //passConv = ev.GetElectronHasValidHitInFirstPixelBarrel(iM);
    try{
      passConvExtra = (fabs(ev.GetElectronDCot(iM)) > mDCot || fabs(ev.GetElectronDist(iM)) > mDist);
      passConvExtra &= (ev.GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
    }
    catch(std::invalid_argument & e){

      if(!mSupressErrors) throw e;
    }
    try{//BROKEN?!(mjarvis)
      passConvExtra &= (ev.GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
    }
    catch(std::invalid_argument & e){
      if(!mSupressErrors) throw e;
    }

    if (fabs(ob->Eta()) < 1.4442) {
      // Barrel
      passIso = ( ob->GetCombIsolation() < mRelCombIsoBarrel );
      //	      ( ob->GetTrkIsolation() < mTrkIsoBarrel &&
      //           ob->GetEcalIsolation()< mEcalIsoBarrel &&
      //           ob->GetHcalIsolation()< mHcalIsoBarrel );
      passHoE = ( ev.GetElectronHoE(iM) < mHoEBarrel );
      passDeltaPhi = ( fabs(ev.GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel );
      passDeltaEta = ( fabs(ev.GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
      passShh = ( ev.GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );
    }
    else if (fabs(ob->Eta()) > 1.560 ) {
      // End-caps
      passIso = ( ob->GetCombIsolation() < mRelCombIsoEndcap );
      //( ob->GetTrkIsolation() < mTrkIsoEndcap &&
      //        ob->GetEcalIsolation() < mEcalIsoEndcap &&
      //        ob->GetHcalIsolation() < mHcalIsoEndcap );
      passHoE = ( ev.GetElectronHoE(iM) < mHoEEndcap );
      if (mCorrEEMisalig){
        passDeltaPhi = ( fabs(ev.GetElectronDeltaPhiAtVtx(iM)-dPhiCorr(ob->Phi(),ob->Eta())) < mDeltaPhiEndcap ) ;
        passDeltaEta = ( fabs(ev.GetElectronDeltaEtaAtVtx(iM)-dEtaCorr(ob->Phi(),ob->Eta())) < mDeltaEtaEndcap);
      }
      else{
        passDeltaPhi = ( fabs(ev.GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiEndcap );
        passDeltaEta = ( fabs(ev.GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaEndcap);
      }
      passShh = ( ev.GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaEndcap );

    } else { return false; }
    bool pass[6] = {passIso, passHoE, passDeltaEta, passDeltaPhi, passShh, passConvExtra};
    return pass[mIDToApply];
  }

std::ostream & DebugElectronID::Description(std::ostream & ostrm){
    ostrm << "Debug Electron ID : " << mIDToApply;
    return ostrm;
  }

}
