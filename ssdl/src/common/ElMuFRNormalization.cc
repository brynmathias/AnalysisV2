#include "ElMuFRNormalization.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
//#include "Gen.hh"
#include <fstream>
using namespace Event;
namespace SSDL {

  ElMuFRNormalization::ElMuFRNormalization(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName)
  {
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
  }

  void ElMuFRNormalization::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }
  ElMuFRNormalization::~ElMuFRNormalization() {

  }

  void  ElMuFRNormalization::BookHistos() {

    hGoodMuFakeEl= new TH2D("hGoodMuFakeEl","hGoodMuFakeEl",10,0,2.5,20,0,100);
    hGoodElFakeEl= new TH2D("hGoodElFakeEl","hGoodElFakeEl",10,0,2.5,20,0,100);
    hGoodMuFakeMu= new TH2D("hGoodMuFakeMu","hGoodMuFakeMu",10,0,2.5,20,0,100);
    hGoodElFakeMu= new TH2D("hGoodElFakeMu","hGoodElFakeMu",10,0,2.5,20,0,100);
  }

  bool ElMuFRNormalization::Process(Event::Data & ev) {
 

    float HT=ev.CommonHT();
    // float MHT=ev.CommonMHT().Pt();
    //try selection with PFMET - AGB 27/10/10
    float MHT=ev.PFMET().Pt();
    float w=ev.GetEventWeight();
 
   

    //PRIMARY LEPTONS
    std::vector<const Lepton *> AllLeptons;
    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
  
      AllLeptons.push_back(*lep);
    }

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
 	lep!=ev.LD_CommonElectrons().accepted.end();++lep){
   
      if (fabs((**lep).Eta())>2.4) continue;
       AllLeptons.push_back(*lep);
    }


    //SECONDARY LEPTONS
    
    std::vector<Lepton > AllSecLeptons;
    if (AllLeptons.size()==1){
      vector<Lepton const *>::iterator ll= AllLeptons.begin();
      for(vector<Lepton>::const_iterator lep=ev.LD_Muons().begin();
	  lep!=ev.LD_Muons().end();++lep) {

	if (fabs(lep->Eta())>(Utils::GetConfig<double>("Common.Muons.EtaCut"))) continue;
	if (fabs(lep->Pt())<(Utils::GetConfig<double>("Common.Muons.PtCut"))) continue;
	//NOT PRIMARY LEPTONS
	if (KS_DeltaR(*lep, (**ll))<0.05) continue;

	//MUON ID CUTS
	int iM = lep->GetIndex();
	if (ev.muonGlobalTracknumberOfValidHits()->at(iM)<=10) continue;
	if (!ev.muonIsGlobalMuon()->at(iM))continue;
	if (!ev.muonIsTrackerMuon()->at(iM)) continue;
 	if (ev.muonGlobalTrackNormChi2()->at(iM)>10.) continue;
	if (fabs(ev.muonInnerTrackdxyBS()->at(iM)>0.02)) continue;

	AllSecLeptons.push_back(*lep);
      }

      for(vector<Lepton>::const_iterator lep=ev.LD_Electrons().begin();
	  lep!=ev.LD_Electrons().end();++lep) {
	if (fabs(lep->Eta())>2.4) continue;
	if (fabs(lep->Pt())<(Utils::GetConfig<double>("Common.Electrons.PtCut"))) continue;


	//NOT PRIMARY LEPTONS
	if (KS_DeltaR(*lep, (**ll))<0.05) continue;
	    
	//ELEC ID CUTS
	int iEl = lep->GetIndex();
	bool passConv =  (  (fabs(ev.GetElectronDCot(iEl)) > 0.02) && 
			    (fabs(ev.GetElectronDist(iEl)) > 0.02 )   &&
			    (ev.GetElectronGsfTrackTrackerExpectedHitsInner(iEl) ==0));
	if (!passConv) continue;

	bool passCharge = ((lep->GetCharge() == ev.GetElectronSCCharge(iEl)) && 
			   (lep->GetCharge() == ev.GetElectronKFCharge(iEl))) ;

	if (!passCharge) continue;

      float ecaliso=0;
      if (fabs(lep->Eta())<1.5) {
	ecaliso=ev.electronEcalIso03()->at(iEl)-1.;
	if (ecaliso<0.) ecaliso=0.;	
      }
      else ecaliso=ev.electronEcalIso03()->at(iEl);
      bool passIso=((ecaliso+ev.electronHcalIso03()->at(iEl)+ev.electronTrkIso03()->at(iEl))<0.15);
      
      if (!passIso) continue;
      bool passd0=ev.GetElectronD0BS(iEl)<0.02;
	if (!passd0) continue; 
	
	
	AllSecLeptons.push_back(*lep);
      }
    }

    int chProd=-1;
    if (AllLeptons.size()==1 && AllSecLeptons.size()>=1)
      chProd=int(AllLeptons[0]->GetCharge()*AllSecLeptons[0].GetCharge());

    bool DECISION=true;

    vector<bool> CUTS;

    //CUT LIST
    CUTS.push_back((AllLeptons.size()==1) && (AllSecLeptons.size()>=1));
    CUTS.push_back((chProd>0));
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    float min_lepPt = 100.;
    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);


    if (DECISION){

      if (AllLeptons[0]->GetType()==1 && AllSecLeptons[0].GetType()==1)
	hGoodElFakeEl->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),min_lepPt),w);
      if (AllLeptons[0]->GetType()==2 && AllSecLeptons[0].GetType()==1)
	hGoodMuFakeEl->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),min_lepPt),w);      
      if (AllLeptons[0]->GetType()==1 && AllSecLeptons[0].GetType()==2)
	hGoodElFakeMu->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),min_lepPt),w);
      if (AllLeptons[0]->GetType()==2 && AllSecLeptons[0].GetType()==2)
	hGoodMuFakeMu->Fill(fabs(AllSecLeptons[0].Eta()),min(AllSecLeptons[0].Pt(),min_lepPt),w);     
    }
    
    return DECISION; // Check for fails above, return false to fail operation.
  } // end of Process method

  std::ostream& ElMuFRNormalization::Description(std::ostream &ostrm) {
    ostrm << "ElMuFRNormalization plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }


}












