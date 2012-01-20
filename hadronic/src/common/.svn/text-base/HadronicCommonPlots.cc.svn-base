#include "HadronicCommonPlots.hh"
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

// -----------------------------------------------------------------------------
HadronicCommonPlots::HadronicCommonPlots( const Utils::ParameterSet& ps ) :
  // Misc
  dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
  //Plotting Categories
  StandardPlots_( ps.Get<bool>("StandardPlots") ),
  DeadECALPlots_( ps.Get<bool>("DeadECALPlots") ),
  CleaningControlPlots_( ps.Get<bool>("CleaningControlPlots") ),
  MECPlots_( ps.Get<bool>("MECPlots") ),
  deadECALFile_(ps.Get<std::string>("DeadECALFile") ),
  deadECAL_minJetPTCut_(ps.Get<double>("DeadECAL_MinJetPtCut") ),
  deadECAL_minBiasCut_(ps.Get<double>("DeadECAL_MinBiasCut") ),
  deadECAL_nBadCellsCut_(ps.Get<int>("DeadECAL_NBadCellsCut") )
  {}

// -----------------------------------------------------------------------------
//
HadronicCommonPlots::~HadronicCommonPlots() {}

// -----------------------------------------------------------------------------
//
void HadronicCommonPlots::Start( Event::Data& ev ) {

  TDirectory* headDir = returnDir(ev.OutputFile(),dirName_.c_str());



  if(StandardPlots_){
    initDir(headDir,"StandardPlots");
    StandardPlots();

  }
  if(DeadECALPlots_){
    initDir(headDir,"DeadECALPlots");
    DeadECALPlots();
  }
  if(CleaningControlPlots_){
    initDir(headDir,"CleaningControlPlots");
    CleaningControlPlots();
  }
  if(MECPlots_){
    initDir(headDir,"MECPlots");
    MECPlots();
  }

  BookHistos();
}

void HadronicCommonPlots::BookHistos() {


}

// -----------------------------------------------------------------------------
//
bool HadronicCommonPlots::Process( Event::Data& ev ) {

  std::ofstream ostrm("hadronicDump.txt",fstream::app);


  if ( StandardPlots_ )               { StandardPlots(ev); }
  // if ( DeadECALPlots_) {DeadECALPlots(ev,ostrm); }
  if ( CleaningControlPlots_) {CleaningControlPlots(ev); }
  if ( MECPlots_) {MECPlots(ev); }

  ostrm.close();


  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& HadronicCommonPlots::Description( std::ostream& ostrm ) {
  ostrm << "Hadronic Common Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") " << endl;


  std::ifstream mystrm("event.txt");

  char * buffer;
  long size;

  // get size of file
  mystrm.seekg(0,ifstream::end);
  size=mystrm.tellg();
  mystrm.seekg(0);
  // allocate memory for file content
  buffer = new char [size];

  // read content of infile
  mystrm.read (buffer,size);
  //   mystrm >> output;
  std::cout << "buffer: "<< buffer <<endl;
  ostrm << buffer;
  return ostrm;

}

// -----------------------------------------------------------------------------
//

void HadronicCommonPlots::DeadECALPlots(){

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

void HadronicCommonPlots::CleaningControlPlots(){

  BookHistArray(Noisy_ECALO_MHT_,
    "Noisy_ECALO_MHT",
    ";Noisy_ECALO_MHT;",
    400,0,2000,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_ECALO_HT_,
    "Noisy_ECALO_HT",
    ";Noisy_ECALO_HT;",
    400,0,2000,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_ECALO_DR_,
    "Noisy_ECALO_DR",
    ";Noisy_ECALO_DR;",
    400,0,10,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_ECALO_BiasDPhi_,
    "Noisy_ECALO_BiasDPhi",
    ";Noisy_ECALO_BiasDPhi;",
    400,0,10,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_ECALO_minDR_,
    "Noisy_ECALO_minDR",
    ";Noisy_ECALO_mindDR;",
    400,0,10,
    nMax_+1,0,1,true);

   BookHistArray(Noisy_HCALO_DR_,
    "Noisy_HCALO_DR",
    ";Noisy_HCALO_DR;",
    400,0,10,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_HCALO_BiasDPhi_,
    "Noisy_HCALO_BiasDPhi",
    ";Noisy_HCALO_BiasDPhi;",
    400,0,10,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_HCALO_minDR_,
    "Noisy_HCALO_minDR",
    ";Noisy_HCALO_mindDR;",
    400,0,10,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_HCALO_MHT_,
    "Noisy_HCALO_MHT",
    ";Noisy_HCALO_MHT;",
    400,0,2000,
    nMax_+1,0,1,true);

  BookHistArray(Noisy_HCALO_HT_,
    "Noisy_HCALO_HT",
    ";Noisy_HCALO_HT;",
    400,0,2000,
    nMax_+1,0,1,true);


  BookHistArray( Noisy_Eta_Phi_,
     "Noisy_Eta_Phi",
     ";#eta;#phi;",
     100,-5,5,
     20*(TMath::Pi()),-(TMath::Pi()),TMath::Pi(),
     nMax_+1,0,1,true);


  BookHistArray( TrackPtOvHT_,
     "TrackPtOvHT",
     ";TrackPtOvHT;",
     1000,0,10,
     nMax_+1,0,1,true);

}


void HadronicCommonPlots::MECPlots(){

  // cout << " in book plots " << endl;

  BookHistArray(MHTPFMETDiffOvMeff_,
    "MHTPFMETDiffOvMeff",
    "#frac{MHT-PFMET}{Meff}",
    600,-1.5,1.5,
    nMax_+1,0,1,true);

  BookHistArray(MHTPFMETDiffOvMeff_vs_HT_,
    "MHTPFMETDiffOvMeff_vs_HT",
    ";#frac{MHT-PFMET}{Meff};H_{T}",
    600,-1.5,1.5,
    160,0,8000,
    nMax_+1,0,1,true);

  BookHistArray(MHTPFMETDiffOvMeff_vs_Meff_,
    "MHTPFMETDiffOvMeff_vs_Meff",
    ";#frac{MHT-PFMET}{Meff};Meff",
    600,-1.5,1.5,
    160,0,8000,
    nMax_+1,0,1,true);

    BookHistArray(MHTCaloMETDiff_,
    "MHTCaloMETDiff",
    "MHT-CaloMET",
    500,-100,100,
    nMax_+1,0,1,true);



  BookHistArray(MHTCaloMETDiffOvMeff_,
    "MHTCaloMETDiffOvMeff",
    "#frac{MHT-CaloMET}{Meff}",
    600,-1.5,1.5,
    nMax_+1,0,1,true);

  BookHistArray(MHTCaloMETDiffOvMeff_vs_HT_,
    "MHTCaloMETDiffOvMeff_vs_HT",
    ";#frac{MHT-CaloMET}{Meff};HT",
    600,-1.5,1.5,
    160,0,8000,
    nMax_+1,0,1,true);

  BookHistArray(MHTCaloMETDiffOvMeff_vs_Meff_,
    "MHTCaloMETDiffOvMeff_vs_Meff",
    ";#frac{MHT-CaloMET}{Meff};Meff",
    600,-1.5,1.5,
    160,0,8000,
    nMax_+1,0,1,true);

  BookHistArray(PFMET_vs_MHTPFMETDiffOvMeff_,
    "PFMET_vs_MHTPFMETDiffOvMeff",
    ";PFMET;#frac{MHT-PFMET}{Meff}",
    200,0,5000,300,-1.5,1.5,
    nMax_+1,0,1,true);

  BookHistArray(MHTOvPFMET_,
    "MHTOvPFMET",
    ";MHTOvPFMET",
    500,0,50,
    nMax_+1,0,1,true);

  BookHistArray(MHTOvPFMET_vs_HT_,
    "MHTOvPFMET_HT_",
    ";MHTOvPFMET",
    500,0,50,
    160,0,8000,
    nMax_+1,0,1,true);

  BookHistArray(MHTOvPFMET_vs_Meff_,
    "MHTOvPFMET_Meff_",
    ";MHTOvPFMET",
    500,0,50,
    160,0,8000,
    nMax_+1,0,1,true);

  BookHistArray(MHTOvCaloMET_,
    "MHTOvCaloMET",
    ";MHTOvCaloMET",
    1000,0,50,
    nMax_+1,0,1,true);

  BookHistArray(MHTOvCaloMET_vs_HT_,
    "MHTOvCaloMET_vs_HT_",
    ";MHTOvCaloMET;HT",
    1000,0,50,
    160,0,8000,
    nMax_+1,0,1,true);

   BookHistArray(MHTOvCaloMET_vs_Meff_,
    "MHTOvCaloMET_vs_Meff_",
    ";MHTOvCaloMET;Meff",
    1000,0,50,
    160,0,8000,
    nMax_+1,0,1,true);

   BookHistArray(MHT_vs_PFMET_,
    "MHT_vs_PFMET",
    ";MHT_vs_PFMET",
    1000,0,5000,
     500,0,5000,
    nMax_+1,0,1,true);



  BookHistArray( BabyJetMHT_10_50_,
     "BabyJetMHT_10_50",
     ";BabyJetMHT;Events/5GeV;",
     60, .0, 300.,
     nMax_+1, 0, 1, true );




  BookHistArray( MissedMHT_,
     "MHTRatio",
     ";MHT50/MHT10;Events/0.1;",
     200, 0., 10,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_vs_HT_,
     "MHTRatio_vs_HT",
     ";MHT50/MHT10;HT;",
     200, 0., 10,
     160,0,8000,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_vs_Meff_,
     "MHTRatio_vs_Meff",
     ";MHT50/MHT10;Meff;",
     200, 0., 10,
     160,0,8000,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_30_50_,
     "MHTRatio_30_50",
     ";MHT50/MHT30;Events/0.1;",
     200, 0., 10,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_30_50_vs_HT_,
     "MHTRatio_30_50_vs_HT",
     ";MHT50/MHT30;HT;",
     200, 0., 10,
     160,0,8000,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_30_50_vs_Meff_,
     "MHTRatio_30_50_vs_Meff",
     ";MHT50/MHT30;HT;",
     200, 0., 10,
     160,0,8000,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_20_50_,
     "MHTRatio_20_50",
     ";MHT50/MHT20;Events/0.1;",
     200, 0., 10,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_20_50_vs_HT_,
     "MHTRatio_20_50_vs_HT",
     ";MHT50/MHT20;HT;",
     200, 0., 10,
     160,0,8000,
     nMax_+1, 0, 1, true );

  BookHistArray( MissedMHT_20_50_vs_Meff_,
     "MHTRatio_20_50_vs_Meff",
     ";MHT50/MHT20;HT;",
     200, 0., 10,
     160,0,8000,
     nMax_+1, 0, 1, true );

  // cout << " after book plots "<< endl;
}




void HadronicCommonPlots::StandardPlots() {


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
    60,0.,1.5,
    nMax_+1, 0, 1, true );

  BookHistArray( AlphaT_Zoomed_,
    "AlphaT_Zoomed",
    ";#alpha_{T}; Events/0.0025;",
    60,0.45,0.6,
    nMax_+1, 0, 1, true );


  BookHistArray( AlphaT_Hadronic_,
    "AlphaT_Hadronic",
    ";#alpha_{T};Events/0.025;",
    60,0.,1.5,
    nMax_+1, 0, 1, true );


  BookHistArray( BiasedDphi_pT50GeV_,
     "BiasedDeltaPhi_pT50GeV",
     ";#Delta #phi^{*} (rad); Events/0.05 rad;",
     60, 0., TMath::Pi(),
     nMax_+1, 0, 1, true );



  BookHistArray( HT_,
    "HT",
    ";H_{T} (GeV); Events/25 GeV;",
    80,0.,2000.,
    nMax_+1, 0, 1, true );

  BookHistArray( Meff_,
    "EffectiveMass",
    ";M_{eff} (GeV); Events/40 GeV;",
    75, 0., 3000.,
    nMax_+1, 0, 1, true );

  BookHistArray( MHT_,
    "MHT",
    ";#slash{H}_{T} (GeV); Events/10 GeV;",
    40,0.,1000.,
    nMax_+1, 0, 1, true );

   BookHistArray( PFMET_,
    "PFMET",
    ";PFMET (GeV); Events/10 GeV;",
    40,0.,1000.,
    nMax_+1, 0, 1, true );


  BookHistArray( MHTOvHT_,
    "MHTOvHT",
    ";#slash{H}_{T}/H_{T};Events/0.025;",
    40,0.,1.,
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

  BookHistArray( JetMultiplicity_,
    "JetMultiplicity_",
    ";JetMultiplicity ; Events ",
    10,-0.5,9.5,
    nMax_+1, 0, 1, true );








}
// -----------------------------------------------------------------------------
//

Double_t HadronicCommonPlots::MT2_Leading( Event::Data& ev ){
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


Double_t HadronicCommonPlots::MT2( Event::Data& ev){

  std::vector<Event::Jet const *> jet = ev.JD_CommonJets().accepted;
  UInt_t n = jet.size();

  mt2_bisect::mt2 mt2_event;

  LorentzV lv1(0.,0.,0.,0.);
  LorentzV lv2(0.,0.,0.,0.);

  // Alpha_t variable
  std::vector<bool> pseudo;

  // cout << " ha "<< endl;
  double alpha_t = AlphaT()( jet, pseudo, false );
  if ( pseudo.size() != jet.size() ) { abort(); }
    // use this to get the pseudo jets
  // cout << " he " << endl;
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



bool HadronicCommonPlots::StandardPlots( Event::Data& ev ) {

  //  cout << "hi ho " << endl;

  UInt_t n = ev.CommonObjects().size();
  if(n > nMax_) n = nMax_;
  if(n < nMin_) n = nMin_;

  Double_t weight = ev.GetEventWeight();

   UInt_t numberJets = ev.JD_CommonJets().accepted.size();


  if ( StandardPlots_ ){

    JetMultiplicity_[0]->Fill(numberJets,weight);
    JetMultiplicity_[n]->Fill(numberJets,weight);

    Mt2_LeadingJets_[0]->Fill( HadronicCommonPlots::MT2_Leading(ev), weight );
    Mt2_LeadingJets_[n]->Fill( HadronicCommonPlots::MT2_Leading(ev), weight );

    MHT_[0]->Fill( ev.CommonMHT().Pt(), weight );
    MHT_[n]->Fill( ev.CommonMHT().Pt(), weight );

    BiasedDphi_pT50GeV_[0]->Fill(ev.CommonMinBiasDPhi(),weight);
    BiasedDphi_pT50GeV_[n]->Fill(ev.CommonMinBiasDPhi(),weight);

    PFMET_[0]->Fill( ev.PFMET().Pt(), weight );
    PFMET_[n]->Fill( ev.PFMET().Pt(), weight );

    HT_[0]->Fill( ev.CommonHT(), weight );
    HT_[n]->Fill( ev.CommonHT(), weight );

    MHTOvHT_[0]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
    MHTOvHT_[n]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );

    Meff_[0]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
    Meff_[n]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );

    AlphaT_Hadronic_[0]->Fill( ev.hadAlpha_t(), weight );
    AlphaT_Hadronic_[n]->Fill( ev.hadAlpha_t(), weight );

    AlphaT_Zoomed_[0]->Fill( ev.CommonAlphaT(), weight );
    AlphaT_Zoomed_[n]->Fill( ev.CommonAlphaT(), weight );

    AlphaT_[0]->Fill( ev.CommonAlphaT(), weight );
    AlphaT_[n]->Fill( ev.CommonAlphaT(), weight );

    for(unsigned int i = 0; i < ev.JD_CommonJets().accepted.size() && i < 3; i++){

      fem_[0]->Fill(ev.JD_CommonJets().accepted[i]->GetEmFrac(),weight);
      JetPt_[0]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_[0]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
      fem_[i]->Fill(ev.JD_CommonJets().accepted[i]->GetEmFrac(),weight);
      JetPt_[i]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_[i]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
    }

  }
  return true;

}

bool HadronicCommonPlots::DeadECALPlots( Event::Data& ev, std::ostream& ostrm ) {

  //  cout << " in dead ecal plots " << endl;

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
  if(DeadECALPlots_){


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

      if(newBiasDPhi < biasedDPhi){
  biasedDPhi = newBiasDPhi;

  deadECALDR = ECALDR;

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

  if(newBiasDPhi_2 < biasedDPhi){
    biasedDPhi = newBiasDPhi_2;

    deadECALDR = ECALDR;

    minEta = (*iI)->Eta();
    minPhi = (*iI)->Phi();

  }
      }
    }

    if( biasedDPhi < deadECAL_minBiasCut_ && deadECALDR < 0.5){

      for( std::vector<Event::Jet const *>::const_iterator i = ev.JD_CommonJets().accepted.begin();
             i != ev.JD_CommonJets().accepted.end();
             ++i ){
          EtaPhi_DeadECAL_[0]->Fill((*i)->Eta(),(*i)->Phi(),weight);
          EtaPhi_DeadECAL_[n]->Fill((*i)->Eta(),(*i)->Phi(),weight);
        }
      }



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


bool HadronicCommonPlots::CleaningControlPlots(Event::Data& ev){

   UInt_t n = ev.CommonObjects().size();
   if(n > nMax_) n = nMax_;
  if(n < nMin_) n = nMin_;

   Double_t weight = ev.GetEventWeight();

   Double_t ECAL_allminDR = 100;
   Double_t HCAL_allminDR = 100;

   Double_t biasedDPhi = 100;
   Double_t ECAL_CleanedDR = 100;
   Double_t HCAL_CleanedDR = 100;

   Double_t newBiasDPhi = 100;
   Double_t badECALDR = 100;
   Double_t badHCALDR = 100;
   Double_t ECAL_myBiasDPhi = 100;
   Double_t HCAL_myBiasDPhi = 100;

   //calculate MHT take into account babyJets
    LorentzV loweredMHT = ev.CommonRecoilMET();
    for(std::vector<Event::Jet const*>::const_iterator iM = ev.JD_CommonJets().baby.begin();iM != ev.JD_CommonJets().baby.end();++iM){
      if( (*iM)->Pt() > 30)loweredMHT -= (**iM);
    }


    for( std::vector<Event::Jet const *>::const_iterator i = ev.JD_CommonJets().accepted.begin();
   i != ev.JD_CommonJets().accepted.end();
   ++i ){

      newBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**i,loweredMHT + (**i))) ;

      try{
  ECAL_CleanedDR = NoisyECALRecHitDR(ev,(*i)->Phi(),(*i)->Eta(),1);
  HCAL_CleanedDR = NoisyHCALRecHitDR(ev,(*i)->Phi(),(*i)->Eta(),9);
      }
      catch(...){}

      if(ECAL_CleanedDR < ECAL_allminDR){
  ECAL_allminDR = ECAL_CleanedDR;
  ECAL_myBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**i,loweredMHT + (**i)));
      }
      if(HCAL_CleanedDR < HCAL_allminDR){
  HCAL_allminDR = HCAL_CleanedDR;
  HCAL_myBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**i,loweredMHT + (**i)));
      }


      if(newBiasDPhi < biasedDPhi){
  biasedDPhi = newBiasDPhi;
  badECALDR = ECAL_CleanedDR;
  badHCALDR = HCAL_CleanedDR;
      }
    }

    for( std::vector<Event::Jet const*>::const_iterator iI = ev.JD_CommonJets().baby.begin(); iI != ev.JD_CommonJets().baby.end();
   ++iI) {
      if((*iI)->Pt() > 30){

  newBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**iI,loweredMHT + (**iI))) ;

      try{
  ECAL_CleanedDR = NoisyECALRecHitDR(ev,(*iI)->Phi(),(*iI)->Eta(),1);
  HCAL_CleanedDR = NoisyHCALRecHitDR(ev,(*iI)->Phi(),(*iI)->Eta(),9);
      }
      catch(...){}

      if(ECAL_CleanedDR < ECAL_allminDR){
  ECAL_allminDR = ECAL_CleanedDR;
  ECAL_myBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**iI,loweredMHT + (**iI)));
      }
      if(HCAL_CleanedDR < HCAL_allminDR){
  HCAL_allminDR = HCAL_CleanedDR;
  HCAL_myBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(**iI,loweredMHT + (**iI)));
      }


      if(newBiasDPhi < biasedDPhi){
  biasedDPhi = newBiasDPhi;
  badECALDR = ECAL_CleanedDR;
  badHCALDR = HCAL_CleanedDR;
      }



      }
    }

    //  cout << " cleandDR " << HCAL_CleanedDR << " mindr " << HCAL_allminDR <<  " my biasDPhi " << HCAL_myBiasDPhi << endl;



   Double_t noisy_ECalo_HT = 0;
   LorentzV noisy_ECalo_MHT;
   noisy_ECalo_MHT.SetPxPyPzE(0.,0.,0.,0.);

   Double_t noisy_HCalo_HT = 0;
   LorentzV noisy_HCalo_MHT;
   noisy_HCalo_MHT.SetPxPyPzE(0.,0.,0.,0.);



   int idx = 0;

  if ( CleaningControlPlots_ ){

    try{
      //fill ECAL cleaned hits
       for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Eb()->begin();ii!=ev.rechitCaloP4Eb()->end();++ii,++idx){
   if(ev.rechitCaloSeverityLevelEb()->at(idx) > 1){
     noisy_ECalo_HT = noisy_ECalo_HT+ (*ii).Et();
     noisy_ECalo_MHT -=(*ii);

     Noisy_Eta_Phi_[0]->Fill((*ii).Eta(),(*ii).Phi(),weight);
     Noisy_Eta_Phi_[n]->Fill((*ii).Eta(),(*ii).Phi(),weight);
   }
  }
   idx = 0;
        for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Ee()->begin();ii!=ev.rechitCaloP4Ee()->end();++ii,++idx){
    if(ev.rechitCaloSeverityLevelEe()->at(idx) > 1){
      noisy_ECalo_HT = noisy_ECalo_HT+ (*ii).Et();
      noisy_ECalo_MHT -=(*ii);
    }
  }
  idx= 0;
  //fill HCAL cleaned hits
  for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Hbhe()->begin();ii!=ev.rechitCaloP4Hbhe()->end();++ii,++idx){
   if(ev.rechitCaloSeverityLevelHbhe()->at(idx) > 9){
     noisy_HCalo_HT = noisy_HCalo_HT+ (*ii).Et();
     noisy_HCalo_MHT -=(*ii);
   }
  }
   idx = 0;
        for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Hf()->begin();ii!=ev.rechitCaloP4Hf()->end();++ii,++idx){
    if(ev.rechitCaloSeverityLevelHf()->at(idx) > 9){
      noisy_HCalo_HT = noisy_HCalo_HT+ (*ii).Et();
      noisy_HCalo_MHT -=(*ii);
    }
  }

      }
    catch(...){}

    double vtx_HT = 0;
    idx = 0;
    try{
      for(std::vector<floatle>::const_iterator vtx = ev.vertexSumPt()->begin();vtx != ev.vertexSumPt()->end();++vtx,++idx){
  vtx_HT = vtx_HT+(*vtx);
  //cout << " idx " << idx << " vtx " << *vtx << endl;
      }

    }
    catch(...){}
    //cout << "Run: "<< ev.RunNumber() <<" Event: " << ev.EventNumber() << " LS: " << ev.LumiSection() << " vertex HT " << vtx_HT << " vtxHT/SumHT " << vtx_HT/ev.CommonHT() << endl;

    TrackPtOvHT_[0]->Fill(vtx_HT/ev.CommonHT(),weight);
    TrackPtOvHT_[n]->Fill(vtx_HT/ev.CommonHT(),weight);

    if(biasedDPhi < 0.5){
      Noisy_ECALO_DR_[0]->Fill(badECALDR,weight);
      Noisy_ECALO_DR_[n]->Fill(badECALDR,weight);
      Noisy_HCALO_DR_[0]->Fill(badHCALDR,weight);
      Noisy_HCALO_DR_[n]->Fill(badHCALDR,weight);
    }

    if(ECAL_allminDR < 0.3){
      Noisy_ECALO_BiasDPhi_[0]->Fill(ECAL_myBiasDPhi,weight);
      Noisy_ECALO_BiasDPhi_[n]->Fill(ECAL_myBiasDPhi,weight);
    }
    if(HCAL_allminDR < 0.3){
      Noisy_HCALO_BiasDPhi_[0]->Fill(HCAL_myBiasDPhi,weight);
      Noisy_HCALO_BiasDPhi_[n]->Fill(HCAL_myBiasDPhi,weight);
    }

    Noisy_ECALO_minDR_[0]->Fill(ECAL_allminDR,weight);
    Noisy_ECALO_minDR_[n]->Fill(ECAL_allminDR,weight);

    Noisy_HCALO_minDR_[0]->Fill(HCAL_allminDR,weight);
    Noisy_HCALO_minDR_[n]->Fill(HCAL_allminDR,weight);

    Noisy_ECALO_MHT_[0]->Fill(fabs(noisy_ECalo_MHT.Et()), weight );
    Noisy_ECALO_MHT_[n]->Fill(fabs(noisy_ECalo_MHT.Et()), weight );


    Noisy_ECALO_HT_[0]->Fill(noisy_ECalo_HT, weight );
    Noisy_ECALO_HT_[n]->Fill(noisy_ECalo_HT, weight );


    Noisy_HCALO_MHT_[0]->Fill(fabs(noisy_HCalo_MHT.Et()), weight );
    Noisy_HCALO_MHT_[n]->Fill(fabs(noisy_HCalo_MHT.Et()), weight );


    Noisy_HCALO_HT_[0]->Fill(noisy_HCalo_HT, weight );
    Noisy_HCALO_HT_[n]->Fill(noisy_HCalo_HT, weight );




  }

  return true;

}


bool HadronicCommonPlots::MECPlots(Event::Data& ev){

  //  cout << " in MEC " << endl;

  UInt_t n = ev.CommonObjects().size();
  if(n > nMax_) n = nMax_;
  if(n < nMin_) n = nMin_;

  Double_t weight = ev.GetEventWeight();


  LorentzV caloMET = LorentzV(*ev.metP4caloTypeII());

  if ( MECPlots_ ){

    LorentzV V_babyMHT_10_50 = LorentzV(0,0,0,0);
    LorentzV V_babyMHT_20_50 = LorentzV(0,0,0,0);
    LorentzV V_babyMHT_30_50 = LorentzV(0,0,0,0);



    for(std::vector<Event::Jet const*>::const_iterator iM = ev.JD_CommonJets().baby.begin();iM != ev.JD_CommonJets().baby.end();++iM){
      if( (*iM)->Pt() > 10)V_babyMHT_10_50 -= (**iM);
      if( (*iM)->Pt() > 20)V_babyMHT_20_50 -= (**iM);
      if( (*iM)->Pt() > 30)V_babyMHT_30_50 -= (**iM);
    }



    Double_t babyMHT_10_50 = V_babyMHT_10_50.Pt();
    // Double_t babyMHT_20_50 = V_babyMHT_20_50.Pt();
    // Double_t babyMHT_30_50 = V_babyMHT_30_50.Pt();

    Double_t MHTratio_10_50 = ev.CommonMHT().Pt()/(V_babyMHT_10_50+ev.CommonMHT()).Pt();
    Double_t MHTratio_20_50 = ev.CommonMHT().Pt()/(V_babyMHT_20_50+ev.CommonMHT()).Pt();
    Double_t MHTratio_30_50 = ev.CommonMHT().Pt()/(V_babyMHT_30_50+ev.CommonMHT()).Pt();


    Double_t MHTPFMETDiff = (ev.CommonMHT().Pt()-ev.PFMET().Pt());
    Double_t MHTCaloMETDiff = (ev.CommonMHT().Pt()-LorentzV(*ev.metP4caloTypeII()).Pt());

    Double_t Meff = ev.CommonMHT().Pt()+ev.CommonHT();




    if ( n >= nMin_ && n <= nMax_ && n < MHTPFMETDiffOvMeff_.size()  ) {
      MHTCaloMETDiff_[0]->Fill(MHTCaloMETDiff,weight);
      MHTCaloMETDiff_[n]->Fill(MHTCaloMETDiff,weight);

      MHTPFMETDiffOvMeff_[0]->Fill( MHTPFMETDiff/Meff, weight );
      MHTPFMETDiffOvMeff_[n]->Fill( MHTPFMETDiff/Meff, weight );
      MHTPFMETDiffOvMeff_vs_HT_[0]->Fill( MHTPFMETDiff/Meff,ev.CommonHT(), weight );
      MHTPFMETDiffOvMeff_vs_HT_[n]->Fill( MHTPFMETDiff/Meff,ev.CommonHT(), weight );
      MHTPFMETDiffOvMeff_vs_Meff_[0]->Fill( MHTPFMETDiff/Meff,Meff, weight );
      MHTPFMETDiffOvMeff_vs_Meff_[n]->Fill( MHTPFMETDiff/Meff,Meff, weight );
    }
    if( n >= nMin_ && n <= nMax_ && n < MHTCaloMETDiffOvMeff_.size()  ) {
      MHTCaloMETDiffOvMeff_[0]->Fill( MHTCaloMETDiff/Meff, weight );
      MHTCaloMETDiffOvMeff_[n]->Fill( MHTCaloMETDiff/Meff, weight );
      MHTCaloMETDiffOvMeff_vs_HT_[0]->Fill( MHTCaloMETDiff/Meff,ev.CommonHT(), weight );
      MHTCaloMETDiffOvMeff_vs_HT_[n]->Fill( MHTCaloMETDiff/Meff,ev.CommonHT(), weight );
      MHTCaloMETDiffOvMeff_vs_Meff_[0]->Fill( MHTCaloMETDiff/Meff,Meff, weight );
      MHTCaloMETDiffOvMeff_vs_Meff_[n]->Fill( MHTCaloMETDiff/Meff,Meff, weight );
    }
    if( n >= nMin_ && n <= nMax_ && n < PFMET_vs_MHTPFMETDiffOvMeff_.size()  ) {
      PFMET_vs_MHTPFMETDiffOvMeff_[0]->Fill(ev.PFMET().Pt(), MHTPFMETDiff/Meff, weight );
      PFMET_vs_MHTPFMETDiffOvMeff_[n]->Fill(ev.PFMET().Pt(), MHTPFMETDiff/Meff, weight );
    }
    if( n >= nMin_ && n <= nMax_ && n < MHTOvPFMET_.size()  ) {
      MHTOvPFMET_[0]->Fill(ev.CommonMHT().Pt()/ev.PFMET().Pt(),weight);
      MHTOvPFMET_[n]->Fill(ev.CommonMHT().Pt()/ev.PFMET().Pt(),weight);
      MHTOvPFMET_vs_HT_[0]->Fill(ev.CommonMHT().Pt()/ev.PFMET().Pt(),ev.CommonHT(),weight);
      MHTOvPFMET_vs_HT_[n]->Fill(ev.CommonMHT().Pt()/ev.PFMET().Pt(),ev.CommonHT(),weight);
      MHTOvPFMET_vs_Meff_[0]->Fill(ev.CommonMHT().Pt()/ev.PFMET().Pt(),Meff,weight);
      MHTOvPFMET_vs_Meff_[n]->Fill(ev.CommonMHT().Pt()/ev.PFMET().Pt(),Meff,weight);
    }
    if( n >= nMin_ && n <= nMax_ && n < MHTOvPFMET_.size()  ) {
      MHTOvCaloMET_[0]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(),weight);
      MHTOvCaloMET_[n]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(),weight);
      MHTOvCaloMET_vs_HT_[0]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(),ev.CommonHT(),weight);
      MHTOvCaloMET_vs_HT_[n]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(),ev.CommonHT(),weight);
      MHTOvCaloMET_vs_Meff_[0]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(),Meff,weight);
      MHTOvCaloMET_vs_Meff_[n]->Fill(ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(),Meff,weight);
    }
    if( n >= nMin_ && n <= nMax_ && n < MHT_vs_PFMET_.size()  ) {
      MHT_vs_PFMET_[0]->Fill(ev.CommonMHT().Pt(),ev.PFMET().Pt(),weight);
      MHT_vs_PFMET_[n]->Fill(ev.CommonMHT().Pt(),ev.PFMET().Pt(),weight);
    }
    if( n >= nMin_ && n <= nMax_ && n < BabyJetMHT_10_50_.size()  ) {
      BabyJetMHT_10_50_[0]->Fill(babyMHT_10_50,weight);
      BabyJetMHT_10_50_[n]->Fill(babyMHT_10_50,weight);
    }

    if( n >= nMin_ && n <= nMax_ && n < MissedMHT_.size()  ) {
      MissedMHT_[0]->Fill(MHTratio_10_50,weight);
      MissedMHT_[n]->Fill(MHTratio_10_50,weight);
      MissedMHT_vs_HT_[0]->Fill(MHTratio_10_50,ev.CommonHT(),weight);
      MissedMHT_vs_HT_[n]->Fill(MHTratio_10_50,ev.CommonHT(),weight);
      MissedMHT_vs_Meff_[0]->Fill(MHTratio_10_50,Meff,weight);
      MissedMHT_vs_Meff_[n]->Fill(MHTratio_10_50,Meff,weight);
    }
    if( n >= nMin_ && n <= nMax_ && n < MissedMHT_30_50_.size()  ) {
      MissedMHT_30_50_[0]->Fill(MHTratio_30_50,weight);
      MissedMHT_30_50_[n]->Fill(MHTratio_30_50,weight);
      MissedMHT_30_50_vs_HT_[0]->Fill(MHTratio_30_50,ev.CommonHT(),weight);
      MissedMHT_30_50_vs_HT_[n]->Fill(MHTratio_30_50,ev.CommonHT(),weight);
      MissedMHT_30_50_vs_Meff_[0]->Fill(MHTratio_30_50,Meff,weight);
      MissedMHT_30_50_vs_Meff_[n]->Fill(MHTratio_30_50,Meff,weight);
    }
    if( n >= nMin_ && n <= nMax_ && n < MissedMHT_30_50_.size()  ) {
      MissedMHT_20_50_[0]->Fill(MHTratio_20_50,weight);
      MissedMHT_20_50_[n]->Fill(MHTratio_20_50,weight);
      MissedMHT_20_50_vs_HT_[0]->Fill(MHTratio_20_50,ev.CommonHT(),weight);
      MissedMHT_20_50_vs_HT_[n]->Fill(MHTratio_20_50,ev.CommonHT(),weight);
      MissedMHT_20_50_vs_Meff_[0]->Fill(MHTratio_20_50,Meff,weight);
      MissedMHT_20_50_vs_Meff_[n]->Fill(MHTratio_20_50,Meff,weight);
    }

  }


   return true;


}






