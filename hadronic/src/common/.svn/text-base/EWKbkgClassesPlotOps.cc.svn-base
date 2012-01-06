#include "GenMatrixBin.hh"
#include "EWKbkgClassesPlotOps.hh"
#include "AlphaT.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
#include "Jet.hh"


using namespace Operation;


PlotPhotons::PlotPhotons(const std::string & folderName) :
  mFolderName(folderName)
{}

PlotPhotons::~PlotPhotons() {}

void PlotPhotons::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

 void PlotPhotons::BookHistos() {
 TH1::SetDefaultSumw2(kTRUE);
 PhotonPt = new  TH1D("PhotonPt",";#gamma P_{T} [GeV];",100,0.,500.);
 PhotonEta = new  TH1D("PhotonEta",";#eta;",50,0.,5.);
 PhotonDR = new  TH1D("PhotonDR",";min #DeltaR(#gamma,jet);",100,0.,6.);

 PhotonPtQuark = new  TH1D("PhotonPtQuark",";#gamma P_{T} [GeV];",100,0.,500.);
 PhotonEtaQuark = new  TH1D("PhotonEtaQuark",";#eta;",50,0.,5.);
 PhotonDRQuark = new  TH1D("PhotonDRQuark",";min #DeltaR(#gamma,jet);",100,0.,6.);

 PhotonPtPrompt = new  TH1D("PhotonPtPrompt",";#gamma P_{T} [GeV];",100,0.,500.);
 PhotonEtaPrompt = new  TH1D("PhotonEtaPrompt",";#eta;",50,0.,5.);
 PhotonDRPrompt = new  TH1D("PhotonDRPrompt",";min #DeltaR(#gamma,jet);",100,0.,6.);

 PhotonPtMeson = new  TH1D("PhotonPtMeson",";#gamma P_{T} [GeV];",100,0.,500.);
 PhotonEtaMeson = new  TH1D("PhotonEtaMeson",";#eta;",50,0.,5.);
 PhotonDRMeson = new  TH1D("PhotonDRMeson",";min #DeltaR(#gamma,jet);",100,0.,6.);

 PhotonPtOther = new  TH1D("PhotonPtOther",";#gamma P_{T} [GeV];",100,0.,500.);
 PhotonEtaOther = new  TH1D("PhotonEtaOther",";#eta;",50,0.,5.);
 PhotonDROther = new  TH1D("PhotonDROther",";min #DeltaR(#gamma,jet);",100,0.,6.);

 PhotonTrIso = new  TH1D("PhotonTrIso",";;",100,0.,1.);
 PhotonHIso = new  TH1D("PhotonHIso",";;",100,0.,1.);
 PhotonEIso = new  TH1D("PhotonEIso",";;",100,0.,1.);
 PhotonCIso = new  TH1D("PhotonCIso",";;",100,0.,1.);

 PhotonC4TrIso = new  TH1D("PhotonC4TrIso",";;",1000,0.,1.);
 PhotonC4HIso = new  TH1D("PhotonC4HIso",";;",1000,0.,1.);
 PhotonC4EIso = new  TH1D("PhotonC4EIso",";;",1000,0.,1.);
 PhotonC4CIso = new  TH1D("PhotonC4CIso",";;",1000,0.,1.);

 PhotonEM = new  TH1D("PhotonEM",";;",100,0.,5.);
 PhotonSieta = new  TH1D("PhotonSieta",";;",1000,0.,1.);
 PhotonR9 = new  TH1D("PhotonR9",";;",100,0.,20.);

}

bool PlotPhotons::Process(Event::Data & ev) {
   if(ev.PD_CommonPhotons().accepted.size() == 0 ) return true; //i.e. no muons exist!

   // Generator stuff to see what typte the events are
   int Index = 0;
   int MotherID = 0;
   int flag =0 ;

   if( ev.pthat.enabled() ) { // very dirty hack (but commonly used in the code) to check if event is MC
   Index = ev.GetMatch(*(ev.PD_CommonPhotons().accepted[0]),22,.5);
   if (Index>0) MotherID = ev.GenParticles()[Index].GetMotherID();  
   if(fabs(MotherID)>0&&fabs(MotherID)<7) flag=1; //quark radiation
   if(fabs(MotherID)==22) flag=2; // prompt
   if(fabs(MotherID)>110) flag=3; // likely a Meson
   // if(fabs(MotherID)==21) flag=4;
   }


   float minDR=10.;
   if(ev.JD_CommonJets().accepted.size() == 0 ) return true; //i.e. no jets exist
   for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) 
     {
       float cDR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(ev.PD_CommonPhotons().accepted.at(0))));
       if(cDR<minDR) minDR = cDR ;
     }
   PhotonDR->Fill(minDR ,ev.GetEventWeight());
   PhotonPt->Fill(ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
   PhotonEta->Fill(fabs(ev.PD_CommonPhotons().accepted[0]->Eta()) ,ev.GetEventWeight());
   
   if(flag==0)
     {
       PhotonDROther->Fill(minDR ,ev.GetEventWeight());
       PhotonPtOther->Fill(ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
       PhotonEtaOther->Fill(fabs(ev.PD_CommonPhotons().accepted[0]->Eta()) ,ev.GetEventWeight());}
   if(flag==1)
     {PhotonDRQuark->Fill(minDR ,ev.GetEventWeight());
       PhotonPtQuark->Fill(ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
       PhotonEtaQuark->Fill(fabs(ev.PD_CommonPhotons().accepted[0]->Eta()) ,ev.GetEventWeight());}
   if(flag==2)
     {
       PhotonDRPrompt->Fill(minDR ,ev.GetEventWeight());
       PhotonPtPrompt->Fill(ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
       PhotonEtaPrompt->Fill(fabs(ev.PD_CommonPhotons().accepted[0]->Eta()) ,ev.GetEventWeight());}
   if(flag==3)
     {
       PhotonDRMeson->Fill(minDR ,ev.GetEventWeight());
       PhotonPtMeson->Fill(ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
       PhotonEtaMeson->Fill(fabs(ev.PD_CommonPhotons().accepted[0]->Eta()) ,ev.GetEventWeight());}
 

   //PhotonEtaQuark->Fill(ev.PD_CommonPhotons().accepted[0]->/ev.PD_CommonPhotons().accepted[0]->Pt()
   //PhotonPtQuark->Fill(ev.PD_CommonPhotons().accepted[0]->/ev.PD_CommonPhotons().accepted[0]->Pt()
   //PhotonDRQuark->Fill(ev.PD_CommonPhotons().accepted[0]->/ev.PD_CommonPhotons().accepted[0]->Pt()


   PhotonTrIso->Fill(ev.PD_CommonPhotons().accepted[0]->GetTrackIsolation()/ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
   PhotonHIso->Fill(ev.PD_CommonPhotons().accepted[0]-> GetHcalIsolation()/ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
   PhotonEIso->Fill(ev.PD_CommonPhotons().accepted[0]->GetEcalIsolation()/ev.PD_CommonPhotons().accepted[0]->Pt() ,ev.GetEventWeight());
   PhotonCIso->Fill((ev.PD_CommonPhotons().accepted[0]->GetTrackIsolation()  +  ev.PD_CommonPhotons().accepted[0]->GetHcalIsolation()  + ev.PD_CommonPhotons().accepted[0]->GetEcalIsolation()  )/ev.PD_CommonPhotons().accepted[0]->Pt(),ev.GetEventWeight());
   PhotonC4TrIso->Fill(ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04()/ev.PD_CommonPhotons().accepted[0]->Pt(),ev.GetEventWeight());
   PhotonC4HIso->Fill(ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04()/ev.PD_CommonPhotons().accepted[0]->Pt(),ev.GetEventWeight());
   PhotonC4EIso->Fill(ev.PD_CommonPhotons().accepted[0]->ecalRecHitSumEtConeDR04()/ev.PD_CommonPhotons().accepted[0]->Pt(),ev.GetEventWeight());
   PhotonC4CIso->Fill(  ( ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04()  +ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04()  + ev.PD_CommonPhotons().accepted[0]-> ecalRecHitSumEtConeDR04() )/ev.PD_CommonPhotons().accepted[0]->Pt(),ev.GetEventWeight());
   PhotonEM->Fill(ev.PD_CommonPhotons().accepted[0]->hadronicOverEm() ,ev.GetEventWeight());
   PhotonSieta->Fill(ev.PD_CommonPhotons().accepted[0]->sigmaIetaIeta() ,ev.GetEventWeight());
   PhotonR9->Fill(ev.PD_CommonPhotons().accepted[0]->r9() ,ev.GetEventWeight());
   //cout << " cone stuff "<< ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04()<<" " <<ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04()  <<endl;
   return true;
  
}


std::ostream& PlotPhotons::Description(std::ostream &ostrm) {
  ostrm << "Photon Plots " ;
  return ostrm;
}

 

GenVBosons::GenVBosons(const std::string & folderName, float VBosonPT) :
  mFolderName(folderName),mVBosonPT(VBosonPT)
{}
GenVBosons::~GenVBosons() {}
void GenVBosons::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

 void GenVBosons::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    BookHistArray( VBPT,"VBPT",";Boson P_{T};",100,0,1000,6,0,1,false);
    BookHistArray( VBET,"VBET",";Boson E_{T};",100,0,1000,6,0,1,false);
    BookHistArray( VBETAT,"VBETAT",";#alpha_{T};",600,0,3,6,0,1,false);
    BookHistArray( VBHT,"VBHT",";H_{T};",100,0,1000,6,0,1,false);
    BookHistArray( VBHTAT,"VBHTAT",";H_{T};",100,0,1000,6,0,1,false);

  BookHistArray( VBY,"VBY",";|Y|;",100,0,10,6,0,1,false);
    BookHistArray( VBPTHT,"VBPTHT",";VBoson P_{T}/H_{T};",100,0,10,6,0,1,false);
    // BookHistArray( VBETHT ,"VBETHT",";VBETHT;",100,0,10,6,0,1,false);
 
    //    BookHistArray(VBHT ,"HT",";HT;",100,0,1000,6,0,1,false);

    VBNjet = new TH1D("Njet",";number of jets;",20,-0.5,19.5);
    VBjet1 = new TH1D("jetPt1",";1. jet P_{T} [GeV];",200,-0.,2000);
    VBjet2 = new TH1D("jetPt2",";2. jet P_{T} [GeV];",200,-0.,2000);
    VBjet3 = new TH1D("jetPt3",";3. jet P_{T} [GeV];",200,-0.,2000);
    VBjet4 = new TH1D("jetPt4",";4. jet P_{T} [GeV];",200,-0.,2000);

    VBjet1Eta = new TH1D("jetEta1",";1. jet |#eta|;",200,-0.,5);
    VBjet2Eta = new TH1D("jetEta2",";2. jet |#eta|;",200,-0.,5);
    VBjet3Eta = new TH1D("jetEta3",";3. jet |#eta|;",200,-0.,5);
    VBjet4Eta = new TH1D("jetEta4",";4. jet |#eta|;",200,-0.,5);

    VBjet1DR2 = new TH1D("jet1DR2 ",";#DeltaR(jet1,jet2);",200,-0.,5);
    VBjet1DPhi2 = new TH1D("jet1DPhi22 ",";#Delta#phi(jet1,jet2);",200,-0.,5);



    //  VBjet1DR3 = new TH1D("jet1DR3 ",";DR(jet1,jet2);",200,-0.,5);
    //  VBjet1DR4 = new TH1D("jet1DR4 ",";DR(jet1,jet2);",200,-0.,5);
   



    //  RVBNjet = new TH1D("RNjet",";Reco Njet;",20,-0.5,19.5);
    // RVBjet1 = new TH1D("RjetPt1",";Reco P_{T} [GeV];",200,-0.,2000);
    //  RVBjet2 = new TH1D("RjetPt2",";Reco P_{T} [GeV];",200,-0.,2000);
    //   RVBjet3 = new TH1D("RjetPt3",";Reco P_{T} [GeV];",200,-0.,2000);
    //    RVBjet4 = new TH1D("RjetPt4",";Reco P_{T} [GeV];",200,-0.,2000);

    BookHistArray( VBDR,"VBDR",";Min #Delta R (Boson,jet);",600,0,3.2,6,0,1,false);

}

bool GenVBosons::Process(Event::Data & ev) {

  // std::cout << " Geni " << std::endl;
    GenMatrixBin myGenMatrixBin(&ev);
    // std::cout << " Weni " << std::endl;
    //    vector <Event::GenObject const *> THEboson;
    Event::GenObject const *  THEboson;
   
    if(myGenMatrixBin.the_GenW.size()>0) THEboson = myGenMatrixBin.the_GenW.at(0);
    if(myGenMatrixBin.the_GenZ.size()>0) THEboson = myGenMatrixBin.the_GenZ.at(0);
    if(myGenMatrixBin.the_GenPhot.size()>0) THEboson = myGenMatrixBin.the_GenPhot.at(0);
 


    //   if
    //  THEboson =   vector <Event::GenObject const *> the_GenW;
    //vector <Event::GenObject const *> the_GenZ;
    if(myGenMatrixBin.the_GenW.size()+myGenMatrixBin.the_GenZ.size()+myGenMatrixBin.the_GenPhot.size()!=1) {
      std::cout << "GenVBosons: many Bosons or none" <<  myGenMatrixBin.the_GenW.size()+myGenMatrixBin.the_GenZ.size()+myGenMatrixBin.the_GenPhot.size()<< std::endl;
      return false;}
    if(THEboson->Pt()<mVBosonPT) return false;
    VBPT[0]->Fill(THEboson->Pt(),ev.GetEventWeight());
    VBET[0]->Fill(THEboson->Et(),ev.GetEventWeight());
    VBY[0]->Fill(THEboson->Rapidity(),ev.GetEventWeight());
  
    float myHT=0;
    float myDR=10;
    vector  <Event::Jet const*> myJets;
  
    Event::GenObject const *  TheLepton;
    bool aLep = false; 
   if(myGenMatrixBin.the_GenEli.size()+myGenMatrixBin.the_GenMuon.size()>0)
     {
       aLep = true;
       if(myGenMatrixBin.the_GenEli.size()>0) TheLepton= myGenMatrixBin.the_GenEli.at(0);
       if(myGenMatrixBin.the_GenMuon.size()>0) TheLepton= myGenMatrixBin.the_GenMuon.at(0);
      }
       
       int Rnjets=0;
    int ovi=-1;
    std::vector<Event::Jet const *>::const_iterator ob = ev.JD_CommonJets().accepted.begin();
    std::vector<Event::Jet const *>::const_iterator oe = ev.JD_CommonJets().accepted.end();
    for ( ; ob != oe; ++ob ) { 
      float iDR = fabs(ROOT::Math::VectorUtil::DeltaR(*(*ob),*THEboson));
      if(iDR<myDR) myDR=iDR;
      if(fabs(ROOT::Math::VectorUtil::DeltaR(*(*ob),*THEboson))<0.5) {ovi=Rnjets;   ;continue;}

      if(aLep)
	{
	  if(fabs(ROOT::Math::VectorUtil::DeltaR(*(*ob),*TheLepton))<0.25) {ovi=Rnjets ;continue;} 
	}

      Rnjets++;
      myJets.push_back(*ob);
      myHT+=(*ob)->Pt(); 
   }

    int njets = myJets.size();

    std::sort(myJets.begin(), myJets.end(),KinSuite::PCompare );

    if(njets>0)  VBjet1->Fill(myJets[0]->Pt(),ev.GetEventWeight());
    if(njets>1)  VBjet2->Fill(myJets[1]->Pt(),ev.GetEventWeight());
    if(njets>2)  VBjet3->Fill(myJets[2]->Pt(),ev.GetEventWeight());
    if(njets>3)  VBjet4->Fill(myJets[3]->Pt(),ev.GetEventWeight());
    if(njets>0)  VBjet1Eta->Fill(myJets[0]->Eta(),ev.GetEventWeight());
    if(njets>1)  VBjet2Eta->Fill(myJets[1]->Eta(),ev.GetEventWeight());
    if(njets>2)  VBjet3Eta->Fill(myJets[2]->Eta(),ev.GetEventWeight());
    if(njets>3)  VBjet4Eta->Fill(myJets[3]->Eta(),ev.GetEventWeight());

    if(njets>1) {
      VBjet1DR2->Fill(fabs(ROOT::Math::VectorUtil::DeltaR(*(myJets[0]),*(myJets[1]))),ev.GetEventWeight());
      VBjet1DPhi2->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(myJets[0]),*(myJets[1]))),ev.GetEventWeight());
   
      
    }
    //  cout << njets << endl;
    VBNjet->Fill(myJets.size(),ev.GetEventWeight());
    VBPTHT[0]->Fill(THEboson->Pt()/myHT,ev.GetEventWeight());
    //  VBETHT[0]->Fill(THEboson->Et()/myHT,ev.GetEventWeight());
    VBHT[0]->Fill(myHT,ev.GetEventWeight());

    if (njets>5) njets=5;
 
    if (njets>0){

      if(njets>1){
		AlphaT myAT;// = AlphaT();
		double ATVal = myAT(myJets);
		VBETAT[0]->Fill(ATVal,ev.GetEventWeight());
		VBETAT[njets]->Fill(ATVal,ev.GetEventWeight());
		VBHTAT[0]->Fill(myHT,ev.GetEventWeight());
		if(ATVal>0.55) 	{
		  VBHTAT[1]->Fill(myHT,ev.GetEventWeight());
		  VBHTAT[njets]->Fill(myHT,ev.GetEventWeight());
		}
      } 

      //    cout <<" VBDR "<< myDR <<endl;
      VBDR[0]->Fill(myDR,ev.GetEventWeight());
      VBDR[njets]->Fill(myDR,ev.GetEventWeight());
      VBPT[njets]->Fill(THEboson->Pt(),ev.GetEventWeight());
      VBET[njets]->Fill(THEboson->Et(),ev.GetEventWeight());
      VBY[njets]->Fill(THEboson->Rapidity(),ev.GetEventWeight());
      VBPTHT[njets]->Fill(THEboson->Pt()/myHT,ev.GetEventWeight());
      //  VBETHT[njets]->Fill(THEboson->Et()/myHT,ev.GetEventWeight());
      VBHT[njets]->Fill(myHT,ev.GetEventWeight());

    }
    //
    //  cout << " I did something " << endl;

    //  if(njets==3) { myGenMatrixBin.PrintStableVis();ev.PrintGen();}
    //myGenMatrixBin.PrintStableVis();ev.PrintGen();
    //ev.PrintStableVisAllRec();
    //cout << " I did something " << endl;

 
   //  cout << " I did something j" << ovi << " "<< Rnjets<< " "<<ev.JD_CommonJets().accepted.size()<<endl;
    /*
   RVBNjet->Fill(Rnjets,ev.GetEventWeight());

    if(ovi<0)
      {
		if(Rnjets>0) RVBjet1->Fill(ev.JD_CommonJets().accepted[0]->Pt(),ev.GetEventWeight());
		if(Rnjets>1) RVBjet2->Fill(ev.JD_CommonJets().accepted[1]->Pt(),ev.GetEventWeight());
		if(Rnjets>2) RVBjet3->Fill(ev.JD_CommonJets().accepted[2]->Pt(),ev.GetEventWeight());
		if(Rnjets>3) RVBjet4->Fill(ev.JD_CommonJets().accepted[3]->Pt(),ev.GetEventWeight());
      }

    */
    //     cout << " I did something o" << endl;
    return true;
 }

std::ostream& GenVBosons::Description(std::ostream &ostrm) {
  ostrm << "Wo photonen wohnen "
    ;
  return ostrm;
}



EWKbkgClassesPlotOps::EWKbkgClassesPlotOps(const std::string & folderName) :
  mFolderName(folderName)
					  //change this parameter ONLY - this will let you use comparison with generator level quantities
{}

EWKbkgClassesPlotOps::~EWKbkgClassesPlotOps() {}

void EWKbkgClassesPlotOps::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void EWKbkgClassesPlotOps::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    BookHistArray(NLeptons,"NLeptons",";number of leptons",3,-.5,2.5,6,0,1,false);
    BookHistArray(NKind,"NKind",";number of leptons",3,-.5,2.5,6,0,1,false);   
    BookHistArray(NLeptonsMHad,"NLeptonsMHad",";# leptons - # had taus",3,-.5,2.5,6,0,1,false);
    BookHistArray(NTau,"NTau",";# taus",3,-.5,2.5,6,0,1,false);
    BookHistArray(NMuon,"NMuon",";# muons",2,-.5,1.5,6,0,1,false);
    BookHistArray(NEli,"NEli",";# electrons",2,-.5,1.5,6,0,1,false);
    BookHistArray(NMuonAc,"NMuonAc",";#eta;P_{T} [GeV]",150,0,15,500,0,500 ,6,0,1,false);
    BookHistArray(NEliAc,"NEliAc",";#eta;P_{T} [GeV]",150,0,15,500,0,500 ,6,0,1,false);
    BookHistArray(MeffZeff,"MeffZeff",";#eta;P_{T} [GeV]",100,0,2000,200,0,10000,6,0,1,false);
    BookHistArray(TransV,"TransV",";#eta;P_{T} [GeV]",500,0,10,6,0,1,false);
    BookHistArray(TransVHT,"TransVHT",";#eta;P_{T} [GeV]",500,0,5000,6,0,1,false);
    BookHistArray(HTeta,"HTeta",";#eta;P_{T} [GeV]",100,0,5,200,0,2000,6,0,1,false);

   // BookHistArray(TransVHT,"TransVHT",";#eta;P_{T} [GeV]",500,0,5000,6,0,1,false);
   // BookHistArray(NTau_Map,"NTau_Map",";# tau -> lepton",3,-.5,2.5,6,0,1,false);
  }

  bool EWKbkgClassesPlotOps::Process(Event::Data & ev) {

    GenMatrixBin myGenMatrixBin(&ev);

    int aNTau = myGenMatrixBin.the_GenTau.size();
    int aNMuon = myGenMatrixBin.the_GenMuon.size();
    int aNEli = myGenMatrixBin.the_GenEli.size();
    int aNLepton = aNTau+aNMuon+aNEli;

    NLeptons[0]->Fill(aNLepton,ev.GetEventWeight());
    NLeptonsMHad[0]->Fill(myGenMatrixBin.nTauHad,ev.GetEventWeight());
    NTau[0]->Fill(aNTau,ev.GetEventWeight());

    if(aNLepton==1)
      {
	if(aNEli==1) NKind[0]->Fill(1.,ev.GetEventWeight());
	if(aNMuon==1)  NKind[0]->Fill(2.,ev.GetEventWeight());
	if(aNTau==1)  NKind[0]->Fill(0.,ev.GetEventWeight());
      }

    if(aNMuon==1)NMuonAc[0]->Fill(fabs(myGenMatrixBin.the_GenMuon[0]->Eta()),myGenMatrixBin.the_GenMuon[0]->Pt(),ev.GetEventWeight());
    if(aNEli==1)NEliAc[0]->Fill(fabs(myGenMatrixBin.the_GenEli[0]->Eta()),myGenMatrixBin.the_GenEli[0]->Pt(),ev.GetEventWeight());

    float muPt = 10;
    float elPt = 10;
    float mueta = 2.4;
    float elEta = 2.4;

    if(aNMuon==1)
      {
	if(fabs(myGenMatrixBin.the_GenMuon[0]->Eta())< mueta && myGenMatrixBin.the_GenMuon[0]->Pt()>muPt )
	  {
	      NMuon[0]->Fill(0.,ev.GetEventWeight());
	  }
	else
	  {
	      NMuon[0]->Fill(1.,ev.GetEventWeight());
	  }
      }

    if(aNEli==1)
      {
	if(fabs(myGenMatrixBin.the_GenEli[0]->Eta())< elEta &&myGenMatrixBin.the_GenEli[0]->Pt()>elPt )
	  {
	    NEli[0]->Fill(0.,ev.GetEventWeight());
	  }
	else
	  {
	    NEli[0]->Fill(1.,ev.GetEventWeight());
	  }
      }


    float Zeff = 0;
    float Zav = 0;
    for ( std::vector<Event::Jet const *>::const_iterator i = ev.JD_CommonJets().accepted.begin();
	  i != ev.JD_CommonJets().accepted.end();i++ )
      {
	Zeff += fabs((*i)->Pz());
	Zav += (*i)->Pz();
      }


    //    MeffZeff[0]->Fill(ev.CommonSumEt(),Zeff,ev.GetEventWeight());
    MeffZeff[0]->Fill(ev.CommonSumEt(),fabs(Zav),ev.GetEventWeight());
    HTeta[0]->Fill(fabs(ev.JD_CommonJets().accepted[0]->Eta()),ev.CommonSumEt(),ev.GetEventWeight());

    TransVHT[0]->Fill(ev.CommonSumEt()/Zeff*ev.CommonSumEt(),ev.GetEventWeight());
    TransV[0]->Fill(ev.CommonSumEt()/Zeff,ev.GetEventWeight());


    //  NTau_Map[0]->Fill(,ev.GetEventWeight());


    return true;
  }




std::ostream& EWKbkgClassesPlotOps::Description(std::ostream &ostrm) {
  ostrm << "tt bar ist wunderbar har har "
    ;
  return ostrm;
}



EWK_Classes::EWK_Classes(const std::string & folderName) :
  mFolderName(folderName)
					  //change this parameter ONLY - this will let you use comparison with generator level quantities
{}

EWK_Classes::~EWK_Classes() {}

void EWK_Classes::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }



  void EWK_Classes::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    BookHistArray(NLeptons,"Type",";type of W;",7,-1.5,5.5,6,0,1,false);
  
  }


  bool EWK_Classes::Process(Event::Data & ev) {

    GenMatrixBin myGenMatrixBin(&ev);
   
    int njets = ev.JD_CommonJets().accepted.size();
    if (njets>6) njets = 6 ;
    int noLep =  myGenMatrixBin.nTauHad + myGenMatrixBin.the_GenElectronExtra.size()+myGenMatrixBin.the_GenMuonExtra.size();
    if(noLep>1) // fully leptonic
      {
	NLeptons[0]->Fill(0.,ev.GetEventWeight());
	NLeptons[njets]->Fill(0.,ev.GetEventWeight());
	return true;
      }
    if(noLep==0) // fully hadronic
      {
	NLeptons[0]->Fill(-1,ev.GetEventWeight());
	NLeptons[njets]->Fill(-1,ev.GetEventWeight());
	return true;
      }

    float muPt = 11;
    float elPt = 11;
    float mueta = 2.3;
    float elEta = 2.3;

    if(myGenMatrixBin.the_GenMuonExtra.size()==1)
      {	
	if(fabs(myGenMatrixBin.the_GenMuonExtra[0]->Eta())< mueta && myGenMatrixBin.the_GenMuonExtra[0]->Pt()>muPt)
	  {
	    NLeptons[0]->Fill(1.,ev.GetEventWeight());
	    NLeptons[njets]->Fill(1.,ev.GetEventWeight());
	  }
	else {  
	  NLeptons[0]->Fill(2.,ev.GetEventWeight());
	  NLeptons[njets]->Fill(2.,ev.GetEventWeight());
	}
      }

    if(myGenMatrixBin.the_GenElectronExtra.size()==1)
      {	
	if(fabs(myGenMatrixBin.the_GenElectronExtra[0]->Eta())< elEta && myGenMatrixBin.the_GenElectronExtra[0]->Pt()>elPt)
	  {
	    NLeptons[0]->Fill(3.,ev.GetEventWeight());
	    NLeptons[njets]->Fill(3.,ev.GetEventWeight());
	  }
	else {  
	  NLeptons[0]->Fill(4.,ev.GetEventWeight());
	  NLeptons[njets]->Fill(4.,ev.GetEventWeight());
	}
      }

    if(myGenMatrixBin.nTauHad==1)
      {
        NLeptons[0]->Fill(5.,ev.GetEventWeight());
	NLeptons[njets]->Fill(5.,ev.GetEventWeight());
      }

    return true;
  }




std::ostream& EWK_Classes::Description(std::ostream &ostrm) {
  ostrm << "EWK_Classes identifyer "
    ;
  return ostrm;
}
