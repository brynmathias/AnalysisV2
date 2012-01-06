#include "EffPlotsAGB.hh"

using namespace AGBTrig;

AGBTrigEffPlots::AGBTrigEffPlots(const Utils::ParameterSet& ps):
  _dirName(ps.Get<std::string>("DirName")),
  _TrigMHTcut(ps.Get<double>("MHTcut")),
  _JetPtThres(ps.Get<double>("JetPt"))
{}


AGBTrigEffPlots::~AGBTrigEffPlots() {}

void AGBTrigEffPlots::Start(Event::Data& ev){
  initDir(ev.OutputFile(), _dirName.c_str());
  BookHistos();
}

void AGBTrigEffPlots::BookHistos() {

  JetsPt = new TH1D("JetsPt","JetsPt",400,0,200);
  pfCommonMHT = new TH1D("pfCommonMHT","pfCommonMHT",390,0,130);
  pfCalcMHT = new TH1D("pfCalcMHT","pfCalcMHT",390,0,130);
  pfCommonMHT_postCut = new TH1D("pfCommonMHT_postCut","pfCommonMHT_postCut",390,0,130);
  pfGenMHT = new TH1D("pfGenMHT","pfGenMHT",390,0,130);
  pfGenMHT_postCut = new TH1D("pfGenMHT_postCut","pfGenMHT_postCut",390,0,130);
  matchedGenMHT = new TH1D("matchedGenMHT","matchedGenMHT",390,0,130);
  matchedGenMHT_postCut = new TH1D("matchedGenMHT_postCut","matchedGenMHT_postCut",390,0,130);
  pfGenMET = new TH1D("pfGenMET","pfGenMET",390,0,130);
  pfGenMET_postCut = new TH1D("pfGenMET_postCut","pfGenMET_postCut",390,0,130);
  pfMET = new TH1D("pfMET","pfMET",390,0,130);
  pfMET_postCut = new TH1D("pfMET_postCut","pfMET_postCut",390,0,130);
  CommonHT = new TH1D("CommonHT","CommonHT",500,0,500);
  CommonHT_postCut = new TH1D("CommonHT_postCut","CommonHT_postCut",500,0,500);
  
}


std::ostream& AGBTrigEffPlots::Description(std::ostream& ostm) {
  ostm << "AGB Trigger efficiencies";
  return ostm;
}



bool AGBTrigEffPlots::Process(Event::Data& ev){


  double w = ev.GetEventWeight();
  double MHTx = 0.;
  double MHTy = 0.;
  double matchedMHTx = 0.;
  double matchedMHTy = 0.;
  double HT = 0.;

  for(std::vector<Event::Jet>::const_iterator j =ev.JD_TerJets().begin(); j != ev.JD_TerJets().end(); ++j){
    if(j->Pt()>=40. && fabs(j->Eta())<3.){
      HT+=j->Et();
    }
  }

  for (std::vector<Event::Jet>::const_iterator j = ev.JD_Jets().begin(); j != ev.JD_Jets().end(); ++j){
    JetsPt->Fill(j->Pt(),w);
    if(j->Pt()>=5. && fabs(j->Eta())<2.5){
      MHTx -= j->Px();
      MHTy -= j->Py();
    }
    if(ev.genJetMatchIndex()->at(j - ev.JD_Jets().begin()) != -1){
      int ind = ev.genJetMatchIndex()->at(j - ev.JD_Jets().begin());
      matchedMHTx -= ev.genJetP4()->at(ind).Px();
      matchedMHTy -= ev.genJetP4()->at(ind).Py();
    }
  }

  double matchGenMHT = sqrt(matchedMHTx*matchedMHTx + matchedMHTy*matchedMHTy);

  matchedGenMHT->Fill(matchGenMHT,w);

  double genMHTx = 0.;
  double genMHTy = 0.;

  for (std::vector<ICF_LorentzV>::const_iterator i = ev.genJetP4()->begin(); i != ev.genJetP4()->end(); ++i){
    if(i->Pt()>=5. && fabs(i->Eta())<2.5){
      genMHTx -= i->Px();
      genMHTy -= i->Py();
    }
  }

  
  
  double MHT = sqrt(MHTx*MHTx + MHTy*MHTy);
  double genMHT = sqrt(genMHTx*genMHTx + genMHTy*genMHTy);

  pfCalcMHT->Fill(MHT,w);

  double commonMHT = ev.CommonMHT().Pt();
  double PFMET = ev.PFMET().Pt();
  double pfgenMET = ev.genMetP4PF()->Pt();
  double comHT = ev.CommonHT();

  pfCommonMHT->Fill(commonMHT,w);
  pfGenMHT->Fill(genMHT,w);
  pfMET->Fill(PFMET,w);
  pfGenMET->Fill(pfgenMET,w);
  CommonHT->Fill(comHT,w);
  
  

  if(MHT > _TrigMHTcut){
    pfMET_postCut->Fill(PFMET,w);
  
  pfCommonMHT_postCut->Fill(commonMHT,w);
  pfGenMHT_postCut->Fill(genMHT,w);
  matchedGenMHT_postCut->Fill(matchGenMHT,w);
  pfGenMET_postCut->Fill(pfgenMET,w);
  }

  if(HT>200.){
    CommonHT_postCut->Fill(comHT,w);
  }
  

  return true;

}
