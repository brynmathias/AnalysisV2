#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "Operation.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "TLorentzVector.h"


namespace LeptonCommissioning{

class EleJetDRFilter : public Compute::ObjectFilter<Event::Jet>{
 public:
  EleJetDRFilter(double drCut):
    mDRCut(drCut) { mModifies=false;}

  ~EleJetDRFilter(){}

  bool Apply(const Event::Jet* ob){
    if(mEv->LD_CommonElectrons().accepted.size()==0) return true;
    else {
      double dR=fabs(ROOT::Math::VectorUtil::DeltaR ((*ob),*(mEv->LD_CommonElectrons().accepted[0])));
      return (dR > mDRCut );

    }

  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Custom DR(e-jet) Cut > "<< mDRCut;
    return ostrm;
  }

 private:
  double mDRCut;
};


class CustomEleId : public Compute::ObjectFilter<Event::Lepton>{
 public:
  CustomEleId(const Utils::ParameterSet & ps) :
      useIso(ps.Get<bool>("useIso")),
      mIso(ps.Get<bool>("Isolation")),
      mHoE(ps.Get<bool>("HoverE")),
      mDelta(ps.Get<bool>("DeltaAtVtx")),
      mShh(ps.Get<bool>("SigmaIEtaIEta")),
      mConv(ps.Get<bool>("Conversions")),
      mCombRelIsoBarrel(ps.Get<double>("Cuts.CombRelIso.Barrel")),
      mCombRelIsoEndcap(ps.Get<double>("Cuts.CombRelIso.Endcap")),
      mHits(ps.Get<double>("Cuts.innerMissingHits")),
      mHoEBarrel(ps.Get<double>("Cuts.HoverE.Barrel")),
      mHoEEndcap(ps.Get<double>("Cuts.HoverE.Endcap")),
      mDeltaPhiBarrel(ps.Get<double>("Cuts.DeltaPhi.Barrel")),
      mDeltaPhiEndcap(ps.Get<double>("Cuts.DeltaPhi.Endcap")),
      mDeltaEtaBarrel(ps.Get<double>("Cuts.DeltaEta.Barrel")),
      mDeltaEtaEndcap(ps.Get<double>("Cuts.DeltaEta.Endcap")),
      mSigmaIEtaIEtaBarrel(ps.Get<double>("Cuts.SigmaIEtaIEta.Barrel")),
      mSigmaIEtaIEtaEndcap(ps.Get<double>("Cuts.SigmaIEtaIEta.Endcap"))
  { mModifies = false; }

  ~CustomEleId(){}


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
    bool passDelta = false;
    bool passShh = false;
    bool passConv = false;

    int iM = (ob)->GetIndex();

    // BARREL
    if (fabs(ob->Eta()) < 1.4442) {
      // Barrel
      passIso = ( ob->GetCombIsolation() < mCombRelIsoBarrel );

      passHoE = ( mEv->GetElectronHoE(iM) < mHoEBarrel );
      passDelta = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel &&
                    fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
      passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );

      // ENDCAPS
    } else if (fabs(ob->Eta()) > 1.560 ) {
      // End-caps
      passIso = ( ob->GetCombIsolation() < mCombRelIsoEndcap );

      passHoE = ( mEv->GetElectronHoE(iM) < mHoEEndcap );

      passDelta = ( ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)-dPhiCorr(ob->Phi(),ob->Eta())) < mDeltaPhiEndcap ) 
		    && ( fabs(mEv->GetElectronDeltaEtaAtVtx(iM)-dEtaCorr(ob->Phi(),ob->Eta())) < mDeltaEtaEndcap) ); 

      //      passDelta = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiEndcap
      //            &&
      //            fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaEndcap);
      passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaEndcap );

    } else { return false; }

    passConv = ( (mEv->GetElectronPartnerTrackTrackerExpectedHitsInner(iM) <= mHits) &&
      (!(fabs(mEv->GetElectronDCot(iM))<0.02) && (fabs(mEv->GetElectronDist(iM))<0.02)) );

    if (useIso) {
      return (mIso==passIso && mHoE==passHoE && mDelta==passDelta && mShh==passShh && mConv==passConv);
    } else {
      return (mHoE==passHoE && mDelta==passDelta && mShh==passShh );
    }
  //   return (mIso==passIso && mHoE==passHoE && mDelta==passDelta &&
//             mShh==passShh && mConv==passConv);
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Custom EleID " << mName << std::endl;
    return ostrm;
  }

 private:
  const std::string mName;
  bool mIso;
  bool mHoE;
  bool mDelta;
  bool mShh;
  bool mConv;
  bool useIso;

  double mHits;
  double mCombRelIsoBarrel, mCombRelIsoEndcap;
  double mHoEBarrel, mHoEEndcap;
  double mDeltaPhiBarrel, mDeltaPhiEndcap;
  double mDeltaEtaBarrel, mDeltaEtaEndcap;
  double mSigmaIEtaIEtaBarrel, mSigmaIEtaIEtaEndcap;
};

}
