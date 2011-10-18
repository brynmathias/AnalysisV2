#include "WChSelect.hh"
#include "KinSuite.hh"
#include <fstream>
using namespace Event;

WChSelect::WChSelect(const std::string & folderName,
		     Utils::ParameterSet &pset
		     ):
  mFolderName(folderName)
{
  elecPt      = pset.Get<double>("ElecPtCut");
  fbremCut    = pset.Get<double>("FBremCut");
  metLowerCut = pset.Get<double>("METLowerCut");
  metUpperCut = pset.Get<double>("METUpperCut");
  mcAnal      = pset.Get<bool>("McAnal");
  useEcal     = pset.Get<bool>("UseEcal");
  chChk       = pset.Get<bool>("ChCheck");
}

void WChSelect::Start(Event::Data & ev) {
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
  
}
WChSelect::~WChSelect() {

}

void  WChSelect::BookHistos() {
  PosEta = new TH1D("PosEta","PosEta",6,-2.4,2.4);
  EleEta = new TH1D("EleEta","EleEta",6,-2.4,2.4); 
  McPosEta = new TH1D("McPosEta","McPosEta",6,-2.4,2.4);
  McEleEta = new TH1D("McEleEta","McEleEta",6,-2.4,2.4); 
  McPosEtaWC = new TH1D("McPosEtaWC","McPosEtaWC",6,-2.4,2.4);
  McEleEtaWC = new TH1D("McEleEtaWC","McEleEtaWC",6,-2.4,2.4); 
  fbremElw = new TH1D("fbremElw","fbremElw",50,0.,1.);
  fbremElg = new TH1D("fbremElg","fbremElg",50,0.,1.);  
  sigmaetaElg = new TH1D("sigmaetaElg","sigmaetaElg",50,0.,0.1);
  sigmaetaElw = new TH1D("sigmaetaElw","sigmaetaElw",50,0.,0.1); 
}

bool WChSelect::Process(Event::Data & ev) {

  float w=ev.GetEventWeight();



  uint ElSize=ev.LD_CommonElectrons().accepted.size();
  vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
  

  float leppt=(ElSize==1)     ?  (*lep)->Pt()        : 0;
  float lepeta=(ElSize==1)    ?  (*lep)->Eta()       : 5.;
  float lepcharge=(ElSize==1) ?  (*lep)->GetCharge() : 0;
  int lepindex=(ElSize==1) ? (*lep)->GetIndex() :-1;
  float fbrem = (ElSize==1) ? ev.GetElectronFbrem(lepindex) : 100;
  float geneta=100;
  float genpt=0;
  int genCharge=0;
  if (useEcal && lepindex>=0) 
    leppt*=(ev.GetElectronEcalEnergy(lepindex)/(*lep)->P());

  if (mcAnal){
  
    int elegen = (ElSize==1) ? ev.leptonMatch(const_cast<Lepton*>((*lep)),1) : -1;

    if (elegen>=0){ 
      Event::GenObject const * genEl=ev.MC_GenLeptons()[elegen];
      geneta=genEl->Eta();
      genpt=genEl->Pt();
      genCharge=(genEl->GetID()>0)? -1:1; 
    }
  }

  

  float met=ev.PFMET().Pt();
  bool DECISION=true;
  vector<bool> cuts;
  cuts.push_back(leppt>elecPt );
  cuts.push_back(met>metLowerCut );
  if (chChk) cuts.push_back(lepcharge==ev.GetElectronSCCharge(lepindex));
  if (chChk) cuts.push_back(lepcharge==ev.GetElectronKFCharge(lepindex));
  for (uint i = 0; i < cuts.size(); i++) 
    DECISION = DECISION && cuts[i];

  if (DECISION){
    if (fabs(lepeta)<0.7) lepeta=0.5;
    if (fabs(lepeta)>0.7 && fabs(lepeta)<1.44) lepeta=1.0;
    if (fabs(lepeta)>1.56 && fabs(lepeta)<2.5)  lepeta=2.0;

    if (lepcharge==1)  PosEta->Fill(lepeta,w);
    if (lepcharge==-1) EleEta->Fill(lepeta,w);
    if (mcAnal && genCharge!=0){
      if (lepcharge!=genCharge){
	fbremElw->Fill(ev.GetElectronFbrem(lepindex));
	sigmaetaElw->Fill(ev.GetElectronSigmaIetaIeta(lepindex));      
      }else{
	fbremElg->Fill(ev.GetElectronFbrem(lepindex));
	sigmaetaElg->Fill(ev.GetElectronSigmaIetaIeta(lepindex));	
      }

      if (genCharge==1){
	McPosEta->Fill(geneta,w);
	if (lepcharge==-1) McPosEtaWC->Fill(geneta,w);
      }
      if (genCharge==-1){
	McEleEta->Fill(geneta,w);
      	if (lepcharge==1) McEleEtaWC->Fill(geneta,w);
      }
    }
  }
  
  return DECISION; // Check for fails above, return false to fail operation.
} // end of Process method

std::ostream& WChSelect::Description(std::ostream &ostrm) {
  ostrm << "WChSelect plots made here: (histograms in ";
  ostrm << mFolderName << ")";
  return ostrm;
}















