#include "GenerationPlots.hh"

namespace Operation {

  //====================================
  // JadGenOrigin implementation
  //====================================

  JadGenOrigin::JadGenOrigin(const std::string & folderName) :
    mFolderName(folderName) {}

  JadGenOrigin::~JadGenOrigin() {}
  
  void JadGenOrigin::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void JadGenOrigin::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    genOrigin = new TH1D("genOrigin", ";Type of Decay; Events", 5, -0.5, 4.5);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool JadGenOrigin::Process(Event::Data & ev) {

    GenMatrixBin myGenMatrixBin(&ev);
    if(myGenMatrixBin.the_GenW.size()) {
      if(myGenMatrixBin.the_GenEli.size() == 1) genOrigin->Fill(0.0, ev.GetEventWeight());
      else if(myGenMatrixBin.the_GenMuon.size() == 1) genOrigin->Fill(1.0, ev.GetEventWeight());
      else if(myGenMatrixBin.the_GenTau.size() == 1) genOrigin->Fill(2.0, ev.GetEventWeight());
      else genOrigin->Fill(3.0, ev.GetEventWeight());
    } else if(myGenMatrixBin.the_GenZ.size()) {
      if(myGenMatrixBin.the_GenEli.size() == 2) genOrigin->Fill(0.0, ev.GetEventWeight());
      else if(myGenMatrixBin.the_GenMuon.size() == 2) genOrigin->Fill(1.0, ev.GetEventWeight());
      else if(myGenMatrixBin.the_GenTau.size() == 2) genOrigin->Fill(2.0, ev.GetEventWeight());
      else genOrigin->Fill(3.0, ev.GetEventWeight());      
    } else genOrigin->Fill(4.0, ev.GetEventWeight());

    return true;
 }


  std::ostream& JadGenOrigin::Description(std::ostream &ostrm) {
    ostrm << "Check the origin of the leptons passing our selection using the generator level information";
    return ostrm;
  }
}
