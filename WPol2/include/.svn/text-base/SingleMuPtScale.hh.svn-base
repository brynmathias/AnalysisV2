#ifndef SingleMuPtScale_hh
#define SingleMuPtScale_hh

#include "Operation.hh"
#include "PlottingBase.hh"
#include "EventData.hh"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "Structures.hh"
#include "Functions.hh"
#include "PolTransforms.hh"

namespace Operation {
  class SingleMuPtScale : public PlottingBase {
  public:

    SingleMuPtScale(const std::string & folderName);
    ~SingleMuPtScale();

    void BookHistos();
    void Start(Event::Data & ev);

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:    
    std::string mFolderName;
    std::string mVBoson;


    TTree * plusmuonstree;
    TTree * minusmuonstree;
    Double_t MCPt;
    Double_t MCEta;
    Double_t MCPhi;
    Double_t RecoPt;
    Double_t RecoEta;
    Double_t RecoPhi;
    Double_t EvWeight;

  }; // ~SingleMuPtScale class
}

#endif
