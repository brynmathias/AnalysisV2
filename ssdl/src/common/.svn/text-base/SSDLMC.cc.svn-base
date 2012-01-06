/*! \file ComMCOps.cc
 * \brief Source code for common object plotting operations.
 */
#include "SSDLMC.hh"
#include "KinSuite.hh"
#include <math.h>
//#include "/framework/include/Compute_Variable.hh"

namespace SSDL {


  NOMC::NOMC(int id):
    id_(id){
 
  }
  
  void NOMC::Start(Event::Data & ev) {
  }
  void  NOMC::BookHistos() {
  }
  NOMC::~NOMC() {
  } // end of FRMC destructor.


  bool NOMC::Process(Event::Data & ev) {
 
    for (std::vector<Event::GenObject>::const_iterator par = ev.GenParticles().begin();
	 par != ev.GenParticles().end();
	 ++par) {
 
      if (fabs((*par).GetID())==id_) return false;
    }
    return true;
  }

  std::ostream& NOMC::Description(std::ostream& ostrm)
  {
    ostrm << "NOMC plots made here: (histograms in ";

    return ostrm;
    //enter description output here
  }


  FRMC::FRMC(const std::string & folderName,
	     Utils::ParameterSet &pset
	     ):mFolderName(folderName)  {   
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");  
  } // end of FRMC constructor.


  void FRMC::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
    
  }
 void  FRMC::BookHistos() {
   hAllEl= new TH2D("hAllEl","hAllEl",10,0,2.5,20,0,100);
   hGoodEl= new TH2D("hGoodEl","hGoodEl",10,0,2.5,20,0,100);
   hAllMu= new TH2D("hAllMu","hAllMu",10,0,2.5,20,0,100);
   hGoodMu= new TH2D("hGoodMu","hGoodMu",10,0,2.5,20,0,100);
 }


  FRMC::~FRMC() {


  } // end of FRMC destructor.


  bool FRMC::Process(Event::Data & ev) {
    float HT=ev.CommonHT();
    float MHT=ev.CommonMHT().Pt();
    float w=ev.GetEventWeight();
    float max_LepPt = 100.; //used in the min functions below
    bool DECISION=true;
    
    vector<bool> CUTS;
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]); 
    if (DECISION){
      for(vector<Lepton>::const_iterator lep=ev.LD_Electrons().begin();
	  lep!=ev.LD_Electrons().end();++lep) {
	if (fabs(lep->Eta())>2.4) continue;  
	int iMatch = ev.leptonMatch(&(*lep),1);
	int lepType = ev.leptonType(iMatch);
	if (lepType>0 &&lepType<6) continue;
	//ELEC ID CUTS
	int iEl = lep->GetIndex();
	bool passConv =  (  (fabs(ev.GetElectronDCot(iEl)) > 0.02) && 
			    (fabs(ev.GetElectronDist(iEl)) > 0.02 )   &&
			    (ev.GetElectronGsfTrackTrackerExpectedHitsInner(iEl) ==0));
	if (!passConv) continue;
	
	bool passCharge = ((lep->GetCharge() == ev.GetElectronSCCharge(iEl)) && 
			   (lep->GetCharge() == ev.GetElectronKFCharge(iEl))) ;
	
	if (!passCharge) continue;

	bool passIso;
	if(Utils::GetConfig<std::string>("Ntuple.Electrons.Suffix")=="PF"){
	passIso= (lep->Pt()<20.) ?
	  (ev.GetElectronChHadIso(iEl) + ev.GetElectronNeuHadIso(iEl)/3 
	   + ev.GetElectronPhotonIso(iEl) <  4.97 +  0.34 * lep->Pt())
	  : (lep->GetCombIsolation()<0.1);
	}
	else{
	  passIso = lep->GetCombIsolation()<0.1;
	}
	if (!passIso) continue;
	bool passd0=ev.GetElectronD0(iEl)<0.02;
	if (!passd0) continue; 
	
	hAllEl->Fill(fabs(lep->Eta()),min(lep->Pt(),max_LepPt),w);
	bool matched =false;
	for(vector<Lepton const *>::const_iterator goodLep=ev.LD_CommonElectrons().accepted.begin();
	    goodLep!=ev.LD_CommonElectrons().accepted.end();++goodLep){
	  if (matched) continue;
	  if (KS_DeltaR((*lep), (**goodLep))<0.05) matched=true;
	}
	if (matched) hGoodEl->Fill(fabs(lep->Eta()),min(lep->Pt(),max_LepPt),w);
      }

      //MUONS
      for(vector<Lepton>::const_iterator lep=ev.LD_SecMuons().begin();
	lep!=ev.LD_SecMuons().end();++lep) {
	if (fabs(lep->Eta())>2.4) continue;  
	int iMatch = ev.leptonMatch(&(*lep),2);
	int lepType = ev.leptonType(iMatch);
	if (lepType>0 &&lepType<6) continue;	
	int iM = lep->GetIndex();
	if (ev.secMuonGlobalTracknumberOfValidHits()->at(iM)<=10) continue;
	if (!ev.secMuonIsGlobalMuon()->at(iM))continue;
	if (!ev.secMuonIsTrackerMuon()->at(iM)) continue;
 	if (ev.secMuonGlobalTrackNormChi2()->at(iM)>10.) continue;
	if (fabs(ev.secMuonInnerTrackdxy()->at(iM)>0.02)) continue;
	hAllMu->Fill(fabs((*lep).Eta()),min((*lep).Pt(),max_LepPt),w);
	bool matched= false;
	for(vector<Lepton const *>::const_iterator goodLep=ev.LD_CommonMuons().accepted.begin();
	    goodLep!=ev.LD_CommonMuons().accepted.end();++goodLep){
	  if (matched) continue;
	  if (KS_DeltaR((*lep), (**goodLep))<0.05) matched=true;
	}
	if (matched)hGoodMu->Fill(fabs((*lep).Eta()),min((*lep).Pt(),max_LepPt),w);
      }

    }
    return DECISION;
  }
  std::ostream& FRMC::Description(std::ostream& ostrm)
  {
    ostrm << "FRMC plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
    //enter description output here
  }


  TTMC::TTMC(const std::string & folderName,
	     int nmu
	     ):nmu_(nmu),mFolderName(folderName)  {    
    
  } // end of FRMC constructor.

  void TTMC::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();

  }
 void  TTMC::BookHistos() {
 }


  TTMC::~TTMC() {


  } // end of TTMC destructor.


  bool TTMC::Process(Event::Data & ev) {
   
    int imuW=0;
    int imutauW=0;
    
    
    int ieleW=0;
    int ieletauW=0;

    if (nmu_<3)
      return (imuW+imutauW==nmu_);
    else
      return (ieleW+ieletauW==1);
  }
  std::ostream& TTMC::Description(std::ostream &ostrm) {
    ostrm << "TTMC plots made here: (histograms in ";
    return ostrm;
  }
 
  //start of SSDLMCTruth class 

  SSDLMCTruth::SSDLMCTruth (const std::string & folderName, Utils::ParameterSet &pset):
    //  SSDL::<int, SSDLMCTruth >,
    mFolderName(folderName)
  { 
    mSugraScan=pset.Get<bool>("MSugraScan");
    MCAnal_= pset.Get<bool>("McAnal");
  }

  void SSDLMCTruth::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();

  }
  SSDLMCTruth::~SSDLMCTruth(){}  //SSDLMCTruth destructor
  

  bool SSDLMCTruth::Process(Event::Data & ev) {
    
    if(mSugraScan){
      w=ev.GetSusyCrossSection() ;
      h_m0_m12_BeforeHLT->Fill(ev.GetM0(),ev.GetM12(),w); 
      h_m0_m12_BeforeHLT_nw->Fill(ev.GetM0(),ev.GetM12());       
    }else{
      w=ev.GetEventWeight();
    }
    
    if(MCAnal_){

      
      std::vector<Event::GenObject const *> isogenLep;
      
      std::vector<Event::GenObject const *> isogenEle;
      std::vector<Event::GenObject const *> isogenMu;
      std::vector<Event::GenObject const *> isogenTau;
      
      std::vector<Event::GenObject const *> charg;
      
      std::vector<Event::GenObject const *> genEle;
      std::vector<Event::GenObject const *> genMu;
      std::vector<Event::GenObject const *> genTau;
      
      std::vector<Event::GenObject const *> genW;
      std::vector<Event::GenObject const *> genZ;
      
      int icharg=0;

      int num_taus = 0;

      double genHT = 0.0;
      ICF_LorentzV genJet;
      // if(ev.genJetMatchIndex()->size() != ev.genJetP4()->size()){
      // 	cout<<ev.JD_CommonJets().accepted.size()<<"   "<<ev.genJetMatchIndex()->size()<<"   "<<ev.genJetP4()->size()<<endl;
      // 	cout<<"WTF"<<endl;
      // }
      
      
      // for(std::vector<Event::Jet const *>::const_iterator j = ev.JD_CommonJets().accepted.begin();
      // 	  j != ev.JD_CommonJets().accepted.end(); ++j){
      // 	genJet = ev.getMatchedGenJet(ev.genJetMatchIndex()->at(j - ev.JD_CommonJets().accepted.begin()));
      // 	// genJet = ev.get1MatchedGenJet(j - ev.JD_CommonJets().accepted.begin());
      // 	genHT += genJet.Et();
      // }

      for(std::vector<ICF_LorentzV>::const_iterator i = ev.genJetP4()->begin(); i != ev.genJetP4()->end();
	  ++i){
	genHT += i->Et();
      }
      // std::cout<<"Jets: number:"<<ev.JD_CommonJets().accepted.size()<<
      // 	"  "<<"gen jets number: "<<ev.genJetP4()->size()<<" GenHT: "<<genHT<<std::endl;
      // std::cout<<"MHT "<<ev.genMetP4True()->Pt()<<std::endl;
      MC_MHT->Fill(ev.genMetP4True()->Pt(), w);
      MC_HT->Fill(genHT, w);
      

      for (std::vector<Event::GenObject>::const_iterator par = ev.GenParticles().begin();
	   par != ev.GenParticles().end();
	   ++par) {
	// cout<<par->GetID()<<endl;
	if((*par).GetStatus()!=3)continue;
	if(fabs((*par).GetID())==1000024 || fabs((*par).GetID())==1000037){
	  // indChargino=(*par).GetIndex();
	  if(mSugraScan){
	    h_m0_m12_chargino->Fill(ev.GetM0(),ev.GetM12(),w);
	    h_m0_m12_chargino_nw->Fill(ev.GetM0(),ev.GetM12());
	  }
	  charg.push_back(&*par);
	  icharg++;
	}
	if(fabs((*par).GetID())==15 ){
	  genTau.push_back(&*par);	    
	}
	if(fabs((*par).GetID())==11 ){
	  genEle.push_back(&*par);	    
	}
	if(fabs((*par).GetID())==13 ){
	  genMu.push_back(&*par);	    
	}

	if(fabs((*par).GetID())==24 ){
	  genW.push_back(&*par);	    
	}
	if(fabs((*par).GetID())==23 ){
	  genZ.push_back(&*par);	    
	}
	  
	if(fabs((*par).GetMotherID())>1000000  || (fabs((*par).GetMotherID())>22 &&  fabs((*par).GetMotherID())<40 )){
	  if(fabs((*par).GetID())==11 && fabs((*par).Eta())<2.4 ){
	    isogenLep.push_back(&*par);
	    isogenEle.push_back(&*par);	     
	    MCTruthElecPt->Fill((*par).Pt());	      
	  } 
	  if(fabs((*par).GetID())==13 && fabs((*par).Eta())<2.4 ){
	    isogenLep.push_back(&*par);
	    isogenMu.push_back(&*par);
	    MCTruthMuonPt->Fill((*par).Pt());	   
	  } 
	  if(fabs((*par).GetID())==15 && fabs((*par).Eta())<2.4 ){
	    isogenLep.push_back(&*par);
	    isogenTau.push_back(&*par);
	    	   
	  } 
	}  // mother
	
	if(fabs(par->GetID())==15){
	  num_taus+=1;
	  MCTruthTauPt->Fill((*par).Pt());
	  if (par->Pt()>15.){
	    MCTruthTauPt15->Fill(par->Pt());
	   
	  }
	   MCTruthTauEta->Fill(fabs(par->Eta()));
	  
	  if (par->Pt()>15. && fabs(par->eta())<2.4){
	    MCTruthTauPt15Eta24->Fill(fabs(par->Pt()));
	      }
	}
	

      }  // loop over genpart
      
      MC_numTaus->Fill(num_taus);
      
      // sort(isogenLep.begin(),isogenLep.end(), compareGenPt);
	
      int genFinalState=-99;
      bool fs_2ssdl=false;
      if(isogenLep.size()==2){
	if(isogenLep[0]->GetID()*isogenLep[1]->GetID()>0){
	  fs_2ssdl=true;
	  if(mSugraScan){
	    h_m0_m12_BeforeHLT_gen2ss->Fill(ev.GetM0(),ev.GetM12(),w); 
	    h_m0_m12_BeforeHLT_gen2ss_nw->Fill(ev.GetM0(),ev.GetM12());
	  }
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 121)genFinalState = 0;    // ee
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 169)genFinalState = 1;    // mumu
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 225)genFinalState = 2;    // tautau
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 143)genFinalState = 3;    // emu
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 165)genFinalState = 4;    // etau
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 195)genFinalState = 5;    // mutau
	}
      }else if(isogenLep.size()>2){
       	//if(isogenLep[0]->GetID()*isogenLep[1]->GetID()>0){
	genFinalState=666;
	//	}
      }else{
	genFinalState=-1;
      }
      
      // mData = genFinalState;       
      //=================================================================================================================
      //================= chargino decays ===============================================================================
      if(mSugraScan){
	int itaufromCharg=0;
	int ielefromCharg=0;
	int imufromCharg=0;
	vector<int> index_motherCharg;
	for(uint ig = 0; ig <ev.GenParticles().size() ; ig++) { 
	  if(ev.GenParticles()[ig].GetStatus()!=3) continue;
	  if((fabs(ev.GenParticles()[ig].GetID())!=15) && (fabs(ev.GenParticles()[ig].GetID())!=11) && (fabs(ev.GenParticles()[ig].GetID())!=13))continue;	  
	  if(fabs(ev.GenParticles()[ig].GetMotherID())==1000024 || fabs(ev.GenParticles()[ig].GetMotherID())==1000037){  //  mother is chargino
	    h_m0_m12_charg_toLep->Fill(ev.GetM0(),ev.GetM12(),w);
	    h_m0_m12_charg_toLep_nw->Fill(ev.GetM0(),ev.GetM12());
	    if(fabs(ev.GenParticles()[ig].GetID())== 15){
	      
	      if(ev.genMotherStored()->at(ig))index_motherCharg.push_back(ev.GenParticles()[ig].GetMother());
	      itaufromCharg++;
	      h_m0_m12_charg_toTau->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toTau_nw->Fill(ev.GetM0(),ev.GetM12());
	    }
	    if(fabs(ev.GenParticles()[ig].GetID())== 11){
	      if(ev.genMotherStored()->at(ig))index_motherCharg.push_back(ev.GenParticles()[ig].GetMother());
	    
	      ielefromCharg++;
	      h_m0_m12_charg_toEle->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toEle_nw->Fill(ev.GetM0(),ev.GetM12());
	    }
	    if(fabs(ev.GenParticles()[ig].GetID())== 13){
	      imufromCharg++;
	     
	      h_m0_m12_charg_toMu->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toMu_nw->Fill(ev.GetM0(),ev.GetM12());
	    }
	  } // end if mother is chargino
	  else if(fabs(ev.GenParticles()[ig].GetMotherID()) == 24 || fabs(ev.GenParticles()[ig].GetMotherID()) == 23  || 
		  (fabs(ev.GenParticles()[ig].GetMotherID()) > 100000   &&  fabs(ev.GenParticles()[ig].GetMotherID())!=1000024  &&  fabs(ev.GenParticles()[ig].GetMotherID())!=1000037 )){  
	    if( ev.genMotherStored()->at(ig) && 
		( fabs(ev.GenParticles()[ev.GenParticles()[ig].GetMother()].GetMotherID()) == 1000024 ||
		  fabs(ev.GenParticles()[ev.GenParticles()[ig].GetMother()].GetMotherID()) == 1000037) ){

	      h_m0_m12_charg_toLep->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toLep_nw->Fill(ev.GetM0(),ev.GetM12());
	      
	      if(fabs(ev.GenParticles()[ig].GetID())== 15  &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 15 ){
		itaufromCharg++;
		h_m0_m12_charg_toTau->Fill(ev.GetM0(),ev.GetM12(),w);
		h_m0_m12_charg_toTau_nw->Fill(ev.GetM0(),ev.GetM12());
	      }
	      if(fabs(ev.GenParticles()[ig].GetID())== 11  &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 15  &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 11){
		ielefromCharg++;
		h_m0_m12_charg_toEle->Fill(ev.GetM0(),ev.GetM12(),w);
		h_m0_m12_charg_toEle_nw->Fill(ev.GetM0(),ev.GetM12());
	      }
	      if(fabs(ev.GenParticles()[ig].GetID())== 13 &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 15  &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 13){
		imufromCharg++;
		h_m0_m12_charg_toMu->Fill(ev.GetM0(),ev.GetM12(),w);
		h_m0_m12_charg_toMu_nw->Fill(ev.GetM0(),ev.GetM12());
	      }
	    } // granmother is chargino
	   
	  } else if( ev.genMotherStored()->at(ig) && ev.genMotherStored()->at(ev.GenParticles()[ig].GetMother()) && 
		     ( fabs(ev.GenParticles()[ev.GenParticles()[ev.GenParticles()[ig].GetMother()].GetMother()].GetMotherID()) == 1000024 ||
		       fabs(ev.GenParticles()[ev.GenParticles()[ev.GenParticles()[ig].GetMother()].GetMother()].GetMotherID()) == 1000037) ){	    
	    h_m0_m12_charg_toLep->Fill(ev.GetM0(),ev.GetM12(),w);
	    h_m0_m12_charg_toLep_nw->Fill(ev.GetM0(),ev.GetM12());
	    
	    if(fabs(ev.GenParticles()[ig].GetID())== 15 && fabs(ev.GenParticles()[ig].GetMotherID())!= 15  ){
 	      itaufromCharg++;
	      h_m0_m12_charg_toTau->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toTau_nw->Fill(ev.GetM0(),ev.GetM12());
	    }
	    if(fabs(ev.GenParticles()[ig].GetID())== 11 &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 15 &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 11 ){
	      ielefromCharg++;
	      h_m0_m12_charg_toEle->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toEle_nw->Fill(ev.GetM0(),ev.GetM12());
		}
	    if(fabs(ev.GenParticles()[ig].GetID())== 13  &&  fabs(ev.GenParticles()[ig].GetMotherID())!= 15 && fabs(ev.GenParticles()[ig].GetMotherID())!= 13){
	      imufromCharg++;
	      h_m0_m12_charg_toMu->Fill(ev.GetM0(),ev.GetM12(),w);
	      h_m0_m12_charg_toMu_nw->Fill(ev.GetM0(),ev.GetM12());
	    }
	  } // grand grand mother is chargino
	} // genparticle loop 
      } // end mSugraScan
      //=================================================================================================================
      //=================================================================================================================
      if(genFinalState<6 &&  genFinalState>=0){
	return true;
      }else{
	return false;      //  if  MCAnal_ = 1 only nlep==2 and SS returns true
      }      
    } // end of MCAnal_
    return true;      // if MCAnal_ = 0, it is always true
  }
  
  void SSDLMCTruth::BookHistos(){

    //create histos here

    //-------------- only for mSugra scan -----------------------------------------------------------------------
    h_m0_m12_BeforeHLT = new TH2D("h_m0_m12_BeforeHLT","h_m0_m12_BeforeHLT",80,0.,4000.,25,100.,600.);
    h_m0_m12_BeforeHLT_nw = new TH2D("h_m0_m12_BeforeHLT_nw","h_m0_m12_BeforeHLT_nw",80,0.,4000.,25,100.,600.);


    h_m0_m12_BeforeHLT_gen2ss = new TH2D("h_m0_m12_BeforeHLT_gen2ss","h_m0_m12_BeforeHLT_gen2ss",80,0.,4000.,25,100.,600.);
    h_m0_m12_BeforeHLT_gen2ss_nw = new TH2D("h_m0_m12_BeforeHLT_gen2ss_nw","h_m0_m12_BeforeHLT_gen2ss_nw",80,0.,4000.,25,100.,600.);


    h_m0_m12_charg_toTau = new TH2D("h_m0_m12_charg_toTau","h_m0_m12_charg_toTau",80,0.,4000.,25,100.,600.);
    h_m0_m12_charg_toMu = new TH2D("h_m0_m12_charg_toMu","h_m0_m12_charg_toMu",80,0.,4000.,25,100.,600.);
    h_m0_m12_charg_toEle = new TH2D("h_m0_m12_charg_toEle","h_m0_m12_charg_toEle",80,0.,4000.,25,100.,600.);
    h_m0_m12_charg_toLep = new TH2D("h_m0_m12_charg_toLep","h_m0_m12_charg_toLep",80,0.,4000.,25,100.,600.);


    h_m0_m12_charg_toTau_nw = new TH2D("h_m0_m12_charg_toTau_nw","h_m0_m12_charg_toTau_nw",80,0.,4000.,25,100.,600.);
    h_m0_m12_charg_toMu_nw = new TH2D("h_m0_m12_charg_toMu_nw","h_m0_m12_charg_toMu_nw",80,0.,4000.,25,100.,600.);
    h_m0_m12_charg_toEle_nw = new TH2D("h_m0_m12_charg_toEle_nw","h_m0_m12_charg_toEle_nw",80,0.,4000.,25,100.,600.);
    h_m0_m12_charg_toLep_nw = new TH2D("h_m0_m12_charg_toLep_nw","h_m0_m12_charg_toLep_nw",80,0.,4000.,25,100.,600.);


    h_m0_m12_nchargino_nw = new TH2D("h_m0_m12_nchargino_nw","h_m0_m12_nchargino_nw",80,0.,4000.,25,100.,600.);
    h_m0_m12_nchargino = new TH2D("h_m0_m12_nchargino","h_m0_m12_nchargino",80,0.,4000.,25,100.,600.);


    h_m0_m12_chargino_nw = new TH2D("h_m0_m12_chargino_nw","h_m0_m12_chargino_nw",80,0.,4000.,25,100.,600.);
    h_m0_m12_chargino = new TH2D("h_m0_m12_chargino","h_m0_m12_chargino",80,0.,4000.,25,100.,600.);
    //----------------------------------------------------------------------------------------------------------

    // h_charginoDecay = new TH1D("h_charginoDecay","h_charginoDecay",5,-1.,4.);


    MCTruthNumFSLeps=new TH1D("MCTruthNumISOFSLeps", "MCTruthNumISOFSLeps", 20, -0.5, 19.5);
    MCTruthSSDiLeps=new TH1D("MCTruthSSISODiLeps", "MCTruthSSISODiLeps", 7, -1.5, 5.5);
    
    MCTruthSingleIsoLepPt=new TH1D("MCTruthSingleIsoLepsPt", "MCTruthSingleIsoLepsPt",50,-10,240);
    MCTruthMultiIsoLepPt=new TH1D("MCTruthMultiIsoLepPt", "MCTruthMultiIsoLepPt", 50, -10, 240);
    
    MCTruthSS_DEFAULT_EMPTY_Pt=new TH1D("MCTruthSS_DEFAULT_EMPTY_Pt", "MCTruthSS_DEFAULT_EMPTY_Pt", 50, -10, 240);
    MCTruthSS_minus1_Pt=new TH1D("MCTruthSS_minus1_Pt", "MCTruthSS_minus1_Pt", 50, -10, 240);
    MCTruthSS_0_Pt=new TH1D("MCTruthSS_0_Pt", "MCTruthSS_0_Pt", 50, -10, 240);
    MCTruthSS_1_Pt=new TH1D("MCTruthSS_1_Pt", "MCTruthSS_1_Pt", 50, -10, 240);
    MCTruthSS_2_Pt=new TH1D("MCTruthSS_2_Pt", "MCTruthSS_2_Pt", 50, -10, 240);
    MCTruthSS_3_Pt=new TH1D("MCTruthSS_3_Pt", "MCTruthSS_3_Pt", 50, -10, 240);
    MCTruthSS_4_Pt=new TH1D("MCTruthSS_4_Pt", "MCTruthSS_4_Pt", 50, -10, 240);
    MCTruthSS_5_Pt=new TH1D("MCTruthSS_5_Pt", "MCTruthSS_5_Pt", 50, -10, 240);
    
    MCTruthElecPt=new TH1D("MCTruthElecPt", "MCTruthElecPt", 50, -10, 220);    
    MCTruthMuonPt=new TH1D("MCTruthMuonPt", "MCTruthMuonPt", 50, -10, 200);    
    MCTruthTauPt=new TH1D ("MCTruthTauPt", "MCTruthTauPt", 50, -10, 140);
    MCTruthTauPt15 = new TH1D ("MCTruthTauPt15", "MCTruthTauPt15", 50, -10, 140);
    MCTruthTauEta = new TH1D("MCTruthTauEta", "MCTruthTauEta", 10, 0, 2.5);
    MCTruthTauPt15Eta24 = new TH1D ("MCTruthTauPt15Eta24", "MCTruthTauPt15Eta24", 50, -10, 140);
    MC_numTaus=new TH1D ("MC_numTaus", "MC_numTaus", 10, 0, 9);
    MC_MHT = new TH1D ("MC_MHT", "MC_MHT", 50, -10, 200);
    MC_HT = new TH1D ("MC_HT", "MC_HT", 100, 0, 400);
       	
  }

  std::ostream& SSDLMCTruth::Description(std::ostream& ostrm)
  {
    ostrm << "SSDLMCTruth plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
//enter description output here
  }

  SSDL_MC_PreSel::SSDL_MC_PreSel(Utils::ParameterSet &pset){
    
    _channel=(pset.Contains("channel") ? pset.Get<int>("channel") : -1);
    _onlySS=(pset.Contains("samesign") ? pset.Get<bool>("samesign") : false);
    _onlyOS=(pset.Contains("oppositesign") ? pset.Get<bool>("oppositesign") : false);
  }

  std::ostream& SSDL_MC_PreSel::Description(std::ostream& ostrm)
  {
    ostrm << "SSDL_MC_PreSel" ;
    return ostrm;
  }

  bool SSDL_MC_PreSel::Process(Event::Data & ev){

    if (_onlySS == _onlyOS){
      _onlySS = false;
      _onlyOS = false;
    }

    std::vector<Event::GenObject const *> FinalStateLeps, PotentialFSTaus, FSTaus;
    std::vector<int> TauMotherInd, PotentialFSTausInd;

    // cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    // cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    for (std::vector<Event::GenObject>::const_iterator par = ev.GenParticles().begin();
    	 par != ev.GenParticles().end(); ++par){

    //   if(fabs(par->GetID())==11 || fabs(par->GetID())==13){
	
    //   	cout<<"Status "<<par->GetStatus()<<" Type: "<<fabs(par->GetID());
    //   	cout<<" Mother "<<par->GetMotherID()<<" MotherInd "<<par->GetMother()<<" Mother status: "<<ev.GenParticles()[par->GetMother()].GetStatus()<<endl;
    // 	cout<<"================================================"<<endl;
    //   }
      
    //   if(fabs(par->GetID())==15){
    // 	cout<<"Tau found, index "<<par-ev.GenParticles().begin()<<" id: "<<par->GetID();
    // 	cout<<" Mother: "<<par->GetMotherID();
    // 	cout<<" Mother status: "<<ev.GenParticles()[par->GetMother()].GetStatus();
    // 	cout<<" Mother ind: "<<par->GetMother();
    // 	cout<<" GrandMotherInd: "<<ev.GenParticles()[par->GetMother()].GetMother();
    // 	cout<<" GrandMother type: "<<ev.GenParticles()[par->GetMother()].GetMotherID();
    // 	cout<<" GrandMother status: "<<ev.GenParticles()[ev.GenParticles()[par->GetMother()].GetMother()].GetStatus()<<endl;
    // 	cout<<"================================================="<<endl;
    //   }
      
      
      
    //   if(fabs(par->GetID())==1000024){
    // 	cout<<"Chargino found "<<par->GetID()<<" Index "<<par-ev.GenParticles().begin()<<endl;
    //   }
      
      double abs_pid = fabs(par->GetID());
      double abs_motherid = fabs(par->GetMotherID());
      int mother_ind = par->GetMother();
      int mother_stat = ev.GenParticles()[mother_ind].GetStatus();
      double abs_Grdmotherid = fabs(ev.GenParticles()[mother_ind].GetMotherID());
      double abs_GrtGrdmotherid = fabs(ev.GenParticles()[ev.GenParticles()[mother_ind].GetMother()].GetMotherID());
      
	
      if(abs_pid == 11 || abs_pid == 13){
      	if(abs_motherid == 15 && mother_stat == 2){
    	  TauMotherInd.push_back(mother_ind);
      	  if(abs_Grdmotherid == 15 && abs_GrtGrdmotherid == 1000024){
      	    // cout<<"push_back"<<endl;
      	    FinalStateLeps.push_back(&*par);
      	  }
      	}
      }

      if(abs_pid == 15 && abs_Grdmotherid == 1000024){
    	PotentialFSTaus.push_back(&*par);
	PotentialFSTausInd.push_back(par-ev.GenParticles().begin());
      }

    }

    //Now we need to remove the taus that decayed to leptons:
    // cout<<"TauMothers size: "<<TauMotherInd.size()<<endl;
    
    if (TauMotherInd.size()>0){
      for(std::vector<int>::iterator tau = PotentialFSTausInd.begin(); tau != PotentialFSTausInd.end(); ++tau){
	bool had_tau = true;
	for(std::vector<int>::iterator tau_mother = TauMotherInd.begin(); tau_mother != TauMotherInd.end(); ++tau_mother){
	  // lept_tau = find(TauMotherInd.begin(), TauMotherInd.end(), *tau);
	  if(*tau == *tau_mother){
	    // PotentialFSTaus.erase(tau - PotentialFSTausInd.begin());
	    // cout<<*tau<<"  "<<*tau_mother<<endl;
	    had_tau = false;
	    break;
	  }
	}
	if(had_tau){
	  FSTaus.push_back(PotentialFSTaus[tau - PotentialFSTausInd.begin()]);
	}
      }
    }
  

    else{
      FSTaus = PotentialFSTaus;
    }
    
    // FinalStateLeps.insert(FinalStateLeps.end(), PotentialFSTaus.begin(), FSTaus.end());
    for(std::vector<Event::GenObject const *>::const_iterator t = FSTaus.begin(); t != FSTaus.end(); ++t){
      FinalStateLeps.push_back(&**t);
    }
    
    // cout<<FinalStateLeps.size()<<endl;
    
      if(FinalStateLeps.size() < 2){
	return false;
      }

      // else{
      // 	// cout<<FinalStateLeps.size()<<endl;
      // 	cout<<FinalStateLeps[0]->GetID()<<endl;
      // 	cout<<FinalStateLeps[1]->GetID()<<endl;
      // }
	


      const Event::GenObject *firstLep, *secLep;
      firstLep = FinalStateLeps[0];
      secLep = FinalStateLeps[1];
      bool SS_charge = true;
      if(firstLep->GetID()*secLep->GetID() < 0){
	SS_charge = false;
      }
      
      // cout<<"Charge: "<< SS_charge <<"  "<<firstLep->GetID()*secLep->GetID()<<endl;
      if(_onlySS && firstLep->GetID()*secLep->GetID() < 0){
	return false;
      }
      else if(_onlyOS && firstLep->GetID()*secLep->GetID() > 0){
	return false;
      }
      
      double id1 = fabs(firstLep->GetID());
      double id2 = fabs(secLep->GetID());

      switch(_channel){
      case 0:
	if(id1 == 11 && id2 == 11){
	  // cout<<"case0"<<endl;
	  return true;
	}
	break;
      case 1:
	if(id1 == 13 && id2 == 13){
	  return true;
	}
	break;
      case 2:
	if(id1 == 15 && id2 == 15){
	  // cout<<"case2"<<endl;
	  return true;
	}
	break;
      case 3:
	if(id1*id2 == 143){
	  return true;
	}
	break;
      case 4:
	if(id1*id2 == 165){
	  return true;
	}
	break;
      case 5:
	if(id1*id2 == 195){
	  return true;
	}
	break;
      case -1:
	return true;
      default:
	return false;
      }
      
    return false; //just to get rid of compiler warning
    
  }
  
} //~namespace Operation
  

	
