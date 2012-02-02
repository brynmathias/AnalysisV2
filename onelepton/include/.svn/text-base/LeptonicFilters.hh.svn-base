#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "LeptonicOps.hh"
#include "GenMatrixBin.hh"
#include "TRandom.h"
// WPol includes
#include "Functions.hh"
#include "Structures.hh"
#include "MuPtScaleCorr.hh"
#include <sstream>
#include <vector>
#include "ICF_NtupleData.hh"
#include "JECUnc_JetCorrectionUncertainty.hh"

using namespace Operation; // For wpol stuff

namespace OneLepton{

   class EleJetDRFilter : public Compute::ObjectFilter<Event::Jet>{
   public:
      EleJetDRFilter(double drCut):
      mDRCut(drCut) { mModifies=false;}

      ~EleJetDRFilter(){}

      bool Apply(const Event::Jet* ob){
	double electronComJetDRmin_ = 9999999.;
	for (std::vector<Lepton const *>::const_iterator iEl = mEv->LD_CommonElectrons().accepted.begin();
	     iEl != mEv->LD_CommonElectrons().accepted.end();
	     ++iEl) {
	  if(fabs(ROOT::Math::VectorUtil::DeltaR ((*ob),(**iEl)))<electronComJetDRmin_) electronComJetDRmin_=fabs(ROOT::Math::VectorUtil::DeltaR (*ob,**iEl));
	  
	}
	if (electronComJetDRmin_ > mDRCut) { return true; } // keep the jet
	else {return false; }
	
	return true;
      }
     
      std::ostream & Description(std::ostream & ostrm){
         ostrm << "Custom DR(e-jet) Cut > "<< mDRCut;
         return ostrm;
      }

   private:
      double mDRCut;
   };

class LooseEleId : public Compute::ObjectFilter<Event::Lepton>{
 public:
  LooseEleId(){mModifies=false;}
  ~LooseEleId(){}
  bool Apply(const Event::Lepton* ob){
    return Operation::isLooseElectron(ob);
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Loose Electron ID";
    return ostrm;
  }
};

  class MuonJetDRFilter : public Compute::ObjectFilter<Event::Jet>{
  public:
    MuonJetDRFilter(double drCut, const Utils::ParameterSet & ps):
      mDRCut(drCut),
      mMuPtCut(ps.Get<double>("MinPt")),
      mMuEtaCut(ps.Get<double>("MaxEta")),
      mMuIsoCut(ps.Get<double>("MaxIsolation"))
    { mModifies=false;}
    
    ~MuonJetDRFilter(){}
    
    
    bool Apply(const Event::Jet* ob){
      
      float minDr =10000;


      for(std::vector<Event::Lepton const *>::const_iterator mu = mEv->LD_CommonMuons().accepted.begin();  mu != mEv->LD_CommonMuons().accepted.end();mu++)
	{
	  if(fabs(ROOT::Math::VectorUtil::DeltaR ((*ob),(**mu)))<minDr) minDr=fabs(ROOT::Math::VectorUtil::DeltaR (*ob,**mu));
	}
      return  minDr > mDRCut;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(mu-jet) Cut > "<< mDRCut;
      return ostrm;
    }
    
   private:
      double mDRCut;
     double mMuPtCut;
     double mMuEtaCut;
     double mMuIsoCut;
   };


  class MuonJetDRFilterRA4Sync : public Compute::ObjectFilter<Event::Jet>{
  public:
    MuonJetDRFilterRA4Sync(double drCut, const Utils::ParameterSet & ps):
      mDRCut(drCut),
      mID(ps.Get<std::string>("MuID")),
      mMinPt(ps.Get<double>("MinPt")),
      mMaxEta(ps.Get<double>("MaxEta")),
      mIsolation(ps.Get<double>("MaxIsolation")),
      mDRMuJet(ps.Get<double>("DRMuJet")),
      mMaxGlbTrkDxy(ps.Get<double>("MaxGlbTrkDxy")),
      mMinGlbTrkNumOfValidHits(ps.Get<int>("MinGlbTrkNumOfValidHits")),
      mSegMatch2GlbMu(ps.Get<int>("SegMatch2GlbMu")),
      mPixelHitsOnInrTrk(ps.Get<int>("PixelHitsOnInrTrk")),
      mMaxInrTrkDz(ps.Get<double>("MaxInrTrkDz"))

    { mModifies=false;}

    ~MuonJetDRFilterRA4Sync(){}

    bool Apply(const Event::Jet* ob){

      /*
      if (
	  ( (ob)->Pt()<30. ) ||
	  ( fabs((ob)->Eta())>2.4 ) ||
	  (mEv->jetPFJetIDLoose()->at(ob->GetIndex()) < 1)
	  ) { return false; }
      */

    double muonComJetDRmin_ = 9999999.;
      for(std::vector<Event::Lepton>::const_iterator mu = mEv->LD_Muons().begin();
	  mu != mEv->LD_Muons().end();
	  ++mu){


	bool id = false;
	if (mID=="Tight") { id = (mEv->IsMuonTracker(mu->GetIndex())) && (mEv->IsGlobalMuonPromptTight(mu->GetIndex())); }
	else { id = (mEv->IsMuonGlobal(mu->GetIndex())); }


	bool muonIsTight = false;

	try {
	  // new definition - 2011
	  if (
	      ( id )  &&
	      ( ((mu->Pt()) >= mMinPt) && (fabs(mu->Eta()) <= mMaxEta) )  &&
	      ( (mu->GetCombIsolation()) < mIsolation )  &&
	      ( fabs(mEv->GetMuonInnerTrackDxyBS(mu->GetIndex())) <= mMaxGlbTrkDxy )  &&
	      ( mEv->muonNumberOfMatches()->at(mu->GetIndex()) > mSegMatch2GlbMu )  &&
	      ( mEv->muonGlobalTracknumberOfValidTrackerHits()->at(mu->GetIndex()) >= mMinGlbTrkNumOfValidHits )  &&
	      ( mEv->muonNumberOfPixelLayersWithMeasurement()->at(mu->GetIndex()) >= mPixelHitsOnInrTrk )  &&
	      ( ( fabs(mEv->muonInnerTrackVertexz()->at(mu->GetIndex()) - (mEv->GetvertexPosition(0).Z())) ) < mMaxInrTrkDz ) &&
	      ( muonComJetDRmin_ > mDRMuJet)
	      ) { muonIsTight = true; }
	  // ~end of new definition - 2011
	}
	catch (std::invalid_argument & e) {
	  // old definition - 2010
	  if (
	      ( id )  &&
	      ( ((mu->Pt()) >= mMinPt) && (fabs(mu->Eta()) <= mMaxEta) )  &&
	      ( (mu->GetCombIsolation()) < mIsolation )  &&
	      ( fabs(mEv->GetMuonInnerTrackDxyBS(mu->GetIndex())) <= mMaxGlbTrkDxy )  &&
	      ( mEv->muonNumberOfMatches()->at(mu->GetIndex()) > mSegMatch2GlbMu )  &&
	      ( mEv->GetMuonInnerTracknumberOfValidHits(mu->GetIndex()) >= mMinGlbTrkNumOfValidHits )  &&
	      ( mEv->muonNumberOfValidPixelHits()->at(mu->GetIndex()) >= mPixelHitsOnInrTrk ) &&
	      ( ( fabs(mEv->GetMuonInnerTrackDz(mu->GetIndex()))) < mMaxInrTrkDz ) &&
	      ( muonComJetDRmin_ > mDRMuJet)
	      ) { muonIsTight = true; }
	  // ~end of old definition - 2010
	}


	if (muonIsTight) {

	  double tmpMuonComJetDR_ = fabs(ROOT::Math::VectorUtil::DeltaR(*ob,*mu));
	  if (tmpMuonComJetDR_ < muonComJetDRmin_) { muonComJetDRmin_ = tmpMuonComJetDR_; }
	  //	    return fabs(ROOT::Math::VectorUtil::DeltaR ((*ob),*mu)) > mDRCut;
	}

      }  // ~ end of looping over the Muons

      if (muonComJetDRmin_ > mDRCut) { return true; } // keep the jet
      else {return false; }

      //      return true;
    } // ~ end of bool function


    std::ostream & Description(std::ostream & ostrm){
      ostrm << "[RA4] Custom DR(mu-jet) Cut > "<< mDRCut;
      return ostrm;
    }

  private:
    double mDRCut;
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

  class LepMaxPtFilter : public Compute::ObjectFilter<Event::Lepton>{
  public:
    LepMaxPtFilter(double min_iso):
      mMaxPt(min_iso){ mModifies = false; }

    ~LepMaxPtFilter(){}

    bool Apply(const Event::Lepton* lep){
      return lep->Pt() <= mMaxPt;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Lepton CombIso  >= " << mMaxPt;
      return ostrm;
    }

  private:
    double mMaxPt;
  };

 class pfMETsmearing : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETsmearing(){ mModifies = true; }
    ~pfMETsmearing(){}

    bool Apply(ICF_LorentzV* ob) {
      ob->SetPxPyPzE(0.0,0.0,ob->Pz(),ob->E());
      //   ob->SetPy(0.0);
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMETsmearing";
      return ostrm;
    }
  };



// Adapted from WPolFilters.hh and made generic wrt lepton type
// Also pass in factors via PSet
  class pfMETLeptonScale : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETLeptonScale(const Utils::ParameterSet & ps) :
      mLepton(ps.Get<std::string>("Lepton")),mGen(ps.Get<bool>("Gen"))
    { mModifies = true;
      if(mLepton == "Muon") mLeptonType = pfMETLeptonScale::MUON;
      else if(mLepton == "Electron") mLeptonType = pfMETLeptonScale::ELECTRON;
      else throw std::invalid_argument("Invalid lepton type: " + mLepton);
    }

    ~pfMETLeptonScale() {}

    bool Apply(ICF_LorentzV* ob) {

      //check that a RECO muon exists so that we can set up the quantity to be smeared:
      const std::vector<const Lepton*> * leptons = (mLeptonType == MUON) ? &(mEv->LD_CommonMuons().accepted) :
	(mLeptonType == ELECTRON) ? &(mEv->LD_CommonElectrons().accepted) : 0;
      if(!leptons || leptons->size() < 1) return false;

      // initial PFMET
      LorentzV pfMETDefault = *ob;
      // corrected PFMET
      LorentzV corPFMET;
      LorentzV lepcorICFV;
      if (mLeptonType == ELECTRON)
	{throw std::invalid_argument("Invalid lepton type for pfMETLeptonScale, not yet coded: " + mLepton);}

      if (mLeptonType == MUON)
	{
	  // Get muon 4 vector directly from ntuple:
	  int iM = leptons->at(0)->GetIndex();
	  TLorentzVector v;
	  v.SetPxPyPzE(mEv->muonP4()->at(iM).Px(),mEv->muonP4()->at(iM).Py(),mEv->muonP4()->at(iM).Pz(),mEv->muonP4()->at(iM).E());

	  // Get the corrected muon 4 vector
	  TLorentzVector lepcor = MuPtScaleCorrIdealGen(int(leptons->at(0)->GetCharge()), v, false,mEv);
	  lepcorICFV.SetPxPyPzE(lepcor.Px(), lepcor.Py(), lepcor.Pz(), lepcor.E());
	  LorentzV lepuncor;
	  lepuncor.SetPxPyPzE(v.Px(), v.Py(), v.Pz(), v.E());
	  // add th uncorrected and subtract the corrected-> effectively replace uncorrected by corrected muon for PFMET
	  corPFMET = pfMETDefault+lepuncor-lepcorICFV;
	}

      ob->operator=(corPFMET);
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMET replacing scaled lepton of type " << mLepton ;
      return ostrm;
    }

  private:
    bool mGen;
    std::string mLepton;
    enum LeptonType{ ELECTRON, MUON } mLeptonType;
  };


// Replace PFmet by PFMETtype1

  class pfMETtopfMETtypeI : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETtopfMETtypeI(void)
    {
      mModifies = true;
    }

    ~pfMETtopfMETtypeI() {}

    bool Apply(ICF_LorentzV* ob) {
      LorentzV TypeI;
      TypeI.SetPxPyPzE(mEv->metP4pfTypeI()->Px(), mEv->metP4pfTypeI()->Py(), mEv->metP4pfTypeI()->Pz(), mEv->metP4pfTypeI()->E());

      ob->operator=(TypeI);
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "Replacing PF MET with type one PFMET" <<endl;;
      return ostrm;
    }

  private:

  };





// Adapted from WPolFilters.hh and made generic wrt lepton type
// Also pass in factors via PSet
  class pfMETResSmear : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETResSmear(const Utils::ParameterSet & ps) :
      mSmear(ps.Get<double>("Smear")),
      mGenMHTBins(ps.Get<std::vector<double> >("GenMHTBins")),
      mResolutionFactors(ps.Get<std::vector<double> >("ResolutionFactors")),
      mLepton(ps.Get<std::string>("Lepton"))
    { mModifies = true;
      if(mResolutionFactors.size() != mGenMHTBins.size())
        throw std::invalid_argument("pfMETResSmear: Mismatched number of bins/factors.");
      if(mLepton == "Muon") mLeptonType = pfMETResSmear::MUON;
      else if(mLepton == "Electron") mLeptonType = pfMETResSmear::ELECTRON;
      else throw std::invalid_argument("Invalid lepton type: " + mLepton);
    }

    ~pfMETResSmear() {}

    bool Apply(ICF_LorentzV* ob) {

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
      const std::vector<const Lepton*> * leptons = (mLeptonType == MUON) ? &(mEv->LD_CommonMuons().accepted) :
        (mLeptonType == ELECTRON) ? &(mEv->LD_CommonElectrons().accepted) : 0;


      if(!leptons || leptons->size() < 1) return false;

      //construct the RECOMHT:
      LorentzV pfMHT = *ob + *(leptons->at(0));

      // Find the bin we want
      int bin_idx = std::lower_bound(mGenMHTBins.begin(), mGenMHTBins.end(), genMHT.Pt()) -mGenMHTBins.begin() - 1;
      double resolution = mResolutionFactors[bin_idx];

      double smear_factor = TMath::Sqrt(((1.0 + mSmear)*(1.0 + mSmear)) - 1.0) * resolution;
      double newMETscaling = gRandom->Gaus(pfMHT.Pt(), smear_factor * pfMHT.Pt()) / pfMHT.Pt();
      pfMHT.SetPxPyPzE(newMETscaling*pfMHT.X(),newMETscaling*pfMHT.Y(),pfMHT.Z(),pfMHT.E());
      ob->operator=(pfMHT - *(leptons->at(0)));
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMET Resolution Smearing " << mLepton << " (" << mSmear << " relative)";
      return ostrm;
    }

  private:
    double mSmear;
    std::vector<double> mGenMHTBins, mResolutionFactors;
    std::string mLepton;
    enum LeptonType{ ELECTRON, MUON } mLeptonType;
  };

class METResSmearNaive : public Compute::ObjectFilter<ICF_LorentzV> {
 public:
  METResSmearNaive(const std::string lepton, double reslong, double restrans):
      reslong_(reslong),
      restrans_(restrans)
  {
    mModifies = true;
    if(lepton == "Electron") lepton_type_ = ELECTRON;
    else if(lepton == "Muon") lepton_type_ = MUON;
    else throw std::invalid_argument("Invalid lepton type: "+ lepton);
  }

  ~METResSmearNaive(){}

  bool Apply(ICF_LorentzV* ob){
    const Event::Lepton * lep = 0;
    if(lepton_type_ == MUON) lep = mEv->LD_CommonMuons().accepted.size() ?
                                 mEv->LD_CommonMuons().accepted[0] : 0;
    else if(lepton_type_ == ELECTRON) lep = mEv->LD_CommonElectrons().accepted.size() ?
                                          mEv->LD_CommonElectrons().accepted[0] :0;
    if(!lep) return false;

    ICF_LorentzV wpt = *lep + *ob;
    // Get components transverse to wpt in x-y plane
    double px_trans = -wpt.Py();
    double py_trans = wpt.Px();
    // Normalisation to give transverse unit vector
    double norm = 1.0/sqrt(px_trans*px_trans + py_trans*py_trans);
    // Gaussian smearing 7.5% of wpt in transverse plane
    double scale_trans = gRandom->Gaus(0, restrans_*wpt.Pt());
    // Gaussian smearing 15% of wpt in longitudinal direction
    double scale_long = gRandom->Gaus(1, reslong_);
    // Scale to give unit vector and then scale again to give shift along
    // transverse vector direction
    px_trans *= norm*scale_trans;
    py_trans *= norm*scale_trans;
    // Reconstruct the wpt with the longitudinal x,y components smeared by 15%
    // and the transverse x,y components scaled 7.5% of original wpt
    wpt.SetPxPyPzE(wpt.Px()*scale_long + px_trans,
                   wpt.Py()*scale_long + py_trans,
                   wpt.Pz(),
                   wpt.E());
    // Subtract lepton back out
    ob->operator=(wpt - *lep);
    return true;

  }
  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Naive MET Resolution Smearing";
    return ostrm;
  }

 private:
  double reslong_, restrans_;
  enum LeptonType{ ELECTRON, MUON } lepton_type_;
};



class PolarisationReweighting : public Compute::ObjectFilter<double> {

public:
  PolarisationReweighting(const Utils::ParameterSet & ps):
      pt_bins_(ps.Get<std::vector<double> >("PTBins")),
      y_bins_(ps.Get<std::vector<double> >("YBins")),
      alpha_plus_(ps.Get<std::vector<double> >("AlphaPlus")),
      beta_plus_(ps.Get<std::vector<double> >("BetaPlus")),
      gamma_plus_(ps.Get<std::vector<double> >("GammaPlus")),
      alpha_minus_(ps.Get<std::vector<double> >("AlphaMinus")),
      beta_minus_(ps.Get<std::vector<double> >("BetaMinus")),
      gamma_minus_(ps.Get<std::vector<double> >("GammaMinus")),
      lepton_(ps.Get<std::string>("Lepton")),
      fLmfR_shift_(ps.Get<double>("fLmfRShift")),
      debug_(ps.Get<bool>("Debug"))

  {
    mModifies = true;
    if(lepton_ == "Muon") lepton_type_ = PolarisationReweighting::MUON;
    else if(lepton_ == "Electron") lepton_type_ = PolarisationReweighting::ELECTRON;
    else throw std::invalid_argument("Invalid lepton type: " + lepton_);
    if(!((alpha_plus_.size() == beta_plus_.size()) &&
         (beta_plus_.size() == gamma_plus_.size()) &&
         (gamma_plus_.size() == alpha_plus_.size()) &&
         (alpha_minus_.size() == beta_minus_.size()) &&
         (beta_minus_.size() == gamma_minus_.size())))
      throw std::invalid_argument("Factors arrays differ in size");
  }

  ~PolarisationReweighting(){}

  bool Apply( double * weight ) {
    if(! mEv->GenMatrix().hasW()) return false;

    const GenObject* genW = mEv->GenMatrix().w();
    const GenObject* genLep;

    switch(lepton_type_){
      case MUON:
        if(mEv->GenMatrix().hasMuon() && !mEv->GenMatrix().hasTau())
          genLep = mEv->GenMatrix().muon();
        else if(mEv->GenMatrix().hasTau() && ! mEv->GenMatrix().hasMuon())
          genLep = mEv->GenMatrix().tau();
        else return false;
        break;
      case ELECTRON:
        if(mEv->GenMatrix().hasElectron() && !mEv->GenMatrix().hasTau())
          genLep = mEv->GenMatrix().electron();
        else if(mEv->GenMatrix().hasTau() && ! mEv->GenMatrix().hasElectron())
          genLep = mEv->GenMatrix().tau();
        else return false;
        break;
    }

    jSolutionsW jMCSolution;
    TLorentzVector jGenLep = TLVConvert(genLep);
    jMCSolution = FindBoost(jGenLep, genW->Px(), genW->Py(), genW->Pz(), true, false, genW->M());
    if(!jMCSolution.realSolutions) return false;

    int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );

    unsigned int pt_bin_idx = std::lower_bound(pt_bins_.begin(), pt_bins_.end(), genW->Pt()) - pt_bins_.begin() - 1;
    unsigned int y_bin_idx = std::lower_bound(y_bins_.begin(), y_bins_.end(), fabs(genW->Rapidity())) - y_bins_.begin() - 1;
    unsigned int factor_idx = pt_bin_idx*y_bins_.size() + y_bin_idx;

    double alphau, betau, gammau;
    assert(factor_idx < alpha_plus_.size());
    if(genLep->GetID() < 0){
      alphau = alpha_plus_[factor_idx];
      betau = beta_plus_[factor_idx];
      gammau = gamma_plus_[factor_idx];
    }
    else{
      alphau = alpha_minus_[factor_idx];
      betau = beta_minus_[factor_idx];
      gammau = gamma_minus_[factor_idx];
    }

    if(alphau < 0.00001) return false;

    double total = alphau + betau + gammau;
    double alpha, beta, gamma;
    alpha = alphau/total; beta=betau/total; gamma= gammau/total;


    double fLmfR;
    double fLmfR_shifted;
    double alpha_shift;
    double beta_shift;
    if(genLep->GetID() < 0){
      fLmfR = (alpha - beta);
      fLmfR_shifted = (1 + fLmfR_shift_)*fLmfR;
      alpha_shift = (fLmfR_shifted - fLmfR)/2;
      beta_shift = -alpha_shift;
    }
    else{
      fLmfR = (beta - alpha);
      fLmfR_shifted = (1 + fLmfR_shift_)*fLmfR;
      alpha_shift = -(fLmfR_shifted - fLmfR)/2;
      beta_shift = -alpha_shift;
    }

    if(debug_){
      std::cout << " (fL - fR) : " << fLmfR << std::endl;
      std::cout << " Shifted : " << fLmfR_shifted << std::endl;
      std::cout << " Alpha Shifted : " << alpha_shift << std::endl;
      std::cout << " Beta Shifted : " << beta_shift << std::endl;

      std::cout << " Yeah : " << ((alpha + alpha_shift)-(beta+beta_shift)) << std::endl;
      //    assert (((alpha + alpha_shift)-(beta+beta_shift)) == alpha_m_beta);
    }
    double factor = BinFraction(alpha+alpha_shift,
                                beta+beta_shift,
                                gamma, index)/BinFraction(alphau, betau, gammau, index);

    if(debug_) std::cout << "Reweight : " << factor << std::endl;
    *weight *= factor;

    return true;
  }

    std::ostream & Description(std::ostream & ostrm) {
      return ostrm;
    }

 private:
  std::vector<double> pt_bins_, y_bins_;
  std::vector<double> alpha_plus_, beta_plus_, gamma_plus_;
  std::vector<double> alpha_minus_, beta_minus_, gamma_minus_;
  std::string lepton_;
  double fLmfR_shift_;
  bool debug_;
  enum LeptonType{ ELECTRON, MUON } lepton_type_;
  };

class MuPtScale : public Compute::ObjectFilter<Event::Lepton> {
 public:
  MuPtScale(bool doGen):
      mDoGen(false)
  {
    mModifies = true;
  }

  bool Apply(Event::Lepton* ob){
    TLorentzVector v = TLVConvert(ob);

    v = MuPtScaleCorrIdealGen(ob->GetCharge(), v, mDoGen,mEv);

    ob->SetPxPyPzE(v.Px(), v.Py(), v.Pz(), v.E());

    return true;
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "MuPtScale Filter";
    return ostrm;
  }
 private:
  bool mDoGen;
};

  class pfMETScale : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
    pfMETScale(const std::string lepton, double scale):mScaleFactor(scale)
    {
      if(lepton == "Muon") mLepton = pfMETScale::MUON;
      else if(lepton == "Electron") mLepton = pfMETScale::ELECTRON;
      else throw std::invalid_argument("Invalid lepton type: " + lepton);

      mModifies = true;
    }

    ~pfMETScale() {}

    bool Apply(ICF_LorentzV* ob) {
      Event::Lepton const * theRECOLepton;
      if(mLepton == pfMETScale::MUON){
        if(mEv->LD_CommonMuons().accepted.size() >0) theRECOLepton = mEv->LD_CommonMuons().accepted.at(0);
        else return true;
      }
      else if(mLepton == pfMETScale::ELECTRON){
          if(mEv->LD_CommonElectrons().accepted.size() > 0) theRECOLepton = mEv->LD_CommonElectrons().accepted.at(0);
          else return true;
        } else throw std::invalid_argument("Invalid lepton type");
      LorentzV pfUnclustered = *ob + *(theRECOLepton);

      pfUnclustered.SetPxPyPzE(mScaleFactor*pfUnclustered.Px(),
                              mScaleFactor*pfUnclustered.Py(),
                              mScaleFactor*pfUnclustered.Pz(),
                              mScaleFactor*pfUnclustered.E());
      ob->operator=(pfUnclustered - *(theRECOLepton));
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "pfMET Scale: " << mScaleFactor << std::endl;
      return ostrm;
    }

  private:
    double mScaleFactor;
    enum LeptonType{ ELECTRON, MUON } mLepton;

  };


 class pfMETRESUnc : public Compute::ObjectFilter<ICF_LorentzV> {
  public:
   pfMETRESUnc( float factor) 
    
    { mModifies = true; }

    ~pfMETRESUnc() {}

    bool Apply(ICF_LorentzV* ob) {

    
      LorentzV pfUnclustered, scaledjets, myscaledjet;
      //    double unc = 0.0;
      Event::Lepton const * theRECOLepton;
      if(mLepton == "Muon") theRECOLepton = mEv->LD_CommonMuons().accepted.at(0);
      else if(mEv->LD_CommonElectrons().accepted.size() > 0) theRECOLepton = mEv->LD_CommonElectrons().accepted.at(0);
      else if(mEv->LD_Electrons().size() > 0) theRECOLepton = &mEv->LD_Electrons()[0];
      else return true;

     //decide whether the lepton is electron or muon, then add it back into the MET calculation
      cout << " before Res increment" << (*ob+*(theRECOLepton)).Pt() << endl;
   pfUnclustered = *ob + *(theRECOLepton);
   
      //to change to use SecJets, use JD_SecJets, TerJets, JD_TerJets
      for(unsigned int i=0; i< mEv->JD_Jets().size(); i++) {
	//loop through all jets above threshold (in this case the Jets relate to AK5PF2PAT)
	if(mEv->JD_Jets().at(i).Pt() > 10.) {
	  float unc = FindResScale(mEv->JD_Jets().at(i)); // unc is the relative change og the jet PT
	  //add in the jets to the (lepton + neutrino) to leave you with unclustered energy
	  pfUnclustered += (mEv->JD_Jets().at(i));
	  //scale the jets by the Jet RES 
	  myscaledjet = mEv->JD_Jets().at(i) * unc;	  
	  //make a negative vector sum of all the scaled jets
	  scaledjets = -myscaledjet;	
	}
      }
      //shift the unclustered energy either up or down
      //   pfUnclustered *= (1.0 + mUnclusteredShift);
      
      pfUnclustered += scaledjets;

      //std::cout << "scaled MHT: " << pfUnclustered.Pt() << std::endl;
      //finally, add the lepton back into the calculation
      ob->operator=(pfUnclustered - *(theRECOLepton));

      cout << " after Res increment" << (*ob+*(theRECOLepton)).Pt() << endl;
      return true;
    }

   float FindResScale(const Event::Jet& aJet)
   {

     float factor_Res_Corl =1;
     if(fabs(aJet.Eta())<1.1) factor_Res_Corl =1.062;
     if(fabs(aJet.Eta())<1.7&&fabs(aJet.Eta())>1.1) factor_Res_Corl =1.084;
     if(fabs(aJet.Eta())>1.7&&fabs(aJet.Eta())<2.3) factor_Res_Corl =1.029;
     if(fabs(aJet.Eta())>2.3) factor_Res_Corl =1.153;
     
     int index=-1;
     float DR = 0.55;
     int idx=0;
     // find the closest Genjet
     for(std::vector<ICF_LorentzV >::const_iterator ii = mEv->genJetP4()->begin();ii!=mEv->muonP4()->end(); ++ii,++idx)
       {
	 float DR_i = fabs(ROOT::Math::VectorUtil::DeltaPhi(aJet,*ii));
	 if(DR_i<DR)
	   {
	     DR = DR_i;
	     index=idx;
	   }
       }
     float Delta_Meas; // This is the mismeasurement of a jet
     if (index>-1) // if a close jet has been found (0.55 or closer)
       {
	 Delta_Meas = aJet.Pt()-mEv->genJetP4()->at(index).Pt();
       }

     float Increment; // This is the amount by wnich to increase the mismeasurement Delta_Meas
     Increment = Delta_Meas*(factor_Res_Corl-1.);
     float RelError; // This is the relative increment
     RelError = (aJet.Pt()+Increment)/aJet.Pt();
     return RelError;    
   }
   

   std::ostream & Description(std::ostream & ostrm) {
     ostrm << "pfMET systematic from JEC Uncertainties";
     return ostrm;
   }
   
 private:
   std::string mJECUncFile;
   std::string mJECUncFileResisual;
   std::string mLepton;
   double mPFJetThresh;
   double mUnclusteredShift;
   bool mShiftUp;
 };





class JESCorrectionsFromFile : public Compute::ObjectFilter<Event::Jet> {
    
  public:
    
  JESCorrectionsFromFile(bool up, std::string JECUncFile)
      
    {
      mModifies = true;
      Up_bool = up;
      mJECUncFile = JECUncFile;

    }
    
    ~JESCorrectionsFromFile(){} 
    
    bool Apply( Event::Jet* ob ) {
      if (!ob) { return true; }


      Operation::JetCorrectionUncertainty jecUnc(mJECUncFile);
      jecUnc.setJetEta(ob->Eta());
      jecUnc.setJetPt(ob->Pt());
      float unc = jecUnc.getUncertainty(true);     
      // cout << " trulala"<<endl;
      float corfactor;
      if (Up_bool) corfactor=1+unc;
      else corfactor=1-unc;
      ob->SetPxPyPzE(corfactor * ob->Px(),
		     corfactor * ob->Py(),
		     corfactor * ob->Pz(),
		     corfactor * ob->E());
      
      return true;
    }
    
    
    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "Jet Energy Corrections applied to jets"<<endl; 
      return ostrm;
    }
    
  private:
    float  Up_bool ;
  std::string  mJECUncFile;
  };




  // TTbar polarization

class TTPolarisationReweighting : public Compute::ObjectFilter<double> {

public:

  TTPolarisationReweighting(std::string Lepton, double fLmfRShift):
    //    lepton_(Lepton),
    fLmfR_shift_(fLmfRShift)
  //  TTPolarisationReweighting(const Utils::ParameterSet & ps):
    //    pt_bins_(ps.Get<std::vector<double> >("PTBins")),
    //    y_bins_(ps.Get<std::vector<double> >("YBins")),
    //    alpha_plus_(ps.Get<std::vector<double> >("AlphaPlus")),
    //    beta_plus_(ps.Get<std::vector<double> >("BetaPlus")),
    //    gamma_plus_(ps.Get<std::vector<double> >("GammaPlus")),
    //    alpha_minus_(ps.Get<std::vector<double> >("AlphaMinus")),
    //    beta_minus_(ps.Get<std::vector<double> >("BetaMinus")),
    //    gamma_minus_(ps.Get<std::vector<double> >("GammaMinus")),
  //  lepton_(ps.Get<std::string>("Lepton")),
  //    fLmfR_shift_(ps.Get<double>("fLmfRShift"))
    //    debug_(ps.Get<bool>("Debug"))

  {
    mModifies = true;
    if (Lepton == "Muon") lepton_type_ = MUON;
    else if(Lepton == "Electron") lepton_type_ = ELECTRON;
    else throw std::invalid_argument("Invalid lepton type: "+ Lepton);
    //    else throw std::invalid_argument("Invalid lepton type: " + lepton_);
    //    if(!((alpha_plus_.size() == beta_plus_.size()) &&
    //         (beta_plus_.size() == gamma_plus_.size()) &&
    //         (gamma_plus_.size() == alpha_plus_.size()) &&
    //         (alpha_minus_.size() == beta_minus_.size()) &&
    //         (beta_minus_.size() == gamma_minus_.size())))
    //      throw std::invalid_argument("Factors arrays differ in size");
  }

  ~TTPolarisationReweighting(){}

  bool Apply( double * weight ) {


    GenMatrixBin myGenMatrixBin(mEv);

    // events with Top
    bool noTop = false;
    if(!mEv->GenMatrix().hasTop()) { noTop = true; *weight *= 1.; return true; }

    // events with one and only one muon/electron
    int NGenMuons     = myGenMatrixBin.the_GenMuon.size();
    int NGenElectrons = myGenMatrixBin.the_GenEli.size();
    int NGenTaus      = myGenMatrixBin.the_GenTau.size();


    bool wrongLepCounting = false;
    if ( (NGenMuons==1 && NGenElectrons!=0) || (NGenElectrons==1 && NGenMuons!=0) || (NGenTaus!=0) ) { wrongLepCounting = true; *weight *= 1.; return true; }

    const Event::GenObject* genTop;
    const Event::GenObject* genW;
    const Event::GenObject* genLep;


    if(lepton_type_ == MUON) {
      for ( std::vector<Event::GenObject const *>::const_iterator iGMu = myGenMatrixBin.the_GenMuon.begin();
	    iGMu != myGenMatrixBin.the_GenMuon.end();
	    iGMu++ ) {
	genLep = (*iGMu);
      }
    }
    else if(lepton_type_ == ELECTRON) {
      for ( std::vector<Event::GenObject const *>::const_iterator iGEl = myGenMatrixBin.the_GenEli.begin();
	    iGEl != myGenMatrixBin.the_GenEli.end();
	    iGEl++ ) {
	genLep = (*iGEl);
      }
    }


    // only leptons comming from Ws
    bool motherNotW = false;
    if (abs(genLep->GetMotherID())!=24) { motherNotW = true; *weight *= 1.; return true; }

    //find which W gave the lepton
    for ( std::vector<Event::GenObject const *>::const_iterator iGW = myGenMatrixBin.the_GenW.begin();
	  iGW != myGenMatrixBin.the_GenW.end();
	  iGW++ ) {

      if ( ((*iGW)->GetIndex()) == (genLep->GetMother()) ) { genW = (*iGW); }

    } // ~end of looping over the GenWs


    for ( std::vector<Event::GenObject const *>::const_iterator iGTop = myGenMatrixBin.the_GenTop.begin();
	  iGTop != myGenMatrixBin.the_GenTop.end();
	  iGTop++ ) {

      if ( ((*iGTop)->GetIndex()) == (genW->GetMother()) ) { genTop = (*iGTop); }

    } // ~end of looping over the GenTops


    TLorentzVector jGenLep = TLVConvert(genLep);
    TLorentzVector jGenW   = TLVConvert(genW);
    TLorentzVector jGenTop = TLVConvert(genTop);

    TLorentzVector jGenLepOnWRestFrame;
    TLorentzVector jGenWInTopFrame;

    TVector3 boostW, boostTop;
    boostW   = jGenW.BoostVector();
    boostTop = jGenTop.BoostVector();

    jGenLepOnWRestFrame   = jGenLep;
    jGenLepOnWRestFrame.Boost(-boostW);

    jGenWInTopFrame = jGenW;
    jGenWInTopFrame.Boost(-boostTop);


    double CosThetaCM = cos(ROOT::Math::VectorUtil::Angle(jGenLepOnWRestFrame,jGenWInTopFrame));


    double f0 = 0.714;
    double fL = 0.251;
    double fR = 0.034; // this remains unchanged

    // change them by this "fLmfR_shift_" i.e. +5% 0.05
    double fL_changed = fL*(1.+fLmfR_shift_);
    double f0_changed = 1.-fR-fL_changed;
    //      cout << fLmfR_shift_ << " " << fL << " " << fL_changed << " " << f0 << " " << f0_changed << "\n";

    double result = (
		     f0*((1-(CosThetaCM*CosThetaCM))/2.) +
		     fL*((pow((1.-CosThetaCM),2))/4.)    +
		     fR*((pow((1.+CosThetaCM),2))/4.)
		     );


    double result_changed = (
			     f0_changed*((1-(CosThetaCM*CosThetaCM))/2.) +
			     fL_changed*((pow((1.-CosThetaCM),2))/4.)    +
			     fR*((pow((1.+CosThetaCM),2))/4.)
			     );

    double factor = result_changed/result;

    //      cout << result << " " << result_changed << " " << factor << " " << CosThetaCM << "\n" ;

    if ( (!noTop) && (!wrongLepCounting) && (!motherNotW) ) { *weight *= factor; }
    else { *weight *= 1.; }

    return true;
  }

    std::ostream & Description(std::ostream & ostrm) {
      return ostrm;
    }

 private:
  //  std::vector<double> pt_bins_, y_bins_;
  //  std::vector<double> alpha_plus_, beta_plus_, gamma_plus_;
  //  std::vector<double> alpha_minus_, beta_minus_, gamma_minus_;
  //  std::string lepton_;
  double fLmfR_shift_;
  //  bool debug_;
  enum LeptonType{ ELECTRON, MUON } lepton_type_;
  };







}

