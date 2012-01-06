/*! \file JadOps.cc 
 * \brief Source code for Monte Carlo (truth) information-based operations.
 */
#include <stdexcept>

#include "JadOps.hh"
#include "GenMatrixBin.hh"
#include "EventData.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
//#include "GenObject.hh"
//#include "TH1F.h"

namespace Operation {

  //================
  // MC Check Existence of W boson
  //================

  MCWExists::MCWExists() {}

  MCWExists::~MCWExists() {}

  bool MCWExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (myGenMatrixBin.the_GenW.size()>0) return true; //a Generator W exists in the event
    return false;
  }

  std::ostream& MCWExists::Description(std::ostream &ostrm) {
    ostrm << "MCWExists (i.e. at least 1 genW exists in the event) " ;
    return ostrm;
  }

  //================
  // MC Check Existence of W decaying to muon + neutrino
  //================

  MCWMuonExists::MCWMuonExists() {}

  MCWMuonExists::~MCWMuonExists() {}

  bool MCWMuonExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (myGenMatrixBin.the_GenMuon.size()>0 && myGenMatrixBin.the_GenMuonNu.size()>0) {
      //if there is a muon + neutrino, and if both their mothers = the index of the W in the genmatrix bin
      //then they are related - this is to be used in the W+Jets sample where there is nominally 1 W boson...
      if(myGenMatrixBin.the_GenMuon.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex() &&
	 myGenMatrixBin.the_GenMuonNu.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex()) return true;
    }
    return false;
  }

  std::ostream& MCWMuonExists::Description(std::ostream &ostrm) {
    ostrm << "MCWMuonExists (i.e. at least 1 genW decays to a muon in the event) " ;
    return ostrm;
  }

  //================
  // MC Muon comes from W decay (for MuonExtra i.e. status 1 and 3)
  //================

  MCMuonExtraFromW::MCMuonExtraFromW() {}

  MCMuonExtraFromW::~MCMuonExtraFromW() {}

  bool MCMuonExtraFromW::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    //use this cut after explicitly asking for 1 MC MuonExtra with the acceptance cuts
      
    if(myGenMatrixBin.the_GenMuonExtra.at(0)->GetStatus() == 3) {
      //this means that the particle in the GenMatrixBin came from the hard scatter process
      //these particles are stored in the GenParticles collection
      for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin(); j != ev.GenParticles().end(); ++j) {
	if(j->GetIndex() == myGenMatrixBin.the_GenMuonExtra.at(0)->GetMother() && fabs(j->GetID()) == 24) return true;
      }
    }
    
    if(myGenMatrixBin.the_GenMuonExtra.at(0)->GetStatus() == 1) {
      //this means that the particle in the GenMatrixBin came from decays subsequent to initial production
      //these particles are stored in the GenLeptons collection - we need to do a few more checks here
      //first check that the status1 muon comes from a tau...
      if(fabs(myGenMatrixBin.the_GenMuonExtra.at(0)->GetMother()) == 15) {
	//...now we check that a W in the GenParticles decays to a tau - this is enough to allow this event to pass (we don't have the information linking
	//GenParticles to GenLeptons) 
	for(unsigned int k =0 ; k<myGenMatrixBin.the_GenTau.size() ; k++) {
	  for(std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin(); j != ev.GenParticles().end(); ++j) {
	  
	    if(myGenMatrixBin.the_GenTau.at(k)->GetMother() == j->GetIndex() && fabs(j->GetID()) == 24) return true;
	  }
	}
      }
    }

    return false;
  }

  std::ostream& MCMuonExtraFromW::Description(std::ostream &ostrm) {
    ostrm << "MCMuonExtraFromW (i.e. either a status 1 or 3 muon comes from a W) ";
    return ostrm;
  }

  //================
  // MC Cut on W boson Pt
  //================

  MCWPTCut::MCWPTCut(float PtCut) :
  mPtCut(PtCut) {}

  MCWPTCut::~MCWPTCut() {}

  bool MCWPTCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (myGenMatrixBin.the_GenW.at(0)->Pt() > mPtCut) return true;
    return false;
  }

  std::ostream& MCWPTCut::Description(std::ostream &ostrm) {
    ostrm << "MCPTCut (make a cut on the genW Pt) " ;
    return ostrm;
  }

  //================
  // MC Cut on GenJet VHT (VHT = vector sum of jets)
  //================

  MCVHTCut::MCVHTCut(float VHTCut) :
  mVHTCut(VHTCut) {}

  MCVHTCut::~MCVHTCut() {}

  bool MCVHTCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    TLorentzVector jVHT;
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      jVHT += (*(myGenMatrixBin.the_GenJets.at(i)));
    }

    if (jVHT.Pt() > mVHTCut) return true;
    else return false;
  }

  std::ostream& MCVHTCut::Description(std::ostream &ostrm) {
    ostrm << "MCVHTCut (make a cut on the Pt of vector sum of GenJets) " ;
    return ostrm;
  }

  //================
  // MC Cut on GenJet HT (HT = scalar sum of jet Pt)
  //================

  MCJetHTCut::MCJetHTCut(float HTCut) :
  mHTCut(HTCut) {}

  MCJetHTCut::~MCJetHTCut() {}

  bool MCJetHTCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    float jHT=0.0;
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      jHT += (myGenMatrixBin.the_GenJets.at(i)->Pt());
    }

    if (jHT > mHTCut) return true;
    else return false;
  }

  std::ostream& MCJetHTCut::Description(std::ostream &ostrm) {
    ostrm << "MCJetHTCut (make a cut on the HT of GenJets) " ;
    return ostrm;
  }

  //================
  // MC Muon exists
  //================

  MCMuonExists::MCMuonExists(unsigned int numMuons) :
  mNumMuons(numMuons) {}

  MCMuonExists::~MCMuonExists() {}

  bool MCMuonExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenMuon.size()== mNumMuons) return true;
    else return false;
  }

  std::ostream& MCMuonExists::Description(std::ostream &ostrm) {
    ostrm << "MCMuonExists (make a cut on the existence of genMuons) " ;
    return ostrm;
  }

  //================
  // MC MuonExtra exists
  //================

  MCMuonExtraExists::MCMuonExtraExists(unsigned int numMuons) :
  mNumMuons(numMuons) {}

  MCMuonExtraExists::~MCMuonExtraExists() {}

  bool MCMuonExtraExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenMuonExtra.size()== mNumMuons) return true;
    else return false;
  }

  std::ostream& MCMuonExtraExists::Description(std::ostream &ostrm) {
    ostrm << "MCMuonExtraExists (make a cut on the existence of genMuons (status 1 and 3)) " ;
    return ostrm;
  }

  //================
  // MC Electron exists
  //================

  MCElectronExists::MCElectronExists(unsigned int numElectrons) :
  mNumElectrons(numElectrons) {}

  MCElectronExists::~MCElectronExists() {}

  bool MCElectronExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenEli.size()== mNumElectrons) return true;
    else return false;
  }

  std::ostream& MCElectronExists::Description(std::ostream &ostrm) {
    ostrm << "MCElectronExists (make a cut on the existence of genElectrons) " ;
    return ostrm;
  }

  //================
  // MC Photon exists
  //================

  MCPhotonExists::MCPhotonExists(unsigned int numPhotons) :
  mNumPhotons(numPhotons) {}

  MCPhotonExists::~MCPhotonExists() {}

  bool MCPhotonExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenPhot.size()== mNumPhotons) return true;
    else return false;
  }

  std::ostream& MCPhotonExists::Description(std::ostream &ostrm) {
    ostrm << "MCPhotonExists (make a cut on the existence of genPhotons) " ;
    return ostrm;
  }

  //================
  // MC GenJet exists
  //================

  MCGenJetExists::MCGenJetExists(unsigned int numGenJets) :
  mGenJets(numGenJets) {}

  MCGenJetExists::~MCGenJetExists() {}

  bool MCGenJetExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenJets.size() > mGenJets) return true;
    else return false;
  }

  std::ostream& MCGenJetExists::Description(std::ostream &ostrm) {
    ostrm << "MCGenJetExists (make a cut on the existence of genJets) " ;
    return ostrm;
  }

  //================
  // RECO Muon exists
  //================

  RECOMuonExists::RECOMuonExists(unsigned int numMuons) :
  mNumMuons(numMuons) {}

  RECOMuonExists::~RECOMuonExists() {}

  bool RECOMuonExists::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size() == mNumMuons) return true;
    else return false;
  }

  std::ostream& RECOMuonExists::Description(std::ostream &ostrm) {
    ostrm << "RECOMuonExists (make a cut on the existence of recoMuons) " ;
    return ostrm;
  }

  //================
  // RECO Cut on CommonJet MHT (MHT = negative vector sum of jets)
  //================

  RECOCommonMHTCut::RECOCommonMHTCut(float MHTCut) :
  mMHTCut(MHTCut) {}

  RECOCommonMHTCut::~RECOCommonMHTCut() {}

  bool RECOCommonMHTCut::Process(Event::Data & ev) {

    if(ev.CommonMHT().Pt() > mMHTCut) return true;
    else return false;
  }

  std::ostream& RECOCommonMHTCut::Description(std::ostream &ostrm) {
    ostrm << "RECOCommonMHTCut (make a cut on the Pt of vector sum of RecoCommonJets) " ;
    return ostrm;
  }

  //================
  // RECO Cut on DeltaR between closest jet and muon
  //================

  RECOMuonJetDRCut::RECOMuonJetDRCut(float MuonJetDRCut) :
  mMuonJetDRCut(MuonJetDRCut) {}

  RECOMuonJetDRCut::~RECOMuonJetDRCut() {}

  bool RECOMuonJetDRCut::Process(Event::Data & ev) {

    float minDeltaR = 0.0;
    for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
      if (i == 0) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonMuons().accepted.at(0))));
      else {
	if(fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonMuons().accepted.at(0)))) < minDeltaR) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonMuons().accepted.at(0))));
      }
  
	}

    if(minDeltaR > mMuonJetDRCut) return true;
    else return false;
  }

  std::ostream& RECOMuonJetDRCut::Description(std::ostream &ostrm) {
    ostrm << "RECOMuonJetDRCut (make a cut on the DeltaR between the muon and the closest jet) " ;
    return ostrm;
  }


} //~namespace Operation
