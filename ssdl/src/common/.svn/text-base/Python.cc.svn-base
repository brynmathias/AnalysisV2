#include <boost/python.hpp>
#include "SSDLTrigger.hh"
#include "SSDLSelection.hh"
#include "dpsSSWSelection.hh"
#include "TTBkgEval.hh"
#include "TauBkgEval.hh"
#include "LowPtIsolation.hh"
#include "SSDLMC.hh"
#include "Utils.hh"
#include "TFile.h"
#include "CleanFilters.hh"
#include "SystFilters.hh"
//#include "LepFilters.hh"

#include "ElMuFRNormalization.hh"
#include "TauFRNormalization.hh"
#include "BkgFromFlip.hh"

#include "ElectronFakeRate.hh"
#include "MuFakeRate.hh"
#include "TauFakeRate.hh"
//#include "TauBkgEval.hh"
//#include "ElecBkgEval.hh"
#include "SSDLSkimSel.hh"
#include "SSDLBkgdCat.hh"
#include "EventPicker.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libSSDL) {
  class_<SSDL::SSDLTrigger,bases<Operation::_Base> >("SSDLTrigger", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::SSDLSelection,bases<Operation::_Base> >("SSDLSelection", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::dpsSSWSelection,bases<Operation::_Base> >("dpsSSWSelection", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::TTBkgEval,bases<Operation::_Base> >("TTBkgEval", init<const std::string &,Utils::ParameterSet &>());
  class_<SSDL::TauBkgEval,bases<Operation::_Base> >("TauBkgEval", init<const std::string &>());
  //MC ANALYSIS
  class_<SSDL::SSDL_MC_PreSel, bases<Operation::_Base> >("SSDL_MC_PreSel", init<Utils::ParameterSet &>());
  class_<SSDL::SSDLMCTruth,bases<Operation::_Base> >("SSDLMCTruth", init<const std::string &,Utils::ParameterSet &>());
  class_<SSDL::TTMC,bases<Operation::_Base> >("TTMC", init<const std::string &, const int &>());
  class_<SSDL::FRMC,bases<Operation::_Base> >("FRMC", init<const std::string &, Utils::ParameterSet & >());
  class_<SSDL::NOMC,bases<Operation::_Base> >("NOMC", init<const int &>());
  //FILTERS
  class_<SSDL::pfMetUncer,bases<Compute::ObjectFilter<LorentzV> > >("PfMetUncer", init<double, bool, bool>());
  class_<SSDL::MetUncerJES,bases<Compute::ObjectFilter<LorentzV> > >("MetUncerJES", init<>());

  class_<SSDL::TauJetDrFilter, bases<Compute::ObjectFilter<Event::Jet> > > ("TauJetDrFilter",init<double>());
  class_<SSDL::MuonTauDrFilter, bases<Compute::ObjectFilter<Event::Lepton> > > ("MuonTauDrFilter",init<double>());
  class_<SSDL::ElectronTauDrFilter, bases<Compute::ObjectFilter<Event::Lepton> > > ("ElectronTauDrFilter",init<double>());
  class_<SSDL::MuonElectronDrFilter, bases<Compute::ObjectFilter<Event::Lepton> > > ("MuonElectronDrFilter",init<double>());
  class_<SSDL::ElectronJetDrFilter, bases<Compute::ObjectFilter<Event::Jet> > > ("ElectronJetDrFilter",init<double>());
  class_<SSDL::MuonJetDrFilter, bases<Compute::ObjectFilter<Event::Jet> > > ("MuonJetDrFilter",init<double>());
  class_<SSDL::LeptonD0Filter, bases<Compute::ObjectFilter<Event::Lepton> > > ("LeptonD0Filter",init<double,double,double>());
  class_<SSDL::LeptonD0FilterVertex, bases<Compute::ObjectFilter<Event::Lepton> > > ("LeptonD0FilterVertex",init<double>());
  //LEPTON ID
  class_<SSDL::CustomEleId, bases<Compute::ObjectFilter<Event::Lepton> > > ("CustomEleId",init<Utils::ParameterSet &>());
  class_<SSDL::CustomMuonId, bases<Compute::ObjectFilter<Event::Lepton> > > ("CustomMuonId",init<Utils::ParameterSet &>());
  class_<SSDL::CustomTauId, bases<Compute::ObjectFilter<Event::Lepton> > > ("CustomTauId",init<Utils::ParameterSet &>());
  class_<SSDL::CustomJetId, bases<Compute::ObjectFilter<Event::Jet> > > ("CustomJetId",init<Utils::ParameterSet &>());
  //NORMALIZATION FOR FAKE RATE METHOD
  class_<SSDL::ElMuFRNormalization,bases<Operation::_Base> >("ElMuFRNormalization", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::TauFRNormalization,bases<Operation::_Base> >("TauFRNormalization", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::BkgFromFlip,bases<Operation::_Base> >("BkgFromFlip", init<const std::string &,Utils::ParameterSet & >());
  //FAKE RATE
  class_<SSDL::ElectronFakeRate,bases<Operation::_Base> >("ElectronFakeRate", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::MuFakeRate,bases<Operation::_Base> >("MuFakeRate", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::TauFakeRate,bases<Operation::_Base> >("TauFakeRate", init<const std::string &,Utils::ParameterSet & >());
  class_<SSDL::SSDLSkimSel,bases<Operation::_Base> >("SkimSel",init<Utils::ParameterSet & ,Utils::ParameterSet & ,Utils::ParameterSet & ,Utils::ParameterSet & >());
  class_<SSDL::SSDLBkgdCat,bases<Operation::_Base> >("SSDLBkgdCat", init<double, double, const std::string &>());
  class_<SSDL::SSDLEventPicker,bases<Operation::_Base> >("SSDLEventPicker", init<Utils::ParameterSet &>());
}
