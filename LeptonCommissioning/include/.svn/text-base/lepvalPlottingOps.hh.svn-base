#ifndef lepvalPlottingOps_hh
#define lepvalPlottingOps_hh

#include "Operation.hh"
#include "EventData.hh"
#include "NtupleData.hh"
#include "PlottingBase.hh"

#include "TH1D.h"
#include "TH2D.h"

namespace lepval{

  class LepValPlots : public PlottingBase {

  public:

    LepValPlots(const std::string& foldername, bool JPsiStudy, bool GenOn, bool TextOut, std::string Outfile);
    ~LepValPlots();
    void BookHistos();
    void Start(Event::Data& ev);
    bool Process(Event::Data& ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFoldername, mOutfile;
    bool mJPsiStudy, mGenOn, mTextOut;

    //the output histograms

    TH1D *LeptonIDs, *mumultip,*numevents, *JPsiInvMassPlot, *LepIsoPt5_10, *LepIsoPt10_15, *LepIsoGenMatchPt5_10, *LepIsoGenMatchPt10_15, *HT, *LeadMuonSpect, *LeadElecSpect, *HT_allObjects, *MuonPtSpect, *ElecPtSpect;

    //output txt file of JPsi candidates
    std::string Outfile;
  
  };
}
#endif
