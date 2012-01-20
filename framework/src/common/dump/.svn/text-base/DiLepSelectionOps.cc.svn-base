/*! \file ComTriggerOps.cc
 * \brief Source code for common object plotting operations.
 */
#include "DiLepSelectionOps.hh"
#include "KinSuite.hh"
#include "EventData.hh"
#include "Lepton.hh"
#include "Jet.hh"

namespace Operation {
  //================================
  // Good Jet Selection Operation
  //================================
  //
  DiLepSelectionTest::DiLepSelectionTest(TFile* outFile,
					 const std::string & folderName,
					 const std::string & selFile)  
  {
   
    initDir(outFile,folderName.c_str());
    BookHistos();

    ControlCards * Config;
    Config = ControlCards::Instance();
    Config->AddCardDouble("SSMHTCut",50);
    Config->AddCardDouble("SSHTCut",50);
    Config->AddCardInt("LeptonCut",1);
    Config->readKeys(selFile.c_str());
    mhtCut=Config->fetchValueDouble("SSMHTCut");
    htCut=Config->fetchValueDouble("SSHTCut");
    leptonCut=Config->fetchValueInt("LeptonCut");
  } // end of DiLepSelectionTest constructor.

  DiLepSelectionTest::~DiLepSelectionTest() {
    // Write out the ROOT file.
  } // end of DiLepSelectionTest destructor.

  bool DiLepSelectionTest::Process(Event::Data & ev) {
    float HT=ev.CommonHT();
    float MHT=ev.CommonMHT().Pt();
    float w=ev.GetEventWeight();
    uint NELEC=ev.LD_CommonElectrons().accepted.size();
    int chProd=-1;
    uint NMUON=ev.LD_CommonMuons().accepted.size();

    //uint NMUON=ev.ND.Nmuon;
    uint NTAUS=ev.LD_CommonTaus().accepted.size();
    //    uint NTAUS = ev.ND.Ntau;
    
    uint NJETS = ev.JD_CommonJets().accepted.size();
    
    std::vector<Event::Lepton const *> AllLeptons;
    for(vector<Event::Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
	lep!=ev.LD_CommonMuons().accepted.end();
	++lep){
      if (fabs((*lep)->Eta())>2.4) continue;
      bool ok=ev.MuonIsGlobalTight()[(*lep)->GetIndex()];
      //ISOLA
      //      if (ev.ND.MuonAllIso[lep->GetIndex()]>3.) ok=false;
      for (std::vector<Event::Jet const *>::const_iterator iJ = ev.JD_CommonJets().accepted.begin();
	   iJ != ev.JD_CommonJets().accepted.end();
	   ++iJ) {
	if (!ok) continue;
	if ((*iJ)->DeltaR(**lep)<0.2) ok=false;
      } 
      if (ok)
	AllLeptons.push_back(*lep);
    }
    for(vector<Event::Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();
	++lep){
      if (fabs((*lep)->Eta())>2.4) continue;
      bool ok=true;
      for (std::vector<Event::Jet const *>::const_iterator iJ =ev.JD_CommonJets().accepted.begin();
	   iJ != ev.JD_CommonJets().accepted.end();
	   ++iJ) {
	if (!ok) continue;
	if ((*iJ)->DeltaR(**lep)<0.2) ok=false;
      } 
      if (ok)
	AllLeptons.push_back(*lep);
    }
    for(vector<Event::Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
	lep!=ev.LD_CommonTaus().accepted.end();
	++lep){
      if (fabs((*lep)->Eta())>2.4) continue;
      AllLeptons.push_back(*lep);
    }
    
    sort(AllLeptons.begin(),
	 AllLeptons.end(),
	 KinSuite::PCompare);

    uint NLEPTONS=AllLeptons.size();
  
    
    float deltaR=-1;
    float alpha=1;
    float MInv=-10;
    float deltaphi=200;

    float E1=-1;
    float E2=-1;
    float DrMHTLep=-1;
    std::vector<TVector3> particles;
        if (AllLeptons.size()>1){
      chProd=int(AllLeptons[0]->GetCharge()*AllLeptons[1]->GetCharge());
      MInv=(*AllLeptons[0]+*AllLeptons[1]).M();
      alpha=AllLeptons[1]->Pt()/MInv;
      deltaphi=AllLeptons[0]->DeltaPhi(*AllLeptons[1]);
      deltaR=AllLeptons[0]->DeltaR(*AllLeptons[1]);
      if (MHT>0) DrMHTLep=AllLeptons[0]->DeltaR(ev.CommonMHT());
    }
    if (NJETS>1){
      E1=ev.JD_CommonJets().accepted[0]->E();
      E2=ev.JD_CommonJets().accepted[1]->E();
    }
    //    cout<<"CICCE" <<ev.ComObs.size()<<" "<<E1<<" "<<E2<<" "<<deltaphi<<" "<<St<<endl;
  
    vector<bool> CUTS;
    CUTS.push_back((NLEPTONS>leptonCut));
    CUTS.push_back((chProd>0));
    CUTS.push_back((HT>htCut));


    bool DECISION=true;
    //SAME SIGN ELECTRONS
    
    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);
    h_bc_MHT->Fill(MHT,w);
    h_bc_HT->Fill(HT,w);
    h_bc_Charge->Fill(chProd,w);
    h_bc_lept->Fill(NLEPTONS,w);
    h_bc_Alpha->Fill(alpha,w);
    if (chProd>0) chProd=1;
    else chProd=-1;
    if (CUTS[2])              h_ss_NLEPTON->Fill(NLEPTONS,w); //NLEPTON 
    if (CUTS[0]&&CUTS[2])     h_Charge->Fill(chProd,w);  //CH prod
    if (CUTS[1]&&CUTS[0]) {
      h_ss_HT->Fill(HT,w); //HT
      h_ss_Alpha->Fill(alpha,w);
    }

 
    if (DECISION){
      h_ac_Alpha->Fill(alpha,w);
      //      h_bc_St->Fill(St,w);
      int REC_STATE=-1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==1) REC_STATE=0;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==4) REC_STATE=1;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==9) REC_STATE=2;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==2) REC_STATE=3;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==3) REC_STATE=4;
      if (AllLeptons[0]->GetType()*AllLeptons[1]->GetType()==6) REC_STATE=5;
      h_ss_MHT->Fill(MHT,w);
      h_ss_NTAU->Fill(NTAUS,w);
      h_ss_NELEC->Fill(NELEC,w);
      h_ss_NMUON->Fill(NMUON,w);
      h_deltaphi->Fill(deltaphi,w);
      h_enSecJet->Fill(E2,w);
      h_DrMHTLep->Fill(DrMHTLep,w);
      h_ss_ht[REC_STATE]->Fill(HT,w);
      h_ss_mht[REC_STATE]->Fill(MHT,w);
    }
    
    return DECISION;
  }
  void  DiLepSelectionTest::BookHistos(){
    h_ss_HT= new TH1D("h_HT","h_HT",40, 0.,2000.); 
    h_ss_MHT= new TH1D("h_MHT","h_MHT",50, 0.,1500.); 
    h_bc_MHT= new TH1D("h_bc_MHT","h_bc_MHT",50, 0.,1500.); 
    h_ss_NTAU=new TH1D("h_NTAU","h_NTAU",20,0,20);
    h_ss_NMUON=new TH1D("h_NMUON","h_NMUON",20,0,20);
    h_ss_NELEC=new TH1D("h_NELEC","h_NELEC",20,0,20);
    h_ss_NLEPTON=new TH1D("h_NLEPTON","h_NLEPTON",20,0,20);
    h_ss_NJET=new TH1D("h_NJET","h_NJET",20,0,20);
    h_deltaphi = new TH1D("h_Dphi","h_Dphi",60,-3.15,3.15); 
    h_St =new TH1D("h_St","h_St",50,0.,1.);
    h_enFirstJet=new TH1D("h_en1jet","h_en1jet",50,0,750.);
    h_enSecJet=new TH1D("h_en2jet","h_en2jet",50,0,500.);
    h_DrMHTLep=new TH1D("h_DrMHTLep","h_DrMHTLep",50,0,5.);
    h_Charge = new TH1D("h_Charge","h_Charge",2,-2,2);
    h_bc_Charge= new TH1D("h_bc_Charge","h_bc_Charge",2,-2,2);
    h_bc_HT = new TH1D("h_bc_HT","h_bc_HT",40, 0.,2000.);
    h_bc_St = new TH1D("h_bc_St","h_bc_St",50,0.,1.);
    h_bc_lept = new TH1D("h_bc_NLEPTON","h_bc_NLEPTON",20,0,20);
    h_bc_Alpha = new TH1D("h_bc_Alpha","h_bc_Alpha",40,0,4);
    h_ac_Alpha = new TH1D("h_ac_Alpha","h_ac_Alpha",40,0,4);
    h_ss_Alpha = new TH1D("h_ss_Alpha","h_ss_Alpha",40,0,4);
    BookHistArray(h_ss_ht,"h_ss_ht","h_ss_ht",100,0.,2000.,dilepFinalStates,0,1,false);
    BookHistArray(h_ss_mht,"h_ss_mht","h_ss_mht",100,0.,2000.,dilepFinalStates,0,1,false);
  }
  std::ostream& DiLepSelectionTest::Description(std::ostream &ostrm) {
    ostrm << "DiLepSelectionTest plots made here: (histograms in ";
    ostrm << mFileName  << "/" << mFolderName << ")";
    return ostrm;
  }
} //~namespace Operation
  

