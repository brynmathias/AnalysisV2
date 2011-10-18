#include "Dalitz.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "HemisphereAlgo.hh"
#include "Jet.hh"
#include "JetData.hh"
#include "KinSuite.hh"
#include "Math/VectorUtil.h"
#include "mt2_bisect.hh"
#include "ThrustStuff.hh"
#include "TH1D.h"
#include "TH2D.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>

#include "Math/GenVector/PtEtaPhiM4D.h"
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > PolarLV;

/*
  - pthat
  - mht cleaning
  - aT/HT scatter, different binning?
  - truth!!
*/

using namespace Operation;

// -----------------------------------------------------------------------------
//
bool SortByPt( const LorentzV& first, const LorentzV& second ) {
  return ( first.Pt() > second.Pt() );
}

// -----------------------------------------------------------------------------
//
bool SortByEt( const LorentzV& first, const LorentzV& second ) {
  return ( first.Et() > second.Et() );
}

// -----------------------------------------------------------------------------
//
Dalitz::Dalitz( const Utils::ParameterSet& ps ) :
  // Misc
  doHtHistos_(true),
  doMeffHistos_(true),
  dirName_("Dalitz"),
  nMin_(2),
  nMax_(10),
  verbose_(false),
  norm_(2.),
  scale_(true),
  maxJetEta_(0.),
  maxLeadingJetEta_(0.),
  // Analysis defaults
  alphaT_(),
  ht_(0.),
  meff_(0.),
  pt1_(0.),
  pt2_(0.),
  pt3_(0.),
  // Binning
  htNbins_(0),
  htXlow_(0.),
  htXhigh_(0.),
  htBins_(),
  htPt1Bins_(),
  htPt2Bins_(),
  htPt3Bins_(),
  meffNbins_(0),
  meffXlow_(0.),
  meffXhigh_(0.),
  meffBins_(),
  meffPt1Bins_(),
  meffPt2Bins_(),
  meffPt3Bins_(),
  // pT hat
  gPtHatAllEvents_(),
  // Sanity check
  hPreMeffRhoRho_(),
  hPreMeffPhiPhi_(),
  hPreMeffSigma3_(),
  hPreMeffRadius_(),
  hPreMeffAlphaT_(),
  hPreMeffMht_(),
  hPreMeffMt2_(),
  hPreMeffCombo_(),
  hPreMeffPhiAB_(),
  hPreMeffPhimB_(),
  hPostMeffRhoRho_(),
  hPostMeffPhiPhi_(),
  hPostMeffSigma3_(),
  hPostMeffRadius_(),
  hPostMeffAlphaT_(),
  hPostMeffMht_(),
  hPostMeffMt2_(),
  hPostMeffCombo_(),
  hPostMeffPhiAB_(),
  hPostMeffPhimB_()
{
  
  // Optional parameters
  if ( ps.Contains("DirName") ) dirName_ = ps.Get<std::string>("DirName");
  if ( ps.Contains("MinObjects") ) nMin_ = ps.Get<int>("MinObjects");
  if ( ps.Contains("MaxObjects") ) nMax_ = ps.Get<int>("MaxObjects");
  if ( ps.Contains("Verbose") ) verbose_ = ps.Get<bool>("Verbose");
  
  // Required parameters
  maxLeadingJetEta_ = ps.Get<double>("MaxLeadingJetEta");
  alphaT_ = ps.Get< std::vector<double> >("AlphaT"); 
  scale_ = ps.Get<bool>("Scale"); 
  ht_ = ps.Get<double>("HT"); 
  meff_ = ps.Get<double>("Meff");
  pt1_ = ps.Get<double>("MinJetPt1");
  pt2_ = ps.Get<double>("MinJetPt2");
  pt3_ = ps.Get<double>("MinJetPt3");
  htNbins_ = (uint)ps.Get<int>("HtNbins"); 
  htXlow_ = ps.Get<double>("HtXlow"); 
  htXhigh_ = ps.Get<double>("HtXhigh"); 
  meffNbins_ = (uint)ps.Get<int>("MeffNbins"); 
  meffXlow_ = ps.Get<double>("MeffXlow"); 
  meffXhigh_ = ps.Get<double>("MeffXhigh"); 

  // Define binning in terms of HT, Meff and pT thresholds
  binning();
  
  // CHECK: if specified, ensure that min pT is greater than or equal to value used for "common jets"
  if ( ps.Contains("MinJetPt") &&
       Utils::Config::Instance().Contains("Common.Jets.PtCut") &&
       pt3_ < Utils::GetConfig<double>("Common.Jets.PtCut") ) { 
    std::cerr << " WARNING! 'MinJetPt' (" << pt3_ 
	      << ") is less than 'Common.Jets.PtCut' (" 
	      << Utils::GetConfig<double>("Common.Jets.PtCut")
	      << ")" << std::endl;
  }

  // Retrieve eta threshold for "common" jets
  maxJetEta_ = ps.Get<double>("MaxJetEta");

  // Add 0. cut value 
  alphaT_.insert( alphaT_.begin(), 0. );

}

// -----------------------------------------------------------------------------
//
Dalitz::~Dalitz() {
}

// -----------------------------------------------------------------------------
//
std::ostream& Dalitz::Description( std::ostream& ss ) {
  ss << "[Dalitz::Description]" 
     << std::endl
     << " Writing histograms to directory \"" << dirName_ << "\""
     << "for events with " << nMin_ << "<objects<" << nMax_ << "."
     << std::endl
     << " Verbose=" << verbose_ 
     << std::endl;

  ss << " Thresholds scaled according to HT bins:" << std::endl
     << " --------------------------------------------------------" << std::endl
     << " |  HT  |    (pT1,pT2,pT3) | Meff |          (x1,x2,x3) |" << std::endl
     << " --------------------------------------------------------" << std::endl;
  for ( uint ii = 0; ii < htNbins_; ++ii ) {
    double ht = htBins_[ii];
    double pt1 = htPt1Bins_[ii];
    double pt2 = htPt2Bins_[ii];
    double pt3 = htPt3Bins_[ii];
    double meff = htBins_[ii] + htPt3Bins_[ii];
    ss << " | " << std::setw(4) << std::setprecision(3) << ht
       << " | (" << std::setw(4) << std::setprecision(3) << pt1
       << "," << std::setw(4) << std::setprecision(3) << pt2
       << "," << std::setw(4) << std::setprecision(3) << pt3
       << ") | " << std::setw(4) << std::setprecision(3) << meff
       << " | (" << std::setw(5) << std::setprecision(3) << (norm_*pt1/meff)
       << "," << std::setw(5) << std::setprecision(3) << (norm_*pt2/meff) 
       << "," << std::setw(5) << std::setprecision(3) << (norm_*pt3/meff) 
       << ") |" << std::endl;
  }
  ss << " --------------------------------------------------------" << std::endl;

  ss << " Thresholds scaled according to Meff bins:" << std::endl
     << " -------------------------------------------------" << std::endl
     << " | Meff |    (pT1,pT2,pT3) |          (x1,x2,x3) |" << std::endl
     << " -------------------------------------------------" << std::endl;
  for ( uint ii = 0; ii < meffNbins_; ++ii ) {
    double meff = meffBins_[ii];
    double pt1 = meffPt1Bins_[ii];
    double pt2 = meffPt2Bins_[ii];
    double pt3 = meffPt3Bins_[ii];
    ss << " | " << std::setw(4) << std::setprecision(3) << meff
       << " | (" << std::setw(4) << std::setprecision(3) << pt1
       << "," << std::setw(4) << std::setprecision(3) << pt2
       << "," << std::setw(4) << std::setprecision(3) << pt3
       << ") | (" << std::setw(5) << std::setprecision(3) << (norm_*pt1/meff)
       << "," << std::setw(5) << std::setprecision(3) << (norm_*pt2/meff) 
       << "," << std::setw(5) << std::setprecision(3) << (norm_*pt3/meff) 
       << ") |" << std::endl;
  }
  ss << " -------------------------------------------------" << std::endl;
  ss << std::fixed << std::setprecision(8);
  return ss;

}

// -----------------------------------------------------------------------------
//
void Dalitz::binning() {

  // HT binning
  for ( uint ii = 0; ii < htNbins_; ++ii ) { 
    double width = ( htXhigh_ - htXlow_ ) / htNbins_;
    htBins_.push_back(htXlow_+width*ii);
  }

  // Meff binning
  for ( uint ii = 0; ii < meffNbins_; ++ii ) { 
    double width = ( meffXhigh_ - meffXlow_ ) / meffNbins_;
    meffBins_.push_back(meffXlow_+width*ii);
  }
  
  // Normalisation: x_{1} + x_{2} + x_{3} = norm

  // pT thresholds that scale with HT
  double meff_default = ht_ + pt3_;
  double x3_default = ( norm_ * pt3_ ) / meff_default; 
  double x3_factor = ( norm_ - x3_default ) / x3_default;
  std::vector<double>::const_iterator iht = htBins_.begin();
  std::vector<double>::const_iterator jht = htBins_.end();
  for ( ; iht != jht; ++iht ) {
    double ht = *iht;
    double pt3 = ht / x3_factor;
    double meff = pt3 + ht;
    double pt1 = pt1_ * meff / meff_default;
    double pt2 = pt2_ * meff / meff_default;
    htPt1Bins_.push_back( scale_ ? pt1 : pt1_ );
    htPt2Bins_.push_back( scale_ ? pt2 : pt2_ );
    htPt3Bins_.push_back( scale_ ? pt3 : pt3_ );
  }

  // pT thresholds that scale with HT
  std::vector<double>::const_iterator imeff = meffBins_.begin();
  std::vector<double>::const_iterator jmeff = meffBins_.end();
  for ( ; imeff != jmeff; ++imeff ) {
    double meff = *imeff;
    double pt1 = pt1_ * meff / meff_;
    double pt2 = pt2_ * meff / meff_;
    double pt3 = pt3_ * meff / meff_;
    meffPt1Bins_.push_back( scale_ ? pt1 : pt1_ );
    meffPt2Bins_.push_back( scale_ ? pt2 : pt2_ );
    meffPt3Bins_.push_back( scale_ ? pt3 : pt3_ );
  }
   
}

// -----------------------------------------------------------------------------
//
bool Dalitz::Process( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();
  
  // Retrieve "common" jets from ntuple
  std::vector<Event::Jet const*> common = ev.JD_CommonJets().accepted;

  // Retrieve "odd" jets from ntuple
  std::vector<Event::Jet const*> odd = ev.JD_CommonJets().odd;

  // Retrieve "raw" jets from ntuple
  std::vector<LorentzV> raw = *(ev.jetP4());

  // Two loops, one for HT, one for Meff
  for ( uint ii = 0; ii < 2; ++ii ) {
    if ( ii == 0 && !doHtHistos_ ) { continue; }
    if ( ii == 1 && !doMeffHistos_ ) { continue; }

    // Number of HT/Meff bins 
    uint nbins = 0;
    if ( ii == 0 ) { nbins = htNbins_; }
    if ( ii == 1 ) { nbins = meffNbins_; }

    // MHT in signal region
    double mht_reco_signal = 0.;
    
    // Loop through HT/Meff bins 
    for ( uint jbin = 0; jbin < nbins; ++jbin ) {
      uint ibin = (nbins-1) - jbin;

      // Scaling factor for MET
      double scaling_factor = 0.;
      if ( ii == 0 ) { scaling_factor = htBins_[ibin] / htBins_[nbins-1]; }
      if ( ii == 1 ) { scaling_factor = meffBins_[ibin] / meffBins_[nbins-1]; }
      
      // Define jet pT thresholds 
      double pt1_threshold = 0.;
      double pt2_threshold = 0.;
      double pt3_threshold = 0.;
      if ( ii == 0 ) { 
	pt1_threshold = htPt1Bins_[ibin];
	pt2_threshold = htPt2Bins_[ibin];
	pt3_threshold = htPt3Bins_[ibin];
      } 
      if ( ii == 1 ) {
	pt1_threshold = meffPt1Bins_[ibin];
	pt2_threshold = meffPt2Bins_[ibin];
	pt3_threshold = meffPt3Bins_[ibin];
      }
      
      // -------------------- RECO INFO --------------------

      // Calculate aT, HT, Meff and MHT from common jets
      std::vector<LorentzV> reco; 
      reco.reserve(10);
      LorentzV mht_reco(0.,0.,0.,0.);
      double at_reco = 0.;
      double ht_reco = 0.;
      double meff_reco = 0.;
      double x1_reco = 0.;
      double x2_reco = 0.;
      double mt2_reco = 0.;

      // Raw jets
      std::vector<LorentzV> raw_jets; 
      raw_jets.reserve(10);
      LorentzV mht_raw(0.,0.,0.,0.);
      double ht_raw = 0.;
      double meff_raw = 0.;

      // Loop through common jets and calc "reco" variables
      std::vector<Event::Jet const*>::const_iterator ireco = common.begin();
      std::vector<Event::Jet const*>::const_iterator jreco = common.end();
      for ( ; ireco != jreco; ++ireco ) {
// 	if ( (*ireco)->Pt() > pt3_threshold ) { 
// 	  reco.push_back(**ireco); 
// 	  ht_reco += (*ireco)->Et();
// 	  mht_reco -= **ireco;
//  	}
	LorentzV tmp(**ireco);// PolarLV((*ireco)->Et(),(*ireco)->Eta(),(*ireco)->Phi(),0.) );

// 	std::cout << " orig: " 
// 		  << (*ireco)->E() << " "
// 		  << (*ireco)->P() << " "
// 		  << (*ireco)->Et() << " "
// 		  << (*ireco)->Pt() << " "
// 		  << (*ireco)->Px() << " "
// 		  << (*ireco)->Py() << " "
// 		  << (*ireco)->Pz() << " "
// 		  << (*ireco)->M() << " "
// 		  << std::endl;
// 	std::cout << " new:  " 
// 		  << tmp.E() << " "
// 		  << tmp.P() << " "
// 		  << tmp.Et() << " "
// 		  << tmp.Pt() << " "
// 		  << tmp.Px() << " "
// 		  << tmp.Py() << " "
// 		  << tmp.Pz() << " "
// 		  << tmp.M() << " "
// 		  << std::endl;

	if ( tmp.Pt() > pt3_threshold ) { 
	  reco.push_back(tmp); 
	  ht_reco += tmp.Et();
	  mht_reco -= tmp;
 	}
      }

      // Meff
      meff_reco = ht_reco + mht_reco.Pt();
      
      // Calc AlphaT and Dalitz variables
      at_reco = calcDalitzVars( reco, mht_reco, x1_reco, x2_reco, mt2_reco );

      // MHT in signal region
      if ( nbins-ibin == 1 ) { mht_reco_signal = mht_reco.Pt(); }
      
      // Loop through "raw" jets and calc MHT(10)
      std::vector<LorentzV>::const_iterator iraw = raw.begin();
      std::vector<LorentzV>::const_iterator jraw = raw.end();
      for ( ; iraw != jraw; ++iraw ) {
	if ( iraw->Pt() > (10./50.) * pt3_threshold &&
	     fabs(iraw->Eta()) < maxJetEta_ ) {
	  raw_jets.push_back(*iraw); 
	  ht_raw += iraw->Et();
	  mht_raw -= *iraw;
	}
      }
      meff_raw = ht_raw + mht_raw.Pt();
    
      // Odd jet veto
      bool odd_jet_veto = false;
      std::vector<Event::Jet const*>::const_iterator iodd = odd.begin();
      std::vector<Event::Jet const*>::const_iterator jodd = odd.end();
      for ( ; iodd != jodd; ++iodd ) {
        if ( (*iodd)->Pt() >= pt3_threshold ) { odd_jet_veto = true; }
      }

      // Order jets by pT
      std::sort( reco.begin(), reco.end(), SortByPt );
      
      // Check multiplicity and pT of leading and second jets
      bool jet_multiplicity = ( reco.size() >= 2 );
      bool leading_jet_pt   = ( reco.size() > 0 && reco[0].Pt() > pt1_threshold );
      bool second_jet_pt    = ( reco.size() > 1 && reco[1].Pt() > pt2_threshold );
      bool leading_jet_eta  = ( reco.size() > 0 && fabs(reco[0].Eta()) < maxLeadingJetEta_ );
      
      // Check if event falls within appropriate HT or Meff bin (last bin is inclusive)
      bool correct_reco_bin = false;
      if ( ii == 0 ) { 
	double ht_lower = htBins_[ibin];
	double ht_upper = ( (nbins-ibin) != 1 ? htBins_[ibin+1] : 10000. ); 
	if ( ht_reco > ht_lower && ht_reco < ht_upper ) { correct_reco_bin = true; }
      } 
      if ( ii == 1 ) { 
	double meff_lower = meffBins_[ibin];
	double meff_upper = ( (nbins-ibin) != 1 ? meffBins_[ibin+1] : 10000. ); 
	if ( meff_reco > meff_lower && meff_reco < meff_upper ) { correct_reco_bin = true; }
      }

      // -------------------- Meff RECO --------------------
      
      if ( ii == 1 ) {
	
	if ( correct_reco_bin && 
	     jet_multiplicity &&
	     !odd_jet_veto
	     ) {
	  
	  fill( reco.size(), hPreMeffRhoRho_[0], x2_reco, x1_reco, weight ); 
	  fill( reco.size(), hPreMeffRhoRho_[ibin+1], x2_reco, x1_reco, weight ); 

	  fill( reco.size(), 
		hPreMeffPhiPhi_[0], 
		phi_mB(x1_reco/norm_,x2_reco/norm_), 
		phi_AB(x1_reco/norm_,x2_reco/norm_), 
		weight ); 

	  fill( reco.size(), 
		hPreMeffPhiPhi_[ibin+1], 
		phi_mB(x1_reco/norm_,x2_reco/norm_), 
		phi_AB(x1_reco/norm_,x2_reco/norm_), 
		weight ); 
	  
	  fill( reco.size(), hPreMeffSigma3_[0], sigma3(x1_reco,x2_reco), weight ); 
	  fill( reco.size(), hPreMeffSigma3_[ibin+1], sigma3(x1_reco,x2_reco), weight ); 

	  fill( reco.size(), hPreMeffRadius_[0], radius(x1_reco,x2_reco), weight ); 
	  fill( reco.size(), hPreMeffRadius_[ibin+1], radius(x1_reco,x2_reco), weight ); 

	  fill( reco.size(), hPreMeffAlphaT_[0], at_reco, weight ); 
	  fill( reco.size(), hPreMeffAlphaT_[ibin+1], at_reco, weight ); 

	  fill( reco.size(), hPreMeffMht_[0], mht_reco.Pt(), weight ); 
	  fill( reco.size(), hPreMeffMht_[ibin+1], mht_reco.Pt(), weight ); 

	  fill( reco.size(), hPreMeffMt2_[0], mt2_reco, weight ); 
	  fill( reco.size(), hPreMeffMt2_[ibin+1], mt2_reco, weight ); 

	  fill( reco.size(), hPreMeffPhiAB_[0], phi_AB(x1_reco/norm_,x2_reco/norm_), weight ); 
	  fill( reco.size(), hPreMeffPhiAB_[ibin+1], phi_AB(x1_reco/norm_,x2_reco/norm_), weight ); 

	  fill( reco.size(), hPreMeffPhimB_[0], phi_mB(x1_reco/norm_,x2_reco/norm_), weight ); 
	  fill( reco.size(), hPreMeffPhimB_[ibin+1], phi_mB(x1_reco/norm_,x2_reco/norm_), weight ); 

// 	  if ( at_reco > 0.5 ) {
// 	    fill( reco.size(), hPreMeffCombo_[0], radius(x1_reco,x2_reco), weight ); 
// 	    fill( reco.size(), hPreMeffCombo_[ibin+1], radius(x1_reco,x2_reco), weight ); 
// 	  }

	  if ( leading_jet_pt &&
	       second_jet_pt &&
	       leading_jet_eta 
	       ) {
	    
	    fill( reco.size(), hPostMeffRhoRho_[0], x2_reco, x1_reco, weight ); 
	    fill( reco.size(), hPostMeffRhoRho_[ibin+1], x2_reco, x1_reco, weight ); 

	    fill( reco.size(), 
		  hPostMeffPhiPhi_[0], 
		  phi_mB(x1_reco/norm_,x2_reco/norm_), 
		  phi_AB(x1_reco/norm_,x2_reco/norm_), 
		  weight ); 
	    fill( reco.size(), 
		  hPostMeffPhiPhi_[ibin+1], 
		  phi_mB(x1_reco/norm_,x2_reco/norm_), 
		  phi_AB(x1_reco/norm_,x2_reco/norm_), 
		  weight ); 
	    
	    fill( reco.size(), hPostMeffSigma3_[0], sigma3(x1_reco,x2_reco), weight ); 
	    fill( reco.size(), hPostMeffSigma3_[ibin+1], sigma3(x1_reco,x2_reco), weight ); 
	    
	    fill( reco.size(), hPostMeffRadius_[0], radius(x1_reco,x2_reco), weight ); 
	    fill( reco.size(), hPostMeffRadius_[ibin+1], radius(x1_reco,x2_reco), weight ); 

	    fill( reco.size(), hPostMeffAlphaT_[0], at_reco, weight ); 
	    fill( reco.size(), hPostMeffAlphaT_[ibin+1], at_reco, weight ); 
	    
	    fill( reco.size(), hPostMeffMht_[0], mht_reco.Pt(), weight ); 
	    fill( reco.size(), hPostMeffMht_[ibin+1], mht_reco.Pt(), weight ); 

	    fill( reco.size(), hPostMeffMt2_[0], mt2_reco, weight ); 
	    fill( reco.size(), hPostMeffMt2_[ibin+1], mt2_reco, weight ); 
	    
	    fill( reco.size(), hPostMeffPhiAB_[0], phi_AB(x1_reco/norm_,x2_reco/norm_), weight ); 
	    fill( reco.size(), hPostMeffPhiAB_[ibin+1], phi_AB(x1_reco/norm_,x2_reco/norm_), weight ); 
	    
	    fill( reco.size(), hPostMeffPhimB_[0], phi_mB(x1_reco/norm_,x2_reco/norm_), weight ); 
	    fill( reco.size(), hPostMeffPhimB_[ibin+1], phi_mB(x1_reco/norm_,x2_reco/norm_), weight ); 
	    
// 	    if ( at_reco > 0.5 ) {
// 	      fill( reco.size(), hPostMeffCombo_[0], radius(x1_reco,x2_reco), weight ); 
// 	      fill( reco.size(), hPostMeffCombo_[ibin+1], radius(x1_reco,x2_reco), weight ); 
// 	    }
	    
	  }

	}

      } // Meff ( ii == 1 )
      
    } // nBins
    
  } // HT or Meff
  
  return false;
  
}

// -----------------------------------------------------------------------------
//
double Dalitz::calcDalitzVars( const std::vector<LorentzV>& jets, 
			       const LorentzV& mht, 
			       double& x1, 
			       double& x2,
			       double& mt2 ) {
  
  if ( jets.size() < 2 ) { return -1.; }

  std::vector<bool> pseudo;
  double at = AlphaT()( jets, pseudo );

  // Construct pseudo di-jets
  double ht = 0.;
  double et1 = 0.;
  double et2 = 0.;
  std::vector<LorentzV> dijets(2,LorentzV(0.,0.,0.,0.));
  if (true) {
    for ( unsigned int i = 0; i < jets.size(); ++i ) {
      ht += jets[i].Et(); 
      if ( pseudo[i] ) { dijets[0] = dijets[0] + jets[i]; et1 += jets[i].Et(); }
      else             { dijets[1] = dijets[1] + jets[i]; et2 += jets[i].Et(); }
    }
  } else if (false) {
    HemisphereAlgo hemi( jets, 2, 3 );
    std::vector<int> group = hemi.getGrouping();
    for ( unsigned int i = 0; i < jets.size(); ++i ) {
      if ( group[i] == 0 ) {
	std::cout << " n: " << group.size() << " n:" << jets.size() << " i: " << i << " group: " << group[i] << std::endl;
      }
      ht += jets[i].Et(); 
      if      ( group[i] == 1 ) { dijets[0] = dijets[0] + jets[i]; et1 += jets[i].Et(); }
      else if ( group[i] == 2 ) { dijets[1] = dijets[1] + jets[i]; et2 += jets[i].Et(); }
      else { std::cout << "ERROR!!!!" << std::endl; }
    }
  } else {
    ThrustStuff t(jets);
    dijets[0] = t.Pjet1;
    dijets[1] = t.Pjet2;
  }

  if ( false ) { 
    if ( dijets[1].Pt() > dijets[0].Pt() ) {
      double tmp = et2;
      et2 = et1;
      et1 = tmp;
      LorentzV temp = dijets[1];
      dijets[1] = dijets[0];
      dijets[0] = temp;
    }
    //std::sort( dijets.begin(), dijets.end(), SortByPt );
  } else {
    if ( et2 > et1 ) {
      double tmp = et2;
      et2 = et1;
      et1 = tmp;
      LorentzV temp = dijets[1];
      dijets[1] = dijets[0];
      dijets[0] = temp;
    }
  }

  // Calculate x1, x2
  if ( false ) {
    x1 = ( norm_ * dijets[0].Pt() ) / ( dijets[0].Pt() + dijets[1].Pt() + mht.Pt() );
    x2 = ( norm_ * dijets[1].Pt() ) / ( dijets[0].Pt() + dijets[1].Pt() + mht.Pt() );
  } else {
    x1 = ( norm_ * et1 ) / ( et1 + et2 + mht.Pt() );
    x2 = ( norm_ * et2 ) / ( et1 + et2 + mht.Pt() );
  }

  if ( false ) {

    double x11 = ( norm_ * et1 ) / ( et1 + et2 + mht.Pt() );
    double x22 = ( norm_ * et2 ) / ( et1 + et2 + mht.Pt() );
    double at2 = x2/(2*sqrt(x1+x2-1));
    double at3 = x22/(2*sqrt(x11+x22-1));
    if (fabs(at2-at)>1.e-6) {

      std::stringstream sss;
      sss << "JETS: "
	  << std::endl;
      for ( unsigned int i = 0; i < jets.size(); ++i ) {
	sss << " i: " << i 
	    << " ET: " << jets[i].Et()
	    << " Pt: " << jets[i].Pt()
	    << " E: " << jets[i].E()
	    << " P: " << jets[i].P()
	    << " Px: " << jets[i].Px()
	    << " Py: " << jets[i].Py()
	    << " M: " << jets[i].M()
	    << " 1? " << ( pseudo[i] ? "true" : "false" )
	    << std::endl;
      }
    
      sss << "PSEUDO-JETS: " 
	  << std::endl
	  << " i: 0"
	  << " ET: " << dijets[0].Et()
	  << " Pt: " << dijets[0].Pt()
	  << " E: " << dijets[0].E()
	  << " P: " << dijets[0].P()
	  << " Px: " << dijets[0].Px()
	  << " Py: " << dijets[0].Py()
	  << " M: " << dijets[0].M()
	  << " n: " << std::count( pseudo.begin(), pseudo.end(), true )
	  << " x1: " << x1
	  << " ET1: " << et1
	  << std::endl;

      sss << " i: 1"
	  << " ET: " << dijets[1].Et()
	  << " Pt: " << dijets[1].Pt()
	  << " E: " << dijets[1].E()
	  << " P: " << dijets[1].P()
	  << " Px: " << dijets[1].Px()
	  << " Py: " << dijets[1].Py()
	  << " M: " << dijets[1].M()
	  << " n: " << std::count( pseudo.begin(), pseudo.end(), false )
	  << " x2: " << x2
	  << " ET2: " << et2 
	  << std::endl;

      sss << "MISC: " 
	  << std::endl
	  << " HT: " << ht
	  << " DHT: " << ( et1 - et2 )
	  << " MHT: " << mht.Pt()
	  << std::endl
	  << " aT from algo: " << at 
	  << " aT from DHT/MHT: " << 0.5 * ( ( ht - ( et1 - et2 ) ) / sqrt( ht*ht - mht.Pt()* mht.Pt() ) )
	  << " aT from x_i: " << at2
	  << " aT from x_ii: " << at3
	  << std::endl;
    
      std::cout << sss.str() << std::endl;

    }

  }
  
  // MT2

  mt2_bisect::mt2 mt2_event;

  double pa[3]; // jet 1
  double pb[3]; // jet 2
  double pm[3]; // mht
  double mn = 0.; // neutrilino mass 

  pa[0] = dijets[0].Px();
  pa[1] = dijets[0].Py();
  pa[2] = 0.; // MT
  
  pb[0] = dijets[1].Px();
  pb[1] = dijets[1].Py();
  pb[2] = 0.; // MT

  pm[1]= mht.Px();
  pm[2]= mht.Py();

  mt2_event.set_momenta(pa,pb,pm);
  mt2_event.set_mn(mn);
  
  mt2 = mt2_event.get_mt2();

  return at;

}
  
// -----------------------------------------------------------------------------
//
double Dalitz::sigma3( double x1,double x2 ) {
  return ( x1 < 1. && x2 < 1. ? (x1*x1+x2*x2)/((1-x1)*(1-x2)) : -1. ); 
}
  
// -----------------------------------------------------------------------------
//
double Dalitz::radius( double x1,double x2 ) {
  return sqrt(x1*x1+x2*x2);
}

// -----------------------------------------------------------------------------
//
double Dalitz::phi_AB( double x1,double x2 ) {
  return ( 3.14159265 - acos( ( x1*x1 + x2*x2 - (1-x2-x1)*(1-x2-x1) ) / (2*x2*x1) ) );
}

// -----------------------------------------------------------------------------
//
double Dalitz::phi_mB( double x1,double x2 ) {
  return ( 3.14159265 - acos( ( x1*x1 - x2*x2 + (1-x2-x1)*(1-x2-x1) ) / (2*x2*(1-x2-x1)) ) );
}

// -----------------------------------------------------------------------------
//
void Dalitz::fill( uint multiplicity,
		   std::vector<TH1D*>& his,
		   double valx,
		   double weight ) {
  
  if ( !his.empty() && 
       multiplicity >= nMin_ ) { 
    if ( his[0] ) his[0]->Fill( valx, weight ); 
  }
  if ( multiplicity >= nMin_ && 
       multiplicity <= nMax_ && 
       multiplicity < his.size() ) { 
    if ( his[multiplicity] ) his[multiplicity]->Fill( valx, weight ); 
  }

}

// -----------------------------------------------------------------------------
//
void Dalitz::fill( uint multiplicity,
		   std::vector<TH2D*>& his,
		   double x, 
		   double y,
		   double weight ) {
  
  if ( !his.empty() && 
       multiplicity >= nMin_ ) { 
    if ( his[0] ) { his[0]->Fill( x, y, weight ); }
  }
  if ( multiplicity >= nMin_ && 
       multiplicity <= nMax_ &&
       multiplicity < his.size() ) { 
    if ( his[multiplicity] ) { his[multiplicity]->Fill( x, y, weight ); }
  }

}

// -----------------------------------------------------------------------------
//
void Dalitz::Start( Event::Data& ev ) {

  // Top-level directory
  initDir( ev.OutputFile(), dirName_.c_str() );

  if ( doMeffHistos_ ) {

    hPreMeffRhoRho_.resize( meffNbins_+1, vTH2D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffRhoRho_" << meff(ii);
      BookHistArray( hPreMeffRhoRho_[ii], 
		     ss.str(),
		     ";x_{2};x_{1}",
		     100, 0., 1., 
		     100, 0., 1.,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffPhiPhi_.resize( meffNbins_+1, vTH2D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffPhiPhi_" << meff(ii);
      BookHistArray( hPreMeffPhiPhi_[ii], 
		     ss.str(),
		     ";#phi_{m1};#phi_{12}",
		     80, 0., 3.2, 
		     80, 0., 3.2, 
		     nMax_+1, 0, 1, true );
    }

    hPreMeffSigma3_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffSigma3_" << meff(ii);
      BookHistArray( hPreMeffSigma3_[ii], 
		     ss.str(),
		     ";#sigma_{3};",
		     1000, 0., 1000.,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffRadius_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffRadius_" << meff(ii);
      BookHistArray( hPreMeffRadius_[ii], 
		     ss.str(),
		     ";#sqrt{x_{1}^{2}+x_{2}^{2}};",
		     1500, 0., 1.5,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffAlphaT_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffAlphaT_" << meff(ii);
      BookHistArray( hPreMeffAlphaT_[ii], 
		     ss.str(),
		     ";#alpha_{T};",
		     1500, 0., 1.5,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffMht_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffMht_" << meff(ii);
      BookHistArray( hPreMeffMht_[ii], 
		     ss.str(),
		     ";H_{T}^{miss};",
		     1500, 0., 1500,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffMt2_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffMt2_" << meff(ii);
      BookHistArray( hPreMeffMt2_[ii], 
		     ss.str(),
		     ";M_{T2};",
		     1500, 0., 1500,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffPhiAB_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffPhiAB_" << meff(ii);
      BookHistArray( hPreMeffPhiAB_[ii], 
		     ss.str(),
		     ";#phi_{12};",
		     1600, 0., 3.2,
		     nMax_+1, 0, 1, true );
    }

    hPreMeffPhimB_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PreMeffPhimB_" << meff(ii);
      BookHistArray( hPreMeffPhimB_[ii], 
		     ss.str(),
		     ";#phi_{m1};",
		     1600, 0., 3.2,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffRhoRho_.resize( meffNbins_+1, vTH2D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffRhoRho_" << meff(ii);
      BookHistArray( hPostMeffRhoRho_[ii], 
		     ss.str(),
		     ";x_{2};x_{1}",
		     100, 0., 1., 
		     100, 0., 1.,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffPhiPhi_.resize( meffNbins_+1, vTH2D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffPhiPhi_" << meff(ii);
      BookHistArray( hPostMeffPhiPhi_[ii], 
		     ss.str(),
		     ";#phi_{m1};#phi_{12}",
		     80, 0., 3.2, 
		     80, 0., 3.2, 
		     nMax_+1, 0, 1, true );
    }

    hPostMeffSigma3_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffSigma3_" << meff(ii);
      BookHistArray( hPostMeffSigma3_[ii], 
		     ss.str(),
		     ";#sigma_{3};",
		     1000, 0., 1000.,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffRadius_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffRadius_" << meff(ii);
      BookHistArray( hPostMeffRadius_[ii], 
		     ss.str(),
		     ";#sqrt{x_{1}^{2}+x_{2}^{2}};",
		     1500, 0., 1.5,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffAlphaT_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffAlphaT_" << meff(ii);
      BookHistArray( hPostMeffAlphaT_[ii], 
		     ss.str(),
		     ";#alpha_{T};",
		     1500, 0., 1.5,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffMht_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffMht_" << meff(ii);
      BookHistArray( hPostMeffMht_[ii], 
		     ss.str(),
		     ";H_{T}^{miss};",
		     1500, 0., 1500,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffMt2_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffMt2_" << meff(ii);
      BookHistArray( hPostMeffMt2_[ii], 
		     ss.str(),
		     ";M_{T2};",
		     1500, 0., 1500,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffPhiAB_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffPhiAB_" << meff(ii);
      BookHistArray( hPostMeffPhiAB_[ii], 
		     ss.str(),
		     ";#phi_{12};",
		     1600, 0., 3.2,
		     nMax_+1, 0, 1, true );
    }

    hPostMeffPhimB_.resize( meffNbins_+1, vTH1D() );
    for ( uint ii = 0; ii <= meffNbins_; ++ii ) { 
      std::stringstream ss;
      ss << "PostMeffPhimB_" << meff(ii);
      BookHistArray( hPostMeffPhimB_[ii], 
		     ss.str(),
		     ";#phi_{m1};",
		     1600, 0., 3.2,
		     nMax_+1, 0, 1, true );
    }

  }

}

// -----------------------------------------------------------------------------
//
std::string Dalitz::ht( int ii ) {
  std::stringstream ss;
  if ( ii == 0 ) { ss << "HT0"; }
  else { ss << "HT" << (int(10.*htBins_[ii-1])/10.); }
  return ss.str();
}

// -----------------------------------------------------------------------------
//
std::string Dalitz::meff( int ii ) {
  std::stringstream ss;
  if ( ii == 0 ) { ss << "Meff0"; }
  else { ss << "Meff" << (int(10.*meffBins_[ii-1])/10.); }
  return ss.str();
}

// -----------------------------------------------------------------------------
//
std::string Dalitz::at( int ii ) {
  std::stringstream ss;
  ss << "aT" << alphaT_[ii]; 
  return ss.str();
}
