/*! \file Python.cc
 * \brief Instantiation of boost python interfaces for this library
 */

// Comment to avoid compiling electron code
#define ELECTRONS 1


#include "MuonPlottingOps.hh"

#include "Functions.hh"
#include "MC7to10.hh"
#include "JECUncPlots.hh"
#include "JECUnc2DPlots.hh"
//#include "PDFUncPlots.hh"
//#include "NewPDFPlots.hh"
#include "MCCSFramePlots.hh"
#include "MCPolPlots.hh"
#include "MCWPlots.hh"
#include "RECOCSFramePlots.hh"
#include "RECOPolPlots.hh"
#include "GenerationPlots.hh"
#include "CutsAndChecks.hh"
#include "MuPtScale.hh"
#include "SingleMuPtScale.hh"
#include "ElCheckPlots.hh"

// Python wrapper
#include <boost/python.hpp>

#include "EventNoDump.hh"

#ifdef ELECTRONS
#include "WPolFilters.hh"
#include "ElPlottingOps.hh"
#include "ElOps.hh"
#include "ttWPlottingOps.hh"
#include "eWPolTemplateHistos.hh"
#include "ElOpsDebug.hh"
#endif
using namespace boost::python;

BOOST_PYTHON_MODULE(libWPol) {

  // Very important - declare the operation base class as virtual (non-creatable)
  // Otherwise this code won't work with python...
  class_<Operation::_Base, boost::noncopyable>("OP__Base", no_init)
    ;

  ///////////////////////////////////////////////////
  // Operation declarations
  ///////////////////////////////////////////////////

  class_<Operation::PrintDebugInfo, bases<Operation::_Base> >("Print_DebugInfo",
                                                              init<const char *>());
  class_<Operation::MCWExists, bases<Operation::_Base> >("MC_GenWExists");
  class_<Operation::MCZExists, bases<Operation::_Base> >("MC_GenZExists");
  class_<Operation::MCWMuonExists, bases<Operation::_Base> >("MC_GenWMuonExists");
  class_<Operation::MCWLeptonExists, bases<Operation::_Base> >("MC_GenWLeptonExists");
  class_<Operation::MCMuonExtraFromW, bases<Operation::_Base> >("MC_GenMuonExtraFromW");
  class_<Operation::MCqqbarW, bases<Operation::_Base> >("MC_qqbarW");
  class_<Operation::MCWPTCut, bases<Operation::_Base> >("MC_GenWPTCut",
							init<float>());
  class_<Operation::MCWPTCut2, bases<Operation::_Base> >("MC_GenWPTCut2",
							 init<float, float>());
  class_<Operation::MCWYCut, bases<Operation::_Base> >("MC_GenWYCut",
						       init<float, float>());
  class_<Operation::MCWYCut2, bases<Operation::_Base> >("MC_GenWYCut2",
							init<float>());
  class_<Operation::MCMuonAccCut, bases<Operation::_Base> >("MC_GenMuonAccCut",
							    init<float, float>());
  class_<Operation::MCWPlots, bases<Operation::_Base> >("MC_WPlots",
							init<const std::string &,const std::string &,const unsigned int &>());
  class_<Operation::ttWPlottingOps, bases<Operation::_Base> >("RECO_ttWPlotting",
							      init<const std::string &>());

  class_<Operation::MCVHTCut, bases<Operation::_Base> >("MC_GenVHTCut",
							init<float, float>());
  class_<Operation::MCJetHTCut, bases<Operation::_Base> >("MC_GenHTCut",
							  init<float, float>());
  class_<Operation::MCLeptonExists, bases<Operation::_Base> >("MC_GenNumLeptons",
							      init<std::string, unsigned int>());
  class_<Operation::MCS1LeptonExists, bases<Operation::_Base> >("MC_GenS1Leptons",
								init<std::string>());
  class_<Operation::MCZtoLeptons, bases<Operation::_Base> >("MC_ZtoLeptons",
							    init<std::string>());
  class_<Operation::MCMuonExtraExists, bases<Operation::_Base> >("MC_GenNumMuonsExtra",
								 init<unsigned int>());
  class_<Operation::MCElectronExists, bases<Operation::_Base> >("MC_GenNumElectrons",
								init<unsigned int>());
  class_<Operation::MCPhotonExists, bases<Operation::_Base> >("MC_GenNumPhotons",
							      init<unsigned int>());
  class_<Operation::MCGTGenJetExists, bases<Operation::_Base> >("MC_GenJetsGT",
								init<unsigned int, float>());
  class_<Operation::MCLTGenJetExists, bases<Operation::_Base> >("MC_GenJetsLT",
								init<unsigned int, float>());
  class_<Operation::MCPolPlots, bases<Operation::_Base> >("MC_PolPlots",
							  init<const std::string &>());
  class_<Operation::RECOMuMuPtCut, bases<Operation::_Base> >("RECO_MuMuPtCut",
							     init<float>());
  class_<Operation::RECOpfMTCut, bases<Operation::_Base> >("RECO_PFMTCut",
							   init<float>());
  class_<Operation::RECO1of2MuonsOverPT, bases<Operation::_Base> >("RECO1of2MuonsOverPT",
							   init<float>());
  class_<Operation::RECOMuMuPtCut2, bases<Operation::_Base> >("RECO_MuMuPtCut2",
							      init<float, float>());
  class_<Operation::RECOMuonExists, bases<Operation::_Base> >("RECO_RecoNumMuons",
							      init<unsigned int>());
  class_<Operation::RECOPolPlots, bases<Operation::_Base> >("RECO_PolPlots",
							    init<const std::string &, const std::string &, bool, const unsigned int &>());
  class_<Operation::RECOCommonMHTCut, bases<Operation::_Base> >("RECO_CommonMHTCut",
								init<float>());
  class_<Operation::RECOCommonMHTCut2, bases<Operation::_Base> >("RECO_CommonMHTCut2",
								 init<float, float>());
  class_<Operation::RECOMuonJetDRCut, bases<Operation::_Base> >("RECO_MuonJetDRCut",
								init<float>());
  class_<Operation::RECO2ndMuonMass, bases<Operation::_Base> >("RECO_2ndMuonMass",
							       init<float,float,bool,std::string>());
  class_<Operation::MCCSFramePlots, bases<Operation::_Base> >("MC_CSFramePlots",
							      init<const std::string &,const std::string &>());
  class_<Operation::RECOCSFramePlots, bases<Operation::_Base> >("RECO_CSFramePlots",
								init<const std::string &,const std::string &,bool>());
  class_<Operation::JadGenOrigin, bases<Operation::_Base> >("CheckGenOrigin",
							    init<const std::string &>());
  class_<Operation::TRIGGERCut, bases<Operation::_Base> >("TRIGGER_Cut",
							  init<const std::string &, const std::string &>());
  class_<Operation::ORTRIGGERCut, bases<Operation::_Base> >("ORTRIGGER_Cut",
							  init<const std::string &, const std::string &>());
  class_<Operation::JECUncPlots, bases<Operation::_Base> >("JECUnc_Plots",
							   init<const std::string &>());
  class_<Operation::JECUnc2DPlots, bases<Operation::_Base> >("JECUnc_2DPlots",
  							     init<const std::string &>());
  //class_<Operation::PDFUncPlots, bases<Operation::_Base> >("PDFUnc_Plots",
  //							   init<const std::string &>());
  //class_<Operation::NewPDFPlots, bases<Operation::_Base> >("NewPDF_Plots",
  //							   init<const std::string &, const std::string &, int>());
  class_<Operation::RECOSecondGMCut, bases<Operation::_Base> >("RECO_SecondGMCut",
							       init<float>());
  class_<Operation::MuPtScale, bases<Operation::_Base> >("MuPtScale",
                                                            init<const std::string &>());
  class_<Operation::SingleMuPtScale, bases<Operation::_Base> >("SingleMuPtScale",
                                                            init<const std::string &>());

#ifdef ELECTRONS
  class_<WPol::PFMHTCut,bases<Operation::_Base> >("OP_PFMHTCut",init<float>());
#endif
  class_<Operation::RECOPFMETCut, bases<Operation::_Base> >("RECO_PFMETCut",
							    init<float>());
  class_<Operation::MCRECOPFMETCut, bases<Operation::_Base> >("MCRECO_PFMETCut",
							    init<float>());
  class_<Operation::MCRECOPFMETCut2, bases<Operation::_Base> >("MCRECO_PFMETCut2",
							      init<float, float>());
  class_<Operation::MCMuMuInvMass, bases<Operation::_Base> >("MCMuMuInvMass",
							      init<float, float>());
  class_<Operation::MCRECOZPFMETCut, bases<Operation::_Base> >("MCRECO_ZPFMETCut",
							    init<float>());
  class_<Operation::RECOPFMETCut2, bases<Operation::_Base> >("RECO_PFMETCut2",
							     init<float, float>());
  class_<WPol::LeptonEffRA4, bases<Compute::ObjectFilter<Event::Lepton> > >("LeptonEffRA4",
									       init<>());



#ifdef ELECTRONS
  class_<WPol::EleJetDRFilter, bases<Compute::ObjectFilter<Event::Jet> > >("EleJetDRFilter",
									   init<double>());

  class_<WPol::LepMinIsoFilter, bases<Compute::ObjectFilter<Event::Lepton> > >("LepMinIsoFilter",
									       init<double>());


  class_<WPol::CustomEleId, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomEleId",
                                                                           init<const Utils::ParameterSet &>());

  class_<eWPol::BasicPlots, bases<Operation::_Base> >("eWPolBasicPlots",
						      init<const std::string &,
						      const Utils::ParameterSet &>());
class_<eWPol::RECOPolPlots, bases<Operation::_Base> >("RECO_ElPolPlots",
						      init<const std::string &,
						      const Utils::ParameterSet &>());

class_<WPol::GenLeptonType, bases<Operation::_Base> >("GenLeptonType",
						      init<const std::string &,
						      const std::string &>());

class_<WPol::ApplyLeptonCut, bases<Operation::_Base> >("ApplyLeptonCut",
                                                       init<const std::string &,
                                                       const double,
                                                       Compute::ObjectFilter<Event::Lepton>*,
                                                       int,
                                                       bool>());


class_<WPol::MassWindowCut, bases<Operation::_Base> >("MassWindowCut",
                                                    init<const std::string &,
                                                    const Utils::ParameterSet &>());

class_<eWPol::TriggerEffPlot, bases<Operation::_Base> >("TriggerEffPlot",
                                                        init<const std::string &>());

class_<WPol::eWPolTemplateHistos,bases<Operation::_Base> >("eTemplateHistos", init <const std::string &,
                                                           Utils::ParameterSet & >());
class_<WPol::RECOpfMTCut, bases<Operation::_Base> >("ePFMTCut",
                                                    init<const std::string &, double>());

#endif


 class_<Operation::MuonPlottingOps, bases<Operation::_Base> >("RECO_MuonPlotting",
							      init<const std::string &>());
 class_<Operation::ElCheckPlots, bases<Operation::_Base> >("RECO_ElCheckPlots",
							   init<const std::string &>());
 class_<WPol::CustomMuonId, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomMuonId",
                                                                           init<const Utils::ParameterSet &>());
 class_<WPol::CustomMuonId_latest, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomMuonId_latest",
										  init<const Utils::ParameterSet &>());
 class_<WPol::pfMETsmearing, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETsmearing",
									   init<const Utils::ParameterSet &>());

 class_<WPol::pfMETResUncOfficial, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETResUncOfficial",
										 init<std::string,std::string>());

 class_<WPol::pfMETResSmear, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETResSmear",
									   init<const Utils::ParameterSet &>());
 class_<WPol::pfMETResSmearPU, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETResSmearPU",
									     init<const Utils::ParameterSet &>());
 class_<WPol::MuonScaleShift, bases<Compute::ObjectFilter<Event::Lepton> > >("MuonScaleShift",
									     init<const Utils::ParameterSet &>());
 class_<WPol::MuonScaleUncertRA4, bases<Compute::ObjectFilter<Event::Lepton> > >("MuonScaleUncertRA4",
										 init<std::string>());
 class_<WPol::pfMETJECUnc, bases<Compute::ObjectFilter<ICF_LorentzV> > >("pfMETJECUnc",
									 init<const Utils::ParameterSet &>());
 class_<WPol::ECALTransparencyCorrections, bases<Compute::ObjectFilter<Event::Lepton> > >("ECALTransparencyCorrections", init<const Utils::ParameterSet &>());
 class_<WPol::ECALResolutionCorrections, bases<Compute::ObjectFilter<Event::Lepton> > >("ECALResolutionCorrections", init<const Utils::ParameterSet &>());
 class_<WPol::ElectronScaleUncertainty, bases<Compute::ObjectFilter<Event::Lepton> > >("ElectronScaleUncertainty", init<const Utils::ParameterSet &>());
 class_<eWPol::ControlPlots, bases<Operation::_Base> >("ControlPlots",
                                                      init<const std::string, const Utils::ParameterSet &>());
 class_<eWPol::DataMCPlots, bases<Operation::_Base> >("DataMCPlots",
                                                      init<const std::string>());

 class_<WPol::ChargeAgreement, bases<Operation::_Base> >("ChargeAgreement");
 class_<WPol::CombRelIsoCut, bases<Operation::_Base> >("CombRelIsoCut", init<double>());
 class_<WPol::EventNoDump, bases<Operation::_Base> >("EventNoDump", init<std::string, std::string>());
 class_<WPol::DebugElectronID, bases<Operation::_Base> >("DebugElectronID",
                                                         init<int,
                                                         const Utils::ParameterSet &
                                                        >());
}
