/*! \file JadOps.hh
 * \brief Header file for Monte Carlo (truth) information-based operations.
 */
#ifndef JadOps_hh
#define JadOps_hh

#include "Operation.hh"
#include <stdexcept>
#include "EventData.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Functions.hh"

namespace Operation {

  class PrintDebugInfo : public Operation::_Base {

  public:

    PrintDebugInfo(const char * option);

    ~PrintDebugInfo(); //!< Destructor

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    const char * mType; //!< type of printing to do.

  }; // ~PrintDebugInfo class
 
  class MCWExists : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    MCWExists();
    ~MCWExists(); //!< Destructor.

    /*! \brief Cuts on
     *
     * \param Reference to the event data container.
     * \return True if
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
	;
  }; // ~MCWExists class

  class MCZExists : public Operation::_Base {

  public:
    MCZExists();
    ~MCZExists(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  private:
    ;
  }; // ~MCZExists class

  class MCWMuonExists : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    MCWMuonExists();
    ~MCWMuonExists(); //!< Destructor.

    /*! \brief Cuts on
     *
     * \param Reference to the event data container.
     * \return True if
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
	;
  }; // ~MCWMuonExists class


  class MCWLeptonExists : public Operation::_Base {

  public:
    MCWLeptonExists();
    ~MCWLeptonExists(); 
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);

  private:
    ;
  }; // ~MCWLeptonExists class


  class MCMuonExtraFromW : public Operation::_Base {

  public:

    MCMuonExtraFromW();
    ~MCMuonExtraFromW(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
	;
  }; // ~MCMuonExtraFromW class

  class MCqqbarW : public Operation::_Base {

  public:

    MCqqbarW();
    ~MCqqbarW(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

  }; // ~MCqqbarW class

  class MCWPTCut : public Operation::_Base {

  public:

    MCWPTCut(float PtCut);
    ~MCWPTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mPtCut;
  }; // ~MCWPTCut class

  class MCWPTCut2 : public Operation::_Base {

  public:

    MCWPTCut2(float PtCutMin, float PtCutMax);
    ~MCWPTCut2();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mPtCutMin;
    float mPtCutMax;
  }; // ~MCWPTCut2 class

  class MCWYCut : public Operation::_Base {

  public:

    MCWYCut(float YCutMin, float YCutMax);
    ~MCWYCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mYCutMin;
    float mYCutMax;
  }; // ~MCWYCut class

  class MCWYCut2 : public Operation::_Base {

  public:

    MCWYCut2(float YCutMin);
    ~MCWYCut2();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mYCutMin;
  }; // ~MCWYCut2 class

  class MCMuonAccCut : public Operation::_Base {

  public:

    MCMuonAccCut(float PtCut, float EtaCut);
    ~MCMuonAccCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mPtCut;
    float mEtaCut;
  }; // ~MCMuonAccCut class

/*
  class MCCOMBoostDir : public Operation::_Base {

  public:

    MCCOMBoostDir(bool postrue);
    ~MCCOMBoostDir(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    bool mPostrue;
  }; // ~MCCOMBoostDir class
*/
/*
  class MCSGEvent : public Operation::_Base {

  public:

    MCSGEvent();
    ~MCSGEvent(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    ;
  }; // ~MCSGEvent class
*/
  class MCVHTCut : public Operation::_Base {

  public:

    MCVHTCut(float VHTCut, float JetEtaCut);
    ~MCVHTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mVHTCut;
    float mJetEtaCut;
  }; // ~MCVHTCut class

  class MCJetHTCut : public Operation::_Base {

  public:

    MCJetHTCut(float HTCut, float JetEtaCut);
    ~MCJetHTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mHTCut;
    float mJetEtaCut;
  }; // ~MCJetHTCut class

  class MCLeptonExists : public Operation::_Base {

  public:

    MCLeptonExists(std::string flavour, unsigned int numLeptons);
    ~MCLeptonExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    std::string mFlavour;
    unsigned int mNumLeptons;
  }; // ~MCLeptonExists class

  class MCS1LeptonExists : public Operation::_Base {

  public:

    MCS1LeptonExists(std::string flavour);
    ~MCS1LeptonExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    std::string mFlavour;
  }; // ~MCS1LeptonExists class

  class MCRECOPFMETCut : public Operation::_Base {

  public:

    MCRECOPFMETCut(float PFMETCut);
    ~MCRECOPFMETCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mPFMETCut;
  }; // ~MCRECOPFMETCut class

  class MCRECOPFMETCut2 : public Operation::_Base {

  public:

    MCRECOPFMETCut2(float PFMETCutmin, float PFMETCutmax);
    ~MCRECOPFMETCut2(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mPFMETCutmin;
    float mPFMETCutmax;
  }; // ~MCRECOPFMETCut2 class

 class MCRECOZPFMETCut : public Operation::_Base {

  public:

    MCRECOZPFMETCut(float PFMETCut);
    ~MCRECOZPFMETCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mPFMETCut;
  }; // ~MCRECOZPFMETCut class


  class MCZtoLeptons : public Operation::_Base {

  public:

    MCZtoLeptons(std::string flavour);
    ~MCZtoLeptons(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    std::string mFlavour;
  }; // ~MCZtoLeptons class

  class MCMuonExtraExists : public Operation::_Base {

  public:

    MCMuonExtraExists(unsigned int numMuons);
    ~MCMuonExtraExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mNumMuons;
  }; // ~MCMuonExtraExists class

  class MCElectronExists : public Operation::_Base {

  public:

    MCElectronExists(unsigned int numElectrons);
    ~MCElectronExists();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mNumElectrons;
  }; // ~MCElectronExists class

  class MCPhotonExists : public Operation::_Base {

  public:

    MCPhotonExists(unsigned int numPhotons);
    ~MCPhotonExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mNumPhotons;
  }; // ~MCPhotonExists class

  class MCGTGenJetExists : public Operation::_Base {

  public:

    MCGTGenJetExists(unsigned int numGenJets, float JetEtaCut);
    ~MCGTGenJetExists();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mGenJets;
    float mJetEtaCut;
  }; // ~MCGTGenJetExists class

  class MCLTGenJetExists : public Operation::_Base {

  public:

    MCLTGenJetExists(unsigned int numGenJets, float JetEtaCut);
    ~MCLTGenJetExists();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mGenJets;
    float mJetEtaCut;
  }; // ~MCLTGenJetExists class

  class TRIGGERCut : public Operation::_Base {

  public:

    TRIGGERCut(const std::string & triggerName1, const std::string & triggerName2);
    ~TRIGGERCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    std::string mTriggerName1;
    std::string mTriggerName2;
  }; // ~TRIGGERCut class

  class ORTRIGGERCut : public Operation::_Base {

  public:

    ORTRIGGERCut(const std::string & triggerName1, const std::string & triggerName2);
    ~ORTRIGGERCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    std::string mTriggerName1;
    std::string mTriggerName2;
  }; // ~ORTRIGGERCut class

  class RECOMuonExists : public Operation::_Base {

  public:

    RECOMuonExists(unsigned int numMuons);
    ~RECOMuonExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mNumMuons;
  }; // ~RECOMuonExists class

  class RECOMuMuPtCut : public Operation::_Base {

  public:

    RECOMuMuPtCut(float ZPtCut);
    ~RECOMuMuPtCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mZPtCut;
  }; // ~RECOMuMuPtCut class

  class RECOMuMuPtCut2 : public Operation::_Base {

  public:

    RECOMuMuPtCut2(float ZPtCutmin, float ZPtCutmax);
    ~RECOMuMuPtCut2(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mZPtCutmin;
    float mZPtCutmax;
  }; // ~RECOMuMuPtCut2 class

  class RECOCommonMHTCut : public Operation::_Base {

  public:

    RECOCommonMHTCut(float MHTCut);
    ~RECOCommonMHTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMHTCut;
  }; // ~RECOCommonMHTCut class

  class RECOCommonMHTCut2 : public Operation::_Base {

  public:

    RECOCommonMHTCut2(float MHTCut_lowlim, float MHTCut_uplim);
    ~RECOCommonMHTCut2(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mMHTCutlow;
    float mMHTCutup;
  }; // ~RECOCommonMHTCut class

  class RECOPFMETCut : public Operation::_Base {

  public:

    RECOPFMETCut(float PFMETCut);
    ~RECOPFMETCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mPFMETCut;
  }; // ~RECOPFMETCut class

  class RECOPFMETCut2 : public Operation::_Base {

  public:

    RECOPFMETCut2(float PFMETCutmin, float PFMETCutmax);
    ~RECOPFMETCut2(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    float mPFMETCutmin;
    float mPFMETCutmax;
  }; // ~RECOPFMETCut2 class

  class RECOMuonJetDRCut : public Operation::_Base {

  public:

    RECOMuonJetDRCut(float MuonJetDRCut);
    ~RECOMuonJetDRCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonJetDRCut;
  }; // ~RECOMuonJetDRCut class

  class RECOMuonPT : public Operation::_Base {

  public:

    RECOMuonPT(float MuonPt);
    ~RECOMuonPT();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonPtCut;
  }; // ~RECOMuonPtCut class

 class RECO1of2MuonsOverPT : public Operation::_Base {

  public:

    RECO1of2MuonsOverPT(float MuonPt);
    ~RECO1of2MuonsOverPT();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonPtCut;
  }; // ~RECO1of2MuonsOverPT class

  class RECOSecondGMCut : public Operation::_Base {
    
  public:
    
    RECOSecondGMCut(float MuonPt);
    ~RECOSecondGMCut();
    
    bool Process(Event::Data & ev);
    
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    float mMuonPtCut;
  }; // ~RECOSecondGMCut class
  
  class RECOMuonISO : public Operation::_Base {

  public:

    RECOMuonISO(float MuonPt);
    ~RECOMuonISO();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonCombIsoCut;
  }; // ~RECOMuonIsoCut class

  class RECO2ndMuonMass : public Operation::_Base {

  public:

    RECO2ndMuonMass(float MuonPt, float Mass, bool keepZ, std::string charge);
    ~RECO2ndMuonMass();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonPt;
    float mMass;
    bool mKeepZ;
    std::string mCharge;

  }; // ~RECO2ndMuonMassCut class

class MCMuMuInvMass : public Operation::_Base {

public:

MCMuMuInvMass(float Min, float Max);
~MCMuMuInvMass();

 bool Process(Event::Data & ev);

std::ostream& Description(std::ostream& ostrm);

private:

float mMin;
float mMax;

};


  class RECOpfMTCut : public Operation::_Base {

  public:

    RECOpfMTCut(float cut);
    ~RECOpfMTCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mCut;

  }; // ~RECOpfMTCut class
  
} //~namespace Operation

#endif //~JadOps_hh
