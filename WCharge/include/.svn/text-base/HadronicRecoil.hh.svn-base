#ifndef HadronicRecoil_h
#define HadronicRecoil_h

#include "TH1D.h"
#include "TH2D.h"
#include "EventData.hh"
#include "Operation.hh"
#include "PlottingBase.hh"
#include "Utils.hh"

using namespace Event;



class HadronicRecoil : public PlottingBase {
public:
  // Standard Operation methods.
  HadronicRecoil(const std::string & filename,
		       Utils::ParameterSet &);
  ~HadronicRecoil(); //!< Destructor.
  
  void Start(Event::Data & ev); //!< Start processing
  bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.
  
  std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
  void BookHistos();
  bool passIsolation (double track, double ecal, double hcal, double eta, int ieff);
  bool passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff);
  bool fid(double eta);
  bool CheckCuts(double v_trk,double v_ecal,double v_hcal,double v_sihih,double v_dfi,double v_dhi,double v_hoe,double eta,int ieff);

private:
  std::string mFolderName;

  double pigreco;

  double elecET;
  
  int itr;
  int ipll;
  int ievt;
 

  bool chChk;
  bool corrEE;
  bool convChk;
  bool lepVeto;
  double lepPtVeto;
  int wp;
  int ieff;
  double mDCot;
  double mDist;
  int mMissingHits;
  double w;

  bool datatype;
  bool dataset;

  TH1D * hEleN;

  TH1D * hMass;
  TH1D * hPt  ;
  TH1D * hMCPt;
  TH1D * hMET ;
  TH1D * hMETTr;
  TH1D * hMETPl;
  TH1D * hMCMETTr;
  TH1D * hMCMETPll;


  TH1D * hMETx;
  TH1D * hMETy;

  TH2D * hMETvsPt  ;
  TH2D * hMETTrvsPt;
  TH2D * hMETPlvsPt;
  TH2D * hMCMETvsPt ;
  TH2D * hMCMETTrvsPt;
  TH2D * hMCMETPlvsPt;


  TH1D * angleGenReco;
  TH1D * angleGenMet ;
  TH1D * angleRecoMet;

}; //

#endif







