#include "SSDLTrigger.hh"

using namespace Event;
namespace SSDL {
  //================================
  // Good Jet Trigger Operation
  //================================
  //

  bool compareGenPt( const GenObject *gen1, const GenObject *gen2 ) {
    return (gen1)->Pt() > (gen2)->Pt();
  }


  SSDLTrigger::SSDLTrigger(const std::string & folderName,  Utils::ParameterSet &pset):
    mFolderName(folderName){
    //    MCAnal_= pset.Get<double>("McAnal");
    MCAnal_= pset.Get<bool>("McAnal");
    mSugraScan=bool(pset.Get<double>("MSugraScan"));
    triggerBits_.clear();
    bool BadTrigBit=false;
    
    for (int i=1;i<11;i++){
      if (BadTrigBit) continue;
      char htn[20];
      sprintf(htn,"%s%d","TriggerBits.bit",i);
      if (pset.Get<string>(htn)==""){
 	BadTrigBit=true;
 	continue;
      }
      triggerBits_.push_back(pset.Get<string>(htn));   
    }


  } // end of SSDLTrigger constructor.


  void SSDLTrigger::Start(Event::Data & ev) {

    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
    
  }


  SSDLTrigger::~SSDLTrigger() {
   
  } // end of SSDLTrigger destructor.


  
  bool SSDLTrigger::Process(Event::Data & ev) {
//    cout<<"EVENT "<<ev.EventNumber()<<" RUN "<<ev.RunNumber()<<endl;
    
//    map<string,bool>::const_iterator it= (*ev.hlt()).begin();
//    map<string,bool>::const_iterator ite= (*ev.hlt()).end();
    
//    for (;it!=ite;++it){
//      cout<<"NAME "<<it->first<<" "<<it->second<<endl;
//    }
       
    //All the trigger Paths passed via external file are  put in OR
    bool TrPassed =false;

  for(std::vector<std::string>::const_iterator it = triggerBits_.begin();
  it != triggerBits_.end();
  ++it){
    if( it->at(it->size()-1) != '*'){
      std::map<std::string, bool>::const_iterator itrig = ev.hlt()->begin();
      std::map<std::string, bool>::const_iterator jtrig = ev.hlt()->end();
      //            for( ; itrig != jtrig; ++itrig ){
// 	cout<<"TRIG "<<itrig->first<<" "<<itrig->second<<endl;
//       }
      std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);

      if(trig != ev.hlt()->end() && trig->second) TrPassed = true;
    }
    else{
      size_t found;
    // now loop though the map and test the string part -- slow!
      std::map<std::string, bool>::const_iterator itrig = ev.hlt()->begin();
      std::map<std::string, bool>::const_iterator jtrig = ev.hlt()->end();
      for( ; itrig != jtrig; ++itrig ){
        if(itrig->second){
          std::string str = *it;
          str = str.substr(0, str.size() - 1 );
          found = itrig->first.find(str);
          if(found != string::npos ){ 
	    TrPassed = true;}
        }
      }
    }
  }
    



//     for (uint i=0; i<triggerBits_.size();i++){
//       if (TrPassed) continue;
//       TrPassed=(map<string,bool>(*ev.hlt()))[triggerBits_[i]];
//     }
//    float TMath::Min(ev.CommonHT(),499.);

    float MEt= TMath::Min(ev.PFMET().Pt(),float(499.));
    float w=ev.GetEventWeight();

    
    h_trig_MET_den->Fill(MEt,w);
    h_trig_HT_den->Fill(ev.CommonHT(),w);
    if (ev.LD_CommonMuons().accepted.size()>0) h_trig_mu_den->Fill(TMath::Min(float(25.),(*ev.LD_CommonMuons().accepted.begin())->Pt()));
    if (ev.LD_CommonElectrons().accepted.size()>0) h_trig_el_den->Fill(TMath::Min(float(25.),(*ev.LD_CommonElectrons().accepted.begin())->Pt()));
    if (ev.LD_CommonTaus().accepted.size()>1) h_trig_tau_den->Fill(TMath::Min(float(25.),(*ev.LD_CommonTaus().accepted[1]).Pt()));
    if(TrPassed){
      h_trig_MET_num->Fill(MEt,w);
      h_trig_HT_num->Fill(ev.CommonHT(),w);
      if (ev.LD_CommonMuons().accepted.size()>0) h_trig_mu_num->Fill(TMath::Min(float(25.),(*ev.LD_CommonMuons().accepted.begin())->Pt()));
      if (ev.LD_CommonElectrons().accepted.size()>0) h_trig_el_num->Fill(TMath::Min(float(25.),(*ev.LD_CommonElectrons().accepted.begin())->Pt()));
      if (ev.LD_CommonTaus().accepted.size()>1) h_trig_tau_num->Fill(TMath::Min(float(25.),(*ev.LD_CommonTaus().accepted[1]).Pt()));
    }

    if (MCAnal_){
           
      std::vector<Event::GenObject const *> isogenLep;     
      std::vector<Event::GenObject const *> isogenEle;
      std::vector<Event::GenObject const *> isogenMu;
      std::vector<Event::GenObject const *> isogenTau;
     
      for (std::vector<Event::GenObject>::const_iterator par = ev.GenParticles().begin();
	   par != ev.GenParticles().end();
	   ++par) {
	if((*par).GetStatus()!=3)continue;

	if(fabs((*par).GetMotherID())>1000000  || (fabs((*par).GetMotherID())>22 &&  fabs((*par).GetMotherID())<40 )){
	  if(fabs((*par).GetID())==11 && fabs((*par).Eta())<2.5 ){
	    isogenLep.push_back(&*par);
	    isogenEle.push_back(&*par);	     
	        
	  } 
	  if(fabs((*par).GetID())==13 && fabs((*par).Eta())<2.4 ){
	    isogenLep.push_back(&*par);
	    isogenMu.push_back(&*par);
	      
	  } 
	  if(fabs((*par).GetID())==15 && fabs((*par).Eta())<2.4 ){    // here tau is considered stable (i.e both hadronic and leptonic decays are included)
	    isogenLep.push_back(&*par);
	    isogenTau.push_back(&*par);	    
	  } 
	}  // mother
	//	  ipar++;
      }  // loop over genpart
      
      sort(isogenLep.begin(),isogenLep.end(), compareGenPt);
      int genFinalState=-99;
      bool fs_2ssdl=false;
      if(isogenLep.size()==2){
	if(isogenLep[0]->GetID()*isogenLep[1]->GetID()>0){
	  fs_2ssdl=true;
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 121)genFinalState = 0;    // ee
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 169)genFinalState = 1;    // mumu
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 225)genFinalState = 2;    // tautau
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 143)genFinalState = 3;    // emu
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 165)genFinalState = 4;    // etau
	  if(isogenLep[0]->GetID()*isogenLep[1]->GetID() == 195)genFinalState = 5;    // mutau
	}
      }else if(isogenLep.size()>2){
	if(isogenLep[0]->GetID()*isogenLep[1]->GetID()>0){
	  genFinalState=6;
	}
      }else{
	genFinalState=-1;
      }
      
      //GET THE FINAL STATE
      // int ifs=ev.MC_SSFinalState();
      
     
      // if (ifs >-1){//true only for a pure SSDL state i.e. iff there are 2 SS leptons
      
      if (genFinalState >-1){  //  true for nlepton >= 2       	
	float minpt= isogenLep[1]->Pt();	
	h_trig_den_pt[6]->Fill(minpt);//Fill histos with non-pure SSDL states	
	if (TrPassed){
	  h_trig_num_pt[6]->Fill(minpt);	  
	}
	if ( genFinalState>=0 && genFinalState  <6){//fill histos with the pure SSDL (nlep=2 && SS) states
	  h_trig_den_pt[genFinalState]->Fill(minpt);
	  if (TrPassed){
	    h_trig_num_pt[genFinalState]->Fill(minpt);
	  }
	}
      }
    }    
    return TrPassed;
  }
  //////////////////////////////
  void  SSDLTrigger::BookHistos(){
    if (MCAnal_){
      BookHistArray(h_trig_den_pt,"h_trig_den_pt","h_trig_den_pt",10,0.,50.,dilepFinalStates+1,0,1,false);
      BookHistArray(h_trig_num_pt,"h_trig_num_pt","h_trig_num_pt",10,0.,50.,dilepFinalStates+1,0,1,false);
    }    

   

    h_trig_HT_den = new TH1D("h_trig_HT_den","h_trig_HT_den",100,200.,700.);
    h_trig_HT_num = new TH1D("h_trig_HT_num","h_trig_HT_num",100,200.,700.);
    h_trig_MET_den = new TH1D("h_trig_MET_den","h_trig_MET_den",100,0.,500.);
    h_trig_MET_num = new TH1D("h_trig_MET_num","h_trig_MET_num",100,0.,500.);
    h_trig_mu_den = new TH1D("h_trig_mu_den","h_trig_mu_den",100,0.,25.);
    h_trig_mu_num = new TH1D("h_trig_mu_num","h_trig_mu_num",100,0.,25.);
    h_trig_el_den = new TH1D("h_trig_el_den","h_trig_el_den",100,0.,25.);
    h_trig_el_num = new TH1D("h_trig_el_num","h_trig_el_num",100,0.,25.);    
    h_trig_tau_den = new TH1D("h_trig_tau_den","h_trig_tau_den",100,0.,25.);
    h_trig_tau_num = new TH1D("h_trig_tau_num","h_trig_tau_num",100,0.,25.);
  }
  ///////////////////////////////
  std::ostream& SSDLTrigger::Description(std::ostream &ostrm) {
    ostrm << "SSDLTrigger plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }
} //~namespace SSDL
  

