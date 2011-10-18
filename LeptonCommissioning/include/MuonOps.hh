#ifndef MuonOps_hh
#define MuonOps_hh

#include "BasicOps.hh"
#include "PlottingBase.hh"
#include "Compare.hh"
#include "TTree.h"
#include "Operation.hh"

using namespace Event;

namespace LeptonCommissioning{


  class myMuonPlots : public PlottingBase{
  public:
    myMuonPlots(const std::string & dir,
		const Utils::ParameterSet & ps):
      mFolderName(dir)
    {}

    ~myMuonPlots(){}
    
  
    void BookHistos();
    bool Process(Event::Data &ev);
    double getCorrD0(double d0, double phi, double X, double Y );
    void Start(Event::Data &ev){
      initDir(ev.OutputFile(),mFolderName.c_str());
      BookHistos();
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Muon basic tree : " << mFolderName;
      return ostrm;
    }
  private:
    
    int mNumObjMax;//=10;
    int mNumObjMin;//=1;
    
    const static int jetArrayLength = 9;
    
    TTree *tree;

    double wgt;
    float trkIso, caloIso, combIso, relTrkIso, relCaloIso, relCombIso;
    int nJet, nMu, nEl;
    int gPar;
    int chrg;
    float ht, mht, recoilMet, caloMet, pfMet;
    float alphaT, alphaT_Had, lp;
    float et_mu, pt_mu, eta_mu, inrTrkD0, inrTrkD0Err;
    float etJet[30], etaJet[30];
    float closestPreJetEt, closestPreJetDR, closestComJetEt, closestComJetDR;
    int lepType;
    float mt_MuRecoilMet, mt_MuCaloMet, mt_MuPfMet;
    float mt2_MuRecoilMet, mt2_MuCaloMet, mt2_MuPfMet;
    float PFLP;
    float biasedDPhi;
    float mEff;
    //    int hlt30U, hlt50U, washlt30UPreScaled;
    int washlt30UPreScaled, washlt50UPreScaled;
 
    const std::string mFolderName;

  }; // ~end of class myMuonPlots


  class NumOfGdMuons : public Operation::_Base {

  public:

    NumOfGdMuons(const std::string & comparison, UInt_t number,float pt, float eta);
    ~NumOfGdMuons();

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    UInt_t mNumber;
    float mPt;
    float mEta;

  };


} // ~ end of namespace LeptonCommissioning

#endif
