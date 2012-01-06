/*
Based on UserCode/Futyan/macros/WenuTemplateHistos.cc
*/
#include "eWPolTemplateHistos.hh"
#include "KinSuite.hh"
#include <fstream>

using namespace std;
//using namespace Event;

namespace WPol{

eWPolTemplateHistos::eWPolTemplateHistos(const std::string & folderName,
Utils::ParameterSet &pset
):
mFolderName(folderName)
{
  elecET     = pset.Get<double>("ElecET");
  //chChk      = pset.Get<bool>("ChCheck");
  corrEE     = pset.Get<bool>("CorrEEMisalig");
  useGEN = pset.Get<bool>("useGEN");
  useObservable = pset.Get<string>("useObservable");
  eType = pset.Get<string>("eType");
}

void eWPolTemplateHistos::Start(Event::Data & ev) {
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();

}
eWPolTemplateHistos::~eWPolTemplateHistos() {

}

/*
~~~BOOK HISTOS~~~
*/
void  eWPolTemplateHistos::BookHistos() {

  int nBins;
  double xMin, xMax;

  if (useObservable=="MET") {
    nBins=200; xMin=0.; xMax=100.;
  } else if (useObservable=="LP") {
    nBins=500; xMin=-2.5; xMax=2.5;
  } else if (useObservable=="Iso") {
    nBins=500; xMin=0.; xMax=5.;
  }

  h_pfMET = new TH1F("h_pfMET","pfMET",nBins,xMin,xMax);
  h_pfMET_presel = new TH1F("h_pfMET_presel","pfMET_presel",nBins,xMin,xMax);

  h_pfMET_sel_90 = new TH1F("h_pfMET_sel_90","pfMET_sel_90",nBins,xMin,xMax);
  h_pfMET_sel_80 = new TH1F("h_pfMET_sel_80","pfMET_sel_80",nBins,xMin,xMax);
  h_pfMET_sel_70 = new TH1F("h_pfMET_sel_70","pfMET_sel_70",nBins,xMin,xMax);
  h_pfMET_sel_60 = new TH1F("h_pfMET_sel_60","pfMET_sel_60",nBins,xMin,xMax);

  h_pfMET_sel_90_barl = new TH1F("h_pfMET_sel_90_barl","pfMET_sel_90_barl",nBins,xMin,xMax);
  h_pfMET_sel_80_barl = new TH1F("h_pfMET_sel_80_barl","pfMET_sel_80_barl",nBins,xMin,xMax);
  h_pfMET_sel_70_barl = new TH1F("h_pfMET_sel_70_barl","pfMET_sel_70_barl",nBins,xMin,xMax);
  h_pfMET_sel_60_barl = new TH1F("h_pfMET_sel_60_barl","pfMET_sel_60_barl",nBins,xMin,xMax);

  h_pfMET_sel_90_endc = new TH1F("h_pfMET_sel_90_endc","pfMET_sel_90_endc",nBins,xMin,xMax);
  h_pfMET_sel_80_endc = new TH1F("h_pfMET_sel_80_endc","pfMET_sel_80_endc",nBins,xMin,xMax);
  h_pfMET_sel_70_endc = new TH1F("h_pfMET_sel_70_endc","pfMET_sel_70_endc",nBins,xMin,xMax);
  h_pfMET_sel_60_endc = new TH1F("h_pfMET_sel_60_endc","pfMET_sel_60_endc",nBins,xMin,xMax);

  h_pfMET_sel_90_pos = new TH1F("h_pfMET_sel_90_pos","pfMET_sel_90_pos",nBins,xMin,xMax);
  h_pfMET_sel_80_pos = new TH1F("h_pfMET_sel_80_pos","pfMET_sel_80_pos",nBins,xMin,xMax);
  h_pfMET_sel_70_pos = new TH1F("h_pfMET_sel_70_pos","pfMET_sel_70_pos",nBins,xMin,xMax);
  h_pfMET_sel_60_pos = new TH1F("h_pfMET_sel_60_pos","pfMET_sel_60_pos",nBins,xMin,xMax);

  h_pfMET_sel_90_neg = new TH1F("h_pfMET_sel_90_neg","pfMET_sel_90_neg",nBins,xMin,xMax);
  h_pfMET_sel_80_neg = new TH1F("h_pfMET_sel_80_neg","pfMET_sel_80_neg",nBins,xMin,xMax);
  h_pfMET_sel_70_neg = new TH1F("h_pfMET_sel_70_neg","pfMET_sel_70_neg",nBins,xMin,xMax);
  h_pfMET_sel_60_neg = new TH1F("h_pfMET_sel_60_neg","pfMET_sel_60_neg",nBins,xMin,xMax);

  h_pfMET_antiDhi_90 = new TH1F("h_pfMET_antiDhi_90","pfMET_antiDhi_90",nBins,xMin,xMax);
  h_pfMET_antiDhi_90_barl = new TH1F("h_pfMET_antiDhi_90_barl","pfMET_antiDhi_90_barl",nBins,xMin,xMax);
  h_pfMET_antiDhi_90_endc = new TH1F("h_pfMET_antiDhi_90_endc","pfMET_antiDhi_90_endc",nBins,xMin,xMax);

  h_pfMET_eiso90_antiDhiDfi90 = new TH1F("h_pfMET_eiso90_antiDhiDfi90","pfMET_eiso90_antiDhiDfi90",nBins,xMin,xMax);
  h_pfMET_eiso80_antiDhiDfi90 = new TH1F("h_pfMET_eiso80_antiDhiDfi90","pfMET_eiso80_antiDhiDfi90",nBins,xMin,xMax);
  h_pfMET_eiso70_antiDhiDfi90 = new TH1F("h_pfMET_eiso70_antiDhiDfi90","pfMET_eiso70_antiDhiDfi90",nBins,xMin,xMax);
  h_pfMET_eiso60_antiDhiDfi90 = new TH1F("h_pfMET_eiso60_antiDhiDfi90","pfMET_eiso60_antiDhiDfi90",nBins,xMin,xMax);

  h_pfMET_eiso90_antiDhiDfi90_barl = new TH1F("h_pfMET_eiso90_antiDhiDfi90_barl","pfMET_eiso90_antiDhiDfi90_barl",nBins,xMin,xMax);
  h_pfMET_eiso80_antiDhiDfi90_barl = new TH1F("h_pfMET_eiso80_antiDhiDfi90_barl","pfMET_eiso80_antiDhiDfi90_barl",nBins,xMin,xMax);
  h_pfMET_eiso70_antiDhiDfi90_barl = new TH1F("h_pfMET_eiso70_antiDhiDfi90_barl","pfMET_eiso70_antiDhiDfi90_barl",nBins,xMin,xMax);
  h_pfMET_eiso60_antiDhiDfi90_barl = new TH1F("h_pfMET_eiso60_antiDhiDfi90_barl","pfMET_eiso60_antiDhiDfi90_barl",nBins,xMin,xMax);

  h_pfMET_eiso90_antiDhiDfi90_endc = new TH1F("h_pfMET_eiso90_antiDhiDfi90_endc","pfMET_eiso90_antiDhiDfi90_endc",nBins,xMin,xMax);
  h_pfMET_eiso80_antiDhiDfi90_endc = new TH1F("h_pfMET_eiso80_antiDhiDfi90_endc","pfMET_eiso80_antiDhiDfi90_endc",nBins,xMin,xMax);
  h_pfMET_eiso70_antiDhiDfi90_endc = new TH1F("h_pfMET_eiso70_antiDhiDfi90_endc","pfMET_eiso70_antiDhiDfi90_endc",nBins,xMin,xMax);
  h_pfMET_eiso60_antiDhiDfi90_endc = new TH1F("h_pfMET_eiso60_antiDhiDfi90_endc","pfMET_eiso60_antiDhiDfi90_endc",nBins,xMin,xMax);

}
  /*
~~~PROCESS~~~
*/
bool eWPolTemplateHistos::Process(Event::Data & ev) {

  float w=ev.GetEventWeight();

  int lepindex = -1;
  size_t ElSize=0;
  /*
  double probe_sc_et;
  double probe_sc_eta;
  double probe_sc_phi;
  */
  double probe_ele_pt;
  double probe_ele_et;
  double probe_ele_eta;

  double probe_ele_combIso;
  double probe_ele_ecal_iso_user;
  double probe_ele_hcal_iso_user;
  double probe_ele_sihih;
  double probe_ele_dfi;
  double probe_ele_dhi;
  double probe_ele_hoe;
  int probe_ele_charge;

  double probe_ele_dcot;
  double probe_ele_dist;
  //  double probe_ele_expectedHitsInner;
  bool probe_ele_expectedHitsInner;

  int probe_type;

  LorentzV pfMET;
  double ICVariablePF;

  int iele=0;
  const std::vector<const Event::Lepton*> & common_leps=ev.LD_CommonElectrons().accepted;
  for(std::vector<const Event::Lepton*>::const_iterator ii=common_leps.begin();
      ii!=common_leps.end(); ++ii){
    int idx=(*ii)->GetIndex();
    /*
      Preselection:
      the event has at least one electron with SC_ET>30GeVand with SC in fiducial
      additionally cuts on the electron charge ch(KF)==ch(GSF)==ch(SC)
    */

    if ( (*ii)->Et()>elecET && fid((*ii)->Eta()) ) {
      iele++;
      if (lepindex==-1) {

        lepindex=idx;

        probe_ele_pt=(*ii)->Pt();
        probe_ele_et=( ev.GetElectronTrkPt(idx)*ev.GetElectronESuperClusterOverP(idx) );
        probe_ele_eta=(*ii)->Eta();
        probe_ele_charge=(*ii)->GetCharge();

        probe_ele_dfi=fabs(ev.GetElectronDeltaPhiAtVtx(idx));
        probe_ele_dhi=fabs(ev.GetElectronDeltaEtaAtVtx(idx));
        probe_ele_sihih=ev.GetElectronSigmaIetaIeta(idx);
        probe_ele_hoe=ev.GetElectronHoE(idx);

        probe_ele_ecal_iso_user=(*ii)->GetEcalIsolation();
        probe_ele_hcal_iso_user=(*ii)->GetHcalIsolation();

        probe_ele_combIso=(*ii)->GetCombIsolation();

        probe_ele_dist=ev.GetElectronDist(idx);
        probe_ele_dcot=ev.GetElectronDCot(idx);
              probe_ele_expectedHitsInner=ev.GetElectronGsfTrackTrackerExpectedHitsInner(idx);
                //probe_ele_expectedHitsInner=ev.GetElectronHasValidHitInFirstPixelBarrel(idx);

        pfMET = (ev.PFMET() + *(*ii));
        ICVariablePF=(((*ii)->Px() * pfMET.Px()) + ((*ii)->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());

              if(useGEN) {
                int iMatch = ev.leptonMatch(*ii,1); probe_type=ev.leptonType(iMatch);
              }

      }

    } // ficucial cuts

  } // end loop on electrons
  ElSize=iele;

  bool fake = ( (probe_type<0 || probe_type==9) );
  bool HF = ( probe_type==10 || probe_type==4 );
  bool Conversion = ( probe_type==22 );

  if (useGEN) {
    if (eType=="fake" && (!fake && !HF)) return false;
    if (eType=="HF" && !HF) return false;
    if (eType=="Conv" && !Conversion) return false;
  }

  // Select Variable to model
  double event_pfMET;

        if (useObservable=="MET") {
          event_pfMET= ev.PFMET().Pt();
        } else if (useObservable=="LP") {
    event_pfMET=ICVariablePF;
  } else if (useObservable=="Iso") {
    event_pfMET=probe_ele_combIso;
  }

  //MET distribution before any selection
  h_pfMET->Fill(event_pfMET,w);

  if (lepindex==-1) return false;

  //MET distribution after preselection
  h_pfMET_presel->Fill(event_pfMET,w);

  float eta_ele = probe_ele_eta;
  int ele_charge = probe_ele_charge;

  //  bool elec2nd = Check2ndEle(probe_sc_et, probe_sc_eta);

  bool pass_dfi90 = CheckCuts(0., 0., probe_ele_dfi, 0., 0., eta_ele,2);
  bool pass_dhi90 = CheckCuts(0., 0., 0., probe_ele_dhi, 0., eta_ele,1);

  //~~~ Fill Histograms ~~~
  //Suffix for histograms
  string r_suffix,c_suffix;
  if ( (fabs(probe_ele_eta)<1.4442) ) r_suffix="_barl";
  else if ( (fabs(probe_ele_eta)>1.52) && (fabs(probe_ele_eta)<2.5) ) r_suffix="_endc";
  else return false;
  if (ele_charge>0) { c_suffix="_pos"; } else { c_suffix="_neg"; }

  TH1F *h1, *h2, *h3;
  TDirectory *currentDirectory= ev.OutputFile()->GetDirectory(mFolderName.c_str());

  for (int ieff=0; ieff<6; ieff++) {
    if (ieff!=0&&ieff!=2) {

      //Determine if conversion rejection, isolation and electron ID are passed for each efficiency
      // working point (ieff)
      bool conv = passConvRejection(probe_ele_expectedHitsInner,
           probe_ele_dist, probe_ele_dcot, ieff);

      bool iso = passIsolation(probe_ele_combIso,eta_ele,ieff);
      /*
      bool iso = passIsolation(probe_ele_combIso,
            probe_ele_ecal_iso_user/probe_ele_et,
            probe_ele_hcal_iso_user/probe_ele_et,
            eta_ele, ieff);
      */
      bool id = passID(probe_ele_sihih, probe_ele_dfi,
          probe_ele_dhi, probe_ele_hoe, eta_ele, ieff);

      //MET distribution after W selection for different eff points: electron iso and id, and require no 2nd electron
      if (useObservable=="Iso") { iso=true; }

      if (conv && id && iso && (ElSize==1)) {
        if (ieff==0) {
    h_pfMET_sel_90->Fill(event_pfMET,w);
    TString r_sel_90= "h_pfMET_sel_90"+r_suffix;
    currentDirectory->GetObject(r_sel_90,h1); h1->Fill(event_pfMET,w);
    TString c_sel_90="h_pfMET_sel_90"+c_suffix;
    currentDirectory->GetObject(c_sel_90,h2); h2->Fill(event_pfMET,w);
        } else if (ieff==1) {
    h_pfMET_sel_80->Fill(event_pfMET,w);
    TString r_sel_80= "h_pfMET_sel_80"+r_suffix;
    currentDirectory->GetObject(r_sel_80,h1); h1->Fill(event_pfMET,w);
    TString c_sel_80="h_pfMET_sel_80"+c_suffix;
    currentDirectory->GetObject(c_sel_80,h2); h2->Fill(event_pfMET,w);
        } else if (ieff==3) {
    h_pfMET_sel_70->Fill(event_pfMET,w);
    TString r_sel_70= "h_pfMET_sel_70"+r_suffix;
    currentDirectory->GetObject(r_sel_70,h1); h1->Fill(event_pfMET,w);
    TString c_sel_70="h_pfMET_sel_70"+c_suffix;
    currentDirectory->GetObject(c_sel_70,h2); h2->Fill(event_pfMET,w);
        } else if (ieff==5) {
    h_pfMET_sel_60->Fill(event_pfMET,w);
    TString r_sel_60= "h_pfMET_sel_60"+r_suffix;
    currentDirectory->GetObject(r_sel_60,h1); h1->Fill(event_pfMET,w);
    TString c_sel_60="h_pfMET_sel_60"+c_suffix;
    currentDirectory->GetObject(c_sel_60,h2); h2->Fill(event_pfMET,w);
        }
      }

      //Fill templates after anti-selections for each efficiency point
      if (ieff==1 && !pass_dhi90) {
        h_pfMET_antiDhi_90->Fill(event_pfMET);
        if (fabs(eta_ele)<1.479) {
    h_pfMET_antiDhi_90_barl->Fill(event_pfMET);
        } else {
    h_pfMET_antiDhi_90_endc->Fill(event_pfMET);
        }
      }
      // both dh and df
      if ( (!pass_dhi90 && !pass_dfi90) ) {
        bool pass_eiso=false;
        if (useObservable=="Iso") {
    pass_eiso = true; //CheckCuts(probe_ecal_iso_user[ele]/probe_ele_et[ele], 0., 0., 0., 0., eta_ele,ieff);
        } else {
    pass_eiso = CheckCuts(probe_ele_combIso, 0., 0., 0., 0., eta_ele,ieff);
        }

        if (pass_eiso) {
    if (ieff==1) {
      h_pfMET_eiso80_antiDhiDfi90->Fill(event_pfMET,w);
      TString rr_sel_80= "h_pfMET_eiso80_antiDhiDfi90"+r_suffix;
      currentDirectory->GetObject(rr_sel_80,h3); h3->Fill(event_pfMET,w);
    } else if (ieff==3) {
      h_pfMET_eiso70_antiDhiDfi90->Fill(event_pfMET,w);
      TString rr_sel_70= "h_pfMET_eiso70_antiDhiDfi90"+r_suffix;
      currentDirectory->GetObject(rr_sel_70,h3); h3->Fill(event_pfMET,w);
    } else if (ieff==5) {
      h_pfMET_eiso60_antiDhiDfi90->Fill(event_pfMET,w);
      TString rr_sel_60= "h_pfMET_eiso60_antiDhiDfi90"+r_suffix;
      currentDirectory->GetObject(rr_sel_60,h3); h3->Fill(event_pfMET,w);
    }

        }
      }


    }
  }


  return true;
} // end of Process method

std::ostream& eWPolTemplateHistos::Description(std::ostream &ostrm) {
  ostrm << "eWPolTemplateHistos plots made here: (histograms in ";
  ostrm << mFolderName << ")";
  return ostrm;
}

bool eWPolTemplateHistos::passIsolation (double comb, double eta, int ieff)
{

  return CheckCuts(comb, 0.,0.,0., 0.,  eta, ieff );

}

bool eWPolTemplateHistos::passID (double sihih, double dfi, double dhi,double hoe, double eta, int ieff)
{

  return CheckCuts(0., sihih, dfi, dhi, hoe,  eta, ieff );

}

bool eWPolTemplateHistos::passConvRejection(bool expectedHits, double dist, double dcot, int ieff)
{
  //  if ( expectedHits == 1 &&
  if ( expectedHits  <=  ConvMissHits[ieff]    &&
       ( fabs(dist) >  ConvDist[ieff]   || fabs(dcot) >  ConvDcot[ieff] )
       ) return true;
  return false;
}


bool eWPolTemplateHistos::fid(double eta) {

  return  (fabs(eta)<2.5 && (  fabs(eta) < 1.4442  || fabs(eta) > 1.56 ));
}

bool eWPolTemplateHistos::CheckCuts(double v_iso,// double v_ecal, double v_hcal,
            double v_sihih, double v_dfi, double v_dhi, double v_hoe,
            double eta, int ieff)
{

  if (fabs(eta)< 1.479) {
    if ( v_iso  <  RelIso[ieff]    &&
         //        v_ecal <  Ecal[ieff]   &&
         //        v_hcal <  Hcal[ieff]   &&
         v_sihih < sihih[ieff]  &&
         fabs(v_dfi) < Dphi[ieff]   &&
         fabs(v_dhi) < Deta[ieff]   &&
         fabs(v_hoe)< HoE[ieff]
         ) return true;
  }
  else {
    if (corrEE){    if ( v_iso <  RelIso_ee[ieff]    &&
             //            v_ecal < Ecal_ee[ieff]   &&
             //            v_hcal < Hcal_ee[ieff]   &&
             v_sihih <sihih_ee[ieff]  &&
             fabs(dPhiCorr(v_dfi,v_dhi)) <Dphi_ee[ieff]   &&
             fabs(dEtaCorr(v_dfi,v_dhi)) <Deta_ee[ieff]     &&
             fabs(v_hoe)< HoE_ee[ieff]
             ) return true;}
    else{
    if ( v_iso <  RelIso_ee[ieff]    &&
         //        v_ecal < Ecal_ee[ieff]   &&
         //        v_hcal < Hcal_ee[ieff]   &&
         v_sihih <sihih_ee[ieff]  &&
         fabs(v_dfi) <Dphi_ee[ieff]   &&
         fabs(v_dhi) <Deta_ee[ieff]     &&
         fabs(v_hoe)< HoE_ee[ieff]
         ) return true;
    }
  }
  return false;
}
float  eWPolTemplateHistos::dPhiCorr(double elePhi , double eleEta){
    double C, D, A;
    if (eleEta>1.479){
      C = 0.0;  D = 0.52; A = 2.17;
    }
    else if (eleEta<-1.479){
      C = 0.0; D = 0.45; A = -1.58;
         }
    else return 0;
    return C + (D/325.)*sinh(eleEta)*sin(A-elePhi);
  }
float  eWPolTemplateHistos::dEtaCorr(double elePhi , double eleEta){
    double C, DZ, D, A;
    if (eleEta>1.479){
      C = 0.0013; DZ = -0.06; D = 0.52; A = 2.17;
    }
    else if (eleEta<-1.479){
      C = -0.0013; DZ = -0.32; D = 0.45; A = -1.58;
    }
    else return 0;
    return C + (tanh(eleEta)/325.)*(DZ-D*sinh(eleEta)*cos(elePhi-A));
  }
}
