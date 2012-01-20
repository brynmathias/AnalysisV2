#include "SSDLSelection.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
//#include "Gen.hh"
#include <fstream>
using namespace Event;
namespace SSDL {
  bool compareE( const Lepton* o1, const Lepton* o2)  { return o1->E() > o2->E(); }

  bool comparePt(TLorentzVector v1, TLorentzVector v2) {
    return v1.Pt() > v2.Pt();
  }

  SSDLSelection::SSDLSelection(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName)
  {
    ignoreNonTau=(pset.Contains("IgnoreNonTauStates") ? pset.Get<bool>("IgnoreNonTauStates") : false);
    onlyETau=(pset.Contains("OnlyETau") ? pset.Get<bool>("OnlyETau") : false);
    onlyMuTau=(pset.Contains("OnlyMuTau") ? pset.Get<bool>("OnlyMuTau") : false);
    onlyTauTau=(pset.Contains("OnlyTauTau") ? pset.Get<bool>("OnlyTauTau") : false);
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
    leptonCut=pset.Get<double>("LeptonCut");
    uppermetcut_=pset.Get<double>("UpperMetCut");
    mInterestingEvents=(pset.Contains("InterestingEvents") ? pset.Get<bool>("InterestingEvents") : false);
    
    for (int ih=0;ih<6;ih++){
      
      for (int ib=0;ib<5;ib++)
	nhdl[ih][ib]=0;

      for (int ib=0;ib<3;ib++){
	nhsl[ih][ib]=0;

      }
    }
  }

  void SSDLSelection::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();

  }
  SSDLSelection::~SSDLSelection() {

  }

  void  SSDLSelection::BookHistos() {


    //trigger efficiency
    h_ssdl_trigEff=new TH1D("h_ssdl_trigEff", "h_ssdl_trigEff",5,-0.5,4.5);
  


    //this is for a crude cut flow
    h_ssdl_cFlow=new TH2D("h_ssdl_cFlow", "h_ssdl_cFlow",6, -0.5, 5.5, 10, -0.5, 9.5);//allow 10 cuts and just fill each consecutive bin for each final state

    //just to get the lep spect
    h_gen_lepPtSpec=new TH1D("h_gen_lepPtSpec","h_gen_lepPtSpec",100,0.,100.);

    //Arlo Jamboree plots 24/08/10 for Jamboree 02-03/09/10

    h_ssdl_postMHT=new TH1D("h_ssdl_postMHT","h_ssdl_postMHT",6,-0.5,5.5);
    h_ssdl_postHT=new TH1D("h_ssdl_postHT","h_ssdl_postHT",6,-0.5,5.5);
    h_ssdl_postHT_postMHT=new TH1D("h_ssdl_postHT_postMHT","h_ssdl_postHT_postMHT",6,-0.5,5.5);
    h_HT_postSSDL=new TH1D("h_HT_postSSDL","h_HT_postSSDL",100,0.,1500.);
    h_MHT_postSSDL=new TH1D("h_MHT_postSSDL","h_MHT_postSSDL",100,0.,1500.);
    h_MHT_postHT=new TH1D("h_MHT_postHT","h_MHT_postHT",100,0,1000.);
    h_MHT_postHT_postSSDL=new TH1D("h_MHT_postHT_postSSDL","h_MHT_postHT_postSSDL",100,0,1000.);
    //nb ht and mht before cuts are already added below
    h_nmuon_postHT=new TH1D("h_nmuon_postHT","h_nmuon_postHT",20,-0.5,19.5);
    h_nelec_postHT=new TH1D("h_nelec_postHT","h_nelec_postHT",20,-0.5,19.5);
    h_ntau_postHT=new TH1D("h_ntau_postHT","h_ntau_postHT",20,-0.5,19.5);
    h_nmuon_postMHT=new TH1D("h_nmuon_postMHT","h_nmuon_postMHT",20,-0.5,19.5);
    h_nelec_postMHT=new TH1D("h_nelec_postMHT","h_nelec_postMHT",20,-0.5,19.5);
    h_ntau_postMHT=new TH1D("h_ntau_postMHT","h_ntau_postMHT",20,-0.5,19.5);
    h_nmuon_postHT_postMHT=new TH1D("h_nmuon_postHT_postMHT","h_nmuon_postHT_postMHT",20,-0.5,19.5);
    h_nelec_postHT_postMHT=new TH1D("h_nelec_postHT_postMHT","h_nelec_postHT_postMHT",20,-0.5,19.5);
    h_ntau_postHT_postMHT=new TH1D("h_ntau_postHT_postMHT","h_ntau_postHT_postMHT",20,-0.5,19.5);
    h_nlep_postHT=new TH1D("h_nlep_postHT","h_nlep_postHT",20,-0.5,19.5);
    h_nlep_postMHT=new TH1D("h_nlep_postMHT","h_nlep_postMHT",20,-0.5,19.5);
    h_nlep_postHT_postMHT=new TH1D("h_nlep_postHT_postMHT","h_nlep_postHT_postMHT",20,-0.5,19.5);

    h_mu_eta_postHT=new TH1D("h_mu_eta_postHT","h_mu_eta_postHT",5,0.,2.5);
    h_elec_eta_postHT=new TH1D("h_elec_eta_postHT","h_elec_eta_postHT",5,0.,2.5);
    h_tau_eta_postHT=new TH1D("h_tau_eta_postHT","h_tau_eta_postHT",5,0.,2.5);
    h_mu_eta_postMHT=new TH1D("h_mu_eta_postMHT","h_mu_eta_postMHT",5,0.,2.5);
    h_elec_eta_postMHT=new TH1D("h_elec_eta_postMHT","h_elec_eta_postMHT",5,0.,2.5);
    h_tau_eta_postMHT=new TH1D("h_tau_eta_postMHT","h_tau_eta_postMHT",5,0.,2.5);
    h_mu_eta_postHT_postMHT=new TH1D("h_mu_eta_postHT_postMHT","h_mu_eta_postHT_postMHT",5,0.,2.5);
    h_elec_eta_postHT_postMHT=new TH1D("h_elec_eta_postHT_postMHT","h_elec_eta_postHT_postMHT",5,0.,2.5);
    h_tau_eta_postHT_postMHT=new TH1D("h_tau_eta_postHT_postMHT","h_tau_eta_postHT_postMHT",5,0.,2.5);

    h_mu_pt_postHT=new TH1D("h_mu_pt_postHT","h_mu_pt_postHT",50,0.,150);
    h_elec_pt_postHT=new TH1D("h_elec_pt_postHT","h_elec_pt_postHT",50,0.,150);
    h_tau_pt_postHT=new TH1D("h_tau_pt_postHT","h_tau_pt_postHT",50,0.,150);
    h_mu_pt_postMHT=new TH1D("h_mu_pt_postMHT","h_mu_pt_postMHT",50,0.,150);
    h_elec_pt_postMHT=new TH1D("h_elec_pt_postMHT","h_elec_pt_postMHT",50,0.,150);
    h_tau_pt_postMHT=new TH1D("h_tau_pt_postMHT","h_tau_pt_postMHT",50,0.,150);
    h_mu_pt_postHT_postMHT=new TH1D("h_mu_pt_postHT_postMHT","h_mu_pt_postHT_postMHT",50,0.,150);
    h_elec_pt_postHT_postMHT=new TH1D("h_elec_pt_postHT_postMHT","h_elec_pt_postHT_postMHT",50,0.,150);
    h_tau_pt_postHT_postMHT=new TH1D("h_tau_pt_postHT_postMHT","h_tau_pt_postHT_postMHT",50,0.,150);

    //end of jamboree plots

    h_ss_HT= new TH1D("h_HT","h_HT",40, 0.,2000.);
    h_ss_MHT= new TH1D("h_MHT","h_MHT",60, 0.,1500.);

    h_ss_NTAU=new TH1D("h_NTAU","h_NTAU",20,0,20);
    h_ss_NMUON=new TH1D("h_NMUON","h_NMUON",20,0,20);
    h_ss_NELEC=new TH1D("h_NELEC","h_NELEC",20,0,20);
    h_ss_NLEPTON=new TH1D("h_NLEPTON","h_NLEPTON",20,0,20);
    h_ss_RECSTATE=new TH1D("h_RECSTATE","h_RECSTATE",6,-0.5,5.5);
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
 

    
    h_ht_sl = new TH2D("h_ht_sl","h_ht_sl",6,0,6,3,0,3);
    h_ht_dl = new TH2D("h_ht_dl","h_ht_dl",6,0,6,6,0,6);

  


  }

  bool SSDLSelection::Process(Event::Data & ev) {

    h_ssdl_trigEff->Fill(0);



    float HT=ev.CommonHT();
    // float MHT=ev.CommonMHT().Pt();
    //try the selection with PFMET - AGB 27/10/10
    float MHT=ev.PFMET().Pt();
    uint NELEC=ev.LD_CommonElectrons().accepted.size();
    
    uint NMUON=ev.LD_CommonMuons().accepted.size();
    uint NTAUS=ev.LD_CommonTaus().accepted.size();

 
    w=ev.GetEventWeight();
  
    




	
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
      AllLeptons.push_back(*lep);
      h_tauEtaPt->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);
    }
    
    sort((AllLeptons).begin(), (AllLeptons).end(), compareLepPt);
    uint NLEPTONS=AllLeptons.size();

    h_bc_NMUON->Fill(NMUON,w);
    h_bc_NELEC->Fill(NELEC,w);
    h_bc_NTAU->Fill(NTAUS,w);

  
    int chProd=-1;
    float InvMassSS=0.;
    int NVertices=ev.GetVertexSize();
    bool VertCompatibility = false;
    if (AllLeptons.size()>1){

      chProd=int(AllLeptons[0]->GetCharge()*AllLeptons[1]->GetCharge());
      TLorentzVector lep1(AllLeptons[0]->Px(),AllLeptons[0]->Py(),AllLeptons[0]->Pz(),AllLeptons[0]->E());
      TLorentzVector lep2(AllLeptons[1]->Px(),AllLeptons[1]->Py(),AllLeptons[1]->Pz(),AllLeptons[1]->E());
      InvMassSS=(lep1+lep2).M();
      if (NVertices>0){
         bool GoodVertex=false;
         for (int ivx=0;ivx<NVertices;ivx++){
          if (GoodVertex) continue;
          if(!ev.GetvertexIsFake(ivx) && ev.GetvertexNdof(ivx)>=4 && ev.GetvertexPosition(ivx).Rho()<2. && fabs(ev.GetvertexPosition(ivx).Z())<24.0){
              GoodVertex=true;
            }
           if (GoodVertex){
	    float lep1Z=0; float lep2Z=0;
            if (AllLeptons[0]->GetType()==3) lep1Z=ev.GetTauVx(AllLeptons[0]->GetIndex()).Z();
            if (AllLeptons[0]->GetType()==2) lep1Z=ev.GetMuonVx(AllLeptons[0]->GetIndex()).Z();
            if (AllLeptons[0]->GetType()==1) lep1Z=ev.GetElectronVx(AllLeptons[0]->GetIndex()).Z();     
	    if (AllLeptons[1]->GetType()==3) lep2Z=ev.GetTauVx(AllLeptons[1]->GetIndex()).Z();
            if (AllLeptons[1]->GetType()==2) lep2Z=ev.GetMuonVx(AllLeptons[1]->GetIndex()).Z();
            if (AllLeptons[1]->GetType()==1) lep2Z=ev.GetElectronVx(AllLeptons[1]->GetIndex()).Z();

          VertCompatibility = ( GoodVertex &&   (fabs(ev.GetvertexPosition(ivx).Z()-lep1Z)<1.0) &&
                               (fabs(ev.GetvertexPosition(ivx).Z()-lep2Z)<1.0));


          }
      //VERTEX COMPATIBILITY MUST BE ADDED
     //VERTEX OF LEPTONS IS MISSING
         }	
       }
     }
    //New for the SSDL analysis: Z veto. 
    //If 3rd lepton in event (after id) pairs with one of the candidate leptons to form Z within 76GeV<M<106GeV
    bool Zveto = false;
    if(AllLeptons.size()>2){
      if (AllLeptons[2]->GetType()==AllLeptons[0]->GetType() && AllLeptons[2]->GetCharge()== - AllLeptons[0]->GetCharge() && (*AllLeptons[2]+*AllLeptons[0]).M()>76. && (*AllLeptons[2]+*AllLeptons[0]).M()<106.) Zveto = true;
      if (AllLeptons[2]->GetType()==AllLeptons[1]->GetType() && AllLeptons[2]->GetCharge()== - AllLeptons[1]->GetCharge() && (*AllLeptons[2]+*AllLeptons[1]).M()>76. && (*AllLeptons[2]+*AllLeptons[1]).M()<106.) Zveto = true;
    }
    
    
    vector<bool> CUTS;
    
    //CUT LIST
    CUTS.push_back((NLEPTONS>leptonCut));
    CUTS.push_back((chProd>0));
    if(htCut>0.){ // for some reason 0 (could be either ht or mht, not sure) still applies some kind of cut...Something to do with number of jets in commonHT?
      CUTS.push_back((HT>htCut));
    }
    if(mhtCut>0.){
      CUTS.push_back(MHT>mhtCut);
    }
    CUTS.push_back(!Zveto);
    CUTS.push_back(MHT<uppermetcut_);
    CUTS.push_back(NVertices>0);
    CUTS.push_back(InvMassSS>5.); 
    // CUTS.push_back(VertCompatibility);
    bool DECISION=true;





    for(vector<Lepton const *>::const_iterator mu=ev.LD_CommonMuons().accepted.begin(); mu!=ev.LD_CommonMuons().accepted.end(); ++mu){
      if(CUTS[2]){
	h_mu_eta_postHT->Fill((*mu)->eta(),w);
	h_mu_pt_postHT->Fill((*mu)->Pt(),w);
      }
      if(CUTS[3]){
	//add post MHT mu here
	h_mu_eta_postMHT->Fill((*mu)->eta(),w);
	h_mu_pt_postMHT->Fill((*mu)->Pt(),w);
      }
      if(CUTS[2]&&CUTS[3]){
	//add post HT&MHT mu here
	h_mu_eta_postHT_postMHT->Fill((*mu)->eta(),w);
	h_mu_pt_postHT_postMHT->Fill((*mu)->Pt(),w);
	
      }      
    }

	
    for(vector<Lepton const *>::const_iterator el=ev.LD_CommonElectrons().accepted.begin(); el!=ev.LD_CommonElectrons().accepted.end(); ++el){
      


      if(CUTS[2]){
	h_elec_eta_postHT->Fill((*el)->eta(),w);
	h_elec_pt_postHT->Fill((*el)->Pt(),w);
      }
      if(CUTS[3]){
	//add post MHT el here
	h_elec_eta_postMHT->Fill((*el)->eta(),w);
	h_elec_pt_postMHT->Fill((*el)->Pt(),w);
      }
      if(CUTS[2]&&CUTS[3]){
	//add post HT&MHT elec here
	h_elec_eta_postHT_postMHT->Fill((*el)->eta(),w);
	h_elec_pt_postHT_postMHT->Fill((*el)->Pt(),w);
      }
      
    }

    for(vector<Lepton const *>::const_iterator tau=ev.LD_CommonTaus().accepted.begin(); tau!=ev.LD_CommonTaus().accepted.end(); ++tau){
      if(CUTS[2]){
	h_tau_eta_postHT->Fill((*tau)->eta(),w);
	h_tau_pt_postHT->Fill((*tau)->Pt(),w);
      }
      if(CUTS[3]){
	//add post MHT tau here
	h_tau_eta_postMHT->Fill((*tau)->eta(),w);
	h_tau_pt_postMHT->Fill((*tau)->Pt(),w);
      }
      if(CUTS[2]&&CUTS[3]){
	//add post HT&MHT tau here
	h_tau_eta_postHT_postMHT->Fill((*tau)->eta(),w);
	h_tau_pt_postHT_postMHT->Fill((*tau)->Pt(),w);
      }
    }

    if(CUTS[2]){
      h_nmuon_postHT->Fill(NMUON,w);
      h_nelec_postHT->Fill(NELEC,w);
      h_ntau_postHT->Fill(NTAUS,w);
      h_nlep_postHT->Fill(NLEPTONS,w);
    }

    if(CUTS[3]){
      h_nmuon_postMHT->Fill(NMUON,w);
      h_nelec_postMHT->Fill(NELEC,w);
      h_ntau_postMHT->Fill(NTAUS,w);
      h_nlep_postMHT->Fill(NLEPTONS,w);
    }

    if(CUTS[2]&&CUTS[3]){
       h_nmuon_postHT_postMHT->Fill(NMUON,w);
      h_nelec_postHT_postMHT->Fill(NELEC,w);
      h_ntau_postHT_postMHT->Fill(NTAUS,w);
      h_nlep_postHT_postMHT->Fill(NLEPTONS,w);
    }

    if(CUTS[2]){
	h_ssdl_trigEff->Fill(1,w);
      }
    if(CUTS[3]){
      h_ssdl_trigEff->Fill(2,w);
    }
    if(CUTS[2]&&CUTS[3]){
      h_ssdl_trigEff->Fill(3,w);
    }
    if(CUTS[2]&&CUTS[3]&&(NLEPTONS>0)){
	h_ssdl_trigEff->Fill(4,w);
      }
    

    //SAME SIGN ELECTRONS
    h_ssdl_cFlow->Fill(0.,0.,w);
    h_ssdl_cFlow->Fill(1.,0.,w);
    h_ssdl_cFlow->Fill(2.,0.,w);
    h_ssdl_cFlow->Fill(3.,0.,w);
    h_ssdl_cFlow->Fill(4.,0.,w);
    h_ssdl_cFlow->Fill(5.,0.,w);
 
    if(CUTS[0]){
      int REC_STATE=-1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
      if (chProd>0) chProd=1;
      else chProd=-1;




      if(CUTS[0]){//this is a really gross way of doing this...but it'll do for now. AGB - 05/11/10
	h_ssdl_cFlow->Fill(REC_STATE,1.,w);
	if(CUTS[1]){
	  h_ssdl_cFlow->Fill(REC_STATE,2.,w);
	  if(CUTS[2]){
	    h_ssdl_cFlow->Fill(REC_STATE,3.,w);
	    if(CUTS[3]){
	      h_ssdl_cFlow->Fill(REC_STATE,4.,w);
	      if(CUTS[4]){
		h_ssdl_cFlow->Fill(REC_STATE,5.,w);
	      }
	    }
	  }
	}
      }
      
      if(chProd>0){
	h_HT_postSSDL->Fill(HT,w);
	h_MHT_postSSDL->Fill(MHT,w);
      }

      if(CUTS[2]){
	h_MHT_postHT->Fill(MHT,w);
      }
	

      if(CUTS[2]&&chProd>0){
	h_ssdl_postHT->Fill(REC_STATE,w);
	h_MHT_postHT_postSSDL->Fill(MHT,w);
      }

      if(CUTS[2]&&CUTS[3]&&chProd>0){
	  h_ssdl_postHT_postMHT->Fill(REC_STATE,w);
	}

    }
  
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

      if(chProd>0){
	h_ssdl_postMHT->Fill(REC_STATE,w);
      }
    }
  
      
      
      
    
      
    
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


    if (CUTS[1]&&CUTS[3]&&(NLEPTONS==2)){
      int REC_STATE=99;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
    }

    //FINAL PLOTS
    if (DECISION){

    //  cout<<mFolderName<<endl<<"RUN:LUMI:EVENT "<<ev.RunNumber()<<":"<<ev.LumiSection()<<":"<<ev.EventNumber()<<endl
    //    <<"FIRST LEP "<<AllLeptons[0]->GetType()<<" Pt= "<<AllLeptons[0]->Pt()
    //    <<"(eta,phi)=( "<<AllLeptons[0]->Eta()<<","<<AllLeptons[0]->Phi()<<")"<<endl
    //    <<"SECOND LEP "<<AllLeptons[1]->GetType()<<" Pt= "<<AllLeptons[1]->Pt()
    //    <<"(eta,phi)=( "<<AllLeptons[1]->Eta()<<","<<AllLeptons[1]->Phi()<<")"<<endl
    //    <<"HT "<<HT<<" MET "<<MHT<<" NJets "<<ev.JD_CommonJets().accepted.size()<<endl;

    
      int REC_STATE=-1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0; // ee
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1; // mm
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2; // tt
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3; // em
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4; // et
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5; // mt
      h_ss_NTAU->Fill(NTAUS,w);
      h_ss_NELEC->Fill(NELEC,w);
      h_ss_NMUON->Fill(NMUON,w);
      h_ss_ht[REC_STATE]->Fill(HT,w);
      h_ss_mht[REC_STATE]->Fill(MHT,w);
      h_ss_RECSTATE->Fill(REC_STATE,w);

     

      //this is a(nother...) hack - let's us turn off the non tau final states for exclusion plots considering only taus
      
      if (ignoreNonTau==true){
	if (REC_STATE==0 || REC_STATE==1 || REC_STATE==3){
	  DECISION = false;
	}
      }

      if (onlyETau==true){
	if (REC_STATE!=4){
	  DECISION = false;
	}
      }

      if (onlyMuTau==true){
	if (REC_STATE!=5){
	  DECISION = false;
	}
      }

      if (onlyTauTau==true){
	if (REC_STATE!=2){
	  DECISION = false;
	}
      }
      
      //Here we print out information about interesting events (only in data)
      
      if (mInterestingEvents && ev.IsData.enabled()){//this is needed at the moment since older MC ntuples don't contain the branch
	if(ev.GetIsData()){
	  std::string lep_type1, lep_type2;
	  switch (AllLeptons[0]->GetType()){
	  case 1:
	    lep_type1="el";
	    break;
	  case 2:
	    lep_type1="mu";
	    break;
	  case 3:
	    lep_type1="tau";
	    break;
	  default:
	    lep_type1="unknown";
	  }
	  switch (AllLeptons[1]->GetType()){
	  case 1:
	    lep_type2="el";
	    break;
	  case 2:
	    lep_type2="mu";
	    break;
	  case 3:
	    lep_type2="tau";
	    break;
	  default:
	    lep_type2="unknown";
	  }
	  
	  
	  ofstream Out;
	  Out.open(("Interesting_events.txt"),ios::out|ios::app);
	  Out<<"RUN: "<<ev.GetRunNumber()<<"    "<<"LUMISEC: "<<ev.GetLumiSec()<<"    "<<"EVENT: "<<ev.GetEventNumber()<<endl;
	  Out<<"HT: "<<ev.CommonHT()<<endl;
	  Out<<"MHT: "<<ev.CommonMHT().pt()<<"   pfMET: "<<ev.PFMET().pt()<<endl;
	  Out<<"Invariant mass/type of two leading leptons: lepton1: "+lep_type1+" lepton2: "+lep_type2+" inv. mass: "<<(*AllLeptons[0]+*AllLeptons[1]).M()<<endl;
	  Out<<"===========The Jets=================="<<endl;
	  for(std::vector<Event::Jet const*>::const_iterator jet=ev.JD_CommonJets().accepted.begin(); jet!=ev.JD_CommonJets().accepted.end(); ++jet){
	    Out<<"Jet "<<jet-ev.JD_CommonJets().accepted.begin()<<":   pt: "<<(*jet)->Pt()<<" eta: "<<(*jet)->eta()<<" phi: "<<(*jet)->phi()<<endl;
	}
	  Out<<"===========The Electrons============"<<endl;
	  for(std::vector<Event::Lepton const *>::const_iterator el=ev.LD_CommonElectrons().accepted.begin(); el!=ev.LD_CommonElectrons().accepted.end(); ++el){
	    Out<<"Electron "<<el-ev.LD_CommonElectrons().accepted.begin()<<":   pt: "<<(*el)->pt()<<" eta: "<<(*el)->eta()<<" phi: "<<(*el)->phi()<<" charge: "<<(*el)->GetCharge()<<endl;
	  }
	  Out<<"===========The Muons============"<<endl;
	  for(std::vector<Event::Lepton const*>::const_iterator mu=ev.LD_CommonMuons().accepted.begin(); mu!=ev.LD_CommonMuons().accepted.end(); ++mu){
	    Out<<"Muon "<<mu-ev.LD_CommonMuons().accepted.begin()<<":   pt: "<<(*mu)->pt()<<" eta: "<<(*mu)->eta()<<" phi: "<<(*mu)->phi()<<" charge: "<<(*mu)->GetCharge()<<endl;
	  }
	  Out<<"===========The Taus============"<<endl;
	  for(std::vector<Event::Lepton const*>::const_iterator tau=ev.LD_CommonTaus().accepted.begin(); tau!=ev.LD_CommonTaus().accepted.end(); ++tau){
	    Out<<"Tau "<<tau-ev.LD_CommonTaus().accepted.begin()<<":   pt: "<<(*tau)->pt()<<" eta: "<<(*tau)->eta()<<" phi: "<<(*tau)->phi()<<" charge: "<<(*tau)->GetCharge()<<endl;
	  }
	  

	}
      }
    }
    return DECISION; // Check for fails above, return false to fail operation.
  } // end of Process method

  std::ostream& SSDLSelection::Description(std::ostream &ostrm) {
    ostrm << "SSDLSelection plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }


}












