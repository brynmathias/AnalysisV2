/*! \file MCOps.cc
 * \brief Source code for Monte Carlo (truth) information-based operations.
 */
#include <stdexcept>

#include "MCOps.hh"
#include "GenMatrixBin.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "TH1F.h"

namespace Operation {

  PrintGenParticleInfo::PrintGenParticleInfo(const char * option) {
    mType = option;
  }

  PrintGenParticleInfo::~PrintGenParticleInfo() {}

  bool PrintGenParticleInfo::Process(Event::Data & ev) {
    // Determine printing mode (if any)
    if (strcmp(mType, "CHAIN")==0) Compute::MC::PrintChain(ev);
    else if (strcmp(mType, "ENDCHAIN")==0) Compute::MC::PrintEndChain(ev);
    else if (strcmp(mType, "FULL")==0) Compute::MC::PrintGen(ev);
    else if (strcmp(mType, "LEPTONS")==0) Compute::MC::PrintGenLeptons(ev);
    else if (strcmp(mType, "EVENTWEIGHT")==0) std::cout << ev.GetEventWeight() << std::endl;
    return true; // Check for fails above, return false to fail operation.
  }

  std::ostream& PrintGenParticleInfo::Description(std::ostream &ostrm) {
    ostrm << "PrintGenParticleInfo Operation performed...";
    return ostrm;
  }

// WARNING: These have been excluded temporarily!!!!
#if 0
  //
  // GenPartContentCut implementation code
  GenPartContentCut::GenPartContentCut(Int_t pdgid,
				       const std::string & comparison,
				       UInt_t number,
				       Bool_t anti,
				       Int_t mother,
				       Bool_t mother_anti) :
    pdgId_(pdgid), number_(number),
    anti_(anti), mother_(mother), mother_anti_(mother_anti) {
    if (anti_) pdgId_ = abs(pdgId_); // Safety ;-)
    if (mother_anti_) mother_ = abs(mother_);
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

  GenPartContentCut::~GenPartContentCut() { delete mComparison; }

  bool GenPartContentCut::Process(Event::Data & ev) {
    // Count the gen particles with the specified PDG ID
    UInt_t count = 0;
    for (std::vector<Event::GenObject>::const_iterator i = ev.GenParticles().begin();
	 i!=ev.GenParticles().end();
	 ++i) {
      Int_t myid = i->GetID();
      if (anti_) myid = abs(myid);
      if (myid == pdgId_) {
	if (mother_==0) { count++; } // no mother check required.
	else {
	  Int_t mymotherindex = i->GetMother();
	  Int_t mymotherid = ev.GenParticles()[mymotherindex].GetID();
	  if (mother_anti_) mymotherid = abs(mymotherid);
	  if (mymotherid == mother_) count++;
	}
      } // end of PDG ID check
    } // end of loop over GenObjects
    // Return the result of the comparison
    return (*mComparison)(count,
			  number_);
  }

  std::ostream& GenPartContentCut::Description(std::ostream &ostrm) {
    ostrm << "GenPartContentCut Operation (Number of PDG ID " << pdgId_;
    ostrm << " " << mComparison->type() << " " << number_;
    ostrm << ", mother ID = " << mother_;
    ostrm << ", anti, antimother " << anti_ << ", " << mother_anti_ << ")";
    return ostrm;
  }

  //==============================================
  // Number of all MC leptons cut
  //===============================================

  NumMCAllLeptons::NumMCAllLeptons(const std::string & comparison,
				   UInt_t number,
				   UInt_t type) :
    mNumber(number),  mType(type) {
    // Type = 1 for electrons ; 2 for muons ; 3 for taus
    if ( type < 0 || type > 2 ) {
      throw std::invalid_argument(std::string("Type out of range 0, 1, 2"));
    }
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

  NumMCAllLeptons::~NumMCAllLeptons() { delete mComparison; }

  bool NumMCAllLeptons::Process(Event::Data & ev) {
    int uMCe, uMCmu, uMCtau;
    uMCe=uMCmu=uMCtau=0;

    for (UInt_t i=0; i<ev.MC_AllLeptons().size(); i++) {
      int pID = abs( ev.MC_AllLeptons()[i]->GetID() );
      if ( pID == 11 ) { uMCe += 1; }
      if ( pID == 13 ) { uMCmu += 1; }
      if ( pID == 15 ) { uMCtau += 1; }
    }

    if (static_cast<int>(mType)==1) {
      return (*mComparison)(UInt_t(uMCe),
			    mNumber);
    }
    if (static_cast<int>(mType)==2) {
      return (*mComparison)(UInt_t(uMCmu),
			    mNumber);
    }
    if (static_cast<int>(mType)==3) {
      return (*mComparison)(UInt_t(uMCe+uMCmu),
			    mNumber);
    }

    throw std::runtime_error("Shouldn't reach here");
    return false;
  }

  std::ostream& NumMCAllLeptons::Description(std::ostream &ostrm) {
    ostrm << "NumMCAllLeptons Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }


  //===============================================
  // "Number of MC leptons" cut
  //===============================================

  NumMCLeptons::NumMCLeptons(const std::string & comparison,
			     UInt_t number,
			     UInt_t type) :
    mNumber(number),  mType(type) {
    if ( type < 0 || type > 2 ) {
      throw std::invalid_argument(std::string("Type out of range 0, 1, 2"));
    }
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

  NumMCLeptons::~NumMCLeptons() { delete mComparison; }

  bool NumMCLeptons::Process(Event::Data & ev) {

    int uMCe, uMCmu, uMCtau;
    uMCe=uMCmu=uMCtau=0;

    for (UInt_t i=0; i<ev.MC_TheLeptons().size(); i++) {
      int pID = abs( ev.MC_TheLeptons()[i]->GetID() );
      if ( pID == 11 ) { uMCe += 1; }
      if ( pID == 13 ) { uMCmu += 1; }
      if ( pID == 15 ) { uMCtau += 1; }
    }

    if (static_cast<int>(mType)==1) {
      return (*mComparison)(UInt_t(uMCe), mNumber);
    }
    if (static_cast<int>(mType)==2) {
      return (*mComparison)(UInt_t(uMCmu), mNumber);
    }
    if (static_cast<int>(mType)==3) {
      return (*mComparison)(UInt_t(uMCe+uMCmu), mNumber);
    }

    return false;
  }

  std::ostream& NumMCLeptons::Description(std::ostream &ostrm) {
    ostrm << "NumMCLeptons Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }

 //==============================================
  // Number of all MC partons cut
  //===============================================

  NumMCAllPartons::NumMCAllPartons(const std::string & comparison,
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

  NumMCAllPartons::~NumMCAllPartons() { delete mComparison; }

  bool NumMCAllPartons::Process(Event::Data & ev) {
    return (*mComparison)(UInt_t(ev.MC_AllPartons().size()),
			  UInt_t(ev.MC_ThePartons().size()));
  }

  std::ostream& NumMCAllPartons::Description(std::ostream &ostrm) {
    ostrm << "NumMCAllPartons Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }


  //===============================================
  // "Number of MC partons" cut
  //===============================================

  NumMCPartons::NumMCPartons(const std::string & comparison,
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
  NumMCPartons::~NumMCPartons() { delete mComparison; }

  bool NumMCPartons::Process(Event::Data & ev) {
    return (*mComparison)(UInt_t(ev.MC_ThePartons().size()),
			  mNumber);
  }

  std::ostream& NumMCPartons::Description(std::ostream &ostrm) {
    ostrm << "NumMCPartons Operation (num " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }

  //================================================
  // Tau filter
  //================================================
  LeptonFilter::LeptonFilter(UInt_t type) :
    mType(type) {}
  LeptonFilter::~LeptonFilter() {}

  bool LeptonFilter::Process(Event::Data &ev) {

    // ev.PrintGen();
    // Lepton's (e/mu) mother
    int iMot = ev.MC_TheLeptons()[0]->GetMother(); // mother's index
    if ( abs(ev.GenParticles()[iMot].GetID())==static_cast<int>(mType) ) { return false; }

    return true;

  }

  std::ostream& LeptonFilter::Description(std::ostream &ostrm) {
    ostrm << "LeptonFilter Operation ";
    return ostrm;
  }


  //================
  // MC MET Cut
  //================
  MCMETCut::MCMETCut(float metVal) :
  mMETvalue(metVal) {}

  MCMETCut::~MCMETCut() {}

  bool MCMETCut::Process(Event::Data & ev) {
    if (ev.MC_SingleLepMET().Pt() > mMETvalue) return true;
    return false;
  }

  std::ostream& MCMETCut::Description(std::ostream &ostrm) {
    ostrm << "MCMETCut (MC-MET > " << mMETvalue << " GeV): ";
    return ostrm;
  }

  //================
  // MC MHT Cut
  //================

  MCMHTCut::MCMHTCut(float mhtVal) :
  mMHTvalue(mhtVal) {}

  MCMHTCut::~MCMHTCut() {}

  bool MCMHTCut::Process(Event::Data & ev) {
    if (ev.MC_SingleLepMHT().Pt() > mMHTvalue) return true;
    return false;
  }

  std::ostream& MCMHTCut::Description(std::ostream &ostrm) {
    ostrm << "MCMHTCut (MC-MHT > " << mMHTvalue << " GeV): ";
    return ostrm;
  }


 //================
  // MC HT Cut
  //================

  MCHTCut::MCHTCut(float htVal) :
  mHTvalue(htVal) {}

  MCHTCut::~MCHTCut() {}

  bool MCHTCut::Process(Event::Data & ev) {
    if (ev.MC_SingleLepHT() > mHTvalue) return true;
    return false;
  }

  std::ostream& MCHTCut::Description(std::ostream &ostrm) {
    ostrm << "MCHTCut (MC-HT > " << mHTvalue << " GeV): ";
    return ostrm;
  }

  //================
  // MC W decay to Mu Cut
  //================

  MCWtoMuCut::MCWtoMuCut() {}

  MCWtoMuCut::~MCWtoMuCut() {}

  bool MCWtoMuCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (myGenMatrixBin.the_GenMuon.size()==1&&myGenMatrixBin.the_GenMuonNu.size()==1&&myGenMatrixBin.the_GenW.size()>0) return true;
    return false;
  }

  std::ostream& MCWtoMuCut::Description(std::ostream &ostrm) {
    ostrm << "MCWtoMuCut (i.e. W decays to Muon) " ;
    return ostrm;
  }

#endif

} //~namespace Operation
