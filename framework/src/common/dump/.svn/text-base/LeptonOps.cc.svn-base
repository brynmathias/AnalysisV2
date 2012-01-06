/*! \file LeptonicOps.cc
 * \brief Source code for leptonic analysis-based operations. */
#include "LeptonOps.hh"

#include "Lepton.hh"
#include <string>
#include <iostream>
#include <stdexcept>

namespace Operation {

  //==============================
  // "Number of good leptons" Cut
  //==============================

  NumGdLepCut::NumGdLepCut(Int_t type,
			   const std::string & comparison,
			   UInt_t number) :
    mType(type),
    mComparison(0),
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
    if ( mType < 0 || mType > 2 ) {
      throw std::invalid_argument(std::string("Type is not allowed"));
    }
  }

  NumGdLepCut::NumGdLepCut() :
    mType(0),
    mComparison(reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>)),
    mNumber(0) {}

  NumGdLepCut::~NumGdLepCut() {
    if ( mComparison != 0 ) {
      delete mComparison;
      mComparison = 0;
    }
  }

  void NumGdLepCut::SetType(Int_t type) {
    if ( type < 0 || type > 2 ) {
      throw std::invalid_argument(std::string("Type is not allowed"));
    }
    mType = type;
  }
  Int_t NumGdLepCut::GetType() const {
    return mType;
  }

  void NumGdLepCut::SetComparison(const std::string & comparison) {
    if ( mComparison != 0 ) { delete mComparison; mComparison = 0; }
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
      throw std::invalid_argument(std::string("Invalid comparison argument"));
    }    
  }
  std::string NumGdLepCut::GetComparison() const {
    if ( mComparison == 0 ) throw std::runtime_error("Comparison not defined");
    return mComparison->type();
  }

  void NumGdLepCut::SetNumber(UInt_t number) {
    mNumber = number;
  }
  UInt_t NumGdLepCut::GetNumber() const {
    return mNumber;
  }

  // TODO: put in an error check?
  bool NumGdLepCut::Process(Event::Data & ev) {
    if ( mComparison == 0 ) throw std::runtime_error("Comparison not defined");
    // The Compare method is part of the Operation namespace - see BaseOps.hh/cc for code.
    // It's my first template!
    switch ( mType ) {
    case 0:
      return (*mComparison)(UInt_t(ev.LD_GoodElectrons().size()) +
			    UInt_t(ev.LD_GoodMuons().size()),
			    mNumber);
    case 1:
      return (*mComparison)(UInt_t(ev.LD_GoodElectrons().size()),
			    mNumber);
    case 2:
      return (*mComparison)(UInt_t(ev.LD_GoodMuons().size()),
			    mNumber);
    }
    throw std::runtime_error(std::string("Code execution shouldn't reach this point"));
    return false; // This is simply here for closure, it should never happen
  }

  std::ostream& NumGdLepCut::Description(std::ostream &ostrm) {
    ostrm << "NumGdLepCut Operation (";
    ostrm << "type = " << mType;
    ostrm << ", num " << mComparison->type() << " " << mNumber;
    ostrm << ")";
    return ostrm;
  }

  //================
  // MT Cut
  //================
  MTCut::MTCut(float mhtVal) :
    mHTvalue(mhtVal) {}

  MTCut::~MTCut() {}

  bool MTCut::Process(Event::Data & ev) {
    
    // JJ - don't we want to take the biggest of these two for the cut?
    double mGdLepMT=-999;

    if (ev.LD_GoodElectrons().size()>0) {
      mGdLepMT = ev.MT(ev.LD_GoodElectrons()[0], &(ev.CommonRecoilMET()));
    } // end of loop over good electrons.

    if (ev.LD_GoodMuons().size()>0) {
      mGdLepMT = ev.MT(ev.LD_GoodMuons()[0], &(ev.CommonRecoilMET()));
    } // end of loop over good muons.

    if (mGdLepMT > mHTvalue) {return true;}
    
    return false;
  }

  std::ostream& MTCut::Description(std::ostream &ostrm) {
    ostrm << "MTCut (MT > " << mHTvalue << " GeV): ";
    return ostrm;
  }


} //~namespace Operation

