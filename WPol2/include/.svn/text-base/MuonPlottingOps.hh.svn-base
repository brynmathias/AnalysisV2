#ifndef MuonPlottingOps_hh
#define MuonPlottingOps_hh

#include "Operation.hh"
#include "PlottingBase.hh"
#include "EventData.hh"

namespace Operation {
  class MuonPlottingOps : public PlottingBase {
  public:

    MuonPlottingOps(const std::string & folderName);
    ~MuonPlottingOps();

    void BookHistos();
    void Start(Event::Data & ev);

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:    
    std::string mFolderName;
    TH1D * hGlbMuMultiplicity;
    TH1D * hGlbMuTrue;
    TH1D * hTrkMuTrue;
    TH1D * hGlbTrkMuTrue;
    TH1D * hMu1Pt1;
    TH1D * hMu2Pt1;
    TH1D * hMu2Pt2;
    TH1D * hMu2InvMass;
    TH1D * hpfMET1;
    TH1D * hMT1;
    TH1D * hpfMET2;
    TH1D * hMT2;
    
    TH1D * hBeamSpotX;
    TH1D * hBeamSpotY;
    TH1D * hVertexX;
    TH1D * hVertexY;
    TH1D * hNumVerticesPerEvent;
    TH1D * hNumPixelHits;
    TH1D * hNumMatches;

    // [ INNER Track ]
    TH1D * hInrTrkDxy_All;
    TH1D * hInrTrkDxyBS_All;
    TH1D * hInrTrkDxyErr_All;
    TH1D * hInrTrkDxyOvDxyErr_All;
    TH1D * hInrTrkNormChi2_All;
    TH1D * hInrTrkValidHits_All;

    // Correlation plots
    TH2D * hInrTrkDxyVsInrTrkNormChi2_All;
    TH2D * hInrTrkDxyVsInrTrkValidHits_All;
    TH2D * hInrTrkValidHitsVsInrTrkNormChi2_All;

    // [ GLOBAL Track ]
    TH1D * hGlbTrkDxy_All;
    TH1D * hGlbTrkDxyErr_All;
    TH1D * hGlbTrkDxyOvDxyErr_All;
    TH1D * hGlbTrkNormChi2_All;
    TH1D * hGlbTrkValidHits_All;

    TH1D * hCombIsolation;

    // Correlation plots
    TH2D * hGlbTrkDxyVsGlbTrkNormChi2_All;
    TH2D * hGlbTrkDxyVsGlbTrkValidHits_All;
    TH2D * hGlbTrkValidHitsVsGlbTrkNormChi2_All;
    TH2D * hInrTrkDxyVsInrTrkDxyBs_All;
  }; // ~MuonPlottingOps class
}

#endif
