#include "lepvalMC.hh"
#include "Utils.hh"

namespace lepval{

  IsolatedLeptons::IsolatedLeptons():
    Compute::User<std::vector<Event::GenObject const *> , IsolatedLeptons>(), mMCLepPtCut(0), mMCLepEtaCut(2.4)
  {
  }

  void IsolatedLeptons::_Update() const{
    mData.clear();

 int ipart=0;

 for (std::vector<Event::GenObject>::const_iterator par = mEv->GenParticles().begin();
      par != mEv->GenParticles().end();
      ++par) {
   
   int pid = abs((*par).GetID());
   
   //ISOLATED HADRONIC TAUS
   if (pid==15){
     int imom = abs(mEv->GenParticles()[par->GetMother()].GetID());
     //ONLY TAUS FROM SUSY PARTICLES OR HEAVY BOSONS
     if ((imom>1000000)  || ((imom>22)&&(imom<40))) {
       
       //REJECT TAUS DECAYING  LEPTONICALLY
       bool hadTau=true;
       for (std::vector<Event::GenObject>::const_iterator par2 = mEv->GenParticles().begin();
	    par2 != mEv->GenParticles().end();
	    ++par2) {
	 if (!hadTau) continue;
	 int pid2 = abs((*par2).GetID());
	 int mom2 = abs(mEv->GenParticles()[par2->GetMother()].GetID());
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
     int imom = abs(mEv->GenParticles()[par->GetMother()].GetID());
     //FROM  SUSY PARTICLES OR HEAVY BOSONS
     if ((imom>1000000)  || ((imom>22)&&(imom<40)) || imom==443) {//443 is J/PSI - this is the modification from the original 'TheIsolatedLeptons'
       //FROM J/PSI
//        if(imom==443){
// 	 int indJPmot = mEv->GenParticles()[par->GetMother()].GetMother();
// 	 int idJPmot = abs(mEv->GenParticles()[indJPmot].GetID());
// 	 int indJPGrandMother = mEv->GenParticles()[indJPmot].GetMother();
// 	 int idJPGrandMother = abs(mEv->GenParticles()[indJPGrandMother].GetID());

	 //	 std::cout<<"lepton "<<pid<<" mother "<<imom<<" grandmother "<<idJPmot<<" greatgrandmom "<<idJPGrandMother<<std::endl;
// 	 int statusJpsi = mEv->GenParticles()[par->GetMother()].GetStatus();

// 	 std::cout<<idJPmot<<" "<<statusJpsi<<std::endl;
//        }
	 
	 if ( (par->Pt() > mMCLepPtCut) &&
	      ( fabs(par->Eta()) < mMCLepEtaCut ) ) {
	   mData.push_back(&*par);//is this a bug in the original? push_back will include leptons from heavyflavour taus at this point
	 }
       }
       //FROM TAU
       if (imom==15){
	 //TAU FROM  SUSY PARTICLES OR HEAVY BOSONS
	 int iddd = mEv->GenParticles()[par->GetMother()].GetMother();
	 int igrmom = abs(mEv->GenParticles()[iddd].GetID());
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

  std::ostream & IsolatedLeptons::Description(std::ostream & ostrm){

    ostrm << "Custom Isolated Leptons Compute" << std::endl;
    return ostrm;
  }
}
  
