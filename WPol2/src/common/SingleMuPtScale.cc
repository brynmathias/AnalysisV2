#include "SingleMuPtScale.hh"

//====================================
// SingleMuPtScale implementation
//====================================

namespace Operation {
  SingleMuPtScale::SingleMuPtScale(const std::string & folderName) :
    mFolderName(folderName) {}

  SingleMuPtScale::~SingleMuPtScale() {}

  void SingleMuPtScale::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void SingleMuPtScale::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    plusmuonstree = new TTree("plusmuonstree","plusmuonstree");
    plusmuonstree->Branch("RecoPt",&RecoPt,"RecoPt/D") ;
    plusmuonstree->Branch("RecoEta",&RecoEta,"RecoEta/D") ;
    plusmuonstree->Branch("RecoPhi",&RecoPhi,"RecoPhi/D") ;
    plusmuonstree->Branch("MCPt",&MCPt,"MCPt/D") ;
    plusmuonstree->Branch("MCEta",&MCEta,"MCEta/D") ;
    plusmuonstree->Branch("MCPhi",&MCPhi,"MCPhi/D") ;
    plusmuonstree->Branch("EvWeight",&EvWeight,"EvWeight/D");

    minusmuonstree = new TTree("minusmuonstree","minusmuonstree");
    minusmuonstree->Branch("RecoPt",&RecoPt,"RecoPt/D") ;
    minusmuonstree->Branch("RecoEta",&RecoEta,"RecoEta/D") ;
    minusmuonstree->Branch("RecoPhi",&RecoPhi,"RecoPhi/D") ;
    minusmuonstree->Branch("MCPt",&MCPt,"MCPt/D") ;
    minusmuonstree->Branch("MCEta",&MCEta,"MCEta/D") ;
    minusmuonstree->Branch("MCPhi",&MCPhi,"MCPhi/D") ;
    minusmuonstree->Branch("EvWeight",&EvWeight,"EvWeight/D");


    TH1::SetDefaultSumw2(kFALSE);
  }

  bool SingleMuPtScale::Process(Event::Data & ev) {


 GenMatrixBin myGenMatrixBin(&ev);

 if (!myGenMatrixBin.the_GenMuonExtra.size()) return false;

for (int i=0;i<myGenMatrixBin.the_GenMuonExtra.size();i++) {
      bool matchfound=false;
      int match=0;
      double DeltaR_MCRECO_Muon;
      double bestDR=1000;
      int j;
      int charge;
      //      CHECK_TIPO_MUONI;
      //      ev.LD_CommonMuons().accepted.at(0)->GetCharge()
      //      ev.LD_Muons()
      for (j=0; j<ev.LD_CommonMuons().accepted.size(); j++) {
        DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*(ev.LD_CommonMuons().accepted.at(j)),*(myGenMatrixBin.the_GenMuonExtra.at(i)));
        if (DeltaR_MCRECO_Muon < bestDR) {bestDR=DeltaR_MCRECO_Muon; match=j;}
      }
      if(bestDR<0.1) {matchfound=true;}
      if (matchfound){
	RecoPt = (ev.LD_CommonMuons().accepted.at(match))->Pt();
	RecoEta = (ev.LD_CommonMuons().accepted.at(match))->Eta();
	RecoPhi= (ev.LD_CommonMuons().accepted.at(match))->Phi();
	MCPt = (*(myGenMatrixBin.the_GenMuonExtra.at(i))).Pt();
	MCEta = (*(myGenMatrixBin.the_GenMuonExtra.at(i))).Eta();
	MCPhi = (*(myGenMatrixBin.the_GenMuonExtra.at(i))).Phi();
	EvWeight = ev.GetEventWeight();
	charge = (ev.LD_CommonMuons().accepted.at(match))->GetCharge();
	if (charge==1) plusmuonstree->Fill();
	else if (charge==-1) minusmuonstree->Fill();
      }

    }


    return true;
  }


  std::ostream& SingleMuPtScale::Description(std::ostream &ostrm) {
    ostrm << "Plotting routines for misalignment studies with Z";
    return ostrm;
  }
}
