#include "ElPlottingOps.hh"
#include "WPolFilters.hh"
using namespace Operation;
using namespace WPol;

// Keep all this in eWPol for the moment to preserve
// current RECOPolPlots. In fact this should work for
// both electrons and muons.

namespace eWPol{

//====================================
  // RECOPolPlots implementation
  //====================================


RECOPolPlots::RECOPolPlots(const std::string & folderName,
                           const Utils::ParameterSet & ps) :
    mFolderName(folderName),
    //change this parameter ONLY - this will let you use comparison with generator level quantities
    mDoGen(ps.Get<bool>("DoGen")),
    mLeptonType(WPol::GetLeptonType(ps.Get<std::string>("LeptonType"))),
    mMETThresh(ps.Get<double>("METThreshold"))
{}

  RECOPolPlots::~RECOPolPlots() {}

  void RECOPolPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void RECOPolPlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);

    RECO_tcMET = new TH1D("RECO_tcMET","",1000,0.,500.);
    RECO_pfMET=new TH1D("RECO_pfMET","",1000,0.,500.);
    RECO_ic5MET=new TH1D("RECO_ic5MET","",1000,0.,500.);
    RECO_ak5MET=new TH1D("RECO_ak5MET","",1000,0.,500.);

    RECO_LeptonPtPlus = new TH1D("RECO_LeptonPtPlus", "", 1000,-0.5,999.5);
    RECO_LeptonPtMinus = new TH1D("RECO_LeptonPtMinus", "", 1000,-0.5,999.5);
    RECO_LeptonEtaPlus =  new TH1D("RECO_LeptonEtaPlus","",100, -5.5, 4.5);
    RECO_LeptonEtaMinus =  new TH1D("RECO_LeptonEtaMinus","",100, -5.5, 4.5);
    RECO_LeptonEtaPlusAbs =  new TH1D("RECO_LeptonEtaPlusAbs","",100, -0.025, 4.975);
    RECO_LeptonEtaMinusAbs =  new TH1D("RECO_LeptonEtaMinusAbs","",100, -0.025, 4.975);
    RECO_CommonMHTPlus = new TH1D("RECO_CommonMHTPlus","",1000,-0.5,999.5);
    RECO_CommonMHTMinus = new TH1D("RECO_CommonMHTMinus","",1000,-0.5,999.5);
    RECO_ICVarPlus = new TH1D("RECO_ICVarPlus","",500,-2.5,2.5);
    RECO_ICVarMinus = new TH1D("RECO_ICVarMinus","",500,-2.5,2.5);

    RECO_ICVarMinus_LH = new TH1D("RECO_ICVarMinus_LH","",500,-2.5,2.5);
    RECO_ICVarPlus_LH = new TH1D("RECO_ICVarPlus_LH","",500,-2.5,2.5);
    RECO_ICVarMinus_RH = new TH1D("RECO_ICVarMinus_RH","",500,-2.5,2.5);
    RECO_ICVarPlus_RH = new TH1D("RECO_ICVarPlus_RH","",500,-2.5,2.5);
    RECO_ICVarMinus_LO = new TH1D("RECO_ICVarMinus_LO","",500,-2.5,2.5);
    RECO_ICVarPlus_LO = new TH1D("RECO_ICVarPlus_LO","",500,-2.5,2.5);

    RECO_ICVarPFMinus_LH = new TH1D("RECO_ICVarPFMinus_LH","",500,-2.5,2.5);
    RECO_ICVarPFPlus_LH = new TH1D("RECO_ICVarPFPlus_LH","",500,-2.5,2.5);
    RECO_ICVarPFMinus_RH = new TH1D("RECO_ICVarPFMinus_RH","",500,-2.5,2.5);
    RECO_ICVarPFPlus_RH = new TH1D("RECO_ICVarPFPlus_RH","",500,-2.5,2.5);
    RECO_ICVarPFMinus_LO = new TH1D("RECO_ICVarPFMinus_LO","",500,-2.5,2.5);
    RECO_ICVarPFPlus_LO = new TH1D("RECO_ICVarPFPlus_LO","",500,-2.5,2.5);

    RECO_ICVarPFMinus_VertexReweighting_LH = new TH1D("RECO_ICVarPFMinus_VertexReweighting_LH","",500,-2.5,2.5);
    RECO_ICVarPFPlus_VertexReweighting_LH = new TH1D("RECO_ICVarPFPlus_VertexReweighting_LH","",500,-2.5,2.5);
    RECO_ICVarPFMinus_VertexReweighting_RH = new TH1D("RECO_ICVarPFMinus_VertexReweighting_RH","",500,-2.5,2.5);
    RECO_ICVarPFPlus_VertexReweighting_RH = new TH1D("RECO_ICVarPFPlus_VertexReweighting_RH","",500,-2.5,2.5);
    RECO_ICVarPFMinus_VertexReweighting_LO = new TH1D("RECO_ICVarPFMinus_VertexReweighting_LO","",500,-2.5,2.5);
    RECO_ICVarPFPlus_VertexReweighting_LO = new TH1D("RECO_ICVarPFPlus_VertexReweighting_LO","",500,-2.5,2.5);

    RECO_ICVarTCPlus = new TH1D("RECO_ICVarTCPlus","",500,-2.5,2.5);
    RECO_ICVarTCMinus = new TH1D("RECO_ICVarTCMinus","",500,-2.5,2.5);
    RECO_ICVarPFPlus = new TH1D("RECO_ICVarPFPlus","",500,-2.5,2.5);
    RECO_ICVarPFMinus = new TH1D("RECO_ICVarPFMinus","",500,-2.5,2.5);
    RECO_ICVarAK5Plus = new TH1D("RECO_ICVarAK5Plus","",500,-2.5,2.5);
    RECO_ICVarAK5Minus = new TH1D("RECO_ICVarAK5Minus","",500,-2.5,2.5);
    RECO_ICVarIC5Plus = new TH1D("RECO_ICVarIC5Plus","",500,-2.5,2.5);
    RECO_ICVarIC5Minus = new TH1D("RECO_ICVarIC5Minus","",500,-2.5,2.5);
    RECO_TransMass = new TH1D("RECO_TransMass","",1000,-0.5,999.5);
    RECO_CommonMHT = new TH1D("RECO_CommonMHT","",1000,-0.5,999.5);
    RECO_LeptonPt = new TH1D("RECO_LeptonPt", "", 1000,-0.5,999.5);

    MC_LeptonMultiplicity = new TH1D("MC_LeptonMultiplicity", ";genW Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    RECO_JetMultiplicity = new TH1D("RECO_JetMultiplicity",";Common Jet Multiplicity;Events / 100 pb^{-1}",20,-0.5,19.5);
    RECO_LeptonMultiplicity = new TH1D("RECO_LeptonMultiplicity", ";RECO Lepton Multiplicity;Events / 100 pb^{-1}", 20,-0.5,19.5);
    MC_WPt = new TH1D("MC_WPt", ";gen W P_{T};Events / 100 pb^{-1}", 1000, -0.5, 999.5);
    MC_WYAbs = new TH1D("MC_WYAbs", ";gen W |Y|; Events / 100 pb^{-1}", 100, -0.025, 4.975);
    MC_CosThetaStar1Plus = new TH1D("MC_CosThetaStar1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    MC_CosThetaStar1Minus = new TH1D("MC_CosThetaStar1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

    RECO_CosThetaStar1Sol1Plus = new TH1D("RECO_CosThetaStar1Sol1Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol1Minus = new TH1D("RECO_CosThetaStar1Sol1Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol2Plus = new TH1D("RECO_CosThetaStar1Sol2Plus", ";cos #theta^{*} from W^{+} ;Events / 100 pb^{-1}", 300,-1.5,1.5);
    RECO_CosThetaStar1Sol2Minus = new TH1D("RECO_CosThetaStar1Sol2Minus", ";cos #theta^{*} from W^{-} ;Events / 100 pb^{-1}", 300,-1.5,1.5);

    MC_RECO_LeptonMultMatch = new TH1D("MC_RECO_LeptonMultMatch",";#mu (MC, RECO) multiplicity match false/true;Events / 100 pb^{-1}",2,-0.5,1.5);
    MC_RECO_MHTDiff = new TH1D("MC_RECO_MHTDiff",";#Delta (MC, RECO)/MC MHT;Events / 100 pb^{-1}", 20000, -1000.5, 999.5);
    MC_RECO_TCMETDiff = new TH1D("MC_RECO_TCMETDiff",";#Delta (MC, RECO)/MC TCMET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_PFMETDiff = new TH1D("MC_RECO_PFMETDiff",";#Delta (MC, RECO)/MC PFMET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_CaloMETDiff = new TH1D("MC_RECO_CaloMETDiff",";#Delta (MC, RECO)/MC CaloMET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_IC5METDiff = new TH1D("MC_RECO_IC5METDiff",";#Delta (MC, RECO)/MC IC5MET;Events / 100 pb^{-1}", 400, -20.5, 19.5);
    MC_RECO_AK5METDiff = new TH1D("MC_RECO_AK5METDiff",";#Delta (MC, RECO)/MC AK5MET;Events / 100 pb^{-1}", 400, -20.5, 19.5);

    MC_RECO_LeptonPtDiff = new TH1D("MC_RECO_LeptonPtDiff",";#Delta (MC, RECO)/MC #muon P_{T};Events / 100 pb^{-1}", 2000, -1000.5, 999.5);
    MC_RECO_LeptonEtaDiff = new TH1D("MC_RECO_LeptonEtaDiff",";#Delta (MC, RECO) #muon #eta;Events / 100 pb^{-1}", 200, -10.5, 9.5);
    MC_RECO_LeptonChargeId = new TH1D("MC_RECO_LeptonChargeId",";#mu charge id wrong/right;Events / 100 pb^{-1}",2,-0.5,1.5);

    RECO_Tr = new TH1D("MC_RECO_TrIsoRel",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Ecal = new TH1D("MC_RECO_Ecal",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Hcal = new TH1D("MC_RECO_Hcal",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Com = new TH1D("MC_RECO_Com",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_DR = new TH1D("MC_RECO_DR",";#mu charge id wrong/right;Events / 100 pb^{-1}",200,-0.,10);
    RECO_Type = new TH1D("MC_RECO_Type",";#mu charge id wrong/right;Events / 100 pb^{-1}",10,-0.5,9.5);
    RECO_2ndMass = new TH1D("mass2muons",";M_{#mu#mu};",1005,-5,1000);

    TH1::SetDefaultSumw2(kFALSE);

    RECO_MHTvsTCMET = new TH2D("RECO_MHTvsTCMET",";MHT; TCMET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsCaloMET = new TH2D("RECO_MHTvsCaloMET",";MHT; CaloMET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsPFMET = new TH2D("RECO_MHTvsPFMET",";MHT; PFMET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsIC5MET = new TH2D("RECO_MHTvsIC5MET",";MHT; IC5MET",1000,-0.5,999.5,1000,-0.5,999.5);
    RECO_MHTvsAK5MET = new TH2D("RECO_MHTvsAK5MET",";MHT; AK5MET",1000,-0.5,999.5,1000,-0.5,999.5);
    MC_WPtY = new TH2D("MC_WPtY",";W P_{T}; W |Y|",1000,-0.5,999.5,  50,-0.05,4.95);

    MC_RECO_MHTDiffProfile = new TProfile("MC_RECO_MHTDiffProfile",";gen W P_{T};#Delta (MC, RECO)/MC MHT",1000,-0.5,999.5,-20.5,19.5,"");
    MC_RECO_PFMHTDiffProfile = new TProfile("MC_RECO_PFMHTDiffProfile",";gen W P_{T};#Delta (MC, RECO)/MC PFMHT",1000,-0.5,999.5,-20.5,19.5,"");
  }

  bool RECOPolPlots::Process(Event::Data & ev) {

    // ******** SOME DEFINITIONS START ********

    //the WPtResCut is for comparing the different MET resolutions vs the genW
    double WPtResCut = 100.0;
    GenMatrixBin myGenMatrixBin;
    std::vector <Event::GenObject const *> *theGenLepton=0;
    std::vector <Event::Lepton const *> theRECOLepton;

    bool GenInfo = false;
    bool Wexists = false;
    if(mDoGen){
      myGenMatrixBin = GenMatrixBin(&ev);
      if((myGenMatrixBin.the_GenMuon.size()==0 && myGenMatrixBin.the_GenTau.size()==0))
        GenInfo=false;
      if(myGenMatrixBin.the_GenW.size() > 0) Wexists = true;
    }

    //use GenInfo as variable to decide if we want to use generator level information

    if(mDoGen && Wexists) GenInfo = true;

    //check that a reco lepton exists otherwise return false safely
    switch(mLeptonType){
      case WPol::WPOL_MUON:
        if(ev.LD_CommonMuons().accepted.size()) theRECOLepton = ev.LD_CommonMuons().accepted;
        else return false;
        if(GenInfo){
          if(myGenMatrixBin.the_GenMuon.size()) theGenLepton = &myGenMatrixBin.the_GenMuon;
          else if(myGenMatrixBin.the_GenTau.size()) theGenLepton = &myGenMatrixBin.the_GenTau;

          if(myGenMatrixBin.the_GenMuon.size() && myGenMatrixBin.the_GenTau.size()) theGenLepton=0;
        }
        break;
      case WPol::WPOL_ELECTRON:
        if(ev.LD_CommonElectrons().accepted.size()) theRECOLepton = ev.LD_CommonElectrons().accepted;
        else return false;
        if(GenInfo){
          if(myGenMatrixBin.the_GenEli.size()) theGenLepton = &myGenMatrixBin.the_GenEli;
          else if(myGenMatrixBin.the_GenTau.size()) theGenLepton = &myGenMatrixBin.the_GenTau;
          if(myGenMatrixBin.the_GenEli.size() && myGenMatrixBin.the_GenTau.size()) theGenLepton=0;
        }
        break;
      default:
        throw std::invalid_argument("Supplied LeptonType option not supported");
    }

    // ******** SOME DEFINITIONS END ********

    //for ICF ntuples only

    LorentzV tcMET, pfMET, ic5MET, ak5MET;
    ICF_LorentzV raw_eli = (ev.electronP4()->at(theRECOLepton[0]->GetIndex()));
    //    tcMET = ev.TCMET() + *(theRECOLepton.at(0));
    pfMET = ev.PFMET() + raw_eli;
    //    ic5MET = ev.IC5MET() + *(theRECOLepton.at(0));
    //ak5MET = ev.AK5MET() + *(theRECOLepton.at(0));

    //    RECO_tcMET->Fill(ev.TCMET().Pt(), ev.GetEventWeight());
    RECO_pfMET->Fill(ev.PFMET().Pt(),  ev.GetEventWeight());
    //RECO_ic5MET->Fill(ev.IC5MET().Pt(), ev.GetEventWeight());
    // RECO_ak5MET->Fill(ev.AK5MET().Pt(),  ev.GetEventWeight());


    //make the IC Variable at RECO level:
    double ICVariable = ((theRECOLepton.at(0)->Px() * ev.CommonMHT().Px()) + (theRECOLepton.at(0)->Py() * ev.CommonMHT().Py())) / (ev.CommonMHT().Pt() * ev.CommonMHT().Pt());

    //    double ICVariableTC = ((theRECOLepton.at(0)->Px() * tcMET.Px()) + (theRECOLepton.at(0)->Py() * tcMET.Py())) / (tcMET.Pt() * tcMET.Pt());
    double ICVariablePF = ((theRECOLepton.at(0)->Px() * pfMET.Px()) + (theRECOLepton.at(0)->Py() * pfMET.Py())) / (pfMET.Pt() * pfMET.Pt());
    //double ICVariableIC5 = ((theRECOLepton.at(0)->Px() * ic5MET.Px()) + (theRECOLepton.at(0)->Py() * ic5MET.Py())) / (ic5MET.Pt() * ic5MET.Pt());
    //double ICVariableAK5 = ((theRECOLepton.at(0)->Px() * ak5MET.Px()) + (theRECOLepton.at(0)->Py() * ak5MET.Py())) / (ak5MET.Pt() * ak5MET.Pt());


    //to use MT, don't call CommonMT() - which is whack. Do the following:
    double eMT=ev.MT(theRECOLepton.at(0),&(ev.CommonRecoilMET()));
    RECO_TransMass->Fill(eMT, ev.GetEventWeight());

    if(GenInfo) {
      MC_WYAbs->Fill(fabs(myGenMatrixBin.the_GenW.at(0)->Rapidity()), ev.GetEventWeight());
      MC_WPt->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
      MC_WPtY->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), fabs(myGenMatrixBin.the_GenW.at(0)->Rapidity()), ev.GetEventWeight());
      if(theGenLepton)
        MC_LeptonMultiplicity->Fill(theGenLepton->size(), ev.GetEventWeight());
    }

    //fill the Lepton and MHT distributions according to charge
    if(theRECOLepton.at(0)->GetCharge()>0.0) {
      RECO_LeptonPtPlus->Fill(theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
      RECO_LeptonEtaPlus->Fill(theRECOLepton.at(0)->Eta(), ev.GetEventWeight());
      RECO_LeptonEtaPlusAbs->Fill(fabs(theRECOLepton.at(0)->Eta()), ev.GetEventWeight());
      RECO_CommonMHTPlus->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
      RECO_ICVarPlus->Fill(ICVariable, ev.GetEventWeight());

      if(GenInfo && theGenLepton) {
        if(theGenLepton->at(0)->GetID() < 0) {
          jSolutionsW jMCSolution;
          jGenW = TLVConvert(myGenMatrixBin.the_GenW.at(0));
          jGenLep = TLVConvert(theGenLepton->at(0));
          jMCSolution = FindBoost(jGenLep, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
	    if(jMCSolution.realSolutions) {
	      int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	      MC_CosThetaStar1Plus->Fill(jMCSolution.rightSol, ev.GetEventWeight());
	      RECO_ICVarPlus_LH->Fill(ICVariable,
                                      ev.GetEventWeight()
                                      * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true,0)
                                      * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 0, 1));
	      RECO_ICVarPlus_RH->Fill(ICVariable,
                                      ev.GetEventWeight()
                                      * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true,1)
                                      * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 1, 1));
	      RECO_ICVarPlus_LO->Fill(ICVariable,
                                      ev.GetEventWeight()
                                      * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true,2)
                                      * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 2, 1));



	      //	      if(pfMET.Pt() > mMETThresh) {
	      RECO_ICVarPFPlus_LH->Fill(ICVariablePF,
                                        ev.GetEventWeight()
                                        * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true,0)
                                        * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 0, 1));
	      RECO_ICVarPFPlus_RH->Fill(ICVariablePF,
                                        ev.GetEventWeight()
                                        * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true, 1)
                                        * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 1, 1));
	      RECO_ICVarPFPlus_LO->Fill(ICVariablePF,
                                        ev.GetEventWeight()
                                        * CorrFactor(jGenW.Pt(), jGenW.Rapidity(), index, true, 2)
                                        * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 2, 1));
              RECO_ICVarPFPlus_VertexReweighting_LH->Fill(ICVariablePF,
                                                          ev.GetEventWeight()
                                                          * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true,0)
                                                          * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 0, 1)
                                                          * GetVertexReweightingElectron(ev.GetVertexSize()));
	      RECO_ICVarPFPlus_VertexReweighting_RH->Fill(ICVariablePF,
                                                          ev.GetEventWeight()
                                                          * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,true, 1)
                                                          * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 1, 1)
                                                          * GetVertexReweightingElectron(ev.GetVertexSize()));
	      RECO_ICVarPFPlus_VertexReweighting_LO->Fill(ICVariablePF,
                                                          ev.GetEventWeight()
                                                          * CorrFactor(jGenW.Pt(), jGenW.Rapidity(), index, true, 2)
                                                          * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), true, 2, 1)
                                                          * GetVertexReweightingElectron(ev.GetVertexSize()));
	      //}


	    }
	}
      }

      //if(tcMET.Pt() > mMETThresh)
      //	RECO_ICVarTCPlus->Fill(ICVariableTC, ev.GetEventWeight());
	//      if(pfMET.Pt() > mMETThresh)
	RECO_ICVarPFPlus->Fill(ICVariablePF, ev.GetEventWeight());
	// if(ic5MET.Pt() > mMETThresh)
	//RECO_ICVarIC5Plus->Fill(ICVariableIC5, ev.GetEventWeight());
	//if(ak5MET.Pt() > mMETThresh)
	//RECO_ICVarAK5Plus->Fill(ICVariableAK5, ev.GetEventWeight());

    }else{
      RECO_LeptonPtMinus->Fill(theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
      RECO_LeptonEtaMinus->Fill(theRECOLepton.at(0)->Eta(), ev.GetEventWeight());
      RECO_LeptonEtaMinusAbs->Fill(fabs(theRECOLepton.at(0)->Eta()), ev.GetEventWeight());
      RECO_CommonMHTMinus->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
      RECO_ICVarMinus->Fill(ICVariable, ev.GetEventWeight());
      if(GenInfo && theGenLepton){
	  if(theGenLepton->at(0)->GetID() > 0) {
	    jSolutionsW jMCSolution;
	    jGenW = TLVConvert(myGenMatrixBin.the_GenW.at(0));
	    jGenLep = TLVConvert(theGenLepton->at(0));
	    jMCSolution = FindBoost(jGenLep, jGenW.Px(), jGenW.Py(), jGenW.Pz(), true, false, jGenW.M());
	    if(jMCSolution.realSolutions) {
	      int index = int( (jMCSolution.rightSol + 1.0) / 0.01 );
	      MC_CosThetaStar1Minus->Fill(jMCSolution.rightSol, ev.GetEventWeight());
	      RECO_ICVarMinus_LH->Fill(ICVariable,
                                       ev.GetEventWeight()
                                       * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,0)
                                       * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 0, 1));
	      RECO_ICVarMinus_RH->Fill(ICVariable,
                                       ev.GetEventWeight()
                                       * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,1)
                                       * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 1, 1));
	      RECO_ICVarMinus_LO->Fill(ICVariable,
                                       ev.GetEventWeight()
                                       * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,2)
                                       * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 2, 1));



	      //      if(pfMET.Pt() > mMETThresh) {
		RECO_ICVarPFMinus_LH->Fill(ICVariablePF,
                                           ev.GetEventWeight()
                                           * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,0)
                                           * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 0, 1));
		RECO_ICVarPFMinus_RH->Fill(ICVariablePF,
                                           ev.GetEventWeight()
                                           * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,1)
                                           * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 1, 1));
		RECO_ICVarPFMinus_LO->Fill(ICVariablePF,
                                           ev.GetEventWeight()
                                           * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,2)
                                           * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 2, 1));
		RECO_ICVarPFMinus_VertexReweighting_LH->Fill(ICVariablePF,
                                                             ev.GetEventWeight()
                                                             * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,0)
                                                             * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 0, 1)
                                                             * GetVertexReweightingElectron(ev.GetVertexSize()));
		RECO_ICVarPFMinus_VertexReweighting_RH->Fill(ICVariablePF,
                                                             ev.GetEventWeight()
                                                             * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,1)
                                                             * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 1, 1)
                                                             * GetVertexReweightingElectron(ev.GetVertexSize()));
		RECO_ICVarPFMinus_VertexReweighting_LO->Fill(ICVariablePF,
                                                             ev.GetEventWeight()
                                                             * CorrFactor(jGenW.Pt(), jGenW.Rapidity(),index,false,2)
                                                             * CorrFactorWeight(jGenW.Pt(), jGenW.Rapidity(), false, 2, 1)
                                                             * GetVertexReweightingElectron(ev.GetVertexSize()));

		// }


	    }
	  }
	}


      //      if(tcMET.Pt() > mMETThresh)
      //	RECO_ICVarTCMinus->Fill(ICVariableTC, ev.GetEventWeight());
	//      if(pfMET.Pt() > mMETThresh)
	RECO_ICVarPFMinus->Fill(ICVariablePF, ev.GetEventWeight());
	// if(ic5MET.Pt() > mMETThresh)
	//RECO_ICVarIC5Minus->Fill(ICVariableIC5, ev.GetEventWeight());
	//if(ak5MET.Pt() > mMETThresh)
	//RECO_ICVarAK5Minus->Fill(ICVariableAK5, ev.GetEventWeight());


    }

    RECO_CommonMHT->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
    RECO_LeptonPt->Fill(theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
    RECO_JetMultiplicity->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());
    RECO_LeptonMultiplicity->Fill(theRECOLepton.size(), ev.GetEventWeight());

    RECO_Tr->Fill(theRECOLepton.at(0)->GetTrkIsolation() /theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
    RECO_Ecal->Fill(theRECOLepton.at(0)->GetEcalIsolation() /theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
    RECO_Hcal->Fill(theRECOLepton.at(0)->GetCombIsolation() /theRECOLepton.at(0)->Pt(), ev.GetEventWeight());
    RECO_Com->Fill(theRECOLepton.at(0)->GetCombIsolation(), ev.GetEventWeight());
    RECO_Type->Fill(theRECOLepton.at(0)->GetType(), ev.GetEventWeight());

    float minDeltaR = 20;
    for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ ) {
      if (i == 0) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton.at(0))));
      else {
	if(fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton.at(0)))) < minDeltaR) minDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theRECOLepton.at(0))));

      }
    }
    RECO_DR->Fill(minDeltaR, ev.GetEventWeight());

    float Zmass = 0.0;
    if(GetRawLeptons(ev,mLeptonType).size()>1) {

      for (std::vector<Event::Lepton>::const_iterator iel = GetRawLeptons(ev,mLeptonType).begin();
           iel != GetRawLeptons(ev,mLeptonType).end(); ++iel) {
	float ZmassCurrent = ROOT::Math::VectorUtil::InvariantMass(*iel,*(theRECOLepton.at(0)));
	if (Zmass==0.0) Zmass=ZmassCurrent;
	if(fabs(ZmassCurrent-91.2) < (fabs(Zmass-91.2)))  Zmass=ZmassCurrent;
      }
    }
    RECO_2ndMass->Fill(Zmass,ev.GetEventWeight());

    if(GenInfo) {
      //check how many times real MC muon exists for RECO muon and when this happens, check the charge identification and the pt and eta widths
      if(theGenLepton && theGenLepton->size() == theRECOLepton.size()) {
	MC_RECO_LeptonMultMatch->Fill(1.0, ev.GetEventWeight());
	if(myGenMatrixBin.the_GenW.size() > 0) {
	  MC_RECO_MHTDiffProfile->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(), (myGenMatrixBin.the_GenW.at(0)->Pt() - ev.CommonMHT().Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
          MC_RECO_PFMHTDiffProfile->Fill(myGenMatrixBin.the_GenW.at(0)->Pt(),
                                         (myGenMatrixBin.the_GenW.at(0)->Pt() - pfMET.Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(),ev.GetEventWeight());
	  if(myGenMatrixBin.the_GenW.at(0)->Pt() > WPtResCut) {
	    MC_RECO_MHTDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - ev.CommonMHT().Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
	    MC_RECO_CaloMETDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - ev.CaloMET().Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());

	    //to ensure compatibility

	    //	    MC_RECO_TCMETDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - tcMET.Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
	    MC_RECO_PFMETDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - pfMET.Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
	    //MC_RECO_IC5METDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - ic5MET.Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());
	    //MC_RECO_AK5METDiff->Fill((myGenMatrixBin.the_GenW.at(0)->Pt() - ak5MET.Pt())/myGenMatrixBin.the_GenW.at(0)->Pt(), ev.GetEventWeight());

	    //	    RECO_MHTvsTCMET->Fill(ev.CommonMHT().Pt(), tcMET.Pt(), ev.GetEventWeight());
	    RECO_MHTvsPFMET->Fill(ev.CommonMHT().Pt(), pfMET.Pt(), ev.GetEventWeight());
	    RECO_MHTvsCaloMET->Fill(ev.CommonMHT().Pt(), ev.CaloMET().Pt(), ev.GetEventWeight());
	    //RECO_MHTvsAK5MET->Fill(ev.CommonMHT().Pt(), ak5MET.Pt(), ev.GetEventWeight());
	    //RECO_MHTvsIC5MET->Fill(ev.CommonMHT().Pt(), ic5MET.Pt(), ev.GetEventWeight());

	  }
	}
	MC_RECO_LeptonPtDiff->Fill((theGenLepton->at(0)->Pt() - theRECOLepton.at(0)->Pt())/theGenLepton->at(0)->Pt(), ev.GetEventWeight());
	MC_RECO_LeptonEtaDiff->Fill((theGenLepton->at(0)->Eta() - theRECOLepton.at(0)->Eta()), ev.GetEventWeight());

	//remember that a negatively charge muon has a positive ID and vice versa
	if((theGenLepton->at(0)->GetID() > 0 && theRECOLepton.at(0)->GetCharge() < 0) || (theGenLepton->at(0)->GetID() < 0 && theRECOLepton.at(0)->GetCharge() > 0)) MC_RECO_LeptonChargeId->Fill(1.0, ev.GetEventWeight());
	else MC_RECO_LeptonChargeId->Fill(0.0, ev.GetEventWeight());

      } else {
	MC_RECO_LeptonMultMatch->Fill(0.0, ev.GetEventWeight());
      }
    }

    //now fill the cos theta star distributions - first check for real solutions
    //jRECOSol = FindBoost(*(theRECOLepton.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), 0.0, false);
    jRECOSol = FindBoost(TLVConvert(theRECOLepton.at(0)), ev.CommonMHT().Px(), ev.CommonMHT().Py(), 0.0, false);

    if(jRECOSol.realSolutions) {
      if(theRECOLepton.at(0)->GetCharge()>0.0) {
	RECO_CosThetaStar1Sol1Plus->Fill(jRECOSol.sol1, ev.GetEventWeight());
	RECO_CosThetaStar1Sol2Plus->Fill(jRECOSol.sol2, ev.GetEventWeight());
      }else{
	RECO_CosThetaStar1Sol1Minus->Fill(jRECOSol.sol1, ev.GetEventWeight());
	RECO_CosThetaStar1Sol2Minus->Fill(jRECOSol.sol2, ev.GetEventWeight());
      }
    } else {
      //plot an "underflow" bin on these plots which will give an indication of the number of virtual solutions for each sample
      if(theRECOLepton.at(0)->GetCharge()>0.0) {
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
    ostrm << "Reco Level Polarisation plots: "
          << GetLeptonString(mLeptonType);
    return ostrm;
  }

void BasicPlots::BookHistos(){
  h_lep_combiso=new TH1D("h_lep_combiso","h_lep_combiso",200,0,5);
  h_lep_combiso->Sumw2();
  h_lep_hfcombiso=new TH1D("h_lep_hfcombiso","h_lep_hfcombiso",200,0,5);
  h_lep_hfcombiso->Sumw2();
  h_lep_fakecombiso=new TH1D("h_lep_fakecombiso","h_lep_fakecombiso",200,0,5);
  h_lep_fakecombiso->Sumw2();
  h_lep_photcombiso=new TH1D("h_lep_photcombiso","h_lep_photcombiso",200,0,5);
  h_lep_photcombiso->Sumw2();
  h_lep_phot2combiso=new TH1D("h_lep_phot2combiso","h_lep_phot2combiso",200,0,5);
  h_lep_phot2combiso->Sumw2();
  h_mht=new TH1D("h_mht","h_mht",100,0,500);
  h_mht->Sumw2();
  h_comlep_combiso=new TH1D("h_comlep_combiso","h_comlep_combiso",1000,0,5);
  h_comlep_combiso->Sumw2();
  h_comlep_fake_combiso=new TH1D("h_comlep_fake_combiso","h_comlep_fake_combiso",200,0,5);
  h_comlep_fake_combiso->Sumw2();
  h_comlep_hf_combiso=new TH1D("h_comlep_hf_combiso","h_comlep_hf_combiso",200,0,5);
  h_comlep_hf_combiso->Sumw2();
  h_comlep_phot_combiso=new TH1D("h_comlep_phot_combiso","h_comlep_phot_combiso",200,0,5);
  h_comlep_phot_combiso->Sumw2();
  h_comlep_phot2_combiso=new TH1D("h_comlep_phot2_combiso","h_comlep_phot2_combiso",200,0,5);
  h_comlep_phot2_combiso->Sumw2();
  h_comlep_pt = new TH1D("h_comlep_pt", "h_comlep_pt", 1000, 0, 1000);
  h_lep_EoverPin=new TH1D("h_lep_EoverPin","h_lep_EoverPin",100,0,10);
  h_lep_EoverPout=new TH1D("h_lep_EoverPout","h_lep_EoverPout",100,0,10);
  h_comlep_EoverPout=new TH1D("h_comlep_EoverPout","h_comlep_EoverPout",100,0,10);
  h_lep_EoverPin->Sumw2();
  h_lep_EoverPout->Sumw2();
  h_comlep_EoverPout->Sumw2();

  h_electron_mva = new TH1D("h_electron_mva", "h_electron_mva", 100,-2,2);
  h_electron_mva->Sumw2();

  h_ele_d0=new TH1D("h_ele_d0","",1000,0.,10.);

  h_dilepton_mass = new TH1D("h_dilepton_mass", "",1000,0.,500.);
  h_dilepton_charge = new TH1D("h_dilepton_charge","", 10, -5, 5);
  // barrel
  h_barrel_EoverPin=new TH1D("h_barrel_EoverPin","h_barrel_EoverPin",100,0,10); h_barrel_EoverPin->Sumw2();
  h_barrel_fbrem=new TH1D("h_barrel_fbrem","h_barrel_fbrem",100,0,1);
  h_barrel_fbrem->Sumw2();

  h_barrel_HoE=new TH1D("h_barrel_HoE","",10000,0.,1.); h_barrel_HoE->Sumw2();
  h_barrel_DeltaEtaAtVtx=new TH1D("h_barrel_DeltaEtaAtVtx","",100,0.,0.025);h_barrel_DeltaEtaAtVtx->Sumw2();
  h_barrel_DeltaPhiAtVtx=new TH1D("h_barrel_DeltaPhiAtVtx","",1000,0.,0.1);h_barrel_DeltaPhiAtVtx->Sumw2();
  h_barrel_SigmaIetaIeta=new TH1D("h_barrel_SigmaIetaIeta","",1000,0.,0.05);h_barrel_SigmaIetaIeta->Sumw2();

  h_barrel_TrkIso=new TH1D("h_barrel_TrkIso","",1000,0.,50.);h_barrel_TrkIso->Sumw2();
  h_barrel_EcalIso=new TH1D("h_barrel_EcalIso","",1000,0.,50.);h_barrel_EcalIso->Sumw2();
  h_barrel_HcalIso=new TH1D("h_barrel_HcalIso","",1000,0.,50.);h_barrel_HcalIso->Sumw2();

  h_barrel_TrkIso_vsHT=new TH2D("h_barrel_TrkIso_vsHT","",1000,0.,50.,1000,0.,1000.);h_barrel_TrkIso_vsHT->Sumw2();
  h_barrel_EcalIso_vsHT=new TH2D("h_barrel_EcalIso_vsHT","",1000,0.,50.,1000,0.,1000.);h_barrel_EcalIso_vsHT->Sumw2();
  h_barrel_HcalIso_vsHT=new TH2D("h_barrel_HcalIso_vsHT","",1000,0.,50.,1000,0.,1000.);h_barrel_HcalIso_vsHT->Sumw2();
  h_barrel_CombRelIso_vsHT=new TH2D("h_barrel_CombRelIso_vsHT","",1000,0.,10.,1000,0.,1000.);h_barrel_CombRelIso_vsHT->Sumw2();
  h_barrel_TrkIso_vsMHT=new TH2D("h_barrel_TrkIso_vsMHT","",1000,0.,50.,1000,0.,1000.);h_barrel_TrkIso_vsMHT->Sumw2();
  h_barrel_EcalIso_vsMHT=new TH2D("h_barrel_EcalIso_vsMHT","",1000,0.,50.,1000,0.,1000.);h_barrel_EcalIso_vsMHT->Sumw2();
  h_barrel_HcalIso_vsMHT=new TH2D("h_barrel_HcalIso_vsMHT","",1000,0.,50.,1000,0.,1000.);h_barrel_HcalIso_vsMHT->Sumw2();
  h_barrel_CombRelIso_vsMHT=new TH2D("h_barrel_CombRelIso_vsMHT","",1000,0.,10.,1000,0.,1000.);h_barrel_CombRelIso_vsMHT->Sumw2();

  //endcap
  h_endcap_EoverPin=new TH1D("h_endcap_EoverPin","h_endcap_EoverPin",100,0,10); h_endcap_EoverPin->Sumw2();
  h_endcap_fbrem=new TH1D("h_endcap_fbrem","h_endcap_fbrem",100,0,1);
  h_endcap_fbrem->Sumw2();

  h_endcap_HoE=new TH1D("h_endcap_HoE","",10000,0.,1.); h_endcap_HoE->Sumw2();
  h_endcap_DeltaEtaAtVtx=new TH1D("h_endcap_DeltaEtaAtVtx","",100,0.,0.025);h_endcap_DeltaEtaAtVtx->Sumw2();
  h_endcap_DeltaPhiAtVtx=new TH1D("h_endcap_DeltaPhiAtVtx","",1000,0.,0.1);h_endcap_DeltaPhiAtVtx->Sumw2();
  h_endcap_SigmaIetaIeta=new TH1D("h_endcap_SigmaIetaIeta","",1000,0.,0.05);h_endcap_SigmaIetaIeta->Sumw2();

  h_endcap_TrkIso=new TH1D("h_endcap_TrkIso","",1000,0.,50.);h_endcap_TrkIso->Sumw2();
  h_endcap_EcalIso=new TH1D("h_endcap_EcalIso","",1000,0.,50.);h_endcap_EcalIso->Sumw2();
  h_endcap_HcalIso=new TH1D("h_endcap_HcalIso","",1000,0.,50.);h_endcap_HcalIso->Sumw2();

  h_endcap_TrkIso_vsHT=new TH2D("h_endcap_TrkIso_vsHT","",1000,0.,50.,1000,0.,1000.);h_endcap_TrkIso_vsHT->Sumw2();
  h_endcap_EcalIso_vsHT=new TH2D("h_endcap_EcalIso_vsHT","",1000,0.,50.,1000,0.,1000.);h_endcap_EcalIso_vsHT->Sumw2();
  h_endcap_HcalIso_vsHT=new TH2D("h_endcap_HcalIso_vsHT","",1000,0.,50.,1000,0.,1000.);h_endcap_HcalIso_vsHT->Sumw2();
  h_endcap_CombRelIso_vsHT=new TH2D("h_endcap_CombRelIso_vsHT","",1000,0.,10.,1000,0.,1000.);h_barrel_CombRelIso_vsHT->Sumw2();
  h_endcap_TrkIso_vsMHT=new TH2D("h_endcap_TrkIso_vsMHT","",1000,0.,50.,1000,0.,1000.);h_endcap_TrkIso_vsMHT->Sumw2();
  h_endcap_EcalIso_vsMHT=new TH2D("h_endcap_EcalIso_vsMHT","",1000,0.,50.,1000,0.,1000.);h_endcap_EcalIso_vsMHT->Sumw2();
  h_endcap_HcalIso_vsMHT=new TH2D("h_endcap_HcalIso_vsMHT","",1000,0.,50.,1000,0.,1000.);h_endcap_HcalIso_vsMHT->Sumw2();
  h_endcap_CombRelIso_vsMHT=new TH2D("h_endcap_CombRelIso_vsMHT","",1000,0.,10.,1000,0.,1000.);h_endcap_CombRelIso_vsMHT->Sumw2();

  h_dcot = new TH1D("h_dcot", "", 1000, 0, 1); h_dcot->Sumw2();
  h_dist = new TH1D("h_dist", "", 1000, 0, 1); h_dist->Sumw2();
  h_partner_track_expected = new TH1D("h_partner_track_expected", "", 100, 0, 100);
  h_MT = new TH1D("h_MT", "", 1000, 0, 1000); h_MT->Sumw2();
  h_pfMET = new TH1D("h_pfMET", "", 1000, 0, 1000); h_pfMET->Sumw2();
}

  double BasicPlots::getCorrD0(double d0, double phi, double X, double Y ) {
    return d0 - X * sin(phi) + Y * cos(phi);

  }

bool BasicPlots::Process(Event::Data &ev){

  h_mht->Fill(ev.CommonMHT().Pt(),ev.GetEventWeight());

  h_MT->Fill(ev.CommonMT(), ev.GetEventWeight());
  h_pfMET->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
  const std::vector<Event::Lepton> & leps = GetRawLeptons(ev,mLeptonType);
  for(std::vector<Event::Lepton>::const_iterator ii=leps.begin();
      ii!=leps.end();
      ++ii){
    h_lep_combiso->Fill(ii->GetCombIsolation(),ev.GetEventWeight());
  }

  const std::vector<const Event::Lepton*> & common_leps=ev.LD_CommonElectrons().accepted;
  for(std::vector<const Event::Lepton*>::const_iterator ii=common_leps.begin();
      ii!=common_leps.end();
      ++ii){
    if(ii - common_leps.begin() > 1) break;
    h_comlep_combiso->Fill((*ii)->GetCombIsolation(),ev.GetEventWeight());
    h_comlep_pt->Fill((*ii)->Pt(), ev.GetEventWeight());
    if(mDoGen){
    int lepType=ExtendedType(ev,*ii,mLeptonType);
    if(lepType < 0) h_comlep_fake_combiso->Fill((*ii)->GetCombIsolation(),ev.GetEventWeight());
    else if(lepType==10) h_comlep_hf_combiso->Fill((*ii)->GetCombIsolation(),ev.GetEventWeight());
    else if(lepType==22) h_comlep_phot_combiso->Fill((*ii)->GetCombIsolation(),ev.GetEventWeight());
    else if(lepType==-22) h_comlep_phot2_combiso->Fill((*ii)->GetCombIsolation(),ev.GetEventWeight());
    }
    int idx=(*ii)->GetIndex();

    // double elecD0=getCorrD0(ev.GetElectronD0(idx), (*ii)->Phi(), ev.BeamSpotPosition()->x(),
    //     		    ev.BeamSpotPosition()->y());

    // h_ele_d0->Fill(elecD0, ev.GetEventWeight());

    try{
      h_electron_mva->Fill(ev.GetElectronMva((*ii)->GetIndex()),ev.GetEventWeight());
    }
    catch(std::exception & e){
    }
      h_dcot->Fill(ev.GetElectronDCot((*ii)->GetIndex()), ev.GetEventWeight());
      h_dist->Fill(ev.GetElectronDist((*ii)->GetIndex()), ev.GetEventWeight());
      h_partner_track_expected->Fill(
          ev.GetElectronPartnerTrackTrackerExpectedHitsInner((*ii)->GetIndex()),
          ev.GetEventWeight());

    if (fabs((*ii)->Eta()) < 1.4442) {

      h_barrel_EoverPin->Fill(ev.GetElectronESuperClusterOverP(idx),ev.GetEventWeight());
      h_barrel_fbrem->Fill(ev.GetElectronFbrem(idx),ev.GetEventWeight());

      h_barrel_HoE->Fill(ev.GetElectronHoE(idx),ev.GetEventWeight());
      h_barrel_DeltaEtaAtVtx->Fill(fabs(ev.GetElectronDeltaEtaAtVtx(idx)),ev.GetEventWeight());
      h_barrel_DeltaPhiAtVtx->Fill(fabs(ev.GetElectronDeltaPhiAtVtx(idx)),ev.GetEventWeight());
      h_barrel_SigmaIetaIeta->Fill(ev.GetElectronSigmaIetaIeta(idx),ev.GetEventWeight());

      h_barrel_TrkIso->Fill( (*ii)->GetTrkIsolation(),ev.GetEventWeight());
      h_barrel_EcalIso->Fill( (*ii)->GetEcalIsolation(),ev.GetEventWeight());
      h_barrel_HcalIso->Fill( (*ii)->GetHcalIsolation(),ev.GetEventWeight());

      h_barrel_TrkIso_vsHT->Fill( (*ii)->GetTrkIsolation(),ev.CommonHT(),ev.GetEventWeight());
      h_barrel_EcalIso_vsHT->Fill( (*ii)->GetEcalIsolation(),ev.CommonHT(),ev.GetEventWeight());
      h_barrel_HcalIso_vsHT->Fill( (*ii)->GetHcalIsolation(),ev.CommonHT(),ev.GetEventWeight());
      h_barrel_CombRelIso_vsHT->Fill( (*ii)->GetCombIsolation(),ev.CommonHT(),ev.GetEventWeight());

      h_barrel_TrkIso_vsMHT->Fill( (*ii)->GetTrkIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());
      h_barrel_EcalIso_vsMHT->Fill( (*ii)->GetEcalIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());
      h_barrel_HcalIso_vsMHT->Fill( (*ii)->GetHcalIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());
      h_barrel_CombRelIso_vsMHT->Fill( (*ii)->GetCombIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());

    }
    else if (fabs((*ii)->Eta()) > 1.560) {

      h_endcap_EoverPin->Fill(ev.GetElectronESuperClusterOverP(idx),ev.GetEventWeight());
      h_endcap_fbrem->Fill(ev.GetElectronFbrem(idx),ev.GetEventWeight());

      h_endcap_HoE->Fill(ev.GetElectronHoE(idx),ev.GetEventWeight());
      h_endcap_DeltaEtaAtVtx->Fill(fabs(ev.GetElectronDeltaEtaAtVtx(idx)),ev.GetEventWeight());
      h_endcap_DeltaPhiAtVtx->Fill(fabs(ev.GetElectronDeltaPhiAtVtx(idx)),ev.GetEventWeight());
      h_endcap_SigmaIetaIeta->Fill(ev.GetElectronSigmaIetaIeta(idx),ev.GetEventWeight());

      h_endcap_TrkIso->Fill( (*ii)->GetTrkIsolation(),ev.GetEventWeight());
      h_endcap_EcalIso->Fill( (*ii)->GetEcalIsolation(),ev.GetEventWeight());
      h_endcap_HcalIso->Fill( (*ii)->GetHcalIsolation(),ev.GetEventWeight());

      h_endcap_TrkIso_vsHT->Fill( (*ii)->GetTrkIsolation(),ev.CommonHT(),ev.GetEventWeight());
      h_endcap_EcalIso_vsHT->Fill( (*ii)->GetEcalIsolation(),ev.CommonHT(),ev.GetEventWeight());
      h_endcap_HcalIso_vsHT->Fill( (*ii)->GetHcalIsolation(),ev.CommonHT(),ev.GetEventWeight());
      h_endcap_CombRelIso_vsHT->Fill( (*ii)->GetCombIsolation(),ev.CommonHT(),ev.GetEventWeight());

      h_endcap_TrkIso_vsMHT->Fill( (*ii)->GetTrkIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());
      h_endcap_EcalIso_vsMHT->Fill( (*ii)->GetEcalIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());
      h_endcap_HcalIso_vsMHT->Fill( (*ii)->GetHcalIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());
      h_endcap_CombRelIso_vsMHT->Fill( (*ii)->GetCombIsolation(),ev.CommonMHT().Pt(),ev.GetEventWeight());

    }
  }

  if(common_leps.size() == 2){
	h_dilepton_mass->Fill( (*common_leps[0] + *common_leps[1]).M(),ev.GetEventWeight());
	h_dilepton_charge->Fill( common_leps[0]->GetCharge() + common_leps[1]->GetCharge(),ev.GetEventWeight());
  }
  return true;
}

TriggerEffPlot::TriggerEffPlot(const std::string & folder):
    mFolderName(folder)
{}

TriggerEffPlot::~TriggerEffPlot(){}

void TriggerEffPlot::Start(Event::Data & ev){
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
  printed =false;
}

void TriggerEffPlot::BookHistos(){
  h_trigger_eff=new TH1D("h_trigger_eff","",500,0,500);
}


bool TriggerEffPlot::Process(Event::Data & ev){
  int idx=0;
  for(std::map<std::string,bool>::const_iterator it2 =ev.hlt()->begin();
      it2!=ev.hlt()->end(); ++it2,++idx){
    if(it2->second) h_trigger_eff->Fill(idx,ev.GetEventWeight());
   }
  if(printed) return true;
  for(std::map<std::string,bool>::const_iterator it2 =ev.hlt()->begin();
      it2!=ev.hlt()->end(); ++it2){
    std::cout << it2->first << " = " << it2->second << std::endl;
   }
  printed = true;
  return true;
}

std::ostream & TriggerEffPlot::Description(std::ostream & ostrm){
  ostrm << "TriggerEffPlot " << mFolderName;
  return ostrm;
}

ControlPlots::ControlPlots(const std::string folder,
                           const Utils::ParameterSet & ps):
mFolderName(folder),
mPtCut(ps.Get<double>("PtCut")),
                                mEtaCut(ps.Get<double>("EtaCut")),
                                mWPtCut(ps.Get<double>("WPtCut")),
                                mMTCut(ps.Get<double>("MTCut"))
{
  mFilter = new Alex::CustomEleId(ps);
}

ControlPlots::~ControlPlots(){}

void ControlPlots::Start(Event::Data & ev){
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
  mFilter->Init(ev);
}

void ControlPlots::BookHistos(){
  TH1::SetDefaultSumw2(kTRUE);
  h_lp_plus = new TH1D("RECO_ICVarPFPlus", "", 500, -2.5, 2.5);
  h_wpt_plus = new TH1D("RECO_WPtPlus", "", 1000, 0, 500);
  h_elept_plus = new TH1D("RECO_ElePtPlus", "", 1000, 0, 500);
  h_eleeta_plus = new TH1D("RECO_EleEtaPlus", "", 1000, -2.5, 2.5);
  h_elephi_plus = new TH1D("RECO_ElePhiPlus", "", 1000, -10, 10);
  h_pfmt_plus = new TH1D("RECO_MTPlus", "", 1000, 0, 500);
  h_pfmet_plus = new TH1D("RECO_pfMETPlus", "", 1000, 0, 500);
  h2d_nvertices_lp_plus = new TH2D("RECO_nVertices_ICVarPFPlus", "", 50, 0, 50, 500, -2.5, 2.5);

  h_lp_minus = new TH1D("RECO_ICVarPFMinus", "", 500, -2.5, 2.5);
  h_wpt_minus = new TH1D("RECO_WPtMinus", "", 1000, 0, 500);
  h_elept_minus = new TH1D("RECO_ElePtMinus", "", 1000, 0, 500);
  h_eleeta_minus = new TH1D("RECO_EleEtaMinus", "", 1000, -2.5, 2.5);
  h_elephi_minus = new TH1D("RECO_ElePhiMinus", "", 1000, -10, 10);
  h_pfmt_minus = new TH1D("RECO_MTMinus", "", 1000, 0, 500);
  h_pfmet_minus = new TH1D("RECO_pfMETMinus", "", 1000, 0, 500);
  h2d_nvertices_lp_minus = new TH2D("RECO_nVertices_ICVarPFMinus", "", 50, 0, 50, 500, -2.5, 2.5);

  h_lp_all = new TH1D("RECO_ICVarPFAll", "", 500, -2.5, 2.5);
  h_wpt_all = new TH1D("RECO_WPtAll", "", 1000, 0, 500);
  h_elept_all = new TH1D("RECO_ElePtAll", "", 1000, 0, 500);
  h_eleeta_all = new TH1D("RECO_EleEtaAll", "", 1000, -2.5, 2.5);
  h_elephi_all = new TH1D("RECO_ElePhiAll", "", 1000, -10, 10);
  h_pfmt_all = new TH1D("RECO_MTAll", "", 1000, 0, 500);
  h_pfmet_all = new TH1D("RECO_pfMETAll", "", 1000, 0, 500);
  h2d_nvertices_lp_all = new TH2D("RECO_nVertices_ICVarPFAll", "", 50, 0, 50, 500, -2.5, 2.5);
  TH1::SetDefaultSumw2(kFALSE);

}

bool ControlPlots::Process(Event::Data & ev){
  std::vector<const Event::Lepton*> passed;

  // Get the anti-selected electrons
  for(std::vector<Event::Lepton>::const_iterator iel = ev.LD_Electrons().begin();
      iel != ev.LD_Electrons().end();
      ++iel){
    if(iel->Pt() > mPtCut &&
       fabs(iel->Eta()) < mEtaCut &&
       mFilter->Apply(&*iel)) passed.push_back(&*iel);
    }
  if(passed.size() == 0) return true;

  // Calculate W Pt
  ICF_LorentzV w =  (ev.PFMET() + *(passed[0]));
  if(!(w.Pt() > mWPtCut)) return true;
  // Calculate pfMT
  double mt = sqrt(2.0 * ev.PFMET().Pt() * passed.at(0)->Pt() *
                     (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(passed.at(0)),
                                                                 ev.PFMET()))));
  if(!(mt > mMTCut)) return true;

  double lp = ((passed.at(0)->Px() * w.Px()) + (passed.at(0)->Py() * w.Py())) / (w.Pt() * w.Pt());

  // Plots
  if(passed[0]->GetCharge() >0){
    h_lp_plus->Fill(lp, ev.GetEventWeight());
    h_pfmet_plus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
    h_pfmt_plus->Fill(mt, ev.GetEventWeight());
    h_wpt_plus->Fill(w.Pt(), ev.GetEventWeight());
    h_elept_plus->Fill(passed[0]->Pt(), ev.GetEventWeight());
    h_eleeta_plus->Fill(passed[0]->Eta(), ev.GetEventWeight());
    h_elephi_plus->Fill(passed[0]->Phi(), ev.GetEventWeight());
    h2d_nvertices_lp_plus->Fill(ev.GetVertexSize(), lp, ev.GetEventWeight());
  }
  else{
    h_lp_minus->Fill(lp, ev.GetEventWeight());
    h_pfmet_minus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
    h_pfmt_minus->Fill(mt, ev.GetEventWeight());
    h_wpt_minus->Fill(w.Pt(), ev.GetEventWeight());
    h_elept_minus->Fill(passed[0]->Pt(), ev.GetEventWeight());
    h_eleeta_minus->Fill(passed[0]->Eta(), ev.GetEventWeight());
    h_elephi_minus = new TH1D("RECO_ElePhiMinus", "", 1000, -10, 10);
    h2d_nvertices_lp_minus->Fill(ev.GetVertexSize(), lp, ev.GetEventWeight());
  }
  h_lp_all->Fill(lp, ev.GetEventWeight());
  h_pfmet_all->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
  h_pfmt_all->Fill(mt, ev.GetEventWeight());
  h_wpt_all->Fill(w.Pt(), ev.GetEventWeight());
  h_elept_all->Fill(passed[0]->Pt(), ev.GetEventWeight());
  h_eleeta_all->Fill(passed[0]->Eta(), ev.GetEventWeight());
  h_elephi_all->Fill(passed[0]->Phi(), ev.GetEventWeight());
  h2d_nvertices_lp_all->Fill(ev.GetVertexSize(), lp, ev.GetEventWeight());

  return true;
}

std::ostream & ControlPlots::Description(std::ostream & ostrm){
  ostrm << "Control Plots";
  return ostrm;
}


DataMCPlots::DataMCPlots(const std::string folder):
mFolderName(folder)
{}

DataMCPlots::~DataMCPlots(){}

void DataMCPlots::Start(Event::Data & ev){
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
}

void DataMCPlots::BookHistos(){
  TH1::SetDefaultSumw2(kTRUE);
  h_lp_plus = new TH1D("RECO_ICVarPFPlus", "", 500, -2.5, 2.5);
  h_wpt_plus = new TH1D("RECO_WPtPlus", "", 1000, 0, 500);
  h_elept_plus = new TH1D("RECO_ElePtPlus", "", 1000, 0, 500);
  h_eleeta_plus = new TH1D("RECO_EleEtaPlus", "", 1000, -2.5, 2.5);
  h_elephi_plus = new TH1D("RECO_ElePhiPlus", "", 1000, -10, 10);
  h_pfmt_plus = new TH1D("RECO_MTPlus", "", 1000, 0, 500);
  h_pfmet_plus = new TH1D("RECO_pfMETPlus", "", 1000, 0, 500);
  h_combiso_plus = new TH1D("RECO_CombIsoPlus", "", 1000, 0, 5);
  h2d_nvertices_lp_plus = new TH2D("RECO_nVertices_ICVarPFPlus", "", 50, 0, 50, 500, -2.5, 2.5);
  h_nvertices_plus = new TH1D("RECO_nVerticesPlus", "", 50, 0, 50);

  h_lp_minus = new TH1D("RECO_ICVarPFMinus", "", 500, -2.5, 2.5);
  h_wpt_minus = new TH1D("RECO_WPtMinus", "", 1000, 0, 500);
  h_elept_minus = new TH1D("RECO_ElePtMinus", "", 1000, 0, 500);
  h_eleeta_minus = new TH1D("RECO_EleEtaMinus", "", 1000, -2.5, 2.5);
  h_elephi_minus = new TH1D("RECO_ElePhiMinus", "", 1000, -10, 10);
  h_pfmt_minus = new TH1D("RECO_MTMinus", "", 1000, 0, 500);
  h_pfmet_minus = new TH1D("RECO_pfMETMinus", "", 1000, 0, 500);
  h_combiso_minus = new TH1D("RECO_CombIsoMinus", "", 1000, 0, 5);
  h2d_nvertices_lp_minus = new TH2D("RECO_nVertices_ICVarPFMinus", "", 50, 0, 50, 500, -2.5, 2.5);
  h_nvertices_minus = new TH1D("RECO_nVerticesMinus", "", 50, 0, 50);

  h_lp_all = new TH1D("RECO_ICVarPFAll", "", 500, -2.5, 2.5);
  h_wpt_all = new TH1D("RECO_WPtAll", "", 1000, 0, 500);
  h_elept_all = new TH1D("RECO_ElePtAll", "", 1000, 0, 500);
  h_eleeta_all = new TH1D("RECO_EleEtaAll", "", 1000, -2.5, 2.5);
  h_elephi_all = new TH1D("RECO_ElePhiAll", "", 1000, -10, 10);
  h_pfmt_all = new TH1D("RECO_MTAll", "", 1000, 0, 500);
  h_pfmet_all = new TH1D("RECO_pfMETAll", "", 1000, 0, 500);
  h_combiso_all = new TH1D("RECO_CombIsoAll", "", 1000, 0, 5);
  h2d_nvertices_lp_all = new TH2D("RECO_nVertices_ICVarPFAll", "", 50, 0, 50, 500, -2.5, 2.5);
  h_nvertices_all = new TH1D("RECO_nVerticesAll", "", 50, 0, 50);
  TH1::SetDefaultSumw2(kFALSE);

}

bool DataMCPlots::Process(Event::Data & ev){
  const std::vector<const Event::Lepton*> & passed = ev.LD_CommonElectrons().accepted;
  if(passed.size() < 1) return true;
  // Calculate W Pt
  // NOTE: We use raw electron 4vector here to remove transparency corrections
  // since they won't be in the pfMET.
  ICF_LorentzV raw_eli = (ev.electronP4()->at(passed[0]->GetIndex()));
  ICF_LorentzV w =  (ev.PFMET() + raw_eli);

  // Calculate pfMT
  double mt = sqrt(2.0 * ev.PFMET().Pt() * passed.at(0)->Pt() *
                     (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(passed.at(0)),
                                                                 ev.PFMET()))));

  double lp = ((passed.at(0)->Px() * w.Px()) + (passed.at(0)->Py() * w.Py())) / (w.Pt() * w.Pt());


  // Plots
  if(passed[0]->GetCharge() >0){
    h_lp_plus->Fill(lp, ev.GetEventWeight());
    h_pfmet_plus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
    h_pfmt_plus->Fill(mt, ev.GetEventWeight());
    h_wpt_plus->Fill(w.Pt(), ev.GetEventWeight());
    h_elept_plus->Fill(passed[0]->Pt(), ev.GetEventWeight());
    h_eleeta_plus->Fill(passed[0]->Eta(), ev.GetEventWeight());
    h_elephi_plus->Fill(passed[0]->Phi(), ev.GetEventWeight());
    h2d_nvertices_lp_plus->Fill(ev.GetVertexSize(), lp, ev.GetEventWeight());
    h_nvertices_plus->Fill(ev.GetVertexSize(), ev.GetEventWeight());
    h_combiso_plus->Fill(passed[0]->GetCombIsolation(), ev.GetEventWeight());
  }
  else{
    h_lp_minus->Fill(lp, ev.GetEventWeight());
    h_pfmet_minus->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
    h_pfmt_minus->Fill(mt, ev.GetEventWeight());
    h_wpt_minus->Fill(w.Pt(), ev.GetEventWeight());
    h_elept_minus->Fill(passed[0]->Pt(), ev.GetEventWeight());
    h_eleeta_minus->Fill(passed[0]->Eta(), ev.GetEventWeight());
    h_elephi_minus->Fill(passed[0]->Phi(), ev.GetEventWeight());
    h2d_nvertices_lp_minus->Fill(ev.GetVertexSize(), lp, ev.GetEventWeight());
    h_nvertices_minus->Fill(ev.GetVertexSize(), ev.GetEventWeight());
    h_combiso_minus->Fill(passed[0]->GetCombIsolation(), ev.GetEventWeight());
  }
  h_lp_all->Fill(lp, ev.GetEventWeight());
  h_pfmet_all->Fill(ev.PFMET().Pt(), ev.GetEventWeight());
  h_pfmt_all->Fill(mt, ev.GetEventWeight());
  h_wpt_all->Fill(w.Pt(), ev.GetEventWeight());
  h_elept_all->Fill(passed[0]->Pt(), ev.GetEventWeight());
  h_eleeta_all->Fill(passed[0]->Eta(), ev.GetEventWeight());
  h_elephi_all->Fill(passed[0]->Phi(), ev.GetEventWeight());
  h2d_nvertices_lp_all->Fill(ev.GetVertexSize(), lp, ev.GetEventWeight());
  h_nvertices_all->Fill(ev.GetVertexSize(), ev.GetEventWeight());
  h_combiso_all->Fill(passed[0]->GetCombIsolation(), ev.GetEventWeight());
  return true;
}

std::ostream & DataMCPlots::Description(std::ostream & ostrm){
  ostrm << "DataMC Plots";
  return ostrm;
}


DebuggingPlots::DebuggingPlots(const std::string folder):
mFolderName(folder)
{}

DebuggingPlots::~DebuggingPlots(){}

void DebuggingPlots::Start(Event::Data & ev){
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
}

void DebuggingPlots::BookHistos(){
  TH1::SetDefaultSumw2(kTRUE);
  kfCharge = new TH1D("kfCharge", "", 10, -5, +5);
  scCharge = new TH1D("scCharge", "", 10, -5, +5);
  gsfCharge = new TH1D("gsfCharge", "", 10, -5, +5);
  TH1::SetDefaultSumw2(kFALSE);

}

bool DebuggingPlots::Process(Event::Data & ev){
  if(ev.LD_CommonElectrons().accepted.size() < 1) return true;
  int ele_idx = ev.LD_CommonElectrons().accepted[0]->GetIndex();
  gsfCharge->Fill(ev.electronCharge()->at(ele_idx));
  kfCharge->Fill(ev.electronKFCharge()->at(ele_idx));
  scCharge->Fill(ev.electronSCCharge()->at(ele_idx));
  return true;
}

std::ostream & DebuggingPlots::Description(std::ostream & ostrm){
  ostrm << "DataMC Plots";
  return ostrm;
}


}
