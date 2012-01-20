#include "ElecBkgEval.hh"
#include "KinSuite.hh"
using namespace Event;

namespace SSDL {

  ElecBkgEval::ElecBkgEval(const std::string & folderName,
			 Utils::ParameterSet &pset):
    mFolderName(folderName)
  {
    MCAnal_= pset.Get<double>("McAnal");
    
    //   MCAnal_= pset.Get<double>("McAnal");
    mhtCut=pset.Get<double>("MHTCut");
    htCut=pset.Get<double>("HTCut");
    njetCut=pset.Get<int>("NjetCut");
    metCut=pset.Get<double>("METCut");
  } // end of ElecBkgEval constructor.

  void ElecBkgEval::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }  
  
  ElecBkgEval::~ElecBkgEval() {
  } // end of TTBkgEval destructor.
  
  bool ElecBkgEval::Process(Event::Data & ev) {
    
    float METPF=ev.metP4pf()[0].Pt();
    float MHT=ev.PFMET().Pt();
    float HT=ev.CommonHT();
    float w=ev.GetEventWeight();
    bool  taufromV= false;
    bool  photon=false;

    bool hlt_jet50 = false;
    bool hlt_ht100 = false;    
    if(MCAnal_){
      for(uint i = 0; i < ev.GenParticles().size(); i++) { 
	if(ev.GenParticles()[i].GetStatus() ==3){	
	  if(ev.GenParticles()[i].GetID()==22)photon=true;
	  if( fabs(ev.GenParticles()[i].GetID())==15 &&  
	      (fabs(ev.GenParticles()[i].GetMotherID())==24 || fabs(ev.GenParticles()[i].GetMotherID())==23)  ){	  
	    taufromV=true;	  
	  }
	}
      }
      
      //if(taufromW)return 1;     
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
    

    
    std::vector<int> tauType;
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){	
      if(!hlt_jet50)continue;
     
      if(MHT>mhtCut)continue;
      if(HT<htCut)continue;
      if(METPF>metCut)continue;
      
      int iEl = (*lep)->GetIndex();
      bool passId=false;
      if ((*lep)->Pt()<20.) passId=(ev.GetElectronMva(iEl)   > 0.6) ;
      if ((*lep)->Pt()>20. &&  fabs((*lep)->Eta())<1.5) 
	passId=(fabs(ev.GetElectronDeltaPhiAtVtx(iEl))<0.06 &&
		fabs(ev.GetElectronDeltaEtaAtVtx(iEl))<0.004 ) ;
      if ((*lep)->Pt()>20. &&  fabs((*lep)->Eta())>1.5) 
	passId=(fabs(ev.GetElectronDeltaPhiAtVtx(iEl))<0.03 &&
		fabs(ev.GetElectronDeltaEtaAtVtx(iEl))<0.007 ) ;

      float elept=-1.;
      if((*lep)->Pt()>100){
	elept=99.;
      }else{
	elept=(*lep)->Pt();
      }

      h_RecoElec_EtaPt->Fill(fabs((*lep)->Eta()),elept,w);         
      //if(passId){
      if(passId){
	h_IDElec_EtaPt->Fill(fabs((*lep)->Eta()),elept,w);   
      }else{
	h_nonIDElec_EtaPt->Fill(fabs((*lep)->Eta()),elept,w);  
      }             
     
      if(HT<50.){	
	h_RecoElec_EtaPt_HT0->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
	if(passId){
	  h_IDElec_EtaPt_HT0->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);   
	}else{
	  h_nonIDElec_EtaPt_HT0->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);  
	}            
      }
      if(HT>=50 && HT<150 ){
	h_RecoElec_EtaPt_HT50->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
	if(passId){
	  h_IDElec_EtaPt_HT50->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);   
	}else{
	  h_nonIDElec_EtaPt_HT50->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);  
	}      
      }   
      if(HT>=150 && HT<350.){
	h_RecoElec_EtaPt_HT150->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
	if(passId){
	  h_IDElec_EtaPt_HT150->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);   
	}else{
	  h_nonIDElec_EtaPt_HT150->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);  
	}      
      }
      if( HT>=350.){
	h_RecoElec_EtaPt_HT350->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);         
	if(passId){
	  h_IDElec_EtaPt_HT350->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);   
	}else{
	  h_nonIDElec_EtaPt_HT350->Fill(fabs((*lep)->Eta()),(*lep)->Pt(),w);  
	}      
      }      
    }    
    return true;
  }
  void  ElecBkgEval::BookHistos(){
    h_RecoElec_EtaPt = new TH2D("h_RecoElec_EtaPt","h_RecoElec_EtaPt",3,0.,3.,10,0.,100.); 
    h_IDElec_EtaPt = new TH2D("h_IDElec_EtaPt","h_IDau_EtaPt",3,0.,3.,10,0.,100.); 
    h_nonIDElec_EtaPt = new TH2D("h_nonIDElec_EtaPt","h_nonIDau_EtaPt",3,0.,3.,10,0.,100.); 
    
    h_RecoElec_EtaPt_HT0 = new TH2D("h_RecoElec_EtaPt_HT0","h_RecoElec_EtaPt_HT0",5,0.,2.5,10,0.,100.); 
    h_IDElec_EtaPt_HT0 = new TH2D("h_IDElec_EtaPt_HT0","h_IDau_EtaPt_HT0",5,0.,2.5,10,0.,100.); 
    h_nonIDElec_EtaPt_HT0 = new TH2D("h_nonIDElec_EtaPt_HT0","h_nonIDau_EtaPt_HT0",5,0.,2.5,10,0.,100.); 
        
    h_RecoElec_EtaPt_HT50 = new TH2D("h_RecoElec_EtaPt_HT50","h_RecoElec_EtaPt_HT50",5,0.,2.5,10,0.,100.); 
    h_IDElec_EtaPt_HT50 = new TH2D("h_IDElec_EtaPt_HT50","h_IDau_EtaPt_HT50",5,0.,2.5,10,0.,100.); 
    h_nonIDElec_EtaPt_HT50 = new TH2D("h_nonIDElec_EtaPt_HT50","h_nonIDau_EtaPt_HT50",5,0.,2.5,10,0.,100.); 
    
    h_RecoElec_EtaPt_HT150 = new TH2D("h_RecoElec_EtaPt_HT150","h_RecoElec_EtaPt_HT150",5,0.,2.5,10,0.,100.); 
    h_IDElec_EtaPt_HT150 = new TH2D("h_IDElec_EtaPt_HT150","h_IDau_EtaPt_HT150",5,0.,2.5,10,0.,100.); 
    h_nonIDElec_EtaPt_HT150 = new TH2D("h_nonIDElec_EtaPt_HT150","h_nonIDau_EtaPt_HT150",5,0.,2.5,10,0.,100.); 
    
    h_RecoElec_EtaPt_HT350 = new TH2D("h_RecoElec_EtaPt_HT350","h_RecoElec_EtaPt_HT350",5,0.,2.5,10,0.,100.); 
    h_IDElec_EtaPt_HT350 = new TH2D("h_IDElec_EtaPt_HT350","h_IDau_EtaPt_HT350",5,0.,2.5,10,0.,100.); 
    h_nonIDElec_EtaPt_HT350 = new TH2D("h_nonIDElec_EtaPt_HT350","h_nonIDau_EtaPt_HT350",5,0.,2.5,10,0.,100.); 

    h_ElecEtaPt = new TH2D("h_ElecEtaPt","h_ElecEtaPt",5,0.,2.5,5,0.,150.); 
    h_selElecEtaPt = new TH2D("h_selElecEtaPt","h_selElecEtaPt",5,0.,2.5,5,0.,150.); 
    
  }
  std::ostream& ElecBkgEval::Description(std::ostream &ostrm) {
    ostrm << "ElecBkgEval plots made here: (histograms in ";
    ostrm <<  mFolderName << ")";
    return ostrm;
  }
  double ElecBkgEval::getDeltaR(double phi1, double phi2, double eta1, double eta2) {
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
