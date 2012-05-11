#include "BtagSystematicPlots.hh"
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
#include "GenMatrixBin.hh"

using namespace Operation;

// -----------------------------------------------------------------------------
BtagSystematicPlots::BtagSystematicPlots( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
  GenPt_(ps.Get<std::vector<double> >("GenPt")),
  GenEta_(ps.Get<std::vector<double> >("GenEta")),
  Pt_Eta_Eff_(ps.Get<std::vector<double> >("Pt_Eta_Eff")),

  Mistag_GenPt_(ps.Get<std::vector<double> >("Mistag_GenPt")),
  Mistag_GenEta_(ps.Get<std::vector<double> >("Mistag_GenEta")),
  Mistag_Pt_Eta_Eff_(ps.Get<std::vector<double> >("Mistag_Pt_Eta_Eff")),

  JetPt_High_(ps.Get<std::vector<double> >("JetPt_High")),
  JetPt_Low_(ps.Get<std::vector<double> >("JetPt_Low")),
  Variation_(ps.Get<std::vector<double> >("Variation")),




// MT2
  StandardPlots_( ps.Get<bool>("StandardPlots") )

  { 
  }

// -----------------------------------------------------------------------------
//
BtagSystematicPlots::~BtagSystematicPlots() {}

// -----------------------------------------------------------------------------
//
void BtagSystematicPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void BtagSystematicPlots::BookHistos() {
  if ( StandardPlots_ )           { StandardPlots(); }
}

// -----------------------------------------------------------------------------
//
bool BtagSystematicPlots::Process( Event::Data& ev ) {
  if ( StandardPlots_ )               { StandardPlots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& BtagSystematicPlots::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void BtagSystematicPlots::StandardPlots() {




  BookHistArray( vertexPtovHT_,
    "vertexPtovHT",
    ";VertexPt / HT (GeV);Events/0.01;",
    1000, 0., 10.,
    4, 0, 1, true );


  BookHistArray( vertexPtovHT_afterAlphaT_55_,
    "vertexPtovHT_afterAlphaT_55",
    ";VertexPt / HT (GeV);Events/0.01;",
    1000, 0., 10.,
    4, 0, 1, true );

    BookHistArray( NumberVerticiesAfterAlphaT_55_,
    "Number_Primary_verticies_after_alphaT_55",
    ";No.Vertercies;Events;",
    50,0.,50,
    4, 0, 1, true );

    BookHistArray( NumberVerticies_,
    "Number_Primary_verticies",
    ";No.Vertercies;Events;",
    50,0.,50,
    4, 0, 1, true );

    BookHistArray( MHTovMET_,
    "MHTovMET",
    ";MHT/MET;Events/0.1;",
    1000, 0., 100,
    4, 0, 1, true );

  BookHistArray( MHTovMET_afterAlphaT_55_,
    "MHTovMET_afterAlphaT_55",
    ";MHT/MET;Events/0.1;",
    1000, 0., 100,
    4, 0, 1, true );
 
  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    4, 0, 1, true );

  BookHistArray( AlphatCut_Meff_55_,
    "EffectiveMass_after_alphaT_55",
    ";M_{eff} (GeV); Events/40 GeV;",
    3000, 0., 3000.,
    4, 0, 1, true );

    BookHistArray( AlphatCut_HT_55_,
    "HT_after_alphaT_55",
    ";H_{T} (GeV); Events/25 (GeV);",
    2000,0.,2000.,
    4, 0, 1, true );
  
  BookHistArray( HT_,
    "HT",
    ";H_{T} (GeV); Events/25 GeV;",
    2500,0.,2500.,
    4, 0, 1, true );


    BookHistArray( Meff_,
    "EffectiveMass",
    ";M_{eff} (GeV); Events/40 GeV;",
    2500, 0., 2500.,
    4, 0, 1, true );

    BookHistArray( MHToverHT_,
    "MHToverHT",
    ";#slash{H}_{T}/H_{T};Events/0.025;",
    40,0.,1.,
    4, 0, 1, true );

  BookHistArray( MHToverHT_afterAlphaT_55_,
    "MHToverHT_afterAlphaT_55",
    ";#slash{H}_{T}/H_{T};Events/0.025;",
    40,0.,1.,
    4, 0, 1, true );

    BookHistArray( MHT_,
    "MHT",
    ";#slash{H}_{T} (GeV); Events/10 GeV;",
    600,0.,600.,
    4, 0, 1, true );

  BookHistArray( MHTAfteraT_55_,
    "MHT after AlphaT 55",
    ";#slash{H}_{T} (GeV); Events/10 GeV;",
    600,0.,600.,
    4, 0, 1, true );

    BookHistArray( MultiplicityAfteraT_55_,
    "JetMultiplicityAfterAlphaT_55",
    ";n",
    15,0.,15.,
    4, 0, 1, true );

    BookHistArray( Multiplicity_,
    "JetMultiplicity",
    ";n",
    15,0.,15.,
    4, 0, 1, true );

  BookHistArray( JetEta_,
    "JetEta",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );


  BookHistArray( Number_Matched_Multiplicity_,
    "Number_Matched_Multiplicity",
    ";Number ; Events;",
    15,0.,15.,
    4, 0, 1, true );

  BookHistArray( Number_Not_Matched_Multiplicity_,
    "Number_Not_Matched_Multiplicity",
    ";Number ; Events;",
    15,0.,15.,
    4, 0, 1, true );

  BookHistArray( Number_GenBJets_,
    "Number_GenBJets",
    ";Number ; Events;",
    6,0.,6.,
    4, 0, 1, true );

  BookHistArray( Number_GenTauJets_,
    "Number_GenTauJets",
    ";Number ; Events;",
    6,0.,6.,
    4, 0, 1, true );

  BookHistArray( Number_Matched_GenBJets_,
    "Number_Matched_GenBJets",
    ";Number ; Events;",
    10,0.,10.,
    4, 0, 1, true );

  BookHistArray( Number_Matched_Gen_NoBJets_,
    "Number_Matched_Gen_NoBJets",
    ";Number ; Events;",
    10,0.,10.,
    4, 0, 1, true );

  BookHistArray( GenJetEta_,
    "GenJetEta",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetEta_,
    "Btagged_GenJetEta",
    "#eta Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( GenJetEta_noB_,
    "GenJetEta_noB",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );

   BookHistArray( Btagged_GenJetEta_noB_,
    "Btagged_GenJetEta_noB",
    "#eta Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );

    BookHistArray( MatchedB_vs_Matched_noB_,
    "Matched_vs_Matched_noB",
    ";Number B-jets; Number Not B-jets;",
    6,0.,6.,
    10,0.,10.,
    4, 0, 1, true );

  BookHistArray( MatchedB_vs_Matched_noB_alphaT_,
    "Matched_vs_Matched_noB_alphaT",
    ";Number B-jets; Number Not B-jets;",
    6,0.,6.,
    10,0.,10.,
    4, 0, 1, true );

  BookHistArray( Duplicate_GenJetEta_,
    "Duplicate_GenJetEta",
    ";#eta ; Events;",
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( Duplicate_GenJetEta_noB_,
    "Duplicate_GenJetEta_noB",
    ";#eta ; Events;",
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( JetPt_,
    "JetPt",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( GenJetPt_,
    "GenJetPt",
    ";GeV ; Event ",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_,
    "Btagged_GenJetPt",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( Btagged_NotMatched_RecoJet_,
    "Btagged_NotMatched_RecoJet_",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( NotMatched_RecoJet_,
    "NotMatched_RecoJet_",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_SFb_,
    "Btagged_GenJetPt_SFb",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( Btagged_GenJetPt_SFb_plus_,
    "Btagged_GenJetPt_SFb_plus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_SFb_minus_,
    "Btagged_GenJetPt_SFb_minus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( GenJetPt_noB_,
    "GenJetPt_noB",
    ";GeV ; Event ",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_,
    "Btagged_GenJetPt_noB",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


  BookHistArray( Btagged_GenJetPt_noB_SFlight_,
    "Btagged_GenJetPt_noB_SFlight",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_SFlight_plus_,
    "Btagged_GenJetPt_noB_SFlight_plus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Btagged_GenJetPt_noB_SFlight_minus_,
    "Btagged_GenJetPt_noB_SFlight_minus",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );


 BookHistArray( Duplicate_GenJetPt_,
    "Duplicate_GenJetPt",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( Duplicate_GenJetPt_noB_,
    "Duplicate_GenJetPt_noB",
    ";GeV ; Events",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( GenPt_ov_RecoPt_,
    "GenPt_ov_RecoPt",
    "Gen/Reco ; Event ",
    600,0,3.,
    4, 0, 1, true );

  BookHistArray( GenPt_ov_RecoPt_noB_,
    "GenPt_ov_RecoPt_noB",
    "Gen/Reco ; Event ",
    600,0,3.,
    4, 0, 1, true );

  BookHistArray( GenPt_minus_RecoPt_noB_,
    "GenPt_minus_RecoPt_noB",
    "Gen/Reco ; Event ",
    1000,-1.,1.,
    4, 0, 1, true );


  BookHistArray( JetEta_afterAlphaT_55_,
    "JetEta_afterAlphaT_55",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( JetPt_afterAlphaT_55_,
    "JetPt_afterAlphaT_55",
    ";GeV ; Events/1 eta ",
    1500,0.,1500.,
    4, 0, 1, true );

  BookHistArray( hLepPt_,
    "MuPt",
    ";P_{T} [GeV];",
    2000,10.,2010.,
    4, 0, 1, true );

  BookHistArray( hLepPt_afterAlphaT_55_,
    "MuPt_afterAlphaT_55",
    ";P_{T} [GeV];",
    2000,10.,2010.,
    4, 0, 1, true );

   BookHistArray( hLepTrIso_,
    "MuTrIso",
    ";Trk Iso;",
    2000,0.,2.,
    4, 0, 1, true );


  BookHistArray( hLepEIso_,
    "MuEIso",
    ";E Iso;",
    2000,0.,2.,
    4, 0, 1, true );


  BookHistArray( hLepHIso_,
    "MuHIso",
    ";H Iso;",
    2000,0.,2.,
    4, 0, 1, true );

  BookHistArray( hLepCIso_,
    "MuCso",
    ";Combined_Iso;",
    2000,0.,2.,
    4, 0, 1, true );

  BookHistArray( hLepTrIso_afterAlphaT_55_,
    "MuTrIso_afterAlphaT_55",
    ";Trk Iso;",
    2000,0.,2.,
    4, 0, 1, true );


  BookHistArray( hLepEIso_afterAlphaT_55_,
    "MuEIso_afterAlphaT_55",
    ";E Iso;",
    2000,0.,2.,
    4, 0, 1, true );


  BookHistArray( hLepHIso_afterAlphaT_55_,
    "MuHIso_afterAlphaT_55",
    ";H Iso;",
    2000,0.,2.,
    4, 0, 1, true );

  BookHistArray( hLepCIso_afterAlphaT_55_,
    "MuCso_afterAlphaT_55",
    ";Combined_Iso;",
    2000,0.,2.,
    4, 0, 1, true );

  BookHistArray( hMT_,
    "MT_",
    ";M){T} [GeV];",
    2000,0.,2000.,
    4, 0, 1, true );

  BookHistArray( hMT_afterAlphaT_55_,
    "MT_after_alphaT_55",
    ";M){T} [GeV];",
    2000,0.,2000.,
    4, 0, 1, true );

    BookHistArray( BtagPreAlphaT_5_,
    "Btag_Pre_AlphaT_5_",
    ";Number of Btags;",
    6,0.,6.,
    4, 0, 1, true );

  BookHistArray( BtagAfterAlphaT_5_55_,
    "Btag_Post_AlphaT_5_55",
    ";Number of Btags;",
    6,0.,6.,
    4, 0, 1, true );

  BookHistArray( GenParticle_Ids_,
    "GenParticle_Ids",
    ";GenParticle_Ids;",
    25,0.,25.,
    4, 0, 1, true );

  BookHistArray( GenParticle_Ids_Btagged_,
    "GenParticle_Ids_Btagged",
    ";GenParticle_Ids;",
    25,0.,25.,
    4, 0, 1, true );

  BookHistArray( GenParticle_B_Jet_Ids_,
    "GenParticle_B_Jet_Ids",
    ";GenParticle_Ids;",
    25,0.,25.,
    4, 0, 1, true );

  BookHistArray( GenJet_DeltaR_noB_,
    "GenJet_DeltaR_noB",
    "DeltaR;;",
    60,0.,3.,
    4, 0, 1, true );

  BookHistArray(MHTOvCaloMET_,
    "MHTOvCaloMET",
    ";MHTOvCaloMET",
    1000,0,50,
    4,0,1,true);

  BookHistArray(MHTOvCaloMET_Lepton_,
    "MHTOvCaloMET_Lepton",
    ";MHTOvCaloMET",
    1000,0,50,
    4,0,1,true);

    
  /*BookHistArray( GenJetPt_vs_GenJetEta_,
    "GenJetPt_vs_GenJetEta",
   ";#eta Events/1 eta; JetPt;",
    1500,0.,1500.,
    60,-5.,5.,
    4, 0, 1, true );
  
  BookHistArray( GenJetPt_vs_GenJetEta_noB_,
    "GenJetPt_vs_GenJetEta_noB",
    ";#eta Events/1 eta; JetPt;",
    1500,0.,1500.,
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( Matched_GenJetPt_vs_GenJetEta_noB_,
    "Matched_GenJetPt_vs_GenJetEta_noB",
    "#eta Events/1 eta; JetPt",
    1500,0.,1500.,
    60,-5.,5.,
    4, 0, 1, true );


    BookHistArray( Matched_GenJetPt_vs_GenJetEta_,
    "Matched_GenJetPt_vs_GenJetEta",
    "#eta Events/1 eta; JetPt",
    1500,0.,1500.,
    60,-5.,5.,
    4, 0, 1, true );*/


}
// -----------------------------------------------------------------------------
//

Double_t BtagSystematicPlots::MT2_Leading( Event::Data& ev ){
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


Double_t BtagSystematicPlots::DeltaHT( Event::Data& ev){
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

std::pair<LorentzV,LorentzV> BtagSystematicPlots::PsudoJets( Event::Data & ev ){
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

Double_t BtagSystematicPlots::MT2( Event::Data& ev){

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


bool BtagSystematicPlots::StandardPlots( Event::Data& ev ) {

  std::vector <Event::Lepton const *> theLepton;
  

  UInt_t nBtags_five = 0;
  for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
  // std::cout << "we are on jet " << i << " the btag discriminator is " << ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 4) << std::endl;
  if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 5) > 0.679) {
  nBtags_five++;
         //if we make it into here, the jet has passed the b-tag requirement
   } 
  
  }


  bool isMu= false;
  bool isLep=false;
  bool isdoubleMu = false;

  if (ev.LD_CommonMuons().accepted.size() + ev.LD_CommonElectrons().accepted.size() != 0){
    isLep=true;}

  if(ev.LD_CommonMuons().accepted.size()>0&&ev.LD_CommonElectrons().accepted.size()==0)
    {
      theLepton = ev.LD_CommonMuons().accepted;
      isMu = true;
    }  

  if(ev.LD_CommonMuons().accepted.size()>1&&ev.LD_CommonElectrons().accepted.size()==0)
    {
      theLepton = ev.LD_CommonMuons().accepted;
      isdoubleMu = true;
   } 

  if(ev.LD_CommonMuons().accepted.size()==0&&ev.LD_CommonElectrons().accepted.size()>0)
    {
      theLepton = ev.LD_CommonElectrons().accepted;
    }  

  if(ev.LD_CommonMuons().accepted.size()>0&&ev.LD_CommonElectrons().accepted.size()>0)
    {
      cout << "WARNING: ttWPlottingOps has common muon AND Electron, it does not know what to plot!!!"<<endl;
       return true;
     }


  UInt_t n = ev.JD_CommonJets().accepted.size();
  if(n>=3){n=3;}
  //cout << "n is equal too " << n << endl;
  Double_t weight = ev.GetEventWeight();
  
  /*cout << " Weight in " << weight << endl;

   if (ev.pthat.enabled()){

        std::map<std::pair<int, double>, double> eff_;
        std::map<std::pair<int, double>, double> misstag_;
        std::map<std::pair<int, double>, double> error_variation_;

        for(std::vector<double>::const_iterator it = GenPt_.begin();it != GenPt_.end(); it++){
              eff_.insert(std::make_pair(std::make_pair((*it),GenEta_[it - GenPt_.begin()]),Pt_Eta_Eff_[it - GenPt_.begin()]));
                }

        for(std::vector<double>::const_iterator it = Mistag_GenPt_.begin();it != Mistag_GenPt_.end(); it++){
              misstag_.insert(std::make_pair(std::make_pair((*it),Mistag_GenEta_[it - Mistag_GenPt_.begin()]),Mistag_Pt_Eta_Eff_[it - Mistag_GenPt_.begin()]));
                }

        for(std::vector<double>::const_iterator it = JetPt_Low_.begin();it != JetPt_Low_.end(); it++){
              error_variation_.insert(std::make_pair(std::make_pair((*it),JetPt_High_[it - JetPt_Low_.begin()]),Variation_[it - JetPt_Low_.begin()]));
                }

        double match_jetpt_low;
        double match_jetpt_high;

        for(unsigned int i = 0; i < gen.the_GenB.size(); i++){
          double match_pt;
          double match_eta;
          double Check_Pt = gen.the_GenB.at(i)->Pt();
          double Check_Eta = gen.the_GenB.at(i)->Eta();
          for(std::vector<double>::const_iterator GenPt_it = GenPt_.begin(); GenPt_it != GenPt_.end(); GenPt_it++){
             if (Check_Pt > (*GenPt_it) && Check_Pt < (*(GenPt_it+1))){
               match_pt = (*GenPt_it);
               break;}
                 }
          for(std::vector<double>::const_iterator GenEta_it = GenEta_.begin(); GenEta_it != GenEta_.end(); GenEta_it++){
             if (Check_Eta > (*GenEta_it) && Check_Eta < (*GenEta_it + 1)){ 
               match_eta = (*GenEta_it);
               break;}  
             else{ match_eta = 0;}
             }

          std::pair<int, double> xy = make_pair(match_pt, match_eta);
          if(eff_.find(xy) == eff_.end()){
            std::stringstream ss;
            ss << "Point: GenPt=" << match_pt << ", Eta=" << match_eta << ") not found. Aborting.";
            throw std::invalid_argument(ss.str());
            }
          double E = eff_.find(xy)->second;
          float minDeltaR = 2*TMath::Pi();
          int index_keeper = -1;
          if( E > 0.99999 && E < 1.00001) {weight *= 1.0;}
          else{
          for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
             float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenB.at(i))));
             if(aminDeltaR<minDeltaR) {
                minDeltaR=aminDeltaR;
                index_keeper = j;
                  }           
                }
             if(index_keeper != -1 && minDeltaR < 0.3 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.8 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.2 ){
                float x = ev.JD_CommonJets().accepted.at(index_keeper)->Pt();
                for(std::vector<double>::const_iterator JetPt_it = JetPt_Low_.begin(); JetPt_it != JetPt_Low_.end(); JetPt_it++){
                  if (x  > (*JetPt_it) && x < (*(JetPt_it+1))){
                  match_jetpt_low = (*JetPt_it);
                  match_jetpt_high = JetPt_High_[JetPt_it - JetPt_Low_.begin()];
                  break;}
                 }
                std::pair<int, double> cd = make_pair(match_jetpt_low, match_jetpt_high);
                double sigma_correction = error_variation_.find(cd)->second;
                //cout << " Jet Pt is " << x << endl;
                //cout << " Jet Pt Low is  " << match_jetpt_low << " Upper bound is " << match_jetpt_high << " Correction " << sigma_correction << endl;
                float SFb = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))))+sigma_correction;
                if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(index_keeper)->GetIndex(), 5) > 0.679){ 
                  //cout << " Btagged Jet " << endl;
                  weight *= SFb;}
                else{ 
                  //cout << " Matched But not Btagged" << endl;
                  weight *= (1.0-(SFb*E))/(1-E);}
                    }
                   }
                  }

              //////////////==================================================////////////
        for(unsigned int i = 0; i < gen.the_GenJets_noB.size(); i++){
          double mistag_match_pt;
          double mistag_match_eta;
          double Check_Mistag_Pt = gen.the_GenJets_noB.at(i)->Pt();
          double Check_Mistag_Eta = gen.the_GenJets_noB.at(i)->Eta();
          for(std::vector<double>::const_iterator Mistag_GenPt_it = Mistag_GenPt_.begin(); Mistag_GenPt_it != Mistag_GenPt_.end(); Mistag_GenPt_it++){
             if (Check_Mistag_Pt > (*Mistag_GenPt_it) && Check_Mistag_Pt < (*(Mistag_GenPt_it+1))){
               mistag_match_pt = (*Mistag_GenPt_it);
               break;}
                 }
          for(std::vector<double>::const_iterator Mistag_GenEta_it = Mistag_GenEta_.begin(); Mistag_GenEta_it != Mistag_GenEta_.end(); Mistag_GenEta_it++){
             if (Check_Mistag_Eta > (*Mistag_GenEta_it) && Check_Mistag_Eta < (*Mistag_GenEta_it + 1)){ 
               mistag_match_eta = (*Mistag_GenEta_it);
               break;}  
             else{ mistag_match_eta = 0;}
             }
          std::pair<int, double> ab = make_pair(mistag_match_pt, mistag_match_eta);
          if(misstag_.find(ab) == misstag_.end()){
            std::stringstream ss;
            ss << "Point: GenPt=" << mistag_match_pt << ", Eta=" << mistag_match_eta << ") not found for mistag. Aborting.";
            throw std::invalid_argument(ss.str());
            }
          double M = misstag_.find(ab)->second;
          float mistag_minDeltaR = 2*TMath::Pi();
          int mistag_index_keeper = -1;
          if ( M > 0.99999 && M < 1.00001) {weight *= 1.0;}
          else{
          for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
             float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenJets_noB.at(i))));
             if(aminDeltaR<mistag_minDeltaR) {
                mistag_minDeltaR=aminDeltaR;
                mistag_index_keeper = j;
                }
               }
             if(mistag_index_keeper != -1 && mistag_minDeltaR < 0.3 &&  gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(mistag_index_keeper)->Pt() > 0.8 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(mistag_index_keeper)->Pt() < 1.2  ){
                float SFlight;  
                float x = ev.JD_CommonJets().accepted.at(mistag_index_keeper)->Pt();
                for(std::vector<double>::const_iterator JetPt_it = JetPt_Low_.begin(); JetPt_it != JetPt_Low_.end(); JetPt_it++){
                  if (x  > (*JetPt_it) && x < (*(JetPt_it+1))){
                  match_jetpt_low = (*JetPt_it);
                  match_jetpt_high = JetPt_High_[JetPt_it - JetPt_Low_.begin()];
                  break;}
                 }
                std::pair<int, double> cd = make_pair(match_jetpt_low, match_jetpt_high);
                double sigma_correction = error_variation_.find(cd)->second;

                if(gen.the_GenJets_noB.at(i)->GetID() == 4){SFlight = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))))+(2*sigma_correction);}
                else{
                  //SFlight = ((1.04318+(0.000848162*x))+(-2.5795e-06*(x*x)))+(1.64156e-09*(x*(x*x)));
                  //SFlight =((0.962627+(0.000448344*x))+(-1.25579e-06*(x*x)))+(4.82283e-10*(x*(x*x))); //min
                  SFlight = ((1.12368+(0.00124806*x))+(-3.9032e-06*(x*x)))+(2.80083e-09*(x*(x*x))); //max
                  }
                if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(mistag_index_keeper)->GetIndex(), 5) > 0.679){ 
                  //cout << " Mistagged Bjet weight factor " << SFlight << endl;
                  weight *= SFlight;}

                else{ 
                  //cout << " Matched But not Btagged None Bjet weight factor " <<  (1.0-(SFlight*M))/(1-M) << endl;
                  weight *= (1.0-(SFlight*M))/(1-M);}
                      }    
                    }
                  }
                 }
  //cout << " Weight out " << weight << endl; */              
   
   
   /*if (ev.pthat.enabled()){

      std::set<unsigned> checkmatch;
      Number_Matched_Multiplicity_[0]->Fill(n,weight);
      for(unsigned int i = 0; i < gen.the_GenB.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenB.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }
        if(index_keeper != -1 && minDeltaR < 0.6 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5 ){checkmatch.insert(index_keeper);}
         }

      for(unsigned int i = 0; i < gen.the_GenJets_noB.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenJets_noB.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }

        if(index_keeper != -1 && minDeltaR < 0.6 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5  ){checkmatch.insert(index_keeper);}     
      }
      
      for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
        bool reco_match = false;
      for(std::set<unsigned>::iterator it = checkmatch.begin(); it != checkmatch.end(); it++){
        if(j == (*it)){reco_match = true;}
       }
      if (!reco_match){
       Number_Not_Matched_Multiplicity_[0]->Fill(n,weight);
       return false;
       //cout << "All Matched" << endl;
        }
       }
    }*/


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

  


  if ( n >= nMin_ && n <= nMax_ && n < BtagPreAlphaT_5_.size()) {
    BtagPreAlphaT_5_[0]->Fill( nBtags_five, weight );
    BtagPreAlphaT_5_[n]->Fill( nBtags_five, weight );
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

    std::pair<LorentzV,LorentzV> PsudoJets = BtagSystematicPlots::PsudoJets( ev );

    if ( n >= nMin_ && n <= nMax_ && n < vertexPtovHT_.size()) {
      vertexPtovHT_[0]->Fill(VertexPt/ev.CommonHT(),weight);
      vertexPtovHT_[n]->Fill(VertexPt/ev.CommonHT(),weight);
    }

    if ( n >= nMin_ && n <= nMax_ && n < MHTovMET_.size() ) {
        MHTovMET_[0]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
        MHTovMET_[n]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      }

    if ( n >= nMin_ && n <= nMax_ && n < NumberVerticies_.size()) {
      NumberVerticies_[0]->Fill(nVertex,weight);
      NumberVerticies_[n]->Fill(nVertex,weight);
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

    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_.size()  ) {
      AlphaT_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_[n]->Fill( ev.HadronicAlphaT(), weight );
    }
    else{cout << "Failed to get in here" << n << "AlphaT size " << AlphaT_.size() <<endl;}

    for(unsigned int i = 0; i < ev.JD_CommonJets().accepted.size() && i < 3; i++){
      JetPt_[0]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_[0]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
      //JetPt_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      //JetEta_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
    }

    LorentzV calomet = LorentzV(*ev.metP4calo());

      for(int i = 0; i < int(ev.LD_CommonElectrons().accepted.size());i++){
        calomet = calomet+(*ev.LD_CommonElectrons().accepted[i]);
      }
      for(int i = 0; i < int(ev.PD_CommonPhotons().accepted.size());i++){
        calomet = calomet+(*ev.PD_CommonPhotons().accepted[i]);
      }
      for(int i = 0; i < int(ev.LD_CommonMuons().accepted.size());i++){
        calomet = calomet+(*ev.LD_CommonMuons().accepted[i]);
      }


    if ( n >= nMin_ && n <= nMax_ && n < MHTOvCaloMET_.size()  ) {
    MHTOvCaloMET_[0]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4calo()).Pt(),weight);
    MHTOvCaloMET_[n]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4calo()).Pt(),weight);

    }
    if ( n >= nMin_ && n <= nMax_ && n < MHTOvCaloMET_Lepton_.size()  ) {
    MHTOvCaloMET_Lepton_[0]->Fill(ev.CommonMHT().Pt()/calomet.Pt(),weight);
    MHTOvCaloMET_Lepton_[n]->Fill(ev.CommonMHT().Pt()/calomet.Pt(),weight);
    }


   

   int counter = 0;
   int counter_noB = 0; 
   std::set<unsigned> recojet;

   if (ev.pthat.enabled()){
      GenMatrixBin gen(&ev);
      if( n >= nMin_ && n <= nMax_ && n < Number_GenTauJets_.size() ){
         Number_GenTauJets_[0]->Fill(gen.the_GenTau.size(),weight);
         Number_GenTauJets_[n]->Fill(gen.the_GenTau.size(),weight);
      }

      //for(unsigned int i = 0; i< gen.the_GenJets_noB.size(); i++){
      //  if( n >= nMin_ && n <= nMax_ && n < GenParticle_Ids_.size()){GenParticle_Ids_[0]->Fill(gen.the_GenJets_noB.at(i)->GetID(),weight);}}

      for(unsigned int i = 0; i< gen.the_GenB.size(); i++){
        if( n >= nMin_ && n <= nMax_ && n < GenParticle_B_Jet_Ids_.size()){GenParticle_B_Jet_Ids_[0]->Fill(gen.the_GenB.at(i)->GetID(),weight);}}

      if( n >= nMin_ && n <= nMax_ && n < Number_GenBJets_.size() ){
         Number_GenBJets_[0]->Fill(gen.the_GenB.size(),weight);
         Number_GenBJets_[n]->Fill(gen.the_GenB.size(),weight);
      }
      
      std::map<std::pair<int, double>, double> error_variation_;

      for(std::vector<double>::const_iterator it = JetPt_Low_.begin();it != JetPt_Low_.end(); it++){
              error_variation_.insert(std::make_pair(std::make_pair((*it),JetPt_High_[it - JetPt_Low_.begin()]),Variation_[it - JetPt_Low_.begin()]));}

      double match_jetpt_low;
      double match_jetpt_high;
      
      for(unsigned int i = 0; i < gen.the_GenB.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenB.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }
        if(index_keeper != -1 && minDeltaR < 0.6 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5 ){

          float x = ev.JD_CommonJets().accepted.at(index_keeper)->Pt();
          for(std::vector<double>::const_iterator JetPt_it = JetPt_Low_.begin(); JetPt_it != JetPt_Low_.end(); JetPt_it++){
                if (x  > (*JetPt_it) && x < (*(JetPt_it+1))){
                match_jetpt_low = (*JetPt_it);
                match_jetpt_high = JetPt_High_[JetPt_it - JetPt_Low_.begin()];
                break;}
                else{ 
                  match_jetpt_low = 30.0;
                  match_jetpt_high = 40.0;
                 }}
          std::pair<int, double> cd = make_pair(match_jetpt_low, match_jetpt_high);
          if(error_variation_.find(cd) == error_variation_.end()){
            std::stringstream ss;
            ss << "Point: GenPt=" << match_jetpt_low << ",Higher " << match_jetpt_high << ") not found for mistag. Aborting.";
            throw std::invalid_argument(ss.str());
            }
          double sigma_correction = error_variation_.find(cd)->second;
          float SFb = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))));
          float SFb_plus = SFb + sigma_correction;
          float SFb_minus = SFb - sigma_correction;
   

          counter += 1;
          recojet.insert(index_keeper);
          //cout << "Reco Jet  " << index_keeper << "Matched to Gen BJet " << i << endl; 
          GenPt_ov_RecoPt_[0]->Fill((gen.the_GenB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt()),weight);
          GenJetPt_[0]->Fill(gen.the_GenB.at(i)->Pt(),weight);
          GenJetEta_[0]->Fill(gen.the_GenB.at(i)->Eta(),weight);
          //GenJetPt_vs_GenJetEta_[0]->Fill(gen.the_GenB.at(i)->Pt(),gen.the_GenB.at(i)->Eta(),weight);

          if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(index_keeper)->GetIndex(), 5) > 0.679){
                        //cout << "Reco Jet " << index_keeper << "Has been Btagged" << endl; 
            Btagged_GenJetPt_[0]->Fill(gen.the_GenB.at(i)->Pt(),weight);
            Btagged_GenJetEta_[0]->Fill(gen.the_GenB.at(i)->Eta(),weight);

            Btagged_GenJetPt_SFb_[0]->Fill(gen.the_GenB.at(i)->Pt(),(weight*SFb));
            Btagged_GenJetPt_SFb_plus_[0]->Fill(gen.the_GenB.at(i)->Pt(),(weight*SFb_plus));
            Btagged_GenJetPt_SFb_minus_[0]->Fill(gen.the_GenB.at(i)->Pt(),(weight*SFb_minus));
            //Matched_GenJetPt_vs_GenJetEta_[0]->Fill(gen.the_GenB.at(i)->Pt(),gen.the_GenB.at(i)->Eta(),weight);
               }
             }
            }
/////////////////////////////////////////////////////////////////////////////////////

if (ev.pthat.enabled()){

      std::set<unsigned> matched;
      for(unsigned int i = 0; i < gen.the_GenJets_noB.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenJets_noB.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }

        GenJet_DeltaR_noB_[0]->Fill(minDeltaR,weight);
        if(index_keeper != -1 && minDeltaR < 0.6 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5  ){
          counter_noB += 1;
          //cout << "Reco Jet  " << index_keeper << "Matched to Gen BJet " << i << endl; 
          GenParticle_Ids_[0]->Fill(gen.the_GenJets_noB.at(i)->GetID(),weight);
          GenPt_minus_RecoPt_noB_[0]->Fill((gen.the_GenJets_noB.at(i)->Pt() - ev.JD_CommonJets().accepted.at(index_keeper)->Pt())/gen.the_GenJets_noB.at(i)->Pt(),weight);
          GenPt_ov_RecoPt_noB_[0]->Fill((gen.the_GenJets_noB.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt()),weight);
          GenJetPt_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),weight);
          GenJetEta_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Eta(),weight);

          //GenJetPt_vs_GenJetEta_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),gen.the_GenJets_noB.at(i)->Eta(),weight);

          if ( i != 0 && matched.count(index_keeper)){ 
              //cout << "Duplicate RecoJet matched to GenJet" << endl;
              Duplicate_GenJetPt_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),weight);
              Duplicate_GenJetEta_[0]->Fill(gen.the_GenJets_noB.at(i)->Eta(),weight);
              }
            //cout << "Reco Jet " << index_keeper << "Has been Btagged" << endl;
          matched.insert(index_keeper);
          recojet.insert(index_keeper);

          if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(index_keeper)->GetIndex(), 5) > 0.679){
            
            float SFlight;
            float SFlight_minus;
            float SFlight_plus;
            float x = ev.JD_CommonJets().accepted.at(index_keeper)->Pt();
            for(std::vector<double>::const_iterator JetPt_it = JetPt_Low_.begin(); JetPt_it != JetPt_Low_.end(); JetPt_it++){
                if (x  > (*JetPt_it) && x < (*(JetPt_it+1))){
                match_jetpt_low = (*JetPt_it);
                match_jetpt_high = JetPt_High_[JetPt_it - JetPt_Low_.begin()];
                break;}
                else{
                  match_jetpt_low = 30.0;
                  match_jetpt_high = 40.0;}
              }
            std::pair<int, double> cd = make_pair(match_jetpt_low, match_jetpt_high);
            if(error_variation_.find(cd) == error_variation_.end()){
            std::stringstream ss;
            ss << "Point: GenPt=" << match_jetpt_low << ",Higher " << match_jetpt_high << ") not found for mistag. Aborting.";
            throw std::invalid_argument(ss.str());
            }
            double sigma_correction = error_variation_.find(cd)->second; 

            if(gen.the_GenJets_noB.at(i)->GetID() == 4){
              SFlight = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))));
              SFlight_minus = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))))-(2*sigma_correction);
              SFlight_plus = (0.6981*((1+(0.414063*x))/(1.+(0.300155*x))))+(2*sigma_correction); }
            else{
               SFlight = ((1.04318+(0.000848162*x))+(-2.5795e-06*(x*x)))+(1.64156e-09*(x*(x*x)));
               SFlight_minus =((0.962627+(0.000448344*x))+(-1.25579e-06*(x*x)))+(4.82283e-10*(x*(x*x))); //min
               SFlight_plus = ((1.12368+(0.00124806*x))+(-3.9032e-06*(x*x)))+(2.80083e-09*(x*(x*x))); //max
               }

            GenParticle_Ids_Btagged_[0]->Fill(gen.the_GenJets_noB.at(i)->GetID(),weight);
            Btagged_GenJetPt_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),weight);
            Btagged_GenJetEta_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Eta(),weight);

            Btagged_GenJetPt_noB_SFlight_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),(weight*SFlight));
            Btagged_GenJetPt_noB_SFlight_plus_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),(weight*SFlight_plus));
            Btagged_GenJetPt_noB_SFlight_minus_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),(weight*SFlight_minus));
            //Matched_GenJetPt_vs_GenJetEta_noB_[0]->Fill(gen.the_GenJets_noB.at(i)->Pt(),gen.the_GenJets_noB.at(i)->Eta(),weight);

              }
             }
            }
        }


/*if (ev.pthat.enabled()){

      std::set<unsigned> matched;
      for(unsigned int i = 0; i < gen.the_GenTau.size(); i++){

        float minDeltaR = 2*TMath::Pi();
        int index_keeper = -1;
        for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
          float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(j)),*(gen.the_GenTau.at(i))));
          if(aminDeltaR<minDeltaR) {
            minDeltaR=aminDeltaR;
            index_keeper = j;
              }
            }

        if(index_keeper != -1 && minDeltaR < 0.6 && gen.the_GenTau.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() > 0.5 && gen.the_GenTau.at(i)->Pt()/ev.JD_CommonJets().accepted.at(index_keeper)->Pt() < 1.5  ){
          recojet.insert(index_keeper);

             }
            }
        }*/





for(unsigned int j = 0; j < ev.JD_CommonJets().accepted.size(); j++){
     bool reco_match = false;
     for(std::set<unsigned>::iterator it = recojet.begin(); it != recojet.end(); it++){
     //for(unsigned int i = 0; i < recojet.size();i++){
      //cout << (*it) << endl;
      if(j == (*it)){
       //cout << "Jet is matched" << endl;
       reco_match = true;}
       }

     if (!reco_match){
       //cout << "Filling Histogram" << endl;
       counter_noB += 1;
       GenJetPt_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);
       GenJetEta_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Eta(),weight);
       NotMatched_RecoJet_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);

       //GenJetPt_vs_GenJetEta_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),ev.JD_CommonJets().accepted.at(j)->Eta(),weight);

       if( ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(j)->GetIndex(), 5) > 0.679){
       Btagged_NotMatched_RecoJet_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);
       float SFlight;
       float SFlight_minus;
       float SFlight_plus;
       float x = ev.JD_CommonJets().accepted.at(j)->Pt();
       SFlight = ((1.04318+(0.000848162*x))+(-2.5795e-06*(x*x)))+(1.64156e-09*(x*(x*x)));
       SFlight_minus =((0.962627+(0.000448344*x))+(-1.25579e-06*(x*x)))+(4.82283e-10*(x*(x*x))); //min
       SFlight_plus = ((1.12368+(0.00124806*x))+(-3.9032e-06*(x*x)))+(2.80083e-09*(x*(x*x))); //max

       Btagged_GenJetPt_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),weight);
       Btagged_GenJetEta_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Eta(),weight);

       Btagged_GenJetPt_noB_SFlight_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),(weight*SFlight));
       Btagged_GenJetPt_noB_SFlight_plus_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),(weight*SFlight_plus));
       Btagged_GenJetPt_noB_SFlight_minus_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),(weight*SFlight_minus));

       //Matched_GenJetPt_vs_GenJetEta_noB_[0]->Fill(ev.JD_CommonJets().accepted.at(j)->Pt(),ev.JD_CommonJets().accepted.at(j)->Eta(),weight);


       }

     }


}

if( n >= nMin_ && n <= nMax_ && n < Number_Matched_Gen_NoBJets_.size() ){
Number_Matched_Gen_NoBJets_[0]->Fill(counter_noB,weight);
Number_Matched_Gen_NoBJets_[n]->Fill(counter_noB,weight);}

if( n >= nMin_ && n <= nMax_ && n < Number_Matched_GenBJets_.size() ){
Number_Matched_GenBJets_[0]->Fill(counter,weight);
Number_Matched_GenBJets_[n]->Fill(counter,weight);}

if( n>=nMin_ && nMax_ && n < MatchedB_vs_Matched_noB_.size()){
MatchedB_vs_Matched_noB_[0]->Fill(counter,counter_noB,weight);
MatchedB_vs_Matched_noB_[n]->Fill(counter,counter_noB,weight);}

if(ev.HadronicAlphaT() > 0.55){
if( n>=nMin_ && nMax_ && n < MatchedB_vs_Matched_noB_alphaT_.size()){
MatchedB_vs_Matched_noB_alphaT_[0]->Fill(counter,counter_noB,weight);
MatchedB_vs_Matched_noB_alphaT_[n]->Fill(counter,counter_noB,weight);}
}



}

    if (isLep){

     Double_t aMT =  sqrt(2.0 * ev.PFMET().Pt() * (theLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton.at(0)), ev.PFMET() ) )));
     hLepPt_[0]->Fill(theLepton.at(0)->Pt(),weight);

     if ( n >= nMin_ && n <= nMax_ && n < hMT_.size()){
     hMT_[0]->Fill(aMT,weight);
     hMT_[n]->Fill(aMT,weight);
     }

     if(ev.HadronicAlphaT() > 0.55){
     if ( n >= nMin_ && n <= nMax_ && n < hMT_afterAlphaT_55_.size()){
     hMT_afterAlphaT_55_[0]->Fill(aMT,weight);
     hMT_afterAlphaT_55_[n]->Fill(aMT,weight);
     }
     }
 
     if ( n >= nMin_ && n <= nMax_ && n < hLepTrIso_.size()){
     hLepTrIso_[0]->Fill(((theLepton.at(0))->GetTrkIsolation())/((theLepton.at(0))->Pt()),weight);
     hLepTrIso_[n]->Fill(((theLepton.at(0))->GetTrkIsolation())/((theLepton.at(0))->Pt()),weight);
     }

     if(ev.HadronicAlphaT() > 0.55){
     if ( n >= nMin_ && n <= nMax_ && n < hLepTrIso_afterAlphaT_55_.size()){
     hLepTrIso_afterAlphaT_55_[0]->Fill(((theLepton.at(0))->GetTrkIsolation())/((theLepton.at(0))->Pt()),weight);
     hLepTrIso_afterAlphaT_55_[n]->Fill(((theLepton.at(0))->GetTrkIsolation())/((theLepton.at(0))->Pt()),weight);
     }
     }

     if ( n >= nMin_ && n <= nMax_ && n < hLepEIso_.size()){
     hLepEIso_[0]->Fill(((theLepton.at(0))->GetEcalIsolation())/((theLepton.at(0))->Et()),weight);
     hLepEIso_[n]->Fill(((theLepton.at(0))->GetEcalIsolation())/((theLepton.at(0))->Et()),weight);
     }

     if(ev.HadronicAlphaT() > 0.55){
     if ( n >= nMin_ && n <= nMax_ && n < hLepEIso_afterAlphaT_55_.size()){
     hLepEIso_afterAlphaT_55_[0]->Fill(((theLepton.at(0))->GetEcalIsolation())/((theLepton.at(0))->Et()),weight);
     hLepEIso_afterAlphaT_55_[n]->Fill(((theLepton.at(0))->GetEcalIsolation())/((theLepton.at(0))->Et()),weight);
     }
     }

     if ( n >= nMin_ && n <= nMax_ && n < hLepHIso_.size()){
     hLepHIso_[0]->Fill(((theLepton.at(0))->GetHcalIsolation())/((theLepton.at(0))->Et()),weight);
     hLepHIso_[n]->Fill(((theLepton.at(0))->GetHcalIsolation())/((theLepton.at(0))->Et()),weight);
     }

     if(ev.HadronicAlphaT() > 0.55){
     if ( n >= nMin_ && n <= nMax_ && n < hLepHIso_afterAlphaT_55_.size()){
     hLepHIso_afterAlphaT_55_[0]->Fill(((theLepton.at(0))->GetHcalIsolation())/((theLepton.at(0))->Et()),weight);
     hLepHIso_afterAlphaT_55_[n]->Fill(((theLepton.at(0))->GetHcalIsolation())/((theLepton.at(0))->Et()),weight);
     }
     }
  
     if ( n >= nMin_ && n <= nMax_ && n < hLepCIso_.size()){
     hLepCIso_[0]->Fill((theLepton.at(0))->GetCombIsolation(),weight);
     hLepCIso_[n]->Fill((theLepton.at(0))->GetCombIsolation(),weight);
     }

     if(ev.HadronicAlphaT() > 0.55){
     if ( n >= nMin_ && n <= nMax_ && n < hLepCIso_afterAlphaT_55_.size()){
     hLepCIso_afterAlphaT_55_[0]->Fill((theLepton.at(0))->GetCombIsolation(),weight);
     hLepCIso_afterAlphaT_55_[n]->Fill((theLepton.at(0))->GetCombIsolation(),weight);
     }
     }
     
    }
      
     if(ev.HadronicAlphaT() > 0.55){


      UInt_t nBtags_AT_four_55 = 0;
      UInt_t nBtags_AT_five_55 = 0;
      for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
      // std::cout << "we are on jet " << i << " the btag discriminator is " << ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 4) << std::endl;
      if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 5) > 0.679) {
      nBtags_AT_five_55++;
            //if we make it into here, the jet has passed the b-tag requirement
      } 
      if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 4) > 2.0) {
      nBtags_AT_four_55++;
             //if we make it into here, the jet has passed the b-tag requirement
      } 
   
      }

      if ( n >= nMin_ && n <= nMax_ && n < MHToverHT_afterAlphaT_55_.size() ) {
      MHToverHT_afterAlphaT_55_[0]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
      MHToverHT_afterAlphaT_55_[n]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < BtagAfterAlphaT_5_55_.size()) {
        BtagAfterAlphaT_5_55_[0]->Fill( nBtags_AT_five_55, weight );
        BtagAfterAlphaT_5_55_[n]->Fill( nBtags_AT_five_55, weight );
        }

      if ( n >= nMin_ && n <= nMax_ && n < vertexPtovHT_afterAlphaT_55_.size()) {
      vertexPtovHT_afterAlphaT_55_[0]->Fill(VertexPt/ev.CommonHT(),weight);
      vertexPtovHT_afterAlphaT_55_[n]->Fill(VertexPt/ev.CommonHT(),weight);
      }
      
      if ( n >= nMin_ && n <= nMax_ && n < NumberVerticiesAfterAlphaT_55_.size()) {
        NumberVerticiesAfterAlphaT_55_[0]->Fill(nVertex,weight);
        NumberVerticiesAfterAlphaT_55_[n]->Fill(nVertex,weight);
      }

      if ( n >= nMin_ && n <= nMax_ && n < MultiplicityAfteraT_55_.size()) {
        MultiplicityAfteraT_55_[0]->Fill( n, weight );
        MultiplicityAfteraT_55_[n]->Fill( n, weight );
      }

     for(unsigned int i = 0; i < ev.JD_CommonJets().accepted.size(); i++){
      JetPt_afterAlphaT_55_[0]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_afterAlphaT_55_[0]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
      //JetPt_afterAlphaT_55_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      //JetEta_afterAlphaT_55_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
     }

      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_HT_55_.size() ) {
        AlphatCut_HT_55_[0]->Fill( ev.CommonHT(), weight );
        AlphatCut_HT_55_[n]->Fill( ev.CommonHT(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_Meff_55_.size()) {
        AlphatCut_Meff_55_[0]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
        AlphatCut_Meff_55_[n]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
      }

    if ( n >= nMin_ && n <= nMax_ && n < MHTovMET_afterAlphaT_55_.size() ) {
        MHTovMET_afterAlphaT_55_[0]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
        MHTovMET_afterAlphaT_55_[n]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      }

    }

  }

  return true;

}
