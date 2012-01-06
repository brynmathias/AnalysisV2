#ifndef EWKbkgClassesPlotOps_hh
#define EWKbkgClassesPlotOps_hh
#include "PlottingBase.hh"

namespace Operation {
  
  class PlotPhotons : public PlottingBase {
    
  public:
    // Standard Operation methods.
    PlotPhotons(const std::string & foldername);
    ~PlotPhotons();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
      std::string mFolderName;
      TH1D * PhotonEta;
      TH1D * PhotonPt;
      TH1D * PhotonDR;


      TH1D * PhotonEtaOther;
      TH1D * PhotonPtOther;
      TH1D * PhotonDROther;

      TH1D * PhotonEtaMeson;
      TH1D * PhotonPtMeson;
      TH1D * PhotonDRMeson;

      TH1D * PhotonEtaPrompt;
      TH1D * PhotonPtPrompt;
      TH1D * PhotonDRPrompt;


      TH1D * PhotonEtaQuark;
      TH1D * PhotonPtQuark;
      TH1D * PhotonDRQuark;

      TH1D * PhotonTrIso;
      TH1D * PhotonHIso;
      TH1D * PhotonEIso;
      TH1D * PhotonCIso;
      TH1D * PhotonC4TrIso;
      TH1D * PhotonC4HIso;
      TH1D * PhotonC4EIso;
      TH1D * PhotonC4CIso;
      TH1D * PhotonEM;
      TH1D * PhotonSieta;
      TH1D * PhotonR9;
   
   };


  
  class GenVBosons : public PlottingBase {
    
  public:
    // Standard Operation methods.
    GenVBosons(const std::string & foldername, float VBosonPT);
    ~GenVBosons();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName;
    float mVBosonPT;    

    std::vector<TH1D *> VBPT;
    std::vector<TH1D *> VBET;
    std::vector<TH1D *> VBPTHT;
    //  std::vector<TH1D *> VBETHT;
    std::vector<TH1D *> VBETAT;
    std::vector<TH1D *> VBHT;
    std::vector<TH1D *> VBY;
    std::vector<TH1D *> VBDR;
  
    TH1D * VBjet1;
    TH1D * VBjet2;
    TH1D * VBjet3;
    TH1D * VBjet4;
    TH1D * VBNjet;
    TH1D * RVBjet1;

    TH1D * VBjet4Eta;
    TH1D * VBjet1Eta;
    TH1D * VBjet2Eta;
    TH1D * VBjet3Eta;
    TH1D * VBjet1DR2;
    TH1D * VBjet1DPhi2;
     std::vector<TH1D *>  VBHTAT;
    // TH1D * RVBjet2;
    // TH1D * RVBjet3;
    // TH1D * RVBjet4;
    // TH1D * RVBNjet;

  };

  


  class EWKbkgClassesPlotOps : public PlottingBase {
    
  public:
    // Standard Operation methods.
    EWKbkgClassesPlotOps(const std::string & foldername);
    ~EWKbkgClassesPlotOps();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName;

    std::vector<TH1D *> NLeptons;
    std::vector<TH1D *> NLeptonsMHad;
    std::vector<TH1D *> NTau;
    std::vector<TH1D *> NMuon;
    std::vector<TH1D *> NEli;
    std::vector<TH1D *> NKind;
    std::vector<TH1D *> TransVHT;
    std::vector<TH1D *> TransV;
    //  std::vector<TH2D *> NTau_Map;
    std::vector<TH2D *> NEliAc;
    std::vector<TH2D *> NMuonAc;
    std::vector<TH2D *> MeffZeff;
    std::vector<TH2D *> HTeta;
  
  }; //~RECOPolPlots class


  class EWK_Classes : public PlottingBase {
    
  public:
    // Standard Operation methods.
    EWK_Classes(const std::string & foldername);
    ~EWK_Classes();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName;
    std::vector<TH1D *> NLeptons;
  }; //~RECOPolPlots class

}



#endif
