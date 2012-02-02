/*! \file PhotonicOps.cc
 * \brief Source code for photonic analysis-based operations.
 */
#include "PhotonOps.hh"

#include <string>
#include <iostream>
#include <stdexcept>

namespace Operation {

  //====================================
  // General PhotonicData cut
  //====================================
  PhotDatCut::PhotDatCut(const char * option) {
    std::stringstream mystream; mystream << option; option_ = mystream.str();  
  }
  
  PhotDatCut::~PhotDatCut() {}
  
  bool PhotDatCut::Process(Event::Data & ev) {
    // Do whatever you gotta do...
    
    // Cut on number of matched photons to signal
    if (option_ == "allsignalmatchedtopreconf") {
      if ( ev.PD_MatchedSignalPreconfPhotons().size() == 2 ) return true;
      else return false;
    }
    std::cout << "Invalid option passed to operation PhotDatCut!!!" << std::endl;
    return false; //
  }
  
  std::ostream& PhotDatCut::Description(std::ostream &ostrm) {
    ostrm << "PhotDatCut Operation (option = " << option_ << ")";
    return ostrm;
  }
  
  
  //==============================
  // "Number of good photons" Cut
  //==============================
  NumGdPhoCut::NumGdPhoCut(const std::string & comparison,
			   UInt_t number) : number_(number) {
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

  NumGdPhoCut::~NumGdPhoCut() { delete mComparison; }
  
  bool NumGdPhoCut::Process(Event::Data & ev) {
    return (*mComparison)(UInt_t(ev.PD_GoodPhotons().size()),
			  number_);
  }
  
  std::ostream& NumGdPhoCut::Description(std::ostream &ostrm) {
    ostrm << "NumGdPhoCut Operation (num " << mComparison->type()
	  << " " << number_
	  << ")";
    return ostrm;
  }

  //=================================
  // "Number of good jets (pho)" Cut
    //=================================
  NumGdPhoJetCut::NumGdPhoJetCut(const std::string & comparison,
				 UInt_t number) : number_(number) {
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

  NumGdPhoJetCut::~NumGdPhoJetCut() { delete mComparison; }
  
  bool NumGdPhoJetCut::Process(Event::Data & ev) {
    return (*mComparison)(UInt_t(ev.PD_GoodJets().size()),
			  number_);
  }
  
  std::ostream& NumGdPhoJetCut::Description(std::ostream &ostrm) {
    ostrm << "NumGdPhoJetCut Operation (num " << mComparison->type() << " " << number_
	  << ")";
    return ostrm;
  }
  
  //=================================
  // "Good photon+jet HT" Cut
  //=================================
  GoodPhoHTCut::GoodPhoHTCut(const std::string & comparison,
			     Double_t cut) : cut_(cut) {
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
  GoodPhoHTCut::~GoodPhoHTCut() { delete mComparison; }
  
  bool GoodPhoHTCut::Process(Event::Data & ev) {
    return (*mComparison)(ev.PD_GoodPhotonsHT(),
			  cut_);
  }
  
  std::ostream& GoodPhoHTCut::Description(std::ostream &ostrm) {
    ostrm << "GoodPhoHTCut Operation (GdPho+Jet HT " << mComparison->type()
	  << " " << cut_
	  << ")";
    return ostrm;
  }
  
  //=================================
  // "Good photon+jet Alpha T" Cut
  //=================================
  GoodPhoAlphaTCut::GoodPhoAlphaTCut(const std::string & comparison,
				     Double_t cut) : cut_(cut) {
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

  GoodPhoAlphaTCut::~GoodPhoAlphaTCut() { delete mComparison; }
  
  bool GoodPhoAlphaTCut::Process(Event::Data & ev) {
    return (*mComparison)(ev.PD_GoodAlphaT(),
			  cut_);
  }
  
  std::ostream& GoodPhoAlphaTCut::Description(std::ostream &ostrm) {
    ostrm << "GoodPhoAlphaTCut Operation (GdPho+Jet Alpha_T " << mComparison->type() << " " << cut_
	  << ")";
        return ostrm;
  }

} //~namespace Operation
