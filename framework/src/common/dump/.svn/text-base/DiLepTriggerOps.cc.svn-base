/*! \file ComTriggerOps.cc
 * \brief Source code for common object plotting operations.
 */
#include "DiLepTriggerOps.hh"
#include "EventData.hh"
#include "Jet.hh"

namespace Operation {
  //================================
  // Good Jet Trigger Operation
  //================================
  //
  DiLepTriggerTest::DiLepTriggerTest(TFile* outFile,
				     const std::string & folderName,
				     const std::string & triggerFile) {
    initDir(outFile,folderName.c_str());
    BookHistos();
   //  for (int i=0;i<6;i++){
//       char htn[20],htt[20];
//       sprintf(htn,"%s%d","h_ss_trig_ht_l1_",i);
//       h_ss_trig_ht_l1[i]= new TH1D(htn,htn,100, 0.,2000.);  
//       h_ss_trig_ht_l1[i]->SetDirectory(mydir);
//       sprintf(htt,"%s%d","h_ss_trig_ht_hlt_",i);
    
//       h_ss_trig_ht_hlt[i]= new TH1D(htt,htt,100, 0.,2000.);  
//       h_ss_trig_ht_hlt[i]->SetDirectory(mydir);

//       char mhtn[20],mhtt[20];
//       sprintf(mhtn,"%s%d","h_ss_trig_mht_l1_",i);
//       h_ss_trig_mht_l1[i]= new TH1D(mhtn,mhtn,100, 0.,2000.);  
//       h_ss_trig_mht_l1[i]->SetDirectory(mydir);
//       sprintf(mhtt,"%s%d","h_ss_trig_mht_hlt_",i);
//       h_ss_trig_mht_hlt[i]= new TH1D(mhtt,mhtt,100, 0.,2000.);  
//       h_ss_trig_mht_hlt[i]->SetDirectory(mydir);

//       char hden[20],hnum[20];
//       sprintf(hden,"%s%d","h_trig_den_pt_",i);
//       h_trig_den_pt[i]= new TH1D(hden,hden,25,0,50.);
//       h_trig_den_pt[i]->SetDirectory(mydir);
//       sprintf(hnum,"%s%d","h_trig_num_pt_",i);
//       h_trig_num_pt[i]= new TH1D(hnum,hnum,25,0,50.);
//       h_trig_num_pt[i]->SetDirectory(mydir);
//     }
    ControlCards * Config;
    Config = ControlCards::Instance();
    //Trigger for SameSign Dilepton Analysis
    std::vector<double> def;
    def.clear();
    Config->AddCardVector("SSTriggerPaths",def);
    Config->readKeys(triggerFile.c_str());
    SSTriggers =Config->fetchValueVector("SSTriggerPaths");

  } // end of DiLepTriggerTest constructor.

  DiLepTriggerTest::~DiLepTriggerTest() {
    // Write out the ROOT file.
  } // end of DiLepTriggerTest destructor.
  
  Double_t DiLepTriggerTest::CalcComHT(const std::vector<TLorentzVector const *> & vtv) {
    Double_t result = 0.0;
    for (std::vector<TLorentzVector const *>::const_iterator j = vtv.begin();
	 j != vtv.end();
	 ++j) {
      result  += (*j)->Pt();
    }
    return result;
  }

  void DiLepTriggerTest::CalcComMHT(const std::vector<TLorentzVector const *> & vtv,
				    TLorentzVector & res) {
    res.SetPxPyPzE(0.,0.,0.,0.);
    for (std::vector<TLorentzVector const *>::const_iterator j = vtv.begin();
	 j != vtv.end();
	 ++j) {
      res -= (**j);
    }
  }

  bool DiLepTriggerTest::Process(Event::Data & ev) {
    //MHT TRIGGER
    std::vector<TLorentzVector const *> L1;
    std::vector<TLorentzVector const *> HLT;

    float HTL1=0;
    float MHTL1=0;
    float HTHLT=0;
    float MHTHLT=0;

    for(std::vector<Event::Jet>::const_iterator j=ev.JD_Jets().begin();
	j!=ev.JD_Jets().end();
	++j ){
      // Hard coded?
      if (j->Pt()>20) L1.push_back(&*j);
      if (j->Pt()>30) HLT.push_back(&*j);
    }

    // GET THE FINAL STATE
    int ifs=-1;
    float minpt=0;
    if (ev.MC_Final().state>0){
      ifs=ev.MC_SSFinalState();
      int ij1=ev.MC_LeptonsTau()[0];
      int ij2=ev.MC_LeptonsTau()[1];
      float px1=ev.genPx()[ij1];
      float py1=ev.genPx()[ij1];
      float px2=ev.genPx()[ij2];
      float py2=ev.genPx()[ij2];
      minpt=sqrt(min((px1*px1+py1*py1),(px2*px2+py2*py2)));
    }
     
    TLorentzVector localComMHT;
    Double_t localComHT;
 
    localComHT = CalcComHT(L1);
    CalcComMHT(L1,
	       localComMHT);
    HTL1 = localComHT;
    MHTL1 = localComMHT.Pt();
    
    localComHT = CalcComHT(HLT);
    CalcComMHT(HLT,
	       localComMHT);
    HTHLT = localComHT;;
    MHTHLT = localComMHT.Pt();
    

    bool L1_HT=(HTL1>200);
    bool HLT_MHT = ((HTHLT>300)&&(MHTHLT>100));
    bool HLT_HT = (HTHLT>500);
    bool MHT=L1_HT && HLT_MHT;
    bool HT=L1_HT && HLT_HT;
    

    //All the trigger Paths passed via external file are  put in OR
    bool TrPassed =false;
    for (uint i=0; i<SSTriggers.size();i++){
      int tr=int(SSTriggers[i]);
      if (TrPassed) continue;
      if (tr>200) continue;
      //199 HT300_MHT100
      if (tr==199)	TrPassed=(MHT||TrPassed);
      //198 HT500
      if (tr==198) TrPassed=(HT||TrPassed);
      //Trigger paths already implemented in CMSSW_2_2_3
      if (tr<160)TrPassed=(TrPassed || ev.HLTArray()[int(SSTriggers[i])]);
    }

    
    h_trig_den_pt[6]->Fill(minpt);
    h_trig_den_HT[6]->Fill(HTHLT);
    if (TrPassed){
      h_trig_num_pt[6]->Fill(minpt);
      h_trig_num_HT[6]->Fill(HTHLT);
    }
    if (ifs>=0 &&ifs<6){
      h_trig_den_pt[ifs]->Fill(minpt);
      h_trig_den_HT[ifs]->Fill(HTHLT);
      if (TrPassed){
	h_trig_num_pt[ifs]->Fill(minpt);
	h_trig_num_HT[ifs]->Fill(HTHLT);
      }
    }
    
    return TrPassed;
  }
  //////////////////////////////
  void  DiLepTriggerTest::BookHistos(){
    BookHistArray(h_trig_den_pt,"h_trig_den_pt","h_trig_den_pt",10,0.,50.,dilepFinalStates+1,0,1,false);
    BookHistArray(h_trig_num_pt,"h_trig_num_pt","h_trig_num_pt",10,0.,50.,dilepFinalStates+1,0,1,false);
    BookHistArray(h_trig_den_HT,"h_trig_den_HT","h_trig_den_HT",100,0.,2000.,dilepFinalStates+1,0,1,false);
    BookHistArray(h_trig_num_HT,"h_trig_num_HT","h_trig_num_HT",100,0.,2000.,dilepFinalStates+1,0,1,false);
  }
  ///////////////////////////////
  std::ostream& DiLepTriggerTest::Description(std::ostream &ostrm) {
    ostrm << "DiLepTriggerTest plots made here: (histograms in ";
    ostrm << mFileName  << "/" << mFolderName << ")";
    return ostrm;
  }
} //~namespace Operation
  

