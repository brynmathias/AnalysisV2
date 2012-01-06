/*! \file LeptonicOps.hh
 * \brief Header file for leptonic analysis-based operations.
 *
 */
#ifndef LeptonicOps_hh
#define LeptonicOps_hh

#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh"
#include "Compare.hh"

using namespace Event;

namespace Operation {

  ////////////////////////////////////////////////////////////////////

  /*! \brief "Number of good leptons" cut.
   * \date February 2009
   * \author Tom Whyntie
   * \version 1.1
   *
   * Allows the user to accept/reject events on the basis of how
   * many good leptons (of a specified type) there are in the event.
   */
  class NumGdLepCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     * @param [in] type Type of lepton (0=>all, 1=>electron, 2=>muon)
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of leptons to compare.
     */
    NumGdLepCut(Int_t type, const std::string & comparison, UInt_t number);
    NumGdLepCut();

    ~NumGdLepCut(); //!< Destructor.

    /*! \brief 
     * @param [in] ev Reference to the event data container.
     * @return True if the number of good leptons of the specified type in the event matches the condition.
     */
    bool Process(Event::Data & ev);

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     * @param [in] ostrm Reference to output stream (for output).
     * @return A reference to an output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

    // Set / get functions
    void SetType(Int_t type);
    Int_t GetType() const;

    void SetComparison(const std::string & comparison);
    std::string GetComparison() const;

    void SetNumber(UInt_t number);
    UInt_t GetNumber() const;
    
  private:
    // Operation private data members
    //--------------------------------
    Int_t mType;              //!< Type of lepton to cut on: 0=> any, 1=>electrons, 2=>muons.
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc
    UInt_t mNumber;           //!< Number of leptons of type to compare.

  }; // ~NumGdLepCut class

  class MTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mHTvalue
     */
    MTCut(float mHTvalue );

    ~MTCut(); //!< Destructor.

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
    float mHTvalue;           //!<

  }; // ~MTCut class




} //~namespace Operation

#endif //~LeptonicOps_hh
