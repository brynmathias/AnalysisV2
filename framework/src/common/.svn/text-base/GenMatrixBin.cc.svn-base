#include "GenMatrixBin.hh"
#include <iostream>
#include <fstream>
#include <TString.h>
#include "TPRegexp.h"

//default constructor
GenMatrixBin::GenMatrixBin() {}

GenMatrixBin::GenMatrixBin(Event::Data* ev) {
  int i = 0;
  //  cout << endl<<" new Event"<<endl;
  for (std::vector<Event::GenObject>::const_iterator j = ev->GenParticles().begin();  j != ev->GenParticles().end(); ++j) {

    if (j->GetStatus()!=3) continue;
    if(fabs((*j).GetID())==6||fabs((*j).GetID())==8) the_GenTop.push_back(&(*j));
    if(fabs((*j).GetID())==24) the_GenW.push_back(&(*j)) ;
    if(fabs((*j).GetID())==23) the_GenZ.push_back(&(*j)) ;


    if(!hasDaughter(ev,i)) { // only particles without daughters in status 3 are regarded
      if(idSelecHad(&(*j),30,15)) {the_GenJets.push_back(&(*j));} //   cout << "hadron with no mother"<<endl;}
      if(idSelecMuon(&(*j),0,15))  the_GenMuon.push_back(&(*j)); //cout << "muon with no mother"<<endl;
      if(idSelecMuonNu(&(*j),0,15))the_GenMuonNu.push_back(&(*j));
      if(idSelecTau(&(*j),0,15))   the_GenTau.push_back(&(*j)); //cout << "Tau with no mother"<<endl;
      if(idSelecTauNu(&(*j),0,15)) the_GenTauNu.push_back(&(*j)); //cout << "Tau with no mother"<<endl;
      if(idSelecEli(&(*j),0,15))   the_GenEli.push_back(&(*j)); //cout << "Eli with no mother"<<endl;
      if(idSelecEliNu(&(*j),0,15)) the_GenEliNu.push_back(&(*j)); //cout << "Eli with no mother"<<endl;
      if(idSelecPhot(&(*j),30,15)) the_GenPhot.push_back(&(*j)); //cout << "Photon with no mother"<<endl;

      if(idSelecMuon(&(*j),0,15)) the_GenMuonExtra.push_back(&(*j));
      if(idSelecEli(&(*j),0,15))  the_GenElectronExtra.push_back(&(*j)); //cout << "Eli with no mother"<<endl;


    }
    i++;
  }

  nTauMuon=0;
  nTauEli=0;
  nTauHad=0;

  if(the_GenTau.size()>0)
  {
      // if (aGenLepN==0) cout << "GenMatrixBin:: not even a tau??"<<endl;
      for(std::vector<Event::GenObject>::const_iterator j =
              ev->GenParticles().begin();  j != ev->GenParticles().end(); ++j)
      {
	//	cout << j->GetStatus() << " id "<< j->GetID() <<" "<<j->GetMother()<<endl;
        if(j->GetStatus()!=3 &&
           (fabs(j->GetID())==11 || fabs(j->GetID())==13 ))
        {
          //if(fabs(ev->genLepMother()[j])==15&&fabs(ev->genLepId()[j])==11)
          if( (fabs(j->GetMotherID()) == 15) && fabs(j->GetID()) == 11)
          {
            nTauEli++;
	    if(j->Pt() > 0.0 && fabs(j->Eta()) < 15) the_GenElectronExtra.push_back(&(*j));	
            continue;//no point checking next if statement...
          }


          //if(fabs(ev->genLepMother()[j])==15&&fabs(ev->genLepId()[j])==13)
          if(fabs(j->GetMotherID()) == 15 && fabs(j->GetID()) == 13)
          {
            if(j->Pt() > 0.0 && fabs(j->Eta()) < 15) the_GenMuonExtra.push_back(&(*j));
            nTauMuon++;
            continue;
          }

        }

        nTauHad=the_GenTau.size()-nTauEli-nTauMuon;
        //  if(nTauHad<0) cout << "GenMatrixBin:: more tau to leptons found then there are taus: IMPOSSIBLE "<<endl;
	}
  }
  // cout << "Phi "<<j->Phi()<<endl;
  // cout << "Status "<<j->GetStatus()<<endl;
  // cout<< endl;
  //  ev->PrintGen();
}

void GenMatrixBin::PrintStableVis()
{
  cout << " List of stable visible generator Status 3 particles:"<<endl;
  cout << "Jets:" <<endl;
  for (std::vector<Event::GenObject const *>::const_iterator iph = the_GenJets.begin(); iph != the_GenJets.end(); ++iph) {
    cout << "Pt: " << (*iph)->Pt()<< " Phi: "<<  (*iph)->Phi()<< " Eta: "<<  (*iph)->Eta()<<endl;
  }
  if(the_GenMuon.size()>0) cout << "Muons:" <<endl;
  for (std::vector<Event::GenObject const *>::const_iterator iph = the_GenMuon.begin(); iph != the_GenMuon.end(); ++iph) {
    cout << "Pt: " << (*iph)->Pt()<< " Phi: "<<  (*iph)->Phi()<< " Eta: "<<  (*iph)->Eta()<<endl;
  }
  if(the_GenEli.size()>0) cout << "Elis:" <<endl;
  for (std::vector<Event::GenObject const *>::const_iterator iph = the_GenEli.begin(); iph != the_GenEli.end(); ++iph) {
    cout << "Pt: " << (*iph)->Pt()<< " Phi: "<<  (*iph)->Phi()<< " Eta: "<<  (*iph)->Eta()<<endl;
  }
 if(the_GenTau.size()>0) cout << "Taus:" <<endl;
  for (std::vector<Event::GenObject const *>::const_iterator iph = the_GenTau.begin(); iph != the_GenTau.end(); ++iph) {
    cout << "Pt: " << (*iph)->Pt()<< " Phi: "<<  (*iph)->Phi()<< " Eta: "<<  (*iph)->Eta()<<endl;
  }
 if(the_GenPhot.size()>0) cout << "Photons:" <<endl;
  for (std::vector<Event::GenObject const *>::const_iterator iph = the_GenPhot.begin(); iph != the_GenPhot.end(); ++iph) {
    cout << "Pt: " << (*iph)->Pt()<< " Phi: "<<  (*iph)->Phi()<< " Eta: "<<  (*iph)->Eta()<<endl;
  }

  cout << "tau mu " << nTauMuon << " tau eli "<< nTauEli << endl;

}

bool GenMatrixBin::idSelecHad(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())>0&&fabs(gen->GetID())<9) return true; // a quark
  if(fabs(gen->GetID())==21) return true; // a gluon
  return false;
}

bool GenMatrixBin::idSelecPhot(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==22) return true; // a photon
  return false;
}


bool GenMatrixBin::idSelecMuonNu(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==14) return true; // a muon neutrino
  return false;
}


bool GenMatrixBin::idSelecMuon(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==13) return true; // a muon
  return false;
}

bool GenMatrixBin::idSelecEli(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==11) return true; // an electron
  return false;
}

bool GenMatrixBin::idSelecEliNu(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==12) return true; // an electron neutrino
  return false;
}

bool GenMatrixBin::idSelecTau(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==15) return true; // a tau
  return false;
}

bool GenMatrixBin::idSelecTauNu(Event::GenObject const * gen, float et, float eta)
{
  if( gen->Pt()<et || fabs(gen->Eta()) > eta ) return false;
  if(fabs(gen->GetID())==16) return true; // a muon neutrino
  return false;
}

bool GenMatrixBin::hasDaughter(Event::Data * ev,int index)
{
  for (std::vector<Event::GenObject>::const_iterator j = ev->GenParticles().begin();  j != ev->GenParticles().end(); ++j) {
    if(j->GetStatus()!=3) continue;
    if(j->GetMother()!=-1){
      //cout << " test "<<ev->GenParticles[j->GetMother()]<< " "<<index <<  endl;
      if(j->GetMother()==index) return true;
    }
  }
  return false;
}
