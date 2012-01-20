#include "JECUnc2DPlots.hh"
namespace Operation {
  //====================================
  // JECUnc2DPlots implementation
  //====================================

  JECUnc2DPlots::JECUnc2DPlots(const std::string & folderName) :
    mFolderName(folderName) {}

  JECUnc2DPlots::~JECUnc2DPlots() {}

  void JECUnc2DPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void JECUnc2DPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    RECO_ICVarPFPlus = new TH1D("RECO_ICVarPFPlus",";LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus = new TH1D("RECO_ICVarPFMinus",";LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_vs_JECUncSigma = new TH2D("RECO_ICVarPFPlus_vs_JECUncSigma","; LP(#mu^{+}); JEC Unc Sigma",500,-2.5,2.5,21,-1.05,1.05);
    RECO_ICVarPFMinus_vs_JECUncSigma = new TH2D("RECO_ICVarPFMinus_vs_JECUncSigma","; LP(#mu^{-});JEC Unc Sigma",500,-2.5,2.5,21,-1.05,1.05);
    TH1::SetDefaultSumw2(kFALSE);

  }

  bool JECUnc2DPlots::Process(Event::Data & ev) {

    for(unsigned int i=0; i<21;i++) {
      double sigma_step = (0.10 * i) - 1.00; //in order to get -1.00, -0.90, -0.80 etc

      JetCorrectionUncertainty jecUnc("GR_R_38X_V15_AK5PF_Uncertainty.txt");

      double unc = 0.0;
      Event::Lepton const * theRECOLepton;
      LorentzV pfUnclustered, scaledjets;
      theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
      pfUnclustered = ev.PFMET() + *(theRECOLepton);

      for(unsigned int i=0; i< ev.JD_Jets().size(); i++) {
	if(ev.JD_Jets().at(i).Pt() > 10.0) {
	  jecUnc.setJetEta(ev.JD_Jets().at(i).Eta());
	  jecUnc.setJetPt(ev.JD_Jets().at(i).Pt());
	  unc = jecUnc.getUncertainty(true);
	  //std::cout << "jet " << i << " pt: " << ev.JD_Jets().at(i).Pt() << " eta: " << ev.JD_Jets().at(i).Eta() << " uncertainty: " << unc << std::endl;
	  pfUnclustered += (ev.JD_Jets().at(i));
	  LorentzV myscaledjet = ev.JD_Jets().at(i) * (1.0 + (sigma_step*unc));
	  if(i==0) scaledjets = -myscaledjet;
	  else scaledjets -=myscaledjet;
	}
      }

      pfUnclustered *= (1.0 + (sigma_step*0.05));
      pfUnclustered += scaledjets;

      //finally, add the lepton back into the calculation - this is the "new" MET:
      pfUnclustered -= *(theRECOLepton);

      //now we construct the pfMHT and pfMT values, and cut on them > 50, >30 respectively.
      double newMHT = (pfUnclustered + *(theRECOLepton)).Pt();
      double newMT = sqrt(2.0 * pfUnclustered.Pt() * theRECOLepton->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*theRECOLepton, pfUnclustered))));
      //if we pass these cuts, then construct the LP (hardcode cut values for now)
      if(newMHT > 50.0 && newMT > 30.0) {
	LorentzV pfMET;
	pfMET = pfUnclustered + *(theRECOLepton);
	double ICVariablePF = ((theRECOLepton->Px() * pfMET.Px()) + (theRECOLepton->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());

	if(theRECOLepton->GetCharge()>0.0) {
	  if(sigma_step == 0.0) RECO_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight()); //for the 1D nominal histogram
	  RECO_ICVarPFPlus_vs_JECUncSigma->Fill(ICVariablePF, sigma_step, ev.GetEventWeight());
	} else {
	  if(sigma_step == 0.0) RECO_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight()); //for the 1D nominal histogram
	  RECO_ICVarPFMinus_vs_JECUncSigma->Fill(ICVariablePF,sigma_step, ev.GetEventWeight());
	}

      }
      
    }

    return true;
  }

  std::ostream& JECUnc2DPlots::Description(std::ostream &ostrm) {
    ostrm << "JEC Uncertainty effect on LP vs step in sigma of JEC Uncertainty";
    return ostrm;
  }
 
} // ~namespace Operation
