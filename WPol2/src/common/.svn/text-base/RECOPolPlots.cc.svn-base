#include "RECOPolPlots.hh"
//originally written by Jad Marrouche, September 2009 onwards
namespace Operation {

  //====================================
  // RECOPolPlots implementation
  //====================================


  RECOPolPlots::RECOPolPlots(const std::string & folderName, const std::string & VBoson, bool Gen, const unsigned int & phase_space) :
    mFolderName(folderName),
    mVBoson(VBoson),
    doGenMaster(Gen),
    mPhaseSpace(phase_space) {}

  RECOPolPlots::~RECOPolPlots() {}

  void RECOPolPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void RECOPolPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    RECO_CommonMHTPlus = new TH1F("RECO_CommonMHTPlus",";Common MHT with mu^{+};Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_CommonMHTMinus = new TH1F("RECO_CommonMHTMinus",";Common MHT with mu^{-};Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_ICVarPlus = new TH1F("RECO_ICVarPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarMinus = new TH1F("RECO_ICVarMinus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarMinus_LH = new TH1F("RECO_ICVarMinus_LH",";IC Variable #mu^{-} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPlus_LH = new TH1F("RECO_ICVarPlus_LH",";IC Variable #mu^{+} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarMinus_RH = new TH1F("RECO_ICVarMinus_RH",";IC Variable #mu^{-} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPlus_RH = new TH1F("RECO_ICVarPlus_RH",";IC Variable #mu^{+} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarMinus_LO = new TH1F("RECO_ICVarMinus_LO",";IC Variable #mu^{-} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPlus_LO = new TH1F("RECO_ICVarPlus_LO",";IC Variable #mu^{+} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarTCPlus = new TH1F("RECO_ICVarTCPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarTCMinus = new TH1F("RECO_ICVarTCMinus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus = new TH1F("RECO_ICVarPFPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_vw = new TH1F("RECO_ICVarPFPlus_vw",";IC Variable #mu^{+} vw;Events",500,-2.5,2.5);
    RECO_ICVarPFPlus_LH = new TH1F("RECO_ICVarPFPlus_LH",";IC Variable PF #mu^{+} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LH_vw = new TH1F("RECO_ICVarPFPlus_LH_vw",";IC Variable PF #mu^{+} LH vw;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LH_GenMu = new TH1F("RECO_ICVarPFPlus_LH_GenMu",";IC Variable PF #mu^{+} LH from gen muon;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LH_GenTau = new TH1F("RECO_ICVarPFPlus_LH_GenTau",";IC Variable PF #mu^{+} LH from gen tau;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_RH = new TH1F("RECO_ICVarPFPlus_RH",";IC Variable PF #mu^{+} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_RH_vw = new TH1F("RECO_ICVarPFPlus_RH_vw",";IC Variable PF #mu^{+} RH vw;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_RH_GenMu = new TH1F("RECO_ICVarPFPlus_RH_GenMu",";IC Variable PF #mu^{+} RH from gen muon;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_RH_GenTau = new TH1F("RECO_ICVarPFPlus_RH_GenTau",";IC Variable PF #mu^{+} RH from gen tau;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LO = new TH1F("RECO_ICVarPFPlus_LO",";IC Variable PF #mu^{+} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LO_vw = new TH1F("RECO_ICVarPFPlus_LO_vw",";IC Variable PF #mu^{+} LO vw;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LO_GenMu = new TH1F("RECO_ICVarPFPlus_LO_GenMu",";IC Variable PF #mu^{+} LO from gen muon;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LO_GenTau = new TH1F("RECO_ICVarPFPlus_LO_GenTau",";IC Variable PF #mu^{+} LO from gen tau;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_A0p10pc = new TH1F("RECO_ICVarPFPlus_A0p10pc",";IC Variable PF #mu^{+} A0+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_A1p10pc = new TH1F("RECO_ICVarPFPlus_A1p10pc",";IC Variable PF #mu^{+} A1+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_A2p10pc = new TH1F("RECO_ICVarPFPlus_A2p10pc",";IC Variable PF #mu^{+} A2+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_A3p10pc = new TH1F("RECO_ICVarPFPlus_A3p10pc",";IC Variable PF #mu^{+} A3+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_A4p10pc = new TH1F("RECO_ICVarPFPlus_A4p10pc",";IC Variable PF #mu^{+} A4+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTWp1pc = new TH1F("RECO_ICVarPFPlus_PTWp1pc",";IC Variable PF #mu^{+} PT(W)+1percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTWp3pc = new TH1F("RECO_ICVarPFPlus_PTWp3pc",";IC Variable PF #mu^{+} PT(W)+3percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTWp5pc = new TH1F("RECO_ICVarPFPlus_PTWp5pc",";IC Variable PF #mu^{+} PT(W)+5percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTWm1pc = new TH1F("RECO_ICVarPFPlus_PTWm1pc",";IC Variable PF #mu^{+} PT(W)-1percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTWm3pc = new TH1F("RECO_ICVarPFPlus_PTWm3pc",";IC Variable PF #mu^{+} PT(W)-3percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTWm5pc = new TH1F("RECO_ICVarPFPlus_PTWm5pc",";IC Variable PF #mu^{+} PT(W)-5percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTMp1pc = new TH1F("RECO_ICVarPFPlus_PTMp1pc",";IC Variable PF #mu^{+} PT(mu) scale+1percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTMm1pc = new TH1F("RECO_ICVarPFPlus_PTMm1pc",";IC Variable PF #mu^{+} PT(mu) scale-1percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTMp3pc = new TH1F("RECO_ICVarPFPlus_PTMp3pc",";IC Variable PF #mu^{+} PT(mu) scale+3percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_PTMm3pc = new TH1F("RECO_ICVarPFPlus_PTMm3pc",";IC Variable PF #mu^{+} PT(mu) scale-3percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_MuonEtaPlus_A0p10pc = new TH1F("RECO_MuonEtaPlus_A0p10pc", ";#mu^+ |#eta| A0+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaPlus_A1p10pc = new TH1F("RECO_MuonEtaPlus_A1p10pc", ";#mu^+ |#eta| A1+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaPlus_A2p10pc = new TH1F("RECO_MuonEtaPlus_A2p10pc", ";#mu^+ |#eta| A2+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaPlus_A3p10pc = new TH1F("RECO_MuonEtaPlus_A3p10pc", ";#mu^+ |#eta| A3+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaPlus_A4p10pc = new TH1F("RECO_MuonEtaPlus_A4p10pc", ";#mu^+ |#eta| A4+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_ICVarPFMinus = new TH1F("RECO_ICVarPFMinus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_vw = new TH1F("RECO_ICVarPFMinus_vw",";IC Variable #mu^{-} vw;Events",500,-2.5,2.5);
    RECO_ICVarPFMinus_LH = new TH1F("RECO_ICVarPFMinus_LH",";IC Variable PF #mu^{-} LH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LH_vw = new TH1F("RECO_ICVarPFMinus_LH_vw",";IC Variable PF #mu^{-} LH vw;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LH_GenMu = new TH1F("RECO_ICVarPFMinus_LH_GenMu",";IC Variable PF #mu^{-} LH from gen muon;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LH_GenTau = new TH1F("RECO_ICVarPFMinus_LH_GenTau",";IC Variable PF #mu^{-} LH from gen tau;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_RH = new TH1F("RECO_ICVarPFMinus_RH",";IC Variable PF #mu^{-} RH;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_RH_vw = new TH1F("RECO_ICVarPFMinus_RH_vw",";IC Variable PF #mu^{-} RH vw;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_RH_GenMu = new TH1F("RECO_ICVarPFMinus_RH_GenMu",";IC Variable PF #mu^{-} RH from gen muon;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_RH_GenTau = new TH1F("RECO_ICVarPFMinus_RH_GenTau",";IC Variable PF #mu^{-} RH from gen tau;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LO = new TH1F("RECO_ICVarPFMinus_LO",";IC Variable PF #mu^{-} LO;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LO_vw = new TH1F("RECO_ICVarPFMinus_LO_vw",";IC Variable PF #mu^{-} LO vw;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LO_GenMu = new TH1F("RECO_ICVarPFMinus_LO_GenMu",";IC Variable PF #mu^{-} LO from gen muon;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LO_GenTau = new TH1F("RECO_ICVarPFMinus_LO_GenTau",";IC Variable PF #mu^{-} LO from gen tau;Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_A0p10pc = new TH1F("RECO_ICVarPFMinus_A0p10pc",";IC Variable PF #mu^{-} A0+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_A1p10pc = new TH1F("RECO_ICVarPFMinus_A1p10pc",";IC Variable PF #mu^{-} A1+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_A2p10pc = new TH1F("RECO_ICVarPFMinus_A2p10pc",";IC Variable PF #mu^{-} A2+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_A3p10pc = new TH1F("RECO_ICVarPFMinus_A3p10pc",";IC Variable PF #mu^{-} A3+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_A4p10pc = new TH1F("RECO_ICVarPFMinus_A4p10pc",";IC Variable PF #mu^{-} A4+10percent;Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTWp1pc = new TH1F("RECO_ICVarPFMinus_PTWp1pc",";IC Variable PF #mu^{-} PT(W)+1percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTWp3pc = new TH1F("RECO_ICVarPFMinus_PTWp3pc",";IC Variable PF #mu^{-} PT(W)+3percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTWp5pc = new TH1F("RECO_ICVarPFMinus_PTWp5pc",";IC Variable PF #mu^{-} PT(W)+5percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTWm1pc = new TH1F("RECO_ICVarPFMinus_PTWm1pc",";IC Variable PF #mu^{-} PT(W)-1percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTWm3pc = new TH1F("RECO_ICVarPFMinus_PTWm3pc",";IC Variable PF #mu^{-} PT(W)-3percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTWm5pc = new TH1F("RECO_ICVarPFMinus_PTWm5pc",";IC Variable PF #mu^{-} PT(W)-5percent;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTMp1pc = new TH1F("RECO_ICVarPFMinus_PTMp1pc",";IC Variable PF #mu^{-} PT(mu) scale+1percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTMm1pc = new TH1F("RECO_ICVarPFMinus_PTMm1pc",";IC Variable PF #mu^{-} PT(mu) scale-1percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTMp3pc = new TH1F("RECO_ICVarPFMinus_PTMp3pc",";IC Variable PF #mu^{-} PT(mu) scale+3percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_PTMm3pc = new TH1F("RECO_ICVarPFMinus_PTMm3pc",";IC Variable PF #mu^{-} PT(mu) scale-3percent at 100Gev;Events / 1pb^{-1}",500,-2.5,2.5);
    RECO_MuonEtaMinus_A0p10pc = new TH1F("RECO_MuonEtaMinus_A0p10pc", ";#mu^- |#eta| A0+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaMinus_A1p10pc = new TH1F("RECO_MuonEtaMinus_A1p10pc", ";#mu^- |#eta| A1+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaMinus_A2p10pc = new TH1F("RECO_MuonEtaMinus_A2p10pc", ";#mu^- |#eta| A2+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaMinus_A3p10pc = new TH1F("RECO_MuonEtaMinus_A3p10pc", ";#mu^- |#eta| A3+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_MuonEtaMinus_A4p10pc = new TH1F("RECO_MuonEtaMinus_A4p10pc", ";#mu^- |#eta| A4+10percent;Events / 1 pb^{-1}", 250,0.0,2.5);
    RECO_ICVarAK5Plus = new TH1F("RECO_ICVarAK5Plus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarAK5Minus = new TH1F("RECO_ICVarAK5Minus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarIC5Plus = new TH1F("RECO_ICVarIC5Plus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarIC5Minus = new TH1F("RECO_ICVarIC5Minus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_caloMT = new TH1F("RECO_caloMT",";Transverse Mass [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMT = new TH1F("RECO_pfMT",";Transverse Mass [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMT_vw = new TH1F("RECO_pfMT_vw",";Transverse Mass [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMTPlus = new TH1F("RECO_pfMTPlus",";Transverse Mass W+ [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMTPlus_vw = new TH1F("RECO_pfMTPlus_vw",";Transverse Mass W+ [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMTPlus_PTMp1pc = new TH1F("RECO_pfMTPlus_PTMp1pc", ";Transverse Mass W+ scale+1percent at 100GeV; Events / 1pb^{-1}", 1000, -0.5, 999.5);
    RECO_pfMTPlus_PTMm1pc = new TH1F("RECO_pfMTPlus_PTMm1pc", ";Transverse Mass W+ scale-1percent at 100GeV; Events / 1pb^{-1}", 1000, -0.5, 999.5);
    RECO_pfMTMinus = new TH1F("RECO_pfMTMinus",";Transverse Mass W- [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMTMinus_vw = new TH1F("RECO_pfMTMinus_vw",";Transverse Mass W- [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMTMinus_PTMp1pc = new TH1F("RECO_pfMTMinus_PTMp1pc", ";Transverse Mass W- scale+1percent at 100GeV; Events / 1pb^{-1}", 1000, -0.5, 999.5);
    RECO_pfMTMinus_PTMm1pc = new TH1F("RECO_pfMTMinus_PTMm1pc", ";Transverse Mass W- scale-1percent at 100GeV; Events / 1pb^{-1}", 1000, -0.5, 999.5);
    RECO_pfMHT = new TH1F("RECO_pfMHT",";pfMHT [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMHT_vw = new TH1F("RECO_pfMHT_vw",";pfMHT [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMHTPlus = new TH1F("RECO_pfMHTPlus",";pfMHT W+ [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMHTPlus_vw = new TH1F("RECO_pfMHTPlus_vw",";pfMHT W+ [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMHTMinus = new TH1F("RECO_pfMHTMinus",";pfMHT W- [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMHTMinus_vw = new TH1F("RECO_pfMHTMinus_vw",";pfMHT W- [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_CommonMHT = new TH1F("RECO_CommonMHT",";Common MHT;Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_pfMET = new TH1F("RECO_pfMET",";pfMET [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMET_vw = new TH1F("RECO_pfMET_vw",";pfMET [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMETPlus = new TH1F("RECO_pfMETPlus",";pfMET W+ [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMETPlus_vw = new TH1F("RECO_pfMETPlus_vw",";pfMET W+ [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_pfMETMinus = new TH1F("RECO_pfMETMinus",";pfMET W- [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_pfMETMinus_vw = new TH1F("RECO_pfMETMinus_vw",";pfMET W- [GeV] vw;Events;",1000,-0.5,999.5);
    RECO_MuonPt = new TH1F("RECO_MuonPt", ";#mu P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPt_vw = new TH1F("RECO_MuonPt_vw", ";#mu P_{T} vw;Events", 1000,-0.5,999.5);
    RECO_MuonPhi = new TH1F("RECO_MuonPhi", ";#phi(#mu);Events / 100 pb^{-1}", 1000,-5.005,4.995);
    RECO_MuonPhiPlus = new TH1F("RECO_MuonPhiPlus", ";#phi(#mu^{+});Events / 100 pb^{-1}", 1000,-5.005,4.995);
    RECO_MuonPhiMinus = new TH1F("RECO_MuonPhiMinus", ";#phi(#mu^{-});Events / 100 pb^{-1}", 1000,-5.005,4.995);
    RECO_MuonEta = new TH1F("RECO_MuonEta", ";#mu |#eta|;Events / 100 pb^{-1}", 250,0.0,2.5);
    RECO_MuonPtPlus = new TH1F("RECO_MuonPtPlus", ";#mu^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPtPlus_vw = new TH1F("RECO_MuonPtPlus_vw", ";#mu^{+} P_{T} vw;Events", 1000,-0.5,999.5);
    RECO_MuonPtPlus_PTMp1pc = new TH1F("RECO_MuonPtPlus_PTMp1pc", ";#mu^{+} P_{T} scale+1percent at 100GeV;Events / 1 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPtPlus_PTMm1pc = new TH1F("RECO_MuonPtPlus_PTMm1pc", ";#mu^{+} P_{T} scale-1percent at 100GeV;Events / 1 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPtMinus = new TH1F("RECO_MuonPtMinus", ";#mu^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPtMinus_vw = new TH1F("RECO_MuonPtMinus_vw", ";#mu^{-} P_{T} vw;Events", 1000,-0.5,999.5);
    RECO_MuonPtMinus_PTMp1pc = new TH1F("RECO_MuonPtMinus_PTMp1pc", ";#mu^{-} P_{T} scale+1percent at 100GeV;Events / 1 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonPtMinus_PTMm1pc = new TH1F("RECO_MuonPtMinus_PTMm1pc", ";#mu^{-} P_{T} scale-1percent at 100GeV;Events / 1 pb^{-1}", 1000,-0.5,999.5);
    RECO_MuonEtaPlus =  new TH1F("RECO_MuonEtaPlus",";#mu^{+} #eta;Events / 100 pb^{-1}",100, -5.5, 4.5);
    RECO_MuonEtaMinus =  new TH1F("RECO_MuonEtaMinus",";#mu^{-} #eta;Events / 100 pb^{-1}",100, -5.5, 4.5);
    RECO_MuonEtaPlusAbs =  new TH1F("RECO_MuonEtaPlusAbs",";#mu^{+} |#eta|;Events / 100 pb^{-1}",250, 0.0, 2.5);
    RECO_MuonEtaMinusAbs =  new TH1F("RECO_MuonEtaMinusAbs",";#mu^{-} |#eta|;Events / 100 pb^{-1}",250, 0.0, 2.5);
    RECO_recobosonMT = new TH1F("RECO_recobosonMT",";M_T(Z) [GeV];Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_recobosonPT = new TH1F("RECO_recobosonPT",";P_{T}(Z) [GeV];Events / 100 pb^{-1}",1000,-0.5,999.5);
    RECO_recobosonPTvsMHTres = new TH1F("RECO_recobosonPTvsMHTres",";P_{T}(Z)-pfMHT / P_{T}(Z);",500,-4.5,5.5);

    MC_MuonMultiplicity = new TH1F("MC_MuonMultiplicity", ";genMuon Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_MuonPlusTauMultiplicity = new TH1F("MC_MuonPlusTauMultiplicity", ";gen(Muon+Tau) Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_MuonExtraMultiplicity = new TH1F("MC_MuonExtraMultiplicity", ";genMuonExtra Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    RECO_JetMultiplicity = new TH1F("RECO_JetMultiplicity",";Common Jet Multiplicity;Events / 100 pb^{-1}",20,-0.5,19.5);
    RECO_JetMultiplicity_vw = new TH1F("RECO_JetMultiplicity_vw",";Common Jet Multiplicity vw;Events",20,-0.5,19.5);
    RECO_MuonMultiplicity = new TH1F("RECO_MuonMultiplicity", ";RECO Muon Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_WPt = new TH1F("MC_WPt", ";gen W P_{T};Events / 100 pb^{-1}", 1000, -0.5, 999.5);
    MC_WYAbs = new TH1F("MC_WYAbs", ";gen W |Y|; Events / 100 pb^{-1}", 100, -0.025, 4.975);
    MC_CosThetaStar1Plus = new TH1F("MC_CosThetaStar1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus = new TH1F("MC_CosThetaStar1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_pthatdist = new TH1F("MC_pthatdist", ";pt_hat;Events / 1 pb^{-1}", 2500, -0.5, 2499.5);

    RECO_CosThetaStar1Sol1Plus = new TH1F("RECO_CosThetaStar1Sol1Plus", ";cos #theta^{*};Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_LH = new TH1F("RECO_CosThetaStar1Sol1Plus_LH", ";cos #theta^{*} LH;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_RH = new TH1F("RECO_CosThetaStar1Sol1Plus_RH", ";cos #theta^{*} RH;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_LO = new TH1F("RECO_CosThetaStar1Sol1Plus_LO", ";cos #theta^{*} LO;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Minus = new TH1F("RECO_CosThetaStar1Sol1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol2Plus = new TH1F("RECO_CosThetaStar1Sol2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol2Minus = new TH1F("RECO_CosThetaStar1Sol2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

    RECO_CosThetaStar1Sol1Plus_A0p10pc = new TH1F("RECO_CosThetaStar1Sol1Plus_A0p10pc",";cos #theta^{*} #mu^{+} A0+10percent;Events / 100 pb^{-1}",300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_A1p10pc = new TH1F("RECO_CosThetaStar1Sol1Plus_A1p10pc",";cos #theta^{*} #mu^{+} A1+10percent;Events / 100 pb^{-1}",300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_A2p10pc = new TH1F("RECO_CosThetaStar1Sol1Plus_A2p10pc",";cos #theta^{*} #mu^{+} A2+10percent;Events / 100 pb^{-1}",300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_A3p10pc = new TH1F("RECO_CosThetaStar1Sol1Plus_A3p10pc",";cos #theta^{*} #mu^{+} A3+10percent;Events / 100 pb^{-1}",300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Plus_A4p10pc = new TH1F("RECO_CosThetaStar1Sol1Plus_A4p10pc",";cos #theta^{*} #mu^{+} A4+10percent;Events / 100 pb^{-1}",300,-1.5,1.5);

    MC_RECO_MuonMultMatch = new TH1F("MC_RECO_MuonMultMatch",";#mu (MC, RECO) multiplicity match false/true;Events / 100 pb^{-1}",2,-0.5,1.5);
    MC_RECO_MHTDiff = new TH1F("MC_RECO_MHTDiff",";#Delta (MC, RECO)/MC MHT;Events / 100 pb^{-1}", 1000, -50.5, 49.5);
    MC_RECO_TCMETDiff = new TH1F("MC_RECO_TCMETDiff",";#Delta (MC, RECO)/MC TCMET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_PFMETDiff = new TH1F("MC_RECO_PFMETDiff",";#Delta (MC, RECO)/MC PFMET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_CaloMETDiff = new TH1F("MC_RECO_CaloMETDiff",";#Delta (MC, RECO)/MC CaloMET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_IC5METDiff = new TH1F("MC_RECO_IC5METDiff",";#Delta (MC, RECO)/MC IC5MET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_AK5METDiff = new TH1F("MC_RECO_AK5METDiff",";#Delta (MC, RECO)/MC AK5MET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_genMHTDiff = new TH1F("MC_RECO_genMHTDiff",";#Delta (MC, RECO)/MC genMHT;Events",1000,-5.005,4.995);

    MC_RECO_MuonPtDiff = new TH1F("MC_RECO_MuonPtDiff",";#Delta (MC, RECO)/MC #muon P_{T};Events / 100 pb^{-1}", 2000, -1000.5, 999.5);
    MC_RECO_MuonEtaDiff = new TH1F("MC_RECO_MuonEtaDiff",";#Delta (MC, RECO) #muon #eta;Events / 100 pb^{-1}", 200, -10.5, 9.5);
    MC_RECO_MuonChargeId = new TH1F("MC_RECO_MuonChargeId",";#mu charge id wrong/right;Events / 100 pb^{-1}",2,-0.5,1.5);

    RECO_Tr = new TH1F("MC_RECO_TrIsoRel",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Ecal = new TH1F("MC_RECO_Ecal",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Hcal = new TH1F("MC_RECO_Hcal",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Com = new TH1F("MC_RECO_Com",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_DR = new TH1F("MC_RECO_DR",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Type = new TH1F("MC_RECO_Type",";#mu charge id wrong/right;Events / 100 pb^{-1}",10,-0.5,9.5);
    RECO_2ndMassZ = new TH1F("RECO_2ndMassZ",";M_{#mu#mu} Z;",2500,-0.5,249.5);
    RECO_2ndMassJPsi = new TH1F("RECO_2ndMassJPsi",";M_{#mu#mu} JPsi;",1000,0.0,5.0);
    RECO_CommMuCommMuMass = new TH1F("RECO_CommMuCommMuMass",";Common M_{#mu#mu};",2500,-0.5,249.5);
    
    RECO_NumVerticesPerEvent = new TH1F("RECO_NumVerticesPerEvent",";NumVerticesPerEvent;Events / 1 pb^{-1};",25, -0.5, 24.5);
    RECO_NumVerticesPerEvent_vw = new TH1F("RECO_NumVerticesPerEvent_vw",";NumVerticesPerEvent vw;Events;",25, -0.5, 24.5);
    RECO_HLTMutriggerbits = new TH1F("RECO_HLTMutriggerbits",";Trigger Bit;",3,0.5,3.5);
    RECO_1v_MuonPt = new TH1F("RECO_1v_MuonPt", ";#mu P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_1v_MuonPtPlus = new TH1F("RECO_1v_MuonPtPlus", ";#mu^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_1v_MuonPtMinus = new TH1F("RECO_1v_MuonPtMinus", ";#mu^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_1v_MuonPhi = new TH1F("RECO_1v_MuonPhi", ";#phi(#mu);Events / 100 pb^{-1}", 1000,-5.005,4.995);
    RECO_1v_MuonEta = new TH1F("RECO_1v_MuonEta", ";|#eta(#mu)|;Events / 100 pb^{-1}", 250,0.0,2.5);
    RECO_1v_pfMT = new TH1F("RECO_1v_pfMT",";Transverse Mass [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMTPlus = new TH1F("RECO_1v_pfMTPlus",";Transverse Mass Plus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMTMinus = new TH1F("RECO_1v_pfMTMinus",";Transverse Mass Minus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMHT = new TH1F("RECO_1v_pfMHT",";pfMHT [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMHTPlus = new TH1F("RECO_1v_pfMHTPlus",";pfMHTPlus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMHTMinus = new TH1F("RECO_1v_pfMHTMinus",";pfMHTMinus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMET = new TH1F("RECO_1v_pfMET",";pfMET [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMETPlus = new TH1F("RECO_1v_pfMETPlus",";pfMETPlus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_pfMETMinus = new TH1F("RECO_1v_pfMETMinus",";pfMETMinus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_1v_ICVarPFMinus = new TH1F("RECO_1v_ICVarPFMinus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_1v_ICVarPFPlus = new TH1F("RECO_1v_ICVarPFPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_gt1v_MuonPt = new TH1F("RECO_gt1v_MuonPt", ";#mu P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_gt1v_MuonPtPlus = new TH1F("RECO_gt1v_MuonPtPlus", ";#mu^{+} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_gt1v_MuonPtMinus = new TH1F("RECO_gt1v_MuonPtMinus", ";#mu^{-} P_{T};Events / 100 pb^{-1}", 1000,-0.5,999.5);
    RECO_gt1v_MuonPhi = new TH1F("RECO_gt1v_MuonPhi", ";#phi(#mu);Events / 100 pb^{-1}", 1000,-5.005,4.995);
    RECO_gt1v_MuonEta = new TH1F("RECO_gt1v_MuonEta", ";|#eta(#mu)|;Events / 100 pb^{-1}", 250,0.0,2.5);
    RECO_gt1v_pfMT = new TH1F("RECO_gt1v_pfMT",";Transverse Mass [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMTPlus = new TH1F("RECO_gt1v_pfMTPlus",";Transverse Mass Plus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMTMinus = new TH1F("RECO_gt1v_pfMTMinus",";Transverse Mass Minus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMHT = new TH1F("RECO_gt1v_pfMHT",";pfMHT [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMHTPlus = new TH1F("RECO_gt1v_pfMHTPlus",";pfMHTPlus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMHTMinus = new TH1F("RECO_gt1v_pfMHTMinus",";pfMHTMinus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMET = new TH1F("RECO_gt1v_pfMET",";pfMET [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMETPlus = new TH1F("RECO_gt1v_pfMETPlus",";pfMETPlus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_pfMETMinus = new TH1F("RECO_gt1v_pfMETMinus",";pfMETMinus [GeV];Events / 100 pb^{-1});",1000,-0.5,999.5);
    RECO_gt1v_ICVarPFMinus = new TH1F("RECO_gt1v_ICVarPFMinus",";IC Variable #mu^{-};Events / 100 pb^{-1}",500,-2.5,2.5);
    RECO_gt1v_ICVarPFPlus = new TH1F("RECO_gt1v_ICVarPFPlus",";IC Variable #mu^{+};Events / 100 pb^{-1}",500,-2.5,2.5);

    RECO_MHTvsTCMET = new TH2F("RECO_MHTvsTCMET",";MHT; TCMET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsCaloMET = new TH2F("RECO_MHTvsCaloMET",";MHT; CaloMET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsPFMET = new TH2F("RECO_MHTvsPFMET",";MHT; PFMET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsIC5MET = new TH2F("RECO_MHTvsIC5MET",";MHT; IC5MET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsAK5MET = new TH2F("RECO_MHTvsAK5MET",";MHT; AK5MET",1000,-0.5,999.5,1000,-0.5,999.5);
    MC_RECO_PFMETres_vs_genMHT = new TH2F("MC_RECO_PFMETres_vs_genMHT",";genMHT; genMHTres",100,0.0,1000.0,100,-5.05,4.95);
    MC_WPtY = new TH2F("MC_WPtY",";W P_{T}; W |Y|",1000,-0.5,999.5,  50,-0.05,4.95);
    RECO_pfMTvspfLP = new TH2F("RECO_pfMTvspfLP",";pfMT;LP",1000,-0.5,999.5,1000,-5.0,5.0);
    RECO_pfMHTvspfLP = new TH2F("RECO_pfMHTvspfLP",";pfMHT;LP",1000,-0.5,999.5,1000,-5.0,5.0);
    RECO_pfMHTvspfMT = new TH2F("RECO_pfMHTvspfMT",";pfMHT;pfMT",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_pfMHTvsMuPt = new TH2F("RECO_pfMHTvsMuPt","RECO_pfMHTvsMuPt;pfMHT;P_{T}(muon)",1000,-0.5,499.5, 1000, -0.5, 499.5);
    RECO_recobosonMvsLP = new TH2F("RECO_recobosonMvsLP",";recoboson M;LP",600,59.5,119.5,500,-2.5,2.5);
   
    RECO_recobosonLPvspfLP = new TH2F("RECO_recobosonLPvspfLP",";recoboson LP;pfLP",100,-2.5,2.5,100,-2.5,2.5);
    RECO_recobosonPTvspfMHT = new TH2F("RECO_recobosonPTvspfMHT",";recoboson PT;pfMHT",100,-0.5,499.5,100,-0.5,499.5);
    RECO_PTmuplusvsMT = new TH2F("RECO_PTmuplusvsMT",";Muon Pt Plus; W Transverse Mass",500,-0.5,499.5,200,-0.5,199.5);
    RECO_PTmuminusvsMT = new TH2F("RECO_PTmuminusvsMT",";Muon Pt Minus; W Transverse Mass",500,-0.5,499.5,200,-0.5,199.5);
  
    RECO_MpPTvsLP = new TH2F("RECO_MpPTvsLP","; #mu^{+}PT; reco LP",500,0,400,100,-2.5,2.5);

    MC_RECO_MHTDiffProfile = new TProfile("MC_RECO_MHTDiffProfile",";gen W P_{T};#Delta (MC, RECO)/MC MHT",1000,-0.5,999.5,-20.5,19.5,"");
    RECO_recobosonMvsLP_Profile = new TProfile("RECO_recobosonMvsLP_Profile",";LP;recoboson M",50,-2.5,2.5,59.5,119.5,"");
    RECO_PTmuplusvsMT_Profile = new TProfile("RECO_PTmuplusvsMT_Profile",";P_{T}(mu^{+});M_{T}(W^{+})",500,-0.5,499.5,59.5,119.5,"");
    RECO_PTmuminusvsMT_Profile = new TProfile("RECO_PTmuminusvsMT_Profile",";P_{T}(mu^{-});M_{T}(W^{-})",500,-0.5,499.5,59.5,119.5,"");

    RECO_CosThetaStar1Sol1CorrPlus = new TH1F("RECO_CosThetaStar1Sol1CorrPlus", ";cos #theta^{*};Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1CorrPlus_LH = new TH1F("RECO_CosThetaStar1Sol1CorrPlus_LH", ";cos #theta^{*} LH;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1CorrPlus_RH = new TH1F("RECO_CosThetaStar1Sol1CorrPlus_RH", ";cos #theta^{*} RH;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1CorrPlus_LO = new TH1F("RECO_CosThetaStar1Sol1CorrPlus_LO", ";cos #theta^{*} LO;Events / 100 pb^{-1}", 300,-1.5,1.5);
    
TH1::SetDefaultSumw2(kFALSE);
  }

  bool RECOPolPlots::Process(Event::Data & ev) {

    if(TString(mVBoson)=="W") {forW = true;forZ = false;}
    if(TString(mVBoson)=="Z") {forW = false;forZ = true;}
    if(TString(mVBoson)!="Z" && TString(mVBoson)!="W") cout << "RECOPolPlots: Error invalid Vector Boson choice!" << endl;
    
    bool doGen = doGenMaster; //do this to initialise the doGen variable

    // ******** SOME DEFINITIONS START ********

    //initialise genmatrixbin using the default constructor - do this so we can use with real data ntuples (i.e. no gen info) without breaking anything
    GenMatrixBin myGenMatrixBin;

    if(doGen) {
      myGenMatrixBin = GenMatrixBin(&ev);
      if((myGenMatrixBin.the_GenMuon.size()==0 && myGenMatrixBin.the_GenTau.size()==0)) doGen=false;
    }

    std::vector <Event::GenObject const *> theVBosons;
    Event::GenObject const * theGenLepton;
    Event::Lepton const * theRECOLepton;
    Event::Lepton const * theRECOLepton2;
    TLorentzVector reco_muon;
    TLorentzVector reco_boson;

    //the WPtResCut is for comparing the different MET resolutions vs the genW
    double WPtResCut = 100.0;

    if(forW) {
      if(ev.LD_CommonMuons().accepted.size()!=1) return false;
      reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(0));
      theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
      if(doGen) {
	if(myGenMatrixBin.the_GenW.size()==0) return false; 
	theVBosons = myGenMatrixBin.the_GenW;
	//now check that either a gen muon or gen tau exists - since we ask for a muon in the reco cutflow, it can only come from either of these gen particles       
	//check that gen muon exists, or if it doesn't, a gen tau exists
	if(myGenMatrixBin.the_GenMuon.size() == 1 && myGenMatrixBin.the_GenTau.size() == 0) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
	else if(myGenMatrixBin.the_GenTau.size() == 1 && myGenMatrixBin.the_GenMuon.size() == 0) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
	else doGen=false; //cannot find the gen lepton (to match with reco one)	 
      }
    }
    if(forZ) {
      if(ev.LD_CommonMuons().accepted.size() != 2) return false;
      //make the choice of whether to use the positively of negatively charged muon from the Z-decay (templates only exist for positively charged lepton by our definition)
      if(ev.LD_CommonMuons().accepted.at(0)->GetCharge() > 0.0) {
	reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(0));
	theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
	theRECOLepton2 = ev.LD_CommonMuons().accepted.at(1);
      } else if(ev.LD_CommonMuons().accepted.at(1)->GetCharge() > 0.0) {
	reco_muon = TLVConvert(ev.LD_CommonMuons().accepted.at(1));
	theRECOLepton = ev.LD_CommonMuons().accepted.at(1);
	theRECOLepton2 = ev.LD_CommonMuons().accepted.at(0);
      } else return false; //i.e. they can't both have the same charge!
      
      reco_boson = TLVConvert(ev.LD_CommonMuons().accepted.at(0)) + TLVConvert(ev.LD_CommonMuons().accepted.at(1));

      if(doGen) {
	if(myGenMatrixBin.the_GenZ.size()==0) return false;
	theVBosons = myGenMatrixBin.the_GenZ;
	if(myGenMatrixBin.the_GenMuon.size() == 2 && myGenMatrixBin.the_GenTau.size() == 0) { //now check for positively charged lepton (i.e. anti particle and so ID < 0) by our convention
	  if(myGenMatrixBin.the_GenMuon.at(0)->GetID() < 0 ) theGenLepton = myGenMatrixBin.the_GenMuon.at(0); 
	  else theGenLepton = myGenMatrixBin.the_GenMuon.at(1);	  
	} else if(myGenMatrixBin.the_GenMuon.size() == 0 && myGenMatrixBin.the_GenTau.size() == 2) {
	   if(myGenMatrixBin.the_GenTau.at(0)->GetID() < 0 ) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
	   else theGenLepton = myGenMatrixBin.the_GenTau.at(1);
	} else doGen=false; //cannot find the gen lepton (to match with reco one)
      }
    }

    // ******** SOME DEFINITIONS END ********
    

    LorentzV tcMET, pfMET, ic5MET, ak5MET; 
    if(forW) {
      tcMET = ev.TCMET() + *(theRECOLepton);
      pfMET = ev.PFMET() + *(theRECOLepton);
      //ic5MET = ev.IC5MET() + *(theRECOLepton);
      ak5MET = ev.AK5MET() + *(theRECOLepton);
    }
    if(forZ) {
      tcMET = ev.TCMET() + *(theRECOLepton) + *(theRECOLepton2);
      pfMET = ev.PFMET() + *(theRECOLepton) + *(theRECOLepton2);
      //ic5MET = ev.IC5MET() + *(theRECOLepton) + *(theRECOLepton2);
      ak5MET = ev.AK5MET() + *(theRECOLepton) + *(theRECOLepton2);
    }
    
    //make the IC Variable at RECO level (use the mumu mass for the Z case)
    if(forW) ICVariable = ((theRECOLepton->Px() * ev.CommonMHT().Px()) + (theRECOLepton->Py() * ev.CommonMHT().Py())) / (ev.CommonMHT().Pt() * ev.CommonMHT().Pt());
    if(forZ) ICVariable = ((theRECOLepton->Px() * reco_boson.Px()) + (theRECOLepton->Py() * reco_boson.Py())) / (reco_boson.Pt() * reco_boson.Pt());

    double ICVariableTC = ((theRECOLepton->Px() * tcMET.Px()) + (theRECOLepton->Py() * tcMET.Py())) / (tcMET.Pt() * tcMET.Pt());
    double ICVariablePF = ((theRECOLepton->Px() * pfMET.Px()) + (theRECOLepton->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());
    double ICVariableIC5 = ((theRECOLepton->Px() * ic5MET.Px()) + (theRECOLepton->Py() * ic5MET.Py())) / (ic5MET.Pt() * ic5MET.Pt());
    double ICVariableAK5 = ((theRECOLepton->Px() * ak5MET.Px()) + (theRECOLepton->Py() * ak5MET.Py())) / (ak5MET.Pt() * ak5MET.Pt());

    //in order to test QCD reweighting code:
    if(ev.pthat.enabled()) MC_pthatdist->Fill(ev.pthat(), ev.GetEventWeight());

    //to use MT, don't call CommonMT() - which is whack. Do the following:
    double eMT=ev.MT(theRECOLepton,&(ev.CommonRecoilMET()));
    RECO_caloMT->Fill(eMT, ev.GetEventWeight());
    double pfMT = sqrt(2.0 * ev.PFMET().Pt() * ev.LD_CommonMuons().accepted.at(0)->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonMuons().accepted.at(0), ev.PFMET()))));
    RECO_pfMT->Fill(pfMT, ev.GetEventWeight());
    RECO_pfMT_vw->Fill(pfMT, ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
    RECO_pfMTvspfLP->Fill(pfMT, ICVariablePF, ev.GetEventWeight());
    RECO_pfMHTvspfLP->Fill(pfMET.Pt(), ICVariablePF, ev.GetEventWeight());
    RECO_pfMHTvspfMT->Fill(pfMET.Pt(), pfMT, ev.GetEventWeight());

    if(forZ) {
      double recobosonMT = sqrt(2.0 * ev.LD_CommonMuons().accepted.at(1)->Pt() * ev.LD_CommonMuons().accepted.at(0)->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*ev.LD_CommonMuons().accepted.at(0), *ev.LD_CommonMuons().accepted.at(1)))));
      RECO_CommMuCommMuMass->Fill(reco_boson.M(), ev.GetEventWeight());
      RECO_recobosonMT->Fill(recobosonMT, ev.GetEventWeight());
      RECO_recobosonPT->Fill(reco_boson.Pt(), ev.GetEventWeight());
      RECO_recobosonPTvspfMHT->Fill(reco_boson.Pt(), pfMET.Pt(), ev.GetEventWeight());
      RECO_recobosonLPvspfLP->Fill(ICVariable, ICVariablePF, ev.GetEventWeight());
      RECO_recobosonMvsLP->Fill(reco_boson.M(), ICVariable, ev.GetEventWeight());
      RECO_recobosonMvsLP_Profile->Fill(ICVariable, reco_boson.M(), ev.GetEventWeight());
      //the following variables below don't contain extra information, but we'd like to see them for sanity checks...
      RECO_MuonPtMinus->Fill(theRECOLepton2->Pt(), ev.GetEventWeight()); //since by definition we choose above that theRECOLepton is positively charged...
      double ICVariableMinus = ((theRECOLepton2->Px() * reco_boson.Px()) + (theRECOLepton2->Py() * reco_boson.Py())) / (reco_boson.Pt() * reco_boson.Pt());
      RECO_ICVarMinus->Fill(ICVariableMinus, ev.GetEventWeight());
      double ICVariablePFMinus = ((theRECOLepton2->Px() * pfMET.Px()) + (theRECOLepton2->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());
      RECO_ICVarPFMinus->Fill(ICVariablePFMinus, ev.GetEventWeight());
      //std::cout << "run number is: " << ev.RunNumber() << std::endl;
      RECO_recobosonPTvsMHTres->Fill((reco_boson.Pt()-pfMET.Pt())/reco_boson.Pt(), ev.GetEventWeight());
      //as a systematics test, we make the plot above of M(the invariant mass) vs LP. If there was a charge dependent bias, then M(LP) would not be flat
      //it looks like in the data it is flat, but in order to put one in by hand (e.g. 1-5% at 100GeV), we do PT(mu +/-)^{new} / PT(mu +/-)^{old} = ( 1.0 +/- PT(mu +/-)^{old}/100 GeV * 1%)
      //Then multiply the existing 4-vector by this factor and recalculate the invariant mass and LP

      RECO_MpPTvsLP->Fill(theRECOLepton->Pt(),ICVariable, ev.GetEventWeight());

    }

    RECO_NumVerticesPerEvent->Fill(ev.GetVertexSize(), ev.GetEventWeight());
    RECO_NumVerticesPerEvent_vw->Fill(ev.GetVertexSize(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
    if(ev.GetVertexSize() == 1) {
      RECO_1v_MuonPt->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      RECO_1v_MuonPhi->Fill(theRECOLepton->Phi(), ev.GetEventWeight());
      RECO_1v_MuonEta->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight());
      RECO_1v_pfMT->Fill(pfMT, ev.GetEventWeight());
      RECO_1v_pfMHT->Fill(pfMET.Pt(), ev.GetEventWeight());
      RECO_1v_pfMET->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
      if(theRECOLepton->GetCharge()>0.0) {
	RECO_1v_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight());
	RECO_1v_pfMTPlus->Fill(pfMT, ev.GetEventWeight());
	RECO_1v_pfMHTPlus->Fill(pfMET.Pt(), ev.GetEventWeight());
	RECO_1v_pfMETPlus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
	RECO_1v_MuonPtPlus->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      } else {
	RECO_1v_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight());
	RECO_1v_pfMTMinus->Fill(pfMT, ev.GetEventWeight());
	RECO_1v_pfMHTMinus->Fill(pfMET.Pt(), ev.GetEventWeight());
	RECO_1v_pfMETMinus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
	RECO_1v_MuonPtMinus->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      }
    } else {
      RECO_gt1v_MuonPt->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      RECO_gt1v_MuonPhi->Fill(theRECOLepton->Phi(), ev.GetEventWeight());
      RECO_gt1v_MuonEta->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight());
      RECO_gt1v_pfMT->Fill(pfMT, ev.GetEventWeight());
      RECO_gt1v_pfMHT->Fill(pfMET.Pt(), ev.GetEventWeight());
      RECO_gt1v_pfMET->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
      if(theRECOLepton->GetCharge()>0.0) {
	RECO_gt1v_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight());
	RECO_gt1v_pfMTPlus->Fill(pfMT, ev.GetEventWeight());
	RECO_gt1v_pfMHTPlus->Fill(pfMET.Pt(), ev.GetEventWeight());
	RECO_gt1v_pfMETPlus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
	RECO_gt1v_MuonPtPlus->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      } else {
	RECO_gt1v_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight());
	RECO_gt1v_pfMTMinus->Fill(pfMT, ev.GetEventWeight());
	RECO_gt1v_pfMHTMinus->Fill(pfMET.Pt(), ev.GetEventWeight());
	RECO_gt1v_pfMETMinus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
	RECO_gt1v_MuonPtMinus->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      }
    }

    if(doGen) {
      MC_WYAbs->Fill(fabs(theVBosons.at(0)->Rapidity()), ev.GetEventWeight());
      MC_WPt->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
      MC_WPtY->Fill(theVBosons.at(0)->Pt(), fabs(theVBosons.at(0)->Rapidity()), ev.GetEventWeight());
      MC_MuonMultiplicity->Fill(myGenMatrixBin.the_GenMuon.size(), ev.GetEventWeight()); 
      MC_MuonPlusTauMultiplicity->Fill((myGenMatrixBin.the_GenMuon.size() + myGenMatrixBin.the_GenTau.size()), ev.GetEventWeight());
      MC_MuonExtraMultiplicity->Fill(myGenMatrixBin.the_GenMuonExtra.size(), ev.GetEventWeight()); //also include taus decaying to muons (which may both be reconstructed)
    }

    //fill the Muon and MHT distributions according to charge
    if(theRECOLepton->GetCharge()>0.0) {
      RECO_MuonPtPlus->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      RECO_MuonPtPlus_vw->Fill(theRECOLepton->Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_MuonEtaPlus->Fill(theRECOLepton->Eta(), ev.GetEventWeight());
      RECO_MuonEtaPlusAbs->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight());
      RECO_pfMTPlus->Fill(pfMT, ev.GetEventWeight());
      RECO_pfMTPlus_vw->Fill(pfMT, ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_pfMHTPlus->Fill(pfMET.Pt(), ev.GetEventWeight());
      RECO_pfMHTPlus_vw->Fill(pfMET.Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_pfMETPlus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
      RECO_pfMETPlus_vw->Fill(ev.PFMET().Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_MuonPhiPlus->Fill(theRECOLepton->Phi(), ev.GetEventWeight());
      RECO_CommonMHTPlus->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
      RECO_ICVarPlus->Fill(ICVariable, ev.GetEventWeight());

      RECO_ICVarTCPlus->Fill(ICVariableTC, ev.GetEventWeight());
      RECO_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight());
      RECO_ICVarPFPlus_vw->Fill(ICVariablePF, ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_ICVarIC5Plus->Fill(ICVariableIC5, ev.GetEventWeight());
      RECO_ICVarAK5Plus->Fill(ICVariableAK5, ev.GetEventWeight());


      //In order to see effects of systematically scaling pfMHT AFTER event selection, write e.g.
      //= ((theRECOLepton->Px() * 1.01*pfMET.Px()) + (theRECOLepton->Py() * 1.01*pfMET.Py())) / (1.01*pfMET.Pt() * 1.01*pfMET.Pt());
      //which is equivalent to ICVariablePFp1pc = ICVariablePF/1.01 etc

      RECO_ICVarPFPlus_PTWp1pc->Fill(ICVariablePF/1.01, ev.GetEventWeight());
      RECO_ICVarPFPlus_PTWp3pc->Fill(ICVariablePF/1.03, ev.GetEventWeight());
      RECO_ICVarPFPlus_PTWp5pc->Fill(ICVariablePF/1.05, ev.GetEventWeight());
      RECO_ICVarPFPlus_PTWm1pc->Fill(ICVariablePF/0.99, ev.GetEventWeight());
      RECO_ICVarPFPlus_PTWm3pc->Fill(ICVariablePF/0.97, ev.GetEventWeight());
      RECO_ICVarPFPlus_PTWm5pc->Fill(ICVariablePF/0.95, ev.GetEventWeight());

      //In order to see effects of a muon scale uncertainty e.g. x% at 100GeV
      RECO_ICVarPFPlus_PTMp1pc->Fill(ICVariablePF * (1.0 + ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_ICVarPFPlus_PTMm1pc->Fill(ICVariablePF * (1.0 - ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_ICVarPFPlus_PTMp3pc->Fill(ICVariablePF * (1.0 + ((0.03 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_ICVarPFPlus_PTMm3pc->Fill(ICVariablePF * (1.0 - ((0.03 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());

      //See effect of muon scale uncertainty on the MT distribution
      RECO_pfMTPlus_PTMp1pc->Fill(pfMT * TMath::Sqrt(1.0 + ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_pfMTPlus_PTMm1pc->Fill(pfMT * TMath::Sqrt(1.0 - ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());

      //See effect of muon scale uncertainty on the muon PT distribution itself
      RECO_MuonPtPlus_PTMp1pc->Fill(theRECOLepton->Pt() * (1.0 + ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_MuonPtPlus_PTMm1pc->Fill(theRECOLepton->Pt() * (1.0 - ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());

      //profile plot of W transverse mass vs muon pt
      RECO_PTmuplusvsMT_Profile->Fill(theRECOLepton->Pt(), pfMT, ev.GetEventWeight());
      RECO_PTmuplusvsMT->Fill(theRECOLepton->Pt(), pfMT, ev.GetEventWeight());
      
      if(doGen) {
	if(theGenLepton->GetID() < 0) { //this check only really works for the W-boson - by definition the Z will pass this check
	  jSolutionsW jMCSolution;
	  jGenLep = TLVConvert(theGenLepton);
	  jMCSolution = FindBoost(jGenLep, theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), true, false, theVBosons.at(0)->M());
	  if(jMCSolution.realSolutions) {
	    int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	    MC_CosThetaStar1Plus->Fill(jMCSolution.rightSol, ev.GetEventWeight());
	    if(forW) {
	      RECO_ICVarPlus_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	      RECO_ICVarPlus_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	      RECO_ICVarPlus_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));


	      RECO_ICVarPFPlus_LH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	      RECO_ICVarPFPlus_RH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	      RECO_ICVarPFPlus_LO->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));

	      RECO_ICVarPFPlus_LH_vw->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace) * GetVertexReweighting(ev.GetVertexSize()));
	      RECO_ICVarPFPlus_RH_vw->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace) * GetVertexReweighting(ev.GetVertexSize()));
	      RECO_ICVarPFPlus_LO_vw->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace) * GetVertexReweighting(ev.GetVertexSize()));

	      if(fabs(theGenLepton->GetID()) == 13) { //i.e. the genlepton is a muon. we don't check the id of the tau for the else statement as we have already done that in filling theGenLepton above
		RECO_ICVarPFPlus_LH_GenMu->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
		RECO_ICVarPFPlus_RH_GenMu->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
		RECO_ICVarPFPlus_LO_GenMu->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	      } else {
		RECO_ICVarPFPlus_LH_GenTau->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
		RECO_ICVarPFPlus_RH_GenTau->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
		RECO_ICVarPFPlus_LO_GenTau->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	      }

	      TLorentzVector hframelepton = HTransform(TLVConvert(theGenLepton), TLVConvert(theVBosons.at(0)));
	      RECO_ICVarPFPlus_A0p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 0, 1.1, 1, true));
	      RECO_ICVarPFPlus_A1p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 1, 1.1, 1, true));
	      RECO_ICVarPFPlus_A2p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 2, 1.1, 1, true));
	      RECO_ICVarPFPlus_A3p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 3, 1.1, 1, true));
	      RECO_ICVarPFPlus_A4p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 4, 1.1, 1, true));
	      RECO_MuonEtaPlus_A0p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 0, 1.1, 1, true));
	      RECO_MuonEtaPlus_A1p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 1, 1.1, 1, true));
	      RECO_MuonEtaPlus_A2p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 2, 1.1, 1, true));
	      RECO_MuonEtaPlus_A3p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 3, 1.1, 1, true));
	      RECO_MuonEtaPlus_A4p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 4, 1.1, 1, true));


	    }

	    if(forZ) {
	      RECO_ICVarPlus_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	      RECO_ICVarPlus_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	      RECO_ICVarPlus_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	    }
	  }
	}	
      }
    } else {
      RECO_MuonPtMinus->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
      RECO_MuonPtMinus_vw->Fill(theRECOLepton->Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_MuonEtaMinus->Fill(theRECOLepton->Eta(), ev.GetEventWeight());
      RECO_MuonEtaMinusAbs->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight());
      RECO_pfMTMinus->Fill(pfMT, ev.GetEventWeight());
      RECO_pfMTMinus_vw->Fill(pfMT, ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_pfMHTMinus->Fill(pfMET.Pt(), ev.GetEventWeight());
      RECO_pfMHTMinus_vw->Fill(pfMET.Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_pfMETMinus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
      RECO_pfMETMinus_vw->Fill(ev.PFMET().Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_MuonPhiMinus->Fill(theRECOLepton->Phi(), ev.GetEventWeight());
      RECO_CommonMHTMinus->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
      RECO_ICVarMinus->Fill(ICVariable, ev.GetEventWeight());

      RECO_ICVarTCMinus->Fill(ICVariableTC, ev.GetEventWeight());
      RECO_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight());
      RECO_ICVarPFMinus_vw->Fill(ICVariablePF, ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
      RECO_ICVarIC5Minus->Fill(ICVariableIC5, ev.GetEventWeight());
      RECO_ICVarAK5Minus->Fill(ICVariableAK5, ev.GetEventWeight());


      RECO_ICVarPFMinus_PTWp1pc->Fill(ICVariablePF/1.01, ev.GetEventWeight());
      RECO_ICVarPFMinus_PTWp3pc->Fill(ICVariablePF/1.03, ev.GetEventWeight());
      RECO_ICVarPFMinus_PTWp5pc->Fill(ICVariablePF/1.05, ev.GetEventWeight());
      RECO_ICVarPFMinus_PTWm1pc->Fill(ICVariablePF/0.99, ev.GetEventWeight());
      RECO_ICVarPFMinus_PTWm3pc->Fill(ICVariablePF/0.97, ev.GetEventWeight());
      RECO_ICVarPFMinus_PTWm5pc->Fill(ICVariablePF/0.95, ev.GetEventWeight());

      RECO_ICVarPFMinus_PTMp1pc->Fill(ICVariablePF * (1.0 + ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_ICVarPFMinus_PTMm1pc->Fill(ICVariablePF * (1.0 - ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_ICVarPFMinus_PTMp3pc->Fill(ICVariablePF * (1.0 + ((0.03 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_ICVarPFMinus_PTMm3pc->Fill(ICVariablePF * (1.0 - ((0.03 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());

      RECO_pfMTMinus_PTMp1pc->Fill(pfMT * TMath::Sqrt(1.0 + ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_pfMTMinus_PTMm1pc->Fill(pfMT * TMath::Sqrt(1.0 - ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());

      RECO_MuonPtMinus_PTMp1pc->Fill(theRECOLepton->Pt() * (1.0 + ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());
      RECO_MuonPtMinus_PTMm1pc->Fill(theRECOLepton->Pt() * (1.0 - ((0.01 * theRECOLepton->Pt()) / 100.0)), ev.GetEventWeight());

      RECO_PTmuminusvsMT_Profile->Fill(theRECOLepton->Pt(), pfMT, ev.GetEventWeight());
      RECO_PTmuminusvsMT->Fill(theRECOLepton->Pt(), pfMT, ev.GetEventWeight());

      if(doGen) {
	if(theGenLepton->GetID() > 0) { //i.e. negative charge case
	  jSolutionsW jMCSolution;
	  jGenLep = TLVConvert(theGenLepton);
	  jMCSolution = FindBoost(jGenLep, theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), true, false, theVBosons.at(0)->M());
	  if(jMCSolution.realSolutions) {
	    int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	    MC_CosThetaStar1Minus->Fill(jMCSolution.rightSol, ev.GetEventWeight());
	    if(forW) {
	      RECO_ICVarMinus_LH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	      RECO_ICVarMinus_RH->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	      RECO_ICVarMinus_LO->Fill(ICVariable, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));


	      RECO_ICVarPFMinus_LH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
	      RECO_ICVarPFMinus_RH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
	      RECO_ICVarPFMinus_LO->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));

	      RECO_ICVarPFMinus_LH_vw->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace) * GetVertexReweighting(ev.GetVertexSize()));
	      RECO_ICVarPFMinus_RH_vw->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace) * GetVertexReweighting(ev.GetVertexSize()));
	      RECO_ICVarPFMinus_LO_vw->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace) * GetVertexReweighting(ev.GetVertexSize()));

	      if(fabs(theGenLepton->GetID()) == 13) {
		RECO_ICVarPFMinus_LH_GenMu->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
		RECO_ICVarPFMinus_RH_GenMu->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
		RECO_ICVarPFMinus_LO_GenMu->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	      } else {
		RECO_ICVarPFMinus_LH_GenTau->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,mPhaseSpace));
		RECO_ICVarPFMinus_RH_GenTau->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,mPhaseSpace));
		RECO_ICVarPFMinus_LO_GenTau->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,mPhaseSpace));
	      }

	      TLorentzVector hframelepton = HTransform(TLVConvert(theGenLepton), TLVConvert(theVBosons.at(0)));
	      RECO_ICVarPFMinus_A0p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 0, 1.1, 1, true));
	      RECO_ICVarPFMinus_A1p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 1, 1.1, 1, true));
	      RECO_ICVarPFMinus_A2p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 2, 1.1, 1, true));
	      RECO_ICVarPFMinus_A3p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 3, 1.1, 1, true));
	      RECO_ICVarPFMinus_A4p10pc->Fill(ICVariablePF, ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 4, 1.1, 1, true));
	      RECO_MuonEtaMinus_A0p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 0, 1.1, 1, true));
	      RECO_MuonEtaMinus_A1p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 1, 1.1, 1, true));
	      RECO_MuonEtaMinus_A2p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 2, 1.1, 1, true));
	      RECO_MuonEtaMinus_A3p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 3, 1.1, 1, true));
	      RECO_MuonEtaMinus_A4p10pc->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight()*AiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), false, 4, 1.1, 1, true));

	    }
	  }
	}       
      }
    }

    RECO_CommonMHT->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
    RECO_pfMHT->Fill(pfMET.Pt(), ev.GetEventWeight());//remember, pfMET is corrected for the muon, so it is really pfMHT
    RECO_pfMHT_vw->Fill(pfMET.Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
    RECO_pfMET->Fill(ev.PFMET().Pt(), ev.GetEventWeight());//ev.PFMET is the pfMET from the event data
    RECO_pfMET_vw->Fill(ev.PFMET().Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
    RECO_pfMHTvsMuPt->Fill(pfMET.Pt(), theRECOLepton->Pt(), ev.GetEventWeight());
    RECO_MuonPt->Fill(theRECOLepton->Pt(), ev.GetEventWeight());
    RECO_MuonPt_vw->Fill(theRECOLepton->Pt(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
    RECO_MuonPhi->Fill(theRECOLepton->Phi(), ev.GetEventWeight());
    RECO_MuonEta->Fill(fabs(theRECOLepton->Eta()), ev.GetEventWeight());
    RECO_JetMultiplicity->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());
    RECO_JetMultiplicity_vw->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight()*GetVertexReweighting(ev.GetVertexSize()));
    //RECO_MuonMultiplicity->Fill(theRECOLepton.size(), ev.GetEventWeight());

    RECO_Tr->Fill(theRECOLepton->GetTrkIsolation() /theRECOLepton->Pt(), ev.GetEventWeight());
    RECO_Ecal->Fill(theRECOLepton->GetEcalIsolation() /theRECOLepton->Pt(), ev.GetEventWeight());
    RECO_Hcal->Fill(theRECOLepton->GetCombIsolation() /theRECOLepton->Pt(), ev.GetEventWeight());
    RECO_Com->Fill(theRECOLepton->GetCombIsolation(), ev.GetEventWeight());
    RECO_Type->Fill(theRECOLepton->GetType(), ev.GetEventWeight());

    float minDeltaR = 20;
    for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
      if (i == 0) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton)));
      else {
	if(fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton))) < minDeltaR) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton)));
      }
    }
    RECO_DR->Fill(minDeltaR, ev.GetEventWeight());

    float Zmass = 0.0;
    float JPsimass = 0.0;
    if(ev.LD_Muons().size()>1) {

      for (std::vector<Event::Lepton>::const_iterator imu = ev.LD_Muons().begin();  imu != ev.LD_Muons().end();++imu) {
	float CurrentMass = ROOT::Math::VectorUtil::InvariantMass(*imu,*(theRECOLepton));
	if(Zmass==0.0) Zmass=CurrentMass;
	if(JPsimass==0.0) JPsimass=CurrentMass;	
	if(fabs(CurrentMass-91.2) < (fabs(Zmass-91.2)))  Zmass=CurrentMass;
	if(fabs(CurrentMass-3.1) < (fabs(JPsimass-3.1)))  JPsimass=CurrentMass;
      }
    }
    RECO_2ndMassZ->Fill(Zmass,ev.GetEventWeight());
    RECO_2ndMassJPsi->Fill(JPsimass,ev.GetEventWeight());

    if(doGen) {
      //check how many times real MC muon exists for RECO muon and when this happens, check the charge identification and the pt and eta widths
      //if(myGenMatrixBin.the_GenMuon.size() == theRECOLepton.size()) {
      //MC_RECO_MuonMultMatch->Fill(1.0, ev.GetEventWeight());
	if(theVBosons.size() > 0) {
	  if(forW) MC_RECO_MHTDiffProfile->Fill(theVBosons.at(0)->Pt(), (theVBosons.at(0)->Pt() - ev.CommonMHT().Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	  if(forZ) MC_RECO_MHTDiffProfile->Fill(theVBosons.at(0)->Pt(), (theVBosons.at(0)->Pt() - reco_boson.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	  if(theVBosons.at(0)->Pt() > WPtResCut) {
	    if(forW) MC_RECO_MHTDiff->Fill((theVBosons.at(0)->Pt() - ev.CommonMHT().Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	    if(forZ) MC_RECO_MHTDiff->Fill((theVBosons.at(0)->Pt() - reco_boson.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	    MC_RECO_CaloMETDiff->Fill((theVBosons.at(0)->Pt() - ev.CaloMET().Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());

	    //to ensure compatibility

	    MC_RECO_TCMETDiff->Fill((theVBosons.at(0)->Pt() - tcMET.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	    MC_RECO_PFMETDiff->Fill((theVBosons.at(0)->Pt() - pfMET.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	    MC_RECO_IC5METDiff->Fill((theVBosons.at(0)->Pt() - ic5MET.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	    MC_RECO_AK5METDiff->Fill((theVBosons.at(0)->Pt() - ak5MET.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
	    RECO_MHTvsTCMET->Fill(ev.CommonMHT().Pt(), tcMET.Pt(), ev.GetEventWeight());
	    RECO_MHTvsPFMET->Fill(ev.CommonMHT().Pt(), pfMET.Pt(), ev.GetEventWeight());
	    RECO_MHTvsCaloMET->Fill(ev.CommonMHT().Pt(), ev.CaloMET().Pt(), ev.GetEventWeight());
	    RECO_MHTvsAK5MET->Fill(ev.CommonMHT().Pt(), ak5MET.Pt(), ev.GetEventWeight());
	    RECO_MHTvsIC5MET->Fill(ev.CommonMHT().Pt(), ic5MET.Pt(), ev.GetEventWeight());

	  }
	}
	MC_RECO_MuonPtDiff->Fill((theGenLepton->Pt() - theRECOLepton->Pt())/theGenLepton->Pt(), ev.GetEventWeight());
	MC_RECO_MuonEtaDiff->Fill((theGenLepton->Eta() - theRECOLepton->Eta())/theGenLepton->Eta(), ev.GetEventWeight());
	//LorentzV genLepton(theGenLepton->Px(), theGenLepton->Py(), theGenLepton->Pz(), theGenLepton->E());
//	LorentzV genMHT = *(ev.genMetP4PF()) + *(theGenLepton);
//	MC_RECO_genMHTDiff->Fill((theVBosons.at(0)->Pt() - genMHT.Pt())/theVBosons.at(0)->Pt(), ev.GetEventWeight());
//	if(genMHT.Pt()>0.0) MC_RECO_PFMETres_vs_genMHT->Fill(genMHT.Pt(), (genMHT.Pt() - pfMET.Pt())/genMHT.Pt(), ev.GetEventWeight());
	//remember that a negatively charge muon has a positive ID and vice versa
	//if((myGenMatrixBin.the_GenMuon.at(0)->GetID() > 0 && theRECOLepton.at(0)->GetCharge() < 0) || (myGenMatrixBin.the_GenMuon.at(0)->GetID() < 0 && theRECOLepton.at(0)->GetCharge() > 0)) MC_RECO_MuonChargeId->Fill(1.0, ev.GetEventWeight());
	//else MC_RECO_MuonChargeId->Fill(0.0, ev.GetEventWeight());

	//} else {
	//MC_RECO_MuonMultMatch->Fill(0.0, ev.GetEventWeight());
	//}
    }

    //fill a histogram to determine which trigger bits fired
    //if(ev.hlt()->find("HLT_Mu3")->second) RECO_HLTMutriggerbits->Fill(1*(ev.hlt()->find("HLT_Mu3")->second), ev.GetEventWeight());
    //if(ev.hlt()->find("HLT_Mu5")->second) RECO_HLTMutriggerbits->Fill(2*(ev.hlt()->find("HLT_Mu5")->second), ev.GetEventWeight());
    //if(ev.hlt()->find("HLT_Mu9")->second) RECO_HLTMutriggerbits->Fill(3*(ev.hlt()->find("HLT_Mu9")->second), ev.GetEventWeight());


    //now fill the cos theta star distributions - first check for real solutions
    //jRECOSol = FindBoost(*(theRECOLepton.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), 0.0, false);
    if(forW) jRECOSol = FindBoost(TLVConvert(theRECOLepton), ev.CommonMHT().Px(), ev.CommonMHT().Py(), 0.0, false);
    if(forZ) jRECOSol = FindBoost(TLVConvert(theRECOLepton), reco_boson.Px(), reco_boson.Py(), reco_boson.Pz(), true, false, reco_boson.M());

    if(jRECOSol.realSolutions) {
      if(theRECOLepton->GetCharge()>0.0) {
	if(forW) {
	  RECO_CosThetaStar1Sol1Plus->Fill(jRECOSol.sol1, ev.GetEventWeight());
	  RECO_CosThetaStar1Sol2Plus->Fill(jRECOSol.sol2, ev.GetEventWeight());
	}

	if(forZ) {
	  int index = int( (jRECOSol.rightSol + 1.0) / 0.01 );
	  RECO_CosThetaStar1Sol1Plus->Fill(jRECOSol.rightSol, ev.GetEventWeight());
	  if(doGen) {
	    RECO_CosThetaStar1Sol1Plus_LH->Fill(jRECOSol.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	    RECO_CosThetaStar1Sol1Plus_RH->Fill(jRECOSol.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	    RECO_CosThetaStar1Sol1Plus_LO->Fill(jRECOSol.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));

TLorentzVector hframelepton = HTransform(TLVConvert(theGenLepton), TLVConvert(theVBosons.at(0)));
	      RECO_CosThetaStar1Sol1Plus_A0p10pc->Fill(jRECOSol.rightSol, ev.GetEventWeight()*AiCorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 0, 1.1, 1, true));
	      RECO_CosThetaStar1Sol1Plus_A1p10pc->Fill(jRECOSol.rightSol, ev.GetEventWeight()*AiCorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 1, 1.1, 1, true));
	      RECO_CosThetaStar1Sol1Plus_A2p10pc->Fill(jRECOSol.rightSol, ev.GetEventWeight()*AiCorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 2, 1.1, 1, true));
	      RECO_CosThetaStar1Sol1Plus_A3p10pc->Fill(jRECOSol.rightSol, ev.GetEventWeight()*AiCorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 3, 1.1, 1, true));
	      RECO_CosThetaStar1Sol1Plus_A4p10pc->Fill(jRECOSol.rightSol, ev.GetEventWeight()*AiCorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(), hframelepton.CosTheta(), hframelepton.Phi(), true, 4, 1.1, 1, true));

	  }
	}


      }else{ // if real sol and minus
	if(forW) {
	  RECO_CosThetaStar1Sol1Minus->Fill(jRECOSol.sol1, ev.GetEventWeight());
	  RECO_CosThetaStar1Sol2Minus->Fill(jRECOSol.sol2, ev.GetEventWeight());
	}
      }
    } else { // if not real solutions
      if(forW) {
	//plot an "underflow" bin on these plots which will give an indication of the number of virtual solutions for each sample
	if(theRECOLepton->GetCharge()>0.0) {
	  RECO_CosThetaStar1Sol1Plus->Fill(-1.2, ev.GetEventWeight());
	  RECO_CosThetaStar1Sol2Plus->Fill(-1.2, ev.GetEventWeight());
	}else{
	  RECO_CosThetaStar1Sol1Minus->Fill(-1.2, ev.GetEventWeight());
	  RECO_CosThetaStar1Sol2Minus->Fill(-1.2, ev.GetEventWeight());
	}
      }
    }

    if (forZ && theRECOLepton->GetCharge()>0.0) { // Mu Pt scale corrected templates

      TLorentzVector theRECOLeptonCorr = MuPtScaleCorr(+1,TLVConvert(theRECOLepton),doGen);       
      TLorentzVector reco_bosonCorr = MuPtScaleCorr(+1,TLVConvert(theRECOLepton),doGen) + MuPtScaleCorr(-1,TLVConvert(theRECOLepton2),doGen);

      jSolutionsW jRECOSolCorr = FindBoost(theRECOLeptonCorr, reco_bosonCorr.Px(), reco_bosonCorr.Py(), reco_bosonCorr.Pz(), true, false, reco_bosonCorr.M());
      if(jRECOSolCorr.realSolutions) {
	int index = int( (jRECOSolCorr.rightSol + 1.0) / 0.01 );
	RECO_CosThetaStar1Sol1CorrPlus->Fill(jRECOSolCorr.rightSol, ev.GetEventWeight());
	if(doGen) {
	  RECO_CosThetaStar1Sol1CorrPlus_LH->Fill(jRECOSolCorr.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,mPhaseSpace));
	  RECO_CosThetaStar1Sol1CorrPlus_RH->Fill(jRECOSolCorr.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,mPhaseSpace));
	  RECO_CosThetaStar1Sol1CorrPlus_LO->Fill(jRECOSolCorr.rightSol, ev.GetEventWeight() * CorrFactorZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeightZ(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,mPhaseSpace));
	}
      }
    }



    return true;

  }


  std::ostream& RECOPolPlots::Description(std::ostream &ostrm) {
    ostrm << "Reco Level Polarisation plots";
    return ostrm;
  }

 
} // ~namespace Operation
