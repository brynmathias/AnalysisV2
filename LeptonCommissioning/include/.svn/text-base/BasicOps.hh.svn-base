#ifndef BasicOps_hh
#define BasicOps_hh

#include "BasicFilters.hh"
#include "PlottingBase.hh"
#include "TTree.h"

using namespace Event;

namespace LeptonCommissioning{

  class LMPlots : public PlottingBase {


  public:
    LMPlots(const std::string & foldername);
    ~LMPlots();\
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  private:
    std::string mFolderName;
    TH1D * ele_pt;
    TH1D * JetMulti;
    TH1D * jet_pt;
    TH1D * jet_Et;

  };


class makeElectronTree : public PlottingBase{
public:
makeElectronTree(const std::string & dir,
             const Utils::ParameterSet & ps):
      mFolderName(dir)
  {}

  ~makeElectronTree(){}

  
  void BookHistos();
  bool Process(Event::Data &ev);
  double getCorrD0(double d0, double phi, double X, double Y );
  void Start(Event::Data &ev){
    initDir(ev.OutputFile(),mFolderName.c_str());
    BookHistos();
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Electron basic tree : " << mFolderName;
    return ostrm;
  }
 private:

  int mNumObjMax;//=10;
  int mNumObjMin;//=1;

  const static int jetArrayLength = 5;

  TTree *tree;

  double wgt;
  bool trig_Jet80;
  bool trig_Jet50;
  bool trig_Jet30;
  double et_j1_uncor;
  int njet_emf_pass;
  double combIso, caloIso;
  int nJet, nEle;
  int gPar;
  double ht, mht, pfMet;
  double alphaT;
  double alphaT_lep;
  double alphaT_had;
  double et_e, pt_e, eta_e;
  double et_j1, eta_j1;
  double eop;
  double closestJetEt, closestJetDR, closestComJetDR;
  int lepType;
  double dcot, dist;
  int mHits;
  bool hitFP;
  double hoe, deta, dphi, sigmaietaieta;
  double CF_j1;
  double CF_corj1;
  double CF_c;
  double et_c_uncor;
  double et_comc_uncor, CF_comc, com_closestJetEt, com_closestJetDR;
  double et_uk_uncor, CF_uk, uk_closestJetEt, uk_closestJetDR;
  const std::string mFolderName;
  double ComMeff, SumMeff;

};
}

#endif
