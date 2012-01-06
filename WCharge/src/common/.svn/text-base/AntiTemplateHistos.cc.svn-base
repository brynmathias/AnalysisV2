/*
Based on UserCode/Futyan/macros/WenuTemplateFit.cc
This code uses GetElectronSCCharge(i) and GetElectronKFCharge(i) which require version 3 ntuples or greater.
See WCharge/scripts/MetTemp.py for an example of how to run the code.
*/

#include "AntiTemplateHistos.hh"
#include "KinSuite.hh"
#include <fstream>

using namespace std;
//using namespace Event;

AntiTemplateHistos::AntiTemplateHistos(const std::string & folderName,
Utils::ParameterSet &pset
):
mFolderName(folderName)
{
	elecET     = pset.Get<double>("ElecET");
	chChk       = pset.Get<bool>("ChCheck");
}

void AntiTemplateHistos::Start(Event::Data & ev) {
	initDir(ev.OutputFile(), mFolderName.c_str());
	BookHistos();

}
AntiTemplateHistos::~AntiTemplateHistos() {

}

/*
~~~BOOK HISTOS~~~
*/
void  AntiTemplateHistos::BookHistos() {

	h_pfMET = new TH1F("h_pfMET","pfMET",200,0.,100.);

	h_pfMET_presel = new TH1F("h_pfMET_presel","pfMET_presel",200,0.,100.);

	h_pfMET_antiDhi90 = new TH1F("h_pfMET_antiDhi90","pfMET_antiDhi90",200,0.,100.);


	h_pfMET_eiso90_antiDhiDfi90 = new TH1F("h_pfMET_eiso90_antiDhiDfi90","pfMET_eiso90_antiDhiDfi90",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90 = new TH1F("h_pfMET_eiso80_antiDhiDfi90","pfMET_eiso80_antiDhiDfi90",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90 = new TH1F("h_pfMET_eiso70_antiDhiDfi90","pfMET_eiso70_antiDhiDfi90",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90 = new TH1F("h_pfMET_eiso60_antiDhiDfi90","pfMET_eiso60_antiDhiDfi90",200,0.,100.);


	h_pfMET_antiDhi_90_eta1_pos = new TH1F("h_pfMET_antiDhi_90_eta1_pos","pfMET_antiDhi_90_eta1_pos",200,0.,100.);
	h_pfMET_eiso90_antiDhiDfi90_eta1_pos = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta1_pos","pfMET_eiso90_antiDhiDfi90_eta1_pos",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90_eta1_pos = new TH1F("h_pfMET_eiso80_antiDhiDfi90_eta1_pos","pfMET_eiso80_antiDhiDfi90_eta1_pos",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90_eta1_pos = new TH1F("h_pfMET_eiso70_antiDhiDfi90_eta1_pos","pfMET_eiso70_antiDhiDfi90_eta1_pos",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90_eta1_pos = new TH1F("h_pfMET_eiso60_antiDhiDfi90_eta1_pos","pfMET_eiso60_antiDhiDfi90_eta1_pos",200,0.,100.);


	h_pfMET_antiDhi_90_eta2_pos = new TH1F("h_pfMET_antiDhi_90_eta2_pos","pfMET_antiDhi_90_eta2_pos",200,0.,100.);
	h_pfMET_eiso90_antiDhiDfi90_eta2_pos = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta2_pos","pfMET_eiso90_antiDhiDfi90_eta2_pos",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90_eta2_pos = new TH1F("h_pfMET_eiso80_antiDhiDfi90_eta2_pos","pfMET_eiso80_antiDhiDfi90_eta2_pos",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90_eta2_pos = new TH1F("h_pfMET_eiso70_antiDhiDfi90_eta2_pos","pfMET_eiso70_antiDhiDfi90_eta2_pos",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90_eta2_pos = new TH1F("h_pfMET_eiso60_antiDhiDfi90_eta2_pos","pfMET_eiso60_antiDhiDfi90_eta2_pos",200,0.,100.);


	h_pfMET_antiDhi_90_eta3_pos = new TH1F("h_pfMET_antiDhi_90_eta3_pos","pfMET_antiDhi_90_eta3_pos",200,0.,100.);
	h_pfMET_eiso90_antiDhiDfi90_eta3_pos = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta3_pos","pfMET_eiso90_antiDhiDfi90_eta3_pos",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90_eta3_pos = new TH1F("h_pfMET_eiso80_antiDhiDfi90_eta3_pos","pfMET_eiso80_antiDhiDfi90_eta3_pos",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90_eta3_pos = new TH1F("h_pfMET_eiso70_antiDhiDfi90_eta3_pos","pfMET_eiso70_antiDhiDfi90_eta3_pos",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90_eta3_pos = new TH1F("h_pfMET_eiso60_antiDhiDfi90_eta3_pos","pfMET_eiso60_antiDhiDfi90_eta3_pos",200,0.,100.);


	h_pfMET_antiDhi_90_eta1_neg = new TH1F("h_pfMET_antiDhi_90_eta1_neg","pfMET_antiDhi_90_eta1_neg",200,0.,100.);
	h_pfMET_eiso90_antiDhiDfi90_eta1_neg = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta1_neg","pfMET_eiso90_antiDhiDfi90_eta1_neg",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90_eta1_neg = new TH1F("h_pfMET_eiso80_antiDhiDfi90_eta1_neg","pfMET_eiso80_antiDhiDfi90_eta1_neg",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90_eta1_neg = new TH1F("h_pfMET_eiso70_antiDhiDfi90_eta1_neg","pfMET_eiso70_antiDhiDfi90_eta1_neg",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90_eta1_neg = new TH1F("h_pfMET_eiso60_antiDhiDfi90_eta1_neg","pfMET_eiso60_antiDhiDfi90_eta1_neg",200,0.,100.);


	h_pfMET_antiDhi_90_eta2_neg = new TH1F("h_pfMET_antiDhi_90_eta2_neg","pfMET_antiDhi_90_eta2_neg",200,0.,100.);
	h_pfMET_eiso90_antiDhiDfi90_eta2_neg = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta2_neg","pfMET_eiso90_antiDhiDfi90_eta2_neg",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90_eta2_neg = new TH1F("h_pfMET_eiso80_antiDhiDfi90_eta2_neg","pfMET_eiso80_antiDhiDfi90_eta2_neg",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90_eta2_neg = new TH1F("h_pfMET_eiso70_antiDhiDfi90_eta2_neg","pfMET_eiso70_antiDhiDfi90_eta2_neg",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90_eta2_neg = new TH1F("h_pfMET_eiso60_antiDhiDfi90_eta2_neg","pfMET_eiso60_antiDhiDfi90_eta2_neg",200,0.,100.);

        h_pfMET_antiDhi_90_eta3_neg = new TH1F("h_pfMET_antiDhi_90_eta3_neg","pfMET_antiDhi_90_eta3_neg",200,0.,100.);
	h_pfMET_eiso90_antiDhiDfi90_eta3_neg = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta3_neg","pfMET_eiso90_antiDhiDfi90_eta3_neg",200,0.,100.);
	h_pfMET_eiso80_antiDhiDfi90_eta3_neg = new TH1F("h_pfMET_eiso80_antiDhiDfi90_eta3_neg","pfMET_eiso80_antiDhiDfi90_eta3_neg",200,0.,100.);
	h_pfMET_eiso70_antiDhiDfi90_eta3_neg = new TH1F("h_pfMET_eiso70_antiDhiDfi90_eta3_neg","pfMET_eiso70_antiDhiDfi90_eta3_neg",200,0.,100.);
	h_pfMET_eiso60_antiDhiDfi90_eta3_neg = new TH1F("h_pfMET_eiso60_antiDhiDfi90_eta3_neg","pfMET_eiso60_antiDhiDfi90_eta3_neg",200,0.,100.);

        h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEP = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEP","pfMET_eiso90_antiDhiDfi90_eta3_neg_EEP",200,0.,100.);
        h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEP = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEP","pfMET_eiso90_antiDhiDfi90_eta3_pos_EEP",200,0.,100.);
        h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEM = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEM","pfMET_eiso90_antiDhiDfi90_eta3_neg_EEM",200,0.,100.);
        h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEM = new TH1F("h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEM","pfMET_eiso90_antiDhiDfi90_eta3_pos_EEM",200,0.,100.);

}
/*
~~~PROCESS~~~
*/
bool AntiTemplateHistos::Process(Event::Data & ev) {

	float w=ev.GetEventWeight();
	
	double event_pfMET= ev.PFMET().Pt();
	int lepindex = -1;
	uint ElSize=0;
	
	double probe_sc_et;
	double probe_sc_eta;
	
	double probe_sc_phi;
	double probe_isolation_value;
	double probe_ecal_isolation_value;
	double probe_hcal_isolation_value;
	double probe_ele_sihih;
	double probe_ele_dfi;
	double probe_ele_dhi;
	double probe_ele_hoe;
	double probe_charge;
	
// 	for (std::vector<Lepton>::const_iterator lep=ev.LD_Electrons().begin();
// 	lep != ev.LD_Electrons().end();
// 	++lep) {
	for (std::vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep != ev.LD_CommonElectrons().accepted.end();
	     ++lep) {
	  
	  int i = (*lep)->GetIndex();
	  /*
	    Preselection: 
	    the event has at least one electron with SC_ET>30GeVand with SC in fiducial
	    additionally cuts on the electron charge ch(KF)==ch(GSF)==ch(SC)
	  */
	  if ( (*lep)->Et()>elecET && fid((*lep)->Eta()) 
	       //	       && (*lep)->GetCharge()==ev.GetElectronSCCharge(i)
	       //	       && (*lep)->GetCharge()==ev.GetElectronKFCharge(i) 
	       &&   ev.GetElectronHasValidHitInFirstPixelBarrel(i))
	    {
	      if (chChk&&(
		(*lep)->GetCharge()!=ev.GetElectronSCCharge(i)||
		(*lep)->GetCharge()!=ev.GetElectronKFCharge(i)
		)) continue;


             if (fabs((*lep)->Eta())>1.44 &&(fabs((*lep)->Eta())<1.56)) continue;


	      ElSize++;
	      if (lepindex==-1){
		lepindex = (*lep)->GetIndex();
		probe_sc_eta = (*lep)->Eta();
		probe_sc_phi = (*lep)->Phi(); 
		probe_sc_et =(*lep)->Pt();
		//	probe_sc_et = ev.GetElectronEcalEnergy(lepindex)/cosh(probe_sc_eta);
		probe_isolation_value = (*lep)->GetTrkIsolation();
		probe_ecal_isolation_value = (*lep)->GetEcalIsolation(); 
		probe_hcal_isolation_value = (*lep)->GetHcalIsolation();
		probe_ele_sihih = ev.GetElectronSigmaIetaIeta(lepindex);
		probe_ele_dfi = ev.GetElectronDeltaPhiAtVtx(lepindex);
		probe_ele_dhi = ev.GetElectronDeltaEtaAtVtx(lepindex);
		probe_ele_hoe = ev.GetElectronHoE(lepindex);
		probe_charge = (*lep)->GetCharge();
	      }
	    }
	}
	//MET distribution before any selection
	h_pfMET->Fill(event_pfMET,w);
	
	if (lepindex==-1) return false;
	
	
	//MET distribution after preselection
	
	//~~~ Fill Histograms ~~~
	//Suffix for histograms
	string suffix;

        if ((fabs(probe_sc_eta)<0.8)&&(fabs(probe_sc_eta)>0.0)&&(probe_charge>0))  suffix="_eta1_pos";
        else if ((fabs(probe_sc_eta)<1.6)&&(fabs(probe_sc_eta)>0.8)&&(probe_charge>0))  suffix="_eta2_pos";
        else if ((fabs(probe_sc_eta)<2.4)&&(fabs(probe_sc_eta)>1.6)&&(probe_charge>0))  suffix="_eta3_pos";
        else if ((fabs(probe_sc_eta)<0.8)&&(fabs(probe_sc_eta)>0.0)&&(probe_charge<0))  suffix="_eta1_neg";
        else if ((fabs(probe_sc_eta)<1.6)&&(fabs(probe_sc_eta)>0.8)&&(probe_charge<0))  suffix="_eta2_neg";
        else if ((fabs(probe_sc_eta)<2.4)&&(fabs(probe_sc_eta)>1.6)&&(probe_charge<0))  suffix="_eta3_neg";
        else if ((probe_charge==0)||(fabs(probe_sc_eta)>2.5)) return false;
        if ((fabs(probe_sc_eta)<1.56)&&(fabs(probe_sc_eta)>1.44) ) return false;


	TH1F *h1;
	TDirectory *currentDirectory= ev.OutputFile()->GetDirectory(mFolderName.c_str());
		
	//~~~ CUTS ~~~
	bool pass_dfi90 = CheckCuts(0., 0., 0., 0., probe_ele_dfi, 0., 0., probe_sc_eta,0);
       
	bool pass_dhi90 =false; 
	  //CheckCuts(0., 0., 0., 0., 0., probe_ele_dhi, 0., probe_sc_eta,0);

	//
	for (int ieff=0; ieff<6; ieff++) {
	  if (ieff!=2&&ieff!=4) {

	    
	    //Fill MET templates after anti-selections for each efficiency point
	    if (ieff==0 && !pass_dhi90) {
	      //MICHELE
	      h_pfMET_antiDhi90->Fill(event_pfMET,w);
	      TString anti90= "h_pfMET_antiDhi_90"+suffix;   
	      currentDirectory->GetObject(anti90,h1);
	      h1->Fill(event_pfMET,w);
	    }
	    if (!pass_dhi90 && !pass_dfi90) {
	      bool pass_eiso = CheckCuts(0., probe_ecal_isolation_value, 0., 0., 0., 0., 0., probe_sc_eta,ieff);
	      if (pass_eiso) {
		if (ieff==0) {
	  h_pfMET_eiso90_antiDhiDfi90->Fill(event_pfMET,w);
		  TString isoanti90= "h_pfMET_eiso90_antiDhiDfi90"+suffix;
		  currentDirectory->GetObject(isoanti90,h1);
		  h1->Fill(event_pfMET,w);

                if ((probe_sc_eta>1.6) &&(probe_charge>0)) h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEP->Fill(event_pfMET,w);
                if ((probe_sc_eta>1.6) &&(probe_charge<0)) h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEP->Fill(event_pfMET,w);
                if ((probe_sc_eta<-1.6) &&(probe_charge>0)) h_pfMET_eiso90_antiDhiDfi90_eta3_pos_EEM->Fill(event_pfMET,w);
                if ((probe_sc_eta<-1.6) &&(probe_charge<0)) h_pfMET_eiso90_antiDhiDfi90_eta3_neg_EEM->Fill(event_pfMET,w);


		} else if (ieff==1) {
		  h_pfMET_eiso80_antiDhiDfi90->Fill(event_pfMET,w);
		  TString isoanti80= "h_pfMET_eiso80_antiDhiDfi90"+suffix;
		  currentDirectory->GetObject(isoanti80,h1);
		  h1->Fill(event_pfMET,w);
		  
		} else if (ieff==3) {
		  h_pfMET_eiso70_antiDhiDfi90->Fill(event_pfMET,w);
		  TString isoanti70= "h_pfMET_eiso70_antiDhiDfi90"+suffix;
		  currentDirectory->GetObject(isoanti70,h1);
		  h1->Fill(event_pfMET,w);
		} else if (ieff==5) {
		  h_pfMET_eiso60_antiDhiDfi90->Fill(event_pfMET,w);
		  TString isoanti60= "h_pfMET_eiso60_antiDhiDfi90"+suffix;
		  currentDirectory->GetObject(isoanti60,h1);
		  h1->Fill(event_pfMET,w);
		  
		}
	      }
	    }
	  }
	}
	return true;
} // end of Process method

std::ostream& AntiTemplateHistos::Description(std::ostream &ostrm) {
	ostrm << "AntiTemplateHistos plots made here: (histograms in ";
	ostrm << mFolderName << ")";
	return ostrm;
}

bool AntiTemplateHistos::passIsolation (double track, double ecal, double hcal, double eta, int ieff)
{

	return CheckCuts(track, ecal, hcal, 0., 0., 0., 0.,  eta, ieff );

}

bool AntiTemplateHistos::passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff)
{

	return CheckCuts(0., 0., 0., sihih, dfi, dhi, hoe,  eta, ieff );

}

bool AntiTemplateHistos::fid(double eta) {

	return  (fabs(eta)<2.5 && (  fabs(eta) < 1.4442  || fabs(eta) > 1.56 ));
}

bool AntiTemplateHistos::CheckCuts(double v_trk, double v_ecal, double v_hcal, 
double v_sihih, double v_dfi, double v_dhi, double v_hoe,
double eta, int ieff)
{


	if (fabs(eta)< 1.479) {	  
		if ( v_trk  <  AnTrk[ieff]    && 
				v_ecal <  AnEcal[ieff]   &&
				v_hcal <  AnHcal[ieff]   &&
				v_sihih < Ansihih[ieff]  &&
				fabs(v_dfi) < AnDphi[ieff]   &&
				fabs(v_dhi) < AnDeta[ieff]   &&
				fabs(v_hoe)< AnHoE[ieff]    
				) return true;
	}
	else {
		if ( v_trk <  AnTrk_ee[ieff]    && 
				v_ecal < AnEcal_ee[ieff]   &&
				v_hcal < AnHcal_ee[ieff]   &&
				v_sihih < Ansihih_ee[ieff]  &&
				fabs(v_dfi) < AnDphi_ee[ieff]   &&
		     //MICHELE DA SCOMMENTARE
		     //				fabs(v_dhi) < AnDeta_ee[ieff]     &&
				fabs(v_hoe)< AnHoE_ee[ieff] 
				) return true;
	}
	return false;
}
