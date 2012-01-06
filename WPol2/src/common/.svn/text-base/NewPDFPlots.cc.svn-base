//#define DOPDF //uncomment to compile
#ifdef DOPDF
#include "NewPDFPlots.hh"
//originally written by Jad Marrouche, January 2011 onwards
namespace Operation {
  //====================================
  // NewPDFPlots implementation
  //====================================

  NewPDFPlots::NewPDFPlots(const std::string & folderName, const std::string & PDFSetName, int setID) :
    mFolderName(folderName),
    mPDFSetName(PDFSetName),
    mSetID(setID) {}

  NewPDFPlots::~NewPDFPlots() {}

  void NewPDFPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void NewPDFPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    MC_CosThetaStar1PlusTest1 = new TH1D("MC_CosThetaStar1PlusTest1", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1MinusTest1 = new TH1D("MC_CosThetaStar1MinusTest1", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

    RECO_ICVarPFPlus = new TH1D("RECO_ICVarPFPlus",";LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus = new TH1D("RECO_ICVarPFMinus",";LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);

    RECO_ICVarPFPlus_LH = new TH1D("RECO_ICVarPFPlus_LH",";Left-Handed LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_RH = new TH1D("RECO_ICVarPFPlus_RH",";Right-Handed LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFPlus_LO = new TH1D("RECO_ICVarPFPlus_LO",";Longitudinal LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);

    RECO_ICVarPFMinus_LH = new TH1D("RECO_ICVarPFMinus_LH",";Left-Handed LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_RH = new TH1D("RECO_ICVarPFMinus_RH",";Right-Handed LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);
    RECO_ICVarPFMinus_LO = new TH1D("RECO_ICVarPFMinus_LO",";Longitudinal LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);

    TH1::SetDefaultSumw2(kFALSE);

    //Set up the PDF uncertainty calculation:
    const string NAME1 = "/home/jadm/dev/lhapdf_stuff/bin/cteq61"; //location of the pdf set currently in the MC
    const string NAME2 = "/home/jadm/dev/lhapdf_stuff/bin/" + mPDFSetName; //e.g. MSTW2008nnlo90cl - the location of the pdf set we want to reweight to

    LHAPDF::Verbosity verbose = LHAPDF::SILENT; //set to silent so it doesn't print out a load of stuff (see the include/LHAPDF.h for more)
    LHAPDF::setVerbosity(verbose);
    std::cout << "initialising PDF Sets" << std::endl;
    //the setID is used so that you are able to compare more than 1 pair of PDFs in a particular cut-flow
    LHAPDF::initPDFSetM(1, NAME1, LHAPDF::LHGRID);
    LHAPDF::initPDFM(1,0);
    LHAPDF::initPDFSetM(mSetID, NAME2, LHAPDF::LHGRID);
    LHAPDF::initPDFM(mSetID,0);
    std::cout << "initialised!" << std::endl;

  }

  bool NewPDFPlots::Process(Event::Data & ev) {

    //print out some interesting stuff for that event:
    //std::cout << "x1: " << ev.genx1() << std::endl;
    //std::cout << "x2: " << ev.genx2() << std::endl;
    //std::cout << "id1: " << ev.genid1() << std::endl;
    //std::cout << "id2: " << ev.genid2() << std::endl;
    //std::cout << "pdf1: " << ev.genpdf1() << std::endl; //this is always -1 for some reason (wrong in ntuple?)
    //std::cout << "pdf2: " << ev.genpdf2() << std::endl; //this is always -1 for some reason (wrong in ntuple?)
    //std::cout << "Q: " << ev.genQ() << std::endl;

    //Set up the Gen Info stuff
    GenMatrixBin myGenMatrixBin;
    myGenMatrixBin = GenMatrixBin(&ev);
    std::vector <Event::GenObject const *> theVBosons;
    Event::GenObject const * theGenLepton;
    jSolutionsW jMCSolution;
    TLorentzVector jGenLep, jGenW;
    if(myGenMatrixBin.the_GenW.size()==0) return false; 
    theVBosons = myGenMatrixBin.the_GenW;
    if(myGenMatrixBin.the_GenEli.size()) theGenLepton = myGenMatrixBin.the_GenEli.at(0);
    else if(myGenMatrixBin.the_GenMuon.size()) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
    else if(myGenMatrixBin.the_GenTau.size()) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
    else {
      cout << "MCWPlots: The W boson does not decay to a lepton" << endl;
      return false;
    }
    
    jGenLep = TLVConvert(theGenLepton);
    jGenW = TLVConvert(myGenMatrixBin.the_GenW.at(0));
    
    //Set up the PDF uncertainty calculation:
    //const int SUBSET = 0; //pdf subset
    //const string NAME1 = "/home/jadm/dev/lhadpdf_stuff/bin/cteq61"; //location of the pdf set currently in the MC
    //const string NAME2 = "/home/jadm/dev/lhadpdf_stuff/bin/MSTW2008nnlo90cl"; //location of the pdf set we want to reweight to

    //LHAPDF::Verbosity verbose = LHAPDF::SILENT; //set to silent so it doesn't print out a load of stuff (see the include/LHAPDF.h for more)
    //LHAPDF::setVerbosity(verbose);

    //std::cout << "initialising PDF Set" << std::endl;
    //LHAPDF::initPDFSet(NAME1, LHAPDF::LHGRID, SUBSET);
    //std::cout << "initialised!" << std::endl;
    //LHAPDF::initPDF(0);
    //now set up the baseline values with which to weight relative to:
    double pdf1 = LHAPDF::xfxM(1, ev.genx1(), ev.genQ(), ev.genid1())/ev.genx1();
    double pdf2 = LHAPDF::xfxM(1, ev.genx2(), ev.genQ(), ev.genid2())/ev.genx2();

    //std::cout << "pdf1: " << pdf1 << std::endl;
    //std::cout << "pdf2: " << pdf2 << std::endl;

    //std::cout << "initialising second PDF Set" << std::endl;
    //LHAPDF::initPDFSet(NAME2, LHAPDF::LHGRID, SUBSET);
    //std::cout << "initialised!" << std::endl;
    //LHAPDF::initPDF(0);
    //now set up the baseline values with which to weight relative to:
    double newpdf1 = LHAPDF::xfxM(mSetID, ev.genx1(), ev.genQ(), ev.genid1())/ev.genx1();
    double newpdf2 = LHAPDF::xfxM(mSetID, ev.genx2(), ev.genQ(), ev.genid2())/ev.genx2();

    double PDFUncWeight = (newpdf1/pdf1)*(newpdf2/pdf2);
    //std::cout << "Weight: " << PDFUncWeight << std::endl;

    TLorentzVector hframelepton = HTransform(jGenLep, jGenW);
    if(theGenLepton->GetID() < 0) MC_CosThetaStar1PlusTest1->Fill(hframelepton.CosTheta(), ev.GetEventWeight() * PDFUncWeight);
    else MC_CosThetaStar1MinusTest1->Fill(hframelepton.CosTheta(), ev.GetEventWeight() * PDFUncWeight);


    if(ev.LD_CommonMuons().accepted.size()) { //i.e. there is at least one RECO muon which passes our ID
      if((myGenMatrixBin.the_GenMuon.size() == 1 && myGenMatrixBin.the_GenTau.size() == 0) || (myGenMatrixBin.the_GenTau.size() == 1 && myGenMatrixBin.the_GenMuon.size() == 0)) { //i.e. the genlepton is true
	//Set up the LP Variable for this event:
	Event::Lepton const * theRECOLepton;
	LorentzV pfMET;
	theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
	pfMET = ev.PFMET() + *(theRECOLepton);
	double ICVariablePF = ((theRECOLepton->Px() * pfMET.Px()) + (theRECOLepton->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());

	if(theRECOLepton->GetCharge()>0.0) {
	  RECO_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight() * PDFUncWeight);

	  if(theGenLepton->GetID() < 0) { //i.e. if the gen-reco charge matches
	    jMCSolution = FindBoost(jGenLep, theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), true, false, theVBosons.at(0)->M());
	    if(jMCSolution.realSolutions) {
	      int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	      RECO_ICVarPFPlus_LH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,1) * PDFUncWeight);
	      RECO_ICVarPFPlus_RH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,1) * PDFUncWeight);
	      RECO_ICVarPFPlus_LO->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,1) * PDFUncWeight);
	    }
	  }
      
	} else {
	  RECO_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight() * PDFUncWeight);

	  if(theGenLepton->GetID() > 0) { //i.e. if the gen-reco charge matches
	    jMCSolution = FindBoost(jGenLep, theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), true, false, theVBosons.at(0)->M());
	    if(jMCSolution.realSolutions) {
	      int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	      RECO_ICVarPFMinus_LH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,1) * PDFUncWeight);
	      RECO_ICVarPFMinus_RH->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,1) * PDFUncWeight);
	      RECO_ICVarPFMinus_LO->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,1) * PDFUncWeight);
	    }
	  }
	}
      }
    }
    return true;
  }

  std::ostream& NewPDFPlots::Description(std::ostream &ostrm) {
    ostrm << "New PDF Plots";
    return ostrm;
  }
 
} // ~namespace Operation
#endif
