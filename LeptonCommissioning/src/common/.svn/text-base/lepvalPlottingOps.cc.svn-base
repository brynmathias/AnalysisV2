#include "lepvalPlottingOps.hh"
#include "lepvalMC.hh"
#include "lepvalJPsiSelection.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
#include "EventData.hh"
#include "Types.hh"
#include <fstream>

namespace lepval{


  LepValPlots::LepValPlots(const std::string& foldername, bool JPsiStudy, bool GenOn, bool TextOut, std::string Outfile) :
    mFoldername(foldername),
    mOutfile(Outfile),
    mJPsiStudy(JPsiStudy),
    mGenOn(GenOn),
    mTextOut(TextOut)
    {}

  LepValPlots::~LepValPlots() {}

  void LepValPlots::Start(Event::Data& ev) {
    initDir(ev.OutputFile(), mFoldername.c_str());
    BookHistos();
    if (mTextOut){
      std::cout<<"should be writing to"<<mOutfile+ev.DataSet()+".txt"<<std::endl;
      ofstream Out;
      Out.open((mOutfile+ev.DataSet()+".txt").c_str(),ios::out|ios::app);
      Out<<"RUN : LUMI : EVENT : MASS : CHARGE : Pt : Eta : Mu1Pt : Mu2Pt : Mu1Eta : Mu2Eta"<<endl;
      Out.close();
    }

      
  }

  void LepValPlots::BookHistos() {
    LeptonIDs = new TH1D("LepID", "LepID", 12, -1, 11); 
    JPsiInvMassPlot = new TH1D("InvMass", "InvMass", 1000, 0, 10);
    LepIsoPt5_10 = new TH1D("LepIsoPt5_10", "LepIsoPt5_10", 201, -0.5, 50);
    LepIsoPt10_15 = new TH1D("LepIsoPt10_15", "LepIsoPt10_15", 201, -0.5, 50);
    LepIsoGenMatchPt5_10 = new TH1D("LepTrkIsoGenMatchPt5_10", "LepTrkIso5_10", 201, -0.5, 50);
    LepIsoGenMatchPt10_15 = new TH1D("LepTrkIsoGenMatchPt10_15", "LepTrkIso10_15", 201, -0.5, 50);
    mumultip = new TH1D("mumltip", "mumultip", 11, -0.5, 10);
    numevents = new TH1D("numevents", "numevents", 2, -0.5, 1.5);
    HT = new TH1D("HT_Distrib", "HT", 401, -0.5, 400.5);
    HT_allObjects = new TH1D("HT_AllObj_distrib", "HT_AllObj", 401, -0.5, 400.5);
    LeadMuonSpect = new TH1D("leadMuonSpec", "MuonPt", 61, -0.5, 60.5);
    LeadElecSpect = new TH1D("leadElecSpec", "ElecPt", 61, -0.5, 60.5);
    MuonPtSpect = new TH1D("MuonPtSpec", "MuonPtSpec", 61, -0.5, 60.5);
    ElecPtSpect = new TH1D("ElecPtSpec", "ElecPtSpec", 61, -0.5, 60.5);
  }

    bool LepValPlots::Process(Event::Data& ev){
      double weight = 1.0;//ev.GetEventWeight();
      double MuonSumPt = 0., ElecSumPt = 0.;
     

      std::vector<Event::Lepton const*> JPsiSelecMuons = ev.Get<lepval::LepValJPsiMu>("JPsiSelectionMuons")();
      //genlep matching
      
      std::vector<int> GenMatchedMuonInd;
      std::vector<Event::GenObject const*> IsoGenLep;
      
      
      if(mGenOn){

	IsoGenLep=ev.Get<lepval::IsolatedLeptons>("Custom_IsoGenLeps")();

      float DRmax=0.5;
      int iLep=0;
      
 for (std::vector<Event::Lepton>::const_iterator it=ev.LD_Muons().begin(); it!=ev.LD_Muons().end(); ++it){

   int matchInd=-1;
      for(std::vector<Event::GenObject const*>::const_iterator GL=IsoGenLep.begin(); GL!=IsoGenLep.end(); ++GL, iLep++)
	{
	  if (abs((*GL)->GetID()==11)||abs((*GL)->GetID()==15)){continue;}

	 
	  float dR = ROOT::Math::VectorUtil::DeltaR(**GL, *it);
	  if (dR < DRmax){
	    matchInd=iLep;
	    DRmax=dR;
	  }
	 
	  
	}

      GenMatchedMuonInd.push_back(matchInd);//this stores the index of the GenMatched RecoMuons

 }    
      }
 numevents->Fill(1, weight);
 
if (mJPsiStudy){
 if(JPsiSelecMuons.size()==2){
   const Event::Lepton *RecMuon1, *RecMuon2;
   RecMuon1=JPsiSelecMuons[0];
   RecMuon2=JPsiSelecMuons[1];
   double DR=ROOT::Math::VectorUtil::DeltaR(*RecMuon1,*RecMuon2);
   double trkiso1 = 0., trkiso2 = 0.;
     if(DR<=0.3){
       trkiso1 = (RecMuon1->GetTrkIsolation())-(RecMuon2->GetTrkIsolation());
       trkiso2 = (RecMuon2->GetTrkIsolation())-(RecMuon1->GetTrkIsolation());
     }
     else{
       trkiso1 = RecMuon1->GetTrkIsolation();
       trkiso2 = RecMuon2->GetTrkIsolation();
     }
   //plot the isolation of the muons
   if(RecMuon1->Pt()>=5. && RecMuon1->Pt()<=10.){
     LepIsoPt5_10->Fill(trkiso1, weight);
   }
   if(RecMuon2->Pt()>=5. && RecMuon1->Pt()<=10.){
     LepIsoPt5_10->Fill(trkiso2, weight);
   }
   if(RecMuon1->Pt()>=10. && RecMuon1->Pt()<=15.){
     LepIsoPt10_15->Fill(trkiso1, weight);
   }
   if(RecMuon2->Pt()>=10. && RecMuon2->Pt()<=15.){
     LepIsoPt10_15->Fill(trkiso2, weight);
   }

   LorentzV RecoJPsi = *RecMuon1+*RecMuon2;
   double JPsiInvMass = RecoJPsi.M();

   JPsiInvMassPlot->Fill(JPsiInvMass, weight);

   //JPsi candidates text out
   if (mTextOut){
     ofstream Out;
     Out.open((mOutfile+ev.DataSet()+".txt").c_str(),ios::out|ios::app);
     uint runnum = ev.RunNumber();
     uint evnum = ev.EventNumber();
     uint lumi = ev.LumiSection();
     double JPsiPt = RecoJPsi.Pt();
     double JPsiEta = RecoJPsi.Eta();
     double JPsiCharge = RecMuon1->GetCharge()+RecMuon2->GetCharge();
     double RecMu1Pt = RecMuon1->Pt();
     double RecMu2Pt = RecMuon2->Pt();
     double RecMu1Eta = RecMuon1->Eta();
     double RecMu2Eta = RecMuon2->Eta();

     Out<<runnum<<":"<<lumi<<":"<<evnum<<":"<<JPsiInvMass<<":"<<JPsiCharge<<":"<<JPsiPt<<":"<<JPsiEta<<":"<<RecMu1Pt<<":"<<RecMu2Pt<<":"<<RecMu1Eta<<":"<<RecMu2Eta<<":"<<std::endl;
     Out.close();
     
   }

 }
 
   
   mumultip->Fill(ev.LD_Muons().size(), weight);
   
   if(mGenOn){
     std::cout<<"GEN IS ON"<<std::endl;
   if(ev.LD_Muons().size()==1){//include case with only 1 reco muon
       bool match1 = GenMatchedMuonInd[0]>=0;//we only want to know if there is a match for the two muons or not
       const Event::Lepton *singleMu;
       singleMu=&ev.LD_Muons()[0];
       if(!match1){return false;}
       if(ev.GenParticles()[IsoGenLep[GenMatchedMuonInd[0]]->GetMother()].GetID()!=9900443){return false;}//usual jpsi pdg is 443, here the value is 9900443 for some reason
       if(singleMu->Pt()>=5. && singleMu->Pt()<=10){
	 LepIsoGenMatchPt5_10->Fill(singleMu->GetTrkIsolation(), weight);
       }
       if(singleMu->Pt()>=10. && singleMu->Pt()<=15.){
	 LepIsoGenMatchPt10_15->Fill(singleMu->GetTrkIsolation(), weight);
       }

       return true;
     }




   if(ev.LD_Muons().size()!=2){return false;}
   bool match1 = GenMatchedMuonInd[0]>=0;
   bool match2 = GenMatchedMuonInd[1]>=0;
   const Event::Lepton *leadingMu, *secondMu, *Muon1, *Muon2;
   Muon1=&ev.LD_Muons()[0];
     Muon2=&ev.LD_Muons()[1];
     double deltaR=ROOT::Math::VectorUtil::DeltaR(*Muon1,*Muon2);
     double trkisolead = 0., trkisosecond =0., trkiso = 0.;
     if(Muon1->Pt()>Muon2->Pt()){
       leadingMu=Muon1;
       secondMu=Muon2;
     }
     else{
       leadingMu=Muon2;
       secondMu=Muon1;
     }
     
     
     if(!match1 && !match2){return false;}
     
     
     
     //now we assess trkiso according to Pt order or matched muons
     if(match1 && match2){//both muons are matched so we take pt order
       if(deltaR<=0.3){//remove contribution of second muon to isolation
	 trkisolead = (leadingMu->GetTrkIsolation())-(secondMu->Pt());
	 trkisosecond = (secondMu->GetTrkIsolation())-(leadingMu->Pt());
       }
       else{
	 trkisolead=leadingMu->GetTrkIsolation();
	 trkisosecond=secondMu->GetTrkIsolation();
       }
     }
     //plot
     if((leadingMu->Pt()>=5.) && (leadingMu->Pt()<=10.)){
       LepIsoGenMatchPt5_10->Fill(trkisolead, weight);
     }
     if((secondMu->Pt()>=5.) && (secondMu->Pt()<=10.)){
       LepIsoGenMatchPt5_10->Fill(trkisosecond, weight);
     }
     if((leadingMu->Pt()>=10.) && (leadingMu->Pt()<=15.)){
       LepIsoGenMatchPt10_15->Fill(trkisolead, weight);
     }
     if((secondMu->Pt()>=10.) && (secondMu->Pt()<=15.)){
       LepIsoGenMatchPt10_15->Fill(trkisosecond, weight);
     }
     //
     
     if(!match1 && match2){
       if(deltaR<=0.3){
	 trkiso=(Muon2->GetTrkIsolation())-(Muon1->Pt());
       }
       else{
	 trkiso=Muon2->GetTrkIsolation();
       }
     }
     //plot
     if((Muon2->Pt()>=5.) && (Muon2->Pt()<=10.)){
       LepIsoGenMatchPt5_10->Fill(trkiso, weight);
     }
     if((Muon2->Pt()>=10.) && (Muon2->Pt()<=15.)){
       LepIsoGenMatchPt10_15->Fill(trkiso, weight);
     }
     //
     
     if(match1 && !match2){
       if(deltaR<=0.3){
	 trkiso=(Muon1->GetTrkIsolation())-(Muon2->Pt());
       }
       else{
	 trkiso=Muon1->GetTrkIsolation();
       }
     }
     //plot
     if((Muon1->Pt()>=5.) && (Muon1->Pt()<=10.)){
       LepIsoGenMatchPt5_10->Fill(trkiso, weight);
     }
     if((Muon1->Pt()>=10.) && (Muon1->Pt()<=15.)){
       LepIsoGenMatchPt10_15->Fill(trkiso, weight);
     }

   
   
   
//    else{
   
//      for(std::vector<Event::Lepton>::const_iterator i=ev.LD_Muons().begin(); i!=ev.LD_Muons().end(); ++i){
//        std::cout<<"OK1"<<std::endl;
//        if(ev.leptonType(ev.leptonMatch(&*i, 2))==10){continue;}
//        std::cout<<"OK2"<<std::endl;
//        if((i->Pt()>=5.) && (i->Pt()<=10.)){
// 	 LepIsoGenMatchPt5_10->Fill(i->GetTrkIsolation(), weight);
//        }
//        if((i->Pt()>=10.) && (i->Pt()<=15.)){
// 	 LepIsoGenMatchPt10_15->Fill(i->GetTrkIsolation(), weight);
//        }
//      }
// //    }
   }//end gen
   
 }//end JPsi Study
   
 if(mGenOn){//typically this bit is for LMx samples
 for(std::vector<Event::Lepton>::const_iterator i=ev.LD_Muons().begin(); i!=ev.LD_Muons().end(); ++i){
   if (i->GetTightId()){
   LeptonIDs->Fill(ev.leptonType(ev.leptonMatch(&*i, 2)), weight);
   if(ev.leptonType(ev.leptonMatch(&*i, 2))==10 || ev.leptonType(ev.leptonMatch(&*i, 2))==-1){continue;}//remove fakes and HF
       if((i->Pt()>=5.) && (i->Pt()<=10.)){
	 LepIsoGenMatchPt5_10->Fill(i->GetTrkIsolation(), weight);
       }
       if((i->Pt()>=10.) && (i->Pt()<=15.)){
	 LepIsoGenMatchPt10_15->Fill(i->GetTrkIsolation(), weight);
       }
     }
 }
 }
   
   
   HT->Fill(ev.CommonHT(), weight);
   HT_allObjects->Fill(ev.CommonSumEt(), weight);
   
   // std::cout<<ev.LD_CommonMuons().accepted.size()<<std::endl;
   if(ev.LD_CommonMuons().accepted.size()>0){
     LeadMuonSpect->Fill(ev.LD_CommonMuons().accepted[0]->Pt(), weight);
     for (std::vector<const Event::Lepton*>::const_iterator it=ev.LD_CommonMuons().accepted.begin(); it!=ev.LD_CommonMuons().accepted.end(); ++it){
       MuonSumPt += (*it)->Pt();
     }
     MuonPtSpect->Fill(MuonSumPt, weight);
   }
   if(ev.LD_CommonElectrons().accepted.size()>0){
     //	std::cout<<ev.LD_CommonElectrons().accepted.size()<<std::endl;
     // 	ElecMultip->Fill(ev.LD_CommonElectrons().accepted.size(), weight);
     LeadElecSpect->Fill(ev.LD_CommonElectrons().accepted[0]->Pt(), weight);
     for (std::vector<const Event::Lepton*>::const_iterator it=ev.LD_CommonElectrons().accepted.begin(); it!=ev.LD_CommonElectrons().accepted.end(); ++it){
       ElecSumPt += (*it)->Pt();
     }
     ElecPtSpect->Fill(ElecSumPt, weight);
   }
   return true;
 }
 
 std::ostream& LepValPlots::Description(std::ostream &ostrm){
   ostrm<<"Lepton Validation Plots";
   return ostrm;
 }
 
    }
  
  
