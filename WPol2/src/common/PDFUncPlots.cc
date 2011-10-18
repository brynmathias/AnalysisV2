//#define DOPDF //uncomment to compile
#ifdef DOPDF
#include "PDFUncPlots.hh"
//originally written by Jad Marrouche, January 2011 onwards
namespace Operation {
  //====================================
  // PDFUncPlots implementation
  //====================================

  PDFUncPlots::PDFUncPlots(const std::string & folderName) :
    mFolderName(folderName) {}

  PDFUncPlots::~PDFUncPlots() {}

  void PDFUncPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void PDFUncPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    //hardcoded for now... 41 = num PDF Sets in CTEQ61
    //TH1D * RECO_ICVarPFPlus[41];
    //TH1D * RECO_ICVarPFMinus[41];
    char h_name_plus[50], h_name_minus[50];
    char h_name_lh_plus[50], h_name_rh_plus[50], h_name_lo_plus[50];
    char h_name_lh_minus[50], h_name_rh_minus[50], h_name_lo_minus[50];
    for(unsigned int n=0; n<41; n++) {
      sprintf(h_name_plus, "RECO_ICVarPFPlus_hist_%d",n);
      RECO_ICVarPFPlus[n] = new TH1D(h_name_plus,";LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
      sprintf(h_name_minus, "RECO_ICVarPFMinus_hist_%d",n);
      RECO_ICVarPFMinus[n] = new TH1D(h_name_minus,";LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);

      sprintf(h_name_lh_plus, "RECO_ICVarPFPlus_hist_LH_%d",n);
      sprintf(h_name_rh_plus, "RECO_ICVarPFPlus_hist_RH_%d",n);
      sprintf(h_name_lo_plus, "RECO_ICVarPFPlus_hist_LO_%d",n);
      RECO_ICVarPFPlus_LH[n] = new TH1D(h_name_lh_plus,";Left-Handed LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
      RECO_ICVarPFPlus_RH[n] = new TH1D(h_name_rh_plus,";Right-Handed LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);
      RECO_ICVarPFPlus_LO[n] = new TH1D(h_name_lo_plus,";Longitudinal LP(#mu^{+});Events / 1 pb^{-1}",500,-2.5,2.5);

      sprintf(h_name_lh_minus, "RECO_ICVarPFMinus_hist_LH_%d",n);
      sprintf(h_name_rh_minus, "RECO_ICVarPFMinus_hist_RH_%d",n);
      sprintf(h_name_lo_minus, "RECO_ICVarPFMinus_hist_LO_%d",n);
      RECO_ICVarPFMinus_LH[n] = new TH1D(h_name_lh_minus,";Left-Handed LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);
      RECO_ICVarPFMinus_RH[n] = new TH1D(h_name_rh_minus,";Right-Handed LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);
      RECO_ICVarPFMinus_LO[n] = new TH1D(h_name_lo_minus,";Longitudinal LP(#mu^{-});Events / 1 pb^{-1}",500,-2.5,2.5);

    }
    //MHTeffect = new TH1D("MHTeffect", ";scaledMHT / originalMHT;Events",2000, -0.005, 1.995);
    TH1::SetDefaultSumw2(kFALSE);
  }

  bool PDFUncPlots::Process(Event::Data & ev) {

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
    TLorentzVector jGenLep;
    if(myGenMatrixBin.the_GenW.size()==0) return false; 
    theVBosons = myGenMatrixBin.the_GenW;
    if(myGenMatrixBin.the_GenMuon.size() == 1 && myGenMatrixBin.the_GenTau.size() == 0) theGenLepton = myGenMatrixBin.the_GenMuon.at(0);
    else if(myGenMatrixBin.the_GenTau.size() == 1 && myGenMatrixBin.the_GenMuon.size() == 0) theGenLepton = myGenMatrixBin.the_GenTau.at(0);
    else return false;
    jGenLep = TLVConvert(theGenLepton);

    //Set up the LP Variable for this event:
    Event::Lepton const * theRECOLepton;
    LorentzV pfMET;
    theRECOLepton = ev.LD_CommonMuons().accepted.at(0);
    pfMET = ev.PFMET() + *(theRECOLepton);
    double ICVariablePF = ((theRECOLepton->Px() * pfMET.Px()) + (theRECOLepton->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());

    //Set up the PDF uncertainty calculation:
    const int SUBSET = 0; //pdf subset
    const string NAME = "/home/jadm/dev/lhapdf_stuff/bin/cteq61"; //location of the pdf set
    //std::cout << "initialising PDF Set" << std::endl;
    LHAPDF::Verbosity verbose = LHAPDF::SILENT; //set to silent so it doesn't print out a load of stuff (see the include/LHAPDF.h for more)
    LHAPDF::setVerbosity(verbose);
    LHAPDF::initPDFSet(NAME, LHAPDF::LHGRID, SUBSET);
    //std::cout << "initialised!" << std::endl;
    LHAPDF::initPDF(0);
    //now set up the baseline values with which to weight relative to:
    double pdf1 = LHAPDF::xfx(ev.genx1(), ev.genQ(), ev.genid1())/ev.genx1();
    double pdf2 = LHAPDF::xfx(ev.genx2(), ev.genQ(), ev.genid2())/ev.genx2();

    //std::cout << "pdf1: " << pdf1 << std::endl;
    //std::cout << "pdf2: " << pdf2 << std::endl;

    const int NUMBER = LHAPDF::numberPDF();

    for (int n = 0; n < NUMBER + 1; ++n) {
      //cout << "Set number: " << n << endl;
      LHAPDF::initPDF(n);
      double newpdf1 =  LHAPDF::xfx(ev.genx1(), ev.genQ(), ev.genid1())/ev.genx1();
      double newpdf2 =  LHAPDF::xfx(ev.genx2(), ev.genQ(), ev.genid2())/ev.genx2();
      double PDFUncWeight = (newpdf1/pdf1)*(newpdf2/pdf2);
      //std::cout << "Weight " << n << ": " << (newpdf1/pdf1)*(newpdf2/pdf2) << std::endl;
      if(theRECOLepton->GetCharge()>0.0) {	
	RECO_ICVarPFPlus[n]->Fill(ICVariablePF, ev.GetEventWeight() * PDFUncWeight);

	if(theGenLepton->GetID() < 0) { //i.e. if the gen-reco charge matches
	  jMCSolution = FindBoost(jGenLep, theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), true, false, theVBosons.at(0)->M());
	  if(jMCSolution.realSolutions) {
	    int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	    RECO_ICVarPFPlus_LH[n]->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,0,1) * PDFUncWeight);
	    RECO_ICVarPFPlus_RH[n]->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,1,1) * PDFUncWeight);
	    RECO_ICVarPFPlus_LO[n]->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),true,2,1) * PDFUncWeight);
	  }
	}

      } else {
	RECO_ICVarPFMinus[n]->Fill(ICVariablePF, ev.GetEventWeight() * PDFUncWeight);

	if(theGenLepton->GetID() > 0) { //i.e. if the gen-reco charge matches
	  jMCSolution = FindBoost(jGenLep, theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), theVBosons.at(0)->Pz(), true, false, theVBosons.at(0)->M());
	  if(jMCSolution.realSolutions) {
	    int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	    RECO_ICVarPFMinus_LH[n]->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,0,1) * PDFUncWeight);
	      RECO_ICVarPFMinus_RH[n]->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,1,1) * PDFUncWeight);
	      RECO_ICVarPFMinus_LO[n]->Fill(ICVariablePF, ev.GetEventWeight() * CorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2) * CorrFactorWeight(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),false,2,1) * PDFUncWeight);
	  }
	}
      }  
    }



    return true;
  }

  std::ostream& PDFUncPlots::Description(std::ostream &ostrm) {
    ostrm << "PDF Uncertainty Plots";
    return ostrm;
  }
 
} // ~namespace Operation
#endif
