#include "FillAnalysisTree.hh"
#include <iostream>
//#include <fstream>
#include "Math/VectorUtil.h"
//#include "GenMatrixBin.hh"
#include "EventData.hh"
#include "Photon.hh"
#include "Lepton.hh"
#include "Jet.hh"
#include <sstream>
#include "TString.h"

//using namespace std;
//using namespace Combinations;

namespace LeptonCommissioning{


  FillAnalysisTree::FillAnalysisTree(const std::string & folderName, UInt_t ty):mFolderName(folderName),
										mType(ty)
{}

  void FillAnalysisTree::Start(Event::Data & ev){
  cout << "Constructor AnalysisSkim booking a tree for analysis output "<<endl;
  anaTFile = ev.OutputFile();
       // TString name = mFileName + "_SLVariables.root";
       // anaTFile = new TFile(name,"recreate");

     TDirectory* anaDir =anaTFile->mkdir(mFolderName.c_str());
 

       anaDir->cd();
      anaTTree=new TTree("LeptonicVars","test");
      cout << "Constructor AnalysisSkim" <<endl;



      anaTTree->Branch("Meff", &Meff, "Meff/double");
      anaTTree->Branch("AlphaT", &AlphaT, "AlphaT/double");
       anaTTree->Branch("MHT", &MHT, "MHT/double");
      anaTTree->Branch("HT", &HT, "HT/double");


      anaTTree->Branch("LepPT",&LepPT,"LepPT/double");
      anaTTree->Branch("LepEta",&LepEta,"LepEta/double");
      anaTTree->Branch("Njet",&Njet,"Njet/int");
      anaTTree->Branch("J1_Et",&J1_Et,"J1_Et/double");
      anaTTree->Branch("J2_Et",&J2_Et,"J2_Et/double");
      anaTTree->Branch("DHT",&DHT,"DHT/double");
      anaTTree->Branch("J1_Eta",&J1_Eta,"J1_Eta/double");
      anaTTree->Branch("ABS_J1_Eta",&ABS_J1_Eta,"ABS_J1_Eta/double");
      anaTTree->Branch("EvtWeight",&EvtWeight,"EvtWeight/double");


 anaTTree->Branch("HIso",&HIso,"HIso/double");
 anaTTree->Branch("EIso",&EIso,"EIso/double");

      anaTTree->Branch("CombIso",&CombIso,"CombIso/double");
 anaTTree->Branch("TrkIso",&CombIso,"CombIso/double");
 anaTTree->Branch("NormIso",&CombIso,"CombIso/double");


 anaTTree->Branch("Type",&Type,"Type/double");

 anaTTree->Branch("MotherType",&MotherType,"MotherType/int");
  }



FillAnalysisTree::~FillAnalysisTree() {
  cout << "shiney" << endl;
    cout << "Writing an analysis tree"<<endl; 
    anaTFile->cd(); 
    anaTFile->Write();
    anaTFile->Close();
  

}



 bool FillAnalysisTree::Process(Event::Data & ev)

{
  Type = mType;
 Meff = ev.CommonMeff();
 Njet = ev.JD_CommonJets().accepted.size();
 if(Njet > 0){
    J1_Et = ev.JD_CommonJets().accepted[0]->Et();
    J1_Eta = ev.JD_CommonJets().accepted[0]->Eta();
    ABS_J1_Eta = fabs(ev.JD_CommonJets().accepted[0]->Eta());

    if(Njet >1){
      J2_Et = ev.JD_CommonJets().accepted[1]->Et();
    }
 }

 if(ev.CommonObjects().size()<7. && ev.CommonObjects().size()>1.){
 AlphaT = ev.CommonAlphaT();
 DHT = ev.CommonMinDEt();
 }
 
  HT = ev.CommonSumEt();
  MHT = ev.CommonMHT().Pt();


  
 
 
  EvtWeight = ev.GetEventWeight();
 

  // cout <<"mtype is  " <<  mType << endl;
  

  if (mType ==1){
  if (ev.LD_CommonElectrons().accepted.size() >= 1){

    int iMatch = ev.leptonMatch(const_cast<Lepton*>(ev.LD_CommonElectrons().accepted[0]),1);
    MotherType = ev.leptonType( iMatch);

    //cout << ev.LD_CommonElectrons().accepted[0]->GetCombIsolation() << '\t' << ev.LD_CommonElectrons().accepted[0]->GetTrkIsolation() << endl;
    LepPT = ev.LD_CommonElectrons().accepted[0]->Pt();
    LepEta = ev.LD_CommonElectrons().accepted[0]->Eta();
    CombIso = ev.LD_CommonElectrons().accepted[0]->GetCombIsolation();
 TrkIso = ev.LD_CommonElectrons().accepted[0]->GetTrkIsolation();
 NormIso = 1 / (1+ ev.LD_CommonElectrons().accepted[0]->GetCombIsolation());
 HIso = ev.LD_CommonElectrons().accepted[0]->GetHcalIsolation();
 EIso = ev.LD_CommonElectrons().accepted[0]->GetEcalIsolation();


  }
  }
  else if (mType ==2){
  if (ev.LD_CommonMuons().accepted.size() >=1){
  int iMatch = ev.leptonMatch(const_cast<Lepton*>(ev.LD_CommonMuons().accepted[0]),2);
    MotherType = ev.leptonType( iMatch);
    LepPT = ev.LD_CommonMuons().accepted[0]->Pt();
    LepEta = ev.LD_CommonMuons().accepted[0]->Eta();
 CombIso = ev.LD_CommonMuons().accepted[0]->GetCombIsolation();
 TrkIso = ev.LD_CommonMuons().accepted[0]->GetTrkIsolation();
 NormIso = 1 / (1+ ev.LD_CommonMuons().accepted[0]->GetCombIsolation());
  }}
  
  else {
    cout << " ERROR: SingleLep Tree has wrong argument " << endl;

  }
 

  
  anaTTree->Fill();
 
  return true;
}







  std::ostream& FillAnalysisTree::Description(std::ostream &ostrm) {
   ostrm << "Filled Analysis tree ";
   return ostrm;
   }
}
