#include "PhotonPlottingOps.hh"
#include "Math/VectorUtil.h"
#include "EventData.hh"
#include "Utils.hh"
#include "Jet.hh"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include "KinSuite.hh"
#include <sstream>
#include <string>

using namespace Operation;

// -----------------------------------------------------------------------------
//
StandardPlots::StandardPlots( const Utils::ParameterSet& ps ) :
  dirName_( ps.Get<std::string>("DirName") ),
  variable_( ps.Get<std::string>("VariableName") ),
  valueMin_( ps.Get<Double_t>("MinValue") ),
  nBins_( ps.Get<int>("nBins") ),
  binWidth_( ps.Get<Double_t>("BinWidth") )
{}

// -----------------------------------------------------------------------------
//
StandardPlots::~StandardPlots() {}

// -----------------------------------------------------------------------------
//
void StandardPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void StandardPlots::BookHistos() {

  BookHistArray( nVertices_,
    "nVertices",
    ";nVertices;Number of Events",
    12, -0.5, 11.5, 
    nBins_+2, 0, 1, true );

  BookHistArray( nJets_,
    "nJets",
    ";nJets;Number of Events",
    10, 1.5, 11.5, 
    nBins_+2, 0, 1, true );

  BookHistArray( HT_,
    "HT",
    ";H_{T} / GeV;Number of Events",
    200,0.,2000.,
    nBins_+2, 0, 1, true );

  BookHistArray( Meff_,
    "Meff",
    ";M_{eff} / GeV;Number of Events",
    100, 0., 3000.,
    nBins_+2, 0, 1, true );

  BookHistArray( BiasedDphi_,
    "BiasedDeltaPhi",
    ";#Delta#phi*;Number of Events",
    100, 0., TMath::Pi(),
    nBins_+2, 0, 1, true );

  BookHistArray( MHToverHT_,
    "MHToverHT",
    ";MH_{T}/H_{T};Number of Events",
    40,0.,1.,
    nBins_+2, 0, 1, true );

  BookHistArray( HTover2SinDeltaPhi_,
    "HTover2SinDeltaPhi",
    ";H_{T}/2sin(#Delta#phi) / GeV;Number of Events",
    50,0.,10000.,
    nBins_+2, 0, 1, true );

  BookHistArray( MHT_,
    "MHT",
    ";MH_{T} / GeV;Number of Events",
    80,0.,400.,
    nBins_+2, 0, 1, true );

  BookHistArray( ak5CaloMET_,
    "ak5CaloMET",
    ";AK5 Calo ME_{T} / GeV;Number of Events",
    80,0.,400.,
    nBins_+2, 0, 1, true );

  BookHistArray( pfMET_,
    "pfMET",
    ";pfME_{T} / GeV;Number of Events",
    80,0.,400.,
    nBins_+2, 0, 1, true );

  BookHistArray( tcMET_,
    "tcMET",
    ";tcME_{T} / GeV;Number of Events",
    80,0.,400.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonPt_,
    "PhotonPt",
    ";Photon P_{T} / GeV;Number of Events",
    100,0.,1000.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonEta_,
    "PhotonEta",
    ";Photon #eta;Number of Events",
    60,-3.,3.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonEcalIso_,
    "PhotonEcalIso",
    ";Photon Ecal Iso / GeV;Number of Events",
    100,0.,10.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonHcalIso_,
    "PhotonHcalIso",
    ";Photon Hcal Iso / GeV;Number of Events",
    100,0.,10.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonTrackIso_,
    "PhotonTrackIso",
    ";Photon Track Iso / GeV;Number of Events",
    100,0.,10.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonHoverE_,
    "PhotonHoverE",
    ";Photon HoverE;Number of Events",
    50,0.,0.1,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonSigmaIetaIeta_,
    "PhotonSigmaIetaIeta",
    ";Photon #sigma_{i#etai#eta};Number of Events",
    50,0.,0.05,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonR9_,
    "PhotonR9",
    ";Photon R9;Number of Events",
    60,0.,1.2,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonHasPixelSeed_,
    "PhotonHasPixelSeed",
    ";Photon HasPixelSeed;Number of Events",
    2,0.,2.,
    nBins_+2, 0, 1, true );

  BookHistArray( PhotonMETdPhi_,
    "PhotonMETdPhi",
    ";#Delta#phi(#gamma, MET);Number of Events",
    20, 0., TMath::Pi(),
    nBins_+2, 0, 1, true );

  BookHistArray( Jet1Pt_,
    "Jet1Pt",
    ";Leading Jet P_{T} / GeV;Number of Events",
    100,0.,1000.,
    nBins_+2, 0, 1, true );

  BookHistArray( Jet1Eta_,
    "Jet1Eta",
    ";Leading Jet #eta;Number of Events",
    60,-3.,3.,
    nBins_+2, 0, 1, true );

  BookHistArray( Jet1EmFrac_,
    "Jet1EmFrac",
    ";Leading Jet EM Fraction;Number of Events",
    50,0.,1.,
    nBins_+2, 0, 1, true );

  BookHistArray( Jet2Pt_,
    "Jet2Pt",
    ";Second Jet P_{T} / GeV;Number of Events",
    100,0.,1000.,
    nBins_+2, 0, 1, true );

  BookHistArray( Jet2Eta_,
    "Jet2Eta",
    ";Second Jet #eta;Number of Events",
    60,-3.,3.,
    nBins_+2, 0, 1, true );

  BookHistArray( Jet2EmFrac_,
    "Jet2EmFrac",
    ";Second Jet EM Fraction;Number of Events",
    50,0.,1.,
    nBins_+2, 0, 1, true );

}

// -----------------------------------------------------------------------------
//
bool StandardPlots::Process( Event::Data& ev ) {

  Double_t value;
  if (variable_ == "nObjects") {
    value = static_cast<double>(ev.CommonObjects().size());
  } else if (variable_ == "HT") {
    value = ev.CommonHT();
  } else if (variable_ == "Meff") {
    value = ev.CommonMHT().Pt() + ev.CommonHT();
  } else{
    std::cout << "[Standard Plots] Error: Variable [" << variable_ << "] not recognised" << std::endl;
  }
  UInt_t n = int( (value - valueMin_)/binWidth_ ) + 1;
  std::vector<Event::Photon const*> photons = ev.Get<SelectedPhotons>("SelectedPhotons")();
  Double_t weight = ev.GetEventWeight();
  //Double_t weight = ev.SusyCrossSection()*151/10000;

  // sin ( dPhi* )
  double Sinphistar = TMath::Sin(ev.CommonMinBiasDPhi());
  if(Sinphistar < 0){Sinphistar = 1.0;}

  // 0 = all in range (1->n); n = nth bin; n+1 = overflow bin
  if ( n <= nBins_ + 1) {
    nVertices_[0]->Fill( ev.GetVertexSize(), weight );
    nVertices_[n]->Fill( ev.GetVertexSize(), weight );
    nJets_[0]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    nJets_[n]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    HT_[0]->Fill( ev.CommonHT(), weight );
    HT_[n]->Fill( ev.CommonHT(), weight );
    Meff_[0]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    Meff_[n]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    BiasedDphi_[0]->Fill( ev.JetMinBiasDPhi(), weight );
    BiasedDphi_[n]->Fill( ev.JetMinBiasDPhi(), weight );
    MHToverHT_[0]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
    MHToverHT_[n]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
    HTover2SinDeltaPhi_[0]->Fill( ev.CommonHT()/(2*Sinphistar), weight );
    HTover2SinDeltaPhi_[n]->Fill( ev.CommonHT()/(2*Sinphistar), weight );
    MHT_[0]->Fill( ev.CommonMHT().Pt(), weight );
    MHT_[n]->Fill( ev.CommonMHT().Pt(), weight );
    ak5CaloMET_[0]->Fill( ev.AK5MET().Pt(), weight );
    ak5CaloMET_[n]->Fill( ev.AK5MET().Pt(), weight );
    pfMET_[0]->Fill( ev.PFMET().Pt(), weight );
    pfMET_[n]->Fill( ev.PFMET().Pt(), weight );
    tcMET_[0]->Fill( ev.TCMET().Pt(), weight );
    tcMET_[n]->Fill( ev.TCMET().Pt(), weight );
    if (ev.PD_CommonPhotons().accepted.size() > 0) {
      PhotonPt_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->Pt() , weight );
      PhotonPt_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->Pt() , weight );
      PhotonEta_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->Eta() , weight );
      PhotonEta_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->Eta() , weight );
      PhotonEcalIso_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->ecalRecHitSumEtConeDR04() , weight );
      PhotonEcalIso_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->ecalRecHitSumEtConeDR04() , weight );
      PhotonHcalIso_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04() , weight );
      PhotonHcalIso_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04() , weight );
      PhotonTrackIso_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04() , weight );
      PhotonTrackIso_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04() , weight );
      PhotonHoverE_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->hadronicOverEm() , weight );
      PhotonHoverE_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->hadronicOverEm() , weight );
      PhotonSigmaIetaIeta_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->sigmaIetaIeta() , weight );
      PhotonSigmaIetaIeta_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->sigmaIetaIeta() , weight );
      PhotonR9_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->r9() , weight );
      PhotonR9_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->r9() , weight );
      PhotonHasPixelSeed_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->hasPixelSeed() ? 1.5 : 0.5 , weight );
      PhotonHasPixelSeed_[n]->Fill( ev.PD_CommonPhotons().accepted[0]->hasPixelSeed() ? 1.5 : 0.5 , weight );
      PhotonMETdPhi_[0]->Fill( fabs(ROOT::Math::VectorUtil::DeltaPhi((LorentzV&) ev.PD_CommonPhotons().accepted[0], ev.PFMET())) , weight );
      PhotonMETdPhi_[n]->Fill( fabs(ROOT::Math::VectorUtil::DeltaPhi((LorentzV&) ev.PD_CommonPhotons().accepted[0], ev.PFMET())) , weight );
    }
    if (ev.JD_CommonJets().accepted.size() > 0) {
      Jet1Pt_[0]->Fill( ev.JD_CommonJets().accepted[0]->Pt(), weight );
      Jet1Pt_[n]->Fill( ev.JD_CommonJets().accepted[0]->Pt(), weight );
      Jet1Eta_[0]->Fill( ev.JD_CommonJets().accepted[0]->Eta(), weight );
      Jet1Eta_[n]->Fill( ev.JD_CommonJets().accepted[0]->Eta(), weight );
      Jet1EmFrac_[0]->Fill( ev.JD_CommonJets().accepted[0]->GetEmFrac(), weight );
      Jet1EmFrac_[n]->Fill( ev.JD_CommonJets().accepted[0]->GetEmFrac(), weight );
    }
    if (ev.JD_CommonJets().accepted.size() > 1) {
      Jet2Pt_[0]->Fill( ev.JD_CommonJets().accepted[1]->Pt(), weight );
      Jet2Pt_[n]->Fill( ev.JD_CommonJets().accepted[1]->Pt(), weight );
      Jet2Eta_[0]->Fill( ev.JD_CommonJets().accepted[1]->Eta(), weight );
      Jet2Eta_[n]->Fill( ev.JD_CommonJets().accepted[1]->Eta(), weight );
      Jet2EmFrac_[0]->Fill( ev.JD_CommonJets().accepted[1]->GetEmFrac(), weight );
      Jet2EmFrac_[n]->Fill( ev.JD_CommonJets().accepted[1]->GetEmFrac(), weight );
    }
  } else {
    nVertices_[0]->Fill( ev.GetVertexSize(), weight );
    nVertices_[nBins_+1]->Fill( ev.GetVertexSize(), weight );
    nJets_[0]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    nJets_[nBins_+1]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    HT_[0]->Fill( ev.CommonHT(), weight );
    HT_[nBins_+1]->Fill( ev.CommonHT(), weight );
    Meff_[0]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    Meff_[nBins_+1]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    BiasedDphi_[0]->Fill( ev.JetMinBiasDPhi(), weight );
    BiasedDphi_[nBins_+1]->Fill( ev.JetMinBiasDPhi(), weight );
    MHToverHT_[0]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
    MHToverHT_[nBins_+1]->Fill( ev.CommonMHT().Pt()/ev.CommonHT(), weight );
    HTover2SinDeltaPhi_[0]->Fill( ev.CommonHT()/(2*Sinphistar), weight );
    HTover2SinDeltaPhi_[nBins_+1]->Fill( ev.CommonHT()/(2*Sinphistar), weight );
    MHT_[0]->Fill( ev.CommonMHT().Pt(), weight );
    MHT_[nBins_+1]->Fill( ev.CommonMHT().Pt(), weight );
    ak5CaloMET_[0]->Fill( ev.AK5MET().Pt(), weight );
    ak5CaloMET_[nBins_+1]->Fill( ev.AK5MET().Pt(), weight );
    pfMET_[0]->Fill( ev.PFMET().Pt(), weight );
    pfMET_[nBins_+1]->Fill( ev.PFMET().Pt(), weight );
    tcMET_[0]->Fill( ev.TCMET().Pt(), weight );
    tcMET_[nBins_+1]->Fill( ev.TCMET().Pt(), weight );
    if (ev.PD_CommonPhotons().accepted.size() > 0) {
      PhotonPt_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->Pt() , weight );
      PhotonPt_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->Pt() , weight );
      PhotonEta_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->Eta() , weight );
      PhotonEta_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->Eta() , weight );
      PhotonEcalIso_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->ecalRecHitSumEtConeDR04() , weight );
      PhotonEcalIso_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->ecalRecHitSumEtConeDR04() , weight );
      PhotonHcalIso_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04() , weight );
      PhotonHcalIso_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->hcalTowerSumEtConeDR04() , weight );
      PhotonTrackIso_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04() , weight );
      PhotonTrackIso_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->trkSumPtHollowConeDR04() , weight );
      PhotonHoverE_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->hadronicOverEm() , weight );
      PhotonHoverE_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->hadronicOverEm() , weight );
      PhotonSigmaIetaIeta_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->sigmaIetaIeta() , weight );
      PhotonSigmaIetaIeta_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->sigmaIetaIeta() , weight );
      PhotonR9_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->r9() , weight );
      PhotonR9_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->r9() , weight );
      PhotonHasPixelSeed_[0]->Fill( ev.PD_CommonPhotons().accepted[0]->hasPixelSeed() ? 1.5 : 0.5 , weight );
      PhotonHasPixelSeed_[nBins_+1]->Fill( ev.PD_CommonPhotons().accepted[0]->hasPixelSeed() ? 1.5 : 0.5 , weight );
      PhotonMETdPhi_[0]->Fill( fabs(ROOT::Math::VectorUtil::DeltaPhi((LorentzV&) ev.PD_CommonPhotons().accepted[0], ev.PFMET())) , weight );
      PhotonMETdPhi_[nBins_+1]->Fill( fabs(ROOT::Math::VectorUtil::DeltaPhi((LorentzV&) ev.PD_CommonPhotons().accepted[0], ev.PFMET())) , weight );
    }
    if (ev.JD_CommonJets().accepted.size() > 0) {
      Jet1Pt_[0]->Fill( ev.JD_CommonJets().accepted[0]->Pt(), weight );
      Jet1Pt_[nBins_+1]->Fill( ev.JD_CommonJets().accepted[0]->Pt(), weight );
      Jet1Eta_[0]->Fill( ev.JD_CommonJets().accepted[0]->Eta(), weight );
      Jet1Eta_[nBins_+1]->Fill( ev.JD_CommonJets().accepted[0]->Eta(), weight );
      Jet1EmFrac_[0]->Fill( ev.JD_CommonJets().accepted[0]->GetEmFrac(), weight );
      Jet1EmFrac_[nBins_+1]->Fill( ev.JD_CommonJets().accepted[0]->GetEmFrac(), weight );
    }
    if (ev.JD_CommonJets().accepted.size() > 1) {
      Jet2Pt_[0]->Fill( ev.JD_CommonJets().accepted[1]->Pt(), weight );
      Jet2Pt_[nBins_+1]->Fill( ev.JD_CommonJets().accepted[1]->Pt(), weight );
      Jet2Eta_[0]->Fill( ev.JD_CommonJets().accepted[1]->Eta(), weight );
      Jet2Eta_[nBins_+1]->Fill( ev.JD_CommonJets().accepted[1]->Eta(), weight );
      Jet2EmFrac_[0]->Fill( ev.JD_CommonJets().accepted[1]->GetEmFrac(), weight );
      Jet2EmFrac_[nBins_+1]->Fill( ev.JD_CommonJets().accepted[1]->GetEmFrac(), weight );
    }
  }

  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& StandardPlots::Description( std::ostream& ostrm ) {
  ostrm << "Standard Plots ";
  ostrm<<"( "<<nBins_<<" bins in "<<variable_<<" from "<<valueMin_<<" to "<<valueMin_+nBins_*binWidth_<<"; bin width = "<<binWidth_<<") ";
  return ostrm;
}

//====================================
// Efficiency Plots
//====================================

EfficiencyPlots::EfficiencyPlots( const std::string& dirName, const std::string& genStatus ) :
  dirName_( dirName ),
  genStatus_( genStatus ),
  mEtCut(0.),
  mEtaCut(0.)
{}

EfficiencyPlots::~EfficiencyPlots() {}

void EfficiencyPlots::Start( Event::Data& ev ) {
  mEtCut = Utils::GetConfig<double>("Common.Photons.EtCut");
  mEtaCut = Utils::GetConfig<double>("Common.Photons.EtaCut");
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void EfficiencyPlots::BookHistos() {

  h_eta_all_ = new TH1D("eta_all", ";#eta;#epsilon", 6, -3., 3.);
  h_pt_all_ = new TH1D("pt_all", ";p_{T} (GeV);#epsilon", 10, 0., 500.);
  h_eta_matched_ = new TH1D("eta_matched", ";#eta;#epsilon", 6, -3., 3.);
  h_pt_matched_ = new TH1D("pt_matched", ";p_{T} (GeV);#epsilon", 10, 0., 500.);
  h_eta_pass_ = new TH1D("eta_pass", ";#eta;#epsilon", 6, -3., 3.);
  h_pt_pass_ = new TH1D("pt_pass", ";p_{T} (GeV);#epsilon", 10, 0., 500.);
  h_eta_matched_pass_ = new TH1D("eta_matched_pass", ";#eta;#epsilon", 6, -3., 3.);
  h_pt_matched_pass_ = new TH1D("pt_matched_pass", ";p_{T} (GeV);#epsilon", 10, 0., 500.);
  h_efficiency_ = new TH1D("efficiency", ";;Number of Photons", 6, 0., 6.);

}

bool EfficiencyPlots::Process( Event::Data& ev ) {

  std::vector<Event::Photon const*> matchedphotons;
  if (genStatus_ == "Status1") {
    std::vector<Event::Photon const*> matchedphotons = ev.Get<MatchedStatus1Photons>("MatchedStatus1Photons")();
  } else if (genStatus_ == "Status3") {
    std::vector<Event::Photon const*> matchedphotons = ev.Get<MatchedStatus3Photons>("MatchedStatus3Photons")();
  } else {
    std::cout << "[Efficiency Plots] Error: genStatus " << genStatus_ << " not recognised." << std::endl;
  }

  for (std::vector<Event::Photon const*>::const_iterator mp = matchedphotons.begin(); mp != matchedphotons.end(); ++mp)
  {
    if ((*mp)->pt() > mEtCut && fabs((*mp)->eta()) < mEtaCut)
    {
      h_eta_matched_->Fill((*mp)->eta(), ev.GetEventWeight());
      h_pt_matched_->Fill((*mp)->pt(), ev.GetEventWeight());
      h_efficiency_->Fill(0.5, ev.GetEventWeight());
      if ((*mp)->hadronicOverEm() < 0.05){
        h_efficiency_->Fill(1.5, ev.GetEventWeight());
        if ((*mp)->ecalRecHitSumEtConeDR04() < 4.2 + 0.006*(*mp)->pt()){
          h_efficiency_->Fill(2.5, ev.GetEventWeight());
          if ((*mp)->hcalTowerSumEtConeDR04() < 2.2 + 0.0025*(*mp)->pt()){
            h_efficiency_->Fill(3.5, ev.GetEventWeight());
            if ((*mp)->trkSumPtHollowConeDR04() < 2. + 0.001*(*mp)->pt()){
              h_efficiency_->Fill(4.5, ev.GetEventWeight());
              h_eta_matched_pass_->Fill((*mp)->eta(), ev.GetEventWeight());
              h_pt_matched_pass_->Fill((*mp)->pt(), ev.GetEventWeight());
              if (fabs((*mp)->eta()) < 1.4442 ? (*mp)->sigmaIetaIeta() < 0.013 : (*mp)->sigmaIetaIeta() < 0.030){
                h_efficiency_->Fill(5.5, ev.GetEventWeight());
              }
            }
          }
        }
      }
    }
  }
  for (std::vector<Event::Photon>::const_iterator iP = ev.PD_Photons().begin(); iP != ev.PD_Photons().end();++iP)
  {
    if (iP->Et() > mEtCut && fabs(iP->Eta()) < mEtaCut)
    {
      h_eta_all_->Fill(iP->eta(), ev.GetEventWeight());
      h_pt_all_->Fill(iP->pt(), ev.GetEventWeight());
    }
  }
  for (std::vector<Event::Photon const*>::const_iterator cp = ev.PD_CommonPhotons().accepted.begin(); cp != ev.PD_CommonPhotons().accepted.end(); ++cp)
  {
    h_eta_pass_->Fill((*cp)->eta(), ev.GetEventWeight());
    h_pt_pass_->Fill((*cp)->pt(), ev.GetEventWeight());
  }
  return true;
}

std::ostream& EfficiencyPlots::Description( std::ostream& ostrm ) {
  ostrm << "Efficiency plots ";
  return ostrm;
}

//====================================
// Spike Plots
//====================================

SpikePlots::SpikePlots( const std::string & dirName ) :
  dirName_(dirName)
{}

SpikePlots::~SpikePlots() {}

void SpikePlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void SpikePlots::BookHistos() {
  h_superClusterPhiWidth_ = new TH1D("superClusterPhiWidth", ";#sigma_{i#phii#phi};Number of Events", 50, 0., 0.05);
  h_superClusterEtaPhiWidth_ = new TH1D("superClusterEtaPhiWidth", ";sigma_{i#etai#phi};Number of Events", 50, 0., 0.05);
  h_superClusterEnergy_ = new TH1D("superClusterEnergy", ";superClusterEnergy;Number of Events", 100, 0., 500.);
  h_superClusterNXtals_ = new TH1I("superClusterNXtals", ";nXtals;Number of Events", 100, 0, 100);
  h_swissCross_ = new TH1D("swissCross", ";swissCross;Number of Events", 60, 0., 1.2);
  h_e2overE9_ = new TH1D("e2overE9", ";E2/E9;Number of Events", 50, 0., 1.);
  h_sigmaIetaIeta_ = new TH1D("sigmaIetaIeta", ";#sigma_{i#etai#eta};Number of Events", 50, 0., 0.05);
  h_seedTime_ = new TH1D("seedTime", ";t_{seed} / ns;Number of Events", 40, -20., 20.);
  h_time2_ = new TH1D("time2", ";t_{2} / ns;Number of Events", 40, -20., 20.);
  h_seedEnergy_ = new TH1D("seedEnergy", ";E_{seed} / GeV;Number of Events", 100, 0., 500.);
  h_energy2_ = new TH1D("energy2", ";E_{2} / GeV;Number of Events", 100, 0., 500.);
  h_e2x2_ = new TH1D("e2x2", ";e2x2 / GeV;Number of Events", 100, 0., 500.);
  h_e3x3_ = new TH1D("e3x3", ";e3x3 / GeV;Number of Events", 100, 0., 500.);
  h_e4x4_ = new TH1D("e4x4", ";e4x4 / GeV;Number of Events", 100, 0., 500.);
  h_e5x5_ = new TH1D("e5x5", ";e5x5 / GeV;Number of Events", 100, 0., 500.);
  h_e2x2overE3x3_ = new TH1D("e2x2overE3x3", ";e2x2/e3x3 / GeV;Number of Events", 50, 0., 1.);
  h_e2x2overE4x4_ = new TH1D("e2x2overE4x4", ";e2x2/e4x4 / GeV;Number of Events", 50, 0., 1.);
  h_e2x2overE5x5_ = new TH1D("e2x2overE5x5", ";e2x2/e5x5 / GeV;Number of Events", 50, 0., 1.);
  h_e2x2overEsc_ = new TH1D("e2x2overEsc", ";e2x2/eSC / GeV;Number of Events", 50, 0., 1.);
  h_sigmaIetaIeta_seedTime_ = new TH2D("sigIhIh_vs_seedTime", ";#sigma_{i#etai#eta};t_{seed} / ns;Number of Events", 50, 0., 0.05, 40, -20., 20.);
  h_sigmaIetaIphi_seedTime_ = new TH2D("sigIhIp_vs_seedTime", ";#sigma_{i#etai#phi};t_{seed} / ns;Number of Events", 50, 0., 0.05, 40, -20., 20.);
  h_sigmaIphiIphi_seedTime_ = new TH2D("sigIpIp_vs_seedTime", ";#sigma_{i#phii#phi};t_{seed} / ns;Number of Events", 50, 0., 0.05, 40, -20., 20.);
  h_e2overE9_seedTime_ = new TH2D("e2overE9_vs_seedTime", ";E2/E9;t_{seed} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overE3x3_seedTime_ = new TH2D("e2x2overE3x3_vs_seedTime", ";e2x2/e3x3;t_{seed} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overE4x4_seedTime_ = new TH2D("e2x2overE4x4_vs_seedTime", ";e2x2/e4x4;t_{seed} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overE5x5_seedTime_ = new TH2D("e2x2overE5x5_vs_seedTime", ";e2x2/e5x5;t_{seed} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overEsc_seedTime_ = new TH2D("e2x2overEsc_vs_seedTime", ";e2x2/eSC;t_{seed} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_swissCross_seedTime_ = new TH2D("swissCross_vs_seedTime", ";1 - E4/E1;t_{seed} / ns;Number of Events", 60, 0., 1.2, 40, -20., 20.);
  h_sigmaIetaIeta_time2_ = new TH2D("sigIhIh_vs_time2", ";#sigma_{i#etai#eta};t_{2} / ns;Number of Events", 50, 0., 0.05, 40, -20., 20.);
  h_sigmaIetaIphi_time2_ = new TH2D("sigIhIp_vs_time2", ";#sigma_{i#etai#phi};t_{2} / ns;Number of Events", 50, 0., 0.05, 40, -20., 20.);
  h_sigmaIphiIphi_time2_ = new TH2D("sigIpIp_vs_time2", ";#sigma_{i#phii#phi};t_{2} / ns;Number of Events", 50, 0., 0.05, 40, -20., 20.);
  h_e2overE9_time2_ = new TH2D("e2overE9_vs_time2", ";E2/E9;t_{2} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overE3x3_time2_ = new TH2D("e2x2overE3x3_vs_time2", ";e2x2/e3x3;t_{2} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overE4x4_time2_ = new TH2D("e2x2overE4x4_vs_time2", ";e2x2/e4x4;t_{2} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overE5x5_time2_ = new TH2D("e2x2overE5x5_vs_time2", ";e2x2/e5x5;t_{2} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_e2x2overEsc_time2_ = new TH2D("e2x2overEsc_vs_time2", ";e2x2/eSC;t_{2} / ns;Number of Events", 50, 0., 1., 40, -20., 20.);
  h_swissCross_time2_ = new TH2D("swissCross_vs_time2", ";1 - E4/E1;t_{2} / ns;Number of Events", 60, 0., 1.2, 40, -20., 20.);
  h_seedTime_t2_ = new TH2D("t1_vs_t2", ";t_{1} / ns;t_{2} / ns;Number of Events", 40, -20., 20., 40, -20., 20.);
}

bool SpikePlots::Process( Event::Data& ev ) {
  for (std::vector<Event::Photon const *>::const_iterator pho = ev.PD_CommonPhotons().accepted.begin(); pho != ev.PD_CommonPhotons().accepted.end(); ++pho) {
    h_superClusterPhiWidth_->Fill(ev.photonSuperClusterPhiWidth()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_superClusterEtaPhiWidth_->Fill(ev.photonSuperClusterEtaPhiWidth()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_superClusterEnergy_->Fill(ev.photonSuperClusterEnergy()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_superClusterNXtals_->Fill(ev.photonSuperClusterNXtals()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_swissCross_->Fill(ev.photonSwissCross()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2overE9_->Fill(ev.photonE2overE9()->at((*pho)->GetIndex()) + ev.photonSeedEnergy()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIetaIeta_->Fill((*pho)->sigmaIetaIeta(), ev.GetEventWeight());
    h_seedTime_->Fill(ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_time2_->Fill(ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_seedEnergy_->Fill(ev.photonSeedEnergy()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_energy2_->Fill(ev.photonEnergy2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2_->Fill(ev.photonE2x2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e3x3_->Fill(ev.photonE3x3()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e4x4_->Fill(ev.photonE4x4()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e5x5_->Fill(ev.photonE5x5()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE3x3_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE4x4_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE4x4()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE5x5_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE5x5()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overEsc_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonSuperClusterEnergy()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIetaIeta_seedTime_->Fill((*pho)->sigmaIetaIeta(), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIetaIphi_seedTime_->Fill(ev.photonSuperClusterEtaPhiWidth()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIphiIphi_seedTime_->Fill(ev.photonSuperClusterPhiWidth()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2overE9_seedTime_->Fill(ev.photonE2overE9()->at((*pho)->GetIndex()) + ev.photonSeedEnergy()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE3x3_seedTime_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE4x4_seedTime_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE4x4()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE5x5_seedTime_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE5x5()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overEsc_seedTime_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonSuperClusterEnergy()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_swissCross_seedTime_->Fill(ev.photonSwissCross()->at((*pho)->GetIndex()), ev.photonSeedTime()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIetaIeta_time2_->Fill((*pho)->sigmaIetaIeta(), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIetaIphi_time2_->Fill(ev.photonSuperClusterEtaPhiWidth()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_sigmaIphiIphi_time2_->Fill(ev.photonSuperClusterPhiWidth()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2overE9_time2_->Fill(ev.photonE2overE9()->at((*pho)->GetIndex()) + ev.photonSeedEnergy()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE3x3_time2_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE4x4_time2_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE4x4()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overE5x5_time2_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonE5x5()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_e2x2overEsc_time2_->Fill(ev.photonE2x2()->at((*pho)->GetIndex())/ev.photonSuperClusterEnergy()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_swissCross_time2_->Fill(ev.photonSwissCross()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
    h_seedTime_t2_->Fill(ev.photonSeedTime()->at((*pho)->GetIndex()), ev.photonTime2()->at((*pho)->GetIndex()), ev.GetEventWeight());
  }
  return true;
}

std::ostream& SpikePlots::Description( std::ostream& ostrm ) {
  ostrm << "Spike plots ";
  return ostrm;
}

//====================================
// TriggerPlots
//====================================

TriggerPlots::TriggerPlots( const std::string & dirName ) :
  dirName_(dirName)
{}

TriggerPlots::~TriggerPlots() {}

void TriggerPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void TriggerPlots::BookHistos() {
  h_pfMET_ = new TH1D("pfMET", ";pf #slash{E}_{T} / GeV;Number of Events", 200, 0., 2000.);
  h_HT_ = new TH1D("HT", ";H_{T} / GeV;Number of Events", 200, 0., 2000.);
  h_MHT_ = new TH1D("MHT", ";MH_{T} / GeV;Number of Events", 200, 0., 2000.);
}

bool TriggerPlots::Process( Event::Data& ev ) {
  h_pfMET_->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
  h_HT_->Fill(ev.CommonHT(), ev.GetEventWeight());
  h_MHT_->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
  return true;
}

std::ostream& TriggerPlots::Description( std::ostream& ostrm ) {
  ostrm << "TriggerPlots ";
  return ostrm;
}

//====================================
// HT Plot
//====================================

HtPlot::HtPlot( const std::string & dirName ) :
  dirName_(dirName)
{}

HtPlot::~HtPlot() {}

void HtPlot::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void HtPlot::BookHistos() {
  h_ht_ = new TH1D("ht", ";H_{T} / GeV;Number of Events", 200, 0., 2000.);
}

bool HtPlot::Process( Event::Data& ev ) {
  h_ht_->Fill(ev.CommonSumEt(), ev.GetEventWeight());
  return true;
}

std::ostream& HtPlot::Description( std::ostream& ostrm ) {
  ostrm << "HT plot ";
  return ostrm;
}

//====================================
// Gen pthat Plots
//====================================

GenPtHatPlots::GenPtHatPlots( const std::string & dirName ) :
  dirName_(dirName)
{}

GenPtHatPlots::~GenPtHatPlots() {}

void GenPtHatPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void GenPtHatPlots::BookHistos() {
  h_pthat_ = new TH1D("pthat", ";gen pthat;Number of Events", 100, 0., 2000.);
}

bool GenPtHatPlots::Process( Event::Data& ev ) {
  h_pthat_->Fill(ev.pthat(), ev.GetEventWeight());
  return true;
}

std::ostream& GenPtHatPlots::Description( std::ostream& ostrm ) {
  ostrm << "Gen pthat plots ";
  return ostrm;
}

//====================================
// Selected Photon Plots
//====================================

PhotonPlots::PhotonPlots(const std::string & folderName, UInt_t numphotons) :
  mFolderName(folderName),
  numphotons_(numphotons) {}

PhotonPlots::~PhotonPlots() {}

void PhotonPlots::Start(Event::Data & ev) {
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
}

void PhotonPlots::BookHistos() {
  BookHistArray(hg_multi_, "Multiplicity", ";Number of photons;",numphotons_+1,-0.5,numphotons_+0.5,1,0,1,true);
  BookHistArray(hg_Et_, "Et", ";E_{T} / GeV;",100,0.,1000.,numphotons_+1,0,1,true);
  BookHistArray(hg_eta_, "eta",  ";#eta;",120,-6.,6.,numphotons_+1,0,1,true);
  BookHistArray(hg_ecalIso_, "ecalIso",  ";ECAL Isolation / GeV;",100,0.,20.,numphotons_+1,0,1,true);
  BookHistArray(hg_ecalIso_Et_, "ecalIso_Et",  ";ECAL Isolation / GeV;E_{T} / GeV",100,0.,20.,100,0.,200.,numphotons_+1,0,1,true);
  BookHistArray(hg_hcalIso_, "hcalIso",  ";HCAL Isolation / GeV;E_{T} / GeV",100,0.,20.,numphotons_+1,0,1,true);
  BookHistArray(hg_hcalIso_Et_, "hcalIso_Et",  ";HCAL Isolation / GeV;E_{T} / GeV",100,0.,20.,100,0.,200.,numphotons_+1,0,1,true);
  BookHistArray(hg_trackIso_, "trackIso",  ";Track Isolation / GeV;",100,0.,20.,numphotons_+1,0,1,true);
  BookHistArray(hg_trackIso_Et_, "trackIso_Et",  ";Track Isolation / GeV;E_{T} / GeV",100,0.,20.,100,0.,200.,numphotons_+1,0,1,true);
  BookHistArray(hg_hadronicOverEm_, "hadronicOverEm",  ";hadronicOverEm;",100,0.,1.,numphotons_+1,0,1,true);
  BookHistArray(hg_r9_, "r9",  ";r9;",100,0.,1.,numphotons_+1,0,1,true);
  BookHistArray(hg_sigmaIetaIeta_, "sigmaIetaIeta",  ";sigmaIetaIeta;",100,0.,0.1,numphotons_+1,0,1,true);
  BookHistArray(hg_hasPixelSeed_, "hasPixelSeed",  ";hasPixelSeed;",2,0.,2.,numphotons_+1,0,1,true);
}

bool PhotonPlots::Process(Event::Data & ev) {

  std::vector<Event::Photon const*> photons = ev.Get<SelectedPhotons>("SelectedPhotons")();
  /*
  if (mCollection == "SelectedPhotons") {
    std::vector<Event::Photon const*> photons = ev.Get<SelectedPhotons>("SelectedPhotons")();
  } else if (mCollection == "AntiSelectedPhotons") {
    std::vector<Event::Photon const*> photons = ev.Get<AntiSelectedPhotons>("AntiSelectedPhotons")();
  } else if (mCollection == "MatchedStatus3Photons") {
    std::vector<Event::Photon const*> photons = ev.Get<MatchedStatus3Photons>("MatchedStatus3Photons")();
  } else if (mCollection == "MatchedStatus1Photons") {
    std::vector<Event::Photon const*> photons = ev.Get<MatchedStatus1Photons>("MatchedStatus1Photons")();
  } else if (mCollection == "AllPhotons") {
    std::vector<Event::Photon const*> photons = ev.PD_Photons(); 
  } else {
    std::cout << "[Photon Plots] Error: collection " << mCollection << " not recognised." << std::endl;
  }
  */

  hg_multi_[0]->Fill( photons.size(), ev.GetEventWeight() );

  UInt_t count = 0;
  for (std::vector<Event::Photon const*>::const_iterator pho = photons.begin(); pho != photons.end(); ++pho) {

    count++;
    // Fill "all" (i.e. "0") histogram(s) first
    hg_Et_[0]->Fill( (**pho).Et(), ev.GetEventWeight() );
    hg_eta_[0]->Fill( (**pho).Eta(), ev.GetEventWeight() );
    hg_ecalIso_[0]->Fill( (**pho).ecalRecHitSumEtConeDR04(), ev.GetEventWeight() );
    hg_ecalIso_Et_[0]->Fill( (**pho).ecalRecHitSumEtConeDR04(), (**pho).E(), ev.GetEventWeight() );
    hg_hcalIso_[0]->Fill( (**pho).hcalTowerSumEtConeDR04(), ev.GetEventWeight() );
    hg_hcalIso_Et_[0]->Fill( (**pho).hcalTowerSumEtConeDR04(), (**pho).E(), ev.GetEventWeight() );
    hg_trackIso_[0]->Fill( (**pho).trkSumPtHollowConeDR04(), ev.GetEventWeight() );
    hg_trackIso_Et_[0]->Fill( (**pho).trkSumPtHollowConeDR04(), (**pho).E(), ev.GetEventWeight() );
    hg_hadronicOverEm_[0]->Fill( (**pho).hadronicOverEm(), ev.GetEventWeight() );
    hg_r9_[0]->Fill( (**pho).r9(), ev.GetEventWeight() );
    hg_sigmaIetaIeta_[0]->Fill( (**pho).sigmaIetaIeta(), ev.GetEventWeight() );
    hg_hasPixelSeed_[0]->Fill( (**pho).hasPixelSeed() ? 1.5 : 0.5, ev.GetEventWeight() );

    // Check needed so we don't seg fault... ;-)
    if (count <= numphotons_) {
      hg_Et_[count]->Fill( (**pho).Et(), ev.GetEventWeight() );
      hg_eta_[count]->Fill( (**pho).Eta(), ev.GetEventWeight() );
      hg_ecalIso_[count]->Fill( (**pho).ecalRecHitSumEtConeDR04(), ev.GetEventWeight() );
      hg_ecalIso_Et_[count]->Fill( (**pho).ecalRecHitSumEtConeDR04(), (**pho).E(), ev.GetEventWeight() );
      hg_hcalIso_[count]->Fill( (**pho).hcalTowerSumEtConeDR04(), ev.GetEventWeight() );
      hg_hcalIso_Et_[count]->Fill( (**pho).hcalTowerSumEtConeDR04(), (**pho).E(), ev.GetEventWeight() );
      hg_trackIso_[count]->Fill( (**pho).trkSumPtHollowConeDR04(), ev.GetEventWeight() );
      hg_trackIso_Et_[count]->Fill( (**pho).trkSumPtHollowConeDR04(), (**pho).E(), ev.GetEventWeight() );
      hg_hadronicOverEm_[count]->Fill( (**pho).hadronicOverEm(), ev.GetEventWeight() );
      hg_r9_[count]->Fill( (**pho).r9(), ev.GetEventWeight() );
      hg_sigmaIetaIeta_[count]->Fill( (**pho).sigmaIetaIeta(), ev.GetEventWeight() );
      hg_hasPixelSeed_[count]->Fill( (**pho).hasPixelSeed() ? 1.5 : 0.5, ev.GetEventWeight() );
    }

  }
  return true;
}

std::ostream& PhotonPlots::Description(std::ostream &ostrm) {
  ostrm << "Photon plots ";
  ostrm << "for up to " << numphotons_ << " photons ";
  ostrm << "(Plots in folder " << mFolderName << "): ";
  return ostrm;
}

//====================================
// Signal Scan
//====================================

SignalScan::SignalScan( const std::string & dirName ) :
  dirName_(dirName)
{}

SignalScan::~SignalScan() {}

void SignalScan::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void SignalScan::BookHistos() {
  h_mChi50_ = new TH2D("SignalScan_mChi50", ";m_{#~{q}};m_{#~{g}}", 21, 360., 2040., 21, 360., 2040.);
  h_mChi150_ = new TH2D("SignalScan_mChi150", ";m_{#~{q}};m_{#~{g}}", 21, 360., 2040., 21, 360., 2040.);
  h_mChi500_ = new TH2D("SignalScan_mChi500", ";m_{#~{q}};m_{#~{g}}", 21, 360., 2040., 21, 360., 2040.);
  h_mChi1000_ = new TH2D("SignalScan_mChi1000", ";m_{#~{q}};m_{#~{g}}", 21, 360., 2040., 21, 360., 2040.);

  h_mChi50_->Sumw2();
  h_mChi150_->Sumw2();
  h_mChi500_->Sumw2();
  h_mChi1000_->Sumw2();
}

bool SignalScan::Process( Event::Data& ev ) {
  double weight = ev.SusyCrossSection()*35./10000;
  if (ev.MChi0() == 50) h_mChi50_->Fill(ev.MSquark(), ev.MGluino(), weight);
  if (ev.MChi0() == 150) h_mChi150_->Fill(ev.MSquark(), ev.MGluino(), weight);
  if (ev.MChi0() == 500) h_mChi500_->Fill(ev.MSquark(), ev.MGluino(), weight);
  if (ev.MChi0() == 1000) h_mChi1000_->Fill(ev.MSquark(), ev.MGluino(), weight);
  return true;
}

std::ostream& SignalScan::Description( std::ostream& ostrm ) {
  ostrm << "Signal Scan ";
  return ostrm;
}

//====================================
// EB dead TTs 
//====================================

EBDeadTT::EBDeadTT( const std::string & dirName ) :
  dirName_(dirName)
{}

EBDeadTT::~EBDeadTT() {}

void EBDeadTT::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void EBDeadTT::BookHistos() {
  h_eb_ = new TH2D("EBDeadTTs", ";i#phi;i#eta", 72, 0., 360., 34, -85., 85.);
}

bool EBDeadTT::Process( Event::Data& ev ) {
  for (std::vector<PolarLorentzV>::const_iterator p4 = ev.ecalDeadTowerTrigPrimP4()->begin(); p4 != ev.ecalDeadTowerTrigPrimP4()->end(); ++p4)
  {
    double phi = p4->phi();
    double eta = p4->eta();
    double x = phi*180/acos(-1) + 180;
    double y = eta*180/acos(-1); 
    if (p4->pt() < 0) {
      h_eb_->Fill(x, y, 1.);
    } else {
      h_eb_->Fill(x, y, 100.);
    }
  }
  return true;
}

std::ostream& EBDeadTT::Description( std::ostream& ostrm ) {
  ostrm << "EB Dead TTs ";
  return ostrm;
}

