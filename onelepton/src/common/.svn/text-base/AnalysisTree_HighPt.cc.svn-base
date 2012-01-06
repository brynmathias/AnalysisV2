#include "AnalysisTree_HighPt.hh"

using namespace Operation;

namespace OneLepton{
  
  void AnalysisTree_HighPt::BookHistos(){
    
    tree=new TTree("T","test");

    // Event variables
    tree->Branch("wgt",&wgt,"wgt/D");
    tree->Branch("RunNumber",&RunNumber,"RunNumber/I");
    tree->Branch("EventNumber",&EventNumber,"EventNumber/I");
    tree->Branch("LumiSection",&LumiSection,"LumiSection/I");
    tree->Branch("NumPVs",&NumPVs,"NumPVs/I");

    // Trigger
    tree->Branch("trig_Mu9",&trig_Mu9, "trig_Mu9/B");
    tree->Branch("trig_Mu11",&trig_Mu11, "trig_Mu11/B");
    tree->Branch("trig_Mu15",&trig_Mu15, "trig_Mu15/B");
    tree->Branch("trig_Mu5_HT70U",&trig_Mu5_HT70U, "trig_Mu5_HT70U/B");
    tree->Branch("trig_Ele15_LW",&trig_Ele15_LW, "trig_Ele15_LW/B");
    tree->Branch("trig_Ele15_SW",&trig_Ele15_SW, "trig_Ele15_SW/B");
    tree->Branch("trig_Ele17_SW_EleId",&trig_Ele17_SW_EleId, "trig_Ele17_SW_EleId/B");
    tree->Branch("trig_Jet50",&trig_Jet50, "trig_Jet50/B");
    tree->Branch("trig_Jet80",&trig_Jet80, "trig_Jet80/B");

    tree->Branch("unpresc_trig_Mu9",&unpresc_trig_Mu9, "unpresc_trig_Mu9/B");
    tree->Branch("unpresc_trig_Mu11",&unpresc_trig_Mu11, "unpresc_trig_Mu11/B");
    tree->Branch("unpresc_trig_Mu15",&unpresc_trig_Mu15, "unpresc_trig_Mu15/B");
    tree->Branch("unpresc_trig_Mu5_HT70U",&unpresc_trig_Mu5_HT70U, "unpresc_trig_Mu5_HT70U/B");
    tree->Branch("unpresc_trig_Ele15_LW",&unpresc_trig_Ele15_LW, "unpresc_trig_Ele15_LW/B");
    tree->Branch("unpresc_trig_Ele15_SW",&unpresc_trig_Ele15_SW, "unpresc_trig_Ele15_SW/B");
    tree->Branch("unpresc_trig_Ele17_SW_EleId",&unpresc_trig_Ele17_SW_EleId, "unpresc_trig_Ele17_SW_EleId/B");
    tree->Branch("unpresc_trig_Jet50",&unpresc_trig_Jet50, "unpresc_trig_Jet50/B");
    tree->Branch("unpresc_trig_Jet80",&unpresc_trig_Jet80, "unpresc_trig_Jet80/B");

    // Jet variables
    tree->Branch("NJet",&NJet,"NJet/I");
    tree->Branch("NJet30",&NJet30,"NJet30/I");
    tree->Branch("NJet40",&NJet40,"NJet40/I");
    tree->Branch("NJet50",&NJet50,"NJet50/I");
    tree->Branch("NJet60",&NJet60,"NJet60/I");
    tree->Branch("JetPt",JetPt,"JetPt[NJet]/D");
    tree->Branch("JetEta",JetEta,"JetEta[NJet]/D");
    tree->Branch("JetPhi",JetPhi,"JetPhi[NJet]/D");
    tree->Branch("JetCor",JetCor,"JetCor[NJet]/D");
    tree->Branch("JetEMF",JetEMF,"JetEMF[NJet]/D");

    // Jet-Raw variables
    tree->Branch("NJetRaw",&NJetRaw,"NJetRaw/I");
    tree->Branch("JetRawPt",JetRawPt,"JetRawPt[NJetRaw]/D");
    tree->Branch("JetRawEta",JetRawEta,"JetRawEta[NJetRaw]/D");
    tree->Branch("JetRawPhi",JetRawPhi,"JetRawPhi[NJetRaw]/D");
    tree->Branch("JetRawCor",JetRawCor,"JetRawCor[NJetRaw]/D");

    // Muon variables 
    tree->Branch("NMuons",&NMuons,"NMuons/I");
    tree->Branch("MuonPt",MuonPt,"MuonPt[NMuons]/D");
    tree->Branch("MuonEta",MuonEta,"MuonEta[NMuons]/D");
    tree->Branch("MuonPhi",MuonPhi,"MuonPhi[NMuons]/D");
    tree->Branch("MuonChrg",MuonChrg,"MuonChrg[NMuons]/D");
    tree->Branch("MuonType",MuonType,"MuonType[NMuons]/I");
    tree->Branch("MuongPar",MuongPar,"MuongPar[NMuons]/I");
    tree->Branch("MuonGenMother",MuonGenMother,"MuonGenMother[NMuons]/I");
    tree->Branch("MuonInrTrkD0BS",MuonInrTrkD0BS,"MuonInrTrkD0BS[NMuons]/D");
    tree->Branch("MuonInrTrkD0PV",MuonInrTrkD0PV,"MuonInrTrkD0PV[NMuons]/D");
    tree->Branch("MuonInrTrkD0err",MuonInrTrkD0err,"MuonInrTrkD0err[NMuons]/D");
    tree->Branch("MuonGlbTrkD0BS",MuonGlbTrkD0BS,"MuonGlbTrkD0BS[NMuons]/D");
    tree->Branch("MuonGlbTrkD0PV",MuonGlbTrkD0PV,"MuonGlbTrkD0PV[NMuons]/D");
    tree->Branch("MuonGlbTrkD0err",MuonGlbTrkD0err,"MuonGlbTrkD0err[NMuons]/D");
    tree->Branch("MuonRelCombIso",MuonRelCombIso,"MuonRelCombIso[NMuons]/D");

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
    tree->Branch("ElectronType",ElectronType,"ElectronType[NElectrons]/I");
    tree->Branch("ElectrongPar",ElectrongPar,"ElectrongPar[NElectrons]/I");
    tree->Branch("ElectronGenMother",ElectronGenMother,"ElectronGenMother[NElectrons]/I");

    // Jet-Electron variables
    tree->Branch("ElectronClosestPreJetDR",ElectronClosestPreJetDR,"ElectronClosestPreJetDR[NElectrons]/D");
    tree->Branch("ElectronClosestPreJetPt",ElectronClosestPreJetPt,"ElectronClosestPreJetPt[NElectrons]/D");
    tree->Branch("ElectronClosestComJetDR",ElectronClosestComJetDR,"ElectronClosestComJetDR[NElectrons]/D");
    tree->Branch("ElectronClosestComJetPt",ElectronClosestComJetPt,"ElectronClosestComJetPt[NElectrons]/D");


    // General kinematic variables
    tree->Branch("AlphaT",&AlphaT,"AlphaT/D");
    tree->Branch("AlphaT_Had",&AlphaT_Had,"AlphaT_Had/D");
    tree->Branch("AlphaT_Lep",&AlphaT_Lep,"AlphaT_Lep/D");

    // General kinematic variables -std-
    tree->Branch("HT",&HT,"HT/D");
    tree->Branch("HT_Lep",&HT_Lep,"HT_Lep/D");
    tree->Branch("MHT",&MHT,"MHT/D");
    tree->Branch("MHTEta",&MHTEta,"MHTEta/D");
    tree->Branch("MHTPhi",&MHTPhi,"MHTPhi/D");
    tree->Branch("CaloMET",&CaloMET,"CaloMET/D");
    tree->Branch("CaloMETtypeII",&CaloMETtypeII,"CaloMETtypeII/D");
    tree->Branch("CaloMETtypeIIPhi",&CaloMETtypeIIPhi,"CaloMETtypeIIPhi/D");
    tree->Branch("MT",&MT,"MT/D");
    tree->Branch("LP",&LP,"LP/D");
    tree->Branch("BiasedDPhi",&BiasedDPhi,"BiasedDPhi/D");
    tree->Branch("Meff",&Meff,"Meff/D");

    // General kinematic variables -pf-
    tree->Branch("PFMET",&PFMET,"PFMET/D");
    tree->Branch("PFMETPhi",&PFMETPhi,"PFMETPhi/D");
    tree->Branch("PFMET_typeI",&PFMET_typeI,"PFMET_typeI/D");

    // General kinematic variables -hybrid-
    tree->Branch("PFMHT_h",&PFMHT_h,"PFMHT_h/D");
    tree->Branch("PFMT_h",&PFMT_h,"PFMT_h/D");
    tree->Branch("PFLP_h",&PFLP_h,"PFLP_h/D");

    tree->Branch("HT12",&HT12,"HT12/D");
    tree->Branch("HT123",&HT123,"HT123/D");

    tree->Branch("MHT12",&MHT12,"MHT12/D");

    tree->Branch("M2_sca",&M2_sca,"M2_sca/D");
    tree->Branch("MinvMax",&MinvMax,"MinvMax/D");

    tree->Branch("M3_sca",&M3_sca,"M3_sca/D");
    tree->Branch("M3_vec",&M3_vec,"M3_vec/D");
    tree->Branch("M3lep_sca",&M3lep_sca,"M3lep_sca/D");
    tree->Branch("M3lep_vec",&M3lep_vec,"M3lep_vec/D");

    tree->Branch("M_LepClosestJet",&M_LepClosestJet,"M_LepClosestJet/D");
    tree->Branch("M_LepHighestJet",&M_LepHighestJet,"M_LepHighestJet/D");
    tree->Branch("M_LepHighestJet2",&M_LepHighestJet2,"M_LepHighestJet2/D");

    tree->Branch("DPhi_LepMET",&DPhi_LepMET,"DPhi_LepMET/D");
    tree->Branch("DPhi_LepMHT",&DPhi_LepMHT,"DPhi_LepMHT/D");
    tree->Branch("DPhi_LepJetmin",&DPhi_LepJetmin,"DPhi_LepJetmin/D");

    tree->Branch("DPhi_Jet1Jet2",&DPhi_Jet1Jet2,"DPhi_Jet1Jet2/D");
    tree->Branch("DR_Jet1Jet2",&DR_Jet1Jet2,"DR_Jet1Jet2/D");

    tree->Branch("DPhi_AllJetsMin",&DPhi_AllJetsMin,"DPhi_AllJetsMin/D");
    tree->Branch("DR_AllJetsMin",&DR_AllJetsMin,"DR_AllJetsMin/D");

    // Razor Variables
    tree->Branch("MR",&MR,"MR/D");
    tree->Branch("MRt",&MRt,"MRt/D");
    tree->Branch("R",&R,"R/D");


    // Gen variables
    tree->Branch("NPartons",&NPartons,"NPartons/I");
    tree->Branch("PartonPt",PartonPt,"PartonPt[NPartons]/D");
    tree->Branch("PartonEta",PartonEta,"PartonEta[NPartons]/D");
    tree->Branch("PartonPhi",PartonPhi,"PartonPhi[NPartons]/D");

    tree->Branch("NGenLeptons",&NGenLeptons,"NGenLeptons/I");
    tree->Branch("GenLeptonPt",GenLeptonPt,"GenLeptonPt[NGenLeptons]/D");
    tree->Branch("GenLeptonEta",GenLeptonEta,"GenLeptonEta[NGenLeptons]/D");
    tree->Branch("GenLeptonPhi",GenLeptonPhi,"GenLeptonPhi[NGenLeptons]/D");
    tree->Branch("GenLeptonChrg",GenLeptonChrg,"GenLeptonChrg[NGenLeptons]/D");

    tree->Branch("NGenNuLeptons",&NGenNuLeptons,"NGenNuLeptons/I");
    tree->Branch("GenNuLeptonPt",GenNuLeptonPt,"GenNuLeptonPt[NGenNuLeptons]/D");
    tree->Branch("GenNuLeptonEta",GenNuLeptonEta,"GenNuLeptonEta[NGenNuLeptons]/D");
    tree->Branch("GenNuLeptonPhi",GenNuLeptonPhi,"GenNuLeptonPhi[NGenNuLeptons]/D");
    
    tree->Branch("GenWPt",&GenWPt,"GenWPt/D");
    tree->Branch("GenWEta",&GenWEta,"GenWEta/D");
    tree->Branch("GenWPhi",&GenWPhi,"GenWPhi/D");

    tree->Branch("DPhi_LepPtW",&DPhi_LepPtW,"DPhi_LepPtW/D");
    tree->Branch("DPhi_LepNuLep",&DPhi_LepNuLep,"DPhi_LepNuLep/D");

    tree->Branch("GenMuonFromW",&GenMuonFromW,"GenMuonFromW/I");

  }  
  
  bool AnalysisTree_HighPt::Process(Event::Data &ev) {

 
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
	//	if (ev.LD_SecElectrons().size()) { thePFLepton_ = ev.LD_SecElectrons(); }
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
    RunNumber = ev.RunNumber();      //cout << "RunNumber:   " << ev.RunNumber()   << " " << RunNumber   << "\n";
    EventNumber = ev.EventNumber();  //cout << "EventNumber: " << ev.EventNumber() << " " << EventNumber << "\n";
    LumiSection = ev.LumiSection();  //cout << "LumiSection: " << ev.LumiSection() << " " << LumiSection << "\n";
    NumPVs = ev.GetVertexSize();

    // Fill the HLT variables
    // HLT_Mu
    std::map<std::string,bool>::const_iterator itMu1=ev.hlt()->find("HLT_Mu9");
    if(itMu1==ev.hlt()->end()) trig_Mu9 = false;
    else trig_Mu9 = itMu1->second;
    std::map<std::string,bool>::const_iterator itMu2=ev.hlt()->find("HLT_Mu11");
    if(itMu2==ev.hlt()->end()) trig_Mu11 = false;
    else trig_Mu11 = itMu2->second;
    std::map<std::string,bool>::const_iterator itMu3=ev.hlt()->find("HLT_Mu15_v1");
    if(itMu3==ev.hlt()->end()) trig_Mu15 = false;
    else trig_Mu15 = itMu3->second;
    std::map<std::string,bool>::const_iterator itMu4=ev.hlt()->find("HLT_Mu5_HT70U_v3");
    if(itMu4==ev.hlt()->end()) trig_Mu5_HT70U = false;
    else trig_Mu5_HT70U = itMu4->second;

    // HLT_Ele
    std::map<std::string,bool>::const_iterator itEl1=ev.hlt()->find("HLT_Ele15_LW_L1R");
    if(itEl1==ev.hlt()->end()) trig_Ele15_LW = false;
    else trig_Ele15_LW = itEl1->second;
    std::map<std::string,bool>::const_iterator itEl2=ev.hlt()->find("HLT_Ele15_SW_L1R");
    if(itEl2==ev.hlt()->end()) trig_Ele15_SW = false;
    else trig_Ele15_SW = itEl2->second;
    std::map<std::string,bool>::const_iterator itEl3=ev.hlt()->find("HLT_Ele17_SW_EleId_L1R");
    if(itEl3==ev.hlt()->end()) trig_Ele17_SW_EleId = false;
    else trig_Ele17_SW_EleId = itEl3->second;

    // HLT_Jet
    std::map<std::string,bool>::const_iterator itJt1=ev.hlt()->find("HLT_Jet50");
    if(itJt1==ev.hlt()->end()) trig_Jet50 = false;
    else trig_Jet50 = itJt1->second;
    std::map<std::string,bool>::const_iterator itJt2=ev.hlt()->find("HLT_Jet80");
    if(itJt2==ev.hlt()->end()) trig_Jet80 = false;
    else trig_Jet80 = itJt2->second;


    // check if the triggers where unprescaled

    //  -- muons --
    std::map<std::string,int>::const_iterator itMuPreSc1=ev.hlt_prescaled()->find("HLT_Mu9");
    if (itMuPreSc1==ev.hlt_prescaled()->end()) unpresc_trig_Mu9 = false;
    else if (itMuPreSc1->second == 1) unpresc_trig_Mu9 = true; 
    else unpresc_trig_Mu9 = false;
    std::map<std::string,int>::const_iterator itMuPreSc2=ev.hlt_prescaled()->find("HLT_Mu11");
    if (itMuPreSc2==ev.hlt_prescaled()->end()) unpresc_trig_Mu11 = false;
    else if (itMuPreSc2->second == 1) unpresc_trig_Mu11 = true; 
    else unpresc_trig_Mu11 = false;
    std::map<std::string,int>::const_iterator itMuPreSc3=ev.hlt_prescaled()->find("HLT_Mu15_v1");
    if (itMuPreSc3==ev.hlt_prescaled()->end()) unpresc_trig_Mu15 = false;
    else if (itMuPreSc3->second == 1) unpresc_trig_Mu15 = true; 
    else unpresc_trig_Mu15 = false;
    std::map<std::string,int>::const_iterator itMuPreSc4=ev.hlt_prescaled()->find("HLT_Mu5_HT70U_v3");
    if (itMuPreSc4==ev.hlt_prescaled()->end()) unpresc_trig_Mu5_HT70U = false;
    else if (itMuPreSc4->second == 1) unpresc_trig_Mu5_HT70U = true; 
    else unpresc_trig_Mu5_HT70U = false;

    //  -- electrons --
    std::map<std::string,int>::const_iterator itElPreSc1=ev.hlt_prescaled()->find("HLT_Ele15_LW_L1R");
    if (itElPreSc1==ev.hlt_prescaled()->end()) unpresc_trig_Ele15_LW = false;
    else if (itElPreSc1->second == 1) unpresc_trig_Ele15_LW = true; 
    else unpresc_trig_Ele15_LW = false;
    std::map<std::string,int>::const_iterator itElPreSc2=ev.hlt_prescaled()->find("HLT_Ele15_SW_L1R");
    if (itElPreSc2==ev.hlt_prescaled()->end()) unpresc_trig_Ele15_SW = false;
    else if (itElPreSc2->second == 1) unpresc_trig_Ele15_SW = true; 
    else unpresc_trig_Ele15_SW = false;
    std::map<std::string,int>::const_iterator itElPreSc3=ev.hlt_prescaled()->find("HLT_Ele17_SW_EleId_L1R");
    if (itElPreSc3==ev.hlt_prescaled()->end()) unpresc_trig_Ele17_SW_EleId = false;
    else if (itElPreSc3->second == 1) unpresc_trig_Ele17_SW_EleId = true; 
    else unpresc_trig_Ele17_SW_EleId = false;

    // -- jets --
    std::map<std::string,int>::const_iterator itJtPreSc1=ev.hlt_prescaled()->find("HLT_Jet50");
    if (itJtPreSc1==ev.hlt_prescaled()->end()) unpresc_trig_Jet50 = false;
    else if (itJtPreSc1->second == 1) unpresc_trig_Jet50 = true; 
    else unpresc_trig_Jet50 = false;
    std::map<std::string,int>::const_iterator itJtPreSc2=ev.hlt_prescaled()->find("HLT_Jet80");
    if (itJtPreSc2==ev.hlt_prescaled()->end()) unpresc_trig_Jet80 = false;
    else if (itJtPreSc2->second == 1) unpresc_trig_Jet80 = true; 
    else unpresc_trig_Jet80 = false;


    
    // Fill the Jet variables
    NJet = ev.JD_CommonJets().accepted.size();
    UInt_t countJts = 0;
    UInt_t countJts30 = 0; UInt_t countJts40 = 0; UInt_t countJts50 = 0; UInt_t countJts60 = 0;
    for ( std::vector<Event::Jet const *>::const_iterator iJ = ev.JD_CommonJets().accepted.begin();
	  iJ != ev.JD_CommonJets().accepted.end();
	  iJ++ ) {

      if ( ((*iJ)->Pt()>30.) && (fabs((*iJ)->Eta())<2.4) ) {
	countJts30++;
      }
      
      if ( ((*iJ)->Pt()>40.) && (fabs((*iJ)->Eta())<2.4) ) {
        countJts40++;
      }
      
      if ( ((*iJ)->Pt()>50.) && (fabs((*iJ)->Eta())<2.4) ) {
        countJts50++;
      }

      if ( ((*iJ)->Pt()>60.) && (fabs((*iJ)->Eta())<2.4) ) {
        countJts60++;
      }
      
      JetPt[countJts] = (*iJ)->Pt();
      JetEta[countJts] = (*iJ)->Eta();
      JetPhi[countJts] = (*iJ)->Phi();
      JetCor[countJts] =  ev.GetJetCorrFactor((*iJ)->GetIndex());
      JetEMF[countJts] = (*iJ)->GetEmFrac();

      countJts++;
    } // ~ end of loop over the common Jts.
    NJet30 = countJts30;
    NJet40 = countJts40;
    NJet50 = countJts50;
    NJet60 = countJts60;


    // Fill the Raw Jet variables
    NJetRaw = ev.JD_Jets().size();
    UInt_t countJtsRaw = 0;
    for (std::vector<Event::Jet>::const_iterator irj1=ev.JD_Jets().begin(); irj1!=ev.JD_Jets().end(); ++irj1) {

      JetRawPt[countJtsRaw]  = (irj1)->Pt();
      JetRawEta[countJtsRaw] = (irj1)->Eta();
      JetRawPhi[countJtsRaw] = (irj1)->Phi();
      JetRawCor[countJtsRaw] = ev.GetJetCorrFactor((irj1)->GetIndex());
    
      countJtsRaw++;
  } // ~end of loop over the PreJets


    // Fill the Muon variables
    NMuons = ev.LD_CommonMuons().accepted.size();
    UInt_t countMus = 0;
    for (std::vector<Event::Lepton const *>::const_iterator iMu = ev.LD_CommonMuons().accepted.begin(); 
	 iMu != ev.LD_CommonMuons().accepted.end(); iMu++) {

      MuonPt[countMus] = (*iMu)->Pt();
      MuonEta[countMus] = (*iMu)->Eta();
      MuonPhi[countMus] = (*iMu)->Phi();
      MuonChrg[countMus] = (*iMu)->GetCharge();
      MuonInrTrkD0BS[countMus] = ev.GetMuonInnerTrackDxyBS((*iMu)->GetIndex());
      MuonInrTrkD0PV[countMus] = ev.GetMuonInnerTrackDxy((*iMu)->GetIndex());
      MuonInrTrkD0err[countMus] = ev.GetMuonInnerTrackDxyError((*iMu)->GetIndex());
      MuonGlbTrkD0BS[countMus] = ev.GetMuonGlobalTrackdxyBS((*iMu)->GetIndex());
      MuonGlbTrkD0PV[countMus] = ev.GetMuonGlobalTrackdxy((*iMu)->GetIndex());
      MuonGlbTrkD0err[countMus] = ev.GetMuonGlobalTrackdxyError((*iMu)->GetIndex());
      MuonRelCombIso[countMus] = (*iMu)->GetCombIsolation();

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

    BiasedDPhi = ev.CommonMinBiasDPhi();


    // ------------------------------------
    // Fill the General variables -std-

    HT               = ev.CommonHT();
    HT_Lep           = ev.CommonHT() + theLepton_.at(0)->Pt();
    MHT              = (ev.CaloMETtypeII() + *(theLepton_.at(0))).Pt();    
    MHTEta           = (ev.CaloMETtypeII() + *(theLepton_.at(0))).Eta();
    MHTPhi           = (ev.CaloMETtypeII() + *(theLepton_.at(0))).Phi();
    CaloMET          = ev.CaloMET().Pt();
    CaloMETtypeII    = ev.CaloMETtypeII().Pt();
    CaloMETtypeIIPhi = ev.CaloMETtypeII().Phi();
    MT               = sqrt(2.*(theLepton_.at(0)->Pt())*(ev.CaloMETtypeII().Pt())*(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton_.at(0)),ev.CaloMETtypeII())))) ;
    LP               = (((theLepton_.at(0)->Px())*((ev.CaloMETtypeII()+(*(theLepton_.at(0)))).Px()))+((theLepton_.at(0)->Py())*((ev.CaloMETtypeII()+(*(theLepton_.at(0)))).Py())))/
      ( ((ev.CaloMETtypeII()+(*(theLepton_.at(0)))).Pt())*((ev.CaloMETtypeII()+(*(theLepton_.at(0)))).Pt()) );
    Meff = HT_Lep + ev.PFMET().Pt();


    PFMET    = ev.PFMET().Pt();
    PFMETPhi = ev.PFMET().Phi();
    PFMET_typeI = ev.metP4pfTypeI()->Pt();


    // "hybrid" version of PFMHT, PFMT, PFLP
    PFMHT_h = (ev.PFMET() + *(theLepton_.at(0))).Pt();
    PFMT_h  = sqrt(2.*(theLepton_.at(0)->Pt())*(ev.PFMET().Pt())*(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton_.at(0)),ev.PFMET())))) ;
    PFLP_h  = (((theLepton_.at(0)->Px())*((ev.PFMET()+(*(theLepton_.at(0)))).Px()))+((theLepton_.at(0)->Py())*((ev.PFMET()+(*(theLepton_.at(0)))).Py())))/
      ( ((ev.PFMET()+(*(theLepton_.at(0)))).Pt())*((ev.PFMET()+(*(theLepton_.at(0)))).Pt()) );
    																	


    TLorentzVector lep;
    lep.SetPxPyPzE(theLepton_.at(0)->Px(),theLepton_.at(0)->Py(),theLepton_.at(0)->Pz(),theLepton_.at(0)->E());
    

    // ----- at least 1 jet
    if (ev.JD_CommonJets().accepted.size()>=1) {

      //      ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), ev.PFMET() ) // DPhi calculation
    } // ~ end of cheking if there are at least 2 jets in the event
    //    else {}


    // ----- at least 2 jets
    if (ev.JD_CommonJets().accepted.size()>=2) {

      TLorentzVector jeta1;  TLorentzVector jeta2;
      jeta1.SetPxPyPzE(ev.JD_CommonJets().accepted[0]->Px(),ev.JD_CommonJets().accepted[0]->Py(),ev.JD_CommonJets().accepted[0]->Pz(),ev.JD_CommonJets().accepted[0]->E());
      jeta2.SetPxPyPzE(ev.JD_CommonJets().accepted[1]->Px(),ev.JD_CommonJets().accepted[1]->Py(),ev.JD_CommonJets().accepted[1]->Pz(),ev.JD_CommonJets().accepted[1]->E());


      HT12 = jeta1.Pt()+jeta2.Pt();
      TLorentzVector tmpJet; tmpJet = jeta1 + jeta2; MHT12 = tmpJet.Pt();
      M2_sca = (jeta1 + jeta2).M();
      M3lep_sca = (lep +jeta1 + jeta2).M();



      MinvMax = -999.; M3lep_vec = -999.;
      int count1j = 0; int count2j = 0;
      TLorentzVector ja; ja.SetPxPyPzE(0.,0.,0.,0.);
      for (std::vector<Event::Jet const *>::const_iterator ij1=ev.JD_CommonJets().accepted.begin(); ij1!=ev.JD_CommonJets().accepted.end(); ij1++) {

        TLorentzVector jj1;
        count1j++;
        jj1.SetPxPyPzE((*ij1)->Px(),(*ij1)->Py(),(*ij1)->Pz(),(*ij1)->E());

	for (std::vector<Event::Jet const *>::const_iterator ij2=ev.JD_CommonJets().accepted.begin(); ij2!=ev.JD_CommonJets().accepted.end(); ij2++) {

          TLorentzVector jj2;
          count2j++;
          if (count2j>count1j) { jj2.SetPxPyPzE((*ij2)->Px(),(*ij2)->Py(),(*ij2)->Pz(),(*ij2)->E()); }

	  if ( ((jj1+jj2).Pt()) > ja.Pt()) { ja.SetPxPyPzE((jj1+jj2).Px(),(jj1+jj2).Py(),(jj1+jj2).Pz(),(jj1+jj2).E()); M3lep_vec = (lep+jj1+jj2).M(); }
	  if ( ((jj1+jj2).M()) > MinvMax) { MinvMax = (jj1+jj2).M(); }

        } // 2nd iteration over jets
      } // 1st iteration over jets
      
    } // ~ end of cheking if there are at least 2 jets in the event
    else { 
      HT12 = -999.; MHT12 = -999.; M2_sca = -999.; MinvMax = -999.;
      M3lep_sca = -999.; M3lep_vec = -999.;
    }


    // ----- at least 3 jets
    if (ev.JD_CommonJets().accepted.size()>=3) {

      TLorentzVector jetb1;  TLorentzVector jetb2; TLorentzVector jetb3;
      jetb1.SetPxPyPzE(ev.JD_CommonJets().accepted[0]->Px(),ev.JD_CommonJets().accepted[0]->Py(),ev.JD_CommonJets().accepted[0]->Pz(),ev.JD_CommonJets().accepted[0]->E());
      jetb2.SetPxPyPzE(ev.JD_CommonJets().accepted[1]->Px(),ev.JD_CommonJets().accepted[1]->Py(),ev.JD_CommonJets().accepted[1]->Pz(),ev.JD_CommonJets().accepted[1]->E());
      jetb3.SetPxPyPzE(ev.JD_CommonJets().accepted[2]->Px(),ev.JD_CommonJets().accepted[2]->Py(),ev.JD_CommonJets().accepted[2]->Pz(),ev.JD_CommonJets().accepted[2]->E());


      HT123 = jetb1.Pt()+jetb2.Pt()+jetb3.Pt();
      M3_sca = (jetb1 + jetb2 + jetb3).M();


      TLorentzVector jb; jb.SetPxPyPzE(0.,0.,0.,0.);
      M3_vec = -9999.;
      int count1 = 0; int count2 = 0; int count3 = 0;
      for (std::vector<Event::Jet const *>::const_iterator ija=ev.JD_CommonJets().accepted.begin(); ija!=ev.JD_CommonJets().accepted.end(); ija++) {

        TLorentzVector j1;
        count1++;
        j1.SetPxPyPzE((*ija)->Px(),(*ija)->Py(),(*ija)->Pz(),(*ija)->E());
	
        for (std::vector<Event::Jet const *>::const_iterator ijb=ev.JD_CommonJets().accepted.begin(); ijb!=ev.JD_CommonJets().accepted.end(); ijb++) {
	  
          TLorentzVector j2;
          count2++;
          if (count2>count1) { j2.SetPxPyPzE((*ijb)->Px(),(*ijb)->Py(),(*ijb)->Pz(),(*ijb)->E()); }

          for (std::vector<Event::Jet const *>::const_iterator ijc=ev.JD_CommonJets().accepted.begin(); ijc!=ev.JD_CommonJets().accepted.end(); ijc++) {
	    
            TLorentzVector j3;
            count3++;
            if (count3>count2) { j3.SetPxPyPzE((*ijc)->Px(),(*ijc)->Py(),(*ijc)->Pz(),(*ijc)->E()); }
	    
            //      cout << ev.EventNumber() << " " << ev.JD_CommonJets().accepted.size() << " " << count1 << " " << count2 << " " << count3 << " ";
            //      cout << M3_vec << " " << j.Pt() << " " << (j1+j2+j3).Pt() << "\n";
            if ( ((j1+j2+j3).Pt()) > jb.Pt()) { jb.SetPxPyPzE((j1+j2+j3).Px(),(j1+j2+j3).Py(),(j1+j2+j3).Pz(),(j1+j2+j3).E()); M3_vec = (j1+j2+j3).M(); }

          } // 3nd iteration over jets
        } // 2nd iteration over jets
      } // 1st iteration over jets

    } else { 
      HT123 = -999.;
      M3_sca = -999.;  M3_vec = -999.;
    }

    TLorentzVector mht;
    mht.SetPxPyPzE((ev.PFMET() + *(theLepton_.at(0))).Px(),(ev.PFMET() + *(theLepton_.at(0))).Py(),(ev.PFMET() + *(theLepton_.at(0))).Pz(),(ev.PFMET() + *(theLepton_.at(0))).E());

    DPhi_LepMET = ROOT::Math::VectorUtil::DeltaPhi(lep,ev.PFMET());
    DPhi_LepMHT = ROOT::Math::VectorUtil::DeltaPhi(lep,mht);


    DPhi_LepJetmin = 999.; double DR_LepJet = 99999.;

    UInt_t count1c = 0;
    for (std::vector<Event::Jet const *>::const_iterator ijc=ev.JD_CommonJets().accepted.begin(); ijc!=ev.JD_CommonJets().accepted.end(); ijc++) {

      TLorentzVector jc1;
      jc1.SetPxPyPzE((*ijc)->Px(),(*ijc)->Py(),(*ijc)->Pz(),(*ijc)->E());

      double tmpDPhi_LepJetmin = ROOT::Math::VectorUtil::DeltaPhi(lep,jc1);
      if (DPhi_LepJetmin>tmpDPhi_LepJetmin) { DPhi_LepJetmin = tmpDPhi_LepJetmin; }

      if (count1c==0) { M_LepHighestJet = (lep+jc1).M(); }
      if (count1c==1) { M_LepHighestJet2 = (lep+jc1).M(); }

      double tmpDR_LepJet = ROOT::Math::VectorUtil::DeltaR(lep,jc1);
      if (DR_LepJet>tmpDR_LepJet) { M_LepClosestJet = (lep+jc1).M(); }

      count1c++;
      }


    MR  = ev.Razor_MR();
    MRt = ev.Razor_MRt();
    R = ev.Razor_MRt()/ev.Razor_MR();



    // Fill the GenVariables

    if (genInfo_) {
      //      cout << "--HERE--0" << "\n";
      GenMatrixBin myGenMatrixBin(&ev);
      
      const Event::GenObject* genW_;
      
      
      TLorentzVector genLep;
      TLorentzVector genW;
      TLorentzVector genNuLep;
      
      
      bool lepRecoGenMatching = false;
      UInt_t tmpGenCounter = 0;     UInt_t countGenLep = 0;
      double tmpGenLeptonMotherIndx = -9999999.;

      //      cout << "--HERE--1" << "\n";
      if (leptonType_ == "Muons") {
	//	cout << "--HERE--2" << "\n";
	for ( std::vector<Event::GenObject const *>::const_iterator iGMu = myGenMatrixBin.the_GenMuon.begin();
	      iGMu != myGenMatrixBin.the_GenMuon.end();
	      iGMu++ ) {
	  
	  tmpGenCounter++;
	  
	  
	  // condition 1: is there a GenLepton for the RecoLepton?
	  double tmpDRLep = fabs(ROOT::Math::VectorUtil::DeltaR(lep,**iGMu));
	  if (tmpDRLep>0.3) { continue; }
	  lepRecoGenMatching = true;
	  
	  tmpGenLeptonMotherIndx = (*iGMu)->GetMother();

	  
	  GenLeptonPt[countGenLep]  = myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->Pt();
	  GenLeptonEta[countGenLep] = myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->Eta();
	  GenLeptonPhi[countGenLep] = myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->Phi();
	  if (((*iGMu)->GetID())>0) { GenLeptonChrg[countGenLep] = -1.; } else { GenLeptonChrg[countGenLep] = 1.; }
	  
	  genLep.SetPxPyPzE(
			    myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->Px(),
			    myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->Py(),
			    myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->Pz(),
			    myGenMatrixBin.the_GenMuon.at(tmpGenCounter-1)->E()
			    );
	  
	  countGenLep++;
	} // ~end of looping over the GenMuons
	NGenLeptons = countGenLep;
	//	cout << "--HERE--3" << "\n";
      } else {
	//	cout << "--HERE--4" << "\n";
	for ( std::vector<Event::GenObject const *>::const_iterator iGEl = myGenMatrixBin.the_GenEli.begin();
	      iGEl != myGenMatrixBin.the_GenEli.end();
	      iGEl++ ) {

	  tmpGenCounter++;
	  
	  
	  // condition 1: is there a GenLepton for the RecoLepton?
	  double tmpDRLep = fabs(ROOT::Math::VectorUtil::DeltaR(lep,**iGEl));
	  if (tmpDRLep>0.3) { continue; }
	  lepRecoGenMatching = true;
	  
	  tmpGenLeptonMotherIndx = (*iGEl)->GetMother();
	  //      GenMuonMother = (*iGEl)->GetMotherID();
	  
	  GenLeptonPt[countGenLep]  = myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->Pt();
	  GenLeptonEta[countGenLep] = myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->Eta();
	  GenLeptonPhi[countGenLep] = myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->Phi();
	  if (((*iGEl)->GetID())>0) { GenLeptonChrg[countGenLep] = -1.; } else { GenLeptonChrg[countGenLep] = 1.; }
	  
	  genLep.SetPxPyPzE(
			    myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->Px(),
			    myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->Py(),
			    myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->Pz(),
			    myGenMatrixBin.the_GenEli.at(tmpGenCounter-1)->E()
			    );
	  
	  countGenLep++;
	} // ~end of looping over the GenMuons
	NGenLeptons = countGenLep;
	//	cout << "--HERE--5" << "\n";
      }
      //      cout << "--HERE--6" << "\n";
      // condition 2: is the GenMuon from a W?
      bool lepIsFromW = false;
      //      cout << "--HERE--7" << "\n";
      for ( std::vector<Event::GenObject const *>::const_iterator iGW = myGenMatrixBin.the_GenW.begin();
	    iGW != myGenMatrixBin.the_GenW.end();
	    iGW++ ) {
	
	if ( ((*iGW)->GetIndex()) == (tmpGenLeptonMotherIndx) ) { genW_ = (*iGW);  lepIsFromW = true; }
	
      } // ~end of looping over the GenWs
      
      //      cout << "--HERE--8" << "\n";
      
      if ( (lepRecoGenMatching) && (lepIsFromW) ) {
	//	cout << "--HERE--9" << "\n";
	GenMuonFromW = 1;
	
	UInt_t tmpGenNuCounter = 0;     UInt_t countGenNuLep = 0;

	if (leptonType_ == "Muons") {
	  //	  cout << "--HERE--10" << "\n";
	  for ( std::vector<Event::GenObject const *>::const_iterator iGNuMu = myGenMatrixBin.the_GenMuonNu.begin();
		iGNuMu != myGenMatrixBin.the_GenMuonNu.end();
		iGNuMu++ ) {
	    
	    if ((*iGNuMu)->GetMother() != tmpGenLeptonMotherIndx) { continue; }
	    
	    tmpGenNuCounter++;
	    
	    GenNuLeptonPt[countGenNuLep]  = myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->Pt();
	    GenNuLeptonEta[countGenNuLep] = myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->Eta();
	    GenNuLeptonPhi[countGenNuLep] = myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->Phi();
	    
	    genNuLep.SetPxPyPzE(
				myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->Px(),
				myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->Py(),
				myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->Pz(),
				myGenMatrixBin.the_GenMuonNu.at(tmpGenNuCounter-1)->E()
				);
	    
	    countGenNuLep++;
	  } // ~end of looping over the GenNuMuons
	  NGenNuLeptons = countGenNuLep;	
	  //	  cout << "--HERE--11" << "\n";
	} else {
	  //	  cout << "--HERE--12" << "\n";
	  for ( std::vector<Event::GenObject const *>::const_iterator iGNuMu = myGenMatrixBin.the_GenEliNu.begin();
                iGNuMu != myGenMatrixBin.the_GenEliNu.end();
                iGNuMu++ ) {

            if ((*iGNuMu)->GetMother() != tmpGenLeptonMotherIndx) { continue; }
	    
            tmpGenNuCounter++;
	    
            GenNuLeptonPt[countGenNuLep]  = myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->Pt();
            GenNuLeptonEta[countGenNuLep] = myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->Eta();
            GenNuLeptonPhi[countGenNuLep] = myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->Phi();

            genNuLep.SetPxPyPzE(
                                myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->Px(),
                                myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->Py(),
                                myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->Pz(),
                                myGenMatrixBin.the_GenEliNu.at(tmpGenNuCounter-1)->E()
                                );

            countGenNuLep++;
          } // ~end of looping over the GenNuElectrons
          NGenNuLeptons = countGenNuLep;
	  //	  cout << "--HERE--13" << "\n";
	}
	//	cout << "--HERE--14" << "\n";
      } 

      else { GenMuonFromW = 0; }
      //      cout << "--HERE--16" << "\n";

      // Fill the Partons --
      NPartons = myGenMatrixBin.the_GenJets.size();
      UInt_t countPartons = 0;
      for ( std::vector<Event::GenObject const *>::const_iterator iGJ = myGenMatrixBin.the_GenJets.begin();
	    iGJ != myGenMatrixBin.the_GenJets.end();
	    iGJ++ ) {
	
	PartonPt[countPartons]  = myGenMatrixBin.the_GenJets.at(countPartons)->Pt();
	PartonEta[countPartons] = myGenMatrixBin.the_GenJets.at(countPartons)->Eta();
	PartonPhi[countPartons] = myGenMatrixBin.the_GenJets.at(countPartons)->Phi();
	
	countPartons++;
      } // ~end of looping over the Partons
      
      //      cout << "--HERE--17" << "\n";
      
      
      genW = TLVConvert(genW_);
     
      GenWPt  = genW.Pt();
      GenWEta = genW.Eta();
      GenWPhi = genW.Phi();

      DPhi_LepNuLep = ROOT::Math::VectorUtil::DeltaPhi(genLep,genW);
      DPhi_LepPtW   = ROOT::Math::VectorUtil::DeltaPhi(genLep,genNuLep);
      //      cout << "--HERE--18" << "\n";
    }
    //    cout << "--HERE--19" << "\n";
    //    if ( (lepRecoGenMatching) && (lepIsFromW) ) { tree->Fill(); }

    tree->Fill();

    return true;
    
    } // ~end of process AnalysisTree_HighPt

} // ~end of namespace
