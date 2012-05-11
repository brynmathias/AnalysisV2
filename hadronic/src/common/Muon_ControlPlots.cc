#include "Muon_ControlPlots.hh"
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
Muon_ControlPlots::Muon_ControlPlots( const Utils::ParameterSet& ps ) :
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
Muon_ControlPlots::~Muon_ControlPlots() {}

// -----------------------------------------------------------------------------
//
void Muon_ControlPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void Muon_ControlPlots::BookHistos() {
  if ( StandardPlots_ )           { StandardPlots(); }
}

// -----------------------------------------------------------------------------
//
bool Muon_ControlPlots::Process( Event::Data& ev ) {
  if ( StandardPlots_ )               { StandardPlots(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& Muon_ControlPlots::Description( std::ostream& ostrm ) {
  ostrm << "Common Control Plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//
void Muon_ControlPlots::StandardPlots() {



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


  BookHistArray( DPhi_MHT_MHTBaby_,
    "CosDetlaPhi_MHT_MHTBaby",
    ";#Delta Cos#phi(MHT,MHTbaby); Events/0.65 rad;",
    40, -1., 1,
    4, 0, 1, true );


  BookHistArray( MissedHT_,
    "MHTRatio_after_alphaT_55",
    ";MHT30/MHT10;Events/0.1;",
    100, 0., 10,
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
 
  BookHistArray( DetlaPhi_LeadingJets_,
    "DetlaPhi_LeadingJets",
    ";#Delta #phi(j_{1},j_{i}); Events/0.65 rad;",
    40, 0., TMath::Pi(),
    4, 0, 1, true );

  BookHistArray( DetlaPhi_NextToLeadingJets_,
    "DetlaPhi_NextToLeadingJets",
    ";#Delta #phi(j_{2},j_{3}); Events/0.65 rad;",
    40, 0., TMath::Pi(),
    4, 0, 1, true );

  BookHistArray( DetlaPhi_LeadingJets_afterAlphaT_55_,
    "DetlaPhi_LeadingJets_afterAlphaT_55",
    ";#Delta #phi(j_{1},j_{i}); Events/0.65 rad;",
    40, 0., TMath::Pi(),
    4, 0, 1, true );

  BookHistArray( DetlaPhi_NextToLeadingJets_afterAlphaT_55_,
    "DetlaPhi_NextToLeadingJets_afterAlphaT_55",
    ";#Delta #phi(j_{2},j_{3}); Events/0.65 rad;",
    40, 0., TMath::Pi(),
    4, 0, 1, true );


  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    4, 0, 1, true );



  BookHistArray( AlphaT_Zero_Six_Vertices_,
    "AlphaT_0_6_vertices",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    4, 0, 1, true );

  BookHistArray( AlphaT_Seven_Ten_Vertices_,
    "AlphaT_7_10_vertices",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    4, 0, 1, true );

  BookHistArray( AlphaT_Gr_Ten_Vertices_,
    "AlphaT_gr_10_vertices",
    ";#alpha_{T};Events/0.025;",
    1000,0.,10.,
    4, 0, 1, true );

  BookHistArray( AlphaT_Zoomed_,
    "AlphaT_Zoomed",
    ";#alpha_{T}; Events/0.0025;",
    60,0.45,0.6,
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

  BookHistArray( HT_Zero_Six_Vertices_,
    "HT_0_6_vertices",
    ";H_{T} (GeV); Events/25 GeV;",
    2500,0.,2500.,
    4, 0, 1, true );

  BookHistArray( HT_Seven_Ten_Vertices_,
    "HT_7_10_vertices",
    ";H_{T} (GeV); Events/25 GeV;",
    2500,0.,2500.,
    4, 0, 1, true );

  BookHistArray( HT_Gr_Ten_Vertices_,
    "HT_Gr_10_vertices",
    ";H_{T} (GeV); Events/25 GeV;",
    2500,0.,2500.,
    4, 0, 1, true );

  BookHistArray( Meff_,
    "EffectiveMass",
    ";M_{eff} (GeV); Events/40 GeV;",
    2500, 0., 2500.,
    4, 0, 1, true );

  BookHistArray( AlphatCut_BiasedDphi_afterAlphaT_55_,
    "BiasedDeltaPhi_after_alphaT_55",
    ";#Delta #phi^{*} (rad); Events/0.05 rad;",
    60, 0., TMath::Pi(),
    4, 0, 1, true );

  BookHistArray( BiasedDphi_,
    "BiasedDeltaPhi",
    ";#Delta #phi^{*} (rad); Events/0.05 rad;",
    60, 0., TMath::Pi(),
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

   BookHistArray( JetPt_,
    "JetPt",
    ";GeV ; Events",
    1500,0.,1500.,
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

  BookHistArray( hLepEta_,
    "MuEta",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
    4, 0, 1, true );

  BookHistArray( hLepEta_afterAlphaT_55_,
    "MuEta_afterAlphaT_55",
    ";#eta ; Events/1 eta;",
    60,-5.,5.,
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

  BookHistArray( Mu_Inner_Track_Hits_,
    "Mu_Inner_Track_Hits_",
    ";num_Inner_Track_valid_Hits_;",
    50,0,50.,
    4, 0, 1, true);

  BookHistArray( Mu_Global_Track_Hits_,
    "Mu_Global_Track_Hits_",
    ";num_Global_Track_valid_Hits_;",
    50,0,50.,
    4, 0, 1, true);

  BookHistArray( Mu_Delta_R_,
    "Mu_Delta_R_",
    ";#Delta R;",
    500,0,2*TMath::Pi(),
    4, 0, 1, true);

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
  
}
// -----------------------------------------------------------------------------
//


bool Muon_ControlPlots::StandardPlots( Event::Data& ev ) {

  std::vector <Event::Lepton const *> theLepton;

  UInt_t nBtags_five = 0;
  for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
    if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 5) > 0.679) {  nBtags_five++; } 
   
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
  Double_t weight = ev.GetEventWeight();
  

  /* if (ev.pthat.enabled()){

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

  //cout << " Weight out " << weight << endl;  */             

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


    if ( nVertex < 7){
    if ( n >= nMin_ && n <= nMax_ && n < HT_Zero_Six_Vertices_.size() ) {
      HT_Zero_Six_Vertices_[0]->Fill( ev.CommonHT(), weight );
      HT_Zero_Six_Vertices_[n]->Fill( ev.CommonHT(), weight );
    }
    }


    if ( nVertex >= 7 && nVertex <= 10){
    if ( n >= nMin_ && n <= nMax_ && n < HT_Seven_Ten_Vertices_.size() ) {
      HT_Seven_Ten_Vertices_[0]->Fill( ev.CommonHT(), weight );
      HT_Seven_Ten_Vertices_[n]->Fill( ev.CommonHT(), weight );
    }
    }


    if ( nVertex > 10){
    if ( n >= nMin_ && n <= nMax_ && n < HT_Gr_Ten_Vertices_.size() ) {
      HT_Gr_Ten_Vertices_[0]->Fill( ev.CommonHT(), weight );
      HT_Gr_Ten_Vertices_[n]->Fill( ev.CommonHT(), weight );
    }
    }


       if ( nVertex < 7){
    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_Zero_Six_Vertices_.size()  ) {
      AlphaT_Zero_Six_Vertices_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_Zero_Six_Vertices_[n]->Fill( ev.HadronicAlphaT(), weight );
    }
    }

    if ( nVertex >= 7 && nVertex <= 10){
    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_Seven_Ten_Vertices_.size()  ) {
      AlphaT_Seven_Ten_Vertices_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_Seven_Ten_Vertices_[n]->Fill( ev.HadronicAlphaT(), weight );
    }
    }

    if ( nVertex > 10){
    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_Gr_Ten_Vertices_.size()  ) {
      AlphaT_Gr_Ten_Vertices_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_Gr_Ten_Vertices_[n]->Fill( ev.HadronicAlphaT(), weight );
    }
    }


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
      AlphaT_Zoomed_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_Zoomed_[n]->Fill( ev.HadronicAlphaT(), weight );
    }


    if ( n >= nMin_ && n <= nMax_ && n < AlphaT_.size()  ) {
      AlphaT_[0]->Fill( ev.HadronicAlphaT(), weight );
      AlphaT_[n]->Fill( ev.HadronicAlphaT(), weight );
    }

    if( biasedDPhi > biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < BiasedDphi_.size()) {
      BiasedDphi_[0]->Fill(biasedDPhi_baby,weight);
      BiasedDphi_[n]->Fill(biasedDPhi_baby,weight);
      }
    }

    if( biasedDPhi <  biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < BiasedDphi_.size()) {
      BiasedDphi_[0]->Fill(biasedDPhi,weight);
      BiasedDphi_[n]->Fill(biasedDPhi,weight);
      }
    }

    if( n >= nMin_ && n <= nMax_ && n < DetlaPhi_LeadingJets_.size() ){
      DetlaPhi_LeadingJets_[1]->Fill( fabs( ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[0],*ev.JD_CommonJets().accepted[1])),weight);
      if(n <2){
        DetlaPhi_NextToLeadingJets_[2]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[1],*ev.JD_CommonJets().accepted[2])),weight);

      }
    }


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

    if (isLep){

    float minDeltaR = 2*TMath::Pi();
    for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ){
      float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theLepton.at(0))));
      if(aminDeltaR<minDeltaR)minDeltaR=aminDeltaR;
      }

     UInt_t iM  = (theLepton.at(0))->GetIndex();
     Double_t aMT =  sqrt(2.0 * ev.PFMET().Pt() * (theLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton.at(0)), ev.PFMET() ) )));

     if ( n >= nMin_ && n <= nMax_ && n < hLepPt_.size()  ) {
     hLepPt_[0]->Fill(theLepton.at(0)->Pt(),weight);
     hLepPt_[n]->Fill(theLepton.at(0)->Pt(),weight);
     }

     if ( n >= nMin_ && n <= nMax_ && n < hLepEta_.size()  ) {
     hLepEta_[0]->Fill(theLepton.at(0)->Eta(),weight);
     hLepEta_[n]->Fill(theLepton.at(0)->Eta(),weight);
     }

     if ( n >= nMin_ && n <= nMax_ && n < Mu_Inner_Track_Hits_.size()  ) {
     Mu_Inner_Track_Hits_[0]->Fill(ev.GetMuonGlobalTracknumberOfValidHits(iM),weight);
     Mu_Inner_Track_Hits_[n]->Fill(ev.GetMuonGlobalTracknumberOfValidHits(iM),weight);
     }

     if ( n >= nMin_ && n <= nMax_ && n < Mu_Global_Track_Hits_.size()  ) {
     Mu_Global_Track_Hits_[0]->Fill(ev.GetMuonInnerTracknumberOfValidHits(iM),weight);
     Mu_Global_Track_Hits_[n]->Fill(ev.GetMuonInnerTracknumberOfValidHits(iM),weight);
     } 
     
     if ( n >= nMin_ && n <= nMax_ && n < Mu_Delta_R_.size()  ) {
     Mu_Delta_R_[0]->Fill(minDeltaR,weight);
     Mu_Delta_R_[n]->Fill(minDeltaR,weight);
     }

     if ( n >= nMin_ && n <= nMax_ && n < hMT_.size()){
     hMT_[0]->Fill(aMT,weight);
     hMT_[n]->Fill(aMT,weight);
     }
     
     if(ev.HadronicAlphaT() > 0.55){
     if ( n >= nMin_ && n <= nMax_ && n < hMT_afterAlphaT_55_.size()){
     hMT_afterAlphaT_55_[0]->Fill(aMT,weight);
     hMT_afterAlphaT_55_[n]->Fill(aMT,weight);
      }
     
     if ( n >= nMin_ && n <= nMax_ && n < hMT_afterAlphaT_55_.size()){
     hLepPt_afterAlphaT_55_[0]->Fill(theLepton.at(0)->Pt(),weight);
     hLepPt_afterAlphaT_55_[n]->Fill(theLepton.at(0)->Pt(),weight);
     }

     if ( n >= nMin_ && n <= nMax_ && n < hMT_afterAlphaT_55_.size()){
     hLepEta_afterAlphaT_55_[0]->Fill(theLepton.at(0)->Eta(),weight);
     hLepEta_afterAlphaT_55_[n]->Fill(theLepton.at(0)->Eta(),weight);
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

      UInt_t nBtags_AT_five_55 = 0;
      for(unsigned int i=0; i<ev.JD_CommonJets().accepted.size(); i++) {
      // std::cout << "we are on jet " << i << " the btag discriminator is " << ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 4) << std::endl;
      if(ev.GetBTagResponse(ev.JD_CommonJets().accepted.at(i)->GetIndex(), 5) > 0.679) {
      nBtags_AT_five_55++;
            //if we make it into here, the jet has passed the b-tag requirement
        } 
      }


      if( n >= nMin_ && n <= nMax_ && n < DetlaPhi_LeadingJets_afterAlphaT_55_.size() ){
      DetlaPhi_LeadingJets_afterAlphaT_55_[1]->Fill( fabs( ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[0],*ev.JD_CommonJets().accepted[1])),weight);
      if(n <2){
        DetlaPhi_NextToLeadingJets_afterAlphaT_55_[2]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[1],*ev.JD_CommonJets().accepted[2])),weight);

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

     for(unsigned int i = 0; i < ev.JD_CommonJets().accepted.size() && i < 3; i++){
      JetPt_afterAlphaT_55_[0]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_afterAlphaT_55_[0]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
      JetPt_afterAlphaT_55_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Pt(),weight);
      JetEta_afterAlphaT_55_[i+1]->Fill(ev.JD_CommonJets().accepted[i]->Eta(),weight);
     }

      if ( n >= nMin_ && n <= nMax_ && n < MissedHT_.size() ) {
        MissedHT_[0]->Fill(  ev.CommonRecoilMET().Pt()/(ev.CommonRecoilMET()+ev.JD_CommonJets().babyHT).Pt(), weight );
        MissedHT_[n]->Fill( ev.CommonRecoilMET().Pt()/(ev.CommonRecoilMET()+ev.JD_CommonJets().babyHT).Pt(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_HT_55_.size() ) {
        AlphatCut_HT_55_[0]->Fill( ev.CommonHT(), weight );
        AlphatCut_HT_55_[n]->Fill( ev.CommonHT(), weight );
      }

      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_Meff_55_.size()) {
        AlphatCut_Meff_55_[0]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
        AlphatCut_Meff_55_[n]->Fill( ev.CommonMHT().Pt()+ev.CommonHT(), weight );
      }

    if( biasedDPhi < biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_BiasedDphi_afterAlphaT_55_.size()) {
      AlphatCut_BiasedDphi_afterAlphaT_55_[0]->Fill(biasedDPhi,weight);
      AlphatCut_BiasedDphi_afterAlphaT_55_[n]->Fill(biasedDPhi,weight);
      }
    }

    if( biasedDPhi > biasedDPhi_baby){
      if ( n >= nMin_ && n <= nMax_ && n < AlphatCut_BiasedDphi_afterAlphaT_55_.size()) {
      AlphatCut_BiasedDphi_afterAlphaT_55_[0]->Fill(biasedDPhi_baby,weight);
      AlphatCut_BiasedDphi_afterAlphaT_55_[n]->Fill(biasedDPhi_baby,weight);
      }
    }

    if ( n >= nMin_ && n <= nMax_ && n < MHTovMET_afterAlphaT_55_.size() ) {
        MHTovMET_afterAlphaT_55_[0]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
        MHTovMET_afterAlphaT_55_[n]->Fill(  ev.CommonMHT().Pt()/LorentzV(*ev.metP4caloTypeII()).Pt(), weight );
      }

    }

  
  }

  return true;

}
