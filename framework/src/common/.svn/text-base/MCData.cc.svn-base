/*! \file MCData.cc
 * \brief Source code for the EventStuff::MCData event data container.
 */

#include "MCData.hh"

#include <algorithm>
#include "KinSuite.hh"
#include "EventData.hh"
#include "GenObject.hh"

namespace Compute {
  namespace MC {

    // MC lepton criteria
    static const Double_t mMCLepPtCut = 2.;
    static const Double_t mMCLepEtaCut = 2.4;

    // MC parton criteria
    static const Double_t mMCPartonPtCut = 30.;
    static const Double_t mMCPartonEtaCut = 5.;

    //////////////////////////////////
    // Help functions
    //////////////////////////////////
    void PrintParticle(const Event::GenObject & p) {
      std::cout << " index: " << p.GetIndex();
      std::cout << " Id: " << p.GetID();
      std::cout << " Mother: " << p.GetMother();
      std::cout << " MotherID: " << p.GetMotherID();
      std::cout << " Et "<< p.Et();
      std::cout << " Pt " << p.Pt();
      std::cout << " Eta "<< p.Eta();
      std::cout << " Phi "<< p.Phi();
      std::cout << " Status " << p.GetStatus();
      std::cout << std::endl;
    } // end of PrintParticle method

    void PrintGen(const Event::Data & ev) {
      std::cout << std::endl;
      std::cout << "+++++++++++++++++  MC Info +++++++++++++++++++++++" << std::endl;
      for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();
	   j != ev.GenParticles().end();
	   ++j) {
	if (j->GetStatus()==100) continue;
	PrintParticle(*j);
      }
    } // end of MCData::PrintGen method

    void PrintEndChain(const Event::Data & ev) {
      std::cout << "+++++++++++++++++  MC End Chain Info +++++++++++++++++++++++" << std::endl;
      for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();
	   j != ev.GenParticles().end();
	   ++j) {
	Bool_t motherfound = false;
	for (std::vector<Event::GenObject>::const_iterator k = ev.GenParticles().begin();
	     k != ev.GenParticles().end();
	     ++k) {
	  if (j->GetIndex() == k->GetMother()) motherfound = true;
	} // end of loop through potential mothers
	if (!motherfound) PrintParticle(*j);
      } // end of loop through all gen particles.
      std::cout << std::endl;
    }

    void PrintChain(const Event::Data & ev) {
      std::cout << "+++++++++  MC Chain Info: PDG_ID(index) +++++++++++++++++++++++" << std::endl;
      for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();
	   j != ev.GenParticles().end();
	   ++j) {
	Bool_t motherfound = false;
	for (std::vector<Event::GenObject>::const_iterator k = ev.GenParticles().begin();
	     k != ev.GenParticles().end();
	     ++k) {
	  if (j->GetIndex() == k->GetMother()) motherfound = true;
	} // end of loop through potential mothers
	if (!motherfound) {
	  //PrintParticle(*j);
	  //Int_t endindex = j->GetIndex();
	  Int_t nextmother = j->GetMother();
	  std::cout << "Chain: " << j->GetID() << "(" << j->GetIndex() << ") ";
	  Bool_t beginreached = false;
	  while (!beginreached) {
	    for (std::vector<Event::GenObject>::const_iterator l = ev.GenParticles().begin();
		 l != ev.GenParticles().end();
		 ++l) {
	      if (l->GetIndex() == nextmother) {
		std::cout << " <= " << l->GetID() << "(" << l->GetIndex() << ") ";
		nextmother = l->GetMother();
	      }
	      if (nextmother == -1) beginreached = true;
	    }
	  }
	  std::cout << std::endl;
	}
      } // end of loop through all gen particles.
      std::cout << std::endl;
    }

  void PrintGenLeptons(const Event::Data & ev) {
    std::cout << "Print Gen Leptons array" << std::endl;
    for(std::vector<const Event::GenObject*>::const_iterator j = ev.MC_GenLeptons().begin();
        j != ev.MC_GenLeptons().end();
        ++j) {
      PrintParticle(**j);
    }
  }

  // Loukas - create GenLeptons container
  GenLeptons::GenLeptons(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, GenLeptons>(ev),
      mElEtCut(Utils::GetConfig<double>("Gen.Electrons.PtCut")),
      mElEtaCut(Utils::GetConfig<double>("Gen.Electrons.EtaCut")),
      mMuEtCut(Utils::GetConfig<double>("Gen.Muons.PtCut")),
      mMuEtaCut(Utils::GetConfig<double>("Gen.Muons.EtaCut"))
    {}

  void GenLeptons::_Update() const {
    mData.clear();
#ifdef _ICF_
    {
      // Fill the GenLepton container
      for (std::vector<Event::GenObject>::const_iterator iGenPar = mEv.GenParticles().begin();
           iGenPar != mEv.GenParticles().end(); ++iGenPar) {

        int pid = abs((*iGenPar).GetID());

        if (pid==11){ // electrons
          if ((*iGenPar).Et() > mElEtCut &&
              fabs((*iGenPar).Eta()) < mElEtaCut &&
              (*iGenPar).GetStatus()==1){
                mData.push_back(&*iGenPar);
          }
        }
	else if (pid==13) { // muons
          if ((*iGenPar).Et() > mMuEtCut &&
	      fabs((*iGenPar).Eta()) < mMuEtaCut &&
              (*iGenPar).GetStatus()==1){
		  mData.push_back(&*iGenPar);
          }
        }
      }
    }
#elif defined(_NT7_)
    {
      // Fill the GenLepton container
      for (std::vector<Event::GenObject>::const_iterator iGenPar = mEv.GenLeptons().begin();
           iGenPar != mEv.GenLeptons().end(); ++iGenPar) {

        int pid = abs((*iGenPar).GetID());

        if (pid==11){ // electrons

          if ((*iGenPar).Et() > mElEtCut &&
	      fabs((*iGenPar).Eta()) < mElEtaCut &&
              (*iGenPar).GetStatus()==1) {
		  mData.push_back(&*iGenPar);
          }
        } else if (pid==13) { // muons

	    if ((*iGenPar).Et() > mMuEtCut &&
                fabs((*iGenPar).Eta()) < mMuEtaCut &&
                (*iGenPar).GetStatus()==1) {
		  mData.push_back(&*iGenPar);
	    }
        }
      }
    }
#endif
  }
  //~ added loukas

  /*
    SingleLepMHT::SingleLepMHT(const Event::Data & ev) :
      Compute::Variable<TLorentzVector, SingleLepMHT>(ev) {}

    void SingleLepMHT::_Update() const {
      double gMHX, gMHY, gMHZ;
      gMHX=gMHY=gMHZ=0.;

      for ( std::vector<Event::GenObject const *>::const_iterator i = mEv.MC_ThePartons().begin() ;
	    i != mEv.MC_ThePartons().end();
	    ++i ) {
	gMHX -= (*i)->Px();
	gMHY -= (*i)->Py();
	gMHZ -= (*i)->Pz();
      }

      double theMHTmod=sqrt(gMHX*gMHX + gMHY*gMHY + gMHZ*gMHZ);

      mData.SetPxPyPzE(gMHX, gMHY, gMHZ, theMHTmod);
    }

    SingleLepHT::SingleLepHT(const Event::Data & ev) :
      Compute::Variable<Double_t, SingleLepHT>(ev) {}

    void SingleLepHT::_Update() const {
      mData = 0.;
      for ( std::vector<Event::GenObject const *>::const_iterator i = mEv.MC_ThePartons().begin() ;
	    i != mEv.MC_ThePartons().end();
	    ++i ) {
	mData += (*i)->Pt();
      }
    }

    SingleLepMET::SingleLepMET(const Event::Data & ev) :
      Compute::Variable<TLorentzVector, SingleLepMET>(ev) {}

    void SingleLepMET::_Update() const {
      int iLSP = mEv.MC_TheLSPs().size();

      double gMEX, gMEY, gMEZ;
      gMEX=gMEY=gMEZ=0.;

      for (std::vector<Event::GenObject const *>::const_iterator i = mEv.MC_TheNeutrinos().begin();
	   i != mEv.MC_TheNeutrinos().end();
	   ++i) {
	gMEX += (*i)->Px();
	gMEY += (*i)->Py();
	gMEZ += (*i)->Pz();
      }
      if ( iLSP >= 2 ) {
	gMEX += mEv.MC_TheLSPs()[0]->Px(); gMEY += mEv.MC_TheLSPs()[0]->Py(); gMEZ += mEv.MC_TheLSPs()[0]->Pz();
	gMEX += mEv.MC_TheLSPs()[1]->Px(); gMEY += mEv.MC_TheLSPs()[1]->Py(); gMEZ += mEv.MC_TheLSPs()[1]->Pz();
      }

      double theMod=sqrt(gMEX*gMEX + gMEY*gMEY + gMEZ*gMEZ);
      mData.SetPxPyPzE(gMEX, gMEY, gMEZ, theMod);
    }


    AllLeptons::AllLeptons(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, AllLeptons>(ev) {}

    void AllLeptons::_Update() const {
      mData.clear();
      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {
	int pid = abs((*par).GetID());
	// Leptons (assumning 1-lepton mode in GEN mode
	if (pid==11 || pid==13 || pid==15) {
	  mData.push_back(&*par);
	}
      }
    }
  */
    TheLeptons::TheLeptons(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, TheLeptons>(ev) {}

    void TheLeptons::_Update() const {
      mData.clear();

      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {
	int pid = abs((*par).GetID());
	// Leptons (assumning 1-lepton mode in GEN mode
	if (pid==11 || pid==13 || pid==15) {
	  if ( (par->Pt() > mMCLepPtCut) &&
	       ( fabs(par->Eta()) < mMCLepEtaCut ) ) {
	    mData.push_back(&*par);
	  }
	}
      }
    }

    TheIsolatedLeptons::TheIsolatedLeptons(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, TheIsolatedLeptons>(ev) {}

    void TheIsolatedLeptons::_Update() const {
      mData.clear();
      int ipart=0;
      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {

	int pid = abs((*par).GetID());

	//ISOLATED HADRONIC TAUS
	if (pid==15){
	  int imom = abs(mEv.GenParticles()[par->GetMother()].GetID());
	  //ONLY TAUS FROM SUSY PARTICLES OR HEAVY BOSONS
	  if ((imom>1000000)  || ((imom>22)&&(imom<40))) {

	    //REJECT TAUS DECAYING LEPTONICALLY
	    bool hadTau=true;
	    for (std::vector<Event::GenObject>::const_iterator par2 = mEv.GenParticles().begin();
		 par2 != mEv.GenParticles().end();
		 ++par2) {
	      if (!hadTau) continue;
	      int pid2 = abs((*par2).GetID());
	      int mom2 = abs(mEv.GenParticles()[par2->GetMother()].GetID());
	      if (((pid2==11) || (pid2==13)) && (mom2==15)){
		if (par2->GetMother()==ipart) hadTau=false;
	      }
	    }
	    if (hadTau){
	      //PT AND ETA CUT
	      if ( (par->Pt() > mMCLepPtCut) &&
		   ( fabs(par->Eta()) < mMCLepEtaCut ) ) {


		mData.push_back(&*par);
	      }
	    }
	  }
	} //END TAU

	// ELECTRONS AND LEPTONS
	if (pid==11 || pid==13) {
	  int imom = abs(mEv.GenParticles()[par->GetMother()].GetID());
	  //FROM  SUSY PARTICLES OR HEAVY BOSONS
	  if ((imom>1000000)  || ((imom>22)&&(imom<40))) {
	    if ( (par->Pt() > mMCLepPtCut) &&
		 ( fabs(par->Eta()) < mMCLepEtaCut ) ) {
	      mData.push_back(&*par);
	    }
	  }
	  //FROM TAU
	  if (imom==15){
	    //TAU FROM  SUSY PARTICLES OR HEAVY BOSONS
	    int iddd = mEv.GenParticles()[par->GetMother()].GetMother();
	    int igrmom = abs(mEv.GenParticles()[iddd].GetID());
	    if ((igrmom>1000000)  || ((igrmom>22)&&(igrmom<40))) {
	      if ( (par->Pt() > mMCLepPtCut) &&
		   ( fabs(par->Eta()) < mMCLepEtaCut ) ) {
		mData.push_back(&*par);
	      }
	    }
	  }
	  ipart++;
	}//END ELECTRONS AND MUONS
      } //END LOOP ON THE GENPARTICLES

    }

    TheNeutrinos::TheNeutrinos(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, TheNeutrinos>(ev) {}

    void TheNeutrinos::_Update() const {
      mData.clear();
      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {
	int pid = abs((*par).GetID());
	// Neutrinos
	if (pid==12 || pid==14 || pid==16) {
	  mData.push_back(&*par);
	}
      }
    }

    TheLSPs::TheLSPs(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, TheLSPs>(ev) {}

    void TheLSPs::_Update() const {
      mData.clear();
      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {
	int pid = abs((*par).GetID());
	// LSPs
	if (pid==1000022) {
	  mData.push_back(&*par);
	}
      }
    }

    ThePartons::ThePartons(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, ThePartons>(ev) {}

    void ThePartons::_Update() const {
      mData.clear();

      bool hasDaughter = false;
      int index=0;
      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {
	int pid = abs((*par).GetID());

	// Partons
	if ( (pid>0 && pid<6) || pid==21) {

	  hasDaughter=false;

	  // Check if parton has a daughter
	  for (std::vector<Event::GenObject>::const_iterator j = mEv.GenParticles().begin();
	       j != mEv.GenParticles().end();
	       ++j) {
	    if(j->GetStatus()!=3) continue;
	    if(j->GetMother()!=-1){
	      if(j->GetMother()==index) {
		hasDaughter=true;
	      }
	    }
	  }

	  if (!hasDaughter) {

	    if ( (par->Pt() > mMCPartonPtCut)) {
	      //allPartons.push_back(&(*par));
	      if ( fabs(par->Eta()) < mMCPartonEtaCut ) {
		mData.push_back(&*par);
	      }
	    }
	  }
	} // end partons
	index++; // particle counter
      }
      sort(mData.begin(), mData.end(), KinSuite::PCompare);
    }

    AllPartons::AllPartons(const Event::Data & ev) :
      Compute::Variable<std::vector<Event::GenObject const *>, AllPartons>(ev) {}

    void AllPartons::_Update() const {
      mData.clear();

      bool hasDaughter = false;
      int index=0;
      for (std::vector<Event::GenObject>::const_iterator par = mEv.GenParticles().begin();
	   par != mEv.GenParticles().end();
	   ++par) {
	int pid = abs((*par).GetID());

	// Partons
	if ( (pid>0 && pid<6) || pid==21) {

	  hasDaughter=false;

	  // Check if parton has a daughter
	  for (std::vector<Event::GenObject>::const_iterator j = mEv.GenParticles().begin();
	       j != mEv.GenParticles().end(); ++j) {
	    if(j->GetStatus()!=3) continue;
	    if(j->GetMother()!=-1){
	      if(j->GetMother()==index) { hasDaughter=true; }
	    }
	  }

	  if (!hasDaughter) {

	    if ( (par->Pt() > mMCPartonPtCut)) {
	      mData.push_back(&(*par));
	      //if ( fabs(par->Eta()) < mMCPartonEtaCut ) {
	      //thePartons.push_back(&(*par));
	      //}
	    }
	  }
	} // end partons

	index++; // particle counter
      }

      // Sort the partons
      //sort(mData.begin(), mData.end(), compare);
    }


    SSFinalState::SSFinalState(const Event::Data & ev) :
      Compute::Variable<int, SSFinalState>(ev),lep_(ev) {
    }

    void SSFinalState::_Update() const {

      if (lep_().size()!=2) mData=-1;
      else{
	int finalstate=1;
	for (vector<Event::GenObject const *>::const_iterator ig=lep_().begin();
	     ig!=lep_().end();++ig){
	  finalstate*=(*ig)->GetID();
	}


	switch (finalstate) {
	case 121:
	  mData = 0;
	  break;
	case 169:
	  mData = 1;
	  break;
	case 225:
	  mData = 2;
	  break;
	case 143:
	  mData = 3;
	  break;
	case 165:
	  mData = 4;
	  break;
	case 195:
	  mData = 5;
	  break;
	default:
	  mData = -1;
	  break;
	}
      }
    }

    // General gen particle access methods
    //=====================================

  //const std::vector<GenObject> & MCData::GetGenParticles() { return const_cast<std::vector<GenObject> &> (GenParticles); }

    /*

    Bool_t MCData::WasItSusy(UInt_t index) {
        // Check if the vector has been filled yet. If it hasn't, call the filler function.
        if ((was_it_susy_.size()==0) && !(GetGenParticles().size()!=0)) fillWasItSusy();

        // Now we know it's been filled, return the corresponding result.
        if (index < was_it_susy_.size()) return was_it_susy_[index];
        else return false;

    } // end of MCData::WasItSusy method

    void MCData::fillWasItSusy() {
        // Loop over the gen particles in the event
        for (std::vector<GenObject>::const_iterator gp = GetGenParticles().begin(); gp!=GetGenParticles().end(); ++gp) {
            // Do what you gotta do ;-)
            // There are a whole bunch of "your mother" jokes to be made here... I'll leave that to you.
            was_it_susy_.push_back(false); // TEMP - now you have to check the gen particles...
        }
    }
    */

    /*


  //
  // Leptonic MC data helper functions
  //===================================
  bool MCData::IsMCSSDilepton(){
    return (finalState>0);
  }



 int MCData::SSFinalStateTauDecay(){

    //
    if (finalStateTau==121) return 0; //ee
    if (finalStateTau==169) return 1; //mm
    if (finalStateTau==225) return 2; //tt
    if (finalStateTau==143) return 3; //em
    if (finalStateTau==165) return 4; //et
    if (finalStateTau==195) return 5; //mt

    return -1;
  }


    */

  } //~namespace MC
} //~namespace Compute
