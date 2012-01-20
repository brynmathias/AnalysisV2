#include "TauBkgEval.hh"
#include "SSDLBkgdCat.hh"
#include "KinSuite.hh"
#include "GenMatch.hh"
using namespace Event;

namespace SSDL {

  TauBkgEval::TauBkgEval(const std::string & folderName):
    mFolderName(folderName)
  {

  } // end of TTBkgEval constructor.

  void TauBkgEval::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }  
  
  TauBkgEval::~TauBkgEval() {
  } // end of TTBkgEval destructor.
  
  bool TauBkgEval::Process(Event::Data & ev) {
    

    std::vector<Event::GenObject>::const_iterator ggb	= ev.GenParticles().begin();
    std::vector<Event::GenObject>::const_iterator gge 	= ev.GenParticles().end();

    for (;ggb!=gge;++ggb){
   
      if (abs(ggb->GetID()) !=15) continue;
      if (ggb->GetStatus() != 2) continue;
      if (abs((*ggb).Eta())>2.3) continue;
 
      float ptvis=ggb->Pt();
      h_MCTau_EtaPt->Fill(fabs((*ggb).Eta()),TMath::Min(float(100.),(*ggb).Pt()));
      h_MCTau->Fill(ptvis);
      bool matched=false;
      for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
	  lep!=ev.LD_CommonTaus().accepted.end();++lep){	
	if (matched) continue;
	double dr = ROOT::Math::VectorUtil::DeltaR(**lep, *ggb);
	if (dr<0.1){
	  matched= true;
	  h_matchedTau_EtaPt->Fill(fabs((*ggb).Eta()),TMath::Min(float(100.),(*ggb).Pt()));
	  h_recoTau->Fill(ptvis);
	}
      }
    }
    
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
 	lep!=ev.LD_CommonTaus().accepted.end();++lep){	
      std::vector<Event::GenObject>::const_iterator gb	= ev.GenParticles().begin();
      std::vector<Event::GenObject>::const_iterator ge 	= ev.GenParticles().end();
      bool matched=false;
      int MCCharge=0;
      //      cout<<"EVENTO "<<ev.EventNumber()<<" RUN "<<ev.RunNumber()<<endl;
      //      cout<<"TAU "<<(*ggb).Eta()<<" "<<(*ggb).Pt()<<endl;
      for (;gb!=ge;++gb){
	if (abs(gb->GetID()) !=15) continue;
	if (gb->GetStatus() != 2) continue;
	if (matched) continue;
       
	double dr = ROOT::Math::VectorUtil::DeltaR(**lep, *gb);

	if (dr<0.5){
	  matched= true;
	  MCCharge=int(gb->GetID()/-15.);
	  //	  cout<<"CHARGE"<<endl;
	}
	//	cout<<"DDDD R "<<dr<<" "<<gb->GetID()<<" "<<(*lep)->GetCharge()<<endl;
      }
      if (matched){
	//	cout<<"SS"<<endl;
	h_Tau_EtaPt->Fill(fabs((*lep)->Eta()),TMath::Min(float(100.),(*lep)->Pt()));	
	if (MCCharge*(*lep)->GetCharge()<0)  h_WCTau_EtaPt->Fill(fabs((*lep)->Eta()),TMath::Min(float(100.),(*lep)->Pt()));
      }
    }


    return true;
  }
  void  TauBkgEval::BookHistos(){
    h_Tau_EtaPt = new TH2D("h_Tau_EtaPt","h_Tau_EtaPt",10,0.,2.5,20,0.,100.); 
    h_WCTau_EtaPt = new TH2D("h_WCTau_EtaPt","h_WCTau_EtaPt",10,0.,2.5,20,0.,100.); 
    h_MCTau_EtaPt = new TH2D("h_MCTau_EtaPt","h_MCTau_EtaPt",10,0.,2.5,20,0.,100.);   
    h_matchedTau_EtaPt = new TH2D("h_matchedTau_EtaPt","h_matchedTau_EtaPt",10,0.,2.5,20,0.,100.);  
    h_MCTau = new TH1D("h_MCTau","h_MCTau",50,0,100.);
    h_recoTau = new TH1D("h_recoTau","h_recoTau",50,0,100.);
  }
  std::ostream& TauBkgEval::Description(std::ostream &ostrm) {
    ostrm << "TauBkgEval plots made here: (histograms in ";
    ostrm <<  mFolderName << ")";
    return ostrm;
  }

}
