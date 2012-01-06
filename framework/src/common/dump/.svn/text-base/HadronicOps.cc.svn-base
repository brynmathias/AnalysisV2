/*! \file HadronicOps.cc
 * \brief Source code for the hadronic operation.
 */
#include "HadronicOps.hh"

#include "Lepton.hh"
#include "EventData.hh"

#include <string>
#include <iostream>

namespace Operation {

  //===========
  // Trigger cut
  //===========
  TriggerCut::TriggerCut(Int_t bit) :
    mTriggerBit(bit) {} 

  TriggerCut::~TriggerCut() {}
  
  bool TriggerCut::Process(Event::Data & ev) {
    // JJ - added range check
    if ( ev.nHLT() <= mTriggerBit ) {
      throw std::invalid_argument("Selected trigger bit is outside range of data");
    }
    return (ev.HLTArray()[mTriggerBit]);
  }

  std::ostream& TriggerCut::Description(std::ostream &ostrm) {
    ostrm << "TriggerBit " << mTriggerBit << " passed ";
    return ostrm;
  }

  //===========
  // SumET cut
  //===========
  HTCut::HTCut(float sumEt) :
  mSumEtCutVal(sumEt) {}

  HTCut::~HTCut() {}

  bool HTCut::Process(Event::Data & ev) {

    return (ev.CommonHT() > mSumEtCutVal);
  }

  std::ostream& HTCut::Description(std::ostream &ostrm) {
    ostrm << "HT " << mSumEtCutVal << " GeV ";
    return ostrm;
  }



  //===========
  // alpha_t cut
  //===========
  alpha_t_had::alpha_t_had(float altcut) :
  maltCutVal(altcut) {}

  alpha_t_had::~alpha_t_had() {}

  bool alpha_t_had::Process(Event::Data & ev) {
    if (ev.JD_CommonJets().accepted.size()<2 ||
	ev.JD_CommonJets().accepted.size()>6) return false;
    if (ev.hadAlpha_t() > maltCutVal) return true;
    return false;
  }

  std::ostream& alpha_t_had::Description(std::ostream &ostrm) {
    ostrm << " alpha_t_had " << maltCutVal  ;
    return ostrm;
  }

  //===========
  // dphi_muon_commht cut
  //===========
  dphi_muon_commht::dphi_muon_commht(float dphicut_min, float dphicut_max) :
  mdphicut_min(dphicut_min), mdphicut_max(dphicut_max) {}

  dphi_muon_commht::~dphi_muon_commht() {}

  bool dphi_muon_commht::Process(Event::Data & ev) {

    if (ev.LD_CommonMuons().accepted.size()>0 && ev.CommonMHT().Pt() > 0){
      if ( (fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonMuons().accepted[0],ev.CommonMHT())) > mdphicut_min)
	   && (fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonMuons().accepted[0],ev.CommonMHT())) < mdphicut_max) ) return true;
    }
    return false;
  }

  std::ostream& dphi_muon_commht::Description(std::ostream &ostrm) {
    ostrm << " dphi_muon_commht Min: " << mdphicut_min << " Max: " << mdphicut_max  ;
    return ostrm;
  }

  //===========
  // ratio_muon_commht cut
  //===========
  ratio_muon_commht::ratio_muon_commht(float ratio_mumht_cut) :
  mratio_mumht_cut(ratio_mumht_cut) {}

  ratio_muon_commht::~ratio_muon_commht() {}

  bool ratio_muon_commht::Process(Event::Data & ev) {

    if (ev.LD_CommonMuons().accepted.size()>0 && ev.CommonMHT().Pt() > 0){
      if ( ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt() > mratio_mumht_cut ) return true;
    }
    return false;
  }

  std::ostream& ratio_muon_commht::Description(std::ostream &ostrm) {
    ostrm << " ratio_muon_commht " << mratio_mumht_cut ;
    return ostrm;
  } 
} //~namespace Operation
