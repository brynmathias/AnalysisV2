#include "CutsAndChecks.hh"
//originally written by Jad Marrouche, Sep 2009 onwards
namespace Operation {

  //================
  // Custom Print Debug Info
  //================

  PrintDebugInfo::PrintDebugInfo(const char * option) {
    mType = option;
  }

  PrintDebugInfo::~PrintDebugInfo() {}

  bool PrintDebugInfo::Process(Event::Data & ev) {

    GenMatrixBin myGenMatrixBin(&ev);
    unsigned int WIndex = myGenMatrixBin.the_GenW[0]->GetIndex();
    
    TLorentzVector jGenW(myGenMatrixBin.the_GenW[0]->Px(), myGenMatrixBin.the_GenW[0]->Py(), myGenMatrixBin.the_GenW[0]->Pz(), myGenMatrixBin.the_GenW[0]->E());
    TLorentzVector jq1(ev.GenParticles()[WIndex-1].Px(), ev.GenParticles()[WIndex-1].Py(), ev.GenParticles()[WIndex-1].Pz(), ev.GenParticles()[WIndex-1].E());
    TLorentzVector jq2(ev.GenParticles()[WIndex-2].Px(), ev.GenParticles()[WIndex-2].Py(), ev.GenParticles()[WIndex-2].Pz(), ev.GenParticles()[WIndex-2].E());

    TVector3 boost = jGenW.BoostVector();
    jq1.Boost(-boost);
    jq2.Boost(-boost);

    jq1+=jq2;
    cout << "total qqbar vec: X() " << jq1.X() << ", Y() " << jq1.Y() << ", Z() " << jq1.Z() << endl;
    cout << "q2rest vec: X() " << jq2.X() << ", Y() " << jq2.Y() << ", Z() " << jq2.Z() << endl;
    cout << "some W info: PT(W) " << jGenW.Pt() << ", PW() " << jGenW.P() << ", cos(angle W and q2rest): " << TMath::Cos(ROOT::Math::VectorUtil::Angle(jq2,jGenW)) << endl;
    cout << endl << endl;
    return true;

    std::cout << "EventWeight: " << ev.GetEventWeight() << std::endl;
    //print full event info:
    //Compute::MC::PrintGen(ev);
    if( ev.JD_CommonJets().accepted.size() ) {
//    if( ev.EventNumber() == 102 ) {
      std::cout << "Event: " << ev.EventNumber() << std::endl;
      std::cout << "Jet Multiplicity: " << ev.JD_CommonJets().accepted.size() << std::endl;
      std::cout << "Common MHT: " << ev.CommonMHT().Pt() << std::endl;
      for(unsigned int i=0; i < ev.JD_CommonJets().accepted.size(); i++ ) {
        std::cout << " Pt: "  << ev.JD_CommonJets().accepted.at(i)->Pt()
                  << " Eta: " << ev.JD_CommonJets().accepted.at(i)->Eta()
                  << " Phi: " << ev.JD_CommonJets().accepted.at(i)->Phi()
                  << std::endl;
      }
    }

    return true;
  }

  std::ostream& PrintDebugInfo::Description(std::ostream &ostrm) {
    ostrm << "PrintDebugInfo Operation performed...";
    return ostrm;
  }


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
  // MC Check Existence of Z boson
  //================

  MCZExists::MCZExists() {}

  MCZExists::~MCZExists() {}

  bool MCZExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (myGenMatrixBin.the_GenZ.size()>0) return true; //a Generator Z exists in the event
    return false;
  }

  std::ostream& MCZExists::Description(std::ostream &ostrm) {
    ostrm << "MCZExists (i.e. at least 1 genZ exists in the event) " ;
    return ostrm;
  }

  //================
  // MC Check Existence of W decaying to muon + neutrino
  //================

  MCWMuonExists::MCWMuonExists() {}

  MCWMuonExists::~MCWMuonExists() {}

  bool MCWMuonExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (   myGenMatrixBin.the_GenMuon.size()>0 && myGenMatrixBin.the_GenMuonNu.size()>0
        && myGenMatrixBin.the_GenTau.size()==0 && myGenMatrixBin.the_GenEli.size()==0) {
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
  // MC Check Existence of W decaying to lepton + lepton neutrino
  //================

  MCWLeptonExists::MCWLeptonExists() {}

  MCWLeptonExists::~MCWLeptonExists() {}

  bool MCWLeptonExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (   myGenMatrixBin.the_GenMuon.size()>0 && myGenMatrixBin.the_GenMuonNu.size()>0 
        && myGenMatrixBin.the_GenTau.size()==0 && myGenMatrixBin.the_GenEli.size()==0) {
      //if there is a muon + neutrino and no tau/electron, and if both their mothers = the index of the W in the genmatrix bin
      //then they are related - this is to be used in the W+Jets sample where there is nominally 1 W boson...
      if(myGenMatrixBin.the_GenMuon.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex() &&
         myGenMatrixBin.the_GenMuonNu.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex()) return true;
    }

    if (   myGenMatrixBin.the_GenTau.size()>0 && myGenMatrixBin.the_GenTauNu.size()>0
        && myGenMatrixBin.the_GenMuon.size()==0 && myGenMatrixBin.the_GenEli.size()==0) {
      //if there is a tau + neutrino and no muon/electron, and if both their mothers = the index of the W in the genmatrix bin
      //then they are related - this is to be used in the W+Jets sample where there is nominally 1 W boson...
      if(myGenMatrixBin.the_GenTau.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex() &&
         myGenMatrixBin.the_GenTauNu.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex()) return true;
    }

    if (   myGenMatrixBin.the_GenEli.size()>0 && myGenMatrixBin.the_GenEliNu.size()>0
        && myGenMatrixBin.the_GenTau.size()==0 && myGenMatrixBin.the_GenMuon.size()==0) {
      //if there is an electron + neutrino and no tau/muon, and if both their mothers = the index of the W in the genmatrix bin
      //then they are related - this is to be used in the W+Jets sample where there is nominally 1 W boson...
      if(myGenMatrixBin.the_GenEli.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex() &&
         myGenMatrixBin.the_GenEliNu.at(0)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetIndex()) return true;
    }

    return false;
  }

  std::ostream& MCWLeptonExists::Description(std::ostream &ostrm) {
    ostrm << "MCWLeptonExists (i.e. at least 1 genW decays to a lepton in the event) " ;
    return ostrm;
  }

  //================
  // MC Muon comes from W decay (for MuonExtra i.e. from Tau decays too)
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
  // MC Cut on W boson coming from tree level quark-antiquark
  //================

  MCqqbarW::MCqqbarW() {}

  MCqqbarW::~MCqqbarW() {}

  bool MCqqbarW::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenW.size()) {
      unsigned int WIndex = myGenMatrixBin.the_GenW.at(0)->GetIndex(); //this gives the particle index 
      for(unsigned int i = WIndex - 1; i > 1; i--) {
	//in this loop, check that all particles BEFORE the W (but after the first two protons) are either u or d quarks
	if(fabs(ev.GenParticles()[i].GetID()) != 1 && fabs(ev.GenParticles()[i].GetID()) != 2 ) return false;
      }
      //now check that the W is produced on its own, i.e. the next particle index in the chain does not have the same mother as the W
      if(myGenMatrixBin.the_GenW.at(0)->GetMother() == ev.GenParticles()[WIndex+1].GetMother()) return false;
      return true;
      
    } else return false;
    
  }
  
  std::ostream& MCqqbarW::Description(std::ostream &ostrm) {
    ostrm << "MCqqbarW (make a cut on the tree-level qqbar->W prod mechanism)";
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
    if(myGenMatrixBin.the_GenW.size()>0) {
      if(myGenMatrixBin.the_GenW.at(0)->Pt() > mPtCut) return true;
    }
    
    if(myGenMatrixBin.the_GenZ.size()>0) {
      if(myGenMatrixBin.the_GenZ.at(0)->Pt() > mPtCut) return true;
    } 

    return false;
  }

  std::ostream& MCWPTCut::Description(std::ostream &ostrm) {
    ostrm << "MCPTCut (make a cut on the genW Pt) > " << mPtCut << "GeV";
    return ostrm;
  }

  //================
  // MC Cut on W boson Pt
  //================

  MCWPTCut2::MCWPTCut2(float PtCutMin, float PtCutMax) :
  mPtCutMin(PtCutMin),
  mPtCutMax(PtCutMax) {}

  MCWPTCut2::~MCWPTCut2() {}

  bool MCWPTCut2::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenW.size()>0) {
      if (myGenMatrixBin.the_GenW.at(0)->Pt() > mPtCutMin && myGenMatrixBin.the_GenW.at(0)->Pt() <= mPtCutMax) return true;
    }
    if(myGenMatrixBin.the_GenZ.size()>0) {
      if (myGenMatrixBin.the_GenZ.at(0)->Pt() > mPtCutMin && myGenMatrixBin.the_GenZ.at(0)->Pt() <= mPtCutMax) return true;
    }
    return false;
  }

  std::ostream& MCWPTCut2::Description(std::ostream &ostrm) {
    ostrm << "MCPTCut2 (make a cut on the genW Pt) > " << mPtCutMin << " && < " << mPtCutMax;
    return ostrm;
  }

  //================
  // MC Cut on W boson Rapidity
  //================

  MCWYCut::MCWYCut(float YCutMin, float YCutMax) :
  mYCutMin(YCutMin),
  mYCutMax(YCutMax) {}

  MCWYCut::~MCWYCut() {}

  bool MCWYCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenW.size()>0) {
      if (fabs(myGenMatrixBin.the_GenW.at(0)->Rapidity()) > mYCutMin && fabs(myGenMatrixBin.the_GenW.at(0)->Rapidity()) <= mYCutMax) return true;
    }
    if(myGenMatrixBin.the_GenZ.size()>0) {
      if (fabs(myGenMatrixBin.the_GenZ.at(0)->Rapidity()) > mYCutMin && fabs(myGenMatrixBin.the_GenZ.at(0)->Rapidity()) <= mYCutMax) return true;
    }
    return false;
  }

  std::ostream& MCWYCut::Description(std::ostream &ostrm) {
    ostrm << "MCYCut (make a cut on the genW |Rapidity|) > " << mYCutMin << " && < " << mYCutMax;
    return ostrm;
  }

  //================
  // MC Cut on W boson Rapidity
  //================

  MCWYCut2::MCWYCut2(float YCutMin) :
  mYCutMin(YCutMin) {}

  MCWYCut2::~MCWYCut2() {}

  bool MCWYCut2::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenW.size()>0) {
      if (fabs(myGenMatrixBin.the_GenW.at(0)->Rapidity()) > mYCutMin) return true;
    }
    if(myGenMatrixBin.the_GenZ.size()>0) {
      if (fabs(myGenMatrixBin.the_GenZ.at(0)->Rapidity()) > mYCutMin) return true;
    }
    return false;
  }

  std::ostream& MCWYCut2::Description(std::ostream &ostrm) {
    ostrm << "MCWYCut2 (make a cut on the genW |Rapidity|) > " << mYCutMin;
    return ostrm;
  }

  //================
  // MC Cut on Muon Acceptance
  //================

  MCMuonAccCut::MCMuonAccCut(float PtCut, float EtaCut) :
    mPtCut(PtCut),
    mEtaCut(EtaCut) {}

  MCMuonAccCut::~MCMuonAccCut() {}

  bool MCMuonAccCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (myGenMatrixBin.the_GenMuon.at(0)->Pt() > mPtCut && fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()) < mEtaCut) return true;
    return false;
  }

  std::ostream& MCMuonAccCut::Description(std::ostream &ostrm) {
    ostrm << "MCMuonAccCut (make a cut on the gen level muon Pt > " << mPtCut << " && |eta| < " << mEtaCut << ") " ;
    return ostrm;
  }

  //================
  // MC Check Centre of Mass Frame Boost Direction
  //================
/*
  MCCOMBoostDir::MCCOMBoostDir(bool postrue) :
  mPostrue(postrue) {}

  MCCOMBoostDir::~MCCOMBoostDir() {}

  bool MCCOMBoostDir::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if (mPostrue == myGenMatrixBin.boostVectorPlus) return true;
    return false;
  }

  std::ostream& MCCOMBoostDir::Description(std::ostream &ostrm) {
    ostrm << "MCCOMBoostDir (cut on boost direction in com frame) " ;
    return ostrm;
  }
*/
  //================
  // MC Check for squark-gluino from same mother in event
  //================
/*
  MCSGEvent::MCSGEvent() {}

  MCSGEvent::~MCSGEvent() {}

  bool MCSGEvent::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);

    //first check that there is at least 1 gluino and at least 1 squark
    if (myGenMatrixBin.the_GenGluino.size() > 0 && myGenMatrixBin.the_GenSquark.size() > 0) {
      for(unsigned int j=0; j<myGenMatrixBin.the_GenGluino.size(); j++) {
      //now loop over all the squarks and check one of them shares the same mother as the gluino
	for(unsigned int i=0; i<myGenMatrixBin.the_GenSquark.size(); i++) {
	//check it's a valence squark
	  if(fabs(myGenMatrixBin.the_GenSquark.at(i)->GetID()) == 1000001 || fabs(myGenMatrixBin.the_GenSquark.at(i)->GetID()) == 1000002 || fabs(myGenMatrixBin.the_GenSquark.at(i)->GetID()) == 2000001 || fabs(myGenMatrixBin.the_GenSquark.at(i)->GetID()) == 2000002 ) {
	    if(myGenMatrixBin.the_GenGluino.at(j)->GetMother() == myGenMatrixBin.the_GenSquark.at(i)->GetMother()) {
	    //i.e. they have the same mother
	      unsigned int motherindex = myGenMatrixBin.the_GenMuon.at(0)->GetMother();//this is done after asking for 1 gen muon in the cutflow
	      while(motherindex != -1) {
		if(motherindex == myGenMatrixBin.the_GenSquark.at(i)->GetIndex()) return true;
		motherindex = ev.GenParticles().at(motherindex).GetMother();
	      }
	      return false;
	    }
	  }
	}
      }
      return false;
    } 
    return false;
    
  }

  std::ostream& MCSGEvent::Description(std::ostream &ostrm) {
    ostrm << "MCSGEvent (cut on 1 squark and 1 gluino sharing same mother in event) " ;
    return ostrm;
  }
*/
  //================
  // MC Cut on GenJet VHT (VHT = vector sum of jets)
  //================

  MCVHTCut::MCVHTCut(float VHTCut, float JetEtaCut) :
    mVHTCut(VHTCut),
    mJetEtaCut(JetEtaCut) {}

  MCVHTCut::~MCVHTCut() {}

  bool MCVHTCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    LorentzV jVHT;
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      if(fabs(myGenMatrixBin.the_GenJets.at(i)->Eta()) < mJetEtaCut) jVHT += (*(myGenMatrixBin.the_GenJets.at(i)));
    }

    if (jVHT.Pt() > mVHTCut) return true;
    else return false;
  }

  std::ostream& MCVHTCut::Description(std::ostream &ostrm) {
    ostrm << "MCVHTCut (make a cut on the Pt of vector sum of GenJets = " << mVHTCut << " and jetetacut = " << mJetEtaCut << ") " ;
    return ostrm;
  }

  //================
  // MC Cut on GenJet HT (HT = scalar sum of jet Pt)
  //================

  MCJetHTCut::MCJetHTCut(float HTCut, float JetEtaCut) :
    mHTCut(HTCut),
    mJetEtaCut(JetEtaCut) {}

  MCJetHTCut::~MCJetHTCut() {}

  bool MCJetHTCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    float jHT=0.0;
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      if(fabs(myGenMatrixBin.the_GenJets.at(i)->Eta()) < mJetEtaCut) jHT += (myGenMatrixBin.the_GenJets.at(i)->Pt());
    }

    if (jHT > mHTCut) return true;
    else return false;
  }

  std::ostream& MCJetHTCut::Description(std::ostream &ostrm) {
    ostrm << "MCJetHTCut (make a cut on the HT of GenJets = " << mHTCut << " and jetetacut = " << mJetEtaCut << ") " ;
    return ostrm;
  }

  //================
  // MC Lepton exists
  //================

  MCLeptonExists::MCLeptonExists(std::string flavour, unsigned int numLeptons) :
    mFlavour(flavour),
    mNumLeptons(numLeptons) {}

  MCLeptonExists::~MCLeptonExists() {}

  bool MCLeptonExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(mFlavour == "tau") {
      if(myGenMatrixBin.the_GenTau.size()== mNumLeptons) return true;
      else return false;
    }else if(mFlavour == "muon") {
      if(myGenMatrixBin.the_GenMuon.size()== mNumLeptons) return true;
      else return false;
    }else if(mFlavour == "electron") {
      if(myGenMatrixBin.the_GenEli.size()== mNumLeptons) return true;
      else return false;
    }else {
      std::cout << "Check you entered a true lepton flavour! either tau, muon or electron" << std::endl;
      return false;
    }
  }

  std::ostream& MCLeptonExists::Description(std::ostream &ostrm) {
    ostrm << "MCLeptonExists (make a cut on the existence of " << mNumLeptons << " " << mFlavour <<")";
    return ostrm;
  }
  //================
  // MC Status1 Lepton exists
  //================

  MCS1LeptonExists::MCS1LeptonExists(std::string flavour) :
    mFlavour(flavour) {}

  MCS1LeptonExists::~MCS1LeptonExists() {}

  bool MCS1LeptonExists::Process(Event::Data & ev) {

    for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();  j != ev.GenParticles().end(); ++j) {

      if (j->GetStatus()==1) {
	if(mFlavour == "muon" && fabs(j->GetID())==13 && fabs(j->GetMother())==15) return true;
	//if(mFlavour == "muon" && fabs(j->GetID())==13) return true;
	if(mFlavour == "electron" && fabs(j->GetID())==11) return true;
      }
    }
    return false;
  }

  std::ostream& MCS1LeptonExists::Description(std::ostream &ostrm) {
    ostrm << "MCLeptonExists (make a cut on the existence of Status 1 " << mFlavour <<"s)";
    return ostrm;
  }

  //================
  // MCRECO Cut on recoPFMET minus genMuon
  //================

  MCRECOPFMETCut::MCRECOPFMETCut(float PFMETCut) :
    mPFMETCut(PFMETCut) {}

  MCRECOPFMETCut::~MCRECOPFMETCut() {}

  bool MCRECOPFMETCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);

    if(myGenMatrixBin.the_GenMuonExtra.size()) { //i.e. if there are any generator muons, try to match - if not,just use the pfMET from the RECO event
    //if(myGenMatrixBin.the_GenMuon.size()) { 
      double MCRECO_PFMHT=0.0;
      double DeltaR_MCRECO_Muon=0.0;
      if(ev.LD_Muons().size()) {
	for (std::vector<Event::Lepton>::const_iterator imu = ev.LD_Muons().begin();  imu != ev.LD_Muons().end();++imu) {
	  DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*imu,*(myGenMatrixBin.the_GenMuonExtra.at(0)));
	  //DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*imu,*(myGenMatrixBin.the_GenMuon.at(0)));
	  if(DeltaR_MCRECO_Muon < 0.1) {
	    //we have found the muon that matches the gen level
	    MCRECO_PFMHT = (ev.PFMET() + *imu).Pt();	    
	    if(MCRECO_PFMHT > mPFMETCut) return true;
	    else return false;
	  }
	}
	//if we get here, we haven't found a muon that matches, so just test the pfMET>cut
	if(ev.PFMET().Pt() > mPFMETCut) return true;
	else return false;
      } else if(ev.PFMET().Pt() > mPFMETCut) return true;    
    }
    return false;
  }
  
  std::ostream& MCRECOPFMETCut::Description(std::ostream &ostrm) {
    ostrm << "MCRECOPFMETCut (make a cut on the recoPFMET - genMuon > " << mPFMETCut << ") " ;
    return ostrm;
  }

  //================
  // MCRECO Cut2 on recoPFMET minus genMuon
  //================

  MCRECOPFMETCut2::MCRECOPFMETCut2(float PFMETCutmin, float PFMETCutmax) :
    mPFMETCutmin(PFMETCutmin),
    mPFMETCutmax(PFMETCutmax) {}

  MCRECOPFMETCut2::~MCRECOPFMETCut2() {}

  bool MCRECOPFMETCut2::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);

    if(myGenMatrixBin.the_GenMuonExtra.size()) { //i.e. if there are any generator muons, try to match - if not,just use the pfMET from the RECO event
    //if(myGenMatrixBin.the_GenMuon.size()) { 
      double MCRECO_PFMHT=0.0;
      double DeltaR_MCRECO_Muon=0.0;
      if(ev.LD_Muons().size()) {
	for (std::vector<Event::Lepton>::const_iterator imu = ev.LD_Muons().begin();  imu != ev.LD_Muons().end();++imu) {
	  DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*imu,*(myGenMatrixBin.the_GenMuonExtra.at(0)));
	  //DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*imu,*(myGenMatrixBin.the_GenMuon.at(0)));
	  if(DeltaR_MCRECO_Muon < 0.1) {
	    //we have found the muon that matches the gen level
	    MCRECO_PFMHT = (ev.PFMET() + *imu).Pt();	    
	    if(MCRECO_PFMHT > mPFMETCutmin && MCRECO_PFMHT <= mPFMETCutmax) return true;
	    else return false;
	  }
	}
	//if we get here, we haven't found a muon that matches, so just test the pfMET>cut
	if(ev.PFMET().Pt() > mPFMETCutmin && ev.PFMET().Pt() <= mPFMETCutmax) return true;
	else return false;
      } else if(ev.PFMET().Pt() > mPFMETCutmin && ev.PFMET().Pt() <= mPFMETCutmax) return true;    
    }
    return false;
  }
  
  std::ostream& MCRECOPFMETCut2::Description(std::ostream &ostrm) {
    ostrm << "MCRECOPFMETCut2 (make a cut on:" << mPFMETCutmin << " < (recoPFMET - genMuon) < " << mPFMETCutmax << ") " ;
    return ostrm;
  }

 //================
 // MCRECO Cut on RECO Pt Z for ev. with 2 GenMuonExtra only
 //================

 MCRECOZPFMETCut::MCRECOZPFMETCut(float PFMETCut) :
    mPFMETCut(PFMETCut) {}

  MCRECOZPFMETCut::~MCRECOZPFMETCut() {}

  bool MCRECOZPFMETCut::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);

    if (myGenMatrixBin.the_GenMuonExtra.size()!=2) {std::cout << "Something is wrong: not 2 muons at gen level" << std::endl; return false;}

    bool matchfound[2];
    int match[2];

    for (int i=0;i<=1;i++) {
      matchfound[i]=false;
      match[i]=0;
      double DeltaR_MCRECO_Muon;
      double bestDR=1000;
      int j;
      for (j=0; j<ev.LD_Muons().size(); j++) {
	DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR((ev.LD_Muons())[j],*(myGenMatrixBin.the_GenMuonExtra.at(i)));
	if (DeltaR_MCRECO_Muon < bestDR) {bestDR=DeltaR_MCRECO_Muon; match[i]=j;}
      }
      if(bestDR<0.1) {matchfound[i]=true;}
    }

    double cutvar;
    if(matchfound[0]&&matchfound[1]) cutvar=((ev.LD_Muons())[match[0]]+(ev.LD_Muons())[match[1]]).Pt();
    if(matchfound[0]&&!matchfound[1]) cutvar=((ev.LD_Muons())[match[0]]+*(myGenMatrixBin.the_GenMuonExtra.at(1))).Pt();
    if(!matchfound[0]&&matchfound[1]) cutvar=((ev.LD_Muons())[match[1]]+*(myGenMatrixBin.the_GenMuonExtra.at(0))).Pt();
    if(!matchfound[0]&&!matchfound[1]) cutvar=(*(myGenMatrixBin.the_GenMuonExtra.at(0))+*(myGenMatrixBin.the_GenMuonExtra.at(1))).Pt();

    if (cutvar>mPFMETCut) return true; else return false;

  }
  
  std::ostream& MCRECOZPFMETCut::Description(std::ostream &ostrm) {
    ostrm << "MCRECOPFMETCut (make a cut on the best RECO estimate of Z Pt > " << mPFMETCut << ") " ;
    return ostrm;
  }


  //================
  // MC ZtoLeptons exists
  //================

  MCZtoLeptons::MCZtoLeptons(std::string flavour) :
    mFlavour(flavour) {}

  MCZtoLeptons::~MCZtoLeptons() {}

  bool MCZtoLeptons::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenZ.size()) {
      if(mFlavour == "tau") {
	if(myGenMatrixBin.the_GenTau.size() == 2 && myGenMatrixBin.the_GenMuon.size() == 0 && myGenMatrixBin.the_GenEli.size() == 0) return true;
	else return false;
      } else if(mFlavour == "muon") {
	if(myGenMatrixBin.the_GenTau.size() == 0 && myGenMatrixBin.the_GenMuon.size() == 2 && myGenMatrixBin.the_GenEli.size() == 0) return true;
	else return false;	
      } else if(mFlavour == "electron") {
	if(myGenMatrixBin.the_GenTau.size() == 0 && myGenMatrixBin.the_GenMuon.size() == 0 && myGenMatrixBin.the_GenEli.size() == 2) return true;
	else return false;
      } else {
	std::cout << "Check you entered a true lepton flavour! either tau, muon or electron" << std::endl;
	return false;
      }
    }
    return false;
  }

  std::ostream& MCZtoLeptons::Description(std::ostream &ostrm) {
    ostrm << "MCZtoLeptons (ask that the Z-boson decays to " << mFlavour << "s at generator level) " ;
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
  // MC GenJet exists GT
  //================

  MCGTGenJetExists::MCGTGenJetExists(unsigned int numGenJets, float JetEtaCut) :
    mGenJets(numGenJets),
    mJetEtaCut(JetEtaCut) {}

  MCGTGenJetExists::~MCGTGenJetExists() {}

  bool MCGTGenJetExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    unsigned int nJets=0;
    for(unsigned int i=0; i < myGenMatrixBin.the_GenJets.size(); i++) {
      if(fabs(myGenMatrixBin.the_GenJets.at(i)->Eta()) < mJetEtaCut) nJets++;
    }
    if(nJets > mGenJets) return true;
    else return false;
  }

  std::ostream& MCGTGenJetExists::Description(std::ostream &ostrm) {
    ostrm << "MCGTGenJetExists (make a cut on > " << mGenJets << " genJets) " ;
    return ostrm;
  }

  //================
  // MC GenJet exists LT
  //================

  MCLTGenJetExists::MCLTGenJetExists(unsigned int numGenJets, float JetEtaCut) :
    mGenJets(numGenJets),
    mJetEtaCut(JetEtaCut) {}

  MCLTGenJetExists::~MCLTGenJetExists() {}

  bool MCLTGenJetExists::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    unsigned int nJets=0;
    for(unsigned int i=0; i < myGenMatrixBin.the_GenJets.size(); i++) {
      if(fabs(myGenMatrixBin.the_GenJets.at(i)->Eta()) < mJetEtaCut) nJets++;
    }
    if(nJets < mGenJets) return true;
    else return false;
  }

  std::ostream& MCLTGenJetExists::Description(std::ostream &ostrm) {
    ostrm << "MCLTGenJetExists (make a cut on < " << mGenJets << " genJets) " ;
    return ostrm;
  }

  //================
  // TRIGGER Cut
  //================

  TRIGGERCut::TRIGGERCut(const std::string & triggerName1, const std::string & triggerName2) :
    mTriggerName1(triggerName1),
    mTriggerName2(triggerName2) {}

  TRIGGERCut::~TRIGGERCut() {}

  bool TRIGGERCut::Process(Event::Data & ev) {

    if(ev.pthat.enabled()) {
      //i.e. are you considering MC

      //bool result1;
      std::map<std::string,bool>::const_iterator it1=ev.hlt()->find(mTriggerName1);
      if(it1==ev.hlt()->end()){ 
	throw std::invalid_argument("MC: Trigger Bit1 not found!");
      }else{ 
	if(it1->second){
	  return true; 
	}
	//	result1 = it1->second;
      }

      //bool result2;
      std::map<std::string,bool>::const_iterator it2=ev.hlt()->find(mTriggerName2);
      
      if(it2==ev.hlt()->end()) { 
	throw std::invalid_argument("MC: Trigger Bit2 not found!");
      }
      return it2->second;
      
    } else {
      if(ev.RunNumber() < 147146) { //this run number is the one where HLT_Mu9 got prescaled
	std::map<std::string,bool>::const_iterator it=ev.hlt()->find(mTriggerName1);
	if(it==ev.hlt()->end()) throw std::invalid_argument("DATA: Trigger Bit1 not found!");
	else return it->second;
      } else {
	std::map<std::string,bool>::const_iterator it=ev.hlt()->find(mTriggerName2);
	if(it==ev.hlt()->end()) throw std::invalid_argument("DATA: Trigger Bit2 not found!");
	else return it->second;
      }
    }

  //if(ev.hlt()->find(mTriggerName)->second) return true;
  //else return false;
  }

  std::ostream& TRIGGERCut::Description(std::ostream &ostrm) {
    ostrm << "TRIGGERCut (Filter on trigger bits " << mTriggerName1 <<" and " << mTriggerName2 << ") ";
    return ostrm;
  }

 ORTRIGGERCut::ORTRIGGERCut(const std::string & triggerName1, const std::string & triggerName2) :
    mTriggerName1(triggerName1),
    mTriggerName2(triggerName2) {}

  ORTRIGGERCut::~ORTRIGGERCut() {}

  bool ORTRIGGERCut::Process(Event::Data & ev) {

      //bool result1;
      std::map<std::string,bool>::const_iterator it1=ev.hlt()->find(mTriggerName1);
      if(it1!=ev.hlt()->end()){ 
	if(it1->second){
	  return true; 
	}
      }

      //bool result2;
      std::map<std::string,bool>::const_iterator it2=ev.hlt()->find(mTriggerName2);
      if(it2!=ev.hlt()->end()) { 
	if(it2->second){
	  return true; 
	}
      }

	return false;
      
  }

  std::ostream& ORTRIGGERCut::Description(std::ostream &ostrm) {
    ostrm << "ORTRIGGERCut (Filter on trigger bits " << mTriggerName1 <<" OR " << mTriggerName2 << ") ";
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
  // RECO Cut on ZPt from Muons (better resolution than MHT)
  //================

  RECOMuMuPtCut::RECOMuMuPtCut(float ZPtCut) :
    mZPtCut(ZPtCut) {}

  RECOMuMuPtCut::~RECOMuMuPtCut() {}

  bool RECOMuMuPtCut::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size() == 2) {
      TLorentzVector muon1(ev.LD_CommonMuons().accepted.at(0)->Px(), ev.LD_CommonMuons().accepted.at(0)->Py(), ev.LD_CommonMuons().accepted.at(0)->Pz(), ev.LD_CommonMuons().accepted.at(0)->E());
      TLorentzVector muon2(ev.LD_CommonMuons().accepted.at(1)->Px(), ev.LD_CommonMuons().accepted.at(1)->Py(), ev.LD_CommonMuons().accepted.at(1)->Pz(), ev.LD_CommonMuons().accepted.at(1)->E());
      TLorentzVector Z = muon1 + muon2;
      if(Z.Pt() > mZPtCut) return true;
      else return false;
    }
    return false;
  }

  std::ostream& RECOMuMuPtCut::Description(std::ostream &ostrm) {
    ostrm << "RECOMuMuMuPtCut (make a cut on the Pt from two reconstructed muons > " << mZPtCut << ") " ;
    return ostrm;
  }

  //================
  // RECO Cut2 on ZPt from Muons (better resolution than MHT)
  //================

  RECOMuMuPtCut2::RECOMuMuPtCut2(float ZPtCutmin, float ZPtCutmax) :
    mZPtCutmin(ZPtCutmin),
    mZPtCutmax(ZPtCutmax) {}

  RECOMuMuPtCut2::~RECOMuMuPtCut2() {}

  bool RECOMuMuPtCut2::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size() == 2) {
      TLorentzVector muon1(ev.LD_CommonMuons().accepted.at(0)->Px(), ev.LD_CommonMuons().accepted.at(0)->Py(), ev.LD_CommonMuons().accepted.at(0)->Pz(), ev.LD_CommonMuons().accepted.at(0)->E());
      TLorentzVector muon2(ev.LD_CommonMuons().accepted.at(1)->Px(), ev.LD_CommonMuons().accepted.at(1)->Py(), ev.LD_CommonMuons().accepted.at(1)->Pz(), ev.LD_CommonMuons().accepted.at(1)->E());
      TLorentzVector Z = muon1 + muon2;
      if(Z.Pt() > mZPtCutmin && Z.Pt() <= mZPtCutmax) return true;
      else return false;
    }
    return false;
  }

  std::ostream& RECOMuMuPtCut2::Description(std::ostream &ostrm) {
    ostrm << "RECOMuMuMuPtCut2 (make a cut on the Pt from two reconstructed muons > " << mZPtCutmin << " & <= " << mZPtCutmax << ") " ;
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
  // RECO Cut2 on CommonJet MHT (MHT = negative vector sum of jets)
  //================

  RECOCommonMHTCut2::RECOCommonMHTCut2(float MHTCut_lowlim, float MHTCut_uplim) :
    mMHTCutlow(MHTCut_lowlim),
    mMHTCutup(MHTCut_uplim) {}

  RECOCommonMHTCut2::~RECOCommonMHTCut2() {}

  bool RECOCommonMHTCut2::Process(Event::Data & ev) {

    if(ev.CommonMHT().Pt() > mMHTCutlow && ev.CommonMHT().Pt() <= mMHTCutup ) return true;
    else return false;
  }

  std::ostream& RECOCommonMHTCut2::Description(std::ostream &ostrm) {
    ostrm << "RECOCommonMHTCut2 (make a cut on the Pt of vector sum of RecoCommonJets) " ;
    return ostrm;
  }

  //================
  // RECO Cut on PFMET minus Muon (better resolution than MHT)
  //================

  RECOPFMETCut::RECOPFMETCut(float PFMETCut) :
    mPFMETCut(PFMETCut) {}

  RECOPFMETCut::~RECOPFMETCut() {}

  bool RECOPFMETCut::Process(Event::Data & ev) {

    if(ev.LD_CommonMuons().accepted.size() == 1) {
      LorentzV mht = (ev.PFMET() + *(ev.LD_CommonMuons().accepted.at(0)));
      if(mht.Pt() > mPFMETCut) return true;
      else return false;
    }
    return false;
  }

  std::ostream& RECOPFMETCut::Description(std::ostream &ostrm) {
    ostrm << "RECOPFMETCut (make a cut on the PFMET - muon > " << mPFMETCut << ") " ;
    return ostrm;
  }

  //================
  // RECO Cut on PFMET minus Muon (better resolution than MHT)
  //================

  RECOPFMETCut2::RECOPFMETCut2(float PFMETCutmin, float PFMETCutmax) :
    mPFMETCutmin(PFMETCutmin),
    mPFMETCutmax(PFMETCutmax) {}

  RECOPFMETCut2::~RECOPFMETCut2() {}

  bool RECOPFMETCut2::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size() == 1) {
      LorentzV mht = (ev.PFMET() + *(ev.LD_CommonMuons().accepted.at(0)));
      if(mht.Pt() > mPFMETCutmin && mht.Pt() <= mPFMETCutmax) return true;
      else return false;
    }
    return false;
  }

  std::ostream& RECOPFMETCut2::Description(std::ostream &ostrm) {
    ostrm << "RECOPFMETCut2 (make a cut on the PFMET - muon > " << mPFMETCutmin << " and <= " << mPFMETCutmax << ") " ;
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

    if(ev.LD_CommonMuons().accepted.size() == 0 && ev.LD_CommonElectrons().accepted.size() == 0) return true; //i.e. no muons and electrons exist!
    if(ev.JD_CommonJets().accepted.size() == 0 ) return true; //i.e. no jets exist

    if(ev.LD_CommonMuons().accepted.size() > 0 ) {
      for ( unsigned int j=0; j< ev.LD_CommonMuons().accepted.size(); j++) {
	for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
	  if (i == 0) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonMuons().accepted.at(j))));
	  else {
	    if(fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonMuons().accepted.at(j)))) < minDeltaR) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonMuons().accepted.at(j))));
	  }
	}
	if(minDeltaR < mMuonJetDRCut) return false;
      }
    } else if(ev.LD_CommonElectrons().accepted.size() >0 ) {
      for ( unsigned int j=0; j< ev.LD_CommonElectrons().accepted.size(); j++) {
	for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
	  if (i == 0) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonElectrons().accepted.at(j))));
	  else {
	    if(fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonElectrons().accepted.at(j)))) < minDeltaR) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.LD_CommonElectrons().accepted.at(j))));
	  }
	}
	if(minDeltaR < mMuonJetDRCut) return false;
      }
    }
    return true; //i.e. if we have looped over all muons and electrons and found none of them in a jet, return true
  }

  std::ostream& RECOMuonJetDRCut::Description(std::ostream &ostrm) {
    ostrm << "RECOMuonJetDRCut (make a cut on the DeltaR between the muon and the closest jet) " ;
    return ostrm;
  }

  //================
  // RECO Cut on muon PT
  //================

  RECOMuonPT::RECOMuonPT(float MuonPt) :
    mMuonPtCut(MuonPt) {}

  RECOMuonPT::~RECOMuonPT() {}

  bool RECOMuonPT::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size()==0) return false;
    if(ev.LD_CommonMuons().accepted.at(0)->Pt()>mMuonPtCut) return true;
    else return false;

  }

  std::ostream& RECOMuonPT::Description(std::ostream &ostrm) {
    ostrm << "RECO MuonPT >" << mMuonPtCut;
    return ostrm;
  }

  RECO1of2MuonsOverPT::RECO1of2MuonsOverPT(float MuonPt) :
    mMuonPtCut(MuonPt) {}

  RECO1of2MuonsOverPT::~RECO1of2MuonsOverPT() {}

  bool RECO1of2MuonsOverPT::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size()!=2) return false;
    if(ev.LD_CommonMuons().accepted.at(0)->Pt()>mMuonPtCut) return true;
    if(ev.LD_CommonMuons().accepted.at(1)->Pt()>mMuonPtCut) return true;
    return false;
  }

  std::ostream& RECO1of2MuonsOverPT::Description(std::ostream &ostrm) {
    ostrm << "1 out of 2 RECO Muons has PT >" << mMuonPtCut;
    return ostrm;
  }


  //================
  // RECO Cut on second global muon
  //================

  RECOSecondGMCut::RECOSecondGMCut(float MuonPt) :
    mMuonPtCut(MuonPt) {}

  RECOSecondGMCut::~RECOSecondGMCut() {}

  bool RECOSecondGMCut::Process(Event::Data & ev) {

    //std::cout << "number of muons in event: " << ev.LD_Muons().size() << std::endl;
    unsigned int numAboveThresh = 0;
    
    //remember that we expect at least one muon above this threshold!
    for (std::vector<Event::Lepton>::const_iterator imu = ev.LD_Muons().begin();  imu != ev.LD_Muons().end();++imu) {
      //std::cout << "pt: " << imu->Pt() << ", isGlobal: " << ev.IsMuonGlobal(imu->GetIndex()) << std::endl;
      if(ev.IsMuonGlobal(imu->GetIndex()) && imu->Pt() > mMuonPtCut) numAboveThresh++;
    }
    if(numAboveThresh == 1) return true;
    else return false;
  }

  std::ostream& RECOSecondGMCut::Description(std::ostream &ostrm) {
    ostrm << "Cut on second global muon >" << mMuonPtCut;
    return ostrm;
  }

  //================
  // RECO Cut on muon Isolation
  //================

  RECOMuonISO::RECOMuonISO(float MuonCombIsoCut) :
    mMuonCombIsoCut(MuonCombIsoCut) {}

  RECOMuonISO::~RECOMuonISO() {}

  bool RECOMuonISO::Process(Event::Data & ev) {
    if(ev.LD_CommonMuons().accepted.size()==0) return false;
    if(ev.LD_CommonMuons().accepted.at(0)->GetCombIsolation()<mMuonCombIsoCut) return true;
    else return false;

  }

  std::ostream& RECOMuonISO::Description(std::ostream &ostrm) {
    ostrm << "RECO MuonCombIso <" << mMuonCombIsoCut;
    return ostrm;
  }

// MC CUT:  invariant mass of two muons in window around Z

MCMuMuInvMass::MCMuMuInvMass(float Min, float Max) :
mMin(Min), mMax(Max) {}

MCMuMuInvMass::~MCMuMuInvMass() {}

bool MCMuMuInvMass::Process(Event::Data & ev){

 GenMatrixBin myGenMatrixBin(&ev);

if (myGenMatrixBin.the_GenMuonExtra.size()!=2) return false;

ICF_LorentzV sum = (*(myGenMatrixBin.the_GenMuonExtra.at(0))+*(myGenMatrixBin.the_GenMuonExtra.at(1)));

float invmass = sum.M();

if (invmass>mMin && invmass<mMax) return true; else return false;

}

std::ostream& MCMuMuInvMass::Description(std::ostream &ostrm) {
    ostrm << "Gen-level cut on MuMu invariant mass: " << mMin << " < invmass < " << mMax;
    return ostrm;
  }




  //================
  // RECO Cut on invariant mass of muon pair (if it exists)
  //================

  RECO2ndMuonMass::RECO2ndMuonMass(float MuonPt, float Mass, bool keepZ, std::string charge) :
    mMuonPt(MuonPt), mMass(Mass), mKeepZ(keepZ), mCharge(charge) {}

  RECO2ndMuonMass::~RECO2ndMuonMass() {}

  bool RECO2ndMuonMass::Process(Event::Data & ev) {
    
    //do we want to veto (i.e. throw away) events in the Z-mass window?
    //also, do we want to explicitly take OS muons, SS muons or both?
    if(mCharge != "OS" && mCharge != "SS" && mCharge != "all") {
      std::cout << "RECO 2ndMuon Invariant Mass Cut - options on charge are SS, OS or all: " << mCharge << " selected. Please correct!" << std::endl;
      return false;
    }

    float Zmass = 0.0;
    //if(ev.LD_Muons().size()>1) { //not common muons, but all muons (we already check there is 1 common muon, but there could be more normal muons...)
    if(ev.LD_Muons().size()>0) {
      for (std::vector<Event::Lepton>::const_iterator imu = ev.LD_Muons().begin(); imu != ev.LD_Muons().end(); ++imu) {
	if(ev.LD_CommonMuons().accepted.at(0)->GetIndex() == imu->GetIndex()) continue; //i.e. don't make an invariant mass with the same muon (remember LD_CommonMuons is a subset of LD_Muons)
	if((ev.LD_CommonMuons().accepted.at(0)->GetCharge() != imu->GetCharge() && mCharge == "OS") || (ev.LD_CommonMuons().accepted.at(0)->GetCharge() == imu->GetCharge() && mCharge == "SS") || mCharge == "all") {
	  float ZmassCurrent = ROOT::Math::VectorUtil::InvariantMass(*imu,*(ev.LD_CommonMuons().accepted.at(0)));
          if(Zmass == 0.0) Zmass = ZmassCurrent;
          if(fabs(ZmassCurrent-mMass) < (fabs(Zmass-mMass))) Zmass = ZmassCurrent; //if another muon pair combination gives an invariant mass closer to the Z-mass...
	}
      }
    } else return false;
    
    bool inWindow;
    if(Zmass > mMass-mMuonPt && Zmass < mMass+mMuonPt) inWindow = true; //i.e. the event is in the Z-mass window
    else inWindow = false;

    //i.e. if the event is in the mass window and we want to keep those events, or if the event is not in the mass window, but we want to reject Z-events anyway, then keep these events    
    if((inWindow && mKeepZ) ||(!inWindow && !mKeepZ) ) return true; 
    
    return false; //otherwise either the event is in the mass window when we don't want it, or is outside the mass window when we do
  }

  std::ostream& RECO2ndMuonMass::Description(std::ostream &ostrm) {
    ostrm << "RECO 2ndMuon Invariant Mass +/- " << mMuonPt << "GeV from " << mMass << " are";
    if(!mKeepZ) ostrm << " NOT ";
    ostrm << "kept";
    return ostrm;
  }

  //================
  // RECO Cut on PF MT
  //================

  RECOpfMTCut::RECOpfMTCut(float cut) :
    mCut(cut) {}

  RECOpfMTCut::~RECOpfMTCut() {}

  bool RECOpfMTCut::Process(Event::Data & ev) {

    if(ev.LD_CommonMuons().accepted.size() == 1) {
      double MT = sqrt(2.0 * ev.PFMET().Pt() * ev.LD_CommonMuons().accepted.at(0)->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonMuons().accepted.at(0), ev.PFMET()))));
      if(MT > mCut) return true;
    } else if(ev.LD_CommonElectrons().accepted.size() == 1) {
      double MT = sqrt(2.0 * ev.PFMET().Pt() * ev.LD_CommonElectrons().accepted.at(0)->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonElectrons().accepted.at(0), ev.PFMET()))));
      if(MT > mCut) return true;
    }
    
    return false;
  }

  std::ostream& RECOpfMTCut::Description(std::ostream &ostrm) {
    ostrm << "RECO pfMT Cut > " << mCut << "GeV";
    return ostrm;
  }

} //~namespace Operation
