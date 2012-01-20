/*! \file CommonOps.hh
 * \brief Header file for operations on common physics objects.
 */
#ifndef CommonOps_hh
#define CommonOps_hh

#include "Operation.hh"
#include "EventData.hh"
#include "Compare.hh"
#include <set>
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"
#include "boost/tuple/tuple_io.hpp"

namespace Operation {

  /*! \brief A cut based on the number of common leptons.
   *
   * \date February 2009
   * \author CMS SUSY ntuple analysis team.
   * \version 1.1
   *
   * Longer description of the operation.
   */
  class NumComLeptons : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of common leptons with which to compare.
     */
    NumComLeptons(const std::string & comparison, UInt_t number);

    ~NumComLeptons(); //!< Destructor.

    /*! \brief Cuts on the number of common leptons of a specified type.
     *
     * \param Reference to the event data container.
     * \return True if the number of common leptons in the event matches the condition.
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
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
    UInt_t mNumber;           //!< Number of common leptons with which to compare.

  }; // ~NumComLeptons class

 class NumComElectrons : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of common leptons with which to compare.
     */
   NumComElectrons(const std::string & comparison, UInt_t number);

    ~NumComElectrons(); //!< Destructor.

    /*! \brief Cuts on the number of common leptons of a specified type.
     *
     * \param Reference to the event data container.
     * \return True if the number of common leptons in the event matches the condition.
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
   Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
   UInt_t mNumber;           //!< Number of common leptons with which to compare.

 }; // ~NumComElectrons class

 class NumComTaus : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of common leptons with which to compare.
     */
   NumComTaus(const std::string & comparison, UInt_t number);

    ~NumComTaus(); //!< Destructor.

    /*! \brief Cuts on the number of common leptons of a specified type.
     *
     * \param Reference to the event data container.
     * \return True if the number of common leptons in the event matches the condition.
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
   Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
   UInt_t mNumber;           //!< Number of common leptons with which to compare.

 }; // ~NumComTaus class

 class NumComMuons : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of common leptons with which to compare.
     */
   NumComMuons(const std::string & comparison, UInt_t number);

    ~NumComMuons(); //!< Destructor.

    /*! \brief Cuts on the number of common leptons of a specified type.
     *
     * \param Reference to the event data container.
     * \return True if the number of common leptons in the event matches the condition.
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
   Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
   UInt_t mNumber;           //!< Number of common leptons with which to compare.

 }; // ~NumComMuons class

 class NumCommonBtagJets : public Operation::_Base
 {
 public:
   NumCommonBtagJets (const std::string & comparison, UInt_t number, float cutValue);
   ~NumCommonBtagJets ();
   bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
  
 private:
   Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
   UInt_t mNumber;           //!< Number of common leptons with which to compare.
   float mCut; // !< value at which the btaging variable cuts.
   /* data */
 };



  /*! \brief Cuts on the basis of the HT of the the event's common objects.
   *
   * \author Dunno
   * \date Dunno
   */
  class HTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     * @param [in] mSumEtCutVal
     */
    HTCut(float mSumEtCutVal);

    ~HTCut() {;}

    /*! \brief Cuts on
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

    float mSumEtCutVal;

  };

  /*! \brief Cuts on the basis of the SumEt of the the event's common objects.
   *
   * \author Markus Stoye
   * \date February 2009
   */

 class HTLessThanCut : public Operation::_Base {

 public:

   /*! \brief Constructor.
    * @param [in] mSumEtCutVal
    */
   HTLessThanCut(float mSumEtCutVal);

   ~HTLessThanCut() {;}

   /*! \brief Cuts on
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

   float mSumEtCutVal;

 };

 /*! \brief Cuts on the basis of the SumEt of the the event's common objects.
  *
  * \author Bryn Mathias
  * \date July 2010
  */



  class BtagResponse : public Operation::_Base {
  public:
    BtagResponse(float, int, int);
    ~BtagResponse(){;}
    bool Process ( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
    int algo_;
    int njetnumber_;
  };



  class CommonMHTCut : public Operation::_Base {

  public:

    CommonMHTCut(float MHTCut);
    ~CommonMHTCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMHTCut;
  }; // ~CommonMHTCut class


  /*! \brief Cuts on the basis of the AlphaT of the the event's common objects.
   *
   * \author
   * \date
   */
  class CommonAlphaTCut : public Operation::_Base {

  public:

    CommonAlphaTCut(float AlphaTCut);
    ~CommonAlphaTCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mAlphaTCut;
  }; // ~CommonAlphaTCut class


  class SumETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    SumETCut(float mSumEtCutVal);

    ~SumETCut(); //!< Destructor.

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

  class SumETCutMax : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] mSumEtCutVal
     */
    SumETCutMax(float mSumEtCutMaxVal);

    ~SumETCutMax(); //!< Destructor.

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
    float mSumEtCutMaxVal;           //!< Sum Et Cut

  }; // ~SumETCut class


  /*! \brief Cuts on the basis of the recoil MET of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */
 class RecoilMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    RecoilMETCut(float mMHTvalue );

    ~RecoilMETCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~RecoilMETCut class


  /*! \brief Cuts on the basis of the calo MET of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */
 class caloMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    caloMETCut(float mMHTvalue );

    ~caloMETCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~caloMETCut class

 class tcMETCut : public Operation::_Base {

  public:

    tcMETCut(float mMHTvalue );

    ~tcMETCut(); //!< Destructor.

   bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mMHTvalue;           //!<

  };
#ifdef _ICF_
  /*! \brief Cuts on the basis of the Dphi Jet2 MET of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */
 class PFMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    PFMETCut(float mMETvalue );

    ~PFMETCut(); //!< Destructor.

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

  }; // ~caloMETCut class
  /*! \brief Cuts on the basis of the Dphi Jet2 MET of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */
#endif


  /*! \brief Cuts on the basis of the Jet1Dphi MET of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */

 class Jet2JDphiMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    Jet2JDphiMETCut(float mMHTvalue );

    ~Jet2JDphiMETCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~Jet2JDphiMETCut class

  /*! \brief Cuts on the basis of the Jet1Dphi MET of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */

 class Jet1JDphiMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    Jet1JDphiMETCut(float mMHTvalue );

    ~Jet1JDphiMETCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~Jet1JDphiMETCut class


 class Jet3JDphiMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    Jet3JDphiMETCut(float mMHTvalue );

    ~Jet3JDphiMETCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~Jet3JDphiMETCut class





 class DRMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    DRMETCut(float mMHTvalue );

    ~DRMETCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~DRMETCut class




 class RecoilMHTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
    RecoilMHTCut(float mMHTvalue );

    ~RecoilMHTCut(); //!< Destructor.

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
    float mMHTvalue;           //!<

  }; // ~RecoilMHTCut class

  /*! \brief Cuts on the basis of the recoil MET and SumEt of the event
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   */
 class  RecoilMET_ov_SumETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     RecoilMET_ov_SumETCut(float mMHTvalue );

    ~ RecoilMET_ov_SumETCut(); //!< Destructor.

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
    float mRMET_SumEt;           //!<

  }; // ~RecoilMETCut class

 class  AK5CaloMETCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     AK5CaloMETCut(float mAK5CaloMET );

    ~ AK5CaloMETCut(); //!< Destructor.

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
    float mAK5CaloMET;           //!<

  }; // ~AK5CaloMETCut class

 class  TDRHTCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     TDRHTCut(float mMHTvalue );

    ~ TDRHTCut(); //!< Destructor.

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
    float mRMET_SumEt;           //!<

  }; // ~TDRHTCut class



 class  MeffCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     MeffCut(float mMHTvalue );

    ~ MeffCut(); //!< Destructor.

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
    float mRMET_SumEt;           //!<

  }; // ~RecoilMETCut class


 class  firstJetetaCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] first jet max eta value
     */
     firstJetetaCut(float mMHTvalue );

    ~ firstJetetaCut(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~firstJetetaCut class


 class  firstJetPtCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     firstJetPtCut(float mMHTvalue );

    ~firstJetPtCut(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~FirstJetPtCut class





 class  missedHTcut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] first jet max eta value
     */
     missedHTcut(float mMHTvalue );

    ~ missedHTcut(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~missedHTcut class

 class  firstJetEtCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] first jet min et value
     */
     firstJetEtCut(float mMHTvalue );

    ~ firstJetEtCut(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~firstJetEtCut class




 class  secondJetEtCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     secondJetEtCut(float mMHTvalue );

    ~ secondJetEtCut(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~secondJetEtCut class


  class  PhotonPtCut : public Operation::_Base {

  public:

    PhotonPtCut(float mMHTvalue );

    ~ PhotonPtCut(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mCut;           //!<

  }; // ~PhotonPtCut class


  class PhotonJetDRCut : public Operation::_Base {

  public:

    PhotonJetDRCut(float MuonJetDRCut);
    ~PhotonJetDRCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mMuonJetDRCut;
  }; // ~PhotonJetDRCut class




 class  alpha_tCut : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     alpha_tCut(float mMHTvalue );

    ~ alpha_tCut(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~alpha_tCut class

 class  alpha_tCut_Less : public Operation::_Base {

  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] mMHTvalue
     */
     alpha_tCut_Less(float mMHTvalue );

    ~ alpha_tCut_Less(); //!< Destructor.

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
    float mCut;           //!<

  }; // ~alpha_tCut_Less class

 ////////////////////////////////////////////////////////

  /*! \brief "Number of good jets" cut.
   *
   * \date Feb 2009
   * \author CMS SUSY ntuple analysis team.
   * \version 1.1
   *
   * Allows the user to accept/reject events on the basis of how
   * many good jetss there are in the event.
   */
  class NumComJets : public Operation::_Base {

  public:

    /*! \brief Constructor.
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of jets to compare.
     */
    NumComJets(const std::string & comparison, UInt_t number);

    ~NumComJets(); //!< Destructor.

    /*! \brief Cuts based on the number of good jets in the event.
     * @param [in] ev Reference to the event data container.
     * @return True if the number of jets in the event matches the condition.
     */
    bool Process(Event::Data & ev);

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     * @param Reference to output stream (for output).
     * @return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
    UInt_t mNumber;           //!< Number of jets of type to compare.

  }; // ~NumComJets class

    /*! \brief Cut on the number of common photons in the event.
     */
    class NumComPhotons : public Operation::_Base {

      public:

        /*! \brief Constructor.
         * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
         * @param [in] number The number of photons to compare.
         */
      NumComPhotons(const std::string & comparison, UInt_t number);

        ~NumComPhotons(); //!< Destructor.

        /*! \brief Cuts based on the number of common photons in the event.
         * @param [in] ev Reference to the event data container.
         * @return True if the number of photons in the event matches the condition.
         */
      bool Process(Event::Data & ev);

        /*! \brief Describes the operation, for analysis output to terminal/log file.
         * @param Reference to output stream (for output).
         * @return Reference to output stream.
         */
        std::ostream& Description(std::ostream& ostrm);

    private:
      // Operation private data members
      //--------------------------------
      Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
      UInt_t mNumber;           //!< Number of objects of type to compare.

    }; // ~NumComPhotons class


 class OddObject : public Operation::_Base {

  public:

    /*! \brief Constructor.
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] number The number of jets to compare.
     */
    OddObject();

    ~OddObject(); //!< Destructor.

    /*! \brief Cuts based on the number of good jets in the event.
     * @param [in] ev Reference to the event data container.
     * @return True if the number of jets in the event matches the condition.
     */
   bool Process(Event::Data & ev);

    /*! \brief Describes the operation, for analysis output to terminal/log file.
     * @param Reference to output stream (for output).
     * @return Reference to output stream.
     */
    std::ostream& Description(std::ostream& ostrm);


  }; // OddObject class


    /*! \brief Cut operation for rejecting events with "bad" photons (pass kinematic cuts, fail iso/ID).
     * \author Markus Stoye
     * \date March 2009
     * \version 1.0
     */
  class OddPhoton : public Operation::_Base {
  public:
    OddPhoton();  //!< Constructor.
    ~OddPhoton(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // OddPhoton class

  /*! \brief Fails an event if a kinematically sound object fails the common "ID" requirements.
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class OddElectron : public Operation::_Base {
  public:
    OddElectron(); //!< Constructor.
    ~OddElectron(); //!< Destructor.
    bool Process(Event::Data & ev); //!< Makes the cut - fails if odd object present.
    std::ostream& Description(std::ostream& ostrm);
  }; // OddElectron class


  /*! \brief Cut operation for rejecting events with "bad" jets (pass kinematic cuts, fail iso/ID).
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class OddJet : public Operation::_Base {
  public:
    OddJet(); //!< Constructor.
    ~OddJet(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // OddJet class

  class PhotkilledJet : public Operation::_Base {
  public:
    PhotkilledJet(); //!< Constructor.
    ~PhotkilledJet(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // OddJet class

  /*! \brief Cut operation for rejecting events with "bad" muons (pass kinematic cuts, fail iso/ID).
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class OddMuon : public Operation::_Base {
  public:
    OddMuon();  //!< Constructor.
    ~OddMuon(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // OddMuon class



  class missedTrCut : public Operation::_Base {
  public:
    missedTrCut(float cutV);  //!< Constructor.
    ~missedTrCut(); //!< Destructor.
    bool Process(Event::Data & ev);
    float mcutV;
    std::ostream& Description(std::ostream& ostrm);
  }; // O





  /*! \brief Cut operation for rejecting events with muons in the jet...
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class badMuonInJet : public Operation::_Base {
  public:
    badMuonInJet();
    ~badMuonInJet(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // badMuonInJet class

  /*! \brief Cut operation for rejecting events with badly corrected CC jets...
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class badJetccJet : public Operation::_Base {
  public:
    badJetccJet();
    ~badJetccJet(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // badJetccJet class

  /*! \brief Cut operation for rejecting events with electrons pT > 5GeV pointing in the direction of the ComRecoilMET
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class badEliInJet : public Operation::_Base {
  public:
    badEliInJet();
    ~badEliInJet(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // badEliInJet class

  /*! \brief Cut operation for rejecting events with objects that killed other in the cross cleaning process.
   * \author Markus Stoye
   * \date March 2009
   * \version 1.0
   */
  class deadOverlap : public Operation::_Base {
  public:
    deadOverlap();
    ~deadOverlap(); //!< Destructor.
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
  }; // deadOverlap class

  class DPhiCut : public Operation::_Base {
  public:

    /*! \brief Constructor.
     *
     * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
     * @param [in] Mindphi MET-JET max value
     */
    DPhiCut(float mMHTvalue );
    ~DPhiCut(); //!< Destructor.

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
    float mSumEtCutVal;           //!<

  }; // ~RecoilMHTCut class

 class JetMETMinDPhiCut : public Operation::_Base {
  public:
   /*! \brief Constructor.
    *
    * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
    * @param [in] mMHTvalue
    */
   JetMETMinDPhiCut(float value );
   ~JetMETMinDPhiCut(); //!< Destructor.

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
   float mCutVal;           //!<

 }; // ~RecoilMHTCut class

 class biasedDPhiCut : public Operation::_Base {
  public:
   /*! \brief Constructor.
    *
    * @param [in] comparison Comparison string, i.e. "==", ">=", etc.
    * @param [in] mMHTvalue
    */
   biasedDPhiCut(float mMHTvalue );
   ~biasedDPhiCut(); //!< Destructor.

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
   float mSumEtCutVal;           //!<

 }; // ~RecoilMHTCut class

 class RA2TrackingFailureFilterCut : public Operation::_Base {
  public:
  RA2TrackingFailureFilterCut();
  ~RA2TrackingFailureFilterCut();
  bool Process(Event::Data & ev);
  std::ostream& Description(std::ostream& ostrm);
};

 class RA2ecaldeadcellfilterflagCut : public Operation::_Base {
  public:
  RA2ecaldeadcellfilterflagCut();
  ~RA2ecaldeadcellfilterflagCut();
  bool Process(Event::Data & ev);
  std::ostream& Description(std::ostream& ostrm);
};


 class GoodEventSelection : public Operation::_Base {
  public:
  GoodEventSelection();
  ~GoodEventSelection();
  bool Process(Event::Data & ev);
  std::ostream& Description(std::ostream& ostrm);
};// Good event selection cuts on techbit physics declared vertexrequirement and monster events


 class beamHaloCSCTightHaloId: public Operation::_Base {
 public:
   beamHaloCSCTightHaloId(); //!< Constructor.
   ~beamHaloCSCTightHaloId(); //!< Destructor.
   bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
 }; // NoiseFilter class


class MonsterFilter: public Operation::_Base {
 public:
   MonsterFilter(); //!< Constructor.
   ~MonsterFilter(); //!< Destructor.
   bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
 }; // NoiseFilter class

 class NoiseFilter : public Operation::_Base {
 public:
   NoiseFilter(); //!< Constructor.
   ~NoiseFilter(); //!< Destructor.
   bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
 }; // NoiseFilter class

 class EcalSpikeCleaner : public Operation::_Base {
 public:
   EcalSpikeCleaner(); //!< Constructor.
   ~EcalSpikeCleaner(); //!< Destructor.
   bool Process(Event::Data & ev);
   std::ostream& Description(std::ostream& ostrm);
 }; // EcalSpikeCleaner class

class TriggerCut : public Operation::_Base {
 public:
  /*! \brief Constructor.
   *
   * @param [in] mTriggerBit
   */
  TriggerCut(const std::string & bit);

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
  const std::string mTriggerBit;
}; // ~TriggerCut class

class TwoTriggerAndCut : public Operation::_Base {
 public:
  /*! \brief Constructor.
   *
   * @param [in] mTriggerBit
   */
  TwoTriggerAndCut(const std::string & bit1, const std::string & bit2);

~TwoTriggerAndCut(); //!< Destructor.

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

  const std::string mTriggerBit1;
  const std::string mTriggerBit2;

}; // ~TwoTriggerAndCut class



class TwoTriggerCut : public Operation::_Base {
 public:
  /*! \brief Constructor.
   *
   * @param [in] mTriggerBit
   */
  TwoTriggerCut(const std::string & bit1, const std::string & bit2);

~TwoTriggerCut(); //!< Destructor.

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

  const std::string mTriggerBit1;
  const std::string mTriggerBit2;

}; // ~TwoTriggerCut class

class ThreeTriggerCut : public Operation::_Base {
 public:
  /*! \brief Constructor.
   *
   * @param [in] mTriggerBit
   */
  ThreeTriggerCut(const std::string & bit1, const std::string & bit2, const std::string & bit3);

~ThreeTriggerCut(); //!< Destructor.

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

  const std::string mTriggerBit1;
  const std::string mTriggerBit2;
  const std::string mTriggerBit3;

}; // ~ThreeTriggerCut class

class TriggersExist : public Operation::_Base {
 public:
  TriggersExist(const Utils::ParameterSet & ps);

  ~TriggersExist(); //!< Destructor.

  bool Process(Event::Data & ev);

  std::ostream& Description(std::ostream& ostrm);

 private:
  std::vector<std::string> mTriggers;
};

class UnPrescaled : public Operation::_Base {
 public:
  /*! \brief Constructor.
   *
   * @param [in] mTriggerBit
   */

  UnPrescaled(const std::string & mbit);



~UnPrescaled(); //!< Destructor.

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
  const std::string mTrigger;
}; // ~UnPrescaled class


  class CutOnUnCorLeadJetPt : public Operation::_Base {

  public:

    CutOnUnCorLeadJetPt(float temp);
    ~CutOnUnCorLeadJetPt();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    float mTemp;
  }; // ~CutOnUnCorLeadJetPt class



class SkimOp : public Operation::_Base{
 public:
  SkimOp(const Utils::ParameterSet &ps);
  ~SkimOp();
  void End(Event::Data & ev);
  void Start(Event::Data &ev);

  bool Process(Event::Data & ev);
  void ParseDropKeep();
  void SetBranchStatuses(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:

  const std::string mSkimName;
  const std::vector<std::string> mBranches;
  const bool mDropBranches;
  TFile* mFile;
  TTree* mCloneTree;
  int mCount;
  int mTotal;
  std::vector<std::pair<bool,std::string> > mCmds;
};

class MultiTrigger : public Operation::_Base{
 public:
  MultiTrigger(const Utils::ParameterSet & ps);
  ~MultiTrigger();

  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  std::vector<std::string> mTriggers;
  bool verb;
  bool usePrescale;
};



  class Mix2Triggers : public Operation::_Base {
  public:

    Mix2Triggers(int runNumber, const std::string & bit1, const std::string & bit2);
    ~Mix2Triggers();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    unsigned int mRunNumber;
    const std::string mTriggerBit1;
    const std::string mTriggerBit2;

  }; // ~Mix2Triggers class



  class Mix3Triggers : public Operation::_Base {
  public:

    Mix3Triggers(int runNumber1, int runNumber2, const std::string & bit1, const std::string & bit2, const std::string & bit3);
    ~Mix3Triggers();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    unsigned int mRunNumber1;
    unsigned int mRunNumber2;
    const std::string mTriggerBit1;
    const std::string mTriggerBit2;
    const std::string mTriggerBit3;

  }; // ~Mix3Triggers class

  class JSONFilter : public Operation::_Base {

  public:

    JSONFilter(const std::string name, const Utils::ParameterSet & ps);

    ~JSONFilter();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    std::set<std::pair<unsigned int, unsigned int> > _lumis;
    unsigned int _cache_run;
    unsigned int _cache_lumi;
    bool _cache_result;
    std::string _json_name;
  };

  class JSONOutput : public Operation::_Base {

  public:

    JSONOutput(const std::string & name);

    ~JSONOutput();

    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    void End(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    Utils::Lumis _lumis;
    const std::string _json_name;
  };

  class EventSelector : public Operation::_Base {
  public:

    EventSelector(const Utils::ParameterSet & ps);
    ~EventSelector();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    std::set<boost::tuple<unsigned int, unsigned int, unsigned int> > select_;
    bool accept_;

  }; // ~EventSelector class








} //~namespace Operation

#endif //~CommonOps_hh

