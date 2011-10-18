#include "EventNoDump.hh"
namespace WPol {
// for the cc file

  EventNoDump::EventNoDump(const std::string & folderName,std::string TreeName):mFolderName(folderName),mTreeName(TreeName){}
  EventNoDump::~EventNoDump(){}
  void EventNoDump::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }
  void EventNoDump::BookHistos() {
    
    mTree = new TTree(TString(mTreeName),TString(mTreeName));
    mTree->Branch("LS",&LS,"LS/I");
    mTree->Branch("Run",&Run,"Run/I");
    mTree->Branch("Event",&Event,"Event/I");
    mTree->Branch("EEdPhi",&EEdPhi,"EEdPhi/F");
    mTree->Branch("EEdEta",&EEdEta,"EEdEta/F");
    mTree->Branch("EBdPhi",&EBdPhi,"EBdPhi/F");
    mTree->Branch("EBdEta",&EBdEta,"EBdEta/F");
    mTree->Branch("Eta",&Eta,"Eta/F");
    mTree->Branch("Pt",&Pt,"Pt/F");
    mTree->Branch("Phi",&Phi,"Phi/F");
    mTree->Branch("Charge",&Charge,"Charge/I");
    mTree->Branch("PFMETPT",&PFMETPT,"PFMETPT/F");
    mTree->Branch("PFMETPhi",&PFMETPhi,"PFMETPhi/F");
    mTree->Branch("WPT",&WPT,"WPT/F");
    mTree->Branch("WPTraw",&WPTraw,"WPTraw/F");
    mTree->Branch("WPhiraw",&WPhiraw,"WPhiraw/F");
    mTree->Branch("WPhi",&WPhi,"WPhi/F");
    mTree->Branch("Ptraw",&Ptraw,"Ptraw/F");


    mTree->Branch("Mhit",&Mhit,"Mhit/I");
    mTree->Branch("ElectronDCot",&ElectronDCot,"ElectronDCot/F");
    mTree->Branch("GetElectronDist",&GetElectronDist,"GetElectronDist/F");
    mTree->Branch("LP",&LP,"GetElectronDist/F");
    mTree->Branch("LPraw",&LPraw,"LPraw/F");
    mTree->Branch("VertexNo",&VertexNo,"VertexNo/I");




  }

    bool EventNoDump::Process(Event::Data & ev) {
     
    //  ev.PrintStableVisRec();
    //  ev.PrintStableVisAllRec();
    //  ev.PrintGen();

    Run = ev.RunNumber();
    Event = ev.EventNumber();
    LS = ev.LumiSection();

    PFMETPT=ev.PFMET().Pt();
    PFMETPhi=ev.PFMET().Phi();
    VertexNo = ev.GetVertexSize();
  
    const std::vector<const Event::Lepton*> & common_leps=ev.LD_CommonElectrons().accepted;
    if(ev.LD_CommonElectrons().accepted.size()>0) 
      {

	const Event::Lepton* theEli = common_leps[0];
	int iM = theEli->GetIndex();

	LorentzV eliRaw = ev.electronP4()->at(iM);
	//std::vector<LorentzV> PFelis 
	Ptraw=eliRaw.Pt();

	//	  LorentzVeliPF

	LorentzV pfMET = ev.PFMET() + *(theEli);
	LorentzV pfMETrawEli = ev.PFMET() + eliRaw;

	WPTraw=pfMETrawEli.Pt();
	WPhiraw=pfMETrawEli.Phi();
	LP = ((theEli->Px() * pfMET.Px()) + (theEli->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());
	LPraw = ((theEli->Px() * pfMETrawEli.Px()) + (theEli->Py() * pfMETrawEli.Py())) / (pfMETrawEli.Pt() * pfMETrawEli.Pt());

	WPT=pfMET.Pt();
	WPhi=pfMET.Phi();


	Eta=theEli->Eta();
	Pt=theEli->Pt();
	Phi=theEli->Phi();
	Charge=(int)theEli->GetCharge();
	
	if (fabs(theEli->Eta()) < 1.4442)
	  {
	    EBdPhi=ev.GetElectronDeltaPhiAtVtx(iM);
	    EBdEta=ev.GetElectronDeltaEtaAtVtx(iM);
	  }
	
	else if (fabs(theEli->Eta()) > 1.560 )
	  {
	    EEdEta=ev.GetElectronDeltaEtaAtVtx(iM);
	    EEdPhi=ev.GetElectronDeltaPhiAtVtx(iM);
	  }
     
     
	GetElectronDist=ev.GetElectronDist(iM);
	ElectronDCot=ev.GetElectronDCot(iM);
	Mhit=ev.GetElectronGsfTrackTrackerExpectedHitsInner(iM);


      }
    
    else
      {
	 Pt=-999;
	 /* Eta=-999;
	 Phi=-999;
	 Charge=-999;
	 EBdPhi=-999;
	 EEdEta=-999;
	 EBdPhi=-999;
	 EBdEta=-999;*/
      }
    
    mTree->Fill();
    return true;
 }

std::ostream&   EventNoDump::Description(std::ostream &ostrm) {
   ostrm<<"Dumping events to Tree: " <<  mTreeName << std::endl;  
   return ostrm;
 }
}
