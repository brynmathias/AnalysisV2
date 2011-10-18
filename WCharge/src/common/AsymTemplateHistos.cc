/*
Based on UserCode/Futyan/macros/WenuTemplateFit.cc
See WCharge/scripts/genTemplates.py for an example of how to run the code.
*/

#include "AsymTemplateHistos.hh"
#include "KinSuite.hh"
#include <fstream>

using namespace std;
//using namespace Event;

AsymTemplateHistos::AsymTemplateHistos(const std::string & folderName,
Utils::ParameterSet &pset
):
mFolderName(folderName)
{
    jet_ET       = pset.Get<double>("jet_ET");

    lep_ET       = pset.Get<double>("lep_ET");
    lep_VetoET   = pset.Get<double>("lep_VetoET");
    lep_MT       = pset.Get<double>("lep_MT");

    lep_WP       = pset.Get<int>("lep_WP");
    lep_VetoWP   = pset.Get<int>("lep_VetoWP");
    lep_AntiWP   = pset.Get<int>("lep_AntiWP");

    lep_AntiDPhi_eb = pset.Get<double>("lep_AntiDPhi_eb");
    lep_AntiDEta_eb = pset.Get<double>("lep_AntiDEta_eb");
    lep_AntiDPhi_ee = pset.Get<double>("lep_AntiDPhi_ee");
    lep_AntiDEta_ee = pset.Get<double>("lep_AntiDEta_ee");

    lep_QCheck   = pset.Get<bool>("lep_QCheck");

    for (int ieff = 0; ieff<6;ieff++){
        TString eff = "_";
        eff+=ieff;
        lep_MissHits[ieff] = pset.Get<int>("lep_MissHits"+wp[ieff]);
        lep_DCot[ieff]     = pset.Get<double>("lep_DCot"+wp[ieff]);
        lep_Dist[ieff]     = pset.Get<double>("lep_Dist"+wp[ieff]);

        lep_Trk_eb[ieff]   = pset.Get<double>("lep_Trk_eb"+wp[ieff]);
        lep_Ecal_eb[ieff]  = pset.Get<double>("lep_Ecal_eb"+wp[ieff]);
        lep_Hcal_eb[ieff]  = pset.Get<double>("lep_Hcal_eb"+wp[ieff]);
        lep_sihih_eb[ieff] = pset.Get<double>("lep_sihih_eb"+wp[ieff]);
        lep_Dphi_eb[ieff]  = pset.Get<double>("lep_Dphi_eb"+wp[ieff]);
        lep_Deta_eb[ieff]  = pset.Get<double>("lep_Deta_eb"+wp[ieff]);
        lep_HoE_eb[ieff]   = pset.Get<double>("lep_HoE_eb"+wp[ieff]);

        lep_Trk_ee[ieff]   = pset.Get<double>("lep_Trk_ee"+wp[ieff]);
        lep_Ecal_ee[ieff]  = pset.Get<double>("lep_Ecal_ee"+wp[ieff]);
        lep_Hcal_ee[ieff]  = pset.Get<double>("lep_Hcal_ee"+wp[ieff]);
        lep_sihih_ee[ieff] = pset.Get<double>("lep_sihih_ee"+wp[ieff]);
        lep_Dphi_ee[ieff]  = pset.Get<double>("lep_Dphi_ee"+wp[ieff]);
        lep_Deta_ee[ieff]  = pset.Get<double>("lep_Deta_ee"+wp[ieff]);
        lep_HoE_ee[ieff]   = pset.Get<double>("lep_HoE_ee"+wp[ieff]);
    }
    ZDat = pset.Get<std::string>("ZDat_file");
    ZMC  = pset.Get<std::string>("ZMC_file");
    WNew = pset.Get<std::string>("W_file");
    doRecoil = pset.Get<bool>("do_recoil");
  	if (doRecoil)
        corrector = new RecoilCorrector(ZDat,ZMC,WNew,123456) ;
}


void AsymTemplateHistos::Start(Event::Data & ev) {
	initDir(ev.OutputFile(), mFolderName.c_str());
	BookHistos();
}
AsymTemplateHistos::~AsymTemplateHistos() {
  	if (doRecoil)
        delete corrector;
}

/*
~~~BOOK HISTOS~~~
*/
void  AsymTemplateHistos::BookHistos() {
	int nBins = 100;

    //Met shapes for Gautier and Micheal
    TString metl = "h_met";
    TString mtl = "h_mt";
    h_met = new TH1F(metl,metl,nBins,0,100.);
    h_mt =  new TH1F(mtl,mtl,nBins,0,100.);

    //Template shapes for Asym vs Eta
	for (int ih=0;ih<EtaChBins_;ih++){
        TString sel          = "h_eta_pfMET"+etabin[ih];
        TString antisel      = "h_eta_anti_pfMET"+etabin[ih];
        h_eta_sel[ih]       = new TH1F(sel,sel,nBins,0,100.);
        h_eta_antisel[ih]   = new TH1F(antisel,antisel,nBins,0,100.);
    }   
    //Template shapes for Asym vs Wpt
	for (int ih=0;ih<WptChBins_;ih++){
        TString sel           = "h_wpt_pfMET"+wptbin[ih];
        TString antisel       = "h_wpt_anti_pfMET"+wptbin[ih];
        h_wpt_sel[ih]    = new TH1F(sel,sel,nBins,0,100.);
        h_wpt_antisel[ih]= new TH1F(antisel,antisel,nBins,0,100.);	 
	}  
    //Template shapes for Asym vs nJets 
	for (int ih=0;ih<JetChBins_;ih++){
        TString sel= "h_jet_pfMET"+jetbin[ih];
        TString antisel= "h_jet_anti_pfMET"+jetbin[ih];
        h_jet_sel[ih]    = new TH1F(sel,sel,nBins,0,100.);
        h_jet_antisel[ih]= new TH1F(antisel,antisel,nBins,0,100.);	 
	}  
}
/*
~~~PROCESS~~~
*/
bool AsymTemplateHistos::Process(Event::Data & ev) {
	w=ev.GetEventWeight();
	double met = ev.PFMET().Pt();
	double met_phi = ev.PFMET().Phi();
//MET CORRECTION HERE TODO
	int nSel=0;
	int nSelVeto=0;
	int nAntiSel=0;

	std::vector<Lepton const *>::const_iterator goodLep;
	std::vector<Lepton const *>::const_iterator antiLep;


    //loop over all jets and find njets
    int nJet = 0;

	for (std::vector<Jet const *>::const_iterator jet=ev.JD_CommonJets().accepted.begin();
         jet != ev.JD_CommonJets().accepted.end();
         ++jet) {
        //int i = (*jet)->GetIndex();
		//double eta = (*jet)->Eta();
		double et  = (*jet)->Et();
        if (et>jet_ET) nJet++;
    }

	for (std::vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin(); 
         lep != ev.LD_CommonElectrons().accepted.end(); 
         ++lep) {
		//Selection
		int i = (*lep)->GetIndex();	
		double eta = (*lep)->Eta();
		double et  = (*lep)->Et();

        double mt =  sqrt(2)*sqrt(
                     (*lep)->Pt()*met
                    -(*lep)->Pt()*met*cos(met_phi-(*lep)->Phi()
        ));
        if (mt<lep_MT) continue;
		if (!fid(eta)) continue;

        bool chargeOk = (lep_QCheck) ?
                        (((*lep)->GetCharge()==ev.GetElectronSCCharge(i)) && 
                        ((*lep)->GetCharge()==ev.GetElectronKFCharge(i)), lep_WP) : true;
        bool convOk = passConv(ev.GetElectronGsfTrackTrackerExpectedHitsInner(i) ,
                                ev.GetElectronDCot(i),
                                ev.GetElectronDist(i),lep_WP ); 
        bool iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(),
                                 (*lep)->GetEcalIsolation()/(*lep)->Pt(),
                                 (*lep)->GetHcalIsolation()/(*lep)->Pt(),eta,lep_WP);
        bool id = passID(ev.GetElectronSigmaIetaIeta(i),
                         ev.GetElectronDeltaPhiAtVtx(i),
                         ev.GetElectronDeltaEtaAtVtx(i),
                         ev.GetElectronHoE(i),eta,lep_WP);
        //TODO VETO 
        bool veto_convOk =passConv(ev.GetElectronGsfTrackTrackerExpectedHitsInner(i),
                                    ev.GetElectronDCot(i), 
                                    ev.GetElectronDist(i), lep_VetoWP); 
        bool veto_iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(), 
                                      (*lep)->GetEcalIsolation()/(*lep)->Pt(),
                                      (*lep)->GetHcalIsolation()/(*lep)->Pt(),eta,lep_VetoWP);
        bool veto_id = passID(ev.GetElectronSigmaIetaIeta(i),
                              ev.GetElectronDeltaPhiAtVtx(i), ev.GetElectronDeltaEtaAtVtx(i),
                              ev.GetElectronHoE(i),eta,lep_VetoWP);
		
		if (iso && id && chargeOk && convOk){
			if (et>lep_ET){
					nSel++;
					goodLep=lep;
            }
		}
		if (veto_iso && veto_id && veto_convOk){
			if (et >lep_VetoET) nSelVeto++;
		}

		bool anti_convOk = true;//(convChk) ? (passConv(ev.GetElectronGsfTrackTrackerExpectedHitsInner(i) , ev.GetElectronDCot(i), ev.GetElectronDist(i), 0) ) : true; //Removed cut
		bool anti_iso = passIsolation((*lep)->GetTrkIsolation()/(*lep)->Pt(),
                                      (*lep)->GetEcalIsolation()/(*lep)->Pt(), 
                                      (*lep)->GetHcalIsolation()/(*lep)->Pt(),eta,lep_AntiWP);//WP80
		bool anti_id = passID(0., 0., 0., ev.GetElectronHoE(i),eta,lep_AntiWP);//WP80 //only HoE
		bool pass_dfi = passID_AS (ev.GetElectronDeltaPhiAtVtx(i), 0., eta);
		bool pass_dhi = passID_AS (0., ev.GetElectronDeltaEtaAtVtx(i), eta);
    
        if (et>lep_ET){
            if (anti_convOk && anti_iso && anti_id && (!pass_dfi) && (!pass_dhi)){
                nAntiSel++;
                antiLep=lep;
            }
		}
	}

    if (nSel==0&&nAntiSel==0) return false;
    if (doRecoil){
        std::vector<Event::GenObject > boson;
        for (std::vector<Event::GenObject>::const_iterator  j = ev.GenParticles().begin();
	                                                        j != ev.GenParticles().end();
                                                           ++j) { 
            if (j->GetStatus()==3){                           //All stable particles
	            int ID = abs(j->GetID());
                if (ID==24){//W bosons
	                boson.push_back(*j);
	            }//End if
            }//End If
        }//End Gen Loop
        //cout<<">>> met: "<<met<<endl;
        if (boson.size()>=0){
            if (nSel==1)
                 corrector->Correct(met,met_phi,boson.at(0).Pt(),boson.at(0).Phi(),(*goodLep)->Pt(),(*goodLep)->Phi());
            else if (nAntiSel==1)
                 corrector->Correct(met,met_phi,boson.at(0).Pt(),boson.at(0).Phi(),(*antiLep)->Pt(),(*antiLep)->Phi());
        }
        //cout<<"met cor: "<<met<<endl;
    }
    if ((nSel==1)&&(nSelVeto==1)){
        double mt =  sqrt(2)*sqrt(
                     (*goodLep)->Pt()*met
                    -(*goodLep)->Pt()*met*cos(met_phi-(*goodLep)->Phi()
        ));
        int ih = getEta(goodLep);	
        int iwpt = getWpt(goodLep,met,met_phi);
        int ijet = getJet(goodLep,nJet);
        if (fabs((*goodLep)->Eta())<1.5){  
            h_met->Fill(met,w);
            h_mt->Fill(mt,w);
        }
        if (ih>=0) h_eta_sel[ih]->Fill(met,w);
        if (iwpt>=0) h_wpt_sel[iwpt]->Fill(met,w);
        if (ijet>=0) h_jet_sel[ijet]->Fill(met,w);
        return true;
    }
    if (nAntiSel==1){
        int ih = getEta(antiLep);	
        int iwpt = getWpt(antiLep,met,met_phi);
        int ijet = getJet(antiLep,nJet);
        if (ih>=0) h_eta_antisel[ih]->Fill(met,w);
        if (iwpt>=0) h_wpt_antisel[iwpt]->Fill(met,w);
        if (ijet>=0) h_jet_antisel[ijet]->Fill(met,w);
        return true;
    }
	return false;
} // end of Process method

std::ostream& AsymTemplateHistos::Description(std::ostream &ostrm) {
	ostrm << "AsymTemplateHistos plots made here: (histograms in ";
	ostrm << mFolderName << ")";
	return ostrm;
}

bool AsymTemplateHistos::passIsolation (double track, double ecal, double hcal, double eta, int ieff)
{
  return CheckCuts(track, ecal, hcal, 0., 0., 0., 0.,  eta, ieff ); 
}

bool AsymTemplateHistos::passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff)
{
  return CheckCuts(0., 0., 0., sihih, dfi, dhi, hoe,  eta, ieff );
}

bool AsymTemplateHistos::passConv (int v_missHits, double v_DCot, double v_Dist, int ieff)
{
	if ((v_missHits <= lep_MissHits[ieff]) && 
			(fabs(v_DCot) > lep_DCot[ieff] || fabs(v_Dist) >  lep_Dist[ieff]) ) return true;
	return false;
}

bool AsymTemplateHistos::passID_AS(double v_dfi, double v_dhi, double eta){
	if (fabs(eta)< 1.479) {	  
		if (fabs(v_dfi)<lep_AntiDPhi_eb && fabs(v_dhi)<lep_AntiDEta_eb) return true;
	}
	else {
		if (fabs(v_dfi)<lep_AntiDPhi_ee && fabs(v_dhi)<lep_AntiDEta_ee) return true;
	}
	return false;
}

bool AsymTemplateHistos::fid(double eta) {
	return  (fabs(eta)<2.4 && (  fabs(eta) < 1.4  || fabs(eta) > 1.6 ));//(  fabs(eta) < 1.4442  || fabs(eta) > 1.56 ));
}

int AsymTemplateHistos::getEta(std::vector<Lepton const *>::const_iterator lep){
	double eta= (*lep)->Eta();
	double charge = (*lep)->GetCharge();
	//double pt= (*lep)->Pt();
	bool acc= (((fabs(eta)<1.6)&&(fabs(eta)>1.4))|| (fabs(eta)>2.4));
	bool cha = (charge==0);
	int ih = -1;
	for (int ieta=0;ieta<EtaBins;ieta++){ 
		if (fabs(eta)<etabinup[ieta]){
			ih = ieta; 
			break;
		}
	}
	if (ih < 0) return -1; // no eta bin found
	if (cha)    return -1;
	if (acc)    return -1;
	if (charge<0) ih+=EtaBins; // positive bins go 0,1,2,3,4,5, negative go 6,7,8,9,10,11
	//cout<<"test:"<<ih<<endl;
	return ih;
}

int AsymTemplateHistos::getWpt(std::vector<Lepton const *>::const_iterator lep, double met, double met_phi){
	double charge = (*lep)->GetCharge();
	double pt= (*lep)->Pt();
	int wpt = -1;
	for (int iwpt=0;iwpt<WptBins;iwpt++){ 
		double measured_Wpt = sqrt(met*met+pt*pt+pt*met*cos(met_phi-(*lep)->Phi()));
		if (measured_Wpt>wptbinlow[iwpt]){
			wpt = iwpt; // note: no +1 since we do not have an inclusive bin here
			//note : no break since these are the lower bin edges
		}
	}
	if (wpt < 0) return -1; // no wpt bin found (should be impossible)
	if (charge<0) wpt+=WptBins; // positive bins go 0,1,2,3,4, negative go 5,6,7,8,9	
	return wpt;
}

int AsymTemplateHistos::getJet(std::vector<Lepton const *>::const_iterator lep,int nJet){
	double charge = (*lep)->GetCharge();
	int ijet = nJet;
	if (nJet < 0) return -1; // no ijet bin found 
	if (nJet > JetBins-1) return -1; //unlikely
	if (charge<0) ijet+=JetBins; // positive bins go 0,1,2,3,4, negative go 5,6,7,8,9	
	return ijet;
}
bool AsymTemplateHistos::CheckCuts(double v_trk, double v_ecal, double v_hcal, 
double v_sihih, double v_dfi, double v_dhi, double v_hoe,
double eta, int ieff){
	if (fabs(eta)< 1.479) {	  
		if (
				v_trk  <  lep_Trk_eb[ieff]    && 
				v_ecal <  lep_Ecal_eb[ieff]   &&
				v_hcal <  lep_Hcal_eb[ieff]   &&
				v_sihih < lep_sihih_eb[ieff]  &&
				fabs(v_dfi) < lep_Dphi_eb[ieff]   &&
				fabs(v_dhi) < lep_Deta_eb[ieff]   &&
				fabs(v_hoe)< lep_HoE_eb[ieff]    
				) return true;
	}
	else {
		if (v_trk <  lep_Trk_ee[ieff] && 
				v_ecal < lep_Ecal_ee[ieff] &&
				v_hcal < lep_Hcal_ee[ieff] &&
				v_sihih <lep_sihih_ee[ieff] &&
				fabs(v_dfi) <lep_Dphi_ee[ieff] &&
				//MICHELE DA SCOMMENTARE   
				fabs(v_dhi) <lep_Deta_ee[ieff] &&
				fabs(v_hoe)< lep_HoE_ee[ieff] 
				) return true;
	}
	return false;
}

