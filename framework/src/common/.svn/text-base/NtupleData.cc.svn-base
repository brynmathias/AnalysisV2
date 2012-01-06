/*! \file NtupleData.cc
 * \brief Source code for the NtupleData ntuple wrapper class.
 */

#include "NtupleData.hh"

//#include "Compute_Helpers.hh"
#include <cmath>
#include <string>
#include <stdexcept>

namespace Event{
// The only constructor
NtupleData::NtupleData(const std::string & fileName,
                       const std::vector<std::string> & fileList,
		       const std::string & dataSetName,
		       UInt_t lastEntry,
		       UInt_t firstEntry) :
    mDataPath(fileName),
    mDataSet(dataSetName),
    mEntry(firstEntry),
    mFirstEntry(firstEntry),
    mLastEntry(lastEntry),
    mFile(fileList.size() ? 0 : TFile::Open(mDataPath.c_str())),
    mChain(fileList.size() ? new TChain(NT_DIRNAME"/"NT_TREENAME) : 0),
    mDirectory(mChain ? 0 : (TDirectory *)mFile->Get(NT_DIRNAME)),
    mDataTree(mChain ? mChain : (TTree*)mDirectory->Get(NT_TREENAME))
{

  if(mChain){
    for(std::vector<std::string>::const_iterator it=fileList.begin();
        it!=fileList.end();
        ++it){
      mChain->Add(it->c_str());
    }
  }

  std::cout << "Total number of events in the ntuple = "
	    << mDataTree->GetEntries()
	    << std::endl;

  // Validate the maximum number of entries
  if ( mLastEntry == 0 ) {
    std::cout << "Setting mLastEntry to match input tree" << std::endl;
    if(mChain) mLastEntry = mChain->GetEntries() -1;
    else mLastEntry = mDataTree->GetEntries() - 1;
  } else if ( mLastEntry >= mDataTree->GetEntries() ) {
    throw std::invalid_argument("mLastEntry is greater than number of entries in tree");
  }

  // Validate the entry start position
  if ( mFirstEntry > mLastEntry ) {
    throw std::invalid_argument("mFirstEntry is greater than mLastEntry");
  }

  if(mChain){
    mChain->LoadTree(mFirstEntry);
    std::cout << "[CHAIN] At Entry: " << mFirstEntry << std::endl;
    std::cout << "[CHAIN] File: " << mChain->GetFile()->GetEndpointUrl()->GetFile()<<std::endl;
    mStopAfter  = mChain->GetTree()->GetEntries() ;
    mChainOffset = mChain->GetChainEntryNumber(0);
  }
  else{
    mChainOffset=0;
    mStopAfter=100000;
  }

  mUserEventWeight=(1/static_cast<float>(mLastEntry-mFirstEntry+1));

} // ~NtupleData constructor.

NtupleData::~NtupleData() {}

UInt_t NtupleData::GetCurrentEntry() const {
  return mEntry;
}

UInt_t NtupleData::GetFirstEntry() const {
  return mFirstEntry;
}

UInt_t NtupleData::GetLastEntry() const {
  return mLastEntry;
}

UInt_t NtupleData::GetTotalEntries() const {
  return mDataTree->GetEntries();
}

UInt_t NtupleData::GetChainOffSet() const {
  return mChainOffset;
}

NtupleData & NtupleData::operator++() {
  ++mEntry;
  if ( mEntry == mStopAfter ) {
    if(mChain && !(mChainOffset+mEntry==mLastEntry+1)){
      mChain->LoadTree(mChainOffset+mEntry);
      std::cout << "[CHAIN] At Entry: "
                << std::dec
                << mChainOffset + mEntry
                << std::endl;
      std::cout << "[CHAIN] File: "
                << mChain->GetFile()->GetEndpointUrl()->GetFile()
                << std::endl;
      for(std::vector<Event::_Element*>::iterator it=mElements.begin();
          it!=mElements.end();
          ++it){
        if((*it)->enabled()) (*it)->Reset();
      }
      mStopAfter=mChain->GetTree()->GetEntries();
      mChainOffset+=mEntry;
      mEntry = (0);
    }
    else if(!mChain){
      std::cout << "At entry "
                << std::dec
                << mEntry
                << std::endl;
      mStopAfter += 100000;
    }
  }
  return *this;
}

bool NtupleData::AtEnd() {
  if ( mChainOffset+mEntry == mLastEntry+1 ) return true;
  return false;
}

bool NtupleData::AtLast() {
  if ( mChainOffset+mEntry == mLastEntry ) return true;
  return false;
}

TTree* NtupleData::GetTree(){
  return mChain ? mChain : mDataTree;
}

void NtupleData::FilterTree(const std::vector<std::pair<bool,std::string> > & filter,
                            std::string out_name){

  for(std::vector< std::pair <bool,std::string> >::const_iterator ii=filter.begin();
      ii!=filter.end();++ii){
    std::cout << "FILTER: " << ii->first << " " << ii->second << std::endl;
    mDataTree->SetBranchStatus((ii->second).c_str(),ii->first ? 1 : 0);
    if(ii->first){
      TObjArray* arr= mDataTree->GetBranch(ii->second.c_str())->GetListOfBranches();

      if (arr->GetEntries()!=1) {
	for(int i=0;i<arr->GetEntries();++i){
	  TBranch* br=(TBranch*)arr->At(i);
	  mDataTree->SetBranchStatus(br->GetName(),1);
	  br->GetEntry(0);
	}
      } else {
	// metP4 type branches ...
	TBranch* br=(TBranch*)arr->At(0);
	TObjArray *ar = br->GetListOfBranches();
	for(int i=0;i<ar->GetEntries();++i){
	  TBranch* subbr=(TBranch*)ar->At(i);
	  //	  std::cout << "Br name = " << subbr->GetName() << std::endl;
	  mDataTree->SetBranchStatus(subbr->GetName(),1);
	  subbr->GetEntry(0);
	}
      }
	/*
	if (br->GetAddress()) {
	  filtered_tree->SetBranchAddress(br->GetName(),br->GetAddress());
	  }
	*/
      mDataTree->GetBranch(ii->second.c_str())->GetEntry(0);
    }
  }

  TFile *newfile=new TFile(out_name.c_str(),"recreate");
  newfile->mkdir(NT_DIRNAME);
  TDirectory* dir=(TDirectory*)newfile->Get(NT_DIRNAME);
  dir->cd();
  TTree *filtered_tree=mDataTree->CloneTree(0);
  if(!filtered_tree) throw std::invalid_argument("Error cloning tree");


  for(int i=0;i<mDataTree->GetEntries();++i){
    if(i%100000 == 0) std::cout << i << std::endl;
    mDataTree->GetEntry(i);
    filtered_tree->Fill();
  }

  filtered_tree->Write();
  filtered_tree->Print();
  filtered_tree->AutoSave();
  newfile->Close();
  delete newfile;
}

void NtupleData::Register(Event::_Element* ele){
  mElements.push_back(ele);
}

void NtupleData::Unregister(Event::_Element* ele){
  for(std::vector<Event::_Element*>::iterator ii=mElements.begin();
      ii!=mElements.end();
      ++ii){
    if(*ii==ele){
      mElements.erase(ii);
      break;
    }
  }
}
//-----------------------------------
// Public access to the ntuple data.
//-----------------------------------
const std::string & NtupleData::DataSet() { return mDataSet; }
const std::string & NtupleData::DataPath() { return mDataPath; }

TBranch* NtupleData::GetBranch(const std::string & name) const{
  if(mChain) return mChain->GetBranch(name.c_str());
  else return mDataTree->GetBranch(name.c_str());
}

}


