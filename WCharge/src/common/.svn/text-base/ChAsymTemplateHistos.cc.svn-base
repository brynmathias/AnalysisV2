/*
Based on UserCode/Futyan/macros/WenuTemplateFit.cc
See WCharge/scripts/genTemplates.py for an example of how to run the code.
*/

#include "ChAsymTemplateHistos.hh"
#include "KinSuite.hh"
#include <fstream>

using namespace std;
//using namespace Event;

ChAsymTemplateHistos::ChAsymTemplateHistos(const std::string & folderName,
Utils::ParameterSet &pset
):
mFolderName(folderName)
{
  elecET     = pset.Get<double>("ElecET");
  chChk      = pset.Get<bool>("ChCheck");
  lepPtVeto  = pset.Get<double>("ElePtVeto");
  convChk    = pset.Get<bool>("ConvCheck");
  lepVeto    = pset.Get<bool>("EleVeto");	
  wp         = pset.Get<int>("WorkingPoint");
  scEta      = pset.Get<bool>("UseSCEta");
  scEnergy   = pset.Get<bool>("UseSCEnergy");

  //(0=95%,1=90%,2=85%,3=80%,4=70%,5=60%)
  ieff=-1;
  if (wp==95) ieff=0;
  if (wp==90) ieff=1;
  if (wp==85) ieff=2;
  if (wp==80) ieff=3;
  if (wp==70) ieff=4;
  if (wp==60) ieff=5;
  if (ieff<0){
    cout<<"Working point "<<wp<<" unknown"<<endl
    <<"Working points accepted are 60,70,80,85,90,95"<<endl
    <<"Job is going to stop"<<endl;
    assert(0);
  } 
  //mMissingHits=0;
  //mDCot=0.02;
  //mDist=0.02;
}

void ChAsymTemplateHistos::Start(Event::Data & ev) {
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
}
ChAsymTemplateHistos::~ChAsymTemplateHistos() {

}

/*
~~~BOOK HISTOS~~~
*/
void  ChAsymTemplateHistos::BookHistos() {
  int nBins = 100;
  for (int ih=0;ih<EtaChBins;ih++){
    TString sel= "h_pfMET"+suff[ih];
    h_sel[ih]= new TH1F(sel,sel,nBins,0,100.);
    for (int iav=0;iav<AntiEvBins;iav++){
      TString dfi= "h_dfi_pfMET"+AV[iav]+suff[ih];
      TString dhi= "h_dhi_pfMET"+AV[iav]+suff[ih];
      TString dfidhi= "h_dfi_dhi_pfMET"+AV[iav]+suff[ih];
      h_dfi[ih][iav]= new TH1F(dfi,dfi,nBins,0,100.);
      h_dhi[ih][iav]= new TH1F(dhi,dhi,nBins,0,100.);
      h_dfi_dhi[ih][iav]= new TH1F(dfidhi,dfidhi,nBins,0,100.);
    }  
  }   
}
/*
~~~PROCESS~~~
*/
bool ChAsymTemplateHistos::Process(Event::Data & ev) {
  w=ev.GetEventWeight();
  double event_pfMET= ev.PFMET().Pt();
  
  //ONLY 1 GOOD ELECTRON && VETO ON THE SECOND 
  int ngoodEle=0;
  int ngoodEleVeto=0;
  std::vector<Lepton const *>::const_iterator goodLep;

  //ANTI EVENT SELECTION
  int nbadEledfi[AntiEvBins]={0,0,0,0,0,0,0};
  int nbadEledhi[AntiEvBins]={0,0,0,0,0,0,0};
  int nbadEledfidhi[AntiEvBins]={0,0,0,0,0,0,0};
   
  std::vector<Lepton const *>::const_iterator dfiLep[AntiEvBins];
  std::vector<Lepton const *>::const_iterator dhiLep[AntiEvBins];
  std::vector<Lepton const *>::const_iterator dfidhiLep[AntiEvBins];
  for (std::vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
  lep != ev.LD_CommonElectrons().accepted.end();
  ++lep) {
    //Selection
    int i = (*lep)->GetIndex();	
    double eta = (scEta)    ? ev.GetElectronESuperClusterEta(i) : (*lep)->Eta();
    //double Et  = (scEnergy) ? ev.GetElectronESuperClusterOverP(i)*ev.GetElectronTrkPt(i) : (*lep)->Et();
    double Et  = (scEnergy) ? ev.GetElectronEcalEnergy(i)/cosh(eta) : (*lep)->Et();
    
    if (!fid(eta)) continue;
    bool chargeOk = (chChk) ? (((*lep)->GetCharge()==ev.GetElectronSCCharge(i)) && ((*lep)->GetCharge()==ev.GetElectronKFCharge(i))) : true;
    bool convOk = (convChk) ? (passConv(ev.GetElectronGsfTrackTrackerExpectedHitsInner(i) , ev.GetElectronDCot(i), ev.GetElectronDist(i), ieff) ) : true; 
    bool iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(), (*lep)->GetEcalIsolation()/(*lep)->Pt(), (*lep)->GetHcalIsolation()/(*lep)->Pt(),eta,ieff);
    bool id = passID(ev.GetElectronSigmaIetaIeta(i), ev.GetElectronDeltaPhiAtVtx(i), ev.GetElectronDeltaEtaAtVtx(i), ev.GetElectronHoE(i),eta,ieff);
  
    bool veto_convOk = (convChk) ? (passConv(ev.GetElectronGsfTrackTrackerExpectedHitsInner(i) , ev.GetElectronDCot(i), ev.GetElectronDist(i), 0) ) : true; 
    bool veto_iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(), (*lep)->GetEcalIsolation()/(*lep)->Pt(), (*lep)->GetHcalIsolation()/(*lep)->Pt(),eta,0);
    bool veto_id = passID(ev.GetElectronSigmaIetaIeta(i), ev.GetElectronDeltaPhiAtVtx(i), ev.GetElectronDeltaEtaAtVtx(i), ev.GetElectronHoE(i),eta,0);
    
    if (iso && id && chargeOk && convOk){
      if (Et>elecET){
        ngoodEle++;
        goodLep=lep;
      }
    }
    if (veto_iso && veto_id && veto_convOk){
      if (Et>lepPtVeto) ngoodEleVeto++;
    }
       
//      David's anti-selection
//       Pass WP80 :
// 	  no Conversion rejection
// 	  All Isolation cuts
// 	  Electron ID (only H/E cut)
//       Anti WP90/85 (Deta/Dphi)
//       Deta > 0.007/0.009 (EB/EE)
//       Dphi > 0.06/0.04  (EB/EE)
    bool AS_convOk = true;//(convChk) ? (passConv(ev.GetElectronGsfTrackTrackerExpectedHitsInner(i) , ev.GetElectronDCot(i), ev.GetElectronDist(i), 0) ) : true; //Removed cut
    bool AS_iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(), (*lep)->GetEcalIsolation()/(*lep)->Pt(), (*lep)->GetHcalIsolation()/(*lep)->Pt(),eta,3);//3 = WP80
    bool AS_id = passID(0., 0., 0., ev.GetElectronHoE(i),eta,3);//3 = WP80 //only HoE
    
    if (Et>elecET){ 
      for (int iav=0;iav<AntiEvBins;iav++){ 
        bool pass_dfi = passID_AS (ev.GetElectronDeltaPhiAtVtx(i), 0., eta ,iav);
        bool pass_dhi = passID_AS (0., ev.GetElectronDeltaEtaAtVtx(i), eta ,iav);
        if ((!pass_dfi)){ 
          nbadEledfi[iav]++;
          dfiLep[iav]=lep;
        }
        if (AS_convOk && AS_iso && AS_id && (!pass_dhi)){
          nbadEledhi[iav]++;
          dhiLep[iav]=lep;
        }
        if (AS_convOk && AS_iso && AS_id && (!pass_dfi) && (!pass_dhi)){
          nbadEledfidhi[iav]++;
          dfidhiLep[iav]=lep;
        }
      }
    }
  }
  
  TDirectory *currentDirectory= ev.OutputFile()->GetDirectory(mFolderName.c_str());
  
  //FOUND 1 GOOD LEPTON
  if ((ngoodEle==1)&&(ngoodEleVeto==1)){
    FillHistos("h_pfMET",currentDirectory,event_pfMET,goodLep) ;
    //cout<<"RUN= "<<ev.RunNumber()<<" LUMIS= "<<ev.LumiSection()<<" EVENT= "<<ev.EventNumber()<<endl;
    return true;
  }
  else{
    bool retval = false;
    for (int iav=0;iav<AntiEvBins;iav++){
      if(nbadEledfi[iav]==1)     FillHistos("h_dfi_pfMET"+AV[iav],currentDirectory,event_pfMET,dfiLep[iav]);
      if(nbadEledhi[iav]==1)     FillHistos("h_dhi_pfMET"+AV[iav],currentDirectory,event_pfMET,dhiLep[iav]);
      if(nbadEledfidhi[iav]==1)  FillHistos("h_dfi_dhi_pfMET"+AV[iav],currentDirectory,event_pfMET,dfidhiLep[iav]) ;
      if ( (nbadEledfi[iav]==1) || (nbadEledhi[iav]==1) || (nbadEledfidhi[iav]==1) ) retval = true; //true means that this event is used as data or for antisection
    }
    return retval;
  }
  return false;
} // end of Process method

std::ostream& ChAsymTemplateHistos::Description(std::ostream &ostrm) {
  ostrm << "ChAsymTemplateHistos plots made here: (histograms in ";
  ostrm << mFolderName << ")";
  return ostrm;
}

bool ChAsymTemplateHistos::passIsolation (double track, double ecal, double hcal, double eta, int ieff)
{
  return CheckCuts(track, ecal, hcal, 0., 0., 0., 0.,  eta, ieff ); 
}

bool ChAsymTemplateHistos::passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff)
{
  return CheckCuts(0., 0., 0., sihih, dfi, dhi, hoe,  eta, ieff );
}

bool ChAsymTemplateHistos::passConv (int v_missHits, double v_DCot, double v_Dist, int ieff)
{
  if ((v_missHits <= MissHits[ieff]) && 
      (fabs(v_DCot) > DCot[ieff] || fabs(v_Dist) >  Dist[ieff]) ) return true;
  return false;
}

bool ChAsymTemplateHistos::passID_AS(double v_dfi, double v_dhi, double eta, int ieff){
  if (fabs(eta)< 1.479) {	  
    if (
        fabs(v_dfi) < Dphi[ieff] && fabs(v_dhi) < Deta[ieff] ) return true;
  }
  else {
    if (fabs(v_dfi) < Dphi_ee[ieff] && fabs(v_dhi) < Deta_ee[ieff] ) return true;
  }
  return false;
}

void ChAsymTemplateHistos::FillHistos(TString Prefix,TDirectory *Dir, double met,std::vector<Lepton const *>::const_iterator lep){
  double eta= (*lep)->Eta();
  double charge = (*lep)->GetCharge();
  double pt= (*lep)->Pt();
  bool acc= (((fabs(eta)<1.56)&&(fabs(eta)>1.44))|| (fabs(eta)>2.4));
  bool cha = (charge==0);
  if (!cha && !acc){
    TH1F *h1;
    Dir->GetObject(Prefix,h1);
    h1->Fill(met,w);
    
    Dir->GetObject(Prefix+Suffix(eta,charge,pt),h1);
    h1->Fill(met,w);

    Dir->GetObject(Prefix+Suffix(eta,charge,pt,1),h1);
    h1->Fill(met,w);
    
    Dir->GetObject(Prefix+Suffix(eta,charge,pt,2),h1);
    h1->Fill(met,w);

  }
}
TString ChAsymTemplateHistos::Suffix(double probe_sc_eta, double probe_charge, double pt, int Option){

  TString suff="";
  if      ((fabs(probe_sc_eta)<0.4)&&(fabs(probe_sc_eta)>0.0))  suff = "_eta1";
  else if ((fabs(probe_sc_eta)<0.8)&&(fabs(probe_sc_eta)>0.4))  suff = "_eta2";
  else if ((fabs(probe_sc_eta)<1.2)&&(fabs(probe_sc_eta)>0.8))  suff = "_eta3";
  else if ((fabs(probe_sc_eta)<1.6)&&(fabs(probe_sc_eta)>1.2))  suff = "_eta4";
  else if ((fabs(probe_sc_eta)<2.0)&&(fabs(probe_sc_eta)>1.6))  suff = "_eta5";
  else if ((fabs(probe_sc_eta)<2.4)&&(fabs(probe_sc_eta)>2.0))  suff = "_eta6";

  if (suff==""){
    cout<<"ETA-Charge bin does not exist"<<endl;
    assert(0);
  }

  if (probe_charge>0) suff+="_pos";
  if (probe_charge<0) suff+="_neg";

  if ((Option==1) &&(probe_sc_eta>0)) suff+="_P";
  if ((Option==1) &&(probe_sc_eta<0)) suff+="_M";

  if ((Option==2) &&(pt<35.)) suff+="_pt1";
  if ((Option==2) &&(pt>=35.)) suff+="_pt2";
    
  return suff;
}

bool ChAsymTemplateHistos::fid(double eta) {
  return  (fabs(eta)<2.4 && (  fabs(eta) < 1.4442  || fabs(eta) > 1.56 ));
}

bool ChAsymTemplateHistos::CheckCuts(double v_trk, double v_ecal, double v_hcal, 
				     double v_sihih, double v_dfi, double v_dhi, double v_hoe,
				     double eta, int ieff){
  if (fabs(eta)< 1.479) {	  
    if (
        v_trk  <  Trk[ieff]    && 
        v_ecal <  Ecal[ieff]   &&
        v_hcal <  Hcal[ieff]   &&
        v_sihih < sihih[ieff]  &&
        fabs(v_dfi) < Dphi[ieff]   &&
        fabs(v_dhi) < Deta[ieff]   &&
        fabs(v_hoe)< HoE[ieff]    
        ) return true;
  }
  else {
    if (v_trk <  Trk_ee[ieff] && 
        v_ecal < Ecal_ee[ieff] &&
        v_hcal < Hcal_ee[ieff] &&
        v_sihih <sihih_ee[ieff] &&
        fabs(v_dfi) <Dphi_ee[ieff] &&
        //MICHELE DA SCOMMENTARE   
        fabs(v_dhi) <Deta_ee[ieff] &&
        fabs(v_hoe)< HoE_ee[ieff] 
        ) return true;
  }
  return false;
}

