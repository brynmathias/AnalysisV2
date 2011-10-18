#include <boost/python.hpp>
#include "WChSelect.hh"
#include "MjPlottingOps.hh"
#include "ErsatzMet.hh"
#include "ChAsymTemplateHistos.hh"
#include "AsymTemplateHistos.hh"
#include "AntiTemplateHistos.hh"
#include "HadronicRecoil.hh"
#include "WenuFilters.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libWCharge) {
  class_<WChSelect,bases<Operation::_Base> >("WChSelect", init<const std::string &,Utils::ParameterSet & >());
  class_<MjPlottingOps,bases<Operation::_Base> >( "MjPlottingOps",init<const std::string &,const Utils::ParameterSet&>()); 
  class_<ErsatzMet,bases<Operation::_Base> >( "ErsatzMet",init<const std::string &,const Utils::ParameterSet&>()); 
  class_<ChAsymTemplateHistos,bases<Operation::_Base> >( "ChAsymTemplateHistos", init<const std::string &,Utils::ParameterSet & >());
  class_<AsymTemplateHistos,bases<Operation::_Base> >( "AsymTemplateHistos", init<const std::string &,Utils::ParameterSet & >());
  class_<AntiTemplateHistos,bases<Operation::_Base> >( "AntiTemplateHistos", init<const std::string &,Utils::ParameterSet & >());
  class_<HadronicRecoil,bases<Operation::_Base> >( "HadronicRecoil", init<const std::string &,Utils::ParameterSet & >());
  class_<WCharge::JetEleDrFilter, bases<Compute::ObjectFilter<Event::Jet> > > ("JetEleDrFilter",init<double>());
  class_<WCharge::EleJetDrFilter, bases<Compute::ObjectFilter<Event::Lepton> > > ("EleJetDrFilter",init<double>());
}
