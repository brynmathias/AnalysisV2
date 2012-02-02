#include "Trigger.hh"
#include "Types.hh"
#include "Vars.hh"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <TDirectory.h>
#include <TFile.h>
#include <TH2D.h>

using namespace allhadronic;

// -----------------------------------------------------------------------------
//
Trigger::Trigger( const Utils::ParameterSet& ps ) :
  algos_(ps),
  triggers_(),
  verbose_(false),
  filters_(),
  vs_(0),
  file_(0)
{
  if ( ps.Contains("Verbose") ) verbose_ = ps.Get<bool>("Verbose");
  if ( ps.Contains("Filters") ) filters_ = ps.Get< std::vector<std::string> >("Filters"); 
  // 0=Prescales, 1=RunNumber(z=Nevents), 2=RunNumber(z=Prescales)...
  if ( ps.Contains("Versus") ) vs_ = ps.Get<int>("Versus");
}

// -----------------------------------------------------------------------------
//
void Trigger::Start( Event::Data& ev ) {}

// -----------------------------------------------------------------------------
//
void Trigger::End( Event::Data& ev ) {

  file_ = ev.OutputFile();
  file_->cd();
  TDirectory* dir = file_->mkdir("Triggers");
  dir->cd();

  if ( vs_ == 0 ) {
  
    TH2D* his = new TH2D( "TriggersVsPrescales", 
			  ";;Prescales", 
			  triggers_.size(), 0., triggers_.size(),
			  10000, 0., 10000. );
    his->Sumw2();
  
    std::stringstream ss;
    ss << "[Trigger::~Trigger]"
       << " List of " << triggers_.size()
       << " triggers matching the specified filters that fired"
       << std::endl;
    Algorithms::Triggers::const_iterator ii = triggers_.begin();
    Algorithms::Triggers::const_iterator jj = triggers_.end();
    for ( ; ii != jj; ++ii ) {
      ss << " Trigger \"" << ii->first << "\""
	 << std::endl;
      Algorithms::Prescales::const_iterator iii = ii->second.begin();
      Algorithms::Prescales::const_iterator jjj = ii->second.end();
      for ( ; iii != jjj; ++iii ) {
	his->Fill(ii->first.c_str(),iii->first*1.,iii->second*1.);
	ss << "  Prescale: " << iii->first
	   << " Events: " << iii->second
	   << std::endl;
      }    
    }
    std::cout << ss.str() << std::endl;
  
    his->Write();

  }

  else if ( vs_ == 1 || vs_ == 2 ) {
    
    // Cache runs used
    std::vector<int> runs;
    Algorithms::Triggers::const_iterator ii1 = triggers_.begin();
    Algorithms::Triggers::const_iterator jj1 = triggers_.end();
    for ( ; ii1 != jj1; ++ii1 ) {
      Algorithms::Prescales::const_iterator iii1 = ii1->second.begin();
      Algorithms::Prescales::const_iterator jjj1 = ii1->second.end();
      for ( ; iii1 != jjj1; ++iii1 ) {
	if ( iii1->second > 0 ) { 
	  if ( find( runs.begin(), runs.end(), iii1->first ) == runs.end() ) {
	    runs.push_back( iii1->first );
	  }
	}
      }    
    }
    
    TH2D* his = new TH2D( "TriggersVsRunNumber", 
			  ";;Run number", 
			  triggers_.size(), 0., triggers_.size(),
			  runs.size(), 0., runs.size() );
    his->Sumw2();
  
    std::stringstream ss;
    ss << "[Trigger::~Trigger]"
       << " List of " << triggers_.size()
       << " triggers (and their prescales) matching the filters that fired"
       << std::endl;
    Algorithms::Triggers::const_iterator ii = triggers_.begin();
    Algorithms::Triggers::const_iterator jj = triggers_.end();
    for ( ; ii != jj; ++ii ) {
      ss << " Trigger (and prescale) \"" << ii->first << "\""
	 << std::endl;
      Algorithms::Prescales::const_iterator iii = ii->second.begin();
      Algorithms::Prescales::const_iterator jjj = ii->second.end();
      for ( ; iii != jjj; ++iii ) {
	std::stringstream run; run << iii->first;
	his->Fill(ii->first.c_str(),run.str().c_str(),iii->second*1.);
	ss << "  RunNumber: " << iii->first
	   << ( vs_==2 ? " Prescales: " : " Events: " ) << iii->second
	   << std::endl;
      }    
    }
    std::cout << ss.str() << std::endl;

    his->LabelsOption("a","Y");
    his->Write();
    
  }
  
}

// -----------------------------------------------------------------------------
//
bool Trigger::Process( Event::Data& ev ) {
  Algorithms::Names fired;
  algos_.triggers( ev, filters_, fired );
  algos_.triggers( ev, fired, triggers_, vs_ ); 
  return true;
}

// -----------------------------------------------------------------------------
//
std::ostream& Trigger::Description( std::ostream& ss ) { return ss; }
