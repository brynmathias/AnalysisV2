#include <fstream>
#include "JetTriggerSelection.hh"

bool comparePtJets(TLorentzVector v1, TLorentzVector v2) {
  return v1.Pt() > v2.Pt();
}

namespace TopSusy {
  JetTriggerSelector::JetTriggerSelector(const std::string&   folderName,
                                         Utils::ParameterSet& pSet) :
                                         folderName_(folderName) {
    minNJets    = pSet.Get<int>        ("MinNJets");
    minJetPt    = pSet.Get<double>     ("MinJetPt");
    initTrigBit = pSet.Get<std::string>("InitTrigBit");

    effTrigBit.clear();

    for (int i = 1; i <= N_TRIG_BITS; i++) {
      char sTrigBit[20];

      sprintf(sTrigBit, "%s%d", "EffTrig.bit", i);

      if (pSet.Get<std::string>(sTrigBit) != "")
        effTrigBit.push_back(pSet.Get<std::string>(sTrigBit));
    }
  }

  JetTriggerSelector::~JetTriggerSelector() {}

  void JetTriggerSelector::BookHistos() {
    BookHistArray(h_nJets,         "h_nJets",         "",  6, -0.5,   5.5, N_CUTS, 0, 1, false);
    BookHistArray(h_jet1Pt,        "h_jet1Pt",        "", 40,  0.0, 200.0, N_CUTS, 0, 1, false);
    BookHistArray(h_jet2Pt,        "h_jet2Pt",        "", 40,  0.0, 200.0, N_CUTS, 0, 1, false);
    BookHistArray(h_jet3Pt,        "h_jet3Pt",        "", 40,  0.0, 200.0, N_CUTS, 0, 1, false);
    BookHistArray(h_jet4Pt,        "h_jet4Pt",        "", 40,  0.0, 200.0, N_CUTS, 0, 1, false);
    BookHistArray(h_jet12DeltaEta, "h_jet12DeltaEta", "", 20,  0.0,   4.8, N_CUTS, 0, 1, false);
    BookHistArray(h_jet12DeltaPhi, "h_jet12DeltaPhi", "", 20,  0.0,   3.2, N_CUTS, 0, 1, false);
  }

  void JetTriggerSelector::Start(Event::Data& data) {
    initDir(data.OutputFile(), folderName_.c_str());

    // Clear name components
    cutName.clear();

    // Clear maps
    nJetsMap.clear();
    jet1PtMap.clear();
    jet2PtMap.clear();
    jet3PtMap.clear();
    jet4PtMap.clear();

    BookHistos();
    createHistNames();
  }

  bool JetTriggerSelector::Process(Event::Data& data) {
    std::vector<bool>           cuts;
    std::vector<TLorentzVector> jets;

    passesInitTrig    = true;
    passesEffTrigs    = false;
    passesCuts        = true;
    eventWeight       = data.GetEventWeight();
    jet1Pt            = -9.9;
    jet2Pt            = -9.9;
    jet2Pt            = -9.9;
    jet2Pt            = -9.9;
    jet12DeltaEta     = -9.9;
    jet12DeltaPhi     = -9.9;

    if (initTrigBit != "")
      passesInitTrig = (map<std::string, bool>(* data.hlt()))[initTrigBit];

    for (uint i = 0; i < effTrigBit.size(); i++) {
      if (!passesEffTrigs)
        passesEffTrigs = (map<std::string, bool>(* data.hlt()))[effTrigBit[i]];
    }

    for (uint i = 0; i < data.JD_Jets().size(); i++) {
      TLorentzVector vec;

      vec.SetPxPyPzE(data.JD_Jets()[i].Px(),
                     data.JD_Jets()[i].Py(),
                     data.JD_Jets()[i].Pz(),
                     data.JD_Jets()[i].E());

      if (vec.Pt()                 >  minJetPt        &&
          fabs(vec.Eta())          <  MAX_JET_ABS_ETA &&
          data.jetLooseID()->at(i) == 1)
        jets.push_back(vec);
    }

    sort(jets.begin(), jets.end(), comparePtJets);

    nJets = jets.size();

    if (jets.size() >= 1)
      jet1Pt = (jets.at(0)).Pt();
    if (jets.size() >= 2) {
      jet2Pt        =             (jets.at(1)).Pt();
      jet12DeltaEta = fabs       ((jets.at(0)).Eta() - (jets.at(1)).Eta());
      jet12DeltaPhi = getDeltaPhi((jets.at(0)).Phi(),  (jets.at(1)).Phi());
    }
    if (jets.size() >= 3)
      jet3Pt = (jets.at(2)).Pt();
    if (jets.size() >= 4)
      jet4Pt = (jets.at(3)).Pt();

    cuts.push_back(true);  // Plot everything first
    cuts.push_back(passesInitTrig);
    cuts.push_back(nJets >= minNJets);
    cuts.push_back(passesEffTrigs);

    for (uint i = 0; i < cuts.size(); i++) {
      passesCuts = passesCuts && cuts.at(i);

      if (passesCuts) {
        nJetsMap        ["h_nJets_"         + cutName.at(i)]->Fill(nJets,         eventWeight);

        if (jets.size() >= 1)
          jet1PtMap       ["h_jet1Pt_"        + cutName.at(i)]->Fill(jet1Pt,        eventWeight);

        if (jets.size() >= 2) {
          jet2PtMap       ["h_jet2Pt_"        + cutName.at(i)]->Fill(jet2Pt,        eventWeight);

          if (jet2Pt > MIN_JET_PT) {
            jet12DeltaEtaMap["h_jet12DeltaEta_" + cutName.at(i)]->Fill(jet12DeltaEta, eventWeight);
            jet12DeltaPhiMap["h_jet12DeltaPhi_" + cutName.at(i)]->Fill(jet12DeltaPhi, eventWeight);
          }
        }

        if (jets.size() >= 3)
          jet3PtMap       ["h_jet3Pt_"        + cutName.at(i)]->Fill(jet3Pt,        eventWeight);

        if (jets.size() >= 4)
          jet4PtMap       ["h_jet4Pt_"        + cutName.at(i)]->Fill(jet4Pt,        eventWeight);
      }
    }

    return passesCuts;
  }

  std::ostream& JetTriggerSelector::Description(std::ostream& ostrm) {
    ostrm << "Selects events with jet triggers";

    return ostrm;
  }

  void JetTriggerSelector::createHistNames() {
    cutName.push_back("0_allEvents");
    cutName.push_back("1_passesInitTrig");
    cutName.push_back("2_nJets_geq_minNJets");
    cutName.push_back("3_passesEffTrigs");

    for (uint i = 0; i < cutName.size(); i++) {
      nJetsMap        ["h_nJets_"         + cutName.at(i)] = h_nJets.at        (i);
      jet1PtMap       ["h_jet1Pt_"        + cutName.at(i)] = h_jet1Pt.at       (i);
      jet2PtMap       ["h_jet2Pt_"        + cutName.at(i)] = h_jet2Pt.at       (i);
      jet3PtMap       ["h_jet3Pt_"        + cutName.at(i)] = h_jet3Pt.at       (i);
      jet4PtMap       ["h_jet4Pt_"        + cutName.at(i)] = h_jet4Pt.at       (i);
      jet12DeltaEtaMap["h_jet12DeltaEta_" + cutName.at(i)] = h_jet12DeltaEta.at(i);
      jet12DeltaPhiMap["h_jet12DeltaPhi_" + cutName.at(i)] = h_jet12DeltaPhi.at(i);

      nJetsMap        ["h_nJets_"         + cutName.at(i)]->SetName(("h_nJets_"         + cutName.at(i)).c_str());
      jet1PtMap       ["h_jet1Pt_"        + cutName.at(i)]->SetName(("h_jet1Pt_"        + cutName.at(i)).c_str());
      jet2PtMap       ["h_jet2Pt_"        + cutName.at(i)]->SetName(("h_jet2Pt_"        + cutName.at(i)).c_str());
      jet3PtMap       ["h_jet3Pt_"        + cutName.at(i)]->SetName(("h_jet3Pt_"        + cutName.at(i)).c_str());
      jet4PtMap       ["h_jet4Pt_"        + cutName.at(i)]->SetName(("h_jet4Pt_"        + cutName.at(i)).c_str());
      jet12DeltaEtaMap["h_jet12DeltaEta_" + cutName.at(i)]->SetName(("h_jet12DeltaEta_" + cutName.at(i)).c_str());
      jet12DeltaPhiMap["h_jet12DeltaPhi_" + cutName.at(i)]->SetName(("h_jet12DeltaPhi_" + cutName.at(i)).c_str());
    }
  }

  void JetTriggerSelector::createHltNames() {
    hltName.push_back("HLT_L1SingleCenJet");
    hltName.push_back("HLT_L1SingleCenJet_NoBPTX");
    hltName.push_back("HLT_L1SingleForJet");
    hltName.push_back("HLT_L1SingleForJet_NoBPTX");
    hltName.push_back("HLT_L1SingleTauJet");
    hltName.push_back("HLT_L1SingleTauJet_NoBPTX");
    hltName.push_back("HLT_L1Jet6U");
    hltName.push_back("HLT_L1Jet6U_NoBPTX");
    hltName.push_back("HLT_L1Jet10U");
    hltName.push_back("HLT_L1Jet10U_NoBPTX");
    hltName.push_back("HLT_Jet15U");
    hltName.push_back("HLT_Jet30U");
    hltName.push_back("HLT_Jet50U");
    hltName.push_back("HLT_DiJetAve15U_8E29");
    hltName.push_back("HLT_DiJetAve30U_8E29");
    hltName.push_back("HLT_DoubleJet15U_ForwardBackward");
    hltName.push_back("HLT_FwdJet20U");
    hltName.push_back("HLT_QuadJet15U");
    hltName.push_back("HLT_L1MET20");
    hltName.push_back("HLT_MET45");
    hltName.push_back("HLT_MET100");
    hltName.push_back("HLT_HT100U");
  }

  double JetTriggerSelector::getDeltaPhi(double phi1, double phi2) {
    if (phi1 - phi2 > PI)
      return fabs(phi1 - phi2 - 2 * PI);

    if (phi1 - phi2 < -1 * PI)
      return fabs(phi1 - phi2 + 2 * PI);

    return fabs(phi1 - phi2);
  }
}
