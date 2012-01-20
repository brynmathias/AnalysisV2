#include "ElectronFakeRate.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
#include "Utils.hh"
//#include "Gen.hh"
#include <fstream>
using namespace Event;
namespace SSDL {

  ElectronFakeRate::ElectronFakeRate(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName)
  {
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
    upperMetCut=pset.Get<double>("UpperMetCut");
  }

  void ElectronFakeRate::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }
  ElectronFakeRate::~ElectronFakeRate() {

  }

  void  ElectronFakeRate::BookHistos() {
    hAllEl= new TH2D("hAllEl","hAllEl",10,0,2.5,20,0,100);
    hGoodEl= new TH2D("hGoodEl","hGoodEl",10,0,2.5,20,0,100);
  }

  bool ElectronFakeRate::Process(Event::Data & ev) {
 

    float HT=ev.CommonHT();
    float MHT=ev.PFMET().Pt();
    float w=ev.GetEventWeight();
 
 

    //SECONDARY LEPTONS

    vector<Lepton> AllElectrons;
    for(vector<Lepton>::const_iterator lep=ev.LD_Electrons().begin();
	lep!=ev.LD_Electrons().end();++lep) {
      if (fabs(lep->Eta())>2.4) continue;  
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
      
      AllElectrons.push_back(*lep);
    }
    
    
    
    
    bool DECISION=true;
    
    vector<bool> CUTS;
    
    //CUT LIST
    CUTS.push_back((AllElectrons.size()==1));
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);
    CUTS.push_back(ev.PFMET().Pt()<upperMetCut);

    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);
    


    //EVALUATE THE EFFICIENCY
    if (DECISION){
      float max_ElPt = 100.;
      for(vector<Lepton>::const_iterator lep=AllElectrons.begin();
	  lep!=AllElectrons.end();++lep) {
	if (fabs(lep->Pt())<(Utils::GetConfig<double>("Common.Electrons.PtCut"))) continue;
	if (fabs(lep->Eta())>(Utils::GetConfig<double>("Common.Electrons.EtaCut"))) continue;
	
	hAllEl->Fill(fabs(lep->Eta()),min(lep->Pt(),max_ElPt),w);

	bool matched= false;
	for(vector<Lepton const *>::const_iterator goodLep=ev.LD_CommonElectrons().accepted.begin();
	    goodLep!=ev.LD_CommonElectrons().accepted.end();++goodLep){
	  if (matched) continue;
	  if (KS_DeltaR(AllElectrons[0], (**goodLep))<0.05) matched=true;

	}
	if (matched)  hGoodEl->Fill(fabs(lep->Eta()),min(lep->Pt(),max_ElPt),w);

      }
    }
    
    return DECISION; // Check for fails above, return false to fail operation.
  } // end of Process method
  
  std::ostream& ElectronFakeRate::Description(std::ostream &ostrm) {
    ostrm << "ElectronFakeRate plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }


}












