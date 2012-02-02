#include "dpsSSWSelection.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
//#include "Gen.hh"
#include <fstream>
using namespace Event;
namespace SSDL {
 

  bool compPt(TLorentzVector v1, TLorentzVector v2) {
    return v1.Pt() > v2.Pt();
  }
  bool compLepPt( const Lepton* o1, const Lepton* o2)  { return o1->Pt() > o2->Pt(); }
  
  dpsSSWSelection::dpsSSWSelection(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName)
  {

    mChargeProdCut=pset.Get<int>("ChargeProd");
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
    leptonCut=pset.Get<double>("LeptonCut");
    maxPtHat=pset.Get<double>("MaxPtHat");
    mSugraScan=bool(pset.Get<double>("MSugraScan"));
    printLep=bool(pset.Get<double>("PrintLep"));
    bkgAnal=bool(pset.Get<double>("BkgAnal"));
    if (bkgAnal){
      recoFile=pset.Get<string>("recoFile");
      mcFile=pset.Get<string>("mcFile");
    }
    

    for (int ih=0;ih<6;ih++){
      
      for (int ib=0;ib<5;ib++)
	nhdl[ih][ib]=0;

      for (int ib=0;ib<3;ib++){
	nhsl[ih][ib]=0;

      }
    }
  }

  void dpsSSWSelection::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();

  }
  dpsSSWSelection::~dpsSSWSelection() {

  }

  void  dpsSSWSelection::BookHistos() {

    h_nlep_hlt = new TH1D("h_nlep_hlt","h_nlep_hlt",20,0,20);
    h_nlep_skim = new TH1D("h_nlep_skim","h_nlep_skim",20,0,20);
    h_nlep_2idlep = new TH1D("h_nlep_2idlep","h_nlep_2idlep",20,0,20);
    h_nlep_charge = new TH1D("h_nlep_charge","h_nlep_charge",20,0,20);

    h_ss_HT= new TH1D("h_HT","h_HT",40, 0.,2000.);
    h_ss_MHT= new TH1D("h_MHT","h_MHT",60, 0.,1500.);

    h_ss_NTAU=new TH1D("h_NTAU","h_NTAU",20,0,20);
    h_ss_NMUON=new TH1D("h_NMUON","h_NMUON",20,0,20);
    h_ss_NELEC=new TH1D("h_NELEC","h_NELEC",20,0,20);
    h_ss_NLEPTON=new TH1D("h_NLEPTON","h_NLEPTON",20,0,20);
    h_bc_NTAU=new TH1D("h_bc_NTAU","h_bc_NTAU",20,0,20);
    h_bc_NMUON=new TH1D("h_bc_NMUON","h_bc_NMUON",20,0,20);
    h_bc_NELEC=new TH1D("h_bc_NELEC","h_bc_NELEC",20,0,20);
    h_bc_ElecPt = new TH1D("h_bc_ElecPt","h_bc_ElecPt",50,0,150);
    h_bc_MuonPt = new TH1D("h_bc_MuonPt","h_bc_MuonPt",50,0,150);
    h_bc_TauPt = new TH1D("h_bc_TauPt","h_bc_TauPt",50,0,150);
    h_Charge = new TH1D("h_Charge","h_Charge",2,-2,2);
    h_bc_Charge= new TH1D("h_bc_Charge","h_bc_Charge",2,-2,2);
    h_bc_HT = new TH1D("h_bc_HT","h_bc_HT",40, 0.,2000.);
    h_bc_lept = new TH1D("h_bc_NLEPTON","h_bc_NLEPTON",20,0,20);
    h_bc_MHT= new TH1D("h_bc_MHT","h_bc_MHT",60, 0.,1500.);
    

    h_tausel1_EtaPt = new TH2D("h_tausel1_EtaPt","h_tausel1_EtaPt",5,0.,2.5,5,0,150.);
    h_tausel2_EtaPt = new TH2D("h_tausel2_EtaPt","h_tausel2_EtaPt",5,0.,2.5,5,0,150.);

    h_tau1AnyJetEtaPt = new TH2D("h_tau1AnyJetEtaPt","h_tau1AnyJetEtaPt",5,0.,2.5,5,0,150.);
    h_tau1BJetEtaPt = new TH2D("h_tau1BJetEtaPt","h_tau1BJetEtaPt",5,0.,2.5,5,0,150.);

    h_tau2AnyJetEtaPt = new TH2D("h_tau2AnyJetEtaPt","h_tau2AnyJetEtaPt",5,0.,2.5,5,0,150.);
    h_tau2BJetEtaPt = new TH2D("h_tau2BJetEtaPt","h_tau2BJetEtaPt",5,0.,2.5,5,0,150.);


    h_tauEtaPt = new TH2D("h_tauEtaPt","h_tauEtaPt",5,0.,2.5,5,0,150.);
    h_tauIDbyTaNCvsPt = new TH2D("h_tauIDbyTaNCvsPt","h_tauIDbyTaNCvsPt",50,0.,1.,50,0,150.);
    
    BookHistArray(h_ss_ht,"h_ss_ht","h_ss_ht",100,0.,2000.,dilepFinalStates,0,1,false);
    BookHistArray(h_abcd_ht,"h_abcd_ht","h_abcd_ht",100,0.,2000.,dilepFinalStates,0,1,false);
    BookHistArray(h_ss_mht,"h_ss_mht","h_ss_mht",100,0.,2000.,dilepFinalStates,0,1,false);
    BookHistArray(h_ch_ht,"h_ch_ht","h_ch_ht",2,-2.,2.,100,0.,2000.,dilepFinalStates,0,1,false);
    BookHistArray(h_nl_A,"h_nl_A","h_nl_A",2,0.,20,dilepFinalStates,0,1,false);    
    BookHistArray(h_m0_m12_fs,"h_m0_m12_fs","h_m0_m12_fs",80,0.,4000,25,100.,600.,dilepFinalStates,0,1,false);

    BookHistArray(h_m0_m12_fs_nw,"h_m0_m12_fs_nw","h_m0_m12_fs_nw",80,0.,4000,25,100.,600.,dilepFinalStates,0,1,false);

    
    h_ht_sl = new TH2D("h_ht_sl","h_ht_sl",6,0,6,3,0,3);
    h_ht_dl = new TH2D("h_ht_dl","h_ht_dl",6,0,6,6,0,6);

    h_m0_m12_AC = new TH2D("h_m0_m12_AC","h_m0_m12_AC",80,0.,4000.,25,100.,600.);
    h_m0_m12_BC = new TH2D("h_m0_m12_BC","h_m0_m12_BC",80,0.,4000.,25,100.,600.);

    h_m0_m12_AC_nw = new TH2D("h_m0_m12_AC_nw","h_m0_m12_AC_nw",80,0.,4000.,25,100.,600.);
    h_m0_m12_BC_nw = new TH2D("h_m0_m12_BC_nw","h_m0_m12_BC_nw",80,0.,4000.,25,100.,600.);

    h_m0_m12_SS = new TH2D("h_m0_m12_SS","h_m0_m12_SS",80,0.,4000.,25,100.,600.);
  }

  bool dpsSSWSelection::Process(Event::Data & ev) {
    if (bkgAnal){

    }

    if(ev.pthat()>maxPtHat)return 0;

   
    float HT=ev.CommonHT();
    float MHT=ev.CommonMHT().Pt();
    w=ev.GetEventWeight();
    uint NELEC=ev.LD_CommonElectrons().accepted.size();
    
    uint NMUON=ev.LD_CommonMuons().accepted.size();
    uint NTAUS=ev.LD_CommonTaus().accepted.size();

    
   


    std::vector<const Lepton *> AllLeptons;

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
      h_bc_MuonPt->Fill((*lep)->Pt(),w);

      AllLeptons.push_back(*lep);
    }

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){
      h_bc_ElecPt->Fill((*lep)->Pt(),w);
      if (fabs((**lep).Eta())>2.4) continue;
      AllLeptons.push_back(*lep);
    }
    int icommTau=0;
    int itau1=-999;
    int itau2=-999;
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
   	lep!=ev.LD_CommonTaus().accepted.end();++lep){
      icommTau++;
      int itau=(*lep)->GetIndex();      
      if(icommTau==1)itau1= itau;
      if(icommTau==2)itau2= itau;
      h_bc_TauPt->Fill((*lep)->Pt(),w);
      
      h_tauEtaPt->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);
      //      h_tauIDbyTaNCvsPt->Fill(ev.GetTauIdbyTaNC(itau),w);
    }
    
    sort(AllLeptons.begin(), AllLeptons.end(), compLepPt);

    
    uint NLEPTONS=AllLeptons.size();


    h_bc_NMUON->Fill(NMUON,w);
    h_bc_NELEC->Fill(NELEC,w);
    h_bc_NTAU->Fill(NTAUS,w);


    int chProd=-1;
    if (AllLeptons.size()>1)
      chProd=int(AllLeptons[0]->GetCharge()*AllLeptons[1]->GetCharge());


    // return 1;

    //==================================================================================
    //----------------------------------------------------------------------------------

    // data skim -----------------
   
    
    bool skimLep=false;
    
    std::vector<Lepton> recolep;
    int irecolep=0;
    for(vector<Lepton  >::const_iterator lep=ev.LD_Electrons().begin();
	lep!=ev.LD_Electrons().end();++lep){
      // h_bc_ElecPt->Fill((lep)->Pt(),w);

      // if (fabs(&(*lep)->Eta())>2.5 || (lep)->Pt()<20) continue;
      // recolep.push_back(&(*lep));

      if (fabs(lep->Eta())>2.5 || lep->Pt()<20) continue;
      irecolep++;
    }

    for(vector<Lepton  >::const_iterator lep=ev.LD_Muons().begin();
	lep!=ev.LD_Muons().end();++lep){
      // h_bc_ElecPt->Fill((lep)->Pt(),w);

      // if (fabs(&(*lep)->Eta())>2.5 || (lep)->Pt()<20) continue;
      // recolep.push_back(&(*lep));

      if (fabs(lep->Eta())>2.4 || lep->Pt()<20) continue;
      irecolep++;
    }
    

    skimLep=( irecolep>1 ) ;
    
    // vector<bool> WWcuts;

    //  WWcuts.push_back(skimLep);
    
 

    // HLT -----------------

    bool hlt = false;
    bool hltmu=false;
    bool hltele=false;
    /*
    for (uint i=0; i<triggerBits_.size();i++){
      if (hlt) continue;
      hlt =(map<string,bool>(*ev.hlt()))[triggerBits_[i]];
    }
    */

    std::map<std::string, bool>::const_iterator ihlt;
    if(ev.hltHandleValid() ){
      for (ihlt=(*ev.hlt()).begin(); ihlt != (*ev.hlt()).end(); ++ihlt) {
	if(ihlt->first == "HLT_Mu9"){
	  if(ihlt->second) hltmu=true; 
	}
	if(ihlt->first == "HLT_Ele15_LW_L1R"){
	  if(ihlt->second) hltele=true; 
	}
      }
    }


    if(hltmu||hltele)hlt=true;

    // WWcuts.push_back(hlt);
    

    // 2 leptons with Opposite/Same charge   pt>20 GeV/c ---------------- 
    bool twoidlep = false; 
    bool charge = false;
    int chargeProd=0;
    if(AllLeptons.size()>1){
      twoidlep = true;
      chargeProd=int(AllLeptons[0]->GetCharge()*AllLeptons[1]->GetCharge());
      if (chargeProd>0) chargeProd=1;
      else chargeProd=-1;

      if(chargeProd == mChargeProdCut ) charge=true;  
    }

    
    if(!hlt) return 0;
    h_nlep_hlt->Fill(irecolep,w);
    if(!skimLep) return 0;
    h_nlep_skim->Fill(irecolep,w);
    if(!twoidlep)return 0;
    h_nlep_2idlep->Fill(irecolep,w);
    if(!charge)return 0;
    h_nlep_charge->Fill(irecolep,w);


    

    // jet veto   PFjets, Akt 0.5 eta<3   Pt_{max} < 25/20 GeV   deltaR(lepton-jet)<0.3
    
    // Extra lepton veto - no leptons with Pt>10 GeV and nominal selection (id, iso, d0,acceptance etc) 
    
    //----------------------------------------------------------------------------------


    return 1;

    vector<bool> CUTS;



    //CUT LIST
    CUTS.push_back((NLEPTONS>leptonCut));
    CUTS.push_back((chProd>0));
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    int ihthth=0;
    if (HT>50 && HT<100)  ihthth=1;
    if (HT>100 && HT<200) ihthth=2;
    if (HT>200 && HT<350) ihthth=3;
    if (HT>350 && HT<600) ihthth=4;
    if (HT>600) ihthth=5;
    bool DECISION=true;


    //SAME SIGN ELECTRONS

    if (CUTS[0] &&CUTS[3]){
      int REC_STATE=-1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
      if (chProd>0) chProd=1;
      else chProd=-1;
      h_ch_ht[REC_STATE]->Fill(chProd,HT,w);
      h_abcd_ht[REC_STATE]->Fill(HT,w);

      if (CUTS[1] && CUTS[2]){ 

	if(mSugraScan){
	  h_m0_m12_AC->Fill(ev.GetM0(),ev.GetM12(),w);      	         
	  h_m0_m12_fs[REC_STATE]->Fill(ev.GetM0(),ev.GetM12(),w); 

	  h_m0_m12_AC_nw->Fill(ev.GetM0(),ev.GetM12());      	         
	  h_m0_m12_fs_nw[REC_STATE]->Fill(ev.GetM0(),ev.GetM12()); 
	  
	}
	
       
	h_nl_A[REC_STATE]->Fill(NLEPTONS,w);

      } // cuts 1 2 
    } // cuts 0 3
    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);



    h_bc_MHT->Fill(MHT,w);
    h_bc_HT->Fill(HT,w);
    h_bc_Charge->Fill(chProd,w);
    h_bc_lept->Fill(NLEPTONS,w);
    if (chProd>0) chProd=1;
    else chProd=-1;
    if (CUTS[2]&&CUTS[3])              h_ss_NLEPTON->Fill(NLEPTONS,w); //NLEPTON
    if (CUTS[0]&&CUTS[2]&&CUTS[3])     h_Charge->Fill(chProd,w);  //CH prod
    if (CUTS[1]&&CUTS[0]&&CUTS[3]) {
      h_ss_HT->Fill(HT,w); //HT
    }
    if(CUTS[1]&&CUTS[0]&&CUTS[2]) {
      h_ss_MHT->Fill(MHT,w); //MHT
    }


    //TAU BKG EVALUATION
    if (CUTS[3]&&(NLEPTONS==1)){
      h_ht_sl->Fill(ihthth,AllLeptons[0]->GetType()-1,w);
    }
    if (CUTS[1]&&CUTS[3]&&(NLEPTONS==2)){
      int REC_STATE=99;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
      h_ht_dl->Fill(ihthth,REC_STATE,w);
    }

    //FINAL PLOTS
    if (DECISION){
      int REC_STATE=-1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
      //      h_ss_NTAU->Fill(NTAUS,w);
      h_ss_NELEC->Fill(NELEC,w);
      //      h_ss_NMUON->Fill(NMUON,w);
      h_ss_ht[REC_STATE]->Fill(HT,w);
      h_ss_mht[REC_STATE]->Fill(MHT,w);



   //BACKGROUND ANALYSIS
      if (bkgAnal){
	ofstream Gen_BKGD,reco_BKGD;
	Gen_BKGD.open(mcFile.c_str(),ios::out|ios::app);
	reco_BKGD.open(recoFile.c_str(),ios::out|ios::app);
  	uint evnum = ev.EventNumber();
  	uint lep_num = ev.MC_GenLeptons().size();
 	std::vector<GenObject const *> iso_leps = ev.MC_TheIsolatedLeptons();

 	uint reco_leps = NLEPTONS;
 	Gen_BKGD<<"==========EVENT GEN DETAIL ("<<evnum<<")============="<<endl;
 	reco_BKGD<<"============EVENT RECO DETAIL ("<<evnum<<")==========="<<endl;
 	Gen_BKGD<<"--------leptons---------"<<endl;
 	Gen_BKGD<<"Number of leptons, of which isolated (1=y, 0=n.See MCD for defs): "<<lep_num<<"    "<<iso_leps.size()<<endl;

 	reco_BKGD<<"--------leptons----------"<<endl;
 	reco_BKGD<<" Total reco leptons: "<<reco_leps<<endl;
 	for (vector<Event::GenObject const *>::const_iterator ig=ev.MC_GenLeptons().begin();
	     ig!=ev.MC_GenLeptons().end();++ig){

	  int iso_test = 0;
	  for (vector<Event::GenObject const *>::const_iterator isol=iso_leps.begin();
	       isol!=iso_leps.end();++isol){
	    if (KS_DeltaR(*isol,*ig)<0.001)
	      iso_test = 1;
 	  }

 	  Gen_BKGD<<"Leptons Iso, ID, Pt, Eta and Phi: "
		  <<iso_test<<"    "<<(*ig)->GetID()<<"    "<<(*ig)->Pt()<<"    "<<(*ig)->Eta()<<"    "<<(*ig)->Phi()<<endl;

 	}


 	for(vector<Lepton const *>::const_iterator ilep=AllLeptons.begin() ; ilep!=AllLeptons.end(); ++ilep)
 	  reco_BKGD<<"Leptons ID,  Charge, Pt, Eta and Phi: "<<(*ilep)->GetType()<<"    "<<(*ilep)->GetCharge()<<"    "<<(*ilep)->Pt()<<"    "<<(*ilep)->Eta()<<"    "<<(*ilep)->Phi()<<endl;




	// 	Gen_BKGD<<"---------Jets----------"<<endl;
// 	Gen_BKGD<<"Number of jets: "<<jets<<endl;
// 	for(uint j=0; j<jets; j++){

// 	  double jet_Et = ev.ND.GetGenJetEt(j);
// 	  double jet_eta = ev.ND.GetGenJetEta(j);
// 	  double jet_phi = ev.ND.GetGenJetPhi(j);


// 	  Gen_BKGD<<"Jets Et, Eta and Phi: "<<jet_Et<<"    "<<jet_eta<<"    "<<jet_phi<<endl;

// 	}

 	reco_BKGD<<"---------Jets----------"<<endl;

 	reco_BKGD<<"Number of jets: "<<ev.JD_Jets().size()<<endl;

	for (vector<Jet >::const_iterator ij=ev.JD_Jets().begin() ;
	ij!=ev.JD_Jets().end(); ++ij)
	  reco_BKGD<<"Jets Pt and Eta: "<<ij->Pt()<<"    "<<ij->Eta()<<"    "<<ij->Phi()<<endl;

	for (vector<Jet const *>::const_iterator ij=ev.JD_CommonJets().accepted.begin() ;
	ij!=ev.JD_CommonJets().accepted.end(); ++ij)
	  reco_BKGD<<"ComJets Pt and Eta: "<<(*ij)->Pt()<<"    "<<(*ij)->Eta()<<"    "<<(*ij)->Phi()<<endl;



      }


    }


    return DECISION; // Check for fails above, return false to fail operation.
  } // end of Process method

  std::ostream& dpsSSWSelection::Description(std::ostream &ostrm) {
    ostrm << "SSDLSelection plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }


}












