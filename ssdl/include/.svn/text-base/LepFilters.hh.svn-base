#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
using namespace Event;
namespace SSDL{

  class CustomEleId : public Compute::ObjectFilter<Event::Lepton> {
  public:
    CustomEleId(const Utils::ParameterSet & ps) :
      mIsoCombSR(ps.Get<double>("Cuts.Isolation.IsoCombSR")),
      mHoEBarrel(ps.Get<double>("Cuts.HoverE.Barrel")),
      mHoEEndcap(ps.Get<double>("Cuts.HoverE.Endcap")),
      mDeltaPhiBarrel(ps.Get<double>("Cuts.DeltaPhi.Barrel")),
      mDeltaPhiEndcap(ps.Get<double>("Cuts.DeltaPhi.Endcap")),
      mDeltaEtaBarrel(ps.Get<double>("Cuts.DeltaEta.Barrel")),
      mDeltaEtaEndcap(ps.Get<double>("Cuts.DeltaEta.Endcap")),
      mSigmaIEtaIEtaBarrel(ps.Get<double>("Cuts.SigmaIEtaIEta.Barrel")),
      mSigmaIEtaIEtaEndcap(ps.Get<double>("Cuts.SigmaIEtaIEta.Endcap")),
      mDCot(ps.Get<double>("Cuts.ConversionsExtra.DCot")),
      mDist(ps.Get<double>("Cuts.ConversionsExtra.Dist")),

      mMissingHits(ps.Get<int>("Cuts.ConversionsExtra.MissingHits")),
      mSupressErrors(ps.Contains("SupressErrors") ? ps.Get<bool>("SupressErrors") : false),
      mPUCorrections(ps.Contains("PUCorrection") ? ps.Get<bool>("PUCorrection") : false),
      mD0max(ps.Get<double>("Cuts.D0max"))

      { mModifies = false; }
    
    ~CustomEleId(){}

    
    bool Apply(const Event::Lepton* ob){
      bool passIso = false;
      bool passHoE = false;
      bool passDelta = false;
      bool passShh = false;
      bool passConv = false;
      
      bool passCharge = false;
      bool passFBrem=false;
      bool passD0=false;
      
      int iM = (ob)->GetIndex();
      int lepCharge = int((ob)->GetCharge());
      
      
      passCharge = ((lepCharge == mEv->GetElectronSCCharge(iM)) && (lepCharge == mEv->GetElectronKFCharge(iM))) ;      // these variables were missing in "old" ntuples
      passConv = (  (fabs(mEv->GetElectronDCot(iM)) > mDCot) || (fabs(mEv->GetElectronDist(iM)) > mDist )   &&
			 (mEv->GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits));	 
      passD0= (fabs(mEv->GetElectronD0(iM))< mD0max);

	 
      if (ob->Pt()>20) passFBrem=true;
      else {
         if (mEv->GetElectronFbrem(iM)>0.15) passFBrem=true; 
         else {
           if ((fabs(ob->Eta()) < 1.) && (mEv->GetElectronESuperClusterOverP(iM) >0.95)) passFBrem=true; 
           else passFBrem=false;
         }
     }

      
      float pucorr=(log(ob->Pt())*(mEv->GetVertexSize()-1))/(30*ob->Pt());
      float IsoThreshold=(mPUCorrections)? mIsoCombSR+pucorr : mIsoCombSR;
	  
      if (fabs(ob->Eta()) < 1.4442) {
	// Barrel
	passIso = ( (mEv->GetElectronTrkIso03(iM) +	max(0.,mEv->GetElectronEcalIso03(iM)-1.) + mEv->GetElectronHcalIso03(iM))/ob->Pt()< IsoThreshold);
	passHoE = ( mEv->GetElectronHoE(iM) < mHoEBarrel );
	passDelta = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel &&
		      fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
	passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );
      } 
      else if (fabs(ob->Eta()) > 1.566 ) {
	// End-caps
	passIso = ( (mEv->GetElectronTrkIso03(iM) + mEv->GetElectronEcalIso03(iM) + mEv->GetElectronHcalIso03(iM))/ob->Pt() < IsoThreshold);
	passHoE = ( mEv->GetElectronHoE(iM) < mHoEEndcap );
	passDelta = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiEndcap &&
		      fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaEndcap);
	passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaEndcap );
      } 


	
      return 
	passShh  && passDelta && passHoE && passIso && passD0 && passCharge && passConv &&passFBrem;

    }


    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom EleID: " << mName
	    << " ( supress errors = " << mSupressErrors << ")";
      return ostrm;
    }
    
  private:
    const std::string mName;
    


    //-------------------------------------------------

 
    
    double mIsoCombSR;
    double mHoEBarrel, mHoEEndcap;
    double mDeltaPhiBarrel, mDeltaPhiEndcap;
    double mDeltaEtaBarrel, mDeltaEtaEndcap;
    double mSigmaIEtaIEtaBarrel, mSigmaIEtaIEtaEndcap;
    double mDCot, mDist;
    int mMissingHits;
    bool mSupressErrors;
    std::string mDxyChoice;
    bool mPUCorrections;
    double mD0max;     
  };
  
  class CustomMuonId : public Compute::ObjectFilter<Event::Lepton> {
  public:
    CustomMuonId(const Utils::ParameterSet & ps) :
      mIsoCombSR(ps.Get<double>("Cuts.Isolation.IsoCombSR")),  
      mNumValidTrackerHits(ps.Get<int>("Cuts.NumValidTrackerHits")),
      mNumValidStandAloneHits(ps.Get<int>("Cuts.NumValidStandAloneHits")),
      mGlobalNormChi2(ps.Get<double>("Cuts.GlobalNormChi2")),
      mDxyV(ps.Get<double>("Cuts.dxyclosestzvertex")),
      mCalVetoes(ps.Contains("CaloVetoes") ? ps.Get<bool>("CaloVetoes") : true),
      mPUCorrections(ps.Contains("PUCorrection") ? ps.Get<bool>("PUCorrection") : false)
    { mModifies = false; }

    ~CustomMuonId() {}

    bool Apply(const Event::Lepton* ob){
      bool passMuonID = false;
      bool passIso =false;

      int iM = (ob)->GetIndex();
      float pucorr=(log(ob->Pt())*(mEv->GetVertexSize()-1))/(30*ob->Pt());
      float IsoThreshold=(mPUCorrections)? mIsoCombSR+pucorr : mIsoCombSR;
  
       
      if( mEv->GetMuonInnerTracknumberOfValidHits(iM) > static_cast<unsigned int>(mNumValidTrackerHits) && 
          mEv->GetMuonOuterTracknumberOfValidHits(iM) > mNumValidStandAloneHits && 
          mEv->IsMuonGlobal(iM) && mEv->IsMuonTracker(iM)  &&  
          mEv->GetMuonGlobalTrackNormChi2(iM)< mGlobalNormChi2  && 
          fabs(mEv->GetMuonInnerTrackDxy(iM)) < mDxyV) passMuonID = true;

      bool passCaloVeto = (mCalVetoes) ? 
	(  mEv->GetMuonEcalVetoDep(iM)< 4. &&
	   mEv->GetMuonHcalVetoDep(iM)< 6.) :true;
      
      passIso = ((mEv->GetMuonTrkIso03(iM) + mEv->GetMuonEcalIso03(iM) + mEv->GetMuonHcalIso03(iM))/ob->Pt()< IsoThreshold );
      return ( passMuonID && passIso && passCaloVeto);   
    }
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom MuonID " << std::endl;
      return ostrm;
    }
    
  private:
    bool mIsolationSR;
    double mIsoCombSR;
    u_int mNumValidTrackerHits;
    u_int mNumValidStandAloneHits;
    double mGlobalNormChi2;
    double mDxyV; 
    bool mCalVetoes;
    bool mPUCorrections;
  };
  
  
  
  class CustomTauId : public Compute::ObjectFilter<Event::Lepton> {
  public:
    CustomTauId(const Utils::ParameterSet & ps):
      tauSrc(ps.Get<string>("TauSource"))
 
    { mModifies = false; 
      mAgEle=ps.Get<bool>("AgainstElectron");
      mAgMu=ps.Get<bool>("AgainstMuon");
      mIso=ps.Get<int>("tauIDbyIso");
      if(tauSrc=="tauHPS"){
	mDecay=ps.Get<bool>("tauIDbyDecay");
	
      }else{
       mUseHps=ps.Get<bool>("UseHps");
      }
    }
    
    ~CustomTauId() {}
    bool Apply(const Event::Lepton* ob){
      int iM = (ob)->GetIndex();  

      bool AgEle=(mAgEle)?  mEv->IsTauAgainstElectron(iM) : true;
      bool AgMu= (mAgMu)?  mEv->IsTauAgainstMuon(iM) : true;
      if(tauSrc=="tauHPS"){
	bool isolation =true;
	if (mIso<1 || mIso>3) cout<<"ISOLATION WP NOT AVAILABLE "<<endl;
	else{
	  if (mIso==1) isolation=mEv->IsTauByLooseIso(iM);
	  if (mIso==2) isolation=mEv->IsTauByMediumIso(iM);
	  if (mIso==3) isolation=mEv->IsTauByTightIso(iM);
	}
	bool Decay=(mDecay)? mEv->IsTauByDecay(iM): true;
	
	return AgEle&&AgMu&&Decay&&isolation;
      } 
      else{
	
   
	if (mUseHps){
           bool hpsId=false;
           bool isolation=false;
           float dr=999;
           int iSec=-1;
           for(vector<Lepton>::const_iterator seclep=mEv->LD_SecTaus().begin();
               seclep!=mEv->LD_SecTaus().end();++seclep) {
              float DRRR=KS_DeltaR(*ob, *seclep);
              if (DRRR>0.2) continue;
              if (DRRR<dr){
                dr=DRRR; 
               iSec=seclep->GetIndex();
              }


           }
          if (iSec<0) return false;
          hpsId=mEv->secTauIdAgainstElectron()->at(iSec) &&
                mEv->secTauIdAgainstMuon()->at(iSec) &&
                mEv->secTauIdbyDecay()->at(iSec);
          if (mIso==1) isolation=mEv->secTauIdbyLooseIsolation()->at(iSec);
          if (mIso==2) isolation=mEv->secTauIdbyMediumIsolation()->at(iSec);
          if (mIso==3) isolation=mEv->secTauIdbyTightIsolation()->at(iSec);
          bool ChargeId=(fabs(ob->GetCharge())==1) && (int(mEv->secTauCharge()->at(iSec))==int(ob->GetCharge()));
          return AgEle&&AgMu&&hpsId&&ChargeId&&isolation;
	}else {
          bool tancId=false;
          if (mIso==1) tancId=mEv->IsTauNCfr100(iM);
	  if (mIso==2) tancId=mEv->IsTauNCfr050(iM);
	  if (mIso==3) tancId=mEv->IsTauNCfr025(iM);	
	  if (mIso==4) tancId=mEv->IsTauNCfr010(iM);
	  bool ChargeId=(fabs(ob->GetCharge())==1);
	return AgEle&&AgMu&&tancId&&ChargeId;
      }
     }
      return true;
    }
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom TauID " << std::endl;
      return ostrm;
    }
  private:
    string tauSrc;
    int mIso;
    bool mDecay;
    bool mAgEle;
    bool mAgMu;
    bool mUseHps;
  };

  
  class CustomJetId : public Compute::ObjectFilter<Event::Jet> {
  public:
    
    CustomJetId(const Utils::ParameterSet & ps):
      mConstit(ps.Get<int>("MinConstituents")),
      mEMFrac(ps.Get<double>("MaxEMFrac")),
      mHAFrac(ps.Get<double>("MaxHadFrac")),
      mChConst(ps.Get<int>("FWDMinCHConstituents")),
      mCHHAdFrac(ps.Get<double>("FWDMinCHHadFrac")),
      mCHMEMFrac(ps.Get<double>("FWDMaxCHEMFrac"))
    { mModifies = false;      
    }
    ~CustomJetId(){}

    
    bool Apply(const Event::Jet* ob){
      int iM = ob->GetIndex();
      
 
      bool isConst=(mEv->jetNcharged()->at(iM)+mEv->jetNneutral()->at(iM))>mConstit;
      bool isHaFrac=mEv->jetFneutralHad()->at(iM)<mHAFrac;
      bool isEMFrac=  mEv->jetEMFneutral()->at(iM) < mEMFrac;
      bool isHighEta= (fabs(ob->Eta())>2.4)? 
	(mEv->jetNcharged()->at(iM)>mChConst && 
	 mEv->jetFchargedHad()->at(iM)>mCHHAdFrac &&
	 mEv->jetEMFcharged()->at(iM)<mCHMEMFrac) : true;
      return isConst && isHaFrac && isEMFrac && isHighEta;
    }
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom JetID " << std::endl;
      return ostrm;
    }
 private:
    int mConstit;
    double mEMFrac;
    double mHAFrac;
    int mChConst;
    double mCHHAdFrac;
    double mCHMEMFrac;
 };
}
