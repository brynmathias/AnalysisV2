/*! \file Python.cc
 * \brief Instantiation of boost python interfaces for this library
 */
#include <boost/python.hpp>
#include "CustomEleID.hh"
#include "CustomMuID.hh"
#include "Lepton.hh"
#include "Utils.hh"
#include "FillAnalysisTree.hh"
#include "lepvalPlottingOps.hh"
#include "lepvalTrigger.hh"
#include "lepvalCuts.hh"
#include "lepvalYields.hh"
#include "lepvalMC.hh"
#include "lepvalJPsiSelection.hh"

#include "BasicOps.hh"
#include "MuonOps.hh"


using namespace boost::python;

BOOST_PYTHON_MODULE(libLepCom) {


  class_<Operation::_Base, boost::noncopyable>("OP__Base", no_init);
 
  class_<LeptonCommissioning::CustomEleId, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomEleId",init<const Utils::ParameterSet &>());
  class_<LeptonCommissioning::CustomMuId, bases<Compute::ObjectFilter<Event::Lepton> > >("CustomMuId",init<float,float,float>());
  
  class_<LeptonCommissioning::FillAnalysisTree,bases<Operation::_Base> >("FillAnalysisTree",init<const std::string &, UInt_t>());
  
  class_<LeptonCommissioning::LMPlots, bases<Operation::_Base> >("OP_LMPlots",init<const std::string &>());

  // Electrons
  class_<LeptonCommissioning::EleJetDRFilter, bases<Compute::ObjectFilter<Event::Jet> > >("EleJetDRFilter",
											  init<double>());
  class_<LeptonCommissioning::MuJetDRFilter, bases<Compute::ObjectFilter<Event::Jet> > >("MuJetDRFilter",init<double,double>());
  class_<LeptonCommissioning::makeElectronTree, bases<Operation::_Base> >("ElectronTree",
								      init<const std::string &,
								      const Utils::ParameterSet &>());
  class_<LeptonCommissioning::myMuonPlots, bases<Operation::_Base> >("MuonTree",
								     init<const std::string &,
								     const Utils::ParameterSet &>());
  class_<LeptonCommissioning::NumOfGdMuons,bases<Operation::_Base> >("OP_NumOfGdMuons", init<const std::string &,UInt_t,float,float>());

  
  
  //from JPsi
  class_<lepval::LepValPlots, bases<Operation::_Base> >("LP_plots", init<const std::string&, bool, bool, bool, std::string>());
  class_<lepval::LepValTrigger, bases<Operation::_Base> >("Trigger",init<const std::string&>());
  class_<lepval::LepValHT_Cut, bases<Operation::_Base> >("HtCut", init<double>());
  class_<lepval::lepvalYields, bases<Operation::_Base> >("Yields", init <const std::string &,Utils::ParameterSet&>());
  class_<lepval::IsolatedLeptons, bases<Compute::UserBase> >("IsoGenLeptons");
  class_<lepval::LepValJPsiMu, bases<Compute::UserBase> >("SelectionJPsiMuons", init<bool, double, double, double, double, double>());
}
