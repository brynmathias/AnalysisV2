#include "MC7to10.hh"
namespace Operation {
  //====================================
  // MC7to10 implementation
  //====================================

  MC7to10::MC7to10(const std::string & folderName) :
    mFolderName(folderName) {}

  MC7to10::~MC7to10() {}

  void MC7to10::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MC7to10::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    MC_WPtMuonAcc = new TH1D("MC_WPtMuonAcc",";gen W P_{T} given muon acceptance;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_WPtPlusMuonAcc = new TH1D("MC_WPtPlusMuonAcc",";gen W^{-} P_{T} given muon acceptance;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_WPtMinusMuonAcc = new TH1D("MC_WPtMinusMuonAcc",";gen W^{+} P_{T} given muon acceptance;Events / 100 pb^{-1}",1000,-0.5,999.5);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool MC7to10::Process(Event::Data & ev) {
    //already check that genW exists and decays to a muon
    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenMuon.at(0)->Pt() > 15.0 && fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()) < 2.1) {
      MC_WPtMuonAcc->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
      if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) MC_WPtPlusMuonAcc->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
      else MC_WPtMinusMuonAcc->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
    }
    return true;
  }

  std::ostream& MC7to10::Description(std::ostream &ostrm) {
    ostrm << "MC 7 to 10 TeV Sanity check plots";
    return ostrm;
  }
 
} // ~namespace Operation
