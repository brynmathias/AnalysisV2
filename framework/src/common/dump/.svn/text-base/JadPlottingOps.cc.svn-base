/*! \file JadPlottingOps.cc
 * \brief Source code for the Monte Carlo-based plotting operations.
 */
#include "JadPlottingOps.hh"
#include "GenObject.hh"
#include "GenMatrixBin.hh"
#include "Lepton.hh"
#include "EventData.hh"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "TH1.h"
#include <sstream>
#include <iostream>

namespace Operation {

  //====================================
  // Boost Calculation Function 
  //====================================

  jSolutionsW FindBoost(const TLorentzVector & jMuon, const double & jVWPx, const double & jVWPy, const double & jVWPz, const bool & cheat=true, const bool & approximate=true, const double & jVWM=80.4) {
    //by having the function in this form, you can slot various combinations for the (px,py,pz) components
    //the cheat variable allows you to choose if you want sol1/sol2 or rightsol/wrongsol - for this you need to pass jVWPz of the real W
    //the approximate variable allows you to choose if you want the approximation using mw=80.4, or the true generator boost back to the W rest frame - must supply jVWM
    //the cheat variable is redundant if the approximate variable is set to false

    //you can follow this calculation if you start from the four-vector argument P_W = P_Mu + P_MuNu and rearrange so P_MuNu is on its own.
    //then square both sides, taking mass_neutrino = 0. Also the dot product of two threevectors is p1xp2x+p1yp2y+p1zp2z and not p1 p2 cos(theta_12)
    //since theta_12 relies on knowing the pz components...

    jSolutionsW results;
    TLorentzVector jRestMu, jTemp4V;
    TVector3 jTempBV;
    double CosThetaStarSol1, CosThetaStarSol2;

    if(approximate) {
      double jVWPt2 = ((jVWPx * jVWPx) + (jVWPy * jVWPy)); //this is the Pt squared
      double delta = ((80.4*80.4)+(0.106*0.106))/2.0 + (jVWPx * jMuon.Px()) + (jVWPy * jMuon.Py());
      double alpha = (jMuon.E() * jMuon.E()) - (jMuon.Pz() * jMuon.Pz());
      double beta = -2.0 * delta * jMuon.Pz();
      double gamma = (jMuon.E() * jMuon.E()) * (jVWPt2 + (80.4*80.4)) - (delta * delta);
      double discarg = (beta*beta) - (4*alpha*gamma);

      if(discarg > 0) {
	double discriminant = sqrt(discarg);
	double sol1 = (-1.0*beta + discriminant) / (2*alpha);
	double sol2 = (-1.0*beta - discriminant) / (2*alpha);

	results.realSolutions = true; //since the discriminant is >0, we get real solutions

	jRestMu = jMuon;
	jTemp4V.SetXYZM(jVWPx,jVWPy,sol1,80.4);
	jTempBV = jTemp4V.BoostVector();
	jRestMu.Boost(-jTempBV);
	CosThetaStarSol1 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jTemp4V));

	jRestMu = jMuon;
	jTemp4V.SetXYZM(jVWPx,jVWPy,sol2,80.4);
	jTempBV = jTemp4V.BoostVector();
	jRestMu.Boost(-jTempBV);
	CosThetaStarSol2 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jTemp4V));

	if(cheat) {
	  if(fabs(sol1 - jVWPz) < fabs(sol2 - jVWPz)) {
	    results.rightSol = CosThetaStarSol1;
	    results.wrongSol = CosThetaStarSol2;
	  } else {
	    results.rightSol = CosThetaStarSol2;
	    results.wrongSol = CosThetaStarSol1;
	  }
	  results.sol1 = 0.0;
	  results.sol2 = 0.0;
	  return results;
	} else {
	  results.rightSol = 0.0;
	  results.wrongSol = 0.0;
	  results.sol1 = CosThetaStarSol1;
	  results.sol2 = CosThetaStarSol2;
	  return results;
	}
      } else {
	results.realSolutions = false;
	results.rightSol = 0.0;
	results.wrongSol = 0.0;
	results.sol1 = 0.0;
	results.sol2 = 0.0;
	return results;
      }
    } else {
      jRestMu = jMuon;
      jTemp4V.SetXYZM(jVWPx,jVWPy,jVWPz,jVWM);
      jTempBV = jTemp4V.BoostVector();
      jRestMu.Boost(-jTempBV);
      CosThetaStarSol1 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jTemp4V));

      results.realSolutions = true;
      results.rightSol = CosThetaStarSol1;
      results.wrongSol = 0.0;
      results.sol1 = 0.0;
      results.sol2 = 0.0;
      return results;
    }

  }


  //====================================
  // MCWPlots implementation 
  //====================================
  
  MCWPlots::MCWPlots(const std::string & folderName) :
    mFolderName(folderName) {}
   
  MCWPlots::~MCWPlots() {}

  void MCWPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MCWPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    MC_WMultiplicity = new TH1D("MC_WMultiplicity", ";genW Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_MuonMultiplicity = new TH1D("MC_MuonMultiplicity", ";genMuon Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_MuonNuMultiplicity = new TH1D("MC_MuonNuMultiplicity", ";genMuonNu Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_JetMultiplicity = new TH1D("MC_JetMultiplicity",";genJet Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_JetMultiplicityAll = new TH1D("MC_JetMultiplicityAll",";All genJet Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_JetPt = new TH1D("MC_JetPt",";genJet P_{T} distribution;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_JetEta = new TH1D("MC_JetEta",";genJet #eta distribution;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_JetPtAll = new TH1D("MC_JetPtAll",";All genJet P_{T} distribution;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_JetEtaAll = new TH1D("MC_JetEtaAll",";All genJet #eta distribution;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_JetMHT = new TH1D("MC_JetMHT",";genJet MHT magnitude;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_JetMHT2 = new TH1D("MC_JetMHT2",";genJet MHT2 magnitude;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_VirtualWMass = new TH1D("MC_VirtualWMass",";Virtual W Mass;Events / 100 pb^{-1}",400,59.5,99.5);
    MC_VirtualWMassRe = new TH1D("MC_VirtualWMassRe",";Virtual W Mass for real solutions to pz;Events / 100 pb^{-1}",400,59.5,99.5);
    MC_VirtualWMassIm = new TH1D("MC_VirtualWMassIm",";Virtual W Mass for imaginary solutions to pz;Events / 100 pb^{-1}",400,59.5,99.5);
    MC_WPT = new TH1D("MC_WPT", ";genW P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WPtPlus = new TH1D("MC_WPtPlus", ";genW^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WPtMinus = new TH1D("MC_WPtMinus", ";genW^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WEtaPlus = new TH1D("MC_WEtaPlus",";genW^{+} #eta;Events / 100 pb^{-1}", 50,-0.5,4.5);
    MC_WEtaMinus = new TH1D("MC_WEtaMinus",";genW^{-} #eta;Events / 100 pb^{-1}", 50,-0.5,4.5);
    MC_MHTGenJetsWPtDiff = new TH1D("MC_MHTGenJetsWPtDiff",";#Delta (MH_{T}, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MHTAllGenJetsWPtDiff = new TH1D("MC_MHTAllGenJetsWPtDiff",";#Delta (MH_{T}, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MHT2GenJetsWPtDiff = new TH1D("MC_MHT2GenJetsWPtDiff",";#Delta (MH_{T}2, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonPt = new TH1D("MC_MuonPt", ";genW to #mu P_{T} ;Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_MuonEta = new TH1D("MC_MuonEta",";genW to #mu #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaAbs = new TH1D("MC_MuonEtaAbs",";genW to #mu |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_MuonNuPt = new TH1D("MC_MuonNuPt", ";genW to #mu #nu P_{T} ;Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_MuonNuEta = new TH1D("MC_MuonNuEta",";genW to #mu #nu #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuEtaAbs = new TH1D("MC_MuonNuEtaAbs",";genW to #mu #nu |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);

    MC_MuonPtCut1 = new TH1D("MC_MuonPtCut1",";#mu P_{T}, p_{T} > 10 GeV |#eta| < 2.1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonPtCut2 = new TH1D("MC_MuonPtCut2",";#mu P_{T}, p_{T} > 20 GeV |#eta| < 2.1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonEtaCut1 = new TH1D("MC_MuonEtaCut1",";#mu #eta, p_{T} > 10 GeV |#eta| < 2.1;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaCut2 = new TH1D("MC_MuonEtaCut2",";#mu #eta, p_{T} > 20 GeV |#eta| < 2.1;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuPtCut1 = new TH1D("MC_MuonNuPtCut1",";#mu #nu P_{T}, p_{T} > 10 GeV |#eta| < 2.1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtCut2 = new TH1D("MC_MuonNuPtCut2",";#mu #nu P_{T}, p_{T} > 20 GeV |#eta| < 2.1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuEtaCut1 = new TH1D("MC_MuonNuEtaCut1",";#mu #nu #eta, p_{T} > 10 GeV |#eta| < 2.1;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuEtaCut2 = new TH1D("MC_MuonNuEtaCut2",";#mu #nu #eta, p_{T} > 20 GeV |#eta| < 2.1;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuPtCut1Plus = new TH1D("MC_MuonNuPtCut1Plus",";#mu^{+} #nu p_{T} cut1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonPtCut1Plus = new TH1D("MC_MuonPtCut1Plus",";#mu^{+} p_{T} cut1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtCut1Minus = new TH1D("MC_MuonNuPtCut1Minus",";#mu^{-} #nu p_{T} cut1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonPtCut1Minus = new TH1D("MC_MuonPtCut1Minus",";#mu^{-} p_{T} cut1;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtCut2Plus = new TH1D("MC_MuonNuPtCut2Plus",";#mu^{+} #nu p_{T} cut2;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonPtCut2Plus = new TH1D("MC_MuonPtCut2Plus",";#mu^{+} p_{T} cut2;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtCut2Minus = new TH1D("MC_MuonNuPtCut2Minus",";#mu^{-} #nu p_{T} cut2;Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonPtCut2Minus = new TH1D("MC_MuonPtCut2Minus",";#mu^{-} p_{T} cut2;Events / 100 pb^{-1}",1000,-0.5,999.5);

    MC_MuonPtPlus = new TH1D("MC_MuonPtPlus",";#mu^+ P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtPlus = new TH1D("MC_MuonNuPtPlus",";#mu^+ #nu P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonEtaPlus = new TH1D("MC_MuonEtaPlus",";#mu^+ #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaAbsPlus = new TH1D("MC_MuonEtaAbsPlus",";#mu^+ |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_MuonNuEtaPlus = new TH1D("MC_MuonNuEtaPlus",";#mu^+ #nu #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuEtaAbsPlus = new TH1D("MC_MuonNuEtaAbsPlus",";#mu^+ #nu |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_ICVarPlus = new TH1D("MC_ICVarPlus",";IC Variable #mu^+;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_MuonPtMinus = new TH1D("MC_MuonPtMinus",";#mu^- P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtMinus = new TH1D("MC_MuonNuPtMinus",";#mu^- #nu P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonEtaMinus = new TH1D("MC_MuonEtaMinus",";#mu^- #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaAbsMinus = new TH1D("MC_MuonEtaAbsMinus",";#mu^- |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_MuonNuEtaMinus = new TH1D("MC_MuonNuEtaMinus",";#mu^- #nu #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuEtaAbsMinus = new TH1D("MC_MuonNuEtaAbsMinus",";#mu^- #nu |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_ICVarMinus = new TH1D("MC_ICVarMinus",";IC Variable #mu^-;Events / 100 pb^{-1}",500,-2.5,2.5);

    MC_WPlusPzMatching = new TH1D("MC_WPlusPzMatching",";False/True;Events",2,-0.5,1.5);
    MC_WMinusPzMatching = new TH1D("MC_WMinusPzMatching",";False/True;Events",2,-0.5,1.5);
    MC_CosThetaStar1Plus = new TH1D("MC_CosThetaStar1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus = new TH1D("MC_CosThetaStar1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar2Plus = new TH1D("MC_CosThetaStar2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar2Minus = new TH1D("MC_CosThetaStar2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar3Plus = new TH1D("MC_CosThetaStar3Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar3Minus = new TH1D("MC_CosThetaStar3Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    //for W Eta bins
    MC_CosThetaStar1RightPzWEtaBin1Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin1Plus",";cos #theta^{*} from W^{+} #eta < 0.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin1Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin1Minus",";cos #theta^{*} from W^{-} #eta < 0.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin2Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin2Plus",";cos #theta^{*} from W^{+} 0.5 < #eta < 1.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin2Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin2Minus",";cos #theta^{*} from W^{-} 0.5 < #eta < 1.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin3Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin3Plus",";cos #theta^{*} from W^{+} 1.0 < #eta < 1.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin3Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin3Minus",";cos #theta^{*} from W^{-} 1.0 < #eta < 1.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin4Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin4Plus",";cos #theta^{*} from W^{+} 1.5 < #eta < 2.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin4Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin4Minus",";cos #theta^{*} from W^{-} 1.5 < #eta < 2.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin5Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin5Plus",";cos #theta^{*} from W^{+} 2.0 < #eta < 2.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin5Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin5Minus",";cos #theta^{*} from W^{-} 2.0 < #eta < 2.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin6Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin6Plus",";cos #theta^{*} from W^{+} 2.5 < #eta < 3.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin6Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin6Minus",";cos #theta^{*} from W^{-} 2.5 < #eta < 3.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin7Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin7Plus",";cos #theta^{*} from W^{+} 3.0 < #eta < 3.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin7Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin7Minus",";cos #theta^{*} from W^{-} 3.0 < #eta < 3.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin8Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin8Plus",";cos #theta^{*} from W^{+} 3.5 < #eta < 4.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin8Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin8Minus",";cos #theta^{*} from W^{-} 3.5 < #eta < 4.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin9Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin9Plus",";cos #theta^{*} from W^{+} 4.0 < #eta < 4.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin9Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin9Minus",";cos #theta^{*} from W^{-} 4.0 < #eta < 4.5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin10Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin10Plus",";cos #theta^{*} from W^{+} 4.5 < #eta < 5.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin10Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin10Minus",";cos #theta^{*} from W^{-} 4.5 < #eta < 5.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin11Plus = new TH1D("MC_CosThetaStar1RightPzWEtaBin11Plus",";cos #theta^{*} from W^{+} #eta > 5.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWEtaBin11Minus = new TH1D("MC_CosThetaStar1RightPzWEtaBin11Minus",";cos #theta^{*} from W^{-} #eta > 5.0;Events / 100 pb^{-1}",300,-1.5,1.5);
    //for W Pt bins
    MC_CosThetaStar1RightPzWPtBin1Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin1Plus",";cos #theta^{*} from W^{+} 100 < p_{T} < 200 ;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin1Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin1Minus",";cos #theta^{*} from W^{-} 100 < p_{T} < 200;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin2Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin2Plus",";cos #theta^{*} from W^{+} 200 < p_{T} < 300;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin2Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin2Minus",";cos #theta^{*} from W^{-} 200 < p_{T} < 300;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin3Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin3Plus",";cos #theta^{*} from W^{+} 300 < p_{T} < 400;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin3Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin3Minus",";cos #theta^{*} from W^{-} 300 < p_{T} < 400;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin4Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin4Plus",";cos #theta^{*} from W^{+} 400 < p_{T} < 500;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin4Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin4Minus",";cos #theta^{*} from W^{-} 400 < p_{T} < 500;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin5Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin5Plus",";cos #theta^{*} from W^{+} 500 < p_{T} < 600;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin5Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin5Minus",";cos #theta^{*} from W^{-} 500 < p_{T} < 600;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin6Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin6Plus",";cos #theta^{*} from W^{+} 600 < p_{T} < 700;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin6Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin6Minus",";cos #theta^{*} from W^{-} 600 < p_{T} < 700;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin7Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin7Plus",";cos #theta^{*} from W^{+} 700 < p_{T} < 800;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin7Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin7Minus",";cos #theta^{*} from W^{-} 700 < p_{T} < 800;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin8Plus = new TH1D("MC_CosThetaStar1RightPzWPtBin8Plus",";cos #theta^{*} from W^{+} 800 < p_{T} < 900;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWPtBin8Minus = new TH1D("MC_CosThetaStar1RightPzWPtBin8Minus",";cos #theta^{*} from W^{-} 800 < p_{T} < 900;Events / 100 pb^{-1}",300,-1.5,1.5);
    //for jet multiplicity bins
    MC_CosThetaStar1RightPzWJetBin1Plus = new TH1D("MC_CosThetaStar1RightPzWJetBin1Plus",";cos #theta^{*} from W^{+} num jets = 0 ;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin1Minus = new TH1D("MC_CosThetaStar1RightPzWJetBin1Minus",";cos #theta^{*} from W^{-} num jets = 0;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin2Plus = new TH1D("MC_CosThetaStar1RightPzWJetBin2Plus",";cos #theta^{*} from W^{+} num jets = 1;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin2Minus = new TH1D("MC_CosThetaStar1RightPzWJetBin2Minus",";cos #theta^{*} from W^{-} num jets = 1;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin3Plus = new TH1D("MC_CosThetaStar1RightPzWJetBin3Plus",";cos #theta^{*} from W^{+} num jets = 2;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin3Minus = new TH1D("MC_CosThetaStar1RightPzWJetBin3Minus",";cos #theta^{*} from W^{-} num jets = 2;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin4Plus = new TH1D("MC_CosThetaStar1RightPzWJetBin4Plus",";cos #theta^{*} from W^{+} num jets = 3;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin4Minus = new TH1D("MC_CosThetaStar1RightPzWJetBin4Minus",";cos #theta^{*} from W^{-} num jets = 3;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin5Plus = new TH1D("MC_CosThetaStar1RightPzWJetBin5Plus",";cos #theta^{*} from W^{+} num jets = 4;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin5Minus = new TH1D("MC_CosThetaStar1RightPzWJetBin5Minus",";cos #theta^{*} from W^{-} num jets = 4;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin6Plus = new TH1D("MC_CosThetaStar1RightPzWJetBin6Plus",";cos #theta^{*} from W^{+} num jets = 5;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzWJetBin6Minus = new TH1D("MC_CosThetaStar1RightPzWJetBin6Minus",";cos #theta^{*} from W^{-} num jets = 5;Events / 100 pb^{-1}",300,-1.5,1.5);

    MC_CosThetaStar1WrongPzPlus = new TH1D("MC_CosThetaStar1WrongPzPlus",";cos #theta^{*} from wrongly p_{z} boosted W^{+} ;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMinus = new TH1D("MC_CosThetaStar1WrongPzMinus",";cos #theta^{*} from wrongly p_{z} boosted W^{-} ;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzPlus = new TH1D("MC_CosThetaStar1RightPzPlus",";cos #theta^{*} from correctly p_{z} boosted W^{+} ;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMinus = new TH1D("MC_CosThetaStar1RightPzMinus",";cos #theta^{*} from correctly p_{z} boosted W^{-} ;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMHT2Plus = new TH1D("MC_CosThetaStar1WrongPzMHT2Plus",";cos #theta^{*} from wrongly p_{z} boosted W^{+} MHT2;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMHT2Minus = new TH1D("MC_CosThetaStar1WrongPzMHT2Minus",";cos #theta^{*} from wrongly p_{z} boosted W^{-} MHT2;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMHT2Plus = new TH1D("MC_CosThetaStar1RightPzMHT2Plus",";cos #theta^{*} from correctly p_{z} boosted W^{+} MHT2;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMHT2Minus = new TH1D("MC_CosThetaStar1RightPzMHT2Minus",";cos #theta^{*} from correctly p_{z} boosted W^{-} MHT2;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMuonMinus = new TH1D("MC_CosThetaStar1WrongPzMuonMinus","cos #theta^{*} from wrongly p_{z} boosted W^{-} + #mu cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMuonPlus = new TH1D("MC_CosThetaStar1WrongPzMuonPlus",";cos #theta^{*} from wrongly p_{z} boosted W^{+} + #mu cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMuonMinus = new TH1D("MC_CosThetaStar1RightPzMuonMinus",";cos #theta^{*} from rightly p_{z} boosted W^{-} + #mu cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMuonPlus = new TH1D("MC_CosThetaStar1RightPzMuonPlus",";cos #theta^{*} from rightly p_{z} boosted W^{+} + #mu cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMuonMHT2Plus = new TH1D("MC_CosThetaStar1WrongPzMuonMHT2Plus",";cos #theta^{*} from wrongly p_{z} boosted W^{+} + (#mu,MHT) cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMuonMHT2Minus = new TH1D("MC_CosThetaStar1WrongPzMuonMHT2Minus",";cos #theta^{*} from wrongly p_{z} boosted W^{-} + (#mu,MHT) cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMuonMHT2Plus = new TH1D("MC_CosThetaStar1RightPzMuonMHT2Plus",";cos #theta^{*} from rightly p_{z} boosted W^{+} + (#mu,MHT) cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMuonMHT2Minus = new TH1D("MC_CosThetaStar1RightPzMuonMHT2Minus",";cos #theta^{*} from rightly p_{z} boosted W^{-} + (#mu,MHT) cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMuonMHT2RecoPlus = new TH1D("MC_CosThetaStar1WrongPzMuonMHT2RecoPlus",";cos #theta^{*} from wrongly p_{z} boosted W^{+} + (#mu,MHT) Reco cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1WrongPzMuonMHT2RecoMinus = new TH1D("MC_CosThetaStar1WrongPzMuonMHT2RecoMinus",";cos #theta^{*} from wrongly p_{z} boosted W^{-} + (#mu,MHT) Reco cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMuonMHT2RecoPlus = new TH1D("MC_CosThetaStar1RightPzMuonMHT2RecoPlus",";cos #theta^{*} from rightly p_{z} boosted W^{+} + (#mu,MHT) Reco cuts;Events / 100 pb^{-1}",300,-1.5,1.5);
    MC_CosThetaStar1RightPzMuonMHT2RecoMinus = new TH1D("MC_CosThetaStar1RightPzMuonMHT2RecoMinus",";cos #theta^{*} from rightly p_{z} boosted W^{-} + (#mu,MHT) Reco cuts;Events / 100 pb^{-1}",300,-1.5,1.5);

    MC_DiffPzWMuPlus = new TH1D("MC_DiffPzWMuPlus",";;#Delta(W^{+} p_{z}, #mu p_{z})Events / 100 pb^{-1}",2000,-1000.5,999.5);
    MC_DiffPzWMuMinus = new TH1D("MC_DiffPzWMuMinus",";#Delta(W^{-} p_{z}, #mu p_{z});Events / 100 pb^{-1}",2000,-1000.5,999.5);
    MC_MuonEtaCosThetaStar1Plus = new TH2D("MC_MuonEtaCosThetaStar1Plus",";cos #theta^{*} from W^{+};#mu^{+} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_MuonEtaCosThetaStar1Minus = new TH2D("MC_MuonEtaCosThetaStar1Minus",";cos #theta^{*} from W^{-};#mu^{-} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_MuonPtCosThetaStar1Plus = new TH2D("MC_MuonPtCosThetaStar1Plus",";cos #theta^{*} from W^{+};#mu^{+} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_MuonPtCosThetaStar1Minus = new TH2D("MC_MuonPtCosThetaStar1Minus",";cos #theta^{*} from W^{-};#mu^{-} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_WEtaCosThetaStar1Plus = new TH2D("MC_WEtaCosThetaStar1Plus",";cos #theta^{*} from W^{+};W^{+} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_WEtaCosThetaStar1Minus = new TH2D("MC_WEtaCosThetaStar1Minus",";cos #theta^{*} from W^{-};W^{-} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_WPtCosThetaStar1Plus = new TH2D("MC_WPtCosThetaStar1Plus",";cos #theta^{*} from W^{+};W^{+} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_WPtCosThetaStar1Minus = new TH2D("MC_WPtCosThetaStar1Minus",";cos #theta^{*} from W^{-};W^{-} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
 
    MC_ICVarCosThetaPlus2D = new TH2D("MC_WPtCosThetaStar1Minus",";cos #theta^{*} from W^{-};W^{-} P_{t}",300,-1.5,1.5,300,-1.5,1.5);
    MC_ICVarCosThetaMinus2D = new TH2D("MC_WPtCosThetaStar1Minus",";cos #theta^{*} from W^{-};W^{-} P_{t}",300,-1.5,1.5,300,-1.5,1.5);
    MC_ICVarCosThetaPlusZ = new TH1D("MC_ICVarCosThetaPlusZ","",300,-1.5,1.5);
    MC_ICVarCosThetaMinusZ = new TH1D("MC_ICVarCosThetaMinusZ","",300,-1.5,1.5);
    MC_ICVarCosThetaPlus = new TH1D("MC_ICVarCosThetaPlus","",300,-1.5,1.5);
    MC_ICVarCosThetaMinus = new TH1D("MC_ICVarCosThetaMinus","",300,-1.5,1.5);
    ICVarCosThetaPlusDiv= new TH2D("ICVarCosThetaPlusDiv","",300,-1.5,1.5,300,-1.5,1.5);
    ICVarCosThetaMinusDiv= new TH2D("ICVarCosThetaMinusDiv",";",300,-1.5,1.5,300,-1.5,1.5);

   TH1::SetDefaultSumw2(kFALSE);
  }

  bool MCWPlots::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    unsigned int counter = 0; //just a temporary variable so we can tell how many particles share the same mother as the W

    //the loop below goes through the particles in the GenMatrixBin identified as jets
    //these are the outgoing quarks and gluons - first we check that any of the outgoing quarks
    //shares the same mother as the W, then that it isn't a gluon. Finally we check that the
    //mother of the W has only 2 daughters
    TLorentzVector jJetSum, jJetSum2; //initialises as empty for each event
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      MC_JetPtAll->Fill(myGenMatrixBin.the_GenJets.at(i)->Pt(), ev.GetEventWeight()); //get the genJet Pt distribution for all jets
      MC_JetEtaAll->Fill(myGenMatrixBin.the_GenJets.at(i)->Eta(), ev.GetEventWeight()); //get the genJet Eta distribution for all jets
      jJetSum -= (*(myGenMatrixBin.the_GenJets.at(i))); //vectorially sum all final state quarks and gluons. take negative vector sum (=MHT =GenW)
      //now do it like we do in reco, with a pt and eta cut on the individual jets going into the sum - see NOTE below
      if(myGenMatrixBin.the_GenJets.at(i)->Pt() > 30.0 && fabs(myGenMatrixBin.the_GenJets.at(i)->Eta() < 3.0) ) jJetSum2 -= (*(myGenMatrixBin.the_GenJets.at(i)));
      if(myGenMatrixBin.the_GenJets.at(i)->GetMother() == myGenMatrixBin.the_GenW.at(0)->GetMother() && myGenMatrixBin.the_GenJets.at(i)->GetIndex() != 21) {
	jRestQuark = (*(myGenMatrixBin.the_GenJets.at(i)));
        counter++;
      }
    }

    MC_JetMultiplicityAll->Fill(myGenMatrixBin.the_GenJets.size(), ev.GetEventWeight());

    jGenW = *(myGenMatrixBin.the_GenW.at(0)); //the generator W
    jGenMu = *(myGenMatrixBin.the_GenMuon.at(0)); //the muon from the W

    //NOTE - The typical multiplicity for this selection of counter=1 is 1 jet. If the jet fails to pass the acceptance and pt cuts, then there will be, by definition no MHT
    //The result of this is a boost vector (0,0,-pz/m) which acts to take the muon away from the flight direction of the W, towards the cos theta = -1 bin
    //i.e. further away than it would normally have been if it had an x and y boost, since the angle we measure is a 3D one...
    //NOTE - To fill genJets in the GenMatrixBin there is already a cut on the jet energy > 30 GeV...
    //NOTE - At the RECO level, we make a MHT Cut > 100. so not sure the above is relevant...

    //only if the W shares a mother with ONE outgoing quark do we do the following
    //There are 3 possibilities for working out cos(theta*)
    //1.Boost the muon into the W rest frame and calculate the angle between the muon and original W flight direction - this is the only thing we can do in real data.
    //2.Boost the outgoing quark into the W rest frame and calculate the angle between the muon and quark
    //3.Boost the W into the W+outgoing quark system rest frame and calculate the angle between the muon in the W rest frame and W direction after first boost
    //(The W+outgoing quark = a virtual quark in the production diagram)
    //the check on counter ==1 is there so we can do boosts 2 and 3 - boost 1 is done outside the if statement below.
    if(counter == 1) {
      jRestQuark2 = jRestQuark; //duplicate the outgoing quark since we will boost it in two different ways
      jRestMu = jGenMu;
      jSol1Mu = jGenMu; //to boost the muon according to one of the two pz solutions
      jSol2Mu = jGenMu; //and the other
      jWrongMu = jGenMu; //and to see the effects of having 100% wrong choice on pz
      jRightMu = jGenMu; //and also if you pick 100% right choice, but the effect of choosing mw*=mw
      jBoost = jGenW.BoostVector();
      jBoost2 = (jRestQuark + jGenW).BoostVector();
      jRestMu.Boost(-jBoost);
      jRestQuark.Boost(-jBoost);
      jRestQuark2.Boost(-jBoost2);
      //CosThetaStar1 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jGenW));
      CosThetaStar2 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jRestQuark));
      CosThetaStar3 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jRestQuark2));
      delta_w_mu = jGenW.Pz() - jGenMu.Pz();
      delta_w_mu_mu = fabs(delta_w_mu - jGenMu.Pz());
      //W+ has particle ID = +24
      if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	//MC_CosThetaStar1Plus->Fill(CosThetaStar1, ev.GetEventWeight());
	MC_CosThetaStar2Plus->Fill(CosThetaStar2, ev.GetEventWeight());
	MC_CosThetaStar3Plus->Fill(CosThetaStar3, ev.GetEventWeight());
	MC_DiffPzWMuPlus->Fill(delta_w_mu, ev.GetEventWeight());
      } else {
	//MC_CosThetaStar1Minus->Fill(CosThetaStar1, ev.GetEventWeight());
	MC_CosThetaStar2Minus->Fill(CosThetaStar2, ev.GetEventWeight());
	MC_CosThetaStar3Minus->Fill(CosThetaStar3, ev.GetEventWeight());
	MC_DiffPzWMuMinus->Fill(delta_w_mu, ev.GetEventWeight());
      }
    }

    //the FindBoost method was developed after the above code was written (and since the above worked, don't touch hehe)
    jMCSolW = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
    if(jMCSolW.realSolutions) {
      if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	MC_CosThetaStar1Plus->Fill(jMCSolW.rightSol, ev.GetEventWeight());
	MC_MuonEtaCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenMu.Eta(), ev.GetEventWeight());
	MC_WEtaCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenW.Eta(), ev.GetEventWeight());
	MC_MuonPtCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenMu.Pt(), ev.GetEventWeight());
	MC_WPtCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenW.Pt(), ev.GetEventWeight());
      }else{
	MC_CosThetaStar1Minus->Fill(jMCSolW.rightSol, ev.GetEventWeight());
	MC_MuonEtaCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenMu.Eta(), ev.GetEventWeight());
	MC_WEtaCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenW.Eta(), ev.GetEventWeight());
	MC_MuonPtCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenMu.Pt(), ev.GetEventWeight());
	MC_WPtCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenW.Pt(), ev.GetEventWeight());
      }
    }

    //there might be a duplication with MC_JetPt and MC_JetPtAll above etc
    MC_MuonMultiplicity->Fill(myGenMatrixBin.the_GenMuon.size(), ev.GetEventWeight());
    MC_MuonNuMultiplicity->Fill(myGenMatrixBin.the_GenMuonNu.size(), ev.GetEventWeight());
    MC_JetMultiplicity->Fill(myGenMatrixBin.the_GenJets.size(), ev.GetEventWeight());
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      MC_JetPt->Fill(myGenMatrixBin.the_GenJets.at(i)->Pt(),ev.GetEventWeight());
      MC_JetEta->Fill(myGenMatrixBin.the_GenJets.at(i)->Eta(),ev.GetEventWeight());
    }

    //plot distribution of the muons
    MC_MuonPt->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
    MC_MuonEta->Fill(myGenMatrixBin.the_GenMuon.at(0)->Eta(), ev.GetEventWeight());
    MC_MuonEtaAbs->Fill(fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()), ev.GetEventWeight());
    MC_MuonNuPt->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
    MC_MuonNuEta->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Eta(), ev.GetEventWeight());
    MC_MuonNuEtaAbs->Fill(fabs(myGenMatrixBin.the_GenMuonNu.at(0)->Eta()), ev.GetEventWeight());
    //add a couple of plots for the separate charges Pt and Eta of the muons and neutrinos
    //and the IC variable (projection of lepton pt to mht normalised to mht). These plots are in the format for the macro
    double ICVariable = ((myGenMatrixBin.the_GenMuon.at(0)->Px() * jJetSum.Px()) + (myGenMatrixBin.the_GenMuon.at(0)->Py() * jJetSum.Py())) / (jJetSum.Pt() * jJetSum.Pt());
  double ICVariableZ = (myGenMatrixBin.the_GenMuon.at(0)->Pz() * jJetSum.Pz()) / jJetSum.Pz();
    if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
      MC_MuonPtPlus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
      MC_MuonNuPtPlus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
      MC_MuonEtaPlus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Eta(), ev.GetEventWeight());
      MC_MuonEtaAbsPlus->Fill(fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()), ev.GetEventWeight());
      MC_MuonNuEtaPlus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Eta(), ev.GetEventWeight());
      MC_MuonNuEtaAbsPlus->Fill(fabs(myGenMatrixBin.the_GenMuonNu.at(0)->Eta()), ev.GetEventWeight());
      MC_ICVarPlus->Fill(2*(ICVariable-.5), ev.GetEventWeight());
      MC_ICVarCosThetaPlus2D->Fill(2*(ICVariable-.5), 2*(ICVariableZ-.5), ev.GetEventWeight());
      MC_ICVarCosThetaPlusZ->Fill(2*(ICVariableZ-.5), ev.GetEventWeight());
      MC_ICVarCosThetaPlus->Fill(2*(ICVariable-.5), ev.GetEventWeight());
      if(jMCSolW.realSolutions)      ICVarCosThetaPlusDiv->Fill(2*(ICVariableZ-.5), jMCSolW.rightSol, ev.GetEventWeight());
    }else{
      MC_MuonPtMinus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
      MC_MuonNuPtMinus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
      MC_MuonEtaMinus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Eta(), ev.GetEventWeight());
      MC_MuonEtaAbsMinus->Fill(fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()), ev.GetEventWeight());
      MC_MuonNuEtaMinus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Eta(), ev.GetEventWeight());
      MC_MuonNuEtaAbsMinus->Fill(fabs(myGenMatrixBin.the_GenMuonNu.at(0)->Eta()), ev.GetEventWeight());
      MC_ICVarMinus->Fill(ICVariable, ev.GetEventWeight());
    }

    MC_JetMHT->Fill(jJetSum.Pt(), ev.GetEventWeight());
    MC_JetMHT2->Fill(jJetSum2.Pt(), ev.GetEventWeight());

    MC_VirtualWMass->Fill(jGenW.M(), ev.GetEventWeight());
    MC_MHTGenJetsWPtDiff->Fill((jJetSum.Pt() - jGenW.Pt())/jGenW.Pt(), ev.GetEventWeight());
    MC_MHT2GenJetsWPtDiff->Fill((jJetSum2.Pt() - jGenW.Pt())/jGenW.Pt(), ev.GetEventWeight());

    //to see the effects of the W left handedness, plot the muon and neutrino spectra for two different muon pt cuts
    //point is that mu- is opposite to W-, so a cut on low pt mu- effects high pt neutrino, hence MET, spectra...
    //to pass the MCWMuon Cut, there must be a muon neutrino in this event...
    if(fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()) < 2.1) {
      if(myGenMatrixBin.the_GenMuon.at(0)->Pt() > 10.0) {
	  MC_MuonPtCut1->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
	  MC_MuonEtaCut1->Fill(fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()), ev.GetEventWeight());
	  MC_MuonNuPtCut1->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
	  MC_MuonNuEtaCut1->Fill(fabs(myGenMatrixBin.the_GenMuonNu.at(0)->Eta()), ev.GetEventWeight());
	  if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	    MC_MuonNuPtCut1Plus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut1Plus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
	  }else{
	    MC_MuonNuPtCut1Minus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut1Minus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());	  
	  }
      }
      if(myGenMatrixBin.the_GenMuon.at(0)->Pt() > 20.0) {
	  MC_MuonPtCut2->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
	  MC_MuonEtaCut2->Fill(fabs(myGenMatrixBin.the_GenMuon.at(0)->Eta()), ev.GetEventWeight());
	  MC_MuonNuPtCut2->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
	  MC_MuonNuEtaCut2->Fill(fabs(myGenMatrixBin.the_GenMuonNu.at(0)->Eta()), ev.GetEventWeight());
	  if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	    MC_MuonNuPtCut2Plus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut2Plus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
	  }else{
	    MC_MuonNuPtCut2Minus->Fill(myGenMatrixBin.the_GenMuonNu.at(0)->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut2Minus->Fill(myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());	  
	  }
      }
    }

    //The above plots are a cheaty way to see how the different polarisation components change with respect to W eta and pt
    //They won't reveal anything useful if the underlying distribution is symmetric as it will change both by the same amount
    //The plots that follow show CosThetaStar1 Plus and Minus in bins of W eta, from 0.0 - 5.0 and above!
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 0.0 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 0.5 ) {
      jMCSolWEtaBin1 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin1.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin1Plus->Fill(jMCSolWEtaBin1.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin1Minus->Fill(jMCSolWEtaBin1.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 0.5 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 1.0 ) {
      jMCSolWEtaBin2 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin2.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin2Plus->Fill(jMCSolWEtaBin2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin2Minus->Fill(jMCSolWEtaBin2.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 1.0 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 1.5 ) {
      jMCSolWEtaBin3 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin3.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin3Plus->Fill(jMCSolWEtaBin3.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin3Minus->Fill(jMCSolWEtaBin3.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 1.5 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 2.0 ) {
      jMCSolWEtaBin4 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin4.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin4Plus->Fill(jMCSolWEtaBin4.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin4Minus->Fill(jMCSolWEtaBin4.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 2.0 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 2.5 ) {
      jMCSolWEtaBin5 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin5.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin5Plus->Fill(jMCSolWEtaBin5.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin5Minus->Fill(jMCSolWEtaBin5.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 2.5 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 3.0 ) {
      jMCSolWEtaBin6 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin6.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin6Plus->Fill(jMCSolWEtaBin6.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin6Minus->Fill(jMCSolWEtaBin6.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 3.0 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 3.5 ) {
      jMCSolWEtaBin7 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin7.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin7Plus->Fill(jMCSolWEtaBin7.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin7Minus->Fill(jMCSolWEtaBin7.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 3.5 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 4.0 ) {
      jMCSolWEtaBin8 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin8.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin8Plus->Fill(jMCSolWEtaBin8.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin8Minus->Fill(jMCSolWEtaBin8.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 4.0 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 4.5 ) {
      jMCSolWEtaBin9 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin9.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin9Plus->Fill(jMCSolWEtaBin9.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin9Minus->Fill(jMCSolWEtaBin9.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 4.5 && fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) <= 5.0 ) {
      jMCSolWEtaBin10 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin10.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin10Plus->Fill(jMCSolWEtaBin10.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin10Minus->Fill(jMCSolWEtaBin10.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(myGenMatrixBin.the_GenW.at(0)->Eta()) > 5.0 ) {
      jMCSolWEtaBin11 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin11.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin11Plus->Fill(jMCSolWEtaBin11.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin11Minus->Fill(jMCSolWEtaBin11.rightSol, ev.GetEventWeight());
	}
      }
    }

    //now we do the same thing for bins of W_Pt
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 100 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 200) {
      jMCSolWPtBin1 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin1.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin1Plus->Fill(jMCSolWPtBin1.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin1Minus->Fill(jMCSolWPtBin1.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 200 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 300) {
      jMCSolWPtBin2 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin2.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin2Plus->Fill(jMCSolWPtBin2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin2Minus->Fill(jMCSolWPtBin2.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 300 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 400) {
      jMCSolWPtBin3 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin3.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin3Plus->Fill(jMCSolWPtBin3.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin3Minus->Fill(jMCSolWPtBin3.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 400 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 500) {
      jMCSolWPtBin4 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin4.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin4Plus->Fill(jMCSolWPtBin4.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin4Minus->Fill(jMCSolWPtBin4.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 500 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 600) {
      jMCSolWPtBin5 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin5.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin5Plus->Fill(jMCSolWPtBin5.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin5Minus->Fill(jMCSolWPtBin5.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 600 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 700) {
      jMCSolWPtBin6 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin6.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin6Plus->Fill(jMCSolWPtBin6.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin6Minus->Fill(jMCSolWPtBin6.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 700 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 800) {
      jMCSolWPtBin7 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin7.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin7Plus->Fill(jMCSolWPtBin7.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin7Minus->Fill(jMCSolWPtBin7.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenW.at(0)->Pt() > 800 && myGenMatrixBin.the_GenW.at(0)->Pt() <= 900) {
      jMCSolWPtBin8 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin8.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin8Plus->Fill(jMCSolWPtBin8.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin8Minus->Fill(jMCSolWPtBin8.rightSol, ev.GetEventWeight());
	}
      }
    }

    //and finally in bins of jet multiplicity
    if(myGenMatrixBin.the_GenJets.size() == 0) {
      jMCSolWJetBin1 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin1.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin1Plus->Fill(jMCSolWJetBin1.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin1Minus->Fill(jMCSolWJetBin1.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 1) {
      jMCSolWJetBin2 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin2.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin2Plus->Fill(jMCSolWJetBin2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin2Minus->Fill(jMCSolWJetBin2.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 2) {
      jMCSolWJetBin3 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin3.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin3Plus->Fill(jMCSolWJetBin3.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin3Minus->Fill(jMCSolWJetBin3.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 3) {
      jMCSolWJetBin4 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin4.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin4Plus->Fill(jMCSolWJetBin4.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin4Minus->Fill(jMCSolWJetBin4.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 4) {
      jMCSolWJetBin5 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin5.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin5Plus->Fill(jMCSolWJetBin5.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin5Minus->Fill(jMCSolWJetBin5.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 5) {
      jMCSolWJetBin6 = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin6.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin6Plus->Fill(jMCSolWJetBin6.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin6Minus->Fill(jMCSolWJetBin6.rightSol, ev.GetEventWeight());
	}
      }
    }


    //now play with different variables affecting measurement of cos(theta*) variable at gen level
    jMCSol = FindBoost(jGenMu, jGenW.Px(), jGenW.Py(), jGenW.Pz());

    if(jMCSol.realSolutions) {
      //plot the VirtualW mass for real solutions to pz
      MC_VirtualWMassRe->Fill(jGenW.M(), ev.GetEventWeight());
	
      //remember that whilst the muon has a positive ID but negative charge, the W+ has ID +24
      if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	MC_CosThetaStar1WrongPzPlus->Fill(jMCSol.wrongSol, ev.GetEventWeight());
	MC_CosThetaStar1RightPzPlus->Fill(jMCSol.rightSol, ev.GetEventWeight());
      }else{
	MC_CosThetaStar1WrongPzMinus->Fill(jMCSol.wrongSol, ev.GetEventWeight());
	MC_CosThetaStar1RightPzMinus->Fill(jMCSol.rightSol, ev.GetEventWeight());
      }	
    }else{
      MC_VirtualWMassIm->Fill(jGenW.M(), ev.GetEventWeight());
    }

    if(jJetSum2.Pt() > 100.0) {
      //MHT2 relates to making jet et and eta cuts contributing to the MHT calculation
      jMCSolMHT2 = FindBoost(jGenMu, jJetSum2.Px(), jJetSum2.Py(), jGenW.Pz());

      if(jMCSolMHT2.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMHT2Plus->Fill(jMCSolMHT2.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMHT2Plus->Fill(jMCSolMHT2.rightSol, ev.GetEventWeight());	  
	}else{
	  MC_CosThetaStar1WrongPzMHT2Minus->Fill(jMCSolMHT2.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMHT2Minus->Fill(jMCSolMHT2.rightSol, ev.GetEventWeight());
	}
      }
    }

    //again, we emulate the RECO cuts, this time on the muon, to see the effects at gen level on the cos(theta*) dist
    if(jGenMu.Pt() > 15.0 && fabs(jGenMu.Eta()) < 2.1) {
      jMCSolMuon = FindBoost(jGenMu,jGenW.Px(),jGenW.Py(),jGenW.Pz());

      if(jMCSolMuon.realSolutions) {
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMuonPlus->Fill(jMCSolMuon.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonPlus->Fill(jMCSolMuon.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1WrongPzMuonMinus->Fill(jMCSolMuon.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMinus->Fill(jMCSolMuon.rightSol, ev.GetEventWeight());
	}
      }
    }

    //now mix all the criteria together at generator level
    if(jGenMu.Pt() > 15.0 && fabs(jGenMu.Eta()) < 2.1 && jJetSum2.Pt() > 100.0) {
      jMCSolMuonMHT2 = FindBoost(jGenMu, jJetSum2.Px(), jJetSum2.Py(), jGenW.Pz());
     
      if(jMCSolMuonMHT2.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMuonMHT2Plus->Fill(jMCSolMuonMHT2.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMHT2Plus->Fill(jMCSolMuonMHT2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1WrongPzMuonMHT2Minus->Fill(jMCSolMuonMHT2.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMHT2Minus->Fill(jMCSolMuonMHT2.rightSol, ev.GetEventWeight());
	}
      }
    }

    //now try doing the same with the RECO quantities (where we can cheat with the real Pz)
    //remember that when the commonmuons are filled, they have to pass the pt>commonmuonetcut_gev and fabs(eta)<commonmuoneta cuts...
    //we don't make the numcomleptons cut though...
    if(ev.LD_CommonMuons().accepted.size() == 1 && ev.CommonMHT().Pt() > 100.0) {
      jMCSolMuonMHT2Reco = FindBoost(*(ev.LD_CommonMuons().accepted.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), jGenW.Pz());

      if(jMCSolMuonMHT2Reco.realSolutions){
	if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMuonMHT2RecoPlus->Fill(jMCSolMuonMHT2Reco.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMHT2RecoPlus->Fill(jMCSolMuonMHT2Reco.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1WrongPzMuonMHT2RecoMinus->Fill(jMCSolMuonMHT2Reco.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMHT2RecoMinus->Fill(jMCSolMuonMHT2Reco.rightSol, ev.GetEventWeight());
	}
      }
    }

    MC_WMultiplicity->Fill(myGenMatrixBin.the_GenW.size(), ev.GetEventWeight());
    MC_WPT->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
    if(myGenMatrixBin.the_GenW.at(0)->GetID() > 0) {
      MC_WPtPlus->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
      MC_WEtaPlus->Fill(fabs(myGenMatrixBin.the_GenW.at(0)->Eta()), ev.GetEventWeight());
    }else{
      MC_WPtMinus->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
      MC_WEtaMinus->Fill(fabs(myGenMatrixBin.the_GenW.at(0)->Eta()), ev.GetEventWeight());
    }
    MC_MHTAllGenJetsWPtDiff->Fill((jJetSum.Pt() - myGenMatrixBin.the_GenW.at(0)->Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
    return true;
  }

  std::ostream& MCWPlots::Description(std::ostream &ostrm) {
    ostrm << "Generator W boson plots";
    return ostrm;
  }


  //====================================
  // MCPolPlots implementation 
  //====================================
  
  MCPolPlots::MCPolPlots(const std::string & folderName) :
    mFolderName(folderName) {}
   
  MCPolPlots::~MCPolPlots() {}

  void MCPolPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MCPolPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    MC_MuonPt = new TH1D("MC_MuonPt", ";#mu P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_MuonEta =  new TH1D("MC_MuonEta",";#mu #eta;Events / 100 pb^{-1}",100, -5.5, 4.5);
    MC_MuonMultiplicity = new TH1D("MC_MuonMultiplicity", ";MC MuonExtra Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_MHT = new TH1D("MC_MHT", ";MHT;Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_CosThetaStar1Sol1Plus = new TH1D("MC_CosThetaStar1Sol1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Sol1Minus = new TH1D("MC_CosThetaStar1Sol1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Sol2Plus = new TH1D("MC_CosThetaStar1Sol2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Sol2Minus = new TH1D("MC_CosThetaStar1Sol2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool MCPolPlots::Process(Event::Data & ev) {
    //the purpose of this class is to be able to look at cos theta* between a muon and virtual W, using the jet recoil (MHT)
    //as the substitute for W so we can look at a quantity we could measure from real data - and see what we'd expect from SUSY at MC level
    //that WAS the purpose of this class, now i'm using it as the closest estimate to the RECO plots using MC quantities. I only intend to run
    //over the ttbar and W samples so we can try to use this as a background estimation.

    GenMatrixBin myGenMatrixBin(&ev);
    TLorentzVector jJetSum; 
    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      //make the negative vector sum of all jets i.e. the MHT = W Pt
      jJetSum -= (*(myGenMatrixBin.the_GenJets.at(i)));
      //now do it like we do in reco, with a pt and eta cut on the individual jets going into the sum
      //if(myGenMatrixBin.the_GenJets.at(i)->Pt() > 30.0 && fabs(myGenMatrixBin.the_GenJets.at(i)->Eta() < 3.0) ) jJetSum2 -= (*(myGenMatrixBin.the_GenJets.at(i)));
    }

    MC_MHT->Fill(jJetSum.Pt(), ev.GetEventWeight());
    MC_MuonMultiplicity->Fill(myGenMatrixBin.the_GenMuonExtra.size(), ev.GetEventWeight());
    MC_MuonEta->Fill(myGenMatrixBin.the_GenMuonExtra.at(0)->Eta(), ev.GetEventWeight());
    MC_MuonPt->Fill(myGenMatrixBin.the_GenMuonExtra.at(0)->Pt(), ev.GetEventWeight());
 
    jMCSol = FindBoost(*(myGenMatrixBin.the_GenMuonExtra.at(0)), jJetSum.Px(), jJetSum.Py(), 0.0, false);

    if(jMCSol.realSolutions) {
      if(myGenMatrixBin.the_GenMuonExtra.at(0)->GetID() < 0) {
	MC_CosThetaStar1Sol1Plus->Fill(jMCSol.sol1, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Plus->Fill(jMCSol.sol2, ev.GetEventWeight());
      }else{
	MC_CosThetaStar1Sol1Minus->Fill(jMCSol.sol1, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Minus->Fill(jMCSol.sol2, ev.GetEventWeight());
      }
    } else {
      //plot an "underflow" bin on these plots which will give an indication of the number of virtual solutions for each sample
      if(myGenMatrixBin.the_GenMuonExtra.at(0)->GetID() < 0) {
	MC_CosThetaStar1Sol1Plus->Fill(-1.2, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Plus->Fill(-1.2, ev.GetEventWeight());
      }else{
	MC_CosThetaStar1Sol1Minus->Fill(-1.2, ev.GetEventWeight());
	MC_CosThetaStar1Sol2Minus->Fill(-1.2, ev.GetEventWeight());
      }
    }

    return true;
  }

  std::ostream& MCPolPlots::Description(std::ostream &ostrm) {
    ostrm << "Generator Polarisation plots";
    return ostrm;
  }

  //====================================
  // RECOPolPlots implementation 
  //====================================
  
  RECOPolPlots::RECOPolPlots(const std::string & folderName) :
    mFolderName(folderName) {}
   
  RECOPolPlots::~RECOPolPlots() {}

  void RECOPolPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void RECOPolPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    RECO_MuonPtPlus = new TH1D("RECO_MuonPtPlus", ";#mu^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPtMinus = new TH1D("RECO_MuonPtMinus", ";#mu^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonEtaPlus =  new TH1D("RECO_MuonEtaPlus",";#mu^{+} #eta;Events / 100 pb^{-1}",100, -5.5, 4.5);
    RECO_MuonEtaMinus =  new TH1D("RECO_MuonEtaMinus",";#mu^{-} #eta;Events / 100 pb^{-1}",100, -5.5, 4.5);
    RECO_MuonEtaPlusAbs =  new TH1D("RECO_MuonEtaPlusAbs",";#mu^{+} |#eta|;Events / 100 pb^{-1}",100, -0.025, 4.975);
    RECO_MuonEtaMinusAbs =  new TH1D("RECO_MuonEtaMinusAbs",";#mu^{-} |#eta|;Events / 100 pb^{-1}",100, -0.025, 4.975);
    RECO_CommonMHTPlus = new TH1D("RECO_CommonMHTPlus",";Common MHT with mu^{+};Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_CommonMHTMinus = new TH1D("RECO_CommonMHTMinus",";Common MHT with mu^{-};Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_ICVarPlus = new TH1D("RECO_ICVarPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarMinus = new TH1D("RECO_ICVarMinus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_TransMass = new TH1D("RECO_TransMass",";Transverse Mass [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);

    MC_MuonMultiplicity = new TH1D("MC_MuonMultiplicity", ";genW Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    RECO_JetMultiplicity = new TH1D("RECO_JetMultiplicity",";Common Jet Multiplicity;Events / 100 pb^{-1}",20,-0.5,19.5);
    RECO_MuonMultiplicity = new TH1D("RECO_MuonMultiplicity", ";RECO Muon Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    
    RECO_CosThetaStar1Sol1Plus = new TH1D("RECO_CosThetaStar1Sol1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Minus = new TH1D("RECO_CosThetaStar1Sol1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol2Plus = new TH1D("RECO_CosThetaStar1Sol2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol2Minus = new TH1D("RECO_CosThetaStar1Sol2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

    MC_RECO_MuonMultMatch = new TH1D("MC_RECO_MuonMultMatch",";#mu (MC, RECO) multiplicity match false/true;Events / 100 pb^{-1}",2,-0.5,1.5);
    MC_RECO_MHTDiff = new TH1D("MC_RECO_MHTDiff",";#Delta (MC, RECO)/MC MHT;Events / 100 pb^{-1}", 2000, -1000.5, 999.5);
    MC_RECO_MuonPtDiff = new TH1D("MC_RECO_MuonPtDiff",";#Delta (MC, RECO)/MC #muon P_{T};Events / 100 pb^{-1}", 2000, -1000.5, 999.5);
    MC_RECO_MuonEtaDiff = new TH1D("MC_RECO_MuonEtaDiff",";#Delta (MC, RECO) #muon #eta;Events / 100 pb^{-1}", 200, -10.5, 9.5);
    MC_RECO_MuonChargeId = new TH1D("MC_RECO_MuonChargeId",";#mu charge id wrong/right;Events / 100 pb^{-1}",2,-0.5,1.5);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool RECOPolPlots::Process(Event::Data & ev) {
    //These plotting routines should be accessed after the following cutflow:
    //1. numcomleptons == 1
    //2. numcommuons == 1
    //3. numphotons == 0
    //4. numgoodjets > 1
    //5. oddobject cuts
    //6. badmuoninjet
    //7. photkilledjet
    //8. deltaR(muon, closestjet) > 0.5
    //9. commonMHT cut > 200.

    GenMatrixBin myGenMatrixBin(&ev);

    //make the IC Variable at RECO level:
    double ICVariable = ((ev.LD_CommonMuons().accepted.at(0)->Px() * ev.CommonMHT().Px()) + (ev.LD_CommonMuons().accepted.at(0)->Py() * ev.CommonMHT().Py())) / (ev.CommonMHT().Pt() * ev.CommonMHT().Pt());

    //to use MT, don't call CommonMT() - which is whack. Do the following:
    double eMT=ev.MT(ev.LD_CommonMuons().accepted.at(0),&(ev.CommonRecoilMET()));
    RECO_TransMass->Fill(eMT, ev.GetEventWeight());

    //fill the Muon and MHT distributions according to charge
    if(ev.LD_CommonMuons().accepted.at(0)->GetCharge()>0.0) {
      RECO_MuonPtPlus->Fill(ev.LD_CommonMuons().accepted.at(0)->Pt(), ev.GetEventWeight());
      RECO_MuonEtaPlus->Fill(ev.LD_CommonMuons().accepted.at(0)->Eta(), ev.GetEventWeight());
      RECO_MuonEtaPlusAbs->Fill(fabs(ev.LD_CommonMuons().accepted.at(0)->Eta()), ev.GetEventWeight());
      RECO_ICVarPlus->Fill(ICVariable, ev.GetEventWeight());
      RECO_CommonMHTPlus->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
    }else{
      RECO_MuonPtMinus->Fill(ev.LD_CommonMuons().accepted.at(0)->Pt(), ev.GetEventWeight());
      RECO_MuonEtaMinus->Fill(ev.LD_CommonMuons().accepted.at(0)->Eta(), ev.GetEventWeight());
      RECO_MuonEtaMinusAbs->Fill(fabs(ev.LD_CommonMuons().accepted.at(0)->Eta()), ev.GetEventWeight());
      RECO_ICVarMinus->Fill(ICVariable, ev.GetEventWeight());
      RECO_CommonMHTMinus->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
    }

    MC_MuonMultiplicity->Fill(myGenMatrixBin.the_GenMuon.size(), ev.GetEventWeight());
    RECO_JetMultiplicity->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());
    RECO_MuonMultiplicity->Fill(ev.LD_CommonMuons().accepted.size(), ev.GetEventWeight());

    //check how many times real MC muon exists for RECO muon and when this happens, check the charge identification and the pt and eta widths
    if(myGenMatrixBin.the_GenMuon.size() == ev.LD_CommonMuons().accepted.size()) {
      MC_RECO_MuonMultMatch->Fill(1.0, ev.GetEventWeight());
      if(myGenMatrixBin.the_GenW.size() > 0) MC_RECO_MHTDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - ev.CommonMHT().Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
      MC_RECO_MuonPtDiff->Fill((myGenMatrixBin.the_GenMuon.at(0)->Pt() - ev.LD_CommonMuons().accepted.at(0)->Pt())/myGenMatrixBin.the_GenMuon.at(0)->Pt(), ev.GetEventWeight());
      MC_RECO_MuonEtaDiff->Fill((myGenMatrixBin.the_GenMuon.at(0)->Eta() - ev.LD_CommonMuons().accepted.at(0)->Eta()), ev.GetEventWeight());
      
      //remember that a negatively charge muon has a positive ID and vice versa
      if((myGenMatrixBin.the_GenMuon.at(0)->GetID() > 0 && ev.LD_CommonMuons().accepted.at(0)->GetCharge() < 0) || (myGenMatrixBin.the_GenMuon.at(0)->GetID() < 0 && ev.LD_CommonMuons().accepted.at(0)->GetCharge() > 0)) MC_RECO_MuonChargeId->Fill(1.0, ev.GetEventWeight());
      else MC_RECO_MuonChargeId->Fill(0.0, ev.GetEventWeight());
    
    } else {
      MC_RECO_MuonMultMatch->Fill(0.0, ev.GetEventWeight());
    }

    //now fill the cos theta star distributions - first check for real solutions
    jRECOSol = FindBoost(*(ev.LD_CommonMuons().accepted.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), 0.0, false);

    if(jRECOSol.realSolutions) {
      if(ev.LD_CommonMuons().accepted.at(0)->GetCharge()>0.0) {
	RECO_CosThetaStar1Sol1Plus->Fill(jRECOSol.sol1, ev.GetEventWeight());
	RECO_CosThetaStar1Sol2Plus->Fill(jRECOSol.sol2, ev.GetEventWeight());
      }else{
	RECO_CosThetaStar1Sol1Minus->Fill(jRECOSol.sol1, ev.GetEventWeight());
	RECO_CosThetaStar1Sol2Minus->Fill(jRECOSol.sol2, ev.GetEventWeight());
      }
    } else {
      //plot an "underflow" bin on these plots which will give an indication of the number of virtual solutions for each sample
      if(ev.LD_CommonMuons().accepted.at(0)->GetCharge()>0.0) {
	RECO_CosThetaStar1Sol1Plus->Fill(-1.2, ev.GetEventWeight());
	RECO_CosThetaStar1Sol2Plus->Fill(-1.2, ev.GetEventWeight());
      }else{
	RECO_CosThetaStar1Sol1Minus->Fill(-1.2, ev.GetEventWeight());
	RECO_CosThetaStar1Sol2Minus->Fill(-1.2, ev.GetEventWeight());
      }
    }

    return true;
  }

  std::ostream& RECOPolPlots::Description(std::ostream &ostrm) {
    ostrm << "Reco Level Polarisation plots";
    return ostrm;
  }

} //~namespace Operation
