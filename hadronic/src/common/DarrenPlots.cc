#include "DarrenPlots.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "Types.hh"
#include "mt2_bisect.hh"
#include "AlphaT.hh"
#include "Jet.hh"
#include "Math/VectorUtil.h"
#include "JetData.hh"
#include <fstream>


using namespace Operation;

//===============================================================
DarrenPlots::DarrenPlots( const Utils::ParameterSet& ps) :
  
  dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),


//MHT/MET Plots
  MHTMETPlots_( ps.Get<bool>("MHTMETPlots") ),
  MHTPlots_( ps.Get<bool>("MHTPlots") ),
  CleaningPlots_( ps.Get<bool>("CleaningPlots") ),
  deadECALFile_(ps.Get<std::string>("DeadECALFile") ),
  deadECAL_minJetPTCut_(ps.Get<double>("DeadECAL_MinJetPtCut") ),
  deadECAL_minBiasCut_(ps.Get<double>("DeadECAL_MinBiasCut") ),
  deadECAL_nBadCellsCut_(ps.Get<int>("DeadECAL_NBadCellsCut") )
  {}
//=================================================================
// Destructor
//================================================================
DarrenPlots::~DarrenPlots() {}
//===================================================================

//==================================================================
void DarrenPlots::Start( Event::Data& ev ) {

  TDirectory* headDir = returnDir(ev.OutputFile(),dirName_.c_str());

  if(MHTMETPlots_){
    initDir(headDir,"MHTMETPlots_");
    MHTMETPlots();
   }
  

  if(MHTPlots_){
    initDir(headDir,"MHTPlots)");
    MHTPlots();
    }


  if(CleaningPlots_){
    initDir(headDir,"CleaningPlots)");
    CleaningPlots();
    }



  BookHistos();
}

void DarrenPlots::BookHistos() {  
}

// -----------------------------------------------------------------------------
//
bool DarrenPlots::Process( Event::Data& ev ) {
  
  if ( MHTPlots_)                   { MHTPlots(ev);    }
  if ( MHTMETPlots_ )               { MHTMETPlots(ev); }
  if ( CleaningPlots_ )             { CleaningPlots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& DarrenPlots::Description( std::ostream& ostrm ) {
  ostrm << "DarrenPlots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";

  return ostrm;

}

//============================================================================
//Book Histos
//=============================================================================
void DarrenPlots::MHTPlots(){

 BookHistArray( MHT_,
   "MHT",
   ";#slash{H}_{T} (GeV); Events/10 GeV;",
   40,0.,400.,
   nMax_+1, 0, 1, true );


  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T};Events/0.025;",
    60,0.,1.5,
    nMax_+1, 0, 1, true );


  BookHistArray( HT_,
    "HT",
    ";H_{T} (GeV); Events/25 GeV;",
    80,0.,2000.,
    nMax_+1, 0, 1, true );
}   


void DarrenPlots::MHTMETPlots(){

  BookHistArray(MHTOvCaloMET_,
		"MHTOvCaloMET",
		";MHTOvCaloMET",
		1000,0,50,
		nMax_+1,0,1,true);

  BookHistArray(BiasedDphi_pT50GeV_,
    "BiasedDeltaPhi_pt50GeV",
    ";#Delta #phi^{*} (rad); Events/0.05 rad;",
    60, 0., TMath::Pi(),
    nMax_+1, 0, 1, true );
  
}


void DarrenPlots::CleaningPlots(){


  BookHistArray(BadJetECALDR_,
    "BadJetECALDR",
    ";DR(jet,Death to the ECAL);"
    ,200,0,10,
    nMax_+1,0,1,true);

  BookHistArray(allMinECALDR_,
    "allMinECALDR",
    ";DR(jet,Death to the ECAL);",
    200,0,10,
    nMax_+1,0,1,true);

  BookHistArray(TPMHT_,
    "TPMHT",
    ";TPMHT;",
    400,0,1000,
    nMax_+1,0,1,true);

  BookHistArray(TPMHTRatio_,
    "TPMHTRatio",
    ";TPMHTRatio;",
    200,0,40,
    nMax_+1,0,1,true);

  BookHistArray(TPHT_,
    "TPHT",
    ";TPHT;",
    400,0,2000,
    nMax_+1,0,1,true);

  BookHistArray(TPHT_vs_BadJetECALDR_,
    "TPHT_vs_BadJetECALDR",
    ";TPHT;BadJetECALDR;",
    400,0,2000,
    200,0,10,
    nMax_+1,0,1,true);


  BookHistArray( BiasedDphi_,
     "BiasedDeltaPhi",
     ";#Delta #phi^{*} (rad); Events/0.05 rad;",
     60, 0., TMath::Pi(),
     nMax_+1, 0, 1, true );

  BookHistArray( EtaPhi_realDeadECAL_,
     "EtaPhi_realDeadECAL",
     ";#eta;#phi;",
     100,-5,5,
     20*(TMath::Pi()),-(TMath::Pi()),TMath::Pi(),
     nMax_+1,0,1,true);

  BookHistArray( EtaPhi_DeadECAL_,
     "EtaPhi_DeadECAL",
     ";#eta;#phi;",
     100,-5,5,
     20*(TMath::Pi()),-(TMath::Pi()),TMath::Pi(),
     nMax_+1,0,1,true);

  BookHistArray(MisMeasured_Eta_Phi_,
    "MisMeasured_Eta_Phi",
    ";#eta;#phi;",
     100,-5,5,
     20*(TMath::Pi()),-(TMath::Pi()),TMath::Pi(),
     nMax_+1,0,1,true);
  
}




//=====================================================================
//Plotting Operation
//====================================================================


bool DarrenPlots::MHTMETPlots( Event::Data& ev) {


  UInt_t n =ev.CommonObjects().size();
  if(n > nMax_) n = nMax_;
  if(n < nMin_) n = nMin_;
  Double_t weight = ev.GetEventWeight();


  double threshold = 50;

  LorentzV calomet = LorentzV(*ev.metP4caloTypeII());
  PolarLorentzV mHT(0.,0.,0.,0.);

if ( MHTMETPlots_ ){


  std::vector<Event::Jet const *>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
  std::vector<Event::Jet const *>::const_iterator jjet = ev.JD_CommonJets().accepted.end();
  std::vector<Event::Jet const *>::const_iterator ibaby = ev.JD_CommonJets().baby.begin();
  std::vector<Event::Jet const *>::const_iterator jbaby = ev.JD_CommonJets().baby.end();
  for(; ijet!=jjet; ++ijet){
    if( (*ijet)->Pt() > threshold){
      mHT -= (**ijet);
    }
  }
  for( ; ibaby!=jbaby; ++ibaby){
    if( (*ibaby)->pt() > threshold ){
      mHT -= (**ibaby);
    }
  }


  for(int i = 0; i < int(ev.LD_CommonElectrons().accepted.size());i++){
    calomet = calomet+(*ev.LD_CommonElectrons().accepted[i]);
  }
  for(int i = 0; i < int(ev.PD_CommonPhotons().accepted.size());i++){
    calomet = calomet+(*ev.PD_CommonPhotons().accepted[i]);
  }
  for(int i = 0; i < int(ev.LD_CommonMuons().accepted.size());i++){
    calomet = calomet+(*ev.LD_CommonMuons().accepted[i]);
  }





if( n >= nMin_ && n <= nMax_ && n < MHTOvCaloMET_.size()  ) {
      MHTOvCaloMET_[0]->Fill( mHT.Pt()/calomet.Pt(), weight);
      MHTOvCaloMET_[n]->Fill( mHT.Pt()/calomet.Pt(), weight);
}
    BiasedDphi_pT50GeV_[0]->Fill(ev.CommonMinBiasDPhi(),weight);
    BiasedDphi_pT50GeV_[n]->Fill(ev.CommonMinBiasDPhi(),weight);
}
return true;
}

// MHT Plots =======================================================


bool DarrenPlots::MHTPlots( Event::Data& ev) {

  UInt_t n =ev.CommonObjects().size();
  if(n > nMax_) n = nMax_;
  if(n < nMin_) n = nMin_;
  Double_t weight = ev.GetEventWeight();

if ( MHTPlots_ ){

  MHT_[0]->Fill( ev.CommonMHT().Pt(), weight );
  MHT_[n]->Fill( ev.CommonMHT().Pt(), weight );

  CaloMHT_[0]->Fill( (*ev.metP4caloTypeII()).Pt(), weight );
  CaloMHT_[n]->Fill( (*ev.metP4caloTypeII()).Pt(), weight );
 
  AlphaT_[0]->Fill ( ev.CommonAlphaT(), weight );
  AlphaT_[n]->Fill ( ev.CommonAlphaT(), weight );


  HT_[0]->Fill( ev.CommonHT(), weight );
  HT_[n]->Fill( ev.CommonHT(), weight );   
  }
return true;
}



bool DarrenPlots::CleaningPlots( Event::Data& ev) {
  
  UInt_t n = ev.CommonObjects().size();
  if(n > nMax_) n = nMax_;
  if(n < nMin_) n = nMin_;


  Double_t weight = ev.GetEventWeight();

  Double_t TPMHT = 0;
  Double_t TPHT = 0;

  int idx = 0;

  LorentzV mht;
  mht.SetPxPyPzE(0.,0.,0.,0.);

  //  cout << " size " << ev.ecalDeadTowerNBadXtals()->size() << endl;
  if(CleaningPlots_){


    double biasedDPhi = 100;
    float ECALDR = 100;
    float deadECALDR = 100;
    float allminECALDR = 100;

    std::string deadfile = deadECALFile_;


    //Calculate TP HT and MHT
    try{
      // cout << " size " << ev.ecalDeadTowerTrigPrimP4()->size() << endl;
      for(std::vector<PolarLorentzV>::const_iterator ii=ev.ecalDeadTowerTrigPrimP4()->begin();ii!=ev.ecalDeadTowerTrigPrimP4()->end();++ii,++idx){

    if((*ii).E() != 0){
      TPHT = TPHT+ (*ii).Et();
      mht-=(*ii);
    }
    if(ev.ecalDeadTowerNBadXtals()->at(idx) >= deadECAL_nBadCellsCut_){
      EtaPhi_realDeadECAL_[0]->Fill((*ii).Eta(),(*ii).Phi(),weight);
      EtaPhi_realDeadECAL_[n]->Fill((*ii).Eta(),(*ii).Phi(),weight);
    }

      }
      TPMHT = fabs(mht.Et());

    }
    catch(...){}

    //calculate MHT take into account babyJets
    LorentzV loweredMHT = ev.CommonRecoilMET();
    for(std::vector<Event::Jet const*>::const_iterator iM = ev.JD_CommonJets().baby.begin();iM != ev.JD_CommonJets().baby.end();++iM){
      if( (*iM)->Pt() > deadECAL_minJetPTCut_)loweredMHT -= (**iM);
    }


    std::vector<LorentzV> Dphicollection(); 
    Double_t minEta = 0;
    Double_t minPhi = 0;


    //calculate min DR to dead ECAL
    for( std::vector<Event::Jet const *>::const_iterator i = ev.JD_CommonJets().accepted.begin();
   i != ev.JD_CommonJets().accepted.end();
   ++i ){

      float newBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**i,loweredMHT + (**i))) ;

      try{ECALDR = DeadECALDR(ev,(*i)->Phi(),(*i)->Eta(),deadECAL_nBadCellsCut_);}
      catch(...){ECALDR = DeadECALDR_File(deadfile,(*i)->Phi(),(*i)->Eta(),deadECAL_nBadCellsCut_);}

      if(ECALDR < allminECALDR) allminECALDR = ECALDR;

      if(newBiasDPhi < 0.5){
  biasedDPhi = newBiasDPhi;
  deadECALDR = ECALDR;

  EtaPhi_DeadECAL_[0]->Fill((*i)->Eta(),(*i)->Phi(),weight);
  EtaPhi_DeadECAL_[n]->Fill((*i)->Eta(),(*i)->Phi(),weight);

//Dphicollection.push_back(i.);

  minEta = (*i)->Eta();
  minPhi = (*i)->Phi();

      }
    }

    for( std::vector<Event::Jet const*>::const_iterator iI = ev.JD_CommonJets().baby.begin(); iI != ev.JD_CommonJets().baby.end();
   ++iI) {
      if((*iI)->Pt() > deadECAL_minJetPTCut_){
  float newBiasDPhi_2 = fabs(ROOT::Math::VectorUtil::DeltaPhi(**iI, loweredMHT + (**iI) )) ;

  try{ECALDR = DeadECALDR(ev,(*iI)->Phi(),(*iI)->Eta(),deadECAL_nBadCellsCut_);}
  catch(...){ECALDR = DeadECALDR_File(deadfile,(*iI)->Phi(),(*iI)->Eta(),deadECAL_nBadCellsCut_);}

  if(ECALDR < allminECALDR)   allminECALDR = ECALDR;

  if(newBiasDPhi_2 < 0.5){
    biasedDPhi = newBiasDPhi_2;
   
  EtaPhi_DeadECAL_[0]->Fill((*iI)->Eta(),(*iI)->Phi(),weight);
  EtaPhi_DeadECAL_[n]->Fill((*iI)->Eta(),(*iI)->Phi(),weight);
     
   
   //Dphicollection.push_back(iI);
    deadECALDR = ECALDR;

    minEta = (*iI)->Eta();
    minPhi = (*iI)->Phi();

  }
      }
    }

//=================================================================================

    MisMeasured_Eta_Phi_[0]->Fill(minEta,minPhi,weight);
    MisMeasured_Eta_Phi_[n]->Fill(minEta,minPhi,weight);


    if( biasedDPhi < deadECAL_minBiasCut_){
  BadJetECALDR_[0]->Fill(deadECALDR,weight);
  BadJetECALDR_[n]->Fill(deadECALDR,weight);

  allMinECALDR_[0]->Fill(allminECALDR,weight);
  allMinECALDR_[n]->Fill(allminECALDR,weight);

  TPHT_vs_BadJetECALDR_[0]->Fill(TPHT,deadECALDR,weight );
  TPHT_vs_BadJetECALDR_[n]->Fill(TPHT,deadECALDR,weight );

      }


      TPMHT_[0]->Fill( TPMHT, weight );
      TPMHT_[n]->Fill( TPMHT, weight );

      TPHT_[0]->Fill( TPHT, weight );
      TPHT_[n]->Fill( TPHT, weight );


      TPMHTRatio_[0]->Fill( ev.CommonMHT().Et()/(ev.CommonMHT()+mht).Et(),weight);
      TPMHTRatio_[n]->Fill( ev.CommonMHT().Et()/(ev.CommonMHT()+mht).Et(),weight);


      BiasedDphi_[0]->Fill(biasedDPhi, weight );
      BiasedDphi_[n]->Fill(biasedDPhi, weight );


      /*
      ostrm <<" NEW EVENT" << endl <<endl;
      ostrm <<"Run: "<< ev.RunNumber() <<" Event: " << ev.EventNumber() << " LS: " << ev.LumiSection() <<endl;

      ostrm << " TPHT " << TPHT << " dead ECAL DR " << deadECALDR << " eta " << minEta << " phi " << minPhi << " biased delta Phi " << biasedDPhi << endl;

      ostrm << " list of dead ECAL cells " << endl;

      int idx = 0;
      for(std::vector<PolarLorentzV>::const_iterator ii=ev.ecalDeadTowerTrigPrimP4()->begin();ii!=ev.ecalDeadTowerTrigPrimP4()->end();++ii,++idx){
  ostrm << " idx " << idx << " ET " << (*ii).Et() << " eta " << (*ii).Eta() << " Phi " << (*ii).Phi() << " number bad crystals " <<  ev.ecalDeadTowerNBadXtals()->at(idx) << " status " << ev.ecalDeadTowerMaxStatus()->at(idx) << endl;

      }
      */
  }


  return true;
}



//=========================================================================================
//=========================================================================================

  
 
 
