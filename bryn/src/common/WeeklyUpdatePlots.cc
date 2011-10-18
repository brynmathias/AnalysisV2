#include "WeeklyUpdatePlots.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include "mt2_bisect.hh"
#include "AlphaT.hh"
#include "Jet.hh"
#include "Math/VectorUtil.h"
#include "JetData.hh"
#include "TMath.h"

using namespace Operation;

// -----------------------------------------------------------------------------
WeeklyUpdatePlots::WeeklyUpdatePlots( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
// MT2
  StandardPlots_( ps.Get<bool>("StandardPlots") )

  {}

// -----------------------------------------------------------------------------
//
WeeklyUpdatePlots::~WeeklyUpdatePlots() {}

// -----------------------------------------------------------------------------
//
void WeeklyUpdatePlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void WeeklyUpdatePlots::BookHistos() {
  if ( StandardPlots_ )           { StandardPlots(); }
}

// -----------------------------------------------------------------------------
//
bool WeeklyUpdatePlots::Process( Event::Data& ev ) {
  if ( StandardPlots_ )               { StandardPlots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& WeeklyUpdatePlots::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void WeeklyUpdatePlots::StandardPlots() {


  BookHistArray( HT_vs_SecondJetPt_,
    "HT_vs_secondJetPt",
    ";H_{T} (GeV);# p_{T}^{j2} (GeV)",
    120, 0., 3000.,
    240, 0., 1600.,
    nMax_+1, 0, 1, true );


  BookHistArray( HT_vs_SecondJetPt_after_alphaT_,
    "HT_vs_SecondJetPt_after_alphaT",
    ";H_{T} (GeV);# p_{T}^{j2} (GeV)",
    120, 0., 3000.,
    240, 0., 1600.,
    nMax_+1, 0, 1, true );


  BookHistArray( vertexPtovHT_,
    "vertexPtovHT",
    ";VertexPt / HT (GeV);Events/0.01;",
    1000, 0., 10.,
    nMax_+1, 0, 1, true );

  BookHistArray( DeltaPhiPsudoJets_,
    "DeltaPhiPsudoJets_",
    ";#Delta #phi PsudoJets;Events;",
    1000, 0., 10000.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaTVsNoVertex_,
    "AlphaTVsNoVertex",
    ";;#alpha_{T};No.Vertercies;",
    400,0.,10.,
    10,0.,10,
    nMax_+1, 0, 1, true );

  BookHistArray( NumberVerticiesAfterAlphaT_,
    "Number_Primary_verticies_after_alphaT",
    ";No.Vertercies;Events;",
    10,0.,10,
    nMax_+1, 0, 1, true );

  BookHistArray( NumberVerticies_,
    "Number_Primary_verticies_",
    ";No.Vertercies;Events;",
    10,0.,10,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaTOneVertex_,
    "AlphaTOneVetex",
    ";#alpha_{T};Events/0.025;",
    400,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaTgOneVertex_,
    "AlphaTGreaterOneVetex",
    ";#alpha_{T};Events/0.025;",
    400,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_components_,
    "AlphaT_Components",
    ";#slashed{H}_{T}/H_{T};#Delta)H_{T}/H_{T}",
    20, 0., 1.,
    20, 0., 1.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaTafterPFMEC_,
    "AlphaT_after_PF_MEC",
    ";#alpha_{T};Events/0.025;",
    400,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_Zoomed_afterPFMEC_,
    "AlphaT_Zoomed_after_PF_MEC",
    ";#alpha_{T}; Events/0.0025;",
    60,0.45,0.6,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaTafterCaloMEC_,
    "AlphaT_after_Calo_MEC",
    ";#alpha_{T};Events/0.025;",
    400,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_ZoomedafterCaloMEC_,
    "AlphaT_Zoomed_after_Calo_MEC",
    ";#alpha_{T}; Events/0.0025;",
    60,0.45,0.6,
    nMax_+1, 0, 1, true );

  BookHistArray( DPhi_MHT_MHTBaby_,
    "CosDetlaPhi_MHT_MHTBaby_",
    ";#Delta Cos#phi(MHT,MHTbaby); Events/0.65 rad;",
    40, -1., 1,
    nMax_+1, 0, 1, true );

  BookHistArray( DPhi_MHT_MHTbaby_AfterAlphaT_,
    "DPhi_MHT_MHTbaby_AfterAlphaT_",
    ";Cos #Delta #phi(MHT,MHTbaby); Events/0.65 rad;",
    40, -1., 1.,
    nMax_+1, 0, 1, true );

  BookHistArray( MinBiasDphi_EtaPhiMap_,
    "MinBiasDphi_EtaPhiMap_",
    ";#eta;#phi",
    60, -3., 3.,
    64, -3.2, 3.2,
    nMax_+1, 0, 1, true );

  BookHistArray( DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_,
    "DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_",
    ";Cos #Delta #phi(MHT,MHTbaby);MHTBaby Over MHT",
    40, -1., 1.,
    50, 0., 5.,
    nMax_+1, 0, 1, true );

  BookHistArray( DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_AfterAlphaT_,
    "DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_AfterAlphaT_",
    ";Cos #Delta #phi(MHT,MHTbaby);MHTBaby Over MHT",
    40, -1., 1.,
    50, 0., 5.,
    nMax_+1, 0, 1, true );

  BookHistArray( BabyJetMHT_StandardAlphaT_,
    "BabyJetMHT_vs_AlphaT",
    "Cos(Dphi(MHT,MHTbaby));CommonAlphaT;",
    400,0.,10.,
    20,-1.,1.,
    nMax_+1, 0, 1, true );

  BookHistArray( BabyJetMHT_,
    "BabyJetMHT",
    ";BabyJetMHT;Events/5GeV;",
    60, .0, 300.,
    nMax_+1, 0, 1, true );

  BookHistArray( BabyJetMHTafterMETcut_,
    "BabyJetMHTafterMetCut",
    ";BabyJetMHT;Events/5GeV;",
    60, .0, 300.,
    nMax_+1, 0, 1, true );

  BookHistArray( MissedHT_,
    "MHTRatio_after_alphaT_55",
    ";MHT30/MHT10;Events/0.1;",
    100, 0., 10,
    nMax_+1, 0, 1, true );

  BookHistArray( CaloMET_,
    "CaloMET",
    ";#slash{H}_T (GeV);Events/0.1;",
    100, 0., 1000,
    nMax_+1, 0, 1, true );

  BookHistArray( CaloMET_afteraT_,
    "CaloMET_after_alphaT",
    ";#slash{H}_T (GeV);Events/0.1;",
    100, 0., 1000,
    nMax_+1, 0, 1, true );

  BookHistArray( MHTovMET_raw_,
    "MHTovMET",
    ";MHT/MET;Events/0.1;",
    100, 0., 10,
    nMax_+1, 0, 1, true );

  BookHistArray( MHTovMET_,
    "MHTovMET_afterAlphaT",
    ";MHT/MET;Events/0.1;",
    1000, 0., 100,
    nMax_+1, 0, 1, true );

  BookHistArray( DetlaPhi_LeadingJets_,
    "DetlaPhi_LeadingJets_",
    ";#Delta #phi(j_{1},j_{i}); Events/0.65 rad;",
    40, 0., TMath::Pi(),
    nMax_+1, 0, 1, true );

  BookHistArray( DetlaPhi_NextToLeadingJets_,
    "DetlaPhi_NextToLeadingJets_",
    ";#Delta #phi(j_{2},j_{3}); Events/0.65 rad;",
    40, 0., TMath::Pi(),
    nMax_+1, 0, 1, true );

  BookHistArray( Mt2_LeadingJets_,
    "Mt2_LeadingJets",
    ";M_{T2} (GeV); Events/20 GeV;",
    100, 0., 2000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Mt2_,
    "Mt2",
    ";M_{T2} (GeV); Events/20 GeV;",
    100, 0., 2000.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_Zoomed_,
    "AlphaT_Zoomed",
    ";#alpha_{T}; Events/0.0025;",
    60,0.45,0.6,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_METCut_,
    "AlphaT_after_MHTRatio",
    ";#alpha_{T};Events/0.025;",
    400,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_Zoomed_METCut_,
    "AlphaT_Zoomed_after_MHTRatio",
    ";#alpha_{T}; Events/0.0025;",
    60,0.45,0.6,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphatCut_Meff_,
    "EffectiveMass_after_alphaT_55",
    ";M_{eff} (GeV); Events/40 GeV;",
    75, 0., 3000.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphatCut_HT_,
    "HT_after_alphaT",
    ";H_{T} (GeV); Events/25 (GeV);",
    80,0.,2000.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphatBefore_HT_,
    "HT_before_alphaT",
    ";H_{T} (GeV); Events/25 (GeV);",
    80,0.,2000.,
    nMax_+1, 0, 1, true );



  BookHistArray( HT_,
    "HT",
    ";H_{T} (GeV); Events/25 GeV;",
    100,0.,2500.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meff_,
    "EffectiveMass",
    ";M_{eff} (GeV); Events/40 GeV;",
    75, 0., 3000.,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphatCut_BiasedDphi_,
    "BiasedDeltaPhi_after_alphaT_55",
    ";#Delta #phi^{*} (rad); Events/0.05 rad;",
    60, 0., TMath::Pi(),
    nMax_+1, 0, 1, true );

  BookHistArray( BiasedDphi_,
    "BiasedDeltaPhi",
    ";#Delta #phi^{*} (rad); Events/0.05 rad;",
    60, 0., TMath::Pi(),
    nMax_+1, 0, 1, true );

  BookHistArray( MHToverHT_,
    "MHToverHT",
    ";#slash{H}_{T}/H_{T};Events/0.025;",
    40,0.,1.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHT_,
    "MHT",
    ";#slash{H}_{T} (GeV); Events/10 GeV;",
    60,0.,600.,
    nMax_+1, 0, 1, true );

  BookHistArray( HT_forRatio_,
    "HT_forRatioPlots",
    ";H_{T} (GeV); Events/25 GeV;",
    80,0.,2000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MultiplicityAfteraT_,
    "JetMultiplicityAfterAlphaT",
    ";n",
    15,0.,15.,
    nMax_+1, 0, 1, true );

  BookHistArray( Multiplicity_,
    "JetMultiplicity",
    ";n",
    15,0.,15.,
    nMax_+1, 0, 1, true );

  BookHistArray( JetEta_,
    "JetEta_",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
    nMax_+1, 0, 1, true );

  BookHistArray( JetPt_,
    "JetPt_",
    ";GeV ; Events/1 eta ",
    75,0.,1500.,
    nMax_+1, 0, 1, true );

  BookHistArray( fem_,
    "fem_",
    ";fem ; Events/0.2 ",
    100,-1.,1.,
    nMax_+1, 0, 1, true );

}
// -----------------------------------------------------------------------------
//

Double_t WeeklyUpdatePlots::MT2_Leading( Event::Data& ev ){
  mt2_bisect::mt2 mt2_event;
  std::vector<Event::Jet const *> jet = ev.JD_CommonJets().accepted;

  LorentzV lv1 = *jet[0];
  LorentzV lv2 = *jet[1];

  double pa[3]; // px py m of object 1
  double pb[3]; // px py m of object 2
  double pm[3];       //jet1
  pa[1] = lv1.Px();
  pa[2] = lv1.Py();
  pa[0] = 0.;//KS_MT(objects[0]);
            //jet2
  pb[1] = lv2.Px();
  pb[2] = lv2.Py();
  pb[0] = 0.;//KS_MT(objects[1]);

  pm[1]= ev.CommonMHT().Px();
  pm[2]= ev.CommonMHT().Py();

  // set invisable mass
  double mn = 0.;
  mt2_event.set_momenta(pa,pb,pm);
  mt2_event.set_mn(mn);

  return mt2_event.get_mt2();

}


Double_t WeeklyUpdatePlots::DeltaHT( Event::Data& ev){
  std::vector<Event::Jet const *> jet = ev.JD_CommonJets().accepted;
  UInt_t n = jet.size();

  LorentzV lv1(0.,0.,0.,0.);
  LorentzV lv2(0.,0.,0.,0.);

  // Alpha_t variable
  std::vector<bool> pseudo;
  AlphaT()( jet, pseudo, false );
  if ( pseudo.size() != jet.size() ) { abort(); }
    // use this to get the pseudo jets

  if ( n == 2 ) {
    if ( jet[0] ) lv1 = *jet[0];
    if ( jet[1] ) lv2 = *jet[1];
  } else if ( n > 2 ) {
    for ( unsigned int i = 0; i < jet.size(); ++i ) {
      if ( jet[i] ) {
        if ( pseudo[i] ) { lv1 += *jet[i];

        }
        else             { lv2 += *jet[i];

        }
      }
    }
    if ( lv2.Pt() > lv1.Pt() ) { LorentzV tmp = lv1; lv1 = lv2; lv2 = tmp; }

  }

  return lv1.Et()-lv2.Et();

}

std::pair<LorentzV,LorentzV> WeeklyUpdatePlots::PsudoJets( Event::Data & ev ){
  std::vector<Event::Jet const *> jet = ev.JD_CommonJets().accepted;
  UInt_t n = jet.size();
  LorentzV lv1(0.,0.,0.,0.);
  LorentzV lv2(0.,0.,0.,0.);

  // Alpha_t variable
  std::vector<bool> pseudo;
  AlphaT()( jet, pseudo, false );
  if ( pseudo.size() != jet.size() ) { abort(); }
    // use this to get the pseudo jets

  if ( n == 2 ) {
    if ( jet[0] ) lv1 = *jet[0];
    if ( jet[1] ) lv2 = *jet[1];
  } else if ( n > 2 ) {
    for ( unsigned int i = 0; i < jet.size(); ++i ) {
      if ( jet[i] ) {
        if ( pseudo[i] ) { lv1 += *jet[i];

        }
        else             { lv2 += *jet[i];

        }
      }
    }
    if ( lv2.Pt() > lv1.Pt() ) { LorentzV tmp = lv1; lv1 = lv2; lv2 = tmp; }

  }
  std::pair<LorentzV,LorentzV> a(lv1,lv2);
  return a;

}

Double_t WeeklyUpdatePlots::MT2( Event::Data& ev){

  std::vector<Event::Jet const *> jet = ev.JD_CommonJets().accepted;
  UInt_t n = jet.size();

  mt2_bisect::mt2 mt2_event;

  LorentzV lv1(0.,0.,0.,0.);
  LorentzV lv2(0.,0.,0.,0.);

  // Alpha_t variable
  std::vector<bool> pseudo;
  AlphaT()( jet, pseudo, false );
  if ( pseudo.size() != jet.size() ) { abort(); }
    // use this to get the pseudo jets

  if ( n == 2 ) {
    if ( jet[0] ) lv1 = *jet[0];
    if ( jet[1] ) lv2 = *jet[1];
  } else if ( n > 2 ) {
    for ( unsigned int i = 0; i < jet.size(); ++i ) {
      if ( jet[i] ) {
        if ( pseudo[i] ) { lv1 += *jet[i];

        }
        else             { lv2 += *jet[i];

        }
      }
    }
    if ( lv2.Pt() > lv1.Pt() ) { LorentzV tmp = lv1; lv1 = lv2; lv2 = tmp; }

  }

  double pa[3]; //m, px, py, of object 1
  double pb[3]; //m, px ,py, of object 2
  double pm[3];       //jet1
  pa[1] = lv1.Px();
  pa[2] = lv1.Py();
  pa[0] = 0.;//KS_MT(objects[0]);
            //jet2
  pb[1] = lv2.Px();
  pb[2] = lv2.Py();
  pb[0] = 0.;//KS_MT(objects[1]);

  pm[1]= ev.CommonMHT().Px();
  pm[2]= ev.CommonMHT().Py();

  // set invisable mass
  double mn = 0.;
  mt2_event.set_momenta(pa,pb,pm);
  mt2_event.set_mn(mn);
  // mt2_event.print();
  return mt2_event.get_mt2();
}


bool WeeklyUpdatePlots::StandardPlots( Event::Data& ev ) {

  UInt_t n = ev.CommonObjects().size();
  Double_t weight = ev.GetEventWeight();

  int count_ = 0;
  double biasedDPhi = 100.;
  double biasedDPhi_baby = 100.;
  int counter_ = 0;
  int counterBaby_ = 0;
  int countBaby_ = 0;

  LorentzV loweredMHT = ev.CommonRecoilMET();
  for(std::vector<Event::Jet const*>::const_iterator iM = ev.JD_CommonJets().baby.begin();iM != ev.JD_CommonJets().baby.end();++iM){
    if( (*iM)->Pt() > 30.)
      loweredMHT -= (**iM);
  }



  for( std::vector<Event::Jet const *>::const_iterator i = ev.JD_CommonJets().accepted.begin();
  i != ev.JD_CommonJets().accepted.end();
  ++i ){
    double newBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**i,loweredMHT + (**i))) ;
    if(newBiasDPhi < biasedDPhi){
      biasedDPhi = newBiasDPhi;
      count_ = counter_;
    }
    counter_++;
  }
  for( std::vector<Event::Jet const*>::const_iterator iI = ev.JD_CommonJets().baby.begin(); iI != ev.JD_CommonJets().baby.end();
  ++iI) {
    if((*iI)->Pt() > 30.){
      double newBiasDPhi_2 = fabs( ROOT::Math::VectorUtil::DeltaPhi(**iI, loweredMHT + (**iI) ) );
      if(newBiasDPhi_2 < biasedDPhi_baby){
        biasedDPhi_baby = newBiasDPhi_2;
        countBaby_ = counterBaby_;
      }
    }
    counterBaby_++;
  }

  if( biasedDPhi < biasedDPhi_baby){
    if ( n >= nMin_ && n <= nMax_ && n < MinBiasDphi_EtaPhiMap_.size()) {
      MinBiasDphi_EtaPhiMap_[0]->Fill(ev.JD_CommonJets().accepted[count_]->Eta(), ev.JD_CommonJets().accepted[count_]->Phi(),weight);
      MinBiasDphi_EtaPhiMap_[n]->Fill(ev.JD_CommonJets().accepted[count_]->Eta(), ev.JD_CommonJets().accepted[count_]->Phi(),weight);
    }
  }
  if( biasedDPhi > biasedDPhi_baby){
    if ( n >= nMin_ && n <= nMax_ && n < MinBiasDphi_EtaPhiMap_.size()) {
      MinBiasDphi_EtaPhiMap_[0]->Fill(ev.JD_CommonJets().baby[countBaby_]->Eta(), ev.JD_CommonJets().baby[countBaby_]->Phi(),weight);
      MinBiasDphi_EtaPhiMap_[n]->Fill(ev.JD_CommonJets().baby[countBaby_]->Eta(), ev.JD_CommonJets().baby[countBaby_]->Phi(),weight);
    }
  }





  int nVertex = 0;
  //Make the vertex sum PT for later plots
  double  VertexPt = 0.;
  for(std::vector<floatle>::const_iterator vtx =
    ev.vertexSumPt()->begin();
  vtx != ev.vertexSumPt()->end();++vtx){
    if(!ev.vertexIsFake()->at( vtx-ev.vertexSumPt()->begin()) && fabs((ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Z()) < 24.0 && ev.vertexNdof()->at( vtx-ev.vertexSumPt()->begin() ) > 4&& (ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Rho() < 2.0 ){  VertexPt += *vtx;}
  }


  for(std::vector<float>::const_iterator vtx =
    ev.vertexSumPt()->begin();
  vtx != ev.vertexSumPt()->end();++vtx){
    if(!ev.vertexIsFake()->at( vtx-ev.vertexSumPt()->begin()) &&
      fabs((ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Z()) < 24.0 &&
      ev.vertexNdof()->at( vtx-ev.vertexSumPt()->begin() ) > 4 &&
      (ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Rho() < 2.0 ){  nVertex++; }
  }

  if ( StandardPlots_ ){

    std::pair<LorentzV,LorentzV> PsudoJets = WeeklyUpdatePlots::PsudoJets( ev );

    if(fabs(cos(ROOT::Math::VectorUtil::DeltaPhi(PsudoJets.first,PsudoJets.second))) < 0.85){
      if ( n >= nMin_ && n <= nMax_ && n < DeltaPhiPsudoJets_.size()) {
        DeltaPhiPsudoJets_[0]->Fill(ev.CommonMHT().Pt()/fabs(cos(ROOT::Math::VectorUtil::DeltaPhi(PsudoJets.first,PsudoJets.second))),weight);
        DeltaPhiPsudoJets_[n]->Fill(ev.CommonMHT().Pt()/fabs(cos(ROOT::Math::VectorUtil::DeltaPhi(PsudoJets.first,PsudoJets.second))),weight);
      }
    }



    if ( n >= nMin_ && n <= nMax_ && n < HT_vs_SecondJetPt_.size()) {
      HT_vs_SecondJetPt_[0]->Fill(ev.CommonHT(),ev.JD_CommonJets().accepted[1]->Pt(),weight);
      HT_vs_SecondJetPt_[n]->Fill(ev.CommonHT(),ev.JD_CommonJets().accepted[1]->Pt(),weight);
    }





    if ( n >= nMin_ && n <= nMax_ && n < vertexPtovHT_.size()) {
      vertexPtovHT_[0]->Fill(VertexPt/ev.CommonHT(),weight);
      vertexPtovHT_[n]->Fill(VertexPt/ev.CommonHT(),weight);
    }



    if ( n >= nMin_ && n <= nMax_ && n < NumberVerticies_.size()) {
      NumberVerticies_[0]->Fill(nVertex,weight);
      NumberVerticies_[n]->Fill(nVertex,weight);
    }


    if ( n >= nMin_ && n <= nMax_ && n < AlphaTVsNoVertex_.size()) {
      AlphaTVsNoVertex_[0]->Fill(ev.CommonAlphaT(),nVertex,weight);
      AlphaTVsNoVertex_[n]->Fill(ev.CommonAlphaT(),nVertex,weight);
    }



    if(nVertex == 1){
      if ( n >= nMin_ && n <= nMax_ && n < AlphaTOneVertex_.size()) {
        AlphaTOneVertex_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaTOneVertex_[n]->Fill(ev.CommonAlphaT(),weight);
      }

    }

    if(nVertex > 1){
      if ( n >= nMin_ && n <= nMax_ && n < AlphaTgOneVertex_.size()) {
        AlphaTgOneVertex_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaTgOneVertex_[n]->Fill(ev.CommonAlphaT(),weight);
      }


    }




    if( (ev.CommonMHT().Pt()-ev.PFMET().Pt())/(ev.CommonMHT().Pt()+ev.CommonHT()) < 0.15){
      if( n >= nMin_ && n <= nMax_ && n < AlphaTafterPFMEC_.size() ) {
        AlphaTafterPFMEC_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaTafterPFMEC_[n]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_Zoomed_afterPFMEC_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_Zoomed_afterPFMEC_[n]->Fill(ev.CommonAlphaT(),weight);
      }
    }

    if( (ev.CommonMHT().Pt()-LorentzV(*ev.metP4caloTypeII()).Pt())/(ev.CommonMHT().Pt()+ev.CommonHT()) < 0.15){
      if( n >= nMin_ && n <= nMax_ && n < AlphaTafterCaloMEC_.size() ) {
        AlphaTafterCaloMEC_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaTafterCaloMEC_[n]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_ZoomedafterCaloMEC_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_ZoomedafterCaloMEC_[n]->Fill(ev.CommonAlphaT(),weight);
      }
    }


    if(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt() < 1.25){
      if ( n >= nMin_ && n <= nMax_ && n < AlphaT_METCut_.size()) {
        AlphaT_METCut_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_METCut_[n]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_Zoomed_METCut_[0]->Fill(ev.CommonAlphaT(),weight);
        AlphaT_Zoomed_METCut_[n]->Fill(ev.CommonAlphaT(),weight);
      }

    }



    if ( n >= nMin_ && n <= nMax_ && n < DPhi_MHT_MHTBaby_.size()) {
      DPhi_MHT_MHTBaby_[0]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),weight);
      DPhi_MHT_MHTBaby_[n]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),weight);

    }

    if ( n >= nMin_ && n <= nMax_ && n < DPhi_MET_MHTBaby_.size()) {
      DPhi_MET_MHTBaby_[0]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.PFMET(),ev.JD_CommonJets().babyHT)),weight);
      DPhi_MET_MHTBaby_[n]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.PFMET(),ev.JD_CommonJets().babyHT)),weight);

    }

    if ( n >= nMin_ && n <= nMax_ && n < DPhi_MET_MHT_.size()) {
      DPhi_MET_MHT_[0]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.PFMET(),ev.CommonMHT())),weight);
      DPhi_MET_MHT_[n]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.PFMET(),ev.CommonMHT())),weight);

    }



    if ( n >= nMin_ && n <= nMax_ && n < BabyJetMHT_.size()) {
      BabyJetMHT_[0]->Fill( ev.JD_CommonJets().babyHT.Pt(), weight );
      BabyJetMHT_[n]->Fill( ev.JD_CommonJets().babyHT.Pt(), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < BabyJetMHT_StandardMHT_.size()) {
      BabyJetMHT_StandardMHT_[0]->Fill( ev.CommonMHT().Pt(),ev.JD_CommonJets().babyHT.Pt(), weight );
      BabyJetMHT_StandardMHT_[n]->Fill( ev.CommonMHT().Pt(),ev.JD_CommonJets().babyHT.Pt(), weight );
    }



    if ( n >= nMin_ && n <= nMax_ && n < DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_.size()) {
      DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_[0]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),
        (ev.JD_CommonJets().babyHT).Pt()/ev.CommonMHT().Pt(),weight);
      DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_[n]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),
        (ev.JD_CommonJets().babyHT).Pt()/ev.CommonMHT().Pt(),weight);

    }




    if ( n >= nMin_ && n <= nMax_ && n < BabyJetMHT_StandardAlphaT_.size()) {
      BabyJetMHT_StandardAlphaT_[0]->Fill( ev.CommonAlphaT(), cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)), weight );
      BabyJetMHT_StandardAlphaT_[n]->Fill( ev.CommonAlphaT(), cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)), weight );
    }



    if ( n >= nMin_ && n <= nMax_ && n < Mt2_LeadingJets_.size()) {
      Mt2_LeadingJets_[0]->Fill( WeeklyUpdatePlots::MT2_Leading(ev), weight );
      Mt2_LeadingJets_[n]->Fill( WeeklyUpdatePlots::MT2_Leading(ev), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < Multiplicity_.size()) {
      Multiplicity_[0]->Fill( n, weight );
      Multiplicity_[n]->Fill( n, weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < MHT_.size()) {
      MHT_[0]->Fill( ev.CommonMHT().Pt(), weight );
      MHT_[n]->Fill( ev.CommonMHT().Pt(), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < HT_.size() ) {
      HT_[0]->Fill( ev.CommonHT(), weight );
      HT_[n]->Fill( ev.CommonHT(), weight );
    }


    if ( n >= nMin_ && n <= nMax_ && n < MHToverHT_.size() ) {
      MHToverHT_[0]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
      MHToverHT_[n]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < Meff_.size()) {
      Meff_[0]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
      Meff_[n]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
    }


    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_Zoomed_.size()  ) {
      AlphaT_Zoomed_[0]->Fill( ev.CommonAlphaT(), weight );
      AlphaT_Zoomed_[n]->Fill( ev.CommonAlphaT(), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_.size()  ) {
      AlphaT_[0]->Fill( ev.CommonAlphaT(), weight );
      AlphaT_[n]->Fill( ev.CommonAlphaT(), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < Mt2_.size() ) {
      Mt2_[0]->Fill( WeeklyUpdatePlots::MT2(ev), weight );
      Mt2_[n]->Fill( WeeklyUpdatePlots::MT2(ev), weight );
    }

    if( biasedDPhi < biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < BiasedDphi_.size()) {
      MinBiasDphi_EtaPhiMap_[0]->Fill(biasedDPhi,weight);
      MinBiasDphi_EtaPhiMap_[n]->Fill(biasedDPhi,weight);
      }
    }
    if( biasedDPhi > biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < BiasedDphi_.size()) {
      BiasedDphi_[0]->Fill(biasedDPhi_baby,weight);
      BiasedDphi_[n]->Fill(biasedDPhi_baby,weight);
      }
    }


    if( n >= nMin_ && n <= nMax_ && n < DetlaPhi_LeadingJets_.size() ){
      DetlaPhi_LeadingJets_[1]->Fill( fabs( ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[0],*ev.JD_CommonJets().accepted[1])),weight);
      if(n <2){
        DetlaPhi_NextToLeadingJets_[2]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[1],*ev.JD_CommonJets().accepted[2])),weight);

      }
    }


    for(unsigned int i = 0; i < ev.JD_CommonJets().accepted.size() && i < 3; i++){
      fem_[0]->Fill(ev.JD_CommonJets().accepted[i]->GetEmFrac(),weight);
      JetPt_[0]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_[0]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
      fem_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->GetEmFrac(),weight);
      JetPt_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
    }



    if( n >= nMin_ && n <= nMax_ && n < AlphaT_components_.size() ){
      AlphaT_components_[0]->Fill(ev.CommonMHT().Pt()/ev.CommonHT(),WeeklyUpdatePlots::DeltaHT(ev)/ev.CommonHT(),weight);
      AlphaT_components_[n]->Fill(ev.CommonMHT().Pt()/ev.CommonHT(),WeeklyUpdatePlots::DeltaHT(ev)/ev.CommonHT(),weight);
    }


    if(LorentzV(*ev.metP4caloTypeII()).Pt() < 20.0){
      if ( n >= nMin_ && n <= nMax_ && n < BabyJetMHTafterMETcut_.size()) {
        BabyJetMHTafterMETcut_[0]->Fill( ev.JD_CommonJets().babyHT.Pt(), weight );
        BabyJetMHTafterMETcut_[n]->Fill( ev.JD_CommonJets().babyHT.Pt(), weight );
      }
    }


    if ( n >= nMin_ && n <= nMax_ && n < MHTovMET_raw_.size() ) {
      MHTovMET_raw_[0]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      MHTovMET_raw_[n]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
    }

    if ( n >= nMin_ && n <= nMax_ && n < CaloMET_.size() ) {
      CaloMET_[0]->Fill(  LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      CaloMET_[n]->Fill(  LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
    }

    if(ev.CommonAlphaT() < 0.55){
      if ( n >= nMin_ && n <= nMax_ && n < AlphatBefore_HT_.size() ) {
        AlphatBefore_HT_[0]->Fill( ev.CommonHT(), weight );
        AlphatBefore_HT_[n]->Fill( ev.CommonHT(), weight );
      }
    }

    if(ev.CommonAlphaT() > 0.55){


      if ( n >= nMin_ && n <= nMax_ && n < HT_vs_SecondJetPt_after_alphaT_.size()) {
      HT_vs_SecondJetPt_after_alphaT_[0]->Fill(ev.CommonHT(),ev.JD_CommonJets().accepted[1]->Pt(),weight);
      HT_vs_SecondJetPt_after_alphaT_[n]->Fill(ev.CommonHT(),ev.JD_CommonJets().accepted[1]->Pt(),weight);
      }


      if ( n >= nMin_ && n <= nMax_ && n < CaloMET_afteraT_.size() ) {
        CaloMET_afteraT_[0]->Fill(  LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
        CaloMET_afteraT_[n]->Fill(  LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < NumberVerticiesAfterAlphaT_.size()) {
        NumberVerticiesAfterAlphaT_[0]->Fill(nVertex,weight);
        NumberVerticiesAfterAlphaT_[n]->Fill(nVertex,weight);
      }

      if ( n >= nMin_ && n <= nMax_ && n < MultiplicityAfteraT_.size()) {
        MultiplicityAfteraT_[0]->Fill( n, weight );
        MultiplicityAfteraT_[n]->Fill( n, weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < HT_forRatio_.size() ) {
        HT_forRatio_[0]->Fill(  ev.CommonHT(), weight );
        HT_forRatio_[n]->Fill( ev.CommonHT(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < MHTovMET_.size() ) {
        MHTovMET_[0]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
        MHTovMET_[n]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < MissedHT_.size() ) {
        MissedHT_[0]->Fill(  ev.CommonRecoilMET().Pt()/(ev.CommonRecoilMET()+ev.JD_CommonJets().babyHT).Pt(), weight );
        MissedHT_[n]->Fill( ev.CommonRecoilMET().Pt()/(ev.CommonRecoilMET()+ev.JD_CommonJets().babyHT).Pt(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_AfterAlphaT_.size()) {
        DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_AfterAlphaT_[0]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),
          ev.JD_CommonJets().babyHT.Pt()/ev.CommonMHT().Pt(),weight);
        DPhi_MHT_MHTbaby_vsMHTbabyOverMHT_AfterAlphaT_[n]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),
          ev.JD_CommonJets().babyHT.Pt()/ev.CommonMHT().Pt(),weight);
      }


      if ( n >= nMin_ && n <= nMax_ && n < DPhi_MHT_MHTbaby_AfterAlphaT_.size()) {
        DPhi_MHT_MHTbaby_AfterAlphaT_[0]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),weight);
        DPhi_MHT_MHTbaby_AfterAlphaT_[n]->Fill(cos(ROOT::Math::VectorUtil::DeltaPhi(ev.CommonMHT(),ev.JD_CommonJets().babyHT)),weight);
      }

      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_HT_.size() ) {
        AlphatCut_HT_[0]->Fill( ev.CommonHT(), weight );
        AlphatCut_HT_[n]->Fill( ev.CommonHT(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_Meff_.size()) {
        AlphatCut_Meff_[0]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
        AlphatCut_Meff_[n]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
      }

    if( biasedDPhi < biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_BiasedDphi_.size()) {
      AlphatCut_BiasedDphi_[0]->Fill(biasedDPhi,weight);
      AlphatCut_BiasedDphi_[n]->Fill(biasedDPhi,weight);
      }
    }
    if( biasedDPhi > biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_BiasedDphi_.size()) {
      AlphatCut_BiasedDphi_[0]->Fill(biasedDPhi_baby,weight);
      AlphatCut_BiasedDphi_[n]->Fill(biasedDPhi_baby,weight);
      }
    }

    }

  }







  return true;

}
