#include "RECOCSFramePlots.hh"
namespace Operation {

  //====================================
  // RECOCSFramePlots implementation
  //====================================
  RECOCSFramePlots::RECOCSFramePlots(const std::string & folderName, const std::string & VBoson, bool Gen) :
    mFolderName(folderName),
    mVBoson(VBoson),
    doGen(Gen) {}

  RECOCSFramePlots::~RECOCSFramePlots() {}

  void RECOCSFramePlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void RECOCSFramePlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    RECO_CSWMuonPlusPhi = new TH1D("RECO_CSWMuonPlusPhi",";gen #mu^{+} #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuonPlusPhi2 = new TH1D("RECO_CSWMuonPlusPhi2",";gen #mu^{+} #phi in CS-Frame;Events / 10 pb^{-1}",700,-0.05,6.95);
    RECO_CSWMuonMinusPhi = new TH1D("RECO_CSWMuonMinusPhi",";gen #mu^{-} #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuonMinusPhi2 = new TH1D("RECO_CSWMuonMinusPhi2",";gen #mu^{-} #phi in CS-Frame;Events / 10 pb^{-1}",700,-0.05,6.95);
    RECO_CSWMuonPlusCosTheta = new TH1D("RECO_CSWMuonPlusCosTheta",";gen #mu^{+} cos#theta in CS-Frame;Events / 10 pb^{-1}",200,-1.05,0.95);
    RECO_CSWMuonMinusCosTheta = new TH1D("RECO_CSWMuonMinusCosTheta",";gen #mu^{-} cos#theta in CS-Frame;Events / 10 pb^{-1}",200,-1.05,0.95);
    RECO_CSWTransMass = new TH1D("RECO_CSWTransMass", ";W Transverse Mass [GeV/c^{2}]; Events / 10 pb^{-1}", 200, -0.5, 199.5);

    RECO_CSWMuon2PlusPhi = new TH1D("RECO_CSWMuon2PlusPhi",";RECO #mu^{+} #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2PlusPhi_A = new TH1D("RECO_CSWMuon2PlusPhi_A",";RECO #mu^{+} #phi in CS-Frame reweightedA;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2PlusPhi_B = new TH1D("RECO_CSWMuon2PlusPhi_B",";RECO #mu^{+} #phi in CS-Frame reweightedB;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2PlusPhi_C = new TH1D("RECO_CSWMuon2PlusPhi_C",";RECO #mu^{+} #phi in CS-Frame reweightedC;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2MinusPhi = new TH1D("RECO_CSWMuon2MinusPhi",";RECO #mu^{-} #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2MinusPhi_A = new TH1D("RECO_CSWMuon2MinusPhi_A",";RECO #mu^{-} #phi in CS-Frame reweightedA;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2MinusPhi_B = new TH1D("RECO_CSWMuon2MinusPhi_B",";RECO #mu^{-} #phi in CS-Frame reweightedB;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2MinusPhi_C = new TH1D("RECO_CSWMuon2MinusPhi_C",";RECO #mu^{-} #phi in CS-Frame reweightedC;Events / 10 pb^{-1}",700,-3.55,3.45);
    RECO_CSWMuon2PlusCosTheta = new TH1D("RECO_CSWMuon2PlusCosTheta",";RECO #mu^{+} cos#theta in CS-Frame;Events / 10 pb^{-1}",300,-1.5,1.5);
    RECO_CSWMuon2PlusCosTheta_A = new TH1D("RECO_CSWMuon2PlusCosTheta_A",";RECO #mu^{+} cos#theta in CS-Frame reweightedA;Events / 10 pb^{-1}",300,-1.5,1.5);
    RECO_CSWMuon2PlusCosTheta_B = new TH1D("RECO_CSWMuon2PlusCosTheta_B",";RECO #mu^{+} cos#theta in CS-Frame reweightedB;Events / 10 pb^{-1}",300,-1.5,1.5);
    RECO_CSWMuon2PlusCosTheta_C = new TH1D("RECO_CSWMuon2PlusCosTheta_C",";RECO #mu^{+} cos#theta in CS-Frame reweightedC;Events / 10 pb^{-1}",300,-1.5,1.5);
    RECO_CSWMuon2MinusCosTheta = new TH1D("RECO_CSWMuon2MinusCosTheta",";RECO #mu^{-} cos#theta in CS-Frame;Events / 10 pb^{-1}",300,-1.5,1.5);

    TH1::SetDefaultSumw2(kFALSE);
    MC_RECO_CSWMuonPhiCorrelation1 = new TH2D("MC_RECO_CSWMuonPhiCorrelation1", "; Reconstructed Muon #phi; True Muon #phi", 700,-3.55,3.45, 700,-3.55,3.45 );
    MC_RECO_CSWMuonPhiCorrelation2 = new TH2D("MC_RECO_CSWMuonPhiCorrelation2", "; Reconstructed Muon #phi; True Muon #phi", 700,-3.55,3.45, 700,-3.55,3.45 );
    MC_RECO_CSWMuonPhiCorrelation3 = new TH2D("MC_RECO_CSWMuonPhiCorrelation3", "; Reconstructed Muon #phi; True Muon #phi", 700,-3.55,3.45, 700,-3.55,3.45 );
    MC_RECO_CSWMuonPhiCorrelation4 = new TH2D("MC_RECO_CSWMuonPhiCorrelation4", "; Reconstructed Muon #phi; True Muon #phi", 700,-3.55,3.45, 700,-3.55,3.45 );
  }

bool RECOCSFramePlots::Process(Event::Data & ev)
{

  if(TString(mVBoson)=="W") {forW = true;forZ = false;}
  if(TString(mVBoson)=="Z") {forW = false;forZ = true;}
  if(TString(mVBoson)!="Z" && TString(mVBoson)!="W") cout << "RECOCSFramePlots: Error invalid Vector Boson choice!" << endl;

  //initialise genmatrixbin using the default constructor - do this so we can use with real data ntuples (i.e. no gen info) without breaking anything
  GenMatrixBin myGenMatrixBin;

  if(doGen) {
    myGenMatrixBin = GenMatrixBin(&ev);
    if((myGenMatrixBin.the_GenMuon.size()==0 && myGenMatrixBin.the_GenTau.size()==0)) doGen=false;
  }

  std::vector <Event::GenObject const *> theVBosons;
  Event::GenObject const * theGenLepton;

  TLorentzVector reco_muon;
  TLorentzVector reco_boson;
  TLorentzVector real_lepton;
  TLorentzVector lepton;

  double w_pole_mass = 80.4;
  bool yesSolutions = false;//as opposed to no solutions :)

  if(forW) {
    if(ev.LD_CommonMuons().accepted.size()!=1) return false;
    reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(0));
    if(doGen) {
      if(myGenMatrixBin.the_GenW.size()==0) return false;
      theVBosons = myGenMatrixBin.the_GenW;
    }
  }
  if(forZ) {
    if(ev.LD_CommonMuons().accepted.size() != 2) return false;
    //make the choice of whether to use the positively of negatively charged muon from the Z-decay
    if(ev.LD_CommonMuons().accepted.at(0)->GetCharge() > 0.0) reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(0));
    else if(ev.LD_CommonMuons().accepted.at(1)->GetCharge() > 0.0) reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(1));
    else return false; //i.e. they can't both have the same charge!

    if(doGen) {
      if(myGenMatrixBin.the_GenZ.size()==0) return false;
      theVBosons = myGenMatrixBin.the_GenZ;
    }
  }

  if(doGen) {
    //let us cheat and use the RECO muon, along with the generator W-boson that is defined in the same event
    //this will show us the effect of (essentially) the muon reconstruction
    lepton = CSTransform( reco_muon, TLVConvert(theVBosons.at(0)));
    double adjusted_phi=0.0;
    //add 2Pi to the negative values of Phi to take it from [-pi,+pi] to [0,2pi]
    if(lepton.Phi() < 0.0) adjusted_phi = ((2.0*TMath::Pi()) + lepton.Phi());
    else adjusted_phi = lepton.Phi();

    if( forZ || (forW && ev.LD_CommonMuons().accepted.at(0)->GetCharge() > 0.0) ) { //by our convention of choosing positive charge for Z
      RECO_CSWMuonPlusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      RECO_CSWMuonPlusPhi2->Fill(adjusted_phi, ev.GetEventWeight());
      RECO_CSWMuonPlusCosTheta->Fill(lepton.CosTheta(), ev.GetEventWeight());
    } else {
      RECO_CSWMuonMinusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      RECO_CSWMuonMinusPhi2->Fill(adjusted_phi, ev.GetEventWeight());
      RECO_CSWMuonMinusCosTheta->Fill(lepton.CosTheta(), ev.GetEventWeight());
    }

    //in this bit of code, we set up the generator lepton which caused us to enter this cut flow
    //either the gen lepton was a muon, or a tau that decayed - in the Z case, it was either Z->mumu or Z->tautau (pick the positively charged lepton)
    if((myGenMatrixBin.the_GenMuon.size() > 0 && myGenMatrixBin.the_GenTau.size() == 0) || (myGenMatrixBin.the_GenMuon.size() == 0 && myGenMatrixBin.the_GenTau.size() > 0)) {
      if(myGenMatrixBin.the_GenMuon.size() > 0) {
	if(forW) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
	else if(forZ && myGenMatrixBin.the_GenMuon.at(0)->GetID() < 0 ) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
	else theGenLepton = myGenMatrixBin.the_GenMuon.at(1);
      }
      if(myGenMatrixBin.the_GenTau.size() > 0) {
	if(forW) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
	else if(forZ && myGenMatrixBin.the_GenTau.at(0)->GetID() < 0 ) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
	else theGenLepton = myGenMatrixBin.the_GenTau.at(1);
      }
    }

    real_lepton = CSTransform( TLVConvert(theGenLepton), TLVConvert(theVBosons.at(0)));
    MC_RECO_CSWMuonPhiCorrelation1->Fill(lepton.Phi(), real_lepton.Phi(), ev.GetEventWeight());
  }

  if(forW) {

    //so we need to make a choice for Pz and Mw to use in an event:
    //For Mw, let's try to use MtW if it's larger than the pole mass (80.4) otherwise use the pole mass
    //The transverse mass is defined with the pt of the neutrino and lepton

    TLorentzVector reco_neutrino;
    LorentzV pfMHT = ev.PFMET() + *(ev.LD_CommonMuons().accepted.at(0));

    //subtract the muon from the MHT (i.e. add it in) so that we have the transverse vector for the neutrino
    //double reco_neutrino_Px = ev.CommonMHT().Px() - reco_muon.Px();
    //double reco_neutrino_Py = ev.CommonMHT().Py() - reco_muon.Py();
    //change definition to pfMET
    double reco_neutrino_Px = ev.PFMET().Px();
    double reco_neutrino_Py = ev.PFMET().Py();
    reco_neutrino.SetXYZM(reco_neutrino_Px, reco_neutrino_Py, 0.0, 0.0);

    //define the transverse mass of the W - which of course only uses transverse quantities
    double w_trans_mass = sqrt( 2.0*reco_muon.Pt()*reco_neutrino.Pt()*(1.0 - cos(reco_muon.DeltaPhi(reco_neutrino)) ) );
    RECO_CSWTransMass->Fill(w_trans_mass, ev.GetEventWeight());

    double adjusted_mass = w_pole_mass;
    if(w_trans_mass > w_pole_mass) adjusted_mass = w_trans_mass;

    if(doGen) {
      //to see the effects of modifying the W mass but otherwise keeping everything the same
      TLorentzVector W_adjusted_mass;
      //use the transverse mass if larger than the pole mass (otherwise pole mass)
      W_adjusted_mass.SetXYZM(theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), adjusted_mass);
      TLorentzVector lepton_adjWmass( CSTransform( TLVConvert(theGenLepton), W_adjusted_mass ) );
      MC_RECO_CSWMuonPhiCorrelation2->Fill(lepton_adjWmass.Phi(), real_lepton.Phi(), ev.GetEventWeight());
    }

    //if we want to do a full "reco"
    //work out the neutrino pz using the four-vector algebra. Do this first with the proper gen level W-boson mass
    //this is so we can check the effects of taking the positive and negative root have on phi - it should be independent...
    //double constantA = (adjusted_mass*adjusted_mass) + (ev.CommonMHT().Perp2()) - (reco_muon.Perp2()) - (reco_neutrino.Perp2());
    double constantA = (adjusted_mass*adjusted_mass) + (pfMHT.Perp2()) - (reco_muon.Perp2()) - (reco_neutrino.Perp2());
    double constantB = (constantA * constantA) - (4.0 * (reco_muon.Perp2()) * (reco_neutrino.Perp2() ));
    if(constantB > 0) {
      double constantC = (2.0 * reco_muon.Perp2()); //paper says 4.0, i think 2.0 - let's see... it's 2.0! hehe
      double constantD = ((constantA * reco_muon.Pz()) / constantC);
      double constantE = ((reco_muon.E() * sqrt(constantB)) / constantC);
      //these solutions are the pz of the neutrino:
      double pzsol1 = (constantD + constantE);
      double pzsol2 = (constantD - constantE);
      pzsol1 += reco_muon.Pz();
      pzsol2 += reco_muon.Pz();
      //the "W-boson" we construct will have MHTX, MHTY, (pz_Neutrino + pz_Muon), Mass we choose - choice of pz solution shouldn't matter
      reco_boson.SetXYZM(pfMHT.Px(),pfMHT.Py(),pzsol1, adjusted_mass);
      yesSolutions = true;
    }
  }

  if(forZ) {
    //we need to construct the reco_zboson from the two muons - much easier!!
    reco_boson = TLVConvert(ev.LD_CommonMuons().accepted.at(0)) + TLVConvert(ev.LD_CommonMuons().accepted.at(1));
    yesSolutions = true;
  }


  if(yesSolutions) {
    //you can only be sure that the reco_boson makes sense if the discriminant above is > 0, otherwise it's =0 - so include this step inside the if(yesSolutions)
    TLorentzVector lepton_reco( CSTransform( reco_muon, reco_boson ) );
    
    //this correlation compares the reco_lepton to the true lepton in the CS-frame
    if(doGen) MC_RECO_CSWMuonPhiCorrelation3->Fill(lepton_reco.Phi(), real_lepton.Phi(), ev.GetEventWeight());
    
    if(forZ || (forW && ev.LD_CommonMuons().accepted.at(0)->GetCharge() > 0.0)) {
      RECO_CSWMuon2PlusPhi->Fill(lepton_reco.Phi(), ev.GetEventWeight());
      RECO_CSWMuon2PlusCosTheta->Fill(lepton_reco.CosTheta(), ev.GetEventWeight());

      //what we need is the generator lepton to make the templates, so we know which phi bin the gen_lepton is in, and what factor we need to reweight it by
      if(doGen) {
	if(theGenLepton->GetID() < 0) {
	  TLorentzVector gen_lepton (CSTransform( TLVConvert(theGenLepton), TLVConvert(theVBosons.at(0))));
	  int index = int( (gen_lepton.Phi() + 3.15) / 0.01 );
	  int index2 = int( (gen_lepton.CosTheta() + 1.00) / 0.01 );
	  if(forW) {
	    RECO_CSWMuon2PlusPhi_A->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0, TString("W")));
	    RECO_CSWMuon2PlusPhi_B->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1, TString("W")));
	    RECO_CSWMuon2PlusPhi_C->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2, TString("W")));
	  }
	  if(forZ) { //again, by our choice of taking the positive charge only from Z decay
	    RECO_CSWMuon2PlusPhi_A->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0, TString("Z")));
	    RECO_CSWMuon2PlusPhi_B->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1, TString("Z")));
	    RECO_CSWMuon2PlusPhi_C->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2, TString("Z")));
	    RECO_CSWMuon2PlusCosTheta_A->Fill(lepton_reco.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,0, TString("Z")));
	    RECO_CSWMuon2PlusCosTheta_B->Fill(lepton_reco.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,1, TString("Z")));
	    RECO_CSWMuon2PlusCosTheta_C->Fill(lepton_reco.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,2, TString("Z")));
	  }
	}
      }

    } else {
      RECO_CSWMuon2MinusPhi->Fill(lepton_reco.Phi(), ev.GetEventWeight());
      RECO_CSWMuon2MinusCosTheta->Fill(lepton_reco.CosTheta(), ev.GetEventWeight());

      if(doGen) {
	if(theGenLepton->GetID() > 0) {
	  TLorentzVector gen_lepton (CSTransform( TLVConvert(theGenLepton), TLVConvert(theVBosons.at(0))));
	  int index = int( (gen_lepton.Phi() + 3.15) / 0.01 );
	  if(forW) {
	    RECO_CSWMuon2MinusPhi_A->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0, TString("W")));
	    RECO_CSWMuon2MinusPhi_B->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1, TString("W")));
	    RECO_CSWMuon2MinusPhi_C->Fill(lepton_reco.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2, TString("W")));
	  }
	}
      }

    }
  }


  return true;
}

  std::ostream& RECOCSFramePlots::Description(std::ostream &ostrm) {
    ostrm << "RECO Collins-Soper Frame Plots";
    return ostrm;
  }


 
} // ~namespace Operation
