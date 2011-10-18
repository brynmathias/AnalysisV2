#include "BasicOps.hh"
#include "GenMatrixBin.hh"

using namespace Operation;

namespace LeptonCommissioning{

  LMPlots::LMPlots(const std::string & foldername) :
    mFolderName(foldername) {}

  LMPlots::~LMPlots() {}

  void LMPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void LMPlots::BookHistos() {
    JetMulti= new TH1D("JetMultiplicity",";No of Jets",20,-0.5,19.5);
    ele_pt = new TH1D("ElePt",";Electron Pt", 1000, 0.,2000.);
    jet_pt = new TH1D("JetPt",";Electron Pt", 1000, 0.,2000.);
    jet_Et = new TH1D("JetEt",";Electron Pt", 1000, 0.,2000.);
  }

  bool LMPlots::Process(Event::Data & ev) {

    if(ev.LD_CommonElectrons().accepted.size() > 1){

      ele_pt->Fill(ev.LD_CommonElectrons().accepted.at(0)->Pt(),ev.GetEventWeight());


    }

   JetMulti->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());


   if(ev.JD_CommonJets().accepted.size() > 1){

     for (std::vector<Event::Jet const *>::const_iterator ob = ev.JD_CommonJets().accepted.begin(); ob != ev.JD_CommonJets().accepted.end(); ++ob) {
       jet_pt->Fill((**ob).Pt(),ev.GetEventWeight());
       jet_Et->Fill((**ob).Et(),ev.GetEventWeight());
  

     }}}

  std::ostream& LMPlots::Description(std::ostream &ostrm) {

  ostrm << "LM plotting operation ";
  return ostrm;
  }

void makeElectronTree::BookHistos(){

  tree=new TTree("T","test");

  tree->Branch("wgt",&wgt,"wgt/D");
  tree->Branch("combIso",&combIso,"combIso/D");
  tree->Branch("caloIso",&caloIso,"caloIso/D");
  tree->Branch("nJet",&nJet,"nJet/I");
  tree->Branch("nEle",&nEle,"nEle/I");
  tree->Branch("gPar",&gPar,"gPar/I");
  tree->Branch("et_e",&et_e,"et_e/D");
  tree->Branch("pt_e",&pt_e,"pt_e/D");
  tree->Branch("eta_e",&eta_e,"eta_e/D");
  tree->Branch("et_j1",&et_j1,"et_j1/D");
  tree->Branch("eta_j1",&eta_j1,"eta_j1/D");
  tree->Branch("eop",&eop,"eop/D");
  tree->Branch("closestJetEt",&closestJetEt,"closestJetEt/D");
  tree->Branch("closestJetDR",&closestJetDR,"closestJetDR/D");
  tree->Branch("ht",&ht,"ht/D");
  tree->Branch("mht",&mht,"mht/D");
  tree->Branch("pfMet",&pfMet,"pfMet/D");
  tree->Branch("alphaT",&alphaT,"alphaT/D");
  tree->Branch("alphaT_lep",&alphaT_lep,"alphaT_lep/D");
  tree->Branch("alphaT_had",&alphaT_had,"alphaT_had/D");
  tree->Branch("lepType",&lepType,"lepType/I");
  tree->Branch("dcot",&dcot,"dcot/D");
  tree->Branch("dist",&dist,"dist/D");
  tree->Branch("mHits",&mHits,"mHits/I");
  tree->Branch("hitFP",&hitFP,"hitFP/B");
  tree->Branch("hoe",&hoe,"hoe/D");
  tree->Branch("deta",&deta,"deta/D");
  tree->Branch("dphi",&dphi,"dphi/D");
  tree->Branch("sigmaietaieta",&sigmaietaieta,"sigmaietaieta/D");
  tree->Branch("njet_emf_pass",&njet_emf_pass,"njet_emf_pass/I");
  tree->Branch("et_j1_uncor",&et_j1_uncor, "et_j1_uncor/D");
  tree->Branch("CF_j1",&CF_j1, "CF_j1/D");
  tree->Branch("CF_corj1",&CF_corj1, "CF_corj1/D");
  tree->Branch("et_c_uncor",&et_c_uncor, "et_c_uncor/D");
  tree->Branch("CF_c",&CF_c, "CF_c/D");

  tree->Branch("et_comc_uncor",&et_comc_uncor, "et_comc_uncor/D");
  tree->Branch("CF_comc",&CF_comc, "CF_comc/D");
  tree->Branch("com_closestJetEt",&com_closestJetEt,"com_closestJetEt/D");
  tree->Branch("com_closestJetDR",&com_closestJetDR,"com_closestJetDR/D");


  tree->Branch("et_uk_uncor",&et_uk_uncor, "et_uk_uncor/D");
  tree->Branch("CF_uk",&CF_uk, "CF_uk/D");
  tree->Branch("uk_closestJetDR",&uk_closestJetDR,"uk_closestJetDR/D");
  tree->Branch("uk_closestJetEt",&uk_closestJetEt,"uk_closestJetEt/D");

  tree->Branch("trig_Jet80",&trig_Jet80, "trig_Jet80/B");
  tree->Branch("trig_Jet50",&trig_Jet50, "trig_Jet50/B");
  tree->Branch("trig_Jet30",&trig_Jet30, "trig_Jet30/B");
  tree->Branch("ComMeff",&ComMeff,"ComMeff/D");
  tree->Branch("SumMeff",&SumMeff, "SumMeff/D");


}
 
  double makeElectronTree::getCorrD0(double d0, double phi, double X, double Y ) {
    return d0 - X * sin(phi) + Y * cos(phi);

  }

bool makeElectronTree::Process(Event::Data &ev){
  wgt=ev.GetEventWeight();
  ComMeff=ev.CommonMeff();
  SumMeff=ev.CommonRecoilMET().Pt()+ev.CommonSumEt();
  // cout <<"Gensize is " << ev.GenParticles().size() << endl;



  std::map<std::string,bool>::const_iterator it=ev.hlt()->find("HLT_Jet80");
  if(it==ev.hlt()->end()) trig_Jet80 = false;
  else trig_Jet80 = it->second;
 std::map<std::string,bool>::const_iterator iy3=ev.hlt()->find("HLT_Jet50");
  if(iy3==ev.hlt()->end()) trig_Jet50 = false;
  else trig_Jet50 = iy3->second;

  std::map<std::string,bool>::const_iterator it2=ev.hlt()->find("HLT_Jet30");
  if(it2==ev.hlt()->end()) trig_Jet30 = false;
  else trig_Jet30 = it2->second;


  int myJetLength = ev.JD_CommonJets().accepted.size();
  if(myJetLength>=jetArrayLength) myJetLength=jetArrayLength-1;

  nJet=myJetLength;

  int count=0;

  nEle=ev.LD_CommonElectrons().accepted.size();
  pfMet=ev.PFMET().Pt();
  ht=ev.CommonHT(); mht=ev.CommonMHT().Pt();

  // Alpha T is computed for 2-6 common objects
  //  if ( ((nJet+nEle)>1) && ((nJet+nEle)<=6) )  {
  if ( ev.CommonObjects().size() >= 1 &&
       ev.CommonObjects().size() <= 6 ) {
    alphaT=ev.CommonAlphaT();
  alphaT_lep=ev.LeptonicAlphaT();
  alphaT_had=ev.HadronicAlphaT();

  } else { alphaT=-999.;  }

  if (ev.JD_CommonJets().accepted.size()>=1) {

    CF_corj1=ev.GetJetCorrFactor(ev.JD_CommonJets().accepted[0]->GetIndex());
    eta_j1=fabs(ev.JD_CommonJets().accepted[0]->Eta());
    et_j1=fabs(ev.JD_CommonJets().accepted[0]->Pt());




  } else {
    eta_j1=-999.; et_j1=-999.;
  }

  const std::vector<const Event::Lepton*> & common_leps=ev.LD_CommonElectrons().accepted;
  for(std::vector<const Event::Lepton*>::const_iterator ii=common_leps.begin();
      ii!=common_leps.end();
      ++ii){

    int idx=(*ii)->GetIndex();

    double et = ( ev.GetElectronTrkPt(idx)*ev.GetElectronESuperClusterOverP(idx) );
    et_e=et; eta_e=(*ii)->Eta();
    pt_e=(*ii)->Pt();

    combIso=(*ii)->GetCombIsolation();
    caloIso = ( (*ii)->GetEcalIsolation() + (*ii)->GetHcalIsolation() )/et;

    hoe=ev.GetElectronHoE(idx);
    deta=fabs(ev.GetElectronDeltaEtaAtVtx(idx));
    dphi=fabs(ev.GetElectronDeltaPhiAtVtx(idx));
    sigmaietaieta=ev.GetElectronSigmaIetaIeta(idx);
    
    double jetEt=-999.;
  double comjetEt=-999.;
  double unkilled_comjetEt=-999.;
    double dRmin=999.;
    double comdRmin=999.;
    double unkilled_comdRmin=999.;
    double inter_CF_j1;

    bool isunkilledjet=false;

    int jet_index=-1;
    int com_jet_index=1;   
    int uk_jet_index=-1;
    int njetemf = 0;
    double inter_et_j1_uncor = -999.;

    TLorentzVector *com_jet;
    TLorentzVector *uk_jet;
   if (ev.JD_Jets().size()>=1) {
    for(std::vector<Event::Jet>::const_iterator ij=ev.JD_Jets().begin();
	ij!=ev.JD_Jets().end();
	++ij){

      double emf = (ij)->GetEmFrac();
      if (emf < 0.9){
	njetemf +=1;
	  }


      double dR=fabs(ROOT::Math::VectorUtil::DeltaR ((**ii),(*ij)));
      if (dR<dRmin) {
	dRmin=dR; jetEt=(ij)->Pt();
	jet_index=(ij)->GetIndex();
 
      }


  
      TLorentzVector *JetUncor = new TLorentzVector(ij->Px()/ev.GetJetCorrFactor(ij->GetIndex()),ij->Py()/ev.GetJetCorrFactor(ij->GetIndex()),ij->Pz()/ev.GetJetCorrFactor(ij->GetIndex()), ij->E()/ev.GetJetCorrFactor(ij->GetIndex()));
   
  if(JetUncor->Pt() > inter_et_j1_uncor){

    inter_et_j1_uncor = JetUncor->Pt();
 inter_CF_j1=ev.GetJetCorrFactor(ij->GetIndex());

  }
     
    }
 
 

    TLorentzVector *cJetUncor = new TLorentzVector(ev.JD_Jets().at(jet_index).Px()/ev.GetJetCorrFactor(jet_index), ev.JD_Jets().at(jet_index).Py()/ev.GetJetCorrFactor(jet_index), ev.JD_Jets().at(jet_index).Pz()/ev.GetJetCorrFactor(jet_index), ev.JD_Jets().at(jet_index).E()/ev.GetJetCorrFactor(jet_index));
    et_c_uncor = cJetUncor->Pt();
    CF_c=ev.GetJetCorrFactor(jet_index);

    et_j1_uncor = inter_et_j1_uncor;
    CF_j1 = inter_CF_j1;

    closestJetEt=jetEt; closestJetDR=dRmin;
    
   }
   else{
     et_c_uncor =-999.; 
     CF_c=-999.;
    closestJetEt=-999.; closestJetDR=-999.;
 et_j1_uncor = -999;
    CF_j1 = -999;


   }
  
      if (ev.JD_CommonJets().accepted.size()>=1) {
    const std::vector<const Event::Jet*> & common_jets=ev.JD_CommonJets().accepted;
      for(std::vector<const Event::Jet*>::const_iterator jj=common_jets.begin();
      jj!=common_jets.end();
      ++jj){
      double comdR=fabs(ROOT::Math::VectorUtil::DeltaR ((**ii),(**jj)));
        if (comdR<comdRmin) {
          comdRmin=comdR; comjetEt=(*jj)->Pt();
	  com_jet = (TLorentzVector*)(*jj);
	  com_jet_index=(*jj)->GetIndex();


      }
      if(comdR>0.3 && comdR<unkilled_comdRmin){
	isunkilledjet=true;
	unkilled_comdRmin=comdR; unkilled_comjetEt=(*jj)->Pt();
	uk_jet = (TLorentzVector*)(*jj);
	uk_jet_index=(*jj)->GetIndex();


      }
        

      }
      

 // cout << " index is " << com_jet_index << endl;

 
    TLorentzVector *comcJetUncor = new TLorentzVector(com_jet->Px()/ev.GetJetCorrFactor(com_jet_index), com_jet->Py()/ev.GetJetCorrFactor(com_jet_index), com_jet->Pz()/ev.GetJetCorrFactor(com_jet_index), com_jet->Py()/ev.GetJetCorrFactor(com_jet_index));


    et_comc_uncor = comcJetUncor->Pt();
    CF_comc=ev.GetJetCorrFactor(com_jet_index);
   com_closestJetEt=comjetEt; com_closestJetDR=comdRmin;
    if (isunkilledjet){
  

    TLorentzVector *uk_cJetUncor = new TLorentzVector(uk_jet->Px()/ev.GetJetCorrFactor(uk_jet_index), uk_jet->Py()/ev.GetJetCorrFactor(uk_jet_index), uk_jet->Pz()/ev.GetJetCorrFactor(uk_jet_index), uk_jet->Py()/ev.GetJetCorrFactor(uk_jet_index));
    et_uk_uncor = uk_cJetUncor->Pt();
    CF_uk=ev.GetJetCorrFactor(uk_jet_index);


 
    uk_closestJetEt=unkilled_comdRmin; uk_closestJetDR=unkilled_comjetEt;


    }
    else{
    et_uk_uncor =-999.; 
     CF_uk=-999.;
    uk_closestJetEt=-999.; uk_closestJetDR=-999.;

    }


      }
      else{
    et_comc_uncor =-999.; 
     CF_comc=-999.;
     et_uk_uncor =-999.; 
     CF_uk=-999.;



    com_closestJetEt=-999.; com_closestJetDR=-999.;
    uk_closestJetEt=-999.; uk_closestJetDR=-999.;
   }

      
    




    



    njet_emf_pass=njetemf;
  


    eop=ev.GetElectronESuperClusterOverP(idx);

    dcot=ev.GetElectronDCot(idx);
    dist=ev.GetElectronDist(idx);
    mHits=ev.GetElectronGsfTrackTrackerExpectedHitsInner(idx);
    
    hitFP=ev.GetElectronHasValidHitInFirstPixelBarrel(idx);

    //    ht=ev.CommonHT(); mht=ev.CommonMHT().Pt();

    int iMatch = ev.leptonMatch(*ii,1);
    lepType=ev.leptonType(iMatch);
    gPar=ExtendedType(ev,*ii,1);
    //    cout << "gPar = " << gPar << " and type = " << lepType << endl;
    
    count++;
  
    tree->Fill();
  
      if (count>0) break;
  
  }
  return true;
}

}
