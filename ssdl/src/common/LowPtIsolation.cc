#include "LowPtIsolation.hh"

namespace SSDL {

  LepIsoPlots::LepIsoPlots(const std::string & folderName):
    mFolderName(folderName){ }

  void LepIsoPlots::Start(Event::Data & ev) {

    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
    
  }

  LepIsoPlots::~LepIsoPlots() {
    for (int i = 0; i < 8; i++) {
      if (i < 4) {
        plotIsoCutEff (h_trackIso [i + 2], h_trackIsoCut_cutEff [i]);
        plotIsoCutEff (h_ecalIso  [i + 2], h_ecalIsoCut_cutEff  [i]);
        plotIsoCutEff (h_hcalIso  [i + 2], h_hcalIsoCut_cutEff  [i]);
        plotIsoCutEff (h_combIso  [i + 2], h_combIsoCut_cutEff  [i]);

        plotRecoEff (h_trackIso [i + 2], nGenLep [i], h_trackIsoCut_recoEff [i]);
        plotRecoEff (h_ecalIso  [i + 2], nGenLep [i], h_ecalIsoCut_recoEff  [i]);
        plotRecoEff (h_hcalIso  [i + 2], nGenLep [i], h_hcalIsoCut_recoEff  [i]);
        plotRecoEff (h_combIso  [i + 2], nGenLep [i], h_combIsoCut_recoEff  [i]);

        plotRecoPurity (h_trackIso [i + 2], h_trackIso [i % 2], h_trackIsoCut_recoPurity [i]);
        plotRecoPurity (h_ecalIso  [i + 2], h_ecalIso  [i % 2], h_ecalIsoCut_recoPurity  [i]);
        plotRecoPurity (h_hcalIso  [i + 2], h_hcalIso  [i % 2], h_hcalIsoCut_recoPurity  [i]);
        plotRecoPurity (h_combIso  [i + 2], h_combIso  [i % 2], h_combIsoCut_recoPurity  [i]);
      }
      else {
        plotIsoCutEff (h_trackIso [i + 6], h_trackIsoCut_cutEff [i]);
        plotIsoCutEff (h_ecalIso  [i + 6], h_ecalIsoCut_cutEff  [i]);
        plotIsoCutEff (h_hcalIso  [i + 6], h_hcalIsoCut_cutEff  [i]);
        plotIsoCutEff (h_combIso  [i + 6], h_combIsoCut_cutEff  [i]);

        plotRecoEff (h_trackIso [i + 6], nGenLep [i], h_trackIsoCut_recoEff [i]);
        plotRecoEff (h_ecalIso  [i + 6], nGenLep [i], h_ecalIsoCut_recoEff  [i]);
        plotRecoEff (h_hcalIso  [i + 6], nGenLep [i], h_hcalIsoCut_recoEff  [i]);
        plotRecoEff (h_combIso  [i + 6], nGenLep [i], h_combIsoCut_recoEff  [i]);

        plotRecoPurity (h_trackIso [i + 6], h_trackIso [(i % 2) + 8], h_trackIsoCut_recoPurity [i]);
        plotRecoPurity (h_ecalIso  [i + 6], h_ecalIso  [(i % 2) + 8], h_ecalIsoCut_recoPurity  [i]);
        plotRecoPurity (h_hcalIso  [i + 6], h_hcalIso  [(i % 2) + 8], h_hcalIsoCut_recoPurity  [i]);
        plotRecoPurity (h_combIso  [i + 6], h_combIso  [(i % 2) + 8], h_combIsoCut_recoPurity  [i]);
      }

      h_trackIsoCut_recoAccept [i]->Divide (h_trackIsoCut_recoEff [i], h_trackIsoCut_recoPurity [i], 1.0, 1.0, "B");
      h_ecalIsoCut_recoAccept  [i]->Divide (h_ecalIsoCut_recoEff  [i], h_ecalIsoCut_recoPurity  [i], 1.0, 1.0, "B");
      h_hcalIsoCut_recoAccept  [i]->Divide (h_hcalIsoCut_recoEff  [i], h_hcalIsoCut_recoPurity  [i], 1.0, 1.0, "B");
      h_combIsoCut_recoAccept  [i]->Divide (h_combIsoCut_recoEff  [i], h_combIsoCut_recoPurity  [i], 1.0, 1.0, "B");
    }

  }

  void  LepIsoPlots::BookHistos() {
    // Initialize generator lepton counters
    for (int i = 0; i < 8; i++)
      nGenLep [i] = 0;

    // Book histograms

    // Book isolation histograms
    BookHistArray (h_trackIso, "h_trackIso", "", 100, 0.0, 1.0, 16, 0, 1, false);
    BookHistArray (h_ecalIso,  "h_ecalIso",  "", 100, 0.0, 1.0, 16, 0, 1, false);
    BookHistArray (h_hcalIso,  "h_hcalIso",  "", 100, 0.0, 1.0, 16, 0, 1, false);
    BookHistArray (h_combIso,  "h_combIso",  "", 100, 0.0, 1.0, 16, 0, 1, false);

    // Book isolation cut efficiency histograms
    BookHistArray (h_trackIsoCut_cutEff, "h_trackIsoCut_cutEff", "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_ecalIsoCut_cutEff,  "h_ecalIsoCut_cutEff",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_hcalIsoCut_cutEff,  "h_hcalIsoCut_cutEff",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_combIsoCut_cutEff,  "h_combIsoCut_cutEff",  "", 100, 0.0, 1.0, 8, 0, 1, false);

    // Book reconstruction efficiency histograms
    BookHistArray (h_trackIsoCut_recoEff, "h_trackIsoCut_recoEff", "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_ecalIsoCut_recoEff,  "h_ecalIsoCut_recoEff",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_hcalIsoCut_recoEff,  "h_hcalIsoCut_recoEff",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_combIsoCut_recoEff,  "h_combIsoCut_recoEff",  "", 100, 0.0, 1.0, 8, 0, 1, false);

    // Book reconstruction purity histograms
    BookHistArray (h_trackIsoCut_recoPurity, "h_trackIsoCut_recoPurity", "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_ecalIsoCut_recoPurity,  "h_ecalIsoCut_recoPurity",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_hcalIsoCut_recoPurity,  "h_hcalIsoCut_recoPurity",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_combIsoCut_recoPurity,  "h_combIsoCut_recoPurity",  "", 100, 0.0, 1.0, 8, 0, 1, false);

    // Book reconstruction acceptance histograms
    BookHistArray (h_trackIsoCut_recoAccept, "h_trackIsoCut_recoAccept", "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_ecalIsoCut_recoAccept,  "h_ecalIsoCut_recoAccept",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_hcalIsoCut_recoAccept,  "h_hcalIsoCut_recoAccept",  "", 100, 0.0, 1.0, 8, 0, 1, false);
    BookHistArray (h_combIsoCut_recoAccept,  "h_combIsoCut_recoAccept",  "", 100, 0.0, 1.0, 8, 0, 1, false);
  }

  bool
  LepIsoPlots::Process (Event::Data& ev) {

    for(vector<GenObject const *>::const_iterator genLep4P=ev.MC_TheLeptons().begin();    
	genLep4P!=ev.MC_TheLeptons().end();++genLep4P){
      if ((*genLep4P)->GetStatus() == 1) {


        if (fabs ((*genLep4P)->Eta()) <= 2.4) {
          if (abs ((*genLep4P)->GetID()) == 11) {
            if (ev.leptonType ((*genLep4P)->GetIndex()) >= 1 &&
                ev.leptonType ((*genLep4P)->GetIndex()) <= 4) {
              if ((*genLep4P)->Pt() >= 5.0 && (*genLep4P)->Pt() <= 15.0)
                nGenLep [0]++;  // genIsoGenElec_ptLessThan15
              else if ((*genLep4P)->Pt() > 15.0)
                nGenLep [1]++;  // genIsoGenElec_ptGreaterThan15
            }
            else if (ev.leptonType ((*genLep4P)->GetIndex()) >= 9 &&
                     ev.leptonType ((*genLep4P)->GetIndex()) <= 10) {
              if ((*genLep4P)->Pt() >= 5.0 && (*genLep4P)->Pt() <= 15.0)
                nGenLep [2]++;  // genNonIsoGenElec_ptLessThan15
              else if ((*genLep4P)->Pt() > 15.0)
                nGenLep [3]++;  // genNonIsoGenElec_ptGreaterThan15
            }
          }
          else if (abs ((*genLep4P)->GetID()) == 13) {
            if (ev.leptonType ((*genLep4P)->GetIndex()) >= 1 &&
                ev.leptonType ((*genLep4P)->GetIndex()) <= 4) {
              if ((*genLep4P)->Pt() >= 3.0 && (*genLep4P)->Pt() <= 9.0)
                nGenLep [4]++;  // genIsoGenMuon_ptLessThan9
              else if ((*genLep4P)->Pt() > 9.0)
                nGenLep [5]++;  // genIsoGenMuon_ptGreaterThan9
            }
            else if (ev.leptonType ((*genLep4P)->GetIndex()) >= 9 &&
                     ev.leptonType ((*genLep4P)->GetIndex()) <= 10) {
              if ((*genLep4P)->Pt() >= 3.0 && (*genLep4P)->Pt() <= 9.0)
                nGenLep [6]++;  // genNonIsoGenMuon_ptLessThan9
              else if ((*genLep4P)->Pt() > 9.0)
                nGenLep [7]++;  // genNonIsoGenMuon_ptGreaterThan9
            }
          }
        }
      }
    }
    

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){
      if ((*lep)->Et()  >= 5.0 &&
          fabs ((*lep)->Eta()) <= 2.4 &&
          (*lep)->GetLooseId()  == 1) {
        double patElecEt      = (*lep)->Et();
        double trackIsoConePt = (*lep)->GetTrkIsolation();
        double ecalIsoConeEt  = (*lep)->GetEcalIsolation();
        double hcalIsoConeEt  = (*lep)->GetHcalIsolation();
        double combIsoConeEt  = (*lep)->GetCombIsolation();


        int matchedGenElecNo = ev.leptonMatch (const_cast<Lepton*>((*lep)) , 1);

        if (patElecEt <= 15.0) {
          h_trackIso [0]->Fill (trackIsoConePt / patElecEt);  // patElec_ptLessThan15
          h_ecalIso  [0]->Fill (ecalIsoConeEt  / patElecEt);  // patElec_ptLessThan15
          h_hcalIso  [0]->Fill (hcalIsoConeEt  / patElecEt);  // patElec_ptLessThan15
          h_combIso  [0]->Fill (combIsoConeEt  / patElecEt);  // patElec_ptLessThan15

          if (ev.leptonType (matchedGenElecNo) >= 1 &&
              ev.leptonType (matchedGenElecNo) <= 4) {
            h_trackIso [2]->Fill (trackIsoConePt / patElecEt);  // genIsoPatElec_ptLessThan15
            h_ecalIso  [2]->Fill (ecalIsoConeEt  / patElecEt);  // genIsoPatElec_ptLessThan15
            h_hcalIso  [2]->Fill (hcalIsoConeEt  / patElecEt);  // genIsoPatElec_ptLessThan15
            h_combIso  [2]->Fill (combIsoConeEt  / patElecEt);  // genIsoPatElec_ptLessThan15
          }
          else if (ev.leptonType (matchedGenElecNo) >= 9  &&
                   ev.leptonType (matchedGenElecNo) <= 10) {
            h_trackIso [4]->Fill (trackIsoConePt / patElecEt);  // genNonIsoPatElec_ptLessThan15
            h_ecalIso  [4]->Fill (ecalIsoConeEt  / patElecEt);  // genNonIsoPatElec_ptLessThan15
            h_hcalIso  [4]->Fill (hcalIsoConeEt  / patElecEt);  // genNonIsoPatElec_ptLessThan15
            h_combIso  [4]->Fill (combIsoConeEt  / patElecEt);  // genNonIsoPatElec_ptLessThan15
          }
          else {
            h_trackIso [6]->Fill (trackIsoConePt / patElecEt);  // fakePatElec_ptLessThan15
            h_ecalIso  [6]->Fill (ecalIsoConeEt  / patElecEt);  // fakePatElec_ptLessThan15
            h_hcalIso  [6]->Fill (hcalIsoConeEt  / patElecEt);  // fakePatElec_ptLessThan15
            h_combIso  [6]->Fill (combIsoConeEt  / patElecEt);  // fakePatElec_ptLessThan15
          }
        }
        else {
          h_trackIso [1]->Fill (trackIsoConePt / patElecEt);  // patElec_ptGreaterThan15
          h_ecalIso  [1]->Fill (ecalIsoConeEt  / patElecEt);  // patElec_ptGreaterThan15
          h_hcalIso  [1]->Fill (hcalIsoConeEt  / patElecEt);  // patElec_ptGreaterThan15
          h_combIso  [1]->Fill (combIsoConeEt  / patElecEt);  // patElec_ptGreaterThan15

          if (ev.leptonType (matchedGenElecNo) >= 1 &&
              ev.leptonType (matchedGenElecNo) <= 4) {
            h_trackIso [3]->Fill (trackIsoConePt / patElecEt);  // genIsoPatElec_ptGreaterThan15
            h_ecalIso  [3]->Fill (ecalIsoConeEt  / patElecEt);  // genIsoPatElec_ptGreaterThan15
            h_hcalIso  [3]->Fill (hcalIsoConeEt  / patElecEt);  // genIsoPatElec_ptGreaterThan15
            h_combIso  [3]->Fill (combIsoConeEt  / patElecEt);  // genIsoPatElec_ptGreaterThan15
          }
          else if (ev.leptonType (matchedGenElecNo) >= 9  &&
                   ev.leptonType (matchedGenElecNo) <= 10) {
            h_trackIso [5]->Fill (trackIsoConePt / patElecEt);  // genNonIsoPatElec_ptGreaterThan15
            h_ecalIso  [5]->Fill (ecalIsoConeEt  / patElecEt);  // genNonIsoPatElec_ptGreaterThan15
            h_hcalIso  [5]->Fill (hcalIsoConeEt  / patElecEt);  // genNonIsoPatElec_ptGreaterThan15
            h_combIso  [5]->Fill (combIsoConeEt  / patElecEt);  // genNonIsoPatElec_ptGreaterThan15
          }
          else {
            h_trackIso [7]->Fill (trackIsoConePt / patElecEt);  // fakePatElec_ptGreaterThan15
            h_ecalIso  [7]->Fill (ecalIsoConeEt  / patElecEt);  // fakePatElec_ptGreaterThan15
            h_hcalIso  [7]->Fill (hcalIsoConeEt  / patElecEt);  // fakePatElec_ptGreaterThan15
            h_combIso  [7]->Fill (combIsoConeEt  / patElecEt);  // fakePatElec_ptGreaterThan15
          }
        }
      }
    }


    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
  
      if ((*lep)->Pt()    >= 3.0 &&
          fabs ( (*lep)->Eta() ) <= 2.4 &&
	  (*lep)->GetTightId() == 1) {
        double patMuonPt      = (*lep)->Pt();
        double trackIsoConePt = (*lep)->GetTrkIsolation();
        double ecalIsoConeEt  = (*lep)->GetEcalIsolation();
        double hcalIsoConeEt  = (*lep)->GetHcalIsolation();
        double combIsoConeEt  = (*lep)->GetCombIsolation();

  

        int matchedGenMuonNo = ev.leptonMatch (const_cast<Lepton*>((*lep)), 2);

        if (patMuonPt <= 9.0) {
          h_trackIso [8]->Fill (trackIsoConePt / patMuonPt);  // patMuon_ptLessThan9
          h_ecalIso  [8]->Fill (ecalIsoConeEt  / patMuonPt);  // patMuon_ptLessThan9
          h_hcalIso  [8]->Fill (hcalIsoConeEt  / patMuonPt);  // patMuon_ptLessThan9
          h_combIso  [8]->Fill (combIsoConeEt  / patMuonPt);  // patMuon_ptLessThan9

          if (ev.leptonType (matchedGenMuonNo) >= 1 &&
              ev.leptonType (matchedGenMuonNo) <= 4) {
            h_trackIso [10]->Fill (trackIsoConePt / patMuonPt);  // genIsoPatMuon_ptLessThan9
            h_ecalIso  [10]->Fill (ecalIsoConeEt  / patMuonPt);  // genIsoPatMuon_ptLessThan9
            h_hcalIso  [10]->Fill (hcalIsoConeEt  / patMuonPt);  // genIsoPatMuon_ptLessThan9
            h_combIso  [10]->Fill (combIsoConeEt  / patMuonPt);  // genIsoPatMuon_ptLessThan9
          }
          else if (ev.leptonType (matchedGenMuonNo) >= 9  &&
                   ev.leptonType (matchedGenMuonNo) <= 10) {
            h_trackIso [12]->Fill (trackIsoConePt / patMuonPt);  // genNonIsoPatMuon_ptLessThan9
            h_ecalIso  [12]->Fill (ecalIsoConeEt  / patMuonPt);  // genNonIsoPatMuon_ptLessThan9
            h_hcalIso  [12]->Fill (hcalIsoConeEt  / patMuonPt);  // genNonIsoPatMuon_ptLessThan9
            h_combIso  [12]->Fill (combIsoConeEt  / patMuonPt);  // genNonIsoPatMuon_ptLessThan9
          }
          else {
            h_trackIso [14]->Fill (trackIsoConePt / patMuonPt);  // fakePatMuon_ptLessThan9
            h_ecalIso  [14]->Fill (ecalIsoConeEt  / patMuonPt);  // fakePatMuon_ptLessThan9
            h_hcalIso  [14]->Fill (hcalIsoConeEt  / patMuonPt);  // fakePatMuon_ptLessThan9
            h_combIso  [14]->Fill (combIsoConeEt  / patMuonPt);  // fakePatMuon_ptLessThan9
          }
        }
        else {
          h_trackIso [9]->Fill (trackIsoConePt / patMuonPt);  // patMuon_ptGreaterThan9
          h_ecalIso  [9]->Fill (ecalIsoConeEt  / patMuonPt);  // patMuon_ptGreaterThan9
          h_hcalIso  [9]->Fill (hcalIsoConeEt  / patMuonPt);  // patMuon_ptGreaterThan9
          h_combIso  [9]->Fill (combIsoConeEt  / patMuonPt);  // patMuon_ptGreaterThan9

          if (ev.leptonType (matchedGenMuonNo) >= 1 &&
              ev.leptonType (matchedGenMuonNo) <= 4) {
            h_trackIso [11]->Fill (trackIsoConePt / patMuonPt);  // genIsoPatMuon_ptGreaterThan9
            h_ecalIso  [11]->Fill (ecalIsoConeEt  / patMuonPt);  // genIsoPatMuon_ptGreaterThan9
            h_hcalIso  [11]->Fill (hcalIsoConeEt  / patMuonPt);  // genIsoPatMuon_ptGreaterThan9
            h_combIso  [11]->Fill (combIsoConeEt  / patMuonPt);  // genIsoPatMuon_ptGreaterThan9
          }
          else if (ev.leptonType (matchedGenMuonNo) >= 9  &&
                   ev.leptonType (matchedGenMuonNo) <= 10) {
            h_trackIso [13]->Fill (trackIsoConePt / patMuonPt);  // genNonIsoPatMuon_ptGreaterThan9
            h_ecalIso  [13]->Fill (ecalIsoConeEt  / patMuonPt);  // genNonIsoPatMuon_ptGreaterThan9
            h_hcalIso  [13]->Fill (hcalIsoConeEt  / patMuonPt);  // genNonIsoPatMuon_ptGreaterThan9
            h_combIso  [13]->Fill (combIsoConeEt  / patMuonPt);  // genNonIsoPatMuon_ptGreaterThan9
          }
          else {
            h_trackIso [15]->Fill (trackIsoConePt / patMuonPt);  // fakePatMuon_ptGreaterThan9
            h_ecalIso  [15]->Fill (ecalIsoConeEt  / patMuonPt);  // fakePatMuon_ptGreaterThan9
            h_hcalIso  [15]->Fill (hcalIsoConeEt  / patMuonPt);  // fakePatMuon_ptGreaterThan9
            h_combIso  [15]->Fill (combIsoConeEt  / patMuonPt);  // fakePatMuon_ptGreaterThan9
          }
        }
      }
    }

    return true;
  }

  void
  LepIsoPlots::plotIsoCutEff (TH1D* h_matchedPatLep_iso,
                              TH1D* h_isoCut_cutEff) {
    TH1D* h_matchedPatLep_iso_integral    = new TH1D ("h_matchedPatLep_iso_integral",    "", 100, 0.0, 1.0);
    TH1D* h_matchedPatLep_iso_maxIntegral = new TH1D ("h_matchedPatLep_iso_maxIntegral", "", 100, 0.0, 1.0);

    h_matchedPatLep_iso_integral->Sumw2();
    h_matchedPatLep_iso_maxIntegral->Sumw2();

    for (int i = 1; i <= 100; i++) {
      double nMatchedPatLep_iso_integral    = h_matchedPatLep_iso->Integral (1, i);
      double nMatchedPatLep_iso_maxIntegral = h_matchedPatLep_iso->Integral (1, 101);

      h_matchedPatLep_iso_integral->SetBinContent    (i, nMatchedPatLep_iso_integral);
      h_matchedPatLep_iso_maxIntegral->SetBinContent (i, nMatchedPatLep_iso_maxIntegral);
    }

    h_isoCut_cutEff->Divide (h_matchedPatLep_iso_integral, h_matchedPatLep_iso_maxIntegral, 1.0, 1.0, "B");

    delete h_matchedPatLep_iso_integral;
    delete h_matchedPatLep_iso_maxIntegral;
  }

  void
  LepIsoPlots::plotRecoEff (TH1D* h_matchedPatLep_iso, int nGenLep,
                            TH1D* h_isoCut_recoEff) {
    for (int i = 1; i <= 100; i++) {
      double nMatchedPatLep_iso_integral = h_matchedPatLep_iso->Integral (1, i);

      h_isoCut_recoEff->SetBinContent (i, nMatchedPatLep_iso_integral / nGenLep);
    }
  }

  void
  LepIsoPlots::plotRecoPurity (TH1D* h_matchedPatLep_iso, TH1D* h_patLep_iso,
                               TH1D* h_isoCut_recoPurity) {
    TH1D* h_matchedPatLep_iso_integral = new TH1D ("h_matchedPatLep_iso_integral", "", 100, 0.0, 1.0);
    TH1D* h_patLep_iso_integral        = new TH1D ("h_patLep_iso_integral",        "", 100, 0.0, 1.0);

    h_matchedPatLep_iso_integral->Sumw2();
    h_patLep_iso_integral->Sumw2();

    for (int i = 1; i <= 100; i++) {
      double nMatchedPatLep_iso_integral = h_matchedPatLep_iso->Integral (1, i);
      double nPatLep_iso_integral        = h_patLep_iso->Integral        (1, i);

      h_matchedPatLep_iso_integral->SetBinContent (i, nMatchedPatLep_iso_integral);
      h_patLep_iso_integral->SetBinContent        (i, nPatLep_iso_integral);
    }

    h_isoCut_recoPurity->Divide (h_matchedPatLep_iso_integral, h_patLep_iso_integral, 1.0, 1.0, "B");

    delete h_matchedPatLep_iso_integral;
    delete h_patLep_iso_integral;
  }

  std::ostream&
  LepIsoPlots::Description (std::ostream& ostrm) {
    ostrm << "Plotting operation ";
    ostrm << "(Plots in folder " << mFolderName << "): ";

    return ostrm;
  }

  //============================================================================
}
  



