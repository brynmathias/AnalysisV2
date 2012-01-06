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
    doTP = pset.Get<bool>("do_TP");
    doRecoilNtuple = pset.Get<bool>("do_RecoilNtuple");
    recType = pset.Get<int>("rec_Type");
    ZDat = pset.Get<std::string>("ZDat_File");
    ZMC  = pset.Get<std::string>("ZMC_File");
    WNew = pset.Get<std::string>("W_File");
    doRecoil = pset.Get<bool>("do_Recoil");
  	if (doRecoil){
        corrector = new RecoilCorrector(WNew);
        corrector->addMCFile(ZMC);
        corrector->addDataFile(ZDat);
    }
}


void AsymTemplateHistos::Start(Event::Data & ev) {
    if (doRecoilNtuple){
	    //TString outFileName("test_" + ev.OutputFile());
        //treeFile = TFile::Open( outFileName, "RECREATE" );
        ev.OutputFile()->cd(); 
        iTree = new TTree("FitRecoil","FitRecoil");
        SetTree(iTree);
    }
	initDir(ev.OutputFile(), mFolderName.c_str());
	BookHistos();
}
void AsymTemplateHistos::End(Event::Data & ev) {
    // Apparently not needed. if you create a ttree in a tfile, when you close
    // the tfile the ttree is automaticaly written...
  	//if (doRecoilNtuple){
    //    ev.OutputFile()->cd(); 
    //    iTree->Write("name");
    //}
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
        TString sel         = "h_eta_pfMET"+etabin[ih];
        TString antisel     = "h_eta_anti_pfMET"+etabin[ih];
        h_eta_sel[ih]       = new TH1F(sel,sel,nBins,0,100.);
        h_eta_antisel[ih]   = new TH1F(antisel,antisel,nBins,0,100.);
        TString s_TP        = "h_TP"+etabin[ih];
        TString s_TPS       = "h_TPS"+etabin[ih];
        TString s_TPC       = "h_TPC"+etabin[ih];
        h_TP[ih]            = new TH1F(s_TP,s_TP,60,60.,120.);
        h_TPS[ih]           = new TH1F(s_TPS,s_TPS,60,60.,120.);
        h_TPC[ih]           = new TH1F(s_TPC,s_TPC,60,60.,120.);
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

   h_TP_all = new TH1F("h_TP_all","TP_all",60,60.,120.);
   h_TPS_all = new TH1F("h_TPS_all","TPS_all",60,60.,120.);
   h_TPC_all = new TH1F("h_TPC_all","TPC_all",60,60.,120.);

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

//	std::vector<Lepton const *>::const_iterator goodLep;
//	std::vector<Lepton const *>::const_iterator antiLep;

    std::vector<Lepton const *> goodLep;  //define Electron Container
    std::vector<Lepton const *> antiLep;  //define Electron Container

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
					//goodLep=lep;
					goodLep.push_back(*lep);
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
	//	bool pass_dfi = passID_AS (ev.GetElectronDeltaPhiAtVtx(i), 0., eta);
		bool pass_dhi = passID_AS (0., ev.GetElectronDeltaEtaAtVtx(i), eta);
        bool pass_upper_dhi = fabs(ev.GetElectronDeltaEtaAtVtx(i))<0.02;
                                    // ^ Additional cut futyan requires         
        if (et>lep_ET){
            if (anti_convOk && anti_iso && anti_id 
            && (!pass_dhi) && pass_upper_dhi){
                nAntiSel++;
                //antiLep=lep;
		        antiLep.push_back(*lep);
            }
		}
	}

    if (nSel==0&&nAntiSel==0) {
        return false;
    }
    if (doRecoil){//Correct recoil
        std::vector<Event::GenObject > boson;
        int nBosons = 0;
        for (std::vector<Event::GenObject>::const_iterator  j = ev.GenParticles().begin();
	                                                        j != ev.GenParticles().end();
                                                           ++j) { 
            if (j->GetStatus()==3){                           //All stable particles
	            int ID = abs(j->GetID());
                if (ID==24){//W bosons
	                boson.push_back(*j);
                    nBosons++;
	            }//End if
            }//End If
        }//End Gen Loop
        //cout<<">>> met: "<<met<<endl;
        //cout<<"nBosons = "<<nBosons<<endl;
        if (boson.size()>0){
            double pfU1 = 0.;
            double pfU2 = 0.;
            if (nSel>=1){
                corrector->CorrectAll(met,met_phi,
                                  boson.at(0).Pt(),boson.at(0).Phi(),
                                  goodLep.at(0)->Pt(),goodLep.at(0)->Phi(),
                                  pfU1,pfU2, 0.);
            }
            else if (nAntiSel>=1){
                corrector->CorrectAll(met,met_phi,
                                  boson.at(0).Pt(),boson.at(0).Phi(),
                                  antiLep.at(0)->Pt(),antiLep.at(0)->Phi(),
                                  pfU1,pfU2, 0.);
            }
        }
        else{
            return false;
            cout<<"no boson"<<endl;
        }
        //cout<<"met cor: "<<met<<endl;
    }

    if (doRecoilNtuple && nSel>=1){// Fill ntuple for Recoil Fitting

        TVector2 * pfMET = new TVector2(0.,0.);
        pfMET->SetMagPhi(ev.PFMET().Pt(),ev.PFMET().Phi());
        TVector2 * trkMET = new TVector2(0.,0.);
        trkMET->SetMagPhi(ev.TCMET().Pt(),ev.TCMET().Phi());

        if (nSel==2 && recType ==0 ){// Z data
            //select a Z
            TLorentzVector elec1,elec2,Z,gen;
            double invariantMass = 0.0;
            elec1.SetPtEtaPhiM(goodLep.at(0)->Et(),goodLep.at(0)->Eta(),goodLep.at(0)->Phi(),0.);
            elec2.SetPtEtaPhiM(goodLep.at(1)->Et(),goodLep.at(1)->Eta(),goodLep.at(1)->Phi(),0.);
            Z = (elec1+elec2);
            invariantMass = Z.M();
            if (invariantMass<120. && invariantMass>60. ) {
                TVector2 electron1, electron2, sumLepton;
                electron1.SetMagPhi(goodLep.at(0)->Et(),goodLep.at(0)->Phi());
                electron2.SetMagPhi(goodLep.at(1)->Et(),goodLep.at(1)->Phi());
                sumLepton = electron1+electron2;
                SetTreeVariables(&Z, &Z, &sumLepton, pfMET, trkMET, w, nJet, iTree);
                delete pfMET;
                delete trkMET; 
                return true;
            }
        }

        if (nSel==2 && recType ==1 ){// Z MC
            std::vector<Event::GenObject > boson;
            for (std::vector<Event::GenObject>::const_iterator  j = ev.GenParticles().begin();
                 j != ev.GenParticles().end(); ++j) { 
                if (j->GetStatus()==3 && abs(j->GetID())==23){ //All stable Z
                    boson.push_back(*j);
                }
            }
            if (boson.size()>0){
                TLorentzVector elec1,elec2,Z,gen;
                double invariantMass = 0.0;
                elec1.SetPtEtaPhiM(goodLep.at(0)->Et(),goodLep.at(0)->Eta(),goodLep.at(0)->Phi(),0.);
                elec2.SetPtEtaPhiM(goodLep.at(1)->Et(),goodLep.at(1)->Eta(),goodLep.at(1)->Phi(),0.);
                Z = (elec1+elec2);
                gen.SetPtEtaPhiM(boson.at(0).Pt(),boson.at(0).Eta(),boson.at(0).Phi(),boson.at(0).M()); 
                invariantMass = Z.M();
                if (invariantMass<120. && invariantMass>60. ) {
                    TVector2 electron1, electron2, sumLepton;
                    electron1.SetMagPhi(goodLep.at(0)->Et(),goodLep.at(0)->Phi());
                    electron2.SetMagPhi(goodLep.at(1)->Et(),goodLep.at(1)->Phi());
                    sumLepton = electron1+electron2;
                    SetTreeVariables(&gen, &Z, &sumLepton, pfMET, trkMET, w, nJet, iTree);
                    delete pfMET;
                    delete trkMET; 
                    return true;
                }
            }
        }

        if (nSel==1 && recType ==2 ){// W MC
            std::vector<Event::GenObject > boson;
            for (std::vector<Event::GenObject>::const_iterator  j = ev.GenParticles().begin();
                j != ev.GenParticles().end(); ++j) { 
                if (j->GetStatus()==3 && abs(j->GetID())==24){ //All stable W
                    boson.push_back(*j);
                }
            }
            if (boson.size()>0){
                TLorentzVector elec1,W,gen,MET;
                elec1.SetPtEtaPhiM(goodLep.at(0)->Et(),goodLep.at(0)->Eta(),goodLep.at(0)->Phi(),0.);
                MET.SetPtEtaPhiM(ev.PFMET().Et(),ev.PFMET().Eta(),ev.PFMET().Phi(),ev.PFMET().M());
                W = (elec1+MET);
                gen.SetPtEtaPhiM(boson.at(0).Pt(),boson.at(0).Eta(),boson.at(0).Phi(),boson.at(0).M()); 
                    TVector2 electron1, electron2, sumLepton;
                    electron1.SetMagPhi(goodLep.at(0)->Et(),goodLep.at(0)->Phi());
                    electron2.SetMagPhi(0.0,0.0);// no second lepton in W events
                    sumLepton = electron1+electron2;
                    SetTreeVariables(&gen, &W, &sumLepton, pfMET, trkMET, w, nJet, iTree);
                delete pfMET;
                delete trkMET; 
                return true;
            }
        }
        if (nSel==1 && recType ==3 ){// W Data just for diagnosis plots, doesn't make sense otherwise
            std::vector<Event::GenObject > boson;
                TLorentzVector elec1,W,gen,MET;
                elec1.SetPtEtaPhiM(goodLep.at(0)->Et(),goodLep.at(0)->Eta(),goodLep.at(0)->Phi(),0.);
                MET.SetPtEtaPhiM(ev.PFMET().Et(),ev.PFMET().Eta(),ev.PFMET().Phi(),ev.PFMET().M());
                W = (elec1+MET);
                TVector2 electron1, electron2, sumLepton;
                electron1.SetMagPhi(goodLep.at(0)->Et(),goodLep.at(0)->Phi());
                electron2.SetMagPhi(0.0,0.0);// no second lepton in W events
                sumLepton = electron1+electron2;
                SetTreeVariables(&W, &W, &sumLepton, pfMET, trkMET, w, nJet, iTree);
                delete pfMET;
                delete trkMET; 
                return true;
        }
        delete pfMET;
        delete trkMET; 

        return false;
    }

    if (doTP && nSel+nAntiSel==2){//Fill T&P studies for antiselection
        //==2 or >=2?
        ////cout<<"nSel="<<nSel<<endl;
        ////cout<<"nAntiSel="<<nAntiSel<<endl;
        //At least 1 tag (passing selection)
        //And 1 signal probe (passing selection)
        //or 1 control probe (passing Antiselection)
        TLorentzVector electron1,electron2,Z;
        double invariantMass = 0.0;
        int ih = -1;
        if (nSel==2){//Probe is signal
            //cout<<"probe is signal"<<endl;
            electron1.SetPtEtaPhiM(goodLep.at(0)->Et(),goodLep.at(0)->Eta(),goodLep.at(0)->Phi(),0.);
            electron2.SetPtEtaPhiM(goodLep.at(1)->Et(),goodLep.at(1)->Eta(),goodLep.at(1)->Phi(),0.);
            Z = (electron1+electron2);
            invariantMass = Z.M();
            ih = getEta(goodLep.at(0));	
        }
        else if (nSel==1&&nAntiSel==1){//Probe is control
            //cout<<"probe is control"<<endl;
            electron1.SetPtEtaPhiM(goodLep.at(0)->Et(),goodLep.at(0)->Eta(),goodLep.at(0)->Phi(),0.);
            electron2.SetPtEtaPhiM(antiLep.at(0)->Et(),antiLep.at(0)->Eta(),antiLep.at(0)->Phi(),0.);
            Z = (electron1+electron2);
            invariantMass = Z.M();
            ih = getEta(antiLep.at(0));	
        }
        else { invariantMass = 0.;}//shouldn't reach this
        //cout<<"invMass= "<<invariantMass<<endl;
        if (invariantMass<120. && invariantMass>60. && ih>=0) {
            //cout<<"test2"<<endl;
            h_TP_all->Fill(invariantMass,w);
            h_TP[ih]->Fill(invariantMass,w);
            if (nSel==2){//Probe is signal
                h_TPS_all->Fill(invariantMass,w);
                h_TPS[ih]->Fill(invariantMass,w);
            } 
            else if (nSel==1&&nAntiSel==1){//Probe is control
                h_TPC_all->Fill(invariantMass,w);
                h_TPC[ih]->Fill(invariantMass,w);
            }
        }
    }
    if ((nSel==1)&&(nSelVeto==1)){//Fill selection histograms
        double mt =  sqrt(2)*sqrt(
                     (goodLep.at(0))->Pt()*met
                    -(goodLep.at(0))->Pt()*met*cos(met_phi-(goodLep.at(0))->Phi()
        ));
        int ih = getEta(goodLep.at(0));	
        int iwpt = getWpt(goodLep.at(0),met,met_phi);
        int ijet = getJet(goodLep.at(0),nJet);
        if (fabs((goodLep.at(0))->Eta())<1.5){  
            h_met->Fill(met,w);
            h_mt->Fill(mt,w);
        }
        if (ih>=0) h_eta_sel[ih]->Fill(met,w);
        if (iwpt>=0) h_wpt_sel[iwpt]->Fill(met,w);
        if (ijet>=0) h_jet_sel[ijet]->Fill(met,w);
        return true;
    }
    if (nAntiSel==1){//Fill anti-selection histograms
        int ih = getEta(antiLep.at(0));	
        int iwpt = getWpt(antiLep.at(0),met,met_phi);
        int ijet = getJet(antiLep.at(0),nJet);
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

int AsymTemplateHistos::getEta(Lepton const * lep){
	double eta= (lep)->Eta();
	double charge = (lep)->GetCharge();
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

int AsymTemplateHistos::getWpt(Lepton const * lep, double met, double met_phi){
	double charge = (lep)->GetCharge();
	double pt= (lep)->Pt();
	int wpt = -1;
	for (int iwpt=0;iwpt<WptBins;iwpt++){ 
		double measured_Wpt = sqrt(met*met+pt*pt+pt*met*cos(met_phi-(lep)->Phi()));
		if (measured_Wpt>wptbinlow[iwpt]){
			wpt = iwpt; // note: no +1 since we do not have an inclusive bin here
			//note : no break since these are the lower bin edges
		}
	}
	if (wpt < 0) return -1; // no wpt bin found (should be impossible)
	if (charge<0) wpt+=WptBins; // positive bins go 0,1,2,3,4, negative go 5,6,7,8,9	
	return wpt;
}

int AsymTemplateHistos::getJet(Lepton const * lep,int nJet){
	double charge = (lep)->GetCharge();
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

void AsymTemplateHistos::SetTree(TTree *tree){

	// lepton properties
	tree->Branch("leppt", &_leppt ,"leppt/F");
	tree->Branch("lepphi", &_lepphi ,"lepphi/F");

	// boson properties
	tree->Branch("genpt", &_genpt ,"genpt/F");
	tree->Branch("genphi", &_genphi ,"genphi/F");
	tree->Branch("mass", &_mass ,"mass/F");
	tree->Branch("pt", &_pt ,"pt/F");
	tree->Branch("y", &_y ,"y/F");
	tree->Branch("phi", &_phi ,"phi/F");

	//pfmet
	tree->Branch("pfmet", &_pfmet ,"pfmet/F");
	tree->Branch("pfmetphi", &_pfmetphi ,"pfmetphi/F");
	tree->Branch("pfmt", &_pfmt ,"pfmt/F");
	tree->Branch("pfu1", &_pfu1 ,"pfu1/F");
	tree->Branch("pfu2", &_pfu2 ,"pfu2/F");

	//track met
	tree->Branch("trkmet", &_trkmet ,"trkmet/F");
	tree->Branch("trkmetphi", &_trkmetphi ,"trkmetphi/F");
	tree->Branch("trkmt", &_trkmt ,"trkmt/F");
	tree->Branch("trku1", &_trku1 ,"trku1/F");
	tree->Branch("trku2", &_trku2 ,"trku2/F");

        tree->Branch("weight", &_weight ,"weight/F");
	tree->Branch("njet", &_njet ,"njet/I");
}

void AsymTemplateHistos::SetTreeVariables(TLorentzVector *genBoson, TLorentzVector *recoBoson,
                                          TVector2 *sumLepton,
                                          TVector2 *pfMET, TVector2 *trkMET,
                                          float wt, int nJet, TTree *tree){


	// Transverse Recoil Vector
    TVector2 * pfU = new TVector2(0.,0.);
    (*pfU) -= *pfMET;
    (*pfU) -= *sumLepton;

    TVector2 * trkU = new TVector2(0.,0.);
    (*trkU) -= *trkMET;
    (*trkU) -= *sumLepton;

	// Transverse Decomposed in to components parallel and perpendicular to
	// boson PT
    TVector2 qT;
    qT.SetMagPhi(genBoson->Pt(),genBoson->Phi());
    // I think this is correct, it doesn;t make sense with the W boson, to use the
    // Reco since the W boson = MET+Lepton, which it equal and oposite to the
    // Recoil = -Met-Lepton
    //
    // For the Z data, I use the reco Z. I think this is correct
    // Indeed this is all correct, more detailed in Phil's Thesis.
    float dPhi = pfU->DeltaPhi(qT);
    //cout<<"~~~~~~~~~~~~~~~~"<<endl;
    //cout<<"TEST: pfU  ="<<pfU->Mod()<<endl;
    //cout<<"TEST: pfUfi="<<pfU->Phi()<<endl;
    //cout<<"TEST: qTU  ="<<qT.Mod()<<endl;
    //cout<<"TEST: qTfi ="<<qT.Phi()<<endl;
    //cout<<"TEST: dphi ="<<dPhi<<endl;
    _pfu1 = pfU->Mod()*cos(dPhi);
    //cout<<"TEST: pfU1 ="<<_pfu1<<endl;
    _pfu2 = pfU->Mod()*sin(dPhi);
    //cout<<"TEST: pfU2 ="<<_pfu2<<endl;

    dPhi = trkU->DeltaPhi(qT);
    _trku1 = trkU->Mod()*cos(dPhi);
    _trku2 = trkU->Mod()*sin(dPhi);


	// boson properties
	_genpt = genBoson->Pt();
	_genphi = genBoson->Phi();
	_mass = recoBoson->M();
	_pt = recoBoson->Pt();
	_y = recoBoson->Rapidity();
	_phi = recoBoson->Phi();

	// lepton properties
	_leppt = sumLepton->Mod();
	_lepphi = sumLepton->Phi();

	//pfmet
	_pfmet = pfMET->Mod();
	_pfmetphi = pfMET->Phi_mpi_pi(pfMET->Phi());
	_pfmt = sqrt(2)*sqrt(sumLepton->Mod()*pfMET->Mod() 
            -sumLepton->Mod()*pfMET->Mod()
            *cos(pfMET->DeltaPhi(*sumLepton)));

	//track met
	_trkmet = trkMET->Mod();
	_trkmetphi = trkMET->Phi_mpi_pi(trkMET->Phi());
	_trkmt = sqrt(2)*sqrt(sumLepton->Mod()*trkMET->Mod() 
            -sumLepton->Mod()*trkMET->Mod()
            *cos(trkMET->DeltaPhi(*sumLepton)));

	_weight = wt;
	_njet = nJet;
    tree->Fill();
}
