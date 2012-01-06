/*! \file Manager.cc
 * \brief File containing source code for the Operation::Manager class.
 */

#include "Manager.hh"
#include <time.h>
#include <iomanip>

namespace Operation {

  //========================================
  // Operation Manager class implementation
  //========================================
  Manager::Manager() :
    mTree(0)
  {}

  Manager::~Manager() {}

  void Manager::Add(Operation::_Base & aOp) {
    Manager::OpData tempData;
    tempData.op = &aOp;
    tempData.ng = 0.0;
    mOperations.push_back(tempData);
  }

  void Manager::Add(Operation::Tree & aTree) {
    mTree = &aTree;
  }

bool Manager::CheckCanWriteToOutput(){
  ofstream outputfile(mLogFileName.c_str(), ios::app);
  return(outputfile.is_open());
}

void Manager::AddUserVar(std::string name,Compute::UserBase & comp){
  mUserVars[name]=&comp;
}

void Manager::AddMuonFilter(std::string order,
                            Compute::ObjectFilter<Event::Lepton> & filter){
  muon_filters.push_back(std::pair<std::string,
                         Compute::ObjectFilter<Event::Lepton>* >(order,&filter));
}

void Manager::AddElectronFilter(std::string order,
                                Compute::ObjectFilter<Event::Lepton> &filter){
  electron_filters.push_back(std::pair<std::string,
                             Compute::ObjectFilter<Event::Lepton>* >(order,&filter));
}

void Manager::AddTauFilter(std::string order,
                                Compute::ObjectFilter<Event::Lepton> &filter){
  tau_filters.push_back(std::pair<std::string,
                             Compute::ObjectFilter<Event::Lepton>* >(order,&filter));
}


void Manager::AddPhotonFilter(std::string order,
                                Compute::ObjectFilter<Event::Photon> &filter){
  photon_filters.push_back(std::pair<std::string,
                             Compute::ObjectFilter<Event::Photon>* >(order,&filter));
}

void Manager::AddJetFilter(std::string order,
                           Compute::ObjectFilter<Event::Jet> & filter){
  jet_filters.push_back(std::pair<std::string,
                        Compute::ObjectFilter<Event::Jet>* > (order,&filter));
}

void Manager::AddMETFilter(std::string order,
                           Compute::ObjectFilter<ICF_LorentzV> & filter){
  met_filters.push_back(std::pair<std::string,
                        Compute::ObjectFilter<ICF_LorentzV>* >(order, &filter));
}

void Manager::AddWeightFilter(std::string order,
                              Compute::ObjectFilter<double> & filter){
  weight_filters.push_back(std::pair<std::string,
                        Compute::ObjectFilter<double>* >(order, &filter));
}

  void Manager::OutputResults(const std::string & dataSet,
			      double ng_all,
			      double ng_total) {

    ofstream outfile(mLogFileName.c_str(), ios::app);

    // Output the results of the analysis.
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "Dataset info recorded in: " << dataSet << std::endl;
    std::cout << "Total events processed by all operations: " << ng_all << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    if (mFormat == "text") {
      outfile << "Number of Events Processed = " << ng_all << std::endl;
      outfile << std::endl;
    } else {
      outfile << "  \"Number of Events Processed\" : " << ng_all << "," << std::endl;
    }

    std::vector<Manager::OpData>::iterator last = mOperations.begin();
    std::vector<Manager::OpData>::iterator i = mOperations.begin();
    while ( i != mOperations.end() ) {

      double ng_tot = i->ng + i->nb;
      int rel = ng_tot > 0. ? int( 100*i->ng / ng_tot ) : 0;
      int abs = ng_all > 0. ? int( 100*i->ng / ng_all ) : 0;
      std::cout << "Events surviving "
		<< *(i->op)
		<< ": "
		<< i->ng
		<< " (rel=" << rel << "%,abs=" << abs << "%)"
		<< std::endl;

      outfile << "Events surviving "
	      << *(i->op)
	      << ": "
	      << i->ng
	      << " (rel=" << rel << "%,abs=" << abs << "%)"
	      << std::endl;

      ++i;
    } // end of while loop

    //if(mOperations.size()==0)
      //std::cout << "No operations" << std::endl;

    if ( mTree ) {

      //cout << (*mTree);
      outfile << (*mTree);
      if (mFormat != "text") {
        outfile << "}";
      }
    } // end of tree output

    mlist_of_runs_and_lumis.Sort();
    ofstream jsonfile(mJsonFileName.c_str());
    jsonfile << mlist_of_runs_and_lumis.Print();

  } // end of Manager::OutputResults method.

void Manager::Run(const Utils::ParameterSet & config,
                  const Utils::ParameterSet & sample) { // Weight default == -1 if not set (off)

  mLogFileName=sample.Get<std::string>("LogFile");
  mJsonFileName=sample.Get<std::string>("JsonFile");
  mFormat=config.Get<std::string>("LogFileFormat");
  if (mTree){
    mTree->SetFormat(mFormat);
  }
  int nevents = 0;

  // Clear event counters (all, totals and for each operation)
    double ng_all = 0.0;
    double ng_total = 0.0;
    std::vector<Manager::OpData>::iterator i = mOperations.begin();
    while ( i != mOperations.end() ) { i->ng = 0.0; ++i; }

    Utils::LoadConfig(config);
    // Instantiate the EventData container, passing it the ref to the ntuple
    // wrapper class.
    Event::Data ev(sample,mUserVars,muon_filters,
                   electron_filters, tau_filters,
                   photon_filters,
                   jet_filters,
                   met_filters,
                   weight_filters); //!< The (re)processed event data container.

    ofstream outfile(mLogFileName.c_str());
    if (mFormat == "text") {
      outfile << "Configuration:" << std::endl;
      outfile << std::endl;
      outfile << config.ToString();
      outfile << std::endl;

      outfile << "Dataset Configuration:" << std::endl;
      outfile << std::endl;
      outfile << sample.ToString();
      outfile << std::endl;

      outfile << "Weighting:" << std::endl;
      ev.GetEventWeight.Print(outfile);
      outfile << std::endl;
    } else {
      outfile << "{" << std::endl;
      outfile << "  \"Dataset\" : \"" << ev.DataSet() << "\"," <<std::endl;

      outfile << "  \"Configuration\" :" << std::endl;
      outfile << "  {" << std::endl;
      outfile << config;
      outfile << "  }," << std::endl;

      outfile << "  \"Dataset Configuration\" :" << std::endl;
      outfile << "  {" << std::endl;
      outfile << sample;
      outfile << "  }," << std::endl;

      outfile << "  \"Weighting\" : ";
      outfile << "\"";
      ev.GetEventWeight.Print(outfile);
      outfile << "\"," << std::endl;
    }

    if(mUserVars.size()>0){
      for(std::map<std::string,Compute::UserBase*>::iterator ii=mUserVars.begin();
          ii!=mUserVars.end();
          ++ii)
      {
        (*ii).second->Init(ev);
      }
    }

    if(muon_filters.size()>0 || jet_filters.size()>0 || electron_filters.size()>0 || photon_filters.size()>0 || tau_filters.size()>0  ){
      // Jets
      for(std::vector<std::pair<std::string,
              Compute::ObjectFilter<Event::Jet>* > >::iterator ii=jet_filters.begin();
          ii!=jet_filters.end();
          ++ii){
        ii->second->Init(ev);
      }
      // Muons
      for(std::vector<std::pair<std::string,
              Compute::ObjectFilter<Event::Lepton>* > >::iterator ii=muon_filters.begin();
          ii!=muon_filters.end();
          ++ii){
        ii->second->Init(ev);
      }
      // Taus
      for(std::vector<std::pair<std::string,
	    Compute::ObjectFilter<Event::Lepton>* > >::iterator ii=tau_filters.begin();
          ii!=tau_filters.end();
          ++ii){
        ii->second->Init(ev);
      }
      // Electrons
      for(std::vector<std::pair<std::string,
              Compute::ObjectFilter<Event::Lepton>* > >::iterator ii=electron_filters.begin();
          ii!=electron_filters.end();
          ++ii){
        ii->second->Init(ev);
      }
      // Photons
      for(std::vector<std::pair<std::string,
              Compute::ObjectFilter<Event::Photon>* > >::iterator ii=photon_filters.begin();
          ii!=photon_filters.end();
          ++ii){
        ii->second->Init(ev);
      }

      // MET
      for(std::vector<std::pair<std::string,
              Compute::ObjectFilter<ICF_LorentzV>* > >::iterator ii=met_filters.begin();
          ii!=met_filters.end();
          ++ii){
        ii->second->Init(ev);
      }

      // Weights
      for(std::vector<std::pair<std::string,
              Compute::ObjectFilter<double>* > >::iterator ii=weight_filters.begin();
          ii!=weight_filters.end();
          ++ii){
        ii->second->Init(ev);
      }
    }
    if ( mTree ) {
      // We must reset the tree in case running on multiple samples
      mTree->Reset();
      // Send the start command
      mTree->Start(ev);
    }

    // Loop over the operations
    i = mOperations.begin();
    while ( i != mOperations.end() ) {
      // Clear this in case we are running on multiple samples
      i->ng=0.;
      i->nb=0.;
      // Call the filter start command
      i->op->Start(ev);
      ++i;
    }
    // Report chain structure
    //if ( mTree ) {
      // Debug output
      //cout << (*mTree);
      //outfile << (*mTree);
    //}
    // Close the log file
    outfile.close();

    time_t start = time(NULL);

    mlist_of_runs_and_lumis.Reset();
    // Main event loop
    // Just keep going until max events is hit or we finish the file
    while ( !ev.AtEnd() ) {

      if (ev.IsData()) mlist_of_runs_and_lumis.Add(ev.RunNumber(), ev.LumiSection());
      // Sum number of events (unweighted)
      nevents++;

      // Sum the total event weight
      ng_all += ev.GetEventWeight();

      // Run the tree
      if ( mTree ) {
	      mTree->Process(ev);
	      if ( ev.AtLast() ) { mTree->End(ev); }
      }

      // Loop over the operations
      i = mOperations.begin();
      while ( i != mOperations.end() ) {

	// Call the filter
	if ( !i->op->Process(ev) ) {
	  i->nb += ev.GetEventWeight();
	  break; // break on failure
	}

	// Filter passed, save weight
	i->ng += ev.GetEventWeight();

	++i;
      }

      // If we aren't at the end continue without adding total
      if ( i == mOperations.end() ){
        // Sum the total that passes all the operations
        ng_total += ev.GetEventWeight();
      }

      // Increment the event position
      ++ev;

    } // end of while loop over events

    time_t elapsed = time(NULL) - start;

    // Output the information about the run to the log file
    OutputResults(mLogFileName.c_str(),
  		  ng_all,
		  ng_total);

    std::cout << "[Manager::~Manager]"
	      << " Analysis has taken "
	      << std::scientific << elapsed
	      << " seconds to process "
	      << std::scientific << nevents
	      << " events at an average rate of "
	      << std::scientific << ( elapsed > 0 ? nevents/elapsed : nevents )
	      << " events/second"
	      << std::endl;

  } // ~Manager::Run method.

void Manager::FilterNtuple(const Utils::ParameterSet & conf,
                           const Utils::ParameterSet & sample,
                           const Utils::ParameterSet & filter){
  Utils::LoadConfig(conf);
  const std::vector<std::string> drops =
      filter.Get<std::vector<std::string> >("Branches");
  std::vector<std::pair<bool,std::string> > cmds;
  for(std::vector<std::string>::const_iterator ii= drops.begin();
      ii!=drops.end();
      ++ii){
    std::string drop_keep="";
    std::string branch_name="";
    std::string::const_iterator ic;
    // Skip leading whitespace
    for(ic=ii->begin();ic!=ii->end();++ic){
      if((*ic)!=' ') break;
    }
    // Get drop/keep string
    for(;ic!=ii->end();++ic){
      if(*ic==' ') break;
      else drop_keep+=*ic;
    }
    // Skip more whitespace
    for(;ic!=ii->end();++ic){
      if(*ic!=' ') break;
    }
    // Get branchname
    for(;ic!=ii->end();++ic){
      if(*ic==' ') break;
      else branch_name+=*ic;
    }
    if(drop_keep=="drop" || drop_keep=="keep"){
      cmds.push_back(
          std::pair<bool,std::string>((drop_keep=="keep"),branch_name));
    }
    else
      throw std::invalid_argument("Invalid filter statement: '"+ *ii+"'");
  }

  if(sample.Get<std::string>("NtupleFormat")=="ICF"){
    ICF::NtupleData icf(sample.Get<std::string>("File"),
                        sample.Get<std::vector<std::string> >("FileList"),
                        sample.Get<std::string>("Name"),
                        0,0,1.);
    icf.FilterTree(cmds,
                   filter.Get<std::string>("OutputDir")+
                   sample.Get<std::string>("Name")+".root");
  }
  else throw std::invalid_argument("Ntuple format not supported");
}
} //~namespace Operation
