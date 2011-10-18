#ifndef FILLANALYSISTREE_hh
#define FILLANALYSISTREE_hh

#include "Operation.hh"
#include "NtupleData.hh"
#include "EventData.hh"
#include "PlottingBase.hh"

#include <iostream>

using namespace Event;
//using namespace EventStuff;

namespace LeptonCommissioning{

class FillAnalysisTree : public Operation::_Base
{

public:
  FillAnalysisTree(const std::string & folderName, UInt_t ty);
  ~FillAnalysisTree();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream& Description(std::ostream& ostrm);
  Double_t Meff;
  Double_t AlphaT;
  Double_t MHT;
  Double_t HT;
  Double_t DHT;
  Double_t J1_Et;
  Double_t J2_Et;
  Double_t J1_Eta;
 Double_t ABS_J1_Eta;
  Double_t LepPT;
  Double_t LepEta;
  UInt_t Njet;
  Double_t EvtWeight;
  Double_t CombIso;
  Double_t NormIso;
  Double_t TrkIso;
  Double_t HIso;
  Double_t EIso;
 
  Double_t Type;
  Double_t MotherType;
  TFile* anaTFile;
  TTree* anaTTree;


private:
 const std::string mFolderName;
  UInt_t mType;
};
}
#endif 
