#include "MuonOps.hh"
#include "GenMatrixBin.hh"

using namespace Operation;

namespace LeptonCommissioning{
  
  void myMuonPlots::BookHistos(){
    
    tree=new TTree("T","test");
    
    tree->Branch("wgt",&wgt,"wgt/D");
    tree->Branch("trkIso",&trkIso,"trkIso/F");
    tree->Branch("combIso",&combIso,"combIso/F");
    tree->Branch("caloIso",&caloIso,"caloIso/F");
    tree->Branch("relTrkIso",&relTrkIso,"relTrkIso/F");
    tree->Branch("relCaloIso",&relCaloIso,"relCaloIso/F");
    tree->Branch("relCombIso",&relCombIso,"relCombIso/F");
    tree->Branch("nJet",&nJet,"nJet/I");
    tree->Branch("nMu",&nMu,"nMu/I");
    tree->Branch("nEl",&nEl,"nEl/I");
    tree->Branch("gPar",&gPar,"gPar/I");
    tree->Branch("et_mu",&et_mu,"et_mu/F");
    tree->Branch("pt_mu",&pt_mu,"pt_mu/F");
    tree->Branch("eta_mu",&eta_mu,"eta_mu/F");
    tree->Branch("inrTrkD0",&inrTrkD0,"inrTrkD0/F");
    tree->Branch("inrTrkD0Err",&inrTrkD0Err,"inrTrkD0Err/F");
    tree->Branch("chrg",&chrg,"chrg/I");
    tree->Branch("etJet",etJet,"etJet[nJet]/F");
    tree->Branch("etaJet",etaJet,"etaJet[nJet]/F");
    tree->Branch("closestPreJetDR",&closestPreJetDR,"closestPreJetDR/F");
    tree->Branch("closestPreJetEt",&closestPreJetEt,"closestPreJetEt/F");
    tree->Branch("closestComJetDR",&closestComJetDR,"closestComJetDR/F");
    tree->Branch("closestComJetEt",&closestComJetEt,"closestComJetEt/F");
    tree->Branch("ht",&ht,"ht/F");
    tree->Branch("mht",&mht,"mht/F");
    tree->Branch("recoilMet",&recoilMet,"recoilMet/F");
    tree->Branch("caloMet",&caloMet,"caloMet/F");
    tree->Branch("pfMet",&pfMet,"pfMet/F");
    tree->Branch("mt_MuRecoilMet",&mt_MuRecoilMet,"mt_MuRecoilMet/F");
    tree->Branch("mt_MuCaloMet",&mt_MuCaloMet,"mt_MuCaloMet/F");
    tree->Branch("mt_MuPfMet",&mt_MuPfMet,"mt_MuPfMet/F");
    tree->Branch("mt2_MuRecoilMet",&mt2_MuRecoilMet,"mt2_MuRecoilMet/F");
    tree->Branch("mt2_MuCaloMet",&mt2_MuCaloMet,"mt2_MuCaloMet/F");
    tree->Branch("mt2_MuPfMet",&mt2_MuPfMet,"mt2_MuPfMet/F");
    tree->Branch("alphaT",&alphaT,"alphaT/F");
    tree->Branch("alphaT_Had",&alphaT_Had,"alphaT_Had/F");
    tree->Branch("lepType",&lepType,"lepType/I");
    tree->Branch("lp",&lp,"lp/F");
    tree->Branch("PFLP",&PFLP,"PFLP/F");
    tree->Branch("biasedDPhi",&biasedDPhi,"biasedDPhi/F");
    tree->Branch("mEff",&mEff,"mEff/F");
    //    tree->Branch("hlt30U",&hlt30U,"hlt30U/I");
    //    tree->Branch("hlt50U",&hlt30U,"hlt50U/I");
    tree->Branch("washlt30UPreScaled",&washlt30UPreScaled,"washlt30UPreScaled/I");
    tree->Branch("washlt50UPreScaled",&washlt50UPreScaled,"washlt50UPreScaled/I");
  }
  
  double myMuonPlots::getCorrD0(double d0, double phi, double X, double Y ) {
    return d0 - X * sin(phi) + Y * cos(phi);
  }
  
  
  bool myMuonPlots::Process(Event::Data &ev){
 
    //  mNumObjMax=10;
    //  int nJ = ev.JD_CommonJets.size();
    wgt=ev.GetEventWeight();
    int myJetLength = ev.JD_CommonJets().accepted.size();
    //    if(myJetLength>=jetArrayLength) myJetLength=jetArrayLength-1;

    nJet=myJetLength;
    
    int count=0;

    nEl = ev.LD_CommonElectrons().accepted.size();
    nMu = ev.LD_CommonMuons().accepted.size();
    ht = ev.CommonHT();
    mht = ev.CommonMHT().Pt();    
    recoilMet = ev.CommonRecoilMET().Pt();
    caloMet = ev.CaloMET().Pt();
    pfMet = ev.PFMET().Pt();
    mEff = ev.CommonMeff();
    /*
    std::map<std::string,bool>::const_iterator it30=ev.hlt()->find("HLT_Jet30");
    if (it30==ev.hlt()->end()) { cout << "IN" << "\n"; hlt30U = 0;}
    else { hlt30U = 1; }

    std::map<std::string,bool>::const_iterator it50=ev.hlt()->find("HLT_Jet50");
    if (it50==ev.hlt()->end()) { cout << "IN" << "\n"; hlt50U = 0;}
    else { hlt50U = 1; }
    */
    
    // if it was prescaled -> store 1 (null), if not 0 !!
    std::map<std::string,int>::const_iterator itpre30=ev.hlt_prescaled()->find("HLT_Jet30U");
    if (itpre30==ev.hlt_prescaled()->end()) { washlt30UPreScaled = 1; }
    else if (itpre30->second == 1) { washlt30UPreScaled = 0; }
    else  { washlt30UPreScaled = 1; }

    std::map<std::string,int>::const_iterator itpre50=ev.hlt_prescaled()->find("HLT_Jet50U");
    if (itpre50==ev.hlt_prescaled()->end()) { washlt50UPreScaled = 1; }
    else if (itpre50->second == 1) { washlt50UPreScaled = 0; }
    else  { washlt50UPreScaled = 1; }
    
    if (nMu>=1) {
      
      mt_MuRecoilMet = sqrt(2.*(ev.LD_CommonMuons().accepted[0]->Pt())*(ev.CommonRecoilMET().Pt())*(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(ev.LD_CommonMuons().accepted[0]),ev.CommonRecoilMET()))));
      mt_MuCaloMet = sqrt(2.*(ev.LD_CommonMuons().accepted[0]->Pt())*(ev.CaloMET().Pt())*
		      (1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(ev.LD_CommonMuons().accepted[0]),ev.CaloMET()))));
      mt_MuPfMet = sqrt(2.*(ev.LD_CommonMuons().accepted[0]->Pt())*(ev.PFMET().Pt())*
			(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(ev.LD_CommonMuons().accepted[0]),ev.PFMET()))));
      mt2_MuRecoilMet = 2.*(ev.LD_CommonMuons().accepted[0]->Pt())*(ev.CommonRecoilMET().Pt())*(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(ev.LD_CommonMuons().accepted[0]),ev.CommonRecoilMET())));
      mt2_MuCaloMet = 2.*(ev.LD_CommonMuons().accepted[0]->Pt())*(ev.CaloMET().Pt())*
	(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(ev.LD_CommonMuons().accepted[0]),ev.CaloMET())));
      mt2_MuPfMet = 2.*(ev.LD_CommonMuons().accepted[0]->Pt())*(ev.PFMET().Pt())*
	(1.-cos(ROOT::Math::VectorUtil::DeltaPhi(*(ev.LD_CommonMuons().accepted[0]),ev.PFMET())));

      lp = ( ((ev.LD_CommonMuons().accepted[0]->Px())*(ev.CommonMHT().Px())) + ((ev.LD_CommonMuons().accepted[0]->Py())*(ev.CommonMHT().Py())) ) /
	((ev.CommonMHT().Pt())*(ev.CommonMHT().Pt()));
      PFLP = ( ((ev.LD_CommonMuons().accepted[0]->Px())*((ev.PFMET()+(*(ev.LD_CommonMuons().accepted[0]))).Px())) + 
	       ((ev.LD_CommonMuons().accepted[0]->Py())*((ev.PFMET()+(*(ev.LD_CommonMuons().accepted[0]))).Py()) ) )  /
	( ((ev.PFMET()+(*(ev.LD_CommonMuons().accepted[0]))).Pt())*((ev.PFMET()+(*(ev.LD_CommonMuons().accepted[0]))).Pt()) );

    }

      alphaT=ev.CommonAlphaT();
      alphaT_Had=ev.hadAlpha_t();
      biasedDPhi=ev.CommonMinBiasDPhi();


    UInt_t countJts = 0;
    for ( std::vector<Event::Jet const *>::const_iterator iJ = ev.JD_CommonJets().accepted.begin();
	  iJ != ev.JD_CommonJets().accepted.end();
	  iJ++ ) {

      etJet[countJts] = ev.JD_CommonJets().accepted[countJts]->Pt();
      etaJet[countJts] = fabs(ev.JD_CommonJets().accepted[countJts]->Eta());

      countJts++;
    } // ~ end of loop over the common Jts.


    const std::vector<const Event::Lepton*> & common_leps=ev.LD_CommonMuons().accepted;
    for (std::vector<const Event::Lepton*>::const_iterator ii=common_leps.begin();
	 ii!=common_leps.end();
	 ++ii) {
      
      int idx=(*ii)->GetIndex();
      
      eta_mu=(*ii)->Eta(); pt_mu=(*ii)->Pt(); et_mu=(*ii)->Et();

      chrg=(*ii)->GetCharge();
      
      trkIso = (*ii)->GetTrkIsolation();
      caloIso = ((*ii)->GetEcalIsolation() + (*ii)->GetHcalIsolation());
      combIso = ((*ii)->GetTrkIsolation() + (*ii)->GetEcalIsolation() + (*ii)->GetHcalIsolation() );
      relTrkIso = ((*ii)->GetTrkIsolation())/pt_mu;
      relCaloIso = ( (*ii)->GetEcalIsolation() + (*ii)->GetHcalIsolation() )/pt_mu;
      relCombIso = (*ii)->GetCombIsolation();

      inrTrkD0 = ev.GetMuonInnerTrackDxy(idx);
      inrTrkD0Err= ev.GetMuonInnerTrackDxyError(idx);
      
      double jetEt=-999.;
      double dRmin=999.;
      double jetEtCom=-999.;
      double dRminCom=999.;
      
      for (std::vector<Event::Jet>::const_iterator ij=ev.JD_Jets().begin();
	   ij!=ev.JD_Jets().end();
	   ++ij) {

	double dR=fabs(ROOT::Math::VectorUtil::DeltaR ((**ii),(*ij)));
	if (dR<dRmin) {
	  dRmin=dR; 
	  jetEt=(ij)->Pt();
	}
	
      } // ~end of loop over the PreJets
    
      closestPreJetDR=dRmin;
      closestPreJetEt=jetEt; 
      
      for ( std::vector<Event::Jet const *>::const_iterator iJ2 = ev.JD_CommonJets().accepted.begin();
	    iJ2 != ev.JD_CommonJets().accepted.end();
	    iJ2++ ) {
	
	double dRCom=fabs(ROOT::Math::VectorUtil::DeltaR ((**ii),(**iJ2)));
	if (dRCom<dRminCom) {
	  dRminCom=dRCom; 
	  jetEtCom=(*iJ2)->Pt();
	}
       
      } // ~ end of loop over the common Jts.
      
      closestComJetDR=dRminCom;
      closestComJetEt=jetEtCom; 


      int iMatch = ev.leptonMatch(*ii,2);
      lepType=ev.leptonType(iMatch); gPar=ExtendedType(ev,*ii,2);
      
      count++;
      
      tree->Fill();
  
      if (count>0) break;
    
    } // ~ end of the loop over the common muons
  
    
    return true;
  } // ~end of process myMuonPlots



  NumOfGdMuons::NumOfGdMuons(const std::string & comparison, UInt_t number,
			     float pt, float eta) :
    mNumber(number),
    mPt(pt),
    mEta(eta)
  {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
    } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
    } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
    } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  NumOfGdMuons::~NumOfGdMuons() { delete mComparison; }

  bool NumOfGdMuons::Process(Event::Data & ev) {

    //var to store the numOfGdMuons / event
    UInt_t count = 0;
    UInt_t sizeOfGdMuons = 99;

    // loop over the PreMuons
    for (std::vector<Lepton>::const_iterator ob = ev.LD_Muons().begin();
         ob != ev.LD_Muons().end();
         ++ob) {

      int iM = ob->GetIndex();
      float tmpInrTrkDxyPrimVtx = 999.;
      int   tmpInrTrkNValidHits = 999;
      float tmpGlbTrkChi2ndf = 999.;

      tmpInrTrkNValidHits = ev.GetMuonInnerTracknumberOfValidHits(iM);
      tmpInrTrkDxyPrimVtx = ev.GetMuonInnerTrackDxy(iM);
      tmpGlbTrkChi2ndf = ev.GetMuonGlobalTrackNormChi2(iM);

      if (
          ( (ev.IsMuonTracker(iM)) )           &&
          ( (ev.IsGlobalMuonPromptTight(iM)) ) &&
          ( (ob->Pt()) >= mPt )                  &&
          ( fabs(ob->Eta()) <= mEta )            &&
          ( tmpInrTrkNValidHits >= 11 )          &&
          ( fabs(tmpInrTrkDxyPrimVtx) < 0.2)     &&
          ( tmpGlbTrkChi2ndf < 10. )
          ) { count++; }

    } // end of looping over the PreMuons

    sizeOfGdMuons = count;

    return (*mComparison)(UInt_t(sizeOfGdMuons),
			  mNumber);
  }

  std::ostream& NumOfGdMuons::Description(std::ostream &ostrm) {
    ostrm << "NumOfGdMuons Operation " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }



} // ~end of namespace
