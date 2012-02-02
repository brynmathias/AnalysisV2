#ifndef hadronic_include_ControlPlottingOps_hh
#define hadronic_include_ControlPlottingOps_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class ControlPlottingOps : public PlottingBase {

  public:

    ControlPlottingOps(const Utils::ParameterSet&);
    ~ControlPlottingOps();
    void BookHistos();
    void Start( Event::Data & ev );
    bool Process( Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName_;
    std::string dirName_;
    TH1D* hMT;
    TH1D* hMHT;
    TH1D* hMeff;
    TH1D* hAlphaT_Lep;
    TH1D* hAlphaT_Had;
    TH1D* hLepPt;
    TH1D* hLepEta;
    TH1D* hLepDR; 
    TH1D* hHT;
    TH1D* hHTlep;
    TH1D* hNJet;
    TH1D* hCaloMET;
    TH1D* hLepTrIso; 
    TH1D* hLepCIso; 
    TH1D* hLepEIso; 
    TH1D* hLepHIso; 
    TH1D* hMugVHits; 
    TH1D* hMuiVHits; 
    TH1D* hMuC2glob; 
    TH1D* hMuC2tr; 
    TH1D* hMuBD0; 
    TH1D* hMuVD0; 
    TH1D* hMuVD0sig; 
    TH1D* hMuVDZ; 
    TH2D* hMTTrkIso;
    TH2D* hHTminDR;
    TH2D* hMuPtHT;
    TH1D* hLepPhi;
    TH1D* hNVertices;
    TH1D* hNTotVertices;
  };

 class VertexOp : public PlottingBase {

  public:

    VertexOp(const std::string & folderName);
    ~VertexOp();
    void BookHistos();
    void Start( Event::Data & ev );
    bool Process( Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName;
   

    TH1D* hNVertices;
   TH1D* h_recon_NVertices;
  };
}
#endif
    
