/*! \file JadOps.hh
 * \brief Header file for Monte Carlo (truth) information-based operations.
 */
#ifndef JadOps_hh
#define JadOps_hh

#include "Operation.hh"
//#include "TH1F.h"
//#include "Compare.hh"

namespace Operation {
 
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
  }; // ~MCWMuonExists clas


  class MCMuonExtraFromW : public Operation::_Base {

  public:

    MCMuonExtraFromW();
    ~MCMuonExtraFromW(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
	;
  }; // ~MCMuonExtraFromW class

  class MCWPTCut : public Operation::_Base {

  public:

    MCWPTCut(float PtCut);
    ~MCWPTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mPtCut;
  }; // ~MCWPTCut class

  class MCVHTCut : public Operation::_Base {

  public:

    MCVHTCut(float VHTCut);
    ~MCVHTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mVHTCut;
  }; // ~MCVHTCut class

  class MCJetHTCut : public Operation::_Base {

  public:

    MCJetHTCut(float HTCut);
    ~MCJetHTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mHTCut;
  }; // ~MCJetHTCut class

  class MCMuonExists : public Operation::_Base {

  public:

    MCMuonExists(unsigned int numMuons);
    ~MCMuonExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mNumMuons;
  }; // ~MCMuonExists class

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

  class MCGenJetExists : public Operation::_Base {

  public:

    MCGenJetExists(unsigned int numGenJets);
    ~MCGenJetExists();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mGenJets;
  }; // ~MCGenJetExists class

  class RECOMuonExists : public Operation::_Base {

  public:

    RECOMuonExists(unsigned int numMuons);
    ~RECOMuonExists(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    unsigned int mNumMuons;
  }; // ~RECOMuonExists class

  class RECOCommonMHTCut : public Operation::_Base {

  public:

    RECOCommonMHTCut(float MHTCut);
    ~RECOCommonMHTCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMHTCut;
  }; // ~RECOCommonMHTCut class

  class RECOMuonJetDRCut : public Operation::_Base {

  public:

    RECOMuonJetDRCut(float MuonJetDRCut);
    ~RECOMuonJetDRCut(); 

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonJetDRCut;
  }; // ~RECOMuonJetDRCut class
  
} //~namespace Operation

#endif //~JadOps_hh
