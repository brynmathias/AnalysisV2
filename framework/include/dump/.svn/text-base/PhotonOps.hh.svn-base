/*! \file PhotonicOps.hh
 * \brief Header file for photonic analysis-based operations.
 *
 */
#ifndef PhotonicOps_hh
#define PhotonicOps_hh

#include "Operation.hh"
#include "EventData.hh"
#include "Compare.hh"

#include <string>
#include <sstream>

namespace Operation {

  //=========================== 
  // General Photonic Data Cut  
  //===========================  
  /*!\brief Operation pro forma. Used for...
   * \date March 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class PhotDatCut : public Operation::_Base {  

  public: 

    /*! \brief Constructor.
     * @param option [in] Option to specify what to do with the cut.
     */
    PhotDatCut(const char * option); 

    ~PhotDatCut(); //!< Destructor

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
    std::string option_; //!< String representation of the option.

  }; // ~PhotDatCut class 
  ////////////////////////////////////////////////////////////////////

    /*! \brief "Number of good photons" cut.
     * \date February 2009
     * \author Tom Whyntie
     * \version 1.1
     *
     * Allows the user to accept/reject events on the basis of how
     * many good photons there are in the event.
     */
    class NumGdPhoCut : public Operation::_Base {

      public:
      NumGdPhoCut(const std::string & comparison, UInt_t number);
      ~NumGdPhoCut(); //!< Destructor.
      bool Process(Event::Data & ev);
      std::ostream& Description(std::ostream& ostrm);
      
    private:
      // Operation private data members
        //--------------------------------
      Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
      UInt_t number_;           //!< Number of photons of type to compare.

    }; // ~NumGdPhoCut class
    
    /*! \brief "Number of good jets (photonic analysis)" cut.
     * \date April 2009
     * \author Tom Whyntie
     * \version 1.0
     *
     * Allows the user to accept/reject events on the basis of how
     * many good jets (photonic analysis def.) there are in the event.
     */
    class NumGdPhoJetCut : public Operation::_Base {

      public:
      NumGdPhoJetCut(const std::string & comparison, UInt_t number);
      ~NumGdPhoJetCut(); //!< Destructor.
      bool Process(Event::Data & ev);
      std::ostream& Description(std::ostream& ostrm);
      
    private:
      // Operation private data members
      //--------------------------------
      Operation::_Compare<UInt_t> *mComparison; //!< Comparison
      UInt_t number_;           //!< Number of jets to compare.

    }; // ~NumGdPhoJetCut class

    /*! \brief Good photon HT cut
     * \date April 2009
     * \author Tom Whyntie
     * \version 1.0
     */
  class GoodPhoHTCut : public Operation::_Base {
    
  public:
    GoodPhoHTCut(const std::string & comparison, Double_t cut);
    ~GoodPhoHTCut(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison
    Double_t cut_;           //!< Cut value
    
  }; // ~GoodPhoHTCut class
  
  /*! \brief Good photon alpha_T cut
   * \date April 2009
   * \author Tom Whyntie
   * \version 1.0
   */
  class GoodPhoAlphaTCut : public Operation::_Base {
    
  public:
    GoodPhoAlphaTCut(const std::string & comparison, Double_t cut);
    ~GoodPhoAlphaTCut(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison
    Double_t cut_;           //!< Cut value
  }; // ~GoodPhoHTCut class
  
} //~namespace Operation

#endif //~PhotonicOps_hh
