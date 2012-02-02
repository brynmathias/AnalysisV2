#include "ANplots.hh"
#include "ThrustStuff.hh"
#include "GenObject.hh"
#include "GenMatrixBin.hh"
#include "Math/VectorUtil.h"
#include "ThrustStuff.hh"
using namespace Operation;

ANplots::ANplots(const std::string & folderName) :
  mFolderName(folderName)
{}

ANplots::~ANplots() {}

void ANplots::Start(Event::Data & ev) {
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
}

void ANplots::BookHistos() {
  TH1::SetDefaultSumw2(kTRUE);
  ZmassmuRaw = new TH1D("Zmass",";Z mass GeV;",200,0,400); 
  Zmassmu = new TH1D("ZmassoppSign",";Z mass GeV;",200,0,400); 
  Zmassmu_pos = new TH1D("ZmassoppSign_pos",";Z mass GeV;",200,0,400); 
  Zmassmu_neg = new TH1D("ZmassoppSign_neg",";Z mass GeV;",200,0,400); 
  
  ZLP = new TH1D("ZLP","ZLP",80,-2,2); 
  ZLP_pos = new TH1D("ZLP_pos","ZLP_pos",80,-2,2); 
  ZLP_neg = new TH1D("ZLP_neg","ZLP_neg",80,-2,2); 
  
  ZLPMHT= new TH1D("ZLPMHT","ZLPMHT",80,-2,2);
  ZLPMHT_pos = new TH1D("ZLPMHT_pos","ZLPMHT_pos",80,-2,2);
  ZLPMHT_neg= new TH1D("ZLPMHT_neg","ZLPMHT_neg",80,-2,2);

  ZLPvsLP = new TH2D("ZLPvsLP",";LP(Z);LP(MH_{T})",80,-2,2,80,-2,2);  
  ZPT  = new TH1D("ZPT",";P_{T}(Z);",200,0,1000); 
  ZPT_pos  = new TH1D("ZPT_pos",";P_{T}(Z);",200,0,1000); 
  ZPT_neg  = new TH1D("ZPT_neg",";P_{T}(Z);",200,0,1000); 
  
  ZPTres = new TH1D("ZPTres",";(P_{T}(Z)-MH_{T})/P_{T}(Z);",160,-2,2); 
  ZPTres_pos  = new TH1D("ZPTres_pos ",";(P_{T}(Z)-MH_{T})/P_{T}(Z);",160,-2,2); 
  ZPTres_neg = new TH1D("ZPTres_neg",";(P_{T}(Z)-MH_{T})/P_{T}(Z);",160,-2,2); 
  
  ZPTvsMHT= new TH2D("ZPTvsMHT",";P_{T}(Z);MH_{T}",50,0.,400.,50,0.,400.); 
  ZMHTpl  = new TH1D("ZMHTpl",";MHT(Z);",200,0,1000); 
  ZMHTpl_pos  = new TH1D("ZMHTpl_pos",";MHT(Z);",200,0,1000); 
  ZMHTpl_neg  = new TH1D("ZMHTpl_neg",";MHT(Z);",200,0,1000); 
  
  ZST  = new TH1D("ZST",";ZST;",200,0,1000); 
  
  CounterCtrl_pos = new TH1D("CounterCtrl_pos","Ctrl Region Events [+]",1,-1,1);
  CounterCtrl_neg = new TH1D("CounterCtrl_neg","Ctrl Region Events [-]",1,-1,1);
  CounterCtrl_tot = new TH1D("CounterCtrl_tot","Ctrl Region Events [+and-]",1,-1,1);
  
  CounterSgnl_pos = new TH1D("CounterSgnl_pos","Sgnl Region Events [+]",1,-1,1);
  CounterSgnl_neg = new TH1D("CounterSgnl_neg","Sgnl Region Events [-]",1,-1,1);
  CounterSgnl_tot = new TH1D("CounterSgnl_tot","Sgnl Region Events [+and-]",1,-1,1);
  
  LPctrl_pos = new TH1D("LPctrl_pos",";L_{P}[+] (ctrl);",450,0.3,2.1);
  LPctrl_neg = new TH1D("LPctrl_neg",";L_{P}[-] (ctrl);",450,0.3,2.1);
  LPctrl_tot = new TH1D("LPctrl_tot",";L_{P} (ctrl);",450,0.3,2.1);
  
  LPsig_pos = new TH1D("LPsig_pos",";L_{P}[+] (sig);",400,-0.65,0.15);
  LPsig_neg = new TH1D("LPsig_neg",";L_{P}[-] (sig);",400,-0.65,0.15);
  LPsig_tot = new TH1D("LPsig_tot",";L_{P} (sig);",400,-0.65,0.15);
  
  LP_pos = new TH1D("LP_pos",";L_{P}[+];",168,-2.1,2.1);
  LP_neg = new TH1D("LP_neg",";L_{P}[-];",168,-2.1,2.1);
  LP_tot = new TH1D("LP_tot",";L_{P};",168,-2.1,2.1);
  
  LPmht_pos = new TH1D("LPmht_pos",";L_{P}[+];",168,-2.1,2.1);
  LPmht_neg = new TH1D("LPmht_neg",";L_{P}[-];",168,-2.1,2.1);
  LPmht_tot = new TH1D("LPmht_tot",";L_{P};",168,-2.1,2.1);
  
  LPfit_tot = new TH1D("LPfit_tot",";L_{P};",21,-2.1,2.1);
  
  MT_pos = new TH1D("MT_pos",";M_{T}^{+} [GeV];",1000,0,2000);
  MT_neg = new TH1D("MT_neg",";M_{T}^{-} [GeV];",1000,0,2000);
  MT_tot = new TH1D("MT_tot",";M_{T} [GeV];",1000,0,2000);
  
  SumLepPt_pos = new TH1D("SumLepPt_pos",";ME_{T}+p_{T}[lep]^{+} [GeV];",1000,0,2000);
  SumLepPt_neg = new TH1D("SumLepPt_neg",";ME_{T}+p_{T}[lep]^{-} [GeV];",1000,0,2000);
  SumLepPt_tot = new TH1D("SumLepPt_tot",";ME_{T}+p_{T}[lep] [GeV];",1000,0,2000);
  
  LepPt_pos = new TH1D("LepPt_pos",";p_{T}[lep]^{+} [GeV];",1000,20,2000);
  LepPt_neg = new TH1D("LepPt_neg",";p_{T}[lep]^{-} [GeV];",1000,20,2000);
  LepPt_tot = new TH1D("LepPt_tot",";p_{T}[lep] [GeV];",1000,20,2000);
  
  LepEta_pos = new TH1D("LepEta_pos",";#eta[lep]^{+};",180,-6.,6.);
  LepEta_neg = new TH1D("LepEta_neg",";#eta[lep]^{-};",180,-6.,6.);
  LepEta_tot = new TH1D("LepEta_tot",";#eta[lep];",180,-6.,6.);
  
  LepPhi_pos = new TH1D("LepPhi_pos",";#phi[lep]^{+};",160,-TMath::Pi(),TMath::Pi());
  LepPhi_neg = new TH1D("LepPhi_neg",";#phi[lep]^{-};",160,-TMath::Pi(),TMath::Pi());
  LepPhi_tot = new TH1D("LepPhi_tot",";#phi[lep];",160,-TMath::Pi(),TMath::Pi());
  
  PFMET_pos = new TH1D("PFMET_pos",";ME_{T}^{+} [GeV];",1000,0,2000);
  PFMET_neg = new TH1D("PFMET_neg",";ME_{T}^{-} [GeV];",1000,0,2000);
  PFMET_tot = new TH1D("PFMET_tot",";ME_{T} [GeV];",1000,0,2000);
  
  PFMHT_pos = new TH1D("PFMHT_pos",";MH_{T}^{+} [GeV];",1000,0,2000);
  PFMHT_neg = new TH1D("PFMHT_neg",";MH_{T}^{-} [GeV];",1000,0,2000);
  PFMHT_tot = new TH1D("PFMHT_tot",";MH_{T} [GeV];",1000,0,2000);
  
  HT_pos = new TH1D("HT_pos",";H_{T}^{+} [GeV];",80,0,2000);
  HT_neg = new TH1D("HT_neg",";H_{T}^{-} [GeV];",80,0,2000);
  HT_tot = new TH1D("HT_tot",";H_{T} [GeV];",80,0,2000);
  //HT_tot_thru = new TH1D("HT_tot_thru",";H_{T} [GeV];",80,0,2000);
  
  MHT_pos = new TH1D("MHT_pos",";MH_{T}^{+} [GeV];",1000,0,2000);
  MHT_neg = new TH1D("MHT_neg",";MH_{T}^{-} [GeV];",1000,0,2000);
  MHT_tot = new TH1D("MHT_tot",";MH_{T} [GeV];",1000,0,2000);

  NrOfJets_tot = new TH1D("NrOfJets_tot", "Number of jets", 10,0.5,10.5);
  NrOfJets_pos = new TH1D("NrOfJets_pos", "Number of jets", 10,0.5,10.5);
  NrOfJets_neg = new TH1D("NrOfJets_neg", "Number of jets", 10,0.5,10.5);

  LepEtaPhi_pos = new TH2D("LepEtaPhi_pos",";#eta;#phi[lep]^{+}",24,-3.,3.,24,-TMath::Pi(),TMath::Pi());
  LepEtaPhi_neg = new TH2D("LepEtaPhi_neg",";#eta;#phi[lep]^{-}",24,-3.,3.,24,-TMath::Pi(),TMath::Pi());
  LepEtaPhi_tot = new TH2D("LepEtaPhi_tot",";#eta;#phi ",24,-3.,3.,24,-TMath::Pi(),TMath::Pi());
  
  DeltaPhiMuJ_pos = new TH1D("DeltaPhiMuJ_pos", "<Mu,Jet> #Delta #phi^{+}",120,0,TMath::Pi()*2);
  DeltaPhiMuJ_neg = new TH1D("DeltaPhiMuJ_neg", "<Mu,Jet> #Delta #phi^{-}",120,0,TMath::Pi()*2);
  DeltaPhiMuJ_tot = new TH1D("DeltaPhiMuJ_tot", "<Mu,Jet> #Delta #phi",120,0,TMath::Pi()*2);

  DeltaPhiMETJ_pos = new TH1D("DeltaPhiMETJ_pos", "<MET,Jet>#Delta #phi^{+}",120,0,TMath::Pi()*2);
  DeltaPhiMETJ_neg = new TH1D("DeltaPhiMETJ_neg", "<MET,Jet>#Delta #phi^{-}",120,0,TMath::Pi()*2);
  DeltaPhiMETJ_tot = new TH1D("DeltaPhiMETJ_tot", "<MET,Jet>#Delta #phi",120,0,TMath::Pi()*2);
    
  DeltaPhiMuWPT_pos = new TH1D("DeltaPhiMuWPT_pos", "<#mu,WPT>#Delta #phi^{+}",120,0,TMath::Pi());
  DeltaPhiMuWPT_neg = new TH1D("DeltaPhiMuWPT_neg", "<#mu,WPT>#Delta #phi^{-}",120,0,TMath::Pi());
  DeltaPhiMuWPT_tot = new TH1D("DeltaPhiMuWPT_tot", "<#mu,WPT>#Delta #phi",120,0,TMath::Pi());

  LPTvsPFMET_pos = new TH2D("LPTvsPFMET_pos",";LPT;MET^{+}",100,20.,1000.,100,0,1000); 
  LPTvsPFMET_neg  = new TH2D("LPTvsPFMET_neg",";LPT;MET^{-}",100,20.,1000.,100,0,1000);
  LPTvsPFMET_tot  = new TH2D("LPTvsPFMET_tot",";LPT;MET",100,20.,1000.,100,0,1000); 

  LepPtvsLP_pos = new TH2D("LepPtvsLP_pos","LepPtvsLP_pos",168,-2.1,2.1,100,0.,1000.);
  LepPtvsLP_neg = new TH2D("LepPtvsLP_neg","LepPtvsLP_neg",168,-2.1,2.1,100,0.,1000.);
  LepPtvsLP_tot = new TH2D("LepPtvsLP_tot","LepPtvsLP_tot",168,-2.1,2.1,100,0.,1000.);

  PFMETvsLP_pos = new TH2D("PFMETvsLP_pos","PFMETvsLP_pos",168,-2.1,2.1,200,0.,1000.);
  PFMETvsLP_neg = new TH2D("PFMETvsLP_neg","PFMETvsLP_neg",168,-2.1,2.1,200,0.,1000.);
  PFMETvsLP_tot = new TH2D("PFMETvsLP_tot","PFMETvsLP_tot",168,-2.1,2.1,200,0.,1000.);

  WPTvsST_pos= new TH2D("WPTvsST_pos",";WPT;ST^{+}",200,0.,1000.,200,0,1000); 
  WPTvsST_neg = new TH2D("WPTvsST_neg",";WPT;ST^{-}",200,0.,1000.,200,0,1000); 
  WPTvsST_tot = new TH2D("WPTvsST_tot",";WPT;ST",200,0.,1000.,200,0,1000); 
  
  PFMETtypeIvsLepPt_pos = new TH2D("PFMETtypeIvsLepPt_pos","; p_{T}[lep]^{+} ;ME_{T};",50,0,2000,50,0,2000);
  PFMETtypeIvsLepPt_neg = new TH2D("PFMETtypeIvsLepPt_neg","; p_{T}[lep]^{-} ;ME_{T};",50,0,2000,50,0,2000);
  PFMETtypeIvsLepPt_tot = new TH2D("PFMETtypeIvsLepPt_tot","; p_{T}[lep] ;ME_{T};",50,0,2000,50,0,2000);

  //PFMETtypeIvsLepPt_pos = new TH2D("PFMETtypeIvsLepPt_pos","; p_{T}[lep]^{+} ;ME_{T};",500,0,2000,500,0,2000);
  //  PFMETtypeIvsLepPt_neg = new TH2D("PFMETtypeIvsLepPt_neg","; p_{T}[lep]^{-} ;ME_{T};",500,0,2000,500,0,2000);
  STHT_tot = new TH2D("STHT_tot","; S_{T}[lep] ;HT;",50,0,2500,50,0,2500);


  //Thrust = new TH1D("Thrust",";Thrust;",100,0,1);
  //ThrustPhi = new TH1D("ThrustPhi",";ThrustPhi;",100,0,TMath::Pi());

  PFMETtypeVSPFMET = new TH2D("PFMETtypeVSPFMET",";PFMet typeI;PFMet;",100,0,2000,100,0,2000);

  //HTthrust = new TH2D("HTthrust",";HT [GeV];Thrust;",40,0,2000,20,0,1);
  PFMETtypeOVPFMET = new TH1D("PFMETtypeOVPFMET",";PFMet typeI/PFMet;",200,0,2);

  MT_lt03_tot = new TH1D("MT_lt03_tot",";M_{T} [GeV];",1000,0,2000);
  MT_gt03_tot = new TH1D("MT_gt03_tot",";M_{T} [GeV];",1000,0,2000);

  JetCorFactor = new TH1D("JetCorFactor","JetCorFactor",1000,0.,10.);
  JetCorFactorB = new TH1D("JetCorFactorB","JetCorFactorB",1000,0.,10.);

  RelCombIso_pos = new TH1D("RelCombIso_pos","RelCombIso_pos",1000,0.,2.);
  RelCombIso_neg = new TH1D("RelCombIso_neg","RelCombIso_neg",1000,0.,2.);
  RelCombIso_tot = new TH1D("RelCombIso_tot","RelCombIso_tot",1000,0.,2.);


  // Slavas's plots
  LPf_tot    = new TH1D("LPf_tot",";L_{P};",28,-2.1,2.1);
  MTf_tot    = new TH1D("MTf_tot",";M_{T} [GeV];",100,0.,1000.);
  STf_tot    = new TH1D("STf_tot",";S_{T}^{lep} [GeV];",20,0.,1000.);
  LepPtf_tot = new TH1D("LepPtf_tot",";p_{T}(lep) [GeV];",50,0.,1000.);


}



bool ANplots::Process(Event::Data & ev) {

  // check if there is a muon or electron  
  std::vector <Event::Lepton const *> theRECOLepton;
  bool isMu = false;

  if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()==0) ) {
    theRECOLepton = ev.LD_CommonMuons().accepted;
    isMu = true;
  }
  
  if ( (ev.LD_CommonMuons().accepted.size()==0) && (ev.LD_CommonElectrons().accepted.size()>0) ) {
    theRECOLepton = ev.LD_CommonElectrons().accepted;
  }  
  if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()>0) ) {
    //  cout << "WARNING: ANplots has common muon AND Electron, it does not know what to plot!!!"<<endl;
    return true;
  }
  
  if (theRECOLepton.size()==0){
    // cout << "  ANplots does require at least one lepton: plots not filled "<<endl;
    return true;
  } 


  
  // define variables
  LorentzV pfMHT = ev.PFMET() + *(theRECOLepton.at(0));
  double LP = ((theRECOLepton.at(0)->Px() * pfMHT.Px()) + (theRECOLepton.at(0)->Py() * pfMHT.Py())) / (pfMHT.Pt() * pfMHT.Pt());
  double LPmht = ((theRECOLepton.at(0)->Px() * ev.CommonMHT().Px()) + (theRECOLepton.at(0)->Py() * ev.CommonMHT().Py())) / (ev.CommonMHT().Pt() * ev.CommonMHT().Pt());
  double SumLepPt = ev.PFMET().Pt() + theRECOLepton.at(0)->Pt();
  double pfMT =  sqrt(2.0 * ev.PFMET().Pt() * (theRECOLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), ev.PFMET() ) )));
  float minDeltaPhiMuJ = 2*TMath::Pi();
  for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
    float aminDeltaPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton.at(0))));
    if(aminDeltaPhi<minDeltaPhiMuJ) minDeltaPhiMuJ=aminDeltaPhi;
  }
  float minDeltaPhiMETJ = 2*TMath::Pi();
  for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
    float aminDeltaPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(*(ev.JD_CommonJets().accepted.at(i)),ev.PFMET()));
    if(aminDeltaPhi<minDeltaPhiMETJ) minDeltaPhiMETJ=aminDeltaPhi;
  }
  DeltaPhiMuWPT_tot->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*theRECOLepton.at(0),pfMHT)),ev.GetEventWeight());
  STHT_tot->Fill(SumLepPt,ev.CommonHT(),ev.GetEventWeight());

  // Fill histograms for positive leptons [+]
  if (theRECOLepton.at(0)->GetCharge()>0.) {

    LPTvsPFMET_pos->Fill((theRECOLepton.at(0)->Pt()),ev.PFMET().Pt(),ev.GetEventWeight());
    WPTvsST_pos->Fill(pfMHT.Pt(),SumLepPt,ev.GetEventWeight());
    LP_pos->Fill(LP,ev.GetEventWeight());
    LPmht_pos->Fill(LPmht,ev.GetEventWeight());
    DeltaPhiMuWPT_pos->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*theRECOLepton.at(0),pfMHT)),ev.GetEventWeight());

    if (LP>=0.3) { 
      LPctrl_pos->Fill(LP,ev.GetEventWeight());
      CounterCtrl_pos->Fill(0.,ev.GetEventWeight());
    }
    if (LP<=0.15) { 
      LPsig_pos->Fill(LP,ev.GetEventWeight()); 
      CounterSgnl_pos->Fill(0.,ev.GetEventWeight());
    }
    MT_pos->Fill(pfMT,ev.GetEventWeight());
    SumLepPt_pos->Fill(SumLepPt,ev.GetEventWeight());
    LepPt_pos->Fill((theRECOLepton.at(0)->Pt()),ev.GetEventWeight());
    LepEta_pos->Fill((theRECOLepton.at(0)->Eta()),ev.GetEventWeight());
    LepPhi_pos->Fill((theRECOLepton.at(0)->Phi()),ev.GetEventWeight());
    PFMET_pos->Fill(ev.PFMET().Pt(),ev.GetEventWeight());
    MHT_pos->Fill(ev.CommonMHT().Pt(),ev.GetEventWeight());
    PFMHT_pos->Fill(pfMHT.Pt(),ev.GetEventWeight());
    HT_pos->Fill(ev.CommonHT(),ev.GetEventWeight());
    LepEtaPhi_pos->Fill(theRECOLepton.at(0)->Eta(),theRECOLepton.at(0)->Phi(),ev.GetEventWeight());
    DeltaPhiMuJ_pos->Fill(minDeltaPhiMuJ,ev.GetEventWeight());
    DeltaPhiMETJ_pos->Fill(minDeltaPhiMETJ,ev.GetEventWeight());
    NrOfJets_pos->Fill(ev.JD_CommonJets().accepted.size(),ev.GetEventWeight());
    PFMETtypeIvsLepPt_pos->Fill(theRECOLepton.at(0)->Pt(),ev.metP4pfTypeI()->Pt(),ev.GetEventWeight());
    LepPtvsLP_pos->Fill(LP,ev.GetEventWeight(),ev.GetEventWeight());
    PFMETvsLP_pos->Fill(ev.PFMET().Pt(),ev.GetEventWeight(),ev.GetEventWeight());
    RelCombIso_pos->Fill((theRECOLepton.at(0)->GetCombIsolation()),ev.GetEventWeight());


  } // end of filling histograms for positively charged leptons [+]
  
  
  // Fill histograms for negative leptons [-]
  if (theRECOLepton.at(0)->GetCharge()<0.) {

    LPTvsPFMET_neg->Fill(theRECOLepton.at(0)->Pt(),ev.PFMET().Pt(),ev.GetEventWeight());
    WPTvsST_neg->Fill(pfMHT.Pt(),SumLepPt,ev.GetEventWeight());
    LP_neg->Fill(LP,ev.GetEventWeight());
    LPmht_neg->Fill(LPmht,ev.GetEventWeight());
    DeltaPhiMuWPT_neg->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi(*theRECOLepton.at(0),pfMHT)),ev.GetEventWeight());

    if (LP>=0.3) { 
      LPctrl_neg->Fill(LP,ev.GetEventWeight());
      CounterCtrl_neg->Fill(0.,ev.GetEventWeight());
    }
    if (LP<=0.15) { 
      LPsig_neg->Fill(LP,ev.GetEventWeight()); 
      CounterSgnl_neg->Fill(0.,ev.GetEventWeight());
    }
    MT_neg->Fill(pfMT,ev.GetEventWeight());
    SumLepPt_neg->Fill(SumLepPt,ev.GetEventWeight());
    LepPt_neg->Fill((theRECOLepton.at(0)->Pt()),ev.GetEventWeight());
    LepEta_neg->Fill((theRECOLepton.at(0)->Eta()),ev.GetEventWeight());
    LepPhi_neg->Fill((theRECOLepton.at(0)->Phi()),ev.GetEventWeight());
    PFMET_neg->Fill(ev.PFMET().Pt(),ev.GetEventWeight());
    PFMHT_neg->Fill(pfMHT.Pt(),ev.GetEventWeight());
    HT_neg->Fill(ev.CommonHT(),ev.GetEventWeight());
    MHT_neg->Fill(ev.CommonMHT().Pt(),ev.GetEventWeight());
    LepEtaPhi_neg->Fill(theRECOLepton.at(0)->Eta(),theRECOLepton.at(0)->Phi(),ev.GetEventWeight());
    DeltaPhiMuJ_neg->Fill(minDeltaPhiMuJ,ev.GetEventWeight());
    DeltaPhiMETJ_neg->Fill(minDeltaPhiMETJ,ev.GetEventWeight());
    NrOfJets_neg->Fill(ev.JD_CommonJets().accepted.size(),ev.GetEventWeight());
    PFMETtypeIvsLepPt_neg->Fill(theRECOLepton.at(0)->Pt(),ev.metP4pfTypeI()->Pt(),ev.GetEventWeight());
    LepPtvsLP_neg->Fill(LP,(theRECOLepton.at(0)->Pt()),ev.GetEventWeight());
    PFMETvsLP_neg->Fill(LP,ev.PFMET().Pt(),ev.GetEventWeight());
    RelCombIso_neg->Fill((theRECOLepton.at(0)->GetCombIsolation()),ev.GetEventWeight());

  } // end of filling histograms for negative leptons [-]
 

  // Fill histograms for [+] & [-]
  LPTvsPFMET_tot->Fill(theRECOLepton.at(0)->Pt(),ev.PFMET().Pt(),ev.GetEventWeight());
  WPTvsST_tot->Fill(pfMHT.Pt(),SumLepPt,ev.GetEventWeight());
  LP_tot->Fill(LP,ev.GetEventWeight());
  LPmht_tot->Fill(LPmht,ev.GetEventWeight());
  LPfit_tot->Fill(LP,ev.GetEventWeight());

  if (LP>=0.3) { 
    LPctrl_tot->Fill(LP,ev.GetEventWeight());
    CounterCtrl_tot->Fill(0.,ev.GetEventWeight());
  }
  if (LP<=0.15) { 
    LPsig_tot->Fill(LP,ev.GetEventWeight()); 
    CounterSgnl_tot->Fill(0.,ev.GetEventWeight());
  }
  MT_tot->Fill(pfMT,ev.GetEventWeight());
  SumLepPt_tot->Fill(SumLepPt,ev.GetEventWeight());
  LepPt_tot->Fill((theRECOLepton.at(0)->Pt()),ev.GetEventWeight());
  LepEta_tot->Fill((theRECOLepton.at(0)->Eta()),ev.GetEventWeight());
  LepPhi_tot->Fill((theRECOLepton.at(0)->Phi()),ev.GetEventWeight());
  PFMET_tot->Fill(ev.PFMET().Pt(),ev.GetEventWeight());
  PFMHT_tot->Fill(pfMHT.Pt(),ev.GetEventWeight());
  HT_tot->Fill(ev.CommonHT(),ev.GetEventWeight());
  MHT_tot->Fill(ev.CommonMHT().Pt(),ev.GetEventWeight());
  LepEtaPhi_tot->Fill(theRECOLepton.at(0)->Eta(),theRECOLepton.at(0)->Phi(),ev.GetEventWeight());
  NrOfJets_tot->Fill(ev.JD_CommonJets().accepted.size(),ev.GetEventWeight());
  DeltaPhiMuJ_tot->Fill(minDeltaPhiMuJ,ev.GetEventWeight());
  DeltaPhiMETJ_tot->Fill(minDeltaPhiMETJ,ev.GetEventWeight());
  PFMETtypeIvsLepPt_tot->Fill(theRECOLepton.at(0)->Pt(),ev.metP4pfTypeI()->Pt(),ev.GetEventWeight());
  LepPtvsLP_tot->Fill(LP,(theRECOLepton.at(0)->Pt()),ev.GetEventWeight());
  PFMETvsLP_tot->Fill(LP,ev.PFMET().Pt(),ev.GetEventWeight());

  PFMETtypeVSPFMET->Fill(ev.metP4pfTypeI()->Pt(),ev.metP4pf()->Pt(),ev.GetEventWeight());
  PFMETtypeOVPFMET->Fill(ev.metP4pfTypeI()->Pt()/ev.metP4pf()->Pt(),ev.GetEventWeight());

  LPf_tot->Fill(LP,ev.GetEventWeight());
  MTf_tot->Fill(pfMT,ev.GetEventWeight());
  STf_tot->Fill(SumLepPt,ev.GetEventWeight());
  LepPtf_tot->Fill((theRECOLepton.at(0)->Pt()),ev.GetEventWeight());


  if ( fabs((1.-ev.metP4pfTypeI()->Pt())/ev.metP4pf()->Pt())>0.3 ) { MT_gt03_tot->Fill(pfMT,ev.GetEventWeight()); }
  if ( fabs((1.-ev.metP4pfTypeI()->Pt())/ev.metP4pf()->Pt())<0.3 ) { MT_lt03_tot->Fill(pfMT,ev.GetEventWeight()); }  

  for ( std::vector<Event::Jet const *>::const_iterator iJ = ev.JD_CommonJets().accepted.begin();
	iJ != ev.JD_CommonJets().accepted.end();
	iJ++ ) {

    JetCorFactor->Fill(ev.GetJetCorrFactor((*iJ)->GetIndex()),ev.GetEventWeight());
    JetCorFactorB->Fill(ev.jetCorrFactor()->at((*iJ)->GetIndex()),ev.GetEventWeight());

  }

  //  ThrustStuff thrust = ev.CommonThrustStuff();
  //  Thrust->Fill(1-(thrust.HTFmin/thrust.HTFmax),ev.GetEventWeight());
  //ThrustPhi->Fill(thrust.pjetDphi,ev.GetEventWeight());
  //HTthrust->Fill(ev.CommonHT(),1-(thrust.HTFmin/thrust.HTFmax),ev.GetEventWeight());
  // HT_tot_thru ->Fill(thrust.HTFmin,ev.GetEventWeight());
  //  ev.PrintGen();->Fill(ev.CommonHT(),1-(thrust.HTFmin/thrust.HTFmax),ev.GetEventWeight());

 RelCombIso_tot->Fill((theRECOLepton.at(0)->GetCombIsolation()),ev.GetEventWeight());



  if(theRECOLepton.size()==2)
    {
      ZmassmuRaw->Fill(ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1))) ,ev.GetEventWeight());

      if(theRECOLepton.at(0)->GetCharge()!=theRECOLepton.at(1)->GetCharge())
	{
	  Zmassmu->Fill(   ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1))) ,ev.GetEventWeight());
	  if( ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1)))>76  &&   ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1)))<107 )
	    {
	      LorentzV ZMHT = ev.PFMET() + *(theRECOLepton.at(0))+ *(theRECOLepton.at(1));
	      LorentzV theZ = (*theRECOLepton.at(0))+(*theRECOLepton.at(1));
	      float  theZLP = (theRECOLepton.at(0)->Px()*theZ.Px()+theRECOLepton.at(0)->Py()*theZ.Py())/(theZ.Pt()*theZ.Pt());
	      float  theZLPSm = (theRECOLepton.at(1)->Px()*theZ.Px()+theRECOLepton.at(1)->Py()*theZ.Py())/(theZ.Pt()*theZ.Pt());
	      float  theZLPMHTSm = (theRECOLepton.at(1)->Px()*ZMHT.Px()+theRECOLepton.at(1)->Py()*ZMHT.Py())/(ZMHT.Pt()*ZMHT.Pt());
	      float  theZLPMHT = (theRECOLepton.at(0)->Px()*ZMHT.Px()+theRECOLepton.at(0)->Py()*ZMHT.Py())/(ZMHT.Pt()*ZMHT.Pt());
	      Zmassmu->Fill(   ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1))) ,ev.GetEventWeight());
	      ZLP->Fill(theZLP ,ev.GetEventWeight());
	      //  ZLP->Fill(theZLPSm,ev.GetEventWeight());
	      ZLPMHT->Fill(theZLPMHT,ev.GetEventWeight());
	      ZLPMHT->Fill(theZLPMHTSm,ev.GetEventWeight());
	      ZLPvsLP->Fill(theZLP,theZLPMHT ,ev.GetEventWeight());
	      ZPT->Fill(theZ.Pt(),ev.GetEventWeight());
	      ZPTres->Fill((theZ.Pt()-ZMHT.Pt())/(theZ.Pt()),ev.GetEventWeight());
	      ZPTvsMHT->Fill(ZMHT.Pt(),theZ.Pt(),ev.GetEventWeight());
	      ZMHTpl->Fill(ZMHT.Pt(),ev.GetEventWeight());
	      ZST->Fill(theRECOLepton.at(0)->Pt()+(ev.PFMET() + *(theRECOLepton.at(1))).Pt(),ev.GetEventWeight());
	      if(theRECOLepton.at(0)->GetCharge()>0)
		{
		  Zmassmu_pos->Fill(   ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1))) ,ev.GetEventWeight());
		  ZLP_pos->Fill(theZLP ,ev.GetEventWeight());
		  ZPT_pos->Fill(theZ.Pt(),ev.GetEventWeight());
		  ZPTres_pos->Fill((theZ.Pt()-ZMHT.Pt())/(theZ.Pt()),ev.GetEventWeight());
		  ZLPMHT_pos->Fill(theZLPMHT,ev.GetEventWeight());
		  ZLPMHT_pos->Fill(theZLPMHTSm,ev.GetEventWeight());
		  ZMHTpl_pos->Fill(ZMHT.Pt(),ev.GetEventWeight());
		}
	       if(theRECOLepton.at(0)->GetCharge()<0)
		{
		  Zmassmu_neg->Fill(   ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1))) ,ev.GetEventWeight());
		  ZLP_neg->Fill(theZLP ,ev.GetEventWeight());
		  ZPT_neg->Fill(theZ.Pt(),ev.GetEventWeight());
		  ZPTres_neg->Fill((theZ.Pt()-ZMHT.Pt())/(theZ.Pt()),ev.GetEventWeight());
		  ZLPMHT_neg->Fill(theZLPMHT,ev.GetEventWeight());
		  ZLPMHT_neg->Fill(theZLPMHTSm,ev.GetEventWeight());
		  ZMHTpl_neg->Fill(ZMHT.Pt(),ev.GetEventWeight());
		}



	    }
	}
																										  
    }


   return true;
}


std::ostream& ANplots::Description(std::ostream &ostrm) {
  ostrm << "ANplots: " ;
  return ostrm;
}
