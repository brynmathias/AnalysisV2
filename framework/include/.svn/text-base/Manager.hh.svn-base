/*! \file Manager.hh
 * \brief Header file for the analysis Operation::Manager class.
 *
 */
#ifndef Manager_h
#define Manager_h

#include "NtupleData.hh"
#include "EventData.hh"
#include "Operation.hh"
#include "Tree.hh"

#include <fstream>
#include <iostream>
#include <string>
#include "Utils.hh"
#include "Compute_User.hh"
#include "Ntuple.hh"

namespace Operation {

  /*! \brief %Operation manager for the ntuple-based analysis.
   *
   * \author CMS SUSY Dijet Analysis Team
   * \date October 2008
   * \version 1.1
   *
   */
  class Manager {

  public:

    /*! \brief Constructor.
     * @param logFileName The name of the log file.
     */
    Manager();

    ~Manager(); //!< Destructor.

    /*! \brief Adds an operation to the analysis.
     * \param aOp Refernce to the (base class of the) operation to be added.
     */
    void Add(Operation::_Base & aOp);

    /*! \brief an operation from the analysis.
     * @param [in] aOp Reference to the operation to be removed.
     */
    void Add(Operation::Tree & aTree);

    /*! \brief Check output file specified can be written to.
     */
    bool CheckCanWriteToOutput();

     /*! \brief Run the analysis.
     */
    void Run(const Utils::ParameterSet & config, // configuration file
             const Utils::ParameterSet & sample
             //   UInt_t lastEntry = 0, // last entry to process (default = run to end)
             //	     UInt_t firstEntry = 0, // first entry to process
	     //double reWeight = 1.0, // TODO - unify last two terms
	     //float Weight = -1
);

    void AddUserVar(std::string name,Compute::UserBase & comp);
    void AddMuonFilter(std::string order,
                       Compute::ObjectFilter<Event::Lepton> & filter);
    void AddElectronFilter(std::string order,
                           Compute::ObjectFilter<Event::Lepton> & filter);
    void AddTauFilter(std::string order,
                           Compute::ObjectFilter<Event::Lepton> & filter);
    void AddPhotonFilter(std::string order,
			 Compute::ObjectFilter<Event::Photon> & filter);
    void AddJetFilter(std::string order,
                      Compute::ObjectFilter<Event::Jet> & filter);
   void AddMETFilter(std::string order,
                      Compute::ObjectFilter<ICF_LorentzV> & filter);
    void AddWeightFilter(std::string order,
                  Compute::ObjectFilter<double> & filter);

    const std::string GetNtupleFormat(){
      return NT_FORMAT;
    }

    const int GetNtupleVersion(){
      return NT_VERSION;
    }

    void FilterNtuple(const Utils::ParameterSet & conf,
                      const Utils::ParameterSet & sample,
                      const Utils::ParameterSet & filter);
  private:
    //-----------------------------------
    // Manager: Private member functions
    //-----------------------------------

    /*! \brief Outputs the results of the operation on the dataset.
     * @param [in] dataSet The name of the dataset being analysed.
     * @param [in] ng_all The number of events analysed.
     * @param [in] ng_total The number of events surviving the analysis operations.
     */
    void OutputResults(const std::string & dataSet,
		       double ng_all,
		       double ng_total);

    /*! \brief The operation storage structure.
     */
    struct OpData {
      Operation::_Base *op; //!< Pointer to the operation.
      Double_t ng;          //!< Counter for the events "passing" the operation.
      Double_t nb;          //!< Counter for the events "failing" the operation.
    };

  private:
    //-------------------------------
    // Manager: Private data members
    //-------------------------------
    std::string mLogFileName; //!< Cached log file name.
    std::string mJsonFileName; //!< Cached log file name.
    std::string mFormat; //!< Cached log file name.
    Utils::Lumis mlist_of_runs_and_lumis;

    // Could also have done this by pushing connection
    // forwarding into the operations themselves, which
    // would make the behaviour locally emergent :)
    // JJ - indeed you could, and this is exactly
    // what the trees do, although it's only partially
    // true so that most of the accounting isn't handled
    // by the operations which would add considerable
    // overhead to some single-track analyses, and
    // also create future caching / threading problems
    std::vector<OpData> mOperations; //!< List of operations in the manager (circular)
    Operation::Tree *mTree;
    std::map<std::string,Compute::UserBase*> mUserVars;
    std::vector< std::pair<std::string,
                           Compute::ObjectFilter<Event::Lepton>* > > muon_filters;
    std::vector< std::pair<std::string,
                           Compute::ObjectFilter<Event::Lepton>* > > electron_filters;
    std::vector< std::pair<std::string,
                           Compute::ObjectFilter<Event::Lepton>* > > tau_filters;
    std::vector< std::pair<std::string,
                           Compute::ObjectFilter<Event::Photon>* > > photon_filters;
    std::vector< std::pair<std::string,
                           Compute::ObjectFilter<Event::Jet>* > > jet_filters;
  std::vector< std::pair<std::string,
                           Compute::ObjectFilter<ICF_LorentzV>* > > met_filters;
    std::vector< std::pair<std::string,
                           Compute::ObjectFilter<double>* > > weight_filters;
  }; // end of Manager class definition.

} // ~namespace Operation

#endif //~Manager_h
