#include "LeptonicPlottingOps.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "GenMatrixBin.hh"
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

#include "JetData.hh"
#include "CommonOps.hh"

using namespace Operation;
using namespace OneLepton;

// -----------------------------------------------------------------------------
//
LeptonicPlottingOps::LeptonicPlottingOps(const std::string & folderName,
           const Utils::ParameterSet& ps ) :
  dirName_(folderName),
  // Misc
    //  dirName_( ps.Get<std::string>("DirName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
  //  verbose_( ps.Get<bool>("Verbose") ),
  doGen_( ps.Get<bool>("doGen") ),
  leptonType_(OneLepton::GetLeptonType(ps.Get<std::string>("LeptonType")) ),

  // Trigger prescale
  usePrescale_(ps.Get<bool>("usePrescale") ),
  mTriggers_(ps.Get<std::vector<std::string> >("Triggers") ),

  // AlphaT
  alphaT_( ps.Get<bool>("AlphaT") ),
  hAlphaT_(),
  hAlphaTVal_(),
  hAlphaTnJets_(),
  // PtHat
  ptHat_( ps.Get<bool>("PtHat") ),
  hPtHat_(),
  // MET
  met_( ps.Get<bool>("MET") ),
  hMetDiff1_(),
  hMetDiff2_(),
  hMetCC_(),
  hMetRaw_(),
  hMetCalo_(),
  hMetPF_(), hMetPFp_(), hMetPFm_(),
  // Event summary
  summary_( ps.Get<bool>("Summary") ),
  // Cross-cleaning
  cc_( ps.Get<bool>("CC") ),
  // Kinematic plots
  kine_( ps.Get<bool>("Kine") ),
  hPrescale_(),
  hEta_(),
  hDEta_(),
  hDR_(),
  hDR_lepJet_(),
  hDR_lepComJet_(),
  hMT_(), hMTp_(), hMTm_(),
  hMT2_(),
  hM3_(),
  hLP_(), hLPp_(), hLPm_(),
  hPFMHT_(),
  hHT_(),
  hHTlep_(),
  hMeff_(),
  hnlMeff_(),

  // Lepton object plots
  lep_( ps.Get<bool>("Lep") ),
  lPt_(), lPtp_(), lPtm_(),
  lEta_(), lEtap_(), lEtam_(),
  lPhi_(), lPhip_(), lPhim_(),
  lRelCombIso_(),
  lType_()

{}

// -----------------------------------------------------------------------------
//
LeptonicPlottingOps::~LeptonicPlottingOps() {}

// -----------------------------------------------------------------------------
//
void LeptonicPlottingOps::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void LeptonicPlottingOps::BookHistos() {
  if ( alphaT_ )   { alphaT(); }
  if ( ptHat_ )    { ptHat(); }
  if ( met_ )      { met(); }
  if ( kine_ )     { kine(); }
  if ( lep_ )      { lepton(); }

}

double LeptonicPlottingOps::TriggerPrescale(Event::Data& ev) {

  double prescaler=1.;

  //  if (usePrescale_) {
  for(std::vector<std::string>::const_iterator it = mTriggers_.begin();
      it != mTriggers_.end();
      ++it){
    std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
    if(trig != ev.hlt()->end() && trig->second) {
      prescaler=ev.hlt_prescaled()->find(trig->first)->second;
      //      cout << "Prescale for " << trig->first << " is: " << prescaler << endl;
    }// return true;
  }

  if (usePrescale_) { return prescaler; }
  prescaler=1.;

  return prescaler;
}

// -----------------------------------------------------------------------------
//
bool LeptonicPlottingOps::Process( Event::Data& ev ) {

  switch(leptonType_) {

  case OneLepton::ONELEPTON_MUON:
      if ( ev.LD_CommonMuons().accepted.size() )
  theLepton_=ev.LD_CommonMuons().accepted;
      else return false;
      break;
  case OneLepton::ONELEPTON_ELECTRON:
    if ( ev.LD_CommonElectrons().accepted.size() )
      theLepton_=ev.LD_CommonElectrons().accepted;
    else return false;
    break;

  default:
    throw std::invalid_argument("Supplied LeptonType Option not supplied");
  }

  if ( summary_ )  { summary(ev); }
  if ( alphaT_ )   { alphaT(ev); }
  if ( ptHat_ )    { ptHat(ev); }
  if ( met_ )      { met(ev); }
  if ( cc_ )       { cc(ev); }
  if ( kine_ )     { kine(ev); }
  if ( lep_ )      { lepton(ev); }
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& LeptonicPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "Leptonic plots ";
  ostrm << "(bins " << nMin_ << " to " << nMax_ << ") ";
  return ostrm;
}


// -----------------------------------------------------------------------------
//
void LeptonicPlottingOps::alphaT() {

  BookHistArray( hAlphaT_,
     "AlphaT",
     ";#alpha_{T}",
     300, 0., 3.,
     nMax_+1, 0, 1, true );

  BookHistArray( hLepAlphaT_,
     "LepAlphaT",
     ";#alpha_{T}^{leptonic}",
     300, 0., 3.,
     nMax_+1, 0, 1, true );

  BookHistArray( hHadAlphaT_,
     "HadAlphaT",
     ";#alpha_{T}^{hadronic}",
     300, 0., 3.,
     nMax_+1, 0, 1, true );


  BookHistArray( hAlphaTVal_,
     "AlphaTVal",
     ";old;new",
     800, 0.3, 0.7,
       800, 0.3, 0.7,
     nMax_+1, 0, 1, true );

  BookHistArray( hAlphaTnJets_,
     "AlphaTnJets",
     ";N_{jet};#alpha_{T}",
     10, 0.5, 10.5,
     100, 0.0, 1.0,
     1, 0, 1, true );

}

// -----------------------------------------------------------------------------
//
void LeptonicPlottingOps::ptHat() {
  BookHistArray( hPtHat_,
     "PtHat",
     "",
     100, 0., 2500.,
     1, 0, 1, true );
}

// -----------------------------------------------------------------------------
//
void LeptonicPlottingOps::met() {

  BookHistArray( hMetDiff1_,
     "CC1",
     "Ratio(RecoilMET,RawMET)",
     1000, 0., 10.,
     1, 0, 1, true );

  BookHistArray( hMetDiff2_,
     "CC2",
     "Ratio(RecoilMET,CaloMET)",
     1000, 0., 10.,
     1, 0, 1, true );

  BookHistArray( hMetCC_,
     "MET(CC)",
     "",
     1000, 0., 2000.,
     1, 0, 1, true );

  BookHistArray( hMetRaw_,
     "MET(Raw)",
     "",
     1000, 0., 2000.,
     1, 0, 1, true );

  BookHistArray( hMetCalo_,
     "MET(Calo)",
     "",
     1000, 0., 2000.,
     1, 0, 1, true );
  // pfMET
  BookHistArray( hMetPF_,
                 "MET(PF)",
                 "",
                 1000, 0., 2000.,
                 1, 0, 1, true );
  BookHistArray( hMetPFp_,
                 "MET(PF)p",
                 "",
                 1000, 0., 2000.,
                 1, 0, 1, true );
  BookHistArray( hMetPFm_,
                 "MET(PF)m",
                 "",
                 1000, 0., 2000.,
                 1, 0, 1, true );
  


//   BookHistArray( hEventDisplay_,
//     "EventDisplay",
//     "",
//     400, -2000., 2000.,
//     400, -2000., 2000.,
//     101, 0, 1, true );

}

// -----------------------------------------------------------------------------
//
void LeptonicPlottingOps::kine() {

  BookHistArray( hPrescale_,
                 "Prescale",
                 ";Prescale factor;",
                 301,
                 -0.5,
                 300.5,
                 nMax_+1, 0, 1, true);

  BookHistArray( hDEta_,
     "DeltaEta",
     ";#Delta#eta(j_{i},j_{i+1});",
     120,
     -12.,
     12.,
     nMax_+1, 0, 1, true);

  BookHistArray( hEta_,
     "Eta",
     ";#eta(j_{i});",
     240,
     -12.,
     12.,
     nMax_+1, 0, 1, true);

  BookHistArray( hDR_,
     "DeltaR",
     ";#DeltaR(j_{i},j_{i+1});",
     100,
     0.,
     10.,
     nMax_+1, 0, 1, true);


  BookHistArray( hDR_lepJet_,
     "DeltaR_LepJet",
     ";#DeltaR(lepton,raw jet);",
     100,
     0.,
     10.,
     nMax_+1, 0, 1, true);

  BookHistArray( hDR_lepComJet_,
     "DeltaR_LepComJet",
     ";#DeltaR(lepton,common jet);",
     100,
     0.,
     10.,
     nMax_+1, 0, 1, true);

  BookHistArray( hNjet_,
                 "Njet",
                 ";number of jets;",
                 15,
                 -0.5,
                 14.5,
                 nMax_+1, 0, 1, true);

  BookHistArray( hJ1Et_,
                 "jet1Et",
                 ";jet1 p_{T};",
                 750,
                 0.,
                 1500.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hJ2Et_,
                 "jet2Et",
                 ";jet2 p_{T};",
                 750,
                 0.,
                 1500.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hJ3Et_,
                 "jet3Et",
                 ";jet3 p_{T};",
                 750,
                 0.,
                 1500.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hJ1Eta_,
                 "jet1Eta",
                 ";jet1 #eta;",
                 240,
                 -12.,
                 12.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hJ2Eta_,
                 "jet2Eta",
                 ";jet2 #eta;",
                 240,
                 -12.,
                 12.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hJ3Eta_,
                 "jet3Eta",
                 ";jet3 #eta;",
                 240,
                 -12.,
                 12.,
                 nMax_+1, 0, 1, true);


  BookHistArray( hMT_,
                 "MT",
                 ";M_{T};",
                 500,
                 0.,
                 1000.,
                 nMax_+1, 0, 1, true);

   BookHistArray( hMTp_,
                 "MTp",
                 ";M_{T}(+);",
                 500,
                 0.,
                 1000.,
                 nMax_+1, 0, 1, true);

   BookHistArray( hMTm_,
                 "MTm",
                 ";M_{T}(-);",
                 500,
                 0.,
                 1000.,
                 nMax_+1, 0, 1, true);


  BookHistArray( hMT2_,
                 "M_{T,2}",
                 ";M_{T,2};",
                 500,
                 0.,
                 2000.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hLP_,
                 "LPvar",
                 ";LP;",
                 500,
                 -2.5,
                 2.5,
                 nMax_+1, 0, 1, true);

   BookHistArray( hLPp_,
                 "LPPlusvar",
                 ";LP+;",
                 500,
                 -2.5,
                 2.5,
                 nMax_+1, 0, 1, true);

   BookHistArray( hLPm_,
                 "LPMinusvar",
                 ";LP-;",
                 500,
                 -2.5,
                 2.5,
                 nMax_+1, 0, 1, true);


   BookHistArray( hPFMHT_,
                 "pfMHT",
                 ";pfMHT;",
                 750,
                 0.,
                 1500.,
                 nMax_+1, 0, 1, true);

   BookHistArray( hMHTsum_,
      "MHTsum",
      ";MHTsum;",
      500,
      0.,
      5000.,
      nMax_+1, 0, 1, true);

  BookHistArray( hHTlep_,
                 "H_{T}^{lep}",
                 ";H_{T}^{lep};",
                 500,
                 0.,
                 5000.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hHThad_,
                 "H_{T}^{had}",
                 ";H_{T}^{had};",
                 500,
                 0.,
                 5000.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hMeff_,
                 "Meff",
                 ";Meff;",
                 500,
                 0.,
                 5000.,
                 nMax_+1, 0, 1, true);

  BookHistArray( hnlMeff_,
                 "Meff'",
                 ";Meff';",
                 500,
                 0.,
                 5000.,
                 nMax_+1, 0, 1, true);


}

void LeptonicPlottingOps::lepton() {

  BookHistArray( lPt_,
                 "Pt",
                 ";p_{T}(lepton);",
                 500,
                 0.,
                 500.,
                 nMax_+1, 0, 1, true);

  BookHistArray( lPtp_,
                 "Ptp",
                 ";p_{T}(lepton+);",
                 500,
                 0.,
                 500.,
                 nMax_+1, 0, 1, true);
    BookHistArray( lPtm_,
                 "Ptm",
                 ";p_{T}(lepton-);",
                 500,
                 0.,
                 500.,
                 nMax_+1, 0, 1, true);

  BookHistArray( lEta_,
                 "lepEta",
                 ";#eta(lepton);",
                 240,
                 -12.,
                 12.,
                 nMax_+1, 0, 1, true);

  BookHistArray( lEtap_,
                 "lepEtap",
                 ";#eta(lepton+);",
                 240,
                 -12.,
                 12.,
                 nMax_+1, 0, 1, true);
  BookHistArray( lEtam_,
                 "lepEtam",
                 ";#eta(lepton-);",
                 240,
                 -12.,
                 12.,
                 nMax_+1, 0, 1, true);

  // Phi
  BookHistArray( lPhi_,
                 "lepPhi",
                 ";#phi(lepton);",
		 24,
                 -3.14156,
                 3.14156,
                 nMax_+1, 0, 1, true);

  BookHistArray( lPhip_,
                 "lepPhip",
                 ";#phi(lepton+);",
		 24,
                 -3.14156,
                 3.14156,
                 nMax_+1, 0, 1, true);
  BookHistArray( lPhim_,
                 "lepPhim",
                 ";#phi(lepton-);",
                 24,
                 -3.14156,
                 3.14156,
                 nMax_+1, 0, 1, true);

  BookHistArray( lRelCombIso_,
                 "RelCombIso",
                 ";Relative combined Isolation;",
                 1000,
                 0.,
                 10.,
                 nMax_+1, 0, 1, true);

  BookHistArray( lType_,
                 "lepton type",
                 ";lepton type;",
                 12,
                 -1.5,
                 10.5,
                 nMax_+1, 0, 1, true);

}


// -----------------------------------------------------------------------------
//
bool LeptonicPlottingOps::alphaT( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();
  // Prescaler
  double prescaling = TriggerPrescale(ev);
  weight *= prescaling;

  // Common objects
  UInt_t n = ev.LeptonicObjects().size();

  // Alpha_t variable
  std::vector<bool> pseudo;
  double alpha_t = AlphaT()( ev.LeptonicObjects(), pseudo, false );
  if ( pseudo.size() != n ) { abort(); }

  // AlphaT Plots
  if ( !hAlphaT_.empty() ) { hAlphaT_[0]->Fill( alpha_t, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hAlphaT_.size() ) {
    hAlphaT_[n]->Fill( alpha_t, weight );
  }
  if ( !hLepAlphaT_.empty() ) { hLepAlphaT_[0]->Fill( ev.LeptonicAlphaT(), weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hLepAlphaT_.size() ) {
    hLepAlphaT_[n]->Fill( ev.LeptonicAlphaT(), weight );
  }
  if ( !hHadAlphaT_.empty() ) { hHadAlphaT_[0]->Fill( ev.HadronicAlphaT(), weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hHadAlphaT_.size() ) {
    hHadAlphaT_[n]->Fill( ev.HadronicAlphaT(), weight );
  }
  // Validation
  if ( n >= nMin_ && n <= nMax_ && n < hAlphaTVal_.size() && n <= Event::KS_MinDEt_MaxN() ) {
    hAlphaTVal_[0]->Fill( ev.CommonAlphaT(), alpha_t, weight );
    hAlphaTVal_[n]->Fill( ev.CommonAlphaT(), alpha_t, weight );
  }

  // AlphaT vs nJets
  if ( !hAlphaTnJets_.empty() ) { hAlphaTnJets_[0]->Fill( n*1., alpha_t, weight ); }

  return true;

}

// -----------------------------------------------------------------------------
//
bool LeptonicPlottingOps::ptHat( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();
  // Prescaler
  double prescaling=TriggerPrescale(ev);
  weight *= prescaling;

  // PtHat plot
  if ( ptHat_ ) { hPtHat_[0]->Fill( ev.pthat(), weight ); }

  return true;

}

// -----------------------------------------------------------------------------
//
bool LeptonicPlottingOps::met( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();
  // Prescaler
  double prescaling=TriggerPrescale(ev);
  weight *= prescaling;

  // Recoil MET from common objects
  LorentzV common_met = ev.CommonRecoilMET();

  // Recoil MET from raw ntuple objects
  LorentzV raw_met = RecoilMET(ev);

  // Calo MET from ntuple
  LorentzV calo_met = ev.CaloMET();
  LorentzV pf_met = ev.PFMET();

  double diff1 = ( fabs(common_met.Pt()) - fabs(raw_met.Pt()) ) / fabs(raw_met.Pt());

  double diff2 = ( fabs(common_met.Pt()) - fabs(calo_met.Pt()) ) / fabs(calo_met.Pt());

  // Histo
  if ( hMetDiff1_[0] ) { hMetDiff1_[0]->Fill( diff1, weight ); }
  if ( hMetDiff2_[0] ) { hMetDiff2_[0]->Fill( diff2, weight ); }

  // Histo
  if ( hMetCC_[0] ) { hMetCC_[0]->Fill( common_met.Pt(), weight ); }
  if ( hMetRaw_[0] ) { hMetRaw_[0]->Fill( raw_met.Pt(), weight ); }
  if ( hMetCalo_[0] ) { hMetCalo_[0]->Fill( calo_met.Pt(), weight ); }
  if ( hMetPF_[0] ) { 
    hMetPF_[0]->Fill( pf_met.Pt(), weight ); 
    if(theLepton_.at(0)->GetCharge() > 0 ) hMetPFp_[0]->Fill(pf_met.Pt(), weight);
    else hMetPFm_[0]->Fill(pf_met.Pt(), weight);
  }

  return true;

}

// -----------------------------------------------------------------------------
//
bool LeptonicPlottingOps::kine( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();

  // Prescaler
  double prescaling=TriggerPrescale(ev);
  //  weight *= prescaling;

  // Common objects
  UInt_t n = ev.LeptonicObjects().size();

  if ( !hPrescale_.empty() ) { hPrescale_[0]->Fill( prescaling, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hPrescale_.size() ) {
    hPrescale_[n]->Fill( prescaling, weight );
  }

  weight *= prescaling;

  // lepton - jet dR separation
  double dRmin=999.;
  if (ev.JD_Jets().size()>=1) {
    for (std::vector<Event::Jet>::const_iterator j=ev.JD_Jets().begin();
   j!=ev.JD_Jets().end(); j++) {

      double dR=fabs(ROOT::Math::VectorUtil::DeltaR (*theLepton_.at(0), *j));
      if (dR<dRmin) { dRmin=dR; }

    }
  }
  if ( !hDR_lepJet_.empty() ) { hDR_lepJet_[0]->Fill( dRmin, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hDR_lepJet_.size() ) {
    hDR_lepJet_[n]->Fill( dRmin, weight );
  }

  dRmin=999.;
  if (ev.JD_CommonJets().accepted.size()>=1) {
    for (std::vector<Event::Jet const *>::const_iterator j=ev.JD_CommonJets().accepted.begin();
   j!=ev.JD_CommonJets().accepted.end(); j++) {

      double dR=fabs(ROOT::Math::VectorUtil::DeltaR (*theLepton_.at(0), **j));
      if (dR<dRmin) { dRmin=dR; }

    }
  }
  if ( !hDR_lepComJet_.empty() ) { hDR_lepComJet_[0]->Fill( dRmin, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hDR_lepComJet_.size() ) {
    hDR_lepComJet_[n]->Fill( dRmin, weight );
  }

  // Global Event kinVariables

  int nJets = ev.JD_CommonJets().accepted.size();

  if ( !hNjet_.empty() ) { hNjet_[0]->Fill( nJets, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hNjet_.size() ) {
    hNjet_[n]->Fill( nJets, weight );
  }

  if (nJets>0) {
    if ( !hJ1Et_.empty() ) { hJ1Et_[0]->Fill( ev.JD_CommonJets().accepted[0]->Pt(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hJ1Et_.size() ) {
      hJ1Et_[n]->Fill( ev.JD_CommonJets().accepted[0]->Pt(), weight );
    }
    if ( !hJ1Eta_.empty() ) { hJ1Eta_[0]->Fill( ev.JD_CommonJets().accepted[0]->Eta(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hJ1Eta_.size() ) {
      hJ1Eta_[n]->Fill( ev.JD_CommonJets().accepted[0]->Eta(), weight );
    }
  }
  if (nJets>1) {
    if ( !hJ2Et_.empty() ) { hJ2Et_[0]->Fill( ev.JD_CommonJets().accepted[1]->Pt(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hJ2Et_.size() ) {
      hJ2Et_[n]->Fill( ev.JD_CommonJets().accepted[1]->Pt(), weight );
    }
    if ( !hJ2Eta_.empty() ) { hJ2Eta_[0]->Fill( ev.JD_CommonJets().accepted[1]->Eta(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hJ2Eta_.size() ) {
      hJ2Eta_[n]->Fill( ev.JD_CommonJets().accepted[1]->Eta(), weight );
    }
  }
  if (nJets>2) {
    if ( !hJ3Et_.empty() ) { hJ3Et_[0]->Fill( ev.JD_CommonJets().accepted[2]->Pt(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hJ3Et_.size() ) {
      hJ3Et_[n]->Fill( ev.JD_CommonJets().accepted[2]->Pt(), weight );
    }
    if ( !hJ3Eta_.empty() ) { hJ3Eta_[0]->Fill( ev.JD_CommonJets().accepted[2]->Eta(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hJ3Eta_.size() ) {
      hJ3Eta_[n]->Fill( ev.JD_CommonJets().accepted[2]->Eta(), weight );
    }
  }

  double pfMHT = (ev.PFMET() + *(theLepton_.at(0))).Pt();

  if ( !hPFMHT_.empty() ) { hPFMHT_[0]->Fill( pfMHT, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hPFMHT_.size() ) {
    hPFMHT_[n]->Fill( pfMHT, weight );
  }

  double pfMHTsum = ( ev.PFMET().Pt() + theLepton_.at(0)->Pt() );

  if ( !hMHTsum_.empty() ) { hMHTsum_[0]->Fill( pfMHTsum, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hMHTsum_.size() ) {
    hMHTsum_[n]->Fill( pfMHTsum, weight );
  }

  double pfMT = sqrt(2.*(theLepton_.at(0)->Pt())*(ev.PFMET().Pt())*
         (1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton_.at(0)),ev.PFMET())))) ;

  if ( !hMT_.empty() ) { 
    hMT_[0]->Fill( pfMT, weight ); 
    if(theLepton_.at(0)->GetCharge() > 0 ) hMTp_[0]->Fill(pfMT, weight);
    else hMTm_[0]->Fill(pfMT, weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < hMT_.size() ) {
    hMT_[n]->Fill( pfMT, weight );
    if(theLepton_.at(0)->GetCharge() > 0 ) hMTp_[n]->Fill(pfMT, weight);
    else hMTm_[n]->Fill(pfMT, weight);
  }

  double pfMT2 = 2.*(theLepton_.at(0)->Pt())*(ev.PFMET().Pt())*
    (1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton_.at(0)),ev.PFMET())));

  if ( !hMT2_.empty() ) { hMT2_[0]->Fill( pfMT2, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hMT2_.size() ) {
    hMT2_[n]->Fill( pfMT2, weight );
  }

  double pfLP = ( ((theLepton_.at(0)->Px())*((ev.PFMET()+(*(theLepton_.at(0)))).Px())) +
     ((theLepton_.at(0)->Py())*((ev.PFMET()+(*(theLepton_.at(0)))).Py()) ) )  /
    ( ((ev.PFMET()+(*(theLepton_.at(0)))).Pt())*((ev.PFMET()+(*(theLepton_.at(0)))).Pt()) );

  if ( !hLP_.empty() ) {
  hLP_[0]->Fill( pfLP, weight );
  if(theLepton_.at(0)->GetCharge() > 0 ) hLPp_[0]->Fill(pfLP, weight);
        else hLPm_[0]->Fill(pfLP, weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < hLP_.size() ) {
        hLP_[n]->Fill( pfLP, weight );
        if(theLepton_.at(0)->GetCharge() > 0 ) hLPp_[n]->Fill(pfLP, weight);
        else hLPm_[n]->Fill(pfLP, weight);
  }

  double HTlep = ev.CommonHT() + theLepton_.at(0)->Pt();

  if ( !hHTlep_.empty() ) { hHTlep_[0]->Fill( HTlep, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hHTlep_.size() ) {
    hHTlep_[n]->Fill( HTlep, weight );
  }

  double HThad = ev.CommonHT();
  if ( !hHThad_.empty() ) { hHThad_[0]->Fill( HThad, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hHThad_.size() ) {
    hHThad_[n]->Fill( HThad, weight );
  }

  double Meff= HTlep + ev.PFMET().Pt();

  if ( !hMeff_.empty() ) { hMeff_[0]->Fill( Meff, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hMeff_.size() ) {
    hMeff_[n]->Fill( Meff, weight );
  }

  double nlMeff = ev.CommonHT() + (ev.PFMET() + *(theLepton_.at(0))).Pt();

  if ( !hnlMeff_.empty() ) { hnlMeff_[0]->Fill( nlMeff, weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < hnlMeff_.size() ) {
    hnlMeff_[n]->Fill( nlMeff, weight );
  }


  // Loop through common objects
  for ( unsigned int ii = 0; ii < n; ++ii ) {

    // Eta
    if ( !hEta_.empty() ) { hEta_[0]->Fill( ev.LeptonicObjects()[ii].Eta(), weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < hEta_.size() ) {
      hEta_[ii]->Fill( ev.LeptonicObjects()[ii].Eta(), weight );
    }

    if ( ( n - ii ) > 1 ) {
      double deta = ev.LeptonicObjects()[ii].Eta() - ev.LeptonicObjects()[ii+1].Eta();
      double dphi = ROOT::Math::VectorUtil::DeltaPhi( ev.LeptonicObjects()[ii], ev.LeptonicObjects()[ii+1] );
      double dr = sqrt( deta * deta + dphi *dphi );
      // DeltaEta
      if ( !hDEta_.empty() ) { hDEta_[0]->Fill( deta, weight ); }
      if ( n >= nMin_ && n <= nMax_ && n < hDEta_.size() ) {
  hDEta_[ii]->Fill( deta, weight );
      }
      // DeltaR
      if ( !hDR_.empty() ) { hDR_[0]->Fill( dr, weight ); }
      if ( n >= nMin_ && n <= nMax_ && n < hDR_.size() ) {
  hDR_[ii]->Fill( dr, weight );
      }
    }

  }

  return true;

}

bool LeptonicPlottingOps::lepton( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();
  // Prescaler
  double prescaling=TriggerPrescale(ev);
  weight *= prescaling;

  // Common objects
  UInt_t n = ev.LeptonicObjects().size();

  if ( !lPt_.empty() ) { 
    lPt_[0]->Fill( theLepton_.at(0)->Pt(), weight ); 
    if(theLepton_.at(0)->GetCharge() > 0 ) lPtp_[0]->Fill(theLepton_.at(0)->Pt(), weight);
    else lPtm_[0]->Fill(theLepton_.at(0)->Pt(), weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < lPt_.size() ) {
    lPt_[n]->Fill( theLepton_.at(0)->Pt(), weight );
    if(theLepton_.at(0)->GetCharge() > 0 ) lPtp_[n]->Fill(theLepton_.at(0)->Pt(), weight);
    else lPtm_[n]->Fill(theLepton_.at(0)->Pt(), weight);
  }

  if ( !lEta_.empty() ) { 
    lEta_[0]->Fill( theLepton_.at(0)->Eta(), weight ); 
    if(theLepton_.at(0)->GetCharge() > 0 ) lEtap_[0]->Fill(theLepton_.at(0)->Eta(), weight);
    else lEtam_[0]->Fill(theLepton_.at(0)->Eta(), weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < lEta_.size() ) {
    lEta_[n]->Fill( theLepton_.at(0)->Eta(), weight );
    if(theLepton_.at(0)->GetCharge() > 0 ) lEtap_[n]->Fill(theLepton_.at(0)->Eta(), weight);
    else lEtam_[n]->Fill(theLepton_.at(0)->Eta(), weight);
  }

  // lepton Phi
    if ( !lPhi_.empty() ) { 
    lPhi_[0]->Fill( theLepton_.at(0)->Phi(), weight ); 
    if(theLepton_.at(0)->GetCharge() > 0 ) lPhip_[0]->Fill(theLepton_.at(0)->Phi(), weight);
    else lPhim_[0]->Fill(theLepton_.at(0)->Phi(), weight);
  }
  if ( n >= nMin_ && n <= nMax_ && n < lPhi_.size() ) {
    lPhi_[n]->Fill( theLepton_.at(0)->Phi(), weight );
    if(theLepton_.at(0)->GetCharge() > 0 ) lPhip_[n]->Fill(theLepton_.at(0)->Phi(), weight);
    else lPhim_[n]->Fill(theLepton_.at(0)->Phi(), weight);
  }


  if ( !lRelCombIso_.empty() ) { lRelCombIso_[0]->Fill( theLepton_.at(0)->GetCombIsolation(), weight ); }
  if ( n >= nMin_ && n <= nMax_ && n < lRelCombIso_.size() ) {
    lRelCombIso_[n]->Fill( theLepton_.at(0)->GetCombIsolation(), weight );
  }

  // Generator plots; applicable only in MC !
  if (doGen_) {

    int iMatch = ev.leptonMatch(theLepton_.at(0), leptonType_);
    int lepType = ev.leptonType(iMatch);

    if ( !lType_.empty() ) { lType_[0]->Fill( lepType, weight ); }
    if ( n >= nMin_ && n <= nMax_ && n < lType_.size() ) {
      lType_[n]->Fill( lepType, weight );
    }

  }

  return true;

}

// -----------------------------------------------------------------------------
//
LorentzV LeptonicPlottingOps::RecoilMET( Event::Data& ev ) {

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

// -----------------------------------------------------------------------------
//
bool LeptonicPlottingOps::summary( Event::Data& ev ) {

  std::stringstream ss;

  // Event info
  ss << "[LeptonicPlottingOps::summary]"
     << " Run: " << ev.RunNumber()
     << " Event: " << ev.EventNumber()
     << " Weight: " << ev.GetEventWeight() << std::endl;

  // Number of raw objects
  ss << " Raw:   "
     << " Jets: " << ev.JD_Jets().size()
     << " Muons: " << ev.LD_Muons().size()
     << " Electrons: " << ev.LD_Electrons().size()
     << " Photons: " << ev.PD_Photons().size()  << std::endl;

  // Number of objects surviving CC
  int nj = 0;
  {
    int n = 0;
    std::vector<Event::Jet const*>::const_iterator i = ev.CC().Jets.begin();
    std::vector<Event::Jet const*>::const_iterator j = ev.CC().Jets.end();
    for ( ; i != j; ++i ) { if ( *i ) { n++; } }
    nj = n;
  }

  int nm = 0;
  {
    int n = 0;
    std::vector<Event::Lepton const*>::const_iterator i = ev.CC().Muons.begin();
    std::vector<Event::Lepton const*>::const_iterator j = ev.CC().Muons.end();
    for ( ; i != j; ++i ) { if ( *i ) { n++; } }
    nm = n;
  }

  int ne = 0;
  {
    int n = 0;
    std::vector<Event::Lepton const*>::const_iterator i = ev.CC().Electrons.begin();
    std::vector<Event::Lepton const*>::const_iterator j = ev.CC().Electrons.end();
    for ( ; i != j; ++i ) { if ( *i ) { n++; } }
    ne = n;
  }

  int np = 0;
  {
    int n = 0;
    std::vector<Event::Photon const*>::const_iterator i = ev.CC().Photons.begin();
    std::vector<Event::Photon const*>::const_iterator j = ev.CC().Photons.end();
    for ( ; i != j; ++i ) { if ( *i ) { n++; } }
    np = n;
  }

  ss << " CC:    "
     << " Jets: " << nj
     << " Muons: " << nm
     << " Electrons: " << ne
     << " Photons: " << np << std::endl;

  // Number of obects accepted as being "Common"
  ss << " Common:"
     << " Jets: " << ev.JD_CommonJets().accepted.size()
     << " Muons: " << ev.LD_CommonMuons().accepted.size()
     << " Electrons: " << ev.LD_CommonElectrons().accepted.size()
     << " Photons: " << ev.PD_CommonPhotons().accepted.size()
     << std::endl;

  // Jet Pt
  if ( ev.JD_CommonJets().accepted.size() > 0 &&
       ev.JD_CommonJets().accepted[0] ) {
    ss << " LeadingJetPt: " << ev.JD_CommonJets().accepted[0]->Pt();
  }
  if ( ev.JD_CommonJets().accepted.size() > 1 &&
       ev.JD_CommonJets().accepted[1] ) {
    ss << " SecondJetPt: " << ev.JD_CommonJets().accepted[1]->Pt();
  }
  if ( ev.JD_CommonJets().accepted.size() > 2 &&
       ev.JD_CommonJets().accepted[2] ) {
    ss << " ThirdJetPt: " << ev.JD_CommonJets().accepted[2]->Pt();
  }
  ss << std::endl;

  // Odd obects and BadMuonInJet
  ss << " OddObjects:"
     << " Jets: " << ev.JD_CommonJets().hasOdd
     << " Muons: " << ev.LD_CommonMuons().hasOdd
     << " Electrons: " << ev.LD_CommonElectrons().hasOdd
     << " Photons: " << ev.PD_CommonPhotons().hasOdd
     << " BadMuonInJet: " << !badMuonInJet().Process(ev) << std::endl;

  // HT
  double denominator = ( ev.CommonRecoilMET() + ev.JD_CommonJets().killedHT ).Pt();
  double missed_ht = denominator > 0. ? ev.CommonRecoilMET().Pt() / denominator : 0.;
  ss << " HT: " << ev.CommonHT()
     << " MHTratio: " << missed_ht << std::endl;

  // MET
  LorentzV gen_met(0.,0.,0.,0.);
  ICF_LorentzVs::const_iterator igen = ev.genJetP4()->begin();
  ICF_LorentzVs::const_iterator jgen = ev.genJetP4()->end();
  for ( ; igen != jgen; ++igen ) { gen_met -= (*igen); }
  ss << " CaloMET: " << ev.CaloMET().Pt()
     << " RecoilMET(GenObjects): " << gen_met.Pt()
     << " RecoilMET(RawObjects): " << RecoilMET(ev).Pt()
     << " RecoilMET(LeptonicObjects): " << ev.CommonRecoilMET().Pt() << std::endl;

  // AlphaT and biased DPhi
  ss << " AlphaT: " << AlphaT()( ev.LeptonicObjects() )
     << " BiasedDPhi: " << ev.BiasedCommonRecoilMETJetDPhi() << std::endl;

  //

  // Output
  std::cout << ss.str();

  return true;

}

// -----------------------------------------------------------------------------
//

bool LeptonicPlottingOps::cc( Event::Data& ev ) {

  // Recoil MET from common objects
  LorentzV common_met = ev.CommonRecoilMET();

  // Recoil MET from raw ntuple objects
  LorentzV raw_met = RecoilMET(ev);

  // Calo MET from ntuple
  LorentzV calo_met = ev.CaloMET();

  // Recoil MET from gen jets
  LorentzV gen_met(0.,0.,0.,0.);
  ICF_LorentzVs::const_iterator igen = ev.genJetP4()->begin();
  ICF_LorentzVs::const_iterator jgen = ev.genJetP4()->end();
  for ( ; igen != jgen; ++igen ) { gen_met -= (*igen); }

  // Checks
  double diff1 = ( fabs(common_met.Pt()) - fabs(raw_met.Pt()) ) / fabs(raw_met.Pt());
  double diff2 = ( fabs(common_met.Pt()) - fabs(calo_met.Pt()) ) / fabs(calo_met.Pt());
  bool fail = ( diff1 > 1. || diff2 > 1. ) ? true : false;

  // Debug
  std::stringstream ss;
  ss << "[LeptonicPlottingOps::cc]"
     << "  FAIL: " << fail << std::endl
     << " HT                      : " << ev.CommonHT() << std::endl
     << " CaloMET                 : " << calo_met.Pt() << std::endl
     << " RecoilMHT(GenJets)      : " << gen_met.Pt() << std::endl
     << " RecoilMET(RawObjects)   : " << raw_met.Pt() << std::endl
     << " RecoilMET(LeptonicObjects): " << common_met.Pt()
     << std::endl;
  //     std::cout << ss.str() << std::endl;
  //     ss.flush();

//   {

//     ss << " GEN OBJECTS FROM NTUPLE:"
//        << std::endl;

//     GenMatrixBin gen(&ev);
//     //gen.PrintStableVis();

//     // Jets
//     ss << "  Found " << gen.the_GenJets.size() << " jets!"
//        << std::endl;
//     for ( unsigned int ijet = 0; ijet < gen.the_GenJets.size(); ++ijet ) {
//       //if ( gen.the_GenJets.at(ijet)->Et() < 50. || fabs( gen.the_GenJets.at(ijet)->Eta() ) > 3.0 ) { continue; }
//       ss << "  "
//   << " Index: " << std::setw(2) << ijet
//   << " Et: " << std::setw(8) << std::setprecision(4) << gen.the_GenJets.at(ijet)->Et()
//   << " Eta: " << std::setw(8) << std::setprecision(4) << gen.the_GenJets.at(ijet)->Eta()
//   << " Phi: " << std::setw(8) << std::setprecision(4) << gen.the_GenJets.at(ijet)->Phi()
//   << " Px: " << std::setw(8) << std::setprecision(4) << gen.the_GenJets.at(ijet)->Px()
//   << " Py: " << std::setw(8) << std::setprecision(4) << gen.the_GenJets.at(ijet)->Py()
//   << "  --- "
//   << std::endl;
//     }

//     // Photons
//     ss << "  Found " << gen.the_GenPhot.size() << " photons!"
//        << std::endl;
//     for ( unsigned int ipho = 0; ipho < gen.the_GenPhot.size(); ++ipho ) {
//       //if ( gen.the_GenPhot.at(ijet)->Et() < 25. || fabs( gen.the_GenPhot.at(ijet)->Eta() ) > 2.5 ) { continue; }
//       ss << "  "
//   << " Index: " << std::setw(2) << ipho
//   << " Et: " << std::setw(8) << std::setprecision(4) << gen.the_GenPhot.at(ipho)->Et()
//   << " Eta: " << std::setw(8) << std::setprecision(4) << gen.the_GenPhot.at(ipho)->Eta()
//   << " Phi: " << std::setw(8) << std::setprecision(4) << gen.the_GenPhot.at(ipho)->Phi()
//   << "  --- "
//   << std::endl;
//     }

//   }

  {

    ss << " GEN JETS FROM NTUPLE:"
       << std::endl;

    // Jets
    ss << "  Found " << ev.genJetP4()->size() << " gen jets!"
       << std::endl;
    ICF_LorentzVs::const_iterator ijet = ev.genJetP4()->begin();
    ICF_LorentzVs::const_iterator jjet = ev.genJetP4()->end();
    for ( ; ijet != jjet; ++ijet ) {
      ss << "  "
   << " Index: " << std::setw(2) << int( ijet - ev.genJetP4()->begin() )
   << " Et: " << std::setw(8) << std::setprecision(4) << ijet->Et()
   << " Eta: " << std::setw(8) << std::setprecision(4) << ijet->Eta()
   << " Phi: " << std::setw(8) << std::setprecision(4) << ijet->Phi()
   << " Px: " << std::setw(8) << std::setprecision(4) << ijet->Px()
   << " Py: " << std::setw(8) << std::setprecision(4) << ijet->Py()
   << "  --- "
   << std::endl;
    }

  }

  {

    ss << " RAW OBJECTS FROM NTUPLE:"
       << std::endl;

    // Jets
    ss << "  Found " << ev.JD_Jets().size() << " jets!"
       << std::endl;
    std::vector<Event::Jet>::const_iterator ijet = ev.JD_Jets().begin();
    std::vector<Event::Jet>::const_iterator jjet = ev.JD_Jets().end();
    for ( ; ijet != jjet; ++ijet ) {

      // Match index
      int index = int( ijet - ev.JD_Jets().begin() );
      if ( index < int( ev.genJetMatchIndex()->size() ) ) {
  index = ev.genJetMatchIndex()->at(index);
      } else { index = -1; }

      ss << "  "
   << " Index: " << std::setw(2) << ijet->GetIndex()
   << " Et: " << std::setw(8) << std::setprecision(4) << ijet->Et()
   << " Eta: " << std::setw(8) << std::setprecision(4) << ijet->Eta()
   << " Phi: " << std::setw(8) << std::setprecision(4) << ijet->Phi()
   << " Px: " << std::setw(8) << std::setprecision(4) << ijet->Px()
   << " Py: " << std::setw(8) << std::setprecision(4) << ijet->Py()
   << "  --- "
   << " MatchIndex: " << std::setw(2) << index
   << " MinimalId: " << std::setw(1) << ijet->GetMinimalId()
   << " LooseId: " << std::setw(1) << ijet->GetLooseId()
   << " TightId: " << std::setw(1) << ijet->GetTightId()
   << " EMF: " << std::setw(8) << std::setprecision(4) << ijet->GetEmFrac()
   << std::endl;
    }

    // Muons
    ss << "  Found " << ev.LD_Muons().size() << " muons!"
       << std::endl;
    std::vector<Event::Lepton>::const_iterator imuon = ev.LD_Muons().begin();
    std::vector<Event::Lepton>::const_iterator jmuon = ev.LD_Muons().end();
    for ( ; imuon != jmuon; ++imuon ) {
      ss << "  "
     << " Index: " << std::setw(2) << imuon->GetIndex()
     << " Et: " << std::setw(8) << std::setprecision(4) << imuon->Et()
     << " Eta: " << std::setw(8) << std::setprecision(4) << imuon->Eta()
     << " Phi: " << std::setw(8) << std::setprecision(4) << imuon->Phi()
     << "  --- "
     << " LooseId: " << std::setw(1) << imuon->GetLooseId()
     << " TightId: " << std::setw(1) << imuon->GetTightId()
     << " TrkIso: " << std::setw(8) << std::setprecision(4) << imuon->GetTrkIsolation()
     << " EcalIso: " << std::setw(8) << std::setprecision(4) << imuon->GetEcalIsolation()
     << " HcalIso: " << std::setw(8) << std::setprecision(4) << imuon->GetHcalIsolation()
     << " CombIso: " << std::setw(8) << std::setprecision(4) << imuon->GetCombIsolation()
     << std::endl;
    }

    // Electrons
    ss << "  Found " << ev.LD_Electrons().size() << " electrons!"
       << std::endl;
    std::vector<Event::Lepton>::const_iterator ielectron = ev.LD_Electrons().begin();
    std::vector<Event::Lepton>::const_iterator jelectron = ev.LD_Electrons().end();
    for ( ; ielectron != jelectron; ++ielectron ) {
      ss << "  "
     << " Index: " << std::setw(2) << ielectron->GetIndex()
     << " Et: " << std::setw(8) << std::setprecision(4) << ielectron->Et()
     << " Eta: " << std::setw(8) << std::setprecision(4) << ielectron->Eta()
     << " Phi: " << std::setw(8) << std::setprecision(4) << ielectron->Phi()
     << "  --- "
     << " LooseId: " << std::setw(1) << ielectron->GetLooseId()
     << " TightId: " << std::setw(1) << ielectron->GetTightId()
     << " TrkIso: " << std::setw(8) << std::setprecision(4) << ielectron->GetTrkIsolation()
     << " EcalIso: " << std::setw(8) << std::setprecision(4) << ielectron->GetEcalIsolation()
     << " HcalIso: " << std::setw(8) << std::setprecision(4) << ielectron->GetHcalIsolation()
     << " CombIso: " << std::setw(8) << std::setprecision(4) << ielectron->GetCombIsolation()
     << std::endl;
    }

    // Photons
    ss << "  Found " << ev.PD_Photons().size() << " photons!"
       << std::endl;
    std::vector<Event::Photon>::const_iterator iphoton = ev.PD_Photons().begin();
    std::vector<Event::Photon>::const_iterator jphoton = ev.PD_Photons().end();
    for ( ; iphoton != jphoton; ++iphoton ) {
      ss << "  "
     << " Index: " << std::setw(2) << iphoton->GetIndex()
     << " Et: " << std::setw(8) << std::setprecision(4) << iphoton->Et()
     << " Eta: " << std::setw(8) << std::setprecision(4) << iphoton->Eta()
     << " Phi: " << std::setw(8) << std::setprecision(4) << iphoton->Phi()
     << "  --- "
     << " LooseId: " << std::setw(1) << iphoton->IsItLoose()
     << " TightId: " << std::setw(1) << iphoton->IsItTight()
     << " TrkIso: " << std::setw(8) << std::setprecision(4) << iphoton->trkSumPtHollowConeDR04()
     << " EcalIso: " << std::setw(8) << std::setprecision(4) << iphoton->ecalRecHitSumEtConeDR04()
     << " HcalIso: " << std::setw(8) << std::setprecision(4) << iphoton->hcalTowerSumEtConeDR04()
     << " HadOverEm: " << std::setw(8) << std::setprecision(4) << iphoton->hadronicOverEm()
     << " r9: " << std::setw(8) << std::setprecision(4) << iphoton->r9()
     << " sigmaIetaIeta: " << std::setw(8) << std::setprecision(4) << iphoton->sigmaIetaIeta()
     << std::endl;
    }

  }

  {

    ss << " CC OBJECTS:"
       << std::endl;

    // Jets
    int njets = 0;
    std::stringstream jets;
    std::vector<Event::Jet const*>::const_iterator ijet = ev.CC().Jets.begin();
    std::vector<Event::Jet const*>::const_iterator jjet = ev.CC().Jets.end();
    for ( ; ijet != jjet; ++ijet ) {
      if ( !(*ijet) ) { continue; }
      jets << "  "
     << " Index: " << std::setw(2) << (*ijet)->GetIndex()
     << " Et: " << std::setw(8) << std::setprecision(4) << (*ijet)->Et()
     << " Eta: " << std::setw(8) << std::setprecision(4) << (*ijet)->Eta()
     << " Phi: " << std::setw(8) << std::setprecision(4) << (*ijet)->Phi()
     << " Px: " << std::setw(8) << std::setprecision(4) << (*ijet)->Px()
     << " Py: " << std::setw(8) << std::setprecision(4) << (*ijet)->Py()
     << "  --- "
     << " EMF: " << std::setw(8) << std::setprecision(4) << (*ijet)->GetEmFrac()
     << std::endl;
      njets++;
    }
    ss << "  Found " << njets << " jets with details:" << std::endl;
    ss << jets.str();

    // Muons
    int nmuons = 0;
    std::stringstream muons;
    std::vector<Event::Lepton const*>::const_iterator imuon = ev.CC().Muons.begin();
    std::vector<Event::Lepton const*>::const_iterator jmuon = ev.CC().Muons.end();
    for ( ; imuon != jmuon; ++imuon ) {
      if ( !(*imuon) ) { continue; }
      nmuons++;
      muons << std::setw(2) << (*imuon)->GetIndex() << " ";
    }
    ss << "  Found " << nmuons << " muons with indices:";
    ss << muons.str() << std::endl;

    // Electrons
    int nelectrons = 0;
    std::stringstream electrons;
    std::vector<Event::Lepton const*>::const_iterator ielectron = ev.CC().Electrons.begin();
    std::vector<Event::Lepton const*>::const_iterator jelectron = ev.CC().Electrons.end();
    for ( ; ielectron != jelectron; ++ielectron ) {
      if ( !(*ielectron) ) { continue; }
      nelectrons++;
      electrons << std::setw(2) << (*ielectron)->GetIndex() << " ";
    }
    ss << "  Found " << nelectrons << " electrons with indices:";
    ss << electrons.str() << std::endl;

    // Photons
    int nphotons = 0;
    std::stringstream photons;
    std::vector<Event::Photon const*>::const_iterator iphoton = ev.CC().Photons.begin();
    std::vector<Event::Photon const*>::const_iterator jphoton = ev.CC().Photons.end();
    for ( ; iphoton != jphoton; ++iphoton ) {
      if ( !(*iphoton) ) { continue; }
      nphotons++;
      photons << std::setw(2) << (*iphoton)->GetIndex() << " ";
    }
    ss << "  Found " << nphotons << " photons with indices:";
    ss << photons.str() << std::endl;

  }

  {

    ss << " CC KILL MAP:"
       << std::endl;
    if ( ev.CC().KillMap.empty() ) {
      ss << "  Empty" << std::endl;
    } else {
      std::stringstream kills;
      std::vector<Compute::KillOp>::const_iterator ii = ev.CC().KillMap.begin();
      std::vector<Compute::KillOp>::const_iterator jj = ev.CC().KillMap.end();
      for ( ; ii != jj; ++ii ) {
  kills << "  ";
  ii->terse(kills);
  kills << std::endl;
      }
      ss << kills.str();
    }

  }

  {

    ss << " ACCEPTED OBJECTS:"
       << std::endl;

    // Jets
    ss << "  Found " << ev.JD_CommonJets().accepted.size() << " jets with indices:";
    std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
    std::vector<Event::Jet const*>::const_iterator jjet = ev.JD_CommonJets().accepted.end();
    for ( ; ijet != jjet; ++ijet ) {
      if ( !(*ijet) ) { continue; }
      ss << std::setw(2) << (*ijet)->GetIndex() << " ";
    }
    ss << std::endl;

    // Muons
    ss << "  Found " << ev.LD_CommonMuons().accepted.size() << " muons with indices: ";
    std::vector<Event::Lepton const*>::const_iterator imuon = ev.LD_CommonMuons().accepted.begin();
    std::vector<Event::Lepton const*>::const_iterator jmuon = ev.LD_CommonMuons().accepted.end();
    for ( ; imuon != jmuon; ++imuon ) {
      if ( !(*imuon) ) { continue; }
      ss << std::setw(2) << (*imuon)->GetIndex() << " ";
    }
    ss << std::endl;

    // Electrons
    ss << "  Found " << ev.LD_CommonElectrons().accepted.size() << " electrons with indices: ";
    std::vector<Event::Lepton const*>::const_iterator ielectron = ev.LD_CommonElectrons().accepted.begin();
    std::vector<Event::Lepton const*>::const_iterator jelectron = ev.LD_CommonElectrons().accepted.end();
    for ( ; ielectron != jelectron; ++ielectron ) {
      if ( !(*ielectron) ) { continue; }
      ss << std::setw(2) << (*ielectron)->GetIndex() << " ";
    }
    ss << std::endl;

    // Photons
    ss << "  Found " << ev.PD_CommonPhotons().accepted.size() << " photons with indices: ";
    std::vector<Event::Photon const*>::const_iterator iphoton = ev.PD_CommonPhotons().accepted.begin();
    std::vector<Event::Photon const*>::const_iterator jphoton = ev.PD_CommonPhotons().accepted.end();
    for ( ; iphoton != jphoton; ++iphoton ) {
      if ( !(*iphoton) ) { continue; }
      ss << std::setw(2) << (*iphoton)->GetIndex() << " ";
    }
    ss << std::endl;

  }

  {

    ss << " OBJECTS KILLED:"
       << std::endl;

    // Jets
    ss << "  Found " << ev.JD_CommonJets().killed.size() << " jets with indices:";
    std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().killed.begin();
    std::vector<Event::Jet const*>::const_iterator jjet = ev.JD_CommonJets().killed.end();
    for ( ; ijet != jjet; ++ijet ) {
      if ( !(*ijet) ) { continue; }
      ss << " " /* << std::setw(2) */ << (*ijet)->GetIndex() ;
    }
    ss << std::endl;

    // Muons
    ss << "  Found " << ev.LD_CommonMuons().killed.size() << " muons with indices:";
    std::vector<Event::Lepton const*>::const_iterator imuon = ev.LD_CommonMuons().killed.begin();
    std::vector<Event::Lepton const*>::const_iterator jmuon = ev.LD_CommonMuons().killed.end();
    for ( ; imuon != jmuon; ++imuon ) {
      if ( !(*imuon) ) { continue; }
      ss << " " /* << std::setw(2) */ << (*imuon)->GetIndex();
    }
    ss << std::endl;

    // Electrons
    ss << "  Found " << ev.LD_CommonElectrons().killed.size() << " electrons with indices:";
    std::vector<Event::Lepton const*>::const_iterator ielectron = ev.LD_CommonElectrons().killed.begin();
    std::vector<Event::Lepton const*>::const_iterator jelectron = ev.LD_CommonElectrons().killed.end();
    for ( ; ielectron != jelectron; ++ielectron ) {
      if ( !(*ielectron) ) { continue; }
      ss << " " /* << std::setw(2) */ << (*ielectron)->GetIndex();
    }
    ss << std::endl;

    // Photons
    ss << "  Found " << ev.PD_CommonPhotons().killed.size() << " photons with indices:";
    std::vector<Event::Photon const*>::const_iterator iphoton = ev.PD_CommonPhotons().killed.begin();
    std::vector<Event::Photon const*>::const_iterator jphoton = ev.PD_CommonPhotons().killed.end();
    for ( ; iphoton != jphoton; ++iphoton ) {
      if ( !(*iphoton) ) { continue; }
      ss << " " /* << std::setw(2) */ << (*iphoton)->GetIndex();
    }
    ss << std::endl;

    std::cout << ss.str() << std::endl;

  }

  return true;

}


