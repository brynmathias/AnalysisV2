#include "JECUncPlots.hh"
namespace Operation {
  //====================================
  // JECUncPlots implementation
  //====================================

  JECUncPlots::JECUncPlots(const std::string & folderName) :
    mFolderName(folderName) {}

  JECUncPlots::~JECUncPlots() {}

  void JECUncPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void JECUncPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    MHTeffect = new TH1D("MHTeffect", ";scaledMHT / originalMHT;Events",2000, -0.005, 1.995);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool JECUncPlots::Process(Event::Data & ev) {
    //already check that genW exists and decays to a muon
//     GenMatrixBin myGenMatrixBin(&ev);
//     if(myGenMatrixBin.the_GenMuon.at(0)->Pt() > 15.0 && fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()) < 2.1) {
//       MC_WPtMuonAcc->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
//       if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) MC_WPtPlusMuonAcc->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
//       else MC_WPtMinusMuonAcc->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
//     }
    //JetCorrectionUncertainty jecUnc("Spring10_Uncertainty_AK5PF.txt");
    JetCorrectionUncertainty jecUnc("GR_R_38X_V15_AK5PF_Uncertainty.txt");

    double unc = 0.0;
    Event::Lepton const * theRECOLepton;
    LorentzV pfUnclustered, scaledjets;
    theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
    pfUnclustered = ev.PFMET() + *(theRECOLepton);

    //std::cout << "pfMHT: " << pfUnclustered.Pt() << std::endl;
    double initialMHT = pfUnclustered.Pt();
    for(unsigned int i=0; i< ev.JD_Jets().size(); i++) {
      if(ev.JD_Jets().at(i).Pt() > 10.0) {
	jecUnc.setJetEta(ev.JD_Jets().at(i).Eta());
	jecUnc.setJetPt(ev.JD_Jets().at(i).Pt());
	unc = jecUnc.getUncertainty(true);
	//std::cout << "jet " << i << " pt: " << ev.JD_Jets().at(i).Pt() << " eta: " << ev.JD_Jets().at(i).Eta() << " uncertainty: " << unc << std::endl;
	pfUnclustered += (ev.JD_Jets().at(i));
	LorentzV myscaledjet = ev.JD_Jets().at(i) * (1.0 + unc);
	if(i==0) scaledjets = -myscaledjet;
	else scaledjets -=myscaledjet;
      }
    }
    //std::cout << "unclustered Pt: " << pfUnclustered.Pt() << std::endl;
    pfUnclustered *= 1.05;
    pfUnclustered += scaledjets;
    //std::cout << "scaled pfMHT: " << pfUnclustered.Pt() << std::endl;
    double finalMHT = pfUnclustered.Pt();

    MHTeffect->Fill(finalMHT/initialMHT, ev.GetEventWeight());


    return true;
  }

  std::ostream& JECUncPlots::Description(std::ostream &ostrm) {
    ostrm << "JEC Uncertainty Plots";
    return ostrm;
  }
 
} // ~namespace Operation
