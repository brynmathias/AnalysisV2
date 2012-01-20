#include <boost/python.hpp>
#include "CustomEleID.hh"
#include "CustomMuID.hh"
#include "LeptonicOps.hh"
#include "LeptonicFilters.hh"
#include "LeptonicPlottingOps.hh"
#include "AnalysisTree.hh"
#include "AnalysisTree_HighPt.hh"
#include "CountsAndBSMGrids.hh"
#include "Utils.hh"
#include "Lepton.hh"
#include "SystematicsPlots.hh"
#include "ANplots.hh"
#include "Zplots.hh"
#include "JetFilters.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libOneLepton) { 
 class_<Operation::PTlepCut, bases<Operation::_Base> >("OP_PTlepCut",init<float,float>() );
 class_<Operation::DphiPTW_muCut, bases<Operation::_Base> >("OP_DphiPTW_muCut",init<float>() );

 class_<Operation::SumPTlepCut, bases<Operation::_Base> >("OP_SumPTlepCut",init<float,float>() );
 class_<Operation::PFMETCutBin, bases<Operation::_Base> >("OP_PFMETCutBin",init<float,float>() );
 class_<Operation::UnCorLeadCut, bases<Operation::_Base> >("OP_UnCorLeadJetCut",init<float>() );
 class_<OneLepton::EleJetDRFilter, bases<Compute::ObjectFilter<Event::Jet> > >("EleJetDRFilter",
									   init<double>());
 class_<Operation::MuonCheck, bases<Operation::_Base > >("OP_MuonCheck");
 
 class_<OneLepton::MuonJetDRFilter, bases<Compute::ObjectFilter<Event::Jet> > >("MuonJetDRFilter",
										init<double, const Utils::ParameterSet &>());
 class_<OneLepton::LepMinIsoFilter, bases<Compute::ObjectFilter<Event::Lepton> > >("LepMinIsoFilter",
										   init<double>());
 
 class_<OneLepton::JESCorrectionsFromFile, bases<Compute::ObjectFilter<Event::Jet> > >("JESCorrectionsFromFile",
										       init<bool, std::string>());

 class_<OneLepton::LooseEleId, bases<Compute::ObjectFilter<Event::Lepton> > >("LooseEleId");
 class_<OneLepton::CustomEleIdRA4Sync, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomEleIdRA4Sync",init<const Utils::ParameterSet &>());

  class_<OneLepton::CustomMuId, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomMuId",init<float,int,int>());
  class_<OneLepton::CustomVBTFMuID, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomVBTFMuID",init<const Utils::ParameterSet &>());


  class_<Operation::HTPTCut, bases<Operation::_Base> >("OP_HTPTCut",
						       init<float,float>());
  class_<Operation::HTlepCut, bases<Operation::_Base> >("RECO_LeptonicHTCut",
						     init<float>());

  class_<Operation::LeptonicAlphaTCut, bases<Operation::_Base> >("OP_LeptonicAlphaTCut",
							       init<float>());
  class_<Operation::GenNumberLepCut, bases<Operation::_Base> >("OP_GenNumberLepCut",							       init<int>());
  class_<Operation::PrintAlphaTEvents, bases<Operation::_Base> >("PrintAlphaTEvents");
  class_<Operation::UpperMuPtCut, bases<Operation::_Base> >("OP_UpperMuPtCut",init<float>() );
  class_<Operation::UpperElePtCut, bases<Operation::_Base> >("OP_UpperElePtCut",init<float>() );
  class_<Operation::MuJetVeto, bases<Operation::_Base> >("OP_MuJetVeto",init<float>());

  class_<Operation::PFMHTCut,bases<Operation::_Base> >("OP_PFMHTCut",init<float>());
  class_<Operation::mPFMHTCut,bases<Operation::_Base> >("OP_mPFMHTCut",init<float>());

  class_<Operation::PFMeffWCut,bases<Operation::_Base> >("OP_PFMeffWCut",init<const std::string &,float>());

  class_<Operation::PFLPCut,bases<Operation::_Base> >("OP_PFLPCut",init<float>());

  class_<Operation::LeptonicPlottingOps, bases<Operation::_Base> >("LeptonicPlots",
								   init <const std::string &,
								   const Utils::ParameterSet&>() );
  class_<Operation::Zplots, bases<Operation::_Base> >("OP_Zplots",init <const std::string &>() );
  class_<Operation::ANplots, bases<Operation::_Base> >("OP_ANplots",init <const std::string &>() );
 // class_<Operation::ResultsPlots, bases<Operation::_Base> >("ResultsPlots",
 //        							   init <const std::string>() );
  class_<OneLepton::AnalysisTree, bases<Operation::_Base> >("AnalysisTree",init<const std::string &,const Utils::ParameterSet &>());
  class_<OneLepton::AnalysisTree_HighPt, bases<Operation::_Base> >("AnalysisTree_HighPt",init<const std::string &,const Utils::ParameterSet &>());

  class_<Operation::NumOfLooseElectrons, bases<Operation::_Base> >("NumOfLooseElectrons", init<const std::string &,int>());
  class_<Operation::NumOfLooseMuons, bases<Operation::_Base> >("NumOfLooseMuons", init<const std::string &,int>());
  class_<Operation::NumOfLooseMuonsRA4, bases<Operation::_Base> >("NumOfLooseMuonsRA4", init<const std::string &,int>());

  class_<Operation::CountsAndBSMGrids, bases<Operation::_Base> >("CountsAndBSMGrids", init<const Utils::ParameterSet&>() );


  class_<OneLepton::pfMETResSmear, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETResSmear",
                                                                            init<const Utils::ParameterSet &>());
  class_<OneLepton::pfMETLeptonScale, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETLeptonScale",
                                                                            init<const Utils::ParameterSet &>());
  class_<OneLepton::METResSmearNaive, bases<Compute::ObjectFilter<ICF_LorentzV> > >("METResSmearNaive",
                                                                                      init<const std::string, double, double>());
  class_<OneLepton::SystematicsPlots, bases<Operation::_Base> >("SystematicsPlots",init<const std::string &,const Utils::ParameterSet &>());
  class_<OneLepton::PolarisationReweighting, bases<Compute::ObjectFilter<double> > >("PolarisationReweighting",
										     init<const Utils::ParameterSet &>());
  class_<OneLepton::MuPtScale, bases<Compute::ObjectFilter<Event::Lepton> > >("MuPtScaleFilter",
									      init<bool>());
  class_<OneLepton::pfMETtopfMETtypeI, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETtopfMETtypeI",
									      init<>());

 class_<OneLepton::MuonJetDRFilterRA4Sync, bases<Compute::ObjectFilter<Event::Jet> > >("MuonJetDRFilterRA4Sync",init<double, const Utils::ParameterSet &>());

 class_<OneLepton::PFJetIDLoose, bases<Compute::ObjectFilter<Event::Jet> > >("PFJetIDLoose",init<>());
 class_<Operation::NumOfLooseElectronsRA4, bases<Operation::_Base> >("NumOfLooseElectronsRA4", init<const std::string &,int,const Utils::ParameterSet &>());


 class_<OneLepton::pfMETScale, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETScale", init<const std::string, double>());

  //  class_<Operation::PrintRunLSEvent, bases<Operation::_Base> >("PrintRunLSEvent");

  //  class_<OneLepton::PolarisationReweighting, bases<Compute::ObjectFilter<double> > >("PolarisationReweighting",init<const Utils::ParameterSet &>());
  class_<OneLepton::TTPolarisationReweighting, bases<Compute::ObjectFilter<double> > >("TTPolarisationReweighting",init<const std::string, double>());

}
