#ifndef LeptonicOps_hh
#define LeptonicOps_hh
#include "Operation.hh"
#include "EventData.hh"
#include "Compare.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "PlottingBase.hh"
#include "Compare.hh"
#include "Utils.hh"
#include "Types.hh"
#include "ICF_NtupleData.hh"
#include "NtupleData.hh"


using namespace Event;

namespace Operation {



 class DphiPTW_muCut : public Operation::_Base {

  public:

   DphiPTW_muCut(float Dphi);
    ~DphiPTW_muCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

   float mDphiPTW_mu;
  };





 class PTlepCut : public Operation::_Base {

  public:

   PTlepCut(float SumPTlep,float SumPTlepUP);
    ~PTlepCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

   float mPTlep;
   float mPTlepUP;
  };


 class PTmuCut : public Operation::_Base {

  public:

   PTmuCut(float SumPTMu);
    ~PTmuCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
   float mPTmu;
 
  };

 class PTZCut : public Operation::_Base {

  public:

   PTZCut(float SumPTMu);
    ~PTZCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
   float mPTmu;
 
  };

 class SumPTlepCut : public Operation::_Base {

  public:

   SumPTlepCut(float SumPTlep,float SumPTlepUP);
    ~SumPTlepCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

   float mSumPTlep;
   float mSumPTlepUP;
  };




 class MuonCheck : public Operation::_Base {

  public:

   MuonCheck();
    ~MuonCheck() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

  };



 class PFMETCutBin : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
   PFMETCutBin(float mMETvalue,float METvalueUP );

    ~PFMETCutBin(); //!< Destructor.

    /*! \brief
     *
     * \param Reference to the event data container.
     * \return True if the
     */
   bool Process(Event::Data & ev);

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mMETvalue;           //!<
   float mMETvalueUP;
  }; // ~caloMETCut class



class HTPTCut : public Operation::_Base {

  public:

  HTPTCut(float mHTPTCutVal,float mHTPTCutValUp=-1 );
    ~HTPTCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    float mHTPTCutVal;
    float mHTPTCutValUp;
  };


class HTthrustCut : public Operation::_Base {

  public:

  HTthrustCut(float mHTthrustCutVal,float mHTthrustCutValUp=-1 );
    ~HTthrustCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    float mHTthrustCutVal;
    float mHTthrustCutValUp;
  };



  class HTlepCut : public Operation::_Base {

  public:

    HTlepCut(float mHTlepCutVal);
    ~HTlepCut() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    float mHTlepCutVal;

  };

  class MuJetVeto : public Operation::_Base {

  public:

    MuJetVeto(float mMuJetVetoVal);
    ~MuJetVeto() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuJetVetoVal;

  };

  class UpperMuPtCut : public Operation::_Base {
  public:
    UpperMuPtCut( float );
    ~UpperMuPtCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };


 class UpperElePtCut : public Operation::_Base {
  public:
    UpperElePtCut( float );
    ~UpperElePtCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };

 class PFLPCut : public Operation::_Base {

  public:

    PFLPCut(float mMHTvalue );

    ~PFLPCut(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mLPvalue;           //!<

  }; // ~caloMETCut class


 class PFMeffWCut : public Operation::_Base {

  public:

    PFMeffWCut(const std::string & comparison,float mMHTvalue );

    ~PFMeffWCut(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mMeffVal;           //!<
   bool mcomparison;
  }; //  class


 class PFMHTCut : public Operation::_Base {

  public:

    PFMHTCut(float mMHTvalue );

    ~PFMHTCut(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mMHTvalue;           //!<

  }; // ~caloMETCut class


  class mPFMHTCut : public Operation::_Base {

  public:

    mPFMHTCut(float mMHTvalue );

    ~mPFMHTCut(); //!< Destructor.                                                                                                                                                         
    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members                                                                                                                                                     
    //--------------------------------                                                                                                                                                    
    float mMHTvalue;           //!<                                                                                                                                                      

  }; // ~caloMETCut class                                                                                                                                                                 



  class UnCorLeadCut : public Operation::_Base {
  public:
    UnCorLeadCut( float );
    ~UnCorLeadCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };

  class LeptonicAlphaTCut : public Operation::_Base {

  public:

    LeptonicAlphaTCut(float AlphaTCut);
    ~LeptonicAlphaTCut();

    bool Process(Event::Data & ev);

   std::ostream& Description(std::ostream& ostrm);

  private:

    float mAlphaTCut;
  }; // ~LeptonicAlphaTCut class

  // cut on number of promt leptons on Genlevel
  class GenNumberLepCut : public Operation::_Base {

  public:

    GenNumberLepCut(int NoLep);
    ~GenNumberLepCut();

    bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);

  private:

    float mNoLep;
  }; // 


  class PrintAlphaTEvents: public Operation::_Base {
  public:

    PrintAlphaTEvents();
    ~PrintAlphaTEvents();
    bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
  };



  inline bool isLooseElectron(const Event::Lepton* el) {
    
  // if barrel Electron
  if ( fabs(el->Eta()) <1.442 ) {

    double relCombIso = 999.;
    relCombIso = ( (el->GetTrkIsolation())
                   + max(0., el->GetEcalIsolation()-1.)
                   + el->GetHcalIsolation())/ el->Pt();

    if ( el->Pt()>15  && relCombIso < 0.2 ) {

      return true;
    }
  }

  // endcap loose electrons
  if ( fabs(el->Eta()) > 1.560 && fabs(el->Eta())<2.5 ) {
        double relCombIso = 999.;
        relCombIso = (el->GetTrkIsolation()
                      + el->GetEcalIsolation()
                      + el->GetHcalIsolation())/ el->Pt();

        if ( el->Pt()>15 && relCombIso < 0.2 ) {

          return true;
        }
      }
  return false;
} // ~end of isLooseElectron

  class NumOfLooseElectrons : public Operation::_Base {
  public:

    NumOfLooseElectrons(const std::string & comparison, int numOfLooseEls);
    ~NumOfLooseElectrons();

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    int mNumOfLooseEls;
  };




  class NumOfLooseMuons : public Operation::_Base {
  public:

    NumOfLooseMuons(const std::string & comparison, int numOfLooseMus);
    ~NumOfLooseMuons();

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    int mNumOfLooseMus;

  };

 class NumOfLooseMuonsRA4 : public Operation::_Base {
  public:

    NumOfLooseMuonsRA4(const std::string & comparison, int numOfLooseMus);
    ~NumOfLooseMuonsRA4();

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    int mNumOfLooseMus;

  };


  class NumOfLooseElectronsRA4 : public Operation::_Base {
  public:

    NumOfLooseElectronsRA4(const std::string & comparison, int numOfLooseEls,
			const Utils::ParameterSet & ps, const std::string & prefix = "Cuts");
    ~NumOfLooseElectronsRA4();

    void Start(Event::Data & ev);

    //Based on Paolo Meridiani's corrections
    float dPhiCorr(double elePhi , double eleEta);
    float dEtaCorr(double elePhi , double eleEta);

    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    int mNumOfLooseEls;

    bool mIso;
    bool mHoE;
    bool mDeltaEta, mDeltaPhi;
    bool mShh;
    bool mConv;
    double mPtMin;
    double mD0BS;
    //      bool mConvExtra;
    double mRelCombIsoBarrel, mRelCombIsoEndcap;
    double mTrkIsoBarrel, mTrkIsoEndcap;
    double mEcalIsoBarrel, mEcalIsoEndcap;
    double mHcalIsoBarrel, mHcalIsoEndcap;
    double mHoEBarrel, mHoEEndcap;
    double mDeltaPhiBarrel, mDeltaPhiEndcap;
    double mDeltaEtaBarrel, mDeltaEtaEndcap;
    double mSigmaIEtaIEtaBarrel, mSigmaIEtaIEtaEndcap;
    double mDCot, mDist;
    int mMissingHits;
    bool mSupressErrors;
    bool mCorrEEMisalig;


  }; // ~end of class NumOfLooseElectronsRA4


 class GridPointSelect: public Operation::_Base {

  public:
    
    GridPointSelect(float SumPTlep,float SumPTlepUP);
    ~GridPointSelect() {;}
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:

   float M0_;
   float M12_;
  };



  class PrintRunLSEvent: public Operation::_Base {
  public:

    PrintRunLSEvent();
    ~PrintRunLSEvent();
    bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
  };





} // end namespace

#endif
