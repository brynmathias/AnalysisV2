/*
Based on UserCode/Futyan/macros/WenuTemplateFit.cc
This code uses GetElectronSCCharge(i) and GetElectronKFCharge(i) which require version 3 ntuples or greater.
See WCharge/scripts/genTemplates.py for an example of how to run the code.
*/

#include "HadronicRecoil.hh"
#include "KinSuite.hh"
#include <fstream>
#include "ChAsymTemplateHistos.hh"
#include "TLorentzVector.h"
#include "Math/GenVector/LorentzVector.h"
#include "TMath.h"

using namespace std;
using namespace Event;
using namespace ROOT::Math;

HadronicRecoil::HadronicRecoil(const std::string & folderName,
Utils::ParameterSet &pset
):
mFolderName(folderName)
{
	elecET     = pset.Get<double>("ElecET");
	chChk      = pset.Get<bool>("ChCheck");
	corrEE     = pset.Get<bool>("CorrEEMisalig");
	lepPtVeto  = pset.Get<double>("ElePtVeto");
	convChk    = pset.Get<bool>("ConvCheck");
	lepVeto    = pset.Get<bool>("EleVeto");	
	wp         = pset.Get<int>("WorkingPoint");
	dataset    = pset.Get<bool>("DataSet");//True= W, False= Z
	datatype   = pset.Get<bool>("DataType");//  True= Data, False= Monte Carlo
//(0=95%,1=90%,2=85%,3=80%,4=70%,5=60%)
	ieff=-1;
	if (wp==95) ieff=0;
	if (wp==90) ieff=1;
	if (wp==85) ieff=2;
	if (wp==80) ieff=3;
	if (wp==70) ieff=4;
	if (wp==60) ieff=5;
	if (ieff<0){
	  
	  cout<<"Working point "<<wp<<" unknown"<<endl
	      <<"Working points accepted are 60,70,80,85,90,95"<<endl
	      <<"Job is going to stop"<<endl;
	  assert(0);
	} 
        mMissingHits=1;
        mDCot=0.02;
        mDist=0.02;
	cout << " ========> Analyzing " ;
	if ( dataset == 1 ) {
	  cout << "W to e nu ";
	} else {
	  cout << "Z to e e ";
	}
	if (datatype ==1 ) {
	  cout << "from LHC collisions" << endl;
	} else {
	  cout << "from MC simulation" << endl;
	}
}

void HadronicRecoil::Start(Event::Data & ev) {
	initDir(ev.OutputFile(), mFolderName.c_str());
	BookHistos();
	itr=0;
	ipll=0;
	ievt=0;
}
HadronicRecoil::~HadronicRecoil() {

}

/*
~~~BOOK HISTOS~~~
*/
void  HadronicRecoil::BookHistos() {
   hEleN = new TH1D ("hEleN", "number of electrons", 100, 0, 100);

   hMass = new TH1D ("hMass", "hMass", 200, 25, 125);
   hPt   = new TH1D ("hPt  ", "Reco Boson Pt  ", 100, 0, 100);
   hMCPt = new TH1D ("hMCPt  ", "Gen Boson Pt  ", 100, 0, 100);

   hMET  = new TH1D ("hMET ", "hMET ", 100, 0, 100);
   hMETTr  = new TH1D ("hMETTr", "Transverse MET", 100, -50, 50);
   hMETPl  = new TH1D ("hMETPl ", "Parallel MET" , 100, -50, 50);
   hMCMETTr = new TH1D ("hMCMETTr", "MC Transverse MET", 100, -50, 50);
   hMCMETPll = new TH1D ("hMCMETPll", "MC Parallel MET", 100, -50, 50);

   hMETx = new TH1D ("hMETx", "hMETx", 100, -50,50);
   hMETy = new TH1D ("hMETy", "hMETy", 100, -50,50);

   hMETvsPt = new TH2D ("hMETvsPt", "MET vs Boson p_{T}", 100, 0, 100, 100, 0, 100);
   hMETTrvsPt = new TH2D ("hMETTrvsPt", "Transverse MET vs Boson p_{T}", 100, 0, 100, 100, -50, 50);
   hMETPlvsPt = new TH2D ("hMETPlvsPt", "Parallel MET vs Boson p_{T}", 100, 0, 100, 100, -50, 50);
   hMCMETvsPt = new TH2D ("hMCMETvsPt", "MET vs Gen Boson p_{T}", 100, 0, 100, 100, 0, 100);
   hMCMETTrvsPt = new TH2D ("hMCMETTrvsPt", "Transverse MET vs Gen Boson p_{T}", 100, 0, 100, 100, -50, 50);
   hMCMETPlvsPt = new TH2D ("hMCMETPlvsPt", "Parallel MET vs Gen Boson p_{T}", 100, 0, 100, 100, -50, 50);

   angleGenReco = new TH1D ("AngleGenReco","AngleGenReco",80, -4, 4); 
   angleGenMet  = new TH1D ("AngleGenMet","AngleGenMet",80, -4, 4); 
   angleRecoMet = new TH1D ("AngleRecoMet","AngleRecoMet",80, -4, 4); 
}
/*
~~~PROCESS~~~
*/
bool HadronicRecoil::Process(Event::Data & ev) {
  pigreco = 3.14159;
  ievt++;
  w=ev.GetEventWeight();

  cout << "event #  "<< ievt<< endl;
 
  //ONLY 1 GOOD ELECTRON && VETO ON THE SECOND 
  int ngoodEle=0;

  std::vector<Lepton const *>::const_iterator goodLep;
  std::vector<Lepton const *> myEle;
 
  std::vector<Event::GenObject > Mj_Electrons;
  std::vector<Event::GenObject > Mj_Neutrinos;
  std::vector<Event::GenObject > Mj_W;
  std::vector<Event::GenObject > Mj_Z;

  TVector2 * myMCBoson2V= new TVector2();

  if (datatype == 0){
    for (std::vector<Event::GenObject>::const_iterator  j = ev.GenParticles().begin();
	 j != ev.GenParticles().end();
       ++j) {                                          //Loop all Gen particles
      if (j->GetStatus()==3){                           //All stable particles
	int ID = abs(j->GetID());
	switch (ID){
	case 11: //Electron
	  Mj_Electrons.push_back(*j);
	  break;
	case 12: //Neutrino
          Mj_Neutrinos.push_back(*j);
          break;
	case 24: //W Boson
	  Mj_W.push_back(*j);
	  break;
	case 23: //Z Boson
	  Mj_Z.push_back(*j);
	  break;
	}//End Switch
      }//End If
    }//End Gen Loop
    if (dataset == 1 && Mj_W.size()==1){
      myMCBoson2V ->Set((Mj_W[0]).Px(),(Mj_W[0]).Py());

    }
    if (dataset == 0 && Mj_Z.size()==1){
      myMCBoson2V -> Set((Mj_Z[0]).Px(),(Mj_Z[0]).Py());

    }
  }
  
  for (std::vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
       lep != ev.LD_CommonElectrons().accepted.end();
       ++lep) {
    
    int i = (*lep)->GetIndex();	

   
    bool chargeOk=(chChk) ? (((*lep)->GetCharge()==ev.GetElectronSCCharge(i)) && ((*lep)->GetCharge()==ev.GetElectronKFCharge(i))) : true;
    bool convOk= (convChk) ? ((ev.GetElectronGsfTrackTrackerExpectedHitsInner(i) <= mMissingHits) &&
                (fabs(ev.GetElectronDCot(i)) > mDCot || fabs(ev.GetElectronDist(i)) > mDist)) : true;
   
    
    if (!fid((*lep)->Eta())) continue;

    
    bool iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(),
			     (*lep)->GetEcalIsolation()/(*lep)->Pt(),
			     (*lep)->GetHcalIsolation()/(*lep)->Pt(),(*lep)->Eta(),ieff);
    bool id = passID(ev.GetElectronSigmaIetaIeta(i),
		     ev.GetElectronDeltaPhiAtVtx(i),
		     ev.GetElectronDeltaEtaAtVtx(i), 
		     ev.GetElectronHoE(i),(*lep)->Eta(),ieff);
    if (iso && id && chargeOk && convOk){
      if ((*lep)->Et()>elecET){
	ngoodEle++;
	goodLep=lep;
// 	cout << (*lep)->Et()<< " electron number " << ngoodEle<< endl; 
	myEle.push_back(*lep);
    }

    } 
    
  }

  hEleN->Fill(myEle.size());

  double event_pfMET= ev.PFMET().Et();

  TLorentzVector * myBoson = new TLorentzVector();
  Lepton const * ele1=0;
  Lepton const * ele2=0;
  TVector2 * myME2V = new TVector2();
  TVector2 * myBoson2V = new TVector2();
  double BosonPx=0;
  double BosonPy= 0;
  double BosonPz= 0;
  double BosonE = 0;

  if (dataset==0){ 
    if (myEle.size() < 2 ) return false;
    double oldmass=0;
    for (unsigned int iEle= 0; iEle< myEle.size(); iEle++){
      for (unsigned int jEle= iEle+1; jEle< myEle.size(); jEle++){
//  	cout << myEle[iEle]-> GetCharge() << " " << myEle[jEle]-> GetCharge()<< endl;
	if (myEle[iEle]->GetCharge()*myEle[jEle]->GetCharge()>0) continue;
	BosonPx= myEle[iEle]->Px()+ myEle[jEle]->Px();
	BosonPy= myEle[iEle]->Py()+ myEle[jEle]->Py();
	BosonPz= myEle[iEle]->Pz()+ myEle[jEle]->Pz();
	BosonE = myEle[iEle]->E() + myEle[jEle]->E();
	TLorentzVector *myZ = new  TLorentzVector(BosonPx,BosonPy,BosonPz,BosonE);
	double mass =  myZ->M();
	if (abs(mass-91.1876)<abs(oldmass-91.1876)) {
	  ele1=myEle[iEle];
	  ele2=myEle[jEle];
	}
      }
    }
    if (ele1 ==0 || ele2==0) return false; 
    BosonPx= ele1->Px()+ ele2->Px();
    BosonPy= ele1->Py()+ ele2->Py();
    BosonPz= ele1->Pz()+ ele2->Pz();
    BosonE = ele1->E() + ele2->E();
    double MEx = ev.PFMET().Px();
    double MEy = ev.PFMET().Py();
    myME2V->Set(MEx,MEy);

  }
  
  if (dataset==1){
    if (myEle.size() !=1 ) {
//       cout << " Ele size " << myEle.size() << endl;
      return false;
    }
    BosonPx= myEle[0]->Px()+ev.PFMET().Px();
    BosonPy= myEle[0]->Py()+ev.PFMET().Py();
    BosonPz= myEle[0]->Pz()+ev.PFMET().Pz();
    BosonE = myEle[0]->E() +ev.PFMET().E();

    // TLorentzVector  ele1(myEle[0]->Px(),myEle[0]->Py(),myEle[0]->Pz(),myEle[0]->E());
    // TLorentzVector  evMet= *(TLorentzVector *)&ev.PFMET();
    // myBoson = & (ele1 + evMet);
    // BosonPx= myBoson->Px();
    // BosonPy= myBoson->Py();

    if ( Mj_Neutrinos.size()!=1 ){
//       cout << Mj_Neutrinos.size() <<" nu! " << endl;
      return false;
    }
//     TLorentzVector * myMEnless = new TLorentzVector();
    double MENuPx= -Mj_Neutrinos[0].Px()+ ev.PFMET().Px();
    double MENuPy= -Mj_Neutrinos[0].Py()+ ev.PFMET().Py();
    double MENuPz= -Mj_Neutrinos[0].Pz()+ ev.PFMET().Pz();
    double MENuE = -Mj_Neutrinos[0].E() + ev.PFMET().E();
//     myMEnless->SetPxPyPzE(MENuPx,MENuPy,MENuPz,MENuE);
    myME2V->Set(MENuPx,MENuPy);

  }

  myBoson->SetPxPyPzE(BosonPx,BosonPy,BosonPz,BosonE);
  myBoson2V ->Set(BosonPx,BosonPy);

  double diEleMass = (myBoson->M());
  hMass -> Fill (diEleMass);
  hPt   -> Fill (myBoson->Pt());

  if (diEleMass< 60. || diEleMass >120. ) return false;  
  hMET  -> Fill (myME2V->Mod());    
  hMETx -> Fill(myME2V->Px());
  hMETy -> Fill(myME2V->Py());


//   double METTr  = (myME2V->Norm(*myBoson2V)).Mod();
//   double METPll = (myME2V->Proj(*myBoson2V)).Mod();

  double angle = myME2V->DeltaPhi(*myBoson2V);
  double METTr = myME2V->Mod()*sin(angle);
  double METPll = myME2V->Mod()*cos(angle);

  angleRecoMet -> Fill ((myBoson2V)->DeltaPhi(*myME2V));

  if (datatype == 0){
    angleGenReco -> Fill ((myBoson2V)->DeltaPhi(*myMCBoson2V));
    angleGenMet -> Fill ((myMCBoson2V)->DeltaPhi(*myME2V));
    angle = myME2V->DeltaPhi(*myMCBoson2V);
    double MCMETTr = myME2V->Mod()*sin(angle);
    double MCMETPll = myME2V->Mod()*cos(angle);
//     cout << " Filling MC histo" << endl;
    hMCMETTr ->Fill(MCMETTr);
    hMCMETPll ->Fill(MCMETPll);
    hMCMETvsPt ->Fill(myMCBoson2V->Mod(),myME2V->Mod());
    hMCMETTrvsPt ->Fill(myMCBoson2V->Mod(),MCMETTr);
    hMCMETPlvsPt ->Fill(myMCBoson2V->Mod(),MCMETPll);
    hMCPt   -> Fill(myMCBoson2V->Mod());
  }

  if (abs(METTr)< 1 && itr < 20){
    cout << "Transverse MET " << METTr << endl;
    itr ++;
  }
  
  if (abs(METPll)< 1 && ipll < 20){
    cout << "Parallel MET " << METPll << endl;
    ipll ++;
  }


  hMETTr ->Fill (METTr);
  hMETPl ->Fill (METPll);
  
  hMETvsPt->Fill(myBoson->Pt(), myME2V->Mod());
  hMETTrvsPt ->Fill (myBoson->Pt(), METTr);
  hMETPlvsPt ->Fill (myBoson->Pt(), METPll);
  
  
  

 
  
  return false;
} // end of Process method

std::ostream& HadronicRecoil::Description(std::ostream &ostrm) {
  ostrm << "HadronicRecoil plots made here: (histograms in ";
  ostrm << mFolderName << ")";
  return ostrm;
}

bool HadronicRecoil::passIsolation (double track, double ecal, double hcal, double eta, int ieff)
{
  
  return CheckCuts(track, ecal, hcal, 0., 0., 0., 0.,  eta, ieff );
  
}

bool HadronicRecoil::passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff)
{
  
  return CheckCuts(0., 0., 0., sihih, dfi, dhi, hoe,  eta, ieff );

}


bool HadronicRecoil::fid(double eta) {
  return  (fabs(eta)<2.4 && (  fabs(eta) < 1.4442  || fabs(eta) > 1.56 ));
}

bool HadronicRecoil::CheckCuts(double v_trk, double v_ecal, double v_hcal, 
				     double v_sihih, double v_dfi, double v_dhi, double v_hoe,
				     double eta, int ieff)
{
  
  
  if (fabs(eta)< 1.479) {	  
    if ( v_trk  <  Trk[ieff]    && 
	 v_ecal <  Ecal[ieff]   &&
	 v_hcal <  Hcal[ieff]   &&
	 v_sihih < sihih[ieff]  &&
	 fabs(v_dfi) < Dphi[ieff]   &&
	 fabs(v_dhi) < Deta[ieff]   &&
	 fabs(v_hoe)< HoE[ieff]    
	 ) return true;
  }
  else {

    if ( v_trk <  Trk_ee[ieff]    && 
	 v_ecal < Ecal_ee[ieff]   &&
	 v_hcal < Hcal_ee[ieff]   &&
	 v_sihih <sihih_ee[ieff]  &&
	 fabs(v_dfi) <Dphi_ee[ieff]   &&
	 //MICHELE DA SCOMMENTARE   
	 //	fabs(v_dhi) <Deta_ee[ieff]     &&
	 fabs(v_hoe)< HoE_ee[ieff] 
	 ) return true;

  }
  return false;
}
