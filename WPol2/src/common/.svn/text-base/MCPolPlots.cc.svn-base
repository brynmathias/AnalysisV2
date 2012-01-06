#include "MCPolPlots.hh"
namespace Operation {


  //====================================
  // MCPolPlots implementation
  //====================================

  MCPolPlots::MCPolPlots(const std::string & folderName) :
    mFolderName(folderName) {}

  MCPolPlots::~MCPolPlots() {}

  void MCPolPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MCPolPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    MC_MuonPt = new TH1D("MC_MuonPt", ";#mu P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_MuonEta =  new TH1D("MC_MuonEta",";#mu #eta;Events / 100 pb^{-1}",100, -5.5, 4.5);
    MC_MuonMultiplicity = new TH1D("MC_MuonMultiplicity", ";MC MuonExtra Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_MHT = new TH1D("MC_MHT", ";MHT;Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_ICVarPlus = new TH1D("MC_ICVarPlus",";IC Variable #mu^+;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus = new TH1D("MC_ICVarMinus",";IC Variable #mu^-;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_CosThetaStar1Sol1Plus = new TH1D("MC_CosThetaStar1Sol1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Sol1Minus = new TH1D("MC_CosThetaStar1Sol1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Sol2Plus = new TH1D("MC_CosThetaStar1Sol2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Sol2Minus = new TH1D("MC_CosThetaStar1Sol2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool MCPolPlots::Process(Event::Data & ev) {
    //the purpose of this class is to be able to look at cos theta* between a muon and virtual W, using the jet recoil (MHT)
    //as the substitute for W so we can look at a quantity we could measure from real data - and see what we'd expect from SUSY at MC level
    //that WAS the purpose of this class, now i'm using it as the closest estimate to the RECO plots using MC quantities. I only intend to run
    //over the ttbar and W samples so we can try to use this as a background estimation.

    GenMatrixBin myGenMatrixBin(&ev);
    TLorentzVector jJetSum;
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      //make the negative vector sum of all jets i.e. the MHT = W Pt - the pt>30GeV cut is made in the GenMatrixBin. Make the |eta|<3 cut here
      //if(fabs(myGenMatrixBin.the_GenJets.at(i)->Eta()) < 3.0) jJetSum -= (*(myGenMatrixBin.the_GenJets.at(i)));
      if(fabs(myGenMatrixBin.the_GenJets.at(i)->Eta()) < 3.0) jJetSum -= (TLVConvert(myGenMatrixBin.the_GenJets.at(i)));
      //jJetSum -= (*(myGenMatrixBin.the_GenJets.at(i)));
      //now do it like we do in reco, with a pt and eta cut on the individual jets going into the sum
      //if(myGenMatrixBin.the_GenJets.at(i)->Pt() > 30.0 && fabs(myGenMatrixBin.the_GenJets.at(i)->Eta() < 3.0) ) jJetSum2 -= (*(myGenMatrixBin.the_GenJets.at(i)));
    }

    MC_MHT->Fill(jJetSum.Pt(), ev.GetEventWeight());
    MC_MuonMultiplicity->Fill(myGenMatrixBin.the_GenMuonExtra.size(), ev.GetEventWeight());
    MC_MuonEta->Fill(myGenMatrixBin.the_GenMuonExtra.at(0)->Eta(), ev.GetEventWeight());
    MC_MuonPt->Fill(myGenMatrixBin.the_GenMuonExtra.at(0)->Pt(), ev.GetEventWeight());

    //jMCSol = FindBoost(*(myGenMatrixBin.the_GenMuonExtra.at(0)), jJetSum.Px(), jJetSum.Py(), 0.0, false);
    jMCSol = FindBoost(TLVConvert(myGenMatrixBin.the_GenMuonExtra.at(0)), jJetSum.Px(), jJetSum.Py(), 0.0, false);
    double ICVariable = ((myGenMatrixBin.the_GenMuonExtra.at(0)->Px() * jJetSum.Px()) + (myGenMatrixBin.the_GenMuonExtra.at(0)->Py() * jJetSum.Py())) / (jJetSum.Pt() * jJetSum.Pt());

    if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
      MC_ICVarPlus->Fill(ICVariable, ev.GetEventWeight());
    }else{
      MC_ICVarMinus->Fill(ICVariable, ev.GetEventWeight());
    }

    if(jMCSol.realSolutions) {
      if(myGenMatrixBin.the_GenMuonExtra.at(0)->GetID() < 0) {
	MC_CosThetaStar1Sol1Plus->Fill(jMCSol.sol1, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Plus->Fill(jMCSol.sol2, ev.GetEventWeight());
      }else{
	MC_CosThetaStar1Sol1Minus->Fill(jMCSol.sol1, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Minus->Fill(jMCSol.sol2, ev.GetEventWeight());
      }
    } else {
      //plot an "underflow" bin on these plots which will give an indication of the number of virtual solutions for each sample
      if(myGenMatrixBin.the_GenMuonExtra.at(0)->GetID() < 0) {
	MC_CosThetaStar1Sol1Plus->Fill(-1.2, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Plus->Fill(-1.2, ev.GetEventWeight());
      }else{
	MC_CosThetaStar1Sol1Minus->Fill(-1.2, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Minus->Fill(-1.2, ev.GetEventWeight());
      }
    }

    return true;
  }

  std::ostream& MCPolPlots::Description(std::ostream &ostrm) {
    ostrm << "Generator Polarisation plots";
    return ostrm;
  }

 
} // ~namespace Operation
