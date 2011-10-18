#include "TTBkgEval.hh"
#include "KinSuite.hh"
using namespace Event;

namespace SSDL {

 TTBkgEval::TTBkgEval(const std::string & folderName,
		       Utils::ParameterSet &pset):
    mFolderName(folderName)
  {
    MCAnal_= pset.Get<double>("McAnal");
    mhtCut=pset.Get<double>("MHTCut");
    htCut=pset.Get<double>("HTCut");
    njetCut=pset.Get<int>("NjetCut");
    metCut=pset.Get<double>("METCut");
    jetPtCut=pset.Get<double>("JetPtCut");    
  } // end of TTBkgEval constructor.

  void TTBkgEval::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }  



  TTBkgEval::~TTBkgEval() {
 
    
    
  } // end of TTBkgEval destructor.
  
  bool TTBkgEval::Process(Event::Data & ev) {
    
    float HT=ev.CommonHT();
    float MHT=ev.CommonMHT().Pt();
    float w=ev.GetEventWeight();
    //float w=1.;
    float METPF=ev.metP4pf()[0].Pt();

 //   bool  taufromV= false;
    bool  photon=false;
    bool mufromV=false;
    bool hlt_jet50 = false;
    bool hlt_ht100 = false;
    

    int nbparton=0;
    if(MCAnal_){
      
      for(uint i = 0; i < ev.GenParticles().size(); i++) { 	
	if(ev.GenParticles()[i].GetStatus() ==3){
	  if(fabs(ev.GenParticles()[i].GetID())==5)nbparton++;
	  if(ev.GenParticles()[i].GetID()==22)photon=true;
	  if( fabs(ev.GenParticles()[i].GetID())==13 &&  	     
	      (fabs(ev.GenParticles()[i].GetMotherID())==24 || fabs(ev.GenParticles()[i].GetMotherID())==23 ||
	       fabs(ev.GenParticles()[i].GetMotherID())==15  )){	  
	    mufromV=true;	    
	  }
	}
      } // genpart loop      

      h_nbparton->Fill(nbparton,w);

      std::map<std::string, bool>::const_iterator ihlt;
      if(ev.hltHandleValid() ){
	for (ihlt=(*ev.hlt()).begin(); ihlt != (*ev.hlt()).end(); ++ihlt) {
	  if(ihlt->first == "HLT_Jet50"){
	    if(ihlt->second) hlt_jet50=true; 
	  }
	  if(ihlt->first == "HLT_HT100"){
	    if(ihlt->second) hlt_ht100=true; 
	  }
	}
      }      
    } // MC anal
    else{      
      std::map<std::string, bool>::const_iterator ihlt;
      if(ev.hltHandleValid() ){
	for (ihlt=(*ev.hlt()).begin(); ihlt != (*ev.hlt()).end(); ++ihlt) {
	  if(ihlt->first == "HLT_Jet50U"){
	    if(ihlt->second) hlt_jet50=true; 
	  }
	  if(ihlt->first == "HLT_HT100U"){
	    if(ihlt->second) hlt_ht100=true; 
	  }
	}      
      } 
    }
    
  
    if(!hlt_jet50)return true;

    std::vector<int> tauType;
    int njets=0;    
    int nBjets=0;
    int indBjet=-9;
    // for (std::vector<Jet const*>::const_iterator jJ =ev.JD_CommonJets().accepted.begin(); 
    //	 jJ !=ev.JD_CommonJets().accepted.end(); ++jJ){
      
    for (std::vector<Jet>::const_iterator jJ =ev.JD_Jets().begin(); 
	 jJ !=ev.JD_Jets().end(); ++jJ){

      h_allJetPt->Fill((jJ)->Pt(),w);
      if((jJ)->Pt()<jetPtCut)continue;
      njets++;
//      h_btagDiscriSV_alljets->Fill(ev.GetBtagSimpleSV((jJ)->GetIndex()),w);
      h_btagDiscriTC_alljets->Fill(ev.GetBtagTrkCount((jJ)->GetIndex()),w);    
      if(ev.GetBtagTrkCount((jJ)->GetIndex())>1.7){
	nBjets++;
	h_Bjet_EtaPt->Fill(fabs((jJ)->Eta()),(jJ)->Pt(),w);
	if(nBjets==1)indBjet=(jJ)->GetIndex();
      }else{
	h_NONBjet_EtaPt->Fill(fabs((jJ)->Eta()),(jJ)->Pt(),w);
      }     
    }
    


    h_HT_njet->Fill(HT,njets,w);
    h_MHT_njet->Fill(MHT,njets,w);

    h_HT_nBjet->Fill(HT,nBjets,w);
    h_MHT_nBjet->Fill(MHT,nBjets,w);
    
    h_HT_bc->Fill(HT,w);
    h_MHT_bc->Fill(MHT,w);
    h_njet_bc->Fill(njets,w);
    h_nBjet_bc->Fill(nBjets,w);

    int nmuon=0;
    int nlep=0;
    
    std::vector<const Lepton *> Mu;
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
	lep!=ev.LD_CommonMuons().accepted.end();++lep){	
      nlep++;
      nmuon++;
      Mu.push_back(*lep);      
    }
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){	
      nlep++;
    }
    

    int nIdMuon = ev.LD_CommonMuons().accepted.size();

    h_nIdMuon_bc->Fill(nIdMuon,w);

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
	lep!=ev.LD_CommonMuons().accepted.end();++lep){	     
      int iM = (*lep)->GetIndex();
      
      h_bc_RecoMuon_EtaPt->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);   
      
      
      float isoSR =(ev.GetMuonTrkIso03(iM) +ev.GetMuonEcalIso03(iM) + ev.GetMuonHcalIso03(iM))/(*lep)->Pt();

      if(!hlt_jet50)continue;
      h_isoSRCombRel_hlt->Fill(isoSR,w);
      

      if(nBjets<1)continue;    
      h_isoSRCombRel_bjet->Fill(isoSR,w);      
      h_RecoMuon_EtaPt->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);        
 
      if(HT<50.){	
	h_RecoMuon_EtaPt_HT0->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
      }
      if(HT>=50 && HT<150 ){
	h_RecoMuon_EtaPt_HT50->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
      }     
      if(HT>=150 && HT<350.){
	h_RecoMuon_EtaPt_HT150->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
      }
      if( HT>=350.){
	h_RecoMuon_EtaPt_HT350->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);           
      }
      
    
      
      double dRmin = 100.;
      int jetInd = -666;
 //     bool jetclose = false;
    
      for (std::vector<Jet>::const_iterator jJ =ev.JD_Jets().begin(); 
	   jJ !=ev.JD_Jets().end(); ++jJ){
	if((jJ)->Pt()<jetPtCut)continue;
	double dR_jet_mu =  KS_DeltaR(*lep,&(*jJ));
	h_dR_mujet->Fill(dR_jet_mu,w);	
	if(dR_jet_mu<dRmin){
	  jetInd=(jJ)->GetIndex();
	  dRmin=dR_jet_mu;
	}else{
	  continue;
	}
	
	h_dRmin_mujet->Fill(dRmin,w);
	float ptjet=-9.; 
	if((jJ)->Pt()<300){
	  ptjet=(jJ)->Pt();
	}else{
	  ptjet=299.;
	}

	h_closetoMu_JetEtaPt->Fill(fabs((jJ)->Eta()),ptjet,w);  
	
	if(MCAnal_){
	  int mugen = ev.leptonMatch(const_cast<Lepton*>((*lep)),2);
	  if(ev.leptonType(mugen)==10){
	    h_muB_closetoMu_JetEtaPt->Fill(fabs((jJ)->Eta()),ptjet,w);  
	  }	
	}

	h_isoSRCombRel_bc->Fill(isoSR,w);
       	if(njetCut>0){
	  if(njets!= njetCut)continue; 
	}  
	h_isoSRCombRel_njet->Fill(isoSR,w);
	
	if(MHT>mhtCut)continue;
	h_isoSRCombRel_mht->Fill(isoSR,w);

	h_HT_aftermht->Fill(HT,w);
	
	if(HT<htCut)continue;
	h_isoSRCombRel_ht->Fill(isoSR,w);

	h_met_ac->Fill(METPF,w);	
	if(METPF>metCut)continue;

	h_isoSRCombRel_ac->Fill(isoSR,w);
       	LorentzV dimu;
       	if(nmuon>1){
	  dimu = *Mu[0]+ *Mu[1] ;
	  float minv2mu = dimu.M();
	  h_minv2mu->Fill(minv2mu,w);
	}
	
	if(jetInd!=indBjet){	  
	  h_probe_closetoMu_JetEtaPt->Fill(fabs((jJ)->Eta()),ptjet,w);    // plot!!!!!
	  if(fabs((jJ)->Eta())<1.){
	    h_isoSRCombRel_eta0->Fill(isoSR,w);
	    h_isoSRTrk_eta0->Fill(ev.GetMuonTrkIso03(iM),w);
	  }else if(1.<fabs((jJ)->Eta())<2.){
	    h_isoSRCombRel_eta1->Fill(isoSR,w);
	    h_isoSRTrk_eta1->Fill(ev.GetMuonTrkIso03(iM),w);
	  }else if(fabs((jJ)->Eta())>2.){
	    h_isoSRCombRel_eta2->Fill(isoSR,w);
	    h_isoSRTrk_eta2->Fill(ev.GetMuonTrkIso03(iM),w);
	  }	  
	  if((jJ)->Pt()<180.){
	    h_isoSRCombRel_pt0->Fill(isoSR,w);
	    h_isoSRTrk_pt0->Fill(ev.GetMuonTrkIso03(iM),w);
	  }else if(180<(jJ)->Pt()<270.){
	    h_isoSRCombRel_pt1->Fill(isoSR,w);
	    h_isoSRTrk_pt1->Fill(ev.GetMuonTrkIso03(iM),w);
	  }else if((jJ)->Pt()>270.){
	    h_isoSRCombRel_pt2->Fill(isoSR,w);
	    h_isoSRTrk_pt2->Fill(ev.GetMuonTrkIso03(iM),w);
	  }
	  
	  if(nbparton==2)h_2bp_probe_closetoMu_JetEtaPt->Fill(fabs((jJ)->Eta()),ptjet,w);  
	  if(MCAnal_){
	    int mugen = ev.leptonMatch(const_cast<Lepton*>((*lep)),2);
	    if(ev.leptonType(mugen)==10){
	      h_muB_probe_JetEtaPt->Fill(fabs((jJ)->Eta()),ptjet,w);  
	      if(HT>300)h_ht300_muB_probe_JetEtaPt->Fill(fabs((jJ)->Eta()),ptjet,w);  
	    }	
	  }
	}
	if(HT<150.){	
	  h_closetoMu_JetEtaPt_HT0->Fill(fabs((jJ)->Eta()),ptjet,w);   
	}else if(HT>=150 && HT<350){
	  h_closetoMu_JetEtaPt_HT150to350->Fill(fabs((jJ)->Eta()),ptjet,w);   
	}else{
	  h_closetoMu_JetEtaPt_HT350->Fill(fabs((jJ)->Eta()),ptjet,w);   
	}
	//	jetclose=true;	  
      }
    }// loop on muons 
    
      
    return true;
  }
  void  TTBkgEval::BookHistos(){
      
    h_allJetPt = new TH1D("h_allJetPt","h_allJetPt",100,0.,500.);
    h_nbparton =  new TH1D("h_nbparton","h_nbparton",6,0.,6.);

    h_minv2mu = new TH1D("h_minv2mu","h_minv2mu",150,0.,150.);
    
    h_met_ac= new TH1D("h_met_ac","h_met_ac",100,0.,100.);

    h_isoPFCombRel_ac= new TH1D("h_isoPFCombRel_ac","h_isoPFCombRel_ac",100,0.,1.);
    h_isoSRCombRel_ac= new TH1D("h_isoSRCombRel_ac","h_isoSRCombRel_ac",100,0.,1.);
    h_isoPFCombRel_bc= new TH1D("h_isoPFCombRel_bc","h_isoPFCombRel_bc",100,0.,1.);
    h_isoSRCombRel_bc= new TH1D("h_isoSRCombRel_bc","h_isoSRCombRel_bc",100,0.,1.);

    //==========================================
    h_isoSRCombRel_hlt= new TH1D("h_isoSRCombRel_hlt","h_isoSRCombRel_hlt",100,0.,1.);
    h_isoSRCombRel_bjet= new TH1D("h_isoSRCombRel_bjet","h_isoSRCombRel_bjet",100,0.,1.);
    h_isoSRCombRel_njet= new TH1D("h_isoSRCombRel_njet","h_isoSRCombRel_njet",100,0.,1.);
    
    h_isoSRCombRel_ht= new TH1D("h_isoSRCombRel_ht","h_isoSRCombRel_ht",100,0.,1.);
    h_isoSRCombRel_mht= new TH1D("h_isoSRCombRel_mht","h_isoSRCombRel_mht",100,0.,1.);
  
    //===========================================


    h_isoSRCombRel_eta0= new TH1D("h_isoSRCombRel_eta0","h_isoSRCombRel_eta0",100,0.,1.);
    h_isoSRCombRel_eta1= new TH1D("h_isoSRCombRel_eta1","h_isoSRCombRel_eta1",100,0.,1.);
    h_isoSRCombRel_eta2= new TH1D("h_isoSRCombRel_eta2","h_isoSRCombRel_eta2",100,0.,1.);



    h_isoSRTrk_eta0= new TH1D("h_isoSRTrk_eta0","h_isoSRTrk_eta0",100,0.,5.);
    h_isoSRTrk_eta1= new TH1D("h_isoSRTrk_eta1","h_isoSRTrk_eta1",100,0.,5.);
    h_isoSRTrk_eta2= new TH1D("h_isoSRTrk_eta2","h_isoSRTrk_eta2",100,0.,5.);

    
    h_isoSRCombRel_pt0= new TH1D("h_isoSRCombRel_pt0","h_isoSRCombRel_pt0",100,0.,1.);
    h_isoSRCombRel_pt1= new TH1D("h_isoSRCombRel_pt1","h_isoSRCombRel_pt1",100,0.,1.);
    h_isoSRCombRel_pt2= new TH1D("h_isoSRCombRel_pt2","h_isoSRCombRel_pt2",100,0.,1.);

    h_isoSRTrk_pt0= new TH1D("h_isoSRTrk_pt0","h_isoSRTrk_pt0",100,0.,5.);
    h_isoSRTrk_pt1= new TH1D("h_isoSRTrk_pt1","h_isoSRTrk_pt1",100,0.,5.);
    h_isoSRTrk_pt2= new TH1D("h_isoSRTrk_pt2","h_isoSRTrk_pt2",100,0.,5.);

    h_HT_njet  = new TH2D("h_HT_njet","h_HT_njet",100,0.,1000,10,0.,10.);
    h_MHT_njet  = new TH2D("h_MHT_njet","h_MHT_njet",100,0.,200,10,0.,10.);

    h_HT_nBjet  = new TH2D("h_HT_nBjet","h_HT_nBjet",100,0.,1000,10,0.,10.);
    h_MHT_nBjet  = new TH2D("h_MHT_nBjet","h_MHT_nBjet",100,0.,200,10,0.,10.);

    h_HT_bc  = new TH1D("h_HT_bc","h_HT_bc",100,0.,1000.);
    h_MHT_bc  = new TH1D("h_MHT_bc","h_MHT_bc",100,0.,200.);
    h_njet_bc  = new TH1D("h_njet_bc","h_njet_bc",10,0.,10.);
    h_nBjet_bc  = new TH1D("h_nBjet_bc","h_nBjet_bc",10,0.,10.);
    h_nIdMuon_bc = new TH1D("h_nIdMuon_bc","h_nIdMuon_bc",10,0.,10.);


    h_HT_aftermht = new TH1D("h_HT_aftermht","h_HT_aftermht",100,0.,1000.);

    h_dRmin_mujet = new TH1D("h_dRmin_mujet","h_dRmin_mujet",100,0.,2.);
    h_dR_mujet = new TH1D("h_dR_mujet","h_dR_mujet",100,0.,2.);
    
    h_btagDiscriSV_alljets = new TH1D("h_btagDiscriSV_alljets","h_btagDiscriSV_alljets",100,-10.,10.);

    h_btagDiscriTC_alljets = new TH1D("h_btagDiscriTC_alljets","h_btagDiscriTC_alljets",100,-10.,10.);

    h_Bjet_EtaPt = new TH2D("h_Bjet_EtaPt","h_Bjet_EtaP",5,0.,2.5,10,0.,100.);
    h_NONBjet_EtaPt = new TH2D("h_NONBjet_EtaPt","h_NONBjet_EtaP",5,0.,2.5,10,0.,100.);

    h_closetoMu_JetEtaPt_HT0 = new TH2D("h_closetoMu_JetEtaPt_HT0"," h_closetoMu_JetEtaPt_HT0",3,0.,3.,10,0.,300.);
    h_closetoMu_JetEtaPt_HT150to350 = new TH2D("h_closetoMu_JetEtaPt_HT150to350"," h_closetoMu_JetEtaPt_HT150to350",3,0.,3.,10,0.,300.);
    h_closetoMu_JetEtaPt_HT350 = new TH2D("h_closetoMu_JetEtaPt_HT350"," h_closetoMu_JetEtaPt_HT350",3,0.,3.,10,0.,300.);

    h_MuSelHF_closetoMu_JetEtaPt_HT0 = new TH2D("h_MuSelHF_closetoMu_JetEtaPt_HT0"," h_MuSelHF_closetoMu_JetEtaPt_HT0",5,0.,2.5,10,0.,300.);
    h_MuSelHF_closetoMu_JetEtaPt_HT150to350 = new TH2D("h_MuSelHF_closetoMu_JetEtaPt_HT150to350"," h_MuSelHF_closetoMu_JetEtaPt_HT150to350",5,0.,2.5,10,0.,300.);
    h_MuSelHF_closetoMu_JetEtaPt_HT350 = new TH2D("h_MuSelHF_closetoMu_JetEtaPt_HT350"," h_MuSelHF_closetoMu_JetEtaPt_HT350",5,0.,2.5,10,0.,300.);

    //===================================================================================
    h_probe_closetoMu_JetEtaPt = new TH2D("h_probe_closetoMu_JetEtaPt","h_probe_closetoMu_JetEtaPt",3,0.,3.,6,-30.,300.);
    h_2bp_probe_closetoMu_JetEtaPt = new TH2D("h_2bp_probe_closetoMu_JetEtaPt","h_2bp_probe_closetoMu_JetEtaPt",3,0.,3.,6 ,-30.,300.);
    h_muB_closetoMu_JetEtaPt = new TH2D("h_muB_closetoMu_JetEtaPt","h_muB_closetoMu_JetEtaPt",3,0.,3.,6,-30.,300.);
    h_muB_probe_JetEtaPt = new TH2D("h_muB_probe_JetEtaPt","h_muB_probe_JetEtaPt",3,0.,3.,6,-30.,300.);
    h_ht300_muB_probe_JetEtaPt = new TH2D("h_ht300_muB_probe_JetEtaPt","h_ht300_muB_probe_JetEtaPt",3,0.,3.,6,-30.,300.);

    h_MuSelHF_closetoMu_JetEtaPt = new TH2D("h_MuSelHF_closetoMu_JetEtaPt","h_MuSelHF_closetoMu_JetEtaPt",3,0.,3.,6,-30.,300.);
    h_closetoMu_JetEtaPt = new TH2D("h_closetoMu_JetEtaPt"," h_closetoMu_JetEtaPt",3,0.,3.,6,-30.,300.);
    //===================================================================================



    h_MuSelHF_EtaPt = new TH2D("h_MuSelHF_EtaPt","h_MuSelHF_EtaPt",5,0.,2.5,10,0.,50.);
      
    h_bc_RecoMuon_EtaPt = new TH2D("h_bc_RecoMuon_EtaPt","h_bc_RecoMuon_EtaPt",5,0.,2.5,10,0.,50.); 
    h_RecoMuon_EtaPt = new TH2D("h_RecoMuon_EtaPt","h_RecoMuon_EtaPt",5,0.,2.5,10,0.,50.); 
    h_IDMuon_EtaPt = new TH2D("h_IDMuon_EtaPt","h_IDau_EtaPt",5,0.,2.5,10,0.,100.); 
    h_nonIDMuon_EtaPt = new TH2D("h_nonIDMuon_EtaPt","h_nonIDau_EtaPt",5,0.,2.5,10,0.,100.); 
    
    h_RecoMuon_EtaPt_HT0 = new TH2D("h_RecoMuon_EtaPt_HT0","h_RecoMuon_EtaPt_HT0",5,0.,2.5,10,0.,50.); 
    h_IDMuon_EtaPt_HT0 = new TH2D("h_IDMuon_EtaPt_HT0","h_IDau_EtaPt_HT0",5,0.,2.5,10,0.,100.); 
    h_nonIDMuon_EtaPt_HT0 = new TH2D("h_nonIDMuon_EtaPt_HT0","h_nonIDau_EtaPt_HT0",5,0.,2.5,10,0.,100.); 
        
    h_RecoMuon_EtaPt_HT50 = new TH2D("h_RecoMuon_EtaPt_HT50","h_RecoMuon_EtaPt_HT50",5,0.,2.5,10,0.,50.); 
    h_IDMuon_EtaPt_HT50 = new TH2D("h_IDMuon_EtaPt_HT50","h_IDau_EtaPt_HT50",5,0.,2.5,10,0.,100.); 
    h_nonIDMuon_EtaPt_HT50 = new TH2D("h_nonIDMuon_EtaPt_HT50","h_nonIDau_EtaPt_HT50",5,0.,2.5,10,0.,100.); 

    h_RecoMuon_EtaPt_HT150 = new TH2D("h_RecoMuon_EtaPt_HT150","h_RecoMuon_EtaPt_HT150",5,0.,2.5,10,0.,100.); 
    h_IDMuon_EtaPt_HT150 = new TH2D("h_IDMuon_EtaPt_HT150","h_IDau_EtaPt_HT150",5,0.,2.5,10,0.,100.); 
    h_nonIDMuon_EtaPt_HT150 = new TH2D("h_nonIDMuon_EtaPt_HT150","h_nonIDau_EtaPt_HT150",5,0.,2.5,10,0.,100.); 

    h_RecoMuon_EtaPt_HT350 = new TH2D("h_RecoMuon_EtaPt_HT350","h_RecoMuon_EtaPt_HT350",5,0.,2.5,10,0.,100.); 
    h_IDMuon_EtaPt_HT350 = new TH2D("h_IDMuon_EtaPt_HT350","h_IDau_EtaPt_HT350",5,0.,2.5,10,0.,100.); 
    h_nonIDMuon_EtaPt_HT350 = new TH2D("h_nonIDMuon_EtaPt_HT350","h_nonIDau_EtaPt_HT350",5,0.,2.5,10,0.,100.); 

    h_MuonEtaPt = new TH2D("h_MuonEtaPt","h_MuonEtaPt",5,0.,2.5,5,0.,150.); 
    h_selMuonEtaPt = new TH2D("h_selMuonEtaPt","h_selMuonEtaPt",5,0.,2.5,5,0.,150.); 

    h_btagSSV_jetClosetoMuon =  new TH1D("h_btagSSV_jetClosetoMuon","h_btagSSV_jetClosetoMuon",100,0.,20.); 

   

  }
  std::ostream& TTBkgEval::Description(std::ostream &ostrm) {
    ostrm << "TTBkgEval plots made here: (histograms in ";
    ostrm <<  mFolderName << ")";
    return ostrm;
  }
  double TTBkgEval::getDeltaR(double phi1, double phi2, double eta1, double eta2) {
    //   double PI                 = 3.14159265;
    double deta=eta1-eta2;
    double dphi=0;
    if (phi1 - phi2 > PI)
      dphi = fabs(phi1 - phi2 - 2 * PI);    
    if (phi1 - phi2 < -1 * PI)
      dphi = fabs(phi1 - phi2 + 2 * PI);    
    double deltaR= pow(deta,2)+pow(dphi,2); 
    return sqrt(deltaR);
  }
  
}
