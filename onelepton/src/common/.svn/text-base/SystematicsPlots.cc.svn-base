#include "SystematicsPlots.hh"
#include "Functions.hh"
#include "GenObject.hh"

using namespace Operation;
namespace OneLepton{

SystematicsPlots::SystematicsPlots(const std::string & foldername,
                                   const Utils::ParameterSet & ps):
    folder_name_(foldername),
    polarisation_(ps.Get<bool>("Polarisation")),
    resolution_(ps.Get<bool>("METResolution")),
    lepton_(ps.Get<std::string>("Lepton"))
{
  if(lepton_ == "Muon") lepton_type_ = MUON;
  else if(lepton_ == "Electron") lepton_type_ = ELECTRON;
  else throw std::invalid_argument("Invalid Lepton: "+ lepton_);
}

SystematicsPlots::~SystematicsPlots(){}

void SystematicsPlots::Start(Event::Data & ev){
  initDir(ev.OutputFile(), folder_name_.c_str());
  MC_RECO_pfMETRes_genMHT = new TH2D("MC_RECO_pfMETRes_genMHT", "MC_RECO_pfMETRes_genMHT",
                                  100, 0, 1000, 100, -5.05, 4.95);
  MC_WPt_Y_CosThetaStarPlus = new TH3D("MC_WPt_Y_CosThetaStarPlus", "MC_WPt_Y_CosThetaStarPlus",
                                   100, 0, 1000, 50, 0, 10, 300, -1.5, 1.5);
  MC_WPt_Y_CosThetaStarMinus = new TH3D("MC_WPt_Y_CosThetaStarMinus", "MC_WPt_Y_CosThetaStarMinus",
                                   100, 0, 1000, 50, 0, 10, 300, -1.5, 1.5);

}

void SystematicsPlots::Polarisation(Event::Data & ev){
  const Event::GenObject* genW;
  const Event::GenObject* genLep;
  const Event::GenObject* genNu;

  if(!ev.GenMatrix().hasW()) return;
  genW = ev.GenMatrix().w();

  if(ev.GenMatrix().hasElectron()){
    genLep = ev.GenMatrix().electron();
    genNu = ev.GenMatrix().electronNu();
  }
  else if(ev.GenMatrix().hasMuon()){
    genLep = ev.GenMatrix().muon();
    genNu = ev.GenMatrix().muonNu();
  }
  else if(ev.GenMatrix().hasTau()){
    genLep = ev.GenMatrix().tau();
    genNu = ev.GenMatrix().tauNu();
  }

  TLorentzVector genLepTLV = TLVConvert(genLep);
  jSolutionsW mcsolw = FindBoost(genLepTLV, genW->Px(), genW->Py(),
                                 genW->Pz(), true, false, genW->M());
  if(mcsolw.realSolutions){
    if(genLep->GetID() > 0) MC_WPt_Y_CosThetaStarMinus->Fill(genW->Pt(), genW->Rapidity(), mcsolw.rightSol);
    else MC_WPt_Y_CosThetaStarPlus->Fill(genW->Pt(), genW->Rapidity(), mcsolw.rightSol);
  }

}

void SystematicsPlots::METResolution(Event::Data & ev){
  const LorentzV* genLep;
  LorentzV genMHT = *genLep + *ev.genMetP4PF();
  const LorentzV* recoLep;
  LorentzV wpt = ev.PFMET() + *recoLep;

  if(lepton_type_ == MUON){
    if(!ev.LD_CommonMuons().accepted.size()) return;
    recoLep = ev.LD_CommonMuons().accepted[0];

    if(ev.GenMatrix().hasMuon() && !ev.GenMatrix().hasTau())
        genLep = ev.GenMatrix().muon();
    else if(ev.GenMatrix().hasTau() && !ev.GenMatrix().hasMuon())
      genLep = ev.GenMatrix().tau();
    else return;
  }
  else if(lepton_type_ == ELECTRON){
    if(!ev.LD_CommonElectrons().accepted.size()) return;
    recoLep = ev.LD_CommonElectrons().accepted[0];

    if(ev.GenMatrix().hasElectron() && !ev.GenMatrix().hasTau())
      genLep = ev.GenMatrix().electron();
    else if(ev.GenMatrix().hasTau() && !ev.GenMatrix().hasElectron())
      genLep = ev.GenMatrix().tau();
    else return;
  }

  if(genMHT.Pt() > 0)
    MC_RECO_pfMETRes_genMHT->Fill(genMHT.Pt(), (genMHT.Pt() - wpt.Pt())/genMHT.Pt(),
                                  ev.GetEventWeight());
}

bool SystematicsPlots::Process(Event::Data & ev){
  if(polarisation_) Polarisation(ev);
  if(resolution_) METResolution(ev);
  return true;
}

std::ostream & SystematicsPlots::Description(std::ostream & ostrm){
  ostrm << "SystematicsPlots";
  return ostrm;
}

}

