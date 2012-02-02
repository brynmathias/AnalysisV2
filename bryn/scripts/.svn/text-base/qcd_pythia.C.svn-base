#include "TDirectory.h"
#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include <string>
#include <vector>

void merged() {
  
  std::vector<std::string> files;
  files.push_back("QCDJets_Pythia_15.root");
  files.push_back("QCDJets_Pythia_30.root");
  files.push_back("QCDJets_Pythia_80.root");
  files.push_back("QCDJets_Pythia_170.root");
  files.push_back("QCDJets_Pythia_300.root");
  files.push_back("QCDJets_Pythia_470.root");
  files.push_back("QCDJets_Pythia_800.root");
  files.push_back("QCDJets_Pythia_1400.root");
  
  for ( int i = 0; i < files.size(); ++i ) {
    TFile* f = new TFile(std::string(files[i]).c_str(),"READ");
    if ( f ) {
      TDirectory* d = (TDirectory*)f->Get("susyTree");
      if ( d ) {
	TTree* t = (TTree*)d->Get("tree");
	if ( t ) {
	  std::cout << " TFile: " << files[i] 
		    << " Entries: " << t->GetEntries() 
		    << std::endl;
	} else {
	  std::cout << " NULL TTree ptr!" << std::endl;
	}
      } else {
	std::cout << " NULL TDirectory ptr!" << std::endl;
      }
      f->Close();
      delete f;
    } else {
      std::cout << " NULL TFile ptr!" << std::endl;
    }
  }
}


