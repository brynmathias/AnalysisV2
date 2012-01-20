#include "AnalysisTree.hh"

using namespace Operation;

namespace OneLepton{
  
  void AnalysisTree::BookHistos(){
    
    tree=new TTree("T","test");

    // Event variables
    tree->Branch("wgt",&wgt,"wgt/D");
    tree->Branch("RunNumber",&RunNumber,"RunNumber/I");
    tree->Branch("EventNumber",&EventNumber,"EventNumber/I");
    tree->Branch("LumiSection",&LumiSection,"LumiSection/I");
    tree->Branch("NumPVs",&NumPVs,"NumPVs/I");

    // Trigger
    tree->Branch("trig_Mu9",&trig_Mu9, "trig_Mu9/B");
    tree->Branch("trig_Mu15",&trig_Mu15, "trig_Mu15/B");
    tree->Branch("trig_Ele15_LW",&trig_Ele15_LW, "trig_Ele15_LW/B");
    tree->Branch("trig_Ele15_SW",&trig_Ele15_SW, "trig_Ele15_SW/B");
    tree->Branch("trig_Ele17_SW_EleId",&trig_Ele17_SW_EleId, "trig_Ele17_SW_EleId/B");
    tree->Branch("trig_Jet50",&trig_Jet50, "trig_Jet50/B");
    tree->Branch("trig_Jet80",&trig_Jet80, "trig_Jet80/B");

    // Jet variables
    tree->Branch("NJet",&NJet,"NJet/I");
    tree->Branch("JetPt",JetPt,"JetPt[NJet]/D");
    tree->Branch("JetEta",JetEta,"JetEta[NJet]/D");
    tree->Branch("JetPhi",JetPhi,"JetPhi[NJet]/D");
    tree->Branch("JetCor",JetCor,"JetCor[NJet]/D");
    tree->Branch("JetEMF",JetEMF,"JetEMF[NJet]/D");

    // Muon variables 
    tree->Branch("NMuons",&NMuons,"NMuons/I");
    tree->Branch("MuonPt",MuonPt,"MuonPt[NMuons]/D");
    tree->Branch("MuonEta",MuonEta,"MuonEta[NMuons]/D");
    tree->Branch("MuonPhi",MuonPhi,"MuonPhi[NMuons]/D");
    tree->Branch("MuonChrg",MuonChrg,"MuonChrg[NMuons]/D");
    tree->Branch("MuonType",MuonType,"MuonType[NMuons]/I");
    tree->Branch("MuongPar",MuongPar,"MuongPar[NMuons]/I");
    tree->Branch("MuonGenMother",MuonGenMother,"MuonGenMother[NMuons]/I");

    // Jet-Muon variables
    tree->Branch("MuonClosestPreJetPt",MuonClosestPreJetPt,"MuonClosestPreJetPt[NMuons]/D");
    tree->Branch("MuonClosestPreJetEta",MuonClosestPreJetEta,"MuonClosestPreJetEta[NMuons]/D");
    tree->Branch("MuonClosestPreJetPhi",MuonClosestPreJetPhi,"MuonClosestPreJetPhi[NMuons]/D");
    tree->Branch("MuonClosestPreJetDR",MuonClosestPreJetDR,"MuonClosestPreJetDR[NMuons]/D");
    tree->Branch("MuonClosestComJetPt",MuonClosestComJetPt,"MuonClosestComJetPt[NMuons]/D");
    tree->Branch("MuonClosestComJetEta",MuonClosestComJetEta,"MuonClosestComJetEta[NMuons]/D");
    tree->Branch("MuonClosestComJetPhi",MuonClosestComJetPhi,"MuonClosestComJetPhi[NMuons]/D");
    tree->Branch("MuonClosestComJetDR",MuonClosestComJetDR,"MuonClosestComJetDR[NMuons]/D");

    // Electron variables 
    tree->Branch("NElectrons",&NElectrons,"NElectrons/I");
    tree->Branch("ElectronPt",ElectronPt,"ElectronPt[NElectrons]/D");
    tree->Branch("ElectronEta",ElectronEta,"ElectronEta[NElectrons]/D");
    tree->Branch("ElectronPhi",ElectronPhi,"ElectronPhi[NElectrons]/D");
    tree->Branch("ElectronChrg",ElectronChrg,"ElectronChrg[NElectrons]/D");

    // Jet-Electron variables
    tree->Branch("ElectronClosestPreJetDR",ElectronClosestPreJetDR,"ElectronClosestPreJetDR[NElectrons]/D");
    tree->Branch("ElectronClosestPreJetPt",ElectronClosestPreJetPt,"ElectronClosestPreJetPt[NElectrons]/D");
    tree->Branch("ElectronClosestComJetDR",ElectronClosestComJetDR,"ElectronClosestComJetDR[NElectrons]/D");
    tree->Branch("ElectronClosestComJetPt",ElectronClosestComJetPt,"ElectronClosestComJetPt[NElectrons]/D");

    // General kinematic variables
    tree->Branch("AlphaT",&AlphaT,"AlphaT/D");
    tree->Branch("AlphaT_Had",&AlphaT_Had,"AlphaT_Had/D");
    tree->Branch("AlphaT_Lep",&AlphaT_Lep,"AlphaT_Lep/D");
    tree->Branch("HT",&HT,"HT/D");
    tree->Branch("HT_Lep",&HT_Lep,"HT_Lep/D");
    tree->Branch("MHT",&MHT,"MHT/D");
    tree->Branch("MHTEta",&MHTEta,"MHTEta/D");
    tree->Branch("MHTPhi",&MHTPhi,"MHTPhi/D");
    tree->Branch("PFMHT",&PFMHT,"PFMHT/D");
    tree->Branch("PFMHTEta",&PFMHTEta,"PFMHTEta/D");
    tree->Branch("PFMHTPhi",&PFMHTPhi,"PFMHTPhi/D");
    tree->Branch("RecoilMET",&RecoilMET,"RecoilMET/D");
    tree->Branch("CaloMET",&CaloMET,"CaloMET/D");
    tree->Branch("CaloMETtypeII",&CaloMETtypeII,"CaloMETtypeII/D");
    tree->Branch("PFMET",&PFMET,"PFMET/D");
    tree->Branch("PFMETPhi",&PFMETPhi,"PFMETPhi/D");
    tree->Branch("MT",&MT,"MT/D");
    tree->Branch("PFMT",&PFMT,"PFMT/D");
    tree->Branch("LP",&LP,"LP/D");
    tree->Branch("PFLP",&PFLP,"PFLP/D");
    tree->Branch("BiasedDPhi",&BiasedDPhi,"BiasedDPhi/D");
    tree->Branch("Meff",&Meff,"Meff/D");

  }  
  
  bool AnalysisTree::Process(Event::Data &ev) {

 
    if (leptonType_ == "Muons") {
      if ( ev.LD_CommonMuons().accepted.size() ) {
        theLepton_ = ev.LD_CommonMuons().accepted;
        lepFlavour = 2;
      } else { return false; }
    }

    else if (leptonType_ == "Electrons") {
      if ( ev.LD_CommonElectrons().accepted.size() ) {
        theLepton_ = ev.LD_CommonElectrons().accepted;
        lepFlavour = 1;
      } else { return false; }
    }

    else {
      throw std::invalid_argument("Wrong Lepton Type supplied [for: mu= Muons, el= Electrons]");
      return false;
    }
    
    // print out HLT's
    //    cout << "\n";
    //    cout << " New Event " << "\n";
    //    for(std::map<std::string,bool>::const_iterator
    //	  it=ev.hlt()->begin();it!=ev.hlt()->end();++it){
    //      std::cout << it->first << " " << it->second << std::endl;
    //    }

      
    // Fill Event variables 
    wgt = ev.GetEventWeight();
    RunNumber = ev.RunNumber();     // cout << "RunNumber:   " << ev.RunNumber()   << " " << RunNumber   << "\n";
    EventNumber = ev.EventNumber(); // cout << "EventNumber: " << ev.EventNumber() << " " << EventNumber << "\n";
    LumiSection = ev.LumiSection(); // cout << "LumiSection: " << ev.LumiSection() << " " << LumiSection << "\n";
    NumPVs = ev.GetVertexSize();

    // Fill the HLT variables
    // HLT_Mu
    std::map<std::string,bool>::const_iterator itMu1=ev.hlt()->find("HLT_Mu9");
    if(itMu1==ev.hlt()->end()) trig_Mu9 = false;
    else trig_Mu9 = itMu1->second;
    std::map<std::string,bool>::const_iterator itMu2=ev.hlt()->find("HLT_Mu15_v1");
    if(itMu2==ev.hlt()->end()) trig_Mu15 = false;
    else trig_Mu15 = itMu2->second;

    // HLT_Ele
    std::map<std::string,bool>::const_iterator it5=ev.hlt()->find("HLT_Ele15_LW_L1R");
    if(it5==ev.hlt()->end()) trig_Ele15_LW = false;
    else trig_Ele15_LW = it5->second;
    std::map<std::string,bool>::const_iterator it4=ev.hlt()->find("HLT_Ele15_SW_L1R");
    if(it4==ev.hlt()->end()) trig_Ele15_SW = false;
    else trig_Ele15_SW = it4->second;
    std::map<std::string,bool>::const_iterator itEl1=ev.hlt()->find("HLT_Ele17_SW_EleId_L1R");
    if(itEl1==ev.hlt()->end()) trig_Ele17_SW_EleId = false;
    else trig_Ele17_SW_EleId = itEl1->second;

    // HLT_Jet
    std::map<std::string,bool>::const_iterator iy3=ev.hlt()->find("HLT_Jet50");
    if(iy3==ev.hlt()->end()) trig_Jet50 = false;
    else trig_Jet50 = iy3->second;
    std::map<std::string,bool>::const_iterator it=ev.hlt()->find("HLT_Jet80");
    if(it==ev.hlt()->end()) trig_Jet80 = false;
    else trig_Jet80 = it->second;

    
    // Fill the Jet variables
    NJet = ev.JD_CommonJets().accepted.size();
    UInt_t countJts = 0;
    for ( std::vector<Event::Jet const *>::const_iterator iJ = ev.JD_CommonJets().accepted.begin();
	  iJ != ev.JD_CommonJets().accepted.end();
	  iJ++ ) {

      JetPt[countJts] = (*iJ)->Pt();
      JetEta[countJts] = (*iJ)->Eta();
      JetPhi[countJts] = (*iJ)->Phi();
      JetCor[countJts] =  ev.GetJetCorrFactor((*iJ)->GetIndex());
      JetEMF[countJts] = (*iJ)->GetEmFrac();

      countJts++;
    } // ~ end of loop over the common Jts.


    // Fill the Muon variables
    NMuons = ev.LD_CommonMuons().accepted.size();
    UInt_t countMus = 0;
    for (std::vector<Event::Lepton const *>::const_iterator iMu = ev.LD_CommonMuons().accepted.begin(); 
	 iMu != ev.LD_CommonMuons().accepted.end(); iMu++) {

      MuonPt[countMus] = (*iMu)->Pt();
      MuonEta[countMus] = (*iMu)->Eta();
      MuonPhi[countMus] = (*iMu)->Phi();
      MuonChrg[countMus] = (*iMu)->GetCharge();
      if (genInfo_) {
	int iMatch = ev.leptonMatch(*iMu,2);
	MuonType[countMus] = ev.leptonType(iMatch); 
	//	  MuongPar[countMus] = ExtendedType(ev,*iMu,2);
	if ( iMatch>=0) { MuonGenMother[countMus] = abs(ev.MC_GenLeptons()[iMatch]->GetMotherID()); }
      }
      
      // Fill the Jet-Muon variables
      double muonPreJetPt_ = -999.;
      double muonPreJetEta_ = -999.;
      double muonPreJetPhi_ = -999.;
      double muonPreJetDRmin_ = 999.;
      double muonComJetPt_ = -999.;
      double muonComJetEta_ = -999.;
      double muonComJetPhi_ = -999.;
      double muonComJetDRmin_ = 999.;
      
      for (std::vector<Event::Jet>::const_iterator iMuj1=ev.JD_Jets().begin(); iMuj1!=ev.JD_Jets().end(); ++iMuj1) {
	double tmpMuonPreJetDR_ = fabs(ROOT::Math::VectorUtil::DeltaR(**iMu,*iMuj1));
	if (tmpMuonPreJetDR_ < muonPreJetDRmin_) { 
          muonPreJetPt_  = (iMuj1)->Pt();
          muonPreJetEta_ = (iMuj1)->Eta();
          muonPreJetPhi_ = (iMuj1)->Phi();
          muonPreJetDRmin_ = tmpMuonPreJetDR_;
	}
      } // ~end of loop over the PreJets
      MuonClosestPreJetPt[countMus]  = muonPreJetPt_;
      MuonClosestPreJetEta[countMus] = muonPreJetEta_;
      MuonClosestPreJetPhi[countMus] = muonPreJetPhi_;
      MuonClosestPreJetDR[countMus]  = muonPreJetDRmin_;
      
      for (std::vector<Event::Jet const *>::const_iterator iMuj2=ev.JD_CommonJets().accepted.begin(); iMuj2!=ev.JD_CommonJets().accepted.end(); iMuj2++) {
	double tmpMuonComJetDR_ = fabs(ROOT::Math::VectorUtil::DeltaR(**iMu,**iMuj2));
	if (tmpMuonComJetDR_ < muonComJetDRmin_) { 
          muonComJetPt_  = (*iMuj2)->Pt();
          muonComJetEta_ = (*iMuj2)->Eta();
          muonComJetPhi_ = (*iMuj2)->Phi();
          muonComJetDRmin_ = tmpMuonComJetDR_;
	}
      } // ~ end of loop over the common Jts.
      MuonClosestComJetPt[countMus]  = muonComJetPt_;
      MuonClosestComJetEta[countMus] = muonComJetEta_;
      MuonClosestComJetPhi[countMus] = muonComJetPhi_;
      MuonClosestComJetDR[countMus]  = muonComJetDRmin_;

      countMus++;
    } // ~ end of loop over the Common Muons.
  

    // Fill the Electron variables
    NElectrons = ev.LD_CommonElectrons().accepted.size();
    UInt_t countEls = 0;
    for (std::vector<Event::Lepton const *>::const_iterator iEl = ev.LD_CommonElectrons().accepted.begin(); 
	 iEl != ev.LD_CommonElectrons().accepted.end(); iEl++) {
      
      ElectronPt[countEls] = (*iEl)->Pt();
      ElectronEta[countEls] = (*iEl)->Eta();
      ElectronPhi[countEls] = (*iEl)->Phi();
      ElectronChrg[countEls] = (*iEl)->GetCharge();
      if (genInfo_) {
	int iMatch = ev.leptonMatch(*iEl,1);
	ElectronType[countEls] = ev.leptonType(iMatch); 
	//	  ElectrongPar[countEls] = ExtendedType(ev,*iEl,2);
	if ( iMatch>=0) { ElectronGenMother[countEls] = abs(ev.MC_GenLeptons()[iMatch]->GetMotherID()); }
      }
      
      // Fill the Jet-Electron variables
      double electronPreJetPt_ = -999.;
      double electronPreJetDRmin_ = 999.;
      double electronComJetPt_ = -999.;
      double electronComJetDRmin_ = 999.;
      
      for (std::vector<Event::Jet>::const_iterator iElj1=ev.JD_Jets().begin(); iElj1!=ev.JD_Jets().end(); ++iElj1) {
	double tmpElectronPreJetDR_ = fabs(ROOT::Math::VectorUtil::DeltaR (**iEl,*iElj1));
	if (tmpElectronPreJetDR_ < electronPreJetDRmin_) { electronPreJetDRmin_ = tmpElectronPreJetDR_; electronPreJetPt_ = (iElj1)->Pt(); }
      } // ~end of loop over the PreJets
      ElectronClosestPreJetDR[countEls] = electronPreJetDRmin_;
      ElectronClosestPreJetPt[countEls] = electronPreJetPt_; 
      
      for (std::vector<Event::Jet const *>::const_iterator iElj2=ev.JD_CommonJets().accepted.begin(); iElj2!=ev.JD_CommonJets().accepted.end(); iElj2++) {
	double tmpElectronComJetDR_ = fabs(ROOT::Math::VectorUtil::DeltaR (**iEl,**iElj2));
	if (tmpElectronComJetDR_ < electronComJetDRmin_) { electronComJetDRmin_ = tmpElectronComJetDR_; electronComJetPt_ = (*iElj2)->Pt(); }
      } // ~ end of loop over the common Jts.
      ElectronClosestComJetDR[countEls] = electronComJetDRmin_;
      ElectronClosestComJetPt[countEls] = electronComJetPt_; 	

      countEls++;
    } // ~ end of loop over the Common Electrons.
    
    
    // Fill the General variables
    
    if ( (ev.CommonObjects().size() >= mMinNumOfObjs_) && (ev.CommonObjects().size()<= mMaxNumOfObjs_) ) {
      AlphaT = ev.CommonAlphaT();
    } else { AlphaT = -999.; }
    if ( (ev.HadronicObjects().size() >= mMinNumOfObjs_) && (ev.HadronicObjects().size()<= mMaxNumOfObjs_) ) {
      AlphaT_Had = ev.HadronicAlphaT();
    } else { AlphaT_Had = -999.; }
    if ( (ev.LeptonicObjects().size() >= mMinNumOfObjs_) && (ev.LeptonicObjects().size()<= mMaxNumOfObjs_) ) {
      AlphaT_Lep = ev.LeptonicAlphaT();
    } else { AlphaT_Lep = -999.; }
    

    HT = ev.CommonHT();
    HT_Lep = ev.CommonHT() + theLepton_.at(0)->Pt();
    
    MHT = ev.CommonMHT().Pt();    
    MHTEta = ev.CommonMHT().Eta();
    MHTPhi = ev.CommonMHT().Phi();
    PFMHT = (ev.PFMET() + *(theLepton_.at(0))).Pt();
    PFMHTEta = (ev.PFMET() + *(theLepton_.at(0))).Eta();
    PFMHTPhi = (ev.PFMET() + *(theLepton_.at(0))).Phi();

    RecoilMET = ev.CommonRecoilMET().Pt();
    CaloMET = ev.CaloMET().Pt();
    CaloMETtypeII = ev.CaloMETtypeII().Pt();
    PFMET = ev.PFMET().Pt();
    PFMETPhi = ev.PFMET().Phi();

    PFMT = sqrt(2.*(theLepton_.at(0)->Pt())*(ev.PFMET().Pt())*(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton_.at(0)),ev.PFMET())))) ;

    LP = ( ((theLepton_.at(0)->Px())*(ev.CommonMHT().Px())) + ((theLepton_.at(0)->Py())*(ev.CommonMHT().Py())) ) /
      ((ev.CommonMHT().Pt())*(ev.CommonMHT().Pt()));
    PFLP = (((theLepton_.at(0)->Px())*((ev.PFMET()+(*(theLepton_.at(0)))).Px()))+((theLepton_.at(0)->Py())*((ev.PFMET()+(*(theLepton_.at(0)))).Py())))/
      ( ((ev.PFMET()+(*(theLepton_.at(0)))).Pt())*((ev.PFMET()+(*(theLepton_.at(0)))).Pt()) );

    BiasedDPhi = ev.CommonMinBiasDPhi();
  
    Meff = HT_Lep + ev.PFMET().Pt();

   
    tree->Fill();
    
    return true;
    
    } // ~end of process AnalysisTree
  

} // ~end of namespace
