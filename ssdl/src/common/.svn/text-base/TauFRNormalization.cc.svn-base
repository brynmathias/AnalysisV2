#include "TauFRNormalization.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
#include "Utils.hh"


#include <fstream>
using namespace Event;
namespace SSDL {
  bool compareLEPPt(const Lepton *l1, const Lepton* l2) {
    return l1->Pt() > l2->Pt();
  }
  TauFRNormalization::TauFRNormalization(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName),
    tauSrc(pset.Get<string>("TauSource"))
  {
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
    looseIso_=pset.Get<int>("LooseIsolation");
    uppermetcut_=pset.Get<double>("UpperMetCut");
    mUseHps=pset.Get<bool>("UseHps");
  }

  void TauFRNormalization::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }
  TauFRNormalization::~TauFRNormalization() {
    //  tree->Write();
  }
  
  void  TauFRNormalization::BookHistos() {

    hGoodMuFakeTau= new TH2D("hGoodMuFakeTau","hGoodMuFakeTau",10,0.,2.5,20,0.,100.);
    hGoodElFakeTau= new TH2D("hGoodElFakeTau","hGoodElFakeTau",10,0.,2.5,20,0.,100.);
    hGoodTauFakeTau= new TH2D("hGoodTauFakeTau","hGoodTauFakeTau",10,0.,2.5,20,0.,100.);
    hFakeTauFakeTau= new TH1D("hFakeTauFakeTau","hFakeTauFakeTau",625,0,625);
    hAllGoodWrongCharge = new TH1D("hAllGoodWrongCharge","hAllGoodWrongCharge",6,-0.5,5.5);
    tree = new TTree( "theTree", "Detector units positions" );
    tree->Branch("weight",   &weight,      "weight/F"      );
    tree->Branch("eta1"  ,   &eta1,        "eta1/F"      );
    tree->Branch("pt1"   ,   &pt1,         "pt1/F"       );
    tree->Branch("eta2"  ,   &eta2,        "eta2/F"      );
    tree->Branch("pt2"   ,   &pt2,         "pt2/F"       );
  }

  bool TauFRNormalization::Process(Event::Data & ev) {
    float w=ev.GetEventWeight();
    float HT=ev.CommonHT();
    // float MHT=ev.CommonMHT().Pt();
    //try the selection with PFMET - AGB 27/10/10
    float MHT=ev.PFMET().Pt();
    float max_LepPt = 99.;

    //PRIMARY LEPTONS
    std::vector<const Lepton *> AllLeptons;
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
 	lep!=ev.LD_CommonTaus().accepted.end();++lep){      
      AllLeptons.push_back(*lep);
    }
   
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
 	lep!=ev.LD_CommonElectrons().accepted.end();++lep){   
      if (fabs((**lep).Eta())>2.4) continue;
      AllLeptons.push_back(*lep);
    }

    //SECONDARY LEPTONS
    
    std::vector<Lepton > AllSecLeptons;
    for(vector<Lepton>::const_iterator lep=ev.LD_Taus().begin();
	lep!=ev.LD_Taus().end();++lep) {
      
      //use the pt cut of the common Taus rather than hardcoding!
      if (fabs(lep->Pt())<(Utils::GetConfig<double>("Common.Taus.PtCut"))) continue;
      if (fabs(lep->Eta())>(Utils::GetConfig<double>("Common.Taus.EtaCut"))) continue;
      int iM = lep->GetIndex();
      if (!ev.IsTauAgainstElectron(iM)) continue;
      if (!ev.IsTauAgainstMuon(iM)) continue;
      if (fabs(lep->GetCharge())!=1) continue;
      if(tauSrc=="tauHPS"){
	if (!ev.IsTauByDecay(iM)) continue;  

	if ((looseIso_==1)   && (!ev.IsTauByLooseIso(iM))) continue;
	if ((looseIso_==2)   && (!ev.IsTauByMediumIso(iM))) continue;
      }else{
        if (mUseHps){
          //HPS CASE
         float dr=999;
         int iSec=-1;
         for(vector<Lepton>::const_iterator seclep=ev.LD_SecTaus().begin();
            seclep!=ev.LD_SecTaus().end();++seclep) {
           float DRRR=KS_DeltaR(*lep, *seclep);
           if (DRRR>0.2) continue;
            if (DRRR<dr){
               dr=DRRR; 
               iSec=seclep->GetIndex();
 
            }
          }
         if (iSec<0) continue;
         if (!ev.secTauIdAgainstElectron()->at(iSec)) continue;
         if (!ev.secTauIdAgainstMuon()->at(iSec)) continue;
	 if ((looseIso_==1)  && (!ev.secTauIdbyLooseIsolation()->at(iSec)  )) continue;
	 if ((looseIso_==2)  && (!ev.secTauIdbyMediumIsolation()->at(iSec) )) continue;
        } else{
          if ((looseIso_==1)   && (!ev.IsTauNCfr100(iM))) continue;
	  if ((looseIso_==2)   && (!ev.IsTauNCfr050(iM))) continue;
	  if ((looseIso_==3)   && (!ev.IsTauNCfr025(iM))) continue;
        }
      }
      
      if(AllLeptons.size()==0){
	AllSecLeptons.push_back(*lep);
      }
      //NOT PRIMARY LEPTONS
      else  if (AllLeptons.size()==1)
	{
	  vector<Lepton const *>::iterator ll= AllLeptons.begin();	
	  if (KS_DeltaR(*lep, (**ll))<0.05) continue;	  
	  AllSecLeptons.push_back(*lep);
	}
    }
 


    sort((AllLeptons).begin(), (AllLeptons).end(), compareLEPPt);
    if ((HT>htCut)&& MHT>mhtCut && AllLeptons.size()>1){
      int chprod=int(AllLeptons[0]->GetCharge()* AllLeptons[1]->GetCharge());
      if (chprod<0){
	int REC_STATE=-2;
	if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
	if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
	if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
	if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
	if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
	if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
	hAllGoodWrongCharge->Fill(REC_STATE);
      }
    }


    int chProd=-1;
    float InvMassSS=0.;
    int NVertices=ev.GetVertexSize();
    bool VertCompatibility = false;

    if (AllLeptons.size()==0 && AllSecLeptons.size()>=2)
      chProd=int(AllSecLeptons[0].GetCharge()* AllSecLeptons[0].GetCharge());

   if (AllLeptons.size()==1 && AllSecLeptons.size()==1){
      chProd=int(AllLeptons[0]->GetCharge()*AllSecLeptons[0].GetCharge());
      TLorentzVector lep1(AllLeptons[0]->Px(),AllLeptons[0]->Py(),AllLeptons[0]->Pz(),AllLeptons[0]->E());
      TLorentzVector lep2(AllSecLeptons[0].Px(),AllSecLeptons[0].Py(),AllSecLeptons[0].Pz(),AllSecLeptons[0].E());
      InvMassSS=(lep1+lep2).M();
      if (NVertices>0){
        bool GoodVertex=false;
         for (int ivx=0;ivx<NVertices;ivx++){
          if (GoodVertex) continue;
          if(!ev.GetvertexIsFake(ivx) && ev.GetvertexNdof(ivx)>=4 && ev.GetvertexPosition(ivx).Rho()<2. && fabs(ev.GetvertexPosition(ivx).Z())<24.0){
              GoodVertex=true;
   }
if (GoodVertex){
            float lep1Z=0; float lep2Z=0;
            if (AllLeptons[0]->GetType()==3) lep1Z=ev.GetTauVx(AllLeptons[0]->GetIndex()).Z();
            if (AllLeptons[0]->GetType()==2) lep1Z=ev.GetMuonVx(AllLeptons[0]->GetIndex()).Z();
            if (AllLeptons[0]->GetType()==1) lep1Z=ev.GetElectronVx(AllLeptons[0]->GetIndex()).Z();     
            lep2Z=ev.GetTauVx(AllSecLeptons[0].GetIndex()).Z();
          VertCompatibility = (  GoodVertex &&  (fabs(ev.GetvertexPosition(ivx).Z()-lep1Z)<1.0) &&
                               (fabs(ev.GetvertexPosition(ivx).Z()-lep2Z)<1.0));


}
      //VERTEX COMPATIBILITY MUST BE ADDED
     //VERTEX OF LEPTONS IS MISSING
         }
       }
     }

   if (AllLeptons.size()==0 && AllSecLeptons.size()>=2){
    chProd=int(AllSecLeptons[0].GetCharge()* AllSecLeptons[1].GetCharge());
      TLorentzVector lep1(AllSecLeptons[0].Px(),AllSecLeptons[0].Py(),AllSecLeptons[0].Pz(),AllSecLeptons[0].E());
      TLorentzVector lep2(AllSecLeptons[1].Px(),AllSecLeptons[1].Py(),AllSecLeptons[1].Pz(),AllSecLeptons[1].E());
      InvMassSS=(lep1+lep2).M();
     if (NVertices>0){
         bool GoodVertex=false;
         for (int ivx=0;ivx<NVertices;ivx++){
          if (GoodVertex) continue;
          if(!ev.GetvertexIsFake(ivx) && ev.GetvertexNdof(ivx)>=4 && ev.GetvertexPosition(ivx).Rho()<2. && fabs(ev.GetvertexPosition(ivx).Z())<24.0){
              GoodVertex=true;
}
if (GoodVertex){
            float lep1Z=ev.GetTauVx(AllSecLeptons[0].GetIndex()).Z();
            float  lep2Z=ev.GetTauVx(AllSecLeptons[1].GetIndex()).Z();
          VertCompatibility = (  GoodVertex &&  (fabs(ev.GetvertexPosition(ivx).Z()-lep1Z)<1.0) &&
                               (fabs(ev.GetvertexPosition(ivx).Z()-lep2Z)<1.0));      
       }
     
      //VERTEX COMPATIBILITY MUST BE ADDED
     //VERTEX OF LEPTONS IS MISSING
         }
       }
  

  }




    
    bool DECISION=true;
    vector<bool> CUTS;
    if(AllSecLeptons.size()<1)return DECISION;
    
    CUTS.push_back((chProd>0));
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    CUTS.push_back(MHT<uppermetcut_);
    CUTS.push_back(VertCompatibility);
    CUTS.push_back(InvMassSS>5.);
 

    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);

    if(DECISION){      
      if (AllLeptons.size()==0 && AllSecLeptons.size()>=2){
	if(  AllSecLeptons[0].GetType()==3 &&  AllSecLeptons[1].GetType()==3){
	  weight=w;
	  eta1=AllSecLeptons[0].Eta();
	  eta2=AllSecLeptons[1].Eta();
	  pt1=AllSecLeptons[0].Pt();
	  pt2=AllSecLeptons[1].Pt();	  
 	} // fake tau fake tau
	tree->Fill();
      } // no good leptons
      
      if (AllLeptons.size()==1 && AllSecLeptons.size()>=1){  
	if (AllLeptons[0]->GetType()==1 && AllSecLeptons[0].GetType()==3)
	  hGoodElFakeTau->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),max_LepPt),w);
	if (AllLeptons[0]->GetType()==2 && AllSecLeptons[0].GetType()==3){
	  hGoodMuFakeTau->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),max_LepPt),w);
	}
	if (AllLeptons[0]->GetType()==3 && AllSecLeptons[0].GetType()==3){
	  hGoodTauFakeTau->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),max_LepPt),w);	
	}  
      }    
    }// DECISION
    
 

    return DECISION; 
  }


  std::ostream& TauFRNormalization::Description(std::ostream &ostrm) {
    ostrm << "TauFRNormalization plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }


}
