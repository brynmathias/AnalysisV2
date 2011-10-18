#include "JetMetPasPlottingOps.hh"
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
#include "TRandom.h"
#include "JetData.hh"


using namespace Operation;

// -----------------------------------------------------------------------------
JetMetPasPlottingOps::JetMetPasPlottingOps( const Utils::ParameterSet& ps ) :
// Misc
dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
// MT2
  Plots_( ps.Get<bool>("Plots") )
  {}

// -----------------------------------------------------------------------------
//
JetMetPasPlottingOps::~JetMetPasPlottingOps() {}

// -----------------------------------------------------------------------------
//
void JetMetPasPlottingOps::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void JetMetPasPlottingOps::BookHistos() {
  if ( Plots_ )           { Plots(); }


}

// -----------------------------------------------------------------------------
//
bool JetMetPasPlottingOps::Process( Event::Data& ev ) {
  if ( Plots_ )               { Plots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& JetMetPasPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "JetMet Pas Plotting Ops ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//



void JetMetPasPlottingOps::Plots() {
//+++++++++++++++++++++++++++++++++





  BookHistArray( met_xyOverSqrtET,
    "METyxOverSqrtET",
    "",
    50,0.,10.,
    nMax_+1, 0, 1, true );



  BookHistArray( mht_xyOverSqrtHT,
    "MHTyxOverSqrtHT",
    "",
    50,0.,10.,
    nMax_+1, 0, 1, true );

  BookHistArray( HT_VS_BiasedDeltaPhi_killedJets_,
    "HT vs BiasedDeltaPhi_killJets_",
    ";BiasedDeltaPhikill;killHT",
    48,0.,TMath::Pi(),
    40,0.,400.,
    nMax_+1, 0, 1, true );


  BookHistArray( HT_VS_BiasedDeltaPhi_Jets_,
    "HT vs BiasedDeltaPhi_Jets_",
    ";BiasedDeltaPhi;HT",
    48,0.,TMath::Pi(),
    40,0.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( HT_VS_BiasedDeltaPhi_Common_,
    "HT vs BiasedDeltaPhi_Common_",
    ";BiasedDeltaPhi;HT",
    48,0.,TMath::Pi(),
    40,0.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( HT_VS_ALPHAt_Common_,
    "HT vs AlphaT_Common_",
    ";AlphaT;HT",
    60,0.,3.,
    40,0.,400.,
    nMax_+1, 0, 1, true );


  BookHistArray( HT_VS_ALPHAt_Jets_,
    "HT vs AlphaT_Jets_",
    ";AlphaT;HT",
    60,0.,3.,
    40,0.,400.,
    nMax_+1, 0, 1, true );


  BookHistArray( HTvsMHT_,
    "HT vs MHT",
    ";HT;MHT",
    80,0.,400.,
    80,0.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( HTvsMHT_X_,
    "HT vs MHTx",
    ";HT;MHT",
    80,0.,400.,
    160,-400.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( HTvsMHT_Y_,
    "HT vs MHTy",
    ";HT;MHT",
    40,0.,200.,
    160,-400.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( CaloMetYvsSUMET_,
    "#sum{E_{T}} vs METy",
    ";SumET;MET",
    40,0.,200.,
    160,-400.,400.,
    nMax_+1, 0, 1, true );


  BookHistArray( CaloMetXvsSUMET_,
    "#sum{E_{T}} vs METx",
    ";SumET;MET",
    40,0.,200.,
    160,-400.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( CaloMetXvsCaloMetY_,
    "# METx vs METy",
    ";METx (GeV);METy(GeV)",
    80,-200.,200.,
    80,-200.,200.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHTxVsMHTy_,
    "# MHTx vs MHTy",
    ";MHTx (GeV);MHTy(GeV)",
    80,-200.,200.,
    80,-200.,200.,
    nMax_+1, 0, 1, true );


  BookHistArray( MHTvsMET_,
    "# MHT vs MET",
    ";MHT (GeV);MET(GeV)",
    80,0.,400.,
    80,0.,400.,
    nMax_+1, 0, 1, true );



  BookHistArray( MHT_Y_,
    "MHT Y",
    ";MHT Y (GeV);",
    160,-400.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHT_X_,
    "MHT X",
    ";MHT X (GeV);",
    160,-400.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( MET_Pt_,
    "MET PT",
    ";Pt (GeV);",
    200,0.,1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( CALO_MET_,
    "Callo MET",
    ";Pt (GeV);",
    200,0.,1000.,
    nMax_+1, 0, 1, true );

  BookHistArray( CaloMetvsSUMET_,
    "#sum{E_{T}} vs Calo MET",
    ";#sum{E_{T}};Calo MET",
    40,0.,400.,
    40,0.,400.,
    nMax_+1, 0, 1, true );

  BookHistArray( SumETvsHT_,
    "#sum{E_{T}} vs HT",
    ";#sum{E_{T}}; HT",
    40,0.,400.,
    40,0.,400.,
    nMax_+1, 0, 1, true );


  BookHistArray( SumETvsMHT_,
    "#sum{E_{T}} vs MHT",
    ";#sum{E_{T}}; MHT",
    40,0.,400.,
    40,0.,400.,
    nMax_+1, 0, 1, true );

}


bool JetMetPasPlottingOps::Plots( Event::Data& ev ){

      // Event weight
  Double_t weight = ev.GetEventWeight();
  Double_t ht=0.;
  LorentzV mht(0.,0.,0.,0.);
  std::vector<Event::Jet const *> jets = ev.JD_CommonJets().accepted;
  // std::vector< Event::Jet const*>::iterator ijet = ev.JD_CommonJets().accepted.begin();
  // std::vector< Event::Jet const*>::iterator jjet = ev.JD_CommonJets().accepted.end();
  UInt_t n = jets.size();
  UInt_t tot = ev.CommonObjects().size();

  std::vector<bool> pseudo;
  double alpha_t = AlphaT()( ev.JD_CommonJets().accepted, pseudo, false );
  if ( pseudo.size() != n ) { abort(); }

  std::vector<bool> pseudoAll;
  double alpha_tInclusive = AlphaT()(ev.CommonObjects(), pseudoAll, false);
  if(pseudoAll.size() != tot){abort();}


    // Recoil MET from raw ntuple objects

  for ( int i = 0 ; i < n ; i++ ) {
    mht -= *jets[i];
    ht+=jets[i]->Et();
  }



//loop over jets and calculate HT amd MHT and kill jet
  TRandom myRand;// = new TRandom();
  float ran = myRand.Uniform(0.,float(jets.size()));
  LorentzV mhtkill(0,0,0,0);
  float htkill = 0;
  int toKill = int(ran);
    //  cout << toKill << " njets " << jets.size() << endl;
  for ( int i = 0 ; i < n ; i++ ) {
    if (i==toKill) continue;
    mhtkill -= *jets[i];
    htkill+=jets[i]->Et();
    // cout << " HT KILL " << htkill << endl;
  }
  float minDPhi = 100.;

  for ( int i = 0 ; i < n ; i++ ) {
    float iDPhi =  fabs(ROOT::Math::VectorUtil::DeltaPhi((*jets[i]),mht+(*jets[i])));
    if(iDPhi<minDPhi) minDPhi=iDPhi;
    // cout << " MIN D PHI  " << minDPhi << " iDphi  " << iDPhi << endl;

  }

  float minDPhikill = 100.;
  for ( int i = 0 ; i < n ; i++ ) {
    if (i==toKill) continue;
    float iDPhikill =  fabs(ROOT::Math::VectorUtil::DeltaPhi((*jets[i]),mhtkill+(*jets[i])));
    if(iDPhikill<minDPhikill) minDPhikill=iDPhikill;
    // cout << " MIN D PHI KILL " << minDPhikill << " iDphi Kill " << iDPhikill << endl;
  }

    // cout << "toKill" << minDPhi <<" " << minDPhikill << endl;
  if( Plots_ ){



    //
    // if(alpha_t>0.55&&ht>120){
    //   cout << " ARRRG bad event " <<endl<<endl;
    //   cout << "lumi Section"<< ev.LumiSection() << " run : " <<  ev.RunNumber()<< " event : "<<  ev.EventNumber() << endl;
    //   cout << "x-cleaned"<<endl;
    //   ev.PrintStableVisRec();
    //   cout << "all"<<endl;
    //   ev.PrintStableVisAllRec();
    // }






  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //++++++++++++++++++++++++++++++ THIS SECTION IS FOR EDITS TO THE SIG:SIG PLOTS +++++++++++++++++++++++++++++++++++++++
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




    if ( n >= nMin_ && n <= nMax_ && n < mht_xyOverSqrtHT.size() && n <= Event::KS_MinDEt_MaxN() ) {
      mht_xyOverSqrtHT[0]->Fill(fabs(mht.Px()/sqrt( ht )), weight );
      mht_xyOverSqrtHT[0]->Fill(fabs(mht.Py()/sqrt( ht )), weight );
      mht_xyOverSqrtHT[n]->Fill(fabs(mht.Px()/sqrt( ht )), weight );
      mht_xyOverSqrtHT[n]->Fill(fabs(mht.Py()/sqrt( ht )), weight );
    }


    if ( n >= nMin_ && n <= nMax_ && n < met_xyOverSqrtET.size() && n <= Event::KS_MinDEt_MaxN() ) {
      met_xyOverSqrtET[0]->Fill(fabs(ev.CaloMET().Px()/sqrt( ev.SumEt()) ), weight );
      met_xyOverSqrtET[0]->Fill(fabs(ev.CaloMET().Py()/sqrt( ev.SumEt()) ), weight );
      met_xyOverSqrtET[n]->Fill(fabs(ev.CaloMET().Px()/sqrt( ev.SumEt()) ), weight );
      met_xyOverSqrtET[n]->Fill(fabs(ev.CaloMET().Py()/sqrt( ev.SumEt()) ), weight );
    }






  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //++++++++++++++++++++++++++++++ THIS SECTION IS THE REQUESTED PLOTS FOR THE SUSY PS+++++++++++++++++++++++++++++++++++
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



  if ( n >= nMin_ && n <= nMax_ && n < HT_VS_ALPHAt_Common_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HT_VS_ALPHAt_Common_[0]->Fill( alpha_tInclusive, ev.CommonHT(), weight );
    HT_VS_ALPHAt_Common_[n]->Fill( alpha_tInclusive, ev.CommonHT(),  weight );
  }


  if ( n >= nMin_ && n <= nMax_ && n < HT_VS_ALPHAt_Jets_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HT_VS_ALPHAt_Jets_[0]->Fill( alpha_t, ht, weight );
    HT_VS_ALPHAt_Jets_[n]->Fill( alpha_t, ht,  weight );
  }






  if ( n >= nMin_ && n <= nMax_ && n < HT_VS_BiasedDeltaPhi_Common_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HT_VS_BiasedDeltaPhi_Common_[0]->Fill( ev.CommonMinBiasDPhi(), ev.CommonHT(), weight );
    HT_VS_BiasedDeltaPhi_Common_[n]->Fill( ev.CommonMinBiasDPhi(), ev.CommonHT(),  weight );
  }


  if ( n >= nMin_ && n <= nMax_ && n < HT_VS_BiasedDeltaPhi_Jets_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HT_VS_BiasedDeltaPhi_Jets_[0]->Fill( minDPhi, ht, weight );
    HT_VS_BiasedDeltaPhi_Jets_[n]->Fill( minDPhi, ht,  weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < HT_VS_BiasedDeltaPhi_killedJets_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HT_VS_BiasedDeltaPhi_killedJets_[0]->Fill( minDPhikill, htkill, weight );
    HT_VS_BiasedDeltaPhi_killedJets_[n]->Fill( minDPhikill, htkill,  weight );
  }










  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //++++++++++++++++++++++++++++++ HERE ENDS THE REQUESTED PLOTS FOR THE SUSY PS+++++++++++++++++++++++++++++++++++
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++








//+++++++++++++++++++OFFICAL PLOTS FOR MET_PAS++++++++++++++++++++++++++++++++++


  if ( n >= nMin_ && n <= nMax_ && n < CALO_MET_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    CALO_MET_[0]->Fill( ev.CaloMET().Pt(), weight );
    CALO_MET_[n]->Fill( ev.CaloMET().Pt(), weight );
  }


  if ( n >= nMin_ && n <= nMax_ && n < CaloMetvsSUMET_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    CaloMetvsSUMET_[0]->Fill( ev.SumEt(), ev.CaloMET().Et(), weight );
    CaloMetvsSUMET_[n]->Fill( ev.SumEt(), ev.CaloMET().Et(),  weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < CaloMetXvsSUMET_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    CaloMetXvsSUMET_[0]->Fill( ev.SumEt(), ev.CaloMET().Px(), weight );
    CaloMetXvsSUMET_[n]->Fill( ev.SumEt(), ev.CaloMET().Px(),  weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < CaloMetYvsSUMET_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    CaloMetYvsSUMET_[0]->Fill( ev.SumEt(), ev.CaloMET().Py(), weight );
    CaloMetYvsSUMET_[n]->Fill( ev.SumEt(), ev.CaloMET().Py(),  weight );
  }
  if ( n >= nMin_ && n <= nMax_ && n < MHTvsMET_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    MHTvsMET_[0]->Fill( mht.Pt(), ev.CaloMET().Et(), weight );
    MHTvsMET_[n]->Fill( mht.Pt(), ev.CaloMET().Et(),  weight );
  }



  if ( n >= nMin_ && n <= nMax_ && n < MHTxVsMHTy_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    MHTxVsMHTy_[0]->Fill( mht.Px(), mht.Py() , weight );
    MHTxVsMHTy_[n]->Fill( mht.Px(), mht.Py() , weight );
  }


  if ( n >= nMin_ && n <= nMax_ && n < CaloMetXvsCaloMetY_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    CaloMetXvsCaloMetY_[0]->Fill( ev.CaloMET().Px(), ev.CaloMET().Py(), weight );
    CaloMetXvsCaloMetY_[n]->Fill( ev.CaloMET().Px(), ev.CaloMET().Py(),  weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < SumETvsMHT_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    SumETvsMHT_[0]->Fill( ev.SumEt(), mht.Pt() , weight );
    SumETvsMHT_[n]->Fill( ev.SumEt(), mht.Pt() , weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < SumETvsHT_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    SumETvsHT_[0]->Fill( ev.SumEt(), ht , weight );
    SumETvsHT_[n]->Fill( ev.SumEt(), ht , weight );
  }


  if ( n >= nMin_ && n <= nMax_ && n < HTvsMHT_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HTvsMHT_[0]->Fill( ht, mht.Pt() , weight );
    HTvsMHT_[n]->Fill( ht, mht.Pt() , weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < HTvsMHT_X_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HTvsMHT_X_[0]->Fill( ht, mht.Px() , weight );
    HTvsMHT_X_[n]->Fill( ht, mht.Px() , weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < HTvsMHT_Y_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    HTvsMHT_Y_[0]->Fill( ht, mht.Py() , weight );
    HTvsMHT_Y_[n]->Fill( ht, mht.Py() , weight );
  }


  if ( n >= nMin_ && n <= nMax_ && n < MHT_X_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    MHT_X_[0]->Fill( mht.Px() , weight );
    MHT_X_[n]->Fill( mht.Px() , weight );
  }

  if ( n >= nMin_ && n <= nMax_ && n < MHT_Y_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    MHT_Y_[0]->Fill( mht.Py() , weight );
    MHT_Y_[n]->Fill( mht.Py() , weight );
  }


}


return true;

}

