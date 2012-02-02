#include "TanjaCCControlPlots.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include <sstream>
#include <string>
#include <iomanip>

using namespace Operation;

// -----------------------------------------------------------------------------
//
TanjaCCControlPlots::TanjaCCControlPlots( const Utils::ParameterSet& ps ) :
  // Misc
  dirName_( ps.Get<std::string>("DirectoryName") )
{}

// -----------------------------------------------------------------------------
//
TanjaCCControlPlots::~TanjaCCControlPlots() {}

// -----------------------------------------------------------------------------
//
void TanjaCCControlPlots::Start( Event::Data& ev ) {
    initDir( ev.OutputFile(), dirName_.c_str() );
    BookHistos();
}

// -----------------------------------------------------------------------------
//
void TanjaCCControlPlots::BookHistos() {


 BookHistArray( hCC_MHT_, 
		 "CC_MHT", 
		 "H_{T}^{miss} [GeV/c]",
		 50, 0., 1000.,
		 3, 0, 1, false );

  BookHistArray( hCC_MHTovHT_, 
		 "CC_MHTovHT", 
		 "H_{T}^{miss}/H_{T}",
		 50, 0., 1.,
		 1, 0, 1, false );

  BookHistArray( hCC_alphaT_, 
		 "CC_alphaT", 
		 "#alpha_{T}",
		 15, 0., 3.,
		 1, 0, 1, false );

  //ele jet plots
  BookHistArray( hCCEleJet_CombRelIso_, 
		 "CCEleJet_CombRelIso", 
		 "CombRelIso",
		 100, 0., 1.,
		 2, 0, 1, false );
  BookHistArray( hCCEleJet_Mult_, 
		 "CCEleJet_Mult", 
		 "Mult",
		 5, 0., 5.,
		 1, 0, 1, false );
  //one plot for [0] tight id object<->matched jet,[1] loose id object<->matched jet,[2] no id object<->matched jet,
  // [3] tight id object<->non matched jet, [4]loose id object<->non matched jet,[5] no id object<->non matched jet,
  BookHistArray( hCCEleJet_MinDeltaR_vs_Pt_, 
		"CCEleJet_MinDeltaR_vs_Pt", 
		"#DeltaR(jet,object)",
		 600,0., 6.,200, 0., 200.,
		 6, 0, 1, false );

  BookHistArray( hCCEleJet_MHT_, 
		 "CCEleJet_MHT", 
		 "H_{T}^{miss} [GeV/c]",
		 50, 0., 1000.,
		 3, 0, 1, false );

  BookHistArray( hCCEleJet_MHTovHT_, 
		 "CCEleJet_MHTovHT", 
		 "H_{T}^{miss}/H_{T}",
		 50, 0., 1.,
		 1, 0, 1, false );

  BookHistArray( hCCEleJet_alphaT_, 
		 "CCEleJet_alphaT", 
		 "#alpha_{T}",
		 15, 0., 3.,
		 1, 0, 1, false );


  //photon jet plots
  BookHistArray( hCCPhotJet_CombRelIso_, 
		 "CCPhotJet_CombRelIso", 
		 "CombRelIso",
		 500, 0., 5.,
		 2, 0, 1, false );
  BookHistArray( hCCPhotJet_Mult_, 
		 "CCPhotJet_Mult", 
		 "Mult",
		 5, 0., 5.,
		 1, 0, 1, false );
  //one plot for [0] tight id object<->matched jet,[1] loose id object<->matched jet,[2] no id object<->matched jet,
  // [3] tight id object<->non matched jet, [4]loose id object<->non matched jet,[5] no id object<->non matched jet,
  BookHistArray( hCCPhotJet_MinDeltaR_vs_Pt_, 
		"CCPhotJet_MinDeltaR_vs_Pt", 
		"#DeltaR(jet,object)",
		 600, 0., 6.,200, 0., 200.,
		 6, 0, 1, false ); 

  BookHistArray( hCCPhotJet_MHT_, 
		 "CCPhotJet_MHT", 
		 "H_{T}^{miss} [GeV/c]",
		 50, 0., 1000.,
		 3, 0, 1, false );

  BookHistArray( hCCPhotJet_MHTovHT_, 
		 "CCPhotJet_MHTovHT", 
		 "H_{T}^{miss}/H_{T}",
		 50, 0., 1.,
		 1, 0, 1, false );

  BookHistArray( hCCPhotJet_alphaT_, 
		 "CCPhotJet_alphaT", 
		 "#alpha_{T}",
		 15, 0., 3.,
		 1, 0, 1, false );


  //mu jet plots
  BookHistArray( hCCMuJet_CombRelIso_, 
		 "CCMuJet_CombRelIso", 
		 "CombRelIso",
		 10, 0., 1.,
		 2, 0, 1, false );
  BookHistArray( hCCMuJet_Mult_, 
		 "CCMuJet_Mult", 
		 "Mult",
		 10, 0., 10.,
		 1, 0, 1, false );
  BookHistArray( hCCMuJet_DeltaPtovPt_, 
		 "CCMuJet_DeltaPtovPt", 
		 "Mult",
		 40, -2., 2.,
		 2, 0, 1, false );

  BookHistArray( hCCMuJet_MHT_, 
		 "CCMuJet_MHT", 
		 "H_{T}^{miss} [GeV/c]",
		 50, 0., 1000.,
		 3, 0, 1, false );

  BookHistArray( hCCMuJet_MHTovHT_, 
		 "CCMuJet_MHTovHT", 
		 "H_{T}^{miss}/H_{T}",
		 50, 0., 1.,
		 1, 0, 1, false );

  BookHistArray( hCCMuJet_alphaT_, 
		 "CCMuJet_alphaT", 
		 "#alpha_{T}",
		 15, 0., 3.,
		 1, 0, 1, false );

   //one plot for [0] tight id object<->matched jet,[1] loose id object<->matched jet,[2] no id object<->matched jet,
  // [3] tight id object<->non matched jet, [4]loose id object<->non matched jet,[5] no id object<->non matched jet,
  BookHistArray( hCCMuJet_MinDeltaR_vs_Pt_, 
		"CCMuJet_MinDeltaR_vs_Pt", 
		"#DeltaR(jet,object)",
		 600, 0., 6.,60, 0., 60.,
		 6, 0, 1, false );


}


// -----------------------------------------------------------------------------
//
bool TanjaCCControlPlots::Process( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();

  // Recoil MET from common objects
  LorentzV common_met = ev.CommonRecoilMET();

  // Recoil MET from raw ntuple objects
  LorentzV raw_met = RecoilMET(ev);

 

  // Calo MET from ntuple
  LorentzV calo_met = ev.CaloMET();

  // double diff1 = ( fabs(common_met.Pt()) - fabs(raw_met.Pt()) ) / fabs(raw_met.Pt());

  // double diff2 = ( fabs(common_met.Pt()) - fabs(calo_met.Pt()) ) / fabs(calo_met.Pt());

  //non cc jets non corrected jets?
  std::vector<Event::Jet>::const_iterator accijet = ev.JD_Jets().begin();
  std::vector<Event::Jet>::const_iterator accjjet = ev.JD_Jets().end();

  //non cc electrons
  std::vector<Event::Lepton const*>::const_iterator ielectron = ev.LD_CommonElectrons().accepted.begin();
  std::vector<Event::Lepton const*>::const_iterator jelectron = ev.LD_CommonElectrons().accepted.end();

  //non cc muons
  std::vector<Event::Lepton const*>::const_iterator imuon = ev.LD_CommonMuons().accepted.begin();
  std::vector<Event::Lepton const*>::const_iterator jmuon = ev.LD_CommonMuons().accepted.end();
 

  //non cc photons
  std::vector<Event::Photon const*>::const_iterator iphoton = ev.PD_CommonPhotons().accepted.begin();
  std::vector<Event::Photon const*>::const_iterator jphoton = ev.PD_CommonPhotons().accepted.end();
  


  //cc electrons
  std::vector<Event::Lepton const*>::const_iterator ccielectron = ev.CC().Electrons.begin();
  std::vector<Event::Lepton const*>::const_iterator ccjelectron = ev.CC().Electrons.end();

  //cc jets
  std::vector<Event::Jet const*>::const_iterator ccijet = ev.CC().Jets.begin();
  std::vector<Event::Jet const*>::const_iterator ccjjet = ev.CC().Jets.end(); 

  //cc muons
  std::vector<Event::Lepton const*>::const_iterator ccimuon = ev.CC().Muons.begin();
  std::vector<Event::Lepton const*>::const_iterator ccjmuon = ev.CC().Muons.end();

   //cc photons
  std::vector<Event::Photon const*>::const_iterator cciphoton = ev.CC().Photons.begin();
  std::vector<Event::Photon const*>::const_iterator ccjphoton = ev.CC().Photons.end();

  //accepted (pt,eta,id) jets
  std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
  std::vector<Event::Jet const*>::const_iterator jjet = ev.JD_CommonJets().accepted.end();

 


  bool eleIsTight = false;
    bool eleIsLoose= false;
    bool eleIsNon = false;

    bool muIsTight = false;
    bool muIsLoose= false ;
    bool muIsNon= false ;

    bool photIsTight= false;
    bool photIsLoose= false;
    bool photIsNon= false;

    Double_t elePt =-1;
    Double_t muPt=-1;
    Double_t photPt=-1;

    //Fill General quantities
    hCC_MHT_[0]->Fill( fabs(raw_met.Pt()),weight);
    hCC_MHT_[1]->Fill( fabs(common_met.Pt()),weight);
    hCC_MHT_[2]->Fill( fabs(calo_met.Pt()),weight);
    hCC_MHTovHT_[0]->Fill( fabs(common_met.Pt())/ev.CommonSumEt(),weight);

  

    hCCEleJet_Mult_[0]->Fill(ev.LD_CommonElectrons().accepted.size() ,weight);
    hCCMuJet_Mult_[0]->Fill(ev.LD_CommonMuons().accepted.size() ,weight);
    hCCPhotJet_Mult_[0]->Fill(ev.PD_CommonPhotons().accepted.size() ,weight);


    // cout << " before alphaT " << endl;
    if(ev.CommonObjects().size() > 1 && ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN())hCC_alphaT_[0]->Fill(ev.CommonAlphaT(),weight); 
      
    // cout << " here " << endl;
   
  //Electron Jet Cross-cleaning*****************************************************************

  
  //calculate Delta R

  Double_t EleJetDeltaR = 100;
  Int_t EleJetindex = -1; 

  Double_t MuJetDeltaR = 100;
  Int_t MuJetindex = -1; 

  Double_t PhotJetDeltaR = 100;
  Int_t PhotJetindex = -1; 


 //iterate over non-cc jets
  for ( ; accijet != accjjet; ++accijet ) {




  }

  //iterate over non-cc jets
  for ( ; ijet != jjet; ++ijet ) {

   

   

    /*if((*ccijet)){
      cout << " jet pt " << (*ijet)->Pt() << " cross-cleaned jet pt " << (*ccijet)->Pt() << endl;
      cout << " jet index " << (*ijet)->GetIndex() << " cross-cleaned jet index " << (*ccijet)->GetIndex() << endl;
      }*/

    // cout << " in jet loop " << endl;

    EleJetDeltaR = 100;
    EleJetindex = -1;

    MuJetDeltaR = 100;
    MuJetindex = -1;

    PhotJetDeltaR = 100;
    PhotJetindex = -1;
      
   

    for (  ielectron = ev.LD_CommonElectrons().accepted.begin(); ielectron != jelectron; ++ielectron ) {	
      if( ROOT::Math::VectorUtil::DeltaR(*(*ijet),*(*ielectron)) < EleJetDeltaR){
	EleJetDeltaR = ROOT::Math::VectorUtil::DeltaR(*(*ijet),*(*ielectron)) ; 
	EleJetindex = (*ielectron)->GetIndex();
      }//end asking for deltaR jet electron	
    }//end loop over non-cc electrons

  

    for ( imuon = ev.LD_CommonMuons().accepted.begin(); imuon != jmuon; ++imuon ) {	
      if( ROOT::Math::VectorUtil::DeltaR(*(*ijet),*(*imuon)) < MuJetDeltaR){
	MuJetDeltaR = ROOT::Math::VectorUtil::DeltaR(*(*ijet),*(*imuon)) ; 
	MuJetindex = (*imuon)->GetIndex();
      }//end asking for deltaR jet muon	
    }//end loop over non-cc muon

  

    for ( iphoton = ev.PD_CommonPhotons().accepted.begin(); iphoton != jphoton; ++iphoton ) {	
      if( ROOT::Math::VectorUtil::DeltaR(*(*ijet),*(*iphoton)) < PhotJetDeltaR){
	PhotJetDeltaR = ROOT::Math::VectorUtil::DeltaR(*(*ijet),*(*iphoton)) ; 
	PhotJetindex = (*iphoton)->GetIndex();
      }//end asking for deltaR jet muon	
    }//end loop over non-cc muon
 
    //  cout << " here2 " << endl;

    int isJetMatched = ev.genJetMatchIndex()->at((*ijet)->GetIndex()); //-1 jet is not matched to gen jet

   


    if(EleJetindex != -1){
      eleIsTight = ((ev.LD_Electrons())[EleJetindex]).GetTightId();
      eleIsLoose = ((ev.LD_Electrons())[EleJetindex]).GetLooseId();
      eleIsNon = (!eleIsTight && !eleIsLoose);
      elePt = ((ev.LD_Electrons())[EleJetindex]).Pt();
    }

    if(MuJetindex != -1){
      muIsTight = ((ev.LD_Muons())[MuJetindex]).GetTightId();
      muIsLoose = ((ev.LD_Muons())[MuJetindex]).GetLooseId();
      muIsNon = (!muIsTight && !muIsLoose);
      muPt = ((ev.LD_Muons())[MuJetindex]).Pt();
    }

    if(PhotJetindex != -1){
      photIsTight = ((ev.PD_Photons())[PhotJetindex]).IsItTight();
      photIsLoose = ((ev.PD_Photons())[PhotJetindex]).IsItLoose();
      photIsNon = (!photIsTight && !photIsLoose);
      photPt = ((ev.PD_Photons())[PhotJetindex]).Pt();
    }


 
   
   

    // min delta R vs pT 2d Histo
    if((*ijet)->Pt() > 10){ //only fill for jets with pT > 10 GeV

      //   cout << " here4 " << endl;

      //Fill ele jet minDeltaR pt Hist

  if(EleJetindex != -1){
      if(eleIsTight && isJetMatched != -1 ) hCCEleJet_MinDeltaR_vs_Pt_[0]->Fill(EleJetDeltaR,elePt,weight);
      if(eleIsLoose && isJetMatched != -1 ) hCCEleJet_MinDeltaR_vs_Pt_[1]->Fill(EleJetDeltaR,elePt,weight);
      if(eleIsNon && isJetMatched != -1 ) hCCEleJet_MinDeltaR_vs_Pt_[2]->Fill(EleJetDeltaR,elePt,weight);
      
      if(eleIsTight && isJetMatched == -1 ) hCCEleJet_MinDeltaR_vs_Pt_[3]->Fill(EleJetDeltaR,elePt,weight);
      if(eleIsLoose && isJetMatched == -1 ) hCCEleJet_MinDeltaR_vs_Pt_[4]->Fill(EleJetDeltaR,elePt,weight);
      if(eleIsNon && isJetMatched == -1 ) hCCEleJet_MinDeltaR_vs_Pt_[5]->Fill(EleJetDeltaR,elePt,weight);
  }
  //  cout << " here5 " << endl;

  //Fill mu jet minDeltaR pt Hist
  if(MuJetindex != -1){
      if(muIsTight && isJetMatched != -1 ) hCCMuJet_MinDeltaR_vs_Pt_[0]->Fill(MuJetDeltaR,muPt,weight);
      if(muIsLoose && isJetMatched != -1 ) hCCMuJet_MinDeltaR_vs_Pt_[1]->Fill(MuJetDeltaR,muPt,weight);
      if(muIsNon && isJetMatched != -1 ) hCCMuJet_MinDeltaR_vs_Pt_[2]->Fill(MuJetDeltaR,muPt,weight);
      
      if(muIsTight && isJetMatched == -1 ) hCCMuJet_MinDeltaR_vs_Pt_[3]->Fill(MuJetDeltaR,muPt,weight);
      if(muIsLoose && isJetMatched == -1 ) hCCMuJet_MinDeltaR_vs_Pt_[4]->Fill(MuJetDeltaR,muPt,weight);
      if(muIsNon && isJetMatched == -1 ) hCCMuJet_MinDeltaR_vs_Pt_[5]->Fill(MuJetDeltaR,muPt,weight);
  }
  // cout << " here5 " << endl;

      //Fill phot jet minDeltaR pt Hist
  if(PhotJetindex != -1){
      if(photIsTight && isJetMatched != -1 ) hCCPhotJet_MinDeltaR_vs_Pt_[0]->Fill(PhotJetDeltaR,photPt,weight);
      if(photIsLoose && isJetMatched != -1 ) hCCPhotJet_MinDeltaR_vs_Pt_[1]->Fill(PhotJetDeltaR,photPt,weight);
      if(photIsNon && isJetMatched != -1 ) hCCPhotJet_MinDeltaR_vs_Pt_[2]->Fill(PhotJetDeltaR,photPt,weight);
      
      if(photIsTight && isJetMatched == -1 ) hCCPhotJet_MinDeltaR_vs_Pt_[3]->Fill(PhotJetDeltaR,photPt,weight);
      if(photIsLoose && isJetMatched == -1 ) hCCPhotJet_MinDeltaR_vs_Pt_[4]->Fill(PhotJetDeltaR,photPt,weight);
      if(photIsNon && isJetMatched == -1 ) hCCPhotJet_MinDeltaR_vs_Pt_[5]->Fill(PhotJetDeltaR,photPt,weight);
  }
      
    }

    //  cout << " hereEle " << endl;

    if(EleJetDeltaR < 0.5){//if ele jet in 0.5 cone

      hCCEleJet_MHT_[0]->Fill( fabs(raw_met.Pt()),weight);
      hCCEleJet_MHT_[1]->Fill( fabs(common_met.Pt()),weight);
      hCCEleJet_MHT_[2]->Fill( fabs(calo_met.Pt()),weight);

      hCCEleJet_MHTovHT_[0]->Fill( fabs(common_met.Pt())/ev.CommonSumEt(),weight);

      if(ev.CommonObjects().size() > 1 && ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN())hCCEleJet_alphaT_[0]->Fill(ev.CommonAlphaT(),weight); 
      
      if(((ev.LD_Electrons())[EleJetindex]).Pt() > 30) hCCEleJet_CombRelIso_[0]->Fill(((ev.LD_Electrons())[EleJetindex]).GetCombIsolation(),weight);
      hCCEleJet_Mult_[0]->Fill(ev.LD_CommonElectrons().accepted.size()
      ,weight);

    }
    else if(EleJetindex != -1 && ((ev.LD_Electrons())[EleJetindex]).Pt() > 30) hCCEleJet_CombRelIso_[1]->Fill(((ev.LD_Electrons())[EleJetindex]).GetCombIsolation(),weight);


    
  
   
    // if(genIndex != -1)cout << " index " << (*ijet)->GetIndex() << " size " << ev.JD_Jets().size() << " gen pt " << pt_gen << " raw pt " << pt_raw << " pt " << pt << endl;
   
    
     if(MuJetDeltaR < 0.2){//if ele jet in 0.5 cone

      hCCMuJet_MHT_[0]->Fill( fabs(raw_met.Pt()),weight);
      hCCMuJet_MHT_[1]->Fill( fabs(common_met.Pt()),weight);
      hCCMuJet_MHT_[2]->Fill( fabs(calo_met.Pt()),weight);

      hCCMuJet_MHTovHT_[0]->Fill( fabs(common_met.Pt())/ev.CommonSumEt(),weight);

      if(ev.CommonObjects().size() > 1 && ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN())hCCMuJet_alphaT_[0]->Fill(ev.CommonAlphaT(),weight); 

    	Int_t genIndex = ev.genJetMatchIndex()->at((*ijet)->GetIndex());

	Double_t pt_raw = (*ijet)->Pt();

	Double_t pt_cc = (*ccijet)->Pt() ;


	if( pt_raw != pt_cc) cout << " raw pt " << pt_raw <<  " pt_cc " << pt_cc << endl;

      if(genIndex != -1){



	Double_t pt_gen = ((ev.genJetP4()->at(genIndex)).Pt());



	//	cout << " pt_gen - pt " << 
	
	if( pt_raw != pt_cc){
	  cout << " raw pt " << pt_raw << " pt gen " << pt_gen << " pt_cc " << pt_cc << endl;
	  hCCMuJet_DeltaPtovPt_[0]->Fill(( pt_gen - pt_cc)/pt_gen);
	  hCCMuJet_DeltaPtovPt_[1]->Fill(( pt_gen - pt_raw)/ pt_gen);
	}
	//	cout << " after " << endl;
	//cout << " delta pt ov pt " << ((ev.genJetP4()->at(genIndex)).Pt() - (*ijet).Pt())/(*ijet).Pt() << endl;
	//	hCCMuJet_DeltaPtovPt_[1]->Fill(((ev.genJetP4()->at(genIndex)).Pt() -  ((ev.JD_CommonJets().accepted).at((*ijet).GetIndex()))->Pt())/((ev.genJetP4()->at(genIndex)).Pt()));
      }


      /*   if(((ev.LD_Muons())[MuJetindex]).Pt() > 30)cout << " comb iso " << ((ev.LD_Muons())[MuJetindex]).GetCombIsolation() << endl;
      if(((ev.LD_Muons())[MuJetindex]).Pt() > 30)cout << " track rel " << ((ev.LD_Muons())[MuJetindex]).GetTrkIsolation()/((ev.LD_Muons())[MuJetindex]).Pt() << endl;
      if(((ev.LD_Muons())[MuJetindex]).Pt() > 30)cout << " ECAL rel " << ((ev.LD_Muons())[MuJetindex]).GetEcalIsolation()/((ev.LD_Muons())[MuJetindex]).Et() << endl;
      if(((ev.LD_Muons())[MuJetindex]).Pt() > 30)cout << " HCAL rel " << ((ev.LD_Muons())[MuJetindex]).GetHcalIsolation()/((ev.LD_Muons())[MuJetindex]).Et() << endl;
      */


      if(((ev.LD_Muons())[MuJetindex]).Pt() > 30)hCCMuJet_CombRelIso_[0]->Fill(((ev.LD_Muons())[MuJetindex]).GetCombIsolation(),weight);
      

     }else {
       //cout << " Mu jet index " << MuJetindex << " size " << ev.LD_Muons().size() << endl;
       if(MuJetindex != -1 && ((ev.LD_Muons())[MuJetindex]).Pt() > 30)hCCMuJet_CombRelIso_[1]->Fill(((ev.LD_Muons())[MuJetindex]).GetCombIsolation(),weight);
     }
    
     // cout << " herePhot " << endl;
     if(PhotJetDeltaR < 0.5){//if ele jet in 0.5 cone

       hCCPhotJet_MHT_[0]->Fill( fabs(raw_met.Pt()),weight);
       hCCPhotJet_MHT_[1]->Fill( fabs(common_met.Pt()),weight);
       hCCPhotJet_MHT_[2]->Fill( fabs(calo_met.Pt()),weight);

      hCCPhotJet_MHTovHT_[0]->Fill( fabs(common_met.Pt())/ev.CommonSumEt(),weight);

      if(ev.CommonObjects().size() > 1 && ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN())hCCPhotJet_alphaT_[0]->Fill(ev.CommonAlphaT(),weight); 
      
      hCCPhotJet_CombRelIso_[0]->Fill( ((ev.PD_Photons())[PhotJetindex]).GetCaloIsolation() /  ((ev.PD_Photons())[PhotJetindex]).Pt(),weight);
     

     }else if(PhotJetindex != -1)hCCPhotJet_CombRelIso_[1]->Fill( ((ev.PD_Photons())[PhotJetindex]).GetCaloIsolation() /  ((ev.PD_Photons())[PhotJetindex]).Pt(),weight);
         
     //  cout << " endPhot " << endl;

  

  }//end loop over non-cc jets



  ++ccijet;
  
  
  return true;
}


// -----------------------------------------------------------------------------
//
std::ostream& TanjaCCControlPlots::Description( std::ostream& ostrm ) {
  ostrm << "Crosscleaning Control Plots ";
  return ostrm;
}


// -----------------------------------------------------------------------------
//
LorentzV TanjaCCControlPlots::RecoilMET( Event::Data& ev ) {
  
  LorentzV mData(0.,0.,0.,0.);

  std::vector<Event::Jet>::const_iterator ijet = ev.JD_Jets().begin();
  std::vector<Event::Jet>::const_iterator jjet = ev.JD_Jets().end();
  for ( ; ijet != jjet; ++ijet ) { mData -= (*ijet); }

  std::vector<Event::Lepton>::const_iterator imuon = ev.LD_Muons().begin();
  std::vector<Event::Lepton>::const_iterator jmuon = ev.LD_Muons().end();
  for ( ; imuon != jmuon; ++imuon ) { mData -= (*imuon); }
  
  std::vector<Event::Lepton>::const_iterator ielectron = ev.LD_Electrons().begin();
  std::vector<Event::Lepton>::const_iterator jelectron = ev.LD_Electrons().end();
  for ( ; ielectron != jelectron; ++ielectron ) { mData -= (*ielectron); }
    
  std::vector<Event::Photon>::const_iterator iphoton = ev.PD_Photons().begin();
  std::vector<Event::Photon>::const_iterator jphoton = ev.PD_Photons().end();
  for ( ; iphoton != jphoton; ++iphoton ) { mData -= (*iphoton); }
  
  return mData;

}
