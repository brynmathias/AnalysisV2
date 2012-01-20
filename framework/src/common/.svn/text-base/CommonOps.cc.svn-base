/*! \file CommonOps.cc
 * \brief Source code for the operations on common physics objects.
 */
#include "CommonOps.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "Lepton.hh"
#include "KinSuite.hh"
#include "ThrustStuff.hh"
#include <iostream>
#include <fstream>
#include "Types.hh"

namespace Operation {

  //===============================================
  // "Number of common leptons" cut
  //===============================================
  NumComLeptons::NumComLeptons(const std::string & comparison,
             UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumComLeptons::~NumComLeptons() { delete mComparison; }

  bool NumComLeptons::Process(Event::Data & ev) {
    // The Compare method is part of the Operation namespace - see BaseOps.hh/cc for code.
    // It's my first template!
    //return Compare<UInt_t>(UInt_t(ev.ComEls.size()) + UInt_t(ev.ComMus.size()),
    return (*mComparison)(UInt_t(ev.LD_CommonElectrons().accepted.size()) + UInt_t(ev.LD_CommonMuons().accepted.size()),
        mNumber);
  }

  std::ostream& NumComLeptons::Description(std::ostream &ostrm) {
    ostrm << "NumComLeptons Operation (num e + mu " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }

 //
  //===============================================
  // "Number of common electrons" cut
  //===============================================

  NumComElectrons::NumComElectrons(const std::string & comparison,
           UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumComElectrons::~NumComElectrons() { delete mComparison; }

  bool NumComElectrons::Process(Event::Data & ev) {
    // The Compare method is part of the Operation namespace - see BaseOps.hh/cc for code.
    // It's my first template!
    return (*mComparison)(UInt_t(ev.LD_CommonElectrons().accepted.size()),
        mNumber);
  }

  std::ostream& NumComElectrons::Description(std::ostream &ostrm) {
    ostrm << "NumComElectrons Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }

 //
  //===============================================
  // "Number of common taus" cut
  //===============================================

  NumComTaus::NumComTaus(const std::string & comparison,
           UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumComTaus::~NumComTaus() { delete mComparison; }

  bool NumComTaus::Process(Event::Data & ev) {
    // The Compare method is part of the Operation namespace - see BaseOps.hh/cc for code.
    // It's my first template!
    return (*mComparison)(UInt_t(ev.LD_CommonTaus().accepted.size()),
        mNumber);
  }

  std::ostream& NumComTaus::Description(std::ostream &ostrm) {
    ostrm << "NumComTaus Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }



  //
  //===============================================
  // "Number of common muons" cut
  //===============================================

  NumComMuons::NumComMuons(const std::string & comparison,
         UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumComMuons::~NumComMuons() { delete mComparison; }

  bool NumComMuons::Process(Event::Data & ev) {
    return (*mComparison)(UInt_t(ev.LD_CommonMuons().accepted.size()),
        mNumber);
  }

  std::ostream& NumComMuons::Description(std::ostream &ostrm) {
    ostrm << "NumComMuons Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }

  
    NumCommonBtagJets::NumCommonBtagJets (const std::string & comparison, UInt_t number, float cutValue):
    mCut(cutValue),
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  

    NumCommonBtagJets::~NumCommonBtagJets(){ delete mComparison; }
    bool NumCommonBtagJets::Process(Event::Data & ev){
      UInt_t nBtags = 0;
      for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
        // std::cout << "we are on jet " << i << " the btag discriminator is " << ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 4) << std::endl;
       if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 4) > mCut) {
         nBtags++;
         //if we make it into here, the jet has passed the b-tag requirement
         
       }
       // std::cout<< "Number of btags so far = " << nBtags << std::endl;
      }
      return (*mComparison)(nBtags,mNumber);
    }
    std::ostream& NumCommonBtagJets::Description(std::ostream& ostrm) {
    ostrm << "NumComBtagsJets Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ") with BTag cut " << mCut << " ";
    return ostrm;
  }
  

  //================
  // Recoil MET Cut
  //================
  RecoilMETCut::RecoilMETCut(float mhtVal) :
    mMHTvalue(mhtVal) {}

  RecoilMETCut::~RecoilMETCut() {}

  bool RecoilMETCut::Process(Event::Data & ev) {
    if (ev.CommonRecoilMET().Pt() > mMHTvalue) return true;
    return false;
  }

  std::ostream& RecoilMETCut::Description(std::ostream &ostrm) {
    ostrm << "RecoilMETCut (MHT > " << mMHTvalue << " GeV): ";
    return ostrm;
  }

  //================
  // calo MET Cut
  //================
  caloMETCut::caloMETCut(float mhtVal) :
    mMHTvalue(mhtVal) {}

  caloMETCut::~caloMETCut() {}

  bool caloMETCut::Process(Event::Data & ev) {
    if (ev.CaloMET().Pt()>mMHTvalue) return true;
    return false;
  }

  std::ostream& caloMETCut::Description(std::ostream &ostrm) {
    ostrm << "caloMETCut (MHT > " << mMHTvalue << " GeV): ";
    return ostrm;
  }

  //================
  // tc MET Cut
  //================
  tcMETCut::tcMETCut(float mhtVal) :
    mMHTvalue(mhtVal) {}

  tcMETCut::~tcMETCut() {}

  bool tcMETCut::Process(Event::Data & ev) {
    if (ev.TCMET().Pt()>mMHTvalue) return true;
    return false;
  }

  std::ostream& tcMETCut::Description(std::ostream &ostrm) {
    ostrm << "tcMETCut (MHT > " << mMHTvalue << " GeV): ";
    return ostrm;
  }

#ifdef _ICF_
  //================
  // PFMET Cut
  //================
  PFMETCut::PFMETCut(float metVal) :
    mMETvalue(metVal) {}

  PFMETCut::~PFMETCut() {}

  bool PFMETCut::Process(Event::Data & ev) {
    if (ev.PFMET().Pt()>mMETvalue) return true;
    return false;
  }

  std::ostream& PFMETCut::Description(std::ostream &ostrm) {
    ostrm << "PF METCut> " << mMETvalue << " GeV): ";
    return ostrm;
  }
#endif





//================
  //  calo MET Cut
  //================
  Jet1JDphiMETCut::Jet1JDphiMETCut(float mhtVal) :
  mMHTvalue(mhtVal) {}

  Jet1JDphiMETCut::~Jet1JDphiMETCut() {}

  bool Jet1JDphiMETCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size() < 1) return true;//true if less than 1 jet
    else if (fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.RecoilMET(),*ev.JD_CommonJets().accepted[0]))>mMHTvalue) return true;
    return false;
  }

  std::ostream& Jet1JDphiMETCut::Description(std::ostream &ostrm) {
    ostrm << "Jet1JDphiMETCut > " << mMHTvalue ;
    return ostrm;
  }

   //================
  // cut on 2. jet <-> MHT dphi
  //================//================
   Jet2JDphiMETCut::Jet2JDphiMETCut(float mhtVal) :
     mMHTvalue(mhtVal) {}

  Jet2JDphiMETCut::~Jet2JDphiMETCut() {}

  bool Jet2JDphiMETCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size() <= 1) return true;//true if less than 2 jets
    else if( fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.RecoilMET(),*ev.JD_CommonJets().accepted[1]))>mMHTvalue) return true;
    //else cout << ev.ComRecoilMET.Pt() <<endl;
    return false;
  }

  std::ostream& Jet2JDphiMETCut::Description(std::ostream &ostrm) {
    ostrm << "Jet2JDphiMETCut  " << mMHTvalue;
    return ostrm;
  }

  //================
  // cut on 3. jet <-> MHT dphi
  //================
  Jet3JDphiMETCut::Jet3JDphiMETCut(float mhtVal) :
  mMHTvalue(mhtVal) {}

  Jet3JDphiMETCut::~Jet3JDphiMETCut() {}

  bool Jet3JDphiMETCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size() <= 2) return true; //true if less than 3 jets
     else if( fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.RecoilMET(),*ev.JD_CommonJets().accepted[2]))>mMHTvalue) return true;
    //else cout << ev.ComRecoilMET.Pt() <<endl;
    return false;
  }

  std::ostream& Jet3JDphiMETCut::Description(std::ostream &ostrm) {
    ostrm << "Jet3JDphiMETCut  " << mMHTvalue;
    return ostrm;
  }





  //================
  // calo MET Cut
  //================
  DRMETCut::DRMETCut(float mhtVal) :
  mMHTvalue(mhtVal) {}

  DRMETCut::~DRMETCut() {}

  bool DRMETCut::Process(Event::Data & ev) {

    // cout << ev.GetR1() << " " << ev.GetR2() <<endl;
    if(ev.GetR1(ev.RecoilMET())<mMHTvalue) return false;
    if(ev.GetR2(ev.RecoilMET())<mMHTvalue) return false;
    return true;
 }

  std::ostream& DRMETCut::Description(std::ostream &ostrm) {
    ostrm << "DR Cut > " << mMHTvalue;
    return ostrm;
  }

//================
  // RECO Cut on CommonJet MHT (MHT = negative vector sum of jets)
  //================

  CommonMHTCut::CommonMHTCut(float MHTCut) :
  mMHTCut(MHTCut) {}

  CommonMHTCut::~CommonMHTCut() {}

  bool CommonMHTCut::Process(Event::Data & ev) {

    if(ev.CommonMHT().Pt() > mMHTCut) return true;
    else return false;
  }

  std::ostream& CommonMHTCut::Description(std::ostream &ostrm) {
    ostrm << "CommonMHTCut (make a cut on the Pt of vector sum of RecoCommonJets) " ;
    return ostrm;
  }

  //================
  // Cut on AlphaT from CommonObjects
  //================

  CommonAlphaTCut::CommonAlphaTCut(float AlphaTCut) :
    mAlphaTCut(AlphaTCut) {}

  CommonAlphaTCut::~CommonAlphaTCut() {}

  bool CommonAlphaTCut::Process(Event::Data & ev) {
    if ( ev.CommonObjects().size() >= 1 &&
   ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN() ) {
      if ( ev.CommonAlphaT() > mAlphaTCut ) return true;
    }
    return false;
  }

  std::ostream& CommonAlphaTCut::Description(std::ostream &ostrm) {
    ostrm << "CommonAlphaTCut " ;
    return ostrm;
  }

  //================
  // Recoil MHT Cut
  //================
  RecoilMHTCut::RecoilMHTCut(float mhtVal) :
  mMHTvalue(mhtVal) {}

  RecoilMHTCut::~RecoilMHTCut() {}

  bool RecoilMHTCut::Process(Event::Data & ev) {
    if (ev.CommonRecoilMET().Pt() > mMHTvalue) return true;
    // else cout << ev.ComMHT.Et() <<endl;
    return false;
  }

  std::ostream& RecoilMHTCut::Description(std::ostream &ostrm) {
    ostrm << "RecoilMHTCut (MHT > " << mMHTvalue << " GeV): ";
    return ostrm;
  }

  //================
  // HT cut
  //================

  HTCut::HTCut(float sumEt)
    : mSumEtCutVal(sumEt)
  {;}

  bool HTCut::Process(Event::Data & ev) {
    return (ev.CommonHT() > mSumEtCutVal);
  }

  std::ostream& HTCut::Description(std::ostream &ostrm) {
    ostrm << "HT " << mSumEtCutVal << " GeV ";
    return ostrm;
  }


  //================
  // HT LessThan cut
  //================

  HTLessThanCut::HTLessThanCut(float sumEt)
    : mSumEtCutVal(sumEt)
  {;}

  bool HTLessThanCut::Process(Event::Data & ev) {
    return (ev.CommonHT() < mSumEtCutVal);
  }

  std::ostream& HTLessThanCut::Description(std::ostream &ostrm) {
    ostrm << "HT less than" << mSumEtCutVal << " GeV ";
    return ostrm;
  }

  //===========
  // SumET cut
  //===========
  SumETCut::SumETCut(float sumEt) :
    mSumEtCutVal(sumEt) {}

  SumETCut::~SumETCut() {}

  bool SumETCut::Process(Event::Data & ev) {
    return (ev.CommonSumEt() > mSumEtCutVal);
  }

  std::ostream& SumETCut::Description(std::ostream &ostrm) {
    ostrm << "SumETCut (Sum ET > " << mSumEtCutVal << " GeV): ";
    return ostrm;
  }

  //===========
  // SumET cut Max
  //===========
  SumETCutMax::SumETCutMax(float sumEtMax) :
    mSumEtCutMaxVal(sumEtMax) {}

  SumETCutMax::~SumETCutMax() {}

  bool SumETCutMax::Process(Event::Data & ev) {
    return (ev.CommonSumEt() <= mSumEtCutMaxVal);
  }

  std::ostream& SumETCutMax::Description(std::ostream &ostrm) {
    ostrm << "SumETCutMax (Sum ET <= " << mSumEtCutMaxVal << " GeV): ";
    return ostrm;
  }

 //===========
  // non-biased dphi cut
  //===========
  DPhiCut::DPhiCut(float dphi) :
  mSumEtCutVal(dphi) {}

  DPhiCut::~DPhiCut() {}

  bool DPhiCut::Process(Event::Data & ev) {
    return (ev.CommonRecoilMETJetDPhi() > mSumEtCutVal);
  }

  std::ostream& DPhiCut::Description(std::ostream &ostrm) {
    ostrm << " DPhi >  " << mSumEtCutVal << " rad): ";
    return ostrm;
  }


  //===========
  // Jet MET Min dphi cut
  //===========
  JetMETMinDPhiCut::JetMETMinDPhiCut(float value) :
  mCutVal(value) {}

  JetMETMinDPhiCut::~JetMETMinDPhiCut() {}

  bool JetMETMinDPhiCut::Process(Event::Data & ev) {
    return (ev.JetMETMinDPhi() > mCutVal);
  }

  std::ostream& JetMETMinDPhiCut::Description(std::ostream &ostrm) {
    ostrm << "JetMETMinDPhi >  " << mCutVal << ": ";
    return ostrm;
  }

  //===========
  // biased dphi cut
  //===========
  biasedDPhiCut::biasedDPhiCut(float sumEt) :
  mSumEtCutVal(sumEt) {}

  biasedDPhiCut::~biasedDPhiCut() {}

  bool biasedDPhiCut::Process(Event::Data & ev) {
    return (ev.JetMinBiasDPhi() > mSumEtCutVal);
  }

  std::ostream& biasedDPhiCut::Description(std::ostream &ostrm) {
    ostrm << "biased DPhi >  " << mSumEtCutVal << " GeV): ";
    return ostrm;
  }

  //===========
  // Recoil/SumET
  //===========
  RecoilMET_ov_SumETCut::RecoilMET_ov_SumETCut(float value) :
  mRMET_SumEt(value) {}

  RecoilMET_ov_SumETCut::~RecoilMET_ov_SumETCut() {}

  bool RecoilMET_ov_SumETCut::Process(Event::Data & ev) {
    return (ev.CommonRecoilMET().Pt()/ev.CommonSumEt() > mRMET_SumEt);
  }

  std::ostream& RecoilMET_ov_SumETCut::Description(std::ostream &ostrm) {
    ostrm << "RecoilMET over SumETCut  > " << mRMET_SumEt << " GeV): ";
    return ostrm;
  }

  //===========
  // AK5CaloMET
  //===========
  AK5CaloMETCut::AK5CaloMETCut(float value) :
  mAK5CaloMET(value) {}

  AK5CaloMETCut::~AK5CaloMETCut() {}

  bool AK5CaloMETCut::Process(Event::Data & ev) {
    return (ev.AK5MET().Pt() > mAK5CaloMET);
  }

  std::ostream& AK5CaloMETCut::Description(std::ostream &ostrm) {
    ostrm << "AK5CaloMET  > " << mAK5CaloMET << " GeV): ";
    return ostrm;
  }

  //===========
  // MeffCut MHT+HT
  //===========
  MeffCut::MeffCut(float value) :
  mRMET_SumEt(value) {}

  MeffCut::~MeffCut() {}

  bool MeffCut::Process(Event::Data & ev) {
    return (ev.CommonRecoilMET().Pt()+ev.CommonSumEt() > mRMET_SumEt);
  }

  std::ostream& MeffCut::Description(std::ostream &ostrm) {
    ostrm << "Meff cut  > " << mRMET_SumEt << " GeV): ";
    return ostrm;
  }


 //===========
  // TDRHT Cut
  //===========
  TDRHTCut::TDRHTCut(float value) :
  mRMET_SumEt(value) {}

  TDRHTCut::~TDRHTCut() {}

  bool TDRHTCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<1) return false;
    return (ev.CommonRecoilMET().Pt()+ev.CommonSumEt()-ev.JD_CommonJets().accepted[0]->Pt() > mRMET_SumEt);
  }

  std::ostream& TDRHTCut::Description(std::ostream &ostrm) {
    ostrm << "TDRHT cut  > " << mRMET_SumEt << " GeV): ";
    return ostrm;
  }



 //===========
  // First Jet eta Cut
  //===========
  firstJetetaCut::firstJetetaCut(float value) :
  mCut(value) {}

  firstJetetaCut::~firstJetetaCut() {}

  bool firstJetetaCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<1) return false;
    return ( fabs(ev.JD_CommonJets().accepted[0]->Eta()) < mCut);
  }

  std::ostream& firstJetetaCut::Description(std::ostream &ostrm) {
    ostrm << " first Jet Eta < " << mCut << " rad): ";
    return ostrm;
  }



  //===========
  // First Jet Pt Cut
  //===========
  firstJetPtCut::firstJetPtCut(float value) :
  mCut(value) {}

  firstJetPtCut::~firstJetPtCut() {}

  bool firstJetPtCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<1) return false;
    return ( ev.JD_CommonJets().accepted[0]->Pt() > mCut);
  }

  std::ostream& firstJetPtCut::Description(std::ostream &ostrm) {
    ostrm << "First jet Pt > " << mCut << " GeV: ";
    return ostrm;
  }



  //===========
  // First Jet Et Cut
  //===========
  firstJetEtCut::firstJetEtCut(float value) :
  mCut(value) {}

  firstJetEtCut::~firstJetEtCut() {}

  bool firstJetEtCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<1) return false;
    return ( ev.JD_CommonJets().accepted[0]->Pt() > mCut);
  }

  std::ostream& firstJetEtCut::Description(std::ostream &ostrm) {


    ostrm << " first Jet Pt > " << mCut << " GeV): ";
    return ostrm;
  }

  //============
  // missed MHT Cut
  //============
  missedHTcut::missedHTcut(float value) :
    mCut(value) {}

  missedHTcut::~missedHTcut() {}

  bool missedHTcut::Process(Event::Data & ev) {
    return( ev.CommonRecoilMET().Pt()/(ev.CommonRecoilMET()+ev.JD_CommonJets().killedHT).Pt()<mCut);
  }

  std::ostream& missedHTcut::Description(std::ostream &ostrm) {
    ostrm << "(missed MHT vev - MHT vec).Pt()/MHT.Pt() " << mCut << " " ;
    return ostrm;
  }

  //===========
  // Second Jet Et Cut
  //===========
  secondJetEtCut::secondJetEtCut(float value) :
  mCut(value) {}

  secondJetEtCut::~secondJetEtCut() {}

  bool secondJetEtCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<2) return false;
    return ( ev.JD_CommonJets().accepted[1]->Pt() > mCut);
  }

  std::ostream& secondJetEtCut::Description(std::ostream &ostrm) {
    ostrm << "Second jet Pt > " << mCut << " GeV: ";
    return ostrm;
  }


 //===========
  // Photon Pt Cut
  //===========
  PhotonPtCut::PhotonPtCut(float value) :
  mCut(value) {}

  PhotonPtCut::~PhotonPtCut() {}

  bool PhotonPtCut::Process(Event::Data & ev) {
    if(ev.PD_CommonPhotons().accepted.size()==0) return true;
    return (ev.PD_CommonPhotons().accepted[0]->Pt() > mCut );
  }

  std::ostream& PhotonPtCut::Description(std::ostream &ostrm) {
    ostrm << "Leading Photon Pt > " << mCut << " GeV: ";
    return ostrm;
  }

//================
  // RECO Cut on DeltaR between closest jet and photon
  //================

  PhotonJetDRCut::PhotonJetDRCut(float MuonJetDRCut) :
  mMuonJetDRCut(MuonJetDRCut) {}

  PhotonJetDRCut::~PhotonJetDRCut() {}

  bool PhotonJetDRCut::Process(Event::Data & ev) {

    if(ev.PD_CommonPhotons().accepted.size() == 0 ) return true; //i.e. no muons exist!
    if(ev.JD_CommonJets().accepted.size() == 0 ) return true; //i.e. no jets exist
    for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
      if(fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.PD_CommonPhotons().accepted.at(0))))<mMuonJetDRCut) return false ;

   }
    return true; //i.e. if we have looped over all muons and found none of them in a jet, return true
  }

  std::ostream& PhotonJetDRCut::Description(std::ostream &ostrm) {
    ostrm << "PhotonJetDRCut (make a cut on the DeltaR between the muon and the closest jet) " ;
    return ostrm;
  }

  //===========
  // Alpha_t Cut
  //===========
  alpha_tCut::alpha_tCut(float value) :
  mCut(value) {}

  alpha_tCut::~alpha_tCut() {}

  bool alpha_tCut::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<2) return false;
    return ( ev.HadronicAlphaT()> mCut);
  }

  std::ostream& alpha_tCut::Description(std::ostream &ostrm) {
    ostrm << "Alpha_t  > " << mCut << " GeV): ";
    return ostrm;
  }


  //===========
  // Alpha_t Cut Less than value
  //===========
  alpha_tCut_Less::alpha_tCut_Less(float value) :
  mCut(value) {}

  alpha_tCut_Less::~alpha_tCut_Less() {}

  bool alpha_tCut_Less::Process(Event::Data & ev) {
    if(ev.JD_CommonJets().accepted.size()<2) return false;
    return ( ev.HadronicAlphaT()< mCut);
  }

  std::ostream& alpha_tCut_Less::Description(std::ostream &ostrm) {
    ostrm << "Alpha_t  < " << mCut << " GeV): ";
    return ostrm;
  }


  //===========================
  // "Number of good jets" Cut
  //===========================

  NumComJets::NumComJets(const std::string & comparison,
         UInt_t number) :
    mNumber(number) {
        if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumComJets::~NumComJets() { delete mComparison; }

  bool NumComJets::Process(Event::Data & ev) {
    return (*mComparison)(UInt_t(ev.JD_CommonJets().accepted.size()),
                          mNumber);
  }

  std::ostream& NumComJets::Description(std::ostream &ostrm) {
    ostrm << "NumComJets Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }


//_________________________________________________________

  //===========
  // BTag the two High Pt Jet
//===========

BtagResponse::BtagResponse(float cut,int njetnumber, int algo): cut_(cut),algo_(algo),njetnumber_(njetnumber) {}

bool BtagResponse::Process(Event::Data & ev) {
        bool response=ev.GetBTagResponse(ev.JD_CommonJets().accepted[njetnumber_]->GetIndex(), algo_)>cut_;
        return response;
}

std::ostream& BtagResponse::Description(std::ostream &ostrm) {
//    ostrm << "Using b-tagging on "<<njetnumber_<<"-th jet with algo number "<<algo_<<endl;
    return ostrm;
}


//________________________________________________________


  //===========================
  // "Number of good photons" Cut
  //===========================

  NumComPhotons::NumComPhotons(const std::string & comparison,
       UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumComPhotons::~NumComPhotons() { delete mComparison; }

  bool NumComPhotons::Process(Event::Data & ev) {
    //return Compare<UInt_t>(UInt_t(ev.ComPhs.size()), mComparison, mNumber);
    return (*mComparison)(UInt_t(ev.PD_CommonPhotons().accepted.size()),
        mNumber);
  }

  std::ostream& NumComPhotons::Description(std::ostream &ostrm) {
    ostrm << "Number of Common Photons " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }




  //===========================
  // odd Oject Cut, meaning a ojects failed loose quility criteria
  //===========================

  OddObject::OddObject() {}
  OddObject::~OddObject() {}

  bool OddObject::Process(Event::Data & ev) {
    return !(ev.JD_CommonJets().hasOdd || ev.LD_CommonElectrons().hasOdd || ev.LD_CommonMuons().hasOdd || ev.PD_CommonPhotons().hasOdd);
  }

  std::ostream& OddObject::Description(std::ostream &ostrm) {
    ostrm << "Check if an Object failed loose Quality criteria";
    return ostrm;
  }


  //=================================================================
  // OddPhoton
  //=================================================================
  OddPhoton::OddPhoton() {}
  OddPhoton::~OddPhoton() {}

  bool OddPhoton::Process(Event::Data & ev) { return !ev.PD_CommonPhotons().hasOdd; }

  std::ostream& OddPhoton::Description(std::ostream &ostrm) {
    ostrm << "Check if a photon failed loose quality criteria";
    return ostrm;
  }
  //=================================================================

  //=================================================================
  // OddElecton
  //=================================================================
  OddElectron::OddElectron() {}
  OddElectron::~OddElectron() {}

  bool OddElectron::Process(Event::Data & ev) { return !ev.LD_CommonElectrons().hasOdd; }

  std::ostream& OddElectron::Description(std::ostream &ostrm) {
    ostrm << "Check if a electron failed loose quality criteria";
    return ostrm;
  }
  //=================================================================

  //=================================================================
  // OddJet
  //=================================================================
  OddJet::OddJet() {}
  OddJet::~OddJet() {}

  bool OddJet::Process(Event::Data & ev) { return !ev.JD_CommonJets().hasOdd; }

  std::ostream& OddJet::Description(std::ostream &ostrm) {
    ostrm << "Check if a jet failed loose quality criteria";
    return ostrm;
  }
  //=================================================================

  //=================================================================
  // PhotkilledJet
  //=================================================================
  PhotkilledJet::PhotkilledJet() {}
  PhotkilledJet::~PhotkilledJet() {}

  bool PhotkilledJet::Process(Event::Data & ev) {

    for (std::vector<Event::Jet>::const_iterator iJ = ev.JD_Jets().begin();
   iJ != ev.JD_Jets().end();
   ++iJ)
      {
        if(true) {
          cout << "This function is deprecieated and always returns true" <<endl;
          continue;
          }
  if(iJ->Pt()<25) continue;// killed jets

  for (std::vector<Event::Photon>::const_iterator iph = ev.PD_Photons().begin();
       iph != ev.PD_Photons().end();
       ++iph) {
      if( fabs( ROOT::Math::VectorUtil::DeltaR (*iJ,*iph) ) < 0.5 ) {
        if(iph->Pt()<0.5*iJ->Pt()) return false;
      }
  }
      }
    return true;
  }

  std::ostream& PhotkilledJet::Description(std::ostream &ostrm) {
    ostrm << "Low pt Photon killed high pt jet.";
    return ostrm;
  }
  //=================================================================

  //=================================================================
  // OddMuon
  //=================================================================
  OddMuon::OddMuon() {}
  OddMuon::~OddMuon() {}

  bool OddMuon::Process(Event::Data & ev) { return !ev.LD_CommonMuons().hasOdd; }

  std::ostream& OddMuon::Description(std::ostream &ostrm) {
    ostrm << "Check if a muon failed loose quality criteria";
    return ostrm;
  }
  //=================================================================




  //=================================================================
  // missed transverse to Leading jet
  //=================================================================
  missedTrCut::missedTrCut(float cutV):
    mcutV(cutV) {}
  missedTrCut::~missedTrCut() {}

  bool missedTrCut::Process(Event::Data & ev){

    ThrustStuff theStuff = ev.CommonThrustStuff();
    if(theStuff.pjetDphi<TMath::Pi()/2.&& ev.SumEt()>mcutV) return true;
    if(sin(fabs(theStuff.pjetDphi-TMath::Pi())) * ev.SumEt()> mcutV) return true;
    return false;
 }

  std::ostream& missedTrCut::Description(std::ostream &ostrm) {
    ostrm << "Thruststuff HT";
    return ostrm;
  }
  //=================================================================






  badMuonInJet::badMuonInJet() {}
  badMuonInJet::~badMuonInJet() {}

  bool badMuonInJet::Process(Event::Data & ev) {
    bool aMuon=true;
    std::vector<Event::Lepton>::const_iterator iph = ev.LD_Muons().begin();
    std::vector<Event::Lepton>::const_iterator jph = ev.LD_Muons().end();
    for ( ; iph != jph; ++iph) {
      if(iph->Pt()<10.) continue;
      std::vector<Event::Jet const *>::const_iterator iJ = ev.JD_CommonJets().accepted.begin();
      std::vector<Event::Jet const *>::const_iterator jJ = ev.JD_CommonJets().accepted.end();
      for ( ; iJ != jJ; ++iJ) {
      if( fabs( ROOT::Math::VectorUtil::DeltaR (**iJ,*iph) ) < 0.5 )
        {
          if(iph->Pt() > 0.5*(*iJ)->Pt() ) { aMuon=false; }
        }
      }
    }
    return aMuon;
  }

  std::ostream& badMuonInJet::Description(std::ostream &ostrm) {
    ostrm << "Bad muon in a Jet";
    return ostrm;
  }



  badEliInJet::badEliInJet() {}
  badEliInJet::~badEliInJet() {}

  bool badEliInJet::Process(Event::Data & ev) {
    bool aEli=true;
    for (std::vector<Event::Lepton>::const_iterator iph = ev.LD_Electrons().begin();
   iph != ev.LD_Electrons().end();
   ++iph)
      {
  if(iph->Pt()<5) continue;
  if( fabs( ROOT::Math::VectorUtil::DeltaPhi ((ev.CommonRecoilMET()),*iph) ) < 0.5 ) return false;
      }
    return aEli;
  }

  std::ostream& badEliInJet::Description(std::ostream &ostrm) {
    ostrm << "Electron pT > 5GeV within Delta phi < 0.5 of Common Recoil MET";
    return ostrm;
  }

//=====================
//HB HE Noise Filter
//=====================

NoiseFilter::NoiseFilter() {}
NoiseFilter::~NoiseFilter() {}

bool NoiseFilter::Process(Event::Data & ev) {
  if(ev.GethbheNoiseFilterResult() == true) {return true;}
  else return false;
}

std::ostream& NoiseFilter::Description(std::ostream &ostrm) {
  ostrm << "Check if an event failed noise filtering criteria";
  return ostrm;
}
//===============================


//=====================
//HB HE Noise Filter
//=====================

//=====================
//Beam halo Filter
//=====================

beamHaloCSCTightHaloId::beamHaloCSCTightHaloId() {}
beamHaloCSCTightHaloId::~beamHaloCSCTightHaloId() {}

bool beamHaloCSCTightHaloId::Process(Event::Data & ev) {
  if(ev.GethbeamHaloCSCTightHaloIdResult() == false) {return true;}
  else return false;
}

std::ostream& beamHaloCSCTightHaloId::Description(std::ostream &ostrm) {
  ostrm << "Check if an event failed CSCTightHaloId filtering criteria";
  return ostrm;
}
//===============================


//=====================
//Beam halo Filter
//=====================

MonsterFilter::MonsterFilter() {}
MonsterFilter::~MonsterFilter() {}

bool MonsterFilter::Process(Event::Data & ev) {
  if(ev.GettracksNEtaLT0p9AllTracks()+ev.GettracksNEta0p9to1p5AllTracks()+ev.GettracksNEtaGT1p5AllTracks() > 10 && ev.GettracksNEtaLT0p9HighPurityTracks()+ev.GettracksNEta0p9to1p5HighPurityTracks()+ev.GettracksNEtaGT1p5HighPurityTracks()  <= 0.25*(ev.GettracksNEtaLT0p9AllTracks()+ev.GettracksNEta0p9to1p5AllTracks()+ev.GettracksNEtaGT1p5AllTracks()) ) {    return false;} // this line removes moster events
  //  if(ev.GettracksNEtaLT0p9AllTracks()+ev.GettracksNEta0p9to1p5AllTracks()+ev.GettracksNEtaGT1p5AllTracks() <= 10) cout <<"few tracks"<<endl;
  return true;

}

std::ostream& MonsterFilter::Description(std::ostream &ostrm) {
  ostrm << "MonsterFilter filter events that appear as monsters from other dimensions using the dimension portal from LHC and trying to conquere the world!";
  return ostrm;
}
//===============================


//=====================
//ECAL Spike Cleaner
//=====================



RA2TrackingFailureFilterCut::RA2TrackingFailureFilterCut() {}
RA2TrackingFailureFilterCut::~RA2TrackingFailureFilterCut() {}

bool RA2TrackingFailureFilterCut::Process(Event::Data & ev) {
  // cout << " nop" <<endl;
  try{
    // cout << " yep" <<endl;
      return ev.GetRA2TrackingFailureFilter();
  }
  catch(std::invalid_argument & e) {return true;}
  
  return true;
}

std::ostream& RA2TrackingFailureFilterCut::Description(std::ostream &ostrm) {
  ostrm << "Check RA2TrackingFailureFilter";
  return ostrm;
}

RA2ecaldeadcellfilterflagCut::RA2ecaldeadcellfilterflagCut() {}
RA2ecaldeadcellfilterflagCut::~RA2ecaldeadcellfilterflagCut() {}

bool RA2ecaldeadcellfilterflagCut::Process(Event::Data & ev) {
  //cout << " nop" <<endl;
  try{
    // cout << " yep" <<endl;
      return ev.GetRA2ecaldeadcellfilterflag();
  }
  catch(std::invalid_argument & e) {return true;}
  
  return true;
}

std::ostream& RA2ecaldeadcellfilterflagCut::Description(std::ostream &ostrm) {
  ostrm << "RA2ecaldeadcellfilterflagCut";
  return ostrm;
}




GoodEventSelection::GoodEventSelection() {}
GoodEventSelection::~GoodEventSelection() {}

bool GoodEventSelection::Process(Event::Data & ev) {

if(!ev.pthat.enabled()){
  if( !ev.GetphysicsDeclared() ){ return false; } // requires physics decalared if running on data!
}

  if(ev.GettracksNEtaLT0p9AllTracks()+ev.GettracksNEta0p9to1p5AllTracks()+ev.GettracksNEtaGT1p5AllTracks() > 10 && ev.GettracksNEtaLT0p9HighPurityTracks()+ev.GettracksNEta0p9to1p5HighPurityTracks()+ev.GettracksNEtaGT1p5HighPurityTracks()  <= 0.25*(ev.GettracksNEtaLT0p9AllTracks()+ev.GettracksNEta0p9to1p5AllTracks()+ev.GettracksNEtaGT1p5AllTracks()) ) {return false;} // this line removes moster events

for( int i = 0; i<ev.GetVertexSize(); i++)
  {
    if(!ev.GetvertexIsFake(i) && fabs(ev.GetvertexPosition(i).Z()) < 24.0 && ev.GetvertexNdof(i)> 4&& ev.GetvertexPosition(i).Rho() < 2.0) return true;
  } // Require at one good vertex passing the above.

 return false;
}

std::ostream& GoodEventSelection::Description(std::ostream &ostrm) {
  ostrm << "Check if an event failed Good event selection";
  return ostrm;
}
//===============================


//=====================
//ECAL Spike Cleaner
//=====================

EcalSpikeCleaner::EcalSpikeCleaner() {}
EcalSpikeCleaner::~EcalSpikeCleaner() {}

bool EcalSpikeCleaner::Process(Event::Data & ev) {

  for (std::vector<Event::Photon const *>::const_iterator pho = ev.PD_CommonPhotons().accepted.begin(); pho != ev.PD_CommonPhotons().accepted.end(); ++pho) {
    if ( ev.photonE2overE9()->at((*pho)->GetIndex()) + ev.photonSeedEnergy()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()) > 0.96 || ev.photonSeedTime()->at((*pho)->GetIndex()) > 5. || ev.photonTime2()->at((*pho)->GetIndex()) > 5. ) return false;
  }
  return true;
  /*
  //std::cout << "Number of dirty Rec Hits = " << ev.rechitCaloP4()->size() << std::endl;
  //if ( ev.rechitCaloP4()->size() > 0)
  // Loop through all dirty rec hits. All have severity 4 = kWeird or 5 = kBad.
  // kWeird: spikes; pt ~ 100GeV; 0 (mostly) or 1 per event.
  // kBad: no rec hit corresponding to det id; time = 0 and pt ~ 0.1 GeV; 0 to 50 per event.
  for (std::vector<PolarLorentzV>::const_iterator  it = ev.rechitCaloP4Eb()->begin(); it != ev.rechitCaloP4Eb()->end(); ++it)
  {
    if (it->Pt() > 10.)
    {
      if ( ev.rechitCaloSeverityLevelEb()->at(it - ev.rechitCaloP4Eb()->begin()) == 3
        || ev.rechitCaloSeverityLevelEb()->at(it - ev.rechitCaloP4Eb()->begin()) == 4 )

      {
        //std::cout << "ECAL SPIKE: Rec Hit pt = " << it->Pt() << std::endl;
        //std::cout << "RecHit pt = " << it->Pt() << std::endl;
        //std::cout << "RecHit eta = " << it->Eta() << std::endl;
        //std::cout << "RecHit phi = " << it->Phi() << std::endl;
        //std::cout << "RecHit time = " << ev.rechitCaloTime()->at(it - ev.rechitCaloP4()->begin()) << std::endl;
        //std::cout << "RecHit severity = " << ev.rechitCaloSeverityLevel()->at(it - ev.rechitCaloP4()->begin()) << std::endl;
        return false;
      }
    }
  }

  for (std::vector<PolarLorentzV>::const_iterator  it = ev.rechitCaloP4Ee()->begin(); it != ev.rechitCaloP4Ee()->end(); ++it)
  {
    if (it->Pt() > 10.)
    {
      if ( ev.rechitCaloSeverityLevelEe()->at(it - ev.rechitCaloP4Ee()->begin()) == 3
        || ev.rechitCaloSeverityLevelEe()->at(it - ev.rechitCaloP4Ee()->begin()) == 4 )

      {
        return false;
      }
    }
  }

  return true;
  */
}

std::ostream& EcalSpikeCleaner::Description(std::ostream &ostrm) {
  ostrm << "Check if an event has a spike";
  return ostrm;
}
//===============================


  //===========
  // Trigger cut
  //===========


TriggerCut::TriggerCut(const std::string & bit):
    mTriggerBit(bit){}


TriggerCut::~TriggerCut() {}

bool TriggerCut::Process(Event::Data & ev) {
  std::map<std::string,bool>::const_iterator it=ev.hlt()->find(mTriggerBit);
   //std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
   //for(std::map<std::string,bool>::const_iterator it2 =ev.hlt()->begin();
   //    it2!=ev.hlt()->end(); ++it2){
   //   std::cout << it2->first << " = " << it2->second << std::endl;
   //  }
   // std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;

    if (it==ev.hlt()->end()){throw std::invalid_argument("Selected trigger bit is not found. Check name/existance of this trigger!");}
    else return it->second;

}

std::ostream& TriggerCut::Description(std::ostream &ostrm) {
  ostrm << "TriggerBit " << mTriggerBit << " passed ";
  return ostrm;
}

 //===========
  // Trigger AND cut
  //===========

  TwoTriggerAndCut::TwoTriggerAndCut(const std::string & bit1, const std::string & bit2):
    mTriggerBit1(bit1),
    mTriggerBit2(bit2){}

TwoTriggerAndCut::~TwoTriggerAndCut() {}

bool TwoTriggerAndCut::Process(Event::Data & ev) {

  std::map<std::string,bool>::const_iterator it1=ev.hlt()->find(mTriggerBit1);
  std::map<std::string,bool>::const_iterator it2=ev.hlt()->find(mTriggerBit2);

  if ( (it1!=ev.hlt()->end()) && (it2!=ev.hlt()->end()) ) {
    return ( (it1->second) && (it2->second) );
  }

  return false;

}

std::ostream& TwoTriggerAndCut::Description(std::ostream &ostrm) {
  ostrm << "TriggerBits " << mTriggerBit1 << " " << mTriggerBit2 << " passed ";
  return ostrm;
}

 //===========
  // 2 Trigger cut
  //===========

  TwoTriggerCut::TwoTriggerCut(const std::string & bit1, const std::string & bit2):
    mTriggerBit1(bit1),
    mTriggerBit2(bit2){}

TwoTriggerCut::~TwoTriggerCut() {}

bool TwoTriggerCut::Process(Event::Data & ev) {

  std::map<std::string,bool>::const_iterator it1=ev.hlt()->find(mTriggerBit1);
  std::map<std::string,bool>::const_iterator it2=ev.hlt()->find(mTriggerBit2);

  if ( (it1!=ev.hlt()->end()) && (it2==ev.hlt()->end()) ) {
    //    cout << "1: " << it1->second << "\n";
    return it1->second;
  }

  if ( (it2!=ev.hlt()->end()) && (it1==ev.hlt()->end()) ) {
    //    cout << "2: " << it2->second << "\n";
    return it2->second;
  }

  if ( (it1!=ev.hlt()->end()) && (it2!=ev.hlt()->end()) ) {
    //    cout << "3: " << it1->second << ", " << it2->second << "\n";
    return ( (it1->second) || (it2->second) );
  }

  if ( (it1==ev.hlt()->end()) && (it2==ev.hlt()->end()) ) {
    return false;
  }
  return false;

}

std::ostream& TwoTriggerCut::Description(std::ostream &ostrm) {
  ostrm << "TriggerBits " << mTriggerBit1 << " " << mTriggerBit2 << " passed ";
  return ostrm;
}

 //===========
  // 3 Trigger cut
  //===========

  ThreeTriggerCut::ThreeTriggerCut(const std::string & bit1, const std::string & bit2, const std::string & bit3):
    mTriggerBit1(bit1),
    mTriggerBit2(bit2),
    mTriggerBit3(bit3){}

ThreeTriggerCut::~ThreeTriggerCut() {}

bool ThreeTriggerCut::Process(Event::Data & ev) {

  std::map<std::string,bool>::const_iterator it1=ev.hlt()->find(mTriggerBit1);
  std::map<std::string,bool>::const_iterator it2=ev.hlt()->find(mTriggerBit2);
  std::map<std::string,bool>::const_iterator it3=ev.hlt()->find(mTriggerBit3);

  // 2^3 = 8 possiblities

  // if only one of the three triggers is present
  if ( (it1!=ev.hlt()->end()) && (it2==ev.hlt()->end()) && (it3==ev.hlt()->end()) ) {
    return it1->second;
  }

  if ( (it2!=ev.hlt()->end()) && (it1==ev.hlt()->end()) && (it3==ev.hlt()->end()) ) {
    return it2->second;
  }

  if ( (it3!=ev.hlt()->end()) && (it1==ev.hlt()->end()) && (it2==ev.hlt()->end()) ) {
    return it3->second;
  }

  // if two of the three triggers are present
  if ( (it1!=ev.hlt()->end()) && (it2!=ev.hlt()->end()) && (it3==ev.hlt()->end()) ) {
    return ( (it1->second) || (it2->second) );
  }

  if ( (it1!=ev.hlt()->end()) && (it3!=ev.hlt()->end()) && (it2==ev.hlt()->end()) ) {
    return ( (it1->second) || (it3->second) );
  }

  if ( (it2!=ev.hlt()->end()) && (it3!=ev.hlt()->end()) && (it1==ev.hlt()->end()) ) {
    return ( (it2->second) || (it3->second) );
  }

  // if all three triggers are present
  if ( (it1!=ev.hlt()->end()) && (it2!=ev.hlt()->end()) && (it3!=ev.hlt()->end()) ) {
    return ( (it1->second) || (it2->second) || (it3->second) );
  }

  // if none of the triggers is present
  if ( (it1==ev.hlt()->end()) && (it2==ev.hlt()->end()) && (it2==ev.hlt()->end()) ) {
    return false;
  }
  return false;

}

std::ostream& ThreeTriggerCut::Description(std::ostream &ostrm) {
  ostrm << "TriggerBits " << mTriggerBit1 << " " << mTriggerBit2 <<  " " << mTriggerBit3 << " passed ";
  return ostrm;
}

TriggersExist::TriggersExist(const Utils::ParameterSet & ps) {
  mTriggers = ps.Get<std::vector<std::string> >("Triggers");
}

TriggersExist::~TriggersExist() {}

bool TriggersExist::Process(Event::Data & ev) {
  for(std::vector<std::string>::const_iterator it = mTriggers.begin();
      it != mTriggers.end();
      ++it){
    std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
    if(trig == ev.hlt()->end()) return false;
  }
  return true;
}

std::ostream& TriggersExist::Description(std::ostream &ostrm) {
  ostrm << "Triggers Exist: ";
  for(std::vector<std::string>::iterator it = mTriggers.begin();
      it != mTriggers.end();
      ++it){
    ostrm << "  " << *it;
  }
  return ostrm;
}

UnPrescaled::UnPrescaled(const std::string & mbit):
    mTrigger(mbit){}

  UnPrescaled::~UnPrescaled() {}

  bool UnPrescaled::Process(Event::Data & ev) {
    //cout << "in the process" << endl;

    std::map<std::string,int>::const_iterator it=ev.hlt_prescaled()->find(mTrigger);
    //  std::cout << ev.hlt_prescaled()->size() <<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    //   for(std::map<string,int>::const_iterator it2 =ev.hlt_prescaled()->begin();
    //       it2!=ev.hlt_prescaled()->end(); ++it2){
    //      std::cout << it2->first << " = " << it2->second << std::endl;
    //     }
    //    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  if(it==ev.hlt_prescaled()->end()) return false;
  else if (it->second == 1) return true;
  else return false;
  }


    std::ostream& UnPrescaled::Description(std::ostream &ostrm) {
  ostrm << "Trigger  " << mTrigger << " is unprescaled ";
  return ostrm;
}


  CutOnUnCorLeadJetPt::CutOnUnCorLeadJetPt(float temp) :
    mTemp(temp) {}

  CutOnUnCorLeadJetPt::~CutOnUnCorLeadJetPt() {}

  bool CutOnUnCorLeadJetPt::Process(Event::Data & ev) {

    int tmpIndex = -999;
    Double_t tmpHighestUnCorJetPt = -999.;

    for (std::vector<Event::Jet>::const_iterator iJ=ev.JD_Jets().begin();
         iJ!=ev.JD_Jets().end();
         ++iJ) {
      Double_t comJet_px = iJ->Px();
      Double_t comJet_py = iJ->Py();
      Double_t comJet_pz = iJ->Pz();
      Double_t comJet_e  = iJ->E();

      Double_t jetCorFac =ev.GetJetCorrFactor(iJ->GetIndex());

      TLorentzVector *unCorJet = new TLorentzVector(comJet_px/jetCorFac,comJet_py/jetCorFac,comJet_pz/jetCorFac,comJet_e/jetCorFac);
      //      cout << unCorJet->Pt() << " " << iJ->Pt() << " " << ev.JD_CommonJets().accepted[iJ->GetIndex()]->Pt()  << "\n";
      if ( (unCorJet->Pt())>tmpHighestUnCorJetPt ) {
        tmpIndex = iJ->GetIndex();
        tmpHighestUnCorJetPt = unCorJet->Pt();
      }

      unCorJet->Delete();
    } // end of loop over the PreJets
    if (tmpHighestUnCorJetPt > mTemp) { return true; }

    return false;
  }

  std::ostream& CutOnUnCorLeadJetPt::Description(std::ostream &ostrm) {
    ostrm << "UnCorLeadJetPt  > " << mTemp << " GeV): ";
    return ostrm;
  }





SkimOp::SkimOp(const Utils::ParameterSet & conf):
    mSkimName(conf.Get<std::string>("SkimName")),
    mBranches(conf.Get<std::vector<std::string> >("Branches")),
    mDropBranches(conf.Get<bool>("DropBranches")),
    mFile(0),
    mCloneTree(0),
    mCount(0),
    mTotal(0)
{}

SkimOp::~SkimOp(){

}

void SkimOp::End(Event::Data & ev){
  std::cout << "[SKIM] " << mSkimName << " Selected " << mCount
            << " events out of  " << mTotal << " => Efficiency = "
            << (double(mCount)/double(mTotal)) << std::endl;
  if(mCloneTree){
    std::cout << "Writing tree" << std::endl;
    mCloneTree->Write();
    mCloneTree->AutoSave();
  }
}


void SkimOp::ParseDropKeep(){
   for(std::vector<std::string>::const_iterator ii= mBranches.begin();
      ii!=mBranches.end();
      ++ii){
    std::string drop_keep="";
    std::string branch_name="";
    std::string::const_iterator ic;
    // Skip leading whitespace
    for(ic=ii->begin();ic!=ii->end();++ic){
      if((*ic)!=' ') break;
    }
    // Get drop/keep string
    for(;ic!=ii->end();++ic){
      if(*ic==' ') break;
      else drop_keep+=*ic;
    }
    // Skip more whitespace
    for(;ic!=ii->end();++ic){
      if(*ic!=' ') break;
    }
    // Get branchname
    for(;ic!=ii->end();++ic){
      if(*ic==' ') break;
      else branch_name+=*ic;
    }
    if(drop_keep=="drop" || drop_keep=="keep"){
      mCmds.push_back(
          std::pair<bool,std::string>((drop_keep=="keep"),branch_name));
    }
    else
      throw std::invalid_argument("Invalid filter statement: '"+ *ii+"'");
  }
}

void SkimOp::SetBranchStatuses(Event::Data & ev){
  for(std::vector< std::pair <bool,std::string> >::iterator ii=mCmds.begin();
      ii!=mCmds.end();++ii){
    std::cout << "FILTER: " << ii->first << " " << ii->second << std::endl;
    ev.GetTree()->SetBranchStatus((ii->second).c_str(),ii->first ? 1 : 0);
    if(ii->first){
      TObjArray* arr= ev.GetTree()->GetBranch(ii->second.c_str())->GetListOfBranches();

      if (arr->GetEntries()!=1) {
  for(int i=0;i<arr->GetEntries();++i){
    TBranch* br=(TBranch*)arr->At(i);
    ev.GetTree()->SetBranchStatus(br->GetName(),1);
    br->GetEntry(0);
  }
      } else {
  // metP4 type branches ...
  TBranch* br=(TBranch*)arr->At(0);
  TObjArray *ar = br->GetListOfBranches();
  for(int i=0;i<ar->GetEntries();++i){
    TBranch* subbr=(TBranch*)ar->At(i);
    //    std::cout << "Br name = " << subbr->GetName() << std::endl;
    ev.GetTree()->SetBranchStatus(subbr->GetName(),1);
    subbr->GetEntry(0);
  }
      }
  /*
  if (br->GetAddress()) {
    filtered_tree->SetBranchAddress(br->GetName(),br->GetAddress());
    }
  */
      ev.GetTree()->GetBranch(ii->second.c_str())->GetEntry(0);
    }
  }
}

void SkimOp::Start(Event::Data &ev){
  if(mDropBranches){
    ParseDropKeep();
    SetBranchStatuses(ev);
  }
  mFile= ev.OutputFile();// new TFile((mSkimName+"_"+ev.DataSet()+".root").c_str(),"recreate");
  mFile->mkdir(NT_DIRNAME);
  TDirectory* dir=(TDirectory*)mFile->Get(NT_DIRNAME);
  dir->cd();
  mCloneTree = (TTree*)ev.GetTree()->CloneTree(0);
  mCloneTree->SetDirectory(dir);
  ev.GetTree()->CopyAddresses(mCloneTree);
  mCount =0;
  mTotal = ev.GetLastEntry() - ev.GetFirstEntry() + 1;
}

bool SkimOp::Process(Event::Data & ev){
  /* ROOT WTF?!
   *
   * Essentially calling TBranch::GetEntry twice for the same branch in the same
   * event leads to uncontrollable segfaulting (at least in ROOT 5.27). Here we
   * try to work around this by looping through all branches and checking if
   * they have previously been read by the rest of the analysis code
   * (GetReadEntry() == ev.GetCurrentEntry()). If they have, then fantastic
   * they'll end up in the output skim. If not then we call GetEntry to fetch
   * them. If the analysis code attempts to read a branch (which wasn't already
   * cached) after the skimmer has had its way then it will probably
   * segfault. Hence this is safest if the skimmer is last in the chain but may
   * work in other circumstances possibly.  If ROOT was even slightly competent,
   * we could just do: ev.GetTree()->GetEntry(ev.GetCurrentEntry(), 1); but
   * instead we'll go for this:
   */
  TObjArray* branches = ev.GetTree()->GetListOfBranches();
  for(int i =0; i < branches->GetSize(); ++i){
    TBranch* b = (TBranch*)branches->At(i);
    if(b->GetReadEntry() != ev.GetCurrentEntry()) b->GetEntry(ev.GetCurrentEntry(), 1);
     TBranch* bskim = (TBranch*)(mCloneTree->GetListOfBranches()->At(i));  //<- get a pointerto the skim tree branch
     bskim->SetAddress(b->GetAddress()); //<set the address of theskim branch to the ntuple tree branch
   }
  mCloneTree->Fill();
  mCount++;
  return true;
}

std::ostream & SkimOp::Description(std::ostream & ostrm){
    ostrm << "SkimOp: " << mSkimName;
    return ostrm;
}

MultiTrigger::MultiTrigger(const Utils::ParameterSet & ps){
  mTriggers = ps.Get<std::vector<std::string> >("Triggers");
  verb = ps.Get<bool>("Verbose");
  usePrescale = ps.Get<bool>("UsePreScaledTriggers");
}

MultiTrigger::~MultiTrigger(){}

bool MultiTrigger::Process(Event::Data & ev){
  for(std::vector<std::string>::const_iterator it = mTriggers.begin();
  it != mTriggers.end();
  ++it){
    if( it->at(it->size()-1) != '*'){
      std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
      std::map<std::string, int>::const_iterator pre = ev.hlt_prescaled()->find(*it);
      if(usePrescale){
        if(trig != ev.hlt()->end() && trig->second) return true;
      }
      if(!usePrescale){
        if(trig != ev.hlt()->end() && trig->second && pre->second == 1 ) return true;
      }
    }
    else{
      size_t found;
    // now loop though the map and test the string part -- slow!
      std::map<std::string, bool>::const_iterator itrig = ev.hlt()->begin();
      std::map<std::string, bool>::const_iterator jtrig = ev.hlt()->end();
      std::map<std::string,int>::const_iterator prescale = ev.hlt_prescaled()->begin();
      for( ; itrig != jtrig; ++itrig, ++prescale ){
        if(itrig->second){
          std::string str = *it;
          str = str.substr(0, str.size() - 1 );
          if(verb) cout <<*it<< " compare with " << itrig->first << endl;
          found = itrig->first.find(str);
          if(found != string::npos ){
            if(usePrescale) return true;
            else{
              if(prescale->second == 1) return true;
            }
          }
        }
      }
    }
  }
  return false;
}

std::ostream & MultiTrigger::Description(std::ostream & ostrm){
  ostrm << "MultiTrigger: ";
  for(std::vector<std::string>::iterator it = mTriggers.begin();
  it != mTriggers.end();
  ++it){
    ostrm << "  " << *it;
  }
  return ostrm;
}





  // --------------
  // Mix 2 triggers

  Mix2Triggers::Mix2Triggers(int runNumber, const std::string & bit1, const std::string & bit2):
    mRunNumber(runNumber),
    mTriggerBit1(bit1),
    mTriggerBit2(bit2){}

  Mix2Triggers::~Mix2Triggers() {}

  bool Mix2Triggers::Process(Event::Data & ev) {

    if (ev.RunNumber() < mRunNumber) {

      std::map<std::string,bool>::const_iterator it = ev.hlt()->find(mTriggerBit1);
      if (it==ev.hlt()->end()){throw std::invalid_argument("Selected trigger bit is not found. Check name/existance of this trigger!");}
      else return it->second;
    }
    else {

      std::map<std::string,bool>::const_iterator it = ev.hlt()->find(mTriggerBit2);
      if (it==ev.hlt()->end()){throw std::invalid_argument("Selected trigger bit is not found. Check name/existance of this trigger!");}
      else return it->second;
    }

    return false;
  } // ~end of bool function

  std::ostream& Mix2Triggers::Description(std::ostream &ostrm) {
    ostrm << "For RunNumbers < "  << mRunNumber << ", TriggerBit " << mTriggerBit1 << " && ";
    ostrm << "For RunNumbers >= " << mRunNumber << ", TriggerBit " << mTriggerBit2 << " passed ";
    return ostrm;
  }



  // --------------
  // Mix 3 triggers

  Mix3Triggers::Mix3Triggers(int runNumber1, int runNumber2, const std::string & bit1, const std::string & bit2, const std::string & bit3):
    mRunNumber1(runNumber1),
    mRunNumber2(runNumber2),
    mTriggerBit1(bit1),
    mTriggerBit2(bit2),
    mTriggerBit3(bit3){}

  Mix3Triggers::~Mix3Triggers() {}

  bool Mix3Triggers::Process(Event::Data & ev) {

    if (ev.RunNumber() < mRunNumber1) {

      std::map<std::string,bool>::const_iterator it = ev.hlt()->find(mTriggerBit1);
      if (it==ev.hlt()->end()){throw std::invalid_argument("Selected trigger bit is not found. Check name/existance of this trigger!");}
      else return it->second;
    }

    else if (ev.RunNumber() < mRunNumber2) {
      std::map<std::string,bool>::const_iterator it = ev.hlt()->find(mTriggerBit2);
      if (it==ev.hlt()->end()){throw std::invalid_argument("Selected trigger bit is not found. Check name/existance of this trigger!");}
      else return it->second;
    }

    else {
      std::map<std::string,bool>::const_iterator it = ev.hlt()->find(mTriggerBit3);
      if (it==ev.hlt()->end()){throw std::invalid_argument("Selected trigger bit is not found. Check name/existance of this trigger!");}
      else return it->second;
    }

    return false;
  } // ~end of bool function

  std::ostream& Mix3Triggers::Description(std::ostream &ostrm) {
    ostrm << "For RunNumbers < "  << mRunNumber1 << ", TriggerBit " << mTriggerBit1 << " passed \n";
    ostrm << "For RunNumbers >= " << mRunNumber1 << " && RunNumbers < " << mRunNumber2  << ", TriggerBit " << mTriggerBit2 << " passed \n";
    ostrm << "For RunNumbers >= " << mRunNumber2 << ", TriggerBit " << mTriggerBit3 << " passed ";
    return ostrm;
  }


JSONFilter::JSONFilter(const std::string name, const Utils::ParameterSet & ps){
  const std::vector<std::string> & runs = ps.Get<std::vector<std::string> >("runs");
  for(std::vector<std::string>::const_iterator run = runs.begin();
      run != runs.end();
      ++run){
    std::stringstream run_ss(*run);
    int run_i = 0;
    run_ss >> run_i;
    const std::vector<int> & lumis(ps.Get<std::vector<int> >(*run));
    for(std::vector<int>::const_iterator lumi = lumis.begin();
        lumi!= lumis.end();
        ++lumi){
      _lumis.insert(std::pair<unsigned int, unsigned int>(run_i, *lumi));
    }
  }
}

JSONFilter::~JSONFilter(){}

bool JSONFilter::Process(Event::Data & ev){
  if(ev.RunNumber() == _cache_run &&
     ev.LumiSection() == _cache_lumi){
    //    std::cout << "(" << ev.RunNumber() << " , " << ev.LumiSection() << ") : " << _cache_result << std::endl;

    return _cache_result;
  }
  else{
    _cache_run = ev.RunNumber();
    _cache_lumi = ev.LumiSection();
    std::pair<unsigned int, unsigned int> runlumi = std::pair<unsigned int, unsigned int>(_cache_run, _cache_lumi);
    _cache_result = (_lumis.find(runlumi) != _lumis.end());
    //    std::cout << "(" << ev.RunNumber() << " , " << ev.LumiSection() << ") : " << _cache_result << std::endl;

  }
  return _cache_result;
}

std::ostream & JSONFilter::Description(std::ostream & ostrm){
  ostrm << "JSON Filter: " << _json_name;
  return ostrm;
}

JSONOutput::JSONOutput(const std::string & name) : _json_name(name) {}

JSONOutput::~JSONOutput(){}

void JSONOutput::Start(Event::Data & ev){
  _lumis.Reset();
}

bool JSONOutput::Process(Event::Data & ev){
  _lumis.Add(ev.RunNumber(), ev.LumiSection());
  return true;
}

void JSONOutput::End(Event::Data & ev){
  _lumis.Sort();
  std::string name = static_cast<std::string> ( ev.OutputFile()->GetName() ); // need to convert TString to string
  name.erase(name.size()-5, 5);
  name.append(_json_name);
  name.append(".json");
  ofstream file;
  file.open(name.c_str(), ios::out);
  file << _lumis.Print();
  file.close();
}

std::ostream & JSONOutput::Description(std::ostream & ostrm){
  ostrm << "JSON Output: ";
  return ostrm;
}

EventSelector::EventSelector(const Utils::ParameterSet & ps):
    accept_(ps.Get<bool>("Accept"))
{
  const std::vector<unsigned int> & runs = ps.Get<std::vector<unsigned int> >("Runs");
  const std::vector<unsigned int> & lumis = ps.Get<std::vector<unsigned int> >("Lumisections");
  const std::vector<unsigned int> & events = ps.Get<std::vector<unsigned int> >("Events");
  // Ensure vectors are equal in size
  if(runs.size() != lumis.size() || lumis.size() != events.size())
    throw std::invalid_argument("EventSelector: ERROR -> Runs, Lumis and Events must be of same size");
  // Store boost::tuple's in set for easy testing
  for(std::vector<unsigned int>::const_iterator run_it = runs.begin();
      run_it != runs.end(); ++ run_it){
    int idx = run_it - runs.begin();
    select_.insert(boost::make_tuple(*run_it, lumis[idx], events[idx]));
    cout << *run_it<<" "<< lumis[idx]<< "  "<< events[idx] << endl;

  }
}

EventSelector::~EventSelector(){}

bool EventSelector::Process(Event::Data & ev){
  boost::tuple<unsigned int, unsigned int, unsigned int> rle = boost::make_tuple(ev.RunNumber(), ev.LumiSection(),
                                                                                 ev.EventNumber());
  bool accept = (select_.find(rle) != select_.end());
  if(!accept_) accept = !accept;
  return accept;
}

std::ostream & EventSelector::Description(std::ostream & ostrm){
  ostrm << "EventSelector (accept = " << accept_ << ")";
  return ostrm;
}

} //~namespace Operation
