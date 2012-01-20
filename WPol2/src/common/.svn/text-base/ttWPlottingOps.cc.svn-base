#include "ttWPlottingOps.hh"
#include "ThrustStuff.hh"
#include "GenObject.hh"
#include "GenMatrixBin.hh"
#include "Math/VectorUtil.h"
#include "MuPtScaleCorr.hh"
using namespace Operation;
//using namespace WPol;

//====================================
  // RECOPolPlots implementation
  //====================================


ttWPlottingOps::ttWPlottingOps(const std::string & folderName) :
    mFolderName(folderName)
    //change this parameter ONLY - this will let you use comparison with generator level quantities
{}

  ttWPlottingOps::~ttWPlottingOps() {}

  void ttWPlottingOps::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void ttWPlottingOps::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    MeffPlus = new TH1D("MeffPlus",";Meff [GeV];#plus charge",100,0,2000);
    MeffMinus = new TH1D("MeffMinus",";Meff [GeV];#minus charge",100,0,2000);
    Meffall = new TH1D("Meff",";Meff [GeV];events",100,0,2000);

    MEta= new TH1D("MMEta",";#eta;",3,0,2.1);
    MEtaC= new TH1D("MMEtaC",";|#eta| #times charge;",120,-3,3);

    MEtaMinus= new TH1D("MMEtaMinus",";#eta;",30,-2.1,2.1);
    MEtaPlus= new TH1D("MMEtaPlus",";#eta;",30,-2.1,2.1);
    MeffIC  = new TH2D("Meff2d",";Meff [GeV];LP",100,0,2000,2,-1.7,2.3);
    MeffMinusIC = new TH2D("Meffpl",";Meff [GeV];LP",100,0,2000,2,-1.7,2.3); 
    MeffPlusIC = new TH2D("Meffmin",";Meff [GeV];LP",100,0,2000,2,-1.7,2.3);
    LPscale   = new TH2D("LPscale",";LP;LP scaled",150,-1.,2.,200,-.2,0.2);
    LPRand    = new TH2D("LPran",";LP;LP smeared",150,-1.,2.,200,-.5,.5);
    EtaPhiP   = new TH2D("EtaPhiP",";#phi;#eta",6,-TMath::Pi(),TMath::Pi(),6,-2.1,2.1);
    EtaPhiM    = new TH2D("EtaPhiM",";#phi;#eta",6,-TMath::Pi(),TMath::Pi(),6,-2.1,2.1);

    IC    = new TH1D("LP","events;sign(charge)*(LP+1);",500,-5.,5.);
    MinusIC = new TH1D("LPmin",";PL^{+};LP",500,-5,5); 
    PlusIC = new TH1D("LPpl",";LP^{-};",500,-5,5);

    MT = new TH1D("MT",";M_{T} [GeV];",500,0,1000);
    MTM = new TH1D("MTM",";M_{T} [GeV];",500,0,1000);
    MTP = new TH1D("MTP",";M_{T} [GeV];",500,0,1000);

    MTC  = new TH1D("MTC",";M_{T} [GeV];",500,0,1000);
    MTMC = new TH1D("MTMC",";M_{T} [GeV];",500,0,1000);
    MTPC = new TH1D("MTPC",";M_{T} [GeV];",500,0,1000);

    JetPT2nd = new TH1D("JetPT2nd",";2nd jet PT [GeV];",500,0,1000);
    MTLP = new TH2D("MTLP",";M_{T} [GeV];LP",500,0,1000,100,-1.7,2.3);

    PFMET = new TH1D("PFMET",";PFMET [GeV];",500,0,1000);
    PFMETM = new TH1D("PFMETM",";PFMET [GeV];",500,0,1000);
    PFMETP= new TH1D("PFMETP",";PFMET [GeV];",500,0,1000);
  
    PFMETDpTDphi= new TH2D("PFMET_Lep_Dphi_Lep_rat",";PFMET [GeV];",50,-TMath::Pi(),TMath::Pi(),500,0,10);
    PFMETDphi = new TH1D("PFMET_Lep_Dphi",";PFMET [GeV];",50,-TMath::Pi(),TMath::Pi());
    PFMETDpT = new TH1D("PFMET_Lep_rat",";PFMET [GeV];",500,0,10);
    PFMETWPT = new TH2D("PFMETWPT",";WPT*LP_{#nu} [GeV];PFMET [GeV]",50,0,1000,50,0,1000);

    MTLepHT = new TH2D("MTLepHT",";Lep HT [GeV];HT [GeV]",50,0,1000,50,0,1000);
    WPTLepHT = new TH2D("WPTLepHT",";Lep HT [GeV];WPT [GeV]",50,0,1000,50,0,1000);
    
    PhiPtPt = new TH2D("PhiPtPt",";PFMETxWPT/WPT [GeV];",50,-1,1,100,-2,2);

    LPWPT = new TH2D("LPWPT",";PFMETxWPT/WPT [GeV];",120,-3,3,50,0,1000);
    WPTMT = new TH2D("WPTMT",";PFMETxWPT/WPT [GeV];",50,0,1000,50,0,1000);  

    Muphi = new TH1D("Muphi",";#phi;",50,-TMath::Pi(),TMath::Pi());
    MuPt = new TH1D("MuPt",";P_{T} [GeV];",500,0,1000);
    MuphiM = new TH1D("MuphiM",";#phi;",50,-TMath::Pi(),TMath::Pi());
    MuPtM = new TH1D("MuPtM",";P_{T} [GeV];",500,0,1000);
    MuphiP = new TH1D("MuphiP",";#phi;",50,-TMath::Pi(),TMath::Pi());
    MuPtP = new TH1D("MuPtP",";P_{T} [GeV];",500,0,1000);

    DilepMassP = new TH1D("DiMuMassP",";P_{T} [GeV];",200,0,1000);
    DilepMassO = new TH1D("DiMuMasso",";P_{T} [GeV];",200,0,1000);
    DilepMassN = new TH1D("DilepMassN",";P_{T} [GeV];",200,0,1000);
    
    DilepMassPI = new TH1D("DiMuMassPI",";P_{T} [GeV];",200,0,1000);
    DilepMassOI = new TH1D("DiMuMassoI",";P_{T} [GeV];",200,0,1000);
    DilepMassNI = new TH1D("DilepMassNI",";P_{T} [GeV];",200,0,1000);
    
    MuEta = new TH1D("MuEta",";#eta ;",100,-5,5);
    MuDR = new TH1D("MuDR",";#Delta R;",100,0,2*TMath::Pi()); 

    MuDRsecM = new TH1D("MuDRsecM",";#Delta R;",100,0,2*TMath::Pi()); 
    MuDPTsecM = new TH1D("MuDPTsecM",";#Delta PT;",200,0,2); 

    MHTRes = new TH1D("MuPtRes",";(pt-pt cor)/pt;",200,-1.,1); 
    MHTResMeff = new TH1D("MHTeff",";(MHT-MF recoil)/Meff;",200,-1.,1); 
    WPtall = new TH1D("WPTall",";MF recoil [GeV];",500,-0.,1000); 

    MuBD0  = new TH1D("MuBD0",";BS D_{0} cm;",5000,0,0.05);
    MuVD0 = new TH1D("MuVD0",";VT D_{0} cm;",5000,0,0.05);
    MuVD0sig = new TH1D("MuVD0Sig",";VT D_{0} #sigma;",500,0,50);
    MuVDZ = new TH1D("MuVDZ",";V #Delta Z cm;",5000,-10.,10.);
    //  MuVDZsig = new TH1D("MuVDZsig",";V #Delta Z #sigma;",500,0.,50.);

    MuVHits = new TH1D("MuVHits",";no valid Hits;",50,0,50);
    MuTrIso  = new TH1D("MuTrIso",";Trk Iso;",400,0,20);
    MuEIso = new TH1D("MuEIso",";E Iso;",400,0,20);
    MuHIso = new TH1D("MuHIso","H Iso;",400,0,20);
    MuCso =  new TH1D("MuCso",";All Iso;",500,0,0.5);
    MuC2glob =  new TH1D("MuChi2glob",";norm chi2 global fit;",50,0,10);
    MuC2tr =  new TH1D("MuChi2inner",";norm chi2 global fit;",50,0,10);

    MuC2globP =  new TH1D("MuChi2globP",";norm chi2 global fit+;",50,0,10);
    MuC2trP =  new TH1D("MuChi2innerP",";norm chi2 global fit+;",50,0,10);
    MuC2globM =  new TH1D("MuChi2globM",";norm chi2 global fit-;",50,0,10);
    MuC2trM =  new TH1D("MuChi2innerM",";norm chi2 global fit-;",50,0,10);

    MTTrkIso =  new TH2D("MTTrkIso",";M_{T} [GeV];TrkIso",500,0,1000,100,0,10);
    MeffTHMax = new TH1D("max",";#eta;",100,0,2000);
    MeffThMin = new TH1D("min",";#eta;",100,0,2000);

    BookHistArray(hg_ScaleP,"ScalePlus",";scale [GeV];", 400,0.,2000.,6,0,1,false);
    BookHistArray(hg_ScaleM,"ScaleMinus",";scale [GeV];", 400,0.,2000.,6,0,1,false);

    BookHistArray(hg_WPTP,"WPTP",";W PT [GeV];", 400,0.,2000.,6,0,1,false);
    BookHistArray(hg_WPTM,"WPTM",";W PT [GeV];", 400,0.,2000.,6,0,1,false);
  }

  bool ttWPlottingOps::Process(Event::Data & ev) {

   std::vector <Event::Lepton const *> theRECOLepton;
  
   bool isMu= false;
   if(ev.LD_CommonMuons().accepted.size()>0&&ev.LD_CommonElectrons().accepted.size()==0)
     {
       theRECOLepton = ev.LD_CommonMuons().accepted;
       isMu = true;
     }  

   if(ev.LD_CommonMuons().accepted.size()==0&&ev.LD_CommonElectrons().accepted.size()>0)
     {
       theRECOLepton = ev.LD_CommonElectrons().accepted;
     }  

   if(ev.LD_CommonMuons().accepted.size()>0&&ev.LD_CommonElectrons().accepted.size()>0)
     {
       //  cout << "WARNING: ttWPlottingOps has common muon AND Electron, it does not know what to plot!!!"<<endl;
       return true;
     }

   if (theRECOLepton.size()==0)
     {
       // cout << "  ttWPlottingOps does require at least one lepton: plots not filled "<<endl;
       return true;
     }


   LorentzV pfMET = ev.PFMET() + *(theRECOLepton.at(0));
   double ICVariablePF = ((theRECOLepton.at(0)->Px() * pfMET.Px()) + (theRECOLepton.at(0)->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());
   double Meff = ev.CommonHT()+ pfMET.Pt();
   double scale = ev.SumEt() + ev.PFMET().Pt()+ (theRECOLepton.at(0))->Pt();
   double aMT =  sqrt(2.0 * ev.PFMET().Pt() * (theRECOLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), ev.PFMET() ) )));

   PFMETDpT->Fill(theRECOLepton.at(0)->Pt()/ev.PFMET().Pt(),ev.GetEventWeight());
   PFMETDphi->Fill(ROOT::Math::VectorUtil::DeltaPhi(ev.PFMET() , *(theRECOLepton.at(0))),ev.GetEventWeight());
   PFMETDpTDphi->Fill(ROOT::Math::VectorUtil::DeltaPhi(ev.PFMET() , *(theRECOLepton.at(0))),theRECOLepton.at(0)->Pt()/ev.PFMET().Pt(),ev.GetEventWeight());
   LPWPT->Fill(ICVariablePF,pfMET.Pt(),ev.GetEventWeight());
   WPTMT->Fill(pfMET.Pt() ,aMT,ev.GetEventWeight());
   PhiPtPt->Fill(((theRECOLepton.at(0)->Px() * pfMET.Px()) + (theRECOLepton.at(0)->Py() * pfMET.Py())) / (pfMET.Pt() * theRECOLepton.at(0)->Pt()),theRECOLepton.at(0)->Pt()/pfMET.Pt() ,ev.GetEventWeight());

   PFMET->Fill(ev.PFMET().Pt(),ev.GetEventWeight());
  
   if(ev.JD_CommonJets().accepted.size()>1) JetPT2nd->Fill(ev.JD_CommonJets().accepted.at(1)->Pt(),ev.GetEventWeight());

 
   PFMETWPT->Fill(pfMET.Pt()*(-(ICVariablePF-1)),ev.PFMET().Pt(),ev.GetEventWeight());

   float allPt = ev.PFMET().Pt()+theRECOLepton.at(0)->Pt();
   MTLepHT->Fill(allPt,ev.CommonHT(),ev.GetEventWeight());
   WPTLepHT->Fill(allPt,pfMET.Pt(),ev.GetEventWeight());

   Muphi->Fill((theRECOLepton.at(0))->Phi(),ev.GetEventWeight());
   MuPt->Fill((theRECOLepton.at(0))->Pt(),ev.GetEventWeight());
   TLorentzVector  mumu;
   mumu.SetPtEtaPhiM(theRECOLepton.at(0)->Pt(),theRECOLepton.at(0)->Eta(),theRECOLepton.at(0)->Phi(),theRECOLepton.at(0)->M());

 
   MHTRes->Fill((theRECOLepton.at(0)->Pt()- MuPtScaleCorrIdealGen(theRECOLepton.at(0)->GetCharge(),mumu,false,&ev).Pt())/theRECOLepton.at(0)->Pt(),ev.GetEventWeight());
   MuEta->Fill((theRECOLepton.at(0))->Eta(),ev.GetEventWeight());

   //  MHTRes->Fill( (ev.CommonMHT().Pt()-pfMET.Pt()) / pfMET.Pt() ,ev.GetEventWeight());
   MHTResMeff->Fill((ev.CommonMHT().Pt()-pfMET.Pt())/(ev.SumEt()+ev.CommonMHT().Pt()),ev.GetEventWeight());
   WPtall->Fill(pfMET.Pt() ,ev.GetEventWeight());
   double CMT =0;

   if (isMu)
     {
       int iM  = (theRECOLepton.at(0))->GetIndex();
       LorentzV CorPFmet =  ev.PFMET();
       CorPFmet = CorPFmet-(*theRECOLepton.at(0));
       //  ev.muonP4()->at(iM);
       //  ev.LD_Muons().size();
       //  LorentzV Inimu= ev.LD_Muons().at(iM);
       LorentzV Inimu=(ev.muonP4()->at(iM));
       //cout << Inimu.Pt()<< " "<<  (theRECOLepton.at(0))->Pt()<<endl;
       CorPFmet = CorPFmet+Inimu;
       
       CMT =  sqrt(2.0 * CorPFmet.Pt() * (theRECOLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), CorPFmet ) )));
       
       
       MuBD0->Fill( fabs(ev.GetMuonInnerTrackDxyBS(iM)),ev.GetEventWeight());
       MuVD0->Fill(fabs(ev.GetMuonInnerTrackDxy(iM)),ev.GetEventWeight());
       MuVD0sig->Fill(fabs(ev.GetMuonInnerTrackDxy(iM)/ev.GetMuonInnerTrackDxyError(iM)),ev.GetEventWeight());
       MuVDZ->Fill(ev.GetMuonInnerTrackDz(iM),ev.GetEventWeight());
       MuVHits->Fill(ev.GetMuonInnerTracknumberOfValidHits(iM),ev.GetEventWeight());
       MuC2glob->Fill(ev.muonGlobalTrackNormChi2()->at(iM),ev.GetEventWeight());
       MuC2tr->Fill(ev.muonInnerTrackNormChi2()->at(iM),ev.GetEventWeight());
       
       if(theRECOLepton.at(0)->GetCharge()>0){
	 MuC2globP->Fill(ev.muonGlobalTrackNormChi2()->at(iM),ev.GetEventWeight());
	 MuC2trP->Fill(ev.muonInnerTrackNormChi2()->at(iM),ev.GetEventWeight());
       }
       else{MuC2globM->Fill(ev.muonGlobalTrackNormChi2()->at(iM),ev.GetEventWeight());
	 MuC2trM->Fill(ev.muonInnerTrackNormChi2()->at(iM),ev.GetEventWeight());}
       
     }
   MuTrIso->Fill((theRECOLepton.at(0))->GetTrkIsolation(),ev.GetEventWeight());
   MuEIso->Fill((theRECOLepton.at(0))->GetEcalIsolation(),ev.GetEventWeight());
   MuHIso->Fill((theRECOLepton.at(0))->GetHcalIsolation(),ev.GetEventWeight());
   MuCso->Fill((theRECOLepton.at(0))->GetCombIsolation(),ev.GetEventWeight());


   MTTrkIso->Fill(aMT,(theRECOLepton.at(0))->GetTrkIsolation(),ev.GetEventWeight());

   float minDeltaR = 2*TMath::Pi();
   for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ )
     {
       float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton.at(0))));
       if(aminDeltaR<minDeltaR)minDeltaR=aminDeltaR;
     }
   
   if(ev.secMuonP4()->size()>0)
     {
       //ev.muonP4()->at(iM)
       MuDRsecM->Fill( fabs(ROOT::Math::VectorUtil::DeltaR ((ev.secMuonP4()->at(0)),*(theRECOLepton.at(0) ))),ev.GetEventWeight());
       MuDPTsecM->Fill(ev.secMuonP4()->at(0).Pt()/theRECOLepton.at(0)->Pt(),ev.GetEventWeight());
     }

  
   MuDR->Fill(minDeltaR,ev.GetEventWeight());
   MT->Fill(aMT,ev.GetEventWeight());
   MTLP->Fill(aMT,ICVariablePF,ev.GetEventWeight());




  //  ThrustStuff aThrustStuff =  ev.CommonThrustStuff();
   Meffall->Fill( Meff , ev.GetEventWeight());
   MeffIC->Fill( Meff , ICVariablePF,ev.GetEventWeight());
   //  IC->Fill(ICVariablePF , ev.GetEventWeight());
   MEta->Fill(fabs(theRECOLepton.at(0)->Eta()) , ev.GetEventWeight());
   MEtaC->Fill(fabs(theRECOLepton.at(0)->Eta())*(theRECOLepton.at(0)->GetCharge()), ev.GetEventWeight());

   //MeffTHMax->Fill(aThrustStuff.HTFmax+aThrustStuff.MHTFmax , ev.GetEventWeight());
   //MeffThMin->Fill(aThrustStuff.HTFmin+aThrustStuff.MHTFmin, ev.GetEventWeight());
   //if(fabs(TMath::Pi()-aThrustStuff.pjetDphi)<TMath::Pi()/2.)  MeffTHMax->Fill(sin(aThrustStuff.pjetDphi)*ev.SumEt()/2., ev.GetEventWeight());
   //else  MeffTHMax->Fill(ev.SumEt(), ev.GetEventWeight());
  
   MTC->Fill( CMT , ev.GetEventWeight());
   if(theRECOLepton.at(0)->GetCharge()>0.0) {
    MTPC->Fill( CMT , ev.GetEventWeight());
    MTP->Fill( aMT , ev.GetEventWeight());
     MuphiP->Fill( theRECOLepton.at(0)->Phi() , ev.GetEventWeight());
     MuPtP->Fill(  theRECOLepton.at(0)->Pt() , ev.GetEventWeight());
     PFMETP->Fill(  ev.PFMET().Pt() , ev.GetEventWeight());


     MeffPlus->Fill( Meff , ev.GetEventWeight());
     MeffPlusIC->Fill( Meff , ICVariablePF,ev.GetEventWeight());
     MEtaPlus->Fill(theRECOLepton.at(0)->Eta() , ev.GetEventWeight());
     EtaPhiP->Fill( theRECOLepton.at(0)->Phi() ,theRECOLepton.at(0)->Eta() , ev.GetEventWeight());
     
     PlusIC->Fill(ICVariablePF , ev.GetEventWeight());
     IC->Fill(ICVariablePF+1 , ev.GetEventWeight());
     hg_ScaleP[0]->Fill(scale , ev.GetEventWeight());
     hg_WPTP[0]->Fill(pfMET.Pt() , ev.GetEventWeight());
     
     if( ev.JD_CommonJets().accepted.size()>0&& ev.JD_CommonJets().accepted.size()<6)
       {
	 	 hg_ScaleP[ ev.JD_CommonJets().accepted.size()]->Fill(scale , ev.GetEventWeight());
	 	 hg_WPTP[ev.JD_CommonJets().accepted.size()]->Fill(pfMET.Pt() , ev.GetEventWeight());
       }
   }
    else{
     MTMC->Fill( CMT , ev.GetEventWeight());
      MuphiM->Fill( theRECOLepton.at(0)->Phi() , ev.GetEventWeight());
      MuPtM->Fill(  theRECOLepton.at(0)->Pt() , ev.GetEventWeight());
      PFMETM->Fill(  ev.PFMET().Pt() , ev.GetEventWeight());
      EtaPhiM->Fill( theRECOLepton.at(0)->Phi() ,theRECOLepton.at(0)->Eta() , ev.GetEventWeight());
      MTM->Fill( aMT , ev.GetEventWeight());

      MeffMinus->Fill( Meff , ev.GetEventWeight());
      MeffMinusIC->Fill( Meff , ICVariablePF,ev.GetEventWeight());
      MEtaMinus->Fill(theRECOLepton.at(0)->Eta() , ev.GetEventWeight());
      MinusIC->Fill(ICVariablePF , ev.GetEventWeight());
      IC->Fill(-ICVariablePF-1 , ev.GetEventWeight());
      
      
       hg_ScaleM[0]->Fill(scale , ev.GetEventWeight());
       hg_WPTM[0]->Fill(pfMET.Pt() , ev.GetEventWeight());
       if( ev.JD_CommonJets().accepted.size()>0&& ev.JD_CommonJets().accepted.size()<6)
	 {
	    hg_ScaleM[ ev.JD_CommonJets().accepted.size()]->Fill(scale , ev.GetEventWeight());
	    hg_WPTM[ ev.JD_CommonJets().accepted.size()]->Fill(pfMET.Pt() , ev.GetEventWeight());
	 }
    }

   if(ev.LD_CommonMuons().accepted.size()==2)
     {
       Event::Lepton const * LepP; Event::Lepton const * LepN;

       if(theRECOLepton.at(0)->GetCharge()>0){
	 LepP = theRECOLepton.at(0);
	 LepN = theRECOLepton.at(1);
       }
       else{
	 LepP = theRECOLepton.at(1);
	 LepN = theRECOLepton.at(0);
       }

       LorentzV Z = (*LepP)+(*LepN);
       float ZLP =   (Z.Px()*LepP->Px() +Z.Py()*LepP->Py())/(Z.Pt()*Z.Pt());

       DilepMassP->Fill(Z.M(), ev.GetEventWeight());
/* if(LepP->Eta()>0.75&&ZLP>0.75)DilepMassP->Fill(Z.M(), ev.GetEventWeight());
       if(LepP->Eta()<-0.75&&ZLP<0.25)DilepMassP->Fill(Z.M(), ev.GetEventWeight());


       if(LepP->Eta()>0.75&&ZLP<0.25)DilepMassN->Fill(Z.M(), ev.GetEventWeight());
       if(LepP->Eta()<-0.75&&ZLP>0.75)DilepMassN->Fill(Z.M(), ev.GetEventWeight());

*/


     }




   return true;
 }


  std::ostream& ttWPlottingOps::Description(std::ostream &ostrm) {
    ostrm << "tt&W control plots "
        ;
    return ostrm;
  }
