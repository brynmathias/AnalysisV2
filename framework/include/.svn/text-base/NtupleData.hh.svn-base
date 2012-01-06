/*! \file NtupleData.hh
 * \brief Header file for the ntuple data wrapper class NtupleData.
 */
#ifndef NtupleData_h
#define NtupleData_h

#include "Ntuple.hh"
#include <string>
#include <iostream>
#include <vector>

#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TChain.h>
#include <TVector3.h>

#include "EventElement.hh"
/*! \brief Wrapper class for ntuple data from an event.
 *
 * \version 2
 * \author CMS SUSY Analysis Team
 * \author John Jones
 * \date Feb 2009
 *
 */
namespace Event{
class NtupleData {

protected:
  /*! \brief Constructor.
   * @param [in] fileName Path of the ROOT file containing the ntuple.
   * @param [in] dataSetName Name of the dataset.
   * @param [in] maxEvents The maximum number of events to process.
   * @param [in] reWeight Factor to re-weight the raw ntuple event weight.
   */
  NtupleData(const std::string & fileName,
             const std::vector<std::string> & fileList,
	     const std::string & dataSetName,
	     UInt_t lastEntry,
	     UInt_t firstEntry = 0);
  //, bool skim = false); // default to using weight from evt
  ~NtupleData(); //!< Destructor.

 private:
  NtupleData();

public:

  /*! \brief Get the next entry (up to mMaxEntries).
   * \return False when out of entries
   */
  NtupleData & operator++();
  bool AtEnd();
  bool AtLast();
  UInt_t GetCurrentEntry() const;
  UInt_t GetFirstEntry() const;
  UInt_t GetLastEntry() const;
  UInt_t GetTotalEntries() const;
  UInt_t GetChainOffSet() const;
  /*! \brief Returns the name of ntuple dataset.
   * \return The name of the dataset.
   */
  const std::string & DataSet();

  /*! \brief Returns the path of the ntuple dataset.
   * \return The path of the ntuple dataset.
   */
  const std::string & DataPath();

  TBranch* GetBranch(const std::string & name) const;
  void FilterTree(const std::vector<std::pair<bool,std::string> > & filter,
                  std::string out_name);

  void Register(Event::_Element* ele);
  void Unregister(Event::_Element* ele);
protected:
  //-------------------------------
  // Analysis running data members
  //-------------------------------
  const std::string mDataPath; //!< Path of the ntuple data set.
  const std::string mDataSet;  //!< Name of the ntuple data set.
  UInt_t mEntry;               //!< The current entry number.
  UInt_t mFirstEntry;          //!< The first entry to be processed.
  UInt_t mLastEntry;           //!< The last entry to be processed.
  double mUserEventWeight;
  UInt_t mStopAfter;
  UInt_t mChainOffset;
  std::vector<Event::_Element*> mElements;
public:
  // File class
  TFile *mFile;
  TChain* mChain;
  TDirectory *mDirectory;
  TTree *mDataTree;     //!< Pointer to the ROOT TTree containing the ntuple.

  //===========================
  // General event information
  //===========================
  /*! \brief Returns the weight of the current event.
   *
   * Note that the returned value is multiplied by the supplied
   * re-weighting factor.
   * \return The weight of the current event (re-weighted).
   */
  Double_t GetUserEventWeight() const{
      return mUserEventWeight;
  }

  TTree* GetTree();

}; // ~NtupleData class definition.
}
#endif //~EventData_h
