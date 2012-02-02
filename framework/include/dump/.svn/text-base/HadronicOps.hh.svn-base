/*! \file HadronicOps.hh
 * \brief Header file for the hadronic analysis-based operations.
 *
 */
#ifndef HadronicOps_hh
#define HadronicOps_hh

#include "Operation.hh"
#include "Math/VectorUtil.h"
#include "TH1F.h"

namespace Operation {

  class TriggerCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mTriggerBit
     */
     TriggerCut(Int_t mTriggerBit);

    ~TriggerCut(); //!< Destructor.

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
    Int_t mTriggerBit;           //Trigger to pass
     
  }; // ~TriggerCut class




  class HTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    HTCut(float mSumEtCutVal);

    ~HTCut(); //!< Destructor.

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
    float mSumEtCutVal;           //!< Sum Et Cut

  }; // ~SumETCut class

 
  class alpha_t_had : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] maltCutVal
     */
    alpha_t_had(float maltCutVal);

    ~alpha_t_had(); //!< Destructor.

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
    float maltCutVal;           //!< alpha_t Cut

  }; // ~alpha_t_had class

  class dphi_muon_commht : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] maltCutVal
     */
    dphi_muon_commht(float mdphicut_min, float mdphicut_max);

    ~dphi_muon_commht(); //!< Destructor.

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
    float mdphicut_min, mdphicut_max;           //!< dphi_muon_commht Cut

  }; // ~dphi_muon_commht class

  class ratio_muon_commht : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] maltCutVal
     */
    ratio_muon_commht(float mratio_mumht_cut);

    ~ratio_muon_commht(); //!< Destructor.

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
    float mratio_mumht_cut;           //!< ratio_muon_commht Cut

  }; // ~ratio_muon_commht class

} //~namespace Operation

#endif //~HadronicOps_hh
