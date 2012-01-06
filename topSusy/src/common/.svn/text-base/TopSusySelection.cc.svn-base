#include <fstream>
#include "TopSusySelection.hh"

namespace TopSusy {
  bool comparePt(TLorentzVector v1, TLorentzVector v2) {
    return v1.Pt() > v2.Pt();
  }

  bool compareLepPt(lepton l1, lepton l2) {
    return (l1.vector).Pt() > (l2.vector).Pt();
  }

  TopSusySelector::TopSusySelector(const std::string&   folderName,
                                   Utils::ParameterSet& pSet) :
                                   folderName_(folderName) {
    minNElecs = pSet.Get<int>   ("MinNElecs");
    minNMuons = pSet.Get<int>   ("MinNMuons");
    minNJets  = pSet.Get<int>   ("MinNJets");
    minHt     = pSet.Get<double>("MinHt");
    minMht    = pSet.Get<double>("MinMht");
    minElecEt = pSet.Get<double>("MinElecEt");
    minMuonPt = pSet.Get<double>("MinMuonPt");
    minJetPt  = pSet.Get<double>("MinJetPt");
  }

  TopSusySelector::~TopSusySelector() {}

  void TopSusySelector::BookHistos() {
    BookHistArray(h_nJets,    "h_nJets",    "",  6, -0.5,   5.5, N_CUTS, 0, 1, false);
    BookHistArray(h_met,      "h_met",      "", 25,  0.0, 250.0, N_CUTS, 0, 1, false);
    BookHistArray(h_wMt,      "h_wMt",      "", 25,  0.0, 250.0, N_CUTS, 0, 1, false);
    BookHistArray(h_m3,       "h_m3",       "", 45,  0.0, 750.0, N_CUTS, 0, 1, false);
    BookHistArray(h_elec1Et,  "h_elec1Et",  "", 20,  0.0, 200.0, N_CUTS, 0, 1, false);
    BookHistArray(h_jet1Pt,   "h_jet1Pt",   "", 40,  0.0, 400.0, N_CUTS, 0, 1, false);
    BookHistArray(h_elec1Eta, "h_elec1Eta", "", 20, -2.4,   2.4, N_CUTS, 0, 1, false);
  }

  void TopSusySelector::Start(Event::Data& data) {
    initDir(data.OutputFile(), folderName_.c_str());

    // Clear name components
    cutName.clear();

    // Clear maps
    nJetsMap.clear();
    metMap.clear();
    wMtMap.clear();
    m3Map.clear();
    elec1EtMap.clear();
    jet1PtMap.clear();
    elec1EtaMap.clear();

    BookHistos();
    createHistNames();
  }

  bool TopSusySelector::Process(Event::Data& data) {
    double                      elecMetDeltaPhi;
    TLorentzVector              mhtVector;
    std::vector<bool>           cuts;
    std::vector<TLorentzVector> jets;
    std::vector<lepton>         elecs, muons;

    passesCuts  = true;
    eventWeight = data.GetEventWeight();
    ht          = 0.0;
    met         = data.CaloMET().Et();
    wMt         = -9.9;
    m3          = -9.9;
    elec1Et     = -9.9;
    jet1Pt      = -9.9;
    elec1Eta    = -9.9;

    mhtVector.SetPxPyPzE(0.0, 0.0, 0.0, 0.0);

    for (uint i = 0; i < data.LD_Electrons().size(); i++) {
      double corrD0 = getCorrD0(data.GetElecD0(i), data.LD_Electrons()[i].Phi());

      double relIso = (data.LD_Electrons()[i].GetTrkIsolation()   +
                       data.LD_Electrons()[i].GetEcalIsolation()  +
                       data.LD_Electrons()[i].GetHcalIsolation()) /
                       data.LD_Electrons()[i].Et();

      TLorentzVector vec;

      vec.SetPxPyPzE(data.LD_Electrons()[i].Px(),
                     data.LD_Electrons()[i].Py(),
                     data.LD_Electrons()[i].Pz(),
                     data.LD_Electrons()[i].E());

      if (data.LD_Electrons()      [i].GetTightId() == 1                  &&
          data.LD_Electrons()      [i].Et()         >  minElecEt          &&
          (fabs(data.LD_Electrons()[i].Eta())       <  MAX_BARREL_ABS_ETA ||
          (fabs(data.LD_Electrons()[i].Eta())       >  MIN_ENDCAP_ABS_ETA &&
          fabs(data.LD_Electrons() [i].Eta())       <  MAX_ELEC_ABS_ETA)) &&
          fabs(corrD0)                              <  MAX_CORR_D0        &&
          relIso                                    <  MAX_ELEC_REL_ISO)
        elecs.push_back(lepton(data.LD_Electrons()[i].GetCharge(), vec));
    }

    for (uint i = 0; i < data.LD_Muons().size(); i++) {
      double corrD0 = getCorrD0(data.GetMuonCombD0(i), data.LD_Muons()[i].Phi());

      double relIso = (data.LD_Muons()[i].GetTrkIsolation()   +
                       data.LD_Muons()[i].GetEcalIsolation()  +
                       data.LD_Muons()[i].GetHcalIsolation()) /
                       data.LD_Muons()[i].Pt();

      TLorentzVector vec;

      vec.SetPxPyPzE(data.LD_Muons()[i].Px(),
                     data.LD_Muons()[i].Py(),
                     data.LD_Muons()[i].Pz(),
                     data.LD_Muons()[i].E());

      if (data.LD_Muons()     [i].GetTightId() == true             &&
          data.GetMuonTrkValidHits       (i)   >= MIN_N_HITS       &&
          data.LD_Muons()     [i].Pt()         >  minMuonPt        &&
          fabs(data.LD_Muons()[i].Eta())       <  MAX_MUON_ABS_ETA &&
          fabs(corrD0)                         <  MAX_CORR_D0      &&
          relIso                               <  MAX_MUON_REL_ISO &&
          data.GetMuonGlobalTrackNormChi2(i)   <  MAX_NORM_CHI_2)
        muons.push_back(lepton(data.LD_Muons()[i].GetCharge(), vec));
    }

    for (uint i = 0; i < data.JD_Jets().size(); i++) {
      bool passesJetElecDeltaR = true;

      TLorentzVector vec;

      vec.SetPxPyPzE(data.JD_Jets()[i].Px(),
                     data.JD_Jets()[i].Py(),
                     data.JD_Jets()[i].Pz(),
                     data.JD_Jets()[i].E());

      for (uint j = 0; j < elecs.size(); j++) {
        double jetElecDeltaPhi = getDeltaPhi(vec.Phi(), ((elecs.at(j)).vector).Phi());

        double jetElecDeltaR = sqrt((vec.Eta() - ((elecs.at(j)).vector).Eta()) *
                                    (vec.Eta() - ((elecs.at(j)).vector).Eta()) +
                                     jetElecDeltaPhi                           *
                                     jetElecDeltaPhi);

        passesJetElecDeltaR = passesJetElecDeltaR && jetElecDeltaR > MIN_JET_ELEC_DELTA_R;
      }

      if (vec.Pt()        > minJetPt        &&
          fabs(vec.Eta()) < MAX_JET_ABS_ETA &&
          passesJetElecDeltaR) {
        jets.push_back(vec);

        ht        += vec.Pt();
        mhtVector += -(vec);
      }
    }

    sort(elecs.begin(), elecs.end(), compareLepPt);
    sort(muons.begin(), muons.end(), compareLepPt);
    sort(jets.begin(),  jets.end(),  comparePt);

    nElecs = elecs.size();
    nMuons = muons.size();
    nJets  = jets.size();

    mht = mhtVector.Pt();

    if (minNElecs == 2 && elecs.size() >= 2)
      chargeProd = (elecs.at(0)).charge * (elecs.at(1)).charge;
    else if (minNElecs == 1 && minNMuons == 1 && elecs.size() >= 1 && muons.size() >= 1)
      chargeProd = (elecs.at(0)).charge * (muons.at(0)).charge;
    else if (minNMuons == 2 && muons.size() >= 2)
      chargeProd = (muons.at(0)).charge * (muons.at(1)).charge;

    if (elecs.size() >= 1) {
      elecMetDeltaPhi = getDeltaPhi(((elecs.at(0)).vector).Phi(), data.CaloMET().Phi());

      wMt = sqrt(2 * ((elecs.at(0)).vector).Et() * met * (1 - cos(elecMetDeltaPhi)));

      elec1Et  = ((elecs.at(0)).vector).Et();
      elec1Eta = ((elecs.at(0)).vector).Eta();
    }

    if (jets.size() >= 3) {
      double jetSumPt        = 0.0;
      double highestJetSumPt = 0.0;

      for (uint i = 0; i < jets.size() - 2; i++) {
        for (uint j = i + 1; j < jets.size() - 1; j++) {
          for (uint k = j + 1; k < jets.size(); k++) {
            jetSumPt = (jets.at(i) + jets.at(j) + jets.at(k)).Pt();

            if (jetSumPt > highestJetSumPt) {
              highestJetSumPt = jetSumPt;
              m3              = (jets.at(i) + jets.at(j) + jets.at(k)).M();
            }
          }
        }
      }
    }

    if (jets.size() >= 1)
      jet1Pt = (jets.at(0)).Pt();

    cuts.push_back(nElecs     >= minNElecs);
    cuts.push_back(nElecs     == minNElecs);
    cuts.push_back(nMuons     >= minNMuons);
    cuts.push_back(nMuons     == minNMuons);
    cuts.push_back(nJets      >= minNJets);
    cuts.push_back(ht         >  minHt && mht > minMht);
    cuts.push_back(chargeProd == 1.0);

    for (uint i = 0; i < cuts.size(); i++) {
      passesCuts = passesCuts && cuts.at(i);

      if (passesCuts) {
        nJetsMap   ["h_nJets_"    + cutName.at(i)]->Fill(nJets,    eventWeight);
        metMap     ["h_met_"      + cutName.at(i)]->Fill(met,      eventWeight);
        wMtMap     ["h_wMt_"      + cutName.at(i)]->Fill(wMt,      eventWeight);
        m3Map      ["h_m3_"       + cutName.at(i)]->Fill(m3,       eventWeight);
        elec1EtMap ["h_elec1Et_"  + cutName.at(i)]->Fill(elec1Et,  eventWeight);
        jet1PtMap  ["h_jet1Pt_"   + cutName.at(i)]->Fill(jet1Pt,   eventWeight);
        elec1EtaMap["h_elec1Eta_" + cutName.at(i)]->Fill(elec1Eta, eventWeight);
      }
    }

    return passesCuts;
  }

  std::ostream& TopSusySelector::Description(std::ostream& ostrm) {
    ostrm << "Selects top/SUSY events";

    return ostrm;
  }

  void TopSusySelector::createHistNames() {
    cutName.push_back("1_nElecs_geq_minNElecs");
    cutName.push_back("2_nElecs_eq_minNElecs");
    cutName.push_back("3_nMuons_geq_minNMuons");
    cutName.push_back("4_nMuons_eq_minNMuons");
    cutName.push_back("5_nJets_geq_minNJets");
    cutName.push_back("6_passesHtMhtCuts");
    cutName.push_back("7_passesSameSignCut");

    for (uint i = 0; i < cutName.size(); i++) {
      nJetsMap   ["h_nJets_"    + cutName.at(i)] = h_nJets.at   (i);
      metMap     ["h_met_"      + cutName.at(i)] = h_met.at     (i);
      wMtMap     ["h_wMt_"      + cutName.at(i)] = h_wMt.at     (i);
      m3Map      ["h_m3_"       + cutName.at(i)] = h_m3.at      (i);
      elec1EtMap ["h_elec1Et_"  + cutName.at(i)] = h_elec1Et.at (i);
      jet1PtMap  ["h_jet1Pt_"   + cutName.at(i)] = h_jet1Pt.at  (i);
      elec1EtaMap["h_elec1Eta_" + cutName.at(i)] = h_elec1Eta.at(i);

      nJetsMap   ["h_nJets_"    + cutName.at(i)]->SetName(("h_nJets_"    + cutName.at(i)).c_str());
      metMap     ["h_met_"      + cutName.at(i)]->SetName(("h_met_"      + cutName.at(i)).c_str());
      wMtMap     ["h_wMt_"      + cutName.at(i)]->SetName(("h_wMt_"      + cutName.at(i)).c_str());
      m3Map      ["h_m3_"       + cutName.at(i)]->SetName(("h_m3_"       + cutName.at(i)).c_str());
      elec1EtMap ["h_elec1Et_"  + cutName.at(i)]->SetName(("h_elec1Et_"  + cutName.at(i)).c_str());
      jet1PtMap  ["h_jet1Pt_"   + cutName.at(i)]->SetName(("h_jet1Pt_"   + cutName.at(i)).c_str());
      elec1EtaMap["h_elec1Eta_" + cutName.at(i)]->SetName(("h_elec1Eta_" + cutName.at(i)).c_str());
    }
  }

  double TopSusySelector::getCorrD0(double d0, double phi) {
    return d0 - BEAM_SPOT_X * sin(phi) + BEAM_SPOT_Y * cos(phi);
  }

  double TopSusySelector::getDeltaPhi(double phi1, double phi2) {
    if (phi1 - phi2 > PI)
      return fabs(phi1 - phi2 - 2 * PI);

    if (phi1 - phi2 < -1 * PI)
      return fabs(phi1 - phi2 + 2 * PI);

    return fabs(phi1 - phi2);
  }
}
