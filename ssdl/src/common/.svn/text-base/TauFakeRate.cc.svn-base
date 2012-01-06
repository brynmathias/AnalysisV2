#include "TauFakeRate.hh"
#include "KinSuite.hh"
using namespace Event;

namespace SSDL {
  TauFakeRate::TauFakeRate(const std::string & folderName,
			 Utils::ParameterSet &pset):
    mFolderName(folderName),
    tauSrc(pset.Get<string>("TauSource"))
  {
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
    upperMetCut=pset.Get<double>("UpperMetCut");    
    upperHTCut=pset.Get<double>("UpperHTCut");   
    looseIso_=pset.Get<int>("LooseIsolation");
    lepReq_ = pset.Get<bool>("OppLepRequest");
    mUseHps=pset.Get<bool>("UseHps");
  } // end of TauFakeRate constructor.

  void TauFakeRate::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }  
  
  TauFakeRate::~TauFakeRate() {
  } // end of TauFakeRate destructor.
  
  bool TauFakeRate::Process(Event::Data & ev) {    
    float HT=ev.CommonHT();
    float MHT=ev.PFMET().Pt();
    float w=ev.GetEventWeight();          

    bool DECISION=true;
    
    vector<bool> CUTS;
    uint iloosetaus=0; 
    
     float looseEta=-1.; 
     float loosePt=-1.;
     float looseCharge=0.;
     float JetWidth=0.;
   for(vector<Lepton>::const_iterator lep=ev.LD_Taus().begin();
	 lep!=ev.LD_Taus().end();++lep) {   

      if (fabs(lep->Pt())<(Utils::GetConfig<double>("Common.Taus.PtCut"))) continue;
      if (fabs(lep->Eta())>(Utils::GetConfig<double>("Common.Taus.EtaCut"))) continue;
      int iM = lep->GetIndex();  
      float jw=0.;
      if (!ev.IsTauAgainstElectron(iM)) continue;
      if (!ev.IsTauAgainstMuon(iM)) continue;
      if (fabs(lep->GetCharge())!=1) continue;
      if(tauSrc=="tauHPS"){
	if (!ev.IsTauByDecay(iM)) continue;  
	if ((looseIso_==1)   && (!ev.IsTauByLooseIso(iM))) continue;
	if ((looseIso_==2)   && (!ev.IsTauByMediumIso(iM))) continue;
	float dr=999;

	for(vector<Jet>::const_iterator jet=ev.JD_Jets().begin();
 	    jet!=ev.JD_Jets().end();++jet) {
	  int ijj=jet->GetIndex();
	  float DDRR=KS_DeltaR(*lep, *jet);
 	  if (DDRR>0.2) continue;	
	  if (DDRR<dr){
	    dr=DDRR;
	    jw=ev.GetJetWidth(ijj);
	  }
 	}  	

      }else{
         if (mUseHps){
          //HPS CASE
         float dr=999;
         int iSec=-1;
         for(vector<Lepton>::const_iterator seclep=ev.LD_SecTaus().begin();
            seclep!=ev.LD_SecTaus().end();++seclep) {
           float DRRR=KS_DeltaR(*lep, *seclep);
           if (DRRR>0.2) continue;
            if (DRRR<dr){
               dr=DRRR; 
               iSec=seclep->GetIndex();
 
            }
          }
         if (iSec<0) continue;
         if (!ev.secTauIdAgainstElectron()->at(iSec)) continue;
	 if (!ev.secTauIdAgainstMuon()->at(iSec)) continue;
	 if ((looseIso_==1)  && (!ev.secTauIdbyLooseIsolation()->at(iSec)  )) continue;
	 if ((looseIso_==2)  && (!ev.secTauIdbyMediumIsolation()->at(iSec) )) continue;
        } else{
         if ((looseIso_==1)   && (!ev.IsTauNCfr100(iM))) continue;
         if ((looseIso_==2)   && (!ev.IsTauNCfr050(iM))) continue;
         if ((looseIso_==3)   && (!ev.IsTauNCfr025(iM))) continue;
        }

      }
      iloosetaus++;
      if (iloosetaus==1){
	looseEta=fabs(lep->Eta()); 
	loosePt=lep->Pt();
	looseCharge=lep->GetCharge();
	JetWidth=jw;
        
      }
    }
    
    
    //CUT LIST
    CUTS.push_back(iloosetaus==1);
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    CUTS.push_back((HT<upperHTCut));
    CUTS.push_back(ev.PFMET().Pt()<upperMetCut);
    if (lepReq_){
      CUTS.push_back(ev.LD_CommonMuons().accepted.size()==1);
      if (ev.LD_CommonMuons().accepted.size()>0)
	CUTS.push_back((*ev.LD_CommonMuons().accepted.begin())->GetCharge() * looseCharge <0);
    }
    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);


    //EVALUATE THE EFFICIENCY
    if (DECISION){
      h_RecoTau_EtaPt->Fill(looseEta,TMath::Min(float(100.),loosePt),w);
      h_LTau->Fill(looseEta,TMath::Min(float(100.),loosePt),JetWidth,w);
      if (ev.LD_CommonTaus().accepted.size()==1){
 	h_IDTau_EtaPt->Fill(fabs((*ev.LD_CommonTaus().accepted.begin())->Eta()),TMath::Min(float(100.),(*ev.LD_CommonTaus().accepted.begin())->Pt()),w);	
 	h_TTau->Fill(looseEta,TMath::Min(float(100.),loosePt),JetWidth,w);
      }
    }
    return DECISION;
  }
  void  TauFakeRate::BookHistos(){
    h_RecoTau_EtaPt = new TH2D("h_RecoTau_EtaPt","h_RecoTau_EtaPt",10,0.,2.5,20,0.,100.); 
    h_IDTau_EtaPt = new TH2D("h_IDTau_EtaPt","h_IDau_EtaPt",10,0.,2.5,20,0.,100.);   
    h_LTau = new TH3D("h_LTau","h_LTau",10,0.,2.5,20,0.,100.,20,0.,0.04);
    h_TTau = new TH3D("h_TTau","h_TTau",10,0.,2.5,20,0.,100.,20,0.,0.04); 
  }
  std::ostream& TauFakeRate::Description(std::ostream &ostrm) {
    ostrm << "TauFakeRate plots made here: (histograms in ";
    ostrm <<  mFolderName << ")";
    return ostrm;
  }

}
