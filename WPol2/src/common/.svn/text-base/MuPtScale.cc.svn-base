#include "MuPtScale.hh"

//====================================
// MuPtScale implementation
//====================================

namespace Operation {
  MuPtScale::MuPtScale(const std::string & folderName) :
    mFolderName(folderName) {}

  MuPtScale::~MuPtScale() {}

  void MuPtScale::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MuPtScale::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);


    RECO_1pcscale_recobosonM = new TH1F("RECO_1pcscale_recobosonM",";newrecoboson M;",60,59.5,119.5);
    RECO_5pcscale_recobosonM = new TH1F("RECO_5pcscale_recobosonM",";newrecoboson M;",60,59.5,119.5);
    RECO_5pcscale_recobosonMvsLP = new TH2F("RECO_5pcscale_recobosonMvsLP",";recoboson M;LP",600,59.5,119.5,500,-2.5,2.5);
    RECO_1pcscale_recobosonMvsLP = new TH2F("RECO_1pcscale_recobosonMvsLP",";recoboson M;LP",600,59.5,119.5,500,-2.5,2.5);
    RECO_5pcscale_recobosonMvsMpPT = new TH2F("RECO_5pcscale_recobosonMvsMpPT",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_5pcscale_recobosonMvsMmPT = new TH2F("RECO_5pcscale_recobosonMvsMmPT",";recoboson M; #mu^{-}PT",600,59.5,119.5,500,0,400);
    RECO_1pcscale_recobosonMvsMpPT = new TH2F("RECO_1pcscale_recobosonMvsMpPT",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_1pcscale_recobosonMvsMmPT = new TH2F("RECO_1pcscale_recobosonMvsMmPT",";recoboson M; #mu^{-}PT",600,59.5,119.5,500,0,400);
    RECO_0pcscale_recobosonMvsMpPT = new TH2F("RECO_0pcscale_recobosonMvsMpPT",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_0pcscale_recobosonMvsMmPT = new TH2F("RECO_0pcscale_recobosonMvsMmPT",";recoboson M; #mu^{-}PT",600,59.5,119.5,500,0,400);

    RECO_5pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_5pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_5pcscale_recobosonMvsMpPT_hrdMm = new TH2F("RECO_5pcscale_recobosonMvsMpPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_1pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_1pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_1pcscale_recobosonMvsMpPT_hrdMm = new TH2F("RECO_1pcscale_recobosonMvsMpPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_0pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_0pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_0pcscale_recobosonMvsMpPT_hrdMm = new TH2F("RECO_0pcscale_recobosonMvsMpPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_5pcscale_recobosonMvsMmPT_hrdMp = new TH2F("RECO_5pcscale_recobosonMvsMmPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_5pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_5pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_1pcscale_recobosonMvsMmPT_hrdMp = new TH2F("RECO_1pcscale_recobosonMvsMmPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_1pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_1pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_0pcscale_recobosonMvsMmPT_hrdMp = new TH2F("RECO_0pcscale_recobosonMvsMmPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_0pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_0pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);

    RECO_4pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_4pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_4pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_4pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_3pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_3pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_3pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_3pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_2pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_2pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_2pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_2pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_m1pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_m1pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_m1pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_m1pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_m2pcscale_recobosonMvsMpPT_hrdMp = new TH2F("RECO_m2pcscale_recobosonMvsMpPT_hrdMp",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);
    RECO_m2pcscale_recobosonMvsMmPT_hrdMm = new TH2F("RECO_m2pcscale_recobosonMvsMmPT_hrdMm",";recoboson M; #mu^{+}PT",600,59.5,119.5,500,0,400);


    RECO_0pcscale_MpPhivsMpPT_hrdMp = new TH2F("RECO_0pcscale_MpPhivsMpPT_hrdMp","",30,-3.14,3.14,500,0,400);
    RECO_0pcscale_MmPhivsMmPT_hrdMm = new TH2F("RECO_0pcscale_MmPhivsMmPT_hrdMm","",30,-3.14,3.14,500,0,400);

    RECO_0pcscale_MpEtavsMpPT_hrdMp = new TH2F("RECO_0pcscale_MpEtavsMpPT_hrdMp","",30,-5,5,500,0,400);
    RECO_0pcscale_MmEtavsMmPT_hrdMm = new TH2F("RECO_0pcscale_MmEtavsMmPT_hrdMm","",30,-5,5,500,0,400);

    RECO_0pcscale_MpPhivsMpPTvsrecobosonM_hrdMp = new TH3F("RECO_0pcscale_MpPhivsMpPTvsrecobosonM_hrdMp","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_0pcscale_MmPhivsMmPTvsrecobosonM_hrdMm = new TH3F("RECO_0pcscale_MmPhivsMmPTvsrecobosonM_hrdMm","",30,-3.14,3.14,100,0,400,40,81.2,101.2);

    RECO_0pcscale_MpEtavsMpPTvsrecobosonM_hrdMp = new TH3F("RECO_0pcscale_MpEtavsMpPTvsrecobosonM_hrdMp","",30,-5,5,100,0,400,40,81.2,101.2);
    RECO_0pcscale_MmEtavsMmPTvsrecobosonM_hrdMm = new TH3F("RECO_0pcscale_MmEtavsMmPTvsrecobosonM_hrdMm","",30,-5,5,100,0,400,40,81.2,101.2);



    // corr. function sin(PtPhiCorrA*Phi+PtPhiCorrB)
    PtPhiCorrA=1.051;
    PtPhiCorrB=0.557;
    RECO_PhiDep1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp = new TH3F("RECO_PhiDep1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDep1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm = new TH3F("RECO_PhiDep1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDep2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp = new TH3F("RECO_PhiDep2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDep2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm = new TH3F("RECO_PhiDep2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDepm1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp = new TH3F("RECO_PhiDepm1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDepm1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm = new TH3F("RECO_PhiDepm1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDepm2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp = new TH3F("RECO_PhiDepm2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp","",30,-3.14,3.14,100,0,400,40,81.2,101.2);
    RECO_PhiDepm2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm = new TH3F("RECO_PhiDepm2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm","",30,-3.14,3.14,100,0,400,40,81.2,101.2);

    dimuonstree = new TTree("dimuonstree","dimuonstree");
    dimuonstree->Branch("MpPt",&MpPt,"MpPt/D") ;
    dimuonstree->Branch("MpEta",&MpEta,"MpEta/D") ;
    dimuonstree->Branch("MpPhi",&MpPhi,"MpPhi/D") ;
    dimuonstree->Branch("MmPt",&MmPt,"MmPt/D") ;
    dimuonstree->Branch("MmEta",&MmEta,"MmEta/D") ;
    dimuonstree->Branch("MmPhi",&MmPhi,"MmPhi/D") ;
    dimuonstree->Branch("Zmass",&Zmass,"Zmass/D") ;
    dimuonstree->Branch("EvWeight",&EvWeight,"EvWeight/D");

    TH1::SetDefaultSumw2(kFALSE);
  }

  bool MuPtScale::Process(Event::Data & ev) {


    Event::Lepton const * theRECOLepton;
    Event::Lepton const * theRECOLepton2;
    TLorentzVector reco_muon;
    TLorentzVector reco_boson;

    TLorentzVector muonplus;
    TLorentzVector muonminus;

    if(ev.LD_CommonMuons().accepted.size() != 2) return false;
    //make the choice of whether to use the positively of negatively charged muon from the Z-decay (templates only exist for positively charged lepton by our definition)
    if(ev.LD_CommonMuons().accepted.at(0)->GetCharge() > 0.0) {
      reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(0));
      theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
      theRECOLepton2 = ev.LD_CommonMuons().accepted.at(1);
    } else if(ev.LD_CommonMuons().accepted.at(1)->GetCharge() > 0.0) {
      reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(1));
      theRECOLepton = ev.LD_CommonMuons().accepted.at(1);
      theRECOLepton2 = ev.LD_CommonMuons().accepted.at(0);
    } else return false; //i.e. they can't both have the same charge!
      
    reco_boson = TLVConvert(ev.LD_CommonMuons().accepted.at(0)) + TLVConvert(ev.LD_CommonMuons().accepted.at(1));
   muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);

    MpPt = muonplus.Pt();
    MpEta = muonplus.Eta();
    MpPhi = muonplus.Phi();
    MmPt = muonminus.Pt();
    MmEta = muonminus.Eta();
    MmPhi = muonminus.Phi();
    Zmass = reco_boson.M();
    EvWeight = ev.GetEventWeight();
    dimuonstree->Fill() ;

    // MU PT SCALE SYSTEMATIC STUDIES
    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    double scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * 0.05);
    double scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * 0.05);
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    TLorentzVector new_reco_boson = muonplus + muonminus;
    double newLP = ((muonplus.Px() * new_reco_boson.Px()) + (muonplus.Py() * new_reco_boson.Py())) / (new_reco_boson.Pt() * new_reco_boson.Pt());
    RECO_5pcscale_recobosonMvsLP->Fill(new_reco_boson.M(), newLP, ev.GetEventWeight());
    RECO_5pcscale_recobosonM->Fill(new_reco_boson.M(), ev.GetEventWeight());
    RECO_5pcscale_recobosonMvsMpPT->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    RECO_5pcscale_recobosonMvsMmPT->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    if (muonplus.Pt()>muonminus.Pt()) {
      RECO_5pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
      RECO_5pcscale_recobosonMvsMmPT_hrdMp->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    }
    else {
      RECO_5pcscale_recobosonMvsMpPT_hrdMm->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
      RECO_5pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    }

    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * 0.04);
    scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * 0.04);
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_4pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    else RECO_4pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());

    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * 0.03);
    scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * 0.03);
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_3pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    else RECO_3pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());

    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * 0.02);
    scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * 0.02);
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_2pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    else RECO_2pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + (0.02*(muonplus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonplus.Phi()+PtPhiCorrB));
    scaling_factor2 = 1.0 - (0.02*(muonminus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonminus.Phi()+PtPhiCorrB));
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_PhiDep2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp->Fill(muonplus.Phi(), muonplus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
    else RECO_PhiDep2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm->Fill(muonminus.Phi(), muonminus.Pt(), new_reco_boson.M(), ev.GetEventWeight());

    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * 0.01);
    scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * 0.01);
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    newLP = ((muonplus.Px() * new_reco_boson.Px()) + (muonplus.Py() * new_reco_boson.Py())) / (new_reco_boson.Pt() * new_reco_boson.Pt());
    RECO_1pcscale_recobosonMvsLP->Fill(new_reco_boson.M(), newLP, ev.GetEventWeight());
    RECO_1pcscale_recobosonM->Fill(new_reco_boson.M(), ev.GetEventWeight());
    RECO_1pcscale_recobosonMvsMpPT->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    RECO_1pcscale_recobosonMvsMmPT->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    if (muonplus.Pt()>muonminus.Pt()) {
      RECO_1pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
      RECO_1pcscale_recobosonMvsMmPT_hrdMp->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    }
    else {
      RECO_1pcscale_recobosonMvsMpPT_hrdMm->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
      RECO_1pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    }
    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + (0.01*(muonplus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonplus.Phi()+PtPhiCorrB));
    scaling_factor2 = 1.0 - (0.01*(muonminus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonminus.Phi()+PtPhiCorrB));
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_PhiDep1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp->Fill(muonplus.Phi(), muonplus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
    else RECO_PhiDep1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm->Fill(muonminus.Phi(), muonminus.Pt(), new_reco_boson.M(), ev.GetEventWeight());


    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 ;
    scaling_factor2 = 1.0 ;
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    newLP = ((muonplus.Px() * new_reco_boson.Px()) + (muonplus.Py() * new_reco_boson.Py())) / (new_reco_boson.Pt() * new_reco_boson.Pt());
    RECO_0pcscale_recobosonMvsMpPT->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    RECO_0pcscale_recobosonMvsMmPT->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    if (muonplus.Pt()>muonminus.Pt()) {
      RECO_0pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
      RECO_0pcscale_recobosonMvsMmPT_hrdMp->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
      RECO_0pcscale_MpEtavsMpPT_hrdMp->Fill(muonplus.Eta(), muonplus.Pt(), ev.GetEventWeight());
      RECO_0pcscale_MpPhivsMpPT_hrdMp->Fill(muonplus.Phi(), muonplus.Pt() ,ev.GetEventWeight());
      RECO_0pcscale_MpEtavsMpPTvsrecobosonM_hrdMp->Fill(muonplus.Eta(), muonplus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
      RECO_0pcscale_MpPhivsMpPTvsrecobosonM_hrdMp->Fill(muonplus.Phi(), muonplus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
    }
    else {
      RECO_0pcscale_recobosonMvsMpPT_hrdMm->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
      RECO_0pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
      RECO_0pcscale_MmEtavsMmPT_hrdMm->Fill(muonminus.Eta(), muonminus.Pt() , ev.GetEventWeight());
      RECO_0pcscale_MmPhivsMmPT_hrdMm->Fill(muonminus.Phi(), muonminus.Pt() ,ev.GetEventWeight());
      RECO_0pcscale_MmEtavsMmPTvsrecobosonM_hrdMm->Fill(muonminus.Eta(), muonminus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
      RECO_0pcscale_MmPhivsMmPTvsrecobosonM_hrdMm->Fill(muonminus.Phi(), muonminus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
    }

    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * (-0.01));
    scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * (-0.01));
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_m1pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    else RECO_m1pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + (-0.01*(muonplus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonplus.Phi()+PtPhiCorrB));
    scaling_factor2 = 1.0 - (-0.01*(muonminus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonminus.Phi()+PtPhiCorrB));
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_PhiDepm1pcscale_MpPhivsMpPTvsrecobosonM_hrdMp->Fill(muonplus.Phi(), muonplus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
    else RECO_PhiDepm1pcscale_MmPhivsMmPTvsrecobosonM_hrdMm->Fill(muonminus.Phi(), muonminus.Pt(), new_reco_boson.M(), ev.GetEventWeight());

    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + ((muonplus.Pt()/100) * (-0.02));
    scaling_factor2 = 1.0 - ((muonminus.Pt()/100) * (-0.02));
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_m2pcscale_recobosonMvsMpPT_hrdMp->Fill(new_reco_boson.M(), muonplus.Pt() , ev.GetEventWeight());
    else RECO_m2pcscale_recobosonMvsMmPT_hrdMm->Fill(new_reco_boson.M(), muonminus.Pt() , ev.GetEventWeight());
    muonplus = TLVConvert(theRECOLepton);
    muonminus = TLVConvert(theRECOLepton2);
    scaling_factor1 = 1.0 + (-0.02*(muonplus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonplus.Phi()+PtPhiCorrB));
    scaling_factor2 = 1.0 - (-0.02*(muonminus.Pt()/100)*TMath::Sin(PtPhiCorrA*muonminus.Phi()+PtPhiCorrB));
    muonplus *= scaling_factor1;
    muonminus *= scaling_factor2;
    new_reco_boson = muonplus + muonminus;
    if (muonplus.Pt()>muonminus.Pt()) RECO_PhiDepm2pcscale_MpPhivsMpPTvsrecobosonM_hrdMp->Fill(muonplus.Phi(), muonplus.Pt(), new_reco_boson.M(), ev.GetEventWeight());
    else RECO_PhiDepm2pcscale_MmPhivsMmPTvsrecobosonM_hrdMm->Fill(muonminus.Phi(), muonminus.Pt(), new_reco_boson.M(), ev.GetEventWeight());


    return true;
  }


  std::ostream& MuPtScale::Description(std::ostream &ostrm) {
    ostrm << "Plotting routines for misalignment studies with Z";
    return ostrm;
  }
}
