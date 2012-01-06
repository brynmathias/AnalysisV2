#include "ElCheckPlots.hh"
//originally written by Jad Marrouche, January 2011 onwards
namespace Operation {
  //====================================
  // ElCheckPlots implementation
  //====================================

  ElCheckPlots::ElCheckPlots(const std::string & folderName) :
    mFolderName(folderName) {}

  ElCheckPlots::~ElCheckPlots() {}

  void ElCheckPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void ElCheckPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    
    RECO_pfMET=new TH1D("RECO_pfMET","",1000,0.,500.);
    RECO_pfMETPlus=new TH1D("RECO_pfMETPlus","",1000,0.,500.);
    RECO_pfMETMinus=new TH1D("RECO_pfMETMinus","",1000,0.,500.);

    RECO_LeptonPt = new TH1D("RECO_LeptonPt", "", 1000,-0.5,999.5);
    RECO_LeptonPtPlus = new TH1D("RECO_LeptonPtPlus", "", 1000,-0.5,999.5);
    RECO_LeptonPtMinus = new TH1D("RECO_LeptonPtMinus", "", 1000,-0.5,999.5);
    RECO_LeptonEtaPlus =  new TH1D("RECO_LeptonEtaPlus","",100, -5.5, 4.5);
    RECO_LeptonEtaMinus =  new TH1D("RECO_LeptonEtaMinus","",100, -5.5, 4.5);
    RECO_LeptonEtaPlusAbs =  new TH1D("RECO_LeptonEtaPlusAbs","",100, -0.025, 4.975);
    RECO_LeptonEtaMinusAbs =  new TH1D("RECO_LeptonEtaMinusAbs","",100, -0.025, 4.975);

    RECO_ICVarPFPlus = new TH1D("RECO_ICVarPFPlus","",500,-2.5,2.5);
    RECO_ICVarPFMinus = new TH1D("RECO_ICVarPFMinus","",500,-2.5,2.5);

    RECO_TransMass = new TH1D("RECO_TransMass","",1000,-0.5,999.5);
    RECO_TransMassPlus = new TH1D("RECO_TransMassPlus","",1000,-0.5,999.5);
    RECO_TransMassMinus = new TH1D("RECO_TransMassMinus","",1000,-0.5,999.5);

    TH1::SetDefaultSumw2(kFALSE);

    RECO_lepEtavspfLP = new TH2D("RECO_lepEtavspfLP",";lepton #eta;LP",100,-5.5,4.5,1000,-5.0,5.0);
    RECO_lepEtavspfLPPlus = new TH2D("RECO_lepEtavspfLPPlus",";lepton #eta;LP",100,-5.5,4.5,1000,-5.0,5.0);
    RECO_lepEtavspfLPMinus = new TH2D("RECO_lepEtavspfLPMinus",";lepton #eta;LP",100,-5.5,4.5,1000,-5.0,5.0);

  }

  bool ElCheckPlots::Process(Event::Data & ev) {

    std::vector <Event::Lepton const *> theRECOLepton;
    
    //check if a (corrected) electron exists - otherwise return false and quit the plotting op.
    if(ev.LD_CommonElectrons().accepted.size()) theRECOLepton = ev.LD_CommonElectrons().accepted;
    else return false;

    LorentzV pfMHT, pfMET;
    //construct the proper pfMHT (which was generated with the raw electron in the first place)
    ICF_LorentzV raw_eli = (ev.electronP4()->at(theRECOLepton[0]->GetIndex()));
    pfMHT = ev.PFMET() + raw_eli;
    pfMET = ev.PFMET() + raw_eli - *(theRECOLepton[0]);

    RECO_pfMET->Fill(pfMET.Pt(), ev.GetEventWeight());
    RECO_LeptonPt->Fill(theRECOLepton.at(0)->Pt(), ev.GetEventWeight());

    double ICVariablePF = ((theRECOLepton.at(0)->Px() * pfMHT.Px()) + (theRECOLepton.at(0)->Py() * pfMHT.Py())) / (pfMHT.Pt() * pfMHT.Pt());
    double pfMT = sqrt(2.0 * pfMET.Pt() * theRECOLepton.at(0)->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), pfMET))));

    RECO_TransMass->Fill(pfMT, ev.GetEventWeight());
    RECO_lepEtavspfLP->Fill(theRECOLepton.at(0)->Eta(), ICVariablePF, ev.GetEventWeight());

    if(theRECOLepton.at(0)->GetCharge()>0.0) {
      RECO_LeptonPtPlus->Fill(theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
      RECO_LeptonEtaPlus->Fill(theRECOLepton.at(0)->Eta(), ev.GetEventWeight());
      RECO_LeptonEtaPlusAbs->Fill(fabs(theRECOLepton.at(0)->Eta()), ev.GetEventWeight());
      RECO_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight()); 
      RECO_TransMassPlus->Fill(pfMT, ev.GetEventWeight());
      RECO_pfMETPlus->Fill(pfMET.Pt(), ev.GetEventWeight());
      RECO_lepEtavspfLPPlus->Fill(theRECOLepton.at(0)->Eta(), ICVariablePF, ev.GetEventWeight());
    } else {
      RECO_LeptonPtMinus->Fill(theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
      RECO_LeptonEtaMinus->Fill(theRECOLepton.at(0)->Eta(), ev.GetEventWeight());
      RECO_LeptonEtaMinusAbs->Fill(fabs(theRECOLepton.at(0)->Eta()), ev.GetEventWeight());
      RECO_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight());
      RECO_TransMassMinus->Fill(pfMT, ev.GetEventWeight());
      RECO_pfMETMinus->Fill(pfMET.Pt(), ev.GetEventWeight());
      RECO_lepEtavspfLPMinus->Fill(theRECOLepton.at(0)->Eta(), ICVariablePF, ev.GetEventWeight());
    }

    return true;
  }

  std::ostream& ElCheckPlots::Description(std::ostream &ostrm) {
    ostrm << "Electron Channel Sanity Check Plots";
    return ostrm;
  }
 
} // ~namespace Operation
