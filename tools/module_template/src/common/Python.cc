#include <boost/python.hpp>
#include "Ops.hh"
using namespace boost::python;

BOOST_PYTHON_MODULE(libTMP_MODULE_NAME) {
  class_<Operation::AlphatTriggerCut, bases<Operation::_Base> >( "OP_AlphaTriggerCut",  init<float,float,float,float>() );


 }
