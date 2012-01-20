/*! \file MCOps.hh
 * \brief Header file for Monte Carlo (truth) information-based operations.
 */
#ifndef MCOps_hh
#define MCOps_hh

#include "Operation.hh"
#include "TH1F.h"
#include "Compare.hh"

namespace Operation {

  //===================================
  // Print Gen Particle Info Operation
  //===================================
  /*!\brief Operation for printing the GenParticle information
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class PrintGenParticleInfo : public Operation::_Base {

  public:

    /*! \brief
     * @param option [in] Print option: NONE, FULL, CHAIN, ENDCHAIN.
     */
    PrintGenParticleInfo(const char * option);

    ~PrintGenParticleInfo(); //!< Destructor

    /*! \brief Processes the event data based on the supplied parameters.
     * @param ev Reference to the event data container class.
     * @return True if the event passes the operation.
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
    const char * mType; //!< type of printing to do.

  }; // ~PrintGenParticleInfo class

// WARNING: These have been excluded temporarily!!!!
#if 0
  /*!\brief  Cut based on the Gen Particles present in the sample
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class GenPartContentCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     * @param [in] pdgid PDG ID of the particle to be looked for.
     * @param [in] comparison String of the comparison to be used.
     * @param [in] number The number of particles of PDG ID to be compared with.
     * @param [in] anti Consider antiparticles (i.e. abs(PDGID)) for subject particle.
     * @param [in] mother_id The ID required of the mother particle
     * @param [in] mother_anti Consider anti-mother particles.
     */
    GenPartContentCut(Int_t pdgid,
		      const std::string & comparison,
		      UInt_t number,
                      Bool_t anti = false,
		      Int_t mother = 0,
		      Bool_t mother_anti = false);

    ~GenPartContentCut(); //!< Destructor

    /*! \brief Description of the process the operation applies.
     * @param ev Reference to the event data container class.
     * @return True if the event passes the operation.
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
    Int_t pdgId_; //!< PDG ID of the particles to be looked for.
    Operation::_Compare<UInt_t> *mComparison; //!< Comparision operator to be made.
    UInt_t number_; //!< Number of particles for comparison.
    Bool_t anti_; //!< Consider antiparticles too?
    Int_t mother_; //!< The required PDG ID of the mother particle (0 => no mother ID required).
    Bool_t mother_anti_; //!< Consider anti-mother particles too?

  }; // ~GenPartContentCut class


  class LeptonFilter : public Operation::_Base {

  public:

    LeptonFilter(UInt_t type);

    ~LeptonFilter(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    UInt_t mType;

  }; // ~LeptonFilter class



  class NumMCAllLeptons : public Operation::_Base {

  public:

    NumMCAllLeptons(const std::string & comparison,
		    UInt_t number,
		    UInt_t type);

    ~NumMCAllLeptons(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison
    UInt_t mNumber;           //!< Number of common leptons with which to compare.
    UInt_t mType;

  }; // ~ class



  class NumMCLeptons : public Operation::_Base {

  public:

    NumMCLeptons(const std::string & comparison,
		 UInt_t number,
		 UInt_t type);

    ~NumMCLeptons(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
    UInt_t mNumber;           //!< Number of common leptons with which to compare.
    UInt_t mType;

  }; // ~NumMCLeptons class

  //==========================
  // Parton mulitplicity cut
  //===========================

  class NumMCAllPartons : public Operation::_Base {

  public:

    NumMCAllPartons(const std::string & comparison,
		    UInt_t number);

    ~NumMCAllPartons(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
    UInt_t mNumber;           //!< Number of common leptons with which to compare.
  }; // ~NumMCAllPartons class

  class NumMCPartons : public Operation::_Base {
  public:
    NumMCPartons(const std::string & comparison,
		 UInt_t number);

    ~NumMCPartons(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
    UInt_t mNumber;           //!< Number of common leptons with which to compare.
    UInt_t mType;
  }; // ~NumMCPartons class

  class MCMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    MCMETCut(float mMETvalue);

    ~MCMETCut(); //!< Destructor.

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
    float mMETvalue;
  }; // ~MCMETCut class


  class MCMHTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    MCMHTCut(float mMHTvalue);

    ~MCMHTCut(); //!< Destructor.

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
    float mMHTvalue;

  }; // ~MCMHTCut class

  class MCHTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    MCHTCut(float mHTvalue);

    ~MCHTCut(); //!< Destructor.

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
    float mHTvalue;

  }; // ~MCHTCut class

  class MCWtoMuCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    MCWtoMuCut();
    ~MCWtoMuCut(); //!< Destructor.

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
  }; // ~MCWtoMuCut class
  #endif
} //~namespace Operation

#endif //~MCOps_hh
