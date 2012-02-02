#include "MuFakeRate.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
//#include "Gen.hh"
#include <fstream>
using namespace Event;
namespace SSDL {

  MuFakeRate::MuFakeRate(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName)
  {
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
  }

  void MuFakeRate::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }
  MuFakeRate::~MuFakeRate() {

  }

  void  MuFakeRate::BookHistos() {
    hAllMu= new TH2D("hAllMu","hAllMu",10,0,2.5,20,0,100);
    hGoodMu= new TH2D("hGoodMu","hGoodMu",10,0,2.5,20,0,100);  
  }

  bool MuFakeRate::Process(Event::Data & ev) {
 

    float HT=ev.CommonHT();
    float MHT=ev.PFMET().Pt();
    float w=ev.GetEventWeight();
 
   
    vector<Lepton> AllMuons;


 

    //SECONDARY LEPTONS
    


  
    for(vector<Lepton>::const_iterator lep=ev.LD_Muons().begin();
	lep!=ev.LD_Muons().end();++lep) {
      if (fabs(lep->Pt())<(Utils::GetConfig<double>("Common.Muons.PtCut"))) continue;
      if (fabs(lep->Eta())>(Utils::GetConfig<double>("Common.Muons.EtaCut"))) continue;
	//NOT PRIMARY LEPTONS
	//MUON ID CUTS
	int iM = lep->GetIndex();

	 
	if (ev.muonGlobalTracknumberOfValidHits()->at(iM)<=10) continue;
	if (!ev.muonIsGlobalMuon()->at(iM))continue;
	if (!ev.muonIsTrackerMuon()->at(iM)) continue;
 	if (ev.muonGlobalTrackNormChi2()->at(iM)>10.) continue;
	if (fabs(ev.muonInnerTrackdxyBS()->at(iM)>0.02)) continue;
	AllMuons.push_back(*lep);
    }
    
    bool DECISION=true;
    
    vector<bool> CUTS;
    

    //CUT LIST
    CUTS.push_back((AllMuons.size()>=1));
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    
    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);
    
    
    if (DECISION){
      bool tagjet=false;
      for (vector<Jet>::const_iterator ij=ev.JD_Jets().begin() ;
	   ij!=ev.JD_Jets().end(); ++ij){
	if (tagjet) continue;
	if (fabs((*ij).Eta())>2.4) continue;
	//here we hack in the bjet tagging - NOTE: this is only because we don't have Btag info in AK5PF jets
	//AGB 28/10/10
	double dr = 0.05;
	bool matchjet = false;
	Event::Jet const *match;
	for(vector<Jet>::const_iterator secjet=ev.JD_SecJets().begin(); secjet!=ev.JD_SecJets().end(); ++secjet){
	  if(KS_DeltaR(*ij, *secjet)<dr){
	      dr=KS_DeltaR(*ij, *secjet);
	      match = &*secjet;
	      matchjet = true;
	    }
	  else continue;
	}
	bool tag;
		if (matchjet){
		tag = (ev.GetSecJetBtagTrkCount(match->GetIndex())>1.7);
		}
	else{tag = false;}


	// if ((KS_DeltaR(AllMuons[0], (*ij))>1.0) && (ev.GetBtagTrkCount(ij->GetIndex())>1.7)) tagjet=true;
	//AGB 28/10/10 - The above line is what we really want when we have the necessary info in ntuples...
	//for the time being:

	if ((KS_DeltaR(AllMuons[0], (*ij))>1.0) && tag) tagjet=true;
	
      }
      if (tagjet){
	float max_LepPt = 100.;
	hAllMu->Fill(fabs(AllMuons[0].Eta()),min(AllMuons[0].Pt(),max_LepPt),w);

	//PRIMARY LEPTONS
	bool matched= false;
	for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
	    lep!=ev.LD_CommonMuons().accepted.end();++lep){
	  if (matched) continue;
	  if (KS_DeltaR(AllMuons[0], (**lep))<0.05) matched=true;
	}
	
	if (matched)  hGoodMu->Fill(fabs(AllMuons[0].Eta()),min(AllMuons[0].Pt(),max_LepPt),w);

      }


    }
    
    return DECISION; // Check for fails above, return false to fail operation.
  } // end of Process method

  std::ostream& MuFakeRate::Description(std::ostream &ostrm) {
    ostrm << "MuFakeRate plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }


}












