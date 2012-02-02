#include "MCWPlots.hh"
//originally written by Jad Marrouche, September 2009 onwards
namespace Operation {

  MCWPlots::MCWPlots(const std::string & folderName, const std::string & VBoson, const unsigned int & phase_space) :
    mFolderName(folderName),
    mVBoson(VBoson),
    mPhaseSpace(phase_space) {}

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
    MC_WEta = new TH1D("MC_WEta", ";genW #eta;Events / 100 pb^{-1}",100,-5.05,4.95);
    MC_WY = new TH1D("MC_WY", ";genW Y;Events / 100 pb^{-1}",5000,-25.05,24.95);
    MC_WYMuAcc = new TH1D("MC_WYMuAcc", ";W Y given |#eta(#mu)|<2.1; Events / 100 pb^{-1}", 5000, -25.05, 24.95);
    MC_WPtPlus = new TH1D("MC_WPtPlus", ";genW^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WPtMinus = new TH1D("MC_WPtMinus", ";genW^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WPTLepAcc2Plus = new TH1D("MC_WPTLepAcc2Plus", ";genW^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WPTLepAcc2Minus = new TH1D("MC_WPTLepAcc2Minus", ";genW^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    MC_WEtaPlus = new TH1D("MC_WEtaPlus",";genW^{+} #eta;Events / 100 pb^{-1}", 250,-0.5,24.5);
    MC_WYPlus= new TH1D("MC_WYPlus",";genW^{+} |Y|;Events / 100 pb^{-1}", 50,-0.05,4.95);
    MC_WEtaMinus = new TH1D("MC_WEtaMinus",";genW^{-} #eta;Events / 100 pb^{-1}", 250,-0.5,24.5);
    MC_WYMinus= new TH1D("MC_WYMinus",";genW^{-} |Y|;Events / 100 pb^{-1}", 50,-0.05,4.95);
    MC_MHTGenJetsWPtDiff = new TH1D("MC_MHTGenJetsWPtDiff",";#Delta (MH_{T}, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MHTAllGenJetsWPtDiff = new TH1D("MC_MHTAllGenJetsWPtDiff",";#Delta (MH_{T}, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MHT2GenJetsWPtDiff = new TH1D("MC_MHT2GenJetsWPtDiff",";#Delta (MH_{T}2, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
    MCRECO_PFMHTWPtDiff = new TH1D("MCRECO_PFMHTWPtDiff",";#Delta (PFMHT, W P_{T}) / genW P_{T};Events / 100 pb^{-1}",100,-5.5,4.5);
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

    MC_MuonPtPlus = new TH1D("MC_MuonPtPlus",";#mu^{+} P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtPlus = new TH1D("MC_MuonNuPtPlus",";#mu^{+} #nu P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonEtaPlus = new TH1D("MC_MuonEtaPlus",";#mu^{+} #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaPlus_LH = new TH1D("MC_MuonEtaPlus_LH",";#mu^{+} #eta LH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaPlus_RH = new TH1D("MC_MuonEtaPlus_RH",";#mu^{+} #eta RH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaPlus_LO = new TH1D("MC_MuonEtaPlus_LO",";#mu^{+} #eta LO;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccPlus = new TH1D("MC_MuonEtaMuonAccPlus",";Acc #mu^{+} #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccPlus_LH = new TH1D("MC_MuonEtaMuonAccPlus_LH",";Acc #mu^{+} #eta LH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccPlus_RH = new TH1D("MC_MuonEtaMuonAccPlus_RH",";Acc #mu^{+} #eta RH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccPlus_LO = new TH1D("MC_MuonEtaMuonAccPlus_LO",";Acc #mu^{+} #eta LO;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaAbsPlus = new TH1D("MC_MuonEtaAbsPlus",";#mu^+ |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_MuonNuEtaPlus = new TH1D("MC_MuonNuEtaPlus",";#mu^+ #nu #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuEtaAbsPlus = new TH1D("MC_MuonNuEtaAbsPlus",";#mu^+ #nu |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_ICVarPlus = new TH1D("MC_ICVarPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A0p10pc = new TH1D("MC_ICVarPlus_A0p10pc",";IC Variable #mu^{+} A_{0}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A1p10pc = new TH1D("MC_ICVarPlus_A1p10pc",";IC Variable #mu^{+} A_{1}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A2p10pc = new TH1D("MC_ICVarPlus_A2p10pc",";IC Variable #mu^{+} A_{2}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A3p10pc = new TH1D("MC_ICVarPlus_A3p10pc",";IC Variable #mu^{+} A_{3}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A4p10pc = new TH1D("MC_ICVarPlus_A4p10pc",";IC Variable #mu^{+} A_{4}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A0p0d01 = new TH1D("MC_ICVarPlus_A0p0d01",";IC Variable #mu^+ A_{0}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A1p0d01 = new TH1D("MC_ICVarPlus_A1p0d01",";IC Variable #mu^+ A_{1}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A2p0d01 = new TH1D("MC_ICVarPlus_A2p0d01",";IC Variable #mu^+ A_{2}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A3p0d01 = new TH1D("MC_ICVarPlus_A3p0d01",";IC Variable #mu^+ A_{3}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_A4p0d01 = new TH1D("MC_ICVarPlus_A4p0d01",";IC Variable #mu^+ A_{4}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_LH = new TH1D("MC_ICVarPlus_LH",";IC Variable #mu^{+} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_RH = new TH1D("MC_ICVarPlus_RH",";IC Variable #mu^{+} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlus_LO = new TH1D("MC_ICVarPlus_LO",";IC Variable #mu^{+} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlusMuonAcc = new TH1D("MC_ICVarPlusMuonAcc",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlusMuonAcc_LH = new TH1D("MC_ICVarPlusMuonAcc_LH",";IC Variable #mu^{+} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlusMuonAcc_RH = new TH1D("MC_ICVarPlusMuonAcc_RH",";IC Variable #mu^{+} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarPlusMuonAcc_LO = new TH1D("MC_ICVarPlusMuonAcc_LO",";IC Variable #mu^{+} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_MuonPtMinus = new TH1D("MC_MuonPtMinus",";#mu^{-} P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonNuPtMinus = new TH1D("MC_MuonNuPtMinus",";#mu^{-} #nu P_{T};Events / 100 pb^{-1}",1000,-0.5,999.5);
    MC_MuonEtaMinus = new TH1D("MC_MuonEtaMinus",";#mu^{-} #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMinus_LH = new TH1D("MC_MuonEtaMinus_LH",";#mu^{-} #eta LH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMinus_RH = new TH1D("MC_MuonEtaMinus_RH",";#mu^{-} #eta RH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMinus_LO = new TH1D("MC_MuonEtaMinus_LO",";#mu^{-} #eta LO;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccMinus = new TH1D("MC_MuonEtaMuonAccMinus",";Acc #mu^{-} #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccMinus_LH = new TH1D("MC_MuonEtaMuonAccMinus_LH",";Acc #mu^{-} #eta LH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccMinus_RH = new TH1D("MC_MuonEtaMuonAccMinus_RH",";Acc #mu^{-} #eta RH;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaMuonAccMinus_LO = new TH1D("MC_MuonEtaMuonAccMinus_LO",";Acc #mu^{-} #eta LO;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonEtaAbsMinus = new TH1D("MC_MuonEtaAbsMinus",";#mu^- |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_MuonNuEtaMinus = new TH1D("MC_MuonNuEtaMinus",";#mu^- #nu #eta;Events / 100 pb^{-1}",100,-5.5,4.5);
    MC_MuonNuEtaAbsMinus = new TH1D("MC_MuonNuEtaAbsMinus",";#mu^- #nu |#eta|;Events / 100 pb^{-1}",50,-0.5,4.5);
    MC_ICVarMinus = new TH1D("MC_ICVarMinus",";IC Variable #mu^-;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A0p10pc = new TH1D("MC_ICVarMinus_A0p10pc",";IC Variable #mu^- A_{0}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A1p10pc = new TH1D("MC_ICVarMinus_A1p10pc",";IC Variable #mu^- A_{1}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A2p10pc = new TH1D("MC_ICVarMinus_A2p10pc",";IC Variable #mu^- A_{2}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A3p10pc = new TH1D("MC_ICVarMinus_A3p10pc",";IC Variable #mu^- A_{3}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A4p10pc = new TH1D("MC_ICVarMinus_A4p10pc",";IC Variable #mu^- A_{4}+10percent;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A0p0d01 = new TH1D("MC_ICVarMinus_A0p0d01",";IC Variable #mu^- A_{0}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A1p0d01 = new TH1D("MC_ICVarMinus_A1p0d01",";IC Variable #mu^- A_{1}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A2p0d01 = new TH1D("MC_ICVarMinus_A2p0d01",";IC Variable #mu^- A_{2}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A3p0d01 = new TH1D("MC_ICVarMinus_A3p0d01",";IC Variable #mu^- A_{3}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_A4p0d01 = new TH1D("MC_ICVarMinus_A4p0d01",";IC Variable #mu^- A_{4}+0.01;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_LH = new TH1D("MC_ICVarMinus_LH",";IC Variable #mu^{-} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_RH = new TH1D("MC_ICVarMinus_RH",";IC Variable #mu^{-} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinus_LO = new TH1D("MC_ICVarMinus_LO",";IC Variable #mu^{-} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinusMuonAcc = new TH1D("MC_ICVarMinusMuonAcc",";IC Variable #mu^-;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinusMuonAcc_LH = new TH1D("MC_ICVarMinusMuonAcc_LH",";IC Variable #mu^{-} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinusMuonAcc_RH = new TH1D("MC_ICVarMinusMuonAcc_RH",";IC Variable #mu^{-} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    MC_ICVarMinusMuonAcc_LO = new TH1D("MC_ICVarMinusMuonAcc_LO",";IC Variable #mu^{-} LO;Events / 100 pb^{-1}",500,-2.5,2.5);

    MC_WPlusPzMatching = new TH1D("MC_WPlusPzMatching",";False/True;Events",2,-0.5,1.5);
    MC_WMinusPzMatching = new TH1D("MC_WMinusPzMatching",";False/True;Events",2,-0.5,1.5);

    MC_PhiStar1Test1 = new TH1D("MC_PhiStar1Test1",";#phi *;Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Plus = new TH1D("MC_PhiStar1Plus",";#phi * from W^{+};Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1PlusMuonAcc = new TH1D("MC_PhiStar1PlusMuonAcc",";#phi * from W^{+};Events MuonAcc / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Minus = new TH1D("MC_PhiStar1Minus",";#phi * from W^{-};Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_CosPhiStar1Test1 = new TH1D("MC_CosPhiStar1Test1",";cos(#phi *);Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Test2 = new TH1D("MC_PhiStar1Test2",";#phi *;Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Test3_acc10 = new TH1D("MC_PhiStar1Test3_acc10",";#phi *;Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_CosPhiStar1_acc10 = new TH1D("MC_CosPhiStar1_acc10",";cos(#phi *);Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Test4_acc20 = new TH1D("MC_PhiStar1Test3_acc20",";#phi *;Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Test3_pt10 = new TH1D("MC_PhiStar1Test3_pt10",";#phi *;Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_PhiStar1Test4_pt20 = new TH1D("MC_PhiStar1Test3_pt20",";#phi *;Events / 100 pb^{-1}", 1000, -5.005, 4.995);
    MC_CosThetaStar1PlusTest1 = new TH1D("MC_CosThetaStar1PlusTest1", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1MinusTest1 = new TH1D("MC_CosThetaStar1MinusTest1", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

    MC_CosThetaStar1Plus = new TH1D("MC_CosThetaStar1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus = new TH1D("MC_CosThetaStar1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar2Plus = new TH1D("MC_CosThetaStar2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar2Minus = new TH1D("MC_CosThetaStar2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar3Plus = new TH1D("MC_CosThetaStar3Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar3Minus = new TH1D("MC_CosThetaStar3Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus_LH = new TH1D("MC_CosThetaStar1Minus_LH", ";cos #theta^{*} from W^{-} LH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus_RH = new TH1D("MC_CosThetaStar1Minus_RH", ";cos #theta^{*} from W^{-} RH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus_LO = new TH1D("MC_CosThetaStar1Minus_LO", ";cos #theta^{*} from W^{-} LO ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Plus_LH = new TH1D("MC_CosThetaStar1Plus_LH", ";cos #theta^{*} from W^{+} LH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Plus_RH = new TH1D("MC_CosThetaStar1Plus_RH", ";cos #theta^{*} from W^{+} RH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Plus_LO = new TH1D("MC_CosThetaStar1Plus_LO", ";cos #theta^{*} from W^{+} LO ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1PlusMuonAcc = new TH1D("MC_CosThetaStar1PlusMuonAcc", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1MinusMuonAcc = new TH1D("MC_CosThetaStar1MinusMuonAcc", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1MinusMuonAcc_LH = new TH1D("MC_CosThetaStar1MinusMuonAcc_LH", ";cos #theta^{*} from W^{-} LH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1MinusMuonAcc_RH = new TH1D("MC_CosThetaStar1MinusMuonAcc_RH", ";cos #theta^{*} from W^{-} RH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1MinusMuonAcc_LO = new TH1D("MC_CosThetaStar1MinusMuonAcc_LO", ";cos #theta^{*} from W^{-} LO ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1PlusMuonAcc_LH = new TH1D("MC_CosThetaStar1PlusMuonAcc_LH", ";cos #theta^{*} from W^{+} LH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1PlusMuonAcc_RH = new TH1D("MC_CosThetaStar1PlusMuonAcc_RH", ";cos #theta^{*} from W^{+} RH ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1PlusMuonAcc_LO = new TH1D("MC_CosThetaStar1PlusMuonAcc_LO", ";cos #theta^{*} from W^{+} LO ;Events / 100 pb^{-1}", 300,-1.5,1.5);

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

    MC_HWA0Numerator = new TH1D("MC_HWA0Numerator",";gen W P_{T} [GeV];A_{0} Numerator",1000,-0.5,999.5);
    MC_HWA1Numerator = new TH1D("MC_HWA1Numerator",";gen W P_{T} [GeV];A_{1} Numerator",1000,-0.5,999.5);
    MC_HWA2Numerator = new TH1D("MC_HWA2Numerator",";gen W P_{T} [GeV];A_{2} Numerator",1000,-0.5,999.5);
    MC_HWA3Numerator = new TH1D("MC_HWA3Numerator",";gen W P_{T} [GeV];A_{3} Numerator",1000,-0.5,999.5);
    MC_HWA4Numerator = new TH1D("MC_HWA4Numerator",";gen W P_{T} [GeV];A_{4} Numerator",1000,-0.5,999.5);

    MC_HWPlusA0Numerator = new TH1D("MC_HWPlusA0Numerator",";gen W^{+} P_{T} [GeV];A_{0} Numerator",1000,-0.5,999.5);
    MC_HWPlusA1Numerator = new TH1D("MC_HWPlusA1Numerator",";gen W^{+} P_{T} [GeV];A_{1} Numerator",1000,-0.5,999.5);
    MC_HWPlusA2Numerator = new TH1D("MC_HWPlusA2Numerator",";gen W^{+} P_{T} [GeV];A_{2} Numerator",1000,-0.5,999.5);
    MC_HWPlusA3Numerator = new TH1D("MC_HWPlusA3Numerator",";gen W^{+} P_{T} [GeV];A_{3} Numerator",1000,-0.5,999.5);
    MC_HWPlusA4Numerator = new TH1D("MC_HWPlusA4Numerator",";gen W^{+} P_{T} [GeV];A_{4} Numerator",1000,-0.5,999.5);

    MC_HWMinusA0Numerator = new TH1D("MC_HWMinusA0Numerator",";gen W^{-} P_{T} [GeV];A_{0} Numerator",1000,-0.5,999.5);
    MC_HWMinusA1Numerator = new TH1D("MC_HWMinusA1Numerator",";gen W^{-} P_{T} [GeV];A_{1} Numerator",1000,-0.5,999.5);
    MC_HWMinusA2Numerator = new TH1D("MC_HWMinusA2Numerator",";gen W^{-} P_{T} [GeV];A_{2} Numerator",1000,-0.5,999.5);
    MC_HWMinusA3Numerator = new TH1D("MC_HWMinusA3Numerator",";gen W^{-} P_{T} [GeV];A_{3} Numerator",1000,-0.5,999.5);
    MC_HWMinusA4Numerator = new TH1D("MC_HWMinusA4Numerator",";gen W^{-} P_{T} [GeV];A_{4} Numerator",1000,-0.5,999.5);

    MC_HWPlusAiDenominator = new TH1D("MC_HWPlusAiDenominator",";gen W^{+} P_{T} [GeV];A_{i} Denominator",1000,-0.5,999.5);
    MC_HWMinusAiDenominator = new TH1D("MC_HWMinusAiDenominator",";gen W^{-} P_{T} [GeV];A_{i} Denominator",1000,-0.5,999.5);
    MC_HWAiDenominator = new TH1D("MC_HWAiDenominator",";gen W P_{T} [GeV];A_{i} Denominator",1000,-0.5,999.5);

    TH1::SetDefaultSumw2(kFALSE);
    //reason we reset the setdefaultsumw2 flag is because of Warning in <TH2::GetBinContent>: this method must be overridden!
    //see here for more info: http://root.cern.ch/root/roottalk/roottalk08/0278.html

    MC_PhiStar_vs_CosThetaStar = new TH2D("MC_PhiStar_vs_CosThetaStar",";#phi *;cos(#theta *)", 30, -1.505, 1.495, 100, -5.005, 4.995);
    MC_PhiStar_vs_CosThetaStar_Plus = new TH2D("MC_PhiStar_vs_CosThetaStar_Plus",";#phi *;cos(#theta *)", 30, -1.505, 1.495, 100, -5.005, 4.995);
    MC_PhiStar_vs_CosThetaStar_Minus = new TH2D("MC_PhiStar_vs_CosThetaStar_Minus",";#phi *;cos(#theta *)", 30, -1.505, 1.495, 100, -5.005, 4.995);
    MC_LP_vs_PhiStar = new TH2D("MC_LP_vs_PhiStar",";LP;#phi *",50, -2.5, 2.5, 100, -5.0, 5.0);
    MC_LP_vs_PhiStarPlus = new TH2D("MC_LP_vs_PhiStarPlus",";LP(+);#phi *",50, -2.5, 2.5, 100, -5.0, 5.0);
    MC_LP_vs_PhiStarMinus = new TH2D("MC_LP_vs_PhiStarMinus",";LP(-);#phi *",50, -2.5, 2.5, 100, -5.0, 5.0);
    MC_LPcol_vs_CosThetaStar = new TH2D("MC_LPcol_vs_CosThetaStar", ";2(LP - 0.5);cos#theta *", 50, -2.5, 2.5, 30, -1.5, 1.5);
    MC_LPcol2_vs_CosThetaStar = new TH2D("MC_LPcol2_vs_CosThetaStar", ";2(LP - 0.5*(E_{W}/P_{W}));cos#theta *", 50, -2.5, 2.5, 30, -1.5, 1.5);
    MC_LeptonTest1 = new TH2D("MC_LeptonTest1", ";lepton P;lepton P", 1000, -0.5, 999.5, 1000, -0.5, 999.5);
    MC_LP3D_vs_LP = new TH2D("MC_LP3D_vs_LP", ";3D LP;LP", 50, -2.5, 2.5, 50, -2.5, 2.5);
    MC_LPcol_vs_CosThetaStarPlus = new TH2D("MC_LPcol_vs_CosThetaStarPlus", ";2(LP - 0.5);cos#theta *", 50, -2.5, 2.5, 30, -1.5, 1.5);
    MC_LPcol_vs_CosThetaStarMinus = new TH2D("MC_LPcol_vs_CosThetaStarMinus", ";2(LP - 0.5);cos#theta *", 50, -2.5, 2.5, 30, -1.5, 1.5);
    MC_diffLPcolCosThetaStar_vs_PhiStar = new TH2D("MC_diffLPcolCosThetaStar_vs_PhiStar",";2(LP-0.5) - cos#theta *;#phi *",50, -2.5, 2.5, 100, -5.0, 5.0);
    MC_diffLPcolCosThetaStar_vs_PhiStarPlus = new TH2D("MC_diffLPcolCosThetaStar_vs_PhiStarPlus",";2(LP-0.5) - cos#theta *;#phi *",50, -2.5, 2.5, 100, -5.0, 5.0);
    MC_diffLPcolCosThetaStar_vs_PhiStarMinus = new TH2D("MC_diffLPcolCosThetaStar_vs_PhiStarMinus",";2(LP-0.5) - cos#theta *;#phi *",50, -2.5, 2.5, 100, -5.0, 5.0);
    MC_leptonrapidity_vs_PhiStar = new TH2D("MC_leptonrapidity_vs_PhiStar",";lepton #eta;#phi *",100, -5.0, 5.0, 100, -5.0, 5.0);
    MC_leptonrapidity_vs_PhiStarPlus = new TH2D("MC_leptonrapidity_vs_PhiStarPlus",";lepton #eta;#phi *",100, -5.0, 5.0, 100, -5.0, 5.0);
    MC_leptonrapidity_vs_PhiStarMinus = new TH2D("MC_leptonrapidity_vs_PhiStarMinus",";lepton #eta;#phi *",100, -5.0, 5.0, 100, -5.0, 5.0);
    MC_leptonPt_vs_PhiStar = new TH2D("MC_leptonPt_vs_PhiStar",";P_{T}(lepton);#phi *",250, -0.5, 499.5, 100, -5.0, 5.0);
    MC_leptonPt_vs_PhiStarPlus = new TH2D("MC_leptonPt_vs_PhiStarPlus",";P_{T}(lepton);#phi *",250, -0.5, 499.5, 100, -5.0, 5.0);
    MC_leptonPt_vs_PhiStarMinus = new TH2D("MC_leptonPt_vs_PhiStarMinus",";P_{T}(lepton);#phi *",250, -0.5, 499.5, 100, -5.0, 5.0);
    MC_leptonWrapiditydiff_vs_PhiStar = new TH2D("MC_leptonWrapiditydiff_vs_PhiStar",";lepton #eta;#phi *",100, -5.0, 5.0, 100, -5.0, 5.0);
    MC_leptonWrapiditydiff_vs_PhiStarPlus = new TH2D("MC_leptonWrapiditydiff_vs_PhiStarPlus",";lepton #eta;#phi *",100, -5.0, 5.0, 100, -5.0, 5.0);
    MC_leptonWrapiditydiff_vs_PhiStarMinus = new TH2D("MC_leptonWrapiditydiff_vs_PhiStarMinus",";lepton #eta;#phi *",100, -5.0, 5.0, 100, -5.0, 5.0);

    MC_MuonEtaCosThetaStar1Plus = new TH2D("MC_MuonEtaCosThetaStar1Plus",";cos #theta^{*} from W^{+};#mu^{+} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_MuonEtaCosThetaStar1Minus = new TH2D("MC_MuonEtaCosThetaStar1Minus",";cos #theta^{*} from W^{-};#mu^{-} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_MuonPtCosThetaStar1Plus = new TH2D("MC_MuonPtCosThetaStar1Plus",";cos #theta^{*} from W^{+};#mu^{+} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_MuonPtCosThetaStar1Minus = new TH2D("MC_MuonPtCosThetaStar1Minus",";cos #theta^{*} from W^{-};#mu^{-} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_WEtaCosThetaStar1Plus = new TH2D("MC_WEtaCosThetaStar1Plus",";cos #theta^{*} from W^{+};W^{+} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_WEtaCosThetaStar1Minus = new TH2D("MC_WEtaCosThetaStar1Minus",";cos #theta^{*} from W^{-};W^{-} #eta",300,-1.5,1.5,1000,-5.5,4.5);
    MC_WPtCosThetaStar1Plus = new TH2D("MC_WPtCosThetaStar1Plus",";cos #theta^{*} from W^{+};W^{+} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_WPtCosThetaStar1Minus = new TH2D("MC_WPtCosThetaStar1Minus",";cos #theta^{*} from W^{-};W^{-} P_{t}",300,-1.5,1.5,1000,-0.5,999.5);
    MC_WPtPzPlus = new TH2D("MC_WPtPzPlus",";W^{+} P_{z} / P_{T}; W^+ P_{T}",100,-0.5,99.5,1000,-0.5,999.5);
    MC_WPtPzMinus = new TH2D("MC_WPtPzMinus",";W^{-} P_{z} / P_{T}; W^- P_{T}",100,-0.5,99.5,1000,-0.5,999.5);
    MC_WMuPtPzPlus = new TH2D("MC_WMuPtPzPlus",";W^{+} / #mu^{+} P_{z};W^{+} / #mu^{+} P_{T}",2000,-10.005,9.995,1000,-0.005,9.995);
    MC_WMuPtPzMinus = new TH2D("MC_WMuPtPzMinus",";W^{-} / #mu^{-} P_{z};W^{-} / #mu^{+} P_{T}",2000,-10.005,9.995,1000,-0.005,9.995);
    MC_WPtY = new TH2D("MC_WPtY",";W P_{T}; W |Y|",1000,-0.5,999.5,  50,-0.05,4.95);
    MC_WYvsMuEta = new TH2D("MC_WYvsMuEta", ";W Y; #mu #eta", 30, -15.5, 14.5, 30, -15.5, 14.5);
    MC_WPT_vs_LepPTPlus = new TH2D("MC_WPT_vs_LepPTPlus", ";P_{T}(W^{+});P_{T}(lep^{+})",100,0.0,1000.0,100,0.0,1000.0);
    MC_WPT_vs_LepPTMinus = new TH2D("MC_WPT_vs_LepPTMinus", ";P_{T}(W^{-});P_{T}(lep^{-})",100,0.0,1000.0,100,0.0,1000.0);
    MC_WPT_vs_LepEtaPlus = new TH2D("MC_WPT_vs_LepEtaPlus", ";P_{T}(W^{+});|#eta(lep^{+})|",100,0.0,1000.0,50,0.0,5.0);
    MC_WPT_vs_LepEtaMinus = new TH2D("MC_WPT_vs_LepEtaMinus", ";P_{T}(W^{-});|#eta(lep^{-})|",100,0.0,1000.0,50,0.0,5.0);

    
    MC_CosThetaStar1CorrPlus = new TH1D("MC_CosThetaStar1CorrPlus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1CorrPlus_LH = new TH1D("MC_CosThetaStar1CorrPlus_LH", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1CorrPlus_RH = new TH1D("MC_CosThetaStar1CorrPlus_RH", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1CorrPlus_LO = new TH1D("MC_CosThetaStar1CorrPlus_LO", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

  }

  bool MCWPlots::Process(Event::Data & ev) {
    GenMatrixBin myGenMatrixBin(&ev);
    //initialise some TLorentzVectors
    TLorentzVector jRestMu, jRestQuark, jRestQuark2, jGenW, jGenLepton;
    Event::GenObject const * genLepton;
    Event::GenObject const * genLepton2;//for the other lepton from the Z-decay (so we can apply acceptance to it too!)
    Event::GenObject const * genLeptonNu;
    unsigned int counter = 0; //just a temporary variable so we can tell how many particles share the same mother as the W
    //in general, since the W mass is large, use rapidity and not pseudo-rapidity in the plots (they are equivalent in the massless limit)

    //the loop below goes through the particles in the GenMatrixBin identified as jets
    //these are the outgoing quarks and gluons - first we check that any of the outgoing quarks
    //shares the same mother as the W, then that it isn't a gluon. Finally we check that the
    //mother of the W has only 2 daughters

    TLorentzVector jJetSum, jJetSum2; //initialises as empty for each event
    TLorentzVector jtempJetSum; //for conversion from LorentzV to TLorentzVector

    if(TString(mVBoson)=="W") {forW = true;forZ = false;}
    if(TString(mVBoson)=="Z") {forW = false;forZ = true;}
    if(TString(mVBoson) != "Z" && TString(mVBoson) != "W") {
      cout << "MCWPlots: Error invalid Vector Boson choice!"<<endl;
      return false;
    }
    vector <Event::GenObject const *> theVBosons;


    if(forW) {
      if(myGenMatrixBin.the_GenW.size()==0) return false;
      theVBosons = myGenMatrixBin.the_GenW;

      jGenW = TLVConvert(myGenMatrixBin.the_GenW.at(0));
      //we can make the below statements with confidence if we use the MCWLeptonExists cut which checks explicitly that the W decays to (one) lepton
      //and of course if we want to reproduce the muon plots, select to use MCWMuonExists (and similarly for other leptons...)
      if(myGenMatrixBin.the_GenEli.size()) {
	jGenLepton = TLVConvert(myGenMatrixBin.the_GenEli.at(0));
	genLepton = myGenMatrixBin.the_GenEli.at(0);
	genLeptonNu = myGenMatrixBin.the_GenEliNu.at(0);
      } else if(myGenMatrixBin.the_GenMuon.size()) {
	jGenLepton = TLVConvert(myGenMatrixBin.the_GenMuon.at(0));
	genLepton = myGenMatrixBin.the_GenMuon.at(0);
	genLeptonNu = myGenMatrixBin.the_GenMuonNu.at(0);
      } else if(myGenMatrixBin.the_GenTau.size()) {
	jGenLepton = TLVConvert(myGenMatrixBin.the_GenTau.at(0));
	genLepton = myGenMatrixBin.the_GenTau.at(0);
	genLeptonNu = myGenMatrixBin.the_GenTauNu.at(0);
      } else {
	cout << "MCWPlots: The W boson does not decay to a lepton" << endl;
	return false;
      }
    }

    if(forZ) {
      if(myGenMatrixBin.the_GenZ.size()==0) return false;
      jGenW = TLVConvert(myGenMatrixBin.the_GenZ.at(0));
      theVBosons = myGenMatrixBin.the_GenZ;
      //in the Z case, genLepton should represent a single charge as it makes no difference which charge we choose...
      //a Z will decay to two leptons
      //here we make a decision to either store the positive charge lepton from the Z-decay (ID <0 is the antilepton and hence the positively charged one)
      //or the negative charge lepton from the Z-decay (ID >0 is the lepton and hence the negatively charged one)
      //of course the neutrino only makes sense in the W-boson decay...
      //we store both muons so that we can apply acceptance to both
      //here we must also check that the Z decays to two leptons (not neutrinos, u-type quarks or d-type quarks etc)

      if(myGenMatrixBin.the_GenEli.size()==2) {
	if(myGenMatrixBin.the_GenEli.at(0)->GetID()<0) { //if the ID is less than zero, then it has a positive charge
	  jGenLepton = TLVConvert(myGenMatrixBin.the_GenEli.at(0));
	  genLepton = myGenMatrixBin.the_GenEli.at(0);
	  genLepton2 = myGenMatrixBin.the_GenEli.at(1);
	} else {
	  jGenLepton = TLVConvert(myGenMatrixBin.the_GenEli.at(1));
	  genLepton = myGenMatrixBin.the_GenEli.at(1);
	  genLepton2 = myGenMatrixBin.the_GenEli.at(0);
	}
      } else if(myGenMatrixBin.the_GenMuon.size()==2) {
	if(myGenMatrixBin.the_GenMuon.at(0)->GetID()<0) {
	  jGenLepton = TLVConvert(myGenMatrixBin.the_GenMuon.at(0));
	  genLepton = myGenMatrixBin.the_GenMuon.at(0);
	  genLepton2 = myGenMatrixBin.the_GenMuon.at(1);
	} else {
	  jGenLepton = TLVConvert(myGenMatrixBin.the_GenMuon.at(1));
	  genLepton = myGenMatrixBin.the_GenMuon.at(1);
	  genLepton2 = myGenMatrixBin.the_GenMuon.at(0);
	}
      }else if(myGenMatrixBin.the_GenTau.size()==2) {
	if(myGenMatrixBin.the_GenTau.at(0)->GetID()<0) {
	  jGenLepton = TLVConvert(myGenMatrixBin.the_GenTau.at(0));
	  genLepton = myGenMatrixBin.the_GenTau.at(0);
	  genLepton2 = myGenMatrixBin.the_GenTau.at(1);
	} else {
	  jGenLepton = TLVConvert(myGenMatrixBin.the_GenTau.at(1));
	  genLepton = myGenMatrixBin.the_GenTau.at(1);
	  genLepton2 = myGenMatrixBin.the_GenTau.at(0);
	}
      } else {	
	return false;
	//cout << "MCWPlots: Have we found a one legged Z?"<<endl;
	//ev.PrintGen();
      }
    }

    for(unsigned int i=0; i<myGenMatrixBin.the_GenJets.size(); i++) {
      MC_JetPtAll->Fill(myGenMatrixBin.the_GenJets.at(i)->Pt(), ev.GetEventWeight()); //get the genJet Pt distribution for all jets
      MC_JetEtaAll->Fill(myGenMatrixBin.the_GenJets.at(i)->Eta(), ev.GetEventWeight()); //get the genJet Eta distribution for all jets
      //jJetSum -= (*(myGenMatrixBin.the_GenJets.at(i))); //vectorially sum all final state quarks and gluons. take negative vector sum (=MHT =GenW). This line is now replaced by the next two lines, due to the change in the dataformat
      jtempJetSum = TLVConvert(myGenMatrixBin.the_GenJets.at(i));
      jJetSum -= jtempJetSum;
      //now do it like we do in reco, with a pt and eta cut on the individual jets going into the sum - see NOTE below
      if(myGenMatrixBin.the_GenJets.at(i)->Pt() > 30.0 && fabs(myGenMatrixBin.the_GenJets.at(i)->Eta() < 3.0) ) jJetSum2 -= jtempJetSum; //jJetSum2 -= (*(myGenMatrixBin.the_GenJets.at(i)));
      if(myGenMatrixBin.the_GenJets.at(i)->GetMother() == theVBosons.at(0)->GetMother() && myGenMatrixBin.the_GenJets.at(i)->GetIndex() != 21) {
	//jRestQuark = (*(myGenMatrixBin.the_GenJets.at(i)));
        jRestQuark = jtempJetSum;
        counter++;
      }
    }

    MC_JetMultiplicityAll->Fill(myGenMatrixBin.the_GenJets.size(), ev.GetEventWeight());

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
      jRestMu = jGenLepton;
      jSol1Mu = jGenLepton; //to boost the muon according to one of the two pz solutions
      jSol2Mu = jGenLepton; //and the other
      jWrongMu = jGenLepton; //and to see the effects of having 100% wrong choice on pz
      jRightMu = jGenLepton; //and also if you pick 100% right choice, but the effect of choosing mw*=mw
      jBoost = jGenW.BoostVector();
      jBoost2 = (jRestQuark + jGenW).BoostVector();
      jRestMu.Boost(-jBoost);
      jRestQuark.Boost(-jBoost);
      jRestQuark2.Boost(-jBoost2);
      //CosThetaStar1 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jGenW));
      CosThetaStar2 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jRestQuark));
      CosThetaStar3 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jRestQuark2));
      delta_w_mu = jGenW.Pz() - jGenLepton.Pz();
      delta_w_mu_mu = fabs(delta_w_mu - jGenLepton.Pz());
      //W+ has particle ID = +24
      //if(theVBosons.at(0)->GetID() > 0) { //use genlepton ID since we need to adapt this code for the Z!
      if(genLepton->GetID() < 0) {
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

    // ----------
    TLorentzVector hframelepton = HTransform(jGenLepton, jGenW);
    MC_PhiStar1Test1->Fill(hframelepton.Phi(), ev.GetEventWeight());
    MC_CosPhiStar1Test1->Fill(cos(hframelepton.Phi()), ev.GetEventWeight());
    //MC_PhiStar1Test2->Fill(hframelepton.Phi(), ev.GetEventWeight());
    if(jGenLepton.Pt()>10 && fabs(jGenLepton.Eta()) < 2.1) {
      MC_PhiStar1Test3_acc10->Fill(hframelepton.Phi(), ev.GetEventWeight());
      MC_CosPhiStar1_acc10->Fill(cos(hframelepton.Phi()), ev.GetEventWeight());
      if(jGenLepton.Pt()>20) MC_PhiStar1Test4_acc20->Fill(hframelepton.Phi(), ev.GetEventWeight()); //since we already check the eta acceptance
    }
    if(jGenLepton.Pt()>10) MC_PhiStar1Test3_pt10->Fill(hframelepton.Phi(), ev.GetEventWeight()); //without the eta cut (to see what really affects the phi* dist)
    if(jGenLepton.Pt()>20) MC_PhiStar1Test4_pt20->Fill(hframelepton.Phi(), ev.GetEventWeight());

    MC_PhiStar_vs_CosThetaStar->Fill(hframelepton.CosTheta(), hframelepton.Phi(), ev.GetEventWeight());
    //to x-check with distributions as below:
    if(genLepton->GetID() < 0) {
      MC_CosThetaStar1PlusTest1->Fill(hframelepton.CosTheta(), ev.GetEventWeight());
      MC_PhiStar1Plus->Fill(hframelepton.Phi(), ev.GetEventWeight());
      MC_PhiStar_vs_CosThetaStar_Plus->Fill(hframelepton.CosTheta(), hframelepton.Phi(), ev.GetEventWeight());
    } else {
      MC_CosThetaStar1MinusTest1->Fill(hframelepton.CosTheta(), ev.GetEventWeight());
      MC_PhiStar1Minus->Fill(hframelepton.Phi(), ev.GetEventWeight());
      MC_PhiStar_vs_CosThetaStar_Minus->Fill(hframelepton.CosTheta(), hframelepton.Phi(), ev.GetEventWeight());
    }

    if(genLepton->GetID() > 0) { //i.e. negative charge
      MC_HWMinusA4Numerator->Fill(theVBosons.at(0)->Pt(), hframelepton.CosTheta() * ev.GetEventWeight());
      MC_HWMinusA3Numerator->Fill(theVBosons.at(0)->Pt(), cos(hframelepton.Phi()) * sin(hframelepton.Theta()) * ev.GetEventWeight());
      MC_HWMinusA2Numerator->Fill(theVBosons.at(0)->Pt(), sin(hframelepton.Theta()) * sin(hframelepton.Theta()) * cos(2.0*hframelepton.Phi()) * ev.GetEventWeight());
      MC_HWMinusA1Numerator->Fill(theVBosons.at(0)->Pt(), cos(hframelepton.Phi()) * sin(2.0*hframelepton.Theta()) * ev.GetEventWeight());
      MC_HWMinusA0Numerator->Fill(theVBosons.at(0)->Pt(), 0.5*(1.0-3.0*hframelepton.CosTheta()*hframelepton.CosTheta()) * ev.GetEventWeight());
      MC_HWMinusAiDenominator->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
    } else {
      MC_HWPlusA4Numerator->Fill(theVBosons.at(0)->Pt(), hframelepton.CosTheta() * ev.GetEventWeight());
      MC_HWPlusA3Numerator->Fill(theVBosons.at(0)->Pt(), cos(hframelepton.Phi()) * sin(hframelepton.Theta()) * ev.GetEventWeight());
      MC_HWPlusA2Numerator->Fill(theVBosons.at(0)->Pt(), sin(hframelepton.Theta()) * sin(hframelepton.Theta()) * cos(2.0*hframelepton.Phi()) * ev.GetEventWeight());
      MC_HWPlusA1Numerator->Fill(theVBosons.at(0)->Pt(), cos(hframelepton.Phi()) * sin(2.0*hframelepton.Theta()) * ev.GetEventWeight());
      MC_HWPlusA0Numerator->Fill(theVBosons.at(0)->Pt(), 0.5*(1.0-3.0*hframelepton.CosTheta()*hframelepton.CosTheta()) * ev.GetEventWeight());
      MC_HWPlusAiDenominator->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
    }

    MC_HWA4Numerator->Fill(theVBosons.at(0)->Pt(), hframelepton.CosTheta() * ev.GetEventWeight());
    MC_HWA3Numerator->Fill(theVBosons.at(0)->Pt(), cos(hframelepton.Phi()) * sin(hframelepton.Theta()) * ev.GetEventWeight());
    MC_HWA2Numerator->Fill(theVBosons.at(0)->Pt(), sin(hframelepton.Theta()) * sin(hframelepton.Theta()) * cos(2.0*hframelepton.Phi()) * ev.GetEventWeight());
    MC_HWA1Numerator->Fill(theVBosons.at(0)->Pt(), cos(hframelepton.Phi()) * sin(2.0*hframelepton.Theta()) * ev.GetEventWeight());
    MC_HWA0Numerator->Fill(theVBosons.at(0)->Pt(), 0.5*(1.0-3.0*hframelepton.CosTheta()*hframelepton.CosTheta()) * ev.GetEventWeight());
    MC_HWAiDenominator->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
    // ----------


    //the FindBoost method was developed after the above code was written (and since the above worked, don't touch hehe)
    jMCSolW = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
    if(jMCSolW.realSolutions) {
      //to convert the index, cast the answer (0.0,2.0) to int
      int index = int( (jMCSolW.rightSol + 1.0) / 0.01 );
      //if(theVBosons.at(0)->GetID() > 0) { //use genlepton ID since we need to adapt this code for the Z!
      if(genLepton->GetID() < 0) {
	MC_CosThetaStar1Plus->Fill(jMCSolW.rightSol, ev.GetEventWeight()); //std::cout << "costhetastar1_true: " << jMCSolW.rightSol << std::endl;
	MC_MuonEtaCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenLepton.Eta(), ev.GetEventWeight());
	MC_WEtaCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenW.Eta(), ev.GetEventWeight());
	MC_MuonPtCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenLepton.Pt(), ev.GetEventWeight());
	MC_WPtCosThetaStar1Plus->Fill(jMCSolW.rightSol, jGenW.Pt(), ev.GetEventWeight());
	if(forW) {
	  MC_CosThetaStar1Plus_LH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	  //std::cout << "CorrFactor+ = " << CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) << std::endl;
	  MC_CosThetaStar1Plus_RH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	  MC_CosThetaStar1Plus_LO->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	}
	if(forZ) {
	  MC_CosThetaStar1Plus_LH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	  MC_CosThetaStar1Plus_RH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	  MC_CosThetaStar1Plus_LO->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));	  
	}
      }else{
	MC_CosThetaStar1Minus->Fill(jMCSolW.rightSol, ev.GetEventWeight()); //std::cout << "costhetastar1_true: " << jMCSolW.rightSol << std::endl;
	MC_MuonEtaCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenLepton.Eta(), ev.GetEventWeight());
	MC_WEtaCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenW.Eta(), ev.GetEventWeight());
	MC_MuonPtCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenLepton.Pt(), ev.GetEventWeight());
	MC_WPtCosThetaStar1Minus->Fill(jMCSolW.rightSol, jGenW.Pt(), ev.GetEventWeight());
	if(forW) {
	  MC_CosThetaStar1Minus_LH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	  //std::cout << "CorrFactor- = " << CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) << std::endl;
	  MC_CosThetaStar1Minus_RH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	  MC_CosThetaStar1Minus_LO->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	}
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
    MC_MuonPt->Fill(genLepton->Pt(), ev.GetEventWeight());
    MC_MuonEta->Fill(genLepton->Eta(), ev.GetEventWeight());
    MC_MuonEtaAbs->Fill(fabs(genLepton->Eta()), ev.GetEventWeight());
    if(forW) {
      //neutrinos only exist in the W-case at the gen level from its decay
      MC_MuonNuPt->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
      MC_MuonNuEta->Fill(genLeptonNu->Eta(), ev.GetEventWeight());
      MC_MuonNuEtaAbs->Fill(fabs(genLeptonNu->Eta()), ev.GetEventWeight());
    }
    //add a couple of plots for the separate charges Pt and Eta of the muons and neutrinos
    //and the IC variable (projection of lepton pt to mht normalised to mht). These plots are in the format for the macro
    //double ICVariable = ((genLepton->Px() * jJetSum.Px()) + (genLepton->Py() * jJetSum.Py())) / (jJetSum.Pt() * jJetSum.Pt());
    double ICVariable = ((genLepton->Px() * jGenW.Px()) + (genLepton->Py() * jGenW.Py())) / (jGenW.Pt() * jGenW.Pt());

    
    //some 2D correlation plots between lepton in HFrame and LP variable
    MC_LP_vs_PhiStar->Fill(ICVariable, hframelepton.Phi(), ev.GetEventWeight());
    MC_LPcol_vs_CosThetaStar->Fill(2.0*(ICVariable - 0.5), hframelepton.CosTheta(), ev.GetEventWeight());
    //here we check that the lepton momentum 3Vector can be reconstructed by the LorentzBoost from the W-Rest Frame
    double coscol2gamma = jGenW.E() / jGenW.M();
    double coscol2beta = jGenW.P() / jGenW.E();
    double plperpW = jGenW.M() * 0.5 * TMath::Sin(hframelepton.Theta());
    double plparrW = coscol2gamma * jGenW.M() * 0.5 * (hframelepton.CosTheta() + coscol2beta);
    MC_LeptonTest1->Fill(TMath::Sqrt((plperpW * plperpW) + (plparrW * plparrW)), genLepton->P(), ev.GetEventWeight());
    //here we check the correlation between cos(theta*) and the 3D LLP variable i.e. |P(lepton)| / |P(W)|
    double ICVariable3D = genLepton->P() / jGenW.P();
    MC_LPcol2_vs_CosThetaStar->Fill((2.0*ICVariable3D) - (jGenW.E()/jGenW.P()), hframelepton.CosTheta(), ev.GetEventWeight());
    MC_LP3D_vs_LP->Fill(TMath::Cos(ROOT::Math::VectorUtil::DeltaPhi(jGenW,jGenLepton))*TMath::Sin(jGenLepton.Theta()) / TMath::Sin(jGenW.Theta()), ICVariable / ICVariable3D, ev.GetEventWeight());

    MC_diffLPcolCosThetaStar_vs_PhiStar->Fill((2.0*(ICVariable - 0.5)) - hframelepton.CosTheta(), hframelepton.Phi(), ev.GetEventWeight());
    MC_leptonPt_vs_PhiStar->Fill(genLepton->Pt(), hframelepton.Phi(), ev.GetEventWeight());
    MC_leptonrapidity_vs_PhiStar->Fill(genLepton->Eta(), hframelepton.Phi(), ev.GetEventWeight());
    MC_leptonWrapiditydiff_vs_PhiStar->Fill(genLepton->Rapidity() - jGenW.Rapidity(), hframelepton.Phi(), ev.GetEventWeight());
    if(genLepton->GetID() < 0) {
      MC_LP_vs_PhiStarPlus->Fill(ICVariable, hframelepton.Phi(), ev.GetEventWeight());
      MC_LPcol_vs_CosThetaStarPlus->Fill(2.0*(ICVariable - 0.5), hframelepton.CosTheta(), ev.GetEventWeight());
      MC_diffLPcolCosThetaStar_vs_PhiStarPlus->Fill((2.0*(ICVariable - 0.5)) - hframelepton.CosTheta(), hframelepton.Phi(), ev.GetEventWeight());
      MC_leptonPt_vs_PhiStarPlus->Fill(genLepton->Pt(), hframelepton.Phi(), ev.GetEventWeight());
      MC_leptonrapidity_vs_PhiStarPlus->Fill(genLepton->Eta(), hframelepton.Phi(), ev.GetEventWeight());
      MC_leptonWrapiditydiff_vs_PhiStarPlus->Fill(genLepton->Rapidity() - jGenW.Rapidity(), hframelepton.Phi(), ev.GetEventWeight());
    } else {
      MC_LP_vs_PhiStarMinus->Fill(ICVariable, hframelepton.Phi(), ev.GetEventWeight());
      MC_LPcol_vs_CosThetaStarMinus->Fill(2.0*(ICVariable - 0.5), hframelepton.CosTheta(), ev.GetEventWeight());
      MC_diffLPcolCosThetaStar_vs_PhiStarMinus->Fill((2.0*(ICVariable - 0.5)) - hframelepton.CosTheta(), hframelepton.Phi(), ev.GetEventWeight());
      MC_leptonPt_vs_PhiStarMinus->Fill(genLepton->Pt(), hframelepton.Phi(), ev.GetEventWeight());
      MC_leptonrapidity_vs_PhiStarMinus->Fill(genLepton->Eta(), hframelepton.Phi(), ev.GetEventWeight());
      MC_leptonWrapiditydiff_vs_PhiStarMinus->Fill(genLepton->Rapidity() - jGenW.Rapidity(), hframelepton.Phi(), ev.GetEventWeight());
    }


    //if(theVBosons.at(0)->GetID() > 0) { //use genlepton ID since we need to adapt this code for the Z!
    if(genLepton->GetID() < 0) {
      MC_MuonPtPlus->Fill(genLepton->Pt(), ev.GetEventWeight());
      MC_MuonEtaPlus->Fill(genLepton->Eta(), ev.GetEventWeight());
      //now apply acceptance - make sure that you do a different check forZ (two leptons from decay and not one!)
      if(forW && genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) MC_MuonEtaMuonAccPlus->Fill(genLepton->Eta(), ev.GetEventWeight());
      MC_MuonEtaAbsPlus->Fill(fabs(genLepton->Eta()), ev.GetEventWeight());
      if(forW) {
	MC_MuonNuPtPlus->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	MC_MuonNuEtaPlus->Fill(genLeptonNu->Eta(), ev.GetEventWeight());
	MC_MuonNuEtaAbsPlus->Fill(fabs(genLeptonNu->Eta()), ev.GetEventWeight());
	MC_ICVarPlus_A0p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 0, 1.1, 0, true));
	MC_ICVarPlus_A1p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 1, 1.1, 0, true));
	MC_ICVarPlus_A2p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 2, 1.1, 0, true));
	MC_ICVarPlus_A3p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 3, 1.1, 0, true));
	MC_ICVarPlus_A4p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 4, 1.1, 0, true));
	MC_ICVarPlus_A0p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 0, 0.01, 0, false));
	MC_ICVarPlus_A1p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 1, 0.01, 0, false));
	MC_ICVarPlus_A2p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 2, 0.01, 0, false));
	MC_ICVarPlus_A3p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 3, 0.01, 0, false));
	MC_ICVarPlus_A4p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 4, 0.01, 0, false));
      }
      MC_ICVarPlus->Fill(ICVariable, ev.GetEventWeight());

      if(jMCSolW.realSolutions) {
	int index = int( (jMCSolW.rightSol + 1.0) / 0.01 );
	if(forW) {
	  MC_ICVarPlus_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	  MC_ICVarPlus_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	  MC_ICVarPlus_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	  //the following plots were added to see what would happen if one were to artificially change the polarisation by e.g. fl+10%, fr-5%, f0-5% in every W (Pt,Y) bin
	  MC_MuonEtaPlus_LH->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	  MC_MuonEtaPlus_RH->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	  MC_MuonEtaPlus_LO->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	  //repeat the above leptons except apply the muon acceptance criteria from reco level
	  if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) {
	    MC_MuonEtaMuonAccPlus_LH->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	    MC_MuonEtaMuonAccPlus_RH->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	    MC_MuonEtaMuonAccPlus_LO->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	  }
	}
	if(forZ) {
	  MC_ICVarPlus_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	  MC_ICVarPlus_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	  MC_ICVarPlus_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	}
      }
    } else {
      MC_MuonPtMinus->Fill(genLepton->Pt(), ev.GetEventWeight());
      MC_MuonEtaMinus->Fill(genLepton->Eta(), ev.GetEventWeight());
      //now apply acceptance - make sure that you do a different check forZ (two leptons from decay and not one!)
      if(forW && genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) MC_MuonEtaMuonAccMinus->Fill(genLepton->Eta(), ev.GetEventWeight());
      MC_MuonEtaAbsMinus->Fill(fabs(genLepton->Eta()), ev.GetEventWeight());
      if(forW) {
	MC_MuonNuPtMinus->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	MC_MuonNuEtaMinus->Fill(genLeptonNu->Eta(), ev.GetEventWeight());
	MC_MuonNuEtaAbsMinus->Fill(fabs(genLeptonNu->Eta()), ev.GetEventWeight());
	MC_ICVarMinus_A0p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 0, 1.1, 0, true));
	MC_ICVarMinus_A1p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 1, 1.1, 0, true));
	MC_ICVarMinus_A2p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 2, 1.1, 0, true));
	MC_ICVarMinus_A3p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 3, 1.1, 0, true));
	MC_ICVarMinus_A4p10pc->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 4, 1.1, 0, true));
	MC_ICVarMinus_A0p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 0, 0.01, 0, false));
	MC_ICVarMinus_A1p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 1, 0.01, 0, false));
	MC_ICVarMinus_A2p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 2, 0.01, 0, false));
	MC_ICVarMinus_A3p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 3, 0.01, 0, false));
	MC_ICVarMinus_A4p0d01->Fill(ICVariable, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 4, 0.01, 0, false));
      }
      MC_ICVarMinus->Fill(ICVariable, ev.GetEventWeight());

      if(jMCSolW.realSolutions) {
	int index = int( (jMCSolW.rightSol + 1.0) / 0.01 );
	if(forW) {
	  MC_ICVarMinus_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	  MC_ICVarMinus_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	  MC_ICVarMinus_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));

	  //the following plots were added to see what would happen if one were to artificially change the polarisation by e.g. fl+10%, fr-5%, f0-5% in every W (Pt,Y) bin
	  MC_MuonEtaMinus_LH->Fill(genLepton->Eta(), ev.GetEventWeight()* CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	  MC_MuonEtaMinus_RH->Fill(genLepton->Eta(), ev.GetEventWeight()* CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	  MC_MuonEtaMinus_LO->Fill(genLepton->Eta(), ev.GetEventWeight()* CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	  //repeat the above leptons except apply the muon acceptance criteria from reco level
	  if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) {
	    MC_MuonEtaMuonAccMinus_LH->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	    MC_MuonEtaMuonAccMinus_RH->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	    MC_MuonEtaMuonAccMinus_LO->Fill(genLepton->Eta(), ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	  }

	}
      }
    }

    //now we'd like to plot both the cos(theta*) and LP variable with muon acceptance (pt>20, |eta|<2.1) and make templates too to see how good the fit is...
    //to do this properly for the Z we should also apply the acceptance to the other muon too
    if(jMCSolW.realSolutions) {
      if(jGenLepton.Pt() > 20.0 && fabs(jGenLepton.Eta()) < 2.1) {
	int index = int( (jMCSolW.rightSol + 1.0) / 0.01 );
	//if(theVBosons.at(0)->GetID() > 0) {
	if(genLepton->GetID() < 0) {

	  if(forW) {
	    MC_CosThetaStar1PlusMuonAcc->Fill(jMCSolW.rightSol, ev.GetEventWeight());
	    MC_CosThetaStar1PlusMuonAcc_LH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	    MC_CosThetaStar1PlusMuonAcc_RH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	    MC_CosThetaStar1PlusMuonAcc_LO->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	  }

	  if(forZ && genLepton2->Pt() > 20.0 && fabs(genLepton2->Eta()) < 2.1) { //make sure to check the second lepton acceptance for the Z
	    MC_CosThetaStar1PlusMuonAcc->Fill(jMCSolW.rightSol, ev.GetEventWeight());
	    MC_CosThetaStar1PlusMuonAcc_LH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	    MC_CosThetaStar1PlusMuonAcc_RH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	    MC_CosThetaStar1PlusMuonAcc_LO->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
  TLorentzVector hframelepton = HTransform(jGenLepton, jGenW);
	MC_PhiStar1PlusMuonAcc->Fill(hframelepton.Phi(),ev.GetEventWeight());
	  }

	  if(forW) {
	    MC_ICVarPlusMuonAcc->Fill(ICVariable, ev.GetEventWeight());
	    MC_ICVarPlusMuonAcc_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	    MC_ICVarPlusMuonAcc_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	    MC_ICVarPlusMuonAcc_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	  }

	  if(forZ && genLepton2->Pt() > 20.0 && fabs(genLepton2->Eta()) < 2.1) { //make sure to check the second lepton acceptance for the Z
	    MC_ICVarPlusMuonAcc->Fill(ICVariable, ev.GetEventWeight());
	    MC_ICVarPlusMuonAcc_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	    MC_ICVarPlusMuonAcc_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	    MC_ICVarPlusMuonAcc_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	  }

	}else{
	  MC_CosThetaStar1MinusMuonAcc->Fill(jMCSolW.rightSol, ev.GetEventWeight());
	  if(forW) {
	    MC_CosThetaStar1MinusMuonAcc_LH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	    MC_CosThetaStar1MinusMuonAcc_RH->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	    MC_CosThetaStar1MinusMuonAcc_LO->Fill(jMCSolW.rightSol, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	  }

	  MC_ICVarMinusMuonAcc->Fill(ICVariable, ev.GetEventWeight());
	  if(forW) {
	    MC_ICVarMinusMuonAcc_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	    MC_ICVarMinusMuonAcc_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	    MC_ICVarMinusMuonAcc_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	  }
	}
      }
    }

    MC_JetMHT->Fill(jJetSum.Pt(), ev.GetEventWeight());
    MC_JetMHT2->Fill(jJetSum2.Pt(), ev.GetEventWeight());

    MC_VirtualWMass->Fill(jGenW.M(), ev.GetEventWeight());
    MC_MHTGenJetsWPtDiff->Fill((jJetSum.Pt() - jGenW.Pt())/jGenW.Pt(), ev.GetEventWeight());
    MC_MHT2GenJetsWPtDiff->Fill((jJetSum2.Pt() - jGenW.Pt())/jGenW.Pt(), ev.GetEventWeight());

    //to see the effects of the W left handedness, plot the muon and neutrino spectra for two different muon pt cuts
    //point is that mu- is opposite to W-, so a cut on low pt mu- effects high pt neutrino, hence MET, spectra...
    //to pass the MCWMuon Cut, there must be a muon neutrino in this event...
    if(fabs(genLepton->Eta()) < 2.1) {
      if(genLepton->Pt() > 10.0) {
	  MC_MuonPtCut1->Fill(genLepton->Pt(), ev.GetEventWeight());
	  MC_MuonEtaCut1->Fill(fabs(genLepton->Eta()), ev.GetEventWeight());
	  if(forW) {
	    MC_MuonNuPtCut1->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	    MC_MuonNuEtaCut1->Fill(fabs(genLeptonNu->Eta()), ev.GetEventWeight());
	  }
	  if(theVBosons.at(0)->GetID() > 0) {
	    if(forW) MC_MuonNuPtCut1Plus->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut1Plus->Fill(genLepton->Pt(), ev.GetEventWeight());
	  }else{
	    if(forW) MC_MuonNuPtCut1Minus->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut1Minus->Fill(genLepton->Pt(), ev.GetEventWeight());
	  }
      }
      if(genLepton->Pt() > 20.0) {
	  MC_MuonPtCut2->Fill(genLepton->Pt(), ev.GetEventWeight());
	  MC_MuonEtaCut2->Fill(fabs(genLepton->Eta()), ev.GetEventWeight());
	  if(forW) {
	    MC_MuonNuPtCut2->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	    MC_MuonNuEtaCut2->Fill(fabs(genLeptonNu->Eta()), ev.GetEventWeight());
	  }
	  if(theVBosons.at(0)->GetID() > 0) {
	    if(forW) MC_MuonNuPtCut2Plus->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut2Plus->Fill(genLepton->Pt(), ev.GetEventWeight());
	    MC_WPTLepAcc2Plus->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
	  }else{
	    if(forW) MC_MuonNuPtCut2Minus->Fill(genLeptonNu->Pt(), ev.GetEventWeight());
	    MC_MuonPtCut2Minus->Fill(genLepton->Pt(), ev.GetEventWeight());
	    MC_WPTLepAcc2Minus->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
	  }
      }
    }

    //The above plots are a cheaty way to see how the different polarisation components change with respect to W eta and pt
    //They won't reveal anything useful if the underlying distribution is symmetric as it will change both by the same amount
    //The plots that follow show CosThetaStar1 Plus and Minus in bins of W eta, from 0.0 - 5.0 and above!
    //Eta was replaced with Rapidity as the W mass is not negligible!
    if( fabs(theVBosons.at(0)->Rapidity()) > 0.0 && fabs(theVBosons.at(0)->Rapidity()) <= 0.5 ) {
      jMCSolWEtaBin1 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin1.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin1Plus->Fill(jMCSolWEtaBin1.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin1Minus->Fill(jMCSolWEtaBin1.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 0.5 && fabs(theVBosons.at(0)->Rapidity()) <= 1.0 ) {
      jMCSolWEtaBin2 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin2.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin2Plus->Fill(jMCSolWEtaBin2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin2Minus->Fill(jMCSolWEtaBin2.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 1.0 && fabs(theVBosons.at(0)->Rapidity()) <= 1.5 ) {
      jMCSolWEtaBin3 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin3.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin3Plus->Fill(jMCSolWEtaBin3.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin3Minus->Fill(jMCSolWEtaBin3.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 1.5 && fabs(theVBosons.at(0)->Rapidity()) <= 2.0 ) {
      jMCSolWEtaBin4 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin4.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin4Plus->Fill(jMCSolWEtaBin4.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin4Minus->Fill(jMCSolWEtaBin4.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 2.0 && fabs(theVBosons.at(0)->Rapidity()) <= 2.5 ) {
      jMCSolWEtaBin5 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin5.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin5Plus->Fill(jMCSolWEtaBin5.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin5Minus->Fill(jMCSolWEtaBin5.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 2.5 && fabs(theVBosons.at(0)->Rapidity()) <= 3.0 ) {
      jMCSolWEtaBin6 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin6.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin6Plus->Fill(jMCSolWEtaBin6.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin6Minus->Fill(jMCSolWEtaBin6.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 3.0 && fabs(theVBosons.at(0)->Rapidity()) <= 3.5 ) {
      jMCSolWEtaBin7 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin7.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin7Plus->Fill(jMCSolWEtaBin7.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin7Minus->Fill(jMCSolWEtaBin7.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 3.5 && fabs(theVBosons.at(0)->Rapidity()) <= 4.0 ) {
      jMCSolWEtaBin8 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin8.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin8Plus->Fill(jMCSolWEtaBin8.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin8Minus->Fill(jMCSolWEtaBin8.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 4.0 && fabs(theVBosons.at(0)->Rapidity()) <= 4.5 ) {
      jMCSolWEtaBin9 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin9.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin9Plus->Fill(jMCSolWEtaBin9.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin9Minus->Fill(jMCSolWEtaBin9.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 4.5 && fabs(theVBosons.at(0)->Rapidity()) <= 5.0 ) {
      jMCSolWEtaBin10 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin10.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin10Plus->Fill(jMCSolWEtaBin10.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin10Minus->Fill(jMCSolWEtaBin10.rightSol, ev.GetEventWeight());
	}
      }
    }
    if( fabs(theVBosons.at(0)->Rapidity()) > 5.0 ) {
      jMCSolWEtaBin11 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWEtaBin11.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWEtaBin11Plus->Fill(jMCSolWEtaBin11.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWEtaBin11Minus->Fill(jMCSolWEtaBin11.rightSol, ev.GetEventWeight());
	}
      }
    }

    //now we do the same thing for bins of W_Pt
    if(theVBosons.at(0)->Pt() > 100 && theVBosons.at(0)->Pt() <= 200) {
      jMCSolWPtBin1 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin1.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin1Plus->Fill(jMCSolWPtBin1.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin1Minus->Fill(jMCSolWPtBin1.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 200 && theVBosons.at(0)->Pt() <= 300) {
      jMCSolWPtBin2 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin2.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin2Plus->Fill(jMCSolWPtBin2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin2Minus->Fill(jMCSolWPtBin2.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 300 && theVBosons.at(0)->Pt() <= 400) {
      jMCSolWPtBin3 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin3.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin3Plus->Fill(jMCSolWPtBin3.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin3Minus->Fill(jMCSolWPtBin3.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 400 && theVBosons.at(0)->Pt() <= 500) {
      jMCSolWPtBin4 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin4.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin4Plus->Fill(jMCSolWPtBin4.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin4Minus->Fill(jMCSolWPtBin4.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 500 && theVBosons.at(0)->Pt() <= 600) {
      jMCSolWPtBin5 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin5.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin5Plus->Fill(jMCSolWPtBin5.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin5Minus->Fill(jMCSolWPtBin5.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 600 && theVBosons.at(0)->Pt() <= 700) {
      jMCSolWPtBin6 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin6.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin6Plus->Fill(jMCSolWPtBin6.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin6Minus->Fill(jMCSolWPtBin6.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 700 && theVBosons.at(0)->Pt() <= 800) {
      jMCSolWPtBin7 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin7.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin7Plus->Fill(jMCSolWPtBin7.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin7Minus->Fill(jMCSolWPtBin7.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(theVBosons.at(0)->Pt() > 800 && theVBosons.at(0)->Pt() <= 900) {
      jMCSolWPtBin8 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWPtBin8.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWPtBin8Plus->Fill(jMCSolWPtBin8.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWPtBin8Minus->Fill(jMCSolWPtBin8.rightSol, ev.GetEventWeight());
	}
      }
    }

    //and finally in bins of jet multiplicity
    if(myGenMatrixBin.the_GenJets.size() == 0) {
      jMCSolWJetBin1 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin1.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin1Plus->Fill(jMCSolWJetBin1.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin1Minus->Fill(jMCSolWJetBin1.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 1) {
      jMCSolWJetBin2 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin2.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin2Plus->Fill(jMCSolWJetBin2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin2Minus->Fill(jMCSolWJetBin2.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 2) {
      jMCSolWJetBin3 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin3.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin3Plus->Fill(jMCSolWJetBin3.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin3Minus->Fill(jMCSolWJetBin3.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 3) {
      jMCSolWJetBin4 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin4.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin4Plus->Fill(jMCSolWJetBin4.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin4Minus->Fill(jMCSolWJetBin4.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 4) {
      jMCSolWJetBin5 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin5.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin5Plus->Fill(jMCSolWJetBin5.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin5Minus->Fill(jMCSolWJetBin5.rightSol, ev.GetEventWeight());
	}
      }
    }
    if(myGenMatrixBin.the_GenJets.size() == 5) {
      jMCSolWJetBin6 = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
      if(jMCSolWJetBin6.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1RightPzWJetBin6Plus->Fill(jMCSolWJetBin6.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1RightPzWJetBin6Minus->Fill(jMCSolWJetBin6.rightSol, ev.GetEventWeight());
	}
      }
    }


    //now play with different variables affecting measurement of cos(theta*) variable at gen level
    jMCSol = FindBoost(jGenLepton, jGenW.Px(), jGenW.Py(), jGenW.Pz());

    if(jMCSol.realSolutions) {
      //plot the VirtualW mass for real solutions to pz
      MC_VirtualWMassRe->Fill(jGenW.M(), ev.GetEventWeight());

      //remember that whilst the muon has a positive ID but negative charge, the W+ has ID +24
      if(theVBosons.at(0)->GetID() > 0) {
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
      jMCSolMHT2 = FindBoost(jGenLepton, jJetSum2.Px(), jJetSum2.Py(), jGenW.Pz());

      if(jMCSolMHT2.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMHT2Plus->Fill(jMCSolMHT2.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMHT2Plus->Fill(jMCSolMHT2.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1WrongPzMHT2Minus->Fill(jMCSolMHT2.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMHT2Minus->Fill(jMCSolMHT2.rightSol, ev.GetEventWeight());
	}
      }
    }

    //again, we emulate the RECO cuts, this time on the muon, to see the effects at gen level on the cos(theta*) dist
    if(jGenLepton.Pt() > 15.0 && fabs(jGenLepton.Eta()) < 2.1) {
      jMCSolMuon = FindBoost(jGenLepton,jGenW.Px(),jGenW.Py(),jGenW.Pz());

      if(jMCSolMuon.realSolutions) {
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMuonPlus->Fill(jMCSolMuon.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonPlus->Fill(jMCSolMuon.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1WrongPzMuonMinus->Fill(jMCSolMuon.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMinus->Fill(jMCSolMuon.rightSol, ev.GetEventWeight());
	}
      }
    }

    //now mix all the criteria together at generator level
    if(jGenLepton.Pt() > 15.0 && fabs(jGenLepton.Eta()) < 2.1 && jJetSum2.Pt() > 100.0) {
      jMCSolMuonMHT2 = FindBoost(jGenLepton, jJetSum2.Px(), jJetSum2.Py(), jGenW.Pz());

      if(jMCSolMuonMHT2.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
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
      //jMCSolMuonMHT2Reco = FindBoost(*(ev.LD_CommonMuons().accepted.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), jGenW.Pz());
      jMCSolMuonMHT2Reco = FindBoost(TLVConvert(ev.LD_CommonMuons().accepted.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), jGenW.Pz());

      if(jMCSolMuonMHT2Reco.realSolutions){
	if(theVBosons.at(0)->GetID() > 0) {
	  MC_CosThetaStar1WrongPzMuonMHT2RecoPlus->Fill(jMCSolMuonMHT2Reco.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMHT2RecoPlus->Fill(jMCSolMuonMHT2Reco.rightSol, ev.GetEventWeight());
	}else{
	  MC_CosThetaStar1WrongPzMuonMHT2RecoMinus->Fill(jMCSolMuonMHT2Reco.wrongSol, ev.GetEventWeight());
	  MC_CosThetaStar1RightPzMuonMHT2RecoMinus->Fill(jMCSolMuonMHT2Reco.rightSol, ev.GetEventWeight());
	}
      }
    }

    if(forW) {
      double MCRECO_PFMHT=0.0;
      double DeltaR_MCRECO_Muon=0.0;
      if(myGenMatrixBin.the_GenMuonExtra.size()) {
	if(ev.LD_Muons().size()) {
	  for (std::vector<Event::Lepton>::const_iterator imu = ev.LD_Muons().begin();  imu != ev.LD_Muons().end();++imu) {
	    //DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*imu,*(genLepton));
	    DeltaR_MCRECO_Muon = ROOT::Math::VectorUtil::DeltaR(*imu,*(myGenMatrixBin.the_GenMuonExtra.at(0)));
	    if(DeltaR_MCRECO_Muon < 0.1) {
	      MCRECO_PFMHT = (ev.PFMET() + *imu).Pt();	    
	      break;
	    }
	  }
	  if(MCRECO_PFMHT) MCRECO_PFMHTWPtDiff->Fill((theVBosons.at(0)->Pt() - MCRECO_PFMHT) / theVBosons.at(0)->Pt());
	  else MCRECO_PFMHTWPtDiff->Fill((theVBosons.at(0)->Pt() - ev.PFMET().Pt()) / theVBosons.at(0)->Pt());
	} else MCRECO_PFMHTWPtDiff->Fill((theVBosons.at(0)->Pt() - ev.PFMET().Pt()) / theVBosons.at(0)->Pt());
      }
    }
    
    MC_WMultiplicity->Fill(theVBosons.size(), ev.GetEventWeight());
    MC_WPT->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
    MC_WEta->Fill(theVBosons.at(0)->Eta(), ev.GetEventWeight());
    MC_WY->Fill(theVBosons.at(0)->Rapidity(), ev.GetEventWeight());
    MC_WPtY->Fill(theVBosons.at(0)->Pt(), fabs(theVBosons.at(0)->Rapidity()), ev.GetEventWeight());
    MC_WYvsMuEta->Fill(theVBosons.at(0)->Rapidity(), genLepton->Eta(), ev.GetEventWeight());
    if(fabs(genLepton->Eta()) < 2.1) MC_WYMuAcc->Fill(theVBosons.at(0)->Rapidity(), ev.GetEventWeight());
    if(theVBosons.at(0)->GetID() > 0) {
      MC_WPtPlus->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
      //cout << "W after boost: " << theVBosons.at(0)->Px() << ", " << theVBosons.at(0)->Py() << ", " << theVBosons.at(0)->Pz() << endl;
      //cout << "W theta in plottingop: " << theVBosons.at(0)->Theta() << endl << endl;
      MC_WEtaPlus->Fill(fabs(theVBosons.at(0)->Eta()), ev.GetEventWeight());
      MC_WYPlus->Fill(fabs(theVBosons.at(0)->Rapidity()), ev.GetEventWeight());
      MC_WPtPzPlus->Fill(fabs(theVBosons.at(0)->Pz() / theVBosons.at(0)->Pt()), theVBosons.at(0)->Pt(), ev.GetEventWeight());
      MC_WMuPtPzPlus->Fill(genLepton->Pz() / theVBosons.at(0)->Pz(),genLepton->Pt() / theVBosons.at(0)->Pt(), ev.GetEventWeight());
      MC_WPT_vs_LepPTPlus->Fill(theVBosons.at(0)->Pt(), genLepton->Pt(), ev.GetEventWeight());
      MC_WPT_vs_LepEtaPlus->Fill(theVBosons.at(0)->Pt(), fabs(genLepton->Eta()), ev.GetEventWeight());
    }else{
      MC_WPtMinus->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
      MC_WEtaMinus->Fill(fabs(theVBosons.at(0)->Eta()), ev.GetEventWeight());
      MC_WYMinus->Fill(fabs(theVBosons.at(0)->Rapidity()), ev.GetEventWeight());
      MC_WPtPzMinus->Fill(fabs(theVBosons.at(0)->Pz() / theVBosons.at(0)->Pt()), theVBosons.at(0)->Pt(), ev.GetEventWeight());
      MC_WMuPtPzMinus->Fill(genLepton->Pz() / theVBosons.at(0)->Pz(),genLepton->Pt() / theVBosons.at(0)->Pt(), ev.GetEventWeight());
      MC_WPT_vs_LepPTMinus->Fill(theVBosons.at(0)->Pt(), genLepton->Pt(), ev.GetEventWeight());
      MC_WPT_vs_LepEtaMinus->Fill(theVBosons.at(0)->Pt(), fabs(genLepton->Eta()), ev.GetEventWeight());
    }
    MC_MHTAllGenJetsWPtDiff->Fill((jJetSum.Pt() - theVBosons.at(0)->Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());

    //MC_FinalBoostDir->Fill(myGenMatrixBin.finalBoostDir, ev.GetEventWeight());
    //MC_InitialBoostDir->Fill(myGenMatrixBin.initialBoostDir, ev.GetEventWeight());

    if (forZ && genLepton->GetID() < 0)  { // Mu Pt Scale corrected
      TLorentzVector genLeptonCorr = MuPtScaleCorr(+1,TLVConvert(genLepton),1);
      TLorentzVector jGenWCorr =  MuPtScaleCorr(+1,TLVConvert(genLepton),1) +  MuPtScaleCorr(-1,TLVConvert(genLepton2),1);
      jMCSolWCorr = FindBoost(genLeptonCorr, jGenWCorr.Px(), jGenWCorr.Py(), jGenWCorr.Pz(), true, false, jGenWCorr.M());
      if(jMCSolWCorr.realSolutions) {
	int index = int( (jMCSolWCorr.rightSol + 1.0) / 0.01 );
	MC_CosThetaStar1CorrPlus->Fill(jMCSolWCorr.rightSol, ev.GetEventWeight());

	MC_CosThetaStar1CorrPlus_LH->Fill(jMCSolWCorr.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	MC_CosThetaStar1CorrPlus_RH->Fill(jMCSolWCorr.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	MC_CosThetaStar1CorrPlus_LO->Fill(jMCSolWCorr.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2)* CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
      }
    }



    return true;
  }

  std::ostream& MCWPlots::Description(std::ostream &ostrm) {
    ostrm << "Generator W boson plots";
    return ostrm;
  }

 
} // ~namespace Operation
