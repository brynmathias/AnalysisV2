#include <boost/python.hpp>
#include "Ops.hh"
#include "EffPlots.hh"
#include "EffPlotsAGB.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libTriggerStudies) {
  class_<Operation::AlphatTriggerCut, bases<Operation::_Base> >( "OP_AlphaTriggerCut",  init<float,float,float>() );
  class_<Operation::MeffTriggerCut, bases<Operation::_Base> >( "OP_MeffTriggerCut",  init<float,float,float>() );
  class_<Operation::HtTriggerCut, bases<Operation::_Base> >( "OP_HtTriggerCut",  init<float,float>() );


  class_<Operation::EffPlots, bases<Operation::_Base> >( "TriggerEffPlots",  init<const Utils::ParameterSet&>());
  class_<AGBTrig::AGBTrigEffPlots, bases<Operation::_Base> >( "TrigEffPlotsAGB", init<const Utils::ParameterSet&>());


 }
