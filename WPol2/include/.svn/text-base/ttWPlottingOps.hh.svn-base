
#ifndef ttWPlottingOps_hh
#define ttWPlottingOps_hh

#include "Operation.hh"
#include "PlottingBase.hh"

/*
This class provides plots with observables connected to W polarization and charge asymmetry,
which allow a good seperation betwenn W and tt. The IC plots can be used for templated fits
in order to seperate ttbar and W+jets
*/
namespace Operation {
class ttWPlottingOps : public PlottingBase {

 public:
  // Standard Operation methods.

  ttWPlottingOps(const std::string & foldername);
  ~ttWPlottingOps();
  void BookHistos();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream& Description(std::ostream& ostrm);

 private:

  std::string mFolderName;

  TH1D* MeffPlus;
  TH1D* MeffMinus;
  TH1D* Meffall;
  TH2D* MTLepHT;
  TH1D* MeffThMin;
  TH2D*   WPTLepHT;
  TH2D* LPscale;
  TH2D* LPRand;
  TH2D* EtaPhiP;
  TH2D* EtaPhiM;

  //TH1D* MeffMinus;
  //TH1D* Meffall;
  TH1D* MT;
  TH1D* MTP;
  TH1D* MTM;
  TH1D* MTC;
  TH1D* MTPC;
  TH1D* MTMC;
  TH1D* JetPT2nd;
  TH1D* Muphi;
  TH1D* MuPt;
  TH1D* MuEta;
  TH1D* MuDR;
  TH1D* MuBD0;
  TH1D* MuVD0;
  TH1D* MuVD0sig;
  TH1D* MuVDZ;
  TH1D* MuVDZsig;
  TH1D* MuVHits;
  TH1D* MuTrIso;
  TH1D* MuEIso;
  TH1D* MuHIso;
  TH1D* MuCso;
  TH1D* MuC2glob;
  TH1D* MuC2tr;
  TH1D* MuC2globP;
  TH1D* MuC2trP;
  TH1D* MuC2globM;
  TH1D* MuC2trM;
  TH1D* MuDRsecM;
  TH1D* MuDPTsecM;
  TH1D* MeffTHMax;
  TH2D* PFMETWPT;
  TH1D* MHTRes;
  TH1D* MHTResMeff;
  TH1D* WPtall;
  TH1D* PFMETDphi;
  TH1D* PFMETDpT;
  TH2D* PFMETDpTDphi;
 
  TH1D* PFMET;
  
  TH2D* PhiPtPt;
  TH1D* DilepMassP;
  TH1D* DilepMassO;
  TH1D* DilepMassN;
  TH1D* DilepMassPI;
  TH1D* DilepMassOI;
  TH1D* DilepMassNI;

  TH2D* MTLP;
  TH2D* MeffIC;
  TH2D* MeffMinusIC;
  TH2D* MeffPlusIC;

  TH2D* MTTrkIso;
  TH2D* LPWPT;
  TH2D* WPTMT;

  TH1D* MEta;
  TH1D* MEtaC;
  TH1D* MEtaMinus;
  TH1D* MEtaPlus;



  TH1D* PFMETM;
  TH1D* PFMETP;
  TH1D* MuphiM;
  TH1D* MuPtM;;
  TH1D* MuphiP;
  TH1D* MuPtP;

  TH1D* IC;
  TH1D* MinusIC;
  TH1D* PlusIC;
  std::vector<TH1D *> hg_ScaleP;
  std::vector<TH1D *> hg_ScaleM;
  std::vector<TH1D *> hg_WPTP;
  std::vector<TH1D *> hg_WPTM;



}; //~ttWPlottingOps class
}

#endif
