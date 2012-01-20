#include "SSDLBkgdCat.hh"
#include <fstream>
#include "KinSuite.hh"
#include "GenMatch.hh"
using namespace Event;
namespace SSDL{

  int classify(int a, int b, bool AA, bool BB){
    if(a==Alex::GenOrigin::Fake && b==Alex::GenOrigin::Fake){
      return 0;//2fakes
    }
    else if (a==Alex::GenOrigin::Fake && b==Alex::GenOrigin::HF){
      return 1;//1fake 1HF
    }
    else if (b==Alex::GenOrigin::Fake && a==Alex::GenOrigin::HF){
      return 10;//1fake 1HF
    }
    else if (a==Alex::GenOrigin::HF && b == Alex::GenOrigin::HF){
      return 11;//2 HF
    }
    else if (a==Alex::GenOrigin::Fake && b==Alex::GenOrigin::Prompt){
      return 2;//1fake, 1 prompt
    }
    else if (b==Alex::GenOrigin::Fake && a==Alex::GenOrigin::Prompt){
      return 20;//1fake, 1 prompt
    }
    else if (a==Alex::GenOrigin::Prompt && b==Alex::GenOrigin::HF) {
      return 21;//1 prompt, 1HF
    }
    else if (b==Alex::GenOrigin::Prompt && a==Alex::GenOrigin::HF){
      return 12;//1 prompt, 1HF
    } 
    else if (a==Alex::GenOrigin::Prompt && b==Alex::GenOrigin::Prompt){
      if (!AA) return 23;
      if (!BB) return 24;
      return 22;//2 prompt and bad charge (charge needs to be checked)
    }
    else{
      return -1;
   }
  }

  // int tau_match(const LorentzV *vec){
  //   float DRmax=0.5;
  //   int iMatch=-1;

    // for(std::vector<Event::GenObject const *>::const_iterator p = MC_TheLeptons().begin(); p !=MC_TheLeptons().end(); p++){
    //   int pID(*par)->GetID(); if ( abs(pID)!=15)


  SSDLBkgdCat::SSDLBkgdCat(double htcut, double mhtcut, const std::string & folderName) :
    _htcut(htcut),
    _mhtcut(mhtcut),
    mFoldername(folderName){}
  SSDLBkgdCat::~SSDLBkgdCat(){}

  void SSDLBkgdCat::Start(Event::Data & ev){
    initDir(ev.OutputFile(), mFoldername.c_str());
    BookHistos();
  }

  void SSDLBkgdCat::BookHistos(){
    //initialise the histos for the bkgd cat. 6 categories (and 1 low bin for unclassified events - should be empty):
    //0 prompt lepts + 2 fakes
    //0 prompt, 1fake, 1 HF
    //0 prompt, 2HF
    //1 prompt, 1 fake
    //1 prompt, 1 HF
    //2 prompt, 1 bad charge
    h_ee = new TH1D("h_ee","h_ee", 26, -1.5,24.5);
    h_mumu = new TH1D("h_mumu","h_mumu", 26, -1.5,24.5);
    h_tautau = new TH1D("h_tautau","h_tautau", 26, -1.5,24.5);
    h_emu = new TH1D("h_emu","h_emu", 26, -1.5,24.5);
    h_etau = new TH1D("h_etau","h_etau", 26, -1.5,24.5);
    h_mutau = new TH1D("h_mutau","h_mutau", 26, -1.5,24.5);
  }


  bool SSDLBkgdCat::Process(Event::Data& ev){
    bool cutpassed;

 
    std::vector<const Lepton *> AllLeptons;

    float HT=ev.CommonHT();
    float MHT=ev.PFMET().Pt();
    double chProd=0.;
    double w = ev.GetEventWeight();


for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }
    
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
   	lep!=ev.LD_CommonTaus().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }

    sort((AllLeptons).begin(),(AllLeptons).end(), KinSuite::PCompare);

    int REC_STATE=-1;
    if (AllLeptons.size()>1){
      chProd=(AllLeptons[0]->GetCharge()*AllLeptons[1]->GetCharge());
      
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
    }

    cutpassed=(HT>_htcut && MHT>_mhtcut && AllLeptons.size()>1 && chProd>0);//fix the min lepton number and charge req...for time being

    if (cutpassed){
     const Lepton *firstlep = AllLeptons[0];
     const Lepton *seclep = AllLeptons[1];
     //     int type1 = -1;
     //     int type2 = -1;
     int bkgdtype = -1; //0==2fake, 1==1fake/1HF, 2==1prompt/1fake, 3==2HF, 4==1prompt/1HF, 5==2prompt/bad charge 


     
    //  if (firstlep->GetType()!=3){
    //    int match1 = ev.Data::leptonMatch(firstlep, firstlep->GetType());
    //    int type1 = ev.Data::leptonType(match1);
    // }

    //  if (seclep->GetType()!=3){
    //    int match2 = ev.Data::leptonMatch(seclep, seclep->GetType());
    //    int type2 = ev.Data::leptonType(match2);
    //  }
     
     Alex::LeptonMatch match1(ev);
     Alex::LeptonMatch match2(ev);
  
     pair<Alex::GenMatchedLepton, bool> m1 = match1(firstlep);
     pair<Alex::GenMatchedLepton, bool> m2 = match2(seclep);
     if (AllLeptons[0]->GetType()>AllLeptons[1]->GetType())
       bkgdtype = classify(m1.first.Source(), m2.first.Source(), m1.second, m2.second);
     else bkgdtype = classify(m2.first.Source(), m1.first.Source(), m1.second, m2.second);
     //bkgdtype = classify(m1.Source(), 1);


     switch (REC_STATE){
     case 0:
       h_ee->Fill(bkgdtype,w);
       break;
     case 1:
       h_mumu->Fill(bkgdtype,w);
       break;
     case 2:
       h_tautau->Fill(bkgdtype,w);
       break;
     case 3:
       h_emu->Fill(bkgdtype,w);
       break;
     case 4:
       h_etau->Fill(bkgdtype,w);
       break;
     case 5:
       h_mutau->Fill(bkgdtype,w);
       break;
     }
     
    }
    return cutpassed;
  }
  
  std::ostream& SSDLBkgdCat::Description(std::ostream& ostrm){
    ostrm<<"SSDL background categorisations"<<std::endl;
    return ostrm;
  }
} 
