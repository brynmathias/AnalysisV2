#include "MuonPlottingOps.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"

//====================================
// MuonPlottingOps implementation
//====================================

namespace Operation {
  MuonPlottingOps::MuonPlottingOps(const std::string & folderName) :
    mFolderName(folderName) {}

  MuonPlottingOps::~MuonPlottingOps() {}

  void MuonPlottingOps::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MuonPlottingOps::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    hInrTrkDxy_All = new TH1D("hInrTrkDxy_All","hInrTrkDxy_All",800,-2.,2.);
    hInrTrkDxyBS_All = new TH1D("hInrTrkDxyBS_All","hInrTrkDxyBS_All",800,-2.,2.);
    hInrTrkDxyErr_All = new TH1D("hInrTrkDxyErr_All","hInrTrkDxyErr_All",400,0.,0.4);
    hInrTrkDxyOvDxyErr_All = new TH1D("hInrTrkDxyOvDxyErr_All","hInrTrkDxyOvDxyErr_All",400,-200.,200.);
    hInrTrkNormChi2_All = new TH1D("hInrTrkNormChi2_All","hInrTrkNormChi2_All",3000,0.,30.);
    hInrTrkValidHits_All = new TH1D("hInrTrkValidHits_All","hInrTrkValidHits_All",75,0.,75.);

    hInrTrkDxyVsInrTrkNormChi2_All = new TH2D("hInrTrkDxyVsInrTrkNormChi2_All","hInrTrkDxyVsInrTrkNormChi2_All",3000,0.,30.,800,-2.,2.);
    hInrTrkDxyVsInrTrkValidHits_All = new TH2D("hInrTrkDxyVsInrTrkValidHits_All","hInrTrkDxyVsInrTrkValidHits_All",75,0.,75.,800,-2.,2.);
    hInrTrkValidHitsVsInrTrkNormChi2_All = new TH2D("hInrTrkValidHitsVsChi2_All","hInrTrkValidHitsVsChi2_All",3000,0.,30.,75,0.,75.);
  
    hGlbTrkDxy_All    = new TH1D("hGlbTrkDxy_All","hGlbTrkDxy_All",800,-2.,2.);
    hGlbTrkDxyErr_All    = new TH1D("hGlbTrkDxyErr_All","hGlbTrkDxyErr_All",400,0.,0.4);
    hGlbTrkDxyOvDxyErr_All = new TH1D("hGlbTrkDxyOvDxyErr_All","hGlbTrkDxyOvDxyErr_All",400,-200.,200.);
    hGlbTrkNormChi2_All  = new TH1D("hGlbTrkNormChi2_All","hGlbTrkNormChi2_All",3000,0.,30.);
    hGlbTrkValidHits_All = new TH1D("hGlbTrkValidHits_All","hGlbTrkValidHits_All",75,0.,75.);
  
    hGlbTrkDxyVsGlbTrkNormChi2_All = new TH2D("hGlbTrkDxyVsGlbTrkNormChi2_All","hGlbTrkDxyVsGlbTrkNormChi2_All",3000,0.,30.,800,-2.,2.);
    hGlbTrkDxyVsGlbTrkValidHits_All = new TH2D("hGlbTrkDxyVsGlbTrkValidHits_All","hGlbTrkDxyVsGlbTrkValidHits_All",75,0.,75.,800,-2.,2.);
    hGlbTrkValidHitsVsGlbTrkNormChi2_All = new TH2D("hGlbTrkValidHitsVsNormChi2_All","hGlbTrkValidHitsVsNormChi2_All",3000,0.,30.,75,0.,75.);

    hInrTrkDxyVsInrTrkDxyBs_All = new TH2D("hInrTrkDxyVsInrTrkDxyBs_All","hInrTrkDxyVsInrTrkDxyBs_All;Dxy(vertex);Dxy(beamspot)",1000, -0.1, 0.1, 1000, -0.1, 0.1);

    hGlbMuMultiplicity = new TH1D("hGlbMuMultiplicity","hGlbMuMultiplicity;;", 20, -0.5, 19.5);
    hGlbMuTrue = new TH1D("hGlbMuTrue","hGlbMuTrue",2,-0.5,1.5);
    hTrkMuTrue = new TH1D("hTrkMuTrue","hTrkMuTrue",2,-0.5,1.5);
    hGlbTrkMuTrue = new TH1D("hGlbTrkMuTrue","hGlbTrkMuTrue",2,-0.5,1.5);
    hMu1Pt1 = new TH1D("hMu1Pt1", "hMu1Pt1;1Mu case: P_{T}(Muon);", 1000, -0.5, 499.5);
    hMu2Pt1 = new TH1D("hMu2Pt1", "hMu2Pt1;2Mu case: P_{T}(Muon1);", 1000, -0.5, 499.5);
    hMu2Pt2 = new TH1D("hMu2Pt2", "hMu2Pt2;2Mu case: P_{T}(Muon2);", 1000, -0.5, 499.5);
    hMu2InvMass = new TH1D("hMu2InvMass", "hMu2InvMass;invariant mass 2 muon pair;", 1000, -0.5, 249.5);

    hpfMET1 = new TH1D("hpfMET1","hpfMET1;;", 1000, -0.5, 249.5);
    hMT1 = new TH1D("hMT1","hMT1",1000, -0.5, 249.5);
    hpfMET2 = new TH1D("hpfMET2","hpfMET2;;", 1000, -0.5, 249.5);
    hMT2 = new TH1D("hMT2","hMT2",1000, -0.5, 249.5);

    hBeamSpotX = new TH1D("hBeamSpotX","hBeamSpotX;;",200, -0.1005, 0.0995);
    hBeamSpotY = new TH1D("hBeamSpotY","hBeamSpotY;;",200, -0.1005, 0.0995);
    hVertexX = new TH1D("hVertexX","hVertexX;;",200, -0.1005, 0.0995);
    hVertexY = new TH1D("hVertexY","hVertexY;;",200, -0.1005, 0.0995);
    hNumVerticesPerEvent = new TH1D("hNumVerticesPerEvent","hNumVerticesPerEvent;;",25, -0.5, 24.5);
    hNumPixelHits = new TH1D("hNumPixelHits","hNumPixelHits;;",25, -0.5, 24.5);
    hNumMatches = new TH1D("hNumMatches","hNumMatches;;",25, -0.5, 24.5);

    hCombIsolation = new TH1D("hCombIsolation", "hCombIsolation;;",1000,-0.005,9.995);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool MuonPlottingOps::Process(Event::Data & ev) {
    double tmpInrTrkD0 = -999.;
    double tmpInrTrkD0BS = -999.;
    double tmpInrTrkD0Err = -999.;
    double tmpInrTrkD0OvD0Err = -999.;
    double tmpInrTrkNormChi2ndf = -999.;
    int tmpInrTrkNhits = -999;
  
    double tmpGlbTrkD0 = -999.;
    double tmpGlbTrkD0Err = -999.;
    double tmpGlbTrkD0OvD0Err = -999.;
    double tmpGlbTrkNormChi2ndf = -999.;
    int tmpGlbTrkNhits = -999;

    //LorentzV pfMET = (ev.PFMET() + *(ev.LD_CommonMuons().accepted.at(0)));
    double MT = sqrt(2.0 * ev.PFMET().Pt() * ev.LD_CommonMuons().accepted.at(0)->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonMuons().accepted.at(0), ev.PFMET()))));

    hGlbMuMultiplicity->Fill(ev.LD_CommonMuons().accepted.size(), ev.GetEventWeight());
    if(ev.LD_CommonMuons().accepted.size() == 1) {
      hMu1Pt1->Fill(ev.LD_CommonMuons().accepted.at(0)->Pt(), ev.GetEventWeight());
      if(ev.LD_CommonMuons().accepted.at(0)->Pt() > 20.0) {
	hMT1->Fill(MT, ev.GetEventWeight());
	hpfMET1->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
      }
    }
    if(ev.LD_CommonMuons().accepted.size() == 2) {
      hMu2Pt1->Fill(ev.LD_CommonMuons().accepted.at(0)->Pt(), ev.GetEventWeight());
      //hMu2Pt2->Fill(ev.LD_CommonMuons().accepted.at(1)->Pt(), ev.GetEventWeight());
      LorentzV mupair = *(ev.LD_CommonMuons().accepted.at(0)) + *(ev.LD_CommonMuons().accepted.at(1));
      if(ev.LD_CommonMuons().accepted.at(0)->Pt() > 20.0 && ev.LD_CommonMuons().accepted.at(1)->Pt() < 20.0) {
	hMu2Pt2->Fill(ev.LD_CommonMuons().accepted.at(1)->Pt(), ev.GetEventWeight()); 
	hMu2InvMass->Fill(mupair.M(), ev.GetEventWeight());
	hMT2->Fill(MT, ev.GetEventWeight());
	hpfMET2->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
      }
    }

    hBeamSpotX->Fill(ev.GetBeamSpotPosition().X(), ev.GetEventWeight());
    hBeamSpotY->Fill(ev.GetBeamSpotPosition().Y(), ev.GetEventWeight());
    hVertexX->Fill(ev.GetvertexPosition(0).X(), ev.GetEventWeight());
    hVertexY->Fill(ev.GetvertexPosition(0).Y(), ev.GetEventWeight());
    hNumVerticesPerEvent->Fill(ev.GetVertexSize(), ev.GetEventWeight());

    for (std::vector<Event::Lepton const *>::const_iterator ob = ev.LD_CommonMuons().accepted.begin(); ob != ev.LD_CommonMuons().accepted.end(); ++ob) {

      int iM = (*ob)->GetIndex();

      tmpInrTrkD0 = ev.GetMuonInnerTrackDxy(iM);
      tmpInrTrkD0BS = ev.GetMuonInnerTrackDxyBS(iM);
      tmpInrTrkD0Err= ev.GetMuonInnerTrackDxyError(iM);
      tmpInrTrkD0OvD0Err= tmpInrTrkD0/tmpInrTrkD0Err;
      tmpInrTrkNormChi2ndf = ev.GetMuonInnerTrackNormChi2(iM);
      tmpInrTrkNhits = ev.GetMuonInnerTracknumberOfValidHits(iM);
   
      tmpGlbTrkD0 = ev.GetMuonGlobalTrackdxy(iM);
      tmpGlbTrkD0Err= ev.GetMuonGlobalTrackdxyError(iM);
      tmpGlbTrkD0OvD0Err= tmpGlbTrkD0/tmpGlbTrkD0Err;
      tmpGlbTrkNormChi2ndf = ev.GetMuonGlobalTrackNormChi2(iM);
      tmpGlbTrkNhits = ev.GetMuonGlobalTracknumberOfValidHits(iM);

      hInrTrkDxy_All->Fill(tmpInrTrkD0,ev.GetEventWeight());
      hInrTrkDxyBS_All->Fill(tmpInrTrkD0BS,ev.GetEventWeight());
      hInrTrkDxyErr_All->Fill(tmpInrTrkD0Err,ev.GetEventWeight());
      hInrTrkDxyOvDxyErr_All->Fill(tmpInrTrkD0OvD0Err,ev.GetEventWeight());
      hInrTrkNormChi2_All->Fill(tmpInrTrkNormChi2ndf,ev.GetEventWeight());
      hInrTrkValidHits_All->Fill(tmpInrTrkNhits,ev.GetEventWeight());
      hInrTrkDxyVsInrTrkNormChi2_All->Fill(tmpInrTrkNormChi2ndf,tmpInrTrkD0,ev.GetEventWeight());
      hInrTrkDxyVsInrTrkValidHits_All->Fill(tmpInrTrkNhits,tmpInrTrkD0,ev.GetEventWeight());
      hInrTrkValidHitsVsInrTrkNormChi2_All->Fill(tmpInrTrkNormChi2ndf,tmpInrTrkNhits,ev.GetEventWeight());
      hInrTrkDxyVsInrTrkDxyBs_All->Fill(tmpInrTrkD0, tmpInrTrkD0BS, ev.GetEventWeight());

      hGlbTrkDxy_All->Fill(tmpGlbTrkD0,ev.GetEventWeight());
      hGlbTrkDxyErr_All->Fill(tmpGlbTrkD0Err,ev.GetEventWeight());
      hGlbTrkDxyOvDxyErr_All->Fill(tmpGlbTrkD0OvD0Err,ev.GetEventWeight());
      hGlbTrkNormChi2_All->Fill(tmpGlbTrkNormChi2ndf,ev.GetEventWeight());
      hGlbTrkValidHits_All->Fill(tmpGlbTrkNhits,ev.GetEventWeight());
      //hGlbTrkDxyVsGlbTrkNormChi2_All->Fill(tmpGlbTrkNormChi2ndf,tmpGlbTrkD0,ev.GetEventWeight());
      //hGlbTrkDxyVsGlbTrkValidHits_All->Fill(tmpGlbTrkNhits,tmpGlbTrkD0,ev.GetEventWeight());
      hGlbTrkValidHitsVsGlbTrkNormChi2_All->Fill(tmpGlbTrkNormChi2ndf,tmpGlbTrkNhits,ev.GetEventWeight());

      hGlbMuTrue->Fill(ev.IsMuonGlobal(iM), ev.GetEventWeight());
      hTrkMuTrue->Fill(ev.IsMuonTracker(iM), ev.GetEventWeight());
      if(ev.IsMuonGlobal(iM) && ev.IsMuonTracker(iM)) hGlbTrkMuTrue->Fill(1.0, ev.GetEventWeight());

      hNumMatches->Fill(ev.muonNumberOfMatches()->at(iM), ev.GetEventWeight());
      hNumPixelHits->Fill(ev.muonNumberOfValidPixelHits()->at(iM), ev.GetEventWeight());
      hCombIsolation->Fill((*ob)->GetCombIsolation(), ev.GetEventWeight());
    }
  
    return true;
  }


  std::ostream& MuonPlottingOps::Description(std::ostream &ostrm) {
    ostrm << "Plotting Suite for MuonID Parameters";
    return ostrm;
  }
}
