#include "Utils.hh"
#include "TRandom.h"
#include "TRandom2.h"
#include "Math/VectorUtil.h"
#include "JECUnc_JetCorrectionUncertainty.hh"

namespace WPol{

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

   class LepMinIsoFilter : public Compute::ObjectFilter<Event::Lepton>{
   public:
      LepMinIsoFilter(double min_iso):
      mMinIso(min_iso){ mModifies = false; }

      ~LepMinIsoFilter(){}

      bool Apply(const Event::Lepton* lep){
         return lep->GetCombIsolation() >= mMinIso;
      }

      std::ostream & Description(std::ostream & ostrm){
         ostrm << "Lepton CombIso  >= " << mMinIso;
         return ostrm;
      }

   private:
      double mMinIso;
   };

   class CustomEleId : public Compute::ObjectFilter<Event::Lepton> {
   public:
     CustomEleId(const Utils::ParameterSet & ps, const std::string & prefix = "Cuts") :
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
      mInvertDeltaVariablesOnly(ps.Contains("InvertDeltaVariablesOnly") ? ps.Get<bool>("InvertDeltaVariablesOnly") : false)
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
         bool passDeltaEta = false; bool passDeltaPhi = false;
         bool passShh = false;
         bool passConv = false;
         bool passConvExtra = false;
         int iM = (ob)->GetIndex();

         //passConv = mEv->GetElectronHasValidHitInFirstPixelBarrel(iM);
         try{
            passConvExtra = (fabs(mEv->GetElectronDCot(iM)) > mDCot || fabs(mEv->GetElectronDist(iM)) > mDist);
	    passConvExtra &= (mEv->GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
         }
         catch(std::invalid_argument & e){

            if(!mSupressErrors) throw e;
         }
         try{//BROKEN?!(mjarvis)
             passConvExtra &= (mEv->GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
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
            passHoE = ( mEv->GetElectronHoE(iM) < mHoEBarrel );
            passDeltaPhi = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel );
	    passDeltaEta = ( fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
            passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );
         }
         else if (fabs(ob->Eta()) > 1.560 ) {
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
         if(mInvertDeltaVariablesOnly)
           return (mDeltaEta == passDeltaEta && mDeltaPhi == passDeltaPhi);
         else{
           return (mIso==passIso && mHoE==passHoE &&
                   mDeltaEta==passDeltaEta && mDeltaPhi==passDeltaPhi &&
                   mShh==passShh && mConvExtra == passConvExtra);
         }
      }

      std::ostream & Description(std::ostream & ostrm){
         ostrm << "Custom EleID: " << mName
         << " ( supress errrors = " << mSupressErrors << ")";
         return ostrm;
      }

   private:
      const std::string mName;
      bool mIso;
      bool mHoE;
      bool mDeltaEta, mDeltaPhi;
      bool mShh;
      bool mConv;
      bool mConvExtra;

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
      const bool mInvertDeltaVariablesOnly;
   };

  class CustomMuonId : public Compute::ObjectFilter<Event::Lepton> {
  public:
    CustomMuonId(const Utils::ParameterSet & ps) :
      mNumValidTrackerHits(ps.Get<int>("NumValidTrackerHits")),
      //mNumPixelHits(ps.Get<int>("NumPixelHits")),
      //mNumMatches(ps.Get<int>("NumMatches")),
      mDxyChoice(ps.Get<string>("dxychoice")),
      mDxyBS(ps.Get<double>("dxybeamspot")),
      mDxyV(ps.Get<double>("dxyclosestzvertex"))
    { mModifies = false; }//use false along with const definition below, true with non-const

    ~CustomMuonId() {}

    bool Apply(const Event::Lepton* ob) {
      //bool Apply(Event::Lepton* ob) {
      int iM = (ob)->GetIndex();

      //ob->SetPx(1.1*ob->X());
      //ob->SetPy(1.1*ob->Y());

      if(mDxyChoice != "vertex" && mDxyChoice != "beamspot") {
	std::cout << "Wrong Dxy choice specified. Options are vertex and beamspot. You chose: " << mDxyChoice << ". Please correct and try again" << std::endl;
	return false;
      }

      if( mEv->GetMuonInnerTracknumberOfValidHits(iM) > static_cast<unsigned int>(mNumValidTrackerHits) && mEv->IsMuonGlobal(iM) && mEv->IsMuonTracker(iM)) {// && mEv->muonNumberOfMatches()->at(iM) >= mNumMatches && mEv->muonNumberOfValidPixelHits()->at(iM) >= mNumPixelHits) {
	if(mDxyChoice == "vertex" && fabs(mEv->GetMuonInnerTrackDxy(iM)) < mDxyV) return true;
	if(mDxyChoice == "beamspot" && fabs(mEv->GetMuonInnerTrackDxyBS(iM)) < mDxyBS) return true;
	return false;
      } else return false;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom MuonID " << std::endl;
      return ostrm;
    }

  private:
    int mNumValidTrackerHits;
    int mNumPixelHits;
    int mNumMatches;
    std::string mDxyChoice;
    double mDxyBS;
    double mDxyV;
  };

  class CustomMuonId_latest : public Compute::ObjectFilter<Event::Lepton> {
  public:
    CustomMuonId_latest(const Utils::ParameterSet & ps) :
      mNumValidTrackerHits(ps.Get<int>("NumValidTrackerHits")),
      mNumPixelHits(ps.Get<int>("NumPixelHits")),
      mNumMatches(ps.Get<int>("NumMatches")),
      mDxyChoice(ps.Get<string>("dxychoice")),
      mDxyBS(ps.Get<double>("dxybeamspot")),
      mDxyV(ps.Get<double>("dxyclosestzvertex"))
    { mModifies = false; }//use false along with const definition below, true with non-const

    ~CustomMuonId_latest() {}

    bool Apply(const Event::Lepton* ob) {
      //bool Apply(Event::Lepton* ob) {
      int iM = (ob)->GetIndex();

      //ob->SetPx(1.1*ob->X());
      //ob->SetPy(1.1*ob->Y());

      if(mDxyChoice != "vertex" && mDxyChoice != "beamspot") {
	std::cout << "Wrong Dxy choice specified. Options are vertex and beamspot. You chose: " << mDxyChoice << ". Please correct and try again" << std::endl;
	return false;
      }

      if( mEv->GetMuonInnerTracknumberOfValidHits(iM) > static_cast<unsigned int>(mNumValidTrackerHits) && mEv->IsMuonGlobal(iM) && mEv->IsMuonTracker(iM) && mEv->muonNumberOfMatches()->at(iM) >= mNumMatches && mEv->muonNumberOfValidPixelHits()->at(iM) >= mNumPixelHits) {
	if(mDxyChoice == "vertex" && fabs(mEv->GetMuonInnerTrackDxy(iM)) < mDxyV) return true;
	if(mDxyChoice == "beamspot" && fabs(mEv->GetMuonInnerTrackDxyBS(iM)) < mDxyBS) return true;
	return false;
      } else return false;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom Muon ID Latest " << std::endl;
      return ostrm;
    }

  private:
    int mNumValidTrackerHits;
    int mNumPixelHits;
    int mNumMatches;
    std::string mDxyChoice;
    double mDxyBS;
    double mDxyV;
  };

  class pfMETsmearing : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETsmearing(const Utils::ParameterSet & ps) :
      mScale(ps.Get<bool>("scale")),
      mValue(ps.Get<double>("value")),
      mMHT(ps.Get<bool>("doMHT"))
    { mModifies = true; }

    ~pfMETsmearing() {}

    bool Apply(ICF_LorentzV* ob) {

      if(mMHT && mEv->LD_CommonMuons().accepted.size() == 0) mMHT = false;

      if(mMHT) {
	LorentzV pfMHT = *ob + *(mEv->LD_CommonMuons().accepted.at(0));
	if(mScale) {
	  //	  pfMHT.SetPx(mValue * pfMHT.X());
	  //	  pfMHT.SetPy(mValue * pfMHT.Y());
	  float tmpX = pfMHT.X(); float tmpY = pfMHT.Y(); float tmpZ = pfMHT.Z(); float tmpE = pfMHT.E();
	  pfMHT.SetPxPyPzE(mValue*pfMHT.X(),mValue*pfMHT.Y(),tmpZ,tmpE);
	  ob->operator=(pfMHT - *(mEv->LD_CommonMuons().accepted.at(0)));
	} else {
	  double newMETscaling = gRandom->Gaus(pfMHT.Pt(), mValue * pfMHT.Pt()) / pfMHT.Pt();
	  //	  pfMHT.SetPx(newMETscaling * pfMHT.X());
	  //	  pfMHT.SetPy(newMETscaling * pfMHT.Y());
	  float tmpX = pfMHT.X(); float tmpY = pfMHT.Y(); float tmpZ = pfMHT.Z(); float tmpE = pfMHT.E();
	  pfMHT.SetPxPyPzE(newMETscaling*pfMHT.X(),newMETscaling*pfMHT.Y(),tmpZ,tmpE);
	  ob->operator=(pfMHT - *(mEv->LD_CommonMuons().accepted.at(0)));
	}
      } else {
	if(mScale) {
	  //	  ob->SetPx(mValue*ob->X());
	  //	  ob->SetPy(mValue*ob->Y());
	  ob->SetPxPyPzE(mValue*ob->X(),mValue*ob->Y(),ob->Z(),ob->E());
	} else {
	  double newMETscaling = gRandom->Gaus(ob->Pt(), mValue * ob->Pt()) / ob->Pt();
	  //	  ob->SetPx(newMETscaling*ob->X());
	  //	  ob->SetPy(newMETscaling*ob->Y());
	  ob->SetPxPyPzE(newMETscaling*ob->X(),newMETscaling*ob->Y(),ob->Z(),ob->E());
	}
      }
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMETsmearing";
      return ostrm;
    }

  private:
    bool mScale;
    double mValue;
    bool mMHT;
  };

  class pfMETResSmear : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETResSmear(const Utils::ParameterSet & ps) :
      mSmear(ps.Get<double>("smear"))
    { mModifies = true; }

    ~pfMETResSmear() {}

    bool Apply(ICF_LorentzV* ob) {

      //set up the bins we will use for the extra smearing:
      unsigned int num_met_bins = 13;
      double lim_min[] = { 0.0, 50.0, 60.0, 70.0, 80.0,  90.0, 100.0, 120.0, 140.0, 160.0, 180.0, 200.0, 250.0};
      double lim_max[] = {50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 120.0, 140.0, 160.0, 180.0, 200.0, 250.0, 1000.0};
      //the results from the fits: (see root_macros/METResolutionFits_binned.C)
      //these are from the 38 WJets Z2 with "little" PU:
      //double bin_res[] = {0.138227, 0.0847698, 0.102731, 0.113414, 0.122413, 0.119542, 0.113068, 0.102622, 0.0965498, 0.0909553, 0.0936789, 0.0854964};
      //these are from the 38 WJets Z2 with "full" PU:
      double bin_res[] = {0.15544, 0.0910675, 0.110968, 0.121085, 0.131144, 0.127082, 0.116845, 0.109509, 0.100616, 0.0934123, 0.0993534, 0.0861262};

      //initialise the genLepton object so that we can construct the genMHT:
      GenMatrixBin myGenMatrixBin(mEv);
      Event::GenObject const * theGenLepton;
      if(myGenMatrixBin.the_GenMuon.size() == 1) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
      else if(myGenMatrixBin.the_GenTau.size() == 1) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
      else if(myGenMatrixBin.the_GenEli.size() == 1) theGenLepton = myGenMatrixBin.the_GenEli.at(0);
      else return false;

      //construct the genMHT:
      LorentzV genMHT = *(mEv->genMetP4PF()) + *(theGenLepton);

      //check that a RECO muon exists so that we can set up the quantity to be smeared:
      if(mEv->LD_CommonMuons().accepted.size() == 0) return false;

      //construct the RECOMHT:
      LorentzV pfMHT = *ob + *(mEv->LD_CommonMuons().accepted.at(0));

      for(unsigned int i=0; i<num_met_bins; i++) {
	if(genMHT.Pt() >= lim_min[i] && genMHT.Pt() < lim_max[i]) {
	  double smear_factor = TMath::Sqrt(((1.0 + mSmear)*(1.0 + mSmear)) - 1.0) * bin_res[i];
	  double newMETscaling = gRandom->Gaus(pfMHT.Pt(), smear_factor * pfMHT.Pt()) / pfMHT.Pt();
	  //	  pfMHT.SetPx(newMETscaling * pfMHT.X());
	  //	  pfMHT.SetPy(newMETscaling * pfMHT.Y());
	  pfMHT.SetPxPyPzE(newMETscaling*pfMHT.X(),newMETscaling*pfMHT.Y(),pfMHT.Z(),pfMHT.E());
	  ob->operator=(pfMHT - *(mEv->LD_CommonMuons().accepted.at(0)));
	}
      }
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMET Resolution Smearing (" << mSmear << " relative)";
      return ostrm;
    }

  private:
    double mSmear;
  };

  class pfMETResSmearPU : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETResSmearPU(const Utils::ParameterSet & ps) :
      mSmear(ps.Get<double>("smear"))
    { mModifies = true; }

    ~pfMETResSmearPU() {}

    bool Apply(ICF_LorentzV* ob) {

      //see JME-10-009

      //check that a RECO muon exists so that we can set up the quantity to be smeared:
      if(mEv->LD_CommonMuons().accepted.size() == 0) return false;

      //construct the RECOMHT:
      LorentzV pfMHT = *ob + *(mEv->LD_CommonMuons().accepted.at(0));

      //smear X and Y independently
      double newMETscalingX = gRandom->Gaus(pfMHT.Px(), mSmear / pfMHT.Pt());
      double newMETscalingY = gRandom->Gaus(pfMHT.Py(), mSmear / pfMHT.Pt());
      //      cout << "pfMHT.Px(): " << pfMHT.Px() << ", scalingX: "<< newMETscalingX << endl;
      //      cout << "pfMHT.Py(): " << pfMHT.Py() << ", scalingY: "<< newMETscalingY << endl;
      //      pfMHT.SetPx(newMETscalingX);
      //      pfMHT.SetPy(newMETscalingY);
      pfMHT.SetPxPyPzE(newMETscalingX,newMETscalingY,pfMHT.Pz(),pfMHT.E());
      ob->operator=(pfMHT - *(mEv->LD_CommonMuons().accepted.at(0)));
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMET PU Resolution Smearing (" << mSmear << "GeV in quadrature)";
      return ostrm;
    }

  private:
    double mSmear;
  };

  class MuonScaleShift : public Compute::ObjectFilter<Event::Lepton> {
  public:
    MuonScaleShift(const Utils::ParameterSet & ps) :
      mScaleChoice(ps.Get<double>("scalechoice")),
      mScaleShift(ps.Get<double>("scaleshift")),
      mPlusPlus(ps.Get<bool>("plusplus"))
    { mModifies = true; }//use false along with const definition below, true with non-const

    ~MuonScaleShift() {}

    //bool Apply(const Event::Lepton* ob) {
    bool Apply(Event::Lepton* ob) {
      //int iM = (ob)->GetIndex();

      double newPtFactor = 1.0;
      if(mPlusPlus) {
	if(ob->GetCharge() > 0.0) {
	  newPtFactor = 1.0 + ((mScaleShift * ob->Pt())/mScaleChoice);
	} else {
	  newPtFactor = 1.0 - ((mScaleShift * ob->Pt())/mScaleChoice);
	}
      } else {
	if(ob->GetCharge() > 0.0) {
	  newPtFactor = 1.0 - ((mScaleShift * ob->Pt())/mScaleChoice);
	} else {
	  newPtFactor = 1.0 + ((mScaleShift * ob->Pt())/mScaleChoice);
	}
      }

      //      ob->SetPx(newPtFactor*ob->X());
      //      ob->SetPy(newPtFactor*ob->Y());
      ob->SetPxPyPzE(newPtFactor*ob->X(),newPtFactor*ob->X(),ob->Z(),ob->E());

      return true;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom MuonID " << std::endl;
      return ostrm;
    }

  private:
    double mScaleChoice;
    double mScaleShift;
    bool mPlusPlus;
  };

  class pfMETJECUnc : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETJECUnc(const Utils::ParameterSet & ps) :
      mJECUncFile(ps.Get<string>("jecuncfile")),
      mLepton(ps.Get<string>("lepton")),
      mPFJetThresh(ps.Get<double>("pfjetthresh")),
      mUnclusteredShift(ps.Get<double>("unclusteredshift")),
      mShiftUp(ps.Get<bool>("shiftup"))
    { mModifies = true; }

    ~pfMETJECUnc() {}

    bool Apply(ICF_LorentzV* ob) {

      Operation::JetCorrectionUncertainty jecUnc(mJECUncFile);

      LorentzV pfUnclustered, scaledjets, myscaledjet;
      double unc = 0.0;
      Event::Lepton const * theRECOLepton;
      if(mLepton == "Muon") theRECOLepton = mEv->LD_CommonMuons().accepted.at(0);
      else if(mEv->LD_CommonElectrons().accepted.size() > 0) theRECOLepton = mEv->LD_CommonElectrons().accepted.at(0);
      else if(mEv->LD_Electrons().size() > 0) theRECOLepton = &mEv->LD_Electrons()[0];
      else return true;

     //decide whether the lepton is electron or muon, then add it back into the MET calculation
      pfUnclustered = *ob + *(theRECOLepton);

      //to change to use SecJets, use JD_SecJets, TerJets, JD_TerJets
      for(unsigned int i=0; i< mEv->JD_Jets().size(); i++) {
	//loop through all jets above threshold (in this case the Jets relate to AK5PF2PAT)
	if(mEv->JD_Jets().at(i).Pt() > mPFJetThresh) {
	  //calculate the uncertainty on the JEC according to corrected PT and Eta
	  jecUnc.setJetEta(mEv->JD_Jets().at(i).Eta());
	  jecUnc.setJetPt(mEv->JD_Jets().at(i).Pt());
	  unc = jecUnc.getUncertainty(true);
	  //add in the jets to the (lepton + neutrino) to leave you with unclustered energy
	  pfUnclustered += (mEv->JD_Jets().at(i));
	  //scale the jets by the JECUnc either up or down
	  if(mShiftUp) myscaledjet = mEv->JD_Jets().at(i) * (1.0 + unc);
	  else myscaledjet = mEv->JD_Jets().at(i) * (1.0 - unc);
	  //make a negative vector sum of all the scaled jets
	  if(i==0) scaledjets = -myscaledjet;
	  else scaledjets -= myscaledjet;
	}
      }
      //shift the unclustered energy either up or down
      if(mShiftUp) pfUnclustered *= (1.0 + mUnclusteredShift);
      else pfUnclustered *= (1.0 - mUnclusteredShift);
      //add in the negative vector sum of scaled jets
      pfUnclustered += scaledjets;

      //std::cout << "scaled MHT: " << pfUnclustered.Pt() << std::endl;

      //finally, add the lepton back into the calculation
      ob->operator=(pfUnclustered - *(theRECOLepton));
      return true;

    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMET systematic from JEC Uncertainties";
      return ostrm;
    }

  private:
    std::string mJECUncFile;
    std::string mLepton;
    double mPFJetThresh;
    double mUnclusteredShift;
    bool mShiftUp;
  };

  class ECALTransparencyCorrections : public Compute::ObjectFilter<Event::Lepton>{
   public:

   public:
    ECALTransparencyCorrections(const Utils::ParameterSet & ps):
        mCorrection(ps.Get<bool>("ApplyAsCorrection")),
        mSystematics(ps.Get<bool>("ApplySystematics")),
        mSystematicsShift(ps.Get<double>("SystematicsShift"))
    {
      mModifies = true;
      std::string corrections_version = ps.Get<std::string>("CorrectionsVersion");
      if(corrections_version == "38") mCorrectionsVersion = ECALTransparencyCorrections::corr38;
      else if(corrections_version == "39") mCorrectionsVersion = ECALTransparencyCorrections::corr39;
      else throw std::invalid_argument("Invalid value for CorrectionsVersion: "+ corrections_version);

      if(mCorrectionsVersion == ECALTransparencyCorrections::corr38) std::cout << "38 Transparency Corrections" << std::endl;
      else std::cout << "39 Transparency Corrections" << std::endl;
    }
    ~ECALTransparencyCorrections(){}
    bool Apply(Event::Lepton* ob){
      double abs_eta = fabs(ob->Eta());
      double corr_factor = 0;

      switch(mCorrectionsVersion){
        case ECALTransparencyCorrections::corr38:
          if(abs_eta < 0.4) corr_factor = 1.00258;
          else if(abs_eta >= 0.4 && abs_eta < 0.8) corr_factor = 1.00592;
          else if(abs_eta >= 0.8 && abs_eta < 1.2) corr_factor = 1.01212;
          else if(abs_eta >= 1.2 && abs_eta < 1.6) corr_factor = 1.01931;
          else if(abs_eta >= 1.6 && abs_eta < 2.0) corr_factor = 1.03928;
          else if(abs_eta >= 2.0 && abs_eta < 2.4) corr_factor = 1.03389;
          else corr_factor = 1.0;
          break;
        case ECALTransparencyCorrections::corr39:
          if (mEv->RunNumber() < 148000){
             if(abs_eta < 0.4) corr_factor = 0.994;
             else if(abs_eta >= 0.4 && abs_eta < 0.8) corr_factor = 0.997;
             else if(abs_eta >= 0.8 && abs_eta < 1.2) corr_factor = 0.997;
             else if(abs_eta >= 1.2 && abs_eta < 1.6) corr_factor = 1.010;
             else if(abs_eta >= 1.6 && abs_eta < 2.0) corr_factor = 0.999;
             else if(abs_eta >= 2.0 && abs_eta < 2.4) corr_factor = 0.998;
             else corr_factor = 1.0;
          }
          else{
            if(abs_eta < 0.4) corr_factor = 0.994;
            else if(abs_eta >= 0.4 && abs_eta < 0.8) corr_factor = 0.995;
            else if(abs_eta >= 0.8 && abs_eta < 1.2) corr_factor = 0.999;
            else if(abs_eta >= 1.2 && abs_eta < 1.6) corr_factor = 1.006;
            else if(abs_eta >= 1.6 && abs_eta < 2.0) corr_factor = 0.989;
            else if(abs_eta >= 2.0 && abs_eta < 2.4) corr_factor = 1.008;
            else corr_factor = 1.0;
          }
          break;
        default:
          throw std::invalid_argument("Unrecognised value for ApplyAsCorrection in ECALTransparencyCorrections.");
          break;
      }

      // Assuming we have a systematic shift 0.5 (50%):
      // We will get for 1.006 -> 1.006 + 0.5*(0.006) = 1.009
      if(mSystematics) corr_factor = 1 + mSystematicsShift*(corr_factor - 1);
      double mult_factor;
      if(mCorrection) mult_factor = corr_factor;
      else mult_factor = 1./corr_factor;

      //      ob->SetPx(ob->Px()*mult_factor);
      //      ob->SetPy(ob->Py()*mult_factor);
      //      ob->SetPz(ob->Pz()*mult_factor);
      //      ob->SetE(ob->E()*mult_factor);
      ob->SetPxPyPzE(ob->Px()*mult_factor,ob->Py()*mult_factor,ob->Pz()*mult_factor,ob->E()*mult_factor);
      return true;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "ECAL Transparency corrections (ApplyAsCorrection = "
	    << mCorrection
	    << ")";
      return ostrm;
    }
  private:
    bool mCorrection;
    bool mSystematics;
    double mSystematicsShift;
    enum CorrectionsVersion {
      corr38 = 0,
      corr39 = 1
    } mCorrectionsVersion;
  };

  class ElectronScaleUncertainty : public Compute::ObjectFilter<Event::Lepton>{
  public:
    ElectronScaleUncertainty(const Utils::ParameterSet & ps):
      mScaleFactor(ps.Get<double>("ScaleFactor"))
    { mModifies = true; }
    ~ElectronScaleUncertainty(){}

    bool Apply(Event::Lepton* ob){
      //      ob->SetPx(mScaleFactor*ob->Px());
      //      ob->SetPy(mScaleFactor*ob->Py());
      //      ob->SetPz(mScaleFactor*ob->Pz());
      //      ob->SetE(mScaleFactor*ob->E());
      ob->SetPxPyPzE(mScaleFactor*ob->Px(),mScaleFactor*ob->Py(),mScaleFactor*ob->Pz(),mScaleFactor*ob->E());
      return true;
    }
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Electron Scale Uncertainty (" << mScaleFactor << ")";
      return ostrm;
    }

  private:
    double mScaleFactor;
  };

  class ECALResolutionCorrections : public Compute::ObjectFilter<Event::Lepton>{
  public:
    ECALResolutionCorrections(const Utils::ParameterSet & ps):
      mCorrections(ps.Get<std::vector<double> >("ResolutionCorrections"))
    {
      mModifies = true;
      rnd = new TRandom2();
      if(mCorrections.size() != 6) throw std::invalid_argument("ResolutionCorrections array is not the right length");
    }

    ~ECALResolutionCorrections(){};

    bool Apply(Event::Lepton* ob){
      double abs_eta = fabs(ob->eta());
      double sigma = 1.0;
      // Find resolution correction for given eta bin
      if(abs_eta < 0.4) sigma = mCorrections[0];
      else if(abs_eta >= 0.4 && abs_eta < 0.8) sigma = mCorrections[1];
      else if(abs_eta >= 0.8 && abs_eta < 1.2) sigma = mCorrections[2];
      else if(abs_eta >= 1.2 && abs_eta < 1.6) sigma = mCorrections[3];
      else if(abs_eta >= 1.6 && abs_eta < 2.0) sigma = mCorrections[4];
      else if(abs_eta >= 2.0 && abs_eta < 2.4) sigma = mCorrections[5];

      //      double min_dr = 10000;
      //const Event::GenObject* gen=0;
      // Find closest gen electron in deltaR < 0.3
//       for(std::vector<Event::GenObject>::const_iterator it = mEv->GenParticles().begin();
// 	  it != mEv->GenParticles().end();
// 	  ++it){
// 	// Check it is status 1 electron
// 	if(it->GetStatus() != 1) continue;
// 	if(abs(it->GetID()) != 11) continue;
// 	double dr = ROOT::Math::VectorUtil::DeltaR(*it, *ob);
// 	if(dr < min_dr){
// 	    min_dr = dr;
//             gen = &(*it);
//         }
//       }

//       // We can't find a compatible lepton. Don't scale.
//       if(min_dr > 0.3) return true;

      // Apply resolution to generator electron
//      std::cout << "Gen Pt = " << gen->Pt() << std::endl;
//      std::cout << "Eta = " << ob->Eta() << std::endl;
//      std::cout << "RECO Pt = " << ob->Pt() << std::endl;
//      double scaled_pt = gen->Pt() + sigma*rnd->Gaus(0, 1);
//      std::cout << "Scaled Pt = " << scaled_pt << std::endl;
      double scaled_pt = ob->Pt() + sigma*rnd->Gaus(0,1);
      double ob_pt = ob->Pt();
      // Rescale RECO 4-vector to new pt
      //      ob->SetPx(ob->Px()*scaled_pt/ob_pt);
      //      ob->SetPy(ob->Py()*scaled_pt/ob_pt);
      //      ob->SetPz(ob->Pz()*scaled_pt/ob_pt);
      //      ob->SetE(ob->E()*scaled_pt/ob_pt);
      ob->SetPxPyPzE(ob->Px()*scaled_pt/ob_pt,ob->Py()*scaled_pt/ob_pt,ob->Pz()*scaled_pt/ob_pt,ob->E()*scaled_pt/ob_pt);
//      std::cout << "New ob Pt " << ob->Pt() << std::endl;
      return true;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "ECAL Resolution corrections" << std::endl;
      return ostrm;
    }

  private:
    std::vector<double> mCorrections;
    TRandom* rnd;
  };


// The next two classes have factors to account for scale and resolution
// differences between 38 and 39 ReRecos. The factors are binned in eta of the
// electron.
 class ElepfMETSmearing : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    ElepfMETSmearing()
    { mModifies = true; }

    ~ElepfMETSmearing() {}

    bool Apply(ICF_LorentzV* ob) {
      LorentzV pfMHT;
      if(mEv->LD_CommonElectrons().accepted.size() == 0) return true;
      else{
        pfMHT = *ob + *(mEv->LD_CommonElectrons().accepted.at(0));
      }
      double abs_eta = fabs(mEv->LD_CommonElectrons().accepted.at(0)->Eta());
      double scale_factor = 0;
      double smear_factor = 0;
      if(abs_eta < 0.4){
        scale_factor = 0.002593;
        smear_factor = 0.05758;
      }
      else if(abs_eta < 0.8){
        scale_factor = 0.002129;
        smear_factor = 0.05194;
      }
      else if(abs_eta < 1.2){
        scale_factor = 0.002199;
        smear_factor = 0.04746;
      }
      else if(abs_eta < 1.6){
        scale_factor = 0.006467;
        smear_factor = 0.05101;
      }
      else if(abs_eta < 2.0){
        scale_factor = 0.008834;
        smear_factor = 0.05392;
      }
      else if(abs_eta < 2.4){
        scale_factor = 0.01144;
        smear_factor = 0.05401;
      }
      else return true;

      // Scale first
      //      pfMHT.SetPx((1+scale_factor)*pfMHT.X());
      //      pfMHT.SetPy((1+scale_factor)*pfMHT.Y());
      pfMHT.SetPxPyPzE((1+scale_factor)*pfMHT.X(),(1+scale_factor)*pfMHT.Y(),pfMHT.Z(),pfMHT.E());
      // Then smear
      double newMETscaling = gRandom->Gaus(pfMHT.Pt(), smear_factor * pfMHT.Pt()) / pfMHT.Pt();
      //      pfMHT.SetPx(newMETscaling * pfMHT.X());
      //      pfMHT.SetPy(newMETscaling * pfMHT.Y());
      pfMHT.SetPxPyPzE(newMETscaling*pfMHT.X(),newMETscaling*pfMHT.Y(),pfMHT.Z(),pfMHT.E());
      ob->operator=(pfMHT - *(mEv->LD_CommonElectrons().accepted.at(0)));
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMETsmearing";
      return ostrm;
    }
  };

class ElePtSmearing : public Compute::ObjectFilter<Event::Lepton> {
  public:
    ElePtSmearing()
    { mModifies = true; }

    ~ElePtSmearing() {}

  bool Apply(Event::Lepton* ob) {
      double abs_eta = fabs(ob->Eta());
      double scale_factor = 0;
      double smear_factor = 0;
      if(abs_eta < 0.4){
        scale_factor = -0.0007349;
        smear_factor = 0.0118;
      }
      else if(abs_eta < 0.8){
        scale_factor = 0.0001147;
        smear_factor = 0.01171;
      }
      else if(abs_eta < 1.2){
        scale_factor = 0.001905;
        smear_factor = 0.01125;
      }
      else if(abs_eta < 1.6){
        scale_factor = -0.003803;
        smear_factor = 0.02055;
      }
      else if(abs_eta < 2.0){
        scale_factor = 0.001261;
        smear_factor = 0.0376;
      }
      else if(abs_eta < 2.4){
        scale_factor = 0.002351;
        smear_factor = 0.03888;
      }
      else return true;

      // Scale first
      //      ob->SetPx((1+scale_factor)*ob->X());
      //      ob->SetPy((1+scale_factor)*ob->Y());
      ob->SetPxPyPzE((1+scale_factor)*ob->X(),(1+scale_factor)*ob->Y(),ob->Z(),ob->E());
      // Then smear
      double newElescaling = gRandom->Gaus(ob->Pt(), smear_factor * ob->Pt()) / ob->Pt();
      //      ob->SetPx(newElescaling * ob->X());
      //      ob->SetPy(newElescaling * ob->Y());
      ob->SetPxPyPzE(newElescaling*ob->X(),newElescaling*ob->Y(),ob->Z(),ob->E());
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "Elesmearing";
      return ostrm;
    }
  };


  class ElepfMETResSmear : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    ElepfMETResSmear(const Utils::ParameterSet & ps) :
      mSmear(ps.Get<double>("smear"))
    { mModifies = true; }

    ~ElepfMETResSmear() {}

    bool Apply(ICF_LorentzV* ob) {

      //set up the bins we will use for the extra smearing:
      unsigned int num_met_bins = 13;
      double lim_min[] = { 0.0, 50.0, 60.0, 70.0, 80.0,  90.0, 100.0, 120.0, 140.0, 160.0, 180.0, 200.0, 250.0};
      double lim_max[] = {50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 120.0, 140.0, 160.0, 180.0, 200.0, 250.0, 1000.0};
      //the results from the fits: (see root_macros/METResolutionFits_binned.C)
      double bin_res[] = {0.138227, 0.0847698, 0.102731, 0.113414, 0.122413, 0.119542, 0.113068, 0.102622, 0.0965498, 0.0909553, 0.0936789, 0.0854964};

      //initialise the genLepton object so that we can construct the genMHT:
      GenMatrixBin myGenMatrixBin(mEv);
      Event::GenObject const * theGenLepton;
      if(myGenMatrixBin.the_GenMuon.size() == 1) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
      else if(myGenMatrixBin.the_GenTau.size() == 1) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
      else if(myGenMatrixBin.the_GenEli.size() == 1) theGenLepton = myGenMatrixBin.the_GenEli.at(0);
      else return false;

      //construct the genMHT:
      LorentzV genMHT = *(mEv->genMetP4PF()) + *(theGenLepton);

      //check that a RECO muon exists so that we can set up the quantity to be smeared:
      if(mEv->LD_CommonElectrons().accepted.size() == 0) return false;

      //construct the RECOMHT:
      LorentzV pfMHT = *ob + *(mEv->LD_CommonElectrons().accepted.at(0));

      for(unsigned int i=0; i<num_met_bins; i++) {
	if(genMHT.Pt() >= lim_min[i] && genMHT.Pt() < lim_max[i]) {
	  double smear_factor = TMath::Sqrt(((1.0 + mSmear)*(1.0 + mSmear)) - 1.0) * bin_res[i];
	  double newMETscaling = gRandom->Gaus(pfMHT.Pt(), smear_factor * pfMHT.Pt()) / pfMHT.Pt();
	  //	  pfMHT.SetPx(newMETscaling * pfMHT.X());
	  //	  pfMHT.SetPy(newMETscaling * pfMHT.Y());
	  pfMHT.SetPxPyPzE(newMETscaling * pfMHT.X(),newMETscaling * pfMHT.Y(),pfMHT.Z(),pfMHT.E());
	  ob->operator=(pfMHT - *(mEv->LD_CommonElectrons().accepted.at(0)));
	}
      }
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "Ele pfMET Resolution Smearing (" << mSmear << " relative)";
      return ostrm;
    }

  private:
    double mSmear;
  };


}

namespace Alex{
/* NOTE: This is a tweaked version of the electronID above. The tweaks allow
   each cut to be applied (1), inverted (0) or ignored (-1). It is used by the
   anti-selection code.
*/

   class CustomEleId : public Compute::ObjectFilter<Event::Lepton> {
   public:
     CustomEleId(const Utils::ParameterSet & ps,
                 const std::string & spec_prefix="",
                 const std::string & prefix = "Cuts") :
      mIso(ps.Get<int>(spec_prefix+"Isolation")),
      mHoE(ps.Get<int>(spec_prefix+"HoverE")),
      mDeltaEta(ps.Get<int>(spec_prefix+"DeltaEtaAtVtx")),
      mDeltaPhi(ps.Get<int>(spec_prefix+"DeltaPhiAtVtx")),
      mShh(ps.Get<int>(spec_prefix+"SigmaIEtaIEta")),
      mConv(ps.Get<int>(spec_prefix+"Conversions")),
      mConvExtra(ps.Get<int>(spec_prefix+"ConversionsExtra")),

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
      mSupressErrors(ps.Contains(spec_prefix+"SupressErrors") ? ps.Get<bool>(spec_prefix+"SupressErrors") : false),
      mCorrEEMisalig(ps.Contains(spec_prefix+"CorrEEMisalig") ? ps.Get<bool>(spec_prefix+"CorrEEMisalig") : false)
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
         bool passDeltaEta = false; bool passDeltaPhi = false;
         bool passShh = false;
         bool passConv = false;
         bool passConvExtra = false;
         int iM = (ob)->GetIndex();

         //passConv = mEv->GetElectronHasValidHitInFirstPixelBarrel(iM);
         try{
            passConvExtra = (fabs(mEv->GetElectronDCot(iM)) > mDCot || fabs(mEv->GetElectronDist(iM)) > mDist);
	    passConvExtra &= (mEv->GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
         }
         catch(std::invalid_argument & e){

            if(!mSupressErrors) throw e;
         }
         try{//BROKEN?!(mjarvis)
             passConvExtra &= (mEv->GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
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
            passHoE = ( mEv->GetElectronHoE(iM) < mHoEBarrel );
            passDeltaPhi = ( fabs(mEv->GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel );
	    passDeltaEta = ( fabs(mEv->GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
            passShh = ( mEv->GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );
         }
         else if (fabs(ob->Eta()) > 1.560 ) {
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
         return ((mIso >= 0 ? (passIso == bool(mIso)) : true) &&
                 (mHoE >= 0 ? (passHoE == bool(mHoE)) : true) &&
                 (mDeltaEta >= 0 ? (passDeltaEta == bool(mDeltaEta)) : true) &&
                 (mDeltaPhi >= 0 ? (passDeltaPhi == bool(mDeltaPhi)) : true) &&
                 (mShh >= 0 ? (passShh == bool(mShh)) : true) &&
                 (mConvExtra >= 0 ? (passConvExtra == bool(mConvExtra)) : true));
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
      int mConvExtra;

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
