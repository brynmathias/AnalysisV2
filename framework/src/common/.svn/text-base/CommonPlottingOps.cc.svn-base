/*! \file ComPlottingOps.cc
 * \brief Source code for common object plotting operations.
 */
#include "CommonPlottingOps.hh"
#include "Math/VectorUtil.h"
//#include "GenMatrixBin.hh"
#include "EventData.hh"
#include "Photon.hh"
#include "Lepton.hh"
#include "Jet.hh"
#include "mt2_bisect.hh"
#include <sstream>
#include "KinSuite.hh"
#include "AlphaT.hh"
#include <fstream>
namespace Operation {

  //====================================
  // ObjCountPlots implementation
  //====================================
  // Constructor
  ObjCountPlots::ObjCountPlots(const std::string & folderName,
             UInt_t Type) :
    mType(Type),
    mFolderName(folderName) {}
  ObjCountPlots::~ObjCountPlots() {}

  void ObjCountPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void  ObjCountPlots::BookHistos() {
    /*
    hg_Gen_hard_JetMultiplicity = new TH1D("JetMultiplicity_Gen_hard", ";Gen no. of Jets;Events / 100 pb^{-1}",     20,-0.5,19.5);
    hg_Gen_hard_EleMultiplicity = new TH1D("EleMultiplicity_Gen_hard", ";Gen no. of Electrons;Events / 100 pb^{-1}",20,-0.5,19.5);
    hg_Gen_hard_MuoMultiplicity = new TH1D("MuoMultiplicity_Gen_hard", ";Gen no. of Muons;Events / 100 pb^{-1}",    20,-0.5,19.5);
    hg_Gen_hard_TauMultiplicity = new TH1D("TauMultiplicity_Gen_hard", ";Gen no. of Taus;Events / 100 pb^{-1}",    20,-0.5,19.5);
    hg_Gen_hard_PhoMultiplicity = new TH1D("PhoMultiplicity_Gen_hard",  ";Gen no. of Photons;Events / 100 pb^{-1}",  20,-0.5,19.5);
    hg_Gen_hard_ObjMultiplicity = new TH1D("TobjMultiplicity_Gen_hard",  ";Gen no. of Objects;Events / 100 pb^{-1}",  20,-0.5,19.5);
    hg_Gen_hard_TopPt = new TH1D("TopPt",  ";Top py [GeV];Events / 100 pb^{-1}",  50,-0.,500);
    hg_Gen_hard_TauPt = new TH1D("TauPt",  ";Tau py [GeV];Events / 100 pb^{-1}",  50,-0.,500);
    hg_Gen_hard_TauMu= new TH1D("hg_Gen_hard_TauMu",  ";Gen no. of Objects;Events / 100 pb^{-1}",  20,-0.5,19.5);
    hg_Gen_hard_TauEli= new TH1D("hg_Gen_hard_TauEli",  ";Gen no. of Objects;Events / 100 pb^{-1}",  20,-0.5,19.5);
    hg_Gen_hard_TauHad= new TH1D("hg_Gen_hard_TauHad",  ";Gen no. of Objects;Events / 100 pb^{-1}",  20,-0.5,19.5);
    hg_Gen_hard_Leptons= new TH1D("hg_Gen_hard_Leptons",  ";Gen no. of Objects;Events / 100 pb^{-1}",  20,-0.5,19.5);
    hg_Gen_hard_WMuPhi= new TH1D("WMuPhi",  "",  40,-TMath::Pi(),TMath::Pi());
    hg_Gen_hard_WNuPhi= new TH1D("WNuPhi",  "",  40,-TMath::Pi(),TMath::Pi());
    hg_WMuRatio= new TH1D("WMuRatio",  "",  20,-0.5,1.5);
    hg_Gen_hard_MuonvsNU = new TH1D("MuonvsNU",  ";MuonNUvsW;Events / 100 pb^{-1}",  50,-0.,2);
    hg_Gen_hard_MuonvsW = new TH1D("MuonvsW",  ";MuonvsW;Events / 100 pb^{-1}",  50,-0.,2.);
    hg_Gen_hard_WPt = new TH1D("WPt",  ";Top py [GeV];Events / 100 pb^{-1}",  100,-0.,1000);
    hg_Gen_hard_WPtRes = new TH1D("WPtRes",  ";Top py [GeV];Events / 100 pb^{-1}",  100,-2.,2);
    */
    BookHistArray(hg_JetMultiplicity, "JetMultiplicity", ";No. of Jets;Events / 100 pb^{-1}",     20,-0.5,19.5,1,0,1,true);
    BookHistArray(hg_EleMultiplicity, "EleMultiplicity", ";No. of Electrons;Events / 100 pb^{-1}",20,-0.5,19.5,1,0,1,true);
    BookHistArray(hg_MuoMultiplicity, "MuoMultiplicity", ";No. of Muons;Events / 100 pb^{-1}",    20,-0.5,19.5,1,0,1,true);
    BookHistArray(hg_TauMultiplicity, "TauMultiplicity", ";No. of Taus;Events / 100 pb^{-1}",    40,-0.5,39.5,1,0,1,true);
    BookHistArray(hg_PhoMultiplicity, "PhoMultiplicity",  ";No. of Photons;Events / 100 pb^{-1}",  20,-0.5,19.5,1,0,1,true);
    BookHistArray(hg_ObjMultiplicity, "ObjMultiplicity",  ";No. of Objects;Events / 100 pb^{-1}",  40,-0.5,39.5,1,0,1,true);
  }


  bool ObjCountPlots::Process(Event::Data & ev) {
    /*
    GenMatrixBin myGenMatrixBin(&ev);
    hg_Gen_hard_JetMultiplicity->Fill(myGenMatrixBin.the_GenJets.size(), ev.GetEventWeight());
    hg_Gen_hard_EleMultiplicity->Fill(myGenMatrixBin.the_GenEli.size(), ev.GetEventWeight());
    hg_Gen_hard_MuoMultiplicity->Fill(myGenMatrixBin.the_GenMuon.size(), ev.GetEventWeight());
    hg_Gen_hard_TauMultiplicity->Fill(myGenMatrixBin.the_GenTau.size(), ev.GetEventWeight());
    hg_Gen_hard_PhoMultiplicity->Fill(myGenMatrixBin.the_GenPhot.size(), ev.GetEventWeight());
    hg_Gen_hard_ObjMultiplicity ->Fill(myGenMatrixBin.the_GenTop.size(), ev.GetEventWeight());

    for (vector <Event::GenObject const *>::const_iterator aIt = myGenMatrixBin.the_GenTop.begin();
   aIt != myGenMatrixBin.the_GenTop.end();
   aIt++) {
      hg_Gen_hard_TopPt->Fill((*aIt)->Pt() , ev.GetEventWeight());
    }

    for (vector <Event::GenObject const *>::const_iterator aIt = myGenMatrixBin.the_GenTau.begin(); aIt != myGenMatrixBin.the_GenTau.end();aIt++) {
      hg_Gen_hard_TauPt->Fill((*aIt)->Pt() , ev.GetEventWeight());
    }

    hg_Gen_hard_TauMu->Fill(myGenMatrixBin.nTauMuon, ev.GetEventWeight());
    hg_Gen_hard_TauEli->Fill(myGenMatrixBin.nTauEli, ev.GetEventWeight());
    hg_Gen_hard_TauHad->Fill(myGenMatrixBin.nTauHad, ev.GetEventWeight());
    hg_Gen_hard_Leptons->Fill(myGenMatrixBin.the_GenTau.size()+myGenMatrixBin.the_GenMuon.size()+myGenMatrixBin.the_GenEli.size(), ev.GetEventWeight());

    if(myGenMatrixBin.the_GenMuon.size()==1&&myGenMatrixBin.the_GenMuonNu.size()==1&&myGenMatrixBin.the_GenW.size()>0) {
      if(myGenMatrixBin.the_GenW[0]->Pt()>0) {
  hg_Gen_hard_MuonvsNU->Fill(myGenMatrixBin.the_GenMuonNu[0]->Pt()/myGenMatrixBin.the_GenW[0]->Pt(), ev.GetEventWeight());
  hg_Gen_hard_MuonvsW->Fill(myGenMatrixBin.the_GenMuon[0]->Pt()/myGenMatrixBin.the_GenW[0]->Pt(), ev.GetEventWeight());
  hg_Gen_hard_WPt ->Fill(myGenMatrixBin.the_GenW[0]->Pt(), ev.GetEventWeight());
  LorentzV myRestNu = *(myGenMatrixBin.the_GenMuonNu[0]);
  LorentzV myRestMu = *(myGenMatrixBin.the_GenMuon[0]);
  b = myGenMatrixBin.the_GenW[0]->BoostVector();
  myRestNu.Boost(-b);
  myRestMu.Boost(-b);
  hg_Gen_hard_WMuPhi->Fill(ROOT::Math::VectorUtil::DeltaPhi(myRestMu ,*(myGenMatrixBin.the_GenW[0])), ev.GetEventWeight());
  hg_Gen_hard_WNuPhi->Fill(ROOT::Math::VectorUtil::DeltaPhi(myRestNu ,*(myGenMatrixBin.the_GenW[0])), ev.GetEventWeight());
  hg_Gen_hard_WPtRes->Fill((myGenMatrixBin.the_GenW[0]->Pt() - ev.CommonMHT().Pt())/myGenMatrixBin.the_GenW[0]->Pt(), ev.GetEventWeight());
  if(myGenMatrixBin.the_GenMuon[0]->Pt()/myGenMatrixBin.the_GenW[0]->Pt()>0.5) hg_WMuRatio->Fill(1. , ev.GetEventWeight());
  else  hg_WMuRatio->Fill(0. , ev.GetEventWeight());
      }
    }
    */
    if (mType==0) {
      hg_JetMultiplicity[0]->Fill(ev.JD_Jets().size(), ev.GetEventWeight());
      hg_EleMultiplicity[0]->Fill(ev.LD_Electrons().size(), ev.GetEventWeight());
      hg_MuoMultiplicity[0]->Fill(ev.LD_Muons().size(), ev.GetEventWeight());
      hg_TauMultiplicity[0]->Fill(ev.LD_Taus().size(), ev.GetEventWeight());
      hg_PhoMultiplicity[0]->Fill(ev.PD_Photons().size(), ev.GetEventWeight());
      // Not including taus yet into the common object count...
      hg_ObjMultiplicity[0]->Fill(ev.PD_Photons().size()+
          ev.JD_Jets().size()+
          ev.LD_Electrons().size()+
          ev.LD_Muons().size(),
          ev.GetEventWeight());
    } else if (mType==1) {
      hg_JetMultiplicity[0]->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());
      hg_EleMultiplicity[0]->Fill(ev.LD_CommonElectrons().accepted.size(), ev.GetEventWeight());
      hg_MuoMultiplicity[0]->Fill(ev.LD_CommonMuons().accepted.size(), ev.GetEventWeight());
      hg_TauMultiplicity[0]->Fill(ev.LD_CommonTaus().accepted.size(), ev.GetEventWeight());
      hg_PhoMultiplicity[0]->Fill(ev.PD_CommonPhotons().accepted.size(), ev.GetEventWeight());
      // Not including taus yet...
      hg_ObjMultiplicity[0]->Fill(ev.PD_CommonPhotons().accepted.size()+
          ev.JD_CommonJets().accepted.size()+
          ev.LD_CommonElectrons().accepted.size()+
          ev.LD_CommonMuons().accepted.size(),
          ev.GetEventWeight());
    }

    return true; // Check for fails above, return false to fail operation.
  }

  std::ostream& ObjCountPlots::Description(std::ostream &ostrm) {
    ostrm << "Object counting operation ";
    if (mType==0) {ostrm << "(preconfigured) ";}
    if (mType==1) {ostrm << "(common) ";}
    ostrm << std::endl;
    for(int i =3 ; i< 11 ;i++) {
      ostrm << "bin: " << i-1
      << " njets: " << hg_JetMultiplicity[0]->GetBinContent(i)
      << " neles: " << hg_JetMultiplicity[0]->GetBinContent(i)
      << " nmuons: " << hg_JetMultiplicity[0]->GetBinContent(i)
      << " nphots: " << hg_JetMultiplicity[0]->GetBinContent(i)
      << std::endl;
    }
    return ostrm;
  }
  //==================================================================

  //====================================
  // ObjKinPlots implementation
  //====================================
  // Constructor
  ObjKinPlots::ObjKinPlots(const std::string & folderName,
         UInt_t Type,
         UInt_t Nth) :
    mType(Type),
    mNth(Nth),
    mFolderName(folderName) {}
  ObjKinPlots::~ObjKinPlots() {}

  void ObjKinPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void ObjKinPlots::BookHistos() {
    BookHistArray(hg_E,"E",";Energy / GeV;", 150, -1000., 2000., mNth+1, 0, 1, true);
    BookHistArray(hg_Et,"Et",";E_{T} / GeV;", 150, -1000., 2000., mNth+1, 0, 1, true);
    BookHistArray(hg_Pt,"Pt",";p_{T} / GeV;", 150, -1000., 2000., mNth+1, 0, 1, true);
    BookHistArray(hg_eta,"eta",";#eta;", 120, -6., 6., mNth+1, 0, 1, true);
    BookHistArray(hg_deta,"DeltaEta",";#Delta#eta(j_{n},j_{n+1});", 240, -12., 12., mNth+1, 0, 1, true);
    BookHistArray(hg_dr,"DeltaR",";#DeltaR(j_{n},j_{n+1});", 100, 0., 10., mNth+1, 0, 1, true);
    BookHistArray(hg_m, "m", ";m / GeV;", 150, -1000., 2000., mNth+1, 0, 1, true);
  }

  bool ObjKinPlots::Process(Event::Data & ev) {
    // Do whatever you gotta do...
    // JJ - rewritten to avoid unnecessary loops
    bool bDoAll = false;

    // Plot the histograms
    UInt_t i = 1; // Counter for which object we're on

    // See if we're doing all or just some
    if ( mType == 100 || mType == 11 || mType == 13 || mType == 22 ) {
      bDoAll = true;
    }

    if (mType==100 || bDoAll) {

      std::vector<Event::Jet const *>::const_iterator ob = ev.JD_CommonJets().accepted.begin();
      std::vector<Event::Jet const *>::const_iterator oe = ev.JD_CommonJets().accepted.end();
      for ( ; ob != oe; ++ob ) {
  double deta = -1.e6;
  double dphi = -1.e6;
  double dr   = -1.e6;
  if ( int(oe-ob) > 1 ) {
    deta = (**ob).Eta() - (**(ob+1)).Eta();
    dphi = (**ob).Phi() - (**(ob+1)).Phi();
    double pi = 3.14159265;
    while ( dphi > pi ) { dphi -= 2*pi; }
    while ( dphi <= -1.*pi ) { dphi += 2*pi; }
    dr = sqrt( deta*deta + dphi*dphi );
  }
  hg_E[0]->Fill( (**ob).E(), ev.GetEventWeight() ); // Fill the "all" objects energy histogram
  hg_Et[0]->Fill( (**ob).Et(), ev.GetEventWeight() ); // Fill the "all" objects transverse energy histogram
  hg_Pt[0]->Fill( (**ob).Pt(), ev.GetEventWeight() ); // Fill the "all" objects transverse momentum histogram
  hg_eta[0]->Fill( (**ob).Eta(), ev.GetEventWeight() ); // Fill the "all" objects pseudo-rapidity histogram
  if ( deta > -1.e3 ) hg_deta[0]->Fill( deta, ev.GetEventWeight() ); // Fill the "all" objects pseudo-rapidity histogram
  if ( dr > -1.e3 ) hg_dr[0]->Fill( dr, ev.GetEventWeight() ); // Fill the "all" objects pseudo-rapidity histogram
  hg_m[0]->Fill( (**ob).M(), ev.GetEventWeight() ); // Fill the "all" objects mass histogram
  // If we're plotting the n^th object, fill the corresponding histogram.
  if (hg_E.size()> i) {
    hg_E[i]->Fill(   (**ob).E(),   ev.GetEventWeight() );
    hg_Et[i]->Fill(  (**ob).Et(),  ev.GetEventWeight() );
    hg_Pt[i]->Fill(  (**ob).Pt(),  ev.GetEventWeight() );
    hg_eta[i]->Fill( (**ob).Eta(), ev.GetEventWeight() );
    if ( deta > -1.e3 ) hg_deta[i]->Fill( deta, ev.GetEventWeight() );
    if ( dr > -1.e3 ) hg_dr[i]->Fill( dr, ev.GetEventWeight() );
    hg_m[i]->Fill(   (**ob).M(),   ev.GetEventWeight() );
  }
  i++; // Move the counter along (since we're using iterators).
      }
      if ( !bDoAll) return true;
    }

    if (mType==11 || bDoAll) {
      for (std::vector<Event::Lepton const *>::const_iterator ob = ev.LD_CommonElectrons().accepted.begin();
     ob != ev.LD_CommonElectrons().accepted.end();
     ++ob) {
  hg_E[0]->Fill( (**ob).E(), ev.GetEventWeight() ); // Fill the "all" objects energy histogram
  hg_Et[0]->Fill( (**ob).Et(), ev.GetEventWeight() ); // Fill the "all" objects transverse energy histogram
  hg_Pt[0]->Fill( (**ob).Pt(), ev.GetEventWeight() ); // Fill the "all" objects transverse momentum histogram
  hg_eta[0]->Fill( (**ob).Eta(), ev.GetEventWeight() ); // Fill the "all" objects pseudo-rapidity histogram
  hg_m[0]->Fill( (**ob).M(), ev.GetEventWeight() ); // Fill the "all" objects mass histogram
  // If we're plotting the n^th object, fill the corresponding histogram.
  if (hg_E.size()> i) {
    hg_E[i]->Fill(   (**ob).E(),   ev.GetEventWeight() );
    hg_Et[i]->Fill(  (**ob).Et(),  ev.GetEventWeight() );
    hg_Pt[i]->Fill(  (**ob).Pt(),  ev.GetEventWeight() );
    hg_eta[i]->Fill( (**ob).Eta(), ev.GetEventWeight() );
    hg_m[i]->Fill(   (**ob).M(),   ev.GetEventWeight() );
  }
  ++i;
      }
      if ( !bDoAll) return true;
    }

    if (mType==13||bDoAll)  {
      for (std::vector<Event::Lepton const *>::const_iterator ob = ev.LD_CommonMuons().accepted.begin();
     ob != ev.LD_CommonMuons().accepted.end();
     ++ob) {
  hg_E[0]->Fill( (**ob).E(), ev.GetEventWeight() ); // Fill the "all" objects energy histogram
  hg_Et[0]->Fill( (**ob).Et(), ev.GetEventWeight() ); // Fill the "all" objects transverse energy histogram
  hg_Pt[0]->Fill( (**ob).Pt(), ev.GetEventWeight() ); // Fill the "all" objects transverse momentum histogram
  hg_eta[0]->Fill( (**ob).Eta(), ev.GetEventWeight() ); // Fill the "all" objects pseudo-rapidity histogram
  hg_m[0]->Fill( (**ob).M(), ev.GetEventWeight() ); // Fill the "all" objects mass histogram
  // If we're plotting the n^th object, fill the corresponding histogram.
  if (hg_E.size()> i) {
    hg_E[i]->Fill(   (**ob).E(),   ev.GetEventWeight() );
    hg_Et[i]->Fill(  (**ob).Et(),  ev.GetEventWeight() );
    hg_Pt[i]->Fill(  (**ob).Pt(),  ev.GetEventWeight() );
    hg_eta[i]->Fill( (**ob).Eta(), ev.GetEventWeight() );
    hg_m[i]->Fill(   (**ob).M(),   ev.GetEventWeight() );
  }
  ++i;
      }
      if ( !bDoAll) return true;
    }


    if (mType==22||bDoAll) {
      for (std::vector<Event::Photon const *>::const_iterator ob = ev.PD_CommonPhotons().accepted.begin();
     ob != ev.PD_CommonPhotons().accepted.end();
     ++ob) {
  hg_E[0]->Fill( (**ob).E(), ev.GetEventWeight() ); // Fill the "all" objects energy histogram
  hg_Et[0]->Fill( (**ob).Et(), ev.GetEventWeight() ); // Fill the "all" objects transverse energy histogram
  hg_Pt[0]->Fill( (**ob).Pt(), ev.GetEventWeight() ); // Fill the "all" objects transverse momentum histogram
  hg_eta[0]->Fill( (**ob).Eta(), ev.GetEventWeight() ); // Fill the "all" objects pseudo-rapidity histogram
  hg_m[0]->Fill( (**ob).M(), ev.GetEventWeight() ); // Fill the "all" objects mass histogram
  // If we're plotting the n^th object, fill the corresponding histogram.
  if (hg_E.size()> i) {
    hg_E[i]->Fill(   (**ob).E(),   ev.GetEventWeight() );
    hg_Et[i]->Fill(  (**ob).Et(),  ev.GetEventWeight() );
    hg_Pt[i]->Fill(  (**ob).Pt(),  ev.GetEventWeight() );
    hg_eta[i]->Fill( (**ob).Eta(), ev.GetEventWeight() );
    hg_m[i]->Fill(   (**ob).M(),   ev.GetEventWeight() );
  }
  ++i;
      }
      if ( !bDoAll ) return true;
    }

    return true; // Check for fails above, return false to fail operation.
  } // end of Process method

  std::ostream& ObjKinPlots::Description(std::ostream &ostrm) {
    ostrm << "Object kinematics plotting operation ";
    if      (mType==100) {ostrm << "(Jets) ";}
    else if (mType==11)  {ostrm << "(Electrons) ";}
    else if (mType==13)  {ostrm << "(Muons) ";}
    else if (mType==22)  {ostrm << "(Photons) ";}
    else                 {ostrm << "(All objects) ";}
    return ostrm;
  }

  //====================================
  // kinSuiteComPlot implementation
  //====================================
  // Constructor
  kinSuiteComPlot::kinSuiteComPlot(const std::string & folderName,
           int NumObjMax,
           int NumObjMin) :
    mNumObjMax(NumObjMax),
    mNumObjMin(NumObjMin),
    mFolderName(folderName) {}

  void kinSuiteComPlot::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  kinSuiteComPlot::~kinSuiteComPlot() {}

  void  kinSuiteComPlot::BookHistos() {
    BookHistArray(hg_RecoilPt,"RecoilPt",";Recoil Pt / GeV;Events / 100 pb^{-1}", 100,-1000.,3000.,mNumObjMax+1,0,1,true);
    BookHistArray(hg_SumEt,"SumEt",";Sum E_{T} / GeV;Events / 100 pb^{-1}", 100,-1000.,3000.,mNumObjMax+1,0,1,true);
    BookHistArray(hg_RecoilPt_SumEt,"RecoilPt_over_SumEt",";;Events / 100 pb^{-1}", 60,-1.,2.,mNumObjMax+1,0,1,true);
    BookHistArray(hg_M,"M",";Combined Mass / GeV;Events / 100 pb^{-1}", 100,-1000.,3000.,mNumObjMax+1,0,1,true);
    BookHistArray(hg_MT,"MT",";Combined M_{T} / GeV;Events / 100 pb^{-1}", 100,-1000.,3000.,mNumObjMax+1,0,1,true);
    BookHistArray(hg_MinDPhi,"MinDPhi",";Min. #Delta #phi / rad.;Events / 100 pb^{-1}", 64,0.,3.2,mNumObjMax+1,0,1,true);
    BookHistArray(hg_MinBiasDPhi,"MinBiasDPhi",";Min. Biased #Delta #phi / rad.;Events / 100 pb^{-1}", 64,0.,3.2,mNumObjMax+1,0,1,true);
    BookHistArray(hg_MinDEt,"MinDEt",";Min. #Delta E_{T} / GeV;Events / 100 pb^{-1}", 100,-1000.,3000.,mNumObjMax+1,0,1,false);
    BookHistArray(hg_AlphaT,"AlphaT",";#alpha_{T};Events / 100 pb^{-1}", 300,0.,3.,mNumObjMax+1,0,1,false);
    BookHistArray(hg_Meff,"Mass Effective",";#M_{eff};Events / 100 pb^{-1}", 1000,0.,1000.,mNumObjMax+1,0,1,false);
    BookHistArray(hg_Ht,"Ht",";H_{T};Events / 100 pb^{-1}", 1000,0.,3000.,mNumObjMax+1,0,1,false);
 BookHistArray(hg_HtOver2sinPhiStar,"HtOver2sinPhiStar",";H_{T}/2 sin(#phi^{*});Events / 100 pb^{-1}", 1000,0.,5000.,mNumObjMax+1,0,1,false);

  }

  bool kinSuiteComPlot::Process(Event::Data & ev) {
    // Do whatever you gotta do...
    int n = ev.CommonObjects().size();

    hg_RecoilPt[0]->Fill( ev.CommonObjectSum().Pt(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_RecoilPt[n]->Fill( ev.CommonObjectSum().Pt(), ev.GetEventWeight() );

    hg_SumEt[0]->Fill( ev.CommonSumEt(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_SumEt[n]->Fill( ev.CommonSumEt(), ev.GetEventWeight() );

    hg_RecoilPt_SumEt[0]->Fill( ev.CommonObjectSum().Pt()/ev.CommonSumEt(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_RecoilPt_SumEt[n]->Fill( ev.CommonObjectSum().Pt()/ev.CommonSumEt(), ev.GetEventWeight() );

    hg_M[0]->Fill( ev.CommonObjectSum().M(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_M[n]->Fill( ev.CommonObjectSum().M(), ev.GetEventWeight() );

    hg_MT[0]->Fill( ev.CommonMT(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_MT[n]->Fill( ev.CommonMT(), ev.GetEventWeight() );

    hg_MinDPhi[0]->Fill( ev.CommonMinDPhi(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_MinDPhi[n]->Fill( ev.CommonMinDPhi(), ev.GetEventWeight() );

    hg_MinBiasDPhi[0]->Fill( ev.CommonMinBiasDPhi(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_MinBiasDPhi[n]->Fill( ev.CommonMinBiasDPhi(), ev.GetEventWeight() );

 if ( ev.CommonObjects().size() >= 1 &&
   ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN() ) {
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_MinDEt[n]->Fill( ev.CommonMinDEt(), ev.GetEventWeight() );
  }
    // JJ - added check for whether alphaT can be calculated
    // I'm presuming you just don't fill the entry if you can't

    hg_AlphaT[0]->Fill( ev.CommonAlphaT(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_AlphaT[n]->Fill( ev.CommonAlphaT(), ev.GetEventWeight() );

    hg_Ht[0]->Fill( ev.CommonHT(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_Ht[n]->Fill( ev.CommonHT(), ev.GetEventWeight() );


    hg_Meff[0]->Fill( ev.CommonMeff(), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_Meff[n]->Fill( ev.CommonMeff(), ev.GetEventWeight() );

hg_HtOver2sinPhiStar[0]->Fill( ev.CommonHT()/(2*TMath::Sin(ev.CommonMinBiasDPhi())), ev.GetEventWeight() );
    if ( n>=mNumObjMin && n<=mNumObjMax) hg_HtOver2sinPhiStar[n]->Fill( ev.CommonHT()/(2*TMath::Sin(ev.CommonMinBiasDPhi())), ev.GetEventWeight() );
    return true; // Check for fails above, return false to fail operation.
  } // end of Process method

  std::ostream& kinSuiteComPlot::Description(std::ostream &ostrm) {
    ostrm << "Common object kinematic suite variables plotting operation ";
    ostrm << "(bins " << mNumObjMin << " to " << mNumObjMax << ") ";
    return ostrm;
  }

  //================================
  // Good Jet Plotting Operation
  //================================
  //
  CommonPlots::CommonPlots(const std::string & folderName) :
    mFolderName(folderName) {}
  CommonPlots::~CommonPlots() {}

  void CommonPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void CommonPlots::BookHistos() {
    //   FileOut = new TFile(mFileName.c_str(), "update");

    hg_JetMultiplicity = new TH1D("JetMultiplicity",";No of Jets",20,-0.5,19.5);
    BookArray(hg_HT, TString("SumEt"), TString(";HT [GeV];events/100 pb^{-1}"),400,0.,2000.);
    BookArray(hg_MHT, TString("MHT"), TString(";MHT [GeV];events/100 pb^{-1}"),400,0.,2000.);
    BookArray(hg_Pt, TString("JetPt"), TString(";P_{T} [GeV];events/100 pb^{-1}"),400,0.,2000);
    BookArray(hg_Eta, TString("JetEta"), TString(";|eta| [GeV];events/100 pb^{-1}"),50,-5.,5.);
    BookArray(hg_dPhi,TString("JetMHTdPhi"), TString(";min_{i} #Delta #phi (MHT,Jet_{i}) [rad];events/100 pb^{-1}"),40,0.,TMath::Pi());
    BookArray(hg_biasedPhi,TString("biasedJetMHTdPhi"), TString(";min_{i}#Delta #phi (MHT-Jet_{i},Jet_{i}) [rad];events/100 pb^{-1}"),40,0.,TMath::Pi());
    BookArray(hg_MScosT,TString("MScosT"), TString(";#Delta cos#theta^{*} ;events/100 pb^{-1}"),40,0.,1);
    BookArray(hg_cosT,TString("cosT"), TString(";#Delta cos#theta^{*} ;events/100 pb^{-1}"),40,0.,1);
    hg_CosThetaGen = new TH1D("CosThetaGen",";",40,-0,1);
    hg_WLepton = new TH1D("WLepton",";",0,-0.5,7.5);;
    BookArray(hg_MHTovHT,TString("MHTovHT"), TString(";MHT/HT;events/100 pb^{-1}"),40,0.,1);
    BookArray(hg_MHTovHT_biasdPhi,TString("MHTovHT_biasdPhi"), TString(";MHT/HT;"),40,0.,1,40,0.,TMath::Pi());
    BookArray(hg_MHTovHT_dPhi,TString("MHTovHT_dPhi"), TString(";MHT/HT;"),40,0.,1,40,0.,TMath::Pi());
    BookArray(hg_caloMetdPhi,TString("CaloMetdPhi"), TString(";#Delta#phi jet met;events/100 pb^{-1}"),40,0.,TMath::Pi());
    BookArray(hg_TeCoilMetdPhi,TString("RecoilMetdPhi"), TString(";#Delta#phi jet recoilmet;events/100 pb^{-1}"),40,0.,TMath::Pi());
    caloMetR1R2 = new TH2D("caloMetR1R2",";#Delta#phi (jet_{1},met);#Delta#phi (jet_{2},met)",40,0.,TMath::Pi(),40,0.,TMath::Pi());
    recoilMetR1R2 = new TH2D("recoilMetR1R2",";#Delta#phi (jet_{1},met);#Delta#phi (jet_{2},met)",40,0.,TMath::Pi(),40,0.,TMath::Pi());
    MPTMHTdPhi = new TH1D("MPTMHTdPhi",";#Delta#phi(MPT,MHT);events/100 pb^{-1}",40,0.,TMath::Pi());
    MPTMETdPhi = new TH1D("MPTMETdPhi",";#Delta#phi(MPT,MHT);events/100 pb^{-1}",40,0.,TMath::Pi());
    BookArray(hg_missed_MHT,TString("missed_MHT"), TString(";missed MHT;events/100 pb^{-1}"),100,0.,500);
    BookArray(hg_missed_MHT_ov_MHT,TString("missed_MHT_ov_MHT"), TString(";missed MHT/MHT;events/100 pb^{-1}"),44,0.,1.1);
    BookArray(hg_missed_MHT_ov_HT,TString("issed_MHT_ov_HT"),    TString(";missed MHT/HT;events/100 pb^{-1}"),44,0.,1.1);
    BookArray(hg_missed_MHTvec_ov_MHT,TString("missed_vector_MHT_ov_MHT"),    TString(";MHT(all jets)/MHT(selected jets);events/100 pb^{-1}"),44,0.,1.1);

    BookArray(hg_missed_MHT_vs_HT,TString("missed_MHT_vs_MHT"), TString("MHT;missed MHT"),50,0.,1000,100,0,500);
    BookArray(hg_missed_MHT_vs_MHT,TString("missed_MHT_vs_MH"), TString("HT;missed MHT"),50,0.,1000,100,0,500);


  } // end of CommonPlots constructor.




void  CommonPlots::BookArray(TH1D* histos[jetArrayLength],
           TString name,
           TString title,
           int bins,
           double min,
           double max)
  {

    if(jetArrayLength<2) cout << "WARNING: CommonPlots::BookArray jetArrayLength "<< jetArrayLength<< "<2 ??"<<endl;
    for (int i=0 ; i<jetArrayLength;i++)
      {
  TString myName;
  if(i==0) myName = name+"all";
  else{
    char aktuell[10];
    sprintf(aktuell, "%d", i+1);
    myName= name+"jets:"+aktuell;
  }
  histos[i] = new TH1D(myName,title,bins,min,max);
  histos[i]->Sumw2();
  //histos[i]->SetDirectory(mydir);
      }
  }

void  CommonPlots::BookArray(TH2D* histos[jetArrayLength],
           TString name,
           TString title,
           int bins,
           double min,
           double max,
           int binsY,
           double minY,
           double maxY)
  {

    if(jetArrayLength<2) cout << "WARNING: CommonPlots::BookArray jetArrayLength "<< jetArrayLength<< "<2 ??"<<endl;
    for (int i=0 ; i<jetArrayLength;i++)
      {
  TString myName;
  if(i==0) myName = name+"all";
  else{
    char aktuell[10];
    sprintf(aktuell, "%d", i+1);
    myName= name+"jets:"+aktuell;
  }
  histos[i] = new TH2D(myName,title,bins,min,max,binsY,minY,maxY);
  histos[i]->Sumw2();
      }
  }



  bool CommonPlots::Process(Event::Data & ev) {
    // Fill the histograms

    hg_HT[0]->Fill(ev.CommonSumEt(), ev.GetEventWeight());
    hg_MHT[0]->Fill(ev.CommonRecoilMET().Pt(), ev.GetEventWeight());
    hg_dPhi[0]->Fill(ev.CommonRecoilMETJetDPhi(), ev.GetEventWeight());
    hg_biasedPhi[0]->Fill(ev.BiasedCommonRecoilMETJetDPhi(), ev.GetEventWeight());
    hg_MHTovHT[0]->Fill(ev.CommonRecoilMET().Pt()/ev.CommonSumEt(), ev.GetEventWeight());
    hg_MHTovHT_biasdPhi[0]->Fill(ev.CommonRecoilMET().Pt()/ev.CommonSumEt(), ev.BiasedCommonRecoilMETJetDPhi(),ev.GetEventWeight());
    hg_MHTovHT_dPhi[0]->Fill(ev.CommonRecoilMET().Pt()/ev.CommonSumEt(), ev.CommonRecoilMETJetDPhi(),ev.GetEventWeight());

    hg_missed_MHT[0]->Fill(ev.JD_CommonJets().killedHT.Pt(),ev.GetEventWeight());
    hg_missed_MHT_ov_MHT[0]->Fill(ev.JD_CommonJets().killedHT.Pt()/ev.CommonRecoilMET().Pt(),ev.GetEventWeight());
    hg_missed_MHT_ov_HT[0]->Fill(ev.JD_CommonJets().killedHT.Pt()/ev.CommonSumEt(),ev.GetEventWeight());
    hg_missed_MHT_vs_HT[0]->Fill(ev.CommonSumEt(),ev.JD_CommonJets().killedHT.Pt(),ev.GetEventWeight());
    hg_missed_MHT_vs_MHT[0]->Fill(ev.CommonRecoilMET().Pt(),ev.JD_CommonJets().killedHT.Pt(),ev.GetEventWeight());

    hg_missed_MHTvec_ov_MHT[0]->Fill((ev.CommonRecoilMET()+ev.JD_CommonJets().killedHT).Pt()/ev.CommonRecoilMET().Pt(),ev.GetEventWeight());

    // cos theta star stuff
    float cosTheta = -1;
    float MScosTheta = -1;


  if(ev.JD_CommonJets().accepted.size()>1){

    caloMetR1R2->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[0]),
                  ev.CommonMHT())),
          fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[1]),
                  ev.CommonMHT())),
          ev.GetEventWeight());
  recoilMetR1R2->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[0]),
                  ev.CaloMET())),
          fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[1]),
                  ev.CaloMET())),
          ev.GetEventWeight());
    MPTMHTdPhi->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.MPT(),ev.CommonMHT())),ev.GetEventWeight());
    MPTMETdPhi->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(ev.MPT(),ev.CaloMET())),ev.GetEventWeight());
    cosTheta=ev.MScosThetaStar2Part(ev.JD_CommonJets().accepted[0],ev.JD_CommonJets().accepted[1]);
    MScosTheta=ev.cosThetaStar2Part(ev.JD_CommonJets().accepted[0],ev.JD_CommonJets().accepted[1]);
    hg_MScosT[0]->Fill(MScosTheta, ev.GetEventWeight());
    hg_cosT[0]->Fill(cosTheta, ev.GetEventWeight());
    }
    int myJetLenght = ev.JD_CommonJets().accepted.size()-1;
    if(myJetLenght>=jetArrayLength) myJetLenght=jetArrayLength-1;

    if (myJetLenght>0){
      hg_HT[myJetLenght]->Fill(ev.CommonSumEt(), ev.GetEventWeight());
      hg_dPhi[myJetLenght]->Fill(ev.CommonRecoilMETJetDPhi(), ev.GetEventWeight());
      hg_MHT[myJetLenght]->Fill(ev.CommonRecoilMET().Pt(), ev.GetEventWeight());
      hg_biasedPhi[myJetLenght]->Fill(ev.BiasedCommonRecoilMETJetDPhi(), ev.GetEventWeight());
      hg_cosT[myJetLenght]->Fill(cosTheta, ev.GetEventWeight());
      hg_MScosT[myJetLenght]->Fill(MScosTheta, ev.GetEventWeight());
      hg_MHTovHT[myJetLenght]->Fill(ev.CommonRecoilMET().Pt()/ev.CommonSumEt(), ev.GetEventWeight());
      hg_MHTovHT_biasdPhi[myJetLenght]->Fill(ev.CommonRecoilMET().Pt()/ev.CommonSumEt(), ev.BiasedCommonRecoilMETJetDPhi(),ev.GetEventWeight());
      hg_MHTovHT_dPhi[myJetLenght]->Fill(ev.CommonRecoilMET().Pt()/ev.CommonSumEt(), ev.CommonRecoilMETJetDPhi(),ev.GetEventWeight());
      hg_missed_MHT[myJetLenght]->Fill(ev.JD_CommonJets().killedHT.Pt(),ev.GetEventWeight());
      hg_missed_MHT_ov_MHT[myJetLenght]->Fill(ev.JD_CommonJets().killedHT.Pt()/ev.CommonRecoilMET().Pt(),ev.GetEventWeight());
      hg_missed_MHT_ov_HT[myJetLenght]->Fill(ev.JD_CommonJets().killedHT.Pt()/ev.CommonSumEt(),ev.GetEventWeight());
      hg_missed_MHT_vs_HT[myJetLenght]->Fill(ev.CommonSumEt(),ev.JD_CommonJets().killedHT.Pt(),ev.GetEventWeight());
      hg_missed_MHT_vs_MHT[myJetLenght]->Fill(ev.CommonRecoilMET().Pt(),ev.JD_CommonJets().killedHT.Pt(),ev.GetEventWeight());
      hg_missed_MHTvec_ov_MHT[myJetLenght]->Fill((ev.CommonRecoilMET()+ev.JD_CommonJets().killedHT).Pt()/ev.CommonRecoilMET().Pt(),ev.GetEventWeight());


    }

    hg_JetMultiplicity->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());

   if( ev.JD_CommonJets().accepted.size()>0)
      {
  hg_Pt[0]->Fill(ev.JD_CommonJets().accepted[0]->Pt(), ev.GetEventWeight());
  hg_Eta[0]->Fill(fabs(ev.JD_CommonJets().accepted[0]->Eta()), ev.GetEventWeight());
  hg_caloMetdPhi[0]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[0]),ev.CommonMHT())),ev.GetEventWeight());
  hg_TeCoilMetdPhi[0]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[0]),ev.CaloMET())),ev.GetEventWeight());
      }

    if( ev.JD_CommonJets().accepted.size()>1)
      {
  hg_Pt[1]->Fill(ev.JD_CommonJets().accepted[1]->Pt(), ev.GetEventWeight());
  hg_Eta[1]->Fill(fabs(ev.JD_CommonJets().accepted[1]->Eta()), ev.GetEventWeight());
  hg_caloMetdPhi[1]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[1]),ev.CommonMHT())),ev.GetEventWeight());
  hg_TeCoilMetdPhi[1]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted[1]),ev.CaloMET())),ev.GetEventWeight());
      }

    if( ev.JD_CommonJets().accepted.size()>2)
      {
  hg_Pt[2]->Fill(ev.JD_CommonJets().accepted[2]->Pt(), ev.GetEventWeight());
  hg_Eta[2]->Fill(fabs(ev.JD_CommonJets().accepted[2]->Eta()), ev.GetEventWeight());
  hg_caloMetdPhi[2]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[2],ev.CommonMHT())),ev.GetEventWeight());
  hg_TeCoilMetdPhi[2]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[2],ev.CaloMET())),ev.GetEventWeight());
      }

    if( ev.JD_CommonJets().accepted.size()>3)
      {
  hg_Pt[3]->Fill(ev.JD_CommonJets().accepted[3]->Pt(), ev.GetEventWeight());
  hg_Eta[3]->Fill(fabs(ev.JD_CommonJets().accepted[3]->Eta()), ev.GetEventWeight());
  hg_caloMetdPhi[3]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[3],ev.CommonMHT())),ev.GetEventWeight());
  hg_TeCoilMetdPhi[3]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[3],ev.CaloMET())),ev.GetEventWeight());
      }

    if( ev.JD_CommonJets().accepted.size()>4)
      {
  hg_Pt[4]->Fill(ev.JD_CommonJets().accepted[4]->Pt(), ev.GetEventWeight());
  hg_Eta[4]->Fill(fabs(ev.JD_CommonJets().accepted[4]->Eta()), ev.GetEventWeight());
  hg_caloMetdPhi[4]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[4],ev.CommonMHT())),ev.GetEventWeight());
  hg_TeCoilMetdPhi[4]->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*ev.JD_CommonJets().accepted[4],ev.CaloMET())),ev.GetEventWeight());
      }
    //ev.PrintGen();
    bool aWlep=false;
    if(ev.GenWtoTau()>0) {hg_WLepton->Fill(ev.GenWtoTau(),ev.GetEventWeight());aWlep=true;}
    if(ev.GenWtoElectron()>0) {hg_WLepton->Fill(ev.GenWtoElectron()+2,ev.GetEventWeight());aWlep=true;}
    if(ev.GenWtoMuon()>0){ hg_WLepton->Fill(ev.GenWtoMuon()+4,ev.GetEventWeight());aWlep=true;}
    if(aWlep) hg_WLepton->Fill(0.1,ev.GetEventWeight());
    else {hg_WLepton->Fill(7.1,ev.GetEventWeight());

    // ev.PrintGen();
    }

    LorentzV vec1;
    LorentzV vec2;
    int i=0;
    for ( std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin() ;
    j != ev.GenParticles().end();
    ++j ) {
      if(i==2) break;
      if (fabs(j->GetMother())==0) {
  if(i==1)
    {
      vec2 = *j;
      i++;
      // cout << "found "<<endl;
    }
  if(i==0)
    {
      vec1 = *j;
      i++;
    }
      }
    }

    // cout << vec1.Eta()<< " "<<vec2.Eta()<<endl;
    // hg_CosThetaGen->Fill(ev.cosThetaStar2Part(&vec1,&vec2), ev.GetEventWeight());

    // cout <<endl<<" Hi I am an nasty QCD Event, infos on me follow"<<endl<<endl;
    //  ev.PrintStableVisRec();
    //   ev.PrintStableVisAllRec();
    //   ev.PrintGen();


    return true; // Check for fails above, return false to fail operation.
  }

  std::ostream& CommonPlots::Description(std::ostream &ostrm) {
    ostrm <<endl;

    for(int i =3 ; i< 9 ;i++) {
      cout <<"jet bin: "<< i-1<< " "<< hg_JetMultiplicity->GetBinContent(i)<<" +/- " << hg_JetMultiplicity->GetBinError(i)<< endl;
    }

    ostrm << "CommonPlots plots are made";
    return ostrm;
  }



  //======================================
  // COMMON OBJECT SEARCH MATRIX PLOTTING
  //======================================
  ComSearchMatrix::ComSearchMatrix(const std::string & folderName,
           UInt_t jetmax,
           UInt_t lepmax,
           UInt_t phomax) :
    mFolderName(folderName),
    jetmax_(jetmax),
    lepmax_(lepmax),
    phomax_(phomax) {}
  ComSearchMatrix::~ComSearchMatrix() {}

  void ComSearchMatrix::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void ComSearchMatrix::BookHistos() {
    // Book the histograms - see Plotting.hh for BookHistArray documentation.

    // Book the histogram for the jet vs lepton search matrix plot
    //-------------------------------------------------------------
    // Note that the last entry is for events with > OBJmax inclusive - plot axes should
    // reflect this if possible.
    // The index of the histogram in the array indicates the number of common photons
    // in the events considered.
    BookHistArray(hg_jet_lep_, "Jet_vs_Lep", ";Number of leptons (e, #mu);Number of Jets",
      lepmax_+2,0.0,lepmax_+2,
      jetmax_+2,0.0,jetmax_+2,
      phomax_+2,0,1,false);

    BookHistArray(hg_jet_pho_, "Jet_vs_Pho", ";Number of photons;Number of Jets",
      phomax_+2,0.0,phomax_+2,
      jetmax_+2,0.0,jetmax_+2,
      lepmax_+2,0,1,false);
  }

  bool ComSearchMatrix::Process(Event::Data & ev) {
    // Fill your histograms...

    // Get the numbers of common objects
    UInt_t numcomjets = ev.JD_CommonJets().accepted.size();
    UInt_t numcomleptons = ev.LD_CommonElectrons().accepted.size()
      + ev.LD_CommonMuons().accepted.size();
    UInt_t numcomphotons = ev.PD_CommonPhotons().accepted.size();

    /*
      std::cout << "Number of jets, leptons, photons "
      << numcomjets << ", "
      << numcomleptons << ", "
      << numcomphotons
      << std::endl;
    */

    // Make adjustments for max size
    if (numcomjets > jetmax_) numcomjets = jetmax_ + 1;
    if (numcomleptons > lepmax_) numcomleptons = lepmax_ + 1;
    if (numcomphotons > phomax_) numcomphotons = phomax_ + 1;

    // Fill the histograms
    hg_jet_lep_[numcomphotons]->Fill( numcomleptons, numcomjets, ev.GetEventWeight() );
    hg_jet_pho_[numcomleptons]->Fill( numcomphotons, numcomjets, ev.GetEventWeight() );

    return true; // Plotting operations always pass.
  }

  std::ostream& ComSearchMatrix::Description(std::ostream &ostrm) {
    ostrm << "Plotting operation ComSearchMatrix ";
    // Add any further documentation, param names etc. here.
    ostrm << "(Plots in folder " << mFolderName << "): ";
    return ostrm;
  }
  //==================================================================

  //====================================
  // COMMON JET PLOTTING OPERATION
  //====================================
  ComJetPlots::ComJetPlots(const std::string & folderName,
        UInt_t numcomjets) :
    mFolderName(folderName),
    numcomjets_(numcomjets) {}
  ComJetPlots::~ComJetPlots() {}

  void ComJetPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }


  void ComJetPlots::BookHistos() {
    // Book the histograms - see Plotting.hh for BookHistArray documentation.
    BookHistArray(hg_multi_, "Multiplicity", ";Number of common jets;",numcomjets_+1,-0.5,numcomjets_+0.5,1,0,1,true);
    BookHistArray(hg_Pt_, "Pt",  ";p_{T} / GeV;",600,-1000.,2000.,numcomjets_+1,0,1,true);
    BookHistArray(hg_eta_, "eta",  ";#eta;",120,-6.,6.,numcomjets_+1,0,1,true);
    BookHistArray(hg_m_, "m",  ";m / GeV;",600,-1000.,2000.,numcomjets_+1,0,1,true);
    BookHistArray(hg_emfrac_, "emfrac",  ";F_{EM};",75,-0.5,3.0,numcomjets_+1,0,1,true);
  }

  bool ComJetPlots::Process(Event::Data & ev) {
    // Fill your histograms...

    // Fill multiplicity histogram
    hg_multi_[0]->Fill( ev.JD_CommonJets().accepted.size(),
      ev.GetEventWeight() );

    UInt_t count = 0;
    // Loop through the common photons
    for (std::vector<Event::Jet const *>::const_iterator cj = ev.JD_CommonJets().accepted.begin();
       cj!= ev.JD_CommonJets().accepted.end();
   ++cj) {
      count++;
      // Fill "all" (i.e. "0") histogram(s) first
      hg_Pt_[0]->Fill( (**cj).Pt(), ev.GetEventWeight() );
      hg_eta_[0]->Fill( (**cj).Eta(), ev.GetEventWeight() );
      hg_m_[0]->Fill( (**cj).M(), ev.GetEventWeight() );
      hg_emfrac_[0]->Fill( (**cj).GetEmFrac(), ev.GetEventWeight() );

      // Check needed so we don't seg fault... ;-)
      if (count <= numcomjets_) {
  hg_Pt_[count]->Fill( (**cj).Pt(), ev.GetEventWeight() );
  hg_eta_[count]->Fill( (**cj).Eta(), ev.GetEventWeight() );
  hg_m_[count]->Fill( (**cj).M(), ev.GetEventWeight() );
  hg_emfrac_[count]->Fill( (**cj).GetEmFrac(), ev.GetEventWeight() );

      } // end of number of jets check

    } // end of loop over common jets

    return true; // Plotting operations always pass.
  }

  std::ostream& ComJetPlots::Description(std::ostream &ostrm) {
    ostrm << "Common jet plots ";
    // Add any further documentation, param names etc. here.
    ostrm << "for up to " << numcomjets_ << " jets ";
    ostrm << "(Plots in folder " << mFolderName << "): ";
    return ostrm;
  }
    //==================================================================

//====================================
  // COMMON PHOTON PLOTTING OPERATION
  //====================================
  ComPhoPlots::ComPhoPlots(const std::string & folderName,
              UInt_t numcomphotons) :
    mFolderName(folderName),
    numcomphotons_(numcomphotons) {}
  ComPhoPlots::~ComPhoPlots() {}

  void ComPhoPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }


  void ComPhoPlots::BookHistos() {
    // Book the histograms - see Plotting.hh for BookHistArray documentation.
    BookHistArray(hg_multi_, "Multiplicity", ";Number of common photons;",numcomphotons_+1,-0.5,numcomphotons_+0.5,1,0,1,true);
    BookHistArray(hg_Et_, "Et", ";E_{T} / GeV;",200,0.,2000.,numcomphotons_+1,0,1,true);
    BookHistArray(hg_eta_, "eta",  ";#eta;",120,-6.,6.,numcomphotons_+1,0,1,true);
    BookHistArray(hg_ecalIso_, "ecalIso",  ";ECAL Isolation;",50,0.,5.0,numcomphotons_+1,0,1,true);
    BookHistArray(hg_hcalIso_, "hcalIso",  ";HCAL Isolation;",50,0.,5.0,numcomphotons_+1,0,1,true);
    BookHistArray(hg_trackIso_, "trackIso",  ";Track Isolation;",50,0.,5.0,numcomphotons_+1,0,1,true);
    BookHistArray(hg_hadronicOverEm_, "hadronicOverEm",  ";hadronicOverEm;",50,0.,0.1,numcomphotons_+1,0,1,true);
    BookHistArray(hg_r9_, "r9",  ";r9;",50,0.,1.0,numcomphotons_+1,0,1,true);
    BookHistArray(hg_sigmaIetaIeta_, "sigmaIetaIeta",  ";sigmaIetaIeta;",50,0.,0.05,numcomphotons_+1,0,1,true);
    BookHistArray(hg_hasPixelSeed_, "hasPixelSeed",  ";hasPixelSeed;",2,0.,1.,numcomphotons_+1,0,1,true);
  }

  bool ComPhoPlots::Process(Event::Data & ev) {
    // Fill your histograms...

    // Fill multiplicity histogram
    hg_multi_[0]->Fill( ev.PD_CommonPhotons().accepted.size(),
            ev.GetEventWeight() );

    UInt_t count = 0;
    // Loop through the common photons
    for (std::vector<Event::Photon const *>::const_iterator cp = ev.PD_CommonPhotons().accepted.begin();
         cp!= ev.PD_CommonPhotons().accepted.end();
     ++cp) {
      count++;
      // Fill "all" (i.e. "0") histogram(s) first
      hg_Et_[0]->Fill( (**cp).Et(), ev.GetEventWeight() );
      hg_eta_[0]->Fill( (**cp).Eta(), ev.GetEventWeight() );
      hg_ecalIso_[0]->Fill( (**cp).ecalRecHitSumEtConeDR04(), ev.GetEventWeight() );
      hg_hcalIso_[0]->Fill( (**cp).hcalTowerSumEtConeDR04(), ev.GetEventWeight() );
      hg_trackIso_[0]->Fill( (**cp).trkSumPtHollowConeDR04(), ev.GetEventWeight() );
      hg_hadronicOverEm_[0]->Fill( (**cp).hadronicOverEm(), ev.GetEventWeight() );
      hg_r9_[0]->Fill( (**cp).r9(), ev.GetEventWeight() );
      hg_sigmaIetaIeta_[0]->Fill( (**cp).sigmaIetaIeta(), ev.GetEventWeight() );
      hg_hasPixelSeed_[0]->Fill( (**cp).hasPixelSeed() ? 1 : 0, ev.GetEventWeight() );

      // Check needed so we don't seg fault... ;-)
      if (count <= numcomphotons_) {
        hg_Et_[count]->Fill( (**cp).Et(), ev.GetEventWeight() );
        hg_eta_[count]->Fill( (**cp).Eta(), ev.GetEventWeight() );
        hg_ecalIso_[count]->Fill( (**cp).ecalRecHitSumEtConeDR04(), ev.GetEventWeight() );
        hg_hcalIso_[count]->Fill( (**cp).hcalTowerSumEtConeDR04(), ev.GetEventWeight() );
        hg_trackIso_[count]->Fill( (**cp).trkSumPtHollowConeDR04(), ev.GetEventWeight() );
        hg_hadronicOverEm_[count]->Fill( (**cp).hadronicOverEm(), ev.GetEventWeight() );
        hg_r9_[count]->Fill( (**cp).r9(), ev.GetEventWeight() );
        hg_sigmaIetaIeta_[count]->Fill( (**cp).sigmaIetaIeta(), ev.GetEventWeight() );
        hg_hasPixelSeed_[count]->Fill( (**cp).hasPixelSeed() ? 1 : 0, ev.GetEventWeight() );
      }

    } // end of loop over common photons

    return true; // Plotting operations always pass.
  }

  std::ostream& ComPhoPlots::Description(std::ostream &ostrm) {
    ostrm << "Common photon plots ";
    // Add any further documentation, param names etc. here.
    ostrm << "for up to " << numcomphotons_ << " photons ";
    ostrm << "(Plots in folder " << mFolderName << "): ";
    return ostrm;
  }

/*
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

  BookHistArray( Mt2_,
    "Mt2",
    ";MT2 / GeV;Number of Events",
    100, 0., 2000.,
    nBins_+2, 0, 1, true );

  BookHistArray( AlphaT_,
    "AlphaT",
    ";#alpha_{T};Number of Events",
    60,0.,1.5,
    nBins_+2, 0, 1, true );

  BookHistArray( AlphaT_Hadronic_,
    "AlphaT_Hadronic",
    ";Hadronic #alpha_{T};Number of Events",
    60,0.,1.5,
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

  std::cout << "Entered main loop of standard plots" << std::endl;
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
  Double_t weight = ev.GetEventWeight();
  //Double_t weight = ev.SusyCrossSection()*151/10000;

  // sin ( dPhi* )
  double Sinphistar = TMath::Sin(ev.CommonMinBiasDPhi());
  if(Sinphistar < 0){Sinphistar = 1.0;}
  // Calculate number of vertices
  int nVertices = 0;
  for( int i = 0; i<ev.GetVertexSize(); i++)
  {
    if(!ev.GetvertexIsFake(i) && fabs(ev.GetvertexPosition(i).Z()) < 24.0 && ev.GetvertexNdof(i)> 4&& ev.GetvertexPosition(i).Rho() < 2.0) nVertices+=1;
  }

  // 0 = all in range (1->n); n = nth bin; n+1 = overflow bin
  if ( n <= nBins_ + 1) {
    //Mt2_[0]->Fill( StandardPlots::MT2_Leading(ev), weight );
    //Mt2_[n]->Fill( StandardPlots::MT2_Leading(ev), weight );
    //AlphaT_[0]->Fill( ev.CommonAlphaT(), weight );
    //AlphaT_[n]->Fill( ev.CommonAlphaT(), weight );
    //AlphaT_Hadronic_[0]->Fill( ev.hadAlpha_t(), weight );
    //AlphaT_Hadronic_[n]->Fill( ev.hadAlpha_t(), weight );
    nVertices_[0]->Fill( ev.GetVertexSize(), weight );
    nVertices_[n]->Fill( ev.GetVertexSize(), weight );
    nJets_[0]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    nJets_[n]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    HT_[0]->Fill( ev.CommonHT(), weight );
    HT_[n]->Fill( ev.CommonHT(), weight );
    Meff_[0]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    Meff_[n]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    //BiasedDphi_[0]->Fill( ev.JetMinBiasDPhi(), weight );
    //BiasedDphi_[n]->Fill( ev.JetMinBiasDPhi(), weight );
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
    //std::cout << "Filled event variables" << std::endl;
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
    //std::cout << "Filled object variables" << std::endl;
  } else {
    //Mt2_[nBins_+1]->Fill( StandardPlots::MT2_Leading(ev), weight );
    //AlphaT_[nBins_+1]->Fill( ev.CommonAlphaT(), weight );
    //AlphaT_Hadronic_[nBins_+1]->Fill( ev.hadAlpha_t(), weight );
    nVertices_[0]->Fill( ev.GetVertexSize(), weight );
    nVertices_[nBins_+1]->Fill( ev.GetVertexSize(), weight );
    nJets_[0]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    nJets_[nBins_+1]->Fill( ev.JD_CommonJets().accepted.size(), weight );
    HT_[0]->Fill( ev.CommonHT(), weight );
    HT_[nBins_+1]->Fill( ev.CommonHT(), weight );
    Meff_[0]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    Meff_[nBins_+1]->Fill( ev.CommonMHT().Pt() + ev.CommonHT(), weight );
    //BiasedDphi_[0]->Fill( ev.JetMinBiasDPhi(), weight );
    //BiasedDphi_[nBins_+1]->Fill( ev.JetMinBiasDPhi(), weight );
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

Double_t StandardPlots::MT2_Leading( Event::Data& ev ){
  mt2_bisect::mt2 mt2_event;
  std::vector<Event::Jet const *> jet = ev.JD_CommonJets().accepted;

  LorentzV lv1 = *(jet[0]);
  LorentzV lv2 = *(jet[1]);

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

Double_t StandardPlots::MT2( Event::Data& ev){

  std::vector<LorentzV> obj = ev.CommonObjects();
  UInt_t n = obj.size();

  mt2_bisect::mt2 mt2_event;

  LorentzV lv1(0.,0.,0.,0.);
  LorentzV lv2(0.,0.,0.,0.);

  // Alpha_t variable
  std::vector<bool> pseudo;
  double alpha_t;
  alpha_t = AlphaT()( obj, pseudo, false );
  if ( pseudo.size() != obj.size() ) { abort(); }
    // use this to get the pseudo jets

  if ( n == 2 ) {
    lv1 = obj[0];
    lv2 = obj[1];
  } else if ( n > 2 ) {
    for ( unsigned int i = 0; i < obj.size(); ++i ) {
      if ( pseudo[i] ) { lv1 += obj[i];
        // std::cout << "Jets included in Jet 1 = " << i << std::endl;
      }
      else             { lv2 += obj[i];
        // std::cout << "Jets included in Jet 2 = " << i << std::endl;
      }
    }
    if ( lv2.Pt() > lv1.Pt() ) { LorentzV tmp = lv1; lv1 = lv2; lv2 = tmp; }

  }

  double pa[3]; // px py m of object 1
  double pb[3]; // px py m of object 2
  double pm[3];       //jet1
  pa[0] = lv1.Px();
  pa[1] = lv1.Py();
  pa[2] = 0.;//KS_MT(objects[0]);

  pb[0] = lv2.Px();
  pb[1] = lv2.Py();
  pb[2] = 0.;//KS_MT(objects[1]);

  pm[1]= ev.CommonRecoilMET().Px();
  pm[2]= ev.CommonRecoilMET().Py();

  // set invisable mass
  double mn = 0.;
  mt2_event.set_momenta(pa,pb,pm);
  mt2_event.set_mn(mn);

  return mt2_event.get_mt2();
}
*/

MetPlots::MetPlots( const Utils::ParameterSet& ps ) :
  dirName_( ps.Get<std::string>("DirName") ),
  variable_( ps.Get<std::string>("VariableName") ),
  valueMin_( ps.Get<Double_t>("MinValue") ),
  nBins_( ps.Get<int>("nBins") ),
  binWidth_( ps.Get<Double_t>("BinWidth") )
{}

MetPlots::~MetPlots() {}

void MetPlots::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

void MetPlots::BookHistos() {

  BookHistArray( caloMet_, "caloMet", ";Calo ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  BookHistArray( caloMetNoHf_, "caloMetNoHf", ";Calo ME_{T} no HF / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  BookHistArray( pfMet_, "pfMet", ";pf ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  BookHistArray( tcMet_, "tcMet", ";tc ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  BookHistArray( ak5CaloMet_, "ak5CaloMet", ";AK5 Calo ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  BookHistArray( ic5CaloMet_, "ic5CaloMet", ";IC5 Calo ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  //BookHistArray( ak7CaloMet_, "ak7CaloMet", ";AK7 Calo ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  //BookHistArray( ak5JptMet_, "ak5JptMet", ";AK5 JPT ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );
  //BookHistArray( ak5PfMet_, "ak5PfMet", ";AK5 PF ME_{T} / GeV;Number of Events", 100, 0., 1000., nBins_+2, 0, 1, true );

}

bool MetPlots::Process( Event::Data& ev ) {

  Double_t value;
  if (variable_ == "nObjects") {
    value = static_cast<double>(ev.CommonObjects().size());
  } else if (variable_ == "HT") {
    value = ev.CommonSumEt();
  } else if (variable_ == "Meff") {
    value = ev.CommonRecoilMET().Pt() + ev.CommonSumEt();
  } else {
    std::cout << "[Met Plots] Error: Variable [" << variable_ << "] not recognised" << std::endl;
  }

  UInt_t n = int( (value - valueMin_)/binWidth_ ) + 1;
  Double_t weight = ev.GetEventWeight();

  if ( n <= nBins_ + 1) {
    caloMet_[0]->Fill( ev.CaloMET().Pt(), weight );
    caloMet_[n]->Fill( ev.CaloMET().Pt(), weight );
    caloMetNoHf_[0]->Fill( ev.CaloMET().Pt(), weight );
    caloMetNoHf_[n]->Fill( ev.CaloMETnohf().Pt(), weight );
    pfMet_[0]->Fill( ev.PFMET().Pt(), weight );
    pfMet_[n]->Fill( ev.PFMET().Pt(), weight );
    tcMet_[0]->Fill( ev.TCMET().Pt(), weight );
    tcMet_[n]->Fill( ev.TCMET().Pt(), weight );
    ak5CaloMet_[0]->Fill( ev.AK5MET().Pt(), weight );
    ak5CaloMet_[n]->Fill( ev.AK5MET().Pt(), weight );
    ic5CaloMet_[0]->Fill( ev.IC5MET().Pt(), weight );
    ic5CaloMet_[n]->Fill( ev.IC5MET().Pt(), weight );
    //ak7CaloMet_[0]->Fill( ev.AK7MET().Pt(), weight );
    //ak7CaloMet_[n]->Fill( ev.AK7MET().Pt(), weight );
    //ak5PfMet_[0]->Fill( ev.AK5PFMET().Pt(), weight );
    //ak5PfMet_[n]->Fill( ev.AK5PFMET().Pt(), weight );
    //ak5JptMet_[0]->Fill( ev.AK5JPTMET().Pt(), weight );
    //ak5JptMet_[n]->Fill( ev.AK5JPTMET().Pt(), weight );
  } else {
    caloMet_[nBins_+1]->Fill( ev.CaloMET().Pt(), weight );
    caloMetNoHf_[nBins_+1]->Fill( ev.CaloMETnohf().Pt(), weight );
    pfMet_[nBins_+1]->Fill( ev.PFMET().Pt(), weight );
    tcMet_[nBins_+1]->Fill( ev.TCMET().Pt(), weight );
    ak5CaloMet_[nBins_+1]->Fill( ev.AK5MET().Pt(), weight );
    ic5CaloMet_[nBins_+1]->Fill( ev.IC5MET().Pt(), weight );
    //ak7CaloMet_[nBins_+1]->Fill( ev.AK7MET().Pt(), weight );
    //ak5PfMet_[nBins_+1]->Fill( ev.AK5PfMET().Pt(), weight );
    //ak5JptMet_[nBins_+1]->Fill( ev.AK5JPTMET().Pt(), weight );
  }
  return true;
}

std::ostream& MetPlots::Description( std::ostream& ostrm ) {
  ostrm << "Met Plots ";
  ostrm<<"( "<<nBins_<<" bins in "<<variable_<<" from "<<valueMin_<<" to "<<valueMin_+nBins_*binWidth_<<"; bin width = "<<binWidth_<<") ";
  return ostrm;
}

  EventNoDump::EventNoDump(const std::string & folderName,std::string TreeName):mFolderName(folderName),mTreeName(TreeName){}
  EventNoDump::~EventNoDump(){}
  void EventNoDump::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void EventNoDump::BookHistos() {

    mTree = new TTree(TString(mTreeName),TString(mTreeName));
    mTree->Branch("LS",&LS,"LS/I");
    mTree->Branch("Run",&Run,"Run/I");
    mTree->Branch("Event",&Event,"Event/I");
    // ostrm.open("event.txt");

  }

  bool EventNoDump::Process(Event::Data & ev) {


    //   ev.PrintStableVisRec();
    //  ev.PrintStableVisAllRec();
    //   ev.PrintGen();

    Run = ev.RunNumber();
    Event = ev.EventNumber();
    LS = ev.LumiSection();
    mTree->Fill();



    //   ostrm.open("event.txt", ios::out | ios::app | ios::binary);
     std::ofstream ostrm("event.txt",fstream::app);

     ostrm <<" NEW EVENT" << endl <<endl;
     ostrm <<"Run: "<< Run<<" Event: " << Event << " LS: " << LS <<endl;

     ostrm <<" MHT/PFMET = :" << ev.CommonMHT().Pt()/ev.PFMET().Pt() <<endl;
     ostrm <<" phi* = :" <<ev.CommonMinBiasDPhi() <<endl;
     ostrm <<" MHT/HT = :" <<ev.CommonMHT().Pt()/ ev.CommonHT() <<endl;
     ostrm <<" alpha_T = :" << ev.CommonAlphaT()<<endl;
     ostrm << "First the other jet Collection: "<<std::endl;

     LorentzV testOther(0,0,0,0);
     float HTOther = 0;

     // Add jetAK5P4 to ICF_Ntuple and fill it with your favorite other jetcollection, e.g. PF jets, then you can print out jet by jet comparison as e.g. below
     /*
       for (std::vector<LorentzV>::const_iterator ak5 = ev.jetAK5P4()->begin();
   ak5 !=  ev.jetAK5P4()->end();
   ++ak5) {
   ostrm << "Pt: " << (*ak5).Pt()
         << " Phi: "<<  (*ak5).Phi()
         << " Eta: "<<  (*ak5).Eta()<<endl;

   HTOther+= (*ak5).Pt();
   testOther+= (*ak5);
       }
     */


       ostrm << "other collection MHT Pt: " << testOther.Pt() <<" phi " << (-testOther).Phi() << " other HT "<< HTOther << endl;
       ostrm<<std::endl << "Now the selected jets: "<<std::endl;
    LorentzV test(0,0,0,0);
    for (std::vector<Event::Jet const *>::const_iterator iph = ev.JD_CommonJets().accepted.begin();
   iph != ev.JD_CommonJets().accepted.end();
   ++iph) {
      ostrm << "Pt: " << (*iph)->Pt()
      << " Phi: "<<  (*iph)->Phi()
      << " Eta: "<<  (*iph)->Eta()
      <<" fem: "<< (*iph)->GetEmFrac()
      << endl;
      test+=  (**iph);
    }

   ostrm << "MHT Pt: " << test.Pt() <<" phi " << (-test).Phi() << " "<< ev.CommonRecoilMET().Pt() << endl;
     ostrm<<std::endl << "Now all jets: "<<std::endl;
     // if you run on MC you can also print out the genjets
     /* LorentzV testgen(0,0,0,0);

     for (std::vector<LorentzV>::const_iterator gen = ev.genJetP4()->begin();
     gen !=  ev.genJetP4()->end();
     ++gen) {
     ostrm << "Pt: " << (*gen).Pt()
     << " Phi: "<<  (*gen).Phi()
     << " Eta: "<<  (*gen).Eta()<<endl;

     testgen+=(*gen);
     }

     ostrm << "gen MHT Pt: " << testgen.Pt() <<" phi " << (-testgen).Phi()<< endl;
     */

   LorentzV test2(0,0,0,0);
   for (std::vector<Event::Jet>::const_iterator iph = ev.JD_Jets().begin();
  iph != ev.JD_Jets().end();
  ++iph) {
     ostrm << "Pt: " << iph->Pt()<< " Phi: "<<  iph->Phi()<< " Eta: "<<  iph->Eta()<<  " fem: "<< iph->GetEmFrac()<<endl;
     test2+=  (*iph);
   }
   ostrm << "all jets MHT Pt: " << test2.Pt() <<" phi " << (-test2).Phi() << ", selected jet MHT: "<< ev.CommonRecoilMET().Pt() << endl;
   if(ev.LD_Muons().size()>0) ostrm << "Muons:" <<endl;
   for (std::vector<Event::Lepton>::const_iterator iph = ev.LD_Muons().begin(); iph != ev.LD_Muons().end(); ++iph) {
     ostrm << "Pt: " << iph->Pt()<< " Phi: "<<  iph->Phi()<< " Eta: "<<  iph->Eta()<< endl;
   }

   if(ev.LD_Electrons().size()>0) ostrm << "Elis:" <<endl;
   for (std::vector<Event::Lepton>::const_iterator iph = ev.LD_Electrons().begin(); iph != ev.LD_Electrons().end(); ++iph) {
     ostrm << "Pt: " << iph->Pt()<< " Phi: "<<  iph->Phi()<< " Eta: "<<  iph->Eta()<< endl;
   }

   if(ev.PD_Photons().size()>0) ostrm << "Photons:" <<endl;
   for (std::vector<Event::Photon>::const_iterator iph = ev.PD_Photons().begin();
  iph != ev.PD_Photons().end();
  ++iph) {
     ostrm << "Pt: " << iph->Pt()<< " Phi: "<<  iph->Phi()<< " Eta: "<<  iph->Eta()<<endl;
   }

   if(ev.LD_Taus().size()>0) ostrm << "Taus:" <<endl;
   for (std::vector<Event::Lepton>::const_iterator iph = ev.LD_Taus().begin();
  iph != ev.LD_Taus().end();
  ++iph) {
     ostrm << "Pt: " << iph->Pt()
     << " Phi: "<< iph->Phi()
     << " Eta: "<< iph->Eta()
     << endl;
   }

   // For unknown (to Markus) reasons in the current head: class Event::Data has no member named rechitCaloP4 occurs
   // If you want noise rechits printed solve the issue
   /*
   ostrm <<"spiky the dog: "<< endl;
     for (std::vector<LorentzV>::const_iterator  it = ev.rechitCaloP4()->begin(); it != ev.rechitCaloP4()->end(); ++it)
     {
     ostrm   << "ECAL SPIKE: Rec Hit pt = " << it->Pt() << std::endl;
     ostrm   << "RecHit pt = " << it->Pt() << std::endl;
     ostrm   << "RecHit eta = " << it->Eta() << std::endl;
     ostrm   << "RecHit phi = " << it->Phi() << std::endl;
     ostrm   << "RecHit time = " << ev.rechitCaloTime()->at(it - ev.rechitCaloP4()->begin()) << std::endl;
     ostrm   << "RecHit severity = " << ev.rechitCaloSeverityLevel()->at(it - ev.rechitCaloP4()->begin()) << std::endl;
     }
   */
   //}
   ostrm.close();
   return true;
 }

 std::ostream&   EventNoDump::Description(std::ostream &aostrm) {
   aostrm<<"EventNoDump:I survived  even: " <<  mTreeName << std::endl;
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
   std::cout << "buffer: "<<buffer<<endl;
   aostrm << buffer;
   return aostrm;
 }



} //~namespace Operation

