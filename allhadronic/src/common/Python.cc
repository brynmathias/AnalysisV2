#include <boost/python.hpp>
#include "Dalitz.hh"
#include "PlottingBaseExtended.hh"
#include "TurnOn.hh"
#include "Trigger.hh"
#include "Validation.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(liballhadronic) {
  
  class_<Operation::Dalitz, bases<Operation::_Base> >( "Dalitz", init<const Utils::ParameterSet&>() );
  class_<allhadronic::PlottingBaseExtended, bases<Operation::_Base> >( "PlottingBaseExtended", init<const Utils::ParameterSet&>() );
  class_<allhadronic::TurnOn, bases<Operation::_Base> >( "TurnOn", init<const Utils::ParameterSet&>() );
  class_<allhadronic::Trigger, bases<Operation::_Base> >( "Trigger", init<const Utils::ParameterSet&>() );
  class_<allhadronic::Validation, bases<Operation::_Base> >( "Validation", init<const Utils::ParameterSet&>() );
  
}
